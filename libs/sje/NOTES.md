
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 sjecl 同一个 Century/adm-single 血统（adm/single/master.lpc + adm/daemons/securityd.lpc）——大部分 bug 相同，用了相同的修法：（1）§7.60 master.lpc log_error()/standard_trace()→CHANNEL_D 编译期崩溃，两处都用 find_object(CHANNEL_D) 守卫。（2）§7.59 securityd.lpc 的 valid_read() 无条件用 this_player() 覆盖，拒绝了 load_object/include 触发的读取，已把这两种情形排除在覆盖之外。（3）§8.1 没减半的 GBK 字节区间 is_chinese() 加上对应没减半的 check_legal_name() 长度界限（原为 4/8 加 i%2 字节窗口→改成逐码点的 2/4）。（4）§7.50 is_killing(who) 物件/字符串不匹配，出现在和 sjecl 相同的 5 个 NPC 对话档案里（少了 sjecl 里少林那份，这份快照没有）。这份档案独有的新发现：adm/daemons/backupd.lpc 用了未定义的 BACKUP_DIR 常量（会被预载，导致开机失败）——已在 globals.h 里加上 #define BACKUP_DIR "/backup/"（硬盘上已经有一个 /backup 目录，确认了原意）。另外：adm/daemons/sited.lpc 的 is_valid() 比 sjecl 的规则更严格/相反——任何非巫师身份的 id 从 127.0.0.1/localhost 连线一律无条件拒绝（只有 wiz_level(id) 为真的账号才能用回环地址），所以 WASM 测试（永远是 127.0.0.1）只能注册巫师身份的 id——已改用先播种 wizlist 再直接以 fluffos 身份注册（一次性验证管理员和注册流程）来绕过，而不是当作需要修的问题（这是这条血统真实的安全策略选择，不是 bug）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这里不需要像 sjecl 那样再加第二条 sited 表条目，因为 127.0.0.1 规则本来就给巫师身份账号开放了完整的回环访问权限）。已验证：完整注册→进入游戏世界，权限正确显示 (admin)。记录了一处不阻断、未修的内容 bug：adm/daemons/questd.lpc 的 spread_quest()/init_dynamic_quest() 在预载的动态任务放置阶段对一个为 0 的物件呼叫 environment()（被捕获，不阻断开机）。LPC 格式化工具对全部 8527 个档案运行；还原了 1 个通过"去空格后比对旧档案"扫描（覆盖 85 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案（d/quanzhen/hudi5.lpc）；直接逐一比对了两个 ASCII 地图档案（d/shaolin 下两份）——干净，只是排版调整。格式化后重新验证过，干净。

## 深度功能测试（§10.7，2026-08-05）

这份档案和刚深挖过的手足档案 `sjecl` 同一血统，先检查了 `sjecl` 自
己的 §10.7 记录（§8.3b 指令表死档、§7.86 留言板 `post` 崩溃、
§7.5 file_size ACL 误判等），逐项核实：

- **§8.3b 不适用**：`sjecl` 的 `commandd.lpc` 有一个转档没跟上的
  `sscanf(...,"%s.c$",...)`（永远匹配不到 `.lpc` 后缀）；这份档案
  的 `commandd.lpc`（以及一份从未被引用的死代码分身
  `adm/commandd.lpc`）从一开始就正确写成 `"%s.lpc"`，指令表健康，
  `look`/`score` 等全部指令都正常。
- **§7.86 适用，而且发现了一个更隐蔽的变体**：全档案 38 处
  `inherit BULLETIN_BOARD` + 多余 `replace_program(BULLETIN_BOARD)`
  致命形状，已删除 37 处静态留言板文件里的多余调用。**第 38
  处不是静态文件，而是 `cmds/king/set_board.lpc`——一个供帮派帮主
  在自己领地里"花一千两黄金建一块留言板"的指令**，它的实现方式是
  在运行时用字符串拼接生成一份全新的 `.lpc` 源码（`write_file()`
  写到磁盘上），拼接出来的模板里同样嵌了一份"先 `inherit
  BULLETIN_BOARD` 又多余 `replace_program`"的写法——也就是说，这
  个 bug 不只存在于已经存档的静态留言板里，而是被写进了"生成新留
  言板"的工厂函数本身，任何帮派以后用这个指令新建的留言板都会天生
  自带这个 `post` 必崩的 bug。已从模板字符串里删掉多余的
  `replace_program` 那一行，保留 `inherit`。这次深挖没有实际测试
  帮派建板流程（需要先加入帮派、攒够一千两黄金），但已经用代码走
  读确认修改后生成的模板语法完整（大括号配对正确）。已更新
  AGENTS.md §7.86，补充"运行时代码生成模板也可能嵌有这个 bug，不
  要只 grep 静态 .lpc 文件"这条提醒。
- **§7.5/§8.9 均不适用**：`securd`/`securityd` 的 ACL 已经在
  WASM 阶段修好（排除了 load_object/include），这次没有再撞上
  file_size 误判；`enter_world()` 的食物/饮水初始化同样是无条件的
  固定值，没有年龄判断包装。
- **战斗/死亡/复活测试**：新角色被"武馆四弟子 孙均"拦在武馆大门
  口（"江湖险恶，你还是在武馆学点东西再出去吧"——需要馆主批准才能
  "离馆"，是有意的新手教程设计，不是 bug），用管理员的 `goto` 指
  令直接跳到城里测试。先在武馆里和"沈城"打了一场安全的切磋（无生
  命危险，礼貌收场），再在北大街和"少林刀僧 行者"打了一场真实的死
  斗，逃跑被拦截，力竭阵亡。这份档案的死亡系统和 `sjecl` 完全不
  同——不是"鬼门关→孟婆亭→孟婆汤"，而是"鬼门关→阎罗大殿→黑白无常/
  秦广王审判"，判定守卫是标准的 `if (!ob || !present(ob))
  return;`（AGENTS.md §7.68，现已收窄到仅 `bmxkx2001` 适用），全
  程未受打扰、未做任何改动，五阶段对话正常播放完毕，正确送回"武馆
  前院"复活，`score` 确认死亡计数 +1。
- 留言板 `post` 已 live 验证：在武馆前院的"襄阳武馆留言板"发帖成
  功，"留言完毕"。
- **本次没有测试**：帮派建板流程（原因见上）、门派拜师、商店。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,004 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug。
本档案就是 §7.100 条目本身引用的"`sje`-precedent"（bug 长在工厂
里，不只是出货内容里）：不只 `clone/misc/roommaker.lpc` 一份房间
建造工具，帮派管理指令集 `cmds/minister/*.lpc`（`accept`、`ally`、
`resign`、`banish`、`declare`、`linkroom`、`mkroom`（2 处）、
`addnpc`（2 处）、`add_action`、`add_desc`、`set_long`、
`set_short`）、`cmds/king/build_bank.lpc`（2 处）、`cmds/adm/
ra.lpc` 也全部把这个 bug 烤进了各自的房间字符串拼接模板里——一共
14 个文件、18 处字符串拼接变体。用 `fix_710_room.py` 扫过
`work/`，删除 1,976 处标准形状；`work/data/group/groom/` 下 10 个
真实 `.lpc` 房间源文件（帮派废墟场景，`inherit ROOM;` 独立标准形
状，被脚本默认的 `data/` 排除规则跳过）另外单独用同一脚本对该子
目录扫过，删除 10 处；上述 18 处字符串拼接变体用一个小 Python 脚
本（二进制模式，逐文件计数校验）批量替换成
`str += "\n\tsetup();\n}\n";`。1976+10+18=2004，与survey记录的
存活总数完全吻合；`git diff --stat` 显示 1998 个文件净删 2004
行、增 18 行，同样吻合。`work/data/group/npc`、`work/data/group/
obj` 下确认没有真实命中。

驱动干净启动（零新增编译错误、端口 40146 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。本档案此前从未被真实注
册过（只有 wizlist 里的 `fluffos (admin)` 条目，没有存档）——用完
整注册流程（UTF-8 编码：BIG5 询问答 N、id、密码 `Mud2026A`、中文
名"秦风"、天赋 0 随机+接受、邮箱、性别 m）创建，落地"门廊"，
`look`/`score`/`quit` 均正常，全程 `debug.log` 保持干净。新建的
管理员存档（`data/{login,user}/f/fluffos.o`）已提交，补全此前
NOTES.md 记录过、但从未真正落地的管理员播种。驱动按精确 PID 结
束。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/yanluo.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/gb/npc/xixia-wushi.lpc`
redundantly calls `setup()` again from inside its own `init()` (on top
of the `setup()` its `create()` already made) -- same shape as the
originally-documented mhxy `zhangmen.lpc` case. `enable_commands()` is
only safe to call from `create()`: calling it again on an object
already `living()` makes the driver re-invoke that same object's
`init()` as a side effect, which recurses back into `enable_player()`
on the same call stack until "Too deep recursion" aborts the boot on
a room's first-ever visit. Fixed with a true reentrancy flag
(`in_enable_player_now`), NOT a `living()` guard (which would break
legitimate re-enables from `revive()` in `feature/damage.lpc` and
`wakeup()`/`wakeup2()` in `cmds/std/sleep.lpc`, both confirmed to
re-invoke `enable_player()` on this lib while the object is still
`living()`). Verified via `lpcc --batch` single-file compile check
(PASS). Part of the corpus-wide §7.19 sweep (Batch E).

## 深度功能测试第三轮 / §10.7 round three (2026-09-03)

新角度：2026-08-05 那一轮测过指令表、留言板 `post`、武馆切磋、北大街
死斗和鬼门关→阎罗审判复活。当时写明没测的是门派拜师和商店。本轮只
补这两条，不重打死亡。管理员仍是 `fluffos` / `Mud2026A`（中文名秦风，
UTF-8：BIG5 询问答 `N`）。端口 40146。回环只放行巫师，本号是 admin。

### 实测过程

- 落地武馆门廊 `/d/wuguan/menlang`，孙均新手讲解还在。`goto
  /d/city/dangpu` 到当铺，老板黄（`lao ban`）。
- `list` 要分类（`armor|weapon|drug|book|misc`）。空武器列表只印标题
  「你可以向当铺老板购买下列武器：」，不崩。
- `clone /clone/weapon/changjian` 后 `value changjian` = 10 银 50 文；
  `sell` 成交，「讨价还价」升 1。再 `list weapon` 显示库存长剑单价
  十八两白银。身上只有卖剑所得 10 银 50 文时 `buy` 回「穷光蛋，一边
  呆着去！」——当铺加价，不是 bug。再 `clone` 一两黄金后
  `buy changjian` 成交：「你从当铺老板那里买下了一柄长剑。」
- 拜师：`clone /kungfu/class/kunlun/jiangtao`（蒋涛几乎无门槛），
  `bai jiang` →「好吧，我就收下你」→ 昆仑派第六代弟子。`score` 师承
  【昆仑派】【蒋涛】。quit 后重连称号和师承都还在。
- 帮派建板仍未测（仍要先入帮、攒一千两黄金）。

### 发现并修复的 PROGRAMMING bug

**`log_file()` 不 `assure_file()`（AGENTS.md §7.11，和 `ldtx` 同一
Century/`adm-single` 形状）**：`adm/simul_efun/file.lpc` 的
`log_file()` 是裸 `write_file(LOG_DIR + file)`，同文件里已经有
`assure_file()` 却没用。`log/nosave/` 被 gitignore，全新/干净树上不
存在。巫师 `clone` 在物件已经复制成功之后去写
`log_file("nosave/CLONE_OBJ")`，抛

```
*Wrong permissions for opening file /log/nosave/CLONE_OBJ for append.
"No such file or directory"
```

栈在 `file.lpc` / `simul_efun.lpc` 第 8 行。`clone` 本身成功，但每
次都对巫师刷执行时段错误。`securityd` 晋升日志和 `valid_write` 拒绝
日志（`log_file("FILES")`）是同一条路。

修复：前向声明 + `assure_file(LOG_DIR + file)`，并加
`nosave int in_log_file` 重入守卫（`securityd` 拒绝写入也会
`log_file("FILES")`，避免再走一遍 `file_size`/`mkdir`；同 fqyy2
2026-09-03）。CRLF 按二进制保留。复测：`clone` 零条权限错误，
`work/log/nosave/CLONE_OBJ` 被自动建出并写下审计行。冷启动无
“Too deep recursion”。

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- 管理员存档 `work/data/{login,user}/f/fluffos.o`（本轮后状态，含昆仑派）

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 9 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 9 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (2 with the terminator glued to the last text line, 1 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`, `d/shaolin/hgaungz5.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 2241 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 216 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK；全库 8363 个对象 HEAD 对工作树的加载检查：8216 -> 8235，新增 19 个可加载，无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理；网页版只有巫师能登录

`scripts/lpc_warnings.py sje --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/tiezhang` 三个房间删去 `return` 后面的 `"\n";`），共改动 489 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：460 -> 460 通过，无回退；改过的头文件的 122 个包含者 121 -> 121 通过。
手工：
- `kungfu/class/shaolin/xuan-du.lpc`（玄度）：`("chat_msg_combat", ({ ... }));` 少了 `set`，只是一个括号表达式，战斗中从不出招；补上 `set`。
- `adm/daemons/sited.lpc` `is_valid()`：从 127.0.0.1/localhost 来的连线只放巫师身份的 id。上面"WASM 修复摘要"当时把这看作这条血统的安全策略、改用播种巫师账号来测；但网页版每个玩家都从 127.0.0.1 连进来（KB 01 §1.3），结果网页上任何玩家 id（包括新注册）都会被"这个英文名字不能从当前地址登录"挡住，`playable` 名不副实。按 KB 01 §1.3(b) 的标准做法改为回环地址一律放行（本机原生运行时回环地址只能是机器自己）。新进程里用新名字登录已能进入注册流程。
- 未动：`d/quanzhen/hudi5.lpc` 第 10 行编码损坏，HEAD 起就编译不过。

启动时警告 62 -> 0。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 2 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 2 -> 0。

- 2026-10-12：`job/gbjob/teamjob.lpc` 的组队任务用 `names[0][random(40)]` 选地点，而这张表只有 29 个地名，`random()` 落到表外时数组越界报错、任务中断。改成 `random(sizeof(names[0]))`（shenmo `u/stey/newjob/teamjob.lpc` 同类）。HEAD 与工作树各载入一次，regress 0。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 5 处多余继承，其余手工，能编译的文件警告清零；改动的 17 个对象在 HEAD 与工作树各载入一次：HEAD PASS 15，tree PASS 15，regress 0。

- 少林武僧 `kungfu/class/shaolin/wuseng.h`（`wuseng2/4/5.lpc` 包含）把可学武功表叫 `skills`，与 `F_SKILL` 存武功等级的 `mapping skills` 同名；文件里照抄 `F_SKILL` 的 `add_skill()` 本该改基类那份，实际改的是这张表：第一次有人教武僧就 `skills = ([])` 把表清空，之后再问学什么 `skills[0][i]` 就取空表。表改名 `skill_ids`，`add_skill()` 才真正记到武僧的武功上。
- 慕容复 `d/mr/npc/murong-fu.lpc`、`d/mr1/npc/murong-fu.lpc` 的偷学目标 `mapping skills = skills[random(sizeof(skills))];` 用同名局部变量去读 `skill.h` 的表；表改名 `steal_skills`，这行改成读 `steal_skills`。
- `kungfu/skill/kurong-changong.lpc` 的穴位表 `xue_name` 与它包含的 `eff_msg.h` 一字不差，删去重复的；`kungfu/skill/lanhua-shou/fuxue.lpc` 的穴位表不同，改名 `fuxue_xue_name`。
- `job/gbjob/teamjob.lpc` 的地名表 `names` 与同被 `ysd.lpc` 包含的 `zzzjob.lpc` 同名，改名 `team_names`；天书任务 `quest/shenshu/npc/man.lpc`、`testman.lpc` 的 `kill_ob()` 改 `void`；`d/xiangyang/npc/shanzei0.lpc` 的 `MAX` 先 `#undef`；`kungfu/skill/jinshe-zhuifa/sheying.lpc` 写明用驱动原先选的 `clean_up()`。
- 2026-10-14：`data/emoted.o`（表情守护进程的存档）整个还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string while restoring emote`，表情守护进程启动时一个表情都没有。现按 GB18030 转码，丢掉原文件里几个被截断的半个字符。转码后 `adm/daemons/emoted` 载入不再报错（HEAD 上报错）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。7 个文件 7 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/skill/jieshou-jiushi/foguang.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/1zhen.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/effect.lpc`（`p *=`）、`/kungfu/skill/taiji-quan/luanhuan.lpc`（`p *=`）、`/kungfu/skill/taiji-quan/zhen.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：`d/dali/job/killer1.lpc`（被 `npc1.lpc` #include 的大理送信任务杀手）`init()` 缺了收尾的 `}`，后面的函数全被读成 `init()` 里的局部声明，`npc1` 整份不编译；补上后载入，顺手删去两个没用的局部变量。

- 2026-10-14：2 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14：3 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；2 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：5 个对象，新增载入 5，回退 0。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。14 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 3 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 2 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，4 处补上 `if (!mapp(fam)) fam = ([ ]);`。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，2 处改为 `add(type, -N)`。

## 化骨绵掌毒不能编译（2026-10-15）

`kungfu/condition/huagu_poison.lpc` 原档就多一个右括号（`qi = me->query("max_qi"))-1;`），文件从未编译成功，中了化骨绵掌的人没有毒发。按原意改为 `qi = me->query("max_qi") - 1;`，现可载入。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。12 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`jinshemiji`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`longxiang-boruo` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`huanxi_chan`→`huanxi-chan`（`longxiang-boruo/yinyang`）；`jinshe-zhang`→`jinshe-zhangfa`（`jinshe-jianfa/kuangwu`）；`tianang-zhengqi`→`tiangang-zhengqi`（`tiangang-zhengqi/heal`）；`tiangang-zhenqi`→`tiangang-zhengqi`（`tiangang-jian`）；`xixing-dafa`→`xixin-dafa`（`qiantian-yiyang`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）。

## 文件首行注释少了一个斜杠（2026-10-15）

首行的说明注释只剩一个 `/`（如 `/kuangwu.c金蛇狂舞`、`/ cloth.txt  //`），文件第一行就语法错误、编译失败：全真教的布衣 `/d/quanzhen/obj/cloth`、`/d/quanzhen/npc/obj/cloth` 因此从来载入不了。补回斜杠成为 `//` 注释，现在都能载入。

## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## 嵩山剑「飞舞」的掌法追击报错（2026-10-15，KB 06 §7.246）

检查并存下兵器的那段被注释掉了（不再要求持剑），后面寒冰神掌、嵩阳手追击时的 `weapon->unequip()`、`weapon->wield()` 用的是从未赋值的 `weapon`，内力扣完后报错。改为当场取兵器，没拿兵器就不卸不装。


## 玄虚刀法「乱环诀」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

10 个文件、11 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/weapon/gangdao`、`/u/qingyun/mingjiao/obj/shenghuo-ling`、`/u/qingyun/mingjiao/obj/yel-cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 10 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 1 个，改后 8 个，没有退步。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_VENDOR_SALE` → `/feature/vendor_sale`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：1 个里 1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 27 个对象设了本库没有文件的武功（19 个名字，最多的是 `zhong-qiang`、`kuang-jian`、`qimen-baguazhen`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：27 个里 25 个通过，其余 2 个停在别的错误上（`clone/gem/zhang`：*No program in object '/clone/gem/zhang'!；`kungfu/class/xiake/master`：*No program in object '/kungfu/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/city/dayuan` 的 `south`：`guanmen` → `caizhu`；`/d/fuzhou/nanmen` 的 `south`：`birdge` → `bridge`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/feature/quest`（宏 `F_QUEST`）←xkxc98sj，2 个对象继承它，抽样 1/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 40 处、40 个文件：`shaolin-shnfa`→`shaolin-shenfa`（22 处）、`kunlun-shnfa`→`kunlun-shenfa`（15 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## guo.lpc 的引号丢了（2026-10-19，KB 06 §7.266）

`d/xiangyang/npc/guo.lpc`（郭靖）第 240 行 `(me->query("family/family_name") == "丐帮)&&(query("gbjob")>1)` 的收尾引号丢了（GBK 转 UTF-8 时被 `丐帮` 后面的字节吃掉），后面的汉字被当成代码，驱动报 `Illegal character 0xe6`。补回 `"`：`"丐帮")`。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/city/dayuan.lpc` 的 `north` 出口：`dayuan2` → `houyuan`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/gb/npc/nanmin.lpc` 的 `#include "/u/explorer/gb/npc/dest1.h"` 改成 `/d/gb/npc/dest1.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/gems/ring`（宏 `S_RING`）←hy2002：11/11 个继承它的对象载入
- `/inherit/weapon/weapon`（宏 `M_WEAPON`）←shujian3：1/2 个继承它的对象载入
- `feature/gems.lpc` 是个 56 行的精简版，没有宝石戒指基类要调用的 `set_ring_desc()`、`set_weapon_desc()`、`set_armor_desc()`：从 hy2002 的同名文件补回这三个函数（`scripts/lpc_transplant_function.py`）；戒指基类的 `init_sockets(object me)` 在没有人在场时（房间刷新里的 `this_player()` 是 0）对 0 调 `query()`，开头加 `if (!objectp(me)) me = this_object();`（旧驱动里 `0->query()` 就是 0）。
- 玩家打造兵器的模板（1 个文件）这回有了基类，照 KB 06 §7.275 加上没有打造者时的保护（`scripts/lpc_fix_forge_template.py`）。

逐个与 HEAD 对比载入，没有退步。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：4 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 5 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/quanzhen/hudi3.lpc`（ldtx）、`/d/quanzhen/hudi4.lpc`（hy3）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/d/quanzhen/xiuxishi2.lpc`（bixiecanyang）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/d/city/zhengmen2.lpc`（2 个）。修后与 HEAD 逐个对比载入：这 5 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/clone/npc/luohantang-shouzuo.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西都会吃掉鱼油。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/food/yuyou.lpc`（4 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 12 处）。改动：`/cmds/usr/bet.lpc`（1 处）、`/d/mr/npc/robber.lpc`（1 处）、`/d/sld/npc/stt.lpc`（1 处）、`/d/sld/sanpo7.lpc`（1 处）、`/kungfu/class/mingjiao/zhangwuji.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 任务守护进程启动时崩溃（2026-10-20，KB 06 §7.303）

`adm/daemons/questd.lpc` 的 `spread_quest()` 在启动时找不到合格的活物（新树里还没有活物），`target` 仍是 0，`environment(target)` 报 `Bad argument 1 to environment()`（启动时 42 次）。加了 `if (!target) return 0;`。

## `zhaohuan`、`scoreold`、`group` 三个指令（2026-10-20，KB 04 §6.25，KB 06 §7.263）

- `cmds/usr/zhaohuan.lpc`：第一行开头多了终端粘贴来的颜色码文字 `[0; 1; 34 m[1 m[0 m  `（ESC 字节丢了），`syntax error, unexpected '['`。去掉以后露出第二层：文件最后 17 行的分号和花括号都丢了，语句连在一起（`weapon->move(ob) if (!i) weapon->wield() i = 1`、`HEL`、`zhaohua`）。照本文件前面两个完整的武器段（sword、blade）和 hymud 的同名文件，把 whip、hammer、staff、axe 四段、`ob->change_combat_mode(me, ob->query("combat_mode"));`、`return ob;` 和 `help()` 重建（hymud 的版本多一个 throwing 段，sje 原来没有，没有加）。
- `cmds/usr/scoreold.lpc`：`sprintf(... "上次遇害：%s%s" ..., 值)` 格式要两个参数，只给了一个（`(s)printf(): More arguments specified than passed`）。补上上一行算好的 `color`，和同目录 `score.lpc` 里这一行的写法一致。
- `cmds/usr/group.lpc`：对 `/open/` 下每个目录 `load_object(dir + "/kingdom")` 再 `->query("king")`；`/open/freeze_list`、`/open/topten` 不是帮派（没有 kingdom 文件），`call_other` 对 0 报错。先测 `file_size(kingdom_file + ".lpc") <= 0`，是就 `continue`。

实测（sje 的全新树，机器人登录）：`group` 打出表头和分隔线（没有帮派），`scoreold` 打出个人资料，`zhaohuan` 答“凭你现在的条件，还没有资格拥有随从呢！”，控制台没有错误；加载检查 2/2，回归 0。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/minister/accept.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/adm/daemons/taskd.lpc`、`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## 天龙寺宝殿 `do_ketou()`：`me` 在赋值之前就被用来初始化 `i`（2026-10-21，KB 06 §7.346）

`object me; int i = me->query_skill("buddhism", 1); ... me = this_player();`：磕头一律抛错。`object me = this_player();` 提到前面，去掉后面那句。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 14 条注册（11 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/dali/wuliang/anbian.lpc`（`do_tiao`）、`/d/dali/wuliang/muwu1.lpc`（`do_tiao`）、`/d/dali/wuliang/yubi.lpc`（`do_jump`）、`/d/huashan/jinshe/obj/haigu.lpc`（`do_move`）、`/d/huashan/jinshe/obj/tiexia.lpc`（`do_move`）、`/d/huashan/npc/yaba.lpc`（`do_follow`、`do_kill`）、`/d/mr/shuichi.lpc`（`do_strike`）、`/d/mr1/shuichi.lpc`（`do_strike`）、`/d/sld/npc/obj/yaolu.lpc`（`do_look`）、`/d/wudang/xiaolu4.lpc`（`do_ci`） 等共 11 个文件。最多的函数名：`do_strike` 4 处、`do_tiao` 2 处、`do_move` 2 处、`do_jump` 1 处、`do_follow` 1 处。没有动（读过）：`/d/city/npc/obj/h_cloth.lpc` 的 `do_log`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/city/npc/obj/h_cloth.lpc` 的 `do_shutdown`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/city/npc/obj/h_cloth.lpc` 的 `do_goto`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/city/npc/obj/h_cloth.lpc` 的 `do_more`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/huanghe/npc/mafu.lpc` 的 `do_rideyz`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/huanghe/npc/mafu.lpc` 的 `do_ridelz`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。9 个文件里 13 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 9 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 9 个，现在 9 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/fuzhou/houyuan.lpc`:`look_tai`。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/quanzhen_b`；`/d/quanzhen/sanqingdian.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"tai": (: look_tai :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 51 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；改名官 `zhuce` 的长度检查按字节算，合法的名字一个也过不了。

本库 51 处（30 个文件）：拼名字的赋值 24 处、与汉字常量比较 17 处、改名官的长度检查 7 处、对切片赋值 2 处、两个名字切片互比 1 处。例：`name[0..1]` → `name[0..0]`（`/d/dali/dlhg/npc/duanzm.lpc:182`）；`name[2..3]` → `name[1..1]`（`/d/mr/npc/murong-bo.lpc:86`）；`old_name[0..3]` → `old_name[0..1]`（`/d/thd/npc/yaoshi.lpc:278`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。
