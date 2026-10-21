
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

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 17 line(s) in 5 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 11 file(s) `inherit F_SSERVER;` and no header defines it (11 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 1 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `u/wiz/u/xxy/room/heimuya/shenggu.lpc`, `u/wiz/u/xxy/room/heimuya/tang.lpc`, `u/wiz/u/xxy/room/heimuya/npc/tang.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/adm/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 2 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location`、`tongji/dynamic_location` 里 2308 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`adm/daemons/tongjid.lpc`、`d/meiyuan/npc/zhuge.lpc`、`d/yihua/npc/yaoyue.lpc`、`tongji/npc/zhuge.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 43 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`adm/daemons/tongjid.lpc`、`d/meiyuan/npc/zhuge.lpc`、`d/yihua/npc/yaoyue.lpc`、`tongji/npc/zhuge.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 5 个，工作树三次分别通过 5、5、5 个（共 6 个），无回退；`d/meiyuan/npc/zhuge.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt wqfy zzfy3` 把 wqfy 警告整理提交（0dd906c83e7）里的改动搬到约 525 个修改前与它一致的文件（逐文件核对非 ASCII 文字：除 wqfy 自己删掉的以外没有丢失或改动），剩下的再跑 `scripts/lpc_warnings.py zzfy3 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 816 个 `.lpc` 和若干 `.h`。
与 wqfy 相同的两处真错误：`adm/daemons/combatd.lpc` 易筋经反震"内伤"800–1600 一档少了 `return`，描述算出来就扔了；`d/kaifeng/npc/huzhou.lpc` 的 `command("follow %s", ob->query("id"))` 在本库是编译错误，护舟这个 NPC 整个加载不了——改成 `command("follow " + ob->query("id"))` 后能加载了。
HEAD 与工作树分别加载（新进程）：745 -> 746 通过（多出的就是 huzhou），无回退；改过的头文件的 25 个包含者 24 -> 24 通过。

启动时警告 76 -> 0。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 9 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 1 个文件；改动 10 个文件，HEAD 与工作树各载入一次无回退（10 objects; HEAD PASS 5, tree PASS 5; regress 0; newly loading 0），这些文件的警告 11 -> 1。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `u/wiz/u/lxh/emoted.lpc`：删去空的 `if (!channel_emote) {}`（下一句才被报警）。载入无回退。

## 编译警告收尾（2026-10-12）

孪生库 zzfy 同日的整理（33a36d7b904：冗余继承 28 处，`cmds/adm/roommaker.lpc` 重复的 `special_props`，`u/wiz/u/lxh/globals.h` 的 `#undef` 与 `BANNED_SITES` 多余分号）用 `scripts/lpc_twin_port.py adopt zzfy zzfy3 --pre 33a36d7b904~1` 搬来，30 个文件与 zzfy 修前逐 token 相同；清单里的警告全部落在这些文件里。HEAD 与工作树各载入一次：HEAD PASS 11，tree PASS 12，regress 0。新载入的是 `d/fy/fish.lpc`：`CREATE_CHAT_ROOM` 宏已继承 ROOM，又写 `inherit ROOM;` 触发 nomask 重定义，从前载不进来。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 2 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 `int power_point()`/`int hard_point()` 返回 1.5、1.75 之类的浮点，经 int 返回被截断；本库没有调用者（练功走 `practice_bonus`/`learn_bonus`），改成 `float` 返回值，保留原数值。

- 2026-10-14：3 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14：1 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上；1 个文件的函数声明为 `int`（或 `void`）却返回字符串、对象（`int query_seal() { return "…"; }`），旧驱动照样把值交给调用者；改为实际返回的类型（`scripts/lpc_fix_void_return.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：4 个对象，新增载入 4，回退 0。

- 2026-10-14：讲故事发奖励系统（`adm/daemons/storyd.lpc` 与 `clone/gift/` 下 20 个故事）照 `obj/gift/readme.txt` 应在 `include/globals.h` 定义 `STORY_D`、`STORY_DIR`，安装时漏了，这 23 个文件整份不编译；补上两个宏后全部载入（新进程比对，回退 0）。readme 还要求把 storyd 加进 preload，那是开不开这项玩法的决定，没有动。`u/wiz/u/xxy/city2/library.lpc` 自己的 `STORY_DIR` 前加 `#undef`。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

10 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 内力/上限当作伤害种类（补）（2026-10-15）

`victim->receive_wound("force", n, me)`（兵器吸内力）、`receive_damage("max_qi", random(100))`（走火入魔扣上限）等本库不接受的种类，1 处改为 `add(type, -N)`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yihua-jimu`→`yihua-jiemu`（`/cmds/daemon/skill/yihua-jiemu`、`qishier-jueji`、`yihua-jiemu`）；`putfiforce`→`putiforce`（`/cmds/daemon/skill/qiankunwuxing`）；`xizia-shengong`→`zixia-shengong`（`hunyuan-zhang`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

178 个文件、249 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/misc/cloth`、`/d/obj/cloth/linen`、`/d/obj/cloth/choupao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 85 个（84 个原来载入不了），没有退步；其余 93 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 94 个对象设了本库没有文件的武功（161 个名字，最多的是 `claw`、`yunlong-shengong`、`yunlong-shenfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 18 个通过，其余 12 个停在别的错误上（`d/city/npc/xiaoxiao`：*No program in object '/d/city/npc/xiaoxiao'!；`d/city/npc/yg/yg-dragon`：*Inherited file '/d/dntg/yunlou/npc/yaoguai' does not exist!……）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/menggu/ta2` 的 `down`：`liuhe1` → `ta1`；`/d/menggu/tadi3` 的 `northeast`：`tadi4` → `yadi4`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/feature/vendor_sale`（宏 `F_VENDOR_SALE`）←xianlvqiyuan，15 个对象继承它，抽样 10/10 载入；`/feature/unique`（宏 `F_UNIQUE`）←haiyang2，14 个对象继承它，抽样 10/10 载入；`/std/weapon/stick`（宏 `STICK`）←xianlvqiyuan，5 个对象继承它，抽样 4/5 载入；`/std/char/npcsave`（宏 `NPC_SAVE`）←xianlvqiyuan，3 个对象继承它，抽样 3/3 载入；`/std/weapon/unarmed`（宏 `UNARMED`）←sjsh，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 27 处、9 个文件：`taiji-force`→`taijiforce`（16 处）、`liumai-shenjian`→`liumaishenjian`（4 处）、`lotus-force`→`lotusforce`（4 处）、`tang-balde`→`tang-blade`（2 处）、`duan-yirangzhi`→`duan-yiyangzhi`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 4 个：`/cmds/daemon/skill/jueqing-zhang.lpc`、`/cmds/daemon/skill/yifeng-jian.lpc`、`/daemon/skill/fanliangyi-dao.lpc`、`/daemon/skill/poyu-quan.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 27 个：`d/kaifeng/npc/tufei2`、`d/kaifeng/npc/tufei3`、`d/kaifeng/npc/tufei4`、`d/kaifeng/npc/tufei5`。（`scripts/lpc_transplant_function.py`）

## laozhe 的 command("give yancao to", me)（2026-10-19，KB 06 §7.266）

`u/wiz/u/xxy/room/heimuya/npc/laozhe.lpc`（巫师目录里的副本）的 `init()` 里写着 `command("give yancao to", me);`，`command()` 只收一个字符串，驱动报 `Too many arguments to 'command'`，整个 NPC 载入不了。照 cctx、fys 等库已经改好的写法，改成 `command("give yancao to " + ob->query("id"));`（`ob` 是刚进房间的玩家）。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：35 个未使用的局部变量，1 处函数返回类型改成与基类一致。修后与 HEAD 逐个物件对比载入，没有退步。

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/adm/etc/ranputthing.lpc`、`/d/city/npc/duguoyin.lpc`、`/questnew/ranputthing.lpc`共 3 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `adm/simul_efun/file.lpc` 补上同系列（fy3dz、fy3xd）的 `write_file2()`：`adm/daemons/brd.lpc` 和订做衣服、打铁的 NPC 调用它，之前编不过
- `d/wudujiao/npc/baichan.lpc` 删掉 `map_skill("baichan-hammer", 100);`（第二个参数应是字符串；上面已有 `set_skill`，下面有 `map_skill("hammer", "baichan-hammer")`）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 技能书的基类（2026-10-19，KB 04 §6.15、KB 06 §7.262）

`obj/book/*.lpc` 的 40 本技能书（与 wqfy、xkyx3b 逐字节相同）都是 `inherit BOOK;`，本库没有这个宏，也没有它的基类，整批载入不了。补回：`/std/item/book.lpc`（宏 `BOOK`，xkyx3b 的同一份，经 wqfy 拷来），`adm/simul_efun/atoi.lpc` 补上基类要用的 `itoa()`、`space()`，`include/ansi.h` 里被注释掉的背景色宏 `BWHT` 恢复。41 个对象（40 本书和基类）全部载入，以前一个都不行，逐个与 HEAD 对比没有退步。（`scripts/lpc_restore_bases.py --evidence --retry`、`scripts/lpc_add_sefun.py space`）

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/menggu/tadi1.lpc`（wqfy）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/wiz/u/legato/obj/skeleton.lpc`（2 个）、`/u/wiz/u/xxy/city2/npc/zhengmen.lpc`（2 个）。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 2 个文件：`/u/wiz/u/mool/kid.lpc`、`/u/wiz/u/xxy/room/heimuya/ren.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/xj/obj/lotus.lpc`（2 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 6 处）。改动：`/d/city/mjlady3.lpc`（3 处）、`/d/wiz/sku/obj/mj.lpc`（3 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。`logon()` 对每个连接都调用它，连接以 `Bad argument 1 to sscanf` 被断开，没有人登录得进来；改后用新进程实测可以登录。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/adm/daemons/logind.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/network/getconfig.h`（1 处）、`/include/getconfig.h`（1 处）。

## `pettrainer` 的 `say_news()` 读不到 `/log/news` 就抛错（2026-10-20，KB 06 §7.326）

`str = read_file("/log/news"); flag = sizeof(explode(str, "\n"));`：`/log/news` 是运行中写出来的新闻频道记录，全新的树里没有，`explode(0)` 报错；宠物训练师的 `chat_msg` 调它，每次都出错。读不到时 `flag = 0`，读出的 `news` 不是字符串就直接返回。三份相同。加载检查各 1/1。

## `register` 指令编译不过：`main()` 里粘进了登录流程的代码（2026-10-20，KB 04 §6.25）

`main()` 开头有两段 `if (yn == "") { ... input_to("confirm_id", ob); }` 和 `if (yn[0] != 'y' ...) { ... input_to("get_id", ob); }`：`yn` 和 `ob` 是登录程序里 `confirm_id()` 的变量，这里没有声明（`Undefined variable 'yn'`），登记表指令从来没有加载过。删掉这两段，留下 `display()` 和对代号的提问（后面的 `a()`……`g()` 逐项提问本来就是这条流程）。加载检查：HEAD FAIL → tree PASS。

## `top` 指令编译不过：`o->query("spi")`（2026-10-20，KB 04 §6.25）

`score += o->query("spi") / 2 + ob->query("cps") / 2 + ...` 里的 `o` 是 `ob` 少打了一个字母（`Undefined variable 'o'`）；wqfy 和 xhcii 的同一行是 `ob->query("spi")`。加载检查：HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 4 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/fy/npc/oldgun.lpc`、`/d/xgchen/shounao.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 38 个存档共 38 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/residence/baiyun982545370.o`（1 处）、`/p/residence/bibi950532639.o`（1 处）、`/p/residence/bll951500300.o`（1 处）、`/p/residence/bll951517371.o`（1 处）（等共 38 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/sleepwith.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。
