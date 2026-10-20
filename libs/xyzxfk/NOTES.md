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

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-13 第二轮只做了重连，没测商店和拜师。本轮用既有
`fluffos`/`Mud@2026`（中文名「浮浮」，男性，无门派）。

- **登录**：落地 `/d/quanzhou/tieqiang` 铁枪庙。无巫师效验码。
- **商店**：`goto /d/city/zuixianlou`，`npc/xiaoer2` `list` 列出烤
  鸡腿八十两黄金 / 牛皮酒袋二百两黄金 / 包子五十两黄金。这是内容
  定价（`jitui` `value` 800000，`baozi` 500000），不是 `value_string`
  换算 bug。普通百姓 `buy jitui` 在只有一两黄金时正确拒绝「你的钱
  不够」。
- **拜师**：`goto /d/gaibang/inhole`，`apprentice zuo`（左全）一次
  完成 →「恭喜您成为丐帮的第二十代弟子」。`score` 称谓「丐帮第二
  十代弟子」、师傅「左全」。`save` + 120 秒冷却后重连，称谓/师傅
  仍在（落地北疆小镇 `/d/xingxiu/beijiang`）。
- **丐帮买东西**：`feature/dealer.lpc` 对 `family_name == "丐帮"`
  一律 `notify_fail("你是个穷叫化，买什麽东西！")`。拜师后再带一
  百两黄金去买，被这条内容规则挡住——不是编程 bug。其它手足档案
  应先买再拜。
- **日志**：live `debug.log` 是 `libs/xyzxfk/log/debug.log`（Boot
  Time Thu Sep 3 21:46:56 2026）。无 `error:`。
- **结论**：商店议价/钱不够路径、有机拜师、重连均通过，本轮无新
  编程 bug 可修。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 3 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 1 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen_old/manglin1.lpc`, `d/quanzhen_old/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/app/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/fyue/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`u/fyue/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`u/fyue/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xyzxfk --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 543 个 `.lpc` 和 3 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：498 -> 498 通过，无回退；改过的头文件的 34 个包含者 34 -> 34 通过。启动时警告 9 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、0 处去后缀（如 `cmds/imm/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/u/snow/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 29 处，返回类型/原型 36 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 2 个文件；改动 63 个文件，HEAD 与工作树各载入一次无回退（63 objects; HEAD PASS 63, tree PASS 63; regress 0; newly loading 0），这些文件的警告 67 -> 0。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 2 处多余的 `F_CLEAN_UP`（`adm/daemons/network/services/temp.lpc`、`kungfu/class/taohua/obj/cloth.lpc`），其余手工，能编译的文件警告清零；改动的 4 个对象在 HEAD 与工作树各载入一次，regress 0。

- `u/isle/ToMud/tomud.h` 重定义 `include/tomud.h` 已有的 `TMI`、`TMA`、`TMB`，先 `#undef`；`u/dream/panzi.lpc` 开头连写两个 `/*`，删去一个；`kungfu/skill/huashan-jian.lpc` 多余的 `;` 删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 3 处 `int power_point()`/`int hard_point()` 返回 1.3、1.75 之类的浮点，经 int 返回被截断；本库没有调用者，改成 `float` 返回值，保留原数值（`float_hooks.py`，KB 04 §6.10）。
- 2026-10-14：2 个存档文件（留言板 2 个；`data/board/wiz2_b.o`, `xyzx/data/board/wiz2_b.o`）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。13 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。8 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 8 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 6 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`beimin-shengong`→`beiming-shengong`（`/d/quanzhen_old/kungfu/skill/xiantian-qigong`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`jiuyin-baiguzhua`→`jiuyin-baiguzhao`（`jiuyin-baiguzhao/jiuyin`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`taiji-shenggong`→`taiji-shengong`（`taiji-jian/tongshou`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 文件首行注释少了一个斜杠（2026-10-15）

首行的说明注释只剩一个 `/`（如 `/kuangwu.c金蛇狂舞`、`/ cloth.txt  //`），文件第一行就语法错误、编译失败：全真教的布衣 `/d/quanzhen_old/obj/cloth` 因此从来载入不了。补回斜杠成为 `//` 注释，现在都能载入。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

5 个文件、10 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/cloth/cloth`、`/obj/weapon/blade`、`/d/gumu/obj/fuchen`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 4 个（4 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/复件 inventory.lpc`、`feature/move.lpc`、`feature/复件 move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（10 个名字，最多的是 `hunyuan-force`、`ruyi-blade`、`taxue-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 7 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/ring`（宏 `RING`）←xyzxfy2，37 个对象继承它，抽样 10/10 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 28 处、26 个文件：`kunlun-shnfa`→`kunlun-shenfa`（4 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`shaolin-shnfa`→`shaolin-shenfa`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）等共 17 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 2 处：`/clone/book/lbook5.lpc` 的 `query_autoload()`、`/clone/book/pixie_book.lpc` 的 `query_autoload()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 5 个 NPC 文件、5 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 5 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/quanzhen_old/obj/allow-letter.lpc`、`/d/quanzhen_old/obj/greenrobe.lpc`、`/d/quanzhen_old/obj/greyrobe.lpc`、`/d/quanzhen_old/obj/hanzhu.lpc`、`/d/quanzhen_old/obj/shenmu.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_bian.lpc`、`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen_old/npc/obj/m_sword.lpc`（共 6 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/cmds/skill/learn.lpc`：`write("你觉得精神好了一些，继续进行学习。\n")` 被注释吞掉
- `/cmds/skill/xue.lpc`：`write("你觉得精神好了一些，继续进行学习。\n")` 被注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 4 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/kungfu/skill/guxing-sword.lpc`（xyzx3）、`/kungfu/skill/huang.lpc`（bixiecanyang）、`/quest/murong/qlist3.lpc`（bixiecanyang）。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/kungfu/skill/kunlun-zhang.lpc`。修后与 HEAD 逐个对比载入：这 4 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 玩家买店用的 `feature/vendor_sale.lpc` 补回（2026-10-19，KB 03 §4.6 第四轮）

`/feature/vendor_sale.lpc`（`/kungfu/class/npc/xiaoer.lpc` 继承它）从 `pay_back` 起约 160 行的行尾丢了最后一个字符（`;` `)` `{` `}`，`else {` 只剩 `els`，`msg` 只剩 `ms`），另有一行 `if(wizardp(who) || getuid(who)==owner_id)` 被拼进了前面的 `log_file(` 调用里。文件载入失败，继承它的物件也跟着失败。别的库（ldtx、ldtxii、xhcii、syxjl、hy3）里有这个文件的完好副本，但那是另一个版本：没有作者后来加的投标公告（`string mesg;` 和 `message("channel:chat", ...)`）。所以按完好副本补回丢失的字符（`scripts/lpc_restore_from_twin.py --diff --extra`），公告两段原样保留；被拼到别处的 `if(...)` 放回完好副本里它所在的 `write("\n盈利` 之前；`message_vision("channel:chat", ...)` 多出来的第一个参数删掉（`message_vision` 的签名是 `(string, object, object)`，每次 `bid` 在扣完款之后都会报错）。补完后文件和继承它的物件都能载入，没有警告，也没有退步（HEAD 上两个都载入失败）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。
