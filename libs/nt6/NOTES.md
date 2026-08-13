
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
