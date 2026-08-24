
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
