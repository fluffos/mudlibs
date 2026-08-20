
## WASM 修复摘要（迁移自 meta.json 的 group_note）

金庸题材 mudlib，游戏内标题为"江湖风云II 之 辽宁风云再起"（Jianghu Fengyun II）。异常干净：完全没有发现 mudlib 代码 bug——宏本来就和 config.fluffos 一致，is_chinese()/check_legal_name() 本来就是正确的码点判断，指令表开箱即用，也没有 this_player()/previous_object() 覆盖问题。完整的注册→look→score→quit 流程第一次真实尝试就顺利跑通。唯一需要做的是管理员播种：把 fluffos/loginpass1 加入既有的 CRLF 格式 adm/etc/wizlist，游戏内"★ 您目前权限：(admin)"显示确认生效。排版格式化后也重新验证过完整流程。格式化工具发现 2 个真正损坏的档案（d/huashan/map.lpc，一张 ASCII 地图，和手足档案里见过的同一种分词器混淆模式；d/player/fyue_room.lpc，一段房间描述）——两者都用 git checkout 还原。d/city/sj.lpc 有和 ffxymud 完全相同路径下那份档案一样的、转档之前就存在的、无法到达的缺引号损坏——未修，不是格式化工具造成的。

## 深度功能测试（§10.7，2026-08-04）

此前的会话确实完整走通了注册→look→score→quit，但"没有发现任何需
要修改的 mudlib 代码"这个结论是没有经过战斗/死亡测试就下的——本轮
原生 driver（端口 40137）实际玩到了移动、留言板、战斗、以及一轮完
整的死亡→复活验证，结果发现这份档案并不像此前记录的那样"完全干
净"，找到并修复了三类真实 bug，全部是本项目已经归档的常见模式。

**主动检查（对照 AGENTS.md 已归档的 bug 类），发现并修复三处真实
bug**：

1. **§7.34 printf 调试泄漏（新实例，两条并行代码路径都有）**：
   `adm/daemons/logind.lpc` 的 `get_name()`（自己输入中文名字的路
   径）和 `get_resp()`（接受系统随机中文名字的路径）里各有一行
   `printf("%O\n", ob);`，紧跟在中文名字确认之后、设定密码之前，
   两条路径都会把连线对象的原始调试信息直接打到玩家屏幕上。此前
   那一轮 WASM 验证很可能测的是同一条路径没有触发第二条、或者没
   有留意这行输出，才被记成"零 bug"。已删除两处。
2. **第 15 例 §7.68 复活软锁死**：`d/death/npc/{wgargoyle,
   bgargoyle}.lpc`（鬼门关的白无常/黑无常，`DEATH_ROOM`
   `/d/death/gate` 直接摆着白无常，其 `north` 出口
   `/d/death/gateway` 摆着黑无常，两者均可达）的 `death_stage()`
   把"玩家暂时不在场"和"对象已销毁"合并成同一个提前 `return`。已
   拆分为标准修法：`!ob` 永久放弃，`!present(ob)` 改为 5 秒后重
   试。这次 `REVIVE_ROOM`（`/d/city/wumiao`，武庙）和 `DEATH_ROOM`
   指向的文件都确认存在——不是上上一轮 `fys` 那种宏指错文件的情
   况。白无常/黑无常两份文件里的"合上册子"台词本身没有损坏（和
   `fys`/`njhhdxdes2hx` 那两次遇到的"阁上册子"/"□上册子"不同，
   这份档案的拷贝是干净的）。
3. **§8.9 食物/饮水错误对象判断（新实例）**：`enter_world()` 里
   `if (ob->query("age") == 14)` 查询的是临时连线对象 `ob`，不是
   持久角色对象 `user`——`ob` 从来没有 `age` 属性，这个条件永远为
   假，食物/饮水初始化代码块从未真正执行过。改成
   `user->query("age") == 14` 后现场验证生效。**注意**：本轮注册
   测试时 `score` 显示食物/饮水两条本来就是满格——说明这个 bug 在
   这份档案里目前是"哑火但无害"的（角色的食物/饮水另有默认值来源
   ，不完全依赖这段代码），但判断逻辑本身确实是错的、和本项目其
   它 6 个已确认的同款实例（`jyqxc`/`bixiecanyang`/`ldtxii` 等）
   写法一致，按既定原则修正，不因为"目前没造成可观察后果"就跳过。

**完整游玩记录**：
1. 用真实中文名字"秦风"（id `qinfeng`）注册成功，落地"客店"（这
   份档案的出生点似乎是随机的几家客栈/客店之一——本轮和更早那次
   注册测试落地的不是同一家），场景里有真正可读的留言板和店小二。
2. 移动：客店→南大街（可以看到"天安门"这样的写实地标，和金庸江
   湖的门派场景混搭），沿途场景描述、出口、NPC 列表均正常渲染。
3. 战斗测试：`wimpy 0` 后 `kill xiao fan`（南大街的小贩），测试
   角色几拳都没打中对方就被一套连续动作打死（攻击力起始只有 1，
   内容/数值现象，不是 bug）。
4. 死亡→复活验证：死亡后正确落地"鬼门关"，白无常在场。**完全不
   打断地等待**（断开连线后静默等待 30 秒，再用新连接重新登录查
   看结果）确认：五段对话全部播完，`reincarnate()` 成功，角色正
   确落地"武庙"（`REVIVE_ROOM`），`score` 显示"你共死亡：1次"，
   食物/饮水恢复满格，可以正常继续游玩。

**结果**：整个测试会话（含一轮死亡复活循环、一次修复后重启）
`debug.log` 全程为空，没有任何真实的 `error:`/`Bad argument`/
`No program`/`Too deep recursion` 记录。测试角色存档
（`data/{login,user}/{q/qinfeng,s/shenmu}.o`，后者是命名冲突后弃
用的第一次尝试）保持未跟踪；三处代码改动均已用 formatter 校验
（`{"errors":0}`）。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 93 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。与手足档案 `jhfy` 不同，这份档案的 `log_error()`
此前**没有**被修复过——两者虽是姊妹档案，`log_error()` 的修复状态
却各自独立，印证了"不能从血统关系假设 bug 状态"这条本轮反复验证过
的教训。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查（AGENTS.md
   §7.34-class，与本轮 `wdxtym`/`ffxymud`/`fy2mg`/`fys`/`hc`/`hy`/
   `hy2000`/`hy2002`/`hy3`/`hy5`/`hyiishzdscbb` 同一原始形状）**：
   `if (this_player(1)) efun::write(...)`——不区分巫师/玩家，也不区
   分警告/错误。修复：加上 `strsrch(message, "arning:") == -1` 判
   断。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例，和姊妹档案 `jhfy`
   完全同一形状）**：`adm/daemons/logind.lpc` 的 `get_gender()`
   （**新角色注册流程的最后一步**）紧跟着调用
   `log_file("login/newid.log", ...)`——`LOG_DIR` 下的 `login/`
   子目录若不存在，会在每一个全新角色注册完成的那一刻未捕获抛出。
   已补上 `assure_file(LOG_DIR + file);`（含前向声明）。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:146`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。

### 管理员账号：存档从未真正提交

README 记录"账号本身通过正常注册流程创建，已在游戏内确认权限显示
正确"——`git log` 确认这个存档从未被提交过，本地 `work/` 目录里也
不存在。已用真实注册流程（英文 id → 确认建立 → 中文名 → 密码
`loginpass1` → 确认密码 → 天赋 0 随机 → 接受 → 邮箱 → 性别）重新
创建 `fluffos`/浮浮，`score` 确认"★ 您目前权限：(admin)"。

### 一次测试方法论的排查记录（非 bug）

`update /adm/simul_efun/file` 报错 `*No program in object
'/adm/simul_efun/file'!`——排查后发现 `adm/simul_efun/file.lpc` 是
被 `#include` 进 `adm/obj/simul_efun.lpc`（`simulated efun file`
配置项指向的档案）的，本身不是一个独立编译单元，不能直接 `update`。
改用 `update /adm/obj/simul_efun` 也报错（`destruct()` 相关，热重
载 simul_efun 对象本身在多数驱动上都有特殊限制，属于测试方法的局
限，不是这份档案的 bug）。改用一个普通对象 `update
/adm/daemons/logind` 成功验证了真正的写权限。`log/debug.log` 里唯
一新增的两条运行期错误就是这两次排查性尝试留下的痕迹，均已确认与
本轮修复无关。驱动最终按精确 PID kill，`ps -p` 确认已退出。

### 已清理

- 管理员 `fluffos` 的存档已提交（`data/{login,user}/f/fluffos.o`）。
- `data/{login,user}/{q/qinfeng,s/shenmu}.o` 是此前会话遗留的未提
  交测试存档（`Aug 4` mtime，早于本次会话），未受本轮任何操作影
  响，未触碰。

## §7.100 房间基类 replace_program() 扫尾修复（2026-08-19）

`ROOM` 宏（`/inherit/room/room`）在本档案 2,070 处房间文件的
`create()` 里紧跟 `inherit ROOM;` 之后又多余调用了一次
`replace_program(ROOM);`——AGENTS.md §7.100 记录的同一个休眠 bug，
和 `yzxiiizylfy`/`xyzxiiylzymh`/`xyzx3`/`xysylmhb` 同一双 roommaker
副本血统（`clone/misc/roommaker.lpc`、`d/huanggon/obj/
roommaker.lpc` 目录结构完全一致）。用 `fix_710_room.py` 扫过
`work/`，删除 2,068 处标准形状；两份房间建造工具各剩 1 处字符串
拼接变体，手工改成 `str += "\n\tsetup();\n}\n";`。修复后 `work/`
下 0 处存活残留，`work/data/` 下没有真实 `.lpc` 源码命中。`git
diff --stat` 显示 2068 个文件净删 2070 行、增 2 行，与脚本自报数
字 + 2 处手工编辑吻合。

驱动干净启动（零新增编译错误、端口 40137 正常监听、`debug.log`
无任何"cannot replace"/"cannot bind"行）。管理员 `fluffos`/
`loginpass1`（本档案自己的密码，与其它 XYZX 血统档案的
`Mud@2026` 不同，也没有 '2060' 握手门槛）实机登录成功，`look`/
`score`/`quit` 均正常，全程 `debug.log` 保持干净。管理员存档的时
间戳漂移已用 `git checkout HEAD --` 还原，未提交；此前会话遗留的
无关测试存档（见上）未触碰。驱动按精确 PID 结束。
