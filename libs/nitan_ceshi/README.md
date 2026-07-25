# 泥潭III测试版 / 《終極魔界》 (nitan_ceshi)

站点内部配置自称"泥潭三"(nitan.3)，但连线后看到的实际招牌是《終極
魔界》("Ultimate Demon Realm")——一个套在"泥潭"引擎上的主题皮肤。
属于 NT/nitan/Lonely 一脉（与本项目转换的 nitan170911、nitan6、
nitan_san 同源），是这条脉络里比较早期的一个内部快照版本。

## 内容亮点

- 传统的中文武侠/仙侠泥巴：新玩家要先取姓名、选性格、"洗"天赋点数，
  再到"生命之谷"由盘古安排投胎，才算真正"出生"进入江湖。
- 世界观走的是盘古开天、转世投胎的神话路线，登陆后的常驻场景是客店
  一类的传统江湖据点。
- 与同系的 nitan170911 不同，这一支**不需要外部 MySQL 数据库**，
  注册与存档全部走本地文件，开箱即可完整体验注册到游戏内的整个流程。

## 在线试玩

https://mudlibs.fluffos.info/nitan_ceshi/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **普通密码 / Password**: `Mud@2026`（平时登录用这个）
- **管理密码 / Admin(recovery) password**: `Mud@2026admin`
  （本库注册时强制设置一个与普通密码不同的"管理密码"，用于找回；
  用管理密码登录会强制要求重设普通密码）
- **中文名 / Display name**: 浮浮（姓"浮"名"浮"）
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改这两个密码。

## 本地运行

```
cd libs/nitan_ceshi
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40054**。文件数量较多，驱动启动后需要二三十秒完成预加载。
