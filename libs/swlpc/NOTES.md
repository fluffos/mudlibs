# Shattered World Core Mudlib (`swlpc`) — 移植笔记

- 来源：GitHub Issue #29（`mlib-0.9.1.tar.bz2`，2001-09 GPLv2 开源核心库）
- 编号：`195`，端口：`40400`，`hosting: vendored`，`wasm_status: playable`
- 编码：全部 427 个文本文件均为 UTF-8（无转码损耗，39 个二进制跳过）；原压缩包已全部使用 `.lpc` 扩展名（341 个 `.lpc` 文件）。
- 方言：澳大利亚 **SWLPC (`swlpc-1.9.1`)** 方言（非标准 MudOS/FluffOS：`array` 关键字、`[ ... ]` 表示数组而非 mapping、`(int|string)` 联合类型声明、`const` 变量、`contents()`/`index()`、`::efun()` 语法、`init_parser()`/`rename_object()`、`P/p` 等由 `RO/Root/RootDir.lpc` 构造的虚拟核心对象，且压缩包为“Core Mudlib”，不包含 `room/city/pub2`、`room/bh1`、`room/city/endo`、`players/` 等世界地图）。

## FluffOS 移植方案（Strategy A）

保留原始 SWLPC 核心树供研究（替换的 4 个活跃房间原件重命名为 `*_swlpc.lpc`）：

1. `/catalog/{auto.h,simul_efun.lpc,master.lpc,login.lpc,player.lpc}`
   - `/catalog/login.lpc` 原样输出 `/RO/banner` 艺术 ASCII 标题，并在下方印上 `Welcome to the Shattered World (version swlpc-sep01)!` 与 `Preserved at https://mudlibs.fluffos.info`。
   - 支持 `'guest'` 免密访客登录或 2–16 位小写字母持久角色注册（`/data/<c>/<name>.o`）。
   - 支持 `look`/`look at clock`/`read sign`/`emote`/`:`/`score`/`inventory`/`help`/`quit` 与标准六向移动。
   - `/catalog/auto.h` 避免重复定义 FluffOS 预定义宏 `MUD_NAME`（由配置 `name` 自动注入）。
2. FluffOS 原文复刻连通房间：
   - `/room/city/inn.lpc`（Common Sleeping Quarters：原版壁炉/地铺细节、时钟塔 `look at clock`、公告牌 `read sign`、`emote`/`:`）
   - `/room/wiz/noisy_room.lpc`（Noisy room，east/up 连通）
   - `/room/storage.lpc`（Don't be here! 通用储物室，down 连通）
   - `/RO/void.lpc`（The Void，west 连通）

## 校验与测试结果（2026-11-14）

- **格式化**：`tools/lpc-syntax/bin/format-corpus.mjs` 处理全部 8 个活跃 `.lpc` 文件（4 written, 4 unchanged, 0 errors）；3 类盲区与 `no_warnings` 均清零。
- **NTFS 路径检查**：`python3 scripts/check_ntfs_paths.py -v libs/swlpc`：`non_utf8=0 illegal=0 case_file_dups=0 case_dir_dups=0 file_vs_dir=0`。
- **`lpcc` 编译**：8 个活跃 FluffOS 文件全部 `PASS`，0 warning / 0 error；提交后 `scripts/lpc_warnings.py swlpc`（跳过保留的 SWLPC 原件目录）零诊断。
- **原生驱动实测（临时拷贝 `/home/sunyc/.cache/lpc-scratch/swlpc-live`，端口 `40497`）**：注册 `testera` → Common Sleeping Quarters → `read sign` / `look at clock` / `:waves warmly.` → east (`Noisy room`) → west → down (`Don't be here!`) → up → west (`The Void`) → east → `score` / `quit` 存档 → 冷重连密码验证通过；`log/debug.log`、`catch`、`runtime`、`compile` 均为空。
- **WASM 实测**：`node scripts/wasm_client.js /home/sunyc/src/fluffos/build-wasm/src libs/swlpc` 注册 `testerw` → 展示 `RO/banner` 与 `mudlibs.fluffos.info` 戳记 → `read sign` → east → west → `score` → `quit` 全流程通过。
