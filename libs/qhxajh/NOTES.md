
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
