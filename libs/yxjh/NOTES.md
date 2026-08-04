
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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

浴血江湖3梦回江湖。WASM 修复找到并修好了 5 个真正的 bug：（1）压缩包里缺少不带后缀的 adm/etc/preload 档案（只有 preload.bak 和一份稍短的 preloadbb 变体）——已从 preload.bak（两者中更完整的一份）恢复，而这份档案还带有 CRLF 换行符，update_file() 的 explode(str,"\n") 不会剥除它们，导致每一个预加载精灵的路径都被静默地变成了例如 '/adm/daemons/securityd\r.lpc'，file_size() 检查失败——已转换成 LF 让预加载真正生效（之前实际上零个精灵被预加载；logind.lpc 之所以之前还能凑合工作，纯属侥幸，是因为它直接继承自 clone/user/login.lpc）。（2）唯一真正生效的 adm/daemons/logind.lpc 里标准的 §8.1 GBK 字节区间 check_legal_name()（i%2==0 奇偶门槛、name[i..<0] 后缀切片、字节数翻倍的 2/10 界限），已修复成逐码点的 name[i..i] 和 1/5 界限；is_chinese() 本身已经正确。保留了三份死代码备用副本未做改动（clone/user/logind.lpc 和真正的 clone/user/login.lpc 以及 login_back.lpc/loginbak.lpc 放在一起；u/rock/ 是某个巫师的个人全量 mudlib 备份目录，自带一整套 logind.lpc/master.lpc/user.lpc 等）——已通过 config.fluffos 里的 master file/simulated efun file 路径确认，LOGIN_D 和 master 档案配置都没有指向这两处任何一处。（3）master.lpc 的 valid_read()/valid_write()（真正生效的 adm/obj/master.lpc，不是 u/rock/obj/master.lpc 那份死代码副本）缺少标准的 'user == this_object()' 短路判断——两处都已加上。（4）d/jerry/saveme.lpc 的 create() 呼叫了 exert_function(10)——exert_function(string func)（定义在 inherit/char/npc.lpc 里）需要的是一个技能名字符串，不是整数，导致这个 NPC 完全编译不过（'*No program in object'），每次启动都会破坏一整块城市房间的居民；这次呼叫的原始意图已经无法还原（是死代码，不像本次会话其它档案的修复那样是打错的算术），所以直接删掉了，做法和 yhyxcs 更早那次原生启动过程里删掉一个无法还原的强制重新加载技巧、而不是猜测修复方式一致。（5）data/ 下 130 个 .o 存档档案里有 118 个是 CRLF 换行，驱动的 restore_object() 在处理嵌套映射结构时可能会因此卡住——已全部统一转换成 LF；这修复了大部分但不是全部的 restore 问题（见下）。碰 socket 的 adm/daemons/httpd.lpc 和 adm/daemons/network/dns_master.lpc 都不在（现在已经恢复的）预加载列表里，也没有真正的外部呼叫者——保持原样，不需要 §7.52 掏空处理。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这份档案的阶层一直到 (admin) 之上的 (ceo)——为了和本次会话的惯例保持一致，用的是标准的 (admin) 阶层）。注册流程在格式化前后都完整验证过（英文 id→y 确认→中文名字→管理员密码+确认→登录密码+确认→天赋菜单（'0' 随机→'y' 接受）→电子邮件→性别→进入中央广场），管理员权限已通过'◇ 您目前权限：(admin)'确认。已知未修复的问题：即使做了 CRLF 修复，adm/daemons/named.lpc 的 restore_object() 每次启动依然会抛出'Illegal mapping format while restoring dbase'——存档档案里的映射字面量语法上是配平的（已核对括号匹配），所以原因出在这个驱动更严格的 restore_object() 解析器里的其它地方，没有进一步深挖；这个失败已被捕获（preload() 的 catch()），只会降级 named.lpc 的近似名字冲突去重检查功能，不会阻挡注册、进入游戏世界、或任何其它已观察到的功能——按 AGENTS.md §7.15 的精神记录在案，不算阻断性问题。LPC 格式化工具对全部 13038 个档案运行（写入 11874 个，1119 个针对本次会话里最杂乱代码库的转档之前就存在的未结束字符串/文本块错误未做格式化，45 个未改动）。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选，没有 CJK 重新加空格/转义损坏命中。格式化后用同样的完整注册+管理员登录流程重新验证过——干净，管理员权限依然是 (admin)。
