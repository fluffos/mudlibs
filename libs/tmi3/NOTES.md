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

## 深度功能测试（§10.7，2026-11-14）

pristine + build-debug，归档端口 40392。`scripts/play_login.py` 注册/连线并验证入世界，驱动 stdout 与新增 `debug.log` 均 0 错误/警告。本轮无新编程缺陷。

## 全库活跃编译告警清零（2026-11-27，KB 04 §6.10）

- 扫描 `tmi3`（`40` 份可编译文件），移除 `/cmds/file/more.lpc:64` `next_line()` 中未用局部变量 `k`（保留原 LF 行尾与 `KEEP`），本馆除临时求值文件 `/tmp/tmp_eval_file.lpc` 外活跃编译告警清零。
- 验证：`lpc_audit_removed_locals.py HEAD` `0 to look at`；`lpc_format_changed.py --apply` `0` 重排；`scripts/lpc_warnings.py tmi3` 确认仅余 `/tmp/tmp_eval_file.lpc`；`lpcc_eval.py` `--head` 对照工作树正常加载 `PASS`；`scripts/lint.py` `--changed HEAD` 与 `--fast`（`197` 条规则）均零错误零告警；`play_boot.sh`+`play_stop.sh` 启动正常且 `ZERO_DRIVERS`。
