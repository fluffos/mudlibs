# 东方故事II ＋ 侠客行 (南京河海大学校内版1.01)

ES2/侠客行系混血引擎，南京河海大学计算机学院测试版，注册流程简单
直接（无需 `new` 关键字，任意未使用的英文 id 都会触发新角色确认）。

## 内容亮点

- 注册流程：英文 id → 是否新建角色(y/n) → 中文名字 → 密码 → 确认密码
  → 邮箱（可留空）→ 性别(m/f)。
- 计算机学院测试版本，内容仍在完善中。

## 在线试玩

https://mudlibs.fluffos.info/njhhdxdes2hx/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 系统管理员
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 授予，
  `SECURITY_D->get_status()` 据此判定。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/njhhdxdes2hx
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40194**。
