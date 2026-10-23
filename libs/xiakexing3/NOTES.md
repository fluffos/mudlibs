# xiakexing3 — 侠客行三 / 金庸群侠传

Archive: `侠客行III .rar` (note: trailing space before `.rar`; TODO.md's
table originally listed this as `侠客行III 可用.zip`, which was wrong —
corrected once the real filename was discovered during extraction).
Port: 40038. Status: **done** (boots clean and quick, full registration
flow verified end-to-end including a real Chinese name).

## What this is

Config's `MUD_NAME` is "侠客行三", but the live connection banner
actually reads "金庸群侠传" ("Jin Yong's Gathering of Heroes") — yet
another instance of a lib's internal game name differing from its
config/archive name. `adm/obj/{master,simul_efun}` layout — confirmed
genuinely **unrelated** to `xiakexing100` (archive #43, `adm/single/`
layout) despite the shared "侠客行" title prefix, reinforcing the
established lesson that similar titles aren't a reliable lineage
signal. Small lib, ~3,651 raw files.

## Extraction quirk (new, see AGENTS.md's "Archive tooling" section)

Despite the `.rar` extension, this archive is actually a **plain POSIX
tar** (`unrar` correctly refused it: "not RAR archive"). Its members are
stored with **relative `../xkx3/...` paths**, which GNU `tar -xf`
unconditionally refuses to extract ("Member name contains '..'") even
with `--transform` (the safety check runs before transforms apply).
Worked around by extracting with Python's `tarfile` module directly,
stripping each member's leading `../` before calling `extract()` — see
AGENTS.md for the reusable snippet.

## Fixes applied

1. **AGENTS.md §15h**, standard shape: `is_chinese()`'s GBK lead-byte
   check → CJK codepoint check; `check_legal_name()`'s byte-count bound
   `< 2 || > 12` → character-count bound `< 1 || > 6`, removed the
   `i%2==0` even-byte-offset gate.
2. **Confirmed NOT needed**: no §4 fix (`master.c`'s `valid_write` gates
   via `find_object` only, `valid_read` is a bare `return 1;`); no
   `named.lpc` (doesn't exist in this lib).
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in under 10 seconds, zero compile errors, no
   hang.

## Interactive test result — full registration flow

No hidden pre-id prompts. Verified the complete registration path in
one continuous connection: id `xkxctest` → confirm `y` → **real Chinese
name `秦风`** → accepted, proceeds straight to "请设定您的密码：". This
lib's registration prompt text warns against using Jin Yong novel
character names, but the actual `banned_name` array only contains
pronouns + "时空" (no specific character names), so no specific name
needed to be avoided this time.

## lpcc sweep

2,981 files, 2,887 pass / 94 fail (96.8%). Failure tail is the usual
shape (missing globals, a handful of syntax typos) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~13GB free).

## Retroactive fix (found via archive #91, jqxz2008): this lib was completely command-dead after registration (AGENTS.md §15ae)

Archive #91 (`金庸群侠传2008加强版.rar`) turned out to have a master.c
byte-identical (in both `adm/single/` and `adm/obj/` locations) to this
lib's raw archive -- confirmed via md5sum, not assumed -- explaining
this lib's previously-unexplained "config says 侠客行三 but live banner
says 金庸群侠传" oddity: this is a rebrand of the same underlying
codebase. That later processing pass (after §15ae, the `private
nomask` command-hook bug, had been discovered) flagged this lib for a
check, since its own original testing above never verified a
post-login command -- exactly the blind spot §15ae warns about.

Checked and confirmed: `feature/command.lpc`'s `command_hook()` was
`private nomask` (the `home/command.lpc` copy was already correct,
`nomask` without `private`). `commandd.lpc`'s `sscanf` pattern was
ALREADY `"%s.lpc"` (not the `".c"` variant found on `bxsj`/`bxsj1`/
`jinyongwenzi` — so §15ar's second bug does not apply here, only
§15ae's). Fixed by dropping `private`; re-verified with a fresh full
registration (id → confirm → real Chinese name "秦岳"/"秦淮" → password
→ stat-gift accept → email → gender) reaching an actual starting room
(客店), with `look`/`score`/`quit` all now producing correct real
output, `debug.log` clean (0 `error:` lines — the "编译时段错误"
warning-spam visible to the player during testing is the separate,
still-unfixed §15w bug, cosmetic and unrelated to command dispatch).

## Re-verification pass (driver rebuild + LPC formatter + WASM build)

- **Reformatted** all 2981 `.lpc` files under `work/` with
  `tools/lpc-syntax/format-corpus.mjs`: 2948 written, 13 already
  idempotent-clean, 20 refused by the tool's own token/byte-identity
  guard (expected on messy legacy code, not chased). Verified the §15ae
  fix above (`feature/command.lpc`'s `command_hook` staying `nomask`
  with `private` dropped) survived the reformat unchanged.
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): clean boot, zero fatal errors in `log/debug.log`. Full
  registration flow re-verified with a fresh real Chinese name
  (`秦墨`/id `xkxcnex`), reaching the actual starting room (`客店`),
  `look`/`score`/`quit` all producing correct output — confirms the
  §15ae fix continues to hold under both the rebuilt driver and the
  reformatted source. No regressions.
- **WASM build test** (`scripts/wasm_client.js` against
  `~/src/fluffos/build-wasm/src`): boots cleanly (only benign compile-
  warning spam, no fatal errors). Full registration completed end-to-end
  under WASM too — id `xkxcwas` → real Chinese name `秦岭` → password/
  stat-roll-accept/email/gender → landed in the same `客店` starting
  room, `look`/`score`/`quit` all produced correct output (post-login
  command dispatch, i.e. the §15ae fix, also confirmed working under
  WASM). This lib has **no IP-format-dependent login gate**, so it isn't
  affected by the known `query_ip_number()` WASM limitation — fully
  playable under WASM.

## WASM-enablement pass (loopback-allow / admin seeding)

This lib is byte-identical (per §2.1 lineage check) to the
`jqxz2008` engine/daemon files, whose WASM pass was
already done and verified with the correct fail-closed convention —
ported that fix here and re-verified independently rather than
assuming it (§2.1's "ported fixes still need per-lib verification").

- `adm/daemons/band.lpc` `is_banned()`: added a loopback short-circuit
  `if (stringp(site) && (site == "127.0.0.1" || site == "::1" ||
  (strlen(site) >= 4 && site[0..3] == "127."))) return 0;` before the
  regexp ban-list scan. Written fail-closed from the start: only a real
  loopback-shaped string counts as local; a malformed/empty/non-string
  site is NOT treated as local and still goes through the regexp ban
  check. `logind.lpc`'s `BAN_D->is_banned(query_ip_name(ob))` gate in
  `logon()` is thereby loopback-proof.
- No `uptime()` startup-grace gate and no per-IP anti-flood/registration
  throttle exist in this lineage (checked the full `logind.lpc`
  input_to chain; the only other connection-adjacent gate is the
  in-memory `mad_lock` admin lockdown flag, default off — game/admin
  design, left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the
real flow (id → y → 浮浮 → password ×2 → talent accept `y` → email →
`m`). Granted `(admin)` by appending `fluffos (admin)` to
`adm/etc/wizlist` (shipped with `sbaa (admin)` already present;
`securityd.lpc` reads this file at `create()`, so a driver restart was
needed to pick up the new line). Verified after restart: `目前权限：
(admin)`, title `【天神】`, `update /adm/daemons/band` →
`重新编译 /adm/daemons/band.lpc：成功！`.

Save files for the orchestrator to force-add (untracked, not
gitignored):
- `libs/xiakexing3/work/data/user/f/fluffos.o`
- `libs/xiakexing3/work/data/login/f/fluffos.o`

Retest: fresh boot, fresh registration (id `qretest`, real Chinese name
秦风十) through `look`/`score`/`quit` — landed in 客店, correct output,
clean quit. `fluffos`/`Mud@2026` admin login verified twice (once via
`update`, once via `score` to confirm `(admin)`/天神 status directly).
Zero `执行时段错误` lines in `debug.log` across the whole session. Test
character `qretest` removed afterward; fluffos kept.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一代码库换牌重发（master.c 逐字节相同）。

## 深度功能测试（§10.7，2026-08-05）

WASM 阶段的"完整验证过注册流程，没有发现 bug"结论需要更正——这次
§10.7 深挖在注册后的日常操作（留言板发帖）里找到一个此前从未触发
过的致命 bug，此外还确认并修好了两个在本轮次开头就已发现的问题。

- **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/logind.lpc`
  `enter_world()` 里 `if (!user->query("food") && !user->query("water")
  && ob->query("age") == 14)` 判断的 `ob->query("age")` 拿的是登录阶段
  用完即弃的连线桩物件，而不是真正的玩家角色本体 `user`——桩物件永
  远没有 `age` 这个属性，条件恒为假，导致**每一个新角色的食物/饮水
  永远初始化成 0**。改成 `user->query("age") == 14` 后，live 验证：
  修复前新注册角色 `score` 食物/饮水两栏都是空的（□□□），修复并
  重启驱动后同一注册流程走到底食物/饮水都是满格（■■■），第二次
  重启后（新角色 `testfive`）依然保持满格，确认修复稳定。
- **`get_name()` 里一行遗留调试 `printf("%O\n", ob)`**：紧跟在玩家
  输入中文姓名之后，会把连线桩物件的原始引用（形如
  `/clone/user/login#0`）直接回显给正在注册的新玩家，是内部调试信
  息泄漏。已删除该行；删除前后的注册流程 transcript 对比确认泄漏
  行消失、其余流程不受影响。
- **缺失的 `log/nosave/` 目录**：`adm/daemons/combatd.lpc`、
  `cmds/std/kill.lpc`、`cmds/skill/apprentice.lpc`、
  `cmds/skill/bai.lpc` 都会往这个目录写文件（主要是 PK 击杀记录和
  拜师技能的 FENG 记录，多数写入点还带 `userp()` 判断，NPC 战斗未
  必会触发），但 AGENTS.md §7.11 已经在这个 `jqxz2008` 系列的其它
  版本上确认过"目录缺失导致复活流程卡死"这个确切形状，属于零风险
  的预防性修复，提前建了这个目录（.gitignore 规则本身就会忽略
  `work/**/log`，不需要额外 git 操作）。
- **§7.86（第四个确认命中的独立血统家族）留言板 `post` 崩溃**：在
  起始房间"客店"的留言板（`clone/board/kedian_b.lpc`）测试
  `post board` 时，瞬间抛出运行时错误：
  ```
  执行时段错误：*cannot bind an lfun fp to an object with a pending replace_program()
  程式：/inherit/misc/bboard.lpc 第 102 行
  物件: /clone/board/kedian_b
  呼叫来自：/inherit/misc/bboard.lpc 的 do_post() 第 102 行，物件： /clone/board/kedian_b ("客店留言板")
  ```
  这行错误文字和 AGENTS.md §7.86（首次在 `xhcii` 上发现）记录的完
  全逐字一致（仅行号不同，102 行对应这份档案自己的
  `/inherit/misc/bboard.lpc` 里同一处
  `this_player()->edit((: done_post, this_player(), note :))` 闭包
  创建语句）。检查 `kedian_b.lpc` 确认是标准的致命形状：既
  `inherit BULLETIN_BOARD;`，`create()` 结尾又多余地对自己
  `replace_program(BULLETIN_BOARD);`。`grep` 全档案后确认这份档案
  一共 18 个留言板实例全部命中同一形状（`clone/board/` 下 17 个
  `*_b.lpc`/`*_r.lpc` 加上 `d/taohua/taohua_b.lpc` 一个重复放置的
  桃花岛留言板），没有发现 `sje` 那种运行时生成留言板源码的工厂变
  体。修复：18 个文件全部只删除多余的 `replace_program(BULLETIN_BOARD);`
  一行，保留 `inherit BULLETIN_BOARD;`，CRLF 行尾格式原样保留。
  Live 验证：重启驱动后用测试角色 `testfive`（李四）在客店留言板
  `post board` 顺利进入编辑器，输入正文、`.` 结束后提示"留言完
  毕。"；`look board` 显示未读数正确从 1 涨到 2，新增一条署名"李
  四"、时间戳为当天的记录；`read 2` 能完整读出刚才写的内容。测试
  完成后已把该留言板存档 `work/data/board/kedian_b.o` 还原到修复
  前的原始内容（只保留档案自带的那条测试留言），不留会话痕迹。此
  修复顺带把该存档文件的类头从 `#/inherit/misc/bboard.c`（`post`
  以外的场景之前一直"变身"成的那个类）改成了 `#/clone/board/kedian_b.lpc`
  （物件自己的真实文件）——纯粹是移除多余 `replace_program()` 的
  自然结果，存档数据本身不受影响，`restore()` 也不严格校验这行类
  头字符串。已在 AGENTS.md §7.86 追加这份档案作为第四个确认命中的
  独立血统。
- **§7.88 message() 参数缺失检查**：走查了 `adm/simul_efun/message.lpc`
  （通过 `adm/obj/simul_efun.lpc` 的 `#include`），`message_vision`/
  `tell_room`/`shout`/`say`/`write` 全部只是转呼叫内建 `message()`，
  没有本档案自己重新定义/包装一个签名不一致的 `message()`，不适用
  §7.88 这个特定形状。
- **§8.3a/§8.3b 指令表**：本轮登录、`look`、`score`、`post board`、
  `kill`、移动指令全部正常响应，WASM 阶段笔记里"已检查过没问题"的
  结论继续成立。
- **战斗与移动测试**：从"客店"往西走到"北大街"（遇到"白驼山少庄
  主「玉面蛇心」欧阳克"这个调戏 NPC，纯对话骚扰不主动攻击），再往
  南到"中央广场"，对普通"流氓"（Liu mang）发起 `kill`，多回合拳脚
  攻防（出拳/踢腿的命中、闪避、擦伤判定文字均正常），最终测试角色
  体力耗尽昏死，`debug.log` 全程零 `执行时段错误`。
- **死亡→复活流程完整走通，无需人工干预**：角色死亡后自动送入
  "鬼门关"，NPC"白无常"翻账册确认"阳寿未尽"后放行 `north` 到
  "酆都城门"，NPC"黑无常"重复同一套账册判断后主动"哼"一声送出，
  一股"阴冷的浓雾"把角色直接传送到复活点"武庙"（岳王庙正殿）。全
  程无需任何指令输入之外的干预，也没有出现 AGENTS.md §7.68 记录
  的那种"present() 判断游戏对象已经不在场导致流程卡死"的鬼魂卡死
  形状——**按 §7.68 的既有结论，这里明确不施加那条已经在其它 lib
  撤回的重试修复**，只如实记录观察到的行为。复活后 `score` 确认
  精/气恢复到约四成、食物/饮水依旧满格（§8.9 修复在多次死亡后依
  然生效）、实战经验从 0 涨到 3。
- 本轮测试方法论：中文角色名（李四）通过 `mudclient.py` 原始
  socket 发送，注册流程与两次驱动重启后的复测均未再撞上此前记录
  过的本地 `telnet`/CJK 字节转义问题；`post`/`kill`/移动等纯
  ASCII 指令改用 `scripts/tmux_mud.sh` 的 tmux 会话完成，全程无异
  常。
- 会话结束前清理：删除测试角色 `testfive`/`testfour` 的存档
  （`work/data/{login,user}/t/*.o`，均无 git 历史、确认是本轮测试
  产物）；`kedian_b` 留言板存档已还原；停止 tmux 会话、终止驱动进
  程；未触碰其它 lib 的任何未追踪文件。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。

### 发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。

### Proactive checks（无需改动）

- `log_error()`（`adm/obj/master.lpc`，即实际生效的 master file）
  已经在 WASM 阶段修复过（`strsrch(message, "arning:") == -1` 判
  断），确认仍然生效。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:176`、`u/wind/refereew.lpc:176`、
  `u/wind/refereew2.lpc:184` 均已用 `to_int(query("win_times")) %
  N`。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

管理员 `fluffos`/`Mud@2026` 用真实密码重新连线，落地在此前保存的
地点（客店），`score` 显示"【天神】"头衔和正确的属性数值，留言板
未读数正常显示。全程 `debug.log` 无运行时错误。驱动按精确 PID 结
束；测试期间产生的存档时间戳增量已 `git checkout --` 还原。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 795 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与 `jqxz2008`/
`jyqxc` 系列同一血统同一形状。`clone/misc/roommaker.lpc` 同样有两
套模板——"造一间空房间"的 heredoc 本来干净，"克隆我所在的房间"命
令的字符串拼接模板把同一枚多余的 `replace_program(ROOM);` 烤进了
每一个新克隆的房间，已同步修正。已用 `build-debug` 驱动干净启动
验证（0 个新增编译错误，端口正常监听）；未做完整 §10.7 深度游玩
测试。

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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师。2026-08-05 / 2026-08-13 两轮都没
测这两步。`F_DEALER` 对丐帮拒绝购买（穷叫化），必须先买再拜。

### 实测过程

管理员 `fluffos` / `Mud@2026`。第一输入是 `您的英文名字：`，落地客
店。`goto /d/city/zuixianlou`，`list` 烤鸡腿八十文铜板 / 包子五十文
/ 牛皮酒袋一两白银。`clone /clone/money/gold` 后 `buy jitui` 成功
（「你从店小二那里买下了一根烤鸡腿」）。当场 `i` 还挂着「一两黄
金」，那是 `MONEY_D->player_pay()` 把金锭 `set_amount(0)` 后物件还
没析构的显示；quit 后再连只剩九十九两白银 + 二十文铜板（10000−80
= 9920），找零数学正确，不是复制金钱。

`goto /d/gaibang/inhole`，`apprentice zuo` 一次成功：左全收徒，
`score` 「丐帮第二十代弟子」、师父左全。`cmds/usr/save.lpc` 真正调
用两个 `save()`。`user.o` 立刻带上 `family_name":"丐帮"` /
`master_name":"左全"`。断线后再连，`score` 仍是丐帮 / 左全，银子还
在。烤鸡腿未进 autoload，quit 后不在身上。

本轮没有新的 programming bug。左全只收男性（`gender != "男性"` 就
静默 return），本账号是男的所以没撞上。live `debug.log` 是
`libs/xiakexing3/log/debug.log`（Boot Time Fri Sep 4 00:43:12
2026），无 `error:` / `Too deep recursion`。`error_handler` 把轨迹
交回驱动 debug.log；`work/log/log` 只有编译期 Unused local
variable 警告。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-05）— 巫师留言板存档 `data/board/*.o.gz`

巫师留言板 `wiz_b` / `towiz_b` 以 `.o.gz` 存档（1996 年的帖子）。本机驱动 `restore_object()` 优先读 `.o.gz`，而留言板用 `save_object(file)` 写明文 `.o`，所以本机上新帖每次重启都退回旧快照；网页版驱动没有 zlib，只读 `.o`，而归档自带的 `.o` 是读不出的二进制。`.gz` 内容为 GB18030（转码时没被处理），转成 UTF-8 写成 `.o`，替换归档里那个读不出的二进制 `.o`；`towiz_b` 原文有 4 个残字节，转为替换符。删除 `.o.gz`（KB 01）。用 lpcc 载入留言板核对条数（jqxz2008：wiz_b 47 条、towiz_b 115 条）。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xiakexing3 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 229 个 `.lpc` 和 8 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：212 -> 212 通过，无回退；改过的头文件的 36 个包含者 34 -> 34 通过。启动时警告 16 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 11 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 10 个文件，HEAD 与工作树各载入一次无回退（10 objects; HEAD PASS 10, tree PASS 10; regress 0; newly loading 0），这些文件的警告 11 -> 0。

- 2026-10-10（续）：第二轮编译警告整理（`lpc_fix_unused_init.py`）删掉了只在不启用的 `#if` 分支里用到的局部变量声明（如 `include/net/ftpdsupp.h` 中 `#ifdef GUEST_WIZARD_FTP` 分支的 `file`），启用该选项时会编译失败；声明已放回所用的分支里，工具已改为跳过这种情况（交给 `lpc_move_decl.py`）。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮加两处手工，能编译的文件警告清零。改动的 37 个对象 HEAD 与工作树各载入一次：HEAD PASS 29，tree PASS 32，regress 0，新载入 3。

- 冗余继承 35 处（`lpc_diamonds.py`）。其中 `d/mingjiao/npc/yinwufu`、`yinwulu`、`yinwushou` 的基类已经继承 `F_UNIQUE`，叶子又 `inherit F_UNIQUE;` 一次，驱动报 `Illegal to redefine 'nomask' function 'violate_unique'`，这三个明教 NPC 从来载不进来；删去后都能载入。
- `kungfu/skill/hubo.lpc`（`ITEM` 与 `SKILL` 都带 `F_CLEAN_UP`）用 `lpc_name_winner.py` 写出驱动本来就选的 `skill::clean_up()`。
- `include/net/ftpdconf.h` 把 `ftpd.h` 的 `VALID_READ`/`VALID_WRITE`（0）改定义为 1，`ftpd.lpc` 两个头都 include；在改定义前加 `#undef`，取值不变。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：5 个对象，新增载入 4，回退 0。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`jiuyang-shengong`、`liumai-shenjian`、`taiji-shengong`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。7 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

3 个文件、4 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/obj/tudao`、`/d/city2/obj/obj/diaopi`、`/d/xueshan/npc/obj/senggun`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 3 个（3 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`clone/npc/meng-zhu.lpc`、`cmds/arch/purge.lpc`、`cmds/usr/suicide.lpc`、`d/quanzhou/npc/tang.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`、`include/net/ftpdsupp.h`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`suicide` 是自杀指令；`purge` 是清除玩家档案的巫师指令；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：6 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（4 个名字，最多的是 `xiake-force`、`xiake-strike`、`xiake-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 0 个通过，其余 1 个停在别的错误上（`kungfu/class/xiake/master`：*No program in object '/kungfu/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/emei/duguangtai` 的 `north`：`huazangzn` → `huazangan`；`/d/emei/jietuopo` 的 `west`：`guanyitang` → `guanyintang`；`/d/emei/jiulaodong` 的 `northeast`：`jiudaoguai4` → `jidaoguai4`；`/d/mingjiao/jmqshulin6` 的 `west`：`jmqjiguan` → `jmqshenmu`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 4 处、3 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/d/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/usr/to.lpc`（1 处）、`/cmds/wiz/to.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 存档里的乱码文件：`restore_object()` 报 `Illegal file format`（2026-10-20，KB 06 §7.316）

存档里有一批数据文件是乱码：开头是 `?adm`、`?inh`、`?clo`、`?obj`（`#/adm/…` 的第一个字节被换成了 `?`），后面是随机字节，没有任何驱动读得了。`adm/daemons/chinesed` 在预载时 `restore()` 读 `data/e2c_dict.o`，首次登录时起始房间的留言板 `/clone/board/kedian_b` 读 `data/board/*_b.o`；`restore_object()` 对不是文本的文件抛 `Illegal file format`，调用处的 `catch()`（KB 06 §7.255）保住了房间和精灵，但本库 master 的 `error_handler()` 把调用栈返回给驱动，每次启动和首次登录都在控制台打印一次或两次 `错误讯息被拦截`。现在共用的 `feature/save.lpc` 的 `restore()` 先读文件第一个字节，不是 `#` 就返回 0（读被 master 拒绝时 `read_bytes()` 返回 0，仍由 `restore_object()` 决定，和以前一样）；留言板和字典从空开始，第一次 `save()` 写出合法文件，乱码文件原样留在树里。实测：启动和登录都没有报错，已保存的角色重新连线照常加载。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 3 个存档共 6 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/d/shaolin/npc/obj/kat.o`（1 处）、`/d/shaolin/obj/kat.o`（1 处）、`/d/shenlong/obj/lxlx.o`（4 处）（共 3 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

同一轮里 `/cmds/arch/tttt.lpc`（`new("/obj/test.lpc")` 之后 `user->restore()`）也报 `Bad argument 1 to call_other()`：本库没有 `/obj/test.lpc`，`new()` 答 0。加了 `if (!user) return notify_fail(...)`。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/adm/recover.lpc`、`/cmds/arch/blockade.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 1 条注册（1 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/inherit/misc/fboard.lpc`（`do_list`）。最多的函数名：`do_list` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/huashan/npc/teller.lpc`:`tell_fortune`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"算命": (: tell_fortune :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 17 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 17 处（12 个文件）：拼名字的赋值 9 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/shaolin/cheng.h:156`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:104`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:140`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 黑木崖脚下的老者：`init()` 里留着调试语句，每个走进 `/d/heimuya/road1` 的人都触发运行时错误（2026-10-22，KB 06 §7.361）

`d/heimuya/npc/laozhe.lpc` 的 `init()` 在 `::init()` 之后有 `what = new(__DIR__ "obj/yancao"); sprintf("%s aaa\n", what);`：调试遗留，`%s` 收字符串或数字、不收对象，于是 `(s)printf(): Incorrect argument to type %s. (arg: 0)` 每次有人进入乱石坡都抛一次，后面的 `call_out("greeting", ...)` 永远不执行，老者不再搭话（还每次白克隆一个烟草）。两行都注释掉（同系的 haiyang2 / hy / hy5 / cctx / fqyy2 早就注释了）。证明：`scripts/lpc_reach_census.py xiakexing2017 --load --walk`（一个普通 NPC 访客走进每个加载成功的房间）：HEAD 336/337，改后 337/337。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。

