
## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 sjecl 同一个 Century/adm-single 血统（adm/single/master.lpc + adm/daemons/securityd.lpc）——大部分 bug 相同，用了相同的修法：（1）§7.60 master.lpc log_error()/standard_trace()→CHANNEL_D 编译期崩溃，两处都用 find_object(CHANNEL_D) 守卫。（2）§7.59 securityd.lpc 的 valid_read() 无条件用 this_player() 覆盖，拒绝了 load_object/include 触发的读取，已把这两种情形排除在覆盖之外。（3）§8.1 没减半的 GBK 字节区间 is_chinese() 加上对应没减半的 check_legal_name() 长度界限（原为 4/8 加 i%2 字节窗口→改成逐码点的 2/4）。（4）§7.50 is_killing(who) 物件/字符串不匹配，出现在和 sjecl 相同的 5 个 NPC 对话档案里（少了 sjecl 里少林那份，这份快照没有）。这份档案独有的新发现：adm/daemons/backupd.lpc 用了未定义的 BACKUP_DIR 常量（会被预载，导致开机失败）——已在 globals.h 里加上 #define BACKUP_DIR "/backup/"（硬盘上已经有一个 /backup 目录，确认了原意）。另外：adm/daemons/sited.lpc 的 is_valid() 比 sjecl 的规则更严格/相反——任何非巫师身份的 id 从 127.0.0.1/localhost 连线一律无条件拒绝（只有 wiz_level(id) 为真的账号才能用回环地址），所以 WASM 测试（永远是 127.0.0.1）只能注册巫师身份的 id——已改用先播种 wizlist 再直接以 fluffos 身份注册（一次性验证管理员和注册流程）来绕过，而不是当作需要修的问题（这是这条血统真实的安全策略选择，不是 bug）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这里不需要像 sjecl 那样再加第二条 sited 表条目，因为 127.0.0.1 规则本来就给巫师身份账号开放了完整的回环访问权限）。已验证：完整注册→进入游戏世界，权限正确显示 (admin)。记录了一处不阻断、未修的内容 bug：adm/daemons/questd.lpc 的 spread_quest()/init_dynamic_quest() 在预载的动态任务放置阶段对一个为 0 的物件呼叫 environment()（被捕获，不阻断开机）。LPC 格式化工具对全部 8527 个档案运行；还原了 1 个通过"去空格后比对旧档案"扫描（覆盖 85 个格式化工具触碰过的档案）确认有 CJK 重新加空格损坏的档案（d/quanzhen/hudi5.lpc）；直接逐一比对了两个 ASCII 地图档案（d/shaolin 下两份）——干净，只是排版调整。格式化后重新验证过，干净。

## 深度功能测试（§10.7，2026-08-05）

这份档案和刚深挖过的手足档案 `sjecl` 同一血统，先检查了 `sjecl` 自
己的 §10.7 记录（§8.3b 指令表死档、§7.86 留言板 `post` 崩溃、
§7.5 file_size ACL 误判等），逐项核实：

- **§8.3b 不适用**：`sjecl` 的 `commandd.lpc` 有一个转档没跟上的
  `sscanf(...,"%s.c$",...)`（永远匹配不到 `.lpc` 后缀）；这份档案
  的 `commandd.lpc`（以及一份从未被引用的死代码分身
  `adm/commandd.lpc`）从一开始就正确写成 `"%s.lpc"`，指令表健康，
  `look`/`score` 等全部指令都正常。
- **§7.86 适用，而且发现了一个更隐蔽的变体**：全档案 38 处
  `inherit BULLETIN_BOARD` + 多余 `replace_program(BULLETIN_BOARD)`
  致命形状，已删除 37 处静态留言板文件里的多余调用。**第 38
  处不是静态文件，而是 `cmds/king/set_board.lpc`——一个供帮派帮主
  在自己领地里"花一千两黄金建一块留言板"的指令**，它的实现方式是
  在运行时用字符串拼接生成一份全新的 `.lpc` 源码（`write_file()`
  写到磁盘上），拼接出来的模板里同样嵌了一份"先 `inherit
  BULLETIN_BOARD` 又多余 `replace_program`"的写法——也就是说，这
  个 bug 不只存在于已经存档的静态留言板里，而是被写进了"生成新留
  言板"的工厂函数本身，任何帮派以后用这个指令新建的留言板都会天生
  自带这个 `post` 必崩的 bug。已从模板字符串里删掉多余的
  `replace_program` 那一行，保留 `inherit`。这次深挖没有实际测试
  帮派建板流程（需要先加入帮派、攒够一千两黄金），但已经用代码走
  读确认修改后生成的模板语法完整（大括号配对正确）。已更新
  AGENTS.md §7.86，补充"运行时代码生成模板也可能嵌有这个 bug，不
  要只 grep 静态 .lpc 文件"这条提醒。
- **§7.5/§8.9 均不适用**：`securd`/`securityd` 的 ACL 已经在
  WASM 阶段修好（排除了 load_object/include），这次没有再撞上
  file_size 误判；`enter_world()` 的食物/饮水初始化同样是无条件的
  固定值，没有年龄判断包装。
- **战斗/死亡/复活测试**：新角色被"武馆四弟子 孙均"拦在武馆大门
  口（"江湖险恶，你还是在武馆学点东西再出去吧"——需要馆主批准才能
  "离馆"，是有意的新手教程设计，不是 bug），用管理员的 `goto` 指
  令直接跳到城里测试。先在武馆里和"沈城"打了一场安全的切磋（无生
  命危险，礼貌收场），再在北大街和"少林刀僧 行者"打了一场真实的死
  斗，逃跑被拦截，力竭阵亡。这份档案的死亡系统和 `sjecl` 完全不
  同——不是"鬼门关→孟婆亭→孟婆汤"，而是"鬼门关→阎罗大殿→黑白无常/
  秦广王审判"，判定守卫是标准的 `if (!ob || !present(ob))
  return;`（AGENTS.md §7.68，现已收窄到仅 `bmxkx2001` 适用），全
  程未受打扰、未做任何改动，五阶段对话正常播放完毕，正确送回"武馆
  前院"复活，`score` 确认死亡计数 +1。
- 留言板 `post` 已 live 验证：在武馆前院的"襄阳武馆留言板"发帖成
  功，"留言完毕"。
- **本次没有测试**：帮派建板流程（原因见上）、门派拜师、商店。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,004 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug。
本档案就是 §7.100 条目本身引用的"`sje`-precedent"（bug 长在工厂
里，不只是出货内容里）：不只 `clone/misc/roommaker.lpc` 一份房间
建造工具，帮派管理指令集 `cmds/minister/*.lpc`（`accept`、`ally`、
`resign`、`banish`、`declare`、`linkroom`、`mkroom`（2 处）、
`addnpc`（2 处）、`add_action`、`add_desc`、`set_long`、
`set_short`）、`cmds/king/build_bank.lpc`（2 处）、`cmds/adm/
ra.lpc` 也全部把这个 bug 烤进了各自的房间字符串拼接模板里——一共
14 个文件、18 处字符串拼接变体。用 `fix_710_room.py` 扫过
`work/`，删除 1,976 处标准形状；`work/data/group/groom/` 下 10 个
真实 `.lpc` 房间源文件（帮派废墟场景，`inherit ROOM;` 独立标准形
状，被脚本默认的 `data/` 排除规则跳过）另外单独用同一脚本对该子
目录扫过，删除 10 处；上述 18 处字符串拼接变体用一个小 Python 脚
本（二进制模式，逐文件计数校验）批量替换成
`str += "\n\tsetup();\n}\n";`。1976+10+18=2004，与survey记录的
存活总数完全吻合；`git diff --stat` 显示 1998 个文件净删 2004
行、增 18 行，同样吻合。`work/data/group/npc`、`work/data/group/
obj` 下确认没有真实命中。

驱动干净启动（零新增编译错误、端口 40146 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。本档案此前从未被真实注
册过（只有 wizlist 里的 `fluffos (admin)` 条目，没有存档）——用完
整注册流程（UTF-8 编码：BIG5 询问答 N、id、密码 `Mud2026A`、中文
名"秦风"、天赋 0 随机+接受、邮箱、性别 m）创建，落地"门廊"，
`look`/`score`/`quit` 均正常，全程 `debug.log` 保持干净。新建的
管理员存档（`data/{login,user}/f/fluffos.o`）已提交，补全此前
NOTES.md 记录过、但从未真正落地的管理员播种。驱动按精确 PID 结
束。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/yanluo.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.
