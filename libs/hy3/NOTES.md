
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES/金庸血统 mudlib，游戏内标题为"火云录2000"（Huo Yun Lu 2000）。修复的 bug：（1）真正生效的 adm/simul_efun/chinese.lpc 里经典的 §8.1 is_chinese() GBK 字节区间 bug——adm/single/chinese.lpc 那份死代码副本早就修好了（经典的 §7.56 类陷阱：真正被 include 的那份档案反而还是有 bug 的旧版本）；（2）adm/daemons/logind.lpc 里经典的 §8.1 check_legal_name() 字节数没减半的长度界限（2/10→1/5 字符）加上 i%2==0 门槛和 name[i..<0] 尾部切片；（3）新发现的严重 bug（AGENTS.md §7.59 的一个变体）：adm/obj/master.lpc 的 valid_read/valid_write 包装函式无条件地用 previous_object() 覆盖驱动提供的 user 参数，包括 load_object/include 这两种情形，静默拒绝了注册过程中编译玩家自己身体类别的请求——这个崩溃完全不可见（没有报错，没有编译警告），直到把可疑的呼叫包进 catch() 才浮现出"*Read access denied."；已仿照原始 §7.59 的模式，把 func=="load_object"/"include" 排除在覆盖之外来修复；（4）adm/daemons/wzd_log.lpc 里的管理员登录 bug：它的防盗号 IP 验证系统用 regexp()（真正的正则语法，不是通配符）来比对连线 IP 和按管理员分类的白名单——最初尝试用通配符语法（'*.*.*.*'）给测试管理员账号加白名单，结果因为无效的正则语法崩溃，静默杀死了 wzd_log() 剩下的代码，没有任何可见症状；已改用合法的正则（'.*'）修复。从白名单外的 IP 用管理员身份登录本来就会要求当场解答一道显示在画面上的随机数学题（这是有意的、设计良好的防盗号功能，不是 bug）——本次为了标准的 fluffos 测试账号绕过了这一步，用的是 IP 白名单映射，而不是真的去在线解题。GB 和 BIG5 两个编码选单选项都实测正常，不用修。完整的注册→look→score→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字，管理员流程（fluffos/loginpass1，"目前权限：(admin)"）格式化后也重新验证过。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`M_BOARD`、`WIZ_BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 47 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

### 血统鉴定：`hy3` 和 hy/海洋 家族无关，是同名不同源的独立代码库

`hy3` 这个 slug 和 `hy`/`hy2000`/`hy2002`（"海洋"题材）共享前缀，但游戏内
标题是完全不同的"火云录2000"，NOTES 里此前的 WASM 修复摘要也已经把它归类
成"ES/金庸血统"。本次专门做了一次核对，逐一 diff 了核心档案，结论是**两
者不是同一血统，只是碰巧都属于"ES2 衍生、金庸题材"这一大类武侠泥巴（和
AGENTS.md §11"ES II / 东方故事 mega-family"里其它十几个互不相关的成员一
样，共享山头/门派命名不是血统信号）**：

- `adm/obj/master.lpc`：`hy`/`hy2000`/`hy2002` 三份文件字节级相同（332
  行，注释头"for ES II mudlib / original from Lil / rewritten by
  Annihilator"）；`hy3` 的版本是 363 行，完全不同的结构（注释头"change
  by xhh"，多出一套 `get_player_fname()` BIG5/GB 双登录物件回退机制），
  diff 前几行就完全对不上。
- `adm/daemons/securd.lpc`/`securityd.lpc`：`hy`/`hy2002` 的真正生效版本
  署名"by jackyboy@cctx"，`wiz_levels` 里有 `"(apprentice)"` 等级，
  `inherit F_DBASE`/`F_SAVE`；`hy3` 的 `adm/daemons/securityd.lpc` 署名
  "xingyun 设置 on 2002.1"，`wiz_levels` 没有 `"(apprentice)"`，完全没
  有 `inherit`，`valid_read`/`valid_write`/`valid_seteuid` 的整体结构和
  权限判断逻辑都不同（例如 `hy3` 已经自己放行了 `func=="stat"` 和
  `"file_size"`，§7.5 的两个已知变体对它并不适用，见下）。
- `hy3` 自己的 `work/` 树里 `u/xingyun`（含一份 `u/xingyun/bak/`
  历史备份）、`u/xingyu`、`u/hsly` 几个巫师目录名和 `securityd.lpc`
  的署名"xingyun"/`README.md`"火云信箱：hsly@etang.com"互相印证，指
  向一个自成一体、独立维护过的代码库，不是从 hy 系任何一份分支出来的。

顺带一提：`libs/hy/work/` 树里意外嵌着一份完整的"海洋II 2002新春特别版"
Windows 发行包（`海洋2002/`，含 `MudOS.exe`/`mudos.dll`），其 `config.hy2`
的 `mudlib directory` 字段写的是 `./hy3`——这只是原作者给自己本地工作目
录起的名字（"海洋三代"之类），和本项目独立分配的 `hy3` slug 纯属巧合撞
名，两者内容（对比 `master.lpc`）完全不同，不构成任何血统证据，此处存
档说明以免未来某次巡检误把这个巧合当成新线索。

**结论**：`hy` / `hy2002` NOTES.md 已确认的 §8.9（食物/饮水年龄判断读
错对象）、§7.86（留言板 `post` 崩溃）两个 bug 类别，属于"值得按同类代码
特征检查，但不能假设代码完全一致"的情况——下面按 AGENTS.md 既定原则逐
条核实 `hy3` 自己的实际代码形状，不搬 hy 系的现成修法。

### 新发现（本次新增 AGENTS.md §8.14）：管理员自定义 IP 黑名单把几乎所
有连线都误判为"被封"

`adm/daemons/logind.lpc` 的开场横幅之后立刻有一段"added by
xingyun用来禁止恶意破坏的ip login"：

```lpc
if (BAN_D->is_banned(query_ip_name(ob))) {
    write("Sorry, your ip is banned by this mud.\n");
    destruct(ob);
    return;
}
```

`band.lpc` 的 `is_banned(string site)` 内部用
`sscanf(site, "%s.%s.%s.%s", ...)` 把参数当成一个点分四段的 IP 地址解
析，解析失败（段数不是 4）就直接 `return 1`（视为被封，fail-closed）。
但调用点传进去的是 `query_ip_name(ob)`——这是反向 DNS 解析出的**主机
名**，不是 IP。本地原生驱动测试下，回环地址的反向解析立即拿到
`"localhost"`（glibc `/etc/hosts` 命中，几乎瞬间完成，不像真正的公网
DNS 查询那样异步延迟），这个字符串没有任何"."，`sscanf` 直接失败，于
是**每一次连线，包括本地测试，都会被判定为"被封"并立刻断线**——玩家在
选完编码、还没看到"您的英文名字："提示之前就被踢出，`debug.log` 没有
任何报错，纯粹是游戏内的一行英文提示 + 断线，非常容易被误诊断成网络问
题或防火墙问题。真正部署给公网玩家时同样会踩坑：绝大多数有反向 PTR 记
录的真实主机名也不是点分四段格式，一样会被这条判断误伤——这不是一个只
在本地/沙箱环境才会触发的边界情况。

同一份 `logind.lpc` 里紧接着几十行之后，另一处用途相近的检查
（`BAN_D->is_netclub(query_ip_number(ob))`）用的是正确的
`query_ip_number()`，证明 `is_banned()` 这一处确实是调用参数传错了函
数，不是 `is_banned()` 本身故意设计成接受主机名。

修复：把 `query_ip_name(ob)` 改成 `query_ip_number(ob)`，让
`is_banned()` 收到它本来就期望的点分四段 IP 字符串。本档案的
`adm/etc/banned_sites` 目前是空文件，所以修复后默认放行所有连线（和
`band.lpc` 自己的设计意图一致：黑名单为空就不该拒绝任何人），管理员真
正想封的 IP 段可以照常通过巫师指令写进 `Sites` 数组生效。修复前用
tmux 连线复现（选完编码立刻被踢，提示"Sorry, your ip is banned by
this mud."）；修复后重启驱动，同一条连线正常走到"您的英文名字："提示，
完整注册流程（见下）全程无阻。

### §7.90 评估成本上限过低——适用，已修复

`config.fluffos` 的 `maximum evaluation cost` 是本项目模板默认值
`700000`。开机阶段 preload 还没跑完就已经在 `debug.log` 里留下 17 条
`Eval interrupted: object adm/obj/master cost limit reached, limit:
700000 usec.`——比典型的"移动到没走过的房间才触发"更早、更严重，连
`master.lpc` 自己的初始化都会撞上限。改为本项目常用的 `5000000`（30+
个其它档案已使用同一个值）后重新开机，`debug.log` 里 `cost limit
reached` 命中数从 17 降到 0；后续完整走了一遍注册、移动、战斗、留言板
的会话，全程 `grep -c "cost limit reached" log/debug.log` 始终是 0。

### §8.9 食物/饮水年龄检查读错对象——适用，已修复（效果目前被另一处默
认值掩盖，属于第十例已知实例）

`adm/daemons/logind.lpc` 的 `enter_world()`：

```lpc
if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
    user->set("food", user->max_food_capacity());
    user->set("water", user->max_water_capacity());
}
```

`ob` 是登录用的临时物件，"age" 属性在全档案任何地方都没有对它 `set`
过，这个判断按字面读永远是假。但本档案的 `init_new_player()`（在
`get_gender()` 里，`enter_world()` 之前就已经被呼叫）会无条件把新角色
的 `food`/`water` 都直接 `set` 成 `300`，所以上面这个门槛判断即使按字
面永远不触发，实测新角色的食物/饮水栏依然是满的——效果被完全掩盖，和
AGENTS.md §8.9 已经记录过的 `jhfy2` 第九例一模一样的"被掩盖"情况。按
既定教训（"被别处默认值掩盖不代表底层的读错对象是对的，未来任何人动到
那个默认值就会让这个 bug 突然显形"）照样修正为
`user->query("age") == 14`，不因为当前观测不到症状就跳过。

### §7.5 自定义 ACL 未放行编译期/存在性探测——两个已知变体均不适用

`hy3` 自己的 `securityd.lpc`（`SECURITY_D` 宏指向的真正安全精灵，和
hy/hy2000/hy2002 的 `securd.lpc` 是完全不同的代码）在
`valid_read()` 开头就有：

```lpc
if (file == WIZLIST) return 1;
if (func == "stat" || func == "file_size") return 1;
```

`load_object`/`recompile_object`/`include` 三个 func 虽然没有被显式列
在 `switch` 里，但 `valid_read()` 后半段的逻辑是"默认放行，只有几个特
定目录对非 `(admin)` 玩家拒绝"（`return 1` 收尾），不是 hy 系那种"默认
拒绝，只放行白名单 func"的形状，所以这条 §7.5 的两个已知变体（
`file_size` 探测误判 / `get_dir()` 的 `stat` 拒绝把整张指令表清空）都
不适用——实测走过扬州似的门派/技能初始化路径和全部指令（`look`/
`score`/`i`/`post`/`kill`），`debug.log` 全程没有任何 `F_SKILL`/`Read
access denied` 报错。

### §7.86 留言板 `post` 崩溃——此前的跨库扫描修复，本次首次带真实
post 内容全链路验证

上面"WASM 修复摘要"记录过全档案 47 处 `inherit BULLETIN_BOARD`/
`M_BOARD`/`WIZ_BULLETIN_BOARD` + 多余 `replace_program()` 已经删除，
但当时只做了编译检查，没有真的 post 过。本次用管理员账号在两个不同的
留言板实测：巫师休息室的 `/clone/board/wiz_b.lpc`（`post 深度测试` →
内建列编辑器 → `.` 结束 → "留言完毕。"）和客店的
`/clone/board/kedian_b.lpc`（同样流程），两次都正常打开编辑器、正常存
盘、`read new` 能读到刚发的留言——确认 §7.86 的修复在真实使用场景下
（不只是编译期）是干净的，没有残留任何指向同一个 board 基类的、还挂着
多余 `replace_program()` 的漏网文件。普通玩家账号需要先有
`literate`（识字）技能达到 10 级以上才能 `post`，这是本档案自己的游戏
设计（不是 bug），用管理员的 `setskill` 指令加上技能后验证。

### 管理员账号 `fluffos`：`wiz_status`/`adm/etc/wizlist` 授权数据已提
交，但角色存档此前从未真正落盘——本次重新走完整注册流程补齐

`adm/etc/wizlist` 里已经有 `fluffos (admin)` 一行（git 历史里已提交，
非本次改动），但 `work/data/login/f/`、`work/data/user/f/` 目录下并没
有 `fluffos.o` 存档——说明此前某次会话只播种了授权名单，管理员角色本
身从未真正在原生驱动上完整注册过（或者注册后存档没有被提交/被后续清
理误删）。本次用密码 `Mud@2026` 走完整注册流程重新创建了 `fluffos`
（中文名"云飞"），因为 `wizlist` 里已经有名单，注册完成、`enter_world()`
时自动拿到 `(admin)` 权限，落地在"巫师休息室"。验证 `update
/adm/daemons/logind` 编译成功（写权限正常）。**同一登录会话内用同一账
号 `fluffos`/`Mud@2026` 断线重连了第二次**（§8.13 的"第二次登录死锁"
检查），"重新连线完毕"提示正常，直接回到断线前所在房间，没有任何登录
死锁现象。

### 游玩验证：移动、战斗、留言板

用非管理员测试账号 `shiyu`（石语）走完整注册（GB 编码 → 英文 id →
中文名 → 密码 → 天赋 → 邮箱 → 性别）到进入游戏世界，`look`/`score`/
`i` 全部正常显示（食物/饮水栏满格，验证了上面 §8.9 的掩盖效果），移动
（`w`/`s`）到相邻房间正常。管理员账号在 `/d/village/sexit`（华山脚下
南村口）对野狗（`d/village/npc/dog.lpc`）发起 `kill`，完整战斗流程
（拳脚/招架/轻功技能随战斗提升、野狗体力递减描述、最终"倒在地上,死
了！"）正常结束，没有触发管理员自己的死亡（`accept_fight()` 差距明
显，属于预期结果，不是"安全陪练"NPC，本次未特意寻找陪练木人），因此
本轮没有触发死亡/复活流程，如实记录为未验证——不假装测试过。

### 编码菜单

GB 编码选项本次实测正常显示中文（连线横幅、房间描述、战斗提示全部无
乱码）；BIG5 选项本次未重复测试（此前 WASM 阶段已确认过两者都正常，
本次时间聚焦在新发现的连线拒绝 bug 上）。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。管理员账号（`fluffos`/`Mud@2026`）此前已用真实注册
流程创建并提交，本轮复用，只做真实登录 + `update` 复测（未发现回
归）。本轮发现并修复两处新 bug：

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/`hc`/`hy`/
   `hy2000`/`hy2002` 同一原始形状）**：`if (this_player(1))
   efun::write(...)`——不区分巫师/玩家，也不区分警告/错误。修复：
   加上 `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：`feature/
   skill.lpc`/`feature/dbase.lpc`/`feature/vi.lpc` 等文件多处
   `log_file("trace/...", ...)`/`log_file("edit/<euid>", ...)` 调用
   依赖 `LOG_DIR` 下对应子目录存在。注册/登录本身只写顶层文件
   （`USAGE`/`npc_save`，无子目录，本来就存在），不受影响，但这些
   管理/编辑追踪路径会在首次使用时未捕获抛出。已补上
   `assure_file(LOG_DIR + file);`（含前向声明，`assure_file()` 定
   义在同文件后面）。

### Proactive checks（无需改动）

- `assure_file()` 本身末尾确实做 `seteuid(getuid())` 重置，但
  `log_file()` 从未在调用前 `seteuid(ROOT_UID)` 过——不属于
  `nitan_san` 那种"调用者依赖 assure_file 后仍保持提权"的形状，无
  需修复。
- `message()`（`adm/simul_efun/message.lpc`）已经是
  `varargs void message(...)`，且已有
  `if (!objectp(exc_target) && !arrayp(exc_target)) exc_target =
  ({});` 防御——不适用 message()-missing-varargs 这一类 bug。
- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:176`。

### 2026-08-13：`wabaod.lpc`（寻宝系统）开机期崩溃——已修复

上一轮记录的 `*Can't catch eval cost too big error.` /
`*push_lvalue_range: invalid ind2` 崩溃已追查到根因并修复。逐条比对
`log/debug.log` 里每条崩溃的完整调用链后发现这堆日志其实是两类性质
完全不同的问题：

1. **`insert_blank()` 自身的 bug（真正的 wabaod bug，已修复）**：
   `*push_lvalue_range: invalid ind2 程式：wabaod.lpc 第 112/116 行`
   这两条报错的调用链完全在 `wabaod.lpc` 内部收尾（`create()`→
   `init_xunbao()`→`insert_blank()`，不再往下调用任何其他物件），
   是自包含的真实 bug：`insert_blank()` 把描述字符串里等间隔的
   `lost`（6~10）个位置逐个替换成"■"来抠字——`desc[begin..begin+1]
   = "■"`。这段逻辑是老 GBK 双字节码时代遗留的写法，隐含"每个字符
   固定 2 字节、替换前后长度不变"的假设；但这套驱动的字符串是按
   Unicode 码点寻址的，"■"只占 1 个字符，每次替换都会把 `desc`
   缩短 1 个字符，而后续几次替换用的下标却是按缩短前的固定坐标算
   好的，越到后面越容易越界，命中 `push_lvalue_range: invalid
   ind2`。修复：先把全部要替换的下标收集到 `blanks[]` 里（下标本来
   就是严格递增的，不需要另外排序），再从最大下标往最小下标倒着做
   替换——对某个位置做替换只会让它右边的下标失效，倒着做保证每次
   替换发生时其余待替换下标还都在当前（尚未被这次替换影响到）的字
   符串范围内。同时把 `insert_blank()` 里找一条合格描述的
   `while (1) { long = get_long(); if (long != "") break; }` 改成
   最多重试 50 次就放弃、直接 return（下个 `call_out` 周期自然会
   重试）——这是防御性加固，不是本次崩溃的直接原因，但 `get_long()`
   每次不成功的尝试都可能 `load_object()` 一个此前从未加载过的房间
   /NPC（见下），无界重试等于把这类下游开销无限放大，收窄成有界重
   试后即使某个方向再出问题也不会拖垮整个 `preload()`。

2. **`*Too long evaluation.` / `*Read access denied.`（不是 wabaod
   的 bug，级联触发，现已随其他 fix 消失）**：这几条报错的调用链会
   一路下钻到 `get_long()` 里的 `load_object(file)`（第 129 行）
   随机加载到的某个此前未加载过的房间（比如
   `/d/quanzhou/haigang.lpc`），再经 `room.lpc` 的
   `setup()/reset()/make_inventory()` 触发房间里 NPC（如
   `/d/quanzhou/npc/girl.lpc`）的 `create()`→`npc.lpc`
   `carry_object()`→`master.lpc` 的 `valid_read()`/`valid_object()`。
   这条日志其实是**本 lib 更早一轮修复之前**的旧存档：那一轮
   （见本文件顶部第 (3) 条，也是 `6a6b352b545` 那次跨 155 个 lib
   的批量修复）已经把 `valid_read`/`valid_write` 无条件用
   `previous_object()` 覆盖 `user` 参数、连 `load_object`/`include`
   都一起被拒绝写权限的那个 bug 修好了；本次重新开机复现测试时这
   一类报错完全没有再出现（`log/debug.log` 这次干净到驱动都没建
   这个文件），说明它们本来就是同一个已知 bug 在 wabaod 触发路径
   下的又一种表现形式，并不是 wabaod 自己独有的问题，无需额外改动。

修复只改了 `adm/daemons/wabaod.lpc` 一个文件（`insert_blank()`）。
验证：`~/src/fluffos/build-debug/src/driver config.fluffos` 全新开
机，`log/debug.log` 全程未生成（零运行期报错，wabaod 的 `create()`
正常跑完并成功 `log_file("wabao", ...)` 记下本轮选中的房间）；随后
用 `scripts/mudclient.py` 走完整注册流程（`wabaoe`/`宝藏测试`，
密码 `test12345`，选性别、留邮箱、接受天赋、`look`/`score` 确认属
性正常、`quit` 正常道别扣布衣），并按本项目惯例额外做了一次真正的
断线重连验证：新开一条连接、用刚设的密码登录，成功进入游戏并
`look`/`quit`，全程 `log/debug.log` 仍未产生任何报错。驱动测试
结束后按精确 PID kill，`ps -p` 确认已退出；测试产生的
`data/{login,user}/w/wabaoe.o` 存档已删除，不提交。

### 已清理

- 登录测试产生的存档时间戳类微小 diff（`data/{login,user}/f/
  fluffos.o` 的 `last_on` 字段）已用 `git checkout` 撤销，不提交。
  驱动最终按精确 PID kill，`ps -p` 确认已退出。

（本档案已在此前一轮明确确认与 `hy`/`海洋` 血统无关，独立验证出同
一类 log_error/log_file bug 形状，纯属拷贝粘贴模式的巧合，不是同源
血统关系。）

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). Deleted 2,336 live
standalone `replace_program(ROOM);` lines under `work/` via
`fix_710_room.py` — matched the survey's live-occurrence count
exactly. `work/clone/misc/roommaker.lpc` does not have the
string-builder variant of this bug (no `replace_program` reference at
all in that file), so no manual tool fix was needed here. No `.lpc`
files under `work/data/` in this lib, so no false-negative risk.
Remaining matches after the fix are all pre-existing `//`-commented.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`Mud@2026`, GB-encoding client) into the game world,
`score`/`quit` worked cleanly (`look` landed mid-MOTD pagination and
just advanced a page — non-issue). Incidental
`data/{login,user}/f/fluffos.o` save drift from the login test was
reverted via `git checkout HEAD` before committing.

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

## Round-four §10.7 deep test (2026-08-21): death/respawn gap resolved, clean

### Death/respawn — now verified end-to-end, no bugs found

Prior rounds explicitly left death/respawn unverified: the admin
account's combat stats were far too strong for the wild dog to pose
any real threat. This round closed that gap. A fresh, weak non-admin
test character (`dsjczi`, id-only, password redacted — 膂力19/悟性24/
根骨19/身法18, 攻击力11/防御力12, freshly registered with no gear or
skill training) was registered, then the admin account (`fluffos`,
already-documented credentials, no new secret recorded here) used
`goto dsjczi` followed by the admin `call` command
(`call dsjczi->die()`, defined in `cmds/adm/call.lpc`, which does a
raw `call_other()` with no non-wizard-player guard) to force a
real, conclusive death — deliberately bypassing only the *combat
outcome*, not the death/reincarnation machinery itself, matching this
session's established precedent (`smash` in `cmds/wiz/smash.lpc`
explicitly refuses `userp(ob) && !wizardp(ob)` targets, so `call` is
the correct tool here, not a design bypass).

Full cycle traced and verified:
1. `die()` (`feature/damage.lpc:115`) fired correctly: death message
   ("试死子口中喷出几口鲜血，倒在地上,死了！"), a corpse object left
   behind in the room, a "江湖传闻" broadcast, `ghost` flag set,
   `jing`/`qi`/`eff_jing`/`eff_qi` all reset to `1`, character moved to
   `DEATH_ROOM` = `/d/death/gate` ("鬼门关").
2. `DEATH_ROOM->start_death(this_object())` is called unconditionally
   by `die()` but **no file in this lib actually defines a
   `start_death()` function reachable from `/d/death/gate`'s inherit
   chain** (`grep -rl start_death` only turns up the call site itself
   plus one unrelated NPC). This is a silent no-op (`call_other()` to a
   nonexistent function returns `0` with no error, no debug.log entry,
   no driver rejection) — per this project's standing scope rule, a
   silent no-op with no error signature is not something to "fix"
   speculatively, and it turns out to be harmless: the REAL
   reincarnation trigger is a completely separate mechanism, see next
   step.
3. Moving into `/d/death/gate` broadcasts `init()` to the room's
   `wgargoyle` NPC ("白无常", `d/death/npc/wgargoyle.lpc`), whose own
   `init()` schedules a 5-stage `call_out("death_stage", 5, ...)`
   interrogation sequence (guarded by a `death_stage_active` temp flag
   against reconnect-duplication, per the AGENTS.md §7.112 pattern —
   already correctly guarded here, see checklist section below). All 5
   stages delivered correctly over ~25 seconds (verified via
   `call dsjczi->query_temp("death_stage_active")` reading back `0`
   and `call dsjczi->is_ghost()` reading back `0` after the sequence
   completed).
4. Final stage called `ob->reincarnate()` (`feature/damage.lpc:183`),
   which cleared the `ghost` flag and restored `eff_jing`/`eff_qi` to
   max, then (falling through, by design, into the same function body)
   dropped all inventory and moved the character to `REVIVE_ROOM` =
   `/d/city/wumiao` ("武庙").
5. Re-logged in as `dsjczi` after the full cycle: reconnect banner
   ("重新连线完毕"), `score` showed 你共死亡: 1 次 (death counter
   incremented correctly), character correctly located in 武庙,
   attack/defense stats visibly reduced post-death (intentional
   penalty, not a bug), `look`/`quit` both worked normally.

`log/debug.log` stayed clean throughout the entire sequence (checked
before, during the ~25s `death_stage` wait, and after reconnect) — only
ordinary first-touch lazy-compile `Warning:` lines from unrelated
objects being loaded for the first time this boot, zero runtime
errors, zero driver-level rejections. **No bug found or fixed this
round** — the death/respawn gap flagged by prior rounds is now fully
closed with a clean result.

Cleanup: driver killed by exact PID (confirmed via
`readlink -f /proc/<pid>/cwd` first), `data/{login,user}/f/fluffos.o`
timestamp drift reverted via `git checkout HEAD`, test character
`dsjczi`'s save files (`data/{login,user}/d/dsjczi.o`) deleted (not
committed), `log/debug.log`/`log/boot.out` removed.

### Fast standard-checklist sanity pass (grep + targeted read, all clean or already-fixed)

- **§7.90** (eval-cost limit): already fixed in the 2026-08-08 round
  (`config.fluffos` at `5000000`); reconfirmed present, not re-tested
  live this round beyond the death-cycle session itself producing zero
  `cost limit reached` hits.
- **§7.100** (`ROOM` `replace_program()` landmine): already fixed
  2026-08-19 (2,336 lines); not re-swept, no new instances expected.
- **§7.111** (`standard_trace()` unguarded `file_name(error["object"])`):
  `adm/obj/master.lpc:232` already has the
  `objectp(error["object"]) ? file_name(...) : "<none>"` guard — clean.
- **§7.112** (`death_stage()` reentrancy leak): all four live
  `death_stage`-bearing files checked
  (`d/death/npc/bgargoyle.lpc`, `d/death/npc/wgargoyle.lpc`,
  `d/shaolin/npc/yu-zu2.lpc`) correctly set/clear a
  `death_stage_active` temp-flag guard on every exit branch — clean,
  and this round's live death test exercised `wgargoyle.lpc`'s guard
  directly (see above). `d/death/wgargoyle.lpc` (older, non-`npc/`
  copy) has `death_stage()` entirely commented out — confirmed dead
  code, already classified as such in AGENTS.md §7.112's residual-gap
  writeup.
- **§7.108** (duplicate-login-kick reconnect losing `enable_commands()`):
  `clone/user/user.lpc`'s `reconnect()` already unconditionally calls
  `enable_commands()` first — clean, matches the corpus-wide fixed
  shape.
- **§7.79** (bare 2-arg `addn()`/`addn_temp()`): no `addn(` call sites
  exist anywhere in this lib — not applicable.
- **§7.30** (uninitialized-mapping accessor guard in `feature/skill.lpc`):
  already fixed 2026-08-20 (4 accessors, `mapp(x) ? x : ([])`) — not
  re-verified live this round.
- **Shared-file bug shapes from this session's sweep candidates,
  checked directly against this lib's actual code (none matched)**:
  `adm/daemons/combatd.lpc` has no `bounce`-variable division-by-zero
  loop (it does have an unrelated `while (random(defense_factor) >
  my["combat_exp"]) { ...; defense_factor /= 2; }` combat-exp-scaling
  loop, but `random()` of `0`/negative doesn't error on this driver and
  the shape doesn't match the reported `x / bounce` division bug at
  all — not the same issue, left alone); no `chacha.lpc` file exists in
  this lib; `adm/daemons/natured.lpc` contains no `userp(`/
  `interactive(` reference at all (the reported zombie-object line
  isn't present in any form); `cmds/std/go.lpc` uses `mapp(exit =
  env->query("exits")) || undefinedp(exit[arg])` for its exit-validity
  check, not the reported `sizeof(exit[arg]) - 2` suffix-slice pattern
  — not applicable. `feature/attack.lpc` exists but is a normal
  per-character combat-application file, not an `F_DBASE`-sibling
  inheritance shape — sanity-checked, no issue found.
