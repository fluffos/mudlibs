# 仙剑狂侠2000（仙剑传奇）

作者叶雨飞。属于"Century（世纪）家族"武侠 MUD 引擎（与《书剑2008》
《书剑飘零II》等同源，管理层目录结构相似），但游戏内容和安全模块均
为独立开发，并非简单复制。

## 内容亮点

- 一个以扬州为舞台展开的传统武侠世界：中央广场、扬州城的店铺与巡抚
  衙门、各大门派（丐帮、全真教、白驼山、五毒教、日月神教等）。
- 颇具特色的"打劫""送镖"等江湖营生任务(job)系统。
- 整体氛围偏正统金庸/古龙式武侠，适合喜欢门派养成与任务体系的玩家。
- 新角色注册时有一次"天赋"选择：膂力/悟性/根骨/身法四项属性，可以
  随机分配也可以自行指定其中一项的具体数值。

## 在线试玩

https://mudlibs.fluffos.info/xianjianchuanqi/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **显示名 / Display name**: 浮浮
- **权限 / Level**: `(admin)` —— securityd `wiz_levels` 中的最高级，
  通过 `adm/etc/wizlist` 授予（启动时被 `securityd->create()` 读入）。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/xianjianchuanqi
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40034**。
