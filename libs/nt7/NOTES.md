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

## Local run

```
cd libs/nt7
~/src/fluffos/build-debug/src/driver config.fluffos
```

Port: **40211**.
