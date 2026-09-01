# 终极地狱之地狱无门 (hell)

游戏内标题为 "REVIVE OF ULTRA HELL(BLOOD & MAGIC) FROM 1999.11.13"（作者自称"doing"），是本项目收录规模最大的金庸题材 mudlib 之一（超过 7000 个 LPC 文件），改编自金庸小说《侠客行》，建立在"东方故事Ⅱ"（Eastern Story II）引擎之上，出生地扬州客店由原著角色戚长发坐镇。它也是本项目里"地狱"/Doing 血统家族的源头：`zjdy2008wzb`、`zjdyaryl`、`zjdywzb`、`zjdyzj` 都与它大量复用同一份地图内容（字节级比对显示 67%-88% 的地图重合），`yhwhpublicfi`（炎黄武魂）的 `master.lpc` 文件头明确写着自己是在这份档案基础上修改而来，`zjmudhell`（指尖MUD）则保留了 67% 相同的地图，却把核心系统整体重写成配合自定义手机 App 协议的实现。新角色要经历一场真正的"投胎"仪式而非简单的选性别流程：注册邮箱并确认、走到不同 NPC 面前选择品性（其中一支的开场白直接点名郭靖、萧峰）、途经阎罗殿（十殿阎罗、牛头马面、地藏王坐镇）、在忘忧池中随机洗四项天赋，最后从包含慕容世家、欧阳世家、段氏皇族、关外胡家等《天龙八部》相关出身在内的 18 个地名中选择投胎地。47 块留言板覆盖了少林、武当、明教、逍遥派、天地会等几乎金庸小说宇宙里所有主要门派，并不局限于单一小说。

## 内容亮点

- 这是"地狱"/Doing 血统家族（`zjdy2008wzb`/`zjdywzb` 等档案都同源，
  `yhwhpublicfi`/炎黄武魂的 `master.lpc` 文件头也明确写着自己是在
  这份"hell"档案基础上二次修改而来）；`zjmudhell`（指尖MUD）的地
  图也和这份档案逐字节相同，但核心系统档案被完全重写成配合自定义
  手机 App 协议的实现，是"地图沿用、引擎重做"的一个特例
  的原始档案，超过 7000 个 LPC 文件，是本项目里规模最大的金庸题材
  泥潭之一。游戏规则文本里明确写着"本游戏改编自「侠客行」，原是建
  立在「东方故事Ⅱ」MUDLIB 上"——不是笼统的"金庸题材"，而是有明确
  的原著出处（金庸小说《侠客行》），出生地扬州客店就有戚长发（"躺
  尸剑门传人"）等原著角色坐镇。
- 独特的"投胎"新手引导，仪式感比常见的"选完性别就直接进游戏"重得
  多：`register <email>` 登记邮箱 → `decide` 确认 → 走到不同 NPC
  跟前用 `out` 选择品性（如"光明磊落"一支的陆天抒，开场白直接点名
  "郭靖、萧峰"两位金庸主角）→ 到阎罗殿（十殿阎罗、牛头马面，地藏王
  端坐大堂，气氛渲染和游戏"地狱"主题呼应）→ `wash` 跳入"忘忧池"随
  机洗四项天赋 → `born <地名>` 正式投胎。此前 `score` 等指令都会提
  示"还没有出生呐"。
- `born` 的目的地清单（`look paizi` 查看）一共 18 个选项，除了苏州、
  杭州等常见地域外，还有"慕容世家""欧阳世家""段氏皇族""关外胡家"
  四个直接对应《天龙八部》里慕容复、欧阳锋、大理段氏、丐帮相关家族
  的特殊出身，是有心思的金庸世界观还原。
- 留言板系统一共 47 块，覆盖了金庸小说宇宙里几乎所有主要门派：少林、
  武当、全真、桃花岛、明教、嵩山、泰山、青城、日月神教、灵鹫宫、星
  宿派、慕容家、神龙教、血刀门、逍遥派、天地会、雪山寺、侠客岛……
  不只取材自单一小说，而是把多部金庸作品的门派体系揉进了同一个世
  界观，这一点在同类"金庸题材" mudlib 里也是比较突出的。
- 角色类型菜单（1-5，直接回车默认均衡型）搭配姓氏+名字分离输入，
  和同家族的 `zjdy2008wzb`/`zjdywzb` 一致。
- 本次修复过程中新发现并记录进 AGENTS.md 的两个 bug 类别（§7.61
  `message()` 的 `exclude` 参数缺省值、§7.62 `check_legal_id()` 对
  空字符串的循环失效），后来都在其它档案里复用了同样的修法。深度功
  能测试（见下）又额外发现两个**阻断性**的 bug——`MESSAGE_D` 未加保
  护呼叫、`command_hook` 权限降级——两者任一未修都会让全新玩家完全
  无法完成注册。

## 注册流程

英文 id（3-10 个小写英文字母）→ 确认建立（y/n）→ 中文姓氏（0-2 个汉
字，可留空跳过）→ 中文名字（1-2 个汉字，姓名合计至少 2 个汉字）→
管理密码（≥5 字元）→ 确认管理密码 → 普通密码 → 确认普通密码 → 角色
类型（1-5，直接回车默认均衡型）→ 性别（m/f）→ 进入游戏世界。进入游
戏后需要依次完成"投胎"仪式：`register <email>` 注册邮箱 → `decide`
确认 → 走到某位 NPC 跟前 `out` 选择品性 → `wash` 洗天赋 →
`born <地名>`（地名清单见 `look paizi`）正式投胎，此前 `score` 等命
令会提示"还没有出生呐"，这是正常的游戏设计，不是 bug。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc` 的 `check_legal_id()`：`while (i--)` 循环
  对空字符串（`strlen(id)==0`）根本不会执行循环体，直接落到
  `return 1`，把空的英文 id 当作合法输入接受。后续
  `clone/user/login.lpc` 的 `query_save_file()` 对空 id 取
  `my_id[0]` 得到整数 0，传给 `sprintf("%c", 0)` 崩溃退出，报错信息
  和真正的 bug 位置相距甚远。已在循环前显式拒绝空字符串（新增
  AGENTS.md §7.62）。
- `adm/simul_efun/chinese.lpc` 的 `is_chinese()`：沿用旧版 GBK 字节
  区间判断，在这个驱动上 `strlen()` 按字符计数、`str[i]` 是 Unicode
  码点而非原始字节，真实的中文姓名永远无法通过检测。已改为码点区
  间判断（`0x4e00`-`0x9fff`，AGENTS.md §8.1）。
- `adm/daemons/logind.lpc` 的 `check_legal_name()`
  以及 `adm/daemons/named.lpc` 的 `invalid_new_name()`：三处独立的
  字节数长度界限（假设每个汉字占 2 字节 GBK），在字符计数的
  `strlen()` 下全部偏大一倍——姓氏/名字各自的长度界限、姓名合计的
  最短长度界限、以及 `invalid_new_name()` 内用于查重的滑动窗口
  （`name[i..i+3]`/`name[i..i+5]`）都按 AGENTS.md §8.1 的既定手法减
  半修正。
- `adm/simul_efun/message.lpc` 的 `message()`：3 参数调用时
  `exclude` 是未初始化的整数 0，直接传给
  `efun::message()` 导致 `Bad argument 4 to EFUN message()`——不只
  影响 `tell_room()`（已知的 §7.12 形状），`channeld.lpc` 的
  `do_channel()` 广播和 `questd.lpc` 的
  `collect_all_quest_information()` 心跳都各自独立触发同样的崩溃。
  已直接在 `message()` 包装函数内加 `exclude || ({})` 兜底（新增
  AGENTS.md §7.61）。
- `clone/user/user.lpc` 的 `accept_kill()`：`is_killing(ob)` 传入
  物件而 `is_killing()` 期望字符串 id（AGENTS.md §7.50，第四个独
  立发现同一 bug 的血统），导致整个玩家身体类无法编译。已改为
  `is_killing(ob->query("id"))`。
- `adm/daemons/versiond.lpc`（~2200 行的版本同步守护进程）：纯
  socket 功能在 WASM 下无法编译，按"禁用整个文件的入口点"方式清空
  为 no-op（AGENTS.md §7.52，和 `zjmudhell`/`shujian3` 的同名文件
  近乎字节相同），共 13 处：`in_server()`/`connect_server()`/
  `send_command()`/`send_client_pending_msg()`/`syn_finish()`/
  `in_listen_callback()`/`in_write_callback()`/`in_close_callback()`/
  `cmd_close()`/`send_pending_msg()`/`send_result()`/
  `remove_connection()`/`clear_syn_info()` 内的 `socket_close()`
  分支。整个文件因为散落各处的 `socket_*` 调用无法编译，运行时会
  导致 `logind.lpc` 的 `logon()` 崩溃（`*No program in object
  '/adm/daemons/versiond'!`），断开每一个新连接。
- 本地存档目录 `log/nosave/` 在这份档案里不存在，导致每个新连接一
  进来就在 `logon()` 写日志时报错断线。已本地创建该目录。

### 深度功能测试（第二轮）新发现的两个阻断性 bug

此前的验证只做到"看到世界入口房间"，从未真正走完新玩家的"投胎"流
程；本轮完整实测后发现两个此前从未触发过的严重 bug，任一未修都会让
**全新玩家完全无法完成注册**（细节见 `NOTES.md` 的"深度功能测试"一
节）：

- `adm/daemons/logind.lpc` 的 `check_ok()`（每次密码校验通过后都会
  执行）未加保护地呼叫 `MESSAGE_D->find_chatter(...)`。`MESSAGE_D`
  （聊天/UDP 精灵）自己的 `create()` 有原始 `socket_create()`/
  `socket_bind()` 呼叫，WASM 下编译不过，导致密码验证成功之后连线
  直接静默断开，永远看不到欢迎信息。已加 `find_object(MESSAGE_D)`
  保护（AGENTS.md §1.3(c)，`yanhuangwuhun`/`yhyxs` 已知同类 bug 的
  第三个实例）。
- `feature/command.lpc` 的 `command_hook` 声明为
  `private nomask`，在这个驱动上继承后会从 `private` 降级为
  `DECL_HIDDEN`，导致 `add_action("command_hook", "", 1)` 这种"捕获
  所有指令"的注册方式对 `ORIGIN_EFUN`（其它物件用 `command()` efun
  发起的呼叫）静默失效（AGENTS.md §8.3a）。这份档案的"投胎"引导全
  部靠 NPC 内部 `command("say/tell/nod ...")` 说话实现，所以这一个
  bug 直接卡死了 `register`/`decide` 的每一句 NPC 回应——玩家输入
  `register 邮箱` 之后 `add_action` 正确匹配、不报"什么？"，但水笙
  一句话也不说，表现上和网络问题一模一样。已去掉 `private`，保留
  `nomask`。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **管理密码 / admin password**: `Mud@2026Adm`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常注
册流程创建，"目前权限：(admin)" 已在游戏内确认显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/hell
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40114**。
