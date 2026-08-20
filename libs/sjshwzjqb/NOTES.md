
## WASM 修复摘要（迁移自 meta.json 的 group_note）

三界神话「泉州师院」完整加强版，sjsh 家族集群的第五个也是最后一个。和 sjshwzb 同一血统——逐字节相同的 bug 组合：master.lpc 的 log_error()/standard_trace() 里没有 CHANNEL_D 呼叫（§7.60 不适用），securityd.lpc 的 valid_read() 从不覆盖驱动的 user 参数（§7.59 不适用），没有 sited.lpc（没有回环闸门）。WASM 修复：（1）熟悉的 convertd.lpc 字节级损坏（45 行，和 sjsh/sjshv150/sjshwzb 完全相同的 0xce/0xb2/0xee/0x96/0xa3 非法字符签名，第 258 行附近，同样的"杂散非 UTF8 字节转义闭合引号"模式）——用标准的字节级 Python 脚本修复。（2）adm/daemons/logind.lpc 里 §8.1 类的 check_legal_name() i%2 奇偶门槛，和 sjshwzb 完全相同的 bug 和修法：改成逐字符呼叫 is_chinese(name[i..i])，不设奇偶门槛，长度界限从字节数（2-12）改成字符数（1-6）。adm/simul_efun/chinese.lpc 的 is_chinese() 本来就是正确的码点区间检查——不用修。emoted.lpc/message.lpc/channeld.lpc：直接检查过，已知的 bug 都不存在也不需要修。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这份快照的 wizlist 档案是空的/只有空白字符，不像 sjshwzb 那份已经有两个其它巫师——是全新写入的）。注册流程在一次连续的 WASM 客户端会话里完整验证过，和 sjshwzb 完全相同的流程（GB/BIG5 选择→非学生关卡→"new"→英文 id→中文名字→管理密码+普通密码，必须不同→电子邮件，需要 xxx@xxx.xxx 格式→可选的个人主页/ICQ→性别→拒绝赠礼→属性分配），全程没有意外错误。管理员权限已直接通过登录横幅"您的系统权限目前是：(admin)"确认。LPC 格式化工具对全部 11569 个档案运行（写入 11286 个，72 个因为杂乱的历史代码报错，211 个未改动）；还原了和 sjshwzb 相同的 2 个档案（panshi_dan.lpc、npc/mm.lpc），确认是转档之前就存在（作者一方，早于本轮）的缺引号损坏被格式化工具进一步重新加了空格。没有 :: 父类呼叫拆分命中。逐一比对了同一个 case 密集的档案（d/calvin/esman.lpc，内容和 sjshwzb 那份逐字节相同）——干净，没有语句被吞掉。通过去空白差异比对了全部 4 个 map.lpc 档案——所有差异都只是大括号排版风格（K&R 合并），内容零变化。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 42 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-08）

三界神话系列的第五个、也是最后一个档案。用原生驱动（`build-debug/src/driver`，端口 40173）通过 `scripts/tmux_mud.sh` 走完整轮，对照同家族已深挖的 `sjsh`（宝鸡站）/`sjshv150`（紫藤分站）/`sjshv2578bb`（测试二区）/`sjshwzb`（泉州师院完整版）NOTES.md 逐条核对候选 bug——README 已注明本档案和 `sjshwzb` 同源、核心文件（`master.lpc`/`securityd.lpc`/`logind.lpc`）与已知 bug 集合逐字节一致，但仍按项目惯例逐条独立验证，不直接照搬结论。

- **§7.97（sjsh 上发现的 LISTNODES 死亡死循环 bug）——不适用，已核实排除**：`work/include/net/config.h` 第 20 行 `#define LISTNODES ([ \` 本身就带着正确的续行反斜杠（`cat -A` 确认行尾是 `\^M$`，不是裸 `^M$`），`LISTNODES` 表项 `"SK": "61.141.216.74 6668"` 和 `sjshwzb` 完全相同（本档案与 `sjshwzb` 这个头文件是逐字节同源的少数几个文件之一）。为求实证，仍然用管理员测试角色 `fluffos`（中文名"紫电仙人"）在朱雀大街对 `疥顶小僧`（`d/city/npc/jieding.lpc`，命中用它注册的 id `xiaoseng`）打 `kill xiaoseng` 到真实死亡：屏幕只打印一次"你死了"，系统频道正常广播"【三界神话】某人：紫电仙人在长安城被疥顶小僧杀死了。"，角色被送进〖阴阳界〗（`/d/death/gate`），判官崔珏（朱笔判官 崔珏）自动完整走完"你莫乱跑→生死有命→翻生死簿→命不该死送还阳"对话，角色活着落地复活室〖荒郊小店〗（`/d/ourhome/kedian`，`气血：重伤`），全程 `log/debug.log` grep `dns_master`/`gchannel`/`No program in object` 均为零命中。确认本档案没有这个 bug。
- **§7.11（log_file 缺 assure_file 防护）适用，已修**：`adm/simul_efun/file.lpc` 的 `log_file()` 是裸 `seteuid(ROOT_UID); write_file(LOG_DIR + file, text);`，同一份文件里紧接着定义的 `assure_file(file)` 辅助函数从未被调用（和 `sjsh`/`sjshv150`/`sjshwzb` 相同的形状，不像 `sjshv2578bb` 已经用 `MONITOR_D->log_file()` 转发做了防护）；`ls work/log/` 确认本档案确实没有随仓库分发 `nosave/` 目录。已按既定套路修：补一行前向声明 `void assure_file(string file);`（`assure_file()` 在文本顺序上定义在 `log_file()` 之后，这个编译器不会自动做前向解析），并在 `write_file()` 前调用 `assure_file(LOG_DIR + file)`。防御性修复，本轮实测没有直接触发这几条日志路径（崩溃处理器、`promote` 指令），按既定"看到就修"的低风险改动处理。
- **§7.34（logind.lpc 遗留 debug printf）适用，已修**：`adm/daemons/logind.lpc` 第 772 行 `get_name()` 里，在 `ob->set("name", arg)` 之前有一行裸 `printf("%O\n", ob);`，会把登录对象的内部路径原样打印在中文名字确认和密码提示之间——用 `fluffos` 账号首次注册（中文名"紫电仙人"）时现场复现确认。已删除该行；重新走一遍注册/重连流程，全程 grep 输出确认没有任何 `login#`/`obj/user`/`/obj/login` 字样泄漏。全档案只有这一处 `printf("%O` 命中，`logind.lpc` 里没有第二条并行的"接受系统建议名字"路径需要一并检查。
- **§8.13（sjshv150 上发现的 WIZ 密码二次登录死锁）——不适用，本档案是完全不同的登录架构，和 `sjshwzb` 一致**：全档案 grep `wiz_password`/`get_wizpwd` 零命中——`adm/daemons/logind.lpc` 走的是双密码架构（管理密码 + 普通密码，注册时就必须两个都设置且不能相同），重新登录时只走一次 `get_passwd()`，没有任何"密码从未设置就永久卡死"的死结。用 `fluffos` 账号实测反复重连（含一次跨越驱动重启的重连，`score` 显示"您是第 三 次连接三界神话「泉州师院」"），每次都正常用普通密码登录进入游戏，无一次卡死，之前的死亡/复活状态（`重伤`、被杀害次数）也正确保留。
- **§8.15（sjshwzb 上发现的 Windows 大写 `.C` 文件 runtime case-mismatch 崩溃）——适用，已修，且比 `sjshwzb` 多发现一层新崩溃**：`obj/board/EMEI_B.C`（峨嵋"仙石碑"留言板）和 `d/emei/NPC/YINGKE.C`（峨嵋"女童"迎客 NPC）两份大写扩展名文件与 `sjshwzb` 完全对应（家族共享的同一处历史遗留）。`d/emei/huayanding.lpc`（〖华严顶〗房间）的 `create()` 里 `set("objects", (["npc/yingke": 1]))` 引用的小写路径解析到磁盘上不存在的位置（真实文件是 `d/emei/NPC/YINGKE.C`），`new()` 静默返回 `0`，紧接着 `std/room.lpc` 的 `make_inventory()` 对 `0` 调用 `ob->move(...)` 抛出 `Bad argument 1 to EFUN call_other()`；同一 `create()` 末尾 `"obj/board/emei_b"->foo();` 既缺前导 `/`、又指向大写的 `EMEI_B.C`，同样解析失败。用 `update /d/emei/huayanding` 强制重编译复现（编译期干净，只有第一次真正 `reset()`/`setup()` 时才炸，和 `sjshwzb` 记录的诊断方式一致）。修复：`git mv obj/board/EMEI_B.C obj/board/emei_b.lpc`、`git mv d/emei/NPC/YINGKE.C d/emei/NPC/yingke.lpc`，`huayanding.lpc` 两处引用相应改成 `__DIR__ "NPC/yingke"` 和 `"/obj/board/emei_b"->foo();`，`emei_b.lpc` 顺带清理掉多余的 `replace_program(BULLETIN_BOARD)`（本档案自己的跨库 §7.86 扫描因为大写 `.C` 扩展名同样漏掉了这一处，和 `sjshwzb` 的 `EMEI_B.C` 完全同一形状）。**新发现的第三层崩溃、以及对 §8.15 修复本身的一处必要修正**：`yingke.lpc` 的 `create()` 有一句 `carry_object("/d/shaolin/obj/cloth.c")->wear();`，指向一个从未真正转档的路径（`work/d` 下没有小写 `shaolin` 目录，只有大写 `d/SHAOLIN/`，和 `sjshwzb` 完全同一形状），照搬 `sjshwzb` 已经验证过的 `std/char/npc.lpc::carry_object()` 存在性防护（`file_size(file) < 0` 直接 `return 0`）后，**这个防护本身在本档案上暴露了一个更大范围的假阴性回归**：`d/city/kezhan.lpc`（起始房间〖南城客栈〗）里的 `d/ourhome/npc/bigeye.lpc`（邮差"千里眼"，`README.md` 记载的邮件系统提示 NPC）的 `create()` 有 `carry_object("/d/ourhome/obj/linen")->wear();`——这个文件是**真实存在、正确大小写**的合法内容（`d/ourhome/obj/linen.lpc`），但因为调用方没带扩展名，新加的 `file_size(file) < 0` 检查对它也返回真（`file_size()` 是字面 `stat()`，不像 `new()`/`load_object()` 那样做 `.lpc`→`.c` 扩展名解析），于是**每一个全新角色第一次踏入起始房间就必定崩溃**——比原来"只影响峨嵋一间偏僻房间"的范围严重得多，命中率从"极少数玩家去过峨嵋"变成"100% 的新注册玩家"。已就地根治并记录为新的 AGENTS.md **§7.99**：把存在性检查改成同时探测 `file_size(file)`/`file_size(file+".lpc")`/`file_size(file+".c")` 三种形式都失败才判定为缺失。**已回填同一修法到 `sjshwzb` 自己的 `std/char/npc.lpc`**（该档案携带同一份 `bigeye.lpc`/`carry_object()` 组合，同样具备触发条件，现场重新验证：`fluffos` 账号重连南城客栈，`look` 显示"千里眼"正常在场，`debug.log` 无崩溃——详见 `sjshwzb/NOTES.md` 补充说明）。三处改完（大小写重命名 ×2、`carry_object()` 三态检查 ×1）后驱动重启验证：全新账号完整注册 → 落地〖南城客栈〗（`千里眼`/`店小二`/`小宁宁` 全部正常在场，无崩溃）→ `update /d/emei/huayanding` 手动重编译峨嵋房间"成功！"，`log/debug.log` 全程零 `Bad argument`/`No program in object`/`call_other`错误。
- **§8.9（食物/饮水初始化）不适用**：`confirm_gift()` 直接 `user->set("food", user->max_food_capacity())`/`user->set("water", user->max_water_capacity())`，没有对象混用、没有年龄闸门。测试角色 `fluffos` `score` 食物/饮水全程显示"正常"（满格）。
- **§7.88/§7.12（message() varargs 缺陷）不适用**：`adm/simul_efun/message.lpc` 里根本没有自定义 `message()` 包装函数（只有 `message_vision()`/`tell_room()`/`say()`/`printf()`），不存在"4 参数声明、3 参数调用"的缺陷形状；本轮死亡广播、频道消息等大量触发 `message`/`tell_room` 的路径全程零崩溃。
- **§8.3a（`private nomask command_hook`）不适用**：`feature/command.lpc` 里 `command_hook()` 声明就是 `nomask int command_hook(string arg)`，注释里留着一行被注释掉的旧声明 `// private nomask int command_hook(string arg)`，说明这条修复在更早的一轮已经存在。
- **§8.3b（`commandd.lpc` 的 `.c` 后缀 sscanf）不适用**：整个档案没有 `commandd.lpc` 这个文件，指令分派走 `feature/command.lpc` 的 `add_action` 机制。
- **§7.5（securd/securityd 自定义 ACL 拒绝编译期访问）不适用**：`adm/daemons/securityd.lpc` 的 `valid_read()` 对不在 `{read_file, file_size, stat, read_bytes, tail, ed_start}` 白名单里的 func 一律直接 `return 1`，不是"默认拒绝"的 fail-closed 形状；`!euid` 分支同样直接 `return 1`（放行），不是 §7.5/§7.98 那种"未认证即拒绝"的形状。本轮完整跑过注册、战斗、死亡、复活、`post`、`update`（触发大量首次编译/首次读取）等路径，`log/debug.log` 未观察到任何 access-denied 类报错。
- **§7.98（daemon `create()` 缺 `seteuid()`）不适用**：全程 `log/debug.log` 没有出现任何 preload 期的 `explode()`/`sscanf()` 崩溃（驱动启动日志本身也完全干净，只有大量无害的 `Unknown #pragma`/`Number of arguments to 'save'/'remove' disagrees` 编译警告）。
- **§7.90（eval cost 上限）本次未观察到问题，`config.fluffos` 保持项目默认 `700000` 未改动**：跨越注册、天赋分配、多次移动到未编译过的房间（朱雀大街、峨嵋华严顶等）、真实战斗到死、完整复活流程、`post`/`read`/`update`（连续多次强制重编译）等操作，全程未见任何 `cost limit reached`/`Too long evaluation` 报错。
- **§8.3/§7.68/§7.86 其它变体均未见新增实例**：`command_hook()` 无 `private`；没有第二个"WIZ 密码"式登录闸门；本轮死亡/复活是一次全新账号、无任何外力打断的正常流程，没有触及 §7.68 那种 present() 语义分歧，未做任何"重试代替放弃"式改动。
- **管理员写权限已现场验证**：用 `fluffos` 账号连续执行 `update /d/emei/huayanding`（两次，一次修复前的失败重现、一次修复后的成功确认）全部按预期动作，确认 `default_trusted_write` 对 `(admin)` 授予的不受限写入权限确实生效。
- **留言板 `post`/`read` 验证通过，§7.86 修复线上确认有效**：在〖荒郊小店〗对"生死之间留言板"（`obj/board/common_a.lpc`）成功 `post` 一条标题「深度测试」的留言并用 `look board` 读出，无崩溃。这份留言板数据在测试前是全新/空白的（`look board` 显示"没有任何留言"），不是转档带来的历史内容，测试留言在提交前已用 `git restore` 撤销（`git diff` 确认改动前后仅这一条新增记录，没有需要保留的历史内容）。南城客栈的"南城客栈留言板"全程显示"没有任何留言"，同样是空白状态，未受影响。
- **商店 `list` 验证通过**：荒郊小店"店小二"`list` 出炸鸡腿/红烧狗肉/西瓜/花雕酒袋及价格，`buy` 本轮时间有限未实测。
- **完整死亡→复活循环、注册、`look`/`score`/`quit`、二次重连均已现场验证**：全新角色注册（`new`→`fluffos`→中文名"紫电仙人"→双密码→邮箱→个人主页/ICQ 留空→性别→天赋分配 `9`/`y`→落地〖南城客栈〗）→移动到朱雀大街 `kill xiaoseng` 打死疥顶小僧（真实战斗，非秒杀）→"你死了"仅出现一次→〖阴阳界〗判官崔珏对话→复活落地〖荒郊小店〗（`重伤`但存活）→`post`/`look board`→`list`→`quit`（正常退出提示"你历了太多的江湖风风雨雨……"，连接干净关闭）；随后二次重连同一账号（`score` 显示"第 三 次连接"），`look` 正常，`quit` 再次干净退出。`log/debug.log` 全程 grep `执行时段错误\|Bad argument\|No program in object\|Segmentation` 零命中（仅有大量无害的 `编译时段错误：...Unknown #pragma, ignored`/`Unused local variable` 编译警告，与实际运行时错误无关）。
- **未覆盖**：帮派/门派拜师流程未触及；`d/emei/NPC/`、`obj/board/`、`d/SHAOLIN/` 之外的其它大写目录残留（和 `sjshwzb` 记录的一样，`find . -type d -regex '.*/[A-Z][A-Z0-9_]*$'` 命中多个非 `binaries/` 目录）未逐一探查是否也有类似的死链，留给后续转档专项；邮件系统（`千里眼` NPC 暗示存在）未实测具体指令。

## 家族总结（5/5 成员全部深挖完毕，2026-08-08）

`sjshwzjqb` 是三界神话「三界」系列 5 个档案家族（`sjsh`/`sjshv150`/`sjshv2578bb`/`sjshwzb`/`sjshwzjqb`）里最后一个完成 §10.7 深度功能测试的成员。基于本档案自己的发现和其余 4 份手足档案各自 NOTES.md 记载的结果，按 bug 类别汇总复现频率（分母固定为 5）：

| Bug 类别 | 命中家族成员数 | 备注 |
|---|---|---|
| §7.34（logind.lpc 遗留 debug printf） | 5/5 | 全员命中，逐一确认并删除，是本家族最普遍的问题 |
| §7.11（log_file 缺 assure_file 防护） | 4/5 | `sjsh`/`sjshv150`/`sjshwzb`/`sjshwzjqb` 命中；`sjshv2578bb` 通过 `MONITOR_D->log_file()` 转发已自带防护 |
| §7.86（board `inherit`+多余 `replace_program()`） | 5/5 | 全员命中（跨库扫描批量修复），另有 `sjshwzb`/`sjshwzjqb` 各自独立发现的一处大写 `.C` 扩展名漏网实例（§8.15 附带） |
| §7.97（LISTNODES 缺续行反斜杠死循环） | 1/5 | 仅 `sjsh` 命中，其余 4 份档案该头文件各自独立维护、内容不同源 |
| §8.13（WIZ 密码二次登录死锁） | 1/5 | 仅 `sjshv150` 命中；`sjshv2578bb` 通过 `#ifdef NO_CHECK_WIZPWD` 已自行规避；`sjshwzb`/`sjshwzjqb` 走双密码架构、压根没有这个登录闸门 |
| §8.15（大写 `.C` runtime case-mismatch 崩溃） | 2/5 | 仅 `sjshwzb`/`sjshwzjqb`（同一血统分支）命中，`sjsh`/`sjshv150`/`sjshv2578bb` 无此内容 |
| §7.99（`file_size()` 存在性检查对无扩展名路径假阴性，本轮新增条目） | 2/5 | `sjshwzjqb` 现场发现并修复，回填修复到同血统的 `sjshwzb` |
| §8.9/§7.88/§7.12/§8.3a/§8.3b/§7.90/§7.5/§7.98 | 0/5 | 全员均不适用（各自独立验证，非假设性排除） |

结论：这个家族最稳定、跨全部 5 个快照复现的问题是 §7.34（遗留调试输出）和 §7.86（留言板崩溃），说明这两处很可能是某个更早的共同祖先档案里就已经存在的缺陷，被逐代快照原样复制。§7.97/§8.13/§8.15 则是各快照独立分叉演化后产生的差异——同一代码库的不同存档时间点，会因为管理员各自的修补历史不同而携带不同的遗留 bug 子集，"血统相同"不能替代逐份验证。§7.99 是本轮唯一一个纯技术性的新发现：不是这份档案原始代码的 bug，而是本项目自己在移植 §8.15 修复时引入的一个新的假阴性风险，提醒未来任何"加一层 `file_size()` 存在性检查"式的防御性修复都要连带检查同一辅助函数的其它调用方。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 644 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），636 处脚本自动
删除；另有 4 份房间建造工具副本手动修正——`obj/roommaker.lpc`、
`u/calvin/obj/roommaker.lpc` 是标准的"两套模板"简单变体；
`u/qkl/roommaker.lpc`、`u/koker/obj/teshu/roommaker.lpc` 是手足
`sjshwzb` 同批也命中的"3 处出现"`room_code`/`str` 变体，三处均手动
删除。`work/data/room/*.lpc`（4 个文件，与 `sjshwzb` 同名同构）确
认无此调用，无需处理。修复后全库仅剩 26 处历史遗留的
`//`-注释掉实例，均确认无害、未改动。已用 `build-debug` 驱动干净
启动验证（0 个新增编译错误，端口 40173 正常监听，`debug.log` 无新
增 "cannot replace"/"cannot bind" 行）；未做完整 §10.7 深度游玩
测试。
