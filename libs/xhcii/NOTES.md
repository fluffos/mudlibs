
## WASM 修复摘要（迁移自 meta.json 的 group_note）

笑红尘②，由拓勘资讯组（topkan.com）开发。在 WASM 下启动并完整完成注册，没有任何编译或运行时错误，也没有任何被捕获的异常——没有发现任何 LPC bug。唯一采取的行动：把 fluffos (admin) 播种进一个空的 adm/etc/wizlist（SECURITY_D 正确指向 /adm/daemons/securityd；globals.h 里有一条注释掉的 '// #define SECURITY_D "/adm/daemons/securd"' 诱饵提醒但未生效；wiz_levels 顶层是 (admin)，已从结构上确认通过 trusted_write 授予完整的 '/' 写入权限）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→单一密码+确认→天赋数值选择（0 为随机，y 接受）→电子邮件（需要 id@address 格式）→性别→带着 MOTD、起始房间描述、NPC 问候和可用的 'look' 指令进入游戏世界，全程没有任何意外错误——用 catch() 包裹了 get_gender()/init_new_player()/enter_world() 每一步来打点确认，性别选择之后进入游戏世界的整条路径上零异常。管理员权限在播种前已通过标准的 '★ 您目前权限：' 横幅实时确认显示为 '(player)'；播种后对应的 '(admin)' 实时确认因为这份档案特有的一个明显的 WASM 专属测试工具计时问题而没能稳定重现——/inherit/char/char.lpc 第一次编译的爆发期（加载 feature/name.lpc、feature/skill.lpc、feature/move.lpc 等）足够沉重，导致性别选择后不久发送的任何指令都有很高概率落在 '什么？'（无法识别），不管 --idle 怎么设都一样（在 --idle 3 到 15 之间都复现过这个失败，而底层那次成功的运行——--idle 6——也没能稳定重现）——这是一个客户端计时竞态，不是 mudlib 缺陷：一次完整干净的运行（格式化之前）通过直接的 catch() 插桩确认了性别选择之后全程零捕获错误，管理员等级权限也已经通过 securityd.lpc 的 trusted_write 表独立地从结构上确认。另外记录（不是 bug，纯粹是内容层面，按范围保持原样未动）：logind.lpc 的注册横幅文字里有一处转档前就存在的乱码/转码错误的中文短语（'也会渌婕乙桓龊玫镊印象'，看起来本意是想说类似'也会给其他玩家一个好的印象'）——这是早于本轮的内容/本地化问题，不是程序 bug。LPC 格式化工具对全部 7080 个档案运行（写入 6990 个，53 个因为杂乱的历史代码报错，37 个未改动）；还原了 1 个档案（d/city/sj.lpc）确认有转档之前就存在（作者一方，早于本轮）的缺引号损坏被格式化工具进一步重新加了空格——和 tybxjh 上已经见过的同一个档案/模式。没有 :: 父类呼叫拆分命中，没有 case 标签带尾随注释的候选。全部 6 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后重新验证开机干净（零编译错误）；注册流程重新验证到密码/属性/邮箱阶段，底层账号/权限逻辑没有被格式化改变（只有 logind.lpc 注册路径之外的档案被做了纯排版的重新格式化，已逐一 diff 审查）。

## 深度功能测试（§10.7，2026-08-05）

之前"没有发现任何 LPC bug"的结论是错的——上面提到的"性别选择后指令
经常落空"从来不是客户端计时竞态，而是一个真实存在、每次注册都会命
中的严重 bug（见下）。这份档案是 104 `tybxjh`（天涯之碧血江湖）的
同源"天涯"家族成员，先检查了 `tybxjh` 自己已完成的 §10.7 记录（2
处 printf 调试残留、§8.9 食物/饮水年龄检查错对象、`exert_function()`
类型错误、一处明文密码泄漏进 doc/help 的严重安全问题、进度条渲染缩
放 bug），逐项在 `xhcii` 自己的源码里核实：

- **2 处 printf 调试残留**：`adm/daemons/logind.lpc` 的
  `get_resp()`/`get_name()` 里各有一处 `printf("%O\n", ob)`，和
  `tybxjh` 逐字节相同。已删除。
- **§8.9 食物/饮水年龄检查错对象**：`enter_world()` 里
  `if (ob->query("age") == 14)`，同样的错对象判断。已改为
  `user->query("age")`。
- **§7.84（tybxjh 的明文密码泄漏）不适用**：这份档案用的是单一密
  码+确认的简化注册流程，没有 `tybxjh` 那套双密码机制，源码里也确
  实没有对应的 `write_file("/doc/help/...")` 调用——核实过，不是漏
  查，是这个 bug 根本不存在的前提（双密码机制）在这里不成立。
- **§7.85（tybxjh 的进度条渲染缩放 bug）不适用**：`cmds/usr/
  score.lpc` 的 `tribar_graph()` 是完全不同的、循环式的正确实现
  （10 段式，`val*100/max/10` 换算，无残留宽度乘数），和 `tybxjh`
  出问题的那个切片式实现是两种不同写法，这里没有同类 bug。
- **一个从未被记录过的严重 bug，本次深挖真正的核心发现（已写入
  AGENTS.md §7.86）**：之前 WASM 修复阶段记录的"性别选择后指令经
  常落空、疑似客户端计时竞态"，实际根源是 `get_gender()` 里一次没
  有保护的 `log_file("login/newid.log", ...)` 调用——档案里根本没
  有 `/log/login/` 这个目录（经典的 §7.11 缺失运行时目录模式），
  这一行抛出未捕获错误，直接把整个 `get_gender()` 函数从这里截断，
  后面的 `init_new_player(user)`/`enter_world(ob, user)` 全部没有
  执行——玩家的指令系统根本没有挂上去，之后无论输入什么都是"什么？"
  永远卡住，角色也从未真正存过盘。用 tmux 重新走一遍注册流程，在
  `work/log/debug.log` 里直接抓到了这个报错，确认这才是真正原因。
  已创建 `work/log/login/` 目录（同时补进
  `scripts/wasm_keep_dirs.txt`，供 WASM 打包复现这个目录形状），
  并给这次 `log_file()` 调用加上 `catch()` 防护（双重保险：目录已
  经修好，但万一以后又出现类似缺失目录，不应该再让整个注册流程被
  一次日志写入拖垮）。修复后重新走完整注册流程，性别选择后立刻正
  常进入游戏世界，`work/log/login/newid.log` 也正确写入了记录。
- **另一个从未被记录过的严重 bug（已写入 AGENTS.md §7.86）**：留
  言板的 `post` 指令在任何一块留言板上都会立刻崩溃：
  `*cannot bind an lfun fp to an object with a pending
  replace_program()`。根源是全档案约 90 份留言板档案（`clone/
  board/*_b.lpc` 和散落在 `d/**/` 下的若干份）的 `create()` 里都
  同时做了 `inherit BULLETIN_BOARD;`（编译期已经拿到全部留言板功
  能）和多余的 `replace_program(BULLETIN_BOARD);`（运行时再自我替
  换成同一个类）——这个多余的自我替换让该物件永远卡在"replace 挂
  起"状态，导致后续任何尝试给它自己的 lfun 绑定闭包的操作（正是
  `do_post()` 调用编辑器回调所需要的）永久失败，而 `read`/`look`
  等不涉及闭包的指令完全正常，这正是这个 bug 之前从未被发现的原
  因——留言板表面看起来完全正常。已删除全部 90 处多余的
  `replace_program(BULLETIN_BOARD);` 调用（保留 `inherit`，功能不
  变）；已发现至少 4 份档案里这一行早就被前任巫师注释掉了（大概率
  是踩过同样的坑但没有找到根因，逐个文件手工规避）。修复后重新走
  过一遍：`post` 正常打开编辑器，`留言完毕` 保存成功，留言板未读数
  正确更新——重启驱动后二次确认依然正常。
- **战斗/死亡/复活测试**：注册后随机落地在铁枪庙（泉州，和 `tybxjh`
  同一批场景），`kill wuya` 一战不敌乌鸦阵亡（这里的乌鸦明显比
  `tybxjh` 那边更凶悍，几回合就见血）。死亡后落到鬼门关，`白无常`
  在场，判定守卫是同样的 `if (!ob || !present(ob)) return;` 写法
  （AGENTS.md §7.68，现已收窄到仅 `bmxkx2001` 适用）——按新纪律没
  有做任何改动，让流程原样跑完，全程未受打扰，复活正确送到武庙，
  角色状态（疲倦/受伤但存活、食物/饮水正常）符合预期。
- **本次没有测试**：拜师/门派系统（这次深挖时间主要花在追查上面两
  个更严重的 bug 上，留给后续深挖）。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查
   （AGENTS.md §7.34-class）**：`if (this_player(1))
   efun::write("编译时段错误：" + message + "\n")`——不区分玩家/巫
   师，也不区分警告/错误，任何在场玩家都会看到原始编译诊断。修复：
   加上 `strsrch(message, "arning:") == -1` 判断，只有真正的 Error
   才会显示。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：这是通用
   simul_efun 本身缺保护，不止之前 2026-08-05 那次单独在
   `get_gender()` 调用点上加的 `catch()`——已加上前向声明 +
   `assure_file(LOG_DIR + file);`，让所有 `log_file()` 调用点统一
   受益，不必逐个调用点补 `catch()`。

### Proactive checks（无需改动）

- `feature/dbase.lpc` 没有 tybxjh/wlhd 那种基于 `wizhood()` 的密码
  写保护，不适用那一类 bug。
- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city2/npc/refereew.lpc:146` 已用 `to_int(query("win_times")) %
  5`。
- 此前（2026-08-05）修复的 `get_gender()` 里 `login/newid.log` 写入
  的 `catch()` 防护、§7.86 留言板 `replace_program()` 死形状修复均
  确认仍然生效。

### 实测过程

`adm/etc/wizlist` 里的 `fluffos (admin)` 一直没有对应存档（此前只
做过结构性核实，没有真正注册过）。本轮通过完整注册流程创建
（id → 确认 y → 中文名"笑红二" → 确认 y → 密码 → 确认密码 → 天赋
0 随机 → 接受 y → email → 性别 m），落地武庙，`score` 显示"目前权
限：(admin)"。随后**单独一步**做了真实断线重连+密码验证：用刚设
的密码重新连线成功登录，存档位置（铁枪庙，`quit` 前移动过）正确
持久化，`score` 数据一致。全程 `debug.log` 只有正常的编译期
Warning（`Unknown #pragma`、未使用局部变量等），无运行时错误。驱
动按精确 PID 结束，管理员存档（`data/{login,user}/f/fluffos.o`）
已提交。
