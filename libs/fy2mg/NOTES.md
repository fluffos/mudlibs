
## WASM 修复摘要（迁移自 meta.json 的 group_note）

adm/obj/master.lpc 和 jyqxc（086）/jyqxc2（087）/jyqxc2013fwq（088）/xkx2017（112）逐字节相同——同一个"金庸群侠传"/XKX 框架家族，游戏内容不同，按本项目对这个家族已有的惯例单独编号；启动干净，零修复。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc 的 make_body() 里 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了 i%2==0 门槛；给 securityd.lpc 的 get_status() 加上了防御。注册流程里有两步是本次会话其它血统档案里没见过的：密码复杂度要求（必须同时包含大小写字母和特殊符号，不只是长度下限），以及性别之后、进入游戏前的民族选择（0-3）——需要照实读取 input_to() 调用链，不能假设它和 jym/hy 系那种更短的流程一样。管理员账号通过纯文本的 adm/etc/wizlist 播种。注册流程到进入游戏世界、look/score/quit、管理员权限识别都已干净验证。

## 深度功能测试（§10.7，2026-08-04）

原生 driver（端口 40198）跑了一遍超出注册流程的完整游玩，先读了
`doc/help/newbie`（风云系《新手指南》，和 `fy330` 的版本几乎同源但不
完全相同）作为测试路线图——这一版明确给出了一份从弱到强排序的安全
陪练对象列表（"无知小童，教书先生，落第书生，乞丐，收破烂的，醉汉，
农夫．．．"），本轮据此思路（虽然这几个具体名字在这份档案自己的地图
里大多没被实际放置，是家族共享的文档模板，不是这份档案专属的内容）
挑选了地图上实际存在、战力由弱到强的几个 NPC 做陪练。

**主动检查命中 2 处，都在 `adm/daemons/logind.lpc` 里**（AGENTS.md
§7.34）：随机姓名分支和手动输入姓名分支各有一处紧挨在
`ob->set("name", ...)` 之前的 `printf("%O\n", ob)` 调试残留，和
`fy330`（同一 XKX 框架家族的姊妹档案）逐字节相同，已一并删除。
`command_hook` 是干净的 `nomask`，没有 MESSAGE_D-> 未防护调用、
stat/water 键名不一致、或 §8.9 食物/饮水按错误对象 age 初始化的问题。

**注册与地图探索**：注册测试角色（秦北 / id `qinbei`），落在"凤求凰
客栈"。`i`/`hp`/`score` 输出格式和数值范围与新手指南的范例基本一致。
探索了风云城的主要街道——南风大街（注意同名但内容不同的两个"南风
大街"房间前后相邻，靠东西方向区分，不是 bug，只是两段街道恰好同
名）、风云广场、西云大路、天主教堂（`no_fight`，"这里不准战斗。"，
符合宗教场所设定）、风云衙门、玉龙珠宝店等，移动和出口全部正常。

**商店测试**：玉龙珠宝店的 `list` 正确显示商品和黄金标价（玉指/玉
簪/玉花/玉镯），vendor 链路工作正常。

**战斗测试（三个不同强度的目标）**：
- 凤求凰客栈的"店小二"（combat_exp 5，`attitude` friendly）——用
  `kill` 绕开 friendly 的 fight-拒绝判定（和 `bixiecanyang`/`fy330`
  发现的技巧一致），双方命中率都很低，气血从 250 缓慢降到 137 后主
  动移动脱离战斗，气血随即回升——确认战斗判定和脱离机制正常。
- 考场的"考生"（combat_exp 50000，friendly）——发现但受时间限制未
  实际交手。
- 风云衙门的"风云衙役"（combat_exp random(500000)，`attitude`
  heroism）——连续三次 `kill`，每次都在气血逼近临界值时触发角色自
  身的自动逃跑（"看来该找机会逃跑了..."），但这个对手会主动跟到玩
  家撤离的房间（"风云衙役走了过来。"）——和 `fy330`/`bixiecanyang`
  遇到的"逃跑必定安全"不同，这里首次观察到追击行为，气血/气血上限
  一度降到 4/29（11%），角色进入"半昏迷"重伤状态但最终还是在下一次
  自动逃跑里脱险，全程没有真正死亡。气血上限随着伤势加重而持续下
  降（250→163→29）是这条血统的负伤机制，不是数值错乱。

**死亡/复活系统：发现并修复 §7.68 的又一实例（未做到现场完整复
现）**：虽然被追杀到气血 11% 也没有真正死亡，但主动读了死亡系统代
码，`d/death/npc/{wgargoyle,bgargoyle}.lpc`（白无常/黑无常）和
`bixiecanyang`/`fy330` 的死亡系统同宗（`revive_loc`/`death_msg` 文
本逐字节相同），`death_stage()` 都有同样的 `if (!ob || !present(ob))
return;` 复活软锁死守卫（AGENTS.md §7.68 第四例）。已按已验证过的
修法拆分：`!ob` 仍然永久放弃，`!present(ob)` 改为 5 秒后重试同一阶
段。两个文件的改动逻辑与 `bixiecanyang` 完全对应——`wgargoyle.lpc`
是纯粹的多阶段复活序列，`bgargoyle.lpc` 在复活序列之前还多一段"活
人闯入阴间就攻击"的判断，两处guard 都属于同一个多阶段流程的一部
分，都需要修。

**诚实记录**：本轮三场战斗测试都没能把角色真正打死（自动逃跑机制
即使在被追击、气血跌到 11% 的极端情况下依然生效），所以
`wgargoyle.lpc`/`bgargoyle.lpc` 的修复是照抄已经在 `bixiecanyang`/
`fy330` 现场验证过的修法应用的，不是本轮独立复现死亡→鬼门关→复活
全流程后现场验证的。这个自动逃跑安全网在两个不同的姊妹档案
（`fy330`、本档案）里都表现得相当可靠，值得作为这整个 ES2 大家族的
一个共性记录下来。

`quit` 正常退出（丢下一件不值钱的布衣，"欢迎下次再来！"），
formatter 检查（三个改动文件均已是干净格式，无需重排版）、
`git status --short libs/fy2mg/` 复查均确认改动范围干净——只有
`logind.lpc`/`wgargoyle.lpc`/`bgargoyle.lpc` 三处源码修改是跟踪变
更，测试角色的新存档保持未跟踪、未提交。`debug.log` 全程没有真实
的 `error:`/`denied`/`Bad argument`/`Too deep recursion` 行。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 7 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fqyy2` 同一原始形状）**：
   `if (this_player(1)) efun::write("编译时段错误：" + message +
   "\n");`——不区分巫师/玩家，也不区分警告/错误，无条件把所有编译诊断
   转发给当前连线的任何人。真实复现：全新驱动进程下首次注册
   `fluffos` 管理员账号触发的冷编译级联（`/std/char` 及其十余个
   `feature/*.lpc` inherit 链首次编译），修复前屏幕上连续刷出二十多
   行原始 "Warning: Unused local variable"/"Unknown #pragma" 诊断。
   修复：加上 `strsrch(message, "arning:") == -1` 判断，只有真正的错
   误才转发。已用同一新驱动进程下的完整重新注册复测：零次诊断刷屏。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例，与 `fqyy2` 同一形
   状）**：`LOG_DIR` 下的 `nosave/` 子目录在全新检出里不存在，
   `suicide`/崩溃日志/`purge`/巫师晋升等管理指令路径的
   `log_file("nosave/...", ...)` 调用会在首次使用时未捕获抛出。注册
   /登录本身只写顶层文件（`USAGE`/`ATTEMPT_LOGIN`，无子目录，本来就
   存在），不受影响，但这是一个明确存在的 bug，按标准模式补上
   `assure_file(LOG_DIR + file);`（含前向声明）。
3. **管理员账号从未真正创建（AGENTS.md §1.5 的"wizlist 有记录但角色
   从未真正建立"形状，与本次会话开头几个档案的 commit 记录同一
   模式）**：`adm/etc/wizlist` 里早就有 `fluffos (admin)` 这一行，
   但 `wizlist` 只决定权限等级，不会凭空创建这个 id 的角色本身——用
   README 记录的密码尝试登录时，系统把它当成一个**从未注册过的全新
   id**（提示"这个名字将会创造一个新的人物"），而不是要求密码，证
   实此前从未有人真正走完注册流程。已用真实注册流程完整创建
   `fluffos` 角色（密码沿用 README 已记录的 `Mud@2026x`，本代码线密
   码复杂度要求最严格，需同时含大小写字母+特殊符号），`score` 确认
   显示"目前权限：(admin)"，`update /adm/daemons/securityd` 确认可
   正常重新编译（验证的是真正的写权限，不只是"看起来是 admin"）。
   README 已同步更正这段记录。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`u/wind/refereew.lpc:176`
  `(string)(to_int(query("win_times")) % 5)`；姊妹文件
  `u/wind/refereew2.lpc:184` 同样已修（`% 3`）。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 实测过程

`fluffos` 管理员账号完整注册（英文 id → 确认建立 → 中文名，直接设定
不需要二次确认 → 密码 → 确认密码 → 邮箱 → 性别 → 民族选择 0-3，此前
未在 README 的注册流程摘要之外单独强调过这一步是新号注册流程的最后
一环）进入"凤求凰客栈"起始区域。修复前后各做一次全新驱动进程下的完
整注册；修复前复现了上述诊断刷屏，修复后干净。`log/debug.log`
全程时间戳未变化，确认无新增未捕获运行期错误。中途一度因为清理测试
存档时用错了路径（这份档案的 `query_save_file()` 比大多数档案多嵌套
一层：`/data/user/f/fluffos/fluffos.o`，不是常见的
`/data/user/f/fluffos.o`）而误以为存档失败，重新确认路径后排除是自
己的操作失误，非真实 bug。驱动最终按精确 PID kill，`ps -p` 确认已
退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos/
  fluffos.o`，注意这份档案的嵌套路径）。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`：删除 525 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），524 处脚本自动
删除；另 1 处在本库房间建造工具 `obj/roommaker.lpc`"克隆我所在的
房间"命令的字符串拼接模板里，与手足档案 `fy2`/`fy2qh` 同一形状，
已同步手动修正。`work/data` 下未找到额外 `.lpc` 源文件（与
`fy2`/`fy2qh` 不同，本库这里没有该变体）。修复后全库仅剩 3 处历史
遗留的 `//`-注释掉实例，均确认无害、未改动。已用 `build-debug` 驱
动干净启动验证（0 个新增编译错误，端口 40198 正常监听，
`debug.log` 无新增 "cannot replace"/"cannot bind" 行）；未做完整
§10.7 深度游玩测试。

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
