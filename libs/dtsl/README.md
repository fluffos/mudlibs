# 大唐双龙传 (Twin Dragons of the Tang Dynasty)

属于"大唐双龙"世界观的一支，与 datangshuanglong、
llmud_datangshuanglong 共享部分基础引擎代码，但各自剧情内容独立开发。
取材自黄易同名武侠小说，以大唐初年江湖为背景。

## 内容亮点

- 新角色从"大唐学院"起步，通过学院课程了解基本操作后即可下山
  （`down`）开始真正的江湖历练，也可以先 `enter` 进入"新人篇"深入
  学习——整体节奏对新手比较友好。
- 密码规则与"书剑"系列不同：只限制长度（5-8 位），不强制要求大小写
  或数字混合。
- 天赋分配同样是四项属性总和固定制（须凑够 80 点，每项 10-30）。

## 在线试玩

https://mudlibs.fluffos.info/dtsl/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`adm/etc/wizlist` 最高等级）
- 授权方式：`adm/etc/wizlist` 加入 `fluffos (admin)` 一行（保留原有
  `fengfei`/`kouzhong`/`ttj`/`zhujiepo` 条目）。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/dtsl
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40008**。
