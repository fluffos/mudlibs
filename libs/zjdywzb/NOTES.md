
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
