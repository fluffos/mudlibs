
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
