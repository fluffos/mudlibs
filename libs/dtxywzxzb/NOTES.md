
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记血统代码库（大唐西游/Journey of the East）。完整 WASM 修复：（1）adm/daemons/convertd.lpc 的希腊字母表漏斜杠错字（§6.6，约 45 处，完全符合已记录的模式），导致 simul_efun 编译失败——已用文档记载的 CRLF 安全 sed 脚本修复；（2）两份用途相同的档案陷阱（§7.56 类）：既有一份 /daemons/logind.lpc（死代码副本，没有任何 LOGIN_D 宏引用它），也有真正被 LOGIN_D 宏解析到的 /adm/daemons/logind.lpc——一开始追错了档案，得到一个完全不同（而且更短）的注册流程；真正生效的档案比死代码副本多了几个步骤（夹在中文名字和普通登录密码之间的一道独立"管理密码"步骤，规则更严格，外加性别选择之后的属性重掷菜单）。（3）GB/BIG5 编码选单（§8.7"第二种形态"，本地整数旗标覆盖+convertd.lpc 字节对照表）这次是真实存在的 bug——选 BIG5 会疯狂输出"Invalid GB code"并弄花画面，因为这张对照表假设的是原始 GB2312 字节，而这份代码库现在全程都是 UTF-8——已把两个选单选项都对应到 encode=0（这个家族的 convertd.lpc 本来就把它当成安全直通）。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 36 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
