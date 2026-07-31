# 妖神之争

一款以"西游记"神话世界为背景的武侠/仙侠向 MUD，新角色由西行取经的
框架切入，起手在长安城"南城客栈"落脚。

## 内容亮点

- 注册流程：`new` 触发注册 → 英文 id → 中文名字 → 密码 → 确认密码 →
  邮箱（可留空）→ 性别（m/f）→ 天赋数值（可反复 reroll，`y` 确认）。
- 天赋属性系统（膂力、胆识、悟性、灵性、定力、容貌、根骨、福缘）随机
  生成，允许拒绝重掷。

## 在线试玩

https://mudlibs.fluffos.info/yszz/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 妖神管理员
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 授予，
  `SECURITY_D->get_status()` 据此判定。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/yszz
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40192**。
