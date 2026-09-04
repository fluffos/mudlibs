# Merentha (merentha)

Merentha is a classic English-language LPMud lib explicitly based on the popular Nightmare 3 lib -- per its own description, aiming for "the Nightmare feel and robustness without the complications of verbs or weird lfun names." This collection already carries `nightmare3` (160) itself, so the two are worth comparing side by side.

## Highlights

- New characters wake in a race-selection limbo room: a large circular
  chamber lined with wall compartments, each holding a frozen male and
  female body of one race. Reading the sign there explains the
  `become <gender> <race>` command, offered across six races: human,
  giant, gnome, elf, dwarf, and fairy.
- After `become`, characters drop into **Cabeiri**, the mudlib's own
  shipped starting town -- a central square with fighter, mage, healer,
  and monk guild halls, plus a general supply shop.
- A full skill-point system: 30+ named skills (swordplay, archery,
  alchemy, healing, bargaining, stealth, and more), a limb-based body
  model, and a from-scratch stat/vitals system (Health/Magic/Stamina).
- The full `/cmds/admin` wizard toolset (file inspection, `update`,
  object manipulation) plus a local peer-mud discovery daemon
  (`daemon/network.lpc`) and an Intermud client scaffold.

## Provenance

The original `lpmuds.net` distribution site is now defunct. This
archive (`merentha_fluffos_v2.zip`, a maintained, already-FluffOS-adapted
release) was recovered from the Wayback Machine snapshot
<https://web.archive.org/web/20120225071653id_/http://lpmuds.net/files/merentha_fluffos_v2.zip>
and content-verified before porting.

## What was fixed

Only one driver-compatibility fix was needed anywhere in the ~140-file
mudlib: this driver build requires `get_root_uid()`/`get_bb_uid()`
applies on the master object (`PACKAGE_UIDS` support), which this
archive never defined -- the driver otherwise exits immediately after
loading the master object, before any mudlib content ever runs. Fixed
by porting the same two-line pair already used by the closely-related
`nightmare3` lib in this collection. See `NOTES.md` for the full
diagnosis, plus a documented (not fixed, out of scope) cosmetic display
glitch in the `score`/inventory panel border rendering.

## Registration flow

`name` -> confirm keep name (`y`/`n`) -> password (4-8 characters) ->
confirm password -> name capitalization format (default: capitalized
name) -> straight into the game world's race-selection room ->
`become <gender> <race>` (e.g. `become male human`) -> Cabeiri.

## Admin account

- **id**: `fluffos`
- **password**: `Mud2026`
- **rank**: administrator (`__Position` set to `"admin"` in the
  account's save data -- any value other than the literal `"player"`
  grants admin here).

Registered through the normal registration flow, then granted admin by
editing the account's own save file directly (this lineage's
`set_position()` setter is itself gated behind already-being-an-admin).
Verified live: the login banner shows "You are logged in as an
administrator", and `update /cmds/admin/update` succeeds.

> Warning: `Mud2026` is a public default password for local play only.
> Change it before exposing this host publicly.

## Status

Boots clean: zero fatal errors, a compile-sweep of 142/143 files
passing (the one non-pass is an inert plain-text documentation file
misnamed with a `.lpc` extension by this project's blanket rename, not
real LPC source -- see `NOTES.md`). Full registration, race/gender
selection (`become male human`), `look`/`score`/`inventory`/`quit`, and
re-login as a returning character all verified end-to-end with a real
driver session and a raw socket client. Admin account verified with a
wizard-only command.

WASM status: **playable**. Login as `fluffos`, `look`, and `score` are
verified under the shared WASM driver (`NOTES.md` WASM status update).
Play: https://mudlibs.fluffos.info/merentha/

## Local run

```
cd libs/merentha
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40223**.
