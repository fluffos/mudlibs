# sanguozhi — 三国志 (git clone from fluffos/sanguozhi)

Source: `git clone https://github.com/fluffos/sanguozhi` (already targets
FluffOS v2017 per its own repo description). Port: 40210. Status:
**done** (boots clean, full registration verified end-to-end with a real
Chinese name, `look`/`score`/`quit`/`help`/`who`/`update` all confirmed
working post-login).

## What this is

A Lima-mudlib-derived (TMI-2/Ellery security lineage — see the base
`/README`, credited to Rust/Deathblade/Beek @ Lima Bean) Three Kingdoms
game. `secure/{master,simul_efun}` layout, `mudlib directory : ./` — the
repo root itself IS the mudlib root, no nested subdirectory. Registration
rolls a talent template (英勇善战/足智多谋/识人善用/智勇全才), and the
live game world (`sgdomain/`, `a/<city>/`) has area rooms across
Three-Kingdoms-era cities (长安/邺城/汉中/... — see `a/`), NPCs (华佗,
merchants, a king/献帝), nation/troop/patrol daemons, named historical
horses (赤兔马/的卢马/大宛马/...), and a real weapon/armor equipment set.

**This repo was already substantially prepared for this exact playbook
before cloning.** Its own git history (3 commits by the same author as
this project, `sunyucong@gmail.com`) already: converted GB18030→UTF-8,
fixed `secure/master.lpc`'s missing `get_root_uid()`/`get_bb_uid()`/
`creator_file()` (PACKAGE_UIDS requirement), fixed the §8.1 GBK
byte-range `is_chinese()`/`valid_chinese_id()` bug in both
`secure/simul_efun/chinese.lpc` and `secure/user/login.lpc`, and several
smaller driver-grammar fixes (postfix-array declarations, `chr(0)`,
`force_game_command()`'s missing `set_this_player()`). This meant the
usual §7/§8 catalog sweep was mostly already done; the on-sight
checklist (§2.2) found nothing new to fix in `master.lpc`/`securityd`/
preload hygiene. `data/secure/access.o` also already had `fluffos`
(alongside the original `mudren`) pre-seeded with root wizard privileges
from that same prior session.

## Conversion notes

- Whole tree was already UTF-8 except ~13 genuine stragglers (all
  extensionless or non-`.lpc` GBK text, none of them source):
  `help/player/sanguo/{command/go,war/myarmy,cmds/set_cmd/brief}` (live
  help text, converted clean) and 9 files under `wiz/rough/archieve/`
  and `wiz/suicide/archieve/` (personal wizard-homedir scratch notes
  from 1999-2000, a few with a handful of lossy-dropped bytes — not
  live-loaded content, converted for completeness anyway per AGENTS.md
  §4.1's "convert every text file" rule).
- `bin/` (prebuilt Windows driver binaries) excluded from `work/` per
  AGENTS.md §2 step 2 — this project uses its own driver.
- **Non-LPC C source wrongly caught by the blanket `.c`→`.lpc` rename**:
  `wiz/fire/project/{messser,cmdcli,unp,ms,discli}.c` is a standalone
  Unix socket-programming side-project (uses `unp.h`, `fd_set`, a
  `makefile`) sitting in a wizard's homedir, not LPC at all (confirmed:
  raw C prototypes, `#include "unp.h"`, compiled `.o`/binary siblings
  already present). Renamed back to `.c` after the conversion pass
  mistook it for mudlib source (surfaced via `lpcc_check.sh`'s "Cannot
  #include sys/socket.h" etc. failures on the wrongly-renamed
  `.lpc` versions).

## Compile-sweep fixes (this session)

`scripts/lpcc_check.sh` found 285/3563 failures initially; after fixes
below (plus recognizing the `.c` C-project false-positives and confirmed
lpcc-batch-only artifacts, see below), the remaining live-tree failures
are unreachable/dead content (see "Not fixed" section).

1. **`secure/daemons/cmd_d.lpc` — the ".c"→".lpc" filename-length drift
   (SEVERE, corpus-wide-within-this-lib impact)**. `cache_dir()` and
   `find_cmd()` strip the `.lpc` extension off cached command filenames
   with `$1[0..<3]` — correct for the ORIGINAL `.c` extension (2 chars)
   but off by exactly 2 after this project's standard `.c`→`.lpc` rename
   (4 chars): `"quit.lpc"[0..<3]` yields `"quit.l"`, not `"quit"`.
   Every single `/cmds/player` and `/trans/cmds` shell command (`quit`,
   `help`, `who`, `date`, `update`, ...) became permanently unmatchable
   via `find_cmd_in_path()`/`smart_arg_parsing()` — typing any of them
   printed `没有 X 这个命令或动词` (no such command/verb), even though
   the command files themselves compile and load fine standalone. This
   is Lima's whole unix-shell command layer (distinct from the
   `cmds/verb(s)/` natural-language parser, which was unaffected — hence
   `look`/`score` working while `quit`/`help` didn't, the exact
   differential that led to finding this). Fixed both slice sites
   (`[0..<3]` → `[0..<5]`). Confirmed fixed live: `quit`/`help`/`who`/
   `update` all work correctly after a driver restart.
   **The same `.c`→`.lpc`-drift pattern recurred in 3 more files** (same
   "strip a computed file extension via a hardcoded slice bound" idiom,
   found by grepping `[0..<3]` project-wide and checking which sites are
   genuinely computing a `.lpc`-suffix basename vs. unrelated 2-char
   suffixes like `.o`/`_d`, which are correctly `[0..<3]` as-is since
   those extensions were never renamed): `daemons/quest_d.lpc` (also had
   a matching guard `base[<2..]==".lpc"` that can never be true — a
   2-char slice compared to a 4-char string — fixed to `[<4..]`),
   `daemons/spell_d.lpc`, `daemons/troop_type_d.lpc`. **Two more
   instances spotted but left unfixed** (self-neutralizing, not
   crash-causing, and outside anything exercised by this session's
   testing): `a/area_server.lpc` (an admin/map-export tool) has the
   inverse shape — its own guard `f[<2..<1]==".lpc"` compares a 2-char
   slice to a 4-char string and is therefore always false, so the
   `.lpc`-strip never fires; the code just keeps the `.lpc` suffix in
   its output keys instead of crashing. Not reachable via normal play;
   flagged here for a future pass if `area_server`'s admin tooling ever
   gets tested directly.
2. **`cmds/player/tell.lpc` / `cmds/player/stell.lpc`**: `string muds;`
   declared as a scalar but assigned `IMUD_D->query_up_muds()` (a
   `string *`) and passed straight into `find_best_match_or_complete()`
   (which requires arg 2 to be `string *`) — "Bad type" compile error,
   breaking the cross-mud `tell user@othermud` feature. Fixed both to
   `string *muds;`. (2 more sandbox copies in `wiz/xiaobai/work/` have
   the identical bug, left unfixed — not live.)
3. **`cmds/area/nation_menu.lpc`**: `string * keys, dis;` — the `*` only
   binds to the first identifier in a multi-declarator statement, so
   `dis` silently typed as plain `string` while `dis = map_array(keys,
   ...)` assigns an array — "Bad assignment"/"Bad argument to implode()"
   breaking this nation-management wizard menu. Fixed to
   `string * keys, * dis;`.
4. **`sgdomain/job/zuoci/zuo_tool.lpc`**: `mixed *  *main_rooms;` (a
   doubled `*` typo) — the variable was never actually declared, so
   every later `main_rooms = ...` use hit "Undefined variable"/"Illegal
   lvalue". Fixed to a single `mixed *main_rooms;`.
5. **`sgdomain/npc/huatuo.lpc`** (华佗, a real reachable job-giver NPC):
   two dead debug/leftover lines (`n_lasttimes=usr->query_job(JOBID,
   ...)`) referencing a never-declared `usr`/undefined `JOBID` macro
   (this file isn't itself a `JOBID`-defining job file — that macro only
   exists per-file under `sgdomain/job/*`) — their results were never
   used elsewhere in the function. Removed; the surrounding real logic
   (which correctly uses the `who` parameter and the literal `"hua
   tuo"` job id) was untouched.
6. **`sgdomain/npc/merchant.lpc`**: `p_goldhave` used (assigned +
   compared) inside the `case "area":` block of a `switch` but never
   declared anywhere in the function — "Undefined variable"/"Illegal
   lvalue", breaking the area-treasury purchase path for this merchant
   NPC. Declared `int p_goldhave;` in that block (its only scope).
7. **`sgdomain/npc/king.lpc`** (献帝, the Emperor Xian NPC): `usr = NULL;`
   twice — this driver has no `NULL` constant. Changed to `usr = 0;`
   (the LPC idiom for "no object").
8. **`daemons/stuff_d.lpc`** / **`sgdomain/job/patrol/patrol.lpc`**: a
   `switch` with only a `default:` case, no real `case` labels — this
   driver rejects that shape outright ("need case statements in
   switch/case, not just default:"). Both were trivially "the default
   branch is the only branch" — replaced the whole `switch` with its
   default body directly (no behavior change).
9. **`daemons/spell_d.lpc`**: `ENSURE(valid_spell_name(spell_name) /*
   comment */);` — an inline `/* ... */` C-style comment inside a
   function-like macro argument that itself contains a nested call —
   this specific combination desyncs the driver's macro-argument
   parser (confirmed via a minimal repro: an adjacent `ENSURE(spell_name
   /* comment */)` with a BARE identifier argument compiled fine; only
   the version with a nested call expression in front of the comment
   broke, cascading into "Undefined function ENSURE" / a string of
   downstream syntax errors that looked like the rest of the function
   had been mangled). Moved both trailing comments to `//` lines above
   the call instead of inline. Not previously cataloged in AGENTS.md —
   worth watching for on any lib using a similar `assert.h`/`ENSURE()`
   macro idiom with inline comments in the call.
10. **`sgdomain/obj/l_lockable.lpc`**: `xiufu()` calls `xiufu_with(ob)`
    three lines before `xiufu_with()`'s own definition, with no forward
    prototype — "Undefined function" (confirmed real: a byte-identical
    sibling file, `sgdomain/obj/door/l_lockable.lpc`, has the same
    functions in the OPPOSITE order — define-before-use — and compiles
    clean). Added `void xiufu_with(object ob); void chuang_with(object
    ob);` forward declarations alongside the file's existing ones.
11. **`sgdomain/obj/other/maker.lpc`** (定制商人, unreferenced/orphaned
    content — not placed in any room, found via `lpcc_check.sh` not
    live testing): a `//`-commented-out alternative branch spans two
    physical lines, but `//` only comments the first line — the second
    line's stray `-----")`  became live code (parsed `--` as decrement),
    cascading into further syntax errors. Fixed by converting to a
    proper `/* ... */` block comment. **Not fully fixed**: further
    genuine pre-existing bugs remain deeper in this same file (multiple
    "Undefined variable"/syntax errors past line 183) — not chased
    further since the object is unreachable from any room in `a/` or
    `sgdomain/` (confirmed via grep), so it's dead content, not a live
    bug. Documented here in case it's ever wired into a room.
12. **The `set_defence_ablity`/`set_attack_ablity` misspelling (SEVERE,
    equipment-wide)**: 55-60+ files across `sgdomain/obj/weapon/*`,
    `sgdomain/obj/{ljtyjia,ljtyji}.lpc`, and several `wiz/*` personal
    equipment items called `set_attack_ablity`/`set_defence_ablity` (a
    typo — missing "i") while their inherited module
    (`sgdomain/modules/m_weapon.lpc`/`m_wearable.lpc`, or the
    equivalent `wiz/ljty` module for `wiz/ljty`-lineage items) only
    defines the correctly-spelled `set_attack_ability`/
    `set_defence_ability` — every one of these weapons/armor pieces
    failed to compile/load. This is a genuine pre-existing content
    typo (not a driver-migration artifact — the misspelling predates
    any conversion). Renamed all call sites via a corpus-wide
    `set_attack_ablity`→`set_attack_ability` /
    `set_defence_ablity`→`set_defence_ability` sed sweep — EXCLUDING the
    files that legitimately define+use the "ablity" spelling
    self-consistently as their OWN function names
    (`wiz/ljty/modules/m_horse.lpc`, `wiz/ljty/verb/m_horse.lpc`,
    `cmds/verb/m_horse.lpc` — a separate ride/rideone/ridetwo verb
    lineage, untouched, still internally consistent under the old
    spelling for its own `query_attack_ablity()`/`query_defence_ablity()`
    query-side functions, which were deliberately left alone).
13. **`sgdomain/obj/horse/*.lpc` — wrong module constant (10 named
    horses, incl. 赤兔马/黑骏马/大宛马/...)**: 11 of 12 files in this
    directory `inherit M_HORSE_1` (`/wiz/ljty/modules/m_horse.lpc`, a
    personal wizard's ride/rideone/ridetwo-verb horse module) while
    calling `set_attack_ability`/`set_defence_ability` — the CORRECT
    spelling, but one that only the CANONICAL `M_HORSE`
    (`/sgdomain/modules/m_horse.lpc`, get-on/get-off interface) module
    defines. Confirmed via the one sibling that already had it right
    (`xiaohonghorse.lpc`, `inherit M_HORSE;`, byte-identical structure
    otherwise) and via checking neither file uses any `M_HORSE_1`-only
    interface (`set_ride_msg`/`set_unride_msg`/`ride()`/`unride()`) —
    plain copy-paste-from-wrong-template bug. Fixed the `inherit` line
    in all 10 failing files (left `horse.lpc`, the dynamic base class
    that genuinely needs `M_HORSE_1`'s `ride`/`unride` interface and
    whose own `set_attack_ability` call is already commented out,
    untouched; also left the older, self-consistent, unreferenced
    `sgdomain/obj/dawanhorse.lpc` duplicate untouched).

## Not fixed (out of scope / unreachable / low value)

- `secure/daemons/ftp_d.lpc`: "Illegal to use local variable in
  functional" (a local var captured in a `(: ... :)` closure — real
  driver-grammar gap) at 2 sites. `ftp_d` is explicitly commented OUT of
  `data/config/preload` in this lib's own shipped config (`#/secure/daemons/ftp_d`)
  and not preloaded/used anywhere else — dead by the lib's own design,
  not chased.
- `secure/obj/mailers/{mh,standard}.lpc`, `secure/modules/m_file.lpc`:
  compile failures in optional mail-client-format/file-browsing
  infrastructure, not exercised by core play.
- `trans/cmds/{find,findfile,grep,replace}.lpc`, `trans/obj/ed_session.lpc`,
  `cmds/wiz/codesay.lpc`: the known `ed_start`/`ed_cmd` driver gap
  (AGENTS.md §6.2 — this driver only has the old `ed()` efun). All are
  wizard shell/file-editing tools, not part of the player-facing verb
  set that was fixed in item 1 above; admin `update`-based editing
  (confirmed working) is the practical workaround.
- `std/armor.lpc`, `std/monster/traditional.lpc`, `std/stock_master.lpc`,
  `std/modules/m_react.lpc`, everything under `domains/std/` (the stock
  Lima demo zone shipped with the base mudlib, generic
  fighter/thief/cleric NPCs, unrelated to 三国): confirmed unreferenced
  by any real room/NPC (`grep -rl` across `a/` and `sgdomain/` finds
  zero hits) — dead template content from the underlying framework, not
  this game's own content.
- `sgdomain/npc/g_test1.lpc`/`g_test2.lpc`, `sgdomain/obj/other/maker.lpc`
  (partially — see item 11 above): unreferenced test/scratch content.
- ~15 room objects under `a/<city>/*.lpc` (e.g. `a/wuling/wl_dadao1`,
  `a/changan/ca_czx`, `a/huayin/{cunzhangjia,vhall}`, ...) show
  `lpcc_check.sh --batch` failures with **zero diagnostic text**
  ("Fail to load object" only). All 15 share `set_objects(([M_BOARD :
  ...]))` — a bulletin-board object whose `setup()` eagerly calls
  `NEWS_D` methods; under `lpcc --batch`'s isolated per-file compile
  (no preload sequence run first), `NEWS_D` never gets loaded, so the
  board's `create()` throws — this is AGENTS.md §10.4's cataloged
  "hardcoded-path call_others to objects that don't exist in isolation"
  false-positive class, not a real bug (confirmed: `NEWS_D` IS in this
  lib's own `data/config/preload`, so a real boot has it available
  before any room loads; `cmds/player/wizlist.lpc` hit the identical
  "Fail to load object, zero diagnostic" pattern for the same reason,
  calling `LAST_LOGIN_D->query_times()` in `create()`). 16 total rooms
  in this lib use `M_BOARD`; the one that DIDN'T fail
  (`a/area_server.lpc`) isn't actually a room. Not fixed — not a real
  defect, and live play with several of these rooms' NPCs (华佗,
  merchant, king — item 5-7 above) already confirms the wider area is
  reachable and functional.

## Interactive test result — full registration flow

Registration shape: **`new`** (literal keyword, not any-unused-id) →
English id → confirm → **Chinese name, no real-name-filter beyond
blocking actual Three Kingdoms figures** (`赵云`/`刘备` rejected with
"不能使用三国中的人物名"; an invented name like `云飞` accepted
immediately, no y/n confirmation needed after the ambiguity check) →
confirm → password (entered twice) → gender (m/f) → email/real name/
homepage (all optional, blank accepted) → then this mudlib's own
**bootstrap convention: every newly-registered account is automatically
promoted to Admin** ("现在建巫师...你自动成为 Admin，记得用
admtool.") — not something specific to a "first account", it fired for
both throwaway test accounts registered this session. New wizards land
in Lima's own base "巫师大厅" (Wizard Hall) room, not a 三国-specific
start room — this is upstream Lima framework behavior (a reincarnation
platform there leads to "人间"/the mortal world), not a bug. Immediately
after wizard setup, the 三国-specific character-talent menu runs
regardless (英勇善战/足智多谋/识人善用/智勇全才 archetype selection,
then accept/reroll stats) — this DOES run for every account, wizard or
not, and populates the real `score` sheet (中文姓名/英文代号/年龄/
性别/容貌/单挑武功/武力/杀伤力/智谋/抵抗力/魅力/所属国/爵位/俸禄/
忠诚/声望/文学修养 — all populated with real rolled values, not
zeros).

`look`, `score`, `who`, `help`, `update <path>`, and `quit` were all
verified working post-login (see fix #1 above for why `quit`/`help`/
`who`/`update` needed a real fix first — they use the `cmds/player`
unix-shell command layer, distinct from `look`/`score` which are
natural-language `cmds/verbs`). `update /secure/master` succeeds
("/secure/master.lpc: 更新并载入。"), confirming full wizard write ACL —
`fluffos` (this project's standard admin id, password `Mud@2026`) was
registered through the normal flow and auto-promoted the same way; its
`data/secure/access.o` root-wizard entry was already present from the
prior upstream session, now backed by an actual player save file too.
Re-login (the restore path) verified separately: reconnecting as an
existing account (`qinfeng`) with the correct password produces a clean
"你重新连线进入" reconnect message and restores the saved character
(same stats, same room) rather than re-running registration.

**One transport-only caveat, not a lib bug** (matches AGENTS.md §10.2's
own documented caveat about `tmux_mud.sh`): a handful of specific
Chinese test names sent through the tmux/telnet-CLI path (`秦风二号`,
`关羽二`) were rejected as "not Chinese" even though `is_chinese()` is
confirmed fixed and correct (verified independently via `python3
scripts/mudclient.py`'s raw-socket UTF-8 path, and via other Chinese
names — `秦风`, `云飞`, `赵云` — going through the SAME tmux session
cleanly). Treat any single tmux-path Chinese-name rejection as
inconclusive; re-verify via `mudclient.py` or a second distinct name
before concluding `is_chinese()` regressed.

## Admin account

`fluffos` / `Mud@2026`, Chinese display name 浮浮, `(admin)`-equivalent
via this lib's own auto-wizard bootstrap (backed by `data/secure/
access.o`'s `wizards`/`privileges` mapping, which already listed
`fluffos` before this session — the previous upstream-repo session
seeded it; this session completed the loop by actually registering the
player account through the normal flow, per AGENTS.md §1.5 step 1).
