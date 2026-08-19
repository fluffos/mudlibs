
## WASM 修复摘要（迁移自 meta.json 的 group_note）

Doing 血统的大型金庸题材 mudlib（7000+ 个 LPC 档案），游戏内标题为 REVIVE OF ULTRA HELL(BLOOD & MAGIC) FROM 1999.11.13。修复的 bug：（1）缺失的本地 log/nosave/ 目录导致 logon() 期间每一个新连线都会断线；（2）check_legal_id() 的 while(i--) 循环会静默接受一个空的英文 id，之后对这个空字符串呼叫 sprintf("%c", my_id[0]) 就会崩溃（新增 AGENTS.md §7.62）；（3）经典 §8.1 GBK 字节区间 is_chinese() bug；（4）三个各自独立的字节数没减半的长度界限 bug（check_legal_name 的姓氏/名字界限、姓名合并后的最短长度、以及 named.lpc 的 invalid_new_name() 滑窗查重检查）都按已确立的 §8.1 减半模式修复；（5）§7.12 类的 message() exclude 参数 bug 就活在 message() 包装函式本身，不只是 tell_room()——channeld.lpc 的 do_channel() 和 questd.lpc 的 collect_all_quest_information() 各自独立崩溃（新增 AGENTS.md §7.61）；（6）accept_kill() 里 §7.50 的 is_killing(ob) 物件/字符串不匹配 bug，是第 4 个确认的同类血统；（7）versiond.lpc 的 13 个碰 socket 的函式按 §7.52 掏空（和 zjmudhell/shujian3 那份几乎逐字节相同），修复了一个会让每个新用户在 logon() 时断线的崩溃。管理员账号（fluffos/Mud@2026，管理密码 Mud@2026Adm）通过真实注册流程 + adm/etc/wizlist 播种，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字。

## 深度功能测试（第二轮，2026-08-03）

本轮不再满足于"注册→look→score→quit"的浅层冒烟测试，而是完整走了
一遍这份档案自己独特的"投胎"新手引导流程，并在过程中发现并修复了两
个会让游戏**完全无法正常游玩**的严重 bug——此前的验证记录只覆盖到
世界入口房间，从未真正触发过这两处代码。

### 发现并修复的 bug

1. **`MESSAGE_D->find_chatter()` 在 `check_ok()` 里未加保护呼叫**
   （新增 AGENTS.md §1.3(c) 条目，`yanhuangwuhun`/`yhyxs` 已知同类 bug
   的第三个确认实例）：`adm/daemons/logind.lpc` 的 `check_ok()`——每一
   次密码校验通过后都会执行的函式——无条件呼叫
   `MESSAGE_D->find_chatter(...)`。`MESSAGE_D`
   （`adm/daemons/network/messaged.lpc`）自己的 `create()` 里有原始的
   `socket_create()`/`socket_bind()` 呼叫（一个 UDP 聊天/跨服精灵），
   在 WASM 下完全编译不过。未加保护的呼叫会抛出"*No program in object
   '/adm/daemons/network/messaged'!"，让 `check_ok()` 执行到一半就中
   止——早于 `make_body()`/`enter_world()`，也就是说**每一次密码验证
   成功之后，连线都会直接静默断开，永远走不到欢迎信息或注册房间**。
   已仿照 `yanhuangwuhun`/`yhyxs` 已经确立的修法，加上
   `if (find_object(MESSAGE_D)) { ... }` 保护。
2. **`feature/command.lpc` 的 `command_hook` 声明为 `private`**（
   AGENTS.md §8.3a，第一次在这份档案上确认，且是目前记录里症状最隐
   蔽的一次）：`private nomask int command_hook(string arg)` 在这个驱
   动上一旦被继承就会从 `private` 降级为 `DECL_HIDDEN`，导致
   `add_action("command_hook", "", 1)` 这种"捕获所有指令"的注册方式
   静默失效——但只对 `ORIGIN_EFUN`（也就是其它物件透过 `command()`
   efun 发起的呼叫）生效，玩家自己直接敲的指令走 `ORIGIN_DRIVER`，不
   受影响。这份档案独特的"投胎"新手引导——`register`/`decide`/
   `wash`/`born`——全部是通过 `d/register/npc/shuisheng.lpc` 的
   `do_register()`/`do_decide()` 内部呼叫 `command("say/tell/nod
   ...")` 来实现 NPC 说话的，也就是说**这一个 bug 直接卡死了每一个
   全新玩家注册流程的第一步**：玩家输入 `register 邮箱地址` 后，
   `add_action` 本身正确匹配、没有报"什么？"，但水笙一句话也不会说，
   连她自己被动触发的 `greeting()`（新手一进房间的欢迎语）也同样哑火
   ——表现上和网络延迟或连线故障一模一样，很容易被误判为环境问题而
   不是代码 bug。真正的诊断线索藏在驱动自己的日志里，而不是玩家看到
   的画面：`apply() with insufficient permission: ... function:
   command_hook, origin: efun, needs: private, has: hidden`，时间戳
   和指令发送的瞬间精确对应。修复方式和 §8.3a 记载的完全一致：去掉
   `private`，保留 `nomask`。

两处 bug 一起意味着：在这次修复之前，这份档案的 WASM 打包版本**任何
一个全新玩家都无法真正完成注册**——`check_ok()` 的崩溃会先一步掐断
连线；就算侥幸绕过（比如管理员账号已经存在存档，走的是不同分支），
"投胎"引导流程本身也会在 `register` 这一步彻底哑火。此前的验证记录
只做到"看到世界入口房间"就停了，从未真正把这两条路径走通过。

### 完整验证：从注册到进入游戏世界

用一个全新账号（非既有的 fluffos 管理员存档）在浏览器环境
（Playwright 驱动的真实 Chromium，不是脚本化的 telnet 客户端——排查
过程中发现脚本化客户端对这份档案的编译延迟计时特别敏感，容易把"driver
正忙着编译"误判成"指令没有响应"，回头改用真实浏览器环境后同样的操
作序列每次都干净复现）完整走通：

- `register fluffos@example.com` → 水笙点头确认，说明邮箱地址、警告
  不做 mail 验证。
- `decide` → "好了！你的email地址已经注册了！现在快去附近选你的品
  质吧。"
- 向东走到"桃源竹屋"，见到陆天抒——他的开场白直接点名"郭靖、萧峰"
  作为"光明磊落"这个品性的代表人物，是金庸小说里两位主角的直接互文。
- `out` 确认选择这个品性，自动被送到"阎罗殿"——十殿阎罗、牛头马面、
  地藏王端坐大堂的场景描写，气氛渲染得相当到位，和游戏标题"终极地狱
  之地狱无门"的地狱主题呼应。地藏王会主动递上"新手入门必读"。
- `look paizi` 看到投胎目的地清单，一共 18 个选项——除了苏州、西域、
  杭州等常见地域外，还有"慕容世家""欧阳世家""段氏皇族""关外胡家"这
  四个直接对应《天龙八部》里慕容复、欧阳锋、大理段氏、丐帮相关家族
  的"出身"选项，是很有心思的金庸世界观还原，不是套模板的通用武侠背
  景。
- `wash` 跳入"忘忧池"随机洗一组四项天赋（膂力/悟性/根骨/身法）。
- `born 扬州人氏` 完成投胎，正式进入游戏世界，出生在扬州客店，店小
  二、「滑不留手」游讯、「宰人不用刀，愿者上钩」戚长发（"躺尸剑门传
  人"）三个 NPC 同时在场——戚长发这个称号直接对应金庸小说《侠客行》
  里的角色，游戏规则文本里也明确写着"本游戏改编自「侠客行」，原是建
  立在「东方故事Ⅱ」MUDLIB 上的一个 MUD"——比 README 原本笼统的"金庸
  题材"要精确得多，这份档案有自己明确的、可考据的原著出处。
- `score` 显示完整角色面板：称号"普通百姓"、"你是扬州人氏，天性光明
  磊落，还没有拜师"，四项天赋 20/20/20/20，气血食水槽全满，战斗数值
  已初始化——和选择的出生地、品性一一对应，没有发现数值错配。
- `board` 列出这份档案的留言板系统，一共 47 块，几乎覆盖了金庸小说里
  所有主要门派/阵营：少林、武当、全真派、桃花岛、丐帮（暗含）、明教、
  嵩山、泰山、青城（五岳剑派对应《笑傲江湖》）、日月神教、灵鹫宫、
  星宿派、慕容家、神龙教、血刀门、逍遥派、天地会、雪山寺、侠客岛
  等——这不是单一某部小说的题材，而是把金庸武侠宇宙里的多部作品揉进
  了同一个世界观，是这份档案区别于其它"金庸题材" mudlib 的一个具体、
  可验证的特征，值得写进 README 的内容亮点。
- `quit` 干净退出，"欢迎下次再来！"，"【系统报告】离线精灵：浮浮
  (fluffos)离开游戏了。"，无残留错误。

### 已知但不是本次范围内 bug 的观察

重新登录测试时撞上了"您要将另一个连线中的相同人物赶出去，取而代之
吗？(y/n)"——是 `check_ok()` 里正常的"同一角色已有一个连线存在"保
护逻辑（旧连线的 `quit` 和新连线的重新登录之间存在一个正常的竞态窗
口），不是 bug，是预期的多重连线保护设计，符合 AGENTS.md §10.7 第 5
条记载的"quit 保留窗口"现象。

### 未覆盖范围（诚实说明，未做代码审查冒充实测）

本轮预算集中在把"投胎"全流程和两个阻断性 bug 排查清楚，没有走到：
战斗（`木人`训练木人在 `d/guanwai/`，离出生点扬州有一段路）、拜师、
经济系统/商店、以及门派加入。这些留给下一轮深入测试；目前的验证边
界到"进入游戏世界 + score + board + quit"为止，如上所述。

## 深度功能测试（第二轮，2026-08-18）——发现并修复两个真实 bug：messaged.lpc 的 socket_bind() 崩溃、eval-cost 过低

补完上一轮留下的战斗/门派测试，过程中发现并修复两个真实 bug。

- **发现并修复：`adm/daemons/network/messaged.lpc` 的 `startup_udp()`
  第一次被触发时崩溃**（§7.52 类，本档案自己已经确认过的同一类问
  题的漏网之鱼）：用巫师账号第一次执行 `goto` 指令时（触发
  `messaged.lpc` 首次懒编译/初始化），撞上
  `执行时段错误：*Bad argument 2 to socket_bind(); Expected: int
  Got: "10"`。追根溯源：`create()` 里 `my_port = LOCAL_PORT() +
  MESSAGE_PORT;`，`LOCAL_PORT()` 宏是
  `(int) get_config(__MUD_PORT__)`——这个 `(int)` 转型只在编译期
  有效，`get_config()` 实际运行时返回的不是数字（这个驱动版本上这
  个 config key 的取值行为和预期不一致），所以 `LOCAL_PORT()` 真
  正返回的是一个空字符串，`"" + 10`（LPC 里字符串 + 整数是字符串
  拼接，不是数值相加）就得到了字符串 `"10"`，传给要求 `int` 类型
  的 `socket_bind()` 直接崩溃。这份档案的 `adm/daemons/versiond.lpc`
  在更早一轮（2026-07-31）就已经因为完全同一类"socket 包在这个驱
  动环境下不可用"的问题被按 AGENTS.md §7.52 掏空过 13 个函式，但
  `messaged.lpc`（同样是碰 UDP socket 的收发信件精灵）当时被漏掉
  了。修复：按同一手法把 `startup_udp()` 掏空成直接 `return 0`（跨
  MUD UDP 消息在这个环境下本来就不可用，让它安安静静地做无害的
  no-op），顺手给 `send_udp()` 加了 `!socket_id` 的保护（原本没有
  判断 `socket_id` 是否真的建立成功就直接呼叫 `socket_write()`）。
  **现场验证**：重启全新驱动进程，`goto` 现在干净执行，`debug.log`
  里不再出现任何 `socket_bind`/`Bad argument` 记录。
- **发现并修复：`config.fluffos` 的 `maximum evaluation cost` 撞上
  §7.90 已确立的"后台任务精灵"变体**：`debug.log` 里出现两条
  `Eval interrupted: ... cost limit reached, limit: 700000 usec` →
  `*Too long evaluation. Execution aborted.`，调用点分别是
  `d/xueshan/obj/yinlun#96` 和
  `kungfu/class/generate/questnpc#275`——都是这份档案自己非常活跃
  的后台"任务精灵"系统（游戏内持续能看到"【系统报告】任务精灵：
  进程(...)创建了一个任务"的滚动播报）动态生成 NPC/物件时的冷编译
  开销，不是玩家直接触发的。按 §7.90 已确立的标准修复，从 700000
  （本项目模板默认值）提到 5000000（本项目内 30+ 档案已经在用的同
  一个值）。**现场验证**：重启后驱动空转约 30 秒（任务精灵系统持
  续在后台生成任务），`debug.log` 全程零 `cost limit reached` 记录。
- **战斗测试**：练功房的木人（`clone/npc/mu-ren.lpc`）继承自
  `inherit/char/fighter.lpc` 的 `accept_fight()`/`accept_hit()`，
  两者都要求 `ob->query("combat_exp") >= 12000` 才允许练功
  （"你这点身手还不足以和木人练功。"）——一个全新角色的
  `combat_exp` 默认是 0，永远达不到这个门槛。这不是一个可以直接判
  定为程序 bug 的发现（`combat_exp` 门槛属于内容/数值设计范畴，按
  本项目既有的"深度测试范围限定在程序 bug"原则不去动它），只是如
  实记录：这个具体的木人可能是给中高阶角色用的进阶陪练目标，不是
  绝对新手的第一个练功对象，真正给新手用的陪练（如果存在）需要下
  一轮另外去找。
- **门派加入、经济系统仍未测试**：本轮时间预算集中在排查上面两个
  真实 bug，没有再去找门派拜师的 NPC 或商店，留给下一轮。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
