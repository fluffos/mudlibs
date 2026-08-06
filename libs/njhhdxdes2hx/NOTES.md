
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/xkx 衍生的校园题材构建版。WASM 修复：修好了 check_legal_name() 里 §8.1 长度界限没减半的部分和残留的 i%2==0 字节步进门槛（is_chinese() 本身已经是正确的码点判断）；修复了 feature/team.lpc 里 §7.47 的 origin()==ORIGIN_LOCAL/ORIGIN_CALL_OUT（整数 vs 字符串）问题；修复了 §7.48 的跨档案非法 private 呼叫（treemap.lpc 的 _query/_set/_delete、action.lpc 的 continue_action、attack.lpc 的 attack——private 改成 protected）；修复了 §7.49 的 valid_write() 存档扩展名不匹配导致 quit 失败报"Denied write permission"。通过 adm/etc/wizlist 把 fluffos/Mud@2026 播种为 (admin)。用真实中文名字（秦风）完整注册+look/score/quit 在 WASM 下全程验证，管理员 update 指令也已验证。

## 深度功能测试（§10.7，2026-08-04）

此前只验证到注册流程本身，本轮原生 driver（端口 40194）走完了移
动、留言板、钱庄 NPC 观察、战斗、以及一轮完整的死亡→复活验证。

**主动检查（对照 AGENTS.md 已归档的 bug 类），发现并修复三类真实
bug**：

1. **全新发现：新角色食物/饮水初始化永远为 0**（现场一注册完就能
   看到 `score` 里食物/饮水两条进度条完全是空的 `□□□□...`）。根
   因：`adm/daemons/logind.lpc` 的 `init_new_player()` 在角色刚创
   建、还没有任何随身衣物时就调用了
   `user->set("food", user->max_food_capacity());`，而这份档案的
   `feature/damage.lpc` 把 `max_food_capacity()`/
   `max_water_capacity()` 定义成 `query_weight() / 200`——新角色此
   时负重为 0，除出来自然永远是 0。这不是 §8.9 的"查询了错误对象
   的 age"变体（这里压根没有 age 判断），而是一个新的、初始化顺
   序错误的 bug：食物/饮水的容量计算依赖一个此刻还不存在的状态
   （随身重量）。已把这两行从 `init_new_player()` 挪到
   `enter_world()` 里"给新手穿上衣服"（`cloth->wear()`）**之后**，
   这时负重才是真实值，并加了 `!user->query("food")` 之类的判断避
   免误伤已有存档的老角色。现场验证：修复后新角色 `score` 食物/饮
   水两条都是满格。
2. **§7.7 的又一次实例（已归档，非新类别）：留言板对象因为存档解
   码失败，导致 `capitalize(query("id"))` 崩溃**——`look` 一进饮风
   客栈就报 `执行时段错误：*Bad argument 1 to capitalize() Expected:
   string Got: 0.`，调用栈和这个 bug 类在 `jyqxc` 上发现时的一模一
   样：`feature/name.lpc` 的 `short()` 无防护地对 `query("id")` 调
   用 `capitalize()`。`data/board/common_b.o` 存档本身是一份从未转
   码、留言内容仍是原始 GBK 字节的旧存档（正文一堆乱码，但顶层字
   段名本身是 ASCII，能正常解析出 "id":"board" 之类的键），怀疑是
   `restore_object()` 在解析内嵌的乱码字节时整体失败、按驱动语义把
   `dbase` 清零，抹掉了 `create()` 里刚设好的 `id`。按 AGENTS.md
   §7.7 的既定结论（重新整理几十份旧存档超出范围，修共享崩溃点才
   是正确做法）在 `capitalize()` 调用处加了 `stringp()` 判断，现场
   确认 `look` 不再崩溃（留言板显示退化成 `文件路径(?)` 这种不好
   看但不崩溃的占位符，符合预期）。
3. **第 14 例 §7.68 复活软锁死**：`d/death/npc/{wgargoyle,
   bgargoyle}.lpc`（`DEATH_ROOM` 直接指向白无常所在房间，其
   `north` 出口可达黑无常）已按标准修法拆分。这次 `REVIVE_ROOM`
   （`/d/snow/temple`）和 `DEATH_ROOM` 指向的文件都确认存在——**不
   是**上一轮 `fys` 那种宏指错文件的情况。现场用一个近乎无法被真
   正打赢的强力 NPC（安记钱庄老板"安惜迩"，`combat_exp` 高达
   200000）一击致命触发死亡，然后完全不打断地等待白无常五段对话
   （含下面提到的错字修复）全部播完，确认 `reincarnate()` 成功、
   角色正确落地"城隍庙"，`score` 恢复正常可玩状态。

**顺手修复几处确认为原始压缩包本身损坏的字符**（均用 Python 直接
读取 raw 归档字节核实过，不是转码流程引入的，比对本项目另外 12+
个不同血统档案的同款白无常/黑无常对话逐字印证）：
- 白无常/黑无常对话"阁上册子"应为"合上册子"（GBK 字节层面确认
  "阁"字本身就在原始档案里，推断是原作者当年手误——"阁"和"合"字
  形相近容易混淆）。
- `d/snow/npc/fist_trainer.lpc` 两处台词里混进了游离的反斜杠字节
  （"说来惭愧\，" "不许\和来这里的客人"），编译时报
  `Unknown escape sequence`，已删除多余的 `\`。
- `d/snow/npc/annihir.lpc`（钱庄老板"安惜迩"）同样两处台词里混进
  了游离反斜杠（"古怪的武功\，所" "也许\是你的错觉"），一并修复。

**主动检查确认不是 bug 的项**：`command_hook`
（`feature/command.lpc`）此前已经是 `nomask`；全文搜索未发现
`MESSAGE_D->` 未加防护的调用；`d/snow/npc/guard.lpc`（淳风武馆门
房"刘安禄"）战斗中反复"忽然像是想起什么，急忙收招"，读代码+游玩
确认这是角色设定好的"只对本派弟子认真出手"（`accept_fight()`
风格逻辑），不是伤害计算 bug，属于内容设计。

**完整游玩记录**：
1. 用真实中文名字"秦风"（id `qinfeng`）注册成功，落地"饮风客栈"
   （雪亭镇），场景里有真正可读的留言板（原本因 §7.7 崩溃，修复
   后能正常 `look`/`read`）、店小二、以及一个客串 NPC"孙悟空"。
2. 移动：饮风客栈→广场→雪亭镇街道→淳风武馆大门→安记钱庄，沿途
   场景描述、出口、NPC 列表均正常渲染。
3. 战斗测试：`wimpy 0` 后先后尝试"旅客"（战斗力低，几回合分不出
   胜负）、"刘安禄"（门房，读代码确认了"不真打"的设计）、最终用
   "安惜迩"（`combat_exp` 200000）一击致命，成功触发完整的死亡→
   复活流程。
4. 死亡→复活验证（如上文详述）：完全不打断地等待白无常五段对话
   播完，确认修复后的资源软锁死 bug 不再复现，角色正确落地"城隍
   庙"。

**结果**：整个测试会话（含一轮死亡复活循环、两次修复后重启）
`debug.log` 全程为空，没有任何真实的 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录。测试角色存档
（`data/{login,user}/{q/qinfeng,s/shenmu}.o`，后者是命名冲突后弃
用的第一次尝试）保持未跟踪；六处 `.lpc` 代码改动均已用 formatter
校验（`{"errors":0}`）。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 23 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
