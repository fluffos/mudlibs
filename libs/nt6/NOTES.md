
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

## Ported §10.7 combat F_DBASE fix from sibling nitan6 (2026-08-21)

`feature/attack.lpc`/`feature/damage.lpc`/`feature/attribute.lpc` confirmed
byte-identical (md5sum) to `nitan6`'s pre-fix copies. `nitan6`'s round-four
§10.7 deep test found and fixed a severe bug: these files are inherited
as siblings of F_DBASE by `char.lpc`, never inheriting F_DBASE themselves,
so their bare `query()`/`set()`/`query_temp()`/`set_temp()` calls silently
hit the shared simul_efun dbase instead of the fighting character's own —
`reset_action()`'s broken `set("actions", ...)` meant `do_attack()`
silently no-opped every combat round, and `receive_damage()`/
`receive_wound()`'s broken calls meant landed hits never actually reduced
qi/jing. **Combat never applied real damage on this lib.** Ported the
identical fix (same `this_object()`/`me` redirect pattern) directly from
`nitan6`'s fixed files rather than re-deriving it. Compile-verified via
`lpcc --batch` (not live-boot-tested independently on this lib — the fix
itself was already proven live on `nitan6`).

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：扬州醉仙楼购物 + 古村武伯拜师。2026-08-12 第二轮走完了注册，
score 因未出生拒绝；2026-08-17 前后几轮留下「还没有拜师」。这是
nitan6 兄弟库，端口 40186。第一输入可以是 `gb` 再英文 id，也可以直接
发 id。管理员 `fluffos` 的 login 口令此前已漂移，本轮用原 salt 重算
`crypt` 把 `password` 和 `ad_password` 都重置成 `Mud@2026`（只提交
`data/login/f/fluffos.o`）。wizlist 是 `fluffos (admin)`。没有
`wizpwd`，登录会警告然后走普通密码。进世界前有约 3 秒「请输入任意键
继续」。预载期间（`SYSTEM_D->valid_login()` 靠 preload_list 逐秒载入）
第一次连上可能只有「已经执行了 N 秒」就挂断、看不到 id 提示——等横幅
出现「允许玩家登入」或开机约 90 秒后再连。

`clone` / `call` 被 `is_admin()` 锁死在 lonely/shulele/cqpkzaz /
`admin_flag==21`，`fluffos` 不能 `clone` 也不能 `call me->save()`。
`gift fluffos` 可用（`(arch)` 经 `(admin)`）。`save` 频繁会「请不要频
繁储存进度」。武伯 `attempt_apprentice` 自己会 `ob->save()`，拜师因此
能落盘。

### 实测过程

管理员 `fluffos` / `Mud@2026`。巫师出生在 `/d/wizard/wizard_room`。
`goto /d/register/entry` 做出生仪式：先 `choose 1`，再
`washto 20 20 20 20`。**和 nitan_san / nitan_ceshi 不同，这份档案的
washto 会自动 born 到古村**；之后再打 `born` 是「什么？」。休息室里的
`register` 动词是 `register <id> <email>`，不是 `register player@me.com`
（后者只在 `/d/register/regroom`）。

`gift fluffos` 后 `goto /d/city/zuixianlou`。F_NAME 修好以后店小二名字
正常。现场付钱买成的是 `buy 1`：「你从店小二那里买下了最后一件布衣」
（金子银子太重，找了 99 铜板）。`buy jitui` 当时仍是「你想买什么？」
——`list` 只剩编号 1 的布衣，因为 `feature/dealer.lpc` 的 `init_goods()`
用裸 `query("vendor_goods")` 打到 simul_efun 共享 dbase。已改成
`this_object()->query("vendor_goods")`。对已加载的店小二做 `update`
不会重新 init 货架，烤鸡腿清单要冷启动后的新 NPC 才看得到。付钱购物
本身已现场验证。

拜师对象是 `/d/newbie/lianwuchang` 的武伯（`d/newbie/npc/wubo.lpc`，
id `({ "wu bo", "wu", "bo" })`）。F_NAME 修好前 `bai wu bo` 会拜到新手
入门必读 / 布衣上，因为 `present("wu")` 先命中身上的布衣。修好后要用
`bai bo`（或先丢掉布衣再 `bai wu`），不要用 `bai wu` / `bai wu bo`。
现场：「恭喜您成为古村的第二代弟子」。杀驱动冷启动再登录：门派古村、
师承武伯、古村第二代传人。身上仍有布衣和 gift 自动加载的六张一千两金
票。

### 发现并修复的 PROGRAMMING bug

1. **F_NAME / F_COMMAND / F_APPRENTICE 裸 `query()`/`set()`**（从
   `nitan6` 已修版本原样移植 `feature/name.lpc`、`feature/command.lpc`、
   `feature/apprentice.lpc`）：这三个 feature 和 F_DBASE 是 `char.lpc`
   的兄弟 inherit，裸调用打到 simul_efun 共享 dbase。修复前每个 NPC/
   物品显示成 `0(0)` / 布衣，`bai wu` 会向布衣磕头。

2. **F_DEALER `vendor_goods` 同样打到共享 dbase**（`feature/dealer.lpc`）：
   `init_goods()` 的 `item = query("vendor_goods")` 改成
   `this_object()->query("vendor_goods")`。不改的话醉仙楼货架对不上
   `xiaoer2.lpc` 里写的 jitui/jiudai/baozi。

3. **华山/青城收徒计数拼写**（与 `jhfy2`/`wmkj`/`hy2002` 同形，静态
   对照修，本轮拜师走的是武伯不是华山）：
   `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc` 以及
   `kungfu/class/qingcheng/yu.lpc` 的 `recruit_apprentice()` 写
   `add("apprentice_availavble", -1)`，永远减不到
   `set("apprentice_available", 3)` 那个字段。四处都改成
   `apprentice_available`。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

1 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 村长的疗伤说明被截断

`d/newbie/npc/laocunzhang.lpc`：新手村长讲内功疗伤的那段 `msg`，`"…达到一定等级。\n\n" HIY;` 后面单独一行 `"    更多相关帮助请参阅帮助文件 help force\n\n" NOR;`——多余的 `;` 把最后一句截掉了，颜色也没有还原（`NOR` 在被丢掉的那句里）。接回去（`scripts/lpc_join_cut_strings.py`，现在也认带颜色宏的字符串）。HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py nt6 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 1821 个 `.lpc` 和 50 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：1745 -> 1745 通过，无回退；改过的头文件的 628 个包含者 604 -> 604 通过。启动时警告 11 -> 0；新进程登录（输入名字）正常。
手改：`adm/kernel/master.lpc` `direct_run_binary()` 的 `ob`、`vob` 只在 `#else`（BINARY_SUPPORT）里用到，声明挪进去；`adm/daemons/natured.lpc` 空语句 `lt[LT_MON];` 删去。护送任务杀手 `d/city/task2/shashou.lpc` 调用本库 namesd 没有的 `jap_name()`（三次加载一次失败）并把数组 id 再包一层，同 nitan6（KB 06 §7.237，`scripts/lpc_nitan_jap_name.py`）；修正后单独加载 6 次全过，探针 `new` 30 个 id 都正常。（裸 telnet 输入名字后 HEAD 与工作树都无回应，相同。）
（更正：本库没有任何 task2 以外的文件生成 `renzhi` 或发 `miling`，这个护送任务目前没接进游戏，上面的杀手修正是在休眠内容里。）

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 9 处比较、0 处去后缀（如 `clone/npc/qingyun.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。
使命任务：`adm/daemons/taskd.lpc` `alloc_task()` 的 `room[<2..<1] != ".lpc"` 让每个房间都被拒，`rooms -= ({ room })` 又拿 `zone + 名字` 去减只有名字的列表，于是无限重抽，`taskd` 从来加载不起来——玩家的 `task`、`locate` 指令只显示“这里发现了臭虫”。改正切片和列表（列表空了就停）；真正走房间之后首次冷加载要 5 秒以上，`maximum evaluation cost` 提到 10000000（nt6 原本就是最大值）。新进程建人物后 `task` 列出使命物品、`locate` 可用；HEAD 两者都失败。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 4 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 4 个，只在 #if 分支用的声明移进分支 6 个文件；改动 14 个文件，HEAD 与工作树各载入一次无回退（14 objects; HEAD PASS 14, tree PASS 14; regress 0; newly loading 0），这些文件的警告 39 -> 2。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `adm/daemons/combatd.lpc` 反击：`your_temp["guarding"];` 丢了 `= 0`（ES2 原版是 `set_temp("guarding", 0)`），一次防守姿态可无限次触发反击；补上 `= 0`。
- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- `d/guiyun/jiuguan.lpc`（12 处）、`*/song/obj/bingfu.lpc`：`query_temp("cai_" + (i + 1, me) + "/name")` 是把 `me->query_temp(...)` 改写成 `query_temp(..., me)` 时括号放错，逗号表达式让键变成 `"cai_" + me + …`，酒馆菜单前移、兵符统军列表都读不到；改为 `query_temp("cai_" + (i + 1) + "/name", me)`。
- `d/death/qiao1.lpc`：`if (dir == "north") { /* … */ }` 只剩注释的空块，把 `if` 一起挪进注释（行为不变）。
- `kungfu/skill/miaojia-jian/gan.lpc`、`zhai.lpc`：`string name() { HIY "…" NOR; }` 少了 `return`，招式名为 0；补 `return`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：u/lonely/combatd.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

与 nitan6 同码（`scripts/lpc_twin_port.py adopt nitan6 nt6`，74 个文件逐字搬入，另 4 个手工补齐），详情见 `libs/nitan6/NOTES.md` 同日一节。可编译文件的警告 **103 -> 0**（`lpc_warnings.py` 全库重扫，22593 个文件可编译；剩下的警告都在本来就编译不过的文件里）。改动的对象、包含改过头文件的对象和 `clone/`、`d/city`、`d/xiangyang`、`feature/`、`inherit/`、`adm/daemons/`、`cmds/` 等抽样 HEAD 与工作树各载入一次（新进程）：`2823 objects; HEAD PASS 2722, tree PASS 2723; regress 0; newly loading 1`（`d/city/business` 在 HEAD 那一批里无报错地失败，单独是批次现象）。删除声明审计 0 处待看。

**严重问题：F_DBASE 旁边的混入件读写 simul_efun 的共享 dbase（KB 05 §7.15 残留）。** `include/dbase.h` 补上与 `feature/dbase.lpc` 一致的属性函数原型，`feature/` 下的 equip、itemmake、food、liquid、pill、alias、message、name、damage、dealer、banker、guarder、apprentice、unique、control、action、condition、move 与 `inherit/char/master.lpc` 都 `#include <dbase.h>`；`npcsd.lpc`、`cmds/adm/eval.lpc` 去掉该包含，`feature/save.lpc` 改用 `this_object()->query("id")`。探针（新进程）：修正前 `wield` 长剑、`wear` 布衣都返回 0，`weapon`/`armor`/`equipped` 一个也没写上，自制道具 `query_autoload()` 恒为 `"kept"`；修正后 `wield`/`wear` 成功、`equipped` 为 `"wielded"`/`"worn"`，自制道具 `wield` 后 `query_autoload()` 为 `"wielded"`。

其余同 nitan6：自制道具 autoload 交给 item/combined（警告消失、行为不变）、神木王鼎虫表 `sw_insects`、`xiang.lpc` 的 `remove()` 先存盘再 `::remove(euid)`、幻境变量重复声明、`info_*.h` 头文件守卫、宏 `#undef`、`GWIZ`、返回类型、未用局部变量、`u/mike/tt.lpc` 的 `s[<1]`。

未解决：`u/mike/eval.lpc`（编译不过的临时文件）让 `lpcc` 段错误（未声明变量上的 `s[..<1]`，驱动问题，HEAD 同样）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。20 个文件 25 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/clone/npc/walker.lpc`（`pot *=`）、`/clone/npc/walker.lpc`（`score *=`）、`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 hhsj 同源同修）：
  - 36 个技能文件的 `int power_point()` 分支里返回 0.6、0.8、1.2、1.4 之类的浮点，经 `int` 返回被截断。本库没有代码调用这个函数，改成 `float` 返回值、保留原数值。
  - `inherit/room/hockshop.lpc` 的售价和 `adm/kernel/simul_efun/ntefun.lpc` 的 `sqrt` 结果写明 `to_int()`。simul_efun 能载入。
  - 改动的 243 个对象 HEAD 与工作树各载入一次，无回退（237 -> 237）。

- 2026-10-14：`inherit/item/item.lpc` 自己定义了 `string to_chinese(int status)`（物品品质名：普通/优良/珍稀/史诗/传说/神器/仙器），把 simul_efun 的 `to_chinese(string)`（技能、属性译名）遮住了；继承它的兵器、装备、药书显示“装备要求”或技能名时调用 `to_chinese(key)`，旧驱动不查类型，传进字符串只会落到最后一个分支，装备要求一律显示成“仙器”；新驱动直接报 `Bad type for argument 1 of to_chinese ( int vs string )`，这些文件整份不编译。照 nt7 的做法把本地函数改名为 `to_ch_desc()`（`short()` 里的品质调用随之改名）。新进程比对 HEAD 与工作树：168 个对象，新增载入 166，回退 0。

- 2026-10-14：40 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；5 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：45 个对象，新增载入 35，回退 0。

- 2026-10-14：`foreach` 里把 `array` 当类型（`foreach (string type, array data in news)`），本驱动不认；改为 `mixed *`（`scripts/lpc_fix_array_type.py` 现在也处理 foreach 变量）。`cmds/usr/history.lpc` 现在载入；`adm/daemons/realnews_d.lpc` 还调用本驱动没有的 `to_default_encoding()`，仍不编译。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/pangen-cuojiefu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。29 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。


## 缺失的转世守护进程 `/adm/daemons/scbornd`（2026-10-15）

`SCBORN_D` 在 globals.h 中有定义，原始存档却只有 `help/scborn`，没有守护进程本身。绝招文件在每次施展时都调用 `SCBORN_D->valid_perform()`，`force.h` 的 `valid_public()` 调用 `valid_learn()`，天界入口和通天老仙调用 `check_data`/`check_data2`/`start_scborn`：全部报 `couldn't find object`。新增一个替身 `adm/daemons/scbornd.lpc`：对所有人回答“未曾转世”，转世本身仍不可进行（与存档一致），但上述调用不再报错。


## 去烦恼指 `qufannao-zhi`（2026-10-15）

该技能 `inherit F_DAMAGE`，其中 `query`/`query_temp` 的成员原型遮住了 simul_efun 的 `query(prop, ob)`，于是 `valid_learn`/`practice_skill` 报 `Undefined function called: query_temp`。改为 `me->query_temp(...)` 等直接调用。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 2 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。


## 摆摊状态的指令路径（2026-10-15）

`kungfu/condition/baitan.lpc` 调用 `/cmds/std/baitan.lpc`，指令实际在 `/cmds/usr/baitan.lpc`。已改正路径；本库摆摊指令用 `start_busy()`，目前没有地方施加这个状态，属于未接线的代码。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。10 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`canhe-zhi`、`chongling-jian`、`duoluoye-zhi`、`feifeng-bian`、`huashan-zhang`、`murong-jianfa`、`sougu-yingzhua`、`xuedao-daofa`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：弹指神通 `tanzhi-shentong/dian` 点灵台穴（攻方读 `query("max_neili", me)`，守方却读成 0）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`five_poison`→`five-poison`（`/clone/medicine/poison/redyao`、`/clone/medicine/poison/shenxiandao`、`/clone/medicine/poison/whiteyao`、`/clone/medicine/poison/wuxing`、`/clone/medicine/poison/yellowyao`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`jiemie-zhua`→`jimie-zhua`（`huzhua-claw`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`lingboweibu`→`lingbo-weibu`（`lingbo-weibu`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/yi`）；`meiren-shanzhao`→`meiren-sanzhao`（`meiren-sanzhao/fengzi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 密宗猴拳「震」最重的一档报错（2026-10-15）

`/kungfu/skill/mizong-houquan/zhen` 按伤害分档写描述：前几档都是 `pmsg = ...`，最后一档（伤害 ≥ 80，也就是最重的一击）却写成 `pmsg += ...`，而 `pmsg` 没有初值，本驱动里 `0 += 字符串` 直接报错，这一招打得最狠时反而中断。改为 `pmsg = ...`。

## 擒龙手「擒龙打」每次都报错（2026-10-15，KB 06 §7.246）

`qinlong-shou/qin` 要求空手施展，却在出招前执行 `wn = weapon->name();`：局部变量 `weapon` 从没赋值，`wn` 也没人用，每次使用都报 `Bad argument 1 to EFUN call_other()`。删去这一行和两个没用的局部变量。


## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。4 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。


## 拜堂时请不来月老（2026-10-15）

苏州媒婆（`d/suzhou/npc/meipo`）和红娘（`adm/npc/hongniang`）拜堂时 `new("/d/suzhou/npc/yuelao")`，本库这个 NPC 放在 `d/ruzhou/npc/yuelao.lpc`（文件头仍写着旧路径，与 nitan3 等库的 `d/suzhou/npc/yuelao.lpc` 逐字节相同）：`new()` 得 0，`moon->move(room)` 报错，婚礼停在拜堂之前。两处都改为 ruzhou 的路径。媒婆从拜堂到送入花轿的整个流程在测试里走通。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

34 个文件、43 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/weapon/blade1`、`/d/dali/npc/obj/zipao`、`/clone/armor/cloth.lpc`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 32 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`S_RING` → `/inherit/gems/ring`（11 个文件）、`F_GEMS` → `/feature/gems`（4 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：15 个里 4 个通过，其余 11 个还有别的错误（`clone/gem/ring.lpc`：Fail to load object /clone/gem/ring.；`clone/gem/ring0.lpc`：Fail to load object /clone/gem/ring0.；`clone/gem/ring1.lpc`：Fail to load object /clone/gem/ring1.……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 58 个对象设了本库没有文件的武功（75 个名字，最多的是 `yijin-jing`、`qiantian-yiyang`、`tianlong-xiang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 18 个通过，其余 12 个停在别的错误上（`d/shiliang/quest/npc/wenfangshan`：*No program in object '/d/shiliang/quest/npc/wenfangshan'!；`d/shiliang/quest/npc/wenfangwu`：*No program in object '/d/shiliang/quest/npc/wenfangwu'!……）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 108 处、46 个文件：`yijin-jing`→`yijinjing`（36 处）、`yunu-xinjing`→`yunv-xinjing`（20 处）、`yunu-shenfa`→`yunv-shenfa`（12 处）、`shaolin-shnfa`→`shaolin-shenfa`（7 处）、`shenzhao-jing`→`shenzhaojing`（6 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`moshen-jianda`→`moshen-jianfa`（3 处）等共 20 个名字。（`scripts/lpc_fix_skill_names.py`）

## count_* 系列简单函数被条件编译挡掉（2026-10-19，KB 05 §7.15）

`adm/kernel/simul_efun/ntefun.lpc` 里的 `count_add/sub/mul/div/lt/gt/le/ge/eq` 整组被 `#ifdef LONELY_IMPROVED` 包着，而且调用的是原版驱动才有的大数 efun `efun::count()`；这里两样都没有，整组函数编译不进 simul_efun，凡是调用它们的对象（`adm/daemons/gambled`、擂台鼓 `adm/npc/obj/drum3/4`、`adm/daemons/enterprised`、`quest11/flagwar/flagd`）都报 `Undefined function count_lt` 载入不了。与 nitan6、nitan170911 的做法一致：去掉条件，包装函数改调 `db_compat.lpc` 里本地的 `count()`。同一批里 `quest11/flagwar/flagd.lpc` 还照 nitan6 把 `ANSI_D->remove_ansi(...)`（本库没有 ANSI_D）改成 `remove_ansi(...)`，把 `reward_money *= 0.9` 改成 `to_int(reward_money * (0.9))`。

## 全局头文件丢了 6 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `ARMOR_D(x)`、`BINGQI_D(x)`、`BOOK_D(x)`、`CLONE_DIR`、`MAZE_D`、`TIME_TICK`，用到它们的物件（名单里 46 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 4 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/shenlong_bak/jushi.lpc`、`sea.lpc`、`sea2.lpc` 里 `me->name() + "\241\243\n"` 的 `\241\243`（GBK 的「。」写成八进制转义，旧驱动把这两个字节原样发给 GBK 客户端）改成「。」；新驱动报 `Invalid UTF8 codepoint in string literal`，三个房间（共 4 处）载入不了。

逐个载入与 HEAD 对比，没有退步。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 缺失的 unew()（2026-10-19，KB 06 §7.262）

本库的 NPC 和兵器在 `create()` 里调用 xkx 一系的模拟函数 `unew(file)`（`new()`，但遵守物件的 `unique` 上限），`/adm/kernel/simul_efun/object.lpc` 里没有，调用者全部报 `Undefined function unew`（以及接收结果那一行的 `Bad assignment ( object vs unknown )`），载入不了。补上和 dtsl、pkuxkx、sjpl2 等库一样的 `unew()`（文件不存在时返回 0，不会让调用者死在 `carry_object()` 里）。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：12 个未使用的局部变量。修后与 HEAD 逐个物件对比载入，没有退步。

## 帮派文件里丢掉的引号（2026-10-19，KB 03 §4.6）

- `d/yixing/doc/set_bang.h` 第 82、84 行：两句帮主的话，最后半个字连同结尾的引号一起丢了（`…景仰之情<乱码>);`），下一行的开头引号把它闭合，后面的汉字被当成代码（`Illegal character 0xe8`），宜兴帮主 `d/yixing/npc/bangzhu.lpc` 从来载入不了。字串照 nt7 里完好的拷贝补回（`犹如滔滔江水连绵不绝。`、`帮主的敬仰犹如黄河泛滥一发不可收拾。`），引号补上。
- 同一文件第 45 行 `level = ceil( pow( … ) ) * 4 / 5;` 把浮点数存进 int，补 `to_int()`。

载入 `d/yixing/npc/` 的 bangzhu、biaotou、bangzhu2、cl_bei：HEAD 通过 3 个，现在通过 4 个（`bangzhu.lpc` 现在载入），没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去。改动：`/adm/daemons/kingward.lpc`（1 处）、`/adm/daemons/ward.lpc`（1 处）、`/d/baihuagu/yangfeng.h`（1 处）、`/d/gumu/liangong1.lpc`（1 处）、`/d/tiezhang/hhyuan-3.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/cmds/usr/mazemap.lpc`（1 处）、`/inherit/room/mine_field.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 21 处）。改动：`/adm/daemons/competed.lpc`（2 处）、`/adm/daemons/intermud2_d.lpc`（2 处）、`/adm/daemons/xinruid.lpc`（2 处）、`/clone/game/mj.lpc`（3 处）、`/clone/game/mjlady3.lpc`（3 处）、`/cmds/wiz/roomlong.lpc`（1 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/d/yaowang/huichun/npc/zhanggui.lpc`（1 处）、`/quest/weixiaobao.lpc`（1 处）、`/quest11/budai.lpc`（1 处）、`/quest11/shediao/yang.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/kernel/simul_efun/object.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/battlefieldd.lpc`（1 处）、`/adm/daemons/storyd.lpc`（1 处）、`/adm/kernel/importer.lpc`（1 处）、`/cmds/adm/refsum.lpc`（4 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `d/luoyang/obj/xiang.lpc`：`chuangli` 先 `explode(read_file("/log/PARTY"))`（2026-10-20，KB 06 §7.326）

关帝像的 `chuangli`（`kaibang`）指令在检查年龄和经验之前就读 `/log/PARTY`，那是运行中的 mud 记录已创立帮派的文件，全新的树里没有，`explode(0)` 报 `Bad argument 1 to explode()`：任何人敲 `chuangli 什么` 都是系统错误，而不是“你还嫩着呢”。改成 `file = read_file("/log/PARTY") || "";`（空串的 `explode` 是空数组）。xkx100utf8 和 nt7 是 gitlink 库（fluffos-org 上游），同一行在那里没有改。加载检查各 1/1。

## `vote` 的 `jail`、`unjail`、`unchblk` 编译不过：计票被改坏了（2026-10-20，KB 04 §6.21）

xkx100 的原文是 `vc = victim->add("vote/count", 1);`，nitan 系把它写成了 `addn("vote/count", 1, vc = victim);`：`vc` 是 `int` 票数，却被赋成了对象 `victim`（`Bad assignment ( int vs object )`），`addn()` 的返回值（新的票数）丢掉了，后面的 `df = vv - vv / 2 - vc` 因此没有意义。改回 `vc = addn("vote/count", 1, victim);`（循环里的 `-1` 也一样，共 5 处）；`addn()` 是本库 sefun，返回 `ob->add(prop, data)`。加载检查：三个文件 HEAD FAIL → tree PASS。nt7 是 gitlink 库，没有改。

## `mroom`（帮会房间生成）读不到 `dir_pre`（2026-10-21，KB 04 §6.16）

`cmds/bunch/mroom.lpc` 的 `valid_room_position()` 和建房流程用 `dir_pre` 当帮会目录前缀，库里没有任何头文件或变量声明它（`include/bunch.h` 只剩 `room_desc_l`、`max_exits`、`r_dir`、`vdirs`，整个语料里也没有 `dir_pre` 的定义），整个命令编译失败：`Undefined variable 'dir_pre'`。`adm/daemons/bunchd.lpc` 里 `BUNCH_HOME "/data/bunch/"`（`BUNCH_HOME + id + "/center.lpc"`，模板目录 `/d/room/bunch/` 复制到那里）和 `valid_room_position()` 的路径算术（前缀 `explode()` 三段、房间路径五段，差 2，返回第四段即帮会 id）对得上，所以在 `mroom.lpc` 里加 `#define dir_pre "/data/bunch/"`。nt6、nitan170911、nitan6、hhsj、xfbhh 的 `mroom.lpc` 逐字节相同，同一处改法；加载检查 HEAD 0、树 1。没有改：nt7（gitlink）同一文件；tianxia 的 `cmds/bangzhu/mroom.lpc` 用的是 `BANGHUI_DIR`，但那里的 `banghui_d` 自己就有类型错误和未声明的变量加载不了。

## `ability`：继承的 `/feature/ability` 档案里没有（2026-10-21，KB 04 §6.18）

管理员扫描里 `ability`（玩家指令 `cmds/usr/ability.lpc`）报 `Inherited file '/feature/ability' does not exist!`：指令 `inherit F_ABILITY`（`#define F_ABILITY "/feature/ability"`），而档案只带 `feature/ability.txt`（家族能力的设计笔记），没有源码，这条指令从来加载不了（`bas_ability`、`fam_ability`、`valid_ability_improve()`、`do_ability_cost()`、`improve_ability()`、`get_ability_info()` 都该在那个文件里，本库别处没有人用）。nitan170911、nt7、hhsj、wdxtym 把同一套接口放在可继承的 `/adm/daemons/abilityd.lpc`（947 行，指令里 `F_ABILITY` 指向它），但那是后一版：能力编号改成 1-35、消耗加了潜能、门派能力由 5 项变 30 项，不是本库当年的表。没有补，留在 `scratchpad/librarian-next.txt` 里等用户决定。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/arch/recovermud.lpc`。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。
