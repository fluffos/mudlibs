# 三界传说.rar → `sjcs`

- Archive: `archives/三界传说.rar`, nested at `sjcs/sjcs/` inside the RAR
  (mudlib root one level down from the archive top). ~12.8k raw files,
  10,873 `.lpc` files after conversion.
- Proposed number: **059** (new, unique — see "Lineage/triage" below).
- Port: **40097** (as assigned; confirmed free against every other lib's
  `config.fluffos` before use).
- Status: **DONE** — boots clean, full registration verified end-to-end
  with a real Chinese name (秦风) natively AND under WASM, admin (`fluffos`)
  verified via `update` on both drivers.

## Triage / lineage

`grep -rIl inherit` finds thousands of hits — genuine LPC mudlib, not a
non-LPC engine. Diffed core files (`master.lpc`, `securityd.lpc`,
`logind.lpc`) against sibling `sanjieshenhua` (also assigned to this
batch, same "三界" branding) — all three differ substantially in line
count and content (495 vs 416 lines for `master.lpc`, 316 vs 747 for
`securityd.lpc`, etc.) — **not** a derivative pair despite the shared
title prefix (per AGENTS.md §2.1's warning that titles are not a lineage
signal). One coincidental match: both libs ship a byte-identical corrupted
`d/sea/npc/beast1.lpc` (see below) — most likely just shared common
ancestry several forks back (both plausibly ES-II-mega-family descendants,
per AGENTS.md §11), not evidence the two archives are the same codebase.
Treated as a fully independent unique game.

## State at handoff (this session)

A previous agent session had already: extracted the archive, run the
encoding+rename conversion, written `config.fluffos` (port 40097), applied
the loopback-allow patch to `band.lpc`/`securityd.lpc`, fixed the
`private`→`nomask` `command_hook` bug (3 files), disabled `dns_master` in
preload, and registered+admin-seeded the `fluffos` account (wizlist entry
`fluffos (admin)` already present, character already existed with
Chinese name 浮浮). No NOTES.md/README.md existed yet. This session
picked up from there, verified the existing work, and found/fixed two
things the interrupted session hadn't reached yet (below).

## Fixes applied this session

1. **166 files stuck as literal uppercase `.C`** (not renamed to `.lpc`)
   — exactly AGENTS.md §4.2 item 7's known trap (the rename glob and the
   forced-text-extension conversion check are both case-sensitive).
   Spread across `clone/armor/`, `clone/bq/`, `cmds/adm/`, `d/qujing/...`,
   `u/tonggang/...` — mostly clonable weapon/armor templates and a few
   NPCs/commands. Verified no lowercase `.c`/`.lpc` sibling existed at the
   same path (so no "which one is authoritative" ambiguity, unlike
   AGENTS.md's `zitengzhan` case) before a blanket `.C`→`.lpc` rename.
   Most were already correctly UTF-8 (the conversion pass's `file`-based
   text detection caught them fine even with the wrong extension); 6 were
   still raw GBK and needed an explicit `iconv -f GB18030 -t UTF-8` pass
   after the rename (`adm/CL/{SHUSHAN,HELL,MOON,LONGGONG,JJF,QIANG}.lpc`).
2. **2 genuinely-corrupted files** found by a full tree-wide Python
   UTF-8-decode scan (AGENTS.md §4.1's "stronger check"), both truncated
   mid-statement with a garbage binary tail in the RAW archive itself
   (confirmed via `xxd` against `raw/sjcs/sjcs/world/...` — not something
   the conversion pipeline broke):
   - `d/qujing/start/24/12.lpc` — truncated mid-`carry_object(...)` call;
     closed the file after the last complete statement with a comment
     noting the drop, per AGENTS.md §6.6 ("close truncated files with an
     empty body; don't fabricate content").
   - `d/obj/quest/shuijingqiu.lpc` — truncated mid-call
     (`...locate_quest(this_player(),arg` + garbage); completed the
     obviously-intended `);\n}` (matching the sibling `do_task()`
     function's identical one-statement-else shape) rather than stubbing
     it out, since the completion was unambiguous.
   - `d/sea/npc/beast1.lpc` — trailing 2 garbage bytes (`\xff\xba`) right
     after a clean `}\n\n` ending; simply truncated the 2 bytes. (Same
     exact corruption, same byte offset, found in sibling `sanjieshenhua`
     — see that lib's NOTES.md.)

## Verification (native)

Booted `cd libs/sjcs && ~/src/fluffos/build-debug/src/driver
config.fluffos` — clean boot, zero fatal errors in `log/debug.log` (only
the usual `#pragma`/unused-variable warnings).

Full registration flow (fresh id `wenshua`, real Chinese name **秦风**):
`gb` (encoding) → `no` (not-a-student gate) → `new` → English id (3-8
lowercase letters only) → Chinese name → password → confirm → email →
gender (m/f) → gift/stat menu (`9` to accept defaults, `y` to confirm) →
entered `南城客栈` (starting room). `look`, `score` (full 个人档案 stat
card), and `quit` all produced correct output.

Admin: logged in as `fluffos`/`Mud@2026` (already registered by the prior
session, character name 浮浮, `fluffos (admin)` line in
`adm/etc/wizlist`) → `update /adm/obj/master.lpc` → `重新编译
/adm/obj/master.lpc：成功！` (wizard write ACL confirmed working) →
`quit` clean.

## Verification (WASM)

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/sjcs` — same full registration flow (fresh id `wenshua`,
name 秦风) reached the same starting room; `look`/`score`/`quit` all
correct. Admin login as `fluffos` + `update /adm/obj/master.lpc` also
succeeded under WASM. **This lib is fully playable under WASM**, not just
"boots" — no IP-format/sockets-absent blockers hit on this lineage's
login path.

## Known remaining issues (documented, not fixed)

- The lpcc batch sweep (`lpcc_batch_raw.log`/`lpcc_fail.log`, retained in
  this dir) shows 422 failures out of ~10.8k files — not triaged
  individually past the two real content bugs above; per AGENTS.md §10.4
  most of these are expected false positives (missing daemons like
  `CLUB_D`/`F_DISASTER` that don't exist in this archive, `tail()` not a
  real efun here, `dump_socket_status()` admin-only debug commands) —
  cross-checked against the clean real boot log, none of them block the
  verified login/play path.
- A minor cosmetic gap: the first preload compile logs "Wrong permissions
  for opening file /u/feizei/log for append" (missing per-user log
  subdirectory for one wizard's home dir) — harmless, caught by the
  driver's own error handler, does not affect play.

## How to run

```
cd libs/sjcs
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40097 --timeout 15 \
  --send "gb" --send "no" --send "new" --send "yourid" \
  --send "你的中文名" --send "yourpass" --send "yourpass" \
  --send "you@example.com" --send "m" --send "9" --send "y" \
  --send "look" --send "score" --send "quit"
```

## 深度功能测试 / Deep functional test (round two, AGENTS.md §10.7)

Native driver, port 40097, tested via raw socket (finer control over
timing than `mudclient.py` for this lib's charset→age-check→id/New→
Chinese-name→password×2→email→gender→gift-selection wizard). Test
characters: `qfthree`/秦风三 (password `TestPassA`) is a clean, fully-
completed registration used for the main playthrough; `qftester` and
`qftwo` are two earlier registrations deliberately left stuck mid-gift-
wizard (see bug below) and kept as before/after evidence.

**Bug found and fixed, live-reproduced and re-verified**: `d/wiz/init.lpc`'s
`init()` schedules `call_out("get_start0", 0, me)` on every reconnect
while the account's gift-selection wizard is still incomplete
(`no_gift` still set), meant to automatically re-show the gift menu so
the player isn't left wondering what happened. `get_start0()` tried to
do this via `me->command("start")` — but the real `command()` efun
(`core.spec`: `int command(string)`) takes no object argument, so this
is a call_other to a method named `command` that is not defined
anywhere on the player object (confirmed via a lib-wide grep). FluffOS
silently no-ops an undefined call_other with no error raised anywhere
(not even in debug.log), so this reconnect path produced **zero visible
output**: a player reconnecting mid-wizard saw nothing at all after
"重新连线完毕。" — no menu, no error, no hint — and the only way out
was to already know to type the undocumented `start` command
themselves (confirmed live: typing `start` manually DID correctly
redisplay the menu, since that add_action registration itself works
fine). Root-caused by directly inspecting `data/user/q/*.o` for
`no_gift`, then confirming live with a raw-socket test that showed
identical silence even after a genuine 10-second wait.

Fixed by rewriting `get_start0()` to replicate `get_start1()`'s body
directly (using `tell_object(me, ...)` instead of `write()`, since
`write()` implicitly targets `this_player()`, which is unset inside a
call_out) and calling `get_start(me)` directly instead of round-
tripping through the broken `command()` call. Also fixed `show_gift()`
the same way (`write()` → `tell_object(me, ...)`), since it's reached
via the same call_out path. Verified live: after the fix, reconnecting
to a mid-wizard account (`qftwo`) auto-displays the full gift menu
within seconds with no manual `start` needed, matching the intended
"重新连线完毕" → immediate resume UX. A fresh, uninterrupted
registration (id → New → Chinese name → password ×2 → email → gender →
gift accept `9`+`y`) was independently confirmed to already work
correctly end-to-end (lands cleanly in 南城客栈/South City Inn per the
newbie doc), so this bug specifically affects the reconnect-while-
mid-wizard path, not first-time registration.

**Verified working**: full registration flow, `look`/`score`/`hp` all
render correctly with rich, properly-escaped ANSI formatting (no
orphaned escape sequences), clean `quit`. debug.log/driver stdout show
only pre-existing harmless compile warnings (unused locals, unknown
`#pragma`) throughout — no new runtime errors from any of this session's
testing.

**Not verified live this pass** (time budget went to the reconnect-
wizard investigation above): net-dead disconnect/reconnect after actual
gameplay has begun, skill learning, sect/faction join, shop purchase,
combat. Given the newbie doc's own detailed skill/combat/shop
instructions, this lib very likely has full playable content beyond
the registration wizard — a future pass should pick up from a
`qfthree`-style completed character and continue the rest of the §10.7
checklist.

**Files modified**: `libs/sjcs/work/d/wiz/init.lpc` (the fix
above). Test character saves kept as before/after evidence rather than
removed.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 46 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 扫描修复（`ROOM` 基类多余 `replace_program()`）

`#define ROOM "/std/room"`（`include/globals_old.h` 也定义了同一
宏值，但该文件未被任何源码 include，是死文件，未处理）：删除 479
处多余的、独立成行的 `replace_program(ROOM);`（保留
`inherit ROOM;`），475 处脚本自动删除；另有 2 份房间建造工具副本
手动修正——`clone/misc/roommaker.lpc` 是标准的"两套模板"简单变体
（1 处）；`obj/roommaker.lpc` 是"3 处出现"`room_code`/`str` 变体
（一处 `room_code +=` 拼接 + `do_saveroom()` 里两条分支各一处，共
3 处）。`work/data` 下未发现额外 `.lpc` 源文件。修复后全库仅剩 8
处历史遗留的 `//`-注释掉实例，均确认无害、未改动。已用
`build-debug` 驱动干净启动验证（0 个新增编译错误，端口 40097 正常
监听，`debug.log` 无新增 "cannot replace"/"cannot bind" 行）；未做
完整 §10.7 深度游玩测试。

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
`init()` body in this lib: 52 NPC/item files call `setup()` directly
or via `reset_me()` from `init()`, after `create()` already called
`setup()` once (which already made the object `living()`). Calling
`enable_commands()` a second time on an already-`living()` object makes
the driver re-invoke that object's own `init()` as a side effect, which
re-enters this same chain while the original call is still on the
stack -- genuine reentrancy, crashing with "Too deep recursion" (most
likely to surface on an NPC's first-ever preload/compile).

`feature/damage.lpc`'s `revive()` and `cmds/std/sleep.lpc`'s `wakeup1()`/`wakeup2()` call `enable_player()` again while the object is still `living()`. This confirms a bare `if (living(this_object())) return;`
guard would be the WRONG fix (it would silently break that legitimate
re-enable) -- used the same true reentrancy-flag fix as `mhxy` instead:
a `nosave private int in_enable_player_now;` set for the duration of the
wrapper's body, guarding only genuine same-call-stack reentrancy while
leaving every legitimate re-enable (revive/wakeup/disguise) unaffected.
`feature/command.lpc`'s `enable_player()` had a single fall-through exit
(no early `return`s), so one guard-at-top + one clear-at-bottom pair was
sufficient. Verified via a single-file `lpcc --batch` compile check
(PASS) -- not individually live-boot-tested.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/moon/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply sjcs`: 24 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 35 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 7 PASS -> 33 PASS, 0 that loaded before fail now, 26 more load.

24 files moved (24 `.lpc`); mostly under `adm/CL/LIWU` (10), `u/tonggang/obj` (7), `d/qujing/kusong` (2), `u/tonggang/npc` (2). A rescan with `scripts/lpc_warnings.py sjcs` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `std/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 254 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 3 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 2 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `std/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告清理；飞贼事件第一次就中断

1. `scripts/lpc_warnings.py --fix` 机械修复 1027 个文件，启动警告 507 → 0。HEAD 与修改后各编译一遍：唯一的差异 `d/qujing/sanda/shanpo1` 重试即通过（随机内容）。被删局部变量的审计 17 处都只出现在注释或同名函数调用里（`piggy` 的 `#ifdef` 与相关函数无关）。手工：`adm/daemons/natured` 的 `for (i;…)` 改 `for (;…)`；`d/moon/npc/yutu` 的 `kill_ob` 改 `void`，与 `feature/attack` 一致。
2. **飞贼事件只运行一次。** 预载的 `u/tonggang/feizei/feizei` 每 250 秒放一个飞贼，给他带的兵器、护具写成 `/u/tianlin/feizei/obj/…`，而这些文件在 `/u/tonggang/feizei/obj/`（本库没有 `u/tianlin/feizei`）。`carry_object()` 出错，`choose_feizei()` 在重新 `call_out` 之前中断，事件从此停止。路径改成本目录。启动后 2 秒的第一次放飞贼不再出错。
3. 验证（新进程，临时副本）：GB → 年龄问题答 `no` → `fluffos` 登录（admin）→ `look`、`score`、`i`、`quit` 正常。

## 深度功能测试（§10.7，2026-10-10）— 编译警告整理（机械部分与返回类型）

`scripts/lpc_warnings.py sjcs --fix`（5 个文件）之后：`scripts/lpc_fix_return_types.py` 把 22 个 `int init()`、5 个 `int create()` 等与基类 `void` 不符的驱动回调改为 `void`（函数体不返回值）；`lpc_diamonds.py` 删去 12 行多余的继承（`CLOTH`/`BOOTS`/`NPC`/`BLADE`/`SSERVER` 之外的 `F_CLEAN_UP`，`FORCE` 之外的 `SKILL`）。工具同时修正：它没认出 `obj/objmaker.lpc`、`d/changan/playerhomes/home.lpc` 里结尾带 `\r` 的 here-document 标记，曾把模板里的 `inherit` 当成代码。改动的 44 个文件 HEAD 与工作树各载入一次：40 -> 40 通过，无回退，警告 58 -> 2。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。3 个文件 8 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 wuhanzhan/xlqy_early 同源同修）：
  - `d/kaifeng/ground.h` 加 `GROUND_TABLES_INHERITED` 守卫；`colors.h` 加防重复包含。
  - `jiasha.lpc` 的 `init()` 先后调用 `cloth::init()` 与 `unique::init()`。
  - `yaoguai_type` 的重复声明去掉。
  - `feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`，与 `sanhua-counter` 自己存档的字段分开。
  - `lijing`/`xiwangmu` 的 `die`/`unconcious` 和 `yutu`/`jinren` 的 `kill_ob` 改 `void`。
  - `reporting.lpc` 各份删去未用的 `str`。
  - `std/equip.lpc` 的 `query_autoload()` 由 `int` 改为 `mixed`：物品子类返回自己的存档字符串。
  - 10 个带调用初始化的未用局部变量：删去声明，调用保留为语句。
  - `huashan-jian*.lpc` 删去多余的 `;`；`obj/roommaker.lpc` 删去被覆盖的 `special_props` 表。
  - 改动的 29 个对象 HEAD 与工作树各载入一次，无回退；定义 `query_autoload` 的 71 个文件重编译后没有警告。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。6 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

32 个文件（技能、绝招、兵器、书籍、区域 NPC 等）来自侠客行体系（qi/jing/neili），而本库人物是 gin/kee/sen/force：`receive_damage("qi", ...)` 报 `伤害种类错误`，`query("neili")` 永远为 0。按 qi→kee、jing→sen（本库学习/读书指令消耗的就是它）、neili→force、max_neili→max_force、jiali→force_factor 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自侠客行体系，按 qi→kee、jing→本库学习指令消耗的池、neili→force 改名（`scripts/lpc_port_es_props.py --any-file`）。


## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/d/obj/books-nonskill/hmeng014`、`/d/wusheng/shijie5`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。

## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`qianye-shou`。


## `->query_(` 笔误（2026-10-15，KB 06 §7.245）

调用不存在的函数 `query_`，call_other 静默返回 0，相关判断永远按 0 计算。改为 `->query(`：`buhui`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`yueya-chan/feicha`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`lanhuashou`→`lanhua-shou`（`/d/pansi/npc/xiang`）；`yan-fly`→`yanfly`（`yanfly`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。1 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`liangyi-sword/yin`。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

8 个文件、9 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`），多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/obj/weapon/staff/tc_staff`、`/d/city/npc/obj/changqiang`、`/d/city/npc/obj/bingfu`）。本库 NPC 基类 `std/char/npc.lpc` 的 `carry_object()` 第一句是 `if (file->query_unique())`，对不存在的文件直接 call_other，驱动在这里报 `call_other() couldn't find object`，`new()` 来不及返回 0，所以只要 NPC 带着一件本库没有的物品就载入不了（调用处加判断对它无效）。在它前面补 `if (!objectp(load_object(file))) return 0;`（`--base`），缺的物品就跳过，NPC 照常载入；上面那些调用处同样改成带判断的块（基类以后改回去也不怕）。载入检查：改动的文件改前能载入 1 个，改后 18 个（17 个原来载入不了），没有退步；其余 1 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`。`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：0 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。

## 蓬莱三星的 `ref()` 是保留字（2026-10-18，KB 04 §6.14）

福星、禄星、寿星（`d/penglai/npc/`）里有一个函数叫 `int ref ()`，`call_out("ref", 20)` 去调它；`ref` 在 FluffOS 里是关键字（引用），`unexpected L_REF`，三个 NPC 都载入不了。函数和 `call_out` 都改叫 `reff`（本系里 dtxyzjb、zitengzhan 早就这么改，`call_out` 却没跟着改）：`d/penglai/npc/fuxing.lpc`、`d/penglai/npc/luxing.lpc`、`d/penglai/npc/shouxing.lpc`。改后载入：3/3 通过。

## `d/moon/obj/poem` 两句诗丢了收尾的引号（2026-10-18，KB 03 §4.6）

`string *poem` 数组里 `"不放玉花飞堕地，留在广寒宫阙。,` 和 `"把酒送春春不语，黄昏却下潇潇雨。,` 的收尾引号没了（转码时跟半个汉字一起丢了），下一行的开引号把字符串合上，后面的诗句成了代码：`Illegal character 0xe6`，整个物件载入不了。补回 `",`。载入：通过。

## `d/shendian/obj/niepan` 的收尾引号变成了私用字符（2026-10-18，KB 03 §4.6）

`set("long", HIR"……五种符号<U+E4D4>NOR);` 里本该是 `"` 的位置是一个私用区字符（转码时半个汉字加引号被换成了它），`Illegal character 0xee`，整个物件载入不了。换回 `"`。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 11 个对象设了本库没有文件的武功（15 个名字，最多的是 `halberd`、`fumozhou`、`guiyuanforce`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：11 个里 9 个通过，其余 2 个停在别的错误上（`d/city/npc/gif-shizhe`：*No program in object '/d/city/npc/gif-shizhe'!；`d/wuguan/npc/master`：*No program in object '/d/wuguan/npc/master'!）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 14 处、14 个文件：`dagonforce`→`dragonforce`（4 处）、`yange_blade`→`yange-blade`（3 处）、`hellfire_whip`→`hellfire-whip`（2 处）、`dragon-step`→`dragonstep`（2 处）、`lahua-shou`→`lanhua-shou`（1 处）、`changqaun`→`changquan`（1 处）、`cuixi-zhang`→`cuixin-zhang`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::buy_object()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 技能基类丢了“预备武功”那一段（2026-10-19，KB 06 §7.262）

`feature/skill.lpc` 有 `skill_map`/`map_skill()`，却没有预备武功（`prepare_skill`）这一块：变量 `skill_prepare`、`prepare_skill()`、`query_skill_prepared()`、`query_skill_prepare()`。来自 xkx 系列的 NPC 在 `create()` 里调用 `prepare_skill("cuff", ...)`，于是 `Undefined function prepare_skill` 整个 NPC 载入不了。从同系的 xkx100 把这一块原样补回（声明加在 `skill_map` 后面，函数加在文件末尾），受益 NPC 1 个：`d/wuguan/npc/master`。（`scripts/lpc_transplant_function.py`）

## 同一个函数原样贴了两遍（2026-10-19，KB 06 §7.264）

同一个文件里同一个函数被原样贴了两遍（除空白外逐字相同），驱动报 `Redeclaration of function`，整个物件载入不了。删掉第二份及以后的副本，共 1 处：`/d/pkdao/room1.lpc` 的 `greeting()`。（`scripts/lpc_fix_dup_functions.py`）

## 全局头文件丢了 10 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `CLUB_D`、`CITY_OB(city,room)`、`WEAPON_OB`、`HOURLY`、`DAILY`、`WEEKLY`、`MONTHLY`、`YEARLY` 等共 10 个，用到它们的物件（名单里 14 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 9 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/qujing/wuji2/shandao3.lpc` 的 `west` 出口：`guankou` → `goukano`
- `/d/qujing/wuji2/shandao4.lpc` 的 `east` 出口：`guankou` → `goukano`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/daemon/skill/qishang-quan.lpc` 的 `#include "/u/fly/skill/eff_msg.h"` 改成 `/daemon/skill/eff_msg.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/daemon/skill/qishang-quan/huoqiu.lpc` 的 `#include "/u/fly/skill/eff_msg.h"` 改成 `/daemon/skill/eff_msg.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/daemon/skill/taiji-jian.lpc` 的 `#include "/u/fly/skill/eff_msg.h"` 改成 `/daemon/skill/eff_msg.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）
- `/daemon/skill/tianmaliuxing-quan.lpc` 的 `#include "/u/fly/skill/eff_msg.h"` 改成 `/daemon/skill/eff_msg.h`（巫师目录 `/u/…` 不在档案里，头文件的唯一副本在区域里）

逐个物件与 HEAD 对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的 inherit / include（2026-10-19，KB 06 §7.274）

`/daemon/class/moon/moonshentong/shiyue.lpc`：`inherit SSERVER;`。这些指令接在上一行 `//` 注释的末尾（档案里丢了换行），成了注释的一部分，驱动看不到：缺 `inherit` 的技能报 `Undefined function offensive_target`，缺 `#include <weapon.h>` 的兵器报语法错误。`scripts/lpc_fix_swallowed_directive.py` 把换行放回去。载入检查 1 个文件，1 个原来编译不过、现在载入，没有退步。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `daemon/skill/qishang-quan.lpc`：`valid_enable()` 的右花括号后面多了一个 `;`，删掉。
- `d/longzhu/npc/long.lpc`、`d/wosshipg/long.lpc`：文件开头声明了 `int long();`，这个函数在文件里从没定义过，类型又和 `/feature/name.lpc` 的 `string long()` 对不上（`Function long inherited from … does not match current function in return type ( string vs int )`）；删掉这行声明。
- `adm/CL/YI.lpc`：`query_autoload()` 的返回类型改成 `mixed`（标准整理轮，基类声明 string）。

逐个与 HEAD 对比载入，没有退步。

## 补回缺失的基类 `UNARMED`（2026-10-19，KB 04 §6.15，`scripts/lpc_restore_bases.py --retry`）

`inherit UNARMED;` 的基类文件 `/std/weapon/unarmed.lpc` 本库没有，宏也没有定义。从 hxxtjqb 取来文件，并在 `include/globals.h` 补上 `#define UNARMED`；`/d/city/obj/dami.lpc` 因此载入。同一轮里重试的其余几个基类（这个库的 JOBNPC / SUPER_NPC / QUEST_OB / F_GUARDER 等）载入时仍缺别的东西，已经撤回，没有留下文件或宏。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/obj/quest/quest_cl.lpc`（dtxywzxzb）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/daemon/skill/unused/snowshade-force.lpc`。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 菩提祖师的银针：`last_time` 没有声明（2026-10-19，开机自检）

`d/lingtai/npc/puti.lpc` 的 `give_zhen()` 用 `last_time` 限制银针发放速度（`if ((time() - last_time) < 60)`，发出后 `last_time = time()`），整个文件没有声明这个变量，编译不过：`Undefined variable 'last_time'`。因为它在启动时的预装入列表里，第一个登录的人在开机屏幕上就能看到这一行错误。文件头加 `int last_time;`（`hxxtjqb` 里是同一个文件，同样处理）。修后开机自检（`scripts/lpc_boot_survey.sh`）零警告零错误。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：“你是怎么混进来的？给我滚！”只对没有门派的人生效（方寸山三星洞以外的门派的人反而放进来）。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/d/lingtai/npc/puti.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## 浩劫系统 `verdict_time()`：领头玩家已经离线时 `lead->name()` 报错，戒严不解除（2026-10-20）

三十分钟后收场时 `lead`（接战书的玩家）若已退出游戏就是 0，`lead->name()` 在宣布战果的 `message()` 里报错，后面的 `LOGIN_D->set_madlock(0)` 不再执行，戒严一直保持，`quit` 指令因此对所有人关闭。改为 `(lead ? lead->name() : "各派豪杰")`。改动：`/feature/disaster.lpc`（2 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 13 处）。改动：`/clone/medicine/liushen.lpc`（1 处）、`/cmds/wiz/dns.lpc`（1 处）、`/d/city/mjlady3.lpc`（3 处）、`/d/longzhu/npc long.lpc`（1 处）、`/d/shendian/babu/obj/longzhua.lpc`（4 处）、`/d/wiz/npc/jing.lpc`（3 处）。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/wiz/callouts.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `tail` 指令：`tail(file)` 驱动里没有（2026-10-20，KB 06 §7.291）

`cmds/*/tail.lpc` 调用 MudOS 的 `tail()` efun，FluffOS 没有，指令编译不过。模拟 efun 文件里补了 `tail(file)`（Discworld 家族的兼容版：文件最后约 20 行，从完整的一行开始，存在返回 1；`scripts/lpc_add_sefun.py tail`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/std/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dumpprog.lpc`（`new`）。加载检查 HEAD 与工作树对照，没有退步。

## `cron.lpc`：`emery()` 用循环外的下标，第一次越界就让 cron 停摆（2026-10-21，KB 06 §7.345）

怪兽入侵事件 `emery()`（`/adm/daemons/cron.lpc`）末尾 `for (m = 0; m < sizeof(user); m++) user[i]->set("kill_guaishou", 1);`：`i` 是前面随机选的地区下标，循环变量 `m` 没用上，同一个玩家被标记 `sizeof(user)` 次，在线人数不到 `i + 1` 时下标越界（`Array index out of bounds`，yueyingqiyuan 管理员扫描里的控制台行；`call /adm/daemons/cron->emery()` 一个人在线时四次里三次抛错）。`init_cron()` 在 15 分钟的整点调用 `emery()`，之后才 `call_out("init_cron", 60)` 重新排自己：抛错之后重排没有执行，玩家自动存盘（`autosave()`）、动态任务刷新（`TASK_D->init_dynamic_quest()`）和后面所有事件在这次启动里都停了。改成 `user[m]`（yueyingqiyuan 上实测：连续六次 `emery()` 都正常返回）。这个标记档案里没有任何地方读它（`go.lpc` 里的用法是注释掉的）。

## 七龙珠 `combine`：六次 `present()` 都存进了 `b`（2026-10-21，KB 06 §7.348）

每颗龙珠的 `do_combine()` 先检查身上有另外六颗：`if (!(b = present("liang longzhu", me))) ... if (!(b = present("fen longzhu", me))) ...`，六句都写成 `b =`，后面 `destruct(b); destruct(c); ... destruct(g)` 的 `c` 到 `g` 一直是 0。这几个库的 `destruct()` sefun 对 0 不抛错（原始 efun 也不抛），结果是合成神龙时只消耗了最后一颗和合成者自己，另外五颗还留在身上，可以反复合成。改成 `b, c, d, e, f, g`（shenmo 的 `/d/longzhu/obj/*` 是对的）。sjsh 上实测：HEAD 合成之后背包里还剩青、黄、蓝、粉、亮五颗，改后只剩神龙。改动：`/d/longzhu/obj/1.lpc`、`/d/longzhu/obj/2.lpc`、`/d/longzhu/obj/3.lpc`、`/d/longzhu/obj/4.lpc`、`/d/longzhu/obj/5.lpc`、`/d/longzhu/obj/6.lpc`、`/d/longzhu/obj/7.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`find_seal`：`disapprear` → `disappear`（法术产生的封印十分钟后从不消失）。改动：`/d/jjf/obj/find_seal.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 18 条注册（11 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/CL/YI.lpc`（`hun`）、`/d/changan/pinqiting.lpc`（`do_pass`、`do_resign`）、`/d/city/npc/duguoyin.lpc`（`do_vendor_list`）、`/d/eastway/npc/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/eastway/petboss.lpc`（`do_cost`、`do_list`、`do_upgrade`）、`/d/milin/npc/guard.lpc`（`do_bian`）、`/d/pansi/npc/qingxia.lpc`（`do_yes`）、`/d/qujing/jisaiguo/obj/luche.lpc`（`do_get`、`do_put`）、`/d/qujing/wudidong/cave2.lpc`（`do_push`）、`/d/zhuxian/npc/guard.lpc`（`do_bian`） 等共 11 个文件。最多的函数名：`do_bian` 3 处、`do_cost` 2 处、`do_list` 2 处、`do_upgrade` 2 处、`do_push` 2 处。没有动（读过）：`/d/wizz/stey/npc/rulai1.lpc` 的 `do_cancel`（对象本身编译不过，登记留着，等对象能加载再处理）、`/daemon/skill/rabbit.lpc` 的 `wave`（对象本身编译不过，登记留着，等对象能加载再处理）、`/daemon/skill/rabbit.lpc` 的 `full`（对象本身编译不过，登记留着，等对象能加载再处理）、`/daemon/skill/rabbit.lpc` 的 `hun`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/qujing/chechi/wugu.lpc` 的 `do_kan`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。1 个文件里 2 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 1 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 1 个，现在 1 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_period()`（2 处调用）。

## 代码里写死 `.c` 后缀的路径（2026-10-22，KB 06 §7.356）

`carry_object("/x/y.c")->wield()`、`new("/x/y.c")`、`inherit "/x/y.c"`、出口 `"down" : "/x/y.c"`、商店货单 `"/x/y.c" : 10` 这类字符串，压缩包里的文件早已改名成 `y.lpc`；明确写出的后缀按原样查找（KB 03 §4.2），找不到文件，`new()` 返回 0，`0->wield()` 报 `Bad argument 1 to EFUN call_other() Got int(0)`，NPC 的 `create()` 中途退出、整个对象加载不了。`scripts/lpc_fix_dotc_path.py` 把 1 个文件里的 1 处 `.c` 改成 `.lpc`（只改文件存在于 `.lpc`、不存在于 `.c` 的代码字符串；注释、巫师目录、两种写法都不存在的路径不动）：`/d/qujing/kusong/npc/zhangmen.c` 等。 加载检查（HEAD 与工作区对比，改动的 2 个文件）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## `/d/qujing/kusong/obj/WEAPON4` 大写文件名，随机兵器取不到（2026-10-22）

`/d/qujing/kusong/npc/yao1` 用 `str = "/d/qujing/kusong/obj/weapon0"; str[strlen(str)-1] = '0' + random(5); carry_object(str)->wield()` 随机挑一件兵器，`weapon0` 到 `weapon3` 是小写文件名，第五件存成了大写的 `WEAPON4.lpc`（压缩包来自不分大小写的系统，路径是运行时拼出来的，`scripts/lpc_case_paths.py` 看不到）：抽到 `weapon4` 时 `carry_object()` 返回 0，`->wield()` 报 `Bad argument 1 to EFUN call_other() Got int(0)`，五分之一的妖怪刷不出来（goto 探测在 sjcs 的 `/d/jjf/front_yard` 里碰到）。`git mv` 成小写的 `weapon4.lpc`（内容与 mhxy 等其他同系的 weapon4 一致）。证明（`scripts/lpcc_eval.py`，HEAD 与工作区各一个新进程）：`load_object("/d/qujing/kusong/obj/weapon4")` 在 HEAD 返回 0，改名后得到对象。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 另有 3 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 1 个文件里有 1 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`/log/nosave/LASTCRASH` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/obj/board/pkboard`；`/d/pkdao/pkdao.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/dlog`（`adm/daemons/moneyd.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 是 `write_file(LOG_DIR + file, text)`，目录不存在就抛同样的错误（实测）。把 `log/dlog` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 2 个文件里 4 行只含这个指针的行（`"复仇" : (: avenge :),` `"漫天飞雪" : (: ask_tian :),` `"下山": (: expell_me :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 3 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 3 处（2 个文件）：拼名字的赋值 3 处。例：`name[0..1]` → `name[0..0]`（`/d/nanhai/npc/master.lpc:109`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## `maximum evaluation cost : 400000`：南岩峰高台一次要创建 14 个 NPC，房间加载不了（2026-10-22，KB 06 §7.90）

`d/wudang/gaotai.lpc` 的 `objects` 是 8 个八卦弟子、5 个五行弟子和 1 个 `yan`，全在第一个玩家走进房间的那一次加载里创建；本库 `config.fluffos` 的 `maximum evaluation cost` 是 400000，新进程里 `load_object("/d/wudang/gaotai")` 报 `Too long evaluation. Execution aborted.`（`catch()` 也接不住），武当上山路上的真武剑阵房间进不去。KB 06 §7.90 的通行值是 5000000，改成 5000000。证明（`scripts/lpc_reach_census.py sjcs --load` 的 FAIL 行；`scripts/lpcc_eval.py` 的暂存树取的是 HEAD 的配置，要改暂存树里的 `config.fluffos` 再用 `lpcc --batch` 跑）：400000 时失败，5000000 时 `e=0`、房间里 14 个对象。同样低于 5000000 的配置还有 dtslmud 600000、kxkj1 300000、mundoscuro 500000、xiyouji2003 600000、yxcs 1000000、huoying 2000000、kxkj 1500000、tianxia 2000000、skylib 1800000、sanjieshenhua 3000000（nightmare3 是子模块），它们的可达房间在这一轮的可达性普查里没有出 `Too long evaluation` 的行，所以没有改。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {`（`/adm/daemons/logind2.lpc:1044`）；`if( (strlen(name) < 4) || (strlen(name) > 16 ) ) {`（`/d/city/npc/huangfeihong.lpc:52`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 13 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 6 处（3 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 兰陵出口仍指向 /u/calvin、大殿北去 /u/fly（2026-10-23，KB 06 §7.367）

可玩的兰陵已在 `/d/lanling/`（`lldj1`、`beijiao4` 等），出口字符串还写着作者目录 `/u/calvin/兰陵/地区/…`，走动即死出口；皇宫大殿北向 `/u/fly/doublesword/houdian` 同样不存在。`scripts/lpc_fix_calvin_lanling.py` 在目标 `.lpc` 存在时改写为 `/d/lanling/<stem>`，并删掉大殿那条北向。本库 8 处。证明：sjshv2578bb 的 `lldj1` 北向加载 `beijiao4`；xianlvqiyuan 大殿 HEAD 有北向、改后没有。未映射：`书局`、`钦陵宫`（库内无对应文件）。


## 家丁 CLOTH_OB()/WEAPON_OB() 调用式宏（2026-10-27，KB 04 §6.16 Also）

`d/wuguan/npc/jiading.lpc`（及 `jiading1`，xlqy 系在 `d/dntg/hgs/wuguan/npc/`）写 `carry_object(CLOTH_OB("cloth"))` / `WEAPON_OB("changjian")`：库中没有带参的 `CLOTH_OB`，`WEAPON_OB` 在 `globals.h` 只是裸路径 `"/d/obj/weapon/"`，展开成 `"/d/obj/weapon/"("changjian")` 语法错误，NPC 无程序。同目录其它 NPC 用 `__DIR__ "obj/cloth"`；剑在 `/d/obj/weapon/sword/changjian`。改成这两条（目标文件均在树内）。证明：HEAD `Undefined function CLOTH_OB`；改后 `new()` 成功且 inventory 为 2。


## 黑风山 pusa1 用未声明的 ob 且函数外残留 call_out（2026-10-27，KB 06 §7.348 Also）

`d/qujing/heifeng/npc/pusa1.lpc` 的 `announce_success(object who)` 写成 `if (!ob->query("obstacle/hf"))`（`Undefined variable 'ob'`），同目录 `pusa.lpc` 是 `who->query("obstacle/hf") == "done"`；`who->save(); }` 之后还残留 `call_out("die"...); return; }`，落在函数外（`unexpected L_STRING`），对象无程序。改成与 `pusa` 相同的门，并删掉残留语句。证明：HEAD 加载失败；改后加载成功。


## 洗衣盆 is_container 映射缺值编不过（2026-10-27，KB 04 §6.28 Also）

`d/gao/obj/pen.lpc`（或 `d/qujing/gao/obj/pen`）的 `is_container()` 写成 `set("objects", ([ "/u/bula/gao/obj/kaoji" ]));`：映射只有键没有值（`unexpected ']'`），对象无程序。同族 hy5 / xyj2000 已把该函数注释掉。改成标准的 `return 1;`。证明：HEAD 加载失败；改后加载成功。


## 星君/罗汉模板缺 ID 宏（2026-10-27，KB 06 §7.348 Also）

`d/dntg/sky/stars/star.lpc` 与 `d/nanhai/luohan/npc/luohan.lpc` 用 `title[ID]` / `first_name[ID]`，真正带号的副本是 `#define ID N` 再 `#include` 本文件；单独编译模板时 `Undefined variable 'ID'`。加 `#ifndef ID` / `#define ID 0` / `#endif`，带号 include 仍用各自的 N。证明：HEAD 模板加载失败；改后模板与 `stars/5`、`luohan5` 均加载成功。


## 雷神 check 在 stop_fight 定义之前调用且 call_out 缺逗号（2026-10-27，KB 04 §6.28 Also）

`d/qujing/start/24/1.lpc` 的 `check()` 里调用 `stop_fight(who)`，函数却写在后面（`Undefined function stop_fight`）；`call_out("lost", 1 who)` 少了逗号（`unexpected L_DEFINED_NAME`）。把 `stop_fight` 挪到 `check` 之前，并改成 `call_out("lost", 1, who)`。证明：HEAD 加载失败；改后加载成功。


## toy 旁缺 message.h（2026-10-27，KB 04 §6.23 Also）

`obj/toy/*.lpc`（及少数 `obj/obj/toy`、嵌套副本）写 `#include "message.h"`，引号 include 只解析同目录；本 lib 的 `d/obj/misc/message.h` 有同内容副本，toy 目录没有。玩具对象无法编译（`Cannot #include message.h`）。从本 lib 的 `d/obj/misc/message.h` 复制到缺失的 toy 目录旁。证明：HEAD `buwawa` 加载失败；改后加载成功。

## 悬空 ::init / unique::init（2026-10-27，KB 06 §7.259 Also）

`kugu-1/2/3`、`kunxian-suo` 写 `::init();`，`tianyi` 写 `unique::init();`，而 `F_UNIQUE` / `ITEM` / `feature/unique` 没有 `init`；本驱动编译报 `Unable to find the inherited function 'init'`（tianyi 带 `in file 'unique'`），物件无法加载。老驱动把空父调用当返回 0。`lpc_fix_dangling_super.py` 删掉这些语句；`cloth::init()` 保留。证明：HEAD 加载失败；改后加载成功。

## dami 误调 init_unarmed（2026-10-27，KB 04 §6.25 Also）

`d/obj/food/dami.lpc` 继承 `ITEM`+`F_FOOD` 却调用 `init_unarmed(5)`（并 `#include <weapon.h>`），未继承空手兵器基类，驱动报 `Undefined function init_unarmed`。手足 hymud 已注释该行。删掉该调用与无用的 weapon 头。证明：HEAD 加载失败；改后加载成功。

## 深度功能测试（2026-10-27，§6.25 gif-shizhe 字符串截断）

`d/city/npc/gif-shizhe` 与 `u/xot/gif-shizhe` 在 `tell_object(HIR"飞霞礼物使告诉你,你得到了` 处文件截断（`End of file in string`）。按同目录完好的 `gift-shizhe2` 收尾补上 `who` 参数、完整字符串、`command(chat*)` 与 `return 1;`。证明：HEAD 失败；改后两处均加载。

## 深度功能测试（2026-10-27，§6.25 tell_object 缺 me（自动放弃/愿否））

一参 `tell_object("…")` 在已有 `me` 时改为 `tell_object(me, "…")`（city.lpc）。证明：抽样 city / xiaolongnv 加载。

## 深度功能测试（2026-10-27，§6.25 one-arg tell_object / skirt 截断）

`cmds/adm/skirt` 的 `tell_object(". \n")` 按同系 snoop 补回停止/开始监听文案与 `ob`。


## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序残渣）

guest：`tell_object("…", who)`→`tell_object(who, …)`。


## 深度功能测试（2026-10-27，§6.25 tell_object 路径当房间）

`tell_object("/…", …)` → `tell_room(load_object("/…"), …)`（去掉 `.lpc`）。


## 深度功能测试（2026-10-27，§6.25 one-arg message_vision）

`message_vision("…")` 补第二参（`me` / `TP` / `this_player()`）。


## 深度功能测试（2026-10-27，§6.10 未知 pragma save_binary/optimize）

删除本库中 FluffOS 不认的 `#pragma save_binary` / `#pragma optimize…` 行。

