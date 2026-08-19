
## WASM 修复摘要（迁移自 meta.json 的 group_note）

档案名叫"风云三"，但实际游戏内横幅是"铁血江湖"（内容无关，只是文件名对不上）。is_chinese() 在这份档案里本来就已经修成了正确的 CJK 码点判断，但 check_legal_name() 的长度界限（strlen<4||>8）和它的字节步进循环（i%2==0 门槛，name[i..<0] 尾部切片）底层仍然是旧的 GBK 字节配对假设，会静默拒绝所有真实中文名字，包括标准的两字测试名——已把界限改成匹配错误提示本身声明的字符数（2-6），循环改成逐字符切片（§8.1）。quit.lpc 强制了一个真实存在的 30 秒登录后冷却（游戏设计如此，不是 bug）——测试时需要更长的 idle/填充指令预算才能观察到冷却结束，而不只是立即的 notify_fail 拒绝。排版格式化工具的第三类盲点检查（CJK 重新加空格）在约 20 个总命中里抓到了 6 处真正的损坏（5 个 ASCII 地图档案加一个分词器失去同步的帮助文字档案）——全部 6 处都直接还原，没有手工修补。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## 深度功能测试（§10.7，2026-08-04）

此前只验证到注册流程本身，本轮原生 driver（端口 40164）走完了移
动、留言板、商店 NPC 观察、战斗、以及**两轮**死亡→复活验证（第
一轮暴露出一个全新的、真正会把玩家永久卡死的 bug；第二轮在修复
后确认问题彻底解决）。

**主动检查（对照 AGENTS.md 已归档的 bug 类），发现并修复三个真实
bug**：

1. **§7.34 printf 调试泄漏（新实例）**：`adm/daemons/logind.lpc`
   `get_name()` 里，紧跟在中文名字校验通过之后有一行
   `printf("%O\n", ob);`——每个新玩家都会在自己屏幕上看到连线对象
   的原始调试信息。已删除。
2. **第 13 例 §7.68 复活软锁死**：`d/death/npc/{wgargoyle,
   bgargoyle}.lpc`（鬼门关的白无常/黑无常，`DEATH_ROOM` 宏
   `/d/death/gate` 直接摆着白无常，其 `north` 出口
   `/d/death/gateway` 摆着黑无常，两者均可达）的 `death_stage()`
   把"玩家暂时不在场"和"对象已销毁"合并成同一个提前 `return`。已
   拆分为标准修法：`!ob` 永久放弃，`!present(ob)` 改为 5 秒后重
   试。
3. **全新发现：`REVIVE_ROOM` 宏指向一个不存在的文件，导致复活序
   列走完对话后玩家永久卡在鬼门关（比 §7.68 更彻底——不是"暂时中
   断才卡死"，而是即使全程不被打扰也一定卡死）**。`include/
   login.h` 里 `#define REVIVE_ROOM "/d/yangzhou/temple"`
   指向的文件根本不存在；现场复现（杀死测试角色、完全不打断地等
   待超过 30 秒）后，虽然 `debug.log` 全程干净，但 driver 自己的
   stdout 捕获（`boot.log`，沿用 §10.8 的排查经验——`debug.log`
   会漏掉这类错误）明确记录了 `执行时段错误：*call_other()
   couldn't find object '/d/yangzhou/temple'.`——白无常的五段对话
   和 `reincarnate()` 都正常完成，但最后一步 `ob->move
   (REVIVE_ROOM)` 静默失败，角色永远留在鬼门关，只能看到白无常反
   复的闲聊消息。追查发现"temple.lpc"这个文件名如今只存在于一个
   完全没有被任何活跃房间引用的备份目录
   `d/yz_bak/yangzhou/`（内容是"隋炀帝陵"，和"temple"这个文件名本
   身的语义已经不匹配了——这份备份目录很可能是扬州分区某次重新整
   理之前的旧版快照）。比对 `d/yz_bak/yangzhou/daxiongbaodian.lpc`
   （"大雄宝殿"）与现役区 `d/yangzhou/damingshi1.lpc`（同样是"大雄
   宝殿"）这一对内容相同、路径不同的房间，可以确认现役的"扬州"分
   区是这个旧备份重新整理/改名后的产物；现役区里语义上真正对应
   "temple"（寺庙）的房间是 `d/yangzhou/damingshi.lpc`（"大名
   寺"，紧邻着"大雄宝殿"，房间里有一位"知客僧"）。已把
   `REVIVE_ROOM` 改指向 `/d/yangzhou/damingshi`，并在宏定义旁写
   了完整的排查注释。现场复现验证：修复后角色死亡→鬼门关→完整对
   话→`reincarnate()`→成功落地"大名寺"，不再卡死。

**顺手发现但未修复、留待观察的一处类似问题**：`u/lxh/dufang.lpc`
（"逍遥赌坊"，一位巫师自建的骰子赌场，从"英豪酒楼"往南可达）的
`east` 出口写的是 `__DIR__ "chunxilu3"`（相对路径，指向
`u/lxh/chunxilu3.lpc`，不存在），现场触发出的是同一类"目标文件不
存在"报错。项目里确实有一个同名文件 `d/chengdu/chunxilu3.lpc`
（"春熙路口"，成都分区），文件名重合但没有找到任何更直接的证据
（没有注释、没有其它文件引用）能确认这就是原作者的本意——不像
`REVIVE_ROOM` 那样有"隋炀帝陵/大雄宝殿"这种结构性配对证据支撑，
所以按本项目一贯的原则（不确信就不要瞎猜）先如实记录，不改动。

**主动检查确认不是 bug 的项**：`command_hook`
（`feature/command.lpc`）已经是 `nomask`；全文搜索未发现
`MESSAGE_D->` 未加防护的调用；食物/饮水在 `logind.lpc` 里两处都
是无条件 `user->set("food", 100); user->set("water", 100);`，没有
任何 age 判断，不是 §8.9 的错误对象变体。

**顺手修复一处确认为原始压缩包本身损坏的乱码字**（用 Python 直接
读取 raw 归档字节核实过，不是转码流程引入的）：白无常/黑无常两份
文件里"□上册子"应为"合上册子"（GBK 字节 `\xa1\xf5` 本来就是符号
表里的"□"，原作者当年大概率是手误/复制粘贴丢字）——本项目另外至
少 10 个不同血统档案的同款判官/无常对话都逐字写着"合上册子"，凭
这么多独立来源的印证还原。

**完整游玩记录**：
1. 用真实中文名"沈牧"（id `shenmu`）注册成功，落地"英豪酒楼"（中
   州城最大的酒楼，`no_fight` 房间），场景里有真正可读的留言板
   （当时无留言）和 NPC"武大郎"。
2. 移动：英豪酒楼→逍遥赌坊（巫师自建赌场，规则牌子文字完整）→
   文定北街→市中心→延陵东路等多个房间，沿途场景描述、出口、
   NPC 列表均正常渲染（除上文记录的 chunxilu3 死路外）。
3. 战斗测试：`wimpy 0` 后依次尝试攻击"小孩""流氓"等新手区 NPC
   （战斗力都很低，几个回合分不出胜负），最终用"侠士"（明显高出
   一个数量级的战斗力）一击致命触发死亡流程。
4. 死亡→复活验证（两轮，如上文详述）：第一轮暴露 `REVIVE_ROOM`
   bug（角色永久卡在鬼门关，即使完全不打断也一样），第二轮在修
   复+重启 driver 后验证角色成功落地"大名寺"。

**结果**：整个测试会话（含两轮死亡复活循环、一次修复后重启）
`debug.log` 全程为空，没有任何真实的 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录——`REVIVE_ROOM` 那个 bug 的
报错只出现在 `boot.log`（driver 自己的 stdout），再次印证了
§10.8 强调的"只看 `debug.log` 会漏掉一类真实错误"的教训。测试角
色存档（`data/{login,user}/s/shenmu.o`）保持未跟踪；三处 `.lpc`
改动（`logind.lpc`/`wgargoyle.lpc`/`bgargoyle.lpc`）已用 formatter
校验（`{"errors":0}`）；`include/login.h` 的宏定义改动不在
formatter 覆盖范围内，改动很小，人工核对无误。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 47 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg` 同一原始形状）**：
   `if (this_player(1)) efun::write("编译时段错误：" + message +
   "\n");`——不区分巫师/玩家，也不区分警告/错误。真实复现：全新驱动
   进程下首次完整注册流程（`fluffos` 管理员账号）触发的冷编译级
   联，屏幕上连续刷出 **124 行**原始诊断（本轮迄今为止最严重的一
   次，这份档案的场景/NPC 数量明显更大）。修复：加上
   `strsrch(message, "arning:") == -1` 判断。已用同一新驱动进程下的
   完整重新注册复测：零次诊断刷屏（唯一命中的"什么"是正常游戏文本
   "发生什么了？"）。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例，与 `fqyy2`/`fy2mg`
   同一形状）**：`LOG_DIR` 下的 `nosave/` 子目录在全新检出里不存
   在，`suicide`/崩溃日志/巫师 `clone` 日志等管理指令路径的
   `log_file()` 调用会在首次使用时未捕获抛出。注册/登录本身只写
   `log_file("USAGE", ...)`（无子目录，本来就存在），不受影响，但
   这是一个明确存在的 bug，按标准模式补上
   `assure_file(LOG_DIR + file);`（含前向声明）。
3. **管理员账号从未真正创建（AGENTS.md §1.5 的"wizlist 有记录但角色
   从未真正建立"形状，与 `fy2mg` 同一模式）**：`adm/etc/wizlist`
   里早就有 `fluffos (admin)` 这一行，但 README 此前的记录"账号本身
   通过正常注册流程创建"经核实是错的——`git log` 确认仓库里从未提交
   过 `data/{login,user}/f/fluffos.o`。已用真实注册流程完整创建
   `fluffos` 角色，`score` 确认显示"目前权限：(admin)"，
   `update /adm/daemons/securityd` 确认可正常重新编译。README 已同
   步更正这段记录。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`
  和 `u/xxy/city2/npc/refereew.lpc:176` 均已用
  `(string)(to_int(query("win_times")) % 5)`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。
- `assure_file()` 本身末尾不做 `seteuid(getuid())` 重置，不属于
  `nitan_san`/`nt6nitan6win` 那种"assure_file 自己把 euid 重置掉"的
  形状。

### 实测过程

`fluffos` 管理员账号完整注册（英文 id → 确认建立 → 中文名，直接设定
不需要二次确认 → 密码（此代码线只要求 ≥3 字元，比 `fqyy2`/`fy2mg`
宽松很多）→ 确认密码 → 邮箱 → 性别）进入起始区域。修复前后各做一次
全新驱动进程下的完整注册；修复前复现了 124 行诊断刷屏，修复后干
净。`log/debug.log` 全程时间戳未变化，确认无新增未捕获运行期错误。
驱动最终按精确 PID kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：2868 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。这份档案有 5 处代码生成模板烤了同一个地雷：
`obj/roommaker.lpc`、`d/obj/clone/misc/roommaker.lpc`（简单字符串
拼接写法）以及 `obj/rmmaker.lpc`、`u/panguan/rmmaker.lpc`、
`u/panguan/room.lpc`（`room_code +=` 缩进写法略有不同的另一套模板，
前两处修完后仍剩 3 处才发现）。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上 5 处模板手动摘除字符串拼接片段。`git diff --stat`：2868 files
changed。备注：survey 记录的"live"数字（3013）和实际盘面对不上，
真实 live 数量是 2870（总匹配 3157 减去 287 处确认为既有注释的行，
逐条抽样核实过），修复后 0 处遗留 live 匹配，287 处注释原样保留未
动。

验证：`build-debug` 驱动真实冷启动，端口 40164 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`Mud@2026` 登录正常
（落地英豪酒楼，look/quit——quit 触发"三十秒后才能下线"的存档中提
示，属正常游戏机制不是崩溃），全程无新增
"cannot replace"/"cannot bind" 日志行。
