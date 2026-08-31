# Primal Darkness

A real, historically-operated English-language MUD (1999-2010) built on
the Nightmare mudlib lineage -- one of the largest libraries in this
collection, at roughly 32,000 source files. Genuinely authored content
throughout, not a stock skeleton: dozens of hand-built domains (aekari,
citrin, distopia, durst, forest, frozen, guilds, helgrath, helves,
inferi_island, lodos, marshes, metaisland, pastarlon, roston, saahr,
tirun, and more), a 30-race character-creation system, guilds, and
years of accumulated wizard-built content and real player history
preserved from the original archive.

Source: `ehershey/pd` on GitHub. The mudlib itself lives at
`libraries/beta-ii/` inside that repository (a bundled Flash client and
driver binaries/scripts were excluded during conversion -- this
collection always uses its own driver).

## Highlights

- **Race-pick character creation**: a short new-character ritual (name,
  password, gender, email) drops you into a creation-limbo room where
  you `read list` to see the 30 available races and `pick <race>` to
  finalize your character -- stats roll automatically and you're placed
  into the real starting area (Tirun Central Park) fully equipped.
- **Large, genuinely hand-built world**: dozens of named domains with
  real room descriptions, NPCs, quests, and guild content, plus an
  in-game newbie helper NPC and a first-time player news feed.
- **An identity-profile system**: the mud tracks which characters have
  connected from the same IP (a LAN/multi-account disclosure feature,
  not a bug) -- expect a one-time "is this a new identity or an
  existing one?" prompt on your first-ever connection from a given
  address.

## Play

Connect and answer the name/password/gender/email prompts to register,
then `read list` and `pick <race>` to finish character creation.
`look`, `score`, `inventory`, and `say` all work as expected once
you're in the world; `quit` saves you and disconnects cleanly, and
reconnecting with the same name/password brings you back to the exact
room and equipment you left with.

## Status

Boots clean natively and plays correctly end-to-end: registration,
race selection, movement through real authored rooms, and the
restore/reconnect path were all verified live, repeatedly, across
multiple independent test accounts. Not yet packaged for the browser
(WASM) gallery.

## Admin account

`fluffos` / see the standard corpus password -- seeded via this
lineage's `(superuser)`/`(assist)`/`(allowed)`/`(creator)`/
`(approval)`/`(mudlib)` groups in `adm/db/groups.db` plus a non-mortal
`position` title in its save file (this lineage gates wizard status on
both group membership AND an in-play "position"/title, not group
membership alone). Verified live via `update <path>`, which exercises
both the read and compile halves of the ACL.

## Onboarding notes

See `NOTES.md` in this directory for the full technical bring-up log.
The headline finding: **two independent, corpus-wide, silently-broken
codepaths**, both fixed and verified live --

1. The command-dispatch daemon's directory-scan used stale
   `.c`-extension slice arithmetic left over from before this
   collection's standard `.c`→`.lpc` rename, corrupting every single
   command's registered key so literally every verb except `quit`
   returned the generic `"What?"` fail message, for every player, from
   the very first boot (AGENTS.md §7.118, a previously-catalogued bug
   class -- this is its largest-scale confirmed instance).
2. The login object's account-restore path silently failed to grant
   itself read access to the player's own save file, due to a
   double misunderstanding of what this driver's `export_uid()` efun
   actually does -- meaning a fresh registration worked perfectly, but
   reconnecting to ANY already-created account silently landed the
   player in a session with zero working commands, including `quit`
   itself (a new catalog entry, AGENTS.md §8.22).

Also fixed: eight base-class setter functions (`set_id` and seven
siblings) declared with parameter types narrower than the vast
majority of the corpus's own call sites use (AGENTS.md §7.127 --
~8,800 of this lib's original ~10,000 compile failures came from just
these eight functions); a genuinely lost `keep.h` header reconstructed
from surviving directory evidence; and a handful of smaller,
lower-blast-radius compile-compat fixes detailed in `NOTES.md`.
