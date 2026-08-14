
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳三-炎龙美化版（夕阳再现III 之 炎龙封印，AKAI Studio）。和 xyj2006 家族一样有 'version '/'2060' 的 Tomud 客户端握手闸门（第一行回复必须是字面的 '2060'）。注册流程没有 'new' 关键字（任何全新 id 都会问 y/n 新角色确认，和 xyj451 一样）；天赋是菜单选栏位（1-4 自定单项属性，0 系统随机整组，然后 y/n 确认接受）。WASM 修复靠 scripts/lib_bulk_fix.py + scripts/scan_known_bugs.py 在第一次启动测试之前就主动抓出来：标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经是正确的逐码点写法）改成了 name[i..i]；master.lpc 的 valid_read()/valid_write() 缺少 'user == this_object()' 短路判断（已主动补上，和这份档案自己原有的、通过 previous_object() 实现的局部保护并存）——和 xyj20032 上曾经静默弄坏每一次注册的那个潜伏风险一模一样。adm/daemons/network/dns_master.lpc（真正生效的 DNS_MASTER，已通过 net/daemons.h 确认）本来就已经在 preload 里被注释掉（原来就是这样，休眠状态）——还有一份没有引用的死代码副本 adm/daemons/dns_master.lpc 也带有原始 socket 呼叫，但从未被加载。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（SECURITY_D 正确指向 securityd.lpc，真的会读取 WIZLIST——globals.h 里另一个 'securd' 路径是注释掉的，这里没有 §7.56 的歧义问题）。注册流程在一次连续的 WASM 客户端会话里完整验证过：版本握手（2060）→英文 id→y（确认新角色）→中文名字→密码+确认→0（随机天赋）→y（接受）→电子邮件→性别（m/f）→在客店进入游戏世界，look/score 都干净。管理员权限已通过"您目前权限：(admin)"确认。LPC 格式化工具对全部 8302 个档案运行（写入 8205 个，64 个转档之前就存在的未结束字符串/文本块内容错误未做格式化——是这一批里最杂乱的一份代码库——33 个未改动）。没有 :: 父类呼叫拆分命中；一处 CJK 重新加空格命中（d/city/sj.lpc）确认是和 tybxjh/xhcii 手足档案上见过的同一处转档之前就存在的缺失引号损坏，已还原；两处 case 标签带尾随注释的命中（cmds/bakcmds/csc.lpc、cmds/bakcmds/meskills.lpc，都是死代码备用指令副本）经 diff 复核干净。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。这份档案的连线
握手比较特殊：`get_id()` 要求连线后的第一行输入必须是字面
的"2060"（Tomud 专用客户端协议握手，不是真正的英文 id 提示，尽管
显示的提示文字写的是"请输入您的英文名字"），之后才是真正的
id→y→中文名→密码 ×2→天赋(0)→接受(y)→email→性别 流程。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`，且这份档案的写法比其它手足档案更简化——连
   `!user->query("food")` 这层"只在从未初始化时才补发"的保护都没
   有，只单纯判断 age）。已改成 `user->query("age") == 14`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`；`d/huashan/npc/refereew.lpc`/`referee.lpc` 未用到 `%`，不适
  用。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程（含"2060"握手）创建，落地"铁枪庙"，
`score` 显示"【天界总管】"头衔，食物/饮水满格。随后**单独一步**做
了真实断线重连+密码验证（同样先发"2060"握手）：用刚设的密码重新
连线成功登录，存档数据一致。全程 `debug.log` 无运行时错误（连线过
程中出现的 `bnway`/`lbadd0`/`ptext` 之类原始字符串是 Tomud 客户端
专用的带外控制标记，正常客户端会解析成小地图/状态栏 UI，不是
bug，用原始 socket 客户端测试时会看到字面文字属于预期噪音）。驱
动按精确 PID 结束；管理员存档已提交。
