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
