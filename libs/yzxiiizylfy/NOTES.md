
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳再现III之炎龙封印（阿凯工作室，AKAI Studio，2006）。和本次会话其它夕阳再现家族档案一样使用同样的 Tomud '2060' 客户端版本握手（get_id() 会拒绝除字面字符串 '2060' 之外的任何第一次输入，提示'not a Tomud client'，然后才继续到 get_id1() 真正的英文 id 提示）。WASM 修复了：（1）标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经是正确的逐码点写法）——改成了逐码点的 name[i..i]，界限从 2/10 减半为 1/5。（2）master.lpc 的 valid_read()/valid_write() 缺少标准的 'user == this_object()' 短路判断——两处都已加上，和这份档案自己原有的（不同寻常、局部的）基于 previous_object() 的保护并存，保留不动。tell_room() 的 exclude 参数和 securityd.lpc 的 save_object() 扩展名检查在这份档案里本来就是正确的，不需要修。存在两份 dns_master.lpc 副本（adm/daemons/dns_master.lpc 和 adm/daemons/network/dns_master.lpc）；DNS_MASTER 宏只引用了 network/ 那一份（adm/daemons/dns_master.lpc 是死代码，没有任何宏或字面路径引用它），而真正生效的那份在 adm/etc/preload 里被注释掉，只有带 find_object() 保护的巫师指令呼叫者——两份都保持原样，不需要 §7.52 掏空处理。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在格式化前后都完整验证过（2060 客户端版本握手→英文 id→y 确认→中文名字→密码+确认→天赋菜单（'0' 随机→'y' 接受）→电子邮件→性别→进入铁枪庙），管理员权限已通过'★ 您目前权限：(admin)'确认。LPC 格式化工具对全部 8302 个档案运行（写入 8205 个，64 个转档之前就存在的错误，33 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。一处 CJK 重新加空格/转义损坏命中（d/city/sj.lpc，一个转档之前就存在、本次会话改动之前就有的不配对引号打字错误，导致格式化工具的分词器失步）——已按 AGENTS.md §9 记载的第 3 个盲点还原，底层的打字错误保持原样，没有进一步深挖。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
