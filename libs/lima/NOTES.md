# lima — Lima Mudlib

来源：`git clone https://github.com/fluffos/lima`（克隆时 HEAD 为
`dbcef2a Update fluffos/lima to 1.1a2 (#33)`，2026-08-24 克隆）。编号
164，端口 40212。状态：**done**（干净启动，真实注册流程 + 角色创建 +
`look`/`score`/`inventory`/`who`/`quit` 全部验证可用；管理员账号
`fluffos` 已播种并验证 `update`/`admtool` 等高权限指令）。按
AGENTS.md §2.3（"已经是 git 仓库、已经针对 FluffOS 适配的源"）流程处理，
而非常规的原始压缩包转换流程。

## 这个 lib 的架构，写给不熟悉 Lima 的读者

Lima 不是本项目里常见的"侠客行/金庸群侠传"系语系（LPMud 经典宗谱），
而是 FluffOS 驱动项目自己维护的官方参考 mudlib（<https://limalib.dev>），
英文，面向开发者/巫师的框架式设计，和本项目收录的绝大多数中文武侠
mudlib 在几乎每个层面上都不同：

- **没有 `add_action()`**——Lima 的 `local_options` 要求驱动编译时定义
  `NO_ADD_ACTION`，房间/物品不用经典的"每个动词一个 `add_action`"模式
  注册命令。取而代之的是一个**集中式自然语言解析器**
  （`parse_command()`/`parse_sentence()`，`secure/master.lpc` 里的
  `parser_error_message()`/`parser_gen_pos()` 等 apply 都是这个子系统
  的一部分），能理解 `take the red potion from the box`、
  `put all coins in bag` 这类完整英语句子，而不是简单的"动词 宾语"。
- **没有传统的 uid 型 root 安全模型**——`master.lpc` 没有实现
  `get_root_uid()`/`get_bb_uid()`（驱动为此打印一条良性警告），取而代之
  是 `/secure/daemons/secure_d.lpc` 实现的一套自成体系的**基于能力
  （capability）的安全系统**：`privileges`（谁拥有哪些权限字符串）、
  `domains`（谁属于哪个"领域"、谁是领域"领主"）、`protections`（目录级
  读写保护等级）、`wizards`（谁是巫师）。`valid_read`/`valid_write` 全部
  委托给这套系统而不是 uid 比较。文档见仓库自带的
  `help/wizard/coding/security`，写得相当详细。
- **巫师用的是类 Unix shell，不是巫师专属指令表**——正常连接后进入的是
  `trans/obj/wish.lpc`（"wish"，Lima 巫师 shell），支持变量
  （`$var = value`）、管道、globbing、命令别名，提示符是
  `? for shell help>`。真正的游戏动词（`look`、移动方向等）在 shell 里
  找不到命令对象时会 fallback 给上面说的自然语言解析器处理。
- **`AUTO_WIZ` 默认开启**——`include/config.h` 里 `#define AUTO_WIZ`
  是上游仓库自带的默认值（Lima 本来就是给开发者/巫师用的框架/演示环境，
  不是要直接放给陌生玩家的正式游戏），意味着**任何新建角色都会立即获得
  向导（Wizard）权限**。第一个在全新安装上创建角色的用户还会额外被
  自动提升为 `Admin`（domain lord，见 `secure/user/sw_body.lpc`
  `sw_body_handle_new_logon()` 的"no admin found"分支）——这是上游
  故意如此设计，不是本项目引入的漏洞，在 README 里也做了说明。

## §7.46 的后续：LIMA 系驱动编译选项冲突，这次真的解决了

AGENTS.md §7.46 早先记录过一个结论："基于 LIMA 代码库的 mudlib 需要
本项目共享驱动没有的编译期开关（`NO_LIGHT`/`NO_ADD_ACTION`/
`NO_WIZARDS`/`undef OLD_ED`/`undef PACKAGE_UIDS`），不在源码层面可修，
需要一个单独编译的驱动 —— 当时判定为 out of scope"（案例：`sgzmudsgz`，
一个基于 LIMA 代码库的三国志 MUD）。这次直接拿到了 LIMA 本尊，所以把
这件事真正做掉了：

- `~/src/fluffos-lima`：用 `git worktree add ~/src/fluffos-lima
  <与~/src/fluffos相同的commit>` 从共享驱动源码树建的**独立工作树**
  （不是完整重新 clone，共享同一份 `.git` 对象库，但工作目录文件互不
  影响，编辑其中的 `src/local_options` 不会污染其它 lib 用的
  `~/src/fluffos/build-debug`）。
- `src/local_options` 改动（对照本项目默认驱动的原值）：
  `NO_ADD_ACTION`/`NO_WIZARDS`/`NO_LIGHT` 从 `#undef` 改为 `#define`，
  `OLD_ED` 从 `#define` 改为 `#undef`。
- CMake 配置额外加 `-DPACKAGE_UIDS=OFF`（默认 ON，Lima 自带的
  `secure/check_config.c` 显式要求它关闭）。`PACKAGE_PARSER`/
  `PACKAGE_CONTRIB` 默认已经是 ON，不用改。
- 构建：`cmake -S ~/src/fluffos-lima -B ~/src/fluffos-lima/build-debug
  -DCMAKE_BUILD_TYPE=Debug -DMARCH_NATIVE=OFF -DUSE_JEMALLOC=ON
  -DSTATIC=OFF -DPACKAGE_UIDS=OFF && cmake --build
  ~/src/fluffos-lima/build-debug --target driver lpcc -- -j$(nproc)`。
- 验证：`~/src/fluffos-lima/build-debug/src/options.autogen.h` 里确认
  `__NO_LIGHT__`/`__NO_ADD_ACTION__`/`__NO_WIZARDS__` 三个都出现（已定义），
  `__OLD_ED__`/`__PACKAGE_UIDS__` 都不出现（未定义）——`secure/
  check_config.c` 的六个要求全部满足，不再在 `simul_efun` 编译期
  `error()` 掉整个启动。

**重要**：`libs/lima/` 不能用 `~/src/fluffos/build-debug`（本项目其余
~240 个 lib 共用的默认驱动）启动——`secure/check_config.c` 会在
`simul_efun` 编译时因为上述六项全部不满足而报错并中止启动。必须用
`~/src/fluffos-lima/build-debug/src/driver`。这个 worktree 是本 session
新建的，**不在 git 版本控制内**（`~/src/`，不是 `libs/lima/` 下），
如果这台机器/这个 checkout 丢失了要重新按上面步骤建一次——大概 5-10
分钟的一次性编译，之后复用。

WASM 状态标为 `partial (native only)`：要让这个 lib 在浏览器里跑，
还需要在 `emcmake cmake --preset wasm` 的基础上叠加同样的
`local_options`/`PACKAGE_UIDS=OFF` 改动，构建一个专用的 wasm 驱动——
留作未来工作，这次 session 的任务范围（见协调者的原始指令）没有要求
WASM 通道。

## 转换步骤（对照 AGENTS.md §2/§2.3）

1. 克隆到 scratch 目录，`lib/` 就是 mudlib 根（README 自带的
   `mudlib directory : ./lib`）；`driver/`（fluffos 子模块）、
   `resources/`、`build.sh` 等构建脚手架按约定忽略，只取 `lib/`。
2. 编码：整个仓库 1969 个文件里只有 2 个非 UTF-8——`WWW/lima.jpg`
   （二进制图片，正常）、`help/wizard/coding/parser`（一处 Latin-1
   版权符号 `©`，`iconv -f latin-1 -t utf-8` 修复）。其余全部原生
   ASCII/UTF-8，符合"最新 fluffos 兼容的现代仓库"预期，不需要
   GB18030/BIG5 转换。
3. `.c` → `.lpc`：`scripts/convert_lib.sh`（用 `UTF-8` 作为"源编码"
   跑一遍，等价于跳过转码、只做改名 + 引用修复），1095 个 `.c` 文件
   全部重命名，118 处字面量 `.c"` 引用自动修复，0 处遗留。
   - 发现一处 §4.2 条目 5（"扩展名缺失文件 + 同名 `.c` 备份"）的实例：
     `secure/daemons/finger_d`（无扩展名）与 `finger_d.lpc`（原
     `finger_d.c`）内容不同。`git log` 确认 `finger_d.c` 是最近一次
     commit（`Update fluffos/lima to 1.1a2 #33`）改过的版本，无扩展名
     的那份自 `#28` 之后再没被碰过——是过时内容，已删除。
   - `static -> nosave` 批量替换踩了 §4.3 描述的"字符串字面量误伤"：
     `domains/std/lima/workroom_ob.lpc` 一句房间描述文本里恰好出现了
     单词 `static`（"a burst of static darts across your screen"），
     被误替换成 `nosave`，已手动改回。`include/global.h` 里
     `#ifndef __SENSIBLE_MODIFIERS__ #define nosave static #define
     protected static #endif` 的兼容 shim（§4.3 第二类碰撞）也被误伤成
     `#define nosave nosave`，同样改回原文——不过这个 shim 本来就在
     `#ifndef __SENSIBLE_MODIFIERS__` 保护下，本项目驱动始终定义
     `__SENSIBLE_MODIFIERS__`，这段代码从未真正执行，改不改都不影响
     行为，纯粹是为了保持源码忠实。

## 编译期发现的真实 bug（而非内容/示例缺口）

以下几处是**驱动兼容性/程序错误**，符合本项目"只修程序 bug，不改
内容设计"的范围，已修复：

1. **`.c`→`.lpc` 改名的连锁反应：命令查找机制本身就没跟上扩展名变长**
   （AGENTS.md §4.2 第4类"固定宽度切片而非扩展名操作"，这次是同一类
   bug 在上游自己的 `.c`-命名树里原本"恰好正确"，被本项目的重命名
   直接触发）。`secure/daemons/cmd_d.lpc` 的 `cache_dir()`
   用 `get_dir(dir+"?*.lpc")` 拿到文件名后用 `$1[0..<3]` 砍掉扩展名——
   这个切片宽度是为**两个字符**的 `.c` 算的（`<3` 在这个驱动的区间
   语法里表示"从末尾数第 3 个字符（含）到开头"，对 5 字节的 `foo.c`
   算出 `foo`），改名后文件变成 4 字节的 `.lpc`，同一个 `<3` 切出
   `score.l` 这种带垃圾尾巴的"命令名"，导致**几乎所有裸词形式的
   巫师/玩家命令全部失效**——`score`、`inventory` 等在 shell 里输入
   会报 `I don't know the verb 'score'`，只有写全路径
   `/cmds/player/score` 才能跑（`score.lpc` 本身完全正常，纯粹是
   路径匹配层面的缓存 key 算错了）。这是**这次转换里影响面最大的一个
   bug**——不修的话整个游戏对话式命令行基本不可用。同一切片模式在
   `cmd_d.lpc` 另一处（`smart_arg_parsing` 里按绝对路径匹配后取
   `cmd_name`）、`daemons/spell_d.lpc`（重建法术目录缓存）、
   `daemons/quest_d.lpc`（显式 `if (base[<2..]==".lpc")` 判断之后却用
   两字节宽度去砍）里各出现一次，一并改成 `<5`（对应 4 字节的
   `.lpc`）。已用真实驱动重新启动、注册、`score`/`inventory`/`update`
   等裸词命令验证全部恢复正常。全仓库还有 27 处同形态的 `[0..<3]`
   切片，逐一读取上下文后确认其余都是无关的字符串截断（去掉末尾逗号、
   `"\n\n"`、`"::"` 等），或是针对 `.o`（`SAVE_EXTENSION`，仍是 2 字节，
   不受影响）——只有以上 4 处真的和 `.c`→`.lpc` 改名相关。
   **不提交上游**：这是本项目自己 `.c`→`.lpc` 改名操作触发的问题，
   上游 `fluffos/lima`/`limalib/lima` 原生文件名仍是两字节的 `.c`，
   `[0..<3]` 在那里本来就是对的——这是本项目的转换产物，不是 lima
   自己源码里的 bug，不属于这次 upstream PR 审计范围（2026-08-31）。
2. **`set_droppable()` 参数类型声明过窄**：`std/modules/m_gettable.lpc`
   自己的文档注释写"传函数或字符串等效于调用 `set_dropmsg()`"，函数体
   也确实用 `functionp(g) || stringp(g)` 判断，但签名却声明成
   `void set_droppable(int g)`——这个驱动的静态类型检查因此拒绝
   `domains/std/lima/directory.lpc`/`workroom_ob.lpc`（后者正是新巫师
   自己的 workroom）里传字符串自定义"拿不下来"提示语的调用。参数类型
   改成 `mixed g`，和函数体实际行为、文档注释保持一致。
   **已提交上游**：`fluffos/lima` 已于 2024-10-08 被官方**归档只读**
   （`gh pr create` 直接报 GraphQL 错误"Repository was archived so is
   read-only"），无法开 PR。经核实，同一 LIMA 社区（同一 Discord 频道
   `#LIMA`、同名品牌"limamudlib.dev"）已迁移到活跃维护的
   `limalib/lima`（非 fork 关系但代码血缘一致，`git clone` 核对确认
   `m_gettable.c`/`m_exit.c`/`usermenu.c` 三处逐字节相同，同一 bug
   原样存在），已改为向 `limalib/lima` 提交：
   **[limalib/lima#49](https://github.com/limalib/lima/pull/49)**。
3. **`private` 跨文件继承调用**（AGENTS.md §7.48 标准案例）：
   `std/modules/m_exit.lpc` 的 `eval_dest()` 声明为 `private`，却被
   继承它的 `std/modules/m_exit_obj.lpc` 直接调用——这个驱动对
   `private` 的强制比老 MudOS 严格（继承链内也不能跨文件调），改成
   `protected`（比 `private` 宽松，不会引入新 bug，只会修好已经存在的
   非法调用错误）。
   **已提交上游**：同上，`fluffos/lima` 已归档，改为
   **[limalib/lima#50](https://github.com/limalib/lima/pull/50)**。
4. **含内联注释的宏参数展开异常**：`daemons/spell_d.lpc` 里
   `ENSURE(spell_name /* 注释 */)` 这种"宏参数里带 C 风格块注释"的写法
   触发这个驱动预处理器的一个真实 bug——`ENSURE` 宏没有正常展开，报
   `Undefined function ENSURE` 后级联出语法错误，导致
   `daemons/spell_d.lpc` 本身以及依赖它的 6 个法术文件全部编译失败
   （`fireball`/`magic_arrow`/`unlock`/`test`/`ale` 及 stock-mage 分支）。
   已构造最小复现（两行 LPC：`ENSURE(x /* c */);`）确认与具体文件内容
   无关，是宏参数解析器本身在"参数里含 `/* */`"时的通用问题——不打算在
   本项目范围内修驱动本身（那是 fluffos/fluffos 的事，需要走 PR），
   采用等价、保留原意的写法规避：把注释挪到宏调用**外面**
   （`ENSURE(spell_name); /* 注释 */`），两处均已修复并验证。
   **不属于本次 lima queue 审计范围**：这是 `fluffos/fluffos`
   驱动本身的 bug，不是 `fluffos/lima`/`limalib/lima` 源码的 bug——
   本次任务（2026-08-31）只审计 lima 的 mudlib 源码是否需要提 PR，
   驱动仓库层面的 PR 不在这次的范围内，未提交。
5. **含"开括号后紧跟内容"的 heredoc（`@TAG content...`）在这个驱动的
   词法分析器里同样有真实问题**：`std/race/troll.lpc`
   （`@LONG Trolls are...`）和 `WWW/cgi/autodoc.lpc`（7 处
   `@END<title>...`）在开始标记同一行紧跟正文时报
   `End of file in text block`——已用两行最小复现确认（`@LONG hi\nthis
   is\na test\nLONG;` 能编译，把首行改成 `@LONG hi` 同一行接内容就不能）。
   同样倾向于判定为驱动词法分析器的真实 bug（不在本项目范围内修驱动，
   fluffos/fluffos 需要走 PR），mudlib 侧用等价、保留原文内容的写法
   规避：把开始标记单独放一行，正文从下一行开始。`troll.lpc` 已完全
   修好（唯一一处），`autodoc.lpc` 的 7 处开始标记都修了，但该文件的
   HTML 内容里**结束标记本身也不是顶格**（比如 `             <UL> END
   +`，`END` 前面还有真实 HTML 内容），而这个驱动的 heredoc 结束标记
   必须是整行的最前面——这是另一类、更深的方言差异（老式 LPC 允许
   结束标记出现在缩进/行内任意位置，这个驱动不允许），不是简单挪一行
   能解决的，`autodoc.lpc` 因此仍然编译失败。鉴于它只是一个默认未启用
   （`http_d` 在 `preload` 里被注释掉）的巫师专用 CGI 文档生成工具，
   不影响核心游玩，这里记录下来但不再深入修——留给以后需要真正用到
   web 文档生成功能时再处理。
   **不属于本次 lima queue 审计范围**：同上一条，这是 `fluffos/fluffos`
   驱动词法分析器本身的 bug，不是 lima 源码的 bug，本次审计
   （2026-08-31）未提交驱动仓库层面的 PR。
6. **赋值/比较符打错**：`obj/usermenu/usermenu.lpc` 的
   `confirm_decision()`——`if (dec == "yes" || dec = "y")`，第二个条件
   是赋值不是比较，导致这个函数**永远返回真**，无视用户实际输入的
   "确认删除角色"对话框形同虚设（`remove_char` 流程里的 yes/no 确认，
   不管输入什么都会被当作"是"）。改成 `==`。
   **已提交上游**：同上两条，`fluffos/lima` 已归档，改为
   **[limalib/lima#51](https://github.com/limalib/lima/pull/51)**。

## §2.2 On-sight checklist 结论

- `master.lpc` 没有 `get_root_uid()`/`get_bb_uid()`（驱动打印良性警告，
  见上文"架构"一节——这套 mudlib 本来就不走 uid 安全模型）。
- 没有 `destruct(simul_efun)` 相关问题；`secure/simul_efun.c` 通过
  `private inherit check_config` + 一串 `inherit
  simul_efun/{overrides,security,objcalls,userfuncs,path,string,misc,
  more,tell,goofy,json}` 组装，`check_config` 的驱动兼容性自检见上文
  "§7.46 的后续"一节。
- `this_user()` 在 `secure_d.lpc` 里被大量、正确地用在权限校验链的
  末端（`check_privilege()` 的调用栈遍历），符合预期。
- preload 列表（`data/config/preload`）没有 dns/intermud 相关裸目录
  引用问题；`daemons/imud_d` 因为 `ADMIN_EMAIL` 仍是上游占位符
  `billg@microsoft.com` 而拒绝加载（`imud_d.lpc` 自己的保护性检查，
  报错信息很清楚）。**保留原样未修**——这是刻意的自我保护
  （防止误配置的 mud 用假地址骚扰 Intermud 网络），且本项目对其余
  ~240 个 lib 的标准策略本来就是"DNS/intermud 排除在 preload 之外"
  （§7.6），imud_d 加载失败只是让 preload 的 `catch()` 静默跳过，不
  影响其余功能，不需要改动 `config.h` 让它连上真实的公网 I3 网络。
- 中文检测/`check_legal_name` 相关条目不适用——这是纯英文 lib。
- 命令派发（cmd_d.lpc 的 `private`/`nomask command_hook` 类问题）：
  见上文 bug #1（cache_dir 切片宽度），是这次唯一命中的、而且是
  影响面最大的一类。
- 端口硬编码：`config.lima`/`include/config.h` 都没有硬编码端口常量，
  端口完全由 `config.fluffos` 的 `port number` 决定，改起来没有陷阱。
- `static`/`nosave` collision：见上文转换步骤一节，已处理。
- `ed_start`/`ed_cmd`/`query_ed_mode`：**存在**（`trans/obj/
  ed_session.lpc` 等 6 个文件），但这次驱动是专门按 Lima 自己的
  `local_options` 要求 `#undef OLD_ED` 编译的，这三个 "new ed" efun
  在这个专用驱动上是真实存在的（`core.spec` 里
  `#ifdef OLD_ED ... void ed(...) #else string ed_start(...) ...`），
  不是 §6.2 描述的那种"这个驱动只有老 ed()"的情况——这正是这次专门
  建一个 Lima 专用驱动要解决的问题之一，编辑器/`update`/`ed` 命令都
  验证可用。

## 管理员账号播种

Lima 自己的安全模型是"能力（capability）+ 领域（domain）"式的，没有
本项目其它 lib 常见的"`adm/etc/wizlist`"或"`(admin)` 状态字符串"，
而是 `/data/secure/access.o`（`SECURE_D` 的存档文件，
`ACCESS_SAVE="/data/secure/access"`）里的 `wizards` 和
`domains["admin"]` 两个 mapping。**上游仓库自带的原始档案是一个"全新
安装、什么人都没有"的空白状态**（`wizards ([])`，`domains["admin"]
([])`）——这本来就是设计使然：`secure/user/sw_body.lpc` 的
`sw_body_handle_new_logon()` 里有一段"没有任何 admin 时，把第一个创建
角色的人自动提升为 admin"的引导逻辑（自举机制），正常情况下靠"第一个
真人巫师创建角色"就能完成播种，不需要额外操作。

但本项目的标准约定是固定的 `fluffos`/`Mud@2026` 账号，而不是"谁先手快
谁当家"——为了不依赖"谁第一个连上来"这种时序，直接编辑
`data/secure/access.o`（纯文本的 `save_object()` 格式，逐行
`变量名 值` ），把 `wizards` 加上 `"fluffos":1`，把
`domains["admin"]` 加上 `"fluffos":2`（2 = 领域领主/lord，和
`add_domain_member(domain, member, lord)` 的语义一致）。这样一来，
`fluffos` 一注册就直接是 admin，同时因为 `domains["admin"]` 已经非空，
"自动提升第一个人"的引导逻辑不会再对后续任何测试账号触发（已用
`traveler`/`finaltest` 两个测试角色验证：它们注册后只拿到普通
`AUTO_WIZ` 赠送的 Wizard 权限，`who` 里 Role 显示 `Wizard`，不是
`Admin`——引导逻辑确实只认第一次）。`data/secure/access_backup.o`
（`save_data()` 顺带写的备份文件，启动时不读取）同步更新以保持一致，
测试期间产生的其它账号相关残留（`traveler`/`finaltest` 的存档、
`data/referrals`、`data/secure/LOG`、`data/daemons/last_login.o`）已
清理，只留 `fluffos` 一个种子账号。

验证：`fluffos` 登录后 `who` 显示 `Role: Admin`；`update
/std/race/human`（读+写都要过 ACL 的规范检验）和 `admtool`
（进入管理菜单，能看到 `1 - priv 1` 选项）均成功，说明播种的不只是
"看起来像 admin"的展示状态，写权限确实生效。

## 已知但未修的内容/示例缺口（按项目惯例：不是程序 bug 就不动）

编译扫描（`lpcc --batch`，1095 个 `.lpc` 文件）在上述 bug 修复后还剩
38 个失败，逐一读取错误信息确认全部是**内容/示例本身的缺口**，不是
驱动兼容性问题：

- `domains/std/school/`（新手教程区）、`domains/std/rooms/{caves,
  labyrinth}` 里少数房间引用了未提供的辅助函数（`start_decay`、
  `set_default_exit`、`ROOM` 全局量），像是这套教程区自己就没写完的
  演示内容。
- `contrib/`（`bboard`、`marriage`、`roommaker`、`transient_effect`
  等）——仓库自己就标成"贡献/可选扩展"目录，`contrib/marriage/
  finger_d.lpc` 引用了一个不存在的 `class finger` 成员 `spouse`，像是
  一次不完整的重构遗留。
- `domains/std/spells/stock-priest/`——`std_priest_spell.lpc` 调用
  `set_cast_time()`/`set_difficulty()`，但全仓库没有任何地方定义这两个
  函数，法术系统这一分支本身就没写完。
- `cmds/player/attic/`、`domains/std/attic/`——目录名本身就是"阁楼/
  废弃"，`m_react.lpc`（`domains/std/attic/{beavis,butthead}` 用到）里
  确实有一处看起来是真实类型错误（`x++` 用在字符串上），但鉴于这些是
  两个彩蛋 NPC 用的、已标记废弃的模块，判定为"内容归档"范畴，不在这次
  的核心游玩验证路径上，不处理。
- `obj/secure/mailers/{mailer,Mh,standard}.lpc`——邮件撰写用到一个
  全仓库都不存在的 `trim_spaces` 函数，且有一处"functional 里用局部
  变量"的驱动限制。`imail_d` 本身正常 preload（收发基础设施没问题），
  但撰写新邮件这个具体功能路径有缺口。因为这属于要新写一个辅助函数、
  猜测其确切行为的范畴，不是一处明确的打字错误，按"内容/设计判断，
  不确定就不动"的原则记录、不修。
- `WWW/cgi/{autodoc,mudinfo}.lpc`——见上文 bug #5 的详细说明；
  `http_d`（唯一会用到这些 CGI 脚本的daemon）默认在
  `data/config/preload` 里被注释掉，不影响核心游玩。
- `secure/daemons/ftp_d.lpc`——一处"functional 里用局部变量"的驱动
  限制，`ftp_d` 同样默认不在 preload 列表里。

## 定义完成的验证记录

用 `scripts/mudclient.py` 通过真实驱动完整走过三轮独立账号
（`questor`→`wanderer`→`traveler`，以及最终的 `fluffos`/`finaltest`）：
注册（id/密码/性别/邮箱/真实姓名/主页/推荐来源全部走完）→ 用户菜单
`c` 创建角色 → 种族选择（human/elf 两种都测过）→ `s` 选择角色 → `p`
进入游戏 → 落地在 Grand Hall（Lima Bean 巫师聚会场所，游戏内自带的
"新手/巫师起始房间"，因为 `AUTO_WIZ` 的关系每个新角色都从这里开始）→
`look`（房间描述正确重复）→ `score`（ASCII-art 状态面板，含种族对应的
六维属性、经验、卡玛值）→ `inventory`（"You are empty handed."）→
`who`（正确列出在线角色和权限等级）→ `quit`（正常退出，
`[announce]` 频道正确广播离线消息，回到用户菜单，`debug.log` 全程
无报错）。管理员账号额外验证 `update`/`admtool`。整个流程干净、无
崩溃、无静默失败。

## 附录（2026-08-26）：`limalib/lima`（"modernized LIMA" fork）调查结论 —— 负面结果，未新建 lib

外部研究提到一个 GitHub 仓库 `limalib/lima`（<https://github.com/limalib/lima>，
自称 "Updated, maintained, modernized LIMA mudlib updated to run latest
FluffOS driver. Kept in the original LIMA spirit."，官网
limamudlib.dev，文档 docs.limamudlib.dev，HEAD `eb25dc6`，2025-10-27），
怀疑这个"现代化"分支是否已经从根本上摆脱了 §7.46 记录的驱动编译期开关
冲突（本条目上文已经用的那五项：`NO_LIGHT`/`NO_ADD_ACTION`/`NO_WIZARDS`/
`undef OLD_ED`/`undef PACKAGE_UIDS`）。本次任务专门验证了这一点——
**结论：没有，问题原样保留，`limalib/lima` 和 `libs/lima` 用的
`fluffos/lima` 一样，需要同一套专用驱动才能启动，不构成新的可独立
onboard 的 lib，因此本次只写这条负面结论，不新建 `libs/<slug>/` 目录。**

### 验证过程

1. **代码血缘对比**：`limalib/lima` 和本 lib 来源的 `fluffos/lima`
   是两个独立的 GitHub 组织下的仓库（`limalib/lima` 的
   `defaultBranchRef`/`parent` 显示不是 `fluffos/lima` 的 fork），
   但目录结构和核心文件几乎一致——两边的 `secure/check_config.c`
   逐行 diff 下来，**除了版权头文字和版本号字符串（"MudOS"→"FluffOS"、
   `config.lima`→`config.mud`）之外，`need()` 检查列表完全相同**，
   证明是同一 LIMA 血缘的演进版本，不是独立重写。文件数
   `limalib/lima` 1534 个 vs `fluffos/lima` 1969 个（前者砍掉了不少
   demo 内容，新增了 `obj/admtool`、`obj/tasktool`、`std/race`、
   `cmds/guild` 等框架性目录），属于同一代码库的功能增补/精简，
   不是从零重写的替代架构。
2. **直接读 `limalib/lima` 自带的 `lib/secure/check_config.c`**——
   这就是 LIMA 系 mudlib 用来拒绝在不兼容驱动上启动的自检文件。
   除了沿用 §7.46 记录的五项（`NO_LIGHT`/`NO_ADD_ACTION`/`NO_WIZARDS`/
   `undef OLD_ED`/`undef PACKAGE_UIDS`），还新增了几项检查
   （`SANE_EXPLODE_STRING` 需定义、`CAST_CALL_OTHERS` 需未定义、
   `OLD_RANGE_BEHAVIOR` 需未定义、`MUDLIB_ERROR_HANDLER` 需定义、
   `ARRAY_RESERVED_WORD` 需未定义、`PACKAGE_CONTRIB`/`PACKAGE_PARSER`
   需定义）——但这些新增项本项目共享驱动（`~/src/fluffos/build-debug`）
   原本就满足，不构成新的冲突点；**真正冲突的仍然是那五项经典要求，
   一个字都没变。**
3. **实测启动**：用本项目的 `scripts/convert_lib.sh` 把
   `limalib/lima` 的 `lib/` 转成 `.lpc`（UTF-8 源码，1407 文件已是
   UTF-8、0 需要转码，127 个二进制文件跳过，行为和 `fluffos/lima`
   转换时几乎一样），配上一份仿照本 lib `config.fluffos` 改路径/端口
   的临时配置，直接用**本项目共享的标准驱动**
   （`~/src/fluffos/build-debug/src/driver`，未加任何特殊 flag）尝试
   启动——`simul_efun`/`master` 加载阶段立即被 `check_config.lpc`
   的 `create()` 用 `error()` 中止，实际报错文本：

   ```
   *Bad driver configuration:
   **********************************************************
   * You have incorrectly compiled the FluffOS driver. This  *
   * driver is not compatible with the LIMA mudlib.   Please *
   * make the following changes to 'local_options' ) in the  *
   * driver source, and recompile.                           *
   **********************************************************
   #define NO_LIGHT is required for LIMA libs.
   #define NO_ADD_ACTION is required for LIMA libs.
   #define NO_WIZARDS is required for LIMA libs.
   #undef OLD_ED is required for LIMA libs.
   #undef PACKAGE_UIDS is required for LIMA libs.
   **********************************************************
   The simul_efun (/secure/simul_efun) and master (/secure/master) objects must be loadable.
   ```

   和 §7.46/本 lib 上文记录的 `fluffos/lima` 症状完全一致——不是
   "modernized" 架构层面移除了这个假设，只是版本号/驱动兼容性提示文字
   更新了而已（README 里"modernized"、"run latest FluffOS driver"
   说的是能跟着最新版 fluffos 驱动源码（`adm/dist/fluffos` 子模块跟踪
   `fluffos/fluffos.git`）编译，而不是摆脱 `NO_LIGHT`/`NO_ADD_ACTION`/
   `NO_WIZARDS`/`OLD_ED`/`PACKAGE_UIDS` 这套架构假设）。

### 有用的推论（供未来参考）

`limalib/lima` 要求的五项和本 lib 已经解决的 `fluffos/lima` 要求
**完全相同**，所以本 session 已经建好的
`~/src/fluffos-lima/build-debug`（worktree，见上文"§7.46 的后续"一节）
理论上不需要任何改动就能同时满足 `limalib/lima` 的 `check_config.c`——
如果未来真的要把 `limalib/lima` 也收进本项目（例如作为它自己独立的
lib，因为它的功能集/demo 内容和 `fluffos/lima` 已经有实质差异，不是
纯粹的重复），可以直接复用这个驱动 worktree，不必重新摸索 flag 组合。
但这次任务的范围只是回答"是否解决了驱动 flag 冲突"这一个问题，
结论是否定的，所以没有走完整的 onboard 流程（没有 `convert_lib.sh`
之后的编译修复循环、没有真实注册验证、没有分配 `number`/`port`、
没有新建 `libs/<slug>/` 目录）。

## 深度功能测试 / Deep functional test (2026-08-27, §10.7)

这个 lib 之前只做过"能启动/编译"级别的验证（见上文"定义完成的验证
记录"一节）——本轮是第一次按 AGENTS.md §10.7 的方法论做一次真正连续
的真人playthrough（真实注册 → 探索 → 战斗 → 门派/公会交互 →
quit/隔一段真实时间后重连 → 查日志），用专用的 `~/src/fluffos-lima`
worktree 驱动（已存在，直接复用，未重新编译）。

Lima 本身是 FluffOS 官方的框架/演示 mudlib，不是一款有完整门派/任务
系统的"游戏"——`help newbie` 就是原版英文 Zork 式通用教程，核心可测
系统是：注册/建角、`AUTO_WIZ`巫师身份、导航、`skills`（战斗中自动
熟练度成长）、`kill`战斗、`GUILD_GUARD`门禁、`talk to`NPC 对话、
`quests`、`quit`/重连。测试角色：账号 `TestHero`/`TestPass123`，角色
`Aidan`（human），全程走过注册六项资料 → 建角（种族选择）→ `s`选中 →
`p`进入游戏，落地 Grand Hall；另建了一个非管理员的 `questfinal`/
`Rowan` 角色专门复测下面的 bug 修复（确认不是只有先前角色的残留状态
碰巧绕过了问题）——**两个测试账号连同它们的存档在验证完成后都已按本
项目惯例清理**（`data/players/{a,r}/`、`data/links/{t,q}/`、以及
`GUILD_D` 因这次测试而首次落盘的 `data/daemons/guild.o`），只保留种子
`fluffos` 管理员账号；`data/secure/{access,access_backup}.o`、
`data/secure/LOG`、`data/daemons/last_login.o`、`data/news/*`
里因登录/公会daemon初始化产生的残留字段也已用 `git checkout`
还原，最终 `git status` 只剩两处真实代码改动。

### 发现并修复的真实 bug

**1. `std/guild_guard.lpc` 的 `handle_blocks()` 对一个从未真正被
`GUILD_D` 定义过的公会名，会把驱动的未捕获 `error()` 直接甩给玩家，
导致"从被公会守卫挡住的房间试图离开"这个完全普通的移动动作每次必
崩溃。**

- 复现路径：Grand Hall 向南进入 `domains/std/Monster_Room`（这个房间
  的 hint 文本自己写着"This room is often used to test combat system
  mechanics"，是官方给的战斗测试区），房间里的 `guild_guard`
  （`domains/std/Monster_Room.lpc:13`，`set_objects((["/domains/std/
  guild_guard":({"sorcery"})]))`）挡住唯一的北向出口，要求"sorcery"
  公会成员身份。而 `data/config/guild-spec`/`stock-guilds`
  只是示例数据文件，从未被任何 preload/create() 调用
  `GUILD_D->define_from_file()` 加载，所以"sorcery"这个公会在
  `GUILD_D` 里根本不存在。任何角色（无论是先打赢了这个 5 HP 的守卫，
  还是干脆直接走）只要尝试往北走，`guild_guard.lpc:22`
  的`GUILD_D->query_guild_allies(guard_for)`就会一路调用到
  `daemons/guild_d.lpc:269` 的 `guild_check()`——这个函数对不存在的
  公会名统一 `error("Non-existant guild - " + name + ".\n")`，而
  `handle_blocks()` 完全没有 catch 这个调用。结果：一个真实的、未捕获
  的驱动错误，栈顶层展开后还级联出第二个无关错误
  （`/cmds/verbs/go.lpc` 报 `Parse accepted, but no do_* function found
  in object /cmds/verbs/go!`，是第一个错误把 `do_go_str()`
  的执行流打断后遗留的状态不一致）。玩家因为 `AUTO_WIZ`
  默认订阅了 errors 频道，会直接在自己的终端上看到两段完整的驱动栈
  跟踪——比"你被挡住了"这种正常游戏反馈严重得多的失败模式。
- 对照：同一个文件里 `query_member_guild()`（`std/body/guilds.lpc`）
  对一个不存在的公会名已经优雅地返回 `0`（"不是成员"），说明
  `handle_blocks()` 本来的意图就是"公会不存在=当作没有这层关系"，
  只是它调用 `query_guild_allies()` 时漏做了同样的防御。
- 修复：给 `GUILD_D->query_guild_allies(guard_for)` 这次调用套一层
  `catch()`，出错时把 `allies` 当作空数组 `({})` 处理（等价于"这个
  公会没有盟友"），而不是让错误继续向上传播。不改变
  `guild_d.lpc`本身任何一个 `guild_check()`
  的行为（它对公会管理类接口——比如 `set_guild_title()`——保持严格报错
  仍然合理，那些接口本来就该假设调用者知道公会存在），只在这个
  "查询式、应该能对不存在的东西安全返回"的调用点做防御。
- 验证：`Aidan`（打赢过守卫）和全新角色 `Rowan`（完全没打过架，直接
  走）两条路径分别复测——修复前两者都在 `north` 时触发上述两段完整
  错误栈；修复后（真实重启驱动生效，LPC 改动无需重新编译 C++）两条
  路径都只剩一条**可控**的信息性日志（`[errors]` 频道仍会显示
  "Non-existant guild - sorcery."，因为 `mudlib error handler : 1`
  这套配置下即使 `catch()` 吞掉的错误也会记录/广播给订阅了 errors
  频道的账号，这是这套 mudlib 自己一贯的调试可见性设计，不是本次改动
  引入的噪音），玩家实际收到的是预期的游戏反馈："The a guard pushes
  you back. \"Guild members only\", she growls."——移动被正确拒绝，
  而不是崩溃。（旁注：这条拒绝消息本身有个"The" + "$n"→"a guard"
  重复冠词的措辞小瑕疵，`set_block_action("The $n $vpush $t
  back...")`——纯文案问题，不影响功能，按本项目"内容/设计不确定就不
  动"的原则只记录不修改。）
- **§9 格式化器**：按流程对这两个改动过的文件跑了一次 §9 LPC
  formatter，`guild_guard.lpc` 结果正常，但 `guild_d.lpc`
  触发了一个新的格式化器盲点——`class guild_defn { ... }`
  这种带内联注释的多字段 struct 体被错误地压扁成一整行后，格式化器的
  花括号配对状态发生错位，导致后面几十个完全无关的函数
  （`belongs_to`/`check_previous`/`guild_add`/… 一直到文件结尾）被
  级联误加了一层缩进（本身是纯空白改动，语法仍然合法，但 diff 膨胀到
  1700+ 行，完全掩盖了这次两行真实修复的意图，且没有信心排除格式化器
  在别处发生了真正的语义级损坏）。按 AGENTS.md §9 "遇到盲点用 `git
  checkout` 整个文件回滚，不要手工修补格式化器的输出"的既定处理方式，
  `git checkout` 回滚了两个文件的格式化结果，手工原样重新应用了上面
  两处最小 diff（未跑格式化器），保留这两个文件原有的缩进风格不变。
  这是这个格式化器的一个新盲点实例（多字段 `class` struct 体 +
  内联注释导致花括号跟踪状态错位），值得以后遇到 `class` 定义密集的
  文件时留意，但由于 Lima 是本语料库里唯一一个用这种框架的 lib，暂不
  在 AGENTS.md §9 补充通用条目。

**2. `daemons/guild_d.lpc` 的 `load_missions()`/`load_favors()`
两个函数在 `GUILD_D` 第一次被懒加载时必定崩溃，因为它们引用的两个
目录在这个仓库里根本不存在——修复 #1 直接触发并暴露了这个第二层
bug。**

- 上面 #1 的 `catch()` 第一次真正把 `GUILD_D` 加载进内存时（此前没有
  任何 preload 项引用过它），`GUILD_D::create()`
  （`daemons/guild_d.lpc:115`）依次调用
  `load_missions()`/`load_favors()`。`load_missions()` 用
  `get_dir(MISSION_DIR "*.lpc")`（`MISSION_DIR` =
  `/domains/common/mission/`）取文件名列表，但这个仓库压根没有
  `domains/common/` 这个目录——`get_dir()` 对一个不存在的目录返回的是
  `0`，不是空数组 `({})`，紧接着的 `foreach (string item in files)`
  直接报 `*Bad argument 2 to foreach Expected: array Got: 0.`，把整个
  `GUILD_D` 的 `create()` 炸掉（`load_favors()` 用
  `FAVOR_DIR`=`/domains/common/favor/`，同一目录也不存在，是完全相同
  的第二处实例）。这正是 AGENTS.md 里已经归档过的"`get_dir()`
  对不存在目录返回 `0` 而非空数组"经典坑（见 AGENTS.md 相关条目），
  这次是它在 Lima 自己的核心 daemon 代码（不是某个具体 domain 的示例
  内容）里的一个新实例，而不是需要单独立项的新 bug 类别，故未新增
  AGENTS.md 条目，仅在此交叉引用。
- 修复：`load_missions()`/`load_favors()` 各加一行
  `if (!files) files = ({});`，`get_dir()` 返回目录存在但为空时本来就
  已经是 `({})`，这个 guard 只处理目录整个不存在的那一种情况，行为上
  完全是"这两类内容还没人往这仓库里加"的空操作，不是猜测应该往里面
  放什么。
- 验证：修复后重启驱动，`GUILD_D`
  第一次被上面 #1 的调用路径懒加载时不再报 `Bad argument 2 to
  foreach`，`load_missions()`/`load_favors()` 静默返回，`GUILD_D`
  正常初始化并落盘一份全新的 `data/daemons/guild.o`（测试完成后已
  按惯例清理，不提交这份纯测试产物）。

### 测试覆盖：干净通过的部分

- **注册 + 建角**：`TestHero`（id/密码/性别/邮箱/真实姓名/推荐来源
  六项资料全走完，未提前用回车跳过任何一项）→ `c`
  建角选人类种族 → `Aidan`；账号存档确认落在
  `data/links/t/testhero.o`（不是`data/players/`——这个 mudlib
  的登录账号和角色身体是两套分开的存档体系，前者由
  `secure/user.lpc` 的 `save_me()` 写 `/data/links/`，后者由角色 body
  对象自己的 `save_me()` 写 `/data/players/`，两者都验证过存在且内容
  正确）。
- **移动/探索**：Grand Hall（`domains/std/Wizroom.lpc`）→ 通过 `enter
  portal`（不是方向指令，是一个 `set_objects()` 里挂的可交互物体）
  到 `domains/std/rooms/beach/Sandy_Beach`（原版自带的"pirate"主题
  演示解谜区，房间自身的告示牌明确写着"DON'T USE THIS AREA ON YOUR
  MUD!!! ... providing this area as an example only"——确认是有意的
  示例内容而非未完成的真实新手区，用 `wade in ocean` 这类挂在物体上
  的 `EXIT_OBJ` 方法而非方向指令才能继续深入，属于教学向导航技巧的
  演示，未强行走完整个九房间解谜，仅验证了它的存在/可达/告示牌文案
  与源码一致）；`goto`（巫师传送指令，`AUTO_WIZ`
  下人人可用）验证可用，用于在 Grand Hall/Monster Room
  间快速往返，不构成绕过测试的问题——纯粹是这个 lib 本来就把每个
  角色都当巫师对待的既定设计。
- **战斗**：`kill guard`（Monster Room 的 5-max-health 门禁守卫）——
  真实回合制近战，命中/闪避/擒摔/致残（"You cannot use your right arm
  anymore"）描述文本随机生成、伤害正确累加到躯干/四肢分区 HP、`skills`
  面板确认 Combat/Defense/Melee/Unarmed 技能百分比确实随着战斗行为
  自动增长（"熟能生巧"机制，符合 `cmds/player/skills.lpc`
  自己文档注释里的说明）。角色是巫师身份，重伤到"If you were mortal,
  you would now no longer be mortal"后自动免疫真死——符合 §10.7
  checklist 里"用 wizard 身份角色测试战斗更安全"的既定经验。
- **公会/门禁交互**：详见上面两处 bug 修复；修复后确认"没有对应公会
  成员身份时被礼貌拒绝，而不是崩溃"这一行为在两个独立角色
  （`Aidan`/`Rowan`）上一致。
- **NPC 对话**：`talk to greeter`——进入带编号选项的对话树（数字选
  Hello!/What do you do?/Where do I get LIMA?/...），驱动侧数字菜单
  分派正确。
- **`quests`**：正确列出"pirate"/"Pirate"两个可见任务及步骤数/状态
  （与 Sandy Beach 演示区的 `sand_with_treasure.lpc` 埋的
  `QUEST_D->grant_points()` 调用对应）。
- **`quit` → 用户菜单 → `q` 完全断开 → 真实等待 75 秒 → 重新连接**：
  `quit`游戏内指令正确回到用户菜单并广播"has left Lima Mud"；`q`
  从用户菜单彻底断开后 `ss -tn`
  确认端口上无残留连接（干净断开，非半开连接）；75 秒真实等待后
  用 `s`→`p` 重新进入游戏，角色状态（位置 Grand Hall、属性、之前战斗
  造成的创伤已自然恢复）全部正确保留，`log/runtime`
  行数在等待前后一致（无新增错误）。debug.log 在这次驱动的启动方式
  下本来就是死的（AGENTS.md §10.9 已归档的通用现象——`log directory :
  /log` 相对驱动启动时的 cwd 解析，chdir 前就 fopen
  失败，此后整个进程生命周期都不会再重试）；这个 lib 真正在用、也
  确实工作正常的错误日志是 `work/log/runtime`（配合 `errors`
  频道），本轮两处 bug 的完整驱动栈跟踪都是从这个文件里读到的确认
  证据，等待前后的行数比对也是拿它做的。
- **管理员账号**：`fluffos`/`Mud@2026` 重新登录验证，`who`
  显示`Role: Admin`，状态与此前"管理员账号播种"一节记录的验证结果
  一致，未发现回归。

### 已知但未修的观察项（不确定是否算 bug，按惯例只记录不改）

- `guild_guard.lpc` 的默认拒绝文案 `"The $n $vpush $t back..."` 对
  `set_name("guard")` 这类没有专有名词、走"a guard"泛指格式的对象会
  拼出"The a guard pushes you back"这种双重冠词——纯粹的英语措辞小
  瑕疵，不影响任何功能判定，本次未改动。
- Sandy Beach 的九房间"pirate"演示解谜区本身明确标注"不要在你的
  mud 上使用"，本轮只验证了可达性/告示牌文案/`wade in
  ocean`这一个非方向性出口的存在，未强行走完整个解谜链（含
  `dig`挖出宝箱的完整 8 次交互序列）——按 §10.7 checklist
  第 6 条的原则，明确记录为"内容探索深度不足"而非"已知损坏"。

## Upstream PR 审计（2026-08-31，standing queue 项目）

按 `project_fluffos_org_upstream_pr_queue.md` 的标准流程，把上文"编译
期发现的真实 bug"一节里已经在本地 `work/` 修好的 6 处 bug 逐一核对
是否需要（也能否）提交回上游：

- **bug #1（`cache_dir()` 等 4 处 `[0..<3]` 扩展名切片宽度）**：不提交
  上游——这是本项目自己 `.c`→`.lpc` 改名触发的问题，上游原生文件名
  仍是两字节的 `.c`，`[0..<3]` 在上游代码里本来就是对的。纯粹的
  driver-build/转换集成问题，不是 lima 自己源码的 bug。
- **bug #2（`set_droppable(int g)` 应为 `mixed g`）**、
  **bug #3（`eval_dest()` `private`→`protected`）**、
  **bug #6（`confirm_decision()` 的 `dec = "y"` 赋值/比较符打错）**：
  三处都是 lima 自己源码里独立于任何编译期开关的真实逻辑 bug（和
  `NO_LIGHT`/`NO_ADD_ACTION`/`NO_WIZARDS`/`OLD_ED`/`PACKAGE_UIDS`
  这套本 lib 专属驱动 flag 完全无关，任何启用静态类型检查/严格
  `private`语义的驱动都会踩到）——判定为上游真正应该修的 mudlib
  bug。核对 `github.com/fluffos/lima`（HEAD 仍是快照记录的
  `dbcef2a`，无新提交/PR/issue 涉及这三处）确认未被上游独立修复后，
  fork+clone 到 scratch 目录、对照上游原始 `.c` 文件逐字节确认 bug
  存在，准备提交 PR 时发现 **`fluffos/lima` 已于 2024-10-08 被官方
  归档为只读仓库**（`gh pr create` 直接报 "Repository was archived so
  is read-only"，无法开 PR）——`meta.json`/本文件开头记录的
  "2026-08-24 克隆 HEAD dbcef2a" 只是 clone 时未受影响（归档仓库仍可
  clone，只是不能收 PR/新 commit）。
  - 核实同一 LIMA 社区已迁移到 `github.com/limalib/lima`（非
    `fluffos/lima` 的 GitHub fork 关系，但同一 Discord `#LIMA` 频道、
    同一品牌"limamudlib.dev"，且本文件前面"附录（2026-08-26）"一节
    已经做过一次代码血缘对比，确认是同一 LIMA 代码库的延续版本，非
    独立重写）——直接 clone 核对，`std/modules/m_gettable.c`/
    `std/modules/m_exit.c`/`obj/usermenu/usermenu.c`
    三个文件对应位置的三处 bug **逐字节存在，尚未修复**（master/
    stable 两个分支都确认过），且该仓库尚无任何提及这三处的
    open/closed PR。判定为这三处 fluffos-org 遗留 bug 的实际可提交
    对象，改为向 `limalib/lima` 提交：
    [PR #49](https://github.com/limalib/lima/pull/49)（`set_droppable`）、
    [PR #50](https://github.com/limalib/lima/pull/50)（`eval_dest`
    private→protected）、
    [PR #51](https://github.com/limalib/lima/pull/51)（`confirm_decision`
    赋值/比较符）。
- **bug #4（`ENSURE(x /* 注释 */)` 宏参数内联注释）**、
  **bug #5（heredoc 开始标记同行接正文）**：均已在原文标注为
  `fluffos/fluffos`**驱动**本身的 bug，不是 `fluffos/lima`/
  `limalib/lima` 的 mudlib 源码 bug——本次任务范围是审计 lima 这个
  mudlib 是否需要提 PR，不包括驱动仓库层面的 PR，未提交。
- 交叉核对 `libs/spacemud`（`limalib/spacemud`，明确基于 LIMA 代码库
  "as few changes to Lima itself as possible"）与 `libs/wilderness`
  （独立的 2000 年代 LIMA 快照）各自的 `NOTES.md`：wilderness 独立
  发现了完全相同的 `eval_dest` private/protected 问题（`private
  protected` 双修饰符写法，同一文件同一函数）和 `set_droppable`
  同类"声明类型比函数体/文档窄"问题（另外还多发现了
  `set_destination`/`set_fluid_level`/`m_complex_exit.lpc`
  的 `set_method`/`add_method` 等 4 处同类型 bug），以及完全相同的
  `ENSURE` 宏注释驱动 bug——回头检查这 4 处 wilderness 独有的额外
  实例在本 lib 当前 `work/` 目录里对应文件的声明**均已经是正确的宽
  类型**（`set_destination(mixed f)`、`set_fluid_level(int x, int y)`、
  `m_complex_exit.lpc` 的 `exit_messages`/`enter_messages` 已经是
  `mixed *`），说明这 4 处是 wilderness 那个独立 2000 年代快照自己的
  历史遗留内容分支，并非 stock `fluffos/lima`/`limalib/lima` 现存的
  bug，不需要额外提交。spacemud 的 `NOTES.md` 未提及这三处 bug（其
  onboarding 没有触发到这几个调用路径），无新增交叉发现。
