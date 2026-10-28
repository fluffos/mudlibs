# StickLib (sticklib) — porting notes

Source: git clone https://github.com/StickMUD/StickLib (commit a0750273104c49d7d506d92f232b221b64577853, cloned 2026-09-05); repo root is the mudlib. Converted 2026-09-05. Config name `StickLib`.
Slug `sticklib`, number **977**, port **40286**.

**This is an LDMud → FluffOS conversion.** Discovery triage normally
drops LDMud-lineage libs; this onboard is an explicit exception in the
same family as `questmud` / `acme` (AGENTS.md §7.158).

This collection’s copy is a snapshot, not a live mirror. Do not onboard
the same upstream repo again.

## 0. Layout

Repo root **is** the mudlib. `raw/` is gitignored. Original LDMud master
preserved as `/secure/master_ldmud.lpc`.

## 1. Convert (2026-09-05)

`convert_lib.sh` with UTF-8 source encoding (already UTF-8 English /
German sources). `.c` → `.lpc` rename + literal `.c"` fixups +
`static`→`nosave` as usual.

## 2. FluffOS port (LDMud → FluffOS)

The archive is **LDMud 3.x** (`set_driver_hook`, `inaugurate_master`,
`#'` / `unbound_lambda` closures, multi-file or directory simul_efun).
FluffOS has none of those driver hooks. A mechanical dialect rewrite of
the whole tree is not attempted; the original login/command stack is
kept as source and not loaded.

`config.fluffos`: master `/catalog/master`, simul `/catalog/simul_efun`,
global include `"/catalog/auto.h"`, port **40286**,
`lazy resets : 1`.

Catalog overlay (questmud §7.158 cluster):

- `/catalog/master.lpc` — `get_root_uid`/`get_bb_uid`, `creator_file`
  always returns string `"BACKBONE"`, `valid_read` includes
  `load_object`/`recompile_object`/`include`/`restore_object`,
  `valid_override` returns 1, `error_handler` → `/log/catch`
- `/catalog/simul_efun.lpc` — thin `cat`/`log_file`/`exists`
- `/catalog/login.lpc`, `/catalog/player.lpc` — name/password → Void
- `/catalog/void.lpc`, `/catalog/workshop.lpc` — look/score/quit surface

## 3. Live-verified (native, port 40286)

Create `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score` /
`north` (workshop) / `south` / `quit`. Reconnect after cold restart
reloads `data/f/fluffos.o`.

## 深度功能测试（§10.7, 2026-09-05）

Catalog overlay only — the StickMUD LDMud 3.x world is not loaded.
Organic `fluffos` / `Mud@2026` on native 40286: Void `look` / `score`
(level 1, hp 20/20) / `inventory` / `north` workshop / `south` /
`quit` persist. Reconnect: Void `look` / `score` / `quit`. Shop,
combat, guild, death: **N/A** (needs a real LDMud driver).

Logs this boot (PID started 20:09:19, live fd
`libs/sticklib/log/debug.log`): stdout + debug.log clean.
`work/log/catch` proven live with a one-shot `catchprobe`
(`CAUGHT /catalog/player.lpc *catch-path-probe`) then reverted;
play itself left no other catch lines.

## 6. Full dialect port (Strategy A, 2026-09-05)

Catalog Void/workshop is no longer the live world. User asked for
the real StickMUD, not a demo skeleton.

What loads now:

- `/catalog/login` still handles name/password. `/catalog/player`
  `enter_world()` moves into `/room/church` (Temple yard, Newbie
  York).
- `/lib/room` rewritten as a FluffOS Stick-API subset: 1-arg
  `set(NO_PK)`, `add_exit`/`add_item`/`add_permanent`,
  `command_driver` → `call_other`. Original LDMud room (closures,
  3-arg implode, PEACE_D/PARTY_D) is `/lib/room_ldmud.lpc`.
- `/catalog/master` `compile_object` delegates to
  `/areas/tristeza/virtual/server` so `S7_6` etc. clone
  `tristeza_room` (FluffOS renames the clone to the virtual path).
- Church `#'query_door_desc` / clock closures → function-name
  strings. Elevator `call_other` uses an explicit path (FluffOS
  parsed `(int)AREA+"rooms/elevator"->fn` as `'rooms/elevator'`).
- `mud_name.h` no longer redefines FluffOS's predefined `MUD_NAME`.
  Simul shims: `member`/`m_delete`/`m_indices`/3-arg `implode`/
  2-arg `move_object`/`nature()`/`notify_fail` returns 0 /
  `symbol_function` / `funcall` leaves literal strings alone.
- `/lib/living`, `/lib/npc`, `/lib/group_npc` are FluffOS subsets
  (originals `*_ldmud.lpc`). `/lib/treasure` keeps its source with
  `closure` → `mixed`. Room `create()` calls `reset_room()` so
  FluffOS lazy reset still stocks shops.

Live walk (native 40286, 2026-09-05, organic `fluffos` /
`Mud@2026`):

- Temple yard look; `look at pit` / `look at door` (closed) /
  `look at clock` (midday fallback); `score`; `pray` ("No sense
  praying unless you're dead.").
- East → Hall of Races (sign look). West back to the yard.
- South → virtual Market Square (S7_6). West → S6_6. West →
  Common Shop. Named shopkeeper present (Culdaff / Falo /
  Nallihan). `list` shows torches and torches of darkness at
  82 gold. `buy torch` → inventory "A torch" / "A torch of
  darkness", gold 200→118→36.
- East from physical S8_6 → Adventurers' Guild loads
  (`8a9558ad094` + `a6e16773d6a`). Sign lists cost/advance/
  list. `cost`: "You still need 1014 experience points for
  next level" (no player-visible ERROR). User graph present.
  `/lib/guild` uses `mixed guildInit`; `#'make_noise` is
  `call_out("make_noise", …)`.
- QUEST_D (`ac61209dffb`): LDMud multi-value mappings rewritten
  as mapping-of-arrays (original `questd_ldmud.lpc`). `quests`
  lists the enabled set. `qp_for_level` still returns 0
  (upstream Kieve stub), so advance is XP-only.
- Eat at Joe's LIVE (`9316443fe04` + `aa89abf6bca`): church →
  S7_6 → S6_6 south → Main Street → Dragon Street north →
  Ladywell west → Joe's. Joe stays in the restaurant (no
  city wander). After ~1s he swallows the player; stomach
  awards QUEST_EAT_AT_JOES (`M6a`). `score` shows `Quests:
  M6a`. Reconnect persists. Guild `quests` drops from 14 to
  13 (Eat at Joe's gone). Stomach has no exits (upstream).
- Well maze LIVE (`6bbecdc51dd`): S7_7 `#'read_file` map
  lambda → `map_text()`. Harry boot wrapped in catch (he
  actually spawned). Maze `exit_num` fixed to 0 so north
  advances. Church → S7_6 south → well square → down →
  north ×4 → End of maze awards QUEST_M3. `score` `Quests:
  M6a, M3`. Reconnect persist. Guild list 12 (Maze Under
  Well gone). Leather armour cloned at the end.
- Beer to Bum LIVE (`f725c02fc45`): church → S7_6 south ×3
  → S7_9 west Potato-Nosed Ogre. Bartender present. `buy
  beer` (48 gold) → inventory "Bottle of Ogre IV beer".
  East, north ×2 to well square, west ×7 to West Gate.
  Bum spawned (archive never placed him; Strategy A puts
  him at `gate_west`). `give beer to bum` awards QUEST_M2.
  `score` `Quests: M6a, M3, M2`. Gold 200→152. Reconnect
  persist. Guild `quests` 11 (Beer to Bum gone). Thin
  `/lib/drink` (original `drink_ldmud.lpc`); `/lib/pub`
  empty `reset_pub()`; nature-null pub hours; catalog
  get/give. City guards still fail to compile (private
  `gender` / `Pronoun` / `set_keep_hb`) — catch-wrapped.
- Combat LIVE (`3235caa3a99`): church → S7_6 south → well
  square (did **not** go down the well). `kill harry` —
  player hits, Harry hits back (5+3 dmg), Harry dies, 70
  XP. `score` hp 12/20 exp 70. Look: Harry gone. Reconnect
  persist hp + exp. Thin `/lib/living` attack/die/heart_beat
  (original still `living_ldmud.lpc` with HitFunc closures).
  Catalog `kill`/`hit` resolves a short fight. Stray dogs
  are a 10% street wander; S6_7 had none this boot.

This-boot live `libs/sticklib/log/debug.log` (fd, PID 1662870
BOOT_MARKER16 sticklib-combat): living + catalog player
compiled. Catch this walk: expected PEACE_D only.

Guild advance LIVE (`0cf82e040d1` + `fc60c6c304d` +
`38d9b3c591c`, native 40286, 2026-09-10): catalog
`set_level`/`set_title` persist (they were no-ops;
`query_level` always returned 1). Harry respawns on
re-enter of S7_7. Temple yard restores HP and unghosts
(login compile needed a `remove_ghost` prototype).
Organic `fluffos`: 13× `kill harry` with church rest
between fights (70 XP each; start 210 → 1120). Guild
`cost`: "enough experience to advance a level".
`advance level` fanfare; score `Fluffos the Mostly
Harmless (level 2)` exp 1120. Reconnect persist.
`qp_for_level` is still 0 (XP-only).

**Published** (`wasm_status: playable`) after WASM
§10.7 of shop / combat / guild (leftover 632,
2026-09-10).

## 4. What is not ported yet

Elevator, PEACE_D, NATURE_D. Trashcan toss (`foreach :`).
Full LDMud HitFunc / weapon closures (thin living is enough
to kill). Bulletin board extra inherit. City guards. Joe's
LDMud tell_here format tokens still print raw. Catalog
inventory persist is still save fields only.

## WASM §10.7 (2026-09-10, leftover 632)

`scripts/wasm_client.js` against `build-wasm`
(`fluffos 20260830`), organic `fluffos` / `Mud@2026`
(native leftover 629 save: level 2 Mostly Harmless,
exp 1120, gold 152, quests M6a/M3/M2):

- Temple yard look / score.
- South → S7_6 west ×2 Common Shop. `list` / `buy
  torch` (gold 152→70).
- East ×2 south → S7_7. `kill harry`: Harry dies,
  exp 1190, hp 11/20.
- East ×2 Adventurers' Guild. `cost`: "You still
  need 332 experience points for next level."
- North to the yard: "The temple yard's peace
  restores you."
- Quit / WASM reconnect: level 2, exp 1190 persist.
  Gold 200 (catalog bump when purse < 80). Inventory
  empty (catalog save fields only — same as native).

Expected compile noise (already documented, not
player-visible): PEACE_D `filter_objects`, trashcan
`foreach :`, bboard `#'`. Do not redo native harry
farm or WASM shop/combat/guild. Remaining partials:
aoh shop/combat (do not invent rooms), simud (no
`world.obj`), morgengrauen (no `/d/ebene`), acme
(no world).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 11 line(s) in 7 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## Deep test (§10.7, 2026-10-08) -- fixed-width `.lpc` suffix slices

The `.c` -> `.lpc` rename changed the string but not the slice width: `f[<2..] == ".lpc"` compares two characters with four and is never true (`!=` always true), so suffix filters and strips never ran or cut `x.l` (KB 06 §7.238). `scripts/lpc_lpc_suffix_slice.py --apply` fixed 4 comparison(s) and 1 strip(s) (e.g. `bin/usr/_ls.lpc`); the changed files load at HEAD and in the tree (fresh processes) with no regression.

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 0 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 184 个，只在 #if 分支用的声明移进分支 0 个文件；改动 103 个文件，HEAD 与工作树各载入一次无回退（103 objects; HEAD PASS 56, tree PASS 56; regress 0; newly loading 0），这些文件的警告 436 -> 246。

- 2026-10-10（续）：第二轮编译警告整理把 `light.lpc` 里未用的 `object env = (all_environment() || ...)[<1];` 留成了无意义的表达式语句，改为整行删去（`lpc_fix_unused_init.py` 现只在初始化式就是单个调用时保留调用）。 另外 `secure/ftp.lpc`、`guilds/priests/rooms/registration.lpc`、`secure/master/log_file.lpc` 中同样被删的 `#if` 分支变量已恢复。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮加手工收尾；能编译的文件警告清零，剩下的警告都在本来就编不过的 LDMud 遗留文件里（`mkmapping`、`interactive_info`、`set_this_object` 等，属移植缺口）。改动的 146 个对象 HEAD 与工作树各载入一次：HEAD PASS 75，tree PASS 75，regress 0。

- 机械类：60 个 `nosave` 函数改 `protected`（2 个删去），121 处无意义转义（`\'`、`\T` 等，输出不变），176 个未用局部变量，3 个只在 `#if` 分支用的声明移进分支。
- 重复继承：`include/room.h` 本身会 `inherit ROOM_FILE`（有 `ROOM_NO_INHERIT` 开关）。`areas/tristeza/shops/bakery.lpc` 和 priests 的 `armoury`/`artificer`/`quartermasters`/`treasury`/`wine_cellar` 先经头文件继承 room，再继承一个本身就继承 room 的类（food_shop、officer_room、pub），于是 room 的变量声明两次、函数“inherited from both”。在这些文件 include 前加 `#define ROOM_NO_INHERIT`。`guilds/thieves/thief.h` 同理直接继承 `mark/can_throw`、`mark/is_valid_target`，新增 `THIEF_NO_INHERIT` 开关，`skills/_stab.lpc`、`skills/_tth.lpc`（已经继承 `criticals`）打开它。驱动原本就选用子类里的定义，行为不变。
- 真 bug（“Expression has no side effects”下面藏的）：
  - `areas/tristeza/finnclub/sauna.lpc`：`str == tmp1` 应为赋值，“... with X” 的写法从没生效。
  - `lib/armour.lpc`：`rcs[i] == "dwarves"`，dwarf 从没换成复数 dwarves，描述里一直是单数 dwarf。
  - `std/obj/pipe.lpc`：`addiction == 0`、`sweat == 0`，负值从不归零。
  - `bin/pub/_check.lpc`：61–80 一档的 `case` 后面是一个孤立的 `tmp;` 而不是 `break;`，直接落到 default，玩家总看到“死在瓶子里”的那句。
  - `basic/curse.lpc`：删 `identified_by` 最后一个名字时算出新数组却没赋回去。
- 其它：`lib/door.lpc` 空的 `if (l_long) {}` 删去；`basic/room/map.lpc`、`bin/usr/_diff.lpc` 的 `?:` 两边类型统一；三个 attack 文件和 `bin/pub/_disguise.lpc` 注释里的嵌套 `/*`。

- 2026-10-14: `guilds/thieves/skills/tumble.lpc` declared its globals above `inherit "/guilds/thieves/skills/criticals"` inside the `#ifndef TMARK_C` block (`Illegal to inherit after defining global variables`); the inherit now comes first.

## Objects that call an inherited function no parent has (2026-10-19, KB 06 7.259)

`::create();`, `::init();` and `return ::buy_object(who, item);` were written against a parent that has the function; this lib's parents do not, the old driver took the call for a no-op returning 0, and the current driver stops at compile time with `Unable to find the inherited function`, so the object never loads. A call written as a statement is deleted, `return ::f(...)` becomes `return 0;` (`return;` in a void function), which is what the old driver did. 1 calls in 1 files: `::reset()` (1). Only files whose every error was this one were edited; a file that also has another error (usually a parent that is itself missing) is left until the parent is restored. (`scripts/lpc_fix_dangling_super.py`)

## Warning scan residue (2026-10-19)

- The fresh scan listed one warning outside a failing file, `Unused local variable 'index'` at `/secure/simul_efun/file_lines.lpc:12`. That file has no such variable and loads with no warning; the row belongs to its neighbour `secure/simul_efun/tail.lpc`, an LDMud-only sefun (`bytes` type, `b"\n"` literals) that does not compile here and is not in the `catalog/simul_efun` set the driver loads. Nothing to fix; the rest of the `secure/` and `std/` tree is LDMud code whose errors are expected (the lib is a catalog overlay, not a port).

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/basic/curse.lpc`（1 处）。

## `add_action()` registrations of functions nobody defines (2026-10-21, KB 06 §7.349)

An `add_action("fn", "verb")` whose function is defined neither by the object, nor by its headers, nor by its parents, nor by any object derived from it (`scripts/lpc_scan_callout_targets.py`, descendants checked transitively, then `function_exists()` in a running driver, `scripts/lpc_verify_handlers.py`). The driver walks the actor's sentences from the newest one: when that sentence's function does not exist it raises `*Function for verb 'drop' not found.` and tries no other handler of the verb (an older dead sentence is passed over silently). Removed 5 registrations in 2 files (`scripts/lpc_fix_dead_add_action.py`), the verbs are left to their other handlers: `/areas/tristeza/shops/lords_shop.lpc` (`read`), `/areas/tristeza/virtual/jail/cavern1.lpc` (`east`, `north`, `south`, `west`). Most frequent: `read` x1, `east` x1, `north` x1, `south` x1, `west` x1. 

## `log/` subdirectories nobody created: the logging `write_file()` / `log_file()` raises (2026-10-22, KB 06 §7.358)

The code of this lib writes logs into 1 subdirectory of `log/`: `log/lords` (`areas/tristeza/bank/bank_back.lpc`). Neither the archive, a `git clone` nor the site pack has them (no local boot wrote into them, so `gen_keep_dirs.py` never recorded them), and `write_file()` raises `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"` for a missing directory: the function that logs stops on that line and what came after it (the reward, the flag, the next step) never runs. This lib's `log_file()` is `write_file(LOG_DIR + file, text)` and raises the same error for a missing directory (measured). `log/lords` are now in `scripts/wasm_keep_dirs.txt` (`scripts/lpc_keep_log_dirs.py`; the site and the pristine tree create the empty directories from it). Proof (`scripts/lpcc_eval.py`, an eval object under `/adm/daemons` or similar writes `/log/zzdirprobe/...`, fresh processes): the measured table in KB 06 §7.358.

## Remaining constant assignments used as conditions (2026-10-27, KB 06 §7.290 Also)

`thief_mark_new` `else if(type = 8)` became `==` (`lpc_fix_cond_assign.py`; KB 06 §7.290 Also).

## 深度功能测试（2026-10-27，§6.25 LDMud foreach 冒号）

LDMud 的 `foreach (object you : arr)` / `foreach (x : arr)` 在本驱动要写成 `in`。本库 27+ 个文件约 80+ 处冒号改成 `in`（含 `flower_man`）。证明：HEAD `flower_man` 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 LDMud mapping foreach）

接着把 `foreach (k, v : map)` 改成 `in`，并修掉无类型替换时 `in` 与标识符粘在一起（`inansi_codes`）。证明：`ansid` 加载。

## 深度功能测试（2026-10-27，§6.25 LDMud `#'fn` 闭包）

简单 `#'ident` → `(: ident :)`；`sort_array(..., #'>/#'<)` → `1`/`-1`。含 `#'?` / `'symbol` 的 unbound_lambda 行未动。`boss_d` / `_channel` / `druids/mark` 可加载（HEAD 为 Illegal character '#'）。

## 深度功能测试（2026-10-27，§6.25 living `private nosave`）

FluffOS 兼容层 `/lib/living.lpc` 把 `level`/`gender`/`liv_Flags` 等标成 `private nosave`，子物件直接读会 `Illegal to use private variable`。改为普通 `nosave`（与 LDMud living 可见性一致）。

## 深度功能测试（2026-10-27，§6.25 catalog sefun present4/object_info）

Strategy A 的 `/catalog/simul_efun` 缺少 LDMud 的 `present4` / `object_info`。已补上（`OI_ONCE_INTERACTIVE` → `interactive()`）。`buster_bag` 与 `_si` 可加载。

## 深度功能测试（2026-10-27，§6.25 Strategy A set_stat）

`/lib/living.lpc` 补上 `set_stat`/`query_stat`（及空 `set_keep_hb`）。janitor 不再报 Undefined function set_stat。

## 深度功能测试（2026-10-27，§6.25 Strategy A Pronoun）

`/lib/living.lpc` 补上 `Pronoun`/`Possessive`/`Objective`（及 query_*）。janitor 不再报 Undefined function Pronoun。

## 深度功能测试（2026-10-27，§6.25 Strategy A pick_any_obj/weight）

`/lib/living` 补 `local_weight`/`experience`/`add_weight`/`recount_weight`/`wield`/`wear`/`unwear`；`/lib/npc` 补 `pick_any_obj`。janitor 可加载。

## 深度功能测试（2026-10-27，§6.25 Strategy A is_fighting/dead）

`is_fighting` 改为 `varargs`；补 `dead` 与 `heart_beat`。guard / guard_captain / janitor 均可加载。

## 深度功能测试（2026-10-27，§6.25 master_ldmud `#'fn` 残渣）

`call_out`/`set_driver_hook` 等行上剩余的简单 `#'ident` → `(: ident :)`（仍跳过 `({#'` lambda 汤）。

## 深度功能测试（2026-10-27，§6.10 sticklib lpc_warnings --fix）

机械修复：未用局部变量删除、`nosave` 函数改为 `protected`（34 文件）。约 119 处「无副作用表达式」留给专批。

## 深度功能测试（2026-10-27，§6.25 Strategy A drink potion API）

薄 `/lib/drink` 只够酒吧 `set_value`/`set_id`；药水的 `create_drink()` 还要 `set_strength`/`set_soft`/`set_info`/`set_empty_container`/`set_drinker_mess`/`set_liquid`/`full` 等（完整版在 `drink_ldmud.lpc`）。补上这些 setter，继承 `/basic/object/dimensions`，并在 `create()` 里调用 `create_drink()`。证明：HEAD potion_heal 报 Undefined set_info；树 6/6 药水与 finnclub 酒水可加载。

## 深度功能测试（2026-10-27，§6.25 Strategy A NPC spell stubs）

NPC 的 `set_chance`/`set_spell_mess1`/`set_spell_mess2`/`set_spell_dam`/`set_breath_attack` 在 `npc_ldmud`；薄 `/lib/npc` 没有。补上存储与 setter（施法心跳仍薄）。证明：HEAD leo 报 Undefined set_chance；树可加载 leo。

## 深度功能测试（2026-10-27，§6.25 catalog sefun apply/mkmapping）

Strategy A `/catalog/simul_efun` 缺 LDMud `apply` 与双参 `mkmapping`，`equipped_npc` / `dueld` 编不过。补上 `apply`（`evaluate` + `call_other` 数组展开）和配对数组 `mkmapping`（赌场多值宽映射仍不支持）。证明：HEAD 报 Undefined；树均可加载。

## 深度功能测试（2026-10-27，§6.25 catalog sefun file_lines/interactive_info）

Strategy A catalog 缺 `file_lines` / `interactive_info`。从档案 sefun 移植 `file_lines`；`interactive_info` 映射到 FluffOS `query_ip_*`/`query_idle`/`in_edit`/`query_snoop*`。证明：HEAD Undefined；树 `_line` 与 mud_guide 可加载。
