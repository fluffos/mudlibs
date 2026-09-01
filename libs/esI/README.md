# 东方故事 — esI（"屠龙之战"）

东方故事，站内活动主题为"屠龙之战"（Dragon Slaying War）。与本批次的 `es1_win`（东方故事·蓝天版）同属 ES / TMI 引擎家族，两者核心代码几乎一致，仅站点内容与分支细节不同。本档案独有一段完整的终局剧情：`eastland/dragon` 是一座三十余间房的洞穴迷宫，深处镇守着 19 级、2500 点血量的最终 boss"孽龙恨天"——传说中因过去屠戮生灵而被玉帝封印于此的恶龙，身披并会掉落一枚龙形护身符。

## 内容亮点

- 与 es1_win 相同的多种族、多职业公会西式奇幻世界（人类、精灵、矮人、
  半兽人、地精等种族；骑士、法师、牧师、武僧、学者、盗贼等公会）。
- farwind 商行支持真实的 `list`/`buy` 购物交易（已实机验证完整购买
  流程）。
- 本档案额外开启了"新角色自动获得巫师（管理员）身份"的测试期配置，
  说明这份快照原本是用于内部测试/性能压测的版本——普通玩家体验可自行
  忽略这项特权，不使用管理指令即可。

## 在线试玩

https://mudlibs.fluffos.info/esI/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: 完整管理员（FULL ADMIN）。`/adm/etc/groups` 将
  `fluffos` 加入 `(root)` 与 `(admin)` 组，连线档设置 `wizard 1` 与
  `domains`（primary=wiz，level=archwizard）。

> 警告：公开架站前请务必修改此默认密码。

## 本地运行

```
cd libs/esI
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40010**。
