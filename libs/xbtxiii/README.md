# 雄霸天下III

真正的 1997-2001 年代 mudlib（按其自带 readme 所述），一个"风云"衍生
分支。原始归档以 4 个分卷 zip（XB.ZIP.1-4）形式提供，解开后内层是
12 个按目录拆分的 tar.gz，而非扁平目录树。

## 注册流程

`new` 触发注册 → 英文 id（3-10 个英文字母，游客请用 `Guest`）→ 确认
创建（y/n）→ 中文名字（1-6 个中文字）→ 密码 → 确认密码 → 性别（m/f）
→ 电子邮件地址 → 人物属性类别（A-L，12 种任选一）→ 天赋确认（Y/N）
→ 职业选择（`enchanter` 魔法师 / `fighter` 武士，英文拼写）→ 职业确认
（y/n）→ 进入一个简短的新手教程房间，再走到真正的起始区域。

## 内容亮点

- 角色创建混合了西式 MUD 的职业体系和中文武侠包装：性别之后要从
  A-L 共 12 种属性类别里选一种，再从英文拼写的 `enchanter`（魔法
  师）/`fighter`（武士）里选职业——比本项目大多数依赖门派/宗师体
  系的档案更接近经典 DikuMUD 式设计。
- 地图里能看到"雪"（`d/snow/`、`d/dsnow/`）、"冰火"
  （`d/icefire/`）、"红/绿"（`d/red/`、`d/green/`）等偏向意象化、
  而非地理写实的场景命名，和常见的"长安/洛阳"式城池命名习惯不同。
- 原始压缩包本身就是分卷 zip（4 部分）套 12 个按目录拆开的
  tar.gz，不是扁平目录树，转换前需要先拼接解压。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`make_body()` 里的 `seteuid(getuid())` 会
  把 `create()` 刚设置好的 euid 重置为空字符串，已改为显式
  `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界，已改为按字符数
  （1-6）+ 逐字符 `is_chinese()` 判断。
- `adm/daemons/network/dns_master.lpc`（互联 UDP daemon）和
  `adm/daemons/network/smtp.lpc`（原始 SMTP 发信 daemon）都无条件调用
  `socket_*` efun，导致各自整个文件编译失败——前者会让**每一次连线**
  的登录都静默卡死（启动流程会间接触碰它），后者会让 `natured.lpc`
  的周期性检查报错。均已按 AGENTS.md §7.52 的模式把涉及 socket 的函
  数体清空为 no-op。
- 缺失的 `/topten/` 目录导致 `toptend.lpc` 在每次角色进入游戏世界时
  存档失败崩溃，已 `mkdir -p` 补上。
- `cmds/usr/score.lpc` 里 `100*.../EXPLORE_D->query_total_explore()`
  未做零值防御——在探索数据尚未被任何人扫描过的全新安装上，
  `query_total_explore()` 合法地返回 0，导致 `score` 指令必崩，已加
  三元判断防御。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/xbtxiii/

## 本地运行

```
cd libs/xbtxiii
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40201**。
