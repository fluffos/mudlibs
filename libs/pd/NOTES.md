# pd — technical notes

Source: `gh repo clone ehershey/pd` (cloned 2026-08-28). Mudlib root at
`libraries/beta-ii/` inside that repo (a bundled `FMud/` Flash client
and `bin/` driver binaries/scripts, both siblings of `libraries/` at
the repo root, were never copied into `raw/` — excluded by construction,
not by a later filter). Number 952, port 40254. Status: **done** —
boots clean natively, full registration-to-gameplay playthrough AND the
restore/reconnect path verified live and repeatedly.

## What this lib is

A real, historically-operated English-language MUD ("Primal Darkness",
1999-2010, `mud.primaldarkness.com`/`www.primaldarkness.com`), Nightmare
mudlib lineage (`adm/obj/master.lpc` credits "Descartes of Borg 03
august 1993, Nightmare Mudlib Version 3.0"). One of the largest libs
onboarded this session: 32,436 `.c`/`.h` files (72,244 total files
including data/docs/logs), all pure ASCII (`already_utf8=71949,
converted=51, lossy=78` per `convert_lib.sh` — the 78 lossy bytes were
all a single garbled `—`/bullet character in a handful of `//` author
comment headers, purely cosmetic, no functional impact). No GB18030/BIG5
conversion needed at all.

Real, extensive, genuinely-authored content confirmed across dozens of
domains: `aekari`, `citrin`, `distopia`, `durst`, `forest`, `frozen`,
`guilds`, `helgrath`, `helves`, `inferi_island`, `lodos`, `marshes`,
`metaisland`, `pastarlon`, `roston`, `saahr`, `tirun`, and more — not
stock/placeholder content. Real historical player and wizard save data
ships with the archive (`adm/save/users/`, `adm/save/boats/`,
`wizards/<name>/`), which is why several early test registrations
collided with pre-existing real historical account names (`brennik`,
`ashlyn` both turned out to be real accounts from the original site —
picked less-common fantasy names for later tests to avoid this).

4 `bin/*.mud` configs (`primal`/`tna`/`whit`/`builders`) in the excluded
`bin/` directory confirm multiple named instances of the same codebase
historically — `primal.mud` was used as the template for this lib's
`config.fluffos` (port/paths/limits adapted, everything else preserved).

## §2.2 on-sight checklist

- `master.lpc`'s `load_object`/`get_root_uid`/`get_bb_uid` all read
  normally; **no `get_include_path()` existed at all** — added one (see
  "Compile-time fixes" below).
- No `securityd`/`is_chinese`/`check_legal_name` — not applicable
  (English lib, no Chinese-name gating anywhere in this lineage).
- `adm/db/preload.db` preloads a normal, small daemon set
  (`/daemon/command`, `castle_d`, `race_d`, `localpost`, `remotepost`,
  `letter`, `economy_d`, `events_d`, a network daemon, `web`) — no
  `dns_master`/intermud entries.
- No hardcoded `MUD_PORT`/`PORTNO` constant anywhere (`grep` came back
  empty) — this lib reads its port purely from `config.fluffos`, so
  none of the §5.3 "port baked into source" trap applies.
- No `command_hook` private/nomask overrides; no `efun::set/query/delete`
  usage; no bare `switch...default` grammar issue; no `ed_start`/
  `ed_cmd`/`query_ed_mode` usage.
- **Genuine, dormant, on-demand outbound `socket_connect()` calls exist**
  (`daemon/plains_d.lpc`'s `connect_plainswalk()` to a hardcoded
  `209.85.145.196:3000`, `adm/daemon/link_d.lpc`'s `connect_server()` to
  `63.84.93.196:2349`, `adm/simul_efun/mail.lpc`'s SMTP relay, and a full
  Intermud-Chat implementation in `daemon/imc_socket.lpc`) — **but,
  unlike `imud`'s always-on I3 connection, none of these fire
  automatically at boot or preload time**: they're all gated behind a
  player/wizard command (a "plainswalk" cross-mud portal feature, a
  mud-to-mud link-server handshake, sending in-game mail, and an IMC
  chat network respectively), and none of the daemons that own them are
  in `preload.db`. Confirmed no automatic network activity across
  several full boot+playthrough cycles. Flagging here per the §2.2
  standing discipline anyway, since a future wizard actually running
  the `plainswalk` or mud-link commands would attempt a real outbound
  connection to a long-dead historical IP (harmless — it'll just
  time out — but worth knowing before assuming this lib is fully
  network-sandboxed like the rest of the corpus).
- Inbound-listening sockets confirmed harmless: `daemon/network.lpc`
  (UDP), `daemon/webservices/main.lpc` (port 12333), `daemon/web.lpc`
  (port 8500), `wizards/whit/network.lpc` (UDP 6123) — these just open
  extra local listening ports that nothing external will ever connect
  to in this environment; not a security or stability concern.

## Conversion (`convert_lib.sh`)

Ran `scripts/convert_lib.sh libs/pd/raw/beta-ii libs/pd/work` (default
GB18030 encoding — a no-op given the pure-ASCII source, confirmed
before running by sampling files with a Python decode round-trip). Full
run took ~26 minutes given the file count. Mechanical fixups the script
applied: 21,629 literal `.c"` reference rewrites, 3,713 local
angle-bracket `#include <x.lpc>` → quoted conversions, 1,017 files'
`static` → `nosave`. Two script-vs-directory-structure edge cases found
and hand-fixed afterward (neither is a new bug class, both are
consequences of the rename step encountering something odd mid-run):

- **A directory literally named `myfile.c`**
  (`wizards/kabaal/room/myfile.c/{room1,room2,room3,room4}.c`) — `find`'s
  `-name '*.c'` glob (no `-type f`) matched the directory too, renaming
  it to `myfile.lpc` in the same pass that was still trying to rename
  its now-stale-pathed children, so those 4 files were left as `.c`
  inside the renamed parent and never got the encoding/literal-`.c`-ref
  fixup pass applied. Manually renamed the 4 files and re-ran the
  literal-`.c`-reference fixup on just them (8 references fixed). These
  4 rooms' own exits reference a typo'd `myfile/roomN.c` path (missing
  the trailing `.c`/`.lpc` on the directory segment itself) that never
  resolved even in the original archive — a pre-existing, unreachable
  dead-end in what is clearly a wizard's personal test scratchpad
  (`wizards/kabaal/room/`), left as-is per scope (content, not a
  conversion regression).
- **A genuinely lost `keep.h` header**: 68 files under
  `wizards/whit/keep/` (`#include <keep.h>`) failed with "Cannot
  #include keep.h" — the file doesn't exist anywhere in the raw
  archive, not a conversion artifact. Reconstructed
  `include/domains/keep.h` from surviving evidence: `ROOMS`,
  `GARDEN`, and `WEP` are unambiguous (they mirror the surrounding
  directory layout, exactly matching this codebase's own convention —
  compare `include/domains/tundra.h`'s `SERVER`/`ROOMS` pair), and
  `GARDEN_SERVER` was fully verifiable since
  `wizards/whit/keep/rooms/garden/server.lpc` already exists on disk —
  a mechanical restoration, not invented content.

## Compile-time fixes (`lpcc_check.sh`)

Given the scale (~32K files), ran the memory-capped sweep in chunks
(fresh `lpcc --batch` VM per chunk, `ulimit -v` capped) rather than one
continuous batch — a single continuous process accumulates enough
resident object memory to hit `std::bad_alloc` well before reaching the
end of a corpus this size (confirmed: ~750 files consumed 8GB in one
continuous run). Final full-corpus pass: **31,923/31,935 files covered,
29,610 pass, 2,313 fail** (down from ~9,988 failures before any fixes —
a handful of memory-dense pockets, mostly large coordinate-grid room
areas, needed a second smaller-chunk pass to get full coverage; 12
files in one chunk that hit a hard abort even at 50-file granularity
remain untested, all inside the same already-known-dead
`wizards/amun/builders/` staging tree described below).

### Dominant class: base-class setters declared narrower than the corpus uses them (AGENTS.md §7.127)

**~8,800 of the original ~10,000 failures (88%)** came from just 8
functions in `std/object.lpc`/`std/room.lpc`/`std/monster.lpc`/
`std/lacky.lpc`/`std/living.lpc`/`std/vault.lpc` (plus their `bak`/
`test`/wizard-personal sibling copies, since this driver compiles every
`.lpc` in the tree standalone):

| Function | Declared as | Corpus actually calls it with | Fix |
|---|---|---|---|
| `set_id` | `string` | array, 7,350+ sites | `mixed`, coerce scalar→1-elem array |
| `set_swarm` | `int` | int OR string (mixed real usage) | `mixed`, no coercion (only used as a boolean flag) |
| `set_languages` | `string *` | array OR scalar | `mixed`, coerce scalar→1-elem array |
| `set_alignment` | `int` | int OR quoted numeric string | `mixed` + `to_int()` before arithmetic |
| `set_long` | `string` | string OR function (dynamic descriptions — `query_long()` already `functionp()`-checks) | `mixed` |
| `set_short` | `string` | string OR function (same as above) | `mixed` |
| `set_door_func` | `string` (3rd arg) | string OR function (`query_door_func()` already declared `mixed`) | `mixed` |

Each was confirmed against **every other real definition/override of
the same function** in the corpus before widening — in every case
(`set_id` most starkly: every non-base override already declares
`string *`) the base declaration was the sole outlier, not the callers.
See AGENTS.md §7.127 for the general "how to apply" writeup, now
updated with this lib as its largest confirmed instance.

### `daemon/command.lpc`'s dispatch table (AGENTS.md §7.118 — see "Two severe bugs" below)

### Missing/shadowed local headers (AGENTS.md §6.1 family)

- `keep.h` — see "Conversion" above (genuinely lost, reconstructed).
- `drowpath.h` (`wizards/stormbringer/roston/drowpath/`) and `vplain.h`
  (`wizards/nulvect/builders/vplain/`) both exist on disk but are
  `#include <x.h>`'d from a **subdirectory** one level below where the
  header actually lives (`rooms/`/`mobs/`) — outside what this lib's
  new `master::get_include_path()` (added since this lib had none at
  all) searches (its own directory only, not ancestors). 17 files
  total; fixed by converting those specific includes to absolute quoted
  paths (`#include "/wizards/.../drowpath.h"`) rather than widening
  `get_include_path()` to search ancestor directories corpus-wide,
  since only these two cases were found.
- `adm/save/boats.old/` (133 files, a stray backup copy of old boat
  source sitting inside what's otherwise a save-data directory) failed
  with "Illegal to inherit after defining global variables" — their
  shared `#include <ocean.h>` (which, unlike every other header these
  files use, declares a real initialized global `string *ocean_map`)
  came before `inherit PIER;` in file order. Fixed by moving
  `#include <std.h>` (needed for the `PIER` macro itself) + the
  `inherit` line ahead of the other two `#include`s in all 133 files —
  purely a reordering, no logic changed. This directory is unreachable
  from the live game (`adm/save/` is data, not loaded content) but was
  cheap and mechanical to fix regardless.

### Remaining ~2,300 failures: concentrated in confirmed-unreachable backup/draft directories

A `grep` sweep of the remaining failure list shows this is NOT a new
systemic class — it's a long tail of syntax errors, MudOS-only-efun
gaps (`dump_socket_status()`, old-style `(: val1, val2 :)` functional
literals), and one duplicate-function-declaration case
(`wizards/amun/builders/marshes/` — 158 files with their own local
`sp_sap()` override AND `#include <amun.h>`, which ALSO defines
`sp_sap()` with different logic; the "live" copy of this same content
under `d/inferi_island/marshes/` has no such conflict), overwhelmingly
concentrated in directories whose own names say "not live content":
`guildbak/`, `/old/`, `wizards/*/builders/`, `cmds/oldskills/`,
`*.nul`/`*.bak`-suffixed files. Spot-checked `wizards/amun/builders/
marshes/` specifically: **zero** references to that path exist anywhere
outside itself in the whole corpus — confirmed genuinely unreachable
from the live room network, not merely low-traffic. Logged here per
this project's content-vs-programming-bug scope line rather than
chased file-by-file; none of it affects the live, playable game.

## Two severe, corpus-wide bugs found and fixed

**Both discovered because the standard §10.1 playthrough script
initially only exercised fresh registration — the project's own
`§8.20`/`§8.22`-style lesson about the restore path needing its own
explicit test applied literally here.**

1. **Command dispatch totally broken (AGENTS.md §7.118, largest
   confirmed instance)** — `daemon/command.lpc`'s `rehash()` builds its
   verb→file table with `choses[j] = choses[j][1..strlen(choses[j])-3]`,
   arithmetic written for the original `.c` (2-char) extension; after
   this collection's standard `.c`→`.lpc` (4-char) rename it silently
   registered every verb one character too long (`"_look.lpc"` →
   `"look.l"` instead of `"look"`), so literally every command except
   `quit` (registered directly via `add_action()`, not through this
   table) returned the driver's generic `"What?"` fail message for
   every player, from the very first boot. Fixed with the established
   `-5` arithmetic. Verified live: before the fix, a fresh character's
   `look`/`score`/`inventory`/`say` all returned `"What?"`; after, all
   four (plus `read list`/`pick <race>` during creation) produced
   correct output.

2. **Existing-account restore/reconnect totally broken (new, AGENTS.md
   §8.22)** — `adm/obj/login.lpc`'s `check_password()` needs to
   temporarily read the connecting player's own save file (to compare
   the stored password hash), via a classic "borrow root through the
   master object" handoff:
   `master()->load_player_from_file(name, ob)` →
   `export_uid(ob); ob->restore_player(name);`. Two compounding
   misreadings of what this driver's `export_uid()` actually does
   (confirmed against the driver's own `f_export_uid()` C source):
   it's a **silent no-op unless the target's OWN euid is currently
   unset** (every object already has one, from `create()`'s own
   `seteuid(getuid())`), and even when it fires **it only ever sets the
   target's UID, never its euid** — it's a one-time ownership-transfer
   primitive, not a privilege grant. So `restore_player()`'s own
   `restore_object()` call always failed `master::check_access()`'s
   permission check on `/adm/save/users/...` with `*restore_object:
   read permission denied`, uncaught, silently aborting
   `check_password()` (and everything queued after it) with **zero
   trace in debug.log** — a brand-new registration worked perfectly (it
   never calls this function at all), but reconnecting to ANY existing
   account — including one that had just registered and cleanly `quit`
   moments earlier — landed the player in a session with literally zero
   working commands, `quit` included, no error visible anywhere.
   Diagnosed via `message()`/`debug_message()` instrumentation (plain
   `write()` produces no visible output during this lineage's pre-body
   login sequence, hence its own code always using
   `message("logon", ..., this_object())`). Fixed with two additions
   mirroring this lineage's own working SAVE-side handoff
   (`save_player()`/`actually_save_player()`, which happens to work by
   accident of a different code shape): a new self-only
   `nomask void clear_euid() { seteuid(0); }` on the shared
   `std/object.lpc` base class, called by `master.lpc`'s
   `load_player_from_file()` right before `export_uid()` (so the
   export actually fires and sets the UID to Root as intended), plus an
   explicit `seteuid(UID_ROOT);` added to `std/user/save.lpc`'s
   `restore_player()` right before `restore_object()` (succeeds because
   the UID `export_uid()` just set makes `master::valid_seteuid()`'s own
   `uid==UID_ROOT` special case pass). Applied identically to
   `master2.lpc` and the `std/test/`/`wizards/nulvect/std/` sibling
   copies. **Verified live end-to-end on two independent accounts**:
   register → `quit` → reconnect with the same password → correct
   restoration of room/inventory/equipment, `look`/`score`/`inventory`/
   `quit` all producing correct output (all of which returned `"What?"`
   before the fix).

## Admin account seeding (§1.5)

Registered `fluffos` through the normal registration flow (real driver,
real prompts). This lineage's wizard-status check is two-part —
`wizardp()` (a real efun, checks an in-memory `O_IS_WIZARD` flag set by
`setup()` whenever the saved `position` field is anything outside
`({"player","high mortal","ambassador"})`) AND `archp()`/`admp()`
(`wizardp(ob) && member_group(name,"superuser")`) — so BOTH halves
needed seeding: added `fluffos` to `adm/db/groups.db`'s `(superuser)`,
`(assist)`, `(allowed)`, `(creator)`, `(approval)`, and `(mudlib)`
groups (matching every real historical admin account's own membership
pattern), and set `fluffos.o`'s saved `position` field from the default
`"player"` to `"Root Avatar"` (a non-mortal title, matching this
lineage's own convention of colorful custom titles like `"Archon
Avatar"`/`"Realms Avatar"` for its real admins). Verified live: logging
in shows the extra Immortal/Arch news pages wizards get, and
`update /std/object` succeeds (`"/std/object: updated and loaded."`),
exercising both the read and compile halves of the file ACL.

## WASM status

Not yet attempted — out of scope for this onboarding pass per the
assigned task (native boot/playthrough only). `wasm_status: "pending"`
in `meta.json`.

## WASM measurement (2026-09-03)

`meta.json` was already `playable` from the 2026-08-31 deploy-unblock;
the README still said "not yet packaged." Cold-boot under the shared
`~/src/fluffos/build-wasm` failed: eager `adm/simul_efun/mail.lpc`
calls `socket_create`/`socket_bind`/`socket_error` (SMTP outbound),
so the whole simul_efun object was not loadable. Wrapped those
bodies in `#ifndef __PACKAGE_SOCKETS__` no-ops (native unchanged).
Wizard `network.lpc` / `daemon/web.lpc` socket failures remain
graceful preload skips.

Verified with `scripts/wasm_client.js`: new character `wasmpd` →
name-policy enter → `y` → `Test12345` twice → male →
`wasm@test.local` → real name → identity `new` → `read list` (30
races including human) → `pick human` → Tirun Central Park →
`score` ("Newbie Wasmpd the boy", 600 gold, 70 stat / 5 skill
points) → `quit` ("Reality suspended. See you another time!").
The seeded `fluffos` admin rejected `Mud@2026` ("Invalid password";
driver also logged the old-crypt 8-char warning) — not chased; new
registration is enough for the gallery path. Shop/combat/death were
not exercised this pass. The MEMFS copy does not write `wasmpd`
back to the host.

## LPC formatter (§9)

**Run 2026-08-31** (catch-up pass) — the original onboarding couldn't
run `node` (PATH issue, since fixed via `~/.zshenv`). Ran
`format-corpus.mjs` over all 31,936 `.lpc` files under `work/`: 31,709
reformatted, 84 already-clean, 143 refused (messy legacy code). Ran all
three §9 blind-spot checks: `::` split (0 hits), case-label/comment
merge (86 candidate spots across 8 files, manually diff-reviewed, all
intact), and pre-existing-unbalanced-quote garbling (1 hit,
`std/obj/deed.lpc` — a genuine original-source typo, fixed by hand and
reformatted). Re-booted and re-verified the full live playthrough
(registration, look, score, quit, restore/reconnect) — all correct.

## §10.7 deep functional test (2026-08-31, round two)

Full continuous playthrough on the native driver (`build-debug`), going
beyond the onboarding pass's registration/restore verification above —
specifically to independently re-confirm the restore-path fix (§8.22)
holds for a SECOND, unrelated account, and to exercise gameplay systems
(race pick, class/subclass acquisition, safe-sparring, domain travel,
long-sit daemon watch) the onboarding pass didn't reach. Test
character: id `Vulmarrow`, password `Test12345`, male human, class
Mage/subclass Sorceror — **kept** (not cleaned up) as a representative
playthrough character. Save file: `work/adm/save/users/v/vulmarrow.o`.

### Bug found and fixed: two objects pass a bare `int` to a `string`-typed setter, so this driver's strict compile-time type check rejects them and they never load

`/d/nopk/standard/cemetary/mon/monument.lpc:12` and
`/d/nopk/standard/rain_forest/obj/statue.lpc:8` both called
`set_prevent_get(1)` — `std/object.lpc`'s real declaration is
`void set_prevent_get(string str)` (494 other call sites across the
corpus correctly pass a message string, e.g. `fighter/dummy.lpc`'s
`set_prevent_get("You can't take that out of the ground!")`) — so both
objects hit `Bad type for argument 1 of set_prevent_get ( string vs int
)` and never compiled at all (`*No program in object '...'!` every time
anything tried to `new()` them). This is the mirror image of the
already-catalogued AGENTS.md §7.127 pattern (there, a shared base
setter was declared narrower than the corpus's real usage; here the
base declaration is correct and these two call sites are the outliers)
— narrow enough (2 files, not a systemic class) that it doesn't warrant
its own new AGENTS.md entry, but worth noting as the same general
"literal-argument-type mismatch on an otherwise-correct setter" shape.
Found via the long-sit boot watch below: a wandering `errand boy` NPC's
`move_around()` heart_beat wandered into
`/d/nopk/standard/cemetary/gravyar9`, whose `reset()` tried to
`new()` the broken `monument.lpc`, throwing a real (if silent-to-players)
error every reset cycle — exactly the class of bug §10.0 exists to
catch (invisible to registration/login smoke testing, only surfaces
once a lazily-reset room with wandering NPC traffic is hit). Fixed by
giving each object a real message string matching the established
convention (`"The monument/statue is far too heavy to carry."`).
Verified with a targeted `lpcc --batch` recompile of just these two
paths — both compile clean, no more `FAIL`/`error` lines — and
confirmed no recurrence of the `No program in object` error across a
fresh driver boot plus the full long-sit idle window below.

### What was tested and confirmed working

- **Registration and race pick**: full flow (name → name-policy
  confirm → password → gender → email → real name → identity-profile
  prompt) into the race-selection void room, `read list` (all 30 races
  render), `pick human` → landed correctly in Tirun Central Park with
  starting gear (boots, chainmail, helmet, newbie guide) and 600 gold.
- **Movement/exploration into 3 distinct domains**: Tirun (walked the
  hand-built street grid — market square, Honin Road, Ganthus Road,
  Wayward/Parthos Roads — using a small BFS script built from parsing
  every room's `set_exits()` in `d/nopk/tirun/`, since the town is large
  enough that blind wandering wasn't practical); the North Forest
  (`d/nopk/standard/forest1-3`, reached via the north gate, a genuinely
  calm/monster-free newbie corridor by design); and Lodos (a full second
  city, reached via the `/d/coach/` inter-city coach system — `coach to
  lodos` from the western coach house, correct in-transit flavor text,
  arrival with newbie fare correctly free — money stayed at 600 gold
  throughout).
- **Safe-sparring found and used before real combat**: `d/nopk/tirun/
  fighter/dummy.lpc` (reached via `enter fighter hall` → south from
  the Sparring Hall) is this lib's designated safe target — its
  `attack dummy` handler is pure narration keyed off `random(this_player
  ()->query_skill("melee"))`, no real damage exchanged either direction;
  used repeatedly with zero HP loss before any real fight was
  attempted (none was attempted this pass — see Death/respawn below).
- **Skill/guild (class/subclass) acquisition, organic path**: walked to
  the mage hall (`enter mage hall` off East Honin Road), `preview` →
  `become mage` (class set, skill points 5→25), then BFS-navigated to
  the sorceror hall (`enter sorceror hall` off East Wayward Avenue),
  `preview` → `become sorceror` (subclass set, skill points →31,
  alignment flipped to Godly, title updated to "novice sorceror").
  `spells`/`skills` both rendered correctly afterward (a `missile`
  attack spell newly available, full skill-point table). **No separate
  admin-only shortcut command for class/subclass assignment was found**
  — grepped `cmds/creator/` for a `set`-style utility and found only a
  generic environment-variable `set` (unrelated); the only path to a
  class/subclass in this lineage is the `become` command inside the
  relevant hall, whether run by a mortal or (via a wizard's generic
  `force`) an admin. Documented honestly rather than guessing at a
  shortcut that doesn't exist.
- **`quit`, `debug.log` grep, reconnect after a real gap — 3 independent
  passes, specifically to re-verify §8.22 (found during onboarding)
  holds for an account other than the one onboarding tested**: (1)
  same-session quit+immediate reconnect — correct password accepted,
  full state (class/subclass/HP/money/skills) restored, zero new
  `debug.log` lines; (2) killed and rebooted the native driver entirely
  (picking up the `monument.lpc`/`statue.lpc` fix), reconnected — same
  clean result; (3) after that reboot, left one idle connection open
  for the full ~220-second long-sit window (below), THEN reconnected a
  real ~5 real-minutes-elapsed gap later — password accepted, full
  state restored again, zero new `debug.log` growth across the entire
  boot+idle+reconnect+quit cycle (`debug.log` line count identical
  before and after). This independently reconfirms §8.22's fix is not
  an artifact of the one account onboarding happened to test.
- **Shop/economy**: the weaponsmith shop (`enter weaponsmith shop` off
  Ganthus Road) correctly lists its repair-only service via `read sign`
  (100 gold/level of disrepair — no `list`/`buy` inventory verb, a
  repair-only shop by design, not a bug); the inter-city coach fare
  system (above) is a real, working economy transaction (newbie-tier
  fare correctly waived, gold unchanged) — a full paid transaction
  (mid/elite fare, or a buy-from-peddler transaction with `Rejik`, whose
  `reset()`-gated appearance in `square1` didn't line up with this
  pass's timing) was not reached; flagging this as **budgeted, not
  fully exercised**, per the project's own explicit fallback for
  shop/economy coverage.
- **Death/respawn**: **not verified live this pass** — time-budgeted
  out in favor of the long-sit watch and the 3-way reconnect
  re-verification above, both judged higher-value given this lib's
  already-known restore-path history. Flagging honestly as unverified
  rather than silently skipping it.
- **Long-sit boot watch (§10.0, native-driver equivalent)**: no WASM
  build exists for this lib yet (§ WASM status below), so used the
  native equivalent — rebooted fresh (with the `monument.lpc`/
  `statue.lpc` fix applied), opened one idle raw-socket connection, and
  sat through a full ~220-second window without logging in, while a
  wandering `errand boy` NPC's heart_beat continued triggering
  `reset()` on the (now-fixed) cemetery room in the background. Zero
  new `debug.log` entries during the entire window — confirms the fix
  above actually closed the only lazily-triggered failure this pass
  found, and surfaced no others.

## 深度功能测试（§10.7，2026-10-05）— 主控 author_file()/domain_file()

驱动的 mudlib_stats 包在主控载入时各调用一次 `author_file(<主控文件>)` 和 `domain_file("/")`，要求返回字符串。本库这两个 apply 只为 domains / realms 目录下的文件返回名字，其余返回 0，所以每次启动都打印 `author_file() in the master file does not work, using root_uid as fallback` 和 `domain_file() in the master file does not work, using bb_ui as fallback` 两行，网页版每位访客的终端里都看得到。`adm/obj/master.lpc` 改成与 fluffos 组织维护的 Dead Souls 上游（`deadsouls_fluffos`）相同的写法：其余文件的域返回 `"BACKBONE"`，作者返回 `"NONAME"`。域等于 backbone 域时驱动让对象沿用创建者的域，与返回 0 时相同；作者统计（`author_stats()`）多出一行 `NONAME`，汇总 realms 目录以外的对象（KB 06 §7.222）。用 `lpcc config.fluffos /nonexistent.lpc` 前后对比，主控载入段只少了这两行。

## 深度功能测试（§10.7，2026-10-06）— Windows 文本被当作 GB18030 解码（KB 03）

本库原文是 Windows 西文（cp1252）：弯引号 `’`、`é`、`»`、`ß` 这类字节在入库转码时被当成 GB18030，两个高位字节合成一个汉字（`owner抯`、`world抯`），单个高位字节则连同后面的 ASCII 字节一起被吃掉（`Aimeé went` 成了 `Aimewent`，存档里的字符串少了收尾引号）。`scripts/latin1_misdecode_repair.py pd --prefix beta-ii --encoding cp1252 --apply` 按 raw 逐行恢复，共 98 个文件（61 个存档、33 个 `.lpc`、几份帮助文档）。

- **四个玩家存档读不出来。** aximili、bahamut、popov、ramona 的别名里有 `Ç`、`å` 之类的键，被吃掉的引号让 `restore_object()` 报 `Illegal mapping format while restoring alias`，这四位无法登录。修复后 61 个改动的存档全部读得出（HEAD 下 57/61）。
- `doc/lpc/intermed/chapter1`（Descartes 的 LPC 教程）是 Mac Roman，`0xD5` 是 `’`，单独改正（cp1252 会给出 `Õ`）。
- `wizards/seeker/asciis.txt` 的 `A1A1` 真是 GB2312 全角空格，转码原本是对的，不改。
- 入库后改过的行脚本不动（23 行，都在房间描述里），其中 `抯` 一类第二字节为 ASCII 的汉字按字符还原为 `’s`（11 个文件）。旧信件里的 cp437 方块画（`圹圹`）不动。
- 改动的 33 个 `.lpc` 用 `lpcc --batch` 编译，32 个通过；`wizards/hermes/workroom` 在 HEAD 也载入失败，与本次无关。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py pd --fix`（3 万多个文件，单独跑；第一次被一小时的超时打断，先改了 `nosave` 函数——`static` 留下的 `nosave` 改成 `protected`，与 `private` 并列的去掉——再完整跑一遍）：无用局部变量 1081 个、裸 `return` 21 处、`varargs` 16 处等，共改动 681 个 `.lpc`。HEAD 与工作树分别加载（新进程）：621 -> 620，少的那个 `d/citrin/rooms/lake/20,4` 只删了两个没用到的局部变量，单独连载三次 HEAD 与工作树都通过，是批量加载的假象（KB 08 §10.13）。
未动：`wizards/danovae/extra/_catchip.lpc` 有一行被 `;` 截断的字符串，但那个变量之后没再用，接不接都一样。

启动时警告 68 -> 0；新进程登录（标题画面、新人物）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 10 处比较、8 处去后缀（如 `std/vault.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-10）— 编译警告整理

`scripts/lpc_warnings.py pd --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 755 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：686 -> 686 通过，无回退。启动时警告 0 -> 0；新进程登录（输入名字）正常。
（这一轮用分块扫描重跑：上一轮单次 `lpcc --batch` 中途死掉，只扫到 31936 个文件里的 2241 个；pd 的房间多，一个 VM 加载几百个就把内存吃到十几 GB，改成每批 600 个。）手改 `wizards/venenum/book.lpc` `set_size()`：每个分支里的 `int maxpages = 5;` 等是新声明的局部变量，遮住了同名的全局 `maxpages`，书的大小从来没被设上；改成给全局赋值 `maxpages = 5;`（该文件 HEAD 起就编译不过，属休眠内容）。新进程登录到 New Character 画面正常。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 4 处，返回类型/原型 64 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 5 个，只在 #if 分支用的声明移进分支 1 个文件；改动 63 个文件，HEAD 与工作树各载入一次无回退（63 objects; HEAD PASS 56, tree PASS 56; regress 0; newly loading 0），这些文件的警告 85 -> 6。

## 深度功能测试（§10.7，2026-10-11）：set_items 逗号键

- `d/old/citrin.old/rooms/` 三个房间 `set_items` 的键写成 `("grip", "hand grip")`，逗号只留最后一个名字；改为数组键 `({ ... })`（`std/room/items.lpc` 会展开数组键）。载入无回退。
- 2026-10-14: `adm/save/users/rid/seeker.o` held two Latin-1 bytes in `real_name`, so `restore_object()` stopped with `Invalid utf8 string`. `scripts/lpc_save_encoding.py` transcoded it from Latin-1 (KB 03 §4).

## Save files the onboarding transcode broke (2026-10-15, KB 03 §4.4)

`/adm/save/boards/spell_idea.o`, `/adm/save/letters/2/1249616752.o`, `/adm/save/users/rid/kenshiro.o`: the archive's Windows-1252 bytes (a `\x92` apostrophe, `¿`, `¡`) were run through `iconv -f gb18030 -c`, which dropped an undecodable byte together with the quote after it, so `restore_object()` stopped with `Illegal mapping format` and the object started empty. Re-decoded from raw/ as Windows-1252 (`scripts/lpc_save_encoding.py --from-raw`); the driver restores each one now (`scripts/lpc_save_restore_check.py`).

## Object paths with two leading slashes (2026-10-19, KB 06 §7.276)

2 file(s), 2 site(s) wrote an object path as `//…` (like `carry_object("//clone/cloth/hic_cloth")`): `/d/events/4thjuly2008/rooms/icystuff/final.lpc`, `/wizards/pyro/personal/fireball.lpc`. The driver these games ran on did not mind (the path was normalised first); this one hands the string to the master's `valid_read()` as written, securityd looks up `//clone`, the NPC's euid has no entry and the answer is `Read access denied.`: the NPC does not load. One slash now.

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/guildbak/newethereal/ethereal/mob/homer.lpc`（3 处）、`/d/guildbak/newethereal/mob/homer.lpc`（3 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/d/events/dragonaug2008/rooms/py/2.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 16 处）。改动：`/cmds/creator/_people.lpc`（2 处）、`/cmds/oldskills/_mudthrow.lpc`（1 处）、`/cmds/oldskills/_paralyze.lpc`（1 处）、`/cmds/oldskills/_roar.lpc`（1 处）、`/cmds/oldskills/_stun.lpc`（1 处）、`/cmds/skills/_mudthrow.lpc`（1 处）、`/cmds/skills/_roar.lpc`（1 处）、`/d/distopia/item/journal.lpc`（3 处）、`/d/nopk/tirun/clergy/druid/druid_grove.lpc`（1 处）、`/d/nopk/tirun/clergy/druid/druid_tree.lpc`（1 处）、`/d/nopk/tirun/clergy/druid/waterfall.lpc`（1 处）、`/d/nopk/tirun/warehouse.lpc`（1 处） 等 13 个文件。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## `tail` 指令：`tail(file)` 驱动里没有（2026-10-20，KB 06 §7.291）

`cmds/*/tail.lpc` 调用 MudOS 的 `tail()` efun，FluffOS 没有，指令编译不过。模拟 efun 文件里补了 `tail(file)`（Discworld 家族的兼容版：文件最后约 20 行，从完整的一行开始，存在返回 1；`scripts/lpc_add_sefun.py tail`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## `guild.h` 重新定义 `ROOM`（2026-10-20，KB 06 §7.306）

`std.h` 定义 `ROOM "/std/room"`，`domains/guild.h` 又把它定义成行会房间基类（586 个文件包含 `<guild.h>`），首次登录时加载行会房间就打印 45 次 `warning: Macro 'ROOM' redefined`。`guild.h` 里在 `#define ROOM` 前加了 `#undef ROOM`（取值不变）。

## 首次登录控制台与核心目录的警告清理（2026-10-20，KB 06 §7.306、KB 04 §6.10）

登录体检（`scripts/play_survey.py`）里 pd 的控制台先是 45 条 `Macro 'ROOM' redefined`（`domains/guild.h` 重新定义 `std.h` 的 `ROOM`，已在前一段处理），去掉后露出下面这些。`scripts/toolkit_fix.sh pd`（跳过 `/d/`、`/wizards/`、`/tmp/`，核心目录 1,751 个文件）：float 赋给 int 的 152 处（多数是 `percent()` 的结果）改成 `to_int()`（98 个文件，其中 `std/living.lpc:604`、`cmds/mortal/_score.lpc:9` 登录就会编译到），3 处继承顺序、4 个 `void` 返回、2 个覆盖函数的返回类型、2 个多余的继承；加载检查 104 个对象，HEAD 通过 95、改后通过 103，无回退，新能加载 8 个。`lpc_fix_macro_redef.py` 给 22 处重复的 `#define`（`SKILLS`、`BALANCE3_D`、`TREASURY_D`、`STATIC_SHIPS`）前加了 `#undef`，`lpc_fix_extra_semicolon.py`（新）去掉 9 个类定义/函数体后多余的 `;`（`adm/include/death_cl.h`、`combo_cl.h`、`faction_cl.h`、`funccheck_cl.h`、`recipe_cl.h`、`adm/daemon/identity_d.lpc`、`cmds/skills/obj/netherlash_ob.lpc`）。

真错误一处：`adm/daemon/identity_d.lpc:356` 的过滤函数写成 `if (n && c->name != c) return 0;`（拿名字和整个 `class ConnData` 比较，应为 `c->name != n`），驱动报 `!= always true because of incompatible types ( string vs class ConnData )`，身份守护进程根本编译不了，而 `std/user.lpc` 登录时就要用 `IDENTITY_D`。改正后能加载（本批 135 个对象的加载检查里新能加载 9 个）。

还留着的：`std/user.lpc:1580` 的 `query_autoload()` 同时来自 `/std/user/autoload.lpc`（`mixed *`）和 `/std/object.lpc`（`int`），返回类型不同，做不了无副作用的覆盖，保持原样；`oldcrypt()` 的弃用提示；`std/backpack.lpc`（`ARMOUR` 与 `BAG` 两条路径各带一份 `nomask clear_euid`，没有任何文件继承它）；`adm/daemon/` 里几个老守护进程缺头文件或宏（`finger.lpc` 的 `FOLDERS_D`、`alchemist_d.lpc` 的 `materials.h`、`link_d.lpc` 的 `link_info.h`），`/d/` 与 `/wizards/` 的 3 万个区域文件没有扫。

## 吟游诗人的三首歌不能编译：`function(object t, …)` 里写了 `$1`（2026-10-20，KB 06 §7.317）

`cmds/song/fools_ballad.lpc`、`noxious_chorus.lpc`、`wracking_reel.lpc` 里有 LDMud 风格的内联闭包 `function(object t, string p) { … }`，函数体里却用 `$1` 取第一个参数：`$N` 只属于 `(: … :)` 简写，`/cmds/song/wracking_reel.lpc:61:7: error: $var illegal inside anonymous function pointer.` 一共四处，随后一条语句 `Undefined variable 'tp'` 和语法错误，三首歌从来没有编译过。现在函数体用声明的参数名 `t`（三个文件各 4 处）；加载检查 HEAD 21 通过 / 3 失败，工作树 24 通过。

## `query_autoload()` 同时来自 autoload 模块和物件基类（2026-10-20，KB 06 §7.318）

`/std/user/autoload.lpc` 有 `mixed *query_autoload()`（要恢复的物品清单），`/std/object.lpc` 经 `/std/living` 带来 `int query_autoload()`（物品的 autoload 级别），玩家身体两个都继承：驱动取第一个并在每次编译玩家身体时警告 `query_autoload() inherited from both … using the definition in /std/user/autoload.lpc`（首次登录控制台就有）。驱动的选择本来就是想要的，所以在 `std/user.lpc` 末尾显式定义 `mixed *query_autoload() { return autoload::query_autoload(); }`，运行时行为不变，警告消失。

## `_backstab` 的编译警告：`dmg *= 0.85`（2026-10-20，KB 04 §6.10）

`cmds/skills/_backstab.lpc` 第 282 行 `dmg *= 0.85;`，`dmg` 是 int：驱动警告浮点被截成整数。改写成 `dmg = to_int(dmg * 0.85);`（结果与原来一样）。加载检查：通过，没有警告。

## 三个编译警告（2026-10-21，KB 04 §6.10）

`include/imc.h` 的 `imc_wizard()`：`if(!interactive(ob)) 0;` 缺了 `return`（上面的 `imc_archp()` 写的是 `return 0;`），改成 `return 0;`（非连线对象不再落到 `wizardp(ob)`）；`daemon/network.lpc` 的 `read_callback()`：`tmp + "";` 本意是 `tmp = "";`（`sscanf` 只匹配到第一段时 `tmp` 没被赋值，后面的 `explode(tmp, "||")` 会报错），改成赋值；`daemon/imc_d.lpc:404`：`if (split[2] == "accept") split[3] == "accept";`（注释写的是 “fixes autoconfigure”）把赋值写成了比较，改成 `=`。三条警告都消失（`imc`、`mudlist` 命令的控制台行）；`daemon/tmp/network.lpc` 是 `tmp/` 里的副本，没有改。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 32 个存档共 61 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/adm/save/boats/aerion.o`（2 处）、`/adm/save/boats/amria.o`（2 处）、`/adm/save/boats/amun.o`（2 处）、`/adm/save/boats/arial.o`（2 处）（等共 32 个存档）。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 4 条注册（3 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/guilds/lastsaints/armour/saints_rosary.lpc`（`read_board`、`report_posts`）、`/d/tombar/mon/candlestick.lpc`（`monter_hit`）、`/std/hm/castle.lpc`（`enter`）。最多的函数名：`read_board` 1 处、`report_posts` 1 处、`monter_hit` 1 处、`enter` 1 处。

## 注册到不存在函数的 `add_action`，第二轮：宏路径父类和静态解析不了的对象（2026-10-21，KB 06 §7.349）

第一轮的静态解析读不了经宏路径继承父类的对象（`#define ROOM STD_DIR "room/room"` 这类定义的正文以另一个宏开头）和它解析不了的继承，这些对象当作 `UNSURE` 没有扫；第二轮修了解析器，重扫并对这些对象在运行时问 `function_exists()`。`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 10 条注册（10 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/events/dragonaug2008/rooms/py/5.lpc`（`jump_north`）、`/d/freepk/merkkerri/demonquest/dquest10.lpc`（`salvation`）、`/d/guilds/dw/hall.lpc`（`fstart`）、`/d/guilds/lastsaints/objects/spare_hall_rooms.lpc`（`homeroom`）、`/d/guilds/lastsaints/rooms/armour_room.lpc`（`go_west`）、`/d/nopk/standard/lorroad2.lpc`（`read`）、`/d/nopk/tirun/electionhall.lpc`（`read`）、`/d/nopk/tirun/monastery.lpc`（`confess`）、`/d/nopk/tirun/nranch.lpc`（`touch`）、`/d/nopk/tirun/obj/misc/deliv_warehouse.lpc`（`read`）。最多的函数名：`read` 3 处、`jump_north` 1 处、`salvation` 1 处、`fstart` 1 处、`homeroom` 1 处。

## 守护进程里 `int clean_up()` 盖在基类 `void clean_up()` 上的警告（2026-10-21，KB 04 §6.10）

`/d/events/dragonaug2008/rooms/instance_d.lpc`、`/adm/daemon/instance_d.lpc`、`/daemon/door_d.lpc`、`/wizards/pyro/sandbox/queue_d.lpc`、`/wizards/pyro/assgn/implemented/door_d.lpc` 的 `int clean_up()` 覆盖 `/std/daemon.lpc` 的 `void clean_up()`，驱动编译时警告 `Function clean_up inherited from '/std/daemon.lpc' does not match current function in return type ( void vs int )`（共 7 处）。`clean_up()` 的返回值驱动会读（返回 0 就不再被询问，`void` 函数就是返回 0）：这几个守护进程靠 `return 1` 让驱动下次再来，数据清空后 `return ::clean_up()` 才销毁自己，所以不能改成 `void`；pd 里覆盖 `std/daemon` 的 `clean_up()` 是 `int` 和 `void` 各 6 个，基类也不好改。覆盖函数改声明为 `mixed clean_up()`：返回值不变，类型检查不再触发。重新加载这 5 个文件（连同本轮其他改动的文件共 15 个）：0 警告，无回退。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。95 个文件里 287 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 95 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 15 个，现在 71 个（新增可加载 56 个，回归 0 个）。

## 不带前导斜杠的物品路径：缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`carry_object("d/city/obj/jiasha")->wear();` 这类路径不带前导斜杠的写法在这个驱动里按根目录解析（`new("d/city/obj/changjian")` 能加载 `/d/city/obj/changjian`），所以和带斜杠的一样：文件不在压缩包里时 `new()` 返回 0，`->wear()` 在 0 上报 `Bad argument 1 to EFUN call_other()`，整个 NPC 加载不了。此前的保护工具把这种写法当作「相对当前目录，没法判断」跳过了。3 个文件里 3 处（`d/standard/frealmz/mob/anathar`、`d/standard/frealmz/mob/roger`、`d/standard/frealmz/mob/talon`）改成带保护的块（`scripts/lpc_guard_carry_object.py`）。 对这 3 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 0 个，现在 3 个（新增可加载 3 个，回归 0 个）。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 1 个子目录写日志：`log/log`（`std/bak2/user_new.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。测试对象里本库的 `log_file()` 什么也没写（探针对象没有写权限，`log_file()` 自己也不建目录），所以真实调用者会得到什么没有测出来。把 `log/log` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

4 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/d/standard/quest_room"->list_quests()`（`/d/freepk/merkkerri/jungle/gcity/gcity29.lpc`、`/d/nopk/arlon/room/fighter_hall.lpc`）→ `"/d/nopk/standard/quest_room"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。

## wizards volcano1 丢分号（2026-10-27，KB 04 §6.25 Also）

三份 `wizards/**/room/volcano1.lpc`（leviathas / nested leviathas / levi aciri）写成 `inherit ROOM` 后无 `;`，且 `::create()` / `set_*` 全无分号，驱动报 `unexpected L_BASIC_TYPE`。补回分号后可加载。同作者 `deatblade` 更残，未动。证明：HEAD catch 失败；改后加载并 `query_short` 正常。

## deatblade 丢分号 + wep/terra.h 错路径（2026-10-27，KB 04 §6.25 / KB 06 §7.359 Also）

三份 `wizards/**/wep/deatblade.lpc` 同样丢光分号，且 `set_short` 颜色串被折行。补回 `;` 并接好 short。另：`wep/terra.h`（及同错的 `item/terra.h`）把 `WEP`/`ARM` 指到不存在的 `weapons/`/`armour/`，`new(WEP "deathblade.lpc")` 得 0 后 `->move` 炸；改为与 `room/terra.h` 一致的 `wep/`/`arm/`（darktown 用本地前缀）。证明：HEAD 语法失败；改后三份均加载。

## manex tower8 缺 inherit 分号（2026-10-27，KB 04 §6.25 Also）

`wizards/manex/tower8.lpc` 写 `inherit ROOM` 后无 `;`，驱动无法编译。补上分号（空房间 stub 保留）。证明：HEAD 失败；改后加载成功。
