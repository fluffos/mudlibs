
## 深度功能测试（第二轮，2026-08-03）

之前只做过注册流程 + 管理员权限的浅层验证，本轮做了完整的 §10.7
深度功能测试。proactive 检查了 AGENTS.md 已归档的四类常见坏味道，
命中了两类：`logind.lpc` 里的 printf("%O") 调试残留（两处），以及
§8.9 那个坏 age 判断（一处）。

**发现并修复的三个真实 bug：**

1. **`logind.lpc` 里有两处 `printf("%O\n", ob)` 调试残留**，分布在
   两条并行的取名流程上——接受系统随机生成的中文名（`get_resp()`）
   和自己手动输入中文名（`get_name()`）——都紧挨在"请输入你的管理
   密码："提示之前，把登录连线物件的内部路径直接打在屏幕上。和
   `hc` 那次发现的形状完全一样（同一行调试代码被复制到两条并行流
   程里），新增 `yxjh` 到 AGENTS.md §7.34 确认实例列表。两处都已
   删除。
2. **§8.9 同款 bug，但是更精简的写法**：`logind.lpc` 里
   `user->setup()` 之后有一段 `if (ob->query("age") == 14) {
   user->set("food", ...); user->set("water", ...); }`——没有
   `cctx`/`niaoren` 那两个实例里额外的 `!user->query("food")`
   前置判断，就是单纯一行 `ob->query("age")`。`ob` 是登录连线物
   件，全库没有任何地方给它设过 age；真正的 age 是
   `inherit/char/char.lpc`/`clone/user/user.lpc` 的 `update_age()`
   写到 `user`（玩家身体）身上的，新角色是
   `14 + age_modify + mud_age/86400`，创建瞬间正好等于 14。条件永
   远为假，食物/饮水满血初始化从未真正生效过。**和 `cctx`/
   `niaoren` 是完全不同的血统**（`yxjh` 属于"天涯"家族，和
   `cctx`/`niaoren` 的驰骋天下家族没有已知关系）——独立犯了同一个
   错误，不是抄来的。已改成 `user->query("age")`，新增 `yxjh` 到
   AGENTS.md §8.9 第三个确认实例。用两个全新角色对照验证：修复前
   `score` 面板食物/饮水槽全空，修复后（`沐剑鸣`/id `yxdive`）两条
   槽都是满的 16 格（■■■■■■■■■■■■■■■■）。
3. **（记录但未修复）`adm/daemons/boss.lpc` 的 `check_time()` →
   `clone_boss()` 在开机 preload 阶段第一次触发时，会连锁编译大量
   房间和 NPC（东厂大门 dongchangdamen 及其驻守的兵 bing 等），累
   计 eval cost 超过驱动的 700000 微秒单次调用上限**，先后抛出两条
   `执行时段错误`（`*Too long evaluation. Execution aborted.` 和更
   严重的 `*Can't catch eval cost too big error.`，后者说明溢出发
   生在已经处于一层 `catch()` 内部的时候，连 `preload()` 自己的
   `CATCH()` 都来不及接住）。`check_time()` 每 60 秒自我重新调度一
   次，但内部真正调用 `clone_boss()` 的判断条件是
   `!time || time <= time()`（`time` 首次未设置，所以开机瞬间必然
   触发一次；之后每 30 分钟 `time = time()+1800` 才会再触发一
   次）——只在"冷编译"（这批房间/NPC还从未被编译进内存过）时才会这
   么昂贵，本次会话观察到的唯一一次触发正是开机瞬间。这次错误没有
   阻止开机完成，之后的注册/登录/`score`/战斗全部正常，暂时判断为
   一次性的开机代价而非持续性阻断问题——但因为 `clone_boss()` 理论
   上每 30 分钟还会再跑一次，不能完全排除长时间在线时再次触发的可
   能性，值得未来一次长时间 soak test（参考 AGENTS.md §10.8）时留
   意，暂不改动代码（没有找到能确定安全的修复方式，比如提高
   eval_cost 限制需要改驱动配置，超出本次单 lib 会话范围）。

**完整流程验证**：连续注册两个全新中文名角色（沐剑鸣/id
`yxdive`、及后续测试角色），从英文 ID→确认新建→中文名→管理密码
+登陆密码双密码制→天赋菜单（`0`随机→`y`接受）→电子邮件→性别，进
入起始房间"铁枪庙"（一处武侠味十足的乡野古庙场景，驻有四只乌鸦
NPC）；`score` 面板（含攻击力/躲闪/防御/招架等详细战斗数值、食
物/饮水槽、江湖威望等）渲染正确；向乌鸦发起战斗，完整交手十余回
合，双方攻击叙述、伤害数值、招架/闪避判定均正常（乌鸦血厚，多次
"非常可怕的严重劈伤"仍未见明显掉血迹象，判断为数值设计而非 bug）；
debug.log 全程除开机那次已记录的 eval-cost 问题外无新增报错。

**未覆盖范围**：拜师、经济系统（挖矿/合成兵器）、帮会加入等玩法因
时间原因未实测，`doc/newbie/xinshou3` 里描述的高度依赖 timer/宏机
器人的资深玩家流程也未尝试复现——只走了组织化程度较低的自然探索
路径。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。第一轮已修复的 §7.34 printf 泄漏/§8.9 均
逐项核对代码仍然生效；`win_times` 的 `%`-operator 也已用
`to_int(query("win_times")) % 5`（`d/city2/npc/refereew.lpc:146`）；
`feature/dbase.lpc`（真正生效的 F_DBASE，`u/rock/dbase.lpc` 是巫师
沙盒死代码副本，不适用）未发现密码写保护，不适用 tybxjh/wlhd 那一
类 bug。

### 本轮新发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master file）
   完全没有严重度检查（AGENTS.md §7.34-class）**：这份档案的写法比
   较特殊——`this_player(1)` 和 `this_player()` 两个分支都无条件回
   显——已把两个分支一起包进 `strsrch(message, "arning:") == -1`
   判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **`confirm_relogin()`（`adm/daemons/logind.lpc`）"踢掉重复连线"
   分支在 `old_link` 为空时的兜底路径参数传错、且没有重新提示，导
   致后续任意输入被静默当成新英文 id 处理（新发现，本轮实测复现）**：
   `old_link = user->query_temp("link_ob")` 为 0 时（旧连线的
   link_ob 已经不存在，但角色对象本身还残留"看起来仍在连线"的状
   态——真实触发场景：短时间内两次断线重连，第一次连线的 socket 已
   经关闭但驱动侧的清理还没跟上），代码走进 `else` 分支：
   `input_to("get_id", ob, user)`——`get_id()` 的真实签名是
   `(string arg, object ob, int ip_cnt)`，这里把一个（刚被
   destruct 的）物件传进本该是 `int` 的第三个参数位置，而且**没有
   先 `write()` 任何提示**就注册了下一次输入的回调。玩家看到的现
   象：屏幕上什么提示都没有，下一条自己随便发的指令（比如
   `look`）被 `get_id()` 当成新英文 id 处理，弹出"使用 look 这个
   名字将会创造一个新的人物，您确定吗"——完全静默的指令流错位，除
   非玩家仔细看提示文字否则很容易误以为是网络问题。live 复现：连
   续两次快速重连触发了这个分支，第二次的 `look`/`score` 被吞成了
   假注册流程。修复：加回缺失的提示 `write("请输入您的英文名字：
   \n");`，并把第三个参数改成合法的 `int`（`0`，和其它正常调用点
   一致的默认值）。同一个签名不匹配的写法在 `get_wizpwd()`（巫师
   密码重试失败分支）里也独立出现了一次（`input_to("get_id",
   user)`，直接漏掉第三个参数，此处 `user` 参数实际语义是连线物
   件），一并修复（补上提示 + `0` 参数）。重启驱动后用连续两次真实
   重连复测：第二次不再触发假注册流程，`look`/`score` 正常执行，
   `debug.log` 里不再出现"中间登陆出错"配对的错位指令。

### Proactive checks（无需改动）

- **一次性冷启动 eval-cost 耗尽（AGENTS.md §7.90/§10.8-class），本
  轮确认自愈，未修改**：注册流程（`get_gender()`→`enter_world()`
  首次编译 `adm/daemons/race/human.lpc` 等）和第一次 `look`
  广场触发的邻近 NPC `feature/dbase.lpc::query()`（内部
  `evaluate()` 求值一个未编译过的表达式）各触发了一次
  `Eval interrupted`/`Too long evaluation`——均发生在
  `Accepting telnet connections` **之后**，是活跃会话期间真实可达
  的冷编译突发，不只是开机 preload 噪音。用第二次全新连线复测同一
  账号、同样访问广场：`debug.log` 里这些错误没有再出现，确认是一
  次性冷编译代价，不是持续性阻断问题，维持第一轮记录的判断（不修
  改 `maximum evaluation cost`，NOTES.md 已有类似 `boss.lpc` 冷编
  译实例的先例记录）。

### 实测过程

管理员 `fluffos`/`Mud@2026`（`adm/etc/wizlist` 早已播种，但从未真
正注册过）用完整双密码注册流程（管理密码+登陆密码）创建，落地"铁
枪庙"，`score` 显示"【天界总管】"头衔，食物/饮水满格。随后**两次连
续**真实断线重连+密码验证（第二次专门用来复现并验证上面 #3 的修
复）：均成功登录，存档数据一致，第二次重连后 `look`/`score` 正常
执行（未再被吞成假注册）。驱动按精确 PID 结束；测试期间产生的
NPC/拍卖背景世界模拟状态漂移（`data/npc/*.o`、`data/paimai.o`、
`u/rock/log.txt`）已 `git checkout --` 还原；管理员存档
（`data/{login,user}/f/fluffos.o`）已提交；`data/{login,user}/y/
yxdive.o` 是 2026-08-03 上一轮深挖遗留的测试角色，与本轮无关，未
触碰。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

浴血江湖3梦回江湖。WASM 修复找到并修好了 5 个真正的 bug：（1）压缩包里缺少不带后缀的 adm/etc/preload 档案（只有 preload.bak 和一份稍短的 preloadbb 变体）——已从 preload.bak（两者中更完整的一份）恢复，而这份档案还带有 CRLF 换行符，update_file() 的 explode(str,"\n") 不会剥除它们，导致每一个预加载精灵的路径都被静默地变成了例如 '/adm/daemons/securityd\r.lpc'，file_size() 检查失败——已转换成 LF 让预加载真正生效（之前实际上零个精灵被预加载；logind.lpc 之所以之前还能凑合工作，纯属侥幸，是因为它直接继承自 clone/user/login.lpc）。（2）唯一真正生效的 adm/daemons/logind.lpc 里标准的 §8.1 GBK 字节区间 check_legal_name()（i%2==0 奇偶门槛、name[i..<0] 后缀切片、字节数翻倍的 2/10 界限），已修复成逐码点的 name[i..i] 和 1/5 界限；is_chinese() 本身已经正确。保留了三份死代码备用副本未做改动（clone/user/logind.lpc 和真正的 clone/user/login.lpc 以及 login_back.lpc/loginbak.lpc 放在一起；u/rock/ 是某个巫师的个人全量 mudlib 备份目录，自带一整套 logind.lpc/master.lpc/user.lpc 等）——已通过 config.fluffos 里的 master file/simulated efun file 路径确认，LOGIN_D 和 master 档案配置都没有指向这两处任何一处。（3）master.lpc 的 valid_read()/valid_write()（真正生效的 adm/obj/master.lpc，不是 u/rock/obj/master.lpc 那份死代码副本）缺少标准的 'user == this_object()' 短路判断——两处都已加上。（4）d/jerry/saveme.lpc 的 create() 呼叫了 exert_function(10)——exert_function(string func)（定义在 inherit/char/npc.lpc 里）需要的是一个技能名字符串，不是整数，导致这个 NPC 完全编译不过（'*No program in object'），每次启动都会破坏一整块城市房间的居民；这次呼叫的原始意图已经无法还原（是死代码，不像本次会话其它档案的修复那样是打错的算术），所以直接删掉了，做法和 yhyxcs 更早那次原生启动过程里删掉一个无法还原的强制重新加载技巧、而不是猜测修复方式一致。（5）data/ 下 130 个 .o 存档档案里有 118 个是 CRLF 换行，驱动的 restore_object() 在处理嵌套映射结构时可能会因此卡住——已全部统一转换成 LF；这修复了大部分但不是全部的 restore 问题（见下）。碰 socket 的 adm/daemons/httpd.lpc 和 adm/daemons/network/dns_master.lpc 都不在（现在已经恢复的）预加载列表里，也没有真正的外部呼叫者——保持原样，不需要 §7.52 掏空处理。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这份档案的阶层一直到 (admin) 之上的 (ceo)——为了和本次会话的惯例保持一致，用的是标准的 (admin) 阶层）。注册流程在格式化前后都完整验证过（英文 id→y 确认→中文名字→管理员密码+确认→登录密码+确认→天赋菜单（'0' 随机→'y' 接受）→电子邮件→性别→进入中央广场），管理员权限已通过'◇ 您目前权限：(admin)'确认。已知未修复的问题：即使做了 CRLF 修复，adm/daemons/named.lpc 的 restore_object() 每次启动依然会抛出'Illegal mapping format while restoring dbase'——存档档案里的映射字面量语法上是配平的（已核对括号匹配），所以原因出在这个驱动更严格的 restore_object() 解析器里的其它地方，没有进一步深挖；这个失败已被捕获（preload() 的 catch()），只会降级 named.lpc 的近似名字冲突去重检查功能，不会阻挡注册、进入游戏世界、或任何其它已观察到的功能——按 AGENTS.md §7.15 的精神记录在案，不算阻断性问题。LPC 格式化工具对全部 13038 个档案运行（写入 11874 个，1119 个针对本次会话里最杂乱代码库的转档之前就存在的未结束字符串/文本块错误未做格式化，45 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。格式化后用同样的完整注册+管理员登录流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 102 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 `work/` 下 2,606 处存活的 standalone `replace_program(ROOM);` 行
  （脚本删除），另外手工修复 `clone/misc/roommaker.lpc` 建房工具代码
  生成模板里的同形状变体，共 2,607 处，与普查记录一致。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行。开机产生的存档时间戳噪声
  （`data/npc/qianyankai.o`、`u/rock/log.txt`）已用 `git checkout` 撤销。

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
2026-08-13 那一轮明确没测这两步。

### 实测过程

管理员 `fluffos` / 普通密码 `Mud@2026`（双密码账号，本次未走管理
密码）。落地 `/d/city2/kedian`。`goto /d/city/zuixianlou`，`list`
价目为铜钱尺度（烤鸡腿八十文钱）。`clone /clone/money/gold` 后
`buy jitui` 成功（找零九十九两银子 + 二十个铜板）。本血统
`feature/dealer.lpc` 没有丐帮「穷叫化」拒绝，买可以放在拜师前或后。

拜师比 zxty08 多一道阵营门：`apprentice zuo` 先被挡，提示「丐帮」
属于名门正派，须先 `join 名门正派`（`cmds/skill/join.lpc`）。宣誓
后再拜，左全收徒，`score` 称谓「丐帮第二十代弟子」、师傅左全。
`logind.lpc` 每次巫师登陆会把 `env/invisibility` 设成 1；`present()`
看不到隐身玩家。正确指令是 `unset invisibility`（没有
`unsetenv`）。这是内容/巫师惯例，未改。

`quit.lpc` 对 `mud_age <= 600` 会 `rm` login.o **和** user.o，真正
删除路径没有 `wizardp()`（确认提示才豁免巫师）。和 zxty08 同一类
既有政策，未改，本轮不 `quit`。

重连 `score` 仍是丐帮第二十代弟子 / 师傅左全；`user.o` 里有
`family` / `zhenying`。

### 发现并修复的 PROGRAMMING bug

1. **`cmds/usr/save.lpc` 把真正的 `link_ob->save()` / `me->save()`
   注释掉了，只打印「档案储存完毕」。** `net_dead()` 只存 login.o
   不存身体；`quit` 在低 `mud_age` 还会删档。结果是玩家（和巫师）
   的 `save` 完全是假的，拜师/购物都不会进 `user.o`，只靠
   `inherit/char/char.lpc` 心跳大约 15 分钟一次的自动存盘。已恢复
   成真正调用两个 `save()`，失败则报「储存失败」。修复后同一次
   `save` 立刻把 `family` 写进 `data/user/f/fluffos.o`。

2. **`securityd.lpc` `valid_read()` 里对 `/log/` 的拒绝会
   `log_file("file/bug_read")`，而 `log_file` 自己又要
   `valid_read(/log/...)`。** 非 `rock`/`jerry` 的巫师（包括
   `fluffos` admin）登陆写 usage 日志、以及 `clone` 碰到 `/log/`
   时，都会 Too deep recursion，并刷几十行「警告：你不能操作这些
   目录下的文件。」。加了 `in_valid_read` 重入保护（和
   `zxty08nxgbb` 同形状；允许读写的 id 在这里仍是 `rock`/`jerry`）。
   修复后登陆只剩两行警告，不再 recursion。

### 观察（未改）

- 冷启动 `boss.lpc` eval-cost 是 2026-08-03 已记录的一次性编译，
  未再改 `maximum evaluation cost`。
- `quit` 低 `mud_age` 删档：确认提示有巫师豁免，真正 `rm` 没有。
- 巫师隐身由 `logind` 强制打开；拜师前需要 `unset invisibility`。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 8 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 2 here-document block(s) repaired (2 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/quanzhen/manglin1.lpc`, `d/quanzhen/manglin2.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply yxjh`: 18 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 26 path reference(s) in 1 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 19 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 19 PASS, 0 that loaded before fail now, 18 more load.

18 files moved (18 `.lpc`); mostly under `u/luoyun/zhuanshi` (18). A rescan with `scripts/lpc_warnings.py yxjh` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/system_1/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`、`u/system_1/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 3、3、3 个（共 3 个），无回退；`adm/daemons/questd.lpc` 原先加载失败，现在加载成功。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py yxjh --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);` 等），共改动 1063 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：988 -> 987，少的那个 `u/jerry/quest/necropolis/obj/box2` 只删了一个没用到的局部变量，单独加载通过，是批量加载的假象；改过的头文件的 42 个包含者 39 -> 39 通过。`d/feitian/npc/xunbu.lpc` 的 `(: random_move() :);` 只造函数指针不调用，巡捕要不要走开是内容设计，未动。

启动时警告 64 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `cmds/app/ls2.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 10 处，返回类型/原型 24 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 1 个文件；改动 34 个文件，HEAD 与工作树各载入一次无回退（34 objects; HEAD PASS 34, tree PASS 34; regress 0; newly loading 0），这些文件的警告 34 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- `d/*/npc/xunbu.lpc` 巡捕：`(: random_move() :);` 只造了一个函数指针就丢掉，巡捕从不走动；改为 `random_move();`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-12：`u/jerry/obj/xiang.lpc` 写着 `int remove() { save(); }`，盖掉了 `feature/move.lpc` 的 `remove(string euid)`——这些存盘箱子/柜子被销毁时不从携带者身上减负重、不清 handing（KB 06 §7.239 变体，nitan_ceshi/tianxiawuxue 同类）。改成 `varargs void remove(string euid) { save(); ::remove(euid); }`。HEAD 与工作树各载入一次，regress 0（载不进的文件在 HEAD 就载不进）。

## 编译警告收尾（2026-10-13）

`scripts/toolkit_fix.sh` 一轮去掉 9 处多余继承；照 wlhd（51f5e219b3d）：`d/jerry/job/peng/peng.lpc` 的 `ask_fail` 原型改 `int`，`u/system_1/ansi2.h` 的 `ESC`、`BEEP` 先 `#undef`；其余手工。能编译的文件警告清零；改动的 15 个对象在 HEAD 与工作树各载入一次：HEAD PASS 12，tree PASS 12，regress 0。

- `u/rock/duihuan.lpc`（充值卡兑换）的循环写成 `for (i - 0; ...)`，本意是 `i = 0`；`i` 之前没赋过值、本来就是 0，所以碰巧能用。改成 `=`。
- 备份 `quest/guojob_bak/guo.lpc` 同时包含 `zzzjob.lpc` 和 `teamjob.lpc`，两者都声明地名表 `names`：`teamjob.lpc` 的改名 `team_names`（只它自己用）；`quest/chousha_bak/killer.lpc` 写明用驱动原先选的 `clean_up()`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 13 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件 `int power_point()`/`hard_point()` 返回浮点被截断；本库没有调用者，改成 `float`，保留原数值。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。30 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。7 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 9 个文件。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`kuihua-dafa`、`mantian-huayu`、`quanzhen-jian`、`wugong-zhao`。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`kuihuasword`、`pixie-jian`、`songshan-sword`、`yiming-sword`。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`zidian-jianfa`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bahuang-qiangfa/throw`、`bingpo-blade/ningxie`、`dagou-bang/ban`、`dagou-bang/chuo`、`dagou-bang/pi`、`dagou-bang/tiao`、`dagou-bang/yin`、`liangyi-dao/sanshen`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/quest2/jinyong`、`/quest2/jinyong/jinyong`、`/quest2/quest2/jinyong` 生成的任务怪物照抄玩家福缘（`set("kar", who->query_skill("kar"))`，怪物福缘一直为 0）。

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：`gouyee/heal`、`yuxuan-guizhen/heal` 的疗伤量写成 `query_skill("neili") / 5`，本库其余疗伤 exert 都是 `query_skill("force") / 5`，照此改为内功等级（若读内力，疗伤量会大十倍）；`lengquan-shengong` 的 `ob_hit()` 用 `query_skill("neili")` 比较双方内力，恒为 0 对 0，只会走“化去一部分”的分支，改为 `query("neili")`；落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`，`ob->query_temp("weapon")` 每次都报错，谁也学不了；还把兵器对象和字符串 "银针" 比较。照 chidi 的修法改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。本库没有银针这件兵器，这门功夫仍学不了，但不再报错，而是提示要先拿起银针。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`guiyuan-dafa`、`honghua-shengong`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`palm-sword`→`plam-sword`（`hand-blade`、`plam-sword`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yiqi-guanriyue`→`yiqiguan-riyue`（`yiqi-guanriyue/heal`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`baitao-xuangong`→`bitao-xuangong`（`bitao-xuangong`）；`huajia-daofa`→`hujia-daofa`（`hujia-daofa`）；`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`jiujin-shengong`→`jiuyin-shengong`（`jiuyin-shengong/perform/zhang`）；`tiaodao-blade`→`tiandao-blade`（`tiandao-blade`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunu-jianfa/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`d/city/obj/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 死神刀「死神锁」命中时报错（2026-10-15，KB 06 §7.246）

命中时要把对方的兵器震飞，用的 `weapon2` 却从未赋值：每次命中都在扣完内力后报错。改为当场取对方的兵器；对方空手就只有“人也彻底崩溃了”那半句。


## 弹指神通「漫天花雨」每次报错（2026-10-15，KB 06 §7.246）

绝招声明了 `object weapon;` 却从不赋值，接着就 `weapon->query_amount()` 数暗器：每次使用都报错。补上取兵器的判断，手里没有暗器时拒绝（“你手中没有暗器”）。


## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

22 个文件、27 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/huanhua/npc/obj/jinpao`、`/d/huanhua/npc/obj/liangongfu`、`/d/huanhua/npc/obj/changshan`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 2 个，改后 8 个（6 个原来载入不了），没有退步；其余 14 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了。改后用 `lpcc` 逐个载入这些对象：2 个通过。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 15 个对象设了本库没有文件的武功（8 个名字，最多的是 `huanhua-shenfa`、`confu`、`huanhua-jianfa`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：15 个里 15 个通过。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/inherit/weapon/stick`（宏 `STICK`）←zxty08nxgbb，3 个对象继承它，抽样 1/3 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 17 处、14 个文件：`yan-fly`→`yanfly`（3 处）、`yijin-jing`→`yijinjing`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`poyu-qua`→`poyu-quan`（1 处）、`meinu-quan`→`meinv-quan`（1 处）等共 9 个名字。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 17 处、17 个文件：`::create()`（17 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 2 个文件：`/d/baituo/npc/obj/bowl.lpc`、`/d/baituo/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 1 个：`d/feitian/npc/wolf`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `UNARMED_ATTACK`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 1 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc`、`/d/rock/shengji.lpc`、`/u/jerry/npc/shengji.lpc`、`/u/rock/hlxy/zs.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/east_copy_1/haitan.lpc` 的 `south` 出口：`guangchang` → `yedian`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- 1 个 NPC 文件、1 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。
