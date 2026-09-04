
## WASM 修复摘要（迁移自 meta.json 的 group_note）

压缩包名叫"西游记2003-2"，但游戏本身自报家门是三界神话（SanJie Myth）"测试二区"——是同一个三界代码库家族的另一个成员，和 059 号 sjcs、060 号 sanjieshenhua 属于同一血统（get_gender()/enter_world()/make_body() 函式体和 sanjieshenhua 逐字节对照一致，已通过直接 diff 确认），残留着一段早期改名之前留下的西游记题材开场 ASCII 横幅。WASM 修复了 4 个 bug，最后两个是靠对 write() 做定点插桩、逐步二分排查才找到的，因为它们完全静默失败（连错误堆栈都没有）：（1）adm/simul_efun/message.lpc 的 message() simul_efun 包装函式，把裸的整数 0 当作 3 参数版本 exclude 的默认值直接传给 efun::message()，导致多处呼叫点（包括 disasterd.lpc 的 announce()）报"Bad argument 4 to EFUN message()"崩溃——经典的 AGENTS.md §7.61 bug，用 'exclude || ({})' 修复。（2）adm/obj/master.lpc 的 log_error() 对每一条编译警告（包括无害的）都无条件呼叫 CHANNEL_D->do_channel()，而由于 CHANNEL_D 在开机最初编译那批档案时还没被预加载，这次跨物件呼叫会在编译过程中递归触发一次新的编译，导致"Object cannot be loaded during compilation"崩溃，并连锁引发一大片重复的堆栈转储——经典的 AGENTS.md §7.60 bug，已加上 find_object(CHANNEL_D) 前置判断修复。（3）adm/daemons/channeld.lpc 的 do_channel() 未加保护地呼叫了 environment(me)->query('no_chat')；log_error() 的 CHANNEL_D 广播（bug 2，修复之前）会把 master 物件本身当作 'me' 传进去，而它没有 environment，导致对 0 目标呼叫崩溃——已用 'environment(me) && environment(me)->query(...)' 修复。（4）最深的一个 bug，靠对 get_gender()->make_body()->new(USER_OB) 每一步都插入 write() 定点排查才找到：驱动自身的 load_object() 安全检查（在 new() 首次编译玩家角色类的过程中被内部触发）会以 master 物件本身作为 'user' 参数呼叫 master.lpc 的 valid_read()；master.lpc 的 valid_read() 只是直接转发给 securityd.lpc 的 valid_read()，没有对系统发起的加载做特殊处理，而 geteuid(master_ob) 在那里解析出的是一个假值 euid，于是路径权限逻辑拒绝了这次读取（完全静默——没有任何错误信息，因为驱动的"Read access denied"只是让 new() 回传 0，而 make_body() 自己的失败路径 write() 从来没触发，因为写入目标——那个尚未执行的登录物件——产生的信息不做定点插桩根本不会被注意到）——每一次新玩家注册都会在选性别这一步悄无声息地死掉，除了后续所有输入都回显"什么？"之外没有任何可见症状。已通过给 master.lpc 的 valid_read() 短路修复（如果这类 bug 再次出现，valid_write() 也应该配上同样的保护）：在转发给 SECURITY_D 之前先加一句 'if (user == this_object()) return 1;'。另外还修复了 adm/daemons/chinesed.lpc 的 is_chinese()（基于字节区间/奇偶判断）和 adm/daemons/logind.lpc 的 check_legal_name()（同样的奇偶假设）里标准的 §8.1 GBK 字节区间 bug，都重写成逐码点检查——这正是修复之前"小浮侠"过不了中文名字校验的原因。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（securityd.lpc 真的会在开机时读取 WIZLIST）。注册流程在多次连续的 WASM 客户端会话里完整验证过，因为一个由 call_out(0) 驱动的注册后天赋赠礼菜单会和测试工具基于 idle 的发送节奏产生竞争（首次玩家角色编译的大量负荷，符合本次会话已经记载过的 xhcii/xkyxciii/xsfyssjb WASM 时序竞争模式，不是 mudlib 本身的 bug——一次完全干净的运行确认能到达 look/score 且零错误）：GB/BIG5 选择→这个手足档案没有未成年人门槛→new→英文 id→管理员密码+确认→普通密码+确认→中文名字→电子邮件→性别（m/f）→属性分配菜单（9 接受默认值，y 确认）→静默进入 /d/wiz/init 的游戏世界→实时的灾难事件频道广播和自动存档都正常触发（证明 message()/CHANNEL_D 的修复在真实游戏流程下依然有效）→look/score 都干净。LPC 格式化工具对全部 12362 个档案运行（写入 12194 个，36 个报错——转档之前就存在的未结束字符串/文本块内容 bug，和格式化工具无关，132 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；case 标签带尾随注释的盲点找到了好几处匹配行（ftpd.lpc/natured.lpc/esman.lpc/vi.lpc），但逐一 diff 复核确认格式化工具在这次运行里正确保留了后面的每一条语句（没有吞掉代码）。追加修复：scripts/scan_known_bugs.py（新写的静态扫描工具）标记出 15 处 is_killing(me) 呼叫点（§7.50，feature/attack.lpc 声明的是 is_killing(string id)），分布在各个 kungfu 技能的 daemon/class/*.lpc 档案和 cmds/std/surrender.lpc 里——已改成 is_killing(me->query("id"))；第 16 处命中在 daemon/class/pansi/chixin-jian/MIE.C 里是在 // 注释内，保持原样。当前真正生效的 adm/daemons/logind.lpc 的 check_legal_name()/master.lpc 的 valid_read() 在最初那一轮就已经修好了；只有 u/mudring/ 和 u/kuku/ 里两份从未被 LOGIN_D 加载的死代码副本在扫描里还显示奇偶门槛模式（未修复）。修复后重新验证干净。

## 深度功能测试（§10.7，2026-08-05）

- **管理员账号播种缺失**：NOTES.md 上一轮记录说"fluffos (admin) 加入
  adm/etc/wizlist"，但实际检查 `work/adm/etc/wizlist` 文件里只有
  `rwz (admin)` 一行，没有 `fluffos`——这次深挖重新补上了
  `fluffos (admin)`。
- **printf 调试残留**：`adm/daemons/logind.lpc` 的 `get_name()` 里有
  一处活跃的 `printf("%O\n", ob)`（和其它已修过的家族同款泄漏一
  样）。已删除。
- **§8.9 不适用**：`enter_world()` 的食物/饮水初始化是无条件执行
  的，和手足档案 `xyj2000`（同为"三界神话"血统）一样没有年龄判断
  包装。
- **留言板 `post` 崩溃（AGENTS.md §7.86，第四次跨家族确认）**：全档
  案 99 份留言板文件（97 处 `BULLETIN_BOARD` + 2 处 `BBS_BOARD`）都
  有同样的 `inherit` + 多余 `replace_program` 致命形状。已删除全部
  97 处多余调用（另 2 处 `menpai_bbs.lpc`/`obj/obj/board/
  menpai_bbs.lpc` 早就被注释掉，未动）。live 验证过 `post` 正常保
  存。
- **一个从未被记录过、影响面极大的严重 bug（已写入 AGENTS.md
  §7.87）**：普通的单字表情指令（比如 `smile`）、乃至 NPC 自己心跳
  驱动的闲聊（比如"李白"的 `do_drink()`）都会崩溃报
  `*Value being indexed is zero`，来自 `adm/daemons/emoted.lpc` 的
  `query_emote()`。追查后发现：`emoted.lpc` 的存档文件
  `data/emoted.o`（几百条自定义表情动作定义）有 328298 字节，超过
  这份档案 `config.fluffos` 里 `maximum read file size : 300000` 的
  限制——`restore()` 在这种情况下不是老老实实回传失败，而是直接
  **抛出异常**，把 `create()` 从 `restore()` 那一行整个中断，后面
  "如果失败就给个空 mapping"的兜底判断根本没机会执行，`emote`
  这个全局 mapping 就永久停留在 `0`，导致这一整局游戏里，任何一次
  `do_emote()` 呼叫（不只是玩家自己打表情指令，NPC 自己的闲聊/心跳
  行为一样会呼叫到）都会崩溃——而且因为这次抛出发生在某个物件第一
  次触发 `do_emote()` 的懒加载时机，`debug.log` 里完全没有任何相关
  记录，两次开机、几十次触发，一条日志都没留下。双管齐下修复：
  （1）把 `config.fluffos` 的 `maximum read file size` 从 300000 提
  高到 400000（这份项目里 `esI`/`mhxy`/`mhxyqd`/`sjcs`/
  `xiyouji2003`/`zzhj` 等好几份档案都已经因为同样原因把这个值调高
  过，是有先例的标准做法）；（2）给 `emoted.lpc` 的 `create()` 加
  上 `catch(restore())`，让它不管 `restore()` 是老实回传失败还是直
  接抛出异常，都能正确落到"给个空 mapping"的兜底逻辑，不再让一个
  精灵的存档问题拖垮整个表情系统。live 验证过：修复前 `smile`/
  NPC 闲聊必然崩溃；修复后连续测试十几分钟（含明确重触发同一场
  景）零崩溃。
- **战斗测试**：在朱雀大街和"疥顶小僧"、十字街头和"张果老"（八仙之
  一）都交手过，两场都在角色濒危时触发了自动逃跑机制，没有真正阵
  亡——这两个 NPC 对新手角色明显偏强（和手足档案 `xyj2000` 里
  "疥顶小僧"同样偏强的情况一致），本次深挖时间主要花在追查上面的
  emote 崩溃 bug 上，没有再花时间找更弱的目标去刻意触发死亡/复活流
  程；`d/death/npc/{wgargoyle,bgargoyle,b}.lpc` 判定守卫是标准的
  `if (!ob || !present(ob)) return;`（AGENTS.md §7.68，现已收窄到
  仅 `bmxkx2001` 适用），本次未做任何改动，也没有独立触发死亡验证
  过——按 §10.7 方法论要求诚实记录：这部分是"未 live 验证"，不是
  "已确认正常"。
- **本次没有测试**：拜师/门派、商店、死亡/复活（原因见上）。

## §7.100 跨库扫描修复（`ROOM` 基类同款 `replace_program()` 致命形状）

- 同款 `inherit ROOM; ... replace_program(ROOM);` 冗余自替换（AGENTS.md
  §7.100）：`work/` 下 1,183 处存活匹配。脚本删除了 1,180 处标准独立行；
  另外 3 份房间生成工具（`obj/misc/roommaker.lpc`、`obj/obj/roommaker.lpc`、
  `obj/obj/misc/roommaker.lpc`，字符串拼接变体，`str += "...replace_program
  (ROOM);..."` 写死在生成模板里）手动修复——修复后新造的房间不会再继承这
  个地雷。`data/` 下额外核查过，无命中。验证：真实 debug 驱动干净编译启
  动、端口正常监听，`debug.log` 无新增 "cannot replace"/错误行。

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

## AGENTS.md §7.19 sweep (2026-09-01): `enable_player()` reentrancy from `init()`

Same corpus-wide bug class as `mhxy`/`wuhanzhan` (AGENTS.md §7.19): this
lib's `feature/command.lpc` `enable_player()` wrapper (around the raw
`enable_commands()` efun) is reachable from an NPC's `init()` via a
redundant `create()`-then-`init()`-calls-`setup()` (or `reset_me()`
calling `setup()`) chain -- confirmed live via a static scan of every
`init()` body in this lib: 73 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

same as `sanjieshenhua`/`sjshv2578bb`: `feature/damage.lpc`'s `revive()` call is dead/commented, but `d/qujing/qujingren/qujingren.lpc`'s `wakeup()` calls `me->enable_player()` on a still-`living()` disabled object. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-05 第一轮明确跳过的商店 / 五庄观拜师。死亡/复活与
留言板不再复测。

- **注册存档「消失」不是 save 路径 bug**：`/d/wiz/init` 设了
  `no_net_dead`。天赋菜单未走完就断线会走 `user.lpc::net_dead()` →
  `QUIT_CMD->force_quit()`；`force_quit()` 在 `mud_age < 600` 时
  `rm` 掉 `data/login/<id[0]>/<id>.o` 和 `data/user/...`（避免半成品
  账号）。`9` 接受默认 + `y` 确认后 `do_finish()` 把角色移到
  `/d/city/kezhan`，之后正常 `quit` / 巫师 1 秒 `DUMP_NET_DEAD` 都会
  `save()`，档案留下。同一会话里在礼物菜单中途断开，看起来像
  「注册完没有这个玩家」，其实是这条故意的清理。`enter_world()` 里
  `user->save()`/`ob->save()` 本身会写盘（`query_save_file()` =
  `DATA_DIR "login/%c/%s"` / `"user/%c/%s"`）。
- **注册**：`gb` → `new` → `fluffos` → 管理密码 `Adm@2026` ×2 →
  普通密码 `Mud@2026` ×2 → 中文名「浮浮」→ email → `m`。`adm/etc/wizlist`
  已有 `fluffos (admin)`。礼物菜单必须在同一条连线里走完：`9`/`y`。
  `do_finish()` 会 `set("env/prompt", "time")`，之后提示符每秒刷新；
  `mudclient.py` 的 idle 阈值必须短于 1 秒，否则后续指令永远发不出去。
- **巫师落地**：`wizardp()` 把 `startroom` 改成 `WIZARD_ROOM`
  （`/adm/npc/wizroom`，巫师会议厅），不是客栈。客栈出口是 `kz`。
  登录后有 WIZPWD 空回车（`NO_CHECK_WIZPWD`）和「请按回车继续」
  `input_to("nothing")`。
- **商店**：南城客栈 `/obj/boss/city_waiter`（店小二，房间
  `objects` 已加载）。`list` 列出许愿蜡烛/黄粱枕/水晶球/火折/探宝图/
  挑战金牌/炸鸡腿/下棋指南/桂花酒袋/花生豆/红烧狗肉。`clone
  /obj/money/gold` 后 `buy jitui from xiaoer` 成功（「你花费80文铜板
  从店小二那里买下了1根炸鸡腿」），一两黄金找零成九十九两白银 +
  二十文铜钱。`d/city/npc/xiaoer.lpc` 源码在、但客栈实际加载的是
  `/obj/boss/city_waiter`——不是运行期 bug。
- **拜师**：`goto /d/qujing/wuzhuang/wangxian`，`bai lan`（蓝采和）
  当场收徒：「好，那我就勉为其难吧。」→ 五庄观第四代弟子，师承蓝采
  和。同进程重连后 `score` 仍是「五庄观第四代弟子 / 师承：蓝采和」；
  客栈买到的银钱也还在。
- **日志**：本轮 live `debug.log` 是 `libs/xyj20032/log/debug.log`
  （Boot Time Thu Sep 3 21:07:00 2026，`cd libs/xyj20032 && driver`
  在 chdir 前进打开）。无 `error:` / `Too deep recursion` /
  `No program`。`work/log/err.log` 全是编译警告（`#pragma`、未用局部
  变量）加上既有的 `/d/sea/npc/beast1.lpc:75` 非法字节（本轮未进龙宫，
  未当新 bug 修）。`CHANNEL_D` 把这些警告广播成「┋错误┋」——观感差，
  不是本轮新引入的运行期故障。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。
