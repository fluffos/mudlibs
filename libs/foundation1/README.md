# Foundation I (foundation1)

A stripped-down, classic Nightmare-3.3-derived LPC library, released by George Reese ("Descartes of Borg") in April 1995. Per its own shipped `README`: "This LPC library is designed very much for people who know what they are doing. Unlike Nightmare, it does not come with any configuration script to get you started, a combat system for a fantasy MUD, or a starter area." Foundation I is a bare engine (login/ registration, security, command dispatch, help, mail, message boards, Intermud-3) meant as a clean base for LPC programmers to build their own game on top of -- not a playable-out-of-the-box game world.

This is the direct, earlier ancestor of this collection's existing
`foundation2` (a separate, more developed later release by the same
author -- Foundation I's own `README` says explicitly that its
documentation was due to be "customized for Foundation II, due May 15"
[1995]). The two are distinct codebases with real, independently-drifted
differences (see `NOTES.md`), not duplicates of each other.

Source: recovered from the MUDBytes File Repository (mudbytes.net, file
#1043) via the Wayback Machine, since the live download endpoint is gone.
Slug `foundation1`, number 946, port 40248.

## Highlights

- A tiny shipped starting area: one room, `domains/Standard/center` (the
  "Pool Room" -- a softly-lit cavern with glowing lichen and magic pools)
  plus a linkdead-holding "freezer" room. An optional `domains/Examples`
  teaching content tree references an incompatible, differently-named
  room/item API from a different snapshot of this engine and doesn't
  compile as shipped -- a pre-existing content mismatch (same shape as
  `foundation2`'s own two incompatible teaching trees), not something
  this port introduced or fixed.
- The highest-impact bugs found while porting this to FluffOS: missing
  `get_root_uid()`/`get_bb_uid()`/`creator_file()` master applies broke
  loading nearly every object in the mudlib (this driver's `PACKAGE_UIDS`
  support requires them), a `.c`-to-`.lpc` rename side effect in the
  command-dispatch table's filename-slicing arithmetic silently corrupted
  every ordinary player command's lookup key, and the reserved-word
  collisions `ref`/`class` (this driver's `REF_RESERVED_WORD` option and
  its native `class` struct type) broke the player body and a dead
  scaffolding file respectively -- all fixed, full details in `NOTES.md`.
- Foundation I makes a real outbound network connection attempt toward
  the historic Intermud-3 router a couple of seconds after every boot
  (`daemon/intermud.c`, preloaded by default) -- genuine upstream
  functionality (almost certainly against a long-dead host today), not a
  bug, flagged in `NOTES.md`.

## Registration flow

`new name` (lowercase letters only, 2-15 chars) -> "Do you really wish
`<name>` to be your name? (y/n)" -> password (5+ letters) -> confirm
password -> gender (`male`/`female`) -> display name (blank = default) ->
email (**required**, must look like `user@host`) -> real name (optional,
blank OK) -> a news screen (`<return>` to continue) -> lands in the
Standard domain's starting cavern.

There is no `score` command anywhere in this minimalist archive (matching
its own README's "no ... stats system" description) -- `status` is the
closest equivalent, printing `hp`/`sp`/`mp`/`experience`.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: `(SECURE)` group membership
  (`secure/cfg/groups.cfg`)

Created through the mud's own normal registration flow (not a save-file
hand-edit) and granted access by adding it to the existing `(SECURE)`
group entry. See `NOTES.md` for the exact edit and how it was verified.

## Status

Boots clean: zero fatal errors across repeated fresh-driver boots.
Verified live with a real driver session and a raw socket client: a
brand-new character's full registration, world entry into the Pool Room,
and `look`/`status`/`inventory`/`quit` all producing correct output.

270 of 275 `.lpc` files pass a full `lpcc_check.sh` batch compile sweep;
the 5 that don't are all non-preloaded, non-boot-critical example/
teaching content with a pre-existing content/API mismatch predating this
port (see `NOTES.md` \S3) -- expected for a deliberately minimal engine
like this one, not a sign of missing conversion work.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/foundation1
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40248**.
