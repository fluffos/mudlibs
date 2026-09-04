# Haven ("havenmud") -- porting notes

Source: `git clone https://github.com/brainface/havenmud` (a single-
commit snapshot from 2023, cloned 2026-08-28). Repo top level: `bin/`
(driver-config scaffolding, ignored -- this project uses its own
driver), `ansible/`, `scripts/`, `smb.conf`, `Vagrantfile`, and `lib/`
(the real mudlib root, confirmed via `bin/haven.cfg`'s `master file :
/secure/daemon/master` and `mudlib directory : /home/haven/haven/lib`).
`secure/daemon/master.c`'s header credits "Descartes of Borg 940910"
and other file headers cite "Nightmare IVr2"/"Nightmare IVr3" and
"Dead Souls" lineages by name -- this is the same MudOS/FluffOS-
compatible Dead Souls/Nightmare family already represented in this
collection by `ds386`, `dsI`/`dsII`/`dsIII`, `dshakkard`, and
`deadsouls_fluffos`. Slug `havenmud`, number 947, port 40249.

Unlike `dshakkard` (a closed-alpha game with almost no bespoke
content beyond three domains) or the various near-stock Dead Souls
ports, this is a **large, long-lived production game**: 13,589 `.c`
files (7,328 under `domains/` alone), 21 custom domains, 25 personal
wizard realms under `realms/`, and its own pantheon/history/calendar
(`doc/help/players/timeline`). Unlike `dshakkard`, this repo commits
its own `secure/` tree in full -- no engine-layer gap to fill from a
sibling.

## 1. Conversion

`scripts/convert_lib.sh` against `raw/havenmud` (16,347 files copied
from the repo's own `lib/`): the content is already almost entirely
ASCII/UTF-8 (16,272 of 16,347 files needed no conversion at all; 7
clean re-conversions, 7 lossy, 61 skipped binaries), matching the
`imud`-class precedent for an English-language source rather than the
usual GBK/GB18030 corpus. 13,589 files renamed `.c`->`.lpc`, 1,188
literal `.c"`-reference fixups, 37 local angle-bracket includes
converted to quotes, 12,234 files touched by the `static`->`nosave`
sweep. Removed two genuine non-content binaries the conversion pass
correctly left alone: a stray macOS `.DS_Store` (`std/mine/`) and a
999,992-byte stale `secure/tmp/swap.mud.5000` runtime swap file that
had been accidentally committed to the original repo.

A tree-wide Python UTF-8 decode scan (per AGENTS.md section 4.1, run
against the WHOLE `work/` tree, not just `.lpc`/`.h`) found the
remaining 47 non-UTF-8-decodable files were all genuine binaries
(a `.bmp`, the `.DS_Store`/swap file above, and ~40 real Microsoft
Word `.doc` design documents under `realms/zalbar/oldfiles/projects/
prison_tunnels/` -- a builder's abandoned project notes, left as-is,
same "someone's late-night work" class this project preserves rather
than discards).

## 2. Missing runtime scaffolding

This repo's `.gitignore` excludes the usual set of runtime-written
directories that were never committed: `/lib/log`, `/lib/tmp`,
`/lib/secure/save`, `/lib/ftp`, `/lib/news`, `/lib/worlds`, `/lib/bak`,
and several named `/lib/save/<category>` subdirectories (`boxes`,
`estates`, `kills`, `phouses`, `pshops`, `shops`, `vehicles`). All were
recreated with the standard placeholder-file convention (`foo.txt` in
otherwise-empty dirs so git tracks the directory shape), following the
`ds386`/`dshakkard` precedent:

- `log/`, `log/errors/` (one placeholder file per top-level `lib/`
  directory name, per-domain name, and per-realm name -- this
  codebase's `master.lpc:log_error()` routes compile warnings to
  `DIR_ERROR_LOGS "/" + <top-segment-or-realm-or-domain-name>`).
- `log/players/`, `log/inet/`, `log/watch/`, `log/reports/`,
  `log/open/`, `log/harass/` -- discovered live, not just via static
  grep: the very first `ConfirmName()` in registration calls
  `log_file("players/newbies", ...)`, which crashed with `Wrong
  permissions for opening file /log/players/newbies for append` (`log/
  players/` didn't exist) on the first live registration attempt.
- `tmp/`, `ftp/`, `news/`, `worlds/`.
- `secure/save/`, `secure/save/immortals/`, `secure/save/players/`,
  `secure/save/newsgroups/` (this codebase's `DIR_CRES` self-heals its
  letter-bucket via `mkdir()` in several admin commands but never the
  base directory; `DIR_PLAYERS` already self-heals fully via
  `master.lpc`'s own `compile_object()`).
- `secure/save/votes/` -- `secure/daemon/voting.lpc`'s `eventSave()`
  otherwise fails `Could not open /secure/save/votes/voting.o.tmp for
  a save` on every reset, caught but noisy in `log/catch`.

Unlike `dshakkard`'s identical-shaped gap, this repo's own
`secure/tmp/` was already present and correct (just holding one stale
swap file, removed per section 1 above) -- only the top-level runtime
trees needed rebuilding.

## 3. Driver-compat fixes

### 3.1 `secure/daemon/master.lpc` -- missing PACKAGE_UIDS applies (AGENTS.md section 7.2)

No `get_root_uid()`/`get_bb_uid()`/`creator_file()` anywhere in this
codebase (confirmed zero `geteuid()`/`uid()` call sites -- permissions
are enforced entirely by the mudlib's own group/wizlist ACL, not the
driver's uid system). Added the standard minimal stubs (all objects
attributed to `"root"`), identical in shape to every other lib in this
lineage that needed this fix.

### 3.2 `secure/daemon/master.lpc:load_access()` -- a local variable named `ref` collides with this driver's `ref` keyword

```lpc
private nosave void load_access(string cfg, mapping ref) {
  ...
  ref[fl] = explode(ac, ":");
}
```

`ref` is a genuine lexer keyword on this driver (`L_REF`, used for
pass-by-reference call arguments) -- using it as a plain identifier
compiles the parameter declaration fine but hard-errors ("syntax
error, unexpected '['") the moment it's used as an lvalue later in the
same function, since the driver expects the `ref`-specific grammar
production there instead. This is the FIRST file loaded at boot
(`load_access()` runs from `create()`, called for read/write/groups
ACLs), so it was a hard boot blocker. Renamed the parameter to `acc`;
LPC mappings are reference types already, so nothing about the
by-reference-mutation behavior changed.

### 3.3 `lib/rooms/room.lpc` -- MudOS-era `replace_program()` fold (AGENTS.md section 7.141)

The exact same fold documented across this whole lineage
(`ds386`/`dsI`/`dsII`/`dsIII`/`dshakkard`): `create()` tried to fold a
bare-inherit room's program into its shared parent to save memory, but
this driver defers `replace_program()`'s effect to a periodic backend
sweep rather than applying it synchronously -- so any closure built on
a freshly-loaded room (this file's own `eventHearTalk()` `TALK_LOCAL`
filter, reached by ordinary `say`/`ask`/`tell`) would crash for the
first several minutes after every boot. Removed the fold entirely,
leaving `SetNoReplace()`/`GetNoReplace()` in place as harmless unused
API, exactly as fixed on every sibling.

### 3.4 OLD_ED vs. the split editor API (AGENTS.md section 6.2)

`lib/users/editor.lpc`, `lib/users/nmsh.lpc`, and `secure/cmds/
creators/lsed.lpc` all called `ed_start()`/`ed_cmd()`/`query_ed_mode()`,
which don't exist under this driver's `__OLD_ED__` build (only the
single-entry `ed()` efun exists). Since `editor.lpc` sits in the player
body's inheritance chain, this compile failure would have taken the
whole player body down with it. Fixed identically to the established
pattern: `editor.lpc` rewritten against `ed(file, exit_fn,
restricted)`; `nmsh.lpc`'s dead custom-prompt branch (already
unreachable once an `ed` session is open, since the driver's own
`comm.cc` intercepts input directly) collapsed to `if(0){...}`;
`lsed.lpc`'s core batch-editing function replaced with a "use `ed`
interactively instead" message, since there's no synchronous
scriptable-ed entry point under OLD_ED at all.

### 3.5 Bare `array` as a type specifier -- hard parse error, not silent mis-declaration

AGENTS.md section 6.3 describes bare `array x;` as typically compiling
without error but failing to actually declare anything. On this
specific driver build it's worse: `array` used as a type specifier
(variable, parameter, or return type) is a hard syntax error
(`unexpected L_IDENTIFIER`), including in a cast position
(`(string array)expr`). 13 files/19 sites fixed (`->` `mixed *`/
`mixed`): `lib/npcs/equipper.lpc`, `lib/livings/race.lpc`, `lib/users/
history.lpc`, `daemon/currency.lpc`, `domains/havenwood/areas/
parvahosp/obj/viallimb_f.lpc` (3 sites), `domains/westwood/areas/
hiker/obj/fruit.lpc`, `secure/daemon/newsgroup.lpc` (2 sites, including
`secure/daemon/include/newsgroup.h`'s matching forward declaration --
`newsgroup` is preloaded, so this alone blocked one boot-critical
daemon), `realms/melchezidek/currency.lpc`, `realms/melchezidek/
armours.lpc`, `realms/melchezidek/projects/starfire/npc/starfire.lpc`
(3 sites), `realms/melchezidek/projects/starfire/room/room08.lpc` (2
sites), `cmds/players/armours.lpc`.

### 3.6 The old-MudOS `TYPE array NAME` two-word dialect (AGENTS.md section 6.3)

356 files / 853 sites, fixed with a masked-text (string/comment-aware)
Python regex pass covering every shape this lineage's siblings already
documented (simple decl, decl-with-init, multi-name comma lists,
function parameters, return types, cast expressions). Verified safe
before running corpus-wide: dry-run diffed against hand-picked samples
(a function whose OWN return type and OWN parameter were both in the
old dialect on one line -- `string array SetRestrictLimbs(string array
limbs)` -- correctly became `string *SetRestrictLimbs(string *limbs)`)
and, after fixing a real bug in the first draft (naive in-place list
splicing shifted every later match's offset once an earlier
variable-length replacement changed the string's length -- rewritten
to build the output left-to-right from a sorted, non-overlapping match
list instead), a paren-balance diff between every touched file's raw
source and its fixed `work/` copy confirmed zero sites where the fixer
introduced or removed an unmatched `(`/`)` across all 356 files.

### 3.7 `daemon/command.lpc`'s `GetCommand()` -- the exact `[0..<3]` bug already found on `ds386`, and its wider sibling class

`cmd = file[0..<3]` while scanning `get_dir(path+"/*.lpc")` keeps
`len-2` characters -- correct for stripping the OLD `.c` MudOS
extension (2 characters) but wrong for `.lpc` (4 characters), turning
`"score.lpc"` into `"score.l"`. Since this daemon is how every
non-`add_action()` player/creator command resolves
(`cmds/players/*.lpc`, `cmds/creators/*.lpc`, etc.), this broke
**every single command dispatched through it** -- confirmed live: a
fresh character's first `score` command silently fell through to the
generic "unrecognized command" fallback with no error message at all,
while movement (`add_action()`-based, a different dispatch path
entirely) worked fine. This is the exact same bug, in the exact same
file, already found and fixed on `ds386` (AGENTS.md/`ds386` NOTES.md:
"broke the stock score command on every login... the single highest-
impact instance of the whole class").

Given the hit, swept the whole corpus for `ds386`'s documented sibling
variants of this same "hardcoded old 2-char `.c` suffix length,
should be 4 for `.lpc`" class and found it recurs **far more widely
here than on `ds386`** -- 24 more sites across 20 files:

- **Guarded pairs** (`X[<2..] == ".lpc"` -- checking the LAST 2
  CHARACTERS against a 4-character string, provably always false --
  paired with `X[0..<3]`): `lib/rooms/player_shop.lpc`, `lib/rooms/
  enter.lpc`, `lib/rooms/exits.lpc`, `lib/common/inventory.lpc`,
  `daemon/verbs.lpc`, `daemon/help.lpc`, `secure/cmds/creators/
  update.lpc`, `cmds/creators/showtree.lpc` -- fixed to `[<4..]`/
  `[0..<5]`.
- **Unguarded `[0..<3]` truncations** with no preceding length check:
  `lib/items/detect.lpc` (2 sites), `daemon/verbs.lpc` (a second,
  different site), `daemon/help.lpc` (2 more sites), `secure/cmds/
  admins/udspell.lpc`, plus `realms/duuk/help.lpc` (a personal-realm
  backup copy of `daemon/help.lpc`, fixed for consistency) -- fixed to
  `[0..<5]`.
- **`[<2..] != ".lpc"`-style append/skip guards** (always true/not-
  equal, so always taking the "not present" branch): `daemon/
  spells.lpc` (`if (spell[<2..] != ".lpc") continue;` in
  `GetSphereSpells()` -- this ALWAYS skipped every file, meaning the
  spell-sphere browsing feature returned an empty list for every
  sphere, always, until this fix), `secure/cmds/creators/update.lpc`,
  `secure/cmds/muses/approvecode.lpc`, `secure/cmds/creators/
  fixfile.lpc`, `secure/sefun/to_object.lpc`, `cmds/creators/
  clone.lpc` -- fixed to `[<4..]`.

Three superficially-similar `[0..<3]`/`[<2..]` sites were confirmed
NOT part of this bug class and left untouched: `lib/users/
history.lpc:113` (stripping a literal `"/g"` 2-char path fragment,
unrelated to `.lpc`), `secure/lib/net/ftp.lpc:441` (stripping a
trailing `"/."`, unrelated), and `secure/daemon/newsgroup.lpc:76`
(genuinely stripping the 2-character `.o` save-file extension, which
IS correctly 2 characters).

### 3.8 `lib/users/player.lpc:SetUndead()` -- bare-string calls into a `string *`-typed API

`RemoveAdditionalId(GetUndeadType())`/`SetAdditionalId(GetUndeadType())`
passed a bare `string` where both functions declare `string
*`. **This is the player body class itself** -- every single character
in the game inherits it -- so this alone hard-blocked all character
loading (`master.lpc`'s `player_object()` reported `*No program in
object '/lib/users/player'!` the moment any registration or login
tried to instantiate a new character). Fixed by wrapping both calls in
a single-element array (`({ GetUndeadType() })`), matching the
established convention already used correctly at dozens of other call
sites in this same codebase.

### 3.9 `SetLong()`/`SetShort()` narrowed to `string` where the real implementation already accepts `mixed` (the Dead Souls "SetLong/SetExternalDesc/SetInternalDesc widened to mixed" class, AGENTS.md, already fixed on `ds386`/`dsIII`/`dshakkard`)

`lib/common/look.lpc`'s `GetExternalDesc()` already handles a function
pointer or a `({day, night})` array in `ExternalDesc`, but its own
setters (`SetExternalDesc(string desc)`, `SetLong(string str)`) were
narrowly typed to `string` only -- widened both to `mixed`. This was
the single largest shared-root-cause cluster in the compile sweep
(`std/obj/screen.lpc`'s `SetLong((: eventView :))` alone cascaded into
77 reported failures across every object that inherits it). A second,
narrower instance: `lib/npcs/npc_interactive.lpc`'s pass-through
`SetShort(string str)`/`SetLong(string str)` wrappers (used by every
NPC) re-narrowed the already-widened base API -- widened to `mixed`
too, fixing `domains/valley/towns/jidoor/npc/sentry.lpc`'s
`SetShort((: CheckSetShort :))` and two similar NPCs.

### 3.10 `lib/rooms/chapel.lpc` -- `TYPE * a, b, c;` comma-list star-binding bug (AGENTS.md section 6.3)

```lpc
private string *Classes, Deities, DeityIds;
```

The `*` binds to the first declarator only on this driver; `Deities`/
`DeityIds` are used as `string *` everywhere in the file (assigned
array literals, indexed with `member_array()`), so both needed their
own `*`. This file is `inherit`ed wherever a marriage/chapel room
exists across the world, so the single missing `*` cascaded into
dozens of reported compile failures.

### 3.11 Author-level content bugs found via the compile sweep (fixed as unambiguous, evidence-backed type/argument-shape corrections, not invented content)

- **`std/spells/religion_eclat/revealrb.lpc`**: `SetMessages()` was
  called with a `mapping` literal where the base class's `Messages`
  field is genuinely an array-of-`(verbs, text)`-pairs (consumed as
  `Messages[i][0]`/`Messages[i][1]` elsewhere in `spell.lpc`) --
  reshaped to the real convention, using the exact same verb/text this
  file's own `eventCast()` already sends directly (so no behavior
  changed, just made the redundant `SetMessages()` call type-correct).
- **101 files' worth of `SetReligions("X")` / 4 files' `SetId("X")` /
  65+21 files' worth of `SetId`/`SetFriends` bare-string calls**
  across NPCs and spells, where the base API takes `string *` and
  correctly-written sibling call sites in the SAME files/domains
  already use `({ "X" })` -- confirms these are typos relative to an
  established local convention, not an alternate calling style. Fixed
  mechanically (`"X"` -> `({ "X" })`) everywhere the shape matched
  exactly.
- **`lib/items/seal.lpc:eventOpen()`**: `eventPick(who, tool)` was
  missing the middle `string id` argument entirely (`lib/verbs/
  lock.lpc`'s real signature is `eventPick(object who, string id,
  object tool)`), so `tool` (an object) landed in the `id` (string)
  slot -- a hard compile error. Since `seal.lpc` is the shared
  closeable+lockable composite `lib/items/door.lpc` inherits, this
  alone took down effectively every door in the game. `id` is only
  consumed by the (usually-unset) custom `Pick` closure, so `0` is a
  safe placeholder for this internal auto-pick-while-opening call,
  which has no player-typed identifier to supply.
- **`verbs/actions/{conspire,dust,parley,fade,rally}.lpc`**: each
  file's own `eventAction()` override called its own `eventAttack()`
  override BEFORE that override's real body appeared later in the same
  file -- AGENTS.md section 6.5's "a forward declaration is not
  enough, the override's real body must physically precede every
  same-file call site" class. Fixed by moving each file's `eventAttack()`
  definition earlier (right after the forward declarations), matching
  the exact reorder-fix already documented for this class. Five
  working siblings (`massacre`/`sweep`/`riposte`/`whirlwind`/`cleave`)
  never hit this because they use a deferred closure
  (`who->SetAttack(targets, (: eventAttack, who, targets :), ...)`)
  instead of a direct synchronous call, which isn't statically
  type-checked the same way.
- **`verbs/actions/rattle.lpc`**: forward-declared its own array-taking
  `eventAction(object who, object *target)` override but never actually
  defined a body for it, so `do_rattle()`'s `eventAction(this_player(),
  this_player()->GetEnemies())` resolved against the INHERITED
  single-object `eventAction()` instead and hard-failed to compile.
  Added the missing override, copied verbatim from the working
  `whirlwind.lpc` sibling's identical closure-based pattern (also
  needed a missing `#include <rounds.h>` for `ROUND_OTHER`).
- **`GetInvis(1)`** (3 files: `domains/valley/towns/jidoor/npc/
  sentry.lpc`, `realms/zalbar/oldfiles/projects/npc/guard.lpc`,
  `realms/zalbar/oldfiles/projects/drazh/npc/c_agent.lpc`): the real
  `GetInvis(object ob)` was called with the integer `1`; every other
  call site in the codebase (dozens, via `->`) uses the bare, no-arg
  form. Fixed to `GetInvis()`.
- **`SetPick(1)`/`SetPick(0)`** (5 files: two `display_case.lpc`
  copies, `shelf.lpc`, `hatch.lpc`, `cabinet.lpc`): `SetPick()` takes a
  function (a custom pick-check closure), not a boolean -- a
  self-evident author misunderstanding, already self-corrected once
  elsewhere in this exact codebase (a commented-out `//SetPick(1);` in
  `std/obj/lootchest.lpc`). Commented out identically rather than
  inventing a closure.
- **`realms/mahkefel/ideas_area/library/npc/wind_mephit.lpc`**:
  `SetNoCorpse("blah.")` (a `string` where the field is `int`) fixed to
  `SetNoCorpse(1)` -- narratively apt too, since a wind elemental
  "disperses into a fine mist" per its own death message.
- **`lib/special/planet.lpc`**: referenced `VS_SHUTTLE`, a vehicle-size
  constant that was never actually `#define`d anywhere in this archive
  (`include/vehicle.h` only goes up from `VS_YACHT`). Added as the
  smallest tier, one step below `VS_YACHT`, matching the file's
  existing size-ordered bitflag convention -- the only place this
  fix required adding a genuinely new constant rather than correcting
  an existing one, and its relative ordering (smaller than every other
  defined tier) is unambiguous from the name and the single call site's
  "too large to enter the atmosphere" gate.
- **`std/crafting/clothing/include/clothing.lpc`**: `SetSize(CraftSize)`
  passed the crafting subsystem's own free-text size STRING (already
  correctly stored one line above via `SetCraftSize()`) into
  `LIB_ARMOUR`'s numeric `SetSize(int)` -- a hard type mismatch with no
  string-to-int mapping anywhere in the codebase to derive the intended
  value from. Removed the always-broken, redundant line rather than
  inventing a mapping; affected every craftable clothing item (12
  files) via this one shared include.
- **`verbs/actions/obj/wound_hamstring.lpc`**: a missing comma before
  `env` in a multi-line `send_messages(...)` call (`"...weight!"` then
  directly `env` with no separator) -- a plain typo, fixed by adding
  the comma.

## 4. Known pre-existing gaps (left undone -- content/archive design, not driver-compat)

- **`std/tower/`** (~70 files: `critters/`, `rooms/`, `forest/`,
  `cavern/`, `weapons/`, `armour/`, `treasure/`): `inherit MONSTER;`
  where `MONSTER` and the `#include <mudlib.h>` it depends on don't
  exist ANYWHERE in this repo, and lowercase `set_name()`/`set_short()`
  API entirely foreign to this codebase's `SetKeyName()`/`SetShort()`
  convention. Confirmed via corpus-wide grep that nothing outside this
  directory references it at all -- a wholesale-imported, never-
  integrated bolt-on quest package, same non-bug class as this
  lineage's documented `stargate`/`open/prog` builder-scaffolding
  traps.
- **`realms/*/projects/*`, `realms/zalbar/oldfiles/*`,
  `realms/alessandra/malveillant/*`**: personal wizard staging/backup
  copies (some byte-identical duplicates of live daemon files missing
  their own header companion, e.g. `realms/duuk/classes.lpc`/
  `races.lpc`; some genuinely unfinished builder-template rooms with
  zero-argument `SetLong()`/`SetItems()`/`SetItemAdjectives()` stub
  calls, e.g. `realms/vaashan/projects/crypt/room/*`) -- the same
  "abandoned wizard scratch content" class already documented across
  this lineage (`dsI`'s `daemon/tmp/A_WEARON.lpc`, `dsII`'s `secure/
  tmp/cratylus_CMD_EVAL_TMP_FILE.lpc`, `dshakkard`'s `realms/muirrum`).
  Left undone rather than fabricating the missing companion files.
- **`realms/laoise/grym/npc/guard.lpc`**: `#include "../wanted.h"`
  doesn't resolve (no `wanted.h` in `realms/laoise/grym/`, only a
  sibling `grymxoria.h`) -- this personal realm appears to be an
  incomplete parallel copy of the real `estergrym`/`grymxoria` domain
  content. Left as a documented gap.
- **`secure/daemon/remote.lpc`** (Remote Creator Protocol, "from the
  Foundation II LPC Library", preloaded): its whole calling convention
  is raw-fd-based (`eventWrite(int fd, ...)`, `eventRead(int fd,
  ...)`), but this codebase's actual `secure/lib/net/server.lpc`
  (`LIB_SERVER`) is connection-OBJECT-based
  (`eventWrite(object owner, ...)`) -- a genuine architecture mismatch
  between a bolt-on protocol daemon and the engine it was dropped into,
  not a simple type-fix; a real rewrite of the daemon's whole
  fd-to-connection-object model, out of scope here. Its preload
  failure is caught by `master.lpc`'s own `preload()` (a logged
  warning, not a fatal boot error) -- wizard-only tooling, no bearing
  on ordinary play.

## 5. Live verification

Booted clean under `~/src/fluffos/build-debug/src/driver`
(`Accepting telnet connections on 0.0.0.0:40249.`, `Initializations
complete.`, zero fatal errors, ~290 MB RSS steady-state).

**Confirmed a real outbound network connection at boot**, same class
already documented for `ds386`/`dsIII`/`dshakkard`: `daemon/intermud`
(preloaded) connects to the public Intermud-3 router --
`ss -tnp` showed `ESTABLISHED ... 97.107.133.86:8787` from the driver
process, the exact same IMC2/I3 endpoint this lineage's other libs
connect to. **Do not sweep this lib into high-frequency automated
re-boot loops.**

Full registration -> world -> reconnect -> quit flow tested with a
raw Python socket client (this project's standard admin identity
wasn't set up for this lib -- see caveat below):

1. **New player registration** (`Testchartwo`, ASCII name -- this
   archive enforces a strict `A-Z a-z` name-charset with no digits,
   confirmed live: `Testchar2` was rejected as "not valid or is
   banished" while `Testchartwo` was accepted): name -> confirm (y/n)
   -> email (required, validated non-blank) -> password (6-char
   minimum) -> confirm password -> gender (male/female) -> real name
   (blank -> defaults sensibly) -> race (`list` showed all 11 playable
   races; `pick human`) -> hometown (`list` showed 4 towns; `pick
   haven`) -> landed in "In the skies above Kailie", the newbie
   staging room, correctly wearing starter clothes (threadbare pants/
   shirt/socks).
2. **The newbie gate**: the staging room's `down` exit is gated behind
   `read book` (completing the "Newbie Book" quest, which correctly
   awarded a real 160 development points and a quest/title credit
   live). Also confirmed the exit command itself is `go down`, not
   bare `down` (this codebase's core movement dispatch, unlike its
   `cmds/`-daemon-based commands, requires the `go` verb).
3. **Reached real custom domain content**: `go down` landed the
   character in **"Above the Elven Charity"** in Haven town
   (`domains/southern_coast/towns/haven/`) -- a fully-described,
   bespoke room (sleeping cots, a ticking clock, its own atmosphere
   text), not a stock/generic placeholder.
4. **`look`/`score`/`quit`** all produced correct output post-login;
   `score` in particular exercises a great deal of the player body
   class (level, alignment, native town/citizenship, faith, quest/
   title counts, in-game birth date and age, development points,
   wimpy percentage, hunger/thirst/intoxication/temperature status,
   combat ratings, heart rate, active fears) and came back fully
   correct and consistent across two separate test characters.
5. **Reconnect** (name + password, no `NetDead` state from a live
   session): restored the SAME character in the SAME room
   ("Above the Elven Charity") with inventory intact and stats
   preserved (quest/title/development-point state correctly carried
   over from the prior session's `read book`) -- confirmed this is a
   genuinely distinct code path from fresh registration, not just a
   re-run of the same logic.

**Caveat**: this lib has no first-boot admin-install wizard (unlike
the `ds386`-lineage Dead Souls forks) -- it's a live production game
whose wizard hierarchy is populated by manual `angel`/`decre`
promotion commands from an EXISTING admin account, and no such account
exists in this fresh checkout. Admin/wizard-level testing (the
`fluffos`/`Mud@2026` identity this project normally seeds) was not
attempted this session; only ordinary player registration and play
were verified. A future session wanting wizard access would need to
either hand-edit a save file's group membership or add a bootstrap
path -- left undone here as out of scope for the native-boot
verification bar.

## 6. Compile sweep

`(ulimit -v 8388608; bash scripts/lpcc_check.sh libs/havenmud/
config.fluffos libs/havenmud/work)` -- run under the 8 GB
virtual-memory cap per this session's standing caution for
large-corpus libs (a prior similarly-sized lib's unguarded batch
compile grew to ~15 GB RSS before being killed); this lib's own batch
run stayed under ~4 GB RSS throughout, well inside the cap. Iterated
four times across this session as fixes landed:

| pass | pass | fail | notes |
|------|------|------|-------|
| 1 | 9,024 | 4,565 | before any fixes beyond the proactive checklist |
| 2 | 9,268 | 4,321 | after the `SetReligions`/`SetId(animate_*)`/`eventAttack` reorder fixes |
| 3 | 9,343 | 4,246 | after chapel.lpc/screen.lpc/SetId+SetFriends sweeps, `GetInvis`/`SetPick`/`SetNoCorpse`/`VS_SHUTTLE`/`wound_hamstring` |
| 4 | 9,344 | 4,245 | after `player.lpc`, `command.lpc`, and the full `[0..<3]` sibling sweep (section 3.7-3.8) |

The remaining failures are overwhelmingly the section 4 classes above
(the orphaned `std/tower/` bolt-on alone accounts for ~70 files;
personal-realm staging/backup copies and unfinished builder templates
account for most of the rest) rather than driver-compat gaps -- the
live playthrough in section 5 reached real, unrelated domain content
with zero runtime errors, which is the stronger signal for this
lib's actual playability than the raw batch-compile percentage (see
this project's own documented `lpcc`-batch-vs-live-boot divergence
class: a battery of `daemon/`-preloaded objects can report a bare
"Fail to load object" with no visible error text at the point they're
reached in a giant batch run, purely as a batch-mode artifact, while
compiling and loading perfectly fine standalone or in a real boot --
confirmed directly on this lib for `domains/valley/towns/jidoor/npc/
parcil.lpc` and `domains/crystal_reaches/towns/gwonish/npc/
sneak_trainer.lpc`, both of which failed in-batch with no error text
at all but compiled clean standalone -- and `parcil` in particular is
a real NPC in the real Haven-adjacent town content, not orphaned or
backup content, further confirming this is a batch-tooling ceiling on
a 13,589-file lib rather than a real per-file defect).

## 7. §10.7 deep functional test (2026-08-31)

Round-two pass on the native driver (`~/src/fluffos/build-debug/src/
driver`, port 40249), building on top of the onboarding playthrough in
section 5. Driven via `scripts/tmux_mud.sh` persistent telnet sessions
(three sequential/parallel test characters: `Deeptestor`, `Combattest`,
`Finaltest`), plus a ~210s idle long-sit boot watch
(`python3 scripts/mudclient.py --idle 210 --timeout 215`) per AGENTS.md
§10.0. One native driver reboot mid-session to pick up the two live
fixes below; per section 5's own caution (`daemon/intermud`'s real
outbound I3 connection), reboots were kept to the minimum needed.

### Two real bugs found and fixed, verified live

1. **AGENTS.md §7.191 (new) -- `daemon/help.lpc`'s `LoadIndices()`
   crashed on the very first `help <topic>` command any player ever
   ran, then stayed silently, permanently degraded for the rest of
   that boot.** `tmp = get_dir(DIR_ROOM_VERBS + "/*.lpc") + get_dir(...)
   + ... + get_dir(DIR_CRAFTING_VERBS + "/*.lpc") + ...` -- `/verbs/
   crafting` genuinely never existed in this archive (confirmed absent
   in `raw/` too, not a conversion artifact), and `get_dir()` on a
   missing directory returns the driver's own bare integer `0` rather
   than an empty array, so `array + int` threw
   `Bad type argument to +. Had array and int.` uncaught. Live impact:
   a fresh character's `help vendors` (the exact topic that surfaced
   this) printed only "A runtime error occurred, use \"bug -r\" to
   report it." Because the crash happened PARTWAY THROUGH a
   `create()`-time one-shot function, every category meant to be
   assigned after that line (`verbs`, `combat actions`, `immortal
   commands`, `player documents`, `immortal documents`, `towns`,
   `classes`, `races`, `religions`, `lore`, `library objects`) was
   simply never populated for the rest of the boot -- confirmed by
   `help human` (a race) and `help sword combat` (a verb) both
   incorrectly returning "Help for the topic ... could not be found",
   and `help index` showing only 3 categories (`commands`, `skill
   documents`, `stat documents`) instead of the real 11. Fixed with a
   `GD(string path)` wrapper (`mixed r = get_dir(path); return
   arrayp(r) ? r : ({});`) substituted into every `get_dir()` call
   feeding a `+`-concatenation in `LoadIndices()` -- the correct
   guarded pattern was already sitting a few lines below in the SAME
   function for a different set of categories. **Verified live twice**:
   before the fix, `help vendors`/`help human`/`help index` all failed
   exactly as above on a fresh boot's first `help` invocation; after
   the fix and a clean reboot, the SAME fresh-boot-first-`help`
   sequence returned the real `doc/help/players/vendors` documentation
   text (confirmed by its own worked example, "Kelan"/"steel boots"),
   `help human` returned the real race blurb, and `help index` showed
   all 11 real categories.
2. **`domains/averath/towns/averath/npc/chartercaptain.lpc` --
   `SetFirstCommands("board ferry")` passed a bare `string` where the
   real signature takes `string *`, so this NPC never compiled at
   all.** Same self-evident-typo class already catalogued in section
   3.11 above (`SetReligions`/`SetId`/`SetFriends` bare-string calls).
   Impact: `domains/averath/towns/averath/room/charter.lpc`'s
   `SetInventory()` tries to `new()` this NPC to run Averath's
   ticket-purchase travel feature ("buy a charter to anywhere you've
   been") -- with the NPC uncompilable, every attempt logs `*No
   program in object '/domains/averath/towns/averath/npc/
   chartercaptain'!` to `log/catch`, and the whole charter-travel
   feature is permanently unusable. This also fires repeatedly and
   noisily during ordinary play: the stock ferry's own wander/sail
   logic (`lib/npcs/shipcaptain.lpc`) passes near/through the charter
   room while sailing the Haven<->Averath route, so the caught error
   logs on a recurring basis even for players who never try to charter
   anything. Fixed by wrapping the argument (`({ "board ferry" })`).
   **Verified**: `lpcc` standalone-compiles `chartercaptain.lpc` with
   zero errors after the fix (zero occurrences of the pre-fix
   `Bad type for argument 1 of SetFirstCommands` in a fresh
   `log/errors/averath` compile pass), versus the error present before
   -- not independently re-confirmed via a live charter purchase this
   session (the charter feature itself needs real travel-history state
   this session's time budget didn't reach), but the compile-blocking
   bug itself, which is the actual defect, is conclusively fixed.

### Confirmed working live

- **Fresh registration, twice more** (`Combattest`, `Finaltest`,
  alongside `Deeptestor` from section 5): identical flow each time,
  landing in the newbie staging room, `read book` correctly awarding
  160 development points and completing the "Newbie Book" quest.
- **The newbie "describe yourself" nudge on first `go down`** (`who->
  eventForce("describe")` in `domains/staff/room/setup.lpc`'s `Newbie()`
  gate function) reproduced identically and deterministically across
  all three fresh characters -- confirmed genuine content design (a
  cheap way to show new players their race's eye/hair/skintone options
  before advancement gates on having used `describe` at level 8, per
  `lib/users/player.lpc:ResetLevel()`), not a test-harness artifact,
  even though the wording ("You must <describe THING as WHAT>. Try
  again.") reads oddly out of context since it's really the command's
  own no-argument usage/help text being (ab)used as a tips display.
- **Class join, organic teacher-NPC path**: `Combattest` converted to
  the Kylin faith via `ask dalahalus to convert combattest`, then `ask
  dalahalus to join priest` -- correctly deducted 160 development
  points, granted a real primary/secondary/other skill set (`blunt
  combat`, `chain armour`, `evokation`, `faith` primary; `healing`,
  `fire magic`, etc. secondary), a title ("the Mendicant of Kylin"),
  and starter gear (mace, armour, book of faith). `skills` afterward
  correctly displayed ALL granted skills side by side in a formatted
  grid (confirms this lib does NOT have the `rifts2`-class "only the
  alphabetically-first skill displays" bug).
- **Class join gating (citizenship + faith), both confirmed as real
  design, not bugs**: Averath's own `Florian Sordeau` (priest leader)
  refused `Deeptestor` ("Sorry, I only deal with people born in
  Averath" -- `Deeptestor` is a Haven citizen); Haven's own `Dalahalus`
  refused `Combattest` for `join priest` until converting to his faith
  first ("Only members of my faith may become priests"). Both gates
  are genuine `GetTown()`/`GetReligion()` checks in `lib/npcs/
  leader.lpc`, working exactly as designed.
- **No formal safe-sparring mechanism exists in this codebase** --
  checked explicitly per AGENTS.md §10.7 item 3. `std/style/spar.lpc`
  (a "sparring" combat style whose own file header credits `combat/
  style.lpc`, which is itself explicitly commented "Outdated as of 18
  August 2008. Any players with old styles should use the 'refund'
  command.") is real but DEAD code: grepped every `SetCombatStyle(`
  call site in the whole tree and found only a handful of NPCs
  self-selecting a fixed style at their own `create()` time, never any
  player-facing `set style <name>` command wiring a player into it.
  No `accept_fight()`-mirrors-attacker-stats training-dummy pattern
  exists anywhere either (grepped `accept_fight`, `dummy`, `spar`,
  `practice fight` corpus-wide). Used a real, low-level wild NPC
  instead for the combat test (see below) -- consistent with this
  being a genuine, long-lived production game rather than a
  content-thin engine demo (the newbie book itself never mentions
  sparring, only "find an NPC and greet them").
- **Real combat, full resolution, zero crashes**: `Combattest` (level
  1 priest, wielding the class-granted mace) fought `Talis of the
  Wharf` (`domains/southern_coast/towns/haven/npc/t_fisher.lpc`, a
  real level-1 townsperson NPC, not a monster) via plain `kill talis`
  at the Haven wharf. Real hit/miss messages, HP loss on both sides,
  XP gain per hit, and a full death sequence (`You slay Talis without
  mercy.`, reputation change with two different factions, 300 XP
  bonus, Talis unwielding his own weapon before dying) -- `log/runtime`
  and `log/catch` stayed byte-identical (zero new entries) across the
  whole fight.
- **Real quest content**: Averath's `Godard the Quest Giver` (`ask
  godard for quests`) handed out a real, specific quest ("kill 5 rats
  in the Averath sewers, from Felix Monteil's tavern-storage-room rat
  problem") with full flavor text -- confirmed this is genuine
  hand-written content, not a stub.
- **Real economy/vendor content, browse+price path**: Taylor's General
  Store (Haven) and Kelan's (referenced in the fixed `help vendors`
  doc) both correctly support `ask <vendor> to browse` (a numbered
  item list, real stock like fishing poles/torches/parchment) and `ask
  <vendor> to price <item>` (a real imperials-denominated quote). A
  full `sell`-side purchase transaction was not completed live this
  session (time budget went to the bug-hunting above and the
  multi-domain travel below) -- flagged here as unverified-live rather
  than silently presented as tested, per AGENTS.md §10.7 item 6.
- **Quit -> `log/runtime`/`log/catch` grep -> reconnect after a real
  wall-clock gap, twice** (`Deeptestor` across the mid-session native
  reboot; `Finaltest` across a plain ~10s gap): both reconnects
  restored the SAME character in the SAME room with inventory/
  equipment intact, a genuinely distinct code path from fresh
  registration (skips race/town/gender prompts entirely, goes straight
  to password). `log/runtime`/`log/catch` byte-for-byte unchanged
  (zero new entries) across every quit in this session.
- **Long-sit boot watch** (AGENTS.md §10.0, ~210s idle,
  `mudclient.py --idle 210 --timeout 215`, run as a genuine
  synchronous blocking wait, not backgrounded): zero new `log/runtime`/
  `log/catch` entries appeared during the idle window on a fresh boot
  -- no lazily-loaded daemon crashed during the watch.
- **Multiple domains visited, real bespoke content in each (3 of the
  21)**:
  1. **Southern Coast / Haven** (the starting town): Merchant's Way
     business district, the Elven Aide Charity newbie-gear NPCs,
     Taylor's General Store, the Haven Town Guard barracks (`Damon
     Falterless`, a real fighter-class leader), the Temple/Sanctuary of
     Kylin (`Dalahalus`, `Ulan`), the Haven Cemetery (gated behind
     level 2 -- `you can't quite get your nerve up to enter the Old
     Cemetery yet`), and the wharf.
  2. **Averath**: reached via the real `daemon/` ferry
     (`domains/southern_coast/towns/haven/npc/ferrycaptain.lpc`'s
     `SetShipWanderPath`, a genuine heart_beat-driven NPC-piloted
     vehicle wandering between the two towns' wharves -- confirmed the
     "out" exit dynamically retargets to wherever the ship currently
     sits via `lib/special/vehicle.lpc:ResetExit()`, correctly
     refusing to disembark into open ocean mid-transit with "You would
     die if you moved into the waters!"). Averath's own town square,
     church, Godard's quest, and the sewer entrance (rats, per the
     quest) were all reached and are real, distinct content from
     Haven's.
  3. **Peninsula**: reached ENTIRELY OVERLAND, on foot, from Haven's
     own town gate -- `Haven Town Gate` -> `out_rd1`/`out_rd2`
     (`domains/southern_coast/towns/haven/room/out_rd*.lpc`) -> the
     `domains/southern_coast/virtual/havenroad.lpc` procedurally-
     numbered road grid (walked west from x=22 down to x=1) -> its
     `x==1` south branch into `domains/peninsula/areas/wood/room/
     vale9.lpc` ("A small wooded vale", corsican pines, a small fox) --
     confirmed this world's geography is genuinely stitched together
     with real cross-domain overland exits, not just isolated islands
     reachable only by scripted vehicle.
  A 4th domain (Crystal Reaches, reachable further west along the same
  road grid at x=-36) was identified in source
  (`CRYSTAL_REACHES_TOWNS "karak/room/rd1"`) but not walked to this
  session given the time already spent on the ferry/road logistics
  above -- left as a known-good, not-yet-walked route for a future
  pass.

### Minor anomaly observed, not root-caused (flagged, not fixed)

- **Standing next to the docked ferry at the Haven wharf and issuing a
  bare cardinal-direction `go` command (e.g. `go north`) once appeared
  to re-board the player onto the ferry instead of moving them into
  town**, immediately followed by the ferry captain's own autonomous
  "All aboard!"/departure sequence. Reproduced once; not conclusively
  isolated within this session's time budget whether this is a genuine
  verb-registration collision (the vehicle's own multi-directional
  ocean-grid exits, which are real add_action-registered commands
  reachable from inside `lib/special/vehicle.lpc`, somehow shadowing
  the room's own `SetExits()` "north" for a bystander standing in the
  same room as a docked vehicle) or coincidental timing with the
  captain's own scheduled departure. Flagged here for whoever next
  works with this lib's vehicle system, rather than silently dropped.

### Sibling bug-class check (per AGENTS.md §10.7 item 7)

Checked both catalogued Dead-Souls/Nightmare-lineage sibling findings
this session was specifically asked to cross-reference:

- **AGENTS.md §8.24** (Nightmare/TMI `access.db`+`groups.db`+
  `creator_file()`-based ACL, found on `rifts2`): does NOT apply here.
  `secure/daemon/master.lpc`'s ACL is architecturally different --
  `query_privs()`/`PRIV_ADMIN`/`PRIV_SECURE`-based, no `access.db`, no
  `groups.db`, no `creator_file()`/UID system at all (confirmed already
  in section 3.1 above during onboarding: "No `get_root_uid()`/
  `get_bb_uid()`/`creator_file()` anywhere in this codebase").
- **AGENTS.md §7.190** (Dead-Souls/Sapidlib `valid_read()`/
  `valid_write()` per-daemon manual-allowlist mail trust gap, found on
  `dock9`): does NOT apply here either. This lib's mail system
  (`secure/obj/post.lpc`, `secure/daemon/folders.lpc`,
  `secure/daemon/letters.lpc`) uses `write_file()`/`read_file()` into a
  centrally-daemon-owned mail store, not `restore_object()`/
  `save_object()` into a recipient's own player-save directory --
  architecturally sidesteps the whole bug class. (A related, smaller,
  non-`§10.7`-blocking finding: EVERY new character's first login logs
  a caught `Could not open /secure/save/postal/<letter>/<name>/
  postalrc.o.tmp for a save` -- `secure/save/postal/` was never
  pre-created as one of the "missing runtime scaffolding" placeholder
  directories in section 2 above, unlike `secure/save/players/`,
  `secure/save/immortals/`, etc. It's silently caught by `master.lpc`'s
  own `apply_unguarded()`/`CATCH` chain and does not visibly disrupt
  play -- flagged as a minor content-scaffolding gap, not fixed, since
  it's cosmetic-only and outside this pass's time budget.)

### Unverified / out of scope for this pass

- **Death/respawn**: Haven's own cemetery (the visible resurrection
  totem) is gated behind character level 2; no admin/wizard account
  exists for this lib (confirmed already in section 5's caveat -- no
  first-boot install wizard, a live production game's wizard hierarchy
  populated by manual promotion from an existing account that doesn't
  exist in this fresh checkout), so there is no `set_hp(0)`/`die()`
  admin shortcut available either. Reaching level 2 organically (or
  finding a level-1-reachable death path) was not accomplished within
  this session's time budget. Flagged as unverified-live rather than
  silently presented as tested, per AGENTS.md §10.7 item 6.
- **A completed shop purchase** (the `sell`-from-vendor-to-player
  transaction, as opposed to `browse`/`price`, which were both
  confirmed): not completed live this session, see above.
- **A `realms/torak/` personal-wizard-realm observation, NOT chased as
  a bug**: `log/runtime`/`log/catch` from an EARLIER boot this session
  (before the native reboot) showed several `*Nesting call_out(0)
  level limit exceeded: 1000` errors and `*No program in object`
  errors for various `/realms/torak/*` NPCs/rooms (`npc/spider`,
  `npc/dairycow`, `castlevania/npc/werewolf`, `torak/workroom`, `trade/
  hugh`, etc.). A clean reboot afterward produced ZERO such errors
  (confirmed both via a fresh `log/runtime`/`log/catch` mtime check and
  a direct stdout grep of the fresh boot's own transcript), meaning
  these are NOT deterministic eager-preload failures but something
  lazily triggered by a specific action taken during the earlier
  session (never isolated within this session's budget). Matches this
  file's own already-established "abandoned personal wizard realm
  scratch content" non-bug class (section 4 above) closely enough
  (`torak` is one of the 25 personal `realms/*`) that it was not
  pursued further -- flagged here rather than silently dropped, for
  whoever next has budget to isolate the exact trigger.

## WASM measurement (2026-09-03)

`meta.json` was already `playable` from the 2026-08-31 deploy-unblock;
the README had no WASM line. Cold-boot under the shared
`~/src/fluffos/build-wasm` succeeded with no mudlib-side compile fix
(FTP/`socket_*` failures in `secure/lib/net/` are graceful preload
skips). Verified with `scripts/wasm_client.js`: new character
`wasmhav` / confirm / email / `Mud@2026` / male / real name /
`pick human` / `pick haven`. Landed in "In the skies above Kailie"
(newbie book visible, `down` exit), `score` showed "You are Wasmhav,
a level 0 Human" / "Citizen of Haven", `quit` printed "Please come
back another time!" / "Wasmhav logs out." Shop/combat/death were not
exercised this pass. The MEMFS copy does not write the throwaway
character back to the host. Do not loop-reboot (I3).
