
## WASM 修复摘要（迁移自 meta.json 的 group_note）

海洋II（Ocean II）血统，hy2000/hy2002 的手足档案（分别按路径和两者重合约 9600/10253 个档案）——上海站第三版快照。修复的 bug（全部是主动套用已知的 hy2000/hy2002 修法并确认这里同样存在）：（1）过时的 MASTER_OB/SIMUL_EFUN_OB 宏指向 /adm/single/ 死代码副本（§7.56 类）；（2）howmany_visitor()/howmany_card()/uptime.lpc 的 LASTCRASH 显示里 §7.54 类的 sscanf/write(read_file(缺失档案)) 崩溃；（3）adm/daemons/network/dns_master.lpc 的 startup_udp()/send_udp()/send_shutdown() 里 §7.52 类的 socket 掏空；（4）经典 §8.1 check_legal_name() 字节数没减半的长度界限 bug（2/10→1/5 字符）加上 i%2==0 门槛和 name[i..<0] 尾部切片（is_chinese() 本身已经是正确的）；（5）§7.63 quit.lpc 的 new('/clone/topten/magic-rice') 缺少防御性判断 if(ob=new(...))，和 hy2000 的模式完全一致。管理员引导偏离常规模式（和 hy2002 同一类 §1.5 bug）：securd.lpc 在 restore_list() 里硬编码了引导用管理员 id "titny"，但这个 id 已经是档案里一个真实存在的旧玩家账号——已在旁边追加一行 set("wiz_status/fluffos","(admin)")，用 fluffos/loginpass1 注册，游戏内"目前权限：(admin)"显示确认生效。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字；GB 和 BIG5 两种编码都实测正常（gb_b5d.lpc 的中文字转换表里有一处无害的编译警告，两种模式下文字都能正确显示）。格式化工具发现 1 个真正损坏的档案（cmds/usr/setbak.lpc，和 hy2000/hy2002 一样的 heredoc 帮助文字损坏）——已用 git checkout 还原。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 53 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
