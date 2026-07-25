# 书剑天下 2008

2008 年版本，由 ShuJian MUD 开发组制作，站点归属重庆电信。与同名的
`shujiantianxia`（小熊泥苑分站）源码几乎完全一致，属于同一游戏在
不同站点的两个部署。

## 内容亮点

- 传统中文武侠 MUD，玩家从"武馆前院"这样的门派场景开始自己的江湖
  之路，体验属性天赋抽取、门派拜师、武学修炼等经典武侠养成玩法。
- 建有短消息、贵宾（VIP）等社区向功能，整体氛围偏经营多年的老牌
  武侠站点风格。
- 中文姓名注册明确禁止使用金庸小说中的人物姓名（例如"萧峰"会被
  直接拒绝）。

## 在线试玩

https://mudlibs.fluffos.info/shujian2008/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码**: `Mud@2026`
- **中文名**: 浮浮
- **权限**: `(admin)`（本 mudlib 巫师等级表的最高级别，拥有
  `/cmds/adm` 在内的全部巫师命令目录）
- 权限授予方式：`/adm/etc/wizlist` 数据文件（格式 `id (级别)`），
  内容为 `fluffos (admin)`。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/shujian2008
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40029**。
