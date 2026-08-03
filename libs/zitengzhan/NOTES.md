# zitengzhan — 紫藤站 (archive #77, `紫藤站.rar`)

## What this lib is

Root dir inside the archive is `ztxy2013/` (self-named "ztxy" = 紫藤西游).
`include/mudlib.h` gives the full game name: **`MUDLIB_NAME "大唐西游之紫藤站"`**
("Journey to the West of the Great Tang — Wisteria Station"), branded
in-game as `【紫藤西游】`/`大唐西游·紫藤站`. Config's own `name` field
(after encoding fix) is `紫藤西游`; live banner during testing showed both
"大唐西游·紫藤站" and "紫藤西游" — same game, matches the slug/archive title
(`紫藤站`) closely enough that no slug-vs-title note is needed.

`adm/obj/master`'s header credits **"for ES II mudlib, original from Lil,
rewritten by Annihilator (11/07/94)"** — this is the same "ES II" engine
lineage as es1_win/esI/xkx2001/rzrmud/bmxkx2001/
kxkj/yueyingqiyuan/wuhanzhan/yanhuangwuhun/haiyang2/
kxkj1/huoying/yhyxs/shenzhou/shenmo — one of
the largest lineages processed in this project. Layout is `adm/obj/` +
`adm/daemons/` (not the `adm/single/` or `adm/kernel/` variants), matching
es1_win/xkx2001/rzrmud most closely. Large lib: 189MB raw / 14,643 `.lpc`
files after conversion (comparable to xiakexing100's 14,227).

## NEW finding this pass: an extensionless "live" file coexisting with a
## stale same-named `.c`/`.C` backup can make the WRONG one authoritative
## after the `.c`→`.lpc` rename — check every lib for this going forward

This archive has an unusually large number (35) of file pairs where a
**real, actively-edited object with NO extension at all** (e.g.
`adm/obj/master`, `adm/daemons/securityd`, `feature/command`,
`feature/damage`, `adm/simul_efun/message`, `cmds/usr/score3`, ...) sits
right next to a **`.c`-suffixed sibling** (`master.c`, `securityd.c`,
`command.c`, ...) that is sometimes a stale earlier backup and sometimes a
newer rewrite — the direction isn't consistent, it has to be checked
per-file. Both the config file's `master file`/`simulated efun file`
directives AND the lib's own macros (`SECURITY_D`, etc.) name the
**extensionless** path with no suffix at all.

Per this driver's real resolution rule (confirmed by reading
`~/src/fluffos/src/vm/internal/simulate.cc`'s `load_object()`):
extension-less names are resolved as **`.lpc` first, `.c` as a fallback —
there is no third attempt at a literal zero-extension filename.** So once
`convert_lib.sh` renames `master.c` → `master.lpc`, **that renamed backup
silently becomes the ONLY thing the driver will ever load** for
`master file : /adm/obj/master`, even though a separate, sometimes-more-
correct `master` file with no extension at all sits right next to it,
completely untouched by the whole pipeline (its glob is `*.c`, so it's
invisible to every mechanical fix pass — encoding, `.c"`-reference-fixing,
`static`→`nosave`, all of it).

**Found via this**: `adm/obj/master.c` (→ `master.lpc`) had TWO real bugs
not present in the extensionless `master`:
1. A stray `return;` right after the local-variable declaration at the top
   of `log_error()`, silently making the whole function a no-op (dead
   code — no logging, no player-facing error text, ever). Removed.
2. `preload()` used an old `call_other(file, "??")` force-load trick
   (works, but always throws a catchable "Undefined function" error per
   daemon, spamming the boot console for no benefit) instead of a plain
   `load_object(file)`. Restored to `load_object(file)`.

Went the OTHER direction for other pairs in this same archive:
`feature/message` (`.c` had the fuller `message_vision(msg,me,you,view,
shield)` signature with shield/view support — the extensionless copy was
the older simpler one), `cmds/usr/score3` (`.c` was "rewritten by huarong
2004/2", clearly superseding a `<SecCrypt CPL V3R05>`-protected older
extensionless original), `obj/mailbox` (trivial one-line difference, `.c`
version has an active `CONVERT_D->input()` call the other has commented
out). **`securityd.c`/`securityd`**: `.c` version (→ `securityd.lpc`, the
one actually loaded) has a strictly larger ACL (extra `d/obj/newitem`
excludes, a `jznt`→`(admin)` special case, a `PLAYERCITY_FILE_DIR` allow)
with no functional regression versus the extensionless copy — kept as-is.

**Recommendation for AGENTS.md**: add this as a new catalog entry. The
check is cheap: `find <raw-root> -type f ! -name "*.*" | while read f; do
[[ -f "$f.c" ]] && echo "PAIR: $f <-> $f.c"; done` (exclude `u/`,
`binaries/`, `backup/`, `OBJ_DUMP/`). For any hit that's on the boot/
registration critical path (master, securityd, simul_efun, logind, or
anything `#include`d/inherited by them), diff the two by hand and decide
which is genuinely correct — don't assume either direction ("`.c` is
older" or "`.c` is newer") holds consistently even within one archive.

## Fixes applied (with why)

- **§15h (GBK byte-range Chinese-name check)**: `adm/simul_efun/chinese.lpc`'s
  `is_chinese()` used `str[0] > 160 && str[0] < 255` (GBK lead-byte range)
  and `strlen(str)>=2` — replaced with a CJK Unified Ideographs codepoint
  check (`str[0] >= 0x4e00 && str[0] <= 0x9fff`) and halved the length
  floor to `>=1`. `adm/daemons/logind.lpc`'s `check_legal_name()` had the
  matching sliding-window bug: `i%2==0 && !is_chinese(name[i..<0])` (byte-
  offset gate, only checking every other position) — dropped the `i%2==0
  &&` gate so every character position is checked; halved the length bound
  from `<2 || >12` (bytes) to `<1 || >6` (chars), matching what the
  message text already promises ("必须是一到六个中文字" = 1 to 6 Chinese
  characters). A THIRD, separate combined-length guard in `get_name()`
  (`strlen(arg) > 8`) was also halved to `> 4` (the "how many total
  characters the whole name may be" cap, tighter than check_legal_name's
  own 6-char ceiling — original intent was clearly 4 real characters at
  8 GBK bytes).
- **§3/§15z**: `include/globals.h` had a `#ifndef __SENSIBLE_MODIFIERS__ /
  #define nosave static / #define protected static / #endif` compat shim.
  `__SENSIBLE_MODIFIERS__` is never defined by this driver, so the shim
  was always active; the blanket `static`→`nosave` sed rewrote it to
  `#define protected nosave`, silently aliasing `protected` to `nosave`.
  Neutralized the whole shim with `#if 0` (both keywords are real,
  correctly-behaving, and need no translation on this driver).
- **§3 counterexample**: 68 files hit the exact `log_file("static/X", ...)`
  → `log_file("nosave/X", ...)` collision (a lib-specific log-subdirectory
  naming convention, unrelated to the keyword) — `log/static/` and
  `log/monitors/` already existed as real seed data on disk. Reverted all
  68 occurrences back to `"static/...` via a scoped sed
  (`s/"nosave\//"static\//g` on every file that matched), verified zero
  `"nosave/` string-literal hits remain and `protected void crash(...)`
  in master.lpc is untouched.
- **§14 (`valid_override` 2-arg → 3-arg)**: upgraded `master.lpc`'s
  `valid_override` to `varargs int valid_override(string file, string
  name, string main_file)`, also trusting `main_file == SIMUL_EFUN_OB ||
  main_file == MASTER_OB` — confirmed via the lpcc sweep that this
  matters for `adm/simul_efun/object.lpc`/`oo.lpc`'s `efun::destruct(ob)`
  call when compiled STANDALONE (the fragment's own `file` !=
  SIMUL_EFUN_OB), though the REAL boot's `simul_efun.lpc` load already
  went through clean either way (see §6b note below).
- **§8d/§15o (`get_include_path()` insurance)**: master had none at all;
  added the standard prepend-including-directory + `:DEFAULT:` fallback,
  proactively, before any failure was observed.
- **§15w (log_error warning-spam gate)**: `master.lpc`'s `log_error()`
  showed either the full compiler trace (wizard) or the generic scary
  default error message (non-wizard) to `this_player(1)` for EVERY
  message reaching this apply, including plain compile *warnings* — gated
  the player-facing echo on the message NOT containing `"warning:"` (still
  logs everything to `home+"log"` regardless). Narrower blast radius than
  wuhanzhan's version (this one only ever messaged the one causing
  player, never broadcast to everyone online) but same underlying gap.
- **§8h (convertd.lpc Greek-table typo)**: 45 occurrences of the stray
  trailing-backslash-before-closing-quote pattern (`"X\",` → `"X",`),
  fixed with the standard sed. File had plain LF endings, no CRLF
  workaround needed.
- **§15t (absolute path in `#include <...>`)**: `death/npc/heiwuchang.lpc`
  had `#include </d/panshi/panshi.h>` — converted to quotes. The header
  itself doesn't exist anywhere at the referenced path (only a same-named
  file survives under an unrelated wizard's personal directory,
  `u/lying/obj/panshi.h`) — a genuine §13-style missing-content gap, not
  fixed further; this NPC isn't preloaded or reachable from the
  registration path.
- **§15ac (bare `SAVE_EXTENSION`)**: 2 files
  (`adm/daemons/network/netmail.lpc`, `u/tianlin/wiz/token.lpc`) used the
  bare macro instead of `__SAVE_EXTENSION__` — fixed both (low priority:
  neither is preloaded or on the critical path, one is intermud/network
  code, the other a personal wizard tool).
- **Uppercase `.C` files (§15h/shenmo precedent)**: 183 files, all under
  `armor/`, `clone/bq/`, etc. — `convert_lib.sh`'s glob only matches
  lowercase `.c`; manually found and renamed all 183 to `.lpc`. No quoted
  string references to the uppercase names existed anywhere (verified via
  grep), so no reference-fixing needed beyond the rename itself.
- **Pre-existing typo, `logind.lpc:129`**: `if( (ip_number[i] != '.') &&
  (ip_number[i]>'25') )` — a multi-character literal `'25'` is illegal on
  this driver's grammar (single-char constants only), a hard compile error
  that took down the entire preload chain (logind is preloaded). Clear
  intent from context (validating an IP-number string as digits-and-dots
  only) — fixed to the single-char `'9'` (reject anything that's neither
  a dot nor a digit).
- **Two isolated BIG5-encoded files** (found via `convert_lib.sh`'s
  "FAILED to convert" list, distinct from the archive's otherwise
  consistent GBK/GB18030 encoding): `d/sea/npc/beast1.c` (a genuine NPC,
  BIG5 content with one stray trailing garbage byte `\xff\xba` past the
  final `}`) and `d/obj/quest/shuijingqiu.pujing` (an orphaned, genuinely
  truncated/corrupt file with no references anywhere in the tree, `.pujing`
  extension so never compiled regardless). Both converted with
  `iconv -f BIG5 -t UTF-8 -c` (drops the trailing invalid byte); `beast1`
  renamed to `.lpc` and is real, working content; `shuijingqiu.pujing` left
  with its original odd extension since nothing loads it.

## Confirmed NOT needed (and how)

- **§4 (lazy `load_object` in `valid_read`/`valid_write` recursion)**:
  `master.lpc`'s `valid_read`/`valid_write` only call `find_object
  (SECURITY_D)` — never `load_object()` — so the recursion trap can't
  fire. Confirmed by reading the actual function bodies.
- **§7 (missing `get_root_uid`/`get_bb_uid`)**: both present in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID` respectively.
- **§15n (custom securityd ACL blocking mid-connection lazy compiles)**:
  `securityd.lpc`'s `valid_read` early-allows everything whose `func`
  ISN'T one of `read_file`/`file_size`/`stat`/`read_bytes`/`tail`/
  `ed_start` — `load_object`/`recompile_object`/`include` all fall
  through to that early `return 1`, so the gap this bug class needs never
  opens here. Confirmed by reading the function; also empirically
  confirmed by the clean boot (every never-preloaded daemon the
  registration flow touches compiled/loaded without a single "Read access
  denied" in `debug.log`).
- **§15l (master destructing SIMUL_EFUN_OB)**: `master.lpc create()` only
  does `write(...)` — no `destruct()` call at all.
- **§15 (nitan-family simul_efun dbase architecture bug)**: `feature/
  dbase.lpc` implements real local `set`/`query`/`delete`/`add` (+ `_temp`
  variants) methods against its own `dbase` mapping — not a bare
  simul_efun call relying on `this_object()`. Confirmed by reading the
  file directly; this lineage was never nitan/kernel-family to begin with.
- **§15p (DNS/intermud daemon preload hang)**: `adm/etc/preload` has no
  `dns_master` entry at all (confirmed by `cat`); a full `network/
  dns_master.lpc` DOES exist on disk but is never referenced from
  `logind.lpc`'s real registration-flow functions (only from unrelated
  `u/`-personal backup copies of `logind.c`) — confirmed via grep, so
  §15ab's "called inline even when excluded from preload" variant doesn't
  apply either.
- **§15ae (`private nomask` command-hook silently breaking every
  post-login command)**: `feature/command.lpc`'s `command_hook()` (the one
  actually wired to `F_COMMAND`, confirmed via the macro) is declared
  plain `nomask int command_hook(string arg)` — the `private` modifier is
  present only as a COMMENTED-OUT line directly above it (`// private
  nomask int command_hook(string arg)`), i.e. this lib's own history
  already dropped it, matching the already-fixed state seen on shenmo/
  shenzhou. Confirmed empirically too: `look`/`score` both produced real
  output post-login (transcript below).
- **§15ag (`ed_start`/`ed_cmd`/`query_ed_mode`, `__OLD_ED__` build)**:
  grepped the whole tree — the only hits for these three names are inside
  `securityd.lpc`'s `valid_read`, comparing the `func` STRING parameter
  against the literal `"ed_start"` (an ACL case, not an efun/apply call at
  all). No lib code anywhere calls the real `ed_start()`/`ed_cmd()`/
  `query_ed_mode()` applies.
- **§15ah (missing save-data directory silently swallowing a `write_file`/
  `log_file` error)**: every `log_file()` path referenced from the boot
  chain / registration flow (`static/CRASHES`, `monitors/login`,
  `monitors/wrongpass`, `monitors/wizpass`, `FILES`, `efun`, `read_files`,
  `user_count`, `counter_for_web`, `band`) resolves to either the log
  root or an already-existing subdirectory (`log/static/`, `log/
  monitors/`, both present in the raw archive). Player-save paths
  (`/data/user/<letter>/<id>`) go through `feature/save.lpc`'s
  `assure_file()` (a real simul_efun that `mkdir()`s every missing parent
  directory before saving) — confirmed empirically too: `data/user/q/
  qinhan.o` etc. were created correctly for every test registration.
- **§15s (`tell_room`/`message()` 4th-arg raw-int-0 bug)**: `adm/
  simul_efun/message.lpc`'s `tell_room(mixed ob, string str, object
  *exclude)` declares `exclude` with the correct `object *` array type
  (not a bare untyped/int parameter), so an omitted 3rd arg resolves to a
  typed-array nil rather than a raw literal `0` the way the buggy
  yueyingqiyuan-family wrapper did. No "Bad argument 4 to message()" ever
  appeared in `debug.log` across 4 full test sessions (including a live
  room, NPCs greeting the player, and heartbeats firing).
- **§15u (dormant phone-home/license-check destructor)**: grepped
  `securityd.lpc`/`master.lpc`/all of `adm/daemons/` for
  `shutdown(`/`rmdir("/"`/`rm("/")`-shaped destructive patterns gated on
  an opaque check — only hit was `profiled.lpc`'s harmless single-file
  `rm("/PROFILE")` (a legitimate profiling-log reset, not a licensing
  gate).
- **§15x (hardcoded `MUD_PORT` mismatch)**: `include/getconfig.h`'s
  `LOCAL_PORT()` macro is `(int) get_config(__MUD_PORT__)` — reads the
  REAL live driver-assigned port dynamically, not a baked-in constant.
  Confirmed via source read; no port-mismatch connection rejection is
  possible here.

## Registration-flow AND post-login-command transcript/outcome

Read `adm/daemons/logind.lpc`'s full `input_to` callback chain before
scripting the test (per the standing policy) — the actual shape is:
`logon()` → `encoding()` (gb/big5) → `if_login()` (1=enter/2=exit) →
`get_id()` (English id; `"new"` branches to registration) →
`get_new_id()` (new English id, auto-confirms via `confirm_id("Yes",ob)`
with NO separate y/n step) → `get_name()` (Chinese name) →
`get_super_password()` → `confirm_super_password()` → `new_password()` →
`confirm_password()` → `get_email()` → `make_body()` + `get_gender()`
(m/f) → `confirm_gift()` → `enter_world()`. **Not documented in
logind.lpc itself, discovered live**: `enter_world()` drops the new
player into a SEPARATE gift/stat-allocation UI (体格/根骨/悟性/灵性,
choose `[0-3]` to re-roll one stat or `[9]` to accept defaults, followed
by a `y/n` confirmation) before the player is actually free to type
ordinary commands — my first test run sent `look`/`score`/`quit` right
after gender and they were silently absorbed as no-op answers to this
stat menu (each producing the same re-prompt) since none matched `0-3`/
`9`/`y`/`n`. Second attempt inserted `9` + `y` before the post-login
commands and worked correctly.

Full successful transcript (one continuous `mudclient.py` connection,
`--send "gb" "1" "new" "qinhan" "秦汉" "Abc123456" "Abc123456" "Xyz65432"
"Xyz65432" "qinhan@test.com" "m" "9" "y" "look" "score" "quit"`):

- `gb` → GB encoding selected, full banner/MOTD shown.
- `1` → enters the id-collection flow, shows site-list text.
- `new` → "请您给自己取一个英文名字：" (give yourself an English name).
- `qinhan` → accepted as a new English id.
- `秦汉` (real Chinese name, 2 characters) → **accepted**, moved straight
  to the admin-password prompt (confirms §15h's fix works end-to-end, not
  just in isolation). One pre-existing cosmetic bug noted here: right
  after acceptance, `get_name()` still has an original debug leftover
  `printf("%O\n", ob);` ("by canoe for suppwd") that echoes the raw object
  reference (`/obj/login#0`, `/obj/login#6`, ...) to the connecting
  client — harmless (doesn't block anything) but ugly; left as-is per
  breadth-over-depth, noted here for whoever revisits this lib.
- `Abc123456` (×2) → accepted as the admin/"super" password (needs both
  upper+lowercase letters plus at least one digit/symbol, >6 chars).
- `Xyz65432` (×2) → accepted as the everyday login password (≥6 chars,
  differs from the super password).
- `qinhan@test.com` → accepted as email (needs an `@` and a `.`).
- `m` → male gender selected.
- `9` then `y` → accepted the default gift/stat allocation.
- **Reached the actual game world**: start room `南城客栈` (South-City
  Inn) with full room description, exits (`west/east/up/north/south`),
  board, and 4 real NPCs listed (新手指导/Newbie npc, 店小二, 邮差千里眼,
  唐三藏, 环境判官) — one NPC (新手指导) proactively greeted the new
  player with a welcome tell.
- `score` → produced a full, correctly-formatted character sheet (仙衔,
  称职, 年龄/生日/性别/体重/婚姻/师承, all 4 base stats at their gifted
  values, health/food/water bars, PK/quest/realm-progress fields) — real,
  live data, not a stub.
- `quit` → produced the expected graceful "you feel tired and decide to
  leave" flavor text and closed the session cleanly.

A second, earlier full run (before the stat-menu discovery) with a
different id/name (`qinfeng`/`秦风`) reached the same point end-to-end too
(confirmed via the transcript, just without the follow-up `look`/`score`
verification since those sends were absorbed by the then-undiscovered
stat menu) — kept as corroborating evidence, not the primary transcript.
A third attempt using a digit-containing id (`qinfeng2`) correctly
demonstrated `check_legal_id`'s letters-only enforcement rejecting it
repeatedly ("对不起，你的英文名字只能用英文字母。") — confirms the
English-id validation path also works as intended, not just the Chinese-
name path.

`debug.log` across all 4 connections combined (from a fresh boot):
**zero** `error`/`denied`/`crash`/`segmentation`/`undefined`-type lines —
only the expected compile-time warnings already listed above (unused
locals, unknown `#pragma`, one unknown escape sequence, one arity-mismatch
warning on `convertd.lpc`'s `add()`, none fatal).

## lpcc sweep

14,643 files (`.lpc` count after the uppercase-`.C` rename), well under
the mega-lib bracket but on the larger side (comparable to xiakexing100).
Watched `free -h` throughout — the `lpcc --batch` process peaked around
2.7GB RSS with 16GB+ still available system-wide (23GB host), finished in
well under 2 minutes; no concerning memory pressure despite other agents'
concurrent conversions/boots running at the same time.

**Result: 14,150 / 14,643 pass (96.63%)**, 493 failures. Triaged by
category rather than fixing every one:
- **366 of 493 (74%)** are under personal wizard directories (`u/...`) —
  the standard "test/backup content, not part of the real reachable game
  world" noise seen on nearly every lib in this project.
- **3 more** are under `p/residence/...` (individual players' personal
  house instances) — same category, a runtime "Bad argument to
  set_living_name()" on an NPC clone whose `id` is set by a caller that
  only exists in the real game's create-order, not in an isolated `lpcc`
  single-object load.
- **~10** are the `adm/daemons/network/*` intermud/DNS subsystem (missing
  `config.h`, an old-driver-only `member_group` efun) — never preloaded,
  not reachable from registration; same category as the DNS-daemon
  exclusions documented in §15p/§15ab elsewhere in this project.
- **2** are `adm/simul_efun/object.lpc`/`oo.lpc`'s `efun::destruct(ob)` —
  a known §6b/§14 "fragment file valid when `#include`d into the real
  `simul_efun.lpc`, invalid when `lpcc` compiles it as a standalone
  top-level object" artifact; confirmed via the real boot's clean
  `simul_efun` load (only one unrelated unused-variable warning there).
- **The remaining ~110** are a genuine long tail of small, independent,
  pre-existing content gaps scattered across many different unrelated
  zones/NPCs/items — no single shared root cause dominates (checked: the
  largest cluster is 12 files all failing on one missing macro,
  `inherit S_WEAPON;`, for a self-contained "stone monster weapon" NPC
  subsystem under `clone/m_weapon/`, never referenced outside that
  subtree). Smaller clusters: `inherit SKI_ZHEN` (4 files), `inherit
  DAEMON` (4 files), plus a long list of one-off missing headers
  (`uid.h`, `ANSI.h`, `valid_kill.h`, `star.h`, `priv.h`, `mailer.h`,
  `daemons.h`, `banned.h`, `7hai.h`, `12gong.h`) and missing base classes/
  inherited files (`/u/wiz/super_npc`, referenced by a couple of `death/`
  zone NPCs). None of these are preloaded, none are reachable from the
  registration flow, and none share one obvious common fix — treated per
  AGENTS.md §13 as genuine archive content gaps, not something to
  fabricate fixes for, consistent with the project's breadth-over-depth
  policy on a 14k-file lib.

## Port

**40071**, per `TODO.md`'s "next free port" note. Driver launched via
`setsid nohup ... & disown` from `libs/zitengzhan/` (own session, `log/`
created first); killed by exact PID after testing, never a pattern-based
`pkill` (other agents had concurrent drivers running for
`bmxkx2001`, `zjdyaryl`, and
`zjdyzj` at the same time on this host).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (14,643 total,
  14,413 written, 175 unchanged, 55 self-checked errors left untouched
  as expected on legacy code).
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`): clean boot, zero errors of
  any kind in `debug.log` (not even the usual benign `socket_bind`
  line). Full registration flow re-verified end-to-end with a fresh id
  and real Chinese name (`ztztest`/秦汉试): GB encoding, `1` → id flow,
  `new` → English id, admin ("super") password ×2, everyday password
  ×2, email, gender, gift-allocation menu (`9`/`y`), landed in 南城客栈
  with the standard 4-NPC welcome; `look` (room re-render), `score`
  (full real character sheet, not a stub), `quit` (clean "沧茫"-themed
  farewell text) all correct.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly. **Blocked by the documented `query_ip_number()`
  WASM-mode limitation, textbook example**: `adm/daemons/band.lpc`'s
  `is_strict_banned(site)` does `ip_now_list = explode(site, ".")` then
  indexes `ip_now_list[1..3]` assuming a real 4-octet dotted-quad; under
  WASM `query_ip_number()` returns an empty string, so `explode("", ".")`
  yields a single-element `({ "" })` array and the very first
  `ip_now_list[1]` access throws `*Array index out of bounds.`,
  uncaught, and `new_conn_handler()` disconnects the connection at the
  very first `logon()` call — before the encoding/id prompt ever
  appears. This is exactly the driver-side WASM limitation the task
  brief anticipated (a site-restriction daemon `sscanf`/`explode`-parsing
  the IP format) — confirmed NOT a mudlib bug (native works perfectly,
  see above) and NOT patched, per standing instruction.
  (Superseded — now patched in the 2026-07 WASM-enablement pass below.)

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper (loopback /
  empty / malformed IP ⇒ local) short-circuits `is_banned()`,
  `create_char_banned()`, and `is_strict_banned()` — the last one was
  THE WASM login blocker (its `explode(site, ".")[j]` range parsing
  throws `Array index out of bounds` on the empty/garbage WASM IP).
- `adm/daemons/logind.lpc` `logon()`:
  - `logon_cnt > 50` per-IP concurrent-connection cap — loopback exempt.
  - the no-`query_ip_name` destruct and the IP-must-be-digits-and-dots
    scan — skipped for loopback/malformed IPs.
  - the `#ifdef MAX_LOGIN` per-IP multi-login cap in `get_id()` —
    loopback exempt.
- The 30s relogin throttle is already commented out upstream; no
  `uptime()` startup gate exists — nothing else to bypass.
- `securityd.lpc`'s `match_wiz_site()` has NO callers in this lib (dead
  code) — left unpatched.
- Admin seeded: `fluffos` / 浮浮, rank `(admin)` ("总管巫师") via
  `adm/etc/wizlist`. THREE passwords in this lineage for a wizard
  account, all must differ pairwise where noted:
  管理密码 (super/recovery) `Admin@2026`, 登陆密码 (daily login)
  `Mud@2026`, and a 巫师专用密码 (wizard-only password, prompted and
  set on first wizard login, must differ from the login password)
  `Wiz@2026`. Verified: 您的系统权限目前是：总管巫师(admin),
  `update /d/city/kezhan.lpc` → 成功.
- Retest: fresh normal registration (`regtest`/秦风测) end-to-end into
  南城客栈 with look/score (full character sheet)/quit correct; test
  saves removed. debug.log clean (no new errors).

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: completely clean, zero grep
hits beyond the known-benign early `Unable to open log file:
"log/debug.log"` line — no new findings. Proactively fixed
`adm/simul_efun/object.lpc`'s `file_owner()` (`return name` → `return
dir`) as part of a repo-wide port of a bug found live on sibling
`zhonghua2` (misattributes 3-level-deep `/u/<wiz>/<subdir>/<file>`
log_error writes to a bogus path); didn't fire in this lib's own sit,
fixed proactively since it's the identical shared file. Retest: fresh
registration (id `sanbztz`/秦峰) through look/score/quit, clean.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：完整的管理员登录流程（GB/BIG5 选择→一个"①进入(Enter) ②退出(Exit)"闸门，需要输入字面数字 '1'，而不是直接回车→id+登录密码→第三道密码提示，这份档案自己独有的"巫师专用密码"，按其自己 README 的说法，和登录密码、管理员/找回密码都不一样）能够干净完成：'您的系统权限目前是：总管巫师(admin)'，quit 正常。
