# Dead Souls 3.0 (dsIII)

The real, self-identified "Dead Souls" object library at its 3.0 point release -- released 2009-12-30, signed Cratylus @ Dead Souls (see `doc/RELEASE_NOTES`). A genuinely distinct release from the other four Dead Souls entries already in this collection (`dsI`, 1996-98 Nightmare-IV-era; `dsII`, 2006's "Dead Souls II"; `ds386`/ `deadsouls_fluffos`, the 2014-era 3.8.6 generation) -- but the CLOSEST of the four to `ds386`/`deadsouls_fluffos` by a wide margin: 90.8% of shared files are byte-identical, and `secure/daemon/master.lpc` differs from `ds386`'s by only 8 trivial lines. Best understood as an early snapshot of the exact same "3.x" codebase branch that later became 3.8.6, captured a few point releases and several years earlier -- see `NOTES.md` \S1 for the full byte-level comparison against all four siblings.

Source: a ZIP archive from mudbytes.net, a now-dead site. Recovered via
the Wayback Machine
(<https://web.archive.org/web/20190802014424id_/http://mudbytes.net/files/download/2733/>)
since the original site is down. Slug `dsIII`, number 182, port 40229.

## Highlights

- Seven shipped domains: `default`, `town`, `Ylsrim`, `campus` (an LPC
  University area), `cave`, `examples`, and `Praxis` -- a strict subset
  of `ds386`'s 9 (missing only `amigara` and `learning`, added in later
  point releases).
- A working first-boot admin-installation wizard
  (`secure/lib/connect.lpc`): name/password/gender/display-name/
  real-name/email, then shuts the mud down (same as `ds386`) -- a
  restart is required before logging in as the new admin.
- Full ordinary-player registration includes an age gate ("Are you 13
  years of age or older?"), then a **race-selection** step (`list`/
  `help RACE`/`pick RACE` -- 8 races: dwarf, elf, half-elf, half-orc,
  halfling, human, orc, poleepkwa).
- **Strict English-only name validation** (`A-Z a-z ' -` only, with an
  explicit rejection message) -- this archive cannot register a Chinese
  character name; a real ASCII test account (`Qinbing`) was used
  instead for verification, same adapted bar as `ds386`'s own testing.
- **Makes THREE independent real outbound network connections** --
  confirmed live, more than any other Dead Souls-lineage lib in this
  collection:
  1. IMC2 (`secure/daemon/imc2.lpc`, preloaded) -- a real socket to a
     live IMC2 hub a couple seconds after boot.
  2. Intermud-3 (`daemon/intermud.lpc`, preloaded) -- a second real
     connection attempt.
  3. **NEW, and automatic on every single boot with zero player
     interaction**: `secure/daemon/autoexec.lpc` (itself preloaded)
     fires `secure/cmds/creators/dsversion.lpc`'s update-check one
     second after boot, which fetches `doc/RELEASE_NOTES` fresh from
     `dead-souls.net` over a real HTTP connection -- confirmed live on
     a bare idle boot with no login at all. The fetched content shows
     dead-souls.net is itself STILL LIVE (release notes through 2020),
     unlike mudbytes.net (this archive's actual download source, which
     really is dead). A related creator command,
     `secure/cmds/creators/rss.lpc`, has the same eager network
     behavior and fires merely from being LOADED -- which an
     `lpcc --batch` compile sweep of this lib will do, meaning **even a
     bare compile sweep of this lib makes real outbound network
     connections**, not just a live boot. See `NOTES.md` \S5 for the
     full detail. **Do not sweep this lib into high-frequency automated
     re-boot OR re-compile loops** -- same safety-flagging convention as
     `dsI`/`dsII`/`imud`/`foundation2`, extended here to cover
     `lpcc_check.sh` sweeps too.
- The archive's own `secure/cfg/groups.cfg`/`secure/include/config.h`
  already shipped with the correct `ADMIN`/`DEBUG_NAME` placeholder
  tokens (unlike `dsII`'s copy, which had the original author's real
  name hardcoded) -- no hand-fix needed for the admin-installer's
  group-membership scrubbing here.
- Nearly every driver-compat bug found while porting this
  (`get_root_uid()`/`get_bb_uid()`/`creator_file()`, the
  `log_error()`-during-compile recursion, a stale `runtime_config.h`
  slot-numbering mismatch, `OLD_ED` vs. the split editor API, `__DIR__`/
  `__FLUFFOS__` macro collisions, a mistyped `LIB_REMOTE` path,
  `SetLong()`/`SetExternalDesc()`/`SetInternalDesc()` declared too
  narrowly, `daemon/books.lpc`'s array-vs-mapping mismatch, a broken
  `set_pre_exit_functions()` call) turned out to be byte-identical to
  bugs already found and fixed while porting `ds386` -- ported that
  fix catalog wholesale rather than rediscovering it. Full list, plus
  the handful of genuinely new findings (a mixed-encoding curse-word
  table, several `TYPE array NAME`-dialect shapes `ds386`'s own sweep
  didn't need to handle), in `NOTES.md` \S3-4.

## Registration flow

`name` -> "Do you really wish to be known as `<Name>`? (y/n)" -> "Are
you 13 years of age or older? (y/n)" -> password (5+ letters) ->
confirm password -> gender (`male`/`female`/`neutral`/`none`) -> email
(required, validated as `user@host`) -> race selection (`list` to see
options, `pick <race>` to choose) -> news screens (<return> to
continue) -> lands in `/domains/default/room/` (the default domain's
start room).

The very first account ever created goes through a separate, one-time
admin-installation wizard instead (see above) -- **the mud shuts down
after that wizard completes**, and every account after the restart uses
the normal flow described here.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: `SECURE`/`ASSIST`/`ELDER`/`TEST`/`INTERMUD`/`BUILDER`/
  `TELNET`/`EMOTES` group membership (`secure/cfg/groups.cfg`), account
  file under `secure/save/creators/f/fluffos.o`

Created through the mud's own first-boot installation wizard; no manual
group-membership fix needed (see Highlights above). Verified live:
`score` shows the correct character sheet, and `update` (this project's
canonical ACL/compile-permission smoke test) succeeds with `Ok`.

## Status

Boots clean, zero fatal errors. Verified live with a real driver session
and a raw socket client: the first-boot admin installation wizard
(including the mud's self-shutdown-after-install), a restart, admin
login, a brand-new ordinary character's full registration (including
the age gate and race selection), a distinct reconnect-login code path,
and `look`/`score`/`update`/a clean `quit` all producing correct output
for both accounts.

2282 of 2291 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep (99.6%); the 9 that don't are all pre-existing non-bugs or
compile-sweep-only eval-cost artifacts (a deliberate author anti-load
trap, two builder-tool scaffolding templates, two confirmed-harmless
isolated-compile warning failures, two confirmed batch-eval-cost
artifacts that pass standalone/live, one genuine but pre-existing and
non-blocking content-side performance bug in the `cave` domain's orc
NPC race setup, a missing `LIB_CAPTURE` library component, and a
missing `opcprof()` efun) -- see `NOTES.md` \S6 for the full breakdown.

WASM status: **playable**. Shared WASM driver (`secure/sefun/sockets.lpc`
already stubbed). Admin login (`fluffos` / `Mud@2026`) into Fluffos'
workroom, plus `score` / `quit`, verified with `scripts/wasm_client.js`.
Play: https://mudlibs.fluffos.info/dsIII/

## Local run

```
cd libs/dsIII
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40229**. Note the THREE outbound-network-connection caveats
above (two at every boot, one also from a bare compile sweep) before
repeated/automated boots or `lpcc_check.sh` runs.
