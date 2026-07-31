# 风云II（美国版本）

以古龙小说世界观为背景的武侠 MUD（`jinyongqunxiazhuan`/XKX 框架家族
成员，与 jyqxc/jyqxc2/jyqxc2013fwq/xkx2017 共享同一份
`adm/obj/master.lpc`，但游戏内容不同，故单独编号）。

## 注册流程

`new` 触发注册 → 英文 id（3-12 个英文字母）→ 确认创建（y/n）→ 中文
名字（1-6 个中文字，留空则随机取名）→ 密码（**需同时包含大写字母、
小写字母和特殊符号，仅满足长度下限不够**）→ 确认密码 → 电子邮件
地址 → 性别（m/f）→ 民族选择（0=汉族，1=苗族，2=满族，3=蒙古族）。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`make_body()` 里的 `seteuid(getuid())` 会
  把 `create()` 刚设置好的 euid 重置为空字符串，已改为显式
  `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界（提示语说"一到六个
  中文字"，实际检查的却是字节数 2-12），已改为按字符数（1-6）+
  逐字符 `is_chinese()` 判断，并去掉隔位检查。
- `adm/daemons/securityd.lpc`：`get_status()` 加了防御性
  `mapp()`/`arrayp()` 检查（未实际观察到重入崩溃，但成本很低）。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026x`（普通密码含大小写字母 + 特殊符号，
  满足本代码线的密码复杂度要求）
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里，格式为
`id (level)`。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/fy2mg/

## 本地运行

```
cd libs/fy2mg
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40198**。
