
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

## 深度功能测试（2026-09-03，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师，并核对存盘后门派是否还在。
2026-08-13 那一轮没测这两步。

### 实测过程

管理员 `fluffos` / 普通密码 `LoginPass456`（2026-08-13 注册时设的，
本次未走管理密码）。落地 `/d/city/wumiao`。`goto /d/city/zuixianlou`，
`list` 价目为铜钱尺度（烤鸡腿八十文钱）。`clone /clone/money/gold`
后 `buy jitui` 成功（找零九十九两银子 + 二十个铜板）。`F_DEALER`
没有丐帮「穷叫化」拒绝。没有 `join 名门正派` 门。

`goto /d/gaibang/inhole`，`apprentice zuo`：左全收徒，`score` 称谓
「丐帮第二十代弟子」、师傅左全。显式 `save` 成功，`user.o` 立刻带上
`family`。断线重连 `score` 仍是丐帮第二十代弟子 / 师傅左全，银子还在。
没有 `wzd_log` 验证码。

`quit.lpc` 对 `mud_age < 1800` 会删档（真正 `rm` 没有 `wizardp()`）。
既有政策，未改，本轮不 `quit`。

### 发现并修复的 PROGRAMMING bug

1. **`cmds/usr/save.lpc` 把真正的 `link_ob->save()` / `me->save()`
   注释掉了，只打印「档案储存完毕」。** 和 yxjh/zxty 同一形状。已
   恢复成真正调用两个 `save()`。

2. **`securityd.lpc` `valid_read()` 里对 `/log/` 的拒绝会
   `log_file("file/bug_read")` 再入。** 非 `zjb`/`daniel` 的巫师
   （包括 `fluffos`）登陆会 Too deep recursion。加了
   `in_valid_read` 重入保护。修复后登陆两行警告，`clone` 一行警告
   加黄金复制成功，本 boot 零 recursion。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 8 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/fyue/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`u/fyue/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 1 个，工作树三次分别通过 1、1、1 个（共 3 个），无回退；`adm/daemons/cron.lpc`、`u/fyue/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py tybxjh --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);` 等），共改动 655 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：596 -> 596 通过，无回退；改过的头文件的 36 个包含者 36 -> 36 通过。`d/feitian/npc/xunbu.lpc` 的 `(: random_move() :);` 只造函数指针不调用，属内容设计，未动。

启动时警告 43 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/app/ls2.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 10 处，返回类型/原型 22 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 33 个文件，HEAD 与工作树各载入一次无回退（33 objects; HEAD PASS 33, tree PASS 33; regress 0; newly loading 0），这些文件的警告 33 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/*/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造了一个函数指针就丢掉，巡捕从不走动；改为 `random_move();`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-12：`u/daniel/obj/xiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 5 处多余继承，其余手工，能编译的文件警告清零；改动的 10 个对象在 HEAD 与工作树各载入一次：HEAD PASS 7，tree PASS 7，regress 0。

- `d/daniel/job/peng/peng.lpc` 原型写 `string ask_fail();`，包含进来的 `dojob.lpc` 定义的是 `int ask_fail()`，原型改 `int`。
- `kungfu/skill/guxing-sword/xingchen.lpc`、`quest/chousha/killer.lpc` 写明用驱动原先选的 `clean_up()`；`u/fyue/ansi2.h` 对已由 `ansi.h` 定义的 `ESC`、`BEEP` 先 `#undef` 再定义；`kungfu/skill/huashan-jian.lpc` 多余的 `;` 删去。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 1 处 `int power_point()` 返回 1.3、1.5 之类的浮点，经 int 返回被截断；本库没有调用者，改成 `float` 返回值，保留原数值（KB 04 §6.10）。
- 2026-10-14（续）：`data/area/好吃党.o` 末尾多一个零字节，转码解析失败；去掉末尾的零字节后按 GB18030 转为 UTF-8（`scripts/lpc_save_encoding.py`）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。24 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-dafa`、`quanzhen-jian`、`wugong-zhao`。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`zidian-jianfa`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest2/jinyong`、`/quest2/jinyong/jinyong`、`/quest2/quest2/jinyong` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`tiangang-zhengqi`、`wangran-xinfa`、`xiantian-gong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`palm-sword`→`plam-sword`（`hand-blade`、`plam-sword`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yunv-xinjing`→`yunu-xinjing`（`wangran-xinfa`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）。

## 帮派地盘档截断（2026-10-15，KB 03 §4.4）

`data/area/天安门妓院.o` 原档停在 `"banghui":"$HIY$【中华大帝国】",`，少了结尾的 `])`，地盘对象读档报错。补上。（这个档的内容其实是天安门钱庄的数据，原档如此，未动；同目录的 `钱庄.o` 是截断的废档，没有地盘用它。）

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/city/obj/bingqipu.o`、`data/area/天安门钱庄.o`、`data/area/成都广场.o`、`data/area/扬州铁匠铺.o`、`data/npc/+瘭+.o`、`data/npc/xianlaoban.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 死神刀「死神锁」命中时报错（2026-10-15，KB 06 §7.246）

命中时要把对方的兵器震飞，用的 `weapon2` 却从未赋值：每次命中都在扣完内力后报错。改为当场取对方的兵器；对方空手就只有“人也彻底崩溃了”那半句。


## 弹指神通「漫天花雨」每次报错（2026-10-15，KB 06 §7.246）

绝招声明了 `object weapon;` 却从不赋值，接着就 `weapon->query_amount()` 数暗器：每次使用都报错。补上取兵器的判断，手里没有暗器时拒绝（“你手中没有暗器”）。


## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

7 个文件、11 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/jyquest/sword`、`/jyquest/armor`、`/obj/cloth/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 3 个，改后 6 个（3 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了。改后用 `lpcc` 逐个载入这些对象：2 个通过。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（4 个名字，最多的是 `hunyuan-force`、`ruyi-blade`、`taxue-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 2 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/stick`（宏 `STICK`）←zxty08nxgbb，3 个对象继承它，抽样 1/3 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 19 处、16 个文件：`yan-fly`→`yanfly`（3 处）、`yijin-jing`→`yijinjing`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）、`poyu-qua`→`poyu-quan`（1 处）等共 10 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 18 处、18 个文件：`::create()`（17 处）、`::do_discard()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/feitian/npc/wolf`。（`scripts/lpc_transplant_function.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 1 个 NPC 文件、1 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`、`/d/npc/m_weapon/weapon/m_sword2.lpc`、`/d/npc/m_weapon/weapon/sword.lpc`（共 4 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`（共 3 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/zjb/paimai.lpc`：拍卖房的 `add("pnum",1)`（竞买者计数）被 `//归还前一个竞买者的钱` 注释吞掉，计数从不增加

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `clone/unique/fan.lpc`：同时继承 `STICK` 和 `SKILL`，两条路径都带来 `/feature/clean_up.lpc` 的 `clean_up()`（`clean_up() inherited from both …`），驱动用了后继承的 SKILL 那条；写出 `int clean_up() { return skill::clean_up(); }`，行为不变（`scripts/lpc_name_winner.py`）。

逐个与 HEAD 对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 4 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）、`/d/quanzhen/hudi6.lpc`（bixiecanyang）、`/kungfu/skill/guxing-sword.lpc`（xyzx3）、`/quest/murong/qlist3.lpc`（bixiecanyang）。修后与 HEAD 逐个对比载入：这 4 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`xpasswd` 保护 boss 账号口令的那一半条件从不成立；客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/cmds/bos/log.lpc`（1 处）、`/cmds/bos/xpasswd.lpc`（1 处）、`/d/changan/ca2.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 14 处）。改动：`/d/zjb/liandan.lpc`（14 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/wiz/mcheck2.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `closed` 守护的心跳每秒调一次不存在的 `versiond`（2026-10-20，KB 01 §1.3(c)）

`closed.lpc` 的 `heart_beat()` 以 `if (! VERSION_D->is_version_ok()) return;` 开头，本库没有 `/adm/daemons/versiond`：有人在闭关时，控制台每秒一条 `call_other() couldn't find object '/adm/daemons/versiond'`，闭关的后续处理（`load_all_users()`）也永远走不到。改成 `if (find_object(VERSION_D) && !VERSION_D->is_version_ok())`（KB 01 的写法：没有版本守护就当版本正常）。加载检查 OK。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 1 个 NPC 文件写成 `set("chat_msg", ({ }))`（或 `chat_msg_combat`）并带正的 `chat_chance`（例如 `/d/xixia/npc/mazei.lpc`），每次心跳有 `chat_chance`% 的概率 `random(0)` 为 0、`msg[0]` 报 `Array index out of bounds`（驱动捕获，心跳继续，但每次一条运行时错误），这个 NPC 在内存里就一直发生。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。
