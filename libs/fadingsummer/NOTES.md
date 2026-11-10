# Lore of the Fading Summer — 恢复笔记

## 来源

- `archives/fadingsummer-0.2.tgz`（SourceForge fadingsummer 0.2，2001-07）
- Issue：GitHub `#17`（用户点名）
- Lontau 从 MudOS v22.2b11 自带的 Lil 起步的 GPLv2 alpha；计划取代 Estilore 的 TMI-2 基库，世界未完成

## Bring-up（2026-11-10）

1. 解包 → `.c`→`.lpc`；port `40395`；global include `<config.h>`
2. 档案未带 `globals.h` / `lpctypes.h` / `SHELL_D` / `BANISH_D` / banner：博物馆补最小桩与 Lil 残留符号（`BASE`/`OVERRIDES_FILE`/`SIMUL_DIR`）
3. `CLONE_DIR`：`/cloneable` → 实际目录 `/clonable`
4. `logon_d`：空名分支补大括号；`SHELL_D->query(name, ({"passkey"}))` 参数；`previous_object()` 与路径宏改用 `base_name()` 比较
5. `newuser_d`：`crypt(user_entry, 0)`；补 `NEWUSER_PASS_NOMATCH`；问候语去掉不存在的 `mud_name()`
6. `daemons.h` / `objects.h`：路径改为单字面量，避免 `"/system"+"/daemons"+("/x"->fn())` 的 `+`/`->` 优先级陷阱
7. `login`：`new()` → `clone_object()`；`(void) MACRO->…` 改为 `call_other`
8. `user`：alpha 未写 `save`/`startup`/`look`/`quit`；跳过未完成的 `parse_init`/`query_ed_mode`
9. `time.lpc`：形参与函数体变量名不一致（`specified_time`）

## 验证

- Boot：`Accepting telnet` on `40395`
- 注册 `testuser` / passkey → void；`look`；`quit`；存档 `data/user/t/testuser.o`

## 深度功能测试

（见下方 2026-11-10 重测。可玩范围仍仅 void + 注册/存档。）

## 深度功能测试（§10.7，2026-11-10）— 重测

手启：`build-debug`；端口 40395。

覆盖：注册 `fluffos` → `y` → passkey `Mud@2026`×2 → email → real name → void
`look`/`quit` → 重连再进/`look`/`quit`。

本库仍是未完成 Lil alpha：无区域、无 `inventory`/`score`/`who`（回 What?）。
驱动 stdout：无 compile warning、无 runtime Error。无新编程缺陷。
