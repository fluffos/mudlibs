
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/金庸血统 mudlib（Annihilator/书剑衍生），游戏内标题为"江湖2005/江湖2006"（书剑主题）。修复的 bug：（1）adm/daemons/securityd.lpc 的 valid_read() 里经典的 §7.59 this_player() 顶替 root 身份 bug——开机时立刻就会崩溃报"*Read access denied."，出现在 logind.lpc 的 gb_big5() 第一次惰性编译 BAN_D->is_banned() 的时候，英文名字提示根本还没出现；已仿照既有模式，把 func=="load_object"/"include" 排除在 this_player() 覆盖之外来修复；（2）adm/daemons/logind.lpc 里经典的 §8.1 GBK 字节区间 is_chinese() bug 加上 check_legal_name() 字节数没减半的长度界限（4/8 字符，i%2 门槛→2/4 字符）；（3）adm/daemons/commandd.lpc 的 rehash() 里经典的 §8.3b 死指令表 sscanf——"%s.c$" 在改名成 .lpc 之后再也匹配不到任何东西，导致整个指令表变成空的；look/quit 碰巧还能用（是靠别处的 add_action 定义或者驱动内建），但包括查看状态用的指令（stscore，不是 score——这份档案不用"score"这个词）在内的其它所有指令都会落到"什么？"，直到修好为止。管理员账号（fluffos/Mud2026Pass）通过真实注册流程 + adm/etc/wizlist 播种，游戏内"您目前的权限：(admin)"显示确认生效（自动带到巫师休息室）。完整的注册→look→stscore→quit 流程在排版格式化前后各验证过一次，用的是真实中文名字——注意这份档案的注册顺序是 id→y/N 确认→密码→确认密码→中文名字→天赋数值→性别，不是其它档案更常见的 id→确认→中文名字→密码那种顺序。

## §10.7 深度功能测试（本次新增）

此前只做过注册→look→stscore→quit 的浅层验证。本次用管理员 `fluffos`
和一个全新普通角色 `tester` 实际走通了注册→look/i/stscore→武馆内移
动→沙袋练功的流程，并在源码层面逐一核对了 AGENTS.md 里已知的 bug
类别。

### 修复：d/death/gate.lpc 的 §7.68 复活软锁

`run(object ob)` 原代码 `if (!ob || !present(ob)) return;` 把"鬼魂对
象已经不存在了"和"鬼魂此刻只是暂时不在这个房间里"混为一谈，一旦判
定瞬间鬼魂碰巧不在场就永久放弃后续引导（送去 `gateway`/`mpting`/
`pusadian`），把鬼魂永久卡在鬼门关。按标准修法拆开：`!ob` 才是真正
放弃，`!present` 改为 1 秒后重试。已用管理员 `update` 指令热编译验
证无编译错误；受限于本次时间和城门 NPC（见下）没能实际找到活的怪物
触发真实死亡，未做端到端的活体复活验证——但这个修法和本项目里已经
反复验证过几十次的同一形状完全一致，可信度很高。

### 检查、确认不适用的已知 bug 类别

- §8.9 食物/饮水年龄检查错对象：本档案的 `stscore` 面板根本没有食
  物/饮水这两项资源，`logind.lpc` 里也搜不到 `ob->query("age")` 这
  种模式，不适用。
- §7.5 securd.lpc 的 file_size ACL 误拒（AGENTS.md 新增变体，上次
  在 hy2002 发现）：`adm/daemons/securityd.lpc` 的 `valid_read()`
  已经显式 `switch(func) { case "file_size": case "stat": return 1;
  }`，本来就放行，不适用。
- §7.78 CHARACTER 的 F_* 混入档缺 F_DBASE inherit：`inherit/char/
  char.lpc` 是和 shujian3/hy2002 完全相同形状的 ES2 结构（同一个
  `feature/dbase.lpc`），这两个同宗档案都已经用真实战斗测试排除过
  这个 bug（裸 set/query 实际写入了真正的 dbase），本次时间关系未
  重复验证，留给未来针对这份档案或其手足 `sjplgfjxb`/`sjplii` 的
  后续 pass。

### 一个不是 bug 的测试方法论坑：连线后不主动打印任何东西 + tmux 中文乱码

`logind.lpc` 的 `logon()` 只 `input_to("gb_big5", ob)` 注册回调，自
己不 `write()` 任何东西——欢迎横幅和"您的英文名字"提示都是在
`gb_big5()`**回调**里才打印的，也就是说这份档案要求连线后先随便送一
行（哪怕是空行）触发第一次回调，才会看到任何东西。用裸 socket 或
`tmux_mud.sh` 的 `read`（不先 `send`）会一直卡着直到驱动自己的 30
秒 `time_check()` 超时断线（"您花在连线进入手续的时间太久了"），一
度以为是驱动挂死，实际上只是没有先送空行。另外：本档案的出口键是
"方向-地点全名"这种复合字符串（如"西-小石路"，不是单独的"西"或
"west"）——用 `tmux_mud.sh` 送这类中文复合字符串偶尔会被 `tmux
send-keys -l` 弄乱（已知限制，见 memory），改用 `mudclient.py` 直连
后确认输入完全正常、移动指令本身没有问题。

### 未能完成的部分（诚实记录，非"未发现"）

新角色离开武馆的正常门槛是 `combat_exp >= 3000` 且完成馆内的拜别仪
式（`d/wuguan/menlang.lpc` 的 `valid_leave()`），本次时间关系没有练
到这个门槛；改用管理员账号 `goto` 到武馆大门外（`/d/xiangyang/
damen`）试图找一个可以安全测试战斗/死亡的目标，但该房间 `objects`
里唯一挂载的 `npc/menwei`（武馆门卫）在两次不同别名尝试下都返回"这
里没有这个人"——没有确认是编译失败还是别的原因，未深入排查。因此本
次没有做成活体的战斗/死亡/复活验证，`gate.lpc` 的修复只做到编译层
面确认，记录在案供未来 pass 补做。
