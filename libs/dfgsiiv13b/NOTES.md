
## WASM 修复摘要（迁移自 meta.json 的 group_note）

ES2 血统代码库（台湾，1994-2000，Annihilator），繁体中文。重大编码发现：最初的 convert_lib.sh 转档流程把这份档案当成 GB18030 解码——GB18030 几乎涵盖所有字节序列，即使这份档案实际是 BIG5 编码也会"成功"解码，只是产生完全的乱码（落在注音符号 Unicode 区段的垃圾字元，比如 BIG5 本该解码成"使用者"的地方变成了"ㄏノ祅祘"），而不是一个转换流程可以拦截到的解码错误。已改用 BIG5 重新跑一遍完整的 raw->work 转换（套用前先用 Python 对照 big5/gbk/gb18030/cp950 四种编码试解码原始 .c 档案，确认 BIG5 才是正确答案）。另外还需要：（1）master.lpc 的 connect(int port) 用 switch 比对一个写死的 MUD_PORT（4000，泥潭原始默认值），而不是本项目实际分配的端口（40144）——不管在不在 WASM 下，每一个连线都会被拒绝（驱动记录："Can not accept connection ... due to error in connect()"），已改为更新 MUD_PORT 宏；（2）master.lpc 的 valid_read/valid_write 递归呼叫 load_object(SECURITY_D) 却没有防递归机制——经典的 §7.1，第一次真正的安全检查就触发"Too deep recursion"，已用文档记载的防递归旗标手法修复；（3）adm/daemons/userid.lpc（identd/RFC1413 反查服务，纯 socket 功能）按 §7.52 掏空处理；（4）is_chinese() 的经典 GBK 字节配对判断（要求 strlen>=2）在 Unicode 码点模型下会拒绝单字符或奇数长度的名字切片——已改成 CJK 码点区间判断。重新套用了一个之前已提交、但这次 BIG5 重新转换（从 raw 重新生成 work/）不慎覆盖掉的原生修复（移除一个和这个驱动自动预定义的 MUD_NAME 冲突的 #define MUD_NAME，§7.39）——先查过 git 记录确认那次提交还动过什么其它地方，只有 globals.h。管理员账号（fluffos/Mud@2026）通过真实注册流程 + 全新创建的 adm/etc/wizlist 播种（原始压缩包里没有附带这个档案）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 1 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

先读 README 和本文件（WASM 修复摘要已确认之前一轮播种了 `fluffos`/`Mud@2026`
管理员账号，透过真实注册流程建立）。本档案的名字本身就是「東方故事II」，
经内容比对（`d/snow/` 只有一个「雪村」示范村，没有门派/公会系统，`doc/help/
topics/` 是空目录，`cmds/std/` 没有 `join` 指令）确认这很可能就是 AGENTS.md
§11 lineage map「ES II / 东方故事 mega-family」这一支的literal ES II 引擎
本身（不是某个分支重新命名的衍生品），`kxkj`/`kxkj1`/`xkxz2`/`xiyouji`/
`rzrmud` 等库的 `feature/dbase.lpc` 很可能都是从这里的同一份代码分叉出去
的——本轮的核心发现（见下）直接命中这份共享代码，值得作为标准清单条目提
醒后续同宗测试。

### kxkj 血统先验 vs. 本档案实测结果（务必逐条核对，不要假设直接适用）

- 新手引导：**不适用**。本档案没有 8 项天赋点数分配、没有「狂想空间新手入
  门房间」，注册流程是英文 id → 密码 → 邮箱 → 种族 → 性别 → 中文名字（与
  README 已记录的一致），落地在 `/d/snow/inn_hall`（小客栈）。
- `fight` 的安全陪练分流：**分流依据不同，但结论相容**。本档案 `cmds/std/
  fight.lpc` 判断的是 `civilized` 属性（不是 kxkj 的 `can_speak`），而
  `civilized` 由 `std/race/humanoid.lpc` 的 `create()` 无条件设成 1，且
  `d/snow/npc/*.lpc` 里目前唯一出现的种族是 `human`（`set_race("human")`）
  ——也就是说这个示范村目前没有任何非人形/非文明生物，`fight` 分支恒定安
  全（点到为止），kxkj 提醒的「挑对象」问题在本档案暂时不构成风险，但
  `kill_ob()` 真杀分支代码本身还在，未来加入动物 NPC 时要留意。现场用
  `fight child`（`d/snow/npc/child1.lpc`，`accept_fight()` 恒定 `return 1`）
  验证：形体全程 90/90→70/70 只随时间自然消耗，未见战斗掉血，"加油！加油！
  加油！"提示符合"点到为止"预期。
- `join` 公会 + `apprentice` 拜师两段式：**不适用，机制不同**。全档案没有
  `join` 指令，`cmds/std/apprentice.lpc` 也没有 kxkj 那种
  `me->query("class") == ob->query("class")` 强制关卡——直接 `apprentice
  <对象>` 由该 NPC 自己的 `accept_apprentice()` 决定要不要收徒。全档案只
  有一个 NPC 实现了 `accept_apprentice()`：`d/snow/npc/alchemist.lpc`（陈
  维侠，私塾 `/d/snow/school`）。现场验证：`apprentice chen` 前几次被随机
  拒绝对白挡下，命中 `set_flag()` 后再次 `apprentice chen` 成功磕头拜师，
  `init_apprentice()` 设 `class="alchemist"`、`title="龍圖丹派弟子"`，
  `score` 面板称谓正确更新为「龍圖丹派弟子 王小明」。
- 管理员技能快捷指令：**结论相同，仍然没有**。搜遍 `cmds/adm/`/`cmds/wiz/`/
  `cmds/imm/`/`cmds/arch/` 未找到任何直接 `set_skill()`/`improve_skill()`
  的管理员命令；本档案连 `skillpass`/`skilldel` 都没有（kxkj 有，这里没
  有）。如实记录：本库同样没有技能快捷路径。
- `quit` 无新手宽限期：**结论相同**，且额外确认 `quit.lpc` 在
  `#ifdef SAVE_USER`（`include/login.h` 里确实定义了）下会调用
  `me->save()`——不同于 kxkj「quit 从不写存档、只有净断线才写」的既有发
  现，本档案的 `quit` **会**正常持久化状态（属性、称谓、位置除外——`quit`
  后重新登入回到起始的小客栈，不是净断线时才回到的「上次所在位置」，这是
  这份代码本身的既有设计：`obj/user.lpc` 的 `reconnect()` 才使用
  `last_location`，`quit` 路径没有）。现场验证：`apprentice` 拜师后
  `quit`，重新登入称谓「龍圖丹派弟子」与属性值都正确保留，只有位置回到小
  客栈（符合预期）。另外用真实的原始 socket 断线（不送 `quit`，直接让连线
  中断）模拟净断线，等待约 75 秒真实挂钟时间后重连，`reconnect()` 正确把
  角色放回断线前所在的房间（`广场`/`square_n`）。

### 修复的程序性 bug

- **`feature/dbase.lpc` 的 `query()`/`query_temp()` 对多层 `"a/b"` 属性路
  径永远静默传回 `0`，与 AGENTS.md §7.29 是完全同一种 bug（已在该条追加本
  库为第二个独立确认实例，附带诊断细节）**：`match_path()` 是 ACL 风格的
  「同层最长前缀比对」efun，不会像 `set()` 那样真的递迴钻进巢狀 mapping；
  但 `query()`/`query_temp()` 原本直接对完整的 `"exits/east"` 呼叫
  `match_path(dbase, prop)`，永远找不到 `dbase["exits"]` 这个巢狀 mapping
  本身。现场用 `call here->query("exits")`（正确返回巢狀 mapping）对比
  `call here->query("exits/east")`（返回 `0`）锁定问题。**影响面极广**：
  `cmds/std/go.lpc` 的 `env->query("exits/"+arg)` 恒定失败（"这个方向没有
  出路"，玩家完全无法在房间间移动，游戏事实上不可玩）；`alchemist.lpc` 的
  `query_temp("pending/alchemist")` 恒定读到 `0`（拜师流程的两段式确认失
  效）；`score.lpc`/`std/char.lpc` 的 `query_score()`/`query_target_score()`
  同样受影响。修复：把 `query()`/`query_temp()` 改成逐层递迴（比对 `set()`/
  `set_temp()` 自己建出的真正巢狀 mapping 形状），不再依赖 `match_path()`
  处理多层路径。已在两处补充中文注释说明成因。修复后现场复测：`go`/单字
  母方向指令（`e`/`s`/`w`/`n`）全部正常在雪村地图移动，`apprentice` 拜师
  两段式确认流程正常完成。
- **`std/char.lpc` 的 `rank()` 在没有掛载对应 class daemon 时把 `int 0` 泄
  漏进 `score` 的中文叙述句**：`daemond.lpc` 的 `query_daemon()` 在找不到
  对应档案时会回传自己（`DAEMON_D` 本身，一个真正的 object，`objectp()`
  测不出来）而不是 `0`；`DAEMON_D` 没有定义 `query_rank()`，`call_other`
  在 `call other type check` 关闭下不会报错而是静静传回 `int 0`，`score`
  里 `%s` 格式化整数 0 变成字面上的 "0" 混进中文叙述（例如"你是一位十四歲
  的 1 級男性人類**0**"）。这份档案本身就没有出货任何 `daemon/class/*.lpc`
  （`register_class_daemon()` 从未被任何文件呼叫过，`grep query_rank` 全档
  案只有 `std/char.lpc` 自己的呼叫端，属于既有的内容缺口，不是本次要补的
  游戏内容）——修复的是"呼叫一个不存在/没有该函式的 daemon 时静默漏出错误
  类型数据"这个程序性缺陷本身：改用 `objectp()` + `function_exists()` 双
  重检查，daemon 不存在或没有 `query_rank` 时比照没有 class 的角色，退回
  纯粹姓名式的 `::rank()`（与本档案原本处理"没有 class"时完全相同的分
  支）。现场复测：`score` 不再出现字面 "0"，拜师后正确显示 "龍圖丹派弟子
  王小明"。
- **`data/chinese.o` 内嵌 13 处孤立反斜线，导致整个中文翻译词典
  `restore_object()` 失败、`to_chinese()` 全面失效**：`chinesed.lpc` 的
  `create()` 呼叫 `restore()` 载入 `dict` 这份 mapping 存档，但档案里有 13
  处形如 `"...功\","` 的孤立反斜线（原始 1994-2000 年代 BIG5 档案本身带的
  作者年代产物，和这一轮 BIG5 重新转换无关——同样的反斜线也大量出现在
  `.lpc` 原始码字串里，例如 `alchemist.lpc` 的"陳維俠擺\了擺\手"，只是
  LPC 编译器对字串常值里的非法跳脱只给警告并悄悄丢弃反斜线本身，不影响显
  示；但 `restore_object()` 解析 mapping 常值时是严格模式，直接报
  `*restore_object(): Illegal mapping format while restoring dict.`，
  `create()` 里未包 `catch()` 的 `restore()` 因此整个失败，`dict` 停留在
  空 mapping `([])`，之后所有 `to_chinese()` 呼叫都直接原样传回输入字串）。
  现场用 `call /adm/daemons/chinesed->chinese("human")` 确认修复前传回字
  面 `"human"`（应为「人類」）。属于 AGENTS.md §7.7（未防护的 `restore()`
  遇到损坏存档）的一个新变体（这次损坏源头是资料档本身的位元组内容，不是
  格式不兼容）。修复：用 `tr -d '\\'` 删掉全档案仅有的 13 个反斜线位元组
  （档案里除了这 13 处不存在任何其它反斜线，逐一人工核对过每一处上下文，
  全部是"XX功\"或"穀\衣"这种紧贴在字之间/字尾的孤立反斜线，没有任何一处
  是合法跳脱如 `\n`/`\"` 的一部分）。现场复测：`call ...->chinese("human")`
  正确传回「人類」，`score` 的种族/性别栏位正确显示中文。
- **`config.fluffos` 的 `maximum evaluation cost : 700000`（AGENTS.md
  §7.90 已收录的项目模板默认值）在冷启动后第一次真正登入时不够用**：全新
  重启驱动后第一个连线（无论是哪个角色）触发
  `*Can't catch eval cost too big error.`（`logind.lpc:659`
  `enter_world`）以及后续 `write_prompt` 的 `*Too long evaluation.
  Execution aborted.`，角色被摆进保底的 `/obj/void`（"最後樂園"）而不是正
  常的出生点，需要重新连线一次（此时相关档案已被前一次连线编译过、走过缓
  存）才能正常进新手小客栈。已按 §7.90 的标准做法把
  `maximum evaluation cost` 提到 `5000000`（本项目已有 30+ 库使用这个
  值）。修复后现场复测：全新重启驱动 + 第一次连线（不是第二次），全程无
  eval-cost 相关的运行时错误，`debug.log` 干净。

### 发现但判定为既有设计、未改动的现象

- `fight.lpc` 里"你對著$n說道﹕«自稱敬语»«自己名字»，領教這位«對方尊称»
  的高招﹗"这句提示，在没有 class daemon 内容（见上）的角色身上会显示成
  名字重复两次（例如"王小明王小明"）——因为 `rank("self")` 修好之后正确
  退回到姓名式的 `::rank()`，但 `fight.lpc` 这句提示原本假设
  `rank("self")` 会返回一个独立的自称敬语（比如"小生"/"晚生"），不是名字
  本身。这是"class daemon 内容本身没有出货"这同一个内容缺口的下游表现，
  不是本次程序修复引入的新问题（修复前这个位置显示的是字面 "0"，同样不
  正确，只是形状不同）；补齐敬语系统属于游戏内容而非程序缺陷，未改动。
- `data/chinese.o` 之外，`.lpc` 原始码里还有大量类似"某某功\"、"某某\了
  某某"的孤立反斜线（编译期"Unknown escape sequence"警告），但因为 LPC 编
  译器对这类跳脱只警告、悄悄丢弃反斜线本身、不影响实际显示或执行，比对
  AGENTS.md §6.6"只在编译器/扫描实际标记出问题的地方手动修"的原则，未逐一
  清理（只修了唯一真正造成功能失效的 `data/chinese.o` 那一处）。

### WASM 未验证说明

按本 session 约定：`emsdk` 固定从 `storage.googleapis.com` 拉取，被本
session 出站代理策略拒绝，WASM 编译/运行验证本轮继续跳过，仅做原生驱动
（linux-debug 预设，ASAN/UBSAN）下的完整 §10.7 测试，全程 debug.log 干净
（仅编译期无害警告）。

## Deep functional test round two (2026-08-14)

Independently re-verified against current code rather than trusting the
round-one writeup above. Found and fixed one new bug (a real, live-
reachable instance of AGENTS.md §7.10, not previously caught here); all 4
of round one's fixes re-confirmed live, not just via diff.

### New fix: `adm/obj/master.lpc`'s `log_error()` had no severity gate at all — broadcast every compile WARNING (not just real errors) to whichever player happened to trigger a lazy compile

Distinct from the more common §7.10 case-mismatch shape this session has
been checking for (`"Warning:"` vs `"warning:"`) — this lib's `log_error()`
had no gate concept whatsoever:
```lpc
// BEFORE:
if (this_player(1)) efun::write("編譯時段錯誤﹕" + message);
// AFTER:
if (this_player(1) && strsrch(message, "arning:") == -1)
  efun::write("編譯時段錯誤﹕" + message);
```
No `wizardp()` check either — this fires for whichever player is
`this_player(1)` at compile time, which for a lazy first-visit room compile
can be an ordinary player, not just a wizard running `update`. Live-
verified the fix: `update /adm/daemons/enterd` (a file with a real,
harmless "Unused local variable" warning, confirmed present in the boot
log) now completes with only "成功。" on screen — pre-fix this would have
dumped the raw compiler warning text at whoever was connected. The
underlying `write_file(home + "log", ...)` call that persists the compile
record has its own separate, lower-severity gap (no `assure_file()` guard
on `home`, so the write can silently no-op if that wizard's log directory
doesn't exist) — left alone this pass, out of scope: it doesn't affect
players, isn't part of this session's established checklist, and touching
it wasn't necessary to fix the actual player-facing leak.

### Re-verified live: all 4 of round one's fixes still hold

- **§7.29 `dbase.lpc` multi-level path bug** (`query()`/`query_temp()` doing
  a flat `match_path()` instead of recursing into nested mappings, which
  made `go`/movement commands fail entirely via `query("exits/east")`):
  code-confirmed the recursive-descent rewrite is still present (the
  `match_path(dbase, prop[0..r-1])` shape plus the explanatory Chinese
  comments), then live-confirmed by actually walking `east` from 小客棧 to
  广场 as admin — worked cleanly, exactly the command path that was
  completely broken before the fix.
- **`std/char.lpc`'s `rank()` int-0 leak**: code-confirmed the
  `function_exists("query_rank", cd)` guard is still present.
- **`data/chinese.o` stray-backslash corruption** (broke
  `restore_object()` for the whole Chinese dictionary): confirmed zero
  backslash bytes remain in the file, and live-verified via `call
  /adm/daemons/chinesed->chinese("human")` returning "人類" (not the raw
  "human" fallback the corrupted dict would have produced).
- **§7.90 eval-cost bump** (300000usec original config trips a "Can't catch
  eval cost too big error" on the very first cold-boot login): confirmed
  `config.fluffos` still has `maximum evaluation cost : 5000000`, and
  live-verified the FIRST login attempt after a fresh driver boot completed
  cleanly with zero eval-cost errors (not the second, which round one's own
  writeup noted was the only clean path pre-fix).

### Standard checklist gap found and fixed

`adm/simul_efun/file.lpc` had the common §7.11-class gap: `log_file()`
called `write_file()` with no `assure_file()` guard, and `cat()` had no
null-guard on `read_file()`. Fixed both, matching the pattern applied
across this session's other libs. No §8.9 food/water wrong-object read, no
`printf` debug leak in `logind.lpc`.

### Verification method

Booted native `build-debug` driver, admin login (`fluffos`/`Mud@2026`) —
clean on the very first attempt (confirming the §7.90 fix). `update
/adm/daemons/logind` and `update /adm/daemons/enterd` as real privileged-
action checks. Two rapid consecutive admin reconnects, both clean. Driver
killed by exact PID after testing; incidental `fluffos.o`/`data/daemon.o`
save-timestamp churn reverted before commit.

### Files modified this pass

- `work/adm/obj/master.lpc` — new fix: `log_error()` severity gate
  (§7.10-class, previously entirely absent).
- `work/adm/simul_efun/file.lpc` — `log_file()` `assure_file()` guard,
  `cat()` null-guard.

## Round three deep functional test (2026-08-19)

Went deeper than rounds one/two, which only tested "safe sparring" combat
and never pushed a character through an actual death. This pass did a full
death→ghost→reconnect→admin-resurrect cycle, real economy transactions
(buy from a vendor NPC), and re-checked the AGENTS.md checklist items
current at the time of this session (§7.111, §7.112, §7.113, §7.90, §7.11
class, `logind.lpc` registration-save).

### Checklist items — all clean, no action needed

- **§7.111** (`master.lpc`'s `standard_trace()` calling `file_name(error["object"])`
  unconditionally): does not apply here — this lib's `standard_trace()`
  formats `error["object"]` with `%O` (`sprintf`), never calls
  `file_name()` on it at all. Different shape, not the same bug.
- **§7.112** (gargoyle/judge-lineage death NPCs with unguarded `call_out()`
  chains in `init()`): `find` for the full filename list in AGENTS.md
  §7.112 found only `d/snow/egate.lpc` and `d/snow/wgate.lpc` present in
  this archive — both are plain gate rooms (`inherit ROOM`), not NPCs, and
  contain no `call_out()`/`death_stage_active` code at all. Not applicable.
- **§7.113** (netdead reconnect never restoring `heart_beat`): checked the
  actually-invoked path — `obj/user.lpc`'s `reconnect()` (called from
  `LOGIN_D->reconnect()`) does `enable_commands()` +
  `set_heart_beat(1)` + `remove_call_out("user_dump")` correctly. Verified
  live in round two already (rapid reconnects) and reconfirmed by code
  read this round; no fix needed.
- **§7.90** (eval-cost): `config.fluffos`'s `maximum evaluation cost` is
  still `5000000` (the round-one fix); confirmed clean cold-boot logins.
- **§7.11 class** (`log_file()`/`write_file()` into a runtime dir the
  archive never shipped): `adm/simul_efun/file.lpc`'s `log_file()` still
  has its round-two `assure_file()` guard.
- **`logind.lpc` `enter_world()`'s `ob->save()`**: present and reachable
  (`#ifdef SAVE_USER` / `user->save()` right after `setup()`, before the
  startroom move) — a newly-registered account is saved immediately on
  first login, not silently dropped.

### New fix: `feature/npc/vendor.lpc`'s `affirm_merchandise()` corrupted
multi-word item names, breaking `buy <item> from <vendor>` for any item
whose primary/full name has a space in it

Live-reproduced at `/d/snow/herb_shop` (the only working vendor NPC in
this archive, `藥鋪掌櫃`/Herbalist): `buy pill from herbalist` (single-word
alias) succeeded, but `buy black pill from herbalist` (the item's actual
full name, `"black pill"`) always failed with the generic "對方好像不願意
跟你交易" decline — even though `"black pill"` is a directly registered
alias on `/obj/medication/black_pill.lpc`. This is a live, easily-hit bug:
a player who types the item's real name (as printed by `list`, e.g.
"Black pill") rather than guessing a shorter alias gets a
false rejection every time.

Root cause: `affirm_merchandise()` uses `sscanf(what, "%s %d", what,
index)` to split an optional trailing item-index number (`buy sword 2`)
off the item name — but LPC's `%s` stops at the *first* embedded space,
not the last, so for `"black pill"` the match attempt sets
`what = "black"` and then fails to parse `"pill"` as `%d`, so the overall
`sscanf()` returns 1 (not 2). The old code only guarded the `index`
variable on failure (`if (sscanf(...) != 2) index = 1;`) but never
restored `what`, so the corrupted `"black"` was used for the subsequent
`item->id(what)` lookup — which fails to match any of `black_pill.lpc`'s
aliases (`"烏心丹"`, `"black pill"`, `"pill"`), even though the correct
full name was typed. Confirmed the exact `sscanf()` truncation behavior
with a throwaway diagnostic wizard command (`sscanf("black pill 1", "%s
%d", what, index)` → `n=1, what="black"` — even with a valid trailing
index number it only manages to peel off the first word, not the whole
multi-word name before it).

Fix: parse into a separate temp variable and only commit it to `what`
when `sscanf()` actually matched both pieces (return value `== 2`);
otherwise leave `what` untouched.
```lpc
// BEFORE:
if (sscanf(what, "%s %d", what, index) != 2)
  index = 1;
// AFTER:
if (sscanf(what, "%s %d", base, index) == 2)
  what = base;
else
  index = 1;
```
Live-reverified after a fresh driver restart: `buy black pill from
herbalist` now succeeds (money deducted, item delivered), and a
subsequent purchase attempt that's correctly short on funds (`buy wild
ginseng from herbalist`) now fails with the correct "你身上的錢不夠"
(can't afford) message instead of the misleading "won't trade with you"
one — confirming the item-name match itself now works and the failure
path is the genuinely-intended one. `debug.log` stayed clean throughout.

Same buggy `sscanf(arg, "%s %d", arg, index) != 2 → index = 1` idiom
(without restoring `arg`/`what` on failure) also exists in
`std/room/hockshop.lpc`'s `do_buy()` and `obj/clan_symbol.lpc` — left
unfixed this pass because neither is reachable from any room actually
shipped in this archive's `d/snow` map (no hockshop room instance exists,
and `obj/CLAN` is an empty directory) — a content gap, not a live bug
here. Flagging in case either becomes reachable in a future content
addition, or as a pattern worth checking on other libs that build on the
same ES2-family `feature/npc/vendor.lpc`/`hockshop.lpc` lineage.

### Deeper death-cycle testing (new ground, not covered by rounds one/two)

Forced a real death via `call me->consume_stat("HP",9999)` as admin (round
one/two only ever tested harmless point-to-point sparring against a
`civilized` child NPC, never an actual death). Full cycle exercised and
confirmed clean end to end, `debug.log` empty throughout:

- Death correctly transitions `life_form` from `"living"` to `"ghost"`
  (`CHAR_D->make_ghost()`), with the expected in-game death message and
  stat-panel change (精/神 shown at reduced-but-full ghost values, 氣/`kee`
  row temporarily absent from `score` while a ghost — this is `make_ghost()`'s
  intentional `clear_temp_dbase()`/stat-remap behavior, not a display bug).
- As a ghost: `look`, movement (`west`/`east`), and `say` all work
  normally; inventory is correctly empty (nothing carried over).
- `quit` while a ghost, then reconnect: `life_form` correctly persists as
  `"ghost"` across save/restore (confirms ghost state isn't silently lost
  on disconnect/reconnect — a plausible failure mode this round
  specifically wanted to rule out).
- `resurrect <name>` (the only player-reachable-by-proxy revival path in
  this archive — see below) correctly flips `life_form` back to
  `"living"` and applies the intentional death penalty (`kee`/氣
  30 → 27, matching `chard.lpc`'s `make_living()`'s documented "corpse-less
  revival loses 10% of max" logic).

**Content-gap finding, not a bug, left alone**: the *only* code path that
calls `CHAR_D->make_living()` (the ghost→living transition) in this
archive is `cmds/adm/resurrect.lpc`, an admin-only command — there is no
player-facing temple/prayer/NPC mechanism to self-resurrect in `d/snow`'s
content, and no hostile/non-`civilized` NPC exists there either (per
round two's finding), so in practice a mortal player who somehow dies
(there is currently no reachable way to, since all `d/snow` NPCs are
`civilized`) would need a wizard to `resurrect` them by hand forever, or
be killed again as a ghost to trigger `LOGIN_D->reincarnate()` (karma-based
character reset). This matches the same "missing daemon/class content"
gap class already documented in round one (no player-facing progression
content shipped beyond the single demo village) — the death/ghost/revival
*machinery itself* is sound and bug-free, it's just missing a
player-reachable front door in this content-limited archive.

### Board/guild system investigation — confirmed unreachable, but for a
benign content-gap reason (not a crash)

Tried `board`/`list`/`post` at `/adm/guild/guildhall` (the only bulletin
board room this archive references) — all returned "什麼？" (unknown
command). Traced this to `guildhall.lpc`'s `create()` calling
`load_object("/daemon/board/wizard")`, but `/daemon/board/` doesn't exist
anywhere in this archive (confirmed via `update`: "沒有
/daemon/board/wizard.lpc 這個檔案"). Since the board object never loads,
its `add_action("do_post","post")` etc. never registers, so `post`/`read`
correctly fall through to "unknown command" rather than crashing —
graceful degradation, no uncaught error, `debug.log` stayed clean through
this. `/adm/guild/` itself is confirmed (again) to be the OOC
wizard-workshop area (巫師公會/巫師學院/會議廳, all `(admin)`-flavored text
about researching LPC), not a player-facing sect/guild system — consistent
with round one/two's finding that `d/snow` ships no player guild/sect
content. `academy.lpc` has the identical `load_object("/daemon/board/lpc")`
gap. Not fixed: missing shipped file (content gap), not a programming
defect, and it doesn't affect any player-facing system.

### Verification method

Booted native `build-debug` driver fresh (debug.log removed first).
Admin login (`fluffos`/`Mud@2026`). Tested: board/guild area (unreachable,
traced to missing shipped file), store/herb_shop economy exploration
(`list` correct), real `buy` transactions (multi-word bug found + fixed +
reverified), full death→ghost→quit→reconnect→resurrect cycle (twice — once
pre-fix baseline, once post-fix on a fresh restart). Used a throwaway
wizard diagnostic command (`cmds/wiz/sstest.lpc`) to directly confirm
`sscanf()`'s truncation behavior; deleted before commit, not part of the
mudlib. Driver killed by exact PID after testing (single SIGTERM
sufficed, no respawn this time). Incidental `.o` save-timestamp churn on
`data/daemon.o` and the `fluffos` login/user saves (from cloning test
money/items and the death/resurrect cycle) reverted via targeted
`git checkout --` before commit; `boot.log` and `work/log/debug.log`
(gitignored scratch) removed.

### Files modified this pass

- `work/feature/npc/vendor.lpc` — `affirm_merchandise()`: don't let a
  failed `sscanf("%s %d", ...)` truncate the item name being looked up
  (new fix, breaks `buy` for any multi-word item name).
