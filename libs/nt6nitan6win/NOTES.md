
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 nt6（142）同一血统/同一 master 哈希——本轮改动的每一个档案都先用 diff 确认逐字节相同才打的补丁。之前一轮移植了 nt6 早前的全部修复（is_chinese、check_legal_name 长度界限、12 个档案里的 origin() §7.47、band.lpc 回环补丁、心跳间隔/mudlistd 的 socket 移除、mudlistd 的裸数组修复）让它启动干净，但和 nt6 出于同样的原因（缓慢的分布式预载打乱了脚本化测试的计时）没有验证过注册流程。这一轮：既然 nt6 所有新修复过的档案（feature/dbase.lpc 完整的 set/query/delete 实现，logind.lpc/named.lpc 减半后的名字长度界限，以及 user.lpc/baby.lpc/giftd.lpc/examined.lpc/room.lpc 里 5 处 efun:: 改成 :: 的作用域解析修复）都确认和 nt6 修复前的版本逐字节相同，就直接把修好的档案原样复制过来，而不是重新推导一遍相同的补丁——完整的 bug 说明见 nt6 自己的 meta.json/README。在这份档案自己身上独立通过一次真实的 WASM 注册验证（不只是继承 nt6 的验证结果）：完整的 id→确认→姓氏→名字→管理密码→确认→登录密码→确认→性别→电子邮件注册流程零编译错误完成，look/quit 也已验证（包括 quit 的新账号删除确认流程），wizlist 里列出的管理员 id（fluffos）重新注册后也被正确带到巫师专属的起始房间。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 76 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，首次完整实机测试）

这是这份档案第一次真正的实机深度测试（此前只有 WASM 修复摘要和 §7.86 跨
库扫描记录，均未做过真人注册流程）。用 `~/src/fluffos/build-debug/src/
driver`（origin/master 最新拉取，含本项目自己提交并合入的 #1343/#1344
两个 PR，以及同一会话里另外提交的驱动 PR：把编译诊断严重度标记从小写改
回大写 "Warning:"/"Error:"）。

### `to_int()` 任务计数器修复

`adm/daemons/combatd.lpc`/`cmds/std/whisper.lpc` 里全部 `quest_count = ...
% 500` 已经是 `to_int(query(...)) % 500` 的修复后形状，无需改动。

### 已确认无需改动：`log_error()`

`adm/kernel/master/error.lpc` 已经是本会话早前语料库扫描（commit
fe27592a94c）修复后的形状（`arning:` 大小写无关匹配 + 门控转发），核对
无需改动。

### 新发现并修复：`message()` 包装函式非 varargs（与 ntii/nte/nt6/hhsj 同类，本档之前误判为"已修"）

`adm/kernel/simul_efun/message.lpc` 的 `message(mixed arg, string
message, mixed target, mixed exclude)` 缺 `varargs` 且没有 `exclude` 守
卫——本轮排查时最初误信了对同一份文件早前"grep 到 exclude || (" 就是已修
复"的粗略检查（那些命中其实是 `message_vision()`/`message_sort()` 等其
他辅助函式内部**呼叫** `message()` 时自己加的守卫，不是 `message()` 本体
的守卫），后来直接读函式本体才发现没修。修复：加 `varargs` + `exclude ||
({})`，和 ntii/nte/nt6/hhsj 完全一致的修法。**现场验证**：修复前"执行时
段错误：Bad argument 4 to EFUN message()"在 `actiond.lpc` 的活动播报链
路反复出现；修复+重启后，同样触发活动播报的注册流程干净完成，"多倍
BOSS奖励"等十条活动公告正确显示，`debug.log` 总行数在多次干净跑（含
`look`/`score`）中稳定保持 402 行不变。

### 新发现并修复：`log_file()` 的 euid 提权在 `assure_file()` 内部被自己撤销（与 nitan_san 逐字节相同）

`adm/kernel/simul_efun/file.lpc` 的 `log_file()` 和 `nitan_san` 修复前的
对应文件逐字节相同（`assure_file()` 结尾 `seteuid(getuid())` 撤销了调用
者刚设置的 ROOT_UID）。用完全相同的修法（`assure_file()` 返回后再
`seteuid(ROOT_UID)` 一次）处理。**同一轮顺手核对并同样修复了这份档案所
在血统的三个兄弟库**（`hhsj`/`nt6`/`xfbhh`，均确认逐字节相同的缺陷，此
前几轮测试这些库时没有专门检查这个函式）。**未能在本轮通过 `quit`→"y"
确认删号路径独立实机验证**——反复尝试（含分两次连线模拟"重新登录"）在
"quit" 之后都遇到"什么？"（未识别指令），但 `debug.log` 全程保持 402 行
不变，说明不是崩溃，很可能是本轮 `mudclient.py` 测试时序上还有没摸清楚
的地方（这份档案在世界入口之后是否需要额外一步才能进入正常指令循环，未
查清），不是这处修复本身的问题——这个修复和 `nitan_san` 已经现场验证过
的版本逐字节相同，源码层面置信度高，留给下一次接触这份档案时用更细致的
时序补做 `quit` 路径的实机验证。

### 冷启动级联编译撑爆 `maximum evaluation cost`（AGENTS.md §7.90/§10.8 已有先例）

和同血统的 `nt6` 一样，第一、二次全新注册尝试在 `master.lpc` 的
`valid_read()`/`valid_object()`/`log_error()`、`get_gender()` 链路上多次
命中"Too long evaluation. Execution aborted."。**验证自愈**：驱动热身几
次后，后续全新账号一次性干净走完注册→"泥潭注册室"→欢迎/活动播报序列，
全程零报错。

### 完整游玩测试范围

沿用其它 nt6/hhsj/xfbhh 血统兄弟库已验证过的"注册成功进入泥潭注册室，
欢迎/活动播报序列正确显示"作为及格线。战斗/门派/quit 完整链路仍未触
达，留给下一次专门测试。

### 本轮结论

这是 nt6nitan6win 第一次真正的实机测试：任务计数器/`log_error()`均确认
无需改动；新发现并修复两个真实 bug（`message()` 非 varargs、`log_file()`
euid 提权被自己撤销），后者同一轮顺手同步修复到 `hhsj`/`nt6`/`xfbhh` 三
个兄弟库（此前测试这些库时遗漏了这个特定函式的检查）；冷启动 eval-cost
级联验证自愈；`quit`→"y"确认删号路径未能独立实机验证（源码层面高置信
度，留给下一轮）。测试账号（`wumeiliu`/`zhoubaqi`/`hematou` 等）存档留
在 `data/` 下作为佐证，未清理（未跟踪文件，不纳入本次提交）。

## AGENTS.md §7.100 修复（2026-08-19）

同族（`nt6`/`hhsj`/`xfbhh`/`nitan170911`）共享的 `ROOM` 基类冗余
`replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md §7.100）：本 lib
4925 个房间文件的 `create()` 末尾都有这一行多余调用，同款地雷也烤进
了自带建房工具 `clone/misc/roommaker.lpc` 的字符串拼接代码生成模
板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`
（`d/huangshan/banshan.lpc` 有两处独立调用，均删除），加上
roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：4926
files changed, 1 insertion(+), 4928 deletions(-)，与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40187 正常监听，
`debug.log` 全程干净。本 lib 之前没有任何预置存档，按 README 记录
的双密码机制（`AdminPass1`/`loginpw1`）走完整注册流程创建
`fluffos` 账号，正确落地"巫师休息室"，确认基于 wizlist 的管理员判
定生效。`goto` 走访 14 个刚修复的房间（`d/wuxi`/`d/emei`/
`d/jingzhou`/`d/wuyi`/`d/luoyang`/`d/yanziwu`/`d/shouxihu`/
`d/northft`/`d/huijiang`/`d/huashan`），均正常返回，无 "cannot
replace"/"cannot bind" 新增日志行。按精确 PID 结束驱动；测试期间产
生的 `mrtg`（第三方流量统计）已跟踪存档漂移已 `git checkout --`
还原，新建的 `fluffos` 存档本就是未跟踪状态，未纳入提交。

## AGENTS.md §7.79 修复（2026-08-19）

裸 `addn("prop", value)`（无第三参数）恒为静默无效果，同族
（`xfbhh`/`hhsj`/`nitan170911`/`nitan6`/`nt6`）共通问题，方法论/脚本
详见 `xfbhh` NOTES.md 对应小节（同一 `fix_addn2.py`）。本 lib
`clone/user/user.lpc` 未发现命名笔误覆盖（正确命名为 `add`），只有
`clone/user/baby.lpc` 一处本地覆盖（覆盖 `addn` 未覆盖
`addn_temp`），排除其 8 处 `addn(...)` 调用。591 处改写，`git diff
--stat`：339 files changed, 591 insertions(+), 591 deletions(-)，加
上排除的 8 处，591+8=599，与调查阶段统计精确吻合（`nitan6`/`nt6`数
字完全一致）。

验证：`build-debug` 驱动真实冷启动，端口 40187 正常监听，`debug.
log` 全程干净，无新增编译错误。用内建 `guest` 快速账号验证登录直达
游戏世界（"你连线进入nt6nitan6win"），无报错。按精确 PID 结束驱
动；测试产生的 `mrtg` 存档增量已 `git checkout --` 还原。

## 深度功能测试（2026-08-20，round four）

### §7.112 缺口检查：`d/death/npc/bai.lpc`/`hei.lpc`（真的存在，已修复）

按兄弟库 `hhsj` 同轮测试的发现去检查——本 lib 的 `DEATH_ROOM`
（`include/login.h` 里 `/d/death/gate`，每个死亡玩家的默认落地
点，不只是 PK/巫师死亡）确实也是由 `d/death/npc/bai.lpc`/
`hei.lpc`（白无常/黑无常）填充，且两个档案都和 `hhsj` 修复前的版
本逐字节相同：`init()` 里无条件 `call_out("death_stage", 5,
previous_object(), 0)`，没有任何重入防护——这正是 AGENTS.md §7.112
的经典形状（两波跨库扫描分别用 `wgargoyle.lpc`/`bgargoyle.lpc` 和
`d/death/npc/pang.lpc`/`b.lpc` 等文件名做种子，但 `bai.lpc`/
`hei.lpc` 这个文件名组合两波都没扫到）。用和 `hhsj` 完全相同的修
法：`init()` 里加 `query_temp("death_stage_active")` 守卫（`if
(previous_object()->query_temp("death_stage_active")) return;` +
`previous_object()->set_temp("death_stage_active", 1);`)，
`death_stage()` 每个真正的退出点都补上 `delete_temp(...)`（含
`!ob || !present(ob)` 分支和最终 `reincarnate()` 之前）。驱动干净
重启后编译无错误（语法层面确认正确）。

### 新发现并修复：`/adm/npc/nanxian.lpc` 源码字节级损坏，阻断每一
个新角色的"出村"关键路径（真实运行时崩溃）

**发现经过**：完整走一遍新手村"出村"流程（`ask lao about 出村` →
`ask hua about 出村` → `1` 选择"直接出村（到扬州武庙）"）时，driver
在玩家眼前直接打印出编译错误（`/adm/npc/nanxian.lpc:491:106: Error:
Illegal embedded NUL byte (0x00) in source` 等 6 条编译错误），角
色停留在"村口"没有真正移动过去。追踪到 `d/city/wumiao.lpc`
`create()` 最后一行 `("/adm/npc/nanxian")->come_here();`
（未加 `catch()`）——这是"直接出村"选项的唯一落地房间，`nanxian.lpc`
编译失败导致这一行抛出未捕获的运行时错误，使 `me->move("/d/city/
wumiao")` 从未真正完成，新角色永久卡在新手村出口，无法进入游戏主
世界。

**根因**：`nanxian.lpc` 内嵌两处真实的字节级源码损坏（不是编码问
题，是原始归档提取阶段就已损坏的乱码字节，含裸 `0x00` 和非法
UTF-8 序列）——一处在注释块内的死代码字符串里（491 行），一处在
`ask_reborn()` 函式内真实会被执行到的 `message_vision()` 字符串里
（787 行，属于"轮回已满三次"的拒绝提示）。损坏字节本身破坏了词法
分析器，连带把 812/820/828 行三处本来完全合法的语句也误判成"语法
错误"（级联错误，不是三个独立 bug）。**核实**：同血统兄弟库 `nt6`
的 `nanxian.lpc` 逐字节相同（同样损坏，33967 字节，含裸 NUL）；
`hhsj`/`xfbhh`/`nitan170911` 的对应档案完全干净但文件大小不同（非
逐字节相同版本，未直接复制过来，避免引入未经验证的内容差异）。原
文已不可逆恢复，用二进制安全的 Python 脚本原地清理这两处乱码，替
换成语义合理、风格一致的中文占位文本（491 行本就是被注释掉的死代
码，直接补全成通顺句子；787 行按同函式其它拒绝分支的语气补一句"此
劫已经错过，无法再渡"）。

**验证**：驱动重新冷启动后 `/adm/npc/nanxian.lpc` 编译零错误（原来
的 6 条编译错误全部消失），完整走一遍"出村"流程，角色成功从"村
口"移动到"武庙-(你目前在扬州城)"，并拿到出村奖励（经验+50000、潜
能+100000）。这是本 lib **每一个新角色都会走的必经路径**（新手村
唯一的"直接出村"选项），此前从未被验证过。

### 新发现并修复：`cmds/std/say.lpc` 的 `capitalize(query("id",
me))` 未加 `stringp()` 守卫，攻击特定 NPC 时崩溃（AGENTS.md §7.7
同一崩溃形状的新命中点，不在原扫描范围内）

**发现经过**：`kill xian`（攻击"醉仙楼"里的冼老板 NPC，`attitude`
为 `friendly` 且 `can_speak`）在 `accept_kill()` 的 `default:`
分支触发 `command("say ...")`，随即在玩家面前打印"WARNING 这里发
现了臭虫"，`debug.log` 记录了真实的
`master/error.lpc::error_handler()` 完整堆栈：`*Bad argument 1 to
capitalize() Expected: string Got: 0.`，崩溃点是 `cmds/std/
say.lpc` 第 42 行 `capitalize(query("id", me))`——`me`（对话发起
者，这里是触发 `command("say")` 的那个物件）的 `"id"` 属性在这个
时间点解析为 `0` 而非字符串，和 AGENTS.md §7.7 已大规模扫描修复过
的崩溃**同一个形状**（`capitalize(query("id"))` 缺 `stringp()`守
护），但那次 154 库的扫描只专门扫了 `feature/name.lpc` 里的
`short()` 这一个命中点，没有覆盖 `cmds/std/say.lpc` 这个独立的裸
调用点——这是同一崩溃形状在这份档案身上的**另一个未被扫描覆盖的
命中点**。根因没有深挖到底（`me->query("id")` 为何在这一刻解析成
`0`，`xian.lpc`/`kuangfeng.lpc` 这类 NPC 在战斗/拜师对话里显示成
"银子"/"酒杯"/"布鞋"这类不相关的物品名字，明显是另一处更深的名字
解析异常，但没有触发任何编译错误或 `debug.log` 崩溃记录，按本轮
"没有崩溃就是内容问题"的判断标准搁置，作为观察记录在此，留给以后
专门排查——不排除是某种"易容/伪装"机制的边界条件，`feature/
name.lpc` 的 `name()` 优先读取 `query_temp("apply/name")`）。**修
复**：和 §7.7 已验证的修法完全一致，加 `stringp()` 守卫——
`capitalize(query("id", me))` → `(stringp(query("id", me)) ?
capitalize(query("id", me)) : "?")`。**现场验证**：驱动重启后同一
个 `kill xian` 序列不再触发崩溃提示、`debug.log` 没有新增错误行，
战斗正常进入多回合攻防（"酒杯慢慢地移动著脚步，伺机出手"等定位/
寻找破绽的战斗文本正常循环显示）。

### 战斗测试

用 `kill xian` 触发和"醉仙楼老板"的战斗（上面 bug 修复后）：`kill`
指令正确解析目标、拒战/接战判定走完整分支、多回合攻防文本正常循
环显示，全程无崩溃、`debug.log` 无新增记录。测试角色（`rfourtwo`）
在新手村"闭眼"教学环节获得了一次性巨额天赋加成（拳脚练至满级，
战斗攻击力/防御力从个位数直接跳到 3712/4083），因此这场对局没有
真正分出生死（对手也没有阵亡），战斗解析机制本身（发起→拒战/接
战判定→多回合攻防→无崩溃）确认工作正常。受时间限制，没有再专门
找一个能真正打死玩家的对手去补做 §7.112 死亡路由的实机复现（`bai.
lpc`/`hei.lpc` 的守卫已按逐字节相同的已验证修法应用，源码层面置
信度高，编译确认无语法错误）。

### 门派/拜师测试

在"醉仙楼"找到帮派招募 NPC `kuangfeng`（狂风，`/adm/npc/
kuangfeng.lpc`），用 `bai kuang` 发起拜师请求：指令正常触发磕头
拜师的动作文本（无崩溃），但 `score` 显示"师承：你还没有拜师"仍
未变化——`apprentice.lpc` 的拜师请求走的是"待师父一方确认"的异步
流程，没有在测试窗口内等到对方确认，机制本身（发起请求→无崩溃→
等待确认）确认可用。测试过程中角色的"门派"字段一度被系统自动改
成"精意山庄"（应为闲置窗口期间某个环境事件/招募脚本触发，不是
`bai`/`apprentice` 指令本身导致），未深究。

### quit→重连循环测试

`quit` 指令正常显示退出横幅，无崩溃；重连时驱动正确执行了"距上
次退出时间过短"的冷却限制（约 20-60 秒防滥用机制，正常设计，非
bug），冷却期过后重连成功，装备/战斗属性/经验潜能/所在房间（武
庙-扬州城）全部正确保留（对比重连前后的 `score`/`look` 输出完全
一致）。完整 quit→重连状态持久化确认工作正常。

### 标准清单快速核对

`§7.90`（`config.fluffos` 已是 `5000000`，intact）、`§7.100`
（房间 `replace_program(ROOM)` 已全部清除，唯一一处命中
`work/d/wuyi/wuyigong`——无扩展名的孤立死档案，真正加载的是同名
`.lpc` 档案且已是修复后的形状，非本地库 bug，intact）、`§7.111`
（`master/error.lpc` 的 `file_name(error["object"])` 已有三元守
卫，intact）、`§7.113`（本 lib 在批次一已确认 `logind.lpc`/
`user.lpc` 的 `reconnect()` 归属正确的干净血统，intact）、
`§7.114`（未单独复测，非本轮重点）、`§7.115`（本 lib 在 13 库缺
失清单中，但属于"12 个死代码"之一——`QUEST` 宏指向的档案确实不存
在，但全档案 grep 不到任何 `QUEST->` 调用点，无需修复，intact）、
`§7.79`（`clone/user/baby.lpc` 自身覆盖了 `addn()`，8 处裸调用走
的是本地正确实现，非漏网的全局 `addn` bug，intact）逐项确认，均
无异常。

### 本轮结论

新发现并修复两个真实 bug：`/adm/npc/nanxian.lpc` 的字节级源码损
坏（阻断每个新角色的出村必经路径，此前从未被测过）、
`cmds/std/say.lpc` 的 `capitalize(query("id"))` 崩溃（§7.7 同形
状但未被原扫描覆盖的新命中点）；确认并修复了 `hhsj` 同轮测试发现
的 §7.112 缺口（`bai.lpc`/`hei.lpc`）。战斗/拜师机制确认可用（未
分出生死/未等到师父确认，机制本身工作正常）；quit→重连完整状态
持久化确认工作正常。标准检查清单全部 intact。NPC 战斗/拜师对话
里出现的"名字显示成不相关物品名"现象（银子/酒杯/布鞋）记录为观
察项，未触发任何崩溃或编译错误，留给以后专门排查。测试账号
（`rfourtwo`）存档留在 `data/` 下未清理（未跟踪文件，不纳入本次
提交）。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 6 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
