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

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter**: ran `format-corpus.mjs` across all 23120 `.lpc`
  files under `work/` — 23042 reformatted, 25 unchanged, 53 refused
  (token-mismatch safety gate, expected/fine at this scale).
- **Native retest against the freshly-rebuilt driver, going further than
  the original pass**: booted clean (`Initializations complete.`, zero
  fatal errors). The earlier conversion pass's interactive test stopped
  at "Chinese surname/given-name entry" — this pass pushed all the way
  through to actually entering the game world, and found a **new,
  genuinely blocking bug** (present in the raw archive itself, not
  introduced by conversion or the reformatter — confirmed identical in
  `raw/nitan/nitan/nitan/feature/alias.c`):
  `feature/alias.lpc`'s `process_input_basic_parse()` had
  `case ''':       //' cmd = "say " + cmd[1..];` — an unescaped/invalid
  single-quote character literal (`'''`), a hard compile error (`Illegal
  character constant`) on this driver. Since `feature/alias.lpc` is
  `#include`d into `inherit/char/char.lpc`, which every player body
  (`USER_OB`, via `clone/user/user.lpc`) inherits, this **broke
  compilation of the player body class entirely** — `make_body()` in
  `logind.lpc` would fail with `*No program in object '/feature/alias'!`
  at the exact moment gender is confirmed during registration, silently
  aborting character creation for **every single new player**, with no
  visible error to the connecting user (just a bare fall-through to an
  unhelpful default command loop). This is a real, pre-existing
  content bug that simply hadn't been exercised by testing before (the
  original pass's registration test never got as far as gender
  confirmation/`make_body()`). **Fixed** (same shape as AGENTS.md §9's
  fullwidth-punctuation-in-code-literal family, just a different
  malformed character-literal variant): changed to
  `case '\'':       // '` (properly escaped single-quote literal),
  restoring the intended "leading `'` means shorthand for `say`" alias
  behavior. Re-verified: full registration (`qflibnw`/`秦风霜`) now
  completes end-to-end, reaching `/d/register/entry.lpc`'s in-fiction
  "泥潭注册室" (registration room in 混沌届/"chaos realm") — this lib
  layers an extra `register <email>` step *after* character creation,
  before the character is considered "born" (a real design choice, not a
  bug: `look`/`score` reply "还没有出生呐" — "not born yet" — until
  `register <email>` is run). Ran `register test13@qq.com` → moved into
  生命之谷 ("Valley of Life") with a real room description and NPC
  (万物之神), confirming the world is genuinely reachable and playable
  post-fix. Zero fatal errors in `debug.log` (the room does print its
  own in-fiction `WARNING 这里发现了臭虫` bug-report hint — that's
  mudlib content, not a driver error). **The same exact bug (byte-
  identical raw source) also exists in `nitan170911`'s `feature/
  alias.lpc`** (shared lineage) — fixed there too, see that lib's NOTES.
  Did **not** re-investigate the previously-documented name-display
  quirk in this lib's own content — left exactly as-is, per this pass's
  scope note.
- **WASM build test** (`scripts/wasm_client.js`): boots cleanly (only
  the expected non-fatal preload warnings). **Login is blocked by the
  documented `query_ip_number()` WASM limitation**, this time via
  `adm/daemons/band.lpc`'s `is_banned(site)`: `if (sscanf(site, "%s.%s.
  %s.%s", tmp1, tmp2, tmp3, tmp4) != 4) return 1;` — a textbook instance
  of the exact `sscanf`-based site-ban shape AGENTS.md's WASM section
  already calls out. Under WASM, `query_ip_number(ob)` doesn't return a
  real dotted-quad string, the `sscanf` fails to match 4 parts, and
  `is_banned()` returns `1` (banned) unconditionally — rejecting the
  connection at the very top of `logon()`, before the encoding/banner
  even fully renders, with `你的地址在本 MUD 不受欢迎，请去论坛
  muds.cn 申述。` (“your address isn't welcome here”). **This is the
  documented driver-level WASM gap, not a mudlib bug** — the exact same
  `band.lpc`/`logon()` code path works fine natively (this pass's own
  native retest above completed full registration with zero issues).
  Not patched, per the standing policy. Status: **boots under WASM;
  every connection is immediately banned by the query_ip_number()-under-
  WASM limitation** (same root cause as the project's other documented
  cases, this time the ban check triggers before any prompt is even
  shown, the earliest-possible manifestation of this limitation seen in
  this batch).

## WASM-enablement pass (2026-07-24): loopback-allow + throttle bypass + admin seeding

Gates patched (loopback = `127.0.0.1`, any `127.*`, or an empty/malformed
non-dotted-quad string, which is what current WASM builds return; in
`logon()` a loopback/malformed IP sets `str = 0`, and every per-IP gate
below is now `str &&`-guarded):

- `adm/daemons/logind.lpc` `logon()` (~line 109) — loopback bypasses:
  the `blocks[]` punish-list check, the >30-stale-connections
  `block_ip()` blocker, the same-IP `ban_cnt > 10` cap, and the
  `ip_cnt > MULTI_LOGIN` same-IP multi-login cap.
- `adm/daemons/band.lpc` `is_banned()` — loopback short-circuit return 0;
  malformed IPs (previously `return 1` = banned — the WASM login killer
  in this lineage) now return 0. `is_multi_login()` — loopback always
  allowed.
- No `uptime()` startup gate in this lib (it uses a
  `SYSTEM_D->valid_login()` boot-wait queue instead, which is graceful —
  left alone).
- Kept (game design): 30-minute new-account quit-retention self-delete.

Admin account: `fluffos`, normal password `Mud@2026`, 管理密码
`Mud@2026admin`, Chinese name 浮浮, granted `(boss)` (top rank) via
`/adm/etc/wizlist`. Verified: real-flow registration, wizard-password
warning branch on re-login, `update /adm/daemons/band.lpc` succeeds,
`goto` works, birth flow completed (register email + choose/washto/born),
`score` renders. **Trap discovered and documented**: deleting a
wizard-ranked account via the 30-min quit self-delete makes securityd
REWRITE `/adm/etc/wizlist` without that account — this silently wiped the
first seeding attempt; re-seeded and avoided quit-based exits for
fluffos since. Fresh normal registration re-verified end-to-end in two
sessions (testqb: create, then re-login → register email → choose/washto/
born → look/score → quit self-delete). Tracked runtime churn
(`data/daemon/mrtg*`) reverted via `git show HEAD:`. debug.log clean.
Save files for the orchestrator: `data/login/f/fluffos.o`,
`data/user/f/fluffos.o`, `data/user/f/fluffos.package.o`.

### Fail-closed retrofit (2026-07-24)

Same correction and same bug as documented in detail on sibling
`nitan170911` (identical `logind.lpc`/`band.lpc` shapes): the loopback
carve-out originally ALSO trusted any empty/non-string/unparseable IP as
local (fail-open); tightened to strict loopback only, restored
`band.lpc`'s original fail-safe (malformed format ⇒ banned) below the
carve-out, and fixed a real bug where `logon()`'s reuse of `str` as both
"the real IP" and a "0 = skip anti-flood gates" sentinel caused
`BAN_D->is_banned(str)` to be called with `0` for every loopback
connection — which, after restoring the fail-safe, started rejecting
loopback logins outright. Introduced a separate `local_conn` flag; `str`
now stays the real IP throughout. Re-verified in one continuous session:
fluffos login, `look`, `update /adm/daemons/band.lpc` (succeeded), clean
reconnect — no regression from the tightening.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

Real playthrough pass per AGENTS.md §10.7. Per the task brief, first
checked `nitan6` for the same F_DBASE bare-call architecture shapes that
`nitan170911`'s deep-test pass found and fixed (AGENTS.md §7.15,
`nitan170911/NOTES.md`'s "深度功能测试" section) — confirmed byte-
identical pre-fix content in the equivalent files (`diff` against
`nitan170911`'s post-fix versions showed only the same mechanical
`this_object()`-redirect delta), then ported the same fixes proactively
and verified live, before doing an independent full playthrough.

### DB backend check: not needed for this lib

`include/unixconf.h` (`#define DB_SAVE 1`) is only reached when
`__PACKAGE_LONELY__` is defined; `include/globals.h` includes
`winconf.h` otherwise (`#undef DB_SAVE`), and neither `config.fluffos`
nor any `.lpc` in this tree defines `__PACKAGE_LONELY__`. So `DB_SAVE`
is undefined here, `clone/user/user.lpc`'s `save()`/`restore()` take the
`::save()`/`::restore()` (plain file-based) branch, and the whole
`DATABASE_D->db_*` chain is dead code for actual gameplay in this
sandboxed environment — no MySQL/MariaDB was needed or stood up for this
pass, confirming this NOTES file's own earlier finding ("this lib's
registration flow does NOT require a live MySQL connection"). The
`databased.lpc` fix below was still applied (same rationale as
`nitan170911`'s `feature/alias.lpc` fix: proactive, for lineage
consistency and in case a future pass enables `__PACKAGE_LONELY__`), but
is **not exercised live** in this pass.

### Ported fixes: same F_DBASE bare-call bug, confirmed present, fixed and verified

**1. `feature/name.lpc`** — confirmed byte-identical pre-fix content to
`nitan170911`'s (before its own fix). Every bare `set()`/`query()` call
(no `this_object()` redirect) in `set_name()`/`set_color()`/`id()`/
`name()`/`short()`/`long()` silently operated on the SIMUL_EFUN object's
shared dbase instead of the caller's own — `query_idname()` was already
the one function with the correct workaround. Fixed identically to
`nitan170911`: added explicit `this_object()` redirects throughout.
Live-verified: fresh registration (`xiakebug`/秦风) produced a real,
correctly-set player name end-to-end (`score`/`look`/room population all
show "秦风" correctly), and zero `debug.log` errors across the whole
registration→born→explore→quit-decline flow.

**2. `feature/command.lpc`** — same bug, `enable_player()`'s
`query("id")`/`query("name")` (feeding `set_living_name()`). Fixed with
`this_object()` redirects, matching `nitan170911`'s identical fix.
Live-verified indirectly: no `set_living_name()` argument-type errors
appeared in `debug.log` across the whole session (player and every NPC
encountered set up cleanly).

**3. `adm/daemons/databased.lpc`** — `db_restore_all()`'s ten
unguarded `restore_variable()` calls on legitimately-`NULL` DB columns
(same shape as `nitan170911`'s bug #2). Guarded each with `stringp()`,
falling back to each setter's expected empty type. **Not live-exercised**
in this pass (see DB-backend note above) — ported for lineage
consistency/future-proofing only, verified only via `lpcc` (compiles
clean, no `Fail to load object`).

**4. `adm/kernel/simul_efun/message.lpc`** — `tell_object()`/
`tell_room()`/`shout()`/`write()`/`say()` etc. all called bare
`message()` above its own definition later in the file with no forward
prototype, binding to the raw driver EFUN instead of the local
exclude-argument-normalizing wrapper (same shape as `nitan170911`'s bug
#3; this file's local `message()` wrapper already had the `exclude ||
({})` normalization, but that alone was insufficient since callers above
it never reached it). Added the missing forward prototype + `varargs`.
Live-verified: no "Bad argument 4 to EFUN message()" in `debug.log`
across logins, room `tell_room()` calls (combat, `ask` NPC dialogue,
room population), and the registration countdown banner's own direct
`message()` call.

### New (fifth) instance of the same bug found independently in this lib: `feature/apprentice.lpc`

**Not one of `nitan170911`'s four documented fixes** — found by
noticing `score`'s `【门派】` (sect) field showed a NON-DEFAULT value
(`丐帮`, i.e. "Beggar Sect") on a character whose every live `bai`
(apprenticeship) attempt had been explicitly rejected
("既不属於任何门派，也没有开山立派，不能拜师"). Investigated instead of
shrugged off, per §10.7's "actually play it" bar. Root cause:
`inherit/char/char.lpc` does `inherit F_APPRENTICE` (=
`feature/apprentice.lpc`) as a SIBLING of `inherit F_DBASE`, exactly
like `feature/name.lpc`/`feature/command.lpc` — but this file was never
touched by `nitan170911`'s pass (its own equivalent `bai` attempts were
also all rejected early, so the bug never surfaced there either; not
independently confirmed present-but-unfixed on `nitan170911`, flagged
here for a follow-up check). Every bare `query()`/`set()` call in
`is_apprentice_of()`, `assign_apprentice()`, `create_family()`,
`recruit_apprentice()`, `query_bunch()`, `query_family()`,
`query_master()`, `query_generation()` that operates on `this_object()`
(as opposed to the small number of calls that already correctly
redirect to a distinct `ob` parameter) hit the identical bootstrapping
trap — meaning sect/family membership data (`family/family_name`,
`family/master_name`, `family/generation`, `title`, `class`,
`can_not_change`, etc.) for every character in the game was being
read from and written to the ONE shared SIMUL_EFUN OBJECT dbase instead
of each character's own. Fixed with the same explicit `this_object()`
redirect pattern as the other four files (calls already redirecting to
`ob` left untouched). Verified via `lpcc` against the composed
`/inherit/char/char.lpc`: compiles clean, no `Fail to load object`.

**Not fully root-caused live, documented honestly**: after this fix,
`score` on the SAME long-lived test character (`xiakebug`) still shows
`【门派】丐帮` even though `xiakebug`'s own last-saved dbase (`data/user/
x/xiakebug.o`) has no `"family"` key at all — meaning the in-memory
value was set live, correctly, on `this_object()`'s own dbase, by
*something* during this session (plausibly a real, non-buggy piece of
content logic tied to physically being in `/d/gaibang/inhole` — the
Beggar Sect hideout `xiakebug` is standing in for the rest of this
session — rather than a residual bug; no `set("family"...)` call was
found in that room's or its NPCs' visible `create()`/`init()` in the
time available). Given the character's own `bai` attempts were all
explicitly rejected, this is left as an **honest open question** rather
than asserted as fixed or as a bug — a follow-up pass should `unset`/
inspect `family/family_name` on a freshly-registered, never-`bai`'d
character standing OUTSIDE any sect territory to isolate whether this is
content (a location-flavor display) or a genuinely separate issue.

### New bug found and fixed, unrelated to the F_DBASE class: `is_killing(object)` vs `is_killing(string)` type mismatch — hard compile failure, two NPC files

`feature/attack.lpc:58` declares `varargs int is_killing(string id)`
(the target's `query("id", ob)` string, matched against a `string
*killer` array of ids) — the sole definition of `is_killing()` in this
codebase, and the convention at 100+ other call sites throughout the lib
is `is_killing(query("id", ob))`. `/d/city/npc/gongzi.lpc:55` and
`/d/city/npc/guidao.lpc:55` (two near-identical "disguised bandit boss"
NPCs — 落魄公子/鬼刀王五) instead called `is_killing(who)`, passing the
raw `object who` parameter directly. Since both call sites are BARE
(inherited, not `->`) calls, the driver's static type checker rejects
this at compile time: confirmed via direct `lpcc` invocation, `error:
Bad type for argument 1 of is_killing ( string vs object )` followed by
`Fail to load object /d/city/npc/gongzi.lpc.` — a hard compile failure,
not a warning. Confirmed this is the SAME shape live during actual
preload/lazy-compile of `guidao.lpc` (triggered indirectly by an
`lpcc` verification run against the file it's inherited into): the
identical error line appears in `log/debug.log`.

**Impact confirmed non-crashing but silently broken**: both NPCs are
listed in real, reachable rooms' `set("objects", …)` population maps
(`guidao` in `/d/city/zuixianlou2.lpc`, the 醉仙楼 second floor —
directly reachable from the inn mentioned in this lib's own newbie doc;
`gongzi` referenced from several quest kill-target files). `inherit/
room/room.lpc`'s `make_inventory()` calls `new(file)` with no `catch()`
and immediately calls `ob->is_ctl_ob()` etc. on the result — but this
driver's `call other type check` is disabled (config), so a failed
`new()` (returning `0`) makes every following `0->method()` call
silently return `0` instead of erroring, so the ROOM itself does not
crash (this differs from AGENTS.md §7.25's crash shape) — the NPC just
silently never spawns, forever, with only a compile-time diagnostic line
as any trace of why. This is a genuinely new, narrower variant of that
existing pattern; see draft classification in the final report (not
added to AGENTS.md directly, per this task's instructions).

Fixed both call sites to `is_killing(query("id", who))`, matching every
other call site's convention. Verified via `lpcc`: both files now
compile clean (no `Fail to load object`), and a broader grep confirmed
these were the only two bare (non-`->`) `is_killing()` call sites in the
whole lib passing anything other than a string.

### Observation, NOT fixed (out of scope / too broad to mass-fix safely): `target->is_killing(me)` passing an object via `call_other`

Found while investigating the above: ~60 call sites across many
independently-authored `kungfu/skill/*.lpc` files (mostly life-force-
draining skills — 化功大法/吸星大法/北冥神功 and similar — plus a
handful of NPC files) call `target->is_killing(me)`, passing an
**object** (`me`) through a `call_other`. Unlike the two bare-call sites
above, `call_other` isn't statically type-checked on this driver (`call
other type check: 0`), so this does NOT fail to compile — but at
runtime, `is_killing(object)`'s `member_array(id, killer)` compares an
object against a `string *` array and can never match, so these checks
always evaluate `false` regardless of actual combat state. Traced
`kill_ob()` (feature/attack.lpc) and confirmed it's internally idempotent
via its own `member_array(query("id", ob), killer) == -1` guard, so the
practical effect is a redundant `kill_ob()` re-invocation (with its
"looks like X wants to kill you" message correctly suppressed on repeat)
rather than a crash or obviously-broken player-visible symptom — this
looks like a genuine latent logic bug (the intended "skip re-triggering
if already fighting" optimization never fires), but is spread across
~60 pre-existing files from many different original authors, each
needing individual verification, well beyond this pass's time budget and
squarely in "long-tail, fix only where it surfaces live" territory per
AGENTS.md §6b's mega-lib guidance (same treatment as this lib's own
already-documented `array usercount` typo class, §15f). Left unfixed;
documented here with concrete file:line examples
(`kungfu/skill/huagong-dafa/hua.lpc:58` etc.) for a future pass.

### Observation, NOT fixed (likely content, not a bug): misleading exit hint text

`d/newbie/npc/laocunzhang.lpc:1452` (the `closeeye` gift's success
message) tells the player "老村长说道：你现在到村口找花伯（指令 [1;31mask
lao about 出村[0m）吧" — but the NPC at the village gate is 花伯 (id
`hua`), not 老村长 (id `lao`); the correct command (confirmed live, and
matching this same file's OWN correct phrasing elsewhere at line 465,
and `d/newbie/npc/huabo.lpc`'s room/NPC text) is `ask hua about 出村`.
Not a functional blocker — `ask lao about 出村` at the village center
still works (老村长 has his own, differently-worded "出村" handler that
gives a smaller flavor response without moving the player), room
descriptions and 花伯's own prompt at the village gate correctly say
`ask hua`, and a player exploring normally reaches the real exit menu
regardless. This reads as a copy-paste text typo (content), not a
programming bug — left untouched per this task's scope note, documented
here as an honest observation.

### Playthrough: registration → born → explore → combat → sect-hall visit, all live

Full continuous session, one test character throughout:

- **Newbie doc read first**: `doc/help/newbie` is an index;
  `doc/help/newbie-basic` (titled for a differently-named sibling
  project, "侠客行" — shared boilerplate across this lineage, not a
  bug) documents the safe `fight` sparring verb, `set wimpy`, the
  `bai`/`xue` teacher pipeline, shops/bank at 醉仙楼/钱庄, and the
  扬州武庙 default spawn — all confirmed matching live behavior below.
- **Registration**: username → confirm-new-character → Chinese surname/
  given-name (`秦`/`风`) → admin password → normal password → gender →
  countdown → `register <email>` (this lib layers this extra step
  before "born", per the existing NOTES above) → `choose 1` (性格) →
  `washto 20 20 20 20` → `born 扬州人氏` → landed in `古村` tutorial
  village (`世界之树`). **Zero `debug.log` errors** across this entire
  chain (this is the exact chain the four ported fixes above make work
  — before the fixes this whole chain was confirmed byte-identical to
  `nitan170911`'s pre-fix breakage).
- **Tutorial village**: `ask lao about here` (topic menu) → `west`/
  `east` navigation (room `.lpc` source read to confirm exits) →
  `closeeye` (organic skill-grant path): six basic skills
  (force/dodge/unarmed/sword/blade/parry) all jumped to level 164/59%,
  +53207 combat exp, +102753 potential — matches the newbie doc's
  description of the tutorial gift exactly. `ask hua about 出村` at the
  village gate → menu → `1` (直接出村) → landed at `武庙`/`扬州城`
  (钱庄/客店/醉仙楼 all present, matching the newbie doc's description)
  with a further +50000 exp/+100000 potential exit bonus.
- **`score`/`look`/`i` at every major state change**: confirmed correct,
  fully-populated output at registration, post-`born`, post-`closeeye`,
  post-exit-to-city, and after every reconnect (see below) — attributes
  (20/20/20/20 washed), skills, inventory (starter book/shoes/cloth),
  exp/potential all consistent and persisted correctly.
- **Safe sparring**: `set wimpy 60` then `fight meipo` (the matchmaker
  NPC on 北大街, same representative NPC `nitan170911`'s pass used) —
  multi-round non-lethal exchange exactly matching the newbie doc's
  description of `fight` as the safe verb; `halt` correctly disengaged
  ("你身行向后一跃，跳出战圈不打了").
  `fight`/`halt` both confirmed live, working.
- **Skill/sect acquisition, two paths**: organic path (`closeeye`, see
  above) fully exercised and successful. Direct `bai` path attempted
  against four different low-rank Beggar Sect NPCs
  (`qin shang`/`tian da`/`zuo quan`/`ding bang`) in the tree-hollow
  hideout (`中央广场` → `enter dong` → `/d/gaibang/inhole`, same "hidden
  tree-hollow passage" zone shape as `nitan170911`'s pass) — all
  consistently rejected ("既不属於任何门派，也没有开山立派，不能拜师"),
  matching the same "recruitment gated behind a real sect hall, not the
  newbie-adjacent representative NPCs" content shape already documented
  for `nitan170911`/`xuanjianlu` — not a bug, not chased further.
- **Shop purchase attempted, correctly rejected (no money)**:
  `list`/`buy cloth` at 醉仙楼 correctly rejected ("店小二冷笑道：
  穷光蛋，一边呆着去！") since the fresh character has no money — matches
  `nitan170911`'s own identical finding, not a bug. `check` (bank
  command) at the wrong room correctly fell through to a different
  command overload, same shape already documented for `nitan170911`.
- **`quit`**: correctly gated behind this lib's own documented 30-minute
  new-account quit-retention rule (`cmds/usr/quit.lpc`, real wall-clock
  `time() - query("birthday")` check) — confirmed the confirmation
  prompt fires correctly and declining (`n`) correctly aborts the quit
  and resumes play, with zero `debug.log` errors. The full aged-past-30-
  minutes clean-quit-then-relogin persistence path was **not completed
  live** in this pass — see "not verified live" below.
- **Net-dead disconnect + reconnect, prompt AND after a real wait**:
  every session in this pass ended by simply letting the mudclient
  connection close without `quit` (net-dead), and every subsequent
  reconnect showed "重新连线完毕" (silent resume) and landed back in the
  exact same room with fully-intact state — exercised both with short
  gaps between commands and, near the end of this pass, after a real
  multi-minute idle gap (session uptime counter moved from "十三分三十
  秒" to "二十二分二十九秒" between two reconnects with no player
  action in between) — state (location, attributes, exp/potential,
  inventory) all confirmed intact across that gap. Zero `debug.log`
  errors and the driver process remained alive and responsive
  throughout (no recurrence of AGENTS.md §10.8's driver-fatal crash
  class was observed in this pass, though the net-dead window achieved
  was well short of the 900s `NET_DEAD_TIMEOUT`).

### Explicitly NOT verified live (time budget / harness constraints)

- **A genuine clean `quit` past the 30-minute new-account retention
  window, then a cold relogin, confirming persisted state survives a
  real save/restore round trip.** The retention window was reached in
  real wall-clock terms during this pass, but the harness this pass ran
  under does not support an uninterrupted long blocking wait
  immediately followed by the next scripted command in the same
  operation, and by the time that was resolved, wrapping up the pass
  took priority over re-deriving a fresh multi-minute wait. Everything
  UP TO this point (registration, persistence of washed attributes/
  skills/inventory/exp across many net-dead reconnects, including after
  a real multi-minute gap) was independently verified live via the
  file-based `::save()`/`::restore()` path (confirmed the active path
  in this lib, since `DB_SAVE` is undefined — see above), so a clean
  `quit`+relogin round trip through the SAME save path is very likely
  to behave identically, but this specific round trip was not directly
  observed and is not claimed as verified.
- **Progressing to real combat/death against a hostile NPC or a real
  duel.** Time budget went to the F_DBASE bug chain and the
  `is_killing()` compile-error bug above instead, both far more
  consequential findings than a routine combat/death check would have
  been.
- **A full `bai`→`xue` cycle against an actual sect-recruiting master**
  — every readily-reachable Beggar Sect NPC declined to recruit (see
  above); reaching one that does was not attempted within the time
  available.

### Test character

`xiakebug` / 秦风 (surname 秦, given name 风), password `TestPass123`,
admin password `AdminAAAA1`. Kept (matches project precedent of leaving
representative test characters as evidence). Final live state: personality
光明磊落, attributes washed to 20/20/20/20, six basic skills at level
164 each, ~53207 combat exp / ~102853 potential, standing in
`/d/gaibang/inhole` (丐帮树洞内部, Yangzhou), inventory has the starter
book/shoes/cloth. Save files: `work/data/user/x/xiakebug.o`,
`work/data/login/x/xiakebug.o` — **note**: these on-disk files predate
the final live session (character was never re-`save`d after the last
`apprentice.lpc`-fix-era `score` check), so the on-disk `family` key is
absent even though the live in-memory `score` showed `丐帮` — see the
"not fully root-caused" note above.

### Process/resource hygiene

Native driver run from `libs/nitan6/work/` (port 40019), driver's own
stdout captured to a scratch file per AGENTS.md §10.8 (no crash of the
`ref count 0`/`free_string` class observed in this pass; scratch file
removed before finishing). No Docker/MariaDB was needed (see DB-backend
note above). Driver killed by confirmed PID/cwd before finishing.
Tracked runtime churn (`data/daemon/mrtg.o`, `data/daemon/mrtg/
mrtg.conf`) reverted via `git show HEAD:`, matching this lib's own
established precedent from the WASM-enablement pass. Ad-hoc `lpcc`
single-file verification runs against this lib's own `config.fluffos`
were used throughout to confirm each fix compiles clean (`Fail to load
object` absent) — note for future passes: these runs share the same
`log/debug.log` path as the live driver and appear to **truncate/
replace** rather than append to it, so `debug.log` line-count deltas
during a pass that also runs ad-hoc `lpcc` checks are not a reliable
signal by themselves; the driver's own captured stdout (§10.8's
existing recommendation) remained the authoritative source of real
runtime errors throughout this pass.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

NT/nitan 血统；游戏内品牌为"笑傲江湖"。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）被识别为巫师账号（"没有设置巫师专用密码"的提示按预期出现，只是装饰性警告），干净地进入游戏世界，quit 干净。和 nitan_ceshi（041）、nitan_san（041-1）是同一家族/同一流程。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 76 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## Round-two re-test (2026-08-14): post-driver-upgrade re-verification

Standard round-two §10.7 pass against the rebuilt driver (`~/src/fluffos`
post PRs #1343/#1344, plus the corpus-wide `%`-on-float fix). This lib
was in the round-one-only queue. Unlike `nitan170911`, `DB_SAVE` is
undefined here (confirmed again this round, same reasoning as the
2026-07-24 pass's DB-backend-check section), so a real live playthrough
was practical and used throughout, rather than the light/grep-only path
`nitan170911`'s round-two pass had to fall back to (no MySQL/Docker
available in this environment).

### 1. Re-verified every previously-documented fix is still in the code

All confirmed present and unchanged, by direct grep against the current
source (not trusted from NOTES.md prose):

- `feature/name.lpc` / `feature/command.lpc` / `feature/apprentice.lpc`:
  all three still carry their `this_object()` redirects (22/15/22
  occurrences respectively) — the F_DBASE bare-call bootstrapping-trap
  fix.
- `adm/daemons/databased.lpc`: still has 48 `stringp(...)` guards around
  `db_restore_all()`'s `restore_variable()` calls.
- `adm/kernel/simul_efun/message.lpc`: forward prototype
  (`varargs void message(...)`, line 15) still present before its
  callers.
- `feature/alias.lpc`: the single-quote character-literal fix
  (`case '\'':`) is intact — re-verified this is not just present but
  load-bearing, since a fresh `bai`-flow `fight`/`halt` session below
  depends on the whole player-body class compiling.
- `d/city/npc/gongzi.lpc` / `d/city/npc/guidao.lpc`:
  `is_killing(query("id", who))` still in place at both call sites (no
  regression to the old `is_killing(who)` bare-object-argument shape).
- `adm/daemons/mudlistd.lpc`: `mixed *usercount` (not bare `array`) and
  the `seteuid(getuid())` call in `create()` both still present.
- `timed.lpc`'s crontab loader: the `catch()` guard around
  `load_object(table[1])` is intact.
- The fail-closed loopback retrofit: `logind.lpc` still has the separate
  `local_conn` boolean (distinct from the real `str` IP variable, used
  throughout `logon()`'s anti-flood gates), and `band.lpc`'s
  `is_banned()`/`is_multi_login()` still do the strict-loopback check
  with the fail-safe restored below the carve-out.

### 2. Standard checklist

- **Kernel simul_efun `file.lpc`'s `assure_file()`**: defined at line
  13, textually before its only two callers `log_file()` (line 37) and
  `sys_log()` (line 127) — already correctly ordered, no fix needed
  (matches `nitan170911`'s clean result on the same check).
- **`config.fluffos`'s `maximum evaluation cost`**: `2000000` — above
  this task's 1000000 floor, so left unchanged per the literal
  threshold. Note for a future pass: AGENTS.md §7.90's fifth instance
  (`zjdyaryl`) shows a lib can still trip a `cost limit reached` abort
  at exactly this value under background daemon `heart_beat()` load; no
  `cost limit reached` hits appeared in this pass's own boot+session log
  (`grep -c` returned 0), but this wasn't a multi-hour idle soak, so the
  ceiling isn't proven safe long-term — worth bumping to `5000000`
  preemptively if a future pass has spare time, not urgent enough to do
  blind in this one.
- **`cmds/wiz/update.lpc`'s `present(file, environment(me))` crash
  (§7.106)**: already correctly guarded —
  `if (environment(me) && (obj = present(file, environment(me))) && ...`
  short-circuits before calling `present()`. No fix needed.

### 3. New bug found and fixed: corrupted byte sequences (embedded NUL +
non-UTF8 codepoints) in `adm/npc/nanxian.lpc` — hard compile failure,
broke a real, newbie-doc-referenced NPC

Not part of the original conversion pass's or the 2026-07-24 deep-test's
findings — surfaced live this round when a room populate (客店, the
inn) lazily triggered a nearby compile chain that touched this file.
`adm/npc/nanxian.lpc` (南贤, "武林泰斗「天下至贤」南贤" — an admin/
gift-dispensing NPC at 武庙, the default new-character spawn temple)
failed to compile entirely: `lpcc`/`update` reported `Illegal embedded
NUL byte (0x00) in source` at two separate spots (lines 491 and 787)
plus an `Invalid UTF8 codepoint in string literal` at line 787, with
three cascading `syntax error, unexpected ';'` at lines 812/820/828
(the parser losing its place after the corrupted literal, not
independent bugs) — ending in `*No program in object '/adm/npc/
nanxian'!` on every load attempt. Confirmed via direct hexdump: line
787's string literal contains a real `0x00` byte followed by six
Private-Use-Area Unicode codepoints (U+E139, U+E308, U+E431, U+E433,
U+E0E9, U+E4E2) mixed in with otherwise-valid UTF-8 — not a driver bug
and not something this pass's own tooling introduced (the corruption
predates this session; the shape looks like a lost/unmapped legacy
GBK user-defined-character region from long before this project's
conversion pipeline touched the archive, though the raw `nitan6.zip`
itself is password-protected and wasn't decrypted to confirm the
byte-for-byte origin).

**Impact**: `d/city/wumiao.lpc:34` calls `("/adm/npc/nanxian")->
come_here()` unconditionally from a prominent, always-reachable room —
every server boot, `nanxian` silently failed to spawn at 武庙, and
`d/newbie/npc/huabo.lpc`'s own newbie-hint text ("到扬州武庙(南贤)处
输入指令 ask nanxian 新手福利 还可领取新手福利!") pointed players at
an NPC that was never actually present. `inherit/room/room.lpc`'s
`make_inventory()` calling `new()` with no `catch()` (same non-crashing-
but-silently-broken shape as the `is_killing()` bug documented in the
2026-07-24 pass) meant this never showed up as a room-level crash,
just a permanently-missing NPC with only a compile-time diagnostic
as any trace.

**Fixed** by recovering the original, uncorrupted text from
`nitan170911`'s byte-identical copy of the same shared file (confirmed
matching surrounding structure line-for-line): line 787 (live code,
`ask_reborn()`'s "already reincarnated 3 times" branch) restored to
`"$N对$n一拱手，道：你已经历过三世轮回了，我看就不用了吧！\n"`; line
491 (dead code inside a `/* */` comment, `ask_me2()`'s commented-out
`message()` call) restored to `" 领取二小时的高效练功时间开始计时。
\n"`. This is a straight content restoration from a confirmed-clean
sibling in the same lineage, not an invented rewrite — same precedent
as this lib's own earlier `feature/alias.lpc` single-quote fix and the
F_DBASE-family ports, just sourced from a different sibling file this
time. Verified: `update /adm/npc/nanxian.lpc` now reports `重新编译
/adm/npc/nanxian.lpc：成功！` with zero errors, and live `goto /d/city/
wumiao` confirms `南贤(nan xian)` now actually appears in the room
population (previously absent every time this room was checked).

**Not independently confirmed on `nitan170911`** — that lib's own
`nanxian.lpc` is the SOURCE of the recovered text (i.e. already clean
there), so no parallel fix was needed on that sibling. Worth a quick
grep sweep across the other ~15 libs sharing this exact file
(`hhsj`, `wxddym`, `nitan_san`, `nt1`, `nt6`, `nt6nitan6win`,
`yanhuangwuhun`, `xfbhh`, `ntii`, `yhyxs`, `hy5`, `nte`, `nitan_ceshi`,
`yhwhpublicfi`, `zhonghua2`, `hymud`) for the same two corrupted spots
in a future pass — not done here, out of this pass's scope (this task
is a single-lib re-test, not a corpus sweep), but flagged since the
corruption is clearly pre-existing/upstream rather than something
`nitan6` alone picked up.

### 4. Open question from the 2026-07-24 pass resolved: the `【门派】丐帮` display was location-flavor, not a bug

The prior pass left this as an honest open question (`xiakebug` showing
`丐帮` in `score` despite no `bai` success and no `"family"` key in the
on-disk save). This round, `xiakebug` was reconnected fresh (net-dead
reconnect, no wizard `goto`) and landed in `客店` (扬州城 inn), OUTSIDE
`/d/gaibang/inhole` — `score` now shows `【门派】普通百姓` (the default,
"ordinary civilian"), not `丐帮`. This confirms the earlier hypothesis:
the sect-name display was tied to physically standing in the Beggar
Sect hideout room (content/flavor, not a persisted or buggy state
change) — the character's actual saved `family` data is, and always
was, empty. No code change needed; documenting this as resolved so a
future pass doesn't re-open it.

### Playthrough summary this round

Native driver booted from `libs/nitan6/work` (port 40019), stdout
captured to `/tmp/nitan6_boot.log` per the debug.log-truncation
caveat (no ad-hoc `lpcc` used this round — all compile checks went
through live `update` instead, so `debug.log` itself stayed reliable
too). Admin login (`fluffos`/`Mud@2026`): wizard-password warning
banner appeared as expected, landed in 巫师休息室, real write access
confirmed via `update` on `guidao.lpc`/`gongzi.lpc`/`nanxian.lpc` (all
non-self files), `goto /d/city/zuixianlou2` confirmed `guidao` (王五)
actually spawns and responds to `look`, `goto /d/city/wumiao` confirmed
`nanxian` spawns post-fix. `xiakebug`/`TestPass123` login: state
(53207 combat exp / 102853 potential / washed 20/20/20/20 attributes /
six basic skills, `阅历163`) persisted correctly across the driver
rebuild and every reconnect. Two full reconnect cycles exercised: a
net-dead disconnect+reconnect (`重新连线完毕`, silent resume, same
room/state) and a real `quit`+relogin (correctly gated by the 30-minute-
equivalent quit-flood guard — `"你距上一次退出时间只有十二秒钟，请稍候
再登录"` on an immediate retry, succeeded cleanly ~15s later). Zero
`debug.log`/stdout errors across the whole session except the
`nanxian.lpc` corruption (fixed above) and the routine compile-time
`Unused local variable`/`Unknown #pragma` warning noise already present
pre-session. `grep -c "cost limit reached"` on the captured stdout: 0.

Driver killed by exact PID (`kill 1646569`, confirmed dead via `ps`),
never `pkill -f`. `git status --short libs/nitan6/` after the session
showed the expected `data/daemon/mrtg*` churn (reverted via `git
checkout --`) plus real save-file updates for `fluffos` and `xiakebug`
(kept, matching this lib's own established precedent) and the
`nanxian.lpc` fix (kept).

### Net result

One new, genuine, previously-undiscovered programming bug found and
fixed (`adm/npc/nanxian.lpc`'s corrupted string literals — a hard
compile failure silently removing a newbie-doc-referenced NPC from the
game's default spawn room). Every previously-documented fix
independently re-verified present and correct. Every standard-checklist
item checked; two were already clean, `maximum evaluation cost` left as
literally-in-range but flagged for a preemptive bump next time there's
spare budget. The prior pass's one open question (`丐帮` display) is now
resolved as location-flavor content, not a bug.

## AGENTS.md §7.100 修复（2026-08-19）

同族（`nt6`/`nt6nitan6win`/`hhsj`/`xfbhh`/`nitan170911`）共享的
`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：本 lib 4925 个房间文件的 `create()` 末尾都有这一行多余调
用，同款地雷也烤进了自带建房工具 `clone/misc/roommaker.lpc` 的字符
串拼接代码生成模板。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`
（`d/huangshan/banshan.lpc` 有两处独立调用，均删除），加上
roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：4926
files changed, 1 insertion(+), 4928 deletions(-)，与预期精确吻合。

验证：`build-debug` 驱动真实冷启动，端口 40019 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`Mud@2026` 登录正
常，`goto` 走访 14 个刚修复的房间（`d/kaifeng`/`d/changan`/
`d/wuxi`/`d/huashan`/`d/hangzhou`/`d/huanggong`/`d/ruzhou`/
`d/northft`/`d/wuyi`），均正常返回，无 "cannot replace"/"cannot
bind" 新增日志行。按精确 PID 结束驱动；测试期间产生的 `mrtg`（第三
方流量统计）及 `fluffos` 账号存档增量已全部 `git checkout --` 还
原。
