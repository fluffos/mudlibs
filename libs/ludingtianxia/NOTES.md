# 鹿鼎天下.rar → `ludingtianxia`

- Archive: `鹿鼎天下.rar` (from the 2026-07-29 bulk `mudlib.rar` drop).
  "Century / adm-single" family lineage (custom `securityd.lpc` ACLs,
  master at `/adm/single/master` — same shape as `shiji` (021),
  `shujian2008` (024), `xianjianchuanqi` (027), `xiakexinzhuan2` (028),
  `xiakexing100` (030)). ES II heritage (`master.c` header: "for ES II
  mudlib... rewritten by Annihilator", further "modified by Xiang for
  XKX").
- **Naming quirk** (AGENTS.md §5.1's "don't trust the name field," a new
  instance of it): the archive is named 鹿鼎天下, but the login banner
  brands the game **雄霸天下『西安站』** ("Xi'an station"), while the
  `quit` message still says "离开了鹿鼎天下" — two different in-game
  names coexist in the shipped source, evidence of a rebrand that wasn't
  applied everywhere. Went with 鹿鼎天下 for the slug (matches the
  archive/what the user is most likely to look for) but documented both
  names in the README.
- Mudlib root in archive: `ldtx/ldj/` (two levels down).
- No shipped config file; reconstructed using `shiji`'s config.fluffos
  (same lineage/master path) as the template.
- Port: **40105**.

## Status: DONE — boots clean, full registration with a real Chinese name verified, playable

## What was fixed

1. **Systemic encoding artifact, not caught by `convert_lib.sh`'s normal
   GB18030→UTF-8 pass**: nearly the entire tree (3903 of ~5960 `.lpc`/`.h`
   files) shipped with doubled `\r\r\n` line endings (CRCRLF, doubled —
   worse than the single-CRCRLF quirk `convert_lib.sh`'s own comments
   already document). This silently broke every subsequent string-literal
   edit (exact-match tooling can't find `\r`-embedded lines). Fixed with a
   blanket `sed -i 's/\r//g'` across every `.lpc`/`.h` file before doing
   any further hand-edits.
2. **§7.1 class, simpler variant**: `adm/single/master.lpc`'s
   `valid_read`/`valid_write` did `if (ob = find_object(SECURITY_D)) ...
   return 0;` — no lazy `load_object()` attempt at all, just permanent
   deny until securityd happens to already be loaded. Real driver boot
   preloads securityd first so this never bit in practice, but it made
   `lpcc_check.sh`'s single-VM compile sweep (which doesn't preload)
   deny-everything (2/5960 pass). Added the standard re-entrancy-guarded
   `load_object(SECURITY_D)` fallback from AGENTS.md §7.1 to both
   functions — jumped to 5793/5960 passing.
3. **§8.1 class**: `adm/simul_efun/chinese.lpc`'s `is_chinese()` (GBK
   byte-range test) and `adm/daemons/logind.lpc`'s `check_legal_name()`
   (byte-oriented length bound 2-10 + `i%2==0` sliding window) — same
   fix pattern as every other lib in this catalog entry. Verified: real
   Chinese name 秦风六 registers correctly end-to-end.
4. `/adm/daemons/network/dns_master` and `/adm/daemons/ftpd` were
   actively preloaded (not already commented out, unlike most other
   libs in this collection) — commented out per the standing no-sockets-
   package policy (§1.3c). Confirmed harmless at runtime: login flow
   prints "网路精灵并没有被载入" (network daemon not loaded) and
   continues normally.
5. Admin seeding (§1.5): registered `fluffos` through the normal flow,
   appended `fluffos (admin)` to `adm/etc/wizlist` (same mechanism as
   the Century family generally — `/` is in `securityd.lpc`'s
   `trusted_write` for `(admin)`). Verified: recompiling `/adm/single/
   master` via `update` succeeds as `fluffos` (shows the driver's
   variable-clear side effect, no ACL denial).

## Known issues, NOT fixed (logged, matching the "content bugs" bar)

167 of 5960 files fail `lpcc_check.sh`'s compile sweep, none of them
core-system files (master/simul_efun/logind/securityd/chinesed all
compile and run correctly). Three observed failure shapes, all isolated
to individual content files:
- A handful of `kungfu/skill/*.lpc` files have a genuinely unterminated
  string literal in the original source (e.g. `qingyi-jian.lpc:11`:
  `"skill_name" : "大侠式,` — missing closing quote before the line
  ends), which then swallows the next line and surfaces as a garbled
  "Illegal character" error further down. Pre-existing author typo, not
  a conversion artifact (confirmed the file decodes as valid UTF-8
  throughout).
- A handful of `clone/misc/*_cloth.lpc` (clothing item) files reference
  the `YEL`/`NOR` ANSI color macros without the header that defines them
  being reachable from that specific file — compile error, item is
  simply unusable in-game.
- A couple of room/NPC files (e.g. `/d/city2/tian_anm`) throw a runtime
  "Bad argument 1 to call_other()" (got int 0) — a null-object reference
  in that room's own logic, likely a stale/removed NPC or item reference
  from the original game's development.

None of these affect the core registration/look/score/quit loop verified
above; logging here rather than auditing all 167 individually.

## Not yet done (out of scope for this pass)

WASM export / GitHub Pages packaging — deferred to a later batch pass.
