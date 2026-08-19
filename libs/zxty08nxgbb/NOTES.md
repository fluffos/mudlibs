
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 138 号 zxty 一样是再现天涯，是 2008 年的修改重新发布版本——master.lpc 内容不同，没有精确哈希匹配，但标题/血统相同；完成了一次中断的转档；重新实现了 efun::tail()（§6.2）；启动干净。完整 WASM 修复：给 band.lpc 加了本地回环放行（这个血统会封禁任何不能严格解析成 4 段点分十进制的地址）；修复了 logind.lpc（create()/make_body()）里同样的因为多余 seteuid(getuid()) 而把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 的字节配对门槛；修复了 named.lpc 的 invalid_new_name() 拒绝单字名字的问题，以及它按字节步进的近似重复名字滑动窗口（重写成按字符步进，和 nt1 的 named.lpc 是同一个 bug 同一种修法——这个血统和 NT/nitan 家族共享 named.lpc/注册房间设计，不只是和 jym 共享）；给 securityd.lpc 的 get_status() 加上了防御性保护（mapp/arrayp 检查，虽然没有实际观察到重入，但这是廉价的保险）。管理员账号通过纯文本的 /adm/etc/wizlist 档案播种（这个血统的 securityd.lpc 每次启动都会直接读取它，不涉及存档档案）。注册到进入游戏世界、look/score/quit（quit 会正确触发这个血统自己的 30 分钟防滥用确认提示，不是 bug），以及管理员身份识别（"您目前权限：(admin)"）都已干净验证。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 101 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试。这份档案是同一"再现天涯"血统里 `zxty`（本轮刚做完深挖）
的 2008 年重发布变体——master.lpc 内容不同（没有精确哈希匹配），
但独立核实后发现了几乎一模一样的一整套 bug 形状，说明这些问题在
分叉之前就已经存在于共同祖先里。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）的两条并行回显分支都没有严重度检查**：`if
   (this_player(1)) efun::write(...)` 和 `else if (this_player())
   tell_object(...)`——和 `zxty` 完全相同的双分支形状，这次一次性
   把两条分支都包进 `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护**：已加上前向声明 +
   `assure_file(LOG_DIR + file);`。
3. **`cat()`（同一文件）两处 `write_file("/log/file/{cat,bugcat}",
   ...)` 同样缺少 `assure_file()` 保护，且 `read_file()` 结果没有
   类型检查**：和 `zxty` 一样确认过 `cat(MOTD)` 调用者是
   `/adm/daemons/logind`，两处 `write_file()` 都显式排除了这个调
   用者，本身不会导致"每次登录必崩"，但玩家/巫师直接用 `cat` 指令
   仍会命中。已加上 `assure_file()` 并把 `write(str1)` 改成
   `write(str1 || "")`。
4. **`feature/dbase.lpc`（真正生效的 F_DBASE）的密码写保护是
   tybxjh/wlhd/zxty 那一类已确认的 bug 形状**：`wizhood()` 纯粹读
   `wizlist` 文件，不检查密码是否已经真正存在于 `dbase` 里。已加
   上 `mapp(dbase) && dbase[prop]`。（`u/zjb/` 目录下三份死代码副
   本有相同形状，未改动，无任何引用指向它们。）
5. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`）。已改成 `user->query("age") == 14`。
6. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。

### Proactive checks / 观察记录

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`。
- **同一个 `wzd_log.lpc` 巫师算术验证码机制，行为和 `zxty` 一
  致**：`adm/daemons/wzd_log.lpc` 存在且真正被 `logind.lpc` 呼叫
  （不是死代码）。用 `scripts/mudclient.py` 连续快速重连时触发了
  这个挑战（随机数字+隐藏公式答案，答错干净断线，不崩溃）；改用一
  个独立的裸 socket 脚本单独测试时完全没有触发，直接成功登录并显
  示"您目前权限：(admin)"——和 `zxty` 观察到的间歇性触发模式完全
  一致，同属"连线时序相关，不产生真正程序错误"的既有现象，未修
  改。

### 实测过程

管理员 `fluffos`（管理密码 `AdminMud@2026`，普通密码
`Mud@2026`，`adm/etc/wizlist` 早已播种但从未真正注册过）用完整双
密码注册流程创建，落地"铁枪庙"，`score` 显示"【天界总管】"头衔，
食物/饮水满格。随后用独立裸 socket 脚本做了真实断线重连+密码验
证：成功登录，`(admin)` 权限确认，存档数据一致。全程 `debug.log`
无运行时错误。驱动按精确 PID 结束；管理员存档已提交。

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). Deleted 2,323 live
standalone `replace_program(ROOM);` lines under `work/` via
`fix_710_room.py`, plus hand-fixed both room-building tool copies'
string-builder template (`work/clone/misc/roommaker.lpc`,
`work/u/landy/obj/roommaker.lpc`). 3 real `.lpc` files under
`work/data/` checked — none had the bug pattern. Remaining matches
after the fix are all pre-existing `//`-commented.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`Mud@2026`) into 铁枪庙, `look`/`score`/`quit` all worked
cleanly. Same sibling-lineage quirk as `wlhd`/`tybxjh`: `quit` deleted
`data/login/f/fluffos.o` even though it had just been used to log in
— reverted via `git checkout HEAD -- work/data` before committing,
unrelated to this fix and out of scope.
