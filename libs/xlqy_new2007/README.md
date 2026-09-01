# 新仙侣情缘之飘渺纪元

新仙侣情缘之飘渺纪元是"仙侣情缘（早期测试版）"（xlqy_early）这套以《西游记》取经旅程为背景的仙侣题材 MUD 更完整、更成熟的一个开发版本，故事围绕西天路上的人物羁绊、仙魔恩怨展开，游戏内建有完整的门派、天赋、新闻系统，新角色创建时能自行分配体格、根骨、悟性、灵性四项天赋点数，并比 xlqy_early 多了一步正式的天赋点数确认环节；经逐字节比对确认，本档案与 xlqy_early、"浙大版"（xlqyzdb）其实是同一位作者笔下同一个世界观的三个开发快照，公共路径下 84%-86% 的文件完全相同，而本站另收录的 2001 年"知秋"存档（xianlvqiyuan）虽是更远的同源近亲，文件层面的重合度却只有约 10%。

## 内容亮点

- 详见上方简介：西游取经题材的仙侣情缘、四项天赋点数分配、与 xlqy_early/xlqyzdb 的三方同源关系。

## 在线试玩

https://mudlibs.fluffos.info/xlqy_new2007/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(admin)` —— 本 lib 的最高巫师权限（通过
  `/adm/etc/wizlist` 授予，`SECURITY_D->get_status()` 据此判定）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xlqy_new2007
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40022**。
