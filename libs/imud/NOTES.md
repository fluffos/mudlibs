# imud — IMUD@FluffOS.v2019

来源：`git clone https://github.com/fluffos/imud`（克隆时 HEAD 为
`6b232d4 Add WASM pack script + GitHub Pages deploy workflow`，
2026-08-24 克隆）。编号 161，端口 40209。状态：**done**（干净启动，
两个命令均验证可用；这个 lib 本身就没有登录/注册/游戏世界，见下）。

## 这个 lib 到底是什么

**不是游戏。** 这是 FluffOS 驱动项目自己在 <https://imud.fluffos.info>
上跑的官方演示，仓库描述就是 "source code for imud.fluffos.info"。整个
`work/` 只有 23 个 `.lpc`/`.h` 文件（原始 `.c`），核心逻辑是：

- `secure/master.c`：极简 master，`epilog()` 只 preload 一个文件
  （`/secure/imud/imud.c`），`valid_read`/`valid_write`/`valid_socket`
  全部无条件返回 1（没有任何访问控制——这是一个单纯的技术演示，不是
  拿来给陌生人开放注册的正式服务器）。
- `secure/user.c`：**没有登录/注册流程**。`connect()` 直接
  `new("/secure/user.c")`，`logon()` 打印欢迎语后立即
  `enable_commands()`，全程没有问 ID、没有问密码、没有存档读写。
- 只有两个可用命令（`secure/commands/`）：
  - `mudlist`：通过 `secure/imud/imud.c`（一个相当完整的 Intermud-3
    协议实现，`imud_d.c`/Deathblade 1995 年的经典 I3 daemon）向真实的
    公网 I3 路由器（`*i4`, `204.209.44.3:8080`）发起 socket 连接，列出
    当前挂在 I3 网络上的真实 MUD。这是这个演示唯一有实质内容的功能。
  - `update <path>`：`destruct()` 再 `load_object()` 指定路径，用于
    演示者热更新代码，**没有任何权限判断**——这是设计如此（单人本地
    演示环境），不是要修的 bug。
- `secure/imud/imud/` 目录下还打包了完整 Intermud-3 扩展协议族的源码
  （`channel.c`/`tell.c`/`emoteto.c`/`who.c`/`finger.c`/`locate.c`/
  `oob.c`/`file.c`/`mail.c`），但 `imud.c` 里只 `inherit` 了
  `daemon_data`/`reconnect`/`mudlist` 三个，其余全部注释掉——这是上游
  仓库自己就没启用的功能桩，不是转换过程引入的缺失。

## §2.2 On-sight checklist 结论

按 AGENTS.md §2.2 逐项检查，全部不适用/无发现：
- master 的 `load_object`/`get_root_uid`/`get_bb_uid` 读取正常，没有
  `get_include_path()` 需求（所有 include 都是相对路径或 `__DIR__`
  拼接，能直接解析）。
- 没有 `securityd`/`is_chinese`/`check_legal_name`——没有账号系统。
- 没有 `adm/etc/preload` 数据文件，没有命令分发私有钩子问题。
- 没有硬编码的 `MUD_PORT`/`PORTNO`；`imud.c` 用的是驱动内建宏
  `__PORT__`（取自 config 的 `port number`），随 config 走，不会重蹈
  AGENTS.md §5.3 那个"端口写死导致连接被拒"的坑。
- 没有 `static`、`ed_start`、裸 `switch...default`、`efun::` 用法。
- **WASM 三板斧（loopback-allow 补丁 / legacy-gate bypass / §1.5 管理员
  账号播种）均不适用**：这个 lib 根本没有登录、没有 ban/site 网关、
  没有账号/wizard 权限体系可以播种。`mudlist.c` 里唯一一处
  `wizardp(this_user())` 判断只是决定要不要多打印一行提示，不影响任何
  功能。

## 转换（convert_lib.sh）

已经是现代 FluffOS 仓库，直接跑
`scripts/convert_lib.sh libs/imud/raw/imud libs/imud/work`：
- 编码：42 个文本文件全部已是 UTF-8（0 次实际转码），5 个二进制文件
  （favicon.ico、xterm.min.js 等前端资源）按扩展名/`file` 判定跳过，
  行为符合预期。
- `.c`→`.lpc` 重命名：23 个文件，`.c"` 引用自动修复 9 处，事后 grep
  确认 0 处残留、没有遗漏的大写 `.C` 文件、没有 `static`。

## `config.fluffos`

原始 `config.txt` 只有 `external_port_1: websocket 7878`，没有普通
telnet 端口——这个项目的 `mudclient.py` 走原生 telnet，所以改成标准的
`port number : 40209`（分配端口）而不是 websocket；没有照搬原仓库的
websocket/`secure/www` 网页客户端配置（那是给 imud.fluffos.info 网站
用的，本项目不需要）。其余数值参数（eval cost、hash table size 等）
沿用其它 lib 的标准模板值，因为原始 `config.txt` 完全没有配置这些
（是驱动的默认值），不是原样照搬某个"权威"配置。

## 编译扫查（lpcc_check.sh）

23 个文件，15 PASS / 8 FAIL。**8 个失败全部是上面提到的、`imud.c`
里被注释掉未启用的 I3 扩展协议模块**（`emoteto`/`file`/`mail`/`who`/
`oob`/`channel`/`locate`/`finger`），单独编译时报缺 `commands.h`/
`log.h`/`socket.h`/`ports.h`/`daemons.h`/`security.h` 等本仓库根本没有
的头文件，以及 `this_body`/`find_body`/`find_user`/`tell`/`mud_name`/
`convert_time`/`DBBUG`、`IMAIL_D`/`CHANNEL_D`/`CMD_OB_TELL`/
`DIR_I3_FILES` 等未定义的函数/全局宏——这些模块显然是从一个更完整的
mudlib 里摘出来的骨架，依赖那个宿主 mudlib 才有的基础设施，从来没有
打算在这个极简演示仓库里独立编译或运行。确认它们**不会被任何活跃代码
路径加载**（`grep` 全仓库，除自身文件外唯一的引用就是 `imud.c` 里那些
被注释掉的 `inherit` 行）——按 AGENTS.md 的 scope 原则，这是上游仓库
自带的、从未启用过的死代码，不是本次转换引入的回归，不修。真正被
`inherit`/加载的 15 个文件全部 PASS。

## 启动与实测（原生驱动）

`cd libs/imud && ~/src/fluffos/build-debug/src/driver config.fluffos`：
干净启动，`log/debug.log` 无 FATAL、无 `Fail to load` （除上述已知的
死代码模块外）。`mudclient.py` 连接验证：

- 连接后立刻收到欢迎语 + "The only command supported are: mudlist"
  + IMUD 状态块，无需任何登录/注册输入。
- `mudlist`：真实连上公网 I3 路由器，返回了几十条当前在线的真实 MUD
  （FluffOS/LDMud/CoffeeMud/DGD 等），列表里能看到我们自己这次启动的
  实例 `IMUD@FluffOS.v2019`（本机公网 IP，端口 40209）。功能符合预期。
- `update /secure/commands/mudlist`：正常 reload，回显 "Done."——验证
  了唯一另一个命令也能用。
- `look`/`score`/`quit`：均无对应命令实现，返回默认的 "What?"——**这是
  正确行为，不是 bug**：这个 lib 从未实现过这些命令，"注册进游戏世界
  再验证 look/score/quit" 这条 AGENTS.md §2 的通用验收标准在这里不适用
  （没有游戏世界，没有玩家对象存档）。已验证的等价物是：连接即可用、
  两个命令都工作、未知命令有合理的兜底响应。

**⚠️ 重要：启动这个 lib 会发起真实的公网出站连接。** `imud.c` 的
`create()` 会立即触发 `reconnect()`，真实 socket 连接到
`204.209.44.3:8080`（I3 路由器 `*i4`）并完成握手——不是沙盒模拟，是
真实的第三方服务器。握手完成后我们的实例会短暂出现在真实 I3 网络的
mudlist 里。这是原始演示故意如此设计（整个 lib 的存在意义就是演示这个
协议），不是要修的 bug，但和语料库里其它所有 lib（纯本地、不出网）性质
不同——**以后如果对这个 lib 跑自动化重复开机测试（比如 §10.0 那种
long-sit 扫描或轮次性重测 cron），要意识到每次启动都会真的连一次公网
I3 网络**，建议：(a) 不要把这个 lib 纳入高频率的自动重启测试队列；
(b) 如果需要频繁重启测试，考虑给 `reconnect()`加一个仅用于本项目
CI/沙盒场景的开关（本次未做——没有被要求修改这个核心演示功能，属于
"design"，不是 bug）。

## WASM 实测

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src libs/imud
--send "" --send "mudlist" --send "quit"`（本机默认 `PATH` 没有
`node`，用的是 `~/.local/opt/node/bin/node`）：干净启动，同样没有登录
流程，两个命令都能跑，无 FATAL。唯一的行为差异：`secure/imud/socket.c`
编译失败——`socket_address`/`socket_write` 是 `Undefined function`
（WASM 构建没有 `sockets` 包，AGENTS.md §1.3c 记录过的已知策略级差异，
不是本 lib 特有的 bug）。`imud.c` 的 `reconnect()` 本来就把
`clone_object(SOCKET)` 包在 `catch()` 里，所以这个编译失败被优雅捕获，
不影响后续任何东西——`router_socket` 保持未设置，`mudlist` 正常执行完，
只是返回 "0 matches out of 0 muds"（空列表，因为拿不到真实 I3
路由器数据）而不是崩溃或挂起。判定 `wasm_status: playable`——启动、
两个命令、退出全部正常，唯一退化的是 `mudlist` 的实际内容（这本来就是
WASM 环境天然拿不到公网 socket 的必然结果，无法用 mudlib 侧代码
修复，也符合 §1.3c 里"sockets 包缺失导致的功能整体缺席，按 playable
处理"的既有先例）。

## 深度功能测试 / Deep functional test（round two, 2026-08-27）

标准 §10.7 round-two checklist（注册→移动→人物信息→战斗→门派/技能→
quit-重连）在这个 lib 上整体不适用——见上面「这个 lib 到底是什么」：没有
账号系统、没有房间地图、没有战斗/技能/门派，`connect()` 直接丢进匿名
`secure/user.c` 会话。本轮把同一条原则（不要只读源码就假设能用，实际
连上一个真跑着的驱动，把每一个真实功能都点一遍）适配成这个 lib 实际
拥有的东西：**boot 真实原生驱动 → 用真实 socket 客户端把两个命令
（`mudlist`/`update`）连同未知命令兜底都跑一遍 → 每次都检查
`log/debug.log` 以外的运行时错误日志**（`work/log/log`/`work/log/log_catch`，
由 `secure/master/error.lpc` 的 `error_handler()` 写入，不是
`log/debug.log`——这两套日志此前没有被本 lib 的记录明确区分过，见下）。

### Bug found and fixed

**`secure/imud/imud.lpc:144-146`（`handle_router_read()`）——检测到非
数组消息后没有 `return`，继续往下执行 `message[0]`，在真实驱动上
**每次启动、每次 I3 socket 建立连接都 100% 必现**一次被捕获的运行时
错误。**

- 症状：`work/log/log_catch`（`catch()`住的运行时错误，由
  `error_handler(mp, caught=1)` 写入——与 `log/debug.log` 是两个不同的
  日志文件，`log/debug.log` 完全不会记录这类被 `catch()` 吞掉的错误）
  在**每一次**原生驱动启动后都立刻多出一条：
  ```
  *Value being indexed is zero.
  Object: /secure/imud/imud at line 148
  'read_callback' at /secure/imud/socket#0 at line 94
  'CATCH' at /secure/imud/socket#0 at line 94
  'handle_router_read' at /secure/imud/imud at line 148
  ```
  对连接过程完全不可见——`mudlist` 照常返回真实数据、欢迎语正常、玩家
  侧没有任何异常——只有翻这个专门的运行时错误日志才能看到。用今天之前
  遗留在 `work/log/log_catch` 里的历史记录核实过：2026-08-24 那次首次
  转换测试的 4 次启动（22:22/22:23/22:24/22:34）**每一次都留了同一条
  错误**，说明这不是偶发，是从这个 lib 转换进本项目那天起就一直存在、
  每次启动必现的问题，只是此前的验证轮次没有检查过这个日志文件。
- 根因：`secure/imud/socket.lpc` 的 `release_callback()`（接受一个新
  出站连接后）故意调用 `catch(evaluate(read_func, this_object(), 0))`——
  用整数 `0` 作为 message 参数，通知上层"新连接建立了"（见该函数自带
  注释 "Deliver a 0 indicating a new connection"）。`imud.lpc` 的
  `handle_router_read(object socket, mixed *message)` 在第 144 行用
  `!arrayp(message)` 正确识别出了这种情况并 `debug_message()` 记录了
  一行 "Unknown message: 0"，但**忘了在这条分支里 `return`**，于是
  第 148 行 `if (message[0] != "mudlist")` 紧接着对整数 `0` 做下标
  访问，触发 "Value being indexed is zero" 运行时错误。因为
  `socket.lpc:94` 的 `read_callback()` 本身把整个调用包在
  `catch(evaluate(read_func, ...))` 里，这个错误被吞掉、不传播、不
  影响后续任何功能——`mudlist`/`update` 全部正常工作（NOTES.md 上一次
  记录的"干净启动"结论在功能层面依然成立）——但这是一个真实的、
  100% 可复现的、`missing return after a stringp()/arrayp() guard`
  类型的驱动 API 误用，完全符合 §10.7 scope 里"missing
  `objectp()`/`stringp()` 一类的守卫"这一类。
- 修复：在 `!arrayp(message)` 分支里补上 `return;`：
  ```lpc
  if (!arrayp(message)) {
    debug_message(sprintf("Unknown message: %O", message));
    return;
  }
  ```
  message 本来就不是数组时，后面所有依赖 `message[0..]` 下标访问的
  分发逻辑都没有意义，提前返回是唯一合理的行为，不改变任何真实 I3
  协议消息（`mudlist`/`startup-reply`/`error`/未知类型转发错误包）的
  处理路径。
- 验证：修复前，`rm` 干净两个日志文件后重新 boot 原生驱动，
  `work/log/log_catch` 立刻出现上述同一条错误（第 5 次独立复现，
  加上历史记录里的 4 次，共 5/5 次启动必现）。应用修复、`kill` 掉进程、
  重新 `boot` 一次全新驱动实例后：`work/log/log_catch`/`work/log/log`
  两个文件启动后仅剩时间戳头，**没有任何错误记录**；随后用真实 socket
  客户端跑了一遍连接 → 欢迎语/IMUD STAT 块 → `mudlist`（真实返回
  "166 matches out of 166 muds. 106 are UP."，能看到 FluffOS/LDMud/
  CoffeeMud/Dead Souls 等真实在线的 MUD）→ 未知命令 `foobar`（正确
  兜底 "What?"）→ `update /secure/commands/mudlist`（正确 "Done."）→
  `update`（无参数，正确 "update what?"）→ 运行约 50 秒的空闲观察期，
  两个错误日志文件全程保持空白，`log/debug.log` 无 FATAL。另外用
  `node scripts/wasm_client.js ~/src/fluffos/build-wasm/src libs/imud
  --send "" --send "mudlist" --send "quit"` 重新跑了一遍 WASM 构建，
  行为与此前记录一致（`socket_address`/`socket_write` 编译失败被
  `catch()` 优雅吸收，`mudlist` 返回空列表而不是崩溃），确认这次修复
  没有引入任何 WASM 侧回归。

### `debug.log` 里一条无害噪音，记录但不修

真实 I3 路由器在握手完成后，会在没有请求的情况下主动推送一条
`chanlist-reply` 消息（属于 channel 扩展协议，本 lib 的
`secure/imud/imud.lpc` 只 `inherit` 了 `daemon_data`/`reconnect`/
`mudlist` 三个模块，channel 模块本来就被上游仓库自己注释掉，见
「这个 lib 到底是什么」一节）。`handle_router_read()` 对着这条未知
类型的消息按设计正确地回了一个 `"error"`/`"unk-type"` 错误包给路由器，
但真实路由器又回了一句 `(<- *i4) not-imp: Unknown command sent to
router: error`——路由器自己不接受把 `"error"` 类型的包直接发给它本身
（只接受它转发给别的 mud 的场景）。这是"演示 lib 只启用了三个协议
模块、面对一个真实的、期望更完整协议栈的生产路由器"这一既定设计事实
自然产生的协议噪音，不改变任何行为，两次干净启动（含修复前后）都能
在 `log/debug.log` 里看到，判定为"design"，不修。

### 结论

本轮修复了一个真实的、每次启动必现的运行时守卫缺失 bug（`imud.lpc`
`handle_router_read()` 的 `return` 缺失），修复前对玩家侧完全无感知，
只在专门的运行时错误日志（`work/log/log`/`work/log/log_catch`，与
`log/debug.log` 是不同文件）里可见——这本身也印证了 AGENTS.md §10.7
"quit 的可见输出正常不代表服务端没有静默出错"这条方法论在这个只有两个
命令的极简 demo 上依然成立。除此之外，这个 lib 唯一有实质内容的功能
（`mudlist` 真实连公网 I3 网络）本轮再次原生实测确认工作正常，`update`
命令、未知命令兜底、~50 秒空闲期、WASM 构建全部无新发现。

## 管理员账号

不适用，见 README「管理员账号」小节——没有账号系统，无法播种。
