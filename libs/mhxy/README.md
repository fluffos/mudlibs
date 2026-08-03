# 梦幻西游 (mhxy)

青岛站，自 2002 年 1 月 15 日起运行，隶属于经典的"西游记"引擎家族
（与本项目转换的 xyj2000f 等同源），底层引擎标注为
MudOS V22Pre11。

## 内容亮点

- 以《西游记》神话世界观为背景：新手村是长安城中的"南城客栈"，黄飞鸿、
  孙悟空等耳熟能详的角色都以 NPC 身份出现在场景里。
- 角色拥有体格、根骨、悟性、灵性四项天赋，踏上取经之路。
- 帮会、门派、九重天/十二宫/冥界等玩法名词在角色档案里都能看到痕迹，
  整体氛围偏休闲。

## 在线试玩

https://mudlibs.fluffos.info/mhxy/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`（"身份标识"/SuperPassWord 同样是
  `Mud@2026`）
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码（及 SuperPassWord）。

## 本地运行

```
cd libs/mhxy
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40016**。
