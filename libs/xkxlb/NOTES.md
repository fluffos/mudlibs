
## WASM 修复摘要（迁移自 meta.json 的 group_note）

从一个扩展名错误的 .rar（实际是带有 ../ 成员路径的 POSIX tar）提取；启动靠 /adm/single/master（树里还打包了一份未使用的 adm/obj/master.lpc，碰巧和 jyqxc/fy2mg/xkx2017 框架家族字节相同，但不是真正被加载的那份）；启动干净，零修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限；给 securityd.lpc 的 get_status() 加上了防御性保护；修复了 securityd.lpc 的 valid_write() 里经典的 §7.49 存档扩展名不匹配 bug。最大的发现：include/globals.h 里的 SIMUL_EFUN_OB 指向一份过时、未使用的 /adm/single/simul_efun.lpc（早期重构留下的死代码副本，虽然在树里但没有被 config.fluffos 的"simulated efun file"设定引用），而不是 config.fluffos 真正加载、定义了 destruct() 覆写的那份真正的 /adm/obj/simul_efun.lpc。这破坏了 feature/move.lpc 的 remove() 安全检查（它会核对 previous_object() 是否等于 SIMUL_EFUN_OB）——每一次经由那个覆写路由的物件销毁都会失败——具体表现为：每一个新玩家的 quit 都会失败，因为 quit 的自动丢弃背包逻辑会销毁任何不值钱的丢弃道具（每个新角色出生就带着一件）。这个 bug 很隐蔽：连线会打印一个被捕获的运行时错误、看起来像是断开了，但角色其实仍然在线，世界那一侧的连线从未真正关闭。已把宏指向真正的档案来修复（和之前某个 lib 里 securityd.lpc/securd.lpc 重复档案陷阱是同一种直觉——哪怕宏名字看起来"显然正确"，也要用 config.fluffos/真实调用链去验证它到底指向哪个文件）。另外修复了一份真正损坏的留言板存档（data/board/kedian_b.o 的某条留言作者字段里有原始的非 UTF-8 GBK 字节，导致每次在那个房间 look 都崩溃）——直接删除了这份损坏的存档档案，而不是冒险做局部字节级重新编码。管理员账号通过纯文本的 adm/etc/wizlist 档案播种。注册流程到进入游戏世界、look/score、以及一次正确完成的 quit 都已干净验证——建议在任何共享这种 SIMUL_EFUN_OB/重复 simul_efun 档案形态的档案上都专门重新测试一下 quit。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 18 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
