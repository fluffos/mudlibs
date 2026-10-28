
## WASM 修复摘要（迁移自 meta.json 的 group_note）

西游记2000（Journey to the West 2000），一个以西游记为题材的经典 MudOS 时代 mudlib，注册流程里带有一个"是不是在校学生"的年龄门槛问题，这是原始设计，不是 bug。WASM 修复了 3 个连环 bug：（1）adm/daemons/convertd.lpc 的 GB/BIG5 转换表（inittable）带有和 sjsh 系档案上同样的字节级损坏模式（多个符号挤在一起，而不是每个数组元素一个）——用标准的逐码点重新拆分脚本修复（影响约 45 行）。（2）adm/daemons/network/dns_master.lpc，一个真正的多用途 intermud 精灵（query_mud_name()/muds 映射被约 28 个其它服务档案呼叫：mudlist_a/mudlist_q/gtell/gchannel/rwho 等）——按照 AGENTS.md §7.52 对多用途精灵的例外处理，没有整个档案掏空，只掏空了两个碰 socket 的入口点（startup_udp() 现在回传 0，符合它自己既有的失败回传惯例，让 create() 里的 'if (startup_udp()) init_database();' 自然跳过依赖 socket 的初始化；send_udp() 变成 no-op），另外删掉了 send_shutdown() 里遗留的一处 socket_close()。（3）由此暴露出的一个连锁 bug：adm/etc/preload 里 dns_master 那一行被注释掉了（原始压缩包里是启用的；很可能是有人在 socket 兼容修复出现之前，为了让 mudlib 至少能启动而做的临时变通），导致 DNS_MASTER 从未被预加载。adm/daemons/logind.lpc 的 encoding() 在选完编码后紧接着检查 'if(!find_object(DNS_MASTER) || ...) shutdown(1);'——find_object() 只对已经加载的物件回传真，精灵既然从未被预加载，这个检查就永远为真，导致每一次连线在 GB/BIG5 选择完之后立刻触发 shutdown(1)，之后再也没有注册 input_to()（后续所有输入都显示为无法识别的指令）。已通过读 logind.lpc 的 encoding() 并确认预加载那一行被禁用（而原始压缩包里是启用的）根源定位；修复方式是重新启用那一行预加载，因为 dns_master.lpc 现在已经能在 WASM 下干净编译运行——logind.lpc 自己的检查逻辑不需要改动。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（securityd.lpc 真的会在开机时读取 WIZLIST）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB/BIG5 选择→否（年龄门槛）→new→英文 id→中文名字→密码+确认→电子邮件→性别（m/f）→属性分配菜单（9 接受默认值，y 确认）→带着完整角色属性表进入游戏世界；look/score/quit 都正常。管理员权限已直接通过登录时的"目前权限：(admin)"确认。LPC 格式化工具对全部 5637 个档案运行（写入 5542 个，4 个因为转档之前就存在的未结束字符串/文本块内容 bug 被拒绝格式化，和格式化工具本身无关，91 个未改动）。改动档案格式化前的原始内容里没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。格式化后用同样的完整注册流程重新验证过——干净，管理员权限依然是 (admin)。追加修复：scripts/scan_known_bugs.py（本次会话新写的静态扫描工具）事后标记出 5 个懒加载/潜伏的 bug，是原本只测注册流程的冒烟测试从未触发过的：d/obj/books-nonskill/book-qujing.lpc 的绝对路径写法 #include </d/qujing/obstacle.h>（永远解析不了，已改成引号写法）；logind.lpc 的 check_legal_name() 带有标准 §8.1 的 i%2 奇偶门槛加 [i..<0] 后缀切片写法（这里之所以无害，只是因为这份档案的 is_chinese() 恰好只检查 str[0]，但为了统一/稳健起见还是改成了标准的逐码点写法）；master.lpc 的 valid_read()/valid_write() 直接转发给 SECURITY_D，没有 'user == this_object()' 保护（和手足档案 xyj20032 上曾经静默弄坏每一次新角色物件编译的那个潜伏风险一模一样——这里没有观察到实际触发，属于主动预防性修复）；3 个档案用物件呼叫了 is_killing(me)，而 feature/attack.lpc 声明的是 is_killing(string id)（§7.50，daemon/class/dragon/dragonforce/roar.lpc、daemon/class/yaomo/kusong/huomo/fire.lpc、cmds/std/surrender.lpc）；d/sky/npc/zz-tianwang.lpc 还残留有原始 GBK 字节，是原来批量 GBK→UTF8 转换那一遍漏掉的（已用 iconv 转换）。另外还发现并修复了 adm/simul_efun/message.lpc 的 tell_room() 把一个未设置的 exclude 直接转发进 message() 第 4 个参数的问题（§7.12，改成 exclude || ({})）。修复后重新验证干净。

## 深度功能测试（§10.7，2026-08-05）

- **printf 调试残留**：`adm/daemons/logind.lpc` 的 `get_name()` 里有
  一处活跃的 `printf("%O\n", ob)`（和"天涯"/"hy"两个家族里已经修过
  的同款泄漏一样），每次注册都会把整个玩家对象的原始引用打印到连
  线画面上。已删除。
- **§8.9 不适用**：`enter_world()` 的 `user->set("food",
  user->max_food_capacity())` 等语句是无条件执行的，本来就没有用
  `ob`（登录对象）做任何年龄判断包装，所以不存在错对象年龄检查的
  问题——这份代码库的写法本身就是对的。
- **留言板 `post` 崩溃 bug（AGENTS.md §7.86，第三个不相关家族确
  认，且发现了一个新变体）**：这个 bug 之前在"天涯"（`tybxjh`/
  `xhcii`/`zxty`）和"hy/海洋"（`hy2000`/`hy2002`）两个互不相关的家
  族里都见过，这次在完全独立的西游记代码库里又发现了——而且这次除
  了常见的 `inherit BULLETIN_BOARD` + 多余 `replace_program
  (BULLETIN_BOARD)`（25 处）之外，还发现了一个新变体：3 份档案
  （`xyj_b.lpc`、`menpai_bbs.lpc`、`query_bbs.lpc`）用的是另一个同
  样有问题的留言板基类 `BBS_BOARD`（`/std/bbsboard.lpc`），同样的
  `inherit` + 多余 `replace_program` 写法，同样的
  `ob->edit((: done_postnews, ... :))` 闭包创建崩溃机制——已确认
  `bbsboard.lpc` 自己的 `do_postnews()` 和 `bboard.lpc` 的
  `do_post()` 是同一个致命形状。共删除 28 处多余的 `replace_program`
  调用（25 处 `BULLETIN_BOARD` + 3 处 `BBS_BOARD`）。live 验证过两
  块不同的留言板（南城客栈留言板、生死之间留言板）`post` 都能正常
  打开编辑器并保存成功。这已经是 §7.86 第三次在互不相关的代码库家
  族里被独立确认，基本可以认定是这一代 ES2 衍生代码库的通用陷阱，
  已更新 AGENTS.md §7.86 记录这个跨家族确认和新的 `BBS_BOARD` 变体。
- **战斗/死亡/复活测试**：在朱雀大街和"疥顶小僧"（一个使用"重重叠
  叠"分身幻术的强力和尚 NPC）打了一场，很快落败身亡，落到"阴阳
  界"，"朱笔判官 崔珏"在场（这份档案自己对§7.68 死亡守卫 NPC 的称
  呼和造型，判定守卫写法和"天涯"/"hy"家族的"白无常"完全一样：
  `if (!ob || !present(ob)) return;`，位于 `d/death/npc/pang.lpc`）。
  **先检查了 `pang.lpc` 的 `init()` 有没有 hy2000 那次发现的
  `wizardp()` 排除判断——确认没有**，管理员测试账号不会被排除在自
  动复活流程之外，于是直接原地等待，没有对判定守卫做任何改动（按
  AGENTS.md §7.68 现在收窄后的纪律）。复活流程完整播放了全部五个阶
  段对话，`reincarnate()` 正确执行，最终送到"荒郊小店"，角色状态
  （气血/精神部分恢复、食物/饮水满格）符合预期——复活系统本身完全
  正常，不需要任何修复。
- **本次没有测试**：拜师/门派、商店（时间主要花在追查/验证留言板
  bug 的完整范围上，留给后续深挖）。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 142 live occurrences deleted: 141 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 1 already-commented-out instance left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40155.

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

## AGENTS.md §7.19: enable_player() reentrancy guard (2026-09-01)

Same corpus-wide bug class as `mhxy`/`wuhanzhan`: `feature/command.lpc`'s
`enable_player()` wraps `enable_commands()` and is unconditionally
reachable from an NPC's `init()` via `setup()`/`reset_me()` (confirmed
on this lib's own `d/*/npc/zhangmen*.lpc`-family NPCs, matching
`mhxy`'s originally-documented `d/xueshan/npc/zhangmen.lpc` pattern).
Calling `enable_commands()` on an object that's already `living()`
makes the driver re-invoke that object's `init()` as a side effect;
since `init()` calls back into `enable_player()`, that is genuine
same-call-stack reentrancy that repeats until "Too deep recursion"
aborts a room's first-ever visit.

Fixed with a true reentrancy flag (`nosave private int
in_enable_player_now;`), NOT a bare `if (living(this_object()))
return;` guard — this lib's `feature/damage.lpc` `revive()` and
`cmds/std/sleep.lpc` `wakeup()`/`wakeup2()` all legitimately
re-invoke `enable_player()` while the object is still `living()`
(that's how a fainted/asleep character gets commands back), so a
living()-gated guard would silently break every one of those real
re-enables. `enable_player()`'s single body has no early `return`
statements, so the flag is set at entry and cleared once, before the
function's fall-through end. Verified with a single-file `lpcc`
compile check (exit 0, no errors) against `feature/command.lpc`.

## 深度功能测试（2026-09-03，第三轮）

新角度：2026-08-05 第一轮明确跳过的商店 / 拜师，加上 quit+reconnect。
死亡/复活与留言板 `post` 不再复测。

- **管理员存档缺失**：`adm/etc/wizlist` 仍有 `fluffos (admin)`，但
  `work/data/login/f/fluffos.o` 不在树上（2026-08-05 那次注册的存档
  已丢）。按 README 流程重新注册：`gb` → `no` → `new` → `fluffos` →
  中文名「浮浮」→ `Mud@2026` ×2 → email → `m`；MOTD 是 `start_more`
  分页，先 `q` 再走 `/d/wiz/init` 天赋菜单（`9` 接受默认、`y` 确认）。
  登录显示「目前权限：(admin)」，落地南城客栈。
- **商店**：客栈 `店小二`（`/d/city/npc/xiaoer`，房间本身就加载）
  `list` 列出水晶球/炸鸡腿/挑战金牌/狗肉/花生/下棋指南/桂花酒袋；
  `clone /obj/money/gold` 后 `buy jitui from xiaoer` 成功（「你向店
  小二买下一根炸鸡腿」），黄金按价找零成九十九两银子 + 二十文钱。
  `d/city/npc/tiejiang.lpc`（周铁匠）源码在、但没有任何长安房间
  `objects` 引用它——内容未接线，不是运行期 bug，本轮用已摆好的店
  小二做商店验证。
- **拜师**：`goto /d/qujing/wuzhuang/wangxian`，`bai lan`（蓝采和）
  当场收徒：「好，那我就勉为其难吧。」→ 五庄观第四代弟子，师承蓝采
  和。`save` + `quit` 后重连，`score` 仍是「五庄观第四代弟子 / 你的
  师父是蓝采和」，银钱仍在；炸鸡腿未随存档回来（食物物件常见
  `no_save`/quit 丢弃，金钱与门派都持久，不按编程 bug 记）。
- **日志**：本轮 live `debug.log` 是 `libs/xyj2000/log/debug.log`
  （`cd libs/xyj2000 && driver` 在 chdir 前进打开）。无 `error:` /
  `Too deep recursion` / `No program`。`work/log/log` 只有编译警告
  （`#pragma`、未用局部变量、`vendor_sale.lpc:504` 的 `remove()`
  参数个数与父类不一致）——商店买卖已现场成功，该警告不是本轮新
  引入的运行期故障。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xyj2000 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`daemon/skill/xuanyuan-archery.lpc` 删去什么也不做的 `(: throw_weapon :);`），共改动 400 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：388 -> 388 通过，无回退；改过的头文件的 185 个包含者 182 -> 182 通过。`adm/simul_efun/oo.lpc` 单独编译的告警是被包含片段的假象（KB 04 §6.10）。

启动时警告 84 -> 0；新进程登录（编码选择、新人物提问）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 8 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 6 个，只在 #if 分支用的声明移进分支 0 个文件；改动 12 个文件，HEAD 与工作树各载入一次无回退（12 objects; HEAD PASS 12, tree PASS 12; regress 0; newly loading 0），这些文件的警告 34 -> 20。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 4 处）后，用 `scripts/lpc_twin_port.py adopt mhxy xyj2000 --pre a9cd825122a~1` 搬来 mhxy 同日整理里与本库逐 token 相同的 7 个文件（`d/kaifeng/ground3.lpc`、`npc/colors.h` 防重、`npc/reporting.lpc` 没用的 `str`、`d/obj/cloth/jiasha.lpc` 等），其余照 mhxy 的改法手工补，能编译的文件警告清零。改动与依赖它们的对象 HEAD 与工作树各载入一次：25 个，HEAD PASS 25，tree PASS 25，regress 0。

- `d/obj/cloth/jiasha.lpc`（袈裟，`CLOTH` + `F_UNIQUE`）原来只跑 unique 的 `init()`，撕袈裟的 `tear` 命令从没加上；现在两个基类的 `init()` 都调。
- `d/kaifeng/ground.h` 的三张表被 `ground0.lpc` 和一层层继承它的 `ground1/2/3.lpc`、`ground.lpc` 各包含一次：表格包进 `#ifndef GROUND_TABLES_INHERITED`，继承方在包含前定义它。
- `feature/alias.lpc` 的命令计时 `last_time` 改名 `last_cmd_time`（三花计数员 `d/city/npc/sanhua-counter.lpc` 自己的 `last_time` 是存盘的键，不动它）；`d/city/npc/yg/yaoguai.lpc` 没人读的 `yaoguai_type` 删去；`d/dntg/lijing/lijing.lpc` 的 `die`/`unconcious`、`d/moon/npc/yutu.lpc` 的 `kill_ob` 改 `void`。

- 2026-10-14：1 个文件的代码里有只含私用区字符（U+F8F5，GBK 转码留下的）的空行，编译器报 `Illegal character 0xef` 整份不编译；这些行清空（字符串、注释里的不动）。新进程比对 HEAD 与工作树：新增载入 1，回退 0。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；载入检查：改动的文件改前能载入 1 个，改后 1 个（0 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:18: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/fuxing.lpc`、`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：3/3 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库目前没有对象设了缺失的武功；三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 4 处、4 个文件：`dragon-step`→`dragonstep`（2 处）、`hellfire_whip`→`hellfire-whip`（1 处）、`yange_blade`→`yange-blade`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 武功基类缺少 NewRandom()（2026-10-19，KB 06 §7.261）

基本武功（`boxing`、`houquan`、`westsword`、`taiji-quan` 等）用 `action[NewRandom(i, 20, level/5)]` 挑招式；`NewRandom()` 和它调用的 `sum()` 在别的库的武功基类里有，本库的 `/std/skill.lpc` 是更精简的版本，没有，于是这些武功全都报 `Undefined function NewRandom` 编译不过，有这门武功的人物只能空手。把这一对函数（115 个库共用的同一份文字）补进武功基类，受益武功 1 个：`/daemon/skill/jueqingbian.lpc`。（`scripts/lpc_restore_skill_helpers.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 1 处：`/d/moon/npc/xiwangmu.lpc` 的 `ask_pantao()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/sky/npc/zz-tianwang.lpc`（增长天王）：文件末尾是转换工具的出错信息 `iconv: incomplete character or shift sequence at end of buffer`，`ask_me` 的最后一句 `return ("老夫脚正痒痒。。。` 没有收尾。照其余二十多个库里完整的同一个文件补上 `\n");` 和函数的 `}`（已转成 UTF-8），NPC 载入。

逐个载入与 HEAD 对比，没有退步。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 1 处）。改动：`/cmds/wiz/dns.lpc`（1 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `xupdate`：`file[sizeof(file)] != '/'` 永远为真（2026-10-21，KB 06 §7.343）

管理员扫描里 `xupdate`（xyj2000）从根目录 `/` 开始递归时报 `Bad argument 2 to foreach Expected: array Got: 0.`：`UpdateDir()` 用 `file[sizeof(file)] != '/'` 判断路径是否已经以 `/` 结尾，下标等于长度读到的是 0，条件永远成立，`/` 变成 `//`，`get_dir("//")` 答 0。改成 `file[<1] != '/'`。同一个写法在 `xrm`、`rm`、`rmdir1`、`rmhir` 里有 55 处，没有动：对普通路径新旧写法的行为相同，唯一改变的是 `xrm /`，旧写法让它死在第一个 `get_dir("//")`，改了它就能递归删光整个游戏目录。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 7 条注册（4 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）。最多的函数名：`do_push` 2 处、`do_pass` 1 处、`do_resign` 1 处、`do_vendor_list` 1 处、`do_get` 1 处。没有动（读过）：`/daemon/class/zhenyuan/taiyi/qimen2.lpc` 的 `finish`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））、`/daemon/class/zhenyuan/taiyi/qimen2.lpc` 的 `quit`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/xueshan/obj/hufabird.lpc`:`saysth`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 6 个文件里有 10 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/CRASHES`、`nosave/PURGE`、`nosave/promotion` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:102`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：2 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 2 处（1 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/adm/daemons/logindtest.lpc:933`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 3 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 雪山 obj/hufabird set_level 缺 }（2026-10-27，KB 04 §6.28 Also）

`d/xueshan/obj/hufabird.lpc` 的 `set_level` 在 `setup();` 后少了一个 `}`，后面的 `int heal_up()` / `leave` / `invocation` / `die` 都嵌进了 `set_level`（`unexpected '('`），对象无程序；同目录 `npc/hufabird.lpc` 正常关闭。顺带：`messege_vision`→`message_vision`，`return : die()`→`return ::die()`，以及无 `saysth` 的 `(: saysth :)` 按 7.355 注释掉。证明：HEAD 加载失败；改后加载成功。


## 月宫 quest/road 模板缺 index（2026-10-27，KB 06 §7.348 Also）

`d/moon/quest/road.lpc`（及误放在 `npc/road.lpc` 的副本）出口写 `sprintf("%d", index ± 1)`，却没有像 `road1`…`road10` 那样声明 `int index = N;`（`Undefined variable 'index'`），对象无程序。补上 `int index = 5;`（中间段，东西出口都能落到已有房间）。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。


## 雷神 check 在 stop_fight 定义之前调用且 call_out 缺逗号（2026-10-27，KB 04 §6.28 Also）

`d/qujing/start/24/1.lpc` 的 `check()` 里调用 `stop_fight(who)`，函数却写在后面（`Undefined function stop_fight`）；`call_out("lost", 1 who)` 少了逗号（`unexpected L_DEFINED_NAME`）。把 `stop_fight` 挪到 `check` 之前，并改成 `call_out("lost", 1, who)`。证明：HEAD 加载失败；改后加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序）

`tell_object("…", me/who)` 参数颠倒（消息当对象）；改为 `tell_object(me/who, "…")`（guest.lpc）。证明：残渣 0；抽样 guest/rukou/forest_c 加载。
