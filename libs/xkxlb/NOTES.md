
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
