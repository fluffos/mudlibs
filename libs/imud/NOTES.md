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

## 管理员账号

不适用，见 README「管理员账号」小节——没有账号系统，无法播种。
