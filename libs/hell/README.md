# 终极地狱之地狱无门 (hell)

游戏内标题为 "REVIVE OF ULTRA HELL(BLOOD & MAGIC) FROM 1999.11.13"（作者
自称"doing"），是一个 Doing 血统的大型金庸题材 mudlib（超过 7000 个
LPC 文件）。

## 内容亮点

- 这是"地狱"/Doing 血统家族（`zjdy2008wzb`/`zjdywzb` 等档案都同源，
  `yhwhpublicfi`/炎黄武魂的 `master.lpc` 文件头也明确写着自己是在
  这份"hell"档案基础上二次修改而来）
  的原始档案，超过 7000 个 LPC 文件，是本项目里规模最大的金庸题材
  泥潭之一。
- 独特的"投胎"新手引导：新角色进入游戏后并不能直接玩——必须先用
  `register <email>` 登记邮箱，再用 `reincarnate` 类指令"投胎"成人，
  在此之前 `score` 等指令都会提示"还没有出生呐"。这比常见的"选完
  性别就直接进游戏"要多一道仪式感的关卡。
- 角色类型菜单（1-5，直接回车默认均衡型）搭配姓氏+名字分离输入，
  和同家族的 `zjdy2008wzb`/`zjdywzb` 一致。
- 本次修复过程中新发现并记录进 AGENTS.md 的两个 bug 类别（§7.61
  `message()` 的 `exclude` 参数缺省值、§7.62 `check_legal_id()` 对
  空字符串的循环失效），后来都在其它档案里复用了同样的修法。

## 注册流程

英文 id（3-10 个小写英文字母）→ 确认建立（y/n）→ 中文姓氏（0-2 个汉
字，可留空跳过）→ 中文名字（1-2 个汉字，姓名合计至少 2 个汉字）→
管理密码（≥5 字元）→ 确认管理密码 → 普通密码 → 确认普通密码 → 角色
类型（1-5，直接回车默认均衡型）→ 性别（m/f）→ 进入游戏世界。进入游
戏后需要用 `register <email>` 命令注册邮箱，然后才能用 `reincarnate`
类命令投胎做人，此前 `score` 等命令会提示"还没有出生呐"，这是正常的
游戏设计，不是 bug。

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
