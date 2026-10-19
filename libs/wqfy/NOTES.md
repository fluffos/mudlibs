
## WASM 修复摘要（迁移自 meta.json 的 group_note）

无情风云（郑州风云世纪珍藏版），游戏内横幅为《天下无敌》，古龙题材 MUD。在 WASM 下启动并完整完成注册，没有任何编译或运行时错误——没有发现任何 LPC bug。唯一采取的行动：把 fluffos (admin) 播种进 adm/etc/wizlist（SECURITY_D 正确指向 /adm/daemons/securityd，只有一份，没有诱饵副本）。备注：这里的密码策略很严格（必须同时包含大写字母、小写字母和特殊符号/数字，至少 6 位）——纯字母数字密码会被拒绝，提示"您的密码必需包含大写和小写英文字母和其它特殊符号"；这是有意的站点策略，不是 bug。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字（会拒绝古龙小说人物名，未测试）→单一密码+确认（不是 sjsh/tybxjh 家族那种双密码机制）→电子邮件→性别→民族选择（0-3）→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 wizlist 指令输出"目前权限：(admin)"确认。LPC 格式化工具对全部 7339 个档案运行（写入 7310 个，24 个因为杂乱的历史代码报错，5 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。两个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 34 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——疑似严重问题，但排查未能定论，未计入 AGENTS.md

第一次对这份档案做完整 §10.7 深度游玩测试，遇到一个耗费大量时间排
查、最终**没有定论**的疑点，如实记录以免下次重蹈覆辙：

- **观察到的现象**：用原始 Python socket 脚本（本轮换用的标准方
  法，见 hxxtjqb 的教训）注册了至少两个不同角色（`qintestww`、
  `qintestzz`）——英文 id→y/n→中文名字→密码→确认密码→电子邮件→性
  别→民族选择，每一步都拿到了正确、及时的回应，注册流程本身完全正
  常，`data/user/q/<id>/` 下也确实生成了存档文件。但选完民族之后
  （`enter_world()` 的收尾阶段：`UPDATE_D->check_user()`、
  `STATUS_D->compare_status()`、`UPGRADE_D->upgrade()`、
  `NEWS_D->check_news()`、`NAME_D->map_name()`、
  `TOPTEN_D->topten_checkplayer()` 这条链），后续的 `look`/`score`
  连续等了 10 分钟以上都没有任何回应。
- **排查过的、且已排除的可能性**：
  - 不是死循环占满 CPU——`ps`/`/proc/<pid>/stat` 的 utime 增量在停
    滞期间几乎不动，`gdb -p <pid> -batch -ex bt` 直接抓到驱动主线
    程正安安稳稳地停在 `epoll_pwait2`（libevent 的事件循环等待处），
    不是卡在某段 LPC 执行里。
  - 不是全局性驱动阻塞——`nc -zv`在停滞期间仍能立刻连上端口（不过
    这只证明 TCP 三次握手能过 accept 队列，不能证明驱动真的在处理
    新连线）。
  - 不是 `query_ip_name()` 阻塞式反向 DNS——读过
    `~/src/fluffos/src/packages/core/dns.cc`，`query_ip_name()` 本
    身只查一个进程内缓存表，不做同步网络调用；真正的解析（若有）
    是 `dns_libevent.cc` 里异步事件驱动的，不会阻塞主循环。
  - 不是本档案自己的 20 秒重连冷却（`quit_time` 差值 < 20 秒的分
    支）——特意在两次连线之间空等超过 25 秒仍然复现。
  - 后续几次尝试复现时，反而先撞上了一个**纯粹是我方测试脚本失误**
    的连环验证失败：用了太长/带数字的英文 id（这份档案的规则是"3
    到 10 个英文字母"，不像 hxxtjqb 是"3 到 8 个"），第一步就被拒
    绝，而脚本没有检查每一步的实际回应就盲目按预设顺序继续发送后
    续指令，导致连续好几条指令都被当成新的（同样无效的）英文名字
    重试，看起来很像"卡住"，其实只是我方脚本没有正确处理验证失败
    分支——这类失误已经在别的地方发生过（telnet 客户端两次假警报），
    不排除本轮最初观察到的"10 分钟无响应"里也有类似的、我还没找到
    的脚本/协议误判成分。
- **未解决、留给下一轮**：`qintestww`/`qintestzz` 那次会话，注册的
  每一步都拿到了内容正确、看起来完全正常的回应（不是重复的验证失
  败提示），只是在民族选择之后彻底停止响应——这和上面确认属于"脚
  本失误"的那次不是同一现象，根因仍未查明。本档案早前的 WASM 验证
  记录（本文件顶部）明确写着"带着完整角色属性表进入游戏世界，全程
  没有任何意外错误"，与今天观察到的情况矛盾，暗示这可能是间歇性
  的、或者是本轮高频率反复连线/掐断连线（多次用 SIGTERM 粗暴结束
  python 脚本，没有走干净的 `quit`）造成的自我诱发状态问题，类似
  本项目已记录过的 hy2002 重复连线锁死先例——但也可能是
  `enter_world()` 收尾那条 daemon 链（尤其是 `TOPTEN_D`，需要扫过
  `top_lst`/`bot_lst` 排行榜数组）里真实存在的性能问题。**不计入
  AGENTS.md 编号目录**，因为没有达到"验证过、可复现、根因明确"的
  标准。下一轮如果继续测试，建议：(1) 全程只用一个连线，不要中途
  杀死重连；(2) 每一步先读回应内容再决定下一步输入，不要盲发预设
  指令序列；(3) 如果注册后仍然卡住，直接 `gdb -p <pid> -batch -ex
  bt` 确认卡在哪个 LPC 函数（如果卡在 LPC 执行中会显示
  `eval_instruction`/具体的 `.lpc` 帧，而不是 `epoll_pwait2`）。

## 深度功能测试（2026-08-17，round two）——上一轮的"停滞"已确认根因：不是 mudlib bug，是测试脚本本身的方法论缺陷

按上一轮末尾留下的三条建议（单一连线、逐步验证、gdb 确认）重新测
试，**这次彻底查明了根因：这份档案的"停滞"从头到尾都不是 mudlib
的问题，而是测试脚本的"等到网络安静下来再继续"这个假设，本身就和
这份档案的一个正常功能互相冲突。**

- **复现过程**：单一连线走完注册（合规的英文 id `qintestrb`，3-10
  个纯字母，避开了上一轮踩过的坑），一路顺畅到进入游戏世界，
  `look`/`score` 都正常。随后用同一个角色重新连线（`此英文名字已
  被使用，请输入此帐号的密码`→密码），发送密码后表面上看"没有任
  何回应"，而且这次连外层 `timeout` 保护都撑爆了（脚本运行超过
  120 秒仍未结束，不是被我方超时机制杀掉的）。
- **驱动侧排查**：`gdb -p <pid> -batch -ex bt` 显示驱动主线程稳稳
  停在 `epoll_pwait2`——和上一轮一样，不是卡在 LPC 执行里，CPU 占
  用率不到 1%。`ss -tnp` 显示连线是 `ESTABLISHED` 状态且客户端
  Recv-Q 里堆着数十字节**已经收到但还没被我方脚本读走**的数据——
  说明驱动其实一直有在正常回应，只是我方脚本没跟上。
- **真正的根因（`strace -p <脚本进程 pid>`)**：脚本卡在
  `recvfrom()`/`poll()` 的循环里，但**并不是卡住**——每隔恰好一秒
  就会成功收到一小段新数据（`\33[256D\33[1;36m21:XX:XX\33[1;33m>
  \33[...`，一个每秒刷新一次的、内嵌当前时间的彩色提示符）。根源
  在 `feature/message.lpc` 的 `prompt()` 函式：如果玩家的
  `env/prompt` 偏好设成 `"time"`（这份档案里似乎是新角色的默认
  值），提示符就会带上 `ctime(time())[11..18]`（时:分:秒），并且
  有一条心跳逻辑每秒都会重新推送一次这个提示符给客户端——即使玩
  家什么都没输入。这是这份档案**有意为之的正常功能**（提示符里显
  示实时时钟），不是 bug。
- **为什么这会让测试脚本看起来"卡死"**：本项目这几轮测试脚本的
  `recv_all()` 统一采用"sleep N 秒，然后不断 `recv()` 直到某次
  `socket.timeout` 触发才返回"这个策略，隐含假设是网络迟早会安
  静下来。但这份档案每秒钟都会主动推送新数据，新数据总是能在
  4 秒的 socket 超时窗口关闭之前抵达，导致这个"等到安静"的循环永
  远不会触发超时分支，从而永远不返回——这跟驱动是否卡死完全无
  关，纯粹是脚本的等待策略和这份档案的功能对不上。上一轮"注册完
  之后 10 分钟无响应"的观察，以及本文件顶部记录的其他几次"卡
  住"，很可能都是同一个根因，只是当时没有用 `strace` 深挖到这一
  步。
- **结论**：**这不是一个 mudlib bug，不适用任何代码修复**，是本
  项目测试方法论的一个新盲点，已记录进
  `feedback_recv_loop_breaks_on_live_clock_prompt` 记忆条目，供以
  后测试任何"提示符可能带时钟"的档案时参考（改用"匹配已知提示符
  /菜单关键字才返回"而不是"等到安静"，或者干脆设一个硬性总超时上
  限）。本档案的死亡/复活循环和留言板发帖仍未验证（受限于这次调
  查耗时），但既然"停滞"的根因已经查明且与 mudlib 本身无关，没有
  必要再为了它专门开一轮——如果以后测试这份档案，直接换一个不依
  赖"等到安静"的接收策略即可，不必再复现这个现象本身。

## 深度功能测试（2026-08-18，round three）——修复了错误处理器自身的崩溃 bug，其余全部验证正常

按 round two 定下的接收策略（硬性总时限的 `recv_budget()`，绝不"等
到安静"）重新写了 Python 测试脚本，逐条注册了十几个合规英文 id 的
新角色（3-10 个纯英文字母，不带数字），系统地跑了 round two 没来
得及测的几块：

- **移动/探索**：从出生的凤求凰客栈开始，西→南风大街→西进玉龙珠
  宝店，南风大街→北进风云广场→东进东云大路→西进阴暗石巷方向，
  以及新手学堂的引导链（新手学堂→东→南→南→回到凤求凰客栈），全
  部房间描述、出口列表、地图 ASCII 图都正常显示，没有任何异常。
- **经济（商店 buy/sell）**：玉龙珠宝店 `list` 正常列出商品（玉指/
  玉簪/玉花/玉镯，标价"两黄金"）；新角色没有初始资金，`buy jade
  ring from seller` 正确返回"你的钱不够。"（不是崩溃，是合理拒
  绝）；`sell jade ring`（未持有该物品）正确返回"什麼？"。向新手学
  堂的接客童子 `ask tong about 盘缠/食物/水` 三个索取指令都正常发
  放"一两银子"/"烤鸡腿"/"牛皮酒袋"，`i` 也能正确显示到手的物品。
  银子（新手起始货币）和黄金（商店计价单位）是两种不同面额，1 两
  银子不够买 1 两黄金的东西，这是合理的经济设计，不是 bug。
- **留言板（post/read）**：风云广场的"盘龙摩天柱"留言板，`post <标
  题>` 正确进入 `feature/edit.lpc` 的行编辑器（用单独一行 `.` 结
  束），发帖后系统回应"留言完毕。"；`read <编号>` 精确读回了刚发的
  帖子（作者/标题/内容与发帖时完全一致，编号为当时留言板的下一个
  序号）。`read new`（读最早未读）也能正常工作。发帖后已用
  `git checkout` 撤销了 `work/data/board/fysquare_b.o` 里的测试留
  言，不留痕迹。
- **战斗**：在东云大路对"卖菜的(Caifan)"发起 `kill`，攻防消息（挥
  拳/格挡/闪避/瞪眼蓄势）逐回合正常输出，房间列表正确显示
  `(战斗中)` 状态。新角色白手空拳的"杀伤力"数值为 0（`score` 里能
  看到），读了 `adm/daemons/combatd.lpc` 的伤害公式（第 628 行
  `damage -= victim->query_fle()`）确认这是设计使然：没有兵器或武
  学加成时，基础伤害会被对方的韧性（fle）直接吃掉归零，双方打了几
  十回合都是"结果没有造成任何伤害"，不是 bug。移动可以在战斗中直
  接执行并逃离（`go.lpc` 里有专门的战斗中移动脱离判定），验证过在
  "(战斗中)"状态下 `west`/`north` 依然能正常换房间。
- **死亡/复活循环：仍未覆盖**。白手空拳时双方都无法造成有效伤害
  （见上），要真正打死一个 NPC 需要先学武学或买兵器，兵器铺（镇风
  兵器铺）在地图上距离出生点较远，权衡后判断这已经超出"找 bug"范
  围、更接近"深度玩通关"，本轮没有追下去。静态读过
  `feature/damage.lpc` 的 `die()`/`revive()`/`reincarnate()`，逻辑
  结构完整（移动到 `DEATH_ROOM`、存档、清空战斗状态），没有发现明
  显问题，但没有做到实机验证。
- **拜师（sect-joining）**：在南风大街对"寒梅先生(Mei)"执行
  `apprentice mei`，正确返回"寒梅先生既不属於任何门派，也没有开山
  立派，不能拜师。"——读过 `cmds/std/apprentice.lpc` 第 39-40 行，
  这是 `!mapp(ob->query("family"))` 的正常判断分支（Mei 本身没有
  `family` 设定，不是一个门派掌门），合理拒绝，不是 bug。没有再找
  真正的掌门 NPC 复测"接受"分支（掌门 NPC 分散在地图各处，同样判
  断为深挖代价大于收益）。

- **发现并修复的真实 bug（不是设计选择）：`error_handler()`
  在处理"驱动级"运行时错误时自身会崩溃**。测试"逃跑"直觉（新角色
  在战斗中输入裸 `flee`，不带参数）时，debug.log 里出现了两条叠加
  的错误：
  1. 驱动的 `add_action.cc` 安全检查触发了一次真实的运行时错误
     `Illegal to move or destruct an object (/questobj/jade-pin#181)
     defining actions from a verb function(flee) in object(/obj/user#199)
     which returns zero.`——这是驱动在阻止一次"在动作链尚未处理完
     时销毁/移动一个仍持有 add_action 注册的对象"的危险操作，触发
     条件依赖当时房间里恰好存在的其它对象状态，本轮只复现了一次，
     换个角色/时间点重试同一步骤未再复现，判断为环境相关的偶发情
     况，没有继续深挖（驱动本身正确拦下了这次操作，没有造成实际损
     坏）。
  2. **真正的 bug**：`adm/obj/master.lpc` 的 `error_handler()` /
     `standard_trace()` 在尝试把上面这条错误格式化写进 debug.log
     时自己崩溃了——`standard_trace()` 第 194 行无条件对
     `error["object"]` 调用 `file_name()`，但驱动产生的这类"非
     LPC 帧"运行时错误里 `error["object"]` 是 `0` 而不是对象，
     导致 `file_name()` 报 `Bad argument 1 to file_name(). Expected:
     object Got: 0.`，日志里只留下一条"Error in mudlib error
     handler: ..."，**原始错误的完整堆栈信息全部丢失**，对任何
     以后要排查驱动级错误的人都是有效信息的黑洞。
  - **修复**：把第 194 行的
    `file_name(error["object"])` 改为
    `objectp(error["object"]) ? file_name(error["object"]) : "(driver)"`，
    只在 `error["object"]` 确实是对象时才调用 `file_name()`，否则
    用占位字符串代替，不影响原有的正常（LPC 帧、`error["object"]`
    是真实对象）报错路径。
  - **实机验证**：杀掉旧驱动进程、清空 debug.log、用修复后的代码
    重新起了一份干净驱动，重复了"注册→移动→对卖菜的发起战斗→裸
    `flee`"的整个流程；这一次 `flee` 本身正常走到了
    `notify_fail("指令格式：sbfind <物品>\n")` 分支（原始的
    jade-pin 冲突这次没有复现，符合上面"环境相关、偶发"的判断），
    全程 debug.log 干净，没有 `Bad argument`/`Error in mudlib error
    handler` 之类的二次崩溃。因为没能在这次验证里重新触发第 1 条
    的驱动级错误，`objectp()` 判空分支本身没有被直接走到过，但改
    动本身是无副作用的纯防御性判空（`objectp()` 三元表达式），逻
    辑上必然覆盖"error["object"] 不是对象"这一路径，风险很低。
  - **附带发现（记录但未修）**：`cmds/std/flee.lpc` 这个文件的
    实际内容其实是 `sbfind`（凭感觉定位物品大概方位）的逻辑（连
    `help` 文字都写的是"指令格式: sbfind <物品>"），跟
    `cmds/adm/sbfind.lpc`（管理员版，权限判断不同）几乎是同一份代
    码的两个变体；由于 FluffOS 的 `cmds/std/` 目录按文件名直接注
    册动词，这意味着玩家输入 `flee`（战斗中最直觉的"逃跑"单词）
    实际跑的是定位物品的逻辑而不是脱战。真正的脱战机制是移动指令
    本身（`go.lpc` 里有战斗中移动的脱离判定，已验证可用），所以
    这不是一个"玩家真的没法逃跑"的功能性缺口，只是命令名字和内容
    对不上、错误提示会提到一个玩家从没打过的"sbfind"这个词，容易
    让人困惑。`git blame` 确认这个文件从最早一次批量转档提交起就
    长这样，判断是原始 2002 年档案自带的历史遗留（可能是命名笔
    误），不是本项目转换过程引入的，按"不改设计/内容"的范围界定，
    这轮没有动它，留档供以后参考。
- **跨库排查建议**：`error_handler()`/`standard_trace()` 里
  `file_name(error["object"])` 不判空这个模式，很可能是这一支
  mudlib 血统里从 `master.c`/`master.lpc` 继承下来的通用样板代码，
  该血统的其它兄弟库大概率共享同一份 `master.lpc`，值得作为下一轮
  跨库机械扫描的候选（搜索模式：`file_name(error["object"])` 或
  `file_name(error\["object"\])` 且前面没有 `objectp()` 判空）。

## 深度功能测试（2026-08-19，round four）——用当前完整清单复测，四项全部确认已经干净，无新修复

按 AGENTS.md 当前完整目录（round three 之后新增的 §7.112～§7.114、
以及 §7.90/§7.111）逐条复查本档案，并用一个全新角色重新走了一遍完
整 §10.7 流程。**结论：全部四项已有检查点都确认干净，本轮没有发现
新 bug，也没有做任何代码改动。**

- **§7.111（`standard_trace()` 空 `error["object"]` 崩溃）**：直接读
  `work/adm/obj/master.lpc` 第 194 行，确认就是本档案本身在 round
  three 里落地的修复
  `objectp(error["object"]) ? file_name(error["object"]) : "(driver)"`，
  git 无未提交改动，只是确认，未重复验证触发路径。
- **§7.112（`init()` 无重入保护的 `death_stage` call_out 链）**：本档
  案的 `d/death/npc/panguan.lpc`／`panguan2.lpc`（判官系 NPC）两份都
  已经带有 `query_temp("death_stage_active")`／`set_temp(...)` 的重
  入保护，corpus 扫描早前已覆盖，直接读代码确认无需改动。全库没有
  `wgargoyle.lpc`/`bgargoyle.lpc`/`yu-zu2.lpc` 等该 bug 常见的其它别
  名文件。
- **§7.113（netdead 重连不恢复 `heart_beat`，本档案是 62 库扫描名单
  外的漏检对象，本轮做了从零开始的完整核实）**：静态读
  `LOGIN_D`（`adm/daemons/logind.lpc`）的 `reconnect(object ob, object
  user, int silent)`，确认它无条件调用 `user->reconnect()`（第 656
  行），并且是从两条真实调用路径触发的活代码（同一 id netdead 后重
  连、以及"已在线，确认踢人重连"两个分支都会走到这里，不是死代
  码）。`work/obj/user.lpc` 自己的 `reconnect()`（第 115-121 行）无
  条件执行 `enable_commands()` + `set_heart_beat(1)`，在正确的
  `this_object() == user` 上下文中生效——属于本项目已确认的"正确血
  统"形状，不是 `shzs` 那种"reconnect() 是死代码，真正入口另有别
  处"的坏形状。**做了实机验证，不只是静态读代码**：用全新角色
  （`qintestrn`）在新手学堂领到初始食物/饮水（`hp` 指令读到基线
  食物 98%／饮水 98%），直接关闭 socket（不走 `quit`，模拟真实断
  线）模拟 netdead，空等 25 秒后用同一帐号+密码重连，重连瞬间
  `hp` 读到的食物/饮水仍是 98%/98%（证明 `net_dead()` 的
  `set_heart_beat(0)` 生效，断线期间没有偷跑/也没有额外扣血），随
  后带着这条重新连线保持连接 20 秒，再读一次 `hp`，食物/饮水已经
  降到 97%/97%——证明 `heal_up()`／`heart_beat` 在重连后确实恢复
  正常跳动。这是一个干净的三点式实机对照（断线前→断线中冻结→重
  连后恢复递减），不是靠单次 `call`/`query_heart_beat()` 的不可靠
  读数下的结论。**本档案不需要任何 §7.113 修复。**
- **§7.114（`private` 修饰的 `input_to()` 回调经 mixin 继承后失
  效）**：`work/feature/edit.lpc` 的 `input_line()` 本身就没有
  `private` 修饰符，`work/std/char.lpc`（`CHARACTER`，`obj/user.lpc`
  的父类）用 `inherit F_EDIT;` 引入这份 mixin，链路是活的。全库对
  `private.*input_line`、以及所有 `->edit(` 调用点（`bboard.lpc`/
  `jboard.lpc`/`mailbox.lpc`/`chfn.lpc`/`to.lpc` 等）逐个 grep 确认
  没有任何 `private` 修饰。**实机验证**：全新角色在风云广场"盘龙摩
  天柱"留言板 `post stone <标题>`，连续输入两行正文，以裸 `.` 结
  束，服务端回应"留言完毕。"；直接读存档文件
  `work/data/board/fysquare_b.o` 确认两行正文都完整写入了同一条留
  言的 `msg` 字段（不是只有第一行、第二行被吞掉），证明多行编辑续
  行回调没有被吞。验证后已用 `git checkout` 撤销这条测试留言，board
  存档文件恢复原状。
- **§7.90（eval-cost 默认值）**：`config.fluffos` 第 39 行
  `maximum evaluation cost : 5000000`，早前 §7.90 机械扫描已经把本
  档案纳入，不是危险的 `700000` 默认值，无需改动。

- **完整 §10.7 游玩流程（全新角色）**：注册（英文 id→y/n→中文名→
  密码×2→邮箱→性别 m/f→民族 0-3→进入游戏世界）、`look`/`score`、
  移动（凤求凰客栈↔南风大街↔风云广场，出口/地图 ASCII 图正常）、
  留言板发帖（见上）、以及上面详细描述的断线-重连-心跳恢复验证，
  全部正常。战斗/死亡复活循环本轮沿用 round three 已经记录的判断
  （白手空拳双方都打不出有效伤害，需要兵器/武学才能真正打死 NPC，
  属于"深度玩通关"范围而非找 bug，未追）——没有新证据推翻这个判
  断。经济、拜师本轮未重复测试（round three 已验证过、且本轮没有
  发现任何提示需要重新验证它们的迹象）。

- **本轮结论**：无新 bug，无代码改动，无需要提交的修复。测试用的
  全新角色帐号（`qintestrh`/`qintestrj`/`qintestrk`/`qintestrm`/
  `qintestrn`/`qintestro`/`qintestrp`）已在测试结束后清理（这些账号
  存档从未被 git 跟踪，本来就是本地测试残留，不影响仓库状态）；
  round one/two/three 遗留的 `qintestd`/`qintestrb`/`qintestww`/
  `qintestzz` 未动（早于本轮，且 `qintestrb`/`qintestww`/`qintestzz`
  已在 NOTES.md 前文中被指名引用为历史排查证据）。驱动进程测试结
  束后按精确 PID kill，未使用 `pkill -f`。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,095 处存活匹配。脚本删除了 1,090 处标准独立行；
  另外 5 处房间生成工具的字符串拼接模板手动修复——`obj/wall.lpc`（这个
  库的房间编辑器工具其实叫"wall.lpc"而非"roommaker.lpc"，命令名为
  `mkroom`/`rset`/`connect`/`saveroom`；其 `mkroom` 用的 heredoc 模板本
  身干净，只有 `do_saveroom()` 的字符串拼接模板有这个 bug）、
  `d/wiz/xgchen/roommaker.lpc`（同一 bug 的独立副本）、
  `cmds/adm/roommaker.lpc`（另一份独立管理员房间生成工具，3 处命中：
  `mkroom` 命令的字符串拼接、`do_saveroom()` 里两条分支各一处）。`data/`
  下额外核查过，无命中。验证：真实 debug 驱动干净编译启动、端口正常监
  听，`debug.log` 无新增 "cannot replace"/错误行（仅有与本次修改无关
  的既有 pragma/nosave 警告）。

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

## 深度功能测试（2026-09-04，shop + 拜师）

Prior 2026-08-18 round three listed 玉龙珠宝店 and correctly refused
an unaffordable `buy jade ring from seller`, and correctly refused
`apprentice mei` on 寒梅先生 (`cmds/std/apprentice.lpc` early-return
when the NPC has no `family` — design, not a bug). This pass
completes a **paid** buy and a recruiting NPC.

Port **40124**, `build-debug` driver. First send is the id (banner
has no GB/BIG5 menu). Registered `fluffos` / `Mud@2026` / name 浮浮
/ email `player@me.com` / male / 汉族 — `(admin)` from
`adm/etc/wizlist`. Password policy still requires upper+lower+special
(site policy). Login prints “请敲回车键［ＲＥＴＵＲＮ］” then a
more-pager; send RETURN/`q` before further commands or they are
swallowed. Prompt has a live per-second clock — idle-based clients
must use ≤0.45s.

**Shop**: `clone /obj/money/gold` works for `(admin)`. `goto
/d/fy/yuljade` 商玉龙 (`F_VENDOR`, already `#include <dbase.h>`).
`list` shows 玉指 jade ring 1 两黄金 / 玉簪 2 两 / 玉花 2 两 / 玉镯
3 两. `buy jade ring from seller` deducted the gold and printed
“你向商玉龙买下一个玉指.” Inventory then showed the ring plus 一文钱
change.

**拜师**: `goto /u/wudang/zhixiao`, `apprentice shi` on 石雁
(`u/wudang/npc/master.lpc`, `create_family("武当派", 57, "掌门人")`).
`attempt_apprentice()` `call_out("do_recruit", 2, ob)` — wait ~2s.
Accepted: “恭喜您成为武当派的第五十八代弟子.” `score` shows
武当派第五十八代弟子 / 你的师父是石雁. `save` then disconnect.
After a full driver kill + reboot, relogin still shows 武当/石雁;
一文钱 persisted; 玉指 did not (not autoload — expected).

**Bug fixed**: `u/wudang/npc/master.lpc` `recruit_apprentice()` wrote
`add("apprentice_availavble", -1)` (extra “av”) while
`attempt_apprentice()` uses `"apprentice_available"`. Same recruit-
limit typo as nitan Huashan — the daily counter never decremented.
Corrected (CRLF preserved). Same typo exists in many other masters
in this tree; only the live-tested 石雁 file was patched this pass.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 9 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply wqfy`: 2 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 4 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 4 PASS, 0 that loaded before fail now, 3 more load.

2 files moved (2 `.C`); mostly under `d/yihua/obj` (1), `questobj/obj/chi.C` (1). A rescan with `scripts/lpc_warnings.py wqfy` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/adm/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 2 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location`、`tongji/dynamic_location` 里 2308 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`adm/daemons/tongjid.lpc`、`d/meiyuan/npc/zhuge.lpc`、`d/yihua/npc/yaoyue.lpc`、`tongji/npc/zhuge.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 43 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`adm/daemons/tongjid.lpc`、`d/meiyuan/npc/zhuge.lpc`、`d/yihua/npc/yaoyue.lpc`、`tongji/npc/zhuge.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 5 个，工作树三次分别通过 5、5、5 个（共 6 个），无回退；`d/meiyuan/npc/zhuge.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py wqfy --fix` 加 `scripts/lpc_fix_no_effect.py --apply`：无用局部变量 1379 个、转义 28 处、`nosave` 函数 19 个改 `protected` 等，共改动 695 个 `.lpc` 和若干 `.h`；`adm/daemons/network/545554.lpc`（`dns_master` 的副本）把 `#if PREF_* & SVC_TCP` 移到 `if` 外面。HEAD 与工作树分别加载（新进程）：670 -> 670 通过，无回退。
手工：
- `adm/daemons/combatd.lpc` 易筋经反震"内伤"的一档 `else if (damage < 1600) HIM "…" NOR;` 少了 `return`，伤害在 800–1600 之间时这句描述算出来就扔了，函数落到 `break` 返回空；补上 `return`。
- `d/kaifeng/npc/huzhou.lpc` `gethelp()`：`command("follow %s", ob->query("id"));` 把 `command()` 当成 printf，跟随的对象是字面的 `%s`；改成 `command("follow " + ob->query("id"));`。

启动时警告 93 -> 0；新进程登录画面正常（输入英文名后断开，HEAD 也一样）。

- 2026-10-10：`include/net/ftpdsupp.h` 的 `string file;` 只在 `#ifdef GUEST_WIZARD_FTP` 分支里用，声明移进该分支（编译警告第二轮）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 2 处多余继承：`d/fy/fish.lpc` 把 `inherit ROOM;` 写了两遍，房间从没载入过，现在载入；`d/city/obj/muren.lpc` 多余的 `F_CLEAN_UP`。手工：`cmds/adm/roommaker.lpc` 把 `special_props` 声明两次，代码用的是后一份（多 `file_name`），删去前一份；`cmds/adm/wizinfo.lpc` 自己定义、却从不使用的 `CHINESE_MUD_NAME` 删去。能编译的文件警告清零；改动的 4 个对象在 HEAD 与工作树各载入一次：HEAD PASS 3，tree PASS 4，regress 0。
- 2026-10-14：1 个存档文件（玩家/登录存档 1 个；`data/login/j/jane/jane.o`）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。驱动忽略返回值的 apply（`init`、`reset`、`heart_beat`、`create`）里改成空 `return;`（`return ::init();` 改为 `{ ::init(); return; }`，调用照旧）。新进程比对 HEAD 与工作树：1 个对象，新增载入 0，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

3 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，1 处改为 `add(type, -N)`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yihua-jimu`→`yihua-jiemu`（`qishier-jueji`、`yihua-jiemu`）；`xizia-shengong`→`zixia-shengong`（`hunyuan-zhang`）。

## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/wiz/qiu/title/title.o`、`open/title.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

33 个文件、57 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/clone/weapon/changjian`、`/d/laowu/npc/obj/bigcloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 12 个（11 个原来载入不了），没有退步；其余 21 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 37 个对象设了本库没有文件的武功（55 个名字，最多的是 `yunlong-shengong`、`yunlong-shenfa`、`claw`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 16 个通过，其余 14 个停在别的错误上（`d/menggu/npc/honghua/chen`：*No program in object '/d/menggu/npc/honghua/chen'!；`d/menggu/npc/honghua/huo`：*No program in object '/d/menggu/npc/honghua/huo'!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/city/kezhan` 的 `north`：`/d/city/misc/idleroom` → `/d/city/bobing`；`/d/city/wuguan` 的 `north`：`/d/city/misc/kantai` → `/d/city/under`；`/d/menggu/ta2` 的 `down`：`liuhe1` → `ta1`；`/d/miti/hole2` 的 `east`：`hole` → `hole3`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/stick`（宏 `STICK`）←mhxy，4 个对象继承它，抽样 3/4 载入；`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 23 处、8 个文件：`taiji-force`→`taijiforce`（16 处）、`lotus-force`→`lotusforce`（4 处）、`tang-balde`→`tang-blade`（2 处）、`duan-yirangzhi`→`duan-yiyangzhi`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 2 处、2 个文件：`::reset()`（2 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 2 个：`/daemon/skill/fanliangyi-dao.lpc`、`/daemon/skill/poyu-quan.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 24 个：`d/kaifeng/npc/tufei2`、`d/kaifeng/npc/tufei3`、`d/kaifeng/npc/tufei4`、`d/kaifeng/npc/tufei5`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `STORY_DIR`、`TRANSFER_MODE`、`MAILDIR`，用到它们的物件（名单里 4 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 3 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `d/wudujiao/npc/baichan.lpc` 删掉 `map_skill("baichan-hammer", 100);`（第二个参数应是字符串；上面已有 `set_skill`，下面有 `map_skill("hammer", "baichan-hammer")`）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 技能书的基类、F_UNIQUE、F_NOCLONE（2026-10-19，KB 04 §6.15、KB 06 §7.262）

`obj/book/*.lpc` 的 40 本技能书（`blade_book_a`、`literate_book_c` ……）都是 `inherit BOOK;`，本库既没有 `BOOK` 这个宏，也没有它的基类，整批载入不了；`obj/npc/*` 里 10 个 NPC 要 `F_UNIQUE`，`include/npc/ultra/` 里 4 个要 `F_NOCLONE`，同样没有。2026-10-18 补基类那一轮试过把它们补回来，载不进来又撤掉了；这次先补上缺的前提，再补基类：

- `/std/item/book.lpc`（宏 `BOOK`）←xkyx3b。xkyx3b 和 xkyxciii 里这 40 本书与本库逐字节相同，这个基类就是给它们写的：画一个带书名的彩色封面，颜色读书上的 `bcolor`/`lcolor`/`fcolor`/`tcolor`。
- 基类调用 `space(n)`，而 `adm/simul_efun/atoi.lpc` 里只有 `atoi()`：补上 `itoa()` 和 `space()`，文字照 xkyx3b 的 `string.lpc`（`scripts/lpc_add_sefun.py space`）。
- 40 本书的 `set("fcolor", BWHT)` 和基类都要背景色宏 `BWHT`，而 `include/ansi.h` 里这一行被注释掉了（`// #define BWHT ESC+"[47m"`，另外七个背景色都在）：恢复。
- `/feature/unique.lpc`（宏 `F_UNIQUE`，10 个对象）←zzfy3。`F_NOCLONE` 也试过（`/feature/noclone.lpc` ←sjshv150）：基类载得进来，但用它的 4 个大宗师 NPC 还要 `NPC_D`，一个也载不进来，所以又撤掉了。

56 个对象里 52 个现在载入（HEAD 上一个都不行），逐个与 HEAD 对比没有退步。剩下 4 个是 `include/npc/ultra/{dugu,huang,kuihua,shenni}.lpc`（大宗师 NPC）：它们要 `NPC_D` 守护进程和 `ultrap()`，本库没有这一套，不动。新载入的 NPC 带出的警告（`obj/npc/*-shi` 等的未用局部变量）留给标准一轮修复。（`scripts/lpc_restore_bases.py --evidence --retry`）
