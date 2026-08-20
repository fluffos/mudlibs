
## WASM 修复摘要（迁移自 meta.json 的 group_note）

内容和 xxcqii 的小雪初晴II.rar 完全相同的 .zip 重新打包版——全部 3033 个共有 .lpc 档案逐字节相同（已通过对照 xxcqii 修复前那次提交的全量内容哈希比对确认）；唯一差异是多出一个档案 topten/topbook.lpc（一份运行时排行榜存档，不是源代码内容）。真正的 WASM 修复过程（httpd/dns_master 的 §7.52 socket 精灵修复、管理员播种、格式化）见 xxcqii，这里不再重复。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

同一形状扩展到全库通用房间基类：删除 846 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），另修正
`clone/misc/roommaker.lpc` 字符串拼接模板里同一枚烤死的
`replace_program(ROOM);`——和手足档案 `xxcqii` 是完全相同的 bug 形
状与命中数（847 处），但注意这次逐档对照发现两份档案在当前状态下
并**不是**逐字节相同（`roommaker.lpc` 等大量档案存在缩进风格差异，
制表符 vs 空格、大括号换行位置等），和本档案 NOTES.md 早先记录的
"与 xxcqii 完全相同"结论不一致（那条结论应是修复前某次格式化差异
导致，或指的是逻辑内容而非字节级别）——因此本次按独立档案完整走
了一遍验证流程，而不是假定与 xxcqii 的结果可以直接照搬。已用
`build-debug` 驱动干净启动验证（0 个新增编译错误，端口正常监听）；
未做完整 §10.7 深度游玩测试。
