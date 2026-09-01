
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
