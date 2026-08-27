# demonangel — 恶魔天使 (git clone from MudRen/DemonAngel)

Source: `git clone https://github.com/MudRen/DemonAngel` (commit
`9487693`, cloned 2026-08-26). Port: 40218. Status: **done** (boots
clean, full registration verified end-to-end with a real Chinese name,
`look`/`score`/`who`/`say`/`whoami`/relogin/`quit` all confirmed
working, admin `update` ACL confirmed).

## What this is

DA (Demon Angel, "恶魔天使") is a Chinese wuxia/xianxia MUD explicitly
derived from es2. Its own `README.md` states in so many words: "本 DA
mudlib 属于一个国家制度的 mudlib 由 es2 1.1e mudlib 修改而成" ("this
DA mudlib ... was modified from the es2 1.1e mudlib"), and the archive
ships es2's own original `README.ES2` unmodified alongside it (signed
"By Annihilator (06/15/95)"). This makes DA part of this project's
"ES II engine family" (`es2`, `haiyang2`, `xkx2001`, `es1_win`, `rzrmud`,
`xo`) -- same `adm/`+`feature/` framework, same recurring driver-compat
bug classes -- but with an entirely independent game world: `d/gourd`
(the starting hub city, literally named for a calabash/gourd),
`d/grid`, `d/pet`, `d/ship`, `d/special`, `d/wiz`, vs. es2's
`canyon`/`choyin`/`city`/`force`/`temple`/`village`. A prior research
pass confirmed this is genuinely independent content, not a duplicate
of es2 or any other onboarded ES2-family lib.

Layout mirrors es2 almost exactly: `adm/` (master/simul_efun/daemons),
`cmds/` (adm/debug/king/min/npc/usr/wiz command dirs), `feature/`
(action, alias, apprentice, attack, attribute, autoload, clean_up,
command, condition, damage, dbase, edit, equip, finance, `irc`,
liquid, message, more, move, name, save, skill, spell, team, treemap,
vendor), `std/` (armor, bboard, char, char/npc, equip, item, room,
ship, weapon/*), `d/` (game-world domains), `daemon/` (class/skill/spell
tables). `config.mud`'s mud name decodes (GB18030) to "葫芦" (gourd),
matching the `d/gourd` starting domain; `mudlib directory : .` (repo
root is the mudlib root, same as es2, no nested subdirectory). Start
room `/d/gourd/gourd_recall` (中央广场, a hub plaza with roads to four
city gates), death room `/d/special/death`.

`feature/irc.lpc` is a red herring: despite the name, it implements an
in-combat team/party-formation mixin (`add_irc_team_member`,
`is_irc_team_leader`, etc.), not an actual IRC bridge -- confirmed no
`socket_connect()`/outbound-network calls anywhere in it.

## Network / outbound-connections check (AGENTS.md caveat)

`adm/daemons/network/` ships a full but incomplete Intermud-style
subsystem (`dns_master`, `mail_serv`, `ftpd`, `telnetd`, `inetd`,
`name_server`, `pingd`/`pingtcp`, `ms`, `userid`, `netmail`,
`services/`) with real `socket_connect()`/`resolve()` calls (in
`ftpd.lpc`). Confirmed **both** `dns_master` and `ftpd` are commented
out of `adm/etc/preload` in the original archive (`#/adm/daemons/
network/dns_master`, `#/adm/daemons/ftpd`) -- the only two daemons that
could reach this code are never loaded at boot. This lib makes **zero
outbound network connections** on boot; safe for an automated reboot
loop. (Same subsystem, same disabled state, as in `es2`.)

## Conversion (GBK→UTF-8)

`scripts/convert_lib.sh libs/demonangel/raw/DemonAngel libs/demonangel/
work GB18030`. Results: 1117 files converted, 86 already UTF-8, **0
lossy** conversions, 21 binaries skipped (unlike es2's 8 lossy files --
this archive's encoding was completely clean). `.c`→`.lpc` renamed 709
files; 181 literal `.c"` references fixed; 8 local `#include <x.lpc>`
angle-bracket includes converted to quoted form.

- **`static`→`nosave` string-literal collision** (AGENTS.md §4.3,
  identical to es2): the blanket `\bstatic\b`→`nosave` sed rewrote
  `log_file("static/...")` path literals in `adm/obj/master.lpc`,
  `adm/daemons/securityd.lpc`, `cmds/npc/suicide.lpc`, `cmds/adm/
  purge.lpc`, `cmds/wiz/call.lpc` (7 hits/5 files) -- reverted `"nosave`
  back to `"static` in all of them. No `#define nosave static`
  compatibility-shim collision found.

## Config / driver-compat fixes

`libs/demonangel/config.fluffos` modeled on the raw `config.mud`
(decoded mud name `恶魔天使`, decoded ANSI-wrapped default error
message preserved byte-for-byte with real escape codes, not
re-typed), pointed at `libs/demonangel/work`, port 40218; dropped the
obsolete directives this driver flags (`address server ip/port`,
`binary directory`, `swap file`, `reserved size`) and reduced the raw
config's absurd `maximum local variables : 10000000` to `200` (in
line with es2's 40 / haiyang2's 30 -- the raw value was clearly a
typo/no-op on the original driver too).

1. **`adm/obj/master.lpc`'s `valid_override()` was 2-arg** (AGENTS.md
   §10.4, identical to es2) -- `simul_efun.lpc` `#include`s 8 fragment
   files needing the 3-arg `(file, name, main_file)` signature. Widened
   the signature and OR'd in `main_file == SIMUL_EFUN_OB`.
2. **`adm/simul_efun/file.lpc`'s `log_file()` had no `assure_file()`
   guard** (AGENTS.md §7.11, identical to es2's fix #2) -- added one
   with a forward declaration (this driver needs forward decls for
   same-file forward references). Also guarded `master.lpc`'s own
   `log_error()` bypass write (`efun::write_file(home + "log", ...)`)
   the same way.
3. **`destruct()` AND `exec()` both overridden as simul_efuns**
   (AGENTS.md §7.38 covers `destruct()`; this driver rejects `exec()`
   the same way, undocumented there until now) --
   `adm/simul_efun/object.lpc` had `void destruct(object ob)` (pre-
   cleanup `ob->remove(euid)` before `efun::destruct()`, "es2 1.2b")
   and `int exec(object to, object from)` (restricted callers to
   `/adm/daemons/logind` and `/cmds/wiz/update` before `efun::exec()`).
   Both hard-rejected at compile time ("Invalid simulated efunction
   override"). Deleted both wrappers; bare `destruct()`/`exec()` calls
   now hit the real efuns directly, losing the pre-cleanup step and the
   caller restriction respectively (same documented tradeoff as every
   other lib in this collection that hit the `destruct()` half of this
   class -- `es2`, the `haiyang` family, `xkx100`).
4. **`is_chinese()`/`check_legal_name()` GBK byte-range vs. CJK-
   codepoint mismatch** (AGENTS.md §8.1, identical to es2) --
   `adm/simul_efun/chinese.lpc`'s `is_chinese()` was `strlen(str)>=2 &&
   str[0] > 160 && str[0] < 255` (a GBK-lead-byte heuristic that never
   matches this driver's UTF-8-native character indexing) and
   `adm/daemons/logind.lpc`'s `check_legal_name()` had the matching
   byte-calibrated `strlen(name) < 2 || > 12` bound plus an `i%2==0`
   GBK-lead-byte loop gate, even though its own error message says "1
   到 6 个中文字". Fixed both to the §8.1 playbook: `is_chinese()` now
   checks the CJK-Unified codepoint range (`str[0] >= 0x4e00 && str[0]
   <= 0x9fff`); `check_legal_name()`'s bound is the literal `1..6`
   characters the message states, checking every character (no `%2`
   gate). Live-verified: 秦风 (2 characters) registered cleanly.
5. **`std/weapon/throwing.lpc`'s `setup()` referenced `damage` out of
   scope** -- `damage` is a parameter of the sibling `init_throwing()`
   function, not `setup()` (every OTHER weapon type in `std/weapon/`
   has this exact `damage+query_weight()/N+1` line, but inlined
   directly inside their own `init_X()` -- only `throwing.lpc` splits
   it into a separate `setup()`, exposing the scope bug). Fixed to
   `query("weapon_prop/damage")+query_weight()/20+1`, matching what
   `init_throwing()` itself stores via `set("weapon_prop/damage",
   damage)`.
6. **`obj/token.lpc` used the bare macro `SAVE_EXTENSION`**, never
   defined anywhere in this archive's includes -- this driver's real
   predefine is `__SAVE_EXTENSION__` (confirmed against
   `~/src/fluffos/build-debug/src/options.autogen.h`; matches es2's
   `feature/save.lpc` usage). Fixed both call sites
   (`obj/token.lpc:111,188`). (`cmds/adm/purge.lpc` also uses a bare
   `SAVE_EXTENSION` but defines its own local `#define SAVE_EXTENSION
   ".o"` at the top of the file -- self-contained, not a bug.)
7. **`open/sky/42.lpc` and `cmds/min/develop.lpc` share the exact same
   copy-pasted author typo**: `set("short", "马厩\");` -- a stray
   backslash immediately before the closing quote escapes it, so the
   string literal swallows everything up to the NEXT unescaped quote
   in the file. In `42.lpc` this ran straight into a `@TEXT`/`TEXT`
   heredoc a line later, producing "End of file in string"; in
   `develop.lpc` (a `mapping` literal, not a heredoc) it produced
   cascading "Illegal character"/syntax errors a line down as the
   lexer resynced mid-token on raw UTF-8 bytes. Fixed both (removed the
   stray backslash: `"马厩"`). Three more instances of the identical
   `马厩\` typo exist in `cmds/min/build.lpc` but land mid-string
   before an ordinary Chinese comma rather than before a closing quote
   -- those only produce non-fatal "Unknown escape sequence" warnings
   (build.lpc compiles fine) and were left as-is (cosmetic, matches
   AGENTS.md's "don't fix content" boundary for a warning-only typo).
8. **`include/ship.h`'s `do_save_ship()` had an unescaped-quote string
   bug**: `str += "#include "ansi.h"\ninherit SHIP;...";` -- the
   embedded `"ansi.h"` quotes broke out of the outer string literal
   mid-expression, producing "Cannot #include config.h"/"Illegal LHS"
   cascading errors in every file `#include`-ing `ship.h` (only
   `cmds/adm/put_ship.lpc` does). Fixed: `"#include \"ansi.h\"\n..."`.
9. **`cmds/wiz/tail.lpc` called a bare `tail()` efun** that was never
   real on MudOS/FluffOS (identical to es2's fix #10) -- reimplemented
   with `read_file()`+`explode()`+`implode()` (last 15 lines).
10. **`cmds/npc/meditate.lpc`: unbalanced parenthesis** -- `mana_gain =
    sen_cost * ((int)me->query_skill("spells");` has one extra unmatched
    `(` before the cast, with nothing closing it (a straightforward
    stray-character typo, same class as es2's goddd.lpc paren fix).
    Removed the stray open-paren rather than guessing at an intended
    divisor (the comment above claims the result "ranges from 1 to 15
    when sen_cost = 30", which no simple reading of the surrounding
    code supports either way -- left the arithmetic itself untouched
    per the "don't redesign game balance" boundary, only restored
    valid syntax).
11. **`cmds/usr/mount.lpc`'s `main()` referenced `ob`, never declared
    or assigned in that function** (`ob` is only a parameter name of
    the sibling `do_ride()`) -- `main()` never actually resolved `arg`
    into a target object at all, an outright dropped line rather than
    a scope typo. Restored the minimal, standard resolution idiom this
    same codebase uses in dozens of sibling commands (e.g.
    `cmds/usr/ident.lpc`: `object ob; ... if(!(ob = present(arg,
    environment(me)))) return notify_fail(...)`) -- deliberately did
    NOT add the pet-registration bookkeeping `cmds/usr/dismount.lpc`
    expects (`me->query("list/pet/file")`, etc.), since that's a
    genuine content/design gap in how `mount`/`dismount` are wired
    together, out of scope here.
12. **Cross-inherit `clean_up(int)` signature mismatch silently
    truncated `std/room.lpc`'s function table when inherited** -- a
    genuinely confusing one, root-caused via a minimal standalone
    repro (`inherit "/std/room"; void create(){create_door(...);}`)
    before touching anything. `feature/clean_up.lpc` defines `int
    clean_up()` (0 args); `std/room.lpc` overrides with `int
    clean_up(int inherit_flag)` (1 arg), producing a "Number of
    arguments to 'clean_up' disagrees with previous definition"
    warning -- but that warning turned out to be a red herring
    (fixing the signature mismatch alone did NOT fix the actual bug,
    confirmed by re-testing the repro). The real cause, found by
    bisecting which of `std/room.lpc`'s functions were visible after
    inheriting it: lines 76-187 of `std/room.lpc` (the ENTIRE door
    subsystem -- `look_door`, `open_door`, `close_door`, `check_door`,
    `create_door`, `query_doors`, `query_door`) are wrapped in one
    giant `/* ... */` block comment, with `valid_leave()`'s own
    door-check logic separately commented out right below it. This is
    deliberate, mudlib-wide-disabled functionality, not a driver
    parsing bug -- `nosave mapping doors;` at the top of the file is
    ALSO commented out. The only live caller of `create_door()`
    anywhere in the archive, `d/wiz/entrance.lpc`, is a leftover that
    was never updated when doors were disabled. Fixed the (harmless,
    unrelated) signature mismatch anyway for hygiene, then disabled
    the orphaned `create_door()` call in `entrance.lpc` to match the
    already-disabled subsystem -- the exact same fix shape as es2's
    §7 fix #11 (city gates calling `create_door()` against an
    already-disabled exit).
13. **`std/char/npc.lpc`'s `carry_object()` didn't honor its own
    documented 0-on-failure contract**: `ob->move(this_object());
    return ob;` returns the newly-`new()`'d object regardless of
    whether `move()` actually succeeded. `move()`
    (`feature/move.lpc`) can fail silently via its own
    `notify_fail()`+`return 0` when the destination's encumbrance
    capacity is exceeded -- and critically, **no plain NPC ever gets
    `max_encumbrance` initialized at all** (`set_max_encumbrance()` is
    only ever called from `adm/daemons/chard.lpc` and the
    `adm/daemons/race/*.lpc` files, all of which only run for player
    characters, never for `std/char/npc.lpc`-based NPCs). So every NPC
    that calls `carry_object(heavy_item)->wear()` in its own
    `create()` -- `obj/npc/heaven_soldier.lpc`'s 50000-weight armor,
    `obj/npc/garrison.lpc`'s cloth/longsword, `d/obj/npc/guard_1.lpc`'s
    sword -- has `move()` silently fail, `carry_object()` returns the
    un-contained object anyway, and the chained `->wear()`/`->wield()`
    then crashes with `*Bad argument 1 to EFUN call_other() ...  Got:
    int(0)` once `wear()`'s own `environment()` check hits 0. This is
    exactly the "MudOS tolerated a nil call_other, this driver enforces
    strict typing" class already catalogued for the ES2 family (es2's
    fix #6/#7) -- just reached via a silently-failed `move()` instead
    of a missing content path. Fixed at the root: `carry_object()` now
    checks `move()`'s return value, `destruct()`s the orphaned clone
    and returns 0 on failure (honoring the contract `add_money()` right
    below it already assumes); guarded all 4 real call sites
    (`heaven_soldier.lpc` x2, `garrison.lpc` x2, `guard_1.lpc` x1) with
    `if (ob = carry_object(...)) ob->wear();`. Left the underlying
    encumbrance-never-initialized-for-NPCs gap itself alone (a genuine
    pre-existing content/design incompleteness, not something to
    invent a fix for) -- NPCs affected by this now start without their
    listed starting gear instead of crashing their own `create()`,
    same net effect the original MudOS driver would have had.
14. **`feature/move.lpc`'s string-destination resolution can hard-
    crash on a nonexistent target file**: `move(dest)` when `dest` is
    a string does `call_other(dest, "???")` purely to force-load the
    file (ignoring the nonsense-function-name return), then
    `find_object(dest)` and a `notify_fail()` fallback if that's still
    0. But `call_other()` on a path with NO compiled object AND no
    file to compile throws a hard, uncatchable-by-the-caller
    `*call_other() couldn't find object ...` error on this driver
    instead of just failing to compile -- so the existing `if(!ob)
    return notify_fail(...)` fallback never gets a chance to run.
    Surfaced via 5 of the 7 `obj/board/*_b.lpc` files (all bulletin
    boards), each `move()`-ing itself in `create()` into a hardcoded
    room path left over from es2's own world (`/d/temple/temple1`,
    `/d/snow/inn`, `/d/sanyen/temple`, `/daemon/class/fighter/
    guildhall`, `/d/snow/schoolhall` -- domains that plainly do not
    exist in DA's own `gourd`/`grid`/`pet`/`ship`/`special`/`wiz`
    world) that were never updated when DA repurposed es2's board
    templates. Rather than guessing which of DA's own rooms each board
    was meant to end up in (a content decision, out of scope), wrapped
    the forced-load call in `catch()` (both the `move()` and
    `direct_move()` copies of this code in `feature/move.lpc`) so a
    genuinely-missing destination degrades to the pre-existing
    "destination unavailable" `notify_fail()` instead of crashing the
    board's `create()` outright. This is a shared low-level utility
    fix (parallel to the `std/room.lpc` `catch()`-around-`new()`/
    `move()` guard es2's fix #6 added), benefiting every caller
    uniformly rather than patching each board individually.

## Not fixed (pre-existing content gaps / dead code, confirmed via `raw/`)

- **`adm/daemons/network/` (12 files)** -- see the outbound-network
  section above; genuinely unreachable (both entry points excluded
  from `preload`), same dead subsystem as es2.
- **`std/room.lpc`'s entire door subsystem** (lines 76-187, see fix
  #12 above) -- deliberately disabled mudlib-wide; only re-enabling it
  properly would be a content/design change, not a driver-compat fix.
- **`F_CLOTH`/`CLOTH` referenced but never defined anywhere** --
  `d/obj/npc/wp/blue_cloth.lpc` (`inherit F_CLOTH;`) and
  `obj/prize/black_vest.lpc` (`inherit CLOTH;`) are each the ONLY
  user of their respective macro; no `std/*cloth*` base class exists
  anywhere in the archive. Exact same shape as es2's `F_UNIQUE`/
  `F_MERCENARY` gap -- a feature class that predates this snapshot or
  was pulled from a different site branch. Not something to invent a
  base class for.
- **`F_FOOD`/`/feature/food.lpc` referenced but never shipped** --
  `obj/example/dumpling.lpc` (documentation/example scaffolding, like
  es2's `obj/example/book.lpc`) is the ONLY user; `feature/food.lpc`
  doesn't exist anywhere in the tree. Genuine content gap.
- **`POWDER`/`/std/medicine/powder.lpc` referenced but never shipped**
  -- `obj/slumber_drug.lpc` is the only user. Same shape as the above
  two.
- **`obj/npc/garrison.lpc`'s `set_skill("move", 100)`** -- `feature/
  skill.lpc`'s `set_skill()` validates against a `SKILL_D(skill)` file
  existing on disk; no skill daemon file for `"move"` exists anywhere,
  so this NPC's `create()` hard-`error()`s before it ever reaches the
  `carry_object()` calls fixed in #13 above. A genuine missing-content
  skill definition, not a driver-compat issue; left as-is.
- **`std/virtual/compiler.lpc`, `adm/daemons/virtual/template/room.lpc`**
  -- unfinished "room description compiler" scaffolding (`#include
  <config.h>`/`<uid.h>`, neither of which exist at those bare paths
  anywhere in the archive; `template/room.lpc`'s `::create()` has no
  resolvable parent). Confirmed unreferenced by anything else in the
  tree -- dead scaffolding, same class as es2's own `std/virtual/
  compiler.lpc` (this file is near-verbatim shared code between the
  two libs).
- **`std/room/bak/hockshop.lpc`** (`COIN_OB` commented out in
  `globals.h`) and **`daemon/skill/bak/gouyee.lpc`** (`/std/force.lpc`
  doesn't exist, `FORCE` macro used nowhere else) -- both live in
  `bak/` backup directories and are unreferenced by anything else.
  Dead scaffolding.
- **`doc/ref/lpc.lpc`, `doc/concepts/lpc.lpc`** -- plain-text prose
  documentation files that `convert_lib.sh`'s extension-based `.c`→
  `.lpc` rename swept up along with real source (they were originally
  `.c` too, e.g. Usenet-post-style help text beginning "发信人:
  jinna@phoenix ..."). Not real LPC, not referenced/preloaded by
  anything -- cosmetic-only lpcc failures, harmless at a real boot.

## Interactive test result — full registration + relogin flow

Registration shape: English id (3-12 lowercase letters) → confirm
new-character (y/n) → real Chinese name (1-6 characters, after the
§8.1-class fix above) → password (≥5 chars, entered twice) → email
(free text) → gender (m/f) → MOTD → lands in `/d/gourd/gourd_recall`
(中央广场, the gourd-city central plaza).

Verified live with a raw Python socket script (UTF-8 throughout --
this archive, unlike some sibling ES2-family libs, needed no special
client-side encoding gymnastics once converted) using a real Chinese
name (秦风):

- **Registration**: `look` after landing showed the full room
  description (四方通往四座城门), exits (`down`/`west`/`east`/
  `north`/`south`), a bulletin board, and NPC 小美女; `score` showed a
  fully populated character sheet (level, race/gender, 六维属性,
  体力/法力 bars, combat ratings); `whoami` showed `User ID = fluffos`.
- **Relogin**: reconnecting and re-entering the same id + saved
  password logged back in cleanly (no re-registration prompt),
  confirming `data/login/f/fluffos.o` and `data/user/f/fluffos.o` both
  saved correctly on first quit.
- **`who`** showed 秦风 as the sole connected user with the correct
  mud-name banner; **`say hello world`** produced the correct
  ANSI-colored self-echo (`你说道：hello world`).
- **`quit`** produced a clean `欢迎下次再来！` with zero runtime errors
  in the driver's stdout/stderr log across the whole session (only the
  expected lazy-compile warnings, which this codebase's `master.lpc`
  `log_error()` deliberately echoes to a connected wizard/admin's
  screen -- intentional existing behavior, not a bug).

## Admin account

`fluffos` / `Mud@2026`, Chinese display name 秦风. Granted via this
lineage's own mechanism (identical to es2): `adm/daemons/securityd.lpc`'s
`create()` reads `adm/etc/wizlist` (a plain `<euid> <status>` text
file) into the in-memory `wiz_status` mapping every boot -- added a
`fluffos (admin)` line alongside the pre-existing `bor (admin)` entry,
then registered `fluffos` through the normal flow. Verified: `update
/adm/obj/master` succeeds ("master: loaded successfully. 重新编译
/adm/obj/master.lpc：成功！") -- the canonical read+compile ACL check
per AGENTS.md §1.5.

## Compile sweep summary

`scripts/lpcc_check.sh`: 709 total, 41 initial failures → 22 remaining
after fixes (96.9% pass rate). All 22 remaining failures are confirmed
dead code, deliberately-disabled subsystems, or genuine pre-existing
content gaps documented above (10 of them are the same already-known
`adm/daemons/network/` tree as es2) -- none affect the live, reachable
game.

## 深度功能测试 / Deep functional test (round two, AGENTS.md §10.7)

First genuinely hands-on *playthrough* pass (the earlier "done" status
above only ever verified registration + `look`/`score`/`who`/`say`/
`whoami`/relogin/`quit`, never real gameplay: movement, class/skill
acquisition, combat, economy, or death). One continuous session on the
native driver (`~/src/fluffos/build-debug/src/driver config.fluffos`),
a raw Python socket client throughout, plus a second admin connection
for teleporting (`goto`) to distant content and for a controlled death
test.

**Newbie path**: no `help newbie`/`help intro` topic exists
(`doc/help/topics` itself is missing too, so even bare `help` prints
nothing useful) -- a genuine content gap, not a bug, left as-is per
scope. Learned the real onboarding shape by reading source instead:
register lands in `/d/gourd/gourd_recall` (中央广场) as a generic "冒险者"
(Adventurer); the actual class system is `d/gourd/choice_class.lpc`
(职业介绍所, reached `north`/`north`/`north`/`west` from the start
room) -- `list` shows 魔法师/战士/牧师, `advance <职业>` locks it in
once. No traditional wuxia master-disciple/sect system is reachable
anywhere in this archive: `feature/apprentice.lpc`'s `recruit_apprentice()`
API exists but is **never called from anywhere else in the tree** --
this game's actual family/social system (`swear`/`adopt`/`marry`, per
`doc/help/family`) is unrelated (marriage/kinship, not martial
apprenticeship), and skill advancement past the initial class pick
runs through the 王国 (kingdom) economy instead (buildable
`magic_tower`/`trainyard`/`hero_guild` rooms, gated behind kingdom
gold/room-count thresholds `cmds/min/build.lpc` enforces) -- confirmed
this is intentional world design, not a missing feature, and left
untouched.

Test character: id `qinlong`, 秦龙 (male, 战士 after class pick),
password `Test@2026` -- kept as a representative playthrough character
(save files `work/data/login/q/qinlong.o`, `work/data/user/q/qinlong.o`).
Admin account `fluffos`/`Mud@2026` (per this lib's existing seeding)
used for `goto` teleports and the death test.

### Bug 1: `private nomask command_hook` and 15 sibling `private`-callback functions across the ES2-inherited codebase -- AGENTS.md §8.3a's class, not previously swept on this lib

`feature/command.lpc`'s central dispatcher was declared `private nomask
int command_hook(string arg)`, registered via `add_action("command_hook",
"", 1)` in the SAME file's `enable_player()`. `command.lpc` is
`inherit`ed into `std/char.lpc` (the base class for both `obj/user.lpc`
and every NPC), which demotes the inherited `private` function to
`DECL_HIDDEN` on this driver -- `add_action`'s later efun-origin
dispatch then hard-refuses to call it (`apply() with insufficient
permission: ... function: command_hook, origin: efun, needs: private,
has: hidden`), reproduced live in `driver_stdout.log` during ordinary
play (triggered from an internal `command()`-style self-call, not a
directly-typed command -- matches this bug class's documented "typed
commands can still look fine" caveat exactly).

A full repo-wide grep (private-function-name declared in the same file
as an `add_action("name"` or `call_out("name"` registration of that
exact name) found **8 more affected files, 16 functions total**, all
genuinely `inherit`ed elsewhere (verified each has a real `inherit`
site, not dead/unused):

| File | Function(s) | Registered via |
|---|---|---|
| `feature/command.lpc` | `command_hook` | `add_action` (the confirmed-live crash above) |
| `feature/action.lpc` | `eval_function` | `call_out`, from `start_call_out()` -- the shared delayed-effect primitive documented in AGENTS.md for `xuanjianlu`/`zjdyaryl`; **confirmed dead in this specific archive** (`start_call_out()` itself has zero callers anywhere in the tree), fixed anyway for consistency with the sibling pattern in case a future skill/drug file starts using it |
| `std/item/combined.lpc` | `destruct_me` | commented-out `call_out("destruct_me", 0)` -- **not currently live**: the real code path calls `destruct_me()` directly (`if (v == 0) destruct_me();`), a normal same-file call unaffected by this bug class. Fixed anyway since the dead `call_out` line is right there as a latent trap (this base class is inherited by `std/money.lpc`, i.e. every coin in the game, plus several potions/weapons) |
| `std/room/furnace.lpc` | `do_load`, `furnace_count_msg`, `furnace_drop`, `do_charge`, `charge_furnace` | `add_action`/`call_out` (魔力炉, inherited by `open/sky/19.lpc`, `24.lpc`) |
| `std/room/misc_shop.lpc` | `do_list`, `do_buy` | `add_action` (杂货店, inherited by `open/sky/28.lpc`, `71.lpc`) |
| `std/room/herb_shop.lpc` | `do_list`, `do_buy` | `add_action` (药店, inherited by `open/sky/30.lpc`, `31.lpc`, `70.lpc`) |
| `std/room/magic_tower.lpc` | `do_list`, `do_study` | `add_action` (法术研习营, inherited by `open/sky/36.lpc`, `73.lpc`) |
| `std/bboard.lpc` | `do_post`, `do_discard`, `do_followup` | `add_action` (see Bug 2 below -- these compound with the redundant `replace_program()` bug on every board) |
| `std/jboard.lpc` | `do_followup` | `add_action` (`obj/board/wizard_j.lpc`) |

Fix, identical everywhere: drop `private`, keep any other modifiers
(`nomask`, etc.) -- these functions are never meant to be player-typed
verbs themselves, so exposing them as ordinary (non-private) functions
adds no real capability. Left alone (confirmed genuinely unaffected,
since this driver only demotes `private`-in-an-*inherited* file, not a
`private` function declared directly in a file nobody else `inherit`s):
`obj/user.lpc`'s `user_dump` (net-dead timeout, `USER_OB` is a leaf,
nothing inherits `obj/user.lpc`), and three other leaf files with the
same shape (`obj/npc/demogorgon.lpc`'s `countdown`, `d/gourd/
gourd_recall.lpc`'s `do_relax`, `cmds/npc/suicide.lpc`'s
`slow_suicide`) -- all confirmed via `grep -rn "inherit.*<name>"` to
have zero inheriting files anywhere in the tree.

Verified live post-fix: `buy bean` at `/open/sky/28` (misc_shop),
`charge furnace` at `/open/sky/19` (furnace, call_out path), `kill
girl`/movement/class-advance (command_hook path) all worked with zero
`insufficient permission` lines in `driver_stdout.log` across the whole
session -- see the sections below for the actual playthrough these
were exercised in.

**Sibling libs to check**: `es2`, `haiyang2`, `xkx2001`, `es1_win`,
`rzrmud`, `xo` share this codebase family; `xkx2001`/`rzrmud` already
have their own §10.7 passes and may or may not have hit this
independently -- worth a `grep -rn 'private.*command_hook'` sweep plus
the same same-file `add_action`/`call_out` cross-check across all six,
since this session found it recurs in non-`command_hook` functions too
(the furnace/shop/board pattern above), not just the one function
AGENTS.md's existing §8.3a catalog already tracks by name.

### Bug 2 (AGENTS.md §7.86's class, confirmed on a 4th codebase lineage): every bulletin board redundantly self-`replace_program()`s its own already-`inherit`ed class, permanently crashing `post`/`followup`

Reproduced live, first try, on a completely fresh boot: `post <title>`
at the very first board a player meets (`obj/board/gourd_recall.lpc`,
the board sitting in the start room) crashed instantly --

```
执行时段错误：*cannot bind an lfun fp to an object with a pending replace_program()
程式：/std/bboard.lpc 第 107 行, 物件: /obj/board/gourd_recall
呼叫来自：/std/bboard.lpc 的 do_post() 第 107 行，物件： /obj/board/gourd_recall ("留言板")
```

Exact match for AGENTS.md §7.86 (previously seen on `xhcii`, `zxty`,
`hy2000`, `xyj2000` -- three unrelated ES2/金庸/西游记 lineages, now a
4th, independent DA/es2 lineage). Root cause identical: every board
file does `inherit BULLETIN_BOARD;` (giving it `do_post`'s `this_player()
->edit((: done_post, this_player(), note :))` closure-creation code
directly) **and then also** calls `replace_program(BULLETIN_BOARD)` in
its own `create()` -- completely redundant since the class is already
directly inherited, and actively harmful on this driver: the object's
"replace program pending" flag is set the moment `replace_program()`
runs and is never observed to clear, so `do_post()`'s and
`do_followup()`'s attempt to bind an unbound lfun closure (`done_post`,
implicitly bound to `this_object()`, the board itself) fails forever,
for the lifetime of that board object. `do_read()`/`list`/`look` all
work fine (no closure involved), which is exactly why the earlier
onboarding smoke-test pass never caught it -- a board looks completely
healthy right up until someone actually tries to write something.

Found and fixed in **all 13 real board instances plus the in-game
builder's own code-generation template**:

- `obj/board/{taoist_b,common_b,wizard_b,gourd_recall,dancer_b,bonze_b,
  gourd_lpc,gourd_bug,query_b,swordsman_b,fighter_b,bor_board}.lpc`
  (12 files, all `inherit BULLETIN_BOARD;` + redundant
  `replace_program(BULLETIN_BOARD);`)
- `open/sky/data/sky15.lpc` (same shape, a kingdom-built board)
- `obj/board/wizard_j.lpc` (same shape but the `JBOARD`-equivalent
  class, `inherit "/std/jboard";` + `replace_program("/std/jboard")`)
- `cmds/min/build.lpc`'s `make_base_post_office()` -- this is the
  **code generator** the in-game `build` wizard/king command uses to
  write a brand new kingdom post-office board file; its string template
  emitted the exact same buggy `inherit BULLETIN_BOARD;` +
  `replace_program(BULLETIN_BOARD);` pair, so every future
  kingdom-built board would reproduce this crash forever even after
  fixing the 13 existing files. Fixed by dropping the generated
  `replace_program(BULLETIN_BOARD);\n}` line from the template (now
  just closes with `}`), with a comment explaining why, so it does not
  get silently re-added by a future edit. Also checked and confirmed
  clean: the *generic* room-builder path (`make_room()`, the
  `case "board":` branch of `build <type> <direction>`) inherits a
  different, unaffected class (`BOARD` = `/std/room/board`, a thin ROOM
  wrapper that just `load_object()`s the real board from kingdom data
  -- itself only `inherit ROOM;` + `replace_program(ROOM)`, and `ROOM`
  never creates a self-bound closure, so this half of the generator was
  never broken).

Verified live, before and after: before the fix, `post <title>` crashed
exactly as above on a completely fresh boot (first command tried).
After the fix (all 13 files + the template, LPC formatter run, fresh
reboot), `post 深度测试标题2` / `Test body...` / `.` on the exact same
board opened the editor normally, printed "留言完毕", and `read 2`
confirmed the new post saved with correct author/timestamp/body;
`followup 2` / body / `.` on the same message also completed cleanly
("留言完毕"). Zero `insufficient permission`/`cannot bind` lines in
`driver_stdout.log` for the rest of the session.

**Also checked and confirmed NOT affected by the general
`inherit X; ... replace_program(X);` redundant-idiom shape** (grepped
all 107 files in this archive using `replace_program()`, cross-checked
each against its own `inherit` line): dozens of `open/sky/*.lpc` room
files redundantly self-`replace_program()` the exact same way for
`ROOM`, `SHOP`, `TAVERN`, `ARMORY`, `SMITH`, `GATE`, `BANK`, `CHURCH`,
`STABLE`, `PORT`, `PET_SHOP`, `WEDDING`, `SWEAR`, `POST_OFFICE`,
`HERO_GUILD`, `BARRACKS`, `TRAINYARD`, `ACTIONROOM` -- but none of
those base classes ever create a self-bound `(:` closure anywhere in
their own code (confirmed by grep), so the "pending" flag never
actually gets exercised for them and they are not currently broken.
Left untouched (removing a redundant-but-harmless call on ~90 working
files would be pure churn, out of scope for a bug-fix pass) -- flagged
here in case a future pass adds an editor/closure-using command to any
of these classes, since the same landmine is sitting there dormant.

**Sibling libs to check**: same recommendation as AGENTS.md §7.86
itself -- any ES2-derived lib with a `BULLETIN_BOARD`/`bboard.lpc`-style
board class is worth a one-line grep
(`grep -rln 'inherit BULLETIN_BOARD' | xargs grep -l 'replace_program(BULLETIN_BOARD)'`)
before assuming its own `post` command works.

### What was tested and confirmed working

- **Registration + class pick**: real Chinese name (秦龙), landed in
  `/d/gourd/gourd_recall`; real navigation (`north`×3, `west`) to
  `/d/gourd/choice_class`, `list` showed the three classes, `advance
  战士` succeeded, `score` immediately reflected "战士" instead of
  "冒险者".
- **Combat**: no dedicated safe-sparring dummy exists in this archive
  (`std/char/npc.lpc`'s generic `accept_fight()` only declines a
  "friendly"-attitude NPC, or any NPC when the attacker isn't near-full
  health -- there's no stat-copying training-dummy mechanism to find).
  Used the low-level, clearly-harmless "小美女" (阿宝) NPC standing in
  the start room itself (level 1, `int 3`/`dex 2`, no weapon) -- `kill
  girl` fought to a real, harmless standstill (both sides level 1
  unarmed, 0 damage exchanged either way, matching design), `flee`
  correctly disengaged. Zero errors.
- **Shop/economy**: `list`/`buy bean` at the misc_shop (`/open/sky/28`)
  completed correctly (gold deducted, item received, confirmed via
  `i`). Full-tree grep for `float` in any currency-adjacent code
  (`feature/finance.lpc`, `feature/dbase.lpc`, `std/money.lpc`,
  `std/char.lpc`) found **zero float usage anywhere** -- the only
  `float` declaration in the whole archive is an unrelated wizard `mem`
  command. The §7.121-class bug (an `int`-declared function doing real
  float math with no `to_int()`) **does not exist in this lib** --
  every money/exp function (`can_afford`, `pay_money`, `deposit_bank`,
  `withdraw_bank`, `got_money`, bank `deposit`/`withdraw`/`transfer`) is
  pure integer arithmetic throughout.
- **Quit / relogin persistence**: `quit` produced the normal "欢迎下次
  再来！" with zero new lines in `driver_stdout.log`; waited a real
  ~90-second wall-clock gap, reconnected with the same id+password --
  logged back in cleanly (no re-registration prompt) with the class
  change ("战士") correctly persisted.
- **Death / respawn**: no wild monster was worth risking for a real
  kill at level 1 (everything nearby trades 0 damage), so used the
  documented admin-forced-death pattern (`smash <target>` →
  `ob->die()` directly) on `qinlong` while genuinely net-dead
  (disconnected, not `quit`) from the earlier combat test -- `秦龙死了`
  printed with zero errors, a corpse ("秦龙的尸体") was left in
  `gourd_recall`, and after the ~13-15 second `delay_move_recall`
  `call_out` fired, reconnecting showed the character alive again at
  the start room with HP 31/39 (79%) and MP 30/25 (120%, from `die()`'s
  hardcoded `set("mp", 30)` intentionally exceeding a level-1 character's
  25 max -- a deliberate flat respawn value in the source, not a
  driver-API misuse, left untouched per scope). Confirms this lib's
  simpler (no ghost-stage, no `DEATH_ROOM->start_death()`) death flow
  works correctly end to end, including the net-dead-body edge case.

### ES2-family cross-check (2026-08-27): AGENTS.md §7.129 `tell_room()` bug found and fixed — NOT on the core death path, but real elsewhere

Following up on `es1`'s severe §7.129 find (a shared `tell_room()`
wrapper forwards its omitted `exclude` arg to `message()` as a literal
`int(0)`, which this driver's `message()` rejects), checked this direct
ES2-family descendant. This lib's core `die()` (`feature/damage.lpc`)
uses `message_vision()`, not `tell_room()`, for its death announcement
— explaining why the earlier §10.7 deep-test pass above (which did
reach a real death) never tripped this bug. But `adm/simul_efun/
message.lpc`'s `tell_room(ob, str, exclude)` still unconditionally
forwarded the bare, defaulted `exclude` straight to `message()`, and
two real 2-argument call sites exist: `obj/user.lpc`'s `user_dump()`
(the disconnect-timeout and idle-timeout auto-kick announcements) and
`adm/daemons/chard.lpc`'s corpse-decay heartbeat daemon (the "一阵风吹
过，把X化成骨灰吹散了" message). Both would have crashed uncaught the
first time either fired. **Fix**: `message("tell_room", str, ob,
exclude)` → `message("tell_room", str, ob, exclude || ({}))`, identical
pattern to `es1`/`es2`/`haiyang2`/etc. Verified live: cloned a throwaway
`/std/item`-based test object, called its own `test_2arg()`/
`test_3arg()` wrapper functions via the wizard `call` command post-fix
— both the 2-arg and 3-arg `tell_room()` forms completed with no crash
(`TESTMSG_2ARG_OK`/`TESTMSG_3ARG_OK` both printed); pre-fix the 2-arg
form would have thrown `*Bad argument 4 to EFUN message()`. Test object
deleted before commit. `include/compress_obj.h` (the sibling §7.14
bug from the same `es1` finding) does not exist anywhere in this
lib's tree — not applicable.

### ES2-family sibling sweep (2026-08-27): `wimpy` dbase-key mismatch found and fixed — same shape as `es2`'s finding

Following up on `es2`'s NOTES.md finding (its `cmds/usr/wimpy.lpc`
read/wrote dbase key `"wimpy"` while the only real consumer,
`std/char.lpc`'s `heart_beat()` auto-flee check, read `"env/wimpy"`
instead — a silent, permanent no-op for the player-facing `wimpy`
command), checked this direct ES2-lineage sibling and found the exact
same bug. `cmds/usr/wimpy.lpc` read/wrote `me->query("wimpy")` /
`me->set("wimpy", wmp)` (no `env/` prefix), while `std/char.lpc`'s
`heart_beat()` reads `wimpy_ratio = (int)query("env/wimpy")` for its
HP-based auto-flee check, and this lib's own NPC templates
(`obj/example/ghost.lpc`, `obj/example/drooler.lpc`) already correctly
set `"env/wimpy"` in their own `create()`. Fixed identically to `es2`:
changed both the read and write in `wimpy.lpc` to use `"env/wimpy"`.
Live-verified: booted the driver, logged in as the seeded `fluffos`
admin account, ran `wimpy 30`, and confirmed the resulting save file
persists `"env":(["wimpy":30,])` under the player's dbase — matching
exactly what `heart_beat()` reads, where pre-fix it would have written
to a top-level `"wimpy"` key nothing ever consumed. (Two other files —
`open/test/npc/0.lpc`/`open/sky/npc/0.lpc` setting `"wimpy",0` on
throwaway test NPCs, and `cmds/min/set_mob.lpc`'s admin diagnostic
display of `dbase["wimpy"]` — also reference the bare key, but neither
is a functional consumer of the player auto-flee setting, so left
untouched.) Checked the sibling ES-family libs `haiyang2`, `xkx2001`,
`bmxkx2001`, `rzrmud`, `xo`/`xo_final`, `zhyx`, and `naruto` for the
same shape: all clean (setter and getter already agree on the same
key, or — `xo`/`xo_final`'s generic `set wimpy N` command and
`naruto`'s per-stat `set_stat_notify`/`query_stat_notify` mechanism —
use a different, internally-consistent implementation shape entirely).
`demonangel` was the only lib in the family carrying the bug.
