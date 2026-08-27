# es1 — 东方故事(蓝天) (git clone from MudRen/es)

Source: `git clone https://github.com/MudRen/es` (commit `4c2177e513c9f2e57fbcca3a9239e6a5096a6b7d`,
cloned 2026-08-26). Port: 40239. Status: **done** (boots clean, full
registration verified end-to-end with an English login name and full
race/gender character-creation flow, `look`/`score`/`who`/`say`/relogin/
`quit` all confirmed working, admin `update` ACL confirmed).

## What this is

This is the original "ES1" engine -- the direct ancestor of this
project's already-onboarded `es2`/`haiyang2`/`demonangel`/`xkx2001`/
`rzrmud`/`xo` "ES2 family". `README.md` in the raw archive says only
"使用FluffOS v2017驱动，游戏管理员账号：admin|mudren" (admin account
admin/mudren); the shipped prebuilt binary is named `mudos.exe`
(a Windows MudOS build, not FluffOS -- "FluffOS v2017" in the README
refers to a *later* fork's driver, not what originally shipped here).
`config.cfg`'s `name` field decodes (GB18030) to `东方故事(蓝天)`
("Eastern Story (Blue Sky)"), and its `default fail message` decodes
to the classic ES-family `什麽？`.

Despite the wuxia-sounding mud name, this is a Western D&D-style
fantasy world, not a jianghu/wuxia setting: registration is
English-login-name-only, and `adm/simul_efun/chinese.lpc` /
`adm/daemons/logind.lpc` have **no `is_chinese()`/`check_legal_name()`
machinery at all** -- that whole §8.1 bug class (documented extensively
for es2/demonangel) simply doesn't exist yet in this snapshot, because
the feature it patches doesn't exist yet either. This, combined with
the total absence of `addn()` and 2-arg `query(prop,ob)` call sites
anywhere in the live tree (both greps came back empty outside one
already-dead file), confirms this archive really is an earlier
*generation* of the engine, not just a differently-reskinned sibling.

New characters pick from 16 races (human/elf/dwarf/orc/gnome/halfling/
lizardman/imp/daemon/centaur/drow/beholder/vampire/hawkman/
shapeshifter) and a gender, then land at `/d/adventurer/hall/adv_guild`
(冒险者公会, the Adventurer's Guild in "远风镇"/Farwind Town).

Layout mirrors the family: `adm/` (master/simul_efun/daemons), `cmds/`
(wiz/arch/imm/usr/std/open/file/object/... command dirs), `feature/`
(only `clean_up.lpc` survives here -- the rest of the later family's
mixin-class system, e.g. `action`/`attack`/`dbase`/`equip`/`move`/
`name`/`save`/`skill`/`team`, doesn't exist yet; this codebase instead
puts nearly everything directly in `std/body*.lpc`/`std/user.lpc`/
`std/npc*.lpc`), `std/` (body/living/user/npc class hierarchy, `adt/`
generic data-structure classes, `races/` per-race mixins, `weapon/`,
`board/`), `d/` (game-world domains: abyss, adventurer, deathland,
eastland, erosmia, god, healer, island, killer, knight, mage, magic,
martial, monk, moorth, noden, scholar, swordman, thief, translate,
wiz -- zero overlap with es2's domain list), `u/` (wizard workspaces).
`mudlib directory` is the repo root itself; `master file : /adm/obj/
master`, `simulated efun file : /adm/obj/simul_efun`.

## Comparison against es2 (sanity check per task brief)

Confirmed genuinely different content, not a duplicate of es2 or
anything else already onboarded:

- `d/` domain lists share **zero** names (es1: abyss/adventurer/
  deathland/eastland/erosmia/god/healer/island/killer/knight/mage/
  magic/martial/monk/moorth/noden/scholar/swordman/thief/translate/
  wiz; es2: canyon/choyin/chuenyu/city/class/death/force/goathill/
  graveyard/green/ice/jail/latemoon/oldpine/sanyen/skill/snow/
  social_guild/temple/village/waterfog).
- `feature/` in es1 has exactly one file (`clean_up.lpc`); es2's
  `feature/` has ~18 mixin classes. es1 predates that architecture.
- es2 requires a real Chinese character name at registration; es1
  is English-name-only with a full D&D race/gender character
  creation wizard es2 doesn't have at all.

**However**, es1 turned out to be near-identical to this project's
own already-onboarded `es1_win` (008, sourced from a separate
`es1_win.rar` archive, also named "东方故事(蓝天)"/"Eastern Story
(Blue Sky)" in its own meta.json) -- discovered only *after* the es2
comparison came back clean, so flagged here explicitly even though it
wasn't the comparison the task brief anticipated. A byte-level
diff (after normalizing es1_win's CRLF line endings) shows `d/`
domain lists, `feature/` (both just `clean_up.lpc`), and individual
files (e.g. `std/body.lpc`) are identical once line endings are
stripped. A broader whitespace-insensitive diff across all 6,927
`.c`/`.lpc` files common to both trees found 6,222 (89.8%) byte-for-
byte identical and only 702 (10.1%) genuinely differing in content --
overwhelming confirmation this is the same underlying codebase as
`es1_win`, just a different point-in-time snapshot (a live git
history here vs. a `.rar` archive there), not two independently
authored mudlibs that happen to share an engine. Per this project's
established precedent for this exact shape (`jyqxc`/`jyqxc2`, two
near-identical browser-download copies of the same archive, both
onboarded independently with `duplicate_of: null` and the relationship
documented in prose), this lib is onboarded as an independent entry
rather than folded into `es1_win`'s number, since the two are not
byte-identical and this git-history snapshot has a verifiable, citable
commit hash the `.rar` archive does not.

## Conversion (GBK→UTF-8)

`scripts/convert_lib.sh libs/es1/raw/es libs/es1/work` (default
GB18030 encoding -- confirmed correct via the config's `name` field
decoding cleanly). Results: 9,215 files scanned, 7,545 converted, 1,570
already UTF-8, 15 lossy (invalid-byte-dropped) files, 85 binaries
skipped. `.c`→`.lpc` renamed 6,929 files; 1,102 literal `.c"`
references fixed; 1 `#include <x.c>` angle-bracket reference fixed; 607
local `#include <x.lpc>` angle-bracket includes converted to quoted
form. Also removed the copied-in `.git/` directory from `work/` (an
artifact of `cp -r`ing the git-cloned raw checkout) -- not part of the
mudlib, and left the shipped `mudos.exe` binary and `.vscode/` project
folder in place untouched since nothing in the mudlib references them.

- **`static`→`nosave` string-literal collision** (AGENTS.md §4.3): the
  blanket `\bstatic\b`→`nosave` sed rewrote `log_file("static/...")`
  path literals in 5 files (same class as es2/demonangel) -- reverted
  `"nosave` back to `"static` in all of them. No `#define nosave
  static` compatibility-shim collision found.
- The 15 lossy-conversion files were spot-checked; all land inside
  comments/string literals of decades-old, already-garbled text and
  cost at most a character or two of cosmetic dialogue -- none broke
  compilation on their own (any compile failures touching these files
  trace to the driver-compat bugs below instead).

## Config / driver-compat fixes

`libs/es1/config.fluffos` modeled on the raw `config.cfg` (decoded
name/messages), pointed at `libs/es1/work`, port 40239; dropped the
directives this driver flags obsolete (`address server ip/port`,
`binary directory`, `swap file`, `reserved size`) and reduced
`maximum local variables` from the raw config's absurd (and clearly
already a no-op typo on the original driver) `50000000`-adjacent value
down to `200`, in line with the rest of this project's ES-family libs.

Followed this session's RAM-safety discipline throughout: compiled
`master.lpc`/`simul_efun.lpc`/`std/room.lpc`/`std/body.lpc`/`std/user.lpc`
and a handful of other widely-inherited base classes individually first
and got them clean before ever running a full `lpcc_check.sh` batch
sweep; watched the batch `lpcc --batch` process's RSS every ~15-20s for
each of the 5 sweeps run this session -- peaked around 1.2GB, nowhere
close to the ~10GB kill threshold.

1. **`adm/daemons/usage_d.lpc`'s `AVERAGING_NUM.0` macro-pasting
   trick** -- `#define AVERAGING_NUM 12` then `x / AVERAGING_NUM.0`
   relied on old-MudOS macro expansion re-lexing `12` immediately
   followed by a literal `.0` into a single float token; this driver's
   preprocessor doesn't re-lex after substitution, producing `syntax
   error, unexpected '.'` at all 4 call sites (plus a 5th cascading
   "Illegal LHS"). This file is loaded very early and widely enough
   that its own compile failure was blocking the RAM-safety pre-check
   of several other base classes (`std/user.lpc`, `std/living.lpc`,
   `std/npc.lpc`, etc. all transitively reference it) -- fixed first,
   before any batch sweep, per this session's own stated discipline.
   Fixed: `AVERAGING_NUM.0` → `(AVERAGING_NUM*1.0)` (4 sites).
2. **`std/npc2.lpc` declared a global variable (`nosave int
   hb_status;`) before its own `inherit LIVING;`** -- "Illegal to
   inherit after defining global variables." Reordered (inherit first).
   Five more files had the identical shape (global var, or an
   `#include` that itself declares file-scope globals, before their
   `inherit`): `d/eastland/beggar/monster/master.lpc`, `d/eastland/
   legend/monster/captain1.lpc`, `d/eastland/story/wiz/monster/
   wiz_elder1.lpc`, `d/noden/hawk/monster/pontiff.lpc`, `obj/tools/
   barney.lpc` (all: moved `inherit` above the offending declaration)
   and `d/mage/tower/monsters/patolas.lpc` (moved the `#include
   "detect-magic.h"` that carries the global array declarations to
   *after* its own `inherit MONSTER;`, matching the correct order
   already used by its sibling `d/mage/tower/obj/crystal_orb.lpc`).
3. **`adm/daemons/ref_d.lpc` used a local variable literally named
   `ref`** -- this driver reserves `ref` as a keyword (its native
   pass-by-reference parameter feature), so `string ref;` inside
   `resolv_ref()` produced `syntax error, unexpected L_REF` --
   cascading into ~120 downstream parse-recovery errors in the rest of
   the same (short, 83-line) file, since this daemon is inherited
   widely enough to appear as the "same root cause" in dozens of
   unrelated command files' failure traces. Renamed the local variable
   to `refstr` (3 sites) -- did not touch the file's own `"ref"`
   *string* property-name literal, which is unrelated data, not the
   colliding identifier.
4. **`class` used as a variable/parameter name in ~15 files** (a
   second reserved-keyword collision, same shape as fix #3 but for
   this driver's struct-like `class` feature) -- `void
   receive_message(string class, string msg)`,
   `void relay_message(string class, ...)`, `void set_guild(string
   class)`, local `string class;` declarations, etc., all producing
   `syntax error, unexpected L_CLASS`. Renamed the colliding
   identifier to `chr_class` (character-class, matching what these
   variables actually hold: knight/mage/healer/etc.) throughout each
   affected function, using a quote-aware substitution that left
   `->query("class")` string-literal lookups (a legitimate stored-
   property key, unrelated to the reserved word) untouched. Affected:
   `d/monk/guild.backup/monsters/saulin_monk.lpc`, `d/eastland/
   beggar/monster/donkey.lpc`, `d/eastland/liang_shan/monster/
   chi_yu/{knight,mage,healer}.lpc`, `d/eastland/liang_shan/monster/
   test2.lpc`, `u/b/boss/monk/inner_room{,1,2}.lpc`, `u/b/boss/god/
   guild/new_guild.lpc`, `u/c/creative/knight/force_room.lpc`, `u/s/
   sage/test/pet.lpc`, `u/s/snake/monster/healer.lpc`, `u/m/moon/
   user.lpc`, `u/m/moon/new_guild.lpc`.
5. **`std/object/ob_logic.lpc`'s `set_name()` had `varargs` on its
   forward-declared prototype but not on its real definition** --
   `varargs void set_name(string str, string c_str);` (line 22) vs.
   the actual `void set_name(string str, string c_str) { ... }`
   (line 135, missing `varargs`); this driver enforces the arity from
   the real definition, not the prototype, so every one-argument
   `set_name("foo")` call site (the overwhelming majority -- this
   codebase has no separate Chinese-name concept) failed with `Wrong
   number of arguments to 'set_name', expected: 2, minimum: 2, got:
   1`. The adjacent sibling function `varargs void set_short(string
   shortname, string c_short)` two lines below already has the correct
   shape, confirming this was a dropped keyword, not a deliberate
   arity change. Fixed by adding `varargs` to the real definition.
6. **The `std/room/room.lpc`→`replace_room.h`→`replace_program(ROOM)`
   redundant-self-replace pattern, AGENTS.md §7.100** -- every one of
   17 per-domain `replace_room.h` header files (plus 2 inline call
   sites, `d/noden/6,8.noden.lpc` and the in-game `u/s/sage/test/
   roommaker.lpc` room-generator's own code-template heredoc -- the
   exact "the bug lives in the factory" shape §7.100 also documents)
   contained a bare `replace_program(ROOM);`, called from `create()`
   in ~159 rooms across domains this file is `#include`d into, always
   immediately after (or as the last statement of) that room's own
   `inherit ROOM;`-derived `create()`. On the FluffOS build this
   project uses, this doesn't produce §7.100's originally-documented
   "closure-crash landmine" symptom -- instead it manifests as an
   immediate, deterministic runtime crash on the room's very first
   load: `*Nesting call_out(0) level limit exceeded: 1000`, thrown
   from `std/room.lpc`'s own `create()` → `call_out("reset", 0)` (line
   28) via the room's `create()` → `reset()` → replace_program()
   interaction on this driver. Root-caused via a minimal single-file
   `lpcc` test on `/d/eastland/tomb/square6` (the single largest
   affected bucket, 69 rooms) before touching anything else. Fixed by
   commenting out the `replace_program(ROOM);` line in all 17 shared
   `replace_room.h` files (one edit per file, each carrying an
   explanatory comment) and both inline call sites, rather than
   editing the ~159 individual room files that `#include` them --
   this is the same one-line-deletion fix §7.100 already validated as
   safe, just applied at the shared-header level this archive happens
   to centralize it at, making a full, reviewable fix tractable in one
   pass instead of the "future sweep backlog" punt §7.100's own
   closing note describes for a lib where the calls aren't
   centralized. Verified with individual `lpcc` re-tests (not just the
   batch sweep, see the caveat below) on 5 sample rooms spanning 3
   different previously-100%-failing domains (`d/eastland/tomb`,
   `d/eastland/liang_shan/lake`) -- all load clean post-fix.
7. **Content-tree-drift class (AGENTS.md §7's "sibling copy dropped a
   file"/"copied from another wizard's home dir without updating the
   include" shapes), ~50 files individually diagnosed and fixed** --
   mechanically similar to, but each individually verified rather than
   guessed, the following sub-patterns:
   - **Genuinely dropped local `#include`s**: 9 files under `d/noden/
     hawk/monster/` (`bird`, `bernice`, `boy`, `girl`, `man`, `older`,
     `older1`, `servant`, `woman`) had zero `#include`s despite bare
     `inherit MONSTER;`, while 30 sibling files in the same directory
     all correctly carry `#include <mudlib.h>` + `#include "../hawk.h"`
     -- restored the same two-line header. 27 more files across a
     dozen other directories (`cmds/{open,std}/_tune.lpc`, several
     `d/eastland/story/{,wiz/}armor/*.lpc`, `d/island/samurai/obj/
     dagger1.lpc`, `d/noden/drow/square{1,2}.lpc`, 7 `d/noden/hawk/
     armor/*.lpc`, 2 `d/noden/hawk/weapon/*.lpc`, `u/m/moon/cloth.lpc`,
     `u/s/snow/obj/{icy,shoe}.lpc`) matched the exact same shape
     (`inherit`-only file, no include, in a directory where the
     dominant/majority sibling pattern is a single `#include
     <mudlib.h>` or a two-line domain-header pair) -- restored via an
     automated per-directory sibling-header-majority-vote script,
     each result spot-checked before applying.
   - **`inherit` before its own domain `#include`** (2 files,
     `d/noden/hawk/monster/{crying,saw}.lpc`): reordered.
   - **Wrong relative-path depth**: `d/island/monster/{feller,
     old_feller}.lpc`'s `#include "../hole.h"` should have been
     `"../hole/hole.h"` (the header actually lives one directory
     deeper, at `d/island/hole/hole.h`) -- confirmed via `old_feller.
     lpc`'s own live (non-commented) use of `HOBJ"saw"`, a macro only
     `hole.h` defines, ruling out the alternative "doesn't need this
     header at all" fix. `d/eastland/liang_shan/obj/fish_plate.lpc`'s
     bare `#include "takeda.h"` (missing the `../` every other sibling
     in that directory uses) got the same one-token fix.
   - **Stray absolute path to a nonexistent/wrong wizard-home file,
     where the file doesn't actually need anything domain-specific**:
     `d/island/samurai/obj/{mercury_pen,weapon}.lpc` (`/u/t/takeda/
     takeda.h`, `/u/o/odin/odin.h` -- neither exists anywhere in the
     archive, and neither file references any macro either would have
     defined) → swapped to the dominant sibling convention, bare
     `#include <mudlib.h>`. Same fix for `d/translate/cwa/
     cut_tails.lpc` (`/u/m/maverick/maverick.h`), `d/scholar/scholar/
     stone1.lpc` (had no include at all), `u/m/moon/ftpd.lpc` (ditto),
     `d/monk/gonfus/test/fon-mo.lpc` + `u/c/creative/fo-mo.lpc`
     (`/u/w/wind/wind.h`, a copy-pasted "gonfu skill" template shared
     between two wizards' homes), and 7 files under `d/scholar/
     demand/where/` (`cave31`, `fire_beast`, `fire_elephant`, `ohio`,
     `pawnbroker`, `princess`, `sky_guilt`) which each `#include`d a
     *different*, unrelated other domain's header (`layuter.h`,
     `goomay.h`, `saulin_temple.h`, `oldcat.h`, `almuhara.h`) despite
     using none of those headers' macros -- confirmed via grep before
     touching each one, then swapped all 7 to `<mudlib.h>`.
   - **Stray absolute path where the *correct* file exists elsewhere
     in the archive, unambiguously**: `d/god/cmds/_god.lpc` + `u/b/
     boss/god/cmds/_god.lpc` + `d/killer/cmds/_killer.lpc` (missing
     `#include <mudlib.h>` for the `DAEMON` macro their `inherit
     DAEMON;` needs -- diff-confirmed near-identical to each other,
     all three missing the exact same line); `d/god/cmds/_god.lpc`'s
     own `"../god.h"` needed `d/god/guild/god.h` to exist (it was
     missing -- restored by copying the byte-identical `d/god/god.h`,
     confirmed identical to `u/b/boss/god/{,guild/}god.h`, into place);
     `d/noden/hawk/monster/{elder,god,god1}.lpc`'s `"/u/s/smore/
     hawk.h"` (nonexistent) → `"../hawk.h"` (the real, local header
     every other sibling in that directory uses); `u/s/sage/guild/
     killer_guild.lpc`'s `"../killer.h"` → `"killer.h"` (the real file
     is in the *same* directory, not the parent); `u/b/boss/sword.lpc`'s
     `"../moon.h"` → `"moon.h"` (ditto, same-directory not parent);
     `u/c/creative/weapon/sword.lpc`'s `"../moon.h"` (doesn't exist
     under `u/c/`) → the absolute `"/u/m/moon/moon.h"` (byte-identical
     content to `u/b/boss/moon.h`, confirmed via diff, and this file
     genuinely needs its `ARM` macro); `d/noden/mj/{emsd,monster/
     ronardo}.lpc`'s `"../lilia.h"` (nonexistent) → the local `mj.h`
     that already exists in `d/noden/mj/` and is byte-identical to
     `d/noden/ruin/lilia.h` (confirmed via diff -- `mj/` is evidently
     the same zone as `ruin/`, just renamed, with the header copied
     over but not the two `.lpc` files that still referenced the old
     name); `u/m/mnb/wenro5.lpc`'s `"../lilia.h"` → `"lilia.h"`
     (the real file, `u/m/mnb/lilia.h`, is in the same directory).
8. **`std/board/archive.lpc` had no `#include` at all**, needing
   `SAVE_EXTENSION` (from `<config.h>`) for its board-archive-file
   suffix check -- confirmed reachable (`d/wiz/archiverm.lpc`, a live
   `d/` domain file, inherits it). Added `#include <config.h>`.
9. **`cmds/{open,file}/_tail.lpc` and `cmds/wiz/_log.lpc` called a
   bare `tail()` efun** that was never real on MudOS/FluffOS (same
   class as es2/demonangel's identical fix) -- reimplemented locally
   in all 3 files with `read_file()`+`explode()`+`implode()` (last 20
   lines), plus a forward declaration in each (this driver needs one
   for same-file forward references, same as fixes documented in the
   sibling libs' own NOTES.md).

## Not fixed (pre-existing content gaps / dead code, confirmed via `raw/`)

- **`adm/daemons/network/` (13 files: `cmwhod`, `dns_master`, `fg`,
  `fs`, `ftpd`, `inetd`, `inter_chan`, `netmail`, `pingd`, `rwho`,
  `telnetd`, `ts`, `userid`, plus `services/`)** -- the same
  incomplete Intermud-style subsystem already documented as dead in
  `es2`/`demonangel`. Both entry points a real boot could reach
  (`ftpd`, `dns_master`) are commented out of `adm/etc/preload`;
  `preload` only ever loads `emoted`/`event`/`logind`/`usage_d`/
  `weather_d`/`channels`/`statsd`/`chinese_d`. Confirmed **zero
  outbound network connections** at boot or during the compile sweep
  -- safe for an automated reboot loop. `netmail.lpc`'s bare
  `SAVE_EXTENSION` reference (undefined, since it never gets
  `<config.h>`) was left as-is since the file is unreachable.
- **`u/s/sage/test/dragon.lpc`**: a wizard's personal "test" scratch
  file containing what reads as two separate, unrelated NPC bodies
  concatenated end-to-end (the first ends mid-file around line 154;
  a second, complete `back_dragon.c`-headed NPC begins immediately
  after with its own `#include`/`inherit MONSTER;`/`inherit MOUNT;`/
  `create()`), producing a "Redeclaration of function 'create'"-class
  cascade. Unreferenced by anything else in the tree -- dead/orphaned
  scratch content, not fabricated content to "fix" by guessing which
  half was meant to survive.
- **`std/adt/body.lpc`**: an unreferenced, orphaned duplicate of the
  real `std/body.lpc` living under the generic `std/adt/` (data-
  structure) directory instead -- its second, redundant `inherit
  "/std/body/attack.lpc";` etc. chain collides with functions already
  made `nomask` by its first `inherit OBJECT;`, producing "Illegal to
  redefine 'nomask' function" errors for `query`/`set`/`query_temp`/
  `_query`/`_set`/`_delete`. Not inherited or referenced by anything
  in the live tree -- dead scaffolding.
- **`d/monk/gonfus/test/fon-mo.lpc`** (and its `u/c/creative/fo-mo.lpc`
  copy, both explicitly under a "test"/"creative" scratch directory):
  reference a bare `C_NAME` macro that is not defined anywhere in this
  archive (the only similarly-named macro, `PROTECT_C_NAME`, is
  unrelated) -- presumably intended as shorthand for `this_player()->
  query("c_name")`, but no such macro was ever shipped. Left as-is
  per AGENTS.md's "don't fabricate content" boundary (the correct
  binding -- always `this_player()`, or something call-site-specific
  -- isn't unambiguous from the surrounding code).
- **`d/island/samurai/room/d04.lpc`**: confirmed via `diff` to be a
  byte-for-byte orphaned duplicate of the real, correctly-placed
  `d/deathland/mine/d04.lpc` (same room, same `Mine"..."`/`Monster
  "..."` macro-qualified exits and NPC spawns, referencing the
  `d/deathland` domain's own `echobomber.h`, which doesn't exist
  anywhere under `d/island/samurai/`). Unreferenced by anything else
  in the tree (grepped) -- a genuine stray leftover copy, not
  something to "fix" by inventing a local header for it.
- **`u/s/sage/test/roommaker.lpc`**: this file's `do_saveroom()`
  function (starting around line 302) is genuinely, severely corrupted
  in the raw archive itself (confirmed byte-identical corruption in
  `raw/`, not a conversion artifact) -- dozens of consecutive
  statements are missing their terminating semicolons and one `while`
  loop is missing its closing paren, well beyond a simple typo-fix
  scope. This in-game room-building tool was never going to compile
  regardless of anything else; the isolated, already-validated
  §7.100 `replace_program(ROOM)` fix (see fix #6 above) was still
  applied to its "new room" code-generation template for hygiene
  (so any future repair of this file, or manual copy-paste from its
  template, doesn't reintroduce the bug), but the rest of the
  function's corruption was left untouched.
- **`F_UNIQUE`/`F_MERCENARY`-shaped gaps**: not checked exhaustively
  given this codebase's `feature/` directory barely exists (see
  "What this is" above) -- this bug class is specific to the later
  ES2-family mixin architecture and doesn't really apply here.

## Interactive test result — full registration + relogin flow

Registration shape (English-only, no Chinese-name step): login name
(a-z, ≤12 chars) → confirm new-character (y/n) → Chinese display name
(optional, blank defaults to the capitalized English name -- note this
prompt exists in the code but nothing downstream actually requires a
real Chinese name, unlike es2/demonangel) → password (≥5 chars,
entered twice) → gender (m/f/n) → race (English race name, or
`? <race>` for a help blurb) → email (`user@host` or `$` for none) →
real name (optional) → lands in `/d/adventurer/hall/adv_guild`
(冒险者公会, Farwind Town's Adventurer's Guild).

Verified live with a raw Python socket test script end-to-end:

- **Registration** as `fluffos`/`Mud@2026`, human, male: `look` after
  landing showed the full room description (远风镇的冒险者公会,
  stairs/exits/board/NPC 亚默长老/Yamor), `score` showed a fully
  populated character sheet (race/gender/age line, six attributes,
  体力/精神力/交谈力 bars, experience, alignment), correctly starting
  with zero money.
- **`who`** showed the "东方故事(蓝天)" mud-name banner and the single
  connected user; **`say hello world`** produced the correct
  self-echo (`你说道：hello world`).
- **Relogin**: reconnecting with the same id/password logged back in
  cleanly (no re-registration prompt, "上次连线时间" showing the
  correct previous-session timestamp), confirming both save files
  (`data/std/connection/f/fluffos.o`, `data/std/user_ob/human/f/
  fluffos.o`) were written correctly on the first `quit`.
- **`quit`** produced the expected `畅玩 ES 之余, 念一点书吧!...拜拜`
  farewell with zero runtime errors in `debug.log` across the whole
  session (only the expected lazy-compile "Unused local variable"
  warnings).
- No `whoami` command exists in this codebase at all (grepped
  `cmds/`) -- not a bug, just a different, smaller default command set
  than the sibling ES2-family libs.

## Admin account

`fluffos` / `Mud@2026`. This codebase's admin mechanism predates
`securityd.lpc`'s `wizlist`-file approach used by es2/demonangel
entirely -- it doesn't exist here. Instead, `adm/obj/master/groups.lpc`
loads a plain-text `/adm/etc/groups` file at boot, defining nested
groups by colon-separated member lists (`(root) :mudren:admin`,
`(admin) (root) :admin`, `(arch) (admin)`, `(sage) (arch)`,
`(wiz) (sage)`). Added `fluffos` to the `(root)` group's member list
(`(root) :mudren:admin:fluffos`), then registered `fluffos` through
the normal flow. Verified via the canonical read+compile ACL check
(AGENTS.md §1.5): `update /adm/obj/master` succeeded ("Updated and
loaded.") with no permission error. Note: the login banner's cosmetic
"目前权限：" line reads from a *different*, unrelated mechanism
(`DOMAIN_D->query_domain_level()`, a domain-builder-list lookup) and
still shows "player" for this account -- this is a separate, purely
cosmetic display and does not reflect actual write/compile permission,
which is confirmed working via the `update` test above.

## Batch-sweep artifact caveat (important for reading `lpcc_fail.log`)

The final `lpcc_check.sh` batch sweep in this lib's `lpcc_fail.log`
reports 943/6,929 failures (86.4% pass), but this **understates** the
true fix rate: after applying fix #6 (the §7.100 `replace_program`
sweep, ~159 affected rooms across a dozen domains), the raw batch
number did not move at all, even though individually re-testing 5
sample rooms from the previously-100%-failing `d/eastland/tomb` and
`d/eastland/liang_shan/lake` buckets with a *fresh, isolated* `lpcc`
invocation showed all 5 loading clean with zero errors. This matches
this project's own documented "lpcc sweep eval-cost artifact" gotcha:
`lpcc --batch` runs every file through a single, long-lived VM process
rather than a fresh boot per file, and something in that shared
process's call_out/eval-cost accounting appears to accumulate across
thousands of sequential object loads, producing spurious repeats of
the exact same `Nesting call_out(0) level limit exceeded` signature
for objects that are actually fine in isolation. The real driver
boot test above (a fresh process, not the batch tool) is the
trustworthy signal for whether the fix works, and it does. The
remaining ~943-row failure list should be read as a conservative
upper bound including this batch-mode noise, not a precise count of
genuinely-broken files; most of the individually-diagnosed content-
tree-drift items in the "Not fixed" section above were confirmed via
single-file `lpcc` runs specifically because of this caveat.
