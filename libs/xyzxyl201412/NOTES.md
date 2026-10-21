
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

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 29 处，返回类型/原型 36 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 3 个文件；改动 64 个文件，HEAD 与工作树各载入一次无回退（64 objects; HEAD PASS 64, tree PASS 64; regress 0; newly loading 0），这些文件的警告 68 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `adm/daemons/cruised.lpc`：五处只剩注释的 `if (cruise[USER_ID]) { }` 挪进注释（与 longyunmeng 同，行为不变）。载入无回退。

## 编译警告收尾（2026-10-12）

孪生库 longyunmeng 同日的整理（116cf276f5b：27 个物品 `query_autoload` 的返回类型，`cmds/std/look_wiz.lpc` 前一份从没显示过的 `per_msg_beast3`，`d/miwudao/secret/npc/` 三个 NPC 的 `die()` 改 `void`，`huashan-jian.lpc` 多余的 `;`）用 `scripts/lpc_twin_port.py adopt longyunmeng xyzxyl201412 --pre 116cf276f5b~1` 搬来，32 个文件与 longyunmeng 修前逐 token 相同；另 `u/fyue/ansi2.h` 的 `BEEP` 前加 `#undef`。HEAD 与工作树各载入一次：32 个对象，HEAD PASS 28，tree PASS 28，regress 0。
- 2026-10-14：技能文件 `int power_point()`/`hard_point()` 返回浮点被截断；本库没有调用者，改成 `float`，保留原数值。
- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）的另外 9 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的 11 个对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。17 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。7 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 9 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 17 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`dagou-bang`。

## 飞雪的兵器销毁（2026-10-15，绝招探测）

`liangyi-jian/feixue.lpc` 末尾的 `else destruct(obj);` 在前一分支已销毁兵器时对 0 调用，改为 `else if (objectp(obj))`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`daya-jian/badao`、`murong-jianfa/kuangjian`、`wenrou-jian/xuanyuan`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`/d/quanzhen_old/kungfu/skill/xiantian-qigong`、`wangran-xinfa`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

4 个文件、4 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/miwudao/secret/npc/obj/cloth`、`/d/baituo/obj/shezhang`、`/d/kunlun/obj/jwqin.lpc`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 3 个（2 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 自制兵器的 id：名字按字节数拆（2026-10-18，KB 07 §8.1）

`feature/item_make` 的 `get_item_id()` 把自制物品的名字拆成一个或两个两字词，再到 `name_id_arg` 里查拼音（「失神」→ `shishen`）。原来按 GBK 字节数拆（`[0..3]`、`len > 4`），UTF-8 里一个汉字只占一个下标：四个字的名字 `[0..3]` 取走整个名字，表里查不到，id 只剩下 ` sword`（空的名字部分），玩家无法用名字指到自己做的兵器。改为按字符数拆（`[0..1]`、`[2..len-1]`、`len > 2`）：「失神炽日」得 `shishen zhiri sword`。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 16 个对象设了本库没有文件的武功（15 个名字，最多的是 `xuantie-sword`、`kwan-yin-spells`、`wudang-array`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：16 个里 15 个通过，其余 1 个停在别的错误上（`quest/menpai/jobnpc/gumu`：*Bad argument 1 to EFUN call_other()）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 49 处、47 个文件：`kunlun-shnfa`→`kunlun-shenfa`（14 处）、`shaolin-shnfa`→`shaolin-shenfa`（12 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`yunv-xinjing`→`yunu-xinjing`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）等共 17 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 3 个 NPC 文件、3 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 2 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/quanzhen_old/obj/greenrobe.lpc`、`/d/quanzhen_old/obj/greyrobe.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen_old/npc/obj/m_sword.lpc`（共 4 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## userp(0)（2026-10-19，KB 06 §7.277）

`adm/simul_efun/player.lpc` 的 `userp(object ob)` 先调 `efun::userp(ob)`，没有人在场时（房间刷新里 NPC 穿会员衣服，`wear()` 里 `userp(this_player())`）`ob` 是 0，驱动报 `Bad argument 1 to userp()  Expected: object  Got: 0`，NPC 和房间载入不了。函数开头加 `if (!objectp(ob)) return 0;`（旧驱动里 `userp(0)` 就是 0）。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。一行文字在逗号前丢了结尾的引号（下一行是同一个表的下一项），补上：`/kungfu/skill/kunlun-zhang.lpc`。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/xuehepai/obj/bairiwan.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 11 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/hainan/npc/xianhe.lpc`、`/d/hainan/npc/xiaohe.lpc`、`/d/shushan/shanjian.lpc`）。改动：`/d/hainan/npc/xianhe.lpc`（3 处）、`/d/hainan/npc/xiaohe.lpc`（3 处）、`/d/shushan/shanjian.lpc`（2 处）、`/kungfu/skill/yansha-quan/heilongbo.lpc`（3 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/network/fileserver.lpc`（1 处）、`/adm/daemons/network/server.lpc`（1 处）、`/adm/daemons/network/server_bf.lpc`（1 处）。

## `partyinfo` 读不到 `/log/cmds/party` 就抛错（2026-10-20，KB 06 §7.326）

`cmds/std/partyinfo.lpc` 把 `read_file("/log/cmds/party")` 直接交给 `explode()`。这个文件是运行中的 mud 才会写出来的帮会日志，克隆出来的目录、站点和全新启动的树里没有，`read_file()` 答 0，于是 `Bad argument 1 to explode()`。现在读不到时按空表处理，只打印表头。同一份文件在 ylfyxa3、xajh4gkb 里已先改过（那里有实测）；这里只做了加载检查（1/1，回归 0）。`u/wenwu/partyinfo.lpc` 是巫师目录里的同名副本，没有碰。

## `passwd`、`jiadian`、`abandon`：`md5crypt()` 不存在（2026-10-21，KB 06 §7.323）

三个命令用 `crypt(pass, old) != old && md5crypt(pass, old) != old` 验旧密码（旧驱动里存档可能是 DES 也可能是 MD5，两种都要认）。这个驱动没有 `md5crypt` efun，`adm/simul_efun/config.lpc` 的 `crypt()` 包装器只在定义了 `MD5_CRYPT` 时才用 `efun::md5crypt`（没有定义），所以三个命令都是 `Undefined function md5crypt`：玩家改不了密码，`abandon` 和 `jiadian` 也打不开。在 `config.lpc` 补 `string md5crypt(string str, string seed) { return efun::crypt(str, seed); }`（这个驱动的 `crypt()` 自己认 `$1$` 盐）。加载检查：HEAD 1、树 4，三个命令新加载。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`、`/inherit/char/npc_bf.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 3 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（3 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dallowip.lpc`（`find_player`）、`/cmds/adm/dbiaoshi-md5.lpc`（`find_player`）、`/cmds/adm/dbiaoshi.lpc`（`find_player`）。加载检查 HEAD 与工作树对照，没有退步。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/bos/socket2.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## `findfile`、`updir`：不带参数（2026-10-21，KB 06 §7.336）

ToMud 升级用的两条指令（`cmds/bos/findfile.lpc`、`updir.lpc`）不带参数时报 `Bad argument 1 to sscanf() Expected: string Got: 0.`：`findfile` 的 `sscanf(arg, "%s,%s", dir, str)` 前面是一段注释掉的代码，`updir` 的 `sscanf(arg, "%s -debug", arg)` 在 `if (playerp(previous_object()))` 里面。`findfile` 补了 `if (!arg) return help(me);`（`help()` 在 `main()` 之后，补了原型），`updir` 在开头 `if (!arg) arg = "";`，不带参数就列出当前目录。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。
