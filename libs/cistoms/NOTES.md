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
