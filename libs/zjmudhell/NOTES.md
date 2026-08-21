
## WASM 修复摘要（迁移自 meta.json 的 group_note）

从 zjmud.7z（指间mud服务器+手机版客户端.zip）里嵌套的一个 zip 中提取，内部文件夹字面命名为 'hell'——和已有的 hell/zjdywzb 世纪家族无关，master 哈希不同。修复了 efun::message() 因 exc_target=0 被拒绝的问题；创建了缺失的 /log/nosave 目录。同样是 shujian3 血统的手机 app 协议和自定义 logind.lpc。需要完整的 WASM 修复：（1）crypt(ZJKEY, 0) 客户端握手的非确定性问题（AGENTS.md §7.14）——已修复为 crypt(ZJKEY, "zj")，和 zjdyzj 一样；和 shujian3 不同，这份档案里 get_user() 中基于 crypt 的密文检查没有被注释掉，也没有逗号到 ║ 的便利替换，所以注册需要字面的 ║ 分隔符和真实的 id/密码密文（crypt(ZJKEY,id)+crypt(ZJKEY,密码)）；（2）经典的 §8.1 GBK 字节区间 is_chinese() 检查修复成 CJK 码点区间；（3）clone/user/user.lpc 的 accept_kill() 里 is_killing() 物件对字符串参数不匹配（§7.50，这是第三个撞上这个 bug 的血统）；（4）按 §7.52 掏空了三个纯 socket 精灵（versiond.lpc——create/in_server/connect_server/send_command 等一共 12 个函式，不像之前那条笔记说的那样"保持原样"，因为它实际上在运行时破坏了 questd.lpc 的 collect_all_quest_information()；payd.lpc 的 HTTP 支付回呼；adm/daemons/network/dns_master.lpc 的 intermud UDP 层）。管理员（fluffos/Mud@2026）通过真实注册加 adm/etc/wizlist 播种。score 对刚创建的角色正确地被一个'born'标记挡住（游戏设计如此，不是 bug）——改用 look+quit 验证。

## 深度功能测试（§10.7，2026-08-08）

本次先按 AGENTS.md §11 通读了 `zjmudhell` 自己的 README（"核心系统改写、
地图原样保留"血统关系）以及同一份手机 App 协议血统的 `shujian3`
README/NOTES.md，逐条对照其已知 bug（§7.68 复活软锁、commandd.lpc
`.c` 后缀死循环、securityd.lpc `valid_read()` 误伤等），但**不**假设
移植——每一条都在 `zjmudhell` 自己的代码里单独核实。

- **`/log/nosave` 目录问题：不是"已创建但可能丢失"，是代码本身缺失
  防护，本次已根治（AGENTS.md §7.11 新增确认实例）**。`adm/simul_efun/
  file.lpc` 的 `log_file(string file, string text)` 一直是裸的
  `write_file(LOG_DIR + file, text)`，没有调用同一份文件里两个函数之
  后就定义的 `assure_file()`（这份代码库里 `channeld.lpc`/
  `examined.lpc`/`versiond.lpc`/`securityd.lpc`/多个 `adm/npc/*.lpc`/
  `cmds/arch/{punish,restore}.lpc` 都已经在正确使用这个 helper）。
  `clone/user/login.lpc` 的 `logon()`——每一条新连线最先执行的函
  数，版本握手横幅打印之前——会无条件调用
  `log_file("nosave/logon", ...)`。当前 `work/log/nosave/` 目录之所
  以还在磁盘上，只是因为上一轮 WASM 排查时意外创建过、后续会话一直
  没有清空过——它从来没有被 git 追踪（`.gitignore` 把整个
  `libs/*/work/log/` 当成驱动每次启动都会重建的运行时状态排除掉，和
  `debug.log` 一个待遇），所以这个隐患一直没有真正暴露。**live 复现
  确认**：把 `work/log/nosave/` 临时改名挪走，用未修复的代码重启驱
  动、发起一条全新连线——连版本握手横幅 `ver1.0,...` 都没有打印出
  来，连线直接卡死。修复（在 `write_file()` 前加
  `assure_file(LOG_DIR + file);`）后，同样的"目录不存在 + 全新驱动
  进程"场景下连线正常完成，`log/nosave/` 被自动重新建出来（用
  `ls`/`git status` 核实过，时间戳是刚刚，内容只有这次会话自己写
  的两个文件）。修复过程踩到和 `xajhxo`（§7.11 原文）完全一样的坑：
  `assure_file()` 在这份文件里是定义在 `log_file()` **之后**的，不
  加前向声明整个 `simul_efun`/`master` 编译直接失败（`No program in
  object '/adm/single/simul_efun'!`，硬启动中止，不是警告）——补一行
  `void assure_file(string file);` 前向声明后编译恢复干净。已把这个
  新确认实例记入 AGENTS.md §7.11（这是继夕阳再现/XYZX 血统家族之后
  第二个独立撞上"同一份文件里 log_file() 没调用紧邻的 assure_file()"
  这个具体形状的、完全不相关的代码库家族）。

- **`efun::message()` 的 0 值 exclude 参数问题：确认是彻底根治，不
  是"只补了一个症状"**。`adm/simul_efun/message.lpc` 的
  `message(mixed arg, string message, mixed target, mixed exclude)`
  本身不是 `varargs`，但函数体第一行就是
  `if (!exclude) exclude = ({}); efun::message(arg, message, target,
  exclude);`——也就是说这个 wrapper 早就把"被驱动静默填成 `int(0)`
  的缺失第 4 参数"在传给 `efun::message()` 之前转换成了空数组，和
  `tell_room()`（同一文件里）已有的 `|| ({})` 写法是同一个思路，只
  是换了个位置实现。这和 `zjdywzb`/`yhwhpublicfi`（AGENTS.md §7.88）
  "4 个必填参数、内部调用点只传 3 个"的破损形状不同——`zjmudhell`
  这份代码从一开始就没有这个漏洞。**live 验证**：完整走过"世外桃
  源 → `east`（进入"光明磊落"竹屋，触发 `陆天抒` NPC 对话）→
  `out`（进入阎罗殿）"这条注册仪式路径，这条路径上多处
  `message_vision()`/`message()` 调用全部正常，没有任何
  `Bad argument 4 to EFUN message()` 报错。上一轮 WASM 笔记"修复了
  efun::message() 因 exc_target=0 被拒绝的问题"这句话本身是准确的
  ——本次只是把"为什么准确、准确到什么程度"钉死到具体代码行。

- **§7.50/§8.3a：已在此前的跨库扫描中修复过，本次重新核实仍然生效**。
  `clone/user/user.lpc` 的 `accept_kill()` 用的是
  `is_killing(ob->query("id"))`（字符串 id，不是物件），`feature/
  command.lpc` 的 `command_hook` 声明是 `nomask int command_hook(...)`
  （没有 `private`）。两处都已经是修好之后的形状，角色创建全程没有
  卡在这两个已知坑上。

- **§7.86（留言板 `post` 崩溃）：不适用——这份档案压根没有留言板系
  统**。全档案搜索 `BULLETIN_BOARD`/`BBS_BOARD`/`inherit.*board`/
  `post.lpc` 均无命中，`cmds/` 目录下也没有任何注册 `"post"` 动词的
  文件；和 `hell`/`zjdywzb` 等血统家族地图内容逐字节相同、但核心系
  统被完全重写这一血统关系一致——留言板属于旧系统的功能，这份手机
  App 引擎重写时没有移植过来，不是"已修复"，是"从未存在"，两者要区
  分清楚。

- **§7.68（死亡/复活 present() 硬中止软锁）：代码形状命中，但按撤回
  说明的两个前提条件核实后确认不适用，未做任何修改**。`d/death/npc/
  {wgargoyle,bgargoyle}.lpc` 的 `death_stage()` 确实是
  `if (!ob || !present(ob, environment())) return;` 这个撤回前的原
  始形状（和 `shujian3` 共享同一套 `gate.lpc`/鬼门关血统，`shujian3`
  自己的这个修复后来也被撤销了，参见 `shujian3` README 的更正说明，
  所以不能拿它当"已验证适用"的先例）。按 §7.68 撤回说明要求的两个前
  提条件逐一核实：（1）本档案的 `feature/move.lpc`/`feature/
  command.lpc` 里完全没有 `is_ghost()` 检查——鬼魂在这份代码里没有
  被禁止移动；（2）没有找到任何"强制移动任意玩家、不检查是否是鬼魂"
  的脚本 NPC（`shujian3`/`bmxkx2001` 那种"游导 NPC"角色，全档案搜索
  `is_ghost` 命中的文件里没有类似的强制 `move()` 逻辑）。两个前提都
  不成立，说明"鬼魂离场就放弃复活流程，等下次进入房间的 `init()`
  重新触发"更可能是这份代码里合理的、大多数鬼魂本来就能自行游荡的
  设计，不是 bug——按撤回说明的要求，未应用重试式修复。

- **实际死亡机制和 `hell`/`zjdywzb` 系的鬼门关不完全一样，值得记录**：
  `feature/damage.lpc` 里真正常见的战斗后果是 `unconcious()`（气/精
  归零、`disable_player()`、随机 30-130 秒后 `call_out("revive", ...)`
  自动苏醒），和真正调用 `die()`/移动进鬼门关的永久死亡是两条不同
  的路径——`score` 的死亡记录字段只在真正 `die()` 时才会变化。用管
  理员账号 `kill ouyang`（`欧阳克`，`/kungfu/class/ouyang/ouyangke`，
  一个门派级 NPC，明显不是给新手打的）挑起战斗，两回合内被打到"气"
  归零、"你的眼前一黑，接著什么也不知道了...."（`unconcious()` 的
  标准文本），符合预期；断线重连后如果气/精仍然是负值，`logind.lpc`
  的 `reconnect()`（第 364-365 行）会再次调用 `unconcious()` 提醒角
  色仍在昏迷中——这是有意的一致性检查，不是本次要修的 bug，只是记录
  下来供以后遇到类似"重连后又打印一次昏迷提示"时不必重新排查。没有
  在这次会话里把角色真正打死（欧阳克显然是刻意放在新手城里、不该被
  新手攻击的强力 NPC，按 §7.90 附近"游戏设计/难度，不是 bug"的既有
  原则不去动它），因此没有触发真正的鬼门关复活流程；`d/death/gate.
  lpc`/`wgargoyle.lpc`/`bgargoyle.lpc` 已做静态代码审查（见上一条），
  未做端到端真人复活的 live 验证。

- **§7.90（eval cost 上限）：`config.fluffos` 是这个项目最常见的
  `700000` 默认值，本次测试没有触发过**。完整会话（注册、5+ 个从未
  访问过的房间移动、门派 NPC 战斗、断线重连、`quit`）之后
  `grep -c "cost limit reached" log/debug.log` 和当次 `boot*.log`
  都是 0——这份档案目前的内容体量没有顶到默认上限，未做调整。

- **手机 App 协议的实测细节**：驱动打印 `ver1.0,<str>` 后需要客户端
  回应 `crypt(ZJKEY, str[2..3])`（`ZJKEY` 硬编码在 `include/zjmud.h`
  里，`str` 本身是固定盐值 `crypt(ZJKEY, "zj")` 所以整条握手串在这
  个驱动构建上是完全确定性的，可以离线用 Python `crypt.crypt()` 算
  出来复用）；随后一次性发送 `账号║密码║密文║email`（`密文` =
  `crypt(ZJKEY,账号)+crypt(ZJKEY,密码)`，真实校验，没有旁路）；新账
  号紧接着发送 `性别║图片║中文昵称`。进入游戏后角色创建走的是
  "世外桃源（选品质方向）→ 阎罗殿：`pianshu <类型>`（先天偏属）→
  `wash`（忘忧池随机洗四维）→ `born <地名>`（转生出生点）"，和
  `shujian3`/`zjdywzb` 是同一套仪式骨架，具体房间/NPC 名字不同。管
  理员账号 `fluffos`/`Mud@2026` 通过这条真实注册流程创建，`目前权限：
  (admin)` 立即生效（`adm/etc/wizlist` 里的名单已经生效，账号文件本
  身是这次会话新注册出来的，验证密码可用）。

- **确认一次 AGENTS.md §10.2 记录过的 telnet 客户端 CJK 字节损坏问
  题，非本档案 bug**：通过 `scripts/tmux_mud.sh`（本地 telnet 进程）
  发送 `kill 李阿婆` 时，telnet 本地直接掉进了自己的 `telnet>` 转义
  命令提示符（`?Invalid command`），从未真正发给驱动；同一条指令换
  成 `scripts/mudclient.py`（裸 socket）发送（改用拼音别名
  `kill ouyang`，`欧阳克` 的 `set_name()` 里注册的别名之一）立即正
  常触发战斗。另外这份档案的角色状态栏（`012` 开头的一整行 HP/气/
  食/水状态）大约每秒钟推送一次，属于 §8.3 第 1 条"实时时钟提示符"
  的同类情况——用 `mudclient.py` 时要用 `--idle 0.5` 或更低，`tmux_
  mud.sh` 因为是固定等待时长而不是"等到安静"，不受这个影响。

- **这份档案没有留言板（见上）、也没有可用玩家指令的商店/买卖/邮件
  系统**：`cmds/` 目录下没有 `mail`/`buy`/`list` 一类的动词文件，
  `feature/dealer.lpc`（NPC 商人逻辑）存在但没有任何 `add_action()`
  暴露给玩家指令——这些功能很可能只通过手机客户端自己的结构化菜单
  协议（连线时看到的 `06b12:...` 这类按钮提示）触发，raw telnet/
  socket 测试触及不到，不代表功能缺失，只是这次测试方法的覆盖边界，

## §7.52 追加实例（2026-08-18）：`adm/daemons/network/messaged.lpc` 的 `socket_bind()` 崩溃

作为 `hell` 那份档案（AGENTS.md §7.52）发现的同一个 bug 的跨库排查
一环，确认这份档案（和 `hell` 属于同一个 `shujian3`/"Doing" 手机
App 血统家族，`goto.lpc` 也共用完全相同的
`MESSAGE_D->find_user(arg)` 兜底逻辑）**现场复现了完全一致的崩
溃**：巫师账号第一次执行 `goto`（触发 `messaged.lpc` 首次懒编译）
时，`执行时段错误：*Bad argument 2 to socket_bind(); Expected: int
Got: "10".`——根因和 `hell` 完全相同（`LOCAL_PORT()` 的 `(int)` 转
型对 `get_config()` 实际返回的非数字值在运行时不起作用）。这份档
案自己早前的 WASM 修复记录里提到过"按 §7.52 掏空了三个纯 socket
精灵"（`versiond.lpc`、`payd.lpc`、`dns_master.lpc`），但
`messaged.lpc`（第四个碰 UDP socket 的精灵）当时被漏掉了——和
`hell` 自己的 `versiond.lpc`-修过-但-`messaged.lpc`-漏掉是完全相
同的疏漏模式。修复：`startup_udp()` 掏空成 `return 0`，
`send_udp()` 补上 `!socket_id` 保护。**现场验证**：重启全新驱动进
程，`goto` 干净执行，`debug.log` 里不再出现任何
`socket_bind`/`Bad argument` 记录。

**跨库排查结论（截至本次）**：这个 bug 在 `hell`/`zjmudhell` 这两
个同源手机 App 血统档案上都 100% 复现；但在完全不相关的血统
`aoxiangtianji`（西游记题材）上用同样的方法（`call`/`eval` 直接触
发 `create()`）**没有复现**——`get_config(__MUD_PORT__)` 在那份档
案上正确返回了数字端口。这说明这不是一个对所有携带这段代码的档案
都必然触发的 bug，可能和具体的血统/配置有关，不能不加验证就对
AGENTS.md §7.52 列出的其余 14 个档案批量套用同一个修复——已经把这
个结论更新回 AGENTS.md §7.52 本身，留给下一轮继续逐个排查。
  记录以供以后有更完整客户端模拟能力时补测。

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). Deleted 2,315 live
standalone `replace_program(ROOM);` lines under `work/` via
`fix_710_room.py`, plus hand-fixed the room-building tool's
string-builder template (`work/clone/misc/roommaker.lpc`). 3 real
`.lpc` files under `work/data/` checked — none had the bug pattern.
Remaining matches after the fix are all pre-existing `//`-commented.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`; `log/` directory didn't
exist for this lib and had to be created before the driver would
boot). Live admin login through this lib's custom 指间MUD
`crypt()`-challenge protocol (same ZJKEY/handshake as sibling
`zjdyzj`) as `fluffos`/`Mud@2026` — entered 客店, `look`/`quit` both
worked cleanly. Incidental `data/{login,user}/f/fluffos.o` save drift
from the login test was reverted via `git checkout HEAD` before
committing.

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

## §10.7 深度功能测试第二轮（2026-08-21）：真正的战斗/死亡/复活、商店、拜师

上一轮（2026-08-08）只走完了注册仪式（世外桃源→east→out），从未真正
玩过游戏本体。本轮用管理员账号 `fluffos`（现场重连，账号早前登记）
补测了战斗死亡复活、商店购买、拜师三项，外加一遍标准检查清单快速核
实。全程用 `/home/sunyc/src/fluffos/build-debug/src/driver` 加载
`config.fluffos`，`work/log/debug.log` 全程零 `Error`（只有大量正常
的懒编译期 `Warning`，不是运行时报错）。

- **战斗/死亡/复活：完整走通，未发现新 bug**。用管理员 `clone
  /d/guanwai/npc/wolf` 在 `/d/guanwai/famu1`（伐木场，符合 wolf.lpc
  `init()` 里 `outdoors` + `/d/guanwai/%*s` 的自动索敌条件）现场复
  制了一只野狼，`kill wolf` 触发真实生死战（不是安全的 spar/fight，
  印证了本次会话在其它档案上反复验证过的规律：`kill` 指令对 NPC 目
  标没有任何安全闸门）。中途因为默认 `wimpy` 阈值触发自动逃跑，
  `wimpy 0` 关闭后重新交战。追踪了完整的伤害链路：
  `feature/damage.lpc` 的 `heart_beat()` 检查 `qi<0||jing<0` 时，如
  果 `living(me)` 仍为真（角色还没被打晕）就调用 `unconcious()`（设
  `qi`/`jing` 精确为 0，`disable_player()` 关闭指令能力，`living()`
  随之变假，`call_out("revive", ...)` 排队苏醒）；由于 `kill.lpc`
  对 NPC 目标会双向调用 `kill_ob()`（`me->kill_ob(obj)` 且
  `obj->kill_ob(me)`），令野狼真正"想杀死"角色（`is_killing` 生
  效），`combatd.lpc` 的脱离战斗判定（第 733 行）要求双方都不
  `is_killing` 对方才会脱战，所以野狼在角色昏迷后不会停手，继续攻
  击把 `qi` 打成负值——下一次 `heart_beat()` 时 `living(me)` 已经是
  假，触发真正的 `die()`。现场日志：`你的眼前一黑，接著什么也不知
  道了....` 后紧接着`你扑在地上挣扎了几下，腿一伸，口中喷出几口鲜
  血，死了！`，角色被移动到 `DEATH_ROOM`（`/d/death/gate.lpc`，"鬼
  门关"），`白无常`（`d/death/npc/wgargoyle.lpc`）的 `death_stage()`
  五段对话按 5 秒间隔完整播放（`是ghost` 分支），最后
  `reincarnate()` + `move("/d/city/guangchang")` 把角色送回泥潭广
  场，之后 `qi`/`jing` 随心跳自然恢复。**§7.112 死亡阶段重入护栏
  现场验证**：`wgargoyle.lpc`/`bgargoyle.lpc` 的 `death_stage()` 每
  条 `return` 路径（不存在/离场、非鬼魂反杀、最终转生）都正确清了
  `death_stage_active` 临时标记，只有"还在等下一段对话"的中间分支
  不清（本来就该保留，等这次 `call_out` 链跑完再清），这次是本档案
  第一次真正触发这段代码，行为和静态审查时的预期一致，没有发现遗
  漏分支。全程 `debug.log` 零新增报错。
- **商店购买：确认此前笔记记录的"无可用买卖指令"结论依然成立，不
  是本次要修的 bug**。`feature/dealer.lpc` 里 `do_buy(string arg)`
  函数本身逻辑完整（价格计算、`vendor_goods` 校验、`INPUTTXT` 二次
  确认购买数量等都写得很完整），但全档案里没有任何地方真正调用它
  ——唯一的调用点是 `adm/npc/youxun.lpc` 自己重载后再 `::do_buy()`
  转发，属于该 NPC 自己内部的特例，不是通用绑定。逐一确认了三层可
  能的绑定方式全部缺失：（1）`cmds/` 目录下没有 `buy.lpc`/
  `list.lpc`/`sell.lpc`，也没有对应的 `.alias` 文件；（2）
  `feature/command.lpc` 的 `command_hook()` 只通过
  `find_command(verb)` 精确匹配 `cmds/` 里的真实文件，没有"扫描房
  间内 NPC 是否认识这个动词"的兜底逻辑；（3）现场对着真实商人 NPC
  `李阿婆`（`d/city/npc/liapo.lpc`，有 `vendor_goods`）连续尝试
  `list`/`buy 1 苹果`/`buy apple`，全部只得到标准的"什么？"（未知
  指令），不是报错，也没有触发任何 debug.log 记录——这正是这份档案
  "核心系统改写、商店 UI 从未移植"血统关系的预期行为，没有错误签
  名，按项目既定原则不算 bug，维持上一轮"手机客户端菜单协议触及不
  到"的结论不变。
- **拜师：完整走通，正确分配门派/称号，未发现新 bug**。用管理员
  `clone /kungfu/class/gaibang/he-bj`（丐帮七袋弟子"何不净"）现场
  复制到角色所在房间，`bai he` 触发真实拜师流程：`cmds/skill/
  apprentice.lpc`（通过 `cmds/skill/bai.alias` 绑定到 `bai` 动词，
  确认过这个绑定机制真实存在）核实双方状态后调用
  `ob->attempt_apprentice(me)`；`he-bj.lpc` 的 `permit_recruit()`
  （定义在 `gaibang.h`，判断没有背叛/没有其他门派）和自身的
  `combat_exp > 120000` 上限检查（新角色 `combat_exp=0`，满足）都
  通过，执行 `command("recruit " + id)`，`recruit_apprentice()`
  正确写入 `family = { family_name: "丐帮", generation: 20,
  master_id/master_name: 何不净, title: 七袋弟子 }`（师父是七袋，
  角色排在第 20 代）。`score` 复核：`丐帮第二十代传人`、`师父：何
  不净。`，字段全部正确。过程中顺带确认了 `permit_recruit()`/
  `attempt_apprentice()` 分层设计在这份代码里是完整可用的（不是像
  `d/city/npc/baibian.lpc` 那个"模仿玩家技能"的对练 NPC那样，虽然
  调了 `create_family()` 但没有 `inherit F_MASTER`、没有定义
  `attempt_apprentice()`，那个是死代码，不适合用来测试拜师——已经
  在排查过程中确认，未使用它）。全程 `debug.log` 零新增报错。
- **标准检查清单快速核实（本次全部确认已修复/不适用，未发现新问
  题）**：§7.111（`master.lpc` 的 `standard_trace()` 第 230 行
  `error["object"] ? file_name(error["object"]) : "0"` 已有三元防
  护）；§7.108（`clone/user/user.lpc` 的 `reconnect()` 第一行就是
  `enable_commands()`）；§7.30（`feature/skill.lpc` 5 个 accessor
  的 `mapp(x) ? x : ([])` 防护逐行核实存在）；§7.79（全档案
  `addn(` 零命中，不适用）；§7.100（此前已修复，本次未复查，沿用
  之前记录）；本次会话额外指定核对的四个"已在其它档案全部关闭"的
  corpus-wide 坑，逐一确认代码形状本身不存在，不是漏查而是真的不
  适用：`adm/daemons/combatd.lpc` 无 `bounce` 相关代码、全档案没有
  `chacha.lpc`、`adm/daemons/natured.lpc` 没有
  `if (!userp(ob[i])) destruct(ob[i])` 这个具体写法、
  `cmds/std/go.lpc` 没有 `sizeof(exit[arg])` 这个具体写法（它用的
  是 `!mapp(exits)`/`undefinedp(exit[arg])` 检查，形状不同，不受
  影响）。
