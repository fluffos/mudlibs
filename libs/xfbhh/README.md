# 洪荒世界（修复版）

NT/泥潭（nitan）血统，与 `hhsj`（洪荒世界原版）和 `nitan170911` 共享
byte-identical 的 master 文件。新角色从「泥潭注册室」开始。

## 内容亮点

- **注册协议**（非常规 telnet 提示，与 hhsj 同源）：连线握手后，登录行
  可用逗号分隔（`id,密码,密文,邮箱`，内部自动转换为 `║`），但新角色
  创建行必须用字面 `║`（U+2551）分隔：`性别║头像║昵称`
  （如 `0║0║秦风`）。
- `score` 会提示"还没有出生呐"——与 hhsj 相同的"降生"仪式设计，
  不是 bug。

## 在线试玩

https://mudlibs.fluffos.info/xfbhh/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮（4 字以内，本 lib 中文名限 2-4 字）
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 授予，
  `SECURITY_D->get_status()` 据此判定。
- 登录时请使用 `fluffos,Mud@2026,x,x@example.com` 格式。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xfbhh
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40190**。
