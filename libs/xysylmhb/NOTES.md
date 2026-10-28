
## WASM 修复摘要（迁移自 meta.json 的 group_note）

夕阳三-炎龙美化版（夕阳再现III 之 炎龙封印，AKAI Studio）。和 xyj2006 家族一样有 'version '/'2060' 的 Tomud 客户端握手闸门（第一行回复必须是字面的 '2060'）。注册流程没有 'new' 关键字（任何全新 id 都会问 y/n 新角色确认，和 xyj451 一样）；天赋是菜单选栏位（1-4 自定单项属性，0 系统随机整组，然后 y/n 确认接受）。WASM 修复靠 scripts/lib_bulk_fix.py + scripts/scan_known_bugs.py 在第一次启动测试之前就主动抓出来：标准的 §8.1 check_legal_name() i%2 奇偶门槛/[i..<0] 后缀切片（is_chinese() 本身已经是正确的逐码点写法）改成了 name[i..i]；master.lpc 的 valid_read()/valid_write() 缺少 'user == this_object()' 短路判断（已主动补上，和这份档案自己原有的、通过 previous_object() 实现的局部保护并存）——和 xyj20032 上曾经静默弄坏每一次注册的那个潜伏风险一模一样。adm/daemons/network/dns_master.lpc（真正生效的 DNS_MASTER，已通过 net/daemons.h 确认）本来就已经在 preload 里被注释掉（原来就是这样，休眠状态）——还有一份没有引用的死代码副本 adm/daemons/dns_master.lpc 也带有原始 socket 呼叫，但从未被加载。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（SECURITY_D 正确指向 securityd.lpc，真的会读取 WIZLIST——globals.h 里另一个 'securd' 路径是注释掉的，这里没有 §7.56 的歧义问题）。注册流程在一次连续的 WASM 客户端会话里完整验证过：版本握手（2060）→英文 id→y（确认新角色）→中文名字→密码+确认→0（随机天赋）→y（接受）→电子邮件→性别（m/f）→在客店进入游戏世界，look/score 都干净。管理员权限已通过"您目前权限：(admin)"确认。LPC 格式化工具对全部 8302 个档案运行（写入 8205 个，64 个转档之前就存在的未结束字符串/文本块内容错误未做格式化——是这一批里最杂乱的一份代码库——33 个未改动）。没有 :: 父类呼叫拆分命中；一处 CJK 重新加空格命中（d/city/sj.lpc）确认是和 tybxjh/xhcii 手足档案上见过的同一处转档之前就存在的缺失引号损坏，已还原；两处 case 标签带尾随注释的命中（cmds/bakcmds/csc.lpc、cmds/bakcmds/meskills.lpc，都是死代码备用指令副本）经 diff 复核干净。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，同时也是这份档案第一次真正的 §10.7 深
度游玩测试（此前只做过 WASM 阶段的注册流程验证）。这份档案的连线
握手比较特殊：`get_id()` 要求连线后的第一行输入必须是字面
的"2060"（Tomud 专用客户端协议握手，不是真正的英文 id 提示，尽管
显示的提示文字写的是"请输入您的英文名字"），之后才是真正的
id→y→中文名→密码 ×2→天赋(0)→接受(y)→email→性别 流程。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master
   file）完全没有严重度检查（AGENTS.md §7.34-class）**：已加上
   `strsrch(message, "arning:") == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **§8.9 食物/饮水初始化判断的对象错了**：`adm/daemons/
   logind.lpc` 的 `enter_world()` 里 `ob->query("age") == 14`（应为
   `user`，且这份档案的写法比其它手足档案更简化——连
   `!user->query("food")` 这层"只在从未初始化时才补发"的保护都没
   有，只单纯判断 age）。已改成 `user->query("age") == 14`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`；`d/huashan/npc/refereew.lpc`/`referee.lpc` 未用到 `%`，不适
  用。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整注册流程（含"2060"握手）创建，落地"铁枪庙"，
`score` 显示"【天界总管】"头衔，食物/饮水满格。随后**单独一步**做
了真实断线重连+密码验证（同样先发"2060"握手）：用刚设的密码重新
连线成功登录，存档数据一致。全程 `debug.log` 无运行时错误（连线过
程中出现的 `bnway`/`lbadd0`/`ptext` 之类原始字符串是 Tomud 客户端
专用的带外控制标记，正常客户端会解析成小地图/状态栏 UI，不是
bug，用原始 socket 客户端测试时会看到字面文字属于预期噪音）。驱
动按精确 PID 结束；管理员存档已提交。

## 深度功能测试（2026-08-18，round three）——冷启动 §7.90、死亡室
§7.112、cat() 缺失文件三个真实 bug

本轮目标是在 round two 覆盖面之外做更深的玩法回路测试：留言板、移
动探索、拜师、战斗/死亡/转世、断线重连穿插在死亡对话链中间。按标
准清单主动核对了四个跨库高发 bug 形状（§7.111 / §7.112 / §7.113 /
`logind.lpc enter_world()` 的 `ob->save()`）。

### 发现并修复的 PROGRAMMING bug

1. **§7.112：死亡室白无常/黑无常 NPC 的 `init()` 无重复触发保护**
   （`d/death/npc/wgargoyle.lpc`、`d/death/npc/bgargoyle.lpc`）：两
   者的 `init()` 都无条件 `call_out("death_stage", 5, ...)`，玩家
   进入死亡室后若中途断线重连（`enable_commands()` 会让驱动对房间
   内每个物件重新广播 `init()`），会在原有对话链之外再叠加一条新
   链，导致对话重复、甚至 `reincarnate()` 被调用两次。已仿照
   `libs/sj/work/d/death/npc/wgargoyle.lpc` 已确立的修复手法，加上
   `set_temp("death_stage_active", 1)` / `query_temp(...)` /
   `delete_temp(...)` 门闩，在 `death_stage()` 的**每一个**退出点
   （消失、非幽魂反杀、转世完成）都清空标记。**现场验证**：用
   `call <id>->die()` 强制测试角色死亡进入死门关，在对话链进行到
   一半时主动断开 socket 模拟掉线，再重新连线——续接的对话没有从
   头重播（未见重复的"喂！新来的"开场白），链条按原节奏继续到转
   世完成，`你共死亡` 计数每次死亡只加一，`debug.log` 全程干净。
2. **`adm/simul_efun/file.lpc` 的 `cat()` 缺文件存在性检查（
   §7.11-class）**：`file_size(file) < __LARGEST_PRINTABLE_STRING__`
   对不存在的文件（`file_size()` 返回 -1）恒真，于是
   `write(read_file(file))` 里 `read_file()` 返回 0，`write(0)` 触
   发 `Bad argument 1 to receive()` 运行时错误。触发路径：
   `get_id()` 对非 Tomud 客户端连线断线前会 `cat("/adm/etc/
   new.txt")`，而这份档案里这个文件本来就不存在——也就是说**每一
   次**普通 telnet/非 Tomud 客户端连线尝试都会在 `debug.log` 里留
   一条运行时错误。已加 `if (file_size(file) == -1) return;` 前置
   判断。**现场验证**：修复后用原始 socket 发送非法握手字符串，
   连线被正常拒绝且断开，`debug.log` 无新增错误。
3. **§7.90：`config.fluffos` 的 `maximum evaluation cost` 只有本
   项目模板默认值 `700000`（此项目 30+ 档案已经统一提升到
   `5000000`），冷启动第一次真实登录时在 `enter_world()` 里编译
   `/clone/cloth/cloth`（首次登录送的新手服装）触发
   eval-cost 超限，且**这一级超限是不可 `catch()` 的**（`debug.log`
   出现 `*Can't catch eval cost too big error.`，driver 的硬保护机
   制），导致整个 `enter_world()` 被中断在 `user->move(startroom)`
   之前——玩家永远没有被放进任何房间，卡在"你的四周灰蒙蒙地一
   片，什么也没有"的虚空里，`look`/移动全部失效，且不会自愈（
   每次冷启动后第一个撞上这条路径的玩家都会中招）。这正是本项目
   `hhsj` round three 记录过的同一类根因（`get_char()`/
   `make_body()` 冷编译被打断），只是这次撞在 `enter_world()` 的穿
   衣逻辑上。**修复**：`config.fluffos` 的 `maximum evaluation
   cost` 从 `700000` 提升到 `5000000`（沿用项目内已确立的标准值）
   ；另外把穿衣逻辑拆成独立的 `give_starting_cloth()` 函数并用
   `catch()` 包起来（防御性加固，仿照同一函数里
   `catch(load_object(startroom))` 的既有写法——虽然这一级
   eval-cost 超限本身不可捕获，但如果未来某次是较轻的、可捕获的
   超限，这层 `catch()` 能避免连锁中断整个 `enter_world()`）。**现
   场验证**：杀掉旧驱动进程、彻底重启一个全新驱动，用同一账号做
   第一次真正登录（此前正是这个场景 100% 复现问题）——现在干净落
   地在真实房间（"武庙"），有正常出口，`debug.log` 全程无
   eval-cost 错误。

### Proactive checks（清单核对，无需改动）

- §7.111（`adm/obj/master.lpc` 的 `standard_trace()`）：已经是
  `objectp(error["object"]) ? file_name(...) : "<none>"` 的三元表
  达式写法，不适用。
- §7.113（netdead 重连未恢复 heart_beat）：真正生效的重连路径是
  `adm/daemons/logind.lpc` 的 `reconnect()`（当
  `find_body(id)->query_temp("netdead")` 为真时，`get_passwd()` 会
  转发到这里），它调用 `user->reconnect()`，即
  `clone/user/user.lpc` 里的 `nomask` 版本，正确执行了
  `enable_commands()` + `set_heart_beat(1)`，不是死代码，不适用。
- `logind.lpc` 的 `enter_world()`：`ob->save()`（第 662 行附近）
  正常存在，未被注释掉，不适用。

### 其它已测试、无异常

- 留言板：`look board` / `read board` 正常；`post <标题>` 命令的
  语法核实（需要标题作为参数，不是分步 input_to），发帖本身受
  `literate` 技能 ≥101 的门槛限制（`inherit/misc/bboard.lpc`），是
  正常设计门槛，未强行绕过测试。
- 移动/探索：夜晚"天色太黑看不清出路"只是氛围文字，不阻挡实际移
  动。
- 拜师（`bai`）：对非门派 NPC（"魔法师"）正确拒绝"既不属於任何门
  派，也没有开山立派，不能拜师"，是设计判断，不是 bug。
- 战斗/死亡/转世全链路：用管理员 `call <id>->die()` 强制触发死
  亡（`smash` 命令本身设计上禁止对未成年角色/玩家生效，是保护设
  计不是 bug），确认死亡→鬼门关→白无常五段对话→转世→回到武庙的
  完整链路正常，死亡次数计数正确递增，转世后精/气各恢复一半（正
  常设计惩罚）。

### 测试账号

`xytestc`/`Test@2026`、`xytestd`/`Test@2026`（两个新注册测试账
号，事后已清理存档，未纳入提交）。管理员 `fluffos`/`Mud@2026` 存档
的死亡次数/位置在测试过程中被改动，已用 `git checkout` 还原到测试
前状态，不纳入提交。

### 潜在的跨库扫描候选（未在本次任务范围内处理其它档案）

- **§7.112 死亡室 NPC 无重复触发保护**：本档案的 `wgargoyle.lpc`/
  `bgargoyle.lpc` 是这个 bug 形状的又一个实例（本日已在 11+ 个其
  它档案发现并修复过同类问题），建议按已有的跨库清单继续排查其它
  尚未测试的档案。本档案里同一 bug 形状（`init()` 里无条件
  `call_out()`）在 kungfu/quest/d 目录下还有约 400 处命中，但多数
  已经用 `remove_call_out()` 自清或 `query_temp` 门闩规避了重复
  触发（437 处命中里 371 处已有防护），只有死亡室这两处是真正会
  引发"双倍转世"级别后果的高危实例，其余约 66 处未加防护的多是
  NPC 自身的学技能/巡逻自计时器，量级和后果都小得多，本轮未逐一
  处理。
- **§7.90 config.fluffos eval-cost 过低**：`700000` 是本项目模板
  默认值，这份档案原来也是这个值，已知至少 `hhsj`（round three）
  和 `cctx` 也用同一默认值——`cctx` round three 报告未记录到同类问
  题，可能只是运气好没撞上，值得在其它仍是 `700000` 的档案里主动
  核查 `config.fluffos`，而不是等一次真实的冷启动踩雷才发现。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,070 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug，
和手足档案 `yzxiiizylfy`/`xyzxiiylzymh`/`xyzx3` 同源（同一双
roommaker 副本血统）。用 `fix_710_room.py` 扫过 `work/`，删除
2,068 处标准形状；两份房间建造工具（`clone/misc/roommaker.lpc`、
`d/huanggon/obj/roommaker.lpc`）各剩 1 处字符串拼接变体，手工改成
`str += "\n\tsetup();\n}\n";`。修复后 `work/` 下 0 处存活残留，
`work/data/` 下没有真实 `.lpc` 源码命中。`git diff --stat` 显示
2068 个文件净删 2070 行、增 2 行，与脚本自报数字 + 2 处手工编辑
吻合。

驱动干净启动（零新增编译错误、端口 40169 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`/
`Mud@2026`（'2060' Tomud 客户端握手）实机登录成功，`look`/
`score`/`quit` 均正常，全程 `debug.log` 保持干净。管理员存档的时
间戳漂移已用 `git checkout HEAD --` 还原，未提交。驱动按精确 PID
结束。

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

## 深度功能测试（2026-08-24，round four）——补测商店购买 + 拜师成功链路，发现并修复动态任务系统的 `.c`/`.lpc` 转档崩溃

重新审计本档案历史后发现两个此前从未真正测试过的缺口：商店购买
（`buy`）从未测过真实交易，以及拜师此前只测过对非门派 NPC 的拒绝
路径，从未走通过一次真正成功的拜师。本轮针对这两点补测，过程中
额外发现并修复了一个真实的 PROGRAMMING bug。

### 发现并修复的 PROGRAMMING bug

**`adm/daemons/questd.lpc` 动态任务系统的 `.c`/`.lpc` WASM 转档遗留
崩溃（`spread_quest()` 对 `new()` 失败无判空）**：`spread_quest()`
第 111-112 行 `tar = new(quest); tar->set("value", 0);` 对
`new(quest)` 的返回值没有做判空检查。`quest` 来自
`d/obj/quest/dynamic_quest`/`dynamic_location` 两份数据文件，这两
份文件里全部 218 条物件/房间路径都还是转档前的字面 `.c` 后缀（例
如 `/d/obj/quest/tieluohan.c`），但转档后所有源码文件都已经改名成
`.lpc`，导致 `new(quest)` 恒定加载失败返回 `0`，随即
`tar->set(...)` 就是对整数 `0` 做 `call_other()`，触发
`*Bad argument 1 to EFUN call_other()` 运行时崩溃。**实际触发路
径确认**：这不是冷门代码——`cmds/std/give.lpc` 的 `do_give()` 每
次 `give` 指令都会经 `/inherit/quest.lpc` 的 `quest_give()` 调用
`"/adm/daemons/questd"->quest_reward(...)`，这是本次驱动会话里
`questd.lpc` 第一次被字符串调用加载，触发它的 `create()` →
`init_dynamic_quest(1)` → `spread_quest()`，在真实测试中一给玩家
钱就当场崩溃、`give` 指令本身也被中断。`init_dynamic_quest(1)` 也
会被 `adm/daemons/cron.lpc` 周期性调用（`already_spreaded(str, 1)`
在硬刷新模式下恒定返回 0，不会跳过），意味着这条崩溃路径不需要
玩家操作也会在每次冷启动后周期性复现，是这份档案里核心游戏机制
（世界随机任务物品投放）事实上完全没有工作过的根因。**修复**：
机械地把两份数据文件里所有以 `/` 开头、以 `.c` 结尾的路径行改成
`.lpc`（`dynamic_quest` 30 行、`dynamic_location` 186 行），逐一
核对转换后每条路径都能在档案里找到对应的真实 `.lpc` 文件（各 30/
188 条中分别 30/152 条精确匹配成功）。**现场验证**：修复前用
`give coin to <玩家>` 稳定复现崩溃（含完整调用栈，定位到
`questd.lpc:112`）；直接用 `call` 指令传入 `.lpc` 路径调用
`spread_quest()` 验证不崩溃且返回 1，确认根因；应用修复、重启全
新驱动后，同样的 `give` 操作干净执行，`debug.log` 全程无新增运行
时错误。

**范围边界（未处理，判定为转档前就有的原始数据问题，非本次转档
引入）**：`dynamic_location` 里另有 38 条路径就算换了 `.lpc` 后缀
依然找不到对应文件——35 条是 `/d/quanzhou` 系列缺失路径分隔符的
拼写错误（如 `/d/quanzhoubamboo.c` 应为 `/d/quanzhou/bamboo.c`）、
`/d/baituo/ouyangfeng.c` 对应的房间文件本身在转档前就已经不存
在、以及两条 `/d/xueshan/tulu2`/`tulu3` 从未带过任何后缀。逐一核
对 2006 年原始 raw 源码（`raw/夕阳再现III/.../world/d/obj/quest/
dynamic_location`）确认这三类问题字节对字节地在原始档案里就已经
存在，不是转档引入的回归。而且这类"位置"路径加载失败时
`spread_quest()` 里 `cur_obj` 会保持 `0`，函数体在
`if (cur_obj) {...}` 保护下直接跳过、正常 `return 1`，不会崩溃
（已用 `call questd->already_spreaded(...)` 验证同一对象的重复调
用不产生异常）——按项目"只修程序错误，不动内容/原始数据"的口径
未做改动，留档说明。

### 商店购买（`buy`）——首次真实交易测试

新注册测试角色 `xytestf`（中文名"浮浮六"，男性，落地"铁枪庙"，
`/d/quanzhou/tieqiang`）没有任何随身现金（`logind.lpc` 的
`init_new_player()` 只有女性角色会拿到 `money`——该属性其实是"钱
庄存款"，`score` 里显示的银行余额，不是可花现金，与本次购买测试
无关，是原始设计如此，不是 bug）。管理员用 `clone`/`call
coin->set_amount(250)`/`give` 给测试角色 250 个铜板（同一操作过
程正是上面撞见的 questd 崩溃发生的地方，验证过修复后干净执行）。
角色移动到 `/d/quanzhou/zahuopu`（杂货铺，NPC `陈阿婆`，继承
`F_DEALER`），`list` 正确列出五件货品及单价，`buy xiuhua zhen` 用
250 个铜板买下一根标价"一两白银"（100 文）的绣花针：交易后 `i`
显示扣款后找零为"一两银子 + 五十个铜板"（250-100=150，
150/100=1 两银子余 50 文，找零算法正确），物品正确出现在背包
里。购买流程本身（`feature/dealer.lpc` 的 `do_buy()`）逻辑正确，
无需修复。

### 拜师（`bai`）——首次成功链路测试

此前只测过对无门派 NPC 的拒绝路径。本轮选定
`d/city3/npc/chen.lpc`（丐帮成都分舵舵主陈玉林，`attempt_apprentice()`
仅要求 `int < 25`，测试角色 `int` 为 24，满足条件）。移动测试角色
到 `d/city3/ruin2`（丐帮分舵），执行 `bai chen`：陈玉林同意收徒、
自动执行 `recruit`，角色下跪磕头，系统提示"恭喜您成为丐帮的第二
十代弟子"。`score` 复核：头衔变为"叫化子"，称谓变为"丐帮第二十
代弟子"，"你的师傅"字段正确显示"陈玉林"。`recruit_apprentice()`/
`assign_apprentice()`（`feature/apprentice.lpc`）逻辑正确，无需
修复。

### 测试账号

`xytestf`/`Test@2026`（新注册测试账号，测试完毕已 `quit` 并删除
存档文件，未纳入提交）。管理员 `fluffos`/`Mud@2026` 因本轮临时持
有的铜板道具及在线时间/食物饮水漂移，已用 `git checkout` 还原，
未纳入提交。驱动两次启动均按精确 PID 结束。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`, `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`quest/dynamic_location` 里 18 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/taskd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/taskd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 1 个，工作树三次分别通过 1、1、1 个（共 2 个），无回退；`adm/daemons/taskd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。
验证：改动过的 `adm/daemons/questd.lpc`、`adm/daemons/taskd.lpc`、`cmds/look.lpc`、`cmds/std/look.lpc` 在新进程里加载，HEAD 通过 3 个、工作树通过 3 个（共 4 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py xysylmhb --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 329 个 `.lpc` 和 3 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：312 -> 312 通过，无回退；改过的头文件的 34 个包含者 34 -> 34 通过。启动时警告 8 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/wiz/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 11 处，返回类型/原型 22 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 34 个文件，HEAD 与工作树各载入一次无回退（34 objects; HEAD PASS 34, tree PASS 34; regress 0; newly loading 0），这些文件的警告 34 -> 0。

## 编译警告收尾（2026-10-12）

孪生库 xyzx3 同日的整理（e4c410f629c：冗余继承 7 处，三个书房/房间的 `STORY_DIR` 前 `#undef`，`kungfu/skill/huashan-jian.lpc` 多余的 `;`）用 `scripts/lpc_twin_port.py adopt xyzx3 xysylmhb --pre e4c410f629c~1` 搬来，11 个文件与 xyzx3 修前逐 token 相同，清单里的警告全部落在这些文件里。HEAD 与工作树各载入一次：11 个对象，HEAD PASS 10，tree PASS 10，regress 0。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 5 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。12 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`quanzhen-jian`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## iceforce「chillgaze」从未编译通过（2026-10-15）

`iceforce/chillgaze` 原档在第一个 `return notify_fail(...)` 后多了一个 `}`，`exert()` 就此结束，后面的语句全落在函数外，`skill`、`damage` 也没有声明，文件编译失败，这个 exert 从来用不了。照 bixiecanyang、hc、xyzx3 已修好的版本删去多余的 `}`、补上 `int skill, damage;`，其余字句不变，只是缩进进函数体。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事要离开时报错，留在原地（`d/city2/npc/liling2` 本身还载入不了：`create()` 里 `carry_object()` 的物品文件缺失或编译失败，见 KB 06 §7.73，另行处理）；婚礼最后一步（`d/nanyang/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了；喜宴结束、礼金付出之后，喜来福（`d/nanyang/npc/xi-laifu`）退回内堂时报错，留在楼上。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

15 个文件、19 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city2/obj/killerbian`、`/obj/cloth/cloth`、`/obj/weapon/blade`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 13 个（13 个原来载入不了），没有退步；其余 2 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/sssinventory.lpc`、`feature/ymove.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`WQA_ROOM` → `/quest/game/wqa_room`（80 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：80 个里 80 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（4 个名字，最多的是 `yiyang`、`hunyuan-force`、`ruyi-blade`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 17 处、16 个文件：`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`poyu-qua`→`poyu-quan`（1 处）、`hanbing-mainzhang`→`hanbing-mianzhang`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/u/zjb/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 2 个 NPC 文件、2 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 开封擂台头文件的重复全局变量（2026-10-19，KB 04 §6.10）

`d/kaifeng/ground.h` 里的 `modes`、`mode_hints`、`families` 三张表被 `ground0.lpc` 和继承它的 `ground1/2/3.lpc`、`ground.lpc` 各包含一次，每次 `inherit` 都报 `Redeclaration of global variable`。表只放在 `ground0.lpc` 里：头文件用 `#ifndef GROUND_TABLES_INHERITED` 包住表，继承的几个程序在 `#include "ground.h"` 前 `#define GROUND_TABLES_INHERITED`（与 xiyouji 系其余库同一改法）。改后警告消失，与 HEAD 逐个对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_bian.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen/obj/m_sword.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 8 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（cctx）、`/d/city2/npc/zhengmen.lpc`（jqxz2008）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/kungfu/skill/guxing-sword.lpc`（xyzx3）、`/kungfu/skill/huang.lpc`（bixiecanyang）、`/quest/baituo/qlist3.lpc`（xyzx3）、`/quest/murong/qlist3.lpc`（bixiecanyang）。修后与 HEAD 逐个对比载入：这 8 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 玩家买店用的 `feature/vendor_sale.lpc` 补回（2026-10-19，KB 03 §4.6 第四轮）

`/feature/vendor_sale.lpc`（`/kungfu/class/npc/xiaoer.lpc` 继承它）从 `pay_back` 起约 160 行的行尾丢了最后一个字符（`;` `)` `{` `}`，`else {` 只剩 `els`，`msg` 只剩 `ms`），另有一行 `if(wizardp(who) || getuid(who)==owner_id)` 被拼进了前面的 `log_file(` 调用里。文件载入失败，继承它的物件也跟着失败。别的库（ldtx、ldtxii、xhcii、syxjl、hy3）里有这个文件的完好副本，但那是另一个版本：没有作者后来加的投标公告（`string mesg;` 和 `message("channel:chat", ...)`）。所以按完好副本补回丢失的字符（`scripts/lpc_restore_from_twin.py --diff --extra`），公告两段原样保留；被拼到别处的 `if(...)` 放回完好副本里它所在的 `write("\n盈利` 之前；`message_vision("channel:chat", ...)` 多出来的第一个参数删掉（`message_vision` 的签名是 `(string, object, object)`，每次 `bid` 在扣完款之后都会报错）。补完后文件和继承它的物件都能载入，没有警告，也没有退步（HEAD 上两个都载入失败）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/haojie/npc/tianshaxing.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `tail` 指令：`tail(file)` 驱动里没有（2026-10-20，KB 06 §7.291）

`cmds/*/tail.lpc` 调用 MudOS 的 `tail()` efun，FluffOS 没有，指令编译不过。模拟 efun 文件里补了 `tail(file)`（Discworld 家族的兼容版：文件最后约 20 行，从完整的一行开始，存在返回 1；`scripts/lpc_add_sefun.py tail`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `wabaod` 的藏宝线索按双字节算（2026-10-20，KB 06 §7.307）

天书的线索由 `adm/daemons/wabaod.lpc` 在房间描述里挖空若干个字：`desc = long[begin..begin + 60]`（按 GB 的 61 字节）、`desc[b..b + 1] = "■"`（两个字节换两个字节）。驱动的字符串是 UTF-8，区间按字符数：窗口成了 61 个字符，每次替换把两个字符换成一个，字符串越换越短，后面的偏移越界，启动时 `push_lvalue_range: invalid ind2`（随机出现，`init_xunbao` 的每次 call_out 也会）。改成按字符算：30 个字符的窗口，每处挖一个字（`scripts/lpc_fix_wabaod.py`）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `quest/dynamic_room` 的 `.c` 行：任务守护进程加载不了（2026-10-21，KB 06 §7.341）

任务守护进程（`adm/daemons/taskd.lpc`）的 `create()` 读 `/quest/dynamic_room`（琉璃庄的 19 个房间，`/d/llzhuang/lou0.c` ……），`clear_room()` 对每一行 `load_object()` 再 `room->reset()`：显式的 `.c` 按原样解析（KB 03 §4.2），档案里的房间是 `.lpc`，`load_object()` 答 0，`0->reset()` 让 `create()` 中止，守护进程没有加载（HEAD 加载失败，改后通过）。2026-10-05 的 `.c` 行扫描只认 `dynamic_location*` 和 `dynamic_quest*` 两种表，`dynamic_room` 和 `dynamic_npc_quest` 没有扫到；`scripts/lpc_dynamic_rows.py` 现在认四种，这 19 行改成 `.lpc`（本库档案里没有的行照旧不动）。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## 谷物加工厂 `goldwork2/3/4`：工作太久被赶出去时 `ob->move(..)`（2026-10-21，KB 06 §7.348）

`working()` 在连续工作次数超过 60+random(100) 时，运气低于 25 的人被送回广场：`if ((int)me->query("kar") < 25) ob->move("/d/city/guangchang");`，`ob` 声明了没赋值（同一目录的 `goldwork.lpc`、`goldwork5.lpc` 写的是 `me->move`）。抛错在 `me->set_temp("working", 0)` 和 `cot--` 之前，房间里的工人计数漏掉一个，三次之后“人手已经够了”永远不再收人。改成 `me->move(..)`，去掉 `object ob;`。改动：`/d/city/goldwork2.lpc`、`/d/city/goldwork3.lpc`、`/d/city/goldwork4.lpc`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 34 条注册（30 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/player/yysz/hupan.lpc`（`do_han`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`）、`/d/quanzhen/npc/qizhicheng.lpc`（`do_decide`）、`/d/quanzhen/npc/sunbuer.lpc`（`do_decide`）、`/d/quanzhen/npc/wangchuyi.lpc`（`do_decide`） 等共 30 个文件。最多的函数名：`do_send` 15 处、`do_decide` 7 处、`do_faint` 5 处、`do_jump` 1 处、`do_sell` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 1 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（9 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（inquiry 2, item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/city/npc/zhuziliu.lpc`:`give_job`、`/d/city/npc/zhuziliu.lpc`:`task_ok`、`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

1 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/d/mj/obj/baihong-jian"->move()`（`/d/mingjiao/npc/yingwang.lpc`）→ `"/d/mingjiao/obj/baihong-jian"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。 其中殷天正（白眉鹰王）的 `do_answer()`：玩家念对暗语（`answer 怜我世人，忧患实多；保护教主，同抗外敌`）时把白虹剑 `move` 给玩家，区域目录改名 `mingjiao` 之后这个路径没跟着改，回答暗语只得到 `couldn't find object`，剑永远发不出来。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 20 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 20 处（15 个文件）：拼名字的赋值 12 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:101`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`name[0..3]` → `name[0..1]`（`/quest/imp/xquest.h:97`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：10 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 10 处（5 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/bakcmds/csc.lpc:611`）；`if (strlen(arg) < 2 || strlen(arg) > 30)`（`/d/player/fan_room.lpc:115`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 5 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 5 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 4 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。


## hanbing `random 反引号（2026-10-27，KB 04 §6.25 Also）

`hanbing-mianzhang` / `hanbing-mianzhang2` 在 `random(` 前多了一个反引号，驱动按模板字面量读到 EOF。删掉。证明：HEAD 失败；改后加载。

## set("long" 丢引号（2026-10-27，KB 04 §6.25 Also）

`set("long",` 后直接跟汉字（无 `"` / `@LONG`），驱动报 Illegal character。用同路径完好手足覆盖（fyue_room←jhfy；hudi5/6←zxty08nxgbb；quanzhen_old/hudi*←xyzxfy2）。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 d/city/sj 去引号）

`d/city/sj` 整文件去引号（`add_action(do_out, out)` 等）；按 jhfy 完整副本替换。

## 深度功能测试（2026-10-27，§6.25 zhongling tell_object 引号错位）

`d/wanjiegu/npc/zhongling`（及同路径副本）的 `tell_object("who, 钟灵脱下一双绣花鞋。\n")` 把对象参数写进了字符串；改为 `tell_object(who, "…")`。证明：原文错位；改后加载，语料残渣 0。
