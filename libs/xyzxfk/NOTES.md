# xyzxfk — 夕阳再现 (Sunset Reappears — "疯狂江湖" build)

Archive: `夕阳再现-疯狂江湖.rar` (byte-identical duplicate: `夕阳再现-疯狂
江湖(1).rar`, already listed in AGENTS.md's Duplicate archives table —
only this one processed). Port: 40040. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese
name).

## What this is

"夕阳再现" ("Sunset Reappears"), `adm/obj/{master,simul_efun}` layout,
~17,768 raw files — one of the larger libs processed in this session.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 10` → character-count bound `< 1 || > 5`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed, via source reading**: no §4 fix
   (`master.c`'s `valid_write` gates via `find_object` only); no
   `named.c` daemon exists in this lib.
3. **Confirmed no DNS/intermud daemon to exclude** — unlike most recent
   libs, `adm/etc/preload` has NO `dns_master` entry at all (nothing to
   apply AGENTS.md §15p to here). `httpd` is in preload, confirmed safe
   — its socket setup is deferred via `call_out("setup", 5)`, non-
   blocking to preload.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xyzfktest` → confirm `y` → **real
Chinese name `秦风`** → accepted, proceeds straight to "请设定您的密码：".
This lib's registration prompt warns against Jin Yong novel character
names, but the actual `banned_name` array only contains pronouns and
generic words ("风云", "流氓", political figures) — no specific
character name needed to be avoided this time.

## Re-verification pass (QA sweep, later session)

Earlier pass's "full registration flow verified end-to-end" only actually
tested through to the password-setup prompt, not an ordinary post-login
command (per the project's standing §15ae policy of always testing at
least one post-login command like `look`/`score`). Re-tested the whole
flow end-to-end this pass:

- Confirmed `feature/command.lpc`'s `command_hook()` is `protected nomask`
  (not `private`) -- §15ae does not apply here.
- **Found and fixed a real bug**: `adm/obj/master.lpc`'s `log_error()`
  showed EVERY compile-time diagnostic to the connected player
  unconditionally (§15w), including harmless WARNINGS (`Unknown #pragma,
  ignored`, `Unused local variable`) from the first-ever lazy compile of
  a never-preloaded room/NPC file -- confirmed live: a fresh registration
  showed ~6 spurious `编译时段错误：... warning: ...` lines interleaved
  with the real welcome banner and room description. Fixed by gating the
  player-facing broadcast on the message NOT containing `"warning:"`
  (still logs everything to disk regardless, matching the established
  fix pattern used across this project). Re-verified with a fresh
  registration (`qinshu`/秦树, female) after restarting the driver: **zero**
  spurious messages, `look`/`score`/`quit` all correct (correct
  female-specific title "芊芊民女", landed in a real starting room
  "铁枪庙").
- Full registration + post-login-command flow now confirmed working with
  real Chinese names 秦天(male, landed in 北疆小镇)/秦树(female, landed in
  铁枪庙), `look`/`score`/`quit` all producing correct output, zero
  `执行时段错误` in `debug.log` after the fix.

## lpcc sweep

14,105 files, 13,798 pass / 307 fail (97.8%). Largest single cluster (53
failures) is a missing `GROUP_D` global — not triaged individually per
AGENTS.md §6b/§13. Memory stayed healthy throughout (~10-11GB free
during this sweep specifically), even while running concurrently
alongside several sibling libs' conversions/sweeps in the same session
as part of a push to parallelize more archives at once.

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  14,003 files reformatted, 37 unchanged, 65 refused (self-check
  failures on messy legacy code, expected/harmless per the tool's own
  docs). Spot-checked that the fix sites below survived reformatting
  byte-for-byte in logic (only whitespace/style changed).
- **New bug found and fixed during this pass's native re-verification**
  (not caught by any earlier pass): `adm/daemons/logind.lpc`'s
  `get_resp()`/`get_name()` had the same stray, pre-existing debug
  leftover `printf("%O\n", ob);` seen in the `xiyouji`-family siblings
  (2 occurrences here) — dumped a raw internal object reference (e.g.
  `/clone/user/login#1`) straight to the connecting player right after
  their Chinese name is accepted, on every registration. Found live
  during a fresh registration test against the rebuilt driver; removed
  both occurrences; re-verified with a fresh registration (`qfzaid`/
  秦风终, male) — no stray object-reference text anywhere in the
  transcript, `look`/`score`/`quit` all still correct.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified with real Chinese name
  **秦风终** (male), reaching the actual starting room (北疆小镇),
  `look`/`score`/`quit` all producing correct output.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only the expected
  non-fatal `httpd.lpc` `socket_create`/`socket_bind` "Undefined
  function" preload errors, since the `sockets` package isn't built
  into this WASM image — same class of harmless preload gap as any
  missing daemon natively). **Login is blocked by the documented
  `query_ip_number()` WASM limitation**: `adm/daemons/logind.lpc`'s
  `logon()` calls `BAN_D->is_banned(query_ip_number(ob))` before any
  other prompt; under WASM this receives a malformed IP string (not a
  real dotted-quad), and the connecting player sees "你的地址在本 MUD
  不受欢迎" (address not welcome) immediately on connect, before ever
  reaching the id/name prompts. This is a driver-side WASM gap, **not**
  a mudlib bug — not patched, per AGENTS.md's standing guidance. Native
  play on `127.0.0.1` is completely unaffected.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the four standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban/site gates**
   - `adm/daemons/band.lpc`: added reusable `is_local_ip(string ip)`
     helper (returns 1 for `127.*`, empty/non-string, or any string that
     fails `sscanf("%*d.%*d.%*d.%*d")` — i.e. WASM garbage IPs).
   - `adm/daemons/band.lpc` `is_banned()` (was ~L106): short-circuits
     `return 0` when `is_local_ip(site)` — this was the WASM login
     blocker (`is_banned()` returned 1 for a malformed IP, rejecting
     every WASM connection with "地址不受欢迎").
   - `adm/daemons/band.lpc` `vaild_allow_address()` (was ~L353):
     short-circuits `return 1` for local IPs (bypasses per-player
     allow-ip restriction).
2. **Uptime startup gate**: none in this build (the sibling
   `xyzxfy2` has `uptime()<30`; this "疯狂江湖" build does
   not).
3. **Anti-flood throttles exempt loopback** — `adm/daemons/logind.lpc`:
   `logon()` `ban_cnt > 6` gate and `get_id()` `ip_cnt > 6` gate both now
   `&& !BAN_D->is_local_ip(...)`. In-game quit/kickout 600s retention
   timers left intact (game design, AGENTS.md §1.3e).
4. **Admin account seeded** — id `fluffos`, registered through the real
   flow (浮浮, male), granted `(admin)` by adding `fluffos (admin)` to
   `adm/etc/wizlist` (read by `securityd.lpc::create()`). Verified after
   restart: `update /adm/daemons/band` recompiled OK, `goto` worked,
   score shows 「您目前权限：(admin)」. Save file:
   `work/data/user/f/fluffos.o` (untracked, NOT gitignored — orchestrator
   must `git add` it).

Retest: fresh registration (the fluffos registration itself) reached the
world as a `(player)`; fluffos re-login has `(admin)` and wizard commands
work; `log/debug.log` clean (0 runtime errors).

## WASM 修复摘要（迁移自 meta.json 的 group_note）

之前被误标记为某个孤儿档案文件名的逐字节重复版本，而那个文件名根本对应不到任何已追踪的档案；这里的内容其实是一款完全独立、可以游玩的游戏（有自己的 -N 版本号、自己的端口、自己的 README）——已清除 duplicate_of。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 103 处命中，其中含 1 处运行时代码生成模板（write_file() 动态生成新留言板源码的字符串模板里嵌了同样的致命形状，已同步从模板字符串中删除，否则玩家用该功能新建的留言板也会一出生就带病），已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (2026-08-07)

按 AGENTS.md §10.7 流程做的第一轮完整交互式游玩测试。这份档案自己
的血统（"夕阳再现" family，AGENTS.md §11）有三个手足档案
（`jhfy`/`wmkj`/`bixiecanyang`）已经各自做过 §10.7 深挖，开机前先读
了这三份记录当路线图，逐条核对已知 bug 是否也存在于本档案——结果
不是简单的"移植"，而是牵出了两个更严重的、之前没被发现过的新 bug。
WASM 本轮仍被跳过验证：emsdk 安装器把工具链下载硬编码到
`storage.googleapis.com`，本 session 的出站代理策略拒绝该域名
（`curl -sS $HTTPS_PROXY/__agentproxy/status` 确认为 403），未重试；
这份档案自己 NOTES.md 里之前的"WASM build tested"记录仍然有效（登录
阶段的 `query_ip_number()` 驱动侧限制已知且非 mudlib bug），只是本轮
没有重新用 WASM 复测这次新修的 bug。

**开机前主动核对手足档案已确认的问题：**

- **AGENTS.md §7.34（本档案自己之前已修好）**：`logind.lpc` 两处随机
  取名/手动取名路径上的 `printf("%O\n", ob)` 调试残留——直接读代码
  确认这份档案自己更早一轮的深度测试已经修过，本轮实测注册流程也
  确认没有再泄漏对象引用，未重复修改。
- **AGENTS.md §8.9（新命中）**：`adm/daemons/logind.lpc` 的
  `enter_world()` 食物/饮水初始化判断 `if (ob->query("age") == 14)`
  用的是登录桩对象 `ob` 而不是玩家本体 `user`，和三个手足档案（`jhfy`/
  `wmkj`/`bixiecanyang`）确认过的形状完全一致。改成
  `user->query("age") == 14`，Live 验证：注册后 `score` 食物/饮水两
  条状态全满（■■■■■■■■■■■■■■■■）。
- **§7.68 死亡软锁"修复"——按已撤销的结论，本轮未施加**：三个手足档
  案的深度测试记录里都提到"复活软锁"曾被当作 bug 修复（`if (!ob ||
  !present(ob)) return;` 改成 5 秒重试），后来被撤销为设计判断而非
  程序错误（详见 AGENTS.md §7.68 顶部撤销说明）。本轮开机前读了这条
  撤销记录，没有对本档案的死亡/复活代码施加同样的"修复"。

**本轮独立发现并修复的两个新 bug（均为真实、可复现的严重问题）：**

1. **`log_file()` 本身无防护 + 一处直接 `write_file()` 未防护，两条
   路径同时命中缺失的 `/log/nosave/`、`/log/login/` 等目录，前者
   导致每一次新角色注册都会卡死，后者导致每一次死亡都会陷入无限
   循环。**
   - `adm/daemons/logind.lpc` 的 `get_gender()`（注册流程的最后一
     步，紧接着调用 `enter_world()`）里 `log_file("login/newid.log",
     ...)` 抛出未捕获的运行时错误（`/log/login/` 目录不存在），把
     `get_gender()` 中止在这一行——`init_new_player()`/`enter_world()`
     根本没有机会执行。玩家看到的现象：天赋/邮箱/性别全部问完，
     最后卡在裸的 `>` 提示符，`look`/`score`/`help` 全部返回默认
     的"什么？"（指令不存在），因为这个角色物件从未真正进入游戏
     世界、从未挂上任何指令目录。这不是"某个功能坏了"，是**每一
     个新角色的注册流程本身就是坏的**。
   - `adm/simul_efun/file.lpc` 的 `log_file()`（全档案通用的日志辅
     助函数，`get_gender()` 的这次调用正是通过它）本身只是裸
     `write_file(LOG_DIR + file, text)`，同一文件里现成的
     `assure_file()` 辅助函数从未被调用。直接在 `log_file()` 内部
     加一行 `assure_file(LOG_DIR + file)`，一次性覆盖它全部至少 4
     个不同的 `/log/{nosave,login,fight}/*` 调用点（`assure_file`
     原本定义在 `log_file` 后面，这个编译器要求同文件内被调用的函
     数需要先声明/定义，顺手把两个函数的顺序对调了，和 jqxz2015 那
     一轮遇到的完全相同的编译器限制）。
   - `adm/daemons/combatd.lpc` 的死亡处理函数（`killer_reward()` 的
     同类逻辑）里还有一处**不经过 `log_file()`、直接裸调用**
     `write_file("/log/nosave/KILL_PLAYER", ...)`，同样没有防护，
     同样因为目录不存在而抛出未捕获错误——这一处不是 `log_file()`
     修复能覆盖到的，必须单独处理。这里的严重后果比注册卡死更离谱：
     每次玩家死亡，`die()` 都会在这一行中止，角色永远不会真正"死
     透"（不会被移到死亡场景、不会设置鬼魂状态），但引擎的
     `heart_beat()` 却认为角色仍在战斗，于是**同一次死亡判定在每
     个心跳周期反复重新触发**——实测复现：用 `kill` 攻击一个普通
     NPC，触发死亡后死亡讯息（"你口中喷出几口鲜血，倒在地上,死
     了！"）和频道八卦讯息连续刷了几十次都不停，角色卡在原地反复
     "死"而从未真正离场，`debug.log` 里同一条 `/log/nosave/
     KILL_PLAYER` 错误也随之反复记录。加一行 `assure_file(...)`
     后重启复测：同样 `kill` 一个 NPC，这次死亡讯息只出现一次，
     角色干净地被送到"鬼门关"，NPC"白无常"完整走完"阳寿未尽"的
     整套判词对白，一股"阴冷的浓雾"把角色送回"武庙"（REVIVE_ROOM），
     `score` 确认"你共死亡：1 次"、精气按死亡惩罚正确减半、潜能
     正确扣除。
   - 顺手排查了同一目录类别下的其余 `write_file("/log/...", ...)`
     直接调用点，全部补上 `assure_file(...)`：`cmds/arch/reboot.lpc`
     和 `cmds/adm/shutdown.lpc`（各一处 `/log/nosave/LASTCRASH`）、
     `cmds/adm/restoredata.lpc`（`/log/nosave/RESTORE_PLAYER`）、
     `cmds/usr/helpbbs.lpc`（`/log/doc/register/<id>`，此前也不存
     在的目录）。这几处触发频率低（管理员专用指令），本轮未逐一实
     机复现，但修法和已验证过的其余四处完全一致，风险为零（`assure_file`
     是幂等的目录创建，不改变原有写入内容）。
   - 归类：均为 AGENTS.md §7.11（"缺失运行期目录导致 write_file
     静默中止"）的确认新实例，其中注册路径这一处的严重度和已归档
     的 `xajhxo` 实例（§7.11 已有记录：注册流程被同类 bug 卡死）完
     全同级，死亡路径这一处的严重度和 `jqxz2008`/`jqxz2008dlx` 已
     确认的 `killer_reward()` 死循环完全同级——`log_file()` 本身缺
     少防护这一具体形状，和 `jqxz2015` 这一轮独立发现的形状也完全
     一致，§7.11 里 `xajhxo` 那条记录已经完整覆盖了这个教训，未再
     重复添加新条目。

2. **`cmds/usr/inventory.lpc` 整个文件不存在——`i`/`inventory` 指
   令从注册那一刻起就是坏的（新分类，AGENTS.md 新增 §7.94）。**
   `cmds/usr/` 目录下只有 `inventory.C`（大写扩展名）、
   `inventory.c.bak`、`复件 inventory.lpc`（"inventory.lpc 的副本"）
   三份不同的历史实现，没有一份叫纯粹的 `inventory.lpc`。别名表
   （`aliasd.lpc`）里 `"i": "inventory"` 照常存在，所以每次 `i`/
   `inventory` 都会解析到一个根本不存在的指令文件，返回引擎默认的
   "什么？"（指令不存在）——和普通打错字的表现完全一样，如果不是
   刚好在测试这条指令，很容易被当成"这个 mud 没有背包指令"直接跳
   过。**没有靠猜就确定了哪一份是"真正"该有的内容**：在同一份档案
   的 `u/isle/ToMud/inventory.lpc`（一个巫师沙盒目录里的工作副本）
   找到一份逐字节对应（除本项目自己的格式化差异外完全一致）的实现，
   而且只有 `inventory.C` 使用了和这份档案 `include/tomud.h` 里
   `CLEAN1`/`ADD1` 宏一致的代码（`.bak`/`复件` 两个变体都没有这段
   逻辑）——这才是把 `inventory.C` 确定为"应该被恢复的那一份"的证
   据，而不是三选一的主观判断（AGENTS.md §7.94 专门记录了这条判断
   依据的重要性：档案里如果同时存在多份内容不同的历史实现，选哪一
   份是内容判断，但"确认某份内容在档案别处也是活代码"是可核实的事
   实）。修法：把 `inventory.C` 的内容原样复制到新建的
   `cmds/usr/inventory.lpc`，`.C`/`.c.bak`/`复件` 三个旧文件不动
   （无害的死代码备份，不会被引擎编译/派发）。Live 验证：修复前
   `i` 返回"什么？"；重启后同一测试角色 `i` 正确列出"□布衣(Cloth)"，
   负重百分比正常显示。

**测试路径**：一次连续会话里：注册（真实中文名 梁景寒，id
`xyzfkdeep`，随机天赋）→ 卡死在裸 `>` 提示符（bug 1 首次复现）→
修复+重启后重新注册，完整 MOTD/权限/上次登录信息/落地"客店"全部正常
显示 → `score`/`i` 确认食物/饮水满格（§8.9 修复）、`i` 正确工作
（bug 2 修复）→ 探索到"北大街"，`fight` 对"收破烂的"（友善 NPC）
被正确拒绝（不同意较量），改用 `kill` 强制开战 → 战斗中触发"你的
「基本拳脚」进步了！"（组织性技能学习），继续战斗直到角色被击杀，
死亡讯息死循环（bug 2 后半段，KILL_PLAYER 写入崩溃首次复现）→
修复+重启后重新用 `kill` 触发死亡，这次死亡→"鬼门关"→白无常判词
→复活送回"武庙"全程一次性走完，无重复讯息 → 门派加入：拜访
"忆香亭"红花会总舵主陈家洛，`apprentice` 正确按代码里的正气门槛
（`shen >= 50000`）拒绝（合理设计，未强行绕过）→ 改用管理员
`setskill xyzfkdeep sword 50` 验证捷径路径，`skills` 确认组织性的
`parry`（对练中自动习得）和捷径赋予的 `sword`（50 级）同时存在 →
`quit` → `debug.log` 检查（用文件修改时间戳而非仅 grep 关键字确
认：quit 前后 debug.log 文件的 mtime 全程停留在修复前最后一次崩溃
的时间点，证明修复后的整个会话零新增运行时错误）→ 断线重连（`nc`
新连接，非同一 TCP 会话），`score`/`skills` 确认门派/技能/死亡次数/
潜能全部正确持久化。

**测试角色**：id `xyzfkdeep`，中文名 梁景寒，密码 `Xyzfk2026Test`，
普通百姓（未入门派，`apprentice` 门槛未达到），技能 parry（组织性）
+ sword（捷径路径，50 级），死亡 1 次，位于武庙（REVIVE_ROOM，起始
房间为随机 4 选 1，未曾 `save` 过固定 startroom）。存档：
`work/data/{login,user}/x/xyzfkdeep.o`。管理员账号 `fluffos` 存档
产生了正常的 food/water/mud_age 增量（无损坏，`setskill.lpc` 全程
正确操作 `ob` 而非 `me`），按这份档案自己既有 NOTES 里"必须提交，
不受 gitignore"的约定一并提交；`adm/daemons/maxonline`（本轮测试
期间因多次重启驱动被意外改写为较低的同时在线人数峰值）已用
`git restore` 还原到测试前的真实历史峰值。

**验证通过**：真实中文名注册（修复后）；`look`/`score`/`i` 多次状
态检查；食物/饮水初始化（§8.9）；`inventory`/`i` 指令本身（新
§7.94）；安全对练 `fight`（正确拒绝）与 `kill` 强制开战；组织性技
能学习（战斗中自动进步）；管理员捷径路径 `setskill`；完整死亡→鬼
门关→复活循环（含 `log_file()`/裸 `write_file()` 两条独立防护路径）；
门派加入的正气门槛正确生效（未绕过）；`quit` 后 debug.log 检查；
断线重连后状态持久化。

**明确未验证**（记录而非静默跳过）：完整拜师流程直到正气达标（需
要大量战斗积累正气值，超出本轮时间预算，改用管理员捷径验证同一底
层技能赋予路径）；商店购买（本轮未探索到商店所在区域）；`cmds/arch/
reboot.lpc`/`cmds/adm/shutdown.lpc`/`cmds/adm/restoredata.lpc`/
`cmds/usr/helpbbs.lpc` 四处新加的 `assure_file()` 防护（管理员专用
或低频功能，未逐一实机复现，仅代码层面确认修法与已验证的四处完全
一致）；WASM 下的重新验证（详见上方说明，proxy 阻断，此前已有会话
独立确认过登录阶段的 WASM 限制且与本轮修的 bug 无关）。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。核对上面记录的所有修复（§7.11 `log_file()`
及其覆盖的注册/死亡路径、§7.94 `inventory.lpc`、`log_error()`
severity 判断）逐项确认代码仍然生效；`win_times` 的 `%`-operator 也
已用 `to_int(query("win_times")) % 5`（`d/city2/npc/refereew.lpc:146`）；
`feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。管
理员 `fluffos`/`Mud@2026` 真实重连验证：`score` 显示"【玄法天君】"
头衔，食物/饮水满格，`i` 正确列出随身物品，`debug.log` 全程干净。
驱动按精确 PID 结束；测试期间产生的存档时间戳增量已 `git checkout
--` 还原，本轮无需新代码改动。

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 5760
处独立、未注释的 replace_program(ROOM); 整行（其中 `d/party/
actionavailable xiao cangtian,0/` 这个名字带空格逗号的异常目录下 32
个房间文件也在其中——目录名本身是一个已有的、和本次修复无关的历史
遗留问题，未做处理，超出本次任务范围）。另外手工清理了造房工具代码
生成模板里内嵌的同一形状，本库有两份完全同形状的拷贝
（`clone/misc/roommaker.lpc`、`u/fyue/misc/roommaker.lpc`，各 1 处
字符串拼接）。删除总计 5762 行，与本次扫描 FINDINGS.md 记录的
xyzxfk 存活命中数完全一致。

验证：干净启动一次真实调试驱动，端口 40040 正常监听，
work/log/debug.log 全程无新增内容。用已播种的 `fluffos`/`Mud@2026`
管理员账号连线，在北疆小镇/巴依家小院/巴依家客厅之间往返走了十余个
房间（含 NPC），look/who 均正常，未见任何 "cannot replace"/"cannot
bind" 或崩溃迹象。测试产生的 `data/{login,user}/f/fluffos.o` 存档
时间戳 diff 已 `git checkout` 撤销，不提交。驱动按精确 PID kill。
