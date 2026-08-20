
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
