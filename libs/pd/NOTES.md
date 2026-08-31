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

## LPC formatter (§9)

**Not run** — `node` is not installed in this environment/session, so
`~/src/fluffos/tools/lpc-syntax/bin/format-corpus.mjs` could not be
invoked on the ~200 files edited during this onboarding. Flagging
explicitly rather than silently skipping, per the project's own
discipline about reporting real tool state.
