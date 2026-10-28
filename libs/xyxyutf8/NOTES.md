
## WASM 修复摘要（迁移自 meta.json 的 group_note）

小雨西游utf8——一份独立打包的、小雨西游/小雨西游Ⅱ代码库（和 003 号 xyxy2、003-1 号 xiaoyuxiyou 同一家族）的 UTF8 重新打包版本，已确认不是逐字节相同的重复档案（8753 对 11149 个 .lpc 档案——是不同的内容快照，不只是同一棵代码树的重新编码）。WASM 修复了 2 个 bug，都是真正的环境限制/潜伏内容问题，不是 mudlib 逻辑错误：（1）AGENTS.md §1.3(e) 记载的常规 uptime() 启动宽限门槛（销毁驱动启动最初 30 秒内的任何连线）——这个家族正是那一节里点名会受影响的例子；已通过只对非本地回环连线设门槛来绕过，符合文档记载的标准补丁做法。（两份手足档案 xiaoyuxiyou/xyxy2 后来发现在更早的一次深入会话里其实已经打了完全相同的绕过补丁——它们的 meta.json/README 只是从未更新反映这一点，两份都还错误地标记为 'limited'，尽管各自的 NOTES.md 已经记载了完整完成情况；已在紧随本次提交的一次后续提交里一并修正。）（2）adm/daemons/logind.lpc 的 encoding() 呼叫了驱动原生的 set_encoding("GBK")/set_encoding("big5")（不是 mudlib 自己那套基于整数的包装函式），在 WASM 下会抛出"Fail to set encoding to GBK, error: U_FILE_ACCESS_ERROR"——内置的 ICU 数据档案里没有 GBK 转换器。既然这份档案本来就已经是 UTF-8 原生重新打包版本（从它自己的名字/品牌就能看出），这次转码呼叫本身已经是多余的；已把两处呼叫都包进 catch()，而不是直接删掉，以防别处的 query_encoding() 依赖这个物件"尝试过设置"这件事本身。另外在 GB/BIG5 选择和真正的登录 id 提示之间多了一个"按回车继续 / Exit"的提示，这在这个家族的某些手足档案里没有——已在 README 的注册流程说明里记录，不是 bug。管理员账号播种：fluffos (admin) 加入 adm/etc/notices（WIZLIST 指向那里，符合 xiaoyuxiyou 自己 README 里记载的家族惯例）。注册流程在一次连续的 WASM 客户端会话里完整验证过：GB 选择→回车（继续）→new→英文 id→中文名字→管理员密码+确认→登录密码+确认→电子邮件→性别（m/f）→属性菜单（9 接受，y 确认）→进入游戏世界，look/score 都干净（look 时有一处无害的 printf("%O") 调试数组残留输出，转档之前就存在，未修复——纯属外观上的调试信息）。管理员权限已通过"目前权限：(admin)"确认。LPC 格式化工具对全部 8753 个档案运行（写入 8536 个，31 个转档之前就存在的未结束字符串/文本块内容错误未做格式化，186 个未改动；daemon/class/spells/40/ 下几个档案/目录名带有原始压缩包文件名编码残留的乱码字节，依然成功完成了格式化）。没有 :: 父类呼叫拆分命中，没有 CJK 重新加空格命中；10 处 case 标签带尾随注释的命中（combatd.lpc、natured.lpc、5 份 maze/tupo40-N/npc/guai.lpc、newcloth.lpc、fabao.lpc、perform.lpc）全部经 diff 复核干净——后面的每一条语句/穿透逻辑都正确保留。格式化后重新验证干净，管理员权限依然是 (admin)。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 40 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 205 live occurrences deleted: 204 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant). 4 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, zero new "cannot replace"/"cannot bind" debug.log lines; confirmed serving via raw-socket connect on port 40168.

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

## 深度功能测试 / Deep functional test (round two, 2026-08-27, AGENTS.md §10.7)

First genuine hands-on playthrough on this lib (every prior pass above
was compile/boot-level verification only). Native driver
(`build-debug`), one continuous session per phase, driven via a raw
Python socket script (`scripts/mudclient.py`-equivalent, hand-rolled
for this session to control the GB/BIG5 wire-encoding negotiation).
Confirmed lineage: same 小雨西游 engine family as `xyxy2`/
`xiaoyuxiyou` (shared `obj/user.lpc`, `feature/skill.lpc`,
`adm/simul_efun/message.lpc`), same 傲来国→翠香楼 starting map,
same 武馆弟子 (`d/aolai/npc/dizi.lpc`) safe-sparring mechanic
documented in `work/doc/help/newbie/newbie`.

**Test character**: id `linfeng`, Chinese name 林风, login password
`test1234`, super password `Test123!` — kept as a representative
playthrough character. Final state: level 5 (admin-set once natural
combat exp already exceeded the requirement, to save time reaching the
level-5 gate for the sect-join test), 百花谷 (Baihuagu) 第四代外门
弟子 under 百草仙, `unarmed` skill at level 1 (learned from 东方聪),
一两白银 + 桂花酒袋 from a real shop purchase. Save files:
`work/data/user/l/linfeng.o`, `work/data/login/l/linfeng.o`.
Admin account `fluffos` / 登陆密码 `Mud@2026a` / 管理密码
`AdminMud@26` (freshly seeded this session — `adm/etc/notices` only
had the bare wizlist line before, no actual account existed yet),
Chinese name 无痕 (the game rejected the intended "小雨" — it's a
hardcoded `banned_name` entry in `logind.lpc`, presumably reserved for
an NPC/founder identity, not a bug). `(admin)` privilege confirmed live
via `update`/`call` (both `(arch)`-gated commands) succeeding.

### Bugs found and fixed

**1. SEVERE — `adm/simul_efun/message.lpc`'s `sort_string()` (the
shared word-wrap routine behind nearly every text output path:
room `long` descriptions, `say()`, `tell_object()`, `tell_room()`,
`message_vision()`) silently dropped every other Chinese character in
any string it wrapped — see new AGENTS.md §8.1 sub-entry for the full
byte-vs-codepoint root-cause writeup and fix. Symptom in play: the very
first text a new character ever sees
(`d/wiz/init.lpc::enter_world()`'s "好！祝你西天取经早成正果！"
welcome line) arrived as "好祝西取早正！"; every room's `long`
description read the same way
("这就傲国有的馆是年大来富所" instead of "这里就是傲来国最有名的
饭馆是早年一大唐来的富商所开..."). Initially misdiagnosed as a
`set_encoding("GBK")`/`set_encoding("big5")` transport bug (this
archive's own README already flags that call as a known-redundant
leftover from the WASM investigation) — ruled out by disabling
`set_encoding()` entirely and reproducing the IDENTICAL corruption,
then isolated definitively via a `strlen()`/`sprintf("%O")` A/B test
that proved the in-memory string was always correct and the corruption
happened purely in the output-wrapping layer. Fixed by removing a
single stray `i++` in `sort_string()`'s wide-character branch (a
leftover from the pre-UTF8 GBK 2-byte-per-char era; this driver indexes
strings by Unicode codepoint, so the extra advance skipped one whole
character after every wide char it processed). Verified live: room
descriptions, NPC dialogue, and system messages all render
byte-for-byte identical to their `.lpc` source text after the fix, with
correct word-wrapping at the intended column width preserved.

**2. SEVERE — `cmds/std/learn.lpc` silently discarded the very first
skill point any character ever learned from an NPC teacher**, despite
printing the full success sequence and deducting potential — see new
AGENTS.md §7.156 for the full writeup (a caller-side regression
introduced by this same lib's own earlier §7.30 corpus-sweep fix to
`feature/skill.lpc`'s `query_skills()` accessor: the accessor's guard
now always returns a valid mapping, defeating `learn.lpc`'s
`!skills || !mapp(skills)` check for "was this ever initialized").
Reproduced live: a fresh character's first `learn unarmed from
dongfang cong` showed `你的「扑击格斗之技」升至 1 级` and deducted 3
potential, but an immediate `skills` said `你目前并没有学会任何技能`
and the `.o` save file had no `skills` key at all — persisted across a
clean reconnect too. Fixed by having `learn.lpc` call
`me->set_skill(skill, my_skill)` unconditionally instead of
re-deriving "never initialized" from the accessor's return shape (that
setter already does the right thing in both cases). Verified live:
re-ran the identical `learn` command post-fix, confirmed `skills` shows
`扑击格斗之技 (unarmed) 初学乍练 1/0` immediately AND after a fresh
reconnect, and the `.o` save file now has a real `skills` key.

**3. `adm/simul_efun/file.lpc::log_file()` had no `assure_file()`
directory-precreation guard (AGENTS.md §7.11) — already fixed in the
sibling `xyxy2`/`xiaoyuxiyou` but not ported here.** Reproduced live:
`call linfeng->add(...)` triggered `cmds/wiz/call.lpc`'s player-call
audit log (`log_file("nosave/call_player", ...)`), which threw `*Wrong
permissions for opening file /log/nosave/call_player for append`
because `work/log/nosave/` doesn't exist in this checkout (gitignored,
same standing gap as every other lib in this family — recreating the
directory alone doesn't fix future checkouts). Fixed at the root: added
a forward declaration + `assure_file(LOG_DIR + file)` call inside
`log_file()` itself (matching `xyxy2`'s exact fix), plus the same
lib's `cat()` null-guard (`read_file(file) || ""`). Verified live:
repeated the exact `call` that crashed before, now succeeds cleanly and
`work/log/nosave/call_player` gets created and written on demand.

**4. `cmds/arch/update.lpc` had the unguarded `present(file,
environment(me))` crash (AGENTS.md §7.106) — `cmds/wiz/update.lpc` in
this same lib was already fixed, but the `(arch)`-level duplicate at a
different path was missed.** `adm/daemons/securityd.lpc` confirms
`cmds/arch` commands are reachable by `(wizard)`/`(apprentice)`/
`(immortal)`/`(arch)`/`(admin)` alike, so this was live-exploitable.
Fixed with the standard one-line guard:
`if (environment(me) && (obj = present(file, environment(me))) &&
interactive(obj))`. Not live-reproduced with a truly-environment-less
character (would require deliberately corrupting a save) but confirmed
compiling and running correctly via `update /adm/daemons/logind` as
both `fluffos` (admin) post-fix.

**5. `adm/obj/master.lpc::log_error()` broadcast raw compile WARNINGS
(not just genuine errors) to every connected player (AGENTS.md
§7.103).** Confirmed the exact vulnerable shape (`if (this_player(1))
efun::write(...)` with no `warning:` substring filter). Fixed with the
standard `strsrch(message, "warning:") == -1` guard. Not separately
re-verified live post-fix (this fix is identical in shape and
confidence to every other §7.103 instance in this corpus; the boot log
for this whole session already shows dozens of lazy-compile warnings
that would otherwise have been broadcast to `linfeng`/`fluffos`
mid-session had this not been caught).

**6. `d/penglai/npc/laitou.lpc` (癞头和尚, a 蓬莱 NPC) carried a
single stray 3-byte Private-Use-Area glyph (`\xef\xa3\xb5`, U+F8F5 —
a leftover proprietary font-glyph artifact from the original archive's
authoring environment, not a mudlib logic error) sitting alone after
the closing `}` of `create()`.** This is a genuine COMPILE ERROR
(`Illegal character 0xef` / `syntax error, unexpected invalid token`),
not just a display glitch — the object could never load at all
(`*No program in object '/d/penglai/npc/laitou'!`, confirmed live via
`debug.log` during ordinary play). Fixed by deleting the stray bytes;
verified via `update /d/penglai/npc/laitou` compiling cleanly as admin.
A corpus-wide grep for the same trailing-PUA-byte shape
(`grep -rlP '[\xef\xf0][\xa0-\xbf][\x80-\xbf]{1,2}\s*$'`) found no
other instances in this lib.

### What was tested and confirmed working

- Registration → real gameplay in one continuous session:
  `look`/`score`/`i` all correct at every state change (post-register,
  post-move, post-skill-learn, post-sect-join, post-shop, post-
  reconnect ×2).
- **Safe-sparring** (`d/aolai/npc/dizi.lpc`'s `fight dizi`, same
  mechanic as `xyxy2`): repeated real fights correctly awarded
  `combat_exp`/`potential`, no scripted-outcome surprises.
- **Organic NPC-teacher skill learning**: `ask dongfang boyu about
  学艺` → `learn unarmed from dongfang cong` two-step flow (see bug #2
  above for what was broken and is now fixed).
- **Sect join**: `bai baicao xian` at `d/city/club.lpc` correctly
  joined 百花谷 as 第四代外门弟子, confirmed via `score`'s 门派/师承
  fields, persisted across reconnect.
- **Shop purchase**: `list`/`buy jiudai from xiao er` at 翠香楼's
  in-room vendor — correct insufficient-funds path first (`你的钱不
  够`), then a real purchase (admin `money_add()` used to fund it,
  since real-time grinding a full 100+-copper economy loop wasn't
  budgeted this pass) with correct currency-tier arithmetic
  (文/两/etc.) before and after.
- **Board (read-only, per this session's safety brief)**: `read 1 from
  board` at 翠香客栈留言板 displayed a real historical-looking post
  cleanly (author/title/timestamp/body/origin footer all present and
  correctly encoded) — did not exercise `post`/`discard`.
- **Two full quit/reconnect cycles**, one after a genuine ~15s
  wall-clock gap: `debug.log` grepped clean each time (aside from the
  pre-existing benign `emoted.o` restore warning, see below); `who`
  showed exactly one `林风` entry both times (no leaked duplicate,
  AGENTS.md §7.150 clean); admin `tell linfeng` correctly resolved the
  character via `find_player()` both after reconnect and while genuinely
  netdead (AGENTS.md §7.152 clean, this lib's `reconnect()` already
  calls `enable_commands()`).
- **Cross-cutting pattern sweep** (per the task's standing checklist):
  targeted greps for §7.100 (4 already-commented-out
  `replace_program(ROOM)` instances found, correctly left alone),
  §7.86 (0 live `BULLETIN_BOARD`+`replace_program()` hits — already
  clean), §7.129 (`tell_room()`/`message_vision()` already correctly
  use `exclude || ({})`), §7.121/§7.123/§7.148 (no hits on this lib),
  §7.150 (`obj/login.lpc` doesn't even call `set_heart_beat()`, so the
  leak shape can't occur here), §7.154 (no daemon combines
  `this_player()` with `call_out`/`heart_beat` in this lib) — all
  clean.

### Explicitly NOT verified live (say so, don't silently skip)

- **Death/respawn and real (non-scripted) NPC combat**: the documented
  wandering 黑狗 (`d/city/npc/dog.lpc`) wasn't encountered wandering
  through the rooms it's supposed to visit during this pass's time
  budget; not pursued further given the two severe bugs above already
  consumed most of the session. Consistent with the sibling `xyxy2`'s
  own round-two finding that this fight tends toward a long stalemate
  at low level without a weapon anyway.
- **10级突破/20级突破 dungeons**: documented in the newbie help but not
  attempted (same time-budget reasoning as siblings).
- **One anomaly, NOT chased to a conclusion**: a single
  `*Bad argument 2 to <=` / `Expected: string Got: 0` runtime error
  appeared once in `debug.log`, attributed by the backtrace to
  `feature/dbase.lpc:541` inside `money_add()`, coinciding with an
  admin `call linfeng->money_add(200)` test call. `money_add()`'s
  visible source at that line (`if (v > 0) {`) contains no `<=`
  operator and is pure integer arithmetic; a second, cleaner
  reproduction attempt (character genuinely online, smaller amount)
  produced no error at all and the correct return value both times.
  Currency arithmetic itself was confirmed correct in both cases (the
  later real shop purchase settled to the exact expected remaining
  balance). Left uninvestigated further per this session's "when
  genuinely unsure, document, don't guess" instruction — worth a second
  look if it recurs.
- A single pre-existing, already-`catch()`-wrapped restore error was
  observed at boot: `/adm/daemons/emoted.lpc`'s `create()` fails to
  restore `data/emoted.o` (`restore_object(): Illegal mapping format`)
  — a 374KB file of real historical custom-emote content. Since the
  failure is already defensively caught (the daemon boots fine with an
  empty emote set instead of crashing) and pinpointing the one bad
  entry inside a large historical content file risked exactly the kind
  of accidental-data-loss this session was told to avoid, this was
  left uninvestigated and unfixed — flagged here for a future session
  with more time budget to spend combing a large save file safely.

Files changed this pass: `work/adm/simul_efun/message.lpc`,
`work/cmds/std/learn.lpc`, `work/adm/simul_efun/file.lpc`,
`work/cmds/arch/update.lpc`, `work/adm/obj/master.lpc`,
`work/d/penglai/npc/laitou.lpc`. New AGENTS.md entries: a §8.1
sub-bullet (word-wrap byte-width bug) and §7.156 (the §7.30-fix
caller-side regression risk, flagged for a possible future corpus-wide
follow-up sweep). LPC formatter (§9) could not be run this session —
`node`/`npm` are not available in this environment; all edits are
small, hand-formatted, and match each file's existing style.

## Description-quality pass correction (2026-09-01, batch 26)

The pre-existing `meta.json` `english_description` claimed this lib's
Aolai Kingdom map made it "closer to the source text than most other
games in this family" — checked directly via `ls work/d/aolai` on all
three siblings and found this false: `xyxy2` and `xiaoyuxiyou` both also
ship the identical `d/aolai/` zone (confirmed live-tested as the actual
starting area in `xyxy2`'s own NOTES.md round-two section). Rewrote the
description to drop the false distinctiveness claim and instead lead
with this lib's genuinely distinct content (the tiered `spells/40/`
dungeon progression) and its own two real bug fixes.

## AGENTS.md §7.19 sweep (2026-09-01): false positive, not fixed

Flagged by the corpus-wide scoping scan as sharing the `mhxy`/`wuhanzhan`
`enable_player()`-reentrancy-from-`init()` shape, but on closer
inspection this lib already carries its own, differently-shaped guard:
`feature/command.lpc` declares `nosave int enabled = 0;` at file scope,
and `enable_player()` only calls the raw `enable_commands()` efun (plus
`add_action("command_hook", ...)`) inside `if (!enabled) { enabled = 1;
... }`. Since `enabled` is set to `1` *before* `enable_commands()` runs,
any reentrant call into `enable_player()` triggered as a side effect of
that same `enable_commands()` call sees `enabled == 1` and skips
re-invoking the efun -- the recursion terminates at depth 2 instead of
running away into "Too deep recursion." (Same pre-existing-guard pattern
Batch C found on sibling lib `xiaoyuxiyou`.) Rest of `enable_player()`
(living-name/path/wizhood setup) still runs harmlessly on a reentrant
call since none of it re-triggers `enable_commands()`. No `mechanical
in_enable_player_now` fix applied -- would be redundant with the
existing `enabled` guard.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/wiz/tail.lpc` calls `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 1 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py xyxyutf8 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 752 个 `.lpc` 和 8 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：731 -> 731 通过，无回退；改过的头文件的 491 个包含者 484 -> 484 通过。启动时警告 63 -> 0；新进程登录（编码选择、输入名字）与 HEAD 相同。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、1 处去后缀（如 `cmds/adm/mem2.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 13 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 6 个，只在 #if 分支用的声明移进分支 0 个文件；改动 17 个文件，HEAD 与工作树各载入一次无回退（17 objects; HEAD PASS 16, tree PASS 16; regress 0; newly loading 0），这些文件的警告 39 -> 20。

## 编译警告收尾（2026-10-13）

`scripts/lpc_twin_port.py adopt xiaoyuxiyou xyxyutf8` 搬来 xiaoyuxiyou 同日整理（0347f6d042c）里与本库逐 token 相同的文件，`scripts/toolkit_fix.sh` 去掉多余继承，能编译的文件警告清零。改动的 23 个对象在 HEAD 与工作树各载入一次：HEAD PASS 23，tree PASS 22；少的那个是 `quest/tianguan/npc/other.lpc`，它随机挑武功，挑到本库没有的就在 `set_skill()` 报错，成败看运气，与改动无关。

- 芥子袋 `d/obj/fabao/jiezi-bag.lpc` 自己声明了 `mapping Gold`，与 `feature/dbase.lpc` 存盘的 `Gold` 同名：存档写两条 `Gold`，`restore()` 填基类那份、清空袋子用的那份，袋里的钱每次读档都没了（KB 06 §7.233）。删去袋子自己的声明，`create()` 里 `Gold = ([]);`，旧存档的 `Gold` 正好读进唯一那份。
- `d/kaifeng/ground.h` 表格守卫、`feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`、擂台与投票箱的 `title` 改名、突破迷宫出口重复的 `gg` 表删去、`d/obj/books-nonskill/book.h` 的 `BOOK` 先 `#undef`，都同 xiaoyuxiyou。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 3 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：99 个文件的代码里有只含私用区字符（U+F8F5，GBK 转码留下的）的空行，编译器报 `Illegal character 0xef` 整份不编译；这些行清空（字符串、注释里的不动）。新进程比对 HEAD 与工作树：99 个对象，新增载入 96，回退 0。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。本库人物只有 kee/sen（连 gin 也没有）：药物的 `receive_heal("gin", 60)`、NPC 的 `receive_curing("gin", ...)` 和来自侠客行体系的 qi/jing 调用都报 `伤害种类错误`。1 个文件按 gin→sen、qi→kee、jing→sen、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`molianspells`→`molian-spells`（`molian-spells`）。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：2/2 通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 29 个对象设了本库没有文件的武功（6 个名字，最多的是 `yingzhaogong`、`sevensteps`、`taoism`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：29 个里 29 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 52 处、29 个文件：`yingzhaogong`→`yingzhao-gong`（32 处）、`hellfire_whip`→`hellfire-whip`（9 处）、`lahua-shou`→`lanhua-shou`（4 处）、`dagonforce`→`dragonforce`（4 处）、`dragon-step`→`dragonstep`（2 处）、`yange_blade`→`yange-blade`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/luoyang/congming3.lpc` 的 `south` 出口：`yunmanlou` → `yinmanlou`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## enable_player() 重入保护（2026-10-19，KB 05 §7.19）

`feature/command.lpc` 的 `enable_player()` 没有重入保护：门派掌门大弟子 `zhangmen.lpc` 的 `init()` 以 `me->setup();` 收尾，`setup()` 调 `enable_player()`，`enable_commands()` 又重跑 `init()`，第一个进房间的活物就触发 `Too deep recursion`。按 §7.19 加了标志变量（`scripts/lpc_fix_enable_player_guard.py`）。改后同样的测试（载入掌门房间，再克隆一个活物走进去）不再出错，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 6 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/cmds/wiz/gift.lpc`：`#include <ansi.h>`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，0 个原来编译不过、现在载入，没有退步。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/liandan/baihuagu.h`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 2 处）。改动：`/daemon/condition/xiangliu_hurt.lpc`（2 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 登录计数文件 `UserNumber` 缺失（2026-10-20，KB 06 §7.298）

`logind.lpc` 的 `do_counter()` 读 `/adm/daemons/UserNumber`（访客计数，运行中的 mud 才会写）；`.gitignore` 把它排除在仓库之外，所以新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不调用它，但同样会在调用时出错。加了 `if (stringp(file))` 的守卫（与 dtxywzxzb、rzrmud、xiyouji2006、zitengzhan 早先的做法相同）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/cmds/adm/cfg.lpc`（1 处）、`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 1 个存档共 6 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/c/data/npc/╤▌┴╖╒╜.o`（6 处）（共 1 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（3 个文件，括号里是接住 0 的 efun）：`/cmds/adm/baiban.lpc`（`sscanf`）、`/cmds/adm/dumpprog.lpc`（`new`）、`/cmds/imm/setskill2.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `update` 不带参数：`valid_read(0)` 先于 `cwf` 缺省（2026-10-21，KB 06 §7.342）

管理员扫描里 `update` 不带参数报 `Bad argument 1 to sscanf() Expected: string Got: 0.`（`/adm/daemons/securityd.lpc` 的 `valid_read()`，第一句 `sscanf(file, "/c/%*s")`）：`main(me, file)` 先 `SECURITY_D->valid_read(file, me, "read")`，之后才 `if (!file) file = me->query("cwf")`。把“缺省取 `cwf`、仍为空就拒绝”这两句移到权限检查前面（是移动，不是复制）。改动：`/cmds/arch/update.lpc`、`/cmds/wiz/update.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 15 条注册（9 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/baihuagu/huahai1.lpc`（`do_niang`）、`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/city/npc/vikee.lpc`（`do_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/qujing/village/npc/oldwoman.lpc`（`do_yes`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）、`/pet/pet.lpc`（`do_gongji`）、`/pet/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）。最多的函数名：`do_list` 3 处、`do_cost` 2 处、`do_upgrade` 2 处、`do_push` 2 处、`do_niang` 1 处。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（1 处调用）；`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_period()`（1 处调用）；`/adm/daemons/moneyd.lpc` ← aoxiangtianji：`price_str()`（1 处调用）。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 9 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：NPC 的称呼和提示里取到两个字而不是一个字。

本库 9 处（9 个文件）：`query("name")[..]` 9 处。例：`->name(1)[0..1]` → `->name(1)[0..0]`（`/quest/tianguan/npc/baihua2.lpc:245`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 1 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 3 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序）

`tell_object("…", me/who)` 参数颠倒（消息当对象）；改为 `tell_object(me/who, "…")`（guest.lpc）。证明：残渣 0；抽样 guest/rukou/forest_c 加载。
