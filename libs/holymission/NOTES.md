# Holy Mission -- porting notes

Source: `github.com/speedbunny/holymission-mud`, cloned via
`gh repo clone speedbunny/holymission-mud raw` (2026-08-31, 30,871
files, `.git` removed after clone). The repo root IS the mudlib root (no
nested subdirectory). Slug `holymission`, number 958, port 40260.

## 0. Lineage verification

Full-tree grep for `driver_hook`, `set_driver_hook`, and
`H_[A-Z_]+` across the entire raw archive returned zero hits -- this is
not an LDMud archive. Combined with the presence of a real
`secure/master.lpc`/`secure/simul_efun.lpc` pair and MudOS-era comments
throughout (`/94-04-14 Herp: trash the secure/passwd directory structure
and use a ndbm database instead/`), this is a genuine MudOS/FluffOS-
lineage archive, safe to proceed with the standard onboarding pipeline.

## 1. Conversion

`scripts/convert_lib.sh libs/holymission/raw libs/holymission/work`
(11m19s, ~24K files): 30576 already UTF-8, 8 converted, 3 lossy, 284
skipped as binary. 23948 `.lpc` files after rename. 5459 literal `.c"`
string-reference fixes. 27 local angle-bracket includes converted to
quotes. 401 files `static`->`nosave`.

## 2. Genuinely-missing runtime directories

`/p/` (the player save-file tree, `/p/<first-letter>/<name>.o`) was
entirely absent from the archive -- created `work/p/{a..z}/` manually.
Also created `libs/holymission/log/` and `work/binaries/` per the
project's standard log-directory-resolves-against-driver-CWD convention.

## 3. The doc/lib/ misfiling: living.lpc and player.lpc

`sys/living.lpc`, `sys/player.lpc`, `sys/living_defs.h`, and several
`sys/include/sys_*.h` headers (`sys_arches.h`, `sys_defs.h`,
`sys_levels.h`, `sys_sheriffs.h`) were preserved as completely empty
(0-byte) files. The REAL implementations -- `doc/lib/living.lpc`
(3600+ lines) and `doc/lib/player.lpc` (4300+ lines, after fixes) --
were misfiled under `doc/` as if they were documentation. Fix:
`sys/living.lpc` and `sys/player.lpc` now simply `inherit` their real
`doc/lib/` counterparts; the `sys/include/sys_*.h` headers were
reconstructed from cross-referenced real content in `players/*/`
personal copies (`players/exos/guild/levels.h`,
`players/kryll/tmp/sys/player_defs.h`).

Critically, `doc/lib/player.lpc` does **not** inherit
`doc/lib/living.lpc` (only `nomask inherit "secure/valid";`), so it
independently duplicates dozens of stat/state fields and helper
functions that would otherwise come free from `living`:
`set_number_of_arms()`, `query_gender()`/`query_pronoun()`/
`query_possessive()`, `query_real_name()`, the follow system, the
language-skill system, `move_player()` (ported ~150 lines verbatim from
`living.lpc`), and a deliberately-simplified `attack_object()`/
`hit_player()` fallback (NOT the full ~830-line armor-class/dodge/parry
combat engine -- flagged as an intentional simplification, out of scope
to port in full).

Also recovered/stubbed as safe no-ops since no real numbers survived
anywhere in the archive: `sys/savings.lpc` (spell-resistance system,
described only in `doc/magik/` narrative design docs, never
implemented anywhere recoverable) and `std_fcn__reset()`/
`std_fcn__init()` (referenced `sys/std_features.lpc` is also
irrecoverably empty).

## 4. Driver dialect gaps (mechanical sweeps)

- `closure`/`#'ident`/`lambda()`/`funcall`/`apply`: tree-wide Python
  tokenizing sweep (369 files), plus hand-rewriting
  `secure/simul_efun.lpc`'s lambda-built `text`/`loop`/`roll` closures
  as plain functions.
- 2-arg `move_object(item, dest)` / 2-arg `command(str, ob)`: ~4300-file
  mechanical AST-aware sweep to `item->move_object(dest)` /
  `ob->force_me(str)`, backed by universal shims spliced into every
  object via `include/include.h` (`move_object(dest)` /
  `force_me(str)`), requiring a permissive `valid_override()` in
  `master.lpc`.
- `status` type, `class` as a plain identifier: tree-wide sweeps (932
  and 12 files).
- `new` as a plain identifier (AGENTS.md §6.2 -- hard-reserved on this
  driver): found and fixed in `room/post.lpc`, `room/village/post.lpc`
  (both `string name, new;` -> `is_new`), and `room/sunalley2.lpc`
  (`object new;` -> `target`). A dead-code `#if 0` block in
  `secure/simul_efun.lpc` also had this shape; left untouched since
  it never compiles.
- Missing classic efuns reimplemented as simul_efun shims: `getpwent`/
  `setpwent`/`addpwent` (a from-scratch `pw_db` mapping persisted via
  `save_object("/secure/PWDB")`, replacing the archive's own lost
  ndbm-based password database per its own 1994 comment), `m_indices`/
  `m_values`/`m_sizeof`/`m_delete`, `strstr`/`extract`/`mappingp`/
  `member`/`isalpha`, `assoc`/`order_alist`/`insert_alist` (classic
  alist reimplementation), `get_prompt_str`/`set_prompt`/
  `enable_interactive`/`disable_interactive` (no-ops -- no driver
  equivalent, and no evidence still needed), `cat` (reimplemented
  pager), `query_mud_port`, `query_input_pending`, `filter_objects`,
  `set_modify_command` (no-op -- see §7 below), `creator()`/
  `master_object()`.

## 5. `file_name()` leading-slash gap (AGENTS.md §7.170)

This driver's `file_name()` always returns a leading `/`. Broke
numerous `file[0..N]=="literal/"` comparisons throughout
`secure/master.lpc`, `doc/lib/living.lpc`, `secure/simul_efun.lpc`, and
most critically `doc/lib/player.lpc`'s own `logon()` security check
(`fn[0..12] != "secure/login#"`), which was destructing **every single
login attempt** with `illegal logon: /secure/login#0` until fixed to
`fn[0..13] != "/secure/login#"`.

## 6. `creator_file()` / uid machinery (AGENTS.md §7.175)

`creator_file()` must always return a non-empty string on every object
load. Fixed `master.lpc`'s `"open"`/`"ftp"`/`"log"` and `default` cases
to return `"root"` instead of `0`/`1`. This had cascading effects:
`valid_write`'s `save_object` case needed `user != "root"` instead of a
bare truthy check; `doc/lib/player.lpc`'s own `if(creator(this_object()))`
"Cloned player" destruct check needed the same `!= "root"` guard;
`simul_efun.lpc`'s `creator()` wrapper needed to coerce an object
argument to a string via `file_name()` first. Also added
`get_root_uid()`/`get_bb_uid()` (both `"root"`) and a permissive
`valid_override() { return 1; }` (required once the `move_object`/
`force_me` include.h shims call real `efun::` names from outside
`secure/simul_efun.lpc`).

Known, deliberately-not-fixed regression from this same change: a
handful of `if(creator(X))` truthy-check call sites in `tools/`
(`display.lpc`, `mistletoe.lpc`) and a `shout()` implementation
elsewhere now always see a truthy value where they used to see `0` for
non-wizard-owned files. Lower priority, non-blocking for the core
register/look/score/quit/reconnect bar verified this session --
documented here rather than fixed.

## 7. The `reset()`-by-name silent-no-op bug (AGENTS.md §7.177 -- the headline finding)

A direct, explicit call to a function literally named `reset` can
silently execute as a no-op on this driver, even when called eagerly
from that same object's own `create()`, on the object's first-ever
load. No compile error, no runtime error, no trace of any kind.

Confirmed independently in two unrelated files:

- `doc/lib/player.lpc`'s own `reset(int arg)`: `env_var`/`msgin`/
  `title`/etc. never got initialized, crashing `score` with "Value
  being indexed is zero" in `short()`. Extensive `debug_message()`
  instrumentation (bracketing the `reset(0);` call site in `create()`
  and every checkpoint inside `reset()` itself) proved `create()` runs
  completely normally -- a direct `env_var = (["TEST":1]);` assignment
  right there worked immediately -- but not one `debug_message()` call
  placed inside `reset()`'s own body, including the very first line,
  ever fired.
- `secure/simul_efun.lpc`'s `reset(int tick)`: the password database
  (`pw_db`) never got restored from `/secure/PWDB.o` on driver boot,
  so **every previously-registered password was silently discarded
  across a driver restart** -- reconnecting with the correct password
  produced "You have no password! Please set one." every time. This
  object gets created TWICE during boot (once during an early
  dependency-triggered compile while `master.lpc` loads, and again as
  what the driver treats as the "real" instance right before "Loading
  preload files"); the FIRST create()'s direct `reset(0)` call actually
  ran fine, but the SECOND one's was silently skipped -- so this is not
  a simple "always works the first time" rule either.

**Fix applied everywhere this was found**: rename the real
initialization logic to `do_reset(int arg)` and call that directly from
`create()`, keeping `void reset(int arg) { do_reset(arg); }` as a thin
pass-through so the driver's own natural scheduled reset-apply (which
needs a function literally named `reset`) still fires normally.

A second, less invasive fix was used for the universal `room/room.lpc`
base class and two singleton "prototype" objects (`obj/armour.lpc`,
`obj/share.lpc`) where touching every subclass's own `reset()` wasn't
practical: `void create() { call_other(this_object(), "reset", 0); }`
-- routing the call through `call_other()` to self also reliably
executes it. This exact `call_other(this_object(),"reset",0)` pattern
was already independently discovered and used in this project's own
`lpmud141` archive for what looks like the same underlying driver
quirk, though it had never been promoted out of that lib's own
`meta.json` into the general `AGENTS.md` catalog until this session
(now §7.177).

This bug had a severe, easy-to-miss knock-on effect: since
`room/room.lpc` (the universal room base class) has no `create()` of
its own anywhere in the stock archive, and this driver's own
`"time to reset"` config is 1800 seconds, **every room in the mudlib
sat completely dark and undescribed for up to half an hour after being
compiled for the first time** -- including a brand-new character's own
starting room. Confirmed live: a fresh character saw "It's too dark."
on `look` immediately after picking a gender, in a room
(`race/room.lpc`) whose own `reset()` unconditionally does
`set_light(1)`. Fixed by adding the `call_other`-routed `create()` to
`room/room.lpc` itself, which (via normal LPC virtual dispatch) reaches
every room that inherits it and doesn't override `create()`.

## 8. The `inaugurate_master()` dead-apply bug (AGENTS.md §7.178)

`secure/master.lpc` had `void inaugurate_master(object ob) {
master_reload(); }` -- `master_reload()` populates `wiz_info`/
`sanc_info` (wizard levels/promotions) from `/secure/WIZSAVE.o`, or
seeds safe defaults if that restore fails. `inaugurate_master()` is a
real LDMud master apply, but `grep -rn inaugurate_master` against this
driver's own source (`~/src/fluffos/src/`) returns **zero hits** -- it
is simply never called. Since nothing else in the mudlib called
`master_reload()` either, `wiz_info` was left to whatever its bare
declaration-time initializer produced, which turned out to depend on
incidental compile-order timing: `get_wiz_level(name)`'s
`wiz_info[name]` lookup intermittently crashed with "Value being
indexed is zero" on a perfectly ordinary player name, right at
`secure/login.lpc`'s very first per-connection wizard-level check
(worked on some driver boots, crashed on others). Fixed by giving
`master.lpc` a real `create() { master_reload(); }` (this driver does
call `create()` normally on the master object -- confirmed live by
`debug_message()` instrumentation before removing it).

## 9. Genuinely-lost content: `obj/rsoul.lpc`

`obj/rsoul.lpc`'s entire original content was a single
`#include "/players/moonchild/misc/rsoul.mudlib.lpc"` -- a file that is
completely absent from the archive under any name, in both the raw,
unconverted tarball and the converted work tree. Every single new
character crashed here (`doc/lib/player.lpc`'s own
`move_player_to_start3()` unconditionally does
`clone_object("obj/rsoul")->move_object(myself);`, uncaught) with
`"No program in object '/obj/rsoul'!"`, aborting that function
partway through and silently skipping everything after it -- including
the actual move into the starting room, which is the real reason a
brand new character never physically arrived anywhere at all (compare
§7 above: the darkness bug was a second, independent blocker layered
on top of this one). Since the real "remote soul" command set can't be
recovered, `obj/rsoul.lpc` is now a minimal inert stand-in (an `id()`
matching `"rsoul"`/`"racesoul"`, `invis()` returning 1, `short()`
returning 0) -- it exists, compiles, and does nothing, so character
setup can actually finish. `doc/lib/player.lpc`'s `drop_all()` also
needed a guard against `short()` returning `0` for such an invisible
utility item (it previously called `capitalize()` on that `0`
unconditionally, crashing on every `quit`).

## 10. `query_real_name()` also genuinely missing

Same root cause as §3 (player.lpc doesn't inherit living.lpc):
`room/post.lpc`'s `query_mail()` -- called unconditionally from
`move_player_to_start3()` during first-time character setup -- calls
`lower_case(call_other(this_player(),"query_real_name"))`, which
crashed with "Bad argument 1 to lower_case()" since `query_real_name()`
didn't exist on the player class at all. Added as a one-line accessor
(`return name;`), mirroring `doc/lib/living.lpc`'s own `nomask` copy.

## 11. `look()`/`mylook()` infinite recursion (self-inflicted, fixed this session)

An earlier fix in this same porting session had `mylook(arg) {
return look(0); }` as a stand-in for the empty `/sys/mylook.lpc` stub --
but `look(str)`'s own `if(!str) return mylook(0);` branch calls back
into `mylook()`, producing instant infinite mutual recursion ("Too deep
recursion", confirmed live on every single bare `look`). Fixed by
having `mylook()` call `environment(this_player())->long(0);` directly
(the same "print my full description" apply a normal room-to-room move
already triggers), matching this file's own existing
`environment(...)->long()` idiom used elsewhere.

## 12. Tolerated pre-existing compile errors

A bucket of ~34-36 compile errors from broken personal wizard
guild/soul/room files (`players/saffrin`, `players/turbo`,
`players/whisky`, `players/redsexy`, `players/darastor`,
`players/meecham`, `players/nae`, `players/tinman`, `players/ted`, and
similar) surface every boot, once `guild/master.lpc` was given a real
`create(){reset(0);}` (see §7 -- these are pre-existing, already-caught
content bugs in those wizards' own files, wrapped in `catch()` by
`guild/master.lpc`'s own reset logic already; not a regression, not
fixed).

## 13. Verification

Live, end to end, with the real driver and a raw Python socket client:
register a brand-new character (`holyseeker`/`TestPass123`), confirm
password, enter the game, pick gender (`m`), see a correctly lit and
described starting room (`race/room`), `list` (shows all 9 races with
sizes), `choose human` (stats update: Str/Con go to 4, race/guild
fields populate, moved to the church with a full room description and
5 obvious exits), `score`, `quit` (saves, hands the connection back to
a fresh login menu -- genuine archived design: `doc/lib/player.lpc`'s
own `quit()` clones a new `/secure/login` and `exec()`s the connection
onto it, not a bug). Reconnect verified across a **full driver
restart**: correct password accepted, character restored in the church
with race/stats/guild intact; a wrong password is correctly rejected
("Wrong password!", `Try again:`), confirming the login check is
genuinely functional post-fix, not just bypassed.

## 14. §10.7 deep functional test (round two, 2026-08-31)

Full continuous native-driver session (`~/src/fluffos/build-debug/src/driver
config.fluffos`, port 40260), specifically instructed to VERIFY the
onboarding-pass fixes above hold up under a genuinely independent
playthrough, not re-run the same steps. Five throwaway characters used
across this pass, all different from onboarding's `holyseeker`/male/human:
`Pilgrim` (female elf), `Aldric`/`Bertrand`/`Cassian` (male human, same
name reused across driver restarts to test different fixes),
`Delphine` (female dwarf), `Gwendal` (female gnome), `Rosalind` (female
hobbit) -- covering 4 of the 9 races and both genders, via
`scripts/tmux_mud.sh` sessions. Explored a materially different part of
the map than onboarding (which stopped at the church): south through
`players/moonchild/newbie/hut` (get sword/jacket), the newbie map room,
then east along the full village road strip (`players/cashimor/extend/village1`
-> `room/vill_track` -> `room/vill_road1` -> `room/vill_road1b` ->
`room/vill_road2` -> `room/vill_shore`), west across `room/hump` (a
river bridge) into `room/wild1`/`room/forest1`, and to
`room/adv_guild` (the Adventurers' Guild room) and `room/narr_alley`
(post office/brokers).

**Onboarding's headline fixes (§7.177 `reset()`-no-op, §7.178
`inaugurate_master()`, the password database, room darkness) all hold**:
verified via 5 independent fresh registrations, gendered race choice
branching correctly (elf/dwarf/gnome/hobbit all showed correct
race-specific stat floors and moved cleanly into a fully lit, described
starting room), and a genuine SEPARATE-CONNECTION reconnect (not the
same open socket) for a second independent account (`Delphine`) across
a real ~3-minute wall-clock gap plus an intervening full driver
restart -- correct password accepted, race/stats/HP restored exactly,
wrong-password rejection re-confirmed working.

This pass found and fixed **4 further real programming bugs**, one of
them (§7.194 below) as severe as anything onboarding found -- the
combat engine was completely unusable against any monster in the game
until now:

### 14.1 `obj/weapon.lpc` missing the same create()-forces-reset() fix already applied to `obj/armour.lpc`/`obj/share.lpc`/`room/room.lpc` (AGENTS.md §7.177/§7.192 class)

Reproduced live: `get sword` in the newbie hut successfully cloned
`players/moonchild/newbie/sword.lpc` (a `obj/weapon` subclass whose own
`reset()` sets `set_name()`/`set_short()`/`set_class()`/`set_weight()`),
but the sword never appeared in `i` (inventory) -- `get jacket`
(`obj/armour`, already fixed) worked correctly side by side with the
identical idiom, isolating the gap to `obj/weapon.lpc` specifically.
`obj/weapon.lpc`'s own `short()` returns the never-initialized
`short_desc` (0), and `doc/lib/player.lpc`'s `inventory()` silently
skips any item whose `short()` is falsy -- so every weapon in the game
sat with no name/short description/class/weight for up to the
30-minute lazy-reset window after being cloned. Fixed identically:
added `void create() { call_other(this_object(), "reset", 0); }` to
`obj/weapon.lpc`. Verified live post-fix: `get sword` -> `i` correctly
shows "A small sword."

### 14.2 `obj/monster.lpc` (this archive's near-universal NPC base, cloned 600+ times) had the identical gap, with a much worse blast radius

Same root cause, same fix (`obj/monster.lpc` had `reset()` -- which
initializes `alias_list = ({})`, `hunted = ({})`, `alignment`, etc. --
but no `create()`). The near-universal room idiom throughout this
archive is `ob = clone_object("obj/monster"); ob->set_name(...);` in
the SAME `reset()`/`init()` that just cloned it -- and `set_name()`
does `member_array(str, alias_list)`, a hard driver error ("Bad
argument 2 to member_array() Expected: string or array Got: 0") when
`alias_list` is still 0. Confirmed live: a fresh character's very
first move (`east` from `room/church` into `players/herp/room/father`,
whose `reset()` clones a "priest" NPC this exact way) threw this error
uncaught INSIDE the room's own `reset()` -- and since `reset()` now
runs synchronously from `create()` (the already-applied §7.177 fix),
an uncaught error there aborts the whole room's compilation
("No program in object ...") rather than just leaving one monster
blank. `room/vill_green.lpc` (whose `clone_list` clones "Harry" the
same way) hit the identical crash. Fixed by adding the same `create()`
to `obj/monster.lpc`. Verified live post-fix: `east` from church now
reaches the priest's room cleanly, `look at priest` shows a fully
described, correctly-inventoried NPC.

### 14.3 §7.194 (new AGENTS.md entry) -- `doc/lib/living.lpc`'s own `query_str()`/`query_dex()`/`query_con()`/`query_int()`/`query_wis()`/`query_chr()` called themselves forever, crashing combat against every monster in the game

The headline finding of this pass. `sys/living_defs.h` (a header this
project's OWN earlier onboarding pass reconstructed from an empty file,
see §3/§9 above) defines `#define Str (query_str())` etc as a
convenience macro for OTHER code. `doc/lib/living.lpc`'s own
`query_str() { return Str; }` (and the Dex/Con/Int/Wis/Chr siblings)
preprocesses into `query_str() { return (query_str()); }` -- a literal
unconditional call to itself. Confirmed live: `kill priest` crashed
with `Too deep recursion.` at `doc/lib/living.lpc:2953`/`:2963` (this
file's own weapon-damage-class calculation calls
`this_object()->query_str()`/`query_dex()`), which also silently
disabled that NPC's `heart_beat`. Since `obj/monster.lpc` (§14.2 above)
is this archive's near-universal NPC base and inherits this exact
`living.lpc`, this bug meant **combat could never work against any
monster in the entire game** -- confirmed the crash reproduces
identically on a second, independent NPC once §14.2 was fixed and this
room became reachable at all. Fixed by making all 6 accessors return
`query_stats(nr_x)` (the file's own real, non-recursive underlying
accessor) instead of their own macro alias -- see AGENTS.md §7.194 for
the full writeup and the general "how to spot this again" grep.
Verified live post-fix: `kill priest` now resolves normal combat
(`You take 19 damage! Priest hit you very hard.`, no crash,
`debug.log`/driver stdout clean).

### 14.4 `room/room.lpc`'s `clone_list` population logic had no guard for a missing/uncompilable clone target -- an unrelated pre-existing gap the §7.177 create()-fix turned from "one blank monster" into "whole room permanently unloadable" (AGENTS.md §7.25 class)

`room/vill_green.lpc`'s `clone_list` references
`/players/emerald/misc/danseuse` and `.../paperboy` -- both files are
genuinely absent from the archive under any name (confirmed both in the
raw and converted trees). `room/room.lpc`'s `reset()` does
`ob = clone_object(clone_list[i+3]); ...; ob->move_object(this_object());`
with no check that `clone_object()` actually succeeded -- for a
genuinely-missing file it returns `0`, and the very next line's
`ob->move_object(...)` (an implicit `call_other()`) throws "Bad
argument 1 to EFUN call_other() ... Got: int(0)" uncaught. Exactly the
same shape as the already-catalogued AGENTS.md §7.25 ("room-population
helper's unguarded `new()`/`move()` chain"), just with `clone_object()`
in place of `new()`. Before the §7.177 create()-fix this would have
been invisible for 30 minutes then silently no-op'd every subsequent
lazy reset; after that fix it aborts the ROOM's own `create()` on
first load, taking down `room/vill_green.lpc` (a room every single new
character walks through one hop from the church) entirely. Fixed with
a plain `if (!ob) continue;` guard in both of `room/room.lpc`'s
`clone_list` branches (the direct-clone branch and the
per-existing-monster item-clone branch). Verified live post-fix:
`room/vill_green` loads and describes correctly; no new AGENTS.md entry
needed, this is a same-shaped instance of the existing §7.25 class.

### 14.5 A separate, unrelated pre-existing compile error: `room/vill_road2.lpc` declared a variable literally named `function`

Found while re-verifying §14.2/§14.3 reached `room/vill_road2.lpc`
("Harry" the chatty NPC) cleanly -- it instead failed with a hard
syntax error (`unexpected L_BASIC_TYPE, expecting L_DEFINED_NAME or
L_IDENTIFIER`) at `string *function, *type, *match;`. `function` is a
real type keyword on this driver (function-pointer/closure type,
`function f = (: foo :);`), hard-reserved the same way `new`/`class`/
`status` already are elsewhere in this archive (AGENTS.md §6.2, this
lib's own NOTES.md §4). This was NOT caused by any of §14.1-14.4's
fixes (a genuine syntax error is caught at parse time, before any of
those runtime paths could ever run) -- it's an independent pre-existing
gap that happened to be masked behind the (also broken) §14.2/§14.3
crashes the whole time, so it was never actually reached/tested by
onboarding either. Fixed by mechanically renaming the identifier to
`func_name` throughout the file (10 occurrences, verified via grep that
no other real archive file uses `function` as a bare identifier
outside `players/`). Verified live: `room/vill_road2` now compiles and
loads; Harry greets arriving players correctly (though see the next
paragraph for a separate, NOT fixed, minor cosmetic observation).

**Minor cosmetic observation, not fixed**: Harry's `say_hello()`
(triggered by a room-chat pattern match on an "arrives" message) prints
"Harry says: Hi 0, nice to see you!" instead of the arriving player's
name -- an `sscanf(str, "%s arrives.", who)` pattern that doesn't
account for whatever the real decorated arrival-message format is on
this driver, leaving `who` at its string-type default. Cosmetic only
(doesn't block or crash anything), flagged here rather than
investigated further given the session's time budget and the size of
the fixes above.

### 14.6 A severe pre-existing content gap, found and fixed as a missing-accessor reconstruction (same technique as §3/§6/§9/§10 above, not a new AGENTS.md pattern): every new character had 0/0 hit points from the moment of creation

`doc/lib/player.lpc` declares `max_hp`/`max_sp` at the top of the file
but -- since this file doesn't inherit `/sys/living` (see §3) -- never
defines `query_maxhp()`/`query_maxsp()` accessors, and never computes
`max_hp`/`max_sp` anywhere. `logon()`'s new-character branch does
`hit_point = max_hp;` while `max_hp` is still its bare-declaration `0`;
`score`'s own `this_object()->query_maxhp()` call_other silently
returned `0` for a nonexistent function (this driver's `call_other()`
doesn't error on a missing function, just returns 0). Confirmed live:
every single fresh character showed "Hit points(max) : 0(0)" --
already effectively dead before taking a single hit, which is also why
Bertrand's very first `kill priest` produced "You have died!"
immediately on the first hit. Root-caused further: `logon()`'s own
comment says "we call the adventurers guild to get our first title,"
via `call_other("room/adv_guild", "advance", 0)` -- but
`guild/guild_room.lpc` (the real base class `room/adv_guild.lpc`
inherits) only defines `do_advance()` (the player-facing command, wired
via `add_action`), never a bare function literally named `advance` --
so that `call_other()` always silently no-ops and never triggers
anything HP-related anyway (nor, apparently, ever assigned a title --
a separate, much more minor loose end not chased further this session).
**Fixed**: added `query_maxhp()`/`query_maxsp()` accessors (one-line,
mirroring `doc/lib/living.lpc`'s own real, intact shape), and in
`logon()`'s new-character branch, computed `max_hp`/`max_sp` for real
via the same `GM->query_maxhp(guild, con, legend_level)`/`query_maxsp`
mechanism `doc/lib/living.lpc`'s `stat_changed()` already uses for
monsters (`guild/master.lpc` is real, intact archive content with a
genuine `gd_info[0] = ({"adventurer", 0, 30, 1, 42, 8, ...})` base+
per-CON-point table for the default "adventurer" guild -- not an
invented balance number). Verified live: a fresh level-1 adventurer
with CON 4 now shows "Hit points(max): 50(50)" and survives real
combat hits instead of being already dead. This is the same
"genuinely missing, reconstruct from the real archive mechanism"
technique already used repeatedly in this file (§3/§6/§9/§10 above),
not a new generalizable driver-quirk pattern, so no new AGENTS.md entry
was added for it -- but it's flagged here prominently given how severe
its effect was (nothing else this session even matters if every
character starts already dead).

### 14.7 Combat/death: real damage now happens both directions, but the already-documented "intentional simplification" of `doc/lib/player.lpc`'s `hit_player()` (NOTES.md §3, "NOT the full ~830-line combat engine") means death never actually ends a fight

With §14.1-14.6 fixed, real bidirectional combat is now genuinely
exercised for the first time this project (previously blocked at the
very first hit by §14.3's crash). `hit_player()` sets `dead = 1` and
prints "You have died!" exactly once when `hit_point` crosses 0, but
never calls any actual death/reincarnation routine, never
`stop_fight()`s the attacker, and the player object is never destructed
or moved -- so the fight (and the "You take N damage!" spam) continues
indefinitely at the NPC's own heart_beat pace regardless of how far
negative `hit_point` goes, until the player disconnects or physically
walks away (both work correctly and end the fight cleanly, confirmed
live -- a plain movement command out of the room, or `quit`, both
succeed instantly even mid-fight and the NPC's aggro drops once its
target is gone). This is squarely the ALREADY-DOCUMENTED, explicitly
out-of-scope content gap from this lib's own onboarding notes (§3
above: "a deliberately-simplified attack_object()/hit_player() fallback
... so combat is at least FUNCTIONAL (damage happens, death happens)
rather than a hard compile/runtime error -- flagged clearly as a real
content gap, not a finished feature") -- confirmed and expanded with a
live reproduction, not a new bug, and per this project's scope
discipline (fix programming bugs, not incomplete content), left
untouched.

**Guild-join / skill acquisition**: no dedicated safe-sparring
mechanism exists in this archive (grepped for `accept_fight` plus a
stat-mirroring dummy pattern -- zero hits anywhere in the tree,
including `players/`) -- used the placed, non-aggressive
`players/herp/room/father` "priest" NPC as the checklist's documented
weak/non-aggressive-NPC fallback instead. Reached `room/adv_guild.lpc`
(the Adventurers' Guild room, real archive content, base class
`guild/guild_room.lpc`) and exercised its real command dispatch
organically (`join` correctly refuses with "You can't join the
adventurers guild." -- `gd == 0` for the default "adventurer" guild is
a deliberate special case in `do_join()`, not a bug; `advance`
correctly refuses with "You are not ready to advance." per the real
0%-experience gate in `do_advance()`) -- confirms the guild-room
command layer itself is functional post-fix, but this session's time
budget did not extend to locating and joining one of the archive's
actual non-default guilds (mage/thief/monk, mentioned in race `about`
text) via either the organic or a shortcut path; flagged honestly as
unverified rather than silently skipped.

**Shop/economy**: attempted but not reached within this session's time
budget -- `room/main_shop.lpc` (`obj/std_shop`-based, real archive
content, confirmed reachable via `room/vill_road2.lpc`'s own `north`
exit in source) was identified but this pass's navigation time was
consumed by the combat-chain bug fixes above and the world's extensive
reuse of near-identical "long road" room descriptions (several
distinct road tiles share verbatim or near-verbatim prose, which
repeatedly caused this session's own dead-reckoning navigation to
misidentify which physical room it was standing in -- a genuine
tooling/methodology lesson for future navigation of this specific lib,
not a bug). Flagged unverified-live rather than silently skipped.

**Long-sit boot watch**: `python3 scripts/mudclient.py 127.0.0.1 40260
--timeout 220 --idle 250`, run synchronously in the foreground for
~220 wall-clock seconds sitting idle at the login prompt -- ended in
the login object's own normal inactivity-timeout disconnect ("Time
out."), zero new `debug.log`/driver-stdout errors, driver RSS a steady
~33-34MB throughout. No lazily-loaded daemon failures surfaced.

**Files modified this pass**: `work/obj/weapon.lpc`, `work/obj/monster.lpc`,
`work/doc/lib/living.lpc`, `work/room/room.lpc`, `work/room/vill_road2.lpc`,
`work/doc/lib/player.lpc`.

## 15. AGENTS.md §7.19 (room/prop variant) -- kawai's "hell" punishment room, two bugs fixed

Corpus-wide `enable_commands()`/`init()` reentrancy sweep (AGENTS.md
§7.19) flagged `players/kawai/obj/flames.lpc:46` (`void init() {
enable_commands(); }`) as a structurally distinct instance from the
ES2/Xiyouji player-wrapper architecture the main sweep fixed (66
libs): a wizard-built hazard prop, freshly cloned and moved into
`players/kawai/hell.lpc` (a punishment room reachable via
`players/kawai/workroom.lpc`'s `boot <name> to hell` wizard command)
every time a living object enters that room.

**Live-confirmed real and severe, not a false alarm -- and confirmed
WORSE than the sibling `darkelib` room/prop instance of the same
AGENTS.md section (see that lib's own NOTES.md/AGENTS.md entry)**:
there, a `living()` guard was sufficient because the SAME persistent
room-fixture object kept getting its own `init()` re-entered. Here,
`hell.lpc`'s own `init()` clones a **brand-new** `flames` object on
every call, so a `living()` guard on `flames.lpc` never blocks
anything -- every reentrant pass gets a fresh, never-yet-`living()`
clone. The real cycle is: entering living object already sits in
hell's inventory -> hell's `init()` clones+moves a flames object ->
driver's own command-registration cascade reenters flames' `init()`
(original `hell.lpc init()` still on the stack) -> `enable_commands()`
there reenters the cascade -> which reenters **hell.lpc's own
`init()`** (cloning yet ANOTHER flames object) -> which reenters
flames' `init()` on that new clone -> ... until "Too deep recursion."
aborts it.

**Live reproduction method**: this lib's wizard command shell
(`/sys/wiz.lpc`) turned out to be a genuinely empty 0-byte file --
confirmed live (a fresh `kawai`-named registration, a name seeded at
wizard level in `secure/WIZSAVE.o`, correctly triggered "Connecting to
/sys/wiz..." but then had ZERO working commands, including `look`,
`i`, and `help` -- all returned "What?") -- so the in-game `boot`
command path was unusable for testing. This is itself a real,
previously-undocumented gap (every wizard login on this lib is
apparently non-functional), flagged here for a future pass but out of
scope for this one. Worked around with a temporary preload test
harness instead: a throwaway `/repro719.lpc` (never committed, deleted
after use, along with its one added-then-reverted line in
`secure/init_file`) whose `create()` legitimately calls
`enable_commands()` on itself (the one documented-safe call site) and
then `move_object("players/kawai/hell")`, using the driver's real move
machinery (not a simulation) to get a genuinely-`living()` object into
hell's inventory exactly the way a real player would.

Pre-fix, this reliably reproduced `*Too deep recursion.` from
`move_object()` AND left **48 leaked, uninitialized `flames` clones**
sitting in the hell room from the recursive clone-and-crash cascade
(`hell room inventory count=49` after a single trigger) -- a real
object leak on top of the crash. The punishment mechanic
(`burn_player()`) never even ran, since the crash happens during the
clone+move line itself, before `hell.lpc`'s `init()` reaches that call.

**Fix 1 (`players/kawai/obj/flames.lpc`)**: removed the
`enable_commands()` call entirely rather than guarding it (a guard
provably doesn't work here, see above). It serves no purpose in this
file -- no `catch_tell()`, no `command()` use, not even an
`add_action()` (unlike darkelib's `pond.lpc`, which at least used
`add_action()` after its `enable_commands()`) -- so nothing anywhere
reads `living(this_object())` for this prop. This matches how the
identical bug was already fixed, independently, elsewhere in this same
archive: 3 near-identical sibling copies
(`players/goldsun/mud/flames.lpc`, `players/goldsun/lank/obj/flames.lpc`,
`players/whisky/garden/obj/flames.lpc`) carry a real 1993 header
comment, "Recoded by Uglymouth 930901: removed enable_commands() and
heart_beat(), ... bug (dead 1, ghost 0) solved now" -- `kawai`'s copy
was simply the one that never got that historical fix applied. (A
4th, unrelated sibling, `players/redsexy/guild/spell/flames.lpc`, was
also checked and has no `init()`/`enable_commands()` at all -- clean.)

**Fix 2 (`players/kawai/hell.lpc`), found live while re-verifying fix
1**: after the crash was fixed, `move_object()` (the universal 1-arg
compat shim in `/include/include.h`,
`mixed move_object(mixed dest) { return efun::move_object(dest); }`)
still threw `Bad argument 1 to EFUN call_other() ... Got: int(0)` --
`ob = clone_object("players/kawai/obj/flames")->move_object(this_object());`
assigns `ob` the compat shim's *return value* (an int status code,
since the real efun always moves `this_object()` and returns a status,
not the moved object), not the cloned flames object; the subsequent
`ob->burn_player(this_player())` then called a method on an int. Split
into two statements (`ob = clone_object(...); ob->move_object(...);`)
so `ob` keeps the real object reference. This bug was **already
present, just permanently masked** by fix 1's crash aborting `init()`
before ever reaching this line -- confirmed by re-running the same
preload harness after fix 1 alone (crash gone, this error appeared)
and again after fix 2 (`err=none`, `hell room inventory count=2`: the
harness object plus exactly one legitimate flames clone, no leak,
`debug.log` clean).

**Same clone-then-`->move_object()` pattern (not the same file, out of
scope for this pass, flagged for a possible future sweep)**: identical
`clone_object(...)->move_object(...)` value-discarding pattern also
exists in `players/whisky/garden/room/oven.lpc`,
`players/goldsun/mud/oven.lpc`, and
`players/misticalla/garden/room/oven.lpc` (each cloning that player's
own, already-fixed `obj/flames.lpc` sibling, not `kawai`'s), plus
`players/topaz/monsters/tower/general.lpc` (an unrelated `flamesword`
weapon clone) -- none of these were exercised or verified this pass.

## WASM measurement (2026-09-03)

`meta.json` was already `playable` from the 2026-08-31 deploy-unblock;
the README still said "not attempted." Cold-boot under the shared
`~/src/fluffos/build-wasm` succeeded (known `catch()` wizard-soul
compile failures still print; they do not block login). Verified with
`scripts/wasm_client.js`: new character `wasmhol` / `TestPass123` /
`TestPass123`, then menu `1` (enter game — not `m`), gender `m`,
`list`, `choose human`. Arrived in the village church (5 exits),
`score` showed "Wasmhol the Human" Level 1, clean `quit`. Name must
be 3–11 lowercase letters; password ≥6. Shop/combat/death were not
exercised this pass.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 57 line(s) in 17 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply holymission`: 2 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 7 path reference(s) in 6 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 9 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 7 PASS -> 9 PASS, 0 that loaded before fail now, 2 more load.

2 files moved (2 `.lpc`); mostly under `players/bobo/clan` (2). A rescan with `scripts/lpc_warnings.py holymission` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— 主控 author_file()/domain_file()

驱动的 mudlib_stats 包在主控载入时各调用一次 `author_file(<主控文件>)` 和 `domain_file("/")`。本库主控没有这两个 apply，所以每次启动都打印 `author_file() in the master file does not work, using root_uid as fallback` 和 `domain_file() in the master file does not work, using bb_ui as fallback` 两行，网页版每位访客的终端里都看得到。`secure/master.lpc` 补上了这两个 apply：作者返回 `get_root_uid()`，域返回 `get_bb_uid()`，正是驱动缺少它们时所用的值。域名等于 backbone 域时，驱动让对象沿用创建者的域，与没有这个 apply 时相同（KB 06 §7.222）。注意：§9 格式化工具仍会把这个主控里 `#if 0` 死代码之后的字符串拆坏（`"secure/login"` 变成 `" secure / login "`，KB 08 §9 盲点 3），本次只插入代码，未格式化此文件。用 `lpcc config.fluffos /nonexistent.lpc` 前后对比，主控载入段只少了这两行。

## 深度功能测试（§10.7，2026-10-05）— 压缩存档

`players/mangla/gal/sourcer/default/start.o.gz` 改为明文 `start.o`（网页版驱动没有 zlib，读不了 `.o.gz`；KB 01）。空文件 `players/moonchild/gquest/bastard.o.gz` 不是 gzip，保持原样。

## 深度功能测试（§10.7，2026-10-06）— LDMud 兼容层：member()、影子、载入时 reset、命令缩写、move_object

全库 `lpcc --batch` 编译与启动检查发现，本库按 MudOS 移植时补的 LDMud 兼容层有几处与原语义不符，影响整片功能：

1. **`member()` 参数顺序反了（KB 06 §7.229）。** 模拟外部函数写成 `member(item, container)`，而全部约 230 处调用都是 LDMud 的 `member(container, item)`，于是每次调用都报 `Bad argument 1/2 to member_array()`：银行、酒馆、路标、门、法师公会的命令钩子（每条命令都调用 `member(verb, '.')`）全部出错。改为 LDMud 语义：映射返回 0/1，数组和字符串返回下标或 -1。
2. **`extract(s, 0, 0)` 返回整串。** 兼容函数把显式的 0 当作“到结尾”，而 16 处调用（包括 udp 主控的封禁与存档路径）用它取首字母。改用 `undefinedp(end)` 区分省略与 0。
3. **所有 `shadow()` 都被拒绝（KB 06 §7.198）。** 主控只有旧名 `query_allow_shadow()`，没有 FluffOS 询问的 `valid_shadow()`，驱动在缺少它时一律拒绝；公会的树皮术、火盾、忍者、窃贼等影子效果从未生效。补 `valid_shadow()` 返回 `query_allow_shadow()`；另补 `unshadow()` 模拟外部函数（`remove_shadow(previous_object())`，37 处调用）。
4. **载入时不执行 `reset(0)`（KB 06 §7.228）。** `obj/treasure`、`obj/thing`、`obj/container`、`obj/food`、`boards/board`、`spells/spell` 等基类没有 `create()`，子类都在 `reset(arg)` 里设置自己，所以新克隆的火炬、背包、报纸、法杖等没有短描述（看不见），要等第一次定时重置（约 30 分钟）；十个公会的灵魂也是这样，克隆出来没有初始化。给 109 个独立文件（核心目录与十个公会目录，`secure/` 下的备用副本除外）补 `create() { call_other(this_object(), "reset", 0); }`。其中 `obj/treasure` 本身没有 `reset()`，按“定义 reset 却没有 create”扫描会漏掉，要沿继承链找根基类。补完后 `obj/explore_xp`、`tools/filetool`、`sargon/guild/obj/mantle` 在无玩家的批量编译里载入失败，是因为它们的 reset 需要 `this_player()`，游戏里克隆时总有玩家，与 LDMud 相同。
5. **方向缩写、别名、历史从未生效（KB 06 §7.230）。** 玩家的 `modify_command()`（obj/expander：别名、历史、主控 `modify_command_global` 的 n/s/e 方向表）原本靠 `set_modify_command()` 注册，移植时把它写成空函数并注明 FluffOS 没有此类钩子；实际上 FluffOS 调用交互对象的 `process_input()`。在 expander 里补 `process_input()` 转给 `modify_command()`。实测 `s`、`n`、`e` 可以走动。
6. **两参数 `move_object(item, dest)`（KB 06 §7.231）。** 全局包含文件里的单参数 `move_object(dest)` 替代了约 1400 处改写，但还有约 100 处调用和 `#define MOVE move_object`/`MO` 宏（`include/defs.h` 与许多巫师头文件）传两个参数，多出的参数被丢掉，调用者把自己移走：`players/matt/castle` 报 `Can't move object inside itself`。改为可变参数：一个参数移动自己，两个参数转给 item；在影子里转给被影子的对象（影子会接到对被影子对象的所有调用，否则移动 Will 这个带隐形侦测影子的 NPC 时会移动影子本身）。
7. **`\` 后接 `\r\r\n`（KB 03）。** 档案被两次转换为 DOS 换行，170 个文件里多行 `#define` 在第一行就结束（`players/redsexy/guild/functions.h` 让召唤师灵魂编译失败），`"...\` 字符串续行留下 CR 和硬换行。在 `@` 文本块之外，奇数个反斜杠后的多余 CR 删掉；这 167 个 `.lpc` 全部编译通过（之前两个失败）。
8. **启动时的编译错误 27 → 0。** LDMud 闭包 `#'call_out` → `(: call_out :)`，`sort_array(a, #'>)` → `sort_array(a, 1)`（LDMud 的 `#'>` 是升序），`#'fn` → `(: fn :)`，21 个文件，其中 14 个由失败变为通过（含 `std/mapping_book`、德鲁伊以外的多个公会灵魂）；含 `lambda()` 的巫师工具没有改。德鲁伊灵魂（`meecham`）的宽映射改为 `([ 键: ({ 冷却, 下次时间 }) ])`，`times[spell, 1]` → `times[spell][1]`。`saffrin` 的 `oldstart`（法师公会房间继承它）把变量 `new` 改名。`cloakspells` 包含的 `.c` 文件已改名为 `.lpc`。`whisky/genesis/sys/` 不在档案里，`filter_live.h`、`break_string.h` 从 darastor 公会的同名副本恢复（darastor 的野蛮人公会照搬自 whisky 的武僧公会），whisky 的 31 个文件由 0 个通过变为 20 个。吟游诗人灵魂包含的 `guild/bin/sing.h`（连同整个 `bin/` 目录）不在档案里，灵魂里没有代码调用它，注释掉这条包含后灵魂可以编译、施法可用，唱歌功能缺失。`ted/castle` 的 2.4.5 式 `add_action("north"); add_verb("north");` 改为两参数；`tinman` 工作室自定义的 `filter()` 改名。
9. **任务表。** `room/quest_room` 依次调用 22 个任务主人的 `make_quest()`，`map_array` 遇到第一个出错的就整个中止，后面的任务都没注册。`matt` 的城堡（家目录 `guild/rooms/` 不在档案里）在最后移回家时出错；sherman、pretzel、patience 的城堡不在档案里。每个主人改用 `catch()`，任务数由 6 个变为 26 个。
10. **`players/haplo/defs.h`** 里的死函数 `OTHERS()` 用 `new` 当变量名，且有 `old!=ob1 = TP` 这样的非法赋值，包含它的 50 个文件（包括教堂东边路北的赌场）全部编译失败；变量改名、条件改为 `old != ob1 && old != TP` 后 50 个全部通过。
11. 实测（只含被跟踪文件的树）：新角色注册、选性别、`choose human`、教堂、`score`、`s`/`e`/`n` 走动、重连“Throw the other copy out”、`quit` 保存都正常。§9 格式化只动了本次改过的文件，其中 24 个巫师灵魂此前因为 `#'` 无法解析，这次第一次被格式化（格式化器只在词法序列等价时写入）；`secure/master.lpc` 仍不格式化（盲点 3）。
12. 全库批量编译：19346 个通过，4602 个失败。最大几类：`Cannot #include`（918，多为巫师目录间缺失的头文件）、继承的文件不存在（770）、`new` 作变量名（343，包括 `obj/soul`）、参数个数不对（384）、`in`/`float` 等作变量名（`room/shop`、`room/yard`）。下一步处理核心目录里的这几类。

## 深度功能测试（§10.7，2026-10-06，续）— 全库编译 19346 → 20365，邮件、法术、商店

接上一节，按全库批量编译的错误种类继续修：

1. **保留字当名字（KB 04）。** `class`（102 个文件）、`function`（98）、`new`（34）、`in`（26）作变量名，用 `scripts/lpc_rename_ident.py` 改为 `class_`/`function_`/`new_`/`in_`（在出错的每个文件里改，基类和子类一致）。作函数名的另改：`in()` → `do_in()`（连同 `add_action` 的函数名参数；silas 的护身符帮助按主题名调用，`help in` 映射到 `in_()`），布告栏的 `new()` → `new_note()`，`cremate` 的 `new()` 与它的 `call_out`，`ls`/`saber` 的 `class()` → `do_class()`；两个农夫的 `hoe->class(11)` 改为 `set_class(11)`（武器没有 `class()`，同一区域其他 NPC 都用 `set_class`）。
2. **2.4.5 式 `add_action(fn); add_verb(v);`（KB 06 §7.174）。** 732 处、260 个文件合成 `add_action(fn, v)`，`add_xverb(v)` 合成 `add_action(fn, v, 1)`（前缀匹配）。
3. **两参数 `command(str, ob)`。** skeeve 的 NPC 装备宏（`WEAPON`/`ARMOUR`，十几个 NPC）和两个 `climb.h` 改为 `ob->force_me(str)`。
4. **法术系统。** `spells/master`、`abilities/master`、`masters/skills` 的排序函数把法术名（字符串）声明为 `object` 并用 `<` 比较，FluffOS 编译时拒绝，于是所有法术文件都载入失败；参数改为 `mixed`，返回 -1/0/1（LDMud 的 `sort_array` 在返回真时交换，保持原来的降序）。德鲁伊法术包含的 `/players/sourcer/guild/druid.h` 不在档案里（sourcer 的目录被移到 `players/mangla/gal/sourcer/`，`guild/` 没有留下）：10 个法术不用它，注释掉包含后编译通过；`flameblade` 改包含移走后的 `define.h`；`heat_armor`、`flame_blade`、`tree_grow` 要用它定义的法力消耗与路径，无法复原，记为缺失。
5. **邮件（第一次可用）。** `obj/mail_reader` 包含的 `/sys/sheriffs.h` 在档案里是空文件，改用已有的占位 `sys/include/sys_sheriffs.h`（`SHERIFFS ({ })`）；抄送处理里的 LDMud `lambda` 改为 `(: strlen($1) > 0 :)`。实测：在邮局给自己写信、收到新邮件提示、`from` 列出、`read` 进入阅读菜单。
6. **`room/store`**（村庄商店的库房）在一个 `if` 块里声明 `torch`，下一个块又用它；在第二块里另行声明。实测商店 `list` 列出火柴与火把。
7. **移动返回值。** 移植时把 `move_object(m = clone_object(f), dest)` 改写成 `m = clone_object(f)->move_object(dest)`（241 处，多为 NPC 生成器，如 moonchild 森林生物、哥布林、侏儒），`m` 得到 0，随后的 `m->set_name()` 出错。全局包含文件里的 `move_object` 现在返回被移动的对象。
8. **whisky 的 `obj/std_shadow`、`std_potion`、`std_scroll`。** `players/whisky/obj/` 整个不在档案里，而核心 `/obj/` 下有同名文件（`std_shadow` 的说明正是 whisky 的“standardshadow”，接口 `start_shadow(player, time, id)` 与各公会影子的调用一致）；84 个继承它们的文件改为继承 `/obj/` 下的版本后 81 个编译通过。whisky 的其他物品（卷轴、药水、`std_dragon` 等，几十处引用）没有可靠的替代，记为缺失；引用它们的随机刷新（如 tatsuo 洞穴的真菌三分之一几率带 `bless_potion`）会让房间偶尔载入失败。
9. **`players/haplo/defs.h`、`obj/bull_board` 等见上。** `room/village/` 是另一个未完成的村庄（引用不存在的 `street9`、`path.h`），没有处理；`qclxxiv`、`arthur`、`chomp`、`silver` 等退役巫师目录被搬到 `players/mangla/gal/` 或 `players/archive/` 下，代码仍用旧绝对路径（`Cannot #include /players/qclxxiv/myroom.h` 等约 1200 处），属原 MUD 退役内容，没有改。
10. **玩家进出房间时别人看到 “0 arrives.”。** 玩家的 `move_player()` 用 `TName`（`this_object()->query_name_true()`），而 `doc/lib/player.lpc` 不继承 living，没有这个函数；按 living 的定义补上。双客户端实测：现在看到 “Zzholyb arrives.”。同样缺少的还有 `query_level`、`attack`、`run_away`、`add_hunted`、`query_noshouts`、`query_earmuff_level`、`queryenv`、`query_testchar`：玩家心跳里的 `this_object()->attack()` 因此永远返回 0。原档案的 `doc/lib/player.c` 使用 living 的变量却不声明它们，说明原来是与 living 一起编译的；把玩家改回继承 living 是下一步的单独工作。
11. 全库批量编译：20365 个通过（上一节 19346），3583 个失败；第一次通过、这次失败的 34 个都是载入时的随机刷新碰到缺失文件（见 8）。本次改过的文件 §9 格式化，`secure/master.lpc` 除外。

## 深度功能测试（§10.7，2026-10-06，续二）— 玩家改回继承 living（KB 06 §7.232）

入库时 `doc/lib/player.lpc` 被做成不继承 living 的“独立玩家类”（见 §3、§14.7）：补了 58 个与 living 同名的全局变量、56 个 living 已有函数的简化副本（`move_player`、简化的 `attack_object()`/`hit_player()` 等），删掉了原文的 `::reset(arg)`（原注释 “!!! HERP”）。但原档案的 `player.c` 使用 living 的变量却不声明它们，`reset()` 第一行就是 `::reset(arg)`，说明它本来就是在 living 之上编译的。后果：玩家没有 `attack()`、`run_away()`、`query_level()`、`add_hunted()` 等函数，心跳里 `this_object()->attack()` 永远返回 0；死亡不结束战斗（§14.7）；`look` 不列出房间里的人和物。

修复：
1. `doc/lib/player.lpc` 加 `inherit "/doc/lib/living";`，删去入库时补的 53 个重复变量声明与 56 个重复函数（编译器的重复声明警告给出确切位置）；原文自己覆盖的 10 个 living 函数（`reset`、`short`、`wield`、`add_weight` 等）保留。14 个变量入库时声明为存档变量而 living 是 `nosave`（`attacker_ob`、`hands`、`cap_name`、法术计时等瞬时状态），以 living 为准；旧存档里的这些字段 `restore_object()` 直接跳过，旧角色登录正常。
2. `do_reset()` 恢复 `living::reset(arg)`，只在第一次执行：FluffOS 的定时重置不带参数，living 会把属性数组重新分配。
3. living 的 `move_player(s[,o][,r][,i])` 文档写明后面参数可省，加 `varargs`；`obj/descs.h` 的 `get_prompt_str(int)`（真正的提示符生成，原来被模拟外部函数的空实现替代）同样加 `varargs`。
4. `sys/mylook.lpc` 在档案里是 0 字节，`sys/archive/mylook.c` 是同一文件的旧版（“the look that is called from living.c”，列出房间里的生物与物品并合并复数）；用它替换玩家里只打印房间长描述的代用 `mylook()`。

实测（只含被跟踪文件的树）：新角色注册、`choose human`、`score`（体型 medium、最大生命 74，来自 living 与公会主控的公式）、走动、`look` 列出 “Priest.”、“Preacher man.”；旧存档角色登录正常（邮件提示、属性完整）；`kill priest`：双方命中/落空与状态行，玩家死亡 “You die. ... Priest killed Zzml.” 变成鬼魂，`score` 显示 “You are a ghost”，在教堂 `pray` 复活（“You reappear in a more solid form.”）。启动编译错误 0。

## 深度功能测试（§10.7，2026-10-06，续三）— 编译警告（机械部分）

1. `obj/monsoul.lpc` 是 `obj/monster`、`obj/mon`、玩家文本包含的文件，入库时给它补了 `msgin`/`msgout`/`mmsgin`/`mmsgout` 的声明，而三个包含者都继承 living，已有这些变量；每个 NPC 编译时都报四条重复声明（约 2859 个文件、11999 条警告的大头）。删掉这行声明，`sreset()` 设置的就是 living 的那一份。
2. `scripts/lpc_warnings.py holymission --fix`：643 个 `nosave` 函数改 `protected`（105 个直接去掉修饰），删 3571 个未用局部变量，补 69 处 `varargs`、7 处缺返回值的 `return;`、约 217 处无效转义。`lpc_audit_removed_locals.py` 复核 5801 个被删声明，0 个需要处理。改动的 1506 个 `.lpc` 用 `lpcc --batch` 复编，之前通过的没有一个失败。全库编译 20419 → 20433，诊断 11796 → 7242 种。§9 格式化：`secure/backmaster.lpc`、`secure/mmm.lpc`（主控的旧副本，不载入）被格式化器拆坏字符串（盲点 3），恢复为 HEAD，本次不改。
3. 启动警告 471 → 34，错误 0；剩下的是结构性的（`Types in ?:`、`add_poison` 返回类型等）。实测（只含被跟踪文件的树）：旧角色登录、`look` 列出 Priest、`kill priest` 死亡、鬼魂、教堂 `pray` 复活；新角色注册、走到商店 `list`。

## 深度功能测试（§10.7，2026-10-06）— LDMud 存档：换行和共享值

1. **存档里的换行读回来是字母 `n`（KB 03）。** LDMud 把字符串中的换行存成 `\n` 两个字符，本驱动存成一个 CR 字节，读档时把 `\X` 还原成 `X`：信件（`room/post_dir`）、留言板、巫师物品存档里的文字全挤成一行，每个换行变成 `n`。`scripts/ldmud_save_newlines.py` 把引号内的 `\n` 改成 CR、`\t` 改成制表符：1184 个文件、72,364 处。用驱动自己的 `restore_variable()` 读 `room/post_dir/akira.o` 的 `messages`：767 行，不再有 `Jun 29n` 这种连写。
2. **玩家房屋存档全部读不回。** `players/silas/houses/` 的 40 个房屋存档用了 LDMud 的共享值写法：`exits_special ({…,<1>=({}),…})` 定义一个共享的空数组，后面的 `<1>` 引用它。本驱动不认识，`restore_object()` 报 `Illegal array format`，房屋（Silas 的房产中介、`house.lpc`、`house_map.lpc`）读不到任何房屋。`scripts/ldmud_wide_save_convert.py` 现在把共享值展开成副本（这里共享的都是空数组，展开后语义不变）。用 `restore_variable()` 逐值检查全部房屋存档：16,707 个值都能读。
3. 仍读不回：`players/moonchild/save/guild_board.o` 的 `tmp_text`，原始存档在一个词中间就截断了，没有右引号，无法恢复。


## Deep test (§10.7, 2026-10-07) — messages cut by a stray `;`

Messages cut by a stray `;`: the second half stood alone as a string statement and never showed. Joined where it continues the text (`players/iishima/workroom.lpc`, `players/archive/thumper/cavern.lpc` — whose long description was only its first line —, `players/ace/castle/rooms/dark1.lpc`, `dark2.lpc`). Deleted where the orphan is a leftover of an earlier wording that the text above already says (`and south.`, `crater.`, `be very painful shouts.` and similar in 22 rooms of emerald, colossus, sargon, kelly, helmut, tatsuo, beardy, warlord, bobo, tamina and `room/plane4.lpc`): no change in what players see.

Changed files loaded at HEAD and in the tree in fresh processes: no regression.

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 6 处比较、2 处去后缀（如 `players/sauron/guild/new/secure/area_creators/room_creator.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。
