# TMI-3 — 恢复笔记

## 来源

- Archive: `tmi-3-0.1a.tar.gz`（`fluffos/mudlib-archives` release `v1.0.0`；本地 `archives/tmi3-a01a.tar.gz`）
- 上游历史：SourceForge `tmi-3` / LPCommunity；MudOS 时代 TMI-2 后继骨架
- Issue 线索：GitHub `#16`（MudOS mudlibs 批量建议）

## Bring-up（2026-11-10）

1. 解包 `lib/` → `work/`；`config.fluffos`：port `40392`，mudlib → `work/`，global include `/include/global.h`，`default error message` → `What?`
2. 全树 `.c` → `.lpc`；同步改：
   - `include/global.h`：`OBJECT`/`CLEAN_UP`/`OB_E`/`ROOM` 路径后缀；无 `__SENSIBLE_MODIFIERS__` 时 `staticf`/`staticv` → `nosave`（FluffOS 保留字）
   - `std/user.lpc`：`commandHook` 里 `file_exists(...+".c")` → `.lpc`
   - `adm/obj/master.lpc`：`epilog` 预载 `file_size(file+".c")` → `.lpc`；`string array` → `string *`
3. `adm/obj/master.lpc`：补 FluffOS `PACKAGE_UIDS` 所需 `get_root_uid` / `get_bb_uid` / `creator_file` / `author_file` / `domain_file`（Alpha 原档无）
4. `log/`、`data/users/{a..z}/`、`data/connection/` 建齐（`debug.log` / 存档字母桶）

## 验证

- Boot：`Ready for connections` on `40392`
- 新号注册 + `look` → void 房；`quit`；重登成功
- `score` 等未实现命令走 `What?`（alpha 骨架，预期）

## 深度功能测试

（见下方 2026-11-10 重测。内容仍是 void 骨架。）

## 深度功能测试（§10.7，2026-11-10）— 重测

手启：`build-debug`；端口 40392。

覆盖：注册 `fluffos` → `y` → `Mud@2026`×2 → void
`look`/`who` → `void2` / `void` 回 void → `quit` → 重连再进/`look`/`quit`。
`inventory`/`score` 回 `What?`（alpha 未实现，预期）。

驱动 stdout：无 LPC compile warning、无 runtime Error（仅有 config 里两条 obsolete line 提示与旧 crypt 口令升级提示）。无新编程缺陷。

## §7.297 sefun `cat()` 未检查 `read_file`（2026-11-10）

`adm/simul_efun/cat.lpc`：`write(read_file(file))` 在档案缺失时把 0 交给 `write`，登录横幅等会中断。改为 `write(read_file(file) || "")`。缺失路径不再报 Bad argument。
