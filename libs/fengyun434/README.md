# 风云Ⅳ — fengyun434

**风云四**（风云Ⅳ，Sumxin 风云工作室出品）。属于本批次的**"风云"
（Fengyun）武侠引擎家族**，与 `fy2`、`fy2005`、`fy2qh`、
`fy3xd`、`fy3dz` 等同属一个核心引擎，各自是不同
站点/年代的内容分支。

## 内容亮点

- 以古龙武侠小说为背景的江湖世界，玩家扮演一位刚踏入江湖的普通百姓，
  选择民族（汉族/苗族/满族/蒙古族，不同民族对应不同的初始属性倾向和
  出生地点），闯荡由古龙笔下人物、门派与恩怨编织的武侠天地。
- 强调角色养成与门派归属，是典型的"风云"系武侠 MUD 玩法。
- 巫师登录设有 IP 白名单机制（本地/回环地址已一律放行）。

## 在线试玩

https://mudlibs.fluffos.info/fengyun434/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 最高级别，通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权。

> 警告：公开架站前请务必修改此默认密码。

## 本地运行

```
cd libs/fengyun434
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40011**。
