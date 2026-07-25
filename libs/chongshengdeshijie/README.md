# 重生的世界 (Revival World)

RWlib v1.0.1，台湾团队开发的生活模拟/城市经营类 MUD，与本项目其他武侠
类 mudlib 完全不属于同一谱系，是一套独立自制的引擎。

## 内容亮点

- 不是打怪升级的武侠 MUD，而是一款以经营、生活为核心的模拟游戏：种田、
  钓鱼、养殖、开工厂、买卖房地产、炒股、打麻将、抽奖样样俱全。
- 配有完整的城市市长、税收、企业系统——新角色可以选择加入某个城市定居，
  体验经营与养成的乐趣，风格更接近生活模拟游戏而非传统砍杀 MUD。
- 每次连线都会展示一段完整的模块加载动画，是这款游戏自己的特色开场。

## 在线试玩

https://mudlibs.fluffos.info/chongshengdeshijie/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`SECURE_D` 的最高等级）
- 授权方式：`system/kernel/data/secure.o`（SECURE_D 的存档）`wizards`
  映射中加入 `"fluffos":"admin"`。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/chongshengdeshijie
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40081**。
