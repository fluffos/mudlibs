# TMI-3 — 恢复笔记

## 来源

- Archive: `tmi-3-0.1a.tar.gz`（`fluffos/mudlib-archives` release `v1.0.0`）
- 上游历史：SourceForge `tmi-3` / LPCommunity；MudOS 时代 TMI-2 后继骨架
- Issue 线索：GitHub `#16`（MudOS mudlibs 批量建议）

## Bring-up（2026-11-10）

1. 解包后 `config.fluffos`：port `40392`，`mudlib directory` → `./`，global include `include/mudlib.h`，`default error message` 设为 `What?`
2. 全树 `.c` → `.lpc`；`include/config.h` 的 `SAVE_EXTENSION` 由 `".c"` 改为 `".o"`（§6.11）
3. `bin/mudlib` 里两处硬编码 `/tmi/` 路径改为相对 `./`（driver / mudlib 根）
4. `cmds/std/look.lpc`：去掉函数名旁的 `nomask`（FluffOS 不允许）
5. `adm/daemons/command.lpc`：`valid_cmd_path` 增加 `/cmds/std/`、`/cmds/file/`、`/cmds/object/`（原仅信任 `/cmds/admin/`，玩家 `look`/`quit` 被拒）
6. `adm/daemons/virtual.lpc`：`compile_object` 对缺失文件先 `file_size` 再 `load_object`，避免 virtual fallback 对不存在路径递归（§7.327）
7. `std/user/save.lpc`：`restore`/`save` 增加 `catch`，坏/空存档不炸登录
8. `log/`、`data/users/{a..z}/`、`data/connection/` 建齐；`adm/daemons/log.lpc` 的 `assure_file` 用 `mkdir` 代替不存在的 `make_dir` efun

## 验证

- Boot：`Ready for connections` on `40392`
- 新号注册 + `look` → void 房；`quit`；重登成功
- `score` 等未实现命令走 `What?`（alpha 骨架，预期）

## 深度功能测试

未做完整 §10.7（内容仅 void 骨架）；登录/重登/基础 look 已过。
