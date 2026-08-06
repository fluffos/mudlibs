
## WASM 修复摘要（迁移自 meta.json 的 group_note）

内容和 xxcqii 的小雪初晴II.rar 完全相同的 .zip 重新打包版——全部 3033 个共有 .lpc 档案逐字节相同（已通过对照 xxcqii 修复前那次提交的全量内容哈希比对确认）；唯一差异是多出一个档案 topten/topbook.lpc（一份运行时排行榜存档，不是源代码内容）。真正的 WASM 修复过程（httpd/dns_master 的 §7.52 socket 精灵修复、管理员播种、格式化）见 xxcqii，这里不再重复。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
