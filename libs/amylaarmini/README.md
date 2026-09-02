# MiniMud (amylaarmini)

A genuine pre-LDMud, Amylaar-driver-era testbed skeleton -- 19 files total. Not a game in any real sense: one starting room, a player class, a handful of commands, and the master/simul_efun pair needed to boot at all. Valuable purely as a primary-source historical artifact from the driver lineage that later forked into LDMud, kept here in the same "verify implemented functionality, don't expect a world" spirit as the already-onboarded `lil` and `lplib8`.

## Provenance

Recovered directly from the still-live Lysator FTP mirror
(`https://ftp.lysator.liu.se/pub/lpmud/mudlibs/Amylaar/minilib/`) --
no Wayback Machine recovery needed.

## Implemented commands

- `look`, `say <text>`, `who`, `ls` -- the basics.
- `eval <expr>` -- compiles `<expr>` on the spot as a throwaway LPC
  function body and runs it (a live debug/REPL tool).
- `update <path>` -- destructs and forces a fresh reload of a single
  object by path. Classic wizard power tool; the archive does nothing
  to guard against the well-known footgun of updating the room you're
  currently standing in (no content relocation) -- this is expected,
  intentional 1990s wizard-tool behavior, not a bug.
- `rehash` -- reloads `access.allow`.

## Highlights (see `NOTES.md` for full detail)

- `get_dir()`'s flag semantics differ from the archive's target
  driver: this driver needs flag `-1` (not the old convention's `2`)
  to get the detailed `({filename, size, mtime})` array form that
  `log_file()`'s log-rotation check needs; the wrong flag value
  silently returns a plain array of filename strings, crashing the
  size comparison the very first time a log file was ever written.
- `set_this_object()` (used in the same function, to make the
  following `write_file()` act with the *caller's* identity rather
  than the log function's own) was never a real efun on this driver.
  Harmless to drop here since this archive's own `valid_write()`/
  `valid_read()` (`secure/master.lpc`) unconditionally `return 1;`
  regardless of caller identity anyway -- a fully permissive
  single-user testbed security model.
- The usual `move_object()` 1-arg vs. 2-arg dialect gap, and
  `cat()`/`log_file()` needing reimplementation as simul_efuns since
  neither is a real efun on this driver.
- A genuinely dead piece of code, confirmed rather than assumed:
  `secure/master.lpc` defines its own `process_input()` (which would,
  if it ever ran, silently swallow and `eval`-as-raw-LPC *every
  single line any player ever types*) and a redundant `logon()`. This
  driver only ever calls `process_input()` on the INTERACTIVE object
  itself (confirmed in FluffOS's own `packages/core/interactive.cc`),
  never on the master object, so both functions are simply never
  invoked -- zero behavioral effect, confirmed live (`look`/`say`/
  `who` all worked normally through ordinary command dispatch).

## Registration flow

Type any name (no password prompt at all) -> straight into the
single starting room.

## Local play

```
cd libs/amylaarmini
~/src/fluffos/build-debug/src/driver config.fluffos
```

Port **40264**.
