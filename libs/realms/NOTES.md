# RealmsMUD core-lib -- porting notes

## 1. What this repo actually is

This is **not** an engine-only skeleton. `https://github.com/realms-mud/core-lib`
ships a large, complete game: `guilds/` (9,994 files -- class/profession
definitions, guild halls, guild-specific commands), `areas/` (2,577 files --
rooms, NPCs, items across many named zones), plus `lib/` (the framework:
core classes, command souls, module system, service layer, character
creation, combat, quests, research/crafting, trading). ~16,570 files total.

The persistence model is unusual for this collection: login credentials and
player-character records live in a **MySQL database** (`RealmsLib`),
accessed through this driver's own `db_*` package, not flat player-save
files. Provisioning that database was itself a significant chunk of this
session's work (see section 9).

## 2. Compile-sweep: dialect/driver differences

This codebase targets LDMud and an LDMud-flavored FluffOS build; porting to
a stock FluffOS driver required all of the following:

- **`virtual inherit`** (LDMud-only) doesn't exist here -- files that relied
  on it for shared state across a diamond (`secure/login/core.lpc` inherited
  independently by `menu-interactions.lpc` and `user-creation.lpc`) were
  switched from `inherit` to `#include` (pure text substitution avoids the
  diamond entirely, and genuinely shares state since it's all one compiled
  scope).
- **FluffOS diamond-inheritance restriction**: the same base program
  reachable via multiple inherit *depths* simultaneously is illegal
  ("Illegal to redefine 'nomask' function"). Hit repeatedly:
  `lib/core/thing.lpc`'s `move_object()`/`command()`/`isIlluminated()` had
  to be made non-`nomask` once `player.lpc` combined `living.lpc`'s
  13-module chain with ~10 of its own direct modules, reaching `thing.lpc`
  at two different depths; `dataAccess.lpc`'s 18 `dataServices/*.lpc`
  subclasses all independently inheriting `dataService.lpc` hit the same
  wall, fixed by moving `dataService.lpc`'s shared logic into a real
  `call_other()`-target object (`dataServiceUtil.lpc`, reached via a
  `DB_UTIL` macro) instead of inheriting it everywhere.
- **Closures can't capture enclosing-function locals** -- pervasive; fixed
  by passing the needed value as a bound arg (`$2`/`$3`, ...) instead of
  referencing it bare inside the closure body. Includes several "half
  fixed" cases where a value *was* bound but the closure body still
  referenced the bare name instead of `$N` (`who.lpc`'s race filter,
  `soul.lpc`, `research.lpc`, `events.lpc`'s `notifySynchronous()`).
- **`(: return EXPR; :)` closures** -- this driver's closure body is an
  expression, not a statement list; `return` inside one is invalid.
  Converted to `(: EXPR :)` at 15 sites across 9 files.
- **`#'funcname`** (LDMud's function-reference operator) doesn't exist;
  converted to `(: funcname :)`.
- **2-arg free functions `move_object(dest, actor)` / `command(cmd,
  actor)`** are LDMud-only; this driver's real efuns are 1-arg,
  current-object-only. Since a bare call to an efun name with no matching
  user-defined function silently no-ops on this driver rather than
  erroring, real `move_object()`/`command()` functions were added to
  `lib/core/thing.lpc` and ~378 call sites (267 for `move_object`, 111 for
  `command`) mechanically rewritten from `move_object(dest, actor)` /
  `command(cmd, actor)` to `actor->move_object(dest)` /
  `actor->command(cmd)` (a real `call_other`, which correctly makes `actor`
  become `current_object` for the call's duration).
- **`m_indices`/`m_values`/`m_delete`/`mappingp`** (old-style mapping efun
  names) -> `keys`/`values`/`map_delete`/`mapp`. **`nosave` as a function
  modifier** -> `protected`. Swept across all `.lpc` *and* `.h` files (an
  initial `--include='*.lpc'`-only pass missed `/lib/modules/secure/
  inventory.h`, redone including headers).
- **`get_dir()` returns bare filenames, not full paths`** -- the same
  driver behavior as LDMud in this respect, but several call sites assumed
  otherwise (see section 3 and 4 below for the two most consequential
  cases). Swept wherever found.
- **`__EFUN_DEFINED__`** used inside inherited fragment files trips a
  driver bug ("Condition too complex"); removed and hardcoded based on
  confirmed driver capabilities in `interactive-info.lpc`,
  `object-info.lpc`, `strings.lpc`, `secure/simul_efun.lpc`.
- Missing efuns/simul_efuns rebuilt from scratch as simul_efuns in
  `secure/simulated-efuns/portability.lpc` (reached via `PORT->` call_other
  from the handful of files that can't use normal simul_efun resolution due
  to eager-compile ordering -- see that file's own header comment for the
  full bootstrapping explanation) and thin wrappers in
  `secure/simul_efun.lpc`: `member()`, `mkmapping()`, `call_direct()`,
  `to_string()`, `object_name()`/`program_name()` (see section 3),
  `strstr()`, `raise_error()`, `regreplace()`/`regexplode()` (see section
  4), `present_clone()`, `save_value()`/`restore_value()` (see section 6).

## 3. `object_name()`/`.lpc`-extension bug (root cause of every player save
failing)

LDMud's `object_name()`/`program_name()` are two separate efuns (full
instance path incl. `#<clone number>` vs. the base file path without it);
this driver collapses both into `file_name()`, which additionally **omits
the `.lpc` extension** that `object_name()`'s original callers expected.
`canAccessDatabase()` (gating every `player->save()`/permission check
across the whole codebase) compared paths *with* the extension against
`file_name()`'s *without*-extension result, denying every single save
silently. Fixed by rebuilding `object_name()` to call `file_name()` and
re-insert `".lpc"` before any `#<clone number>` suffix; `program_name()`
calls that and additionally strips the clone suffix.

## 4. `strsrch()`'s 3rd argument bug (root cause of the "look" command
crashing for everyone)

This driver's real `strsrch(big, little, flag)` (confirmed against
`packages/core/efuns_main.cc`'s `f_strsrch()`) treats its 3rd argument as a
**boolean direction flag** ("search starting at right if set") -- not a
start position. `regreplace()`/`regexplode()` (this driver has no native
equivalents at all; both hand-built on `pcre_match_all()`) used it as a
cursor to resume searching after each successive match, which is exactly
backwards: the first match (cursor==0, so `flag` is falsy, a normal forward
search) was always found correctly, but every subsequent match search
silently flipped to a **backward** scan from the end of the whole string.

This corrupted `lib/commands/baseCommand.lpc`'s `prepCommandRegExp()`,
which converts `"who [-w] [-p] [-r ##Value##] [-g ##Value##]"`-style
templates into working regexes via two chained `regreplace()` calls. Any
template with 3+ bracket groups (`who`, `say`, `shout`, `traits`, `skills`)
produced a regex with dangling, unmatched `]` characters. The moment any
player's `look` command tried to match against the *combined* command
table (which includes these broken patterns), this driver's regex engine
threw `"unexpected ]"` as an **uncaught error**, breaking dispatch
entirely -- for every command, not just the broken ones, since the error
aborted the whole `executeCommand()` call.

Fixed in both `regreplace()` and `regexplode()` (`secure/simulated-efuns/
portability.lpc`): never pass a "start offset" to `strsrch()`. Slice the
unsearched tail of the string first (plain LPC range indexing has
unambiguous start-offset semantics) and search *that* from its own
beginning (flag `0`, always a real forward search), adding the cursor back
to the result. The public `strstr(big, small, start)` wrapper (LDMud's
`strstr` with a real start-offset parameter) had the exact same bug and got
the same fix.

## 5. `regexp()`'s 10-group cap (root cause of "look" still crashing after
the strsrch fix)

Fixing section 4 surfaced a second, independent bug in the same area: this
driver's legacy `regexp()` efun (`packages/core/regexp.cc`) hard-caps at 10
capturing groups total (`NSUBEXP == 10`, and the check is `>=` so 10 groups
is already one too many). `baseCommand.lpc`'s `canExecuteCommand()` (when
`SplitCommands` is unset, its default) ORs *every* alias/flag-set a command
registers into one combined regex -- `"look"`'s 5 aliases (look/l/examine/
exa/glance, each with their own optional groups) compile to 13+ groups.
`commandRegistry.lpc`'s own per-alias dispatch loop can hit the same cap
too: the `"'"`/`say` command's single template (`-verb`/`-adverb`/
`-language`/`-target`/wildcard) compiles to exactly 10 groups.

Switched every command-matching `regexp()` call (`baseCommand.lpc`'s
`canExecuteCommand()`/`commandString()`, `commandRegistry.lpc`'s
`executeCommand()`) to this driver's PCRE-backed `pcre_match()`, which
accepts the identical array-subject/array-of-matches calling convention
and has no such cap.

## 6. `save_value()`/`restore_value()` don't exist (root cause of every
item failing to compile)

LDMud's `save_value(mixed)`/`restore_value(string)` -- serialize an
arbitrary int/float/string/array/mapping value to a string and back --
don't exist on this driver at all, and there's no `eval-a-string-as-LPC-
literal` facility to build them on top of (checked `core.spec`; only
`save_object()`/`restore_object()`, whole-*object* persistence, exist).

`/lib/items/item.lpc` -- the base class nearly every equippable/usable item
in the game inherits -- used both for its bulk `query(item, "all")`/
`set(item, "all", data)` accessor (used by the shop system to clone/restore
an item's full property mapping). An undefined function is a hard compile
error on this driver, so **item.lpc had no compiled program at all**, which
would cascade to every subclass.

Implemented from scratch in `portability.lpc`: a small recursive serializer
producing LPC-literal-shaped text (`({...})` for arrays, `([...])` for
mappings, quoted strings with `\"`/`\\`/`\n` escapes, plain int/float via
`%d`/`%.17g`) and a matching hand-written recursive-descent parser
(`_restoreValueParse()`) to read it back. Only needs to round-trip within
this port (nothing else reads this format), so it doesn't match LDMud's
exact grammar byte-for-byte -- just int/float/string/array/mapping, which
is everything `item.lpc`'s own data actually contains.

## 7. `add_action()`'s `command_giver` requirement (root cause of every
command failing after login)

This driver's `add_action()` (`packages/core/add_action.cc`) silently
returns without registering anything unless, *at the exact moment it's
called*, `current_object == command_giver` (or an environment relation
between them) -- no error, no signal at all.

`player.lpc`'s `create()` calls `addCommands()` -> `add_action
("executeCommand", "", 2)` at object-*creation* time (i.e. inside
`clone_object()`), which for a login always happens **before** `exec()`
ever reassigns the interactive connection from the login object to the new
player object. So `command_giver` is still the login object when this runs,
and the registration silently no-ops. A freshly logged-in character could
reach `"You have the following login options:"`, select a character, and
even see the login flow's own automatic `player->command("l")` succeed
structurally -- but every subsequent typed command (`look`, `score`,
`quit`, everything) produced the *driver's own* default `"> "` prompt
(confirmed via `grep`, not emitted by any mudlib code -- `comm.cc:135`'s
`set_prompt("> ")`) and its default fail message, forever.

Confirmed via `interactive.cc`'s `replace_interactive()`: `exec()` *does*
call `set_command_giver(ob)` immediately, synchronously, the moment it
runs, updating the driver's `command_giver` global for the rest of that
same LPC call. Fixed by re-calling `player->addCommands()` (idempotent --
the pre-exec attempt was a no-op, so this is the only registration that
actually takes effect) immediately after `exec()` in all three call sites
that create and attach a player (`secure/login/menu-interactions.lpc`'s
`execCharacter()`, `secure/login/user-creation.lpc`'s `execNewPlayer()` and
`execGuestPlayer()`).

## 8. `catch(expr; nolog)` doesn't exist

LDMud's `catch(expr; nolog)` (a `;`-separated modifier suppressing the
error-log entry on failure) isn't supported by this driver's grammar at
all -- confirmed against `compiler/internal/grammar.y`: `catch` only
accepts a bare parenthesized expr or a `{ }` block, no `;`-separated
modifier syntax whatsoever. Every occurrence was a hard syntax error
("syntax error, unexpected ';'"). Swept mechanically across 51 files (48
pre-existing upstream `/lib/tests/*.lpc` unit-test files, excluded from
preload so not gameplay-critical but fixed anyway for consistency; plus 3
real gameplay files this port's own new code and upstream both used the
pattern in -- `secure/master/logging.lpc`, `lib/commands/wizard/cc.lpc`,
`lib/services/tradingService.lpc`/`lib/modules/domains/trading/selectors/
buySelector.lpc`) -- removed the trailing `; nolog`, keeping plain
`catch(expr)` (the only behavioral difference is a harmless error-log entry
on failure).

## 9. `inherit_list()` never includes an object's own program (wizard
commands unreachable for every rank)

This driver's `inherit_list()` (aliased from `shallow_inherit_list()`; see
`vm/internal/base/array.cc`'s `inherit_list()`) returns only the files an
object's program *directly inherits from* -- it never includes the queried
object's own class/program itself. Upstream's `member(inherit_list(x),
"/lib/realizations/wizard.lpc") > -1` idiom (used repeatedly to check "is
this object a wizard") only makes semantic sense if `inherit_list()`
includes the queried object's own class -- apparently true under LDMud, but
never true here. `wizard.lpc` doesn't inherit itself, so this check is
permanently `-1` for a genuine `wizard.lpc` instance, meaning wizard-only
commands were **unreachable for every account regardless of rank**
(confirmed live with the `owner`-ranked admin account -- `pwd`/`ls`
produced the driver's default `"What?"`, not a "no such command" from the
mudlib itself, since the command was excluded from the dispatch table
entirely before matching was even attempted).

Fixed in `commandRegistry.lpc`'s `executeCommand()` -- the one instance
confirmed to actually gate real end-to-end functionality -- by also
checking `program_name(initiator) == Wizard` directly (a same-class check,
which correctly complements `inherit_list()`'s "class B inherits from
class A" semantics). **This exact idiom recurs elsewhere** in the codebase
(at minimum `lib/commands/player/who.lpc`'s wizard-listing filter); only
the one confirmed-live-blocking instance was fixed this session, not a
full corpus sweep.

## 10. `-=` doesn't work on strings

LDMud's string `-` operator (remove every occurrence of the right operand
substring from the left) doesn't exist on this driver at all -- confirmed
against `vm/internal/base/interpret.cc`'s `F_SUBTRACT`, which only accepts
int/float/array operands ("Bad right type to -" otherwise). Broke
`baseCommand.lpc`'s `commandString()` (`ret -= "$";`, meant to strip a
known trailing `"$"` char) outright the moment any command with a target
argument (`getTarget()`) was used. Fixed with a direct trailing-character
trim (`ret` always ends in `"$"` here by construction), a precise
substitute for what was intended.

## 11. Miscellaneous, smaller fixes

- **`"? [-v]"` unescaped in a regex**: `score.lpc` registers a literal `"?"`
  as a command alias. Once command matching switched to PCRE (section 5),
  the resulting `"^?( -v)*$"` pattern was a hard compile error ("nothing to
  repeat" -- `?` right after `^` has no preceding atom). Escaped
  unconditionally in `baseCommand.lpc`'s `prepCommandRegExp()`; none of
  this codebase's own template syntax (`[optional]`/`(a|b)`) ever needs a
  literal `?`.
- **`copy_file()` doesn't exist**: this driver's own file-copy efun is
  `cp(string, string)` (checked `core.spec`). This was a real,
  previously-undetected compile error in `lib/commands/wizard/cp.lpc` --
  and since that file is loaded eagerly by every player's command
  registration via the shared `commandRegistry` singleton, it was aborting
  command registration for *every* login until fixed.
- **`all_inventory(0)` hard-errors** on this driver instead of returning an
  empty array (confirmed live via `look.lpc`'s pre-environment automatic
  `"l"` call, issued right after login before a brand-new character has
  gone through character creation and been placed in a room). Guarded in
  `look.lpc`; **not** swept across the other ~25 files with the same
  `all_inventory(environment(...))` pattern (documented as a residual gap,
  section 12).
- **`call_other()` on a `0` target hard-errors** on this driver instead of
  silently returning `0`. Confirmed live in two places: `player.lpc`'s
  `executeCommand()` fallback to a possibly-uninitialized research service,
  and `combat.lpc`'s `calculateAttack()` calling into a possibly-absent
  `inventory` module (hit via `score.lpc`'s weapon-stat display running
  outside real combat). Both guarded with an `objectp()` check before the
  call; the underlying "why is this module sometimes absent" question
  (likely upstream's own design, not a porting artifact) wasn't
  investigated further.
- **Diamond-inheritance conflicts elsewhere**: `experienceDataService.lpc`
  had 4 private functions colliding with `relationshipsDataService.lpc`
  once both got combined into `dataAccess.lpc`'s aggregate (renamed with an
  `exp`-prefix); `inventory.lpc`'s `getSkillModifier` collided with
  `skills.lpc`'s same-named function (renamed to `itemGetSkillModifier`).
- **`remove_action(1, ob)`** (LDMud's "remove every add_action this object
  registered on `ob`" bulk form) doesn't exist -- confirmed against
  `core.spec`, this driver's real `remove_action(fun, verb)` needs an
  explicit verb. Two of three occurrences (`baseSelector.lpc`,
  `researchChooser.lpc`) had a recoverable exact verb (the only
  registration each object ever makes, called from within that same
  callback) and got a precise `remove_action("verbName", "")` fix; the
  remaining two elsewhere in this port (`lib/environment/environment.lpc`,
  `lib/modules/conversations.lpc`) had no recoverable verb and the call was
  simply dropped (documented rationale in each file).
- MySQL provisioning quirks: `log_bin_trust_function_creators=1` needed on
  the root connection for this schema's stored functions;
  `db_fetch()` on this driver returns `({})` (truthy) for "no rows", not
  `0` -- a pre-existing `result && result[0]` pattern in
  `validateDatabase()` assumed the LDMud-style falsy-0 convention and threw
  "Array index out of bounds".
- One pre-existing upstream typo fixed while investigating an unrelated
  crash: `dataAccess.lpc` had `\x1b0;37;1m` (missing `[` after the ESC
  byte) in an ANSI color sequence -- LDMud's string-escape parser
  apparently tolerated it; this driver's stricter parser rejected it
  outright ("Illegal character constant"). Every other ANSI sequence in the
  same codebase correctly has `\x1b[...`.

## 12. Residual gaps (documented, not fixed this session)

- **Wizard *command execution* not fully verified.** The admin account
  (`fluffos`, `owner` rank) is confirmed to be a genuine
  `/lib/realizations/wizard.lpc` instance and can play the core game
  normally, and the section 9 fix confirmed wizard commands are no longer
  categorically excluded from dispatch -- but actual command execution
  (`ls`, `pwd`, `cc`, ...) still additionally requires passing
  `lib/services/groups/baseGroup.lpc`'s file-permission checks
  (`hasExecuteAccess()` via `groupObjects()`/`isMemberOf()`/
  `getPermissionForPath()`). Those loaded without any driver-level error
  during testing, but this session ran out of time to trace why they still
  deny a rank that should have full permissions -- unclear whether this
  needs additional data seeding (a permission-map default this session
  didn't provision) or is a genuine remaining logic bug. Not confirmed as
  either a driver-compat issue or upstream content/design, so left
  unresolved rather than guessed at.
- **`score`'s weapon-stat display** can still hit a null-`getModule
  ("inventory")` `call_other()` error in `combat.lpc`'s
  `calculateDamage()` (a second call site with the same class of bug as
  section 11's guarded `calculateAttack()` -- not swept further).
- **`all_inventory(environment(...))`** without a null guard appears in
  ~25 other files beyond the one (`look.lpc`) confirmed to crash live and
  fixed.
- **`remove_action(1, ob)`** and **`inherit_list(x)` self-class-check**
  idioms both plausibly recur elsewhere in this ~16,570-file codebase
  beyond the confirmed-live instances fixed. No corpus-wide grep sweep was
  completed for either given the time already spent tracing the chain of
  bugs each fix uncovered.
- **`/lib/services/regionService.lpc`** (a `#include`d header path with a
  double-slash typo, `/lib//services/regions/terrain.h`, plus a genuine
  `syntax error, unexpected L_CLASS`) and **`/lib/commands/wizard/
  patch.lpc`** (`to_object`/`apply` -- neither exists on this driver) both
  fail to compile from unrelated upstream issues. Neither file is on the
  tested critical path (region generation, wizard `patch` command); both
  are pre-existing compile-error residue, not swept this session.
- The unit-test suite under `/lib/tests/` (excluded from preload, so
  never loaded during normal play) was not run or verified beyond the
  mechanical `catch(expr; nolog)` sweep in section 8 -- it may have its own
  additional compile issues unrelated to gameplay.

## 13. MySQL provisioning (session-local, not part of the shipped repo)

A fresh clone of this repo needs its own MySQL 8.0+ instance -- this is
**not** bundled or automated by this port; it matches the repo's own
README installation instructions. This session provisioned one locally via
`apt-get download` + `dpkg-deb -x` (no root needed) for portable
`mysqld`/`mysql` binaries, a throwaway datadir, and
`log_bin_trust_function_creators=1` set on the root connection (required
for this schema's stored functions). `secure/simulated-efuns/database.lpc`'s
`RealmsDatabase()` (returns `"RealmsLib"`) names the expected schema; point
a real MySQL instance at that name and this driver's own `db_connect()`
(FluffOS's `(host, database, user, type)` argument order, not LDMud's) will
reach it.
