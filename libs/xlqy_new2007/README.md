# 新仙侣情缘之飘渺纪元

属于 ES II 引擎家族，与"仙侣情缘（早期测试版）"（xlqy_early）系出同门，
是这套仙侣情缘代码更完整、更成熟的一个版本（子标题"乱世站"）。

## 内容亮点

- 以《西游记》世界观为底色的仙侣题材 MUD，故事围绕西天取经路上的人物
  羁绊、仙魔恩怨展开。
- 游戏内建有完整的门派、天赋、新闻系统，新角色创建时能自行分配体格、
  根骨、悟性、灵性四项天赋点数。
- 相比 `xlqy_early`，注册流程更完善，多了一步正式的天赋点数确认环节。

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
