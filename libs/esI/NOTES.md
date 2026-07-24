# esI.rar → `esI`

- Archive: `archives/esI.rar` (10.2MB — "东方故事"/"Eastern Story", themed
  "屠龙之战"/"Dragon Slaying War" per the live banner; up since May 2001
  per its own credits). Same 东方故事 lineage as archive #12 (es1_win),
  different snapshot/branch.
- Mudlib root: `esI/` at archive top level. Config at top-level
  `config.cfg`.
- Port: **40010**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: banner, staff/admin credits, uptime status,
name-length validation, name-not-taken confirmation prompt.

## What was fixed

Applied both fixes discovered on lib #12 (same lineage) **proactively**,
before the first boot attempt, since a quick grep confirmed both patterns
present in the raw archive:
1. `std/object/prop.lpc`'s `#include </std/object/prop_logic.c>` (angle
   brackets, local directory, reached via preload) — `convert_lib.sh`'s
   automated `.c>`→`.lpc>` fix only fixes the extension, not the
   bracket-vs-quote distinction, so this still needed the manual switch
   to quotes (`#include "/std/object/prop_logic.lpc"`) per AGENTS.md §8d's
   preload-timing addendum. **Worth teaching `convert_lib.sh` to convert
   local angle-bracket `#include`s to quotes automatically** the next time
   this pattern recurs in enough libs to justify it (seen twice now).
2. `master.lpc`'s `domain_file()` — same `explode("/", "/")` returning a
   zero-length array, `!path` guard not catching it — added
   `|| !sizeof(path)`.

Both fixes applied before ever attempting a boot; booted clean on the
first real attempt. Plus the routine per-lib steps: encoding (8471
converted, 1741 already UTF-8/ASCII, 107 skipped binary, 14 lossy),
`.c`→`.lpc` (7035 files, 1009 refs + 1 angle-bracket ref auto-fixed),
`static`→`nosave` (121 files).

## Known remaining issues (documented, not fixed)

- 1195 lpcc-sweep failures (of 7035) — not triaged past confirming the
  lib boots and plays; given the time budget across ~90 remaining
  archives, not chasing every failure category individually this time
  (same call as es1_win's NOTES.md documents for its own long tail).

## How to run

```
cd libs/esI
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40010 --timeout 10 --send "" --send "look" --send "quit"
```

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **Formatter**: `format-corpus.mjs` over all 7035 `.lpc` files; 6986
  reformatted, 5 unchanged, 44 refused (self-check `errors`, expected).
- **Native retest against rebuilt driver — 2 regressions found + fixed**
  (both pre-existing gaps from before this pass, only surfaced now by
  actually running `look`/`score`/`quit` to completion rather than just
  confirming boot + registration):
  1. Same stray debug `write("aadsaaaaaaaaaaaaaaaaaaaa\n\n")` in
     `std/user.lpc`'s `setup()` as `es1_win` (same lineage/root cause,
     absent from `raw/`) — deleted.
  2. **`quit` crashed** with `*Inherited file '/std/room' does not
     exist!` the first time, then `*No program in object
     '/d/std/IRC/lobby'!` after a partial fix — both trace back to the
     same **§8d `get_include_path()` gap**: this lib's TODO.md entry
     claims "both known fixes applied proactively" (referring to
     `es1_win`'s §8d fix), but `adm/obj/master.lpc` was actually
     *missing* `get_include_path()` — only `es1_win`'s copy has it. Two
     symptoms stacked: (a) `include/globals.h`'s `ROOM` macro is stale
     (`"/std/room"`, real file is `std/room/room.lpc`) while
     `include/mudlib.h`'s is correct (`"/std/room/room"`) — files that
     `#include <mudlib.h>` are fine, files relying only on the
     auto-included `globals.h` (e.g. `logoutd.lpc`'s room lookups) got
     the wrong path; fixed by correcting `globals.h`'s value to match
     `mudlib.h` (single point, matches the pattern of every other macro
     in that file). (b) once that was fixed, `d/std/IRC/lobby.lpc`
     (lazily compiled mid-connection during `logoutd`'s post-quit
     cleanup, not during preload) still failed with `Cannot #include
     irc.h` — the exact §8d/§15o symptom (angle-bracket same-dir
     `#include` needs `master.lpc`'s `get_include_path()` for compiles
     triggered live, not preload/bare-`lpcc`); fixed by adding the
     standard `get_include_path()` shape to `master.lpc` (identical to
     `es1_win`'s). Re-verified: full registration + `look`/`score`/
     `quit` all clean, zero debug.log errors, with two separate real
     Chinese names (乔峰, 阿朱).
- **WASM test**: boots cleanly (only the expected non-fatal
  `Undefined function socket_create` et al. in
  `/adm/daemons/network/cmwhod.lpc` during preload, and the same
  cmwhod-related `*No program in object` at `quit`-time cleanup — both
  are the documented "no sockets package under WASM" limitation, caught
  by the existing error handling, non-cascading). Full registration with
  a real Chinese name (慕容), `look`, and `quit` all worked end-to-end —
  this lib's IP-check is non-blocking, so it is unaffected by the
  documented `query_ip_number()` WASM limitation.

## WASM-enablement pass (loopback / admin seeding)

Identical to sibling `es1_win` (ES II family, 008).

- **Loopback ban bypass** (§1.3b): `adm/daemons/banish.lpc`
  `check_banned_site()` (~line 75) — short-circuit at top for loopback /
  empty / non-string / `localhost` / `127.` names (returns 0). Gate is
  fed `query_ip_name()`, called from `logind.lpc:242` and `:577`.
- **Uptime gate**: none rejecting. `logind.lpc:87` `uptime()<43200` only
  grants extra user slots (content, kept).
- **Anti-flood throttle**: none (per-session password retry cap only).
- **Admin account** (§1.5): `fluffos` / `Mud@2026`, display 浮浮. Added to
  `(root)`+`(admin)` in `/adm/etc/groups`; `wizard 1` + `domains`
  (archwizard) in `data/std/connection/f/fluffos.o`. Verified
  `update /adm/daemons/statsd` loads OK.
- **Fail-closed retrofit** (2026-07-24 security correction): the loopback
  check(s) above originally also treated an empty/non-string IP as
  loopback (defensive fallback for the then-broken `query_ip_number()`).
  Since the driver's IP-reporting bug is now fixed upstream (WASM
  reports a clean `127.0.0.1` like native), that fallback was removed —
  loopback is now strictly `stringp(ip) && (ip=="127.0.0.1" ||
  ip=="::1" || ip[0..3]=="127.")`; anything unparseable/empty is
  untrusted/remote and goes through the original gate logic. Retested:
  fluffos login + `look`/`quit` still clean over loopback.
- **Save files to force-add** (untracked, NOT gitignored):
  `libs/esI/work/data/std/connection/f/fluffos.o`,
  `libs/esI/work/data/std/user_ob/human/f/fluffos.o`.
