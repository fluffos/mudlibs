
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 146/hy（海洋基础档案）同一血统——同样的重复 create() ftpd.lpc 修复（§7.40）和 author_file() 防递归；完成了一次中断的转档（58882 个档案的压缩包最初转档超时中断）；修复了 tell_room() 里 efun::message() 对 exc_target=0 的拒绝；启动干净。完整 WASM 修复：给 band.lpc 的 is_banned() 加了本地回环放行；修复了和 146/hy 完全相同的 adm/daemons/logind.lpc 里 seteuid(getuid()) 把 euid 重置掉的 bug（create()、howmany_user()、make_body() 都改成显式的 seteuid(ROOT_UID)）；给 howmany_visitor()/howmany_card() 加上了缺失计数档案的防护；修复了 check_legal_name() 过时的 GBK 字节长度界限（4-10→2-5，去掉 i%2==0 门槛，is_chinese() 改成逐字符呼叫）；给 adm/daemons/securd.lpc 的 get_status() 加上了和 146/hy 相同的防重入编译崩溃保护（arrayp(wiz_levels) 判断）。另外发现了一个 146/hy 没有的新 bug：adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 无条件呼叫 socket_create/socket_bind/socket_close（WASM 下没有 sockets 包），导致整个档案编译失败——由于 gb_big5() 间接碰到这个精灵，编译失败会静默破坏整个注册流程（input_to(get_id) 从未真正注册过，之后所有输入都落进普通的指令解析器）。已把涉及 socket 的函式体掏空成 no-op 修复，和 §7.52 里 mudlistd.lpc 的模式相同。管理员账号直接播种进了 adm/daemons/securd.o 的 wiz_status 映射（和 146/hy 相同的非 wizlist 机制），用二进制模式编辑。注册流程到进入游戏世界、管理员权限识别都已验证；这条血统的 Big5 提示实际上要求输入 g/gb 或 b/big5（不是 y/n）——不要照搬另一份措辞相似的 146/hy 提示的语义假设。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 62 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
