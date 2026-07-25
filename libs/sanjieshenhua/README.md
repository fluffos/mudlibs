# 三界神话 (San Jie Shen Hua) — 春节版

与 `sanjiechuanshuo`（三界传说）标题相近，但为独立开发的不同代码库
（核心文件差异巨大，非同一引擎的分支）。

## 内容亮点

- 以"三界"神话世界观为背景，新角色从"南城客栈"起步。
- 可从六种角色类型中选择一种：刀剑侠/魔法师/终结者/精灵族/均衡型/
  暗黑地狱使者——比一般武侠 MUD 更偏奇幻杂糅的职业设定。
- 注册需设置两组密码：一组"普通密码"用于日常登陆，另一组"管理密码"
  在忘记普通密码时可用来找回。
- 同账号退出后有 60 秒冷却期（巫师账号不受此限制）——是这套引擎自带
  的防灌水机制。

## 在线试玩

https://mudlibs.fluffos.info/sanjieshenhua/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **普通密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 中的
  `fluffos (admin)` 行授权。
- 注：本版本还有一个可选的"WIZPWD"巫师密码机制，但本档尚未设置，
  登录时按回车即可跳过（原始设计允许如此）。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/sanjieshenhua
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40098**。
