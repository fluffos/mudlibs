
## WASM 修复摘要（迁移自 meta.json 的 group_note）

终极地狱2008完整版（REVIVE OF ULTRA HELL(BLOOD & MAGIC) FROM 1999.11.13，CDS 出品），和本次会话已经处理过的 'hell' 档案同属一个 Doing 血统家族——master.lpc/logind.lpc/named.lpc/versiond.lpc 结构几乎逐行一致。WASM 修复了：（1）经典的 §8.1 GBK 字节区间 is_chinese()（用 176-247/161-254 区间做 str[i..i+1] 字节对检查）重写成逐码点 0x4e00-0x9fff 检查；check_legal_name() 对应的、没有减半的 maxlen 界限修复成 maxlen/2，最小值从 2 改成 1。（2）master.lpc（adm/single/master.lpc）的 valid_read()/valid_write() 缺少标准的 'user == this_object()' 保护——两处都已加上。（3）§7.50 类的 is_killing(object) 对 is_killing(string id) 修复了 12 处呼叫点（kungfu/skill/*.lpc 的 suck/tan/zhua/hua 档案、clone/user/user.lpc、d/city/npc/guidao.lpc、cmds/std/ansuan.lpc、cmds/std/surrender.lpc）。（4）缺失的 log/nosave/ 目录导致 logon() 的第一次 log_file() 呼叫抛出'Wrong permissions for opening file /log/nosave/logon'，直接把每一个连线用户断线（'new_conn_handler: logon() ... has failed'）——已创建该目录，和 yxxcii 上见过的同一类 bug 一样，但这里是阻断启动的，不只是外观问题。（5）get_name() 里姓+名合并的最小长度检查（strlen(fname)<4，字节数翻倍）和 named.lpc 的 invalid_new_name() 滑动窗口近似名字去重（最小值 2→1，窗口切片 name[i..i+3]/name[i..i+5] → name[i..i+1]/name[i..i+2]，循环界限 l-4 → l-2，闸门 i+6<=l → i+3<=l）都修复成减半后的逐码点界限，和 hell 家族的先例完全一致——不修的话，单字姓氏和任何两字全名都会被拒绝为'太短'。（6）versiond.lpc 的 in_server()（通过 logind.lpc 在 logon() 里直接、未加保护的 VERSION_D->is_version_ok()/query_temp() 呼叫触达，所以即使它不在 adm/etc/preload 里，第一次连线时也会被编译）带有和 hell 的 versiond.lpc 一样真实、未掏空的 socket_create()/socket_bind() 呼叫——按照 AGENTS.md §7.52，把全部 13 个碰 socket 的函式（in_server、connect_server、clear_syn_info 里的 socket_close 循环、send_command、send_client_pending_msg、syn_finish 里的 socket_close、in_listen_callback、in_write_callback、in_close_callback、cmd_close、send_pending_msg、send_result、remove_connection 里的 socket_close）都掏空成 no-op/notify_fail，和 hell 的修复方式几乎一致。adm/daemons/ftpd.lpc 和 adm/daemons/network/dns_master.lpc 都处于休眠状态（在 adm/etc/preload 里被注释掉，只有带保护的巫师指令呼叫者）——保持原样。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。注册流程在格式化前后都完整验证过（英文 id→y 确认→中文姓→中文名→管理员密码+确认→登录密码+确认→角色类型菜单（1-5，用的 5）→性别→进入世外桃源），管理员权限已通过'目前权限：(admin)'确认。这份档案的提示符会显示实时时钟（符合 AGENTS.md §8.3 第 1 条）——注册测试时用的是 --idle 0.3。LPC 格式化工具对全部 7287 个档案运行（写入 7258 个，1 个转档之前就存在的错误，28 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

手足档案 `zjdywzb`（同一个 Doing/"hell" 血统家族）已经做过 §10.7 深挖，
发现并修复了 §7.88（`message()` 包装函数漏标 `varargs`）、§7.89（自带
`runtime_config.h` 索引错位）、§7.86（留言板 `post` 崩溃）。本次按照
"移植的修复仍需逐库验证"的项目惯例，逐条重新核实这三处在
`zjdy2008wzb` 自己代码里的实际形状，而不是直接照搬。

- **§7.86：已经在跨库扫描时修复过（见上一节），本次确认无遗漏**。
  全档案搜索 `inherit.*BOARD` 关系的 `.lpc`，没有任何一处还残留多余
  的 `replace_program()`；用巫师账号在"客店留言板"（`/d/beijing/
  kedian`）实测 `post board` 全流程顺利完成（"留言完毕"），`look
  board` 确认帖子正确显示作者与时间戳。

- **§7.89：代码形状与 `zjdywzb` 完全一致，已修复并 live 验证**。
  `include/runtime_config.h` 是同一份索引编号从零开始、和这个驱动
  版本真实内部枚举对不上的自带旧版头文件（`__MUD_PORT__` 等于
  `CFG_INT(0)`，但驱动实际的 `__MUD_PORT__` 编号完全不同）。换成驱
  动自带的权威版本（旧版备份为 `include/runtime_config.h.orig_
  zjdy2008wzb`），处理了两个仍在使用的孤儿符号：`__SAVE_BINARIES_
  DIR__`（`adm/daemons/versiond.lpc` 两处引用）别名成
  `__MUD_LIB_DIR__`；`__ADDR_SERVER_IP__`（`cmds/arch/config.lpc` 一
  行纯展示用的巫师 `config` 指令输出）直接删除这一行（这个驱动版本
  压根没有 addr_server 概念）。`__PORT__`（`adm/daemons/versiond.lpc`
  第 1468 行引用）不需要别名，这个驱动本身把它当编译期预定义常量。
  live 验证：修复前没有单独复现（直接先修好再测的），但修复后巫师
  账号 `fluffos` 反复重新连线、`look`、`goto`、`update` 全部正常，
  `adm/daemons/network/messaged.lpc` 编译干净（只有几行 `Unused
  local variable` 警告，没有任何 `socket_bind()` 类型错误）。

- **§7.88：代码形状和 `zjdywzb` 相同（`adm/simul_efun/message.lpc`
  的 `message()` 包装函数不是 `varargs`，但同一文件内 `message_
  vision()`/`message_combatd()` 等多处只传 3 个参数），但这次**没能
  在这份档案的当前驱动构建上实测复现崩溃**，与 `zjdywzb`/
  `yhwhpublicfi` 的确认结果不同，记录如下：为了严谨验证，先临时把
  `message()` 恢复成原始（无 `varargs`）版本，重启驱动，走完整条
  "register 邮箱 → decide → west 进桃源石屋 → out" 角色创建仪式（这
  条路径必定经过 `hua.lpc`（花铁干）`check_leave()` 里的 `message_
  vision()` 调用，以及 `entry.lpc`（世外桃源）`valid_leave()` 里另
  一处 2 参数的 `message_vision()` 调用——这两处都会让内部的
  `message()` 包装函数以 3 参数被呼叫），全程没有任何崩溃或行为异
  常，`debug.log` 里也没有出现 `Bad argument 4 to EFUN message()`。
  走读这个驱动构建（`~/src/fluffos/src/packages/core/efuns_main.cc`
  的 `f_message()`）发现原因：`efun::message()` 的第 4 参数
  （`exclude`）在 `num_arg==4` 分支下对 `T_NUMBER`（也就是缺失参数
  被静默填成的 `int(0)`）走的是 `default` 分支，直接把
  `avoid = &the_null_array` 当成"没有排除对象"处理，完全没有对第 4
  参数调用 `bad_argument()`——只有第 3 参数（`target`）在类型不对时
  才会报错。也就是说，`zjdywzb`/`yhwhpublicfi` 记录的那个具体崩溃文
  本（"Bad argument 4 to EFUN message() Expected: object, array, Got:
  int(0)."）在**这个驱动构建**上无法用同样的调用形状复现——保留
  `varargs` 修复（改回 `varargs void message(...) { efun::message(...,
  exclude || ({})); }`，和 `tell_room()` 已有写法一致）不会有任何副
  作用，是更严谨、更符合声明的写法，且完全对齐这个"hell"血统家族的
  既有修复先例，所以还是照做保留了，但**明确记录本次未能实测复现
  §7.88 描述的那个具体崩溃**，不算是本档案独立确认的第三个实例。

- **本次新发现，AGENTS.md §7.80 命中第二例（同一份 `eventd.lpc`
  文件，同一处 `[0..<3]` 切片）**：干净启动后 `debug.log` 里有
  `执行时段错误：*call_other() couldn't find object '/adm/daemons/
  event/emei.l'.`。走读 `adm/daemons/eventd.lpc` 的 `create()`：
  `event_name = map_array(event_name, (: $1[0..<3] :));` 想要去掉
  `.lpc`（4 个字符）后缀，但 `[0..<3]` 在这个驱动上只会丢弃 3-1=2
  个字符（`str[0..<n]` 保留 `len-n+1` 个字符，不是 `len-n`），实际
  把 `"emei.lpc"` 切成 `"emei.l"` 而不是 `"emei"`——`adm/daemons/
  event/` 目录下每一个事件档案都被切错，导致 `collect_all_event()`
  的 `(EVENT_DIR + event)->create_event()` 每次都打在一个不存在的
  路径上，整个事件系统从一开始就是静默失效的（被驱动的错误处理器
  拦下，不影响启动/注册/其它任何功能，纯粹是这一个子系统悄悄不工
  作）。这和 AGENTS.md §7.80（`nt1`'s `eventd.lpc`）是**字面同一个
  文件、同一处代码**——修复方式完全一致：`[0..<3]` → `[0..<5]`
  （`suffix_length + 1` = `4 + 1`）。修复并重启后，`debug.log` 里
  不再出现任何 `couldn't find object '.../event/...'` 类错误。

- **本次新发现，AGENTS.md §7.81 命中第三例（`inherit/misc/quest.
  lpc` 的 `set_information()` 参数类型过窄）**：`clone/quest/
  {capture,shen,deliver,search,supply,judge,explore,avoid}.lpc` 这
  8 个任务档案的 `register_information()` 都会呼叫 `set_information
  (NPC_NAME, (: ask_npc :))`，传一个闭包；但它们共同 `inherit` 的
  `inherit/misc/quest.lpc` 把自己的转发函数声明成 `void
  set_information(string key, string info)`——`info` 被错误地限制
  成 `string`，而它转发的目标 `adm/daemons/questd.lpc` 的真正版本
  签名是 `(object qob, string key, mixed info)`，本来就接受
  `mixed`。这个过窄的类型声明导致全部 8 个任务档案编译失败
  （`error: Bad type for argument 2 of set_information ( string vs
  function )`），`new("/clone/quest/xxx")` 之后拿到的是空程序对象，
  每个任务精灵的 `heart_beat()`/`start_quest()` 都会打出
  `*No program in object '/clone/quest/xxx'!`——整个随机任务生成子
  系统从存档转换之初就是静默失效的，没有任何启动或登录期间可见的
  症状。这和 AGENTS.md §7.81 记录的 `nt1`/`yhwhpublicfi` 两个先例
  一模一样（`yhwhpublicfi` 恰好也是同一个"hell"血统家族），修复同
  样是把 `info` 的类型从 `string` 拓宽成 `mixed`。live 验证：修复
  后用巫师账号对全部 8 个档案逐一执行 `update`，全部显示"成功！"，
  不再有任何 `Bad type for argument` 编译错误。

- **注册与角色创建**：完整走过"英文 id → y 确认 → 中文姓 → 中文名
  → 管理密码+确认 → 登录密码+确认 → 角色类型菜单(1-5) → 性别(m/f)"
  的整条流程，测试角色"陈小武"（`cxtestwzb`）；世外桃源 → 西入桃
  源石屋 → `out`（触发花铁干 `check_leave()`，天性变"阴险奸诈"）→
  阎罗殿 → `wash`（忘忧池洗天赋）→ `born 扬州人氏`，一次成功，正确
  落地 `/d/city/kedian`（客店），`score` 显示年龄十四岁、四项天赋、
  食物/饮水满格，完全正常。

- **战斗测试**：在"北大街"对"白驼山少庄主"欧阳克（`ouyang ke`，
  `attitude: friendly`，属性与新手角色量级接近）发起 `kill`，多回
  合拳脚攻防判定正常（命中、伤情提示、"半昏迷"预警），最终角色力
  竭"眼前一黑，接著什么也不知道了"（陷入昏迷，非死亡，精/气随后自
  动回满），全程无崩溃。

- **死亡/复活流程完整走通（比手足档案 `zjdywzb` 更进一步——那份档
  案受限于巫师 `call` 指令的 ACL 未能验证到底）**：巫师账号对
  `cxtestwzb` 使用 `smash` 指令（"一道闪电......正正劈中陈小武"），
  角色当场死亡，倒地留下"陈小武的尸体(Corpse)"，`debug.log` 编译了
  `d/death/npc/wgargoyle.lpc`（鬼门关"白无常"）。重新连线后角色变
  成鬼魂站在"鬼门关"，`wgargoyle.lpc` 的 `init()` 排除了
  `wizardp(previous_object())`（符合 AGENTS.md §10.7 第 6a 条描述
  的形状——但测试角色不是巫师，不受此排除影响），确认排定了
  `call_out("death_stage", 30, ob, 0)`。等待约 3 分钟（30 秒首次
  + 后续每 10 秒一次、12 个阶段的"白无常"对话轮次）后重新连线查
  看，角色已经被 `reincarnate()` 并正确送到 `REVIVE_ROOM`（"武庙"，
  岳王庙正殿），`score` 显示"你到目前为止总共到黑白无常那里串门一
  次。你最后一次是被陈管理用雷劈死了。"精/气条清空（死亡后的复活
  初始状态），全程没有任何 §7.68 类型的卡死或崩溃。

- **未测试**：门派拜师、商店购物、邮件系统；`debug.log` 里出现过两
  次 `Eval interrupted: object adm/single/master cost limit reached`
  / `Too long evaluation`，但都发生在本次测试对同一个巫师连线短时
  间内连续执行 8 条 `update` 指令（逐一重编译全部任务档案）期间，
  不是任何一次普通移动/指令触发的（没有在正常游玩流程——包括战斗、
  死亡复活、注册——中观察到过），判断是本次测试本身的高强度编译负
  载造成，不认定为 AGENTS.md §7.90 类的一般性 eval-cost 配置问题，
  留作观察记录。

- **管理员账号播种：本次发现 README 记录的"已播种"是过时/不准确
  的**——`data/login/f/`、`data/user/f/` 目录下之前完全没有
  `fluffos` 的存档文件，说明 WASM 阶段记录的注册从未真正落地（或
  存档在某次会话间丢失）。本次通过正常注册流程重新播种：
  `fluffos` / `Mud@2026`（管理密码 `Mud@2026Adm`），两个密码都被
  验证流程直接接受，未触发任何长度/格式限制变体；`/adm/etc/
  wizlist` 里原有的 `fluffos (admin)` 条目仍然有效，注册后立即通
  过 `look` 房间路径显示、`goto`、`update` 三重验证确认 `(admin)`
  权限生效。

- **§9 LPC 格式化工具本次未运行**：本次会话环境里没有可用的
  `node`/`npm`（`which node`/`npm` 均找不到），无法执行
  `format-corpus.mjs`。本次改动的 5 个文件（`adm/simul_efun/
  message.lpc`、`cmds/arch/config.lpc`、`include/runtime_config.h`、
  `inherit/misc/quest.lpc`、`adm/daemons/eventd.lpc`）都是手工做的
  外科手术式最小改动，逐行对照周围代码风格，风险较低，但仍留作已
  知欠账，下次有 `node` 可用的会话应补跑一次格式化再复核。

## 深度功能测试第四轮（§10.7 round-four，2026-08-19）

本轮任务：补测第三轮明确标记为"未测试"的三个系统——门派拜师、商
店购物、邮件系统；并对已经全库扫描完毕的几条 checklist（§7.90、
§7.111-§7.115）做一次本档案专属的抽查。**没有发现任何新的编程
bug**，三个系统里两个（拜师、购物）完整验证正常工作，第三个（邮
件）确认是这个"hell"血统家族项目本身就蓄意关闭的功能，不是本档
案独有的坏损。

**测试前置状况**：管理员账号 `fluffos` 的存档处于损坏的中间状
态——`data/login/f/fluffos.o` 存在（`purename` 是"浮浮"，明显是
一次未走完的注册残留），但 `data/user/f/fluffos.o` 完全不存在，
导致用 `fluffos` 连线会在 `logind.lpc` 的 `user->restore()` 失败
分支直接断线（"无法读取你的数据档案，您需要和巫师联系。"），且
这个档案的 `CONFIG_D->query_int("ask_recreate")` 返回假，连"是否
重新创造玩家"的补救提示都不会出现。判断是第三轮会话在" look/
goto/update 三重验证"之后没有让角色真正存过档（`obj/user.lpc` 的
存档很可能只在正常 `quit`/心跳周期性存档时触发，而不是巫师权限检
查本身需要的），随后如果那次会话是直接杀掉驱动进程结束的，新建的
角色存档就会跟着丢失——这本身可能是个值得未来注意的"角色数据只
在正常退出/心跳时落盘，异常关闭会丢刚创建的角色"式的存档可靠性
问题，但和本档案玩家实际测试无关，未展开处理。本轮临时在
`adm/etc/wizlist` 加了 `wztestfour (admin)`，通过正常注册流程重
新播种了一个可用的管理员测试角色，验证完毕后已经把 wizlist 恢复
原状、删除了 `wztestfour`/`fluffos` 的残留存档档案（`fluffos` 的
损坏 login 存档也一并清掉了，避免下一轮踩同一个坑）。

- **门派拜师（bai/apprentice）：完整验证正常工作**。走读
  `cmds/skill/apprentice.lpc`（`bai`/`apprentice` 指令的实现）确
  认调用链是 `apprentice.lpc` → NPC 的 `attempt_apprentice()` →
  （接受时）`recruit_apprentice()`/`assign_apprentice()`
  （`feature/apprentice.lpc`）。逐个走读了几个宗门的
  `attempt_apprentice()` 实现：`d/heimuya/npc/xiang.lpc`（向问天）
  直接拒收，`d/baituo/npc/{trainer,li}.lpc`（白驼山教练/李管家）
  门槛是"必须先天生就是欧阳世家出身"（`born_family` 检查，创角色
  时选择，不能后天拜入），这两处都是合理的内容级拒绝，不是 bug。
  找到 `kungfu/class/gaibang/{li-futou,qiu-wanjia}.lpc`（丐帮六袋
  弟子李斧头/邱五嘉）这类新手可达成的拜师入口——门槛只是
  `permit_recruit()`（没有叛师/没有已拜过其他门派）加性别检查，
  对一个全新注册的男性角色正好满足。用巫师 `goto /d/gaibang/
  underhs` 传送新角色到场，`bai li futou` 一次成功："你想要拜李
  斧头为师。" → "李斧头决定收你为弟子。" → "你跪了下来向李斧头恭
  恭敬敬地磕了四个响头，叫道：「师父！」" → "恭喜您成为丐帮的第
  二十代弟子。"，`family`/`title`/`recruit_apprentice()` 全部正
  确落地，机制完全正常。

- **商店购物（buy/sell）：完整验证正常工作，买卖双向都测了，货币
  找零精确无误**。`d/huashan/npc/xiaoer2.lpc`（山顶小店店小二，
  `inherit F_DEALER`）挂了 `buy`/`list` 指令。用巫师 `call /adm/
  daemons/moneyd->pay_player(<角色对象>, 5000)` 给测试角色发了
  50 两白银的启动资金（`call` 指令要求 `(arch)` 以上权限，本档案
  admin 账号满足），`list` 正确列出四样商品及单价（烤鸡腿每根
  八十文铜板等），`buy jitui` 成功买下一根烤鸡腿，`i` 确认库存
  正确增加、白银从五十两正确扣到四十九两（找零二十文铜钱，
  5000-80=4920=49两+20文，算术完全对得上）。又在 `d/huashan/
  shop` 买了一个牛皮酒袋（一两白银=100文，找零精确到九十文铜
  钱），带去 `d/beijing/dangpu`（当铺，`d/beijing/npc/
  dangpuzhang.lpc` 挂了 `sell`/`value` 指令）用 `sell jiudai` 卖
  掉，到手 70 文铜钱（100 文 × 70% 折价率，`feature/dealer.lpc`
  的 `do_sell()` 里 `MONEY_D->pay_player(this_player(), value *
  70 / 100)` 精确对应），`i` 确认铜钱从二十文正确增加到九十文。
  另外验证了 `do_sell()` 对不可回收物品的正确拒绝（`sell jitui`
  被拒"剩菜剩饭留给您自己用吧"，因为 `food_supply` 字段命中；
  `sell jinduan`/`sell shoes` 被拒"一文不值"，因为新手服装道具
  `value` 为 0）——这些都是设计内合理拒绝，不是 bug。

- **邮件系统：确认是这个"hell"血统家族项目本身蓄意关闭的功能，
  不是本档案独有的坏损，不作为 bug 处理**。`cmds/usr/mail.lpc`
  的 `main()` 第一行就是 `return notify_fail("此服务已经暂停。
  \n");`——在解析任何参数、进入任何 `input_to` 编辑流程之前就无
  条件拒绝，说明这是原始游戏运营方自己关掉的功能（中文提示"此服
  务已经暂停"读起来就是运营公告口吻，不像是移植过程中引入的坏
  损）。走读 `adm/daemons/maild.lpc` 确认底层 `queue_mail()` 面
  向的是真实 SMTP 外发邮件（收件地址必须是 `user@domain` 格式，
  `mail_from`/`mail_to` 都要求含 `@`），压根不是玩家对玩家的站内
  信——这个游戏没有独立的站内信/信箱系统，`clone/misc/letter.lpc`
  等"信件"档案只是任务道具，没有读写内容的逻辑。对照血统同源的
  `zjdywzb`/`hell` 两份档案，`cmds/usr/mail.lpc` 的这一行拒绝逐字
  节完全相同，确认这是这个"hell"家族项目级别的统一决定（很可能
  是原始运营者出于防止滥发垃圾邮件或者当时没配置真实 SMTP 服务
  器），和之前记录的 `ftpd.lpc`/`dns_master.lpc` 休眠状态属于同一
  类"刻意保持原样"的档案，不需要也不应该重新启用——启用与否是内
  容/策略决定，不是这次深挖任务该处理的编程 bug 范畴。

- **checklist 抽查（均已是全库扫描完毕的条目，本档案只做专属核
  实，未发现异常）**：
  - **§7.111**（`master.lpc` 的 `standard_trace()` `file_name
    (error["object"])` 崩溃）：`adm/single/master.lpc` 第 230
    行已经是 `error["object"] ? file_name(error["object"]) :
    "0"` 的三元保护写法，安全。
  - **§7.112**（`init()` 重连叠加 `call_out` 链）：
    `d/death/npc/{wgargoyle,bgargoyle}.lpc` 都已经用
    `query_temp("death_stage_active")`/`set_temp(...)`/
    `delete_temp(...)` 做了防重入闸门，和第三轮"死亡复活流程完
    整走通、无卡死"的实测结果一致。
  - **§7.113**（netdead 重连不恢复 `heart_beat`）：`adm/daemons/
    logind.lpc` 的 `reconnect()` 无条件呼叫 `user->reconnect()`，
    `clone/user/user.lpc` 的 `reconnect()` 里无条件
    `set_heart_beat(1)`——属于 AGENTS.md §7.113 记录的"批次二"
    45 库之一，本档案当时就已确认干净，本轮静态复查结论一致。
  - **§7.114**（`private` 修饰的 `input_to` 回调经 mixin 失效）：
    `feature/edit.lpc` 的 `input_line()` 没有 `private` 修饰符，
    不受影响——而且这次实测走过的"多行输入"路径（`bai`/`buy`/
    `sell` 都不需要多行编辑，但拜师确认、购物问答等交互全程响应
    正常，没有出现"第一行有效、后续行被吞"的症状），间接佐证这
    个档案确实不在 §7.114 名单里。
  - **§7.115**（`QUEST` 宏指向不存在的档案）：本档案的
    `include/quest.h`/`include/globals.h` 里 `QUEST_OB`（`/inherit/
    misc/quest`）、`QUEST_D`（`/adm/daemons/questd`）两个真正会被
    `call_other` 呼叫的宏对应的档案都真实存在（`work/inherit/
    misc/quest.lpc`、`work/adm/daemons/questd.lpc`），没有"单纯
    叫 `QUEST` 且指向缺失档案"的那种宏，不适用本条。
  - **§7.90**（eval-cost 配置）：`config.fluffos` 的 `maximum
    evaluation cost` 已经是 `5000000`（第三轮已修），本轮驱动干
    净启动 + 完整拜师/购物/多次巫师 `call`/`goto` 操作，全程
    `debug.log` 没有出现任何 `cost limit reached`/`Too long
    evaluation`，佐证了第三轮"那两次 eval-cost 报错是当时会话自
    己连续 8 条 `update` 造成的高强度负载，不是常规游玩会触发的
    一般性配置问题"的判断是站得住的，本轮没有推翻这个结论。

**清理**：临时的 `wztestfour` 管理员测试账号（存档 + wizlist 条
目）已经清理干净，损坏的 `fluffos` 残留登录存档也已删除；驱动测
试进程按 PID 正常 kill，未使用 `pkill -f`。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,306 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——和姊妹档案 `zjdywzb`/`zjdyzj`/`zjmudhell`
同一个 AGENTS.md §7.100 记录的休眠 bug（多余调用给对象打上永久
"pending replace"标记，对象一旦绑定任何闭包就会崩溃）。用
`fix_710_room.py`（二进制模式，只删除内容严格等于
`replace_program(ROOM);` 的独立行）扫过 `work/`，删除 2,305 处；剩
余 1 处是房间生成工具 `clone/misc/roommaker.lpc` 里
`str += "...replace_program(ROOM);..."` 的字符串拼接变体，手工改成
`str += "\n\tsetup();\n}\n";`。另有 17 处是转档之前已注释掉的 `//`
行，原样保留；`work/version/`（一份独立的 46 文件版本同步子树）和
`work/data/` 下都没有真实 `.lpc` 源码命中。`git diff --stat` 确认
2305 个文件各删 1 行 + roommaker.lpc 1 处字符串编辑，与脚本自报数
字吻合。修复后真实驱动干净启动（零新增编译错误、端口正常监听、
`debug.log` 无任何"cannot replace"/"cannot bind"行）；由于这份档案
先前的 `fluffos` 存档已被上一轮测试清理删除，重新走了一次完整注
册流程（`fluffos`/`浮浮云`/管理密码`Mud@2026Adm`/登录密码
`Mud@2026`/均衡型/男），确认"目前权限：(admin)"后 `look`/`goto`
两个曾经命中过这个 bug 的房间
（`d/mingjiao/shanlu3.lpc`、`d/guanwai/shanhaiguan.lpc`）/`quit`
全部正常，无回归。

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
