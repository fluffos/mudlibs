
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 nt6（142）同一血统/同一 master 哈希——本轮改动的每一个档案都先用 diff 确认逐字节相同才打的补丁。之前一轮移植了 nt6 早前的全部修复（is_chinese、check_legal_name 长度界限、12 个档案里的 origin() §7.47、band.lpc 回环补丁、心跳间隔/mudlistd 的 socket 移除、mudlistd 的裸数组修复）让它启动干净，但和 nt6 出于同样的原因（缓慢的分布式预载打乱了脚本化测试的计时）没有验证过注册流程。这一轮：既然 nt6 所有新修复过的档案（feature/dbase.lpc 完整的 set/query/delete 实现，logind.lpc/named.lpc 减半后的名字长度界限，以及 user.lpc/baby.lpc/giftd.lpc/examined.lpc/room.lpc 里 5 处 efun:: 改成 :: 的作用域解析修复）都确认和 nt6 修复前的版本逐字节相同，就直接把修好的档案原样复制过来，而不是重新推导一遍相同的补丁——完整的 bug 说明见 nt6 自己的 meta.json/README。在这份档案自己身上独立通过一次真实的 WASM 注册验证（不只是继承 nt6 的验证结果）：完整的 id→确认→姓氏→名字→管理密码→确认→登录密码→确认→性别→电子邮件注册流程零编译错误完成，look/quit 也已验证（包括 quit 的新账号删除确认流程），wizlist 里列出的管理员 id（fluffos）重新注册后也被正确带到巫师专属的起始房间。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 76 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
