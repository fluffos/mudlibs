
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记451（ES II mudlib 家族，v4.50）。注册流程没有 'new' 关键字：任何还没存档的英文 id 都会直接落到"是否使用 X 作为新角色，确认？(y/n)"。天赋分配是一个重投循环（"接受这组属性吗？[n|y|q]"，n 重投，y 接受，q 大概是放弃），和 三界/xyj2000 家族那种字段选择菜单不一样。WASM 修复靠 scripts/lib_bulk_fix.py + scripts/scan_known_bugs.py（两个都是本次会话新写的工具）在第一次启动测试之前就主动抓出来：（1）标准的 §8.1 GBK 字节区间 is_chinese()（str[0] > 160 && str[0] < 255）重写成逐码点 0x4e00-0x9fff 检查，配套的 check_legal_name() 的 i%2 奇偶门槛/[i..<0] 后缀切片也改成了逐码点的 name[i..i]；（2）master.lpc 的 valid_read()/valid_write() 直接转发给 SECURITY_D，没有 'user == this_object()' 保护——和 xyj20032 上曾经静默弄坏每一次注册的那个潜伏风险一模一样，这里没有观察到实际触发，属于主动预防性修复；（3）14 处 is_killing(me)/is_killing(who) 呼叫点，分布在 kungfu 技能的 daemon/class/*.lpc 档案和 cmds/std/surrender.lpc 里，用物件当参数传，而 feature/attack.lpc 对应声明的是 is_killing(string id)（§7.50）。httpd.lpc/dns_master.lpc 本来就已经在 adm/etc/preload 里被注释掉（休眠状态，原来就是这样）——保持原样，没有编译崩溃风险。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB 选择→英文 id→y（确认新角色）→中文名字→密码+确认→电子邮件→性别（m/f）→y（接受重投的属性）→q（跳过分页的每日消息）→在南城客栈进入游戏世界，look/score 都干净。管理员权限已通过"目前权限：(admin)"确认。LPC 格式化工具对全部 9322 个档案运行（写入 9297 个，9 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，16 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；唯一一处 case 标签带尾随注释的命中（ftpd.lpc）经 diff 复核干净。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 41 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
