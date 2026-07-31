# 幻想西天加强版

游戏内标题为"西行战记"（MudOS v22pre11 MudLib Build 3310），一个西
游记题材的传统 GB/BIG5 双编码 ES 血统 mudlib。

## 注册流程

进入后先选择编码 GB/BIG5（gb/big5）→ 是否为中小学生或更小年龄的提
醒（yes/no，答 yes 会被劝退）→ 英文 id（键入 `New` 触发新玩家注
册，3-8 个小写英文字母）→ 中文名字（1-6 个汉字）→ 密码（≥5 字元）
→ 确认密码 → 电子邮件地址 → 性别（m/f）→ 天赋数值调整菜单（选
`9` 接受当前设置，再输入 `y` 确认）→ 进入游戏世界。

## 本次修复的关键 bug

- `adm/daemons/convertd.lpc`：经典的希腊字母对照表多余反斜杠
  bug（AGENTS.md §6.6），45 处 `"α\",` 应为 `"α",`，导致
  `convertd.lpc` 编译失败，进而在 `logind.lpc` 的 `logon()` 里
  `cat("/adm/etc/banner")` 崩溃，断开每一个新连接。
- `adm/daemons/logind.lpc` 的 `check_legal_name()`：经典的 GBK 字
  节区间长度假设 bug（AGENTS.md §8.1）——长度界限按字节数写成
  `strlen(name)<2||>12`（应为按字符数 `<1||>6`，错误提示"一到六
  个中文字"本身就说明了正确的字符数意图）、`i%2==0` 的 GBK 双字节
  对齐门槛、以及 `name[i..<0]` 尾部切片判断，在这个驱动按字符计数
  的 `strlen()`/码点索引下全部失效。`adm/simul_efun/chinese.lpc`
  的 `is_chinese()` 本身已经是正确的码点区间判断，不需要改动。
- GB/BIG5 编码选单（AGENTS.md §8.7）：实际连线测试发现选择 BIG5
  会导致后续所有中文文字被判定为"Invalid GB code"而无法正常显
  示——`feature/encoding.lpc` 的编码转换表基于原始 GB2312 字节设
  计，在 UTF-8 转换后已经失效。已将 `adm/daemons/logind.lpc` 里
  BIG5 选项也映射到 GB（直通）编码，两个选项现在都能正常显示。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里；账号本身通过正常
注册流程创建，"目前权限：(admin)" 已在游戏内确认显示正确。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/hxxtjqb
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40177**。
