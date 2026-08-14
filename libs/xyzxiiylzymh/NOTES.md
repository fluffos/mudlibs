
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳再现II-炎龙专用美化客户端——xysylmhb 家族的又一个夕阳再现III/炎龙封印构建版本，同样有 AKAI Studio 的 Tomud '2060' 客户端握手闸门。WASM 修复靠 scripts/lib_bulk_fix.py + scripts/scan_known_bugs.py 在第一次启动测试之前就主动抓出来：标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经正确）改成了逐码点的 name[i..i]；master.lpc 的 valid_read()/valid_write() 缺少 'user == this_object()' 短路判断（这份档案和它的手足档案一样，已经有一段基于 previous_object() 的局部保护——额外补上了标准保护）。dns_master.lpc 本来就已经在 preload 里被注释掉（原来就是这样，休眠状态）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（SECURITY_D 正确指向 securityd.lpc）。注册流程在一次连续的 WASM 客户端会话里完整验证过：版本握手（2060）→英文 id→y（确认新角色）→中文名字→管理员密码+确认→登录密码+确认→天赋菜单（0 随机，y 接受）→电子邮件→性别（m/f）→在北疆小镇进入游戏世界（和手足档案 xysylmhb 的南城客栈不同的起始房间——这个构建版本在 4 个 start_room 条目里随机选择），look/score 都干净。管理员权限已通过"★ 您目前权限：(admin)"确认。LPC 格式化工具对全部 8302 个档案运行（写入 8205 个，64 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，33 个未改动）。没有 :: 父类呼叫拆分命中；一处 CJK 重新加空格命中（d/city/sj.lpc）确认是和 xysylmhb 那份完全相同的手足档案上见过的同一处转档之前就存在的缺失引号损坏，已还原；和 xysylmhb/xyzx 一样的 2 处 case 标签带尾随注释的命中（cmds/bakcmds/csc.lpc、cmds/bakcmds/meskills.lpc，都是死代码备用指令副本）经 diff 复核干净。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。**更正**：
group_note 里描述的"管理员密码+确认→登录密码+确认"双密码流程和这
份档案实际代码不符——`adm/daemons/logind.lpc` 读代码确认只有一组
密码（`new_password`/`confirm_password`），没有独立的"管理密码"
（`wizpwd`）步骤，和手足档案 `xysylmhb`/`xyzx` 的双密码机制不同，
这是同一血统下的一个更简化的构建变体。连线握手（"2060"）沿用同一
家族的机制。

### 发现并修复的 PROGRAMMING bug

1. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。
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
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程（含"2060"握手）创建，落地"客店"，`score`
显示"【天界总管】"头衔，食物/饮水满格。随后**单独一步**做了真实断
线重连+密码验证（同样先发"2060"握手）：用刚设的密码重新连线成功
登录，存档数据一致。全程 `debug.log` 无运行时错误（连线过程中出现
的 `bnway`/`lbadd0`/`lbclear0`/`ptext` 之类原始字符串是 Tomud 客户
端专用带外控制标记，正常客户端会解析成小地图/状态栏 UI，不是
bug）。驱动按精确 PID 结束；管理员存档已提交。
