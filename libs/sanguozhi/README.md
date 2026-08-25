# 三国志

以三国历史为背景的 MUD，脱胎于经典 Lima mudlib（TMI-2 / Ellery 安全
体系一脉），原始存档来自 https://github.com/fluffos/sanguozhi （已经
为 FluffOS v2017 驱动做过一轮适配）。

## 内容亮点

- 注册时先在武侠/演义气质的四种天赋模板中挑选一种（英勇善战型、
  足智多谋型、识人善用型、智勇全才型），系统随机分配武力/智谋/魅力
  三维属性，满意后即可正式进入游戏。
- 真实的三国地图：长安、邺城、汉中等多座城市与关隘、战场，NPC
  包括华佗、各地商人以及汉献帝本人。
- 个人武装系统：招募亲兵、骑乘赤兔马/的卢马/大宛马等历史名马、
  发展地方或国家官职，是这个游戏的核心玩法之一（见游戏内
  `help myarmy`）。
- 继承自 Lima mudlib 的 unix 风格巫师 shell（`quit`/`help`/`who`/
  `update` 等命令与 `look`/`score` 等自然语言动词是两套独立的
  派发机制，见下方"已知特性"）。
- 中文取名不能使用真实的三国人物姓名（如"刘备""赵云"会被拒绝），
  其余合法中文姓名直接通过，无需额外确认步骤。

## 已知特性（非 bug）

- **每个新注册账号都会自动获得巫师（Admin）权限**，这是这个存档自带
  的引导机制（"你自动成为 Admin，记得用 admtool."），并非仅限第一个
  账号。新巫师会先出现在 Lima 框架自带的"巫师大厅"，而不是三国志
  自己的新手村——大厅北墙的轮回台可以前往人间地图。天赋选择菜单在
  巫师引导流程之后仍会正常出现。

## 在线试玩

https://mudlibs.fluffos.info/sanguozhi/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **显示名 / Display name**: 浮浮
- **权限 / Level**: 通过这个存档自己的自动巫师引导机制授予（首次
  注册即自动提升），同时 `data/secure/access.o` 也直接记录了
  `fluffos` 的最高写权限。`update <path>` 已验证可用。

> 警告：这是一个公开的默认密码，仅供本地/浏览器试玩。正式对外开服前
> 请务必修改此密码。

## 本地运行

```
cd libs/sanguozhi
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40210**。
