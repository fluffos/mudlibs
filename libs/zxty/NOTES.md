
## WASM 修复摘要（迁移自 meta.json 的 group_note）

再现天涯（游戏内横幅：梦回天涯 / 'Dream Return to Tianya'）。和本次会话更早处理过的 Doing 血统 'hell' 家族无关——是一个独立的 ES 衍生代码库，但带有一个巫师个人目录（u/zjb/）里放着好几份核心系统档案（logind.lpc、master.lpc、securityd.lpc）过时的备份副本，没有任何真实路径引用它们（根据 include/globals.h 和 config.fluffos，LOGIN_D=/adm/daemons/logind，MASTER_OB=/adm/obj/master）——已通过 grep 确认 u/zjb/ 之外没有任何地方引用这些备份副本，所以只改动了两份真正生效的档案；备份保持原样，作为无害的死代码。WASM 修复了：（1）真正生效的 adm/daemons/logind.lpc 里一个转档之前就存在（不是本轮引入）的、阻断启动的编译错误：第 28 行 'string *banned_id = (...)' 前面多了一个孤立的 ':'，产生"error: modifier list may not be empty"，导致 logind 完全编译不过，通过 new_conn_handler 把每一个连线用户都断开了——已删掉这个多余的冒号。（2）check_legal_name() 的 §8.1 GBK 字节区间/奇偶 bug：strlen 界限没有减半（<4||>8，本意"2 到 4 个中文字"，已改成 <2||>4）以及一个 i%2==0 的奇偶门槛，配合一个单码点的 is_chinese(name[i..<0]) 辅助函式，实际上只验证了每隔一个字符是不是中文——已删掉奇偶门槛，让每个字符都被检查。is_chinese() 本身（adm/simul_efun/chinese.lpc）本来就是正确的（对 str[0] 做逐码点的 0x4e00-0x9fff 区间检查），不需要修。（3）master.lpc（adm/obj/master.lpc）的 valid_read()/valid_write() 缺少标准的 'user == this_object()' 保护——两处都已加上。已确认这里不需要的修复：is_killing()（feature/attack.lpc）本来就接受物件参数，每一个呼叫点也本来就传的是物件——这份档案不存在 §7.50 类的类型不匹配 bug。httpd.lpc、dns_master.lpc（通过 inetd.lpc）、versiond.lpc、closed.lpc 都带有真实、未掏空的 socket_*() 呼叫，但没有一个在 adm/etc/preload 里，也没有一个能从登录/注册路径触达（VERSION_D 和 CLOSED_D 互相呼叫，还被少数几个 NPC/指令呼叫，而那些呼叫者本身在启动时也触达不到）——保持原样，完全休眠，和本项目其它地方对 ftpd/dns_master 已经确立的先例一致；已通过 grep 确认没有任何预加载精灵或 logind.lpc 引用它们。log/nosave/ 目录缺失（很多非启动路径的功能会用到它——shell 日志、制作日志、吃道具日志）——出于预防已经创建，尽管这里不是阻断启动的（logon() 自己的 log_file() 呼叫都不指向 nosave 路径）。管理员账号播种：fluffos (boss) 加入 adm/etc/wizlist（这份档案的最高巫师阶层字符串是 '(boss)'，不是 '(admin)'——和压缩包原有的 tangsheyu/baizhou/bzhou/baixzhou 条目并存）。注册流程在格式化前后都完整验证过（英文 id→y 确认→单一中文全名（2-4 个字，不分姓名）→管理员密码+确认→登录密码+确认→属性赠礼菜单（0 随机）+确认→电子邮件地址→性别→进入有间客栈），管理员权限已通过'您目前权限：(boss)'确认。有一处格式化工具第 3 个盲点命中（d/city/sj.lpc，转档之前就存在的不配对引号导致 CJK 重新加空格损坏）——已通过 git checkout 还原，确认格式化前的原始内容里没有那个 '\ n' 签名。LPC 格式化工具对全部 13193 个档案运行（写入 13067 个，80 个转档之前就存在的错误，46 个未改动，包括 u/zjb/ 下很多死代码档案）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。

## 深度功能测试（§10.7，2026-08-05）

这份档案是"天涯"家族的又一分支，先检查了同家族已完成 §10.7 深挖
的 `tybxjh`/`xhcii` 的记录，逐项在 `zxty` 自己的源码里核实：

- **2 处 printf 调试残留**：`adm/daemons/logind.lpc` 的
  `get_resp()`/`get_name()`，和 `tybxjh`/`xhcii` 逐字节相同。已删除。
- **§8.9 食物/饮水年龄检查错对象**：`enter_world()` 里
  `if (ob->query("age") == 14)`，同样的错对象判断。已改为
  `user->query("age")`。
- **§7.85（tybxjh 的进度条渲染缩放 bug）适用，已修复**：
  `cmds/usr/score.lpc` 的 `tribar_graph()` 和 `tybxjh` 修复前的版
  本逐字节相同（`bar_string`/`blank_string` 16 字符，
  `none_string` 34 字符，残留的 `*2` 宽度乘数），同样的两个失效模
  式（数值为 0 时因为负数下标 `[0..-1]` 反而显示满格；超过约一半
  时切片终点越界被静默截断成满格）。已用相同的重写修复，注册后食
  物/饮水条正确显示（战斗后再查看时能看到真实按比例扣减，比如
  15/16）。
- **§7.86（tybxjh/xhcii 的留言板 `post` 崩溃 bug）适用，已修复**：
  全档案 105 份留言板档案（`clone/board/*_b.lpc`、`d/**/`下多处、
  `p/residence/board/` 玩家自建的留言板）都同时 `inherit
  BULLETIN_BOARD` 和多余地 `replace_program(BULLETIN_BOARD)`，同
  样导致 `post` 指令必然崩溃（`*cannot bind an lfun fp to an
  object with a pending replace_program()`）。已删除全部 102 处
  多余调用（另外 3 处早就被前任巫师注释掉，保持不动）。live 验证
  过：`post` 正常打开编辑器，"新贴子完成"保存成功。
- **§7.86 的另一半（缺失 `/log/login/` 目录导致注册截断）不适
  用**：这份档案的 `work/log/login/` 目录本来就存在（里面已经有
  `newid.log` 等真实历史记录），`log_file("login/newid.log", ...)`
  从未失败过，注册流程干净。
- **exert_function(10) 类型错误，4 处——之前两次深挖（`tybxjh`/
  `xhcii`）用来排查这个 bug 的 grep 命令写错了**：早先用的是
  `exert_function([0-9])`（单个数字的字符类），根本匹配不到两位数
  的 `exert_function(10)`，所以 `xhcii` 那次深挖实际上是真的没有
  这个 bug（用修正后的 `exert_function([0-9]+)` 正则重新核实过，
  确认 `xhcii`/`tybxjh` 都干净），但 `zxty` 这边是真的有，而且是
  live 撞见的：死亡后在鬼门关等复活流程跑完时，`debug.log` 直接报
  出 `error: Bad type for argument 1 of exert_function (string vs
  int)`，来自 `d/daniel/saveme.lpc:23`。和 `tybxjh` 完全相同的四个
  档案（`d/zjb/shengji.lpc` 升级师、`d/daniel/saveme.lpc` 和
  `d/player/ltsh/npc/saveme.lpc` 两份"大魔道士--雅薇丝"、
  `u/zjb/hlxy/zs.lpc` 转世僧人）都有这一行死代码，已全部删除。用
  `goto /d/daniel/saveme` 直接重新编译确认修复生效（之前会编译失
  败，现在正常显示房间和 NPC）。
- **战斗/死亡/复活测试**：〖有间客栈〗禁止战斗（正常设计），移动到
  〖中央广场〗与"收破烂的"打了一场势均力敌的回合制战斗，最终力竭
  阵亡，落到鬼门关，`白无常` 在场，判定守卫是同样的
  `if (!ob || !present(ob)) return;`（AGENTS.md §7.68，现已收窄到
  仅 `bmxkx2001` 适用）——按新纪律未做任何改动，让流程原样跑完。
  第一次尝试时，流程进行到一半，`debug.log` 报出了上面提到的
  `exert_function` 编译错误（`d/daniel/saveme.lpc`）——没有确凿证
  据证明这次编译尝试和复活流程本身有因果关系（也可能是某个不相关
  的房间重置/巡逻逻辑恰好在同一时间触发了那个档案的惰性编译），但
  确实是在等待复活期间实际发生、抓到 debug.log 里的一次真实崩溃，
  值得记录。修复 `exert_function` bug 之后，`goto` 直接确认了那个
  档案能正常编译；死亡/复活流程本身（判定守卫、五阶段对话、
  `reincarnate()`）从代码读取上看没有问题，和已验证过的 `tybxjh`/
  `xhcii` 是同一套实现。
- **本次没有测试**：拜师/门派系统、商店（时间主要花在追查/验证上
  面几个更严重的 bug 上，留给后续深挖）。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。上面记录的所有修复（printf 泄漏、§8.9、
§7.85 进度条、§7.86 留言板、`exert_function` 类型错误）逐项核对代
码仍然生效；`win_times` 的 `%`-operator 也已用
`to_int(query("win_times")) % 5`（`d/city2/npc/refereew.lpc:146`）。

### 本轮新发现并修复的 PROGRAMMING bug

1. **`feature/dbase.lpc`（真正生效的 F_DBASE）的密码写保护是
   tybxjh/wlhd 那一类已确认的 bug 形状**：`if ((prop == "password"
   || prop == "ad_password") && wizhood(this_object()->query("id"))
   == "(boss)" && this_player() && geteuid(this_player()) !=
   this_object()->query("id")) return;`——`wizhood()` 纯粹读
   `wizlist` 文件，不检查密码是否已经真正存在于 `dbase` 里，任何
   预先播种为 `(boss)` 的 id 都会在自己第一次设置密码时被这条守卫
   拦截。按已确立的标准修法加上 `mapp(dbase) && dbase[prop]`，只在
   密码已存在时才拦截，不影响首次创建。（`u/zjb/` 目录下另外三份
   `dbase.lpc` 死代码副本有完全相同的形状，但没有任何宏或引用指向
   它们，未改动。）
2. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）的严重度检查漏了第二个回显分支**：这份档案的写法有两条并
   行的回显路径——`if (this_player(1)) efun::write(...)` 和 `else
   if (this_player()) tell_object(...)`——第一轮编辑只把严重度判
   断包进了第一条分支，live 复现：注册过程中仍然收到大量原始的
   `编译时段错误：.../combatd.lpc:1384:1: Warning: Unused local
   variable ...` 泄漏，因为走的是第二条 `tell_object` 分支。已把
   两条分支一起包进 `strsrch(message, "arning:") == -1` 判断（和
   yxjh 上确认过的同一类"多分支各自需要单独加保护"教训一致）。
3. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护**：函数体只有裸 `write_file()`，同一文件里
   的 `assure_file()` 辅助函数从未被调用。已加上前向声明 +
   `assure_file(LOG_DIR + file);`。
4. **`cat()`（同一文件，供玩家/巫师直接呼叫的 `cat` 指令）两处独立
   的 `write_file("/log/file/{cat,bugcat}", ...)` 同样缺少
   `assure_file()` 保护，且对不存在文件的 `read_file()` 结果没有类
   型检查**：`work/log/file/` 整个目录被 `.gitignore` 忽略，真正
   全新的检出不会带有这个目录。特别检查过 `enter_world()` 里的
   `cat(MOTD)` 调用——它的调用者 `base_name(ob)` 正好是
   `/adm/daemons/logind`，两处 `write_file()` 都显式排除了这个调
   用者，所以这条路径本身不会导致"每次登录必崩"（不像 yxcs 的
   `cat(WELCOME)` 那次），但玩家/巫师直接用 `cat` 指令读取任意档
   案时仍然会命中未防护的 `write_file()`。已给两处都加上
   `assure_file()`，并把 `write(str1)` 改成 `write(str1 || "")`。

### Proactive checks / 观察记录

- **一个间歇性触发、确认为既有安全设计、未修改的现象**：
  `adm/daemons/wzd_log.lpc`（真正被 `logind.lpc` 多处呼叫，不是死
  代码）给巫师/管理员账号加了一层算术验证码防护——`wizardp(user)`
  为真时，`enter_world()`/`reconnect()` 会被重定向进
  `wzd_log()`，显示一串数字并要求提交一个基于隐藏公式
  `(n1*n4+8)*100+n2*n3-3` 算出的答案，答错就直接断线（不崩溃，干
  净拒绝）。本轮测试中这个挑战在某些重连尝试中出现、某些又不出
  现（比如用一个独立的裸 socket 脚本单独测试时完全没有触发，紧接
  着的另一次快速连续重连又触发了）——具体触发条件似乎和
  `previous_object()`/连线时序有关，和 yxjh 那次确认的连线状态竞争
  同属一类现象，但这次是驱动干净拒绝，没有崩溃或指令流错位，
  `debug.log` 全程也没有任何报错。因为触发/不触发都不产生真正的
  程序错误（只是安全挑战有没有被插入这一步），按本项目"没有实测复
  现真正崩溃就不改动"的纪律未做处理，如实记录供未来复测参考。

### 实测过程

管理员 `fluffos`（管理密码 `AdminMud@2026`，普通密码
`Mud@2026`，`adm/etc/wizlist` 早已播种但从未真正注册过）用完整双
密码注册流程创建，落地"有间客栈"，`score` 显示"【巫师总兼】"头
衔，食物/饮水满格。随后做了三次独立的断线重连+密码验证（详见上方
"间歇性触发"记录）：均成功用普通密码登录，存档数据一致。全程两个
调试日志位置都干净，无运行时错误。驱动按精确 PID 结束；管理员存
档已提交。

## AGENTS.md §7.100 修复（2026-08-19，批次三）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：4474 个房间文件命中。本 lib 有四份独立的建房工具拷贝
（`clone/misc/roommaker.lpc`、`u/xiyang/obj/roommaker1.lpc`、
`u/landy/obj/roommaker.lpc`、`u/bzhou/obj/roommaker.lpc`），全部
四份的字符串拼接代码生成模板里都烤了同一个地雷，一并修复。

修复：脚本化删除独立成行的 `replace_program(ROOM);`，四份 roommaker
模板手动摘除字符串拼接片段。`git diff --stat`：4474 files changed，
与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40166 正常监听。既有管理
员账号 `fluffos`/`Mud@2026` 登录（本次连线未触发既有记录过的间歇
性 wzd_log 巫师身份验证挑战），`score` 显示【巫师总兼】头衔，
`quit` 干净退出，全程无新增 "cannot replace"/"cannot bind" 日志行。
测试触发了本 lib 自身"游戏内时长不足 30 分钟不予存档"的既有逻辑，
误删了 `data/login/f/fluffos.o`，已用 `git checkout` 还原，未纳入
提交。

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

## 深度功能测试（2026-09-03，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师，并核对存盘后门派是否还在。
2026-08-13 那一轮明确没测这两步。

### 实测过程

管理员 `fluffos` / 普通密码 `Mud@2026`（本次未走管理密码）。落地
`/d/city/kedian`。`goto /d/city/zuixianlou`，`list` 价目为铜钱尺度
（烤鸡腿八十文钱）。`clone /clone/money/gold` 后 `buy jitui` 成功
（找零九十九两银子 + 二十个铜板）。`F_DEALER`（`feature/dealer.lpc`）
没有丐帮「穷叫化」拒绝；`dealer1.lpc` / `vendor.lpc` 有，醉仙楼小二
不用那两份。本轮仍先买再拜。

`goto /d/gaibang/inhole`，`apprentice zuo`：左全收徒，`score` 称谓
「丐帮第二十代弟子」、师傅左全。没有 yxjh 那种 `join 名门正派` 门。
显式 `save` 成功，`user.o` 立刻带上 `family`。

本轮第一次登陆 127.0.0.1 没走 `wzd_log`；断线重连时触发，显示码
首位是诱饵，按第 2–5 位算 `(n1*n4+8)*100+n2*n3-3` 通过，公式和
2026-08-13 / zxty08 记录一致。重连 `score` 仍是丐帮第二十代弟子 /
师傅左全，银子还在。

`quit.lpc` 对 `mud_age < 1800` 会删 login.o（真正 `rm` 没有
`wizardp()`）。和 zxty08 同一既有政策，未改，本轮不 `quit`。

### 发现并修复的 PROGRAMMING bug

1. **`cmds/usr/save.lpc` 把真正的 `link_ob->save()` / `me->save()`
   注释掉了，只打印「档案储存完毕」。** 和 yxjh 同一形状。已恢复
   成真正调用两个 `save()`。

2. **`securityd.lpc` `valid_read()` 里对 `/log/` 的拒绝会
   `log_file("file/bug_read")` 再入。** 非 `zmud`/`bzhou` 的巫师
   （包括 `fluffos`）登陆会 Too deep recursion。加了
   `in_valid_read` 重入保护（和 zxty08/yxjh 同形状；允许 id 在这里
   是 `zmud`/`bzhou`）。修复后登陆两行警告，`clone` 一行警告加黄金
   复制成功，本 boot 零 recursion。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 1 个，工作树三次分别通过 1、1、1 个（共 2 个），无回退；`adm/daemons/cron.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt zxty08nxgbb zxty` 把 zxty08nxgbb 警告整理提交（20451f2a232）里的改动搬到 715 个修改前与它一致的文件（逐文件核对非 ASCII 文字：没有丢失或改动），剩下的再跑 `scripts/lpc_warnings.py zxty --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（两份 `wzd_log.lpc` 的 `for (i == 0; ...)` 改成 `=`），共改动 1007 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：857 -> 857；`d/migong/lev20/npc/lev3` 在批量里 HEAD 通过、工作树失败，单独连载三次 HEAD 与工作树都失败，是批量加载的假象（随机迷宫 NPC），对应的 `lev18/npc/lev3` 反过来新能加载。改过的头文件的 94 个包含者 77 -> 77 通过。
手工：`feature/jh_dealer.lpc` 只剩注释的 `if (!vip) { }` 去掉，注释留着；`clone/obj/traverser.lpc` 的空 `DEBUG` 宏改成调用空函数。`clone/obj/job_server.lpc` HEAD 起就编译不过，未动。

启动时警告 27 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、0 处去后缀（如 `cmds/app/lp2.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 10 处，返回类型/原型 25 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 36 个文件，HEAD 与工作树各载入一次无回退（36 objects; HEAD PASS 35, tree PASS 35; regress 0; newly loading 0），这些文件的警告 36 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/*/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造了一个函数指针就丢掉，巡捕从不走动；改为 `random_move();`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-12：`clone/npc/obj/xiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 5 处多余继承，照 tybxjh（72440a6be25）搬来 peng 的 `ask_fail` 原型、`xingchen` 的 `clean_up()`、`huashan-jian` 的多余 `;`；其余手工。能编译的文件警告清零；改动的 17 个对象在 HEAD 与工作树各载入一次：HEAD PASS 14，tree PASS 14，regress 0。

- `adm/daemons/poistiond.lpc`（继承 `ITEM` 与 `F_SAVE`）的 `varargs int remove() { save(); return 1; }` 盖住了 `F_MOVE` 的 `remove(euid)`——销毁时卸装备、从持有者身上扣重量的那一步（KB 06 §7.239）；改成先 `save()` 再 `::remove(euid)`。
- `adm/npc/beastseller.lpc` 的 `attempt_apprentice()` 改 `void`；足球赌局五个房间（`d/zjb/zuqiu*.lpc`、`u/zjb/zuqiu.lpc`）把 `MAX` 定义成坐庄本钱，覆盖 `globals.h` 的 `MAX(a, b)`，先 `#undef`；`clone/box/gboxa.lpc` 已在注释里的一段又写了一个 `/*`，删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 `int power_point()`/`int hard_point()` 返回 1.5、1.75 之类的浮点，经 int 返回被截断；本库没有调用者（练功走 `practice_bonus`/`learn_bonus`），改成 `float` 返回值，保留原数值。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 6 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-dafa`、`quanzhen-jian`、`wugong-zhao`。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`zidian-jianfa`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`、`dagou-bang/chuo`、`dagou-bang/pi`、`dagou-bang/tiao`、`dagou-bang/yin`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest/quest2/jinyong`、`/quest2/jinyong`、`/quest2/jinyong/jinyong`、`/quest2/quest2/jinyong` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`；落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`wangran-xinfa`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`palm-sword`→`plam-sword`（`hand-blade`、`plam-sword`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`miaojia-jian`→`miaojia-jianfa`（`miaojia-jianfa/miehun`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yunv-xinjing`→`yunu-xinjing`（`wangran-xinfa`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 随机取房间后不判断就过滤（2026-10-15，KB 06 §7.250）

`/d/city/npc/ftb_zhu.lpc` 从 mapdb 随机取一个房间后直接 `strsrch(room_path, ...)` 排除区域；地图还没生成时取回的是 0，`strsrch(0, ...)` 报错，护镖等任务就此中断。条件前补 `!stringp(room_path) ||`，取不到房间时走原有的重试和“cannot find target room”提示。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。


## 福威镖局的程金斧和刺客从没载入过（2026-10-15）

`clone/obj/npc_setup.lpc` 的技能表抄自 xkx2001，本库没有 `kick` 以及桃花、白驼、雪山、华山的一些技能（共 14 个），F_SKILL 对不存在的技能直接报错：`d/city/npc/ftb_zhu`（程金斧，护镖任务）一载入就报 `F_SKILL: No such skill (kick)`。npc_setup 里加 `set_skill`/`map_skill`/`prepare_skill` 三个包装，跳过本库没有的技能。刺客 `ftb_killer` 另外穿的是本库没有的 `/clone/armor/beixin`，改为本库自己的 `/d/city/obj/beixin`（同一件皮背心）。两者现在都能载入。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunu-jianfa/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/city/obj/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 弹指神通「漫天花雨」每次报错（2026-10-15，KB 06 §7.246）

绝招声明了 `object weapon;` 却从不赋值，接着就 `weapon->query_amount()` 数暗器：每次使用都报错。补上取兵器的判断，手里没有暗器时拒绝（“你手中没有暗器”）。


## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

10 个文件、14 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/jyquest/sword`、`/jyquest/armor`、`/quest/weiguo/japan/obj/japanblade`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 3 个，改后 8 个（5 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/std/sssinventory.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了。改后用 `lpcc` 逐个载入这些对象：2 个通过。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`BUILD_ROOM` → `/inherit/room/buildroom`（20 个文件）、`STICK` → `/inherit/weapon/stick`（3 个文件）、`F_GUARDER` → `/feature/guarder`（3 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：26 个里 23 个通过，其余 3 个还有别的错误（`clone/unique/kusang-bang.lpc`：Unable to find the inherited function 'create'.；`clone/unique/yuzhu-zhang.lpc`：Unable to find the inherited function 'create'.；`d/room/roomnpc/laopu.lpc`：Unable to find the inherited function 'accept_hit'.）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 205 个对象设了本库没有文件的武功（64 个名字，最多的是 `magic-unarmed`、`magic-sword`、`spells`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 30 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/ring`（宏 `RING`）←xyzxfy2，13 个对象继承它，抽样 10/10 载入；`/clone/fam/gift/gift`←wxddym，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 22 处、18 个文件：`yan-fly`→`yanfly`（3 处）、`yijin-jing`→`yijinjing`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`poyu-qua`→`poyu-quan`（1 处）等共 13 个名字。（`scripts/lpc_fix_skill_names.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/feitian/npc/wolf`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 2 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `F_SILENTDEST`、`LOOK_CMD`，用到它们的物件（名单里 2 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 2 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/clone/unique/fumo-dao.lpc`、`/clone/unique/jinfu.lpc`、`/clone/unique/jinshe-jian.lpc`、`/clone/unique/jiuyin_force_book.lpc`等共 19 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 1 个 NPC 文件、1 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_sword3.lpc`（共 3 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`（共 3 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/zjb/paimai.lpc`：拍卖房的 `add("pnum",1)`（竞买者计数）被 `//归还前一个竞买者的钱` 注释吞掉，计数从不增加

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/misc/_xiao`（宏 `MI_XIAO`）←tianxiawuxue：1/1 个继承它的对象载入，同时带来头文件 `/include/music.h`

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 7 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）、`/d/city2/npc/zhengmen.lpc`（jqxz2008）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/kungfu/skill/guxing-sword.lpc`（xyzx3）、`/quest/murong/qlist3.lpc`（bixiecanyang）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/zjb/adm/combatd2.lpc`。修后与 HEAD 逐个对比载入：这 7 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/cmds/bos/log.lpc`（1 处）、`/d/changan/ca2.lpc`（1 处）。

## 任务 NPC 的 `random_move()`：目的地房间没载入时 `find_object(dest)->query(...)` 对 0 调用（2026-10-20）

任务/豪杰 NPC 随机走动前先问目的地房间是否 `no_fight`，`find_object(dest)` 在房间还没载入时返回 0，`0->query()` 报 `Bad argument 1 to call_other()`，NPC 每次心跳报一次错、永远走不出第一个房间。改为 `(find_object(dest) || load_object(dest))->query("no_fight")`。改动：`/quest2/wenshu/task1/questnpc.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 14 处）。改动：`/d/zjb/liandan.lpc`（14 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/wiz/mcheck2.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/versiond.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/migong/migong/obj/npc1.lpc`、`/d/migong/migong/obj/npc2.lpc`、`/d/migong/migong/obj/npct.lpc`、`/d/migong/obj/npc1.lpc`、`/d/migong/obj/npc2.lpc`、`/d/migong/obj/npct.lpc`（等共 8 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 11 个存档共 16 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/data/guild/$HIC$〖御云山庄〗.o`（1 处）、`/data/guild/$HIC$烟$HIW$波$HIB$瀛洲$HIR$阁.o`（6 处）、`/data/npc/chike.o`（1 处）、`/data/npc/dukuan.o`（1 处）（等共 11 个存档）。

## `dual` 不带参数：`evaluate_shell()` 对 0 取下标（2026-10-21，KB 06 §7.336）

`dual`（`cmds/arch/dual.lpc`）把参数原样交给 `me->evaluate_shell(arg, flag)`，那里第一件事是 `arg[<1] == ';'`，参数为 0 时报 `Value being indexed is zero.`（`feature/shell.lpc`）；静态扫描只认直接传给 efun 的参数，看不见这种经过 `call_other` 的。命令开头加 `if (!arg) return notify_fail("指令格式 : dual [detail]\n");`（同系 16 个 `dual` 里另外 7 个本来就有这个检查）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（2 个文件，括号里是接住 0 的 efun）：`/cmds/bos/mu.lpc`（`sscanf`）、`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。

## 九阴真经上篇：`/cmds/skill/du.lpc` 本库叫 `study`（2026-10-21，KB 06 §7.344）

`/clone/unique/jiuyin_force_book.lpc` 的 `do_read()`：`9yin == "granted"` 的玩家读书时 `"/cmds/skill/du.lpc"->main(me, arg)`。本库把这条指令改了名（`cmds/skill/study.lpc`，代码和别的库的 `du.lpc` 相同，用法行写着 `study|du`），`du.lpc` 不存在，读书就是一条 `couldn't find object`。改成 `"/cmds/skill/study.lpc"`。

## `mapp`：全局变量不能写 `varargs`（2026-10-21，KB 04 §6.28）

`varargs mixed m;` 和 `varargs string *rfile;` 是 `mapp` 指令的两个全局变量，本驱动只允许函数用 `varargs`（`Illegal to declare varargs variable.`），指令编译不了。去掉两处 `varargs`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 商人基类 `do_buy()`：替别人买东西时提示读没赋值的 `ob`（2026-10-21，KB 06 §7.348）

买家 `who` 不是 `this_player()` 且身上超过 35 件东西时，提示写的是 `ob->name() + "身上已经太多东西了"`，`ob` 没赋值：改成 `who->name()`。改动：`/feature/dealer.lpc`、`/feature/jh_dealer.lpc`、`/feature/ty_dealer.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 79 条注册（38 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/ling.lpc`（`do_drop`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/qn.lpc`（`do_push`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/feitian/npc/biguqing.lpc`（`do_accept`）、`/d/pipip/diablo.lpc`（`do_climb`）、`/d/player/yysz/hupan.lpc`（`do_han`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`） 等共 38 个文件。最多的函数名：`do_kill` 20 处、`do_send` 16 处、`do_bihua` 8 处、`do_halt` 8 处、`do_decide` 7 处。没有动（读过）：`/clone/obj/job_server.lpc` 的 `do_job_clear`（对象本身编译不过，登记留着，等对象能加载再处理）、`/clone/obj/job_server.lpc` 的 `do_job_hist`（对象本身编译不过，登记留着，等对象能加载再处理）、`/clone/obj/job_server.lpc` 的 `do_job_stat`（对象本身编译不过，登记留着，等对象能加载再处理）、`/clone/obj/job_server.lpc` 的 `do_set_exp_limit`（对象本身编译不过，登记留着，等对象能加载再处理）、`/clone/obj/job_server.lpc` 的 `do_set_pot_limit`（对象本身编译不过，登记留着，等对象能加载再处理）、`/clone/obj/job_server.lpc` 的 `do_job_info`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/weapon.lpc`（`do_duanlian`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 4 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（9 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 9 个函数没有补（other 4, inquiry 3, chat_msg 1, item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/clone/obj/job_server.lpc`:`compare_exp`、`/clone/obj/job_server.lpc`:`compare_pot`、`/clone/obj/job_server.lpc`:`compare_name`、`/clone/obj/job_server.lpc`:`compare_number`、`/d/city/npc/zhuziliu.lpc`:`give_job`、`/d/city/npc/zhuziliu.lpc`:`task_ok`、`/d/feitian/npc/luo.lpc`:`kungfu_asked1`、`/d/feitian/npc/shiren.lpc`:`away`、`/d/yihua/lianhuachi.lpc`:`look_CAI`。 另有 2 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 4 个文件里 5 行只含这个指针的行（`"table": (: look_table :),` `"scoreboard": (: look_scoreboard :),` `"杀": (: kungfu_asked1 :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 22 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 22 处（15 个文件）：拼名字的赋值 11 处、与汉字常量比较 11 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:101`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:107`）；`chk[0..1] == "你"` → `chk[0..0] == "你"`（`/clone/npc/ganjiang.lpc:535`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：28 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 28 处（14 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/adm/simul_efun/logind.lpc:1318`）；`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/clone/npc/luban.lpc:1767`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 13 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 1 处（1 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 5 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 4 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。


## 圣舍利 ssl 条件被写坏（2026-10-27，KB 04 §6.25 Also）

`d/pipip/ssl.lpc`（或本库 `d/system_2/ssl.lpc`）的 `do_xi` 有一行 `if me->("neili") > ("maxneili)*2)`：缺 `if (`，且 `"maxneili` 未闭合，下一行中文 `notify_fail` 被当成源码（`Illegal character`），物件无法加载。同库 `d/ygbz/obj/ssl.lpc` 完好。上面两行已取了局部变量 `neili`/`maxneili`，改为 `if (neili > maxneili * 2)`。证明：HEAD 加载失败；改后加载成功。


## jinyong 丢了 query 字符串收尾引号（2026-10-27，KB 04 §6.25 Also）

`quest/quest2/jinyong.lpc` 两行 `who->query("max_jingli))`：`"max_jingli` 未闭合，字符串吃掉下一句，怪的 jingli 未按玩家 max 设置。改为 `query("max_jingli")`。证明：HEAD 源码为破引号；改后为正确键；物件两端均可加载。

## 炼丹室 liandan 无法加载（2026-10-27，KB 04 §6.25 Also）

`d/zjb/liandan.lpc`（wlhd / yxjh 为 `d/rock/liandan`）：14 处 `delete_temp("zhuyao)` 缺收尾引号，1 处 `new(/d/.../obj/yao")` 缺开引号，后续中文 `notify_fail` 被吞成 `Illegal character`。补齐引号。`if (shoubi = 27&&zhuyao=3)` 一类赋值当条件、以及 `/u/.../yao/` 目标未动。证明：HEAD 加载失败；改后加载成功。

## 炼丹室 liandan 赋值当条件（2026-10-27，KB 06 §7.290 Also）

接 §6.25 补引号之后：`if (shoubi = 27&&zhuyao=3)` 等 8 处（`tui` / `all` 同形）把 `=` 写成了 `==` 的意思，非零局部变量时分支恒真，配方判断乱套。`lpc_fix_cond_assign.py --apply` 改成 `==`（zxty / zxty08nxgbb / tybxjh 的 `d/zjb/liandan`，wlhd / yxjh 的 `d/rock/liandan`；共 40 处，残留 0）。证明：HEAD 源码仍是赋值；改后是比较；对象仍可加载。

## set("long" 丢引号（2026-10-27，KB 04 §6.25 Also）

`set("long",` 后直接跟汉字（无 `"` / `@LONG`），驱动报 Illegal character。用同路径完好手足覆盖（fyue_room←jhfy；hudi5/6←zxty08nxgbb；quanzhen_old/hudi*←xyzxfy2）。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 zmud/dan 去引号）

`u/zmud/dan` 整文件去引号；按 `clone/misc/dan` 重写（保留档案的 exp/40 与「小刀」日志）。

## 深度功能测试（2026-10-27，§6.25 d/city/sj 去引号）

`d/city/sj` 整文件去引号（`add_action(do_out, out)` 等）；按 jhfy 完整副本替换。

## 深度功能测试（2026-10-27，§6.25 zhongling tell_object 引号错位）

`d/wanjiegu/npc/zhongling`（及同路径副本）的 `tell_object("who, 钟灵脱下一双绣花鞋。\n")` 把对象参数写进了字符串；改为 `tell_object(who, "…")`。证明：原文错位；改后加载，语料残渣 0。

## 深度功能测试（2026-10-27，§6.25 tell_object 缺 me（自动放弃/愿否））

一参 `tell_object("…")` 在已有 `me` 时改为 `tell_object(me, "…")`（city.lpc）。证明：抽样 city / xiaolongnv 加载。

## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。

