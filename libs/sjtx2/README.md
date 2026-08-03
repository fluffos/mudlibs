# 书剑天下（小熊泥苑分站）

同样自称**「书剑天下」**，这是"小熊泥苑"（http://dtxy.126.com）站点
部署的一个分支——与本项目中的 `shujian2008` 源码几乎完全一致（同一
款游戏，不同站点的两次独立部署）。

## 内容亮点

- 玩法与设定同 `shujian2008`：从"武馆前院"起步，体验属性天赋抽取、
  门派拜师、武学修炼等经典武侠养成玩法。
- 带有短消息、贵宾（VIP）等社区向功能。
- 中文姓名注册同样禁止使用金庸小说中的人物姓名。

## 在线试玩

https://mudlibs.fluffos.info/sjtx2/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码**: `Mud@2026`
- **中文名**: 浮浮
- **权限**: `(admin)`（本 mudlib 巫师等级表的最高级别，注册后直接落在
  巫师休息室）
- 权限授予方式：`/adm/etc/wizlist` 数据文件，内容为 `fluffos (admin)`。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/sjtx2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40030**。
