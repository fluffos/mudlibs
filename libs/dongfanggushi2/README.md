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
