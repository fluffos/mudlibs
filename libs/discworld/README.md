# Discworld (discworld)

The official Discworld MUD mudlib, set in Terry Pratchett's Discworld and running continuously since 1991 -- one of the longest-lived, most widely studied LPMuds in existence. This copy comes from Cratylus's (the Dead Souls maintainer's) unofficial "Discworld Bundle" v3 redistribution, which pairs the mudlib with a matching FluffOS build (we use this project's own driver instead, per usual). This project also holds independently converted v1 and v2 snapshots of the same bundle (`libs/dw_fluffos_v1/` port 40271, `libs/dw_fluffos_v2/` port 40272).

## Highlights

- New characters start in the famous circular Discworld Room, in the
  Cabbage Warehouse Rooming House in Ankh-Morpork -- a large stone table
  at its centre bears a map of the world resting on Great A'Tuin and the
  four elephants, exactly as the books describe it.
- A wandering "womble" NPC greets new arrivals and wanders the starting
  rooms delivering flavour dialogue -- Discworld's own idiom for "an NPC
  that moves/does something" is literally the verb "womble".
- Commands are resolved through a directory-based dispatcher: a verb
  like `look` maps to a file `cmds/living/l_ook.lpc`, where the
  underscore marks the shortest legal abbreviation (`l`). Every command
  passes through a `drunk_check()`/`lower_check()` throttle first, which
  can transiently queue a command ("Queued command: look") for a moment
  right after login while your character's initial time budget catches
  up -- this is normal, not a bug.
- `quit` triggers an in-character send-off (a gecko checks your
  inventory, then a chimera or giant bird carries you off) rather than
  an instant disconnect.

## Registration flow

`N` (new character) -> character name -> confirm (`y`/`n`) -> password
-> confirm password -> capitalisation (accept the default with Enter, or
type your own) -> gender (`male`/`female`) -> a Terms and Conditions
screen, which the server deliberately pauses ~30 seconds before showing
the final `yes`/`no` prompt for (a real server-side `call_out`, not a
client hang -- just wait it out) -> `yes` -> you arrive in the Discworld
Room.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **rank**: full trustee/administrator (Discworld's own `TRUSTEE` rank,
  the same level `query_trustee()`/`query_administrator()`/
  `high_programmer()` all check)

Registered through the normal registration flow like any other
character. Discworld's admin model layers a hardcoded `TRUSTEES` macro
(in `secure/master.lpc`, containing `Root` and the original archive's
`cratylus`) on top of a real, persisted `positions` mapping saved in
`secure/master.o` -- and since granting trustee rank normally requires
already *being* a trustee (`add_trustee()` checks the caller), the
bootstrap grant was seeded directly into that save file:
`positions (["fluffos":2,])` (`2` is `master.lpc`'s own `TRUSTEE`
constant). Verified live: wizard-only login banners appear, and a
wizard-level recompile command (`compile <path>`) passes its ACL check
cleanly (it hits an unrelated pre-existing bug further in, documented in
NOTES.md, not a permission denial).

## Status

Boots clean (zero compile errors in `debug.log`). Fresh registration,
`look`, `score`, and `quit` all verified end-to-end with a real driver
session, including the initial automatic room description on arrival
and a full server-driven quit sequence. Re-login (the restore path) also
verified. See `NOTES.md` for the full list of driver-compatibility bugs
found and fixed during this port -- the headline one: this codebase's
`add_action(fn, "*", ...)` catch-all convention doesn't exist on this
driver (the catch-all verb here is `""`), so **every single command
silently failed** until that was fixed across five call sites, alongside
a separate `[0..<3]` fixed-width extension-stripping bug in
`secure/command.lpc` that broke the directory-based command dispatcher
the same way. A few genuine content gaps in this third-party archive
(a missing `/std/outside.lpc` base class, missing `/obj/armours/` and
`/obj/clothes/` content directories, no MySQL server available for the
map/pathfinding subsystem) are documented in `NOTES.md` rather than
invented or patched over.

WASM status: **playable**. Full registration through to the Discworld
circular hall is verified under the shared WASM driver (`NOTES.md`
WASM section). Play: https://mudlibs.fluffos.info/discworld/
