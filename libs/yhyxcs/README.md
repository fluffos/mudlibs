# 银河英雄传说

源自 2026-07-29 批量归档 `mudlib.rar` 中的 `银河英雄传说.zip`。ES II 引擎
家族的一支（`master.c` 署名"原作 Lil，Annihilator 改写"），以田中芳树
的科幻小说/动画《银河英雄传说》为背景重新设计。

## 内容亮点

- 舞台设定在银河帝国与自由行星同盟对峙的宇宙历时代，出生地是费沙
  （Fezzan）中央宇宙港——原作粉丝会认出这个中立贸易星球的设定。
- 角色属性沿用原作的军事化风格：力量、胆识、才智、统率、沉着、魅力、
  体格、运气，还记录"曾率领舰队取得胜绩/败绩"次数与"银河使命榜"
  完成度，战斗/指挥两条经验线分开计算。
- 起名规则特别提醒"请勿使用《银河英雄传说》中的人名"——原作人物名
  (杨威利、莱因哈特等) 被显式排除在外，鼓励玩家给自己的角色单独取名。
- 城市间设有出租车（ID卡付款）系统，是这批归档里少见的"打车"玩法。

## 在线试玩

https://mudlibs.fluffos.info/yinhexiongxiongchuanshuo/

## 管理员账号 / Admin account

- **ID**: `fluffos`
- **密码 / Password**: `Mud@2026`
- **中文名 / Display name**: 浮浮
- **权限 / Level**: `(admin)`（最高级别），通过 `/adm/etc/wizlist` 授予。

> 警告：对外公开架设前请务必修改此密码。

## 本地运行

```
cd libs/yhyxcs
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40104**。
