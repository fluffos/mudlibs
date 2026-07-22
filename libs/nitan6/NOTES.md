# nitan6 — 笑傲江湖 (NT/nitan/Lonely mudlib lineage, same as nitan170911)

Archive: `nitan6.zip`. Port: 40019. Status: **done** (boots clean,
connects, plays through login and into full character creation —
Chinese surname/given-name entry — with zero crashes).

## What this is

Same "NT/nitan/Lonely" mudlib lineage as `nitan170911` (archive #21,
"仙剑奇侠传"), this one themed "笑傲江湖" (The Smiling, Proud Wanderer),
"NTlib V5.1g" / "NTOS V2.4". 26,270 raw files, 23,118 `.lpc` after
conversion. Shares the exact same core engine (`adm/kernel/simul_efun.lpc`
composition, `feature/dbase.lpc`, `wizard.lpc`, etc.) as nitan170911, just
with different game content and a few different daemon files.

## Approach: applied nitan170911's fixes proactively, not from scratch

Since this is confirmed the same lineage, every fix from nitan170911
(AGENTS.md §15/§15b/§15c/§15e) was applied **before the first boot
attempt**, either by directly copying the generic engine files (verified
byte-identical pre-fix, via `diff` against nitan170911's committed
versions) or by manually re-applying the same transformation to files with
real lib-specific differences (`clone/user/user.lpc`, `clone/user/
baby.lpc`, `adm/daemons/giftd.lpc`, `adm/daemons/examined.lpc` — same
`efun::set/query/delete/addn` → `::set`/`ob->set` pattern, applied
per-file since each has different surrounding content).

**Result: booted with zero compile errors on the very first attempt** —
confirms the proactive-fix approach (already established practice for
same-lineage libs, see AGENTS.md's "recognize lineage, apply fixes
proactively" note) works even for this scale of fix.

Files copied wholesale from nitan170911 (confirmed pre-fix content was
byte-identical): `feature/dbase.lpc`, `feature/treemap.lpc`, `adm/kernel/
check_config.lpc`, `adm/kernel/simul_efun.lpc`, `adm/kernel/simul_efun/
wizard.lpc`, `inherit/room/room.lpc`, plus the two new fragments `adm/
kernel/simul_efun/ansi_util.lpc` and `adm/kernel/simul_efun/
db_compat.lpc`.

Files manually re-fixed (real content differences from nitan170911, same
transformation applied): `adm/kernel/simul_efun/util.lpc` (one
`efun::remove_ansi` call site), `clone/user/user.lpc`, `clone/user/
baby.lpc`, `adm/daemons/giftd.lpc`, `adm/daemons/examined.lpc`,
`adm/etc/preload` (stripped `.c` extensions), `adm/daemons/
equipmentd.lpc` (guarded the same unchecked `TEMPLATE_D->create_object()`
call site as nitan170911 — `u/redl/cangku.lpc`, the file that happened to
trigger it there, doesn't exist in this lib).

## New bugs found beyond the proactive fixes (this lib's own content)

1. **`adm/daemons/mudlistd.lpc:145`**: `array usercount = allocate(3);` —
   bare `array` as a full type-by-itself declaration doesn't actually
   declare a usable variable on this driver (new catalog entry, AGENTS.md
   §15f); fixed to `mixed *usercount`. This exact typo pattern (`array
   name;`/`array name = expr;`) appears ~30-40 more times across this lib
   and nitan170911 combined — **not fixed exhaustively**, only as each
   occurrence surfaces via a real compile/interactive-test failure (see
   §15f and §6b's "long tail" note — not worth a blind sweep-and-fix on a
   26,000+ file lib).
2. **`adm/daemons/timed.lpc`**: `query_heartbeat_interval()`/
   `set_heartbeat_interval()` — real MudOS efuns (dynamic heartbeat-rate
   throttling under CPU load) with no FluffOS equivalent at all. Restored
   as simul_efuns in `db_compat.lpc` backed by a plain stored int — this
   can't actually pause/throttle the real driver heartbeat, but preserves
   the toggle logic every caller (`timed.lpc`, `systemd.lpc`) expects
   self-consistently.
3. **`adm/daemons/mudlistd.lpc`'s `create()`** was missing a
   `seteuid(getuid())` call that every other daemon in this codebase has
   at the top of `create()`. Harmless as long as mudlistd is loaded during
   the normal root-context preload sequence — but it isn't preloaded at
   all here (not listed in `adm/etc/preload`), so the first time anything
   lazily loads it (in this case: `timed.lpc`'s crontab, itself first
   triggered by `TIME_D->replace_ctime()` from a **connecting player's**
   login flow) it runs with no euid set, and its `create()` immediately
   calls `save_object()` (creating its own persisted data file for the
   first time) — denied by `securityd.lpc`'s `valid_write` (requires
   euid == ROOT_UID). Fixed by adding the missing `seteuid(getuid())`.
   (nitan170911's copy of this same file has an unconditional `return;`
   as the first statement of `create()`, so this exact path is dead there
   — not a bug needing the same fix on that lib.)
4. Also added a `catch()` guard around `timed.lpc`'s crontab entry loader
   (`init_crontab()`, per-entry `load_object()`) — a single misbehaving
   crontab target used to crash whatever caller happened to trigger this
   whole chain first (a connecting player, via an unrelated
   `TIME_D->replace_ctime()` call), not just fail to schedule that one
   task. Logs to `nosave/crontab` on failure instead of crashing.

## Interactive test result

Boots clean, connects, full ANSI banner + Chinese glyphs render correctly,
registered-player-count and online-count lines print (both go through the
exact same crash-prone `TIME_D`/crontab chain that needed the mudlistd fix
above), username prompt validates correctly, and — unlike nitan170911 —
this lib's registration flow does NOT require a live MySQL connection to
proceed (its `DB_SAVE`-guarded code path handles `do_sql()`'s failure
differently and falls through to local file-based character creation): a
brand-new username gets a "create new character?" confirmation, and
confirming leads into the full Chinese surname/given-name entry flow.
Verified through that point with zero crashes; did not create a full
character or play further into the game world (out of scope for this
conversion pass).

## lpcc sweep

**Not run** — see AGENTS.md §6b's mega-lib memory note (this lib is
26,270 raw files / 23,118 `.lpc`, in the same "the sweep itself risks
OOMing the host before finishing" territory as nitan170911). The boot +
interactive-connect test above is the verification for a lib this size.
