
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2006之最终幻想——另一个 AKAI Studio Tomud 品牌分支，是 122 号 xyj2006n 的手足档案（文件布局和 bug 模式完全相同；需要同样的自定义客户端版本握手：第一行回复必须是字面的 '2060'）。WASM 修复了和 xyj2006n 完全相同的 5 类 bug：（1）标准的 §6.6 convertd.lpc 希腊字母表反斜杠错字（45 处，真正生效的 adm/daemons/convertd.lpc 和一份死代码副本 daemons/convertd.lpc 里都有），（2）4 处绝对路径尖括号 #include 在这个驱动的 include 目录规则下永远解析不了，（3）message.lpc 的 tell_room() 把未设置的 exclude 转发进 message() 第 4 个参数（§7.12），（4）两个残留的原始 GBK 内容档案（beast1.lpc、shuijingqiu.lpc）已用 iconv 重新转换，（5）真正生效的 adm/daemons/logind.lpc 的 check_legal_name() 标准 §8.1 奇偶门槛/后缀切片写法改成了逐码点写法，另外还有 6 处 is_killing(me) 对照 is_killing(string id)（§7.50）的呼叫点，分布在 daemon/class/*.lpc 的 kungfu 技能档案里。以上全部都是靠 scripts/lib_bulk_fix.py（机械修复 1-3）和 scripts/scan_known_bugs.py（4-5，两个都是本次会话新写的工具）在第一次启动测试之前就主动抓出来的，而不是一次启动周期发现一个。httpd.lpc/ftpd.lpc/dns_master.lpc 不在真正生效的预加载列表里（休眠状态，只能通过巫师手动加载触达）——没有掏空，标记为和 xyj2006n 一致的已知潜伏风险。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在一次连续的 WASM 客户端会话里完整验证过：版本握手（2060）→new→英文 id→中文名字→管理员密码+确认→登录密码+确认→电子邮件→性别（m/f）→属性分配菜单（9/y）→进入游戏世界，look/score 都干净，零错误，管理员权限通过"目前权限：(admin)"确认。LPC 格式化工具对全部 9264 个档案运行（写入 9119 个，8 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，137 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；case 标签带尾随注释的盲点找到了和 xyj2006n 一样的 combatd.lpc/ftpd.lpc 命中，逐一 diff 复核确认格式化工具正确保留了后面的每一条语句。格式化后重新验证干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 36 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
