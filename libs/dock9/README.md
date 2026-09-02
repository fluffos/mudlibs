# Dock 9 (dock9)

A small English-language LPC mudlib built on the same LPUniversity/ Sapidlib teaching-engine base as this project's `lpuni` -- a complete login/registration/security/command-dispatch/help/mail/news/channel/ Intermud-3 engine, plus a small, genuinely original starting area: the dock town of Trepi.

Source: [`dyher/dock9`](https://github.com/dyher/dock9) on GitHub. Slug
`dock9`, number 964, port 40266.

## Highlights

- **The bespoke content**: `areas/trepi/docks/` -- Dock 9 itself (the
  mud's own namesake starting room), a network of numbered docks (7, 8,
  10, 11, 12) connected by piers, a shipping/cargo area, and a helpful
  sailor NPC who greets new arrivals with real dialogue. Real
  author/date comments throughout, real room descriptions and exits --
  not a copy of `lpuni`'s own starting area.
- There is no combat/stats system at all, same as `lpuni` -- no `score`
  command to test.
- **Dock 9 makes a real outbound network connection at boot**: its
  Intermud-3 module connects to the public `*i4` chat router within a
  few seconds of every boot. Genuine upstream functionality, not a bug
  -- but avoid scripting repeated/automated boots of this lib (see
  `NOTES.md`).
- Porting this surfaced the same high-impact FluffOS-compat bugs found on
  `lpuni` (this driver's `PACKAGE_UIDS` support needing
  `get_root_uid()`/`get_bb_uid()`/`creator_file()`; the `.c`-to-`.lpc`
  rename side effect breaking `update`/`clone`/`dest`/`clean`/`goto`/
  `ls`/`more`'s filename-suffix checks) plus one new one: a fresh
  player's very first save could fail outright if their name's first
  letter had never been used before (`/data/users/<letter>/` buckets
  aren't pre-created for every letter in this archive). Full details in
  `NOTES.md`.

## Registration flow

`Please select a name:` -> (new account?) `Would you like to create it?`
`yes` -> password -> confirm password -> public e-mail address ->
`[Hit any key to continue]` -> `[Hit enter to continue]` -> lands in
**Dock 9**, the starting room.

Names may only contain the letters a-z (no Chinese support -- this is an
English-only engine, same as `lpuni`).

## Admin account

- **id**: `fluffos`
- **password**: `MudAt2026`
- **privilege**: admin (seeded manually into `/adm/etc/groups` and the
  account's saved command-path list -- this archive's own one-shot
  first-boot admin flag had already been consumed by the original
  developers; see `NOTES.md` for exactly how it was granted).

Verified live: `update <path>` against a real `adm/obj/master.lpc` file
succeeds.

## Status

Boots clean: zero compile errors on a fresh driver boot, zero entries in
`log/debug.log`. Verified live with a real driver session and a raw
socket client: fresh registration all the way into the world, `inventory`/
`help`/`look`/`ls`/`news` as a brand-new player's first commands,
movement through the full bespoke Trepi/docks area (with the greeter NPC
and real room content), the admin `update` command, a clean `quit`, and a
successful reconnect. 207 of 220 `.lpc` files pass a full
`lpcc_check.sh` batch compile sweep; the 13 that don't are all either
non-LPC HTML templates that merely share the `.lpc` extension, files
meant to be `#include`d into `simul_efun` rather than compiled standalone,
or an object whose `create()` legitimately needs a live player context --
see `NOTES.md` \S6 for the full triage.

WASM status: not attempted (`wasm_status` left `""`).

## Local run

```
cd libs/dock9
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40266**.

**Note**: booting this lib makes a real outbound network connection (see
Highlights above) -- avoid scripting repeated/automated boots.
