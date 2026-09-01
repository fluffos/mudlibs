
## WASM 修复摘要（迁移自 meta.json 的 group_note）

风云Ⅳ，古龙小说题材 MUD。同时修复了 is_chinese()（字节区间判断+要求 strlen>=2）和 check_legal_name()（长度界限和错误提示自己声明的 1-5 字符范围对不上，外加按字节步进的 i%2==0 尾部切片循环）里经典的 §8.1 中文名字 bug——会静默拒绝所有真实中文名字，包括标准的两字测试名。GB/BIG5 编码选单两个选项都实测过，画面正常，这里不是真实存在的 bug。排版格式化工具的第三类盲点检查在少数几个"误报"里抓到了一处真正的损坏（daemon/damage-1.lpc，一份纯文本战斗记录数据表被压成一行并加了空格）——已还原。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## 深度功能测试（§10.7，2026-08-04）

此前只验证到注册流程本身（含中文名字 bug 修复的回归确认），本轮原生
driver（端口 40165）走完了完整的游玩会话：移动、商店、留言板、战
斗、死亡、无人打扰的完整复活。

**主动检查（对照 AGENTS.md 已归档的 bug 类）**：全文搜索 `printf(`
未发现 §7.34 遗留调试输出；`command_hook` 未发现 `private` 违规
（用 grep 确认唯一定义处已是标准写法）；未发现 §8.9 的错误对象
age 判断变体。

**新发现并修复：第 12 例 §7.68 复活软锁死**（`d/death/npc/
panguan.lpc`，鬼门关的"朱笔判官"——文件头注释写着 `// TIE@FY3`，
说明这份文件的血统其实来自风云Ⅲ 系列，和本项目里 `fy330`/`fy2mg`
两份档案共享同一个原始判官 NPC 设计）。原判断把四个条件全部塞进一
行提前 return：`if (!ob || !present(ob) || !ob->is_ghost() ||
(int)ob->query("combat_exp") > MAX_EXP) return;`——`!present(ob)`
（玩家暂时不在场）和另外三个"应当永久放弃"的条件（对象已销毁、已
经不是鬼、战斗经验超过判官能处理的上限）被错误地合并成了同一种
"永久放弃"。已拆分：`!ob` 单独永久放弃；`!present(ob)` 改为 5 秒
后重试（标准修法）；`!ob->is_ghost() || combat_exp > MAX_EXP` 保留
为永久放弃（这两个条件本来就该是"这个判官不负责处理你，交给别的
机制"，不是暂时性问题，和 `fy330` 自己那份判官文件当初的处理方式
一致）。另外确认了同目录的 `panguan2.lpc`（生死判官）和
`greengirl.lpc`（绿珠，非死亡流程但也有一个 `call_out` 链）看起来
形似但**不是**同一类 bug：前者的 `death_stage()` 是一次性检查（活
人误闯深处地狱会被攻击），没有多阶段重试逻辑，玩家离开后什么也不
发生就是正确行为；后者的 `next_stage()` 同理，`environment(me) ==
environment()` 判断失败时安静放弃也是设计如此——两者都没有"卡死
鬼魂"的风险，未改动。

**完整游玩记录**：
1. 用真实中文名"沈牧"（id `shenmu`）注册成功，落地"凤求凰客栈"
   （唯一出口 west）。
2. 移动：客栈→广场南→玉龙珠宝店（`list` 正确显示玉指/玉簪/玉花/
   玉镯四样商品和价格）→广场南→风云天下（中心广场）→广场北，沿
   途场景描述、出口、NPC 列表均正常渲染。
3. 留言板测试：风云天下的"盘龙摩天柙(Stone)"是一个真正的公共留言
   板（`/std/bboard.lpc`），`read 1` 成功读出一条真实留言（标题"第
   一个"，作者"温柔杀手"）——注意指令格式是 `read <编号>`，不是
   `read stone <编号>`（一开始按后者格式试过，被 `notify_fail`
   正确拒绝，不是 bug，是命令语法理解错误）。
4. 战斗测试：`kill police`（广场的巡逻士兵）——新手角色一击斃命
   （攻击力/防御力起始只有个位数到两位数，巡逻士兵明显不是新手该
   招惹的对象，纯粹是数值/内容现象，不是 bug）。死亡后正确落地
   "鬼门关"，朱笔判官/牛头/马面均在场。
5. 死亡→复活验证（**两轮**，第二轮是应用 §7.68 修复并重启 driver
   之后做的回归验证）：**在完全不打断的情况下**（发送战斗指令后立
   即断开，等待约 20 秒让 `call_out` 链自行走完，再用一条全新连接
   静默重连查看落地位置）确认：判官的四段对话依次播放完毕，
   `reincarnate()` 成功，角色最终随机落地 `revive_loc` 两个复活点
   之一（本次落在"天主教堂"），`score` 正确显示"你总共杀了零个
   人...被杀了一次"。**这正是修复后应有的行为**——如果没有这次拆
   分修复，任何一次连线中断都会让鬼魂永久卡在鬼门关。
6. `quit` 正常退出，退出前正确丢弃了随身衣物（死亡惩罚的一部分，
   内容行为）。

**结果**：整个测试会话（含两次死亡复活循环）`debug.log`
除了已知的、和本次测试无关的沙盒环境噪音（`init_addr_server`/
`socket_write` 的 DNS/UDP 权限拒绝，属于 §7.6 一类的沙盒网络限制，
不是这次改动引入的）之外没有任何 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录；本轮测试专门清空过一次
`debug.log` 以确认这一点，测试期间该文件全程为空。测试角色存档
（`data/{login,user}/s/shenmu/`）保持未跟踪；`panguan.lpc` 的改动
已用 formatter 校验（`{"errors":0}`）。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 9 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,180 处存活匹配，全部标准独立行形式，脚本一次
  性删除，无不规则残留。没有房间生成类工具（`roommaker`/`makeroom` 均未
  找到），不涉及工厂模板修复。`data/` 下额外核查过，无命中。验证：真实
  debug 驱动干净编译启动、端口正常监听，`debug.log` 无新增 "cannot
  replace"/错误行。

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

## 深度功能测试（§10.7，2026-09-01，第二轮）

角度：这次专门补测上一轮（2026-08-04）明确跳过的部分——真实的商店
买卖交易、拜师门派流程、信箱/寄信系统，以及沿途新走的房间是否触发
§7.19 一类的 NPC `init()` 重入 bug。原生 debug driver（端口 40165），
用纯 Python socket 脚本全程操作（未用 `tmux_mud.sh`）。协议层确认：
这个 lib 的连线是 **UTF-8**，不是 GBK（草稿脚本一开始按 GBK 编码送
字符导致中文名字连续判定失败，换成 UTF-8 后正常）。

1. 用真实中文名"沈秋"（id `muqiuxia`）注册成功，落地"凤求凰客栈"。
2. **管理员账号补注册**：发现 meta.json 里记录的"fluffos/Mud@2026
   已通过真实注册流程播种"其实不准确——`adm/etc/wizlist` 里虽然列
   着 `fluffos (admin)`，但 `data/login`/`data/user` 下根本没有这个
   账号的存档（甚至连 `f` 字母桶目录都不存在）。重新用正常注册流程
   走了一遍（id `fluffos`，密码 `Mud@2026`），因为在 wizlist 里，注
   册完直接拿到 `(admin)` 权限。之后用这个号 `goto`/`summon`/
   `clone`/`give` 给测试角色发测试用的黄金。
3. **商店买卖交易（此前只测过 `list`）**：玉龙珠宝店（`d/fy/yuljade.
   lpc`，掌柜"商玉龙"）`buy 玉簪 from jadeseller` 成功购买，价格、
   找零（黄金/银子/铜钱换算）都正确；千银当铺（`d/fy/qianyin.lpc`，
   老板娘"香菱"，`feature/pawnowner.lpc`）`value`/`sell` 也验证成
   功，按物品价值的 80% 换算成实际钱币正确发放。注意：这两个指令走
   的是 `present()`/`id()`，只认物品的英文 id（如 `jade pin`），不
   认中文名字"玉簪"作为参数——直接拿中文名字当 `sell`/`value` 的参
   数会被判定为"没有这样物品"，这不是 bug，是这个 lib 全局一致的物
   品寻址规则（`feature/name.lpc` 的 `id()` 只查英文 id 数组，`buy`
   指令之所以能认中文名字，是 `feature/vendor.lpc` 里 `buy_object()`
   自己额外加了一条按 `name()` 比较的特例，不是通用规则）。
4. **拜师门派流程**：`d/fy/jbang.lpc`（帮主堂，金钱帮总舵）的
   "荆无命"（`d/fy/npc/jinwuming.lpc`）`attempt_apprentice()` 无条
   件接受拜师，用 `apprentice master jin` 一次成功拜师，`score` 正
   确显示"金钱帮 帮众"和"你的师父是荆无命"。
5. **信箱/寄信系统**：风云驿站（`d/fy/mailst.lpc`）的"王风"
   （`officer.lpc`）`ask officer about mail` 成功领取信箱（`obj/item/
   mailbox.lpc`），`mail muqiuxia` 给自己寄信（标题+正文，用 `.` 结
   束编辑，`n` 选择不留副本）成功，`from`/`read 1` 都能正确读出刚
   寄出的信。这个 lib 没有独立的 `tell`/频道类指令入口可测（未找到
   `cmds/usr/tell.lpc` 或类似文件）。
6. 沿途新走的房间（`swind2`/`swind3`/`swind4`/`qianyin`/`jinqian`/
   `jting`/`jhuang1`/`jbang`/`wcloud1`/`wcloud2`/`mailst`，均为上一
   轮未到过的区域）里的黄衣卫、王风、香菱、荆无命、上官金虹等 NPC
   首次编译加载时 `debug.log` 全程干净，没有出现 §7.19 一类的
   "Too deep recursion"。

**新发现并修复（真实 bug，非设计选择）**：`std/money.lpc` 的
`query_autoload()` 被注释掉了（`autoload(string param)` 接收端完整
存在且能正常工作，但登记端整行被 `//` 注掉），导致 `cmds/usr/
quit.lpc` 把所有随身货币都误判成"不支持 autoload"，每次正常 `quit`
都会把身上的黄金/银子/铜钱直接丢在退出时所在的房间地板上（公共场
所，任何路人都能捡走），而且下次登入也不会恢复——这不是断线/net-
dead 的边缘情况，是**每一次正常 `quit` 都会触发**的通用逻辑。追到
`raw/fy4_S/fy4/std/money.c`，确认这行注释在原始风云Ⅳ源码里就已经
存在，不是这次转换引入的；但这明显是真实的程序 bug 而不是设计选
择——全库跨库搜索发现同一行 `string query_autoload() { return
query_amount() + ""; }` 在几十个非风云系血统的 lib 里是**启用状态**
（原样一字不差），只有风云系血统的档案带着这行被注释掉的版本，说
明这就是别的血统早就修过、风云系一直没修的同一个 bug。已取消注释，
用管理员账号发钱给测试角色、`quit`、重新登入验证：修复后 `quit`
正确打印"黄金化成一蓬粉末消失了"（走 destroy-and-reconstruct 分
支，不再是"你丢下一些黄金"），重新登入后 `i` 正确显示黄金金额原样
恢复。已加入 AGENTS.md §7.199。

**跨库扫描（同日）**：grep 全部 lib 的 `std/money.lpc`，发现同样被
注释掉的这一行一共命中 16 个 lib（全部是风云系血统）：`fysjmb`（本
lib，已实测验证）、`fengyun434`、`fy2`、`fy2005`、`fy2mg`、`fy2qh`、
`fy330`、`fy3dz`、`fy3xd`、`sjpl2`、`sjplgfjxb`、`sjplii`、`wqfy`、
`xsfyssjb`、`zzfy`、`zzfy3`。其余 15 个用同一处单行取消注释修复，
逐一用 `lpcc config.fluffos /std/money` 做了针对性编译检查，全部干
净通过；未对这 15 个做完整 §10.7 深度游玩测试或整库重启验证，符合
本项目"一个 lib 实测确认、其余同款 lineage 机械扫描 + 编译检查"的
既有惯例。

**结果**：本轮测试期间 `debug.log` 除已知的编译期"unused local
variable"一类警告（首次加载各文件时会广播到当前连线的屏幕上，是正
常的懒编译提示，不是错误）之外，没有出现任何 `error:`/`Bad
argument`/`No program`/`Too deep recursion`/`FATAL` 记录。测试角色
存档（`data/{login,user}/m/muqiuxia/`）与管理员测试号
（`data/{login,user}/f/fluffos/`）均保持未跟踪。
