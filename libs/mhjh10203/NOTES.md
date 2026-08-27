
## WASM 修复摘要（迁移自 meta.json 的 group_note）

编译好的 Windows 客户端，带 Lua 脚本，不是 LPC。

## 深度功能测试（round two）— 不适用 (2026-08-27)

复核确认：`libs/mhjh10203/` 只有 `raw/`，没有 `work/`、没有
`config.fluffos`，`raw/` 内容是编译好的 Windows 可执行文件
（`Game.exe`/`tymain.exe`）、DLL（`ScriptManager.dll`、`lua5.dll`
等）和美术/音效资源（jpg/png/tga/wav/pak），完全没有可编译的 LPC
源码。`meta.json` 的 `wasm_status` 已经是 `"not-mudlib"`，与
`chongchujianghu`/`atlantis` 等同类档案一致。

因此本档案不具备 AGENTS.md §10.7 round-two 深度功能测试的前提条件
（无法用 `~/src/fluffos` 的 driver 启动，没有登录/角色/技能/战斗等
可测试的 LPC 逻辑）。§10.7 "找出所有未跑过 round-two 的 playable
lib" 的判定应该排除 `wasm_status: not-mudlib` 的档案——本条目就是为
了让以后的 round-two 扫描不要再把它当成候选目标。没有做任何代码/
配置改动。
