
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳再现 之「风云再起Ⅱ」——夕阳三-炎龙美化版（xysylmhb）家族的原始基础版本；logind.lpc/master.lpc/注册流程几乎一致，标准端口上没有 Tomud '2060' 握手闸门（master.lpc 的 connect() 里有一个单独的 TOMUD_PORT 检查会设一个临时标记，logind.lpc 只在这个标记被设置时才检查它，所以普通的、相当于 telnet 的端口完全跳过这一步）。WASM 修复靠 scripts/lib_bulk_fix.py + scripts/scan_known_bugs.py 在第一次启动测试之前就主动抓出来：（1）一个 uptime()<30 启动宽限门槛（AGENTS.md §1.3(e)，和 xyxyutf8 等档案同样的模式）——已对本地回环连线放行。（2）标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经正确）改成了逐码点的 name[i..i]。（3）master.lpc 的 valid_read()/valid_write() 缺少 'user == this_object()' 短路判断（这份档案已经有一段基于 previous_object() 的局部保护，和 xysylmhb 一样——为了一致性又额外补上了标准保护）。httpd.lpc/dns_master.lpc 本来就已经在 preload 里被注释掉（原来就是这样，休眠状态）——保持原样。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（SECURITY_D 正确指向 securityd.lpc，真的会读取 WIZLIST；globals.h 里另一个 securd 路径是注释掉的，没有 §7.56 的歧义问题）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y（确认新角色）→中文名字→管理员密码+确认→登录密码+确认→天赋菜单（0 随机，y 接受）→电子邮件→性别（m/f）→在客店进入游戏世界，look/score 都干净。管理员权限已通过"★ 您目前权限：(admin)"确认。LPC 格式化工具对全部 14000 个档案运行（写入 13888 个，75 个转档之前就存在的未结束字符串/文本块内容错误未做格式化——是目前这一批里最杂乱的代码库——37 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；和 xysylmhb 一样的 2 处 case 标签带尾随注释的命中（cmds/bakcmds/csc.lpc、cmds/bakcmds/meskills.lpc，都是死代码备用指令副本）经 diff 复核干净。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。这份档案（和手
足档案 `xysylmhb` 一样）用双密码机制：先设"管理密码"（用于账号安
全恢复），再设"普通密码"（日常登录用，系统会拒绝和管理密码相同的
普通密码）——已确认没有 tybxjh 那种把管理密码明文写进 help 文件的
§7.84 泄漏，也没有 `feature/dbase.lpc` 里 tybxjh/wlhd 那种密码写保
护 bug（这份档案压根没有 `dbase.lpc` 里涉及密码字段的守卫逻辑）。

### 发现并修复的 PROGRAMMING bug

1. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`，CRLF 行
   尾档案）各有一处调试残留 `printf("%O\n", ob)`（AGENTS.md
   §7.34-class）**：紧跟在中文名字确认之后，把连线桩物件的原始引
   用直接回显给正在注册的新玩家。已删除两处。
2. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
3. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
4. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`）。已改成 `user->query("age") == 14`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`；`d/huashan/npc/refereew.lpc`/`referee.lpc` 未用到 `%`，不适
  用。

### 实测过程

管理员 `fluffos`（管理密码 `AdminMud@2026`，普通密码
`Mud@2026`，`adm/etc/wizlist` 早已播种但从未真正注册过）用完整注
册流程创建（id → y → 中文名 → 确认 y → 管理密码 ×2 → 普通密码 ×2
→ 天赋(0) → 接受 y → email → 性别 m），落地"北疆小镇"，`score`
显示"【玄法天君】"头衔，食物/饮水满格，`debug.log` 干净，未见调试
泄漏。随后**单独一步**做了真实断线重连+密码验证（用普通密码
`Mud@2026`）：成功登录，存档数据一致。驱动按精确 PID 结束；管理员
存档已提交。
