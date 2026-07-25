# 泥潭三 / 《終極魔界》 (nitan_san)

站点内部自称"泥潭"(nitan)，是 NT/nitan/Lonely 系列真正的"三代"正宗
版本（登陆横幅本身就打出"一入泥潭深似海"字样，驱动版本标注
"MudOS v22.2b14 NT-Build"）。实际连线看到的招牌是《終極魔界》，与它
的近亲 nitan_ceshi 一样是套在"泥潭"引擎上的一层皮肤。

## 内容亮点

- 和 nitan_ceshi 是同门师兄弟：新玩家取姓名、选性格、"洗"天赋，再到
  "生命之谷"由盘古安排投胎，才算正式踏入江湖，世界观基于盘古开天、
  转世投胎的神话设定。
- 同样**不需要外部 MySQL 数据库**，注册、存档全部走本地文件。两者
  虽然血缘很近，但各自独立演化，遇到的具体小毛病也不完全一样。

## 在线试玩

https://mudlibs.fluffos.info/nitan_san/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **普通密码 / Password**: `Mud@2026`（平时登录用这个）
- **管理密码 / Admin(recovery) password**: `Mud@2026admin`
- **中文名 / Display name**: 浮浮（姓"浮"名"浮"）
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改这两个密码。

## 本地运行

```
cd libs/nitan_san
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40055**。文件数量较多，驱动启动后需要约二十秒完成预加载。
