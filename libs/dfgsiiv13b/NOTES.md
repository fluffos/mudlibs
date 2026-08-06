
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2 血统代码库（台湾，1994-2000，Annihilator），繁体中文。重大编码发现：最初的 convert_lib.sh 转档流程把这份档案当成 GB18030 解码——GB18030 几乎涵盖所有字节序列，即使这份档案实际是 BIG5 编码也会"成功"解码，只是产生完全的乱码（落在注音符号 Unicode 区段的垃圾字元，比如 BIG5 本该解码成"使用者"的地方变成了"ㄏノ祅祘"），而不是一个转换流程可以拦截到的解码错误。已改用 BIG5 重新跑一遍完整的 raw->work 转换（套用前先用 Python 对照 big5/gbk/gb18030/cp950 四种编码试解码原始 .c 档案，确认 BIG5 才是正确答案）。另外还需要：（1）master.lpc 的 connect(int port) 用 switch 比对一个写死的 MUD_PORT（4000，泥潭原始默认值），而不是本项目实际分配的端口（40144）——不管在不在 WASM 下，每一个连线都会被拒绝（驱动记录："Can not accept connection ... due to error in connect()"），已改为更新 MUD_PORT 宏；（2）master.lpc 的 valid_read/valid_write 递归呼叫 load_object(SECURITY_D) 却没有防递归机制——经典的 §7.1，第一次真正的安全检查就触发"Too deep recursion"，已用文档记载的防递归旗标手法修复；（3）adm/daemons/userid.lpc（identd/RFC1413 反查服务，纯 socket 功能）按 §7.52 掏空处理；（4）is_chinese() 的经典 GBK 字节配对判断（要求 strlen>=2）在 Unicode 码点模型下会拒绝单字符或奇数长度的名字切片——已改成 CJK 码点区间判断。重新套用了一个之前已提交、但这次 BIG5 重新转换（从 raw 重新生成 work/）不慎覆盖掉的原生修复（移除一个和这个驱动自动预定义的 MUD_NAME 冲突的 #define MUD_NAME，§7.39）——先查过 git 记录确认那次提交还动过什么其它地方，只有 globals.h。管理员账号（fluffos/Mud@2026）通过真实注册流程 + 全新创建的 adm/etc/wizlist 播种（原始压缩包里没有附带这个档案）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
