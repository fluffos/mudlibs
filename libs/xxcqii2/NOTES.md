
## WASM 修复摘要（迁移自 meta.json 的 group_note）

内容和 xxcqii 的小雪初晴II.rar 完全相同的 .zip 重新打包版——全部 3033 个共有 .lpc 档案逐字节相同（已通过对照 xxcqii 修复前那次提交的全量内容哈希比对确认）；唯一差异是多出一个档案 topten/topbook.lpc（一份运行时排行榜存档，不是源代码内容）。真正的 WASM 修复过程（httpd/dns_master 的 §7.52 socket 精灵修复、管理员播种、格式化）见 xxcqii，这里不再重复。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

同一形状扩展到全库通用房间基类：删除 846 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），另修正
`clone/misc/roommaker.lpc` 字符串拼接模板里同一枚烤死的
`replace_program(ROOM);`——和手足档案 `xxcqii` 是完全相同的 bug 形
状与命中数（847 处），但注意这次逐档对照发现两份档案在当前状态下
并**不是**逐字节相同（`roommaker.lpc` 等大量档案存在缩进风格差异，
制表符 vs 空格、大括号换行位置等），和本档案 NOTES.md 早先记录的
"与 xxcqii 完全相同"结论不一致（那条结论应是修复前某次格式化差异
导致，或指的是逻辑内容而非字节级别）——因此本次按独立档案完整走
了一遍验证流程，而不是假定与 xxcqii 的结果可以直接照搬。已用
`build-debug` 驱动干净启动验证（0 个新增编译错误，端口正常监听）；
未做完整 §10.7 深度游玩测试。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 针对性排查：xxcqii 的 §10.7 round-two 7 类 bug 逐项核对（2026-08-27）

来源：`libs/xxcqii/NOTES.md`"深度功能测试（2026-08-27，round two,
AGENTS.md §10.7）"一节记录的 7 类 bug（同属小雪初晴系列，共享同一份
引擎代码）。逐一在本档案（`xxcqii2`）里定位对应档案并核对，7 类全部
存在，已全部按 `xxcqii` 的原始修复方式逐字修正：

1. **注册流程 debug 遗留 `printf("%O\n", ob)`**：`adm/daemons/
   logind.lpc`/`logind1.lpc`/`logind2.lpc` 的 `get_name()` 三份都有，
   已全部删除该行。用真实 socket 脚本连续注册一个新角色验证：设定
   中文名字之后到"请设定您的临时密码"提示之间，不再出现任何裸露的
   `/clone/user/loginXXX` 内部对象路径。

2. **`valid_learn()` 0/1 参数签名不一致**：`inherit/skill/skill.lpc`
   基类是 0 参数，`kungfu/skill/force.lpc` 也是 0 参数（本档案的
   93+ 个其它技能档案都是 1 参数），和 `xxcqii` 完全同型。两处都改成
   `int valid_learn(object me) { return 1; }`。用 `lpcc --batch` 单独
   编译 `/kungfu/skill/force` 验证：干净通过，无"Number of
   arguments...disagrees with previous definition"警告（driver 完整
   启动日志里也未见此警告）。

3. **AGENTS.md §7.11 实例**：`adm/simul_efun/file.lpc` 的
   `log_file()` 没有调用同档案里已有的 `assure_file()`，已加上
   `assure_file(LOG_DIR + file);`（连同前向声明）。本次未走管理员
   `call` 审计日志路径现场触发（测试预算用在了其余 6 类上），改用
   `lpcc --batch` 编译干净 + 静态核对修复后的函数体确认。已在
   AGENTS.md §7.11 补充条目。

4. **AGENTS.md §7.112 实例**：`d/shaolin/kfroom_1.lpc`~`kfroom_6.lpc`
   六个档案的形状和 `xxcqii` 完全一致——`kfroom_5`/`kfroom_6` 的
   `init()` 完全没有防重入保护，`kfroom_1`~`4` 只有一次性入场旗标、
   没有"本轮机关阵正在进行中"的防护。六个档案均按 `xxcqii` 的原始
   补丁逐字修正。由于少林寺前山门广场的守门僧（`d/shaolin/
   guangchang1.lpc`的`valid_leave()`）会拦下所有非"少林派"归属的
   角色（"这位施主请回罢，本寺不接待俗人"），无法靠纯步行到达
   `kfroom_5`，改用临时管理员账号（往 `adm/etc/wizlist` 追加一行、
   重启 driver 生效、验证完毕后已恢复原始档案内容，未保留）执行
   `call me->move("/d/shaolin/kfroom_5")` 直接传送进入——传送本身
   只是绕过 RP 前置任务，机关阵触发/断线/重连的验证路径和真实玩家
   完全一致。真实断线-重连复现实验（`socket.close()`模拟真实掉线，
   非清洁 `quit`）确认："一走进始武房...机关开动了"这句开场白在整个
   会话里只出现了 1 次（`grep -c` 核实），重连后机关阵继续原有进度
   （斗志数值连续下降），没有叠加第二条奖励链。

5. **AGENTS.md §7.151 实例**：`feature/dealer.lpc` 的 `do_list()`
   同样是 `j=tmp[goods];`（应为 `j=tmp[goods[i]];`），已修正。现场用
   `d/bianliang/npc/wei.lpc`（韦鸭毛，杂货铺，`carry_object()`带一件
   布衣，从新手初始房间往东、北、东三步可达）验证：`list` 命令修复后
   正确显示"1件布衣"（该 NPC 实际只带一件）。

6. **AGENTS.md §7.86 实例**：`d/kunming/dangpu.lpc`/`d/kunming/obj/
   dpm.lpc` 都有 `inherit SR_DANGPU;` 之后多余的
   `replace_program(SR_DANGPU);`，已删除两处。`dangpu.lpc` 经
   `lpcc --batch` 编译干净；`dpm.lpc` 全档案搜索确认同样是从未被
   引用的死代码，且带有与本次修复无关的既存编译错误
   （`set_name()` 未定义，`SR_DANGPU` 祖先链没有提供），按"存疑不动"
   处理，不修复，仅记录。

7. **AGENTS.md §7.152 实例**：`clone/user/user.lpc` 的 `reconnect()`
   同样缺少 `set_living_name()`，已在函数开头补上与 `xxcqii` 相同的
   两行。用真实双 socket 复现实验验证：角色 A 断线（`socket.close()`
   不发 quit）后在约 2 秒内重连，角色 B 立刻 `tell <A的id> ...`
   （注意用 id 而非中文名——`find_player()`按注册的 living name 也就
   是 id 匹配），A 端正常收到消息，未出现"没有这个人"报错。

**结算与清理**：测试角色（tstsnowc/d/f/g/h 等，含临时管理员
tstsnowf）的存档、`adm/etc/wizlist` 的临时追加行均已在提交前删除/
还原；`adm/etc/users`（访客计数器）因真实注册流程自然增长，比照
`xxcqii` 原提交的先例保留未回滚。`lpcc --batch` 全库编译检查：
3034 个档案里 2932 通过、102 失败——除已知的 `d/kunming/obj/dpm`
（见上方第 6 类，预先已知且与本次修复无关）外，其余失败与本次
7 处改动的档案均无交集，属于本库既有的历史遗留问题。`grep -h
'"port"'` 端口唯一性检查已过。

## Shop + 拜师 (2026-09-04)

Live native play on port **40138**. First send **`g`**. Seeded `fluffos
(admin)` in `adm/etc/wizlist` (sibling `xxcqii` already has this line;
the 2026-08-27 pass had appended it only temporarily). Registered
`fluffos`/`Mud@2026`, display 浮浮, 【天神】(admin), wizard guild.

**Shop.** `goto /d/bianliang/sanhelou`, 店小二 `list` already showed
`1件布衣` (2026-08-27 §7.151 `tmp[goods[i]]` fix still in place) plus
烤鸡腿 八十文. Cloned 一两白银, `buy jitui` → 买下烤鸡腿, leftover
二十文铜板. Relog kept the 二十文; food is not autoload.

**拜师.** `goto /d/huanhua/huzu` — unlike sibling `xxcq`, this tree
ships `npc/zuyuan_h.lpc`, so both 李子木 and 虎组组员 spawned.
`bai li` → 好吧…收你为弟子, 浣花剑派第六代弟子、虎组组员. Relog
`score` still 师父是李子木.

**Bug ported.** `inherit/room/room.lpc` `make_inventory()` had no
`objectp` guard after `new()` (same abort-rest-of-reset shape as
`xxcq` 2026-09-04). `zuyuan_h` exists here so 拜师 was not blocked,
but `reset()` still did unguarded `ob[list[i]]->is_character()` after
a failed `new()`. Added `if (!objectp(ob)) return 0;` plus the two
`objectp` checks in `reset()`. CRLF preserved. Dealer list-index was
already fixed (2026-08-27).

How to run: `cd libs/xxcqii2 && ~/src/fluffos/build-debug/src/driver
config.fluffos` then `g` / `fluffos` / `Mud@2026`.
