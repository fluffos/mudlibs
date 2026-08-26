# Dead Souls I (dsI)

An early, distinct generation of the Dead Souls object library. Several
files in this archive self-identify as "Dead Souls V" or "the Dead
Soulsr1/r2 Object Library" (circa 1996-98), and per lpmuds.net's own
description this snapshot is closer to Nightmare IV than to the later
3.8.6-era Dead Souls already in this collection (`ds386`,
`deadsouls_fluffos`). Confirmed genuinely distinct by a structural and
byte-level diff -- see `NOTES.md` \S1.

Source: a maintained, already-FluffOS-adapted archive (`dsI.zip`) from
lpmuds.net, a now-defunct LPMud archive site. Recovered via the Wayback
Machine
(<https://web.archive.org/web/20160306035507id_/http://lpmuds.net/files/deadsouls/dsI.zip>)
since the original site is down. Slug `dsI`, number 178, port 40225.

## Highlights

- A genuine, working first-boot admin-setup wizard (`secure/lib/
  connect.lpc`/`connect.real`): connecting to a fresh install walks
  through name/password/gender/display-name/email/real-name, then a
  **race selection** step (`list`/`help RACE`/`pick RACE` -- 17 races
  on offer) before the mud's real, ongoing login/registration flow
  self-installs in its place. See `NOTES.md` for how this project's
  admin account was created through this exact flow.
- Two shipped domains: `default` (a small starting area) and `Ylsrim`
  (an example town with a pub, armoury, weaponry, a jar-and-lightning-
  bug minigame object, and a couple of "broken" disease-item examples)
  -- a much smaller content footprint than `ds386`/`deadsouls_fluffos`'s
  8 domains, consistent with this being an earlier codebase generation
  rather than a smaller snapshot of the same one.
- **Makes a real outbound network connection at boot**: `daemon/
  intermud.lpc` is preloaded by default and connects to a real
  Intermud-3 nameserver (`149.152.218.102:23`, "*yatmim") ~2 seconds
  after boot -- confirmed live (`ss -tnp` showed an ESTABLISHED
  connection during this port's own test boot). This is genuine
  upstream functionality, not a bug, and both existing Dead-Souls-
  lineage siblings in this collection preload the identical
  `daemon/intermud` with `DISABLE_INTERMUD` defaulting to `0`
  (enabled) too -- but per this project's established safety-flagging
  convention (see `imud`, `foundation2`), this means dsI should **not**
  be swept into high-frequency automated re-boot/deep-test loops the
  way most of this corpus safely can be, since each boot is a real
  network event against a real third party.
- The highest-impact bugs found while porting this to FluffOS: a batch
  of missing/broken `LIB_*` macros in `secure/include/lib.h`
  (`LIB_UNDEAD` was gated behind a garbled, always-false `#ifdef Dead
  SoulsLPMud`, breaking `inherit LIB_UNDEAD;` in `lib/body.lpc` and
  therefore this codebase's *entire* living-creature class hierarchy --
  body -> race -> living -> npc/sentient -- everything a player or NPC
  is built from) and the old-MudOS `TYPE array NAME` declaration
  dialect (370+ sites across 107 files, including the command-dispatch
  table's own return type). Full list in `NOTES.md`.

## Registration flow

`name` -> "Do you really wish to be known as `<Name>`? (y/n)" ->
password (5+ letters) -> confirm password -> gender (`male`/`female`)
-> display name (blank = default) -> email (**required**, must look
like `user@host`) -> real name (optional, blank OK) -> race selection
(`list` to see options, `pick <race>` to choose) -> two news screens
(<return> to continue) -> lands in `/domains/default/room/start`.

The very first account ever created goes through a separate, one-time
admin-installation wizard instead (see above) -- every account after
that uses the flow described here.

## Admin account

- **id**: `fluffos`
- **password**: `fluffwiz123`
- **privilege**: `ASSIST` + `SECURE` group membership
  (`secure/cfg/groups.cfg`), account file under `secure/save/creators/`
  (this codebase's on-disk creator/wizard marker -- see `NOTES.md`
  \S4 for `creatorp()`'s exact check)

Created through the mud's own first-boot installation wizard (see
`NOTES.md`), not a save-file hand-edit. Verified live: `who` lists
Fluffos under "Arch:", login shows both Creator and Admin news
sections, and `update <path>` (this project's canonical ACL/compile-
permission smoke test) succeeds both with no argument (updates the
current room) and with an explicit target file.

## Status

Boots clean, zero fatal errors. Verified live with a real driver
session and a raw socket client: the first-boot admin installation
wizard, a brand-new ordinary character's full registration (including
race selection), and `look`/`score`/`who`/`update`/a clean `quit` all
producing correct output.

576 of 585 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep; the 9 that don't are all non-preloaded, non-boot-critical
pre-existing archive gaps (2 truncated/corrupted source files, a
missing library component, an abandoned feature, a missing header, a
foreign-codebase API mismatch, and a wizard's leftover debug scratch
file) -- see `NOTES.md` \S6 for the full breakdown.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/dsI
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40225**. Note the Intermud-3 outbound-connection caveat
above before repeated/automated boots.
