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

## 深度功能测试（§10.7，本轮）：注册之外，全程未发现新 bug

之前几轮已经把这份档案测得非常彻底了（完整注册流程、lpcc 全量扫描、
WASM 长时间静置观察、几乎所有已归档的 bug class 都逐一排查过），但都
停在"注册成功+look/score/quit 正确"这一层，没有真正玩到移动/商店/战
斗/死亡这些更深的系统。这次专门补上这一段。

用之前已注册好的账号（`qindeep`/秦深）登录，走了：`look` 确认起始房
间"南城客栈"→ `west` 到"朱雀大街"→ 再 `west` 到"董记当铺"，`list`
正确显示"当铺目前没有任何货物可卖"（新档案确实没人当过东西，不是
bug）→ 回到朱雀大街，找到一个游荡 NPC"疥顶小僧"，`kill` 触发了一场
完整的战斗（招式描述丰富多样、命中/闪避判定、血条/精神条正确刷新）
→ 角色被打死，正确触发死亡流程：进入"阴阳界"，NPC"朱笔判官 崔珏"自
动（不需要玩家任何操作）念白+翻生死簿+还阳，把角色送到复活点"荒郊
小店"，全程没有任何卡死或者需要 present()/环境判断重试的迹象（不是
§7.68 那种多阶段 death_stage() 架构，这个是单一 NPC 自主对话驱动的复
活流程）→ 复活后 `score` 确认状态合理（属性 20/20/25/25 保持不变，
气血显示"重伤"、综合评价从 1 涨到 90，符合刚经历一场战斗和死亡的预
期）→ 试了留言板，`read board`/`read board 1` 都收到"你要读第几张留
言？"提示（这是 notify_fail 提示，不是等待后续输入的交互式问题——
`read 1`（不带 board）才是正确指令格式），成功读出一条 2011 年的旧留
言，格式正常。

**全程 `debug.log` 保持完全空白，没有发现任何新 bug**——这是本项目里
少数几个真正做到"越玩越深、依然找不出问题"的档案，大概率是因为之前
几轮 WASM 修复阶段已经把大部分已知 bug class 都排查并处理过了（见上
文各节），这次的移动/商店/战斗/死亡复活/留言板测试没有找出任何遗漏。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 43 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round 2 (2026-08-15, post driver-upgrade re-test)

Round-two re-verification against the current native `build-debug` driver
(post-upgrade — pulls in PRs #1343/#1344 and the corpus-wide `%`-operator
float-crash fix). Standard checklist + live playthrough-style verification.

Findings:

1. **AGENTS.md §7.108** (`obj/user.lpc`'s `reconnect()` missing
   `enable_commands()`): confirmed active `LOGIN_D` (`adm/daemons/logind.lpc`)
   calls `user->reconnect()` on the character body after `exec(old_link,
   user)`. Fixed by adding `enable_commands();` as the first statement.
   Live-verified with two concurrent telnet sessions using this lib's
   three-password wizard flow (login password `Mud@2026` then
   wizard-only password `Wiz@2026`): session 2 confirmed the "赶出去，
   取而代之吗？(y/n)" prompt with `y`, and the resulting session correctly
   dispatched `look` (real room description) and `score` (real stat
   panel). (An identically-shaped dead `obj/user2.lpc` — not referenced
   anywhere outside the archive's `u/` stray-account tree, confirmed via
   `include/globals.h`'s `USER_OB` define pointing only at `obj/user` —
   was left untouched.)
2. **AGENTS.md §7.106** (`present(file, environment(me))` missing the
   `environment(me) &&` guard): this lib ships FOUR separate `update.lpc`
   copies under different `cmds/<rank>/` directories. `cmds/imm/update.lpc`
   and `cmds/wiz/update.lpc` already had the guard; `cmds/eld/update.lpc`
   and `cmds/arch/UPDATE.lpc` did not — fixed both.
3. **`adm/simul_efun/file.lpc`**: `log_file()` never called `assure_file()`
   before `write_file()`; added the call (plus a forward declaration).
   `cat()`'s `write(read_file(file))` had no null-guard; changed to
   `write(read_file(file) || "")`.
4. **`config.fluffos`**: `maximum evaluation cost` was `500000`, well
   below this project's standard safe value; raised to `5000000`.
5. **Already correct, no change needed**: `adm/obj/master.lpc`'s
   `log_error()` already uses the case-agnostic `"arning:"` filter
   (AGENTS.md §7.10). No `adm/daemons/closed.lpc` exists, so AGENTS.md
   §7.107 does not apply.

Live verification summary: booted the native driver on port 40071 (clean
boot, only pre-existing unused-variable warnings, no fatals;
`Initializations complete` / `Accepting telnet connections` both printed).
Logged in as the seeded `fluffos` admin through this lib's three-password
flow (`Mud@2026` then `Wiz@2026`), confirmed real write access via `update
/adm/simul_efun/file` (recompiled successfully — the very first `update`
attempt was silently absorbed by the post-login news pager/gift-menu
sequence, a known pattern on this project; resending it at the settled
prompt worked). Noted the "请选择你想重新设置哪一项天赋" gift-reroll
prompt shown on every wizard login is a genuine pre-existing
`d/wiz/init.lpc` feature shared across this lineage (confirmed via a
corpus grep hitting several unrelated sibling libs), not a bug — answered
`9`/`y` to keep the current values, matching normal play. Ran the
two-session kick-duplicate-login reconnect test described above and
confirmed the §7.108 fix live. No fatal errors in the driver's console
output. Killed the driver by exact PID when done.

本轮修改的文件 / Files modified this round:
- `libs/zitengzhan/work/obj/user.lpc`
- `libs/zitengzhan/work/cmds/eld/update.lpc`
- `libs/zitengzhan/work/cmds/arch/UPDATE.lpc`
- `libs/zitengzhan/work/adm/simul_efun/file.lpc`
- `libs/zitengzhan/config.fluffos`

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the `hy5`/`hymud`/... batch-1-6 sweep (ES II
lineage, `ROOM` macro from `include/globals.h`). Deleted 2,445 live
standalone `replace_program(ROOM);` lines from `.lpc` files under
`work/` via `fix_710_room.py`, plus hand-fixed both room-building
tool copies' string-builder template
(`work/clone/misc/roommaker.lpc`, `work/obj/roommaker.lpc`:
`str += "\n\tsetup();\n\treplace_program(ROOM);\n}\n";` →
`str += "\n\tsetup();\n}\n";`). No `work/data/` false-negative source
files found. All remaining `replace_program(ROOM)` matches in `work/`
are pre-existing `//`-commented lines (harmless, left alone).
Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`Mud@2026`/`Wiz@2026`) + `update /d/city/kezhan.lpc` +
`quit`, all successful.

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bgargoyle.lpc`, `d/death/npc/wgargoyle.lpc`, `d/shengdoushi/7hai/nby/npc/haijiangjun.lpc`, `death/npc/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 1 file(s) `inherit F_SSERVER;` and no header defines it (1 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (1 with the terminator glued to the last text line, 2 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`, `u/lying/ic2.lpc`, `u/lying/obj/ip.c.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply zitengzhan`: 3 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 6 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 2 PASS -> 4 PASS, 0 that loaded before fail now, 2 more load.

3 files moved (3 `.lpc`); mostly under `u/tianlin/clone` (2), `u/lying/tonggang` (1). A rescan with `scripts/lpc_warnings.py zitengzhan` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 263 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 4 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 1 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退；`adm/daemons/questd.lpc` 原先加载失败，现在加载成功。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 飞贼的装备路径

`u/lying/feizei/feizei` 和 `u/lying/tonggang/feizei/feizei` 给飞贼带的装备写成 `/u/tianlin/feizei/obj/…`，本库没有这个目录，装备在各自的 `obj/` 下；`carry_object()` 出错会让 `choose_feizei()` 在重新 `call_out` 之前中断。路径改成各自所在目录（与 sjcs、dtxyzjb 同一处代码）。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py zitengzhan --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/dntg/yunlou/npc/yaoguaixdao.lpc` 的 `for (t == 0; ...)` 改成 `=` 等），共改动 1149 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：1105 -> 1105 通过，无回退；改过的头文件的 575 个包含者 501 -> 501 通过。
手工：`daemon/skill/huomo-dao/boyue.lpc` 和 `daemon/class/tianmo/huomo-dao/boyue.lpc`（火魔刀「波月」）的出招描述 `msg = HIC "\n$N默运神功…直劈向$n，\n";` 后面一行"$n只觉刀光如电，竟不知如何躲避了！"被多余的 `;` 截成单独的语句，颜色也没还原；接回去（`scripts/lpc_join_cut_strings.py`）。`adm/daemons/natured.lpc` `event_night()` 里只在注释掉的钟馗段落用的 `badguy`、`room2` 删去（那段注释以 `/*/` 开头，扫描工具没认出来）。
未动：`d/jjf/npc/xiaomotou1.lpc`、`d/npc/vr_room/obj/tai1.lpc`、`daemon/bagua.lpc` 本身有语法错误，HEAD 起就编译不过。

启动时警告 65 -> 0；新进程登录（编码选择、进入游戏菜单）正常。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 175 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 21 个，只在 #if 分支用的声明移进分支 0 个文件；改动 187 个文件，HEAD 与工作树各载入一次无回退（187 objects; HEAD PASS 181, tree PASS 181; regress 0; newly loading 0），这些文件的警告 267 -> 72。

- 2026-10-11：第二轮整理删掉了 `u/lying/d/npc/vr_room/obj/tai1.lpc` 的 `do_get()` 里仍在使用的 `object ob = this_object();`（该文件本来就编译不过，编译器的“未用”报告不可信）；已恢复。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（同码收尾）

- 改动文件：u/yhq/npc/│+_dashi.lpc 
- 与前几批同型：`youming.lpc` 空 `DEBUG` 宏改空函数；`who1.lpc` 孤立的分隔线字符串删去；`jing.lpc` 被分号截断的“惨叫一声，血流如注。”接回上一句；`_dashi.lpc` 三行只造不调的 `(: call_other, __FILE__, "…_name_skill", who :);` 改成注释（行为不变）。
- 载入无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 11 处，3 个覆盖函数的返回类型）后，用 `scripts/lpc_twin_port.py adopt dtxyzjb zitengzhan --pre 6986ce28cd8~1` 搬来孪生库 dtxyzjb 的同类修法（51 个与 dtxyzjb 修前逐 token 相同的文件），再手工补文字不同的几处，能编译的文件警告清零。改动的 64 个对象 HEAD 与工作树各载入一次：HEAD PASS 55，tree PASS 56，regress 0。

- `d/dntg/yunlou/npc/yaoguai.lpc`、`yaoguaixdao.lpc` 及 `u/jznt`、`u/xdao`、`u/lxmas` 的 `yaoguai.lpc`：自己的 `nosave int tick`（出绝招的节拍）与 `std/char.lpc` 的心跳 `tick` 同名，驱动本就给了两个变量；叶子这边改名 `perform_tick`（`lpc_rename_ident.py`），行为不变，`d/city/npc/yg/*`、`d/dntg/yunlou/npc/yg-*`、`quest/renzhi1/quest_killer` 的重复声明随之消失。
- `include/vrm.h`：迷宫表被 `std/room/vrm_server.lpc` 和继承它的 `d/room/vr_room/vrm_*.lpc` 各包含一次；表格包进 `#ifndef VRM_TABLES_INHERITED`，房间在包含前定义它（数值保留本库的 7200/3600 秒）。
- `d/game/give/yuan.lpc`：`int bt = 2;` 连写三次，留一行。
- `d/jjf/npc/xiaomotou1.lpc`（天魔宫小魔头）从来载不进来：`attempt_apprentice` 外面多套了一个同名函数头；拜师广播的字符串里直接换行（LPC 字符串不能跨行）；文件用了 `HIR` 等颜色宏却没 `#include <ansi.h>`。三处都改，现在能载入。
- `u/nanf/room/npc/ddz_judge.lpc`：`die()`/`unconcious()` 在 `void` 基类上写成 `int`，没人读返回值，改为 `void`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。11 个文件 22 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/u/nanf/room/ddz_table.lpc`（`score *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：擂台 `d/leitai/leitai.lpc` 整份不编译：`fullup()` 缺了收尾的 `}`，后面那份重复的 `do_quit()` 被读成 `fullup()` 里的局部声明。补上 `}`，删去那份从未生效的重复 `do_quit()`（前面那份照旧是 add_action 的目标）。现在载入。

- 2026-10-14：3 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：4 个对象，新增载入 2，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

49 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`、`buhui1`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bainiao-jian/feijian`、`bawang-qiang/ba`、`bawang-qiang/bafang`、`bawang-qiang/meihua`、`bawang-qiang/zhuiming`、`bingpo-blade/ansha`、`bingpo-blade/ningxie`、`canxin-jian/jinsheng`、`canxin-jian/xiaoyao`、`dali-bang/mantian`、`dali-bang/shenli`、`dashen-bian/diaoyu` 等 58 个。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`wuxingquan`→`wuxing-quan`（`/daemon/bagua`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`huomo-dao/moguan`、`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

14 个文件、18 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/weapon/sword/xy_sword.lpc`、`/d/obj/weapon/hand/hand.lpc`、`/u/ken/obj/weapon/blade/dongyangdao.lpc`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 9 个，改后 15 个（6 个原来载入不了），没有退步。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/shouxing.lpc`。改后载入：1/1 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 29 个对象设了本库没有文件的武功（50 个名字，最多的是 `zhaoyangbu`、`huxiaoquan`、`huntianforce`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：28 个里 25 个通过，其余 3 个停在别的错误上（`d/game/biao/fan`：*Inherited file '/d/snowtu/npc/super_npc' does not exist!；`quest/renzhi/npc/quest_bandit`：*Bad argument 1 to EFUN call_other()……）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/adm/daemons/vrm_server`←xiyouji2006，6 个对象继承它，抽样 2/6 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 32 处、32 个文件：`lahua-shou`→`lanhua-shou`（20 处）、`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`dragon-step`→`dragonstep`（2 处）、`yange_blade`→`yange-blade`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）、`xuanhu-balde`→`xuanhu-blade`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 4 个：`/daemon/skill/taiji-quan.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill/zhuihun-sword.lpc`、`/daemon/skill_wiz/whip/jueqingbian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/zhanchang/warplace1.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 开封擂台头文件的重复全局变量（2026-10-19，KB 04 §6.10）

`d/kaifeng/ground.h` 里的 `modes`、`mode_hints`、`families` 三张表被 `ground0.lpc` 和继承它的 `ground1/2/3.lpc`、`ground.lpc` 各包含一次，每次 `inherit` 都报 `Redeclaration of global variable`。表只放在 `ground0.lpc` 里：头文件用 `#ifndef GROUND_TABLES_INHERITED` 包住表，继承的几个程序在 `#include "ground.h"` 前 `#define GROUND_TABLES_INHERITED`（与 xiyouji 系其余库同一改法）。`d/kaifeng/npc/colors.h` 也加了防重复包含。改后警告消失，与 HEAD 逐个对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/u/allenc/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

4 个文件、4 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/cmds/std/fly.akuma.lpc`、`/cmds/std/fly.lpc`、`/cmds/std/fly_2.lpc`、`/cmds/std/fly_3.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/yhq/npc/annie.lpc`。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 从 `work/` 里删掉 tar 的 `PaxHeader/` 记录（2026-10-19，KB 02 §2.2）

压缩包的制作者把 tar 的 pax 扩展头记录（`49 path = ...`、`20 ctime = ...`，每个不超过 262 字节）当成文件打进了包里，放在 `PaxHeader/` 目录（有的嵌套两层）。转换时 `.c` 结尾的被改名成 `.lpc`，在扫描里成了编译不过的“物件”。这些是元数据，不是 mudlib 内容：7 个文件从 `work/` 删除（`raw/` 里仍然有）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/liandan/baihuagu.h`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/quest/renzhi/vrm_server.lpc`（1 处）、`/std/room/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 6 处）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/storyd.lpc`（2 处）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`、`/u/xdao/npc.lpc`（共 2 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 6 个存档共 24 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/cmds/usr/quest.c.o`（6 处）、`/d/obj/npc/yao.o`（8 处）、`/d/qujing/lingshan/npc/rulai2/obj/jingshu.o`（2 处）、`/d/ygbz/baokudt.c.o`（4 处）（等共 6 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 4 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（6 个文件，括号里是接住 0 的 efun）：`/cmds/adm/add.lpc`（`sscanf`）、`/cmds/adm/admove.lpc`（`present`）、`/cmds/adm/baiban.lpc`（`sscanf`）、`/cmds/adm/giveu.lpc`（`sscanf`）、`/cmds/adm/query.lpc`（`sscanf`）、`/cmds/wiz/info.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 28 条注册（16 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/duchang5.lpc`（`cloud_goto`、`cloud_update`、`detect`、`int`等）、`/d/city/fangzhang1.lpc`（`do_get`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/leitai/wizroom.lpc`（`do_life`）、`/d/pansi/npc/qingxia.lpc`（`do_yes`）、`/d/qujing/baoxiang/obj/baxianzhu.lpc`（`do_zhengzhi`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`） 等共 16 个文件。最多的函数名：`do_get` 2 处、`do_cost` 2 处、`do_list` 2 处、`do_upgrade` 2 处、`do_push` 2 处。没有动（读过）：`/d/game/biao/biao.lpc` 的 `do_none`（对象本身编译不过，登记留着，等对象能加载再处理）、`/death/npc/heiwuchang.lpc` 的 `doAgree`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/shengdoushi/7hai/shendian/npc/haihuangnpc.lpc` 的 `do_shoot8`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。3 个文件里 3 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 3 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/cmds/std/go.lpc` ← fyzfqyy：`query_chinese_dir()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 4 个函数没有补（inquiry 4）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/bwbj/npc/hsg.lpc`:`say_position`、`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/death/npc/heiwuchang.lpc`:`askLeave`、`/death/npc/yanluowang.lpc`:`ask_cancel`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 1 个文件里有 1 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`/log/nosave/ATTEMP_KILL` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 3 行只含这个指针的行（`"效劳": (: say_position :),` `"cancel": (: ask_cancel :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:101`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：18 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 18 处（9 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 20)) {`（`/cmds/usr/buildlian.lpc:72`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/cmds/usr/buildmen.lpc:72`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。
