
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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 11 file(s) `inherit F_SSERVER;` and no header defines it (11 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply sjshwzb`: 278 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 3 path reference(s) in 3 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 372 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 103 PASS -> 361 PASS, 0 that loaded before fail now, 258 more load.

In total 335 files differ from the old names (249 `.C` -> `.lpc`, 83 files of renamed directories, 2 `.H`, 1 `.bak`): the references-driven run (278 moves) and `--dos` (79 more: the other `.C` / `.H` files of those directories and the all-upper-case directory names in them, `daemon/skill/MAHAYANA.C` among them). The code is the same as `sjshwzjqb`'s, and so is the finding: `std/room.lpc` `make_inventory()` now `catch`es `new(file)` (`scripts/lpc_resilient_room.py`), because the NPCs behind the renamed directories exist for the first time and some of them raise in `create()` (the six `d/mojie/npc/*` need a skill `molianspells` this archive does not have); the 11 objects of the load check that still fail (those six, two NPCs whose `carry_object()` item is not in the archive, `d/dntg/yunlou/npc/yg-shaolin.lpc` (its base `yaoguai` is missing), `d/youxia/npc/maihuanu1.lpc` (`init()` twice), `std/weapon/_qin.lpc` (`#include "qin.c"`)) are content gaps. A rescan with `scripts/lpc_warnings.py sjshwzb` is still due.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 280 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/stey/u/lestat/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`u/stey/u/lestat/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 3 个，工作树三次分别通过 3、3、3 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

与 `sjsh` 同代码的 779 个文件照搬 `sjsh` 的修复（`scripts/lpc_twin_port.py adopt sjsh sjshwzb`，757 个按格式化重写、17 个拼接、5 个原样；非 ASCII 文字检查无差异），其余由 `scripts/lpc_warnings.py sjshwzb --fix` 处理（无用局部变量 1004 个、`varargs` 16 处、转义 24 处），共改动 1223 个 `.lpc`。HEAD 与工作树分别加载（新进程）：1188 -> 1188 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 20 条候选都是声明被重建。启动时警告 197 -> 0。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 26 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 8 个，只在 #if 分支用的声明移进分支 0 个文件；改动 32 个文件，HEAD 与工作树各载入一次无回退（32 objects; HEAD PASS 30, tree PASS 30; regress 0; newly loading 0），这些文件的警告 54 -> 20。

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

- 2026-10-12：`u/stey/newjob/teamjob.lpc` 的组队任务用 `names[0][random(40)]` 选地点，而这张表只有 12 个地名，`random()` 落到表外时数组越界报错、任务中断。改成 `random(sizeof(names[0]))`（shenmo `u/stey/newjob/teamjob.lpc` 同类）。HEAD 与工作树各载入一次，regress 0。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

`scripts/toolkit_fix.sh` 加手工修复，能编译的文件里的警告 61 条（48 个文件）-> 0（`lpc_warnings.py sjshwzb` 重扫：11648 -> 11650 个文件可编译；剩下的诊断都在本来就编译不过的文件里）。本库的西游记底子与 mhxy 相同，mhxy 当天的修复（提交 a9cd825122a）有 8 个文件是 token 级孪生，用 `lpc_twin_port.py adopt` 搬过来：`d/kaifeng/ground1/2/3.lpc` 的 `GROUND_TABLES_INHERITED`、`ground.h` 的 `#ifndef` 表 guard、`npc/colors.h` 的 guard、`reporting.lpc` 未用的 `str`、`lijing.lpc` 的 `void die()/unconcious()`、`jiasha.lpc` 的 `init()`；其余照 mhxy 手工改。

**真问题：**
- `d/obj/cloth/jiasha.lpc` 锦镧袈裟：`inherit CLOTH; inherit F_UNIQUE;` 两个基类都有 `init()`，驱动只用 unique 的 `check_owner()`，cloth 的 `tear` 动作丢了；叶子里写 `init() { cloth::init(); unique::init(); }`。
- `u/koker/obj/axe.lpc`、`blade.lpc`：`inherit F_UNIQUE; inherit AXE/BLADE;` 之外又 `inherit ITEM;`（武器基类已带），`dbase` 等重复声明，HEAD 下两件神兵都载不进来；`toolkit_fix.sh` 删掉多余的 inherit 后能载入。

**其余：**
- `feature/alias.lpc` 的 `nosave int last_time`（命令频率计数，只有本文件读）与 `d/city/npc/sanhua-counter.lpc` 自己要存档的 `int last_time` 同名，改名 alias 这边为 `last_cmd_time`（同 mhxy），叶子与已有存档不动。
- `d/city/npc/yg/yaoguai.lpc`：自己的 `int yaoguai_type = 0;` 从来不读（只有基类 `d/dntg/yunlou/npc/yaoguai.lpc` 用），删掉；11 个 `yg-*` 的重复声明警告随之消失。
- `d/kaifeng/ground.lpc` 加 `GROUND_TABLES_INHERITED`；`d/moon/npc/yutu.lpc`、`d/lingtai/npc/jinren.lpc` 的 `kill_ob()` 改 `void`（仍调用 `::kill_ob()`，没人读返回值）；`d/longzhu/npc/long.lpc`、`d/wosshipg/long.lpc` 删掉没有函数体的 `int long();`（继承来的是 `string long()`）。
- `u/stey/newjob/teamjob.lpc` 的 `names` 与同被 `guo.lpc` 包含的 `zzzjob.lpc` 同名，改名 `team_names`（同 xkx 系列的处理）。
- `u/koker/obj/teshu/roommaker.lpc`、`u/qkl/roommaker.lpc`：`special_props` 声明了两次，代码只用后一份，删掉前一份。
- `d/close/npc/tang.lpc`、`u/angell/npc/tang.lpc`：NPC 与 SSERVER 都带 F_CLEAN_UP，写明 `clean_up()` 用哪一份（`lpc_name_winner.py`，行为不变）。
- `adm/daemons/toptend.lpc` 与 `u/stey/u/xintai/tmp/toptend.lpc` 有意重定义 `RICH_B/EXP_B/AGE_B`，前面加 `#undef`；`u/stey/u/vikee/network/dns_master.lpc` 的 `#if PREF_X & SVC_TCP` 挪到空 if 外面；`u/stey/u/rainy/` 下 10 个文件的多余 `;`。
- `toolkit_fix.sh` 另删了 7 个多余的 `inherit F_CLEAN_UP`（NPC/物品/武器基类已带）。

验证：改动文件、`d/kaifeng` 与 `d/city/npc` 全部对象、`/std` 及 `/std/char` 基类、`/obj/user` 共 360 个对象，HEAD 与工作树各用新进程载入：331 -> 333 通过（新增载入 axe、blade），regress 0；删除声明审计 0 项待看。360 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。6 个文件 11 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。5 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

9 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。本库人物只有 kee/sen（连 gin 也没有）：药物的 `receive_heal("gin", 60)`、NPC 的 `receive_curing("gin", ...)` 和来自侠客行体系的 qi/jing 调用都报 `伤害种类错误`。27 个文件按 gin→sen、qi→kee、jing→sen、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/lingtai/shijie5`、`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`emei-force`→`emeiforce`（`/d/emei/npc/baimei`）。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：药（人参、熊胆、狐狸皮、虎骨，`clone/drug/cb_renshen`、`clone/drug/hugu`、`clone/drug/hulipi`、`clone/drug/xiongdan`）吃下后没有移走，31 秒后才销毁，这期间还能交给别人再吃一次。4 个文件改为移进本库的虚空房间 `VOID_OB`（`/obj/void`），与原作把它们“停放”在巫师房间的用意相同。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

21 个文件、27 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/npc/obj/choupao`、`/u/tianlin/阿修罗界/obj/shixieshendao`、`/d/obj/weapon/sword/zijian`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 21 个（21 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`PILL` → `/std/medicine/pill`（9 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：9 个里 9 个通过。


## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 17 个对象设了本库没有文件的武功（16 个名字，最多的是 `shifo-zhi`、`molianspells`、`heilianforce`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：17 个里 16 个通过，其余 1 个停在别的错误上（`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/needle`（宏 `NEEDLE`）←mohuanshiji，2 个对象继承它，抽样 2/2 载入；`/inherit/char/snake`（宏 `SNAKE`）←shenmo，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 15 处、15 个文件：`dagonforce`→`dragonforce`（4 处）、`lahua-shou`→`lanhua-shou`（2 处）、`yange_blade`→`yange-blade`（2 处）、`changqaun`→`changquan`（2 处）、`dragon-step`→`dragonstep`（2 处）、`hellfire_whip`→`hellfire-whip`（1 处）、`lingyi-sword`→`liangyi-sword`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 5 个：`/d/qujing/xuanyuan/skill/fox-hand.lpc`、`/daemon/skill/boxing.lpc`、`/daemon/skill/fox-hand.lpc`、`/daemon/skill/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 5 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`、`MAILDIR`、`NEW_USER_LOCK`、`F_DISASTER`、`MUSIC_D`，用到它们的物件（名单里 6 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 2 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/nanhai/npc/maihuanu1`、`d/xuyi/npc/maihuanu1`、`d/youxia/npc/maihuanu1` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

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

- `/std/item/yueqi`（宏 `YUEQI`）←sjshv150：1/1 个继承它的对象载入

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/stey/obj/putao.lpc`、`/u/stey/obj/tao.lpc`。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 补回丢失的基类宏（2026-10-19，KB 04 §6.13、§6.16）

`include/globals.h` 补回 `UNARMED` 指向 `/std/weapon/unarmed`：`clone/newitem/newweapon/` 或 `d/city/obj/` 里 `inherit` 这些宏的物件找不到宏，载入失败（一个只在巫师目录的头文件里定义的宏，对正式文件不算已定义，`scripts/lpc_restore_macros.py` 以前把它当成了已定义）。补完后这些物件载入，没有警告。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：`valid_enable()` 对任何 usage 都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/daemon/skill/talk.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/calvin/lanling/yuhuayuan.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 11 处）。改动：`/clone/drug/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/longzhu/npc long.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/daemon/yish/medicine/liushen.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## 日志子目录没有人建（2026-10-20，KB 06 §7.310）

登录体检里 `write_file("/log/dlog/money", ...)` 报 `Wrong permissions for opening file /log/dlog/money for append.`：`log/dlog/` 没有任何东西创建，而 `scripts/wasm_keep_dirs.txt` 只列了这台机器上真实启动时建过的子目录。代码里写入 `/log/` 下的 `nosave`、`dlog`、`login`、`cmds`、`edit`，把 `log/cmds`、`log/dlog`、`log/edit`、`log/login` 补进了 `wasm_keep_dirs.txt`（试玩树和站点都会建出来）。

## `heall` 指令的条件被存档弄坏了：编译不过（2026-10-20，KB 04 §6.25）

`cmds/std/heall.lpc` 第 13 行是 `if (!me)->query_skill("medical", 1) < 1000`，后面一行单独一个 `)`，再多一个 `}`：`syntax error, unexpected L_ARROW` / `Illegal LHS`，`main()` 在第一条用到 `force` 的语句之前就结束了，指令从来没加载过（指令扫描里 `heall` 打印出这些错误）。损坏出在存档本身，不是转档造成的；sjsh、sjshwzb、sjshwzjqb 三个库的这个文件逐字节相同，别的库没有这一行。按提示语 `你还不会医术,不能疗伤。` 的意思，把条件还原成检查施救者（`ob`）的医术：`if ((int)ob->query_skill("medical", 1) < 1000) return notify_fail(...)`，去掉多余的 `}`（这是对原意的推断）。加载检查：HEAD 0 通过 / 1 失败，工作树 1 通过。
