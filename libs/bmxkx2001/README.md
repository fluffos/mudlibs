# 侠客行 (The Quest of Oriental Chivalry) — 北美 2001 版

属于 ES II/"侠客行"引擎家族（与 xkx2001、xuanjianlu 等同宗，`chinese.c`/
`master.c` 字节级相同），1996-1999 年 XiaKeXing Gaming Group 制作、于
北美地区运营的一个版本。`d/taihu/gumu/houtang.lpc` 等场景文件头带着
"Cracked by Roath"署名，和另一轮处理过的 `jym`（金庸梦）、`xkm`（侠客
梦）是同一批"Cracked by Roath"流通版本（`xkx2000zxb` 则是"Cracked by
Kafei"的另一份流通版本），此前没有互相记录过这层关系。

## 内容亮点

- 取材自金庸同名武侠小说，以"侠客岛"为核心背景——新玩家一入游戏就会由
  岛上的"赏善使"或"罚恶使"两位使者之一迎接，带你前往挂名处登记，随后
  才能真正踏入江湖。
- 新角色第一次进入游戏会先经历侠客岛的迎宾/登记流程，此时只能使用
  `look`、`follow`、`say`、`quit` 等少数指令——这是游戏本身刻意设计的
  新手引导限制，需先跟随迎宾使者完成登记，之后再次登录才会进入真正可
  自由行动的江湖世界。
- 门派、武功体系完整，紧扣金庸原著世界观，是早期中文 MUD 里颇具代表性
  的武侠作品。
- 中文姓名会避开小说中已有的人物姓名（如"韦小宝"等会被系统直接拒绝）。

## 在线试玩

https://mudlibs.fluffos.info/bmxkx2001/

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（本系最高等级）
- 授权方式：`data/securityd.o`（SECURITY_D 的存档）中 `wiz_status`
  加入 `"fluffos":"(admin)"`、`wiz_sites` 加入 `"fluffos":".*"`。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。

## 本地运行

```
cd libs/bmxkx2001
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40039**。
