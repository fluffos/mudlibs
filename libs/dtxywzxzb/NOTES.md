
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记血统代码库（大唐西游/Journey of the East）。完整 WASM 修复：（1）adm/daemons/convertd.lpc 的希腊字母表漏斜杠错字（§6.6，约 45 处，完全符合已记录的模式），导致 simul_efun 编译失败——已用文档记载的 CRLF 安全 sed 脚本修复；（2）两份用途相同的档案陷阱（§7.56 类）：既有一份 /daemons/logind.lpc（死代码副本，没有任何 LOGIN_D 宏引用它），也有真正被 LOGIN_D 宏解析到的 /adm/daemons/logind.lpc——一开始追错了档案，得到一个完全不同（而且更短）的注册流程；真正生效的档案比死代码副本多了几个步骤（夹在中文名字和普通登录密码之间的一道独立"管理密码"步骤，规则更严格，外加性别选择之后的属性重掷菜单）。（3）GB/BIG5 编码选单（§8.7"第二种形态"，本地整数旗标覆盖+convertd.lpc 字节对照表）这次是真实存在的 bug——选 BIG5 会疯狂输出"Invalid GB code"并弄花画面，因为这张对照表假设的是原始 GB2312 字节，而这份代码库现在全程都是 UTF-8——已把两个选单选项都对应到 encode=0（这个家族的 convertd.lpc 本来就把它当成安全直通）。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 36 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

原生驱动（`~/src/fluffos/build/src/driver`，linux-debug + ASAN/UBSAN）从档案根目录启动，端口 40150 正常监听。WASM 验证跳过（emsdk 被代理拒绝，与其他档案一致，未在 WASM 下复测）。

### 发现并修复的 PROGRAMMING bug

1. **`do_counter()` 对缺失计数器档案的 `sscanf` 未加保护（AGENTS.md §7.9/§7.54 的又一确认实例）**：`adm/daemons/logind.lpc` 的 `do_counter()`（`/adm/daemons/UserNumber`，gitignore 中明确标注为运行期数据、全新检出必然缺失）对 `read_file()` 的返回值不做 `stringp()` 检查就直接喂给 `sscanf()`；该档案在全新检出上必然不存在，触发 `*Bad argument 1 to sscanf` 未捕获运行期错误。要命的是这行代码在 `encoding()` 里排在"是否为中小学生"提问**之前**（第 205 行 vs 第 246 行），未捕获错误直接把整个 `encoding()` 函数中断，导致**每一个全新连线**都卡死在编码选择之后——连接对象仍能收命令（回显默认失败讯息"什么？"），但永远等不到任何注册提示，注册流程彻底瘫痪。修复：`if (stringp(file)) sscanf(file, "%d", number);`。已用真实连线复现（修复前）并复测通过（修复后，见下方"实测过程"）。
2. **`log_file()`/`master.lpc` 的 `log_error()` 缺少 `assure_file()` 目录保护（AGENTS.md §7.11 的又一确认实例）**：`adm/simul_efun/file.lpc` 的 `log_file()` 和 `adm/obj/master.lpc` 的 `log_error()` 都直接 `write_file()` 到 `/log/` 下，全新检出该目录不存在（gitignore 明确排除），每次调用都抛出未捕获的 `*Wrong permissions for opening file ... for append` 运行期错误——预加载阶段仅 NPC 心跳（如 trashman 的 `clean_trash()`）就已经刷屏了几十次。已补上 `assure_file()` 调用；`file.lpc` 里 `log_file()` 定义在 `assure_file()` 之前，同档案内前向调用在本驱动上不会自动解析（AGENTS.md §6.5），额外加了一行前向声明 `void assure_file(string file);`。
3. **`toptend.lpc` 的 `topten_save()` 同样缺 `assure_file()`（§7.11 变体）**：`data/topten/` 目录全新检出缺失，`topten_save()` 只检查了 `write_file()` 的返回值却没有先保证目录存在，导致**每一次新角色注册**（`enter_world → confirm_gift → topten_checkplayer → topten_add ×11 → topten_save`）都抛出一次未捕获的 `*Wrong permissions for opening file /data/topten/rich.o for overwrite`（11 种排行榜各一次）。虽然这次没有中断注册流程本身（远早于中断点的 `do_counter()` 已经先被修复，且该错误发生在 `enter_world()` 更靠后、`move()` 之前，本身似乎不会级联中断——但仍是刷屏噪音+潜在的排行榜数据丢失），补上 `assure_file(f_name)` 后已用一次性测试角色复现问题、复测通过。
4. **`cmds/arch/setskill.lpc` 单技能删除分支引用了错误/未初始化变量**：`setskill <人物> <单个技能> 0`（非 `all`）分支里，`write()` 用的是 `skills[i]`，但 `skills`/`i` 只在 `all` 分支里被赋值，这里永远是未初始化的 `0`/空值，触发 `*Value being indexed is zero`（管理员命令直接崩溃）。已用真实 `setskill shenyh parry 0` 复现（修复前）并复测通过（修复后）：改成引用真正的局部变量 `skill`。

### 实测过程（同一连续会话）

1. 读 `doc/help/newbie`：确认起始场景为长安城南城客栈，拜师走 `apprentice`/`bai`，学艺走 `learn <功夫> from <师父>`。
2. 修复前用真实连线复现"注册永远卡在编码选择后"的问题（见上）；依次定位、修复、用 `~/src/fluffos/tools/lpc-syntax/bin/format-corpus.mjs` 格式化、重启复测，前后共 3 次重启才把 §7.9 类和 §7.11 类两个独立 bug 都揪出来。
3. 全新注册真实中文名角色"沈月华"（id `shenyh`），走完整注册流程（gb 编码 → 非中小学生 → 英文名 → 中文名 → 管理密码 → 登录密码 → 邮箱 → 性别 → 天赋 9/确认）。`look`/`score`/`i` 均正常显示。
4. 战斗机制：`cmds/std/fight.lpc` 用的是 `can_speak` 判定安全切磋 vs 直接开打（`obj->query("can_speak")` → `accept_fight()`/`fight_ob()`；否则 `kill_ob()`），与本次会话在其他血统里反复确认的变体一致。新手客栈本身 `no_fight`；在朱雀大街西侧的长安乐坊对"公孙大娘"（可讲话 NPC）使用 `fight`，机制正确触发（对话+`accept_fight()`），NPC 因 `attitude=friendly` 拒绝切磋——这是既有设计，不是 bug；机制本身（判定分支、`notify_fail`、无崩溃）验证通过。
5. 技能/门派获取，两条路径都验证：
   - **管理员捷径**：`cmds/arch/setskill.lpc`（需要 `(arch)` 或以上权限），`setskill shenyh unarmed 3` 成功（过程中发现并修复了上面第 4 个 bug）。
   - **正常游戏内路径**：`fluffos` 管理员用 `goto`+`summon` 把测试角色叫到 `/d/jjf/jjf_bingqi`（兵器架），对无条件接受的将军府管家"秦平"（`d/jjf/npc/qinping.lpc`，`attempt_apprentice()` 无门槛）使用 `apprentice qin ping`，成功拜师；`score` 确认门派/师承字段正确更新；`learn parry from qin ping` 成功习得新技能，`skills` 显示等级 1。全程无崩溃、无报错。
6. quit 宽限期：`cmds/usr/quit.lpc` 对 `time()-birthday<3600` 的新号有二次确认逻辑，测试角色处于此窗口内，因此没有直接发 `quit`——改用直接终止客户端进程模拟断线（本来每次 mudclient.py 调用结束就是这样退出的）。
7. 等待真实时钟间隔（期间做静态代码审查、grep 排查、撰写本节笔记，实际间隔数分钟，驱动累计运行 11+ 分钟）后重新连线登录，`look`/`score`/`skills`/`i` 确认角色位置（兵器架）、门派（将军府/秦平）、技能（parry 1 级、unarmed 3 级）全部正确持久化。
8. `grep` 全程 `log/debug.log`（本档案 `log directory` 配置解析到档案根目录下的 `log/`，而不是 `work/log/`——两处都检查过，本档案实际写入的是前者）：除上面 4 个已修复的 bug 各出现过一次外，无其它未捕获运行期错误。

### 发现但判定为既有设计、未改动的现象

- 预加载阶段出现过一次孤立的 `*Too long evaluation`（`/d/obj/drug/jinchuang` 冷编译，触发自 `/d/npc/ts.lpc` 的随机 NPC 携带物品生成，`feature/dbase.lpc` 第 41 行），仅一次、且发生在玩家连线之前，未再复现，也没有影响本次任何玩家可见的操作路径——判定为 `maximum evaluation cost: 700000` 下偶发的冷编译开销，未观察到它实际阻塞过任何玩家操作，未调整该配置值。
- `公孙大娘`（长安乐坊）以 `attitude=friendly` 拒绝一切切磋请求——`std/char/npc.lpc` 的 `accept_fight()` 对 `friendly` 属性 NPC 硬编码拒绝，这是设计使然（"友善"NPC 不切磋），不是 bug。
- README 记录的管理员账号 `fluffos` 在磁盘上实际不存在（`data/login/f/` 下没有对应存档，此前的 WASM 修复记录可能只是流程记录、存档从未真正提交），本次按 AGENTS.md §1.5 流程重新走真实注册创建，`update` 命令验证 ACL 正常，已提交存档。

### 已清理

- 测试用一次性小号 `shenyh`、`toptt` 的存档（`data/{login,user}/{s,t}/`）已删除，未提交。
- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`），密码与 README 一致。

## Deep functional test round two (2026-08-14)

Independently re-verified all 4 round-one fixes still hold (`do_counter()`
`stringp()` guard, `file.lpc`/`master.lpc` `assure_file()` guards,
`toptend.lpc` `assure_file()`, `setskill.lpc`'s `skill` variable fix — all
confirmed present by direct code inspection). Found and fixed three more
issues on top: a new §7.10-class log_error() gate gap, an active printf
leak, and — the highest-value find — a §7.90-class eval-cost abort that
was the ROOT CAUSE of two separate-looking crashes (`update.lpc` and
`quit.lpc`), and turned out to match a shape already confirmed on two
other libs this session, now a corpus-wide sweep candidate (128 libs).

### New fix 1: `adm/obj/master.lpc`'s `log_error()` had no severity gate at all

Same shape found on `dfgsiiv13b` earlier this session — not the more
common case-mismatch variant, but a complete absence of any warning/error
distinction:
```lpc
// BEFORE:
if (this_player(1)) efun::write("编译时段错误：" + message + "\n");
// AFTER:
if (this_player(1) && strsrch(message, "arning:") == -1)
  efun::write("编译时段错误：" + message + "\n");
```

### New fix 2: active `printf("%O\n", ob)` debug leak in `logind.lpc`

Reached on every registration, right before the "请设定您的管理密码："
prompt in the manual-name-confirmation branch. Removed (one-line deletion,
`// by canoe for suppwd` comment above it left in place as it's clearly an
old author annotation, not describing the printf itself).

### New fix 3 (root cause of two crashes): §7.90-class eval-cost abort during `enter_world()`'s cold room compile — reused the established remedy, and it happens to explain why the `update.lpc`/`present(environment(me))` crash class exists at all

- **How this was found**: first admin login this pass hit `update` and
  got `*Bad argument 2 to present() Expected: object Got: 0.` at
  `cmds/wiz/update.lpc:20` — the exact same crash shape already found and
  fixed on `xiakexing2017` and `dtslmud` earlier this session. Applied the
  same defensive fix there:
  ```lpc
  // BEFORE:
  if ((obj = present(file, environment(me))) && interactive(obj)) {
  // AFTER:
  if (environment(me) && (obj = present(file, environment(me))) && interactive(obj)) {
  ```
  But unlike the other two instances, this pass also caught the SAME
  session's `quit` crashing too (`*Bad argument 3 to EFUN message()` at
  `cmds/usr/quit.lpc:75`, `message("system", ..., environment(me), me)`)
  — both crashes share one root cause: `debug.log` showed `Eval
  interrupted: object obj/user#7 cost limit reached, limit: 700000 usec`
  during `enter_world()`'s cold compile of the admin's real starting room
  (`/d/city/kezhan.lpc`), aborting mid-`enter_world()` and leaving the
  character with no environment at all for the rest of that session — a
  direct instance of AGENTS.md §7.90's already-documented class (the
  700000usec project-template default sitting at the low end of what
  libs in this corpus actually need).
- **Fix**: `config.fluffos`: `maximum evaluation cost : 700000` →
  `5000000` (§7.90's established remedy, already used by 30+ other libs).
- **Verified**: fresh reboot, first login as `fluffos` landed cleanly in
  the real starting room (`「南城客栈」`), `update`/`quit` both succeeded
  with zero errors, across two further rapid reconnects. The
  `update.lpc` defensive guard (fix above) is still worth keeping even
  though this config fix eliminated the specific reproduction — any
  admin whose environment is legitimately unset for any other reason
  would still hit it otherwise.
- **Corpus-wide implication, not yet acted on beyond this lib**: grepped
  for the `update.lpc` crash shape (`present(file, environment(me)))`
  without an `environment(me) &&` guard) — **128 other libs** share the
  identical vulnerable code, only 3 (`xiakexing2017`, `dtslmud`, this lib)
  fixed so far, each found independently this session. This crosses this
  project's own "3+ independent lineages" threshold for a mechanical
  corpus-wide sweep rather than continuing to find it one lib at a time —
  flagged for the very next work cycle.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`),
`update /adm/daemons/logind` and `quit` as the checks that caught the
eval-cost root cause. Two rapid consecutive admin reconnects post-fix,
both clean. Driver killed by exact PID after each reboot (two total:
initial boot where the crashes were found, clean reboot for
verification); incidental `fluffos.o`/`zhangmen_chang_e.o` save churn
reverted before commit.

### Files modified this pass

- `config.fluffos` — §7.90 fix (`maximum evaluation cost` 700000 →
  5000000).
- `work/cmds/wiz/update.lpc` — `environment(me)` null-check (defensive,
  proactive given the config fix already resolves the specific repro).
- `work/adm/obj/master.lpc` — `log_error()` severity gate (§7.10-class,
  previously entirely absent).
- `work/adm/simul_efun/file.lpc` — `cat()` null-guard.
- `work/adm/daemons/logind.lpc` — removed one `printf("%O\n", ob)` debug
  leak.

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 235 live occurrences deleted: 234 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same lineage as `xiyouji2006`/`xyj2006n`/`xyj2006zzzhx`). 6 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect showing the real login banner on port 40150. Pre-existing untracked debris (`data/zhangmen/zhangmen_{dapeng_mingwang,master_puti}.o`) confirmed left untouched.

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


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).

## 深度功能测试（2026-09-04，round three，shop）

新角度：南城客栈真实购买。§10.7 已经走通将军府秦平拜师 +
`learn parry`，本轮不再拜师。NOTES 全文没有 `buy`/`商店` 实测。

本轮没有新的 programming bug。`log_file()`/`log_error()` 已有
`assure_file()`。第一输入是 GB/BIG5 菜单（发 `gb`；BIG5 也映射到
encode=0），然后「是否中小学生」(no)，然后英文名字。

### 实测过程

管理员 `fluffos` / `Mud@2026`。端口 40150。登陆密码那句是「请输入
密码(管理密码或登陆密码)」，`Mud@2026` 走登陆密码。落地南城客栈
`/d/city/kezhan`，店小二 id `xiaoer`。`clone /obj/money/gold` 一次
成功。`list` 炸鸡腿八十文 / 花生二十文 / 桂花酒袋一两银子等。
`buy jitui from xiaoer` 成功：「你向店小二买下一根炸鸡腿。」`i`
剩九十九两银子 + 二十文钱（10000−80=9920）+ 炸鸡腿。`save`「档案
储存完毕。」`score` 门派仍是普通百姓（拜师角色是 `shenyh`，本轮
用管理员号只测商店）。

live `debug.log` 是 `libs/dtxywzxzb/log/debug.log`（Boot Time Fri
Sep 4 03:51:35 2026），无 `error:` / `Too deep recursion`。玩家可见
0 条「编译时段错误」。管理员存档未提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 6 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 263 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 4 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 4、4、4 个（共 4 个），无回退；`adm/daemons/questd.lpc`、`daemons/cron.lpc` 原先加载失败，现在加载成功。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py dtxywzxzb --fix`：无用局部变量 2004 个、`varargs` 63 处、转义 8 处、裸 `return` 7 处、`nosave` 函数 16 个改 `protected`，共改动 975 个 `.lpc` 和若干 `.h`。`scripts/lpc_fix_no_effect.py --apply`：`d/dntg/doushuai/bgl1.lpc`、`d/dntg/yunlou/npc/yaoguai.lpc`（及 `u/canoe/` 副本）的 `for (n == 0; ...)` 改成 `=`；两份 `xuanyuan-archery.lpc` 的 `practice_skill()` 删去什么也不做的 `(: throw_weapon :);`；三份 `dns_master.lpc` 把 `#if PREF_* & SVC_TCP` 移到 `if` 外面。
HEAD 与工作树分别加载（新进程）：941 -> 941 通过，无回退；改过的头文件的 375 个包含者 361 -> 361 通过。`scripts/lpc_audit_removed_locals.py HEAD` 的 17 条候选都是声明被重建或同名 efun。
未动：`d/city/npc/vikee.canoe.lpc`（及 `npc/npc/` 副本）把 `case` 写成 `cast`，是没人引用的旧副本；`adm/simul_efun/oo.lpc` 单独编译的告警是被包含片段的假象（KB 04 §6.10）。

启动时警告 99 -> 0；新进程登录（编码选择、新人物提问）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 18 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 28 个，只在 #if 分支用的声明移进分支 0 个文件；改动 36 个文件，HEAD 与工作树各载入一次无回退（36 objects; HEAD PASS 35, tree PASS 35; regress 0; newly loading 0），这些文件的警告 138 -> 92。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

`scripts/toolkit_fix.sh` 加手工修复，能编译的文件里的警告 114 → 0（全库 9077 → 9079 个文件可编译）。剩下的 3 条都在本来就编译不过的文件里：`adm/simul_efun/oo.lpc`（simul_efun 片段单独编译的假象）和两份残缺的 `10.10/score.lpc`（分号、括号全丢）。做法参照同内容的 xyj2006n（提交 94b87c18461）。

**发现的真实 bug：**
- `d/city/npc/vikee.canoe.lpc` 与 `d/city/npc/npc/vikee.canoe.lpc` 的 `do_yao()` 里 `cast "mace" :` 把 `case` 打错，整个文件编译失败。这两份是没人引用的旧副本（在用的是 `vikee.lpc`），游戏里看不到影响；改成 `case` 后两份都能载入，以后若有人启用也不会坏。（xyj2006n 里也有同样的错字，不在本次范围内。）
- `d/city/npc/sanhua-counter.lpc`（及 `npc/npc/` 下的副本）自己声明的 `int last_time` 跟 `feature/alias.lpc` 的 `nosave int last_time` 同名，驱动把后声明的一份强制成 nosave，所以这个计时从来没存进存档，重启后每次都重新 `check_date()`。改名为 `last_check`，现在会正常保存。

**机械 / 结构修复：**
- 9 处多余的 inherit（NPC/武器/sserver 再次 inherit F_CLEAN_UP）删掉。
- `d/kaifeng/ground.h` 及 `u/yesi/leitai1-4/ground.h`：三张常量表包进 `#ifndef GROUND_TABLES_INHERITED`，继承 ground0 的 ground/ground1/2/3 在 include 前 `#define`（KB 04 §6.10）。
- 擂台 `npc/quest.lpc`（5 份）：`#include "colors.h"` 挪进 `__KAIFENG_QUEST__` 守卫里，`color_code` 不再重复声明。
- `npc/reporting.lpc`（5 份）删掉没用的 `str` 局部变量；`yg/yaoguai.lpc`（2 份）删掉从不读的 `yaoguai_type`（基类 yunlou yaoguai 才用它）。
- `d/dntg/lijing/lijing.lpc` 的 `die()`/`unconcious()` 改为 `void` 空函数（行为不变）。
- `d/obj/cloth/jiasha.lpc` 明写 `void init() { unique::init(); }`，保留驱动原本选中的定义。
- `daemons/toptend.lpc` 重定义的 8 个宏前加 `#undef`（原本就是后一个定义生效）。

74 个对象载入无回退（HEAD 67 通过 → 现在 69 通过，新增 2 个载入）；`lpc_audit_removed_locals.py` 0 条需复查。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

19 个文件、22 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/npc/obj/choupao`、`/d/city/npc/obj/changqiang`、`/d/obj/cloth/cloth`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 19 个（18 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，2 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h；`daemons/network/netmail`：/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（5 个名字，最多的是 `chanting`、`essencemagic`、`qitian-gun`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）
