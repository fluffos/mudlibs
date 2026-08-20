
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
