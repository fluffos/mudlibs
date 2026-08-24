
## WASM 修复摘要（迁移自 meta.json 的 group_note）

三界神话「测试二区」，5 档案 sjsh 家族集群的第三个；这个变体的 sited.lpc 本来就无条件允许回环连线（没有仅限巫师的闸门），不像 sjshv150。WASM 修复：（1）§7.60 master.lpc log_error()/standard_trace()→CHANNEL_D 编译期崩溃，两处都用 find_object(CHANNEL_D) 守卫。（2）修好（1）之后让 CHANNEL_D 真正加载会暴露出的一个新的、§7.61 相邻的 bug：channeld.lpc 的 do_channel() 无条件呼叫 environment(me)->query("no_chat")，没有检查 environment(me) 是否非空——当 do_channel() 被呼叫在一个没有 environment 的物件上时（比如 master.lpc 自己的 this_object()，经由 log_error() 自己的 CHANNEL_D 广播一个被捕获的 connect() 错误）就会崩溃报"Bad argument 1 to EFUN call_other()"——已加上 environment(me) 真值判断守卫。（3）§7.61 message() simul_efun 包装函式缺少 exclude||({}) 守卫，和 sjshv150 相同。（4）§7.41 类损坏的 emoted.o，同样的 catch(restore()) 修法。（5）§8.1 类的 is_chinese() 字节区间 bug，同时出现在 adm/daemons/chinesed.lpc（CHINESE_D 委托的真正实现）和 logind.lpc 的 check_legal_name() 里的 i%2 奇偶门槛（和 sjshv150 相同的 UTF8 vs GBK 字节配对不匹配）——两处都已修成码点区间/逐字符检查。这份快照里没有 convertd.lpc（档案不存在）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。已验证：完整注册（new→id→管理密码→确认→普通密码→确认→名字→电子邮件→性别）每一步都干净推进，没有任何意外错误；default_trusted_write ACL 已直接核对源码确认授予 (admin) 不受限的"/"访问权限（脚本化测试因为计时/刷屏差异没能捕获到确切的权限显示确认，这是这个家族手足档案里已经记载过的、不阻断的测试工具限制）。LPC 格式化工具对全部 12494 个档案运行；还原了 3 个确认有 CJK 重新加空格损坏的档案（2 个和 sjsh/sjshv150 共享，另加一个重复副本），通过"去空格后比对旧档案"扫描（覆盖 138 个格式化工具触碰过的档案）找到；另外直接比对了两个 map.lpc 档案——干净，只是排版调整。格式化后重新验证过，干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 97 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

用原生驱动（`build-debug/src/driver`，端口 40125）通过 `scripts/tmux_mud.sh` 走完整轮，对照同家族已深挖的 `sjsh`（宝鸡站）/`sjshv150`（紫藤分站）NOTES.md 逐条核对候选 bug。

- **§7.97（sjsh 上发现的 LISTNODES 死亡死循环 bug）——不适用，已核实排除**：`work/include/net/config.h` 第 19 行 `#define LISTNODES ([ \` 本身就带着正确的续行反斜杠（`cat -A` 确认行尾是 `\^M$`，不是裸 `^M$`）——这份档案的 `LISTNODES` 表项是 `"CS": "220.114.15.55 6668"`，和 sjsh/sjshv150 都不同，说明这个头文件在三份档案里各自独立维护、并非逐字节同源。为求实证而非只信静态分析，仍然用管理员测试角色在朱雀大街对 `疥顶小僧`（`d/city/npc/jieding.lpc`，id 用 `xiaoseng` 才能命中——`kill jieding` 本身会因为该 NPC 没有把 `jieding` 单独注册为 id 而被拒绝为"这里没有这个人"，这是本档案自己的 id 命名细节，不是 bug）打 `kill xiaoseng` 到真实死亡：屏幕只打印一次"你死了"，系统频道正常广播"〖谣言〗某人：紫电仙人在长安城被疥顶小僧杀死了。"（`log/NK_LOG`、`log/death` 两份日志同步确认），角色被送进〖阴阳界〗（`/d/death/gate`），判官崔珏（朱笔判官 崔珏）自动完整走完"莫乱跑→生死有命→翻生死簿→命不该死送还阳"对话，角色活着落地复活室〖荒郊小店〗（`/d/ourhome/kedian`），全程 `log/debug.log`、`work/log/err.log` grep `dns_master`/`gchannel`/`No program in object` 均为零命中。确认本档案没有这个 bug。（注：战斗中途"逃跑失败"两次触发了随机传送到相邻房间的既有机制——不是本次要修的死亡循环，属于战斗系统本身的既定行为。）

- **（新增 AGENTS.md 记录，非新 bug）§8.13 在本变体上不适用，而且是这份档案自己已经提前修好的形状，值得记录供家族对照**：`sjshv150` 上发现的"WIZ 密码二次登录死锁"（`get_wizpwd()` 在密码从未设置时既不放行也不重新 `input_to()`，静默卡死）在这份档案里**没有出现**，因为 `adm/daemons/logind.lpc` 第 18 行本来就有 `#define NO_CHECK_WIZPWD`，`get_wizpwd()` 对应分支是：
  ```lpc
  if (!user->query("wiz_password")) {
  #ifdef NO_CHECK_WIZPWD
      write("请登陆后用wizpwd来设定你的巫师密码！\n");
      check_ok(user);
  #else
      ...destruct(user); ...
  #endif
      return;
  }
  ```
  `NO_CHECK_WIZPWD` 已经定义，所以未设置 WIZ 密码时会打印提醒后正常 `check_ok(user)` 放行，而不是像 sjshv150 那样直接卡死。用管理员账号 `fluffos` 实测验证：注册当次会话完全不会走到这段代码（和 sjshv150 的发现一致，只有重连才会碰到）；重新连线（用 `quit -lovesjsh` 正常退出保存后，新开一条连线重连，走完 id + 普通密码流程）后看到"请输入相应的WIZ密码』如果你还没有设定巫师密码，请输入回车继续"提示，直接回车后打印"请登陆后用wizpwd来设定你的巫师密码！"，随即正常进入游戏（落地〖巫师会议厅〗，`look` 显示正常，"系统权限目前是：总管巫师(admin)"），没有任何卡死。结论：这份档案独立于 sjshv150 就已经用一个 `#ifdef` 开关规避了这个 bug 形状，§8.13 记录的问题不适用于本档案，无需移植修复。

- **测试踩坑记录（不是程序 bug，是这份档案自己的既定反滥用设计，记录下来避免下次重蹈覆辙）**：本档案 `cmds/std/quit.lpc` 有一条"新建账号未连续在线满 10 分钟（`mud_age < 600`）就退出会被删档"的规则，`quit` 命令本身会先弹出 y/n 确认；但 `obj/user/user.lpc` 里巫师账号的净断线（net_dead）超时被特意设成 1 秒而非普通玩家的 600 秒（`call_out("user_dump", wiz_level(me) ? 1 : NET_DEAD_TIMEOUT, DUMP_NET_DEAD)`），断线后几乎立刻触发 `QUIT_CMD->force_quit()`——而 `force_quit()` 对"未满 10 分钟"的判断**没有** `quit` 命令那样的 y/n 确认，直接静默删档（`cmds/std/quit.lpc` 第 198 行附近，注释写着"避免利用断线保留档案"）。第一次给 `fluffos` 播种时因为用 `tmux stop` 直接掐断连线（模拟断线）而不是走 `quit` 流程，账号在几乎注册完成后立刻被这条规则删除，`data/login/f/`、`data/user/f/` 都没有留下任何文件（确认过：不是 bug，是设计意图明确的反小号刷号机制）。第二次重新播种时改用 `quit` 命令自带的 `-lovesjsh` 参数（`arg != "-lovesjsh"` 检查允许绕过 10 分钟限制），干净存盘成功。后续所有测试（含本条新增的 §8.13 排除验证）均基于这次成功播种的存档。给未来的重新播种/测试留一句话：**巫师账号测试全程都必须用 `quit -lovesjsh` 正常退出，绝不能直接掐断连线，否则十分钟内断线会被这份档案自己的反滥用逻辑连档一起删掉。**

- **§7.34（logind.lpc 遗留 debug printf）适用，已修**：`get_name()` 在 `ob->set("name", arg)` 之后紧跟着一行裸 `printf("%O\n", ob);`（第 776 行），会把登录对象内部路径（`/obj/user/login#1 ("0-fluffos")`）原样打印在中文名字确认和邮件地址注册提示之间——用 `fluffos` 账号首次注册时现场复现确认。已删除该行；重启驱动后用同一个 `fluffos` 账号重新连线，全程 grep 输出确认没有任何 `login#`/`obj/user` 字样泄漏。LPC 格式化工具（`~/src/fluffos/tools/lpc-syntax/bin/format-corpus.mjs`）对改动文件单独跑过，`unchanged`（无需重新排版），§9 三个盲点检查（`::` 误切分、`case`+`//`注释吞并、CJK 被拆空格）均无命中，`git diff --stat` 确认只有这一行删除。

- **§7.11（log_file 缺 assure_file 防护）不适用，已提前修好**：`adm/simul_efun/file.lpc` 的 `log_file()` 转发给 `MONITOR_D->log_file()`（`/adm/daemons/monitord.lpc`），而 `monitord.lpc` 自己的 `log_file()` 实现已经是 `file = LOG_DIR + file; assure_file(file); write_file(file, text);`——防护本来就在，和 sjsh/sjshv150 那种裸 `write_file()` 无防护的形状不同（本档案的 `adm/simul_efun/file.lpc::log_file()` 本身只是一层转发，真正的落地实现在 `monitord.lpc` 里）。`monitord.lpc` 的另外两个写入点（`log_wiz()`、`mudring_log()`）也都各自有 `assure_file()` 前置调用。确认无需修复。

- **§8.9（食物/饮水初始化）不适用**：`confirm_gift()` 直接 `user->set("food", user->max_food_capacity())`/`user->set("water", user->max_water_capacity())`，没有对象混用、没有年龄闸门。测试角色 `score` 食物/饮水均显示"很饱"/"正常"（满格）。

- **§7.88/§7.12（message() varargs 缺陷）不适用，此前一轮已修好**：`adm/simul_efun/message.lpc` 第 234-236 行的 `message()` 已经是 `efun::message(arg, message, target, exclude || ({}));`（对应 group_note 里记载的 §7.61 修复），`message_vision()`/`message_combatd()` 内部所有 `message()` 调用都带够参数。本轮死亡广播、频道消息（谣言频道、天地劫剧情广播）等大量触发 `message()`/`tell_room()` 的路径全程零崩溃，确认修复依然有效。

- **§8.3a（`private nomask command_hook`）不适用**：`feature/command.lpc` 第 35 行 `command_hook()` 声明就是 `nomask int command_hook(string arg)`，没有 `private`（第 34 行还留着一条注释掉的旧声明 `// protected nomask int command_hook(string arg)`，说明这条修复在更早的一轮就已经存在）。

- **§8.3b（`commandd.lpc` 的 `.c` 后缀 sscanf）不适用**：整个档案没有 `commandd.lpc` 这个文件，指令分派走 `feature/command.lpc` 的 `add_action` 机制。

- **§7.90（eval cost 上限）本次未观察到问题，`config.fluffos` 保持项目默认 `700000` 未改动**：跨越注册、天赋分配、多次移动到未编译过的房间（朱雀大街、十字街头等）、真实战斗到死、完整复活流程、`post`/`read`/`update`（触发 `/d/city/kezhan.lpc` 首次重编译）等操作，`log/debug.log`、`work/log/err.log` grep `cost limit reached`/`Too long evaluation` 均为 0。

- **§7.5（securd/securityd 自定义 ACL 拒绝编译期访问）不适用**：全程注册、战斗、死亡、复活、`post`、`update`（recompile）等触发大量首次编译/首次读取的路径，`log/debug.log`、`work/log/err.log` 均无任何 "access denied"/"Read access denied" 记录。

- **§7.98（daemon `create()` 缺 `seteuid()` 导致自身配置读取被拒）不适用**：全程 `log/debug.log` 没有出现任何 preload 期的 `explode()`/`sscanf()` 崩溃（驱动启动日志本身也完全干净，只有大量无害的 `Unknown #pragma`/`Unused local variable` 编译警告）。

- **管理员写权限已现场验证**：用 `fluffos` 账号执行 `update /d/city/kezhan`，输出"重新编译 /d/city/kezhan.lpc ...成功！"，确认 `default_trusted_write` 对 `(admin)` 授予的不受限写入权限确实生效。

- **留言板 `post`/`read` 验证通过，§7.86 修复线上确认有效**：在〖荒郊小店〗对"生死之间留言板"（`obj/board/common_a.lpc`）成功 `post` 一条标题「deep-test」的留言并 `read 1` 读出，无崩溃，同一条内容还自动镜像进了〖巫师会议厅〗留言板总汇（`post_b.o`，和 sjshv150 记载的转发机制一致）。这两份留言板数据此前完全未随仓库分发（`git status` 确认 `data/board/` 之前不存在），测试产生的两个 `.o` 文件（`post_b.o`、`common_a.o`）已在提交前直接 `rm` 掉，不影响任何真实历史内容（本档案确实没有 sjsh 那种历史留言）。

- **发现一处死内容，确认无害未处理**：`d/wiz/entrance3`（没有 `.lpc` 后缀）是一份带 `inherit BULLETIN_BOARD;` + 多余 `replace_program(BULLETIN_BOARD);`（旧 §7.86 崩溃形状）的旧版留言板源码，和真正在用的房间/留言板文件 `d/wiz/entrance3.lpc`（ROOM）、`obj/board/newbie_b.lpc`（已经是干净的、没有多余 `replace_program()` 的新版）是两份完全不同的文件。全档案 grep 不到任何代码路径引用不带后缀的 `/d/wiz/entrance3` 作为编译目标（唯一引用它的地方是 `newbie_b.lpc` 里 `set("location", "/d/wiz/entrance3")`，那只是给留言板留的地点标签字符串，不会触发编译）——是历史换版遗留的死文件，不会被驱动加载，§7.86 的扫描/修复不需要碰它，按既定"保留死内容、不主动删除"的项目惯例原样留着。

- **未覆盖**：`buy`/商店购买流程本轮时间有限未测；帮派/门派拜师流程未触及；`WIZPWD` 指令本身（设置 WIZ 密码后的校验分支）未实测，只验证了"未设置时不再卡死"这一路径。这几项风险较低（`WIZPWD` 校验逻辑本身是简单的 `crypt()` 比对，`§8.13` 的实测已经覆盖了唯一有卡死风险的分支），留待下次深挖时一并验证。

管理员账号（`fluffos`/管理密码 `Mud@2026`/普通密码 `Mud@2027`）本次通过正常注册流程重新走了一遍——`adm/etc/wizlist` 里已有 `fluffos (admin)` 一行（更早的 WASM 阶段播种），但存档目录下当时并没有真正落地的 `fluffos.o`（说明此前只播种了权限数据，账号从未真正注册过）；本次完整走完双密码注册流程后立即显示"系统权限目前是：总管巫师(admin)"，`update` 验证写权限正常。见上文"测试踩坑记录"：第一次注册因为用掐断连线的方式测试断线场景，被这份档案自己的反小号删档规则删掉，第二次改用 `quit -lovesjsh` 正常退出后才成功保留存档——README 已同步更新为具体密码（此前写的是"注册时自设"）。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：与 `xyj20032` 同构，`work/` 下 1,183 处存活匹配。脚本删除了
  1,180 处标准独立行；另外 3 份房间生成工具（`obj/misc/roommaker.lpc`、
  `obj/obj/roommaker.lpc`、`obj/obj/misc/roommaker.lpc`，字符串拼接变体）
  手动修复。`data/` 下额外核查过，无命中。验证：真实 debug 驱动干净编译
  启动、端口正常监听，`debug.log` 无新增 "cannot replace"/错误行。

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

## 深度功能测试第四轮（2026-08-23）— 补齐前一轮"未覆盖"的三项

用真实驱动（`~/src/fluffos/build/src/driver`，端口 40125）通过 `scripts/tmux_mud.sh`
补齐前一轮记录在"未覆盖"里的 `buy`/拜师/`WIZPWD` 校验分支三项，同时对照
本 session 在 `sjshwzb`/`sjshwzjqb` 两个同家族手足档案上发现的两个真 bug
做移植排查。

- **combatd.lpc killer_reward() 的 PKD/DIE 缺失 bug——不适用，已确认排除**：`sjshwzb`/`sjshwzjqb`
  上发现的"`killer->add("PKS", 1);` 之后缺 `killer->add("PKD", 1); victim->add("DIE", 1);`
  两行，导致 score 的『被杀害』计数永远不增长"这个 bug 形状在本档案（`work/adm/daemons/combatd.lpc`
  第 994-995 行）**本来就有** `victim->add("DIE", 1);`（只是没有紧跟着的 `killer->add("PKD", 1);`）。
  进一步核对发现 `PKD` 这个统计键在全档案（含两个手足档案）都没有除 `combatd.lpc` 自身之外的
  读取点——真正驱动 score 显示的是 `DIE`（普[..]位、总[..]位杀害计数），而本档案的 `cmds/usr/score.lpc`
  『杀害记录』一行本身就只显示"杀害玩家：普[]黄[]总[]位，杀死敌人：[]位"，**根本不显示"被杀害"次数**
  （和 sjshwzb 的 score 格式不同，本档案是独立的显示格式）。所以两个手足档案上那个"被杀害计数卡在 0"
  的具体症状在本档案不存在——既没有对应的可见字段，DIE 计数本身也已经在正确递增。确认不需要移植修复。
- **`d/lingtai/obj/shengmao.lpc` 未闭合字符串 bug——文件不存在，不适用**：本档案压根没有
  `d/lingtai/obj/shengmao.lpc` 这个文件（`d/lingtai/` 目录下没有任何 `shengmao*` 文件），
  不是"文件存在但字符串已经修好"，是这份快照原本就没有这个物品档案。无需处理。
- **发现一个独立的、真实的 compile-crash bug（不在原始核对清单里，是本轮探索路上撞到的）：
  `d/sea/npc/beast1.lpc` 有两处损坏，级联触发"天地劫"世界事件生成怪物时崩溃**——
  在世界事件（"天地劫"，游戏内定时触发的门派沦陷剧情，会调用 `disasterd.lpc` 批量
  `copy_npc()` 生成/搬运各地怪物）巡到东海龙宫附近时，现场触发了
  `执行时段错误：*No program in object '/d/sea/npc/beast1'!`：
  1. 文件末尾（第 75 行，`}` 闭合大括号之后）有两个孤立的 U+FFFD 替换字符（`\xef\xbf\xbd \xef\xbf\xbd`），
     不在任何字符串或注释内，触发 `error: Illegal character 0xef` / `syntax error, unexpected invalid token`，
     导致整个文件编译失败（"No program in object"）。这是一段游离在函数体外的纯垃圾字节，删掉不影响任何逻辑。
  2. 修好（1）之后暴露出第二层：`set("race", "...")` 的值本身也被同一种编码损坏污染成
     `\xd2\xb0`（GBK『野』）+ 两个 U+FFFD——`adm/daemons/chard.lpc` 的 `setup_char()` 对
     `race` 做 `switch`，"人类"/"妖魔"/"野兽"是仅有的三个合法值，损坏后的字符串匹配不上任何
     一个，落入 `default: error("Chard: undefined race " + race + ".\n")`，未被外层 `disasterd.lpc`
     捕获，直接中断该 NPC 的 `create()`。凭『野』字前缀在"人类/妖魔/野兽"三选一里唯一对应
     "野兽"（且该 NPC 本身就是 `d/sea/npc/beast1.lpc`——文件名和用途都指向"野兽"这个种族），
     以及后续 `set("long", ...)` 等其它字段同样是同批次 GBK→UTF8 转换损坏的产物（未受影响，
     因为在字符串内部，driver 不校验字符串内容合法性），判定这是可以安全、无歧义修复的编码
     损坏，恢复为 `set("race", "野兽")`。两处都改完后 `update /d/sea/npc/beast1` 打印"成功！"，
     不再有编译错误或运行时 `error()`。这是本 session 在同一份"游离字节+损坏字符串导致 switch/default
     崩溃"这条 GBK 转 UTF8 损坏链路上遇到的一个新变体，和 group_note 记载的『3 份 CJK 重新加
     空格损坏档案』是不同的损坏形态（那批是排版工具误插空格，这份是原始转码时替换字符残留）。
     只修了这一个文件，未做全库同类扫描（时间有限，留给未来一轮）。
- **`buy` 补测通过**：在〖荒郊小店〗对店小二（`d/ourhome/npc/xiaoer.lpc`，id 是 `xiao`/`xiao er`/
  `waiter`，不是 `xiaoer`）克隆一个"白银"（`obj/money/silver.lpc`，`base_value` 100 文）后
  `buy 1 jitui from xiao`，`list` 显示炸鸡腿单价 80 文，成交后 `i` 确认背包里多了『炸鸡腿』
  和找零『二十文铜钱』（100-80=20，找零金额正确），无崩溃。测试后 `drop` 掉两件物品清理干净。
- **拜师流程补测通过**：`d/shushan/tower.lpc`（镇妖塔）里的『蜀山剑派入门弟子 李逍遥』
  （`d/shushan/npc/lxy.lpc`）`attempt_apprentice()` 无条件接受，`apprentice li` 后完整走完
  "磕头拜师"对话，`score` 确认『师承』字段从『未入师门』变成『李逍遥』、职称栏也同步显示
  『蜀山剑派第六代弟子』。未测试拒绝分支（本档案没找到一个"总是拒绝"的现成 NPC，
  不影响判定——接受路径本身就是关键的可写状态变更，已验证正确落地）。
- **`WIZPWD` 校验两个分支补测通过**：用 `fluffos` 账号 `wizpwd` 指令首次设定巫师密码
  （`TestWiz123`，旧密码留空放行，因为当时 `wiz_password` 还未设置——`get_old_pass()`
  对未设置密码的情况不做旧密码校验，符合预期）后，`quit -lovesjsh` 正常退出，用两条
  独立连线分别验证：（a）故意输错密码→打印『密码错误！』随即断线；（b）输入正确密码
  `TestWiz123`→打印『密码正确！』正常进入游戏。`crypt()` 比对分支本身没有 bug，
  上一轮记录的『未设置时不再卡死』和这一轮补测的两个校验分支加起来，`WIZPWD` 全流程
  已经完整覆盖。

结论：本轮补测三项全部通过（`buy`、拜师、`WIZPWD` 两个校验分支），两个手足档案上
的已知 bug 都确认不适用于本档案（一个是本档案本来就没有该 bug 症状，一个是文件根本
不存在），额外发现并修复了 `d/sea/npc/beast1.lpc` 的双重编码损坏 compile-crash bug。
