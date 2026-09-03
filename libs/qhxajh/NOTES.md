
## 深度功能测试（第二轮，2026-08-03）

之前的会话只测过注册流程，本轮做了完整的 §10.7 深度功能测试。
proactive 检查 AGENTS.md 已归档的四类常见坏味道，均未命中（logind.lpc
路径是 `system/daemon/logind.lpc`，不是通常的 `adm/daemons/`）。

**发现并修复的两个真实 bug，都是同一类此前已归档的转档乱码问题
（AGENTS.md §4.1"iconv -c 吃掉相邻真实字节"）的新表现形式——已扩
充该条目：**

1. **`clone/misc/void.lpc`（"天涯海角"死亡/传送用房间，玩家实际会
   走进去）编译失败**：`update` 时报 `End of file in text block`。
   核对原始压缩包字节确认：闭合用的 `LONG` 标签本来单独占一行，转
   码时丢了紧挨在它前面的换行符，和文字内容粘在一起变成一整行——
   解析器因此永远找不到真正的闭合标签，一路读到文件结尾报错。已
   对照原始字节在正确位置插回缺失的换行符。这个房间恰好是"南阳北
   门"往南走某几步会真正路过的地方，`/d/nanyang/npc/man` 这个大
   汉 NPC 的 `create()` 因为触发了这个坏掉的房间加载链条而报错，
   导致这个 NPC 从来没有真正生成过。
2. **`system/skill/basic/kongshou.lpc`（空手/徒手格斗，全游戏几乎
   每一场战斗的基础技能）编译失败，但只有真正打起来才会触发**：
   同一类字节丢失，但这次是把一行中文注释和紧跟着的函数声明粘在
   了一起——`// ...这种天生的技能与其他后天学习的技能int
   is_native_skill()\n{`——`int is_native_skill()` 这段声明整个被
   吞进了 `//` 注释里（`//` 注释延伸到行尾），实际留下的只是一个
   没有函数签名、光秃秃的 `{`，报 `syntax error, unexpected '{'`。
   因为这个技能物件是遇到战斗才惰性编译，不在开机预加载范围内，
   之前几轮的"能开机、能注册"验证完全没有触碰到它——直到本轮实际
   打了一架，每一个回合都反复报
   `*No program in object '/system/skill/basic/kongshou'!`，刷屏
   刷得很明显。已对照原始字节插回缺失的换行符，重启后同一场战斗
   完整走完，双方攻防叙述、招架提示全部正常渲染，报错完全消失。

修复过程中顺带核实了一处**真实存在、判断为不阻断、未修复**的内容
缺失：`man.lpc`（南阳北门附近的"大汉"NPC）和 `waiter.lpc` 的
`create()` 分别用 `BLADE_DIR`/`CLOTH_DIR` 给自己装备兵器和衣服，
但这两个宏最终展开的 `/clone/weapon/`、`/clone/wear/` 整个子树在
这份档案里根本不存在（`clone/` 下只有 `user/`、`money/`、
`misc/`、`wizard/` 四个目录）——全库搜索这四个宏只有 3 处引用
（含 `system/std/room/road.lpc` 里一处通用逻辑），范围很小，报错
都已经被各自房间的 `setup()`/`reset()` 包装 `catch()` 接住，不会
让房间整体加载失败或让玩家看到任何报错——按项目一贯做法保持原样，
没有去凭空发明替代的武器/衣物内容。

顺带把管理员账号 `fluffos`/`Mud@2026` 通过正常注册流程真正注册并
存盘了——`secure/etc/wizlist` 里虽然已经列了 `fluffos (admin)`，
但检查发现从未有对应的存档文件被真正提交过（`data/user/f/
fluffos.o` 等此前一直是未跟踪状态），本轮登录验证"目前权限：
(admin)"显示正确后已 `git add` 这两个存档文件。

**完整流程验证**：注册全新角色（沐清华/id `qhdive`），从"南阳北
门"到"大街"（柯府门前）一路探索，`hp` 显示精神/生命/体能/食物/饮
水槽均满值；以管理员身份 `goto` 到"厨房"，和"厨娘"（`kill chu
niang`）打了一场完整的徒手格斗，修复 kongshou.lpc 前后各打一次对
照验证；`quit` 干净退出。除上述两个已修复的转档乱码 bug 外，
`log/catch`（运行时错误追踪）和 `log/room_log`（房间创建失败记
录）全程无其它报错。

**未覆盖范围**：门派拜师、任务系统、留言板因时间原因未实测。

## 深度功能测试补测：门派拜师、任务系统、留言板（2026-08-24）

补测上一轮标记为"未覆盖"的三项。

**内容缺口（已核实为真实存在、非阻断，未修复，与本档案已记载的
man.lpc/waiter.lpc `BLADE_DIR`/`CLOTH_DIR` 缺失同类）**：这份"清华笑
傲江湖"档案目前的整个游戏世界只有南阳一座城（`d/nanyang`，58 个房
间/物件档），从未包含任何真正的"掌门"NPC 档案。`dating.lpc`（大厅）
的门禁逻辑提到"过彦之""戴子奇"两个伏牛派弟子会拦人，`quest/funiu/
quest0.lpc` 等任务数据档里"过彦之"也是任务发布者——但全档案（包括
`raw/xo/lib` 原始转档）从未包含这两个 NPC 的任何档案。核对同源码库
的姐妹档案 `xajhxo`（同一 XO/TMI-2/ES2/Falcon 家族）确认：那边"过
彦之"等掌门 NPC 各自都实现了自己的 `attempt_apprentice()`（决定是
否收徒的对话/条件判定），而 `system/std/char/master.lpc`（含
`give_quest()`）这个"掌门"混入类是设计给具体掌门 NPC 主动 `inherit`
+ 手动 `add_action("give_quest","quest")` 用的——本档案里没有任何
NPC 这样做，`create_family()` 全档案只有自己的定义、从未被任何地方
调用过。也就是说门派拜师和任务系统在这份档案里都卡在同一个根因：
掌门 NPC 内容本身缺失，不是代码逻辑的锅。

用现有的管理员 `call`（`call <物件>-><函数>(<参数>)`，档案自带的合
法工具）临时给"樊子发"（南阳商号老板 `d/nanyang/npc/boss.lpc`）挂
上 `create_family("伏牛派",1,"掌门")`，跑通了 recruit→apprentice 的
真实代码路径：`score` 正确显示"你已拜在伏牛派门下，是伏牛派的第二
代弟子。你的师父是樊子发。"——机制本身没问题。任务系统同理，临时
（测试完已改回）给 boss.lpc 加一行 `inherit
"/system/std/char/master";` + `add_action("give_quest","quest")` +
`create_family(...)`，验证 `give_quest()`/`quest` 指令端到端正常
（接到"杀何三"任务、显示剩余时间、无崩溃）；任务文字里提到的"过彦
之"是任务数据本身的角色名，与本次测试用的替身 NPC 无关，纯粹是测
试环境产生的错位，不代表档案本身有问题。

**发现并修复的四个真实 bug（都在这三项范围内，都有明确的错误信
号，不是内容/设计问题）：**

1. **留言板 `funiu_b`（`d/nanyang/obj/funiu_b.lpc`）的 `location`
   写成 `/d/city/nanyang/xiangf1`，但这份档案的房间树根本没有
   `city/` 这一层（真实路径是 `/d/nanyang/xiangf1`）**——`move()`
   找不到目标房间直接静默失败，留言板永远飘在空间里，玩家在任何房
   间都看不到它。已改成 `/d/nanyang/xiangf1`。
2. **`xiangf1.lpc`（厢房，留言板所在房间）自己的 `create()` 里用
   `call_other(__DIR__ "funiu_b", "???")` 来强制预载留言板，但
   `funiu_b.lpc` 实际存在于 `obj/` 子目录下**——真实驱动跑起来会在
   `create()` 里报 `*call_other() couldn't find object
   '/d/nanyang/funiu_b'.`，而且这个未捕获错误发生在房间对象自己的
   编译期初始化中，直接导致 `go north` 从"前院"进厢房失败（玩家卡
   在原地），留言板房间整个不可达——比 bug 1 更严重，`lpcc --batch`
   批量编译检查也测不出来（对照本项目已记载的"lpcc-vs-live-driver
   artifact"套路：批量模式下只显示`Fail to load object`，没有具体
   错误文本，必须用真实驱动开机复现才能看到完整 trace）。已改成
   `call_other(__DIR__ "obj/funiu_b", "???")`；核对姐妹档案
   `xajhxo` 里完全相同的 `xiangf1.lpc` 确认原本就是 `obj/funiu_b`
   写法，本档案是转档时丢了这一段路径。
3. **`system/std/bboard.lpc`/`jboard.lpc` 的 `setup()` 覆盖了父类
   `ITEM`（`system/std/item.lpc`）的 `setup()`，但没有链式调用
   `::setup()`，导致父类里的 `seteuid(getuid())` 从未执行**——直
   接后果：留言板对象永远没有 euid，`post` 指令流程里的
   `save_object()` 每次都因为
   `securityd.lpc:valid_write()`权限判定失败而报
   `*Denied write permission in save_object()`（trace 写入
   `/log/runtime`），当前会话内 `post`/`read` 表面正常（数据只在
   内存里），但驱动一重启所有留言就会全部丢失。已在两个文件的
   `setup()` 开头补回 `seteuid(getuid());`，与 `system/std/
   room.lpc`（同样是非 clone 的 `/d/` 常驻对象，也显式调用了同一
   行）保持一致的既有约定。
4. **即便留言板有了 euid，`save_object()` 仍然失败**：这份档案
   `/d/` 目录下的对象（含留言板）编译期 uid 由
   `secure/simul_efun/object.lpc` 的 `creator_file()` 统一赋成字面
   量 `"Domain"`，不是 `ROOT_UID`；而 `securityd.lpc` 的
   `trusted_write` 白名单里完全没有覆盖 `data/board` 这个子目录（也
   不允许非 clone 对象凭 `"Domain"` euid 写 `/data/`），于是留言板
   即使正确设了 euid 也过不了 `valid_write()`。已仿照同一映射里已
   有的 `"quest"`/`"system/skill"` 这类按目录+euid 精确授权的写
   法，新增 `"data/board": ({ "Domain" })` 一条。修复后重启驱动、
   重新 `post`，`data/board/funiu_b.o` 正确落盘（无 `Denied write
   permission` 报错），`log/catch`、`log/runtime` 全程无新增报错。
5. **`cmds/verb/apprentice.lpc` 的"对方已经在等你收徒
   （`pending/recruit`）"分支里，判断是否"背叛师门"时直接比较
   `me->query("family/family_name") != ob->query("family/
   family_name")`，没有先判断 `me` 是否真的已经有门派**——第一次拜
   师（`me` 从未加入过任何门派）时 `me->query("family/family_name")`
   返回 `0`，和目标门派名字符串必然不相等，于是被误判成"决定背叛师
   门，改投入……门下！！"，实测复现（全新角色第一次拜伏牛派显示
   "背叛"提词）。对照姐妹指令 `recruit.lpc` 里同样的逻辑分支，那边
   正确地先用 `(ob->query("family")) &&` 做了守卫。已给
   `apprentice.lpc` 补上同样的 `mapp(me->query("family")) &&` 守
   卫；修复后重新用全新角色测试，正确显示"你决定拜樊子发为师。"。

以上 5 处修复均已用 `lpcc_check.sh` 全库编译检查（407/413 通过，
和修复前的已知失败集合一致，无新增回归）+ 真实 `build-debug/src/
driver` 开机验证（`log/catch`、`log/room_log`、`log/runtime` 全程
除已记载的 man.lpc/waiter.lpc 缺失装备目录外无其它报错）。§9 格式
化工具对本次改动的 7 个文件跑过，`wouldChange=0`（已符合既有格
式，无需改动）。测试用管理员临时挂在 boss.lpc 上的 `inherit
master`/`create_family`/`add_action("give_quest",...)` 三行测试脚
手架已在验证完毕后原样改回（`git diff` 确认改动前后字节相同）；
测试角色 `qhtestox` 的存档、测试用留言板留言均已清理。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 019（xo）、019-1（xo_final）同一个 XO/TMI-2/ES2/Falcon 代码库家族，任务/游戏内容不同。WASM 修复：（1）经典的 §8.1 GBK 字节区间 is_chinese()。（2）logind.lpc 的 check_legal_name() 长度界限没减半（(< 4)||(> 10)，对应字节数时代的写法，应为 (< 2)||(> 5) 以匹配它自己"2-5 个汉字"的提示）。（3）一处闭包形式的 input_to((: get_id :), ob) 在这个驱动下静默永远不会触发，已改成和同一档案里其它所有呼叫点一样的字符串形式 input_to("get_id", ob)。（4）§7.52 socket 精灵：从 secure/etc/preload 里移除了 /secure/daemon/ftpd（未定义的 socket efun，100+ 处呼叫点，没有非 socket 的外部呼叫者，太大不适合逐一掏空）。（5）§7.1 master.lpc 的 valid_read()/valid_write() 自举死锁——已记载的"崩溃成堆栈溢出"形态在这里不适用（这个构建的驱动把 load_object() 失败降级成一个被捕获的"Object cannot be loaded during compilation"而不是真的崩溃），所以这个 bug 表现成了一种静默的变体：securityd.lpc 自己的 create() 通过 read_file() 读取 wizlist 从未真正完成过，因为 securityd.lpc 自己永远无法编译完成（编译器需要读取自己的源码/#include/继承档案时的每一次嵌套读取都会递归回 valid_read()，每次都在还在编译中的状态下再次尝试 load_object(SECURITY_D)）——于是 wiz_status 永远是空的，包括 wizlist 文件里已有的账号在内，所有 id 都被判定成 (player)。previous_object()==securityd 这种特判方式对这个变体无效：在这些由编译触发的嵌套读取里，previous_object() 报告的永远是 master 自己，从来不是 securityd。已用标准的 §7.1 重入旗标修复（已作为 §7.1 新记录的一种症状补充进 AGENTS.md，因为原来的写法只覆盖了崩溃这一种形态）。（6）缺失的 libs/qhxajh/work/log/nosave 目录（§7.11，被 gitignore，未跟踪）导致 log_login() 的 log_file() 呼叫崩溃，静默破坏每一次注册的 get_gender()。另外把 config.fluffos 里的"maximum evaluation cost"从 700000 调高到 5000000000（原来极小的上限把预载拆成约 150 次各自被打断的恢复，耗时约 100 秒；这本身不是 bug，只是慢）。完整的注册（id→确认→中文名字→管理密码→确认→电子邮件→性别）→进入游戏→look→score→quit 修复后和格式化后都验证正常，管理员 id"fluffos"正确显示 (admin)。§9 格式化工具的三类盲点检查都干净（被标记的 CJK 间距字符串是转档之前就有的原作者内容，没有被这次 diff 改动）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). No live room-file
occurrences — both instances were inside this lib's own room-building
tool, `clone/wizard/roommaker.lpc`: a standalone line in its heredoc
"make an empty room" template, and a string-builder line in its
"save room" code-generator (tab-indented variant). Both fixed. A full
post-fix grep confirms 0 live occurrences remain. Verified via a clean
native driver boot (zero new `debug.log` errors, port listening, killed
by exact PID after ~8s).

## 深度功能测试第三轮 / Deep functional test round three (2026-09-03)

新角度：挤号重连（§7.108）、`log/nosave` 缺失时的 wiz 登录
（§7.11）、迷你档装备路径（§7.73，同 `xo` 本轮形态）、留言板/
小店买卖、以及 reconnect 路径上对缺失 `UPDATE_D` 的调用。

### Bug 1（§7.108）：`clone/user/user.lpc::reconnect()` 缺
`enable_commands()`

本档案不在当年 162-lib §7.108 扫过名单的生效结果里（或当时漏网）。
`reconnect()` 只恢复了 `set_heart_beat(1)`，没有 `enable_commands()`。
现场：第二次连线答 y 挤掉旧连线后，提示「重新连线返回」但所有指令
一律回「什麼？」——与 `xo` 已修形态一致。已补上 `enable_commands()`；
挤号重连后 `look`/`score`/`quit` 立即正常。

### Bug 2（§7.11）：`log_file()` 不 `assure_file()`，`log/nosave/`
一缺就炸 wiz 登录/重连

`secure/simul_efun/file.lpc` 的 `log_file()` 直接 `write_file(LOG_DIR
+ file)`，没有兄弟档 `xo` 已有的 `assure_file()`。`log/nosave/` 被
gitignore，环境里一不存在，`log_login()`→`log_file("nosave/wiz_usage")`
就抛 `Wrong permissions for opening file /log/nosave/wiz_usage`，在
`get_passwd`/`confirm_relogin` 里炸掉——表现成登录后有 `>` 却任何指令
都「什麼？」（enter_world 路径被截断）。已加前向声明 + `assure_file`
；删掉 `log/nosave` 后重测，目录被自动建出，runtime 干净。

### Bug 3：`UPDATE_D`（`/system/daemon/updated`）整档缺失，
reconnect 必炸

`logind.lpc::reconnect()` 末尾 `UPDATE_D->check_user(user)`，但
`system/daemon/updated.lpc` 在本档案里根本不存在（`xo`/`xajhxo` 同
家族有）。每次挤号重连都在 runtime 留下
`*call_other() couldn't find object '/system/daemon/updated'`。从
`xo` 拷入同家族的 `updated.lpc`（含 force 上限钳制）；重测 reconnect
后 runtime 为空。

### Bug 4（§7.73）：`man.lpc`/`waiter.lpc` 无防护的全局装备宏

上一轮 NOTES 已记录「`BLADE_DIR`/`CLOTH_DIR` 整树不存在、被 room
`catch` 吞掉、未修」。本轮按 `xo` 迷你档先例正式修：

- `man.lpc`：`cloth2` 改指向本地 `__DIR__ "obj/cloth2"`（档案里有）；
  `blade` 无本地副本，保留宏但加守卫。
- `waiter.lpc`：`cloth6` 全局/本地皆无，仅加守卫；顺手修好战斗喊话
  字符串里把 `\n` 转码成 PUA+`n` 的损坏（`！n"` → `！”\n"`；
  `xajhxo` 同文件仍带同一损坏，未在本轮改兄弟档）。

`goto` 大街/小店后大汉与马老二正常出现，`list ma`/`buy 大碗清茶`
成交；catch 无 `call_other(0)`。

### 本轮其它验证（无新 bug）

- §7.111 `trace_line` 已有 `obj ? file_name : "<none>"`
- 留言板 `post`/`read`（先前 §10.7 补测修过的 funiu_b / seteuid）正常
- 管理员 `fluffos`/`Mud@2026` 登录→look/score→挤号重连→quit

### 本轮修改的文件

- `work/clone/user/user.lpc`
- `work/d/nanyang/npc/man.lpc`
- `work/d/nanyang/npc/waiter.lpc`
- `work/secure/simul_efun/file.lpc`
- `work/system/daemon/updated.lpc`（新增，来自 xo）
