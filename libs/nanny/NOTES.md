# NannyMUD（Lysator 1996-03-29 快照）— 恢复笔记

## 来源

- Lysator FTP 历史归档快照 `https://ftp.lysator.liu.se/pub/lpmud/nannymud/nannylib.tgz`（1996-03-29，GitHub `#22`）
- 原运行于 Lysator 自研 NannyMOS（LPMud / Amylaar compat 分支）驱动；包含村庄中心（`room/church`、`room/vill_green`、`room/adv_guild`、`room/shop`）、Middle-earth / Malkuth 等世界区域（`room/` 325 个文件）、完整 `/std/` 与 `/obj/` 框架、Quest 系统以及 Profezzorn 的 Brain Shell。

## Bring-up 与 FluffOS 移植（2026-11-14）

1. 目录与配置：`convert_lib.sh` 规范化 `.lpc` 扩展名；分配编号 `193`，端口 `40398`；`config.fluffos` 开启 `lazy resets : 1`、`inherit chain size : 60` 与全局头文件 `<fluffos_global.h>`；补齐运行期目录 `log/`、`data/binaries/`、`www/quests/`。
2. 兼容层（`include/fluffos_global.h` 与 `obj/simul_efun.lpc`）：
   - 移除导致 `FAIL(CAPVERB+...)` 宏递归展开的 `#define query_verb() efun::query_verb()`。
   - 在 `obj/simul_efun.lpc` 覆盖 `file_name(ob)` 剥离 FluffOS 前导 `/`，并在 `obj/master.lpc` `get_wiz_name()` 中兼容可选前导 `/`，使整库原有的 `obj/player#*`、`obj/shut`、`obj/daemon/` 及 `players/profezzorn/brain.h` 路径判别一次恢复正常；同时为 `load_object()` 的 `call_other(s, "?")` 加上 `catch()` 保护。
   - 补齐 NannyMOS 兼容接口：`_disconnect()`（转调 `efun::remove_interactive`）、`_object_cpu()`、`_object_memory()`（`memory_info`）、`_set_prompt()`、`_driver_stat()`；为非 socket 构建（WASM）在 `#ifndef __PACKAGE_SOCKETS__` 下提供安全的 `socket_*` 失败桩（返回 `-1` / `0`）。
3. 语法、警告与原始 Bug 修复：
   - 修复保留字变量与负常数下标：全库 `58` 处 `[-n]` 改为 `[<n]`；`obj/player.lpc` 与 `std/rfc/parser.lpc` 的 `in` 重命名并补全 `void create()` / `write_prompt()` / `clear_cached_quest_points()`；`secure/login.lpc:246` `cap_name` 修正为 `capitalize(name)`。
   - 消除所有编译警告与类型错误：移动 `17` 处文件级 `int inorout = N;` 进函数内部；修复 `obj/smartmonster.lpc` 的 `DEBUG_LOG`/`SAY_CONFUSED` 宏、注释嵌套、重复继承成员及 `void _signal_gotten` 误写 `return call_out(...)`；修复 `std/basic_monster.lpc` 的 `clean_up` 菱形歧义；修复 `obj/soft_drink.lpc:113` 多余分号、`obj/daemon/lockd.lpc:135` `ret +=`、`obj/daemon/timed.lpc:486` 字符串拼接、`std/tools/converter.lpc` 严格返回类型及 `players/profezzorn/local.h` 关闭 `TRACE` 宏。
4. `create()` 入口与运行期防护：
   - 在 `std/basic.lpc`、`room/room.lpc`、`obj/property.lpc`、`obj/monster.lpc`、`room/std.h` 以及 `65` 个独立对象（含 `obj/wiztool.lpc`、`obj/daemon/{dnsd,identd,entryd,autoaliasd}.lpc` 等）补全 `void create() { this_object()->reset(0); }`。
   - 修复实机暴露的运行期异常：`obj/wiztool.lpc` 空 `this_player()` 判空；`obj/printer.lpc` 缺少 `/etc/newssources` 时防空爆炸；`obj/daemon/entryd.lpc` 在缺少 `/etc/LOGO2` 时返回 `0` 回退至 `etc/LOGO`；`obj/daemon/autoaliasd.lpc` 与 `obj/player.lpc` `load_auto_obj()` 跳过空 `"^!"` 项避免字符串越界；`obj/living_functions.lpc` `real_move_player()` 在 `load_object(dest)` 为 `0` 时拦阻（例如通往缺失向导目录 `/players/ingis/village/lane` 的南向出口）；`obj/daemon/{dnsd,identd}.lpc` 在无法创建 socket 时保留 `sd = -1` 而非自毁；`obj/player.lpc` `help()` 在归档缺失 `/doc/` 时给出明确提示而非打印 `0`。
5. 登录横幅：在 `etc/LOGO` 原卷轴框画内保留全部原文本并补入 `Hosted at: mudlibs.fluffos.info`，同时将 `Driver: $$$$$$$$$$$$$$$$` 槽位对齐 16 字符宽的 `version()`（`NannyMUD/FluffOS`）。

## 深度功能测试与验证（2026-11-14）

- **排除的不可编译/未完成残留文件（`--skip`，共 `40` 个）**：
  - 未配置/依赖外部 TMI-2 宏的旧 socket 守护进程 `/obj/daemon/sockets/{cmwhod,finger,inetd,mail_serv,mailer_d,ms,name_server,news,news.dev,news_serv,ts}.lpc`（`11` 个）；
  - 模板文件（需先 `#define NAME`/`DEST`/`LINEMEMBERS` 等）`/players/panic/{castle,def_castle}.lpc`、`/room/{def_castle,def_workroom}.lpc`、`/obj/line/line.lpc`、`/std/rfc/def_castle.lpc`；
  - 依赖归档未附带向导目录的文件 `/local/module.lpc`（缺 `slater`）、`/obj/newspaper.lpc`（缺 `chrystoval`）、`/room/boxroom.lpc` 与 `/room/flame_room.lpc`（缺 `padrone`）、`/room/project_room.lpc`（缺 `wing`）、`/secure/truth.lpc`（缺 `gwendolyn`）、`/examples/old/{room11,room12}.lpc`（缺 `anna`）；
  - 明确限制仅限 `alt_name` 克隆而自毁的 `/local/brainloader.lpc`，明确位于 `not_working_yet/` 的 `/room/maze1/not_working_yet/maze_room.lpc`，以及未完成的 `/std/rfc/` 实验草稿（`box` 菱形继承、`composite_room`、`monster`、`good_monster`、`zellski_room*`、`demo/test*`，共 `14` 个）。
- **编译与警告**：全库 `.lpc` 经 formatter 规范化（`583` 个文件零 error、盲区扫描全清）后，对其余全部 `544/544` 个有效文件执行 `lpcc --batch` 与 `scripts/lpc_warnings.py` 扫描，全部编译并通过 `reset(0)` 初始化，`0` errors、`0` warnings、`0` `#pragma no_warnings`；将原归档中不符合 Windows/NTFS 规范的路径 `players/milamber/boardhelp/?`（改名为 `question` 并同步 `players/milamber/board.lpc`）及与文件冲突的目录 `etc/News`（改名为 `etc/NewsDir` 并同步 `obj/adstand.lpc`）修正后，`check_ntfs_paths.py` 全部通过。
- **原生启动与实机测试**：`build/src/driver` 正常启动，登录横幅完整对齐显示 `Driver: NannyMUD/FluffOS` 与 `Hosted at: mudlibs.fluffos.info`。先后测试 `guest` 与新建角色 `testera` 注册，在教堂（`room/church`）、教堂礼拜堂（`east`）、绿地（`room/vill_green`）、村道（`vill_track` -> `vill_road1` -> `vill_road2`）、冒险者公会（`room/adv_guild`，`list` 显示任务列表与布告板）及商店（`room/shop`）间往返移动，验证 Harry NPC 主动打招呼与跟随移动、`score`/`who` 输出以及缺失南向出口（`/players/ingis/village/lane`）安全提示不崩溃；`log/debug.log` 全程无未捕获错误。
- **WASM 验证（`scripts/wasm_client.js`）**：`build-wasm` 正常启动，登录横幅显示 `mudlibs.fluffos.info`，完成 `testerw` 新角色注册、`look`/`who`/`score` 与村镇移动（Harry 正常交互）及安全退出，无 WASM 运行期错误。

## 缺文件两步 `read_file()` 保护修复（2026-11-15，KB 06 §7.387）

- 修复 `obj/daemon/rlogind.lpc`（`query_rlogin()`）：归档未附带 `/etc/rlogins` 时 `read_file("/etc/rlogins")` 返回 `0` 并在 `explode(rl, "\n")` 抛出 `*Bad argument 1 to explode()`；增加 `if (!stringp(rl)) return 0;`。
- 验证：`lpcc_eval.py` 修前 `--head`（`*Bad argument 1 to explode`）→ 修后（`ZZ_NANNY=0 res=0` `PASS`）。
