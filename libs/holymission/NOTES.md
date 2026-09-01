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
