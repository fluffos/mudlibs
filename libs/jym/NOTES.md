
## WASM 修复摘要（迁移自 meta.json 的 group_note）

完成了一次中断的转档（多个档案，包括 master.lpc，残留有 static 关键字）；用 read_file+explode+slice 重新实现了 efun::tail()（§6.2）；启动干净。完整 WASM 修复：给 band.lpc 加了本地回环放行；修复了 logind.lpc（create()/make_body()/howmany_user() 都改成 seteuid(ROOT_UID)）里同样的 seteuid(getuid()) 把 euid 重置掉的 bug；修复了 check_legal_name() 过时的 GBK 字节长度界限，去掉了一个毫无意义的 name[j]+=128 变异操作（旧版 GBK 高位字节假设的遗留代码）；给 adm/daemons/securityd.lpc 的 get_status() 加上了防止 wiz_status/wiz_levels 尚未初始化时重入编译崩溃的保护。发现了两个新 bug：cmds/usr/quit.lpc 呼叫 environment(me)->query(...) 没做保护，玩家在环境为空时退出游戏就会崩溃报"*Bad argument 1 to call_other()"（已给全部三处呼叫点加上保护）；adm/simul_efun/message.lpc 的 tell_room(ob,str,exclude) 包装函式把省略的可变参数 exclude 直接以裸整数 0 传给 message() 的第 4 个参数，而不是空数组——导致游戏里第一次 tell_room() 呼叫（欢迎室自己的 create()）就崩溃，这是已收录进 AGENTS.md §7.12 的共享包装函式 bug，已用文档记载的 exclude || ({}) 写法修复。管理员账号播种进了 data/securityd.o 的 wiz_status 映射（这里是 CRLF 配对编码，不是 hy/hy5 那条血统里的纯 CR 逐键编码——出于保险仍用二进制模式编辑）。注册流程到进入游戏世界、look/score/quit、管理员权限识别都干净验证过，没有残留的横幅计时问题。

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到"注册→look/score/quit→管理员权限识别"的浅层冒烟测
试。本轮在 boot 之前先主动检查了本次会话已经在 `hell`/`zsdsj` 上反
复确认过的两类高价值 bug 模式，直接在源码里发现并提前修复了一处，
随后完整走通了注册、门派加入、`quit` 全流程。

### 主动排查发现并修复：`feature/command.lpc` 的 `private command_hook`

`feature/command.lpc`（`inherit/char/char.lpc` 通过 `F_COMMAND` 继
承，是真正生效的玩家指令分发中枢）把 `command_hook` 声明为
`private nomask int command_hook(string arg)`。这是 AGENTS.md §8.3a
已经记录多次的经典模式：这个驱动上 `private` 一旦被继承就会降级为
`DECL_HIDDEN`，导致 `add_action("command_hook", "", 1)` 这种"捕获全
部指令"的注册方式对 `ORIGIN_EFUN`（其它物件透过 `command()` efun
发起的呼叫，比如 NPC 自己说话）静默失效。已去掉 `private`，保留
`nomask`，和已确立的标准修法一致。

另有一份 `feature/command2.lpc` 也带有完全相同的 `private nomask
command_hook` 声明，但确认它是死代码——全代码库里唯一提到
"command2" 的地方是 `log/static/editfile.lpc`（这不是真正的 LPC 源
码，是一份历史巫师编辑记录日志，纯文本"某巫师在某时间编辑了某文件"
的流水账，文件名后缀 `.lpc` 是历史遗留的误用），没有任何 `inherit`
真正引用 `feature/command2.lpc`——保持原样未做改动，符合"死代码备
份保持原样"的既有惯例。

### 完整验证：从注册到加入门派

用全新账号在原生驱动上完整走通：GB 编码（默认）→ 英文 id（3-8 个
英文字母，注意上限只有 8 个字符，比很多同类档案的 10-12 上限更
严）→ y 确认建立 → 中文名字（1-4 个汉字）→ 使用密码 + 确认 → **保
密密码**（至少 10 位，与使用密码是完全独立的第二套密码，专门用于
密码找回）+ 确认 → 天赋选择（0-4，0 为系统随机，随机结果需要 y/n
二次确认，不满意可以重新摇）→ 电子邮件 → 性别 → 进入"新手的殿堂"。

一进入新手殿堂就有 [1;33m金庸[37;0m（作者本人被拟人化成一个 NPC！）
主动搭话："欢迎光临本ＭＵＤ，本人现在将助你一臂之力"，并列出全部
12 个可加入的门派：丐帮、全真教、武当派、华山派、密宗、星宿派、
白驼山庄、桃花岛、少林派、峨眉派、大理段氏、灵鹫宫——同样是把金庸
小说宇宙里跨多部作品的门派体系（射雕/神雕的全真教丐帮、天龙八部的
星宿派大理段氏灵鹫宫白驼山庄、笑傲江湖的华山派、倚天屠龙记的少林
武当峨眉）揉进同一个游戏世界。`join wudang` 立即成功，触发一条全服
公共频道广播"在下承蒙金庸先生帮助，现已加入武当派！"，金庸 NPC 确
认"现在我已经给你帮助了"，"身体更新完毕"——这一整条 NPC 对话+全服
广播链路，正是 `command_hook` bug 最容易静默破坏的那一类
`command()`-efun 自呼叫路径，本轮完整验证无异常，间接印证了上面那
处修复的必要性。`score` 显示完整角色面板（膂力/悟性/根骨/身法四项
天赋、精/气/食物/饮水四条状态槽全部正确显示，饮水槽满格，没有类似
`zsdsj` 那种初始化缺失的问题）。`quit` 正常触发"开始退出游戏，进行
中..."流程。debug.log 除了驱动自身的启动期诊断信息（找不到旧版二
进制、反向地址解析被拒绝，均为环境噪音，不影响功能）外没有任何来自
本次实际游玩会话的运行时错误。

### 未覆盖范围（诚实说明）

预算集中在验证 `command_hook` 修复的必要性和门派加入这条最容易受
影响的 NPC 对话链路，没有走到：门派内部技能学习、战斗、经济系统。
这些留给下一轮，目前的验证边界如上所述。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Round three deep functional test（2026-08-18）

本轮预算集中在第二轮明确留白的范围：门派内技能/经济/留言板/死亡复活，
并主动排查了当天新收录的两类 bug 模式（AGENTS.md §7.111、§7.112）。

### §7.111（`master.lpc` 的 `standard_trace()` 无条件呼叫 `file_name()`）：不适用

本档案真正生效的 master 是 `adm/single/master/master.lpc`（config.fluffos
的 `master file` 指向这里，`adm/single/master.lpc` 是未使用的旁支）。
它的 `standard_trace()` 用 `%O` 格式化 `error["object"]`，不是无条件
`file_name()`，`%O` 对 0/非物件值都是安全的。确认不受影响，未改动。

### §7.112（NPC `init()` 无守卫地排 `call_out()` 链，重连会叠加第二条链）：命中并修复

`d/death/npc/wgargoyle.lpc`、`wgargoyle1.lpc`、`bgargoyle.lpc`（鬼门关/
酆都城门的白无常、黑无常）三个死亡引导 NPC 的 `init()` 都是这个形状：
`if (!previous_object() || !userp(...) || wizardp(...)) return; call_out("death_stage", 30, previous_object(), 0);`
——没有任何防止玩家重连时 `init()` 被驱动重新广播、从而叠加第二条独立
`death_stage` 链的守卫。三个文件都按文档记载的修法加了
`previous_object()->query_temp("death_stage_active")` 守卫（`init()`
里排 `call_out` 前检查+置位），并在 `death_stage()` 的每个出口
（含 `bgargoyle` 特有的"阳人闯阴间被赶出"分支）用
`delete_temp("death_stage_active")` 清除。

现场验证（用 `eval` 直接检查 `call_out_info()`）：admin 把测试号
summon 进鬼门关，白无常 `init()` 触发，`call_out_info()` 只有一条
`death_stage` 记录（守卫已置位）；随后让该测试号断线重连（触发
`enable_commands()` 重新广播 `init()`），再查 `call_out_info()`——
仍然只有一条链在推进，没有叠加第二条。链走完后守卫标志正确清零
（`query_temp` 归零），玩家被移到 `/d/city/wumiao`（`REVIVE_ROOM`）
恰好一次，全程 debug.log 无报错。

### 主动排查发现并修复两处严重程序缺陷（非目录里的两类模式，是本库独有）

1. **`adm/daemons/logind.lpc` 的 `enter_world()` 里 `ob->save()` 被注
   释掉**（第 907 行，原文 `//        ob->save();`）——新角色完成注册
   后，登入身份物件（`data/login/<首字母>/<id>.o`，含密码/保密密码/
   email/`registered` 等字段）**从未被存盘**，除非玩家恰好从设了
   `valid_startroom` 的房间正常 `quit`（会走 `cmds/usr/quit.lpc` 里
   `link_ob->save()` 的立即存盘分支），或者等到 `autosaved.lpc` 的
   8~108 分钟一轮的心跳存盘赶上。新手殿堂（`d/welcome/welcome.lpc`）
   本身没设 `valid_startroom`（该行被注释掉了），所以任何在离开新手
   殿堂之前断线/退出的新号，登入身份**永久丢失**——下次再用同一个
   id 登入，系统会误判"账号不存在"，提示重新创建新角色（角色本体
   `data/user/...` 即使侥幸存在也对不上）。这也解释了为什么本库此前
   两轮播种的 `fluffos` 管理员账号在本轮开始时已经完全消失（`data/
   login/f/` 和 `data/user/f/` 都没有档案，只剩 `securityd.o` 里的
   `wiz_status` 授权记录）。修法：去掉注释，让 `ob->save()` 在
   `enter_world()` 里无条件执行（新号和回头客都会跑到这一行，无害）。
   现场验证：修复前，全新注册号在没跳出新手殿堂时 quit 后无法用原密
   码重新登入（提示创建新号）；修复后，同样流程的全新注册号可以立
   刻正常重连（提示"你距上次退出仅N秒，请稍后再登陆"的防刷屏节流，
   证明账号被正确识别）。已按 AGENTS.md §1.5 惯例用标准凭证
   `fluffos`/`Mud@2026` 重新走完整注册流程播种管理员账号（`data/
   login/f/fluffos.o`、`data/user/f/fluffos.o` 都已就位，`wiz_status`
   授权原本就还在），此账号文件已提交。

2. **`include/globals.h`（驱动 `global include file` 自动包含给所有
   源文件的全域头）缺少 `EDITOR_D` 宏定义**——`inherit/misc/bboard.lpc`
   （`BULLETIN_BOARD` 的实现，被所有留言板 clone 继承）第 304 行用到
   `EDITOR_D->get_file_num(...)`，但这个宏只在另一个不会被自动包含
   的旁支头文件 `inherit/misc/globals.h` 里定义过，导致 `bboard.lpc`
   编译失败（`Error: Undefined variable 'EDITOR_D'`）。后果两层：(a)
   任何驻留留言板 clone（如客店的 `kedian_b`）的房间，第一次在某次
   驱动会话里被访问、触发房间 `create()` 尝试 clone 留言板对象时，会
   因为 clone 物件"没有程式"而抛出未捕获运行时错误，导致移动指令
   （如新手殿堂的 `down`）整体中断——当事玩家会卡在原地，只看到"你
   发现事情不大对了"的模糊提示，摸不着头脑（第二个及以后访问同一房
   间的玩家不受影响，因为房间物件已经在内存里创建过一次，不会重新
   触发）；(b) 全档案所有留言板永久性地没有实际留言板物件可用，
   `list`/`post`/`read` 全部静默失效——客店留言板还原后一次性找回了
   189 条 2007 年的历史留言（此前完全无法访问）。修法：在
   `include/globals.h` 里按字母序补上
   `#define EDITOR_D "/adm/daemons/editord"`（与 `inherit/misc/
   globals.h` 里的定义完全一致，`/adm/daemons/editord.lpc` 本来就存
   在）。现场验证：修复前，全新驱动会话里第一个走 `down` 的号必然
   触发上述崩溃；修复后，同样全新驱动会话里第一个走 `down` 的号顺利
   进客店，`list` 能看到 189 条历史留言。

### 其余深度测试

`join wudang` 门派加入本轮再次复核无误（与第二轮一致）。留言板
list/post 流程在客店验证可用（`list` 走分页，`ENTER`/`q`/`b` 翻页；
未继续测 post/discard 全流程，范围已覆盖到功能修复所需的最低验证）。
死亡复活链路（白无常/黑无常引导流程）已在上面 §7.112 段落里连同守
卫修复一起验证。经济系统（铁匠铺等商店 `list`/`buy`）、门派内技能学
习/PK 战斗仍未覆盖，留给下一轮。

### 潜在跨库线索（未在本库外验证，仅标记）

`logind.lpc` 里 `enter_world()` 缺失 `ob->save()` 这个具体行号可能是
本库独有的历史误删，但"新号未经由 `valid_startroom` 房间正常退出就
会丢失登入凭证"这类问题的**排查方法**（检查 `enter_world`/等价函式
里是否存在被注释掉的登入物件 `save()` 调用）值得在其它库round-three
测试中留意，尤其是那些新手初始房间没设 `valid_startroom` 的血统。

## §7.100 修复（`ROOM` 基类的同一"多余 replace_program()"形状，全档案扫描第 6 批）

- 删除 `work/` 下 2,661 处存活的 standalone `replace_program(ROOM);` 行
  （脚本删除），另外手工修复 `clone/misc/roommaker.lpc` 建房工具代码
  生成模板里的同形状变体，共 2,662 处，与普查记录一致。
- 验证：真实 `build-debug` 驱动干净开机、端口正常监听，`debug.log` 中
  零 "cannot replace"/"cannot bind" 行。

## Round four deep functional test（2026-08-19）

本轮专门补完第三轮明确留白的三大系统：战斗、门派内技能学习、经济系
统（铁匠铺 list/buy）。全程用真实 `build-debug` 驱动 + 全新注册测试
号（`rfourjym`）+ admin（`fluffos`）双连线协同测试（`goto`/`summon`/
`eval` 辅助定位与状态调整），驱动全程干净，`debug.log` 除编译期警告
外零运行时错误。三项全部验证通过，**没有发现任何真实程序 bug**。

### 1. 战斗：通过

在武当柏林用新号空手攻击「野兔」（`d/wudang/npc/yetu.lpc`），完整走
完多回合攻防：命中/招架/闪避描述随机切换，野兔的状态提示逐步升级
（"力不从心" → "半昏迷" → 摔倒 → 死亡），死亡触发 `die()` 正确清除
物件并生成"兔肉"战利品，全程无崩溃、无 debug.log 报错。

### 2. 门派内技能学习：通过

已知加入武当派（`join wudang`）的角色，其 `family/master_id` 是欢迎
室里"金庸"NPC（`d/welcome/npc/shizhe.lpc`）自己，而这个 NPC 没有设
置任何 `set_skill()`，所以理论上无法直接向他 `learn`。真正的门派内
授业 NPC 是 `kungfu/class/wudang/*.lpc` 这批角色（通过 `CLASS_D`
宏放置在 `d/wudang/sanqingdian.lpc` 等房间里，例如宋远桥、谷虚道
长、张三丰），都用 `bai <NPC>` 拜师、`ob->attempt_apprentice()` 里
按 `taiji-shengong` 内功等级 + `shen`（声望）双重门槛决定是否收徒，
门槛因人而异（宋远桥最低：`taiji-shengong>=60` 且 `shen>=35000`）。

刚 `join wudang` 的新号 `shen` 只有 30000，天然差 5000 达不到宋远桥
门槛——这是**内容/设计门槛，不是 bug**，符合本项目已反复确认的"声
望/等级门槛拒绝求教"模式。为了验证 `bai`/`recruit_apprentice`/
`learn`/`is_apprentice_of` 这条机制本身是否work，用 admin `eval`
把测试号的 `shen` 临时提到 40000（纯粹测试用途的状态调整，不是代码
修复）。之后：

- `bai song` → 宋远桥 `attempt_apprentice()` 检查通过 → 自动
  `command("recruit "+id)` → `你跪了下来向宋远桥恭恭敬敬地磕了四个
  响头，叫道：「师父！」恭喜您成为武当派的第三代弟子。`（`family`
  正确更新为 `master_id`=宋远桥、`generation`=3）
- `learn song sword 3` → `你向宋远桥请教有关「基本剑法」的疑问。你
  听了宋远桥的指导，似乎有些心得。` → `skills` 确认 `sword` 技能的
  进度值从 `62/0` 变为 `62/73`（尚未跳级，但确认经验值真实累积）。

途中还观察到 `bai` 指令本身有一个**符合设计**的行为、不是 bug：对
同一 NPC 连续 `bai` 两次，第二次会命中"你想拜XX为师，但是对方还没
有答应"的 pending 分支而不重新触发 `attempt_apprentice()`——必须先
`bai cancel` 清掉 pending 状态才能让门槛检查重新跑一次。这解释了本
轮测试过程中第一次 boost shen 后立刻重试 `bai song` 依然被拒的现
象（当时 pending 状态还压着上一次失败的请求）。机制本身完全正常。

### 3. 经济系统：通过

- **大理铁器铺**（`d/dali/smithshop.lpc`，NPC 南彝商人
  `d/dali/npc/ironsmith.lpc`）：`list` 正确列出菜刀/铁锤及价格；
  `buy hammer` 扣款 150 文（50 两白银 → 48 两白银 + 50 文铜钱），角
  色背包正确收到铁锤。该 NPC 只注册了 `buy`/`list` 两个 `add_action`
  （没有 `sell`），`sell pao` 返回"什么？"——**这是本项目已反复确认
  的"只收不卖"NPC 设计模式，不是 bug**，遵照本轮任务说明未做任何改
  动。
- **京城打铁铺**（`d/city/datiepu.lpc`，NPC 王铁匠
  `d/city/npc/tiejiang.lpc`）：确认这个 NPC 额外注册了
  `do_sell`/`sell`（`feature/dealer.lpc` 标准商人混入），把刚买的
  铁锤 `sell hammer` 成功卖出，`你卖掉了一把铁锤给王铁匠。`，钱包正
  确增加，物品正确移出背包。买卖两条路径均验证通过、无报错。

`inherit/room/hockshop.lpc`（当铺基类）在全档案里没有任何房间
`inherit` 它——是完全未使用的死代码，本档案没有可达的当铺型 NPC，
符合"未使用旁支保持原样"的既有惯例。

### 标准 bug 清单快速复核（全部干净，无异常）

- **§7.90**（eval cost）：`config.fluffos` 的 `maximum evaluation
  cost` 已是 5000000，符合此前扫描修复记录。
- **§7.100**（`ROOM` 冗余 `replace_program()`）：全档案仅剩 9 处，
  全部是已被注释掉的死代码残留（`//	replace_program(ROOM);`），无
  一处存活，符合第 6 批扫描"完全清除"的记录。
- **§7.111**（`master.lpc` `standard_trace()`）：本库真正生效的
  master 用 `%O` 格式化 `error["object"]`，本就安全，不受影响（与
  round-three 记录一致）。
- **§7.112**（NPC `init()` 重连叠加 `call_out` 链）：`wgargoyle.lpc`
  /`wgargoyle1.lpc`/`bgargoyle.lpc` 的 `death_stage_active` 守卫仍
  然完整在位，未被回退。
- **§7.113**（netdead 重连不恢复 `heart_beat`）：`LOGIN_D`
  （`adm/daemons/logind.lpc`）的 `reconnect()` 无条件呼叫
  `user->reconnect()`；`clone/user/user.lpc::reconnect()` 无条件
  `set_heart_beat(1)`——正确血统，不受影响。
- **§7.114**（`private` `input_to()` 回调经 mixin 失效）：
  `feature/edit.lpc`（`F_EDIT`）里的 `input_line()` 根本没有
  `private` 修饰，全档案 grep 也找不到任何 `private ... input_line`
  形状——不受影响。
- **§7.115**（`QUEST` 宏指向不存在的档案）：本库 `include/globals.h`
  /`globals2.h` 都没有定义 `QUEST` 宏，`cmds/std/give.lpc`/
  `ask.lpc` 也完全不引用它——不适用。
- **§7.79**（裸 2 参数 `addn`/`addn_temp`）：全档案 grep
  `addn(`/`addn_temp(` 零命中——本库不存在这个形状，不是新发现。

### 清理

测试号 `rfourjym` 的存档（`data/login/r/rfourjym.o`、
`data/user/r/rfourjym.o`）已在测试结束后删除，不作为常驻测试凭证保
留。驱动进程按精确 PID kill，未使用模式匹配。`work/tmp/`（`eval`
指令写临时文件用的目录，本档案原先没有这个目录）予以保留，纯粹是
运行时基础设施，不含任何游戏状态。
