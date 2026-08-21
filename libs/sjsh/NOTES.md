
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
