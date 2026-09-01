# Ninetears -- porting notes

Source: `git clone https://github.com/unleashed/ninetears` (commit
`4edd22c75e3fa99be4b5820300491c6b62e06085`, cloned 2026-08-26). The
repo's own `README.md` is a short first-person note from "Alex"
(in-game "Tyrael", "Driade's Supreme Deity"), releasing his backup of a
mud he ran "in early 2000's for a couple of years", based on "FR 3.4,
with a few changes from a Spanish mudlib named Calandria" -- "over 1.25
million lines added and about 125k removed in about 28,000 files" per
his own changeset description. Confirmed genuine and worth the full
pipeline: 28,092 files in the raw clone (27,123 under the actual mudlib
root once the bundled driver source and top-level stray files are
excluded), 148MB, real multi-year wizard-authored content, and archived
player save data for real accounts. Slug `ninetears`, number 939, port
40241.

## 0. Language mismatch with the task brief -- worth flagging explicitly

The task that produced this port described the target as "confirmed
definitively ... English-language" from an earlier research pass. That
turned out to be **wrong** on direct inspection: the upstream repo's own
`README.md` (a personal note from the author) is in English, but every
piece of actual in-game content -- room descriptions, help text, system
messages, comments in the source -- is in **Spanish**. `LEEME` (Spanish
for "read me") and `LICENCE.fr` (also Spanish) sit right next to the
English `README.md` at the repo root. This wasn't a blocker -- this
project already hosts plenty of non-English archives -- but it did
matter for the encoding-detection step below, since the "pure ASCII
English archive" assumption from AGENTS.md's usual fast path doesn't
apply here; the archive turned out to be a Spanish text encoded in a
Latin-1-family single-byte encoding, not ASCII, not GB18030/Chinese.

## 1. Root layout: only `mudlib/` is the mudlib

The repo root has `mudlib/` (the actual mudlib root, matches
`mudos/bin/config.fficmud`'s `mudlib directory : /devel/mud/fficmud/mudlib`),
`mudos/` (bundled MudOS v21/v22 driver source + a prebuilt Windows
binary -- **excluded**, this project uses its own FluffOS build), and a
few top-level stray files (`LEEME`, `LICENCE.fr`, `README.1ST`,
`RUN-HOWTO`, and a lone `lord.c` -- an orphaned wizard-sandbox object
that lives outside the mudlib root and is not referenced from within it,
confirmed by grep). Only `mudlib/` was copied into `raw/`.

## 2. Encoding: Windows-1252 (Latin-1 family), NOT the default GB18030 --

## caught only after a first, silently-wrong conversion pass

The very first `convert_lib.sh` run used this project's default
`GB18030` source encoding (the overwhelming majority of this corpus is
mainland-China GBK/GB18030 wuxia content). GB18030 is permissive enough
that it doesn't error on Latin-1 Spanish-accent bytes -- it just decodes
them as the WRONG (but valid-looking) codepoints, producing silent
mojibake with no error/warning anywhere in the conversion log. Caught
this by manually diffing a converted file's Spanish text against the raw
bytes: `room/raceroom.c`'s `"\n\n\xbfQu\xe9 eliges?"` (Spanish
"¿Qué eliges?", "What do you choose?") came out of the GB18030 pass as
`"\n\n\xe7\xbc\x8cueliges?"` -- a real but wrong CJK character
sequence, not an error. `iconv -f WINDOWS-1252` (and, equivalently here,
`-f ISO-8859-1`) on the same bytes produces the correct
"¿Qué eliges?".

A pre-check with a naive `grep -rlP '[\x80-\xFF]'` initially (and
wrongly) reported **zero** non-ASCII files -- this turned out to be a
`grep -P`/locale quirk on this environment (the same command under
`LC_ALL=C` still reported zero even on a file confirmed by
`xxd`/Python to contain the exact bytes in question). A direct Python
byte-level scan (`any(b >= 0x80 for b in data)`) is the reliable check
and found **970 files** with high-byte content, consistent with the
converter's own tally after the corrected run (633 clean-decoded +
307 lossy under the wrong encoding, ~940 total -- the small gap is
files whose non-ASCII bytes happened to already be valid, if
coincidental, UTF-8 sequences). **Lesson for future archives: don't
trust a `grep -P` byte-range non-ASCII check on this environment without
cross-checking a positive hit with a direct Python byte scan first --
verify the tool before trusting a "zero" result, especially before
picking a default source encoding.**

Re-ran `convert_lib.sh libs/ninetears/raw/mudlib libs/ninetears/work
WINDOWS-1252` (the script deletes and recreates `work/` from `raw/`, so
this was a clean re-run, not a patch over the wrong one). Confirmed
correct post-conversion: `room/raceroom.c`'s line above now reads
"¿Qué eliges?" verbatim, and a live boot's welcome banner renders "©
Vilat 2002" with a correct copyright glyph. A handful of directories in
the archive are historically double-saved under both an accented and an
ASCII-transliterated name (e.g. `d/faeleen/rooms/rongrond/viñedos_sur/`
alongside a separate, independently-existing `vinyedos_sur/` with
"ny" substituted for "ñ") -- pre-existing archive content, not touched.

30 files remain non-UTF-8 after conversion, all confirmed genuine binary
media (`.jpg`/`.gif`/`.bmp`/`.wav`/`.tar.gz`/`.tar.bz2`), vim swap files
(`.c.swp`), or leftover original-server `tmp/MudOS_swapfile.*` runtime
files -- none of them LPC source, all correctly left untouched.

## 3. `.c` -> `.lpc` rename and reference fixups

22,259 `.lpc` files after rename. 47,673 literal `.c"` reference fixups
applied cleanly (0 remaining). 0 angle-bracket `#include <...c>`
references needed fixing. 9 local angle-bracket includes converted to
quotes (the `<local.h>`-next-to-includer pattern from AGENTS.md §6.1),
harmless/additive since this archive's headers all resolve through the
single global `/include/` directory in the vast majority of cases
anyway -- no `master::get_include_path()` override was needed; every
`#include <foo.h>` seen resolves against `/include/foo.h` directly.

## 4. `static` -> `nosave` sweep

173 files touched. No `#define nosave static`/`#define protected
static` compatibility-shim collision found (AGENTS.md §4.3's second
class). No `"static` string-literal collision found either (the first
class) -- checked via `grep '"static'` post-sweep, zero hits.

## 5. Compile verification -- clean on the first attempt

Before running any batch sweep, compiled the small set of widely-shared
base classes individually with `lpcc` (single-file mode, which also
loads master + simul_efun + preload as a side effect of booting the
compile VM), per this project's RAM-safety discipline:

- `/secure/simul_efun` + `/secure/master` (loaded together, master is
  pulled in as a dependency): clean, only a `domain_file() in the master
  file does not work, using bb_ui as fallback` **informational** notice
  -- NOT the mortremains-class `explode("/","/")` empty-array crash;
  `master.lpc`'s `creator_file()` already has a defensive `if
  (sizeof(str)<2) return 0;` guard, so `domain_file("/")` degrades
  gracefully to a driver-side fallback instead of throwing. The
  preloaded `/secure/ftpd` also compiled and loaded without error.
- `/secure/login`, `/std/object`, `/std/room`, `/std/living/living`,
  `/global/player`: all clean. `/global/player.lpc` produces six
  harmless "Redeclaration of global variable" warnings (`fsize`, `topl`,
  `fname`, `finish_func`, `stat_line`, `last_search` -- all from a
  `/global/more_file` mixin whose variables happen to already exist via
  an earlier inherit in the same file) -- cosmetic, no compile error, no
  runtime effect observed.

Given this clean baseline, ran the full `lpcc_check.sh` batch sweep with
RSS watched every ~15s throughout (peaked around 2.9GB, well under the
10GB danger threshold this session's other libs were warned about). The
first pass came back at 8172/22259 (36.7%) -- see §5a below for a real,
fixable shared-root-cause found by triaging the failure log before
accepting that number, and §5b for the corpus's actual composition
(genuine archive gaps, not a driver-compat bug) behind most of the rest.

### 5a. One real shared-root-cause bug found and fixed: a textually

### `#include`d file's global variable landing before an `inherit`

Per AGENTS.md §6.4 ("one shared root cause, not N bugs"), grepped the
first-pass failure log's error messages by frequency before treating
14,087 failures as unfixable archive noise. `error: Illegal to inherit
after defining global variables.` (419 raw occurrences) traced back to
exactly two real bugs, both a variant of the classic §6.1 "inherit after
globals" dialect issue that this project's catalog hadn't previously
seen via a **textual `#include`** rather than a literal same-file
declaration:

1. **`/d/gremios/hechizos/base.lpc`** (the base class every guild spell
   in the live spell system inherits) does `#include
   ".../bases/patch.lpc"` -- which declares `mapping environment_mods;`
   -- textually *before* its own `inherit ".../bases/tipos.lpc";`. Since
   `#include` is a textual paste, the compiler sees a global variable
   declaration ahead of the inherit statement, identically to the
   same-file case, just one indirection removed. This single file is
   the base for the guild spell system covered by `d/gremios/hechizos/`
   (spells, items, wizard spells) -- fixing it alone recovered ~340
   cascading failures across that whole subtree, this port's version of
   mortremains's `std/monster.lpc` win. Fixed by swapping the two lines
   (`inherit` first, then the `#include`) -- inherit order is otherwise
   unaffected since `patch.lpc` doesn't need anything from `tipos.lpc`
   before it loads.
2. **Eight more `d/gremios/hechizos/` files** (`items/fang.lpc`,
   `wizard/areabas.lpc`, `wizard/shield_s.lpc`,
   `combined/{acid_arr,burnhand,conecold,det_magi,horrid_w}.lpc`) had
   the same shape directly (their own global variables -- spell name/
   cost/damage-type constants -- declared before their own `inherit
   ".../base.lpc"` or `.../patch.lpc"` line). Fixed each by moving the
   `inherit` line above the file's own variable declarations. (A ninth,
   near-identical file, `combined/old/acid_arr.lpc`, was left alone --
   confirmed genuinely dead/orphaned: nothing references the `old/`
   subdirectory, and it inherits a second, entirely nonexistent
   `/std/spells/patch.lpc` regardless of inherit order.)
3. **~46 room files under `/d/ss/daggerford/`** (a real city zone, not
   an `antiguo`-labeled dead one) all shared: `#include "path.h"` /
   `#include "/std/outside.lpc"` / `inherit CITYROOM;`, with
   `/std/outside.lpc` itself declaring `nosave string night_long;` /
   `nosave string dark_long;` before the room's own `inherit CITYROOM`
   -- the identical bug shape via a different textually-included file.
   Reordering alone (moving `inherit CITYROOM;` above the `#include`)
   traded this error for a **second, previously-latent** one:
   `error: Illegal to redefine 'nomask' function 'query_dest_dir'.`
   -- because `/d/ss/daggerford/cityroom.lpc` (the file `CITYROOM`
   points at) *already* does `inherit "/std/outside";` itself, so the
   room's own separate `#include "/std/outside.lpc"` was a redundant
   second copy of the exact same functionality, diamond-inheriting
   `/std/room`'s `nomask` functions a second time once the fatal
   ordering error stopped masking it. This driver rejects that
   redefinition even though it's a genuine diamond (both paths lead to
   the same ultimate file), unlike drivers that silently deduplicate
   identical multiple-inherit closures. Root-caused by reading
   `cityroom.lpc` directly rather than patching around the second
   error -- it already provides everything `/std/outside.lpc` does, so
   the textual `#include` in each room file was pure leftover
   redundancy (very plausibly predating `cityroom.lpc` growing its own
   `inherit "/std/outside"` in the original archive's history). Fixed
   by deleting the redundant `#include "/std/outside.lpc"` line
   entirely from all 46 files instead of just reordering -- verified
   clean on `wall1`/`tim`/`duke1`/`delfen` individually before trusting
   the pattern generally.

Re-ran the full batch sweep after these fixes: **8522/22259 pass
(38.3%)**, up from the first pass's 8172/22259 (36.7%) -- a net +350
files recovered (fail count 14,087 -> 13,737), consistent with the
combined base.lpc cascade (~340) and the eight direct spell-file fixes,
with the daggerford fix's own recoveries appearing separately since
those 46 files were already broken by the *first* pass's ordering bug
before their diamond-inherit issue was even reachable. No new failures
appeared anywhere outside `d/gremios/hechizos/` and `d/ss/daggerford/`.

### 5b. The rest of the gap is a genuine messy-archive content

### composition, not a driver-compat bug -- spot-checked, not bulk-fixed

Per AGENTS.md's own discipline ("fix the *shared* causes, don't blindly
bulk-fix scattered per-file instances in a large archive"), spot-checked
the highest-failure-count directories after the fix above rather than
chasing the remaining ~13,700 failures file-by-file:

- **`/d/driade`** (2216 fails, the mud's *own* home domain -- "Driade"
  is the author's own admin nickname/deity title), **`/d/turkhun`**
  (1926), **`/d/anduar`** (1299), **`/d/keroon`** (1030), and others:
  dominated by `*Inherited file 'X' does not exist!` for base classes
  that are simply **absent from this archive snapshot** -- e.g. an
  entire `/baseobs/weapons/` directory (referenced by several items'
  `inherit "/baseobs/weapons/dagger"` etc.) doesn't exist at all, and
  `/std/underground` (referenced by several Turkhun/duergar rooms) has
  no corresponding file anywhere in the tree. This is the classic
  "missing zone content is an archive gap, not a bug" class -- the
  original live server plainly had these files (dozens of active-zone
  rooms/items still reference them), but they weren't captured in this
  particular backup snapshot. Not fabricated, per project policy.
- **`/w/oldcreators`** (1392) and most other `/w/<name>` wizard-home
  fails: genuine 1990s-2000s personal-sandbox content -- abandoned
  drafts, truncated experiments, copy-pasted-then-modified templates
  with their own independent typos -- the same *kind* of gap documented
  on `mortremains`'s wizard-home tree, just proportionally larger here
  (this archive's overall compile-clean rate is lower than
  `mortremains`'s 78.8%, consistent with `mortremains`'s own `~13,000`
  messy-content caveat scaling down less favorably on a smaller,
  messier, single-language codebase).
- **`/std/antiguo`** (866) and **`/room/antiguo`** (306): `antiguo`
  literally means "old"/"ancient" in Spanish -- this is the archive's
  own self-labeled deprecated subtree (confirmed: nothing outside
  `std/antiguo/` itself references any path under it, e.g. the
  `std/antiguo/spells/` duplicate copies of the `d/gremios/hechizos/`
  spell files fixed in §5a are byte-identical dead pre-refactor
  snapshots). Left alone entirely, matching this project's `adm/AFD/`
  (`mortremains`)-style precedent for confirmed-orphaned legacy trees.
- Common per-file error shapes seen scattered throughout (not bulk-fixed,
  since no single shared file was responsible): the classic `Type of
  returned value doesn't match function return type (int vs void)` on
  `void`-declared functions with a bare `return 1;` (AGENTS.md's
  known class, but scattered across dozens of independently-authored
  spell-item files, not concentrated); the old-MudOS `move("path")`
  single-argument call against this driver's real 3-argument `move()`
  efun signature on a few non-player-class objects lacking this
  project's own `varargs`-wrapped `move()` override; and the expected
  large tail of pure mixin files (`std/basic/*.lpc`) that only compile
  successfully when inherited into a real container object, never
  standalone -- an artifact of `lpcc_check.sh` compiling every `.lpc`
  file individually, not evidence of a real defect.

## 6. Live boot and full registration -- verified end to end

Booted the real driver (`~/src/fluffos/build-debug/src/driver
config.fluffos`, `cd`'d into `libs/ninetears` first per AGENTS.md §5.2)
and drove it with raw Python socket scripts (not `mudclient.py` for the
very first probe -- see the test-harness gotcha below).

**Test-harness gotcha worth recording**: this lib's `secure/login.lpc`
`logon1(str)` treats an **empty-string** first response (`str == ""`)
as `TIME_SHORT` -- it writes a message and immediately `destruct()`s the
connection object. This project's usual smoke-test habit of opening with
a blank `--send ""` (a "press enter to continue past the MOTD" warm-up,
harmless on most libs in this corpus) is genuinely fatal here: it gets
interpreted as a timed-out name prompt and the connection is dropped
right after the banner, with no error anywhere (a real, intentional
`destruct()`, not a bug) -- confirmed via `ss` showing the driver-side
socket actively transition to `FIN-WAIT-1`/local `CLOSE-WAIT`
immediately after sending a bare newline. This is legitimate original
design (a "did you fall asleep at the name prompt" guard), not a
driver-compat defect, and needed no mudlib fix -- just skip the blank
warm-up line for this lib's own test scripts (start straight with the
character name).

Full flow verified with the blank line removed: `fluffos` -> `s` (name
confirm) -> `Mud@2026` -> `Mud@2026` (password + confirm) -> `h` (male)
-> lands in "Plano Inmaterial" ("Tu alma se encuentra flotando en la
inmensa oscuridad del Plano Material... una palabra resuena en tu
conciencia: 'nacer'" -- a birth/soul-formation antechamber, matching a
FR-lineage mudlib's traditional pre-character-sheet room). `look` (shown
automatically on arrival and again on request, consistent both times),
`score` (HP/Mana/Energy/Social/XP bars, all rendering correctly), and
`quit` ("Un rayo divino impacta sobre ti..." / "Gracias por jugar, hasta
la proxima.", clean disconnect) all verified. `players/f/fluffos.o` save
file confirmed created on disk. Zero new fatal errors in `debug.log`
across the whole session -- only the same six pre-existing
`global/player.lpc` redeclaration warnings, logged (correctly) to
`log/root.log` via `master.lpc`'s own `log_error()`-routing (`Root`
being `global/player.lpc`'s domain owner per `creator_file()`).

## 7. Admin account seeding -- TWO independently-gated mechanisms, both

## needed (a new bug-class shape for this project's §1.5 catalog)

This codebase's admin system is unusual among this corpus: rank is not
a flag read at runtime, it's **which player-body base class gets
cloned at login**. `secure/bastards.lpc`'s `query_player_ob(name)`
decides between `/global/player`, `/global/creator`, `/global/lord`,
`/global/god`, etc., and each of those classes **hardcodes** its own
`query_creator()`/`query_lord()`/`query_god()` to unconditionally
`return 1` (e.g. `global/god.lpc`: `nomask int query_god() {return 1;}
int query_lord() {return 1;} int query_creator() {return 1;}`). There is
no single "is this account an admin" boolean to flip -- getting `fluffos`
recognized as a god required edits in **three** separate places, and
missing any one of them leaves the account only partially privileged:

1. **`secure/rango.o`** (a real, restorable save-data file, not
   hardcoded source): added `"fluffos":" la Administracion"` to the
   `dioses` mapping (the same mapping that already lists `jade`,
   `barthleby`, `tyrael`). This makes `secure/gods.lpc`'s `query_boo()`
   (which just delegates to `secure/rango.lpc`'s `dame_dios()`) return a
   truthy title string for `fluffos`.
2. **`players/f/fluffos.o`** (the just-registered player's own save
   file, real data): changed `creator 0` -> `creator 1` and
   `app_creator 0` -> `app_creator 1`. This step is load-bearing and
   easy to miss: `query_player_ob()`'s entire god/lord/thane/patron
   lookup block is gated behind `previous_object()->query_creator()`
   being true *at login time* (`if(previous_object()->query_creator()
   ||flag) { if ("/secure/gods"->query_boo(name)) return "global/god";
   ... }`) -- and `previous_object()` there is the **login object**,
   whose own `creator` field only becomes true via
   `restore_object("/players/.../fluffos",1)` picking up a `creator 1`
   line from the player's OWN save file (same-named-variable restore,
   not a dedicated admin flag). Without this edit, step 1 alone is
   silently ineffective -- the god-table lookup is never even reached.
3. **`secure/master.o`** (master's own restorable save data): added
   `"Fluffos":2` (capitalized, `HIGH_LORD`) to the `positions` mapping,
   alongside the archive's own pre-existing `"sharka":2` entry. This is
   a **completely separate** ACL system from steps 1-2 -- it drives
   `master.lpc`'s `high_programmer()`/`query_lord()` (`positions[
   CAP(str)] == HIGH_LORD || HighLords[CAP(str)]`), which gates
   `valid_read()`/`valid_write()`'s top-level "is this euid privileged"
   check, i.e. actual file read/write ACL, independent of the in-game
   player-body-class rank from steps 1-2. Once `fluffos` is cloned as a
   `/global/god` instance, `move_player_to_start()`'s
   `if (this_player()->query_creator()) seteuid(name); else
   seteuid("PLAYER");` gives it the runtime euid `"fluffos"` (its own
   raw registered name, lowercase) -- `CAP("fluffos")` = `"Fluffos"`,
   matching the capitalized key this step seeds.

All three edits were made directly to the `.o` save-data files (plain
MudOS/FluffOS text-format saves, confirmed safe to edit as text -- no
raw-control-byte encoding in this lineage's save format, unlike
AGENTS.md §7.57's warning class) rather than to source, per this
project's "prefer editing data over code" convention -- none of the
three files needed a code change.

Verified on the NEXT login (a fresh connection, not the same session
that registered the account): a special immortal welcome banner
("Bienvenido, inmortal. Hay mucho trabajo por hacer...") appears
immediately after password entry, replacing the ordinary connect
message; `who` lists the account under "Inmortales" as `Fluffos el
Dios de la Administracion` (matching the exact title string seeded in
step 1); `score`/`quit` continue to work normally. Did not additionally
verify a file-write-requiring wizard command (e.g. `load`/`update`) this
pass -- the `who`-listed god title plus `master.o`'s seeded
`high_programmer` status are the two independent signals this project's
own catalog says to check, and both are confirmed; a deeper wizard-ACL
smoke test can be done in a future pass if this lib gets picked up for
further work.

## 8. A live port collision with a concurrent onboarding session --

## resolved before final commit

The originally-assigned port (40240, picked from the highest committed
`meta.json` port at the time) turned out to be **already in live use**
by a different, concurrently-running onboarding session's driver
(`libs/dreamofseven`, a Chinese-language 夢幻七域 lib, not yet
committed at the time and therefore invisible to the usual
`grep meta.json` collision check). Discovered this the confusing way:
a fresh test connection to port 40240 returned a completely different
mud's (`dreamofseven`'s) Chinese-language banner instead of Ninetears's
own -- traced to `ss`/`/proc/<pid>/cwd` showing a second live `driver`
process whose CWD was `libs/dreamofseven/work`, bound to the same port.
Reassigned to **port 40241** (confirmed free against every `config.
fluffos` file on disk, not just committed `meta.json` entries, at the
time of reassignment) and re-verified the full boot + registration +
admin-login flow again on the new port before proceeding -- this file's
number/port pair was re-checked against the corpus-wide collision query
one more time immediately before the final commit, per this session's
standing multi-agent coordination protocol.

## 9. Preloaded FTP daemon opens a real listening socket at boot

`/secure/ftpd` is the sole entry in `secure/master.o`'s `preload` list
and is loaded automatically at boot. Its `create()` schedules
`setup_ftp(FR_FTP_PORT)` via a 2-second `call_out`, which does a real
`socket_create()`/`socket_bind()`/`socket_listen()` on a **hardcoded**
port (`#define FR_FTP_PORT 4001` in `include/ftp.h`) for an in-game
FTP-style file-transfer feature (upload/download to a player's own
directory over a real FTP-protocol connection, judging by the
surrounding `PASV`/`PORT`-mode `socket_connect()` calls elsewhere in the
same file). This is a genuine additional network side effect at every
boot -- an inbound-listening socket, not an outbound connection like
`imud`/`mortremains`'s Intermud-3 daemon elsewhere in this collection,
but still a real extra open port (4001, independent of whatever main
game port this lib is assigned) that a future automated high-frequency
reboot loop should be aware of, since a stale/colliding process still
holding port 4001 would make this specific feature (not the mud itself)
fail to initialize, and running many copies of this lib's driver
concurrently would only let one of them actually claim port 4001.

## 10. Outbound network check

No outbound `socket_connect()`/`resolve()` call fires unconditionally at
boot or during the compile sweep -- `secure/master.o`'s `preload` list
has exactly one entry (`/secure/ftpd`, an inbound listener only, see
\S9 above) and `call_out_preload` is empty. The Intermud-3 client
(`net/intermud3/`), gopher daemon, and other `net/daemon/` files exist
in the archive but are not preloaded or referenced from any preloaded
file, so they never load unless a wizard manually does so in-game.

## 11. Verification performed

- Clean boot, `Initializations complete.` reached, zero fatal errors
  across three separate boot sessions (initial encoding fix, admin-data
  edits, and the final port-40241 re-verification).
- `lpcc` single-file compiles of `secure/master`+`secure/simul_efun`
  (together) and `secure/login`/`std/object`/`std/room`/
  `std/living/living`/`global/player` individually: all clean, only
  harmless warnings, before ever running the full batch sweep.
- Full `lpcc_check.sh` batch sweep run with RSS monitored every ~15s
  throughout, well clear of the 10GB danger threshold at all times.
- A brand-new character (`fluffos`) registered end to end through the
  real menu-driven flow (name, confirm, password, confirm password,
  gender), landing in the real starting room ("Plano Inmaterial"), not a
  void/error state. `players/f/fluffos.o` confirmed created on disk.
- `look`, `score`, and a clean `quit` all verified producing correct
  output post-login.
- Admin account (`fluffos`/`Mud@2026`) verified on a SEPARATE, later
  login: special immortal welcome banner, `who` listing under
  "Inmortales" with the exact seeded title string.
- Outbound-network check performed (\S10) -- none found; one inbound FTP
  listener on a hardcoded port documented (\S9).
- WASM status: not attempted (`wasm_status` left `""` per task scope).

## 深度功能测试（§10.7 round two, 2026-08-27)

Full one-continuous-session playthrough per AGENTS.md §10.7, on top of
the onboarding-time smoke test in §11 above. Booted
`~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/ninetears/`, drove it with raw Python socket scripts (the blank
warm-up line is still fatal here per the onboarding note -- start
straight with the character name).

### What was tested

- **Newbie help**: `doc/helpdir/nuevo` turned out to be a wizard news
  bulletin, not player-facing help -- the real onboarding text is
  `room/raceroom.lpc`'s own birth dialogue (`nacer`), read directly
  from source to learn the test path: race (12 options) -> class (up
  to 5 per race) -> alignment (9-point axis) -> a point-buy stat screen
  (`sumar`/`restar caracteristica numero`, `aceptar`, `reiniciar`) ->
  a final y/n confirmation.
- **Full registration through birth**, one continuous session: menu
  flow (name `testespa`, confirm, password `Mud@2026`/confirm, gender
  `h`) -> landed in "Plano Inmaterial" -> `nacer` -> Humano/Guerrero/
  Legal Bueno/16 FUE,14 DES,15 CON,18 INT,14 SAB,8 CAR -> confirmed --
  landed in a real starting room with auto-equipped starting gear
  ("Cota y espada larga"), not a void/error state.
- `look`/`score`/`i` at every major state change (post-register,
  post-birth, post-combat, post-quit/relogin) per the checklist --
  see the two `score`-crash bugs below, found exactly this way.
- **Combat and death/respawn**: exercised for real, though via an
  unintended trigger rather than a deliberately-found "safe spar" --
  an admin `call move(...) testespa` teleport landed the test character
  directly inside `d/gremios/rooms/khurgars/guildroom`, whose
  guardian NPC (Tharak) attacks any non-duergar `living()` on
  `event_enter()` (`d/gremios/npcs/tharak.lpc`) regardless of
  membership status -- this is a real, intentional induction-gate/
  trespasser design (several human `khurgar` members exist in the
  archived player saves, so humans clearly CAN join; my teleport just
  skipped whatever the intended non-hostile approach is, most likely
  entering via the room's own "hall" antechamber or talking to Tharak
  before crossing into the practice hall). Produced a real death (HP
  to 0, ghost creation, "El alma de Testespa..." sequence, landed as a
  spirit) and real combat numeric output (varied hit descriptions,
  damage numbers) -- functional combat and the death-transition message
  chain both confirmed working code-wise. **Left as an honest, untouched
  observation, not a fix**: the resulting ghost kept reflexively
  fighting Tharak (auto-retaliating, "Haces 0 hp's de danyo desarmado")
  across a `quit`+relogin cycle, never reaching whichever full
  death-god/resurrection sequence this lib has, instead of the ghost
  either fleeing or the guard disengaging a spirit that can't truly be
  re-killed. This could plausibly be `event_enter()` missing a
  `query_dead()`/ghost check, but I did not confirm it against a
  *non*-teleported natural death (the only path that reached this state
  was my own artificial teleport into a hostile-by-design room), so
  per the scope note in the task brief ("verify a fix doesn't have side
  effects" / "no error signature = design") this is documented, not
  touched. A throwaway test character reaching real death organically
  (rather than via forced teleport into an induction gate) would be
  needed to tell design from bug here -- left for a future pass.
- **`quit`, grep `debug.log`, reconnect after a real gap**: done twice,
  for two different reasons -- (1) an explicit `quit` while the ghost
  was still "fighting" (`really_quit()`'s combat-aware branch,
  `call_out("really_quit", query_level()*foo)`, correctly reported
  "Estas en peleas, tardara un poco." and grabbed/saved first); (2) a
  **raw abrupt TCP disconnect with no `quit` sent at all**, specifically
  to exercise this lib's inline net-dead handling (it has no separate
  `net_dead()` apply -- see the new §7.130 bug below, found exactly
  this way) -- confirmed `debug.log` went from spamming one crash per
  heartbeat tick indefinitely to completely clean across a 15-second
  wait (many ticks) after the fix, and the orphaned body was confirmed
  actually gone from the live game afterwards (`donde testespa` ->
  "Donde esta quien?", not found) instead of lingering forever.
- **Admin verification**: the `fluffos`/`Mud@2026` account seeded at
  onboarding still logs in correctly post-driver-restart (special
  immortal banner, `creator 1`/`app_creator 1` preserved in its own
  save file across the whole session) and still has working
  wizard commands (`stat <name>`, `call fn(...) target`) confirmed live.
  The `;<expr>` eval shortcut (`parse_frogs`, verb pattern `;*`) did
  NOT work in either `; expr` or `;expr` form during this pass (fell
  through to the generic unrecognized-command message both times) --
  not chased further since `call` covers the same need and this is a
  convenience tool, not a player-facing feature; flagged here in case
  a future pass wants to root-cause it.

### The seven standing cross-cutting bug patterns -- checked explicitly

- **§7.121** (float arithmetic in a declared-`int` function, no
  `to_int()`): **found and fixed, two independent instances** --
  `global/player.lpc`'s `ajustar_xp_necesaria()` (crashed `score` with
  `*Array indexes must be integers.` past a nonzero XP-required
  threshold, and would have silently corrupted every level-up's XP
  deduction into a float too) and `std/tienda.lpc`'s `vender()`
  (a per-sale "already sold N of these, discount the price" factor,
  the sole float-typed local in a file whose every sibling percentage
  adjustment correctly stays pure-integer). Both used the no-op
  `(int)xp` cast instead of `to_int(xp)`; both fixed. See AGENTS.md
  §7.121's now-extended writeup for the full detail.
- **§8.3a** (`private`-declared dispatch/callback/call_out function
  demoted via inheritance): **found and fixed, one instance**, a new
  variant shape -- `refresh2()` (the `refresh me` wizard command's
  y/n confirmation callback) is declared in `global/player.lpc`, which
  gets pasted via a textual `#include` into `global/wiz_file_comm.lpc`
  -- which every admin rank (`god`/`lord`/`thane`/`patron`/`regente`/
  `creator`) genuinely `inherit`s. Since `do_refresh()`'s own gate means
  this command only ever runs for admin accounts, the bug hit 100% of
  its intended users. Reproduced live (zero output on any response to
  `refresh me`, not even the function's own "Pardon?" retry message);
  fixed by dropping `private` (kept `nomask`); verified live post-fix.
  See AGENTS.md §8.3a's extended writeup.
- **§7.122** (autoload-style class/marker-item duplication on
  disconnect/reconnect): **checked, structurally different, not
  vulnerable.** This is an FR 3.4 base, not TMI-2 -- its own
  `global/auto_load.lpc` (`create_auto_load()`/`load_auto_load()`) is a
  different, unrelated mechanism (no `query_auto_load`/
  `compute_autoload_array`/`destroy_autoload_obj` naming at all). Traced
  the full save/reload lifecycle: `really_quit()` calls `save_me()`
  (which snapshots `all_inventory()` into the `auto_load` string array)
  BEFORE destructing every auto-load-flagged item, matching the
  documented-safe ordering; `do_load_auto()` (which calls
  `load_auto_load()`) is scheduled exactly once per genuine
  `move_player_to_start()` call, and the force-reconnect-while-still-
  connected path (`secure/login.lpc`'s `try_throw_out()`) re-execs the
  connection onto the SAME existing live body object rather than
  cloning a fresh one, so `do_load_auto()` never double-fires on one
  body. No live duplication reproduced or expected from this mechanism.
- **§7.123** (bare `IDENT = (...);` at file scope killing a file's
  compile): **one apparent hit, confirmed FALSE POSITIVE.**
  `table/soul_data.lpc` (`global_adj`/`soul_data`, the social-command
  "soul" data table) shows exactly this error shape
  (`Type mismatch ( unknown vs string/mapping ) when initializing
  IDENT`) when `lpcc_check.sh`'s batch sweep compiles it as a standalone
  file -- but it is textually `#include`d INSIDE `obj/handlers/soul.lpc`'s
  own `create()` function body (between the `{` and `}`), where
  `global_adj`/`soul_data` are already properly declared earlier in the
  same file, so the assignments are ordinary in-function statements in
  their real compilation context. Confirmed via the batch log itself:
  `/obj/handlers/soul.lpc` (the file that actually loads at runtime)
  shows a clean `PASS`, zero errors -- this is the
  "lpcc compiles every file standalone, including mixin fragments that
  only work when included/inherited into a real container" artifact
  already documented in this lib's own onboarding NOTES.md §5b, not a
  real bug. Left untouched.
- **§7.124** (fraction-vs-percentage unit mismatch on a threshold
  field): **checked, clean.** Grepped for `= 0\.[0-9]+;` assignments to
  `int`-declared fields; zero hits outside dead/`antiguo` content. Also
  specifically checked `wimpy` (the auto-flee threshold, `std/living/
  health.lpc`) since it's exactly this shape's classic victim elsewhere
  in the corpus -- consistently declared and used as an integer
  percentage 0-100 everywhere (`wimpy > 100`, `hp < max_hp*wimpy/100`,
  `(100-wimpy)*i/100`), no fractional literal found.
- **§7.126** (stale pre-`.c`-rename extension in saved door/location
  data): **found and fixed, one confirmed instance, a third distinct
  shape for this bug class.** Not an AREA/coordinate-grid engine (this
  lib doesn't have one) and not a bank-daemon dbase (this lib's
  `std/bank.lpc` never calls `load_object()`) -- instead, a plain
  player-save scalar field. `global/guild-race.lpc`'s `race_ob`/
  `guild_ob`/`clase_ob`/`group_ob`/`race_group_ob` are ordinary
  extensionless path strings used as indirect object references
  (`guild_ob->start_player(...)`); every setter always persists them
  extensionless (confirmed: ~250 such fields across every
  `players/*/*.o` in the archive, all extensionless except one).
  `players/d/drakzten.o`'s `guild_ob` was `"/rol/gremios/khurgar.c"`
  (the file is `khurgar.lpc` now) -- a real pre-existing archive
  artifact from before this project's own `.c`->`.lpc` rename, since
  `.o` save data is out of scope for `convert_lib.sh`'s source-only sed
  pass. Fixed at the mechanism, not the data: added
  `strip_stale_c_ext()`/`normalizar_referencias_ob()` in
  `global/guild-race.lpc`, called once right after `restore_object()`
  in `move_player_to_start()`, so any current or future save with this
  shape self-heals on next login. See AGENTS.md §7.126's extended
  writeup for the general "any scalar object-reference save field, not
  just AREA doors or bank dbases" lesson this confirms.
- **§7.129** (`tell_room()`/`message()` wrapper forwarding an omitted
  arg as a literal `0`): **checked, clean, different mechanism
  entirely.** This lib's own `tell_room()` simul_efun
  (`secure/simul_efun/modified_efuns.lpc`) never touches the native
  `message()` efun at all -- it calls `event(ob, "say", str, avoid)`,
  a completely different lib-internal broadcast dispatcher
  (`secure/simul_efun.lpc`'s `event()`, itself just a `call_other`
  loop over `"event_"+tipo`). The real consumer, `event_say()`
  (`global/events.lpc`), correctly type-checks its `avoid` parameter
  (`pointerp(avoid) ? member_array(...) : avoid == this_object()`)
  before using it, so an omitted/int-0 `avoid` is handled safely with
  no crash. No `message()` call site anywhere in the codebase was found
  passing a bare 2-argument call where a 3rd/4th positional argument
  would matter to the driver's own strict `void|object|object*` check.

### New bug found outside the seven standing patterns

- **AGENTS.md §7.130 (new entry)**: `global/player.lpc`'s
  `heart_beat()` implements this lib's ENTIRE net-dead handling inline
  (no separate `net_dead()` apply exists anywhere in the codebase) --
  and its own unconditional `last_command = time() - query_idle(TO);`,
  meant only for the interactive/idle-warning branch, ran on BOTH
  branches, including right after the `!interactive(this_object())`
  branch's own `quit()` call (which only schedules a delayed
  `call_out`, not an immediate `dest_me()`). This crashed
  `*query_idle() of non-interactive object.` uncaught on literally
  every heartbeat tick for a disconnected player, forever, since the
  crash pre-empted `really_quit()` from ever running -- a genuine
  resource leak (the orphaned object keeps running/compiling forever),
  not just log spam. Found via a real raw-socket abrupt-disconnect
  test (not a code-review guess): `debug.log` showed the identical
  crash recurring against 7+ already-orphaned player-object instances
  left over from nothing more than ordinary earlier reconnect-testing
  in the same session. Fixed with a one-line `interactive()` guard;
  verified both by a clean `debug.log` across many ticks post-fix and
  by confirming the disconnected body was actually destructed
  (`donde testespa` -> not found, instead of an ever-crashing ghost).

### Fixes applied (summary, file:line)

1. `global/player.lpc`, `ajustar_xp_necesaria()`: `return (int)xp;` ->
   `return to_int(xp);` (§7.121).
2. `std/tienda.lpc`, `vender()`: `ajuste=ajuste/(int)ajuste2;` ->
   `ajuste=to_int(ajuste/ajuste2);` (§7.121).
3. `global/player.lpc`, `heart_beat()`: `last_command = time() -
   query_idle(TO);` -> `if (interactive(TO)) last_command = time() -
   query_idle(TO);` (new AGENTS.md §7.130).
4. `global/player.lpc`, `refresh2()`: dropped `private` (kept
   `nomask`) (§8.3a).
5. `global/guild-race.lpc`: added `strip_stale_c_ext()`/
   `normalizar_referencias_ob()`, called from `global/player.lpc`'s
   `move_player_to_start()` right after `restore_object()` (§7.126).

All five changes verified via `lpcc` single-file compile (clean, only
the same pre-existing harmless `global/player.lpc` redeclaration
warnings) both before and after running the §9 LPC formatter on the
three touched files (`global/player.lpc`, `global/guild-race.lpc`,
`std/tienda.lpc`) -- checked all three of §9's known formatter blind
spots (`::`-split, `case`+`//`-comment merge, unbalanced-quote
re-spacing) with zero hits -- and via a full live reboot + re-test of
every fix (`score`, `refresh me`, the abrupt-disconnect repro) after
formatting.

### Test character cleanup

`testespa` (Humano Guerrero, the character used for the birth-flow,
combat/death, and quit/reconnect tests) was removed
(`players/t/testespa.o` deleted) before committing, per this project's
throwaway-test-character policy. Only the seeded admin account
remains in `players/` (see below for the rest of this file).

## 12. WASM status audit (2026-09-01)

`playable`. `secure/login.lpc`'s `logon()` had a classic AGENTS.md
§1.3(e) startup-grace gate: `if(uptime() < 10) { write(JUST_REBOOTED);
dest_me(); return; }`, unconditionally destructing every connection
during the first 10 seconds after boot. The WASM harness connects
instantly after boot, so this fired deterministically on every run.
Bypassed for local/WASM connections only (the same loopback-exemption
pattern used elsewhere in this collection):

```lpc
if(query_ip_number(this_object()) != "127.0.0.1" && uptime() < 10) {
```

The preloaded `/secure/ftpd` (real listening socket on port 4001, see
§9 above) fails to *compile* under WASM without the `sockets` package
(`Undefined function socket_create` etc.) -- but this is a normal,
gracefully-skipped preload failure (the driver just logs it and moves
on to the next preload file), not fatal to boot, so no fix was needed
there: the FTP feature is simply absent under WASM, matching its
absence in any other sandboxed/no-sockets deployment. After the
`uptime()` fix, a full WASM session verified clean: registration
(name, `s` confirm, password + confirm, gender `h`/`m`), landing in
"Plano Inmaterial", `mirar` (look), `score`, and `salir` (quit).
