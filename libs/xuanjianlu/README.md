# 玄剑录

属于 ES II / 侠客行（XKX）引擎家族，与"侠客行 2001"等游戏同源，但拥有
自己独立的武林世界与剧情内容，核心舞台设定在明教、昆仑、侠客岛等门派
与地点之间。文件头带"Cracked by Kafei"署名，和 `xkx2000zxb` 是同一批
流通版本（`xkx2001` 本身则是"Cracked by Roath"的另一批）。

## 内容亮点

- 传统武侠题材 MUD：玩家初入江湖，会先被"侠客岛"的赏善使、罚恶使等
  人物迎接，随后展开习武、结交门派、闯荡各方势力的江湖之旅。
- 天赋分配环节可以自行指定膂力等属性的某一项，也可以让系统随机分配。
- 巫师登录在普通密码之外还要求一个独立的"巫师验证码"。

## 在线试玩

https://mudlibs.fluffos.info/xuanjianlu/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **巫师验证码 / wizard passcode**: `Mud@2026`（本 lib 的巫师登录在普通
  密码之后还会额外要求一个"巫师验证码"，两者已设为相同）
- **中文名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(admin)` —— 最高权限。授权数据存放在
  `/data/securityd.o`（`SECURITY_D` 的存档，`wiz_status`/`wiz_sites`
  两个映射），巫师登录地址限制为 `.*`（任意地址）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xuanjianlu
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40064**。
