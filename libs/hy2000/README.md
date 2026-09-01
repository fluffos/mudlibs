# 海洋2000 (hy2000)

游戏内标题为"海洋II"（Ocean II），ES2/金庸题材血统的 mudlib，和
`fqyy2`（风起云涌2）同属"海洋/hy"代码线家族——两者的 `SECURITY_D` 都
指向 `adm/daemons/securd.lpc`，管理员认证也都不走常见的 wizlist 文本
文件，而是靠该 daemon 里硬编码的后门 id（此处是"无忧"）。它同时也是
`hy2002` 的底本：hy2002 在同一份约 10,630 个文件的地图基础上另外增加
了约 3,000 个文件（新地图、新门派内容），其余部分与 hy2000 完全一
致。世界在华山、武当、少林、丐帮等常规门派地图之上，还叠加了一套婚
恋玩法（`d/marry/`、`d/happy/` 场景）。

## 内容亮点

- 地图里有 `d/marry/`（结婚玩法）与 `d/happy/` 场景，配合华山、武
  当、少林、丐帮等常规门派地图。
- 管理员认证机制不走常见的 `wizlist` 文本文件，而是 `securd.lpc`
  的 `restore_list()` 里硬编码的后门 id `wuyou`（中文名"无忧"）——
  这是"海洋/hy"家族的共同特征，`fqyy2` 也是同一套机制。
- 本次修复中发现一个此前未见过的 bug 类别（新增 AGENTS.md
  §7.63）：`quit.lpc` 里生成排行榜"米袋"道具的呼叫点漏掉了其余四处
  同类呼叫都有的防御性判断，导致每次玩家退出游戏都会崩溃——修复时
  发现同一份代码库里 `topdel.lpc` 甚至留着一句注释"topten的
  magic-rice出问题了"，说明原作者自己也遇到过这个问题的一部分。
- 深度功能测试（§10.7）发现并修复了两个真正会影响游玩的 bug：全档
  案 53 块留言板的 `post` 指令必然崩溃（AGENTS.md §7.86，此前只在
  "天涯"家族见过，这是跨家族的第三次确认），以及地图第一次巡逻时
  `securd.lpc` 的自定义 ACL 把技能文件存在性检查误判为"文件不存
  在"、连带炸掉 NPC 初始化（AGENTS.md §7.5，和手足档案 `hy2002` 完
  全相同的 bug）。

## 注册流程

连线后先回答"Are you using BIG5 font [Y|N]?"（本次验证选 N/GB，选
Y/BIG5 同样可正常显示，未发现编码问题）→ 英文 id（3-12 个小写英文
字母）→ 确认建立新角色（y/n）→ 中文名字（直接输入完整姓名，无需
拆分姓氏/名字）→ 密码（设定 + 确认两次）→ 天赋数值（输入 0 交由系
统随机产生，或 1-4 自选一项，随后需再输入 y 确认这组数值）→ 电子
邮件地址 → 性别（m/f）→ 进入游戏世界。

## 本次修复的关键 bug

- `include/globals.h` 的 `MASTER_OB`/`SIMUL_EFUN_OB` 宏指向了
  `/adm/single/` 下的死代码副本，而 `config.fluffos` 实际加载的是
  `/adm/obj/master`、`/adm/obj/simul_efun`（AGENTS.md §7.56 同类陷
  阱）。已修正宏定义指向实际使用的文件。
- `adm/daemons/logind.lpc` 的 `howmany_visitor()`/`howmany_card()`：
  经典的 `sscanf(read_file(缺失文件), ...)` 在全新档案下崩溃
  （AGENTS.md §7.54），`read_file()` 对不存在的
  `/log/mud/MUDVISITOR`/`GIFTCARD` 返回整数 0 而非字符串，导致
  `sscanf` 报错。已加上 `if (!content) return 0;` 的空档案兜底。
- `cmds/usr/uptime.lpc`：同一类 bug 的变体（AGENTS.md §7.54 新增
  段落）——`write(read_file("/log/nosave/LASTCRASH"))` 在文件不存在
  时对整数 0 调用 `write()`，触发 `receive()` 参数类型错误，而且
  这个崩溃恰好发生在显示"上次当机原因"这行、紧接着英文名字提示
  之前，导致整个注册流程在连线后卡死，连提示语都不会出现，是本
  次修复中最难定位的一个 bug。已加上文件存在性判断。
- `cmds/usr/quit.lpc`：调用 `new("/clone/topten/magic-rice")` 后
  没有像同一份代码库里其余四处调用（`top10.lpc`、`topboard.lpc`、
  `topten.lpc`、`topdel.lpc`，其中 `topdel.lpc` 甚至留了一句注释
  "topten的magic-rice出问题了"）一样加上 `if(ob=new(...))` 的防御
  性判断，导致每次玩家退出游戏都会崩溃报错（新增 AGENTS.md
  §7.63）。已比照其余四处调用补上同样的判断。

## 深度功能测试（§10.7）修复的 bug

- **§8.9 变体**：`enter_world()` 的年龄判断
  `if (!user->query("food") && !user->query("water") &&
  ob->query("age") == 14)` 里，食物/饮水的空值检查用对了 `user`，但
  年龄判断仍然错误地用了登录对象 `ob`，导致食物/饮水永远不会被初
  始化。已改为 `user->query("age")`。
- **留言板 `post` 崩溃（AGENTS.md §7.86）**：全档案 53 份留言板文
  件都同时 `inherit BULLETIN_BOARD` 又多余地对自己
  `replace_program(BULLETIN_BOARD)`，导致 `post` 指令必然崩溃。这
  是这个 bug 第一次在"天涯"家族之外的代码库里被发现——证实这是这一
  代 ES2 衍生代码库的通用陷阱，不是某个家族特有的问题。已删除全部
  53 处多余调用。
- **`securd.lpc` 的 `file_size` ACL 误判（AGENTS.md §7.5）**：地图
  第一次巡逻/populate 时，`debug.log` 报出一连串 `F_SKILL: No such
  skill` 错误，但对应的技能档案其实都存在。根源和手足档案 `hy2002`
  已经确认过的一模一样：自定义 `valid_read()` 没有为
  `load_object`/`include`/`file_size` 这类纯检查用途放行，当触发
  调用的 NPC 还在自己 `create()` 内部、euid 还没设置好时，
  `file_size()` 被 ACL 拒绝、表现得像文件不存在，导致 `set_skill()`
  误判并中断那个 NPC 的初始化。已比照 `hy2002` 的修法在
  `securd.lpc` 里补上放行判断。

## 管理员账号 / Admin account

这份档案的管理员认证机制和本项目里大多数档案不同：`adm/daemons/
securd.lpc` 的 `restore_list()` 直接在代码里硬编码了一个后门 id
`set("wiz_status/wuyou","(admin)");`，**不是**常见的纯文本
`adm/etc/wizlist` 文件机制。

- **id**: `wuyou`
- **中文名**: `无忧`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员账号通过正常注册流程创建，只要英文 id 填 `wuyou` 就会自动获
得 `(admin)` 权限，已在游戏内确认 "目前权限：(admin)" 显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/hy2000
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40174**。
