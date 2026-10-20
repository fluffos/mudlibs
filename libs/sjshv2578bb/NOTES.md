
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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 73 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

same as `sanjieshenhua` (same lineage): `feature/damage.lpc`'s `revive()` call is dead/commented, but `d/qujing/qujingren/qujingren.lpc`'s `wakeup()` calls `me->enable_player()` on a still-`living()` disabled object. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 more block(s) repaired: 1 with the terminator spelled in another case than the opener (`@MING_PART ... MING_part`: the lexer compares case-sensitively, so the block never ended): `d/obj/club/bihai_mark.lpc`.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply sjshv2578bb`: 58 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 81 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 8 PASS -> 41 PASS, 0 that loaded before fail now, 33 more load.

58 files moved (58 `.C`); mostly under `d/quest/fangzhudao` (46), `d/quest/digmoney` (3), `d/9ct/npc` (2), `d/quest/newequip` (2). A rescan with `scripts/lpc_warnings.py sjshv2578bb` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 306 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `cmds/std/team/party.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt sjsh sjshv2578bb` 把 sjsh 警告整理提交里的改动搬到 369 个修改前与它一致的文件（304 个按块拼接；逐文件核对非 ASCII 文字：除 sjsh 自己删掉的以外没有丢失或改动）。剩下的再跑 `scripts/lpc_warnings.py sjshv2578bb --fix`：无用局部变量 2187 个、转义 91 处、`varargs` 63 处、`nosave` 函数 3 个改 `protected`（1 个去掉）；`scripts/lpc_fix_no_effect.py --apply`：两份 `xuanyuan-archery.lpc` 删去 `(: throw_weapon :);`，`dns_master.lpc` 把 `#if PREF_* & SVC_TCP` 移到 `if` 外面。共改动 1374 个 `.lpc` 和若干 `.h`。
手工（与 xyj20032 相同的三处）：`adm/daemons/natured.lpc` 删去空语句 `lt[LT_MON];`；`securityd.lpc` 删去没用到的 `string ip = query_ip_number(ob);`；`channeld.lpc` 只在 `#ifdef XYJ` 分支用的局部变量，声明挪进同样的条件里。
HEAD 与工作树分别加载（新进程）：1336 -> 1336 通过，无回退；改过的头文件的 496 个包含者 473 -> 473 通过。`d/gumu/npc/zhangmen.lpc` 是编译不过、没人引用的旧稿（古墓掌门用 `obj/zhangmen/gumu.lpc`），未动。

启动时警告 115 -> 0；新进程登录正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 41 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 14 个，只在 #if 分支用的声明移进分支 0 个文件；改动 53 个文件，HEAD 与工作树各载入一次无回退（53 objects; HEAD PASS 52, tree PASS 52; regress 0; newly loading 0），这些文件的警告 75 -> 20。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 4 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/cmds/skill/exercise.lpc`（`force_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 wuhanzhan/xlqy_early 同源同修）：
  - `d/kaifeng/ground.h` 加 `GROUND_TABLES_INHERITED` 守卫；`colors.h` 加防重复包含。
  - `jiasha.lpc` 的 `init()` 先后调用 `cloth::init()` 与 `unique::init()`。
  - `yaoguai_type` 的重复声明去掉。
  - `feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`（与 NPC 自己存档的同名字段分开）。
  - `lijing`/`xiwangmu` 的 `die`/`unconcious` 和 `yutu`/`jinren` 的 `kill_ob` 改 `void`。
  - `reporting.lpc` 未用的 `str` 删去；`roommaker` 被覆盖的 `special_props` 表删去；没有定义的 `int long();` 原型删去。
  - 改动的对象 HEAD 与工作树各载入一次，无回退。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：2 个对象，新增载入 2，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。4 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

6 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。本库人物只有 kee/sen（连 gin 也没有）：药物的 `receive_heal("gin", 60)`、NPC 的 `receive_curing("gin", ...)` 和来自侠客行体系的 qi/jing 调用都报 `伤害种类错误`。7 个文件按 gin→sen、qi→kee、jing→sen、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/linghai/shishi2`、`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`qiusheng-blade`→`qiushen-blade`（`/d/wizz/passion/siqi`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

18 个文件、20 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/armor/密林青衣`、`/d/leox/weapon/pa`、`/obj/longsword`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 18 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 2 个，改后 2 个，没有退步。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（11 个名字，最多的是 `fumobashi`、`mizongbu`、`bite`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 6 个通过，其余 1 个停在别的错误上（`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/jjf/front_yard` 的 `down`：`/d/quest/m_weapon/lianfushi` → `/d/quest/weapon_bk/lianfushi`；`/d/jjf/front_yard` 的 `up`：`/d/quest/m_weapon/lianmaceshi` → `/d/quest/weapon_bk/lianmaceshi`；`/d/lingtai/forrest2` 的 `south`：`/d/quest/m_weapon/liangunshi` → `/d/quest/weapon_bk/liangunshi`；`/d/moon/neartop` 的 `north`：`/d/quest/m_weapon/lianbianshi` → `/d/quest/weapon_bk/lianbianshi`；`/d/nanhai/tingjing` 的 `east`：`/d/quest/m_weapon/lianzhangshi` → `/d/quest/weapon_bk/lianzhangshi`；`/d/qujing/kusong/kusongjian` 的 `west`：`/d/quest/m_weapon/lianqiangshi` → `/d/quest/weapon_bk/lianqiangshi`；`/d/qujing/wudidong/dong` 的 `up`：`/d/quest/m_weapon/liandaoshi` → `/d/quest/weapon_bk/liandaoshi`；`/d/qujing/wuzhuang/juyuan` 的 `up`：`/d/quest/m_weapon/lianchuishi` → `/d/quest/weapon_bk/lianchuishi`；`/d/shushan/shanjiao` 的 `east`：`/d/quest/m_weapon/lianjianshi` → `/d/quest/weapon_bk/lianjianshi`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/u/helpler/npc/clubdd_master`←sjshv150，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 30 处、30 个文件：`lahua-shou`→`lanhua-shou`（10 处）、`dagonforce`→`dragonforce`（7 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`yange_blade`→`yange-blade`（2 处）、`dragon-step`→`dragonstep`（2 处）、`kongming--steps`→`kongming-steps`（1 处）、`changqaun`→`changquan`（1 处）、`lingyi-sword`→`liangyi-sword`（1 处）等共 12 个名字。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 5 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill_bk/boxing.lpc`、`/daemon/skill_bk/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 1 处：`/d/pkdao/room1.lpc` 的 `greeting()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 和包含文件同目录的头文件，改成引号形式（2026-10-19，KB 04 §6.17）

2 个文件用尖括号写 `#include <hedi.h>` 这类头文件（`banned.h` 等），头文件其实就放在它们自己的目录里。老驱动对尖括号名字也会先找包含文件所在目录，本驱动只找 include 路径，所以报 `Cannot #include ...`，整个物件载入不了。改成 `#include "hedi.h"`（引号形式相对包含文件解析，预加载、`lpcc` 和运行时编译都一样）。（`scripts/lpc_fix_local_include.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `d/quest/fangzhudao/kezhan.lpc`：`int block_cmd(string);` 声明和后面定义的参数个数不一致，声明删掉；`d/quest/fangzhudao/shandong.lpc`：`int valid_leave()` 盖掉基类带参数的 `valid_leave(object me, string dir)`，改成 `varargs int valid_leave(object me, string dir)`，函数里的 `this_player()` 改读 `me`（没传时仍取 `this_player()`），`::valid_leave(me, dir)` 把参数传给基类（与 xyj20032 同一处修改）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：离开时清除“砍柴”标记只在往北走时才生效，往南不清。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/wizz/stey/npc/robber.lpc`（1 处）、`/d/lingtai/forrest2.lpc`（1 处）。
