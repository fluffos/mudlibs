# 大唐双龙 (DaTangShuangLong)

与 dtsl（大唐双龙传）、llmud_datangshuanglong 同属"大唐双龙"世界观分支，
但代码实现各自独立（共享部分基础道具内容与中文姓名校验逻辑）。取材自
黄易的武侠小说，以大唐初年天下大乱的江湖为背景。

## 内容亮点

- 新角色从"大唐学院"起步，可通过 `down` 直接开始江湖生涯，也可以先
  `enter` 进入学院详细了解游戏系统——对新手比较友好的双轨设计。
- "石龙武馆"是新手枢纽区，提供银行存取款、拜师学艺、npc 陪练等一整套
  新手服务；`learn`/`xue` 向师父学艺，`bai` 正式拜师入门派。
- 中文姓名会避开寇仲、徐子陵等小说主角姓名，系统直接拒绝重名。
- 天赋分配采用四项属性总和固定制（须凑够 80 点，每项 10-30），整体
  设计偏向系统化、数值化的养成玩法。
- 新建账号需连续在线超过一小时才会自动存档，退出前会主动询问"是否
  保留这个账号"。

## 在线试玩

https://mudlibs.fluffos.info/datangshuanglong/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`adm/etc/wizlist` 最高等级）
- 授权方式：`adm/etc/wizlist` 加入 `fluffos (admin)` 一行（保留原有
  `hpdxxd` 条目）。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/datangshuanglong
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40043**。
