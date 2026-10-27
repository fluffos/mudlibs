
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

## 深度功能测试第二轮（2026-08-23）：死亡计数器、buy、拜师、大写目录死链、邮件系统

用既有的 `fluffos` 账号（§10.7 深挖账号）通过原生驱动（端口 40173）+
`scripts/tmux_mud.sh` 逐条核实 2026-08-08 那轮记录的「未覆盖」四项。
本档案和刚测完的同源手足 `sjshwzb` 逐字节同源的核心文件集合完全一致
（`combatd.lpc`/`weapon.h`/`std/room.lpc`/`d/nanhai/*`），所以本轮直接
对照 `sjshwzb` 那轮的发现逐项复核，而不是从头盲测——多数命中的是同一
血统里独立分叉演化出的同一个 bug。

- **被杀害次数计数器（`combatd.lpc` `killer_reward()`）——本档案自己的
  §10.7 深挖会话之前已经确认并修复（commit `74a85438aae`）**：这是
  `sjshwzb` 那轮现场发现的 bug（`killer->add("PKS", 1);` 之后缺
  `killer->add("PKD", 1); victim->add("DIE", 1);` 两行），因为两份
  `combatd.lpc` 逐字节相同，直接比对确认后原样移植过来，无需重新调查。
  本轮**现场复核**：`score` 基线"被杀害：0 次" → `kill xiaoseng`
  致死疥顶小僧 → 判官崔珏送还阳 → 复活后 `score` 显示"被杀害：1 次"，
  确认修复在真实驱动上生效，`debug.log` 全程无 `combatd` 相关报错。
- **`list`/`buy` ——真实 bug，已修（新发现，`sjshwzb` 没有这一处）**：
  南城客栈"店小二"（`d/city/npc/xiaoer.lpc`）的 `list` 指令
  （`feature/vendor_sale.lpc`/`d/city/npc/xiaoer.lpc` 的
  `do_vendor_list()`）现场执行时崩溃：`*No program in object
  '/d/lingtai/obj/shengmao'!`（"三界神帽"，货架上第五项商品）。追查到
  `d/lingtai/obj/shengmao.lpc` 第 8 行 `set_name( HIC "三界神帽 NOR ,
  ({...}) );` ——"三界神帽"这个中文字符串字面量缺了闭合引号（正确形状
  应为 `HIC "三界神帽" NOR`，对照同档案 `std/skill.lpc` 里
  `HIC "举世无双" NOR` 等一致写法确认），导致后面的 ` NOR` 被吞进字符串、
  再往后一路吞到下一个真正的引号（`"sheng mao"` 前那个），使编译器在
  随后的 `set("unit", "顶")` 等语句处把已经是合法 UTF-8 的中文字节序列
  当成裸源码字符解析，报 `Illegal character 0xe9` 等一串虚假的"非法字符"
  错误，最终整个档案 `*No program in object*`——和 README 记载的
  convertd.lpc"杂散非 UTF8 字节转义闭合引号"损坏是同一个根因类别（缺引号），
  只是这次落在货物档案而不是转档脚本产物。**逐字节比对确认 `sjshwzb` 的
  同名档案 `d/lingtai/obj/shengmao.lpc` 携带完全相同的缺引号损坏，同样
  会在 `list` 时炸——是两份档案共同祖先里就存在的 bug，不是本次转档
  引入的，但此前两轮 §10.7 测试都只测了 `list` 本身没崩（`sjshwzb`
  那轮的货架里没炸到这一项，或没触发到 `list` 全量遍历），这是本档案
  第一次真正命中并定位**。已在 `d/lingtai/obj/shengmao.lpc` 第 8 行
  补回闭合引号。`lpcc --batch` 确认档案编译通过；驱动重启后现场复测
  `list` 正常显示全部 12 项货物（含"三界神帽"），随后 `buy jitui from
  xiaoer`（炸鸡腿，八十文钱）用 `clone` 一两银子（一百文）购买，找零
  精确为"二十文钱"、炸鸡腿正确入包——找零/库存运算本身没有 bug。
- **拜师（`apprentice`）流程已实测，正反两条路径都正常，无 bug**：
  南海普陀山"大圣国师王菩萨"（`d/nanhai/npc/master.lpc`）对无门派角色
  `apprentice pusa` 正确按战功/佛法门槛拒绝（"老夫不收外门弟子……"），
  南门"赵神将"（`d/nanhai/npc/zhao.lpc`，`attempt_apprentice()` 的
  `else` 分支对非本门弟子直接收徒、无门槛）`apprentice zhao` 成功拜师，
  `score` 的"师承"字段正确显示"南海普陀山赵神将"。`feature/
  apprentice.lpc`/`cmds/std/apprentice.lpc` 机制本身没有 bug；具体
  门槛数值属于内容设计，未改动。（`sjshwzb` 用的是 `zuozhizhu.lpc`
  这个不同的掌门 NPC，本档案没有 `d/swordman-map/` 这个区域，改用
  同样具备"无条件收徒" `else` 分支的 `zhao.lpc`，效果等价。）
- **大写目录死链——和 `sjshwzb` 完全同一血统的三层修复，已提前在
  `apprentice` 测试前一并核实存在并修复**：`d/nanhai/npc/master.lpc`
  的 `carry_object("/d/xuyi/obj/tianlong")->wield()` 会命中
  `include/weapon.h` 缺失的 `HALBERD`/`F_HALBERD` 宏定义（对比同档案
  其它 14 种武器类型都有对应宏），这本来会让 7 个现役戟类武器档案
  （`d/xuyi/obj/tianlong.lpc` 等）编译期直接语法错误、`goto
  /d/nanhai/xiaoshi` 现场必崩，挡住 `apprentice pusa` 的第一次测试。
  比对 `sjshwzb` 那轮的诊断和修法（`weapon.h` 补
  `#define HALBERD "/std/weapon/halberd"` /
  `#define F_HALBERD "/std/weapon/_halberd"`）后原样移植过来，逐字节
  相同问题。同时移植了 `std/room.lpc` 的 `make_inventory()` 防护
  （`new()` 失败返回 0 时不再对 0 调用 `->move()`，改为 `if
  (!objectp(ob)) return 0;`）和 `reset()` `case 1` 分支的
  `objectp(ob[list[i]]) &&` 短路检查——`d/nanhai/zhulin0.lpc`（〖紫竹林〗）
  的 `objects` 表里同样有 `__DIR__ "npc/tianji": 1` 指向不存在的小写
  路径（真实文件是大写 `/d/youxia/NPC/TIANJI.C`），`goto
  /d/nanhai/zhulin0` 复现过同一个 `Bad argument 1 to EFUN call_other()`
  崩溃，修完后房间正常加载（缺失的 NPC 不出现，不崩）。`lpcc --batch`
  批量复查（11568 个档案，11261 通过/307 失败）确认失败集里只有已知的
  历史遗留死档案（`/d/nanhai/obj/tianlong` 等），没有新增回归。
- **邮件系统（"千里眼" NPC）已实测，机制本身没有 bug，但发现一个值得
  记录的"read"动词歧义（非崩溃，未改动）**：`d/ourhome/npc/bigeye.lpc`
  的 `inquiry` 表把"mail"/"发信"/"收信"等关键词映射到
  `send_mail()`/`receive_mail()`，`ask qianli yan about mail` 在
  南城客栈里成功领到一个私人信箱（`obj/mailbox.lpc`，`千里眼`只在
  `startroom` 里才发放）。`mail fluffos` 现场完整走完标题→正文
  （`edit()`，`.` 结束）→是否留底稿（y）的流程，成功寄出（因为收件人
  就是自己，`send_mail()` 的 `ppl && this_player()->visible(ppl)`
  分支直接命中同一个信箱对象，`from`/`readmail 1` 都能看到 2 封信）。
  **发现的歧义**：`obj/mailbox.lpc` 把 `do_read` 同时注册在 `"read"`
  和 `"readmail"` 两个动词上（`add_action("do_read", "read");
  add_action("do_read", "readmail");`），但南城客栈本身还有一块留言板
  （`obj/board/nancheng_b.lpc`，继承 `BULLETIN_BOARD`）也注册了
  `"read"` 动词；现场验证裸 `read 1` 命中的是留言板的 `do_read()`
  （返回"留言板上目前没有任何留言。"）而不是信箱的，`readmail 1`
  则正确显示信件内容——说明这个驱动/mudlib 的多对象同名动词搜索顺序里，
  房间内其它对象（留言板）的 `add_action` 排在玩家自己随身物品（信箱）
  前面。这不是崩溃、不是数据丢失（信件一直都在，只是要用没有歧义的
  `readmail` 才能读到），而且 mailbox.lpc 自己已经预留了无歧义的
  `readmail` 别名，符合"没有错误信号（崩溃/debug.log 报错/结构性
  计数器失效）的多半是设计/边界情况"的既定判断标准，所以**未作为 bug
  修复**，只记录在案，供后续如果要统一多对象动词优先级时参考。另外
  确认了信箱是房间绑定的临时道具：一旦离开 `千里眼` 所在的
  `startroom`（南城客栈），信箱会被自动收回（"你将信箱交回给邮差。"），
  角色死亡时也会被强制收回（"你看到紫电仙人的信箱破空而去……"）——均
  是既有设计，非 bug。测试产生的邮件数据（`data/mail/f/fluffos.o`）
  在提交前已删除，不留存测试内容。
- **管理员写权限、驱动重启持久化均已现场复核，与既有记录一致**：本轮
  全程使用既有 `fluffos` (admin) 账号，`score` 显示"第 五 次连接"，
  之前记录的〖重伤〗气血状态、门派/被杀害计数在跨会话/跨死亡后均正确
  持久化。

修复文件清单（本轮）：`d/lingtai/obj/shengmao.lpc`（缺引号，真实
崩溃修复）、`include/weapon.h`（补 `HALBERD`/`F_HALBERD` 宏，移植自
`sjshwzb`）、`std/room.lpc`（`make_inventory()`/`reset()` 空指针防护，
移植自 `sjshwzb`）。工具调用数约 90 次，在预算范围内。

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

- 8 file(s) `inherit F_SSERVER;` and no header defines it (8 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply sjshwzjqb`: 280 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 3 path reference(s) in 3 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 414 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 106 PASS -> 403 PASS, 0 that loaded before fail now, 297 more load.

In total 376 files differ from the old names (288 `.C` -> `.lpc`, 86 files of renamed directories, 2 `.H`, 1 `.bak`): two runs of the tool, the references-driven one (`d/SHAOLIN`, `d/Mojie`, `d/youxia/OBJ`, `d/emei/NPC`, the Shaolin/Emei/Mojie skill classes under `daemon/class`) and `--dos` (every other `.C` / `.H` file of those directories and the all-upper-case directory names in them: `daemon/skill/MAHAYANA.C`, the `u/piao` tree ...; the skills are looked up as `SKILL_D + name`, a computed path no scan sees; 399 moves in the two runs, 376 net). `std/room.lpc` `make_inventory()` now `catch`es `new(file)` (`scripts/lpc_resilient_room.py`): with the NPCs of the renamed directories reachable, the six `d/mojie/npc/*` NPCs (skill `molianspells`, which this archive does not have) and a few Emei items raise in `create()`, and without the `catch` the rooms that hold them stopped loading (21 more objects of the load check pass with it). The 11 objects of the load check that still fail (6 Mojie NPCs, two NPCs whose `carry_object()` item is not in the archive, `d/dntg/yunlou/npc/yg-shaolin.lpc` (its base `yaoguai` is missing), `d/youxia/npc/maihuanu1.lpc` (`init()` twice), `std/weapon/_qin.lpc` (`#include "qin.c"`)) are content gaps. A rescan with `scripts/lpc_warnings.py sjshwzjqb` is still due.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 280 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/stey/u/lestat/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`u/stey/u/lestat/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 3 个，工作树三次分别通过 3、3、3 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

与 `sjsh` 同代码的 779 个文件照搬 `sjsh` 的修复（`scripts/lpc_twin_port.py adopt sjsh sjshwzjqb`；非 ASCII 文字检查无差异），其余由 `scripts/lpc_warnings.py sjshwzjqb --fix` 处理（无用局部变量 1000 个、`varargs` 12 处、转义 24 处），共改动 1240 个 `.lpc`。HEAD 与工作树分别加载（新进程）：1206 -> 1206 通过，无回退；`scripts/lpc_audit_removed_locals.py HEAD` 的 20 条候选都是声明被重建。启动时警告 197 -> 0。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 26 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 7 个，只在 #if 分支用的声明移进分支 0 个文件；改动 31 个文件，HEAD 与工作树各载入一次无回退（31 objects; HEAD PASS 30, tree PASS 30; regress 0; newly loading 0），这些文件的警告 53 -> 20。

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

能编译的文件里的警告 61 条（48 个文件）-> 0（`lpc_warnings.py sjshwzjqb` 重扫：11609 个文件可编译，剩下的诊断都在本来就编译不过的文件里）。本库与 sjshwzb 同码：sjshwzb 当天的修复（提交 424584b9c2e）改的 42 个文件在这里全部是 token 级孪生（`lpc_twin_port.py classify`），用 `adopt` 原样搬过来，详细说明见 sjshwzb 的 NOTES.md 同名一节。

**真问题（与 sjshwzb 相同）：**
- `d/obj/cloth/jiasha.lpc` 锦镧袈裟：CLOTH 与 F_UNIQUE 两个 `init()` 只跑了 unique 的，cloth 的 `tear` 丢了；叶子里两个都调。
- `u/koker/obj/axe.lpc`、`blade.lpc`：武器基类之外又 `inherit ITEM;`，HEAD 下载不进来；删掉多余的 inherit 后能载入。

**其余：** `feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`（不再与三花计数器要存档的 `last_time` 相撞）；开封擂台 `ground*.lpc`/`ground.h`/`colors.h` 表 guard；`yaoguai.lpc` 不读的 `yaoguai_type`；`lijing`/`yutu`/`jinren`/`long` 的返回类型；`teamjob.lpc` 的 `team_names`；两个 roommaker 的重复 `special_props`；toptend 的 `#undef`；dns_master 空 if；多余的 `;`；9 个多余的 inherit；两个 tang 的 `clean_up()` 写明来源。

验证：改动文件、`d/kaifeng` 与 `d/city/npc` 全部对象、`/std` 及 `/std/char` 基类、`/obj/user` 共 360 个对象，HEAD 与工作树各用新进程载入：331 -> 333 通过（新增载入 axe、blade），regress 0；删除声明审计 0 项待看。360 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。6 个文件 11 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/daemon/class/shaolin/banruo-zhang/banruo.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

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

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 5 个：`/d/qujing/xuanyuan/skill/fox-hand.lpc`、`/daemon/skill/boxing.lpc`、`/daemon/skill/fox-hand.lpc`、`/daemon/skill/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 3 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`、`F_DISASTER`、`MUSIC_D`，用到它们的物件（名单里 4 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 2 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 同一个 init() 写了两遍、内容不同（2026-10-19，KB 06 §7.265）

`d/nanhai/npc/maihuanu1`、`d/xuyi/npc/maihuanu1`、`d/youxia/npc/maihuanu1` 里 `init()` 定义了两次（一个加 `buy`/`work` 之类的指令，另一个再加 `list`/`block_cmd`），驱动报 `Redeclaration of function 'init'`，整个物件载入不了。两处作者本来都要：把第二个 `init()` 里的 `add_action(...)` 并到第一个 `init()` 末尾，删掉第二个。（`scripts/lpc_merge_dup_init.py`）

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city/npc/duguoyin.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

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

## `heall` 指令的条件被存档弄坏了：编译不过（2026-10-20，KB 04 §6.25）

`cmds/std/heall.lpc` 第 13 行是 `if (!me)->query_skill("medical", 1) < 1000`，后面一行单独一个 `)`，再多一个 `}`：`syntax error, unexpected L_ARROW` / `Illegal LHS`，`main()` 在第一条用到 `force` 的语句之前就结束了，指令从来没加载过（指令扫描里 `heall` 打印出这些错误）。损坏出在存档本身，不是转档造成的；sjsh、sjshwzb、sjshwzjqb 三个库的这个文件逐字节相同，别的库没有这一行。按提示语 `你还不会医术,不能疗伤。` 的意思，把条件还原成检查施救者（`ob`）的医术：`if ((int)ob->query_skill("medical", 1) < 1000) return notify_fail(...)`，去掉多余的 `}`（这是对原意的推断）。加载检查：HEAD 0 通过 / 1 失败，工作树 1 通过。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 2 个存档共 2 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/data/city/花满.o`（1 处）、`/data/city/襄阳.o`（1 处）（共 2 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `cron.lpc`：`emery()` 用循环外的下标，第一次越界就让 cron 停摆（2026-10-21，KB 06 §7.345）

怪兽入侵事件 `emery()`（`/adm/daemons/cron.lpc`）末尾 `for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`：`i` 是前面随机选的地区下标，循环变量 `m` 没用上，同一个玩家被标记 `sizeof(user)` 次，在线人数不到 `i + 1` 时下标越界（`Array index out of bounds`，yueyingqiyuan 管理员扫描里的控制台行；`call /adm/daemons/cron->emery()` 一个人在线时四次里三次抛错）。`init_cron()` 在 15 分钟的整点调用 `emery()`，之后才 `call_out("init_cron", 60)` 重新排自己：抛错之后重排没有执行，玩家自动存盘（`autosave()`）、动态任务刷新（`TASK_D->init_dynamic_quest()`）和后面所有事件在这次启动里都停了。改成 `user[m]`（yueyingqiyuan 上实测：连续六次 `emery()` 都正常返回）。这个标记档案里没有任何地方读它（`go.lpc` 里的用法是注释掉的）。

## `full`（`cmds/arch`）：`else` 写了两遍，`help()` 里塞进了整个旧文件（2026-10-21，KB 04 §6.28）

`/cmds/arch/full.lpc` 编译不了（`unexpected L_ELSE`，修掉之后是 `End of file in text block`）：`main()` 里 `if (wizard) {...} else { if (!arg) ob = me; } else { ... }` 多了一段 `else`，`help()` 的 `@HELP` 文本里贴着整份旧版文件，没有结束符。去掉第一段 `else`，帮助文字只留 `指令格式 : full` 和一句说明（兄弟库的 `full` 写着“这个指令让你加满精气神。”），补上 `HELP`、`);`、`return 1;`、`}`。

## 观礼台 `d/city/under.lpc`：`wait_and_start()` 里的 `fan` 没赋值，比武开不了（2026-10-21，KB 06 §7.346）

接受挑战（`defend`）两秒后 `wait_and_start()` 调用 `fan->command("chat ...比武开始")`，`object fan;` 声明了却没有 `fan = load_object(__DIR__ "npc/fan");`（dtxywzxzb 的同一份文件有），抛错之后两条 `kill` 和 `call_out("finish_match", 300)` 都不执行，比赛不开始。补上这一句（`npc/fan.lpc`、`ground.lpc` 本库都有）。

## `ccast`、`ssteal`、`jji`、`pperform`：新手保护检查贴在目标赋值之前（2026-10-21，KB 06 §7.346）

`/cmds/std/jji.lpc`、`/cmds/std/pperform.lpc`、`/cmds/std/ssteal.lpc`：vikee 加的“本站暂时保护新手”检查 `if (userp(target) && target->query("age") < 16)`（以及后面两句 `... && userp(target)`）贴在 `target = present(...)` 之前。老驱动里 `userp(0)` 是 0，这几句从来不会触发；这里 `userp(0)` 抛错，指令一用就死。保持原来的（不触发）效果：赋值之前的 `userp(target)` 改成 `objectp(target) && userp(target)`。`pperform` 的检查还写着没声明的 `obj->query("target")`（整条指令编译不了），改成 `target->query("age")`，和其他几条一致。

## 七龙珠 `combine`：六次 `present()` 都存进了 `b`（2026-10-21，KB 06 §7.348）

每颗龙珠的 `do_combine()` 先检查身上有另外六颗：`if (!(b = present("liang longzhu", me))) ... if (!(b = present("fen longzhu", me))) ...`，六句都写成 `b =`，后面 `destruct(b); destruct(c); ... destruct(g)` 的 `c` 到 `g` 一直是 0。这几个库的 `destruct()` sefun 对 0 不抛错（原始 efun 也不抛），结果是合成神龙时只消耗了最后一颗和合成者自己，另外五颗还留在身上，可以反复合成。改成 `b, c, d, e, f, g`（shenmo 的 `/d/longzhu/obj/*` 是对的）。sjsh 上实测：HEAD 合成之后背包里还剩青、黄、蓝、粉、亮五颗，改后只剩神龙。改动：`/d/longzhu/obj/1.lpc`、`/d/longzhu/obj/2.lpc`、`/d/longzhu/obj/3.lpc`、`/d/longzhu/obj/4.lpc`、`/d/longzhu/obj/5.lpc`、`/d/longzhu/obj/6.lpc`、`/d/longzhu/obj/7.lpc`。

## 六道轮回 `ldlh`：`check_fight()` 里的 `weapon` 没赋值（2026-10-21，KB 06 §7.348）

施展后每秒的 `call_out("check_fight", 1, me)` 第一轮就在 `weapon->query("apply/skill_type")` 抛错，`remove_effect()` 永远不执行，`ldlh` 和 `lunhui` 两个标记一直留在身上。补 `weapon = me->query_temp("weapon");`（`perform()` 里同样的写法）。武器类型的判断原来是 `apply/skill_type != "stick" || (apply/skill_type != "stick" && skill_type != "stick")`，第一项恒真（本库没有任何武器设过 `apply/skill_type`），补上赋值后效果会在一秒后结束；去掉第一项，改成“两个属性都不是 stick 才结束”，并加 `!weapon ||`（卸了武器视同效果结束）。改动：`/daemon/class/ghost/kusang-bang/ldlh.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 40 条注册（24 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/drug/guiyuan.lpc`（`do_pour`）、`/clone/drug/huiyang-san.lpc`（`do_pour`）、`/clone/drug/shedan.lpc`（`do_pour`）、`/clone/drug/yangxin.lpc`（`do_pour`）、`/clone/drug/yulu-wan.lpc`（`do_pour`）、`/d/calvin/lanling/npc/guard1.lpc`（`do_bian`）、`/d/calvin/lanling/npc/gurad1.lpc`（`do_bian`）、`/d/calvin/lanling/x.lpc`（`do_swim`）、`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`） 等共 24 个文件。最多的函数名：`do_swim` 10 处、`do_pour` 5 处、`do_bian` 5 处、`do_fuming` 5 处、`do_cost` 2 处。没有动（读过）：`/d/wizz/stey/npc/rulai1.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/calvin/npc/wu.lpc`（`do_bian`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 2 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/cmds/std/go.lpc` ← fyzfqyy：`query_chinese_dir()`（1 处调用）。

## 代码里写死 `.c` 后缀的路径（2026-10-22，KB 06 §7.356）

`carry_object("/x/y.c")->wield()`、`new("/x/y.c")`、`inherit "/x/y.c"`、出口 `"down" : "/x/y.c"`、商店货单 `"/x/y.c" : 10` 这类字符串，压缩包里的文件早已改名成 `y.lpc`；明确写出的后缀按原样查找（KB 03 §4.2），找不到文件，`new()` 返回 0，`0->wield()` 报 `Bad argument 1 to EFUN call_other() Got int(0)`，NPC 的 `create()` 中途退出、整个对象加载不了。`scripts/lpc_fix_dotc_path.py` 把 17 个文件里的 19 处 `.c` 改成 `.lpc`（只改文件存在于 `.lpc`、不存在于 `.c` 的代码字符串；注释、巫师目录、两种写法都不存在的路径不动）：`/d/emei/obj/haotianjing.c`、`/d/city/obj/cloth.c`、`/d/shaolin/obj/cloth.c`、`/d/emei/npc/zhangmen.c`、`/d/kunlun/npc/zhangmen.c` 等。 加载检查（HEAD 与工作区对比，改动的 18 个文件）：HEAD 能加载 13 个，现在 18 个（新增可加载 5 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（inquiry 2, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/d/emei/npc/dan.lpc`:`ask_cancel`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。 另有 2 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/obj/board/xy_b`；`/d/qujing/xuanyuan/xuanyuan/dadian.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 5 个文件里 7 行只含这个指针的行（`"cancel": (: ask_cancel :),` `"出门": (: expell_me :),` `"leave": (: expell_me :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/tidu.lpc:126`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：6 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 6 处（3 个文件）：`if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {`（`/adm/daemons/loggind.lpc:897`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/d/city/npc/zhangsunwuji.lpc:163`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 10 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 6 处（3 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 兰陵出口仍指向 /u/calvin、大殿北去 /u/fly（2026-10-23，KB 06 §7.367）

可玩的兰陵已在 `/d/lanling/`（`lldj1`、`beijiao4` 等），出口字符串还写着作者目录 `/u/calvin/兰陵/地区/…`，走动即死出口；皇宫大殿北向 `/u/fly/doublesword/houdian` 同样不存在。`scripts/lpc_fix_calvin_lanling.py` 在目标 `.lpc` 存在时改写为 `/d/lanling/<stem>`，并删掉大殿那条北向。本库 9 处。证明：sjshv2578bb 的 `lldj1` 北向加载 `beijiao4`；xianlvqiyuan 大殿 HEAD 有北向、改后没有。未映射：`书局`、`钦陵宫`（库内无对应文件）。


## 阿修罗界出口仍指向 /u/tianlin（2026-10-23，KB 06 §7.369）

可玩的阿修罗区域已在 `/d/xiuluo/`（或 `/d/axiuluo/`、`/d/axlj/`），出口仍写作者目录 `/u/tianlin/阿修罗界/…`。`scripts/lpc_fix_tianlin_xiuluo.py` 在目标存在时改写，并优先跟源文件所在区名。本库 8 处。证明：shenmo `diyu5` HEAD 下向 `/u/tianlin/…/diyu6`，改后 `/d/xiuluo/diyu6` 可加载；sjshwzb `lu1` enter → `/d/axiuluo/lu2`。


## kill1 未赋值就读 obj、双 else 编不过（2026-10-27，KB 06 §7.348 Also）

`cmds/std/kill1.lpc` 在 `present(arg)` 之前调用 `obj->is_character()`（obj 仍为 0），且 `just_issued` 消息后有连续两个 `} else {`，驱动报 `unexpected L_ELSE`，对象从未加载。按同库 `kill.lpc` 重排为先 `!arg`、再 `present`、再 `is_character`；补上 `can_kill` 分支的 `do_kill`/`return`，把原误挂的第二段 `else` 收成 `can_kill` 的 else，并在 `do_kill` 定义前关闭 `main`。证明：HEAD `load_object("/cmds/std/kill1")` 失败；改后加载成功。


## xupdate 多一个 } 编不过（2026-10-27，KB 04 §6.28 Also）

`cmds/adm/xupdate.lpc`（与 sjsh / sjshwzb / sjshwzjqb 三份字节相同）在列目录后缀的 `while` 后又多了一个 `}`，提前关掉了 `main`，`write("目录…")` 落在函数外（`unexpected L_STRING`）；`updatefile` 里 `destruct(obj)` 前同样多了一个 `}`；且只声明了 `int i` 却在 `for` 里用 `j`。同族 mhxy / shenmo 的副本完好。去掉两处多余 `}` 并补上 `j`。证明：HEAD `load_object("/cmds/adm/xupdate")` 失败；改后加载成功。


## vikee 新手门在 present 之前（2026-10-27，KB 06 §7.348 Also）

`ssteal` / `pperform` / `jji` / `ccast`（及同族 `steal`/`cast`）里 vikee 加的年龄 / 经验 / 道行门用 `objectp(victim|target)`，却写在 `present()` 赋值之前：局部仍是 0，门永远不进。挪到 `present` 与空指针检查之后，并去掉多余的 `objectp`。证明：HEAD `ssteal` 仍在 `present` 前有 `objectp(victim)`；改后在其后且对象加载成功。


## 家丁 CLOTH_OB()/WEAPON_OB() 调用式宏（2026-10-27，KB 04 §6.16 Also）

`d/wuguan/npc/jiading.lpc`（及 `jiading1`，xlqy 系在 `d/dntg/hgs/wuguan/npc/`）写 `carry_object(CLOTH_OB("cloth"))` / `WEAPON_OB("changjian")`：库中没有带参的 `CLOTH_OB`，`WEAPON_OB` 在 `globals.h` 只是裸路径 `"/d/obj/weapon/"`，展开成 `"/d/obj/weapon/"("changjian")` 语法错误，NPC 无程序。同目录其它 NPC 用 `__DIR__ "obj/cloth"`；剑在 `/d/obj/weapon/sword/changjian`。改成这两条（目标文件均在树内）。证明：HEAD `Undefined function CLOTH_OB`；改后 `new()` 成功且 inventory 为 2。


## 黑风山 pusa1 用未声明的 ob 且函数外残留 call_out（2026-10-27，KB 06 §7.348 Also）

`d/qujing/heifeng/npc/pusa1.lpc` 的 `announce_success(object who)` 写成 `if (!ob->query("obstacle/hf"))`（`Undefined variable 'ob'`），同目录 `pusa.lpc` 是 `who->query("obstacle/hf") == "done"`；`who->save(); }` 之后还残留 `call_out("die"...); return; }`，落在函数外（`unexpected L_STRING`），对象无程序。改成与 `pusa` 相同的门，并删掉残留语句。证明：HEAD 加载失败；改后加载成功。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 洗衣盆 is_container 映射缺值编不过（2026-10-27，KB 04 §6.28 Also）

`d/gao/obj/pen.lpc`（或 `d/qujing/gao/obj/pen`）的 `is_container()` 写成 `set("objects", ([ "/u/bula/gao/obj/kaoji" ]));`：映射只有键没有值（`unexpected ']'`），对象无程序。同族 hy5 / xyj2000 已把该函数注释掉。改成标准的 `return 1;`。证明：HEAD 加载失败；改后加载成功。


## 月宫 quest/road 模板缺 index（2026-10-27，KB 06 §7.348 Also）

`d/moon/quest/road.lpc`（及误放在 `npc/road.lpc` 的副本）出口写 `sprintf("%d", index ± 1)`，却没有像 `road1`…`road10` 那样声明 `int index = N;`（`Undefined variable 'index'`），对象无程序。补上 `int index = 5;`（中间段，东西出口都能落到已有房间）。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。
