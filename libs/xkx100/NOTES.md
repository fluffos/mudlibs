
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行一百（Coollizard & xkx100，2003-2004，yoyo.xm.fj.cn/xkx100）。和另一个独立完成的 GitHub fluffos/xkx100 仓库不同（不同代码库，无关）。WASM 修复了 6 个各自独立的编译/运行时 bug：（1）§7.48 类的"private"函式被继承档案呼叫：feature/treemap.lpc 的 _set()/_query()/_delete() 声明为 private，但继承了 F_TREEMAP 的 feature/dbase.lpc 直接呼叫它们——已改成 protected，和 AGENTS.md 记载的模式完全对应。（2）同样的 §7.48 模式又独立出现在 feature/action.lpc 的 continue_action() 和 feature/attack.lpc 的 attack() 里，都被 /inherit/char/char.lpc 呼叫——也改成了 protected。（3）feature/team.lpc 的 follow_path() 里 §7.47 类的 origin()==ORIGIN_X 整数位掩码比较（这个驱动的 origin() 回传字符串）——已改成按文档记载的映射 origin()=="local"/"internal"。（4）adm/daemons/logind.lpc 里一个真正的缺失档案健壮性 bug：howmany_visitor()/howmany_card() 对 read_file() 的结果做 sscanf() 前没有先检查它是不是字符串——log/MUDVISITOR 在这份档案里真的完全不存在（连 raw/ 里都确认没有），所以一次真正全新的安装第一次连线就会撞上（英文名字提示还没出现之前），sscanf(0, ...) 的类型不匹配错误会在 logon() 执行过程中被驱动静默吞掉，连线卡死，没有任何错误文字也没有提示——已加上 stringp(content) 判断，文件不存在时回传 0，匹配这份档案自己代码明显预期（num 默认为 0）但没有安全实现的情形。（5）adm/daemons/combatd.lpc 里一处错误的 #include 路径：'#include </quest/quest.h>'（绝对路径写法）在这个驱动的 include 目录搜索规则下解析不了；这份代码库里其它所有需要同样的 quest_finished()/quest_failed()/lock_quest() 辅助函式的档案都已经用 '#include <quest.h>'（解析到 /include/quest.h，一份几乎相同的更新副本）——已把 combatd.lpc 改成一致写法。（6）修好（5）之后连锁出现的"Illegal to inherit after defining global variables"：quest.h 声明了一个全局 quest_name 映射，落在了 combatd.lpc 的 'inherit F_DBASE;' 之前——已把 #include 挪到 inherit 语句之后（最安全的位置，因为 #include 是纯文本替换，只需要满足"先 inherit 后全局变量"这条排序规则）。adm/simul_efun/chinese.lpc 里 §8.1 类的 is_chinese() 本来就是正确的逐码点检查；只有 check_legal_name() 自己独立的 i%2 门槛和按字节数算的长度界限（4-10，本意是 2-5 个字符）需要同样的标准修复（逐字符呼叫 is_chinese(name[i..i])，长度界限改成 2-5）。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（已有多个 (admin)/(arch)/(wizard) 账号；SECURITY_D 正确指向 /adm/daemons/securityd）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→密码+确认→出生地选择（1-5）→属性点数分配（3 项明确输入，第 4 项自动算出剩余）→y 接受→性格特质菜单（0 为不设定）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 'score'/'look' 指令进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"，fluffos 出现在最高的 (admin) 阶层里。LPC 格式化工具对全部 14255 个档案运行（写入 14237 个，2 个报错，16 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 8 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## 深度功能测试（§10.7，本轮）：核对并确认这份档案同样带着 jqxz2008/xkx2017 家族的大部分 bug

这份档案自己此前只做过 WASM 修复级别的注册流程验证，没有玩到移动/
战斗/死亡这些更深内容。这次先核对了最近几轮在 `jqxz2008` 系列和同
属"MudOS v21 世系"的 `xkx2017` 上依次确认的 5 个 bug，逐一核对后：

**命中的（已修复）：**
1. `adm/daemons/logind.lpc`（§8.9）：`ob->query("age") == 14` 检查
   了错误的对象（应该是 `user`），每个新角色的食物/饮水从创建起就
   永远是空的。改成 `user->query("age") == 14`。
2. `adm/daemons/combatd.lpc`/`cmds/std/kill.lpc`（§7.11）：
   `/log/nosave/` 目录不存在，`combatd.lpc` 的 `killer_reward()`
   （每次死亡都会跑到）对着这个不存在的目录裸调 `write_file()`。加
   了 `assure_file()`。

**没有命中的（核对后确认不需要修）：**
3. `chinesed.lpc` 的 `create()` 虽然也是未加保护的 `restore()`，但
   这份档案里 `data/e2c_dict.o` 这个档案根本不存在（不是"存在但损
   坏"，是压根没有）——`restore_object()` 对着一个不存在的档案只是
   正常返回失败，不会抛出异常，所以 `create()` 能正常走完，`dict`
   保留着自己声明时的 `([])` 初始值。用真实驱动实测（打死一次角色，
   战斗/死亡讯息大量用到中文格式化）确认全程没有任何相关报错，没
   有修改这个档案。
4. `bai.lpc`/`apprentice.lpc` 里判断"是否从风清扬门下叛出"的逻辑，
   这份档案是完全不同的、写法正确的独立实现（用
   `present("feng qingyang", room)` 而不是共享计数档案），没有那处
   括号位置错误。

**这次额外发现了本档案独有的 4 处 §7.68 死亡/复活软锁**：
`d/death/npc/{mengpo,bgargoyle,wgargoyle,chacha}.lpc`——其中孟婆
（`mengpo.lpc`）的函式名不叫 `death_stage()` 而是 `tea_give()`（喂
孟婆汤的多阶段对话），但是同样的 bug 形状：`if (!ob || !present(ob))
return;` 把"角色永久离开"和"暂时不在场"混在一起，没有重试路径。全部
按各文件自己原有的重试间隔（`mengpo`/`chacha` 3 秒，`bgargoyle`/
`wgargoyle` 5 秒）拆分成"暂时不在场则重试"。

用真实驱动完整验证了两次全新注册（走完出生地选择→膂力/悟性/根骨/
身法分点→性格选择→email→性别的完整流程，比 `xkx2017`/`jqxz2008` 系
列多两个步骤），`score` 正确显示食物/饮水两条状态全满、属性数值和
输入一致；用测试角色（小九）在南阳城实际攻击 NPC"小贩"，角色被打
死，干净地触发"你死了"→"鬼门关"死亡场景→NPC"白无常"打招呼——
`debug.log` 全程保持空白，确认 `combatd.lpc` 的修复生效。

### 未继续测试的部分

时间关系，没有测试拜师、购物、留言板。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 70 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。这份档案的注册流程比大多数同类档案多两
步（出生地选择、天赋点数手动分配 80 点预算），完整走了一遍：id →
y → 中文名 → 密码 ×2 → 出生地(1) → 膂力/悟性/根骨各输入 20（身法
自动算出 20）→ 接受 y → 性格(0) → email → 性别(m)。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`，实际生效的 master file）
   完全没有严重度检查（AGENTS.md §7.34-class）**：`if
   (this_player(1))` 无条件回显。已加上 `strsrch(message, "arning:")
   == -1` 判断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
3. **`inherit/char/char.lpc` 第 111 行 `heart_beat()` 里
   `environment()->is_chat_room()` 没有先判断 `environment()`
   是否为空，`call_other()` 拿到 int(0) 直接崩溃**：live 测试注册流
   程进入"北京"区域时，`clone/quest/questyinshi#4`（"江湖豪客"）连
   续多个心跳周期反复抛出 `*Bad argument 1 to EFUN call_other()
   Expected: object... Got: int(0).`——该 NPC 在这一刻没有
   `environment()`（不在任何房间容器里）。这份档案自己在
   `feature/command.lpc:46` 已经有 `environment() && ...` 的标准写
   法，说明这是本代码库自己认可的惯用防护模式，只是这一处漏加。已
   改成 `if (!environment() || !environment()->is_chat_room() ||
   ...)`。修复后同样流程的完整会话（含约 90 秒纯 idle 观察期）里
   debug.log 里这个错误没有再出现过。
4. **冷启动 eval-cost 耗尽（AGENTS.md §7.90/§10.8-class）**：注册流
   程首次进入"北京"区域时大量档案第一次编译，`maximum evaluation
   cost`（默认 700000）在注册会话期间连续触发了近 20 次 `Eval
   interrupted`/`Too long evaluation`——比典型的"仅冷启动一次"更严
   重，属于这份档案自己文件规模较大触发的更严重实例。按已确认的补
   救方式把 `config.fluffos` 的这个值从 700000 提到 5000000（本项
   目另有 30+ 档案在用这个值）。修复后重新走一遍同样的注册+同一区
   域访问流程，debug.log 里零 `Eval interrupted`/`Too long
   evaluation`。

### Proactive checks（无需改动）

- `win_times` 的 `%`-operator 修复确认存在且正确：
  `d/city/npc/jinyong.lpc:197`、`d/beijing/npc/refereew.lpc:177`、
  `d/city/npc/gulong.lpc:246` 均已用 `to_int(query("win_times")) %
  5`；`d/huashan/npc/referee.lpc`/`.old` 不涉及 `%`，不适用。
- `feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。

### 实测过程

`adm/etc/wizlist` 里的 `fluffos (admin)` 一直没有对应存档（此前只
做过 WASM 阶段的结构性核实）。本轮通过完整注册流程创建（含出生地/
天赋点数分配这两步本档案独有的额外流程），落地"北京"客店，`score`
显示"目前权限：(admin)"，食物/饮水满格。随后**单独一步**做了真实
断线重连+密码验证：用刚设的密码重新连线成功登录，存档数据一致。全
程（含 90 秒 idle 观察期）`debug.log` 干净，无运行时错误。驱动按精
确 PID 结束；管理员存档（`data/{login,user}/f/fluffos.o`，此前从
未真正注册过）已提交。
