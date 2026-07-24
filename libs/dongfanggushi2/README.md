# 东方故事Ⅱ之天朝帝国 (Eastern Story II: The Celestial Empire)

属于"东方故事"/ES 系列引擎(与 es1_win、esI 同属一支,但内容与代码规
模都独立、较小巧)。

## 简介

「东方故事Ⅱ之天朝帝国」是一款早期(1995-1996 年建立)的经典 MUD,支持
多个种族(人族 human、jiaojao、woochan、yenhold)供玩家选择,新角色从
"小客栈"起步,由掌柜和店小二两位 NPC 迎接。整体节奏简洁,更偏"传统老
派" MUD 的风格,而非后期武侠向的门派体系。

## 如何运行

```
cd libs/dongfanggushi2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口:**40027**。

## 如何连接游玩

```
python3 scripts/mudclient.py 127.0.0.1 40027
```

注册流程比多数同类 MUD 略长一些,依次为:
1. 英文 ID(3-12 个**纯英文字母**,不可包含数字或符号)
2. 确认创建新角色(y/n)
3. 密码(至少 5 字元)
4. 确认密码
5. 电子邮件地址
6. **选择种族**(human / jiaojao / woochan / yenhold,每个种族消耗不同
   点数的"业力")
7. 选择性别(m/f)
8. 中文姓名

完成后进入"小客栈",`look`/`score` 等指令均正常工作,店内的掌柜 NPC 会
主动向你打招呼。

## 已知问题

目前主线流程与起始场景均已确认正常,未发现影响新手体验的内容缺失。
本游戏已确认可在 WASM/浏览器模式下完整游玩(注册、登陆、基础指令均
正常),不受底层驱动 IP 检测限制影响。

## 管理员账号 / Admin account

- **ID**：`fluffos`
- **密码 / Password**：`Mud@2026`
- **中文名 / Display name**：浮浮
- **权限 / Level**：`(admin)`（`adm/etc/wizlist` 最高等级）——已验证
  `update` 巫师指令可用（登录后显示"目前权限：(admin)"）。
- 授权方式：`adm/etc/wizlist` 加入 `fluffos (admin)` 一行（保留原有
  `test` 条目），重启后 `securityd.lpc` 的 `create()` 读入生效。
- 存档文件：`work/data/user/f/fluffos.o`、`work/data/login/f/fluffos.o`
  （未被 gitignore，普通 `git add libs/dongfanggushi2/` 即可纳入）。

> 警告：`Mud@2026` 是本地游玩用的公开默认密码。若要正式对外开放主机，
> 请先修改此密码。
