# 狂想空间

1995 年 9 月 22 日创建的老牌台湾 MUD（创始团队 wade、shorst、jcder
等），属于 ES II 引擎系列（与本项目中的 es1_win、esI、xkx2001、
rzrmud、侠客行系列等同宗）。本项目中还有另一个档案"新狂想空间II"
（增加了邮箱注册等更新内容），两者虽然都自称"狂想空间"，但经比对是
两个不同时期、独立流传的版本。本档案是相对更早的一个存档快照。

## 内容亮点

- 早期台湾武侠/奇幻风格 MUD，世界观相对自由，更偏向"帮派"社群玩法——
  新手会先进入"世界的入口"，再决定是否加入某个帮派闯荡江湖。
- 整体节奏偏休闲，历史悠久，保留了不少早期台湾 MUD 特有的界面风格和
  玩法设计（如 tintin 客户端脚本支持提示等）。
- 与"新狂想空间II"不同，本版没有邮箱注册这一步，注册流程更简洁。
- 天赋点数分配式创角系统：8 项属性、共 160 点预算逐项手动分配，
  而非常见的"随机重掷"流程。

- **更正（2026-08-05）**：上面提到的"7.68 复活软锁"修复已经撤销——经重新评估，鬼魂"不在场"时放弃复活流程更可能是有意的游戏设计（多数这类档案里鬼魂本身就无法自行移动，离开是一种游荡机制，回来时 init() 会重新触发流程），不是需要强制重试的 bug；详见 NOTES.md。

## 深度功能测试新发现的 bug（§10.7，2026-08-04）

- **§7.68 复活软锁死（第 10 例）**：`open/death/npc/{wgargoyle,
  bgargoyle}.lpc`（鬼门关的白无常/黑无常）的复活流程在角色暂时不在
  场时会直接 `return`，永久放弃复活。已按标准修法拆分为"重试"与
  "放弃"两种情况。
- **§7.75（新增条目）：`end_death()` 指错文件，死亡惩罚从未真正执
  行过**：上述两个文件复活完成后调用的 `DEATHROOM->end_death(ob)`
  实际指向 `open/death/gate.lpc`，但真正的死亡惩罚逻辑定义在
  `open/death/start.lpc`（该文件自己的头注释还留着
  `// Room: /open/death/gate.c`，加上确认它仍被 `bridge1.lpc` 引
  用，判断这是一次文件拆分/重构时遗漏搬迁的历史遗留 bug）。已修正为
  直接调用 `start.lpc`。
- **§4.1（第 4 个确认实例）**：全树 UTF-8 解码扫描发现 5 个
  extensionless 的 GBK 文本残留（`doc/help/main_map2`、
  `doc/help/quest`、`doc/skill/taoist.chun`、`open/island/room/
  board`、`open/main/README`），已转换为 UTF-8。
- 顺手修复 `open/death/gate.lpc` 场景描述中一处确认为原始压缩包本
  身损坏的乱码字（"钗h" → "许多"，凭本项目内另外 7 个不同血统档案
  中逐字相同句子的印证）。
- 现场验证：注册 → 商店 → 战斗死亡 → 鬼门关 → 未被打断的完整复活
  → 重连确认落地"中央驿站"且状态正常，全程 `debug.log` 干净。

## 在线试玩

https://mudlibs.fluffos.info/kxkj1/

## 管理员账号 / Admin account

- **id**: `fluffos`
- **密码 / password**: `Mud@2026`
- **中文名 / display name**: 浮浮
- **权限 / level**: `(admin)` — 最高权限。
- 授权方式：`work/adm/etc/wizlist` 加入 `fluffos (admin)`。

> 警告：正式对外开放前请务必修改此密码。

## 本地运行

```
cd libs/kxkj1
~/src/fluffos/build-debug/src/driver config.fluffos
```

游戏端口：**40063**。
