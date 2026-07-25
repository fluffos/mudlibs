# 夕阳再现III之炎龙封印

游戏全名《夕阳再现III之炎龙封印》，2006 年由"阿凯工作室"（AKAI Studio）
制作，登录后能看到的实际站点名叫"江湖风云"。这是国产 MudOS 老武侠
Mud 里比较有代表性的一支，风格偏经典门派、内功修炼的江湖养成玩法。

## 内容亮点

- 传统武侠世界观：玩家从长安城一带的客栈开始闯荡江湖，围绕门派、内功、
  武学修为逐步成长，留言板、门派系统、任务链都比较齐全。
- 连线时有一道隐藏的客户端版本暗号校验（固定输入 `2060`），是当年
  Tomud/笑傲江湖 WWW 客户端的握手代码，与本项目另收录的多部同期作品
  共享这一机制。
- 本地/回环连接（含 WASM 浏览器连线）已无条件放行，不再受封禁名单和
  IP 数量限制影响。

## 在线试玩

https://mudlibs.fluffos.info/xiyangzaixian3/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **显示名 / display name**: 浮浮（Fluffos）
- **权限 / level**: `(admin)` —— 通过 `/adm/etc/wizlist` 名单授予
  （`fluffos (admin)`）。登录时记得先输入客户端暗号 `2060`。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此默认密码。

## 本地运行

```
cd libs/xiyangzaixian3
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40042**。
