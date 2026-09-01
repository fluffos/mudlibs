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
   **Upstream disposition (2026-08-31, fluffos-org-PR-queue audit)**: no
   genuine upstream-worthy fix — this entire item (cmd_d/quest_d/
   spell_d/troop_type_d's `[0..<3]`↔`[<2..]` slice bounds, plus the
   unfixed `area_server.lpc` instance) is an artifact of THIS
   collection's own blanket `.c`→`.lpc` rename; upstream's original
   files still end in the 2-char `.c` extension, so the original
   `[0..<3]`/`[<2..]` slice bounds are already correct there. Not
   ported.
**Upstream disposition (2026-08-31)**: items 2–10 below (compile-blocking
type/scope/grammar bugs) and the `cmds/player/help.lpc` trailing-newline
fix further down were filed upstream as
[fluffos/sanguozhi#1](https://github.com/fluffos/sanguozhi/pull/1),
confirmed present byte-for-byte in a fresh clone and not already fixed
independently upstream.

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
    **Upstream disposition (2026-08-31)**: no genuine upstream-worthy
    fix — the fix applied here is itself incomplete (further genuine
    pre-existing bugs remain deeper in the file, past line 183), and
    the object is confirmed unreachable/dead content. Not ported.
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

**Upstream disposition (2026-08-31)**: items 12 and 13 above (both
equipment bugs) were filed upstream together as
[fluffos/sanguozhi#2](https://github.com/fluffos/sanguozhi/pull/2).
The upstream audit turned up 2 files this session's local sweep missed
(`wiz/ljty/obj/ljtyjia.c` and `wiz/ljty/obj/ljtyji.c` — inherit
`M_WEARABLE`/`M_WEAPON`, not `M_HORSE_1`, so they have the genuine
typo bug too, not the self-consistent `M_HORSE_1` spelling; not
re-checked against this collection's own converted `.lpc` tree, since
neither is loaded by any live room/NPC here either way) and correctly
excluded `sgdomain/obj/dawanhorse.lpc`'s sibling
`wiz/ljty/obj/dawanhorse.lpc` (also self-consistent under `M_HORSE_1`).

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

## 深度功能测试（round two, 2026-08-27）

Full continuous playthrough per AGENTS.md §10.7: registered two fresh
non-wizard Chinese-named test characters (`qintcf`/云飞策,
`qinver`/云飞验— both deleted before commit, see below), plus a
throwaway account (`qintcer`/云飞测) specifically to exercise the
first-ever-admin bootstrap path (also deleted after use). Covered
newbie help (`help newbie`/`help starts`), movement through 巫师大厅
→ 草庐 → 华阴村 (`小村中心`/`厨房`/`帐房`/`前庭`/`前院`), the full
砍柴 (chopwoods) job cycle (`ask chu niang about job` → `chop woods
with kanchai dao` ×20+ → `ask chu niang about pay` → the 智慧测试
quiz), `score`/`i` at every state change, `admtool`, `quit` +
`debug.log` grep (empty/clean both times — no error ever logged the
entire session) + reconnect after a real wall-clock gap (state
persisted correctly: same stats, same room). `fight`'s own help text
states it can never kill (`没有 kill`, only NPC-replica duels) and
requires having already `settle`d into a role — a multi-step prereq
not reached this pass; documented here as unverified-live rather than
silently skipped. Craftsman/shop commerce (`ask <匠人> about
list/order/good`, see `help order`) is dialogue-driven
(`add_question()`/`special_answer()`, same mechanism as the already-
live-verified 厨娘/chuniang job-pay dialogue), architecturally
distinct from the `add_action(fun,"",1)`+`force_me()` shape §7.143
warns about — that shape doesn't exist anywhere in this codebase
(`force_me()` only appears in `trans/cmds/` wizard-shell tools, an
unrelated "force another session to run a command" feature), so the
NPC-shop check required by this pass is satisfied by architecture
review plus the live-verified chuniang dialogue exchange.

### SEVERE — the "auto-Admin the first wizard" bootstrap can never
actually promote anyone, so it fires on literally EVERY new
registration forever, and `adminp()`/`admtool`'s `[大神]`-tier
commands were unusable by anyone (including the seeded `fluffos`
account) until fixed this session

`secure/user/sw_body.lpc`'s `new_user_ready()` (run once per account,
right after registration finishes) has:
```lpc
/* auto-Admin the first wizard if there are no Admins */
{
    string * members = SECURE_D->query_domain_members("Admin");
    if ( !sizeof(members) )
    {
        ...
        unguarded(1, (: SECURE_D->add_domain_member("Admin",
                        $(query_userid()), 1) :));
    }
}
```
`add_domain_member()` (`secure/daemons/secure_d.lpc`) requires the
domain to already exist (`if (!domains[domain]) return ERR_NODOMAIN;`)
— but **nothing anywhere in this entire mudlib ever calls
`SECURE_D->create_domain("Admin")` (or any case of it)**, confirmed via
a whole-tree grep. So this `add_domain_member()` call fails silently
every single time (its error return is never checked), `domains["Admin"]`
never gets created, `query_domain_members("Admin")` stays permanently
empty, and the `!sizeof(members)` "am I the first admin?" check is
therefore true on literally every account creation — not just the
first. Confirmed live: registering `qintcf` right after this session's
fix, once `qintcer` (registered under the OLD code) had already
"become" the phantom admin, correctly did NOT re-trigger the bootstrap
message (branch `2`, non-admin `set_privilege()`), whereas `qintcer`
saw the misleading "你自动成为 Admin，记得用 admtool" message but
`adminp("qintcer")` was actually **false** — confirmed by testing
`fluffos` (the seeded standard admin account, already `wizardp()==1`
via a hand-seeded `data/secure/access.o` from a prior session) live via
`admtool`'s `d` (region-management) menu: `c admin` (create a domain,
a `[大神]`-only op) failed with `Error: 权力不足` (insufficient
privilege) BEFORE the fix — `fluffos` was a wizard but never a real
Admin, despite the game claiming otherwise at registration. `adminp()`
(`secure/simul_efun/userfuncs.lpc`) is used to gate `admtool`'s
`[大神]` items, `trans/obj/admtool/{user,money}.lpc`, `votetool.lpc`,
channel/news moderation, `wizlist`, `finger_d`/`ftp_d`, and more — all
silently root-privilege-less for the entire history of this
installation except via the one hardcoded `m == "mudren"` test bypass
already in `adminp()`.

**Root cause is a domain-name mismatch, not (only) a missing
`create_domain()` call**: every consumer in this bootstrap path
(`sw_body.lpc`, `userfuncs.lpc`) uses `"Admin"` (capital A), but
`SECURE_D->create_domain()` (the only sanctioned way to create one)
`lower_case()`s the name **before** storing it (and `admtool`'s own
`/trans/obj/admtool/domain.lpc` wrapper independently already
lower-cases user input before calling `SECURE_D->create_domain()`,
confirming lowercase is this codebase's established convention) — so
even adding a `create_domain("Admin")` call up front would create
`domains["admin"]`, still not matching the literal `"Admin"` key
`add_domain_member()`/`query_domain_members()` look up (neither of
which normalizes case on their own). **Fix**: changed both
`secure/user/sw_body.lpc` (the bootstrap block — added a
`create_domain("admin")` call before `add_domain_member()`, since
nothing else ever creates it) and `secure/simul_efun/userfuncs.lpc`'s
`adminp()` to use lowercase `"admin"` consistently, matching
`create_domain()`/`admtool`'s own convention. `create_domain()` on an
already-existing domain returns a harmless "already exists" error
string that's correctly ignored (matching how `add_domain_member()`'s
own return was already being ignored).

**Verified live, end to end, after the fix**: registered `qintcer` →
became the real first Admin (`data/secure/access.o` afterward:
`domains (["admin":(["qintcer":2,])])`) → logged in as `qintcer`,
used `admtool`'s `d` menu's `a fluffos admin` to add the seeded
`fluffos` account as an `admin` member too → reconnected as `fluffos`
→ `admtool`'s `d` → `c ztest` (create a real `[大神]`-gated domain)
**succeeded** (`区域建成`), `l` listed it, `d ztest` deleted it cleanly
— proving `fluffos` now has genuine root/Admin privilege for the first
time in this installation's history. Registered a THIRD fresh account
(`qintcf`) after the fix and confirmed it correctly did **not**
re-trigger the bootstrap (since `domains["admin"]` was non-empty by
then) — restoring the intended "only the very first ever admin" 
semantics instead of firing on every single registration. Cleaned up
afterward: removed `qintcer` from the `admin` domain via `admtool`
(`r qintcer admin`, run as the now-legitimate `fluffos` admin) before
deleting its player-save files, leaving `fluffos` as the sole `admin`
domain member (`domains (["admin":(["fluffos":1,])])` in the final
`data/secure/access.o`).

Files: `secure/user/sw_body.lpc` (bootstrap block), `secure/simul_efun/
userfuncs.lpc` (`adminp()`). New AGENTS.md bug-class entry needed (not
a prior-numbered pattern) — see the corpus doc.

**Upstream disposition (2026-08-31)**: filed upstream as
[fluffos/sanguozhi#3](https://github.com/fluffos/sanguozhi/pull/3),
confirmed byte-for-byte present in a fresh clone (including the same
`domains["Admin"]`-is-permanently-empty root cause) and not already
fixed independently upstream.

### §7.121-class (int declared, float-literal arithmetic, no
`to_int()`) — 19 confirmed instances across the entire `sgdomain/jimou/`
national-warfare stratagem subsystem, plus 2 more in the 献帝/Emperor
Xian NPC's reputation-penalty code

Systemic, not a one-off: every file in `sgdomain/jimou/` that computes
a stratagem's success/damage roll multiplies an `int`-declared local by
a bare float literal (`1.2`, `1.5`, `1.8`, `2.5`, `0.3`, `0.4`, `0.75`,
...) with no `to_int()`/`(int)`-that-actually-works, then feeds the
result straight into `random()` (an `int`-only efun) or into
`WARAI_D->kill_troop()`/`chinese_number()`/`apply_condition()`. Same
underlying driver gap as every other §7.121 instance already cataloged
project-wide (a declared `int` type does not coerce a runtime float on
this driver) — confirmed the worst-case downstream sink here is
`random()`, whose C implementation (`f_random()` in
`efuns_main.cc`) reads `sp->u.number` directly with **no type check at
all**, so a float-tainted argument is read as whatever bit pattern its
`double` happens to have reinterpreted as an integer — undefined/
garbage results, not a clean type error, and with no runtime symptom
to grep for. `sgdomain/jimou/shidu.lpc`'s "施毒" (poison) stratagem is
the worst offender: its float-taint (`e_skill *1.2`) is **unconditional
on every single use**, not gated behind any "if" a real playthrough
might rarely miss.

Fixed by wrapping every such expression in `to_int()` at the exact
point its result is assigned to the `int`-declared sink (preserving
the real float arithmetic through intermediate steps, only truncating
where the LPC type system actually requires it — same pattern as every
other confirmed §7.121 fix project-wide):
- `kill = kill*2 - kill1*1.2;` → `kill = to_int(kill*2 - kill1*1.2);`
  (`jbsj.lpc`, `jbhj.lpc`, `luoshi.lpc`, `neihong.lpc`, `huangbao.lpc`,
  `fakeorder.lpc`, `shoushi.lpc` [`*1.8`], `jiedu.lpc` [`*1.8`],
  `shidu.lpc` [different expression, same shape]) — 9 files, the value
  that's about to hit `random()`.
- `e_skill = e_skill + 1.5*CHAR_D->get_skill(who,"chenzhuo");` →
  wrapped in `to_int()` (`jbsj.lpc`, `jbhj.lpc`, `luoshi.lpc`,
  `neihong.lpc` [2 sites — also had a bare `*1.5` a few lines above],
  `huangbao.lpc`, `shidu.lpc`) — 7 sites.
- `damage = <rate-or-literal-involving float expr>;` → wrapped in
  `to_int()` (`jbsj.lpc` ×2, `jbhj.lpc`, `luoshi.lpc`, `neihong.lpc`
  ×3, `huangbao.lpc`, `zhanbu.lpc`, `shidu.lpc`) — 9 sites.
- `hunluan.lpc` ("混乱"/confusion stratagem) had a distinct shape: two
  LOCAL multiplier constants (`x=1.8; z=1.5;`) were declared `int`
  right alongside their float literal initializers — changed their
  declared type to `float` (they're pure intermediate weights, never
  themselves fed to an int-only sink) instead of `to_int()`-truncating
  them at assignment, which would have flattened the intended 1.8 vs
  1.5 asymmetric weighting down to 1:1 and silently changed the
  stratagem's balance; `kill = kill*x - kill1*y;` (the actual sink)
  got the usual `to_int()` wrap.
- `sgdomain/npc/king.lpc` **and** its live sibling
  `sgdomain/event/ev_king/king.lpc` (献帝/Emperor Xian — the
  `sgdomain/npc/` copy turned out to be dead/unreferenced by any real
  room, `grep -rl` finds zero hits; `sgdomain/event/ev_king/king.lpc`
  IS referenced by `a/changan/ca_czx.lpc` and
  `sgdomain/area/emp/dadi.lpc`, so both were fixed anyway since they're
  byte-identical on this bug): `repd= 0.2*t_money;` (a reputation
  penalty for rudely declining an imperial summons) — `repd`/`rep` are
  both `int`, and `rep -= repd` permanently corrupts the persisted
  `CHAR_D->set_char(n_id,"reputation",rep)` value into a float, same
  shape as the AGENTS.md §7.121 catalog's own headline example.
  Fixed: `repd = to_int(0.2*t_money);`.

Checked the remaining 12 files in `sgdomain/jimou/` (`chenzhuo`,
`dantiao`, `fenfa`, `fengbian`, `guwu`, `jiaoma`, `luanshe`, `maifu`,
`qibing`, `scout`, `sugong`, `tianbian`) — none use `float` or any
decimal literal at all, confirmed clean. Not live-reproduced end-to-end
(reaching real national-warfare combat requires troops/nation office,
out of reach for a level-1 newbie in one session) — fixed on strong,
already-corpus-confirmed pattern match per AGENTS.md §7.121's own
"how to apply generally" guidance, verified only via code review +
clean `lpcc`/formatter passes, not a live repro. Flagged honestly as
such rather than claimed as live-verified.

**Upstream disposition (2026-08-31)**: filed upstream as
[fluffos/sanguozhi#4](https://github.com/fluffos/sanguozhi/pull/4),
confirmed byte-for-byte present in a fresh clone (all `kill`/`e_skill`/
`damage` sink sites, `hunluan.lpc`'s `x`/`z` int-declared-with-float-
initializer shape, and both `king.lpc` copies' `repd` reputation
penalty), and not already fixed independently upstream.

### §7.118-class (`.c`→`.lpc` filename-slice-arithmetic leftovers) — 2
new instances beyond the corpus already fixed at onboarding time

- `trans/cmds/dir.lpc`'s wizard `ls`/`dir` colorizer:
  `if (file[<2..] == ".lpc")` — a 2-character slice can never equal
  the 4-character string `".lpc"`, so `.lpc` files never get the
  "code" color in a directory listing (`.h`/`.o`, both genuinely
  2-char extensions, work correctly right next to it — the exact
  differential that flags this as the familiar leftover-from-`.c`
  pattern, not a design choice). Cosmetic only, wizard-only tool
  (confirmed non-wizard players get "没有 dir/ls 这个命令" — this
  lives in `trans/cmds/`, outside the normal player verb set). Fixed:
  `[<2..]` → `[<4..]`.
- `daemons/doc_d.lpc`'s incremental autodoc scanner:
  `item[0][<2..<1] == ".lpc"` — same shape (a 2-char slice compared to
  a 4-char string, always false), meaning the "which changed `.lpc`
  files need their autodoc regenerated" scan never actually found any
  file to update. Wizard-tool-only (autodoc generation), not
  player-facing. Fixed: `[<2..<1]` → `[<4..<1]`.

Also found and fixed one **unrelated** off-by-slice-bound bug while
grepping for the above, same broad "wrong slice bounds" shape but not
a `.c`→`.lpc` migration artifact: `cmds/player/help.lpc` (the actual
live `help` command every player uses) had
`if(ret[<3..<1]!="\n") ret+="\n";` — comparing the LAST 3 CHARACTERS of
the help text to the 1-character string `"\n"`, which can never be
equal, so the condition is a tautology and `help` **always** appended
an extra trailing blank line, even to text that already ended in one.
Every other trailing-newline check in this codebase
(`secure/master.lpc`, `secure/daemons/lpscript_d.lpc`,
`daemons/imud/channel.lpc`, `std/modules/m_react.lpc`) consistently
uses the correct single-index idiom `str[<1] == '\n'` — confirming this
was a typo, not an intentional different check. Fixed to match:
`if(ret[<1]!='\n') ret+="\n";`.

**Upstream disposition (2026-08-31)**: the `dir.lpc`/`doc_d.lpc` pair
above is this collection's own `.c`→`.lpc` rename artifact — not
upstream-worthy (upstream's original 2-char `.c` extension makes the
original `[<2..]`/`[<2..<1]` slices correct as-is there). The
`cmds/player/help.lpc` fix (a genuine pre-existing typo, independent
of any extension rename) was filed upstream as part of
[fluffos/sanguozhi#1](https://github.com/fluffos/sanguozhi/pull/1)
(see the note at the top of the "Compile-sweep fixes" section above).

### Confirmed clean / not applicable (systematic grep sweep of every
standing cross-cutting pattern requested for this pass)

- **§7.112** (unconditional `init()` call_out chain, no re-entry
  guard): no `init()`/`call_out()` combination found on any NPC in
  `sgdomain/npc/` or elsewhere; this lib's combat/death architecture is
  Lima-native, not the ES2 `heart_beat()`-chain shape this pattern was
  cataloged from.
- **§8.3a** (`private nomask command_hook` demoted once inherited):
  this is a Lima/TMI-2 mudlib, not ES2 — no `command_hook`-shaped
  central dispatch function exists; grepped every `private nomask`
  declaration or a mixin file registering itself via
  `add_action`/`call_out` and found none matching the shape. Also
  independently confirmed live: `look`/`score`/`i`/`ask`/`chop`/
  `admtool`/`quit`/`help`/`who`/`update` all dispatch correctly.
- **§7.122** (class/marker autoload duplication): the
  `compute_autoload_array()`/`destroy_autoload_obj()`/
  `load_autoload_obj()` mechanism doesn't exist anywhere in this
  codebase.
- **§7.123** (bare file-scope `IDENT = (...);` killing a compile): grep
  found several superficially-matching zero-indent lines, but every one
  is inside a function body (just unindented legacy style), not
  genuine file scope — confirmed via context read on each hit
  (`sgdomain/menu/votetool.lpc`, `daemons/relation_d.lpc`,
  `daemons/fate_d.lpc`).
- **§7.124** (percentage field initialized as a 0.0-1.0 fraction): no
  matching threshold/rate-gate field found; the two `repd=0.2*t_money`
  hits under this search turned out to be §7.121 instances instead
  (fixed above).
- **§7.126** (stale `.c` extension in `__DIR__`-based save data): no
  live `.lpc` file references a `__DIR__"foo.c"`-style path; the only
  hits are in non-compiled sibling files (`.listen`, a numbered `.1`
  backup).
- **§7.129** (`tell_room()` wrapper passing omitted `exclude` to
  `message()` as bare `0`): `tell_room()` in this codebase is a
  deliberate hard `error()` stub (`secure/simul_efun/overrides.lpc`,
  "Use tell_environment() or tell_from_inside() instead") — never
  calls `message()` at all. The real message-delivery chain
  (`tell()`/`tell_environment()`/`tell_from_inside()` in
  `secure/simul_efun/tell.lpc`) routes through `receive_*_msg()`
  LPC-level body methods, not a direct `message()` efun call; the only
  direct `message()` efun call sites in the whole tree are in two
  personal wizard-homedir files (`wiz/emperor/ask.lpc`,
  `wiz/yue/obj/jia.lpc`), not core infrastructure, and both pass
  explicit arguments.
- **§7.130** (`query_idle()` called unconditionally post-non-interactive
  in `heart_beat()`): the only `query_idle()` call sites are cosmetic
  (a `score`/`who` idle-time display string), not part of any
  heart_beat-driven net-dead detection; this lib's net-dead handling is
  the §7.133-style direct `net_dead()` apply instead (see next item).
- **§7.131** (`find_living()`/`find_player()` needing
  `set_living_name()`): both are deliberately disabled in this codebase
  (`secure/simul_efun/overrides.lpc`: `error("find_player() is
  obsolete. Use find_body() instead")`; `std/living.lpc`'s own comment:
  "find_living() doesn't exist") — a fully-wired-up, already-tested-
  working replacement (`find_user()`/`find_body()`, confirmed live
  throughout this session), not an archive that assumes the classic
  apply still works.
- **§7.132** (`map()`-over-mapping bound to the key instead of value):
  every `map()` call found in `sgdomain/`/`daemons/`/`std/`/`secure/`
  operates on a genuine array (`string*`), not a mapping — checked each
  candidate's declared type individually.
- **§7.133** (disconnect-notification apply never defined): `net_dead()`
  IS defined, in `secure/user.lpc` (the actual `USER_OB` connection
  object the driver's apply targets) — confirmed indirectly via this
  session's own clean quit/reconnect cycle (a `私 nomask` qualifier
  wouldn't block a driver-level apply anyway, only LPC-level external
  dispatch like `add_action`).
- **§7.134** (extra-desc accumulator array with no `({})` default):
  every room navigated this session (village center, kitchen, front
  hall/courtyard, 草庐, etc.) rendered its full description with no
  truncation or error.
- **§7.135/§7.30** (accessor missing a `mapp()`/lazy-init guard): spot-
  checked the central `CHAR_D->get_char()`/`sgdomain/modules/
  m_skills.lpc` skill-map accessors — `sg_skills`/`skill_map` are both
  initialized inline (`= ([]);`) at declaration, and `set_sg_skill()`
  already has a proper `!mapp(sg_skills)` guard elsewhere in the same
  file; no bare-uninitialized-mapping-return path found.
- **§7.136** (command souls stripped, race content missing):
  `look`/`get`/`i`/`say`(disabled by design, see below)/`ask`/`chop`
  all worked correctly throughout an extended live session — command
  dispatch is not broken project-wide.
- **§7.139** (interactive-catch-tell config off, breaking `%^TAG%^`
  colour rendering): confirmed working correctly — every session
  transcript this pass shows real ANSI escape sequences
  (`\x1b[1;36m` etc.), not literal `%^...%^` text.
- **§7.141** (MudOS-era `replace_program()` fold): `replace_program()`
  only appears in one personal wizard-homedir file
  (`wiz/lei/room/startroom.lpc`) and the help doc — never in live game
  content.
- **§7.142** (virtual-object engine manufacturing a disconnected
  duplicate room for a broken exit typo): this lib DOES use a
  `compile_object()`-based virtual-object engine (`secure/master.lpc`,
  walking up the directory tree calling `virtual_create()`), actively
  used by several real systems (`sgdomain/base/base_server.lpc`'s
  coordinate-grid city areas, `sgdomain/home/home_server.lpc`,
  `a/area_server.lpc`, `sgdomain/modules/{char_server,troop}.lpc`).
  Exhaustively auditing every hardcoded exit path against this engine's
  expected `area/file/room` argument shape for a missing-segment typo
  is beyond this pass's time budget — flagged honestly as **not
  exhaustively checked**, unlike the fully-covered patterns above,
  rather than claimed clean.
- **§7.144** (one-shot `set_name()` guard defeating per-instance
  rename): `std/living.lpc`'s `set_name()` has no such guard — it
  correctly removes the old id before adding the new one, re-callable
  at any time.
- **§7.145** (shop verb shadowed by a direct `add_action` override):
  this lib's commerce system is entirely dialogue-driven (`ask X about
  Y`), not `add_action`-based — the pattern doesn't apply
  architecturally (see the NPC-shop paragraph above).
- **§7.146** (broken `/`-instead-of-`/*` comment): no confirmed
  instance found in live `.lpc` content; the original conversion
  session's `lpcc_check.sh` sweep (285→documented-remainder failures)
  would have caught any compile-fatal case, and this pass's own grep
  turned up only ASCII-art string literals as false positives.

## Cleanup

All three throwaway test characters (`qintcer`, `qintcf`, `qinver`) and
their save files (`data/players/q/`, `data/pshells/q/`, `data/links/q/`,
`data/wshells/`) were removed before commit. `qintcer` was first
cleanly removed from the `admin` domain via `admtool` (run as the
now-legitimate `fluffos` admin) so the final `data/secure/access.o`
state has `fluffos` as the sole real Admin, matching this project's
standing seeded-admin convention.

## 深度功能测试（round three, 2026-09-01）

A third pass, deliberately covering exactly what the round-two pass
above documented as unreached: `settle`+`fight` combat, real board
`post`/read (checked specifically against the AGENTS.md §7.86
`replace_program()` board-crash shape), currency persistence across a
real `quit`+reconnect, adversarial/malformed input, and the §7.19-class
NPC `init()`/`enable_commands()` reentrancy shape. Two fresh throwaway
non-wizard test characters (`qtstv`/云斗五, `qtstw`/云斗六, both deleted
via `CHAR_D->remove_char()` plus their `data/{players,pshells,links}/q/`
save files before commit) plus the standing `fluffos` admin account.

**`settle` → `fight`**: `sgdomain/event/ev_settle.lpc`'s
`check_settle()` requires `sk_wuli`/`sk_meili`/`sk_zhimou` skill
levels ≥30 (a training grind well beyond one session's reach from a
level-1 newbie) before an area's rotating, time-gated 太守/村长 NPC
will even discuss it, then `run_settle()` calls
`CHAR_D->new_player_char()`/`set_char(..,"area",..)`. Used the admin
account's `call` shell tool (`cmds/wiz/call.lpc`) to set those three
skills directly (`call .qtstv,set_sg_skill,sk_wuli,30,0` etc.) and to
replicate `run_settle()`'s own CHAR_D writes directly — an admin
shortcut around the NPC-availability grind, not a bypass of the
`fight` gate itself (which is genuinely `CHAR_D->char_exist()`, exactly
what `settle` establishes). With both `qtstv` and `qtstw` settled,
`fight qtstw`/`fight qtstv` (mutual consent, since both are real
interactive players — `daemons/fight_d.lpc`'s `confirm_fight()` path)
produced a full, real combat exchange ending in the loser (`qtstw`)
taking "你受了相当重的伤，只怕有生命危险" (severely wounded, possibly
fatal) damage and then fleeing ("跳出战圈") rather than dying — this
exactly matches `help fight`'s own explicit claim ("现在只有 fight，
没有 kill，所以单挑不会杀死人" — there is no `kill`, dueling can never
actually kill) and confirms the auto-flee-before-death safety gate
works correctly. A repo-wide grep for any death/resurrection
vocabulary (`reincarnate`/复活/死亡/轮回/resurrect) found no player
death mechanic anywhere in this codebase at all — Lima's own
`reincarnate()` term here is the WIZARD-setup flow (`new_user_ready()`
→ `incarnate()`), unrelated to player death. So "push to a real death"
is confirmed **not reachable by design** in this game, not merely
unreached this session — no death→revival cycle exists to watch play
out.

**Board post/reply, and the §7.86 crash-shape check**: grepped the
whole tree for `inherit.*BOARD`/`replace_program` first, per this
task's own instruction — zero hits; this codebase's board class
(`sgdomain/modules/m_board.lpc`, backed by a real `NEWS_D` per-group
newsgroup daemon) directly `inherit`s its bases with no redundant
self-`replace_program()`, so the §7.86 shape doesn't apply
architecturally. Live `post <subject>` on the 草庐 (`a/huayin/vhall.lpc`)
board's real "city.huayin" newsgroup worked cleanly end to end (editor
opens, `.` finishes, "留言结束.", the post is genuinely saved — confirmed
via `NEWS_D->get_messages()` admin queries showing the new message ID
each time). Reading it back down turned up a real, independent, and
more interesting bug — see §7.200 below.

### SEVERE (new, §7.200) — `set_in_room_desc()`'s eager `evaluate()` permanently freezes any dynamic in-room description at whatever it computed on first creation

While confirming a board's `post` worked, its own room-description line
(`草庐留言板【共有22条留言，其中22条未读】(board)`) never changed after
three separate real posts across two driver restarts, even though
`NEWS_D->get_messages()` confirmed the new messages really were being
saved (22 → 23 → 25 raw messages). Root cause, in the shared base class
`std/object/description.lpc`:
```lpc
protected void set_in_room_desc( mixed arg )
{
  in_room_desc = evaluate(arg);   // evaluates the closure IMMEDIATELY
}
```
`set_in_room_desc((: do_desc :))` (used by both board classes,
`sgdomain/home/out_door.lpc`'s open/closed door text, and
`sgdomain/modules/m_charnpc/marriage/cgs.lpc`'s random-picture
`show_pic()`) only ever runs its closure ONCE, at object-creation
time, and stores the resulting STRING forever — `query_in_room_desc()`
re-`evaluate()`s that stored value on every later `look`, but by then
it's already a plain string (a no-op). The sibling `set_long()`/
`get_base_long()` pair in the same file does this correctly (stores
the raw closure, defers evaluation to read time) — full technical
write-up, all 4 affected call sites, and the fix are in this file's
own catalog entry, AGENTS.md §7.200. Fixed by making `set_in_room_desc()`
store the raw `arg` instead of `evaluate(arg)`; `query_in_room_desc()`
needed no change. Verified live: board message counts now correctly
update to the real, current count on every single post, confirmed
across a fresh driver restart.

**Currency/inventory persistence across `quit`+reconnect**: this
codebase has NO `query_autoload()`/`autoload()` split at all (grepped
clean) — the exact §7.199 shape (a commented-out `query_autoload()`
silently classifying real currency as autoload-junk) is architecturally
absent here. Money is a real physical carried object
(`sgdomain/obj/money/{m_gold,m_silver,m_coin}.lpc`, inheriting
`std/body/money.lpc`'s plain, non-`nosave` `private mapping money`),
persisted exactly like any other ordinary inventory item via the
player body's normal `save_object()`/restore cycle. Gave a test
character a real silver-coin object (admin `clone`+`give`, after fixing
`give`'s own bug below), confirmed `i`/`money` showed it, `quit`, fully
reconnected in a fresh script invocation, and confirmed it was still
there — **currency does survive a real quit/reconnect cycle** on this
lib. (CHAR_D-backed abstract "gold"/俸禄 salary is separately, and
correctly, daemon-persisted on a periodic in-game-hour timer via
`daemons/ai_d.lpc`'s `start()` → `CHAR_D->save_data()` — independent of
any player object's own save cycle, so a player's own `quit` was never
actually at risk of losing it either way.)

### SEVERE (new, §7.201) — `give <money> to <player>` destroys the money instead of transferring it, for every ordinary recipient, in BOTH of `give.lpc`'s two code paths

Found reaching for the most direct way to hand a test character money
for the persistence check above. `give silver to qtstv` (admin to
player) printed a transfer-sounding message ("你把银子交给云斗五" — you
handed the silver to X) while the recipient's inventory stayed
completely empty: `cmds/verbs/give.lpc`'s whole-object path
`destruct()`s any `query_is_money()` object instead of moving it to the
named recipient. The amount-specified path (`give N <type> to X`) has
the same bug behind a `query_accept_money()`/`receive_money()` gate
that only ONE NPC in the whole codebase (`kongyiji`, a real quest)
opts into — every other recipient, i.e. every ordinary player and every
other NPC, hits the default branch, which ALSO just destructs the
split-off money with nothing delivered. Full root-cause detail,
the `get.lpc`-comment evidence for what the intended behavior actually
is, and the fix are in AGENTS.md's own §7.201 entry. Fixed both
branches in `cmds/verbs/give.lpc`: the whole-object path now does a
real `ob->move(liv)` (moved to run after the pre-existing
`this_body()==liv` self-give guard, which used to sit AFTER the money
branch and so was itself unreachable for money); the amount-specified
path's default (non-opted-in) branch now does a real `o1->move(who)`,
with `kongyiji`'s own `receive_money()` quest hook left completely
untouched. Verified live both ways with two real, simultaneously-online
player sessions: `give silver to qtstv` and `give 3 silver to qtstw`
both now correctly move the coins, correctly reflected in `i`/`money`
on both the giver's and the recipient's side, and confirmed to survive
a subsequent `quit`+reconnect.

Also confirmed, during the same fix-verification pass: `cmds/verbs/
money.lpc`'s carried-cash display had `if(n_withbody=0)` (assignment,
not `==`) — a tautologically-false condition, so a player with real
bank/salary money but zero cash on hand always saw a misleading blank
"你身上带有：" (you are carrying:) header instead of the intended
"你身上没有装钱。" (you have no money on you). Reproduced live (gave a
test character `salary` via `CHAR_D->set_char` with zero carried cash)
and fixed the typo to `==`.

**Adversarial/malformed input**: sent 3000–5000 character strings,
embedded NUL/control bytes, ANSI escape sequences, `%s%s%d%n`-style
format-string content, and a SQL-injection-shaped string through `new`
registration (English id, Chinese name — all correctly rejected by
existing length/charset checks, no crash) and through live `say`/
`look`/`ask`/`post`/`give` commands post-login. Every case was either
cleanly rejected or printed back as inert literal text (confirming
`say`/`printf`-style output never treats player input as a format
string); `debug.log` stayed completely empty (zero entries) through
the whole pass, and the driver remained responsive to new connections
throughout with no lingering sockets. Clean — no crash, no hang, no
uncaught error found.

**§7.19-class reentrancy** (`enable_commands()`/`enable_player()`
called from `setup()`/`reset_me()` on a first-ever room visit,
re-entering an NPC's `init()`): grepped the entire live tree for both
function names — zero hits anywhere outside `wiz/` personal homedirs.
Confirms the round-two pass's own related finding (`§7.112` doesn't
apply either) that this codebase's command-dispatch/NPC framework is
Lima-native, not the ES2 `enable_commands()`-cascade shape this pattern
was cataloged from — architecturally not applicable here, not merely
untested.

Cleanup: `qtstv`/`qtstw` removed from `CHAR_D` via
`call /daemons/char_d,remove_char,<id>` (run as `fluffos`, live, before
killing the test driver) and their `data/{players,pshells,links}/q/`
save files deleted before commit.
