# 东方故事（蓝天） — es1_win

"东方故事"（ES）系列 MUD 的一个早期基础版本，属于 **ES / TMI 引擎家族**
——尽管名字听起来像武侠题材，实际内容是一个西式奇幻/DND 风格的冒险
世界。与本批次的 `esI`（屠龙之战）同源，共享同一套核心引擎代码。新
角色降生在远风镇的冒险者公会大厅（`/d/adventurer/hall/adv_guild`），
通过 `cost`/`advance`/`train`/`list`/`join` 等公会内部指令自行训
练升级——没有 NPC 教师，以骑士、法师、牧师、武僧、学者、盗贼等公会
体系取代门派玩法；farwind 商行的 `list`/`buy` 交易是出镇后的第一
站。角色创建菜单本身即提供十余种可选种族：人类、精灵、矮人、半兽
人、地精、半身人、蜥蜴人等。

## 内容亮点

- 十余种可选种族：人类、精灵、矮人、半兽人、地精、半身人、蜥蜴人、
  妖精、魔族、半人马、黑暗精灵、眼魔、吸血鬼、鸟人、变形虫。
- 通过加入不同的职业公会（骑士团、法师塔、牧师团、武僧院、学者会、
  盗贼公会等）来学习技能、提升等级——公会制而非门派制，是它与本项目
  其他"风云"系列武侠 MUD 最大的不同之处。
- 冒险者公会大厅（`/d/adventurer/hall/adv_guild`）是新手枢纽，商店
  系统（如 farwind 商行）支持真实的 `list`/`buy` 交易。
- 整体风格更接近传统欧美奇幻 MUD，而非江湖武侠。

## 在线试玩

https://mudlibs.fluffos.info/es1_win/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: 完整管理员（FULL ADMIN）。通过 `/adm/etc/groups` 将
  `fluffos` 加入 `(root)` 与 `(admin)` 组（`/adm/etc/access` 授予
  `(admin)` 对 `/` 的全局读写），并在连线档设置 `wizard 1` 与
  `domains`（primary=wiz，level=archwizard）。

> 警告：公开架站前请务必修改此默认密码。

## 本地运行

```
cd libs/es1_win
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40009**。
