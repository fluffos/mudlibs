# `git clone https://github.com/fluffos/nt7` → `nt7`

- Source: `git clone https://github.com/fluffos/nt7` (王者归来, "泥潭7").
  Adapted per AGENTS.md §2.3 (already-git-hosted, already-FluffOS-
  adapted source), not a raw archive extraction — mudlib root IS the
  repo root (`config.ini`: `mudlib directory : .`). Repo history goes
  back to a `nt7 for fluffos v2019` initial commit plus a handful of
  community fixes (`调整登录，增加GBK端口`, `修正代码`, `修正部分BUG`
  from contributor `oiuv`/`steyeu`) and, most recently, two commits from
  this project's own author fixing the exact `Bad argument 4 to EFUN
  message()` bug (§6.4-ish/`message()` varargs-exclude class) and
  seeding the `fluffos` admin account (§1.5) — i.e. **this specific
  GitHub repo had already been independently worked on by this
  project's maintainer before being folded into the monorepo here.**
  Both of those pre-existing fixes were verified still present/intact
  in the cloned source and left as-is.
- **Encoding**: verified, not assumed — every `.c`/`.h` file in the raw
  clone decodes as valid UTF-8 (0/30,337 failures via a full-tree
  Python UTF-8 decode check). `scripts/convert_lib.sh` run anyway per
  §2.3's "run it unconditionally" lesson (`UTF-8` as the source
  encoding arg, so the whole pass is a no-op on content, just the
  mechanical `.c`→`.lpc` rename + literal-reference fixups): 29,920
  `.lpc` files, 8,757 literal `.c"` refs fixed, 166 files' `static`→
  `nosave`, 2 lossy-conversion files (`help/ntbook`, cosmetic help text).
  Repo-only cruft (`.github/`, `.vscode/`, `scripts/pack_for_web.sh`,
  a stray `git_status` dump file) stripped from `work/` — not part of
  the mudlib itself.
- Port: **40211** (pre-assigned).

## Status: native + WASM playable, full registration verified both ways

## Lineage vs. the existing NT/nitan/Lonely family (AGENTS.md §2.1/§11)

**Genuinely distinct branch, not a duplicate of any existing lib.**
Spot-checked core files (`adm/kernel/master.lpc`, `adm/daemons/
logind.lpc`, `adm/daemons/securityd.lpc`, `adm/daemons/named.lpc`,
`adm/daemons/chinesed.lpc`) against `nitan170911`, `nitan6`, `nt1`,
`nt6`, `nt6nitan6win`, `xfbhh`, and `hhsj`: every file differs
substantially (hundreds to ~900 diff lines even under whitespace-
insensitive `diff -bw`, out of files 150–1,850 lines long) — this is
NOT the "byte-identical modulo reformatting" shape that predicts a
wholesale fix-port (contrast: `nt7`'s `feature/dbase.lpc` byte content
vs. `hhsj`'s post-reformat copy WAS identical modulo indentation style,
confirming shared engine ancestry, but the higher-level daemon files
have each evolved independently since the fork). Directory layout
(`adm/`, `clone/`, `cmds/`, `d/`, `data/`, `feature/`, `inherit/`,
`kungfu/`, `quest/`, `u/`, `template/` …) and world content (`d/
dongtian/`, family/sect system, `data/business` bsave format) closely
mirror `hhsj`'s, and `securityd.lpc`'s own file header credits "Doing
Lu for ULTRA HELL" (the same "Doing"/hell lineage credit chain
documented elsewhere in AGENTS.md §11) — strong evidence of a shared
distant ancestor, not a recent fork of any single already-onboarded
lib.

**The single biggest payoff of checking lineage first: the family's
signature architecture bug (AGENTS.md §7.15, "the nitan set/query/
dbase architecture bug") is ALREADY FIXED upstream here, and does not
need porting.** §7.15 describes the NT/nitan/Lonely lineage's classic
trap: bare `set()`/`query()`/`delete()`/`addn()` simul_efun calls
resolving `this_object()` to the SIMUL_EFUN OBJECT (wrong) rather than
the caller, requiring a two-part fix (real local `set`/`query` in
`feature/dbase.lpc` + a `previous_object()`-based simul_efun fallback).
`nt7`'s `feature/dbase.lpc` has NO local `set`/`query`/`delete`
functions at all (same shape as the historically-BROKEN state on
`nitan170911`/`nitan6`/`hhsj`/`xfbhh`/`nt6`/`nt6nitan6win`/`nt1` before
this project's own fixes) — but `nt7`'s simul_efun shim
(`adm/kernel/simul_efun/ntefun.lpc`, guarded `#ifndef
__PACKAGE_DBASE__`, which is always true on this driver) correctly uses
`previous_object()` (the CALLER) rather than `this_object()` (the
simul_efun itself) to resolve the redirect target:
```lpc
varargs mixed query(string prop, object ob) {
    if (!objectp(ob)) ob = previous_object();
    return ob->query_db(prop);
}
```
This is architecturally correct and was verified live (registration,
`washto`, `score` all read/write player properties correctly). Since
every bare call anywhere in the whole tree routes through this ONE
correctly-implemented simul_efun (there being no local override
anywhere to create the split-resolution shape §7.78 describes), the
downstream §7.78 (mixin-file bare-call mis-resolution) and §7.79
(`addn`/`addn_temp` misdirection) bug classes don't apply here either —
`addn`'s shim uses the same `previous_object()` pattern. `check_legal_name`
also already uses a real Unicode `pcre_match(str, "^\\p{Han}+$")` check
(§8.1's "byte-range Chinese-detection" bug class does NOT apply — the
GBK-byte-oriented `is_chinese2()` variant still exists in the same file
but is unreachable dead code, confirmed via corpus-wide grep, left
alone). Net effect: this branch appears to have either independently
fixed, or never actually shipped, the exact bug class that was this
project's single biggest recurring finding across the rest of this
lineage — a useful confirmation that the bug is a fork-time regression
in SOME branches, not baked into the shared upstream design itself as
§7.15's own text once concluded.

## Bugs found + fixed (programming/driver-compat only, per AGENTS.md §6)

1. **§7.80-shaped bug, confirmed present, fixed**: `adm/daemons/
   eventd.lpc`'s `create()` builds its event-file list with
   `map_array(event_name, (: $1[0..<3] :))` to strip the `.lpc`
   extension — same off-by-one as the corpus-wide §7.80 sweep (`str[0..<n]`
   keeps `len-n+1` chars on this driver, so stripping a 4-char suffix
   needs `[0..<5]`, not `[0..<3]`). This lib wasn't part of that sweep
   (never onboarded before), so it still had the bug. Fixed
   `[0..<3]` → `[0..<5]`.
2. **§4.3 string-literal collision, self-inflicted by the mechanical
   `static`→`nosave` conversion, fixed**: 150 files/282 call sites had
   `log_file("static/...", ...)`-style path literals rewritten to
   `"nosave/...` by `convert_lib.sh`'s blind `\bstatic\b` sed (the
   original source, confirmed via `raw/`, has zero `"nosave/` strings
   anywhere — this is 100% conversion-tool fallout, not an upstream
   bug). Reverted every `"nosave/` → `"static/` across the whole tree.
3. **`#ifndef __SENSIBLE_MODIFIERS__` shim in `include/globals.h`,
   confirmed DEAD (not a live bug on this driver), removed for
   cleanliness anyway**: the classic AGENTS.md §4.3 "`#define protected
   static`" shim was present (`#define protected nosave`), but this
   driver's LPC preprocessor already defines `__SENSIBLE_MODIFIERS__`
   unconditionally (confirmed via the driver's own predefines dump), so
   the `#ifndef` branch was always compiled out — `protected` was
   already the real keyword, not aliased. Removed the dead shim block
   rather than leave a misleading comment; verified via a clean
   recompile (no new warnings/errors), and confirms `feature/
   command.lpc`'s `protected nomask int command_hook(...)` (§8.3a) was
   never actually broken here either — no fix needed for that one.
4. **New WASM-only bug, found + fixed, root-caused via bisection**: the
   very FIRST connection under the WASM build always failed
   `logon()` silently (driver log: `new_conn_handler: logon() on
   object clone/user/login#0 has failed, the user is disconnected.`,
   with ZERO LPC-level error/trace anywhere — `safe_apply()` just
   returns null) — reproducibly, at the exact same point, regardless of
   what was typed. Bisected with temporary `write()` markers spliced
   into `logon()`: everything up through `chinese_number(max_usr)`
   printed fine; the very next call, `TIME_D->replace_ctime(time1)`,
   never even entered the target function body. Root cause: `TIME_D`
   (`adm/daemons/timed.lpc`) is listed in `adm/etc/preload` and DOES
   compile clean during boot preload (no warnings/errors at all), but
   is NOT actually resident (`find_object(TIME_D)` returns 0) by the
   time of the very first connection — and a bare `call_other()`
   (`TIME_D->replace_ctime(...)`) to a not-yet-loaded object, which
   transparently triggers an implicit `load_object()` and works fine
   under the NATIVE driver, silently fails the whole `logon()` call
   under the WASM build instead (confirmed empirically: an EXPLICIT
   `catch(load_object(TIME_D))` immediately before the call fixes it
   completely, and every following line — including `replace_ctime()`'s
   own body — then executes normally). This looks like a genuine
   WASM-specific driver-level gap (implicit load-on-call_other not
   reliable there), not a mudlib logic bug, but per AGENTS.md §1.3's
   "mudlib-side guards are encouraged" policy, fixed at the mudlib
   level: `if (!find_object(TIME_D)) catch(load_object(TIME_D));`
   immediately before the `TIME_D->replace_ctime(time1)` call in
   `logind.lpc`'s `logon()`. Did NOT attempt to preemptively guard every
   other daemon call in this ~30k-file mega-lib against the same
   theoretical class — this was the one call site actually exercised
   and confirmed broken on the critical first-connection path; note for
   a future WASM pass on this lib (or a sibling) if another
   first-connection daemon call turns up the same symptom.
5. **Unrelated hardening applied alongside #4**: `logind.lpc`'s
   `logon()` also had an UNCONDITIONAL `DATABASE_D->db_count_user()`
   call (real MySQL `db_connect()`) feeding a purely cosmetic "N
   registered players" banner line — every other `DATABASE_D->` call in
   the same file is already correctly gated behind `#ifdef DB_SAVE`
   (disabled in this checkout's `include/unixconf.h`/`winconf.h`), so
   this one call was inconsistent with the file's own convention. Fixed
   to match: `#ifdef DB_SAVE ... #else reg_usr = 0; #endif`. Confirmed
   via bisection this was NOT the actual cause of bug #4 (removing it
   alone didn't fix the WASM hang) — kept anyway since it's a genuine,
   independent correctness/consistency fix (and doubly so under WASM,
   where `PACKAGE_DB` isn't compiled in at all, per the WASM build's
   own `CMakePresets.json`).

## Interactive verification

**Native** (`~/src/fluffos/build-debug/src/driver config.fluffos`,
`scripts/mudclient.py`): full flow scripted end-to-end multiple times —
`id` → confirm → surname/given-name (real Chinese, e.g. 秦风/秦峰/秦枫)
→ admin password → confirm → play password → confirm → gender → notice
board → lands in `/d/register/regroom` ("泥潭注册室") → `reg
<email>` completes the stub email-registration step (mail-sending is
commented out upstream; `registered` flag just gets set) → moves to
`/d/register/entry` ("生命之谷", meets 盘古/Pangu by name) → `choose
1`-`4` → `washto <str> <int> <con> <dex>` (13–30 each, ≤80 total) auto-
completes the "投胎" (reincarnation) step and moves the character
straight into `/d/city.../世界之树` in the Ancient Village (no separate
`born <city>` command needed once `washto` succeeds — confirmed the
game's own flow, not a bug: `do_washto()` calls the equivalent of
`do_born()` internally). `look`/`score` both produce correct,
fully-rendered output (character sheet shows the exact str/int/con/dex
values from `washto`, correct gender/personality/age, zero mojibake).
`quit` triggers the same "new account must stay online 30 minutes or
it's deleted" policy already documented as intentional design on
`hhsj` — confirmed by completing it with `y`: clean "账号...档案被
删除" message, save file actually removed, zero `debug.log` errors
throughout any of the runs.

**WASM** (`scripts/wasm_client.js` against `~/src/fluffos/build-wasm/src`):
same full flow, same script, same result — registration through
`choose`/`washto`/world-entry/`score`/`quit` all produce identical
correct output to the native run, after fix #4 above. Before that fix,
EVERY WASM connection attempt failed at the exact same point (silently,
right after the "已经执行了N秒" uptime banner) regardless of what was
typed — this was the actual §1.3/§1.4 WASM playability blocker for
this lib, not an IP/socket/pcre-package issue like the family's other
usual WASM traps.

## Not fixed (deliberately, out of scope)

- Cosmetic compile warnings throughout the whole tree ("Unused local
  variable", "Number of arguments to X disagrees with previous
  definition", "Non-void functions must return a value", "Expression
  has no side effects") — pre-existing lazy-compile noise common to
  virtually every lib in this corpus, not touched per this project's
  scope discipline (programming bugs with an actual error signature,
  not lint-level noise).
- `is_chinese2()` in `adm/kernel/simul_efun/chinese.lpc` still has the
  old GBK-byte-range `is_chinese()` shape (§8.1's classic bug) — but
  it's genuinely dead code (zero callers anywhere in the tree, confirmed
  via grep), so left alone per this project's "don't fix unreachable
  code" convention.
- `lpcc_check.sh`'s full-tree batch compile-sweep was started but
  KILLED partway through (RSS had reached ~15.7GB / >58% of host RAM
  on a shared multi-agent host after ~12 minutes, still climbing, no
  sign of finishing soon) — per AGENTS.md §10.4's explicit mega-lib
  guidance ("on mega-libs the boot + interactive test is the sufficient
  verification gate; the sweep is nice-to-have"), relied on the clean
  native boot (zero fatal errors, only cosmetic warnings) plus the full
  live registration/play verification above instead of the batch sweep.

## Admin account seeding (AGENTS.md §1.5)

`adm/etc/wizlist` already shipped `fluffos (boss)` (seeded upstream by
this project's own author in the pre-existing `254262ec` commit, before
this pass even started). No save file existed for it yet, so registered
it for real through the normal flow (this lib's registration requires
BOTH an admin/recovery password and a distinct regular login password —
sending the same value for both is rejected): id `fluffos`, name 浮云
(surname 浮, given name 云 — picking the same character twice for both,
e.g. "浮浮", trips a same-surname-name re-confirmation branch in
`get_name()` that isn't a bug, just needs the joined full name typed
back; used two different characters instead), admin password
`Mud@2026`, regular login password `Mud@2026wiz` (matching this
project's own established convention for this specific repo, from the
`254262ec` commit message). Since `fluffos` already resolves to
`(boss)` via `wizlist`, `enter_world()`'s own startroom logic correctly
routes it straight to `WIZARD_ROOM` (`/d/wizard/wizard_room`) instead of
through the normal player birth-ceremony rooms — confirmed correct
behavior, not a bug (wizard accounts are expected to skip `reg`/
`choose`/`washto`). Verified live: reconnect with the regular password
succeeds, `update /adm/daemons/timed` reports "成功！". `score` reports
"还没有出生呐" (not yet "born") for this account, since the normal
birth-ceremony rooms that set the `born` property are never visited by
a wizard-status login — did not chase this further (out of scope, likely
by design for a staff-only account that isn't meant to use `score`).

## Deep functional test (round two, 2026-08-27)

Full §10.7 playthrough (never previously done on this lib) against a
freshly-rebuilt `~/src/fluffos/build-debug/src/driver`, native only.
Also checked all of AGENTS.md's standing cross-cutting bug-pattern
list (§7.121, §8.3a, §7.112, §7.118, §7.122–§7.136, §7.139, §7.141–
§7.148) via systematic grep — see per-pattern notes below. No sibling
NT/nitan-lineage bug classes applied here beyond what's already
documented above (§7.15 architecture bug already fixed upstream, per
the earlier onboarding writeup).

**Housekeeping note, not an nt7 bug**: found an unrelated stray driver
process (PID bound to port 40211, cwd in a completely different lib
`sanguozhi`, reparented to init) squatting on this lib's assigned port
before boot could even start — killed by exact PID before proceeding.
Unrelated to nt7's own code; flagged here only so a future session
knows this can happen on a shared host.

### Bug found and fixed #1 — §7.80-shaped filename-slice bug, 29 more call sites in the kungfu/skill tree

`explode(__FILE__, "/")[<1][0..<3]` (and the `dirs[<1][0..<3]` variant)
appears in 27 individual `kungfu/skill/**/*.lpc` files plus the two
shared mixins `inherit/meskill/skill_model_{weapon,unarmed}.lpc` and
the shared header `kungfu/skill/force.h` — the exact same `str[0..<n]`
off-by-one this project already fixed in this very lib's `adm/daemons/
eventd.lpc` (`.lpc` is 4 characters, `[0..<3]` only strips 2, so
`"guiyuan-tunafa.lpc"` yields `"guiyuan-tunafa.l"` instead of
`"guiyuan-tunafa"`). This project's original onboarding pass only
grepped for `eventd.lpc`'s own exact line shape and never turned up
this second, much larger family of call sites in the same lib. Two
confirmed-live consequences:

- `inherit/meskill/skill_model_weapon.lpc`'s `practice_skill()` calls
  `me->query_skill(skname, 1)` with the corrupted id, so this always
  looks up a nonexistent skill and returns 0 — silently breaking skill-
  level checks for the player-invented-martial-arts feature (`cmds/
  skill/invent.lpc`, `SKILL_MODEL_WEAPON`/`SKILL_MODEL_UNARMED`
  templates).
- `kungfu/skill/force.h`'s `valid_public()` (included by 9 top-tier
  force/internal-energy skill files, e.g. `guiyuan-tunafa.lpc`) builds
  a `can_skill` self-exclusion list containing the file's OWN corrupted
  id, so the self-exclusion check never actually matches the player's
  own already-partially-learned copy of that same skill — every `learn`
  attempt past the very first one hits `"你不散掉归元吐呐法，如何能
  修习归元吐呐法。"` (an absurd "you must give up X before you can
  learn X" self-rejection), permanently capping every one of these 9
  force skills at whatever their first `learn` happened to reach.

The remaining ~20 kungfu/skill call sites compute the same corrupted
id but only pass it to `SCBORN_D->valid_learn()`/`valid_perform()` — a
prerequisite-checking daemon whose file (`adm/daemons/scbornd.lpc`)
does not exist anywhere in this archive at all (confirmed via
corpus-wide grep for `scbornd`/`SCBORN_D`). Every such call
unconditionally fails regardless of the id's correctness, so fixing the
slice has no observable behavior change at those specific call sites —
flagging this as a separate, out-of-scope missing-content gap
(inventing what a whole prerequisite daemon should do would be a
content/design decision, not a programming fix) rather than chasing it
further. Fixed the slice arithmetic at all 29 sites anyway
(`[0..<3]` → `[0..<5]`), since it's the same unambiguous mechanical bug
independent of what currently consumes the result.

One additional match, `adm/daemons/skillsd.lpc`'s real `valid_perform(
object me, string file)` (the actively-used `SKILLS_D`, as opposed to
the unreferenced dev-sandbox copy at `u/lonely/skillsd.lpc`), had
already had its own `[0..<3]` slice commented out and replaced with a
bare `dirs[<1]` (no stripping at all) by a prior author — checked this
against its real caller (`inherit/skill/skill.lpc`'s `perform_action()`,
which passes an already-extension-less path via `perform_action_file()`)
and confirmed the no-slice form is actually CORRECT for that call
site's real argument shape (the one other caller that would pass a
`.lpc`-suffixed path is fully commented out, dead code). Left untouched.

Verified live: `bai wu bo` (拜师) then `learn wu bo unarmed 1`
correctly raised a fresh character's `unarmed` skill (`skills` showed
`基本拳脚 (unarmed) - 不堪一击 6/14` after one `learn` call) — this
exercises the general skill-learning path, not the specific 9
force-skill files, since reaching those requires much deeper
progression; the force.h self-exclusion fix was verified by direct
code-level tracing (confirmed the corrected id now matches what
`member_array()` checks against) rather than a live multi-level force
skill grind, given time budget — documented here as verified-by-code-
reading rather than fully live-verified for that specific consequence.

### Bug found and fixed #2 — a missing-content-factory null check silently truncates the crontab scheduler on every single boot

100%-reproducible on every fresh boot (not a random-roll fluke):
`adm/daemons/timed.lpc`'s `init_crontab()` reads `adm/etc/crontab` (140
lines) and does `find_object(table[1]) || load_object(table[1])` on
every referenced object to verify it resolves — one of the very first
entries (line 120) references `/u/redl/cangku` (a wizard's personal
treasure room, target of 6 华山论剑/牛人三部曲 tournament-scheduling
crontab lines). Loading it for the first time runs its `create()`,
which does `EQUIPMENT_D->create_dynamic("", 60, 600)->move(this_
object())` in a loop — an unguarded §7.147-shaped chain. Worse,
`create_dynamic()` ITSELF (`adm/daemons/equipmentd.lpc:1368`) has no
null check either: `ob = TEMPLATE_D->create_object(filename, obj_type,
temp_status);` can return 0 (whenever the randomly-rolled obj_type/
level combination doesn't resolve to a real shipped template file),
and the very next statements unconditionally do `set(..., ob)` and
`ob->set_color(color)` — a bare `call_other()` on `int(0)`, which
throws uncaught: `*Bad argument 1 to EFUN call_other() Expected:
object, string, array, Got: int(0)` (`debug.log`, reproduced on every
single boot in this session, both before and after the fix was
verified absent).

Severity beyond the immediate crash: the error is only caught by an
OUTER `catch()` several frames further up the call stack (`logind.
lpc`'s pre-existing `catch(load_object(TIME_D))`, from this lib's own
bug #4 above) — which means the entire unwind aborts `init_crontab()`'s
for-loop at that exact point, silently discarding EVERY crontab entry
after line 120 (the 华山论剑 sect-tournament scheduler, the 牛人三部曲
PK-event scheduler, and anything else later in the 140-line file) on
every single boot, not merely failing to spawn one random equipment
drop in one wizard's personal room.

**Fix**: added `if (!objectp(ob)) return 0;` immediately after the
`TEMPLATE_D->create_object()` call in `equipmentd.lpc`'s
`create_dynamic()`, restoring the function's own already-documented
"returns 0 on failure" contract (mirrors the identical early-return
guard already present at the top of the same function for `ilvl < 1`).
Also fixed the caller-side chain in `cangku.lpc`: stored the return in
the already-available `ob` local and guarded the `->move()` call with
`if (objectp(ob))`. Verified live: `debug.log` goes from this error
firing deterministically on every single fresh boot (both via a first
connection reaching `logind.lpc`'s `TIME_D` lazy-load path, and via a
direct wizard `update /u/redl/cangku.lpc`/`update /adm/daemons/
equipmentd.lpc`) to zero occurrences across multiple clean reboots
post-fix. Added as a new confirmed instance of AGENTS.md §7.147, with
a new note about the extra severity when an unguarded factory chain is
reached from inside a bootstrap/scheduler loop rather than ordinary
gameplay.

### Standing cross-cutting patterns checked, confirmed clean

- **§7.121 / §7.124** (float-into-int economy math / fraction-vs-
  percentage threshold): grepped the whole tree for float-literal
  threshold assignments and `wimpy`-style fields; all ~140 `set("env/
  wimpy", N, ...)` call sites use consistent integer 0–100 percentages,
  and the one genuine `float rate` family (quest/skybook damage-scaling
  code) is correctly declared `float` throughout. Clean.
- **§8.3a** (`private`/`nomask` command-dispatch demotion): already
  confirmed clean at onboarding time (the `#ifndef __SENSIBLE_
  MODIFIERS__` shim is dead on this driver) — re-confirmed no new
  `private nomask command_hook`-shaped declarations exist.
- **§7.112** (NPC `init()` unconditional `call_out` chain with no
  reconnect guard): the one `remove_call_out()`-then-`call_out()`
  pattern found (`d/newbie/npc/qianbo.lpc`'s shopkeeper greeting) DOES
  carry the guard already, and is cosmetic (a greeting message) rather
  than the death/combat-state class this pattern targets. Clean.
- **§7.123** (bare file-scope mapping/array literal killing a compile):
  the only 4 hits for the raw pattern are either legitimate multi-
  variable `protected nosave mapping a = (...), b = (...), c = (...);`
  declarations or inside `/* ... */` comments. Clean.
- **§7.126** (stale `.c` extension in saved door/exit data): no
  `"__DIR__...\.c"`-style saved references found anywhere. Clean.
- **§7.129** (`tell_room()`/`message()` wrapper forwarding omitted
  `exclude` as literal `0`): already fixed upstream in this exact repo
  before this project even started (see bugs-found item at the top of
  this file) — `adm/kernel/simul_efun/message.lpc`'s `message()`
  correctly checks `arrayp(exclude) || objectp(exclude)` before
  forwarding to the real efun. Re-confirmed by reading the current
  source. Clean.
- **§7.130 / §7.133** (net-dead / disconnect-notification gaps):
  `net_dead()` is defined on both `clone/user/user.lpc` and `clone/
  user/login.lpc`, so the driver's real disconnect apply is handled.
  Clean.
- **§7.131** (`find_living`/`find_player` without `set_living_name`):
  `set_living_name` IS called (7 sites) — this archive uses the modern
  registration convention, not the classic implicit-scan one. Clean.
- **§7.132** (`map()`-over-mapping bound to the wrong argument): no
  `map(m, (: $1 ... :))`-shaped single-argument lambda calls over a
  mapping found anywhere. Clean.
- **§7.134 / §7.135** (uninitialized accumulator/lazy-init guard
  inconsistency): the specific `room_descs`/`add_my_desc()` identifiers
  from the documented pattern don't exist in this codebase (different
  room-description architecture); this lib's own `dbase` accessor
  layer was already verified correctly guarded at onboarding time.
  Nothing newly found.
- **§7.136** (command-soul strip with no race content to re-grant):
  N/A — this codebase's command dispatch (`feature/command.lpc`) is a
  different architecture (no `cmdsoul_list`/`NPC_SOULS` concept).
- **§7.139** (`interactive catch tell` config flag / `%^TAG%^` colour
  markers bypassing `add_message()`): this lib renders colour via
  direct ANSI escape macros (`<ansi.h>`'s `HIC`/`HIY`/`NOR`, etc.)
  embedded literally in output strings, not a `catch_tell()`-mediated
  `%^TAG%^` translation layer — confirmed live throughout this session
  (every coloured message rendered correctly with real escape codes,
  no literal `%^...%^` text ever appeared in any test transcript
  except one obscure, unreachable-in-practice quest macro in `quest/
  skybook/jimou/{fengbian,tianbian}.lpc` that builds a `%^WEATHER_
  CHANNEL%^`-tagged string with no corresponding tag-resolution table
  anywhere in the codebase — flagged as a content/quest observation,
  not fixed, since deciding what that tag should resolve to would be a
  content decision). §7.139's actual failure mode does not apply here.
- **§7.141 / §7.142** (`replace_program()` fold breaking post-boot
  communication / virtual-object engine masking a broken exit typo):
  no virtual-object engine in use in this codebase; `replace_program()`
  calls are the standard ROOM-class pattern already covered by the
  corpus-wide §7.100 sweep (N/A here, this lib wasn't part of that
  sweep's target shape and its own `replace_program(ROOM)` calls are
  the harmless single-inherit-fold idiom).
- **§7.143** (shop NPC `add_action`/`force_me` command_giver mismatch):
  live-tested at `d/newbie/zahuopu`'s `钱伯` (qianbo, `F_DEALER`
  mixin) — `list` and `buy fire` both correctly dispatched to the
  NPC's own `do_list`/`do_buy` (confirmed via the correct in-character
  "钱伯冷笑道：穷光蛋，一边呆着去！" no-money rejection message, not a
  silent no-op). Clean.
- **§7.144** (one-shot `set_name()` setup guard defeating per-instance
  rename): no generic reusable NPC base class self-naming in its own
  `setup()` found in this codebase's `NPC`/`F_MASTER` inherits.
- **§7.145** (broken pre-check wired as direct verb override instead of
  base-class hook): not found; shop verbs (`buy`/`list`) dispatch
  correctly per the §7.143 test above, with no shadowing override.
- **§7.146** (stray `/` meant as `/*`): zero hits in any `.lpc`/`.h`
  file (only in ASCII-art map/doc files, which aren't compiled).
- **§7.148** (parameter literally named `nosave`/`static`): zero hits.

### Interactive verification (this pass)

Registered a fresh Chinese-named test character (`qinfengnt`, 秦风,
admin pw `fluffos`, play pw `Mud2026play`) via a raw Python
socket bridge script, one continuous session:

- `washto 20 20 20 20` → landed at `世界之树` correctly, innate skills
  banner shown, `score`/`i` both fully rendered with correct values.
- Walked to `/d/newbie/lianwuchang` (练武场), `bai wu bo` (拜师)
  succeeded ("古村第二代弟子"), `score` afterward correctly showed
  `【门派】古村` / `【师承】武伯`.
- `learn wu bo unarmed 1` correctly raised `unarmed` skill; `skills`
  confirmed `基本拳脚 (unarmed) - 不堪一击 6/14`.
- Walked to `/d/newbie/houcun-road`, `kill ye tu` (野兔) — full combat
  round-trip with real damage numbers both ways, correct kill message,
  correct XP/potential/江湖阅历 reward banner. Safe low-level wild
  target, no dedicated "safe sparring" NPC found reachable in the
  newbie zone (`d/heizhao/npc/muren.lpc`'s stat-mirroring training
  dummy exists in the codebase but its containing zone, `d/heizhao/`,
  is unrelated/unreachable from the newbie village — a wild rabbit
  served as the safe low-risk combat test instead).
- `quit` → correctly triggered this lib's documented "new account must
  stay online 30 minutes" retention policy (already documented as
  intentional design on sibling `hhsj`); confirmed with `y`, save file
  actually removed, zero `debug.log` errors throughout.
- Reconnected as the SAME character before deletion actually confirmed
  the persistence-then-delete race wasn't an issue (character correctly
  showed `古村第二代传人`/`门派 古村`/`师承 武伯`/20-20-20-20 stats on
  a fresh reconnect prior to the final `quit y`), satisfying the
  "reconnect after a wall-clock gap, confirm state persisted" step.
- Admin account (`fluffos`/`Mud@2026wiz`, already seeded) reconnect
  verified clean: lands at `WIZARD_ROOM` as documented, `goto` teleport
  and `update` (live-recompile) wizard commands both work correctly.
- Shop test: `goto /d/newbie/zahuopu`, `list`/`buy fire` against 钱伯
  both dispatched correctly (see §7.143 note above).
- Test character's save file (`qinfengnt`) removed via the `quit y`
  flow above; no other throwaway saves created this session.

RSS stayed under 130MB throughout (well below this lineage's documented
§7.110 OOM risk threshold) — no mass-restore operation was exercised
this session, so that risk wasn't specifically stress-tested here.

## Local run

```
cd libs/nt7
~/src/fluffos/build-debug/src/driver config.fluffos
```

Port: **40211**.
