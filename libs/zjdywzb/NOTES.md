
## WASM 修复摘要（迁移自 meta.json 的 group_note）

终极地狱完整版（游戏内横幅：EMPEROR OF ULTRA HELL(BLOOD & MAGIC) FROM 2002.06.2），和本次会话已经处理过的 zjdy2008wzb 同属一个 Doing 血统 'hell' 家族——master.lpc/logind.lpc/named.lpc 结构几乎一致（原始压缩包内部文件夹字面就叫 'hell'）。WASM 修复了：（1）经典的 §8.1 GBK 字节区间 is_chinese()（用 161/255/176/248 阈值和 i%2 奇偶判断做 str[i] 字节对检查）重写成逐码点 0x4e00-0x9fff 检查；check_legal_name() 对应的界限（最小值 2→1，没有减半的 maxlen → maxlen/2）也做了相应修复。（2）master.lpc（adm/single/master.lpc）的 valid_read()/valid_write() 缺少标准的 'user == this_object()' 保护——两处都已加上。（3）get_name() 里姓+名合并的最小长度检查（strlen(fname)<4，字节数翻倍）和 named.lpc 的 invalid_new_name() 滑动窗口近似名字去重（最小值 2→1，窗口切片 name[i..i+3]/name[i..i+5] → name[i..i+1]/name[i..i+2]，循环界限 l-4 → l-2，闸门 i+6<=l → i+3<=l）都修复成减半后的逐码点界限，和 hell 家族的先例一致——不修的话，单字姓氏和任何两字全名都会被拒绝为'太短'。（4）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了 11 处呼叫点（kungfu/skill/*.lpc 的 suck/tan/zhua/hua/huolang 档案、clone/user/user.lpc、d/city/npc/guidao.lpc、cmds/std/ansuan.lpc、cmds/std/surrender.lpc）。（5）versiond.lpc（2194 行，比 zjdy2008wzb 那份更大更完整的构建同步版本精灵，但属于同一类 socket 精灵 bug）通过 logind.lpc 在 logon() 里直接、未加保护的 VERSION_D->is_version_ok()/query_temp() 呼叫在每一次连线时都能触达，即使它不在 adm/etc/preload 里——按照 AGENTS.md §7.52 掏空了 in_server()、connect_server()、clear_syn_info()（只掏空 socket_close 循环）、send_command()、send_client_pending_msg()、syn_finish()（只掏空 socket_close）、in_listen_callback()、in_write_callback()、in_close_callback()、cmd_close()、send_pending_msg()、send_result()、remove_connection()（只掏空 socket_close）里所有真正的 socket_*() 呼叫点；已确认没有残留的原始 socket_*() efun 呼叫，且大括号配平（145==145）。adm/daemons/ftpd.lpc（117 处 socket 呼叫）和 adm/daemons/network/dns_master.lpc（5 处 socket 呼叫）都处于休眠状态（在 adm/etc/preload 里被注释掉，只有带保护的巫师指令呼叫者）——保持原样，符合 AGENTS.md §7.52 的指引。另外确认了从共享的 hell 源码带过来的一些既有修复本来就是对的：securityd.lpc 的 save_object valid_write() 检查本来就对照 query_save_file()+__SAVE_EXTENSION__，而且 SECURITY_D/preload 路径本来就正确，adm/daemons/securityd 已经排在预加载列表最前面。log/nosave/ 目录本来就存在（和 zjdy2008wzb 不同，这份档案没有撞上那个阻断启动的目录缺失 bug）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（和压缩包原有的 'doing (admin)' 条目并存）。注册流程在格式化前后都完整验证过（英文 id→y 确认→中文姓→中文名→管理员密码+确认→登录密码+确认→角色类型菜单（1-5，用的 5）→性别→进入世外桃源），管理员权限已通过'目前权限：(admin)'确认。这份档案的提示符会显示实时时钟（符合 AGENTS.md §8.3 第 1 条）——这里用 --idle 1.0 就够了，不像 zjdy2008wzb 需要 0.3。有一处转档之前就存在、非致命的'Bad argument 4 to EFUN message()'运行时错误在预加载期间和 quit 期间会反复出现（几个精灵的 create()/sys_info() 路径通过 channeld.lpc 呼叫 simul_efun.lpc 的 message()，传了一个整数 0 作为第 4 个参数）——不会阻挡启动、注册、或管理员权限验证；作为一个转档之前就存在的驱动 message() 签名怪癖保留，不在这次 WASM 修复的范围内。LPC 格式化工具对全部 7080 个档案运行（写入 7025 个，27 个转档之前就存在的错误，28 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。

## 深度功能测试（§10.7，2026-08-05）

这份档案和手足档案 `zjdy2008wzb` 都还没做过 §10.7 深挖，这次直接从
AGENTS.md 的已知 bug 类别清单出发逐项排查，而不是 sibling-check（因
为没有已深挖的手足可以参考）。

- **§7.88（本次新增）"非致命" message() 签名怪癖其实会把新手卡死
  在角色创建流程里，是全新角色永远无法通过的硬性 soft-lock**：WASM
  阶段的笔记把 `Bad argument 4 to EFUN message()` 记成"转档之前就存
  在、不影响启动/注册/管理员验证的驱动签名怪癖"，予以保留。这次实
  测发现它不是无害噪音——`adm/simul_efun/message.lpc` 的 `message()`
  包装函数声明了 4 个必填参数，直接透传给 `efun::message()`，但同一
  份档案里好几处呼叫只传了 3 个参数，缺的第 4 个参数被驱动静默填成
  `int(0)`，`efun::message()` 直接拒绝这种类型不对的调用而抛错。新
  角色创建流程里"选品质"一步（在"桃源石屋"对 NPC 花铁干 `out` 离开）
  的 `check_leave()` 恰好先呼叫了 `command("chat ...")`，这个 chat
  频道广播触发了同样的崩溃——而且这次崩溃发生在 `check_leave()` 内
  部、`valid_leave()` 判断房间是否放行"之前"，导致整条呼叫链被中断：
  房间不放行离开（角色永远卡在桃源石屋），紧跟着那行本该执行的
  `me->set("character", "阴险奸诈")` 也永远不会跑。也就是说**每一
  个新角色在人物创建的强制步骤上都会被卡死，反复输入 `out` 只会反
  复触发同一个崩溃**，是比"注册后指令表是空的"更隐蔽的一种"注册流
  程看起来正常，实际完全走不下去"的 bug（因为这条崩溃夹在一大串正
  常的注册提示文字中间）。修复：把 `message()` 包装函数声明成
  `varargs`，缺失的 `exclude` 参数补上 `|| ({})` 兜底（和同一个文件
  里 `tell_room()` 已经用的写法一致）。修复前反复 `out` 必现同一崩
  溃、角色永远留在桃源石屋；修复并重启驱动后，同样的房间、同样的
  NPC、同样的 `out` 指令一次成功，顺利走完"忘忧池洗天赋→born
  <地名>"全部剩余创建流程，第一次真正进入游戏世界。已更新
  AGENTS.md，新增 §7.88。
- **§7.89（本次新增）自带的 runtime_config.h 索引编号和驱动实际编
  号不一致，导致 get_config() 静默取到类型不对的另一个配置槽位，
  巫师账号登录时崩溃**：用巫师身份（`fluffos`，已经在 wizlist 里）
  登录时，密码验证通过后连线立刻卡死——`look` 等任何指令都不再有
  任何回应（连"什么？"都没有）。`log/debug.log` 显示
  `logind.lpc` 的 `check_ok()`（只有巫师登录才会走到）触发
  加载 `/adm/daemons/network/messaged`，其 `create()`→
  `startup_udp()`→`socket_bind(socket_id, my_port)` 报错
  `*Bad argument 2 to socket_bind() Expected: int Got: "10"`——
  `my_port = LOCAL_PORT() + MESSAGE_PORT` 本该是纯整数运算，但
  `LOCAL_PORT()` 依赖的 `get_config(__MUD_PORT__)` 里 `__MUD_PORT__`
  是 `CFG_INT(0)`，而这份档案自带的 `include/runtime_config.h` 用的
  是自己从零开始算的 `BASE_CONFIG_STR`/`BASE_CONFIG_INT` 编号，和这
  个驱动版本真实的内部配置槽位编号对不上（用
  `~/src/fluffos/src/include/runtime_config.h` 逐条 diff 确认，和之
  前 `ds386` 发现的"自带 runtime_config.h 编号错位"是同一类问题，
  但这次真的撞上了一次会崩溃的类型错配，而不只是取到空值/错误
  值）——`get_config(14)` 实际读到的是驱动内部第 14 号槽位的真实内
  容（一个字符串），导致 `my_port` 变成字符串 `"10"` 而不是数字端
  口号，`socket_bind()` 直接拒绝这种类型的第二参数并抛错，把
  `check_ok()` 从中间截断，登录流程永远无法完成。修复：直接把这份
  档案的 `include/runtime_config.h` 换成驱动自带的权威版本（旧版备
  份为 `runtime_config.h.orig_zjdywzb`），diff 出新旧版本符号差异后
  发现三处旧符号在别处仍被引用：`__SAVE_BINARIES_DIR__`（只在已经
  按 §7.52 掏空过的同步精灵里使用）→ 别名成 `__MUD_LIB_DIR__`；
  `__ADDR_SERVER_IP__`（`cmds/arch/config.lpc` 里一行纯展示用的巫师
  `config` 指令输出，这个驱动版本压根没有 addr_server 这个概念）→
  直接删除这一行而不是硬造一个假别名；`__PORT__`（`ftpdconf.h`/
  `versiond.lpc` 引用）不需要任何别名——这个驱动本身就把它当编译期
  预定义常量（`add_predefine("__PORT__", ...)`），重新 `#define` 反
  而会报"Illegal to redefine a predefined value"编译错误。修复并重
  启驱动后，`fluffos` 巫师账号登录、`look`、`goto` 全部恢复正常，
  权限正确显示 `(admin)`。已更新 AGENTS.md，新增 §7.89。
- **§7.86 留言板 `post` 崩溃同样适用，是第五个以上独立血统家族命
  中此形状**：全档案 43 处 `inherit BULLETIN_BOARD` + 多余
  `replace_program(BULLETIN_BOARD)` 致命形状，全部删除多余调用（未
  发现 sje 那种运行时代码生成模板变体）。修复并重启后，用巫师账号
  在"客店留言板"实测发帖，`post board` 全流程顺利完成（"留言完毕"），
  `look board` 确认帖子正确显示作者与时间戳。
- **§7.5/§8.9/§8.3a/§8.3b 均不适用**：ACL 已在 WASM 阶段修好；
  `enter_world()` 的食物/饮水初始化是无条件固定值，没有年龄判断包
  装；`command_hook()`/指令表健康，注册后 `look`/`score`/`kill`/
  `goto` 全部正常响应。
- **战斗测试**：新角色在南阳城对小贩发起 `kill`，双方多回合拳脚
  攻防判定正常（命中/闪避/擦伤消息、体力下降提示），血量降到危险
  阈值时角色自动逃跑到相邻的"大驿道"（这份档案自带的求生保护机
  制，属于设计行为，不是 bug），过程全程无崩溃。
- **死亡/复活测试未能完整走通，记录为本次已知限制**：尝试用巫师
  `smash` 指令秒杀测试角色（`ob->receive_damage("qi",1,me);
  ob->die();`），代码读到 `die()` 应该无条件把玩家送进
  `DEATH_ROOM`（`/d/death/gate`）并触发复活流程，但实测多次
  `smash` 后角色始终原地满血站着，未观察到任何死亡/复活画面。走读
  `combatd.lpc` 的 `player_escape()` 发现其中有一条基于
  `is_want_kill()`/`want_kill` 意图标记的"逃过一劫"随机分支，怀疑
  `smash` 这种非常规击杀路径没有正确设置该标记，导致这条保护分支
  被意外命中——但没有用 `call` 指令直接实测验证（巫师账号的 `call`
  指令被 `SECURITY_D->valid_grant(me,"(arch)")` 拒绝，"(admin)"权
  限在这份档案里似乎不自动满足"(arch)"授权，也没有深入排查这一
  点）。这是内容/设计层面的不确定性，不是本次确认的编程 bug，留给
  以后有需要时再深挖；`DEATH_ROOM->start_death(me)` 这个呼叫指向的
  函数在全档案里也没有任何定义（`->` 呼叫不存在的函数在 LPC 里静
  默返回 0，不会报错），是否有意如此（依赖 `me->move(DEATH_ROOM)`
  之后房间自身的 NPC/机制接手）也一并留待验证。
- **测试方法论上的两个新发现，已写入 AGENTS.md §10.2**：(1) 本地
  `telnet` 客户端经由 tmux 传输部分中文字符（如"者""考"）时会被传
  输层损坏，`is_chinese()` 误判为"不是中文"，换成 `mudclient.py`
  原始 socket 连线后同样的字符完全正常——不是驱动/mudlib bug，是
  测试工具本身的传输问题；(2) 这份档案的提示符带实时时钟，用
  `mudclient.py --idle 1.0`（等于时钟跳动间隔）会和每秒一次的时钟
  刷新赛跑，导致后续指令永远发不出去（`wash`/`born`/`score` 全部
  石沉大海），改用 `--idle 0.5` 后立即解决。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`，见 `include/globals.h`）在 2,310 处
房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后又多余地调用了一次
`replace_program(ROOM);`——和 AGENTS.md §7.100 记录的 `jhfy3`/其它
姊妹档案同一形状的休眠 bug：这个多余调用给对象打上永久的"pending
replace"标记，该对象一旦在生命周期里绑定任何闭包（`call_out`、
`edit()`、自定义 `input_to`、房间外的 `set(..., (: ... :))` 等）就
会崩溃。用已验证过的 `fix_710_room.py`（二进制模式，只删除内容严
格等于 `replace_program(ROOM);` 的独立行）扫过 `work/`，删除 2,309
处；剩余 1 处是房间生成工具 `clone/misc/roommaker.lpc` 里的
`str += "...replace_program(ROOM);..."` 字符串拼接变体，手工改成
`str += "\n\tsetup();\n}\n";`（同一工具另有一处 heredoc 模板已被脚
本正常扫到）。另有 21 处是转档之前就已经被注释掉的 `//` 行，原样保
留。`work/data/` 子目录下没有真实 `.lpc` 源码被脚本误跳过（唯一的
`work/data/room/moman/*.lpc` 4 个文件本身没有这个 bug）。`git diff
--stat` 确认 2309 个文件各删 1 行 + roommaker.lpc 1 处字符串编辑，
与脚本自报数字吻合。修复后真实驱动干净启动（零新增编译错误、端口
正常监听、`debug.log` 里没有任何"cannot replace"/"cannot bind"行），
巫师账号 `fluffos`/`Mud@2026` 实测走了 2 个曾经被注释触发过这个 bug
的房间（`d/city/library.lpc`、`d/mingjiao/shanlu3.lpc`）以及世外桃
源出生点，`look`/`goto`/`quit` 全部正常，无回归。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 死亡/复活谜团破案（§10.7 回合四，2026-08-20）

上一轮遗留的"多次 `smash` 都杀不死角色"谜团这次彻底查清楚了，真相
和上一轮的猜测（`combatd.lpc` 的 `player_escape()`/`want_kill` 逃脱
分支意外拦截）完全无关——用临时 `tell_object()` 插桩逐行追踪
`cmds/arch/smash.lpc` 的 `main()` 才发现真正原因：

- **根因：`is_admin()` 是一层独立于巫师身份的更高权限门槛，`smash`/
  `call`/`clone`/`summon`/`grant` 全部共用同一套 `!me->is_admin()`
  ⟹ `switch(SECURITY_D->query_site_privilege(cmd))` ⟹ 默认分支
  `return notify_fail(...)`（返回 0）的写法**。`clone/user/user.lpc`
  第 62 行 `is_admin()` 的定义是 `admin_flag == 1222 ||
  getuid() == "pkyou"`，和 wizlist 里的 `(admin)` 身份完全是两回
  事——注释原文写得很清楚："判断是否具有管理权限：如果是版本发布
  站点或是通过 PASSWD 命令设置过，则具有管理权限。具有该权限的巫
  师可是使用诸如 clone、call、log、smash、copyskill等命令。"
  `set_admin()`（把 `admin_flag` 设成 1222 的唯一途径）要求
  `is_root(previous_object())`，而全档案没有任何地方呼叫
  `set_admin()`——也就是说这份档案里除了硬编码的 `uid=="pkyou"` 后
  门，压根没有任何在游戏内可达的合法途径把 `admin_flag` 置为
  1222。`site_privilege` 是个空 mapping（只能通过巫师指令
  `set_site_privilege()` 写入，没人写过），所以 `smash`/`call` 里
  `switch` 永远落到 `default:` 分支，`main()` 静默 `return 0`。
- **`command_hook()`（`feature/command.lpc` 第 71-85 行）把"命令
  main() 返回 0"通用地当成"这个动词不是命令，接着试试当作
  emote"**：`find_command(verb)` 命中且 `call_other` 返回假值后，
  会依次 fallback 到 `EMOTE_D->do_emote()`。`data/emoted.o` 里刚好
  存在一个名字也叫 `"smash"` 的表情动作（"$P高举双手大喝：去死
  吧！从天上降下一道闪电将$n化作一堆灰烬。"）——这正是上一轮和这
  一轮反复看到的"看起来像是把目标劈死了，但角色毫发无伤"的假象来
  源：admin 指令 `smash` 因为权限门槛静默失败后，动词又被通用
  fallback 机制当成了同名表情来执行，纯粹是场面话，根本没有调用
  `receive_damage()`/`die()`。用 `look <target>` 复查过，目标确实
  "气血充盈，并没有受伤"。这不是 bug（`smash`/`call`/`clone`/
  `summon`/`grant` 的门槛写法、以及"动词 fallback 到同名 emote"都
  是一致、故意的设计），只是两层设计叠加出了一个极具迷惑性的假
  象。用插桩确认后已经把 `smash.lpc` 恢复成原样（`git checkout`），
  没有对这份档案做任何"修复"这层权限门槛的改动。
- **顺带查清楚了 `player_escape()` 到底是什么：只保护"玩家杀玩家"
  的场景，和 `smash`/NPC 杀死玩家完全无关**。`player_escape(killer,
  ob)` 一开始就要求 `playerp(ob)`（受害者是玩家）且
  `playerp(killer) && killer->is_want_kill(ob->query("id"))`（凶手
  也是玩家，且明确设过"想杀死你"意图标记）——`smash` 走的是
  `receive_damage()+die()` 直接调用，从不呼叫 `want_kill()`，就算
  `smash` 真的执行到底也不会触发这条逃脱分支；NPC 杀死玩家时
  `killer` 不是 `playerp`，同样永远不会命中。顺便观察到一处可疑但
  按项目规则不动的地方：`player_escape()` 顶部"今天是否已经用过一
  次逃脱名额"的节流检查读的是顶层属性 `combat/which_day`/
  `total_count`，但全文件唯一写入这两个键的地方是
  `winner_reward()` 里完全不同的嵌套路径
  `combat/today["which_day"]`/`combat/today["total_count"]`——这两
  组键名从未被真正写过，节流检查恒为假，逃脱分支理论上会对每一次
  符合条件的玩家杀玩家意图击杀都无限次生效。这看起来像一处真正的
  路径不匹配，但它只影响游戏平衡（PK 杀不死人），不产生任何编译
  错误/运行时崩溃/debug.log 错误/驱动拒绝，按 AGENTS.md 的判定标
  准属于"无错误信号=设计，不动"的范畴，本次不做任何改动，只记录在
  这里供以后需要时参考。
- **真正打通了一次完整的死亡流程，全程 debug.log 干净**：把
  `fluffos`（巫师账号，`(admin)` 身份但没有 `is_admin()` 神权限）
  用 `goto /d/guanwai/milin2` 送进 `d/guanwai/npc/dongbeihu.lpc`
  （东北虎，`attitude: aggressive`，`outdoors: guanwai` 房间进
  入即主动攻击）的地盘，纯粹靠真实战斗多回合打到死——依次看到
  "你的眼前一黑，接著什么也不知道了...."（昏迷）→"你扑在地上挣扎
  了几下，腿一伸，口中喷出几口鲜血，死了！"（和 `combatd.lpc` 第
  1200-1201 行 `announce(me,"dead")` 的文案逐字一致，证实真的走到
  了这条分支而不是表情假动作）→"【谣言四起】某人：听说浮浮莫名其
  妙地死了。"（全服讣告）→角色被送进 `鬼门关 - /d/death/gate`
  （`DEATH_ROOM`），房间里站着"冥府地藏王殿前 白无常(white
  gargoyle)"。全程 `debug.log` 没有产生任何新的运行时错误（唯一出
  现的运行时错误是和这次测试完全无关、独立于任务任务精灵心跳复现
  的 `*Inherit chain too deep: > 60`，见下）。
- **`DEATH_ROOM->start_death(me)` 未定义确认无害，是本次会话第 4
  个证实同一良性形状的档案**：`feature/damage.lpc` 第 397 行
  `DEATH_ROOM->start_death(me);` 在全档案里确实找不到任何
  `start_death` 的定义，`->` 呼叫不存在的函数静默返回 0；实测死亡
  全程没有任何相关报错，紧随其后的 `me->move(DEATH_ROOM)` 和房间
  自身的白无常 NPC（`d/death/npc/wgargoyle.lpc`）完整接管了后续流
  程，和本次会话已经在 dtsl2/mhxy/tianxia 三份档案验证过的结论一
  致——这是同一份共享血统里带过来的良性死代码，不是 bug。
- **`death_stage()` 的重入防护逐支路读代码确认写得对，但受限于巫
  师排除逻辑+目标区域太远，没能用真人角色走完整段对话**：
  `d/death/npc/wgargoyle.lpc`（以及血统一致的 `bgargoyle.lpc`）的
  `init()` 里有 `if (previous_object()->query_temp
  ("death_stage_active")) return;` 防重入闸门，`death_stage()`
  本体三条出口分别是：(1) `!ob || !present(ob)` 时清掉
  `death_stage_active` 再 `return`；(2) 对话没讲完时"不清掉闸门、
  `call_out` 续下一句再 `return`"——这不是遗漏，是故意让闸门在整
  段对话进行期间保持"占用"状态；(3) 对话讲完时先清掉闸门再
  `reincarnate()`，随后落入 `move(REVIVE_ROOM)` 走到函数末尾正常
  结束。三条路径的收尾都对，没有 §7.112 那种"某个退出分支忘记清
  闸门"的漏洞。没能用真人角色实测这整套对话的原因是：`init()` 里
  `wizardp(previous_object())` 直接短路跳过整套流程（巫师角色的鬼
  魂永远不会触发白无常对话，这也是刚才测试 `fluffos` 死亡后鬼魂在
  `鬼门关` 干等、白无常没有主动搭话的原因），必须换一个非巫师角
  色才能真正触发；本次新注册了测试角色 `pkyou`（关外人氏出生），
  但从出生点 `/d/guanwai/kedian` 走到最近的野兽出没点（`milin2`/
  `famu`/`heifengkou`）实测超过 14 跳，中途按房间 `exits` 字段脚
  本化寻路时踩进了一个不相关的死胡同（`xuedi1↔xuedi2↔xuedi3↔
  chuanchang` 雪地循环，和目标区域并不连通），而 `summon`/`goto`
  等巫师快速传送指令对目标是"玩家"时同样卡在 `is_admin()` 门槛
  上（`summon.lpc` 第 42 行同款 `switch` 结构），没有合法的巫师
  途径把 `pkyou` 快速送到猛兽出没的房间。鉴于逐行读过的三条退出
  分支逻辑清晰无歧义，且这正是本次会话第 3 次在不同档案里核实到
  的同一段血统代码（`death_stage()` 的写法和 §7.112 已核实过的其
  它档案一致），判断为设计正确、不需要进一步修复，但如实记录"非
  巫师完整对话流程"这一小块没有做到真人实测，留给以后有需要时再
  验证。
- **顺带发现一个超出本次任务范围、和 smash/死亡无关的独立运行时
  错误，先记录不修**：驱动心跳期间反复出现 `执行时段错误：
  *Inherit chain too deep: > 60`，触发源是 `adm/daemons/quest/
  shen.lpc` 的 `heart_beat()`/`start_quest()` 链路生成
  `kungfu/class/generate/questnpc`/`shennpc`（还观察到一次
  `/d/quanzhou`），这些运行时动态生成的继承链条超过了驱动
  `inherit chain size`（60，来自 `config.fluffos`）的上限。这是一
  个真正的运行时错误（有明确的 debug.log 报错签名），但和本次任务
  的死亡/smash 调查完全无关，超出本次任务范围，留给以后专门排查
  任务系统时处理，本次不动。
- **快速核对清单结果（均已确认，未发现新问题）**：§7.90（eval-
  cost）、§7.111（`standard_trace()`，`adm/single/master.lpc` 定义
  正常）、§7.108 均无异常；§7.112（`death_stage()` 重入防护）在
  `wgargoyle.lpc`/`bgargoyle.lpc` 两处都写对，见上；§7.79
  （`addn()` 2 参数）全档案 0 处残留；§7.100（`ROOM` 基类
  `replace_program()`）全档案 21 处命中，逐一确认全部是转档之前
  就已注释掉的 `//` 行，和 2026-08-19 那次扫尾记录完全吻合，没有
  新的活跃实例；§7.30（`feature/skill.lpc` 未初始化 mapping 存取
  器）5 处存取器全部已是 `mapp(x) ? x : ([])` 写法；`combatd.lpc`
  没有 `bounce` 相关代码，4 份姊妹档案命中的除零 bug 在这份档案不
  适用。

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：扬州醉仙楼购物 + 丐帮李斧头拜师。上一次深挖是 2026-08-20
死亡/复活（`smash`/`death_stage`），NOTES 全文没有 `buy`/`商店`/
`apprentice` 实测。sibling `zjdyaryl` 同日刚走过同一条路径；
`zjdy2008wzb` 2026-08-19 已经 `buy jitui` + `bai li futou`。

本轮没有新的 programming bug。`enter_world()` 已经是
`ob->set("registered", user->query("registered"))`（从 user 抄到
login，和 xkxz2 Bug 2 方向相反）。`work/log/nosave/` 目录本来就在，
`clone` 这条路没碰到 ntii 那种缺目录崩溃——但 `clone` 本身对
`(admin)` 巫师不可用：`is_admin()` 是 `admin_flag == 1222 ||
getuid() == "pkyou"`，和 wizlist `(admin)` 是两回事（2026-08-20
NOTES 已记录，不改）。`env/prompt` 是 `"time"`，live clock，idle
0.45。

### 实测过程

管理员 `fluffos` / `Mud@2026` / 浮浮。第一输入是「您的英文名字」，
没有 BIG5 提示。端口 40109。原先 `registered:0`、`qi:1`（上次死亡
测试留下的）、`startroom` 世外桃源。`recover` 后走完 `register
fluffos@example.com` → `decide` → `west`/`out`（阴险奸诈）→ `wash`
→ `born 扬州人氏`，落地扬州客店。`born` 后弹出游戏规则 pager
（ENTER/q）。

`clone /clone/money/gold` 被拒：「你不能复制物品。」（`is_admin()`
门槛，设计如此）。布衣当铺估价一文不值。改用巫师 `update` 加载一
个一次性 `/clone/misc/_tmp_pay.lpc`（`create()` 里 `new` 黄金然后
`move` 给 `this_player()`；测完已删，未提交），`i` 出现一两黄金。

`goto /d/city/zuixianlou`，`list` 包子五十文 / 烤鸡腿八十文。扬州
店小二没有丐帮穷叫化踢人。`buy jitui` 成功：「你从店小二那里买下
了一根烤鸡腿。」`i` 剩九十九两白银 + 二十文铜钱（10000−80=9920）。

`goto /d/gaibang/underhs`（舍身崖下），李斧头 id `li` /
`kungfu/class/gaibang/li-futou.lpc`，只收男性。`apprentice li` 一次
成功：「恭喜您成为丐帮的第二十代弟子。」`score`「你是扬州人氏，
天性阴险奸诈，师父是李斧头。」`title`「丐帮第二十代传人」。

第一次 `save` 撞上 30 秒冷却（`born` 刚写过 `last_save`）。丢
socket 后重连「重新连线完毕」，再 `save`「档案储存完毕」。此时
`user.o` `registered:1` + `family_name` 丐帮 / `master_name` 李斧头；
`login.o` 仍是 `registered:0`（`do_decide` 不写 `link_ob`）。

重启驱动强迫走 `enter_world()`。重连落地客店而不是世外桃源，没有
「您还没有注册」，`score` 仍是丐帮二十代 / 李斧头 / 扬州人氏，银
子铜钱还在。烤鸡腿是 `F_FOOD`，不进 autoload，重启后不在身上——
不是存档 bug。

live `debug.log` 是 `libs/zjdywzb/log/debug.log`（第一轮 Boot Time
Fri Sep 4 03:39:22，persist 轮 03:41:00），无 `error:` / `Too deep
recursion`。mudlib `work/log/log` 只有开机/指令编译警告。心跳期
`Inherit chain too deep`（2026-08-20 已记录、quest/shen.lpc）本轮
短会话没有再出现，不修。管理员存档未提交。
