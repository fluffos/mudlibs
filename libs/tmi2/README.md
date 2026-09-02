# TMI-2 (tmi2)

TMI-2 ("The Mud Institute", version 2) is one of the historically significant, widely-copied English-language LPMud mudlibs of the 1992-1996 era. Its `std/` base classes, command-soul dispatch, and `/adm/`-rooted security-daemon layout (`master`, `access`, `groups`) were inherited and re-derived by a large family of later mudlibs -- this project's own catalog already refers to a "TMI-2/Falcon family" of descendants because of how far this lineage's conventions spread through the wider LPMud ecosystem.

This port is the "famous TMI-2 quad" release itself: a landing zone with
a general-purpose bulletin board, a network-discussion room (Intermud-3),
an MudOS-driver-discussion room, a bug-report room, and a link down into
`/d/Fooland`, plus the full TMI-2 wizard toolset (file/object inspection
commands, the channel system, the student/teacher tutorial subsystem,
FTP and HTTP daemons, a `resolv_str`/`resolv_ref` scripting mini-language
for wizard reference variables) and character creation covering 13
playable races (dwarf, elf, gnome, human, orc, troll, halfling, sprite,
shadow, ent, siren, skeleton, zombie).

## Provenance

The original `lpmuds.net` distribution site is now defunct. This archive
(`tmi2_fluffos_v3.zip`, a maintained, already-FluffOS-adapted release)
was recovered from the Wayback Machine snapshot
<https://web.archive.org/web/20160306040625if_/http://lpmuds.net/files/tmi2_fluffos_v3.zip>
and content-verified (real 1996-dated LPC source) before porting.

## Highlights

- The most severe porting bug: `master.lpc`'s `domain_file()` function
  crashed with an uncaught "Array index out of bounds" on the very first
  boot-time call the driver itself makes (`master::domain_file("/")`),
  because this driver's `__SANE_EXPLODE_STRING__` build makes
  `explode("/", "/")` return an empty array where old-style MudOS
  returned a two-element one with empty strings -- and the function's
  existing null-check didn't cover the empty case. The failure happened
  so early in the driver's own boot sequence (before any mudlib error
  handler is installed) that the top-level message was just "The
  simul_efun and master objects must be loadable", with the real cause
  buried in a `/log/runtime` trace the driver never got a chance to
  surface before aborting. Fixed by widening the array-emptiness guard.
  See `NOTES.md` for the full diagnosis.
- A second compile-blocking bug: two real, live-loaded files
  (`adm/daemons/channels.lpc`, the in-game channel system, and
  `adm/daemons/ref_d.lpc`, the wizard reference-variable daemon) used
  `ref` as an ordinary variable/parameter name -- a name this driver
  reserves as a pass-by-reference-parameter keyword. Renamed the
  conflicting identifiers; see `NOTES.md` \S2.
- TMI-2's file-permission system is a separate `/adm/etc/groups` +
  `/adm/etc/access` group-membership scheme, independent of the in-game
  "wizard status" flag new characters can be auto-granted at creation --
  the admin account needed an explicit `(root)` group entry added before
  `update`/file-write access actually worked. See `NOTES.md` \S3.

## Registration flow

`name` -> confirm (`y`/`n`) -> password -> confirm password -> gender
(`male`/`female`/`neuter`/`hermaphrodite`) -> race (`dwarf`/`elf`/
`gnome`/`human`/`orc`/`troll`/`halfling`/`sprite`/`shadow`/`ent`/
`siren`/`skeleton`/`zombie`) -> email address (`user@host` form
required) -> real name -> the game world.

## Admin account

- **id**: `fluffos`
- **password**: `FluffOS2026Admin`
- **rank**: automatic in-game wizard status (first character created)
  plus explicit `(root)` file-group membership added in
  `adm/etc/groups` for real read/write access.

Registered through the normal registration flow (as the very first
character on this install), then given root file-group membership.
Verified live: `update /cmds/wiz/_goto` and `update /adm/daemons/quota`
both succeed ("Updated and loaded.").

## Live network connection at boot

Like `imud` in this collection, booting this lib makes a real outbound
connection to the public Intermud-3 router network (a hardcoded router
IP in `include/net/i3.h`) and exchanges a real mudlist/registration with
it -- confirmed by seeing dozens of real other muds (with real IPs) come
back in the saved I3 state after a boot. This is correct, intended
upstream behavior, but means this lib should not be swept into
high-frequency automated re-boot testing loops the way fully-sandboxed
libs in this collection can be. See `NOTES.md` \S5.

## Status

Boots clean: zero compile errors and zero uncaught runtime errors in
`log/runtime` across repeated fresh-driver boots. Full registration (a
brand-new character all the way through race/gender/email selection into
the actual game world), `look`/`score`/`inventory`/`quit`, re-login as an
existing character, and wizard-level `update` all verified end-to-end
with a real driver session and a raw socket client.

A compile-sweep tail of 28 files (of 715) remains beyond the fixes
above -- confirmed to be either unreferenced/dead legacy content
(personal wizard scratch files, dated backup copies of live files,
documentation stubs, a subsystem explicitly disabled in the archive's
own shipped preload file) or one likely lpcc-harness-only artifact (a
`create()` guard that self-destructs outside its expected caller, the
same known class of false-FAIL this project has documented before). See
`NOTES.md` \S4 for the full breakdown. None of it blocks a real boot or
blocks play.

WASM status: not attempted this session (`wasm_status` left `""`).

## Local run

```
cd libs/tmi2
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40220**.
