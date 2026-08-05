
## WASM 修复摘要（迁移自 meta.json 的 group_note）

侠客行（"The Story of Hero"），MudOS v21 世系——和 110 号 xkx100、111 号 xkx2000zxb 是同一个核心代码库家族（从共享的 combatd.lpc/quest.h 结构就能看出）。WASM 修复：（1）和 xkx2000zxb 上已经见过的完全相同的错误 #include bug：adm/daemons/combatd.lpc 的 '#include </quest/quest.h>'（绝对路径写法）在这个驱动的 include 目录规则下解析不了——已改成 '#include <quest.h>' 并挪到 'inherit F_DBASE;' 之后以满足随之而来的"全局变量在 inherit 之前"排序规则（完全相同的修法，因为这是两份独立的压缩包，所以各自独立打的补丁）。（2）一处真正由损坏的留言板存档导致的下游后果：inherit/misc/bboard.lpc 的 setup() 未加保护地呼叫了 restore()；那份特定损坏的存档（clone/board/kedian_b 的）在解析过程中抛出"Illegal file format"，而由于 restore() 是 setup() 里的最后一条语句，这个异常（只被调用链更外层一个很远的 catch() 捕获）在呼叫者（kedian_b.lpc 的 create()）剩下的 set()/replace_program() 语句能执行之前就中止了执行，导致这个留言板的名字/短称状态处于损坏状态——之后每次在那个房间 look 都会崩溃报"Bad argument 1 to capitalize(), Got: 0"，出在 feature/name.lpc 的 short() 里。已给 bboard.lpc 的 restore() 呼叫包一层 catch()（这是一个共享的继承，所以能保护整个 mudlib 里的每一个留言板分身，不只是 kedian_b 那一个）——那一个特定损坏留言板的旧留言内容已经无法挽回，但房间/留言板物件本身现在能干净地初始化了。没有发现 is_chinese()/check_legal_name() bug——"小浮侠"（三个字）第一次尝试就通过了，不需要修。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（这份档案的 securityd.lpc 真的会在开机时读取 WIZLIST，不像 xkx2000zxb 那种基于存档档案的机制——已通过源码确认，而不是假设文本档案方式能用；也没有 xkx2000zxb 那种 valid_wiz_login() 站点锁定闸门）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→密码+确认→接受天赋赠礼（y）→电子邮件（id@address 格式）→性别→带着完整角色属性表和可用的 score/look 指令（包括之前会崩溃的留言板房间）进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 'wizlist' 指令输出确认"目前权限：(admin)"。LPC 格式化工具对全部 3268 个档案运行（写入 3239 个，29 个因为杂乱的历史代码报错，0 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 3 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## 深度功能测试（§10.7，本轮）：确认这份档案也带着 jqxz2008 家族那一整套 bug（虽然不是同一份代码库）

这份档案的 group_note 自己已经指出和 `xkx100`/`xkx2000zxb` 同属"MudOS v21"/ES II 世系，但没提过和 `jqxz2008` 系列（金庸群侠传）有关系——不过这次深挖发现两者的 `adm/daemons/{chinesed,combatd,logind}.lpc`、`cmds/std/kill.lpc`、`cmds/skill/{bai,apprentice}.lpc` 这几个关键档案结构高度相似，最近几轮在 `jqxz2008`/`jqxz2008dlx`/`jqxz2008std` 上依次确认的 5 个 bug，在这里逐一核对后**全部命中**：(1) `chinesed.lpc` 的 `create()` 对损坏的 `data/e2c_dict.o` 做未加保护的 `restore()`，会崩溃第一次真正用到 `chinese()`/`to_chinese()` 的地方；(2) `/log/nosave/` 目录不存在，`combatd.lpc` 的 `killer_reward()`（每次死亡都会跑到）、`kill.lpc`、`bai.lpc`/`apprentice.lpc` 对着这个不存在的目录裸调 `write_file()`，会让 `die()` 中途崩溃并在心跳里死循环重现；(3) `bai.lpc`/`apprentice.lpc` 里判断是否从风清扬门下叛出的分支有括号位置错误，`==` 比较被夹进了 `query()` 的参数列表，分支永远不会触发。全部按已经验证过的相同修法处理（`catch(restore())` + `mapp()` 守卫、四处 `write_file()` 前加 `assure_file()`、括号挪到 `query()` 外面比较返回值）。

**这次还额外发现了第 4 类，本档案独有：`adm/daemons/logind.lpc` 的 §8.9 食物/饮水初始化检查错了对象**——`if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`，`age` 是角色（`user`）的属性不是登录物件（`ob`）的，这个分支永远不会触发，新角色的食物/饮水从创建起就永远是空的。改成 `user->query("age") == 14`。

**以及 3 处 §7.68 死亡/复活软锁**：`d/death/npc/{wgargoyle,newgargoyle,bgargoyle}.lpc` 的 `death_stage()` 都有 `if (!ob || !present(ob)) return;` 这种把"角色永久离开"和"暂时不在场"混在一起的写法，已按各文件自己的重试间隔（均为 5 秒）拆分成"暂时不在场则重试"。

用真实驱动完整验证了两次全新注册（小四、小五），`score` 正确显示食物/饮水两条状态全满；用小四实际去攻击 NPC"萧峰"（「铁掌降龙」），角色被打死，干净地触发"你死了"→"鬼门关"死亡场景→NPC"白无常"打招呼——`debug.log` 全程保持空白，确认 `combatd.lpc` 的修复生效、没有死循环崩溃。这份档案再次印证了"同一大家族（哪怕不是同一份具体代码库）的多个档案值得直接核对已知 bug 列表"这条经验——这次跨越了两个原本以为不相关的具体世系分支（`jqxz2008` 系列 vs `xkx100`/`xkx2000zxb` 系列）。

### 未继续测试的部分

时间关系，没有测试拜师、购物、留言板（虽然 group_note 里已经记录过这一块此前修复过存档损坏问题）。


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
