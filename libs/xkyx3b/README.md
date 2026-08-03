# 侠客英雄传 III

属于早期国产 MudOS 自研引擎，`adm/obj` 目录结构的小型武侠 MUD，没有
明确的"系列血统"可归类——是一个独立开发的小型作品。

## 内容亮点

- 一个颇为特别的"混搭"世界：游戏登录界面自称"以金庸小说、西欧中世纪
  传说及漫画为背景"。你可以在同一个世界里遇到江湖门派、也能撞见西欧
  风格的骑士传说与漫画式的种族设定。
- 新手创建角色时要在人类、矮人、精灵、妖精、龙人、兽人之间选择种族，
  这在同类武侠 MUD 里并不常见。
- 整体规模不大（约3800个文件），游戏内公告也自称"处于试运行阶段"，
  胜在设定新颖。

## 在线试玩

https://mudlibs.fluffos.info/xkyx3b/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **显示名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— 本 lib `securityd` wiz_levels 中的最高级，
  通过 `adm/etc/wizlist` 授予（该文件在启动时被 `securityd->create()` 读入）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xkyx3b
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40036**。
