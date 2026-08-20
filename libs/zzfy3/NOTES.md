
## WASM 修复摘要（迁移自 meta.json 的 group_note）

郑州风云3（游戏内横幅：风云系列之天下无敌 / 'Invincible Under Heaven'，一款受古龙小说启发的风云系列武侠 MUD，由长孙无情/Xgchen 制作）。有一个带有真实游玩内容的巫师个人目录（u/wiz/u/xxy/，技能/NPC 档案，不是死代码系统精灵备份），另外还有少数几份真正的死代码 logind.lpc 备份，分布在 d/wiz/xgchen/、u/wiz/u/china/、u/wiz/u/lxh/——已通过 LOGIN_D=/adm/daemons/logind 和 MASTER_OB=/adm/obj/master（include/globals.h）确认只有 adm/daemons/logind.lpc 和 adm/obj/master.lpc 是真正生效的；logind.lpc 的备份保持原样未做改动，但 u/wiz/u/xxy/ 下的 is_killing() 呼叫点确实做了修复，因为那些技能/NPC 档案是普通的、可触达的游玩内容，不是死代码精灵副本。这份档案的 securityd.lpc 不同寻常：完全不使用 adm/etc/wizlist——管理员身份是通过 securityd.lpc 自己的 restore_list() 里一行硬编码的 'set("wiz_status/xgchen","(admin)")' 授予的，每次启动都会重新应用，所以第一次启动获得管理员权限的唯一方式就是用原作者自己的巫师 id 'xgchen' 注册——已确认 'xgchen' 不在 logind.lpc 的 banned_id 列表里。WASM 修复了：（1）check_legal_name() 的 §8.1 字节数翻倍界限（<2||>12，本意"1 到 6 个中文字"，已改成 <1||>6）以及一个 i%2==0 的奇偶门槛，配合一个单码点的 is_chinese() 辅助函式（通过 name[i..<0] 切片检查 str[0]），实际上只验证了每隔一个字符——已删掉奇偶门槛。（2）master.lpc（adm/obj/master.lpc）的 valid_write() 缺少标准的 'user == this_object()' 保护——已加上（valid_read() 这里本来就无条件回传 1，完全没有转发给 securityd，不需要保护）。（3）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了 25 处呼叫点，分布在 daemon/class/*、cmds/daemon/class/*（一份和 daemon/ 真正平行的重复代码树，两边都有相同的内容——两边都做了修复，因为无法排除任何一边是死代码）、cmds/std/{surrender,nuoyi,kill}.lpc、d/wiz/xgchen/touxiang.lpc，以及 u/wiz/u/xxy/ 下多个技能/NPC 档案（kungfu 技能、mei-po.lpc）。确认本来就正确的地方：securityd.lpc 的 save_object valid_write() 检查本来就对照 query_save_file()+__SAVE_EXTENSION__。httpd.lpc 和 dns_master.lpc（包括 adm/daemons/ 里的正本以及 u/wiz/u/china、u/wiz/u/lxh 里过时的备份副本）都带有真实、未掏空的 socket_*() 呼叫，但都在 adm/etc/preload 里被注释掉，也没有其它可触达的呼叫者——保持完全休眠，和本项目其它档案已经确立的模式一致；这份档案里不存在 versiond.lpc。log/nosave/ 目录缺失——出于预防已经创建（没有确认是阻断启动的）。管理员账号是通过硬编码的 xgchen 授权隐式播种的（这份档案没有 wizlist 档案可以编辑）。注册流程在格式化前后都完整验证过（英文 id 'xgchen'→y 确认→单一中文名字（1-6 个字）→密码+确认→电子邮件→性别→民族菜单（0-3，用的 0 代表汉族）→一个"按回车继续"的信息屏幕闸门→进入凤求凰客栈），管理员权限已通过'目前权限：(admin)'确认。这份档案的提示符会显示实时时钟（符合 AGENTS.md §8.3 第 1 条）——注册测试时用的是 --idle 0.4。LPC 格式化工具对全部 9224 个档案运行（写入 9194 个，20 个转档之前就存在的错误，10 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 34 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-09）

**血统确认（新发现，AGENTS.md §11 已更新）**：`zzfy3` 和已经做过完整
§10.7 深度测试的 `zzfy`（020 号，同名"郑州风云3"，此前两份档案从未
互相记录过关系）其实是**同一套引擎/地图的近乎重复副本**——两边
`work/` 目录都是 10345 个档案，`diff -rq` 只有 183 个档案内容不同，
且大部分差异是个别 NPC 的对话/价格微调、日志/存档噪音，或者两边各自
独立修过的同一个 bug（比如这份档案自己此前已经修过的 §7.50
`is_killing()`、check_legal_name 等，`zzfy` 那边没有；反过来
`zzfy` 已经修过的几个 bug 这份档案还没有）。核心文件（`obj/master.lpc`、
`std/char/master.lpc`、`p/fystreet/npc/master.lpc`、`u/tangmen/master.lpc`
等）目录结构完全一致，`adm/obj/master.lpc` 档头都是同一句 "for ES II
mudlib / original from Lil / rewritten by Annihilator (11/07/94)"。
结论：这是两个站长各自运营、各自轻微改动过的同一份原始档案，不是
两个不同的游戏——按本项目 `jyqxc`/`jyqxc2` 近重复对的先例处理（不
回头合并两个 `libs/` 条目的编号，但把 `zzfy` 已经现场验证过的 §10.7
发现直接当作已确认的兄弟 bug 列表来对照移植，逐条现场复测而不是盲
搬）。移植并现场验证过的 `zzfy` 既有发现：

1. **§7.24（死亡代码覆盖永久登入地点）**：`d/death/npc/panguan.lpc`
   的 `death_stage()` 最后一步无条件 `ob->set("startroom",
   base_name(environment(ob)))`，把玩家的永久登入/存档地点覆盖成两个
   临时"投胎候位点"之一（`/d/fy/church` 或 `/u/guanwai/tower`，都没
   有 `cmds/usr/save.lpc` 要求的 `valid_startroom` 标记）——删除了这
   一行，`move()` 已经处理了死后的即时安置，不需要再改登入地点。
2. **§7.25（房间填充助手 `new()`/`move()` 无防护）**：`std/room.lpc`
   的 `make_inventory()` 对 `new(file)` 的结果没有任何检查就直接
   `->move()`/`->set()`——补了 `catch(ob = new(file)) ||
   !objectp(ob)` 防护，并在 `reset()` 两处消费该结果的地方加了
   `objectp()` 检查。
3. **`feature/vendor.lpc` 商店 bug（同一 §7.25 类，不同调用点）**：
   `vendor_goods` 里一条商品路径 `/obj/example/wineskin`
   不存在（正确路径是 `/obj/food/wineskin`），13 个 NPC 档案
   （`d/laowu/npc/{dang,waiter,drunk}.lpc`、`d/chenxiang/npc/oldman.lpc`、
   `d/kaifeng/npc/waiter.lpc`、`d/fy/npc/{drunk,waiter,waiter_bak,
   biaotou}.lpc`、`d/tieflag/npc/xiaofan.lpc`、
   `d/songshan/npc/waiter.lpc`、`u/tangmen/npc/waiter.lpc`、
   `u/wudang/npc/waiter.lpc`）都用了这条坏路径，`do_vendor_list()`/
   `buy_object()`/`compelete_trade()` 对商品路径直接 `->name()`
   之类隐式 `load_object()`，撞到坏路径就整个商店 `list`/`buy`
   崩溃——13 个 NPC 档案的路径都改成 `/obj/food/wineskin`，
   `feature/vendor.lpc` 三处循环都包一层 `catch(load_object(name[i]))`
   跳过，防止未来任何一个未发现的坏路径继续把整个商店拖垮。
4. **`cmds/wiz/summon.lpc` 空指针判断顺序（管理员专用，小问题）**：
   `ob->query("id")` 判断在 `!ob` 判断之前，`summon` 一个当前不在线
   的玩家会直接崩成 `Bad argument 1 to EFUN call_other()`——调换了
   两行顺序。

**本轮（`zzfy` 自己的 §10.7 没发现、`zzfy3` 独有的）新发现**：

5. **新增 AGENTS.md §7.102：`cmds/std/go.lpc` 移动派发器自己的出口
   强制加载没有防护**：`凤求凰客栈`（`/d/fy/fqkhotel.lpc`）店小二明确
   叫每个新玩家打「新手学堂」，但这个出口指向 `/d/newbei/wel1`——一个
   整个档案里根本不存在的新手学堂分区（`find` 确认，真实内容缺失，
   不是拼写错误能修的路径问题）。`go.lpc` 用裸 `call_other(dest,
   "???")` 强制加载出口目标，目标压根不存在时直接抛出未捕获的
   `*call_other() couldn't find object`，把驱动自己的完整报错堆栈
   （程式名、行号、呼叫链）甩到玩家屏幕上，而不是正常的"无法移动。"
   拒绝提示。这不是这个房间独有的问题——任何房间的任何一个失效/
   过期出口都会炸出同样的堆栈，因为 `go.lpc` 是所有移动指令共用的
   唯一派发器。`zzfy` 那边 `go.lpc` 和这个坏出口都是字节相同、同样
   没修（该库自己的 §10.7 没有恰好试到这个出口）。修复：
   `call_other()` 外面包一层 `catch()`，失败就走跟"确认不存在"完全
   一样的 `notify_fail("无法移动。\n")`。现场验证：修复前 `新手学堂`
   直接甩出完整报错堆栈；修复后同一指令显示"错误讯息被拦截"（本项目
   `catch()`-防护类修复的标准输出约定）+ 正常的"无法移动。"，命令
   派发器继续正常工作（同一会话里后续的战斗/死亡/复活全部正常）。
   缺失的"新手学堂"分区本身是真实的内容缺口，没有编造内容去填。
6. **新增 AGENTS.md §7.103：`master.lpc` 的运行时报错处理器把纯编译
   *警告*（不只是真正的错误）原样甩给每一个普通玩家**：
   `adm/obj/master.lpc` 的 `log_error()` 对 `this_player(1)`（这个
   驱动上是"忽略 shadow 拿到当前玩家"，不是"仅限巫师"）无条件
   `efun::write("编译时段错误：" + message)`，结果是几乎每一次某个
   房间/NPC/指令档案第一次惰性编译时产生的"Unused local variable"/
   "Unknown #pragma"之类纯警告，都会原样刷屏甩给当时在线的**任何**
   玩家，包括普通玩家——现场确认：光是注册流程+走几步路，就已经刷了
   几十行这种警告文本。兄弟档案 `zzfy` 其实已经独立修过这个问题（本次
   血统核对时通过 diff 发现），补丁是给 `this_player(1)` 那个条件加
   一个 `&& strsrch(message, "warning:") == -1`——移植了同样的补丁：
   真正的报错（消息里不含字面 "warning:"）照常显示，纯警告不再进入
   玩家可见的输出流（仍然会 `write_file()` 进对应巫师的 log，只是
   不刷屏）。现场验证：补丁前的注册+移动流程刷了大量警告文本，补丁
   后同样的流程干净，而 §7.102 的真实 catch() 报错依然正常显示。
7. **标准 §1.3b/§1.3e 连线节流豁免此前缺失**：`adm/daemons/band.lpc`
   没有 `is_local_site()`，`adm/daemons/logind.lpc` 的多重登录上限
   （`iplimit > 15`）和 20 秒重连节流都没有本地/回环豁免——测试过程
   中亲自撞上了这个节流（`quit` 后立刻重连被拒："你刚退出游戏19秒，
   为了减轻系统负担请过二十秒再连入"）。兄弟档案 `zzfy` 已经有这个
   标准补丁（本项目对所有档案的既定政策），直接移植：
   `band.lpc` 新增 `is_local_site()`（127.0.0.1/::1/localhost/127.
   前缀），两处节流各加 `&& !BAN_D->is_local_site(query_ip_number(ob))`
   短路（1 小时踢出惩罚保持不变，那是游戏设计不是连线保护）。现场
   验证：补丁后 `quit` 立刻重连不再被节流拒绝。

**§7.68 / §7.101 是否适用于本库的死亡系统**：都不适用，理由分别记录：

- **§7.101（`exits` 缺键导致 `valid_leave()` 永远打不到）不适用**：
  本库的死亡引擎完全不是 ES2/`kxkjii2` 那种 `exits`-映射-门控的复活
  机制——`d/death/gate.lpc`（鬼门关）的出口（south/east）都是普通、
  完整可用的键，没有被注释掉或缺失的方向；真正负责复活的是房间里的
  判官 NPC `d/death/npc/panguan.lpc`，靠自己的 `init()`/`call_out()`
  链条播放对话、`reincarnate()`、`move()` 送回人间，完全不经过
  `go`/`valid_leave()` 这条路径。
- **§7.68（`present(ob)` 缺失重试导致鬼魂卡死）不适用，现场验证过
  两条前提都不成立**：`panguan.lpc::death_stage()` 的守卫确实是同样
  的 `if (!ob || !present(ob) || ...) return;` 形状，但现场验证：
  (1) 鬼魂**可以**在这个房间自主移动——`单于五(zztestone)` 死后从
  `鬼门关` 主动打 `south` 成功走到了 `冥府大道`，没有任何"你已经
  精疲力尽，动弹不得"之类的阻挡提示；(2) 通读全库没有找到任何类似
  `bmxkx2001` 剧情 NPC 那种会强行拖走鬼魂的机制。两条前提都不成立，
  保持原样不改，这正是"鬼魂在阴间自己游荡、下次撞见判官会重新触发
  对话"的有意设计——现场也确认了这一点：`死亡玩家` 先在没有判官的
  `鬼门关` 落地（判官那时候刚好走去了别处），死亡对话完全没有开始；
  用 `goto panguan` 把 `zztestone` 移到判官所在的 `冥府大道` 后，
  判官的 `init()` 立刻触发，五段对话如期播放，`reincarnate()` +
  `move()` 落地在 `天主教堂`（两个投胎候位点之一）。
- **现场验证的完整死亡/复活流程（非管理员角色）**：注册了一个普通
  玩家 `zztestone`/`单于五`，用管理员 `xgchen` 在同一房间 `clone`
  出一只山西土匪（`d/fy/npc/tufei11111.lpc`，`combat_exp` 高达十万到
  四百万，"aggressive" 主动攻击属性）——土匪一进房间就主动开打，先后
  打死了在场的管理员 `xgchen`、`店小二`、`zztestone`（三人都是同一
  只土匪杀的，纯粹是测试道具选得太狠，不是游戏平衡问题）。`zztestone`
  死后经上文所述的判官对话链完整走完，`score` 确认"被杀了一次"、
  属性/血条恢复正常、不再显示鬼魂状态。**`quit` 后真实重连验证
  §7.24 修复**：重新登入 `zztestone`，落地地点是原本注册时选的
  `凤求凰客栈`（而不是死亡候位点 `天主教堂`/`关外楼`），确认永久
  登入地点没有被死亡流程覆盖。
- **管理员账号的鬼魂状态（§10.7 第 6a 条已知模式，非 bug）**：
  管理员 `xgchen` 死后同样被移到 `鬼门关`，但 `panguan.lpc::init()`
  对 `wizardp(previous_object())` 直接 `return`，从不给巫师排死亡
  对话——这是本项目已确认的标准设计（巫师靠自己的指令自救，不占用
  NPC 复活剧情），现场确认 `xgchen` 用 `goto`/巫师权限完全可以自由
  行动，没有任何卡死。

**已观察但未深入调查（不属于本轮已验证修复范围，如实记录）**：
`adm/daemons/natured.lpc::event_noon()`（应为每游戏日中午触发一次的
天气/生病随机事件）在本轮测试session 里短时间内连续触发了几十次
"你偶感风寒，竟而发起烧来"/"单于五的脸蛋烧得通红"（在场两名玩家交替
出现），远超"一天一次"的预期频率——可能是这个函数被多次
`call_out()`/`heart_beat()` 重复排程（类似 §7.23 的形状），也可能是
游戏内时间推进速度本身很快导致短短几分钟真实时间跨过了好几个游戏日
的中午。没有现场追踪具体的排程代码来确认是哪一种，也没有改动任何
代码——与本轮的所有 bug 修复（§7.24/§7.25/§7.102/§7.103/商店坏路径/
连线节流）均无关，纯属游戏天气系统的既有行为，留给下一次专门调查。

**其余检查过、确认没问题的项目**：留言板 `post`/`look board`
现场复测正常（`/d/fy/fysquare.lpc` 强制加载的 `/obj/board/
fysquare_b.lpc`，此前 §7.86 扫描已删过多余的 `replace_program()`，
本轮实际发帖验证：`post stone` 写入一条新留言，`look stone` 确认
可见）；`skills`（技能查询）、`score`、`i`、移动多房间穿行均无异常；
`feature/skill.lpc`、`d/fy/npc/{gmaster,sqx}.lpc`（教师/帮派收徒
NPC）与 `zzfy` 逐字节相同（仅一处纯空白差异），`zzfy` 自己的
§10.7 已经现场验证过技能学习（`learn ... from ... with ...`）和
帮派加入（`apprentice`）两条路径均正常，本档案共用同一份代码，未
重复验证。`replace_program(ROOM)`（AGENTS.md §7.100 描述的"ROOM
基类版 §7.86"landmine 变体）在本库出现 2059 次——量级上属于"很可能
已经殖民了房间基类"的区间，但本轮完整会话（注册/移动/战斗/死亡/
复活/留言板）的 `debug.log` 和驱动 stdout 里没有出现过一次 "cannot
replace a program" 的驱动警告，说明本轮没有现场触发——按 AGENTS.md
§7.100 已有的处置原则（`jyqxc`/`jyqxc2` 先例），量级记录在案、留作
后续专门扫描的已知积压，本轮不做批量修改。

**本轮种子/测试角色**：管理员 `xgchen`/`Mud@2026`（按本档案既有的
硬编码 `restore_list()` 机制自动获得 `(admin)`，本轮重新走完整注册
流程验证过，登入横幅确认"目前权限：(admin)"，`update` 指令验证过写
权限）；普通玩家 `zztestone`/`Mud@2026`/随机分配中文名`单于五`
（中文取名步骤在这个特定 tmux 会话里被 telnet 传输损坏了一次，
跟 AGENTS.md §10.2 记录的已知 CJK 字节损坏陷阱一致——本轮注册
`xgchen` 时用同样的 tmux 链路顺利输入了真实中文名"长孙风"，说明不是
`is_chinese()` 本身的问题，纯属传输层偶发损坏，接受随机名继续测试）。
两个角色、测试期间产生的尸体/骸骨等战斗残留物均保留在存档里，作为
本轮测试证据，未删除。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。上面记录的修复逐项核对代码仍然生效
（`log_error()` 已经有严重度判断，`d/death/npc/panguan.lpc`/
`std/room.lpc`/`feature/vendor.lpc`/`cmds/std/go.lpc`/
`band.lpc` 的修复都还在）；这份档案没有 `win_times` 相关的裁判
NPC（`u/wiz/` 巫师个人目录不存在），不适用。

### 本轮新发现并修复的 PROGRAMMING bug

1. **管理员账号播种从未覆盖 `fluffos`——和兄弟档案 `zzfy` 完全相
   同的 bug 形状**：`securityd.lpc` 的 `wiz_status` 是 `nosave`，
   `restore_list()` 只硬编码授予 `xgchen` 管理员权限；上一轮深挖
   全程用的都是 `xgchen` 这个账号，`fluffos` 从未被注册或授权过。
   已在 `set("wiz_status/xgchen", "(admin)")` 后面加一行
   `set("wiz_status/fluffos", "(admin)")`，不改动既有的 `xgchen`
   硬编码。Live 验证：完整注册流程创建 `fluffos` 后，`update
   /adm/simul_efun/file` 显示"重新编译
   /adm/simul_efun/file.lpc：成功！"，确认真实拥有 `(admin)` 级写
   权限（没有只看登入横幅的状态文字就下结论——这份档案的登入横幅
   本身没有显示"目前权限"这类文字，用 `update` 直接验证写权限是
   唯一可靠的确认方式）。
2. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护**：已加上前向声明 +
   `assure_file(LOG_DIR + file);`。
3. **`cat()`（同一文件）对不存在文件的空指针式崩溃，主动加固**：
   未在本档案现场触发，属主动加固，改成 `write(read_file(file) ||
   "");`。
4. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）**：紧跟
   在中文名字确认之后，把连线桩物件的原始引用直接回显给正在注册
   的新玩家。已删除两处。

### Proactive checks（无需改动）

- §8.9 食物/饮水初始化不适用：无条件
  `user->set("food", user->max_food_capacity())`。
- `feature/dbase.lpc` 未发现密码写保护，不适用 tybxjh/wlhd 那一类
  bug。
- **确认这份档案的注册流程比 `zzfy` 多一步民族选择（0-3：汉/苗/
  满/蒙古），没有天赋赠礼菜单**：读代码核实过实际顺序是 id→y→中文
  名→密码 ×2→email→性别→民族，不是盲搬 `zzfy` 的流程假设。

### 实测过程

管理员 `fluffos`（`wiz_status` 此前从未覆盖到这个 id）用完整注册
流程（含民族选择步骤）创建，落地"凤求凰客栈"。随后**两次**真实断
线重连+密码验证：第一次专门用 `update /adm/simul_efun/file` 确认
`(admin)` 权限真正生效，第二次单独验证密码重连本身。均成功登录，
存档数据一致。全程 `debug.log` 无运行时错误。驱动按精确 PID 结
束；管理员存档（`data/{login,user}/f/fluffos/fluffos.o`）已提交。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/std/room`）在本档案 1,967 处房间文件的 `create()` 里
紧跟 `inherit ROOM;` 之后又多余调用了一次 `replace_program(ROOM);`
——AGENTS.md §7.100 记录的同一个休眠 bug，和兄弟档案 `zzfy`（郑州
风云同一血统，`fix_710_room.py` 标准扫描数字逐位吻合：1,817 标准
形状 + 40 处 `u/wiz/u/heart/xuedao/` 子目录的规整形状）完全同源。
剩余 150 处不规则存活形态也和 `zzfy` 完全一致：`u/wiz/u/heart/
xuedao/` 下 143 个文件带有和 `tiexuejianghu` 血统同源的"如果没有
init 函数请不要删除这句话"尾随 UTF-8 注释变体（按既有先例整行删
除，含注释），以及 14 个文件、18 处帮派/房间建造工具字符串拼接
变体（`cmds/adm/roommaker.lpc` 3 处、`d/wiz/xgchen/roommaker.lpc`、
`obj/wall.lpc`、`u/wiz/u/panguan/{room,rmmaker}.lpc`），手工改成
`str += "...setup();\n}\n";`／`room_code += "...setup();\n}\n";`。
`git diff --stat` 显示 1963 个文件净删 1967 行、增 7 行，与
survey 记录的存活总数完全吻合。`work/data/` 下没有真实 `.lpc`
源码命中。

驱动干净启动（零新增编译错误、端口 40120 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`/
`Mud@2026` 实机登录成功（沿用固定总时长读取策略，绕开这份档案
每秒刷新的 `HH:MM:SS>` 提示符），`look`/`score`/`quit` 均正常，
落地"凤求凰客栈"（和兄弟档案 `zzfy` 相同的起始房间）。管理员存
档的时间戳漂移已用 `git checkout HEAD --` 还原，未提交。驱动按精
确 PID 结束。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/panguan.lpc`, `d/death/npc/panguan2.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.
