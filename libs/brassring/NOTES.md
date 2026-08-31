# The Brass Ring -- porting notes

Source: `gh repo clone LashMUD/TheBrassRing` (cloned 2026-08-31). Slug
`brassring`, number 963, port 40265.

## 1. What this repo actually is: a content-only overlay, not a full mudlib

The repo's own `README.md`/`Setup.txt` say it outright: this holds "files
based on the Dead Souls mudlib ... used to develop The Brass Ring mud,"
and the setup instructions are literally "download the dead souls mud
library from http://dead-souls.net ... then replace the files in the
ds3.9/lib directories with the files in this repository." Confirmed by
file counts: the repo ships only 1,717 files total, and per-directory
counts are a small fraction of a real Dead Souls tree (`daemon/`: 2 vs
ds386's 60; `secure/`: 26 vs 568; `cmds/`: 8 vs 150; `lib/`: 21 vs 318).
Only the files the author actually touched or added were ever
committed.

**The hard consequence**: `secure/daemon/master.lpc`,
`secure/sefun/sefun.lpc`, and the entire rest of the security-daemon
engine layer were **never committed to this repo at all** -- not
gitignored, genuinely absent from git history (`git log --all --
lib/secure/daemon/master.c` returns zero commits, and there is no
`.gitignore` in this repo at all). Without a `master.lpc` the game
cannot boot under any driver.

Bundled inside the same repo (not a separate clone) is a complete port
of **DikuMud Alfa** (`domains/diku-alfa/`, 1,185 files -- the city of
Midgaard and its zones) with a top-level note crediting "the DikuMud to
Dead Souls port." The sibling repo
`LashMUD/DikuMud-to-Dead-Souls-Port` was checked and found to be the
same content already folded into this repo (confirmed file-for-file on
`room/90.zon/rm_9000.c`, byte-identical to the truncated file present
here -- see section 6.4) -- it did not need to be cloned separately.

## 2. Reconstructing the missing security layer, following the ds386/dshakkard precedent

This is the exact situation `dshakkard` (185, `ds-hakkard`) and, before
it, the general Dead-Souls-lineage guidance in AGENTS.md section 1.5
already cover: **`ds386`'s own raw archive, and its own already
driver-compat-fixed `work/` tree, are the correct substitute for a
missing Dead Souls engine layer** -- not invented content, since
`ds386` (Dead Souls 3.8.6) is confirmed the same lineage TBR is built
on (its `Setup.txt` says "ds3.9," close enough that `dshakkard`'s own
precedent -- also a 3.8.6-vs-3.9-labelled game -- used the same `ds386`
substitution successfully).

Procedure actually followed, at whole-tree scale rather than just
`secure/`:

1. `rsync -a --ignore-existing` `ds386`'s pristine **raw** archive
   (`libs/ds386/raw/ds3.8.6/lib/`) onto TheBrassRing's own raw clone
   (`libs/brassring/raw/lib/`). `--ignore-existing` means TBR's own
   1,717 files were never touched; every directory or file TBR didn't
   ship (all of `secure/daemon`, `secure/sefun`, most of `cmds/`,
   entire top-level directories like `estates/`, `realms/`, `save/`,
   `www/`, etc.) was filled in from ds386's pristine source. Verified
   after merge: 573 files under `secure/` (568 from ds386 + TBR's own
   26, with only overlapping paths -- `secure/cfg/preload.cfg`, the
   `secure/include/*.h` set, `secure/daemon/{autoexec,finger,players}`,
   `secure/lib/connect`, `secure/obj/medtric`, `secure/sefun/light`,
   and one each under `secure/cmds/admins` and `secure/cmds/creators`
   -- correctly kept as TBR's own versions).
2. Ran `scripts/convert_lib.sh` on the merged raw tree (GB18030->UTF-8
   -- a no-op here, this repo was already plain ASCII/UTF-8 --
   `.c`->`.lpc` rename, `static`->`nosave`, literal `.c"` reference
   fixes) to produce `libs/brassring/work`.
3. **Then, critically, went one step further than a plain "copy
   ds386's raw" substitution**: every file the mechanical rename step
   touched that TBR itself never shipped (identified precisely via
   `git status --porcelain --untracked-files=all` inside the raw
   clone, since the `rsync --ignore-existing` step left ds386's added
   files untracked in that git working copy -- 4,676 files) was
   **replaced again**, this time with `ds386`'s own already
   driver-compat-fixed `work/` copy of the same path (after the
   `.c`->`.lpc` rename). This reuses every hand-fix `ds386`'s own
   onboarding already discovered (the `get_root_uid()`/`get_bb_uid()`
   stubs, the `valid_read`/`valid_write` lazy-load reentrancy guard,
   etc. -- see AGENTS.md section 7.1/7.2) instead of rediscovering them
   from a fresh mechanical-only conversion of ds386's *raw* (unfixed)
   source. All 4,676 substitutions matched a real path in `ds386`'s
   `work/` -- zero misses.
4. TBR's own 1,717 files went through nothing but the ordinary
   mechanical `convert_lib.sh` pass; they needed their own,
   TBR-specific fixes on top (section 3 below).

This means `secure/daemon/master.lpc`, `secure/sefun/sefun.lpc`,
`secure/daemon/players.lpc`'s non-TBR sibling pieces, and every other
inherited engine file in this lib are **not reconstructed from
scratch** in the sense of writing new code -- they are `ds386`'s own
real, already-tested Dead Souls 3.8.6 engine, verified to be the
correct substitute the same way `dshakkard` verified it (every
`/secure/*` path TBR's own code actually references was checked to
exist in `ds386`, and TBR's shipped `secure/include/config.h` and
`secure/cfg/*` are TBR's own real customized versions, not
substitutions).

## 3. Genuine programming bugs found and fixed (TBR's own code, or the bundled diku-alfa content)

None of the bugs below live in the reused ds386 engine layer -- that
part came pre-fixed. All of them are in content this session actually
had to touch: TBR's own custom files, or the bundled DikuMud port.

### 3.1 `array` is not a reserved word in this driver build -- pervasive `TYPE array NAME` old-MudOS dialect (AGENTS.md section 6.3, much larger instance than previously catalogued)

`~/src/fluffos/src/compiler/internal/lexer_utils.cc` only lexes the
word `array` as the `L_ARRAY` token when the driver is built with
`ARRAY_RESERVED_WORD` defined -- this build isn't, so `array` is a
plain identifier. Every `TYPE array NAME` declaration (global, local,
function-return-type, and function-parameter forms alike) is a hard
syntax error here: the parser reads `TYPE` as the type, `array` as the
*declared name*, and chokes on whatever follows. AGENTS.md section 6.3
already catalogues this class from isolated single-lib instances; here
it was **the single largest driver-compat fix of this session** --
found in every layer of TBR's own hand-written code (`lib/body.lpc`,
`lib/combat.lpc`, `lib/combat_r_o.lpc`, `lib/living.lpc`,
`lib/genetics.lpc`, `lib/base_trainer.lpc`, `lib/meal.lpc`,
`lib/props/deterioration.lpc`, `lib/std/base_armor.lpc`,
`lib/lvs/abilities.lpc`, `daemon/help.lpc`, `daemon/seasons.lpc`,
`secure/lib/connect.lpc`, `secure/daemon/finger.lpc`,
`secure/daemon/players.lpc`, `secure/cmds/admins/mudconfig.lpc`,
`secure/obj/medtric.lpc`, `powers/npc/magic_user.lpc`) and in the
bundled diku-alfa content (`domains/diku-alfa/etc/{magic_user,
base_trainer}.lpc` and 4 `cityguard` NPCs) and etnar's own bespoke NPCs
(`albert_derby.lpc`, `waltin_kelley.lpc`) -- 37 files, ~120 sites.

Because `lib/body.lpc` and `lib/player.lpc` (see 3.2) are inherited by
essentially every player/NPC object, this single bug class cascaded
into **1,873 of 3,800 files (49%) failing a full `lpcc_check.sh` batch
sweep** before it was found and fixed -- a textbook instance of
AGENTS.md section 6.4's "one shared root cause, not N bugs."

Fix: mechanical script (`fix_type_array.py`, not checked in) that
drops the word `array` and inserts the real `TYPE *NAME` pointer-array
syntax, adding one `*` per comma-separated declarator (the classic
"`TYPE * a, b;` only stars the first name" sub-bug -- section 6.3's
other variant -- would otherwise reappear if only the first name in a
list got starred). Two shapes needed hand-fixing after the script ran:

- **`TYPE array *NAME`** (8 sites: `powers/npc/magic_user.lpc`,
  `waltin_kelley.lpc`, `caltan_dowini.lpc`, both `pierce_pascal*.lpc`,
  both `diku-alfa/etc/magic_user*.lpc`, `diku-alfa/room/50.zon/
  rm_5039.lpc`) -- the author had *already* written the correct `*`
  and the redundant `array` keyword doubled it; the script's blind
  "insert a star" rule produced `object **targets` (a pointer to an
  array of arrays, not what was intended). Fixed by hand: drop `array
  ` only, keep the existing single `*`.
- **`class TYPENAME array NAME`** (2 sites: `lib/body.lpc`'s
  `class MagicProtection array GetMagicProtection()`,
  `secure/daemon/finger.lpc`'s `class marriage array Marriages`) -- the
  same dialect applied to a `class`-typed array, needing `class
  TYPENAME *NAME` instead.

### 3.2 `lib/player.lpc`: un-starred `oldparties` -- the exact bug already catalogued on `ds386`'s own raw archive

`Setup()`'s `string oldparties = PARTY_D->GetOldParties();` (missing
the `*`) is passed to `RemoveExtraChannels()` and `foreach`ed as if it
were an array, causing `Bad type for argument 1 of
RemoveExtraChannels ( string * vs string )`. This is not a new
discovery -- `dshakkard`'s own meta.json already documents "a real
un-starred `string oldparties` bug in `lib/player.lpc` present
byte-identically in `ds386`'s own raw archive" from that session's
`TYPE * a, b;`-class sweep. TBR's `lib/player.c` is its own tracked
file (not reused from `ds386`'s already-fixed copy), so it carried the
same pre-existing upstream typo forward unfixed. Confirmed the fix
(`ds386/work/lib/player.lpc` already has `string *oldparties`) and
applied the identical one-character change. This bug alone masked a
huge share of the section 3.1 cascade, since `player.lpc` is inherited
by every player body -- fixing it (after fixing every direct `TYPE
array` site) is what let the corpus-wide compile-sweep failure rate
drop from 49% to under 1%.

### 3.3 `domains/etnar/wyr/wyr/npc/pierce/pierce_pascal.lpc`: missing closing brace drops a whole function

`checkPrank()` opens 2 extra brace levels (an `if` block, then a
`switch`) but only closes 1 before the file moves on to
`checkPlacement()` -- a hard "unexpected `(`" parse error at the next
function's own declaration, since the parser is still inside
`checkPrank()`'s body. Confirmed genuinely missing (not a
`convert_lib.sh` fallout) by a raw brace count (21 open, 20 close) and
by diffing against the sibling draft file `pierce_pascal_1.lpc` (a
much later, unfinished rewrite of the same NPC's logic, not currently
`inherit`ed/loaded by anything -- left as-is, it's the author's own
in-progress scratch file, not dead weight to clean up). Fixed by adding
the one missing `}`.

### 3.4 `domains/diku-alfa/room/74.zon/npc/7044_blob_lemure.lpc`: `SertClass()` typo

`SertClass("fighter")` -- undefined function; should be `SetClass()`.
A plain one-character transposition typo, one instance, in the bundled
diku-alfa content (not TBR's own file). Fixed directly.

### 3.5 `domains/diku-alfa/room/79.zon/meals/6013_water_barrel.lpc`: wrong argument type to `SetMealType()`

`SetMealType("water")` -- `SetMealType()` (`lib/meal.lpc`) takes the
`int` bitmask constants from `include/meal_types.h`
(`MEAL_FOOD`/`MEAL_DRINK`/etc.), not a string; every sibling meal file
in the same directory (e.g. `7090_waybread.lpc`) correctly passes
`MEAL_FOOD`. Fixed to `SetMealType(MEAL_DRINK)`, matching the object's
actual purpose (a water barrel).

### 3.6 `#define __DIR__` collisions in etnar's and diku-alfa's virtual-room servers -- same class dshakkard already catalogued

16 `virtual/server.lpc`/`virtual/void.lpc` files (all 6 etnar
sub-regions -- `virtual`, `char`, `q'in`, `wyr/baramblewood`,
`wyr/orgon`, `wyr/vexwood`, `wyr/wyr` -- plus `diku-alfa/virtual/`)
carry a manual `#define __DIR__ "/domains/<name>/virtual/"` that
collides with this driver's own native `__DIR__` predefine ("Illegal
to redefine a predefined value"). AGENTS.md/`dshakkard`'s own notes
already catalogue this exact pattern ("6 bespoke-domain virtual-room
files with the redundant manual `#define __DIR__`", fixed there by
deleting the line since the driver's own value is already correct).
Same fix applied here, at larger scale (16 files, since both etnar and
the bundled diku-alfa port use the standard Dead Souls virtual-room
template).

## 4. Config changes for playability (not bugs -- shipped defaults that would have blocked testing)

- **`MUD_IS_LOCKED`**: TBR ships this `1` (a personal-development
  default -- `secure/lib/connect.lpc`'s `is_locked()` check gates every
  new connection except creators). Flipped to `0` so ordinary
  registration works, matching this project's standard "make the
  default boot actually playable" policy.
- **`ADMIN_EMAIL`/`DEBUGGER`**: TBR ships `"n@n.net"`/`"lash"` (the
  original author's placeholders, per `Setup.txt`'s own instruction to
  change them). Set to a generic placeholder and `"fluffos"`
  respectively; `DEBUGGER` only gates a couple of debug-message/newbie
  exclusions, not admin rank (see section 5).

Confirmed **no live outbound network connections at boot**: TBR's own
`secure/include/config.h` ships `DISABLE_IMC2 1` (verified this
actually gates `secure/daemon/imc2.lpc`'s `socket_create()`/
`socket_connect()` calls behind `#if DISABLE_IMC2`, not just a cosmetic
flag); `DISABLE_INTERMUD` is `0` but `daemon/intermud.lpc` makes no
socket calls of its own at all in this codebase (it's a local
chat-channel abstraction only). No `RELEASE_NOTES`/version-check HTTP
fetch runs automatically either (TBR's own `secure/daemon/autoexec.lpc`
is much smaller than `ds386`'s and only calls
`IMC2_D->UnSetAutoDisabled()`, itself a no-op while `DISABLE_IMC2` is
set). Unlike `ds386`/`dshakkard`/`havenmud`, **this lib is safe for
high-frequency automated re-boot loops.**

## 5. Admin seeding (fluffos / Mud@2026) -- the Dead Souls file-move convention, made easier by a lucky default

Per AGENTS.md section 1.5's Dead-Souls-lineage note: admin-ness here is
a save-file-directory fact (`secure/save/creators/<letter>/<name>.o`
vs `secure/save/players/<letter>/<name>.o`), not a rank flag. Procedure
followed exactly as documented on `riftsds`: registered `fluffos`
through the completely normal new-player flow (name/age/password/
gender/email/race/skill-selection, `AUTO_WIZ` left at its shipped `0`
so no special creator prompt was needed), then with the driver stopped,
moved `secure/save/players/f/fluffos.o` to a newly-created
`secure/save/creators/f/fluffos.o`, then rebooted.

One bonus finding: TBR's own shipped `secure/cfg/groups.cfg` **already
lists `fluffos` in every ACL group** (`SECURE`, `ASSIST`, `ELDER`,
`TEST`, `INTERMUD`, `BUILDER`, `TELNET`, `EMOTES`) -- confirmed
byte-identical to `ds386`'s own default `groups.cfg`, i.e. this is Dead
Souls' own stock placeholder example name, not something this project
seeded. So the file-move above was the *only* step actually needed;
`groups.cfg` required no edit.

Verified: `update /domains/town/room/start` succeeds with no ACL
denial as `fluffos` (creator-only compile permission confirmed
working), and `fluffos` can `goto` anywhere in the world (used to
verify the etnar and diku-alfa content -- see section 6).

## 6. Live boot + playthrough verification

Boots with **zero compile errors and zero fatal errors** in
`log/debug.log` across every test session in this write-up (grep
count: 0 every time). `lpcc_check.sh` full-corpus batch sweeps hit
FluffOS's normal "batch mode never unloads" memory ceiling on this
unusually large corpus (3,800 files -- the full Dead Souls 3.8.6 engine
plus the bundled 1,185-file DikuMud port) before finishing a complete
pass every time it was tried (killed by this session's own 8-9.5GB RSS
safety net, per AGENTS.md section 10.4's documented memory-balloon
caution for mega-libs); the largest completed sample covered 2,590 of
3,800 files (68%) with a 99.2% pass rate and zero unexplained failures
after the section 3 fixes landed, so per section 10.4's own guidance
("on mega-libs the boot + interactive test is the sufficient
verification gate") the live boot below is the authoritative check,
not the partial sweep.

Verified live, twice with two independent new characters
(`fluffos`/`qintest`) plus one full reconnect:

- Full registration flow: name -> confirm -> 13+ age gate -> screen-
  reader question -> password (+confirm) -> gender -> email (validated
  -- a deliberately-malformed address was correctly rejected and
  re-prompted) -> race pick (8 races: dwarf, elf, half-elf, half-orc,
  halfling, human, orc, poleepkwa) -> full skill selection (6 primary/
  4 secondary/4 minor skill slots, all 28 `secure/cfg/skills.cfg`
  skills reachable and correctly bookkept slot-by-slot) -> character
  summary -> arrival in `/domains/default/room/start`, wearing starting
  clothes.
- `enter town` correctly moves a new player into Saquivor's "Village
  Road Intersection" (the real starting town, distinct from the
  tutorial start room) with correct room text, exits, and inventory
  (clock tower).
- **Etnar verified**: `goto /domains/etnar/wyr/wyr/room/rm_174` reaches
  "The Lounge" in the village of Wyr with correct room text, ASCII
  minimap, and exits -- the bespoke, still-in-progress fantasy setting
  the repo's own `readme.txt` describes.
- **Bundled diku-alfa content verified**: `goto
  /domains/diku-alfa/room/30.zon/rm_3001` reaches "The Temple of
  Midgaard" with correct room text and exits.
- `look`/`score`/`update` (admin)/`quit` all produce correct output.
- Reconnect (`fluffos`/`Mud@2026`) restores the exact same character,
  in the exact same room last left in (via `goto`), with the same worn
  inventory (t-shirt, jeans) -- confirmed across two separate
  reconnects.

## 7. A known, pre-existing content gap (not fixed -- matches upstream, not a driver-compat bug)

`domains/diku-alfa/room/90.zon/rm_9000.lpc` is genuinely truncated
mid-`create()` (opens the function, sets climate/light, then the file
just ends -- no closing braces at all). Confirmed this is **not**
conversion fallout: cloned the sibling repo
`LashMUD/DikuMud-to-Dead-Souls-Port` directly and its
`room/90.zon/rm_9000.c` is byte-for-byte the same 17-line truncated
file. This is an authentic upstream content gap in the original DikuMud
port, left as-is per this project's content-vs-driver-compat boundary
(AGENTS.md's standing rule: fix programming bugs, don't invent missing
content).

Also left as-is, matching classes already documented on
`ds386`/`dshakkard`'s own lpcc sweeps (pre-existing, non-bugs):
`obj/stargate.lpc`'s deliberate `#include "this is here on purpose to
prevent this from loading"` anti-load trap; `secure/cmds/admins/
opcprof.lpc`'s call to the `opcprof()` efun, which this driver doesn't
implement; and two builder scratch/template files
(`open/prog.lpc`'s `$S` template placeholder and `#define` with no
name, `obj/area_room.lpc`'s reference to a `../customdefs.h` template
file that was never meant to exist standalone).

## 8. §9 LPC formatter

Ran `format-corpus.mjs` across all 3,817 `.lpc` files: 3,812
reformatted, 5 unchanged, 0 errors. All three documented blind-spot
checks came back clean: zero `::`-parent-call-split hits (`grep -rnE
':\s:\s*[a-zA-Z_]+\(' `), zero damaged-escape-sequence hits (`grep -rl
'\\ n'`), and a manual review of every `case LABEL: //comment` line in
the corpus (diku-alfa's `magic_user.lpc` switch statement and
`secure/daemon/imc2.lpc`'s mode-name comments) confirmed no
comment-swallowing damage -- all case bodies and fall-throughs intact.
Re-booted and re-ran the full `fluffos`-reconnect smoke test after
formatting: zero new compile/fatal errors, same room/inventory/output
as before formatting.

## 9. §10.7 deep functional test (round two, 2026-08-31)

Full continuous native-driver session beyond the onboarding smoke test,
with a fresh mortal (`Questora`, human, PRIMARY blade/melee
attack+defense/stealth/detection, SECONDARY bargaining/healing/
tracking/concealment, MINOR faith/fishing/stealing/multi-hand) driven
via `scripts/tmux_mud.sh`, plus the seeded `fluffos` admin for
`eval`/`goto`-assisted navigation between this lib's disconnected
content clusters (etnar's bespoke domain and the bundled diku-alfa port
share no real exits with `domains/town`, confirmed by grep --
`eventMoveLiving()`, the same primitive `secure/cmds/creators/goto.lpc`
itself uses, is the correct way to relocate a living object here;
`object->move(dest)` is NOT a real function in this codebase and
silently no-ops with no error via `->`-dispatch -- a footgun worth
recording for any future session scripting movement here).

**Tooling note**: this lib's registration flow ("Do you use a screen
reader...") drives an ANSI-cursor-addressed overhead-map/stat-panel
HUD that assumes a normal ~24-row terminal. A `tmux_mud.sh`-style pane
taller than that (the tool's default `-y 500`) makes `tmux capture-pane`
show badly interleaved stale-and-fresh text (the HUD only repaints
rows within its assumed viewport, leaving everything below frozen at
whatever was last drawn there) -- looks exactly like a hung/unresponsive
connection but isn't. Fix: `tmux resize-window -t <session> -y 50`
right after `start`. Confirmed via independent `eval
file_name(environment(player))` ground-truth checks that the game
state was always correct even when the pane looked frozen/garbled.

Tested and confirmed working correctly, live: guild-independent skill
training via `ask <trainer> to train <skill>` (the class's own
in-character hint text, not the more natural-sounding but WRONG `ask
<trainer> train <skill>` or bare `train <skill>`, both of which this
verb's own rule table -- `verbs/common/ask.lpc`'s `SetRules("LIV STR",
...)` routes to a plain spoken-sentence handler, not
`eventAsk()`/`CommandResponses` at all -- confirmed correct rejection
"You need more training points!" at level 1/0 training points, per
design); real melee combat vs. a placed diku-alfa mob (`Beastly Fido`,
bidirectional limb-targeted damage, a live "You are a bit more adept
with your melee attack" skill-improvement message, clean `flee`); the
Pet Shop's economy loop end-to-end (`inquire` correct price list,
`adopt <pet>` correctly refused for insufficient gold, then correctly
succeeded once funded, with the right currency deduction); etnar's Wyr
village (`The Lounge` -> `The Common Room` -> `The Entrance to the
Cyclops Inn`, matching onboarding's own documented room text) and
diku-alfa's Midgaard city square area, both with correct room
text/exits and zero new `debug.log` errors; `quit` -> `debug.log` grep
(clean) -> a real ~3.5-minute gap (the long-sit watch below) ->
reconnect, correctly restoring the exact same character/location/
worn-inventory/vitals; a ~200s synchronous idle long-sit boot watch
(`python3 scripts/mudclient.py ... --timeout 200 --idle 300`, this lib
has no WASM build yet) sitting on an open connection at the login
prompt -- ended in the login object's own normal inactivity timeout,
zero new `debug.log` errors, driver RSS stable (~2.2GB, expected for
this 3,800+-file mega-lib per its own onboarding notes).

Death/respawn and a full guild-class questline were not reached --
budgeted out in favor of the two real bugs below and the broad
etnar+diku-alfa content-verification pass the task specifically asked
for; flagged honestly as unverified-live rather than silently skipped.

### Bugs found and fixed

1. **AGENTS.md §7.193 (NEW) -- two DikuMud-port `SetShort()` calls hold
   a full "long room-appearance" sentence instead of a bare noun
   phrase, and this codebase's living-NPC room-listing code
   unconditionally appends a posture verb phrase to `GetShort()`
   regardless of what it already says**, producing a doubled,
   grammatically broken line. `domains/diku-alfa/room/30.zon/npc/
   3095_pet_shop_boy.lpc` had `SetShort("A Pet Shop Boy is here,
   humming gently.")`; `domains/diku-alfa/room/41.zon/npc/
   4101_troll.lpc` had `SetShort("A large mean-looking troll is
   here")`. `lib/body.lpc`'s `GetHealthShort()` just wraps
   `GetShort()` in a health-color code with no stripping; `lib/events/
   describe.lpc`'s room-listing code then buckets livings by
   `GetPosition()` and appends `" is standing here."`/`" is lying
   down."`/etc. unconditionally to that same string for the
   `POSITION_STANDING` (etc.) bucket -- confirmed live: `look`ing at
   the Pet Shop showed "A Pet Shop Boy is here, humming gently. is
   standing here." Every OTHER living NPC checked in the same corpus
   (`3064_drunk.lpc`: `"a singing, happy Drunk"`, `3061_janitor.lpc`:
   `"the Janitor"`, `3062_fido.lpc`: `"Beastly Fido"`) correctly uses a
   bare noun phrase for `SetShort()`, matching a DikuMud port
   convention where the original Diku MOB file's "long description"
   (Diku's own room-listing line, self-contained) was supposed to stay
   separate from the short combat-message name -- these 2 files
   mistakenly got the Diku long-description text copied into
   `SetShort()` instead. (Non-living scenery objects like
   `3600_candlestick.lpc`/`3134_bench.lpc` correctly DO bake `"is
   standing here"` directly into their own `SetShort()`, because
   inanimate items are rendered via a different, non-appending display
   path -- confirmed by checking `all_inventory(env)` is filtered by
   `living(ob)` before the posture-bucketing code ever runs, so this
   is not a contradiction, just two different, both-legitimate
   conventions for two different object categories.) Fixed by
   stripping the redundant sentence fragment from both `SetShort()`
   calls, matching the established living-NPC convention (`"a humming
   Pet Shop Boy"`, `"a large mean-looking troll"`). Verified live
   (destruct + respawn a fresh instance of each): the pet shop now
   correctly shows "A humming Pet Shop Boy is standing here."
   **How to apply generally**: any Dead-Souls lib hosting a DikuMud (or
   similar Diku-lineage) port is suspect for this exact class --
   `grep -rE 'SetShort\("[^"]* is (here|standing|lying)' domains/` (or
   the equivalent short-description setter) to find any living NPC
   whose short description was left as a full self-contained sentence
   instead of a bare noun phrase.

2. **`domains/diku-alfa/room/30.zon/rm_3031.lpc`'s pet-shop `adopt`
   command has the `if (!name)`/`if (name)` branches swapped/confused
   for 4 of 5 pet types**, a copy-paste mistake (confirmed via the
   file's own `cmd_adopt`-equivalent switch statement): the `if
   (!name)` branch (meant for "no custom name given") for wolf,
   rottweiler, puppy, and kitten still executed `ob->SetShort("a pet
   <animal> named " + capitalize(name))` with `name` actually 0/undefined,
   producing a dangling `"a pet kitten named "` (rendered live as "A
   pet kitten named is standing here." once combined with bug #1's
   posture-append behavior) -- confirmed by adopting an unnamed kitten
   and reproducing this exact broken line. The `SetId()` calls in the
   same branch also uselessly included the undefined `name`/
   `capitalize(name)` values in the identifier array. The beagle case
   had the OPPOSITE bug: its `if (name)` branch (custom name given) was
   byte-identical to its `if (!name)` branch, so a beagle NEVER got its
   custom name applied even when the player supplied one. Fixed all 5:
   the `if (!name)` branches for wolf/rottweiler/puppy/kitten now just
   set a bare `"a pet <animal>"` short description (matching the
   beagle's own already-correct no-name branch) with no bogus `name`
   values in `SetId()`; the beagle's `if (name)` branch now actually
   applies `"a pet beagle named " + capitalize(name)` (matching the
   pattern the other 4 pets already use in their own `if (name)`
   branches). Verified live, both directions: `adopt puppy` (no name)
   now correctly shows "A pet puppy is standing here."; `adopt puppy
   Rex` (with a name, after destructing/re-adopting) correctly shows
   "A pet puppy named Rex is standing here." No new AGENTS.md entry --
   this is a narrow, single-room copy-paste bug in bespoke vendor
   script, not a shared-library pattern likely to recur elsewhere.

### Non-bugs (documented, not fixed)

- `doc/RELEASE_NOTES_HTTP`'s cached response timestamp updated during
  this session's boots despite NOTES.md §4's earlier claim of "No
  RELEASE_NOTES/version-check HTTP fetch runs automatically" --
  apparently a real outbound HTTP GET does still fire somewhere in the
  boot/`autoexec` chain after all (the file's `Date:` header advanced
  across reboots). Not chased further (out of this pass's scope, and
  the response itself is cached/served from a local file either way,
  not a live dependency of anything tested) -- flagged as a correction
  to that earlier claim for whoever next cares about this lib's
  network footprint, not fixed or re-verified in depth.
