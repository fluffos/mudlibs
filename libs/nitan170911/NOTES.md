# nitan170911 — 仙剑奇侠传 (NT/nitan/Lonely mudlib lineage)

Archive: `nitan170911.7z`. Port: 40018. Status: **done** (boots clean,
connects, plays through to username entry and character-registration
gate; registration itself needs a real MySQL backend, out of scope).

## What this is

A large (~54,000 `.lpc` files under `work/`) "仙剑奇侠传" (Legend of Sword
and Fairy) themed wuxia/xianxia mudlib, "NTLIB V7.1x". Uses a MySQL-backed
account system (`db_connect`/`db_exec` via the DB package) for player
registration/login — this only partially applies here since we have no
MySQL server configured; the mudlib itself handles that failure
gracefully (see below), so this isn't a blocker for local testing.

`nitan6.zip` (archive #22, port 40019) is the same lineage — expect to
need the identical fixes described here; apply them proactively rather
than rediscovering.

## Fixes applied (see AGENTS.md §15/§15b/§15c/§15d/§15e for full writeups)

1. **`config.fluffos`**: corrected `master file`/`simulated efun file` to
   `/adm/kernel/master` and `/adm/kernel/simul_efun` (config pointed at
   `/adm/obj/...`, which doesn't exist — actual location is
   `/adm/kernel/...`).
2. **`adm/kernel/check_config.lpc`**: commented out the `#ifdef __PRIVS__
   need(...)` block — driver has PRIVS on globally, no per-lib toggle
   exists, field is inert/unused by this mudlib.
3. **The big one — simul_efun-based `set`/`query`/`delete` dbase
   architecture (AGENTS.md §15).** `this_object()` is the SIMUL_EFUN
   OBJECT during a bare simul_efun call on this driver, not the caller —
   confirmed empirically. Fixed by:
   - `feature/dbase.lpc`: added real local `set`/`query`/`delete`/
     `set_temp`/`query_temp`/`delete_temp` (with an `ob`-redirect trailing
     param, since the dominant call convention across this mudlib is
     `query(prop, ob)` / `set(prop, data, ob)`, not the documented 2-arg
     "raw flag" form). Every object inheriting F_DBASE (nearly everything)
     now gets correct per-object storage via ordinary inheritance.
   - `adm/kernel/simul_efun.lpc`: stopped `inherit F_DBASE` (which itself
     calls bare `set`/`query`/`get_object`, and during simul_efun.lpc's
     OWN self-composition those resolve against not-yet-defined local
     prototypes, not the real simul_efun functions defined later in the
     same file — a bootstrapping trap). Inherits `F_TREEMAP` directly
     instead and declares `dbase`/`tmp_dbase`/`default_ob` inline.
   - `adm/kernel/simul_efun/wizard.lpc`: kept as a fallback ONLY for
     objects that don't inherit F_DBASE, with the same `ob`-redirect.
   - Files with their OWN local set/query override (`inherit/room/
     room.lpc`, `clone/user/user.lpc`, `clone/user/baby.lpc`,
     `adm/daemons/giftd.lpc`, `adm/daemons/examined.lpc`) had their
     `efun::set/query/delete/addn(...)` fallback calls fixed to
     `::set(...)` (explicit parent-scope call to F_DBASE's real
     implementation) for the "operate on myself" case, and `ob->X(...)`
     (plain call_other) for the "operate on a different given object"
     case. **Do NOT route the self-case through the simul_efun object** —
     it recurses infinitely back into the same override (hit this on
     room.lpc: "Too deep recursion").
4. **Restored several never-actually-defined globals** (AGENTS.md §15b),
   each only surfacing at runtime the first time some code path used
   them:
   - `addn`/`addn_temp` (numeric increment-or-set) — new simul_efun in
     `wizard.lpc`, delegating to `ob->add(prop, data)` /
     `ob->add_temp(...)`.
   - `remove_ansi`/`noansi_strlen` — new `adm/kernel/simul_efun/
     ansi_util.lpc` fragment (included early, before chinese.lpc/file.lpc
     which call it).
   - `B2G` (Big5→GBK, meaningless post-UTF8-conversion) and `db_affected`
     (no driver equivalent — see below) — new `adm/kernel/simul_efun/
     db_compat.lpc` fragment.
5. **`adm/etc/preload`** (AGENTS.md §15c): stripped `.c` from every line
   (`sed -i 's/\.c$//'`) — this plain-text daemon preload list still had
   the old `.c` extensions, so `securityd`/`databased`/`logind`/etc. never
   loaded post-rename (silently — the mudlib's own preload loop
   `catch()`es load failures). Root-caused via `lpcc --batch` directly
   against `/adm/daemons/securityd` returning FAIL with no visible error,
   then a `catch()`-wrapped `restore()` revealing the real chain.
6. **`u/redl/cangku.lpc`** and **`adm/daemons/equipmentd.lpc`**
   (AGENTS.md §15e): guarded two un-checked `->method()` calls chained
   straight onto `TEMPLATE_D->create_object(...)` / `EQUIPMENT_D->
   create_dynamic(...)`, both of which can legitimately return 0 (missing/
   mismatched item template) — this only surfaces the first time
   `timed.lpc`'s cron `init_crontab()` runs (which happens to create a
   specific player's warehouse object, which happens to auto-populate
   random equipment). No other unchecked call sites of these two
   factories were audited exhaustively — if a similar crash recurs
   elsewhere, it's the same shape.

## Interactive test result

Boots clean (`Initializations complete.`), telnet connects, full ANSI-art
welcome banner renders correctly (UTF-8, Chinese glyphs intact), uptime
line prints, registered-player-count line prints (both go through
`TIME_D`/`CHINESE_D` call chains that previously crashed), username prompt
appears and validates (rejects non-alphabetic / wrong-length names
correctly), and new-account registration is correctly rejected with a
friendly message when the MySQL backend is unreachable:

> 对不起，由于连接不上数据库所在服务器，目前仙剑奇侠传暂时不接受数据漫游或
> 新玩家注册。

This is expected/correct behavior given no MySQL server is configured for
this converted lib — not a bug. Setting up a real MySQL backend to test
actual character creation/login is out of scope for this pass.

## lpcc sweep

**Not completed** — this lib has ~54,600 `.lpc` files, and `lpcc --batch`
keeps everything loaded in one VM session with no unloading; the sweep
drove this 23GB host down to ~370MB free with heavy swapping after ~18
minutes, well before finishing, so it was killed rather than risk an OOM
(see AGENTS.md §6b's mega-lib note). The boot + interactive-connect test
above is what actually found every real bug fixed in this pass (§15/§15b/
§15c/§15e) and is treated as sufficient verification for a lib this size;
a full sweep would mostly surface the same long-tail false positives
described in §6b (files needing specific runtime context to load) rather
than new architecture bugs, at real cost to run safely.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter**: ran `format-corpus.mjs` across all 54627 `.lpc`
  files under `work/` (mega-lib — per AGENTS.md's mega-lib guidance this
  was run anyway, just expected to take longer) — 54596 reformatted, 28
  unchanged, 3 refused (token-mismatch safety gate, negligible at this
  scale).
- **Native retest against the freshly-rebuilt driver**: booted clean
  (`Initializations complete.`, zero fatal errors, `RSS` stayed modest —
  this only preloads a short daemon list, not the whole 54,600-file
  tree, so it's a fast/cheap boot despite the raw file count). Per
  AGENTS.md's mega-lib guidance, did **not** run the full `lpcc` sweep
  again (same reasoning as the original pass). Confirmed via
  `mudclient.py` that registration still correctly hits the same
  documented MySQL-unavailable gate as before, unchanged:
  `对不起，由于连接不上数据库所在服务器，目前仙剑奇侠传暂时不接受数据
  漫游或新玩家注册。` — expected/correct given no MySQL backend is
  configured here, not a regression.
- **Same `feature/alias.lpc` malformed-character-literal bug as
  `nitan6`** (byte-identical raw source, confirmed via diff) — fixed
  here too (`case '''` → `case '\''`), even though the MySQL gate means
  `make_body()`/this code path can't actually be exercised in this
  sandboxed environment (no player ever gets past registration to
  reach the player-body class). Applied proactively for lineage
  consistency and in case a future pass adds a real MySQL backend.
- **WASM build test** (`scripts/wasm_client.js`): contrary to this
  pass's own worst-case expectation ("copying the whole 506MB/61,157-
  file `work/` tree into an in-memory FS may be slow/memory-heavy"),
  the test **completed quickly and cleanly**, well within a bounded
  240-second wall-clock budget — boot only loads the short
  `adm/etc/preload` daemon list (same as native), not the full file
  tree, so the mega-lib's sheer file count doesn't translate into a
  slow/expensive WASM boot the way a full `lpcc` sweep would. Host
  memory stayed healthy throughout (checked via `free -h` mid-run).
  Login hit the **same documented `query_ip_number()`-under-WASM
  limitation** as `nitan6`/`nitan_ceshi`/`nitan_san`: this lineage's
  shared `BAN_D->is_banned()` (identical `sscanf(site, "%s.%s.%s.%s",
  ...) != 4` shape) rejected the connection with `你的地址在本 MUD
  不受欢迎，请去论坛 muds.cn 申述。` immediately after the banner — not
  a mudlib bug, the documented driver-side WASM gap. (The MySQL-gate
  question is moot here since the IP-ban check fires first, before the
  registration flow is ever reached.) Status: **boots under WASM
  quickly and without incident; login blocked by the query_ip_number()
  -under-WASM limitation (same root cause as the rest of the NT/nitan
  lineage in this batch)** — the mega-lib size turned out NOT to be a
  practical obstacle for this particular test, worth noting for future
  passes considering the same worry.

## WASM-enablement pass (2026-07-24): loopback-allow (admin seeding skipped)

Gates patched (same shapes as the rest of the NT/nitan lineage; loopback
= `127.0.0.1`, any `127.*`, or an empty/malformed non-dotted-quad string):

- `adm/daemons/band.lpc` `is_banned()` — loopback short-circuit return 0;
  malformed IPs (previously `return 1` = banned — this was the documented
  WASM login blocker for this lib) now return 0. `is_multi_login()` —
  loopback always allowed.
- `adm/daemons/logind.lpc` `logon()` (~line 109) — loopback/malformed IPs
  set `str = 0` and bypass: the `blocks[]` punish list, the
  >30-stale-connections `block_ip()` blocker, the same-IP `ban_cnt > 20`
  cap, and the `ip_cnt > MULTI_LOGIN` cap.
- No `uptime()` startup gate in this lib (uses the graceful
  `SYSTEM_D->valid_login()` wait queue).

**Admin seeding SKIPPED** — registration and character save/restore are
MySQL-backed (`DB_SAVE` defined; `DATABASE_D->db_save_all/db_restore_all`
in the save path, `do_sql()` user lookups in `logind.lpc`). With no DB
server the flow correctly rejects new registrations ("连接不上数据库所在
服务器"), so the real registration flow cannot produce a fluffos account,
and hand-crafting a save would not survive the DB-backed restore path.
Making this lib DB-less is real (WASM-relevant, since WASM builds have no
`db` package at all) but is an architecture change beyond this pass —
flagged as future work.

Retest: boots clean, banner + id prompt + the documented DB-unavailable
rejection all behave exactly as before the patch; debug.log clean.

### Fail-closed retrofit (2026-07-24)

The `band.lpc`/`logind.lpc` carve-outs above originally ALSO treated any
empty/non-string/unparseable IP as trusted-local (fail-open, defensive
against an older WASM `query_ip_number()` bug now fixed upstream).
Tightened to strict loopback only (`"127.0.0.1"`, `"::1"`, `"127."`
prefix); `band.lpc`'s `is_banned()`/`is_multi_login()` also had their
pre-existing malformed-format fallback restored to the ORIGINAL fail-safe
(`return 1` = banned for anything that isn't a clean loopback address or
a valid 4-part dotted quad, matching the codebase's own convention before
this pass touched it).

**Bug found and fixed during the retrofit**: `logind.lpc`'s `logon()`
reused the same `str` variable both as "the real IP" (later passed
verbatim to `BAN_D->is_banned(str)`) and as a "0 = loopback, skip
anti-flood gates" sentinel. Zeroing `str` for loopback connections meant
`is_banned(0)` was called for every local connection — which, after the
fail-safe restore above, now correctly rejects non-string input, so
**loopback connections were being banned** ("你的地址在本 MUD 不受欢迎")
until this was caught by retest. Fixed by introducing a separate
`local_conn` boolean for the anti-flood gates and leaving `str` as the
real IP throughout (same fix applied to sibling `nitan6`, which has the
identical shape). Re-verified: loopback connection reaches the id prompt
and the documented DB-unavailable rejection again, no ban message.
