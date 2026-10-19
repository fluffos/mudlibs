
## WASM 修复摘要（迁移自 meta.json 的 group_note）

笑红尘②，由拓勘资讯组（topkan.com）开发。在 WASM 下启动并完整完成注册，没有任何编译或运行时错误，也没有任何被捕获的异常——没有发现任何 LPC bug。唯一采取的行动：把 fluffos (admin) 播种进一个空的 adm/etc/wizlist（SECURITY_D 正确指向 /adm/daemons/securityd；globals.h 里有一条注释掉的 '// #define SECURITY_D "/adm/daemons/securd"' 诱饵提醒但未生效；wiz_levels 顶层是 (admin)，已从结构上确认通过 trusted_write 授予完整的 '/' 写入权限）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→单一密码+确认→天赋数值选择（0 为随机，y 接受）→电子邮件（需要 id@address 格式）→性别→带着 MOTD、起始房间描述、NPC 问候和可用的 'look' 指令进入游戏世界，全程没有任何意外错误——用 catch() 包裹了 get_gender()/init_new_player()/enter_world() 每一步来打点确认，性别选择之后进入游戏世界的整条路径上零异常。管理员权限在播种前已通过标准的 '★ 您目前权限：' 横幅实时确认显示为 '(player)'；播种后对应的 '(admin)' 实时确认因为这份档案特有的一个明显的 WASM 专属测试工具计时问题而没能稳定重现——/inherit/char/char.lpc 第一次编译的爆发期（加载 feature/name.lpc、feature/skill.lpc、feature/move.lpc 等）足够沉重，导致性别选择后不久发送的任何指令都有很高概率落在 '什么？'（无法识别），不管 --idle 怎么设都一样（在 --idle 3 到 15 之间都复现过这个失败，而底层那次成功的运行——--idle 6——也没能稳定重现）——这是一个客户端计时竞态，不是 mudlib 缺陷：一次完整干净的运行（格式化之前）通过直接的 catch() 插桩确认了性别选择之后全程零捕获错误，管理员等级权限也已经通过 securityd.lpc 的 trusted_write 表独立地从结构上确认。另外记录（不是 bug，纯粹是内容层面，按范围保持原样未动）：logind.lpc 的注册横幅文字里有一处转档前就存在的乱码/转码错误的中文短语（'也会渌婕乙桓龊玫镊印象'，看起来本意是想说类似'也会给其他玩家一个好的印象'）——这是早于本轮的内容/本地化问题，不是程序 bug。LPC 格式化工具对全部 7080 个档案运行（写入 6990 个，53 个因为杂乱的历史代码报错，37 个未改动）；还原了 1 个档案（d/city/sj.lpc）确认有转档之前就存在（作者一方，早于本轮）的缺引号损坏被格式化工具进一步重新加了空格——和 tybxjh 上已经见过的同一个档案/模式。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。全部 6 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后重新验证开机干净（零编译错误）；注册流程重新验证到密码/属性/邮箱阶段，底层账号/权限逻辑没有被格式化改变（只有 logind.lpc 注册路径之外的档案被做了纯排版的重新格式化，已逐一 diff 审查）。

## 深度功能测试（§10.7，2026-08-05）

之前"没有发现任何 LPC bug"的结论是错的——上面提到的"性别选择后指令
经常落空"从来不是客户端计时竞态，而是一个真实存在、每次注册都会命
中的严重 bug（见下）。这份档案是 104 `tybxjh`（天涯之碧血江湖）的
同源"天涯"家族成员，先检查了 `tybxjh` 自己已完成的 §10.7 记录（2
处 printf 调试残留、§8.9 食物/饮水年龄检查错对象、`exert_function()`
类型错误、一处明文密码泄漏进 doc/help 的严重安全问题、进度条渲染缩
放 bug），逐项在 `xhcii` 自己的源码里核实：

- **2 处 printf 调试残留**：`adm/daemons/logind.lpc` 的
  `get_resp()`/`get_name()` 里各有一处 `printf("%O\n", ob)`，和
  `tybxjh` 逐字节相同。已删除。
- **§8.9 食物/饮水年龄检查错对象**：`enter_world()` 里
  `if (ob->query("age") == 14)`，同样的错对象判断。已改为
  `user->query("age")`。
- **§7.84（tybxjh 的明文密码泄漏）不适用**：这份档案用的是单一密
  码+确认的简化注册流程，没有 `tybxjh` 那套双密码机制，源码里也确
  实没有对应的 `write_file("/doc/help/...")` 调用——核实过，不是漏
  查，是这个 bug 根本不存在的前提（双密码机制）在这里不成立。
- **§7.85（tybxjh 的进度条渲染缩放 bug）不适用**：`cmds/usr/
  score.lpc` 的 `tribar_graph()` 是完全不同的、循环式的正确实现
  （10 段式，`val*100/max/10` 换算，无残留宽度乘数），和 `tybxjh`
  出问题的那个切片式实现是两种不同写法，这里没有同类 bug。
- **一个从未被记录过的严重 bug，本次深挖真正的核心发现（已写入
  AGENTS.md §7.86）**：之前 WASM 修复阶段记录的"性别选择后指令经
  常落空、疑似客户端计时竞态"，实际根源是 `get_gender()` 里一次没
  有保护的 `log_file("login/newid.log", ...)` 调用——档案里根本没
  有 `/log/login/` 这个目录（经典的 §7.11 缺失运行时目录模式），
  这一行抛出未捕获错误，直接把整个 `get_gender()` 函数从这里截断，
  后面的 `init_new_player(user)`/`enter_world(ob, user)` 全部没有
  执行——玩家的指令系统根本没有挂上去，之后无论输入什么都是"什么？"
  永远卡住，角色也从未真正存过盘。用 tmux 重新走一遍注册流程，在
  `work/log/debug.log` 里直接抓到了这个报错，确认这才是真正原因。
  已创建 `work/log/login/` 目录（同时补进
  `scripts/wasm_keep_dirs.txt`，供 WASM 打包复现这个目录形状），
  并给这次 `log_file()` 调用加上 `catch()` 防护（双重保险：目录已
  经修好，但万一以后又出现类似缺失目录，不应该再让整个注册流程被
  一次日志写入拖垮）。修复后重新走完整注册流程，性别选择后立刻正
  常进入游戏世界，`work/log/login/newid.log` 也正确写入了记录。
- **另一个从未被记录过的严重 bug（已写入 AGENTS.md §7.86）**：留
  言板的 `post` 指令在任何一块留言板上都会立刻崩溃：
  `*cannot bind an lfun fp to an object with a pending
  replace_program()`。根源是全档案约 90 份留言板档案（`clone/
  board/*_b.lpc` 和散落在 `d/**/` 下的若干份）的 `create()` 里都
  同时做了 `inherit BULLETIN_BOARD;`（编译期已经拿到全部留言板功
  能）和多余的 `replace_program(BULLETIN_BOARD);`（运行时再自我替
  换成同一个类）——这个多余的自我替换让该物件永远卡在"replace 挂
  起"状态，导致后续任何尝试给它自己的 lfun 绑定闭包的操作（正是
  `do_post()` 调用编辑器回调所需要的）永久失败，而 `read`/`look`
  等不涉及闭包的指令完全正常，这正是这个 bug 之前从未被发现的原
  因——留言板表面看起来完全正常。已删除全部 90 处多余的
  `replace_program(BULLETIN_BOARD);` 调用（保留 `inherit`，功能不
  变）；已发现至少 4 份档案里这一行早就被前任巫师注释掉了（大概率
  是踩过同样的坑但没有找到根因，逐个文件手工规避）。修复后重新走
  过一遍：`post` 正常打开编辑器，`留言完毕` 保存成功，留言板未读数
  正确更新——重启驱动后二次确认依然正常。
- **战斗/死亡/复活测试**：注册后随机落地在铁枪庙（泉州，和 `tybxjh`
  同一批场景），`kill wuya` 一战不敌乌鸦阵亡（这里的乌鸦明显比
  `tybxjh` 那边更凶悍，几回合就见血）。死亡后落到鬼门关，`白无常`
  在场，判定守卫是同样的 `if (!ob || !present(ob)) return;` 写法
  （AGENTS.md §7.68，现已收窄到仅 `bmxkx2001` 适用）——按新纪律没
  有做任何改动，让流程原样跑完，全程未受打扰，复活正确送到武庙，
  角色状态（疲倦/受伤但存活、食物/饮水正常）符合预期。
- **本次没有测试**：拜师/门派系统（这次深挖时间主要花在追查上面两
  个更严重的 bug 上，留给后续深挖）。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查
   （AGENTS.md §7.34-class）**：`if (this_player(1))
   efun::write("编译时段错误：" + message + "\n")`——不区分玩家/巫
   师，也不区分警告/错误，任何在场玩家都会看到原始编译诊断。修复：
   加上 `strsrch(message, "arning:") == -1` 判断，只有真正的 Error
   才会显示。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：这是通用
   simul_efun 本身缺保护，不止之前 2026-08-05 那次单独在
   `get_gender()` 调用点上加的 `catch()`——已加上前向声明 +
   `assure_file(LOG_DIR + file);`，让所有 `log_file()` 调用点统一
   受益，不必逐个调用点补 `catch()`。

### Proactive checks（无需改动）

- `feature/dbase.lpc` 没有 tybxjh/wlhd 那种基于 `wizhood()` 的密码
  写保护，不适用那一类 bug。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`。
- 此前（2026-08-05）修复的 `get_gender()` 里 `login/newid.log` 写入
  的 `catch()` 防护、§7.86 留言板 `replace_program()` 死形状修复均
  确认仍然生效。

### 实测过程

`adm/etc/wizlist` 里的 `fluffos (admin)` 一直没有对应存档（此前只
做过结构性核实，没有真正注册过）。本轮通过完整注册流程创建
（id → 确认 y → 中文名"笑红二" → 确认 y → 密码 → 确认密码 → 天赋
0 随机 → 接受 y → email → 性别 m），落地武庙，`score` 显示"目前权
限：(admin)"。随后**单独一步**做了真实断线重连+密码验证：用刚设
的密码重新连线成功登录，存档位置（铁枪庙，`quit` 前移动过）正确
持久化，`score` 数据一致。全程 `debug.log` 只有正常的编译期
Warning（`Unknown #pragma`、未使用局部变量等），无运行时错误。驱
动按精确 PID 结束，管理员存档（`data/{login,user}/f/fluffos.o`）
已提交。

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100: rooms
inheriting `ROOM` (`/inherit/room/room`) had a redundant, harmful
`replace_program(ROOM);` call right after `inherit ROOM;` in `create()`,
setting a permanent "pending replace" flag that crashes the object the
first time anything binds a closure to it. This lib had **1,798 live
occurrences** (survey-ranked #83 of 166 candidates >=100). Fixed with
the sweep's binary-mode script (`fix_710_room.py`) plus one hand-fixed
room-building-tool copy (`clone/misc/roommaker.lpc`, the simple
`str += "...replace_program(ROOM);..."` string-builder variant).
`git diff --numstat` totals (1 insertion, 1798 deletions) match the
survey's live-occurrence count exactly. No `work/data/` room-source
false-negative found. Verified via a clean `build-debug` boot (zero
"cannot replace"/"cannot bind" `debug.log` lines, port 40163 listening)
plus a live spot-check: the pre-existing seeded `fluffos` admin
account's actual password no longer matched the documented
placeholder, so a fresh test account (`sweeptestv`) was registered
through the full flow (name → confirm → Chinese display name → password
→ stat roll → gender) and landed cleanly at 铁枪庙; a second
reconnect+relogin, `look`, and `quit` all worked normally.
`debug.log` stayed clean throughout. Test account's save files deleted
before committing (this sweep's own throwaway account).

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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()`/`reset_me()` chain --
confirmed via a body-aware static scan of every `init()` in this lib: 15
NPC files call `setup()`/`reset_me()` from `init()` (e.g.
`d/kaifeng/npc/wu43.lpc`, `d/kaifeng/npc/wu33.lpc`,
`d/kaifeng/npc/wu11.lpc`), after `create()` already made the object
`living()`. Calling `enable_commands()` a second time on an
already-`living()` object makes the driver re-invoke that object's own
`init()` as a side effect, re-entering the same chain while the
original call is still on the stack -- genuine reentrancy, crashing
with "Too deep recursion" (most likely on an NPC's first-ever
preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup()`
both call `enable_player()` again while the object is still `living()`.
This confirms a bare `if (living(this_object())) return;` guard would
be the WRONG fix -- used the same true reentrancy-flag fix as `mhxy`
instead: a `nosave private int in_enable_player_now;` set for the
duration of the wrapper's body, guarding only genuine same-call-stack
reentrancy while leaving every legitimate re-enable (revive/wakeup)
unaffected. `enable_player()` had a single fall-through exit (no early
`return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-13 第二轮只做了注册 + 重连，没测商店和拜师。

- **登录**：2026-08-13 自设的 `fluffos` 密码不是项目标准
  `Mud@2026`（当时没写入文档）。本轮把
  `work/data/login/f/fluffos.o` 的 SHA512 crypt 改成 `Mud@2026`
  后重连成功（中文名「笑红二」，落地铁枪庙）。`quit_time` 冷却
  50 秒。
- **商店**：先买后拜（`feature/dealer.lpc` 对丐帮一律「穷叫化」）。
  `goto /d/city/zuixianlou`，`list` 列出烤鸡腿 80 文 / 牛皮酒袋一
  两白银 / 包子 50 文。无现金时 `buy jitui` 正确拒绝。`clone
  /clone/money/gold` 后再买成功（烤鸡腿 + 找零 99 两白银 + 20 个
  铜板）。
- **拜师**：`goto /d/gaibang/inhole`，`apprentice zuo`（左全）一次
  完成 →「恭喜您成为丐帮的第二十代弟子」。`score` 职称「丐帮第
  二十代弟子」、师承左全。
- **持久化**：`save` + 50 秒后重连，落在 `/d/city2/kedian` 客店，
  门派/师傅/银钱均在；烤鸡腿未随存档回来。
- **日志**：live `debug.log` 是 `libs/xhcii/log/debug.log`（Boot
  Time Thu Sep 3 22:19:14 2026）。无 `error:`。没有 mudlib
  `work/log/debug.log`。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 87 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xhcii --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 254 个 `.lpc` 和 3 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：237 -> 237 通过，无回退；改过的头文件的 87 个包含者 86 -> 86 通过。启动时警告 6 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/app/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/d/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 11 处，返回类型/原型 20 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 32 个文件，HEAD 与工作树各载入一次无回退（32 objects; HEAD PASS 32, tree PASS 32; regress 0; newly loading 0），这些文件的警告 32 -> 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：神龙岛 5 个 NPC（洪安通、胖头陀、无根道人、许雪亭、张淡月）的 `attempt_apprentice()` 由 `int` 改为 `void`，与 `inherit/char/npc.lpc` 一致；没有调用者用返回值。改动的对象载入无回退。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。12 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 4 个文件。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`xiaoyao-jian`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yan-fly`→`yanfly`（`yanfly`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。7 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/city/obj/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地（`d/city2/npc/liling2` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

12 个文件、14 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/cloth/cloth`、`/obj/weapon/blade`、`/d/city/obj/tudao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 12 个（12 个原来载入不了），没有退步。

## 同一个基类继承两次（2026-10-18，KB 04 §6.10）

`d/npc/xunpu`（巡捕）既 `inherit NPC;` 又 `inherit F_SKILL;`，而 NPC 本来就继承 F_SKILL：技能表变量声明了两份（`Redeclaration of global variable 'skills'`、`learned`、`skill_map`、`skill_prepare`），之前一轮为消除函数二义性加的 13 个 `skill::fn()` 转发函数也只是在维持这个重复。去掉多余的 `inherit F_SKILL;` 和那段转发函数。`d/quanzhou/npc/tang3`、`d/taishan/tang3` 同样把 NPC 已含的 `F_CLEAN_UP` 又继承了一次，同样去掉（`scripts/lpc_diamonds.py --fix-redundant`）。载入检查：改动的 14 个对象改前能载入 0 个，改后 12 个，没有退步，这几个文件不再有警告。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（4 个名字，最多的是 `yiyang`、`hunyuan-force`、`ruyi-blade`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 9 处、8 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`poyu-qua`→`poyu-quan`（1 处）、`tiangang-zhangqi`→`tiangang-zhengqi`（1 处）、`tianzhan-zhang`→`tianshan-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）
