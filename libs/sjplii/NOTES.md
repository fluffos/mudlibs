
## WASM 修复摘要（迁移自 meta.json 的 group_note）

sjplgfjxb 的手足档案（同一个飞白工作室《书剑飘零》ES II 代码库家族，这次用的是 adm/daemons/securityd.lpc——没有 securd/securityd 分裂，没有双档案混淆）。和 sjplgfjxb 不同，这份快照启动和注册都干净，完全不需要任何修复——sjplgfjxb 的那些 bug（report_error/CHANNEL_D、未定义的 REMOTE_DIR、损坏的 emote 存档）在这里都不存在。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已通过 include/globals.h 和 login.h 确认 SECURITY_D/WIZLIST 具体解析到的是 adm/daemons/securityd.lpc 和 adm/etc/wizlist——这份档案还带着好几个其它名叫 securityd.lpc/wizlist 的档案，分别在 adm/、adm/tmp/、adm/daemons/bak/ 下，都不是真正被使用的那些，符合既定的 §7.56 提醒）。已验证：完整注册（id→确认→名字→密码→确认→电子邮件→性别→出生地选择）→look/score/quit 全部干净，权限正确显示 (admin)，update 成功。LPC 格式化工具对全部 12421 个档案运行；还原了 2 个其实是纯文本 Windows dir 指令输出、被粘贴成 .lpc 扩展名的档案（不是真正的代码，格式化工具试图把它们当 LPC 重新排版导致损坏），另外还有 3 个确认有真正 CJK 重新加空格损坏的档案，都是通过"去空格后比对旧档案"扫描（覆盖 68 个格式化工具触碰过的档案）找到的；另外直接逐一比对了全部 3 个 map.lpc 档案——全部干净，只是排版调整。格式化后重新验证过，干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
