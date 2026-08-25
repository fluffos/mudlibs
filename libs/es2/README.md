# 东方故事Ⅱ — Eastern Story II (ES II)

**中文MUD鼻祖**——根据 GitHub `mudchina` 组织的介绍，这是现存最早的
中文 LPC mudlib 之一。它不是某个既有引擎的中文化移植，而是一份从零
写起的原创代码（署名 Annihilator@Eastern.Stories，1994-1995 年间开发，
建立在经典的 Lil mudlib 与 TMI 功能混入代码之上）——本项目里反复出现
的"ES2/TMI-2/Falcon 家族"这一说法，追根溯源，指的正是这一脉传承。

原始存档：`git clone https://github.com/mudchina/es2`（commit
`ae8adf6`）。仓库本身是纯 GBK 编码的原始快照，本次上线按本项目一贯
的方式完成了 GBK→UTF-8 全量转码与驱动兼容性修复（详见 `NOTES.md`）。

## 内容亮点

- 注册时需要取一个真正的中文名字（如"秦风"），新人物会降生在雪亭镇
  的"饮风客栈"——一处武侠气息浓厚的驿站，NPC 包括店小二、旅客，
  乃至一位来自《七龙珠》的客串角色"孙悟空"。
- 游戏世界由多个"domain"组成：京师城门与街道、雪山门派、丹霞谷竹林、
  绿林庄园、坟场/幽冥地带等，展现了早期中文 MUD 典型的东方奇幻地图
  结构。
- 门派/师徒（`create_family`）与技能练功系统，双轨的"精/气/神"三维
  状态条与独立的战斗攻防评分，`score` 指令展现完整的干支生辰、门派、
  潜能百分比等信息。
- 保留了 1994-1995 年间原始 MudOS 架构的大量历史痕迹（`adm/obj/
  master.lpc`、`feature/*.lpc` 功能混入式设计等），是研究早期中文
  MUD 代码演化的第一手样本。

## 在线试玩

https://mudlibs.fluffos.info/es2/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 秦风
- **权限 / level**: 通过编辑 `adm/etc/wizlist`（`securityd.lpc` 在
  `create()` 时读入此文件填充 `wiz_status`）加入 `fluffos (admin)`
  一行，再以正常注册流程创建该账号。已用 `update /adm/obj/master`
  验证成功（读取+编译 ACL 均通过）。

> 警告：公开架站前请务必修改此默认密码。

## 本地运行

```
cd libs/es2
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40214**。
