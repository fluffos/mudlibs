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
