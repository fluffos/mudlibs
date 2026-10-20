
## WASM 修复摘要（迁移自 meta.json 的 group_note）

从一个扩展名错误的 .rar（实际是带有 ../ 成员路径的 POSIX tar）提取；启动靠 /adm/single/master（树里还打包了一份未使用的 adm/obj/master.lpc，碰巧和 jyqxc/fy2mg/xkx2017 框架家族字节相同，但不是真正被加载的那份）；启动干净，零修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限；给 securityd.lpc 的 get_status() 加上了防御性保护；修复了 securityd.lpc 的 valid_write() 里经典的 §7.49 存档扩展名不匹配 bug。最大的发现：include/globals.h 里的 SIMUL_EFUN_OB 指向一份过时、未使用的 /adm/single/simul_efun.lpc（早期重构留下的死代码副本，虽然在树里但没有被 config.fluffos 的"simulated efun file"设定引用），而不是 config.fluffos 真正加载、定义了 destruct() 覆写的那份真正的 /adm/obj/simul_efun.lpc。这破坏了 feature/move.lpc 的 remove() 安全检查（它会核对 previous_object() 是否等于 SIMUL_EFUN_OB）——每一次经由那个覆写路由的物件销毁都会失败——具体表现为：每一个新玩家的 quit 都会失败，因为 quit 的自动丢弃背包逻辑会销毁任何不值钱的丢弃道具（每个新角色出生就带着一件）。这个 bug 很隐蔽：连线会打印一个被捕获的运行时错误、看起来像是断开了，但角色其实仍然在线，世界那一侧的连线从未真正关闭。已把宏指向真正的档案来修复（和之前某个 lib 里 securityd.lpc/securd.lpc 重复档案陷阱是同一种直觉——哪怕宏名字看起来"显然正确"，也要用 config.fluffos/真实调用链去验证它到底指向哪个文件）。另外修复了一份真正损坏的留言板存档（data/board/kedian_b.o 的某条留言作者字段里有原始的非 UTF-8 GBK 字节，导致每次在那个房间 look 都崩溃）——直接删除了这份损坏的存档档案，而不是冒险做局部字节级重新编码。管理员账号通过纯文本的 adm/etc/wizlist 档案播种。注册流程到进入游戏世界、look/score、以及一次正确完成的 quit 都已干净验证——建议在任何共享这种 SIMUL_EFUN_OB/重复 simul_efun 档案形态的档案上都专门重新测试一下 quit。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 18 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/single/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `!user->query("food") &&
   !user->query("water") && ob->query("age") == 14` 判断的
   `ob->query("age")` 拿的是登录阶段用完即弃的连线桩物件，永远没有
   `age` 这个属性，条件恒为假，每个新角色食物/饮水永远初始化成
   0。改成 `user->query("age") == 14`。live 测试确认：修复前注册
   `score` 食物/饮水两栏全空（□□□），修复后重连（这个判断在
   `enter_world()` 里每次登录都会重新求值，只要 `food`/`water` 仍
   是 0 就会补发）同一账号立即变满格（■■■）。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:176`、`u/wind/refereew.lpc:176`、
  `u/wind/refereew2.lpc:184` 均已用 `to_int(query("win_times")) %
  N`。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。
- **留言板存档括号计数怀疑（未采取行动）**：用简单的方括号/圆括号
  配对启发式扫描全部 `data/board/*.o`，`bonze_b`、`gaibang_b`、
  `gaibang_r`、`huashan_b`、`shaolin_b`、`taohua_b`、`towiz_b`、
  `wiz_b`、`wudang_b`、`xiaoy_b`、`xueshan_b` 共 11 份显示括号不配
  对（`kedian_b.o` 那份真正确认损坏的存档 WASM 阶段已经删除）。这
  个启发式本身不可靠（留言内容里出现的普通括号标点也会误报），本
  轮完整注册/look/score/重连流程没有触发任何一份的
  `restore_object()` 报错，`debug.log` 全程干净，没有实际证据证明
  这些是真损坏（不像 `xkx2017` 那批，有确认的存档头缺失+live 崩溃
  复现）。按"没有真实复现就不动"的纪律，本轮未删除任何一份，留给
  以后如果真的踩到崩溃再处理。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程创建，落地"客店"，`score` 显示"【天神】"
头衔。随后**单独一步**做了真实断线重连+密码验证：用刚设的密码重
新连线成功登录（顺带验证了 #3 的食物/饮水修复对已存在账号的自愈效
果）。全程 `debug.log` 无运行时错误。驱动按精确 PID 结束；管理员
存档已提交。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 791 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与 `jqxz2008`/
`jyqxc`/`xiakexing3` 系列同一血统同一形状。`clone/misc/
roommaker.lpc` 同样有两套模板——"造一间空房间"的 heredoc 本来干
净，"克隆我所在的房间"命令的字符串拼接模板把同一枚多余的
`replace_program(ROOM);` 烤进了每一个新克隆的房间，已同步修正。已
用 `build-debug` 驱动干净启动验证（0 个新增编译错误，端口正常监
听）；未做完整 §10.7 深度游玩测试。

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

## 深度功能测试（2026-09-01，round three，首次真正完整的 §10.7 深度游玩测试）

本轮之前，本档案唯一挂名"深度功能测试"的那一节实际只覆盖了注册/重
连和三个孤立 bug 修复的验证（见上面 2026-08-13 那节自己在末尾承认的
"此前只做过 WASM 阶段的注册流程验证"，且更早的 §7.86 扫描修复也明确
写着"未做完整 §10.7 深度游玩测试"）。本轮用一个全新角色（云飞扬 /
`yunfeiyang`）从零走完注册 → 移动 → 留言板 → 战斗 → 死亡/复活 → 拜师
的完整流程，是这份档案第一次真正的全流程 §10.7 测试。

### 发现并修复的 PROGRAMMING bug：3 份存档级损坏的留言板

2026-08-13 那轮曾用方括号配对启发式扫描出 11 份"疑似"损坏的留言
板存档，但因为没有真实复现，按"没有真实复现就不动"的纪律未采取行
动。本轮实际走到了其中两处并当场触发了真实崩溃，另一处经静态字节
分析确认是同一 bug 类：

1. **`/clone/board/gaibang_b`（丐帮弟子留言板，`/d/city/pomiao` 土地
   庙）**：玩家第一次真正走到这个房间（经 `dongmen`→`ml1..ml7` 迷宫
   路径）时，`restore_object(): Invalid utf8 string while restoring
   dbase` 从 `bboard.lpc` 的 `setup()`→`restore()` 未捕获地抛出，
   整个 `go`（进房间）命令失败，玩家被弹回上一个房间。字节级检查确
   认 `data/board/gaibang_b.o` 与 `raw/xkx/data/board/gaibang_b.o`
   完全字节一致（不是本项目引入的新损坏），整份文件是**从未转码过
   的原始 GBK**（`gb18030` 可以干净、完整地解码，也没有真正的
   `\r\n` 需要按引号感知规则折叠——文件里的换行全部是这份存档格式
   自带的裸 `\r`）。用与 AGENTS.md 里 `fy2`/`fy2qh` 那次相同的手法
   修复：整份文件按 `gb18030` 解码、重新编码为 UTF-8。live 验证：
   修复后重进该房间干净，`read 1` 能正确显示全部 5 条历史留言（含
   一处这类老式存档里常见的、原本就存在于归档里的终端转义符残留
   `[A[A`，原样保留未改动）。
2. **`/clone/board/towiz_b`（玩家意见留言板，`/d/wizard/guest_room`，
   武庙西北竹门内）**：同样的 `Invalid utf8 string` 崩溃，经
   `open door` → `northwest` 触发。但这份文件的损坏比 gaibang_b 更
   深一层，不是单纯未转码：字节级排查发现内容中间夹杂着大量原始
   ANSI 光标控制码（`\x1b[D`/`\x1b[C`——某个上古年代客户端在编辑留
   言、按方向键时被原样录了进去），其中一段控制码恰好插在一个双字
   节 GBK 字符的中间，把后面所有字符的双字节对齐全部冲散——
   `gb18030`/`gbk`/`big5` 全部无法完整解码整份文件，是真正字节级
   丢字节式的损坏，不是编码判断错误、也无法靠换编码挽救。按本档案
   早先处理 `kedian_b.o`（WASM 阶段，同样"不可恢复、宁可直接删除
   也不冒险做局部字节修补"）的先例，直接删除了这份存档。**踩坑一
   次**：只删了明文 `towiz_b.o`，重启驱动后同一个崩溃原样重现——
   原来 FluffOS 的 `restore_object()` 在明文 `.o` 不存在时会自动透
   明回退读取同名 `.o.gz`（这份存档恰好还留着一份 gzip 压缩备份
   `towiz_b.o.gz`，内容是同一份损坏数据），只删 `.o` 不删 `.o.gz`
   等于什么也没修。补删 `.o.gz` 后重启驱动再测，房间干净加载，留
   言板显示"没有任何留言"（预期中的空板）。
3. **`/clone/board/taohua_b`（桃花岛弟子留言板，`/d/taohua/dating`）**：
   **未做现场复现**（该房间需要额外的地图/渡海路线，超出本轮时间
   预算），但静态字节分析确认了与 towiz_b 完全相同性质的损坏：对
   比同一条留言里 `title` 字段与 `msg` 字段本应相同的前缀，可以看
   到 `msg` 字段中途缺失了至少一个字节，导致其后所有双字节 GBK 配
   对全部错位，`gb18030`/`gbk`/`big5` 均无法完整解码。该文件与
   `raw/` 归档原件字节级一致（非本项目引入），触发机制
   （`restore_object()` 遇到无效 UTF-8 时未捕获地抛出运行时错误）
   已经在另外两份文件上现场验证过两次，判定为同一 bug 类的第三个
   实例，直接应用了同样的"删除不可恢复存档"补救（这份没有 `.gz`
   备份需要额外处理）。

其余 8 份此前被方括号启发式误报的留言板（`bonze_b`、`huashan_b`、
`shaolin_b`、`wiz_b`、`wudang_b`、`xiaoy_b`、`xueshan_b`、
`gaibang_r`）经直接 UTF-8 有效性检查全部确认是**假警报**——本身就是
合法 UTF-8，之前的方括号计数启发式只是被留言正文里的普通括号标点
误导，未发现新问题，未做任何改动。至此，2026-08-13 那轮遗留的"11
份疑似损坏留言板"这个悬而未决的问题彻底关闭：3 份真损坏（已修
复），8 份假警报（确认无恙）。

### 验证过但确认无需修复（AGENTS.md §7.117 / §7.19）

- **`cmds/skill/bai.lpc` 的一处括号错位（AGENTS.md §7.117 "sj" 同款
  形状）**：`(string)me->query("family/master_id" == "feng
  qingyang")` 一行里 `==` 先于 `query()` 求值，等价于调用
  `query(0)`，如果真的走到这条分支会在 `feature/dbase.lpc` 的
  `strsrch(prop, '/')` 里因参数类型错误崩溃。但现场验证（用两个真
  实测试角色 `yunfeiyang`/`chengfeng`：`yunfeiyang` 对已在场的
  `chengfeng` 执行 `recruit chengfeng`，再让 `chengfeng` 执行
  `bai yunfeiyang`）证实这条分支在本档案里**彻底不可达**：
  `bai.lpc` 自己在更早处就有
  `if (userp(ob)) return notify_fail("现在不能拜玩家为师了。\n");`，
  玩家之间互相拜师被无条件挡住；这条括号错位的分支只有当师父是
  NPC 时才可能触发，而 NPC 自动收徒（`attempt_apprentice()` →
  `command("recruit ...")`）走的是 `recruit.lpc` 自己那条**已经正
  确加了 `me->query("family") &&` 首次收徒判空守卫**的完成分支
  （文件里 1995 年的注释 "fix a bug in 1st time recruit" 就是证
  据），根本不会让 `bai.lpc` 里那条括号错位的分支执行到。确认为
  死代码，按"只修真实可触发的 bug"纪律未改动。
- **§7.19 reentrancy 模式**：全档案搜索所有 `void/int init() { ...
  }` 函数体，没有一处调用 `setup()`/`enable_player()`/
  `enable_commands()`；唯一的 `enable_player()` 调用点在
  `inherit/char/char.lpc` 的 `setup()`（由 `create()` 触发，属于合
  法的一次性调用），没有从 `init()` 被间接触发的路径。确认本档案
  不受影响。

### 实测过程

全新账号 `yunfeiyang`（中文名"云飞扬"）走完注册流程，落地"客
店"，`score`/`look` 正常。在客店留言板 `post` 了一条测试留言，随
后 `read 1` 正确读回。经北大街→中央广场，主动 `kill liumang`（命中
的是"流氓头"，武功比新手玩家强得多），真实打到力竭、半昏迷、最
终"你死了"，`【谣言】` 死亡广播正常。死亡后被送进"鬼门关"，
`d/death/npc/wgargoyle.lpc` 的白无常走的是自动 5 阶段
`call_out("death_stage", 5, ...)` 对话链（不是 `d/death/inn1.lpc`
那条需要玩家主动 `ask <自己> about 回家` 的隐藏彩蛋路线——两条路都
存在，但真正的默认复活机制是白无常这条），约 25 秒后自动
`reincarnate()` 并把玩家扔到 `REVIVE_ROOM`（武庙），`score` 显示
"潜能"从 99 掉到 50（正确的死亡惩罚），称号重置为"平民"。随后走
完北大街→中央广场→东大街→东门→（青竹林迷宫）→土地庙的完整路
线，对丐帮九袋长老"鲁有脚"执行 `bai lu`，一次性被收为"丐帮第十
九代弟子"，`score` 正确显示新门派与师父。全程只在两处地图上第一
次探索到的留言板房间触发过运行时错误（已修复，见上），其余移动/
战斗/死亡/复活/拜师全程 `debug.log` 干净。驱动按精确 PID 结束并重
启验证过一次（确认两处崩溃彻底消失；唯一一次"删了 `.o` 还是崩"的
意外是漏删了 `towiz_b.o.gz` 压缩回退文件，补删后重启复测干净）。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-05）— 巫师留言板存档 `data/board/*.o.gz`

巫师留言板 `wiz_b` / `towiz_b` 以 `.o.gz` 存档（1996 年的帖子）。本机驱动 `restore_object()` 优先读 `.o.gz`，而留言板用 `save_object(file)` 写明文 `.o`，所以本机上新帖每次重启都退回旧快照；网页版驱动没有 zlib，只读 `.o`，而归档自带的 `.o` 是读不出的二进制。本库原有的明文 `wiz_b.o` 是更新的 22 条（1996-06 起），保留；`.gz` 里较早的 47 条（1996-02 起）转成 UTF-8 存为 `wiz_b.bak`，不被载入但保留下来。删除 `.o.gz`（KB 01）。用 lpcc 载入留言板核对条数（jqxz2008：wiz_b 47 条、towiz_b 115 条）。

## 深度功能测试（§10.7，2026-10-06）— 白驼山掌门欧阳锋编译不过

`d/baituo/ouyangfeng.lpc` 有两处笔误，整个 NPC 从未编译成功：`greeting()` 里 `write("你是谁？我要杀了你！哈￣哈￣哈￣") break;` 缺分号，`inquiry_map()` 里 `object me = this - player();`（应为 `this_player()`）。白驼山派的掌门因此不存在，拜师、问路（`inquiry_map`）都无从谈起。两处改正后，新进程里 HEAD 加载失败、工作树加载成功。同一文件在 14 个 xkx 系的库里一字不差。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

3 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/nanjiang2.lpc`、`d/xingxiu/nanjiang3.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`inherit/weapon/throwing.lpc`、`inherit/weapon/fork.lpc`、`inherit/weapon/whip.lpc`、`inherit/weapon/sword.lpc`、`inherit/weapon/weapon.lpc`、`inherit/weapon/axe.lpc`、等共 10 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xkxlb --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 217 个 `.lpc` 和 8 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：200 -> 200 通过，无回退；改过的头文件的 36 个包含者 34 -> 34 通过。启动时警告 13 -> 0；新进程登录（输入名字）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 13 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 11 个文件，HEAD 与工作树各载入一次无回退（11 objects; HEAD PASS 11, tree PASS 11; regress 0; newly loading 0），这些文件的警告 13 -> 0。

- 2026-10-10（续）：第二轮编译警告整理（`lpc_fix_unused_init.py`）删掉了只在不启用的 `#if` 分支里用到的局部变量声明（如 `include/net/ftpdsupp.h` 中 `#ifdef GUEST_WIZARD_FTP` 分支的 `file`），启用该选项时会编译失败；声明已放回所用的分支里，工具已改为跳过这种情况（交给 `lpc_move_decl.py`）。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 34 处）后，用 `scripts/lpc_twin_port.py adopt xiakexing3 xkxlb --pre fa4f24186c2~1` 搬来孪生库 xiakexing3 同日的修法（`kungfu/skill/hubo.lpc` 写明 `skill::clean_up()`，`include/net/ftpdconf.h` 改定义 `VALID_READ`/`VALID_WRITE` 前 `#undef`），再删去 `kungfu/skill/dugu-jiujian.lpc`、`huashan-jianfa.lpc` 招式表后面多余的一行 `;`，能编译的文件警告清零。改动的 36 个对象 HEAD 与工作树各载入一次：HEAD PASS 29，tree PASS 32，regress 0。新载入的 3 个是明教 `d/mingjiao/npc/yinwufu`、`yinwulu`、`yinwushou`：基类已有 `F_UNIQUE`，叶子再继承一次触发 `Illegal to redefine 'nomask' function 'violate_unique'`，从前载不进来。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：1 个存档文件（留言板 1 个；`data/board/tiandi_b.o`）还是原档案的 GBK 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后对象以空数据启动（表情守护进程没有表情、留言板没有帖子、玩家无法载入）。`scripts/lpc_save_encoding.py` 逐个按 GB18030 解码，结果按存档格式解析通过才写回（KB 03 §4）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：5 个对象，新增载入 4，回退 0。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。4 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 3 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。6 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`jiuyang-shengong`、`liumai-shenjian`、`taiji-shengong`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。7 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

11 个文件、15 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/xiaoyao/npc/obj/cloth`、`/d/xiaoyao/npc/obj/blade`、`/d/city/obj/tudao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 11 个（11 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`clone/npc/meng-zhu.lpc`、`cmds/arch/purge.lpc`、`cmds/usr/suicide.lpc`、`d/quanzhou/npc/tang.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`、`include/net/ftpdsupp.h`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`suicide` 是自杀指令；`purge` 是清除玩家档案的巫师指令；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：6 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 1 个对象设了本库没有文件的武功（4 个名字，最多的是 `xiake-force`、`xiake-strike`、`xiake-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：1 个里 0 个通过，其余 1 个停在别的错误上（`kungfu/class/xiake/master`：*No program in object '/kungfu/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/emei/duguangtai` 的 `north`：`huazangzn` → `huazangan`；`/d/emei/jietuopo` 的 `west`：`guanyitang` → `guanyintang`；`/d/emei/jiulaodong` 的 `northeast`：`jiudaoguai4` → `jidaoguai4`；`/d/mingjiao/jmqshulin6` 的 `west`：`jmqjiguan` → `jmqshenmu`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 4 处、3 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`d/heimuya/npc/laozhe.lpc`（黑木崖的老者）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_blade.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 1 个文件：`/d/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/mingjiao/shanmen.lpc`（1 处）。
