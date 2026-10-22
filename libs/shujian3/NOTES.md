
## WASM 修复摘要（迁移自 meta.json 的 group_note）

从一个嵌套压缩包中提取（外层压缩包同时打包了一个 Android 客户端 apk 和这份 shujian3.zip 源码）；和 bxsj/bxsj1 及其他任何一个已有档案都没有 master 哈希匹配；原生启动干净，但 WASM 修复需要真正的修复：（1）logind.lpc 的 euid 重置（seteuid(getuid())→seteuid(ROOT_UID)），用于 create()/make_body()；（2）check_legal_name() 过时的 GBK 字节长度界限和字节步进循环，加上 is_chinese() 的 GBK 字节区间判断，都改成逐字符码点检查；（3）named.lpc 的字节步进封禁名字循环改成逐字符；（4）band.lpc 加上了标准的本地回环放行保护；（5）payd.lpc（HTTP 充值回调精灵）有 4 个函式无条件呼叫 socket_*（setup/store_client_info/listen_callback/close_connection），按整档入口点禁用方式掏空成 no-op；（6）一个真正存在、此前从未记录过的 securityd.lpc bug：valid_read() 无条件用 this_player() 覆盖驱动提供的 user 参数，而对于"load_object"/"include"这两种情形本应是 master_ob（root）——当一个刚连线的、无权限的新账号在场时，这会拒绝编译任何代码（包括 USER_OB 和每一个 #include），彻底阻断注册；已把这两个情形排除在覆盖之外来修复；（7）commandd.lpc 的 rehash() 里第二个真正的 bug：它的 sscanf 模式硬编码了转档之前的"%s.c$"后缀，永远匹配不到本项目改名后的"*.lpc"档案，导致 get_dir() 过滤出来的指令列表变成空的，每一个玩家指令（look/score/quit/任何指令）都会静默落到默认的"什么？"失败讯息——已改成"%s.lpc$"修复。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 条目播种（纯文本 wizlist 机制，标准的 XKX/ES2 血统 securityd.lpc）。自定义手机 App 协议：登录/注册用 id,password,ciphertext,email（逗号会自动替换成 U+2551 ║），角色创建用 gender║img║nickname（只认字面的 ║）；连线后不管输入什么都会无条件打印一次"ver1.0,<key>"+版本校验横幅。

## §10.7 深度功能测试（本次新增）

此前只有 WASM 修复阶段的注册流程验证，没有做过真正的深度玩法测试。本次
用自定义手机 App 协议（`账号,密码,密文,email` 逗号会自动替换成 ║；新号
接着发 `性别║图片║昵称`）通过原始 socket 脚本驱动，先后走了两条角色线：

- **fluffos（(admin) 权限，通过 wizlist 播种）**：注册 → 新手教程六步
  （`i`/`help new`/`hp`/`score`/`help newbie`/`help job`，每步都有明确的
  经验奖励提示）→ `goto` 到各类房间验证 admin 专用指令。
- **tester01（普通玩家）**：完整走了一遍同样的新手教程 → `ask shizhe
  about 新手训练/帮助/门派` 三段式拜师流程（"帮助"这一步会一次性把新号
  的六项基础技能拉到 50 级、内力精力封顶、送 3 天会员）→ 选择武当派，
  被"一阵狂风"传送到武当三清殿 → 在武当后山走廊/小径间移动，验证房间
  描述、出口列表、NPC 列表均正确。

### 战斗与死亡/复活

`kill muren`（武馆练武场的木人）被 `武馆内禁止杀人` 挡下——这是武馆区
显式的禁止 PK 设定，不是 bug。真正的战斗测试改用武当宗门自身的防御
机制触发：用 admin 账号 `goto tester01` 后 `kill tester01`，武当守卫
NPC 俞莲舟主动介入迎战入侵者（"大胆狂徒，竟敢在武当放肆！"），并成功
反杀了 admin 角色（气血 100→-1，"你吐了几口鲜血，在地上抽动了几下就
死了！"）。admin 死后被送到鬼门关系统，正确复活回巫师休息室（气血/精
神回到 1/1，逐步恢复中，无卡死）。

### 修复：d/death/gate.lpc 的 §7.68 复活软锁（新发现）

`run(object ob)` 在鬼魂进入鬼门关 1 秒后被 `call_out` 触发一次，原代码
`if (!ob || !present(ob, this_object())) return;` 把"鬼魂对象已经不存
在了"和"鬼魂此刻只是暂时不在这个房间里（延迟/换房间/网络卡顿）"两种
情况混为一谈，只要那一秒的判定点鬼魂碰巧不在场就永久放弃后续的黄泉引
导流程（送去 `gateway`/`mpting`/`pusadian`），把鬼魂永久卡在鬼门关。
按 AGENTS.md §7.68 的标准修法拆开：`!ob` 才是真正放弃，`!present` 则
改为 1 秒后重试，不再是一次性判定。这是本档案除 WASM 修复阶段那 7 处
之外，第一次在实际深度游玩中发现的新 bug。

### 排查但排除：CHARACTER 的 F_* 混入档缺 F_DBASE inherit（§7.78 结构相符，但未复现）

`inherit/char/char.lpc` 同一档案里直接 `inherit F_ATTACK/F_COMMAND/
F_DAMAGE/F_ATTRIBUTE/F_MOVE/F_NAME/F_TEAM/...` 以及 `F_DBASE` 本身，
而 `feature/{name,command,damage,attribute,move,team}.lpc` 这些混入档
自己都不 `inherit F_DBASE`，却在函式内部大量使用裸 `set()`/`query()`
——这和本项目在 NT/nitan 血统里连续confirmed 5 次的 §7.78 bug（bare
set/query 绑定到定义档自己的编译期继承图，而不是最终合并对象的）在
**文件结构上完全一致**，一度怀疑是第 6 个独立血统的实例（"// From ES2"
注释显示 shujian3 实际上是 ES2/XKX 血统的旁支，而不是 NT 血统）。

但直接验证结果是**这个 bug 在这份档案里没有复现**：
1. 先做了最直接的尝试性修复——给 `feature/name.lpc` 加
   `inherit F_DBASE;` 后用管理员 `update` 指令热编译，结果**编译成
   功**（这个引擎的 `dbase.lpc` 没有把 `set`/`query`/`dbase` 变量标记
   成 `nomask`，不会像 NT 血统那样直接编译报错）。但把同样的改动套到
   其余 5 个混入档、再热编译 `inherit/char/char.lpc` 时，boot.log 里
   出现了大量 `warning: Redeclaration of global variable 'dbase'`——
   说明这个引擎在同一继承图里对同一档案的多路径 inherit **不会去
   重复**，每个混入档会各自拿到一份独立的 `dbase`/`tmp_dbase` 变量，
   和 `char.lpc` 自己那份互不相通。也就是说"直接补 inherit"这个最直
   觉的修法在这里反而是错的，会制造出比原来更隐蔽的分裂存储。
2. 于是改用已验证过的 `this_object()->set(...)`/`this_object()-
   >query(...)` call_other 改法，在 6 个档案里全部替换完并热编译通
   过，正准备提交前做了一次决定性的实测：状态列（`012气血...`，每条
   指令后自动打印）由 `cmds/usr/hp1.lpc` 生成，它读的是
   `ob->query_entire_dbase()`——一次正常的、外部 call_other，读到的必
   然是 `char.lpc` 自己那份真正的 dbase。前面 admin 被俞莲舟打死的整
   个过程里，这条状态列全程正确跟踪气血从 100 掉到 -1，说明
   `feature/damage.lpc` 里那些裸 `set("eff_qi",...)`/`set("jing",...)`
   写入，**确实落到了 char.lpc 真正的 dbase 里**，不是某个不相干的
   simul_efun 兜底位置。admin 死而复活后重新登录，气血栏也正确保留在
   1/1（不是被静默重置）。这和 §7.78 已确认实例里"裸调用写歪了地方、
   跨档案读不到"的核心症状直接矛盾。
3. 结论：这份档案虽然在**静态文件结构**上和 §7.78 的坏形状一模一样
   （混入档没 inherit F_DBASE + 内部裸 set/query），但在**这个具体驱
   动编译单元的实际绑定行为**上没有复现该 bug——已把尝试性修改全部
   `git checkout` 撤销，未提交任何改动到这 6 个档案。这里留一个技术笔
   记：§7.78 的"裸调用绑定到定义档自己的编译期继承图"这个机制本身应该
   是驱动级别、和具体 lib 无关的通用行为，但同一份 F_* 混入档结构在不
   同 lib 之间为什么会有不同的运行时表现，目前没有查清楚（可能和某个
   编译期 pragma、或者这份代码里 `F_DBASE` 本身没有 nomask 保护有关，
   使得驱动在这个特定形状下选择了不同的绑定路径）——如果未来某次 deep
   test 在这份档案的其它混入档功能上发现数据"跨会话消失"的症状，应该
   回来复查这里，而不是想当然地认为已经排除。

### 其它已排查、确认不适用的已知 bug 类别

- §8.9（食物/饮水年龄检查错对象）：本档案 `init_new_player()` 直接把
  食物/饮水设成 200，没有这个基于年龄的错误对象检查，不适用。
- 除 `d/death/gate.lpc` 外，`d/death/npc/`（孟婆、阎罗、沙弥、菩萨等）
  和 `d/death/{mpting,pusadian,gateway}.lpc` 都没有用到
  `call_out()+present()` 这种一次性判定的组合，不需要修。

管理员账号 `fluffos` 存档（`data/{login,user}/f/fluffos.o`）本次测试
过程中首次真实生成并随本次提交一起入库（此前 wizlist 虽然已经列了这个
账号，但存档本身从未被创建过）。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。本档案登录走的是自定义手机 App 协议
（单行 `账号,密码,密文,email`，逗号自动替换成 ║，密文校验本身已被
源码注释掉），本轮沿用这一格式验证。标准检查清单发现并修复四处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `700000`（已知
   风险区间）提升到 `5000000`。
2. **`cmds/app/update.lpc`（AGENTS.md §7.106）**：缺少
   `environment(me) &&` 前置防护，补上（`cmds/imm/update.lpc` 已是正
   确写法）。
3. **`adm/simul_efun/file.lpc`**：`cat()` 补上 `read_file() || ""`
   空值防护（`log_file()` 委托给 `LOG_D`，未处理）。
4. **`clone/user/user.lpc::reconnect()`（AGENTS.md §7.108，第四条独
   立确认的血统——同 Century/书剑家族的 shiji、shujian2008 均命中过
   同一处）**：缺少 `enable_commands()`。按 §7.108 记录的写法预防性
   修复，现场验证：本档案的踢掉重复登录路径**不问 y/n，直接自动踢
   掉旧连线**（与 shiji/shujian2008 的确认式不同，但底层
   `exec(old_link, user)` 机制一致）——用两个真实连线复现"保持第一
   个连线不断开→第二个连线用同一账号登录"，第二个连线显示"重新连
   线完毕"后 `score` 立即正常输出完整角色资料卡，确认修复有效。

`master.lpc::log_error()` 的直接玩家广播已注释掉（改走 `CHANNEL_D`
的 `"err"` 频道广播，属频道订阅制、非无差别泄漏，判定非 bug，未
处理）；本档案无 `adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026,x,x` 登录确认
`您目前的权限是：(admin)`，`update /adm/daemons/logind` 成功验证真
实写入权限。踢掉重复登录重连路径现场验证通过（见上）。`debug.log`
全程干净（393 行，无真实错误）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/simul_efun/file.lpc`
- `work/cmds/app/update.lpc`
- `work/clone/user/user.lpc`

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Same lineage/shape as
sibling libs `bxsj`/`sjecl`/`sjtx2`/`shujian2008`, plus an additional
12-file `d/pk/turen*.lpc` cluster not present in those siblings: 36 live
`replace_program(ROOM);` occurrences deleted (`d/wanshou/*.lpc`,
`data/group/groom/*.lpc`, `d/cangzhou/dangpu.lpc`, `d/pk/turen*.lpc`).
No roommaker.lpc factory-bug variant. Verified via a clean native driver
boot (zero new `debug.log` errors, port listening, killed by exact PID
after ~8s).

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/death2.h` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

Note: the touched header here (`death2.h`) turned out to be dead/unreferenced code in this lib -- the live NPCs (`yanluo.lpc`/`mengpo.lpc`/`pusa.lpc`) actually `#include` a sibling `death.h`, which was already guarded from an earlier fix. This edit is a harmless no-op; no live vulnerability existed in this lib for this file.

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

## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()`: the shared
`inherit/char/char.lpc` `setup()` (called from every character's
`create()`) itself calls `enable_player()`, and `d/gb/npc/xixia-wushi.lpc`
redundantly calls `setup()` again from inside its own `init()` (on top
of the `setup()` its `create()` already made) -- same shape as the
originally-documented mhxy `zhangmen.lpc` case. `enable_commands()` is
only safe to call from `create()`: calling it again on an object
already `living()` makes the driver re-invoke that same object's
`init()` as a side effect, which recurses back into `enable_player()`
on the same call stack until "Too deep recursion" aborts the boot on
a room's first-ever visit. Fixed with a true reentrancy flag
(`in_enable_player_now`), NOT a `living()` guard (which would break
legitimate re-enables from `revive()` in `feature/damage.lpc` and
`wakeup()`/`wakeup2()` in `cmds/std/sleep.lpc`, both confirmed to
re-invoke `enable_player()` on this lib while the object is still
`living()`). Verified via `lpcc --batch` single-file compile check
(PASS). Part of the corpus-wide §7.19 sweep (Batch E).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py shujian3 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 574 个 `.lpc` 和 14 个 `.h`（多为删去未用的局部变量、`#pragma save_binary`）。HEAD 与工作树分别加载（新进程）：566 -> 566 通过，无回退；改过的头文件的 28 个包含者 27 -> 27 通过。
手改一处：`adm/daemons/logind.lpc` 登录时查新信件后的 `if (num > 0) { }`，原作者把里面的提示语注释掉了，只剩空的分支（编译警告 `Value of conditional expression is unused`）；把 `if` 也注释掉，行为不变。

启动时警告 26 -> 0；新进程连线行为与 HEAD 相同（本库走指间 MUD 协议，裸 telnet 输入名字得到“未知错误”，HEAD 亦然）。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 10 处比较、0 处去后缀（如 `d/xueshan/zanpugc.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 16 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 3 个，只在 #if 分支用的声明移进分支 0 个文件；改动 19 个文件，HEAD 与工作树各载入一次无回退（19 objects; HEAD PASS 19, tree PASS 19; regress 0; newly loading 0），这些文件的警告 19 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 编译警告收尾（2026-10-12）

先用 `scripts/lpc_twin_port.py adopt shujian2008 shujian3 --pre baa6caf453e~1` 搬来与 shujian2008 修前逐 token 相同的 23 个文件，再跑 `scripts/toolkit_fix.sh`（覆盖函数 11 个，冗余继承 1 处），其余按 shujian2008/bxsj 同样的改法手工补，能编译的文件警告清零。改动的 53 个对象 HEAD 与工作树各载入一次：HEAD PASS 53，tree PASS 53，regress 0。

- 13 个 NPC 自带的门派表与 `FIGHTER` 的 `str_menpai` 同名（叶子用自己的表定 `party`，`FIGHTER` 用它自己的），叶子这边改名 `npc_menpai`（与 bxsj/shujian2008 同名）。
- `d/city/npc/wushi.lpc` 的 `nick_first`/`nick_second` 与它 include 的 `skills_pfm.h` 里的两张表逐字相同（自己那份 `create_nick()` 已注释掉），删去叶子这份。
- `adm/daemons/huanjing2003/room_readygo_hj.lpc` 每个名字声明两次的写法合成一次；`cmds/usr/mygift*.lpc` 的 `?:` 类型；`d/village/npc/obj/robber.lpc` 的 `NAME_D` 前 `#undef`；`clone/pet/pet.lpc` 用 `lpc_name_winner.py` 写明 `clean_up()`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 18 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/d/mr/npc/murong-fu.lpc`（`bouns *=`）、`/kungfu/skill/force/qi.lpc`（`q *=`）、`/kungfu/skill/force/recover.lpc`（`q *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分）：`d/sld/seawar/seaward.lpc`（海战）里船速、风速、水流、炮弹的 `x = sin(...) * speed` 等 8 处写明 `to_int()`。坐标是整数格，行为不变；原先浮点修正脚本把列号落在 `sin(...)` 括号里的语句误当成条件里的赋值，没有处理，脚本已修正。改动的 9 个对象 HEAD 与工作树各载入一次，无回退。

- 2026-10-14：`d/tanggu/biwuleitai.lpc`（比武擂台）`message_vision(HIRNOR "\n", …)` 把两个颜色宏写连了，整份不编译；改为 `HIR NOR`。现在载入。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/fanchang`、`/kungfu/skill/hujia-daofa`、`/kungfu/skill/huntian-qigong/huntian`、`/kungfu/skill/lanhua-shou`、`/kungfu/skill/longxiang-boruo/fanchang`、`/kungfu/skill/yiyang-zhi`。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。11 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-shengong`、`yunlong-zhua`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinshe-zhang`→`jinshe-zhangfa`（`jinshe-jianfa/kuangwu`、`kuangwu`）；`qimen_baguazhen`→`qimen-baguazhen`（`suibo-zhuliu/wuzhuan`）；`xixing-dafa`→`xixin-dafa`（`tianlong-shengong`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuantia-wuji`→`xuantian-wuji`（`xuantian-wuji/wuji`）。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## npc_setup 的浮点截断警告（2026-10-15，KB 04 §6.10）

`/clone/obj/npc_setup.lpc`：`level = pow(10 * exp, 0.333334);` 把浮点数隐式截成整数，编译时警告；改为 `to_int(...)`，结果不变。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

2 个文件、2 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/obj/blade`、`/u/lius/wudang/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 2 个，改后 3 个，没有退步。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（22 个名字，最多的是 `kick`、`liangyi-dao`、`pishi-poyu`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 1 个通过，其余 1 个停在别的错误上（`clone/obj/npc_setup`：*No program in object '/clone/obj/npc_setup'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/fuzhou/nanmen` 的 `south`：`birdge` → `bridge`；`/d/shaolin/nanyang` 的 `south`：`yidao2` → `hanshui2`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 35 处、35 个文件：`shaolin-shnfa`→`shaolin-shenfa`（14 处）、`kunlun-shnfa`→`kunlun-shenfa`（11 处）、`yijinjing`→`yijin-jing`（2 处）、`guiyuan-tuanfa`→`guiyuan-tunafa`（2 处）、`banrou-zhang`→`banruo-zhang`（2 处）、`qinmang-jian`→`qingmang-jian`（1 处）、`huashen-shenfa`→`huashan-shenfa`（1 处）、`weiituo-gun`→`weituo-gun`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `SHOP_DIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/shaolin/npc/xuan-du.lpc` 的 `#include "/u/hunthu/npc/xuan-du.h"` 改成 `/kungfu/class/shaolin/xuan-du.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/inherit/weapon/weapon_combo`←sje：2/2 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西都会吃掉鱼油。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/food/yuyou.lpc`（4 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/clone/npc/mj.lpc`（3 处）、`/cmds/group/glist_new.lpc`（2 处）、`/d/city/npc/budai.lpc`（1 处）、`/d/city/obj/budai.lpc`（1 处）、`/d/sld/npc/stt.lpc`（1 处）、`/d/sld/sanpo7.lpc`（1 处）、`/kungfu/skill/qiankun-danuoyi.lpc`（7 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 峨嵋 `d/emei/npc/jing-xin.lpc` 找不到 `nigu.h`，静心师太加载不了（2026-10-20，KB 04 §6.24）

这个 NPC 是 `kungfu/class/emei/jing-xin.lpc` 的副本（文件头注释还写着原来的路径），`#include "nigu.h"` 却没有跟着改：`nigu.h` 只在 `kungfu/class/emei/` 里，`d/emei/npc/` 下没有，所以静心师太从来加载不了（登录调查的游戏阶段控制台 5 次 `/d/emei/npc/jing-xin.lpc:5: error: Cannot #include nigu.h`）。改成绝对路径 `#include "/kungfu/class/emei/nigu.h"`，不复制头文件（两份会各自漂移）。加载检查：HEAD 0 通过 / 1 失败，工作树 1 通过，无退化。同一家族的六个库（bxsj、bxsj1、shujian2008、shujian3、sjecl、sjtx2）是同一处。

## `exchange` 指令：数据库结果还没检查大小就取下标（2026-10-20，KB 06 §7.324）

`cmds/usr/exchange.lpc` 的 `Update_Credit()` 在声明里就读 `ret[0][0]`，下一条语句才检查 `sizeof(ret) == 1`：博物馆没有 MySQL，`dbquery()` 返回空数组，每次敲 `exchange` 都是 `*Array index out of bounds.`（指令扫描里的裸指令）。改成 `int credit = (sizeof(ret) == 1 && sizeof(ret[0])) ? ret[0][0] : 0;`。实测：`exchange` 显示 `您目前可用书剑通宝为：零个……`，`exchange gold` 显示用法，控制台无报错。同一份文件在 bxsj、bxsj1、shujian2008、shujian3、sjecl、sjtx2 六个库里逐字节相同。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `bwscore`：比武大会的广场房间档案里没有（2026-10-21，KB 06 §7.299）

玩家指令 `bwscore`（`cmds/usr/bwscore.lpc`）不带参数时打印 `/d/bwdh/sjsz/square.lpc` 的描述，本库没有 `d/bwdh`（只有 xkm、xkx2000zxb、shenzhou 带着），`new()` 答 0，`0->long_desc()` 就是玩家看到的系统错误。改成 `(square ? square->long_desc() : "")`，用法提示照常。

## 苗疆山谷 `shangu1`：第二条蛇写成了 `jinshe = new(..yinshe)`（2026-10-21，KB 06 §7.346）

烧灵芝兰（`do_shao`）引出两条蛇：`jinshe = new(__DIR__ "npc/jinshe"); jinshe = new(__DIR__ "npc/yinshe");`，第二句把第一条覆盖了，`yinshe` 一直是 0，后面的 `yinshe->move(...)` 抛错。第二句改成 `yinshe = new(...)`（sje、jym 的同一份文件是对的）。

## 张三丰 `ask_me_6`：`who->query("id")`（2026-10-21，KB 06 §7.348）

非武当弟子问“太极道袍”时先 `command("shake " + (string)who->query("id"))`，`who` 声明了没赋值，应是 `this_player()`；抛错在拒绝的 `say` 之前，什么也说不出来。改成 `this_player()`，去掉 `who`。改动：`/kungfu/skill/zhang.lpc`。

## 保护任务的商人 `clone/obj/job/job_protect_npc.lpc`：两处笔误让整个文件从来没编译过（2026-10-21，KB 04 §6.29）

`clone/obj/job/protect.h`（保护商人的任务）克隆这个 NPC，但文件有两处笔误：`int baohu(string age)` 的函数体用的是 `arg`（`Undefined variable 'arg'`），而 `init()` 登记的是 `do_baohu`，函数名也对不上；`query->("id")` 多了一个 `->`。改成 `int do_baohu(string arg)` 和 `query("id")`（`if (!player = find_player(...))` 报的 `Illegal LHS` 只是前面语法错误引出来的连锁错误，这种写法本身是对的，没有动）；文件第一次能编译后带出 7 个 `Unused local variable` 警告（`sacrifice`、`exp_rate`、`skill_rate`、`lmt`、`menpai`、`killer`、`kill_num`），按 KB 04 §6.10 删掉。`baohu` / `protect` 两个动词现在有处理函数，任务的商人也第一次能出现。改动：`/clone/obj/job/job_protect_npc.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 23 条注册（17 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/daemons/robot-judge.lpc`（`do_test`）、`/clone/zhi/tiechui.lpc`（`do_ttt`）、`/d/city/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/dali/wuliang/muwu1.lpc`（`do_tiao`）、`/d/huanghe/npc/mafu.lpc`（`do_rideyz`）、`/d/huashan/jinshe/obj/haigu.lpc`（`do_move`）、`/d/huashan/npc/mu_renqing.lpc`（`do_go`）、`/d/huashan/npc/yaba.lpc`（`do_follow`、`do_kill`）、`/d/mr/obj/chahua3.lpc`（`do_chu`）、`/d/plummanor/hall.lpc`（`do_answer`） 等共 17 个文件。最多的函数名：`do_ttt` 2 处、`do_go` 2 处、`do_answer` 2 处、`do_learn` 2 处、`do_test` 1 处。没有动（读过）：`/clone/obj/job/job_protect_npc.lpc` 的 `do_baohu`（对象本身编译不过，登记留着，等对象能加载再处理）、`/cmds/leitai/dzd/dzd_flag.lpc` 的 `do_check`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/dali/yideng/npc/yuren.lpc`（`__DIR__ "../obj/boat"` → `"/d/dali/yideng/obj/boat"`）, `/d/dali/yideng/npc/yuren.lpc`（`__DIR__ "../obj/jiang"` → `"/d/dali/yideng/obj/jiang"`）, `/d/lanzhou/npc/chen.lpc`（`__DIR__ "../obj/jiuyin-book2"` → `"/d/lanzhou/obj/jiuyin-book2"`）, `/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← fengyun434：`check_control()`（2 处调用）、`check_length()`（9 处调用）、`check_return()`（2 处调用）、`check_space()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（inquiry 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/mr/npc/fu.lpc`:`ask_dan1`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 2 行只含这个指针的行（`"合修": (: ask_for_test :),` `"玉露清新散": (: ask_dan1 :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。
