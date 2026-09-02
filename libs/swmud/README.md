# Star Wars Mud (swmud)

A Star Wars-themed LPC mudlib built as an extension of the Lima mudlib
(<https://limalib.dev>, FluffOS's own official reference/framework
mudlib). Its own README describes it exactly: "This project only
includes additions and changes to the base mudlib. It must be installed
over the current Lima mudlib." So that's how it's built here: a full
copy of this project's already-converted `libs/lima/work/` (164, port
40212) with swmud's own ~980-file tree overlaid on top (852 new files,
233 overriding same-path Lima files).

Source: `git clone https://github.com/coupdeforce/swmud` (last pushed
2016-02-16, commit `cf33a51`). Slug `swmud`, number 180, port 40227.

## Highlights

- A from-scratch Star Wars race roster (13 playable races: alderaanian,
  corellian, defel, ithorian, jawa, lorrdian, mon calamari, nabooan,
  tatooinian, twi'lek, verpine, wookiee, ysanna -- several of them
  distinct human ethnicities from different planets), its own combat/
  limb/wound system (`std/adversary/*`), guild classes (jedi, smuggler,
  bounty hunter, diplomat, engineer, physician, slicer, assassin,
  merchant), a crafting/manufacturing system, and item trees for weapons,
  armor, and lightsabers -- all genuinely new content built on top of
  Lima's engine (parser, security model, wish shell, etc).
- Real character creation: race selection -> point-buy attributes ->
  dominant hand -> Imperial/Rebel/Neutral team alignment -> lands in the
  game with a starting body.
- Porting it surfaced a large cluster of dropped macro definitions
  (mudlib.h/classes.h/commands.h/daemons.h/config.h each independently
  rewritten by swmud, apparently trimmed by hand at some point without
  checking every caller still in the tree) and one genuine ordering bug
  in the character-creation code that crashes the very first player ever
  to register on a fresh install. Full list in `NOTES.md`.
- The real Star Wars starting area (`/d/coru/main`, "Coruscant") was
  never included in this archive at all -- confirmed absent from both
  the git history and the raw clone. Players land in a real, working
  fallback room (`/d/common/void`, "Void") instead; see `NOTES.md`.

## Registration flow

`new name` -> "Is '<Name>' correct?" -> password -> confirm password ->
gender (`male`/`female`) -> email -> real name -> homepage (optional) ->
race selection (type a race name, or `list`/`help races`/`help stats`)
-> point-buy attributes (`a <stat> [n]` / `s <stat> [n]`, `done` when
satisfied) -> dominant hand (`left`/`right`) -> team (`imperial`/`rebel`/
`neutral`) -> lands in Void with a starting body, 1000 XP, and a
`$N the Bantha Fodder` title.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`

Created through the mudlib's own real first-boot bootstrap (Lima's
"whoever registers first on an empty install becomes admin" convention,
inherited by swmud's `sw_body_handle_new_logon()`) -- not a save-file
hand-edit. Verified live: `who` shows Role `Admin Wizard`; `update
/std/race/wookiee` and `admtool` (including its wizard-gated `priv 1`
submenu) both succeed.

## Status

Boots clean. Verified live with a real driver session and a raw socket
client: full registration (both a wizard-bootstrap account and a second,
ordinary account), race selection across multiple races, point-buy
attribute allocation, `look`/`score`/`who`/`inventory`, admin `update`/
`admtool`, and a clean `quit`, all producing correct output.

1731 of 1860 `.lpc` files pass a full `lpcc_check.sh`-style batch compile
sweep. Nearly all of the 129 that don't are orphaned Lima demo content
(`domains/`'s stock example rooms/monsters/spells, `std/sword.lpc`,
`std/race/unused/troll.lpc`, etc. -- content swmud's own game world never
uses and that predates this port) hitting the same "swmud rewrote the
item/combat API out from under Lima's original demo files" incompatibility
documented repeatedly in `NOTES.md`. See `NOTES.md` for the full
breakdown and what's left unfixed on purpose.

WASM status: `noboot`. The specialized Lima-flavor WASM driver (built in
`~/src/fluffos-lima` the same way as the native one) boots this lib's
content cleanly -- registration, race selection, and world entry all
verified live -- but the deployed site packages every lib against one
shared WASM driver binary with no per-lib driver override mechanism, so
the site itself cannot actually run it this way. See `libs/lima/NOTES.md`'s
`wasm_status 审计` section and this lib's own `NOTES.md` for the full
investigation; this is a site-infrastructure gap, not a defect in swmud
itself.

> **⚠️ Makes a real outbound network connection at boot.** `daemons/
> imud_d.lpc` preloads and connects to the public Intermud-3 router
> network at every boot (`ADMIN_EMAIL` in `include/config.h` is a real-
> looking value, so Lima's placeholder-based protective guard doesn't
> block it). Do not include this lib in high-frequency automated re-boot
> loops. See `NOTES.md`.

## Local run

```
cd libs/swmud
~/src/fluffos-lima/build-debug/src/driver config.fluffos
```

**Important**: this lib needs the same specialized Lima-flavor driver
build as `libs/lima/` (`~/src/fluffos-lima/build-debug`, built with
`NO_ADD_ACTION`/`NO_WIZARDS`/`NO_LIGHT` defined, `OLD_ED`/`PACKAGE_UIDS`
undefined) -- it will NOT boot on this project's shared default driver
at `~/src/fluffos/build-debug`. See `libs/lima/NOTES.md` for how that
driver was built, if the checkout needs to be recreated.

Game port: **40227**.
