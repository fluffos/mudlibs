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

## AGENTS.md §7.79 修复（2026-08-19）

裸 `addn("prop", value)`（无第三参数）恒为静默无效果，同族
（`xfbhh`/`hhsj`/`nitan170911`/`nt6`/`nt6nitan6win`）共通问题，方法
论/脚本详见 `xfbhh` NOTES.md 对应小节（同一 `fix_addn2.py`）。本 lib
`clone/user/user.lpc` 未发现命名笔误覆盖（正确命名为 `add`），只有
`clone/user/baby.lpc` 一处本地覆盖（覆盖 `addn` 未覆盖
`addn_temp`），排除其 8 处 `addn(...)` 调用。591 处改写，`git diff
--stat`：339 files changed, 591 insertions(+), 591 deletions(-)，加
上排除的 8 处，591+8=599，与调查阶段统计精确吻合（`nt6`/
`nt6nitan6win` 三个近乎同源的兄弟 lib 数字完全一致）。

验证：`build-debug` 驱动真实冷启动，端口 40019 正常监听，`debug.
log` 全程干净，无新增编译错误。本 lib 注册流程为传统英文 ID 握手
（非 xfbhh/hhsj 那种 `ver1.0` 中文字段格式），用内建 `guest` 快速
账号验证登录直达游戏世界，无报错。按精确 PID 结束驱动；测试产生的
`mrtg` 存档增量已 `git checkout --` 还原。

### ```§7.112``` residual-gap closure (2026-08-20)

Corpus re-scan (`grep -rl 'call_out("death_stage"' ... | filter for missing guard`) found unguarded `init()`-scheduled `death_stage()` call_out chain(s) in `d/death/npc/bai.lpc`, `d/death/npc/hei.lpc` that the original two-wave sweep (see AGENTS.md §7.112) missed -- same reconnect-triggered duplicate-chain bug, different filename/lineage. Added the standard `query_temp("death_stage_active")`/`set_temp`/`delete_temp` re-entry guard, adapted per file's own exit points. Compile-verified via `lpcc --batch`.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 6 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## Round-four (§10.7) deep-functional pass: combat/death, shop purchase, sect recruitment (2026-08-20)

Full session targeting the three systems this lib's own history explicitly
deprioritized in prior rounds. Native `build-debug` driver, several clean
cold reboots throughout (each verified zero `debug.log` errors on boot),
admin `fluffos`/`Mud@2026` used throughout via `wizlian`-granted stats/
skills to reach test position quickly (per this task's own sanctioned
"admin stat/skill grant" allowance) — no new test character created, no
password newly recorded.

### 1. Combat/death against a hostile NPC: major real bug found and fixed
(damage was never actually applied — a 6th/7th/8th instance of this lib's
already-well-documented F_DBASE bare-call bug); permanent death via `kill`
not reached despite extensive live testing, root cause narrowed but not
confidently classified as bug vs. design, left unfixed

Used the real `kill` command (confirmed, per this session's own project-
wide precedent, no gate against real danger for NPC targets) against
`meipo` (媒婆, 北大街's matchmaker NPC, the same representative low-level
NPC prior rounds used for safe `fight` sparring). First attempt: many
rounds of both sides only ever "sizing up" (`guard_msg` flavor text),
zero hits ever landing on either side despite `wizlian`-granted `str`/
`unarmed`/etc. Traced via `adm/daemons/combatd.lpc`'s `fight()` →
`do_attack()`: `query_action()` (same file) calls `me->reset_action()`
when `query("actions", me)` is empty, then re-reads `query("actions",
me)` — still empty, so `do_attack()`'s very first line (`action =
query_action(me, flag); if (!action) return 0;`) silently no-ops on
**every single combat round, for any character**. Root cause:
`feature/attack.lpc` (F_ATTACK) is inherited as a SIBLING of F_DBASE by
`char.lpc`, exactly like the already-documented `feature/name.lpc`/
`feature/command.lpc`/`feature/apprentice.lpc` bug family — but this file
had never been touched by any prior pass. `reset_action()`'s bare
`set("actions", ...)`/`set("second_actions", ...)` calls (no
`this_object()` redirect) silently wrote to the SIMUL_EFUN OBJECT's own
shared dbase instead of the fighting character's own, so the "fix" attempt
inside `query_action()` never actually took effect. Fixed with the
standard `this_object()`/`me` redirect pattern throughout the whole file
(not just the `reset_action()` call sites — `kill_ob()`/`want_kill()`/
`select_opponent()`/`remove_all_enemy()`/`attack()` all had the same bare-
call shape and were fixed too). Verified: after the fix + a fresh
`update`+relogin (an ALREADY-LIVE object stays bound to its old compiled
program — `update`ing the source alone does not retroactively rebind
already-loaded instances, confirmed empirically this pass; a genuine
`quit`+relogin, i.e. a fresh `new()`-cloned instance, was required each
time to observe a fix's effect), `kill meipo` produced real, varied combat
narration (hits, misses, dodges) on both sides.

With real hits landing, a SECOND, even more consequential instance of the
same bug surfaced: `feature/damage.lpc` (F_DAMAGE, via `inherit __DIR__
"limb"`, itself uninherited) is ALSO a bare sibling of F_DBASE.
`receive_damage()`/`receive_wound()` — the functions `do_attack()` calls
via `victim->receive_damage("qi", damage, me)` to actually apply a landed
hit's damage — had the identical bare `query(type)`/`set(type, ...)`
shape at their core, so **landed hits produced correct damage narration
text but the victim's real `qi`/`jing` never moved**: `meipo` visibly
absorbed 20+ hits for hundreds of damage each while `look meipo` kept
reporting "她看来身上并无丝毫伤痕" (no wounds at all). This is almost
certainly why no prior round of this lib's testing ever reached combat/
death — real damage simply never applied, at all, to anyone, ever. Fixed
the whole file with the same redirect pattern (`receive_damage`/
`receive_wound`/`receive_heal`/`receive_curing`/`receive_full`/
`dps_count`/`record_dp`/`remove_dp`/`unconcious`/`revive`/`die`/
`reincarnate`/`max_food_capacity`/`max_water_capacity`/`set_weak`/the
non-mapping-reference parts of `heal_up`) — left `heal_up()`'s large
`my = this_object()->query_entire_dbase()`-then-mutate-by-reference block
untouched, since that's a real `->` call returning a live mapping
reference, genuinely safe from this trap already. Verified: after this
fix + fresh relogin, `meipo` correctly showed escalating wound-status
flavor text (精力充沛 → ... → 已经陷入半昏迷状态，神智全失) and
genuinely fell unconscious (`COMBAT_D->announce(ob, "unconcious")`'s
"$N脚下一个不稳，跌在地上一动也不动了" text, confirmed only reachable
from `feature/damage.lpc`'s own `unconcious()`) — the first time this
lib's `qi`/`jing` combat resource pools have ever been observed to
actually deplete from real combat.

While investigating, `inherit/char/char.lpc` itself (where `heart_beat()`'s
death-check logic lives) was checked too and is clean — it inherits
F_DBASE directly, so its own bare calls correctly resolve locally; no fix
needed there.

**Permanent death not reached, root cause narrowed, left unfixed as an
honest open question (not confidently a bug, see below)**: with the two
fixes above, `meipo` cycled through real unconscious episodes repeatedly
(7-10+ confirmed across two separate ~1-2 minute continuous `kill`
sessions) but never reached the actual "扑在地上挣扎了几下...死了"
(`"dead"` announce case) death text. Read `inherit/char/char.lpc`'s
`heart_beat()` closely: it has TWO separate qi/jing threshold checks —
(1) `eff_qi<0 || eff_jing<0 || qi< -max_qi/5 || jing< -max_jing/5` →
correctly checks `killer->is_killing(...)` intent (real `kill`-command
lethal path) before choosing `die()` vs `unconcious()`; (2) a lower-
priority `qi<0 || jing<0` fallback that unconditionally calls
`unconcious()` (never checks kill intent at all, since `living(me)` stays
true right up until real death). Since `receive_damage()`'s "qi" floor-
at-`-1` mechanic means plain `qi` crosses zero on nearly every hit (long
before the much larger `eff_qi` wound-ceiling, only reduced by the
rarer wound-type hits, ever does), block (2) appears to catch nearly
every real depletion event first, resetting `qi` back to `0` via
`unconcious()` before block (1)'s kill-aware death path is ever reached
simultaneously with `eff_qi` also being negative. A temporary `log_file()`
probe placed at block (1)'s entry (removed before finishing; briefly
left `nosave/` missing on this lib, created it since several existing
call sites already expect it) never fired even once across ~10 unconscious
cycles, consistent with this theory. **Not fixed**: this needs a real
design call (should block 2 also check kill intent? should `unconcious()`
not reset plain `qi` so aggressively while `eff_qi` is still positive?)
that a mechanical bare-call redirect fix doesn't answer, and — per this
project's hard-won "pawnshop" precedent — "hard to actually kill things
in normal combat" is at least plausible as intentional NPC/civilian
toughness rather than a confirmed defect, so left untouched. Flagging
concretely for a future pass with more session budget to spare on this
one question: `inherit/char/char.lpc` lines ~97-118.

Command input while in an active, ongoing `kill`-triggered auto-fight was
also observed to be silently swallowed (no reply, no error, confirmed
with completely passive commands like `look`/`score`/`i`) for the
duration of combat — worth a dedicated look in a future pass, but not
chased further here since it didn't block the two real fixes above (both
verified via careful command sequencing around it) and might simply be
this project's already-documented telnet/raw-socket-vs-real-client
harness gap rather than a driver/mudlib bug.

### 2. Shop purchase: verified working, no bug found

`nitan170911`/this lib's own prior rounds both stopped at "correctly
rejected for insufficient funds" (content, not a bug). This round funded
a real purchase via the sanctioned admin path: `cmds/adm/gift.lpc`
(`gift <id>`, gated by `(arch)` rank, not the separate `clone`-command
`is_admin()`-only gate this lib's hardcoded superuser check blocks
`fluffos` from — confirmed `clone`/`dest`/`smash` are all gated behind
`me->is_admin()` literally hardcoded to `getuid()` ∈
`{lonely, shulele, cqpkzaz}`, which no wizlist-granted "boss" account
satisfies on this lib) granted `/clone/money/thousand-gold` ×3 among
other items. `list`/`buy cloth` at 醉仙楼 (`d/city/zuixianlou`, NOT the
`zuixianlou2` upstairs room prior rounds referenced) then correctly
deducted 1 coin-equivalent and produced real change across all four
denominations (coin/silver/gold/thousand-gold), and the `cloth` item was
received. No bug found; `MONEY_D->player_pay()`'s denomination-breakdown
math checked out exactly against the displayed post-purchase inventory.

### 3. Sect recruitment (`bai`→`xue`): two real bugs found and fixed;
full cycle completed live

The readily-reachable Beggar Sect NPCs' rejection remains correctly
identified as content (recruitment gated behind a real sect hall) —
not re-investigated, matches `nitan170911`/`xuanjianlu`. Located a real
recruiting master instead: `kungfu/class/huashan/yue-buqun.lpc` (岳不群,
Huashan Sect leader), placed via `d/huashan/qunxianguan.lpc` (群仙观,
directly reachable, no maze/gate). `attempt_apprentice()`/`do_recruit()`
gate on gender≠female, `shen`≥20000, `huashan-neigong`/`huashan-sword`
skill≥140 — granted via `wizlian` (shen/skill grants, the sanctioned
fast-path).

**Bug 1, fixed**: `do_recruit()`'s `recruit_apprentice()` override calls
`this_object()->add("apprentice_availavble", -1)` — a typo'd property
name (extra "av") that doesn't match the real `"apprentice_available"`
property `attempt_apprentice()`/`reset()` actually read/write. Since
`add()` on a never-before-set property just creates it fresh (per
`feature/dbase.lpc`'s `add()` semantics), the real recruit-limit counter
silently never decremented — the master's own dialogue ("老夫今天已经
收了三个弟子，不想再收徒了", i.e. "already recruited 3 today") became
permanently dead/unreachable code, an observably-broken intended state
transition from a literal property-name typo (not a design/balance call —
matches this project's strict in-scope bar). Same typo found and fixed
in all 4 files sharing this exact recruiter-limit pattern: `kungfu/class/
huashan/yue-buqun.lpc`, `feng-buping.lpc`, `yue-wife.lpc`, `kungfu/class/
qingcheng/yu.lpc` (a narrow, self-contained grep sweep, not corpus-wide).

**Bug 2, fixed, real compile-error blocker**: `update`ing `yue-buqun.lpc`
cascaded into `/clone/misc/pin` (a hairpin weapon he `carry_object()`s in
`create()`) failing to compile: `inherit/weapon/pin.lpc:47: Error: Bad
type for argument 1 of to_chinese ( int vs string )`. Root cause: `inherit/
item/item.lpc` (reached via `EQUIP`'s `inherit ITEM;`, which `pin.lpc`
itself inherits via `inherit EQUIP;`) defines its OWN LOCAL
`string to_chinese(int status)` (an item-rarity-tier→Chinese-name
converter, unrelated purpose) — this locally-inherited definition
SHADOWS the simul_efun `to_chinese(string)` (a generic English→Chinese-
numeral-name converter) for every file that inherits `EQUIP`/`ITEM`, so
`pin.lpc`'s dead-but-still-compiled `extra_long()` display code (calling
`to_chinese(key)` where `key` is genuinely a string attribute-requirement
name) resolved to the WRONG local function and failed to type-check —
a hard compile error, not a driver bug (confirmed reproducible in
isolation via direct `update` on the file alone). Same exact shape (same
copy-pasted `extra_long()` block) independently confirmed in `inherit/
weapon/xsword.lpc`. **Impact**: this silently broke `yue-buqun.lpc`'s own
compile whenever anything in the dependency chain (his own `create()`,
via `carry_object`) touched `/clone/misc/pin` — meaning **Huashan Sect's
leader NPC never actually spawned in the game world at all**, on every
boot, until fixed (same class of impact as this lib's earlier
`nanxian.lpc` and `is_killing()` findings). Fixed by explicitly
qualifying the intended simul_efun call as `("/adm/kernel/simul_efun")->
to_chinese(key)` in both files (an `efun::to_chinese(...)` attempt was
tried first and correctly rejected — `to_chinese` isn't a real driver
efun on this build, only a simul_efun, so `efun::` doesn't reach it;
explicit `call_other` to the simul_efun object is the correct
disambiguation). Verified: `update` on both files now succeeds, and
`goto /d/huashan/qunxianguan` confirms 岳不群 now genuinely spawns.

**Full cycle verified live**: `bai yue buqun` → "你想要拜岳不群为师" →
2s `attempt_apprentice`→`do_recruit` delay → "岳不群决定收你为弟子" →
"恭喜您成为华山派的第十四代弟子" (14th generation). `score` before/after:
`【门派】` changed from `普通百姓` to `华山派`, `【师承】` (master/
lineage) correctly shows `岳不群` — a REAL, persisted family/master
assignment via the genuine code path (not the earlier-documented
location-flavor display quirk). `xue yue buqun huashan-neigong`
correctly declined (skill already at the granted level, "你的华山内功
功力已经是非同凡响了"). `xue yue buqun huashan-shenfa` (a skill NOT
pre-granted, that he does teach per his own `set_skill` list) succeeded:
8× "你的「华山身法」进步了！" skill-improvement messages, "你听了岳不群
的指导，似乎有些心得" completion message — real skill acquisition via
the genuine teaching mechanic, not a shortcut.

### Standard checklist re-confirmation (spot-check only, per task scope)

All items previously documented as already-applied to this lib re-
confirmed still intact and not regressed by this pass's fixes: `§7.90`
(`maximum evaluation cost` still `2000000`, unchanged, no
`cost limit reached` hits in any boot log this session), `§7.100`
(`grep -rl "replace_program(ROOM)"` hits are all inside `//`-commented
dead code, matching the sweep's own documented exclusion — confirmed
`d/huashan/qunxianguan.lpc` and every room visited this pass loaded and
populated correctly), `§7.79`/`§7.108`/`§7.111`/`§7.30` — no fresh
`Bad argument`/`array usercount`-class/uninitialized-mapping errors
surfaced across this pass's several full cold boots and extended live
sessions. Every cold boot this pass: zero `debug.log` errors.

### Process/resource hygiene

Several full driver restarts this pass (native `build-debug`, port
40019) — deliberately re-booted clean after every functional fix to
confirm each fix survives a REAL cold start (not just a live `update`,
which — as documented above — does not retroactively rebind already-
loaded object instances). Killed by exact PID each time, confirmed via
`readlink -f /proc/<pid>/cwd` before each kill; several harness-side
Python `mudsession.py` helper processes from earlier reconnects were
also cleaned up by exact PID (never `pkill -f`). Tracked `data/daemon/
mrtg*` churn reverted via `git checkout --`, matching this lib's own
established precedent. Real gameplay-state file creation was kept: `fluffos`'s
own save files (stat/skill grants used throughout this pass) and a new,
previously-never-exercised `data/shop/*.o` (21 files — the city-wide
shop daemon's first-ever persisted state, created by this pass's real
`buy cloth` purchase). `nosave/` did not exist on this lib prior to this
pass (created, empty, harmless — several existing call sites, e.g.
`timed.lpc`'s crontab-failure logger, already expected it to exist).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`；两个头文件被同一个守护进程（`npcd` 等）一起包含时，后包含的印度名表覆盖马来名表，`generate_ma_name()` 生成的是印度名字。印度表改名 `in_sname`/`in_pname`（KB 04 §6.10）。
- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

1 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 村长的疗伤说明被截断

`d/newbie/npc/laocunzhang.lpc`：新手村长讲内功疗伤的那段 `msg`，`"…达到一定等级。\n\n" HIY;` 后面单独一行 `"    更多相关帮助请参阅帮助文件 help force\n\n" NOR;`——多余的 `;` 把最后一句截掉了，颜色也没有还原（`NOR` 在被丢掉的那句里）。接回去（`scripts/lpc_join_cut_strings.py`，现在也认带颜色宏的字符串）。HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理、任务杀手加载失败

`scripts/lpc_warnings.py nitan6 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 1824 个 `.lpc` 和 50 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：1762 -> 1762 通过，无回退；改过的头文件的 628 个包含者两边同为 606/607 通过（差的一个是下面的 `shashou`，随机加载失败）。手改：`adm/kernel/master.lpc` `direct_run_binary()` 的 `ob`、`vob` 只在 `#else`（BINARY_SUPPORT）里用到，声明挪进去；`adm/daemons/natured.lpc` 空语句 `lt[LT_MON];` 删去。启动时警告 11 -> 0；新进程登录（新人物确认）正常。

护送任务（`d/city/task2/renzhi.lpc`）途中一半机会刷出的杀手 `d/city/task2/shashou.lpc` 是从 xkx100 的 task2 抄来的：`create()` 里 `random(3)` 的第三种调用 `NAMES_D->jap_name()`，本库 `adm/daemons/namesd.lpc` 没有这个函数，返回 0，`name["name"]` 出错——三次里一次加载失败，`renzhi` 的 `new(ss_name)` 跟着出错，护送那一步中断；另两种用 xkx100 的写法 `({ name["id"] })`，而本库 namesd 返回的 id 已经是数组，嵌套之后 `query("id")` 是数组，玩家无法用 id 指这个杀手。修正（`scripts/lpc_nitan_jap_name.py`）：namesd 补上 `jap_name()`（名表取自 xkx100 `adm/daemons/named`，返回本库的数组 id），shashou 直接传 `name["id"]`。验证：HEAD 单独加载 3 次 1 次失败；修正后 8 次全过；探针连续 `new` 30 个，`query("id")` 都是字符串且 `id()` 认得。
（更正：本库没有任何 task2 以外的文件生成 `renzhi` 或发 `miling`，这个护送任务目前没接进游戏，上面的杀手修正是在休眠内容里。）

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 9 处比较、0 处去后缀（如 `clone/npc/qingyun.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。
使命任务：`adm/daemons/taskd.lpc` `alloc_task()` 的 `room[<2..<1] != ".lpc"` 让每个房间都被拒，`rooms -= ({ room })` 又拿 `zone + 名字` 去减只有名字的列表，于是无限重抽，`taskd` 从来加载不起来——玩家的 `task`、`locate` 指令只显示“这里发现了臭虫”。改正切片和列表（列表空了就停）；真正走房间之后首次冷加载要 5 秒以上，`maximum evaluation cost` 提到 10000000（nt6 原本就是最大值）。新进程建人物后 `task` 列出使命物品、`locate` 可用；HEAD 两者都失败。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 4 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 4 个，只在 #if 分支用的声明移进分支 6 个文件；改动 14 个文件，HEAD 与工作树各载入一次无回退（14 objects; HEAD PASS 14, tree PASS 14; regress 0; newly loading 0），这些文件的警告 39 -> 2。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `adm/daemons/combatd.lpc` 反击：`your_temp["guarding"];` 丢了 `= 0`（ES2 原版是 `set_temp("guarding", 0)`），一次防守姿态可无限次触发反击；补上 `= 0`。
- `clone/obj/genmap.lpc`/`traverser.lpc`：`DEBUG` 是空宏，调用处留下 `("text", n);`；改成空函数 `varargs void DEBUG(string fmt, mixed arg) {}`。
- `d/guiyun/jiuguan.lpc`（12 处）、`*/song/obj/bingfu.lpc`：`query_temp("cai_" + (i + 1, me) + "/name")` 是把 `me->query_temp(...)` 改写成 `query_temp(..., me)` 时括号放错，逗号表达式让键变成 `"cai_" + me + …`，酒馆菜单前移、兵符统军列表都读不到；改为 `query_temp("cai_" + (i + 1) + "/name", me)`。
- `d/death/qiao1.lpc`：`if (dir == "north") { /* … */ }` 只剩注释的空块，把 `if` 一起挪进注释（行为不变）。
- `kungfu/skill/miaojia-jian/gan.lpc`、`zhai.lpc`：`string name() { HIY "…" NOR; }` 少了 `return`，招式名为 0；补 `return`。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 6）

- 补齐前几批漏掉的同码副本：`your_temp["guarding"];` 补 `= 0`（反击后清除防守姿态，含 `u/` 下的 combatd 拷贝）；`(: WEAPON_D, "query_action" :)` 改为 `(: call_other, WEAPON_D, "query_action" :)`（KB 04）；`mysql_d.lpc` 的空 `MSG` 宏改成空函数；`gigicook.lpc` 的 `arg == menu_list[0]` 改为 `=`。
- 改动文件：u/lonely/combatd.lpc 
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件的警告 **103 -> 0**（`lpc_warnings.py` 全库重扫，22637 个文件可编译；剩下的警告都在本来就编译不过的文件里，如 `feature/dealer1.lpc`、`inherit/self/armor/armor.lpc`、`clone/pharmacy/herb/herb.lpc`）。改动的对象、包含改过头文件（`dbase.h`、`d/yixing/doc/info_*.h`）的对象，加上 `clone/`、`d/city`、`d/xiangyang`、`d/shaolin`、`feature/`、`inherit/`、`adm/daemons/`、`cmds/` 的抽样，HEAD 与工作树各载入一次（新进程）：`2823 objects; HEAD PASS 2734, tree PASS 2734; regress 0; newly loading 0`。删除声明审计 0 处待看。

**严重问题：F_DBASE 旁边的混入件读写 simul_efun 的共享 dbase（KB 05 §7.15 残留，与 nitan170911 同一处）。** 本库 `include/dbase.h` 没有属性函数原型，`feature/equip.lpc`、`itemmake.lpc`、`food.lpc`、`liquid.lpc`、`pill.lpc`、`alias.lpc`、`message.lpc`、`name.lpc`、`damage.lpc`、`dealer.lpc`、`banker.lpc`、`guarder.lpc`、`apprentice.lpc`、`unique.lpc`、`control.lpc`、`inherit/char/master.lpc`，还有 nitan170911 漏掉的 `feature/action.lpc`（忙乱的 `apply/avoid_busy`、`reduce_busy` 读不到自己的）、`condition.lpc`（中毒的 `apply/avoid_poison` 等）、`move.lpc`（移动时 `query("equipped")`、`env/brief`、`guardfor`）都不继承 F_DBASE，裸 `query()`/`set()` 编译成 simul_efun 的后备函数，读写所有物件共用的那一个 dbase（之前 `apprentice`、`name`、`damage` 等已经逐处改成 `query(x, this_object())`，其余没改）。探针（新进程）：修正前给店小二 `wield` 长剑返回 0，`query_temp("weapon")` 为 0、`equipped` 没写进兵器；`wear` 布衣同样失败；自制道具（`inherit SWORD; inherit F_ITEMMAKE;`）`wield` 失败、`query_autoload()` 恒为 `"kept"`。修正：`include/dbase.h` 补上与 `feature/dbase.lpc` 签名完全一致的 `set/query/delete/set_temp/query_temp/delete_temp/add/add_temp` 原型（照搬 nitan170911），上述混入件都 `#include <dbase.h>`；`adm/daemons/npcsd.lpc`、`cmds/adm/eval.lpc` 不是 dbase 物件，去掉它们的 `#include <dbase.h>`；`feature/save.lpc` 也被不带 F_DBASE 的守护进程继承，那里两处 `query("id")` 改成 `this_object()->query("id")`，不加原型。修正后探针：`wield` 返回 1、`weapon` 指向长剑、`equipped == "wielded"`，`wear` 写入 `armor/cloth`、`equipped == "worn"`，自制道具 `wield` 成功、`query_autoload()` 为 `"wielded"`。

**自制道具的 autoload。** 玩家自制道具（`adm/npc/ganjiang.lpc` 运行时生成的 `inherit 兵器基类; inherit F_ITEMMAKE;`）每件都报 `query_autoload()/autoload() inherited from both`。照 nitan170911：itemmake 的这对改名 `query_itemmake_autoload()`/`itemmake_autoload()`，`inherit/item/item.lpc` 与 `combined.lpc` 的 `query_autoload()`/`autoload()` 先看 `function_exists()`，有就交给它；驱动原来选的就是 itemmake 那对，行为不变，警告消失（探针确认）。

**其他（多数与 nitan170911 同码，`scripts/lpc_twin_port.py` 搬过来）：**
- `clone/misc/swmuding.lpc` 神木王鼎重新声明了木鼎的 `insects` 表，木鼎代码读的是自己那份，神木王鼎的虫表从没生效；改名 `sw_insects`，在 `create()` 里赋给 `insects`。
- `adm/npc/obj/xiang.lpc` 的 `varargs int remove() { save(); }` 盖掉了 F_MOVE 的 `remove()`（减负重、清 handing）；改为先存盘再 `::remove(euid)`。
- `d/city/npc/oldman.lpc` 宠物体重表 `weight` 与 F_MOVE 同名，改名 `pet_weights`；`maze/forest/maze.lpc` 的 `unique_rooms` 改名 `forest_unique_rooms`；`template/gem/*`、`template/weapon/*` 自己又声明了基类的 `dbase_format` 等，改名 `my_*`。
- 幻境 `fairyland_quest` 的变量重复声明、`d/yixing/doc/info_*.h` 加头文件守卫、`ultra_questd`/`invent`/`meng-zhu`/`tianshen`/`canhezhi` 的宏重定义（`#undef`）、`channeld.lpc`（含 `u/lonely/` 拷贝）里从没用过的 `GWIZ` 频道位宏被 `<net/dns.h>` 覆盖，删去（频道表本来就直接写 256）。
- `attempt_apprentice()`/`close_gate()` 返回类型与基类一致（`void`）；`html_d.lpc` 的 `?:` 两边类型；多余的 `;`、重复继承 `F_CLEAN_UP`、未用局部变量；`u/mike/tt.lpc` 的 `s[-1]` 改 `s[<1]`。

未解决：`u/mike/eval.lpc`（eval 指令留下的临时文件，本身编译不过）会让 `lpcc` 段错误：`s[..<1]` 里 `s` 未声明时，驱动报完 `Bad type of left index to range operator` 后空指针崩溃（HEAD 同样，驱动问题，待做最小复现）。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。21 个文件 26 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/clone/npc/walker.lpc`（`pot *=`）、`/clone/npc/walker.lpc`（`score *=`）、`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/quest11/flagwar/flagd.lpc`（`reward_money *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 hhsj/nt6 同源同修）：36 个技能文件的 `int power_point()` 返回 0.6–1.4 的浮点（含分支写法），经 int 返回被截断；本库没有调用者，改为 `float`、保留原数值（`scripts/lpc_fix_float_hooks.py`）。当铺售价和 simul_efun `ntefun.lpc` 的 `sqrt` 写明 `to_int()`，simul_efun 能载入。改动的 244 个对象载入无回退。

- 2026-10-14：`inherit/item/item.lpc` 自己定义了 `string to_chinese(int status)`（物品品质名：普通/优良/珍稀/史诗/传说/神器/仙器），把 simul_efun 的 `to_chinese(string)`（技能、属性译名）遮住了；继承它的兵器、装备、药书显示“装备要求”或技能名时调用 `to_chinese(key)`，旧驱动不查类型，传进字符串只会落到最后一个分支，装备要求一律显示成“仙器”；新驱动直接报 `Bad type for argument 1 of to_chinese ( int vs string )`，这些文件整份不编译。照 nt7 的做法把本地函数改名为 `to_ch_desc()`（`short()` 里的品质调用随之改名）。新进程比对 HEAD 与工作树：166 个对象，新增载入 164，回退 0。

- 2026-10-14：39 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；5 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：44 个对象，新增载入 37，回退 0。

- 2026-10-14：`foreach` 里把 `array` 当类型（`foreach (string type, array data in news)`），本驱动不认；改为 `mixed *`（`scripts/lpc_fix_array_type.py` 现在也处理 foreach 变量）。`cmds/usr/history.lpc` 现在载入；`adm/daemons/realnews_d.lpc` 还调用本驱动没有的 `to_default_encoding()`，仍不编译。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/pangen-cuojiefu`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。29 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。


## 缺失的转世守护进程 `/adm/daemons/scbornd`（2026-10-15）

`SCBORN_D` 在 globals.h 中有定义，原始存档却只有 `help/scborn`，没有守护进程本身。绝招文件在每次施展时都调用 `SCBORN_D->valid_perform()`，`force.h` 的 `valid_public()` 调用 `valid_learn()`，天界入口和通天老仙调用 `check_data`/`check_data2`/`start_scborn`：全部报 `couldn't find object`。新增一个替身 `adm/daemons/scbornd.lpc`：对所有人回答“未曾转世”，转世本身仍不可进行（与存档一致），但上述调用不再报错。


## 去烦恼指 `qufannao-zhi`（2026-10-15）

该技能 `inherit F_DAMAGE`，其中 `query`/`query_temp` 的成员原型遮住了 simul_efun 的 `query(prop, ob)`，于是 `valid_learn`/`practice_skill` 报 `Undefined function called: query_temp`。改为 `me->query_temp(...)` 等直接调用。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。2 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 2 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。


## 摆摊状态的指令路径（2026-10-15）

`kungfu/condition/baitan.lpc` 调用 `/cmds/std/baitan.lpc`，指令实际在 `/cmds/usr/baitan.lpc`。已改正路径；本库摆摊指令用 `start_busy()`，目前没有地方施加这个状态，属于未接线的代码。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。10 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`canhe-zhi`、`chongling-jian`、`duoluoye-zhi`、`feifeng-bian`、`huashan-zhang`、`murong-jianfa`、`sougu-yingzhua`、`xuedao-daofa`。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：弹指神通 `tanzhi-shentong/dian` 点灵台穴（攻方读 `query("max_neili", me)`，守方却读成 0）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`five_poison`→`five-poison`（`/clone/medicine/poison/redyao`、`/clone/medicine/poison/shenxiandao`、`/clone/medicine/poison/whiteyao`、`/clone/medicine/poison/wuxing`、`/clone/medicine/poison/yellowyao`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`jiemie-zhua`→`jimie-zhua`（`huzhua-claw`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`lingboweibu`→`lingbo-weibu`（`lingbo-weibu`）；`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/yi`）；`meiren-shanzhao`→`meiren-sanzhao`（`meiren-sanzhao/fengzi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 密宗猴拳「震」最重的一档报错（2026-10-15）

`/kungfu/skill/mizong-houquan/zhen` 按伤害分档写描述：前几档都是 `pmsg = ...`，最后一档（伤害 ≥ 80，也就是最重的一击）却写成 `pmsg += ...`，而 `pmsg` 没有初值，本驱动里 `0 += 字符串` 直接报错，这一招打得最狠时反而中断。改为 `pmsg = ...`。

## 擒龙手「擒龙打」每次都报错（2026-10-15，KB 06 §7.246）

`qinlong-shou/qin` 要求空手施展，却在出招前执行 `wn = weapon->name();`：局部变量 `weapon` 从没赋值，`wn` 也没人用，每次使用都报 `Bad argument 1 to EFUN call_other()`。删去这一行和两个没用的局部变量。


## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。4 处（4 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。


## 拜堂时请不来月老（2026-10-15）

苏州媒婆（`d/suzhou/npc/meipo`）和红娘（`adm/npc/hongniang`）拜堂时 `new("/d/suzhou/npc/yuelao")`，本库这个 NPC 放在 `d/ruzhou/npc/yuelao.lpc`（文件头仍写着旧路径，与 nitan3 等库的 `d/suzhou/npc/yuelao.lpc` 逐字节相同）：`new()` 得 0，`moon->move(room)` 报错，婚礼停在拜堂之前。两处都改为 ruzhou 的路径。媒婆从拜堂到送入花轿的整个流程在测试里走通。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

34 个文件、43 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/clone/weapon/blade1`、`/d/dali/npc/obj/zipao`、`/clone/armor/cloth.lpc`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步；其余 32 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`S_RING` → `/inherit/gems/ring`（11 个文件）、`F_GEMS` → `/feature/gems`（4 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：15 个里 4 个通过，其余 11 个还有别的错误（`clone/gem/ring.lpc`：Fail to load object /clone/gem/ring.；`clone/gem/ring0.lpc`：Fail to load object /clone/gem/ring0.；`clone/gem/ring1.lpc`：Fail to load object /clone/gem/ring1.……）。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 58 个对象设了本库没有文件的武功（75 个名字，最多的是 `yijin-jing`、`qiantian-yiyang`、`tianlong-xiang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：30 个里 18 个通过，其余 12 个停在别的错误上（`d/shiliang/quest/npc/wenfangshan`：*No program in object '/d/shiliang/quest/npc/wenfangshan'!；`d/shiliang/quest/npc/wenfangwu`：*No program in object '/d/shiliang/quest/npc/wenfangwu'!……）。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 108 处、46 个文件：`yijin-jing`→`yijinjing`（36 处）、`yunu-xinjing`→`yunv-xinjing`（20 处）、`yunu-shenfa`→`yunv-shenfa`（12 处）、`shaolin-shnfa`→`shaolin-shenfa`（7 处）、`shenzhao-jing`→`shenzhaojing`（6 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`moshen-jianda`→`moshen-jianfa`（3 处）等共 20 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 6 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `ARMOR_D(x)`、`BINGQI_D(x)`、`BOOK_D(x)`、`CLONE_DIR`、`MAZE_D`、`TIME_TICK`，用到它们的物件（名单里 46 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。补完后名单里有 4 个载入，其余还差别的东西。（`scripts/lpc_restore_defines.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 载入不了的零碎文件（2026-10-19，KB 03 §4.7、KB 04 §6.10）

- `d/shenlong_bak/jushi.lpc`、`sea.lpc`、`sea2.lpc` 里 `me->name() + "\241\243\n"` 的 `\241\243`（GBK 的「。」写成八进制转义，旧驱动把这两个字节原样发给 GBK 客户端）改成「。」；新驱动报 `Invalid UTF8 codepoint in string literal`，三个房间（共 4 处）载入不了。

逐个载入与 HEAD 对比，没有退步。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 缺失的 unew()（2026-10-19，KB 06 §7.262）

本库的 NPC 和兵器在 `create()` 里调用 xkx 一系的模拟函数 `unew(file)`（`new()`，但遵守物件的 `unique` 上限），`/adm/kernel/simul_efun/object.lpc` 里没有，调用者全部报 `Undefined function unew`（以及接收结果那一行的 `Bad assignment ( object vs unknown )`），载入不了。补上和 dtsl、pkuxkx、sjpl2 等库一样的 `unew()`（文件不存在时返回 0，不会让调用者死在 `carry_object()` 里）。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 帮派文件里丢掉的引号（2026-10-19，KB 03 §4.6）

- `d/yixing/doc/set_bang.h` 第 82、84 行：两句帮主的话，最后半个字连同结尾的引号一起丢了（`…景仰之情<乱码>);`），下一行的开头引号把它闭合，后面的汉字被当成代码（`Illegal character 0xe8`），宜兴帮主 `d/yixing/npc/bangzhu.lpc` 从来载入不了。字串照 nt7 里完好的拷贝补回（`犹如滔滔江水连绵不绝。`、`帮主的敬仰犹如黄河泛滥一发不可收拾。`），引号补上。
- 同一文件第 45 行 `level = ceil( pow( … ) ) * 4 / 5;` 把浮点数存进 int，补 `to_int()`。

载入 `d/yixing/npc/` 的 bangzhu、biaotou、bangzhu2、cl_bei：HEAD 通过 3 个，现在通过 4 个（`bangzhu.lpc` 现在载入），没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`cross pubu`（穿瀑布）永远回答“你要往哪儿穿？”，瀑布后面的密室进不去。改动：`/adm/daemons/kingward.lpc`（1 处）、`/adm/daemons/ward.lpc`（1 处）、`/d/baihuagu/yangfeng.h`（1 处）、`/d/gumu/liangong1.lpc`（1 处）、`/d/tiezhang/hhyuan-3.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/cmds/usr/mazemap.lpc`（1 处）、`/inherit/room/mine_field.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 21 处）。改动：`/adm/daemons/competed.lpc`（2 处）、`/adm/daemons/intermud2_d.lpc`（2 处）、`/adm/daemons/xinruid.lpc`（2 处）、`/clone/game/mj.lpc`（3 处）、`/clone/game/mjlady3.lpc`（3 处）、`/cmds/wiz/roomlong.lpc`（1 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/hangzhou/npc/meipo.lpc`（1 处）、`/d/yaowang/huichun/npc/zhanggui.lpc`（1 处）、`/quest/weixiaobao.lpc`（1 处）、`/quest11/budai.lpc`（1 处）、`/quest11/shediao/yang.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/kernel/simul_efun/object.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/adm/daemons/battlefieldd.lpc`（1 处）、`/adm/daemons/storyd.lpc`（1 处）、`/adm/kernel/importer.lpc`（1 处）、`/cmds/adm/refsum.lpc`（4 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/include/getconfig.h`（1 处）。

## `d/luoyang/obj/xiang.lpc`：`chuangli` 先 `explode(read_file("/log/PARTY"))`（2026-10-20，KB 06 §7.326）

关帝像的 `chuangli`（`kaibang`）指令在检查年龄和经验之前就读 `/log/PARTY`，那是运行中的 mud 记录已创立帮派的文件，全新的树里没有，`explode(0)` 报 `Bad argument 1 to explode()`：任何人敲 `chuangli 什么` 都是系统错误，而不是“你还嫩着呢”。改成 `file = read_file("/log/PARTY") || "";`（空串的 `explode` 是空数组）。xkx100utf8 和 nt7 是 gitlink 库（fluffos-org 上游），同一行在那里没有改。加载检查各 1/1。

## `vote` 的 `jail`、`unjail`、`unchblk` 编译不过：计票被改坏了（2026-10-20，KB 04 §6.21）

xkx100 的原文是 `vc = victim->add("vote/count", 1);`，nitan 系把它写成了 `addn("vote/count", 1, vc = victim);`：`vc` 是 `int` 票数，却被赋成了对象 `victim`（`Bad assignment ( int vs object )`），`addn()` 的返回值（新的票数）丢掉了，后面的 `df = vv - vv / 2 - vc` 因此没有意义。改回 `vc = addn("vote/count", 1, victim);`（循环里的 `-1` 也一样，共 5 处）；`addn()` 是本库 sefun，返回 `ob->add(prop, data)`。加载检查：三个文件 HEAD FAIL → tree PASS。nt7 是 gitlink 库，没有改。

## `mroom`（帮会房间生成）读不到 `dir_pre`（2026-10-21，KB 04 §6.16）

`cmds/bunch/mroom.lpc` 的 `valid_room_position()` 和建房流程用 `dir_pre` 当帮会目录前缀，库里没有任何头文件或变量声明它（`include/bunch.h` 只剩 `room_desc_l`、`max_exits`、`r_dir`、`vdirs`，整个语料里也没有 `dir_pre` 的定义），整个命令编译失败：`Undefined variable 'dir_pre'`。`adm/daemons/bunchd.lpc` 里 `BUNCH_HOME "/data/bunch/"`（`BUNCH_HOME + id + "/center.lpc"`，模板目录 `/d/room/bunch/` 复制到那里）和 `valid_room_position()` 的路径算术（前缀 `explode()` 三段、房间路径五段，差 2，返回第四段即帮会 id）对得上，所以在 `mroom.lpc` 里加 `#define dir_pre "/data/bunch/"`。nt6、nitan170911、nitan6、hhsj、xfbhh 的 `mroom.lpc` 逐字节相同，同一处改法；加载检查 HEAD 0、树 1。没有改：nt7（gitlink）同一文件；tianxia 的 `cmds/bangzhu/mroom.lpc` 用的是 `BANGHUI_DIR`，但那里的 `banghui_d` 自己就有类型错误和未声明的变量加载不了。

## `ability`：继承的 `/feature/ability` 档案里没有（2026-10-21，KB 04 §6.18）

管理员扫描里 `ability`（玩家指令 `cmds/usr/ability.lpc`）报 `Inherited file '/feature/ability' does not exist!`：指令 `inherit F_ABILITY`（`#define F_ABILITY "/feature/ability"`），而档案只带 `feature/ability.txt`（家族能力的设计笔记），没有源码，这条指令从来加载不了（`bas_ability`、`fam_ability`、`valid_ability_improve()`、`do_ability_cost()`、`improve_ability()`、`get_ability_info()` 都该在那个文件里，本库别处没有人用）。nitan170911、nt7、hhsj、wdxtym 把同一套接口放在可继承的 `/adm/daemons/abilityd.lpc`（947 行，指令里 `F_ABILITY` 指向它），但那是后一版：能力编号改成 1-35、消耗加了潜能、门派能力由 5 项变 30 项，不是本库当年的表。没有补，留在 `scratchpad/librarian-next.txt` 里等用户决定。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/arch/recovermud.lpc`。

## 任务分配 `quest`：按顺序找目标的备用循环用了 `living[j]`（2026-10-21，KB 06 §7.347）

`/feature/quest.lpc`：先随机挑目标（`j = random(sizeof(living))`），挑不中再“按顺序找”：`for (i = 0; i < sizeof(living); i++) if (check(living[j], ...)) { target = living[j]; break; }`。下标写成了 `j`（上一个循环最后一次的随机下标），备用循环把同一个 NPC 检查 `sizeof(living)` 遍，世界小的时候任务就分不出去。xkx100 的原文就是这样，派生库照抄。改成 `living[i]`。

## `combatd.lpc` 的阵法防御：先问 `ob->is_busy()`，后给 `ob` 赋值（2026-10-21，KB 06 §7.348）

对手在阵里、气或精低于 40% 时执行 `!ob->is_busy() && objectp(ob = victim->query_array_obstructor())`，`ob` 此时是 0，`do_attack()` 在战斗中途抛错。hhsj、nitan170911、nitan3、nitan_ceshi、nitan_san 是 `objectp(ob = ...) && !ob->is_busy()`，对调回来。`u/lonely/combatd.lpc` 是巫师的开发副本，不动。改动：`/adm/daemons/combatd.lpc`。

## 追杀任务 `killer1.lpc`：奖励循环里的 `me` 从没赋值（2026-10-21，KB 06 §7.348）

黑衣人 `die()` 对每个在场的追杀者发经验和潜能，循环里写的是 `me->add("combat_exp", exp)`（nitan 系是 `addn("combat_exp", exp, me)`），`me` 要到循环之后才被 `find_player(owner)` 赋值：xkx100 系抛 `Bad argument 1 to call_other()`，nitan 系把奖励悄悄记到 0 上，追杀者什么也拿不到。循环里先 `me = obs[i];`。改动：`/clone/quest/killer1.lpc`。

## 马钰 `waiting()`：等了 300 秒没等到的惩罚落在没赋值的 `ob` 上（2026-10-21，KB 06 §7.348）

七星阵的等待超时分支写的是 `ob->add("score", -5000)`（nitan6 系 `addn("score", -5000, ob)`），`ob` 在这个分支里还是 0：超时那一刻抛错，之后的 `do_back` 已经排好了所以只是少了惩罚。hhsj、nitan170911、xfbhh 里同一处写的是 `me`（带着任务的玩家），照改。改动：`/kungfu/class/quanzhen/ma.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`ruanweijia` / `yuxiao`：`return_to_zhang` → `return_to_huang`（携带者在战斗时的重试从不发生，宝物一直留在玩家手里）；张无忌：`destrory` → `destroy`。改动：`/clone/lonely/ruanweijia.lpc`、`/clone/lonely/yuxiao.lpc`、`/kungfu/class/mingjiao/zhangwuji.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 27 条注册（17 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/beichou.lpc`（`do_join`）、`/adm/npc/jierishizhe.lpc`（`do_vendor_list`）、`/adm/npc/referee.lpc`（`do_halt`）、`/clone/medicine/nostrum/gaoyao.lpc`（`do_eat`）、`/clone/misc/city/city.lpc`（`do_chakan`）、`/d/beijing/npc/tiegongji.lpc`（`do_bcheck`、`do_bcun`、`do_bqu`）、`/d/changan/npc/tiegongji.lpc`（`do_audit`、`do_bcheck`、`do_bcun`、`do_bqu`）、`/d/city/npc/qian.lpc`（`do_bcheck`、`do_bcun`、`do_bqu`）、`/d/city/npc/tang.lpc`（`do_check`）、`/d/gumu/npc/obj/qingci-ping.lpc`（`do_add`） 等共 17 个文件。最多的函数名：`do_bcheck` 3 处、`do_bcun` 3 处、`do_bqu` 3 处、`do_halt` 2 处、`do_audit` 2 处。没有动（读过）：`/d/kongdong/npc/mu.lpc` 的 `give_quest`（对象本身编译不过，登记留着，等对象能加载再处理）、`/d/kongdong/npc/mu_bak_xli.lpc` 的 `give_quest`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest11/jiuyin/zhou.lpc` 的 `do_answer`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest11/jiuyin/zhou.lpc` 的 `do_learn`（对象本身编译不过，登记留着，等对象能加载再处理）、`/quest11/tlbb/murong-fu.lpc` 的 `do_lingwu`（对象本身编译不过，登记留着，等对象能加载再处理）。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 1 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/yixing/npc/bangzhu.lpc`（`do_xue`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。6 个文件里 8 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 6 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 5 个，现在 5 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 8 个函数没有补（other 4, inquiry 4）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/adm/daemons/intermud2_d.lpc`:`receive_support_answer`、`/adm/daemons/npcsd.lpc`:`exert_function`、`/adm/daemons/npcsd.lpc`:`perform_action`、`/d/yixing/npc/bangzhu.lpc`:`ask_skills`、`/inherit/banghui/smith.lpc`:`is_money`、`/quest11/jiuyin/zhou.lpc`:`questions`、`/quest11/kuihua/linzhennan.lpc`:`test_dart`、`/quest11/tlbb/liao-huo.lpc`:`ask_for_join`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 99 个文件里有 175 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/using`、`nosave/security`、`nosave/party_quest` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave/guilei` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 3 个子目录写日志：`log/job`（`d/xueshan/obj/jitan.lpc`）、`log/money`（`d/suzhou/npc/meipo.lpc`）、`log/test`（`d/baituo/npc/shenu.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/job`、`log/money`、`log/test` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 2 行只含这个指针的行（`"武功": (: ask_skills :),` `"skills": (: ask_skills :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 36 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 36 处（26 个文件）：拼名字的赋值 22 处、与汉字常量比较 13 处、`to_chinese()[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:135`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:41`）；`name[4..5]` → `name[2..2]`（`/kungfu/class/quanzhen/chu.h:80`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 全局头文件里的宏，`carry_object` 守卫以前看不见：44 处（2026-10-22，KB 06 §7.361）

`config.fluffos` 的 `global include file` 会被驱动塞进每个对象，文件里没有写 `#include` 也能用 `ARMOR_D("shoes")` / `BINGQI_D("langya-bang")` 这类宏；`lpc_guard_carry_object.py` 的宏表只读文件自己写出来的 `#include`，认不出它们，第 46 批 `--macro` 把这些行整个跳过了——NPC 在 `create()` 里 `carry_object(ARMOR_D("shoes"))->wear()`，文件不存在，`new()` 答 0，`->wear()` 抛 `Bad argument 1 to EFUN call_other()`，NPC 加载不了。宏表现在加上全局头文件；本库 44 处改成守卫块（缺文件就不穿，文件回来照旧穿）。证明（HEAD / 工作树加载对比，只含改过的 `.lpc`）：HEAD 加载失败的对象里有 10 个现在能加载，0 退步（quest11 的镖师、金蛇、九阴、葵花、天龙八部各路 NPC 等）。其余仍失败的文件失败在别的原因（`Unable to find the inherited function`、`Undefined variable 'RNAME_D'`），不属于这一类。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/npc/luban.lpc:1765`）；`if ((strlen(name) < 2) || (strlen(name) > 10)) {`（`/d/city/npc/petseller.lpc:184`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 8 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。
