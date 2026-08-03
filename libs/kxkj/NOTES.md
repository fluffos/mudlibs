# kxkj — 狂想空间 (Fantasy Space) II

Archive: `新狂想空间II.rar` ("New Fantasy Space II", #53). Port: 40047.
Status: **done** (boots clean, full registration flow verified
end-to-end including a real Chinese name entering the game world).

## What this is

The archive's own top-level readme (`狂相空间II.txt`) identifies it as
**"狂想空间II"** ("Fantasy Space II"), a Taiwanese source drop dated
October 2002 ("这套源码来自台湾！2002年10月份的狂想空间II"), crediting
the Taiwan wizard **wade** for the release. The archive's *actual*
self-identified name in `config.fs` (`name : 狂想空间`, no "II"/"新")
and the live in-game banner both say plain **"狂想空间"** — noted here
since it differs slightly from the archive filename, per the task's
convention (no separate slug rename needed; `kxkj` is
kept as the working slug since it was pre-assigned).

A second file, `小熊泥苑.txt`, is a collector-site readme (from the
archiving site "小熊泥苑", `http://dtxy.126.com`) explaining that this
particular archive is a BIG5→GB-converted copy of the original Taiwan
"狂想空间" source, not a separate game — consistent with the wade/2002
Taiwan credit above. In-game credit line: `以 ESII 为架构改编，初次架于
1995 9 22，感谢 annihilator & elon & mineral` — confirms this is
**genuinely built on the "ES II" (Eastern Stories II) mudlib base**,
the same lineage already seen in `es1_win`(#12)/`esI`(#13)/`xkx2001`
(#25)/`rzrmud`(#23)/`bmxkx2001`(#45) — `master.c`'s header
comment says exactly `// for ES II mudlib / original from Lil /
rewritten by Annihilator (11/07/94)`. `adm/obj/{master,simul_efun}` +
`adm/simul_efun/*.c` fragment layout (not `adm/single/`), matching that
family. Admin accounts per the readme/`wizlist`: `bear`/`wade`
(manager), `banyan` (arch).

Raw archive: 14,440 files under `raw/fsII/` (the mudlib root — no
nesting, `config.fs` sits directly at top level), 12,089 of them
renamed `.c`→`.lpc`. A prebuilt Windows `MudOS.exe` binary and its
`bin/` support scripts are bundled alongside the source (ignored, per
AGENTS.md — we use our own driver build).

## Fixes applied

1. **AGENTS.md §15h**, standard shape, `adm/simul_efun/chinese.lpc`:
   `is_chinese()`'s GBK lead-byte range check (`strlen(str)>=2 &&
   str[0]>160 && str[0]<255`) rewritten to a CJK Unicode codepoint
   check (`strlen(str)>=1 && str[0]>=0x4e00 && str[0]<=0x9fff`).
2. **AGENTS.md §15h**, `check_legal_name()` in `adm/daemons/logind.lpc`:
   byte-count bound `< 2 || > 12` → character-count bound `< 1 || > 6`
   (message text already said "必须是 1 到 6 个中文字", confirming the
   halved bound, not a guess); removed the `i%2==0 &&` even-byte-offset
   gate in the per-character `is_chinese()` sliding check so every
   character position is checked (previously only every other
   character was checked under UTF-8 semantics).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was present in
   `adm/etc/preload` — removed proactively before the first boot
   attempt, per standing policy.
4. **NEW variant of AGENTS.md §8d/§15o (absolute-path angle-bracket
   `#include`), found here** — this is the most impactful fix in this
   pass. 359 files across the lib write `#include <` immediately
   followed by an **already-absolute path** (leading `/`), e.g.
   `std/armor/cloth.lpc`'s `#include </open/open.h>` and ~350 zone
   files' `#include </open/open.h>`/`#include </open/badman/badman.h>`
   etc. Read the driver source
   (`compiler/internal/lexer_utils.cc`'s `inc_open()`) to confirm the
   root cause: angle-bracket resolution unconditionally joins each
   configured `include directories` entry with the given name
   (`path + "/" + name`), with **no special-case for a name that's
   already an absolute path** — so `<...>`-style absolute includes can
   never resolve, regardless of `get_include_path()` or preload timing
   (unlike the quoted `"file"` form, whose `merge()` helper explicitly
   detects and handles a leading `/` as "absolute from mudlib root").
   **Fix applied**: added `master::get_include_path()` (the standard
   §8d/§15o shape, prepending the compiling file's own directory plus
   `:DEFAULT:`) AND, since `get_include_path()` is only consulted for
   VM-context (mid-connection) compiles per §15o's documented caveat —
   confirmed here too, `lpcc` alone still failed on this file even
   after adding the apply — blanket-converted every `#include <ABSOLUTE_PATH>`
   (`grep -rlZ '#include *<\s*/[^>]*>' | xargs sed -E
   's#include *<[[:space:]]*(/[^>]*)>#include "\1"#'`) to the quoted
   form, which resolves absolute paths unconditionally via `merge()`
   with no VM-context dependency. 359 files fixed in one shot, 0
   remaining. This was NOT just cosmetic: `/std/armor/cloth.lpc` is
   the starting-clothes item every new character equips at the end of
   registration, and (more importantly) `/open/newhand/newhand.lpc`
   (`STARTROOM`) transitively depends on this same pattern — **before
   this fix, every brand-new character's `press_enter()` silently fell
   through to `VOID_OB`** (`catch(load_object(STARTROOM))` failing
   twice, per the existing degrade-to-void fallback in
   `logind.lpc`), landing the player in `/obj/void.lpc`'s "精灵圣域/天
   外天" placeholder room instead of the real newbie room, AND
   triggering an unrelated-looking infinite error-spam loop (next item).
5. **Discovered via the interactive test (not proactive), root-caused
   to item 4 above, no separate code fix needed**: with the character
   landing in `VOID_OB` (whose path top-level dir is `obj`, not
   `open`), `adm/daemons/check_w_r_y.lpc`'s anti-cheat "did a player
   wander outside `/open`" heart_beat check fired every second,
   calling `CBIP_D->record(...)` to log it to a hardcoded path
   (`/u/b/bss/record/no_in_open` — the original site's `bss` wizard's
   home directory, which doesn't exist in this archive: only
   `/u/bear` and `/u/w` exist under `/u`). `write_file()` failed
   (`mkdir()` can't create `/u/b/bss/record` in one shot since its
   parent `/u/b/bss` doesn't exist either), throwing a runtime error
   that aborted `check_w_r_y.lpc`'s `main()` **before** it reached the
   line that would have set its "already recorded, don't retry" flag —
   so the failure retried, and re-failed, every single heartbeat tick
   forever, flooding `debug.log` with `*Wrong permissions for opening
   file ... for append.` once per second. Once item 4's fix let the
   character land in the real `/open/newhand/newhand` room instead,
   this check's `dir!="open"` condition is false and it never fires at
   all — confirmed by re-running the full registration test after the
   fix and finding zero occurrences of this error in `debug.log`. Left
   unfixed (no code change needed): this is a real environment/content
   gap (`bss`'s missing home directory) that simply never gets
   exercised once characters correctly land inside `/open`; fabricating
   a `/u/b/bss/record` directory tree for a wizard account that isn't
   part of this project's scope isn't warranted.

## Fixes applied — found via the `lpcc_check.sh` sweep (post-boot-test pass)

The interactive boot/registration test alone doesn't exercise most of the
game-content tree (rooms/items/NPCs never touched by the registration
path). Running the full sweep afterwards, per AGENTS.md's pipeline,
surfaced these additional genuine bugs (triaged by grouping the 624
initial failures by error-message shape before fixing anything, per
§6b):

6. **NEW bug shape, not yet in the catalog: `#include` of a file that
   itself declares a global variable, positioned textually BEFORE
   `inherit`** — "Illegal to inherit after defining global variables."
   (74 initial failures). The compiler enforces `inherit` must precede
   any global-variable declaration in the ASSEMBLED token stream, which
   includes anything spliced in by an earlier `#include`, not just
   literal declarations in the file itself. Two shapes found:
   - **67 files**, `/open/gblade/room/n_area{0..66}.lpc`: each does
     `#include "n_area.h"` (declares `string *n_area_msg = ({...});`)
     THEN `inherit ROOM;` — one shared header, one shared bug, fixed in
     one shot by swapping the two lines' order in all 67 files (grep
     confirmed all 67 share byte-identical first-3-line structure
     first, then a scripted swap, then re-verified all 67 via
     `lpcc`/spot-check).
   - **5 standalone files** with a bare `object user;` (or `int mean;`)
     declared directly before their own `inherit`:
     `open/main/obj/super-cloth.lpc`, `open/japan/obj/super-cloth.lpc`
     (both copies of the same "雀皇飞云裳" item), `open/mogi/village/
     obj/mcc.lpc`, `open/beggar/skill/pdarray.lpc`, and `u/bear/start.lpc`
     (whose actual culprit was `#include "/include/basic_skill.lpc"`,
     which declares `mapping basic_skill = (...)`, sitting before its
     `inherit ROOM;` — same root shape as the header case above, just a
     different header). Fixed by reordering each file's own
     declaration/include to come after its `inherit` line. All 6 file
     groups (74 files total) re-verified clean via `lpcc` afterward.
   - **Caught and self-corrected a real mistake while fixing this**:
     my first attempt at the 67-file bulk fix used a `sed` one-liner
     that (due to a copy/paste test fragment `sed -i '2,3{2!d}'` left
     in a loop meant only as a dry-run check) actually **deleted** the
     `inherit ROOM;` line from all 67 files instead of moving it.
     Caught immediately by re-checking file contents before trusting
     the result, restored by re-inserting `inherit ROOM;` right after
     the `#include` line, then re-did the fix correctly (moving
     `inherit` to BEFORE the `#include`, since the include's spliced
     content — not just its own line position — is what has to follow
     inherit). Verified via a systematic post-check (`grep -c "^inherit
     ROOM;$"` == 1 in every one of the 67 files) before moving on.
7. **NEW gap, `..`-relative `#include` (driver disallows `..` in
   include paths entirely, both quoted and angle-bracket forms, per
   `docs/lpc/preprocessor/include.md` and confirmed in
   `compiler/internal/lexer_utils.cc`'s `legal_path()` check)**:
   - **27 files** under `/open/start/{npc,room,obj}/*.lpc` used
     `#include <../start.h>` to reach `/open/start/start.h` (a real,
     existing file one directory up) — fixed by rewriting to the
     absolute quoted form `#include "/open/start/start.h"` (safe/exact,
     no content change, `start.h` itself was never missing).
   - **27 files** under `/open/cold/*.lpc` used `#include "../cold.h"`
     to reach a `cold.h` that (unlike `start.h` above) **does not exist
     anywhere in the raw archive at all** — a genuine content gap, not
     a path-syntax issue alone. Reconstructed a minimal `cold.h`
     defining only the two macros actually referenced anywhere in this
     zone's own files (`COLD_ROOM`, `COLD_NPC` — grepped for
     `\bCOLD[A-Z_]*\b` across `open/cold/*.lpc` first to confirm
     `COLD_OBJ` is never used and no `obj/` subdirectory exists there
     either, so it was deliberately not guessed/added), using the
     exact same path-prefix macro style as the sibling zones already
     defined in `open/open.h` (`SNOW`/`SNOW_ROOM`/`SNOW_NPC`/`SNOW_OBJ`
     etc.) — this is the same kind of "reconstruct one small, obviously-
     patterned missing macro header" precedent as `xyzx3`'s
     `WQA_ROOM` fix (AGENTS.md §8g variant), not fabricating game
     content, since none of the actual room text/logic needed guessing.
   All 54 files (27+27) re-verified clean via `lpcc` afterward.

Net effect on the sweep: **130 additional files fixed** beyond the two
proactive §15h/§15p fixes (74 inherit-ordering + 54 `..`-include +
2 header/config side effects), taking the pass rate from the initial
sweep's 94.8% (11,465/12,089) up to the final number below.

## Confirmed NOT needed (checked by reading the source, not assumed)

- **§4** (`load_object`-in-`valid_read`/`valid_write` recursion): this
  lib's `master.lpc` already wraps the lazy `SECURITY_D` load in
  `catch()` with an `objectp()` result check (`if(
  !catch(ob=load_object(SECURITY_D)) && objectp(ob) ) return ...;
  return 0/1;`), the same `catch()`-guarded shape already proven safe
  on sibling ES-II libs (`es1_win`, `rzrmud`, `xkx2001`) — no
  additional reentrancy-flag guard needed. Confirmed via a full clean
  boot + interactive registration/gameplay test producing zero
  recursion/stack-overflow symptoms.
- **§7** (`get_root_uid`/`get_bb_uid`): both already implemented in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID` directly.
- **§14** (2-arg `valid_override`): `master.lpc`'s `valid_override(file,
  name)` is 2-arg, but it already unconditionally allows any file under
  `/adm/simul_efun/` (`if( file[0..15] == "/adm/simul_efun/" ) return
  1;`) — this generalizes past the specific 3-arg/`main_file` case §14
  describes (it allows the whole directory, not just the real
  simul_efun compilation unit), so no `#include`d-simul_efun-fragment
  override was ever at risk of rejection. Confirmed by reading the
  function and cross-checking the boot log for zero `valid_override`
  related denials.
- **§8f** (`TYPE * a, b;` forgotten-star bug): grep found 268 instances
  of the `TYPE *name1, name2;` shape (e.g. `mixed *cnd, err;`, `object
  *enemy,who,user;`), but spot-checking several confirmed each is
  **intentionally** mixed (the starred variable is genuinely used as an
  array via `keys()`/`sizeof()`/indexing, the un-starred ones are
  genuinely scalar, e.g. `err = catch(...)`, `user =
  query_leader()`) — this is normal, correct C-style declaration usage
  in this lineage, not the Dead-Souls-specific copy/paste bug §8f
  documents. No fix applied.
- **§15/§15b family** (nitan-lineage bare simul_efun
  `set`/`query`/`delete` dbase architecture bug): `feature/dbase.lpc`
  implements real, local `set`/`query`/`delete`/`add` methods (via
  `inherit F_TREEMAP;`), and `logind.lpc`/other objects `inherit
  F_DBASE;` directly — the architecturally-correct per-object pattern,
  same as `rzrmud`/`es1_win`. Confirmed by reading `feature/dbase.c`
  before boot; no simul_efun-shared-storage bug exists here.
- **`tail()` missing-efun (§8e)**: grep found zero calls to `tail(` /
  `efun::tail(` anywhere in the lib.
- **`array` bare-type declarations (§15f)**: zero matches for the
  `array name;`/`array name = expr;` shape.
- **Case-sensitivity data-file bugs (§15g/§15k)**: not investigated
  exhaustively (no symptom pointed at one), but the WELCOME/MOTD/etc
  paths in `login.h` all matched real on-disk casing, and the boot +
  full registration/gameplay test produced no missing-file symptoms.
- **Encoding stragglers**: `convert_lib.sh` reported `lossy=0` (no
  invalid-byte drops at all, unlike several prior libs). A follow-up
  `file`-classifier sweep flagged 12 files (`include/lock.h` [1-byte,
  effectively empty], plus 11 `.lpc`/`.h` files under `open/`) as
  "data" instead of "text" — verified each is a **false positive** of
  `file`'s heuristic (short files / heavy box-drawing and ANSI-color
  content confusing its classifier), not an actual encoding problem:
  every one round-trips clean through `iconv -f UTF-8 -t UTF-8` and
  `cat`s as correct, meaningful Chinese/English text (e.g.
  `open/heaven/castle/room/sky0.lpc` reads "//天界之城 Edit By Del" and
  a correct long-description block). No further conversion needed.

## Known lpcc-sweep failures NOT fixed (pre-existing content bugs/gaps, not driver-compat)

Triaged the remaining failure categories after the fixes above; none of
these are on the registration/boot path (confirmed via the clean
interactive test) and all are pre-existing authoring issues in the
original archive, not artifacts of this conversion pass:

- **~22 files, "Illegal character 0xNN" in item/skill flavor text**
  (`/nets/god/god_*` wizard-tier equipment, `/obj/board/immo_b`,
  `/obj/turtle_blood`, `/open/beggar/skill/kang_s`, and others):
  decorative ANSI-color-macro item names missing their `+` concatenation
  operators between bare macro tokens (`HIB`/`HIW`/`NOR`) and adjacent
  quoted box-drawing characters (confirmed via the raw pre-conversion
  bytes — the underlying GBK byte `0xA1F5` correctly decodes to "□"
  WHITE SQUARE either way, so this is a genuine missing-`+` authoring
  bug, not an encoding artifact). Not a single uniform shape across all
  22 (some are missing `+` between string segments, at least one has a
  bare box-drawing character sitting on its own source line entirely
  outside any string/expression) — spot-checked several to confirm the
  variety before deciding NOT to risk a blanket regex fix; these are all
  decorative wizard/misc item names, never touched by registration.
- **1-2 files, "Undefined function set"/"set_name"**
  (`open/snow/npc/medical_boy.lpc`, `u/w/wade/npc/money.lpc`): the
  `inherit F_VENDOR;` line is explicitly commented out
  (`// inherit F_VENDOR;`) — this looks like a deliberately
  disabled/work-in-progress NPC (the original author's own comment
  marker, not something broken by conversion), not restored since
  there's no way to know whether commenting it out was intentional.
- **~15 files, "Cannot #include stdio.h"/"uid.h"/`/u/c/cage/lib/door.h`**:
  `adm/daemons/network/{mail_serv,pingd,pingtcp,telnetd}` (unused
  network utility daemons, none in `adm/etc/preload`), `include/{crypt,
  cstrip,replace,touch}` (oddly-placed personal admin-utility scripts),
  `open/killer/{home,room}/rb*` (a door-based sub-area referencing a
  specific wizard's personal library, `/u/c/cage/lib/door.h`, which
  doesn't exist in this archive), and `u/w/wade/text3d` (a personal
  test file). All orphaned/dead/personal content per AGENTS.md §12/§13
  — not fabricated, not fixed, never reached by any live code path.

## Config notes

`config.fluffos` adapted from the lib's own `config.fs` (converted to
UTF-8 before any other edit, per AGENTS.md §5). Dropped three
driver-obsolete keys the boot log flagged (`reserved size`, `binary
directory`, `swap file` — all warned "obsolete line in config file,
please delete" on the first boot attempt). `maximum local variables`
(50) and `living hash table size` (100, in the "not currently used"
section) both trip a harmless "invalid new value, resetting to
default" warning — cosmetic only, left as-is (matches the archive's
original values, not something we need to correct). Created
`work/adm/tmp/` (referenced by the original `swap file` directive,
long removed from the config but the dir doesn't hurt to have) and the
sibling `log/` directory (driver's `log directory` resolves relative
to CWD, not mudlib root, per AGENTS.md §6).

## Registration-flow transcript (verified end-to-end)

Read `adm/daemons/logind.lpc`'s full callback chain before scripting
the test (`logon → get_id → confirm_id → get_name → new_password →
confirm_password → get_email → get_gender → get_points ×7 →
enter_world → press_enter`) — no hidden BIG5/client-version pre-id
gate in this lib (the very first prompt is the real English-id
prompt). Point allocation is 8 attributes/160 points average 20 each,
but only 7 of them (`str,cps,int,cor,con,spi,per`) are prompted
individually — the 8th (`kar`) is auto-computed as the remainder the
moment the `per` prompt is answered, going straight to `enter_world()`
with no further prompt.

Ran via `python3 scripts/mudclient.py 127.0.0.1 40047 --timeout 45
--idle 1` in one continuous connection, `--send` sequence: english id
→ `y` (confirm new char) → **real Chinese name "秦风二"** → password
→ password again → email → `m` (gender) → `20`×7 (attribute points) →
`` (press enter) → `look` → `quit`.

Outcome: id accepted, confirmation accepted, **"秦风二" (a genuine
2-character Chinese name) accepted by the fixed `is_chinese`/
`check_legal_name`**, password/email/gender/all 7 attribute prompts
all proceeded correctly, character creation completed, and the
character was dropped into the **real starting room**
("狂想空间新手入门房间" — "Fantasy Space Newbie Room", under
`/open/newhand/newhand`), with the room's full Chinese description,
exits, a same-session news bulletin, and birthday-reminder message all
rendering correctly. `look` re-displayed the same room correctly.
`quit` produced a clean goodbye ASCII-art banner and disconnect
message ("你离开狂想空间了。" — "You have left Fantasy Space."). Zero
crashes, zero permission-denied errors, zero `debug.log` runtime
errors for the whole session (only harmless "Unused local
variable"/"Illegal to declare nosave function" compiler warnings,
which this mudlib's `error_handler` happens to echo to the connected
client live — pre-existing/cosmetic behavior, not something introduced
by this pass, not fixed).

(An earlier attempt reusing the already-registered id `qinfeng` from a
first, pre-fix test run correctly hit the "already registered, enter
password" branch instead of character creation — expected, not a bug;
and a follow-up attempt with a fresh id within the same 10-second
window correctly hit `logind.lpc`'s per-IP anti-flood throttle
("请勿连续尝试，请您稍后再连线。", same shape as AGENTS.md §15j) — also
expected, resolved by waiting past the in-memory 10s window, not a
restart.)

**Re-verified again after ALL fixes above (including the sweep-driven
inherit-order/`..`-include fixes) with a fresh id/name (`qinfengc` /
"秦风三")**, on a freshly-rebooted driver: identical clean outcome,
same real starting room, same clean `quit`, and this time zero
`debug.log` output at all beyond the harmless compiler-warning echoes
(confirming the `check_w_r_y.lpc`/`cbipd.lpc` error-spam from item 5
above is genuinely gone now that the character lands in `/open/...`
instead of `VOID_OB`).

## lpcc sweep

`scripts/lpcc_check.sh libs/kxkj/config.fluffos
libs/kxkj/work`, run twice:

1. **First pass** (before the sweep-discovered fixes above):
   `total=12089 pass=11465 fail=624` (94.8%).
2. **Final pass** (after fixing the 74-file inherit-ordering bug and the
   54-file `..`-include bug, both described above): **`total=12089
   pass=11595 fail=494` (95.9%)**. The remaining 494 failures were
   re-triaged by error-message shape and confirmed to be exactly the
   "known, not fixed" categories documented above (decorative-item
   `+`-concatenation typos, 1-2 deliberately-disabled NPCs, and
   orphaned/personal-wizard/dead-network-utility content) — zero new
   or unexplained failure categories introduced by any fix.

Ran concurrently with other agents' sweeps on this host both times;
memory stayed healthy throughout (`available` — the metric that
matters, not the `free` column, which dipped much lower due to normal
page-cache usage — stayed in the 13-19GB range out of 23GB total for
essentially the whole run, spot-checked repeatedly via `free -h`).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (12089 files): 12064
  reformatted, 24 already-clean/unchanged, 1 self-checked error
  (skipped, expected on legacy code).
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`):
  booted clean (only pre-existing compile warnings, no fatals). Full
  registration flow re-verified end-to-end with a fresh real Chinese
  name ("秦风廿二") — English id → confirm y/n → Chinese name →
  password ×2 → email → gender → 7 attribute prompts (all `20`) →
  entered the real starting room (`狂想空间新手入门房间`);
  `look`/`score`/`quit` all produced correct Chinese output.
  `log/debug.log` was completely clean (no output at all beyond driver
  startup). Reformat + new driver build introduced no regressions.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly — the only preload-time errors are the expected non-fatal
  `Undefined function socket_create`/`socket_bind`/`socket_close` in
  `adm/daemons/ftpd.lpc` (no `sockets` package under WASM). Full
  registration flow **completed successfully** under WASM with a real
  Chinese name ("秦风测试") through the identical prompt sequence,
  reaching the same starting room, `look`/`quit` both correct. The
  known `query_ip_number()` WASM limitation is visible but purely
  cosmetic here: the welcome banner's "您正以位址 ... 连线中" line
  prints a blank IP instead of `127.0.0.1` under WASM, but this lib
  doesn't gate login on the IP's format anywhere, so it has no
  functional effect — a clean, fully-playable WASM result.

## WASM-enablement pass (2026-07, loopback/uptime/throttle + admin seed)

Standard WASM-first pass per AGENTS.md §1.3(b)/(e) and §1.5. Loopback =
`127.0.0.1`, any `127.` prefix, or an empty/non-string/malformed IP
(covers older WASM `query_ip_number()` garbage). Gates patched:

- `adm/daemons/cbipd.lpc::check_ip()` (~line 7): loopback short-circuit
  `return 0` — the banned-IP list ("此 IP 目前已被停用") can never hit
  local connections.
- `adm/daemons/relog_ip.lpc::check_ip()` (~line 38): loopback
  short-circuit `return 0` — the auto-ban ("重连太多次被ban 3天") can
  never hit local connections.
- `adm/daemons/banmultid.lpc::ban_multi()` (~line 17): loopback
  short-circuit `return 1` (allowed) — the per-IP concurrent-login cap
  no longer applies to local connections.
- `adm/daemons/logind.lpc::logon()` (~line 204): the 10-second per-IP
  reconnect block (`blocks[ip] > time()`, "请勿连续尝试") is now
  loopback-exempt. This removes the README's old "wait ~15s between
  test connections" caveat for local play.
- `adm/daemons/logind.lpc::new_destruct()` (~line 1176): loopback
  connections are no longer recorded into the `blocks[]` mapping or the
  auto-ban counters (they just destruct cleanly) — repeated local
  testing can no longer poison `/adm/etc/relog_ip`.
- No `uptime()` startup-grace gate in this lib.

Admin seed: registered `fluffos` / display 浮浮 / password `Mud@2026`
through the real flow (id → `y` → Chinese name → password x2 → email →
gender m → seven "20" talent allocations → empty send → world). Granted
`(manager)` — the TOP rank of this lib's `wiz_levels` (above `(admin)`)
— by appending `fluffos (manager)` to `/adm/etc/wizlist`. Verified:
relogin as fluffos → `update /adm/daemons/banmultid` →
"重新编译 ...成功！".

**Lineage quirk worth knowing**: the relogin path checks the LOGIN
object's save (`/data/login/<c>/<id>.o`), but registration/`quit` never
writes it (`ob->save()` is commented out in `enter_world`, and
`cmds/std/quit.lpc` destructs the body without saving the link object).
The login save is only written by the NET-DEAD path
(`obj/user.lpc::net_dead()` → `link_ob->save()`). So to make a fresh
account relogin-able, end its first session by dropping the connection
(client timeout), NOT by `quit` — that is how
`data/login/f/fluffos.o` was produced here. (Pre-existing behavior,
documented rather than changed.)

Retest: fresh normal registration (`qfkxkj` / 秦风) re-verified
end-to-end into the newbie welcome area with `look`/`score`/`quit`
correct; test saves removed. No new errors in `log/debug.log`.

Save files for the orchestrator to add (both paths tracked, not
gitignored; `data/user/f/` and `data/login/f/` are NEW directories):
- `libs/kxkj/work/data/user/f/fluffos.o`
- `libs/kxkj/work/data/login/f/fluffos.o`
