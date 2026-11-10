# Middle of Nowhere — 恢复笔记

## 来源

- `archives/mofn-cvs.zip`（SourceForge CVS 快照）
- Issue：GitHub `#25`（用户点名）
- James Smith 2002 MudOS 库，部分基于 Discworld 20.0；MySQL 鉴权 / 权限（`db_connect`）与 web 内容栈

## Bring-up 结论（2026-11-10）→ `noboot`

1. 解包转换后 port `40396`，master `/secure/adm/master`
2. CVS 快照的 `include/` 与 `secure/include/` **目录为空**（Discworld 风格头文件未进库）；simul_efun 首行即 `Cannot #include config.h`
3. 设计依赖 MySQL：`DB_HOST=localhost` / `DB_DATABASE=mofn` / user `mud`（`secure/handlers/db.lpc`）。无库则鉴权与 permission handler 无法工作（同 `realms` 先例）
4. 不 stub 整棵 include 树 + MySQL；标 `wasm_status=noboot`，保留转换树供日后有完整 dump / DB 时再启

## 验证

- Boot 失败于 simul_efun 加载（缺头文件）；未进入监听

## `if (bits[0] = "player")` 条件里的赋值（2026-11-10，KB 06 §7.290）

`secure/handlers/bank.lpc` 的 `query_account()` 写成 `if (bits[0] = "player" && …)`，赋值恒真，任何 `acct` 前缀都当玩家账户解析。`lpc_fix_cond_assign.py` 改为 `==`。`lpc_fix_cond_assign` 扫后残留为 0。
