
## WASM 修复摘要（迁移自 meta.json 的 group_note）

从一个"rar 套 rar"的嵌套压缩包中提取（外层压缩包里有一个"风起云涌.rar"，里面才是真正的 mudlib 根目录，文件夹名叫 xkx2）；和本项目里任何其它档案都没有 master-hash 匹配；启动干净，零修复。完整 WASM 修复：和"海洋/hy"血统同一套 bug 组合（这份档案的 SECURITY_D 也指向 adm/daemons/securd.lpc）——给 band.lpc 加了本地回环放行；修复了 logind.lpc（create()/make_body()/howmany_user()）里 seteuid(getuid()) 把 euid 重置掉的 bug；给 howmany_visitor()/howmany_card() 加上了缺失计数档案的防御；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 门槛；给 securd.lpc 的 get_status() 加上了防重入编译崩溃的保护。新发现的 bug（和 hy5 同一类）：adm/daemons/network/dns_master.lpc 在 3 个函式里无条件呼叫 socket_create/socket_bind/socket_close/socket_write，导致整个档案编译失败——而由于等同于 gb_big5() 的开机流程会间接碰到这个精灵，编译失败会静默破坏每一次连线的 input_to(get_id) 注册流程。已按 AGENTS.md §7.52 把涉及 socket 的函式体掏空成 no-op。管理员账号播种进了 adm/daemons/securd.o 存档文件自身的 wiz_status 属性（逐键用 CR 编码，需二进制模式读写）。注册流程到进入游戏世界、管理员权限识别都已验证。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 94 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
