# 书剑天下 (ShuJian MUD)

重庆电信 ShuJian MUD Wizard Group 自 1997 年起开发维护的经典武侠 MUD，
与 bxsj1《书剑·经典》同源，共享大部分核心引擎代码。

## 内容亮点

- 新人从"武馆前院"起步，沿东练武场、东武场（设有木人陪练）、兵器库一路
  探索，是一套完整成型的新手引导区。
- 木人（`d/wuguan/wuchang4`）会原样复制攻击者自身属性/技能来对练，`fight`
  时到五成资源自动收手认输，是真正意义上的安全陪练。
- 拜师系统有两条路：正统的门派掌门（如武当宋远桥）循序渐进拜师，或找
  游戏内建的"礼物使者"NPC 直接问"拜师"/"门派名"，瞬间加入 15 个门派中
  的任意一个并获得满级绝技全套装备——后者是官方明示的"新手鼓励"捷径，
  非破解漏洞。
- 有一处值得留意的原始设计：非巫师角色 `quit` 退出时，未标记
  autoload/unique 的随身物品（包括初始布衣布履）会被直接清空——这是
  ES2 谱系一以贯之的"防屯物"机制，重新连线（非完整退出）不受影响。
- 江湖社交三件套 `ask <npc> about name/rumors/here` 对几乎所有 NPC 都
  有效，`rumor` 频道会匿名化发言者，`chat` 频道则显示真实姓名。

## 在线试玩

https://mudlibs.fluffos.info/bxsj/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`（8 位，含大写字母与数字，符合本站密码规则）
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`adm/etc/wizlist` 中授予的最高等级）
- 授权方式：在 `adm/etc/wizlist` 加入 `fluffos (admin)` 一行。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/bxsj
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40004**。
