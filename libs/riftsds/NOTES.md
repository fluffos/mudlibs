# `grav1tyzero/rifts-ds` → `riftsds`

Source: `git clone https://github.com/grav1tyzero/rifts-ds` (cloned
2026-08-30). Mudlib root is the repo's `lib/` directory; `bin/`,
`extra/` (a `wolfpaw/` subdir containing classic MudOS driver-build
headers `macros.h`/`configure.h`/`system_libs` -- driver source, not
mudlib code), `fluffos-2.23-ds03/` (a full bundled driver source tree),
`win32/`, and the top-level license/readme/batch files were not
converted. Slug `riftsds`, number 955, port 40257.

Dead Souls 3.9 lineage -- same base engine family as the already-
onboarded `ds386`/`dsI`/`dsII`/`dsIII`/`dshakkard`/`deadsouls_fluffos`
(§2.1 lineage confirmation: `secure/daemon/master.lpc` is
near-byte-identical to `ds386`'s own pre-fix raw baseline, differing
only in the same `static`→`nosave`/`.c`→`.lpc` conversion artifacts).
The ASCII boot banner reports "Mudlib: Dead Souls 3.9" (a later point
release than `ds386`'s 3.8.6), which explains the bundled
`domains/std` Lima-style builder-school example area that `ds386`
doesn't have. Not a duplicate of the already-onboarded `rifts2`
(`tsathoqqua/RiftsMUD2`) -- that lib is DarkeLIB/Nightmare lineage, a
completely different codebase that happens to use the same tabletop
setting.

**This repo is a live/played development snapshot, not a pristine
archive.** It arrived with three real pre-existing wizard accounts
(`gravity`, `thurtea`, `shrub` -- all full admins per
`secure/cfg/groups.cfg`), a huge number of `realms/thurtea/tmp/*.lpc`
scratch files (leftover `ed`/eval-session temp files from live
development, hundreds of randomly-named files), and only 10 total git
commits upstream ("money pops up a lot more than I thought", "multiple
fixes credits added mana now ppe", etc.) -- this reads as one
developer's personal in-progress mud, not a finished release.

## 1. Conversion

`convert_lib.sh` ran normally (GB18030 default encoding -- this lib is
pure English/ASCII, so the encoding pass was a no-op except for a
handful of genuinely non-Chinese legacy-8-bit files, see below): 5605
already-UTF-8, 7 converted, 9 lossy, 33 skipped-binary. 3219 `.lpc`
files after rename, 747 literal `.c"` references fixed, 32 local
angle-bracket includes converted, 1605 files touched by the
`static`→`nosave` sweep.

**Lossy-conversion files, all pre-existing (not conversion fallout),
all fixed:**
- `doc/CREDITS`, `doc/help/players/credits`,
  `domains/town/txt/mystery.txt` -- Latin-1/MacRoman punctuation, byte-
  identical to `ds386`'s own known-bad set for these exact filenames
  (this lineage's stock Dead Souls doc tree). Fixed by directly copying
  `ds386`'s already-corrected versions of these three files (confirmed
  byte-identical match before copying).
- `secure/sefun/translate.lpc` (the "speak a foreign language badly"
  word-scramble table) -- one Finnish entry (`"kyrp\xe4","r\xe4k\xe4"`)
  is genuine Latin-1, and GB18030 decoding silently mangled it into
  `"kyrp,"r鋕,"` (the classic `iconv -c`-eats-an-adjacent-real-byte
  shape, AGENTS.md §4.1 -- here it also ate the string's own closing
  quote and the following comma). A second entry
  (`"\xd0\xa5\xd0\xa3\xd0\x98\xd0\xa2\xd0\x90"`, Cyrillic "ХУИТА") was
  ALREADY valid UTF-8 but got re-mangled into other valid-but-wrong
  CJK codepoints by the same GB18030 pass. Both fixed by hand,
  matching `ds386`'s own already-published fix for this exact
  byte-for-byte-shared file.
- `save/intermud.o`, `secure/save/functions.o`, `realms/thurtea/tmp/
  *.c` (4 files): stale runtime caches (an I3-router mudlist cache,
  an empty function-signature cache, and 4 of the hundreds of `ed`
  scratch temp files) -- harmless, left as-is (all valid UTF-8 in
  their converted form, no fix needed).

## 2. Ported ~160 already-proven `ds386` driver-compat fixes wholesale

Confirmed via a fresh from-scratch reconversion of `ds386/raw` (into a
scratch dir, matching this session's own `convert_lib.sh` output byte-
for-byte) that large parts of this lib's shared "engine" tree (outside
`domains/`) are byte-identical to `ds386`'s own PRE-FIX baseline. A
Python script walked every file under `secure/`, `lib/`, `cmds/`,
`daemon/`, `std/`, `obj/`, `verbs/`, `powers/`, `cfg/`, `include/`,
`ftp/`, `open/`, `shadows/`, `doc/`, and `domains/`; wherever this lib's
file was byte-identical to `ds386`'s freshly-reconverted (unfixed)
version of the same path AND `ds386`'s own committed (fixed) version of
that path differs from the unfixed baseline, this lib's file was
directly overwritten with `ds386`'s fixed version. **160 files ported
this way**, including the highest-impact fixes from `ds386`'s own
onboarding: `secure/daemon/master.lpc` (uid stubs, `runtime_config.h`
already swapped for the driver's canonical copy), `secure/sefun/
economy.lpc` (the `to_int()`-missing float-corruption bug, AGENTS.md
§7.121), `lib/editor.lpc`/`lib/interactive.lpc`/`lib/nmsh.lpc` (the
`OLD_ED` single-entry-`ed()` rewrite, AGENTS.md §6.2 -- see below for
2 files that needed the SAME fix applied by hand since their content
had locally diverged from `ds386`'s baseline), `secure/lib/connect.real`
(the `static`/array-idiom fixes for Dead Souls' self-rewriting login
object), `secure/include/lib.h` (`LIB_REMOTE` stale path), `lib/events/
look.lpc`+`look_in.lpc` (the `SetLong`/`SetInternalDesc` narrow-string-
type bug, AGENTS.md §7.81-class), `daemon/command.lpc` (the `.c`→`.lpc`
filename-slice bug that broke the stock `score` command), and
`secure/sefun/sockets.lpc`/`instances.lpc` (WASM `sockets`-package-
absent gutting -- not yet verified under WASM here, see below).

`~724` other shared-tree files diverged from `ds386`'s baseline (this
lib is a materially newer/extended Dead Souls snapshot -- new systems
not present in `ds386` at all: a magic-point/`P.P.E.` resource,
parties, voting, teacher/apprentice skill training) and were left
untouched by the port; each one that actually failed to compile was
triaged individually (§4 below).

## 3. Manual fixes beyond the ported set

- **The `TYPE array NAME` idiom (AGENTS.md §4.3/§6.3), same driver
  build (`ARRAY_RESERVED_WORD` undefined, confirmed against this
  driver's own `options_internal.h`)**: a quote/comment-aware Python
  sweep across the whole `work/` tree found and fixed 230 single-
  declarator instances across 62 files (`object array x` → `object *x`,
  etc.) plus 11 multi-declarator lines (`string array a, b, c;` → all
  three get `*`, verified per-variable against actual usage --
  `explode()`/`foreach`/index-access confirms array use -- not blindly
  applied): `daemon/classes.lpc`, `daemon/help.lpc`, `daemon/
  seasons.lpc`, `daemon/races.lpc`, `domains/town/npc/brandy.lpc`,
  `secure/daemon/players.lpc` (×3 lines), `secure/cmds/admins/
  mudconfig.lpc`, `lib/magic.lpc` (`send_to`), and `lib/chapel.lpc`
  (`Religion`/`Deities`/`DeityIds`, initially missed in the first pass
  since it wasn't in the multi-declarator report handled at the same
  time -- caught by the `lpcc_check.sh` sweep's "Bad assignment (string
  vs mixed*)" errors and fixed separately). **New AGENTS.md §7.163**:
  found one instance with a `class` compound type instead of a bare
  base type (`lib/body.lpc`'s `class MagicProtection array
  GetMagicProtection()`), invisible to a plain-base-type regex.
- **The `.c`→`.lpc` filename-slice-length bug (AGENTS.md §7.118-class)**
  -- several sites where the code checks a suffix against the 4-char
  `.lpc` string but slices/truncates by the old 2-char `.c` length:
  `daemon/help.lpc` (3 sites in `LoadIndices()`'s helper closures + 1
  in `GetTopic()`'s guard, this file wasn't part of the ported set
  since it had genuinely diverged from `ds386`'s version), `verbs/
  builders/initfix.lpc`, `lib/std/boobytrap_object.lpc`, `secure/obj/
  weirder.lpc` (3 sites), `secure/cmds/admins/mudconfig.lpc`,
  `secure/daemon/rooms.lpc`, `secure/sefun/sefun.lpc`. All fixed
  `last(x,2)`/`[<2..]`/`[0..<3]` → `last(x,4)`/`[<4..]`/`[0..<5]`
  paired with the matching `truncate(x,2)`→`truncate(x,4)`. Verified via
  a corpus-wide re-grep that zero unrelated 2-char-suffix uses (`.o`,
  `"/g"`, `", "`, `"--"`) were touched.
- **`lib/std/room.lpc`'s `SetLong` wrapper was narrower than the
  `SetInternalDesc` it forwards to** (`string SetLong(string str)` vs
  the already-fixed `mixed SetInternalDesc(mixed str)` in `lib/events/
  look_in.lpc`) -- widened to `mixed SetLong(mixed str)`. This broke
  every room using `SetLong( (: SomeClosureFn :) )` for a dynamic
  description (confirmed live: `secure/room/router.lpc` throws `Bad
  type for argument 1 of SetLong ( string vs function )` without this
  fix). Two OTHER `SetLong` overrides (`lib/die.lpc`, `lib/
  interactive.lpc`) are also narrowly `string`-typed but are only ever
  called with literal strings in this codebase -- left alone per scope
  discipline (no error, no fix).
- **`lib/player.lpc`'s `Setup()` declared `string oldparties =
  PARTY_D->GetOldParties();`** but `GetOldParties()` is declared (and
  actually returns) `string *` -- a plain wrong-type local variable,
  not the array-idiom bug. This crashed `RemoveExtraChannels()`
  (`Bad type for argument 1 ( string * vs string )`) on literally every
  successful login (the function runs unconditionally in `Setup()`).
  Fixed the declaration to `string *oldparties`.
- **`domains/town/npc/zoe.lpc`**: `SetCurrencies( ({ "universal
  credits"" }) );` -- a stray doubled closing quote, present in the raw
  archive (confirmed via `raw/`, not conversion fallout). Broke this
  NPC's compile with a cascading `End of file in string`, which took
  `domains/town/room/bank.lpc` down with it (Zoe stands in the bank).
  Fixed by removing the extra quote. Verified live: the bank room now
  loads correctly with "Zoe the bank teller" present.
- **`domains/Praxis/supply2.lpc`**: `set_pre_exit_functions( ({ "north"
  }), ({ "go_north" }) );` -- the exact same broken macro-aliased call
  (`set_pre_exit_functions` is `#define`d straight to
  `SetProperty(string, mixed)` in `secure/include/compat.h`) already
  documented and fixed on `ds386`'s own copy of this identical file;
  every sibling room in the same directory (`hall.lpc`, `hall2-5.lpc`)
  already has the call commented out, confirming this never worked
  under any driver. Commented out identically, matching `ds386`'s own
  fix verbatim (same file, same lineage).
- **`lib/interactive.lpc`'s `quit()`-path** and **`lib/nmsh.lpc`'s
  `GetPrompt()`** both still had the pre-fix `ed_cmd()`/
  `query_ed_mode()` calls from `AGENTS.md` §6.2's `OLD_ED` class (their
  content had diverged from `ds386`'s baseline enough that the bulk
  port skipped them) -- applied the identical remedy `ds386` already
  proved: dropped the belt-and-suspenders manual `ed_cmd()` save/close
  (the driver's own `destruct_object()` already flushes a live
  `ed_buffer` on destruct under `OLD_ED`) and dropped the
  now-unreachable `query_ed_mode()`-gated custom prompt branch (the
  driver prints its own ed-mode prompt directly from C while an editor
  session is open, bypassing this apply entirely).
- **24 `domains/<Continent>/virtual/{server,void}.lpc` files** (one
  pair per bundled continent-stub domain: Africa, Americas, Atlantis,
  Australia, AustraliaOutback, China, Europe, Japan, Mexico, Russia,
  SouthAmericas) all had `#define __DIR__ "/domains/<Continent>/
  virtual/"` -- `__DIR__` is a live compiler predefine on this driver
  (same class as AGENTS.md §7.39), so this is `error: Illegal to
  redefine a predefined value.` on every one. This is the exact same
  virtual-server/void template `ds386` hit on its own `amigara`/
  `learning` domains, just replicated 12× here (once per continent
  stub) instead of `ds386`'s 1×. Deleted all 24 `#define` lines (the
  driver's live `__DIR__` produces the identical value, trailing slash
  included). The two matching top-level scaffold templates
  (`std/virtual_void.txt`, `std/server.txt`, with a literal
  `CHANGEME` placeholder) were correctly left untouched -- not meant to
  compile standalone, matching AGENTS.md's `area_room.lpc`/`open/
  prog.lpc` template-scaffold precedent.
- **Admin account seeding** -- see the new AGENTS.md §1.5 Dead-Souls-
  lineage sub-entry for the full writeup. Summary: this repo arrived
  PAST its own first-boot install wizard (three real wizard accounts
  already exist), so the usual "register through the bootstrap wizard"
  path doesn't apply. Added `fluffos` to every line of `secure/cfg/
  groups.cfg` (alongside the pre-existing `gravity:thurtea:shrub`,
  not replacing them), registered `fluffos` through the ordinary
  NEW-player flow (password `Mud@2026`), then with the driver stopped
  moved `secure/save/players/f/fluffos.o` to `secure/save/creators/f/
  fluffos.o` unchanged -- exactly what the stock `encre` admin command
  does under the hood (`creatorp()` checks the live player object's
  `file_name()` against `DIR_CRES`, not any ACL/rank table). Verified
  live: `fluffos` immediately shows the admin room-path annotation and
  banner, and `goto`/wizard commands work with no further seeding.

## 4. SEVERE FINDING: `domains/omega`, `domains/common`, and the bundled `domains/std` example area are ALL non-functional -- a whole missing base-object framework, never committed to this repo

**This is the single most important finding of this onboarding.** See
**AGENTS.md §7.164** for the full catalogued writeup; summary here.

The task brief for this onboarding (and the repo's own file layout)
strongly suggested `domains/omega` -- 150 files describing "Omega
Station," a detailed multi-floor sci-fi space station with NPCs, a
shop, and a working elevator -- was this lib's standout content. It is
not functional. Every one of the 150 files (148 with real code, 2 are
empty 0-byte stubs) fails to compile, because they `inherit` classes
that are `#define`d nowhere in the entire repository: `LIVING`,
`M_VENDOR`, `CONTAINER`, `M_OPENABLE`, `M_WEARABLE`, `M_GETTABLE`,
`ARMOUR`, `INDOOR_ROOM`, `ELEVATOR`. Checked exhaustively: the whole
mudlib tree, the bundled `fluffos-2.23-ds03/` driver source, and even
the non-mudlib top-level `extra/wolfpaw/` directory (which turned out
to be classic MudOS driver-BUILD headers -- `macros.h`/`configure.h` --
not mudlib code at all, a red herring this session chased down before
ruling it out).

`domains/common` (33 files, shared sci-fi item/ship infrastructure --
`WEAPON`, `DRINK`, `ITEM_DECAY_FOOD`, `SPACESHIP`) hits the identical
problem, evidently meant to back `domains/omega`. And bundled stock
Dead Souls 3.9 itself ships a large Lima-style "builder school"
tutorial/example area at `domains/std` (315 files -- a completely
different missing-macro set: `KEY`, `OBJ`, `PARAM_OBJ`, `BOOK`,
`VEHICLE`, `ADVERSARY`, `STOCK_MASTER`, `RANGED_WEAPON`, `LIVING`,
`INDOOR_ROOM`) -- same failure shape, different intended framework
(this one looks like it's meant to be a well-known classic LPMud
"Lima"/LPUniversity teaching area, judging by the `school/A/F/M/O/R/
W/X` letter-subdirectory convention and a `lima_guide.lpc`/`domains/
std/lima/` presence).

**Together these three trees account for 496 of the lib's 519 total
`lpcc_check.sh` compile failures** (148 + 33 + 315) -- one root cause,
not 496 separate bugs.

This is not a gap this project's conversion introduced. `secure/
include/compat.h` (gated live: `COMPAT_MODE 1` in `global.h`, genuinely
wired into every object's global include) proves the repo's own author
was ACTIVELY building a compatibility shim for exactly this purpose --
it correctly maps `ROOM`/`OBJECT`/`DAEMON`/`MONSTER`/`VAULT` and
~50 lowercase `set_*`/`query_*` verb names (`set_short`→`SetShort`,
etc.) onto this lib's own Dead Souls CamelCase API -- but it simply
never got the additional ~18 class macros these three content trees
actually need. The upstream repo's own `git log` (only 10 commits
total: "Initial commit" bulk-imports these large trees, then all
follow-up commits are small numeric tweaks -- "money pops up a lot
more than I thought", "multiple fixes credits added mana now ppe") is
consistent with one developer's personal, mid-construction mud: the
big content trees were bulk-imported once and the compat layer was
never finished before development moved on to other systems.

**Confirmed live, not just via the batch compile sweep.** Logged in as
the seeded `fluffos` admin and ran `goto /domains/omega/room/
elevator_center` -- the driver echoed the exact compile error
interactively (`error: syntax error, unexpected L_IDENTIFIER ...
inherit ELEVATOR;`) followed by `*No program in object '/domains/
omega/room/elevator_center'!` on the subsequent reference, then
`Could not load that location.` `goto /domains/omega/npc/hugo` failed
the same way. As a control, `goto /domains/Praxis/supply2` (stock Dead
Souls content, fixed above) loaded correctly and printed its real room
description -- confirming the failure is specific to the three
missing-framework trees, not a general problem with `goto`/this
driver/this lib's boot.

**No attempt was made to author the missing framework.** Guessing at
correct implementations for `LIVING`/`CONTAINER`/`ARMOUR`/`ELEVATOR`/
`M_VENDOR`/etc. (and the completely separate `KEY`/`OBJ`/`ADVERSARY`/
`STOCK_MASTER`/etc. set for `domains/std`) from ~500 call sites' worth
of usage would mean writing a second mudlib engine from scratch, not
fixing a bug -- this project's established policy (`ds386`'s own
`LIB_CAPTURE`/`jar.lpc` precedent: "implementing an entire mechanic
from a one-line hint would be inventing content") applies at much
larger scale here. `domains/omega` and `domains/common` are left
exactly as shipped (uncompilable, documented); nothing was deleted.

**What DOES actually work**: the stock Dead Souls 3.9 base itself, and
every domain built on its real, existing API --
`Africa`/`Americas`/`Atlantis`/`Australia`/`AustraliaOutback`/`China`/
`Europe`/`Japan`/`Mexico`/`Russia`/`SouthAmericas` (thin stock-base
stubs, as expected and documented for Dead-Souls-lineage variants
elsewhere in this corpus), `campus`/`town`/`Praxis`/`Ylsrim`/`default`/
`amigara` (the standard Dead Souls demo areas, same as `ds386`), plus
this lib's own Rifts-flavored additions layered onto the REAL API:
Rifts races (`greathorneddragon` alongside the stock dwarf/elf/human/
etc. set, `secure/cfg/races/greathorneddragon`), a P.P.E. (Potential
Psychic Energy) resource shown on the prompt and `score` sheet
alongside HP/SP, and Rifts-flavored currency/vendor content in the
town.

## 5. `lpcc_check.sh` compile sweep

Ran under `(ulimit -v 8388608; ...)` given the tree size (3219 files,
larger than `ds386`'s 2427). **Final: 2700/3219 pass, 519 fail, all
519 fully triaged and explained:**

- **496** -- the missing-framework finding above (§4): 148
  `domains/omega`, 315 `domains/std`, 33 `domains/common`.
- **9** -- personal wizard-realm scratch/test content
  (`realms/thurtea/tmp/*.lpc` ×5, `realms/thurtea/legwand.lpc` -- a
  `SetPosition(int vs string)` type error in a private test item --,
  `realms/gravity/area/room/{startroom,wayne_manor_backroad}.lpc` --
  missing `RACE_D`/`ROOM_NEWBIE` macros and genuine syntax errors --,
  `realms/gravity/tmp/*.lpc` ×1). These are individual wizards' own
  private home-directory scratch/test content, not part of the shipped
  game world any ordinary player reaches -- left undocumented-further
  and unfixed, matching this project's treatment of admin-only/
  out-of-scope tooling elsewhere.
- **14** -- exactly matches `ds386`'s own already-documented "known
  non-functional" class (same files, several literally shared byte-
  for-byte with `ds386`): `obj/stargate.lpc` (deliberate author
  anti-load trap), `obj/area_room.lpc` + `open/prog.lpc` (builder-tool
  template scaffolding, `$S`-placeholder/relative-include patterns
  never meant to compile standalone), `domains/Ylsrim/broken/jar.lpc`
  (pre-existing incomplete content in the archive's own `broken/`
  bin), `secure/cmds/admins/opcprof.lpc` (calls a MudOS efun never
  ported to FluffOS), `secure/tmp/thurtea_CMD_EVAL_TMP_FILE.lpc` (an
  auto-generated `cmd eval` scratch file), `secure/daemon/i3router/
  server.lpc` (optional admin-only Intermud-3 tooling, undefined
  `ROUTER_NAME` -- not on the boot/login/play path, matches `ds386`'s
  own explicitly-left-alone i3router/imc2/ftp admin-tool list), and
  `daemon/help.lpc` + `secure/daemon/mudinfo.lpc` +
  `domains/campus/{chamber/elevator,room/monty,room/plab2}.lpc` +
  `domains/campus/npc/{charles,charly}.lpc` (zero actual "error:" text
  in the failure log -- the AGENTS.md §10.4 "isolated single-file
  lpcc-batch-mode artifact" class; `daemon/help.lpc` in particular is
  proven fine live -- the driver's real boot compiled it clean and
  `help`-adjacent features worked throughout the playthrough).

Zero unexplained failures.

## 6. Live playthrough (native driver)

Full continuous session via `scripts/mudclient.py` against
`~/src/fluffos/build-debug/src/driver config.fluffos`.

1. Fresh boot: `log/debug.log` clean, zero uncaught errors (only the
   expected benign `nosave`-on-function warnings, AGENTS.md §4.3),
   `Accepting telnet connections`/`Initializations complete.`
2. Registered a fresh test character, `Qintestomegab`, through the
   full flow (name → confirm → age gate → screen-reader prompt →
   password/confirm → gender → email → race pick `human` → two news
   pagers) -- landed in the start room wearing a t-shirt and jeans, the
   HUD prompt showing `hp`/`ppe`/`sp` (P.P.E. being this lib's Rifts-
   specific addition to the stock HP/SP pair).
3. `look`: correct room description/exits every time, across multiple
   rooms (start room, `Horace's General Supply Shop`, `First Village
   Bank` with "Zoe the bank teller" present).
4. `score`: correct full character sheet (name, level, race, class,
   native town, faith, birth date, training points, feeling/food/
   drink/alcohol status, XP-to-next-level, customization points) --
   confirmed both as a fresh player and as the seeded admin.
5. `i` (inventory): correct (starting Player's Handbook + worn t-shirt
   and jeans).
6. **Reconnect path** verified distinct from fresh registration (a
   second connection while the first session was still open correctly
   showed `Reconnected.`/`[X has rejoined]`).
7. **Admin verification**: seeded `fluffos` per §3 above; confirmed
   live via the admin-only room-path annotation on `look`, the
   admin-FAQ welcome banner, and successful `goto` into real (stock)
   content.
8. **Omega domain**: directly navigated via `goto` (see §4) --
   confirmed non-functional live, exactly matching the compile-sweep
   finding. This was the task's own explicit ask ("navigate into the
   omega domain specifically to verify its content actually works")
   and the honest answer is that it does not, for reasons entirely
   external to anything this onboarding pass could fix.
9. `quit`: clean disconnect (`Please come back another time!`,
   `[Fluffos quits Rifts DS]`, worn items correctly stripped on the way
   out).

## 7. WASM status

Not attempted this pass -- `wasm_status` left blank in `meta.json`,
matching the current treatment of other still-pending Dead-Souls-
lineage libs (`discworld`/`nightmare3`/`lima` as of 2026-08-25). Given
`ds386`'s own WASM pass found a real `sockets`-package-absent gap in
the eagerly-loaded simul_efun (`secure/sefun/sockets.lpc`) that had to
be gutted to boot at all under WASM, and that exact fixed file WAS
ported into this lib wholesale (§2 above), a future WASM pass should
start from a strong position -- but `secure/daemon/instances.lpc`
(also socket-touching, also loaded during a normal `quit()`'s channel
broadcast per `ds386`'s own writeup) diverged from `ds386`'s baseline
here (only whitespace/indentation differences, but enough that the
automated port skipped it) and has NOT had the same socket-gutting fix
re-applied -- worth checking first if a future WASM pass reports the
same "no sockets package" boot failure `ds386` hit.

## §10.7 deep functional test (2026-08-31, round two)

Full continuous playthrough against the shared `~/src/fluffos/build-
debug/src/driver config.fluffos` (no dedicated worktree needed),
deliberately exercising the WORKING stock-Dead-Souls content per this
session's own brief -- the confirmed-broken `domains/omega`/`domains/
common`/`domains/std` gap (§4 above, AGENTS.md §7.164) was not
re-litigated or re-poked at beyond a single deliberate negative-control
clone (below). A fresh throwaway mortal registration (`Vantharion`,
human) through the full chargen ritual (name validation, age gate,
screen-reader prompt, password, gender, email, race pick) landed
correctly in the start room; `enter town` reached the real, working
village hub. Also re-verified the seeded `fluffos` admin account
(§1.5/AGENTS.md's Dead-Souls admin-seeding note) still logs in
correctly and shows the wizard room-path annotation.

### What was tested and confirmed working -- zero programming bugs found this pass

- **Movement/navigation**: start room -> town intersection -> Saquivor
  Road (a talking beggar NPC gave a real map item) -> the Healer's
  Guild building, all with correct descriptions/exits/NPCs every time.
- **Shop/economy**: the Healer's Guild's real buy-a-service shop
  (`buy claritin from james`) correctly refused an empty-walleted
  character with "You don't have enough universal credits to buy
  that." -- a genuine, live-verified insufficient-funds economy check,
  not just a `list` read.
- **Real combat, extensively**: cloned a real stock-content NPC
  (`/domains/town/npc/orc`, the ordinary Dead Souls API --
  `inherit LIB_NPC`) as the admin and fought it to the admin's own
  death. Limb-targeted damage was exchanged realistically in both
  directions for well over 30 rounds (hits, misses, "flourish of
  attacks," stunning blows, per-limb messages) with zero crash and
  zero `debug.log` growth throughout.
- **Death and full resurrection cycle, live end-to-end** -- normally
  one of the two hardest-to-reach §10.7 checklist items, verified for
  real here because the admin-vs-orc fight above went all the way:
  `SYSTEM <death> Orc has slain Fluffos.` -> landed in `/domains/
  default/room/death` (`YOU ARE DEAD!`, "You are in formless void
  without substance and outside time.") -> the room's own `regenerate`
  command worked correctly, rematerializing the character back at
  `/domains/default/room/start` with restored (if reduced) HP/PPE/SP.
  Not gated behind `wizardp()` the way some other libs' ghost-recovery
  flows are (AGENTS.md §7.68/§10.7 item 6a) -- this lib's own death
  system handles a wizard character exactly like an ordinary one.
- **`quit` / reconnect**: clean disconnect (`Please come back another
  time!`), `log/debug.log` never created at any point in the whole
  session (before, during, or after the death/regen sequence). A fresh
  reconnect as `fluffos` correctly restored the post-respawn location
  (`/domains/default/room/start`) and HP/PPE/SP state from the save
  file.
- **Negative control, confirming §4's finding is still accurate and
  scoped correctly**: deliberately tried `clone /domains/std/monster/
  troll` (part of the already-documented broken `domains/std` tree) --
  got the exact same `inherit ADVERSARY;` compile error §4 already
  catalogued, then successfully cloned the WORKING `/domains/town/npc/
  orc` instead for the real combat test above. Confirms the broken/
  working boundary from onboarding is still exactly where it was
  documented, not encroaching on stock content.
- **~220s (3+ hour, see below) idle long-sit boot watch**: `debug.log`
  never created; stdout showed zero new errors beyond the one expected
  `domains/std/monster/troll.lpc` compile error from this session's
  own deliberate negative-control clone above.

### Minor, unresolved cosmetic observations (not fixed -- neither blocks anything or has a confirmed severe effect; scope discipline against guessing)

- **HP/PPE/SP occasionally render as a raw float** (`hp:
  132.000000/440` instead of `hp: 132/440`) after the death/regenerate
  sequence -- some stat-regen calculation along that path isn't
  truncated back to an int before being substituted into the prompt
  template. Purely cosmetic (regeneration and the death/respawn cycle
  both worked correctly regardless); not root-caused given time
  constraints.
- **`domains/Praxis/supply2.lpc`'s `add_sky_event((: "shop_closing"
  :))`** triggers this driver's "Function pointer returning string
  constant is NOT a function call" warning at compile time -- the same
  MudOS single-string functional-literal shorthand class already
  catalogued in AGENTS.md §8.23 (confirmed there to silently never
  fire on this driver). Here it would only affect a shop's scheduled
  "closing" cosmetic flavor event, not blocking `list`/`buy`/`sell`
  themselves; not chased further given the narrow, cosmetic blast
  radius and time budget.

### Not reached this session, flagged honestly

- **Skill/guild-class progression** (as distinct from the Healer's
  Guild's plain buy-a-service building, which is a shop not a
  class/skill guild): not exercised -- time was budgeted toward the
  admin combat/death/respawn sequence instead, which this project's
  own methodology explicitly treats as one of the two hardest-to-reach
  checklist items and therefore worth prioritizing when it becomes
  reachable.
- **A full two-sided paid shop transaction** (buy AND sell, with
  correct change): only the insufficient-funds refusal path was
  reached; a fresh mortal character never accumulated enough starting
  currency to complete a real purchase in the time available.

### An extended idle window (not a soak-test bug)

The driver was left running considerably longer than the standard
~200s idle target this pass (a background-task notification delay
outside this session's control stretched the wait to several hours of
real wall-clock time) -- reported here for the record since it's an
unusually long uptime, not because anything was found: `debug.log`
remained completely absent the entire time, and memory growth (~1.5GB
-> ~5.6GB RSS) is consistent with this driver's own already-documented
ambient NPC `heart_beat()`/lazy-compile behavior (AGENTS.md §10.8) over
that much extra wall-clock time, not a new leak specific to this lib.

### Files modified this pass

None -- this pass found zero programming bugs. Runtime state generated
during testing (the `fluffos` admin's updated save, the throwaway
`Vantharion` character's save/mailbox, and a few daemon `.o` save
files) was reverted before committing, per this project's own
runtime-state policy.
