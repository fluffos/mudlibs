# LPlib8 (lplib8)

An experimental mudlib written by Lars Pensjö himself -- the creator of LPMud, and the author of the original LPC driver line -- as his own testbed for "how things really should be done" with the new features of "LPmud game driver 3.0" (per the archive's own README). Explicitly NOT the well-known "CDlib" for Genesis; a much smaller, more experimental sketch, mailed out for feedback (`lars@cd.chalmers.se`).

54 real `.c` files, genuinely FluffOS/MudOS-compatible (zero
`driver_hook`/`set_driver_hook` usage anywhere). A thin but real
playable demo: a small green-lawn/hedge-maze starting area, a knife
to pick up, doors with working lock/key logic, a procedurally-
generated "experimental map system" (tiles created and cached
on demand, deleted from disk once loaded -- a real, working 1989-era
procedural-world mechanism), a mail reader, and the classic
LPMud stats/skills system.

## Provenance

Recovered directly from the still-live `ibiblio.org` Linux/games/muds
mirror (`https://ibiblio.org/pub/Linux/games/muds/lplib8.tar.z`) -- no
Wayback Machine recovery needed, the file is still served as-is
(a gzip stream despite the classic Unix-`compress` `.Z`-style
extension).

## Highlights (see `NOTES.md` for full detail)

- **A genuinely new, previously-uncatalogued driver-convention gap**:
  this driver's `valid_write()`/`valid_read()` master applies pass the
  CALLING OBJECT ITSELF as their 2nd argument (confirmed directly in
  FluffOS's own `packages/core/file.cc`), not a euid STRING the way
  the classic driver this archive targets did. Every single euid
  string comparison in the archive's own security code
  (`eff_user == get_root_uid()`, domain-membership checks, etc.) was
  therefore silently always false, regardless of the real caller's
  actual identity -- confirmed live: EVERY player's very first
  character save failed ("Denied write permission in save_object()"),
  and every subsequent login's restore failed too ("read permission
  denied"), with zero indication of WHY beyond the bare permission
  message. Fixed by converting the object to its real euid/uid string
  at the top of both master applies.
- A second, independent bug in the same permission subsystem:
  `valid_seteuid()` never actually let a plain backbone-owned object
  (e.g. a freshly cloned `/obj/player`) seteuid to `"root"` even
  temporarily -- the archive's OWN code comment on this exact function
  admits it: *"the game driver has not been fixed to call these
  valid_functions ... yet, but I will fix that really soon (Lars)"*.
  Both bugs had to be fixed together before save/restore worked at
  all; fixing only one still left the other blocking every save.
- A genuine ambiguity in this project's own `extract()` simul_efun
  reimplementation (needed because this driver never had the classic
  efun): a 3-argument call whose END argument is explicitly `0`
  (`extract(name, 0, 0)`, meaning "just the first character") is
  indistinguishable from the 2-argument "to end of string" form,
  since LPC coerces an omitted `varargs` argument to plain `0`. This
  silently broke the save-file bucketing scheme (`/players/<name>/`
  instead of the intended `/players/<first letter>/`) until the one
  real call site was rewritten with unambiguous range slicing instead.
- Two genuine pre-existing bugs in the ORIGINAL 1989-93 source,
  confirmed against the raw archive bytes (not conversion damage): a
  missing closing brace in `obj/mail_reader.lpc`'s `move()` (leaving
  `move_object()`/`return MOVE_OK` unreachable and corrupting the
  parse of everything after it in the file) plus a `MOVE_DESTRUCT` vs.
  the header's real `MOVE_DESTRUCTED` typo; and a dangling `if`
  statement with no body at all in `obj/roommaker.lpc`, immediately
  followed by the function's own closing brace.
- `obj/lockable_door.` (note the trailing dot, no `.c` extension --
  an original-archive filename oddity, not conversion damage) was
  invisible to the `.c`->`.lpc` rename and to the game entirely; the
  file exists and is real, needed content (`sys/door.h`'s
  `MAKE_LOCKABLE_DOOR` macro clones it by path). Renamed to
  `.lpc` directly.
- Reimplemented six classic MudOS efuns this driver never had:
  `extract()`, `log_file()`, `cat()`, `version()`, `wizlist()`,
  `localcmd()`.
- The usual dialect gaps already catalogued from the sibling
  `basis`/`lpmud245` onboardings this session: `move_object()`/
  `transfer()` 2-arg forms (fixed via a shared `move_object(dest)`
  shim on `basic/move.lpc`, inherited by every real movable object --
  a cleaner fix here than the per-file blanket approach needed on
  `lpmud245`, since this archive actually uses real `inherit`),
  `command(str, ob)`, `snoop()`'s 1-arg semantics, `valid_override()`
  for the driver's efun-name-collision guard, `get_include_path()` for
  quote-included cross-directory headers, and the `in`/`class`
  reserved-word collisions.

## Registration flow

Type your name -> password -> straight into the starting lawn
(no confirmation, no gender/race prompt -- this thin, early testbed
never implemented those).

## Local play

```
cd libs/lplib8
~/src/fluffos/build-debug/src/driver config.fluffos
```

Port **40263**.
