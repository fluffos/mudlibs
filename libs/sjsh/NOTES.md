
## WASM 修复摘要（迁移自 meta.json 的 group_note）

三界神话『宝鸡站』，5 档案家族集群（sjsh/sjshv150/sjshv2578bb/sjshwzb/sjshwzjqb）的第一个。WASM 修复：（1）adm/daemons/convertd.lpc 希腊字母/GBK 转换映射表里损坏的原始字节——44 行在闭合引号前紧跟着一段杂散的非 UTF8 字节序列，最后一个字节恰好是 0x5C（反斜杠），转义掉了闭合引号，让字符串字面量没有正常结束，导致编译失败；已用字节级脚本只去掉每一行末尾那段有问题的反斜杠+乱码（同一张表里其它非阻断编译的乱码内容保持原样——纯粹是内容质量层面的噪音，不是开机阻碍，按既定惯例不在本次范围内）。（2）§7.41 类损坏的存档数据：adm/daemons/emoted.lpc 的 create() 对自己损坏的存档档案做了未加保护的 restore()；已包一层 catch(restore())，并显式补上 emote=([]) 兜底（被捕获的错误依然会通过这份 mudlib 自己的 error_handler() 详细记录，确认无害/预期之中，和 sjplgfjxb 已记载的模式一致）。注册流程备忘（不是 bug，是为了测试/以后参考）：一个真正的新 id 必须先字面输入"new"，然后才是想要的 id，然后是中文名字——confirm_id() 是硬编码"Yes"自动呼叫的，中间没有 y/n 确认步骤。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist。已验证：完整注册（new→id→名字→密码→确认→电子邮件→个人主页→ICQ→性别）→look/score/quit 全部干净，管理员账号权限正确显示；trusted_write['/']/exclude_write 也已直接核对源码确认授予 (admin) 不受限的写入权限。LPC 格式化工具对全部 9350 个档案运行；还原了 2 个通过"去空格后比对旧档案"扫描（覆盖 79 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案；另外直接逐一比对了唯一一个近似 ASCII 地图的档案——干净，只是排版调整。格式化后重新验证过，干净。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 46 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

之前两轮都只做过编译检查/浅层注册测试，没有真正玩过。这次用原生驱动（`build-debug/src/driver`）通过 `scripts/tmux_mud.sh` 和 `scripts/mudclient.py` 走完整轮：GB/BIG5 编码选择 → 「是否中小学生」拦截 → `new` → 英文 id（3-8 位纯字母，测试用 `testqx`/`qxtwo`/`qxthree`）→ 中文名字 → 密码（至少 5 位）→ 确认密码 → 电子邮件（须含 `@` 和 `.`，长度 ≥9）→ 个人主页（可空）→ ICQ（可空）→ 性别 m/f → 天赋分配小游戏（`d/wiz/init.lpc`，房间 〖天赋房〗，选 `9` 接受默认再 `y` 确认）→ 落地 〖南城客栈〗（长安城，`/d/city/kezhan`）。README 记载的注册坑点（`new` 硬编码流程、`confirm_id()` 无 y/n 确认）依然准确无需更正。`look`/`score`/`quit`/男女两种性别分支都验证过，`quit` 干净退出无崩溃。

- **（新增 AGENTS.md §7.97）`include/net/config.h` 的 `LISTNODES` 多行宏第一行缺续行反斜杠，把 `dns_master.lpc` 编译坏了，进而让 `die()` 在关键状态重置之前被打断，造成永久性"你死了"死循环，比 §7.68 的鬼魂卡死更严重**：用管理员测试角色和普通角色分别在朱雀大街对 `疥顶小僧`（`d/city/npc/jieding.lpc`）和 `和尚`（南海普陀山第三代弟子，`d/city/npc/bonze.lpc`）打 `kill`，真实战斗到死后，屏幕开始无限重复"你死了"，`debug.log` 每次都带着同一条崩溃栈：`/adm/daemons/network/dns_master.lpc` 报 `*No program in object`，调用链是 `feature/damage.lpc` 的 `die()` 第 349 行 `COMBAT_D->killer_reward(...)` → `combatd.lpc` 的 `killer_reward()` → `channeld.lpc` 的 `do_channel()`（把死亡消息广播到系统频道）→ `gchannel.lpc` 的 `send_msg()` 第 36 行调用未编译的 `DNS_MASTER`。根因在 `include/net/config.h` 第 20 行：`#define LISTNODES ([` 这一行结尾没有反斜杠，而后面三行（`"SK": ...,` 等）都有——预处理器把宏体在第一行就截断成不完整的 `([`，后面三行 `"SK": "..."，` 之类的内容不再算宏的一部分，而是原样泄漏进任何 `#include` 这个头文件的源码里，导致 `dns_master.lpc` 编译期语法错误、彻底不存在于内存里。因为这个调用点完全没有 `catch()`，异常会一路把 `die()` 从第 349 行整个打断——后面「重置 kee/eff_kee/sen/eff_sen 为 1」「移动进 `DEATH_ROOM`」「呼出判官对话」全部没执行；`eff_kee`/`eff_sen` 停在致命负值，`std/char.lpc` 的 `heart_beat()` 每一 tick 都重新判定 `eff_kee<0` 再次调用 `die()`，同一个崩溃无限重演——角色连"变成鬼魂"这一步都到不了，是比 §7.68 更彻底的死锁。修复：给 `#define LISTNODES ([` 补上末尾反斜杠。重启驱动后重测：`kill` 到死只触发一次"你死了"，系统频道正常广播"【三界神话】某人：紫电仙人在长安城被和尚杀死了。"，角色被送进 〖阴阳界〗（`/d/death/gate`），判官 `崔珏`（`朱笔判官 崔珏`）完整走完"翻生死簿→判定阳寿未尽→送还阳"对话，角色活着落地在复活室 〖荒郊小店〗（`重伤`但不再是鬼魂/不再重复死亡），`score`/`look`/`i` 等指令全部正常。已更新 AGENTS.md，新增 §7.97。
- **（§7.34 leftover printf 调试残留，已修）`adm/daemons/logind.lpc` 第 621 行 `get_name()` 里，在 `ob->set("name", arg)` 之前有一行裸的 `printf("%O\n", ob)`**，会把登录对象的内部路径（形如 `/clone/user/login#N`）原样打印在中文名字确认和密码提示之间。已直接删除这一行；重新注册验证提示序列干净、没有多余输出。
- **（§7.11 缺失 assure_file 防护，已修）`adm/simul_efun/file.lpc` 的 `log_file()` 是裸 `write_file(LOG_DIR + file, text)`，同一份文件里紧接着定义了现成的 `assure_file(file)` 辅助函数却从未被调用**：`log_file("nosave/CRASHES", ...)`（`adm/obj/master.lpc` 的崩溃处理器）、`log_file("nosave/promotion", ...)`（`securityd.lpc` 授权日志）等调用目标目录 `/log/nosave/` 在这份档案里从未随仓库分发（`ls log/` 只有 `attack`/`dlog`/`edit`/`static`），一旦真的触发（崩溃处理、`promote` 指令等）就会静默失败或抛错。修复：`log_file()` 前置一次 `assure_file(LOG_DIR + file)`（并按同一文件里既有的用法补了一行前向声明，因为 `assure_file()` 在文本顺序上定义在 `log_file()` 之后，这个编译器不会自动做前向解析）。属于防御性修复——本轮实际游玩没有走到这几条日志路径本身，但按 AGENTS.md §7.11 的既定套路修，属于"看到就修"级别的低风险改动。
- **§8.9（食物/饮水初始化）不适用**：`adm/daemons/logind.lpc` 的 `confirm_gift()` 直接 `user->set("food", user->max_food_capacity())`/`user->set("water", user->max_water_capacity())`，没有 `ob`/`user` 混用的错误对象读取，也没有任何 `age==14` 之类的额外闸门。三个测试角色 `score` 食物/饮水都是满格「正常」，符合预期。
- **§7.88/§7.12（message()/tell_room() varargs 缺陷）不适用**：`adm/simul_efun/message.lpc` 里没有自定义 `message()` 包装，只有 `tell_room()`，本来就是 `varargs void tell_room(mixed ob, string str, object *exclude)`，函数体里已经是 `exclude || ({})` 的正确写法；`shout()`/`say()`/`message_vision()` 内部所有 `message()` 调用都带够 4 个参数，没有缺省参数被驱动补 `int(0)` 的风险。
- **§8.3a（`private nomask command_hook`）不适用，已在更早的一轮修过**：`feature/command.lpc` 里 `command_hook()` 定义前有一行注释掉的 `// private nomask int command_hook(string arg)`，当前实际声明是 `nomask int command_hook(string arg)`（没有 `private`），说明这条修复在本次深挖之前就已存在。
- **§8.3b（`commandd.lpc` 的 `.c` 后缀 sscanf）不适用**：整个档案里没有 `commandd.lpc` 这个文件，指令分派完全走 `feature/command.lpc` 的 `add_action` 机制，不存在这类命令表重建逻辑。
- **§7.90（eval cost 上限）本次未观察到问题，`config.fluffos` 保持项目默认 `700000` 未改动**：`grep -c "cost limit reached" log/log` 在跨越注册、天赋分配、多次移动到从未去过的房间（朱雀大街、长安乐坊、荒郊小店等）、两轮真实战斗到死、两次完整复活流程之后仍为 0——本档案目前的 NPC/技能开销没有触到这个上限，暂不需要按 §7.90 的套路上调。
- **留言板双实例全部实测通过**：〖南城客栈〗的"南城客栈留言板"（`obj/board/nancheng_b.lpc`）和复活室〖荒郊小店〗的"生死之间留言板"（`common_a.o` 底层，收录了 27 条从 2001 年前后留存至今的真实历史留言，涉及 pk、死亡、门派八卦等——按项目"保留而非清空"的精神，测试留言在提交前已用 `git restore` 撤销，没有污染这份历史存档）都能正常 `post`/`.`/`read <n>`，未读数正确更新，§7.86 的修复确认线上有效。
- **商店 `list`/查看正常**：荒郊小店的店小二 `list` 出炸鸡腿/红烧狗肉/西瓜/花雕酒袋及价格；未实测 `buy`（本轮时间有限，留待下次）。
- **背景世界事件"天地劫"确认是设计内容，不是 bug**：一个后台精灵每隔约 10-20 秒向全服广播魔教攻陷各大门派（蜀山剑派、五庄观、大雪山、南海普陀山、阎罗地府、东海龙宫、陷空山无底洞、花果山盘丝洞、方寸山三星洞、将军府，均因"门下空无一人"不战而胜）的滚动剧情，最终以"太白金星：魔教虽然暂时退了，但不知什么时候又会卷土重来!"收尾，观察范围内只完整播报一轮、没有失控重复，判断是纯粹的氛围内容，不属于本轮范围内的程序 bug。
- **内容层面的有趣发现（好奇心记录，非 bug，不属于本轮修复范围）**：这份档案的招牌横幅明确写着"三界神话『宝鸡站』"，但天赋分配环节的欢迎语却是硬编码的"欢迎光临西游记！"，而 `help newbie` 的整份帮助文档标题是"【仙侣情缘】之新手指南"（另一个完全不同的游戏名），文中还提到"刚进入时，你的食物和饮水都是空的"——这与实测的满格食物/饮水完全矛盾，说明这是更早期某次换皮时遗留、从未同步更新的说明文字。三层不同的招牌名称（三界神话/西游记/仙侣情缘）叠在同一份档案里，印证了 README 已经指出的"共享地名风格但代码库不同"背后其实是层层转手改名的历史，而非本次转档带来的失真——按既定范围（内容/文案问题不算程序 bug）未做任何改动。
- **未覆盖**：邮差千里眼（南城客栈里的 NPC）暗示存在邮件系统，但本轮没有找到/测试具体邮件指令；代码里存在 `d/city/obj/muren.lpc`/`d/shushan/obj/muren.lpc`（练功木人，`accept_fight()` 会复制攻击者自身属性，是典型的安全陪练设计）但全档案 grep 不到任何房间引用这两个文件路径，可能是要靠某条尚未找到的指令动态 `new()` 出来，或是死内容——本轮未继续深挖；门派拜师、正式技能学习流程也未触及。

## 深度功能测试（§10.7 round-four，2026-08-20）—— 补齐上一轮标记的「未覆盖」项

用 `build-debug` 驱动配 `config.fluffos`（端口 40141）单独起了一份 sjsh 专属进程，写了双 socket（admin + 测试角色 `qxfour`）的 Python 脚本互相配合走查，而不是用 tmux_mud.sh。新建的测试角色 `qxfour`（密码 `TestPass123`）走完整注册流程后落地〖南城客栈〗，测试全程用管理员 `fluffos` 账号 `goto`/`summon`/`clone`/`call`/`give` 配合搭桥（给钱、临时调高 combat_exp 以跳过拜师门槛），不涉及修改任何代码逻辑。测试结束后已用 `git restore` 清掉 fluffos.o/avguser/maxonline 的会话统计噪音，并删除了 `qxfour` 的测试存档（未跟踪文件，直接 rm），仓库无残留改动。

1. **商店 `buy`——完整实测通过，价格扣除和收货都正确**：一开始用 `buy jitui from xiaoer` 失败，报错"你要跟谁买东西？"——排查后发现这不是 bug：〖荒郊小店〗店小二（`d/ourhome/npc/xiaoer.lpc`）的 `set_name()` 实际 id 列表是 `({"xiao er", "xiao", "waiter"})`，并不包含"xiaoer"（"xiaoer"只出现在语义完全不同的 `shop_id` 属性里，那是给"买下整个店铺"的新店主重新分配称呼用的，不是拿来给玩家 present() 匹配的）；而长安城〖南城客栈〗那位同名店小二（`d/city/npc/xiaoer.lpc`）的 id 列表里则确实有"xiaoer"——两份几乎一样的 NPC 代码之间的别名列表不一致，属于内容层面的差异，不是错误信号，未作改动。改用 `buy jitui from xiao` 后一次成功：`你向店小二买下一根炸鸡腿。`，管理员用 `clone /obj/money/coin` + `call coin->set_amount(300)` + `give coin to qxfour` 给了 300 文钱，购买后 `i` 显示余额精确变成"二两银子(Silver)、二十文钱(Coin)"（300−80=220，找零拆分成银子+铜钱也完全正确），背包里多了"炸鸡腿(Jitui)"。全程 `debug.log` 干净无新增报错。

2. **门派拜师（`bai`/`apprentice`）与正式技能学习（`xue`/`learn`）——完整实测通过**：找了个明确不需要任何门槛就欢迎新人的开山祖师——将军府〖正厅〗（`d/jjf/keting.lpc`）的秦琼（`d/jjf/npc/qinqiong.lpc`，`combat_exp>=100000` 即可）。管理员 `goto`+`summon` 把测试角色接到该房间，再用 `call qxfour->set("combat_exp", 200000)` 跳过战力累积（纯粹为了压缩测试时间，不改代码）。`bai qin` 一次成功：`秦琼说道：很好，时下正是用人之际，小兄弟多加努力，他日必定有成。`→`秦琼决定收你为弟子。`→`恭喜您成为将军府的第三代弟子。`，`score` 里"师承"字段正确显示"将军府秦琼"，称号变成"将军府第三代弟子"。随后 `xue spear from qin for 5` 一次成功：`你向秦琼请教有关「基本枪法」的疑问。`→`你听了秦琼的指导，似乎有些心得。`，`skills` 指令正确显示新学会的"基本枪法 (spear) - 初学乍练 1/0"。全程无崩溃，`debug.log` 干净。（注：地图上大多数"第二代"及以上的门派 NPC 的 `attempt_apprentice()` 都设了很高的 `combat_exp`/`daoxing` 门槛甚至要求已在同门——这是常规的师门晋升设计，不是 bug；此外发现 `d/city/npc/shubao.lpc`（另一处"秦琼"）虽然写了完整的 `attempt_apprentice()`，但全档案 grep 不到任何房间引用它——是真正的死内容，与本轮实测通过的 `d/jjf/npc/qinqiong.lpc` 是两份独立的秦琼代码。）

3. **（低优先级，本轮时间充裕补测完成）邮件系统——存在且能用，不是缺失功能**：〖南城客栈〗千里眼（`d/ourhome/npc/bigeye.lpc`）的 inquiry 表里挂着"mail"/"发信"/"收信"等关键词，要用 `ask <目标> about mail`（目标同样要用 id 列表里的词，如"bigeye"，而不是显示名里带空格的"qianli yan"）触发；`ask bigeye about mail` 一次成功，千里眼把一个"秋雁的信箱(Mailbox)"塞进了玩家背包，随后 `mail` 指令（在拥有信箱后才会通过 `obj/mailbox.lpc` 的 `add_action` 注册）也能正常呼出"你要寄信给谁？"提示——邮件系统是通过"先找千里眼要信箱"这一步触发的，不是常驻指令，之前几轮没找到只是没跟 NPC 对话过，不是代码缺陷。

4. **（低优先级，本轮时间充裕补测完成）`d/shushan/obj/muren.lpc` 练功木人——纠正上一轮"全档案未被引用"的误判，实际是可达内容且实测能打**：重新 grep 后发现 `d/shushan/w-lianwu.lpc`（西武场）和 `d/shushan/e-lianwu.lpc`（东武场）的 `objects` 表里各有 `__DIR__ "obj/muren": 4`（会展开成 `/d/shushan/obj/muren`）——上一轮的 grep 大概率只搜了字面量路径没搜到 `__DIR__` 宏拼接后的引用。实测：管理员 `goto`+`summon` 把测试角色送进〖西武场〗，`kill muren` 失败（同款 id 别名坑：木人的 id 列表是 `({"mu ren","mu","wood man","wood"})`，不含"muren"，需要 `kill mu`），改用后一路真实打到死：`accept_fight()` 里第一次触发的 `random(me->query("fight_times"))`（此时 `fight_times` 还是初始值 0，即 `random(0)`）没有报错也没有崩溃，说明这份 FluffOS 对 `random(0)` 的处理是安全的（返回 0），不是潜在 bug；一路格斗到"木人死了"，`score` 正确记录"杀死敌人：1 名"，全程 `debug.log` 无新增报错。与之相对，`d/city/obj/muren.lpc` 复核后确认在 `d/city/` 目录下确实没有任何房间引用，是真正的死内容。

管理员账号（`fluffos`/`Mud@2026`）本次通过正常注册流程重新走了一遍——`adm/etc/wizlist` 里已有 `fluffos (admin)` 一行（更早的 WASM 阶段留下），但存档目录 `data/login/f/`、`data/user/f/` 下当时并没有真正落地的 `fluffos.o`（说明此前只播种了权限数据，账号从未真正注册过）。本次老老实实走完整个注册流程后立即显示"系统权限目前是：(admin)"，`update /d/city/kezhan.lpc` 重编译成功，确认 write ACL 完全没问题；README 的既有记录基本准确，只是密码此前写的是"注册时自设"，现已确认为标准 `Mud@2026`。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 513 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），508 处脚本自动
删除；另有 3 份房间建造工具副本手动修正——`obj/roommaker.lpc`、
`u/calvin/obj/roommaker.lpc` 是标准的"两套模板"简单变体；
`u/koker/obj/roommaker.lpc` 是同一血统家族已知的"3 处出现"
`room_code`/`str` 变体（一处 `room_code +=` 拼接 + `do_saveroom()`
里两条分支各一处），三处均手动删除。`work/data` 下未发现额外
`.lpc` 源文件（与手足 `sjshv150` 不同，本库没有那个变体）。修复后
全库仅剩 17 处历史遗留的 `//`-注释掉实例，均确认无害、未改动。已
用 `build-debug` 驱动干净启动验证（0 个新增编译错误，端口 40141
正常监听，`debug.log` 无新增 "cannot replace"/"cannot bind" 行）；
未做完整 §10.7 深度游玩测试。

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

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 1 file(s) `inherit F_SSERVER;` and no header defines it (1 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 280 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py sjsh --fix`：无用局部变量 1565 个、`varargs` 60 处、转义 39 处、`nosave` 函数 14 个改 `protected`、裸 `return` 4 处，共改动 843 个 `.lpc`。HEAD 与工作树分别加载（新进程）：823 -> 823 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 15 条候选都是声明被重建（有 `#if` 的只有 `d/city/piggy*.lpc`，与被删的名字无关）。手工：`adm/daemons/cron.lpc` `reward()` 里的 `if (tang) { }` 只剩一行被注释掉的频道消息，空的判断删去。启动时警告 195 -> 0。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 21 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 7 个，只在 #if 分支用的声明移进分支 0 个文件；改动 26 个文件，HEAD 与工作树各载入一次无回退（26 objects; HEAD PASS 25, tree PASS 25; regress 0; newly loading 0），这些文件的警告 48 -> 20。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `daemon/skill/*-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用（练习本就不该射箭），删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `daemon/skill_wiz/archery/xuanyuan-archery.lpc` `practice_skill()`：`(: throw_weapon :);` 只造函数指针不调用，删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["tell"/"finger"] & SVC_KNOWN)) {` 里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 体为空（“无副作用”警告）；把 `#if`/`#endif` 挪到 if 外面（KB 04 §6.10，2026-10-07 那次扫描漏掉了 `! (` 带空格、大括号另起一行的写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：dns_master 空 if

- `adm/daemons/network/dns_master.lpc` `query_services()`：`if (! (mud_svc[mud]["finger"/"tell"] & SVC_KNOWN))` 块里只有 `#if PREF_X & SVC_TCP … #endif`，选项关闭时 if 为空（“无副作用”警告报在下一句）；把 `#if`/`#endif` 挪到 if 外面（KB 04，2026-10-07 那次扫描漏了 `! (` 加括号换行这种写法）。载入无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（同码副本）

- `u/angell/npc/shen.lpc`（及 `u/immortal/npc/nushen.lpc`）：三行 `(: call_other, __FILE__, "…_name_skill", who :);` 只造函数指针不调用，指向的是 `input_to` 式回调，原意无法确定，改成注释（行为不变，与 shenmo 同）。`d/youxia/npc/shaolong.lpc` 注释掉的 `chat_msg` 中漏注释的一行、`u/stey/cron.lpc` 只剩注释的 `if (tang) { }` 一并注释。
- 改动的对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。4 个文件 8 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/cmds/std/exercise.lpc`（`force_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 wuhanzhan/xlqy_early 同源同修）：
  - `d/kaifeng/ground.h` 加 `GROUND_TABLES_INHERITED` 守卫；`colors.h` 加防重复包含。
  - `jiasha.lpc` 的 `init()` 先后调用 `cloth::init()` 与 `unique::init()`。
  - `yaoguai_type` 的重复声明去掉。
  - `feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`（与 NPC 自己存档的同名字段分开）。
  - `lijing`/`xiwangmu` 的 `die`/`unconcious` 和 `yutu`/`jinren` 的 `kill_ob` 改 `void`。
  - `reporting.lpc` 未用的 `str` 删去；`roommaker` 被覆盖的 `special_props` 表删去；没有定义的 `int long();` 原型删去。
  - 改动的对象 HEAD 与工作树各载入一次，无回退。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。5 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

5 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。本库人物只有 kee/sen（连 gin 也没有）：药物的 `receive_heal("gin", 60)`、NPC 的 `receive_curing("gin", ...)` 和来自侠客行体系的 qi/jing 调用都报 `伤害种类错误`。13 个文件按 gin→sen、qi→kee、jing→sen、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/lingtai/shijie5`、`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：药（人参、熊胆、狐狸皮、虎骨，`clone/drug/cb_renshen`、`clone/drug/hugu`、`clone/drug/hulipi`、`clone/drug/xiongdan`）吃下后没有移走，31 秒后才销毁，这期间还能交给别人再吃一次。4 个文件改为移进本库的虚空房间 `VOID_OB`（`/obj/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

17 个文件、21 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/d/city/npc/obj/bingfu`、`/d/obj/weapon/staff/tc_staff`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 18 个（17 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`UNARMED` → `/std/weapon/unarmed`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：1 个里 1 个通过。


## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 5 个对象设了本库没有文件的武功（9 个名字，最多的是 `cuff`、`medical`、`strike`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：5 个里 4 个通过，其余 1 个停在别的错误上（`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/medicine/pill`（宏 `PILL`）←sjshwzb，9 个对象继承它，抽样 9/9 载入；`/std/weapon/halberd`（宏 `HALBERD`）←sjshwzb，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 15 处、15 个文件：`dagonforce`→`dragonforce`（4 处）、`lahua-shou`→`lanhua-shou`（2 处）、`yange_blade`→`yange-blade`（2 处）、`changqaun`→`changquan`（2 处）、`dragon-step`→`dragonstep`（2 处）、`hellfire_whip`→`hellfire-whip`（1 处）、`lingyi-sword`→`liangyi-sword`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 3 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill_wiz/whip/jueqingbian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 1 处：`/d/pkdao/room1.lpc` 的 `greeting()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MUSIC_D`、`WEAPON_OB`、`F_DISASTER`，用到它们的物件（名单里 5 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 3 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/nanhai/npc/maihuanu1` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 补回本库没有的基类文件，第二轮（2026-10-19，KB 04 §6.15、§6.18）

宏有定义、基类文件却不在档案里：继承它的对象载入时报 `Inherited file '…' does not exist!`，编译扫描看不到这一类（`scripts/lpc_missing_inherits.py` 能列出）。同系的库里有同一个文件，原样拷来（`scripts/lpc_restore_bases.py`）；基类和继承它的对象 include 而本库没有的头文件一起带来。每个基类补回后单独载入，再载入使用它的对象，载不进来、或一个用户也载不进来的撤掉了。

- `/std/item/yueqi`（宏 `YUEQI`）←sjshwzb：1/1 个继承它的对象载入
- `/std/medicine/powder`←sjshwzb：1/1 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/calvin/lanling/yuhuayuan.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 11 处）。改动：`/cmds/wiz/dns.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/longzhu/npc long.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/daemon/class/tianpeng/fofa/only.lpc`（1 处）、`/daemon/class/tianpeng/fofa/onlyu.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。
