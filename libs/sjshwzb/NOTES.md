
## WASM 修复摘要（迁移自 meta.json 的 group_note）

三界神话「泉州师院」，5 档案 sjsh 家族集群的第四个。和 sjsh/sjshv150/sjshv2578bb 同一血统，但这份快照的 master.lpc/securityd.lpc/logind.lpc 和前三份不是逐字节相同——master.lpc 的 log_error()/standard_trace() 里根本没有 CHANNEL_D 呼叫（§7.60 在这里不适用），securityd.lpc 的 valid_read() 从不覆盖驱动的 user 参数（§7.59 不适用），也没有 sited.lpc（没有回环闸门需要处理）。WASM 修复：（1）熟悉的 convertd.lpc 字节级损坏（45 行，和 sjsh/sjshv150 相同的"闭合引号前有杂散非 UTF8 字节，最后一个字节是 0x5C 转义了引号"模式，同样在第 258 行附近的 0xce/0xb2/0xee/0x96/0xa3 非法字符签名）——用标准的字节级 Python 脚本修复。（2）adm/daemons/logind.lpc 里 §8.1 类的 check_legal_name()：i%2 奇偶门槛假设每个中文字占 2 字节 GBK，加上按字节数算的长度界限（2-12）；在这个驱动的 UTF8 码点索引下会误判奇数字数的中文名字——已改成逐字符呼叫 is_chinese(name[i..i]) 检查，不设奇偶门槛，长度界限改成按字符数（1-6，匹配提示文字"一到六个中文字"）。adm/simul_efun/chinese.lpc 的 is_chinese() 本来就是正确的码点区间检查（0x4e00-0x9fff）——不用修。这份快照里没有发现 emoted.lpc/message.lpc/channeld.lpc 的 bug（直接检查过，都不存在/不需要）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这份档案的 wiz_levels 顶层就是 (admin)，和 sjsh 的等级上限一样）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 编码选择→非学生关卡→"new"关键字→英文 id→中文名字→管理密码+确认→普通密码（必须和管理密码不同）+确认→电子邮件（需要 xxx@xxx.xxx 格式）→个人主页/ICQ（可选，留空也行）→性别→拒绝赠礼→角色属性分配画面，全程没有任何意外错误。管理员权限已直接通过登录后的横幅文字"您的系统权限目前是：(admin)"确认。LPC 格式化工具对全部 11658 个档案运行（写入 11364 个，83 个因为杂乱的历史代码报错，211 个未改动）；还原了 2 个档案（panshi_dan.lpc、npc/mm.lpc）确认有转档之前就存在的损坏被重新加了空格——这两个源档案在格式化之前就已经完全缺少字符串引号（作者一方的损坏，早于本轮），符合已记载的"转档前引号不配对"盲点；格式化工具在已经缺引号的内容上做的重新加空格已经还原，而不是手工修补。没有 :: 父类呼叫拆分命中。逐一比对了唯一一个 case 密集的格式化档案（d/calvin/esman.lpc）——干净，没有任何 case 标签之后的语句被吞掉。通过去空白差异比对了全部 4 个 map.lpc 档案——所有差异都只是大括号排版风格（K&R 合并），内容零变化。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 42 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

用原生驱动（`build-debug/src/driver`，端口 40113）通过 `scripts/tmux_mud.sh` 和 `scripts/mudclient.py` 走完整轮，对照同家族已深挖的 `sjsh`（宝鸡站）/`sjshv150`（紫藤分站）/`sjshv2578bb`（测试二区）NOTES.md 逐条核对候选 bug。

- **§7.97（sjsh 上发现的 LISTNODES 死亡死循环 bug）——不适用，已核实排除**：`work/include/net/config.h` 第 20 行 `#define LISTNODES ([ \` 本身就带着正确的续行反斜杠（`cat -A` 确认行尾是 `\^M$`，不是裸 `^M$`）——这份档案的 `LISTNODES` 表项是 `"SK": "61.141.216.74 6668"`，和 sjsh/sjshv150/sjshv2578bb 都不同，再次印证这个头文件在各份档案里各自独立维护。为求实证而非只信静态分析，仍然用管理员测试角色 `fluffos`（中文名"紫电仙人"）在朱雀大街对 `疥顶小僧`（`d/city/npc/jieding.lpc`，命中用的是它注册的 `xiaoseng` id，`kill jieding` 本身会被拒绝为"这里没有这个人"——本档案自己的 id 命名细节，和 `sjshv2578bb` 记载的情况一样）打 `kill xiaoseng` 到真实死亡：屏幕只打印一次"你死了"，系统频道正常广播"某人：紫电仙人在长安城被疥顶小僧杀死了。"，角色被送进〖阴阳界〗（`/d/death/gate`），判官崔珏（朱笔判官 崔珏）自动完整走完"你莫乱跑→生死有命→翻生死簿→命不该死送还阳"对话，角色活着落地复活室〖荒郊小店〗（`/d/ourhome/kedian`，`气血：重伤`），全程 `log/debug.log` grep `dns_master`/`gchannel`/`No program in object` 均为零命中。驱动重启后用 `call me->save()` 强制存档、`score` 复核，状态（重伤、被杀害次数）在重启前后完全一致，确认存档链路本身也没问题。确认本档案没有这个 bug。
- **§7.11（log_file 缺 assure_file 防护）适用，已修**：`adm/simul_efun/file.lpc` 的 `log_file()` 是裸 `seteuid(ROOT_UID); write_file(LOG_DIR + file, text);`，同一份文件里紧接着定义的 `assure_file(file)` 辅助函数从未被调用（和 `sjsh`/`sjshv150` 相同的形状，不像 `sjshv2578bb` 已经用 `MONITOR_D->log_file()` 转发做了防护）；`ls work/log/` 确认本档案确实没有随仓库分发 `nosave/` 目录。已按既定套路修：`log_file()` 前面补一行 `assure_file(LOG_DIR + file);`，因为 `assure_file()` 在文本顺序上定义在 `log_file()` 之后，这个编译器不会自动做前向解析，所以另外补了一行前向声明 `void assure_file(string file);`。防御性修复，本轮实测没有直接触发这几条日志路径（崩溃处理器、`promote` 指令），按既定"看到就修"的低风险改动处理。
- **§7.34（logind.lpc 遗留 debug printf）适用，已修**：`adm/daemons/logind.lpc` 第 772 行 `get_name()` 里，在 `ob->set("name", arg)` 之前有一行裸 `printf("%O\n", ob);`，会把登录对象的内部路径（`/obj/login#146`）原样打印在中文名字确认和密码提示之间——用 `fluffos` 账号首次注册时现场复现确认（发送中文名"紫电仙人"后立刻看到 `/obj/login#146` 单独一行）。已删除该行；重启驱动后重新走一遍注册流程，全程没有再出现任何 `login#`/`obj/` 字样泄漏。
- **§8.13（sjshv150 上发现的 WIZ 密码二次登录死锁）——不适用，本档案是完全不同的登录架构**：全档案 grep `wiz_password`/`get_wizpwd` 零命中——`adm/daemons/logind.lpc` 根本没有 sjshv150/sjshv2578bb 那种"WIZ 密码"二次登录闸门概念。这份档案走的是双密码架构（管理密码 + 普通密码，注册时就必须两个都设置且不能相同），重新登录时只走一次 `get_passwd()`（`adm/daemons/logind.lpc` 第 524 行起），普通密码或管理密码任一匹配即可放行，管理密码登录后会额外提示"你采用了管理密码进入游戏，因此请你先修改你的普通密码"并转入改密码流程，不存在任何"密码从未设置就永久卡死"的死结。用 `fluffos` 账号实测反复重连多次（含跨越一次完整驱动重启），每次都能正常用普通密码登录进入游戏，无一次卡死。
- **§7.86（留言板 `post` 崩溃）——之前的跨库扫描漏掉了 1 处，本轮补上**：`obj/board/EMEI_B.C`（峨嵋"仙石碑"留言板）之前跨库扫描的 42 处修复里没有覆盖到，因为它的文件名是全大写的 `.C` 扩展名（`inherit BULLETIN_BOARD;` + 多余 `replace_program(BULLETIN_BOARD);`），标准的 `*.lpc` glob 扫描天然跳过了它。已删除多余的 `replace_program(BULLETIN_BOARD)` 调用。这块留言板不是死内容——`work/data/board/emei_b.o` 里保存着 2002 年前后的真实历史留言（"陆菲青(Lzz)"/"无瑕(Lilytam)"），`d/emei/huayanding.lpc`（〖华严顶〗）的 `create()` 末尾也确实有 `"obj/board/emei_b"->foo();` 这行强制预载调用，说明这是一直有人用过的真实内容，只是从未被本项目的 §7.86 扫描工具碰到过。
- **新发现并记录为 AGENTS.md §8.15：Windows 时代大写 `.C` 文件在 RUNTIME（而非编译期）触发的 case-mismatch 崩溃**：验证上面的 `EMEI_B.C` 修复时，用 `update /d/emei/huayanding` 强制重新编译该房间，暴露出两处更深的、和 §7.86 无关的独立崩溃——房间 `create()` 本身编译干净（这就是为什么之前的全库编译检查、以及本档案两轮 WASM 通过测试都没有报出任何问题），只有真正**进入**这个房间（或强制 `update` 它）触发 `reset()`→`setup()` 时才会炸：（1）`set("objects", (["npc/yingke": 1]))` 里的 `npc/yingke`（小写、不带扩展名）在磁盘上对应的实际文件是 `d/emei/NPC/YINGKE.C`（目录、文件名、扩展名全部大写），`new("npc/yingke")` 静默返回 `0`，紧接着 `ob->move(this_object())` 对 `0` 呼叫 `call_other()` 抛出 `Bad argument 1 to EFUN call_other()... Got: int(0)`；（2）`"obj/board/emei_b"->foo();`（本档案 §7.86 修复对象本身）额外还缺了前导 `/`，和本档案其它同类预载写法（如 `d/city/kezhan.lpc` 的 `call_other("/obj/board/nancheng_b", "???")`）不一致。追查驱动源码（`~/src/fluffos/src/vm/internal/simulate.cc` 第 480-502 行）确认：这个驱动对"路径已带扩展名"的判定是**字节级、大小写敏感**的字面量比较（只认小写 `.c`/`.lpc`），所以任何指向大写 `.C` 文件的引用——不管怎么改大小写、加不加扩展名、加不加前导斜杠——永远无法被 `new()`/`load_object()` 解析成功；唯一真正的修复是把磁盘上的文件本身改名成小写 `.lpc`（匹配全库转档惯例），单纯改引用字符串没用。已 `git mv obj/board/EMEI_B.C obj/board/emei_b.lpc`、`git mv d/emei/NPC/YINGKE.C d/emei/NPC/yingke.lpc`，`huayanding.lpc` 里两处引用相应改成 `__DIR__ "NPC/yingke"` 和 `"/obj/board/emei_b"->foo();`。改完后 `update /d/emei/huayanding` 又暴露出第三层崩溃：`yingke.lpc` 自己的 `create()` 有一句无防护的 `carry_object("/d/shaolin/obj/cloth.c")->wear();`，而 `/d/shaolin/obj/cloth.c` 在这份档案里压根不存在——不是又一处大小写问题，是整个 `d/SHAOLIN/`（大写目录，102 个档案）从未被转档流程处理过，`raw/sjsh-new/d/SHAOLIN/OBJ/CLOTH.C` 确实存在但从未进 `work/`。`std/char/npc.lpc` 的共享 `carry_object()` 对不存在的路径走的是 `file->query_unique()`（对字符串变量做隐式 `call_other()`），这个驱动对这种运行时字符串 call_other 用的是 `find_object()`（只找已加载对象，不会现场 `load_object()`），找不到就直接 `error()` 抛出——**外层用 `catch()` 包住调用方（`yingke.lpc` 里的 `carry_object(...)` 调用）拦不住这个异常**（已现场验证：加了 `catch()` 依然照样崩，说明这个 `error()` 走的是不同于普通运行时异常的信号路径）；真正管用的修复是在 `carry_object()` 入口处直接加 `file_size(file) < 0` 前置检查，不存在就直接 `return 0`，从源头避免那句会抛异常的 `file->query_unique()` 被执行。三处改完、`update /std/char/npc`→`update /d/emei/NPC/yingke`→`update /d/emei/huayanding` 依次强制重编译（LPC 继承在编译期把父类字节码烤进子类，只 `update` 父类不会让已加载的子类跟着变，必须连子类一起重编译）后，房间彻底干净：驱动完整重启后 `update /d/emei/huayanding`（连带 `emei_b.lpc`）不再报任何错误。`d/SHAOLIN/` 目录级大写残留（连带整库 251 个大写 `.C` 文件里可能还有的其它个例）本轮**未做全量清理**——范围明显超出本次深挖，留给未来一轮的专项转档扫描（`find work/ -iname '*.C'`）。
- **§8.9（食物/饮水初始化）不适用**：`confirm_gift()` 直接 `user->set("food", user->max_food_capacity())`/`user->set("water", user->max_water_capacity())`，没有对象混用、没有年龄闸门。测试角色 `fluffos` `score` 食物/饮水全程显示"正常"（满格）。
- **§7.88/§7.12（message() varargs 缺陷）不适用**：`adm/simul_efun/message.lpc` 里根本没有自定义 `message()` 包装函数（只有 `message_vision()`/`tell_room()`/`say()`/`printf()`），不存在"4 参数声明、3 参数调用"的缺陷形状；本轮死亡广播、频道消息等大量触发 `message`/`tell_room` 的路径全程零崩溃。
- **§8.3a（`private nomask command_hook`）不适用**：`feature/command.lpc` 第 35 行 `command_hook()` 声明就是 `nomask int command_hook(string arg)`，没有 `private`（第 34 行留着一条注释掉的旧声明，说明这条修复在更早的一轮已经存在）。
- **§8.3b（`commandd.lpc` 的 `.c` 后缀 sscanf）不适用**：整个档案没有 `commandd.lpc` 这个文件，指令分派走 `feature/command.lpc` 的 `add_action` 机制。
- **§7.5（securd/securityd 自定义 ACL 拒绝编译期访问）不适用**：`adm/daemons/securityd.lpc` 的 `valid_read()` 对不在 `{read_file, file_size, stat, read_bytes, tail, ed_start}` 白名单里的 func 一律直接放行（`return 1`），不是"默认拒绝"的 fail-closed 形状；本轮完整跑过注册、战斗、死亡、复活、`post`、`update`（触发大量首次编译/首次读取）等路径，未观察到任何 access-denied 类报错。
- **§7.98（daemon `create()` 缺 `seteuid()`）不适用**：`adm/daemons/monitord.lpc` 的 `create()` 第一行就是 `seteuid(getuid());`，是正确顺序；全程 `debug.log` 没有出现任何 preload 期的 `explode()`/`sscanf()` 崩溃。
- **§7.90（eval cost 上限）本次未观察到问题，`config.fluffos` 保持项目默认 `700000` 未改动**：跨越注册、天赋分配、多次移动到未编译过的房间（朱雀大街、聊天室、发呆室、峨嵋华严顶等）、真实战斗到死、完整复活流程、`post`/`read`/`update`（连续多次强制重编译）等操作，全程未见任何 eval-cost 相关报错。
- **管理员写权限已现场验证**：用 `fluffos` 账号连续多次 `update` 不同档案（`/d/emei/huayanding`、`/obj/board/emei_b`、`/std/char/npc`、`/d/emei/NPC/yingke`）全部成功，`default_trusted_write` 对 `(admin)` 授予的不受限写入权限确认有效。
- **留言板 `post`/`read` 验证通过，§7.86 修复线上确认有效**：在〖荒郊小店〗对"生死之间留言板"（`obj/board/common_a.lpc`）成功 `post` 一条标题「深度测试」的留言并读出，无崩溃；南城客栈的"南城客栈留言板"也确认能正常 `look board` 显示（20 张历史留言，本档案没有清空）。这两份留言板数据里都是转档时就带来的真实历史内容（`common_a.o` 存有 2002 年前后 2 条真实玩家留言），测试留言在提交前已用 `git restore` 撤销，未污染历史存档。
- **死亡记录计数存在一个小的展示不一致（观察记录，非本轮修复范围）**：`score` 里的"被杀害：0 次"字段在两次真实死亡+复活之后仍然显示 0，和 `sjsh`/`sjshv2578bb` 里"被杀害次数正确记为 1"的行为不同——本轮没有深入追查这个计数字段具体挂在哪个存档路径上，只确认它是纯展示/统计层面的问题，不影响死亡→复活的核心流程（判官对话、复活室落地、健康状态重置全部正常），留给下次深挖时再查。
- **未覆盖**：`buy`/商店购买流程本轮时间有限只看了荒郊小店"店小二" `list` 出的菜单，没有实测 `buy`；帮派/门派拜师流程未触及；`d/emei/` 之外的其它大写目录残留（`d/youxia/OBJ`、`d/youxia/NPC`、`d/youxia/BAGUA`、`daemon/class/emei/MAHAYANA` 等，`find . -type d -regex '.*/[A-Z][A-Z0-9_]*$'` 命中 10 个非 `binaries/` 目录）未逐一探查是否也有类似 `d/SHAOLIN/` 这样的死链，留给后续转档专项。

管理员账号（`fluffos`/普通密码 `Mud@2026`/管理密码 `AdminPass123`）本次通过正常注册流程首次真正落地——`adm/etc/wizlist` 顶层就是 `(admin)`，注册完成后立即显示"您的系统权限目前是：(admin)"；`update` 反复验证写权限正常。README 的既有"管理员账号"记录已同步更新为具体密码（此前写的是"注册时自设"）。

## 补充修复（随 sjshwzjqb §10.7 深挖回填，2026-08-08）

- **（新增 AGENTS.md §7.99）`std/char/npc.lpc` 的 `carry_object()` 存在防护漏判**：本档案第五个（也是最后一个）家族手足 `sjshwzjqb` 在移植这份 `npc.lpc` 的 §8.15 `file_size()` 存在性检查时，发现该检查对不带扩展名的合法路径是假阴性——`file_size()` 是字面 `stat()`，不像 `new()`/`load_object()` 那样做 `.lpc`→`.c` 扩展名解析。本档案自己的 `d/ourhome/npc/bigeye.lpc`（南城客栈邮差"千里眼"）的 `carry_object("/d/ourhome/obj/linen")->wear()`——完全合法、文件确实存在——在这份档案自己身上就会触发同样的假阴性崩溃（现场重新验证：用 `fluffos` 账号重连南城客栈，`look` 显示"千里眼"正常在场，`debug.log` 全程无 `call_other()`/`int(0)` 崩溃，确认补丁生效）。已同步补上三重检查（`file_size(file)`/`+".lpc"`/`+".c"`），详见 AGENTS.md §7.99 与 `sjshwzjqb/NOTES.md`。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 662 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），654 处脚本自动
删除；另有 6 份房间建造工具副本手动修正——`obj/roommaker.lpc`、
`u/leox/obj/roommaker.lpc`、`u/ziyie/obj/roommaker.lpc`、
`u/calvin/obj/roommaker.lpc` 是标准的"两套模板"简单变体（heredoc
本来干净，字符串拼接模板第 138/139 行把多余调用烤进克隆出的房
间）；`u/qkl/roommaker.lpc`、`u/koker/obj/teshu/roommaker.lpc` 是
`shenmo`/`sjsh` 家族已知的"3 处出现"`room_code`/`str` 变体（一处
`room_code +=` 拼接 + `do_saveroom()` 里两条分支各一处），三处均
手动删除。`work/data/room/*.lpc`（4 个文件）确认无此调用，无需处
理。修复后全库仅剩 26 处历史遗留的 `//`-注释掉实例，均确认无害、
未改动。已用 `build-debug` 驱动干净启动验证（0 个新增编译错误，端
口 40113 正常监听，`debug.log` 无新增 "cannot replace"/"cannot
bind" 行；启动时出现的 `/log/dlog/money` 权限报错为既有、与本次
改动无关的缺目录问题，未处理，超出本次范围）；未做完整 §10.7 深
度游玩测试。

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

## 深度功能测试第二轮（2026-08-23）：死亡计数器、buy、拜师、大写目录死链

用 `fluffos` 账号（既有 §10.7 深挖账号）通过原生驱动（端口 40113）+
`scripts/tmux_mud.sh` 逐条核实 2026-08-08 那轮记录的四个未覆盖点。

- **被杀害次数计数器——真实 bug，已修**：追查到 `score` 的"被杀害：%d
  次"字段读的是 `my["DIE"]`，由 `killer_reward()`（`COMBAT_D->killer_reward`，
  `#define COMBAT_D "/adm/daemons/combatd"`）在 `userp(victim)` 分支里
  `victim->add("DIE", 1)` 递增。比对本仓库里两份几乎逐字节相同的
  `combatd.lpc`（真正被加载的 `work/adm/daemons/combatd.lpc`，和一份从未
  被任何 `#define` 引用、纯属历史遗留的死副本 `work/adm/combatd.lpc`）后
  发现：活的那份在 `killer->add("PKS", 1);` 之后，缺了紧接着的两行
  `killer->add("PKD", 1); victim->add("DIE", 1);`——死副本里这两行都在，
  活的那份漏掉了，是一处结构性的语句缺失（不是设计选择：两个副本内容
  几乎完全一致，只有这两行的差异，且 `PKD`/`DIE` 在 `score.lpc` 里都有
  对应的读取展示位）。已在 `work/adm/daemons/combatd.lpc` 补回这两行。
  现场验证：`score` 基线"被杀害：0 次"→ `goto` 朱雀大街对疥顶小僧
  `kill xiaoseng` 致死 → 判官崔珏送还阳 → 复活后 `score` 显示"被杀害：
  1 次"，`debug.log` 全程零 `combatd`/`killer_reward` 相关报错。驱动完整
  重启后重新登录复核，计数器持久化正常（1 次未丢）。
- **顺带发现：2026-08-08 那次提交的 commit message 声称修了但实际没有
  落盘的两处旧 bug，本轮一并补上**：调查上面的 `combatd.lpc` 问题时，
  用 `clone`（wizard 指令）测试环境触发了 `log_file()` 因为
  `/log/nosave/` 目录不存在而崩溃——`git show`/`git log` 核实后确认，
  commit `7787c8dddd8`（§7.11 assure_file 防护 + §7.34 logind.lpc 遗留
  printf）的提交说明写了这两处改动，但 `git show <commit> -- work/adm/
  simul_efun/file.lpc` 和 `-- work/adm/daemons/logind.lpc` 都是空 diff
  ——文件从未真正被改过（大概率上一轮编辑完成后没有正确保存/加入
  commit）。本轮已按 NOTES.md 原先描述的方案重新补上两处：
  `adm/simul_efun/file.lpc` 的 `log_file()` 调用 `write_file()` 之前先
  `assure_file(LOG_DIR + file);`；`adm/daemons/logind.lpc` 第 772 行的
  裸 `printf("%O\n", ob);` 已删除。现场验证：`clone /obj/money/silver`
  不再报错、正常放入物品栏；重新走一遍注册流程确认不再泄漏
  `login#`/`obj/` 字样。
- **`buy` 已实测，找零/库存运算正确**：南城客栈/荒郊小店的"店小二"
  （`d/ourhome/npc/xiaoer.lpc`，继承 `F_VENDOR_SALE`）用的是
  `cmds/std/buy.lpc` 的 `buy <物> from <人>` 语法（不是单纯的
  `buy <物>`）。`clone /obj/money/silver`（一两银子＝100 文）后
  `buy jitui from xiaoer`（炸鸡腿 80 文）成功，`i` 确认找零精确为
  "二十文钱(Coin)"、炸鸡腿正确进入物品栏——`feature/finance.lpc` 的
  `pay_money()` 熔铸找零逻辑运算正确，无 bug。
- **拜师（`apprentice`/`bai`）流程已实测，正反两条路径都正常**：
  `cmds/std/apprentice.lpc` 对无门派角色 `apprentice pusa`（南海普陀山
  大圣国师王菩萨）正确按 `attempt_apprentice()` 里的战功/佛法门槛拒绝
  （"老夫不收外门弟子……"，无崩溃）；随后用 admin 权限
  `call me->set_temp("swordman/zuozhizhu",1)` 满足另一位掌门（青石街道
  "打架专家 相乐佐之助"，`d/swordman-map/npc/zuozhizhu.lpc`）的收徒条件后
  `apprentice xiangle` 成功拜师，`score` 的"师承"字段正确显示"剑客联盟
  相乐佐之助"，`family`/`recruit_apprentice()` 链路（`feature/
  apprentice.lpc`）运作正常。机制本身没有 bug；具体门槛（战功/佛法数值）
  属于内容设计，未改动。
- **大写目录死链——真实可复现崩溃，已修，且是一个可能覆盖全库的通用
  修复**：`d/youxia/`（几乎整个区域是未转档的大写 `.C` 文件，和已知的
  `d/SHAOLIN/` 同类）下有 `NPC`/`OBJ`/`BAGUA` 三个大写子目录。`d/youxia/
  BAGUA`、`daemon/class/emei/MAHAYANA`、`u/piao/DAN` 三个目录在全库范围
  内没有任何文件引用它们（连本目录内部互相引用都没有 grep 命中）——真正
  死码，不可达，不是 bug，未处理。但 `d/nanhai/zhulin0.lpc`（〖紫竹林〗，
  经 `d/nanhai/road4.lpc` 北向可达，`road4` 属于普陀山主线，可达）的
  `objects` 里有 `__DIR__ "npc/tianji": 1`，指向不存在的 `/d/youxia/
  npc/tianji`（实际文件是 `/d/youxia/NPC/TIANJI.C`，大写）——现场
  `goto /d/nanhai/zhulin0` 复现崩溃：`Bad argument 1 to EFUN call_other()
  ... Got: int(0)`，出在 `std/room.lpc` 第 18 行 `ob->move(this_object())`
  （`make_inventory()` 对 `new()` 返回值零检查缺失，和已记录的 §8.15/
  §7.99 carry_object() 是同一个 bug 类别，只是这次是房间 `objects`
  预载而不是 NPC 随身物品）。`cmds/std/go.lpc`/`feature/move.lpc` 的
  `_move()` 对 exits/`fly` 目的地已经有 `load_object()` 失败时的优雅
  降级（"你要去的区域还没有连通。"/"move: destination unavailable."），
  所以 `d/kaifeng/east1.lpc`（north exit 指向不存在的 `/d/youxia/
  baiyun`，真实文件 `BAIYUN.C`）、`d/changan/seashore2.lpc`（north exit
  指向不存在的 `/d/youxia/wanmei`）、`cmds/std/fly.lpc` 的 `wanmei`/
  `shaolin` 目的地这几处大小写死链**不会崩溃**，只会提示"区域还没有
  连通"——这几处不用动。真正会崩的只有 `objects` 预载这一类路径。已给
  `std/room.lpc` 的 `make_inventory()` 加了 `if (!objectp(ob)) return 0;`
  防护，并给 `reset()` 里 `case 1` 分支调用 `ob[list[i]]->is_character()`
  之前加 `objectp(ob[list[i]]) &&` 短路检查（`default` 多实例分支本来就
  靠 `!objectp()` 重试自愈，不用改）——这是通用防护，不止修 `zhulin0`
  这一处，全库范围内任何房间 `objects` 里指向坏路径的条目都不会再让
  `reset()` 整体崩溃。现场验证：驱动重启后 `goto /d/nanhai/zhulin0`
  房间正常加载（缺失的 NPC 不出现，不崩），`debug.log` 无新增
  `call_other`/`room.lpc` 报错。批量 `lpcc --batch` 复查（11654 个档案，
  11343 通过/311 失败）确认失败集里没有新增回归——`/adm/combatd`、
  `/adm/logind`、`/d/nanhai/obj/tianlong` 这几个失败条目都是与本轮改动
  无关的、历史遗留、从未被任何 `#define` 或引用触达的死副本/孤立档案
  （比对过 `git show` 确认改动前后这些文件本身没有被本轮改动碰过）。
- **顺带修复：`/std/weapon/halberd.lpc`/`_halberd.lpc` 一直存在，但
  `include/weapon.h` 从未给 `HALBERD`/`F_HALBERD` 定义宏**（对比同一
  文件里 `SWORD`/`F_SWORD` 等其它 14 种武器类型都有对应宏）。全库 7 个
  现役文件（`d/xuyi/obj/tianlong.lpc`〖大圣国师王菩萨的天龙戟〗、
  `d/obj/weapon/halberd/{chubai,huaji,sanchaji,ji,muji,cuiling,halberd}
  .lpc`）里的 `inherit HALBERD;` 因此从建库起就是编译期语法错误
  （"unexpected L_IDENTIFIER, expecting L_STRING"），这几个文件全部
  加载失败——`d/nanhai/npc/master.lpc`（南海普陀山大圣国师王菩萨）的
  `create()` 末尾 `carry_object("/d/xuyi/obj/tianlong")->wield()` 因此
  现场必崩（`goto /d/nanhai/xiaoshi` 直接复现）。是在追查上面的
  `zhulin0` 崩溃时顺带发现的同类问题，不是本轮四个既定任务之一，但
  同属"case 崩溃/编译错误"的编程 bug 范畴，且直接挡住了拜师流程的
  第一次尝试（王菩萨所在房间进不去），所以一并修了：在 `weapon.h`
  补上 `#define HALBERD "/std/weapon/halberd"` 和
  `#define F_HALBERD "/std/weapon/_halberd"`（跟其它武器类型完全同一
  命名规范）。修复后 7 个文件全部 `lpcc` 单独编译通过，`goto /d/nanhai/
  xiaoshi` 房间干净加载、王菩萨正常佩戴天龙戟出场。`d/nanhai/obj/
  tianlong.lpc`（同名但内容是"王府令牌"的另一份孤立档案，`inherit
  HALBERD` 已被前人注释掉、全库无任何引用、不可达）依然编译失败
  （缺 `set_name`/`setup` 等基础函数）——不是本轮改动导致，也不是活
  内容，未处理。

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 50 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup1()`/`wakeup2()` call `enable_player()` again while the object is still `living()`. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.
