# LPmud 1.4.1-A -- porting notes

Source: `lpmud-1.4.1-A-r10.tar.gz`, recovered from the Wayback Machine
(originally hosted at mudmagic.com, a now-defunct MUD community site, at
`/codes/dl/2154/lpmud-1.4.1-A-r10.tar.gz`). The CDX API found two working
snapshots (2006-11-07 and 2006-12-09, identical digest,
`F45N5YSOL3EUATOFS2SYVS6EN7BIFC6R`, 178589 bytes); downloaded via the
`id_` URL suffix (raw bytes, no Wayback chrome) and confirmed as a valid,
non-corrupted gzip/tar (`tar -tzf`, 374 members) before use. Slug
`lpmud141`, number 941, port 40243.

The archive bundles the original classic C-language LPMud driver source
(`lang.y`, `interpret.c`, `simulate.c`, `object.c`, `backend.c`, `comm1.c`,
`ed.c`, etc. -- ~15,000 lines) alongside the real payload, `mudlib/` (338
files). Per this project's standing convention, **the bundled driver was
never touched or built** -- only `mudlib/` was ported, against this
project's own FluffOS build.

## 0. This is NOT a normal onboarding: no master object, ever

Before any conversion work, `grep -rn master` across the entire bundled
driver source returns **zero hits**. This is not an oversight or a
stripped-down archive -- this driver genuinely predates the
"master object" security-daemon architecture that LPMud 3.x/MudOS/FluffOS
(and by extension every other lib in this 940+-lib corpus) standardized
on. Confirmed by reading the driver's own connection-handling code
(`comm1.c`'s `new_player()`): it hardcodes
`ob = clone_object("obj/player")->u.ob;` then `logon(ob)` (which just
`apply`s a hardcoded `"logon"` function name) for every new connection --
no master, no ACL, no uid model of any kind. Boot-time object loading is
equally hardcoded: `backend.c`'s `load_first_objects()` always loads
`room/void` first, then reads `room/init_file` line by line loading
each named object, then loads `room/rum2.c` as an unconditional final
kludge (its own comment: "For some reason the environment of the last
castle preloaded doesn't get its long description!").

FluffOS unconditionally requires a master object (a `master file` config
directive; PACKAGE_UIDS applies; `connect()`/`epilog()`/`preload()` at
boot). Since none exists anywhere in this archive (mudlib/ or the driver
directory), `secure/master.lpc` and `secure/simul_efun.lpc` were
**authored from scratch** -- see §2 below for exactly what's in them and
why each piece is there. This is pure driver-glue reproducing the
driver's own hardcoded C behavior in LPC, not invented mudlib content;
every actual room/NPC/item file in `mudlib/` is untouched archive
material.

One nearby archive file *did* get relocated: `security.h` (wizard-level
and invisibility-level `#define`s -- `SENIOR`, `GOD`, `NO_SHORT`,
`INVIS_TELEPORT`, etc.), referenced by 3 mudlib files via
`#include "../../security.h"`. In the original tarball layout that
resolves one directory *above* `mudlib/`, i.e. into the driver's own
source tree (where the file genuinely lives, `lpmud/security.h`) -- an
artifact of the original single combined driver+mudlib checkout, not a
missing-content gap. Copied into `work/security.h` (the mudlib root) and
the 3 `#include` lines repointed to `"/security.h"`; the constants
themselves are untouched, real archive content.

## 1. Conversion

Pure-ASCII English archive (`LC_ALL=C grep -rlP '[\x80-\xFF]'` found zero
non-ASCII files) -- `scripts/convert_lib.sh` ran with zero encoding work
needed: 148 `.c` files renamed to `.lpc`, 2 literal `.c"` references
fixed, 1 local angle-bracket `#include` converted to quotes, 0 files hit
by the `static`->`nosave` sweep (this codebase never uses `static` at
all).

## 2. `secure/master.lpc` and `secure/simul_efun.lpc` (authored, §0)

`master.lpc`: `get_root_uid()`/`get_bb_uid()` (both `"root"`, matching
this codebase's single-tier trust -- it never had a uid model to begin
with); permissive `valid_read()`/`valid_write()`/`valid_socket()`/
`valid_seteuid()`/`valid_hide()`/`valid_shadow()` (same reasoning);
`valid_override()` (needed for the `efun::` syntax used in the global
`auto.h`, §3); `connect()` reproducing `comm1.c`'s hardcoded
`clone_object("obj/player")`; `epilog()`/`preload()` reproducing
`backend.c`'s `load_first_objects()` exactly -- always `/room/void`
first, then every non-comment non-blank line of `room/init_file` (read
fresh every boot, so wizard castles appended by `create_wizard()`, §4,
keep preloading across restarts); `creator_file()`/`domain_file()`/
`author_file()` (silence harmless-but-noisy "no function defined"
warnings); `log_error()`/`error_handler()` for compile/runtime
diagnostics.

**A real bug was found and fixed in `error_handler()` itself while
building it**: an early draft did `ret += "Object: " + ... + " at " +
mp["file"] + ":" + mp["line"] + "\n"` -- concatenating a string with
`mp["line"]` (an int) via `+`, which this driver does not implicitly
convert. That throws *inside the error handler itself*, and with no
handler for a from-error_handler error, the driver aborts the whole
load **completely silently** (`lpcc`'s own `main_lpcc.cc` wraps
`find_object()` in a bare `catch(...)` with no diagnostic printed) --
"Fail to load object X" with zero explanation was the only visible
symptom, and it looked exactly like a real compile/runtime bug in X for
several debugging cycles before the root cause (a bug in the *handler*,
not in the failing object) was found by temporarily replacing
`error_handler()` with a `sprintf("%O", mp)` dump. Fixed with
`sprintf("%s:%d", mp["file"], mp["line"])` and an `objectp()` guard
around `mp["object"]` instead of a bare truthiness check. Worth
remembering for future onboardings: **an uncaught error inside a
from-scratch master.lpc's own `error_handler()` is indistinguishable
from a silent object-load failure** unless you specifically suspect and
test the handler in isolation.

`simul_efun.lpc`: see §5 for the driver-only-efun shims it provides, and
§3 for `resolve_ob()`.

## 3. `add_action()`/`add_verb()`: a two-call idiom, not a bare-function-value bug

This driver's `add_action` and `add_verb` are **two separate one-argument
driver instructions** (`lexical.l`: both are real lexer tokens,
`F_ADD_ACTION`/`F_ADD_VERB` -- not efuns in the modern sense at all,
literally keywords in this dialect). `add_action(fn)` registers a
pending function name; `add_verb(cmd)` binds the verb to whatever was
most recently registered. Confirmed by reading `interpret.c`/
`simulate.c`'s `F_ADD_ACTION`/`F_ADD_VERB` cases, and by the archive's
own usage: `room/pub2.lpc` calls `add_action("order")` **twice** with
two different `add_verb()`s (`"order"` and `"buy"`), proving the two
calls are genuinely decoupled, not just cosmetic sugar over a 2-arg
`add_action(fn, cmd)`.

This driver's own `add_action` spec is `void add_action(string|function,
string|string*, void|int)` -- **the verb argument is mandatory** here
(only the trailing flag is optional), so a literal single-argument
`add_action(fn)` call would fail to compile even before considering
`add_verb()` at all.

Confirmed exhaustively via a small Python balanced-paren/string-aware
scanner before touching anything: **every single `add_action(...)` call
in the archive (308 of them, across 58 files including two `.h` files --
`room/std.h`'s `TWO_EXIT`-style movement macros) is immediately followed
by exactly one `add_verb(...)` call**, with nothing but whitespace
between them, 1:1 paired, zero exceptions. Mechanically merged into
single two-argument `add_action(fn, cmd)` calls tree-wide (dropping the
separate `add_verb` call). This is the correct, semantics-preserving
translation, not a workaround -- confirmed against the `pub2.lpc` two-verb
case (`add_action("order", "order"); add_action("order", "buy");`,
i.e. the same function reachable via two different words, exactly as
`pub2.lpc`'s own author intended) and live-tested (§7): "smile" and
other social commands, "east"/"west"/"south" movement, all correctly
verb-matched.

## 4. `move_object(item, dest)`: moves an arbitrary object, not just the caller

The single most consequential driver-dialect gap in this archive.
`interpret.c`'s `F_MOVE_OBJECT` case takes **two** arguments (the object
being moved, and its destination) and moves *that* object -- not
necessarily `this_object()`. Used ~200 times across the whole `obj/` and
`room/` tree (`move_object(weapon, guard)`, `move_object(this_player(),
"room/church")`, etc.) -- this is how the archive's own `obj/player.lpc`
moves a fresh character into their starting room in the first place.

FluffOS's real `move_object()` efun signature is `void
move_object(object|string)` -- **one argument**, always moving
`current_object`. Getting an *other* object to move requires the
standard LPC idiom `item->move_object(dest)` (call `item`'s own
`move_object` function via `call_other()`, which runs with
`current_object == item`, so a bare `move_object(dest)` inside that
function correctly targets `item`). All ~200 call sites were mechanically
rewritten to this form (a Python balanced-paren/top-level-comma-aware
scanner split each call into exactly 2 arguments -- 0 anomalies -- and
emitted `A->move_object(B)`, or plain `move_object(B)` when `A` was
already textually `this_object()`).

That rewrite alone was **not sufficient** and looked, for a while, like
it hadn't worked at all: `call_other()` on this driver never falls back
to a real efun of the same name if the target object's own *compiled
program* has no LPC function called `move_object` -- and nothing in this
archive defines one. `item->move_object(dest)` was therefore silently
resolving to nothing (a `call_other()` to a nonexistent function just
returns 0, no error) -- confirmed by a from-scratch character never
actually arriving in a room (`environment()` was `0` after login, with
zero errors logged anywhere). Fixed by giving *every* object in the
mudlib a real `move_object()` function, for free, via the global include
file (`secure/auto.h`, injected into every single compile):

```c
varargs void move_object(mixed dest) {
  efun::move_object(dest);
}
```

`efun::` (not a bare call) is required inside this function -- a bare
`move_object(dest)` here would recurse into this very function forever,
since a local definition always shadows a same-named efun for plain
calls within its own file. `valid_override()` had to be added to
`master.lpc` for the `efun::` syntax to even compile (this driver gates
it behind a `valid_override()` master apply -- see `secure/master.lpc`).

A second, narrower problem layered on top of this: `resolve_ob()`
(`simul_efun.lpc`) handles destination strings. This driver's original
`find_object()` **silently fell back to `load_object()`** when the named
object wasn't already resident (`simulate.c`: `ob = find_object2(str); if
(ob) return ob; return load_object(str);`) -- but FluffOS's real
`find_object()` efun is a pure in-memory lookup with no such fallback,
and the real `move_object()` efun's own string-destination handling calls
exactly that non-compiling `find_object()` internally, throwing
`"move_object failed: could not find destination"` the first time
anything tries to move something into a room that hasn't been touched
yet (which, for a brand-new character's very first room, is *every*
boot). `resolve_ob(x)` (find-or-load, matching the original semantics
exactly) wraps every destination argument at every rewritten call site:
`A->move_object(resolve_ob(B))`.

## 5. `reset(arg)` with `arg==0`: expected to fire synchronously, doesn't on this driver

The second most consequential gap, and the hardest to diagnose --
new characters arrived in a real room (§4 fixed) but every room was
pitch dark (`test_dark()` -> `set_light(0) <= 0`) despite every room's
own `reset(arg) { if (arg) return; set_light(1); ... }` -- the extremely
common "arg 0 means first-time setup" idiom, confirmed as this driver's
own convention by reading `simulate.c`: `apply("reset", ob, 0)` is
called synchronously right after object creation (both for fresh
compiles and clones), *before* anything else touches the object.

FluffOS's own object lifecycle does **not** do this. Read directly out
of `~/src/fluffos/src/vm/internal/base/object.cc` and `backend.cc`,
since this gap is subtle enough that guessing would have been wrong:
`call_create()` (called for every compile *and* every clone) calls
`set_nextreset(ob)` -- scheduling `next_reset` a full `time to reset`
interval in the future (randomized-halved if that config option is on)
-- then runs `create()`, then **immediately sets `O_RESET_STATE`**.
Every later reset check (`try_reset()`'s lazy on-touch path *and*
`backend.cc`'s eager periodic-scan path) requires both "time's up" AND
"`O_RESET_STATE` not set" -- and the latter is already true the instant
`create()` returns, for every object, always. A brand-new object's own
`reset(arg==0)` therefore does not fire again until a full reset
interval (900-1800s here) has elapsed, full stop -- regardless of lazy
vs. eager reset config, regardless of anyone visiting the room in the
meantime. (This is presumably a non-issue for the rest of this 940+-lib
corpus because their room/NPC base classes do first-time setup in
`create()` directly rather than depending on `reset(0)` -- but this
archive, again, predates that split.)

Fixed the same way as §4 -- a universal default, injected via
`secure/auto.h` into every compile, confirmed to collide with nothing
(`grep -rln "^create("` across the whole archive returns zero files --
nothing here defines its own `create()` at all, since the concept
didn't exist on the original driver):

```c
void create() {
  call_other(this_object(), "reset", 0);
}
```

`call_other()`, not a bare call, deliberately: plenty of files (most
plain items) have no `reset()` of their own, and a bare call to an
undefined function is a compile error, while `call_other()` to a
nonexistent function just harmlessly returns 0. This one `create()`
addition alone took every room in the archive from permanently dark and
empty (or, for shops/NPC spawns, permanently unstocked) to fully
populated on first visit -- confirmed live, §7.

**Known, accepted, harmless side effect**: two archive files'
`reset()`/`create()`-adjacent code assumes a real connected player
(`this_player()`) is present at first-reset time, which is true in
actual gameplay but not in `lpcc`'s standalone compile-check harness (no
interactive session exists there) --
`obj/wiz_soul.lpc:16` (`restore_object("players/" +
call_other(this_player(),"query_real_name",0))`) and `obj/crash.lpc:6`
(a one-shot "a wizard has arrived" announcement effect, `shout(...+
call_other(this_player(),"query_name")+...)`). Both throw `Bad argument
1 to EFUN call_other() ... Got: int(0)` *only* under `lpcc_check.sh`;
confirmed via a real boot (`obj/wiz_soul` is one of the 5
`room/init_file`-preloaded objects) that this is silently absorbed by
`master.lpc`'s `preload()` (`catch(load_object(file))`) with no visible
effect, and confirmed live that a real wizard's `soul on` (which clones
`obj/wiz_soul` fresh, in a real player's connection context) works
correctly (§7). Not fixed -- fixing it would mean guarding every
`this_player()` use against a test-harness-only condition that never
occurs in real play, which is exactly the kind of harness-only false
positive this project's own methodology (§10.4) says to identify and
leave alone rather than "fix."

## 6. Smaller driver-compat fixes

- **`status` type keyword**: `obj/torch.lpc` and `obj/weapon.lpc` declare
  `status is_lit;` / `status wielded;` -- this driver's own boolean-ish
  type synonym for `int` (confirmed: unrelated to the "reserved word"
  class below, this driver's grammar genuinely accepts `status` as a
  type name). Not a valid type on this driver; both replaced with `int`
  (2 files, 2 declarations).
- **`class` used as a plain variable name**: `room/fortress.lpc` and
  `room/orc_vall.lpc` both declare `int n,i,class,value,weight;` --
  `class` is a genuine reserved word on this driver build
  (`__STRUCT_CLASS__` is predefined), so the whole multi-variable
  declaration failed to parse, and every use downstream on the same line
  cascaded into further "Undefined variable" errors for `value`/`weight`
  too (one root cause, not three -- AGENTS.md §6.4). Renamed to `wclass`
  in both files (5 renamed uses each).
- **`new(hd)` function name**: `obj/bullboard.lpc` names its
  "post a new message" handler `new` (bound to the `note` command via
  `add_action("new", "note")`) -- also a reserved word on this driver
  (struct/class instantiation). Renamed the function and its
  registration to `new_note`. While in this function anyway, fixed a
  same-function author typo blocking compile once `new` no longer masked
  it: `envorinment(this_object())` -> `environment(this_object())`
  (AGENTS.md §6.6 -- pre-existing author typo, not a conversion
  artifact, fixed because the compiler flags it).
- **`crypt()`/`snoop()` need mandatory 2nd/1st args**: this driver's
  `crypt(string, string|int)` has no 1-argument form (the classic
  driver auto-generated a salt); `obj/player.lpc`'s 2 password-set call
  sites (`password = crypt(password)`) became `crypt(password, 0)` (a
  fresh random salt per this project's own documented convention, see
  AGENTS.md §7.14), and its 2 password-*verify* sites (`crypt(p) !=
  password`) became `crypt(p, password) != password` (verify against
  the stored hash's own salt prefix, the standard idiom). Separately,
  `snoop()` with zero arguments (this driver's "stop my own snoop" form)
  needed the real efun's 1-argument form: `snoop(this_player())`.

## 7. Verification performed (live, real driver, real socket client)

Raw Python `socket` scripts (`connect()`, send/recv with short sleeps,
no `tmux_mud.sh`) against `~/src/fluffos/build-debug/src/driver
config.fluffos`, run from `libs/lpmud141/` (required -- `log directory :
/log` resolves against the driver's own CWD, AGENTS.md §5.2):

- **New character registration**: connect -> name prompt (`valid_name()`
  requires 1-11 lowercase a-z letters, no digits -- this archive's own
  rule, predating non-ASCII names entirely, so a plain English name like
  `testwizard` is the correct/only valid input, not a workaround) ->
  "New character." -> password (typed twice, matching) -> guild-advance
  message -> full MOTD -> arrives lit, in the correct starting room
  (`room/church`, "Endoplasmatorium") with its real long description.
- **`look`**: full room description, no longer "It is too dark."
  (§5's headline fix).
- **`score`**: real stats (50 HP, level 1, title "the utter novice"),
  not all-zero.
- **`soul on` + emote commands**: `smile` -> "You smile happily." (a
  real `add_action`/`add_verb`-registered command, §3, reaching a
  correctly-`move_object()`-attached clone, §4).
- **Movement**: `east` (Endoplasmatorium -> clinic, full description),
  `west` (back), `south` (-> village green) -- confirmed multiple
  distinct rooms all independently reset/lit/described correctly, not
  just the login room.
- **`i` (inventory)**: correct empty-inventory output (not "too dark").
- **`quit`**: "Saving <Name>." -- and reconnecting with the *same*
  character name + password afterward (including across a full driver
  process restart, `kill` + relaunch) correctly restores the saved
  character (persisted stats, incremented `age`), not a fresh "New
  character." -- confirmed twice, across two separate restarts.
- **Outbound network**: `grep -rln "socket_connect\|socket_create\|resolve("`
  across the whole mudlib returns nothing -- no outbound connections of
  any kind, as expected for an archive this old.
- **No admin-account seeding** (AGENTS.md §1.5): this codebase's only
  privilege concept is a per-character `level` field promoted via
  `obj/wiz_soul.lpc`'s in-game "grant" commands (real gameplay, not an
  account/wizard-rank system with a login-time seed hook) -- N/A here,
  same as `imud`/`lil`.

## 8. Deliberately not fixed / not in scope

- Everything in §5's "known, accepted, harmless side effect" note
  (`wiz_soul`/`crash` under the `lpcc` harness only).
- `obj/soul_com.lpc` and `room/def_castle.lpc` both fail
  `lpcc_check.sh` standalone (`Undefined variable 'cap_name'`/
  `'NAME'`/`'DEST'`) -- both are genuinely include-only/template files,
  never meant to be compiled or loaded on their own: `soul_com.lpc` is
  `#include`-d verbatim at the end of `obj/soul.lpc` (which declares
  `string cap_name;` *before* the `#include`, so the combined file
  compiles and loads fine -- confirmed, `obj/soul` is one of the 146
  passes); `def_castle.lpc` is a template `create_wizard()` (`secure/
  simul_efun.lpc`) concatenates a generated `#define NAME .../#define
  DEST ...` header onto before writing a new file, never compiled as
  `room/def_castle.lpc` directly. Both are `lpcc_check.sh`
  batch-sweep false positives from feeding every `.lpc` file to the
  compiler indiscriminately, not real bugs -- same class as this
  project's documented precedent for test-fixture/mixin files
  (AGENTS.md, `lil`'s `single/tests/compiler/fail/`).
- Content is thin by design, not by omission: this is a genuine 1990s
  university reference mudlib (`README`'s own contact is
  `jseidman@jarthur.claremont.edu`, "HMC LP-mud" -- Harvey Mudd
  College), not a commercial game. A handful of rooms, a starter guild,
  soul/emote commands, basic combat, wizard tools. Left exactly as
  shipped -- no new rooms, NPCs, or commands invented, per this
  project's standing rule.
