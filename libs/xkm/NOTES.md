
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和金庸梦（jym，147）同一血统/同一套 simul_efun 组成——用同样的方式重新实现了 efun::tail()（§6.2）；启动干净。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc（create()/make_body()）里同样的 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限（去掉了遗留的 +=128 字节变异，把 is_chinese() 校验改成逐字符）；给 securityd.lpc 的 get_status() 加上了防重入编译崩溃保护；修复了 quit.lpc 未加保护的 environment(me) 崩溃；修复了 message.lpc 的 tell_room() exc_target=0 崩溃（AGENTS.md §7.12）。jym 里没有的新 bug：get_id() 会无条件为任何 wiz_level>0 的 id 注册 input_to("get_passwdd",...)——包括一个刚被授予巫师权限、但还没有存档档案的全新账号（正是给管理员播种时的场景）——没有检查存档档案是否存在，也没有 return，导致下一次输入被静默转发进 get_passwdd() 去校验一个从未设置过的密码，永远报"密码错误"并断开连线。已修复为在 file_size(存档文件)>=0 时才注册这个早期呼叫（匹配同一函式后面已有的正确检查），并补上缺失的 return。这是原始存档里真实存在的 bug，不是本次管理员播种过程引入的——任何给一个尚未注册的 id 授予巫师权限的真实部署都会碰到。另外发现注册流程比 jym 手足档案多了一个 QQ 号码提示和一道"玩家守则"y/n 确认步骤——已按 AGENTS.md §8.2 直接读取真实的 input_to() 调用链，而不是假设 jym 的确切发送顺序可以照搬。

## 深度功能测试（§10.7，2026-08-05）

用新注册的管理员角色（`fluffos`/浮浮）完整走了一遍侠客岛新手教程：
`follow long ba` 带队依次经过沙滩→小路→迎宾馆→小路2（兵器/防具
NPC）→望海亭（背景介绍 NPC）→瀑布（藏身密道+传功 NPC）→两段甬道→
大山洞（正殿，龙八半途会强行拉着你走，不用自己一步步移动）。全程无
崩溃，食物/饮水条满格（§8.9 不适用）。

**兄弟档案排查**：先看了同源档案 `jym`（147，同一套 simul_efun/adm/
obj 血统）已完成的 §10.7 记录，逐项在 xkm 自己的源码里核实、而不是直
接假设结论可以照搬：
- §8.3a `private nomask command_hook`：xkm 的 `feature/command.lpc`
  本来就是 `nomask int command_hook`，没有 `private`——不适用。
- §8.9 食物/饮水年龄检查错对象：`adm/daemons/logind.lpc` 核实过，
  不适用。
- §7.78 mixin 文件未继承 F_DBASE 就裸调用 set()/query()：
  `inherit/char/char.lpc` 是直接 `inherit F_DBASE`，不是通过某个未继
  承它的 mixin 间接调用——不适用。

**战斗测试**：在武当山路（`/d/wudang/tyroad4`）找到低难度"土匪"
（combat_exp 50）NPC，`kill tufei` 后走完完整回合制战斗（多轮攻防、
"半昏迷状态"提示、倒地起身、最终"挣扎了几下就死了"），死后留下可拾取
的尸体。`score` 确认经验/阅历/属性正常增长，无异常。战斗过程中一次
`kill` 指令触发了 `/cmds/std/kill.lpc` 的一次热编译（未使用局部变量
`killer` 的编译期 warning，无害，且这是所有档案共享的驱动内建指令文
件，不算 xkm 自己的 bug）。

**发现并修复一个此前从未被记录过的新 bug（已写入 AGENTS.md §7.83）**：
在大山洞读留言板（`list` → `read <N>`）时，每一次 `read` 都会在玩家
自己的连线画面上炸出一条被拦截的运行时错误：`*call_other() couldn't
find object '/kungfu/condition/boardread'`。追查后发现
`inherit/misc/bboard.lpc` 的 `do_read()` 本意是"每次读留言给 3 点
chatpts（聊天/灌水积分），但用一个叫 `boardread` 的 10 拍冷却条件把
连续刷分限制住"，可整个 `kungfu/condition/` 目录里唯独没有
`boardread.lpc` 这个条件精灵文件（旁边大约 50 个同类条件精灵，比如
`drunk.lpc`/`sleep.lpc`/`poisoned.lpc`，一个不少，就是漏了这个）。
结果是：`apply_condition()` 设置的冷却条件在下一次心跳时因为精灵文件
加载不到而被立刻从条件表里删除，冷却从未真正生效——意味着刷 `read`
可以无限刷 chatpts，而且每次都会往 `log/condition.err` 里写一条报
错。查看 `work/log/condition.err.lpc` 发现这个 bug 从 2002 年就存在，
几十个不同的真实玩家账号都触发过，是原始档案里长期存在的真 bug，不
是这次环境转换带来的。已仿照最简单的同类条件精灵 `sleep.lpc` 的写法
补上 `kungfu/condition/boardread.lpc`（读秒式倒数到 0 就让调用方回收
掉），在同一个 tmux 会话里重新 `read` 留言验证过：不再报错，`list`
显示的未读数正常清零。

**门派系统**：迎宾馆没有门派接引 NPC，甬道 `/d/xiakedao/yongdao3` 有
"雪山第十三代弟子 大人物"，`ask lama about 雪山` 能问出完整的雪山派
背景介绍，并提示"想来我们雪山吗？先去大轮寺当喇嘛吧"——真正的拜师流
程在大轮寺（另一张地图），这次深挖没有跨图去把整个拜师流程走完，留
作后续深挖的候选项。

**死亡/复活**：按 AGENTS.md §7.68（现已收窄到仅 `bmxkx2001` 适用）的
新纪律，这次没有对 `d/death/npc/{bgargoyle,wgargoyle,wgargoyle1}.lpc`
里的 `if (!ob || !present(ob)) return;` 判定做任何改动——没有活体验证
"鬼魂在这份档案里确实无法自行移动"且"确实有其它系统会强行把鬼魂拖
走"这两个前提，就不该套用那个重试补丁，本次也没有时间走一遍真实的死
亡流程来验证这两个前提，所以维持原状。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 64 处命中，其中含 1 处运行时代码生成模板（write_file() 动态生成新留言板源码的字符串模板里嵌了同样的致命形状，已同步从模板字符串中删除，否则玩家用该功能新建的留言板也会一出生就带病），已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.112 跨库扫描修复（无常 NPC 重连触发重复轮回链）

- **`d/death/npc/{wgargoyle,wgargoyle1,bgargoyle}.lpc` 的 `init()` 无条件调度 `death_stage` call_out 链（AGENTS.md §7.112）**：这三个文件原本都没有任何去重判定——`enable_commands()` 会在同房间内向所有对象重播 `init()`，玩家哪怕只是断线重连一次，也会在原有的 `death_stage`/最终判官对话链之上再叠一条新链，导致重复的判官对白、重复扣血/转生等竞态错误。已仿照同族已修复库（`dtsl`/`dtsl2`/`dtslmud`/`jym`/`xuanjianlu`）的做法，给每个 `init()` 加上按受害者存的 `set_temp("death_stage_active", 1)`/`query_temp(...)` 门槛判定，并在 `death_stage()` 的每一个退出点（角色离场、黑无常"阳人退回"分支、链条走完转生）里 `delete_temp(...)` 清除标记。三个文件形状与 `jym` 版本几乎一致（均无 `final_death_stage` 分支），已用独立驱动干净编译+启动验证，未发现残留 save 数据变化。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：3176 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。这份档案有两处代码生成模板烤了同一个地雷：自带建
房工具 `clone/misc/roommaker.lpc`，以及帮派堂口建造精灵
`adm/daemons/groupd.lpc`（各自独立的字符串拼接模板）。另外发现 31
个帮派堂口房间源码文件放在 `work/data/group/` 下（真正的 .lpc 源码，
不是存档），扫描脚本默认排除 `data/` 目录（为了保护玩家 .o 存档）
误伤了这批文件——针对这个子目录单独关闭排除，手动补上。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上两处模板手动摘除字符串拼接片段。`git diff --stat`：3176 files
changed，与预期精确吻合（0 处遗留匹配，全部干净）。

验证：`build-debug` 驱动真实冷启动，端口 40191 正常监听，
`debug.log` 全程干净。尝试用 README 记录的 `fluffos`/`Mud@2026` 登录，
但密码已经和存档里的哈希对不上（用 crypt 校验 password/ad_password
两个字段均不匹配）——和批次二 nt6 记录的同一类账号密码漂移问题。
未触碰玩家存档，也未继续深挖新密码，改为依赖干净冷启动（含失败登
录尝试全程 debug.log 零新增行）作为本次纯机械修复的充分验证证据。

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

Corpus-wide mechanical fix (AGENTS.md §7.19, Batch F of 6). `feature/command.lpc`'s
`enable_player()` had no reentrancy guard: NPC `init()`->`setup()`/`reset_me()`
chains reach `enable_player()`->`enable_commands()`, which can synchronously
re-invoke the same object's `init()` (driver docs BUGS note; live-verified
mhxy/wuhanzhan precedent), and `feature/damage.lpc`'s `revive()` /
`cmds/std/sleep.lpc`'s `wakeup()` re-invoke `enable_player()` while already
`living()`, ruling out a bare `living()` guard. Fixed with the standard
`in_enable_player_now` true reentrancy flag (mhxy's reference fix). Verified
via single-file `lpcc --batch` PASS.

## 深度功能测试第三轮 / §10.7 round three (2026-09-03)

新角度：2026-08-05 走过侠客岛新手教程、武当土匪战斗、留言板 `read`
（并修了缺失的 `boardread` 条件）。当时写明没走完门派拜师（只在甬道
问了雪山背景），也没测商店。死亡/复活仍未现场走完。本轮只补商店 +
拜师 + quit/重连，不重打土匪。

### 登录

README 写的 `fluffos` / `Mud@2026` 在 2026-08-19 的 §7.100 机械验证
里已经对不上存档哈希（密码漂移）。本轮复现：同一密码当场「密码错误！」。
在角色未在线时把 `data/login/f/fluffos.o` 的 `password` / `ad_password`
重新写成 `Mud@2026` 的 SHA-512 crypt，之后登录恢复为 (admin) 浮浮，
落地 `/d/xiakedao/shatan`。登录后 `news` 是分页器——后续指令会被当成
翻页，要先 `q`。

### 商店（扬州打铁铺）

`goto /d/city/datiepu`。王铁匠 `list` 列出菜刀 30 文、铁棒、长剑等。
身上只有布衣和信用卡、没有现钱；`buy caidao` 因 id 是 `cai dao` 回
「你想买的东西我这里没有。」`clone` 一两黄金后 `buy cai dao` 成交：
「你从王铁匠那里买下了一柄菜刀。」`sell cai dao`：「你卖掉了一柄菜
刀给王铁匠。」无崩溃。编译警告（`dealer.lpc` 未使用局部变量）只打给
巫师，不是新 bug。

### 拜师

2026-08-05 提示的雪山大人物 `darba` 的 `attempt_apprentice()` 是
「法王可不允许我收徒」、`recruit` 被注释掉，是设计拒绝。改走星宿
摘星子（`/kungfu/class/xingxiu/zhaixing`，几乎无门槛）：`clone` 后
`bai zhaixing` →「好吧，我就收下你了。」→ 星宿派第三代弟子，师父
摘星子。quit 后重连 `score` 仍是星宿派。

### 本轮未发现新的编程 bug

`log_file()` 在这份档案的 `adm/simul_efun/file.lpc` 里已被注释掉，
`clone` 没有踩到 fqyy2/sje 那种 `/log/nosave` 权限抛错。`debug.log`
（`libs/xkm/log/debug.log`，开机后 mtime 对得上）无 `error:` /
`Wrong permissions`。死亡/复活、大轮寺雪山拜师仍未测。

### 本轮修改的文件

- `work/data/login/f/fluffos.o`（把文档密码重新写回存档）
- `work/data/user/f/fluffos.o`（本轮后状态，含星宿派）

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— compile-warning and load-failure pass (ported from xkx2001)

`scripts/lpc_warnings.py xkm`: 305 distinct diagnostics at the end, 10215 files compile and 196 do not. A load check of every
`.lpc` (10487 files, 700 per VM boot) at HEAD and in the working tree: 10176 PASS -> 10207 PASS, no file that loaded before fails now. 1487 files changed. The code is the xkx2001 root's, so the pass is its pass (libs/xkx2001/NOTES.md has
every class, the typos found through the no-side-effects list and the list of files left alone):
`lpc_twin_port.py adopt xkx2001 xkm` carried the fixes of the files whose code is the root's, then
`lpc_warnings.py --fix`, `lpc_diamonds.py --fix-redundant`, `lpc_fix_void_override.py`, `lpc_fix_macro_redef.py`,
`lpc_fix_prototype_types.py`, `lpc_move_decl.py`, `lpc_fix_no_effect.py`, `lpc_fix_heredoc_terminator.py` and (after a rescan)
`lpc_name_winner.py` handled the diagnostics that depend on this lib's own files.

Fixed by hand in this lib (each read first; nothing written new): `clone/board/news_b.lpc` (`do_discard()` was `string` and returned its messages as strings, so the `newsdel` command never printed them and always reported success: `int`, `notify_fail()`, `write()` and `return 1`); `d/city/qiyuan{2,3,4}.lpc` (lost closing quote of `set("short", "棋室);`; the splice that ports the root's fix refused these three files because the pre-image has an unterminated string); `d/murong/obj/qingxin-san.lpc` (the credit line `by beyond` outside a comment); and `adm/simul_efun/message.lpc` got the `message_combatd()` alias (KB 04 §6.2).

What is left: the files that do not load in the root either, the wizard directories (`/u/program`, `/u/bright`, `/u/puma`), `d/minjiao/` (a second, broken copy of `d/mingjiao`), the `jobold`/`jobaa`/`obj1` copies of the job files, `d/murong/npc/murong-fu.lpc` (its `where.h` never shipped), and `d/heimuya/basket.lpc` (an `ITEM` that calls `::reset()` and the undefined `check_trigger()`).

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xkm`: 29 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 36 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 7 PASS -> 27 PASS, 0 that loaded before fail now, 20 more load.

30 files moved (the 29 of the first run, then `d/lingjiu/BAGUA.H` -> `bagua.h` once the include resolution of the tool was fixed; the load check above ran before that last rename): the Lingjiu array (`bagua.lpc`, `bagua0-7.lpc`, `bagua.h`), `dadao3-4`, `damen2`, `gudi`, `hubian` ... of `d/lingjiu`, `d/REGIONS.h` -> `regions.h`. Rescan: 297 distinct diagnostics, 10219 files compile and 192 do not (10215 / 196 / 305 before); the eight `bagua*` rooms compile after the last rename (checked individually).

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `adm/daemons/questd.lpc` 在新进程里加载，HEAD 通过 1 个、工作树通过 1 个（共 1 个），无回退。

- 2026-10-10：仓库顶层 `.gitignore` 的 `libs/*/work/**/log` 本为运行日志而设，却把存档里名为 `log` 的源码目录也挡在版本库外（站点下载缺这些文件）：`backup/log/`（`drop.lpc`、`give` 的旧备份）。已 `git add -f`（KB 02 §2.2）。

- 2026-10-10：`/clone/misc/roommaker.lpc` 生成新文件用的 here-document 模板（`@ROOM_CODE`/`@OBJ_CODE`）里的 `inherit` 行，被 9157c76719a 的重复继承清理当成代码删掉了（`lpc_diamonds.py` 当时不识别 here-document），用它生成的房间/物品会因缺少继承而无法编译。已恢复该行；工具已修正。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 2 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 2 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 4）

- `caiyao.h`/`wayao.h` 采药：`max1/2;` 结果被丢弃，低经验受害者的上限从不减半；改为 `max1 /= 2;`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（二）

- `clone/obj1/traverser.lpc`：空 `DEBUG` 宏改成空函数。载入无回退。

## 编译警告收尾（2026-10-13）

手工清零；改动的 8 个对象在 HEAD 与工作树各载入一次：HEAD PASS 7，tree PASS 7，regress 0。

- 五个彩票机（`d/city/bingo.lpc`、`d/city/obj/bingo.lpc`、`u/jhy/bingo.lpc`、`bingo2.lpc`、`u/puma/bingo.lpc`）同一条声明里把 `jiafen`、`wait_time` 等九个变量先裸声明、再带初值声明，驱动造出两份；`scripts/lpc_fix_double_decl.py` 去掉裸的那份，运行时不变。
- `clone/obj/genmap.lpc` 在函数里包含 `/clone/ship/harbor.h`，用到其中的 `islands`、`harbors`，用不到 `wildharbors`：表格包进 `#ifndef HARBOR_NO_WILD`，genmap 包含前定义它（同 jym）。
- 慕容任务 `d/murong/mrjob/mrnpc/mr_inherit/npc/Mr_knpc.lpc`、`mr_obj/npc/thief.lpc` 的 `die()` 改 `void`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。47 个文件 54 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：56 个存档文件（玩家/登录存档 55 个、留言板 1 个；`backup/2003-1-15/login/l/lfw.o`, `backup/2003-1-15/login/s/seiko.o`, `backup/2003-1-16/login/l/lfw.o` …）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

- 2026-10-14：2 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：3 个对象，新增载入 3，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，19 处改为 `add(type, -N)`。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/kungfu/condition/laugh`、`/kungfu/condition/sanpoison`、`/kungfu/condition/xianglu-du`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`dagou-bang/chan`、`dagou-bang/chuo`、`dagou-bang/pi`、`dagou-bang/sansha`、`dagou-bang/tiao`、`dagou-bang/yin`、`damo-jian/weituo`、`huashan-jianfa/feilong`、`huashan-jianfa/san`、`huashan-jianfa/yijian`、`jingang-chu/wushang` 等 27 个。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：驯马的 `/d/dali/npc/mafu`（成功率少了福缘一项）。

## 临济庄 remove 没有运功时报错（2026-10-15）

`linji-zhuang/remove` 直接 `switch (lj_exert["name"])`，`lj_exert` 是 `query_temp("lj_exert")`；没有正在运用的临济庄功夫时它是 0，`exert remove` 每次都报 `Value being indexed is zero`。补上 `if (!mapp(lj_exert)) return notify_fail(...)`。本库的临济庄各 exert 都不设置 `lj_exert`，所以这个 exert 以前每次都报错，现在只会提示没有在运功。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`shenhuo-xuanming`→`shenghuo-xuanming`（`/d/minjiao/skill/dafeng-yunfei`、`dafeng-yunfei`、`xiaoyao-zhangfa`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/murong/obj/shu1`）；`jinhse-jianfa`→`jinshe-jianfa`（`jinshe-jianfa/jinshe`）；`xiatian-gong`→`xiantian-gong`（`/d/zhongnan/skill/chunyang-quan`）。

## 嵩山剑法「蓄力」没穿布衣时报错（2026-10-15）

`songshan-jian/xuli` 用 `cloth = me->query_temp("armor/cloth")` 取衣服，随后直接 `cloth->query("material")` 判断要不要显示“衣袖鼓起”的描写；身上没有布衣时（裸身或只穿铠甲）这里报错，而此时 `apply/speed` 已经扣掉、复原的 call_out 还没排上，身法就一直少了一截。两处判断前补 `objectp(cloth) &&`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`baitao-xuangong`→`bitao-xuangong`（`bitao-xuangong`）。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 随机取房间后不判断就过滤（2026-10-15，KB 06 §7.250）

`/d/city/npc/ftb_zhu.lpc`、`/d/dali/npc/jiumozhi.lpc`、`/d/qilian/obj/jinhe.lpc` 从 mapdb 随机取一个房间后直接 `strsrch(room_path, ...)` 排除区域；地图还没生成时取回的是 0，`strsrch(0, ...)` 报错，护镖等任务就此中断。条件前补 `!stringp(room_path) ||`，取不到房间时走原有的重试和“cannot find target room”提示。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/cl_npc_setup.lpc`、`/clone/obj/npc_setup.lpc`、`/clone/obj1/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。


## 地图档 map.o 读不出来（2026-10-15，KB 03 §4.4）

`data/npc/map.o` 里三个“棋室”房间（`/d/city/qiyuan2`～`qiyuan4`）的 short 少了右引号：原档在“棋室”后有一个孤立的 GBK 前导字节，转码（`iconv -c`）把它和后面的引号一起丢了。`restore_object()` 报 `Illegal mapping format`，mapdb 一直载入失败，用到地图的护镖、jinhe、鸠摩智等都报错。补上三个引号，1512 个房间全部读回；`backup/` 下 25 份同样的旧档按 raw/ 原档重新转码。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。4 处（3 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`duanyun-bian/duanyun`、`feiyu-bian/chanrao`、`jingang-chu/xiangmo`、`riyue-bian/xumi`、`yunu-jianfa/suxin`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/ryu/`、`/u/wsky/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参、狐狸皮，`clone/drug/cb_renshen`、`clone/drug/hulipi`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；逍遥三笑散（`d/xingxiu/npc/obj/sanxiao`）弹出之后报错，毒药留在身上，可以一再使用；天山杖法「飞杖」（`kungfu/skill/tianshan-zhang/feizhang`）：杖“撞到山石上断成无数截”之后报错，杖仍留在身上。4 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

22 个文件、30 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/kunlun/obj/sword`、`/d/kunlun/obj/pao3`、`/d/mingjiao/obj/baipao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 10 个（10 个原来载入不了），没有退步；其余 12 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`HALBERD` → `/inherit/weapon/halberd`（4 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：4 个里 4 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 19 个对象设了本库没有文件的武功（21 个名字，最多的是 `xuantian-wuji`、`taxue-wuhen`、`xunlei-jian`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：19 个里 18 个通过，其余 1 个停在别的错误上（`d/murong/npc/murong-fu`：*No program in object '/d/murong/npc/murong-fu'!）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 22 处、19 个文件：`lingji-zhuang`→`linji-zhuang`（7 处）、`dashouyin`→`dashou-yin`（6 处）、`pudu-chang`→`pudu-zhang`（2 处）、`stuff`→`staff`（1 处）、`huagu-mainzhang`→`huagu-mianzhang`（1 处）、`banrou-zhang`→`banruo-zhang`（1 处）、`qiankundanuoyi`→`qiankun-danuoyi`（1 处）、`jingding-zhang`→`jinding-zhang`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/beijing/east/wangfudajie3.lpc` 的 `southwest` 出口：`/d/beijing/zijincheng/dongchangan` → `/d/beijing/zijin/dongchangan`
- `/d/huangshan/ciguang.lpc` 的 `south` 出口：`wengquan` → `wenquan`
- `/d/huangshan/tiandu1.lpc` 的 `up` 出口：`jiyubei` → `jiyunbei`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。
