
## WASM 修复摘要（迁移自 meta.json 的 group_note）

NT/nitan 血统，但和 nitan170911/nitan6 不是逐字节相同。之前一轮 WASM 修复从 nitan170911 移植了 §7.15 dbase 架构修复的注释/wizard.lpc 片段，并修好了几个其它 bug（GBK is_chinese()、origin() 检查、band.lpc 回环放行、NTOS 心跳移除、mudlistd.lpc 的 socket/数组类型 bug），让这份档案启动干净，但由于这份档案缓慢的分布式预载（SYSTEM_D->valid_login() 靠一个 preload_list，通过 call_out 每秒载入一个档案，约 30 秒）反复撞上测试工具的计时问题，交互式注册流程一直没有验证过。这一轮终于完成了注册验证，并发现真正剩下的阻碍是架构性的，不是计时问题：（1）§7.15 的移植其实没做完——feature/dbase.lpc 自己的注释早就声称 set()/query()/delete() "现在已经定义"成真正的、各物件独立的函式，但函式本体其实从未从 nitan170911 真正复制过来，导致所有继承 F_DBASE 的物件用裸调用 set()/query() 时，仍然会静默命中 simul_efun 里那个全局共享的后备 dbase，而不是自己的——已经从 nitan170911 的 feature/dbase.lpc 移植了完整实现（set/query/delete/set_temp/query_temp/delete_temp），这次是真的核对过实际档案，而不是只信注释。（2）logind.lpc 的 get_surname()/get_name()（check_legal_name(arg, 4) 应为 2，对应"不超过两个汉字"的提示）和 named.lpc 的 invalid_new_name()（strlen(name) < 2 应为 < 1——会把任何合法的单字给名比如"风"当成"空名字"拒绝）里还残留着第二处 §8.1 类的 GBK 字节数没减半的 bug。（3）5 个档案（user.lpc、baby.lpc、giftd.lpc、examined.lpc、room.lpc）在各自局部覆写的属性存取函式里用 efun::set/query/addn/delete(...) 想呼叫"原始"实现——但 set/query 等在这个驱动上从来就不是真正的内建 efun（只是 simul_efun 或继承函式），efun:: 完全无法解析（"Unknown efun"）。已改成 ::（父层作用域，现在 F_DBASE 完整了就能正确解析）来处理 set/query/delete，addn 的情形则直接改成 ob->add(prop,data) 呼叫（addn 只存在于 simul_efun 里，从未被继承过，所以 ::addn 找不到有效目标——两处呼叫点其实是把本该呼叫 ::add 的函式（本身就叫 add()）打错成了 addn，对应 F_DBASE 真正的 add()）。已通过一次真实的 WASM 注册确认：完整的 id→确认→姓氏→名字→管理密码→确认→登录密码→确认→性别→电子邮件注册流程零编译错误完成，look/quit 也已验证（包括 quit 的新账号 30 分钟内可撤销删除流程）。一个 wizlist 里列出的管理员 id（"fluffos"）重新注册后被正确带到巫师专属的起始房间（巫师休息室），确认管理员身份生效。"score"对刚注册的角色会拒绝显示"还没有出生呐"——不是 bug：这份档案有一套独立的、游戏内的"出生仪式"（在 /d/register/ 里和盘古、地藏王等创世神话 NPC 对话），真实玩家需要先完成它才会被标记为"已出生"，和其它内容/游戏设计限制一样不在本轮修复范围内。既有的格式化通过记录（之前的提交）已经覆盖了整个档案；这一轮改动的约 8 个档案单独重跑过格式化工具，不需要任何改动（已经符合它的风格）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 76 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

用新编译的 `~/src/fluffos/build-debug/src/driver`（origin/master 最新拉
取，含本项目自己提交并合入的 #1343/#1344 两个 PR，以及同一会话里另外提
交的驱动 PR：把编译诊断的严重度标记从 clang 风格的小写 `warning:`/
`error:` 改回大写 `Warning:`/`Error:`，专门为了兼容本语料库里大量按老式
MudOS 惯例检查大写"Warning"的 mudlib 代码）重新验证。

### `to_int()` 任务计数器修复

`adm/daemons/combatd.lpc`/`cmds/std/whisper.lpc` 里全部 `quest_count = ...
% 500` 已经是 `to_int(query(...)) % 500` 的修复后形状，无需改动。

### 新发现并修复：与 hhsj 逐字节相同的 `log_error()` 严重度门控缺失

`adm/kernel/master/error.lpc`——和 `hhsj`（同一会话本轮更早修复过）的对
应文件逐字节相同，同一个 bug：`error_type` 的大小写判断本身是对的
（`strsrch(message, "Warning") == -1`），但从来没有真正拿这个判断结果去
门控是否要 `tell_object()` 转发给玩家——不管是不是纯 warning，一律无条
件转发。修复：只在真正的 error 时才转发（`debug` 频道广播给巫师和
`write_file()` 落盘均保持不变）。**现场验证**：驱动升级后（大写
"Warning:" 恢复）配合这个修复，干净注册流程的欢迎序列不再夹带任何
"编译时段警告：...Warning:"文本。

### 新发现并修复：`message()` 包装函式非 varargs（与 ntii/nte 同类）

`adm/kernel/simul_efun/message.lpc` 的 `message(mixed arg, string
message, mixed target, mixed exclude)` 没有声明 `varargs`，但驱动仍然接
受少于 4 个实参的呼叫（缺失的 `exclude` 静默补成整数 `0`），再原样转发
给 `efun::message()`——这个驱动的原生 message() efun 拒绝接受字面 `0`
作为 exclude。`adm/daemons/actiond.lpc` 的 `check_action_startend()`（每
次新角色 `enter_world()` 时通过 `festival.lpc`→`actiond.lpc`创建触发）
用 3 个参数呼叫 `message("system", ..., users())`，每次新注册都会命中。
修复（加 `varargs`，`exclude || ({})`）与 ntii/nte 的修法完全一致。**现
场验证**：修复前"执行时段错误：Bad argument 4 to EFUN message()"反复出
现在 debug.log；修复+重启后，同样触发活动播报的注册流程干净完成，"多倍
BOSS奖励"等活动公告正确显示在欢迎序列里，没有任何报错。

### 冷启动级联编译撑爆 `maximum evaluation cost`（AGENTS.md §7.90/§10.8 已有先例，本档尤其严重）

这份档案的分布式预载设计（`SYSTEM_D->valid_login()` 靠 `preload_list`
每秒载入一个档案，约 30 秒才允许登录，见既有 WASM 修复摘要记录）意味着
驱动刚起服后的头几次全新注册撞上的冷启动级联比 `hhsj`/`ntii`/`nte` 更
频繁：`master.lpc` 的 `valid_read()`/`valid_object()`、`logind.lpc` 的
`get_gender()`、`user.lpc` 的 `calc_sec_id()`、`simul_efun.lpc` 的
`assure_file()` 等多处各自独立触发过"Too long evaluation. Execution
aborted."，符合已知类别，不是新回归（同一会话里 `hhsj`/`ntii`/`nte` 用
同一份升级后驱动测试时记录了同样的现象）。**验证自愈**：驱动"热身"几
次注册尝试、账号存档确认幸存（`qinfengjiu`/`qinfenger`/`qinfengshi` 均
成功落盘）后，后续全新账号（`qinfengba`）一次性干净走完注册→"泥潭注
册室"→欢迎序列（含活动播报），全程零报错。一次由冷启动级联间接触发的
下游症状（`adm/daemons/analectad.lpc` 的 `prompt_user()` 在
`analecta_list` 疑似因 `create()` 被级联打断而未初始化的情况下命中
"Value being indexed is zero"）同样在驱动热身后的干净重跑里没有再复
现，判定为同一根因的下游表现，不是独立 bug，未单独修复。

### 完整游玩测试范围

沿用 hhsj/round one 已经验证过的"注册成功进入泥潭注册室，欢迎/活动播报
序列正确显示"作为及格线（`score` 对未完成"出生仪式"的角色返回"还没有出
生呐"，是这份档案自己的设计，不是 bug，和 hhsj 的记录一致）。战斗/死亡
循环仍未触达，留给下一次专门测试。

### 本轮结论

驱动升级（含把诊断严重度标记改回大写"Warning"的驱动侧修复）后 nt6 整体
状态良好：任务计数器 `to_int()` 修复确认已生效；新发现并修复两个真实
bug（与 hhsj 逐字节相同的 `log_error()` 严重度门控缺失、与 ntii/nte 同
类的 `message()` 非 varargs 崩溃），均现场验证；冷启动 eval-cost 级联比
其他档案更频繁但同样验证自愈，一个下游症状（analectad.lpc 索引崩溃）
同样自愈、判定为同一根因。测试账号
（`qinfengjiu`/`qinfenger`/`qinfengshi`/`qinfengba`）存档留在 `data/`
下作为佐证，未清理（未跟踪文件，不纳入本次提交）。

## 深度功能测试（2026-08-17，round three）——上一轮"自愈"结论被推翻

上一轮把冷启动 eval-cost 级联归类为"验证自愈"（靠存档幸存作为证据）。
这一轮真正把新角色一路测到能正常下达指令，发现"自愈"结论低估了严重
性，找到并修复了两个真实 bug：

1. **AGENTS.md §7.109（跨库扫描）**：`logind.lpc` 的 `get_gender()` 未加
   `catch()` 呼叫 `init_new_player(user)`，其后紧接的
   `waiting_enter_world(ob, user)`（真正设置出生点/开启指令派发的那一
   步）。`init_new_player()` 内部的 `CHANNEL_D->query_default_channel(...)`
   在冷启动时会强制首次编译 `channeld.lpc`，若撞上 eval-cost 上限就会
   未捕获地抛出，导致角色永久卡在"已登录但没有环境、没有指令派发"的
   状态——`look` 等任何指令都只返回"什么？"，且**永远不会有存档**（比
   上一轮记录的"自愈"更严重，account 甚至没能落盘过）。修复：
   `catch(init_new_player(user))`。此形状在另外 112 个档案里逐字节相
   同，已跨库批量修复（AGENTS.md §7.109）。
2. **`maximum evaluation cost` 700000 不足以撑过本档案的冷启动级联**：
   即使套用 §7.109 的 `catch()` 修复后，同一驱动进程里**第一个**注册的
   角色仍然在 `/feature/command.lpc` 自身的编译过程中（即 `add_action()`
   指令注册所在的那份档案）撞上 `Eval interrupted: ... cost limit
   reached`——这条路径完全在 §7.109 的 `catch()` 范围之外（发生在
   `logind.lpc` 调用链之外，是驱动装载 `char.lpc` 继承链时的编译期开
   销），角色一样卡死在无指令派发状态，`look` 依旧"什么？"。修复：把
   `config.fluffos` 的 `maximum evaluation cost` 从 `700000` 提到
   `5000000`（AGENTS.md §7.90 的标准补救值，本项目 30+ 档案已使用）。
   **现场验证**：重开一个全新驱动进程，第一次注册（`qinteste`）在拉高
   eval-cost 前必现同样的"什么？"卡死；拉高后重开驱动，同一批第一次
   注册干净走完（`look` 正确显示"泥潭注册室"，`debug.log` 全程零
   `cost limit reached`）。上一轮"自愈"的判断标准（存档能幸存）不够
   充分——本轮才发现最坏情况是"连存档都没有"，必须真正拉高上限。
3. **`cmds/std/say.lpc` 对 NPC 触发的 `say` 未加保护**：出生仪式的
   `pangu`（盘古）NPC 通过 `command("say ...")` 以自己的身份触发 `say`
   命令，但 `say.lpc` 的广播行无条件 `capitalize(query("id", me))`——
   NPC 从不设置 `"id"`（这是玩家专属属性），导致 `capitalize(0)` 崩溃
   （被驱动的 mudlib 错误处理器捕获、降级为玩家可见的"发现了臭虫"提
   示，不阻断后续流程，但确实是一个真实、可复现的类型错误）。修复：
   `stringp(query("id", me)) ? capitalize(...) : "?"`，与本项目对同类
   `capitalize(query("id"))` 问题的一贯处理方式一致（AGENTS.md
   §7.7）。只在本档案修复，未跨库扫描（触发条件依赖"NPC 用
   `command()` 主动触发 `say`"这个具体交互，未确认是否在其它档案里也
   存在，留给未来遇到时再核实，不盲目套用）。

完整验证了注册 → 出生仪式（盘古对话、`choose` 性格、`washto` 天赋）→
`score` 显示完整角色面板（不再是"还没有出生呐"）全程零报错。战斗/死
亡循环/留言板仍未触达——本轮时间预算内先把发现的两个严重 bug 落地，
留给下一轮专门测试。测试账号 `qinteste` 存档留在 `data/` 下作为佐证，
未清理（未跟踪文件，不纳入本次提交）。

## 深度功能测试（2026-08-17，round four）——战斗测试起步，一个待核实的疑点

出村流程（`ask hua about 出村`，需先"拜师"）比预期更长，本轮改用
wizlist 里的管理员 id（`fluffos`，重新注册，正确获得巫师身份并被带
到巫师休息室）走 `goto` 直达 `/d/wudang/tufeiwo1`（土匪常出没的林中小
路）快速触发战斗，跳过完整的新手村教学/拜师流程。

**发现但未确认的疑点**：`kill tufei` 攻击 `土匪(银子)` 后，`【系统】
战斗精灵：银子(): bad action = 0` 在系统频道上无限重复（每个心跳一
条，`flee` 离开房间后仍在继续），双方均未见明显掉血，战斗从未真正推
进。追踪到 `adm/daemons/combatd.lpc` 的 `query_action()`——当
`query("actions", me)` 不是 mapping 时会调用 `me->reset_action()`
重试一次，仍失败则广播这条系统消息并 `return 0`（放弃这次攻击，不崩
溃）。`feature/attack.lpc` 的 `reset_action()` 理论上总会把 `actions`
设成某个值（技能对应的 closure，或 `query("default_actions")` 兜底），
所以持续失败意味着这两条路径对 `土匪` 这个 NPC 都没能产出一个合法
mapping——但**未确认根因**，也**未确认这是真实玩家会遇到的路径**：
本轮测试用的 `fluffos` 账号是全新注册的巫师，没有走任何拜师/学技能
流程，本身就没有任何战斗技能；不清楚这个"僵局"是 NPC 自身设置
（`tufei2.lpc` 只用 `set_skill("unarmed", ...)` 直接赋值，没有走正常
拜师获得技能映射的路径）的问题，还是我方（攻击者）没有技能导致的连
带问题，或两者都是。**不计入 AGENTS.md 编号目录**——直到用一个走完
正常拜师/学技能流程的角色重现，才能确定这是否是真实玩家可达的 bug，
还是纯粹因为用了一个跳过教学的巫师账号测试而产生的假象。下一轮如果
继续测试战斗，应该用完成拜师的角色（或至少 `setskill` 给自己一个合
法技能）重新触发同样的战斗，看警告是否消失。

工具方法记录：`scripts/tmux_mud.sh` 的 `read`/`sendread` 因为 tmux
面板固定开了 `-y 500`（220x500），`capture-pane -S -N` 的 N 起不到预
期的"只看最后 N 行"效果（面板本身够大，永远整页回卷），改用
`tmux capture-pane -p | tail -N` 更可靠。另外，直接在 `tmux send-keys
-l` 里发送含中文的长指令（如 `ask hua about 出村`）会偶发触发本地
telnet 客户端自己的 `^]` escape 模式（`telnet>` 提示符），经原始
socket 验证过服务端应答本身完全干净（不含裸露的 `\xff`），确认是本
地 telnet 客户端的问题，不是这份档案的 bug；用 `telnet -E`（禁用
escape 字符）启动连接后问题消失。

## 深度功能测试（2026-08-17，round five）——第二个待核实疑点，本轮未能推进战斗测试

尝试按 round four 的建议，用一个真正学过技能的角色重现"bad action"警
告，但被两条独立的权限/寻址问题挡住，未能在本轮内完成：

1. **`clone`/`setskill` 等 `cmds/arch/` 指令需要真正的 `(arch)` 授权**
   （`SECURITY_D->valid_grant(me, "(arch)")`），`fluffos` 这个 wizlist
   里标注"(admin)"的账号并不自动具备——和 `is_admin()` 的情况一样
   （`clone.lpc`/`admin_flag` 那条，见 round four 记录），wizlist 的
   "(admin)" 标注看起来只是展示用途，不直接对应驱动侧真正的高权限判
   定。绕过尝试：改走正常玩家路径——去新手村练武场 `bai wubo`（`拜
   师请使用指令 bai 师傅ID(bai wu bo)`）取得真实技能。
2. **`cmds/skill/apprentice.lpc`（`bai`/`apprentice` 指令的真正实现）
   的目标寻址疑似有 bug，或者是我方操作有误，尚未查清**：在武伯所在
   的练武场对 `bai wu bo`（含空格，武伯 `set_name` 声明的 id 之一）
   / `apprentice wu bo` 均得到 "你恭恭敬敬地向新手入门必读磕头请安，
   叫道：「师父！」"——即代码里 `me->is_apprentice_of(ob)` 为真时的
   提前返回分支，但 `score` 确认"师承"仍是"你还没有拜师"，说明
   `present(arg, environment(me))` 解析出的 `ob` 实际上是新手指南
   书（`新手入门必读`，id 只有 `book`/`newbie book`），不是武伯。把
   书从背包丢在地上后重试，结果完全相同，排除了"present() 误查了我
   方背包"这个最直接的猜测。真正根因（present() 的房间物件搜索顺序、
   多字词 id 的匹配规则，还是别的原因）未查清——**同样不计入 AGENTS.md
   编号目录**，因为可能是我方指令用法本身有误（比如武伯的真实注册 id
   或者拜师指令的正确调用方式和源码字面猜测的不一样），而不一定是这
   份档案的 bug。

鉴于两轮排查战斗/技能获取路径都没有干净的结论，且已经在 nt6 一份档案
上投入了五轮测试，本轮到此为止，不再继续深挖——战斗、死亡/复活循环、
留言板仍未验证。如果未来还要继续测试 nt6 的这部分，建议换一个思路：
不要试图用巫师账号走捷径，直接完整跑一遍新手村教学流程（`ask lao
about` 各编号选项，一步步做完老村长的任务），用系统本身引导的路径推
进到真正学会技能，这样才能排除"用了非常规账号/指令导致的假象"这个反
复出现的干扰因素。

## AGENTS.md §7.100 修复（2026-08-19）

同族（`hhsj`/`xfbhh`/`nitan170911`）共享的 `ROOM` 基类冗余
`replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md §7.100）：本 lib
4925 个房间文件的 `create()` 末尾都有这一行多余调用，同款地雷也烤进
了自带建房工具 `clone/misc/roommaker.lpc` 的字符串拼接代码生成模
板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`
（`d/huangshan/banshan.lpc` 有两处独立调用，均删除），加上
roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：4926
files changed, 1 insertion(+), 4928 deletions(-)，与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40186 正常监听，
`debug.log` 全程干净。既有的 `fluffos` 管理员存档密码与 README 记录
的默认值（`loginpw1`/`AdminPass1`）都对不上（大概率是更早一轮测试
时被改过），且删除玩家存档不在本次修复授权范围内——改用另一个
`wizlist` 里列出、此前从未创建过存档的 id `wuji`，走完整注册流程
（含双密码机制）后正确落地"巫师休息室"，确认基于 wizlist 的管理员
判定在修复后依旧生效。`goto` 走访 14 个刚修复的房间（`d/wuxi`/
`d/city`/`d/changan`/`d/wuyi`/`d/beijing`/`d/northft`/`d/kaifeng`/
`d/huashan`/`d/ruzhou`），均正常返回，无 "cannot replace"/"cannot
bind" 新增日志行。按精确 PID 结束驱动；测试期间产生的
`mrtg`（第三方流量统计）相关四个已跟踪存档文件漂移已
`git checkout --` 还原，新建的 `wuji`/`qinteste` 存档本就是未跟踪状
态，未纳入提交。

## AGENTS.md §7.79 修复（2026-08-19）

裸 `addn("prop", value)`（无第三参数）恒为静默无效果，同族
（`xfbhh`/`hhsj`/`nitan170911`/`nitan6`/`nt6nitan6win`）共通问题，方
法论/脚本详见 `xfbhh` NOTES.md 对应小节（同一 `fix_addn2.py`）。本
lib `clone/user/user.lpc` 未发现命名笔误覆盖（正确命名为 `add`），
只有 `clone/user/baby.lpc` 一处本地覆盖（覆盖 `addn` 未覆盖
`addn_temp`），排除其 8 处 `addn(...)` 调用。591 处改写，`git diff
--stat`：339 files changed, 591 insertions(+), 591 deletions(-)，加
上排除的 8 处，591+8=599，与调查阶段统计精确吻合（`nitan6`/
`nt6nitan6win` 数字完全一致）。

验证：`build-debug` 驱动真实冷启动，端口 40186 正常监听，`debug.
log` 全程干净，无新增编译错误。用内建 `guest` 快速账号验证登录直达
游戏世界（"你连线进入nt6"），无报错。按精确 PID 结束驱动；测试产生
的 `mrtg` 存档增量已 `git checkout --` 还原。

## adm/npc/nanxian.lpc 字节损毁修复（2026-08-20）

兄弟库 `nt6nitan6win` 自己的第四轮测试发现并修复了这份档案里
`adm/npc/nanxian.lpc` 的字节级损毁（两处字符串字面量内嵌入了 NUL 字
节+乱码，来自同一份共享档案打包时的损毁），其中一处在真正会执行到
的 `ask_reborn()` 的 `message_vision()` 调用里，会让这个 NPC 的
`create()` 崩溃中断（连带 `create_family()`/`setup()`/穿装备全部执
行不到）。确认 `nt6` 自己的 `nanxian.lpc` 携带完全同一处损毁（字节
偏移量不同但损毁形状一致），已用同样的修复内容改正（改后档案哈希
与 `nt6nitan6win` 修复后的档案完全一致，确认两边原本就是同一份内
容）。因为本档案既有的 `fluffos` 管理员账号密码已经漂移（此前记
录），无法用 `update` 现场触发这个懒加载 NPC 档案的重新编译，本次
验证止于全新驱动进程干净冷启动（零新增编译错误）+ 修复内容与已证实
正确的兄弟库版本逐字节比对一致，未做真正的游戏内触发验证。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc`, `d/death/npc/hei.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

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
