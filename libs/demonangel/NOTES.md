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
