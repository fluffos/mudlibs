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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

狂想空间基础版（更晚的快照）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 14 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

先读 `doc/help/newbies/newbie`/`newbie2`：本档案是台湾巫师 wade 于 2002 年发布
的 ES II 架构老牌 MUD，与本项目的 `es1_win`/`esI`/`xkx2001`/`kxkj1`（同游戏
不同快照，见 AGENTS.md §11）同属一个大家族。新手流程：设 8 项天赋（膂力/
定性/悟性/胆识/根骨/灵性/容貌/福缘，共 160 点自由分配）→ 进入
`狂想空间新手入门房间` → `enter` 正式进入 → `give cloth to girl` 帮助新
手房里的小女孩 → `down` 两次进入中央驿站/大马路一带。

### 修复的程序性 bug

无。全程 debug.log 干净（仅编译期无害警告），未发现 §7.11/§8.9/§7.34 等已
知类别的确认实例。

### 发现但判定为既有设计、未改动的重要现象（务必记录，供后续同宗 ES II 库测试参考）

**`fight` 指令对"不会说话"的生物（动物）走的是真实杀伤分支，可能导致角色
真的死亡**——现场以 (manager) 账号验证：在 `d/snow/eroad2` 对野狗
（`d/snow/npc/dog.lpc`）使用 `fight dog`，系统提示"看起来野狗想杀死你！"，
数回合后角色"气血"归负、陷入半昏迷、最终"你死了"，被送往 `阴曹入口`（真
实死亡，非"昏迷后自动恢复"）。追查 `cmds/std/fight.lpc` 源码：
```lpc
if (obj->query("can_speak")) {
  me->fight_ob(obj);
  obj->fight_ob(me);          // 双方都是"点到为止"，安全
} else {
  me->fight_ob(obj);
  obj->kill_ob(me);           // 对方是真杀，玩家一方仍是 fight_ob 但对方不是
}
```
`can_speak` 在全部 `d/` 目录下没有任何 NPC 文件显式 `set()` 过（只在
`adm/daemons/race/human.lpc` 等种族档案里设为 1），换言之只有走过种族初始
化流程的人形角色（玩家、以及归属人类种族的 NPC）才会落入安全的
`fight_ob()`/`fight_ob()` 双向分支；纯野生动物（`dog.lpc`/`crazy_dog.lpc`
等，未经种族初始化）会让对方调用 `kill_ob()`，对玩家是真实杀伤。现场用
`fight trainee`（`淳风武馆` 的"武馆弟子"，人形 NPC，无自定义
`accept_fight()`，走默认 `NPC::accept_fight()`）复测：对话式的挑衅讯息
（"你对着武馆弟子说道：...领教...的高招！"，与动物分支的"你大喝一声，开
始对XX发动攻击！"用词不同），全程零受伤，武馆弟子力竭后"跌在地上一动也
不动了"（昏迷，随后自行"清醒了过来"），确认这才是"点到为止"分支。

**判定为既有设计，不是 bug**：`fight.lpc` 自己的 help 文本（"这种形式的
战斗纯粹是点到为止...不会真的受伤"）和 `newbie` 文档的"就算你昏了也没关
系"都是针对"打人"（人形对手）语境说的，武侠类 MUD 里"野兽不懂收力、人可
以点到为止"是常见且合理的题材设定，并非程序逻辑缺陷——`fight`/`kill_ob`
的分流本身工作正确，只是文档的措辞没有明确排除动物这一类目标，容易让新
测试者（或新手玩家）误以为对任何生物用 `fight` 都绝对安全。未做任何代码
改动。**给未来同宗 ES II 库测试的提醒**：挑选"安全陪练"测试对象时，务必
先确认目标是人形 NPC（或亲自读一遍其 `accept_fight()`），不要直接假设名
字看起来温和的生物（"野狗"这类）就安全；已检查 `kxkj1`（本库唯一已完成
§10.7 的同游戏姊妹库）现有 NOTES.md，未记录同一现象，值得下次碰到时留意。

### 测试覆盖

- **注册**：英文 id `kxkjdeep` → 中文名 **秦风廿八** → 密码 `abc12345`
  （×2）→ 邮箱 → 性别 `m` → 8 项天赋各 `20` → 落地
  `狂想空间新手入门房间`。`look`/`score`/`i` 均正常；`score` 面板的
  食物/饮水以表情符号（`^o^`）而非数字条显示，属本档案自有 UI 风格，非
  bug。全程 debug.log 干净。
- **新手引导**：`enter` 进入正式世界，`give cloth to girl` 对新手房间
  的小女孩成功；`down` 两次抵达中央驿站/大马路一带（中央驿站本身有
  `no_fight` 标记，"这里禁止对打"，符合交通枢纽的安全区设计）。
- **安全切磋**：见上方专节——`fight` 对人形 NPC（武馆弟子）安全，对动物
  （野狗）是真实杀伤；用后者现场复现了"死亡"，用前者复现了正确的"昏迷
  →自动清醒"流程。两者都不是程序 bug。
- **技能/门派习得（正规组织路径）**：`join`（`/open/gsword/room/
  swordhouse` 的剑士公会三长老柳毅）成功加入剑士公会，设定 `class`
  属性；`apprentice teng`（仙剑派第三代掌门人郑士欣，`/open/gsword/
  room/g5-1`）因掌门年事已高被引导 `select` 七位弟子之一（选了首徒张乘
  风）；`apprentice fon`（`/open/gsword/room/g1-1`）正式拜入仙剑派第五
  代弟子；`learn force from fon` 成功习得基本内功，`score` 确认武学伤
  害力等数值相应提升。注意：`apprentice` 要求玩家 `class` 属性与目标一
  致（`cmds/std/apprentice.lpc` 第 60-62 行），所以必须先 `join` 公会
  设定职业，才能对该职业名下的门派掌门/弟子拜师——这是本档案自己的两段
  式设计，未改动。
- **技能习得（管理员快捷路径）——本档案没有**：搜遍 `cmds/adm/` 未找到
  任何直接对玩家 `set_skill()`/`improve_skill()` 的管理员命令；
  `skillpass`/`skilldel` 是技能翻译表（中英文对照）管理，不是玩家个人
  技能等级设定。如实记录：本库不提供这类快捷方式，管理员若要提升角色
  技能仍需走正规的 `join`+`apprentice`+`learn`/`exercise` 流程。
- **退出/重连**：`quit` 正常结算（无强制删号规则）。按本档案已有 NOTES
  记录的"注册/quit 从不写入 LOGIN 对象存档，只有净断线路径才写"的既有
  发现，本轮改用 `Ctrl-C` 断开原始 socket（模拟净断线）而非 `quit` 来
  结束第一段连线，约 16 分钟后用同一 id/密码重连，提示"重新连线完
  毕。"，`look`/`score` 确认所在房间与状态完整保留。

### 进程卫生附注

清理了两处与本次修复无关的测试残留：(a) 因现场验证死亡机制而写入
`work/open/death/death_record`（一个跨玩家共享的历史死亡记录文件）的一
行"fluffos浮浮被dog野狗所杀"条目，已用 `git checkout HEAD --` 还原；
(b) 一次 `dump` 指令尝试产生的诊断文件 `work/OBJ_DUMP`，已删除，未纳入
本次提交。

### WASM 未验证说明

按本 session 约定：`emsdk` 固定从 `storage.googleapis.com` 拉取，被本
session 出站代理策略拒绝（`curl -sS $HTTPS_PROXY/__agentproxy/status`
返回 403），WASM 编译/运行验证本轮继续跳过，仅做原生驱动（linux-debug
预设，ASAN/UBSAN）下的完整 §10.7 测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-14)

第一轮（上一节）确认零程序性 bug；本轮独立复核第一轮结论，并新增修复。

### 新发现并修复的 bug

- **AGENTS.md §7.106 第 4 种路径变体**：`cmds/apr/update.lpc` 的
  `main()` 里 `present(file, environment(me))` 在 `environment(me)`
  为 0 时崩溃（`*Bad argument 2 to present()`）。本库属于 ES II
  wade/kxkj 血统，走的是 `apr` 而非 `wiz`/`adm`/`imm` 目录，是本项目
  第一次在此路径命中该崩溃类。修复：
  ```lpc
  // 修复前
  if ((obj = present(file, environment(me))) && interactive(obj))
  // 修复后
  if (environment(me) && (obj = present(file, environment(me))) && interactive(obj))
  ```
  已跨库扫描确认同一路径变体还命中 `kxkj1`、`kxkjii2`、
  `njhhdxdes2hx`、`xbtxiii`（含本库共 5 库），随本库一并提交、已推送
  （独立 commit `413ad703415`）。AGENTS.md §7.106 已补充"第 4 种路径
  变体"小节记录这批库。
- **`adm/simul_efun/file.lpc`**：两处既有类别的实例，本库此前未修：
  1. `cat(string file, int trans)`（2 参数变体，本库特有签名）缺少
     `read_file()` 空值防护，`read_file(file) || ""` 修复；
  2. `log_file()` 缺少 `assure_file()` 目录预建保护，且其定义在
     `assure_file()` 自身定义之前（本驱动不容忍前向调用未声明函数，
     参见本 session 在 `dtsl` 上的发现），补上
     `void assure_file(string file);` 前向声明 + `log_file()` 内的
     `assure_file(LOG_DIR + file);` 调用。

### 复核第一轮已有结论（独立验证，非盲信原记录）

- 全库 grep `log_error(`/`logind.lpc` 两处 `printf` 分支：均已有正确
  的错误级别门控与参数校验，无 §7.34/§8.9 已知类别的未修实例。
- `config.fluffos` 的 `maximum evaluation cost` 为 `1500000`，高于本
  项目已知的问题阈值（300000/700000），无 §7.90 类崩溃风险，无需调整。
- 第一轮记录的"`fight` 对动物走真杀伤分支、对人形 NPC 走安全分支"现
  象复核代码未变，`cmds/std/fight.lpc` 的 `can_speak` 分流逻辑与第一
  轮描述一致，仍判定为既有设计，非 bug。

### 现场验证

驱动干净启动（PID 1630062，`linux-debug`/ASAN 预设），以管理员账号
`fluffos`/`Mud@2026` 登录，确认 `目前权限 -> 【 天  帝 】(manager)`
（角色所在地为第一轮死亡测试遗留的真实存档位置"阴曹入口"，非 bug）。
用 `update /adm/daemons/logind` 验证真实写入权限（重编译成功，确认
`file.lpc`/`update.lpc` 两处修复编译干净）；`update /cmds/apr/update`
自我更新命令本身无可见输出（命令对象在执行中自毁重载的正常边界情
况，非 bug，`debug.log` 确认编译无错误）。`debug.log` 由 570 行增至
673 行，逐行核对零已知错误特征，仅编译期无害警告。两次快速重连（各
自独立 `fluffos`/`Mud@2026` 登录）均正确显示
`目前权限 -> 【 天  帝 】(manager)`，`quit` 产生正常告别横幅与断线
提示。

### 本轮修改的文件

- `work/cmds/apr/update.lpc`
- `work/adm/simul_efun/file.lpc`

## 深度功能测试第三轮 / Deep functional test round three (2026-08-18)

第一、二轮已确认注册/新手引导/`fight` 安全分流/正规拜师/quit-净断线重连均
正常。本轮先读完第一、二轮记录，确认无重复，转向前两轮未覆盖的系统：经
济（商店买卖）、布告栏（真实发帖/读取）、帮派（`cmds/clan/` 整套子系
统）、以及死亡后的完整"奈何桥→鬼门关→酆都城门→黑白无常"复活流程（前两
轮只读过 `/open/death/start.lpc` 源码，从未真正走完全程）。另确认本库
`adm/obj/master.lpc::standard_trace()` 用 `sprintf("%O", error["object"])`
格式化，并未调用 `file_name()`，AGENTS.md §7.111（`file_name(error["object"])`
未判空导致的崩溃）**不适用本库**，无需修补。

### 修复的程序性 bug

无。全程 `debug.log` 完全干净（未生成该文件，即零运行时错误），只有编译
期无害警告。

### 新覆盖并确认工作正常的系统

- **经济 / 商店**：`open/capital/room/cshop.lpc`（`inherit /std/room/shop`
  的正规商行）`sell cloth` 真实卖出（物品从背包移除，店主给出合理反
  馈）；`open/start/room/s5.lpc` 的小贩 NPC（`inherit F_VENDOR`）
  `list`/`buy tea from vendor` 在余额不足时正确走 `notify_fail("你的钱
  不够。")` 失败分支，未崩溃、未静默丢失物品。（顺带发现
  `feature/finance.lpc:262` 有一行 `if (wizardp(this_object())) printf
  ("total=%d\tamount=%d\n", total, amount);` 调试输出，只对巫师身份的
  角色可见——判定为刻意保留给巫师看的诊断辅助，不是崩溃或静默失败，未
  改动。）
- **布告栏（真实发帖）**：`/open/trans/room/room4.lpc`（"中央驿站"，经
  `call_other(.., "???")` 惰性加载 `/obj/board/start_b`）`post <标题>`
  → 编辑器 `.` 结束 → "留言完毕。"，版上留言数从 26 增至 27；`read 1`
  正确读出旧文章内容。确认第 §7.86 节此前修的"多余
  `replace_program()`"崩溃点在真实 `post` 流程下确实不再触发。
- **帮派 / 公会子系统**（`cmds/clan/`，前两轮完全未测）：`c_list` 正确
  列出全部 5 个真实存在的帮派（十三吉祥/阴曹地府/傲云山庄/红莲教/天道
  无极，`adm/daemons/clanvd.lpc::fs_clan()` 扫描 `/open/clan/` 子目录并
  过滤系统保留目录）及四项排行榜；`c_index` 列出完整帮务说明文件索
  引；`help c_deposit`/`help c_donate` 文本正常。`c_create`/`c_join` 读
  代码确认均为合理的既有设计门槛（`c_create` 需要 `wiz_level>=5`；
  `c_join` 需先被现有帮众邀请），非 bug，未做门槛测试（不适合用巫师账
  号測試玩家专属流程）。
- **死亡→复活完整流程**（前两轮只读代码，本轮首次现场走通全程）：从
  `/open/death/start`（阴曹入口）经 `north` ×5 依次穿过奈何桥头
  →奈何桥上→奈何桥尾→鬼门关（白无常）→酆都城门（黑无常），在酆都城门
  停留不动，`open/death/npc/bgargoyle.lpc::init()` 于玩家进入房间时自
  动排程 5 段对话（每段间隔 5 秒），全部播完后自动
  `ob->reincarnate()` + `DEATHROOM->end_death(ob)` + 食物/饮水回满，并
  将玩家送回 `STARTROOM`（"狂想空间入口处"，与新角色注册落地点相同）。
  现场验证：`score` 面板从"(鬼气)"状态变回正常称谓显示、精气神回满
  100%、食物/饮水回满 300/300，`look` 确认房间已切换。**唯一前提**：
  必须在酆都城门原地停留满约 25 秒（5 段 ×5 秒）让 `call_out` 链跑完；
  中途再移动房间会让链条在下一次 `present(ob)` 检查时静默中止（此设计
  与许多 MUD 的"NPC 触发对话需玩家留在原地"惯例一致，不是 bug）。另确
  认：任何鬼魂身份的玩家一旦 `quit`/断线重连（走 `press_enter()`），
  `logind.lpc:867` 的 `if (user->is_ghost()) startroom = DEATHROOM;` 会
  强制把其重新丢回 `/open/death/start`（阴曹入口）——不管之前走到迷宫
  多深处，都会从头开始；判定为刻意的防卡关设计，不是 bug。
- **`阎罗王`（Ghost king，`open/death/npc/king.lpc`）**：这是复活迷宫外
  的一个独立小彩蛋（`kneeze` 下跪给 `standby` 属性加值，用于某种"免死
  符"周边玩法），与黑白无常的自动复活机制无关，未深入测试（超出本轮
  程序性 bug 排查范围，且看起来是内容/玩法而非崩溃点）。

### 排查但判定非 bug（读代码确认，未改动）

- **`/open/death/start.lpc::valid_leave()` 的 `south`/`up` 分支是死代
  码**：函数体对 `"south"`（"想回家吗"警告后需要连续尝试 5~9 次才放
  行）和 `"up"`（`back_road>=10` 时走旧版"手动重生"逻辑）都有完整实
  现，但该房间自己的 `exits` 映射里这两个方向都被注释掉了（只留
  `"north"`），玩家从来无法在这个房间打出 `south`/`up` 指令（会得到
  "什么? south? 请用 help cmds 查询指令。"，因为驱动只给已注册的出口
  自动生成移动指令）。由于本库真正、可达、已现场验证工作正常的复活路
  径是上面那条"黑白无常自动复活"流程，这段死代码不影响任何真实游玩路
  径，只是历史遗留（大概率是从更早的版本继承下来、后来把手动重生改成
  自动化时忘记清掉的旧逻辑）——不是崩溃、不是静默失败，未改动。
- **一开始怀疑 `goto /open/center/room/inn` 会静默吞掉传送（写了个隔离
  测试，重开全新驱动作为连线后第一条指令复现），但排查后发现这是**测
  试脚本的假象**，不是 mudlib bug：本库登录成功后会先打印一条"--
  请按 Enter 键继续 --"，要求先按一次 Enter 才会真正开始处理后续输
  入；连线后发的第一条"真实"指令实际上被这次按键吞掉了（对任何指令都
  会重现，不只 `goto`）。加一条空指令吃掉这次"按 Enter"提示后，同一个
  `goto` 立刻按预期工作。记录此陷阱供以后同 lineage（ES II）库测试参
  考，此次未误报为 bug、未做任何代码改动。

### 现场验证摘要

驱动 `linux-debug`（ASAN/UBSAN）预设，两次全新冷启动分别验证：(1) 管理
员账号 `fluffos`/`Mud@2026`（(manager) 权限）用于经济/布告栏/帮派/死亡
复活流程测试；(2) 全新注册角色 `kxkjrthb` / 中文名"秦风卅一"（英文 id
只能纯小写字母，无数字——首次因误用带数字 id 被反复拒绝后遭防灌水机制
断线，重新用合规 id 后一次成功注册）验证新手引导（`enter`→
`give cloth to girl`→`down`）流程与第一轮结论一致，`down` 第二次进入的
是暗室（"四周到处黑沉沉的, 看也看不清。"，需要光源，属正常暗房设计非
bug）。两条会话全程 `log/debug.log` 均未生成（零运行时错误）。

### 进程卫生附注

测试产生的存档churn（`data/board/start_b.o` 因真实发帖测试、
`data/user/f/fluffos.o` 因管理员多次登入/移动/复活状态变化）已用
`git checkout --` 还原；测试用的全新角色存档
（`data/user/k/kxkjrthb.o`，未跟踪）与临时创建的 `u/f/`（供 `eval` 指
令使用的巫师工作目录，未跟踪）均已删除，未纳入本次提交。驱动进程按
PID 精确 kill（非 pkill 模式匹配）。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,310 处存活匹配，全部为标准独立行形式，脚本一次
  性删除，无不规则残留。房间生成工具 `obj/roommaker.lpc` 检查过——它的
  heredoc 模板本身没有把这行冗余调用写进生成结果，不受影响，不需要修。
  `data/` 下的其余 `.lpc` 源文件（自动加载装备等）额外核查过，无命中。
  验证：真实 debug 驱动干净编译启动、端口正常监听，`debug.log` 无新增
  "cannot replace"/错误行。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `open/death/npc/bgargoyle.lpc`, `open/death/npc/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
