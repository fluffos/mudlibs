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

未做完整 §10.7；登录/Void/城堡路径已过。

## §6.10 未用局部（2026-11-10）

- Boot 普查：`/single/simul_efun.lpc` `resolve_path` 声明 `t1,t2,t3,t4`，仅 `t1` 参与 `sscanf`。
- 改为 `string t1;`。证明：`lpcc --batch` 启动 0 warning / 0 error。
