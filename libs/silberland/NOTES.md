# SilberLand (silberland) — 移植笔记

- 来源：`https://codeberg.org/lycis/silberland-mudlib`（commit `3a80c370`），奥地利/德语 MorgenGrauen 系 LDMud/Amylaar mudlib。
- 编号：**198**，端口：**40403**。

## 1. 源码清理与编码转换

- 上游仓库原始工作树约 `688 MB`，其中运行日志（`*.log`）、醉酒公会统计转储（`gilden/zechpreller/statistics/`）、旧邮件/RCS `,v`/压缩包（`.rar`/`.zip`/`.tgz`）占约 `530+ MB`。导入时剔除上述非源码运行产物与备份目录（`bak/`、`RCS/`），完整保留 `27,063` 个 `.c`→`.lpc` 源码文件、`sys/`、`std/`、`secure/`、`gilden/`、`d/`、`doc/`、`etc/` 等世界树。
- 以 `ISO-8859-1 -> UTF-8` 批量转码（`29,676` 个已是 UTF-8，`5,220` 个由 Latin-1 转为 UTF-8，`0` 有损，`0` `#pragma no_warnings`）。
- 文件名经 `scripts/check_ntfs_paths.py -v libs/silberland` 校验：`non_utf8=0`、`illegal=0`、`case_file_dups=0`、`case_dir_dups=0`、`file_vs_dir=0`。

## 2. FluffOS Strategy A 适配

- 原生 LDMud `master`、多文件 `simul_efun` 及各原始房间文本保留为 `/gilden/abenteurer_ldmud.lpc`、`/room/{treff,void}_ldmud.lpc` 与 `/d/ebene/Midas/room/*_ldmud.lpc` 作为档案源码不参与运行时加载。
- 新增 `catalog/` 覆盖层：`auto.h`、`simul_efun.lpc`、`master.lpc`、`login.lpc`、`player.lpc`、`room.lpc`；登录界面原样输出 `/etc/WELCOME` 中的 SilberLand ASCII 徽标与规则公告，并标注 `Preserved at https://mudlibs.fluffos.info`。
- 登录支持游客（`gast` / `guest`）及 2-16 位小写字母角色注册持久化（`/data/<letter>/<name>.o`），进入 `/gilden/abenteurer`（Die beruehmte Abenteurergilde），可上行 `/room/treff` 或向西漫游 Midas 城中心（侧巷、`Hauptstrasse`、礼拜堂、`Zur roten Nase` 酒馆及餐厅、西城门、百货店、邮局、教堂东段与市政厅方向南侧小巷），同时支持德语与英语移动/查看/阅读/嗅听动词。
- 24 个新建/修改文件已通过 `format-corpus.mjs` 格式化并完成三项盲区检查（0 命中）。

## 深度功能测试（§10.7, 2026-11-14）

- `lpcc libs/silberland/config.fluffos --batch`：全部 23 个活跃对象（5 个 `catalog` 对象 + 18 个房间）零警告一次通过；提交后使用 `scripts/lpc_warnings.py silberland` 限定覆盖该 23 个活跃 `.lpc` 文件校验零诊断。
- 原生端测试（临时副本端口 `40494`）：`gast` 登录检验 `/etc/WELCOME` 与 `mudlibs.fluffos.info` 标记，`status`/`help` 并走通全部 17 个可通行房间及闭环折返；注册新角色 `testera`（`/data/t/testera.o`）、冷重启驱动后成功复登并 `quit` 存档；`log/{debug.log,catch,runtime,compile}` 均为零错误。
- WASM 端测试（`scripts/wasm_client.js`）：`testerw` 注册并遍历 Midas 城房间与阅读物品、存档退出全程无异常。已通过 `scripts/gen_keep_dirs.py --merge silberland` 合并运行空目录清单。

## 单行 `#define` 字符串未闭合修复（2026-11-20，KB 04 §6.33）

- 修复 `/gilden/piratenmeute/pm.h:31,33` 中 `DO_LOG_EINAUS(x)` 遗漏 `"yondala/pm_io.log"` 起始引号及 `DO_LOG_PUB_TRY(x)` 末尾 `"\n"` 遗漏起始引号，补全两处引号并保留原 CRLF 行尾（核实 `sys/terminal.h` 含字面 `\r` 的宏实已闭合）。
- 验证：`lpc_format_changed.py --apply` 13/13 头文件零重排；`lpcc_eval.py` 验证通过（`wxddym` `/adm/daemons/skillsd1` 加载正常、`xkxc98sj`/`xkxz2` `F_ITEMMAKE` 由 `--head` 语法错误转为 `"/feature/itemmake.lpc"`、`kxkj`/`kxkj1`/`kxkjii2` `PANTS`、`fengyun434`/`fysjmb`/`xsfyssjb` `ansi4.h`、`wuhanzhan` `ansi1.h` 及 `silberland` `PMMASTER` 均通过）；`scripts/lint.py`（新增规则 #86 `unclosed-define-string`）`13/13` `HEAD` 正例与工作树/`silberland/work/sys/terminal.h` 反例单测通过，全库 `--all` 与 `--fast` 均 `0` 错误 `0` 告警；`13/13` 馆 `play_boot.sh`+`play_stop.sh`（端口 `47531..47543`）全部正常且 `ZERO_DRIVERS`。
