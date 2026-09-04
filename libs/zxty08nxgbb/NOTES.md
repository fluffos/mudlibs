
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

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（2026-09-03，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师，并核对重连后门派是否还在。

### 实测过程

管理员 `fluffos` / 普通密码 `Mud@2026`（本次未走管理密码）。落地
`/d/city/wumiao`。`goto /d/city/zuixianlou`，店小二 `list` 价目为铜钱
尺度（烤鸡腿八十文钱）。`clone /clone/money/gold` 后 `buy jitui` 成功
（找零九十九两银子 + 二十个铜板）。`goto /d/gaibang/inhole`，
`apprentice zuo`：左全收徒，`score` 称谓「丐帮第二十代弟子」、师傅
左全。显式 `save` 成功。

`quit` 仍走 `mud_age < 1800` 的删档分支（`cmds/usr/quit.lpc` 只在
三次确认提示上豁免巫师，真正 `rm` login/user 存档时没有
`wizardp()` 判断）——和 `zxty`/`wlhd`/`tybxjh` 同一既有政策，未改。
本轮在 `quit` 之前已经 `save`，`user.o` 里的 `family` 还在；被删掉
的是 `login.o`（从 git 还原后重连）。重连 `score` 仍是丐帮第二十代
弟子 / 师傅左全，银子还在；烤鸡腿不存档（食物 `no_save`）。本轮
`wzd_log` 验证码在有残留身体时触发过一次，按显示六位里第 2–5 位
算 `(n1*n4+8)*100+n2*n3-3` 通过，公式和 2026-08-13 记录一致。

本血统 `feature/dealer.lpc` 没有丐帮「穷叫化」拒绝（和 xyzx 家族
不同），拜师前后都能买。

### 发现并修复的 PROGRAMMING bug

1. **`exert_function(10)` 类型错误，4 处**（和 `zxty` 2026-08-13 已
   修的那一组相同，这份 08 年修改版当时漏了）：
   `d/daniel/saveme.lpc`、`d/player/ltsh/npc/saveme.lpc`、
   `d/zjb/shengji.lpc`、`u/zjb/hlxy/zs.lpc`。`exert_function` 要
   string，传入 int 则编译失败。武庙 `objects` 里写了
   `"/d/daniel/saveme"`，所以每次登陆武庙都会
   `Bad type for argument 1 of exert_function (string vs int)`，NPC
   进不来房间。已按 `zxty` 同样办法删掉这行死代码。修复后武庙
   `look` 出现「清神 大魔道士--雅薇丝」。

2. **`securityd.lpc` `valid_read()` 里对 `/log/` 的拒绝会
   `log_file("file/bug_read")`，而 `log_file` 自己又要
   `valid_read(/log/...)`**——非 `zmud`/`landy` 的巫师（包括
   `fluffos` admin）每次登陆写 usage 日志、以及 `clone` 碰到
   `/log/` 时，都会 `Too deep recursion`（报在
   `sscanf(base_name(user), ...)` 那一行）并刷几十行「警告：你不能
   操作这些目录下的文件。」。加了 `in_valid_read` 重入保护：第一次
   拒绝仍写一条警告并记 log，再入直接 `return 0`。修复后登陆只剩
   两行警告（`log_file("usage")` / `log_file("USAGE")` 各一次），
   `clone /clone/money/gold` 一行警告、黄金复制成功，不再 recursion。

### 观察（未改）

- `quit` 对 `mud_age < 1800` 的巫师同样删 `login.o`：确认提示有
  `!wizardp()` 豁免，真正 `rm` 没有。与先前 §7.100 记录的「quit
  删掉刚登录用的 login.o」是同一形状，当既有政策留下。
- 本轮 `feature/dealer.lpc` 无丐帮购买拒绝。
- 驱动 `log/debug.log`（`cd libs/zxty08nxgbb && driver` 打开在
  chdir 之前）是本轮 live 日志；mudlib `error_handler` 写
  `work/log/debug.log`。修复后的那次 boot 后者没有新的执行时段
  错误。
