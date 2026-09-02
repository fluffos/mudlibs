# Hakkard World (dshakkard)

A custom closed-alpha game ("Hakkard World", banner reads "Revision 0.0.1, Status: Closed Alpha") built on the Dead Souls 3.8.6 mudlib -- the same Cratylus-lineage engine this collection already hosts as `ds386`/`deadsouls_fluffos` and `dsIII`. Not a distinct Dead Souls release: the non-secure top-level code (command dispatch, headers, the stock `campus`/`cave`/`default`/`examples`/`learning`/`Praxis`/`town`/ `Ylsrim` domains) is close to byte-identical to `ds386`'s own raw archive. What makes this game distinct is three bespoke domains added on top -- `lennar`, `lennarmanor`, and `northernwastes`, a custom fantasy setting with its own manor rooms, NPCs, and virtual-room servers -- plus a personal builder's realm (`realms/muirrum`) with several in-progress test rooms and abandoned editor scratch buffers.

Source: `git clone https://github.com/hakkard-dev-team/ds-hakkard`.
Slug `dshakkard`, number 185, port 40230.

## The interesting part of this port

The public repo's own `.gitignore` excludes `lib/secure`, `lib/save`,
and `lib/log` -- the entire security/daemon engine layer (including
`secure/daemon/master.lpc` itself) and both top-level runtime
directories were **never committed to this repository's git history at
all**. Since the rest of the codebase is confirmed byte-identical to
`ds386` wherever the two overlap, this port supplies the missing
`secure/` tree from `ds386`'s own already driver-compat-fixed copy
(verified file-by-file first) rather than inventing anything, then
applied the same dialect/OLD_ED/`__DIR__` fixes `ds386`/`dsIII` already
catalogued to ds-hakkard's own customized files. The missing `/log` and
`/save` top-level directories turned out to matter even more: their
absence made the driver's own error handler crash while trying to log
routine compile warnings, which silently miscategorized ~35 harmless
files as hard compile failures and masked several real save-path
errors entirely. See `NOTES.md` for the full porting log, including a
subtler pitfall (`ds386`'s own copy of `secure/lib/connect.lpc` had
already self-consumed its one-time admin installer, which had to be
restored from `connect.first.lpc` before this session's own install
wizard could be tested for real).

## Status

Boots clean, zero fatal errors. Verified live with a raw socket client:
the first-boot admin installation wizard (including the mud's
self-shutdown-and-restart-required design), admin login into a wizard
workroom, ordinary new-player registration (age gate, 8-race
selection), a distinct reconnect code path, and
`look`/`score`/`update`/`quit` all producing correct output.

2432 of 2440 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep (99.7%); the 8 that don't are all pre-existing non-bugs matching
classes already documented on `ds386`/`dsIII` (a deliberate anti-load
trap, builder-tool scaffolding templates, a missing efun, a missing
library component, an abandoned editor scratch file, and one real
content gap -- `daemon/help.lpc` crashes on `get_dir()` of a
`verbs/spells` directory this repo never shipped) -- see `NOTES.md` §6.

**Makes three real outbound network connections at boot** (IMC2,
Intermud-3, and an automatic `dead-souls.net` RELEASE_NOTES fetch) --
same caveat as `ds386`/`dsIII`: do not sweep this lib into
high-frequency automated re-boot loops.

WASM status: **playable**. Full admin login (`fluffos`/`Mud@2026`) and a
fresh new-player registration (8-race pick, age gate, email validation)
both verified clean end-to-end (`look`/`score`/`update`/`quit`) via
`scripts/wasm_client.js`. The same `sockets`-package-absent gap
`ds386`'s WASM pass already fixed was mostly inherited for free (shared
`secure/` tree); one remaining `secure/daemon/imc2.lpc` compile gap is
identical to `ds386`'s own current state and doesn't block boot/login/
play -- see `NOTES.md`'s "WASM bring-up (2026-08-27)" section.

## Local run

```
cd libs/dshakkard
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40230**.
