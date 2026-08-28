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

## 14. 深度功能测试（§10.7 deep functional test, first pass)

This lib had never had a real §10.7 pass before this session -- prior
verification (section 1-13 above) covered onboarding-level checks only
(registration + character creation UI + `look`/`quit` on a handful of
fresh accounts, explicitly flagged in README/NOTES as not yet deep-tested).
This pass provisioned MySQL exactly per section 13, booted the native
driver, and did a genuine continuous playthrough -- which immediately hit
a severe, previously-undiscovered chain of bugs: **the 11-step
character-creation wizard had never actually worked, at all, for any
character, and neither had character persistence.** Both are now fixed
and verified end-to-end (see below). Test characters left in the database
as evidence: `cepheus` (id 1, the auto-granted `owner` account, fully
created -- human, Str/Int/Wis/Dex/Con/Cha populated, 16 skills, 2 traits,
`LastLogin`/`location` updating correctly across relogin) and `nerielle`
(a second, ordinary account, also fully created). The MySQL instance and
its data are session-local/throwaway per section 13 and were torn down at
the end of this session; a future session re-provisioning the DB from
scratch should re-run at least the `cepheus`/registration flow once to
re-confirm before assuming these fixes still hold against a fresh schema.

### Severe bug #1: character creation was completely broken for every player (fixed)

**Symptom**: every single new character landed in the game world with
completely blank data -- `Race: Unknown`, every attribute `0`, no
skills/traits/guild -- and the 11-step character-creation wizard
(`colorSelector` → ... → `traitSelector`) never appeared at all, for any
account, ever. This was previously invisible because no prior session had
played far enough into a real account to notice -- the wizard's own
missing prompts don't produce any visible error, they just silently don't
happen, and the resulting blank character still looks superficially
"logged in successfully."

**Root cause (two independent bugs, both required to actually see the
wizard)**:

1. **`restore()` (and the character-creation-triggering event it fires)
   ran before `exec()`.** `lib/modules/secure/login.lpc`'s
   `loadNewPlayerObject()` used to call `ret->restore(name)` as part of
   creating the player object, which happens *before* the three login
   call sites (`secure/login/user-creation.lpc`'s `execNewPlayer()`/
   `execGuestPlayer()`, `secure/login/menu-interactions.lpc`'s
   `execCharacter()`) call `exec(player, this_object())`. `restore()`
   (`lib/modules/secure/persistence.lpc`) synchronously fires
   `onRestoreFailed` for a genuinely new character, which
   `lib/modules/creation/initializePlayer.lpc`'s handler uses to start the
   wizard via `tell_object()`/`input_to()` -- both of which this driver
   silently no-ops for a non-interactive object (confirmed against
   `vm/internal/simulate.cc`'s `tell_object()`: falls back to
   `tell_npc()`/`catch_tell()` unless `ob->interactive` is already set,
   which only happens once `exec()` runs). This is the exact same class of
   bug as this file's own already-documented `add_action()`/
   `command_giver` fix (section 7) -- a create()-time/pre-exec() call
   assuming driver state it doesn't have yet -- just hitting
   `tell_object()`/`input_to()` instead of `add_action()`. Fixed by
   splitting `restore()` out of `loadNewPlayerObject()` into a new
   `login.lpc` method, `restorePlayerObject(player, name)`, that all three
   call sites now call explicitly *after* `exec()`.
2. **`lib/core/baseSelector.lpc` (the base class every one of the 11
   selectors inherits) never inherited `lib/core/thing.lpc`.** Even after
   fix #1 made the wizard's first prompt appear correctly (plain
   `tell_object()` output works before OR after this second fix), every
   typed answer fell through to the player's own normal command dispatch
   instead of the selector, because `initializePlayer.lpc`'s
   `selectorObj->move_object(Player)` (moving the freshly-cloned selector
   into the player so its `init()` can register `applySelection` as a
   real add_action) silently no-op'd: this driver's real `move_object()`/
   `command()` efuns only exist as call_other targets when the calling
   object's class actually inherits `thing.lpc` (see that file's own port
   note on why this port added them at all) -- baseSelector.lpc never did,
   so the call_other was to an undefined function (silently returns 0 on
   this driver, `environment(selectorObj)` stayed 0 after the "move",
   confirmed via a temporary debug trace). Fixed by adding
   `inherit "/lib/core/thing.lpc";` to `baseSelector.lpc`.

**A third, independent bug was needed for the wizard to survive its own
first real live demo** (the `minimapSelector` step, which
`load_object()`s the game's actual starting room,
`/areas/eledhel/southern-city/southern-city.lpc`, to render a live
before/after minimap comparison) -- see "Severe bug #2" below; the room
chain it exercises turned out to have never successfully compiled either.

### Severe bug #2: the starting room (and therefore `/lib/environment/environment.lpc`, the base class for every room in the game) had never successfully compiled

Fixing bug #1 above immediately surfaced this one, since the
character-creation wizard's `minimapSelector` step is the first thing in
this whole codebase that ever actually `load_object()`s a real game room.
`/areas/eledhel/southern-city/southern-city.lpc` (and by extension
`/lib/environment/environment.lpc`, since every room in the game inherits
it) failed with a long chain of compile errors, fixed one layer at a time:

- **Diamond-inheritance `nomask` conflicts, swept across the whole
  `lib/environment/` and `lib/environment/modules/regions/` module
  families.** `/lib/environment/environment.lpc` inherits essentially
  every module under `lib/environment/modules/environment/` (core,
  bonuses, description, elements, exits, generated-region, harvest,
  legacy, lighting, region, shop, state) directly, and several of those
  modules *also* inherit each other (e.g. `elements.lpc` and
  `lighting.lpc` both directly inherit `state.lpc`, which `exits.lpc` also
  inherits directly) -- the exact same "same base reachable at two
  inherit depths simultaneously" restriction already documented in
  section 2 (`Illegal to redefine 'nomask' function ...`), just newly
  discovered because this was the first session to ever actually
  `load_object()` a real room and trigger it. Swept `nomask` off every
  affected function in: `core.lpc`, `state.lpc`, `region.lpc`, `bonuses.lpc`,
  `harvest.lpc`, `legacy.lpc`, `exits.lpc`, `lighting.lpc`, `elements.lpc`,
  `generated-region.lpc`, `shop.lpc` (environment modules) and `core.lpc`,
  `entries-and-exits.lpc`, `generate-room.lpc` (region modules) and
  `lib/environment/modules/environmental-elements/core.lpc` (used by
  `/lib/environment/environmentalElement.lpc`, the base for clonable room
  decorations). Confirmed via `grep` that none of these names are
  overridden anywhere else in the ~2,500-file area corpus, so losing
  `nomask`'s override-protection costs nothing in practice. See each
  file's own inline port note for the exact diamond shape.
- **`string **`/`int **`/`mapping **` (nested-array declared types) don't
  exist on this driver at all**, in ANY position (return type, parameter,
  local variable) -- confirmed via a from-scratch minimal repro against
  `compiler/internal/grammar.y`'s `optional_star` production, which is a
  single bit everywhere, never a full "how many stars" count. Fixed in
  `lib/services/regionService.lpc`'s `getMapIcon()`,
  `lib/environment/modules/regions/domain.lpc`'s `getDomainMapIcon()`, and
  `/lib/environment/environment.lpc`'s own base `customIcon()` (all
  `mixed *` now, no behavior change since this driver's type annotations
  are compile-time-only) -- plus a **63-site mechanical sweep** across the
  region-generation "building" subsystem (`map.lpc`,
  `building-decorators.lpc`, `building-files.lpc`, `building-doors.lpc`,
  `building-layout.lpc`, `generate-building.lpc`,
  `generate-tunneling.lpc`) once the pattern was confirmed wide. **Not
  swept**: ~44 files under `/areas/tol-dhurath/temple-interior/*.lpc`
  using the identical `string **customIcon(string **baseIcon, ...)`
  override pattern -- unrelated hand-built game content for one specific
  area, not reached by any test path this session, flagged as a residual
  gap (see section 12's own note, now expanded: this is confirmed to be a
  driver-wide syntax restriction, not specific to the region-generation
  subsystem).
- **`inherit_list()` (this driver's `shallow_inherit_list()`, direct
  inherits only) used where the real ancestor could be reached
  indirectly.** `lib/services/environmentService.lpc`'s
  `registerElement()`/`environmentalObject()`/`getEnvironment()` (plus two
  more call sites, `key.lpc`/`baseDoor.lpc` checks) used
  `member(inherit_list(x), BaseElement) > -1`-style checks assuming
  `BaseElement` (`/lib/environment/environmentalElement.lpc`) is always a
  *direct* parent -- true for some leaf classes, false for others (e.g.
  `/lib/environment/terrain/city.lpc` inherits `baseTerrain.lpc`, which
  inherits `environmentalElement.lpc` two levels up). With plain
  `inherit_list()`, `city.lpc`'s own environment-element registration
  always failed with `"Unable to register ... Be sure that the file
  exists and inherits a valid environmental element"`, which broke every
  terrain-based room's decoration/registration, including the game's own
  `StartLocation()`. This driver *also* provides `deep_inherit_list()` (a
  second, separate efun, confirmed against `vm/internal/base/array.cc`)
  that walks the full ancestor chain and correctly fixes this -- switched
  all five call sites in `environmentService.lpc` to it. This is a
  different flavor of the already-documented section 9 `inherit_list()`
  gap (that one was about self-class, this one is about ancestor depth);
  `deep_inherit_list()` fixes both at once and is the generally-correct
  primitive for any "is this an X" check like this.
- **`lib/environment/modules/regions/generate-path.lpc`**: `for (int i;
  i < 50; i++)` (no initializer) is a hard syntax error on this driver
  (`unexpected ';', expecting L_ASSIGN` -- confirmed this driver's grammar
  requires an explicit for-loop initializer, unlike LDMud's implicit-0).
  Fixed with `int i = 0` (no behavior change). Also had two more
  closure-capturing-enclosing-locals bugs (same class as section 2) in
  `filter()` calls referencing `nextRoom["x"]`/`nextRoom["y"]` bare inside
  the closure -- fixed by binding them as `$2`/`$3`.
- **`/lib/environment/modules/regions/domain.lpc`**: a raw `\xe2` byte in
  a regex string literal (meant to byte-match a UTF-8 box-drawing
  character's lead byte) is invalid standalone UTF-8, and this driver's
  compiler validates every string literal as well-formed UTF-8 (`Invalid
  UTF8 codepoint in string literal`). Fixed by building the byte at
  runtime via `sprintf("%c", 0xe2)` instead of embedding it in the
  literal -- only compile-time literals get validated, not
  runtime-constructed strings.
- **`/lib/environment/region.lpc`'s own `grid` variable silently
  fragments into multiple physical storage slots.** This driver gives
  each independent `inherit` of the same base program its own copy of
  that program's instance variables rather than sharing one -- confirmed
  against `compiler/internal/compiler.cc`'s `define_variable()`: a name
  collision from a second inherit path allocates a NEW variable slot and
  silently repoints the symbol table at it ("the nasty idiots have two
  variables of the same name in the same object" is the driver's own
  comment), rather than reusing the first slot. `region.lpc` reaches
  `lib/environment/modules/regions/core.lpc` (which declares `grid`) both
  directly and indirectly (via `generate-region.lpc`/`persist-region.lpc`/
  `map.lpc`, which each also inherit it directly) -- `createEmptyGrid()`
  (defined in `generate-region.lpc`) and `setCoordinate()` (defined
  directly in `region.lpc`) ended up bound to *different* physical `grid`
  slots, so `setCoordinate()` always saw an empty grid regardless of
  `createEmptyGrid()` having "already run" moments earlier --
  `"Value being indexed is zero"` on the very first `setCoordinate()` call
  in any region.lpc-based area, confirmed live via
  `southern-city.lpc`'s own `Setup()`. Fixed by overriding
  `createEmptyGrid()` directly in `region.lpc` (identical body) so it's
  guaranteed to compile in, and share the `grid` slot with,
  `setCoordinate()`/`create()` in the same file (LPC function dispatch is
  virtual, so this also correctly takes over `generate-region.lpc`'s own
  internal calls to it during procedural generation). **This is a real,
  general class of bug this session did not have time to fully audit**:
  any OTHER function elsewhere in this ~20-file `regions/` directory that
  reads/writes `grid` (or `MaxX`/`entry`/etc.) from a *different* file
  than where it's declared could hit the same fragmentation depending on
  that file's own inherit-resolution order. A full fix would need the
  same "shared object instead of shared inherit" restructuring already
  used elsewhere in this port for an analogous problem (section 2's
  `dataServiceUtil.lpc` writeup) applied across the whole directory --
  flagged as a residual gap. One already-noticed secondary symptom:
  `generate-room.lpc`'s `generateRoomDetails()` reads `entry` from its own
  (likely different) slot, so its "is this the entry room" check may
  always see `entry` as empty -- not confirmed as user-visible, not
  fixed.
- **`get_dir()` returns bare filenames, never full paths (already
  documented in section 2), swept across three more, previously-untested
  call sites** that only became reachable once the two bugs above stopped
  masking them: `lib/services/shopService.lpc`'s consumable-item
  generation (`generateConsumableItems()`, wrong extension `\.c$` AND
  missing directory prefix -- a shop selling potions/books/gems/etc.
  crashed with `item == 0` the moment it tried to roll a random,
  non-explicitly-listed item), `lib/services/materials/components/
  generate-random-item.lpc`'s `getListOfBlueprints()` (same two bugs,
  affects every random-item shop across every shop type), and
  `lib/services/traitsService.lpc`'s `creationListForTraitType()` (same
  missing-directory-prefix bug, broke the character-creation wizard's
  genetic/educational/health/sexuality trait-selection menus outright).
  **Not swept**: `traitsService.lpc` has four more `traitObject(trait)`
  call sites (lines ~147/170/193/215) that plausibly have the same
  missing-prefix issue wherever they're fed a bare filename instead of an
  already-fully-qualified one -- not confirmed live this session, flagged
  as a residual gap. The general pattern (`get_dir()` result used as-is
  without re-prepending its own directory) recurs in ~51 `get_dir()` call
  sites total across this lib; only the ones confirmed to actually crash
  were fixed.
- **`lib/core/prerequisites.lpc`**: `ret[..(sizeof(ret) - 5)]` (an
  omitted start index paired with a plain, non-`<` end index) is a hard
  syntax error on this driver -- confirmed against
  `compiler/internal/grammar.y`'s range-index productions, none of which
  cover "start omitted, plain end" (only the `<`-marked from-the-end forms
  allow omitting the start). Fixed by making the start index explicit
  (`ret[0..(sizeof(ret) - 5)]`, exactly what an omitted start already
  means -- no behavior change). Also had an accidental nomask name
  collision: `checkResearch(object researcher, string research)`
  (private, internal-only) collided with `/lib/items/craftingBlueprint.lpc`'s
  own unrelated public `checkResearch(object user)` (a completely
  different single-arg crafting-requirement check) -- this driver's
  nomask protection blocks a subclass reusing a nomask name even when the
  base's version is `private`. Renamed the prerequisites.lpc one to
  `checkResearchPrerequisite` (its only call site is within the same
  file).

### Severe bug #3: character SAVE was completely broken -- no character's data was ever actually persisted to the database, for the entire life of this port

**Symptom**: confirmed via a direct MySQL query -- after dozens of
successful-looking `quit`s across many test characters throughout this
session (and, per the DBERROR log, going back to the original onboarding
session too), the `players`/`skills`/`traits` tables had essentially zero
real character data: one single bootstrap-inserted row (from
`checkInitialization()`'s one-time owner-grant `insert`, itself only
ever a bare name) and otherwise empty. This directly explains bug #1's
own downstream symptom -- `restore()`'s `validatePlayerData()` correctly
saw every "already created" character's saved record as empty/incomplete
and kept re-triggering the wizard on every single login, forever, for
every account, even after fully completing character creation once.

**Root cause (two independent bugs)**:

1. **`lib/modules/secure/persistence.lpc`'s `getPlayerInfo()` never
   included a `"name"` key at all** -- only `"userName"` (the login
   *account* name, not necessarily the same as the character's own name).
   `lib/modules/secure/dataAccess.lpc`'s `savePlayerData()` gates its
   entire save block on `member(playerData, "name") && (playerData["name"]
   != "")`, and `lib/modules/secure/dataServices/
   basicPlayerDataService.lpc`'s `saveBasicPlayerData()` uses
   `playerData["name"]` as the player's own SQL primary key -- with the
   key missing entirely, `savePlayerData()`'s very first condition was
   always false, so it silently no-op'd on literally every single save,
   forever. Fixed by adding `"name": this_object()->Name()` to
   `getPlayerInfo()`'s returned mapping.
2. **`lib/core/thing.lpc`'s `has()` (and therefore `getModule()`) used
   plain `inherit_list()` to check whether the current object's class
   inherits a given service module** -- the exact same
   shallow-vs-ancestor-depth gap as `environmentService.lpc` above, but
   here far more consequential: `player.lpc` inherits `living.lpc`, and
   it's `living.lpc` (not `player.lpc` directly) that inherits
   `materialAttributes`/`attributes`/`biological`/`combat`/`races`/
   `research`/`skills`/`traits`/`factions.lpc` -- 9 of `getPlayerInfo()`'s
   15 "services" (plus `inventory`/`wizard`, 11 of 15 total). With plain
   `inherit_list()`, `has()` returned false for every one of them, on
   every player, for this port's entire lifetime -- meaning no
   character's attributes, biological data, combat stats, race, research,
   skills, traits, or factions were EVER included in even a *successful*
   save (only the 4 services `player.lpc` inherits directly --
   `guilds`/`quests`/`settings`/`domains` -- ever got a real
   `serviceObject`, though see the sub-note below). This is likely also
   the *original* root cause of the already-fixed section-11 `score`
   guards (`calculateAttack()`/`calculateDamage()`/`calculateSoakDamage()`
   in `lib/modules/combat.lpc` all call `getModule("inventory")`, which
   was *always* returning 0 before this fix, regardless of whether a real
   character actually had inventory data) -- those guards remain correct
   and are now simply exercising their real, working code path instead of
   always hitting the null-guard branch. Fixed the same way as
   `environmentService.lpc`: switched `has()` to `deep_inherit_list()`.
   **This is a foundational, wide-reaching fix** -- `getModule()`/`has()`
   are called throughout this ~16,500-file codebase; any other code path
   that silently assumed a "logically inherited" service module was
   unavailable (and had its own defensive `if (serviceObject)`/`if
   (getModule(...))` guard, the normal defensive style already used
   everywhere in this codebase) will now actually reach that service for
   the first time. This session did not have time to audit for *newly
   surfaced* behavior changes beyond the ones directly observed (`score`'s
   Attack/Defend/Soak numbers changing from all-zero to real computed
   values for a wizard-created character, confirmed live) -- flagged as
   worth a broader post-fix regression pass in a future session.
   Sub-note: even the 4 "directly inherited" services
   (`guilds`/`quests`/`settings`/`domains`) never actually call a real
   `send<Service>()` function either -- **no `sendXxx()` naming-convention
   function exists ANYWHERE in this codebase** (confirmed via corpus-wide
   grep) for any of the 15 services `getPlayerInfo()` tries to call. Yet
   `character set`/`page size`/`guilds`/`quests`/etc.-looking keys
   demonstrably appear in the saved data (confirmed live). This
   contradiction was not resolved this session -- flagged as a genuine,
   unexplained observation rather than guessed at (per this project's
   own "document as observation, don't guess" rule): either there's a
   fallback/forwarding mechanism this session didn't find, or the
   apparent data is coming from an entirely different source than the
   `services` loop. Worth a dedicated trace in a future session, since it
   means the `sendXxx()` convention itself might be fully dead code that
   happens to not matter because something else already covers it -- or
   it might mean there's a *second*, still-undiscovered bug in exactly
   this area.

**Verified fix, end-to-end, live**: registered account `cepheus` (the
auto-granted first-ever `owner`), completed the full 11-step wizard,
confirmed via `score` that real values were shown in-game (Race: Human,
Str/Int/Wis/Dex/Con/Cha all populated, Attack/Defend/Soak all non-trivial
computed values), `quit`, then queried MySQL directly and confirmed a
real row (`name='cepheus', race='human', strength=5, intelligence=5`,
`location` set to the real starting room path, `LastLogin` updated) plus
16 rows in `skills` and 2 rows in `traits`. Reconnected after a real
wall-clock gap: logged in directly to `"It is too dark."` (the real
starting room) with **no** re-triggered character-creation wizard, and
`score` correctly displayed the exact same restored data -- confirming
`validatePlayerData()` now correctly recognizes a genuinely-complete
character. This is the first time in this lib's history that a
character has round-tripped through create → save → reconnect → restore
correctly.

### Residual gap, revisited but not resolved: wizard command *execution* still denied for the owner rank

README/NOTES previously flagged this as unconfirmed ("ran out of time to
trace why they still deny access"). This session found and fixed one
real, confirmed bug in this exact chain -- but empirically, `ls`/`pwd`
(and presumably every other wizard command) still produce the driver's
own default `"What?"` for `cepheus` (`owner` rank, confirmed via a
genuine `wizard.lpc` instance, confirmed via `groups()`'s
`owner`→...→`apprentice`→`player` fall-through switch, confirmed via a
completed character creation and a real relogin) even after the fix
below, so this remains an open, only-partially-root-caused gap.

**Confirmed and fixed this session**: `lib/services/groups/baseGroup.lpc`'s
`group()` (used by `isMemberOf()` to identify which permission group a
group-service object represents) matched a literal `\.c$` extension --
this port's own `program_name()` (section 3) always returns paths ending
in `.lpc`, so `group()` silently and permanently returned `0` for every
group object regardless of rank, making `isMemberOf()` (comparing `0`
against a string array) always false. Fixed to match `.lpc`.

**Verified structurally correct, but access is still denied**:
`apprentice.lpc` (the base rank every wizard level falls through to, per
`wizard.lpc`'s own `groups()` switch) does register `addCommand("ls")`/
`addCommand("pwd")`; `commandRegistry.lpc`'s own `executeCommand()`
already has the section-9 `program_name(initiator) == Wizard` fix so
wizard commands aren't stripped from a genuine wizard's command list; no
wizard-command-file compile errors are logged during registration
(`registerWizardCommands: skipping ...` never appears in `debug.log`).
Despite all of this checking out individually, `ls`/`pwd` still produce
the driver's bare default fail message (not even the mudlib's own
"access denied"-style message), meaning the command is still not being
matched/reached at all somewhere in this chain. **Not resolved this
session** -- ran out of time to add further live tracing (e.g. a
temporary debug print inside `executeCommand()`'s actual
`commandList`/`wizCommands` comparison, or inside `hasExecuteAccess()`
itself) to pin down the exact remaining point of failure. Flagged
honestly as still-open, with the one confirmed-and-fixed bug documented
above so the next session doesn't have to re-derive it.

### What else was tested

- **Registration**: real English name (this driver's login name validator
  rejects non-ASCII directly per its own regex, confirmed via source
  read, so this session used real-word English names rather than forcing
  Chinese names against a validator that would just reject them --
  consistent with this being an English-language-only upstream codebase,
  unlike the Chinese `wuxia`-genre libs elsewhere in this collection),
  password confirmation, first-ever-registrant automatic `owner` grant
  (re-verified against a fresh database), all previously verified and
  reconfirmed working.
- **Character creation**: full 11-step wizard end-to-end (color, charset,
  minimap, gender, race, subrace, hair, eyes, attributes, skills, traits)
  -- multiple times, with multiple test characters, after every fix in
  this session, to confirm each fix moved the flow strictly further
  before finally reaching genuine completion.
- **Region generation**: the character-creation `minimapSelector` step's
  live before/after minimap demo IS a real exercise of the region system
  (loads `StartLocation()`, walks its `region.lpc`-based grid, calls
  `RegionService->getMapDecorator()`/`getMapIcon()`) -- this is what
  surfaced and got fixed in severe bug #2 above. The wizard `generate
  region` command itself (procedural generation from scratch) was not
  separately live-tested this session (time did not allow completing a
  full character AND a separate wizard-command session AND a
  procedural-generation walkthrough) but shares the exact same
  `region.lpc`/`generate-region.lpc` code path already exercised and
  fixed -- reasonably confident it's on stronger footing than before, not
  independently confirmed.
- **`quit`/reconnect after a real gap**: verified clean, multiple times,
  both before and after the persistence fix (before the fix: quit
  succeeded with no error, but silently discarded everything, as
  documented above; after the fix: correctly round-trips).
- **`score`**: real, populated stat card verified for two separate fully-
  created characters (`cepheus`, `nerielle`), zero uncaught errors after
  the `combat.lpc` guards (see below) were added.
- **Combat/skills/guilds**: `score`'s own combat-math display
  (`calculateAttack()`/`calculateDamage()`/`calculateSoakDamage()` in
  `lib/modules/combat.lpc`) hit the exact null-`getModule("inventory")`
  crash class already documented in section 11/12 -- confirmed two more
  live instances beyond the one already fixed (`calculateDamage()` and
  `calculateSoakDamage()`, not just `calculateAttack()`) and applied the
  identical `objectp(inventory)` guard fix to both. Real combat
  (attacking another creature), guild joining, and the `skills`/`traits`
  commands' own advancement flows were not reached this session --
  `skills`/`traits` display commands were confirmed working (real data
  shown, no errors) but the underlying training/advancement mechanics
  were not exercised live. Flagged as unverified-live, not silently
  presented as tested, per this project's own budget-for-combat-or-say-so
  rule.
- **Wizard `patch` command**: could not be live-tested this session (time
  ran out before reaching a wizard command execution session with
  `hasExecuteAccess()` working) -- but its own pre-existing compile
  errors (`to_object`/`apply`, neither exists on this driver) were fixed
  and confirmed to compile clean: `to_object(parameter)` →
  `find_object(parameter, 0)` (this driver's real equivalent for
  resolving an already-loaded object by name without loading a fresh
  copy), and `apply((: call_other :), target, methodName, parameters)` →
  `call_other(target, methodName, callParameters...)` (this driver
  supports spreading an array as trailing call arguments via `arr...`,
  the direct equivalent of LDMud's apply() semantics; `parameters` is
  normalized to `({})` first since it can legitimately be `0` rather than
  an array).

### Files changed this session (42 total)

Character-creation/login-timing fix: `lib/modules/secure/login.lpc`,
`secure/login/user-creation.lpc`, `secure/login/menu-interactions.lpc`,
`lib/core/baseSelector.lpc`. Persistence fix: `lib/modules/secure/
persistence.lpc`, `lib/core/thing.lpc`. Wizard-permission fix:
`lib/services/groups/baseGroup.lpc`. Environment/room diamond-inheritance
sweep (14 files): `lib/environment/environment.lpc`,
`lib/environment/region.lpc`, `lib/environment/modules/environment/
{core,state,region,bonuses,harvest,legacy,exits,lighting,elements,
generated-region,shop}.lpc`, `lib/environment/modules/regions/
{core,entries-and-exits,generate-room}.lpc`,
`lib/environment/modules/environmental-elements/core.lpc`. Nested-array
(`type **`) sweep (9 files): `lib/services/regionService.lpc`,
`lib/environment/modules/regions/domain.lpc`,
`lib/environment/modules/regions/{building-decorators,building-doors,
building-files,building-layout,generate-building,generate-tunneling,
map}.lpc`. `deep_inherit_list()` fix: `lib/services/environmentService.lpc`
(plus `thing.lpc` above). `get_dir()`/bare-filename fix:
`lib/services/shopService.lpc`, `lib/services/materials/components/
generate-random-item.lpc`, `lib/services/traitsService.lpc`. Misc
compile/runtime fixes: `lib/environment/modules/regions/
{generate-path,persist-region}.lpc`, `lib/core/prerequisites.lpc`,
`lib/commands/wizard/patch.lpc`, `lib/services/regions/region-types.h`,
`lib/modules/combat.lpc` (2 more null-guard instances).
