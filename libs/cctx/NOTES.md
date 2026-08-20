
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2/XKX 血统代码库（襄阳关/嘉峪关场景内容）。完整 WASM 修复：（1）过时的 SIMUL_EFUN_OB 和 MASTER_OB 宏都指向了未被使用的 /adm/single/{master,simul_efun}.lpc 死代码副本，而 config.fluffos 实际使用的 master/simul_efun 文件是 /adm/obj/{master,simul_efun}.lpc（真正的 simul_efun.lpc 带有旧版本缺少的 destruct()/remove() 覆写，和 §7.58 类的 bug 是同一类，在它搞坏 quit 之前就被排查出来了）；（2）adm/daemons/httpd.lpc（纯 HTTP 服务器，无条件调用 socket_*）按 §7.52 的整文件入口点掏空模式处理掉了。排版格式化工具的第三类盲点检查（CJK 重新加空格）在约 40 个"误报"（原文本来就有的装饰性房间名/诗词间距）里抓到了一处真正的损坏：d/huashan/map.lpc（一张密集的 ASCII 地图）——已直接还原，没有手工修补。管理员账号（fluffos/Mud@2026）通过真实注册流程 + adm/etc/wizlist 播种。

## 深度功能测试（第二轮，2026-08-03）

此前的验证只做到浅层冒烟测试。本轮启动前先主动检查了本次会话已经
反复确认过的 `private command_hook` 模式，提前修复了一处；随后完整
走通了注册流程，过程中又发现并修复了两个真实 bug：一处是本会话已
经在别的档案上见过的经典"调试信息泄漏"，另一处是全新发现、已经写
进 AGENTS.md §8.9 的一类新 bug——多物件函式里读错了物件。

### 主动排查发现并修复：`feature/command.lpc` 的 `private command_hook`

和本次会话在 `hell`/`jym` 上已经修过的同一个 AGENTS.md §8.3a 模式：
`inherit/char/char.lpc` 通过 `F_COMMAND` 继承的 `feature/command.lpc`
把 `command_hook` 声明成 `private nomask`，在这个驱动上继承后会降
级为 `DECL_HIDDEN`，导致对 `ORIGIN_EFUN`（NPC 自己用 `command()`
efun 说话）的分发静默失效。启动前 grep 直接命中，已去掉 `private`，
保留 `nomask`。

### 注册流程中发现并修复：`get_name()` 里一行调试用的 `printf("%O", ob)`

`adm/daemons/logind.lpc` 的 `get_name()` 在校验完中文名字之后有一行
`printf("%O\n", ob);`——这是 AGENTS.md §7.34 已经收录的经典模式（
`esI`/`xianlvqiyuan` 都出现过同一类问题）：原作者调试用的物件路径
打印，从未清理就随档案一起流通了出去。实测复现：注册时"您的中文名
字："提示之后，紧接着会看到一行 `/clone/user/login#1`（登录物件自
己的内部路径），然后才是"请设定您的密码："提示——每一个新玩家注册
时都会看到这行内部实现细节。已直接删除这一行，属于 AGENTS.md §7.34
明确记载的"删掉即可，从不服务于任何玩家可见目的"的一类修复，已列入
该条目"确认实例"名单。

### 注册流程中发现并修复：食物/饮水初始化门槛读错了物件（新增 AGENTS.md §8.9）

`adm/daemons/logind.lpc` 的 `enter_world()`（`exec(user, ob)` 之后
的角色进世界流程）里，食物/饮水一次性初始化的判断条件是
`!user->query("food") && !user->query("water") && ob->query("age")
== 14`——链条里前两个条件读的都是 `user`（刚创建的玩家身体物件），
唯独最后一个读的是 `ob`（临时的登录连线物件）。`clone/user/user.lpc`
的 `update_age()`（由 `setup()` 调用，在这个判断之前就已经执行过）
确实会把 `user` 自己的 age 设成 14，但**整个代码库里没有任何地方给
`ob` 这个物件设置过 age**（已通过对全代码库 `set("age"` 逐一核对确
认——所有命中都落在 `user`/NPC 类别上，登录物件类完全没有）。
`ob->query("age")` 因此永远回传驱动默认值 0，判断条件永远为假，
`max_food_capacity()`/`max_water_capacity()` 从未真正套用到任何一
个新角色身上——**每一个全新玩家一进游戏世界食物和饮水槽都是空的**，
第一次 `look`/`score` 就会触发"你饿得直冒金星，实在是顶不住了"的
挨饿提示。已把 `ob->query("age")` 改成 `user->query("age")`，和判断
链条里其它条件保持对象一致。修复前后各注册一个全新角色对照验证：
修复前 `score` 的食物/饮水槽全空，伴随挨饿提示；修复后两条槽全满，
没有挨饿提示。

### 完整验证：从注册到探索

用全新账号在原生驱动上完整走通：英文 id（3-12 个英文字母）→ y 确认
→ 中文名字（无泄漏问题）→ 密码 + 确认 → 天赋确认（y/n）→ 电子邮件
→ 性别 → 进入"欢迎光临驰骋天下"的欢迎室，食物/饮水槽全满（如上）。
`e` 移动到下一个房间，"接客童子"NPC 主动搭话，介绍 eat/drink/get/
buy/sell/sleep 等基本生存指令，并主动提示"如果你没有盘缠的话，可以
问我要"——是一整条 `command()`-efun 驱动的 NPC 对话链路，间接印证
了 `command_hook` 修复的必要性。断线后用同一账号重新登录，"重新连
线完毕"，直接回到游戏内状态，移动/NPC 对话依然正常。`quit` 干净退
出（丢下一件不值钱的布衣，"欢迎下次再来！"）。debug.log 只有驱动启
动期的诊断噪音（找不到旧版二进制路径、反向地址解析被拒绝），没有
来自本次实际游玩会话的运行时错误。

### 未覆盖范围（诚实说明）

预算集中在验证三处修复和基础移动/NPC 对话链路，没有走到：门派拜师、
战斗系统、经济系统（buy/sell/盘缠）。这些留给下一轮，目前的验证边
界如上所述。

## 深度功能测试（第三轮，2026-08-18）——补完经济/战斗，发现并修复一个 §7.11 类新实例（8 个排行榜档案全部写入失败）

补完上一轮留下的门派拜师、战斗系统、经济系统测试，过程中发现并修
复一个此前未被注意到的 §7.11 类 bug。

- **发现：`adm/daemons/toptend.lpc` 的 `topten_save()` 对
  `/topten/*.txt`（8 个排行榜档案：rich/exp/pker/neili/shen1/shen2/
  per1/per2/age）做无保护的 `write_file()`，而档案本身从未打包过
  `/topten/` 这个目录**：`debug.log` 里出现
  "Wrong permissions for opening file /topten/rich.txt for
  overwrite. No such file or directory"，调用链是
  `enter_world()` → `get_gender()`（注册流程最后一步，性别选择）→
  `topten_checkplayer()` → `topten_add()` → `topten_save()`——也就
  是说**每一个新角色注册**都会触发这条写入。好消息是 `topten_save()`
  自己对 `write_file()` 的返回值做了检查（`if (!write_file(...))
  return notify_fail(...)`），所以这不是一个未捕获异常，不会像
  xkyxciii/hhsj 那两个实例一样打断整个注册流程或角色创建——注册、
  进入游戏世界、`look`/`score`/`fight`/`buy`/`sell` 全部正常。但代
  价是：这份档案的排行榜系统（富豪榜/经验榜/PK榜等 8 种排行）从第
  一次开机起就从未真正写入过一条记录，是个悄悄彻底失效的功能。
- **修复**：`adm/simul_efun/file.lpc` 里本来就有的 `assure_file()`
  帮助函式，在 `write_file()` 之前补一行 `assure_file(f_name);`——
  和 AGENTS.md §7.11 已经确立的标准修复手法完全一致。**现场验证**：
  重启全新驱动进程，全新注册一个角色，`debug.log` 里不再出现任何
  "Wrong permissions"/"rich.txt" 记录，`work/topten/` 目录下 8 个
  排行榜档案全部成功创建并写入了内容。
- **经济系统验证**：昆明"聚朋茶馆"的茶小二支持 `list`/`buy`（买到
  一碗大碗茶，正确扣钱、正确加入背包）；南大街"当铺"的老板支持
  `sell`/`value`（对不值钱的物品正确返回"一文不值"，没有崩溃）。
  `list`/`buy`/`sell` 三个指令全程零报错。
- **战斗系统验证**：`help combat` 文档明确的安全切磋指令是 `fight`
  （非致命，打到一方昏迷/认输/逃走为止），不是 `kill`。在"近日古
  楼"对"捕快"使用 `fight bu`，触发真实的攻防交换（命中/闪避描述、
  伤害叙述），本次测试角色落败被打晕（"你的眼前一黑，接著什么也
  不知道了...."），`look`/`score` 在昏迷期间正确地不返回任何输出
  （不是 bug——`help combat` 本身就说明昏迷期间指令会被封锁），过
  一段真实时间后角色自动恢复知觉，`look` 恢复正常。全程符合文档描
  述的设计，没有发现异常。
- **门派拜师未覆盖**：`bai <师傅>`（`cmds/skill/bai.lpc`）需要在同
  一房间内对一个 `query("family")` 非空的 NPC 使用，但确认这类"开
  山立派"的师傅 NPC（通过 `create_family()` 建立门派）散布在
  `d/heimuya`、`d/huashan`、`d/shaolin`、`d/wudang` 等各门
  派专属地图区域，离本轮测试角色所在的昆明新手区有相当距离，本轮
  时间预算内没有找到合理的步行路径。留给下一轮，如果继续测试建议
  直接用巫师账号 `goto` 快速定位一个师傅 NPC 而不是徒步摸索地图。
- 本轮结论：经济系统和战斗系统均验证正常工作，额外发现并修复一个
  真实的、影响所有新角色注册（虽然是非致命的）的排行榜写入失败
  bug。门派拜师系统本身代码逻辑读起来是合理的（`bai.lpc` 有完整的
  错误提示和状态检查），但受限于地图导航复杂度，本轮未能实际验证。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 33 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 第四轮回归测试（2026-08-19）——针对 §7.111/§7.112/§7.113/§7.114/§7.90 逐项核查 + 全新角色完整 §10.7 游玩，结论：全部清洁，无需修复

本轮是在 AGENTS.md 新增 §7.111–§7.114 之后对 `cctx` 做的一次针对性回归，
`cctx` 此前**没有**被 §7.113（netdead 重连不恢复 heart_beat）的两批语料
库扫描覆盖到（不在扫描名单内），因此本轮对这一条做了最仔细的从零核查
和真实存活验证，而不是照抄扫描结论。

- **§7.111（`master.lpc` 的 `standard_trace()` 对 `error["object"]==0`
  未加保护而崩溃）**：`adm/obj/master.lpc`（真正被 `config.fluffos`
  使用的 master 文件）已经是
  `objectp(error["object"]) ? file_name(error["object"]) : "(driver)"`
  的安全写法，早已修复（推测是此前某次 67 库扫描时处理的），本轮**无
  需改动**。
- **§7.112（`init()` 里无保护的 `call_out("death_stage", ...)`，重连时
  `enable_commands()` 重放 `init()` 导致链条重复）**：全档案定位到三
  处 `call_out("death_stage"` 命中——`d/death/npc/wgargoyle.lpc`、
  `d/death/npc/bgargoyle.lpc`、`d/shaolin/npc/yu-zu2.lpc`——逐一检查，
  三处全部已经带有 `query_temp("death_stage_active")` 前置判断 +
  `set_temp`/`delete_temp` 配对保护，**已经是正确写法，无需改动**。
  另外 `d/shenlong/npc/pang.lpc` 虽然文件名貌似相关，实际是完全不同
  的门派宗师 NPC（`join`/`do_skills` 逻辑），与 death_stage 模式无关。
- **§7.113（netdead 重连不恢复 heart_beat，永久性无法自然痊愈的软锁）
  ——本轮重点**：追踪真实的 `LOGIN_D`（`/adm/daemons/logind`）
  `reconnect(object ob, object user, int silent)`：在"同一 id 已经
  netdead"和"confirm_relogin 顶替旧连线"两条分支下都会被调用，且函数
  体里无条件执行 `user->reconnect()`（`->` 跨物件呼叫，`this_object()`
  正确落在玩家身体物件上）。`clone/user/user.lpc` 自己的
  `reconnect()` 则无条件 `set_heart_beat(1)`——链路完全正确，是本项目
  中已经确认过的"正确血统"写法，与另外 62 个已核对过的库一致。
  **现场验证**（不仅仅是静态读码，按任务要求做了真实存活验证）：用全
  新角色 `rfourtst` 注册进游戏，先用 `fight`/`kill` 让角色受伤/陷入
  半昏迷/甚至**真正死亡**（触发 `d/death/npc/wgargoyle.lpc`"白无常"
  完整的 death_stage 判词流程，角色被判"阳寿未尽"送回土地庙复活，是
  这个死亡系统的正常非致命结局，不是 bug），然后用裸 socket 脚本反复
  模拟掉线（不发 `quit`，直接断开 TCP 连线触发 `net_dead()`）→ 等待
  → 用同一账号密码重新连线（触发 `logind.lpc` 的 netdead 重连分支）。
  重连后紧跟着的 `score` 显示 `<精>`/`<气>` 血条仍处于受伤状态（27
  格中 20 格），随后在**同一条连线内**每隔 8 秒重复 `score`：
  t=0s→20/27格，t=8s→24/27格，t=16s→27/27（满血）——血条持续、可观测
  地自然恢复，直接证明 `heart_beat()`→`heal_up()` 在 netdead 重连后
  确实在正常运作，不是"角色仍可操作但心跳已死"的隐蔽软锁。整个测试
  过程中 `debug.log` 没有出现任何运行期报错（只有编译期的
  Unused-local-variable 警告噪音）。**结论：`cctx` 本项不需要修复，
  可以从 §7.113 语料库扫描的"待核查"名单里正式排除。**
- **§7.114（`inherit` 进来的 mixin 里 `input_to()` 回调函数被声明成
  `private` 导致多行输入续行静默失败）**：`feature/edit.lpc` 的
  `input_line(string line, string text, function callback)` 没有加
  `private` 修饰符——即使这份 mixin 是通过 `inherit/char/char.lpc` 的
  `F_EDIT` 间接继承给 `obj`/`clone/user/user.lpc` 使用，也不受这个
  bug 影响。**现场验证**：用 `chfn` 指令（复用同一个 `edit()`/
  `input_line()` 续行机制）走了两轮"多行输入 + 裸 `.` 结束"（自我介绍
  两行、签名一行），每一行都被正确累积，两次都在裸 `.` 后正确跳转到
  下一步提示，没有出现"什么？"这种续行落空的症状。本轮未额外找到可
  达的留言板房间做 `post` 测试（`d/kunming/kedian.lpc` 里唯一挂载的
  `kedian_k` 留言板调用是注释掉的死代码，`kedian_b` 这个真正生效的
  留言板挂在 `d/city/kedian.lpc`，本轮测试角色的行动范围内没有找到通
  往那里的路径）——但 `chfn` 用的是与留言板完全相同的底层机制，已经
  足以确认这条链路本身是好的。
- **§7.90（`config.fluffos` 的 maximum evaluation cost）**：确认为
  `5000000`，此前已修复过，本轮无需改动。
- **完整 §10.7 全新角色游玩**：全新账号 `rfourtst` 完整走通注册（英
  文名→确认→中文名→密码→天赋→邮箱→性别）→ 食物/饮水槽满（§8.9 修复
  依然生效）→ 移动探索（欢迎室→选择"云南"分支→昆明客栈/南大街/茶馆/
  近日古楼/北大街/王府大门）→ 经济系统（茶馆 `list`/`buy` 买大碗茶成
  功扣钱入包）→ 战斗系统（`fight bing` 对王府亲兵非致命切磋，正确陷
  入昏迷，`call_out("revive", ...)` 在 30-130 秒随机延迟后正常唤醒，
  期间 `score` 正确无输出，符合 `help combat` 文档）→ **真实死亡**
  （`kill bing` 打到"你死了"，进入白无常判词死亡流程，被判还阳送回
  土地庙，装备/潜能按预期扣减，不是 bug）→ 多次真实断线重连（heart_
  beat 持续正常工作，见上）→ 干净 `quit` 退出。全程 `debug.log` 除编
  译期变量未使用警告外没有任何运行期报错。**结论：本轮零新增 bug，
  `cctx` 在当前完整检查清单下状态清洁。**
- **本轮留下的唯一空白**：因地图路径限制，没有走到一个真正生效的留
  言板房间做 `post` 测试（用 `chfn` 间接验证了同一机制），也没有重复
  验证经济系统的 `sell`（第三轮已验证过 `sell`/`value` 正常，本轮只
  重新确认了 `buy`）；门派拜师系统本轮继续未测试（同第三轮记录的理
  由——需要巫师 `goto` 才能合理到达）。这些都不是回归重点（§7.111~
  §7.114 才是），留给后续如果继续深挖。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 2081 live occurrences deleted: 2073 via scripted sweep (`fix_710_room.py`), plus 8 hand-fixed: 5 real `.lpc` source files under `d/quanzhou/shaolin/xingsu/binaries/` (a real-content directory misleadingly named like a compiled-binaries dir — the sweep script's `binaries`-directory exclusion, meant to protect driver-compiled artifacts, false-negatived on it; caught by this batch's mandatory post-sweep `work/`-wide recheck) fixed with the same scripted logic applied directly; `clone/misc/roommaker.lpc`'s string-builder template; `d/shenlong/lwta2.lpc` (call shared a line with unrelated code: `setup(); replace_program(ROOM); set("outdoors", "shenlong");`); `d/gumu/bingqifang.lpc` (space before semicolon). ~70 already-commented-out instances left untouched. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40161. Pre-existing untracked test-account debris under `data/{login,user}/` confirmed left untouched.

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
