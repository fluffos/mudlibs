
## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云Ⅳ，古龙小说题材 MUD。同时修复了 is_chinese()（字节区间判断+要求 strlen>=2）和 check_legal_name()（长度界限和错误提示自己声明的 1-5 字符范围对不上，外加按字节步进的 i%2==0 尾部切片循环）里经典的 §8.1 中文名字 bug——会静默拒绝所有真实中文名字，包括标准的两字测试名。GB/BIG5 编码选单两个选项都实测过，画面正常，这里不是真实存在的 bug。排版格式化工具的第三类盲点检查在少数几个"误报"里抓到了一处真正的损坏（daemon/damage-1.lpc，一份纯文本战斗记录数据表被压成一行并加了空格）——已还原。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## 深度功能测试（§10.7，2026-08-04）

此前只验证到注册流程本身（含中文名字 bug 修复的回归确认），本轮原生
driver（端口 40165）走完了完整的游玩会话：移动、商店、留言板、战
斗、死亡、无人打扰的完整复活。

**主动检查（对照 AGENTS.md 已归档的 bug 类）**：全文搜索 `printf(`
未发现 §7.34 遗留调试输出；`command_hook` 未发现 `private` 违规
（用 grep 确认唯一定义处已是标准写法）；未发现 §8.9 的错误对象
age 判断变体。

**新发现并修复：第 12 例 §7.68 复活软锁死**（`d/death/npc/
panguan.lpc`，鬼门关的"朱笔判官"——文件头注释写着 `// TIE@FY3`，
说明这份文件的血统其实来自风云Ⅲ 系列，和本项目里 `fy330`/`fy2mg`
两份档案共享同一个原始判官 NPC 设计）。原判断把四个条件全部塞进一
行提前 return：`if (!ob || !present(ob) || !ob->is_ghost() ||
(int)ob->query("combat_exp") > MAX_EXP) return;`——`!present(ob)`
（玩家暂时不在场）和另外三个"应当永久放弃"的条件（对象已销毁、已
经不是鬼、战斗经验超过判官能处理的上限）被错误地合并成了同一种
"永久放弃"。已拆分：`!ob` 单独永久放弃；`!present(ob)` 改为 5 秒
后重试（标准修法）；`!ob->is_ghost() || combat_exp > MAX_EXP` 保留
为永久放弃（这两个条件本来就该是"这个判官不负责处理你，交给别的
机制"，不是暂时性问题，和 `fy330` 自己那份判官文件当初的处理方式
一致）。另外确认了同目录的 `panguan2.lpc`（生死判官）和
`greengirl.lpc`（绿珠，非死亡流程但也有一个 `call_out` 链）看起来
形似但**不是**同一类 bug：前者的 `death_stage()` 是一次性检查（活
人误闯深处地狱会被攻击），没有多阶段重试逻辑，玩家离开后什么也不
发生就是正确行为；后者的 `next_stage()` 同理，`environment(me) ==
environment()` 判断失败时安静放弃也是设计如此——两者都没有"卡死
鬼魂"的风险，未改动。

**完整游玩记录**：
1. 用真实中文名"沈牧"（id `shenmu`）注册成功，落地"凤求凰客栈"
   （唯一出口 west）。
2. 移动：客栈→广场南→玉龙珠宝店（`list` 正确显示玉指/玉簪/玉花/
   玉镯四样商品和价格）→广场南→风云天下（中心广场）→广场北，沿
   途场景描述、出口、NPC 列表均正常渲染。
3. 留言板测试：风云天下的"盘龙摩天柙(Stone)"是一个真正的公共留言
   板（`/std/bboard.lpc`），`read 1` 成功读出一条真实留言（标题"第
   一个"，作者"温柔杀手"）——注意指令格式是 `read <编号>`，不是
   `read stone <编号>`（一开始按后者格式试过，被 `notify_fail`
   正确拒绝，不是 bug，是命令语法理解错误）。
4. 战斗测试：`kill police`（广场的巡逻士兵）——新手角色一击斃命
   （攻击力/防御力起始只有个位数到两位数，巡逻士兵明显不是新手该
   招惹的对象，纯粹是数值/内容现象，不是 bug）。死亡后正确落地
   "鬼门关"，朱笔判官/牛头/马面均在场。
5. 死亡→复活验证（**两轮**，第二轮是应用 §7.68 修复并重启 driver
   之后做的回归验证）：**在完全不打断的情况下**（发送战斗指令后立
   即断开，等待约 20 秒让 `call_out` 链自行走完，再用一条全新连接
   静默重连查看落地位置）确认：判官的四段对话依次播放完毕，
   `reincarnate()` 成功，角色最终随机落地 `revive_loc` 两个复活点
   之一（本次落在"天主教堂"），`score` 正确显示"你总共杀了零个
   人...被杀了一次"。**这正是修复后应有的行为**——如果没有这次拆
   分修复，任何一次连线中断都会让鬼魂永久卡在鬼门关。
6. `quit` 正常退出，退出前正确丢弃了随身衣物（死亡惩罚的一部分，
   内容行为）。

**结果**：整个测试会话（含两次死亡复活循环）`debug.log`
除了已知的、和本次测试无关的沙盒环境噪音（`init_addr_server`/
`socket_write` 的 DNS/UDP 权限拒绝，属于 §7.6 一类的沙盒网络限制，
不是这次改动引入的）之外没有任何 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录；本轮测试专门清空过一次
`debug.log` 以确认这一点，测试期间该文件全程为空。测试角色存档
（`data/{login,user}/s/shenmu/`）保持未跟踪；`panguan.lpc` 的改动
已用 formatter 校验（`{"errors":0}`）。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 9 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,180 处存活匹配，全部标准独立行形式，脚本一次
  性删除，无不规则残留。没有房间生成类工具（`roommaker`/`makeroom` 均未
  找到），不涉及工厂模板修复。`data/` 下额外核查过，无命中。验证：真实
  debug 驱动干净编译启动、端口正常监听，`debug.log` 无新增 "cannot
  replace"/错误行。

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

## 深度功能测试（§10.7，2026-09-01，第二轮）

角度：这次专门补测上一轮（2026-08-04）明确跳过的部分——真实的商店
买卖交易、拜师门派流程、信箱/寄信系统，以及沿途新走的房间是否触发
§7.19 一类的 NPC `init()` 重入 bug。原生 debug driver（端口 40165），
用纯 Python socket 脚本全程操作（未用 `tmux_mud.sh`）。协议层确认：
这个 lib 的连线是 **UTF-8**，不是 GBK（草稿脚本一开始按 GBK 编码送
字符导致中文名字连续判定失败，换成 UTF-8 后正常）。

1. 用真实中文名"沈秋"（id `muqiuxia`）注册成功，落地"凤求凰客栈"。
2. **管理员账号补注册**：发现 meta.json 里记录的"fluffos/Mud@2026
   已通过真实注册流程播种"其实不准确——`adm/etc/wizlist` 里虽然列
   着 `fluffos (admin)`，但 `data/login`/`data/user` 下根本没有这个
   账号的存档（甚至连 `f` 字母桶目录都不存在）。重新用正常注册流程
   走了一遍（id `fluffos`，密码 `Mud@2026`），因为在 wizlist 里，注
   册完直接拿到 `(admin)` 权限。之后用这个号 `goto`/`summon`/
   `clone`/`give` 给测试角色发测试用的黄金。
3. **商店买卖交易（此前只测过 `list`）**：玉龙珠宝店（`d/fy/yuljade.
   lpc`，掌柜"商玉龙"）`buy 玉簪 from jadeseller` 成功购买，价格、
   找零（黄金/银子/铜钱换算）都正确；千银当铺（`d/fy/qianyin.lpc`，
   老板娘"香菱"，`feature/pawnowner.lpc`）`value`/`sell` 也验证成
   功，按物品价值的 80% 换算成实际钱币正确发放。注意：这两个指令走
   的是 `present()`/`id()`，只认物品的英文 id（如 `jade pin`），不
   认中文名字"玉簪"作为参数——直接拿中文名字当 `sell`/`value` 的参
   数会被判定为"没有这样物品"，这不是 bug，是这个 lib 全局一致的物
   品寻址规则（`feature/name.lpc` 的 `id()` 只查英文 id 数组，`buy`
   指令之所以能认中文名字，是 `feature/vendor.lpc` 里 `buy_object()`
   自己额外加了一条按 `name()` 比较的特例，不是通用规则）。
4. **拜师门派流程**：`d/fy/jbang.lpc`（帮主堂，金钱帮总舵）的
   "荆无命"（`d/fy/npc/jinwuming.lpc`）`attempt_apprentice()` 无条
   件接受拜师，用 `apprentice master jin` 一次成功拜师，`score` 正
   确显示"金钱帮 帮众"和"你的师父是荆无命"。
5. **信箱/寄信系统**：风云驿站（`d/fy/mailst.lpc`）的"王风"
   （`officer.lpc`）`ask officer about mail` 成功领取信箱（`obj/item/
   mailbox.lpc`），`mail muqiuxia` 给自己寄信（标题+正文，用 `.` 结
   束编辑，`n` 选择不留副本）成功，`from`/`read 1` 都能正确读出刚
   寄出的信。这个 lib 没有独立的 `tell`/频道类指令入口可测（未找到
   `cmds/usr/tell.lpc` 或类似文件）。
6. 沿途新走的房间（`swind2`/`swind3`/`swind4`/`qianyin`/`jinqian`/
   `jting`/`jhuang1`/`jbang`/`wcloud1`/`wcloud2`/`mailst`，均为上一
   轮未到过的区域）里的黄衣卫、王风、香菱、荆无命、上官金虹等 NPC
   首次编译加载时 `debug.log` 全程干净，没有出现 §7.19 一类的
   "Too deep recursion"。

**新发现并修复（真实 bug，非设计选择）**：`std/money.lpc` 的
`query_autoload()` 被注释掉了（`autoload(string param)` 接收端完整
存在且能正常工作，但登记端整行被 `//` 注掉），导致 `cmds/usr/
quit.lpc` 把所有随身货币都误判成"不支持 autoload"，每次正常 `quit`
都会把身上的黄金/银子/铜钱直接丢在退出时所在的房间地板上（公共场
所，任何路人都能捡走），而且下次登入也不会恢复——这不是断线/net-
dead 的边缘情况，是**每一次正常 `quit` 都会触发**的通用逻辑。追到
`raw/fy4_S/fy4/std/money.c`，确认这行注释在原始风云Ⅳ源码里就已经
存在，不是这次转换引入的；但这明显是真实的程序 bug 而不是设计选
择——全库跨库搜索发现同一行 `string query_autoload() { return
query_amount() + ""; }` 在几十个非风云系血统的 lib 里是**启用状态**
（原样一字不差），只有风云系血统的档案带着这行被注释掉的版本，说
明这就是别的血统早就修过、风云系一直没修的同一个 bug。已取消注释，
用管理员账号发钱给测试角色、`quit`、重新登入验证：修复后 `quit`
正确打印"黄金化成一蓬粉末消失了"（走 destroy-and-reconstruct 分
支，不再是"你丢下一些黄金"），重新登入后 `i` 正确显示黄金金额原样
恢复。已加入 AGENTS.md §7.199。

**跨库扫描（同日）**：grep 全部 lib 的 `std/money.lpc`，发现同样被
注释掉的这一行一共命中 16 个 lib（全部是风云系血统）：`fysjmb`（本
lib，已实测验证）、`fengyun434`、`fy2`、`fy2005`、`fy2mg`、`fy2qh`、
`fy330`、`fy3dz`、`fy3xd`、`sjpl2`、`sjplgfjxb`、`sjplii`、`wqfy`、
`xsfyssjb`、`zzfy`、`zzfy3`。其余 15 个用同一处单行取消注释修复，
逐一用 `lpcc config.fluffos /std/money` 做了针对性编译检查，全部干
净通过；未对这 15 个做完整 §10.7 深度游玩测试或整库重启验证，符合
本项目"一个 lib 实测确认、其余同款 lineage 机械扫描 + 编译检查"的
既有惯例。

**结果**：本轮测试期间 `debug.log` 除已知的编译期"unused local
variable"一类警告（首次加载各文件时会广播到当前连线的屏幕上，是正
常的懒编译提示，不是错误）之外，没有出现任何 `error:`/`Bad
argument`/`No program`/`Too deep recursion`/`FATAL` 记录。测试角色
存档（`data/{login,user}/m/muqiuxia/`）与管理员测试号
（`data/{login,user}/f/fluffos/`）均保持未跟踪。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— compile-warning pass (ported from fengyun434)

`scripts/lpc_warnings.py fysjmb` (8359 files): 2321 distinct diagnostics and 47 files that did not compile at the start, 82 diagnostics and 45 files at the end (7630 compile;
the six files below and the `tail()` command compile after that scan, checked individually). 876 files changed. This lib is a different build of the Fengyun code than
fengyun434 (about 700 files differ), so the root's pass was ported where the code is the same (`lpc_twin_port.py adopt fengyun434 fysjmb`: 496 reformatted, 174 verbatim, 1
spliced) and the rest was scanned on its own; `scripts/lpc_family_pass.py` ran the tools (KB 04 §6.10, the 87 prototypes for functions called before their definition).
It has no `.C` files: `scripts/lpc_case_paths.py` found nothing to rename.

**By hand.** `adm/simul_efun/file.lpc` defines `tail()` in LPC (the efun of the MudOS this archive ran on; `cmds/wiz/tail.lpc` called it). `d/biancheng/npc/obj/paper_{1..5}.lpc`
end in a story note that opens with `/*` and was cut off before its `*/`: the comment is closed at the end of the file, the text is unchanged (fengyun434 carries the files without the note).

**What is left (33 files with a compile error; 7 of them are not failing in the root):** the root's list (`ed.c`-style leftovers, the TMI-2 network daemons without headers,
drafts) minus the files its pass fixed, plus `cmds/std/practice_.lpc` and a saved user file `data/login/p/peal/peallkpmpdi.lpc` (damaged bytes).

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. This lib has no wrong-case paths; the change is the one made in the libs whose renames made such NPCs reachable (KB 03 §4.5), and keeps a room loadable when an NPC in its inventory has a content gap: it loads without that NPC. The room base compiles and loads with the change (HEAD against the working tree).

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 1432 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/taskd.lpc`、`adm/daemons/tasknpcd.lpc`、`d/for_suu/tasknpcd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 8 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：3 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/taskd.lpc`、`adm/daemons/tasknpcd.lpc`、`d/for_suu/tasknpcd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 4 个，工作树三次分别通过 4、4、4 个（共 4 个），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 2 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 2 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/tieflag/npc/drinkmonk.lpc` `go_in()`：`for (int i = 0; i < sizeof(enemy); i)` 没有自增，第一个敌人不在同一房间时死循环（直到 eval cost 报错）；改为 `i++`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 编译警告收尾（2026-10-13）

手工清零；改动的 13 个对象在 HEAD 与工作树各载入一次，regress 0。

- 天旗病维摩拳的乾坤挪移 `daemon/class/tieflag/ill-quan/qiankun.lpc` 把施招者的敌人名单存在全局 `nosave object *enemy` 里，与 `F_ATTACK` 的 `enemy` 同名；招式文件是所有玩家共用的一个对象，名单该是 `perform()` 的局部变量，改过去。
- 车夫两处（`d/fy/npc/officer.lpc`、`d/guanwai/npc/waiter.lpc`）计时收回马车的 `check_status` 与 `feature/damage.lpc` 检查昏迷/死亡的 `check_status()` 同名（基类那个本库无人调用，所以没出事）；改名 `check_rental`（连同 `call_out` 字符串）。
- 黄山小姑娘、乌龟、画眉，华山燕子，桃源两只猫的 `kill_ob()`，华山青青的 `die()` 改 `void`，与基类一致（`kill` 命令不读返回值）。
- `daemon/class/yinshi/iceheart/depoison.lpc`（冰心逼毒）多继承了一个用不到的 `/daemon/condition/generic_condition`，它的 `clear_condition*()` 都是对玩家调用的；去掉那行继承。`d/bawang/npc/skill/snake-spear.lpc` 自己的招式表 `action` 与 `SKILL` 的同名，改名 `snake_action`（自带 `query_action()` 读它，行为不变）；`d/fy/npc/newsman.lpc` 在定义前调用 `ask_question()`，补原型。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。4 个文件 9 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 离别剑选目标的笔误（2026-10-15）

`daemon/skill/libie-sword.lpc` 的 `victims[random(sizeof(victim))]` 量的是未赋值的单个 `victim`，总是选第一个敌人；改为 `sizeof(victims)`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：连击之术 `dual-attack` 的 `valid_learn()`（风云的 `query_skill()` 去载入 `/daemon/skill/combat_exp`，报错）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（1 个名字，最多的是 `qingfengsword`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 1 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/neon_playground/grassland` 的 `south`：`shanpo` → `kezhan`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 31 处、13 个文件：`dabei-trike`→`dabei-strike`（12 处）、`qingping-sword`→`qingpingsword`（10 处）、`fumotaff`→`fumostaff`（4 处）、`draginstrike`→`dragonstrike`（2 处）、`cloud-staff`→`cloudstaff`（2 处）、`qingfengsword`→`qingfeng-sword`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## sanniang 的 query(environment(...))->query（2026-10-19，KB 06 §7.266）

`d/biancheng/npc/sanniang.lpc`（边城的三娘）里写成了 `query(environment(this_object()))->query("discussion_shen")`，多了外面一层 `query(`，驱动报 `Bad type for argument 1 of query ( string vs object )`，整个 NPC 载入不了；同一个文件另一处正确写成 `environment(ob)->query("discussion_shen")`。去掉多余的 `query(`。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 2 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/taoyuan/npc/kid.lpc`、`/daemon/condition/idiot.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

4 个文件、4 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/bat/npc/dizi.lpc`、`/d/cave2/npc/dizi.lpc`、`/d/eren2/npc/dizi.lpc`、`/d/eren2/npc/dizi_a.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 2 个文件：`/d/eren2/npc/fighter1.lpc`、`/d/eren2/npc/fightnpc.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：战斗精灵里只该对 hatred / vendetta 出现的追杀提示对所有类型都出现；战斗精灵里只该对 hatred / vendetta 出现的追杀提示对所有类型都出现。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/adm/daemons/combatd-4-17.lpc`（1 处）、`/adm/daemons/combatd-4-20.lpc`（1 处）、`/std/char/questnpc.lpc`（1 处）、`/std/char/questnpc2.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/d/neon_playground/migong/adm/daemons/vrm_server.lpc`（1 处）、`/std/room/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 22 处）。改动：`/d/damage1.lpc`（2 处）、`/d/eren2/npc/obj/key.lpc`（1 处）、`/d/huangshan/jiusi.lpc`（2 处）、`/d/jinan/mjroom.lpc`（1 处）、`/d/jinan/mjroomBUG.lpc`（1 处）、`/d/maze/wood-room.lpc`（1 处）、`/d/resort/teagarden.lpc`（2 处）、`/d/shanliu/npc/xiucai.lpc`（1 处）、`/d/taiping/npc/obj/key.lpc`（1 处）、`/d/yinghe/irongate.lpc`（1 处）、`/d/yinghe/irongate2.lpc`（1 处）、`/d/zangbei/cave.lpc`（2 处） 等 15 个文件。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 任务守护进程启动时崩溃（2026-10-20，KB 06 §7.303）

`quest/dynamic_npc_quest` 有两行写成 `/questnpc/gong.c`、`/questnpc/yannantian.c`，而文件是 `.lpc`（2026-10-05 的 `.c` 行扫荡只处理了 `dynamic_location` / `dynamic_quest`）：`tasknpcd::create()` 启动时报 `Bad argument 1 to EFUN call_other()`。两行改成 `.lpc`。

## `TASKNPC_D` 的路径少了一个 s：`/adm/daemon/tasknpcd`（2026-10-20，KB 06 §7.325）

`include/globals.h` 里 `#define TASKNPC_D "/adm/daemon/tasknpcd"`，守护进程文件是 `/adm/daemons/tasknpcd.lpc`：裸指令 `enroll` 在扫描里打印了 24 次 `call_other() couldn't find object '/adm/daemon/tasknpcd'`（任务 NPC 每次心跳问这个守护进程都是同样的错误）。同一棵树里 `d/for_suu/globals.h` 的写法是对的。改成 `/adm/daemons/tasknpcd`（fengyun434、fysjmb、xsfyssjb 三个飞扬系库同一处）。实测：`enroll` 显示用法，控制台无报错。`QUESTNPC_D`（`/adm/daemons/questnpcd`，`questnpc` 指令用）指向一个所有库都没带的守护进程，属于内容缺失，没动。

## 任务 NPC 逃跑时 `*Undefined function called: do_flee`（2026-10-20，KB 06 §7.259）

`std/char/questnpc.lpc` 和 `questnpc2.lpc` 声明了 `int do_flee();` 并在八处调用，却从来没有定义它（`cmds/std/go.lpc` 里的同名函数带一个 `object me` 参数，是另一个函数）：任务 NPC 在战斗中血量低于逃跑线时，每次心跳都是一条 `Undefined function called: do_flee`（扫描里 42 条，分散在一串无关的指令名下）。同一个文件在 fy2005 里有定义：随机走 3–7 步，`return !is_fighting();`，原样补到两个文件末尾。两个基类和 `d/shanliu/npc/qinge`、`yang` 的加载检查 HEAD 与工作树都通过；`do_flee` 只在战斗逃跑时才会被调用，没有做实战验证。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 88 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/biancheng/npc/bandit.lpc`、`/d/biancheng/npc/tulaohu.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/for_suu/questnpc.lpc`、`/d/for_suu/tasknpc.lpc`、`/std/char/questnpc.lpc`、`/std/char/questnpc2.lpc`、`/std/char/tasknpc.lpc`（共 5 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 41 个存档共 41 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/residence/amine1027580822.o`（1 处）、`/p/residence/amine1027587616.o`（1 处）、`/p/residence/amine1027594915.o`（1 处）、`/p/residence/baby1032108114.o`（1 处）（等共 41 个存档）。

## `questnpc`：悬赏榜守护进程 `/adm/daemons/questnpcd` 档案里没有（2026-10-21，KB 06 §7.299）

玩家指令 `questnpc`（`cmds/std/questnpc.lpc`）调用 `QUESTNPC_D->dyn_evil_quest_list()` 和 `dyn_good_quest_list()`，`globals.h` 里有这个宏，指向的 `/adm/daemons/questnpcd` 哪个档案里都没有，敲这条指令是 `call_other() couldn't find object '/adm/daemons/questnpcd'`（管理员扫描发现；同系的 fengyun434 和 xsfyssjb 里同名的指令是另一条，用 `TASK_D`）。指令开头加 `file_size(QUESTNPC_D + ".lpc") <= 0` 的判断，回一句“目前没有悬赏中的 NPC。”；NPC `d/shanliu/npc/qinge.lpc` 的 `quest_reward()` 调用同一个守护进程，没有动。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 12 条注册（12 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/baiyun/beach1.lpc`（`do_dive`）、`/d/biancheng/npc/oldman.lpc`（`do_vendor_list`）、`/d/fugui/npc/dashuai.lpc`（`do_accept`）、`/d/fugui/npc/robleader.lpc`（`do_accept`）、`/d/huashan/npc/obj/bamboo_cont.lpc`（`do_use`）、`/d/shanliu/npc/taoist1.lpc`（`do_answer`）、`/d/shanliu/npc/yang.lpc`（`do_answer`）、`/d/shaolin/fangnan.lpc`（`do_look`）、`/d/songshan/damocave.lpc`（`do_look`）、`/d/wanmei/woodhouse.lpc`（`do_fillwater`） 等共 12 个文件。最多的函数名：`do_accept` 2 处、`do_answer` 2 处、`do_look` 2 处、`do_dive` 1 处、`do_vendor_list` 1 处。没有动（读过）：`/d/huashan/npc/snake.lpc` 的 `do_train`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/fy/npc/gangster2.lpc`:`goaway`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 9 个文件里有 15 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/PURGE`、`nosave/promotion` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`(: goaway :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 2 处（2 个文件）：拼名字的赋值 1 处、与汉字常量比较 1 处。例：`name[0..1]` → `name[0..0]`（`/d/qianfo/npc/master2.lpc:96`）；`things[0..13] == "天南地北双飞客"` → `things[0..6] == "天南地北双飞客"`（`/d/tieflag/magroom.lpc:41`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if( (strlen(name) < 2) || (strlen(name) > 10 ) )`（`/adm/daemons/logind.zh.lpc:733`）；`if ((strlen(name) < 2) || (strlen(name) > 40)) {`（`/cmds/std/buildroom.lpc:68`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 12 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 无参数时命令对 0 的调用（2026-10-27，KB 06 §7.336 Also）

巫师/管理员命令在通过权限门之后仍会把 0 交给 `sscanf` / `read_file` / `find_living` 等。`lpc_fix_bare_arg.py` 在首次使用参数前加上 `if (!arg)`（或 `help(me)` / `GetHelp()`）。本库本批改动见该提交。

## open 下死出口由对侧房间修好（2026-10-27，KB 06 §7.257 Also）

`lpc_fix_dead_exits` 的 SKIP 曾把 `/open/` 当巫师目录。本库本批出口改写见该提交（大小写/错名，由对侧出口回指判定）。证明见 KB。

## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。

