
## WASM 修复摘要（迁移自 meta.json 的 group_note）

神话世界·西游记 4.50 版，游戏内品牌《欢乐园》("A Journey to the West")，西安交大 BBS 附属 MUD。WASM 修复：（1）熟悉的 convertd.lpc 字节级损坏（45 行，和 sjsh 家族里见过的相同 0xce/0xb2/0xee/0x96/0xa3 非法字符签名，第 250 行附近）——用标准的字节级 Python 脚本修复。（2）adm/daemons/logind.lpc 的 banned_name 数组字面量里一个真正的语法错误：一行开头多了一个逗号（',"欢乐园",...'紧跟在上一行结尾的逗号后面），产生了一个不合法的空数组元素，连锁引发文件后面 5 个额外的解析错误（包括后面的"Undefined variable mud_list"，因为解析器再也没能恢复正常）——已去掉这个多余的逗号。（3）adm/simul_efun/chinese.lpc 和 adm/daemons/logind.lpc 里 §8.1 类的 is_chinese()/check_legal_name() GBK 字节配对 bug：两处都假设每个中文字占 2 字节 GBK 编码（strlen%2 奇偶门槛，对照一个魔术参考字符串做原始字节区间检查），在这个驱动按码点索引的情况下会拒绝合法的奇数字数 UTF8 中文名字——已把两处都改成逐码点的 0x4e00-0x9fff 区间检查，并把 check_legal_name 的长度界限从字节数（2-12）改成字符数（1-6）。另外记录（不是 bug）：logind.lpc 的 encoding() 里有一个开机后 180 秒的连线闸门——CONTROL_CENTER->query('MUD_SRART_TIME')（原文如此，原始源码里的拼写错误）会在驱动启动后的 3 分钟内拒绝所有登录，除非发送的第一行是字面的绕过短语'let me join ok'；这是有意的防灌水/开机稳定设计，不是缺陷。管理员账号播种：fluffos (admin) 加入 adm/etc/wizlist（原档案完全是空的；wiz_levels 顶层是 (admin)，SECURITY_D 正确指向 /adm/daemons/securityd，没有诱饵副本）。注册流程在一次连续的 WASM 客户端会话里完整验证过：'let me join ok' 绕过→英文 id→y/n 创建确认→中文名字→单一密码+确认（不是双密码机制）→性别→电子邮件（可选，留空也行）→天赋重掷循环（y 接受）→带着完整角色属性表进入游戏世界，全程没有任何意外错误。管理员权限已直接通过 wizlist 指令输出"目前权限：(admin)"确认。LPC 格式化工具对全部 7338 个档案运行（写入 7272 个，3 个报错，63 个未改动）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中，没有 case 标签带尾随注释的候选。两个 map.lpc 档案确认内容完全相同（只是空白差异）。格式化后用同样的完整注册流程（包括'let me join ok'绕过）重新验证过——干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（§10.7，2026-08-09）

**血统确认**：`adm/obj/master.lpc` 的档头注释（"for ES II mudlib / original
from Lil / rewritten by Annihilator (11/07/94)"）与 AGENTS.md §11 的
ES II / 东方故事巨型家族（尤其是 `kxkj`/`kxkj1`/`kxkjii2` 一支）完全一致，
`cmds/std/go.lpc` 的移动派发逻辑也是同一形状（先查房间自己的
`exits` 映射键是否存在，存在才会调用 `valid_leave()`）——因此在深挖前
先按 §7.101（`kxkjii2` 发现的死亡出口 bug）和 §7.12（该家族常见的
`message()` 参数 bug）专门核对过这两类，见下文。此前的 WASM 阶段已经
按 §8.1 修复过 `is_chinese()`/`check_legal_name()` 的 GBK 字节配对问题、
按 §7.86 修复过全部 44 处留言板 `replace_program()` 崩溃——本轮复测两者
均确认线上正常，未回归。

**本轮修复的 bug**：

1. **§7.90 变体：`maximum evaluation cost` 默认值 700000 在 PRELOAD 阶段
   就直接把驱动"防不住"（`*Can't catch eval cost too big error.`）**：
   `config.fluffos` 沿用了本项目最常见的 700000 默认值，但 `adm/obj/
   master.lpc` 的 `preload("/d/wiz/qiushi")`——囚室房间，`create()` 里
   通过 `setup()` 生成 NPC `d/wiz/npc/yuzu.lpc`——连续 3 次触发
   `Eval interrupted: ... cost limit reached, limit: 700000 usec.`
   重试后，第 4 次直接变成不可 `catch()` 的 `*Can't catch eval cost too
   big error.`，在**驱动刚启动、还没有任何玩家连线**的阶段就写入
   debug 日志。这是 NPC 首次冷编译（`/std/char` 及其整条 `inherit`
   链）的一次性开销撞上偏低上限，与 AGENTS.md §7.90 已归档的
   `xyj2000f`/`xiyouji450`/`xlqy_early` 等实例是同一形状。修复：
   `config.fluffos` 的 `maximum evaluation cost` 从 700000 提到
   5000000（本项目已有 30+ 个库使用的常规补救值）。现场验证：修复前
   每次重启驱动都在 preload 阶段稳定复现上述 3+1 次报错；修复后连续
   两次全新驱动重启，`d/wiz/qiushi` 的 preload 均无任何 eval-cost 报错，
   随后完整的注册、移动、战斗、死亡/复活全流程（见下文）也没有再触发
   过 `cost limit reached`。
2. **§7.12 变体：`adm/simul_efun/message.lpc` 的 `shout()` 把
   `this_player()` 直接当 `message()` 第 4 个排除参数，在非玩家上下文
   （游戏内报时的 `heart_beat`/`call_out`）调用时炸出
   `Bad argument 4 to EFUN message()`**：同文件里的 `tell_room()` 早就
   有 `exclude || ({})` 的防御写法，但 `shout()` 漏了同样的保护。
   `adm/daemons/timed.lpc::bj_hour_event()` 每到欢乐纪元的整点就调用
   `shout()` 广播"现在是北京时间...点整"，此时没有 `this_player()`
   （返回 `int(0)`），`message()` 的类型检查直接报错——**这个游戏内
   时钟推进远快于真实时间**（本轮会话不到 5 分钟真实时间，游戏内时辰
   就从丑时跳到卯时，跨过了至少一次整点广播），所以这不是要等很久才
   触发一次的边角情况，而是几乎每次整点都会命中的常规错误。现场验证：
   修复前的第一次驱动启动，日志里在 `Initializations complete.`
   之后几秒内就出现了这条 `Bad argument 4 to EFUN message()` 报错
   （伴随 `previous_object(1): /adm/daemons/timed`，确认是
   `bj_hour_event()` 触发）；修复（`this_player() || ({})`）后重启，
   同一会话跑满至少一次整点广播窗口（游戏内从丑时到卯时），
   `debug.log`/stdout 都没有再出现这条报错。修复方式与该文件里
   `tell_room()` 已有的写法完全对称。
3. **§7.34 debug 遗留输出**：`adm/daemons/logind.lpc::get_name()`，
   中文取名成功后、设定密码提示之前，有一行裸的 `printf("%O\n", ob)`，
   会把登录对象的内部路径（`/clone/user/login#N` 之类）直接打在取名
   和密码提示之间——已删除，属于本项目在多个血统里反复见过的原作者
   调试遗留输出，不影响任何逻辑，纯粹的信息泄露/观感问题。现场验证：
   修复前后各走了一遍完整注册流程，修复后取名成功到密码提示之间干净
   无多余输出。

**§7.68 / §7.101 是否适用于本库的死亡系统**：都不适用，理由分别记录：

- **§7.101（`exits` 缺键导致 `valid_leave()` 永远打不到）不适用**：本库
  死亡去处 `/d/death/gate.lpc`（阴阳界）的 `exits` 映射本身 4 个方向
  （south/north/west/east）都是真实、可用的键（虽然映射上方注释写着
  过时的 `/* sizeof() == 2 */`，纯粹是没跟着改的注释，不影响功能）；
  真正负责复活的不是玩家手动找出口，而是房间里的 NPC 判官
  `d/death/npc/pang.lpc`——它的 `init()` 在鬼魂进房时立刻排一个 5 个
  阶段、每阶段 5 秒的 `call_out("death_stage", ...)` 对话链，最后调用
  `ob->reincarnate(); ob->move(REVIVE_ROOM);` 把玩家送回
  `/d/ourhome/kedian`（荒郊小店）。整个复活机制完全不经过 `go`/
  `valid_leave()` 这条路径，`gate.lpc` 自己的 `valid_leave()` 其实是在
  鬼魂状态下**无条件拒绝所有方向**移动（"还是赶着去投胎吧！"），这与
  §7.101 描述的"该有的出口被注释掉"完全是两回事。
- **§7.68（`present(ob)` 缺失重试导致鬼魂卡死）也不适用，且未做任何
  改动**：`pang.lpc::death_stage()` 的守卫是同样的
  `if (!ob || !present(ob)) return;` 形状，但按 AGENTS.md 的撤回说明，
  这个"改成重试"的修复只有在**同时**满足 (1) 鬼魂在这个房间无法自主
  移动、且 (2) 确实存在某个外部系统会强制把鬼魂拖走 两个前提都现场
  验证过之后才该应用。本库满足条件 (1)（`gate.lpc::valid_leave()` 对
  `is_ghost()` 的角色无条件 `notify_fail`，鬼魂物理上走不出这个房间），
  但通读全库没有找到任何类似 `bmxkx2001` 里"剧情向导 NPC 会不分死活强
  行拖走任何被追踪玩家"的强制位移机制——条件 (2) 未成立，因此保持原样
  不改，符合"没有现场验证两个前提就不要套用"的既定原则。
- **现场验证的完整死亡/复活流程**：用种子出的 `fluffos` 管理员账号在
  长安城中心 `kill guolao`（张果老，NPC 战斗力明显超出新手角色），
  几回合后角色死亡，移动到 `/d/death/gate`（阴阳界），判官崔珏的
  `init()` 立刻触发（**没有** `wizardp()` 排除逻辑，管理员账号和普通
  玩家走的是同一条复活流程，这点和 `hy2000` 记录的"管理员被排除在
  鬼魂剧情外"不一样），5 段对话如期播放，最终"你的魂魄又回到了自己
  身上"+"reincarnate()"，落地在 `/d/ourhome/kedian`（荒郊小店）。
  `score` 确认死亡计数 +1、气/神条恢复到 `reincarnate()` 设定的初始值、
  食物/饮水条满格（§8.9 一类的食水初始化问题未复现）。

**其余检查过、确认没问题的项目**：§7.5/§7.98（`adm/daemons/
securityd.lpc` 是 `trusted_read`/`trusted_write` 目录前缀式 ACL，
`valid_read()` 对未设置 euid 的情况是放行而非拒绝，即使是这样也没有
在 `file_size`/`stat` 上出现过 §7.5 那种"目录 ACL 挡住编译期检查"的假
阴性）、§8.13（没有独立的"WIZ 密码"二次登录闸门）、§8.14（`is_banned()`
统一传入 `query_ip_number()`，没有 `query_ip_name`/`query_ip_number`
混用）。留言板 `post`/`look board` 现场复测正常（§7.86 修复未回归）。
二次登录（`quit` 后重连）确认存档正确保存并恢复：管理员权限、留言板
帖子均在重连后完整可见。

**已记录但保持不修的观察项（非 bug，符合 §1.3e 精神）**：
`adm/daemons/logind.lpc::encoding()` 里"限制多重登录"的节流逻辑用
`query_ip_name(usr[i]) == ip_number` 比较（一边是反向 DNS 主机名，一边
是点分十进制 IP），实际上永远不相等，导致这个节流从未真正生效——但
既然本项目对这类 circa-2000 的连线节流机制本来就是"直接绕过，不用
修对"的既定政策（§1.3e），这个 bug 的净效果恰好就是"节流形同虚设"，
不需要改成"修好之后又要专门加绕过"，故按现状记录、不改代码。

**环境说明**：本轮测试中途，运行环境所在的底层主机发生过一次更换
（CPU 型号变成不支持 AVX 的 Xeon L5520），导致 `build-debug/` 下用
`-march=native` 编译出的驱动二进制在新主机上无声崩溃
（`SIGILL`，退出码 132，stdout/debug.log 均无任何输出）——这不是这个
库本身的问题，其它任何库都会同样炸；已用 `-DMARCH_NATIVE=OFF`
重新配置并完整重建 `build-debug`（详见 AGENTS.md §12 新增第 5 条），
重建后本库和另一个对照库都能正常启动，本轮后续的全部现场测试都是在
重建后的驱动上完成的。

**运行环境限制**：本次会话的 sandbox 里没有 `node`（仅
`~/.vscode-server` 下捆绑的 v16.13.2 可临时借用，已用它跑过一次
`format-corpus.mjs`，两处改动均"unchanged"，说明本身格式已合规），
`scripts/wasm_client.js` 这条 WASM 备用路径本次未启用，全程用原生
驱动 + `scripts/tmux_mud.sh` 完成注册、移动、留言板、战斗和完整死亡/
复活流程的现场验证。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 192 live occurrences deleted: 189 via scripted sweep (`fix_710_room.py`), plus 3 hand-fixed roommaker-tool templates across 3 separate tool copies (`obj/roommaker.lpc`, `d/obj/clone/misc/roommaker.lpc`, `u/fof/roommaker.lpc` — all simple string-builder variant). 2 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40179. Boot auto-created empty `data/{board,ip_usage,usage}/` directories (normal daemon first-boot behavior); left untracked/untouched.

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

新角度：2026-08-09 第一轮做了战斗 / 死亡 / 留言板，没测商店和拜师。

- **登录**：开机 180 秒闸门仍在（`let me join ok` 绕过）。既有
  `fluffos`（admin，中文名「毛绒绒」，`Mud@2026`）能进，落地
  `/d/city/kezhan`，权限 `(admin)`。死亡计数 1 次仍在（上一轮杀张果
  老），尚未入门派。
- **商店**：客栈 `店小二`（`/d/city/npc/xiaoer`，房间 `objects` 已
  加载）`list` 列出炸鸡腿/红烧狗肉/花生豆/下棋指南/桂花酒袋。
  `clone /obj/money/gold` 后 `buy jitui from xiaoer` 成功（「你向店
  小二买下一根炸鸡腿」），黄金找零成九十九两银子 + 二十文钱。
- **拜师**：`goto /d/qujing/wuzhuang/wangxian`，`bai lan`（蓝采和）
  当场收徒：「好，那我就勉为其难吧。」→ 五庄观第四代弟子，师父是
  蓝采和。`save` + `quit` 后重连，`score` 仍是「五庄观第四代弟子 /
  你的师父是蓝采和」，银钱仍在；炸鸡腿未随存档回来（食物物件常见
  `no_save`，金钱与门派都持久，不按编程 bug 记）。
- **日志**：本轮 live `debug.log` 是 `libs/xajdxyj/log/debug.log`
  （Boot Time Thu Sep 3 21:19:16 2026）。无 `error:` / `Too deep
  recursion` / `No program`。`work/log/log` 只有编译警告（未用局部
  变量）。商店买卖和拜师都现场成功。
- **结论**：商店 / 有机拜师 / 重连均通过，本轮无新编程 bug 可修。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 9 line(s) in 3 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.


## 深度功能测试（§10.7，2026-10-04）— undefined macro and simul_efun gaps

- 2 file(s) `inherit F_SSERVER;` and no header defines it (2 did not compile: `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`). `#define F_SSERVER SSERVER` in `include/globals.h` (KB 04 §6.2, `scripts/lpc_alias_macro.py`). 0 still fail.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 兵器的 `actions` 函数指针

`set("actions", (: WEAPON_D, "query_action" :));`：旧 MudOS 把 `(: 字符串, "函数" :)` 当作 call_other 函数指针，本驱动把它当作表达式函数指针，求值只得到字符串 `"query_action"`。没有对应兵器技能时 `feature/attack.lpc` 直接用兵器的 `actions`，`COMBAT_D` 拿到的不是 mapping，`reset_action()` 后仍不是，记一条 bad action 就不出招——拿着这些兵器打不出攻击。改成别的兵器早已用的 `(: call_other, WEAPON_D, "query_action" :)`（KB 04 §6.10）：`d/obj/inherit/weapon/throwing.lpc`、`d/obj/inherit/weapon/fork.lpc`、`d/obj/inherit/weapon/whip.lpc`、`d/obj/inherit/weapon/sword.lpc`、`d/obj/inherit/weapon/axe.lpc`、`d/obj/inherit/weapon/blade.lpc`、等共 9 个。改动的文件在 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xajdxyj --fix` 加 `scripts/lpc_fix_no_effect.py --apply`：`cmds/adm/reg_mail.lpc`、`d/happy/register.lpc` 生成注册密码的 `for (j == 0; ...)` 改成 `=`（`j` 未初始化恰好是 0，行为不变）；三份 `xuanyuan-archery.lpc` 删去什么也不做的 `(: throw_weapon :);`。共改动 655 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：620 -> 620 通过，无回退；改过的头文件的 291 个包含者 277 -> 277 通过。

启动时警告 66 -> 0。新进程登录画面正常；启动后三分钟内登录会答"服务器正在进行启动前事务处理"，是 `adm/daemons/logind.lpc` 有意的启动锁。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 13 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 6 个，只在 #if 分支用的声明移进分支 2 个文件；改动 17 个文件，HEAD 与工作树各载入一次无回退（17 objects; HEAD PASS 17, tree PASS 17; regress 0; newly loading 0），这些文件的警告 39 -> 20。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

`scripts/toolkit_fix.sh` 加手工修复，能编译的文件里的警告 44 -> 0（`lpc_warnings.py xajdxyj` 重扫：7158 个文件可编译；剩下 5 条警告都在本来编译不过的文件里）。mhxy 今天的收尾（提交 a9cd825122a）有 4 个文件在本库是 token 级孪生（`lijing.lpc`、`d/kaifeng/ground1/2/3.lpc`），`lpc_twin_port.py adopt` 搬过来；其余手改。

**真问题：**
- `obj/home.lpc`（玩家新房）：给 `homename` 命令用的处理函数叫 `set_short(string str)`，正好覆盖了本库 `std/item.lpc` 的 `string set_short()`——后者是 `short()` 计算短描述的地方（`short()` 里 `return set_short();`，`setup()` 里也 `call_out("set_short", 1)`）。于是新房对象的 `short()` 走到新房的版本，无参数时返回 0，房间里列出这件东西时没有名字。处理函数改名 `do_homename`，`add_action` 同改；item 的 `set_short()` 恢复生效。（同系 40 多个库的 `home.lpc` 也有这个处理函数，但它们的 `item.lpc` 没有 `set_short()`，不受影响。）
- `task/`、`d/task/`、`obj/task.bak/` 三份任务物品 `yjping.lpc`（甘露玉净瓶，`ITEM + F_LIQUID + F_UNIQUE`）和 `pldudou.lpc`（破烂肚兜，`CLOTH + F_UNIQUE`）：两个基类都有 `init()`，驱动只用了 unique 的 `check_owner()`，玉净瓶的 `drink`/`fill`、肚兜的 `tear` 动作都丢了；叶子里定义 `init()` 两个都调用。

**其余：**
- `d/kaifeng/ground.h` 三张常量表包进 `#ifndef GROUND_TABLES_INHERITED`，派生房间 `ground1/2/3.lpc`、`ground.lpc` 在包含前定义它（KB 04 §6.10）。
- `d/city/npc/yg/yaoguai.lpc` 删掉从不读的 `int yaoguai_type = 0;`（只有基类 `d/dntg/yunlou/npc/yaoguai.lpc` 用，基类也初始化为 0），10 个 `yg-*` 的重复声明警告随之消失。
- `lijing.lpc` 的 `die()/unconcious()`、`u/moonsky/sun/guizi.lpc` 的 `die()` 改 `void`（基类是 void 钩子；guizi 仍调用 `::die()`）。
- `daemon/skill/hubo.lpc`（ITEM + SKILL）、`test-whip.lpc`（SKILL + SSERVER）两条路径带进同一个 `clean_up()`，按驱动原本的选择写明（`lpc_name_winner.py`）；`daemon/skill/huashan-jianfa.lpc` 删掉招式表后多余的 `;`。
- `toolkit_fix.sh`：9 个多余的 `inherit F_CLEAN_UP`。

验证：改动文件、`d/kaifeng`、`d/city/npc`、`task`、`d/task` 全部对象和 `/obj/user` 共 309 个对象，HEAD 与工作树各用新进程载入：291 -> 291 通过，regress 0；删除声明审计 0 项待看。309 个对象载入无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。1 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

43 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`liumai-shenjian`）。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`u/moonsky/nw/usr/` 8 个、`u/moonsky/nw/` 2 个：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

82 个文件、114 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/suburb/xkx/shaolin/obj/cheng-cloth`、`/d/suburb/xkx/shaolin/obj/changjian`、`/d/suburb/xkx/shaolin/obj/dao-cloth`）。本库 NPC 基类 `std/char/npc.lpc`、`std/char/npcc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 2 个，改后 84 个（82 个原来载入不了），没有退步。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`include/net/ftpdsupp.h`、`include/net/pftpdsupp.h`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:20: error: Cannot #include mailer.h）。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（4 个名字，最多的是 `huntian-qiong`、`xiake-force`、`xiake-strike`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 1 个通过，其余 1 个停在别的错误上（`daemon/class/xiake/master`：*No program in object '/daemon/class/xiake/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 补回本库没有的基类文件（2026-10-18，KB 04 §6.15）

下面这些基类本库没有，继承它们的对象（房间、NPC、物品）整批载入不了（`inherit XXX;` 的宏没定义，或者 `inherit "/std/…";` 的文件不在）。同系的库里有同名文件，两库有大量逐字节相同的文件（亲缘关系），所以从那边原样拷来，缺的宏补进全局头文件 `include/globals.h`：`/std/weapon/unarmed`（宏 `UNARMED`）←wuhanzhan，1 个对象继承它，抽样 1/1 载入；`/d/xueshan/obj/anqi-jian`←wuhanzhan，2 个对象继承它，抽样 2/2 载入。每个基类补回后单独载入、再抽样载入使用它的对象，基类载不进来或者一个用户也载不进来的就撤掉（本库撤掉了它们，不再补）。（`scripts/lpc_restore_bases.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 10 处、10 个文件：`dagonforce`→`dragonforce`（4 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`lahua-shou`→`lanhua-shou`（1 处）、`yange_blade`→`yange-blade`（1 处）、`dragon-step`→`dragonstep`（1 处）、`huntian-qiong`→`huntian-qigong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 武功文件里混进了分页器的文字（2026-10-19，KB 06 §7.263）

`daemon/skill/boxing.lpc` 第一行是 `> more boxing.c  // houquan.c 猴拳`，`daemon/skill/westsword.lpc` 两个数组元素中间有一行 `已 经 显 示 26 % (ENTER 继 续 下 一 页 ， q 离 开 ， b 前 一 页)`：这两个文件是从 `more` 分页器里复制出来的，命令行和分页提示留在了文本里，驱动报 `unexpected L_ORDER`、`Illegal character 0xe5`。前后的代码是完整的（与 chidi、yxjh 的同名文件逐记号对照，除了数值调整之外一致），删掉这两行就能载入。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`；`/u/moonsky/nw/skill/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 2 个文件，2 个原来编译不过、现在载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 16 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/daemon/class/huashan/ning.lpc`（fy2mg）、`/daemon/skill/beiming-shengong.lpc`（fy2mg）、`/daemon/skill/fanliangyi-dao.lpc`（fy2mg）、`/daemon/skill/hanbing-mianzhang.lpc`（fy2mg）、`/daemon/skill/huashan-shenfa.lpc`（fy2mg）、`/daemon/skill/huashan-zhangfa.lpc`（fy2mg）、`/daemon/skill/hunyuan-zhang.lpc`（fy2mg）、`/daemon/skill/lingboweibu.lpc`（fy2mg）、`/daemon/skill/liumai-shenjian.lpc`（fy2mg）、`/daemon/skill/longxiang.lpc`（fy2mg）、`/daemon/skill/poyu-quan.lpc`（fy2mg）、`/daemon/skill/taizuchangquan.lpc`（fy2mg）、`/daemon/skill/xiaowuxiang.lpc`（fy2mg）、`/daemon/skill/yunlong-shenfa.lpc`（fy2mg）、`/daemon/skill/yunlong-zhua.lpc`（fy2mg）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/daemon/skill/unused/snowshade-force.lpc`。修后与 HEAD 逐个对比载入：这 16 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。
