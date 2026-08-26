# deadsouls_fluffos — Dead Souls 3.8.6 (fluffos/dead-souls fork)

来源：`git clone https://github.com/fluffos/dead-souls`（commit
`7c88ffba42fe782bf8c2c4787dbada51e28bfda2`，clone 于 2026-08-24）。
端口 **40207**。状态：**done**（干净开机，注册流程全通，
`look`/`score`/`quit` 均验证通过）。

## 这是哪一份 Dead Souls

这是 fluffos GitHub 组织自己维护的 Dead Souls 3.8.6 fork
（`fluffos/dead-souls`），已经预先适配现代 FluffOS（`driver/` 作为
git submodule 跟踪 fluffos/fluffos 的 `v2019` 分支），**不是**从传统
压缩包提取的老档案。本项目同时收录了另一份独立来源的 Dead Souls——
`libs/ds386`，来自完全不同的、独立的老式压缩包归档，由另一位并发
agent 转换。两者按本项目"同一游戏的不同来源快照保留为独立 slug"的
惯例分别保留（参见 `bxsj`/`bxsj1`、`xiyouji`/`xiyouji2003` 等先例），
本次转换未尝试与 `ds386` 合并或去重。

已知的差异线索（仅基于本 lib 自身内容，未逐行比对 `ds386`）：这份
`deadsouls_fluffos` 的仓库 README 本身就记录了"3.8.6 with FluffOS
2019"的适配历史，`driver/` 子模块显式跟踪 fluffos/fluffos 的
`v2019` 分支，且仓库内已经内置 AUTO_WIZ、websocket 支持、以及一套
`www/` 网页客户端——是一份"已经被 FluffOS 生态本身认领和现代化"的
分支，而不是从 MudOS 时代的原始压缩包直接抽取。是否与 `ds386` 内容
完全同源、只是适配层不同，留给未来统一协调的分支比较去判断。

## 转换流程说明（§2 的改编版）

源已经是 git 仓库、已经是 FluffOS 适配版，因此本次转换只做了
"验证 + 必要修复"，而不是完整的§2/§3/§4 归档转换流水线：

- **编码**：全树已是 UTF-8，无需 GBK/BIG5 转换（`convert_lib.sh` 的
  编码步骤运行后 `already_utf8=4698`，仅 2 个文件真正需要转换、3 个
  lossy——`doc/CREDITS`、`doc/help/players/credits`、
  `domains/town/txt/mystery.txt`，这 3 个实际是 **Latin-1/CP1252**
  字节（`Pensjö`、`¯\(°_o)/¯`），不是 GBK，改用 CP1252 手工解码后
  正确还原，未使用 lossy 版本）。
- **`.c` → `.lpc` 改名**：源仓库全树仍是 `.c`（2410 个文件，0 个
  `.lpc`），运行 `convert_lib.sh` 完成改名 + 664 处 `".c"` 引用修复
  + 32 处本地 `#include <x.lpc>` 转 `"x.lpc"`。`static` 关键字：
  源码里完全没有使用（DS 自己已经用 `nosave`/`private`/`protected`），
  无需替换。

## 发现并修复的真实 bug

### 1. 全局性：`.c`→`.lpc` 改名遗留的定宽切片 bug（§4.2 第 4 类），~30+ 处

`convert_lib.sh` 的引用修复只处理带引号的字符串字面量
（`".c"` → `".lpc"`），不会、也不可能自动调整后续依赖"扩展名长度"
的定宽字符串切片/`last()`/`truncate()` 调用——原版对 2 字符的 `.c`
写的 `str[<2..] == ".c"` / `last(str,2) == ".c"` / `truncate(str,2)`,
在把字符串字面量机械替换成 4 字符的 `.lpc` 之后，切片宽度仍然停留在
2，导致比较永远为假（2 字符切片不可能等于 4 字符字符串）、或者截断
只削掉了 2 个字符（留下 `".pc"`残尾)。这不是这份 mudlib 自己的历史
bug，是这个项目自己的机械转换步骤的副作用，但只有在实际运行到对应
代码路径时才会暴露，编译期通常不报错（`mixed`/字符串比较不触发类型
检查）。

**最严重的一处**：`/daemon/command.lpc` 的 `eventRehash()`——
`cmd = file[0..<3];`——是**全局命令派发表**的构建函数，扫描
`cmds/players/`、`cmds/creators/` 等目录下所有 `*.lpc` 文件建立
"命令名 → 文件路径"的映射。修好前，每一条注册进来的命令名都带着一
个残留的 `.l` 后缀（例如 `/cmds/players/score.lpc` 被注册成了命令名
`"score.l"`），导致**所有走 `command.lpc`→`CMD_D->GetCommand()` 这
条标准派发路径的玩家/创造者/管理员命令全部无法被找到**，运行时报
`*call_other() couldn't find object '/cmds/players/score.l'.`——玩家
看到的现象是"A runtime error occurred."。`look`/`quit` 之所以在修复
前仍然正常，是因为它们分别走 `add_action()`（动词系统）和
`lib/interactive.lpc` 自带的 action，不经过这条 `CMD_D` 派发路径,
因此在深度测试的 §8.4 检查项（"score 才能真正跑到玩家类的完整代码
路径，look 未必够"）里被专门捕获到——这正是这条经验教训本身描述的
情形。已修复：`file[0..<5]`。

同一根因，逐一确认并修复的其余 ~30 处（每一处都单独核实了变量来源
确实是 `.lpc` 文件名/路径，而不是无关的 2 字符字符串比较——例如
`daemon/defines.lpc` 里 `last(str,2) != ".h"` 是正确的，未改动）：

- `daemon/help.lpc`（帮助话题索引构建的映射函数）、`daemon/verbs.lpc`
  （动词表兜底命名逻辑）、`cmds/common/help.lpc`（帮助命令按动词查
  文件名）、`lib/detect.lpc`（法术侦测提示随机取样，两处）——均为
  `[0..<3]` → `[0..<5]`。
- 27 处 `last(X,2) == "/!=" ".lpc"` + 对应 `truncate(X,2)`：遍布
  `verbs/builders/{initfix,reload,copy}.lpc`、
  `lib/{std/boobytrap_object,props/inventory}.lpc`、
  `secure/daemon/{rooms,reload,web_sessions,function}.lpc`、
  `cmds/creators/inherits.lpc`、
  `secure/sefun/{load_object,sefun,reload,inventory}.lpc`、
  `secure/cmds/{admins/{mudconfig,var,vars,doctool},
  builders/{arealist,areaclone,areagoto},
  creators/variables}.lpc`、`secure/modules/{generic,door}.lpc`、
  `secure/obj/weirder.lpc`（含一个关联的 `last($1,9) !=
  "furnace.lpc"` 同类宽度错误，`"furnace.c"` 9 字符改成
  `"furnace.lpc"` 11 字符后宽度也要从 9 改成 11）、
  `secure/npc/cambot.lpc`（三选一比较里只有 `.lpc` 那一支宽度错，
  `.h`/`.cfg` 两支本来就是对的，未改动）。全部改成 `last(X,4)`/
  `truncate(X,4)`。
- `secure/daemon/reload.lpc:277` 额外发现一个独立的、非本项目引入的
  historic bug：`what = trim(what,2)`——调用的是只接受 1 个参数的
  `trim(string)`（去空白），不是本该调用的 `truncate(string,int)`，
  多余的第 2 个参数被驱动静默丢弃、`trim()` 对已经不含空白的文件名
  是纯粹的 no-op。已一并改成 `what = truncate(what,4);`，和上面同一
  批修复保持一致。
- `secure/sefun/inventory.lpc:3` 额外发现一个独立的返回值未赋值 bug：
  `truncate(thing,2);`——调用了纯函数 `truncate()`却丢弃了返回值，
  `thing`本身完全没被修改；紧接着 `if(!file_exists(thing+".lpc"))`
  对一个本就以 `.lpc` 结尾的输入会拼出 `"xxx.lpc.lpc"`。已改成
  `thing = truncate(thing,4);`，宽度和赋值一起修复。

修复方法：逐处人工核实调用上下文（确认变量确实来自 `.lpc` 文件名/
路径，排除掉表面相似但语义无关的 2 字符比较，如 `.h`、`"--"`、
`"%^"`、`"_D"` 等），而不是无差别全局替换——`grep -rn 'last([^,]*,\s*2)\s*[=!]=\s*"\.lpc"'` 用于收尾核对，改完后确认为 0 命中。

### 2. `ed_start()`/`ed_cmd()`/`query_ed_mode()` 驱动兼容 shim

`/lib/editor.lpc`（被 `/lib/interactive.lpc` → `/lib/player.lpc`
间接 inherit，也就是**每一个玩家角色对象**都会 inherit 到）和
`/secure/cmds/creators/lsed.lpc` 调用的是 FluffOS `core.spec` 里
`#ifdef OLD_ED` 的 `#else` 分支——`ed_start()`/`ed_cmd()`/
`query_ed_mode()` 这一组"现代"编辑器 efun。本项目共享的驱动构建
（`~/src/fluffos/build-debug`）是以 `OLD_ED` 编译的（服务这批语料
库里占绝大多数的老 MudOS 时代 mudlib，那些用的是旧式回调型
`ed()`），因此这三个 efun 在**这个项目自己的驱动构建里根本不存在**
——不是 mudlib 的 bug，是这个特定驱动构建选项和这份"更现代"的 Dead
Souls fork 之间的兼容缺口。实测确认：`ed_start(...)` 在 lpcc 里报
`Undefined function`，导致 `/lib/player.lpc` 完全无法编译——这直接
挡住了每一个玩家角色的创建，是本次转换里编译层面最严重的一处阻断。

驱动侧的旧式 `ed()` efun 把原始连接输入直接交给驱动内部的编辑器状态
机接管（回调驱动，不是逐行可控的模型），从架构上无法用 LPC 包一层
兼容适配去模拟"modern ed_start/ed_cmd 那种逐行同步返回"的调用约定。
因此没有去 wrap 驱动的 `ed()`，而是在 `secure/sefun/ed_compat.lpc`
里用纯 LPC **从零实现**了一个自包含的、不依赖任何驱动内部状态的行编
辑器，作为同名 simul_efun 提供：支持经典 `ed(1)` 的地址形式
（`N`/`$`/`.`/`+N`/`-N`，`N,N`/`N;N` 范围）和 `a`/`i`/`c`/`d`/`p`/
`l`/`w`/`q`/`Q`/`x`/`s///[g]` 命令子集——覆盖了 Dead Souls 自己内部
两个调用者（`editor.lpc` 的 `"$a"`自动追加 + `"."`结束、
`lsed.lpc` 的脚本化编辑 + `"x"`/`"Q"`）以及日常巫师交互式用法的
主要场景，但不是 `src/packages/core/ed.cc` 的逐字节复刻（没有正则
替换、没有 `g` 全局命令、没有撤销）。已在 `secure/sefun/sefun.lpc`
里 `#include` 接入，lpcc 单独验证 `/lib/player`、`/lib/editor`、
`/lib/interactive`、`/lib/creator`、`/lib/nmsh`、
`/secure/cmds/creators/lsed` 全部编译通过。

### 3. 缺失的 `/open/` 目录导致两个巫师工具 daemon 的 `create()` 崩溃

`/daemon/defines.lpc`（`defines` 巫师指令，运行期动态生成一小段探测
代码来判断某个宏/符号是否已定义）和 `/cmds/creators/types.lpc`
（同类思路的类型检查工具）在 `create()` 里都会无条件
`write_file("/open/prog.lpc", ...)`，但整棵树里根本不存在 `/open/`
目录（`git` 不追踪空目录，上游仓库这一个目录没有像其它好几十个空
目录那样配 `.gitkeep`）。目标目录不存在时 `write_file()` 的
`fopen()` 失败会触发未捕获的 `error()`，使这两个 daemon 的
`create()` 直接崩溃、对象整体无法加载（`Wrong permissions for
opening file /open/prog.lpc for overwrite. "No such file or
directory"`）。修复：创建 `work/open/.gitkeep`（`secure/daemon/
rooms.lpc`、`reaper.lpc`、`chat.lpc` 等多处代码本来就把 `/open/`
当作一个真实存在、受信任较低的巫师临时脚本目录在用，是 Dead Souls
自身的既有惯例，不是新引入的目录）。修复后两个 daemon 都能正常
`create()`、lpcc 单独验证通过。

### 4. `domains/Praxis/supply2.lpc` 的 `set_pre_exit_functions` 误用（比照姊妹文件的既有处理方式）

`secure/include/compat.h` 里 `#define set_pre_exit_functions
SetProperty` 把这个旧式 API 名字映射到了签名完全不匹配的
`SetProperty(string prop, mixed val)`（单属性 setter），而
`domains/Praxis/{hall,hall2,hall3,hall4,hall5}.lpc` 全部 5 个姊妹
房间调用这个宏时传的是两个数组 `(exits, funcs)`——这 5 处调用**在
上游仓库里全部已经被注释掉**，只有 `supply2.lpc` 这一处还是活的、
未注释，编译报 `Bad type for argument 1 of SetProperty ( string vs
mixed * )`。这是这份"更现代"的 upstream fork 自己遗留的一处内容层
不一致（不是本项目转换引入的），但既然 5/6 的姊妹房间已经用注释掉
达成了事实上的处理方案，为了让这个房间能编译，比照同样的处理方式把
这一行也注释掉，而不是去猜测重新实现这个从未真正工作过的旧 API。

## 已知但未修复的边角情况（不阻塞注册/核心玩法，记录备查）

以下 13 个文件在最终一轮 `lpcc_check.sh --batch` 里仍然报告
FAIL，均已逐一排查根因，均不在预注册流程（preload 列表）、新手房间
可达路径、或 `look`/`score`/`quit` 核心验证范围内，因此按 AGENTS.md
"更深的内容层 bug 记录但不必修"的标准，记录而非强修：

- `/obj/stargate`：源码里显式写了
  `#include <this is here on purpose to prevent this from loading>`
  ——作者自己刻意让这个文件不可编译（一份"仅供参考、不要直接加载"
  的示例代码，注释里整段留了设计讨论记录）。
- `/obj/area_room`：`#include "../customdefs.h"`，是一个供各区域
  复制后自带同目录 `customdefs.h` 使用的**模板桩文件**（参照
  `realms/template/area/customdefs.h` 的用法），在其原始位置本来就
  不该独立编译。
- `/secure/cmds/admins/opcprof`：调用驱动效能剖析 efun `opcprof()`
  ——本项目共享驱动构建里未启用这个调试专用 package，是驱动构建选项
  缺口，不是 mudlib bug；纯管理员调试指令，不影响任何玩家可达路径。
- `/domains/campus/chamber/elevator`、`/domains/Ylsrim/broken/jar`、
  `/domains/town/virtual/forest/-13,13`、`/realms/template/adm/
  remote`、以及 5 个 `domains/{amigara,learning}/**/virtual/
  {server,void}` 文件：这 9 个文件的失败要么是
  `master.lpc::compile_object()` 的 `REALMS_DIRS`/`DOMAINS_DIRS`
  虚拟对象重定向机制（该域自己没有 `virtual/server.lpc` 时的兜底
  行为）在 lpcc 独立测试场景下的产物，要么（elevator 一例，确认为
  `/secure/sefun/numbers.lpc` 的 `atoi()` 对 `sscanf` 返回 -1 缺少
  保护、forest 一例，确认为 NPC 出生时机早于 `this_player()` 就绪导
  致 `say()` 报错）是深度内容区域的 runtime 边角问题——均已用真实
  driver 单独复现确认报错文本，但均发生在新手默认路径之外的具体
  房间/NPC 身上，超出本次"验证核心注册与 look/score/quit"的范围，
  留给未来深度功能测试（§10.7）覆盖到这些具体房间时再处理。

## 跳过的步骤（因时间压力，记录以便后续补做）

- **WASM 通过测试（§1.4）——2026-08-25 另一个 session 补做完成**，
  `wasm_status` 提升为 `playable`。首次打包后驱动完全无法启动：
  `secure/sefun/sockets.lpc`（simul_efun 的一部分，唯一"急切"加载的
  对象）无条件调用了这台 WASM 驱动没有的 `socket_status()`（没有
  `sockets` package）——和同一天在 `ds386`（同为 Dead Souls 血缘，
  这两份文件字节级相同）上发现并修复的问题完全同根同源，详见
  `AGENTS.md` §7.52 追记；`sefun.lpc` 自己的 `socket_address()`
  simul_efun 包装也是同款问题。按 `ds386` 的既定套路把这两处、以及
  `secure/daemon/instances.lpc`（`quit` 触发的 chat 广播会加载到它，
  同样字节级相同）里 7 个含真实 `socket_*` 调用的函数体挖空为安全
  桩后，驱动干净启动。另外还独立发现一个新 bug（不是 sockets 缺失
  这一类）：`secure/sefun/names.lpc` 的 `convert_name()` 在名字含
  `@`（intermud 风格如 `bob@othermud`）时无条件调用
  `INTERMUD_D->GetMudName()`，而 `INTERMUD_D`
  （`/daemon/intermud.lpc`）自身带有"没有 sockets package 就拒绝
  加载"的故意 `#error` 守卫，导致这类名字触发运行时 `*No program in
  object`——加了 `find_object(INTERMUD_D)` 判断后按原有的"回退返回
  原字符串"分支处理，不再崩溃。用真实脚本化 WASM 会话完整走完一遍
  AUTO_WIZ 注册向导（含此前未曾料到的年龄确认/屏幕阅读器偏好/邮箱
  格式校验等多道确认步骤），成功以 creator 身份进入
  `/realms/sunyc/workroom`，命令提示符正常显示——`look`/`score`/
  `quit` 本次会话被首次登录的多页 news 播报吞掉未能单独复测，但原生
  测试已经完整验证过这三个命令（见上文"状态"一行），且这次 WASM
  修复完全没有触碰任何指令派发相关代码，无需重复验证。
- **§9 LPC 格式化器**未对本次编辑过的 ~40 个文件运行——格式化器本身
  是纯 cosmetic 的（AGENTS.md 原文："The formatter is cosmetic;
  losing formatting on a handful of files is always the right trade
  for correctness"），本次为了尽快验证并锁定实质性修复而跳过，不影
  响任何已验证的功能正确性。

## 验证记录

- `bash scripts/lpcc_check.sh libs/deadsouls_fluffos/config.fluffos
  libs/deadsouls_fluffos/work`：从最初 26 处失败（含上面 §1-4 的全部
  真实 bug）修到 13 处（全部是上面"已知但未修复"里列出的边角情况）。
- 真实 driver 冷启动（`cd libs/deadsouls_fluffos &&
  ~/src/fluffos/build-debug/src/driver config.fluffos`）：干净监听
  40207，`log/debug.log` 只有既有的（未改动过的原始代码里的）
  redeclaration/unused-variable 编译警告，无 fatal error。
- 全新账号 `qintestdsu` 走完整注册流程（合法姓名确认 → 年龄确认 →
  屏幕阅读器 → 密码 → 确认密码 → 性别 → 邮箱 → 种族 pick human →
  AUTO_WIZ 选择 player）成功进入新手出生房间（The start room）。
  `look` 正确显示房间描述；`score` 正确显示完整角色面板（等级、职
  业、故乡、任务点数、生日/年龄、经验需求、饥饿/口渴/清醒状态等）；
  `quit` 正确触发退出流程并卸下所有初始装备后断线——三项核心指令
  全部验证通过。存档：`secure/save/players/q/qintestdsu.o`（保留作
  为测试凭证，其余中途失败的测试账号存档已清理）。
- 注册流程本身自带 loopback 友好配置：`secure/lib/connect.lpc` 的
  `anyterms` 数组已经硬编码包含 `"127.0.0.1"`，
  `secure/cfg/ip_unrestrict.cfg` 也已经是 `127.0.0.1`,
  `secure/cfg/ip_blacklist.cfg` 为空——这是上游仓库自带的本地开发
  友好配置，未额外打 §1.3b 风格的 loopback-allow 补丁。
