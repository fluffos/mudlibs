# UNItopia (`unitopia`) — 移植笔记

- 来源：GitHub Issue #26（`http://www.unitopia.de/pub/UNItopia/mudlib.tar.gz` 2016 年归档公开基础 Mudlib，`2.3M`，含 `516` 个 `.c`、`126` 个 `.h`，无闭源校园 `/d/Campus` / `/d/Vaniorh` 域）。
- 编号：`197`，端口：`40402`，`hosting: vendored`，`wasm_status: playable`
- 授权说明：遵照根目录 `COPYRIGHT` 要求，所有改写适配的 UNItopia 房间文件头部均保留 `This file was originally part of UNItopia MUDlib.` 及原作者名单。
- 编码与符号链接处理：
  - 原包内 `map/stranden.c`、`obj/hlptool2.c`、`static/skill/magie/*.s`、`doc/hilfe/*` 等含 `130` 处符号链接（全部指向有效目标）；转码前以 `cp -aL` 解引用为常规文件，杜绝 NTFS/Git 符号链接问题。
  - `convert_lib.sh` 转换：`already_utf8=1352, converted=2, lossy=0, skipped_binary=1`；重命名 `516` 个 `.lpc` 文件，修正 `96` 处 `.c"` 引用，替换 `24` 处本地尖括号 `#include`，并在 `197` 个文件中完成 `static` → `nosave`。
- 语言/方言：德国 **LDMud**（`#ifdef UNItopia` / `HomeMUD` 双分支、特殊语法 `([:2])`、`'*'::create()`、`#'` 闭包等）。

## FluffOS 移植方案（Strategy A，参照 `libs/tamedhon`）

原 LDMud 核心源码完整保留供研究（被运行时覆盖的 `14` 个房间另存为 `*_ldmud.lpc`）：

1. `/catalog/{auto.h,simul_efun.lpc,master.lpc,login.lpc,player.lpc}`
   - `login.lpc` 读取原版 `/static/adm/WELCOME`（跳过开头 `HTTP/1.0 302` 与清屏控制行，保留 `Willkommen in UNItopia!` 原始欢迎辞），并附加 `Preserved at https://mudlibs.fluffos.info` 戳记；支持 `gast`/`guest` 免密访客登录及 `2-16` 位小写字母持久化角色注册（`/data/<c>/<name>.o`）。
   - `player.lpc` 支持德英双语命令：`norden/n`、`sueden/s`、`osten/o/e`、`westen/w`、`hoch/u`、`runter/d`、`forum`、`nische`、`raus`、`schau/unt/look`、`lies/read`、`rieche/smell`、`lausche/listen`、`fuehle/feel`、`status/score`、`inventar/i`、`hilfe/help`、`ende/quit`。
2. FluffOS 原汁复刻房间（按源码 `HomeMUD` / `#else` 分支自然连通 Tadmor 核心区）：
   - `/room/church.lpc`（Kathedrale von Tadmor：Gedenktafel/Stein、Kirchenuhr、Schild、Gruft、Turmfenster）
   - `/room/kirche/unten.lpc`（Im Kirchturm：北塔底层）
   - `/room/rathaus/treppe.lpc`（Rathaustreppe：`lies tafel` 禁乞告示牌）
   - `/room/rathaus/foyer.lpc`（Das Rathausfoyer：`lies wegweiser` 路牌，连通东西南北四翼）
   - `/room/rathaus/spielerrat/gang1.lpc`（Gang der Spielerratsraeume）
   - `/room/rathaus/gilden1.lpc` → `gilden5.lpc`（Gang der Gilden 公会展示走廊 1–5）
   - `/room/rathaus/reinkarnation.lpc`（Halle der Reinkarnation：`lies platte` / `schriftzeichen`）
   - `/room/rathaus/forum.lpc`（Das Forum：众神议事穹顶大厅）与 `/room/rathaus/nische.lpc`（Fensternische：眺望修道院窗龛）
   - `/room/void.lpc`（Das Nirwana：`runter` 返回大教堂）

## 校验与测试结果（2026-11-14）

- **格式化**：`format-corpus.mjs` 处理全部 `19` 个活跃文件（13 written, 6 unchanged, 0 errors）；3 类盲区（`:\s:\s*`、`case.*//`、`\ [nrt]`）清零；全库 `no_warnings` = 0。
- **NTFS 路径检查**：`python3 scripts/check_ntfs_paths.py -v libs/unitopia`：`non_utf8=0 illegal=0 case_file_dups=0 case_dir_dups=0 file_vs_dir=0`。
- **`lpcc` 编译与 `lpc_warnings.py`**：18 个活跃 FluffOS `.lpc` 文件全部 `PASS`，0 warning / 0 error。
- **原生驱动实测（临时拷贝 `/home/sunyc/.cache/lpc-scratch/unitopia-live`，端口 `40495`）**：
  - `gast` 访客登录 → 阅读告示牌 → 进入北塔返回 → `status` / `ende`。
  - 注册 `testera` → 走遍 Rathaustreppe（`lies tafel`）→ Foyer（`lies wegweiser`）→ Spielerratsraeume → Gilden 1–5 → Reinkarnation（`lies platte`）→ Forum → Nische → `status` / `ende` → 冷重连密码验证通过；日志零报错。
- **WASM 实测**：`node scripts/wasm_client.js /home/sunyc/src/fluffos/build-wasm/src libs/unitopia` 注册 `testerw` 并浏览 WELCOME 与大厅走廊、退出通过。
