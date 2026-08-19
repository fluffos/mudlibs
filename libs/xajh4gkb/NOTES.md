
## WASM 修复摘要（迁移自 meta.json 的 group_note）

笑傲江湖Ⅳ（公开版），游戏内品牌「夕阳再现」，是在"炎龙"代码核心基础上的第四代分支。在 WASM 下启动并完整完成注册，没有任何编译或运行时错误——没有发现任何 LPC bug。唯一采取的行动：把 fluffos (admin) 播种进 adm/etc/wizlist（已有两个 (boss) 级创始人账号——afei/tianya；wiz_levels 顶层是 (ceo) > (boss) > (admin)，但 (admin) 按 trusted_write 已经能获得完整的 '/' 写入权限，和本轮惯例一致；SECURITY_D 正确指向 /adm/daemons/securityd，globals.h 里有一条注释掉的 '// #define SECURITY_D "/adm/daemons/securd"' 诱饵提醒但未生效）。注册流程在一次连续的 WASM 客户端会话里完整验证过：英文 id→y/n 创建确认→中文名字→密码+确认→一个独立的"身份标识"（用于自杀/找回密码）+确认→天赋数值选择（0 为随机，y 接受）→电子邮件（需要 id@address 格式）→性别→带着完整角色属性表进入游戏世界，包括一串自定义地图协议标记（'lbadd0'/'lbclear0' 等，无害的客户端标记，不是错误），全程没有任何意外错误。管理员权限已直接通过游戏内横幅"★ 您目前的权限：(admin)"确认。LPC 格式化工具对全部 16167 个档案运行（写入 16133 个，4 个报错，30 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。全部 4 个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。

## 深度功能测试（§10.7，2026-08-05）

WASM 阶段"没有发现任何 LPC bug"的结论**基本站得住**（没有发现代码逻辑
bug），但深挖发现了一个会在普通游玩中反复打断玩家的资源限制配置问
题，此前从未被触发过，因为 WASM 阶段的测试范围只到"完成注册"为止，
没有继续在世界里走动。

- **`maximum evaluation cost` 配置过低，导致新角色/新房间在正常移动
  中反复触发"Too long evaluation"中断**：用测试账号 `testrole`/王五
  注册后，仅仅是最基本的移动（`w`/`n`/`fly yz` 等，走进从未被访问过、
  需要懒编译的新房间/新 NPC）就反复触发全局 `error_handler()`，普通
  玩家看到的是"这里发现了臭虫，请用 SOS 指令将详细情况报告给巫师。"
  （`debug.log` 里对应的是 `*Too long evaluation. Execution aborted.`，
  `Eval interrupted: ... limit: 700000 usec.`）。追踪了几条完整调用
  链（`d/city/npc/scavenger.lpc`/`bing.lpc`/`quest/weiguo/japan/
  japan2.lpc` 的 `create()` → `char.lpc` 的 `setup()` → `feature/
  skill.lpc` 的 `set_skill()` → ACL 的 `file_size()`/`valid_read()`
  检查），没有找到单一"哪一行本身特别贵"的孤立逻辑 bug——比较像是
  "这份档案的 NPC 创建链条（`create()` 里显式设置技能，`setup()` 里
  `2017.8.5阿飞改` 那段"统一重置NPC技能"又把同样的技能全部 `set_skill()`
  一遍）本身开销不小，而 `config.fluffos` 的 `maximum evaluation cost`
  只有 700000（这个项目里大多数档案的默认值，但明显对这份档案的内容
  规模不够用）"。这类"旧配置数值和实际内容规模对不上"的问题在
  AGENTS.md 里已经有先例（§7.87 的存档文件大小限制），这次是同一类问
  题在"单次函数呼叫允许的执行开销"这个维度上的体现。已把 `maximum
  evaluation cost` 从 700000 提到 5000000（这个项目里另外 30 份档案已
  经在用的数值，比默认值宽松但不算离谱）。live 验证：修复前，反复
  `w`/`n`/`fly yz;w;n;w` 这条固定路径必现多次"臭虫"崩溃；提高限制并
  重启驱动后，同一条路径、同一个已存档角色，连续 12 步移动（含之前必
  现崩溃的那条路径）零次触发，`debug.log` 里也不再出现任何 `cost
  limit reached`。
- **战斗测试**：在北大街对成名 NPC 郭靖发起 `kill`，多回合拳脚攻防正
  常（命中/闪避判定、"飞龙在天"技能描述），郭靖一记重击（42871 点瘀
  伤）直接将测试角色打死——伤害数值、"半昏迷"→"死了"的过渡文字、死
  亡后自动生成尸体并移动到"鬼门关"，全程正常。
- **死亡/复活测试完整走通**：鬼门关的"白无常"NPC 通过 `call_out` 驱
  动的一连串独白（"喂！新来的，你叫什么名字？"→...→"阳寿未尽？怎么可
  能？"→"罢了罢了，你走吧。"）自动完成判定，不需要玩家手动输入姓名
  应答（对它 `王五` 直接回复"什么？"，属于对话不接受自由文本输入的
  正常行为，不是 bug），几秒后自动把角色送回死亡地点附近的"武庙"，
  `score` 确认死亡计数 +1、"最后杀你者"正确记录为郭靖，全程未受
  §7.68 类问题打扰（未做任何改动，AGENTS.md 现已收窄该guard-retry修
  法为仅 `bmxkx2001` 适用）。
- **留言板 `post` 崩溃（§7.86）不适用**：武庙的"臭虫留言板"（巧合地
  和上面那个 bug 同名）live 实测发帖成功，无崩溃。
- **§7.5/§8.9/§8.3a/§8.3b 均不适用**：ACL 已在 WASM 阶段确认正常；
  未观察到食物/饮水年龄判断相关问题（这份档案的 `score` 面板不直接展
  示食物/饮水条，本次未做进一步的专项排查）；注册后所有指令均正常
  响应。
- **本次未测试**：拜师门派、商店购物、组队巡街、日本神户跨海区域、
  杀手楼路线。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 62 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对升级后的驱动（`quest_times`/`win_times` `%`-operator 修复 +
Warning/warning 大小写驱动兼容回退）做的第二轮 §10.7 重测。`config.fluffos`
里 round one 的 `maximum evaluation cost`（700000→5000000）修复仍
然在位，重测期间移动未再触发"Too long evaluation"崩溃。

### 发现并修复的 PROGRAMMING bug

1. **`log_error()`（`adm/obj/master.lpc`）完全没有严重度检查
   （AGENTS.md §7.103 的又一确认实例）**：`if (this_player(1))
   efun::write("编译时段错误：" + message + "\n");`——任何一次编译警
   告（不只是真正的错误）都会原样丢给当前连线玩家，包括普通玩家在
   正常游玩中触发的懒编译警告。修复：加上大小写不敏感的
   `strsrch(message, "arning:") == -1` 判断，与本项目现行惯例一致。
2. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class）**：`write_file(LOG_DIR + file, text)`
   前没有先建目录，而 `assure_file()` 恰好就定义在同一个文件里稍后
   的位置。全档案所有 `log_file()` 调用点（`feature/command.lpc`、
   `feature/condition.lpc`、`feature/move.lpc`、`feature/autoload.lpc`、
   `inherit/char/npcsave.lpc`、多个 `d/`/`clone/` 下的调用点等）都经
   由这个 simul_efun，一次性全部修复。修复：`assure_file(LOG_DIR +
   file); write_file(LOG_DIR + file, text);`，并在文件顶部加了
   `void assure_file(string file);` 前向声明（`assure_file()` 定义在
   `log_file()` 之后，这个驱动不做前向解析）。
3. **`adm/daemons/logind.lpc` 里两处遗留的 `printf("%O\n", ob);` 调
   试残留（AGENTS.md §7.34 的形状）**：分别在"确认中文名字后进入密
   码设置"的两条并行分支（手动输入名字 `get_name()`、接受随机名字
   `get_resp()`）里，每次注册确认名字后都会原样把 `ob` 的
   `file_name`（如 `/clone/user/login#18`）打印给玩家——live 实测已
   确认复现（用测试号 `gktestqq` 注册时屏幕上出现了裸的
   `/clone/user/login#18`）。两处均已删除该行，只保留紧邻的
   `ob->set("name", ...)`。同目录下还有一份 `logind碎梦.lpc`，含相
   同形状的调试残留，但确认全档案没有任何地方 `inherit`/`call` 它
   ——是未接入编译树的废弃备份文件，未做改动。

### §5/dbase.lpc 密码守卫检查：不适用

`feature/dbase.lpc` 的 `set(prop, data)` 是纯粹的无守卫赋值，没有任
何 `wizhood()`/`password` 相关的特殊分支，跟 tybxjh/wlhd 那个类的
bug 形状完全不同。也没有单独的 `ad_password` 密码守卫代码路径。

### 管理员播种验证：round one 的 wizlist 条目此前没有对应存档

`adm/etc/wizlist` 里 `fluffos (admin)` 这一条 round one 就已写入，
但 `data/login/f/`、`data/user/f/` 下都没有 `fluffos.o`——和本次重
测系列里其他几个 lib 遇到的情况一样，"wizlist 里看起来对"但从未真
正走过一次注册流程留下真实存档。本轮用 `fluffos` 这个 id 走了一次
完整注册（英文 id→y/n 创建确认→中文名"王五测"→密码
`testpass123`+确认→身份标识+确认→天赋 0 随机→邮箱
`fluffos@example.com`（`id@domain` 格式）→性别 m→进入游戏世界），
入世后游戏内横幅确认 `★ 您目前的权限：(admin)`，`score` 面板头衔显
示"天界总管"。**强制验证步骤**：`quit` 断线后重新连接，输入
`fluffos`/`testpass123` 完成一次真正的断线重连，密码验证通过，管理
员权限保持 (admin)——不是只看世界进入和权限横幅就下结论，是真正做
了断线-密码-重连这一步。新产生的 `data/login/f/fluffos.o`、
`data/user/f/fluffos.o` 已提交，`fluffos` 现在是真正可用的种子管理
员账号。

### 移动/驱动兼容性检查

`kedian`→`south`→`up`→`north` 往返移动多次未触发任何"Too long
evaluation"崩溃或其他异常，`debug.log` 全程只有一条无关紧要的编译期
`Unused local variable 'time'` 警告（preload 阶段产生，未连线玩家，
不受 §7.103 修复影响也无需影响）。

### `quest_times`/`win_times` `%`-operator 修复：抽查确认在位

`d/city2/npc/refereew.lpc` 现有 `to_int(query("win_times")) % 5`，
是corpus-wide 2026-08-12 sweep（commit `c571a53629f`）已经打过补丁
的写法，无需额外改动。

### 未在本轮测试

拜师门派、商店购物、完整战斗到死亡/复活循环（round one 已用测试号
`testrole`/王五在北大街对郭靖打过一次完整的死亡/复活循环，本轮认为
不需要重复；本轮重点是驱动升级后的回归检查 + 正常游玩中顺手发现的
bug）。

## 深度功能测试（2026-08-19，round four，补测此前五项未测系统）

针对 round one/two 均标注"本次未测试"的五个系统做的专项补测：拜师门派、
商店购物、组队巡街、日本神户跨海区域、杀手楼路线。用全新测试号
`rfourtest`/肆轮测在真实驱动（`~/src/fluffos/build-debug/src/driver`，
`build`(ASAN/UBSAN) 目录在本机会因 `evthread_use_pthreads` 内的一条
非法指令直接崩溃，与本 lib 代码无关，改用 `build-debug` 正常启动）上
完整走完注册流程，全程通过 `nc localhost 40154`（而非 telnet，避免
telnet IAC 转义误报）驱动。**全程 `debug.log` 始终为空文件，没有任何
一条编译/运行时错误**——五项系统的机制本身均可正常触达和运行，没有
发现任何需要修复的 PROGRAMMING bug。

1. **拜师门派**：找到新手盟教练 NPC「阿飞」(`d/new/npc/xinshou-afei.lpc`
   ，位于 `fly new` → `northwest`)，`bai xinshou afei`（注意：`set_name`
   的 id 是整个 `"xinshou afei"` 字符串，单独 `bai afei` 找不到人，属于
   命名习惯不是 bug）。以零级新号身份尝试，`cmds/skill/apprentice.lpc`
   的等级门槛检查正常触发，返回"阿飞斜眼瞟了你一眼，就你这种实力还想拜
   师？我不收无能之人。"——机制本身（`feature/apprentice.lpc` 的
   `attempt_apprentice`/`recruit_apprentice`）正常运行，用合理理由拒绝，
   属于干净通过（EITHER 接受或拒绝都算通过，见任务范围说明）。**顺手
   观察，未改动**：`kungfu/class/huashan/yue-buqun.lpc` 里
   `recruit_apprentice()` 覆写用 `add("apprentice_availavble", -1)`（拼写
   错误，多了个 `v`），实际字段名是 `apprentice_available`——这个 typo
   使得该 NPC 的"招满三个弟子就不再收徒"计数永远不会真正递减，可能是一
   个真实的编程 bug（变量名打错），但没有观察到任何报错或崩溃，且是否
   "应该限流收徒"本身是设计意图问题，按标准审慎存疑不动，仅记录在案。
2. **商店购物**：`fly yz` 进城后经 `西大街→中央广场→东大街→杂货铺`（或
   `d/city/zahuopu.lpc`，`杨永福` 老板，`inherit F_VENDOR`* 类似的自定义
   `do_buy`/`list`）完成一次真实购买：`list` 正常列出货物表，`buy budai`
   成功购得"麻布袋"一个，扣款/发货全部正常，无任何报错。未测试卖出（按
   `hell` 教训，不同 NPC 是否收购属于内容设计，不在没有报错的情况下当
   bug 处理）。
3. **组队巡街**：`team found rfourteam` 得到明确的拒绝提示——"鉴于组队
   没任何用处，巫师关闭组队功能。"——这是巫师主动关闭的、带清晰理由的
   拒绝，机制本身运行正常，不是 bug。进一步代码走查发现这与"组队巡街"
   的抓奸细任务（`quest/kangwo/teamjob.lpc` 的 `ask_jianxi()`：要求
   2-4 人组队，随机分派到某条街道设伏拦截"日本奸细"，正是"组队+巡街"
   的字面对应）是一致的：该任务函数唯一被 `#include` 的宿主 NPC
   `quest/hyhusong/wang.lpc`（王坚，泉州守备）的整个 `inquiry` 映射表都
   被注释掉了（连 `job`/`fangqi` 等其他条目也一并注释），也没有其他任何
   活跃代码路径调用 `ask_jianxi()`。也就是说该任务在当前档案里完全没有
   入口——但这和"组队"功能被巫师主动关闭一样，属于内容被有意停用/未完
   工，没有任何报错，符合"内容缺失可能是有意为之"的判断标准，未改动。
4. **日本神户跨海区域**：确认可达，且有两条独立路径：(a) `fly dy` 直达
   `/d/japan/zhongxin.lpc`（"这里是神户的中心"）；(b) 真实航海路径
   `d/quanzhou/haigang2.lpc`（"城外海港，有商船前往东瀛"）`enter chuan`
   → `/d/feitian/dahai`（有几率遭遇倭寇海盗）→ 20-50 秒后 `rfeitian()`
   送达 `/d/japan/haigang.lpc`；日本境内另有 `/d/gaoli/gangkou.lpc`
   （高丽港口）到日本、日本到高丽的对向航线。本轮走了 (a) 路线并在神户
   境内 `市中心→east→街道`（当铺/铁匠铺子）继续走了一步，房间/出口/
   描述均正常加载，无任何错误。
5. **杀手楼路线**：`fly ssl` 直达 `/d/shashou/enterance.lpc`（"杀手楼大
   门"），沿 `north→north→north` 连续穿过"小路"→"枫林"→"校场"（杀手楼
   校场，含留言板），全程四个房间连续加载、出口正常、无任何报错。

### 标准清单巡检（§7.90/§7.111/§7.112/§7.113/§7.114/§7.115）：全部确认在位/不适用

- **§7.90**：`config.fluffos` 的 `maximum evaluation cost` 确认为
  `5000000`（round one 已修复的值），在位。
- **§7.111**：`adm/obj/master.lpc` 里 `error["object"] ? file_name(error
  ["object"]) : "0"` guard 确认在位。
- **§7.112**：`d/death/npc/wgargoyle.lpc`/`bgargoyle.lpc` 的 `init()` 均
  有 `death_stage_active` temp 标记防重入 guard，确认在位。
- **§7.113**：`LOGIN_D` 指向 `adm/daemons/logind.lpc`，其 `reconnect()`
  调用 `user->reconnect()`；`clone/user/user.lpc::reconnect()` 内
  `set_heart_beat(1)` 在正确的 `this_object()==user` 语境下无条件执行，
  是已知的"正确谱系"写法，确认在位。
- **§7.114**：`feature/edit.lpc` 的 `input_line()` 没有 `private` 修饰，
  该 bug 形状不适用于这份档案。
- **§7.115**：`include/globals.h` 里 `#define QUEST "/inherit/quest"` 指
  向的 `inherit/quest.lpc` 文件真实存在且实现完整（`quest_give`/
  `quest_ask`/`quest_kill`），不是像 `aoxiangtianji` 那样指向不存在的文
  件，不适用。

### 测试环境说明

`~/src/fluffos/build` (ASAN/UBSAN 编译) 在本机启动时于
`evthread_use_pthreads()` 内直接 `Illegal instruction` 崩溃（与 mudlib
代码无关的驱动/环境问题），改用 `~/src/fluffos/build-debug` 正常启动，
干净监听 40154 端口，`Initializations complete.`。测试全程用
`nc localhost 40154`（tmux 会话）而非 telnet，避免 telnet IAC 转义把
中文字节误判为控制序列导致的假阳性。测试号 `rfourtest`/肆轮测已在
`quit` 时被游戏自身的"半小时内退出自动删号"机制清理，`data/login/`、
`data/user/` 下未留下任何新存档，`git status` 确认无新增/改动文件。

## AGENTS.md §7.100 修复（2026-08-19）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：本 lib 4745 个房间文件的 `create()` 末尾（紧跟 `inherit
ROOM;`）都有这一行多余调用，第一次对该房间对象绑定闭包会永久失败。
同款地雷也烤进了自带建房工具 `clone/misc/roommaker.lpc` 的字符串拼
接代码生成模板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上 roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：
4746 files changed, 1 insertion(+), 4747 deletions(-)，与预期精确吻
合。

验证：`build-debug` 驱动真实冷启动，端口 40154 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`testpass123`（本文
件上方记录）登录正常，`goto` 走访 14 个刚修复的房间（`d/migong`/
`d/wizard`/`d/xiangyang`/`d/qingcheng`/`d/baituo`/`d/city`/
`d/zhongzhou`/`d/wanjiegu`/`d/wudang`），均无 "cannot replace"/
"cannot bind" 新增日志行。走访过程中顺带遇到两个与本次修复无关的既
有问题：`/d/migong/lev7/dong47` 一场 NPC 战斗把测试角色打死（正常
游戏机制，非 bug）；`/d/wudang/bolin` 的 NPC
（`kungfu/class/wudang/famu.lpc`）`create()` 里呼叫
`carry_object()` 抛出 "*Read access denied."——均已确认与
`replace_program(ROOM)` 无关，不在本次修复范围内，如实记录未修。按
精确 PID 结束驱动；测试期间产生的 `fluffos` 存档增量（登录计数器 +
死亡状态）已 `git checkout --` 还原。
