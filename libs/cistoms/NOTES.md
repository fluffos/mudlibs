# CISTOMS — 恢复笔记

## 来源

- SourceForge CVS 快照 `archives/cistoms-cvs.zip`（RCS `,v` → 检出 testsuite 树）
- Issue：GitHub `#14`（用户点名）
- MudOS testsuite 后裔；Casimir / Rahvin 巫师区与钓鱼小游戏

## Bring-up（2026-11-10）

1. CVS 检出 → `convert_lib.sh` → `work/`；port `40394`；global include `<global.h>`
2. 登录对象在 `exec` 之后改调 `user->start_login()`（原 `login_d` 在 `input_to` 前被 destruct）
3. `user.lpc`：补 `void setup();` / `start_login` 原型；`receive_message(string msgclass, …)`（`class` 保留字）
4. `move_object` 统一单参（MudOS 二参写法）
5. 起点 Void；`goto` 可达 Casimir 城堡工作间

## 验证

- Boot：`Accepting telnet` on `40394`
- 名 `cisbot` → Void；`look`；Casimir workroom；`quit`

## 深度功能测试

（见下方 2026-11-10 重测。）

## §6.10 未用局部（2026-11-10）

- Boot 普查：`/single/simul_efun.lpc` `resolve_path` 声明 `t1,t2,t3,t4`，仅 `t1` 参与 `sscanf`。
- 改为 `string t1;`。证明：`lpcc --batch` 启动 0 warning / 0 error。

## 深度功能测试（§10.7，2026-11-10）— 重测

手启：`build-debug`；端口 40394。

覆盖：名 `fluffos` → Void `look`/`who` → `goto /u/Casimir/castle/workroom/workroom`
→ `look` → `walk east` 花园口 / `walk west` 回工作室 → `quit` → 重连/`look`/`quit`。
（本库方向移动是 `walk <dir>`，裸 `east` 会「You cannot do that」。）

### §6.10 编译警告（同轮修）

驱动在首次加载相关文件时报告 4 条，已在源处清掉：

- `exits.lpc` `query_str_exit`：未用局部 `str_exit`
- `look.lpc` / `l.lpc`：未用局部 `junk`
- `goto.lpc`：`load_room` 定义写成 `int`，原型是 `object`（定义改回 `object`）
- `base.lpc`：`listids` 原型 `void`，定义是 `string`（原型改 `string`）

冷启动重测：stdout 无 compile warning、无 runtime Error。无其它新编程缺陷。

## §7.297 sefun `cat()` 未检查 `read_file`（2026-11-10）

`single/simul_efun.lpc`：`write(read_file(file))` 在档案缺失时把 0 交给 `write`，登录横幅等会中断。改为 `write(read_file(file) || "")`。缺失路径不再报 Bad argument。

## 深度功能测试（§10.7，2026-11-14）

pristine + build-debug，归档端口 40394。`scripts/play_login.py` 建角进入 `The Void` 并执行 `look`（纯骨架库），驱动 stdout 与新增 `debug.log` 均 0 错误/警告。本轮无新编程缺陷。

## `command/ed.lpc` 与 `command/rm.lpc` 错含 `<globals.h>` 修复（2026-11-27，KB 04 §6.138）

- 扫描 `cistoms`（`112` 份可编译文件），修复 `/command/ed.lpc:1` 与 `/command/rm.lpc:1` 的 `#include <globals.h>` 为本馆头文件 `#include <global.h>`（保留原 LF 行尾与 `KEEP`）。
- 验证：`lpc_format_changed.py --apply` `0` 重排；`lpcc_eval.py` `--head` 对照工作树确认 `/command/ed` 与 `/command/rm` 由 `0/2` 解锁为 `2/2`；`scripts/lint.py`（新增规则 #197 `worknpc-busy-msg-cistoms-global-h`）`--changed HEAD` 与 `--fast` 均零错误零告警；`play_boot.sh`+`play_stop.sh` 启动正常且 `ZERO_DRIVERS`。

## 全库活跃编译告警清零（2026-11-27，KB 04 §6.10）

- 扫描 `cistoms`（`114` 份可编译文件），清理全部 `4` 份活跃文件中的 `11` 处编译告警（保留原 LF 行尾与 `KEEP`），本馆除临时求值文件 `/tmp_eval_file.lpc` 外活跃编译告警清零：
  1. `/inherit/std/item/item.lpc`：移除与父类 `/inherit/base.lpc` 重复声明的全局变量 `string genericname;`（一次消除 `item.lpc` 及 `fish.lpc`/`purse.lpc` 等 `6` 处 `Redeclaration of global variable 'genericname'` 告警），并移除 `set_name()` 中未用局部 `daycode` 与 `randid`。
  2. `/command/get.lpc`：移除未用局部 `str_junk`。
  3. `/command/update.lpc`：移除未用局部 `updater`。
  4. `/single/daemons/login_d.lpc`：移除未用局部 `*passkey`。
- 验证：`lpc_audit_removed_locals.py HEAD` `0 to look at`；`lpc_format_changed.py --apply` `0` 重排；`scripts/lpc_warnings.py cistoms` 确认仅余 `/tmp_eval_file.lpc`；`lpcc_eval.py` `--head` 对照工作树 `4/4` 正常加载 `PASS`；`scripts/lint.py` `--changed HEAD` 与 `--fast`（`197` 条规则）均零错误零告警；`play_boot.sh`+`play_stop.sh` 启动正常且 `ZERO_DRIVERS`。

## `command/iwin.lpc` 裸 `include <globals.h>` 编译阻断修复（2026-11-27，KB 04 §6.139）

- 修复 `/command/iwin.lpc:8` 缺失 `#` 且写错头文件名的 `include <globals.h>` 为 `#include <global.h>`（保留原 LF 行尾与 `KEEP`）。
- 验证：`lpc_format_changed.py --apply` `0` 重排；`lpcc_eval.py` `--head` 对照工作树确认 `/command/iwin` 由 `FAIL` 解锁为 `PASS`；`scripts/lint.py`（新增规则 #198 `zzhj-return-types-cistoms-iwin`）`--changed HEAD` 与 `--fast` 均零错误零告警；`play_boot.sh`+`play_stop.sh` 启动正常且 `ZERO_DRIVERS`。
