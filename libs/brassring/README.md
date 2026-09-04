# The Brass Ring (brassring)

A Dead Souls 3.8.x-based game-in-development. The village of Saquivor is the starting town; from there, roads lead west past the old church, across a humpbacked bridge, and into a dark forest. Bundled alongside the game's own custom content is a full port of the classic DikuMud Alfa world (the city of Midgaard and its surrounding zones) and the beginnings of a bespoke fantasy continent called Etnar -- the village of Wyr, with the Bramblewood and Vexwood forests and the town of Orgon planned around it.

Source: `gh repo clone LashMUD/TheBrassRing`. Slug `brassring`, number
963, port 40265.

## Etnar

Etnar is the game's own original setting-in-progress, not carried over
from the base Dead Souls or DikuMud content. The village of Wyr is the
region the author was actively building at the time of this snapshot,
with rooms and NPCs (Albert Derby, Waltin Kelley, Caltan Dowini, the
Pierce family) already in place, plus a virtual (procedurally-served)
room system covering the wider wilderness. The `char` and `q'in`
subdirectories are reserved for future regions the game's own
`readme.txt` describes as "the lands of Q'in and Char."

## Status

Boots clean under this project's native FluffOS driver, zero compile
or fatal errors. Verified live with two independent new characters:
full registration (name, age gate, screen-reader question, password,
gender, email, race pick, and a 6/4/4 primary/secondary/minor skill
selection covering all 28 skills) all the way into the game world;
`enter town` correctly reaching Saquivor's "Village Road Intersection";
Etnar's Wyr village and the bundled DikuMud content both reached and
rendering correctly; `look`/`score`/`update`/`quit` all producing
correct output; and reconnecting restoring the same character, in the
same room, with the same inventory.

**Admin account**: `fluffos` / `Mud@2026` (this project's standard
seeded admin, granted by moving its save file into
`secure/save/creators/` after a normal registration -- see `NOTES.md`
section 5).

WASM status: **playable**. Shared WASM driver. Admin login
(`fluffos` / `Mud@2026`) through the news pager into the Temple of
Midgaard, plus `hp: 430/430` / `quit` ("Please come back another
time!"), verified with `scripts/wasm_client.js`. Play:
https://mudlibs.fluffos.info/brassring/

See `NOTES.md` for the full porting log, including how this session
reconstructed the game's entire missing security-daemon layer (this
repo never once committed a `secure/master.lpc`/`simul_efun` engine of
its own -- it ships as a pure content overlay meant to be dropped onto
an existing Dead Souls 3.9 install) and the real programming bugs found
along the way.

No outbound network connections at boot (IMC2 is disabled by this
game's own shipped config, and its Intermud daemon never actually opens
a socket) -- unlike several other Dead-Souls-family libs in this
collection, this one is safe for high-frequency automated re-boot
loops.

## Local run

```
cd libs/brassring
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40265**.
