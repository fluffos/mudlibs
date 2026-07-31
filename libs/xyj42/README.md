# 西游记 4.2

以西游记世界观为背景的 MUD。（`西游记4.2.rar` 是本归档纯换行符差异
的重复版本，只处理了一次。）

## 注册流程

`new` 触发注册 → 英文 id（3-8 个英文字母）→ 确认创建（y/n）→ 中文
名字（1-6 个中文字）→ 密码 → 确认密码 → 电子邮件地址 → 性别（m/f）
→ 天赋数值确认（[n|y|q]）。

**注意**：本代码线是先问电子邮件、再问性别（与部分同类 lib 的顺序
相反）——请务必直接阅读 `logind.lpc` 实际的 `input_to()` 调用链，
不要凭经验假设顺序。

## 本次修复的关键 bug

- `adm/daemons/logind.lpc`：`make_body()` 里的 `seteuid(getuid())` 会
  把 `create()` 刚设置好的 euid 重置为空字符串，已改为显式
  `seteuid(ROOT_UID)`。
- `check_legal_name()`：沿用旧版 GBK 字节长度界，已改为按字符数
  （1-6）+ 逐字符 `is_chinese()` 判断。
- `adm/daemons/securityd.lpc`：`get_status()` 加了防御性
  `mapp()`/`arrayp()` 检查。
- `adm/daemons/combatd.lpc`：一个 `switch(random(4))` 块的真实
  `case` 分支全被注释掉了，只留下裸的 `default:`——这个驱动不允许
  只有 `default` 没有任何真实 `case` 的 switch，导致整个文件编译
  失败，进而悄悄破坏所有涉及战斗的代码路径（错误只有在第一次真正
  调用 combatd 时才会显现）。由于被注释掉的分支本来就意味着这段代码
  从未真正做过随机分支，已直接把 `switch` 替换成普通代码块。

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **权限 / level**: `(admin)`

管理员名单存储在纯文本文件 `adm/etc/wizlist` 里。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 在线试玩

https://mudlibs.fluffos.info/xyj42/

## 本地运行

```
cd libs/xyj42
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40203**。
