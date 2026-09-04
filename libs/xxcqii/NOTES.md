
## WASM 修复摘要（迁移自 meta.json 的 group_note）

小雪初晴II（SnowMud），一款以温瑞安小说为题材的 MUD，是 117 号 xxcq（品牌名"大侠传奇之小雪初晴"）的手足档案。WASM 修复了 2 处各自独立的 §7.52 类 socket 精灵 bug：（1）adm/daemons/httpd.lpc，一个自成一体的网页服务器（JackyBoy@CuteRabbits Studio 移植），没有外部呼叫者——不仅掏空了每一个碰 socket 的函式，还按照最新的处理惯例彻底关掉了入口点：create() 不再安排 call_out("setup", 5)，也不再发出虚假的"网页服务器启动成功"提示。（2）adm/daemons/network/dns_master.lpc，一个真正的多用途 intermud 精灵（query_mud_name()/muds 映射/query_udp_port() 等被大约 28 个其它服务档案呼叫：mudlist_a/mudlist_q/gtell/gchannel/rwho/ping 等）——按照 AGENTS.md §7.52 对多用途精灵的明确例外处理，没有整个档案掏空，只掏空了两个碰 socket 的入口点（startup_udp() 现在只是回传 0，符合它自己既有的失败回传惯例，所以 create() 里的 'if (startup_udp()) init_database();' 会自然跳过依赖 socket 的数据库初始化，不需要改动其它任何代码；send_udp() 变成 no-op），另外还删掉了 send_shutdown() 里遗留的一处 socket_close() 呼叫。和 xxcq 不同，这份快照的 SECURITY_D 正确指向 /adm/daemons/securityd（不是 securd.lpc 那种硬编码播种模式），而且真的会在开机时读取 WIZLIST；adm/etc/ 目录本来就存在且带有真实数据（不像手足档案 xxcq 那样有目录缺失 bug）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已有 14 个账号，分布在 (admin)/(hufa)/(immortal)/(apprentice) 各阶层）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 选择→英文 id→y/n 确认创建→中文名字→临时密码+确认→接受天赋赠礼（y）→性别（m/f）→在武林盟起始房间的电子邮件注册闸门（register/zhuce 指令，或直接输入指定的中文短语才能继续）→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过"目前权限：(admin)"确认，fluffos 出现在一个正在进行的任务列表里，和其它管理员并列。LPC 格式化工具对全部 3034 个档案运行（写入 2976 个，28 个报错，30 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。唯一一个存在的 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

同一形状扩展到全库通用房间基类 `#define ROOM "/inherit/room/room"`：
删除 846 处多余的、独立成行的 `replace_program(ROOM);`（保留
`inherit ROOM;`）。此外，本库自带的房间建造工具
`clone/misc/roommaker.lpc` 有两套生成模板——"造一间空房间"的
heredoc 模板本来就是干净的，但"克隆我所在的房间"命令的字符串拼接
模板（第 138 行）把同一枚多余的 `replace_program(ROOM);` 直接烤进了
每一个用它克隆出来的新房间，已同步修正（删除该拼接片段，保留
`setup();`）。已用 `build-debug` 驱动干净启动验证（0 个新增编译
错误，端口正常监听）；未做完整 §10.7 深度游玩测试。

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

## 深度功能测试（2026-08-27，round two, AGENTS.md §10.7）

一次连续的真人视角游玩会话，用真实的原始 socket 脚本（非 tmux_mud.sh）
完成：注册中文角色苏晓雪(tstsnow) → 乘马车赶到华阳 → 徒步穿越 5+
个房间抵达浣花剑庐 → `ask jia ding about 拜师` 由家丁带路入庐 →
`bai li` 拜虎组组长李子木为师，正式成为"浣花剑派第六代弟子、虎组
组员" → `learn li force` 学艺成功 → 前往少林寺"穷武房"(kfroom_5)
用木人练功桩安全对练 11 轮，最终因反复测试而阵亡成"鬼魂" → 干净
`quit` 后 grep debug.log（全程无任何 error）→ driver 完整重启后
reconnect，确认角色属性、门派归属、师父、已学技能、位置全部正确
持久化。管理员账号也按 NOTES 记录的 fluffos/Mud@2026 重新走完整注册
流程验证（此前的 WASM 阶段存档并未留存在这份 work/ 树里），确认
"目前权限：(admin)"，落地在巫师公会。

发现并修复了 6 类程序性 bug（按 AGENTS.md 标准清单逐项排查后确认）：

1. **注册流程 debug 遗留 `printf("%O\n", ob)` 泄漏内部对象引用**
   （`adm/daemons/logind.lpc`/`logind1.lpc`/`logind2.lpc` 的
   `get_name()`，仅 `logind.lpc` 是 `LOGIN_D` 实际生效的档案，另两份
   是历史快照但一并修正保持一致）：每一个新注册玩家在设定中文名字
   之后，正式提示"请设定您的临时密码"之前，都会先看到一行裸露的
   `/clone/user/login#N` 内部对象路径。已删除该行调试语句。

2. **`inherit/skill/skill.lpc` 基类 `valid_learn()` 声明 0 参数，
   但全库 93/94 个技能档案（含 `kungfu/skill/force.lpc`）都用 1 参数
   `valid_learn(object me)` 覆写**：`force.lpc` 是唯一残留 0 参数版本
   的档案。这个不一致触发驱动的"Number of arguments... disagrees
   with previous definition"编译警告，且该警告会直接印在**触发首次
   编译的那个玩家自己的屏幕上**（`learn <师父> <功夫>` 第一次真正
   延迟编译某个技能档案时）。已将基类和 `force.lpc` 都统一成 1 参数
   形式；driver 重启后确认警告消失。

3. **AGENTS.md §7.11**：`adm/simul_efun/file.lpc` 的 `log_file()`
   没有调用同档案里现成的 `assure_file()`，本库从未随档发过
   `log/nosave/` 目录。已加上 `assure_file(LOG_DIR + file);`（连同
   一个前向声明，因为 `assure_file()` 定义在 `log_file()` 之后）。
   详见 AGENTS.md §7.11 新增条目。

4. **AGENTS.md §7.112 新实例**：`d/shaolin/kfroom_5.lpc`/`kfroom_6.lpc`
   （少林"穷武房"11 轮木人机关阵，每轮实发 `combat_exp`/`potential`）
   的 `init()` 完全没有防重入保护；`kfroom_1`~`4` 虽然有一次性入场
   旗标但没有"本轮正在进行中"的防护。已用真实的断线-重连复现实验
   （非清洁 `quit`，模拟真实掉线）确认修复前会在重连时叠加第二条
   完整的机关阵调用链（重复触发"机关开动了"横幅），修复后不再重复。
   6 个档案均已修正并用 `update` 热编译验证。详见 AGENTS.md §7.112
   新增段落。

5. **`feature/dealer.lpc` 的 `do_list()` 用整个键数组当映射下标**
   （`j = tmp[goods];` 应为 `j = tmp[goods[i]];`），导致**全库所有
   商人的 `list` 指令永远把实际持有的商品数量显示成 0**（在华阳
   打铁铺·刘铁匠现场确认："0件布衣" → 修复后 "1件布衣"，实际持有
   数量全程未变）。这是一处全新的、AGENTS.md 尚未收录的 bug 形状，
   已作为 §7.151 新增条目登记。

6. **AGENTS.md §7.86 新实例**：`d/kunming/dangpu.lpc`（当铺房间）和
   `d/kunming/obj/dpm.lpc`（当铺柜台）都是 `inherit SR_DANGPU;` 之后
   又多余调用一次 `replace_program(SR_DANGPU);`——本库先前的
   `ROOM`/`BULLETIN_BOARD` 专项扫描没有覆盖这个宏，属于漏网实例。
   已删除两处多余调用；`dangpu.lpc`（真正会被载入的房间）经
   `update` 验证编译干净。`dpm.lpc` 经全库搜索确认是**从未被任何地方
   引用的死代码**，且本身还带一个与这次修复无关的既存编译错误
   （`set_name()` 未定义，因为 `SR_DANGPU` 的祖先链里没有提供这个
   函数的物品/角色基类）——因为不可达且需要猜测原作者想再继承哪个
   基类，此项按"存疑不动"处理，只作为观察记录，未修复。

7. **AGENTS.md §7.152（新增条目）**：`clone/user/user.lpc` 的
   `reconnect()` 会正确恢复 `heart_beat`、清除 `netdead` 旗标，但
   **从未重新调用 `set_living_name()`**（不同于建号时 `enable_player()`
   会做的事）。用两个 socket 的隔离复现实验确认：任何玩家只要有过
   一次掉线重连（哪怕只隔 1.5 秒），在该次连线剩余时间内，
   `find_player()`/`find_living()` 驱动的所有功能都会找不到这个人——
   已现场验证 `tell <名字> ...`（真实玩家指令）和管理员 `call
   <名字>->...`（调试工具）两者都会报错"没有这个人"/"找不到指定的
   物件"，即使该角色明显在线、可以正常收发指令。已在 `reconnect()`
   开头补上与 `enable_player()` 相同的 `set_living_name()` 调用；
   干净重启后重新做同样的断线-重连复现实验，`tell` 恢复正常。**排查
   过程中的一个误报**：清洁 `quit` 后立刻（10 秒内）重新登录同一个
   ID 会被本库自己的防灌水机制拒绝（`get_passwd()` 里"你距上次退出
   仅 N tick"的检查，`adm/daemons/logind.lpc` 明确写出的既有设计），
   一开始误以为是另一个 bug，等够 10 秒以上再测就确认这是正常行为。

**结算与清理**：测试角色（tstsnow、以及排查过程中另建的 freshzz）
的存档和相关一次性 daemon 运行时状态（`emaild.o`、`data/SaveRoom/`）
已在提交前删除，只保留播种的 fluffos 管理员存档。`grep -h '"port"'`
端口唯一性检查、LPC 格式化工具（16 个改动档案，0 written/0 errors，
说明本次改动本身已符合格式规范）均已过。

**留给后续测试 `xxcqii2`（同属小雪初晴系列，很可能共享同一份引擎
代码）的排查清单**：以上 7 类里第 3～5、7 项（`log_file()`/
`assure_file()`、`kfroom_*` 防重入、`dealer.lpc` 的 `do_list()` 下标、
`reconnect()` 缺 `set_living_name()`）都基于共享 mixin/feature 档案，
如果 `xxcqii2` 复用了同一份代码，大概率会有同样的问题，建议优先
核对这几个档案。

## Shop (2026-09-04)

2026-08-27 already did 浣花 `bai li` (on tstsnow, later deleted) and
fixed dealer `list` at 华阳打铁铺 (`0件布衣` → `1件布衣`). That pass
never paid for a catalog item. This pass: native port **40131**, first
send **`g`**, admin `fluffos`/`Mud@2026` (云天明, 【天神】). `goto
/d/bianliang/sanhelou`, `list` still `1件布衣` + 烤鸡腿 八十文.
Cloned 一两白银, `buy jitui` → 买下烤鸡腿, leftover 二十文铜板.
拜师 not re-run.

**Bug ported.** `inherit/room/room.lpc` `make_inventory()` lacked the
`objectp` guard after `new()` (same sibling shape as `xxcq` /
`xxcqii2`). Added `if (!objectp(ob)) return 0;` plus the two `reset()`
`objectp` checks. CRLF preserved.
