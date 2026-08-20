
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
