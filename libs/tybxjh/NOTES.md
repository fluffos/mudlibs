
## WASM 修复摘要（迁移自 meta.json 的 group_note）

天涯之碧血江湖（TIANYA.ZB 版），天涯泥潭巫师组，自 2002 年运营至今。在 WASM 下完全干净地启动运行——没有编译错误，没有运行时错误，整个代码库不需要任何修复。唯一采取的行动是把 fluffos (admin) 播种进 adm/etc/wizlist（SECURITY_D 正确指向 /adm/daemons/securityd，已通过 globals.h 确认；u/zjb/securityd.lpc 下有一份诱饵副本但没有被接上）。备注：securityd.lpc 的 get_status() 硬编码了 4 个具名 euid（daniel/zjb/kjh/jiji），不管 wizlist 内容如何都一律回传最高的 (boss) 等级——这是有意的创始人账号逻辑，不是 bug，也不影响 fluffos 账号。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→管理密码+确认→普通密码（必须不同）+确认→天赋数值选择（0 为随机，y 接受）→电子邮件（需要 id@address 格式）→性别→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过登录后的横幅"您目前权限：(admin)"确认。测试备注：这份档案强制执行一个真实存在的 150 秒 LOGIN_TIMEOUT（从连线那一刻用 call_out 计时，不是每个提示符重置），会把太慢的注册断线并提示"您花在连线进入手续的时间太久了"——这是真实、有意的 mudlib 行为（不是 WASM/测试artifact），已通过读取 clone/user/login.lpc 的 time_out()/LOGIN_TIMEOUT（150 秒，include/login.h）确认。早期测试用较长的 --idle（6-15 秒）来躲避编译警告刷屏的计时竞态，反而正好撞上了这个超时，因为 get_email()/get_gender() 会触发 /inherit/char/char 及其 feature 档案的一次沉重的一次性编译；改用较快的 --idle 2 能在窗口内顺利完成注册，这是这份档案特有的正确做法。LPC 格式化工具对全部 9398 个档案运行（写入 9303 个，61 个因为杂乱的历史代码报错，包括一处确认的转档前 token 不匹配跳过，34 个未改动）；还原了 1 个档案（d/city/sj.lpc）确认有转档之前就存在（作者一方，早于本轮）的缺引号损坏被格式化工具进一步重新加了空格。没有 :: 父类呼叫拆分命中。没有找到 case 标签带尾随注释的候选。逐一比对了全部 4 个 map.lpc 档案——3 个只是大括号排版（K&R 合并）；cmds/std/map.lpc 的 diff 一开始看起来更大，是因为一个很长的 sprintf() 呼叫被重新换行成多行，但去空白的全档案比对确认内容逐字节相同（2032 个字符，完全一致）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## 深度功能测试（§10.7，2026-08-05）

之前的 WASM 修复阶段结论"完全无需修复"过于乐观——这是同源"天涯"家族
（`wlhd`/`xhcii`/`zxty`/`ffxymud`/`jhfy2` 等）的原始代码库，先检查了
`wlhd` 自己已经完成的 §10.7 记录（2x printf 调试残留、§8.9 食物/饮
水年龄检查错对象、一处 `exert_function()` 类型错误），逐项在 `tybxjh`
自己的源码里核实，而不是假设结论可以照搬——结果全部命中，而且比
`wlhd` 更严重：

- **2 处 printf 调试残留**：`adm/daemons/logind.lpc` 的
  `get_resp()`/`get_name()` 里各有一处 `printf("%O\n", ob)`，每次注册
  都会把整个玩家对象的原始引用打印到连线画面上，和 `wlhd`（在同一批
  核心系统档案里）逐字节相同的 bug。已删除。
- **§8.9 食物/饮水年龄检查错对象**：`enter_world()` 里
  `if (ob->query("age") == 14)` 用的是登录对象 `ob` 而不是角色对象
  `user`——`ob` 根本没有 "age" 属性，这个判断永远不成立，导致每一个
  新角色的食物/饮水从创建起就一直是空的。已改为 `user->query("age")`。
  用临时的 `write_file()` 埋点验证过修复后确实生效：
  `age=14 weight=54000 maxfood=270 food=270`（角色自身的 body weight
  在这个判断执行时已经非零，不涉及 §7.77 那种"能力值依赖尚未穿戴装
  备"的顺序问题）。
- **`exert_function(10)` 类型错误，4 处（比 `wlhd` 的 1 处更多）**：
  `inherit/skill/skill.lpc` 的 `exert_function()` 需要一个技能名字符
  串参数，但 `d/zjb/shengji.lpc`（升级师 NPC）、`d/daniel/saveme.lpc`
  和 `d/player/ltsh/npc/saveme.lpc`（两份"大魔道士--雅薇丝"医疗 NPC）、
  `u/zjb/hlxy/zs.lpc`（转世僧人 NPC）的 `create()` 里都传了裸整数
  `10`——硬编译错误，导致这四个 NPC 全部从各自房间里静默消失，包括
  升级、疗伤、转世这几个实用性 NPC。已删除这行死代码（和 `wlhd` 对
  同类死代码的处理方式一致）。
- **一个从未被记录过的严重安全问题（已写入 AGENTS.md §7.84，标记为
  HIGH severity）**：双密码注册流程（每个账号都要设置管理密码+普通
  密码，不只是巫师）在正确地把密码哈希存进 `ob->set(...)` 之后，还
  额外把**明文密码**逐条追加写进 `/doc/help/neima2`（管理密码）和
  `/doc/help/neima3`（普通密码）——而 `/doc/help/` 正是标准 `help`
  指令对**任何玩家**（不需要巫师权限，`doc/help.h` 的
  `DEFAULT_SEARCH_PATHS` 里没有 `wizardp()` 限制）开放搜索的路径之
  一。也就是说任何一个连线的普通玩家，只要打 `help neima2` 或
  `help neima3`，就能看到从建站至今每一个注册账号的管理密码和普通
  密码明文——文件里已经有的 `kjh`/`commando` 两个账号的记录证实这个
  漏洞从游戏实际运营期间就一直存在，不是转档带来的问题。已删除这两
  处 `write_file()` 调用（登录/鉴权逻辑本身完全不依赖这次明文写入，
  真正生效的哈希存储在两行之前已经完成）；历史遗留的
  `kjh`/`commando` 记录按项目"保留历史存档"的惯例原样保留未动，只
  撤销了本次测试过程中自己账号追加的记录。
- **一个从未被记录过的新 bug（已写入 AGENTS.md §7.85）**：`score`
  指令的食物/饮水/精/气进度条无论真实数值如何，几乎总是显示"满格"
  ——这掩盖了上面 §8.9 的真实影响（食物明明是空的，进度条却显示满
  格）。根源是 `cmds/usr/score.lpc` 的 `tribar_graph()` 里一个转档前
  GBK 双字节时代遗留的 `*2` 宽度换算：`bar_string` 现在是 16 个字符
  （UTF-8 逐字符索引），但换算公式仍按 32 个存储单位计算切片范围，
  导致数值为 0 时切片变成 `bar_string[0..-1]`（被驱动的负数下标规则
  解释成"到最后一个字符"，反而返回整条满格字符串），数值超过约一半
  时切片终点也早就超出真实字符串长度、被静默截断成满格——所以这条进
  度条实际上只在 50% 以下才有意义，51% 和 100% 看起来一模一样。已用
  相同的三段式（实心/半透明/空白）视觉效果重写为按字符数索引，用临
  时埋点验证过 0%/25%/50%/100% 四个采样点渲染正确，随后在真实战斗中
  确认气血掉到一半时进度条确实显示了正确的半格。这份档案另外还有 3
  份各自独立实现的 `tribar_graph()`（`score1.lpc`/`score2.lpc`/
  `i2.lpc`，巫师版 score 和 i 指令用），`score1.lpc` 至少有同类"宽度
  不匹配"的迹象（自己的 `bar_string` 17 字符 vs 配套的 `blk_string`
  34 字符），但这次没有逐一审计/修复，留给后续。
- **战斗/移动测试**：注册后随机落地在铁枪庙（泉州），与"乌鸦"NPC 交
  手一场回合制战斗并获胜（击杀记录 +1），期间食物/饮水/气血条随伤害
  正确地按比例下降（证实上面两个 bug 修复后确实协同工作）；`west`
  移动到嘉兴南门确认地图连通性正常。`quit` 指令正常退出，但因为这次
  测试账号登录不到 30 分钟，触发了这份档案自己的"节省资源不存档"规
  则（真实、有意的设计，不是 bug），所以没有进一步测试重新登录/存档
  恢复路径。
- **本次深挖没有触碰死亡/复活流程**：按 AGENTS.md §7.68（现已收窄到
  仅 `bmxkx2001` 适用）的纪律，没有对本档案的死亡/复活相关文件做任
  何 §7.68 类判断的改动（这次测试也没有实际让角色死亡，未涉及）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`§7.86` 留言板 `post` 崩溃，本档案此前实际从未修复**：AGENTS.md §7.86 的记录曾把本档案列为"天涯"家族已确认命中并修复的三个成员之一（连同 `xhcii`/`zxty`），但本次跨库扫描核实后发现这个说法不准确——`git log`/`NOTES.md` 里都找不到任何针对本档案的 §7.86 提交或记录，全档案 100 处 `BULLETIN_BOARD` 仍是原始的 `inherit` + 多余 `replace_program()` 致命形状，`post` 命令在修复前实际上一直是崩溃的。已在本次扫描中删除全部 100 处多余的 `replace_program(...)` 调用（保留 `inherit`），编译检查通过（驱动干净启动、监听端口正常）。未做完整 §10.7 深度游玩测试，之前记录的"已修复"结论应视为误传，以本条为准。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，CRLF 行尾档案）完全没有严
   重度检查（AGENTS.md §7.34-class，本轮反复确认的形状）**：
   `if (this_player(1)) efun::write(...)`——不区分巫师/玩家，也不区
   分警告/错误。修复：加上 `strsrch(message, "arning:") == -1` 判
   断（用 Python 字节级正则替换保留 CRLF 行尾——第一次尝试直接用
   贪婪正则捕获整行字符串字面量时越界匹配到了跨越
   `+ message + "\n"` 的部分，产生了重复代码，已发现并撤销重做，
   改用精确匹配已知字面量的方式）。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例）**：`adm/daemons/
   logind.lpc` 的 `get_gender()`（新角色注册流程的最后一步）紧跟
   着调用 `log_file("login/newid.log", ...)`——和 `ffxymud`/`hc`/
   `jhfy`/`jhfy2` 完全同一形状。已补上
   `assure_file(LOG_DIR + file);`。**第一次尝试时漏加了前向声明**
   （`assure_file()` 定义在同文件后面），导致 `/adm/obj/
   simul_efun` 编译失败、整个驱动无法启动（"Undefined function
   assure_file"）——立即发现（下一步就是启动驱动）并补上前向声明
   重新编译，驱动恢复正常启动。

### 发现并修复的重大 PROGRAMMING bug：新注册的管理员账号永远无法真
   正登录（密码从未被持久化）

3. **`feature/dbase.lpc` 的 `set()` 对 `password`/`ad_password` 属
   性有一条防劫持保护，但错误地把"这个 id 已经在 wizlist 里被列为
   (admin)"当成了"这个账号已经有一个受保护的旧密码"，导致这个 id
   **第一次注册、设置自己密码的那一刻**就已经被自己的保护机制拦
   截**（新发现的 bug 类别）**：
   ```
   if ((prop == "password" || prop == "ad_password") &&
       wizhood(this_object()->query("id")) == "(admin)" &&
       this_player() && geteuid(this_player()) != this_object()->query("id"))
     return;
   ```
   `wizhood()` 只读取 `/adm/etc/wizlist` 这个纯文本文件，和这个 id
   是否已经有一个真实存在的角色/密码完全无关。本项目标准做法是提
   前把 `fluffos (admin)` 写进 `wizlist`，再让 `fluffos` 走正常注
   册流程——但正是这个标准做法，让 `fluffos` 在**它自己第一次设置
   密码的那一刻**，就已经满足 `wizhood(id)=="(admin)"` 这个条件；
   同时因为此刻这个连线对象自己的 euid 还没被 `seteuid(id)` 提权
   （提权发生在后面的 `make_body()`），第二个条件
   `geteuid(this_player()) != id` 也成立——两个条件同时满足，
   `set("password", ...)` 直接 `return`，**从未真正写入
   `dbase["password"]`**。现场复现确认：修复前完整走完注册流程、
   `score` 也正常显示"(admin)"权限，但存档文件 `data/login/f/
   fluffos.o` 里 `dbase` 映射根本没有 `"password"`/`"ad_password"`
   这两个键；第二次用刚设置的密码重新连线，被要求输入密码时三次
   都被拒绝，账号被踢下线。这不是这份档案独有的偶发问题，而是
   `set()` 权限检查本身的逻辑缺陷：它把"保护一个已存在的密码不被
   覆盖"错误地实现成了"任何 wizlist 里已登记为 admin 的 id，永远
   不能通过正常流程设置自己的密码"——任何库如果也用了同一段
   `feature/dbase.lpc`（或类似逻辑），都会在"提前播种 wizlist、再
   走正常注册"这个本项目的标准 §1.5 流程下必然复现这个 bug。
   修复：只在 `dbase[prop]` 已经存在（真的有一个旧密码需要保护）
   时才触发这条保护，不影响原本"禁止非本人覆盖他人已有密码"的安
   全意图：
   ```
   if ((prop == "password" || prop == "ad_password") &&
       wizhood(this_object()->query("id")) == "(admin)" &&
       this_player() && geteuid(this_player()) != this_object()->query("id") &&
       mapp(dbase) && dbase[prop])
     return;
   ```
   已现场复现验证：修复后重新走一次完整注册流程，`data/login/f/
   fluffos.o` 的 `dbase` 映射里 `"password"`/`"ad_password"` 两个
   键都有正确的 crypt 哈希值；用刚设置的普通密码重新连线，
   "重新连线完毕"确认真正登录成功（此前会被三振出局踢下线）。

### Proactive checks（无需改动）

- `win_times` 修复本档案未搜到对应的 refereew.lpc 场景 NPC（此项
  目 §10.7 检查清单并非每份档案都适用，如实记录未命中）。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 发现但未修复：`update` 指令报"没有这个档案"

修复验证阶段尝试用 `update /adm/simul_efun/file`/`/adm/daemons/
logind`/`/adm/obj/master` 都报"没有这个档案。"，但这些文件在磁盘上
确实存在（`file_size()` 检查失败的原因未查明——不是本轮改动引入的
回归，`update.lpc` 的 `resolve_path()`/`SECURITY_D->valid_write()`
链路较复杂，值得未来单独排查，但不影响本轮已经验证过的核心结论：
密码持久化 bug 已用真实的"设置密码→重新连线"往返验证过，属于比
`update` 权限检查更直接、更关键的验证）。

### 发现但未修复：两条 debug.log 记录，均判定为已知的非 bug 类别

- `*Too long evaluation. Execution aborted.`（`log_error()` 那行，
  三次）：全新驱动进程下首次触发 `get_gender()`→`enter_world()` 冷
  编译级联，AGENTS.md §7.90/§10.8 已归档的冷启动 eval-cost 耗尽类
  别，第二次登录（重新连线）未再出现，确认已自愈，非持久性 bug。

### 2026-08-13 更正并修复：emote 存档损坏，之前误判为"仅噪音"

上一轮记录把 `*restore_object(): Illegal mapping format while
restoring emote.`（`/adm/daemons/emoted` 开机 preload 阶段）当成和
`jqxz2008` 的 `e2c_dict.o` 一样的"数据损坏但已被 `catch()` 安全吞掉、
不影响运行"，未展开修复。本轮重新深挖，结论有一半不成立：损坏本
身确认属实（`data/emoted.o` 291724 字节，`[`/`]`/`(`/`)` 括号计数
不平衡：`[` 455 次 vs `]` 454 次，`(` 461 次 vs `)` 462 次，是真实
的存档级结构损坏，不是格式化工具误判），`master.lpc` 的
`preload()` 确实用 `catch(call_other(file, "??"))` 拦住了这个错误
让开机不中断——但错误往上抛穿了 `emoted.c` 的 `create()`：

```
void create() {
  if (!restore() && !mapp(emote))
    emote = ([]);
}
```

`restore()` 内部的 `restore_object()` 抛出的是一个**可以被 catch()
拦截、但不是"返回 0"的错误**，会中断 `create()` 的执行，导致
`emote = ([])` 这个兜底赋值根本没机会跑到——`emote` 全局变量最终
停留在**从未初始化的 `int 0`**，不是一个空 mapping。用临时
`write_file()` 埋点在真实驱动里验证过：`preload()` 里
`catch(call_other(file, "??"))` 捕获到的 `err` 正是这行错误文本；
紧接着调用 `EMOTE_D->query_all_emote()`（内部是 `keys(emote)`）会
再抛出 `*Bad argument 1 to keys(): Expected mapping Got: 0`——而
`cmds/imm/edemote.lpc`/`cmds/adm/udemote.lpc`（巫师/管理员编辑预
设动作表的指令）第一步就调用 `EMOTE_D->query_all_emote()`，也就是
说这两个巫师指令在修复前会**直接崩溃**，不只是开机日志噪音。

修复：`git rm work/data/emoted.o`。删除后 `restore()` 正常返回 0
（文件不存在），`emote = ([])` 按设计兜底执行，`query_all_emote()`/
`query_emote()` 恢复正常（返回空表而不是报错）。`do_emote()`（`emote
<动作词>` 里带参数匹配预设动作模式的那条路径）修复前后行为其实一致
——它自己用 `!mapp(emote) || ...` 短路判断，`mapp(0)` 返回假不会报
错，所以预设动作在修复前后都是"匹配不到"（数据本来就已经不可用），
不构成回归，只是 `edemote`/`udemote` 的硬崩溃被消除了。

验证：新驱动进程干净启动 5 次，`boot_verify.log`/`debug.log` 均不再
出现 `Illegal mapping` 或任何 `emote` 相关报错；用临时埋点直接调用
`EMOTE_D->query_all_emote()` 确认不再抛错、返回空 array。完整走了
两次全新注册流程（英文 id→中文名→双密码→天赋→email→性别→进入游戏
世界），均正常到达 `(player)` 权限、正常显示房间描述，没有任何
emote 相关报错。另外用已提交的管理员 `fluffos` 账号（`data/login`/
`data/user` 下的存档早于本次改动，来自更早的会话）做了一次真实的
"全新连线→用已存普通密码登录→look 看到正确房间描述"的重连验证。

**顺带发现但明确排除在本次修复范围之外、留给未来处理的两个不相关
pre-existing bug**（用同一个 `fluffos` 账号反复重连测试时命中，用
"先还原 `emoted.o`、同样步骤复现" 的对照实验确认这两个和本次的
emote 修复无关，删除/不删除损坏档案都一样会触发）：
1. `Too deep recursion. program: /adm/daemons/securityd.lpc:263`——
   在管理密码登录改密码、以及"踢掉重复连线"两条路径上都能稳定复
   现,不是一次性冷启动效应（同一新号连续两次注册都命中同一行）。
2. `cmds/usr/quit.lpc` 第 38 行 `environment(me)->query("fight_room")`
   在 `environment(me)` 为 0 时 `call_other()` 直接报错——命中一次，
   与前一条同一次会话里的 `fluffos` 账号状态有关，未确认是否对全
   新注册角色同样可复现。
两者均已如实记录，不属于本轮任务范围（emote 存档），未做任何改动。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`，
  密码：管理密码 `AdminPass123`，普通密码 `LoginPass456`）。
- `data/board/`、`data/{login,user}/t/testfixseven.o` 是此前会话遗
  留的未提交测试痕迹——`Aug 5` mtime，早于本次会话，未受本轮任何
  操作影响，未触碰。

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"`, same `tybxjh`/`wlhd` sibling lineage as
`include/globals.h` confirms). Deleted 2,376 live standalone
`replace_program(ROOM);` lines under `work/` via `fix_710_room.py`,
plus hand-fixed the room-building tool's string-builder template
(`work/clone/misc/roommaker.lpc`). `work/data/` only had 2 real
`.lpc` files, neither with the bug pattern — no false negative.
Remaining matches after the fix are all pre-existing `//`-commented.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`LoginPass456`) into the game world, `look`/`score`/`quit`
all worked cleanly. Same sibling-lineage quirk as `wlhd`: `quit`
deleted `data/login/f/fluffos.o` (credential file) even though it had
just been used to log in successfully — reverted via
`git checkout HEAD -- work/data` before committing, unrelated to this
fix and out of scope.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
