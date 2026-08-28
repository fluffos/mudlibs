
## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云Ⅳ（Sumxin fengyun），一款以古龙小说为题材的 MUD（sumxin.com/bbs、fy.sumxin.com）。和 wqfy（本轮另一个风云系手足档案）血统/bug 模式相同，但是不同的代码库。WASM 修复了经典的 §8.1 GBK 字节区间 is_chinese() bug：adm/simul_efun/chinese.lpc 的 is_chinese() 要求偶数字节对长度，还检查 str[0] 的原始字节区间（161-254），会拒绝合法的奇数字符数 UTF8 中文名字；adm/daemons/logind.lpc 自己的 check_legal_name() 有对应的 i%2 奇偶门槛，以及按字节数算的长度界限（2-10，本意是按用户提示"一到五个中文字"应为 1-5 个字符）。已把 is_chinese() 改成逐码点 0x4e00-0x9fff 区间检查，check_legal_name() 改成逐字符检查，长度界限修正为 1-5。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（存在两个 securityd.lpc 候选档案——adm/securityd.lpc 和 adm/daemons/securityd.lpc——已通过 SECURITY_D 宏确认 /adm/daemons/securityd 才是真正生效的那份，符合 §7.56 记载的双档案歧义模式；WIZLIST 真的会在开机时被读取）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 编码选择→英文 id→y/n 确认创建→中文名字→密码+确认→性别（m/f）→民族选择（0-3）→带着完整角色属性表和可用的 score/look 指令进入游戏世界，全程没有任何意外错误。测试笔记：性别/民族选择正好接在 std/char.lpc 首次编译的大量负荷之后，引发了和 xhcii/xkyxciii 上记载过的同一类测试工具时序竞争——用 --idle 4 补发额外的 'm'/'0' 能可靠绕过；这是客户端时序上的假象，不是 mudlib 本身的缺陷。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高阶层里。LPC 格式化工具对全部 8238 个档案运行（写入 6459 个，1775 个报错——几乎全部是安全的 TOKEN MISMATCH 安全闸门跳过，针对无法幂等往返的杂乱历史代码，跳过比例明显偏高但无害，因为被跳过的档案完全没有被改动——4 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。唯一一个存在的 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 15 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,188 处存活匹配，全部标准独立行形式，脚本一次
  性删除，无不规则残留。本库没有房间生成类工具（`roommaker`/
  `makeroom` 均未找到），不涉及工厂模板修复。`data/` 下额外核查过，无
  命中。验证：真实 debug 驱动干净编译启动、端口正常监听，`debug.log`
  无新增 "cannot replace"/错误行。

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

## 深度功能测试（round two，2026-08-27）

第一次完整的 §10.7 连续游玩测试（此前该库从未做过完整 round-two
playthrough）。用真实原生 driver（端口 40149）走完了：注册（中文名
"沈牧"，id `shenmu`）→ look/score/i/hp → 移动 → 商店购买 → 帮派拜师
两条路径 → study/learn 技能路径 → fight（安全切磋）/kill（真实战
斗）→ 留言板只读测试 → 两轮断线重连 → 管理员账号验证 → 系统性 grep
排查了任务里列出的全部标准 cross-cutting bug 类别。

**发现并修复了 3 个真实 bug：**

1. **`adm/obj/master.lpc::log_error()` 把编译 WARNING 当错误播给玩家
   看（AGENTS.md §7.103 的确认实例）。** 注册后走 `look`/`score`/`i`
   立刻触发多条 `编译时段错误：...warning: Unused local variable 'x'`
   字样的原始编译警告文本，直接打印在普通玩家屏幕上（`cmds/std/
   look.lpc`/`cmds/usr/inventory.lpc`/`std/char/master.lpc` 首次编译
   触发）。修法：`if (this_player(1)) efun::write(...)` 改成
   `if (this_player(1) && strsrch(message, "warning:") == -1)
   efun::write(...)`。重启驱动后用同样的 register→look→score→i 流程
   复测，干净无警告输出。

2. **`adm/simul_efun/file.lpc::log_file()` 缺少 `assure_file()` 目录
   保护，导致管理员 `call` 指令对玩家目标彻底失效（AGENTS.md §7.11
   的确认实例，和 `xyj2006n`/`xyj2006zzzhx` 同一形状同一文件）。**
   现场复现：用管理员账号 `call shenmu->add_money("coin", 5000)` 给
   测试角色注资时，`call.lpc` 自己在真正调用目标函数之前先往
   `/log/nosave/CALL_PLAYER` 写审计日志——但 `/log/nosave/` 目录从未
   存在于本库归档里，`write_file()` 静默失败并抛出未捕获的执行时段
   错误（"Wrong permissions...No such file or directory"），导致后面
   的 `call_other()` 根本没有执行——确认了目标角色的物品栏完全没有
   变化。这意味着管理员最常用的调试指令 `call` 对任何玩家目标从来
   没有真正生效过。修法：在 `log_file()` 里实际调用文件里已经写好但
   从未被使用的 `assure_file(LOG_DIR + file)`（因为它在同文件里定义
   在 `log_file()` 之后，加了一行前向声明）。重启后复测：同样的
   `call` 指令干净执行，目标角色物品栏真的发生了变化，
   `/log/nosave/CALL_PLAYER` 按需自动创建。

3. **`adm/daemons/logind.lpc::reconnect()` 断线重连时泄漏旧的
   `link_ob`（新增 AGENTS.md §7.155，和 §7.150 的检查目的相同但是不
   同的具体形状）。** 按任务要求做了两轮"断线（非 quit）→ 等待→重
   连"循环，发现 `reconnect()` 把 `user` 的 `link_ob` 临时变量直接
   覆盖成本次新连线对象，却从未 `destruct()` 掉上一次会话遗留的旧
   `link_ob`——而同一文件里几行之外的"踢掉重复登录"分支
   (`confirm_relogin()`) 是正确处理这个场景的。旧 `/obj/login` 对象
   因为自己的 `time_out()` 自清理逻辑在 `body_ob` 被设置后会主动放
   弃（`if (objectp(query_temp("body_ob"))) return;`），所以永远不会
   自行销毁，每一次非 quit 的断线重连都会永久泄漏一个对象。本库这份
   `/obj/login` 没有 heart_beat，所以不会像经典 §7.150 那样反复用陈
   旧数据覆盖存档，但仍然是一个真实、会无限累积的对象泄漏。修法：在
   `reconnect()` 里补上和 `confirm_relogin()` 一样的
   `old_link = user->query_temp("link_ob"); if (old_link && old_link
   != ob) destruct(old_link);`。重启后复测两轮"断线→等待→重连"循环，
   `debug.log` 干净无错误，且 `find_player()`/管理员 `call`/`tell`
   在两轮重连之后依然能正确找到角色（本库的 `set_living_name()` 注
   册挂在常驻的角色对象本身而不是登录壳对象上，所以 §7.152 描述的
   "重连后 find_player 失效" 这条具体症状在本库并不成立——但泄漏对象
   本身仍然是一个需要修的真实 bug）。

**测试过但确认干净、未改动的部分：**

- `fight`（安全切磋）指令：对满血友好型 NPC（店小二）测试，正确按
  `accept_fight()` 逻辑婉拒——设计如此，不是 bug。
- `kill`（真实战斗）指令：对丐帮"一袋弟子"老乞丐（combat_exp 100）
  测试，双方多回合互有攻防、无一方造成伤害（数值层面，不是 bug），
  中途用移动指令安全撤离，`debug.log` 全程无错误。
- 帮派拜师：测试了两条路径——`apprentice old beggar`（丐帮普通乞丐，
  没有覆写 `attempt_apprentice()`，调用未定义函数在本驱动上静默返回
  0，师父不会主动收徒；这是"只有真正的帮主才能收徒"设计的自然结
  果，不是 bug）和 `apprentice tianji`（风云天下的天机老人，明确注
  释"收徒极挑剔"，`attempt_apprentice()` 只出一道机锋考题、没有任何
  代码路径真正完成收徒——和它自己的角色设定"极其挑剔"完全吻合，判定
  为有意的设计，不是 bug，未改动）。
- `study`/`learn` 技能路径：从警世书局读千里处购买《轻功简介》
  (movebook) 成功（`buy movebook from duqianli`，正确扣款找零）；
  `study movebook <神数量>` 因为角色 `literate` 技能为 0 被拒绝
  （"你看不懂耶"），`learn <技能> from <NPC> with <潜能点>` 对没有
  覆写 `recognize_apprentice()` 的普通人类 NPC（读千里）同样被拒绝
  ——这些都是 `cmds/std/study.lpc`/`cmds/std/learn.lpc` 自身文档化的
  前提条件在正确生效，不是 bug。
- 留言板（风云天下"盘龙摩天柱(Stone)"）：255 条真实历史留言，
  `read 1` 读出一条 2001 年前后的真实存档内容（茶茶/teatea 的
  emote 收集通告）；`read next`/`read new` 依次正确前进到 #2、#3，
  没有 §7.153 的分页 bug。严格只读，未使用任何 discard/delete 类指
  令。
- `quit` 会无差别丢弃玩家身上所有非 autoload 物品（金钱、书籍、衣
  服）——这正是 `newbie.txt` 自己第 5 条明确警告过的设计（"暂时离开
  风云之前应先当铺/银行寄存"），不是 bug。
- 断线重连：`find_player()`/管理员 `call`/`tell` 两轮重连后均正常，
  唯一发现的问题已在上面第 3 条修复。
- 管理员账号：`adm/etc/wizlist` 里列有 `fluffos (admin)`，但存档目
  录里此前从未真正存在过 `fluffos` 的注册档案（`data/{login,user}/
  f/fluffos/` 不存在）——本轮通过真实注册流程补种（id `fluffos`，
  密码 `Mud@2026`），登录时立即显示"目前权限：(admin)"，
  `wizlist` 指令输出确认在场。这不是代码 bug（wizlist 权限判定本身
  是正确的、按 id 动态查表），只是此前的"已验证"记录缺少实际存档
  佐证；现已实际播种并提交。
- 系统性检查了任务列出的全部标准 cross-cutting bug 类别（§4.3 静态
  转 nosave、§4.4 BIG5 0x5C、§7.80/§7.118 文件名切片、§7.121 浮点/整
  数、§7.122 autoload 重复、§7.123 裸文件作用域 mapping/array 赋值、
  §7.124 百分比阈值、§7.126 stale .c 扩展名、§7.129 tell_room 传
  0、§7.130 query_idle 无条件调用、§7.131 find_living 注册、§7.132
  map() 绑定、§7.133 net_dead apply、§7.134 无初始化累加器、§7.136
  verb soul 剥离、§7.139 catch_tell 配置、§7.141 replace_program 折
  叠、§7.142 虚拟对象引擎、§7.143 force_me 不匹配、§7.144 一次性
  set_name、§7.145 verb 遮蔽、§7.146 单斜杠注释、§7.147 factory 空
  指针、§7.148 保留字参数名、§7.149 首位管理员自动提升）——均未发现
  新的命中；`feature/vendor.lpc`/`adm/simul_efun/message.lpc` 里的
  `tell_room`/`message()` 转发已经是正确的 `exclude || ({})` 写法，
  没有 §7.129 的问题。

**测试角色**：`shenmu`（沈牧）在提交前已清理（`data/{login,user}/s/
shenmu/` 已删除）。保留的唯一存档账号是管理员种子账号
`data/{login,user}/f/fluffos/`（id `fluffos`，密码 `Mud@2026`，
`(admin)` 权限）。
