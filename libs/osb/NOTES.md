# One Step Beyond (`osb`) — 移植笔记

- 来源：GitHub Issue #18（`osb-lib-030218.tar.gz`，2003-02-18 经典 LDMud / Nightfall 衍生公开快照）
- 编号：`196`，端口：`40401`，`hosting: vendored`，`wasm_status: playable`
- 编码：ISO-8859-1 → UTF-8 转换完成（`already_utf8=4903, converted=44, lossy=0, skipped_binary=22`；共 2417 个 `.lpc` 文件，修正 266 处 `.c"` 引用，移除 macOS `._`/`.DS_Store`）。
- 语言/方言：德国/国际 **LDMud (`#'` 闭包 / `Set()` 属性架构)**，与 `libs/aoh` (`976`) 为同系父子分支（`osb` 为 1997–2003 历史母本，含完整的 `/d/login/entrance`“困在热狗里”新手起点及 `/etc/WELCOME` 城堡字符画）。

## FluffOS 移植方案（Strategy A，参照 `libs/aoh` / `libs/tamedhon`）

原 LDMud 核心树完整保留供研究（被运行时覆盖的 12 个房间备份为 `*_ldmud.lpc`）：

1. `/catalog/{auto.h,simul_efun.lpc,master.lpc,login.lpc,player.lpc,void.lpc}`
   - `login.lpc` 读取并原样显示 `/etc/WELCOME` 城堡欢迎横幅，并附加 `Preserved at https://mudlibs.fluffos.info` 戳记；支持 2–16 位小写字母角色注册与 `/data/<c>/<name>.o` 持久化存档。
   - `player.lpc` 支持 `look/l`、`smell`、`listen`、`read`、`score/sc`、`inventory/i`、`quit` 及移动指令（含起始房间 `normal`/`newbie`/`instant`/`out`）。
2. FluffOS 原汁复刻房间（均取自 OSB 2003 原文描述、细节 `extras`、气味、声音与阅读文本）：
   - `/d/login/entrance.lpc`（*Entering One Step Beyond*：热狗状褐墙大厅，`instant`/`normal`/`newbie` 登岸至 `quay1_2`）
   - `/d/silvere/rooms/harbour/quay1_2.lpc`（*The docks*：渔网与海鸥，向西 `quay1_3`、向东 `quay1_1`）
   - `/d/silvere/rooms/harbour/quay1_3.lpc`（*The quay at Silvere*）与 `/d/silvere/rooms/harbour/ntower_enter.lpc`（*Before a high tower*，北部防御塔入口）
   - `/d/silvere/rooms/harbour/quay1_1.lpc` 与 `/d/silvere/rooms/harbour/shipyard.lpc`（*The shipyard of Silvere*，造船厂木屑焦油气味与船匠敲打声）
   - `/d/silvere/rooms/harbour/street3.lpc` → `street2.lpc` → `street1.lpc` → `entrance.lpc`（*City Gate*）
   - `/d/silvere/rooms/harbour/harbour_inn.lpc`（*The Seaman's Rest*：`read menu`、`read barrels`、`listen song` 唱航海号子）
   - `/d/silvere/rooms/harbour/harbourmaster.lpc`（*The Office of the Harbourmaster*：`read map`、`read plaque`）

## 校验与测试结果（2026-11-14）

- **格式化**：`format-corpus.mjs` 处理全部 18 个活跃文件（12 written, 6 unchanged, 0 errors）；3 类盲区清零；全库 `no_warnings` = 0。
- **NTFS 路径检查**：`python3 scripts/check_ntfs_paths.py -v libs/osb`：`non_utf8=0 illegal=0 case_file_dups=0 case_dir_dups=0 file_vs_dir=0`。
- **`lpcc` 编译与 `lpc_warnings.py`**：17 个活跃 FluffOS `.lpc` 文件全部 `PASS`，0 warning / 0 error。
- **原生驱动实测（临时拷贝 `/home/sunyc/.cache/lpc-scratch/osb-live`，端口 `40496`）**：注册 `testera` → 浏览 `/etc/WELCOME` 与 `mudlibs.fluffos.info` → `/d/login/entrance` `smell` → `instant` → 走遍北区码头、防御塔、造船厂、街道、城门、The Seaman's Rest（`listen song`、`read menu`）、Harbourmaster 办公室（`read map`） → `score` / `quit` → 冷重连密码验证通过；日志零报错。
- **WASM 实测**：`node scripts/wasm_client.js /home/sunyc/src/fluffos/build-wasm/src libs/osb` 注册 `testerw` 并完整游览、退出通过。
