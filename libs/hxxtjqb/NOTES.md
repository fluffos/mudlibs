
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记题材的 ES 血统 mudlib（MudOS v22pre11 MudLib Build 3310），游戏内标题为"西行战记"，连线时有一个实时的 GB/BIG5 双编码选单。修复的 bug：（1）经典的 §6.6 convertd.lpc 希腊字母表漏斜杠错字，45 处，导致每次连线的横幅 cat() 都会崩溃；（2）logind.lpc 里经典的 §8.1 check_legal_name() 字节数没减半的长度界限+i%2==0 门槛+尾部切片 bug（is_chinese() 本身已经是正确的码点判断）；（3）实时存在的 GB/BIG5 编码选单 bug（§8.7）——选 BIG5 会在之后每一行都刷出"Invalid GB code"，已把两个选单选项都对应到 GB 直通编码修复。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字（秦风）。格式化工具发现 2 个档案（d/moon/obj/poem.lpc、u/bmw/task/taskd.lpc）带有转档之前就存在的损坏字符串字面量（一段没有结束的诗词字符串，和一段写死在源码里的分页器输出痕迹）——已还原格式化工具对这两处的重新加空格处理，而不是在已有损坏之上继续叠加，其余问题按 WASM 验证范围之外处理，未修。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 32 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——干净通过，零 bug，但揭穿了一个 tmux/telnet 测试工具的严重可靠性问题

第一次对这份档案做完整的 §10.7 深度游玩测试（注册→探索→战斗→死亡/
复活→留言板发帖），全程零真实 bug：

- **注册/look/score/hp/inventory/探索**：全部干净通过。
- **战斗**：巫师账号（`fluffos`/`Mud@2026`，真实注册，wizlist 播种的
  管理员身份现场确认生效）用 `goto` 直达 `/d/xueshan/xihai`（一个有
  `attitude: aggressive` 怪物"朱睛冰蟾"的房间），进房间后怪物主动攻
  击，几回合内被杀死——纯属测试过程中的意外，不是刻意安排的，但正好
  覆盖了死亡/复活这一步。
- **死亡处理**：死亡讯息、"某人被杀死了"的谣言广播、移动到
  `/d/death/gate`（阴阳界），全部正确无误。
- **复活**：`/d/death/npc/pang.lpc`（崔判官）的复活流程是**全自动**
  的——`init()` 里对刚进房的鬼魂启动一条 `call_out("death_stage", 5,
  ...)` 链，5 个阶段各间隔 5 秒播放一句判官台词，最后一步调用
  `ob->reincarnate()` 并移动到 `REVIVE_ROOM`，全程不需要玩家任何输
  入。现场验证：断线约 30 秒后重新连线，角色已经在复活点
  `/d/ourhome/kedian`，血量正确地是满血的四分之一（符合
  `pang.lpc` 里 `kee = max_kee/4` 的设定），无任何报错。
- **留言板发帖**：`post <标题>`（标题必须跟在同一行，不是交互式追
  问）触发内建编辑器（`结束离开用 '.'，取消输入用 '~q'`），逐行输入
  正文，单独一行 `.` 结束保存——`read <编号>` 验证发的贴子标题、正
  文、作者字段全部正确落盘。

### 重要的工具方法教训：tmux + telnet 对这份档案（也可能更广泛）不
可靠到会制造假 bug

`score`/`hp`/`inventory`，以及任何不存在的指令，透过
`scripts/tmux_mud.sh`（`telnet -E` 起的会话）测试时**全部只显示空白**
——没有任何报错、没有"什么？"，看起来像是一个极其严重的"指令派发
静默失效"的 bug。深挖了 `query_entire_dbase()`、`error_handler()`、
`default error message` 配置、`report_error()` 频道广播等好几层，
一度高度怀疑是驱动侧的静默吞错误配置缺陷。**最终用一个独立的原始
Python socket 连线重现同一操作序列，`score`/`hp`/`inventory` 全部
返回完整、正常的内容**——证明这完全是本地 telnet 客户端的问题，不
是这份档案的 bug，和 nt6 round four 发现的 `^]` escape 模式问题是
同一类，但这次是**静默丢弃后续输出、不显示任何提示**，比那次更隐
蔽，`telnet -E` 也没能解决它。

本轮之后改用单次 Python `socket.create_connection()` 脚本驱动整段
测试（一个脚本内完成"连线→登录→若干条指令→断线"这一整个逻辑阶
段，而不是每条指令都开一条新连线）——既保留了跨指令的会话延续性
（不违反"别用一次性 Python 脚本"的既有教训的精神），又完全避开了
telnet 客户端这层不可靠的中间人。**建议以后凡是在这个项目里做
`§10.7` 深度游玩测试，默认就用这个原始 socket 脚本方式，而不是
`scripts/tmux_mud.sh`**——tmux+telnet 现在已经在两个互不相关的档案
上各自制造过一次足以误导排查方向的假象。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 295 live occurrences deleted: 291 via scripted sweep (`fix_710_room.py`), plus 4 hand-fixed roommaker-tool occurrences across 2 tool copies (`clone/misc/roommaker.lpc` — simple variant; `obj/roommaker.lpc` — "room_code"/`str` 3-occurrence variant). 3 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40177 listening, zero new "cannot replace"/"cannot bind" debug.log lines. Pre-existing untracked test-account debris (`data/{login,user}/{f/fluffos,q/qintest}.o`) confirmed left untouched by `git status` review before staging.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.
