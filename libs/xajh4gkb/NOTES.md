
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
