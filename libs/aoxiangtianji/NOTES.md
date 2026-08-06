# aoxiangtianji — 翱翔天际 (a Xiyouji/"Journey to the West"-lineage codebase,
## fluffos2019-era config)

Archive: `翱翔天际utf8.7z`. Port: **40101**. Status: **done** (boots clean,
full registration flow verified end-to-end with a real Chinese name,
admin account verified in both native and WASM modes).

## Encoding verdict (per dispatch note: verify, don't assume from filename)

The archive's filename claims "utf8", and this is **confirmed true** —
this is the one archive in this batch that did NOT need any BIG5/GBK
conversion pass. `raw/axtj2019/config.cfg`: `file(1)` reports "Unicode
text, UTF-8 text" outright, and the whole raw tree (10876 files) was
already UTF-8 when extracted — a prior session (this lib's
`libs/aoxiangtianji/{raw,work}/` already existed with the `.c`→`.lpc`
rename done and 9446 real `.lpc` files, but `config.fluffos`/`NOTES.md`/
`README.md` were never written) had evidently already done the mechanical
`convert_lib.sh`-style pass and found nothing to convert. This session
independently re-confirmed the UTF-8 verdict by spot-decoding
`config.cfg`'s `name : 翱翔天际` line directly and by the fact that the
`lpcc` sweep (below) shows essentially zero encoding-shaped failures.
**No BIG5 trail-byte-doubling issue applies to this archive at all** —
that bug (see `libs/niaoren/NOTES.md` for the full writeup) is specific
to BIG5's 0x5C trail byte; a UTF-8-native archive was never at risk of it
in the first place.

## What this is

Root: `raw/axtj2019/` (one level). `config.cfg` is a modern
fluffos-2019-style config (the archive's own header says "MudOS v21" but
also literally comments "fluffos v2019 运行时配置文件" and defines
`external_port_1 : telnet 6666` / `external_port_3 : websocket 8888`
rather than the older single `port number` line — this project's
convention is to collapse that to a single `port number` in
`config.fluffos`, which is what's done here). `master file : /adm/obj/
master`, `simulated efun file : /adm/obj/simul_efun`, `mudlib directory :
.` (relative in the original, absolute in ours).

The mudlib is clearly a customized fork of a much older "西游记"
(Journey to the West) codebase: the login banner, several system
messages, and even the ASCII-art logo's ALT text still literally say
"西游记"/`Welcome to Xi You Ji!` in multiple places (`adm/daemons/
logind.lpc`), while the actual configured name, in-game banners, and the
vertically-read ASCII logo (翱／擎, 翔／日, 之／挽, 天／挽, 际／月 — reads
"翱翔天际" down the left column) are all genuinely 翱翔天际-branded. This
is cosmetic legacy from whoever rebranded the old Xiyouji base into this
new game and didn't update every string — left as-is (harmless, not
gameplay-breaking, and correcting decades of one author's in-jokes/
half-renames is out of scope here).

Large archive: 10876 raw files, 9446 real LPC (`.c`→`.lpc`, already done
before this session) source files. No bundled driver binary/mega-lib
concerns.

## Fixes applied this session

### 1. `.c`→`.lpc` rename fallout: string-slice extension-stripping bugs
(a new variant of AGENTS.md §2's ".c"-length-assumption family — this
project's catalog documents the `sscanf`-based version of this bug;
this is the first **slice-arithmetic** version seen)

`adm/daemons/eventd.lpc`'s `create()` does:
```lpc
event_name = get_dir(EVENT_DIR + "*.lpc");
event_name = map_array(event_name, (: $1[0..<3] :));
```
`x[0..<3]` in LPC means "every character except the last 3". This was
written back when the archive's real extension was `.c` (2 characters):
for `"emei.c"` (6 chars), `[0..<3]` keeps indices `0..3` = `"emei"` —
correctly strips a 2-char extension. After this project's mechanical
`.c`→`.lpc` rename, the same slice against `"emei.lpc"` (8 chars) keeps
indices `0..5` = `"emei.l"` — a **stray trailing "l"**, not the bare name.
Confirmed exactly this symptom at boot: `Preloading : /adm/daemons/
eventd] -> Error *call_other() couldn't find object '/adm/daemons/event/
emei.l'.` (the file `emei.lpc` genuinely exists; the constructed lookup
path was simply wrong). Fixed by changing `<3` to `<5` (strip 4 chars,
matching `.lpc`'s actual length) with a comment explaining why. The
identical bug, same fix, was also present in `adm/daemons/storyd.lpc`
(same `get_dir(STORY_DIR+"*.lpc")` + `map_array($1[0..<3])` shape — this
one didn't throw a boot-time error since nothing preload-triggers a
lookup-by-stripped-name before a player interacts with the story system,
but would have silently broken every story-by-name lookup) and in
`cmds/wiz/update.lpc`'s backup-file-naming logic (`new_name=
file[0..<3]+uptime()+".lpc"` — cosmetic-only impact, produces a working
but oddly-named backup file like `foo.l172023.lpc` instead of
`foo172023.lpc`; fixed anyway since it's the same one-line change).
**Worth checking any other lib in this fluffos2019/xiyouji lineage for
the same `[0..<3]` shape** — grep `\[0\.\.<3\]` and check whether it's
adjacent to a `get_dir(...*.lpc)` or `.lpc` string-building context (a
few unrelated `[0..<3]` uses elsewhere in the tree are legitimate
independent slices, not this bug — verified each hit individually rather
than blind-replacing).

### 2. Stray debug `printf("%O\n", ob)` leaking to the connecting player

`adm/daemons/logind.lpc`'s `get_name()` (Chinese-name registration step)
had a leftover `printf("%O\n", ob);` immediately before `ob->set("name",
arg)` — this is a raw LPC object-reference dump (driver's `%O`
formatter), and since `logind.lpc`'s `write`/`printf` calls all target
the connecting (still-registering) player, EVERY new registration was
shown a line like `/obj/user/login#3 ("0(axtjqin)")` in the middle of
the "your name has been set to..." confirmation — clearly leftover
debugging output from whoever last touched this function, not intended
player-facing text. Removed the one line; re-verified registration is
now clean (no more object-reference leak) with a fresh account.

## Confirmed NOT applicable / no action needed

- **§4-style `load_object(SECURITY_D)` recursion**: `master.lpc`'s
  `valid_read`/`valid_write` don't lazily `load_object` a security daemon
  at all in this lineage (`securityd.lpc` is a normal preloaded daemon,
  referenced only via the already-loaded `SECURITY_D` define) — not
  applicable.
- **Hardcoded `MUD_PORT`-style `connect()` dispatch**: `master.lpc`'s
  `connect()` (grepped) has no literal-port `switch`/`if` gating the
  connection — this codebase's own `external_port_N` config style +
  single `port number` override in `config.fluffos` was already enough;
  first-connection tests worked immediately with no silent-reject
  symptom.
- **`uptime()` startup gate**: none found (grepped `master.lpc` and
  `logind.lpc`); the only startup-adjacent gate is `REBOOT_CMD->
  is_rebooting()`, a manually-toggled wizard shutdown-countdown flag, not
  a `uptime()`-based grace period.
- **BIG5 mixed-encoding config gotcha** (huoying-style): not applicable,
  archive is genuinely all-UTF-8 (see above).

## `lpcc` sweep

`scripts/lpcc_check.sh libs/aoxiangtianji/config.fluffos libs/aoxiangtianji/work`:
**9439/9446 pass (99.93%)** even before this session's fixes (the eventd/
storyd bugs above are `create()`-time runtime issues, not compile
failures, so they didn't show up in the lpcc count either way). The
remaining 7 failures are ALL "Fail to load object" with no compile error
text — sampled and confirmed these are abstract templates never meant to
be `load_object()`'d bare (only `clone_object()`'d with caller-supplied
state): `std/phome/phome_{one,two,three,four}` (player-home templates,
cloned by `adm/daemons/playerhomed.lpc` with a `master_name` property
pre-set before `create()`'s `restore()` call ever runs), `obj/self/
animal`, `adm/daemons/story/{pangtong,mengzi}` (story-daemon-driven
NPCs). None of these are real bugs; the generic lpcc harness simply has
no way to supply the context these files require.

## Registration flow (read from `adm/daemons/logind.lpc`'s actual
`input_to` chain — notably different shape from other libs in this
project)

`logon`→`encoding` (GBK/utf-8 choice, pick `utf-8`)→`get_id` (type `new`
for a new character)→`get_new_id` (English id, 3-8 **pure letters, no
digits**)→`confirm_id` (auto, no y/n)→`get_name` (Chinese name, 2-4
chars)→`new_ad_password`/`confirm_ad_password` (a **separate "management
password"**, ≥5 chars)→`new_password`/`confirm_password` (the **regular
login password**, ≥5 chars, must differ from the management password)→
`get_gift` (accept the random stat roll, y/n)→`get_QQ` (a QQ number,
4-13 digits — required, not skippable)→`get_email`→`get_gender`(m/f)→
`selete_char` (pick a "personality", 1-4)→world entry. This lib requires
BOTH a management password and a regular password up front (unlike
`niaoren`/`huoying`'s single-password flow) — worth checking per-lib
rather than assuming a fixed shape.

**Existing (i.e. already-registered) wizard accounts have an ADDITIONAL
gate**: on reconnect, after the regular password, if `password_w` (the
separate "wizard-only password") isn't set yet, the game forces setting
one immediately (`new_passwd_w`/`confirm_pass_w`) — must be ≥6 chars,
contain at least one uppercase AND one lowercase letter, and must not
equal the id, the Chinese name, or the regular password. Once set, every
future wizard login asks for it (`get_passwd_wiz`) as a second factor
after the regular password.

## Boot + registration-flow verification (native)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/aoxiangtianji/`. Clean boot, only cosmetic warnings, `Accepting
telnet connections on 0.0.0.0:40101.` / `Initializations complete.`.

Full transcript (`scripts/mudclient.py`), fresh id `axtjqin`, real Chinese
name **秦风**:
```
--send ""                    # banner
--send "utf-8"                # encoding choice
--send "new"                   # new character
--send "axtjqin"                # English id
--send "秦风"                    # REAL Chinese name (2 chars)
--send "adminpass123"             # management password
--send "adminpass123"              # confirm
--send "test12345"                  # regular password
--send "test12345"                   # confirm
--send "y"                             # accept stat roll
--send "123456"                         # QQ number
--send "test1@test.com"                  # email
--send "m"                                # gender
--send "1"                                 # personality (光明磊落)
--send "look" / "score" / "quit" / "y"      # (quit on a <30min-old
                                              # account asks to confirm
                                              # deletion -- game's own
                                              # policy, not a bug)
```
Result: name "秦风" accepted with zero rejection, entered the world at
"南城客栈" (South-city Inn) with full scene/NPC/board text; `score`
showed the correct bracket-quoted title (`【 少 年 】`) and a complete,
correctly-rendered Traditional-charset-free Simplified Chinese character
sheet (attributes, combat stats, sect/alliance fields, PK record, etc.);
`quit` on the fresh (<30-min-old) account triggered the game's own
"delete this new account?" confirmation, answered `y`, account cleanly
removed. A second run with a 3-character name (王小虎, gender f,
personality 2) also registered without any name-rejection (save file
`data/user/w/wangxh.o` confirmed created) — deleted after testing since
it was just a throwaway verification account.

## Admin account

id `fluffos`, regular login password **`Mud@2026`** (used for the actual
per-task-spec admin credential), Chinese name 浮浮, management password
`AdmMud2026x`, wizard-only password `WizMud2026!` (this lib's own extra
security layer — see "Registration flow" above; not part of the task's
single-password spec, but required by this codebase's own design to
reach a working wizard session, so documented here for whoever logs in
next). Granted `(admin)` via `adm/etc/wizlist` (plain-text, one line per
wizard: appended `fluffos (admin)` next to the archive's original
`jinning (admin)`) — **note**: `securityd.lpc` caches `wizlist` in memory
at daemon preload time (`create()`), so an edit to the wizlist file only
takes effect on the NEXT driver boot, not immediately (a distinct gotcha
from AGENTS.md's already-cataloged patterns — worth adding to the
general checklist: any `wiz_status`/permission table read once in
`create()` and cached needs a reboot, not just a file edit, before a
grant/revoke is visible). Save files (must be committed — gitignored by
default): `work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

Verified via the real flow after a fresh reboot: login as `fluffos` /
`Mud@2026` → prompted for (and, first time, required to set) the wizard
password → `目前权限：主管天神(admin)` shown; ran the actual wizard
commands `update /adm/daemons/rankd` and `update /adm/daemons/band` →
both `→ 文件顺利更新成功！` (recompiled successfully); `wizlist` command
shows both `fluffos` and `jinning` as `『 主管天神 』` (admin-tier).

## WASM-enablement pass (fail-closed loopback gates)

Found and patched THREE distinct IP/site gates, none previously
loopback-aware (this lib had no prior loopback pass — unlike `niaoren`,
this archive's `config.fluffos`/pipeline work never got to this step
before this session):

- **`adm/daemons/band.lpc`'s `is_banned()`/`create_char_banned()`/
  `is_strict_banned()`** — added a shared `is_loopback_site()` helper
  (loopback ⇒ exactly `127.0.0.1`/`::1`/`localhost`/a `127.` prefix;
  anything else, including unparseable input, still goes through the
  real ban-list regexp check — fail-closed from the start, matching the
  corrected project-wide pattern, not the now-retired "malformed IP =
  trust it" shape).
- **`adm/daemons/logind.lpc`'s `logon()` same-IP concurrent-connection
  cap** (`logon_cnt > 8` → reject) — added a loopback exemption
  (`query_ip_number(ob) != "127.0.0.1" && != "::1"`) so repeated local/
  WASM test connections can never trip it.
- **NOT patched, and confirmed why it doesn't need to be**: the 100-slot
  `MAX_LOGIN`/`allow_multi_login()` per-IP cap (`include/login.h`) is
  already high enough (100) that it can't practically block any of this
  project's local/automated testing; left as the archive's own default
  rather than special-casing a gate that was never going to fire.
- **NOT an IP gate, so not touched**: the 120-second post-quit
  reconnect cooldown (`logind.lpc` `get_passwd()`, `time()-user->query(
  "last_on") < 120`) is keyed on the ACCOUNT, not the connecting IP —
  it throttles the same character reconnecting too fast regardless of
  origin, so a loopback exemption would change actual game balance/
  anti-abuse behavior rather than just unblocking local testing. Left as
  designed; testing simply waited it out / used fresh accounts.
- No `uptime()` startup gate exists (see above).
- No per-IP registration-count throttle (the `huoying`-style "创造的人物
  太多" pattern) exists in this lib.

Recompiled both changed daemons live via `update` and reverified: loop
back reconnect still succeeds without hitting either patched gate.

## WASM verification (`scripts/wasm_client.js` against `build-wasm/src`)

**Important scripting note for future testers of this specific
registration flow**: the WASM harness boots a fresh, ephemeral in-memory
driver instance per invocation (copying the HOST's `work/` at boot, not
persisting writes back) — a full registration AND its subsequent login/
look/score/quit verification must happen in ONE single `wasm_client.js`
invocation's `--send` list, not two separate invocations (a save made in
one process's memory is invisible to the next). Learned this the hard
way on the first attempt (a `wasmqin` registration that looked like it
completed, followed by a separate `--send` list to reconnect and test
`look`/`score`, failed with "没有这个玩家" — no such player — because the
second invocation was a brand-new ephemeral instance that never saw the
first one's in-memory-only save).

Single-invocation full flow (id `wasmqf`, real Chinese name **秦风**):
registration (same field order as native above) → entered 南城客栈 →
`look` showed the room correctly → `score` showed the correct `【 少 年
】` bracket-quoted title and full character sheet → `quit` on the fresh
account triggered the same new-account-deletion confirmation as native,
confirmed `y`. Separately, WASM admin login (`fluffos`/`Mud@2026` +
wizard password) showed `目前权限：主管天神(admin)`, and `wizlist` showed
both admin accounts correctly.

**Verdict: native OK + WASM OK.**

## Process/cleanup notes

- Killed this session's own driver processes by exact PID (verified via
  `/proc/<pid>/cwd` pointing at this lib's `work/`) before every restart;
  never touched any other lib's driver process running concurrently on
  this shared host.
- Deleted the two throwaway test characters' save files created during
  this session's native testing (`wangxh` — `axtjqin` self-deleted via
  the game's own new-account-quit policy, no manual cleanup needed for
  that one). The `fluffos` admin account's saves ARE kept/committed.

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到浅层冒烟测试。本轮启动前先主动排查了本次会话已经
反复确认过的四类高价值 bug 模式（`private command_hook`、
`logind.lpc` 里未加保护的 `MESSAGE_D->` 呼叫、`stat/water` 对
`stat/drink` 键名不一致、`printf("%O", ob)` 调试信息泄漏），全部
未命中——这份档案这一轮没有发现新的编程 bug，是一次干净的复核。

### 完整验证：从注册到探索

用全新账号在原生驱动上完整走通：GBK/utf-8 编码选择 → `new` → 英文
id（3-8 个英文字母）→ 中文名字（二到四个字，重名会被拒绝并要求重
新输入）→ 管理密码 + 确认 → 普通密码 + 确认 → 天赋摇点（y/n 确认）
→ QQ 号码 → 电子邮件地址 → 性别 → 四种天性择一（①光明磊落 ②狡黠多
变 ③心狠手辣 ④阴险奸诈）→ 进入"南城客栈"。入口场景带有一幅像素风
格的电脑显示器 ASCII 画和一句"你是不是也象我一样。。。"的感伤台
词，气氛渲染和常见的"侠客上路"开场很不一样。店小二 NPC 主动搭话
（"这位小兄弟，进来歇歇脚，喝两盅吧"），确认 NPC 的 `command()`
自呼叫对话链路工作正常。`score`（个人档案）显示完整信息面板，其中
"关卡信息"一节明确列出"大闹天宫"和"西行取经"两条主线关卡进度（均
显示"你尚未开始/你尚未西行"），"道行境界/武学境界/法力修为/内力修
为"四项境界评价，和 README 已经记载的"保留了呼应《西游记》原始题
材的关卡系统"完全吻合。`i`（背包）显示起始装备（皮靴、短打劲装）。

### 已确认属于设计、不是 bug 的观察（复核既有记录）

`quit` 在新账号未连续在线满 30 分钟时会触发确认提示——"你的账号是
新建的...退出游戏将删除你的账号...你确定要放弃该帐号而退出吗？
(y/n)"，确认后干净完成删除（"您选择了放弃账号退出西游记，档案被删
除。。。。。。"），没有崩溃或残留错误。这是这份档案自己的防止小号
滥用设计，NOTES.md 更早的记录里已经提到过，本轮只是重新验证了一遍
该流程本身在这个驱动上运行正常、不会崩溃。debug.log 除了驱动启动
期噪音外没有来自本次实际游玩会话的运行时错误。

### 未覆盖范围（诚实说明）

预算集中在验证注册全流程、天性选择、以及关卡系统的存在与显示，没
有走到：拜师、战斗、门派/联盟系统的实际互动。这些留给下一轮，目前
的验证边界如上所述。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 24 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
