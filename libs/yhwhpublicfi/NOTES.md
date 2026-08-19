
## WASM 修复摘要（迁移自 meta.json 的 group_note）

炎黄武魂public-final-2016-12-08——一个 Doing 血统的构建版本（master.lpc 的档头注明'ES II mudlib... updated by Doing Lu for hell (2K), modified by Linux@lxtx for yh 2003.3'），游戏内标题是《武林群侠传》之炎黄武魂。注册流程用姓+名分开输入（get_surname/get_name），有双重管理员+登录密码，一个 5 选项的角色类型菜单（猛士/智慧/耐力/敏捷/均衡）代替天赋重投，没有电子邮件步骤。WASM 修复了：（1）经典的 §8.1 GBK 字节区间 is_chinese()（奇偶门槛加 176-247/161-254 字节区间检查）重写成对每一个字符（不只是第一个）都做逐码点 0x4e00-0x9fff 循环检查。（2）三处各自独立的、来自同一个 §8.1 血统的字节数翻倍长度界限 bug，全部减半以匹配这个驱动按码点计的字符串索引方式：check_legal_name() 的最小界限（strlen<2 → strlen<1）和它的最大长度界限（maxlen → maxlen/2），get_name() 里姓+名合并后的最小长度（strlen(fname)<4 → <2），以及 named.lpc 的 invalid_new_name() 滑动窗口近似名字去重检查（最小值 2→1，窗口切片 name[i..i+3]/name[i..i+5] → name[i..i+1]/name[i..i+2]，循环界限 l-4 → l-2，闸门 i+6<=l → i+3<=l）——不修的话，像'张'这样的单字姓氏会被拒绝为'太长'，任何两个字的全名都会被拒绝为'太短'。（3）master.lpc 的 valid_read()/valid_write()（不同寻常地位于 adm/single/master.lpc，不是常见的 adm/obj/master.lpc）在转发给 SECURITY_D 之前缺少标准的 'user == this_object()' 短路判断——两处都已加上，修复了那种静默的 new() 注册卡死失败模式。（4）versiond.lpc 的 in_server() 呼叫 get_config(__MUD_PORT__) + VERSION_PORT，期待一个整数，但 WASM 驱动的 get_config(__MUD_PORT__) 在这里没有解析成期待的类型，产生一个字符串拼接出来的端口号（'12'），在每次启动时都触发'Bad argument 2 to socket_bind()'崩溃；按照 AGENTS.md §7.52（和 hell/hell 家族对同一个 versiond.lpc 血统几乎一字不差的先例一致），把全部 13 个碰 socket 的函式（in_server、connect_server、clear_syn_info 里的 socket_close 循环、send_command、send_client_pending_msg、syn_finish 里的 socket_close、in_listen_callback、in_write_callback、in_close_callback、cmd_close、send_pending_msg、send_result、remove_connection 里的 socket_close）都掏空成 no-op/notify_fail，保留周围不碰 socket 的版本追踪逻辑不变。（5）§7.50 类的 is_killing(object) 对 is_killing(string id) 类型不匹配，修复了 15 处呼叫点（kungfu/skill/*.lpc 的 10 处命中、clone/user/user.lpc、clone/lonely/sheying.lpc、d/city/npc/guidao.lpc、cmds/std/surrender.lpc、cmds/std/ansuan.lpc），全部用标准的 ->query("id") 包装函式修复。adm/daemons/ftpd.lpc 和 adm/daemons/network/dns_master.lpc 都处于休眠状态（在 adm/etc/preload 里被注释掉，除了各自 network/ 子目录之外没有其它运行时呼叫者）——保持原样未做改动。管理员账号播种：wlqxztest (admin) 加入 adm/etc/wizlist（wiz_levels 顶层是 (admin)；wizlist 查找只按 ID 字符串，所以一个刚注册的角色马上就能显示管理员状态，不需要额外的存档/重新登录步骤）。注册流程多次完整验证过：英文 id→y（确认新角色）→姓→名→管理员密码+确认→登录密码+确认→角色类型菜单（1-5，用的 5）→性别（m/f）→进入世外桃源，全程干净。管理员权限已通过'目前权限：(admin)'确认。score 指令需要先在游戏内完成一个单独的'出生'步骤才能报数据，这是有意为之的游戏设计门槛，不是 bug，保持原样。LPC 格式化工具对全部 10751 个档案运行（写入 10715 个，6 个针对杂乱历史代码的转档之前就存在的错误，30 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 61 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-07）

本轮之前 `yhwhpublicfi` 只做过 WASM 阶段的注册冒烟测试和 §7.86 的编
译级扫描修复，从未做过完整的 §10.7 深挖。这次用原生驱动
（`~/src/fluffos/build-debug/src/driver`，端口 40132）从 AGENTS.md
已知 bug 类别清单逐项排查，并与同血统手足档案 `zjdywzb`/`zjdy2008wzb`
（同为 Doing 系 "hell" 血统的独立分支，本 session 早前已深挖）做了
对照检查。全程用 `scripts/mudclient.py`（`--idle 0.5`-`0.6`）驱动；
`scripts/tmux_mud.sh` 在一次 `born <地名> <名字>` 的中文+空格组合输
入上出现了 AGENTS.md §10.2 记录过的本地 telnet 二进制吞字节现象（连
接卡死、后续任何指令包括 `look` 都没有任何回应），改用
`mudclient.py`（裸 socket，不经过本地 telnet 进程）后同一条指令立刻
正常执行——按文档指引确认是传输层问题，不是服务器端 bug。

### 找到并修复的 bug

- **§7.88 复现，位置不同：`message()` 包装函式同一个 4 参数必填/
  3 参数呼叫的缺口，这次在预加载阶段就会炸**：`adm/simul_efun/
  message.lpc` 的 `message(mixed arg, string message, mixed target,
  mixed exclude)` 声明了 4 个必填参数直接透传给 `efun::message()`，
  但同一份档案里 `tell_object()`（`message("tell_object", str, ob)`）
  和 `write()`（`message("write", str, this_player())` /
  `message("write", str, previous_object())`）两处呼叫都只传了 3 个
  参数。第一次干净重启驱动就立刻在预加载期间炸出
  `*Bad argument 4 to EFUN message() Expected: object, array, Got:
  int(0).`（`adm/daemons/analectad.lpc` 的 `create()` 经
  `channeld.lpc` 的 `do_channel()` 触发），说明这不是要等玩家操作才
  会撞上的边缘情况，而是每次开机都会命中的系统级频道广播路径。和
  `zjdywzb` 一样，这条崩溃也埋伏在角色创建"选品质"一步——在"桃源石
  屋"对 NPC 花铁干 `out` 离开时，`hua.lpc` 的 `check_leave()` 先呼叫
  `command("chat ...")`，触发同一处崩溃，把 `valid_leave()` 判断房
  间放行"之前"的呼叫链整个打断（房间不放行离开，角色永远卡在桃源
  石屋，紧跟着的 `me->set("character", ...)` 也永远不会跑）。修复：
  `varargs void message(...)`，缺失的 `exclude` 参数补上
  `|| ({})` 兜底（和同一文件里 `tell_room()` 已经用的写法一致）。
  实测：修复前干净重启后预加载阶段必现该崩溃；修复并重启后预加载
  期间零错误，且新角色在"桃源石屋"对花铁干 `out` 一次成功，顺利进
  入"阎罗殿"。
- **§7.89 复现，第三处受害对象：这次不是 `versiond.lpc` 而是
  `messaged.lpc`（跨服 UDP 聊天精灵），且每个新连线的第一次登录都
  可能命中**：`include/runtime_config.h` 的索引编号和驱动真实内部
  编号不一致（和 `zjdywzb`/`ds386` 是同一类问题）——此前一轮 WASM
  修复已经发现并"修好"了这个问题在 `versiond.lpc` 里的表现（按
  §7.52 掏空了 `in_server()` 等函式里的全部 socket 呼叫），但那只
  是给一个受害者打了补丁，没有修根。这次深挖发现同一份坏掉的
  `runtime_config.h` 还坑了另一个完全独立的精灵：
  `adm/daemons/network/messaged.lpc`（`MESSAGE_D`，一个跨服 UDP 聊
  天/私聊路由精灵，游戏内 `tell`/`chat`/"缥缈虚空"聊天室子系统重
  度依赖它，不是可以随手掏空的休眠精灵）。`logind.lpc` 的
  `check_ok()`（**每一次没有存量在线/断线重连身体的登录都会走到，
  不分巫师还是普通玩家**）无条件呼叫
  `MESSAGE_D->find_chatter(ob->query("id"))`，这是这份档案里第一次
  触碰 `MESSAGE_D` 的地方，触发它的懒编译；其 `create()` →
  `startup_udp()` → `socket_bind(socket_id, my_port)` 里
  `my_port = LOCAL_PORT() + MESSAGE_PORT`，而 `LOCAL_PORT()` 依赖的
  `get_config(__MUD_PORT__)`——`__MUD_PORT__` 在这份档案自带的坏头
  文件里编号成 `CFG_INT(0)` = 14，但驱动真实的内部第 14 号槽位是
  一个字符串型配置（`__MUD_IP__`）——取到的是空字符串而不是整数，
  `"" + 10` 在这台驱动上做的是字符串拼接而不是数字加法（`(int)`
  强制转型对这种类型不匹配的场景是编译期语法糖、并不真正在运行时
  强制转换），`my_port` 变成字符串 `"10"`。传给 `socket_bind()` 直
  接因参数类型不对被拒绝报错，把 `check_ok()` 从中间截断——这一步
  之后的 `make_body()`/`enter_world()` 永远不会跑。用真实游玩会话
  实测复现：一次约 12 分钟的连续测试会话中，这个崩溃只在某次连线
  第一次真正触碰 `MESSAGE_D`（不是重连/不是已有身体分支）时出现过
  一次，之后该精灵已经常驻内存，不会再重复。这次没有再用"单点掏空
  某个精灵的 socket 函式"的补丁思路，而是做了根因修复：把
  `include/runtime_config.h` 整份换成驱动自带的权威版本
  （`~/src/fluffos/src/include/runtime_config.h`），然后逐一处理三
  处仍在用旧符号的呼叫点——`versiond.lpc`（`__SAVE_BINARIES_DIR__`，
  只用于一行路径前缀比较）别名到 `__MUD_LIB_DIR__`（新头文件里始终
  有值，和 `zjdywzb`/`ds386` 先例一致）；`cmds/arch/config.lpc` 的
  `__ADDR_SERVER_IP__`（一行纯展示用的巫师 `config` 指令输出，这个
  驱动版本压根没有 addr_server 概念）直接删除这一行；同一个指令里
  的 `__BIN_DIR__`——虽然新头文件里这个符号本身还在，但这台驱动的
  `read_config()` 从来不往这个槽位写值（`rc.cc` 的 `STR_FLAGS` 表里
  根本没有对应的配置项），直接 `get_config()` 会抛错而不是安静地
  返回空字符串，所以额外包了一层 `catch()`，取不到就显示"（未
  知）"而不是让巫师的 `config` 指令崩溃。同时在 `logind.lpc` 的
  `check_ok()` 里给 `MESSAGE_D->find_chatter()` 呼叫加了
  `find_object(MESSAGE_D)` 前置判断（AGENTS.md §1.3c 的标准写法），
  作为双重保险。实测：修复并重启驱动后，用巫师账号 `tell fluffos
  hello` 主动触发 `messaged.lpc` 的懒加载，`debug.log` 零
  `socket_bind`/错误记录，指令正常回应"这个用户没有登录，你无法和
  他交谈。"；巫师 `config` 指令完整跑出 Mud 名称/Mudlib 路径/执行
  档路径（空白但不崩溃）三行加上运行时配置表，无任何报错。
- **（新增 AGENTS.md §7.81 第三例）任务系统共享的 `set_information()`
  包装函式参数类型比它转发的精灵窄，导致全部 8 种随机任务永远编译
  不出来**：`inherit/misc/quest.lpc`（被 `clone/quest/` 下每一个任
  务档案 `inherit`）声明了 `void set_information(string key, string
  info)`，只是单纯转发给 `adm/daemons/questd.lpc`/`questd2.lpc` 的
  `set_information(object qob, string key, mixed info)`——精灵那边
  第三参数本来就是 `mixed`。但 `clone/quest/{capture,shen,judge,
  deliver,search,trace,supply,explore}.lpc`（全部 8 个任务类型）的
  `register_information()` 都是 `set_information(NPC1_NAME, (:
  ask_npc1 :))` 这种传闭包的写法——对精灵的 `mixed` 契约完全合法，
  却被本地这层过窄的 `string info` 类型声明在编译期直接拒绝
  （`Bad type for argument 2 of set_information ( string vs
  function )`），8 个任务档案全部编译失败。因为这是 `clone/` 下的
  内容档案编译错误，不是启动期的致命错误（`new()` 一个编译失败的
  档案只会得到一个空程式对象），完全没有任何启动期症状——真正暴露
  出来是各任务类型自己的精灵（`adm/daemons/quest/{capture,shen,
  judge,deliver,search,trace,supply,explore}.lpc`）的 `heart_beat()`
  周期性呼叫 `start_quest()` 尝试实例化对应的 `clone/quest/*` 档案
  时，反复报 `*No program in object '/clone/quest/capture'!` 这类
  错误——8 个任务类型各自独立、周期性地反复报错，`debug.log` 里
  快速堆积。这正是 AGENTS.md §7.81 已经在完全不同血统档案 `nt1`
  上记录过的形状（同样是 `inherit/misc/quest.lpc` 的
  `set_information` 窄类型 wrapper，同样是那 8 个任务档案名字），
  这是该 bug 类别的第二次独立确认，跨越两个完全无关的血统家族
  （NT/nitan 家族 vs 本档案的 Doing/hell 家族），进一步证实这是这
  一类"共享 wrapper 类型比它转发的精灵窄"的通用陷阱，不是某个血统
  自己的独有问题。修复：把 `string info` 改成 `mixed info`（单文件
  改动，一次性修好全部 8 个任务档案，内容档案本身完全不用动）。实
  测：修复并重启驱动后，用巫师账号对全部 8 个 `clone/quest/*`
  档案逐一 `update`，全部显示"成功！"；`debug.log` 全程零"No
  program in object"/"Bad type"记录。
- **一次性会话结论：README 已记录的 §7.52 versiond.lpc 掏空补丁本
  身没有问题**（`in_server()` 等 13 处 socket 呼叫掏空后确认没有残
  留，`versiond.lpc` 独立编译、独立运作正常）——只是当时的排查止步
  于"这一个精灵不再崩溃"，没有意识到 `runtime_config.h` 的编号错位
  是可以坑到任意精灵的系统级根因，这次借着深挖顺手补上了真正的根
  因修复。

### 转档遗漏：三个从未转码的 GBK 遗留文本档案（AGENTS.md §4.1）

用整棵 `work/` 树的 Python UTF-8 解码扫描（排除 `backup/`、字体、
二进制存档等已知非文本内容）找到 3 个仍是原始 GB18030 字节、从未
被转档管线处理过的无后缀纯文本档案，和 §4.1 记录的 `yhyxs`/
`yanhuangwuhun`（同为 yh2003 血统的手足档案）**一字不差是同一批档
案**：

- `help/rules`——"游戏规则"说明，`d/register/yanluodian.lpc` 的
  `do_born()` 在每一个新角色完成投胎的那一刻自动呼叫
  `HELP_CMD->main(me, "rules")` 展示；也可以用 `help rules` 主动查
  看。实测：修复前新角色投胎完成的瞬间和手动 `help rules` 都会看到
  整屏乱码；用 `iconv -f GB18030 -t UTF-8` 转码后，同一个已投胎角
  色的 `help rules` 显示完整、语法通顺的"游戏规则"正文（"本游戏改
  编自微尘的「终极地狱」……"），无乱码。
- `clone/game/8_hlp`、`clone/game/21_hlp`——`clone/game/pai.lpc`
  （客店茶房一带的纸牌小游戏道具）用 `read_file(__DIR__ + arg +
  "_hlp")` 动态拼路径读取的"玩 8 张"/"玩 21 点"游戏说明，`helppai`
  指令会触发。转码后直接 GB18030 解码验证内容通顺（"牌桌玩8张使用
  方法：""牌桌玩21点使用方法："），未在实机上找到牌桌道具触发
  `helppai` 做二次确认（预算有限，未追踪道具具体摆放位置），按
  §4.1 的既有先例视为同一批遗漏内容，一并修复。

`kungfu/skill/huashan-quan/MFM1992`、`clone/game/{8,21}_hlp` 之外的
`clone/game/` 目录里还有几个类似命名的档案——检查过没有任何 `.lpc`
引用 `MFM1992`，是未被任何代码路径引用的死档案（`file(1)` 误判成
"OpenPGP Secret Key"，实际是随机二进制游戏数据），未做处理。
`adm/etc/font/` 下的位图字库档案（`Asc12`/`Hzk16` 等）本来就是二进
制，不在转档范围内。

### 已确认没有踩中的已知 bug 类别

- **§7.68 幽灵卡死重试守卫**：本轮测试全程没有触发角色死亡（见下），
  未观察到相关现象；不适用/未触发，按文档要求不主动移植该修复。
- **§8.3a/§8.3b 指令表**：`yhwhpublicfi` 本身已经在更早一轮的
  repo-wide `private command_hook` 扫描里被列入并修好（AGENTS.md
  §8.3a 命中列表），这次复核 `commandd.lpc`（若存在）未见
  `sscanf(...".c"...)` 残留形状；`look`/`score`/`i`/`kill`/`post`/
  `tell`/`update` 等指令全部正常响应。
- **§8.9 食物/饮水初始化**：`logind.lpc` 第 769 行本来就是
  `if (user->query("age") == 14)`，读的就是刚 `setup()` 过的
  `user` 对象本身，不是登录桩对象 `ob`——不适用，无需修复。
- **§7.92 `user_cwd()`**：`adm/simul_efun/path.lpc` 的
  `user_cwd()` 本来就是 `"/u/" + name`（扁平路径），和这份档案本
  来就是扁平的 `u/`（只有 `u/ivy` 一个巫师目录）完全匹配——不适用。
- **§7.94 指令档案丢失 `.lpc` 后缀**：`cmds/` 下大量 `.c.bak`/
  `.alias` 档案乍看像是这个类别，但逐一核对后每个 `.c.bak` 都有对
  应的、内容正常的同名 `.lpc` 现役档案（`look.c.bak`↔`look.lpc`、
  `score.c.bak`↔`score.lpc`、`set.c.bak`↔`set.lpc` 等），这些只是
  历史备份，不是丢失后缀——不适用。
- **§8.10 版本握手重试误路由**：`logind.lpc` 的三处
  `input_to("get_id", ob)` 都是同一个 `get_id()` 自身的重试分支
  （非法英文名/取消确认后请求重新输入），没有类似 Tomud 家族那种
  `get_id()`/`get_id1()` 两段式版本握手结构——不适用。
- **§8.11 `@TEXT` 内嵌宏未展开**：走查过 `logind.lpc`/
  `yanluodian.lpc` 里所有玩家可见的多行 `@TEXT` 块，未发现内嵌未
  展开的 `#define` 常量名。

### 实机游玩记录

用新注册的测试角色「秦风」（`yhwhtest`，均衡型，天性阴险奸诈，出
生地"扬州人氏"）完整跑了一遍：

1. **完整投胎仪式**：英文 id → `y` → 中文姓"秦"（单字，验证 WASM
   阶段修的字节界限 bug 没有回归）→ 中文名"风"（双字）→ 管理密码
   +确认 → 登录密码+确认 → 角色类型菜单选"5"（均衡型）→ 性别
   `m` → 世外桃源。对花铁干 `out`（触发本轮新修的 §7.88 message()
   崩溃点）→ 阎罗殿，地藏王塞了本"天书"。`washto 20 20 20 20`（四
   项天赋各 20，合计 80）→ `born 扬州人氏` → 进入"客店"，`score`
   显示膂力/悟性/根骨/身法各 20、天性"阴险奸诈"、出生地"扬州人
   氏"，和实际操作路径完全对得上。
2. **移动**：客店 → south → 客店茶房（扬州客栈茶园）→ north 回客
   店；另一条路线 west → 北大街 → south → 中央广场 → south → 南大
   街，沿途房间描述、出口列表、NPC 列表均正常显示，无一处
   "No such object"/环境缺失。
3. **留言板**：`post board` 打开内建行编辑器，输入标题正文，`.`
   结束，"留言完毕"；`look board` 显示"[ 1] board ... 秦风-
   yhwhtest"，退出重连后未读计数正确显示"1 张留言，1 张未读"——
   确认 §7.86 的跨库修复在这份档案上真实生效，不只是编译期检查。
4. **战斗**：南大街对"流氓头"（四位流氓中带头的强化个体，比普通
   "流氓"更硬）发起 `kill`，双方多回合正常拳脚攻防（命中/闪避/擦
   伤消息、伤害数字提示），秦风连续中招约 24-40 点伤害后触发游戏
   自带的"看来该找机会逃跑了……"自动脱战机制，安全撤到隔壁"赌场"
   房间，没有死亡，也没有任何崩溃或异常。之后专门去挑一般"流氓"
   （数值更弱）重新开战，同样正常攻防几回合后再次自动脱战，全程
   `debug.log` 干净。**没有触发死亡/复活循环**——这台驱动的自动逃
   跑机制在低等级角色明显劣势时会主动撤离，属于正常设计（`help
   newbie` 也提到"如果在游戏过程中你不幸身亡，则死后从鬼门关复活
   回来，到扬州的武庙，继续游戏"，说明死亡复活确有实现，但本轮预
   算内没有人为构造出一定会死的场景来强制触发；如实记录为未验证
   实况，不是"没有实现"）。
5. **退出/重连（存档路径）**：真实 `quit` 后立即重连命中"你距上次
   退出只有 N 秒钟，请稍候再登录"的退出保留窗口（设计如此，不是
   bug）；等待超过该窗口后重新登录，`你上次光临…` 时间戳正确、位
   置正确还原到"客店"（上次 quit 前所在房间），留言板未读数正确
   保留——存档/还原路径确认正常。
6. **管理员账号**：按 AGENTS.md §1.5 标准约定新增播种了 `fluffos`/
   `MudLogin2026`（这份档案此前 WASM 阶段播种的是非标准 id
   `wlqxztest`，密码在当时的会话里已自设、这次无法复用，予以保
   留、并列存在），加入 `adm/etc/wizlist`。实测 `update
   /adm/daemons/eventd`、`update /clone/quest/*`（见上）、`config`
   指令均成功，确认 `(admin)` 权限真实生效，不只是登录横幅显示。

### 一处走查但判定为内容问题、未改动

- `d/register/yanluodian.lpc` 的 `paizi` 提示文字
  "投胎乃人生大事，切记不可草率！washto选好天赋之后，就输入
  born <中文地名>。" 里 `washto` 和后面的中文之间缺一个空格/标点
  （`washto` 其实是这份档案真实的指令名，不是"wash"+"to"两个词），
  读起来容易让人以为要打"wash"再打"to"。`help/newbie` 里同样残留
  了"投胎前需要先 register 邮箱地址"的旧版流程说明，和这份档案已
  经取消电子邮件步骤、实测 `register` 指令也回应"你不是已经注册过
  了吗？不用再注册了"的现状不符。这两处都是纯文字表述问题，不影
  响任何实际指令的执行（`washto`/`born` 本身运作完全正常），按
  §10.7 的范围界定（只修程式 bug，不做内容/文案判断）如实记录，
  未改动。

## §7.100 修复（ROOM 基类多余 replace_program()，2026-08-19）

- 与其它同类档案一样，`inherit ROOM;`（`/inherit/room/room`）后面跟着
  一个多余、有害的 `replace_program(ROOM);`，给几乎每个房间物件都埋
  下了一个"首次绑定 closure 就崩溃"的休眠地雷。删除了全部 3373 处存
  活的独立调用行（40 处已注释掉的历史遗留行保持原样未动）；房间构
  建工具 `clone/misc/roommaker.lpc` 的字符串拼接模板
  （`str += "...replace_program(ROOM);..."`）里的同一形状也一并手动
  修掉，避免玩家用工具新建的房间继续继承这个 bug。`git diff --stat`
  核对为 3373 文件纯删除 + roommaker.lpc 的 1 行改写，和脚本自报数字
  完全一致。真实驱动干净启动，用本轮之前播种的 `fluffos`/
  `MudLogin2026` 管理员账号登录（`(admin)` 权限确认生效），在投胎前
  的世外桃源区域走了 6+ 个房间（entry↔roomn↔rooms 往返），debug.log
  全程零"cannot replace"/"cannot bind"行。之前批次搁置这份档案是因
  为以为只有非标准的 `wlqxztest` 管理员账号可用，重新核对 README 后
  发现本轮 §10.7 深测已经按标准约定并行播种了 `fluffos`/
  `MudLogin2026`，不需要再逆向工程注册流程。
