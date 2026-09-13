# yhwhckdm（炎黄武魂参考代码）-- porting notes

原档只有 `d/`、`kungfu/`、`clone/` 三棵树，没有 master，原先标 `not-convertible`。发布说明（薪有所属，2017-03-03）写明这是当时炎黄武魂的参考代码，方便规划 id。

按用户指示接到已转换的 `yanhuangwuhun` 骨架上：

1. `rsync` `libs/yanhuangwuhun/work/` → `libs/yhwhckdm/work/`。
2. `convert_lib.sh` 转好的参考树覆盖 `clone/`、`d/`、`kungfu/`（already_utf8=61 converted=10123 lossy=1）。
3. 引擎仍是 yh 2003 的 `/adm/single/master`。

端口 **40321**（原 40270；§10.7 改到空闲段）。注册流程与 `yanhuangwuhun` 相同（`washto` / `born`）。
骨架带过来的管理员 `fluffos`/`Mud@2026` 可直接登录，落地扬州客店
`/d/city/kedian`（参考树覆盖了原炎黄的世外桃源起点）。`look`/`quit` 正常。

## 商店 + 拜师（2026-09-04 librarian shop slice）

新角度：扬州醉仙楼付费购买。进口笔记只写了骨架落地。参考树覆盖
了 `d/`，但醉仙楼 `/d/city/zuixianlou` 和黎生路径与
`yanhuangwuhun` 2026-09-03 相同。管理员存档从骨架带过来时已经是
丐帮第二十代 / 师父黎生，本轮不再重拜。

本轮没有新的 programming bug。`goto` / `clone` / `MESSAGE_D` 的
`to_int` 和 `log_file assure_file` 已在骨架里。`log directory :
/log` 仍是绝对路径，本机 `debug.log` 不打开。

### 实测过程

`fluffos` / `Mud@2026`，第一输入是英文 id。落地扬州客店
`/d/city/kedian`（北丑、戚长发、店小二在场）。`score`：「丐帮第二
十代传人 浮浮」「师父是黎生」。`goto /d/city/zuixianlou`，店小二
`list` 烤鸡腿八十文。`clone /clone/money/gold`「黄金复制成功」。
`buy jitui`：「你从店小二那里买下了一根烤鸡腿。」`i` 一两黄金 +
九十八两白银 + 四十文铜钱 + 烤鸡腿。`quit` 后再登：门派、黎生、
银钱都在；烤鸡腿是食物，不进档（手足 yh 已知）。

管理员存档未提交。

## WASM (2026-09-11 leftover 652)

`wasm_client.js`：`fluffos` / `Mud@2026` → 扬州客店 `/d/city/kedian`
（戚长发、北丑、店小二），`look` 同文，`score`「丐帮第二十代传人
浮浮」，`quit`「欢迎下次再来」。`wasm_status` 改为 `playable`。

## 深度功能测试（§10.7，2026-09-13）

原生 driver 端口 **40321**（原笔记 40270；本轮改到 §10.7 惯用
40320–40380 空闲段），`fluffos` / `Mud@2026`。从 slug 目录启动：
`~/src/fluffos/build-debug/src/driver config.fluffos`，stdout →
`/tmp/yhwh-driver.out`。slug `libs/yhwhckdm/log/debug.log` 与 mudlib
`work/log/log`（`master->log_error()`）都按本轮 mtime 查了；`call`/
`clone` 审计还写了 `work/log/static/{call_player,clone}`。

这是 **yanhuangwuhun 骨架 + 炎黄武魂参考代码叠层**：引擎仍是 yh
2003 master，`d/`/`clone/`/`kungfu/` 被参考树覆盖。`help newbie` 仍
写桃源起步，实际落地是参考树的扬州客店——文档与地图不一致是嫁接
事实，不是本轮新洞。

### 游玩证据

- 登录落地扬州客店 `/d/city/kedian`（戚长发、北丑、店小二）；
  `score`「【 小叫花 】丐帮第二十代传人 浮浮 / 师父是黎生」。
- 商店：`goto /d/city/zuixianlou`，`list` 烤鸡腿八十文；
  `clone /clone/money/gold` 后 `buy jitui` →
  「你从店小二那里买下了一根烤鸡腿。」`i`：1 金 + 98 银 + 40 铜 +
  烤鸡腿。
- 门派点：`goto /d/gaibang/inhole`，黎生在场；本号已是弟子，未重拜。
- 任务：`quest` →「你现在没有领任何任务！」；`job`/`jobs`/`task`
  均「什么？」。环境里任务精灵仍在 ambient 创建
  （SUPPLY/DELIVER/SHEN 等日志），玩家侧无已领任务。
- 战斗：`goto /d/city/guangchang`，`clone /clone/npc/mu-ren`；新手
  `fight mu ren` 被拒「这点身手还不足以和木人练功」（木人门槛，
  设计如此）。巫师 `call` 把 unarmed/dodge/parry 提到 50、
  `combat_exp` 5 万后，`fight mu ren` 互出拳脚，`halt` 干净跳出。
- `quit`「欢迎下次再来」；重连后门派/师父/银钱仍在。烤鸡腿未随档
  （食物常见 `no_save`，与手足 `yanhuangwuhun` 相同）。

### 日志

本轮 boot + 游玩：slug `debug.log` **无** `执行时段错误` /
`Bad argument` / `Too long evaluation`。`work/log/log` 本轮增量主要是
preload/`shopd`/`quit` 的 unused-variable 警告，无同形功能缺口。

### 未改 / 剩余缺口

- 管理员运行时存档未提交。
- 嫁接上限：`help newbie` 桃源文案与参考树扬州起点不一致；玩家
  `quest` 空、无 `job` 指令（任务精灵 ambient 自转不等于可玩任务线）。
- 端口配置已改为 40321（本轮空闲优先），未改回 40270。
