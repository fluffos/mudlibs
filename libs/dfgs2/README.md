# 东方故事Ⅱ之天朝帝国 (Eastern Story II: The Celestial Empire)

属于"东方故事"/ES 系列引擎（与 es1_win、esI 同属一支，但内容与代码规模
都独立、较小巧，源代码题头署名开发者为 Annihilator 与 Phoebus.suny，
"建立架构"始于 1995 年 11 月、"测试游戏制度"于 1996 年 4 月），是这一
支系里较早期的经典 MUD。可选人族、jiaojao、woochan、yenhold 四个种族，
风格更偏西方奇幻而非江湖门派体系。注册流程较长（账号、密码、邮箱、
种族、性别，最后才是中文名字），新角色最终落脚"小客栈"，掌柜与店小
二会热情招呼："掌柜说道：欢迎！欢迎！请里面坐！"

## 内容亮点

- 提供四个可选种族：人族 human、jiaojao、woochan、yenhold，每个种族
  消耗不同点数的"业力"，风格更偏传统欧美奇幻而非江湖武侠门派体系。
- 新角色从"小客栈"起步，由掌柜和店小二两位 NPC 主动迎接，节奏简洁，
  是这批 ES 引擎家族里较为"老派"的一支。

## 在线试玩

https://mudlibs.fluffos.info/dfgs2/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`adm/etc/wizlist` 最高等级）
- 授权方式：`adm/etc/wizlist` 加入 `fluffos (admin)` 一行（保留原有
  `test` 条目）。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/dfgs2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40027**。
