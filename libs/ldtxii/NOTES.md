
## 深度功能测试（第二轮，2026-08-03）

之前只测过注册流程 + look→score→quit 的浅层验证，本轮做了完整的
§10.7 深度功能测试。proactive 检查 AGENTS.md 已归档的四类常见坏味
道，命中了两类：`logind.lpc` 里的 printf("%O") 调试残留，以及
§8.9 那个坏 age 判断——两处都和姊妹档案 `ldtx` 在完全相同的行号上
一字不差，说明这是从 `ldtx` 继承下来、从未修过的祖传 bug，不是这
份档案自己独立引入的。

**发现并修复的两个真实 bug（`ldtx` 有完全相同的未修副本，已在
AGENTS.md §7.34/§8.9 里记录"下次碰 `ldtx` 要顺手补上"）：**

1. `logind.lpc` 的 `get_name()` 有一行调试用的 `printf("%O\n",
   ob)`，紧挨在把中文名字写入角色之前，每个新玩家注册时都会看到
   （AGENTS.md §7.34）。已删除。
2. 食物/饮水满值初始化的判断条件是 `!user->query("food") &&
   !user->query("water") && ob->query("age") == 14`——前两项读
   `user`（玩家身体），最后一项却读 `ob`（登录连线物件，全库没有
   任何地方给它设过 age），条件永远为假，每一个新角色食物/饮水槽
   永远是空的（AGENTS.md §8.9 第四个确认实例）。已改成
   `user->query("age")`。用新角色对照验证：修复后食物/饮水槽创建
   时即为满值（16/16格）。

顺带核实了一处一开始看起来很可疑的地方：登录横幅、BBS 链接、系列
主页等文字通篇写的都是"雄霸天下"，和这份档案的标题"鹿鼎天下II"完
全对不上。全库搜索"韦小宝/神龙教/康熙/鹿鼎"命中 48 个档案（任务
线、门派设定等），确认游戏内容确实是《鹿鼎记》题材，标题和
README 的定性没有错——只是登录横幅本身是从"雄霸天下"引擎模板直接
抄来的通用文案，作者重新包装时没有替换，属于 AGENTS.md §5.1 早就
归档的"config `name` 字段陈旧复制粘贴"同一类现象，只是这次出现在
运行时横幅里而不是 config 字段里，没有去动它。

**完整流程验证**：注册全新角色（沐鹿鼎/id `ldtdive`），从"客店"起
步，向西走到"北大街"（遇到金庸《射雕英雄传》客串角色"白驼山少庄主
欧阳克"，跨小说串场是这批档案常见的手法），向南到"中央广场"，向
"流氓头"发起战斗——完整交手多回合后被打倒昏迷（"你的眼前一黑，接
著什么也不知道了"），昏迷状态下所有指令（包括`score`）都短暂返回
通用的"什么？"提示，一度让人怀疑指令分发坏掉；但重连后确认角色其
实是自动复活到了"武庙"（岳飞庙，血量从满血跌到 1/100 正在自然回
复），`look`/`score`工作完全正常，死亡次数/死因（"最后一次死于
[流氓头]之手"）、潜能/经验值扣减都正确记录——是正常的"重伤昏迷→
自动送医复活"死亡惩罚机制，不是 bug，只是短暂昏迷期间指令被挡的
提示信息看起来容易让人误判。`quit`干净退出。全程 debug.log 零报
错。

**未覆盖范围**：银行存取款、拱猪赌场小游戏、拜师、门派加入因时间
原因未实测。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

ldtx 的手足档案（同一个 Century/adm-single 家族，同一套架构，内容大部分不同——不是重复压缩包）。WASM 修复：修复了 adm/simul_efun/chinese.lpc 的 is_chinese() 里经典的 §8.1 GBK 字节区间 bug（str[0] > 160 && str[0] < 255——一个 GBK 首字节判断，在这个驱动上会拒绝所有真实中文字符，因为中文码点是 0x4e00-0x9fff，远超过 255；已换成正确的码点区间判断）。另外掏空了 adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/socket_close()（§7.52），和 ldtx 完全相同的修法——同样的未定义 socket efun 失败破坏了每次连线在英文名字提示之前的 encoding_to_mudlist() 步骤。check_legal_name() 的 i%2==0 隔字检查存在但无害（和 ldtx 一样）。通过 adm/etc/wizlist 把 fluffos/Mud2026Adm 播种为 (admin)——和 ldtx 不同，这份档案没有更早一轮遗留下来的既有管理员账号或 README，所以没有 id 冲突需要处理。留下一处真实存在、不阻断的内容缺口未修：d/city/chatroom.lpc 的物件列表引用了 /u/mouse/topten，这个巫师目录在整个档案里根本不存在——某个 NPC 的 heart_beat 驱动的 random_move 走进这个房间时，make_inventory() 对这个缺失档案呼叫 new() 会失败，之后对结果 0 做 ->move() 就会崩溃，和 ldtx 的 xiaobao.lpc 情况（以及更广泛的 sj.lpc 先例）是同一类缺失内容——按惯例保持原样，没有凭空捏造替代内容。完整的注册（gb→id→确认→中文名字→密码→确认→天赋'0'→接受'y'→电子邮件→性别）和 look→score→quit 流程在排版格式化前后都验证过；格式化工具没有引入任何损坏（三类盲点检查都干净）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`WIZ_BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 34 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

上面"第二轮"（2026-08-03）那次早于今天的驱动重建（全库
`quest_times`/`win_times` `%`-operator 修复 + Warning/warning 驱动
文本回退），不能算作针对当前驱动的覆盖——这是真正针对今天驱动的重
测。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查
   （AGENTS.md §7.34-class，本轮反复确认的形状）**：`if
   (this_player(1)) efun::write(...)`——不区分巫师/玩家，也不区分
   警告/错误。修复：加上 `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`，CRLF 行尾档案）完全没
   有 `assure_file()` 保护（AGENTS.md §7.11-class 的又一确认实
   例，比本轮此前见过的所有实例都更严重）**：`adm/daemons/
   logind.lpc` 的 `get_passwd()`（**每一次密码提交，不只是新角色
   注册，包括普通老玩家的日常登录**）第一行就调用
   `log_file("buglog/npc_save", ...)`——`LOG_DIR` 下的 `buglog/`
   子目录若不存在，会在**每一次**登录尝试（不管新号老号）未捕获
   抛出，比 `ffxymud`/`hc`/`jhfy` 那些"只在新角色注册最后一步"触
   发的实例影响面更大。已补上 `assure_file(LOG_DIR + file);`
   （含前向声明，CRLF 行尾用 Python 字节级替换保留原格式，未破坏
   行尾风格）。

### 更正（2026-08-13）：明文密码写入日志问题已修复

上面记录的"未做任何改动"已过时——按用户指示已修复。`get_passwd()`
那一行 `log_file("buglog/npc_save", sprintf("%s%s login from %s
%s\n", ob->query("name"), ..., pass, ctime(time())))` 把玩家刚提交
的明文密码原样写进了日志文件，每次登录尝试（不只是失败时）都会触
发。已改为不记录密码本身，只保留"谁在什么时候尝试登录"这部分原本
就有诊断价值的信息：`log_file("buglog/npc_save",
sprintf("%s%s login attempt from %s\n", ob->query("name"), ...,
ctime(time())))`。已用真实登录复测：新写入的日志条目不再包含密
码，旧条目（这台开发机本地的、从未被提交到仓库的 gitignored 日
志文件里）依然保留着修复前的明文密码，不受影响也无需清理（不在版
本控制范围内）。

### 一个额外的注册流程排查记录（非 bug）

`logon()` 之后的 `encoding_to_mudlist()` 在处理完编码选择、打印
mud 列表之后，会额外要求一次"Press Enter to Continue..."才真正进
入 `login()`（进而才是 `get_id`）——这一步很容易被漏发送导致后续
所有输入错位（第一次尝试时 `fluffos` 被这一步吃掉，后续所有输入
都被当成非法英文 id 反复重问）。已确认这是这份档案自己的真实流程
形状，不是 bug，只是测试时容易踩的坑，记录下来供未来复测参考。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:176`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。
- `check_legal_name()` 沿用旧版 GBK 字节长度界（`strlen(name) <
  2 || > 10`，按字节而非字符数），普通 2 字中文名字（6 字节）仍在
  范围内可以正常使用，4-5 字长名字会被误拒——已知的 §8.1 类问题，
  本轮未修改（不在这次任务的标准检查范围内，如实记录）。

### 实测过程

管理员账号 `fluffos`/`Mud2026Adm`——README 记录"已在游戏内确认"，
但 `git log`/本地文件都确认从未真正提交过存档。已用真实注册流程
（GB/BIG5 选码 → Press Enter 继续 → 英文 id → 确认建立 → 中文名 →
密码 → 确认密码 → 天赋 0 随机 → 接受 → 邮箱 → 性别）重新创建，
`score` 确认"目前权限：(admin)"（这份档案的 `wiz_status` 不是
`nosave`，注册后立即拿到权限，机制上比 `hy`/`fqyy2` 那类更简
单），`update /adm/simul_efun/file`（就是本轮改过的文件）确认可正
常重新编译。全程未生成 `debug.log`（说明真的零运行期错误，不是文
件被清空）。驱动最终按精确 PID kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。
- `data/{login,user}/l/ldtdive.o` 是此前会话遗留的未提交测试存档
  ——`Aug 3` mtime，早于本次会话，未受本轮任何操作影响，未触碰。

## §7.100 sweep (2026-08-19): redundant `replace_program(ROOM);` landmine

Same corpus-wide bug as documented at AGENTS.md §7.100: rooms
inheriting `ROOM` (`/inherit/room/room`) had a redundant, harmful
`replace_program(ROOM);` call right after `inherit ROOM;` in `create()`,
setting a permanent "pending replace" flag that crashes the object the
first time anything binds a closure to it. This lib had **1,516 live
occurrences** (survey-ranked #88 of 166 candidates >=100, tied with and
sharing the same 雄霸天下/LDJ lineage as `ldtx`). Fixed with the
sweep's binary-mode script (`fix_710_room.py`); `git diff --numstat`
totals (0 insertions, 1516 deletions) match the survey's
live-occurrence count exactly. Like `ldtx`, this lib's
`clone/misc/roommaker.lpc` room-building tool never had the
factory-bug variant — its generated-room templates never included a
`replace_program(ROOM)` call. No `work/data/` room-source
false-negative found. Verified via a clean `build-debug` boot (zero
"cannot replace"/"cannot bind" `debug.log` lines, port 40176 listening)
plus a live admin login (`fluffos`/`Mud2026Adm`, GB encoding
selection, `Press Enter to Continue` banner) — entered the game world
normally, `look`/`quit` both worked, `debug.log` stayed clean
throughout. Incidental admin save-timestamp drift from the spot-check
reverted before committing; only the two tracked `fluffos.o` files
were touched, the pre-existing untracked `ldtdive.o` save files were
left alone.

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/wgargoyle.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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

## 深度功能测试补完：银行、赌场骰子、拜师 (2026-08-23)

按上面第一轮"未覆盖范围"清单补测了银行存取款、赌场骰子小游戏、拜师
三项，均为真人游玩（`fluffos`/`Mud2026Adm` 管理员账号）+ 新起的
`build-debug` 驱动。

### 发现并修复：AGENTS.md §7.30 第二形状（call-site indexing）在
### ldtxii 里再现，6 处未防护崩溃点

手足档案 `ldtx` 的 round-four 测试（AGENTS.md §7.30 结尾那段"Note:
the SECOND shape ... currently a single confirmed instance"）已经记
录过这个坑：`attempt_apprentice(object ob)` 里 `mapping ob_fam =
ob->query("family")`——对从未拜过师的角色，`query("family")` 合法
地返回裸 `int 0`，不是 `mapping`。凡是紧接着不加 `mapp()` 防护就
直接 `ob_fam["xxx"]` 取值的写法，第一次被没有门派的角色 `bai` 都
会崩溃。

`ldtxii` 和 `ldtx` 同一血统（`work/` 内容基本相同，逐文件核对确
认byte-identical的形状），先用 `grep -rn 'ob_fam\['` 扫过全部含
`attempt_apprentice` 的候选文件，绝大多数已经有
`if (!(ob_fam = ob->query("family")) || ob_fam["xxx"] != ...)`这种
赋值+短路防护写法（安全），但下面 6 个文件和 `ldtx` 当时揪出来的
一模一样，完全没有防护：

- `kungfu/class/shaolin/qing-wei.lpc`
- `kungfu/class/shaolin/qing-wu.lpc`
- `d/quanzhen/obj/mayu.lpc`
- `d/quanzhen/npc/mayu.lpc`
- `d/quanzhen/npc/wangchuyi.lpc`
- `d/quanzhen/npc/qiuchuji.lpc`

修法和 `ldtx` 一致：`mapp(ob_fam) &&` 短路防护，单行改动，逐文件
用 Python 字节级替换只动目标那一行（Edit 工具会顺手清掉同文件里
其它行的行尾空格，产生大量无关噪音 diff，改用精确字节替换避免）。

**Live 复现 + 修复验证**：`fluffos` 管理员账号从未拜过师（天然满
足"没有门派"触发条件）。修复前无法测（本来就会崩），直接用修复后
的驱动测：`goto /d/quanzhen/neishi` → `bai ma`（马钰，全真教）→
被以"资质不适合当道士"婉拒，正常走 else 分支，无崩溃；`goto
/d/shaolin/guangchang1w` → `bai qingwei`（清为比丘，少林派）→ 立
即被收为俗家弟子，`score` 确认"称谓：少林派第四十一代弟子"、"你
的师傅：清为比丘"，门派信息正确写入。全程 `debug.log` 未生成（零
运行期报错）。

### 银行（钱庄）存取款：干净，无 bug

`/d/city/qianzhuang` 的 NPC `钱眼开`（`d/city/npc/qian.lpc`）：
`deposit <数量> <货币> / cun`、`withdraw <数量> <货币> / qu`、
`check / chazhang`。用管理员 `clone /clone/money/silver` 15 次（
`COMBINED_ITEM`货币在同一环境内自动合并成一叠，验证了 clone 出的
零散物件确实会自动堆叠），实测 `deposit 10 silver` → 钱庄存款显示
十两白银、身上剩五两；`withdraw 5 silver` → 存款减为五两、
`MONEY_D->pay_player`找零回来的五两和身上原有的五两自动合并成十
两——金额换算全程正确。原本担心 `do_withdraw()`里
`what = "/clone/money/" + what; ... what->query("base_value")`（把
字符串重新赋值成文件路径后直接在字符串上做`->`调用）会不会是
FluffOS 下的驱动误用崩溃点——**实测证明不是 bug**：这台驱动上
`"路径字符串"->function()`会被当成隐式 load + call_other 正常执
行，全程无报错，只是先记录下这处曾经怀疑过的写法，避免以后重复调
查。

### 赌场骰子小游戏：干净，无 bug（未测拱猪，理由见下）

`/d/city/duchang` 描述"楼上是打拱猪的地方"，但拱猪
（`inherit/room/pigroom.lpc`）是标准 4 人对战牌局（`sit
<方位>`凑齐四家才能`deal`），单人管理员账号无法在测试时间内独立
跑通一整局，且拱猪本身走的是纯积分（`pig_score`）机制，`pigroom.
lpc`/`pigd.lpc` 里搜不到任何 `money`/`balance` 相关调用——它不是
一个"钱进钱出"的赌局，和任务描述"验证金钱易手"对不上。改测
`/d/city/dice1`（骰子厅，`npc/dice_thrower.lpc`星哥）的真实押注骰
子游戏：`bet <种类> <银量>`，押"0 3"（3两银子压"小"）。30 秒开骰
+ 后续动画 call_out 链，等了约 45 秒完整看到摇骰结果（5,3,6=14点，
"赔大吃小"，押"小"的这把输了），身上银两如实从十两扣到七两，金钱
如约易手（虽然是输，符合任务里"win or lose 都算通过"的要求），全
程无崩溃、无 `debug.log` 报错。

### 清理

- 管理员 `fluffos` 存档（`data/{login,user}/f/fluffos.o`）：本轮
  测试留下的门派归属（少林派）、剩余七两白银属于正常游玩产生的状
  态变化，按此前几轮的既定做法随存档一起提交，不做人为清零。
- 未触碰此前遗留的未提交测试存档
  `data/{login,user}/l/ldtdive.o`（`ldtx`-era 遗留，与本轮无关）。
- 用于对照的 `lpcc_check.sh` 中间产物（`lpcc_fail.log`、
  `lpcc_batch_raw.log`）测试后已删除，未提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py ldtxii --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 82 个 `.lpc` 和 4 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：71 -> 71 通过，无回退；改过的头文件的 7 个包含者 5 -> 5 通过。启动时警告 2 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 10 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 2 个文件；改动 9 个文件，HEAD 与工作树各载入一次无回退（9 objects; HEAD PASS 8, tree PASS 8; regress 0; newly loading 0），这些文件的警告 11 -> 1。

- 2026-10-12：明教 `d/mingjiao/npc/yinwufu`、`yinwulu`、`yinwushou` 连写了两行 `inherit F_UNIQUE;`，驱动报 `Illegal to redefine 'nomask' function 'violate_unique'`，这三个 NPC 从来载不进来（xiakexing3/xkxlb 同日同修）。删去重复的一行后三个都能载入（HEAD PASS 0 → tree PASS 3）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 10 处多余继承，`d/shenlong/ma.lpc` 补上 `ask_me()` 原型。能编译的文件警告清零；改动的对象在 HEAD 与工作树各载入一次（11 objects; HEAD PASS 9, tree PASS 9; regress 0; newly loading 0）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：22 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：25 个对象，新增载入 23，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。20 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 2 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 6 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`huanhua-jian/snow`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`/d/mj/skill/jiuyang-shengong`、`guiyuan-dafa`、`honghua-shengong`、`jiuyang-shengong`、`taiji-shengong`、`tiangang-zhangqi` 等 9 个文件）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）。

## 文件首行注释少了一个斜杠（2026-10-15）

首行的说明注释只剩一个 `/`（如 `/kuangwu.c金蛇狂舞`、`/ cloth.txt  //`），文件第一行就语法错误、编译失败：全真教的布衣 `/d/quanzhen/obj/cloth`、`/d/quanzhen/npc/obj/cloth` 因此从来载入不了。补回斜杠成为 `//` 注释，现在都能载入。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。14 处（12 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变（`kungfu/skill/hebi.lpc` 是放错位置的同一文件，不在绝招路径上，一并改正）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

16 个文件、27 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/u/csy/kunlun/obj/cloth`、`/u/csy/kunlun/obj/sword`、`/u/csy/kunlun/obj/cloth.lpc`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 16 个（16 个原来载入不了），没有退步。

## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`SSERVER` → `/inherit/sserver`（2 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：2 个里 2 个通过。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（4 个名字，最多的是 `kongmingquan`、`tiangang-jian`、`xingxiu-duzhang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 7 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/huanhua/podi` 的 `southwest`：`/d/dali/road7` → `/d/dali1/road7`；`/d/kunlun/liangong` 的 `south`：`sanshengtang` → `shanshengtang`；`/d/mingjiao/jmqshulin6` 的 `west`：`jmqjiguan` → `jmqshenmu`；`/d/wudang/wdroad1` 的 `west`：`/d/dali/dadao1` → `/d/dali1/dadao1`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/feature/banker`（宏 `F_BANKER`）←hc，1 个对象继承它，抽样 1/1 载入；`/inherit/weapon/stick`（宏 `STICK`）←yxcs，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 11 处、7 个文件：`kongmingquan`→`kongming-quan`（10 处）、`poyu-qua`→`poyu-quan`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/shashou/enterance.lpc` 的 `south` 出口：`/d/dali/dadao1` → `/d/dali1/dadao1`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `d/biwu/wudao4.lpc` 删掉 `"/u/lzd/biwu_b"->foo();`（巫师的留言板不在档案里，调用失败会让房间载入不了）
- `d/wizard/arch_room.lpc` 删掉 `call_other("/u/jiudai/arch_b", "???");`（同上）
- 27 个 NPC 文件、40 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）
- `d/city/npc/wei.lpc` 对巫师目录里的衣服 `/u/rhxlwd/xueyuetu` 的 `->wear()` 加上判断（姊妹档案 ldtx 已是这样写）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 6 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/quanzhen/hudi3.lpc`（ldtx）、`/d/quanzhen/hudi4.lpc`（hy3）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/kungfu/skill/yanxing-dao.lpc`（syxjl）、`/quest/baituo/qlist3.lpc`（xyzx3）、`/quest/xingxiu/qlist0.lpc`（ffxymud）。修后与 HEAD 逐个对比载入：这 6 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 4 处）。改动：`/adm/daemons/logind.lpc`（2 处）、`/adm/daemons/logindnew.lpc`（2 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。
