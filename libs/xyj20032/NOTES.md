
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

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 more block(s) repaired: 1 with the terminator spelled in another case than the opener (`@MING_PART ... MING_part`: the lexer compares case-sensitively, so the block never ended): `d/obj/club/bihai_mark.lpc`.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply xyj20032`: 58 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 81 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 8 PASS -> 41 PASS, 0 that loaded before fail now, 33 more load.

58 files moved (58 `.C`); mostly under `d/quest/fangzhudao` (46), `d/quest/digmoney` (3), `d/9ct/npc` (2), `d/quest/newequip` (2). A rescan with `scripts/lpc_warnings.py xyj20032` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 306 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `unew(file)`（缺档时它在 simul_efun 里对 0 调用 `query("unique")`），`else` 分支只在确有克隆时才取 `[<1]`；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `cmds/std/team/party.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xyj20032 --fix`：无用局部变量 2735 个、`varargs` 105 处、转义 99 处、裸 `return` 3 处、`nosave` 函数 5 个改 `protected`（1 个去掉），共改动 1374 个 `.lpc` 和若干 `.h`。`scripts/lpc_fix_no_effect.py --apply`：两份 `xuanyuan-archery.lpc` 删去什么也不做的 `(: throw_weapon :);`，`dns_master.lpc` 把 `#if PREF_* & SVC_TCP` 移到 `if` 外面。
手工（与 sanjieshenhua 相同的三处）：`adm/daemons/natured.lpc` 删去空语句 `lt[LT_MON];`；`adm/daemons/securityd.lpc` `valid_grant()` 删去没用到的 `string ip = query_ip_number(ob);`；`adm/daemons/channeld.lpc` 只在 `#ifdef XYJ` 分支用的四个局部变量，声明挪进同样的条件里。
HEAD 与工作树分别加载（新进程）：1336 -> 1336 通过，无回退；改过的头文件的 496 个包含者 473 -> 473 通过。
未动：`d/gumu/npc/zhangmen.lpc`（`fully_recover()` 缺一段，编译不过）是没人引用的旧稿，古墓掌门用的是 `obj/zhangmen/gumu.lpc`；`d/quest/mofeng/npc/stey/` 是不加载的草稿。

启动时警告 115 -> 0；新进程登录（编码选择、英文名、IP 提示）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 41 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 14 个，只在 #if 分支用的声明移进分支 0 个文件；改动 53 个文件，HEAD 与工作树各载入一次无回退（53 objects; HEAD PASS 52, tree PASS 52; regress 0; newly loading 0），这些文件的警告 75 -> 20。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

`scripts/toolkit_fix.sh` 加手工修复，能编译的文件里的警告 53 -> 0（`lpc_warnings.py xyj20032` 重扫：12144 个文件可编译；剩下 20 条警告都在本来就编译不过的文件里，例如拼接错乱的 `d/gumu/npc/zhangmen.lpc` 和 `d/calvin/armor/rjl.lpc`）。mhxy 今天的收尾（提交 a9cd825122a）有 8 个文件在本库是 token 级孪生，`lpc_twin_port.py adopt` 搬过来（开封擂台 `ground.h` 表格 guard 及 `ground1/2/3.lpc`、`npc/colors.h` guard、`reporting.lpc` 未用的 `str`、`lijing.lpc` 钩子改 `void`、`jiasha.lpc`）；其余照同样做法手改。

**真问题：**
- `d/obj/cloth/jiasha.lpc` 锦镧袈裟：`inherit CLOTH; inherit F_UNIQUE;` 两个 `init()` 只用了 unique 的，cloth 的 `tear` 动作丢了；叶子里两个都调用。
- `d/quest/task/cron.lpc`（waiwai 那套任务系统的副本）第一行 `#define TASK_D __DIR__"questd"`，随后又 `#include <globals.h>`，全局头把 `TASK_D` 改回 `/adm/daemons/questd`，所以这个副本的 cron 一直驱动的是主任务守护进程，而不是同目录的 `questd.lpc`。同目录的 `questd.lpc` 自己载不进来（缺 `obj/dynamic_location`，HEAD 就如此），所以保留实际行为：删掉那行从未生效的定义，加注释说明 `TASK_D` 来自 globals.h。这套副本没有别处引用。

**其余：**
- `feature/alias.lpc` 私有的 `nosave int last_time` 改名 `last_cmd_time`：三花计数器 `d/city/npc/sanhua-counter.lpc` 自己的 `int last_time` 是后声明的，驱动（`compiler.cc` `define_variable()`）只在前一个可存档时才强制后一个 nosave，alias 那份本来就是 nosave，所以计数器一直正常存档；只改 alias 这边，存档键不变。
- `d/city/npc/yg/yaoguai.lpc`、`d/quest/yuan/yg/yaoguai.lpc`：叶子自己的 `int yaoguai_type = 0;` 从不读（只有基类 `d/quest/li/yaoguai.lpc` 用，基类也初始化为 0），删掉；22 个 `yg-*` 的重复声明警告随之消失。
- `d/kaifeng/ground.lpc` 包含前定义 `GROUND_TABLES_INHERITED`；`d/quest/kaifeng/` 的 `colors.h`/`reporting.lpc` 拷贝同样处理。
- `d/longzhu/npc/long.lpc` 与 `d/quest/longzhu/npc/long.lpc` 删掉没有函数体的 `int long();` 原型；`d/moon/npc/yutu.lpc` 的 `kill_ob()` 改 `void`，仍调用 `::kill_ob()`。
- `include/net/ftpdconf.h`、`d/quest/task/questd.lpc`、`tu.lpc`：重定义宏前加 `#undef`（本来就是后一个定义生效）。
- `toolkit_fix.sh`：2 个多余的 `inherit F_CLEAN_UP`。

验证：改动文件、`d/kaifeng`、`d/quest/kaifeng`、`d/city/npc`、`d/quest/yuan`、`d/quest/task` 全部对象、包含 ftpd 头文件的对象、`/obj/user`、`/std/char` 共 418 个对象，HEAD 与工作树各用新进程载入：389 -> 389 通过，regress 0；删除声明审计 0 项待看。418 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 4 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/cmds/skill/exercise.lpc`（`force_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：2 个对象，新增载入 2，回退 0。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。4 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

6 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。本库人物只有 kee/sen（连 gin 也没有）：药物的 `receive_heal("gin", 60)`、NPC 的 `receive_curing("gin", ...)` 和来自侠客行体系的 qi/jing 调用都报 `伤害种类错误`。7 个文件按 gin→sen、qi→kee、jing→sen、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/linghai/shishi2`、`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`qiusheng-blade`→`qiushen-blade`（`/d/wizz/passion/siqi`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

18 个文件、20 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/armor/密林青衣`、`/d/leox/weapon/pa`、`/obj/longsword`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 0 个（0 个原来载入不了），没有退步；其余 18 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## NPC 带着不存在的物品：simul_efun `unew()` 报错（2026-10-18，KB 06 §7.73）

`adm/simul_efun/object.lpc` 的 `unew(str)`（带 `unique` 判断的 `new()`）先 `ob = new(str)`，紧接着就读 `ob->query("unique")`。物品文件不存在时 `new()` 返回 0，读 0 的属性报 `Bad argument 1 to EFUN call_other()`，从 `carry_object()` 一路带出去：`create()` 里带着缺失物品的 NPC 载入不了（jh2006 的苗疆何铁手一类，该有 NPC 的房间少了人）。读属性之前补 `if (!ob) return ob;`（`int i = ob->query("unique"), j, k;` 拆成声明和赋值两句），缺的物品跳过，NPC 照常载入（`scripts/lpc_guard_carry_object.py --unew`）。载入检查：改动的文件改前能载入 2 个，改后 2 个，没有退步。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 7 个对象设了本库没有文件的武功（11 个名字，最多的是 `fumobashi`、`mizongbu`、`bite`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：7 个里 6 个通过，其余 1 个停在别的错误上（`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/jjf/front_yard` 的 `down`：`/d/quest/m_weapon/lianfushi` → `/d/quest/weapon_bk/lianfushi`；`/d/jjf/front_yard` 的 `up`：`/d/quest/m_weapon/lianmaceshi` → `/d/quest/weapon_bk/lianmaceshi`；`/d/lingtai/forrest2` 的 `south`：`/d/quest/m_weapon/liangunshi` → `/d/quest/weapon_bk/liangunshi`；`/d/moon/neartop` 的 `north`：`/d/quest/m_weapon/lianbianshi` → `/d/quest/weapon_bk/lianbianshi`；`/d/nanhai/tingjing` 的 `east`：`/d/quest/m_weapon/lianzhangshi` → `/d/quest/weapon_bk/lianzhangshi`；`/d/qujing/kusong/kusongjian` 的 `west`：`/d/quest/m_weapon/lianqiangshi` → `/d/quest/weapon_bk/lianqiangshi`；`/d/qujing/wudidong/dong` 的 `up`：`/d/quest/m_weapon/liandaoshi` → `/d/quest/weapon_bk/liandaoshi`；`/d/qujing/wuzhuang/juyuan` 的 `up`：`/d/quest/m_weapon/lianchuishi` → `/d/quest/weapon_bk/lianchuishi`；`/d/shushan/shanjiao` 的 `east`：`/d/quest/m_weapon/lianjianshi` → `/d/quest/weapon_bk/lianjianshi`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件：`/u/helpler/npc/clubdd_master`←sjshv150，1 个对象继承它，抽样 1/1 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 30 处、30 个文件：`lahua-shou`→`lanhua-shou`（10 处）、`dagonforce`→`dragonforce`（7 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`yange_blade`→`yange-blade`（2 处）、`dragon-step`→`dragonstep`（2 处）、`kongming--steps`→`kongming-steps`（1 处）、`changqaun`→`changquan`（1 处）、`lingyi-sword`→`liangyi-sword`（1 处）等共 12 个名字。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 5 个：`/daemon/skill/boxing.lpc`、`/daemon/skill/westsword.lpc`、`/daemon/skill_bk/boxing.lpc`、`/daemon/skill_bk/westsword.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 1 处：`/d/pkdao/room1.lpc` 的 `greeting()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `WEAPON_OB`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 和包含文件同目录的头文件，改成引号形式（2026-10-19，KB 04 §6.17）

2 个文件用尖括号写 `#include <hedi.h>` 这类头文件（`banned.h` 等），头文件其实就放在它们自己的目录里。老驱动对尖括号名字也会先找包含文件所在目录，本驱动只找 include 路径，所以报 `Cannot #include ...`，整个物件载入不了。改成 `#include "hedi.h"`（引号形式相对包含文件解析，预加载、`lpcc` 和运行时编译都一样）。（`scripts/lpc_fix_local_include.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 标准整理轮，第二轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：2 个函数补上 varargs（调用处少传参数）。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/jz/npc/jiang.lpc`（dtxyzjb）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：离开时清除“砍柴”标记只在往北走时才生效，往南不清。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/wizz/stey/npc/robber.lpc`（1 处）、`/d/lingtai/forrest2.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：同盟可以取门派的名字（`fname == A && fname == B && ...`）。改动：`/adm/daemons/leagued.lpc`（13 处）、`/d/lanling/yuhuayuan.lpc`（1 处）、`/d/wizz/calvin/lanling/yuhuayuan.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/d/liufangdao/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 9 处）。改动：`/cmds/skill/club/clublevel.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/d/shengdian/npc/rulai.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `hebing` 指令编译不过：字符串里多了一个引号（2026-10-20，KB 04 §6.25）

`cmds/usr/hebing.lpc` 第 162 行 `tell_object(me, HIC "你利用手头的物品创造了探险通行证 "！\n" NOR);`：`证` 后面多出一个空格和一个 `"`，字符串在那里结束，后面的全角 `！` 就成了代码（`Illegal character 0xef`）。sjshv150 的 `hebing.lpc` 里同一句是 `"你利用手头的物品创造了探险通行证！\n"`，xyj20032 和 sjshv2578bb 照它改（去掉多出的空格和引号）。加载检查：各 1/1，HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/jobnpc.lpc`、`/std/char/npc.lpc`（共 2 个文件）。

## 监狱 `d/wiz/jail`：`quit` 调用不存在的 `/cmds/eld/quit`（2026-10-21，KB 06 §7.344）

`do_quit()` 调 `"/cmds/eld/quit"->main(this_player(), "")`，本库没有 `eld` 目录。被关进监狱的玩家（`tojail`、红包、彩蛋都会把人送进来）敲 `quit` 只得到一条运行时错误，退不出游戏。改成标准的 `/cmds/std/quit`。

## 观礼台 `d/city/under.lpc`：`wait_and_start()` 里的 `fan` 没赋值，比武开不了（2026-10-21，KB 06 §7.346）

接受挑战（`defend`）两秒后 `wait_and_start()` 调用 `fan->command("chat ...比武开始")`，`object fan;` 声明了却没有 `fan = load_object(__DIR__ "npc/fan");`（dtxywzxzb 的同一份文件有），抛错之后两条 `kill` 和 `call_out("finish_match", 300)` 都不执行，比赛不开始。补上这一句（`npc/fan.lpc`、`ground.lpc` 本库都有）。

## 七龙珠 `combine`：六次 `present()` 都存进了 `b`（2026-10-21，KB 06 §7.348）

每颗龙珠的 `do_combine()` 先检查身上有另外六颗：`if (!(b = present("liang longzhu", me))) ... if (!(b = present("fen longzhu", me))) ...`，六句都写成 `b =`，后面 `destruct(b); destruct(c); ... destruct(g)` 的 `c` 到 `g` 一直是 0。这几个库的 `destruct()` sefun 对 0 不抛错（原始 efun 也不抛），结果是合成神龙时只消耗了最后一颗和合成者自己，另外五颗还留在身上，可以反复合成。改成 `b, c, d, e, f, g`（shenmo 的 `/d/longzhu/obj/*` 是对的）。sjsh 上实测：HEAD 合成之后背包里还剩青、黄、蓝、粉、亮五颗，改后只剩神龙。改动：`/d/longzhu/obj/1.lpc`、`/d/longzhu/obj/2.lpc`、`/d/longzhu/obj/3.lpc`、`/d/longzhu/obj/4.lpc`、`/d/longzhu/obj/5.lpc`、`/d/longzhu/obj/6.lpc`、`/d/longzhu/obj/7.lpc`、`/d/quest/longzhu/obj/1.lpc`、`/d/quest/longzhu/obj/2.lpc`、`/d/quest/longzhu/obj/3.lpc`、`/d/quest/longzhu/obj/4.lpc`、`/d/quest/longzhu/obj/5.lpc`、`/d/quest/longzhu/obj/6.lpc`、`/d/quest/longzhu/obj/7.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 80 条注册（35 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/calvin/lanling/npc/guard1.lpc`（`do_bian`）、`/d/calvin/lanling/npc/gurad1.lpc`（`do_bian`）、`/d/calvin/lanling/x.lpc`（`do_swim`）、`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/eastway/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/gumu/huo.lpc`（`do_chop`）、`/d/gumu/jin.lpc`（`do_chop`）、`/d/gumu/mu.lpc`（`do_chop`）、`/d/gumu/shui.lpc`（`do_chop`） 等共 35 个文件。最多的函数名：`do_swim` 30 处、`do_no` 10 处、`do_bian` 9 处、`do_chop` 9 处、`do_list` 3 处。没有动（读过）：`/d/gumu/npc/zhangmen.lpc` 的 `do_comfirm`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/wizz/stey/npc/rulai1.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/wizz/stey/npc/rulaim.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 3 处、3 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/calvin/npc/wu.lpc`（`do_bian`）、`/d/quest/stey/yz_guai/guai.lpc`（`do_persuade`）、`/d/wizz/calvin/npc/wu.lpc`（`do_bian`）。

## 代码里写死 `.c` 后缀的路径（2026-10-22，KB 06 §7.356）

`carry_object("/x/y.c")->wield()`、`new("/x/y.c")`、`inherit "/x/y.c"`、出口 `"down" : "/x/y.c"`、商店货单 `"/x/y.c" : 10` 这类字符串，压缩包里的文件早已改名成 `y.lpc`；明确写出的后缀按原样查找（KB 03 §4.2），找不到文件，`new()` 返回 0，`0->wield()` 报 `Bad argument 1 to EFUN call_other() Got int(0)`，NPC 的 `create()` 中途退出、整个对象加载不了。`scripts/lpc_fix_dotc_path.py` 把 3 个文件里的 9 处 `.c` 改成 `.lpc`（只改文件存在于 `.lpc`、不存在于 `.c` 的代码字符串；注释、巫师目录、两种写法都不存在的路径不动）：`/d/hellfire/hellfire1/in.c`、`/d/obj/armor/jinjia.c`、`/d/obj/weapon/sword/qinghong.c` 等。 加载检查（HEAD 与工作区对比，改动的 3 个文件）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 6 个函数没有补（chat_msg_combat 3, inquiry 2, chat_msg 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/9ct/npc/wuyazi.lpc`:`kick_back`、`/d/death/npc/yanluowang.lpc`:`ask_cancel`、`/d/obj/npc/girl.lpc`:`my_randommove`、`/d/quest/mofeng/npc/stey/yg-hell.lpc`:`perform_action`、`/d/quest/mofeng/npc/stey/yg-hell.lpc`:`cast_spell`、`/d/xueshan/obj/hufabird.lpc`:`saysth`。 另有 11 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。2 个文件里 2 处（`d/obj/weapon/spear/jinqiang.c`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 5 个文件里 15 行只含这个指针的行（`"回去": (: kick_back :),` `"cancel": (: ask_cancel :),` `"set": (: set_max :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 2 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 2 处（1 个文件）：拼名字的赋值 2 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/tidu.lpc:126`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：9 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 9 处（4 个文件）：`if (strlen(arg) > 32) {`（`/adm/daemons/newsd.lpc:215`）；`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/npc/wuji.lpc:177`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 10 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 从末尾按字节取汉字、书剑开帮长度（2026-10-23，KB 06 §7.364）

§7.360 只折了数字下标的 `[a..b]`，从末尾取的 `[<2..<1]`（GBK 下一个汉字）和 `[<4..<1]`（两个字）还留着：开帮 `gcreate` 的帮助写「二至六个汉字 / 3到8个英文字母」，检查却是 `(strlen%2)==1 || <4 || >12`，末字对 `({ "帮","会",… })` 用 `gname2[<2..<1]` 永远对不上；少林 / 峨嵋法名 `"明" + name[<2..<1]`、死讯 `killer[<2..<1] != "。"`、兵器改名的 `can_name` 同样坏掉。`scripts/lpc_fix_tail_slice.py` 只改汉字语境（对照非 ASCII 字面量、`can_name` / `valid_group_name`、拼名字），ASCII 补零 / ctime / 复数词尾 / `.lpc` 不动；`[<2..<1]`→`[<1..<1]`，`[<4..<1]`→`[<2..<1]`，开帮门槛按帮助改写。本库 从末尾切片 2 个文件。证明（`scripts/lpcc_eval.py` bxsj）：HEAD 上 `斧头帮[<2..<1]` 对不上「帮」；改后 `[<1..<1]` 对上；长度放行 `斧头帮`/`fut`；`"明"+"张三"[<1..<1]` 得「明三」。

## 茶馆猜诗读不到诗库：Domain 对 /d 无读权限（2026-10-23，KB 06 §7.366）

mudring 的 `creator_file()` 给所有 `/d`/`/obj`/`/daemon` 对象 euid `Domain`；`securityd` 的 `default_trusted_read` 却只有根上的巫师级，工作树又没有 sjshv150 那种带 `"/d": ({ "Domain" })` 的 `extend_trusted_read` 存档（本库存到 `data/nosave/securityd`）。于是茶馆 `/d/city/clubpoem` 的 `new_poem()` 对 `/d/ourhome/honglou/poem/poemN` 的 `read_file` 得到 0，接着 `sscanf(0, …)` 抛错，房间加载不完。在 `default_trusted_read` 里加上 `"/d": ({ "Domain" })`。证明：HEAD 加载抛错；改后房间加载且 `valid_read(...poem1...) == 1`。


## 兰陵出口仍指向 /u/calvin、大殿北去 /u/fly（2026-10-23，KB 06 §7.367）

可玩的兰陵已在 `/d/lanling/`（`lldj1`、`beijiao4` 等），出口字符串还写着作者目录 `/u/calvin/兰陵/地区/…`，走动即死出口；皇宫大殿北向 `/u/fly/doublesword/houdian` 同样不存在。`scripts/lpc_fix_calvin_lanling.py` 在目标 `.lpc` 存在时改写为 `/d/lanling/<stem>`，并删掉大殿那条北向。本库 63 处。证明：sjshv2578bb 的 `lldj1` 北向加载 `beijiao4`；xianlvqiyuan 大殿 HEAD 有北向、改后没有。未映射：`书局`、`钦陵宫`（库内无对应文件）。


## 家丁 CLOTH_OB()/WEAPON_OB() 调用式宏（2026-10-27，KB 04 §6.16 Also）

`d/wuguan/npc/jiading.lpc`（及 `jiading1`，xlqy 系在 `d/dntg/hgs/wuguan/npc/`）写 `carry_object(CLOTH_OB("cloth"))` / `WEAPON_OB("changjian")`：库中没有带参的 `CLOTH_OB`，`WEAPON_OB` 在 `globals.h` 只是裸路径 `"/d/obj/weapon/"`，展开成 `"/d/obj/weapon/"("changjian")` 语法错误，NPC 无程序。同目录其它 NPC 用 `__DIR__ "obj/cloth"`；剑在 `/d/obj/weapon/sword/changjian`。改成这两条（目标文件均在树内）。证明：HEAD `Undefined function CLOTH_OB`；改后 `new()` 成功且 inventory 为 2。


## 黑风山 pusa1 用未声明的 ob 且函数外残留 call_out（2026-10-27，KB 06 §7.348 Also）

`d/qujing/heifeng/npc/pusa1.lpc` 的 `announce_success(object who)` 写成 `if (!ob->query("obstacle/hf"))`（`Undefined variable 'ob'`），同目录 `pusa.lpc` 是 `who->query("obstacle/hf") == "done"`；`who->save(); }` 之后还残留 `call_out("die"...); return; }`，落在函数外（`unexpected L_STRING`），对象无程序。改成与 `pusa` 相同的门，并删掉残留语句。证明：HEAD 加载失败；改后加载成功。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 月宫 quest/road 模板缺 index（2026-10-27，KB 06 §7.348 Also）

`d/moon/quest/road.lpc`（及误放在 `npc/road.lpc` 的副本）出口写 `sprintf("%d", index ± 1)`，却没有像 `road1`…`road10` 那样声明 `int index = N;`（`Undefined variable 'index'`），对象无程序。补上 `int index = 5;`（中间段，东西出口都能落到已有房间）。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。


## 雷神 check 在 stop_fight 定义之前调用且 call_out 缺逗号（2026-10-27，KB 04 §6.28 Also）

`d/qujing/start/24/1.lpc` 的 `check()` 里调用 `stop_fight(who)`，函数却写在后面（`Undefined function stop_fight`）；`call_out("lost", 1 who)` 少了逗号（`unexpected L_DEFINED_NAME`）。把 `stop_fight` 挪到 `check` 之前，并改成 `call_out("lost", 1, who)`。证明：HEAD 加载失败；改后加载成功。


## toy 旁缺 message.h（2026-10-27，KB 04 §6.23 Also）

`obj/toy/*.lpc`（及少数 `obj/obj/toy`、嵌套副本）写 `#include "message.h"`，引号 include 只解析同目录；本 lib 的 `d/obj/misc/message.h` 有同内容副本，toy 目录没有。玩具对象无法编译（`Cannot #include message.h`）。从本 lib 的 `d/obj/misc/message.h` 复制到缺失的 toy 目录旁。证明：HEAD `buwawa` 加载失败；改后加载成功。

## 玉皇 yuhuang1 去引号无法加载（2026-10-27，KB 04 §6.25 Also）

`d/dntg/sky/npc/yuhuang1.lpc`：字符串与路径几乎全部丢掉引号（`set_name(玉皇大帝,…)`、`carry_object(/d/obj/cloth/mangpao)`、`setup()` 后无 `;`），下一句 `int promote_me()` 成语法错误。同目录手足 `yuhuang.lpc` 完好；用本库 `yuhuang` 字节覆盖 `yuhuang1`。证明：HEAD 加载失败；改后加载成功。
