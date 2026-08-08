
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
  记录以供以后有更完整客户端模拟能力时补测。
