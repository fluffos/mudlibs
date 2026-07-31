# 海洋2000 (hy2000)

游戏内标题为"海洋II"（Ocean II），ES2/金庸题材血统的 mudlib。

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
