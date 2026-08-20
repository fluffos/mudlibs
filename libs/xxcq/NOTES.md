
## WASM 修复摘要（迁移自 meta.json 的 group_note）

小雪初晴，游戏内品牌名"SnowMud"，CuteRabbit Studio（JackyBoy）为 CCTX 和 SDXL 制作的一款以温瑞安小说为题材的 MUD。WASM 修复了一个真正会卡死游戏的 bug：这份压缩包里任何地方都没有 adm/etc/ 这个目录（连 raw/ 里也确认不存在），导致 logind.lpc 最开头的 write_file(USERS, ...) 呼叫（访客计数器自增，每一次连线、在 id 提示出现之前都会执行）抛出"Wrong permissions for opening file /adm/etc/users for overwrite, No such file or directory"——write_file() 能创建缺失的档案，但创建不了缺失的目录，所以这是每一次连线都会触发的未捕获错误，驱动会静默吞掉它，直接把裸连线丢进一个交互式指令提示符，从未呼叫 input_to() 进入注册流程（之后任何输入都显示成无法识别的"什么？"指令）。这在原生启动下也会一模一样地失败，不只是 WASM 环境的问题。已通过创建 libs/xxcq/work/adm/etc/ 目录并预置 users/iduser 计数器档案（均为 '0'）修复。另外通过源码确认（§7.56 双档案歧义提醒）SECURITY_D 实际指向 /adm/daemons/securd，而不是那份引用了（这份代码库里根本没用到的）WIZLIST 文本档案的诱饵档案 .../securityd.lpc——securd.lpc 是通过 restore_list() 里一行硬编码的 set('wiz_status/jackyboy', '(admin)') 呼叫来播种管理员账号的（和本轮之前修过的 sj 那份档案是同一种形态），而不是读取 wizlist 档案；已加上一行同样的 set('wiz_status/fluffos', '(admin)')。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 选择→英文 id→y/n 确认创建→中文名字→临时密码+确认→接受天赋赠礼（y）→性别（m/f）→带着完整角色属性表进入游戏世界，连线横幅里已经直接显示"目前权限：(admin)"，还有"【天神】"最高阶层称号，全程没有任何意外错误。LPC 格式化工具对全部 2886 个档案运行（写入 2828 个，28 个报错，30 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。唯一一个存在的 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## §10.7 深度功能测试（本次新增）

此前只做过一次连续会话内的注册流程验证。本次实际深入游玩后发现：**WASM
修复阶段创建 `adm/etc/` 目录时遗漏了一个文件**，导致每一次注册实际上
仍然会在幕后彻底失败——只是这次失败得比之前更隐蔽，不会中断连接，而
是让角色永远卡在"灰蒙蒙一片、什么也没有"的无环境状态。这是本次会话里
发现的最严重的一类 bug，同时还额外发现了 §8.9、printf 调试残留、2 处
§7.68、以及一个从未被记录过的登录对象权限过严 bug。

### 修复 1（本次最严重的发现）：adm/etc/motd 缺失导致每次注册都静默失败

`adm/daemons/logind.lpc` 的 `enter_world()` 里有一行完全没有防护的
`write(read_file(MOTD));`（`MOTD` = `/adm/etc/motd`）。WASM 阶段虽然
创建了 `adm/etc/users`/`iduser`，却没注意到还需要一个 `motd` 文件——
`read_file()` 对不存在的文件返回 `0`（不是字符串），`write(0)` 会让
`receive_message()` 抛出未捕获的 `*Bad argument 1 to receive()`，而这
一行恰好出现在**同一个函数里、真正把角色 `move()` 到起始房间那一行代
码之前**——所以每一次注册，函数都会在这里意外中断，角色对象已经创建、
已经存盘，但从未被放进任何房间。之后无论连线多少次、输入什么指令，
`look` 都只会看到"你的四周灰蒙蒙地一片，什么也没有。"，没有任何报错
提示玩家，连管理员账号自己第一次注册也是这个下场。这是本档案原始压缩
包里真实存在的缺陷（原生开机下也一样），不是 WASM 沙箱特有的问题；
WASM 阶段已经处理了同类问题的一半（补齐了 `adm/etc/` 目录本身），但
遗漏了这个具体文件，掩盖了背后这个真正的代码级 bug。已按 AGENTS.md
§7.9 的标准做法加上 `stringp()` 判断修复，不再依赖恰好存在这个可选的
欢迎消息文件。

### 修复 2：adm/daemons/natured.lpc 的同类连锁 bug——缺失的昼夜数据表

同样的根因还影响了另一个完全独立的档案：`natured.lpc` 的
`read_table("/adm/etc/nature/day_phase")` 在这份压缩包里同样彻底不存
在，`explode(read_file(file), "\n")` 在没有防护的情况下崩溃
`*Bad argument 1 to explode()`——第一次被惰性编译触发的时机恰好是巫师
起始房间自动 `look` 的时候。加上 `stringp()` 防护后问题并没有完全解
决：`day_phase` 变成了空数组，而 `init_day_phase()`/
`update_day_phase()`/`outdoor_room_description()`/`outdoor_room_
outcolor()` 这四处都假设这个数组至少有一项，`sizeof(day_phase)-1` 会
变成 -1（"Array index must be positive or zero"），取模 `%
sizeof(day_phase)` 还会除以零——每一个户外房间的 `look` 都会崩溃。最
终修法是在读取数据表的地方就填入一个最小的兜底单条目（"天色如常"），
让下游所有假设"至少一条"的索引/取模运算保持有效，而不是逐个访问点单
独加判断（详见 AGENTS.md §7.9 的追加记录）。

### 修复 3：§8.9 食物/饮水年龄检查错对象

`logind.lpc` 的 `enter_world()`：
`if (!user->query("food") && !user->query("water") && ob->query("age") == 14)`
——`ob` 是登录对象，`ob->query("age")` 永远是 undefined，这道门槛永久
为假，每个新角色的食物/饮水会静默永远保持 0。已改成
`user->query("age") == 14`，实测新角色食物/饮水栏正确显示为满格。

### 修复 4：printf 调试残留

`get_name()` 在设置角色中文名字之后紧跟一行
`printf("%O\n", ob);`，会把登录对象的原始引用（如
`/clone/user/login#0`）泄露给每一个刚输入完中文名字的新玩家。已删除。

### 修复 5：两处 §7.68 复活软锁（d/death/npc/{b,w}gargoyle.lpc）

`death_stage(object ob, int stage)` 原代码
`if (!ob || !present(ob)) return;` 把"鬼魂对象已经不存在了"和"鬼魂此
刻只是暂时不在这个房间里"混为一谈，一旦判定瞬间鬼魂碰巧不在场就永久
放弃后续引导，把鬼魂永久卡在鬼门关。按标准修法拆开：`!ob` 才是真正放
弃，`!present` 改为 5 秒后重试。

### 修复 6（此前完全没有暴露过的新 bug）：登录对象自身的 set() 权限保护过严，导致邮箱注册的密码更新静默失效

`clone/user/login.lpc` 给自己的 `set()` 加了 `nomask` 保护（"Protect
login object's data against hackers"）：只允许 `geteuid(previous_
object()) == ROOT_UID` 的调用者写入。但真正核心的邮箱注册流程
`inherit/room/regroom.lpc` 的 `do_register()`——不是玩家自造的内容，
是系统本身的注册房间——运行在房间自己的普通域 euid（这里是
`"Domain"`）下，并不是 root，于是它对 `linkob->set("password", ...)`
和 `linkob->set("email", ...)` 的调用全部被无声拒绝，只在玩家屏幕上
打印一行 `login set is error!Domain`（打印之后**并不中断**，后续代码
照常执行，所以整个注册看起来完全正常："你是第1个注册的朋友！发送到
...的邮件已经加入发送队列！"）。实际效果：系统生成并通过邮件发送给
玩家的新随机密码从未真正生效，玩家的密码一直停留在最初自选的临时密
码上，和"忘记密码请查收邮件"这套流程的承诺完全不符。修复没有直接放
宽 `login.lpc` 自己的保护（那样会重新打开它自己注释里承认的"漏洞"），
而是给已经拥有 root euid 的 `logind.lpc`（`create()` 里
`seteuid(getuid())`）加了一个小的转发函数 `set_login_field()`，
`regroom.lpc` 改成通过这个函数间接写入。已实测确认：修复后同样的注
册流程不再打印任何 `login set is error`/`password seting is fail`。

### 检查、确认不适用的已知 bug 类别

- §7.78 CHARACTER 的 F_* 混入档缺 F_DBASE inherit：`inherit/char/
  char.lpc` 是和 shujian3/hy2002/jh2006 完全相同形状的 ES2 结构，这
  几个同宗档案都已经用真实测试排除过这个 bug（裸 set/query 实际写入
  了真正的 dbase），本次时间关系未重复验证。

### 未能完成的部分（诚实记录）

由于地图上能立即找到的敌对 NPC 几乎都被原作者自己注释掉了（"objects"
清单整段包在 `/* ... */` 里，如 `d/bianliang/guandao10.lpc` 的
`bigwolf`），本次深度测试完成了完整的注册→移动→户外场景验证，但没有
找到一个可以快速安全触发的实战/死亡目标，因此没有做成活体的战斗/死
亡/复活验证——`bgargoyle.lpc`/`wgargoyle.lpc` 的 §7.68 修复只做到静态
代码审查确认，留给未来 pass 补做。


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

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 20 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复五处问题：

1. **`config.fluffos`**：`maximum evaluation cost` 从 `700000`（已知
   风险区间）提升到 `5000000`。
2. **`cmds/ang/update.lpc`（AGENTS.md §7.106）**：缺少
   `environment(me) &&` 前置防护，补上。
3. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
4. **`adm/obj/master.lpc::log_error()`（AGENTS.md §7.10/§7.103）**：
   `if (this_player(1)) efun::write(...)` 完全没有警告过滤门，任何
   编译警告都会原样广播给连线玩家。补上
   `strsrch(message, "arning:") == -1` 判定。
5. **`clone/user/user.lpc::reconnect()`（AGENTS.md §7.108，第十八条
   独立确认的血统）**：`adm/daemons/logind.lpc` 有同款
   `exec(old_link, user);` 踢掉重复登录写法，`reconnect()` 缺少
   `enable_commands()`。按 §7.108 记录的写法预防性修复，现场用两个
   真实连线复现"保持第一个连线不断开→第二个连线登录→答 y 踢掉旧连
   线"验证：`score` 修复后立即正常显示完整角色档案。

### 方法论记录（非 bug）：既有 `fluffos` 账号密码未知，改用新账号测试

与本 session 早前在 `sj` 上遇到的情况一样：已有存档的 `fluffos` 账
号（第一轮用"临时密码"通过真实注册流程播种，但 NOTES.md 没有记录
具体密码值）用标准密码 `Mud@2026` 登录失败。管理员授权在
`securd.lpc::restore_list()` 里是纯代码层硬编码（`set("wiz_status/
fluffos", "(admin)")`），不依赖密码正确与否。仿照 `sj` 的处理方
式，新增一行 `set("wiz_status/fluffosb", "(admin)")`，用全新 id
`fluffosb` 走真实注册流程验证（密码 `Mud@2026`），本轮所有测试均
用这个新账号完成。原 `fluffos` 账号存档原样保留，未触碰。

### 现场验证摘要

驱动干净启动，`fluffosb` 走完整注册流程（GB 选择→id→中文名"秦
风"→临时密码→天赋确认→性别）后确认 `目前权限：(admin)`，`update
/adm/daemons/logind` 成功验证真实写入权限，现场未观察到编译警告
泄漏（确认 log_error 修复生效）。踢掉重复登录重连路径现场验证通过
（见上）。`debug.log` 全程干净（196 行，无真实错误）。

### 本轮修改的文件

- `config.fluffos`
- `work/adm/daemons/securd.lpc`
- `work/adm/obj/master.lpc`
- `work/adm/simul_efun/file.lpc`
- `work/cmds/ang/update.lpc`

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/inherit/room/room"`：删除 792 处多余的、独立成行的
`replace_program(ROOM);`（保留 `inherit ROOM;`），与 `xxcqii`/
`xxcqii2` 同一血统同一形状（本档案是它们的祖先/同系原始档案）。
`clone/misc/roommaker.lpc` 同样有两套模板——"造一间空房间"的
heredoc 本来干净，"克隆我所在的房间"命令的字符串拼接模板把同一枚
多余的 `replace_program(ROOM);` 烤进了每一个新克隆的房间，已同步
修正。已用 `build-debug` 驱动干净启动验证（0 个新增编译错误，端
口正常监听；启动时的 `domain_stats`/`author_stats` 统计文件缺失
警告是预先存在的良性提示）；未做完整 §10.7 深度游玩测试。
- `work/clone/user/user.lpc`

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
