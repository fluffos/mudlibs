# Tamedhon (`tamedhon`) — 移植笔记

- 来源：GitHub Issue #24（Codeberg `td-mudlib`，开源 GPLv3 部分；2024 年仍有 Aloy 提交记录）
- 编号：`194`，端口：`40399`，`hosting: vendored`，`wasm_status: playable`
- 编码：UTF-8（原仓库 3107 个文本文件为 UTF-8，仅 3 个 `doc/` 文档有 lossy 字节，未改源代码逻辑；21 个二进制跳过）。
- 语言/方言：德国 **LDMud 3.6+ / Silberland-MorgenGrauen 系**（`#'` 闭包 1131 处、`struct` 265 处、`set_driver_hook`、`e308` 等，且 `/d/gidhrog` 等闭源世界域未包含在开源包中）。

## FluffOS 移植方案（Strategy A，参照 `libs/morgengrauen`）

原 LDMud 核心档案保留为源码供研究（其中与运行时重合的 9 个部屋/公会文件备份为 `*_ldmud.lpc`）：

1. `/catalog/{auto.h,simul_efun.lpc,master.lpc,login.lpc,player.lpc,void.lpc}`
   - `login.lpc` 输出原版 `/etc/ansi/WELCOME.localhost` 256 色 ANSI 横幅（去除行尾兼容序列 `\e(B` 以免在非 ISO-2022 客户端显示多余 `B`），并在下方印上 `Preserved at https://mudlibs.fluffos.info` 标记。
   - 支持双语交互（德语/英语）：`gast`/`guest` 免密访客登录，或 2–16 位小写字母注册持久化存档（`/data/<c>/<name>.o`）；移动指令兼容 `n/norden/north`、`s/sueden/south`、`o/osten/east/rechts`、`w/westen/west/hinten`、`oben/u/up`、`unten/d/down`、`raus`，以及 `schau/unt/look`、`lies/read`、`rieche/smell`、`status/score`、`hilfe/help`、`ende/quit`。
2. FluffOS 原汁复刻房间与公会（保留 Tamedhon 原文描述、细节 `extras`、气味 `smells` 与出口连通）：
   - `/gilden/abenteurer.lpc`（Die Gilde der Abenteurer：壁炉/战利品细节、`lies liste` 显示 6 个公会法术、`rieche`、向西通往 Kreuzung）
   - `/room/kreuzung.lpc`（Eine Kreuzung im Untergrund von Tamedhon：`lies wegweiser`，连通 Lehrlingsbude、MKZ、Das Kittchen、Die Anderswelt 与 Abenteurergilde）
   - `/room/lehrlingsbude.lpc`（Die Lehrlingsbude von Tamedhon）
   - `/room/mkz.lpc`（Mud-Kontrollzentrum：控制台 `druecke 1`、`gott` 直达 `/players/gott/workroom`）
   - `/players/gott/workroom.lpc`（Der Arbeitsraum von Gott）
   - `/room/jail.lpc`（Das Kittchen：`sag` / `nicke` / `nein`，保留 `westen`/`raus` 与 `unten` 防卡死出口）
   - `/room/debug.lpc`（Debugraum von Tamedhon：`umlegen` 开关与 `hebel` 检查）
   - `/room/void.lpc`（Die Anderswelt：`welt` 指令传送回 `/gilden/abenteurer`，亦可通过 `oben` 返回 Kreuzung）
   - `/room/lagerraum.lpc`（Lagerraum）

## 校验与测试结果（2026-11-14）

- **格式化**：`tools/lpc-syntax/bin/format-corpus.mjs` 处理全部 14 个活跃 `.lpc` 文件（10 written, 4 unchanged, 0 errors）；3 类盲区（`:\s:\s*`、`case.*//`、`\ [nrt]`）清零；全库 `no_warnings` = 0。
- **NTFS 路径检查**：`python3 scripts/check_ntfs_paths.py -v libs/tamedhon`：`non_utf8=0 illegal=0 case_file_dups=0 case_dir_dups=0 file_vs_dir=0`（包含 German umlaut 邮件/存档目录 `mail/ä` 等合法 UTF-8 路径）。
- **`lpcc` 编译与 `lpc_warnings.py`**：14 个活跃 FluffOS 文件全部 `PASS`，0 warning / 0 error（其余 `/d/`、`/obj/`、`/p/`、`/secure/`、`/spellbooks/`、`/std/`、`/doc/`、`/room/death/`、`/room/netztot` 及 `*_ldmud.lpc` 为保留的 LDMud 源码）。
- **原生驱动实测（临时拷贝 `/home/sunyc/.cache/lpc-scratch/tamedhon-live`，端口 `40498`）**：注册 `testera` → 落点 Abenteurergilde → `lies liste` / `rieche` / `unt drachenkopf` → Kreuzung → `lies wegweiser` → Lehrlingsbude → MKZ → `druecke 1` → `gott` workroom → Kittchen → `sag hallo` → Debugraum → `umlegen` → Anderswelt → `welt` 回公会 → `score` / `quit` 持久化 → 冷重连密码验证通过；`log/debug.log`、`catch`、`runtime`、`compile` 均为空。
- **WASM 实测**：`node scripts/wasm_client.js /home/sunyc/src/fluffos/build-wasm/src libs/tamedhon` 注册 `testerw` → 浏览 `WELCOME.localhost` 横幅与 `mudlibs.fluffos.info` 戳记 → `lies liste` → Kreuzung → Lehrlingsbude → Kreuzung → `score` → `quit` 全流程通过。

## 单行 `#define` 字符串未闭合修复（2026-11-20，KB 04 §6.33）

- 修复 `/obj/tools/astralschwert.h:8` 中 `#define ESC "\x1b` 缺少闭合 `"`，补全闭合引号并保留原 LF 行尾（保留其余 LDMud 归档源码不变）。
- 验证：`lpc_format_changed.py --apply` 13/13 头文件零重排；`lpcc_eval.py` 验证通过（`wxddym` `/adm/daemons/skillsd1` 加载正常、`xkxc98sj`/`xkxz2` `F_ITEMMAKE` 由 `--head` 语法错误转为 `"/feature/itemmake.lpc"`、`kxkj`/`kxkj1`/`kxkjii2` `PANTS`、`fengyun434`/`fysjmb`/`xsfyssjb` `ansi4.h`、`wuhanzhan` `ansi1.h` 及 `silberland` `PMMASTER` 均通过）；`scripts/lint.py`（新增规则 #86 `unclosed-define-string`）`13/13` `HEAD` 正例与工作树/`silberland/work/sys/terminal.h` 反例单测通过，全库 `--all` 与 `--fast` 均 `0` 错误 `0` 告警；`13/13` 馆 `play_boot.sh`+`play_stop.sh`（端口 `47531..47543`）全部正常且 `ZERO_DRIVERS`。
