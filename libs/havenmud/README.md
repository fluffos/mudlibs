# Haven (havenmud)

A long-running Dead Souls-based game called Haven, set in the world of Kailie. New characters begin in "the skies above Kailie" -- a staging area where you read the newbie book (Type `read book`, then `go down`) before descending into the real world through your chosen hometown.

Source: `git clone https://github.com/brainface/havenmud`. Slug
`havenmud`, number 947, port 40249.

## The world

Kailie has its own pantheon (the Lord of Balance Duuktsaryth and the
Primal Gods Amelia, Balishae, Syra, Morgoth, Zaxan, and Ahriman), its
own creation-myth timeline, and its own calendar counting years from
the opening of Haven for player testing. Playable races include
humans, elves, dwarves, half-elves, orcs, half-orcs, sprites, skaven,
lamrani, dark-elves, and wild-elves -- with several more (goblins,
kobolds, gelflings, nosferatu, drughkor, meuzzin) appearing in the
lore and as NPCs.

21 custom domains make up the live world: `averath`, `baria`,
`crystal_reaches`, `estergrym`, `frostmarches`, `gurov`, `havenwood`,
`innersea`, `islands`, `namatar`, `peninsula`, `southern_coast`,
`tairi`, `valley`, `westwood`, `xandria`, and `yozrath`, among others
-- towns, wilderness, dungeons, and quest lines built up over years.
On top of the world content, Haven has a marriage/chapel system,
player estates, a crafting subsystem (clothing, at least), an
in-game newsgroup daemon, and an FTP daemon for wizards. `realms/`
holds 25 personal wizard workrooms (Duuk, Zaxan, Mahkefel, Alessandra,
Laoise, Torak, and others), several containing real in-progress
building projects alongside old scratch files and backups.

## Status

Boots clean under this project's native FluffOS driver and plays
through the full flow: name -> confirm -> email -> password (with
confirmation) -> gender -> real name -> race (`list`/`pick`) -> town
(`list`/`pick`) -> arrival in the newbie staging room -> `read book`
(awards a real quest completion + development points) -> `go down`
into your hometown's real content (verified reaching Haven town's
"Above the Elven Charity"). `look`/`score`/`quit` all produce correct
output, and reconnecting (name + password) restores the same
character in the same room with inventory intact.

See `NOTES.md` for the full restoration log, including several driver-
compatibility bugs found and fixed -- most notably a single off-by-one
slice bug in the shared command dispatcher that silently broke every
non-verb player command (including `score`) game-wide.

**Live network note**: this lib's `daemon/intermud` preloads and makes
a real outbound connection to the public Intermud-3 network on boot
(confirmed live, same router this collection's other Dead Souls-family
libs connect to) -- don't sweep this lib into high-frequency automated
re-boot loops.
