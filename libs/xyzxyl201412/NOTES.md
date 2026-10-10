
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳再现-炎龙20141231——一个更晚、改动更大的夕阳再现构建版本（自定义巫师阶层一路到 (boss)/(ceo)、接受天赋之后多一步 11 项元素亲和力选择、多端口 ZMud/ToMud 选择）。WASM 修复找到并修好了 4 个真正会阻断编译的 bug（本次会话其它夕阳再现家族档案里都没有见过）：（1）adm/daemons/network/dns_master.lpc 有真正的、没有掏空的 socket_create()/socket_bind() 呼叫（和手足档案不同，那些档案里这个文件早就已经是 no-op 桩函式），而且真的会在运行时被 logind.lpc 的 logon() 直接呼叫 DNS_MASTER->query_doing_end()（不只是预加载）——已确认有 29 个外部呼叫者（按 AGENTS.md §7.52 的例外规定属于真正的多用途精灵），所以只掏空了 startup_udp()/send_udp()，加上 send_shutdown() 里遗留的一处 socket_close()，没有掏空整个档案。（2）adm/daemons/network/server_2000.lpc，一个完全自成一体的基于 socket 的文件传输服务器（TCP listen/accept/connect，约 15 处 socket_* 呼叫），只有一个呼叫者（一个仅限巫师使用的 cmds/bos/send_file3.lpc 指令）——整个通过在 adm/etc/preload 里注释掉来禁用，而不是掏空（符合独立精灵的处理模式；档案本身没有改动，因为禁用预加载就已经足够，没有其它代码路径会加载它）。（3）adm/daemons/teamd.lpc 呼叫了一个完全未定义的函式 count(count(v,"*",lvl),"/",max_lvl)（大概本意是想通过某个从未在这份 mudlib 里真正定义过的、基于字符串的运算符分发辅助函式来算出 v*lvl/max_lvl）——这是一个真正的、转档之前就存在的 bug，原生驱动下也一样编译不过，不是 WASM 特有的问题；已改成直接算术运算 'v * lvl / max_lvl'。（4）标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经正确）改成了逐码点的 name[i..i]，另外 master.lpc 的 valid_read()/valid_write() 缺少 'user == this_object()' 短路判断（已加上，和这份档案自己原有的、基于 previous_object() 的局部保护并存）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这份档案自定义的阶层一直到 (admin) 之上的 (boss)/(ceo)——为了和项目标准保持一致，用的是标准的 (admin) 阶层，而不是最高可用阶层）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y（确认新角色）→中文名字→管理员密码+确认→登录密码+确认→天赋菜单（0 随机，y 接受）→元素亲和力选择（0-10，用的 0）→电子邮件→性别（m/f）→进入游戏世界，完整属性表干净。管理员权限已通过'★ 您目前的权限：(admin)'确认。LPC 格式化工具对全部 15146 个档案运行（写入 15015 个，92 个转档之前就存在的未结束字符串/文本块内容错误未做格式化——是这一批里最杂乱的代码库——39 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；6 处 case 标签带尾随注释的命中（ftpd.lpc、master.lpc 两份副本、u/wenwu/securd.lpc、通常那 2 份死代码 bakcmds 副本）全部经 diff 复核干净，其中包括 master.lpc 里一处转档之前就存在的重复 case 标签怪癖（无害，不是格式化工具引入的）。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 101 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。**更正**：
group_note 描述的"管理员密码+确认→登录密码+确认"双密码流程读代码
后确认不准确——实际只有一组密码，但确实比大多数手足档案多一步独
立的"身份标识"（`new_biaoshi`/`confirm_biaoshi`，至少 9 个字符，
和密码分开设置），以及密码之后的元素亲和力选择（0-10）。§8.9 的食
物/饮水判断在这份档案里本来就用的是 `user`（不是 `ob`），不适用
那一类 bug。

### 发现并修复的 PROGRAMMING bug

1. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。
2. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
3. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc`；`d/huashan/npc/refereew.lpc`/
  `referee.lpc` 未用到 `%`，不适用。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。
- **一次性冷启动 eval-cost 耗尽（AGENTS.md §7.90/§10.8-class），发
  生在 `Accepting telnet connections` 之前的开机预加载阶段，和任何
  连线会话无关，未修改**：`Eval interrupted: object
  d/wizard/newer#2 cost limit reached` 发生在驱动 preload 阶段（早
  于开始接受连线），是纯粹的开机首次编译突发，不是本轮任何操作触
  发的。

### 一个额外的登录流程排查记录（非 bug）

**重连一个已存在的 `(admin)` 账号时，`get_id1()` 会先要求一段"巫师
登陆效验码"（`get_wizpas()`），和真正的密码是分开的两步**——这一
步只在 `wiz_level(arg) > 0`（即用一个已经在 `wizlist` 里的 id 重连
已有存档）时触发，新账号首次注册不会经过这条路径。核实代码发现
`get_wizpas()` 里的实际校验被写死成 `if (1 /* crypt(wizpas,
wizpass) == wizpass */)`——真正的效验码比对被注释掉了，任何输入都
会"验证通过"。这是既有代码里已经存在的宽松验证（非本轮引入，也不
是崩溃/功能性 bug，只是一个安全层面的形同虚设），按本项目惯例不在
§10.7 常规测试范围内擅自修改安全逻辑，如实记录。第一次重连测试时
没注意到这一步，把真实密码当成了这一步的输入，导致后续两次真正的
密码提示被错误消费（"您还有一次机会"），第二次重连补上这一步后正
常登录成功。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程（含身份标识、元素亲和力选择）创建，落地
"客栈"，`score` 显示"【天界总管】"头衔。随后**单独一步**做了真实
断线重连+密码验证（含上述"巫师登陆效验码"步骤）：成功登录，存档数
据一致。驱动按精确 PID 结束；管理员存档（`data/{login,user}/f/
fluffos.o` 以及这份档案自己的 `data/key/data/{login,user}/f/
fluffos.key`，同一账号创建流程的正常产物，其余账号的 `.key` 文件
本来就已提交在 git 里）已提交。

## AGENTS.md §7.100 修复（2026-08-19）

同 `xyzxfy2` 同源的 `ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃
地雷（详见 AGENTS.md §7.100）：本 lib 4833 个房间文件的 `create()`
末尾（紧跟 `inherit ROOM;`）都有这一行多余调用，第一次对该房间对象
绑定闭包会永久失败。同款地雷也烤进了自带建房工具两份副本
（`clone/misc/roommaker.lpc`、`u/fyue/misc/roommaker.lpc`）的字符串
拼接代码生成模板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上两份 roommaker 工具模板里各自手动摘除字符串拼接片段。`git diff
--stat`：4835 files changed, 2 insertions(+), 4837 deletions(-)，与
预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40175 正常监听，
`debug.log` 全程干净。管理员 `fluffos`/`Mud@2026` 账号重连（含上文
记录的"巫师登陆效验码"额外一步，任意输入即可通过）成功，`goto` 走
访 14 个刚修复的房间（`d/migong`/`d/tiezhang`/`d/mingjiao`/
`d/new`/`d/tongchi`），13 个正常返回，无 "cannot replace"/"cannot
bind" 新增日志行。走访 `/d/migong/lev12/dong60` 时触发一个与本次修
复无关的既有内容 bug——房内 NPC（`/d/migong/lev12/npc/lev5.lpc`）
的 `create()` 给自己设置了一个从未定义过的技能 "xuantie-sword"，
`feature/skill.lpc` 的 `set_skill()` 抛出 "*F_SKILL: No such skill"
——已确认 `debug.log` 里没有 "cannot replace"/"cannot bind" 相关字
样，属于房间填充时的独立内容问题，不在本次 §7.100 修复范围内，如实
记录未修。按精确 PID 结束驱动；测试期间产生的 `fluffos` 存档增量
（`data/{login,user}/f/fluffos.o`）已 `git checkout --` 还原。

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

## §7.19 enable_player() reentrancy fix (2026-09-01)

Corpus-wide mechanical fix (AGENTS.md §7.19, Batch F of 6), byte-identical
sibling of `longyunmeng`'s `feature/command.lpc`. Originally flagged as a
possible false positive (pre-existing `nosave int enabled = 0;` flag) --
but this is NOT the safe shape: `enabled = 1` is set AFTER
`enable_commands()` returns, not before, so it does not guard the
synchronous reentrant `init()`->`setup()`->`enable_player()` call that
happens DURING `enable_commands()`. Confirmed the reachable chain is real
via the `d/shushan/npc/zhangmen.lpc` family (`init()` unconditionally calls
`me->setup()` -> `enable_player()`). Fixed by adding a true
`in_enable_player_now` reentrancy flag alongside the existing `enabled`
bookkeeping variable (left untouched, `disable_player()` still needs it).
Verified via single-file `lpcc --batch` PASS.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-13 第二轮只做了注册 + 巫师效验码重连，没测商店和
拜师。本轮用既有 `fluffos`/`Mud@2026`（中文名「浮浮」）。

- **登录**：重连仍先走 `get_wizpas()`「巫师登陆效验码」（硬编码
  `if (1 /* crypt... */)`，任意输入通过），再输真正密码。落地
  `/d/city2/kedian` 客店（不是 `/d/city/kedian`）。
- **商店**：客店 `店小二` 不是 vendor。`goto /d/city/zuixianlou`，
  `npc/xiaoer2`（`F_DEALER`）`list` 列出烤鸡腿 80 文 / 牛皮酒袋一
  两白银 / 包子 50 文。身上无现金时 `buy jitui` 正确拒绝「你的钱
  不够」。`clone /clone/money/gold` 后再买成功（烤鸡腿 + 找零 99
  两白银 + 20 文铜板）。
- **拜师**：指令是 `apprentice`（`bai` 同义），不是独立 `bai.lpc`。
  `goto /d/gaibang/inhole` 里是丐帮七袋弟子**左全**（不是黎生；黎
  生在 `underqz`/`underwd`/`underhs`，要过密码门）。`apprentice
  zuo` 一次完成：左全 `recruit` →「恭喜您成为丐帮的第二十零代弟
  子」（`chinese_number(20)` 的既有写法）。`score` 称谓「丐帮第
  二十零代弟子」、师傅「左全」。左全只收男性，无经验门槛。
- **持久化**：`save` + `quit` 后重连，仍在树洞内部，称谓/师傅/
  烤鸡腿/银钱均在。
- **日志**：live `debug.log` 是 `libs/xyzxyl201412/log/debug.log`
  （Boot Time Thu Sep 3 21:30:48 2026）。无 `error:`。mudlib
  `error_handler()` 写 `work/log/debug.log`，本轮 mtime 仍是
  2026-08-19（无新捕获运行时错误）。`work/log/log` 里的
  `teamd.lpc` `count()` 报错是旧编译残留；现行 `teamd.lpc` 已是
  `v * lvl / max_lvl`（WASM 阶段修过）。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- `message_combatd(msg, me, you)` is called by 9 file(s) (the perform files) and defined nowhere in this archive (a simul_efun of the original server): 8 of them did not compile (`Undefined function message_combatd`). `adm/simul_efun/message.lpc` now has `varargs void message_combatd(string msg, object me, object you, mixed extra)` calling `message_vision()`, placed after `message_vision`'s definition (KB 04 §6.2). All callers compile.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xyzxyl201412`: 6 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 10 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 4 PASS -> 10 PASS, 0 that loaded before fail now, 6 more load.

6 files moved (6 `.C`); mostly under `d/feitian/ximen.C` (1), `d/japan/path1.C` (1), `d/japan/senlin1.C` (1), `d/japan/senlin2.C` (1). A rescan with `scripts/lpc_warnings.py xyzxyl201412` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `adm/daemons/questd.lpc` 在新进程里加载，HEAD 通过 1 个、工作树通过 1 个（共 1 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xyzxyl201412 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/tiezhang` 三个房间删去 `return` 后面的 `"\n";`，`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);` 等），共改动 772 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：744 -> 744 通过，无回退；改过的头文件的 37 个包含者 37 -> 37 通过。手工：`adm/daemons/story/new7.lpc` 里只剩注释的 `if (ob) { }` 去掉，注释留着。`adm/daemons/cruised.lpc` 是编译不过的漫游守护进程草稿，未动。

启动时警告 41 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、1 处去后缀（如 `cmds/app/ls3.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/u/snow/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。
