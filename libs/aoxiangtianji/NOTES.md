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

## 深度功能测试（第二轮，2026-08-18）——补完战斗，深入排查拜师系统（非 bug 的设计限制），经济系统未定位到

补完上一轮留下的拜师、战斗、经济系统测试。战斗验证成功，拜师系统
深入排查后确认是设计限制（不是 bug），经济系统（真正的 buy/sell 商
店）本轮时间预算内未能定位。

- **战斗验证**：`help newbie/combat-basic` 文档明确安全切磋指令是
  `fight`（非致命）。用巫师账号 `goto`+`summon` 把测试角色带到"朱
  雀街"，对"鬼见愁 钟馗"使用 `fight zhong kui`，触发真实攻防交
  换（命中部位描述、伤害数字、气血百分比），角色落败后自动"认输"
  （`surrender` 机制自动触发，"这场比试算我输了，佩服，佩服！"），
  紧接着仍被打晕（"你的眼前一黑，接著什么也不知道了...."），一段
  真实时间后自动恢复知觉。全程符合 `help combat` 文档描述，
  `debug.log` 全程零报错。
- **拜师系统深入排查**：`bai <NPC>`（`cmds/skill/apprentice.lpc`）
  对 NPC 目标会调用 `ob->attempt_apprentice(me)`。用巫师账号
  `goto`+`summon` 依次尝试了南海普陀山（观音道场）的知客僧、剃度
  僧，两次都被拒绝（"小兄弟非我南海普陀山弟子，贫僧/老衲所教恐怕
  难以理解"）。逐行读了 `attempt_apprentice()` 的完整实现（观音本
  尊 `d/nanhai/npc/guanyin.lpc`、知客僧、剃度僧三份档案的
  `attempt_apprentice()` 函式体完全一致）：先检查
  `family/family_name == "南海普陀山"`（不是就直接回绝这条消
  息），然后检查 `class == "bonze"`，然后
  `level > 32`，然后 `obstacle/number >= 34`（已完成的西游取经关卡
  数）。**这不是一个可以让全新角色直接加入的入门门派**——它的验收
  门槛（32 级以上、完成 34 个以上取经关卡、必须已经是"bonze"职
  业）说明这是一个高等级、任务线深度绑定的终局门派，本轮用的是一
  个全新 1 级角色，从一开始就不是这个门派的合理测试目标，不代表拜
  师系统本身有 bug。`bai.lpc` 自己的指令逻辑（`cmds/skill/
  apprentice.lpc`）读起来是完整、合理的（正确处理 cancel、已是弟
  子、跨门派转投、玩家间不能收徒等边界情况）。
- **经济系统未定位到**：起始客栈本身 `no_fight`/应该也没有 buy/
  sell（该房间没有 `add_action "buy"`）；相邻的"朱雀街"、"南城钱
  庄"都探过——"南城钱庄"是钱庄（票号），NPC "铁公鸡" 没有
  `add_action "buy"`，`list` 返回"什么？"，猜测这里走的是存取款
  （deposit/withdraw）而不是 buy/sell 商品；真正的杂货铺/兵器店本
  轮在附近没有找到，未继续深入城内其他区域寻找。`newbie` 指令（新
  手武器/装备）需要具体物品名参数，本轮未继续深挖。
- 本轮结论：战斗系统验证正常工作，无发现问题。拜师系统的"每次都被
  拒绝"现象经代码走查确认是**设计使然**（南海普陀山是一个高等级终
  局门派，不接受新手），不是 bug——这次没有像 cctx 那样只是"没找到
  地图路径"，而是**找到了、试了、并且确认了拒绝的具体原因**，比单
  纯"留给下一轮"更进一步。真正意义上适合新手加入的门派（如果存
  在）在哪里，以及经济系统的真正商店位置，仍留给下一轮寻找。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 24 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（第三轮，2026-08-18）——真实死亡→断线→重连→复活全流程，发现并修复一例 §7.112 同类 bug

本轮延续第二轮留下的问题（经济系统定位、拜师系统、战斗），重点补上前两轮从未走到的：真实死亡（非 `fight` 切磋）→断线模拟→重连→复活的完整链路，以及留言板、当铺(拍当/卖断)经济系统。开始前先按标准清单核对了本次会话已固化的五类高价值 bug 模式。

### 标准清单核对结果

- **§7.111**（`master.lpc` `standard_trace()` 的 `file_name(error["object"])` 空指针）：`adm/obj/master.lpc` 内两处调用点（行 416、552）**均已带三元判空保护**（`error["object"] ? file_name(...) : "0"` 及 `(undefinedp(...)||!...) ? "(none)" : file_name(...)`），无需再动。
- **§7.112**（gargoyle 血统 `wgargoyle.lpc`/`bgargoyle.lpc`）：本档案没有这两个文件名（`find -iname "*gargoyle*"` 零命中）。但**没有止步于按文件名判断**——按 AGENTS.md §7.112 "标准清单"要求，对全档案 `init()` 内 `call_out()` 做了针对性检查，在 `d/death/npc/pang.lpc`（本档案自己的地府判官 NPC，功能上与 `dtsl` 的 `yanluo.lpc`、其他血统的 `wgargoyle.lpc` 完全等价：五段式 `death_stage()` 引导亡魂复活）中找到了**本档案自己的、未被任何已有 sweep 命中过的真实实例**，详见下方"发现并修复"。
- **§7.113**（netdead 重连不恢复 heart_beat）：读代码 + 实测双重确认**不存在**。`adm/daemons/logind.lpc` 的 `logon()`（约行 754：`user = find_body(...); if (!interactive(user)) { reconnect(ob, user); return; }`）是驱动实际调用的重连入口；其 `reconnect(object ob, object user, int silent)`（约行 1976）会调用 `user->reconnect()`，也就是 `obj/user/user.lpc` 的真正实现（非死代码），该实现正确地 `set_heart_beat(1); net_dead = 0;`。用真实断线+重连实测复核：管理员账号在整个死亡链路中用 `info` 观察未见异常（虽然 `info` 命令本身对在线角色用 id 字符串查找会返回"没有这样物件"——`info.lpc` 只支持 `present()`/`find_object()` 风格查找，不支持 `find_player()`，这是 `info` 命令自身查找逻辑的局限，**不是本次任务范围内的 bug**，未处理），但整个死亡→断线→重连→复活序列的**行为本身**（见下）已经足以证明 heart_beat 链路没有卡死。
- **§7.90**（eval-cost 过低）：`config.fluffos` 的 `maximum evaluation cost : 30000000`，早已是本项目的高位修正值，非默认低值，无需再动。
- **§7.11 类**（`log_file()`/`write_file()` 写入未随包的运行时目录）：审查了 `adm/simul_efun/file.lpc` 的 `log_file()`（确认**无 `assure_file()` 保护**，属于潜在风险形状）以及全档案约 50 处调用点涉及的目标子目录（`static/`、`wizcmds/`、`quest_xyj/` 等），逐一核对 `work/log/` 下这些子目录**全部随包存在**（`ls work/log/` 确认 `static`、`wizcmds`、`quest_xyj`、`channel`、`cmds`、`dig`、`player`、`quest`、`user` 均已随包创建）。本档案未命中 §7.11。
- **`logind.lpc` `enter_world()` 的 `ob->save()`**：确认存在且非注释掉（约行 1551-1553：`user->save(); ... ob->save();`），无需处理。

### 发现并修复：`d/death/npc/pang.lpc` 的 §7.112 同类 bug（未被此前的 gargoyle 专项 sweep 命中）

`d/death/npc/pang.lpc`（阴阳界的"崔判官"NPC，玩家死亡后被送到这里走完五段式复活引导）的 `init()` 原样：
```lpc
void init()
{
  ::init();
  if( !previous_object()
   || !userp(previous_object()) )
    return;
  call_out( "death_stage", 5, previous_object(), 0 );
}
```
没有任何重入保护。`obj/user/user.lpc` 的 `reconnect()`（第 349 行起）无条件调用 `enable_commands()`，而 FluffOS 会在 `enable_commands()` 时把房间内每个物件的 `init()` 重新广播一次——也就是说，一个正处在"阴阳界"五段对话/复活流程中的鬼魂玩家，只要恰好断线重连一次（哪怕只是网络抖动的几秒钟），就会在原有链条之外**额外堆叠一条完全独立的 `death_stage()` call_out 链**。第二条链最终仍会各自跑到 `ob->reincarnate()`（该函数默认 `wakeup=0` 分支会把玩家身上所有物品 unequip 并 `command("drop ...")` 全部丢弃）以及 `ob->move(REVIVE_ROOM)`，于是玩家在**已经复活、正常游玩一段时间之后**，会在某个随机的后续时刻被无声地二次强制传送回复活点，并把当时正穿戴的所有装备原地丢在地上——没有任何报错，纯粹的静默破坏性 bug，和 AGENTS.md §7.112 原始发现（`dtsl` 的 `yanluo.lpc`）在功能形状上完全一致，只是这里的 NPC 换了名字和文案（"崔判官"而非"阎罗王"/"石像鬼"），因此没有被基于 `wgargoyle.lpc`/`bgargoyle.lpc` 文件名的原始 corpus sweep 覆盖到。

**修复**（`d/death/npc/pang.lpc`，纯 LF 文件，无 CRLF 顾虑）：给 `init()` 加了按受害者（`ob`）区分的 `set_temp`/`query_temp`/`delete_temp("death_stage_running")` 重入锁，在链条正常终点（`reincarnate()`+`move(REVIVE_ROOM)` 之后）和提前退出分支（`!ob->is_ghost()`）都清除该标记，写法与 AGENTS.md §7.112 记录的标准修复形状一致。

**实测验证**（修复后重启驱动，双连线编排：管理员连线 A + 测试角色连线 B/C）：
1. 用全新注册角色 `axtjrsan`（阮三），管理员执行 `call axtjrsan->die()` 制造真实死亡（非 `fight` 切磋），角色正常死亡、被送入"阴阳界"，崔判官 `init()` 触发，第一、二段对话按 5 秒间隔正常出现。
2. 在第二段对话后**直接关闭 socket B（不发送 quit，模拟断线）**，2 秒后用新 socket C 以同一账号重新连线——`logind.lpc` 立即判定 `!interactive(user)` 走 `reconnect()` 分支，显示"重新连线完毕"，没有走"是否踢掉旧连线"的确认分支（证明是真断线而非仍在线的旧连线冲突）。
3. C 连线上收到的后续对话**只完整播放了一次**（第三、四段对话 + 最终"崔判官伸手向你一指...魂魄又回到了自己身上"+复活传送到"荒郊小店"），reconnect 触发的 `init()` 重新广播被新加的重入锁正确挡住，没有出现重复的复活消息或二次强制传送——在 reconnect 后又等待了完整 25 秒宽裕窗口以捕捉可能的"迟到"第二条链，未见任何异常。
4. `work/log/debug.log`（本次会话从空文件开始）全程只有驱动启动噪音（211 行），没有任何来自这次死亡/断线/重连/复活序列的运行时错误。

### 经济系统：确认定位，两条真实可用路径，此前"未找到真正商店"的疑问已解决

- **`obj/shop/*.lpc`（"百宝斋"等 9 个跨城市同款商店，通过如 `/d/city/majiu` 的 `up` 出口进入）全部在 `create()` 里硬编码 `set("shop_type", 0)`**（`adm/daemons/shopd.lpc` 里 `shop_type` 的语义明确写着"0 表示关闭"，且 `do_list`/`do_buy`/`do_sell`/`do_pawn`/`do_retrieve` 全部有 `if (!room->query("shop_type")) return "对不起，该店铺目前已经被巫师关闭。\n";` 的门禁）。9 处实例**全部**是 0，没有一个例外，且开关本身就是标准巫师指令（`shopd.lpc` 里的 `open_shop`/`close_shop`）能操作的运营状态位——这是这份档案"商店需要巫师上架/开张才能营业"的运营设计（游戏管理员的常规工作，不是玩家能触发的路径），**不是编程 bug**，未做任何改动。这与第二轮"起始客栈附近没找到杂货铺/兵器店"的观察吻合并给出了确切原因。
- **真正对普通玩家开放、随开随用的经济路径是当铺（`std/room/hockshop.lpc`，如 `/d/city/dangpu_e` 古记当铺）**：`value <物品>`（估价）、`sell <物品>`（卖断，一次性换钱）、`pawn <物品>`（典当，可赎回）均已实测正常工作——管理员账号把起始装备"锦缎"用 `sell jinduan` 卖给当铺，正确收到"二两白银又四十文钱"，`i` 确认物品消失、`Coin`/`Silver` correctly 入包。这条路径此前两轮均未测试到，本轮补完。
- **留言板**（`std/item/bboard.lpc`）：在南城客栈自带的留言板上 `post <标题>` → 输入正文 → `.` 结束（不是 `@`，编辑器提示"结束离开用 '.'"）→ `read 1` 正确显示刚发的帖子（标题、作者、时间、正文全部正确）。普通玩家发帖需要"读书识字"技能 ≥30（`do_post()` 里的门槛判定），这是设计门槛（新手还没学识字技能），未作为 bug 处理。

### 本轮结论

发现并修复一例真实、跨会话已证明高价值的 §7.112 同类静默复活重复 bug（`d/death/npc/pang.lpc`），已实测验证死亡→断线→重连→复活全链路在修复后正确无重复；经济系统的两条真实路径（当铺 sell/pawn、留言板 post/read）均已实测确认可用，商店"全部关闭"确认是巫师运营设计而非 bug；标准五项检查清单（§7.90/§7.11/§7.111/§7.112/§7.113）逐项复核，除本轮新修复的 pang.lpc 外均确认此前记录有效或本档案不适用。**AGENTS.md §7.112 的通用教训在此再次成立：文件名匹配（`wgargoyle.lpc`）的机械 sweep 无法覆盖所有同功能异名 NPC，任何后续档案的深度测试都应该独立按"`init()` 内无保护 `call_out()`"这一行为特征去查，而不是只看文件名。

## 深度功能测试（第四轮，2026-08-19）——用全新角色独立复核经济系统，发现并修复一例真实 `give`/`ask` 崩溃 bug

本轮任务书的前提（"经济系统仍未定位"）实际上已经过时：第三轮（同为
2026-08-18）已经找到并实测了当铺 sell/pawn 与留言板两条真实经济路径
（见上一节），只是驱动本轮任务的记忆索引条目没有跟上第三轮的进度。
没有因此跳过任务——本轮改用一个**全新注册、从未被任何前几轮账号触
碰过**的测试角色，独立地把"卖东西换钱"这条链路完整走了一遍作为二
次确认，并且在走查 `give`/`ask` 命令时发现了一例此前三轮测试都没有
覆盖到的真实运行时崩溃 bug，已修复并实测验证。

### 经济系统：用全新角色独立复核 sell 交易，确认可正常工作

全新注册账号 `axtjshi`（中文名"李四"），走完完整注册流程后进入"南
城客栈"。该角色出生自带装备为"皮靴(pi xue)"和"蓝马褂(cloth)"——分别
读代码确认为 `work/obj/cloth/male-shoe.lpc` 和 `work/obj/cloth/
male6-cloth.lpc`（两份文件的注释都明确写着"This is the basic equip
for players just login."），两者 `create()` 里都显式 `set("value",
0)`。用巫师账号 `goto`+`summon` 把这个全新角色带到"古记当铺"
（`/d/city/dangpu_e`）后，`value pi xue`/`sell cloth` 均返回"一文不
值"——**这不是经济系统坏了，是这两件新手起始装备本来就被设计成 0 价
值**（防止用重复注册小号刷钱的常见 MUD 设计），与经济系统本身能否
正常运作是两回事。

为了排除"起始装备恰好都不值钱"这个巧合，进一步用巫师账号 `clone
/obj/cloth/jinduan`（`value=800` 的锦缎，第三轮用的也是这件）后
`give jinduan to axtjshi` 把一件真正有价值的物品转移给这个全新角
色，再切回该角色执行完整交易：`value jinduan` 正确显示"锦缎价值八
两白银……如果卖断(sell)，可以拿到二两白银又四十文钱"，`sell
jinduan` 正确扣除物品、正确发放"四十文铜钱(Coin)"+"二两白银
(Silver)"到背包，`i`/`score` 确认到账无误。**结论：经济系统（当铺
sell 路径）在一个完全独立、未被前几轮任何账号触碰过的全新角色上再
次验证工作正常，不是"账号级偶然"，是系统级可用**。全档案 9 处
`obj/shop/*.lpc` 商店仍确认全部 `shop_type=0`（巫师未上架，运营设
计而非 bug，与第三轮记录一致，本轮 `grep` 复核未变）。

### 新发现并修复：`give`/`ask` 命令的 `QUEST` 宏路径错误，导致运行时崩溃

在准备"把物品转移给测试角色"这一步时，`give jinduan to axtjshi`
第一次尝试直接在玩家的转移路径上崩溃：

```
执行时段错误：*call_other() couldn't find object '/std/quest'.
程式：/cmds/std/give.lpc 第 108 行
```

`work/cmds/std/give.lpc` 第 108 行：`if (QUEST->quest_give (me, who,
obj))`；`work/include/globals.h` 第 152 行：`#define QUEST
"/std/quest"`。全档案里根本不存在 `/std/quest.lpc` 这个文件——最接近
的同名文件是 `work/std/misc/quest.lpc`，但读了它的内容后确认这是
"所有玩家任务继承此对象"的**任务基类模板**（供各个具体任务对象
`inherit`，本身没有 `quest_give`/`quest_ask` 这两个全局钩子函数)，
不是 `QUEST` 宏原本想指向的那种"通用任务完成检测守护进程"。也就是
说这不是简单的路径打错字（"缺一段 `misc/`"那么简单），而是这个全局
`QUEST` 守护进程本身在这份档案里从未被真正实现/交付过——是一个从祖
先代码库遗留下来、一直没写完的钩子。

**影响范围**：`grep -rn "QUEST->" work --include="*.lpc"` 全档案只
有三处：
- `work/cmds/std/give.lpc` 第 108 行（活代码，**任何一次成功的
  `give <物品> to <目标>` 都会触发**——只要 `present()`/`playerp()`
  等前置检查都通过，必然执行到这一行，等于说这个玩家最基础的社交/
  交易命令，长期以来对**任何**"给某人某东西"的合法用例都会崩溃）。
- `work/cmds/std/ask.lpc` 第 87 行（活代码，`ask <NPC> about <话
  题>` 分支——只要目标不是玩家（`!userp(ob)`），即绝大多数"向 NPC
  打听消息"的正常用法都会触发同样的崩溃）。
- `work/std/char/char.lpc` 第 113 行：`QUEST->quest_kill(...)` 整
  行被注释掉，死代码，未处理。

**修复**：给两处活的 `QUEST->` 调用点各加一个house-style的文件存在
性守卫（本档案里 `file_size(path+".lpc") > 0` 这个写法在
`cmds/std/go.lpc`/`cmds/imm/goto.lpc`/`cmds/adm/restore.lpc` 等多处
已经是既有习惯用法），而不是瞎编一个"最小实现"或者把宏改指到语义
完全不符的 `std/misc/quest.lpc` 模板类去凑合：

```lpc
// give.lpc 第108行
if (file_size(QUEST + ".lpc") > 0 && QUEST->quest_give (me, who, obj))
// ask.lpc 第87行
if ( file_size(QUEST + ".lpc") > 0 && (msg = QUEST->quest_ask(me, ob, topic)) )
```

效果：这个从未交付的全局任务钩子被安全跳过（`give`/`ask` 命令的其
余逻辑完全不受影响，只是不会再触发这个本来就不存在的钩子），不会再
崩溃。

**实测验证**：`update /cmds/std/give` + `update /cmds/std/ask` 热更
新成功后，重新执行 `give jinduan to axtjshi`（"你给李四一件锦
缎。"，无崩溃）与 `ask gu guiyou about jinduan`（"古贵有疑惑地看着
你，摇了摇头。"——正常的 NPC 不认识话题回复，无崩溃），两条命令均
恢复正常。`work/log/debug.log`（本次会话从空文件开始）全程只捕捉到
**这一条**修复前的报错，修复并热更新之后的所有后续操作（含上面完整
的 sell 交易）零报错。

**未做的事**：没有去写一个真正的 `/std/quest.lpc` 全局任务守护进
程——这份档案里从来没有交付过这个功能，凭空发明一套任务完成检测逻
辑属于新增游戏功能而不是修 bug，超出本轮范围。也没有把这个发现扩大
成跨库 sweep——本轮只确认了这一份档案里的实例，`QUEST` 这个宏名字
本身很通用，其他血统家族即使同名宏也未必是同一份 `globals.h`/同样
的路径错误，需要每个库各自读代码确认，不建议不经验证就批量替换。

### 标准清单复核（快速确认，非重新深挖）

- **§7.111**（`master.lpc` 的 `file_name(error["object"])` 空指针
  防护）：`work/adm/obj/master.lpc` 第 416、552 行两处调用点仍然带
  三元判空保护，与第三轮记录一致，无需再动。
- **§7.112**（`init()` 内无保护 `call_out()` 死亡引导链）：
  `d/death/npc/pang.lpc` 第三轮已修复的重入锁仍在（本轮未改动该文
  件，快速 `grep "death_stage_running"` 确认锁仍存在），无需再动。
- **§7.113**（netdead 重连不恢复 heart_beat）：`work/adm/daemons/
  logind.lpc` 的 `logon()`→`reconnect()` 路径与第三轮读到的一致，
  本轮亲自靠 `find_body`+"重新连线完毕" 的实测重连（多次，见上文两
  处后台连线技巧）反复验证了重连后角色仍能正常收发命令、正常交易，
  没有观察到任何 heart_beat 卡死的迹象，维持"不适用"结论。
- **§7.114**（`private` 的 `input_to()` 回调经由继承 mixin 静默失
  效）：`grep -rn "private.*input_line\|private.*input_to"
  work --include="*.lpc"` 全档案零命中；本档案唯一的编辑器 mixin
  `work/feature/edit.lpc` 的 `input_line()` 本身不带 `private`，不
  是这个 bug 的 shape，不适用。
- **§7.90**（eval-cost 过低）：`config.fluffos` 的 `maximum
  evaluation cost : 30000000`，与第三轮记录一致，早已是高位修正
  值，无需再动。

### 本轮结论

经济系统（当铺 sell/pawn）经一个全新、未被任何前几轮账号触碰过的测
试角色独立复核，确认系统级可用，不是账号偶然；顺带发现并修复一例此
前三轮都未覆盖到的真实 bug——`give`/`ask` 命令因 `QUEST` 宏指向一个
从未交付的全局任务守护进程路径而在几乎所有正常用例下崩溃，已加存在
性守卫修复并实测验证（`give`、`ask` 均恢复正常，交易全程 `debug.
log` 零报错）。标准五项检查清单（§7.90/§7.111/§7.112/§7.113/
§7.114）逐项复核均确认此前结论有效或本档案不适用，没有发现新的异
常。测试用留存证据账号：`axtjshi`（含一次完整、已验证到账的 sell
交易）。会话中产生的一个额外遗留测试账号 `qinzhan`（第三轮某次未清
理干净的残留，未提交追踪）已一并清理。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). 10 live
`replace_program(ROOM);` occurrences across 10 room files
(`obj/misc/void.lpc`, `d/kaifeng/wroad3.lpc`, `d/nanhai/zhulin2.lpc`,
`d/lanzhou/duchuan.lpc`, `d/lanzhou/huanghe_2.lpc`,
`d/emei/qfachanfang.lpc`, `d/emei/xiaolu2.lpc`, `d/chengdu/sanxia2.lpc`,
`d/chengdu/shudao12.lpc`, `d/chengdu/chaoyangdong.lpc`) — same fatal
redundant-replace-after-inherit shape as the rest of the §7.100 family.
No room-building tool exists in this lib. Fixed by deleting the
redundant lines. Verified via a clean native driver boot (zero new
`debug.log` errors, port listening, killed by exact PID after ~8s).

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## §7.19 enable_player() reentrancy -- FALSE POSITIVE, unreachable (2026-09-01)

Corpus-wide mechanical sweep (AGENTS.md §7.19, Batch F of 6). `feature/command.lpc`'s
`enable_player()` does have the same structurally-ineffective
`nosave int enabled = 0;` guard found on `ylfyxa3`/`longyunmeng`/`xajh4gkb`/
`xyzxyl201412`/`wdxtym` in this batch (`enabled = 1` set AFTER
`enable_commands(1)` returns, not before -- would NOT actually prevent the
reentrancy if it were reachable), and `feature/damage.lpc`'s `revive()`
does re-invoke `enable_player()` while already `living()`. However, unlike
those 5 siblings, an exhaustive search of this entire lib (every `void
init()` in all ~1150 files that define one, brace-matched to isolate each
function's own body, cross-checked with a second independent line-window
heuristic, plus every file inheriting `NPC` individually, plus every
`F_*` mixin `char.lpc` inherits) found **zero** calls to `setup()`,
`reset_me()`, `enable_player()`, or `enable_commands()` from inside any
`init()` function anywhere in the lib -- this lib's NPC roster (e.g.
`std/char/smith.lpc`, `d/meishan/npc/cao.lpc`, `d/qujing/wuji/npc/kingfake.lpc`)
simply doesn't use the "leader NPC's `init()` unconditionally re-calls
`me->setup()`" idiom that the `zhangmen.lpc`-family sibling libs in this
batch do. The only whole-file grep hits were coincidental same-named
`setup()` calls in unrelated functions (a fire-hazard room's own exit
`setup()` in `d/18hell/16/heitudi.lpc`, a ranking-board item's `ITEM`-lineage
`setup()` in `obj/mptop.lpc`, both several lines *after* their `init()`'s own
closing brace, not inside it) -- same false-positive shape as the already-
documented `shzs`/`xzyx`/`xiyouji2003` cases. Since `enable_player()` is
never reachable from any `init()`, the driver-side-effect reentrancy this
sweep guards against cannot occur here regardless of the `enabled` flag's
ordering. **Left untouched, no fix applied** (the mechanical fix would be
inert but harmless; skipped per this project's "don't fix what isn't
reachable" standing practice).
