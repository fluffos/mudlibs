# AGENTS.md — handbook for restoring and polishing these mudlibs

This is the accumulated knowledge base of a ~100-archive restoration
project, rewritten as a durable reference for whoever (human or agent)
continues the work. Read the section relevant to your task before touching
a lib; almost every problem you will hit has been hit before and is
cataloged here with its fix.

**Current state (as of 2026-08-09)**: 243 libs in `libs/` (193
`playable`, 1 genuinely `limited` — `zjdyzj`, a real client-protocol
handshake WASM terminals can't compute, native play fully verified —
the rest `not-mudlib`/`password-protected`/`not-convertible`/
`deprioritized`), all fully WASM-playable end to end and through the
long-sit boot-log sweep (§10.0) — the WASM-conversion phase is done.
`dfgsitlzjwin`/`ds386`/`hellxg`/`hy2`/`sgzmudsgz` were purged as
permanently out of scope (duplicates, no standalone master object,
wrong driver requirement, deprioritized English lib — see the git
history around 2026-08-07 for the purge commit); their raw archives
are preserved in `archives/`, not `libs/`. The corpus keeps growing as
new archives get dropped in; `README.md`'s table and
`lib_numbering.json` are the current source of truth for the exact
count, not the numbers above.

**§10.7 deep functional testing: campaign complete for the current
corpus.** All 191 non-duplicate `playable` libs have had a full §10.7
pass as of this writing (grep `libs/*/NOTES.md` for a `深度功能测试
（§10.7` heading to check current status per lib — do NOT trust this
count once it's stale, recompute it: any newly-added or newly-promoted
`playable` lib without that heading is the next candidate). With no
un-dived playable lib left, the standing fallback per
`project_jhfy3_room_sweep_backlog` memory is to work off `jhfy3`'s
large in-lib §7.100 ROOM-class sweep backlog (batch cycles, ~400-600
files each, see §7.100 below for detail) until either it's exhausted
or a new/promoted lib needs its own §10.7 pass. §1 is still the triage
playbook for any lib that somehow hasn't had its WASM pass yet.

**Round-two re-test campaign in progress (started 2026-08-12), against
an upgraded driver.** `~/src/fluffos` was rebuilt from a fresh
`origin/master` pull (brings in two PRs from this project's own driver
work: #1343 diagnostics-arena, #1344 O(1) ASCII-string fast path). This
also follows a live production crash found and fixed corpus-wide: a
`%` operator handed a corrupted-float player attribute
(`quest_count = killer->query("questXX_times") % 500` and the
copy-pasted `win_times`-referee-NPC equivalent) — fixed with `to_int()`
across 175 files/255 occurrences (commit `c571a53629f`; see
`project_quest_times_percent_operator_corpus_sweep` memory for the full
writeup, including why driver-side truncation was considered and
rejected). A corpus-wide `lpcc_check.sh` compile sweep sampled 30 libs
post-upgrade and found **zero compile-level regressions**. Live §10.7
playthrough re-testing is the higher-value check and is working
through the corpus lib-by-lib (one at a time, via the recurring cron
job) — round-two passes so far use a dated heading like `深度功能测试
（2026-08-12` rather than the bare `（§10.7` marker, so grep for the
current year-month to find what's already been re-covered vs. what
still only has a round-one pass. Two lineage siblings already done
(`zhonghua2`, `ntii`) turned up real new bugs (a dead random-quest
subsystem from a stale non-`mixed` param type, a missing-`varargs`
crash, off-by-2 suffix-slice bugs) — check sibling libs in the same
lineage for the same patterns before assuming a fresh find is isolated.

Every lib has a number: `NNN` per unique game, `NNN-M` for confirmed
derivatives of the same codebase, `9xx` for non-LPC archives (one,
`033-3`, is a cataloged binary-only release that was never convertible
and has no `libs/` dir). This file refers to libs by **slug**
(`libs/<slug>/`) and number, never by "archive #N" (a retired
convention) or by any machine-local path.

Conventions used throughout:

- `~/src/fluffos` = the FluffOS checkout this project builds its drivers
  from (native `build-debug/`, `build/`, and `build-wasm/`). Adjust to
  wherever your checkout lives; the *relationship* (one source tree, three
  builds) is what matters.
- Each lib: `libs/<slug>/{config.fluffos, work/, raw/, NOTES.md, README.md}`.
  `work/` is the playable tree (UTF-8, `.lpc`); `raw/` is the pristine
  extraction (gitignored, regenerable via `scripts/extract.sh`).
- Ports: one unique port per lib, recorded in its `config.fluffos` and the
  README table. Check `lib_numbering.json` for the current highest
  assigned port before picking one for a new archive — it keeps climbing
  as new archives arrive (past 40100 as of this writing).
- Update this file whenever you learn something that saves time on the
  *next* lib. Keep entries in the catalog style: symptom → root cause →
  fix (with code) → how to detect → which lineages it affects. Do this
  proactively, as part of finishing the lib — don't wait to be asked,
  and don't batch it up for "later".
- **Run the §9 LPC formatter on every lib whose `.lpc`/`.h` files you
  edited, before considering the lib done** — not just when reminded.
  It's a required step of the workflow, same tier as boot-testing, not
  an optional polish pass. Then check all three §9 blind spots and
  re-boot/re-test after formatting, since the formatter itself can
  introduce a regression.
- **Slugs are short pinyin initials, not full transliterations.** Derive
  from the Chinese `name`, not from the archive filename: `bxsj` (书剑天下),
  `ldtx` (鹿鼎天下), `yhyxcs` (炎黄英雄史), `bmxkx2001` (北美侠客行2001).
  Keep a distinguishing suffix (year, station name, `dlx`/`std`-style
  English abbreviation, or a trailing digit) only when needed to
  disambiguate siblings — Roman numerals in the Chinese title become plain
  Arabic digits in the slug (`Ⅱ`/`II` → `2`, `Ⅲ`/`III` → `3`), never spelled
  out. If you ever do need to rename a slug: `git mv` the directory, update
  the lib's own `meta.json` `slug` field, fix the absolute `mudlib
  directory` path baked into `config.fluffos`, then grep the whole tree
  (`README.md`, this file, every other lib's `README.md`/`meta.json`) for
  the old slug and replace it — a rename that leaves stale cross-references
  is worse than not renaming at all. **Also re-run
  `python3 scripts/gen_keep_dirs.py`** (see its own docstring, and the
  `pack_lib_for_web.sh`/§1.4 note on `wasm_keep_dirs.txt`) — this manifest
  is keyed by slug, so a rename that skips it silently orphans the old
  slug's entries and ships the new slug with NONE of its needed runtime
  directory shape. Caught live on `xkyx3b` (renamed from
  `xiakeyingxiong3`): the packed site booted the driver fine but every
  single connection died silently at `logind.lpc`'s very first
  `write_file(LOG_DIR "login/users", ...)` (missing `log/login/`
  directory — the classic missing-directory-swallows-errors pattern, just
  one CI rebuild removed from the rename instead of immediate) — the
  in-browser symptom was the status line stuck forever at "connecting…"
  with zero console errors, only visible by opening the page's own Logs
  tab and reading the driver's `execution error` trace, or by diffing
  `git ls-files libs/<slug>/work/` against `find libs/<slug>/work -type d`
  for directories that exist locally but hold no tracked file.
- **`meta.json` stays lightweight structured data — number, slug, archive,
  name, wasm_status, port, duplicate_of.** It is not the place for prose.
  Anything explaining *what was found or fixed* belongs in the lib's own
  `NOTES.md`, in Chinese, alongside its historical conversion notes — not
  in a `group_note` field. If you're about to write more than one sentence
  into `meta.json`, it belongs in `NOTES.md` instead.
- **Approach this project with curiosity and empathy, not just throughput.**
  These are somebody's late nights from 1997–2015 — a wizard group's
  in-jokes in a `securityd.lpc` comment, a founder's own bootstrap account
  still hardcoded into `restore_list()`, a room description somebody was
  clearly proud of. The goal is preservation, not just a green checkmark on
  a boot test: read the actual room text, the actual NPC dialogue, the
  actual quest chain before writing a README's content section — don't
  reach for generic wuxia boilerplate when the lib in front of you has its
  own specific, discoverable identity. When two libs turn out to share
  code under different branding (or vice versa), that lineage *is* part of
  the history worth recording, not just a dedup detail.

---

## 1. WASM — the primary target

### 1.1 What WASM mode is

The FluffOS driver compiles to WebAssembly (`build-wasm/src/fluffos.js` +
`fluffos.wasm`) and runs a whole mudlib inside a browser tab or under
node: the mudlib tree is copied into an in-memory filesystem (MEMFS), the
driver boots against it, and "connections" are in-process
(`wasm_console_connect()` / `fluffos_input()` / an output callback) — no
sockets anywhere. The GitHub Pages workflow (`.github/workflows/pages.yml`
+ `scripts/build_site.sh` / `pack_lib_for_web.sh` / `gen_site_index.py`)
packs every lib this way and publishes a click-to-play site.

Build notes (once per machine):

```
# emsdk version is pinned in ~/src/fluffos/.github/actions/build-wasm/action.yml
cd ~/.local/opt/emsdk && ./emsdk install <pinned> && ./emsdk activate <pinned>
source ~/.local/opt/emsdk/emsdk_env.sh    # per shell; do NOT pipe this through
                                          # anything (a subshell drops the PATH)
cd ~/src/fluffos
tools/wasm/build-deps.sh PREFIX=/opt/wasm-deps          # ICU, once
cmake --preset native-tools && cmake --build --preset native-tools -- -j8
emcmake cmake --preset wasm  && cmake --build --preset wasm -- -j8
```

Gotcha in `build-deps.sh`: the ICU data-archive step runs host-built ICU
tools that need their own `lib/` on `LD_LIBRARY_PATH`
(`libicutu.so` load error). If `libicudata.a` is missing from the deps
prefix, re-run just that step with
`LD_LIBRARY_PATH=$WORK/icu/source/build-host/lib`. Check all three `.a`
files exist before the driver build — the failure otherwise surfaces
later as a confusing cmake/link error, not at the deps step.

### 1.2 Testing a lib under WASM

`scripts/wasm_client.js` mirrors `mudclient.py`'s interface but drives an
in-process WASM driver:

```
node scripts/wasm_client.js ~/src/fluffos/build-wasm/src libs/<slug> \
    --timeout 20 --idle 1.0 --send "" --send "look" --send "quit"
```

Second argument is the lib ROOT (contains `config.fluffos` and `work/`),
not `work/` itself. The script rewrites `mudlib directory :` to the MEMFS
path before boot. To boot-check a packed site bundle:
`node scripts/wasm_boot_check.js <site/slug> <site/_driver>`.

Two harness facts worth knowing (both already fixed in the scripts, but
they explain historical NOTES entries and are traps if you rewrite the
harness):

- `fluffos_tick()` expects a monotonic clock starting near 0
  (`performance.now()`-style). Passing `Date.now()` epoch ms makes the
  first tick replay the driver's full catch-up cap (100 gameticks) at
  once — e.g. a 30-second login-timeout `call_out` fires ~2 real seconds
  after connect. Track elapsed-ms-since-start yourself.
- The harness must recreate the **entire nested directory shape** of
  `log/` (and any other runtime-written tree) in MEMFS, not just the top
  level — an unguarded `write_file("/log/mud/FOO")` into a missing nested
  dir throws and can kill a login chain (see §7.11). Several libs'
  "blocked under WASM" verdicts turned out to be this harness gap;
  suspect the harness before the mudlib when a WASM-only failure involves
  a `log/` path.
- **A file/directory name with invalid UTF-8 bytes crashes the harness's
  `copyDir()` outright** (`ENOENT: no such file or directory, scandir
  '...'`, with garbled `�` characters in the printed path) before the
  driver even boots — Node's `fs.readdirSync`/`fs.readFileSync` require
  valid UTF-8 paths, while `git`/Python tolerate arbitrary bytes fine.
  This is a real archive-content defect (usually a GBK-as-UTF-8
  mojibake from an old CJK-locale zip/rar extraction), not a harness
  bug — the file/directory legitimately has garbage bytes in its name.
  Detect with a quick Python walk: `name.encode('utf-8')` raises
  `UnicodeEncodeError` on the offending entries (surrogateescape-decode
  first if you need to read the raw bytes: `os.listdir()` already
  returns `str` with lone surrogates for undecodable bytes on Linux).
  Fix: rename to a sanitized ASCII placeholder, preserving file
  content — these are never real LPC source (real `.lpc` files must
  already have valid, compilable identifiers/paths), typically stray
  `.txt` notes or a duplicate NPC/room file the original archiver
  double-saved with a corrupted name. Check for a redundant full-tree
  backup copy nested inside `work/` (e.g. a stray `work/version/`
  mirroring `work/adm`, `work/d`, etc.) — if the corrupted name exists
  in the real tree it's often duplicated there too, and the harness
  walks that copy as well. (`nt1`: 20 corrupted entries, 10 in the real
  tree and 10 duplicated under an unreferenced `work/version/` backup.)
- **A lib that intentionally destructs the login connection and tells
  the player to reconnect** (a distributed/staggered preload gate that
  polls readiness via a self-rescheduling `input_to()` — `"载入中，请
  稍后..."` — then kicks every waiting connection with a "启动完毕，
  重新连线中" message once done, rather than just gating `input_to()`
  until ready) looks like a hang or crash to the harness by default: a
  disconnect with unsent `--send` lines remaining ends the run early.
  This is legitimate design, not a bug — pass `--reconnect-on-
  disconnect` to have the harness open a fresh `fluffos_connect()` and
  keep going. Leave the flag off by default (most disconnects mid-
  script ARE a genuine crash/ban and should end the run, not be
  silently retried). (`nt6`'s `SYSTEM_D->valid_login()` gate — solving
  this made an EARLIER "boots clean but registration times out"
  verdict on `nt6` actually testable; the real remaining blockers
  turned out to be architectural, see §7.15.)

### 1.3 Known WASM-mode gaps, and the current policy for each

**Policy change (important)**: earlier in the project, WASM login blockers
were documented-not-patched to preserve original behavior. Now that WASM
playability outranks preserving original behavior, **mudlib-side guards
are encouraged** for everything in this section, including the
`query_ip_number()` bug itself — though as of this writing that bug is
already FIXED at the driver level (see below), so a future agent
building from a current `fluffos` checkout should not need to work
around it at all; the class is documented here for historical context
and in case anyone is running an older driver build.

#### (a) `query_ip_number()` returned garbage — driver bug, FIXED upstream (merged)

On earlier WASM builds, `query_ip_number()` on an in-process connection
did not return a real dotted-quad (observed returning `"("`), despite
the driver setting `INADDR_LOOPBACK` internally. Any login path that
parsed/validated the IP could break. Three recurring shapes, all one
root cause:

- `sscanf(ip, "%d.%d.%*d.%*d", ...)`-style site/ban daemons reject every
  login (e.g. `bxsj`'s `sited.lpc`, many `band.lpc`/`BAN_D` variants) —
  usually a clean "not welcome" rejection message.
- `explode(query_ip_number(ob), ".")[1]`-style indexing throws an
  **uncaught `Array index out of bounds`** and silently desyncs the whole
  prompt chain before the id prompt (e.g. `mhxyqd`/`mhxy`'s
  `ipd.lpc`, `zitengzhan`'s `band.lpc`).
- Cosmetic-only uses (displaying the IP in a banner) — harmless, ignore.

**Both driver-side fixes below are MERGED upstream in `fluffos/fluffos`
(verifiable via `git log origin/master` in the fluffos checkout — look
for the `query_ip_number()`/`resolve()` WASM commits) and both the
native and WASM drivers used by this project have been rebuilt from
that merged master.** This is the now-active contract:

1. `query_ip_number()` on a WASM connection returns a real
   `"127.0.0.1"` dotted-quad (and `query_ip_name()` something sane like
   `"localhost"`) — confirmed live in multiple libs' retest transcripts,
   which show real `127.0.0.1` banners/messages post-fix.
2. `resolve()` under WASM no longer raises "DNS resolver is not
   available" — it mirrors the native contract exactly but with
   synthetic success: the callback is scheduled on the next tick, any
   hostname resolves to `"127.0.0.1"`, reverse lookups to
   `"localhost"`.

**Implication, now in effect: do NOT patch mudlibs around IP-format or
`resolve()` crashes under WASM as if the driver bug were still present
— that class is closed.** If you see a "limited" WASM status in
`scripts/wasm_status.json` whose reason cites `query_ip_number`, `IP`,
`band.lpc`, `BAN_D`, `sited`, or `ipd`, rebuild the WASM driver and
RE-TEST that lib — it will very likely now pass. Any mudlib-side
patches made for these two classes back when the driver bug was live
are legacy and can be simplified away over time (they're harmless to
leave, since they're now dead code paths — a genuine `resolve()` call
under WASM just succeeds instead of throwing into the `catch()`). The
mudlib-side policies that DO remain regardless of driver state: the
loopback-allow-through-ban-gates patch (b) — **fail-closed, see below**
— the uptime-gate/throttle bypass (e), and the `fluffos`/`Mud@2026`
admin seeding (§1.5).

#### (b) The loopback-allow patch (standard, per user direction) — FAIL-CLOSED

Every lib gets a small patch making connections from `127.0.0.1` bypass
ban lists, site-restriction gates, and per-IP registration throttles.
Shape — short-circuit at the TOP of the gating function(s), before any
parsing of the IP:

```lpc
// in BAN_D/band.lpc's is_banned(), sited.lpc's site check,
// logind.lpc's inline gate, etc.
int is_banned(object ob)
{
    string ip = query_ip_number(ob);
    // local/WASM connections are always allowed.
    if (ip == "127.0.0.1" || ip == "::1" || strsrch(ip, "127.") == 0)
        return 0;
    ... original logic unchanged ...
}
```

**Do NOT treat a malformed/empty/non-string IP as loopback.** An
earlier version of this pattern also matched `!stringp(ip)` and any IP
that failed `sscanf(ip, "%*d.%*d.%*d.%*d") != 4`, on the reasoning that
older WASM driver builds returned garbage for `query_ip_number()`. That
was fail-open: a spoofed or garbled IP from a REAL remote connection
would silently bypass every ban/throttle, not just genuine loopback
ones. The driver bug that motivated it is now fixed (§1.3a's
`query_ip_number()`/`resolve()` fixes are merged upstream, both drivers
rebuilt) — WASM connections report a clean `"127.0.0.1"` same as
native — so the fallback has no remaining justification. An unparseable
IP must fall through to the ORIGINAL gate logic, not bypass it. (This
was caught and fixed after several libs had already shipped the
fail-open version; if you find `!stringp(ip) ||` or an
`sscanf(...) != 4` disjunct feeding an "is local" check in any lib,
that's this bug — tighten it.)

Rules: patch the *entry points* the login flow actually calls (read
`logind.lpc`'s chain — ban check, site check, multi-login check,
registration throttle), keep the original logic intact below the
short-circuit, and record the patch in the lib's NOTES.md. This also
neutralizes most of (a) for practical purposes, but keep the two concerns
separate in your head: (a) is a driver bug being fixed properly; (b) is a
deliberate local-play convenience.

#### (c) No `sockets` package — dns/intermud/version daemons can't load

WASM builds ship without `sockets`/`db`/`ffi`/`pcre`/`crypto`/`async`/
`compress`. The big one is `sockets`: `dns_master`, `versiond`,
ident/port-113 lookups, and anything calling `resolve()`/
`socket_create()` throws `Undefined function` at load. Usually non-fatal
(caught by the lib's own error handler, daemon just absent), but several
recurring shapes DO break login and now get mudlib-side guards on sight:

- **Unconditional `DNS_MASTER->query_muds()` / mirror-site checks** in
  `logind.lpc` — crash or `shutdown(1)` when the daemon is absent. Guard:
  `if (find_object(DNS_MASTER)) ...` and treat "absent" as "skip the
  gate". (Seen: `shiji`, `xyj2000f`, `xiyouji450`,
  `syxjl` — note the check can hide inside the *absent* branch
  of an earlier `find_object()` test, as on `xyj2000f`.)
- **`VERSION_D->is_version_ok()`-style gates** (the 中华英雄/终极地狱
  lineage idiom) — same fix: `find_object()` guard, absent ⇒ allow.
  (Seen: `zhonghua2`, `zhongjidiyu`, `zjdyzj`,
  `yanhuangwuhun`, `yhyxs`.)
- **`MESSAGE_D->find_chatter()` called unconditionally from
  `logind.lpc`'s `check_ok()`** (every successful password check, both
  new and returning logins) — `MESSAGE_D` is a chat/UDP daemon with raw
  `socket_create()`/`socket_bind()` in its own `create()`, so it fails to
  compile under WASM entirely; the unguarded call throws `*No program in
  object`, which aborts `check_ok()` mid-way and disconnects the user
  before `make_body()`/`enter_world()` ever run — the connection just
  silently drops with no further prompt. Fix: `if (find_object(MESSAGE_D))
  { user = MESSAGE_D->find_chatter(...); ... }`, absent ⇒ skip (no one
  to kick off a chat session with). (Seen: `yanhuangwuhun`, `yhyxs`,
  `hell`.)
- **`resolve()` called in a security daemon's `create()`** before it
  initializes its own state — under WASM the throw aborts `create()`
  mid-way, leaving globals (e.g. `wiz_status`) uninitialized, and the
  *first ACL lookup* crashes later with no obvious link to the cause.
  Fix: reorder state init before the `resolve()` call AND wrap it in
  `catch()`. (Seen: `fy3dz`, `moniHuafu`, `fengyun434`/
  `fy2005` proactively — the 风云 family's `securityd.lpc` idiom.)
  NOTE: the `resolve()` driver fix (§1.3a) is now merged, which makes
  the `catch()` unnecessary going forward — but the reordering is
  correct defensive style anyway, and the state-init-before-network-call
  lesson generalizes.
- **ident/auth lookups on connect** (`userid.lpc` doing
  `socket_create()`/`socket_connect()` to port 113) — wrap in `catch()`
  or gate on a `find_object()`/feature check; the lookup is cosmetic.
  (Seen: `huoying`.)

Also absent: zlib (compressed saves silently degrade; `.gz` not
auto-decompressed) and non-algorithmic charsets (GBK/Big5
`string_encode()` raises — irrelevant post-conversion, everything is
UTF-8).

#### (d) No `pcre` — can be a hard boot blocker

`zsdsj` (055) is the one known no-boot: its
`system_d`/simul_efun ANSI-code handling uses pcre efuns, so simul_efun
itself fails to compile and nothing boots. Options, in preference order:
rewrite the ANSI stripping/parsing in plain LPC string ops
(`replace_string()`/manual scan — the ANSI grammar used is simple);
`#ifdef`-gate the pcre path with an LPC fallback; last resort, stub the
ANSI processing to passthrough (loses color, boots). This class can exist
in any lib that regex-processes color codes — grep `pcre\|regexp(` when a
WASM boot dies inside simul_efun.

#### (e) Legacy connection-time gates: uptime grace periods and per-IP throttles — bypass them (standing policy)

Two classes of circa-2000 hosting protection make no sense for a per-tab
WASM instance or local play, and per user direction should be
**bypassed on sight**, not merely documented:

- **`uptime()` startup-grace gates** — refuse/destruct connections during
  the first N seconds/minutes of a boot (`if (uptime() < 30)
  destruct(ob)`, up to 5 minutes on `fy2005`). Natively you rarely
  notice; the WASM harness connects instantly after boot, so the gate
  fires deterministically every run. Known affected:
  `xyxy2`, `xiaoyuxiyou`, `bixiecanyang`,
  `xyzxfy2`, `fy2005` (5 min), `nitan_ceshi`,
  `nitan_san`, `xajhzcjh` (uptime()<10), `tianxia`,
  `jhfy3` (uptime()<30, fired deterministically every WASM run since the
  harness connects instantly after boot — no amount of real-wall-clock
  waiting via filler `--send` traffic satisfies it, because the WASM
  event backend is host-tick-driven, not wall-clock-driven).
- **Per-IP anti-flood / registration throttles** — "one new registration
  per N minutes per IP" mappings (`xo_final`'s `BAN_D` 3-minute
  throttle, `xajh2`'s per-IP throttle) whose rejection path is
  often a *silent* disconnect (§8.6).

**Patch pattern**: remove or short-circuit the `uptime()` check (or gate
it to non-loopback connections only), and exempt loopback from
anti-flood throttles — the same loopback test as (b):

```lpc
// startup-grace gate: only ever applies to remote connections now
if (query_ip_number(ob) != "127.0.0.1" && uptime() < 30) { ... original ... }
// anti-flood throttle: loopback exempt
if (ip == "127.0.0.1") return 1;   // IsTimeAllowed()-style check
```

**KEEP in-game content timers** — quit-retention windows ("new accounts
deleted if you quit within 30 min", `xiyouji2003`), save gates ("need 10
points before quit saves", `xajh2`), skill/combat cooldowns —
those are game design, not hosting protection. Record every bypassed
gate in the lib's NOTES.md.

- **Wizard-only-loopback login/registration gates** — a `sited.lpc`-style
  `is_valid(id, ip)` that special-cases `127.0.0.1`/`localhost` to
  require `wiz_level(id)` (protecting the server's own local console
  from casual access) can end up blocking the literal registration
  keyword itself (e.g. `"new"`), since a not-yet-chosen id is never a
  wizard — every WASM/local-telnet registration attempt dies at the very
  first prompt with a generic "can't login from this address" message,
  before the id has even been typed. Bypass narrowly: add the keyword
  (`id == "new"`) as an explicit exception alongside whatever hardcoded
  bootstrap-id exception the lib already has (e.g. `sjshv150`'s own
  `id == "allenc"`), not a blanket loopback bypass — real remote
  deployments never hit the loopback branch at all, so this is exactly
  the same class of test-only friction as the two gates above.
  (`sjshv150`.)

### 1.4 WASM triage playbook (per lib)

Status lives in `libs/<slug>/meta.json`'s `wasm_status` field — the single
per-lib source of truth (also read for the main README table). Prose
explaining what was found/fixed goes in the lib's own `NOTES.md` (Chinese),
not in `meta.json` — see the "Conventions" list at the top of this file.
`scripts/gen_site_index.py` (the Pages site generator) derives the
deployed site's status badges directly from every lib's `meta.json` on
each run (via `scripts/assemble_numbering.py`, which it always re-invokes
first) — editing a lib's `meta.json` and re-running the site generator is
the entire update path; there is no separate cache file to hand-sync.
(`scripts/wasm_status.json` is still written as a build artifact/inspectable
snapshot, but nothing reads it back to derive status.) For every lib not
yet `playable`:

1. Reproduce: `wasm_client.js` with the lib's documented login sequence
   (read its README for the flow — id, hidden prompts, Chinese name).
   Read the FULL transcript plus captured driver output.
2. Classify against §1.3: IP-parse rejection/crash (a) → wait for the
   driver fix, or apply the loopback patch (b); sockets-absent daemon
   crash (c) → guard; pcre (d) → rewrite; instant silent disconnect at
   connect-time (e) → uptime gate; `log/`-path ENOENT → harness dir shape
   (§1.2); anything else → treat as a real mudlib bug, native rules apply
   (§6–§8) — first check whether it reproduces natively, since a
   WASM-only genuine mudlib bug is rare.
3. Fix, re-run the FULL flow (registration with a real Chinese name →
   `look` → `score` → `quit`, same standard as native, §10.1).
4. Update the lib's own `meta.json` (`wasm_status`), write up what was
   found/fixed in `NOTES.md` (Chinese), and update the main README table.
5. Known one-off oddities to not rediscover: `xo` reaches the gender
   prompt then hangs at world-entry under WASM only (not IP-related, not
   reproducible on sibling `xo_final` — unexplained, flagged);
   `xajhxo`'s character-creation finalization is flaky under
   the harness (timing-shaped, fine natively).

### 1.5 Admin account seeding (standard convention)

Every lib gets a pre-seeded admin account — **id `fluffos`, password
`Mud@2026`** — so users (and future test passes) get wizard powers
without per-lineage archaeology. Procedure per lib:

1. Register `fluffos` through the NORMAL registration flow (real driver,
   real prompts — this exercises the flow one more time, which is
   valuable in itself). If the lib's id rules reject `fluffos` (length
   caps, reserved words), pick the closest allowed variant and document
   it in the lib's README under 「管理员账号 / Admin account」.
2. Grant admin via the lineage's own mechanism — typically one of:
   an `adm/etc/wizlist`-style data file; `securityd.lpc`'s
   status/ACL save data (set the account's status to the top rank the
   ACL tables use, e.g. `(admin)`); a `master.lpc`/`WIZ_D` mapping. Read
   how the lib's own `wizardp()`/`get_status()` decides, then seed that
   store. Prefer editing the *data* (save file / etc file) over code.
3. Verify: log in as `fluffos`, run a wizard command (`update <path>` is
   the canonical check since it exercises the ACL for both read and
   compile), confirm no permission denial.
4. Commit the seeded data + document in the lib's README (id/password if
   nonstandard, and the granting mechanism used, so it can be re-seeded
   if save data is ever reset).

The password is a deliberate published default for local play; the
top-level README carries the change-it-if-hosting warning.

**Bug class: rank granted but write ACL empty by design.** Some
lineages (seen in the Century/`adm/single`-style `master.lpc` family,
e.g. `sanjieshenhua`) separate "is this account a wizard" (what
`wizlist`/`(admin)` status controls) from "what may this account
actually write/compile" (a SEPARATE `default_trusted_write`/
`extend_trusted_write` table in `securityd.lpc`'s own save data, often
shipped EMPTY except for a commented-out example, with the lineage's
own escape hatch — e.g. an `auth` command — hardcoded to a couple of
the original author's uids instead). Symptom: `fluffos` logs in and
shows `(admin)` correctly, but `update`/any write-requiring wizard
command fails ACL as if not a wizard at all. Fix: don't just seed the
rank — also seed (or create, if the save file doesn't exist yet) the
trusted-write entry granting `fluffos` root write, the same way you'd
seed the rank itself. Always verify step 3 (`update <path>` actually
succeeds) rather than trusting a `(admin)` banner as proof of working
admin access — the two are enforced by genuinely different code paths
in libs with this shape.

**Bug class: the hardcoded bootstrap admin id is already occupied by a
pre-existing archived player.** Some `securd.lpc`/`securityd.lpc`
lineages hardcode a single bootstrap admin id directly in
`restore_list()`/`create()` (e.g. `set("wiz_status/hxsd",
"(admin)");`, with a comment acknowledging the intent: "leave a door
open, but make sure the admin claims this id first"). If the archived
save data already has a real player registered under that exact id
(from the original site's actual history), the id's password is
unknown and `fluffos` can't claim it — attempting to register it hits
`密码错误！` instead of the normal new-character flow. Don't try to
guess the password or delete the pre-existing player's save data. Add
a parallel `set("wiz_status/fluffos", "(admin)");` line right next to
the original (with a one-line comment explaining why), register
`fluffos` normally, and verify the usual way. Document the deviation
in the lib's README so a future re-seed knows both ids are meaningful.
(`hy2002`, sibling of `hy2000`'s `wuyou` bootstrap id — that one WAS
still unclaimed.)

**Bug class: `wiz_status` (or equivalent) declared `nosave`.** A few
lineages declare the wizard-status mapping `private nosave mapping
wiz_status = ([]);` — it is NEVER written to a save file, always starts
empty on every boot, and is populated only via a hardcoded default in
`create()` (sometimes alongside a hardcoded backdoor like `if (euid ==
"lonely" || euid == "ken") return "(admin)";`). There is no data file
to edit here — check the variable's declaration for `nosave` before
reaching for a save-file edit; if present, add the seed as a plain
assignment in `create()` instead (e.g. `wiz_status["fluffos"] =
"(admin)";`, placed after any `restore()` call so it isn't overwritten).
(`nt1`'s `adm/daemons/securityd.lpc`.)

---

## 2. The per-lib pipeline (bring-up from a raw archive)

All 103 archives are done — this section remains the reference for
re-converting a lib from scratch, onboarding a newly-found archive, or
understanding how the trees in `libs/` were produced.

1. **Extract**: `scripts/extract.sh archives/<file> libs/<slug>/raw/`
   (§3 for the archive-format traps).
2. **Identify the mudlib root.** Archives nest inconsistently: top-level,
   one level down (`mud/`, the game's name), bundled alongside a prebuilt
   Windows driver or clients. Find the original config file (grep for
   `master file` / `mudlib directory`) or locate `adm/obj/master.c` /
   `secure/master.c`. Ignore bundled driver source/binaries — we use our
   own driver.
3. **Convert**: `scripts/convert_lib.sh` copies root → `work/` and does,
   in this order: GB18030→UTF-8 transcode (encoding FIRST, before any
   other edit — see §4.1), `.c`→`.lpc` rename, literal-`.c`-reference
   fixups. Then run the §4 post-conversion checks (stragglers, uppercase
   `.C`, etc.).
4. **Write `libs/<slug>/config.fluffos`** from the lib's original config
   (§5). Assign the next free port.
5. **Apply the proactive checklist** (§2.2) — most catalog bugs are
   cheaper to fix on sight than to diagnose from a broken boot.
6. **Compile-sweep**: `scripts/lpcc_check.sh <config> <work-dir>` after
   master/simul_efun themselves compile (fix that chain first with the
   real driver — `lpcc` needs a working master; a synthetic stand-in
   master does NOT work). Triage failures per §10.4 before "fixing" them.
7. **Boot and play**: `cd libs/<slug> && ~/src/fluffos/build-debug/src/driver
   config.fluffos` (must cd — §5.2), then `mudclient.py` through the FULL
   registration flow. §10.1 defines the verification bar.
8. **Record**: findings → `libs/<slug>/NOTES.md`; player-facing intro →
   `README.md`; anything reusable → this file; status → README table /
   `wasm_status.json`. Then the WASM pass (§1.4).

**Definition of done** (current standard, learned the hard way):
- boots with zero fatal errors and a clean-enough `log/debug.log`;
- a NEW character registers with a **real Chinese name** (e.g. 秦风) all
  the way INTO the game world — not just "reaches a prompt" (§8.1);
- at least `look`, `score`, and `quit` each produce correct output
  post-login (§8.4 — reaching the world ≠ being able to play in it, and
  `score` exercises the player-body class in ways `look` does not);
- WASM status determined and recorded (§1.4);
- deeper content bugs (individual rooms/skills erroring) are logged in
  NOTES.md, not necessarily fixed.

### 2.1 Recognize the lineage first — fixes port across siblings

Before deep-diving a lib, spot-check its core files against
already-processed libs: `md5sum`/`diff` on `master.c`, `chinese.c`,
`chinesed.c`, `logind.c`, `named.c`, `securityd.c`. A match means you
port the sibling's proven fix list wholesale and boot clean on the first
attempt (worked repeatedly: `bxsj1` from `bxsj`, `nitan6` from
`nitan170911`, `sjtx2` from `shujian2008`,
`mhxyqd` from `mhxy`, the whole `jqxz2008`
group, `fy2qh` from `fy2`). §11 maps the known families.

Two hard-won caveats:
- **Similar Chinese titles are NOT a lineage signal, in either
  direction.** Same-titled libs proved unrelated (`sjpl2` vs
  `shujian2008`; `zhongjidiyu` vs the other two 终极地狱;
  `kxkj1` vs `kxkj` are same game but
  different snapshots; `xianlvqiyuan` vs `xlqy_new2007` different
  codebases) and different-titled libs proved identical
  (`xiakexing3` = `jqxz2008`; `jinyongwenzi` = `bxsj`).
  Always verify by diff.
- **Ported fixes still need per-lib verification** — a sibling can have
  independently drifted (the "identical" file you didn't diff), and an
  automated multi-file fix needs checking per-instance, not just on the
  samples that motivated it (a regex-shaped bug class can have
  genuinely-correct instances mixed in).

### 2.2 The proactive on-sight checklist

Run these before the first boot attempt on any newly-converted lib; each
points at its catalog entry:

```
# master.lpc / security daemon reads (§7.1, §7.2, §6.1, §7.4):
grep -n "load_object\|get_root_uid\|get_bb_uid\|get_include_path\|valid_override" adm/obj/master.lpc  # (or the lib's master path)
grep -n "destruct" <master> | grep -i "simul_efun\|SIMUL_EFUN_OB"   # §7.3
grep -n "this_player()" <securityd>                                  # §7.4
# preload hygiene (§7.6, §1.3c):
grep -n "dns_master\|dns_d\|intermud" adm/etc/preload
# chinese-detection (§8.1): read the lib's chinese.lpc/chinesed.lpc/named.lpc
grep -rn "is_chinese\|check_legal_name\|PATH(" adm/ secure/ | head
# command dispatch (§8.3):
grep -rn "private.*command_hook\|nomask.*command_hook" .
grep -rn 'sscanf.*\.c[$"]' adm/daemons/                              # §8.3b
# hardcoded ports/self-destructs (§5.3, §7.13):
grep -rn "MUD_PORT\|PORTNO" include/ *.h 2>/dev/null
grep -rn "shutdown\|rm(\|unlink" <securityd> | grep -vi valid        # §7.13
# grammar/efun gaps (§6):
grep -rn "\bstatic\b" --include='*.lpc' --include='*.h' . | head     # §4.3
grep -rn "ed_start\|ed_cmd\|query_ed_mode" .                         # §6.2
grep -rn "switch\s*([^)]*)\s*{\s*default:" .                         # §6.3
grep -rn "efun::set(\|efun::query(\|efun::delete(" .                 # §7.15
```

Plus the WASM-era standards: loopback-allow patch (§1.3b), legacy-gate
bypass (§1.3e), admin seeding (§1.5).

---

## 3. Archive extraction traps

`unzip`, `unrar`, `7z`, `tar` all work; `unrar x -y` handles Chinese
filenames fine in a UTF-8 locale. `scripts/extract.sh` wraps them,
resolves the archive path to absolute before any `cd`, and fails loudly
if `raw/` ends up empty. Known traps:

- **Self-extracting `.exe`** (RAR SFX): `unrar x` / `7z x` open them
  directly (`jinyongwenzi`'s `金庸文字版.exe`).
- **`7z` "success" with all-zero-byte output**: on some RAR variants `7z`
  exits 0 while every member internally failed (`Unsupported Method`),
  leaving a tree of 0-byte placeholders. Spot-check extracted file sizes;
  if suspiciously uniform zeros, retry with `unrar` — it handled the same
  archive correctly.
- **A `.rar` that is actually a tar with `../` member paths**: `file`
  says POSIX tar, `unrar` refuses ("not RAR archive"), and GNU `tar -xf`
  hard-refuses members containing `..` (before `--transform` applies).
  Extract with Python `tarfile`, stripping each member's leading `../`
  (seen: `xiakexing3`'s archive — which also has a trailing space in its
  filename; always `ls archives/ | grep` for the exact name).
- **Bare `.gz` of a tar** (`xixingzhanji`'s `西行战记.gz` → `xxzj.tar`).
- **Mudlib nested inside a second archive** inside the first
  (`xyj2000f`: mudlib in `world.tar.gz` inside the tarball).
- **"Binary version" archives**: mostly compiled MudOS bytecode (`.b`,
  `MUDB` magic) with no bootable source — not convertible
  (`longyunmeng_binary`, 033-3). Check for a "源码版"/source-version
  sibling archive before giving up.
- **Non-LPC engines dressed like mudlibs**: a `d/<city>/`, `npc/`,
  `std/` directory shape is NOT evidence of LPC. The decisive check is
  `grep -rIl inherit` — zero hits across thousands of files means a
  C/C++ engine (the whole 重出江湖 family, 三国歪传, atlantis,
  mofaleidemuba). Don't create `libs/<slug>/` dirs for confirmed
  non-mudlibs; record the finding in the numbering JSON/README instead.

---

## 4. Encoding and conversion

### 4.1 Encoding rules

- Default: `iconv -f GB18030 -t UTF-8` (superset of GBK/GB2312). Fall
  back to `-f BIG5` when GB18030 errors (`zsdsj` is fully
  BIG5/CP950). Some files are already UTF-8 (mixed-era edits) — detect
  with a UTF-8 round-trip before converting.
- **The "fall back to BIG5 when GB18030 errors" rule doesn't actually
  fire for a WHOLE archive that's pure BIG5** — GB18030 is such a broad
  superset that it essentially never hard-errors on real BIG5 bytes; it
  just silently produces valid-looking-but-wrong UTF-8 (mojibake landing
  in odd Unicode ranges, notably Bopomofo phonetic symbols U+3105–312F,
  since GBK/BIG5 double-byte sequences decode differently). `convert_lib.sh`
  logs zero errors and zero lossy conversions in this case — it looks
  like a clean run. Caught on `dfgsiiv13b` (a Taiwan ES2-lineage archive)
  only because the login banner and a compile warning
  (`Unknown escape sequence`) both showed obvious garbage after boot —
  a lib that never gets far enough to print user-facing text could sail
  through undetected. Detect proactively: pick 2-3 raw source files,
  trial-decode with `python3 -c "open(f,'rb').read().decode('X')"` across
  `big5`/`gbk`/`gb18030`/`cp950`, and eyeball which one produces
  grammatical Chinese (both GBK and BIG5 decode without raising on most
  real text, so "didn't error" proves nothing — only reading the result
  does). Fix: re-run the WHOLE `convert_lib.sh` pass with BIG5 substituted
  for GB18030 (`sed 's/GB18030/BIG5/g'` on a throwaway copy of the
  script) rather than patching individual files — check git history for
  any native-pass fixes already committed to the mis-decoded `work/`
  first, since regenerating it from `raw/` wipes them and they need
  reapplying afterward.
- **Convert EVERY text file, not just source**: extensionless banners
  (`adm/etc/welcome`, `motd`), help text, and plain-text `.o` save data
  are all GBK. Never iconv real binaries (`.exe`, compiled `.o`, images).
- **Encoding conversion is always step 1**, before any sed/rename/edit.
  Editing GBK bytes with UTF-8-assuming tools plants U+FFFD; a later
  GBK→UTF-8 pass turns that into the classic irrecoverable "锟斤拷"
  double-corruption. This applies to `config.fluffos` too (it starts as a
  copy of the GBK original).
- **`file(1)`'s text/binary guess is not reliable** — GBK source with
  `\r\r\n` line endings gets classified `data` and silently skipped.
  `convert_lib.sh` forces known text extensions
  (`.c .lpc .h .txt .log .cfg .conf .map`) regardless of `file`'s
  opinion. After conversion, sweep for stragglers:

  ```
  find work \( -name "*.lpc" -o -name "*.h" \) -print0 |
    while IFS= read -r -d '' f; do
      file -b "$f" | grep -qE "text|script|empty" || echo "$f"; done
  ```

  Any hit is raw GBK masquerading as source. A full Python
  UTF-8-decode scan across the tree is the stronger check (it caught 15
  files on `mohuanshiji` that both `file` and the extension list missed
  because their extension was uppercase `.C`). **Run the tree-wide scan
  against the WHOLE `work/` directory, not just `.lpc`/`.h`** — found on
  `yhyxs`'s §10.7 deep functional test, months after this lib's own
  original conversion pass and WASM-enablement pass had both already
  been marked done: `help/rules` (a first-login rules text, triggered
  automatically or via `help rules`) and `clone/game/{8,21}_hlp` (the
  拱猪/21点 card-minigame help text) were still raw GB18030 bytes —
  extensionless filenames, exactly the class the first bullet above
  warns about, invisible to any `.lpc`/`.h`-scoped sweep and never
  caught by the original `convert_lib.sh` pass. Symptom in play: a
  wall of `U+FFFD`-replacement-character mojibake (or, over a raw
  telnet client instead of this project's UTF-8-decoding
  `mudclient.py`, literal garbled GBK bytes) exactly where the real
  text should be — easy to misread as a terminal/rendering quirk
  rather than a real conversion gap. A plain `python3 -c
  "open(f,'rb').read().decode('utf-8')"` walk of the entire `work/`
  tree (skip `raw/`, and expect a few genuine binaries/runtime
  artifacts to fail too — filter those by content inspection, not by
  assuming every hit is text) finds these in seconds; fix with the
  same `iconv -f GB18030 -t UTF-8` as any other straggler, then verify
  the decoded output reads as grammatical Chinese before installing it.
  **Confirmed on `yhyxs`'s own sibling `yanhuangwuhun` too** (yh2003
  lineage) — same three files, byte-for-byte identical content to
  `yhyxs`'s (confirmed via `diff` after converting both), meaning this
  wasn't a one-off gap but content shared — and un-transcoded — across
  both sibling archives. When one sibling in an already-established
  lineage (§11) turns out to have this gap, check every other sibling
  for the same specific files before assuming it's isolated.
  **A third instance, found via `yhwhpublicfi`'s §10.7 deep functional
  test**: the exact same three files (`help/rules`,
  `clone/game/8_hlp`, `clone/game/21_hlp`), still raw GB18030, months
  after this lib's own separate WASM-enablement pass had already been
  marked done — `yhwhpublicfi` is a different, independently-forked
  yh2003-lineage branch (§11: "modified by Linux@lxtx for yh 2003.3"
  per its own `master.lpc` header) from `yhyxs`/`yanhuangwuhun`, not a
  copy of either, so this is genuinely a third independent carrier of
  the same un-transcoded content rather than a repeat finding on an
  already-known pair. `help/rules` is reached automatically on every
  character's very first `born` (character-creation finalization), not
  just via the `help rules` command — the mojibake is unavoidable for
  every new player, not an easter egg only curious players trip over.
  **A third, structurally different instance on `syxjl`** (unrelated
  ES2 branch, not a `yh2003` sibling) — this time not a help/doc text
  but `adm/etc/banned_name`, a 137-entry registration name-blacklist
  (period-appropriate politically-sensitive terms, government titles,
  etc. — genuine early-2000s Chinese-MUD content-moderation config).
  Made harder to notice than the help-text instances: `logind.lpc`'s
  `check_legal_name()` has a self-seeding fallback (`if
  (file_size(CONFIG_DIR + "banned_name") >= 0) { load it } else {
  write out a hardcoded 6-entry default }`) — since the real file was
  never converted, EVERY boot of this lib silently wrote a plausible-
  looking-but-drastically-weaker 6-entry `banned_name` file into
  `work/`, masking the fact that the real 137-entry list had never
  existed there at all. A missing extensionless config file with a
  self-seeding fallback can look, superficially, like "this file just
  doesn't need to exist" — the tree-wide UTF-8 scan doesn't care
  either way (a freshly-seeded ASCII/UTF-8 file decodes fine and won't
  show up as a decode failure), so this one was only caught by
  independently noticing `git status` showing a brand-new untracked
  file after a play session and checking whether the raw archive had
  a same-path original. **When a play session produces an unexpected
  new untracked file in `adm/etc/` or similar config directories,
  check the raw archive for a same-path file before assuming it's
  inconsequential runtime state** — it may be a silently-reconstructed
  weaker stand-in for content the conversion pass dropped.
  **A fourth confirmed instance on `kxkj1`** (independent ES2-family
  branch, unrelated to the `yh2003`/`syxjl` cases above) — five files
  across the tree: `doc/help/main_map2`, `doc/help/quest`,
  `doc/skill/taoist.chun`, `open/island/room/board`, and
  `open/main/README`, found via a whole-tree Python UTF-8-decode scan
  during a §10.7 pass. Notable here: `file(1)` actively misdirected
  triage on three of the five, reporting "COM executable for DOS" (a
  false-positive collision between certain GBK double-byte sequences
  and the DOS-executable magic-byte heuristic) rather than the more
  common "data"/binary-silent-skip failure mode documented above —
  worth knowing `file(1)` can misfire in this specific direction too,
  not just fail open. All five confirmed genuine grammatical Chinese
  via direct GB18030 decode before converting.
- **`iconv -c` can eat an adjacent REAL byte** along with an invalid one
  — most damagingly a newline or closing quote, producing "End of file
  in text block" / missing-quote errors at compile time (a heredoc's
  closing `LONG` tag merged onto the previous line). Any compile error
  of that shape in a file flagged "LOSSY conversion" in the conversion
  log ⇒ diff against the raw bytes and re-insert the exact dropped
  character. Seen on `tianxia`, `xo_final`, `shujian2008`,
  `xianlvqiyuan`, `ylfyxa3` (where it silently deleted
  NPC `set_name()` lines), and `qhxajh` (same xo/TMI-2/ES2/Falcon
  engine family as `xo_final` — same conversion-tooling corruption hit
  a sibling archive independently). `qhxajh` surfaced a second shape of
  the same root cause worth watching for beyond the heredoc-tag case:
  a `//` line comment immediately followed (no newline) by the next
  line's real code swallows that code INTO the comment — found live via
  §10.7 deep functional testing, not a boot-time compile error, in two
  different ways. `clone/misc/void.lpc` (a room a player can actually
  walk into) threw the expected "End of file in text block" the moment
  a wizard tried to `update` it (the heredoc-tag sub-case, same as
  above). `system/skill/basic/kongshou.lpc` — the base UNARMED combat
  skill, exercised by nearly every fight in the game — had
  `// 这个函数用来区别...int is_native_skill()\n{` (the comment
  swallowing the very next line's function signature, leaving a bare
  `{` with no declaration): this one compiles-on-boot fine (unarmed
  skill objects are lazily compiled on first use, not preloaded) and
  only surfaced once combat was actually exercised — every single
  combat round threw a repeating `*No program in object
  '/system/skill/basic/kongshou'!` runtime error until fixed, easy to
  miss if a testing pass never gets to combat. **Because this sub-case
  produces no compile-time error and can just as easily swallow a
  function that's never LATER referenced (silently deleting it with
  zero symptom, same failure mode already seen in `ylfyxa3`'s vanished
  `set_name()` calls)**, don't assume a lib flagged "LOSSY conversion"
  is clean just because it boots and compiles clean — a live §10.7 pass
  that actually exercises combat/movement/interaction is what catches
  this shape, not a boot-log read. Fix is identical either way: diff
  against the raw archive bytes at the exact offset and re-insert the
  single dropped newline.
- **Mixed encodings within ONE file**: BIG5 lines inside an otherwise-GBK
  file decode via GB18030 *without error* into valid-but-wrong mojibake —
  undetectable by the lossy-conversion log. Only a human skim of
  user-facing strings catches it (`huoying`'s `config.cfg`; also found
  live during a §10.7 deep functional test on `shzs` — 9
  `指令格式：` command-help headers mixing this lib's BIG5-heritage ES2
  base text with GBK text a later Chinese-reskin author appended without
  re-encoding; a broader automated scan of the same lib found the
  corruption is likely more widespread than any single pass caught,
  since the scanner has a real false-negative gap when BIG5-as-GBK lands
  on other valid-looking CJK — flag for a dedicated cleanup pass rather
  than assuming one spot-check found everything). Re-decode just the
  affected lines with BIG5.
- **Whole help/motd/broadcast files skipped entirely by an earlier
  conversion pass**: `shzs`'s `doc/help/{topics,cmds,story}`,
  `adm/etc/motd`, and `adm/etc/nature/day_phase` (a preloaded daemon that
  broadcasts this text to every outdoor player on every day/night
  transition, for as long as the driver is up) were still raw GBK,
  undetected until a §10.7 deep functional test actually ran `help` and
  waited through a phase transition. A conversion pass's file-extension
  sweep can still miss extensionless or non-`.lpc` text files if they
  weren't in whatever glob the sweep used — re-run the "convert EVERY
  text file" check above specifically against `doc/` and `adm/etc/` on
  any lib being deep-tested, not just the source tree.
- **Stray DOS Ctrl-Z bytes** (`0x1a`, old MS-DOS EOF markers) lurk in
  Windows-era files; strip them (seen with the uppercase-`.C` cluster on
  `mohuanshiji`).
- **Sandbox/tooling trap**: GNU `grep` silently treats GBK-encoded raw
  files as binary and reports nothing (or just "binary file matches") —
  when grepping `raw/` trees (still GBK), use `/bin/grep -a` (or
  `grep -a`) so matches in unconverted files aren't invisibly dropped.
  A "no matches in raw/" conclusion made without `-a` is unreliable.
- **`.o` save files can be un-transcoded GBK too, and hand-fixing one
  needs a QUOTE-AWARE scan, not a blind `iconv`/CRLF collapse.** Found
  on `fy2`/`fy2qh` (byte-identical siblings): `data/board/fysquare_b.o`
  (a message board every new player walks past on their first
  exploration), `data/board/poem_b.o`, and `data/emoted.o` (the entire
  emote-command pattern database) were all raw, un-transcoded GBK —
  `restore_object(): Invalid utf8 string`, thrown uncaught from each
  owning daemon/board's `create()` (see §7.7's third `fy2`/`fy2qh`
  instance and §7.87's third instance for the downstream crashes this
  caused). A first, naive fix attempt (`iconv -f GB18030 -t UTF-8`, then
  blindly collapsing every `\r\n` → `\r`) silently produced NEW
  corruption: this driver's `save_svalue()` writes an embedded real
  `\n` inside a saved string as a bare `\r` byte (not `\r\n`, not an
  escaped `\n` — see `src/vm/internal/base/object.cc`'s
  `save_svalue()`/`restore_string()`), and `restore_object_from_buff()`
  splits the WHOLE file strictly on literal `\n` bytes with no
  bracket-balance continuation logic — so a GENUINE `\r\n` pair
  anywhere in the body (these `.o` files carry real Windows-style CRLF
  line endings predating this project, most plausibly from the original
  Windows-hosted server or a Windows-based archival step) desyncs the
  whole file's variable-boundary parsing. Blindly collapsing every
  `\r\n` → `\r` merges genuine top-level statement boundaries (it
  merged `emoted.o`'s `dbase (...)` and `emote (...)` variables into one
  unparseable statement, silently producing an EMPTY-but-`mapp()`-true
  `emote` mapping rather than an error). **Correct fix**: walk the
  decoded text tracking whether the cursor is inside an (unescaped) `"`
  string literal, and only collapse `\r\n` → `\r` when INSIDE one —
  every `\r\n` OUTSIDE a string literal is a genuine top-level statement
  separator and must stay a real `\n`. Re-deriving both board saves from
  the pristine `git show HEAD:...`/raw-archive bytes with this
  quote-aware scanner restored their real archived content (including a
  garbled multi-`\r` control-sequence-spam post an earlier, cruder
  attempt had manually "cleaned" into one line) instead of losing it.
  General lesson: when a `.o` save file throws `restore_object():
  Invalid utf8 string`/`Illegal file format`/`Illegal mapping format`
  and the archive is Windows-era, check for GBK un-transcoding AND
  genuine embedded CRLF before assuming either alone explains the
  corruption — fixing one without the other can silently trade one
  parse failure for a different, quieter one.

### 4.2 The `.c` → `.lpc` rename and its long tail of fallout

FluffOS resolves an explicit extension exactly (`load_object("/foo.c")`
never finds `foo.lpc`); extensionless paths resolve `.lpc` then `.c`,
never a literal zero-extension file. Old mudlibs hardcode `.c`
everywhere. `convert_lib.sh` renames and fixes quoted references, but
each of these shapes has bitten at least once:

1. **Quoted refs in `.h` macros** — `#define F_DBASE "/feature/dbase.c"`
   surfaces at runtime as `Inherited file '...' does not exist!`. Scope
   ref-fix greps to `--include="*.lpc" --include="*.h"` together.
2. **Bare paths in plain-text data files** — `adm/etc/preload` listing
   `/adm/daemons/securityd.c` one per line; `load_object()` fails
   silently inside the preload loop's `catch()`, so (often) the security
   daemon just never loads, and every write is denied with no error.
   Check every `adm/etc/`-style data file for bare `/path.c` lines. Can
   hit at real scale, not just a handful of preload lines: `fy2005`'s
   `adm/etc/scenery_phase` (17 rows) and `quest/dynamic_location` (1440
   rows, a room pool `taskd.lpc` samples for quest-item placement) had
   EVERY row stale — the whole scenery-event feature was silently dead
   and `spread_quest()`'s "drop on the ground" path had been
   unreachable for the entire archive's lifetime, degrading to "always
   hand it to an NPC instead". One of the two consumers additionally
   crashed the caught-vs-uncaught way this class of bug can split: the
   scenery daemon's own preload self-check is `catch()`-wrapped and
   just logs a warning, but its actual "make the event happen" function
   (`scenery_happen()`) does an unguarded `load_object()` result straight
   into `room->init_scenery()` with no `catch()`/`objectp()` at all —
   crashes for real the first time a `random()` roll actually picks a
   dead entry. Verify a whole data file's worth of paths at once with a
   quick script (confirm the `.lpc` exists for each, strip `.c`), don't
   assume a couple of samples generalize.
3. **Runtime `sscanf` extension filters** — `sscanf(f+"$", "%s.c$", f)`
   in a command-indexing daemon matches nothing forever after the
   rename; the command table stays empty and every typed command
   silently does nothing (see §8.3b — can co-occur with the `private`
   command-hook bug and independently cause the same symptom). Grep
   daemons for `sscanf` with a literal `.c`.
4. **Fixed-width slices instead of extension ops** —
   `map_array(get_dir(DIR+"*.lpc"), (: $1[0..<3] :))` stripped 2-char
   `.c` correctly, now leaves `"foo.l"`. Grep `\[0\.\.<[0-9]\]` near
   `get_dir()` and widen by 2.
5. **Extensionless live file + same-named `.c` backup**
   (`zitengzhan`, 35 pairs): the original driver loaded the literal
   extensionless file; this driver's `.lpc`-then-`.c` resolution makes
   the renamed BACKUP authoritative — silently promoting stale content
   (two real bugs shipped that way). Direction isn't consistent even
   within one archive: diff every same-dir same-basename pair and pick
   the correct content.
6. **A DIRECTORY named `something.c`** confuses the rename (renames the
   dir, orphans children, harmless `mv` warnings). Rename such dirs to a
   non-`.lpc`-lookalike (e.g. `foo.orphaned-dir`).
7. **Uppercase `.C` files are missed** by both the rename glob AND the
   forced-text-extension conversion check (both case-sensitive), so they
   stay raw GBK with the old extension (363 on `shenmo`, 183 on
   `zitengzhan`, 15 on `mohuanshiji`). `find work/ -name '*.C'` on every
   lib. After renaming, also check macros whose hardcoded lowercase path
   no longer case-matches the file on disk (`CHANNEL_D` →
   `/adm/daemons/channeld` vs `CHANNELD.lpc` on `mohuanshiji`).
8. **Orphaned non-LPC `.c` files** (ASCII-art maps etc.) become
   permanently-failing `.lpc` files. If nothing references them, rename
   to `.txt` so sweep results stay meaningful.

A lib with intractably many `.c` references may keep non-critical files
as `.c` (the driver runs mixed trees fine) so long as the master/login
path is `.lpc` — note it in NOTES.md.

### 4.3 `static` → `nosave`, and its two known collisions

This driver still accepts `static` on **variables** but hard-errors on
**functions** (`syntax error ... expecting L_ASSIGN or ';'` at the
return type). Fix: blanket word-boundary `\bstatic\b` → `nosave` across
`.lpc` + `.h` (legal for variables too; functions then emit only a soft
"Illegal to declare nosave function" warning — see §7.10 for why that
warning matters). Two collision classes to check after every run:

- **String literals**: `log_file("static/CRASHES", ...)`-style path
  names get rewritten, orphaning real on-disk seed data. Grep `"static`
  (quote immediately before the word) and revert those hits. Seen on
  `moniHuafu` (10 files) and then repeatedly across the ES II family
  (up to 105 hits/60 files on `yanhuangwuhun`).
- **Compatibility shims**: `#ifndef __SENSIBLE_MODIFIERS__` /
  `#define nosave static` / `#define protected static` — the sed turns
  the *values* into `nosave`, silently aliasing `protected` → `nosave`.
  Grep `#define\s\+\(nosave\|protected\)\s` in `.h` files and neutralize
  the shim entirely (both keywords are real on this driver). Seen on
  `yxcs`, `ylfyxa3`, `zitengzhan`,
  `xajhzcjh`.

---

## 5. Config files

### 5.1 Format

Old MudOS configs (`config.cfg`, etc.) use the same `key : value` format
FluffOS still reads (`~/src/fluffos/testsuite/etc/config.test` is the
modern canonical example). Adaptation checklist for
`libs/<slug>/config.fluffos`: convert its encoding FIRST (§4.1); point
`mudlib directory` at `libs/<slug>/work`; assign the lib's unique port;
prune keys the driver rejects / add ones it requires (boot stderr tells
you); never trust the shipped config's absolute paths (they're the
original server's, e.g. `mudlib directory : /tx`) or even its `name:`
field (stale copy-paste from other muds is common — `dtsl2`
ships a 碧血残阳 name field and even a `config.bxcy` filename;
`tiexuejianghu` ships 风云三; `xkxz2` ships 海洋II).

### 5.2 `log directory` resolves against the driver's CWD

Unlike nearly every other path (mudlib-relative), `log directory` is
relative to the launch CWD. Convention: `libs/<slug>/log/` and ALWAYS
launch via `cd libs/<slug> && .../driver config.fluffos` — otherwise you
silently get no `debug.log` at all.

### 5.3 Ports hardcoded in mudlib source

A `MUD_PORT`/`PORTNO` constant in `globals.h` used by `master.lpc`'s
`connect(port)` dispatch silently rejects EVERY connection when it
doesn't match the assigned port — clean boot log, dead server
(`huoying`, hardcoded 8000; `dfgsiiv13b`, hardcoded 4000, an ES2-lineage
default — driver log shows `Can not accept connection ... due to error
in connect()`). Grep for hardcoded port constants during the standard
pass. Related but distinct: a hardcoded `TOMUD_PORT`-style
constant that only sets a cosmetic flag is harmless (`bixiecanyang`) —
read what the constant actually gates before "fixing" it.

---

## 6. Compile-time bug classes (driver-compat)

Grammar/preprocessor/efun-set differences between this driver and the
MudOS-era targets these libs were written for. Each entry: symptom, root
cause, fix, detection, known-affected lineages.

### 6.1 `#include` resolution

- **`<local.h>` next to the including file** (angle brackets search the
  include path ONLY, never the local dir): `Cannot #include ground.h`
  across hundreds of per-room flavor headers. One-shot fix — implement
  `master::get_include_path()` prepending the compiling file's own dir:

  ```lpc
  string *get_include_path(string file)
  {
      string *parts = explode(file, "/");
      if (sizeof(parts) <= 1) return ({ "/", ":DEFAULT:" });
      return ({ "/" + implode(parts[0..<2], "/"), ":DEFAULT:" });
  }
  ```

  Extend an existing implementation rather than overwrite it. (ES II
  family everywhere; first found on `xyxy2`.)
  **Timing caveat**: `get_include_path()` is NOT consulted for
  preload-time compiles (no VM context yet) — a `<local.h>` include in
  anything reachable via preload still fails; change those specific
  includes to `"quotes"`. (`es1_win`.)
  **Second caveat**: with NO `get_include_path()` at all, compiles
  triggered live mid-connection resolve NO include path (not even the
  config default) — `Cannot #include globals.h` only for lazy compiles
  during login, while preload/lpcc are clean. Add the apply.
  (`shujian2008`; §7.5 is the sibling runtime shape.)
- **Absolute paths in angle brackets** — `#include <ABS/PATH/x.h>` never
  resolves (the `<>` resolver doesn't special-case absolute names). Can
  silently break only lazily-loaded objects, e.g. sending every new
  character into the void room instead of the start room. Convert to
  quoted form. (359 files on `kxkj`, 172 on
  `kxkj1`, recurs across ES II. Also found live on
  `wuhanzhan` via its §10.7 deep functional test — a single surviving
  instance that an earlier grep-based sweep missed because the grep
  pattern was case-sensitive and only matched uppercase absolute paths
  (`<ABS/...>`); this one was lowercase (`<d/qujing/...>`). When
  re-sweeping for this class, grep case-insensitively. Also found as a
  single-file instance on `jyqxc2013fwq` (`combatd.lpc`'s
  `#include </quest/quest.h>`, the only angle-bracket absolute include
  in an otherwise all-quoted codebase) — compiled fine once quoted, but
  then hit this section's `inherit`-after-globals bullet below, since
  the newly-resolved header's top-level `mapping` landed above the
  file's `inherit` statement; fixed by moving the #include below the
  inherit line. Worth checking for both bugs stacked whenever a single
  angle-bracket absolute include is the only thing wrong with a file.)
  **Alternative fix when quoting individual `#include` lines is
  impractical (many scattered occurrences, or the exact same shape
  keeps recurring across new content)**: found on `xyxy2`'s
  §10.7 pass. `get_include_path()` (this section's own opening fix)
  CANNOT resolve an already-absolute header name — the driver always
  builds `search_dir + "/" + header_name` for a `<...>` include, so no
  list of search directories helps once `header_name` itself starts with
  `/`. The driver offers a separate, purpose-built hook:
  `master::include_file(compiled, from, path)` may return a STRING that
  DIFFERS from the original `path` to force the include through the same
  `merge()`-based resolution a `"quoted"` include gets — and `merge()`
  explicitly treats a leading `/` as mudlib-root-absolute. Returning the
  unchanged `path` is a no-op; prepend one extra `/` instead
  (`"/" + path`) — `merge()` collapses any run of leading slashes to one
  absolute-root marker, so the double-slash is harmless and the returned
  string differs from the input, which is what actually flips the driver
  into the working resolution path. Add this apply once in `master.lpc`
  and every future absolute-inside-`<>` include on that lib resolves
  without touching individual files. Second confirmed application:
  `kxkjii2` (ES II/Annihilator lineage, unrelated to
  `xyxy2`) had 358 files with this exact shape — the
  `include_file()` apply fixed all of them in one master.lpc edit, no
  individual file touched. General signal for reaching for this fix
  over hand-quoting: grep count in the low hundreds or more.
- **`..` in include paths is disallowed entirely** (security rule).
  Point at the real absolute quoted path. (Same libs.)
- **Case-sensitivity**: `#include <Action.h>` vs on-disk `action.h` —
  Windows-authored libs compile clean there, hard-fail here, and ONE
  wrong-case include can dominate a sweep's failure count (fixing 3
  files took `xo` from 209 failures to 72). `find . -iname` before
  assuming missing content. Data files hit the same trap at runtime —
  §7.8.
- **`inherit` textually after global variables / an already-included
  header's globals** — "Illegal to inherit after defining global
  variables" is fatal here. Reorder (fix the shared header once when the
  failures cluster). Sed-based bulk reorders are error-prone — diff a
  sample first (one bad regex deleted the `inherit` lines outright).

### 6.2 Things that were never real efuns on this driver

`error: Unknown efun: X` (compile) or runtime "Undefined function":

- **`tail(file)`** — reimplement in LPC (`read_file` + `explode` +
  slice). Fatal when it sits inside simul_efun. (`chidi` fatal,
  `shzs` benign.)
- **`efun::set/query/delete/addn(...)`** — nitan-family property system;
  see §7.15, the biggest architectural item in this catalog.
- **`LONELY_IMPROVED`-gated `efun::` families** (nitan branch):
  `sort_string`, `file_crypt`, ... — check for the pure-LPC `#else`
  fallback branch sitting right next to the dead one and flip the guard
  before reimplementing anything. The one sub-case with no fallback —
  `count_*` arbitrary-precision bignum wrappers (~230-1000 call sites) —
  blocks simul_efun compile; restore as 64-bit int arithmetic routed
  through the lib's own `atoi()` (NOT a bare `(int)` cast — that's a
  type assertion here, not a parse, and crashes on numeric strings), or
  write a small LPC bignum lib if the economy genuinely needs it.
  (`nitan_ceshi`, `nitan_san`, `longyunmeng`.)
- **`ed_start`/`ed_cmd`/`query_ed_mode`** — this driver build uses
  `__OLD_ED__`, so only the old `ed()` efun exists. An editor feature
  inherited into the player body class fails the whole body compile —
  silently killing `make_body()` mid-registration with zero visible
  error (compiles fine standalone; only the full inheritance chain
  fails). Rewrite call sites against `ed()`.
  Grep `ed_start\|ed_cmd\|query_ed_mode` early. (`xajh2`.)
- **Never-defined simul_efun globals** called from everywhere:
  `remove_ansi`, `noansi_strlen`, `B2G` (passthrough is correct
  post-UTF-8), `db_affected` (stub 1), `clr_ansi`, `chinese_number`
  (port the nitan `chinesed.lpc` algorithm), `changed_match_path`
  (passthrough to `match_path()`), `query_bandwide` (stub
  `({0.0,0.0})` — called unguarded on every connection on `tianxia`),
  `query_shadowed` — restore as `shadow(previous_object(), 0)`, NOT
  `this_object()` (which is the simul_efun object itself during a bare
  simul_efun call — §7.15's footgun; the wrong version silently blocked
  the player body class from compiling on `tianxia`). These surface at
  RUNTIME only, one at a time, as game logic reaches them — keep
  watching debug.log during play-testing.

### 6.3 Grammar strictness

- **`static` on functions** — §4.3.
- **Bare `array x;`** (no element type) compiles without error but
  doesn't actually declare anything; later use fails `Undefined
  variable`/`Illegal lvalue`. Fix occurrences as they surface (`array` →
  `mixed *`); don't bulk-fix 50k-file libs. (nitan family ~30-40/lib;
  470 occurrences on `zsdsj` where bulk-fix WAS warranted.)
- **`TYPE * a, b;`** — the `*` binds to the first declarator only
  (C-style); old code intends both as arrays. Symptom: `Bad assignment
  ( TYPE vs TYPE * )` in scattered files. Script-fix the narrow
  declaration-line shape. (`ds386`, 33 files; an English-lib habit.)
- **`switch` with only `default:`** — hard parse error ("need case
  statements"), fatal when it's `master.lpc`'s `connect()`. Rewrite as a
  plain block. Grep `switch\s*([^)]*)\s*{\s*default:`.
  (`xixingzhanji`, `syxjl`.)
- **`MACRO.0` float-promotion trick** — old-MudOS idiom
  `AVERAGING_NUM.0` (textually gluing `.0` onto a macro to make a float
  literal) is a hard syntax error here. Rewrite as
  `(AVERAGING_NUM * 1.0)`. Found in `usage_d.lpc` on `es1_win`/`esI`
  (on `esI` it failed a preload compile every single boot). Grep
  `[A-Z_]\.0[^0-9]` if a syntax error points at a macro followed by `.0`.
- **Multi-char character literals** — `case '''` (an invalid quote-quote
  literal) breaks the whole file; on `nitan6`/`nitan170911` it sat in
  `feature/alias.lpc`, breaking the entire player-body class and
  silently failing every character creation at gender-confirmation. Fix
  to `case '\''`. Similar: a `'25'` multi-char literal (`zitengzhan`).
- **`TYPE array NAME`** (two words — a type keyword directly followed by
  the literal word `array`, e.g. `string array arrCmd = explode(cmd,
  ";")`) is a SECOND, distinct old-MudOS array-declaration dialect this
  driver doesn't accept — not to be confused with the *bare* `array x;`
  (no element type) bug above. Fix by dropping the `array` keyword and
  using the real array-type syntax (`string *arrCmd`). (`xajh2`'s
  `clone/user/immortal.lpc`, the wizard-only `;`-separated multi-command
  batching feature.)

### 6.4 One shared root cause, not N bugs

When the SAME error string appears in dozens/hundreds of sweep failures,
check for one shared `inherit`/`#include` target before investigating
any individual file: a single bad declaration in a common base fixed 299
failures at once (`ds386`); a MISSING macro (`#define WQA_ROOM ...`
absent from `globals.h`) fixed 81 (`xyzx3`); missing
`GROUP_TASK`/`EXERT_DIR`/armor macros fixed cascades on
`xajhxo`/`tiexuejianghu`. Extract the exact underlying error
line from a few failing blocks — byte-identical ⇒ one shared dependency.

### 6.5 Function-binding order within a file

- **Calling a same-file function before its definition** can fail to
  resolve (`Undefined function`) for a newly-added helper — just define
  before use.
- **A wrapper named after a real efun** (`message()`, `write()`,
  `tell_room()`) called before its own definition appears silently binds
  to the REAL efun — no error, wrapper bypassed (crashed 9 preload
  daemons on `yanhuangwuhun`). Fix: `varargs` forward declaration at the
  top of the file. When fixing any same-named-as-efun wrapper, grep
  every call site in the file and confirm the definition (or forward
  decl) precedes all of them.
- **Overriding an inherited function**: a forward *declaration* is NOT
  enough — an early call silently binds to the INHERITED version. The
  override's real body must physically precede every same-file call
  site. (`xlqy_early`; also the shape behind two formatter-corruption
  boot failures, §9.)

### 6.6 Pre-existing typo classes (authors', not conversion's)

All confirmed present in the raw GBK bytes; fix by hand, only where the
compiler/sweep flags them:

- Fullwidth punctuation as syntax: `set("short"， ...)` (U+FF0C comma),
  `#include <ansi。h>`. Never blanket-replace fullwidth chars — they're
  correct inside Chinese strings.
- Missing closing quote before concatenation:
  `"$N把身上的 + ob->query("name") + ...` — the "Illegal character"
  cascade lands mid-Chinese-text; add the quote.
- Copy-paste inherits of nonexistent std types (`inherit AXE;` where
  only blade/dagger/sword exist): match the inherit to what the file's
  own content says it is, using an existing sibling as template — never
  implement the missing base class.
- Left-margin `//` comment glued to real code on the same physical line
  (`// 中文注释int is_native_skill()`), swallowing a declaration —
  "unexpected `{`" pointing one line BELOW the real defect. Split the
  comment. Also seen swallowing an `inherit` and half an if/else chain.
- `convertd.lpc`'s Greek-table stray backslash (`"α\",` for `"α",`) —
  recurs across the whole 西游记/ES II family, ~43-45 occurrences per
  lib, often fatal (inside simul_efun's compile). CRLF endings make the
  naive sed silently no-op (`$` anchors before `\n`, not `\r`) — always
  re-grep after the sed; use `s/\\"(,)?\r?$/"\1\r/` on CRLF files.
- Whole-file self-duplication and truncation (missing closing braces) —
  close truncated files with an empty body; don't fabricate content.
  When a truncation is found in one member of a derivative group, check
  every sibling's copy too (the `zhengmen.lpc` truncation existed in
  three 金庸群侠传 builds).

---

## 7. Boot-time and runtime crash classes

### 7.1 Master's lazy security-daemon load recurses to stack overflow

`master.lpc`'s `valid_read`/`valid_write` doing
`if (!find_object(SECURITY_D)) load_object(SECURITY_D);` — this driver
forbids `load_object()` mid-compile; the error thrown from inside a
master apply re-enters `valid_read` via the error-reporting path →
unbounded recursion → real segfault. Fix with a re-entrancy flag +
`catch()`, degrading to allow:

```lpc
private nosave int loading_security_d;
int valid_read(string file, mixed user, string func) {
    if (!find_object(SECURITY_D)) {
        if (loading_security_d) return 1;
        loading_security_d = 1;
        catch(load_object(SECURITY_D));
        loading_security_d = 0;
        if (!find_object(SECURITY_D)) return 1;
    }
    return (int)SECURITY_D->valid_read(file, user, func);
}
```

Grep `load_object` inside master before first boot. (Widespread; first
on `shzs`; also `dfgsiiv13b`, whose variant used
`catch(load_object(SECURITY_D))` directly in `valid_read`/`valid_write`
with no guard at all — same fix applies regardless of the exact
`load_object`/`find_object` shape.)

A subtler symptom of the exact same bug: no crash at all, just
`securityd`'s own `wiz_status` mapping ending up permanently empty (every
id, including ones already listed in the wizlist file, resolves to
`(player)`). This happens when the missing guard only manifests as
`load_object(SECURITY_D)` failing with "Object cannot be loaded during
compilation" — caught, degrading to a default `return` — rather than a
segfault: `securityd.lpc`'s own `create()` calling `read_file(WIZLIST)`
triggers `valid_read`, which (lacking the flag) calls
`load_object(SECURITY_D)` again while `securityd.lpc` is still mid
compile; every nested read the compiler needs (its own source, its
`#include`s, its inherited files) recurses the same way, none of them
ever completing successfully, so `securityd` never finishes loading and
`wiz_status` is never populated. A `previous_object() == find_object(
SECURITY_D)`-style check does NOT fix this variant — during those nested
compile-triggered reads `previous_object()` reports as master itself
(whoever called `load_object()`), never securityd, no matter how the
comparison is phrased. Only the reentrancy flag above breaks it. (`qhxajh`
— confirmed via a debug trace showing `read_file(WIZLIST)` returning `0`
inside `securityd`'s own `create()`, with zero visible compile error.)

### 7.2 Missing `get_root_uid()`/`get_bb_uid()` applies

With `PACKAGE_UIDS` on, `set_master()` requires both (the apply name is
`get_bb_uid`, not `get_backbone_uid`) or the driver `exit(-1)`s. Add
minimal stubs returning the lib's existing uid constants.

### 7.3 `create()` destructing SIMUL_EFUN_OB segfaults the process

An old-MudOS force-reload trick in master's `create()`
(`efun::destruct(find_object(SIMUL_EFUN_OB))`) segfaults the whole
driver during bootstrap — raw C++ stack dump, nothing catchable. The
reload serves no purpose here; delete it. Check every master's
`create()` for `destruct` targeting SIMUL_EFUN_OB/MASTER_OB — invisible
to lpcc, only crashes a real boot. (`dfgs2`.)

### 7.4 `this_player()` overriding the ACL caller identity

```lpc
// securityd.lpc valid_read — BEFORE (denies privileged system loads
// whenever any player happens to be mid-login):
if (this_player()) user = this_player();
// AFTER:
if (this_player() && !geteuid(user) && !getuid(user))
    user = this_player();
```

A privileged lazy `load_object()` that happens to run during a player's
`input_to` chain gets attributed to that (unprivileged) player and
denied — permanently stranding every new connection at the first
never-preloaded daemon it touches. (`bxsj` lineage; grep the shape in
every custom securityd.)

### 7.5 Custom ACLs must allowlist compile-time access

The driver routes its OWN compile/include file access through
`valid_read` with `func` = `"load_object"`/`"recompile_object"`/
`"include"`; a real per-directory ACL denying `(player)` reads of
`/adm`/`/cmds` then crashes the FIRST lazy compile of each
never-preloaded object touched during login ("Read access denied", one
new dependency each time you fix the last). Add to the ACL's
`switch(func)`:

```lpc
case "load_object": case "recompile_object": case "include":
    return 1;   // compiling code is never a sensitive data read
```

(`shujian2008` and every genuinely-custom securityd since; far more
robust than growing the preload list.)

**Variant found on `hy2002`'s deep functional test (§10.7): `file_size`,
not just `load_object`.** Same custom-ACL root cause, but a different
and much sneakier symptom — no crash, no visible error at all, just a
silently *wrong answer*. `feature/skill.lpc`'s `set_skill()` probes
`file_size(SKILL_D(skill) + ".lpc")` to check whether a skill file
genuinely exists before accepting it:

```lpc
if (!find_object(SKILL_D(skill))
    && file_size(SKILL_D(skill) + ".lpc") < 0)
    error("F_SKILL: No such skill (" + skill + ")\n");
```

The very first time any NPC's `create()` references a skill nobody has
touched yet this boot (e.g. the very first player to enter the
starting-town martial-arts hall, referencing `"dodge"`), `find_object()`
correctly returns 0 (not loaded yet) — but the fallback `file_size()`
call gets denied by the same custom ACL (attributed to the low-privilege
object still mid-`create()`, no euid yet), returns `-1` as if the file
didn't exist, and the game incorrectly `error()`s claiming the skill
doesn't exist — aborting that NPC's entire `create()` partway through.
Once *any* object has successfully `load_object()`'d the skill file
(e.g. a wizard manually `update`-recompiling it), `find_object()` finds
the resident blueprint and the buggy `file_size()` branch is never
reached again for the rest of that boot — so this reproduces exactly
once per skill file per boot, which makes it easy to mistake for a
one-off fluke rather than a systemic ACL bug hitting a large fraction of
never-yet-touched game content on every fresh boot. Fix: add
`case "file_size":` to the same allowlisted-func `switch` as
`load_object`/`recompile_object`/`include` — checking whether a file
exists on disk is exactly as harmless as compiling it.

**Second confirmed instance: `hy2000`** (same "hy"/海洋 lineage as
`hy2002`, byte-identical `feature/skill.lpc`/`securd.lpc` shape) — the
exact same `F_SKILL: No such skill (strike)`/`(unarmed)` errors on the
very first population of the starting-town map (`d/city/npc/{man,
qian}.lpc`'s `create()`). Root-caused via temporary instrumentation
(a `write_file()` call added right before the `error()`, which itself
silently produced NO output — a useful confirming clue on its own,
since a "harmless" logging write getting silently dropped inside the
exact same call stack that's about to hit an ACL-driven false negative
is consistent with the write itself also being denied by the same
euid-not-set-yet condition). Fixed with the identical allowlist
addition to `securd.lpc`'s `valid_read()`. Two independent instances in
the same family in one project session — treat this as a standing
checklist item for any new "hy"-lineage lib: grep `debug.log` for
`F_SKILL` after the first real map traversal, not just after
registration.

**Third confirmed instance, and the most severe yet: `hy` itself (the
predecessor/ancestor lib of the `hy2000`/`hy2002` pair, confirmed via
its own §10.7 deep functional test — NOT byte-identical to either
sibling, its own independently-shaped `securd.lpc`) — a `func` value
neither prior instance covered (`"stat"`) that breaks the ENTIRE
command table for EVERY player, not just one NPC's `create()`.** The
driver's `get_dir()` efun (used by `adm/daemons/commandd.lpc`'s
`rehash()` to list each command directory's `.lpc` files and build the
verb-lookup cache) internally calls `check_valid_path(path,
current_object, "stat", 0)` — **`func == "stat"`, not `"file_size"` or
any compile-related string** (confirmed by reading
`fluffos/src/packages/core/file.cc`'s `get_dir()`). `commandd.lpc`
itself never calls `seteuid()` anywhere, so at the moment `rehash()`
first calls `get_dir()` for `/cmds/std/` etc., `commandd.lpc`'s own
euid is unset (falsy) and the custom ACL's `if (!euid) return 0;` path
denies it — `get_dir()` gets silently treated as "empty directory"
(FluffOS returns `0`/an empty result on denial, no error, no
exception), so `search[dir]` never gets populated, `find_command()`
never finds ANY verb in ANY directory, and `command_hook()` falls
through to the driver's own `default fail message` for literally every
command a player types — `look`, `score`, `kill`, everything —
including for the account that just finished registering. No crash, no
debug.log signal at all; the only visible symptom is every single
command silently answering with the driver's generic "what?" text
(`什麼？` in this lib's `config.fluffos`), which is easy to mistake for
§8.3's `private command_hook` or dead-command-table sscanf bugs (§8.3a/
§8.3b) — check those first since they're more common, but if both come
back clean and EVERY command including `look` fails identically, grep
the driver's C source for what `func` string `get_dir()` (or any other
efun you're suspicious of) actually passes to `valid_read`/
`check_valid_path`, rather than assuming only the funcs already in this
catalog exist. Fixed by adding `case "stat":` to the same allowlisted
`switch(func)` as `load_object`/`recompile_object`/`include`/
`file_size` — listing a directory's filenames is exactly as harmless as
checking one file's size or existence. Verified live: before the fix,
a freshly-registered character's `look`/`score` both returned "什麼？"
immediately after entering the world (native driver, tmux + mudclient
sessions independently reproduced it); after adding `"stat"` and
rebooting, the same account's `look`/`score`/`kill`/`post` all resolved
correctly. **Detection pattern**: if `private command_hook` and the
`.lpc`-suffix sscanf in `commandd.lpc`'s `rehash()` are BOTH already
clean but every typed command still dies with the driver's generic fail
message, suspect a custom `securd.lpc`-style ACL denying `get_dir()`
(func `"stat"`) from the command-table daemon itself — add a
`write_file()` or `printf()` right before the `rehash()` call to
confirm `get_dir()`'s return value directly, and check the ACL's
`switch(func)` list against the driver's own source rather than this
catalog's list, since new efuns can introduce new `func` strings this
project hasn't hit yet.

**Confirmed instance: `hy5`** (same "hy"/海洋 naming, `master.lpc`
byte-identical to `hy`'s, but `securd.lpc` independently rewritten — a
`trusted_read`/`trusted_write`/`exclude_read`/`exclude_write` directory-
prefix ACL, not a `switch(func)` dispatcher). Its `valid_read()` has the
same root shape as every other instance in this section
(`euid = geteuid(user); if (!euid) return 0;`, unconditionally, before
any func-specific allowance) but no `switch(func)` at all to extend —
fixed by adding one, as an early return ahead of the existing euid check:
`switch (func) { case "load_object": case "recompile_object": case
"include": case "file_size": case "stat": return 1; }`. Both known
symptoms confirmed live in the same session: (1) `feature/skill.lpc`'s
`file_size()`-based skill-existence probe crashing the first NPC to
reference a given never-loaded skill file (`chen2`/`陈有德`'s `create()`
in the starting martial-arts hall), and (2) `commandd.lpc`'s `rehash()`
`get_dir()` call (func `"stat"`) being silently denied and leaving
`look`/`score`/every command answering "什麼？" for a freshly-registered
character — reproduced and fixed together in one pass since this lib's
ACL denied both at once (unlike `hy2000`/`hy2002`, which only hit the
`file_size` variant). Detection and fix verified identical to the
pattern above; only the shape of where to splice the allowlist into the
custom ACL differs per lineage — always read the actual `valid_read()`
body rather than assuming a `switch(func)` already exists to extend.

### 7.6 DNS/intermud daemons: exclude from preload, then guard the callers

Standing policy — before first boot, remove `dns_master`-style daemons
from `adm/etc/preload`: they bootstrap against dead remote servers and
hang/crawl the boot (minutes of wall clock, no CPU). Not risk-free by
itself; two follow-on classes:

- **Inline callers elsewhere** (`gb_big5()` mud-list displays, a
  `Mud_name()` macro, `encoding_to_mudlist()`) call the daemon's API
  independent of preload — reroute to a local constant or guard.
  (`haiyang2`, `xixingzhanji`.)
- **Site-verification gates** that call `shutdown(1)` when the daemon is
  absent (an anti-piracy registration check) — kill every connection or
  the whole driver. Guard on `find_object(DNS_MASTER)` truthiness,
  absent ⇒ skip the gate. (`xiyouji2003`, `xiyouji450`, `xiyouji`,
  `syxjl`, `longyunmeng`.) Same idiom family as the WASM
  VERSION_D gates (§1.3c).

After the exclusion, always boot AND connect before considering it done.

### 7.7 Unguarded `restore()` / corrupted save data

- A daemon's `create()` calling `restore()` uncaught on a stale/corrupt
  shipped `.o` file aborts `create()` and can masquerade as an
  intentional gate — `zhonghua2`'s "正在同步版本" maintenance message
  was a crashed version daemon that never set its ready flag. Any
  unexplained "syncing/please wait" banner ⇒ check debug.log for
  `restore_object(): Illegal mapping format` first. Move the corrupt
  save aside (restore-on-missing is not an error).
- Corrupt save data can also crash silently under `catch()` and leave a
  daemon half-initialized (a GBK byte run inside `securd.o`'s
  channel_id on `haiyang2`) — fix the data file directly.
- **`restore_object(file)` without flag 1 ZEROES every global variable
  absent from the save file** — not just "doesn't set them". A field
  the save predates (or that testing never wrote) silently nulls an
  initialized global, and the crash surfaces far away (an indexing
  error on quit, in `haiyang2`'s topten object). Guard after restore:

  ```lpc
  restore_object(FILE);          // wipes globals missing from FILE
  if (!pointerp(top_list)) top_list = allocate(10);   // rebuild defaults
  ```
- **Whole-directory legacy binary save format, not a single corrupt
  file.** `jyqxc`'s `data/board/*.o` (all ~49 bulletin-board saves)
  start with magic bytes `#inh`/`?inh` — a compact binary encoding this
  driver's `restore_object()` cannot parse at all (`*restore_object():
  Illegal file format`). Since these objects store properties in one
  `mapping dbase` variable (a `set()`/`query()` feature, not raw
  globals), the zeroing-on-failed-parse wipes the *entire* property
  table, including values `set()` moments earlier in the same
  `create()` (e.g. `set_name()`'s `"id"`). The crash then surfaces in
  wholly unrelated shared code far from any board file:
  `feature/name.lpc`'s `short()` did `capitalize(query("id"))`
  unguarded, so *any* room containing a board crashed `look` for every
  player. Reformatting dozens of legacy binary saves is out of scope
  (content restoration, not a code fix, with no guarantee of getting
  the original encoding right) — fix the shared crash site instead:
  guard the `capitalize()`/similar call on `stringp()`, matching the
  general "restore() can legitimately fail, code downstream must
  tolerate it" lesson above.

  or pass flag 1 where preserving unmentioned globals is the intent.
- **Second confirmed instance of the `capitalize(query("id"))` crash
  site, different proximate cause: `njhhdxdes2hx`.** Same shared-code
  crash (`feature/name.lpc`'s `short()`), same board-triggers-it-on-
  every-`look` symptom, but this time the save file (`data/board/
  common_b.o`) is a normal text-format save (not `jyqxc`'s binary
  `#inh` format) whose message bodies were simply never converted from
  raw GBK — the invalid byte sequences embedded in the `notes` array's
  `msg`/`title`/`author` strings appear to break `restore_object()`'s
  parse partway through, with the same end result: the whole `dbase`
  mapping — including `id`, set moments earlier in `create()` — ends up
  wiped. Confirms the general lesson generalizes across DIFFERENT
  underlying corruption shapes (wrong binary format vs. invalid string
  encoding), not just the one binary-magic-bytes case — same fix
  (`stringp()`-guard the shared crash site) applies regardless of why
  the restore failed.
- **Third confirmed instance, a third distinct corruption source, plus
  a wider collateral-damage mechanism: `fy2`/`fy2qh` (byte-identical
  siblings).** `std/bboard.lpc`'s (and `std/jboard.lpc`'s) `setup()` did
  `move(loc); ...; restore();` with NEITHER call guarded. This time the
  corruption source was a genuine `.o`-file conversion gap (§4.1: some
  `data/board/*.o` save files were never GBK→UTF-8 transcoded at all —
  `restore_object(): Invalid utf8 string`), not a wrong binary format or
  embedded-invalid-bytes-in-text. Same end result as the two instances
  above: the throw aborts the board's `create()` before `set_name()`/
  `id` is ever set, and every subsequent `look` at the ROOM containing
  that board crashes a second time on the same
  `capitalize(query("id"))` in `feature/name.lpc`'s `short()` — but
  because this crash is a **first-boot-load**, not a first-*visit*, it
  does NOT self-heal after one visit the way the §7.17/§7.19/§7.22
  family does; it keeps crashing every `look` at that room for the rest
  of the boot, since the board's in-memory name/id state is genuinely
  never populated, not just racily so. A second, independent trigger for
  the same unguarded-`move()`/`restore()` shape: a board whose own
  `"location"` field is a stale/renamed path (§7.18) makes the unguarded
  `move()` throw instead, with the identical collateral effect on the
  owning room. Fix: wrap BOTH the `move()` and the `restore()` calls in
  `std/bboard.lpc`/`std/jboard.lpc`'s `setup()` in `catch()` — a bad
  board (missing location, corrupt/un-transcoded save data) now degrades
  to an unpopulated-but-present board object instead of aborting the
  room's own `create()`. This is the same general lesson §7.73's own
  "wider blast radius" addendum documents (an uncaught throw inside a
  populated CHILD object's `create()`/`setup()` can silently truncate
  whatever statements come after it in the PARENT room's `create()`) —
  here the child is a board via `restore()`/`move()` rather than an NPC
  via `carry_object()->wear()`, confirming the general shape recurs with
  different trigger calls, not just the one already cataloged there.

### 7.8 Case-sensitive DATA-file paths (Windows-origin)

`read_file("/adm/single/MUDVISITOR")` vs on-disk `mudvisitor` — no
compile error; `read_file()` returns 0 at runtime and the crash lands
wherever that 0 flows (`sscanf`), which on a `logon()` path kills every
connection with a totally empty transcript — looks like a dead server.
When the very first connection produces literally nothing: check
debug.log for a `Bad argument`/sscanf error rooted in
`logon()`/`connect()`, then `find -iname` the path. (`shiji`,
`xianlvqiyuan`'s BANNER, more.)

### 7.9 The `sscanf(read_file(...))` login-banner crash bomb (fresh-checkout class)

A recurring specific shape of §7.8 worth its own entry: `logind.lpc`
visitor/uptime counters do

```lpc
// BEFORE — crashes EVERY connection when the counter file is absent:
sscanf(read_file("/log/MUDVISITOR"), "%d", n);
// AFTER:
string s = read_file("/log/MUDVISITOR");
if (stringp(s)) sscanf(s, "%d", n);
```

The counter file is RUNTIME data — gitignored/absent in a fresh
checkout — so a lib that tested fine can ship broken-on-first-boot for
everyone else ("works on my tree" fresh-checkout bomb). Every
`read_file()` whose result feeds `sscanf`/string ops on a
connection-setup path needs a `stringp()` guard. Known fixed:
`xiakexing100`, `xiyouji2006`, `zitengzhan`, `zzfy`, `yueyingqiyuan`,
`rzrmud` (found live on the published WASM site, not in any prior local
pass — the gitignored counter file happened to already exist on that
session's own disk from earlier testing, masking the crash locally;
only a genuinely fresh checkout/CI pack reproduces it); also the
`uptime.lpc` `write(read_file(LASTCRASH))` variant (`xjcq2000`,
`moniHuafu`, `syxjl`, `mnhf` — see also §7.11 for the
receiving side). On `mnhf` this crash fired on the FIRST connection
attempt, since `logind.lpc`'s `logon()` calls `UPTIME_CMD->main()`
before the id prompt on every connection — the driver auto-retried and
a second attempt showed a normal-looking banner, so a shallow test
that only looks at the final transcript can miss this entirely; check
for a `new_conn_handler: logon() ... has failed, the user is
disconnected` line earlier in the log.
Grep: `grep -rn "sscanf(read_file\|write(read_file" work/`.

**Whole-directory-missing variant, found on `xxcq`'s deep functional
test (§10.7): every registration was silently aborted, stranding the
character with no environment at all, no error ever shown to the
player.** This archive shipped with no `/adm/etc/` at all (already
known from the WASM pass — see below), but the WASM-fix pass's directory
seed only created `users`/`iduser`, missing `/adm/etc/motd`. `logind.lpc`'s
`enter_world()` does `write(read_file(MOTD));` completely unconditionally,
with **no** `stringp()` guard and not even inside the usual
`sscanf`/uptime-counter idiom — `write(0)` throws `*Bad argument 1 to
receive(): Expected: string or buffer Got: 0` straight out of
`receive_message()`, uncaught, which aborts `enter_world()` **before**
the `user->move(startroom)` call that appears later in the very same
function. Net effect: the character object is fully created and saved,
but never actually placed in any room — `look` afterward shows "你的四
周灰蒙蒙地一片，什么也没有" (the generic no-environment message), with
no crash trace visible to the player and nothing in debug.log pointing
at the real cause unless you're watching boot.log at the exact moment.
Symptomatic of a broader lesson: §7.9's fix pattern (`stringp()` guard)
has to be applied to **every** unconditional `write(read_file(...))`
that sits before a room-move in the login chain, not just the ones
already shaped like a counter/banner read.

A second daemon on the same archive hit the identical root cause one
level removed: `adm/daemons/natured.lpc`'s day/night-phase system reads
`/adm/etc/nature/day_phase` (also entirely absent) via
`explode(read_file(file), "\n")` with no guard, crashing
`*Bad argument 1 to explode()` the first time anything lazily touched
it (here: the wizard-start room's own `move()` triggering an
auto-`look`, then every subsequent outdoor room). Guarding just the
`explode()` call is not enough on its own, though — `day_phase` ends up
an **empty array**, and half a dozen *other* functions in the same file
(`init_day_phase()`, `update_day_phase()`,
`outdoor_room_description()`/`_outcolor()`) all index
`day_phase[current_day_phase]` assuming at least one entry exists;
`sizeof(day_phase)-1` goes negative, and modulo-by-`sizeof(day_phase)`
divides by zero. Patching each read site individually is fragile and
easy to under-cover; the more robust fix is a single minimal one-entry
fallback table installed right where the file is read, so every
existing index/modulo computation downstream stays well-defined:

```lpc
day_phase = read_table("/adm/etc/nature/day_phase");
if (!sizeof(day_phase))
  day_phase = ({ (["length": 1440, "desc_msg": "...", "outcolor": "...", "time_msg": "..."]) });
```

General lesson: when a `read_file()`/table-parse guard produces an
*empty* collection rather than erroring, grep every other use of that
same variable in the file before declaring the fix complete — an empty
array/mapping is a different failure mode than a missing file, and can
resurface the same crash (or a new one, e.g. division-by-zero) one
level downstream.

### 7.10 `log_error()` receives WARNINGS too — and must not touch the ACL

Two independent traps in the same apply:

- This driver funnels soft compile warnings (e.g. §4.3's nosave
  warning) through `APPLY_LOG_ERROR` alongside real errors; a mudlib
  that broadcasts them to players spams everyone with scary messages
  (98 in one session on `wuhanzhan`). Gate the broadcast on the message
  NOT containing the severity marker. **Case history, since this has
  flip-flopped once already and cost real debugging time both
  directions:** the driver originally used capitalized `"Warning:"`
  (matching this whole corpus's old MudOS-era convention); a compiler
  rewrite switched it to clang-style lowercase `"warning:"`, silently
  breaking every mudlib's capitalized check (`shenzhou`, `bmxkx2001`
  shipped with what was, at the time, a "broken-case" gate); this
  project's own driver fork then reverted that back to capitalized
  `"Warning:"`/`"Error:"` specifically for this corpus's sake (see
  fluffos PR `claude/keep-capitalized-warning-error`, and this file's
  §7.104-adjacent case-mismatch fixes on `hhsj`/`nt6`/`ntii`/`nte` from
  that same investigation). **Don't hardcode either case going
  forward** — match the substring `"arning:"` (no leading `w`/`W`),
  which is present in both `"warning:"` and `"Warning:"` identically,
  so the check survives if this ever flip-flops a third time. A
  corpus-wide sweep (2026-08-12) already converted every previously-
  lowercase-only `strsrch(message, "warning:")` gate found across the
  corpus to this case-agnostic form.
- `log_error()` calling `wizardp(this_player(1))` (or anything that
  lazily loads the security daemon) can fire from the FIRST preload
  compile, before securityd exists — crashing every boot at the
  earliest possible point (`shenzhou`), or generating dozens of caught
  error-traces per boot (`bmxkx2001`). Guard with
  `find_object()` checks, same discipline as §7.1.
- Related: `error_handler()` is a `void` apply here — old "falls
  through to debug.log" comments lie. An explicit
  `efun::write_file("/log/RUNTIME_ERRORS", trace)` inside the handler is
  cheap permanent insurance. And an error handler whose own body calls
  an unguarded daemon (`CHANNEL_D->do_channel()`) mid-compile re-enters
  itself — "Error in error handler" cascades, ~150 log lines each
  (`bxsj`/`bxsj1`) — guard those call sites with `find_object()`.

### 7.11 Missing runtime directories and the silent write_file abort

- An uncaught `write_file()`/`log_file()` into a directory the archive
  never shipped (`/log/nosave/`, `data/user/a/`...) fails mid-flow; if
  it sits deep in a registration `call_other` chain the error reaches
  NOTHING standard — not debug.log, not the player; on
  `xajh2` it appeared only in the lib's own custom
  `/log/runtime/secure` log. Registration "silently stalls" ⇒ also grep
  the lib's own custom log paths. Fix: `mkdir -p` every directory any
  write call references as part of pre-boot setup (save-data shards
  `data/{login,user,npc}/{a-z}/` included — `save_object()` does a bare
  fopen with no mkdir), plus `catch()` at the call site.
- The player-side twin: `receive_message()` on the PRE-LOGIN connection
  object missing the standard `!stringp(str)` guard that every
  post-login body copy has — `write(0)` from routine startup code then
  crashes every fresh connection at the first banner line (`haiyang2`'s
  `clone/user/login.lpc`). Audit the pre-auth object's copy separately.
- **Sibling-lineage instance, same custom-log-not-debug.log shape, worse
  severity: `xajhxo`.** Same TMI-2/ES2/Falcon "XO" family as `xajh2`
  above (§11). `logind.lpc`'s `get_gender()` — the LAST step of
  character creation, called right after the gender prompt — calls
  `log_login()`, which calls the simul_efun `log_file()`
  (`write_file(LOG_DIR + file, text)`, no directory guard at all) to
  append to `/log/static/usage`, a directory this archive never shipped.
  Because this fires before `init_new_player()`/`enter_world()` in the
  same function, EVERY new registration died right there — silently
  routed to this lib's own `error_handler()` (`mudlib error handler : 1`
  in `config.fluffos`), which writes to `log/runtime`, not
  `debug.log`, exactly like `xajh2`. The player saw a bare `>` prompt
  forever, no error, no world entry — misdiagnosed in an earlier pass on
  this same archive as a WASM-only timing artifact around this exact
  `get_email()`→`get_gender()` handoff; it reproduces identically on the
  native driver and has nothing to do with WASM. Fix used this lib's own
  pre-existing `assure_file(file)` helper (already correctly called by
  `log_d.lpc` and others in the same tree) instead of a blanket `mkdir
  -p`: `assure_file(LOG_DIR + file); write_file(LOG_DIR + file, text);`
  — needed a one-line forward declaration too, since `assure_file()` is
  defined textually after `log_file()` in the same file and this
  compiler doesn't resolve forward references without one (same
  convention `logind.lpc` itself already uses for its own helpers).
  Lesson: when §7.11 hits a registration flow specifically, check
  EVERY `log_file()`/`write_file()` call between the last input prompt
  and the actual `enter_world()`/move-into-game call, not just the
  first one found — this one was buried inside a *logging* side-call,
  not the visible save/world-entry code itself.
- **New blast-radius shape, `nitan_ceshi`'s deep functional test (§10.7):
  a non-fatal, permanently-silent variant outside `log_file()`
  entirely.** `adm/daemons/toptend.lpc::topten_save()` (the top-ten
  leaderboard daemon, called from `logind.lpc::enter_world()` for every
  non-wizard login) did the same unguarded `write_file()` into a
  never-shipped `/data/topten/` directory, but its own
  `if (!write_file(...)) return notify_fail(...)` guard kept it from
  crashing the registration flow the way the `log_file()` call sites
  above do — the failure just meant the five leaderboards
  (rich/pker/exp/age/killed) silently never updated for any player,
  forever, with the error visible only in `debug.log`'s ordinary
  runtime-error stream (not a custom log path this time). Same fix
  shape (`assure_file(f_name)` before the `write_file()`), same lesson:
  §7.11 is not confined to `log_file()`/simul_efun call sites or to
  registration-blocking failures — grep every unguarded `write_file()`
  in daemons that fire on common player actions, not just the login
  chain.
- **Escalated-severity instance, `xixingzhanji`'s deep functional test
  (§10.7): the exact same `topten_save()` shape, same missing
  `/topten/` directory, but this time the `write_file()` call itself
  throws instead of just returning 0.** `nitan_ceshi`'s finding above
  relied on `if (!write_file(...)) return notify_fail(...)` degrading
  gracefully because `write_file()` returned a falsy value on failure.
  On this lib's driver build, `write_file(f_name, str, 1)` — note the
  3rd arg, FluffOS's "open in overwrite mode" flag, absent from
  `log_file()`'s plain 2-arg calls — throws `*Wrong permissions for
  opening file /topten/rich.txt for overwrite` / `"No such file or
  directory"` when the parent directory doesn't exist, rather than
  returning 0. Because this call is UNCAUGHT and sits textually BEFORE
  the player's start-room `move()` in `logind.lpc::enter_world()`
  (`"/adm/daemons/toptend"->topten_checkplayer(user);` runs first, the
  `if (user->query("no_gift")) user->move(...)` block second, same
  function), the whole rest of `enter_world()` — including the move —
  never executes. Every new registration completed the id/name/
  password/gender prompts, printed the normal "目前权限" banner, then
  silently left the player parented to no room at all (`look` showing
  "灰蒙蒙一片", `quit` then crashing per the `message()` entry above) —
  with NO error visible to the connecting player and nothing before a
  `debug.log`/`RUNTIME_ERRORS` grep to suggest why. Lesson: `write_file(f,
  s, 1)` (overwrite mode) is not equivalent to the bare 2-arg
  (append-creates-if-missing) form for missing-directory behavior on
  this driver — audit `write_file(..., 1)` call sites for a missing
  `assure_file()`/`mkdir` guard even more aggressively than plain
  `write_file()` sites, since the failure mode here is a hard throw, not
  a quiet return-0. Same fix (`assure_file(f_name)` before the call);
  additionally wrapped the `enter_world()` call site itself in `catch()`
  as defense-in-depth, since a second, unrelated bug in the same
  function (`topten_add()`'s `sscanf` array-argument slip, new §7.54
  instance below) was ALSO capable of aborting this exact call chain.
- **Third+ independent confirmation in the same 夕阳再现/XYZX lineage:
  `xajhzcjh`'s deep functional test (§10.7).** Identical shape to
  `xajhxo` above, down to the exact call site (`logind.lpc`'s
  `get_gender()`, the step right before `enter_world()`, calling
  `log_file("login/newid.log", ...)`), and `libs/xyzxfy2` and
  `libs/ylfyxa3` had ALREADY independently found and fixed the identical
  bug in their own deep-test passes before this one — `adm/simul_efun/
  file.lpc`'s `log_file()`/`assure_file()` pair is a shared low-level
  utility file copy-pasted across this whole engine family (confirmed:
  `bixiecanyang` and `jhfy` still carry the unfixed, bare-`write_file()`
  version as of this writing). **Check this exact file/function FIRST**
  on any future 夕阳再现-lineage deep-test pass, before spending time
  live-diagnosing what looks like a mysterious "registration silently
  stalls with no banner, no working commands, no save, and nothing in
  debug.log" bug from scratch — it's almost certainly this.
- **Fourth+ instance, unrelated lineage: `zjmudhell`'s §10.7 deep
  functional test** (custom mobile-app-protocol "hell"-map-content
  archive — §11 — unrelated codebase to the 夕阳再现/XYZX family above
  despite sharing this exact bug shape). `adm/simul_efun/file.lpc`'s
  `log_file(string file, string text)` was a bare `write_file(LOG_DIR +
  file, text)` with no `assure_file()` guard, even though `assure_file()`
  is declared in the very same file, two functions below it, and is
  already used correctly by a dozen other call sites across the tree
  (`channeld.lpc`, `examined.lpc`, `versiond.lpc`, `securityd.lpc`,
  several `adm/npc/*.lpc` files, `cmds/arch/{punish,restore}.lpc`).
  `clone/user/login.lpc`'s `logon()` — the very first thing that runs on
  ANY new connection, before the version-handshake banner even prints —
  calls `log_file("nosave/logon", ...)` unconditionally. `log/nosave/`
  happened to already exist on disk from an earlier WASM-stage pass
  (confirmed via `git status`/`git ls-files`: it was NEVER git-tracked,
  since this whole project's `.gitignore` excludes `libs/*/work/log/`
  wholesale as driver-recreated runtime state — same treatment as
  `debug.log`), so the crash hadn't been re-triggered since. A previous
  pass's own NOTES.md flagged this exact risk ("created-but-possibly-
  missing `/log/nosave` directory") without confirming whether the
  underlying code was actually fixed or the directory just hadn't been
  lost yet. Verified live both ways: temporarily renamed `log/nosave`
  out of the way and confirmed a fresh driver boot + connect against the
  UNFIXED code hung the very first connection dead at the version
  banner (never even printed `ver1.0,...`); applied the standard
  `assure_file(LOG_DIR + file);` guard immediately before the
  `write_file()` call, and the identical fresh-boot-with-missing-
  directory scenario then connected cleanly, auto-creating `log/nosave/`
  on demand (confirmed via `ls`/`git status` immediately after — freshly
  timestamped, containing only the files this session actually wrote).
  Hit the exact same forward-reference gotcha `xajhxo` above already
  documents: `assure_file()` is defined textually AFTER `log_file()` in
  this file, so the fix needed its own one-line forward declaration
  (`void assure_file(string file);` near the top of the file) or the
  whole `simul_efun`/`master` compile fails outright (`No program in
  object '/adm/single/simul_efun'!` — a hard boot-abort, not a warning).
  Confirms this exact bug shape (unguarded `log_file()` sitting right
  next to its own unused `assure_file()` helper) recurs independently
  across at least two unrelated codebase families, not just the
  夕阳再现/XYZX lineage above — grep any new lib's `log_file()`
  implementation for a missing `assure_file()` call on sight, regardless
  of which engine family it belongs to.
- **Fifth+ instance, a third unrelated lineage: `ldtx`'s §10.7 deep
  functional test** (Century/`adm-single` family — §11 — unrelated to
  both the 夕阳再现/XYZX lineage and `zjmudhell`'s "hell"-map codebase
  above, yet the identical `adm/simul_efun/file.lpc` shared-utility
  file, right down to `log_file()` sitting unguarded two functions above
  its own already-correct `assure_file()` helper). Symptom here was
  milder than a boot-time hang: `/log/nosave/` was one of the few
  `log_file()`-referenced subdirectories genuinely missing from this
  archive (confirmed via a full-tree grep of every `log_file("<dir>/...",`
  call site against `find work/log -type d`), and it's the target of
  `cmds/app/update.lpc`'s own audit-log line — so every wizard `update`
  command, on a lib that otherwise boots and plays perfectly cleanly,
  threw a raw stack trace to the wizard's screen (`*Wrong permissions
  for opening file /log/nosave/update for append. "No such file or
  directory"`) immediately AFTER a successful recompile, masking the
  "成功！" confirmation message. Same 17 call sites share `nosave/` in
  this lib (`master.lpc`'s crash logger, `securd.lpc`'s promotion
  logger, and most `cmds/{app,arch,wiz,std}/*.lpc` audit logs), all
  silently broken the same way. Same fix, same forward-declaration
  gotcha, same verification method (`update <path>` as admin, before/
  after). Fourth unrelated confirmation this bug shape is a near-
  universal copy-paste idiom, not tied to any one lineage — the pairing
  of "`log_file()` with no `assure_file()` guard" plus "the guard
  already exists two functions below, unused" is now common enough that
  it's worth checking on sight in ANY newly-encountered `adm/simul_efun/
  file.lpc`, independent of engine family.
- **Sixth+ instance, and the most severe blast radius yet: `jyqxc2013fwq`'s
  §10.7 deep functional test — this one breaks the death/resurrection
  system itself, on EVERY death, not just registration or a leaderboard.**
  `adm/daemons/combatd.lpc::killer_reward(object killer, object victim)`
  — called unconditionally from `feature/damage.lpc::die()` for every
  single death, player or NPC-on-player — ends with an unguarded
  `write_file("/log/nosave/KILLRECORD", ...)` into a directory this
  archive never shipped. Unlike the `topten_save()`/leaderboard instances
  above, this write sits BEFORE the two lines in `die()` that actually
  matter: `this_object()->move(DEATH_ROOM); DEATH_ROOM->start_death(...)`.
  Because the throw is uncaught, it doesn't just abort `killer_reward()`
  — it unwinds the entire call stack back through `die()` and up to the
  `heart_beat()` that triggered it, so the move-to-death-room and
  `start_death()` calls never execute. The result, verified live: a
  player killed by an ordinary street NPC (流氓头/"thug leader") got
  "你死了" ("you died") printed every combat heartbeat, forever, while
  remaining in the same room, at 0 HP, still being attacked by the same
  NPC, which itself kept re-triggering `die()` on the next heartbeat —
  an infinite "already dead but never actually removed from combat"
  loop with no way out except a wizard `update`/directory fix, not
  merely a missing log line. This lib's own `adm/simul_efun/file.lpc`
  already had a correct, unused `assure_file()` helper (same idiom as
  the instances above); adding `assure_file("/log/nosave/KILLRECORD");`
  immediately before the `write_file()` call fixed it — hot-`update`d
  `combatd.lpc` while a test character was mid-loop, and the very next
  heartbeat's death resolved cleanly, moving the player to `/d/death/gate`
  and completing a full, undisturbed death→白无常 dialogue→`reincarnate()`
  →revive-room cycle. **`jyqxc`/`jyqxc2` (this lib's already-deep-dived
  sibling archives, same architecture family, §11) carry the byte-identical
  unguarded `write_file()` call in their own `combatd.lpc` — unlike this
  lib, theirs is gated behind `if (userp(killer))` (player-killed-player
  only), so it never fired during either of those libs' own §10.7 passes
  (both killed an NPC), and remains UNFIXED there as of this writing.**
  Detection pattern: when a death sequence "sort of" works — the death
  message prints, but the player never leaves the room, or the same death
  message repeats every few seconds — suspect an uncaught error partway
  through `die()`/`killer_reward()`/equivalent aborting the function
  before its actual state-transition (move to death room, `reincarnate()`,
  revive) runs; check for any unguarded `write_file()`/`log_file()` call
  textually BEFORE that transition in the same function, not just at
  the login/registration boundary this bug class was first found at.

### 7.12 Shared message/wrapper argument bugs

A 2-arg `tell_room()` wrapper passing a raw int 0 as `message()`'s
exclude argument → `Bad argument 4 to message()` on the first room
heartbeat (578 call sites, ONE shared root — fix the wrapper:
`exclude || ({})`). When a preloaded room crashes on its own heartbeat
with an efun-arg-type error, suspect the shared simul_efun wrapper, not
the room. (`yueyingqiyuan` and most of the ES II family; combine with
§6.5's binding-order trap — the wrapper fix can be silently bypassed.)
Missing `message_combatd`/`message_sort` simul_efuns: alias to
`message_vision` (defined AFTER it in the file, per §6.5).

**Severity escalation, found on `dtsl`'s deep functional test (§10.7) —
raise this bug's priority, it is not merely cosmetic**: this same wrapper
bug, hit from a `call_out`-driven function with no enclosing `catch()`
(as opposed to a player-typed command, where the driver's own top-level
handler catches it and the only visible damage is an ugly `debug.log`
line), aborts the REST of that function at the exact statement — on
`dtsl`, that function was `obj/user.lpc`'s `user_dump()`, the
`NET_DEAD_TIMEOUT`-driven (900s / 15 real minutes) force-quit handler,
and the two lines after the crashed `tell_room()` call
(`enable_player()`; `command("quit")`) never ran — **silently disabling
the entire net-dead force-quit safety net**: any player who net-deads
and never manually reconnects stays alive in server memory forever
(until restart), never properly saved via this path. Worse: reproducing
this live, TWO characters hitting the aborted `user_dump()` at nearly the
same real moment, followed by a reconnect attempt, was immediately
followed by an actual **native driver process crash** — a C-level
double-free abort (`debugmalloc: attempted to free non-malloc'd
pointer`) inside `dealloc_object()`/`free_svalue()`, taking down the
whole MUD for every connected player. The exact C-level mechanism wasn't
rigorously proven (would need ASan/valgrind, out of scope for an
LPC-focused pass), but the correlation is strong and the crash did not
recur after the standard fix. **This is exactly the kind of consequence
that only a real, full-duration net-dead wait (§10.7's checklist item 8)
will ever surface** — 40+ minutes of otherwise-thorough live gameplay on
this same pass never hit any OTHER instance of this bug among the 80+
2-argument `tell_room()` call sites in the lib. Any lib carrying this
`tell_room()` shape should be treated as carrying a live crash risk, not
just an annoyance, until the wrapper is fixed.

### 7.13 Booby traps: phone-home license checks and self-destructs

Functions in `securityd.lpc`-like files whose body mass-deletes the
mudlib / `shutdown()`s, gated on an opaque "license"/date check —
sometimes dormant, sometimes genuinely reachable (`fy3dz`
via `gtell.lpc`; a year-2109 time bomb on `fy2005`). While reading any
security daemon, grep for `rm(`/`unlink`/`shutdown` in
non-admin-command context and neutralize the destructive body (keep the
function so callers don't break). This project is exactly the "next
host" these traps were aimed at.

### 7.14 Assorted runtime traps (one-liners)

- **`file_size()` in boolean context**: returns -1 (missing) / -2
  (dir), both truthy — `if (file_size(path))` means "if MISSING or
  file". Use `>= 0`. Caused infinite virtual-object recompiles on
  `zhongjidiyu`.
- **`crypt(str, 0)`**: int salt = fresh random SHA-512 hash per call
  here (was: deterministic DES) — made a client challenge/response
  handshake mathematically unpassable, zero errors anywhere
  (`zjdyzj`; fixed with an explicit string salt `"zj"`).
  Check every crypt() in custom handshakes.
- **Factory calls chained without a check**:
  `SOME_D->create_x(...)->move(...)` — factories legitimately return 0
  on missing content; old drivers no-op'd call_other on 0, this one
  throws. Guard `if (objectp(ob))` at the call site; don't "fix" the
  factory.
- **Unguarded `environment(me)` in quit/command paths**: `quit` racing the
  post-registration prompt (or any moment the body has no environment)
  crashes on `environment(me)->query(...)`. Guard with
  `if (environment(me))`. Recurs across the 风云 family (`fy2`,
  `fy2qh`, `fengyun434`, `fy3xd`,
  `fy3dz`, `xyj2000f`, `esI`) — when fixing it in
  one member of a family, port it to every sibling immediately.
- **Missing post-registration destination room**: registration moves
  the new player to a gift/init room absent from the archive; the move
  silently fails, the player has NO environment, and every command
  breaks — symptom-identical to the command-hook bug (§8.3) with a
  completely different cause. Guard the move with
  `load_object()`/fallback to START_ROOM. (`xiyouji2003`.)
- **Missing zone content is an archive gap, not a bug**: whole `d/`
  subtrees absent, dozens of boards referencing them. Document in
  NOTES.md, don't fabricate rooms.
- **`__FILE__` in an `#include`d fragment** expands to the FRAGMENT's
  path, not the includer — misattributed runtime errors by the hundred.
  Replace with `file_name(this_object())`. (`xlqy_early`,
  `longyunmeng`.)
- **check_config-style driver self-checks** inherited into
  simul_efun/master `error()` on stale MudOS `#ifdef` assumptions
  (`__PRIVS__` vs `PACKAGE_UIDS` assumed exclusive). Disable just the
  failing checks, keep the file. (`tianxia`.)
- **versiond `socket_bind()` config-ID noise**: harmless if the ready
  flag is set synchronously before the failing call — read the code
  before chasing a single non-fatal boot-log line.
  (`yhyxs`.)

### 7.15 The nitan `set`/`query`/`dbase` architecture bug (the deep one)

The NT/nitan/Lonely lineage implements per-object property storage as
**bare simul_efun calls** (`set(prop, val)` / `query(prop)` /
`delete(prop)`, tens of thousands of call sites), relying on
`this_object()` being the CALLER during a simul_efun call. On this
driver `this_object()` inside a simul_efun is the SIMUL_EFUN OBJECT —
so every object without a local override reads/writes ONE shared
property bag. Fix, two parts:

1. Give `feature/dbase.lpc` real local `set`/`query`/`delete`
   (+`_temp`, `add`) methods — nearly everything already
   `inherit F_DBASE`, so bare calls then resolve locally per object.
   The 3-arg convention's trailing `ob` redirects via plain
   `ob->set(...)` when `ob != this_object()`.
2. Keep a matching fallback set in the simul_efun for non-F_DBASE
   objects, with the same redirect.

**Recursion trap inside the fix**: files with a partial local override
falling through to "the generic implementation" must fall through as
`::set(...)` (parent scope), NEVER `SIMUL_EFUN_OB->set(..., this_object())`
— the simul_efun's redirect calls straight back into the override.
Only use `ob->X(...)` when `ob` is a different object.

**Scope**: applies to `nitan170911`/`nitan6` (check
`adm/kernel/simul_efun/wizard.lpc`); does NOT apply to every nitan-ish
lib — `nitan_ceshi`/`nitan_san` predate the bug (real local dbase
already present), `rzrmud`/`syxjl`/`xajh2`/
`yxcs` have real per-object storage. Check whether the
simul_efun actually defines global set/query before assuming.

**A port of this fix can carry the explanatory comment without the
actual fix.** On `nt6` (a distinct-but-related lineage, ported from
`nitan170911` in an earlier pass), `feature/dbase.lpc` had this
section's exact reasoning copied in as a comment — "the real fix:
define set/query/delete directly HERE... nearly everything" — sitting
directly above `set`/`query`/`delete` function bodies that were simply
never copied over; only `add()`/`query_entire_dbase()`/`set_dbase()`
etc. existed. The lib still booted clean (no compile error — a missing
function isn't a syntax error) and got marked as having this fix
"applied" on that basis, but registration failed immediately
(`set("id", arg, ob) != arg` → "Failed setting user name.") because
bare `set()` calls were still hitting the simul_efun's shared fallback.
**Never trust a fix-claiming comment without grepping the file for the
function signature it claims to define** — `grep -c
"^varargs mixed set(string prop"` the target file directly, don't just
read the prose above it. (Confirmed identically on `nt6nitan6win`, same
lineage/master hash — diffed byte-identical to `nt6`'s pre-fix state
before copying the corrected files across.)

**A downstream consequence worth checking once `set`/`query`/`delete`
are real local (inherited) functions**: any file that locally overrides
one of them and tries to call "the un-overridden version" via
`efun::set(...)`/`efun::query(...)`/`efun::delete(...)` will now fail
to compile — `set`/`query`/`delete` were never genuine driver efuns
here (`error: Unknown efun: set`), only simul_efuns/inherited
functions, and `efun::` only resolves true built-ins. Grep
`efun::(set|query|delete|addn|set_temp|query_temp)\(` across the whole
lib once §7.15's fix is in place; fix by switching to `::set(...)` etc.
(parent-scope, now resolves through the completed F_DBASE). `addn` is a
special case — it's simul_efun-ONLY (never inherited, see this
section's own `addn()`/`addn_temp()` in `wizard.lpc`), so `::addn(...)`
has no valid target; replace with either a direct
`(ob||this_object())->add(prop, data)` call, or `::add(...)` when the
surrounding override is itself named `add()` and the `addn` was
actually just a typo for `add` (both shapes seen on `nt6`: `user.lpc`
and `giftd.lpc` had the typo inside an `add()` override, `baby.lpc` had
a genuinely-named `addn()` override needing the `ob->add()` replacement).
(`nt6`: 5 files — `user.lpc`, `baby.lpc`, `giftd.lpc`, `examined.lpc`,
`room.lpc`.)

### 7.16 Stale shipped real-timestamps feeding an unbounded catch-up loop

A saved data file that ships as part of the archive (leaderboards,
rankings, anything with a per-entry `"time"`/epoch field) can carry
**real Unix timestamps from the original live server's era** (seen:
`bxsj`'s `/log/rank`, real ~2008 player-ranking data,
`"time":1219369347`). Harmless on its own — until a LOOP (not a
one-shot comparison) uses `time() - saved_time` to decide how many times
to iterate, e.g. an hourly score-decay pattern:

```lpc
// pattern to grep for: while(...["time"]...< t) / while(...time()...)
while (rank["time"] + 3600 < t) {
    rank["time"] += 3600;
    rank["score"] = rank["score"] * 97 / 100;   // ~3%/hour decay
}
```

This is safe under the ORIGINAL always-on server, where `t` only ever
drifts forward by however long the driver has been up between calls
(minutes to hours). It becomes pathological the moment a lib boots this
project's frozen ~2008 (or whenever) save data against **today's real
wall clock** — an 18-real-year gap means ~157,000 required iterations
for a single stale entry, times however many entries the table holds —
trivially exceeding the eval-cost limit ("Too long evaluation. Execution
aborted.") every time the function runs. Dangerous specifically when the
function is called unconditionally on a hot path (`bxsj`'s
`cmds/usr/top.lpc add_rank()` family runs on literally **every quit**,
via `cmds/usr/quit.lpc`'s unconditional `TOP_CMD->add_rank(me)`) — every
single quit crashed (caught by the driver's error handler, so the
player-visible "正在退出游戏……" looked completely normal; only
debug.log showed it). **This is exactly the kind of bug a "did `quit`
look right to the player" check will never catch — grep debug.log after
`quit`, not just after login, on any deep pass.**

Fix: cap the loop's iteration count (e.g. 240 hourly steps ≈ 10 days,
already enough to decay any realistic score to near-zero), then
unconditionally jump the stored timestamp forward to `t` regardless of
whether the cap was hit — preserves the original per-hour compounding
for any realistic gap, only changes behavior for the pathological
long-stale case (whose score was headed to noise anyway). Grep for the
pattern (`while.*\["time"\].*< *t\b`, `while\s*(.*time()`) across the
WHOLE lib, not just the one function that happened to crash first —
`bxsj` had five live copies of the identical loop (one per rank
category: score/beauty/pk/rich/worker) plus a sixth already-dead copy
inside a commented-out duplicate function (leave dead code alone).

### 7.17 Unbounded `init()`/`reset()` reentrancy crashes a room's FIRST-EVER visit only

Found on `xiyouji`'s deep functional test (AGENTS.md §10.7), a
completely different lineage from the §7.16 bug. `std/room.lpc`'s
`setup()` calls `this_object()->reset()` synchronously as the last step
of every room's `create()` — but the driver's own standard behavior can
also fire a `reset()` pass on the same freshly-loaded object around the
same trigger (a player's first `move()` into it), so `reset()` can run
**twice**, genuinely reentrant (the second call starting before the
first returns), on a room's very first compile. `reset()` populates the
room's NPCs via `make_inventory()` → `new(file)` → `move(...)` and only
marks that done on its LAST line (`set_temp("objects", ob)`) — a
reentrant second call sees the population-tracking mapping still empty
and clones a **second full set of NPCs**. Cloning + moving an NPC
synchronously fires that NPC's own `init()`, and if that NPC's `init()`
self-locates its home room by forcing a path lookup (e.g.
`call_other(room_path, "???"); find_object(room_path)` instead of
`environment(this_object())`), that force-load can itself re-trigger the
room's own compile — closing a cycle that repeats until the driver's
call-depth limit aborts with `Too deep recursion.`

Player-visible symptom is deceptive: the crash is caught, so the room is
usually still entered, but with corrupted NPC state (a property read
that resolved mid-crash renders as a stray `0` in the NPC's title/name)
— easy to mistake for a content typo rather than a crash, and the
blamed file:line in `debug.log` varies run to run depending on exactly
what was executing when the stack tipped over. **Only reproduces on a
room's first-ever visit after a fresh boot** — once its objects are in
memory, every later visit is clean, so this is invisible to boot-log
watching, registration smoke tests, and even a full playthrough that
happens to visit the affected room a second time before checking. Grep
`debug.log` for `Too deep recursion` specifically, not just `error:`,
after walking a brand-new character through content beyond the start
room.

Fix (two independent reentrancy guards — both closed the cycle in
practice, kept both since each is separately structural, not just a
theory):
1. `std/room.lpc`: a `nosave int resetting_now;` flag, checked and set
   at the top of `reset()`, cleared on every return path. Reentrant
   calls become a safe no-op; the original call still runs once.
   Lib-wide (every room inherits it) but provably inert for the normal
   non-reentrant case.
2. The NPC's own `init()`: a `nosave int in_init_now;` flag guarding the
   entire function body the same way. `init()` is one-time setup with no
   legitimate reason to be reentrant on the same live object.
3. Belt-and-suspenders: if an `init()`-time self-locate function takes
   its own room as a path argument, prefer `environment(this_object())`
   over a forced `call_other(path, "???")`/`find_object(path)` — the
   room is, by construction, always already the NPC's environment at
   that point; only fall back to the force-load if that's somehow not
   true.

**A false lead worth recording**: raising `maximum call depth` in
`config.fluffos` had zero effect on at least one driver build — checked
the actual driver source (`src/vm/internal/base/interpret.cc`) and
confirmed the enforced limit is a compile-time constant
(`CFG_MAX_CALL_DEPTH`), with the config key registered but never read.
Don't assume this key is live without checking the specific driver
build; if the recursion is genuinely cyclic (not just legitimately
deep), a config bump won't help regardless — the fix has to be a code
change. Also: disabling any ONE contributing call site sometimes still
crashed with the blame shifted to whatever ran next — a strong signal
you're looking at a reentrant cycle, not one bad line, when the blamed
file:line moves around between otherwise-identical repro runs.

Check for this shape wherever a lib has multiple structurally-identical
copies of a "sect entrance" / "zone gate" style NPC that all
self-initialize the same way — `xiyouji` had the same vulnerable
`init()`/`create_identity()` pattern copy-pasted into all 9 of its
sect-entrance NPCs; only one was live-reproduced, the rest fixed
proactively by code-shape match (§2.1) and flagged as unverified live.

### 7.18 A hardcoded room path left stale after the ORIGINAL game replaced its own zone

Found on `tiexuejianghu`'s deep functional test (§10.7). Distinct from
every previously-cataloged path bug — those are all conversion-era
typos/renames introduced by THIS project's pipeline. This one predates
conversion entirely: a `#define`d room constant
(`include/login.h`'s `REVIVE_ROOM`, `"/d/yangzhou/temple"`) pointed at a
path that no longer resolves because the ORIGINAL mud's own developers
replaced the entire `d/yangzhou/` zone with an unrelated rewrite at some
point during the game's live history, reusing the same directory name
for incompatible content. The old zone survived intact in the archive,
just relocated to a backup directory (`d/yz_bak/yangzhou/`) that isn't
part of the live map — easy to misdiagnose as ordinary missing content
rather than a stale reference, since the backup directory LOOKS like
leftover cruft rather than the thing the constant actually needs.

Every `call_other()`/`move()` to the stale path throws a caught-but-real
`*call_other() couldn't find object` error. Blast radius depends entirely
on how central the call site is — here it was the reincarnation flow's
`death_stage()`, hit on **every single player death**, right after the
death-realm dialogue finished, silently stranding the player forever
(crash caught, nothing shown on screen).

Detection: grep hardcoded room-path `#define`s in `include/login.h` (or
wherever a lib keeps its start/death/revive-room constants) and spot
check each one resolves to a real, LIVE-map file — not just any file
with a plausible name. A `*_bak`/backup directory sitting next to a
same-named live directory with genuinely different content (compare file
listings, not just directory names) is the tell that the live directory
was a full replacement, not an addition.

Fix: repoint the stale constant at an always-loadable fallback already
used elsewhere in the same flow for the same purpose (here, `START_ROOM`
— the same fallback `enter_world()` already falls back to for a broken/
missing custom startroom) rather than resurrecting the disconnected old
zone, which would reconnect deliberately-superseded content back into
the live map.

**Confirmed lineage instance: `fy2`/`fy2qh`** (byte-identical siblings,
风云 family). A zone rename from `/d/wiz/` to `/d/waterfog/` left FOUR
stale references behind: `d/waterfog/hall1.lpc`/`jobroom.lpc` (both
still carry `// Room: /d/wiz/....c` header comments — the tell) and
their two message boards `obj/board/wizard_b.lpc`/`wizard_j.lpc`
hardcoded absolute exits/`"location"` values under the old path, even
though the zone's own `d/waterfog/entrance.lpc` already correctly uses
`__DIR__`-relative exits for the same neighbors. A fourth, more
consequential instance of the same stale path lived outside the zone
itself: `feature/alias.lpc`'s anti-bot "you look like a script"
auto-teleport (a genuinely reachable safety mechanism, not dead code)
sent the accused player to `load_object("/d/wiz/courthouse")` — also
nonexistent — which would have silently `move()`d the player into
environment 0 (§7.14) had it ever fired. Fixed all four to point at
`/d/waterfog/...`/`__DIR__`, plus an `objectp()` guard on the
`alias.lpc` teleport as defense in depth. One of the two stale boards
also fed the §7.7 `capitalize(query("id"))` collateral-crash shape via
an unguarded `move()` in the board's own `setup()` — see the third
`fy2`/`fy2qh` instance recorded under §7.7.

### 7.19 Calling a create()-only driver primitive from `init()` re-triggers that object's own `init()` — first-visit-only "Too deep recursion"

Found on `wuhanzhan`'s deep functional test (§10.7). Same first-visit-
only symptom shape as §7.17 (a room's very first compile crashes with
"Too deep recursion", caught, corrupting NPC state into a stray `0` in
the title) but a **different, more general root cause** — not a
room-`reset()` double-fire, not a hardcoded self-locate path. This one
is driver-API misuse and can recur independent of lineage, in any lib.

`enable_commands()` (and any lib's `enable_player()`-style wrapper
around it) is documented (driver source tree,
`docs/efun/interactive/enable_commands.md`, BUGS section) as safe to
call ONLY from `create()` — calling it again on an object that's already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect of registering command hooks on its environment/siblings/
inventory. If an NPC's own `init()` → `setup()` chain calls
`enable_player()` again (redundantly, on an object that already went
through it once during a normal `create()`), the driver's re-invocation
of `init()` happens while the ORIGINAL `init()` call is still on the
stack — genuinely reentrant, not merely called-again-later — and
repeats until the call-depth limit aborts it.

Detection: grep call sites of `enable_commands(`/`enable_player(` (or
whatever a lib's own wrapper is named) and check whether any of them are
reachable from `init()`, directly or via a chain like `init() →
setup() → enable_player()`. Root-cause it the way this instance was
found (§10.3-style `efun::write()` instrumentation) if the crash's
blamed file:line moves around between runs — that's the same reentrancy
tell as §7.17.

Fix: guard the wrapper function itself (the shared choke point, cheaper
than chasing every call site) — `if (living(this_object())) return;` at
the top. `living()` reliably reflects whether `enable_commands()` has
already run for this object, so the guard is inert for every legitimate
call site (the real `create()` call, or a call after a genuine
`disable_commands()`) and only blocks the pathological repeat-call.

**Correction found on `mhxy`'s deep functional test: the
`living(this_object())` guard above is NOT always safe — verify before
applying it verbatim.** Some libs deliberately call `enable_commands()`
again from their OWN `disable_player()`-style function specifically to
keep the object `living()` while "disabled" (their own comment on
`mhxy`: "so this object would be marked living again") — sleep/wakeup,
unconscious/revive, and disguise-item flows all legitimately re-enter
`enable_player()` while `living()` is already true. A `living()`-gated
guard silently no-ops every one of those real re-enables too (skipping
whatever cleanup the real call was supposed to do — on `mhxy` this would
have left a woken/revived player permanently unable to act), while still
blocking the one pathological case it was meant to catch. Before using
`living()` as the guard condition, grep the lib's own
`disable_*`/`sleep`/`wake`/revive code for a legitimate re-`enable_`
call while already `living()`; if one exists, use a true reentrancy flag
instead (`nosave int in_enable_player_now;`, set at entry, cleared at
every return) — it only blocks same-call-stack reentrancy and has none
of the collateral damage. `xiyouji`, the lib this section was originally
written from, happens not to have that legitimate-reenable shape, which
is why the simpler `living()` form worked there — don't assume it
transfers.

### 7.20 Net-dead void-parking without a location-restore path strands players silently on disconnect

Found on `shzs`'s deep functional test (§10.7). **Zero signal
in `debug.log`** — no crash, no error, no warning — the single hardest
bug class in this catalog to detect, since every other bug here at least
leaves SOME trace. Only reproducible by deliberately disconnecting
uncleanly (not sending `quit`) mid-session and reconnecting, both
promptly (inside the net-dead timeout) and after letting the timeout
elapse, then checking the actual room/`startroom` save field — a step no
prior verification layer in this project has ever performed, since every
earlier pass either sent a clean `quit` or didn't reconnect at all.

**Symptom**: a player who disconnects without a clean `quit` (a network
drop or client crash — the single most common real-world disconnect
mode, far more common than a deliberate `quit`) can end up permanently
starting every future session in a bare "void" holding room with no
exits.

**Root cause, two independent flavors — check for both**:
1. The driver's `net_dead()` handler (typically in `obj/user.lpc`) parks
   a disconnected player in a temporary "void" room (`VOID_OB` or
   equivalent) while awaiting reconnect, remembering the real room in a
   `temp`/`nosave` variable. If the player never reconnects before the
   net-dead timeout, a force-quit runs (via `user_dump()`) **while the
   object is still sitting in the void** — if the quit command's
   save-current-location-as-`startroom` logic doesn't special-case the
   void room, it persists the void itself as the permanent respawn
   point.
2. Separately, some libs define a proper `reconnect()` apply on the
   player object whose whole job is restoring the pre-disconnect room
   from that remembered temp variable — but nothing ever calls it; the
   login daemon re-links the connection through a *different*,
   same-named function that only handles network-level reattachment and
   never restores location. `grep -rn "->reconnect(" <mudlib>/`
   returning zero hits is the tell. This means even a PROMPT reconnect,
   well inside the net-dead window, still leaves the player stuck in the
   void.

**Fix pattern**:
1. In the quit/force-quit command, special-case the void room
   specifically — recover the real location from the net-dead handler's
   own remembered temp variable instead of blindly persisting
   `base_name(environment(me))`.
2. In whichever reconnect function is actually invoked by the login
   flow (not necessarily the one named `reconnect()` — verify which
   function the login daemon actually calls), restore that same
   temp-remembered location if the player is currently sitting in the
   void, before or immediately after re-linking the connection.

**Lineages likely affected**: any FF/ES2-derived codebase sharing this
`net_dead()`/`VOID_OB`/`user_dump()` pattern — check `obj/user.lpc` and
the quit/logout command on sibling libs in the same lineage family for
the same shape.

### 7.21 Reconnecting mid a mandatory pre-gameplay wizard permanently strands a player

Found on `rzrmud`'s deep functional test (§10.7). General shape: any lib
with a mandatory first-time `input_to()`-driven setup wizard (character
creation, starting-gift allocation, etc.) run from a room whose `init()`
gates every other command behind a catch-all blocker is vulnerable if a
player net-deads mid-wizard and `reconnect()` doesn't specifically detect
and resume that state.

Root cause: `input_to()` doesn't survive `net_dead()`/reconnect on this
driver — the pending prompt is simply gone. Nothing else re-triggers the
wizard: the routing that sends a brand-new player into the wizard room
only runs from a genuinely fresh login (`enter_world()`), which a plain
`reconnect()` path never calls, and the room's own `init()` (which
normally auto-starts the wizard) only fires on the original `move()`
into the room, not on reconnect. But the room's `add_action` catch-all
blocker (rejecting every command except a documented few) DOES survive
reconnect, since it's bound to the still-alive player object, not the
lost `input_to()`. Net effect: every command the player types is
silently swallowed with no indication of what happened, and the account
is permanently stuck unless they already happen to know whatever
undocumented resume command exists.

Detection: net-dead (don't `quit`) mid a first-time setup wizard,
reconnect, and try ordinary commands — if they're all silently rejected,
this bug is present. Check the wizard room's `init()` for what it calls
to originally start the flow (grep for its own name from a
`call_out`/direct call) — that's what `reconnect()` needs to detect and
re-invoke.

Fix: in the player object's `reconnect()`, check whether the player is
still sitting in the wizard room with the wizard's own "not yet
complete" flag still set (e.g. a `no_gift`-style marker), and if so,
call the room's resume entry point directly — the same one its `init()`
would have called on a fresh `move()` in.

### 7.22 An uncatchable eval-cost abort during a room's cold first compile can leave a fresh login with no environment at all

Found on `rzrmud`'s deep functional test (§10.7). A login-path variant
of the §7.17 "first-visit-only" theme, but hitting `START_ROOM`
specifically — every single fresh connection is exposed, not just
players who wander into one particular zone.

Root cause: the driver's eval-cost abort (`*Can't catch eval cost too
big error`) is genuinely **uncatchable** — a `catch()` wrapped around the
call does not stop it. If a room's cold FIRST-EVER compile this boot
cascades into expensive `create()`-time work (here: an NPC's own
`restore()`) that blows the eval-cost limit, the abort unwinds past any
`catch()` and aborts the ENTIRE enclosing function immediately at the
point of failure — including `enter_world()`'s own pre-existing
`!environment(user)` safety net a few lines further down, which never
gets a chance to run. Result: a player finishes login with no
environment at all — `look` degrades (gracefully, if written
defensively) but any code assuming `environment(me)` is always an object
(e.g. `quit.lpc` passing it straight to `message()`'s 3rd argument) can
itself crash on top of the original problem.

Detection: hard to catch outside a genuinely cold boot (the crash is a
one-shot "first compile only" event, same timing sensitivity as §7.17)
— watch for `*Can't catch eval cost too big error` in `debug.log` during
`enter_world()`'s call chain specifically, and check every later
function in the login path for an assumption that `environment(user)` is
always non-null.

Fix: since the crash aborts the CURRENT function/call stack but not the
whole process, schedule an independent recovery pass via
`call_out(..., 0, ...)` **before** the risky room-entry calls — a
`call_out`-triggered invocation gets its own fresh eval-cost budget,
independent of whether the function that scheduled it later aborts
partway through. The recovery function checks `!environment(user)` and,
if true, moves the player to a safe fallback room (this driver's own
`START_ROOM`-if-custom-startroom-broken fallback is a fine reuse). Also
audit downstream code (like `quit.lpc` above) for the null-environment
assumption independently — the recovery pass narrows the window but
doesn't make every other function environment-null-safe by itself.

**Same symptom, different trigger — a compile ERROR instead of an
eval-cost abort**: found on `chidi`'s deep functional test. A hard
compile error anywhere in `START_ROOM`'s (or any zone room's) own
first-ever compile this boot — e.g. an NPC in that room calling
`exert_function(<int>)` when the real signature is
`exert_function(string func)`, a plain copy-paste type mismatch —
aborts the room's compile entirely, which aborts whatever caller
triggered it (a `move()`/`load_object()` during login) the same way the
eval-cost abort does, landing the player with no environment and the
same "灰蒙蒙一片"/can't-move symptom. Same detection/fix shape applies:
grep `debug.log`'s compile-error output for anything in the
zone-room-and-its-NPCs dependency chain of any room a fresh login can
reach, not just runtime errors. **Grep pitfall (caught on `zxty`,
2026-08-05): `exert_function([0-9])` — a single-digit character
class — silently misses `exert_function(10)` and any other multi-digit
argument.** Two prior deep-tests (`tybxjh`, `xhcii`) used exactly this
pattern; `tybxjh` had already found its 4 instances by other means
(sibling-check, a live compile error) so nothing was missed there, but
the grep itself would have reported a false "clean" on any lib whose
only instances happened to be double-digit. Use
`exert_function([0-9]+)` (or just `exert_function([0-9]` with no
anchor) when checking a new lib for this pattern. Not worth a separate
numbered class — the uncatchable-crash-during-cold-first-compile shape
is the same
regardless of whether the crash is an eval-cost abort or a compile
error; treat both as instances of this section.

### 7.23 A missing `return` after a retry-reschedule lets a self-rescheduling `call_out` chain double-schedule itself, eventually segfaulting the driver

Found on `xkx2001`'s deep functional test (§10.7). **The most severe bug
class found by this project's round-two testing pass so far.** Distinct
from every other §7.16–§7.22 entry: those are all caught LPC runtime
errors (aborted functions, "Too deep recursion", eval-cost aborts) that
the driver's own error handler swallows harmlessly. This one is a
genuine **process segfault** — it kills the driver outright, disconnects
every player, and requires a restart.

Root cause: an NPC "patrol"/"escort"-style function that reschedules its
own `call_out` on every invocation (`call_out("move_next", N, self,
...)`) had a conditional early-exit branch (here: "the guest wandered
off, retry in 10s") that scheduled a RETRY `call_out` but forgot a
`return` afterward — so execution fell through into the function's own
unconditional tail, which scheduled a SECOND, different `call_out` on
the same object in the same invocation. Each time the conditional branch
fires, one more untracked duplicate accumulates (the paired
`remove_call_out()` calls only clear one pending registration, not all
of them). If the object is later `destruct()`ed — e.g. an ordinary
"gave up, NPC leaves" cleanup path, which every such NPC has — while a
duplicate `call_out` is still pending, the driver's C++ call_out
bookkeeping ends up holding a scheduled callback against a freed
`object_t*`. Dereferencing it (observed at
`src/packages/core/call_out.cc:209`, `while (ob->shadowing) ...`)
segfaults the whole process the next time that duplicate fires — not
just the one LPC call.

Detection: grep any file with a self-rescheduling `call_out` chain (a
function that both handles `call_out`-triggered dispatch AND calls
`call_out()` on itself again) for more than one `call_out(<same name>,
...)` call site reachable from a single invocation — especially inside
an `if`-branch lacking a `return` immediately after its own
reschedule. Easy to miss by inspection: each individual reschedule call
looks completely reasonable in isolation; the bug is the *combination*
being reachable in one invocation. Confirming it live requires
deliberately keeping the branch's trigger condition true across multiple
real `call_out` cycles (here: a player becoming separated from an
escorting NPC, repeatedly, over several real minutes) and watching
whether the **process itself** is still alive, not just `debug.log` — a
short scripted test session never lingers long enough to accumulate
enough duplicates to hit this.

Fix: add the missing `return` (or otherwise restructure so only one
`call_out(<name>, ...)` registration is ever reachable per invocation).
Worth pairing with a `catch()` around any single risky step inside the
same function (a scripted movement `command()`, a `call_other`, etc.) —
found alongside this bug: an unrelated uncaught error earlier in the
same function could abort it before the (now-fixed) single reschedule
ever ran, silently orphaning the object with zero pending `call_out`s at
all. Milder than the segfault but the same underlying lesson — a
self-rescheduling `call_out` chain needs EXACTLY one registration
guaranteed per invocation, on every exit path, including error paths.

Lineages likely affected: any lib with a copy-pasted "guide escorts a
new player through scripted rooms" NPC pattern —
`bmxkx2001` (documented sibling of `xkx2001`) carries a
byte-identical, unfixed copy of the vulnerable file; check any other lib
sharing this ES2 island-onboarding lineage for the same shape.

### 7.24 Death/reincarnation code silently overwrites the permanent login-location field

Found on `zzfy`'s deep functional test (§10.7). A lib's death-handling
NPC (temporarily relocating a dying/reincarnating player through a
limbo/antechamber room before they resume play) can, via a copy-pasted
or careless `ob->set("startroom", base_name(environment(ob)))`,
permanently hijack the SAME field the login daemon's `enter_world()`
reads on every FUTURE full login — turning a transient flavor placement
into a permanent, unannounced relocation. On `zzfy` this meant a
player's FIRST death silently and permanently moved every future login
away from wherever they'd actually chosen to live, 50% of the time to
an isolated, hard-to-escape zone with no easy way back — with zero
player-facing explanation, since the crash-free "you have died and been
reincarnated" flow gives no hint that anything about future logins just
changed.

Detection: grep death/reincarnation NPC files for `set("startroom"` or
`set("start_room"`, and check whether the room(s) it moves the player
through carry whatever "may this room be a permanent home" flag the
lib's own `save`-equivalent command already gates the SAME field on
(commonly `valid_startroom`) — if the death code writes to that field
without checking that flag, it's this bug.

Fix: don't touch the login-location field from death/limbo code at all
— leave the player's real, previously-chosen (properly-flagged) login
location intact; the `move()` that's already placing them in the
death/limbo room handles the immediate post-death placement without
needing to also rewrite where future logins land.

### 7.25 A room-population helper's unguarded `new()`/`move()` chain crashes a room's first-ever visit when a listed NPC/object is missing or fails to compile

Found on `zzfy`'s deep functional test (§10.7). Distinct from §7.17
(reentrancy) and from a plain missing-content gap (§13) — this is about
the SHARED helper function every room's `reset()` calls to populate its
`"objects"` mapping (typically `std/room.lpc`'s `make_inventory()`)
having no guard at all around the `new(file)` → `ob->move(...)` chain.
`new()` legitimately returns `0` for a file that doesn't exist (a stale
wizard-workspace reference, a renamed/deleted content file — an ordinary
archive gap), but for a file that EXISTS and fails to COMPILE (e.g. an
`inherit`ed feature macro that's referenced by several NPC files but has
no matching `#define`/feature file anywhere in the archive — itself a
different, also-legitimate content gap) `new()` instead **throws**
(`*No program in object ...!`) — a bare post-hoc `objectp()` check on
the result can't catch that, since the throw happens inside `new()`
itself, before any assignment. Either failure mode crashes the
UNCONDITIONAL `ob->move()`/`ob->set()` calls that follow, which — same
timing shape as §7.17/§7.19/§7.22 — only ever bites a room's first-ever
population this boot; once whatever DID load is in memory, later resets
just skip the bad entry silently (if a later guard exists) or keep
re-throwing quietly forever (if it doesn't), so this is easy to miss in
short smoke testing.

A closely related shape hits the same "first-ever visit only" crash via
a completely different call: rooms that force-load a companion object
(commonly a message board) via `call_other("<path>", "???")` in their
own `create()`, when that companion object doesn't exist in this
archive — same fix (`catch()` around the call), same detection method.

Detection: read the shared room base class's `make_inventory()` (or
equivalent) and check whether the `new()`/`move()`/`set()` sequence is
guarded; separately grep individual room files for unguarded
`call_other("<path>", "???")` force-loads of a fixed companion-object
path. Reproduce live by walking a fresh character into a room whose
`"objects"` mapping (or force-loaded companion) references broken/
missing content — the crash is caught by the driver, so nothing looks
wrong on screen unless you check `debug.log`.

Fix: wrap the base class's population helper in `catch()` and return
`0`/skip on either failure mode (missing file OR compile failure), and
add an `objectp()` check at every call site that assumes the helper
always returns a real object before calling further methods on the
result. For a force-loaded companion object, just `catch()` the
`call_other()` itself. Do NOT fabricate the missing content (a
referenced-but-undefined feature macro, a deleted board object) to make
the compile succeed — that's a real archive gap (§13), not a conversion
bug; only make the crash degrade gracefully.

### 7.26 A `file_owner()` path-depth off-by-one misattributes nested wizard content, crashing `log_error()`'s write on any compile diagnostic

Found on `mhxy`'s deep functional test (§10.7). Related to §7.10 (both
are `log_error()`-adjacent traps) but a distinct mechanism — §7.10 is
about the ACL/broadcast side of `log_error()`; this is about a helper
`file_owner()` (used by `log_error()` to pick which wizard's log
directory to write compile diagnostics into) misidentifying the wizard
entirely for the overwhelmingly common case of nested content.

Root cause: `file_owner(string file)` did
`sscanf(file, "/u/%s/%s/%s", dir, name, rest) == 3` and returned `name`
— the SECOND captured segment, despite the misleadingly-ordered
`dir`/`name`/`rest` variable names. This only returns the correct wizard
uid when the file is exactly 2 levels under `/u/<wizard>/<file>`; for
the far more common 3-level-or-deeper shape
(`/u/<wizard>/<subdir>/<file>` — `npc/`, `obj/`, `room/` subdirectories,
which is how virtually all real wizard-built content is organized) it
returns the SUBDIRECTORY name instead of the wizard. `log_error()` then
writes to `user_path()` of that bogus "owner" (e.g. `/u/npc/`), a
directory that never exists, aborting with `*Wrong permissions for
opening file .../<subdir>/log for append. "No such file or directory"`.
Because this fires from ANY compile diagnostic (warning or error) on
ANY file under `/u/`, and the whole point of `log_error()` is to run
whenever the driver has something to report, this can crash the
compile chain of literally any room containing a not-yet-compiled `/u/`
file with so much as a compiler warning — including, on `mhxy`, the
START ROOM's own NPC roster, so it hit every single fresh login.

Detection: grep for a `file_owner`/`creator_file`-shaped function in
the lib's simul_efun sources feeding `log_error()`, and check whether it
captures a FIXED-DEPTH segment (breaks for any other nesting depth) or
the FIRST segment after `/u/` unconditionally (correct regardless of
depth). Compare against how the same file typically handles `/d/`,
`/open/`, `/ftp/` ownership — if those already use a "first segment
only" pattern (commonly `path[1]` after `explode(file, "/")`) and the
`/u/` branch doesn't match that discipline, that inconsistency is the
tell.

Fix: capture only the first segment after `/u/`
(`sscanf(file, "/u/%s/%s", name, rest) == 2`), matching whatever
first-segment discipline the rest of the function already uses for
other root directories.

Lineages likely affected: `mhxyqd`, `xyj2000f`,
`xiyouji2003`, `xiyouji2006` (confirmed via grep to carry identical
code, not yet fixed there — out of scope for the pass that found this).

### 7.27 (RETRACTED — false positive, see §10.7's scope note) A time-gated transit room deleting its exit on window-close

Originally found on `xyxy2`'s deep functional test (§10.7)
and initially "fixed" by restoring the deleted exit — **reconsidered and
reverted on user review**: this is a real-time-gated raft mechanic
(`room->delete("exits/out")` when a ~20s boarding window closes) whose
flavor text ("一个浪头打来，木筏向海上漂去" — a wave hits, the raft
drifts out to sea) plausibly describes an INTENTIONAL "you missed the
boat and are now stranded" consequence, not an oversight. Recoverable by
disconnecting (the room never sets `valid_startroom`, so no permanent
account-level harm), which is a real but plausibly-deliberate design
choice for this kind of timing mechanic.

**Kept as a cautionary case study, not a bug-class to fix on sight**:
this is exactly the shape of finding §10.7's scope note warns about — a
mechanic that looks like a bug (a session-long soft-lock with no in-game
recovery) but is at least as plausibly an intentional, if harsh, design
choice. Deleting a room's exit as a timed-consequence mechanic is not
inherently a programming defect the way a missing `objectp()` check or
a wrong efun argument type is. If you find this shape again: document it
in the lib's NOTES.md as an observation, do NOT restore the exit
yourself — this is a content/design judgment call, not a program to
debug.

### 7.28 Redundant `enable_player()`/`enable_commands()` calls stack duplicate `add_action` sentences, silently re-running FAILED commands' side effects

Found on `dtsl`'s deep functional test (§10.7). Related in root cause to
§7.19 (uncritical repeated `enable_commands()`/`enable_player()` calls)
but a completely different, non-crashing symptom — worth checking for
independently even on a lib that's already been fixed for §7.19's
reentrancy shape, since the two failure modes are orthogonal.

Root cause: `enable_player()` (or equivalent) registers the central
command dispatcher via `add_action("command_hook", "", 1)` with no
idempotency guard, and ordinary, unremarkable code paths call it more
than once per session by design — a login daemon's `enter_world()`
calling it directly and then again via `setup()`, or a `sleep`/wakeup
cycle calling it multiple times per cycle. `enable_commands()` itself is
idempotent at the driver level (harmless to call repeatedly), but a bare
`add_action()` is NOT — each redundant call stacks another duplicate
wildcard sentence for the same verb dispatcher. This is invisible for
any command whose handler SUCCEEDS (the driver stops at the first
sentence in a stack that returns nonzero), but every FAILING command
(the common case — wrong target, insufficient funds/skill/mana, a typo)
gets silently RE-RUN once per extra stacked sentence, including any side
effects that already fired before the failure return (observed: a
failed skill-purchase attempt double-charged and double-printed its
tuition message).

Detection: count how many distinct code paths in a session can call the
central `enable_player()`/`enable_commands()` wrapper (grep its own name
across the lib — login flow, `setup()`, sleep/wake, revive, disguise
items are the common repeat offenders), and check whether a command that
deliberately fails (wrong syntax, insufficient resources) produces its
failure-path side effects/output more than once after any of those
repeat-triggering events has occurred in the same session.

Fix, and a caution about a tempting-but-wrong alternative: the temptation
is a `living(this_object())`-gated guard (mirroring §7.19's pattern) —
but `living()` can already be true across a LEGITIMATE re-enable (a
`disable_player()`-style function that calls `disable_commands()`
immediately followed by a bare `enable_commands()`, specifically to keep
the object marked living while "disabled"), which would make a
`living()`-gated guard skip the one call that was actually supposed to
register a working sentence — a straight regression (breaks every
command after any disable/re-enable cycle). The correct, call-order/
call-count-independent fix is `remove_action("command_hook", "")`
immediately before the `add_action()` call, inside `enable_player()`
itself — guarantees exactly one sentence is ever registered no matter
how many times or in what order the function is called.

### 7.29 Restoring a missing simul_efun as a passthrough to a same-named real efun can be semantically wrong even though it compiles and boots clean

Found on `tianxia`'s deep functional test (§10.7) — a correction to an
EARLIER pass's own fix, not a fresh conversion bug. A generic per-object
"slash-path" property-storage convention (`query("a/b")` meaning
"descend into nested submapping `a`, read key `b`") called a bare,
never-defined `changed_match_path(mapping, string)`. An earlier pass
restored it as a thin passthrough to FluffOS's real `match_path()` efun,
reasoning from name+signature match alone (`changed_match_path` vs.
`match_path`, same argument shape) — a defensible-looking guess that
turned out wrong: the real efun implements ACL-style
longest-matching-**prefix** lookup over a **flat** mapping (keys are
literal strings, some ending in `/` as a wildcard), not recursive
descent into nested submappings one `/`-segment at a time. Every caller
in this lib's `feature/dbase.lpc` (`set()`/`query()`/`query_temp()`)
clearly assumed the latter — `set()`'s own code sits right next to each
call, doing `cont = changed_match_path(dbase, prop[0..r-1]); if
(mapp(cont)) return cont[prop[r+1..]] = data;`, i.e. expecting the
function to return the actual nested submapping so it can be indexed by
the trailing segment.

This passed every prior verification layer — compiles, boots, single-key
`query()` calls and `score` all work — because the real efun's ACL
algorithm degenerates to a correct plain-key lookup whenever the path
string contains no `/`, which is the common case for simple properties.
Only 2+-level property paths are affected, and they fail **silently**
(return `0`/unset, no error, nothing in `debug.log`) — invisible to any
boot-log sweep or registration smoke test. On `tianxia` this broke every
bare directional movement command lib-wide (`feature/command.lpc`'s
exits-detection uses `query("exits/"+verb)`), while `go <dir>` kept
working (a different code path that never touches this function) — plus
every 2+-level `query()` for quest flags, chat-flood gates, and the
auto-look brief-mode toggle.

Detection: before restoring ANY never-defined function purely by
name/signature match to a real efun (a pattern this project uses
deliberately elsewhere — see §5/§6's function-restoration guidance), check
every call site's actual USAGE pattern against that efun's real,
documented algorithm, not just its argument types. A caller's own
neighboring code (here, `set()`'s explicit path-splitting logic sitting
right next to the call) can directly reveal the intended semantics don't
match. If a lib has this shape (a same-named/same-signatured missing
simul_efun that got "fixed" by passthrough purely on name grounds),
re-derive the semantics from the callers instead of trusting the
name match.

Fix: implement the semantics the callers actually need (here: recursive
descent through nested submappings, one `/`-segment per level, returning
the final leaf value or `0`/unset if any level isn't a mapping) rather
than delegating to the closest-matching real efun.

**Second confirmed instance, no restored-passthrough involved:
`dfgsiiv13b`** (§10.7) — same `feature/dbase.lpc` `set()`/`query()`/
`query_temp()` shape, but here `match_path()` was never missing; the
lib just calls the real efun directly on the full `"a/b"` path, with
the exact same wrong nested-descent assumption. Root-caused via `call
here->query("exits/east")` returning `0` while `call
here->query("exits")` correctly returned the real nested mapping — a
crisp, reproducible isolation of the ACL-prefix-match-vs-recursive-
descent gap. Impact was total: every `go <dir>` failed ("這個方向沒有
出路" on a real, listed exit), `apprentice`'s two-step accept flow
(`query_temp("pending/alchemist")`) always read `0` even right after
the matching `set_temp()`, and `score`'s class-title lookup silently
lost data the same way. `dfgsiiv13b` is this session's best candidate
for the literal ES II engine root (`xkxz2`/`xiyouji`/`kxkj`/`rzrmud`/
etc. group in §11's lineage map) — since this exact `feature/dbase.lpc`
shape is what many of those forked from, grep any ES II-lineage
sibling's `feature/dbase.lpc` for a bare `match_path(dbase, prop)` (no
truncate-and-descend loop matching `set()`'s own) before assuming its
`query()` works just because its `set()`/single-key `query()` do. Same
fix as above, applied to both `query()` and `query_temp()`.

### 7.30 A mapping-typed accessor returns its raw never-initialized variable (`int 0`) instead of an empty mapping, crashing any unguarded indexing/`keys()` call

Found on `xiakexing2017`'s deep functional test (§10.7), in two
independent shapes. An accessor declared to return `mapping` (`mapping
query_skills() { return skills; }`) is fine as long as `skills` was
assigned somewhere first — but a `mapping` instance variable that was
never `set()`/assigned defaults to LPC's generic zero value, `int 0`,
not `([])`. For any player/object that never triggered whatever code
path populates the mapping (the most common case: a brand-new
character with no skills learned yet), the accessor faithfully returns
that raw `0`. Any caller that does `keys(query_skills())` or
`query("nested")["key"]` without an `objectp()`/`mapp()` guard first
crashes with `Bad argument 1 to keys()` or `Value being indexed is
zero` — reproduced live via an NPC greeting hook reachable by ordinary
non-faction players and a brand-new character trying to use a shared
skill-list accessor.

The second shape is the same underlying trap one level removed: code
that stores structured data as a nested submapping under a generic
per-object property store (`ob->query("party")["party_name"]`,
`ob->query("family")["family_name"]`) crashes identically for any
object that never had that top-level key set at all — `query("party")`
legitimately returns `0` for a player who never joined a faction, and
indexing `0` with a string key is exactly the same crash.

Detection: grep declared-`mapping`-returning accessors for a bare
`return <instance var>;` with no `mapp()`/ternary guard, and grep for
`->query("<key>")[` / `->query("<key>")["..."]`-shaped indexing chains
with no `mapp()`/`objectp()` check immediately before them. Reproduce
live by exercising the affected code path with a player who genuinely
lacks the expected state (a brand-new character with no skills, a
character in no faction) — this is exactly the class of state a smoke
test using an established/admin character never exercises.

Fix: at the accessor, return `mapp(x) ? x : ([])` instead of the raw
variable. At an inline `query(...)["key"]` chain, capture the query
result into a local first and guard with `mapp()` before indexing —
don't index the `query()` call's return value directly.

### 7.31 `enter_world()` overwrites the just-restored persistent player object's flag with the fresh per-connection object's stale/default value

Found on `xkxz2`'s deep functional test (§10.7). On login, two
distinct objects exist briefly: the persistent player body (`user`,
restored from the player's save file, carrying their real accumulated
state) and a brand-new per-connection login/network object (`ob`,
created fresh for this one connection attempt, whose own properties are
either never set or explicitly zeroed during the new-character-creation
path). `enter_world()` did `user->set("registered",
ob->query("registered"))` — copying `ob`'s always-stale-or-zero value
onto `user`, unconditionally overwriting whatever the player's own save
data had correctly restored. Net effect: a boolean flag that's supposed
to persist forever once set true (`registered`, set permanently by a
one-time registration NPC interaction, `this_player()->set("registered",
1)`) got silently reset to false on EVERY subsequent full login,
re-triggering the entire registration flow and rerouting an established
player back to the newbie register room instead of their real
`startroom`.

Detection: any `enter_world()`/login-flow code doing
`user->set(<flag>, ob->query(<flag>))` (or the reverse) — for a
supposedly-persistent flag, this is backwards unless `ob` is genuinely
the current source of truth for that specific property. Check where the
flag is actually SET elsewhere in the lib (grep for
`set("<flag_name>"` broadly) — if it's set on the persistent player body
by unrelated gameplay code (an NPC interaction, a quest completion), not
freshly derived from the connection object every login, blindly copying
from `ob` will stomp it.

Fix: treat the flag as monotonic where that's the correct semantics —
true on either object wins (`if (ob->query(f) || user->query(f)) {
ob->set(f, 1); user->set(f, 1); } else user->set(f, 0);`) — or, more
simply, just stop writing to `user` from `ob` for any property that's
supposed to already be correctly restored on `user` from its own save
data.

### 7.32 A dangling/missing `else` in a sequential `if`-chain silently rejects every case but the last

Found on `xkxz2`'s deep functional test (§10.7). A classic
control-flow defect, not lib-architecture-specific, but worth cataloging
since it produced a severe, silent, near-total feature failure: a
multi-destination dispatcher (a paid travel-guide NPC's `do_go()`)
checked each valid destination with an INDEPENDENT `if (target ==
"X") me->set_temp("go_x", 1);` — no `else` chaining between them — and
ended with a single `if (target == "<last option>") ...; else return
notify_fail(...)`. Because C-family `else` binds only to its immediately
preceding `if`, that trailing `else` fires for EVERY target that isn't
the LAST option checked — even after an EARLIER `if` in the same chain
already matched and correctly set that destination's flag. Result: only
the last-checked destination ever actually worked; every other valid,
correctly-recognized destination string got its flag set and then was
immediately rejected with a generic "never been there" failure message,
because the function still fell through to the final unconditional
`if/else` before ever reaching the success path (`call_out("do_goto",
0, me); return 1;`) at the bottom.

Detection: read the FULL body of any multi-branch dispatcher built from
sequential `if`s ending in a single trailing `else` — don't assume the
`else` covers "none of the above" for the whole chain just because
that's the common intent; check whether it's actually only attached to
the last `if`. Reproduce live by trying every documented option, not
just the first or last one a smoke test happens to pick.

Fix: convert the sequential `if`s into a proper `if`/`else if`/…/`else`
chain so the trailing `else` genuinely covers "none of the preceding
conditions matched," not just "didn't match the last one."

---

### 7.33 Persisting a state change BEFORE validating that the underlying action actually succeeded

Found on `zhongjidiyu`'s deep functional test (§10.7), in a `born`
(character-origin-selection) handler: the code resolved a destination
room via `load_object(dest)`, then IMMEDIATELY did `me->set("startroom",
dest); me->set("born", arg); ...` — persisting the choice as fact —
and only checked `if (!objectp(obj)) { ... return 1; }` AFTER all of
that, at the very end of the function. On this particular archive every
`born` destination's target zone was missing from the conversion, so
every `born` attempt failed the objectp() check — but by then the
broken path had already been written to the player's permanent
`startroom` field. The visible failure message ("牛头一呆...") looked
like a no-op, but the account was actually left silently, permanently
stranded: the next login's `enter_world()` would try to load that
broken path and (absent the §7.14/§7.22-class fallback logic covering
THIS specific failure mode) throw with the player left with no
environment at all.

This is a distinct mechanism from §7.24 (which is about code that
overwrites `startroom` unconditionally, with no failure path at all) —
here the code DOES check for failure, just in the wrong order relative
to the writes. The general shape — "commit a multi-field state change
optimistically, validate afterward, and only skip a FINAL step on
failure" — is a plausible pattern anywhere a handler builds up several
`set()` calls before its own validation gate.

Detection: for any handler that both (a) calls `set()` on a
persistent/permanent field and (b) has ANY failure/rejection path,
check whether every `set()` happens strictly after the corresponding
validation, not before it. Grep the surrounding function for `set(` and
compare its line number against the nearest `if (!objectp(...))`-style
guard.

Fix: move the validation check to before the first `set()` call that
depends on it, so a failed action can never leave a persisted field
half-written to a broken value.

---

### 7.34 Leftover developer debug output shipped into a live login/registration prompt sequence

Found repeatedly across this round's deep functional tests: `esI` (five
`tell_object(player, "ttt\n")`/`"ttt1\n"`/etc. checkpoints strung through
`enter_world()`), `xianlvqiyuan` and `cctx` (each a bare
`printf("%O\n", ob)` printing the login object's raw internal path,
e.g. `/obj/login#2`/`/clone/user/login#1`, between the name and
password prompts — `cctx`'s instance found via §10.7 deep functional
test, not just code review), `hc`, `yxjh`, `xkyx3b`, `mnhf`,
`bixiecanyang`, `fy330`, `fy2mg`, `wmkj`, and `jhfy2` (each the SAME `printf("%O\n",
ob)` line duplicated across TWO parallel name-entry code paths —
accept a system-suggested random name vs type your own — both landing
right before the password prompt, both found and fixed together;
`fy330`'s own sibling `fy2` carries the byte-identical line but was
previously left unfixed as "harmless" — worth revisiting that call the
next time `fy2` is touched, now that this round treats the pattern as
a routine, safe-to-fix hit rather than a judgment call), `sanjieshenhua`, `ldtxii`,
`yszz`, `mohuanshiji`, `jyqxc`, `syxjl`, and `gjzddmudda` (each the same
bare `printf("%O\n", ob)`
right before the Chinese-name is set — `ldtxii`'s sibling `ldtx` has
the byte-identical line, unfixed; port the same one-line deletion
there too when next touching that lib), `jyqxc2` (`jyqxc`'s own sibling
— §10.7 deep-dive found the two libs' `work/` trees are byte-identical
apart from `logind.lpc` itself, i.e. `jyqxc2` was carrying `jyqxc`'s
PRE-fix state of this exact file, printf and all; same one-line
deletion), `xiakexing3` and `jqxz2015`
(same ES II lineage, §10.7 deep-dives; `logind.lpc`'s `get_name()`,
bare `printf("%O\n", ob)` right after the Chinese-name prompt — present
on `xiakexing3` and confirmed as a SECOND independent instance on
sibling `jqxz2015` despite `jqxz2015`'s own content-lineage precedent
(`jqxz2008`/`jqxz2008dlx`/`jqxz2008std`) NOT carrying the line at all,
underscoring that even within one shared-engine family, individual
archives can pick up or drop this class of leftover debug scaffolding
independently — worth checking `jqxz2008std`/`jqxz2008dlx`'s own
`get_name()` again the next time either is touched), and
noted-but-left-alone on
`fy2` (a
similar stray `printf` in `logind.lpc`, existing precedent from `zzfy`
treats it as harmless). `ylfyxa3` (XYZX/炎龙封印 branch, §11) carries the
SAME pair — `get_resp()` (accept-random-name path) and `get_name()`
(typed-name path) — each a bare `printf("%O\n", ob)` printing
`/clone/user/login#N`, found via §10.7 deep functional test; both
removed. A leftover diagnostic write/printf with no
explanatory comment, sitting in an otherwise-clean sequence of
player-facing `write()`/prompt calls in a login or registration daemon,
prints raw internal state (an object's driver-assigned path, a
sequence-number checkpoint, etc.) directly into the visible prompt
flow. Confirmed byte-identical in each raw archive — original-author
debug scaffolding never cleaned up before the archive was shipped/
seeded, not a conversion-pipeline artifact.

Detection: grep login/registration daemons (`logind.lpc` and similar)
for `printf("%O` / `write(sprintf("%O"` / bare numbered
`tell_object(...)` checkpoints with no surrounding diagnostic comment,
especially ones sitting between otherwise-legitimate player-facing
prompts.

Fix: delete the line. It never serves a player-facing purpose (if it
did, it would already be phrased as normal game text, not a `%O` dump
or a bare marker string like `"ttt"`). Verify by re-running registration
and confirming the prompt sequence reads cleanly with no stray output.
This is cosmetic/UX-hygiene, not gameplay logic — safe to fix on sight
even under the §10.7 programming-bugs-only scope rule, since it's
leaked implementation detail, not a content or balance choice.

---

### 7.35 An object-vs-string argument type mismatch fails LOUD via a bare call, but SILENT via `->`

Found on `nitan6`'s deep functional test (§10.7): two NPC files called
`is_killing(who)` — passing an `object` — where `feature/attack.lpc`'s
own `is_killing(string id)` declares a `string` parameter. Called as a
BARE (non-`call_other`) function call, this driver's static type
checker rejects the mismatch outright at compile time (`Fail to load
object`) — so the whole NPC file simply never loads, silently absent
from wherever it's supposed to spawn, with a clear (if easy to miss
among other archive-gap noise) compile diagnostic.

The catch: the exact same author mistake reached via `->` (a
call-other) does NOT get this protection — `call other type check` is
commonly disabled on these drivers/configs, so `target->is_killing(me)`
with the same object-for-string mismatch compiles and runs fine,
silently. `nitan6` itself had ~60 such call-other sites across many
independent skill files, all defeating an "already fighting" guard
check (always evaluates false) with no crash at all — traced and
confirmed harmless in that specific case only because the downstream
function happened to be idempotent, not because the pattern is safe in
general.

Detection: when you find one instance of this mismatch via a hard
compile failure (bare call), grep the whole lib for OTHER calls to the
same function via `->` — those are the same bug, just silently
degraded to a logic error instead of a load failure, and won't show up
in an `lpcc` sweep at all.

Fix: pass the argument type the function actually declares (commonly
`query("id", who)` to get the string form of an object, matching
whatever convention the rest of the lib already uses at its other,
correct call sites for the same function). For a wide "silent" spread
across many call-other sites, evaluate case by case whether the
downstream effect is genuinely harmless before mass-fixing — don't
assume; confirm each site's blast radius, or document it as an
observation and leave it for a dedicated follow-up pass if the count is
large (§6b's mega-lib "long-tail" precedent).

---

### 7.36 An idle-room cleanup daemon that checks only `interactive()` can destroy a room a net-dead player is still standing in

Found on `xiaoyuxiyou`'s deep functional test (§10.7): a room-idle
cleanup check (`feature/clean_up.lpc`) used `interactive(inv[i])` alone
to decide "is anyone genuinely here," and `destruct()`ed itself when
that came back false for everyone in its inventory. `interactive()` is
false for a NET-DEAD player — the socket is gone, but the player's body
and save state are still logically present and reconnectable — so a
room holding nothing but a net-dead player looked "empty" to this check
and got destructed out from under them by the driver's own idle sweep,
corrupting `environment()` to 0 for that player. This cascaded: the
corrupted environment then made an UNGUARDED `tell_room(environment(),
...)` inside the net-dead force-quit handler (`user_dump()`) throw,
which — since that throw happened before the actual `QUIT_CMD->main()`
save/quit call in the same function — silently skipped the net-dead
safety net's own save entirely. Found only via a real ~10-minute
net-dead soak wait (the class of test §10.7/§10.8 explicitly encourage
attempting, not simulating).

Detection: grep any idle-room/zone cleanup daemon for occupancy checks
that call `interactive()` without also checking `userp()`. `userp()`
reflects the driver's persistent "this is a player body" flag, which
stays true across a net-dead disconnect (it's what the net-dead
handling code elsewhere in the same lib already relies on) — a
same-lib inconsistency between what the cleanup check tests and what
the net-dead handler assumes is a strong tell. Reproduce live with a
real net-dead wait past whatever the room's own idle-sweep interval is
(often much shorter than `NET_DEAD_TIMEOUT` itself), then check whether
the disconnected character's `environment()` is still sane on
reconnect.

Fix: add `|| userp(inv[i])` (or equivalent) to the occupancy check so a
net-dead-but-still-real player keeps their room alive. As defense in
depth, also guard any `tell_room(environment(), ...)`-style call inside
net-dead/idle force-quit handlers with `objectp()` so a corrupted
environment from some OTHER bug can never itself block the actual
save/quit that same handler exists to guarantee.

---

### 7.37 Calling `ob->efun_name(...)` where `efun_name` matches a real driver efun, but no method of that name is actually defined on `ob`, silently no-ops

Found on `sjcs`'s deep functional test (§10.7): a room's
reconnect-triggered `call_out` tried to automatically resume a stalled
gift-selection wizard via `me->command("start")` — but the real
`command()` efun (`core.spec`: `int command(string)`) takes NO object
argument; it always operates on the current command-giver context.
`ob->command(str)` is call_other syntax, which requires `ob` to define
its OWN function literally named `command`, which nothing in this lib
did anywhere (confirmed via a lib-wide grep). This driver raises NO
error for a call_other to an undefined function — not to the caller,
not to debug.log, nowhere — it just silently returns 0. The result was
a completely silent dead end: a player reconnecting mid-wizard saw
"重新连线完毕。" and then nothing else, forever, with zero indication
anything was wrong, while the SAME verb typed directly by the player
(going through the driver's own normal command dispatch, which doesn't
depend on this broken call) worked perfectly fine — a discrepancy that
made this easy to initially misdiagnose as "the add_action registration
must be broken" when in fact it was fine.

This is a distinct trap from §8.3a (`private`→`DECL_HIDDEN` demotion
breaking a real, DEFINED function's dispatch) — here there was never
any function to dispatch to in the first place; the bug is confusing
"an efun that happens to share this name" with "a method call," a
mistake the compiler cannot catch because call_other targets are
resolved dynamically at runtime, not statically.

Detection: whenever you see `ob-><efun_name>(...)` for any of this
project's common efuns (`command`, `write`, `tell_object`, `message`,
etc. — check the real signature in `core.spec` or the relevant
package's `.spec` file), verify the target object actually defines a
same-named method (grep the whole lib, not just the obvious base
classes) before assuming the call does what its name suggests.
Reproduce live by exercising the actual caller path (here: reconnect
while mid-wizard, not just fresh registration) and watching for
complete silence with no debug.log trace — that combination (call
succeeds with no error, but visibly does nothing) is the tell.

Fix: replace the broken round-trip with a direct call to the underlying
logic using the already-available explicit target object, being
careful that anything relying on implicit `this_player()` context
(`write()`, and similarly `tell_object`-adjacent, ambient-target efuns)
gets rewritten to take the explicit target instead — `write()` and
friends silently target `this_player()`, which is typically unset
inside a `call_out`, so simply removing the broken `ob->command(...)`
call without ALSO auditing what it was trying to reach just moves the
silent-failure point one level deeper.

### 7.38 `destruct()` cannot be overridden as a simul_efun on this driver

`error: Invalid simulated efunction override` — some libs' `adm/simul_efun/
object.lpc` defines its own `void destruct(object ob)` (pre-cleanup like
`ob->remove(euid)` before calling `efun::destruct(ob)`) as a simul_efun
wrapper. This driver hard-rejects overriding `destruct` specifically, unlike
`set`/`query`/`message`/etc. Minimal fix: delete the override; every bare
`destruct(...)` call site now hits the real efun directly. The pre-cleanup
step is lost — if that cleanup was load-bearing (e.g. an inventory-tracking
invariant), audit callers rather than assuming this is free. (Whole `haiyang`
family — `hy2002`/`hy2000`/`hyiishzdscbb` — and `xkx100`, all independently.)

### 7.39 Mudlib's own `#define MUD_NAME` collides with the driver's predefine

`error: Illegal to redefine a predefined value` on a `globals.h` line like
`#define MUD_NAME "..."`. This driver auto-predefines `MUD_NAME` (and a
handful of other config-derived macros) from the config file's own `name`
setting (`lexer_utils.cc`'s `add_quoted_predefine`) — the mudlib redefining
it is a hard compile error, not a silent shadow. Fix: delete/comment the
mudlib's own `#define MUD_NAME` line; the driver's version (from
`config.fluffos`'s `name :` field) takes over transparently. (`dfgsiiv13b`,
an ES2-lineage `globals.h`.)

### 7.40 A textually-`#include`d daemon file duplicates `create()` inside `simul_efun.lpc`

`error: Redeclaration of function 'create'` at the LAST line of
`simul_efun.lpc`'s own (correct-looking) `create()`. Root cause is earlier:
`simul_efun.lpc` does `#include "/adm/daemons/ftpd.lpc"` (textual inline, not
`inherit`) alongside its normal simul_efun fragment includes, and `ftpd.lpc`
—being a full daemon object in its own right — has its own `create()`.
Textually inlining a daemon file into the simul_efun composition duplicates
every top-level function it defines, `create()` just happens to be the one
that collides loudly. Consistent with the standing no-sockets-package policy
(§1.3c) — delete the stray `#include`, don't try to reconcile the two
`create()` bodies. Grep `#include ".*daemons/(ftpd|dns_master)` inside any
`simul_efun.lpc`-shaped file whenever `Redeclaration of function 'create'`
shows up with no visible duplicate in the file itself. (`haiyang` family:
`hy2002`, `hy2000`, `hyiishzdscbb`.)

### 7.41 Corrupted shipped save data: a literal `\r` byte where `/` belongs in a mapping key

`restore_object(): Invalid utf8 string while restoring dbase` or `...Illegal
mapping format...`, thrown from a daemon's own `create()`→`restore()` (e.g.
`securd.lpc`) on a completely ordinary-looking `.o` save file. Inspecting the
raw bytes shows a path-shaped mapping key like `"d\rnpc"` where `"d/npc"` is
obviously intended — a single `0x0d` (CR) byte sitting where `/` (0x2f)
should be. This is pre-existing corruption in the shipped save data itself
(confirmed: `convert_lib.sh`'s own CR-handling only touches `.lpc`/`.h`
files, never `.o` saves), not something introduced by conversion. Since this
is cached runtime ACL/permission state, not authored content, the safe fix
is to move the corrupted file aside (`mv foo.o foo.o.corrupt-bak`) rather
than hand-repair it — the daemon regenerates a fresh, empty dbase on next
save. (`hy2002`, `hy2000` — both `adm/daemons/securd.o` and the `network/`
copy.)

### 7.42 A content NPC/quest object that happens to also be named `master.c` can be misdetected as the real master object

When identifying the master file automatically (§2, or any tooling doing
the same) by searching for a file literally named `master.c`/`master.lpc`
anywhere under `adm/`, a lib can ship a completely unrelated object at a
path like `adm/daemons/story/master.c` — a boss/quest NPC (here: "master"
as in kungfu grandmaster, part of a "五大宗师" storyline), not the master_ob.
Using it as `config.fluffos`'s `master file` compiles "successfully" but
then fails at boot with `No function get_root_uid() in master object` (or
similar) — a confusing symptom that looks like a missing-applies bug (§7.2)
rather than a wrong-file bug. The real master (`adm/single/master.lpc` in
every case seen) sat right there the whole time. Detection: the real
master_ob always defines `object connect(...)` — grep `^object connect(`
across the whole tree and prefer THAT file over any bare filename match
before writing a config. (Century/`adm-single` family: `zjdywzb`,
`zjdy2008wzb`, `hell`, `xkxc98sj`, `ntii`, `nte` — all from one bulk-convert
pass whose automated config generator wasn't yet doing this check.)

### 7.43 `master.lpc`'s `creator_file`/`domain_file`/`author_file()` recurses into a simul_efun object that isn't loaded yet

A common master.lpc pattern forwards these three applies straight to
the simul_efun object (`call_other(SIMUL_EFUN_OB, "author_file", str)`),
used by the driver's own warning/stat-reporting machinery. If ANY
compiler warning fires while `simul_efun.lpc` itself is still being
compiled (e.g. an "Expression has no side effects" or "Unused local
variable" warning inside one of its `#include`d fragments), the driver
tries to attribute it via master's `author_file()`, which calls back
into the not-yet-loaded simul_efun object — `*Object cannot be loaded
during compilation`, then `*No program in object '<simul_efun path>'`,
and the whole boot aborts (`The simul_efun ... and master ... objects
must be loadable`). Looks like a warning, is actually fatal. Fix: guard
each of the three applies with `if (!find_object(SIMUL_EFUN_OB)) return
"";` before the `call_other`. (`hy`, `hy5` — haiyang family.)

### 7.44 A lib assumes `/log` (or a specific subdirectory under it) already exists

`master.lpc`'s `preload()`/`log_error()` or a daemon's `log_file()` call
does an unconditional `write_file`/`->" append` into a path like `/log/log`
or `/log/nosave/quest` with no directory-existence check — the original
archive shipped that directory pre-created (or the original host's
mudlib-setup script made it), but a fresh `work/` tree from this
project's conversion pipeline doesn't have it. Symptom: `*Wrong
permissions for opening file ... for append. "No such file or
directory"` at boot or on first use of the affected daemon. Fix:
`mkdir -p work/log` (and any subdirectory the specific error names) —
check every such error for its exact path, don't assume `/log` alone is
enough. (`njhhdxdes2hx`, `qhxajh`, `zjmudhell`.)

Same pattern, different directory: `toptend.lpc`'s leaderboard save can
target `/topten/<file>` (or `/data/topten/`), both gitignored project-
wide (`.gitignore` lines for `libs/*/work/topten/` and
`libs/*/work/data/topten/`) alongside `toptend.o`. Unlike `log/` — which
usually DOES exist on local disk with real shipped content, just
untracked by git — `topten/` sometimes never existed in the original
archive at all (nobody ever triggered a leaderboard save in the
snapshot that got captured), so there's no local directory for
`scripts/wasm_client.js`'s shape-copying trick to find and recreate
either. The harness now special-cases `topten/` the same way it does
`log/` (so libs where the directory DOES exist locally get it shaped
into MEMFS automatically), but if `ls work/topten` shows nothing at all
on local disk, you still need a real `mkdir -p work/topten` — this is a
genuine first-deployment gap (whoever eventually hosts the lib for real
would hit the identical crash on the very first player to place on the
leaderboard), not just a WASM-sandbox quirk, and won't be fixed by a
git commit since the directory is gitignored either way. (`xbtxiii`.)

### 7.45 `global include file` config directive references a filename that doesn't exist in this archive's `include/`

`config.fluffos`'s auto-generated `global include file : <globals.h>`
default doesn't verify the file actually exists — some archives name it
`global.h` (singular) instead. Compile fails immediately with `error:
Cannot #include globals.h` from every file, cascading into `Undefined
function` errors for anything the (never-loaded) global include would
have defined. Fix: `find work/ -iname "global*.h"` and point the config
line at whatever's actually there. (`sgzmudsgz`.)

### 7.46 A mudlib built on the LIMA codebase demands driver compile flags this project's shared build doesn't have

LIMA-derived mudlibs ship their own `check_config.lpc` self-test that
refuses to boot unless the driver was compiled with a specific flag set
(`NO_LIGHT`, `NO_ADD_ACTION`, `NO_WIZARDS`, `ARRAY_RESERVED_WORD`,
`undef OLD_ED`, `undef PACKAGE_UIDS`) — incompatible with every other
mudlib in this collection, which need the opposite. Not fixable at the
mudlib-source level; would require a second, separately-compiled driver
binary just for LIMA libs. Out of scope for now — file as `noboot` with
the specific flag list from the error message (useful if this is ever
revisited). (`sgzmudsgz`, 三国志MUD.)

### 7.47 `origin()` returns a STRING on this driver, not the old int bitmask

Old-MudOS code compares `origin()` against `ORIGIN_LOCAL`/`ORIGIN_CALL_OUT`/
etc (int bitmask constants from `origin.h`, e.g. `0x2`, `0x10`). This
driver's `origin()` returns the STRING name instead (`f_origin()` calls
`push_constant_string(origin_name(caller_type))` in
`src/packages/core/efuns_main.cc`) — the comparison is `always false
because of incompatible types (string vs int)`, a compile error, not a
runtime surprise. Mapping (`origin_name()`'s table, index by
`ffs(orig)-1`): `0x1`→`"driver"`, `0x2`→`"local"`, `0x4`→`"call_other"`,
`0x8`→`"simul"`, `0x10`→`"internal"` (yes, `ORIGIN_CALL_OUT` maps to the
string `"internal"`, not `"call_out"`), `0x20`→`"efun"`,
`0x40`→`"function pointer"`, `0x80`→`"functional"`. Fix: replace
`origin()==ORIGIN_X` with `origin()=="<string>"` per this table; grep
`origin()\s*==\s*ORIGIN_` across the whole lib, not just the file that
happened to fail first. (`njhhdxdes2hx`'s `feature/team.lpc`.)

### 7.48 `private` function/variable declared in one file, called from a program that inherits it — illegal on this driver

Old-MudOS's `private` was effectively today's `protected` (blocks
external `->` calls, but still reachable through the inheritance
chain). This driver enforces `private` strictly: a function/variable is
only visible within the SAME file it's declared in, full stop — calling
it from ANY inheriting program (even one that legitimately inherits the
declaring file) is `Illegal to call inherited private function 'X'`, a
compile error on the INHERITING file, not the declaring one. Common
shape: a `feature/dbase.lpc`-style file `inherit`s a treemap/storage
helper (`F_TREEMAP`) and calls its `_query`/`_set`/`_delete` directly;
or a `std/char.lpc` composed from a dozen `feature/*.lpc` files calls a
sibling feature's helper (`continue_action()`, `attack()`) that's meant
to be feature-internal-but-inheritable. Fix: change `private` to
`protected` on the specific declaration the error names — safe to do
blanket across a lib's `feature/`-style helper files, since `protected`
is strictly less restrictive than a working `private` and can't
introduce a NEW bug, only fix an existing illegal-call error. Leave
alone anything not actually erroring (e.g. `command_hook()` declared
`private nomask` is often a deliberate anti-override security measure,
§8.3's checklist item — don't loosen it preemptively).
(`njhhdxdes2hx`'s `feature/treemap.lpc`, `feature/action.lpc`,
`feature/attack.lpc`.)

### 7.49 A `valid_write()` save-file allowlist check forgets the driver appends the save extension

A common security-daemon idiom lets a player save their OWN file by
comparing the literal `file` argument `save_object()`'s security
callback receives against `object->query_save_file()`'s return value —
but `query_save_file()` conventionally returns the BARE path (no
extension; callers append `__SAVE_EXTENSION__` themselves before
calling `assure_file()`), while the driver's own `save_object()` efun
passes the FULL final filename, extension included, to `valid_write()`.
The two never match, `save_object()` denies write access, and `quit`
(or anything triggering a save) throws `*Denied write permission in
save_object()` — reachable only once a REAL save actually fires, so it
survives a "boots clean, look/score work" check and only shows up when
you actually run `quit` to completion (§7.16's cousin: verify the FULL
flow, not just the parts before the bug). Fix: compare against `file ==
qsf || file == qsf + ".o"` (or whatever `__SAVE_EXTENSION__` is) instead
of a bare equality. Diagnosed by temporarily logging both sides of the
comparison in `valid_write()` — faster than guessing when the mismatch
isn't obvious from reading the two functions in isolation.
(`njhhdxdes2hx`'s `securityd.lpc`.)

### 7.50 `accept_kill()` passes an object where `is_killing()` expects a string id

A recurring copy-paste bug in `clone/user/user.lpc`'s `accept_kill(object
ob)`: `if (is_killing(ob)) return 1;` — but `is_killing()` (typically in
`feature/attack.lpc`) takes a string id (`is_killing(string id)`), and
every OTHER call site in the same lib correctly passes
`ob->query("id")`. Compiles with `Bad type for argument 1 of is_killing
(string vs object)`, blocking the whole `clone/user/user` compile (and
therefore character creation, since `make_body()` needs it). Fix:
`is_killing(ob)` → `is_killing(ob->query("id"))`, matching the other
call sites in the same file. Seen independently in five unrelated
lineages (`nt1`, `wxddym`, `zjmudhell`, `hell`, `nte`), so check for it
on sight in any new lib rather than waiting to hit the compile error.

### 7.51 NTOS-specific driver extensions with no FluffOS equivalent: `query_heartbeat_interval()`/`set_heartbeat_interval()`

Some NT/nitan-lineage libs call `query_heartbeat_interval()`/
`set_heartbeat_interval()` (a CPU-adaptive heartbeat-throttling feature
specific to the NTOS MudOS fork these libs originally ran on) to slow
down the global driver heartbeat under load. Neither function exists on
this driver — `Undefined function`, a compile error wherever called
(`adm/daemons/timed.lpc`'s periodic CPU check, `adm/daemons/systemd.lpc`'s
pre/post-save heartbeat pause). No FluffOS equivalent exists (heartbeat
interval isn't configurable this way). Fix: delete the calls entirely
(they're pure side-effect statements, safe to drop) — the feature is
unavailable, not replaceable. Grep `heartbeat_interval` across the whole
lib, not just the file that failed first. (`nt6`/`nt6nitan6win`.)

### 7.52 A `mudlistd`-style intermud daemon uses `sockets` package efuns unconditionally, breaking its own compile

Distinct from §1.3c's "daemon absent, guard with find_object()" pattern:
here the daemon's OWN source directly calls `socket_create()`/
`socket_connect()`/`socket_close()`/`socket_write()` with no availability
check, so the FILE ITSELF fails to compile (`Undefined function
socket_create` etc) the moment anything tries to load it — no
`find_object()` guard at the call site helps, since the callee can't
even compile far enough to be found absent. If something in the boot/
login chain references this daemon (directly or transitively — the
trigger can be hard to pin down exactly), the whole chain can fail.
Fix: since the underlying feature (dialing out to other muds) is
categorically unavailable without the sockets package, gut the
sockets-dependent function bodies to no-ops (delete the `socket_*`
calls; a function that only ever set up a callback chain for a socket
that will never open should just do nothing) rather than trying to
preserve partial behavior. Non-socket parts of the same daemon (local
data storage, HTML/MRTG stats generation) can stay untouched. While
doing this, watch for genuinely pre-existing unrelated bugs uncovered
in the same dead code path — e.g. a bare `array x = allocate(3);`
declaration (no element type; `array` alone isn't a valid type on this
driver, see §6.3) — fix those too since the function still needs to
compile even though it'll never usefully run. (`nt6`/`nt6nitan6win`'s
`mudlistd.lpc`.)

**Default to disabling the whole file, not patching call sites one at
a time.** When a file's entire PURPOSE is a socket server/client (a
pure intermud daemon like `mudlistd.lpc`/`dns_master.lpc`), the fastest
correct fix is usually to neuter the couple of top-level ENTRY POINTS
that kick off the socket lifecycle (`create()`, `startup_udp()`,
`connect_server()`, an `in_server()`-style listener setup) down to
no-ops/early-returns, rather than hunting down and patching every
individual `socket_*` call across dozens of helper functions. Once the
entry points never fire, the helper functions (read/write/close
callbacks, command parsers) are dead code at runtime — but LPC still
type-checks unreachable code (per §6.x), so each helper that itself
contains a `socket_*` call still needs its OWN body gutted to compile,
even though nothing will ever invoke it. For a FILE WHOSE ENTIRE
PURPOSE is sockets (no other functionality anything else depends on),
gutting every socket-touching function this way effectively disables
the whole file with minimal risk. The one case where this default is
WRONG: a large multi-purpose daemon where socket-based sync is only
ONE of several bundled features and many OTHER non-socket functions in
the same file are called broadly elsewhere in the codebase (e.g. a
`versiond.lpc` that also tracks release-server status, checksums, and
version metadata used by dozens of unrelated NPCs/commands) — there,
actually disabling the whole file (excluding it from load, or making
its `create()` a no-op) would break all those unrelated callers too;
keep the file loadable and only gut the specific socket-touching
functions, leaving the rest of its public interface intact. (`nt1`'s
`versiond.lpc` — a ~2300-line file with 13 separate functions
containing `socket_*` calls, but whose `is_version_ok()`/
`is_release_server()`/`append_sn()` etc. are called from dozens of
unrelated files throughout the mudlib.)

Independently confirmed on `nte`'s own (unrelated codebase, different
lineage) `versiond.lpc` — same shape almost exactly: also 13 socket-
touching functions/callbacks, also `is_version_ok()`/`query()` etc.
called from 32 other files. `grep -rl "VERSION_D->" work --include=
'*.lpc' | grep -v adm/daemons/versiond.lpc | wc -l` before deciding
whole-file-vs-selective is a fast, repeatable way to make this call —
don't eyeball it.

Also confirmed on the Century/adm-single family's own `dns_master.lpc`
(`ldtx`, `ldtxii`) — `startup_udp()`/`send_udp()`/the `socket_close()`
in `send_shutdown()` gutted per this section's default. Notably here
the trigger was in the registration flow itself, not preload:
`logind.lpc`'s `encoding_to_mudlist()` (the very first prompt after
connect, before the id prompt) calls `DNS_MASTER->query_muds()`, so the
failed compile hung EVERY connection immediately after encoding
selection — a stronger symptom than the usual "some daemon-adjacent
feature is broken," worth checking first whenever a lib hangs right
after its first prompt with no further output.

Also confirmed on an `httpd.lpc` (`mnhf`) — a from-scratch HTTP
World-Wide-Web server daemon (Truilkan/Jacques' classic Interstice-
derived `httpd.c`, ported to several ES II-family libs), gutted
`setup()`/`write_data_retry()`/`store_client_info()`/
`listen_callback()`/`close_connection()`/`remove()`. Distinct from the
`dns_master.lpc` cases: the compile failure here happened during
PRELOAD (not on the registration path), so it surfaced as a boot-time
`No program in object '/adm/daemons/httpd'!` rather than a hang after a
specific prompt — worth grepping `socket_create\|socket_bind\|
socket_accept\|socket_write\|socket_close` across EVERY preloaded
daemon on a new lib, not just the ones with "dns"/"mudlist" in the
name; any from-scratch network-server daemon (HTTP, FTP, telnet proxy)
is equally likely to hit this.

### 7.53 A daemon's own defensive `seteuid(getuid())` silently resets a euid that `create()` deliberately set

If a daemon's real uid never resolves (e.g. `master.lpc`'s
`creator_file()`/`domain_file()`/`author_file()` return `""` — see
§7.43 — for whatever authorship path this file's directory implies),
`getuid(this_object())` permanently returns `""` for that object. A
`create()` that explicitly does `seteuid(ROOT_UID)` to work around this
looks like it fixes everything (welcome banner, first few reads all
work) — but if any OTHER function in the same file later does the
"defensive" `seteuid(getuid())` idiom (common in old code as a
no-op-looking reset to "my own normal uid"), that call resets euid back
to the broken `""`, silently breaking every `read_file()`/`write_file()`
call from that point onward in the same request — with no error at the
`seteuid()` call site itself (it succeeds; it just sets euid to
garbage). Symptom: an early operation works (e.g. a `write()`d welcome
banner), then something several calls later throws
`*Bad argument 1 to sscanf`/`explode()` on a `read_file()` result that
used to work fine natively — because the euid got clobbered in between
by an unrelated helper function's own uid "hygiene" line. Detection:
grep the WHOLE file for `seteuid(` once you've found one euid-related
bug in it — don't stop at the first occurrence. Fix: replace every
`seteuid(getuid())` in the file with the same `seteuid(ROOT_UID)` (or
whatever the file's real intended identity is) rather than trusting
`getuid()` to return anything useful. (`hy`'s `adm/daemons/logind.lpc`
— `howmany_user()` and `make_body()` both had this, in addition to the
already-fixed `create()`.)

### 7.54 A `sscanf(read_file(counter_file), ...)` crash on a truly fresh checkout — not just a WASM-sandbox artifact

Code that tracks a running counter in a small text file (visitor
count, gift-card count, etc.) via `read_file()` + `sscanf()` assumes
the file already exists. If it doesn't, `read_file()` returns the
integer `0` (not an empty string), and `sscanf(0, "%s %d", ...)` throws
`*Bad argument 1 to sscanf, Expected: string Got: 0`, aborting whatever
mid-registration flow called it. This is easy to dismiss as a
WASM-test-harness artifact (the harness's `copyDir()` deliberately
skips copying `log/` file CONTENTS into the WASM sandbox, per its own
comment — see `scripts/wasm_client.js`), but it is NOT harness-specific
here: `libs/*/work/**/log` is `.gitignore`d project-wide, so a genuinely
fresh `git clone` of this repo also lacks the file, and a real first
boot ever would hit the identical crash. Detection: any
`sscanf(read_file(X), ...)` where `X` lives under `log/` (or any other
gitignored/runtime-only directory) is suspect — check whether the
directory is gitignored before assuming "well it existed when the
archive was captured, so it's fine." Fix: guard with
`if (!content) return 0;` (or an equivalent sane default) before the
`sscanf`. (`hy`'s `howmany_visitor()`/`howmany_card()`, reading
`/log/mud/MUDVISITOR`/`GIFTCARD`; same two functions recur near-
verbatim in sibling lineage `hy2000`.)

Same root cause, different call: `write(read_file(missing_file))` —
e.g. `cmds/usr/uptime.lpc` printing "上次当机原因" (last crash reason)
from `/log/nosave/LASTCRASH` — fails as `*Bad argument 1 to receive()
Expected: string or buffer Got: 0`, since `write()` internally calls
`receive()` on the (int 0) argument. This one is easy to miss because
the crashing call is buried inside an innocuous-looking status/banner
command (`uptime`), often invoked from deep in the login flow (here,
from `logind.lpc`'s post-BIG5-answer banner display) — the actual
symptom is the id prompt never appearing at all, with no error visible
in a casual read of the transcript unless the full boot log is
inspected. Fix the same way: guard with `if (content) write(content);`
before printing. (`hy2000`.)

**Fourth confirmed instance, different shape: `xo_final`'s `topten_add()`
crashes on EVERY player login, not just a fresh-checkout edge case.**
`system/daemon/toptend.lpc`'s `topten_add()` (called for 12 leaderboard
categories from `logind.lpc`'s `enter_world()`, unconditionally, for
every non-wizard login) DOES have a guard — but the wrong one:
`if (file_size(f_name) == 0) { ...write a fresh file... }` only catches
"file exists and is empty", not `file_size()`'s `-1` ("doesn't exist").
`libs/*/work/data/topten/` is project-wide `.gitignore`d as
"regenerable", so this isn't archive-specific — it fires on any real
first boot from a fresh checkout, on every single login, for as long as
the topten files stay unwritten. The same file's OTHER two read sites
(`topten_query()`, `topten_del()`) correctly check `== -1` — proof the
`== 0` at the `topten_add()` site is a typo'd comparison value, not an
intentional design choice. Fix: change `== 0` to `<= 0` so both "missing"
and "empty" fall into the same existing "write a fresh file" branch
(matches the two sibling checks' effective behavior without changing
anything for the "file already has real data" path). Detection pattern
for this specific variant: grep a file for multiple `file_size(...) ==`
guards on the same kind of resource — if most say `-1` and one says `0`,
the `0` one is very likely the bug, not a deliberate difference.

**Fifth confirmed instance, third distinct bug shape in the same
recurring `toptend.lpc` daemon: `xixingzhanji`'s `topten_add()` passes
the whole line-array to `sscanf()` instead of the current line.**
`adm/daemons/toptend.lpc::topten_add()`'s fallback parse of an existing
leaderboard file does:
```lpc
astr = explode(str, "\n");
...
if (sscanf(astr[i], "%s(%s)%d", name, id, data) != 3)
  if (sscanf(astr, "%s(%s)%d;%*s", name, id, data) != 3)   // astr, not astr[i]
    return notify_fail(...);
```
The primary attempt correctly indexes `astr[i]` (the current line); the
fallback attempt — meant to retry the SAME line against an alternate
format — passes the bare array `astr` instead, throwing `*Bad argument
1 to sscanf Expected: string Got: array` the moment any existing
leaderboard line fails the primary pattern (uncommon on a fresh file,
but not rare once several players' entries with slightly different
`short()` text have accumulated). Called unconditionally from
`logind.lpc::enter_world()` for every non-wizard login, uncaught, so
this aborts the ENTIRE remainder of `enter_world()` — including the
subsequent `move()` into the player's start room — leaving the
connecting player parented nowhere (`environment()` stays 0) with no
player-visible error at all; only `look` printing "灰蒙蒙一片" and a
later `quit` crashing on `message()`'s null-environment argument (see
§7.11 above) gave it away. Fix: `astr` → `astr[i]` in the fallback
call. Detection: any `sscanf(<array-typed-var>, ...)` where a sibling
line one statement above correctly indexed that same array is very
likely a copy-paste slip, not an intentional whole-array parse (`sscanf`
never accepts an array as its subject argument). As with the §7.11
instance immediately below, this is another reason `enter_world()`'s
call into `toptend.lpc` deserves a defensive `catch()` at the call
site regardless of which specific internal bug it's masking this time.

### 7.55 A security/status daemon crashes on a REENTRANT call to itself, mid-`create()`, before its own later-declared variables initialize

Top-level variable initializers in a `.lpc` file run in DECLARATION
ORDER as the object loads — not all-at-once before `create()`. If
`create()` calls something that reenters the SAME object (e.g.
`restore()` triggers `master.lpc`'s `valid_read()`, which forwards to
`SECURITY_D->valid_read()` — and `SECURITY_D` is this very object,
still mid-load), any function invoked during that reentrant call sees
only the variables declared BEFORE the one currently being
initialized — variables declared later in the file are still their
zero-value default (`0`), not their intended literal. Symptom:
`*Bad argument 2 to member_array(), Expected: string or array Got: 0`
(or similar) from a function like `get_status()` that reads a
STRING-ARRAY variable (e.g. `wiz_levels`) declared textually AFTER a
MAPPING variable (e.g. `wiz_status`) that's declared first and so is
already valid by the time of the reentrant call — the mapping lookup
succeeds, the fallback array lookup crashes. This crash is intermittent
in practice: it only manifests when something happens to trigger the
reentrant call at exactly this point in this object's own load
sequence (boot preload ordering, or which save-file edits change byte
offsets/read timing), so a lib can appear to boot clean and register
players fine in one test run and crash in another that exercises the
same status-check code path slightly earlier. Fix: guard the
type-sensitive call, e.g. `arrayp(wiz_levels) && member_array(...)`,
so a not-yet-initialized variable degrades to "not found" instead of
crashing. (`hy`'s `adm/daemons/securd.lpc` `get_status()`.)

### 7.56 Two files both plausibly named "the security daemon" — always confirm which one the `SECURITY_D` (or similar) macro actually resolves to before editing

A lib can ship BOTH `adm/daemons/securityd.lpc` and
`adm/daemons/securd.lpc` (or similarly near-named pairs elsewhere) —
one a genuine dead-code leftover from an earlier refactor, unreferenced
by anything, the other the file every macro/call site actually points
at. Editing the unreferenced one is harmless but wastes a debugging
session's worth of "why doesn't my fix change the observed behavior"
confusion. Detection: before editing a daemon whose name you inferred
from convention (rather than grepping its actual macro), grep the
`#define X_D "..."` line in `include/globals.h` (or wherever the
project keeps its path macros) and confirm the path matches the file
you're about to edit — do this BEFORE spending time reading/patching
it, not after the fix mysteriously doesn't take effect. (`hy` ships
both `securityd.lpc` — dead code, never referenced — and `securd.lpc`
— the real one `SECURITY_D` resolves to.) Not limited to
`SECURITY_D`/`securityd.lpc` specifically — `dtxywzxzb` had the exact
same trap on `LOGIN_D`: a `/daemons/logind.lpc` dead-code duplicate
(shorter registration flow, no macro anywhere pointing at it) alongside
the real `/adm/daemons/logind.lpc` that `LOGIN_D` actually resolves to
(a longer flow with an extra "super password" step and a post-gender
attribute-reroll menu the dead copy lacks) — tracing the wrong one
produced a plausible-looking but entirely wrong registration sequence
to test against.

### 7.57 Editing an LPC save file (`.o`) with a text-mode file open corrupts it if the lineage encodes structural characters as raw control bytes

Some lineages encode mapping-key path separators as a literal control
character rather than escaping `/` textually — e.g. `implode(path, "\r")`
or `implode(path, "\n")` to flatten a path into a single save-file
mapping key, relying on the raw byte surviving the save/restore
round-trip. If you edit such a `.o` file with a scripting language's
default TEXT-mode file I/O (e.g. Python's `open(path, 'r')` /
`open(path, 'w')` without `'b'`), universal-newline translation on read
converts every `\r` (and `\r\n`) in the file to `\n`, and the write-back
re-serializes only `\n` — silently converting every embedded CR control
byte to LF throughout the ENTIRE file, not just near your intended
edit. Symptom on next boot: `*restore_object(): Illegal mapping format
while restoring dbase` (or similar), often followed by cascading
crashes in anything that reads the now-malformed mapping (e.g. §7.55's
`member_array` crash, if the corruption also disturbs load timing).
Detection: `git diff` on the edited `.o` file shows what LOOKS like
dozens of new line breaks inside what was one long line — that's real,
not a terminal-wrapping illusion; confirm with a raw byte count
(`data.count(b'\r')` before vs. after) rather than trusting a visual
diff. Fix: revert to the original blob and redo the edit with
`open(path, 'rb')`/`open(path, 'wb')` (or equivalent raw-bytes I/O),
verifying the CR/LF counts are unchanged except for your intended
insertion. (`hy`'s `adm/daemons/securd.o`, seeding the `fluffos` admin
account into its saved `wiz_status` mapping.)

### 7.58 A stale `SIMUL_EFUN_OB` (or similar "obviously canonical" path macro) silently breaks EVERY `destruct()`, most visibly as `quit` failing for every new player

§7.56's "two files, wrong macro" trap isn't limited to security daemons
— it can hit `SIMUL_EFUN_OB` itself. A lib can ship an unused, stale
`adm/single/simul_efun.lpc` (a dead-code leftover from an earlier
directory reorg) alongside the real, actively-loaded
`adm/obj/simul_efun.lpc` (confirm which is real via
`config.fluffos`'s `simulated efun file :` line, not by guessing from
the macro name) — with `include/globals.h`'s `#define SIMUL_EFUN_OB`
still pointing at the stale path. Since `SIMUL_EFUN_OB` is a
foundational-feeling macro (the kind you'd assume is always correct
without checking), this is easy to miss entirely. Symptom: any
`remove(string euid)` hook that gate-checks `base_name(previous_object())
== SIMUL_EFUN_OB` (the standard idiom for "only the driver's own
`destruct()` may call this") starts rejecting EVERY legitimate call,
because the real simul_efun override's `destruct()` calls
`ob->remove(...)` from the REAL file's path, which no longer matches
the stale macro. This throws a caught-but-real runtime error
(`*move: remove() can only be called by destruct() simul efun.`) on
every `destruct()` of an object with that hook — concretely, this
breaks `quit` for essentially every new player, since a fresh
character's auto-drop-inventory logic destructs any worthless dropped
starting item. The failure mode is deceptive: the connection prints
the caught error and appears to disconnect, but the character object
is never actually destructed — the player is still logged in and the
world-side session never really closes, even though the client sees
what looks like a normal disconnect. Detection: `quit` (or any other
path that calls `destruct()` on a fresh object) throws this exact
`remove()` permission error; grep `SIMUL_EFUN_OB`'s definition against
`config.fluffos`'s `simulated efun file` line and confirm they name the
SAME path — don't stop at "the macro exists and looks right." Fix:
point the macro at the file `config.fluffos` actually loads. (`xkxlb`.)

### 7.59 A custom `valid_read()` unconditionally substitutes `this_player()` for the driver's `user` argument, denying code compiles while a low-privilege player is connected

The driver calls `master->valid_read(file, user, func)` for more than
just player-triggered file reads — critically, for `func ==
"load_object"` (compiling the main file of an object) and `func ==
"include"` (resolving a `#include`), the `user` argument the driver
passes is `master_ob` itself (root), not whoever happens to be
connected. Some hand-written `securityd.lpc` implementations open with
`if (this_player()) user = this_player();` before doing anything else —
a defensive-looking line meant to make ACL checks reflect "the player
this read is really on behalf of." Applied unconditionally, it also
clobbers the `load_object`/`include` case: the correctly-root `user`
gets replaced with the low-privilege object connected at that moment,
and every subsequent ACL check (e.g. a directory-level `exclude_read`
list that denies `(player)` status from `/clone` or similar) now runs
against a player, denying the compile outright. Since compiling a
player's own body class (`new(USER_OB)`) and its `#include`s happens
during registration — precisely when the connection is a fresh,
unprivileged player — this silently breaks registration for EVERY new
account, not just under WASM. Symptom: `*Read access denied.` (or
`*Object cannot be loaded during compilation.`) thrown synchronously
from a `new(...)` or `#include` line, with the error trace's "对象"
(command_giver/this_player()) showing the connecting object, not a
privileged daemon. Detection: trace which `func` value the failing
`valid_read()` call received (add temporary logging, or reason from the
driver source: `check_valid_path(..., master_ob, "load_object", 0)` in
`vm/internal/simulate.cc`, `check_valid_path(..., master_ob, "include",
0)` in `compiler/internal/lexer_utils.cc`) — if it's `"load_object"` or
`"include"` and `user` was overridden anyway, this is it. Fix: exclude
those two funcs from the override —

```lpc
// BEFORE:
if (this_player())
    user = this_player();
// AFTER:
if (this_player() && func != "load_object" && func != "include")
    user = this_player();
```

Do not chase this by adding narrow per-file `trusted_read` exemptions
(tried first, insufficient — a compile touches its own file AND every
`#include`, each a separate `valid_read()` call with a different `file`
argument; only the func-based fix covers all of them at once).
(`shujian3`, and confirmed again on `jh2006` in the exact original
`this_player()` shape — crashed immediately at boot with `*Read access
denied.` inside `gb_big5()`'s very first `BAN_D->is_banned()` lazy
compile, before the id prompt ever appeared.)

**Variant: the clobber lives in `master.lpc`'s own `valid_read`/
`valid_write` wrapper, using `previous_object()` instead of
`this_player()`.** Same bug, different clobbering source:

```lpc
// BEFORE (always overwrites user, regardless of func):
int valid_read( string file, mixed user, string func )
{
    object ob;
    if (!undefinedp(user))
        if (!objectp(user=previous_object()))
        return 1;
    if( ob = find_object(SECURITY_D) )
        return (int)SECURITY_D->valid_read(file, user, func);
    return 1;
}
// AFTER:
    if (!undefinedp(user) && func != "load_object" && func != "include")
        if (!objectp(user=previous_object()))
        return 1;
```

Symptom was unusually hard to pin down here because the game's OWN
`securityd.lpc` had no `this_player()` call anywhere (a plain grep for
that turned up nothing) — the actual clobber was one layer up, in
`master.lpc`'s wrapper, before `securityd.lpc` ever saw the request.
Detection took adding temporary `write()` calls at every `deny`
`return 0` inside `securityd.lpc`'s `valid_read()` to print `file`/
`user`/`func`, which showed `func=="load_object"` paired with
`user=="/clone/user/user"` (the player's own body class) — a dead
giveaway once visible, since only `master_ob` should ever appear there.
Also confirms the general debugging move for this whole bug class:
when `*Read access denied` fires deep inside an ordinary-looking
`setup()`/`create()` chain during registration, wrap the suspected
call in `catch()` first to surface the actual error text (the crash
otherwise propagates silently, truncating the rest of the enclosing
function with zero visible symptom beyond "the player has no
environment" or similar downstream fallout) — then bisect with
`write()`/`tell_object()` calls (not `log_file()`, which doesn't
persist across separate WASM sandbox invocations) to find exactly
which statement stops executing. (`hy3`.)

### 7.60 `master.lpc`'s `log_error()` calls `CHANNEL_D->do_channel(...)`, triggering the same load-mid-compile crash as §7.1 — but from a completely ordinary compile WARNING, not an error

Same underlying driver rule as §7.1 (`load_object()`/an implicit compile
via `->` forbidden while another compile is already in progress), but
reached through a different, much more commonly-hit door:
`master.lpc`'s `log_error(file, message)` — called for EVERY compile
warning, not just real errors, including totally harmless ones like
`Unknown #pragma, ignored` — ends with
`CHANNEL_D->do_channel(this_object(), "err", message)`. If `CHANNEL_D`
hasn't been preloaded yet (true for whichever files sit before it in
`adm/etc/preload`, `securityd.lpc` often being the very first), that
call-other silently triggers a fresh compile of `channeld.lpc` from
inside the CALLER's still-in-progress compile — caught, but re-thrown
as `*Object cannot be loaded during compilation.` and re-logged through
`log_error()` again, which calls `CHANNEL_D->do_channel()` again,
producing a wall of repeated trace dumps (tens of thousands of lines
in one case) for what was originally just a benign pragma warning on
the first couple of preloaded files. Bounded to the boot window before
`CHANNEL_D` loads — once it's up, subsequent `log_error()` calls are
ordinary method calls on an already-compiled object and work fine — but
during that window it drowns real output and wastes enormous transcript
space. Fix: guard the broadcast the same way §7.1 guards its own
recursive load, checking `find_object()` first instead of assuming the
object is there:

```lpc
// BEFORE:  CHANNEL_D->do_channel(this_object(), "err", message);
// AFTER:
if( find_object(CHANNEL_D) )
    CHANNEL_D->do_channel(this_object(), "err", message);
```

The `write_file()` call just above still captures the message to the
log file regardless, so no information is lost by skipping the
broadcast during the boot window. (`fyzfqyy`.)

### 7.61 The §7.12 wrapper bug can live in `message()` itself, not just in `tell_room()`

§7.12 documents the classic `tell_room()` shape (`exclude` arg defaults
to raw int 0), but on some libs the actual simul_efun `message()`
wrapper is the one missing the guard:

```lpc
// BEFORE:
void message(mixed arg, string message, mixed target, mixed exclude) {
    efun::message(arg, message, target, exclude);
}
// AFTER:
void message(mixed arg, string message, mixed target, mixed exclude) {
    efun::message(arg, message, target, exclude || ({}));
}
```

Fixing only `tell_room()`'s own body is insufficient here: `message()`
is called directly, with just 3 args (leaving `exclude` an
uninitialized int 0), from many other unrelated places —
`channeld.lpc`'s `do_channel()` (`message("channel:" + ..., msg, obs)`)
and `questd.lpc`'s `collect_all_quest_information()` broadcast were both
observed crashing independently of `tell_room()` on the same lib. When
`Bad argument 4 to EFUN message()` recurs from more than one call site
after the `tell_room()` fix is already in place, fix the root
`message()` wrapper instead of chasing each caller individually.
(`hell`.)

### 7.62 `check_legal_id`'s `while (i--)` loop silently accepts an empty string

A common English-id validator shape:

```lpc
int check_legal_id(string id) {
    int i;
    i = strlen(id);
    while (i--) {
        if ((id[i] < 'a' || id[i] > 'z') && id[i] != '_') return 0;
    }
    return 1;
}
```

For `id == ""`, `strlen(id)` is 0, so `while (i--)` never runs its body
at all (the loop condition is checked before any decrement takes
effect) and the function falls straight through to `return 1` —
accepting an empty name as legal. This is easy to hit by accident (an
automated test client sending a blank line as its very first input, or
a real user just pressing Enter at the very first prompt) and the
consequences cascade: the empty id gets `set("id", "")`, and any
downstream code indexing `id[0]` for save-path sharding (e.g.
`sprintf(DATA_DIR "login/%c/%s", my_id[0], my_id)`) reads index 0 of an
empty string — which returns integer 0 rather than throwing an
out-of-bounds error on this driver — and `sprintf("%c", 0)` then fails
with `*(s)printf(): Incorrect argument to type %c, must be valid UTF8
char. (arg: 0)`, disconnecting the user with a confusing low-level
error nowhere near the actual bug. Fix: reject empty input explicitly
before the loop:

```lpc
if (! i) {
    write("对不起，没有这个玩家。\n");
    return 0;
}
```

Any `while (len--)` (or `for`) loop meant to validate every character
of a string has this same empty-string blind spot — check for it
whenever a validator's rejection message can be bypassed by sending
nothing at all. (`hell`.)

### 7.63 One caller of `new(X)` is missing the defensive `if (ob = new(X))` guard that every sibling call site already has

`quit.lpc` called `ob=new("/clone/topten/magic-rice"); ob->movein(me);
ob->savetopten(me); destruct(ob);` with no null check, crashing every
quit with `*Bad argument 1 to EFUN call_other() Expected: object,
string, array, Got: int(0)` when `new()` returned 0. Deep investigation
(tracing `create()` with `write()` debug statements, comparing against
a known-good `new()` target, confirming the file lexes cleanly via the
formatter's own driver-backed lexer) never pinned down WHY `new()`
silently fails for this particular file under this driver — `create()`
never even starts executing, with no compile error, no catchable
exception, nothing. The decisive shortcut: grep the rest of the
codebase for other `new("/clone/topten/magic-rice")` call sites FIRST,
before spending time on driver-internals archaeology. Every other
caller (`top10.lpc`, `topboard.lpc`, `topten.lpc`, `topdel.lpc`) already
wraps the call in `if (ob = new(...)) { ... }`, and `topdel.lpc` even
has a comment acknowledging it: `"topten的magic-rice出问题了"`
("topten's magic-rice has a problem") in its `else` branch. The
original authors already knew this exact `new()` call is fragile and
defended every site except this one. Fix: match the sibling pattern
instead of chasing the root cause — wrap in `if (ob = new(...)) { ...
}` and skip the topten update silently on failure, exactly like the
other three call sites already do. General lesson: when one call site
of `new(X)`/`clone_object(X)` lacks a guard that ALL other call sites
of the same X already have, that asymmetry is itself the diagnostic —
check sibling call sites (and their comments) before deep-diving into
driver internals. (`hy2000`.)

Same asymmetry, larger scale, simpler root cause on `jinyongwenzi`:
`adm/daemons/natured.lpc`'s `event_morning()` has 15 `if (random(8) ==
N) { ... }` weather-event blocks, each spawning 2-8 "invading spy"
NPCs via `badguy = new("/quest/weiguo/<nation>/<file>N")` — the FIRST
`new()` in every block (the "boss" variant) is properly guarded
(`objectp(badguy = new(...)) && badguy->move(room)`), but every
following `new()` in the same block (the rank-and-file variants,
sometimes 2-6 more per block, ~40 unguarded call sites total) is bare
`badguy = new(X); badguy->move(room);` with no check. Here the reason
is mundane and confirmable, unlike `hy2000`'s driver mystery: the
entire `/quest/weiguo/` directory tree was never shipped in this
archive (`find work/quest/weiguo` comes up empty), so every `new()`
call in this whole feature silently returns 0, and the very next
unguarded `->move()` throws `*Bad argument 1 to EFUN call_other() ...
Got: int(0)`. Because this crash happens INSIDE `update_day_phase()`'s
`call_other(this_object(), event_fun)` (no `catch()`), the abort skips
that function's own tail — `remove_call_out("update_day_phase")` /
`call_out("update_day_phase", ...)` never run — permanently killing the
driver's entire day/night cycle heartbeat the first time `event_morning`
draws an unlucky `random(8)`, not just failing one spy-spawn. Fix:
mechanically wrap every previously-bare pair in `if (objectp(badguy =
new(X))) badguy->move(room);`, matching the already-guarded sibling in
the same block — confirmed via a fresh grep that no bare pair remains.
Detect this shape fast in any lib: grep a daemon file for `new(` calls
sharing a variable name, and diff which ones are `objectp()`-guarded
vs bare — an asymmetric split within the SAME function/file is the
signal, same as `hy2000`. (`jinyongwenzi`.)

**Confirmed at a much larger scale, `hy5`'s §10.7 deep functional
test**: `adm/daemons/taskd.lpc`'s `give_gift()` (a periodic
`call_out("auto_save", 88 + random(20), ...)`-driven random-quest/gift
daemon) repeats `room2 = load_object(location); local =
room2->query("short"); if (local) { ... }` across roughly a dozen
near-identical `case N:` blocks, where `location` is a random line
picked from `read_file("/clone/medicine/map1")` (a plain-text list of
room paths). Exactly one block's `new(target["where"] + ".lpc")` call
site is guarded with `if (room2) { ... }`; every other block — 19 sites
in this one file alone — is bare, crashing with the same `*Bad argument
1 to EFUN call_other()` the instant any one line in the map-list file is
a stale/typo'd path. Because the daemon fires roughly every 90 seconds
regardless of player activity, this reproduced multiple times in a
single short test session (confirmed via `debug.log`, not merely
inferred). The exact same copy-pasted pattern, evidently propagated by
copy-paste from a shared original, turned up in `p/npc/teamjob.lpc` (12
sites), `quest/menpai/teamjob.lpc` (12 sites — a near-duplicate of the
first, reached via a different `#include`), `adm/daemons/natured.lpc`
(4 sites, inside the same file as this lib's §7.98 instance above), and
`cmds/std/ask.lpc` (7 sites) — 54 unguarded call sites total across 5
files. Rather than restructure every call site's braces (risky at this
volume under time pressure), fixed with a minimal, behavior-preserving
substitution applied uniformly: `local = room2->query("short");` →
`local = objectp(room2) ? room2->query("short") : 0;` — the very next
line in every single one of these blocks is already `if (local) { ...
}`, so making `local` correctly fall through to falsy on a failed
`load_object()` fully neutralizes the crash without touching any
control flow. Verified live: before the fix, this crash recurred
multiple times across one ~10-minute session purely from the
background `call_out`, unrelated to any specific player action; after
the fix and a reboot, the same daemon cycled repeatedly with zero
crashes. Two backup/dev copies of the same file under `u/hxsd/` (e.g.
`u/hxsd/taskd.lpc/taskd.lpc`) have the identical unfixed pattern but are
not on any code path the driver actually loads (not referenced by path
from anywhere else in the tree) — left untouched, matching this
project's standing convention for `.old`/backup-directory copies.
Detection pattern at this scale: `grep -c` a suspect literal query
string (here `room2->query("short")`) across the whole tree, not just
the one file where a crash first surfaced — a bug this mechanical is
rarely confined to a single file when the underlying idiom is this
copy-paste-friendly.

### 7.64 A stray semicolon after `if (...)` turns the guard into a no-op, making an unconditional `call_other()` hit a daemon that was never shipped

`natured.lpc`'s heartbeat loop had `if (wizardp(user[i]) &&
user[i]->query("env/check_heart"));` — the trailing `;` ends the `if`
right there (empty body), so the next statement,
`"/adm/daemons/temp.lpc"->record_heart_beat(user[i]);`, runs
unconditionally for every connected user on every heartbeat tick (every
second, forever), not just the intended wizard-with-a-flag-set subset.
`/adm/daemons/temp.lpc` doesn't exist anywhere in the codebase (`find
-iname` across the whole lib came up empty) — a dev-only scratch daemon
whose two call sites (one behind this broken guard, one behind a real
guard chain further down) were never cleaned up before release.
`call_other()` on a missing object is a soft failure (logs, returns 0,
execution continues) so this never crashed anything — it just spammed
one runtime-error message per connected user per second, forever,
which is how it surfaced during a routine post-registration `look`.
Fix: since the target file is confirmed absent project-wide, remove
the dead call sites rather than fabricate a replacement daemon (no way
to know what `record_heart_beat()` was supposed to record). General
lesson: `if (cond);` (semicolon immediately after the closing paren,
no braces) is always a bug in LPC same as in C — grep
`if\s*\([^)]*\)\s*;` when a runtime error traces back to a `call_other`
on a suspiciously named daemon (`temp`, `test`, `debug`, `tmp`) that a
`find -iname` can't locate anywhere in the tree. (`kxkjii2`.)

### 7.65 An uncaught `create()` error (e.g. the §7.41 corrupted-save class) leaves a daemon permanently non-resident, and a later IMPLICIT `->` call on it silently no-ops instead of auto-compiling

A meaner consequence of §7.41-style corrupted save data than the visible
compile-error noise it usually gets filed under: if the corrupted-`.o`
daemon's `create()` is never guarded, the uncaught `restore()` error
leaves the object **permanently non-resident** on this driver
(`find_object()` returns 0 for it forever, even though preload printed
no visible error — preload errors are silent, see §1.2/§7.9) — NOT
crashed loudly, NOT auto-recovered. The trap: a later **implicit**
call-string invocation on that still-unloaded object (`SOME_D->foo(...)`,
as opposed to an explicit `catch(load_object(SOME_D))`) does **nothing
at all** — no error, no retry, the call just silently never completes —
instead of auto-compiling the object the way you'd expect from a normal
`->` call on a cold path. Confirmed by bisection: swapping the same
implicit call for `catch(load_object(SOME_D))` immediately BEFORE it
made the daemon load successfully (with the restore error now visibly
caught) and the following implicit call then worked fine.

This matters most when the failing call sits in the middle of a
synchronous setup chain with no error path of its own — e.g. a
`named.lpc`-style "check this new player's name isn't taken" daemon
called from character creation (`get_char()`) BEFORE `make_body()`/
`enter_world()` ever run. The whole character-creation `input_to` chain
just silently dies at that one call: no crash, no visible error, the
connection is left wedged with no player body and no command path ever
set, so literally EVERY subsequent command (not just ones touching the
broken daemon) falls through to the driver's generic fail message
forever. This looks exactly like a command-dispatch/permission-search-
path bug (all commands "not found") and is easy to misdiagnose as one —
the actual defect is entirely upstream, in a completely unrelated
daemon's unguarded `restore()`.

Diagnosis technique: `log_file()` output does not persist across
separate WASM test invocations (see §1.2), so bisect with `write()`
statements instead, placed in a genuinely-interactive call chain
(`input_to` callbacks triggered by real typed input write fine; preload/
`call_out`-triggered code does not, see §7.60/§1.2) — walk the suspect
function step by step until the last visible marker pinpoints the exact
call that goes silent. Fix is the same as §7.41: guard the daemon's own
`restore()` with `catch()` so a corrupted save degrades to an empty
dbase instead of leaving the object stuck non-resident. (`hhsj`
— `adm/daemons/named.lpc`'s `create()` restoring a genuinely corrupted
~168KB save file, discovered because `NAME_D->invalid_new_name()` is an
unavoidable step of every new character's `get_char()`.)

---

### 7.66 An archive snapshot ships only PART of the original `/d/obj/` shared-item tree, relocated under `d/city/obj/` — dozens of NPCs' hardcoded old paths now 404 into the driver's generic error message

Found on `xiyouji2003`'s §10.7 deep functional test, and worth checking on
any lib whose archive turns out to only ship a subset of the original
zone tree (§3's "mudlib nested/partial" traps are the extraction-time
version of this; this is the runtime symptom). This lib's `d/` only
contains `city/` and `wiz/` — no `d/obj/`, no `d/moon/`, no
`d/nanhai/`, no `d/lingtai/`, etc. — yet ~35 different city NPC files
still `carry_object("/d/obj/cloth/<item>")` at `create()` time, a path
that resolves nowhere in this snapshot. Because `carry_object()` (via
`load_object()`) fails inside `catch()`-free code, every one of these
NPCs throws `*call_other() couldn't find object '/d/obj/cloth/<item>'`
the moment their room is first (lazily) loaded — caught by the driver's
config-level `default error message`, so the player just sees a generic
`系统局部错误，请向巫师汇报。` with zero detail, once per affected room
per boot. Individually harmless (session continues, NPC just ends up
unclothed) but pervasive enough to degrade nearly every room transition
during exploration.

**Two genuinely different outcomes hide behind the same symptom — check
both before deciding a hit is fixable:**

1. **Relocated, not lost**: some of the referenced basenames turn out to
   have a same-name, same-purpose file sitting under `d/city/obj/`
   instead (`linen` "粗布衣", `choupao` "绸袍"/"绸布长袍", `sengyi` "僧衣",
   `sengxie` "僧鞋" — confirmed by matching `set_name()` and clothing
   type, not just filename). This is a genuine, high-confidence,
   mechanically fixable path bug: `CITY_OBJ` (`/d/city/obj/`) is already
   the macro these libs use for everything else under that directory.
   Swept all 58 affected files in one pass (binary-mode substitution per
   §10.4's CRLF lesson, since this lineage mixes LF/CRLF file-by-file):
   `/d/obj/cloth/linen` → `/d/city/obj/linen`,
   `/d/obj/cloth/choupao` → `/d/city/obj/choupao`, plus the two
   `jieding.lpc` hits by hand. Re-verified via a fresh boot + full
   `debug.log` walk-through of the previously-affected rooms: all
   `linen`/`choupao`/`sengyi`/`sengxie` errors gone.
2. **Genuinely gone**: most other basenames referenced the same way
   (`pink_cloth`, `shoupipifeng`, `yuanxiang`, `magua`, `piyi`,
   `baguapao`, `shoupiqun`, and others) have no match anywhere in the
   tree — this snapshot's `/d/obj/` subtree was never included at all,
   full stop. Do not invent a substitute or guess a "close enough" item
   from an unrelated directory (a top-level `/obj/cloth/` does exist and
   happens to also contain `magua`/`piyi`/`shoupiqun` files, but nothing
   confirms those are the SAME items rather than an unrelated later
   addition — left untouched rather than guessed). Same root cause,
   same shape, also confirmed genuinely missing: `hua_girl.lpc`'s
   `/d/moon/obj/luoyi` (whole `d/moon/` zone absent),
   `jieding.lpc`'s own `/d/obj/books-nonskill/book-qujing`, and
   `dashi.lpc`'s `/d/obj/weapon/staff/gangzhang`. `d/city/zhuque-e2.lpc`
   /`zhuque-e3.lpc` additionally throw a DIFFERENT-shaped error for the
   same underlying cause — `room.lpc`'s `make_inventory()` doesn't guard
   `load_object()` returning `0`, so a missing `d/nanhai/npc/bonze` NPC
   surfaces as `*Bad argument 1 to EFUN call_other() ... Got: int(0)`
   instead of the cleaner "couldn't find object" message; same
   "genuinely missing zone" diagnosis, just a noisier symptom.

Detection for a similar lib: grep for a hardcoded shared-item directory
prefix (`carry_object("/d/obj/`, or whatever this lineage's macro
resolves to) across all NPC files, then check `find <root> -maxdepth 1
-type d` to see whether the archive's `d/` actually contains that
directory at all — if not, expect this exact failure mode, and triage
each distinct referenced basename individually (relocated vs. genuinely
gone) rather than assuming either answer for the whole set.

---

### 7.67 A character-creation menu's displayed label doesn't match what selecting it actually assigns — copy-pasted from a sibling menu that numbers the same slot differently

Found on `sanjieshenhua`'s §10.7 deep functional test: the registration
flow's role-selection prompt displays `5. 均衡型` ("Balanced"), but
`get_type()`'s `switch (n) { case 5: ob->set_temp("type", "野蛮人"); ...
}` actually assigns `"野蛮人"` ("Barbarian") — a completely different,
unlisted value. Selecting option 5 and immediately being told "您选择
了野蛮人的角色" (a role you never saw on the menu) is the live symptom.
Root-caused by checking where the resulting value is actually consumed
downstream: `enter_world()` calls `user->set("hell_type", ...)` — the
field name alone gives it away — and `"野蛮人"` turns out to be a real,
extensively-used class value throughout this lib's separate `daemon/
hellfire/` combat subsystem (attack-efficiency tables, class-specific
NPC logic), while `"均衡型"` has zero references anywhere else in the
codebase. A sibling character-creation script (`d/wiz/init2.lpc`, a
different/older entry point into the same hellfire system) displays the
SAME six-slot menu but with slot 5 correctly labeled `野蛮人` — strong
evidence the main registration prompt's label was copy-drifted to say
something else (`均衡型`) while the `switch` block underneath, copied
from (or shared design intent with) the hellfire menu, kept assigning
the original value. **The display string was the bug, not the
`switch`** — confirmed by checking which of the two candidate values is
actually load-bearing elsewhere before "fixing" either one. Fixed by
changing the menu label to `野蛮人` to match both the `switch` and the
sibling menu; left the `switch`'s assignment untouched.

General lesson: when a menu's displayed option and its resulting
assigned value disagree, don't assume the `switch`/dispatch table is
the stale one just because it's more "code-like" — grep for where the
resulting value actually gets consumed (a `set()` key name, a lookup
table, a sibling subsystem) and let that settle which side of the
mismatch is load-bearing before editing either.

---

### 7.68 (RETRACTED except `bmxkx2001` — read the retraction before applying) A multi-stage `call_out()` sequence gated on `present(ob)` can look like it silently abandons its subject if something else moves it away mid-sequence — but absence is usually the subject just wandering off on its own, which is often intentional design, not a bug

**Retraction (user correction, 2026-08-05): "stuck as a ghost if you're
not in the room" is a plausible, even likely, INTENTIONAL design
choice, not a universal bug.** The original `bmxkx2001` finding below
is real and confirmed live. But the fix was then applied to ~13 other
libs found with the same `if (!ob || !present(ob)) return;` shape
purely by pattern-matching the code, without re-verifying the actual
precondition each time: this fix is only correct if (a) a ghost's own
movement is normally blocked entirely, so `present(ob)` can only go
false via some OTHER system forcibly moving it, AND (b) such a forcing
mechanism actually exists in that lib. Most of those 13 never checked
(b), several never even checked (a) — a few were applied "proactively,
before the soft-lock was ever triggered live." If a lib's ghosts CAN
wander off under their own power, then never re-triggering the revival
dialogue is just as plausibly an intentional "wander the underworld
until you find your own way back" mechanic (the room's `init()`
re-schedules the whole sequence fresh next time the ghost re-enters,
so nothing is unrecoverably lost) — and forcing indefinite retry
instead can introduce a NEW bug: if the ghost wanders back later, the
stale retry and a fresh `init()`-triggered sequence run concurrently
and garble the dialogue. **Action taken**: reverted in every lib below
except `bmxkx2001` (restored to the original bare guard); each lib's
own NOTES.md has a short correction note. **Do not apply this fix to a
new lib on code-shape alone** — first confirm LIVE that (1) a ghost
genuinely cannot move under its own power there, AND (2) some other
system actually forces ghosts to move against their will during the
resurrection window. Absent both, "absent → abandon, restart fresh on
next room-entry" is correct, intentional behavior — same spirit as
§7.27's transit-room retraction.

Found on `bmxkx2001`'s §10.7 deep functional test, in the death/
resurrection NPCs (`d/death/npc/{wgargoyle,wgargoyle1,bgargoyle}.lpc`).
Dying moves the player-ghost to a 鬼门关 (ghost-gate) room and starts a
~50-second, five-stage flavor-text sequence
(`call_out("death_stage", 30, ob, 0)`, each stage rescheduling itself
`call_out("death_stage", 5, ob, stage+1)`) that ends by calling
`ob->reincarnate()` and moving the now-living player back into the
world. Every stage opens with `if (!ob || !present(ob)) return;` — a
reasonable-looking guard against acting on a player who's since logged
off or wandered away. The bug: this guard doesn't distinguish "gone
forever" from "not here THIS INSTANT" — a bare `return` with no
reschedule means ANY single instant of absence during the ~50-second
window kills the whole sequence permanently. Normally this never
fires, because a ghost's own movement commands are blocked (`你已经
精疲力尽，动弹不得` — confirmed live, matches the room's own flavor
text "一进鬼门关就无法再回阳间了"), so `present(ob)` always holds for
a player behaving normally. It DOES fire when something else issues a
forced `ob->move(...)` on the ghost mid-sequence — found live via an
unrelated scripted tour-guide NPC (`d/xiakedao/npc/longx.lpc`,
`move_next()`) that can grab ANY tracked player (dead or alive, no
`is_ghost()`/interactivity check on its side either) and forcibly
relocate them per its own script. When the two systems collide, the
death daemon's next `death_stage()` tick finds `!present(ob)`, returns,
and NEVER reschedules — the player is left stuck as a 【鬼魂】(ghost)
indefinitely, silently, with no error in `debug.log` and no message
telling them what happened; only a wizard's manual intervention (or
this fix) recovers them. Reproduced live: fought and died deliberately,
got dragged away by the tour-guide NPC before the sequence finished,
reconnected and waited it out — confirmed permanently stuck (score
still showed 【鬼魂】/empty 精气 bars with no further progress after
another full wait). Fix (applied to all three ghost-guard files):
split the combined guard so only a truly-gone `ob` (`!ob`, i.e. the
object itself was destructed) aborts for good; a merely-absent-right-now
`ob` reschedules the same stage 5 seconds later instead of giving up:
```lpc
if (!ob) return;
if (!present(ob)) {
  call_out("death_stage", 5, ob, stage);
  return;
}
```
Verified: normal (undisturbed) death→resurrection still completes
correctly post-fix; a second death, disturbed by the same tour-guide
NPC mid-sequence exactly as before, this time still resulted in the
character ending up alive and freely mobile afterward (a ghost cannot
move on its own, so free movement is itself proof of resurrection).
General lesson: a `present()`/liveness guard inside a multi-stage
`call_out()` chain that's meant to protect against a subject going away
permanently should default to RETRY on ambiguous absence, not permanent
abandonment — reserve the hard stop for a genuinely-destructed/gone
object, since "briefly not here" and "gone forever" are different
failure modes. **But only apply that principle once (1) and (2) above
are actually confirmed live — see the retraction.**

**Reverted-and-corrected instances** (all had this same guard shape in
a death/resurrection `death_stage()`-style chain, all reverted to the
plain `if (!ob || !present(ob)) return;`, none independently confirm
this bug class since neither precondition was live-verified in any of
them): `bixiecanyang`, `dtslmud`, `fy2mg`, `fy330`, `fys`, `fysjmb`,
`hhsj`, `hy2002`, `jh2006`, `jhfy`, `jhfy2`, `jyqxc`, `kxkj1`, `mhxy`,
`mhxyqd`, `njhhdxdes2hx`, `shujian3`, `sj`, `syxjl`, `wdxtym`, `wlhd`,
`wmkj`, `xfbhh`, `xkx100`, `xkx2017`, `xxcq`, `yanhuangwuhun`, `yhyxs`,
`zjdyzj` (28 libs total) — plus a jail-mechanic variant unrelated to
death/resurrection (`d/shaolin/npc/yu-zu2.lpc`, found in
`jyqxc`/`syxjl`/`wmkj`). Several
of these (`jyqxc`, `yhyxs`, `yanhuangwuhun`, `syxjl`) DID reproduce a
genuine live undisturbed death→resurrection cycle while the fix was in
place — worth noting only because it shows the *normal* revival flow
works correctly, not because it validates the retry-vs-abandon
distinction (an undisturbed cycle never exercises that distinction
either way). One unrelated, still-valid finding surfaced along the
way and is worth keeping on its own merits: `yanhuangwuhun`'s dead,
unreferenced `d/death/npc/bgargoyle.lpc` (superseded by `hei.lpc`/
`bai.lpc`) has an inverted `!wizardp(previous_object())` check in
`init()` where every live sibling has the bare (non-inverted) form —
harmless only because the file is unreachable; grep for that inverted
shape on sight in any lib with multiple death-NPC implementations.
`fys` additionally had a second, more severe, and still-valid bug in
the same sequence — see §7.76 (`REVIVE_ROOM` pointing at a nonexistent
file) — and `kxkj1`/`wmkj` each surfaced their own separate, unretracted
findings alongside this one (§7.74, §7.75).

### 7.76 A revive/recall macro points at a file that was renamed or reorganized out of existence, so a normally-completing resurrection sequence's FINAL step (not the multi-stage present() chain covered by §7.68) fails and strands the ghost forever, even with zero interruption

Found on `fys`'s §10.7 deep functional test, immediately downstream of
that lib's own §7.68 fix (13th instance). With the `present(ob)` guard
correctly split, `d/death/npc/wgargoyle.lpc`'s `death_stage()` reliably
plays all five `death_msg` stages and calls `ob->reincarnate()` — but
the very next line, `ob->move(REVIVE_ROOM)`, silently failed on EVERY
run, including ones with zero disconnects or interruptions of any kind.
`REVIVE_ROOM` (`include/login.h`) was `#define`d as `"/d/yangzhou/
temple"`, a path with no corresponding file anywhere in the live,
reachable part of the mudlib. `debug.log` showed nothing; the failure
only surfaced in the driver's own captured stdout (`boot.log`, per
§10.8's established precedent for catching what `debug.log` misses):
`执行时段错误：*call_other() couldn't find object '/d/yangzhou/
temple'.` The dead giveaway this was a stale-path problem, not a
missing-content problem: a file named `temple.lpc` DOES still exist in
this archive, but only inside a completely unreferenced backup copy of
the same zone, `d/yz_bak/yangzhou/` (confirmed via a repo-wide grep
that nothing outside that directory ever references `yz_bak`). That
backup's `temple.lpc` no longer even matches its own filename
semantically (its `long` describes "隋炀帝陵", a tomb, not a temple) —
strong evidence the zone was reorganized/renamed at some point and the
`REVIVE_ROOM` macro was simply never updated to track the move. Root-
caused the correct live-zone target by finding a second file that
exists on BOTH sides with matching content: `d/yz_bak/yangzhou/
daxiongbaodian.lpc` ("大雄宝殿") pairs with the live `d/yangzhou/
damingshi1.lpc` (same "大雄宝殿" content) — this pairing, plus the live
zone's OWN `damingshi.lpc` ("大名寺", a temple room immediately adjacent
to `damingshi1.lpc`, complete with a resident 知客僧 monk NPC), gave
enough confidence to redirect `REVIVE_ROOM` to `/d/yangzhou/damingshi`
rather than leaving the finding undocumented-and-unfixed the way
`wmkj`'s genuinely-unresolved §7.74 was. Verified live: killed a fresh
test character, waited fully undisturbed past the entire dialogue
sequence, reconnected, and confirmed the character had landed at "大名
寺" instead of being stuck at the death gate. **Distinguish this from
§7.68**: §7.68 is about a multi-stage `call_out` chain abandoning its
subject on TRANSIENT absence mid-sequence (recoverable by retrying);
this bug fires even on a flawless, completely uninterrupted death cycle
— the sequence completes in full, and only the FINAL, one-shot `move()`
call fails because its destination doesn't exist. Fixing §7.68 alone on
a lib with this bug would NOT be sufficient — always verify a full
undisturbed death cycle lands the character somewhere real, not just
that the dialogue plays to completion. A second, structurally identical
dangling exit was found in the same archive (`u/lxh/dufang.lpc`'s
`east` exit, `__DIR__ "chunxilu3"`, pointing at a nonexistent file in a
wizard's personal directory) but was deliberately left unfixed and
just documented: unlike `REVIVE_ROOM`, there was no comparably strong
structural evidence (no paired same-content file under both an old and
new name) for what the "correct" target should be — a same-named file
does exist elsewhere (`d/chengdu/chunxilu3.lpc`), but a shared filename
alone is too weak a signal to act on; document, don't guess.

**Fourteenth confirmed instance: `njhhdxdes2hx`** (RETRACTED — see top of §7.68) (ES2/侠客行 hybrid,
南京河海大学 campus build — unrelated lineage to `fys` above despite
sharing the exact same shared "白无常/黑无常" gargoyle NPC boilerplate
almost every ES2-family lib in this project carries). `d/death/npc/
{wgargoyle,bgargoyle}.lpc` (`DEATH_ROOM` places `wgargoyle` directly,
its `north` exit reaches `bgargoyle`, both confirmed reachable). Fixed
with the standard split-guard pattern. Here `REVIVE_ROOM`
(`/d/snow/temple`) and `DEATH_ROOM` both resolve to real, existing
files — confirmed NOT an instance of §7.76 on top of this one. Found a
combat_exp-200000 NPC (`d/snow/npc/annihir.lpc`, a money-changer shop
owner far stronger than anything else in the newbie zone) to guarantee
a one-hit kill, then verified via a fully undisturbed wait that all
five `death_msg` stages play and the character lands correctly at "城
隍庙". Also fixed the same one-word text corruption as the `fys`/
`kxkj1` instances above ("阁上册子" → "合上册子" — a different
corrupted character than either prior instance, but the same target
phrase, further corroborating how widely this exact dialogue line was
copied across ES2-family forks) and two unrelated stray-backslash
`Unknown escape sequence` corruptions in two other NPC files
(`fist_trainer.lpc`, `annihir.lpc`) — see §7.77's sibling finding for
the food/water bug found on the same lib.

**Fifteenth confirmed instance: `jhfy2`** (RETRACTED — see top of §7.68) (江湖风云II 之 辽宁风云再起,
"tianya"-map-family sibling to `tybxjh`/`xhcii`/`zxty`/`ffxymud` — a
relationship this lib itself was the SIXTH confirmed member of, per its
own README, but unrelated to any prior §7.68 instance's lineage).
`d/death/npc/{wgargoyle,bgargoyle}.lpc` (`DEATH_ROOM` places
`wgargoyle` directly, its `north` exit reaches `bgargoyle`, both
confirmed reachable). Fixed with the standard split-guard pattern. Both
`REVIVE_ROOM` (`/d/city/wumiao`) and `DEATH_ROOM` confirmed to resolve
to real files (not a §7.76 case), and this lib's copy of the death
dialogue was NOT corrupted (clean "合上册子" already, unlike the `fys`/
`njhhdxdes2hx` instances). Notable here: this lib's own prior WASM-pass
NOTES.md entry explicitly concluded "no mudlib bugs found — clean
first try" based on a registration-only smoke test (no combat, no
death) — this §10.7 pass is a reminder that a clean registration flow
says nothing about what's reachable only through combat/death, and
"no bugs found" conclusions from registration-only passes should be
read as scoped, not as a clean bill of health for the whole lib. Two
OTHER bug classes were also found live on the same pass — see the
`printf("%O\n", ob)` catalog entry above (§7.34) and the §8.9 catalog
entry below, both newly confirmed on this lib in the same session.

### 7.77 A new character's food/water capacity is computed from `query_weight()` before the character owns any equipment, so it's always initialized to zero

Found on `njhhdxdes2hx`'s §10.7 deep functional test: immediately after
registration, `score` showed both the food and water bars completely
empty (0%) for a brand-new character — not gradually draining, starting
empty. `adm/daemons/logind.lpc`'s `init_new_player()` calls
`user->set("food", user->max_food_capacity());` (and the water
equivalent) while setting up a fresh character's stats — but this
lib's `feature/damage.lpc` defines `max_food_capacity()` and
`max_water_capacity()` as `query_weight() / 200`, i.e. proportional to
how much the character is currently carrying. `init_new_player()` runs
BEFORE `enter_world()` gives the new character their starting clothes
(`cloth->wear()`), so at the moment food/water capacity is computed,
`query_weight()` is genuinely 0 — every single new character's food and
water are set to `0 / 200 = 0`, silently, with no error of any kind.
**Distinguish this from §8.9**: §8.9 is about checking the WRONG
OBJECT's `age`, making an existing gate permanently false; this bug has
no such gate at all — the assignment runs unconditionally and
successfully, it just computes a always-zero value because of
initialization ORDER, not because of a wrong-object reference. Detection:
if a freshly-registered character's `score` shows an empty (not just
low) food/water bar, check whether the capacity formula depends on
`query_weight()` (or any other piece of character state) and whether
that dependency is actually populated yet at the point the initial value
is computed — grep for where clothes/starting equipment get assigned
relative to where food/water get set. Fix: move the food/water
assignment from `init_new_player()` to `enter_world()`, placed AFTER
the starting clothes are equipped (guarded with `if
(!user->query("food"))` so it doesn't clobber an already-fed returning
player whose `enter_world()` call is shared between new-character and
restore-login paths). Verified live: a fresh character's `score` showed
full food/water bars immediately after registration, post-fix.

### 7.69 The driver's own auto-included global header is missing a macro that a live daemon requires — while a near-identical, unused duplicate elsewhere in the tree still has it

Found on `bmxkx2001`'s §10.7 deep functional test: `inherit/misc/
bboard.lpc` (the bulletin-board base class, inherited by every board
clone in the game, e.g. `/clone/board/xkd_b`) failed to compile with
`error: Undefined variable 'EDITOR_D'`, which cascaded into `*No
program in object '/inherit/misc/bboard'!` the moment any code tried
to use a board clone (here, an NPC's ambient room-population logic
loading `d/xiakedao/dadong.lpc`, which sets up a board). `EDITOR_D` is
a completely ordinary daemon-path macro (`"/adm/daemons/editord"`,
and `/adm/daemons/editord.lpc` genuinely exists — this is not missing
content). The lib's `config.fluffos` auto-includes `<globals.h>` →
resolves to `include/globals.h` — and that specific file was simply
missing the `#define EDITOR_D` line that every sibling daemon macro
around it has. The twist that makes this easy to misdiagnose: there's
a SECOND, 90%-identical `globals.h` sitting at `inherit/misc/globals.h`
(literally commented "this file will be automatically included by the
driver", i.e. it LOOKS like the canonical one) which DOES have
`EDITOR_D` — but per `config.fluffos` it is never actually the one the
driver includes, and it's independently missing several OTHER macros
(`REGBAN_D`, `UPDATE_D`, `BEAST_D`, `FERRY`, `HARBOR`, `SHIP`,
`F_MULTI`, `SAVE_EXTENSION`, etc.) that the real, auto-included
`include/globals.h` already has — so it's not simply "the good copy",
either; it's a stale duplicate that drifted independently. Before
"fixing" a missing-macro compile error by swapping in a duplicate
header wholesale, confirm via `config.fluffos`'s `global include file`
directive (or the lib's include-path setup) which file the driver
ACTUALLY loads, and diff the two candidates fully (`diff` both
directions) rather than assuming the one with the macro you need is
the complete/correct one — it may itself be missing things the real
file already has. Fix: added the single missing `#define EDITOR_D
"/adm/daemons/editord"` line to the real `include/globals.h`, in its
alphabetical place among the other `*_D` daemon macros; left the
unused duplicate at `inherit/misc/globals.h` untouched (out of scope,
and deleting/syncing dead files is a separate cleanup, not this fix).
Verified: fresh boot's `debug.log` no longer shows the `Undefined
variable`/`No program in object` pair.

### 7.70 A whole codebase confuses its own two-argument `query(prop, raw)` with the far more common `query(prop, target_object)` idiom from other mudlib families — a pervasive, ~162-file pattern found via a genuinely-completed multi-step quest, not a boot check

Found on `wxddym`'s §10.7 deep functional test, while actually finishing
the "投胎" (reincarnation) multi-NPC ritual that a sibling lib (`hhsj`)
had explicitly deferred as "out of proportion for a first bring-up" —
this project's first time actually walking that quest chain to
completion on any lib in this shape. Doing so reached a room
(`/d/newbie/shijiezhishu`, the newbie-zone entry point) whose populating
NPC, `d/newbie/npc/laocunzhang.lpc`, failed to compile:
`error: Bad type for argument 2 of query (int vs object)` at
`query("id", me)` — a call clearly *intending* "look up `me`'s own
`id` property" (embedded in help text: `"look " + query("id", me)`),
but written as if `query()` were a global two-arg helper meaning
`query(property, target_object)`. **It isn't, in this codebase.** Every
actual definition of `query()` in the whole tree (`feature/dbase.lpc`,
`inherit/room/room.lpc`, `adm/daemons/examined.lpc`, `u/rock/dbase.lpc`)
has the signature `query(string prop, int raw)` — `raw` is a
"return the unformatted value" flag, not a target object — so passing
an object where an `int` is statically expected is a genuine type
error, not a matter of which overload gets picked. Fixed this one
instance: `query("id", me)` → `me->query("id")` (the call-other form is
what the surrounding code actually needs). Verified live: the fix
alone was sufficient to let the reincarnation ritual complete end-to-end
(the previously-punted-on quest chain now genuinely finishes, character
reaches 【天界总管】/普通百姓 status with full attributes, personality,
and talents all correctly set, and the newbie-zone NPC's dialogue works).

**Scope note, not fixed further in this pass**: `grep -rlP
'query\("[a-zA-Z_/]+",\s*(me|ob|user|this_player\(\)|this_object\(\))\)'`
across this lib's whole tree matches **162 files** — this exact
misuse is not a one-off typo, it's a systemic confusion running through
a large fraction of the codebase (`feature/apprentice.lpc`, most of
`kungfu/class/**`, and many more), almost certainly copy-pasted forward
from file to file or carried over by an author used to a different
mudlib family's convention. Whether each individual instance actually
breaks depends on whether the driver's static type checker can see a
concrete `object`-typed value at that call site (a `mixed`-typed local
might dodge the compile-time check and only misbehave at runtime, or
silently do the wrong thing without erroring at all) — this was NOT
verified per-instance and needs real triage, not a blind global
replace. Given the scale (162 files) this is out of proportion for a
single-lib deep-dive pass; flagging for a future **dedicated systematic
sweep** on this lib specifically, following the same triage discipline
as the §8.3a `command_hook` sweep (batch-classify hits, verify each
survives a real boot before rewriting, expect some false positives
where a variable named `me`/`ob` happens to actually hold an int).
Detection for other libs: this is `wxddym`-specific so far (a
substantially reworked/forked codebase, not a shared-lineage family
member per §11) — no other lib has shown this shape yet, but the
detection grep above is generic enough to run on any lib during triage
if a similar "Bad type for argument 2 of query" compile error surfaces.

### 7.71 A `call_out()` is scheduled to a function whose entire body is commented out — no error, no dialogue, no progress, forever

Found on `syxjl`'s §10.7 deep functional test, in the death system's
`d/death/npc/bgargoyle.lpc` (黑无常): `init()` correctly calls
`call_out("death_stage", 5, previous_object(), 0)` on every arriving
ghost — but `void death_stage(object ob, int stage) { ... }`, the
entire function including its signature, is wrapped in `/* ... */`
just below. A `call_out()` targeting a function name that doesn't
resolve to any actual function on the object silently no-ops when it
fires (same "no error, no crash, no `debug.log` trace" shape as every
other entry in this section) — so every single object that reaches
this NPC gets scheduled for a revival sequence that will NEVER run:
no death dialogue, no `reincarnate()`, no revival, forever, with
nothing telling the player or a wizard anything went wrong. This is
strictly worse than §7.68's soft-lock (which at least works normally
until interrupted) — here NOTHING ever works, unconditionally, for
every single visitor.

Detection: when auditing a lib's death-NPC (or any `call_out`-scheduled
revival/release) files, don't just grep for the `!ob || !present(ob)`
guard shape (§7.68) — also check that the scheduled function actually
EXISTS as live code, not inside a `/* */` block. A quick sanity check:
`grep -n "call_out(\"<funcname>\"" file.lpc` paired with
`grep -n "^void <funcname>\|^/\*.*<funcname>"` to see whether the
function definition sits inside or outside a comment.

Fix: restore the function (uncomment it) rather than removing the
`call_out()` — the commented-out body is clearly the intended,
already-written implementation (matches its sibling `wgargoyle.lpc`'s
shape almost exactly), not dead/abandoned design; this is a case of
"restore already-written content," not "fabricate new content." Apply
whatever other fixes are independently warranted (here, the §7.68
split-guard) while restoring. If a companion file exists that's
ALSO unreferenced by any room (confirmed dead, not just the specific
function questionably alive), it's fine to leave a matching commented-
out `death_stage()` untouched there — fixing genuinely-unreachable
code inside an ALSO-unreferenced file has no observable effect either
way, so it's a documentation note rather than a required fix (`syxjl`
had exactly this second case: `d/death/wgargoyle.lpc`, a bare-path
duplicate superseded by `d/death/npc/wgargoyle.lpc`, with the same
commented-out shape, left as-is).

Verification caveat: confirm the room the fixed NPC lives in is
actually reachable by whatever's supposed to reach it. On `syxjl`,
`bgargoyle.lpc`'s room (`d/death/gateway.lpc`) is only reachable via a
`north` exit from the primary death gate (`d/death/gate.lpc`) — but a
freshly-dead ghost cannot move at all ("你已经没有力气再走路了，休息
一下吧。"), so this specific fix could be verified as compiling and
loading cleanly, but NOT re-triggered through an actual live ghost
encounter. Document that gap honestly rather than implying a full live
repro that didn't happen.

### 7.72 A flood-kick handler calls `command("quit")` (destructing the caller) without returning immediately after — every subsequent line touching the now-destructed object throws

Found on `syxjl`'s §10.7 deep functional test: `feature/alias.lpc`'s
`process_input()` — the input-dispatch mixin every player command
passes through — counts repeated identical input and, past
`MAX_REPEAT`, tells the player they've been flood-kicked and calls
`command("quit")` to disconnect them. `command("quit")` runs the quit
sequence synchronously, which destructs `this_object()` (the player).
But `process_input()` has no `return` after that call — execution
falls through to the very next lines, which call
`this_object()->query_temp("disable_inputs")` on the object that was
just destructed a few lines above, throwing `Bad argument 1 to EFUN
call_other()` (object shown as `0` in the trace) on literally every
single flood-kick. The player-visible kick itself looks correct (they
really do get disconnected with the intended flavor message), which is
exactly why this is easy to miss without checking `debug.log` — the
bug is silent to the person it happens to.

Fix: add `return` (or an early return of whatever the function's
normal no-op return value is) immediately after `command("quit")`, so
nothing past that point ever touches the destructed object. Verified
live: re-triggered the kick (30+ repeated identical commands) after
the fix and confirmed `debug.log` stayed clean, where it had shown the
error every time before.

Detection: any handler that calls `command("quit")`, `destruct()`, or
similar self-terminating action on `this_object()`/`this_player()`
needs a `return` immediately after — grep for `command("quit")` or
bare `destruct(` calls not immediately followed by `return` in the
same block as a quick triage signal.

### 7.73 An NPC's `create()` unconditionally chains `->wear()`/`->wield()` off `carry_object()`/`new()` for a file that never existed anywhere in the archive

Found on `syxjl`'s §10.7 deep functional test: `u/bsd/npc/
christmas-man.lpc` (a seasonal "Santa Claus" NPC actually placed in
the main town square, `d/city/guangchang.lpc` — not isolated wizard
scratch content despite living under a personal `u/<wizard>/`
directory) has `carry_object("/u/bsd/obj/silver-cloth")->wear();` in
`create()`. `/u/bsd/obj/silver-cloth.lpc` does not exist anywhere —
not in `work/`, not in the raw archive, no similarly-named sibling
file either (confirmed: `u/bsd/obj/` holds exactly three unrelated
items). `carry_object()` returns `0` for a missing path, and the
unguarded `->wear()` on that `0` throws `Bad argument 1 to EFUN
call_other()` every single time this NPC is cloned (on every room
reset that repopulates the square). Same shape as §7.63's missing-
guard class, but on a chained `carry_object()->method()` rather than a
bare `new()`.

Since the target file is a genuine, irrecoverable content gap (not a
misspelled path pointing at an existing file — confirmed by checking
both `work/` and the raw archive), the fix is a defensive guard, not
fabricating a replacement garment:
```lpc
object cloth;
cloth = carry_object("/u/bsd/obj/silver-cloth");
if (cloth) cloth->wear();
```
**A syntax trap hit while writing this fix**: an initial attempt used
the more compact `if (object cloth = carry_object(...)) cloth->wear();`
inline-declaration form. This project's `lpc-syntax` formatter parsed
it without complaint (`{"errors":0}`), but the actual FluffOS driver
rejected it at compile time (`syntax error, unexpected L_IDENTIFIER,
expecting L_COLON_COLON or '('`) — this driver's LPC grammar does not
support C99-style inline variable declarations inside an `if`
condition. **The formatter's parser is more permissive than the real
driver's grammar; passing the formatter is not proof a fix compiles.**
Always restart the driver and watch it load the actual file (or
trigger the code path live) after any edit more syntactically novel
than a straight-line statement change — don't trust formatter-clean as
the final word. Declaring the variable on its own line first side-
steps the whole question. Verified live after the correction: walked
to the square, confirmed the NPC loads and renders correctly, and
`debug.log` stayed clean where it had shown the error every time
before.

**Wider-blast-radius confirmed instance, `ldtx`'s §10.7 deep functional
test: the same unguarded chain, when it lives inside a ROOM's own
NPC-population step, can silently abort an unrelated LATER statement in
that same room's `create()` — here, the room's own message-board force-
load.** `d/city/npc/xiaobao.lpc` (a named NPC placed in `d/city/kedian`,
this lib's actual starting room) had `carry_object("/u/rhxlwd/cloth")
->wear();` in `create()`, targeting a wizard directory (`/u/rhxlwd/`)
that doesn't exist anywhere in the archive — already known and
documented as a "harmless, caught" content gap in an earlier pass. It
is not harmless: `kedian.lpc`'s own `create()` populates its NPCs via
`setup()` (which recurses into `xiaobao.lpc`'s `create()`) as one
statement, then force-loads its bulletin board via a bare `"/clone/
board/kd_b"->foo();` as the textually NEXT statement. Because `xiaobao`'s
`carry_object(...)->wear()` throws and nothing in the `create()`/
`setup()`/`reset()`/`make_inventory()` chain catches it, the throw
propagates out of `kedian.lpc`'s own `create()` entirely — silently
skipping the board-load line that follows, so the board was never
present in the room, for any player, for the entire lifetime of the
boot. Confirmed live: on a fresh driver boot, the very first connection
into the starting room showed no board in the room's inventory listing
and `look kdboard`/`post kdboard` both failed with "你要看什么？"; a
manual admin `update /clone/board/kd_b` fixed it retroactively for that
boot only. Applying the exact §7.73 guard (`object cloth; cloth =
carry_object(...); if (cloth) cloth->wear();`) to `xiaobao.lpc` let
`kedian.lpc`'s `create()` run to completion on the very next fresh boot
— the board appeared correctly in the room description on the first-
ever visit, `post`/`look` both worked, and the NPC's own dialogue
(`chat_msg`/`inquiry`) was unaffected either way, before or after the
fix (its own logic never reaches the broken line). A static sweep of
this lib for the same shape (`carry_object("<literal path>")->wear()/
->wield()`, excluding already-commented-out lines) found 25 further
live call sites across 15 files referencing 8 distinct missing paths
(mostly an entire absent wizard directory, `/u/csy/kunlun/obj/`, hit by
11 of them) — all given the same guard, none independently confirmed to
have this room-create()-abort side effect, but fixed proactively since
the guard is mechanical, safe, and identical in shape. **Detection
takeaway beyond §7.73's original scope: when auditing this bug class,
don't stop at "does the broken NPC itself look wrong" — check what
OTHER statements execute later in the same room's `create()` (or any
caller up that stack), since a single uncaught throw silently truncates
everything sequentially after it, and a completely unrelated feature
(a board, a second NPC, an exit) can go missing with zero error visible
to a player.**

### 7.74 (UNRESOLVED) `object->move(dest)` appears to silently never return when called from deep inside a `call_out()` chain, downstream of a `reincarnate()` call — no error, no crash, no completion

Found on `wmkj`'s §10.7 deep functional test, in the exact same death-
resurrection sequence already fixed by this lib's own §7.68 instance.
With that fix correctly in place (confirmed: all five `death_msg`
stages play in full, in order, every time), `d/death/npc/wgargoyle.lpc`'s
`death_stage()` reaches its final branch: `ob->reincarnate();` followed
by an inventory-drop loop and `ob->move(REVIVE_ROOM);`. Instrumented
with `tell_object()` debug probes at each step (not `write()`, which
targets `this_player()` — wrong context inside a `call_out`) to
localize the failure precisely:
```lpc
} else
  ob->reincarnate();
tell_object(ob, "TRACE: reincarnate done, ghost=" + ob->is_ghost() + "\n");
inv = all_inventory(ob);
for (i = 0; i < sizeof(inv); i++) DROP_CMD->do_drop(ob, inv[i]);
tell_object(ob, "TRACE: about to move\n");
i = ob->move(REVIVE_ROOM);
tell_object(ob, "TRACE: move returned\n");   // <-- never printed
```
The "reincarnate done" and "about to move" lines print reliably and
consistently (`ghost=0`, confirming `reincarnate()` itself completed
correctly). The "move returned" line — a bare `tell_object()` with NO
string concatenation, NO computed value, nothing that could itself
throw — NEVER printed, across multiple independent repro attempts with
different fresh characters. The character remains stuck at the death
gate room afterward, receiving only the gargoyle's ambient `chat_msg`
chatter, never arriving at `REVIVE_ROOM`. Neither `debug.log` nor the
driver's own captured stdout (`boot.log`, per §10.8's precedent for
catching what `debug.log` misses) showed ANY trace of an error,
warning, or crash — the driver process itself stayed alive and
responsive to new, unrelated connections throughout.

Ruled out as NOT the cause, with evidence:
- **Not this lib's §7.68 fix**: the sequence would abort even earlier
  (at the `!present(ob)` check, before ever reaching `reincarnate()`)
  without that fix — this anomaly is strictly downstream of a working
  fix, not caused by it.
- **Not `reincarnate()` itself**: confirmed executing successfully
  (`ghost=0` observed) before the stall.
- **Not the destination room**: `/d/city/wumiao` has no visible
  `prevent_enter`/ghost-blocking logic in its `create()`.
- **Not a stale/corrupted test character**: reproduced with multiple
  independently-registered fresh characters, not just repeated reuse
  of one.
- **Not the driver crashing**: confirmed alive via a parallel connection
  attempt with a different id succeeding normally while the stuck
  character's session was still active.

Suspected but NOT confirmed: `feature/move.lpc`'s own `move()`
override has an early guard — `if (query("equipped") &&
!this_object()->unequip()) return notify_fail(...);` — and
`notify_fail()`'s behavior when there is no active player command being
processed (as is the case deep inside a `call_out`) is untested territory
in this codebase; it's plausible this returns something that reads as
"still executing" to the caller rather than a clean failure, though this
was not proven within this pass's time budget. Not fixed — no root
cause was pinned down with enough confidence to make a real change
rather than a guess, and this project's standing discipline is to
document honestly rather than patch speculatively. If revisited: instrument
`move()`'s own function body directly (not just the calling site) with
probes at every branch, particularly around the `equipped`/`unequip()`
guard, to see whether execution ever actually enters the function body
at all when called in this specific context.

### 7.75 A "canonical" room macro used as a call target actually points at the WRONG file after a historical split/rename, silently orphaning the real function it was meant to call

Found on `kxkj1`'s §10.7 deep functional test, in the same death/
resurrection files as the §7.68 fix above. After the fixed-and-verified
`death_stage()` sequence completes and calls `ob->reincarnate();`, both
`open/death/npc/wgargoyle.lpc` and `bgargoyle.lpc` immediately call
`DEATHROOM->end_death(ob);` — `DEATHROOM` is a simple room-path macro,
resolving to `open/death/gate.lpc` (this exact room; both gargoyles are
literally standing in or next to it). But `gate.lpc` only
`inherit ROOM;` — it has no `end_death()` function at all, so this call
has been a silent no-op (implicit `->` on an object with no matching
function just fails to do anything, per this driver's semantics —
distinct from §7.65's "object not resident yet" case, but the same
class of symptom: a call site that LOOKS like it does something but
doesn't) since the file was written. The REAL `end_death()` — genuine
death-penalty logic, deducting `combat_exp` proportional to whichever
attribute the dying character trained hardest — is defined in
`open/death/start.lpc`, a completely different file. The giveaway that
this wasn't just "wrong macro, pick a different existing one" but a
genuine historical accident: `start.lpc`'s OWN file-header comment
reads `// Room: /open/death/gate.c` — i.e. `start.lpc` was originally
meant to BE (or replace) `gate.lpc`, and at some point the codebase
split/renamed rooms without updating the `DEATHROOM->end_death(ob)`
call sites to point at wherever the logic actually ended up. Confirmed
`start.lpc` is not itself dead code — it's still reachable via
`open/death/bridge1.lpc` — so this isn't a case of "just delete the
orphaned call," the function is real and was meant to fire. Fix: changed
both gargoyle files' `DEATHROOM->end_death(ob);` to
`"/open/death/start"->end_death(ob);`, calling the file that actually
defines the function. Detection pattern for future libs: when a
"death penalty" / "quest completion" / similar consequential call site
uses a macro pointing at a ROOM rather than a daemon, don't assume the
macro's target file has the function just because the call compiles
clean (implicit `->` calls to a missing function are NOT compile
errors) — grep for the function's actual definition and confirm the
macro's resolved path matches it. A stray `// Room: X` header comment
on a DIFFERENT file than the one it's found in is a strong signal of
exactly this kind of drift.

### 7.78 A §7.15-architecture fix doesn't reach bare `set()`/`query()` calls made from INSIDE a mixin file that doesn't itself inherit `F_DBASE` — even though the composed object it's mixed into does

Found on `xfbhh`'s §10.7 deep functional test, while chasing why
`d/register/npc/pangu.lpc`'s `set_name("盘古", ...)` didn't persist:
`query("name")` read back `0` immediately after `set("name", ...)`
returned. This is the same underlying mechanism as §7.15 (bare
`set`/`query` resolving to the simul_efun's shared fallback dbase when
no local candidate exists) but §7.15's own fix doesn't fully cover it.

§7.15's fix works by making `feature/dbase.lpc` (`F_DBASE`) define real
local `set`/`query`/`delete`, on the assumption that "nearly everything
already inherits F_DBASE, so bare calls then resolve locally". That
holds for the TOP-LEVEL composed file (e.g. `inherit/char/char.lpc`,
which directly `inherit F_DBASE;`) — but LPC binds a bare call inside a
function body to whatever's in **that function's own defining file's**
compile-time inheritance graph, not the final merged object's. `char.lpc`
composes CHARACTER out of ~14 separate `F_*` mixin files (`inherit
F_ACTION; inherit F_ATTACK; ...`), each independently compiled. A mixin
that itself has zero (or unrelated, e.g. `F_NATURE`) inherits and calls
bare `query(...)`/`set(...)` in its own body has NO local candidate at
ITS OWN compile time — those calls fall through to the simul_efun
exactly like a §7.15-unfixed object would, regardless of what `char.lpc`
inherits elsewhere. Confirmed empirically: `set("long", ...)` called
directly in `pangu.lpc`'s own `create()` persisted correctly; `set_name()`
(defined in `feature/name.lpc`, which only `inherit F_NATURE;`) calling
`set("name", ...)` internally did not — same object, same moment, only
the DEFINING FILE of the call differed.

**The obvious-looking fix doesn't work.** Adding `inherit F_DBASE;`
directly to the mixin (e.g. `name.lpc`) seems like the natural §7.15-style
fix, but `char.lpc` already inherits `F_DBASE` directly — re-inheriting
the same file via a second path is NOT deduplicated/shared by this
driver's compiler, it's a hard error: `Illegal to redefine 'nomask'
function '_query'` (from `F_DBASE`'s own `inherit F_TREEMAP;` colliding
with itself), because a duplicate inherit of a file containing `nomask`
functions can't just be silently merged. This broke `char.lpc`'s
compile entirely and cascaded into garbled login-prompt behavior for
EVERY connection, not just the one object being edited — revert
immediately if you see this error after adding an inherit line.

**Real fix**: route the mixin's self-targeting bare
`set`/`query`/`query_temp`/`set_temp`/`delete`/`delete_temp`/`add`/`add_temp`
calls through `this_object()->` (call_other) instead of inheriting
anything. `this_object()->query(prop, ob)` dispatches dynamically
against the object's REAL, fully-composed function table (which does
have `F_DBASE` via `char.lpc`), and is behaviorally identical to what a
correctly-resolved bare call would have done — including calls that
already pass an explicit different target object (`query(prop, ob)`
where `ob != this_object()`), since `F_DBASE`'s own `query()`/`set()`
still handle that redirect internally. No need to case-by-case judge
which calls are "already safe" via the simul_efun fallback's own
incidental `ob`-redirect (`adm/kernel/simul_efun/wizard.lpc` does
support it) — converting uniformly is simpler and removes the
dependency on that fallback entirely.

**Severity/symptom**: not cosmetic. `feature/command.lpc`'s
`enable_player()` — called from `char.lpc`'s `setup()` on EVERY new
character's login, not just this one NPC's dialogue — has a bare
`query("id")` that returned `0`, crashing `set_living_name()` (`Bad
argument 1... Expected: string Got: 0`) for every fresh registration.
`feature/attribute.lpc`'s `query_str()`/`query_int()`/`query_con()`/
`query_dex()`/`query_per()` (core combat/attribute reads) all had the
same bare-call pattern. On `xfbhh` this touched 13 of CHARACTER's ~14
`F_*` mixins with bare-call sites: `action`, `apprentice`, `attack`,
`attribute`, `command`, `condition`, `damage`, `equip_liv`, `message`,
`more`, `move`, `name`, `team` (only `alias`/`edit`/`finance`/`skill`
had none). Fixed and verified live via a full registration → attribute
allocation → world-entry playthrough: NPC names/dialogue render
correctly, `score` shows the exact str/int/con/dex values assigned
during `washto`, and `debug.log` stayed empty through the whole session.

**Detection**: grep each mixin file composed into a shared base (not
just the base itself) for bare `\bset\(`/`\bquery\(`/etc., then check
whether THAT SPECIFIC FILE (not the composing object) has `F_DBASE`
anywhere in its own `inherit` chain. A mixin with zero inherits (or only
inherits of other equally bare-handed mixins) that still calls
`query(...)`/`set(...)` is a strong signal — even if the object it's
ultimately composed into looks completely fine on paper.

**Confirmed 2nd instance: `hhsj`** (the `xfbhh`/`nitan170911` lineage
sibling — byte-identical `feature/dbase.c`/`feature/name.c` down to
formatting). Same 13 mixin files, same fix. Worth checking on EVERY
`nitan`/`hhsj`/`nitan170911`-lineage lib (§11 lineage map) — a
byte-identical `dbase.c` is a near-certain predictor of the same bug in
the same 13 files, not just a hint. `hhsj`'s deep-dive also caught a
related-but-distinct bug this pattern can mask: `adm/daemons/
logind.lpc`'s `enter_world()` calls `message("system", ADD2(user),
users);` — only 3 args, but the local `message()` wrapper (`adm/kernel/
simul_efun/message.lpc`) isn't varargs (`void message(mixed arg, string
message, mixed target, mixed exclude)`), so the omitted `exclude` is
silently `0`, and `efun::message()` on this driver build rejects a
literal `0` for that arg (`Bad argument 4... Expected: object, array`).
Fires for EVERY new character at `enter_world()`, not just wizard
accounts as an earlier, less-thorough pass had it scoped (mis-scoped
because that pass only tested the wizard login path) — fix is `if
(!exclude) exclude = ({});` before the `efun::message()` call. Grep
`adm/kernel/simul_efun/message.lpc` for a non-varargs `message()`
wrapper on any `nitan`-lineage lib before assuming this one's fine.

**Confirmed 3rd instance: `nt1`** — and this one has NO exact
master-hash match to `xfbhh`/`hhsj`/`nitan170911` (its own README notes
it as an independent branch, e.g. `F_SHELL` where the others have
`F_EQUIP_LIV`). Same architecture, same `command.lpc` `enable_player()`
crash, same fix — proving this bug traces to the shared NT/nitan/Lonely
UPSTREAM design itself (bare set/query in composed-but-not-inheriting
mixin files), not to one archive being copy-pasted from another. Treat
`§7.78` as a standing check for **every** lib in the NT/nitan/Lonely
family (§11 lineage map), not just byte-identical siblings.

**Confirmed 4th instance: `nitan170911` itself** — the original mega-lib
(014) that `xfbhh`/`hhsj`/`nt1` all descend from, with the near-exact
same bare-call counts per mixin file as `xfbhh` (`attack.lpc` 12,
`damage.lpc` 54, etc.). This is the strongest confirmation yet that the
bug is baked into the upstream NT/nitan/Lonely design itself, present
since before any of the archived forks diverged. Fixed with the
identical `this_object()->` treatment, verified via clean recompile
(0 syntax errors, no new `debug.log`/`boot.log` entries touching the 13
mixin files) — **could NOT be verified via live login/registration**,
because this specific archive's login path requires a real MySQL
connection even for RETURNING characters with an existing local save
(`adm/daemons/logind.lpc`'s `#ifdef DB_SAVE` branch calls
`DATABASE_D->query_db_status()` unconditionally, before ever checking
for a local save file), and this environment has no MySQL/MariaDB
installed at all — a pre-existing, already-documented, permanent
limitation (see this lib's own README), not something this pass could
work around. When a fix can't be live-verified for an environmental
reason like this, static verification (clean compile + no regressions
in the touched files' surrounding log output) plus a proven track
record on architecturally-identical siblings is the fallback — say so
explicitly rather than skipping the fix or claiming false-confidence
live verification.

**Confirmed 5th instance: `wdxtym`** — another independent NT/nitan
branch (same `ver1.0` version-challenge handshake and `║`-separated
registration fields as `xfbhh`/`hhsj`/`nt1`/`nitan170911`, plus its own
extra `F_SUIT` mixin). 10 mixin files affected (`alias`, `apprentice`,
`attack`, `attribute`, `command`, `damage`, `message`, `more`, `name`,
`skill`), same `command.lpc` `enable_player()` crash, same fix. Unlike
`nitan170911`, this one has NO MySQL dependency for login, so it got a
full live verification: 3 separate fresh registrations, each showing
the NPC greeting and player name rendering correctly and an empty
`debug.log` throughout. This lib's own pre-existing NOTES.md/README
*also* independently documents fixing the exact §7.80 bug (the
`eventd.lpc` `[0..<3]` slice) during an earlier WASM pass, before §7.80
existed as a cataloged entry — confirms §7.80 recurs across this
lineage too, not just a one-off on `nt1`.

### 7.79 (IDENTIFIED, NOT FIXED — too large for one pass) Bare, self-targeting `addn()`/`addn_temp()` calls are ALWAYS broken, codebase-wide, regardless of `F_DBASE` — because `addn` is simul_efun-ONLY and never locally defined anywhere

Related to §7.78 but a distinct trap: unlike `set`/`query`/`delete`
(which `feature/dbase.lpc` DOES define locally, so a bare call resolves
correctly for any file with `F_DBASE` genuinely in its own inherit
chain), `addn`/`addn_temp` are **never defined as local/inherited
functions anywhere in this lineage** — only in
`adm/kernel/simul_efun/wizard.lpc`, as a compatibility shim for a
driver efun this build doesn't have (see that file's own header
comment). Every bare `addn(...)` call, no matter what file it's in or
what that file inherits, is ALWAYS a genuine simul_efun call. The
shim's own redirect (`if (!ob) ob = this_object(); return
ob->add(prop, data);`) only works when an explicit target `ob` is
passed AND is not `this_object()` — for the extremely common
self-targeting form (`addn("some_stat", delta)`, no third argument,
meant to buff the caller), `this_object()` inside that simul_efun call
is the simul_efun object itself, so the shim redirects the write to the
simul_efun's own throwaway dbase instead of the caller's. Symptom:
skill/effect code that looks like it's applying a buff or decrementing
a resource on the acting character silently does nothing measurable to
that character (no crash, no error — same "silent no-op" signature as
§7.15's original discovery).

**Scope check on `xfbhh`**: `grep -rPn '(?<!->)\baddn\(|(?<!->)\baddn_temp\('
--include="*.lpc"` found **~10,150 bare call sites across ~3,590
files**, overwhelmingly in `kungfu/`/skill-effect code (e.g.
`feature/pill.lpc`'s `addn("food_remaining", -1);`,
`kungfu/class/murong/murongfu.lpc`'s `addn("san_count", -1);`). This is
far too large to hand-fix in one deep-dive pass and was NOT attempted
here — documented per the established precedent (§7.74) of leaving a
genuinely-too-large finding honestly recorded rather than
partially/riskily patched. Fix pattern for a future pass: same
`this_object()->` treatment doesn't apply here (bare `addn` is never
locally defined, so `this_object()->addn(...)` would just throw "Unknown
function"); instead replace each self-targeting bare `addn(prop, data)`
with `this_object()->add(prop, data)` (or `(ob ||
this_object())->add(prop, data)` for the already-3-arg call sites, per
§7.15's own `addn`-replacement guidance) — `add()` IS a real local
`F_DBASE` function. Given the scale, this likely wants a scripted
per-file transform plus spot-verification rather than manual editing,
and should probably be its own dedicated pass rather than bundled into
an unrelated lib's deep-dive cycle.

### 7.80 A filename-suffix-stripping slice is off by (suffix-length − 1) because `str[0..<n]` keeps `len-n+1` characters, not `len-n`

Found on `nt1`'s §10.7 deep-dive: `adm/daemons/eventd.lpc` builds its
list of loadable event files with `get_dir(EVENT_DIR + "*.lpc")` then
`map_array(event_name, (: $1[0..<3] :))` to strip the `.lpc` extension
before using each name as a `call_other` target. `.lpc` is 4 characters,
but the slice only drops 3 — because this driver's `str[0..<n]` range
keeps indices `0` through `sizeof(str)-n` INCLUSIVE, i.e. `len-n+1`
characters survive, not `len-n`. `"emei.lpc"[0..<3]` is `"emei.l"`, not
`"emei"`. Every single event in the directory got the same off-by-one
corruption (`"huanggs.lpc"` → `"huanggs.l"`, etc.), so
`collect_all_event()`'s `(EVENT_DIR + event)->create_event()` always
targeted a nonexistent path — caught by the driver's error handler
(`*call_other() couldn't find object ...`), so it never crashed
anything, just silently disabled the entire event system on every boot.
Detection: grep for `\[0\s*\.\.\s*<\s*\d+\]` (or the equivalent
`sizeof(str)-N` arithmetic) anywhere it's paired with a known fixed
suffix like `.lpc`/`.c`, and check the off-by-one by hand — `[0..<N]`
needs `N = suffix_length + 1` to fully remove an N-1-character suffix,
not `N = suffix_length`. Fix: change the slice bound to
`suffix_length + 1` (here, `.lpc` is 4 characters, so `[0..<5]`).

**Second confirmed instance: `zjdy2008wzb`'s §10.7 deep functional
test.** Byte-for-byte the same `adm/daemons/eventd.lpc` file and the
same `event_name = map_array(event_name, (: $1[0..<3] :))` line as
`nt1` above, in a completely unrelated Doing/"hell"-lineage codebase —
confirming this isn't specific to one mudlib family, just a copy-pasted
idiom. Same symptom (`*call_other() couldn't find object '/adm/
daemons/event/emei.l'.` etc. on every boot, entire event subsystem
silently dead, no other symptom), same fix (`[0..<3]` → `[0..<5]`),
verified by a clean reboot producing zero `couldn't find object
'.../event/...'` lines in `debug.log`.

### 7.81 A shared base file's own method signature is narrower than the daemon it forwards to, breaking every content file that relies on the daemon's wider contract

Found alongside §7.80 on the same `nt1` deep-dive:
`inherit/misc/quest.lpc` (inherited by every quest content file in the
lib) declares `void set_information(string key, string info)` — but
this is just a thin forward to `adm/daemons/questd.lpc`'s own
`set_information(object qob, string key, mixed info)`, which already
and correctly accepts `mixed`. Nine separate quest files
(`clone/quest/{capture,shen,supply,trace,search,explore,deliver,
judge}.lpc`) call `set_information(NAME, (: ask_npcN :))`, passing a
closure — perfectly valid against the daemon's real `mixed` contract,
but rejected by the narrower local wrapper with a hard compile error
(`Bad type for argument 2 of set_information ( string vs function )`),
taking all nine quest types out of rotation with no runtime symptom at
all (a compile error on a `clone/` file just means `new()` produces an
empty-program object later — see §7.7-adjacent "no program in object"
symptom, not a boot-time failure). This is the same "check whether
scattered-looking errors share one inherited ancestor" lesson as
`ds386`'s `body.lpc` case (§3), but the SHAPE is different: here it's a
narrower TYPE on a wrapper function, not a syntax error, and the
signature narrowing is easy to miss because the wrapper's OWN body
(`QUEST_D->set_information(this_object(), key, info)`) compiles fine —
only callers passing a non-string ever hit it. Detection: when several
unrelated content files fail to compile with the identical "Bad type
for argument N" message on the same call shape, check whether they all
route through one shared inherited wrapper, and compare that wrapper's
declared parameter types against whatever it actually forwards to —
the wrapper is very often more restrictive than its own real backend
for no functional reason. Fix: widen the wrapper's parameter type to
match what it forwards to (here, `string info` → `mixed info`) — a
single-file fix that resolved all nine quest files at once, no content
file itself needed touching.

**Second confirmed instance, unrelated lineage: `yhwhpublicfi`'s §10.7
deep functional test.** Byte-for-byte the same `inherit/misc/quest.lpc`
shape and the same eight `clone/quest/{capture,shen,judge,deliver,
search,trace,supply,explore}.lpc` filenames as `nt1` above — but
`yhwhpublicfi` is a Doing/"hell" lineage fork (§11), completely unrelated
to `nt1`'s NT/nitan family, confirming this is a generic wrapper-narrowing
trap and not something specific to one codebase's quest system. Unlike
`nt1`, this instance had zero runtime symptom reachable from ordinary
play in the test session (each affected quest type's own daemon
(`adm/daemons/quest/*.lpc`) just logs `*No program in object
'/clone/quest/capture'!` etc. on its own periodic `heart_beat()` — the
whole random-quest-generation subsystem was silently dead from the
archive's first boot, invisible without a `debug.log` read after letting
the boot idle). Fix identical (`string info` → `mixed info`); verified
live by having a wizard account `update` all eight `clone/quest/*.lpc`
files after the fix — all eight now compile clean.

**Third confirmed instance, sibling lineage: `zjdy2008wzb`'s §10.7 deep
functional test.** Same "hell" root lineage as `yhwhpublicfi` (an
independent, direct sibling of `zjdywzb` — §11), same `inherit/misc/
quest.lpc` wrapper shape, same eight affected `clone/quest/{capture,
shen,deliver,search,supply,judge,explore,avoid}.lpc` files (this
archive's set swaps `trace` for `avoid` but the shape is otherwise
identical). Same zero-runtime-symptom presentation (`heart_beat()`
logging `*No program in object` silently, invisible without a
`debug.log` read) and identical fix/verification (`string info` →
`mixed info`; all eight files `update` clean afterward).

**Fourth confirmed instance, another "hell" sibling: `xkxc98sj`'s §10.7
deep functional test.** `master.lpc`/`securd.lpc` headers confirmed
byte-identical-lineage with `hell`/`zjdyaryl`/`zjdyzj` (§11 — "for ES
II mudlib ... modified by Xiang for XKX ... updated by Doing Lu for
hell (2K)"), NOT the same codebase as the similarly-"XKX"-titled
`xkx100`/`xkx2017` family despite the shared branding (confirmed by
diff — see §11). Same `inherit/misc/quest.lpc` wrapper shape, this
archive's set is seven files (`clone/quest/{search,shen,judge,supply,
deliver,explore,defend}.lpc`; `avoid.lpc`/`block.lpc` don't call
`set_information()` with a closure and were unaffected). Same
zero-runtime-symptom presentation (`adm/daemons/quest/{search,supply,
deliver}.lpc`'s periodic `heart_beat()` silently logging `*No program
in object '/clone/quest/search'!` etc., discovered via a `debug.log`
read after letting the boot idle, not from any player-visible
symptom) and identical fix (`string info` → `mixed info` in both
`include/quest.h`'s forward declaration and the wrapper body in
`inherit/misc/quest.lpc`). Verified live: a wizard `update` on all
seven previously-erroring files now reports "重新编译 ... 成功！"
with zero `Bad type for argument 2 of set_information` lines
remaining in the log. `defend.lpc` and `block.lpc` each have
additional, unrelated compile errors of their own (`Undefined
variable 'ENEMYS'`/`'my'`/`'i'`, `Illegal lvalue`, `Illegal to use
local variable in a functional`, `Too few arguments to 'message'`) —
these look like genuinely incomplete/broken original quest scripts,
not a copy-paste artifact of this bug class, and were left as a
documented-not-fixed observation in `xkxc98sj`'s own NOTES.md rather
than guessed at.

### 7.82 A login object's own protective `set()` override is too strict, silently blocking a legitimate registration step

Found on `xxcq`'s deep functional test (§10.7). `clone/user/login.lpc`
hardens its own data against tampering with a `nomask` override:

```lpc
// Protect login object's data against hackers.
nomask mixed set(string prop, mixed data) {
  if (geteuid(previous_object()) != ROOT_UID) {
    write("login set is error!" + geteuid(previous_object()) + "\n");
    return 0;
  }
  return ::set(prop, data);
}
```

Reasonable threat model (block a player-triggered exploit from
overwriting `password`/`id` directly) — but the ROOT-only allowlist is
too narrow: `inherit/room/regroom.lpc`'s own `do_register()` (the
*intended*, core email-registration flow, not player-authored content)
calls `linkob->set("password", crypt(pass, 0))` and `linkob->set("email",
...)` while running at the registration room's own ordinary domain euid
(here `"Domain"`), not root. Every call gets silently rejected —
`"login set is error!Domain"` prints to the player, and the function
carries on as if nothing happened (does NOT `return`/abort), so the
rest of registration completes and *looks* successful ("你是第1个注册
的朋友！发送到...的邮件已经加入发送队列！"), but the freshly-generated
password mailed to the player is never actually applied — the
account's real password stays whatever the player originally chose,
silently diverging from what the "forgot your password? check your
email" flow promises. Easy to miss because nothing crashes and the
registration transcript reads as clean; only the literal `"login set is
error!"` string in the transcript gives it away.

Fix: don't widen the login object's own guard (that reopens exactly the
hole its own comment warns about — "现在还是不够的！还是有漏洞！").
Instead route the privileged write through a daemon that already
legitimately holds root euid (`/adm/daemons/logind.lpc`, whose
`create()` does `seteuid(getuid())`), via a small helper:

```lpc
// logind.lpc
mixed set_login_field(object linkob, string prop, mixed data) {
  if (!objectp(linkob) || base_name(linkob) != LOGIN_OB) return 0;
  return linkob->set(prop, data);
}
// regroom.lpc, instead of linkob->set(...) directly:
LOGIN_D->set_login_field(linkob, "password", crypt(pass, 0));
```

Detection pattern: grep for the literal guard-rejection string(s) in a
live transcript (`"set is error"`, `"is fail"`, `"denied"` etc.) even
when the surrounding flow doesn't crash — a `nomask` self-protecting
`set()`/`save()` override on a login/character object is a recurring
idiom in this lineage, and it's easy for the ORIGINAL author's own
system code (not just modern conversion tooling) to end up on the
wrong side of its own guard.

---

### 7.83 A stat-farming cooldown gate silently never engages because its `apply_condition()`/`update_condition()` heartbeat daemon file is missing from the archive

Found on `xkm`'s §10.7 deep functional test, while reading messages off
the newbie-hall board (`大山洞`). `inherit/misc/bboard.lpc`'s `do_read()`
grants `chatpts` (a "灌水积分"/chat-points stat, presumably a leaderboard
or title-unlock currency) once per read, gated by a cooldown condition:

```lpc
if ((int)the_player->query_condition("boardread") > 0) {
  the_player->apply_condition("boardread", 10);
} else {
  the_player->apply_condition("boardread", 10);
  the_player->add("chatpts", 3);
}
```

The intent is clear: `query_condition("boardread")` should read as
"already on cooldown" on the second-and-later read, so only the first
read in a cooldown window grants `chatpts`. But `apply_condition()`
just writes into a plain mapping (`feature/condition.lpc`) — decay is
entirely the job of a per-condition-name daemon at
`CONDITION_D(name)` == `/kungfu/condition/<name>.lpc`, driven from
`heart_beat()`'s `update_condition()`. That daemon file
(`/kungfu/condition/boardread.lpc`) does not exist anywhere in the
archive — `kungfu/condition/` has ~50 sibling condition daemons
(`drunk.lpc`, `sleep.lpc`, `poisoned.lpc`, ...) but no `boardread.lpc`
was ever shipped. Every board read therefore: (1) sets the condition,
(2) on the very next heartbeat tick, `update_condition()` tries to
`find_object`/lazily `call_other` the missing daemon, fails, logs
`Failed to load condition daemon /kungfu/condition/boardread` to
`log/condition.err`, and immediately `map_delete()`s the condition —
so it can never be observed as "still active" by a later read. Net
effect: the cooldown never engages (`chatpts` is granted on literally
every single `read <N>`, an unlimited farm — the exact opposite of the
throttle the code was trying to implement), AND every read spams a
caught runtime error visible in the player's own transcript (`错误讯息
被拦截: 执行时段错误：*call_other() couldn't find object
'/kungfu/condition/boardread'.`) and grows the error log without
bound. `work/log/condition.err.lpc` already had hundreds of these
entries going back to 2002 across dozens of distinct real player names
— this is a long-standing bug in the original archive, not something
introduced by conversion.

Fix: write the missing daemon, mirroring the minimal shape of the
simplest existing sibling (`sleep.lpc`) — decrement and re-apply until
the duration counts down to 0, then let the caller's `map_delete()`
remove it:

```lpc
// kungfu/condition/boardread.lpc
int update_condition(object me, int duration) {
  if (duration < 1)
    return 0;
  me->apply_condition("boardread", duration - 1);
  return 1;
}
```

Detection pattern: any `apply_condition("<name>", ...)` call site is a
promise that `/kungfu/condition/<name>.lpc` exists — grep
`kungfu/condition/` for the name before assuming a cooldown/buff/debuff
mechanic actually works; a caught-and-logged `call_other() couldn't
find object` error for a `CONDITION_D`-shaped path is this bug, not a
red herring.

---

### 7.84 (SEVERITY: HIGH) Every account's plaintext password gets appended to a file under `doc/help/`, which the standard `help` command serves to ANY connected player, not just wizards

Found on `tybxjh`'s §10.7 deep functional test, as an unexpected `git
status` diff in `doc/help/neima2`/`neima3` after a routine test
registration. `adm/daemons/logind.lpc`'s dual-password registration
flow (every account sets BOTH an "admin/recovery password" and an
everyday password, not just wizard accounts) does the real,
correct thing first — `ob->set("ad_password", crypt(pass, 0))` /
`ob->set("password", crypt(pass, 0))`, hashed, exactly as it should be
— and then, immediately after, ALSO does this:
```lpc
write_file("/doc/help/neima2", sprintf("%s的管理密码是%s。\n", ob->query("id"), pass));
...
write_file("/doc/help/neima3", sprintf("%s的普通密码是%s。\n", ob->query("id"), pass));
```
`pass` here is the raw plaintext the player just typed, appended
verbatim, once per registration, forever. The critical second half of
this bug: `/doc/help/` is not some root-only admin log directory — it
is listed directly in `doc/help.h`'s `DEFAULT_SEARCH_PATHS`, the exact
path list `cmds/usr/help.lpc`'s `main()` searches for ANY player's
plain `help <topic>` command, with no `wizardp()` gate at all (unlike
the same file's `/doc/skill/` entry, which IS specifically gated). Any
player, wizard or not, typing `help neima2` or `help neima3` gets back
the complete, ever-growing plaintext dump of literally every account's
admin and regular password, ever registered. This lib's own MOTD
banner reports 86,000+ registered accounts over 20+ years of
operation — the two files already contained real entries (`kjh`,
`commando`) predating this project's involvement, confirming this was
a live, exploitable vulnerability throughout the game's actual
operational history, not a conversion artifact. Fix: delete both
`write_file()` calls — the hashed `ob->set(...)` two lines above each
one already IS the real, correct persistence; the plaintext dump serves
no function the rest of the login flow depends on. Do NOT scrub the
pre-existing historical entries already in `neima2`/`neima3` (that's
original archive data worth preserving, like any other save file), but
DO revert any password your OWN test session appended before
committing — treat it exactly like the existing test-account save-file
hygiene rule, just for this one extra pair of files.

Detection pattern: grep the whole tree for `write_file(` calls whose
target path sits under a directory also present in `help.h`'s
`DEFAULT_SEARCH_PATHS` (or equivalent per-lib mechanism) — logind.lpc
writing "helpfully" to a doc path is the shape to watch for. More
generally, after ANY registration-flow test, diff `doc/`, not just
`data/` — a write into shipped documentation content is exactly as
easy to miss in a routine `git status` skim as a stray save file, and
here it was far more consequential.

---

### 7.85 A percent-bar renderer's index arithmetic still assumes each glyph is 2 storage units wide (a GBK-byte-era leftover), so it silently clamps to a full-looking bar for most non-empty values and for a fully-EMPTY value alike

Found on `tybxjh`'s §10.7 deep functional test: a freshly registered
character's 食物/饮水 (food/water) bars showed completely full in
`score` immediately after login, which looked like it contradicted the
already-confirmed §8.9 bug (`ob->query("age")` instead of
`user->query("age")`, meaning food/water should have been left at 0).
Both things were true at once — §8.9 WAS live (food really was 0) and
the bar STILL rendered full, because `cmds/usr/score.lpc`'s
`tribar_graph()` has its own, independent bug:
```lpc
string tribar_graph(int val, int eff, int max, string color) {
  return color + bar_string[0..(val * 16 / max) * 2 - 1] + ...
}
```
`bar_string` is a 16-CHARACTER string (`"■■■■■■■■■■■■■■■■"`) in this
UTF-8-converted codebase, but the arithmetic still multiplies the
16-wide fill fraction by 2 before slicing — a leftover from the
pre-conversion GBK source, where each glyph really did cost 2 bytes and
byte-indexed slicing needed the `*2`. Two independent failures follow
from this one stale multiplier: (1) at `val=0`, `(0*16/max)*2-1` = `-1`,
and `bar_string[0..-1]` — meant as an empty-slice sentinel — is instead
interpreted by this driver's negative-index convention as "up to the
LAST character," returning the ENTIRE bar_string; an empty stat renders
as completely full. (2) For any `val/max` ratio above ~50%, the
computed end index already exceeds `bar_string`'s real 16-character
length and the slice silently clamps to the full string too — so the
bar is only ever a meaningful gauge below the halfway point, and
reads identically "full" for 51% and 100%. Confirmed both failure modes
live: a fresh character's genuinely-zero food/water (from the
still-unfixed-at-that-moment §8.9 bug) showed full bars, and mid-combat
damage that brought `<气>`(qi) down to exactly 50% also rendered as a
completely solid bar. Fixed by reworking the same visual shape
(filled/pending/blank three-segment bar) with a one-glyph-per-character
scale, no stale width multiplier:
```lpc
string tribar_graph(int val, int eff, int max, string color) {
  int filled, shown;
  if (!max) return none_string;
  if (val < 0) val = 0;
  if (eff < val) eff = val;
  filled = val * 16 / max;
  shown = eff * 16 / max;
  if (filled > 16) filled = 16;
  if (shown > 16) shown = 16;
  return color
    + (filled > 0 ? bar_string[0..filled - 1] : "")
    + (shown > filled ? blank_string[filled..shown - 1] : "")
    + (shown < 16 ? none_string[0..15 - shown] : "")
    + NOR;
}
```
Verified via temporary instrumentation (call `tribar_graph()` directly
with synthetic 0/25%/50%/100% inputs, log the results, remove the
instrumentation) that all four points now render with the correct
proportional fill, then confirmed live in actual combat that a
mid-fight, partially-depleted stat shows a genuinely partial bar. This
lib ships THREE OTHER, differently-implemented copies of
`tribar_graph()` (`cmds/wiz/score1.lpc`, `cmds/wiz/score2.lpc`,
`cmds/usr/i2.lpc`) for the wizard `score`/`i` variants — at least
`score1.lpc`'s copy has the same shape of mismatch between its own
`bar_string` (17 characters) and a `blk_string` companion (34
characters, i.e. still assuming double-width), but this pass only
confirmed and fixed the ordinary player-facing `cmds/usr/score.lpc`
copy (the one every single player sees on every `score`); the other
three are unaudited and may have the same or a differently-shaped
issue. **A full bar is not proof a depletion mechanic (food, water, a
poison condition, anything else rendered through a similar bar
function) is actually fine** — this is exactly the kind of rendering
bug that can silently mask a real §8.9-class initialization bug, so
don't let a full-looking bar substitute for checking the underlying
value when investigating a stat-initialization bug in any lib that
renders stats this way.

---

### 7.86 A board object that both `inherit`s its board base class AND redundantly self-`replace_program()`s the same class permanently breaks its own `post` command, driver-wide, across every board instance in the lib

Found on `xhcii`'s §10.7 deep functional test: `post <title>` on an
ordinary player board crashed instantly, every time, on every board
tried:
```
执行时段错误：*cannot bind an lfun fp to an object with a pending replace_program()
程式：/inherit/misc/bboard.lpc 第 88 行
```
Line 88 is `this_player()->edit((: done_post, this_player(), note :));`
— a closure literal referencing `done_post`, an lfun of the CURRENT
object (the board itself, since `done_post` has no explicit object
prefix). Every single board file in this archive (~90 of them, both
`clone/board/*_b.lpc` and various `d/**/`-embedded ones) has the exact
same `create()` shape:
```lpc
inherit BULLETIN_BOARD;   // "/inherit/misc/bboard" -- gives this object
                          // every bboard.lpc function/variable directly,
                          // at compile time.
void create() {
  ...
  replace_program(BULLETIN_BOARD);   // redundant: already inherited above
}
```
`replace_program()` is meant for a lightweight shell file to dynamically
BECOME another class at runtime, when it doesn't already have that
class's code compiled in. Calling it on an object that already directly
`inherit`s the exact same target is a no-op at best -- but on this
driver it's actively harmful: the object never clears its "replace
pending" flag, and any later attempt to bind a closure to that object's
own lfun (exactly what `do_post()`'s editor callback needs) fails
permanently, forever, for the lifetime of that object. `do_read()`/
`list`/`look` all work fine because they never create a closure --
`post` is the ONLY command that touches this path, which is why the
original WASM/registration-smoke-test pass never caught it: a
functioning board (`look`, message counts, `read`) looks completely
healthy right up until a real player tries to actually write something.
Several board files in this same archive already had the
`replace_program()` line COMMENTED OUT (`//  replace_program(...)`) --
plausible evidence a past wizard hit this exact crash on some boards
and silently worked around it file-by-file without ever finding or
fixing the root shape.

Fix: delete the redundant `replace_program(BULLETIN_BOARD);` call from
every board file that already `inherit`s `BULLETIN_BOARD` directly --
the `inherit` alone is sufficient and was always doing 100% of the real
work. Verified live: before the fix, `post test` crashed instantly with
the error above on a freshly-registered account; after removing the
line (all ~90 files, confirmed none has the two calls with anything
BETWEEN them worth preserving) and restarting, `post` opens the normal
line editor, completes ("留言完毕"), and the board's unread count
updates correctly -- reconfirmed clean on a second board after a full
driver restart.

Detection pattern: any `inherit X;` immediately followed, in the same
file's `create()`, by `replace_program(X)` with the SAME target -- grep
for a class macro appearing both after `inherit` and inside
`replace_program(...)` in the same file. This is a `bboard.lpc`-family
idiom in this codebase (and its "天涯" sibling lineage), but the
general shape -- redundant self-replace_program() on an already-
directly-inherited class -- is worth checking in ANY lib where a
command that creates closures (an editor callback, a delayed
`call_out()` bound to `this_object()`, anything using `(: lfun, ... :)`
literal syntax without an explicit target object) mysteriously fails
only on that one command while everything else on the same object works
fine.

**Confirmed across three unrelated codebase families, not one
lineage's quirk**: reproduced byte-for-byte identically on `zxty`
(same "天涯" family as `xhcii`, 102 more files), on `hy2000` (an
entirely unrelated ES2/金庸 "hy"/海洋 lineage, 53 files), and on
`xyj2000` (a third, unrelated 西游记-themed codebase, where it also
turned out to affect a SECOND, differently-named board base class --
`BBS_BOARD` == `/std/bbsboard.lpc`, not just `BULLETIN_BOARD` ==
`/std/bboard.lpc` -- 3 of `xyj2000`'s 28 total affected files used
`inherit BBS_BOARD;` + `replace_program(BBS_BOARD);` instead; confirmed
`bbsboard.lpc`'s own `do_postnews()` has the identical
`ob->edit((: done_postnews, ... :))` closure-creation shape driving the
same crash). Treat this as a near-universal copy-paste idiom across
this whole generation of ES2-derived codebases -- check EVERY class a
board-like object inherits for a matching redundant
`replace_program()`, not just the most common `BULLETIN_BOARD` name.

**Don't stop at grepping static `.lpc` files.** Found on `sje`'s §10.7
deep functional test: 37 of 38 matches were the usual static board
files, but the 38th was `cmds/king/set_board.lpc` -- a player-facing
command letting a kingdom/faction leader pay in-game gold to build a
board in their own territory, implemented by string-concatenating a
brand new `.lpc` source file at runtime (`write_file()`) and compiling
it on demand. The generated template embedded the exact same `inherit
BULLETIN_BOARD;` + redundant `replace_program(BULLETIN_BOARD);` shape
as every static file in the same lib -- meaning the bug wasn't just
sitting in already-shipped content, it was baked into the *factory*
that generates NEW boards, so every future board any player ever
built with this command would be born already broken. Fixed by
deleting the `replace_program` line from the template string (keeping
the `inherit` line, exactly like every other fix in this section).
When sweeping a lib for this bug, also grep for `BULLETIN_BOARD`/
`BBS_BOARD` appearing inside a `sprintf`/string-literal template being
`write_file()`'d out and compiled, not just literal top-level
`inherit`/`replace_program()` statements -- a few libs in this project
generate board (or NPC, or item) source code at runtime this way.

**A fourth confirmed lineage, `xiakexing3`** (金庸群侠传, `jqxz2008`
engine family): `post board` in the starting-room 客店 board
(`clone/board/kedian_b.lpc`) crashed with the byte-for-byte identical
error text (`*cannot bind an lfun fp to an object with a pending
replace_program()`, just a different line number --
`/inherit/misc/bboard.lpc` 第 102 行 here, since this lib's `bboard.lpc`
has a few extra lines vs. `xhcii`'s -- both point at the same
`this_player()->edit((: done_post, ... :))` closure in `do_post()`).
All 18 of this lib's board instances (`clone/board/*_b.lpc` plus one
`d/taohua/taohua_b.lpc` duplicate) had the exact `inherit
BULLETIN_BOARD;` + `create()`-tail `replace_program(BULLETIN_BOARD);`
shape; no runtime-generated board factory in this lib. Fixed by
deleting the redundant `replace_program()` line from all 18 (CRLF line
endings preserved). Live-verified: before the fix, `post board`
crashed instantly; after the fix and a driver restart, `post board`
opened the line editor normally, `留言完毕` on `.`, and the post showed
up correctly under both `look board`'s unread count and `read <n>`.
Worth noting as a secondary effect of the fix: the board's save file's
class header line changed from `#/inherit/misc/bboard.c` (the class it
used to `replace_program()` into) to `#/clone/board/kedian_b.lpc` (its
real file) after the redundant call was removed -- cosmetic only, the
save/restore mapping data is unaffected and `restore()` doesn't
validate that header strictly.

---

### 7.87 A save file exceeding the driver's configured "maximum read file size" makes `restore()` THROW instead of failing gracefully, and the throw happens during a lazy first-load with no error ever reaching `debug.log`

Found on `xyj20032`'s §10.7 deep functional test: `smile` and other
one-word emote commands, and — far more alarmingly — ordinary NPC
chat/heart_beat-driven social actions (an NPC drinking, chatting,
anything routed through `do_emote()`) started throwing:
```
执行时段错误：*Value being indexed is zero.
程式：/adm/daemons/emoted.lpc 第 341 行
```
on `query_emote()`'s `emote[pattern]` lookup — meaning `emote`, the
daemon's own persistent mapping, was `0` instead of a mapping. Its
`create()` looked properly defensive at a glance:
```lpc
void create() {
  if (!restore() && !mapp(emote))
    emote = ([]);
}
```
The intent: if `restore()` fails, fall back to an empty mapping. But
`emoted.o` — this lib's save file for hundreds of custom emote
definitions — is 328298 bytes, and this lib's `config.fluffos` has
`maximum read file size : 300000`. When the file exceeds that limit,
`restore()` doesn't return a falsy value at all — it **throws**, which
aborts `create()` immediately, before the `if` statement's fallback
assignment ever executes. `emote` is left permanently `0` for the rest
of that boot. Because this happens the first time ANYTHING calls
`do_emote()` (frequently an NPC's own ambient chat, not a player
command), and because the throw occurs mid lazy-compile/first-call
rather than during boot's own preload sweep, **nothing was ever
written to `debug.log`** — the only visible symptom was the runtime
error shown live to whichever player happened to trigger it (or
silently to nobody, if it was only ever NPC-to-NPC). This is the same
"uncaught throw during a lazy first load, invisible to every standard
log" shape as §7.60's `CHANNEL_D` bug and §7.5's `file_size` ACL
false-denial, but the trigger here is a driver-level resource limit,
not mudlib logic.

Two-part fix: (1) raise `config.fluffos`'s `maximum read file size`
past the actual save file's size — bumped to `400000` here, matching
the value already used by several other libs in this project
(`esI`/`mhxy`/`mhxyqd`/`sjcs`/`xiyouji2003`/`zzhj`/others) for the
identical reason. (2) **Also** make the daemon's own `create()` robust
regardless of *how* `restore()` fails — a thrown error and a falsy
return both need the same fallback:
```lpc
void create() {
  catch(restore());
  if (!mapp(emote))
    emote = ([]);
}
```
Verified live: before either fix, `smile` and ambient NPC chat both
crashed with the error above, and `debug.log` had zero related entries
despite dozens of triggers across two boot sessions. After both fixes,
ten+ minutes of ambient NPC activity and direct emote commands produced
zero occurrences.

Detection pattern: any lib with a `create()` shaped like
`if (!restore() && !mapp(X)) X = ...;` is silently assuming `restore()`
can only ever return a value, never throw — check `config.fluffos`'s
`maximum read file size`/`maximum string length` against the actual
byte size of every `.o` save file that daemon-level object owns
(`ls -la` the path from its own `query_save_file()`), not just the
per-player save files this project already routinely checks elsewhere.
A singleton daemon whose OWN save data silently exceeds the configured
limit is a different failure shape from a corrupted per-player save —
it breaks the feature for every single player and NPC in the game,
permanently, for that boot, with no log trace at all.

**Second confirmed instance, different trigger: `xlqyzdb`.** Byte-for-byte
the same vulnerable `emoted.lpc` `create()` shape, but `data/emoted.o`
(262239 bytes) was well under this lib's `maximum read file size`
(300000) — `restore()` still threw, this time with
`*restore_object(): Illegal mapping format while restoring emote.`,
i.e. genuinely corrupt/unparseable mapping syntax in the save data
itself (the §7.7 corruption shape), not a resource-limit throw. Same
fix applies regardless of *why* `restore()` throws — only the
`catch(restore()); if (!mapp(emote)) emote = ([]);` half of the two-part
fix was needed here since the size limit was already fine. Confirms the
detection pattern generalizes: any `if (!restore() && !mapp(X))`
`create()` is unsafe against *any* restore failure mode, not just
oversized files — check for both before ruling a daemon's save-restore
safe.

**Third confirmed instance, a third distinct trigger: `fy2`/`fy2qh`**
(byte-identical siblings). Same vulnerable `if (!restore() &&
!mapp(emote)) emote = ([]);` `create()` shape, but this time `restore()`
threw because `data/emoted.o` (~72KB, the entire `smile`/`nod`/`bow`/
`wave`/... emote pattern database) was simply never GBK→UTF-8
transcoded by the conversion pipeline (§4.1) — `restore_object():
Invalid utf8 string`, a conversion GAP rather than either a resource
limit (first instance) or pre-existing corrupt mapping syntax (second
instance). Same end effect regardless of cause: `emote` stayed
permanently `0` for the rest of the boot, so EVERY emote command
(`smile`, `nod`, ...) silently fell through to the generic
"什麽？"/unknown-command message, for the entire archive's lifetime.
Same two-part fix (re-transcode the save data per §4.1's quote-aware
CRLF-collapse addendum, plus `catch(restore())`). Confirms the class
generalizes across THREE independent trigger shapes now (oversized
file, corrupt mapping, un-transcoded encoding) — the `if (!restore() &&
!mapp(X))` idiom is unsafe against any of them, and a lib carrying it
is worth checking for all three before declaring the daemon's
save/restore path safe.

### 7.88 A simul_efun `message()` wrapper is declared with 4 *required* params but called with only 3 in several places in the same file, so the missing arg silently becomes `int(0)` and crashes the builtin `efun::message()` — and when that crash lands synchronously inside a gating function, it can permanently soft-lock players, not just spam the log

Found on `zjdywzb`'s §10.7 deep functional test. This lib's
`adm/simul_efun/message.lpc` wraps the builtin:
```lpc
void message(mixed arg, string message, mixed target, mixed exclude) {
  efun::message(arg, message, target, exclude);
}
```
— no `varargs`, all 4 params required. But the *same file* calls it
with only 3 args in half a dozen places (`message("tell_object", str1,
me);`, etc.). This driver pads a missing trailing arg to `int(0)`
rather than erroring at the call site, so `exclude` becomes `int(0)`,
and `efun::message()` itself rejects that: `*Bad argument 4 to EFUN
message() Expected: object, array, Got: int(0).` Both `zjdywzb` and its
sibling `zjdy2008wzb` had already logged this exact runtime error
during their WASM-stage passes and dismissed it as "a pre-existing,
non-fatal `message()` signature quirk, out of scope" — it fires
constantly (preload, quit, ambient chat) and the game still boots and
plays, so it read as cosmetic log noise.

It is not cosmetic. During the §10.7 deep-dive's character-creation
ritual, choosing a "quality" (`out` from the 桃源石屋 room) calls
`hua.lpc`'s `check_leave()`:
```lpc
void check_leave(object me, string dir) {
  if (dir == "out") {
    message_vision("$N对$n奸笑道：上路吧！\n", this_object(), me);
    command("chat 哈哈！江湖上又要...... 嘿嘿！");   // <-- crashes here
    me->set("character", "阴险奸诈");                 // <-- never runs
  }
```
The `command("chat ...")` triggers a channel broadcast that hits the
buggy 3-arg `message()` call inside `channeld.lpc`, which throws. Since
nothing between `check_leave()` and the top-level command dispatcher
catches it, the throw unwinds the *entire* `go.lpc` → `valid_leave()` →
`check_leave()` chain: the room-leave permission is never granted (the
player stays in 桃源石屋 forever) AND the character-quality `set()` on
the next line never executes. Every new player hit this — repeating
`out` just repeats the identical crash and the identical non-move,
forever. This is a permanent, unrecoverable soft-lock in the
*mandatory* character-creation path, not a rare edge case.

Fix — make the wrapper tolerant of the same omission its own file already
relies on, matching the `|| ({})` pattern its sibling `tell_room()`
already uses one function above it:
```lpc
varargs void message(mixed arg, string message, mixed target, mixed exclude) {
  efun::message(arg, message, target, exclude || ({}));
}
```
Verified live: before the fix, `out` in 桃源石屋 crashed identically on
every attempt (reproduced 3×) and the player never left the room. After
the fix and a driver restart, the same room, same NPC, same `out`
command moved the player to 阎罗殿 with no error, and the rest of the
registration ritual (跳入忘忧池 → `born <地名>`) completed cleanly for
the first time.

Detection pattern: don't dismiss a `Bad argument N to EFUN message()`
(or any wrapped efun) runtime error as "pre-existing and harmless" just
because the mud keeps running after it — check whether the call site
that triggers it sits inside a function whose *return value or
side-effect gates something the player needs* (a room-leave check, a
quest-stage advance, a shop transaction). A crash mid-function silently
skips every line after it; if one of those skipped lines was the actual
state change the player was trying to make, "the game didn't crash" is
not the same as "the action worked."

**Second confirmed instance, sibling lineage: `yhwhpublicfi`'s §10.7
deep functional test.** Same "hell" root lineage as `zjdywzb` (an
independent yh2003-era fork, not a later pass on the same archive —
§11), byte-identical `adm/simul_efun/message.lpc` wrapper shape and the
same `tell_object()`/`write()` 3-arg call sites. New detail this
instance surfaced: the crash isn't gated behind any player action at
all — a completely clean, freshly-booted driver hits it during ordinary
**preload**, before any connection exists (`adm/daemons/analectad.lpc`'s
`create()` → `channeld.lpc`'s `do_channel()` → the buggy `message()`),
confirming this bug class can be a boot-time finding, not only a
gameplay-triggered one — worth checking a fresh boot's very first
`debug.log` lines for this exact error shape even before attempting any
login. The same 花铁干/`out`/桃源石屋 character-creation soft-lock as
`zjdywzb` reproduced identically here too. Fixed identically (`varargs`
+ `exclude || ({})`); verified both the preload error disappearing on a
clean reboot and the `out` command completing successfully afterward.

**Nuance found on `zjdy2008wzb`'s §10.7 deep functional test (direct
sibling of `zjdywzb`, same lineage): the exact same wrapper-shape bug
did NOT reproduce live on this project's current driver build.** The
code shape is byte-for-byte identical (`message()` non-`varargs`,
called with 3 args from `message_vision()`/`message_combatd()` in the
same file), and the fix was applied anyway (harmless, matches the
lineage's own precedent, and is simply the more correct declaration).
But deliberately reverting the fix and replaying the exact same
crash-triggering path (`register` → `decide` → `west` into 桃源石屋 →
`out`, which necessarily calls `message_vision()` → the 3-arg
`message()` call) produced no error at all, on a full reboot, verified
against a fresh `debug.log`. Root cause, read directly from this
project's `~/src/fluffos` checkout
(`src/packages/core/efuns_main.cc`'s `f_message()`): the 4th arg
(`exclude`) only gets a `bad_argument()` check for the 3rd arg
(`target`); for the 4th, `num_arg==4`'s `switch` has cases for
`T_OBJECT`/`T_ARRAY` and a silent `default` that treats anything else
(including the `int(0)` a missing arg pads to) as "no exclusions" —
there is no path to `bad_argument()` for arg 4 at all on this build.
The `"Bad argument 4 to EFUN message() Expected: object, array, Got:
int(0)."` text documented above for `zjdywzb`/`yhwhpublicfi` is real
(it was captured live in those sessions), but whether it reproduces
appears to depend on the exact driver build/version in use, not just
the mudlib code shape — **don't assume this bug class is live just
because the wrapper shape matches; if reproducing it matters (e.g. to
justify a fix beyond the free, harmless `varargs` change), verify
against a debug.log first**, the same "shape isn't proof" discipline
this whole catalog otherwise insists on for the mudlib side.

### 7.89 A mudlib's own bundled `runtime_config.h` uses a `get_config()` index numbering that doesn't match this driver build's actual internal enum, so a `get_config()` call silently returns a value from an unrelated (and wrongly-typed) config slot instead of erroring — and if that value then flows into a typed efun call, it crashes

Extends the pattern first noted on `ds386` (whose own bundled
`runtime_config.h` gave wrong/empty values for `get_config()` calls,
deprioritized as an English-lib finding without chasing a live crash).
On `zjdywzb`'s §10.7 deep-dive, logging in as a **wizard** account
specifically (not a normal player — normal registration never touches
this path) crashed immediately after the password prompt, leaving the
connection in a broken state where every subsequent command, including
plain `look`, silently returned nothing (not even "什么？"):
```
执行时段错误：*Bad argument 2 to socket_bind()
Expected: int Got: "10".
呼叫来自：/adm/daemons/network/messaged.lpc 的 startup_udp() 第 101 行
呼叫来自：/adm/daemons/logind.lpc 的 get_passwd()/check_ok()
```
`logind.lpc`'s `check_ok()` (a wizard-login-only step) loads
`/adm/daemons/network/messaged` for the first time, whose `create()`
calls `startup_udp()` → `socket_bind(socket_id, my_port)`. `my_port`
is computed as `LOCAL_PORT() + MESSAGE_PORT`, i.e.
`(int)get_config(__MUD_PORT__) + 10`, and `__MUD_PORT__` is
`CFG_INT(0)` — but this lib's bundled `include/runtime_config.h` used
its own from-scratch `BASE_CONFIG_STR`/`BASE_CONFIG_INT` numbering that
does **not** match this driver build's real internal config-slot
ordering (confirmed by diffing against the driver's own canonical
`~/src/fluffos/src/include/runtime_config.h` — same divergence already
seen on `ds386`). `get_config(14)` (this lib's miscomputed index for
"mud port") actually reads whatever the *real* driver puts in slot 14,
which turned out to be some unrelated **string** config value — hence
`my_port` ending up holding the *string* `"10"` (`MESSAGE_PORT`
concatenated onto a string instead of added to an int), which
`socket_bind()` then rejects outright with the driver aborting
`check_ok()` mid-function, before the login can complete.

Fix: replace the lib's stale `include/runtime_config.h` with the
driver's own canonical copy (same remedy as `ds386`) rather than trying
to patch individual indices. Diff the symbol set between old and new
before swapping — any symbol used elsewhere in the lib that the new
header dropped needs either a compatibility `#define` aliasing it to
the closest still-valid equivalent, or its call site updated/removed.
On `zjdywzb`: `__SAVE_BINARIES_DIR__` (used only inside an
already-§7.52-gutted sync daemon) got aliased to `__MUD_LIB_DIR__`;
`__ADDR_SERVER_IP__` (one cosmetic wizard-`config`-command display
line, addr_server support doesn't exist in this driver at all) got
removed outright rather than faked; `__PORT__` needed **no** alias —
it's a compiler-predefined literal on this driver
(`add_predefine("__PORT__", ...)`), and re-`#define`-ing it is a
compile error ("Illegal to redefine a predefined value"), not a no-op.

Detection pattern: a lib bundling its own `runtime_config.h` (common in
archives that shipped with their own driver source) is a standing risk
even when nothing crashes yet — wrong-but-untyped `get_config()`
results (empty strings, 0) fail quietly, but a wrong-and-wrongly-typed
result WILL crash the instant it reaches a typed efun call like
`socket_bind()`, `set_config()`, or similar. Diff the lib's copy against
the driver's canonical header as a matter of course whenever a lib
ships its own — don't wait for a wizard-login crash (or any other
lazy-first-touch call site) to surface it, since — per §7.60/§7.87 — a
throw during a lazy first load often leaves zero trace in `debug.log`.

**Second confirmed instance, sibling lineage, different victim daemon
and NOT wizard-only: `yhwhpublicfi`'s §10.7 deep functional test.**
Same "hell" root lineage as `zjdywzb` (§11 — an independent 2003 fork,
not a later pass on the same archive), same bundled
`include/runtime_config.h` divergence, but an EARLIER pass on this
specific lib had already "fixed" the symptom it found (`versiond.lpc`'s
`in_server()` crashing `socket_bind()`) by gutting that one daemon's
socket calls per §7.52 — without recognizing the header mismatch itself
was the root cause. This deep-test pass found the SAME broken header
also breaks a second, completely different daemon:
`adm/daemons/network/messaged.lpc` (`MESSAGE_D`, a cross-mud UDP chat
daemon that this lib's `tell`/`chat`/"缥缈虚空" chat-room subsystem
depends on for real — not a discardable dead intermud feature). Worse,
the crash site is NOT wizard-gated here: `logind.lpc`'s `check_ok()`
calls `MESSAGE_D->find_chatter(ob->query("id"))` unconditionally for
**every** login (new or returning) that doesn't already have a live/
net-dead body — the very first such login in a boot lazily compiles
`messaged.lpc`, whose `create()` → `startup_udp()` →
`socket_bind(socket_id, my_port)` crashes on the same
`Bad argument 2 to socket_bind() ... Got: "10"` shape (this lib's
`__MUD_PORT__` mis-numbered to the slot the real driver uses for
`__MUD_IP__`, a string that happens to be `""` here, so `"" + 10`
string-concatenates to `"10"` rather than adding to an int). This time,
instead of gutting yet another daemon's sockets one-by-one (whack-a-mole
against however many more daemons might share the same broken header),
the header itself was replaced with the driver's canonical copy — the
correct, root-cause fix this class always called for — with the same
three-symbol reconciliation as `zjdywzb` (`__SAVE_BINARIES_DIR__` →
alias to `__MUD_LIB_DIR__`; `__ADDR_SERVER_IP__` → removed from
`cmds/arch/config.lpc`'s display line; `__PORT__` → no alias needed,
compiler-predefined). One NEW wrinkle worth generalizing: `__BIN_DIR__`
is a real symbol name in the canonical header, but this driver's
`rc.cc` never actually populates that string slot from any config-file
key (checked the `STR_FLAGS` table directly) — `get_config(__BIN_DIR__)`
THROWS, not silently returns empty, even with the canonical header
correctly aliased. Any cosmetic display line referencing a canonical-
but-never-populated slot needs its own `catch()` guard, same as any
other lazy-first-touch call site. Detection generalizes: don't assume
a lib is "done" with this bug class just because one crashing daemon
got patched — grep the WHOLE lib for `get_config(` call sites (not just
the one that happened to crash first) before concluding the header
itself doesn't also need fixing, especially when the first-found victim
is a non-essential daemon that was easy to just gut instead of asking
why its `get_config()` call was wrong in the first place.

### 7.90 `config.fluffos`'s `maximum evaluation cost` is set to this project's common default, but this lib's own NPC-creation cost routinely exceeds it — ordinary movement into any not-yet-compiled room trips a global eval-cost abort and shows every non-wizard player a generic "bug found, report it" message

Found on `xajh4gkb`'s §10.7 deep-dive. WASM-stage testing (registration
only) found zero LPC bugs — the first symptom only appeared once actual
movement was tested. Walking into ordinary, never-before-visited rooms
(no special content, just lazy-compiled NPCs like `d/city/npc/
scavenger.lpc`/`bing.lpc`) repeatedly threw:
```
Eval interrupted: object d/city/npc/bing#265 cost limit reached, limit: 700000 usec.
执行时段错误：*Too long evaluation. Execution aborted.
程式：/feature/skill.lpc 第 17 行
```
Because this driver has `mudlib error handler : 1`, non-wizard players
never see this — the global `error_handler()` in `adm/obj/master.lpc`
downgrades it to a generic "这里发现了臭虫，请用 SOS 指令将详细情况
报告给巫师。" (only wizards get the real stack trace via a `debug`
channel check), so the underlying eval-cost abort is invisible unless
you're grepping `debug.log` or testing as a wizard.

Traced the full call chain (NPC `create()` → `inherit/char/char.lpc`'s
`setup()` → `feature/skill.lpc`'s `set_skill()` → the `file_size()`/
`valid_read()` ACL check) looking for one specific expensive statement
and didn't find a smoking gun — no missing files, no ACL
false-denial-forcing-a-reload (§7.5), no infinite loop. What's
different about this lib: `char.lpc`'s `setup()` has an author-added
block (`//2017.8.5阿飞改，若NPC有技能，统一重置NPC的基础技能与特殊
技能等级`) that iterates every skill an NPC's `query_skills()` already
holds and calls `set_skill()` on each one AGAIN — meaning most NPCs pay
for their own skill-setting cost twice (once in their own `create()`,
once redundantly via this "unify-reset" pass in `setup()`), on top of
whatever real ACL-check cost `set_skill()` already carries. None of that
is unambiguously a single bug to "fix" — it reads as this lib's content
simply being more NPC/skill-setup-heavy than most, colliding with
`maximum evaluation cost : 700000`, the single most common value in
this project (100+ libs use it, largely because it was this project's
own generated `config.fluffos` template default) but one that sits at
the low end of the range libs in this project actually use (300000 up
to 50000000000, per-lib).

Fix: raised `maximum evaluation cost` to `5000000` (already used by 30
other libs in this project) — the exact same class of remedy as §7.87's
`maximum read file size` bump, just for a different resource-limit knob.
Verified live: before the fix, a fixed movement path (`fly yz; w; n; w`
through several never-before-visited rooms) reliably produced multiple
`cost limit reached` aborts every single run. After the fix and a driver
restart, the identical path — same character, same rooms — produced
zero aborts across 12 consecutive movement commands, and `debug.log`
showed no further `cost limit reached` entries for the rest of the
session (including a full combat + death + resurrection cycle).

A harsher variant on `xyj2000f`: `maximum evaluation cost : 400000`
(even lower than the 700000 template default), and the cold compile
that tripped it wasn't ordinary room movement but `make_body()` itself
— `/std/char.lpc`'s first-ever load, pulling in its whole inheritance
chain (`feature/edit`, `feature/finance`, etc.) during ordinary
registration's `get_email()` step. Every single new registration hit
`Eval interrupted: ... cost limit reached` and aborted mid-`make_body()`
with no player-facing error at all (the connection just silently stops
responding right after the email prompt) — 100% reproducible, not the
"only some never-visited rooms" flavor §7.90 first documented. Same
fix, same remedy value (`5000000`); verified by reproducing the abort
in `debug.log` pre-fix, then a full clean registration (past the
former hang point, straight through to gender/gift selection and
entering the world) post-fix with zero further eval-cost entries.

Second confirmed instance, same lineage: `xiyouji450` (a sibling
"mirror-site" release of the same xiyouji.org engine family) shipped
the identical `maximum evaluation cost : 400000`. An earlier pass on
this lib had already hit the exact same `make_body()` abort, but
misdiagnosed it as environmental flakiness ("cold boot, concurrent
driver load") because a retry *within the same driver process*
succeeded — the failed compile attempt had already cached
`/std/char`'s inheritance chain in the process, so later registrations
in that same still-running driver never re-paid the first-load cost
and never re-tripped the limit, masking that a fresh process would
deterministically fail its very first registration every time. Applied
the §7.90 fix proactively before ever registering a character this
round (raised to `5000000`); two independent registrations, each in
its own freshly-booted driver process, both succeeded cleanly on the
first try. Lesson: a first-load eval-cost abort that "goes away on
retry" within one driver session is not evidence it was a fluke — it
just means the expensive compile got cached; test with a fresh driver
restart before concluding no fix is needed.

Fourth instance, unrelated lineage: `xlqy_early` (an ES-II-family "早期
测试版" snapshot, not the xiyouji.org/Tomud family the first three
instances share) shipped `maximum evaluation cost : 500000`, tripped at
boot by `adm/daemons/leveld.lpc`'s `create()` — a genuinely legitimate
nested loop precomputing a per-level exp/道行 table, not a bug in
itself — preloaded from `master.lpc`. One occurrence was severe enough
to bypass even `catch()` (`*Can't catch eval cost too big error.`).
Same fix (`5000000`); confirms this isn't a single-lineage quirk —
check `maximum evaluation cost` on sight for ANY lib, regardless of
engine family, when it's set anywhere near or below this project's
700000 template default.

Fifth instance, unrelated lineage: `zjdyaryl` (ES II → XKX → "hell"
family, not xiyouji.org/Tomud or the xlqy_early ES-II snapshot) shipped
`maximum evaluation cost : 2000000`. Not tripped by registration or
movement, but by ordinary background quest activity: `adm/daemons/
quest/capture.lpc`'s periodic `heart_beat()` spawning a `kungfu/class/
generate/capturenpc3` NPC whose randomly-chosen `setup_family()` branch
(`from_xueshan()`) hit `Eval interrupted: ... cost limit reached, limit:
2000000 usec` mid-`set_skill()`/ACL-check, ~20 minutes into an otherwise
idle boot with no player nearby. Same remedy (`5000000`); confirms the
detection net needs to include a plain `grep -c "cost limit reached"
log/debug.log` after letting a boot idle for a while, not just after
active player movement/registration — a low ceiling can be tripped by
daemon `heart_beat()`s alone.

Sixth instance, unrelated lineage: `xbtxiii` (风云-derived, not any of
the five priors) shipped the project's common `700000` default. Not
tripped by registration or player movement either — caught in
`debug.log` during an otherwise ordinary interactive session,
attributed to `adm/daemons/taskd.lpc`'s `send_task()`/`find_target()`
lazily compiling a not-yet-loaded quest NPC
(`d/shaolin/npc/cheng-xin1.lpc`) as a side effect of the room
(`d/shaolin/banruo1.lpc`) that NPC lives in being populated for the
first time — the player never walked there; `taskd`'s own background
task-matching logic reached the room on its own. Same remedy
(`5000000`); a full subsequent play session (movement, board post,
friendly-spar decline, real `kill` combat, death, full resurrection
sequence, quit, relogin) produced zero further `cost limit reached`
hits. Reinforces the §7.90 lesson from a third angle beyond
"registration" and "movement": a background daemon's own bookkeeping
pass can be the thing that first lazily-compiles an expensive room/NPC,
with no player action anywhere near it — `grep -c "cost limit reached"
log/debug.log` after any extended session, not just after directed
exploration.

Seventh instance, same lineage as the fifth: `xkxc98sj` (another ES II
→ XKX → "hell" family member — §11) shipped the project's common
`700000` default and tripped it immediately at the least-forgiving
point yet seen: character creation's own `make_body()` (via
`logind.lpc`'s `get_gender()`, the very first cold compile of
`inherit/char/char.lpc`'s whole feature-inheritance chain), 100%
reproducible on a completely fresh driver process, every single time —
not a sometimes-flaky "some rooms" or "some background daemon" shape
like the earlier instances, but every new registration dying silently
mid-`make_body()` with no player-facing error at all (same presentation
as the `xyj2000f`/`xiyouji450` instances above, just a different
lineage). Same remedy (`5000000`); verified live with a fresh driver
restart: the identical registration flow (id → password → Chinese name
→ class → gender) that previously aborted with `Eval interrupted:
object adm/single/master cost limit reached` now completes cleanly into
the game world, and a subsequent full session (movement, board,
combat, and two full undisturbed death→resurrection cycles) produced
zero further `cost limit reached` hits in `log/log` (this lib's
`master.lpc` writes compile/runtime diagnostics to a file literally
named `log`, not `debug.log` — see this lib's own NOTES.md).

Detection pattern: don't stop testing at "registration completes
cleanly" — a lib can pass every WASM-stage check and still throw
eval-cost aborts the moment a player actually walks around, because
lazy-compiled room/NPC creation is exactly the kind of bursty, one-time
cost that a registration-only smoke test never exercises. If ordinary
movement (not combat, not a quest, just `w`/`n`/`look`) into new areas
triggers the generic "臭虫"/"bug found" message for a non-wizard
character, `grep -c "cost limit reached" log/debug.log` before assuming
it's a one-off content bug — a whole exploration session producing
several hits, with no single suspiciously-expensive statement in the
traced call chain, points at the config ceiling being undersized for
this lib's content rather than a discrete logic error to chase down.

### 7.91 A one-character skill-name typo in a sect master NPC's `create()` silently deletes that entire sect's join path from the archive's first boot onward

Found on `xajhxo`'s §10.7 deep functional test. `d/menpai/shaolin/npc/
xuanci.lpc` — 玄慈, the Shaolin abbot and the sect's actual
`create_family()` holder — has:

```lpc
set_wugong("shalin-xinfa", 200);   // should be "shaolin-xinfa"
create_family("少林派", 36, "掌门方丈");
```

`shaolin-xinfa.lpc` exists in `system/skill/shaolin/`; `shalin-xinfa`
(missing the "o") does not — a plain authorship typo, not a renamed or
removed skill (confirmed: no other file in the archive references
either spelling). `set_wugong()` on a nonexistent skill throws
(`F_SKILL: No such skill (...)`), and this line sits textually BEFORE
`create_family()` in the same `create()` — so the throw aborts the
function before the abbot is ever registered as his sect's master. Two
compounding effects make this far worse than a typical single-NPC
compile warning: (1) the room-population code that instantiates NPCs on
room load only logs the failure (`创建房间中的物体失败, 详见
room_log`) — the abbot's OWN room shows a normal description with no
NPC in it, no crash the player ever sees; (2) because `create_family()`
never runs, EVERY other Shaolin NPC that gates on "does this sect have a
registered master/family" (here, `huijue.lpc`'s recruiter dialogue)
degrades to a permanently-unsatisfiable prerequisite — the entire sect's
join path is dead from the archive's first boot, not just this one NPC.
Detection: `grep -c "No such skill" log/debug.log` after visiting every
sect's own master/leader room specifically (not just after registration
or ordinary map traversal) — a master NPC failing to spawn produces no
player-visible symptom until someone tries to interact with a
sect-gated feature and gets an unexplained rejection several steps
removed from the actual cause. Fix: correct the one-character spelling
to match the real skill file; verify by re-visiting the NPC's room after
a driver restart and confirming it now appears in the room listing.

### 7.92 `user_cwd()`/`user_path()` assume a letter-sharded wizard-directory layout an archive's `/u/` tree never had

First found on `fy3dz`'s §10.7 deep functional test, confirmed as a
SECOND independent instance on sibling `fy3xd` (same 风云3/Fengyun III
engine family, §11) — worth checking on any remaining sibling
(`zzfy`) too. `adm/simul_efun/path.lpc`:

```lpc
string user_cwd(string name) {
  return ("/u/" + name[0..0] + "/" + name);
}
```

assumes the ES II-family letter-sharding convention (`/u/g/guanwai/`)
seen elsewhere in this project, but these archives' actual `/u/` trees
are flat (`/u/guanwai/`, `/u/palace/`, ...) — confirmed present in the
RAW pre-conversion archive too on `fy3dz`, so it's a pre-existing
mismatch in the original code, not something the conversion pipeline
introduced. Only 2-3 call sites lib-wide (bare `cd` with no argument,
`master.lpc`'s `log_error()`, `path.lpc` itself) — all wizard/admin
paths, so a non-wizard player never notices. Symptoms: bare `cd`
resolves to a directory that never exists for ANY wizard ("没有这个目
录"); chained with a §7.26-shaped `file_owner()` bug in the same file
tree, `log_error()` fails one level further down too
(`/u/g/guanwai/log` instead of `/u/guanwai/log`), so error-logging from
lazy compiles of nested `/u/<wizard>/npc|obj/` content silently goes to
the wrong path. Fix: drop the letter-shard segment —
`return ("/u/" + name);`. Detection: `ls u/` on any newly-picked lib —
if it's flat (no single-letter subdirectories) but `user_cwd()`/
`user_path()` insert one, this bug is present regardless of whether it's
been independently confirmed on that specific archive yet.

### 7.93 An admin "grant sect/skills to a target player" command silently mutates the *caller* instead of the target for one field, because a late edit reused `me` where every other line in the function correctly uses `ob`

Found on `sjtx2`'s §10.7 deep functional test, in THREE copies of the
same file: `cmds/wiz/setparty.lpc` and `cmds/arch/setparty.lpc` (the
live one — `arch` commands shadow `wiz` commands of the same name for
an `(admin)`-level caller, so this is the copy that actually runs) plus
two untouched dated backup copies (`setparty15.lpc`, `setparty18.lpc`).
`setparty <target> <party>` is a wizard shortcut that resolves `ob =
find_player(obj)` (the target) up front, then spends ~380 lines
correctly calling `ob->set(...)`/`ob->set_skill(...)` to grant the
target sect-appropriate stats and skills — except the very last line:

```lpc
default: party = "普通百姓";
}
me->set("family/family_name", party);   // should be ob->set(...)
```

`me` is the admin invoking the command, not the target. Live
reproduction: `setparty sjtxdeep wd` as admin `fluffos` correctly
applied all the stat/skill grants to `sjtxdeep` (combat_exp, neili,
skills, VIP registration) but left `sjtxdeep`'s own `师承`
(sect-membership display) at 普通百姓, while `fluffos`'s OWN character
data was silently flipped to `师承:【武当派】` — a wizard testing tool
corrupting the admin's own save file as a side effect, with the
intended target left without the one field the command exists to set.
Fix: `ob->set("family/family_name", party);` in all three live/backup
copies (the two numbered backups aren't reachable as commands but carry
the identical bug — fixed for consistency since the diff is one word).
This `me`/`ob` transposition — the target object resolved correctly up
top, used correctly everywhere else in a long function, then swapped
for the caller on one late-added or hand-edited line — is a generic
copy-paste risk in any admin "set field(s) on a named target" command,
not specific to sect data; worth grepping any newly-picked lib's
`cmds/{wiz,arch,adm}/set*.lpc` for a bare `me->set(...)` sitting among
otherwise-consistent `ob->set(...)` calls in the same function.

### 7.94 A live command file lost its plain `.lpc` name somewhere along the way, leaving only differently-named draft/backup copies — the command silently doesn't exist

Found on `xyzxfk`'s §10.7 deep functional test: `cmds/usr/` had
`inventory.C` (uppercase extension), `inventory.c.bak`, and a
Chinese-prefixed `复件 inventory.lpc` ("copy of inventory.lpc") — three
different historical implementations of the same command, none of them
named plain `inventory.lpc`. The alias table (`aliasd.lpc`) maps `"i":
"inventory"` as usual, so every `i`/`inventory` invocation resolved to
a nonexistent command file and hit the driver's generic "什么？" (default
fail message) — indistinguishable from a genuine typo unless you
already suspect the command is missing. Confirmed which content was the
intended live file (not a guess among the three candidates) by finding
a byte-for-byte match, module the project's own `.lpc` reformatting, in
`u/isle/ToMud/inventory.lpc` — a working per-wizard sandbox copy
elsewhere in the SAME archive, using the same `CLEAN1`/`ADD1` macros
from `include/tomud.h` that only `inventory.C` (not the `.bak` or
`复件` variant) also referenced. This is what distinguishes the fix
from a content/design judgment call: without an independent matching
copy proving which implementation was "the real one," picking among
three materially different draft implementations would itself be a
content decision outside this project's scope — the fix here is
narrowly "restore the missing filename with content already proven
correct elsewhere in this exact archive," not "choose which feature
set the inventory command should have."

Fix: copy the confirmed-correct content to a properly-named
`inventory.lpc` in the same directory; leave the `.C`/`.c.bak`/`复件`
files untouched (harmless dead backups, not compiled or dispatched).
This is a distinct failure mode from AGENTS.md's `.c`→`.lpc` rename
and GBK-encoding conversion-gap classes (§2, §12) — those are about the
*conversion pipeline* missing a file; this is about the *original
archive* itself already having lost the canonical filename before the
archive was even captured, evidenced by the archive shipping multiple
non-canonically-named candidates side by side. Detection heuristic for
any newly-picked lib: if a command works via `help <name>` (help text
compiles standalone) but the live command itself returns the driver's
default fail message, `find cmds -iname "<name>*"` and check for
sibling files with non-`.lpc` extensions, `.bak`/`.old` suffixes, or
localized "copy of" prefixes before concluding the command was
intentionally removed.

Confirmed a second instance on `xyzx3`'s §10.7 deep functional test:
`cmds/adm/setskill.c.org`, the admin skill-grant shortcut command, was
the ONLY candidate under that name (no competing drafts, so no content
judgment call — narrower than the `xyzxfk` case). Restoring it as
`cmds/adm/setskill.lpc` also surfaced an independent copy-paste bug in
the same file: the single-skill `level == 0` branch's message referenced
the `all`-branch's `skills[i]` array (uninitialized in that code path)
instead of the local `skill` string — a guaranteed runtime error on
`setskill <target> <single-skill> 0`, fixed by using `skill` in that
branch.

### 7.95 A queued `notify_fail()` rejection message never reaches the player because the same code path unconditionally `return`s success right afterward

Found on `xbtxiii`'s §10.7 deep functional test, in `cmds/std/fight.lpc`
(the friendly "讨教/切磋" spar command, distinct from `kill`). The
handler's own `help` text explains that some NPCs will decline a spar
challenge ("并不是所有的 NPC 都喜欢打架"), and the code visibly tries
to say so:
```lpc
notify_fail("看起来" + obj->name() + "并不想跟你较量。\n");
if (!userp(obj) && !obj->accept_fight(me)) return 1;
```
`notify_fail()` only queues a rejection string — the driver's command
dispatcher displays it *only if the eventually-returned value from the
whole `add_action` chain for that input line is 0* (a real failure); if
any handler for the line returns nonzero, the queued message is
discarded unshown, no matter how many times `notify_fail()` was called
along the way. This handler calls `notify_fail()` and then explicitly
`return 1;` (success) on the exact branch where the NPC actually
declined — so the very message meant to explain the decline can
*never* be displayed. Live symptom: challenging an NPC that declines
(here, `d/fy/npc/waiter.lpc`, a friendly shopkeeper) produced the
player's own opening "领教...高招" challenge line and then complete
silence — no acceptance, no rejection, no combat, indistinguishable
from a hang. Confirmed via the surrounding file's own established
idiom: every OTHER rejection path in the same function (missing
target, target not a creature, target already fighting you, etc.) uses
`return notify_fail(...)` — the standard pattern where `notify_fail()`'s
own return value (0) becomes the function's return value, correctly
triggering the queued message. Only this one branch breaks the
pattern by calling `notify_fail()` as a bare statement and then
returning a hardcoded `1` instead of forwarding the 0. Fix: change
`return 1;` to `return 0;` on the declined-spar branch (equivalently,
`return notify_fail(...)` inline) — leaves the accepted-spar path
(which still reaches `fight_ob()`/`return 1` further down) untouched.
Verified live: before the fix, `fight waiter` produced only the
player's own challenge line and nothing else; after the fix and a
driver restart, the identical command produced "看起来店小二并不想
跟你较量。" as intended.

Detection pattern: `notify_fail("...")` followed, in the same
conditional branch, by an explicit `return <nonzero>` (or any codepath
that returns nonzero without going through `notify_fail()`'s own
return value) — the message was written to explain a real rejection,
so the branch should almost always return 0. Cross-check against
sibling branches in the same function: if some already correctly use
`return notify_fail(...)`, a branch that instead calls it as a bare
statement is very likely the same author's mistake, not a deliberate
choice. General lesson beyond this one file: `notify_fail()`'s message
is silently swallowed by ANY successful (nonzero-returning) outcome
for that input line, even one that runs alongside/after the
`notify_fail()` call — this is easy to get backwards when a function
has multiple exit points and only some of them are meant to "fail."

### 7.96 `catch(load_object(path))` is not a reliable "does this room/file exist" existence check on this driver — a nonexistent path returns `0` without throwing, so the `catch()`-guarded fallback branch never runs

Found on `fyzfqyy`'s §10.7 deep functional test, in the very common
`enter_world()` shape:

```lpc
if (! catch(load_object(startroom)))
    user->move(startroom);
else
    user->move(START_ROOM);   // "fallback if the real room is missing"
```

The intent is obvious (if the player's saved `startroom` can't be
loaded, fall back to a known-good `START_ROOM`), but on this driver
`load_object()` on a path with no matching file just returns `0`
silently — no error, nothing for `catch()` to catch — so
`!catch(load_object(startroom))` evaluates true (no exception ⇒
"success") even though nothing actually loaded, and the very next
statement (`user->move(startroom)`, or the same shape inside `->set()`/
`->move()` chains elsewhere) throws its own *different*,
uncaught-by-this-`catch()` error (`*call_other() couldn't find object
'...'` or, one layer further in, `*Bad argument 1 to EFUN call_other()`
once something already holds a `0` "object"). The fallback branch this
code was clearly trying to protect never fires, because the thing
guarding it never fires either. This bit twice in the same lib: once in
`enter_world()`'s own `START_ROOM` fallback (which was itself ALSO
missing, an ordinary content gap — but the fallback logic's inability
to detect that made it crash instead of degrading gracefully), and
independently in a sibling lib's death-room fallback with the identical
shape (`move(DEATH_ROOM)` with no existence check at all).

Fix: use `file_size(path + ".lpc") >= 0` as the existence check instead
of `catch(load_object(path))` — `file_size()` is a plain filesystem
stat, unambiguous, and (per §7.5) already commonly allowlisted for
every ACL in this project. Chain fallbacks as needed (this lib's
`enter_world()` now falls back `startroom → START_ROOM → REGISTER_ROOM`,
each step gated by its own `file_size()` check, since `START_ROOM`
itself is not guaranteed to exist any more than the player's own saved
value is).

Detection for a similar lib: grep for `catch(load_object(` used purely
as an existence test (as opposed to guarding a real nested-compile
hazard like §7.60) feeding an `if (!catch(...)) move(...) else
move(fallback)` branch, and verify live by pointing the guarded path at
something that genuinely doesn't exist — if the "success" branch still
runs and crashes on the subsequent `move()`/`set()`, this is the bug.

### 7.97 A multi-line `#define` mapping literal is missing the line-continuation backslash on its very first line, silently truncating the macro to `([` and leaking the rest of the mapping as raw top-level statements — breaking an unrelated daemon's compile and, from there, permanently aborting death/resurrection mid-sequence

Found on `sjsh`'s §10.7 deep functional test, while deliberately fighting
an NPC to death to exercise the resurrection cycle. `kill`ing an NPC
(`d/city/npc/jieding.lpc`/`bonze.lpc`, both wandering 疥顶小僧/和尚 in
朱雀大街) to a normal, undisturbed death produced a *repeating* "你死了"
message — the exact same death line firing over and over, forever, on
every subsequent heartbeat tick, with no ghost stage, no death-gate
room, no resurrection NPC ever appearing. `debug.log` showed the real
cause on the very first death:
```
执行时段错误：*No program in object '/adm/daemons/network/dns_master'!
程式：/adm/daemons/network/services/gchannel.lpc 第 36 行
呼叫来自：/std/char.lpc 的 heart_beat() 第 79 行
呼叫来自：/feature/damage.lpc 的 die() 第 349 行
呼叫来自：/adm/daemons/combatd.lpc 的 killer_reward() 第 1238 行
呼叫来自：/adm/daemons/channeld.lpc 的 do_channel() 第 341 行
呼叫来自：/adm/daemons/network/services/gchannel.lpc 的 send_msg() 第 36 行
```
`dns_master.lpc` itself failed to compile with `include/net/config.h:21:4:
error: syntax error, unexpected L_STRING`. Root cause, in
`include/net/config.h`:
```lpc
#define LISTNODES ([ 
"SK": "61.141.216.74 6668", \
"BJ": "61.150.127.254 6668", \
"SD": "61.137.138.166 6668", \
     ])
```
Line 1 (`#define LISTNODES ([`) has **no trailing `\`**, while every
following line does. The C preprocessor treats a `#define` body as
ending at the first line lacking a continuation backslash — so
`LISTNODES` silently expands to the incomplete literal `([` and lines
2-4 (`"SK": "...", \` etc.) are NOT part of the macro at all; they leak
into whatever file `#include`s `net/config.h` as bare top-level LPC
statements, which the compiler rejects outright. `dns_master.lpc` never
compiles as a result — but because that failure happens lazily, at
whatever moment something first calls into `DNS_MASTER` (here, the
public death-announcement broadcast in `gchannel.lpc::send_msg()`, itself
called from `channeld.lpc`'s ordinary "系统频道" relay, from
`combatd.lpc::killer_reward()`, from `feature/damage.lpc::die()` at the
exact line where a dying player's kill gets announced), it surfaces as
an uncaught runtime error deep inside a completely unrelated subsystem
—nowhere near the actual broken file. Because nothing between
`killer_reward()` and `die()`'s call site catches the error, the throw
unwinds `die()` entirely: everything AFTER line 349 — resetting
`kee`/`eff_kee`/`sen`/`eff_sen` to 1, moving the corpse-shedding player
into `DEATH_ROOM`, starting the judge-NPC resurrection dialogue — never
runs. The character's `eff_kee`/`eff_sen` stay at their fatal
(negative) values forever, so `heart_beat()`'s own `my["eff_kee"] < 0 ||
my["eff_sen"] < 0` check re-fires `die()` on literally every subsequent
tick, forever, with the exact same crash each time — a permanent,
unrecoverable death loop stricter than the §7.68 stuck-ghost class:
here the player never even reaches the ghost stage, let alone a
recoverable one. Fix: add the missing backslash —
```lpc
#define LISTNODES ([ \
"SK": "61.141.216.74 6668", \
```
Verified live: before the fix, a deliberate `kill` to death repeated
"你死了" indefinitely with the `dns_master`/`gchannel` crash trace on
every tick and the character permanently un-resurrectable; after the
fix and a driver restart, an identical `kill`-to-death on a fresh
character produced the public death broadcast cleanly (`【三界神话】
某人：紫电仙人在长安城被和尚杀死了。`), moved the character to
`〖阴阳界〗` (the death gate), the judge NPC 崔珏 ran its full
生死簿/画押/还阳 dialogue, and the character landed alive (albeit
`重伤`/badly-wounded) in the revival room `〖荒郊小店〗` — the complete
cycle, no crash, one clean `你死了`.

Detection pattern: grep any lib's `#define NAME (...` (or `({...`,
`([...`) for a multi-line macro whose FIRST line ends without a
trailing `\` while later lines have one — this is a strict subset of
the already-cataloged "stray backslash mangles a string literal"
class (see the `convertd.lpc` Greek-table note in §6 and the entry
this document keeps under §7.13's neighborhood), but inverted: instead
of an accidental backslash breaking a string, a MISSING backslash
breaks the macro's line continuation itself. The daemon that fails to
compile is often a cosmetic-sounding one (DNS/intermud service tables
are exactly the kind of file nobody boots into interactively), so the
failure can sit dormant for a long time — it only becomes visible the
moment some ordinary, unrelated player action (here: literally just
dying once) happens to call into it. When a `heart_beat()`-driven
crash trace mentions a network/intermud daemon (`dns_master`,
`gchannel`, `mudlist_*`) crashing something that looks completely
unrelated (death, chat, a channel broadcast), check that daemon's own
`#include`d headers for a truncated multi-line macro before assuming
the crash lives in the calling code.

### 7.98 A daemon's `create()` reads its own config file/table before ever calling `seteuid()`, so a custom `securd.lpc`-style ACL denies the read as if the object had no privileges — and the resulting crash trace points at `explode()`/`sscanf()`, not at the real permission problem

Found on `hy`'s §10.7 deep functional test, in the very first seconds of
boot (well before any player connects): `debug.log` showed two
back-to-back crashes during preload,
```
执行时段错误：*Bad argument 1 to explode()
Expected: string Got: 0.
程式：/adm/daemons/questd.lpc 第 698 行
呼叫来自：/adm/daemons/questd.lpc 的 create() 第 39 行
呼叫来自：/adm/daemons/questd.lpc 的 read_table() 第 698 行
```
and an identical shape in `adm/daemons/natured.lpc`'s `create()` →
`read_table()` → `explode(read_file(file), "\n")`. Both crash traces
look exactly like this project's well-known §7.9 "missing file" class
(`read_file()` on a nonexistent path returns `0`, and an unguarded
`explode()`/`sscanf()` on that `0` throws "Bad argument 1") — but
`/quest/dynamic_quest` and `/adm/etc/nature/day_phase` were BOTH
present on disk at their expected sizes. The real cause: `read_file()`
is itself subject to the mudlib's custom `valid_read()` ACL (func
`"read_file"`), and neither daemon calls `seteuid()` anywhere in its
own source — at the exact moment `create()` runs during preload, the
object's own effective uid is unset (falsy), so `securd.lpc`'s
`valid_read()` hits its `if (!euid) return 0;` fallback and silently
denies the daemon's read of its OWN config file. `read_file()` then
returns `0` exactly as if the file didn't exist, and the crash surfaces
one level downstream, inside whatever parse function is unlucky enough
to call `explode()`/`sscanf()` on the result — nowhere near the actual
missing ingredient (a `seteuid()` call). This is the mirror image of
§7.5: where §7.5 is about the ACL wrongly denying harmless
compile-time/existence checks (fixable by broadening the ACL's
allowlist), this is about a daemon that genuinely SHOULD be
authenticated failing to authenticate itself before touching privileged
data — the correct fix is on the daemon's side, not the ACL's.
Confirmed nothing else in this lib's `adm/daemons/*.lpc` shares the
bug: grepping every daemon file for `read_file(`/`read_table(` while
having zero `seteuid` calls anywhere in the same file turned up
exactly these two. Fixed by adding `seteuid(ROOT_UID);` as the first
line of each `create()`, matching the same defensive pattern this
lib's own `logind.lpc` already needed in three other places (see its
`README.md`). Verified live: before the fix, boot.log showed the two
`explode()` crashes every single boot, `quests`/`day_phase` silently
stayed empty (breaking the dynamic-quest system and, per this
project's established §7.9 "empty collection" lesson, risking a
downstream `sizeof()-1`/modulo-by-zero the moment anything indexes
`day_phase[current_day_phase]`); after the fix, a clean reboot showed
neither crash and both tables loaded with their real content.
**Detection pattern**: a `*Bad argument to explode()/sscanf()` crash
during PRELOAD (before any player has connected) whose file argument
genuinely exists on disk (`ls -la` it before assuming §7.9 applies) is
the tell — grep the crashing daemon for `seteuid` first; if it has
none, the custom ACL is almost certainly denying its own
`read_file()`/`get_dir()` calls, not reporting a missing file. Same
family as §7.5's `"stat"` variant (also `hy`, same session) — a custom
`securd.lpc` can break either side of the same problem: over-denying
harmless operations from *other* not-yet-authenticated objects (§7.5),
or under-authenticating a *privileged* daemon that never bothered to
`seteuid()` itself before doing legitimate privileged work (this
entry). Check both whenever one shows up.

**Confirmed instance: `hy5`** (a distinct-but-related codebase — `master.lpc`
is byte-identical to `hy`'s, but `securd.lpc` is an independently-shaped
rewrite, confirmed via diff before assuming anything carried over
unmodified). Same exact crash shape at the same two files,
`adm/daemons/questd.lpc` (`create()` → `read_table()` → `explode(read_file(...))`
at a different line number than `hy`'s) and `adm/daemons/natured.lpc`,
both missing `seteuid()` in `create()`, both fixed the same way. A third,
previously-unseen variant surfaced in the same lib: `adm/daemons/bgift.lpc`
has no `create()` at all (so no chance to `seteuid()`) and calls
`read_file()` from `killer_rewardboss()`, a function that only runs when a
player kills a specific "boss" NPC with a treasure-drop reward key — this
is the same underlying bug (an un-authenticated daemon touching
`read_file()`), but the trigger is a live PLAYER ACTION, not preload, so it
would never show up in a boot-log scan at all, only via actually killing
the right kind of NPC or via a static grep for `read_file`/`read_table`
call sites with zero `seteuid` anywhere in the file. Fixed by adding a
`create() { seteuid(ROOT_UID); }` to `bgift.lpc` where none existed
before. **Broadened detection pattern**: don't limit the "daemon missing
`seteuid()`" grep to files with a `create()` that runs at preload — some
daemons only touch `read_file()`/`read_table()` from a function reachable
solely through in-game player actions, and still need the same fix.

### 7.99 A `file_size()` existence-check guard added ahead of a case-mismatch-sensitive `new()`/`load_object()` call is a false negative for legitimate EXTENSIONLESS paths, because `file_size()` does a literal `stat()` with no `.lpc`/`.c` resolution, unlike `new()`/`load_object()`

Found on `sjshwzjqb`'s §10.7 deep functional test, while porting sibling
`sjshwzb`'s own §8.15 fix (a `carry_object()` helper in `std/char/npc.lpc`
guarded against loading a case-mismatched/missing item path with `if
(file_size(file) < 0) return 0;` before the `file->query_unique()` call
that would otherwise throw — see §8.15). Applying the byte-identical fix
here produced a NEW crash the very first time a fresh character entered
the starting room: `d/ourhome/npc/bigeye.lpc` (千里眼, the mail-hint NPC)
crashed in its own `create()` at `carry_object("/d/ourhome/obj/linen")->
wear();` with `*Bad argument 1 to EFUN call_other() Expected: object,
string, array, Got: int(0)` — even though `/d/ourhome/obj/linen.lpc`
genuinely exists on disk, correctly cased, at exactly that path. Root
cause: `file_size()` (`fluffos/src/packages/core/file.cc`) calls
`check_valid_path()` then a plain `stat()` on the LITERAL string passed
in — it does **not** perform the `.lpc`-then-`.c` extension resolution
that `new()`/`load_object()` do for an extensionless path. `bigeye.lpc`
passes `"/d/ourhome/obj/linen"` with no extension (the normal, idiomatic
way to reference an item in this codebase — the SAME file's own
`add_money()` helper does the identical thing via `carry_object("/obj/
money/" + type)`), so `file_size(file)` on that literal returns `-1`
even though the file is right there as `linen.lpc` — the newly-added
guard returns `0` for a perfectly good item, and the caller's `->wear()`
on that `0` crashes exactly the same way the original bug (an actually-
missing file) did, just for a different, much more common reason. This
is a regression risk inherent to the §8.15 fix'S OWN SHAPE, not specific
to this lib — any lib porting that same `carry_object()` guard is
exposed to it the moment any caller passes an extensionless path to an
item that legitimately exists, which on this codebase family is the
common case, not the exception. Fix: check all three forms before
concluding the file is genuinely missing —
```lpc
if (file_size(file) < 0 && file_size(file + ".lpc") < 0 &&
  file_size(file + ".c") < 0) return 0;
```
Verified live: before this refinement, a fresh character's first `look`
in the starting room (〖南城客栈〗) crashed loading `bigeye.lpc` on every
single registration/reconnect; after it, the same room populated cleanly
with `千里眼` present, `add_money()`-driven money grants and clothing
`wear()` calls both worked normally across a full registration →
combat → death → resurrection → board-post session with zero further
`call_other()`/`int(0)` errors in `debug.log`.

Detection pattern: whenever adding a `file_size()`-based (or any other
literal-`stat()`-based) existence guard ahead of a `new()`/`load_object()`
call that historically accepted extensionless paths, grep the SAME guard
function's other call sites (and sibling helpers like `add_money()`) for
extensionless callers before shipping the guard — a guard that's
correct for the ONE call site that motivated it can silently break every
OTHER extensionless caller of the same shared helper. More generally:
`file_size()`/`stat()`-family efuns and `new()`/`load_object()`-family
efuns resolve paths under DIFFERENT rules on this driver (literal vs.
extension-searching) — never assume a `file_size()` check ahead of a
`new()` call is an equivalent, side-effect-free existence probe for it.

---

### 7.100 (IDENTIFIED, ONLY PARTIALLY FIXED — too large for one pass) §7.86's "redundant self-`replace_program()`" shape recurs on the universal `ROOM` base class itself, not just boards — turning nearly every room in the archive into a dormant closure-crash landmine

Found on `jhfy3`'s §10.7 deep functional test. §7.86 documented a fatal
`replace_program()` misuse (`inherit X;` immediately followed by a
redundant, no-op-but-harmful `replace_program(X);` in the same file's
`create()`) that permanently blocks any later attempt to bind a closure
to that object's own lfuns — confirmed on `BULLETIN_BOARD`/`BBS_BOARD`
across six unrelated lineages, always breaking the board's `post`
command specifically. `jhfy3` has that exact shape too (a handful of
already-`//`-commented-out board instances, harmless) — but it ALSO has
the identical shape on `ROOM` (`/inherit/room/room`, `#define ROOM
"/inherit/room/room"` in `include/globals.h`), the base class nearly
every single room object in the archive inherits: `grep -c
"replace_program(ROOM)"` across `work/` returned **5,717 matches**, of
which only 124 were already commented out — **5,591 live, standalone
`replace_program(ROOM);` calls**, roughly 60% of this ~9,300-file
archive. Confirmed this is not theoretical: an ordinary room visit
during a routine post-registration walk (`/d/city/xxci1.lpc`, a room
with nothing unusual about it) produced a live `debug.log` line at
first load — `d/city/xxci1.lpc: cannot replace a program with function
references, ignored` — a DIFFERENT, non-fatal driver message than
§7.86's board crash, because this room happens to call `create_door()`
(which does `set("item_desc/" + dir, (: look_door, dir :));` — a
closure bound to `this_object()`) BEFORE its own `replace_program(ROOM)`
line runs in `create()`; the driver detects the already-pending
function reference at replace-time and safely REFUSES the replace
rather than performing an inconsistent one, so this specific room
never actually breaks. That refusal is the exception, not the rule:
any room that does NOT create a closure before its `replace_program(ROOM)`
call (the vast majority — `create_door()` is only used by rooms with
doors) gets a SUCCESSFUL, silent replace at boot time, which sets the
same permanent "pending replace" flag §7.86 documented — and that
object will crash exactly like a §7.86 board the first time ANYTHING
later in its lifetime binds a closure to itself (a `set("item_desc/...",
(: ... :))` added outside `create_door()`, an `edit()` call, a
`call_out()` closure argument, a custom `input_to()` callback bound to
the room, etc.) — the same "everything works until the one command that
creates a closure" signature as the original board bug, just spread
across the single most common object class in the entire lib instead of
one board file per zone.

**Compounding discovery**: the exact same broken `create()` shape is
baked into this lib's own in-game room-building tool,
`clone/misc/roommaker.lpc` (byte-identical duplicate at
`u/fyue/misc/roommaker.lpc`) — in TWO separate places: a heredoc
(`@ROOM_CODE ... ROOM_CODE`) template for its "make an empty room"
command, and a `str += "...replace_program(ROOM);..."` string-builder
for its "clone the room I'm standing in" command. Every room any
player or wizard ever built with this in-game tool was therefore born
with the same dormant landmine already inside it — this is the
`sje`-precedent "the bug lives in the factory, not just the shipped
content" shape (see §7.86's fourth confirmed lineage writeup).

**Scope decision**: given the fix is the exact same one-line-deletion
pattern already validated safe across six §7.86 lineages (delete the
redundant `replace_program(X);` line, keep the `inherit`), a scripted
sweep across all 5,591 live occurrences was attempted but declined by
this session's own execution-safety tooling as too broad an automated
bulk-rewrite to approve in one shot — consistent with this project's
own standing rule against deriving a mass action from a broad
tree-wide scan (§10.5's `git status`-derived-deletion-list lesson,
same shape applied to a mass *edit* instead of a mass *delete*). Fixed
in this pass, individually reviewed: the one file with LIVE observed
evidence (`d/city/xxci1.lpc`), both copies of the room-building tool's
TWO code-generation templates (`clone/misc/roommaker.lpc`,
`u/fyue/misc/roommaker.lpc` — so newly-built rooms stop inheriting the
bug going forward), plus three more spot-fixed as a pattern check
(`d/mingjiao/maowu.lpc`, `d/quanzhou/nanhu.lpc`,
`d/xiangyang/qianzhuang.lpc`). **The remaining ~5,585 room files are
UNFIXED** — left as a known, large, mechanically-simple but
individually-unverified backlog for a dedicated future sweep session
(ideally run in explicit, hand-reviewed batches rather than one
tree-wide script, per the scope decision above). All six fixed files
verified via `update <path>` recompiling successfully post-fix, and
`xxci1.lpc`'s "cannot replace a program... ignored" warning confirmed
gone from a fresh boot's `debug.log`.

Detection pattern: `grep -c "replace_program(ROOM)" work -r --include=
"*.lpc"` (substitute the lib's own room-base-class macro, found via
`grep 'define ROOM' include/*.h`) on ANY lib already known to carry
§7.86's board-file shape — if the count is in the thousands rather than
the tens, the bug has very likely also colonized the room base class,
not just boards, and deserves a dedicated sweep pass of its own rather
than being folded into a single §10.7 session. `jyqxc`/`jyqxc2` (XKX/
金庸群侠传 framework family, unrelated to `jhfy3`) both carry the same
`inherit ROOM; ... replace_program(ROOM);` shape at a smaller but still
substantial scale (845 occurrences, 804 live) — checked during
`jyqxc2`'s own §10.7 pass, `debug.log` showed zero "cannot replace a
program" lines across a full registration→combat→death→board→mailbox
session, so no live trigger was ever observed and, per this entry's own
scope decision, no sweep was attempted; left as an unconfirmed-but-
plausible backlog item for whoever next does a dedicated pass on this
family. Also check any in-lib
room/NPC/item content-generation tool (`roommaker`, `npcmaker`,
`objmaker`, etc.) for the same shape baked into its own output
templates — a factory bug compounds silently every time a player uses
the tool.

**SWEEP COMPLETE (11 batches)**: the ~5,585-file jhfy3 backlog
described above is now fully closed out. Worked off in eleven batches,
each independently boot-tested (native debug driver, existing seeded
admin account, `goto` into 8-10 rooms drawn from that batch, clean
`debug.log`) and committed/pushed separately: batch 1, 508 files,
`1b18f1ce550`; batch 2, 520 files, `a199792470c`; batch 3, 520 files,
`3e273269ab5`; batch 4, 550 files, `62147942e9c`; batch 5, 550 files,
`caa774e425a`; batch 6, 481 files, `60446dfce1c`; batch 7, 522 files,
`17d7b6565db`; batch 8, 501 files, `2d0951fbf72`; batch 9, 559 files,
`72085ed5259`; batch 10, 550 files, `13fae17062e`; batch 11 (final),
324 files, `50f6701eec2`. Grand total: **5,585 files fixed** across all
eleven batches (508+520+520+550+550+481+522+501+559+550+324). A final
post-batch-11 sweep confirms 0 live `replace_program(ROOM);`
occurrences remain in `work/` — the only 124 remaining matches are
pre-existing, already-`//`-commented-out instances (harmless, and
intentionally left untouched, consistent with every prior batch).

### 7.101 A room's `exits` mapping omits directions its own `valid_leave()` still has full logic for, making the shared movement dispatcher reject the command before `valid_leave()` ever runs — silently disabling this codebase's entire death-recovery mechanism

Found on `kxkjii2`'s §10.7 deep functional test (ES II/Annihilator
lineage). This engine's generic movement command,
`cmds/std/go.lpc`, gates on the room's OWN `exits` mapping before ever
consulting `valid_leave()`:
```lpc
if (!mapp(exit = env->query("exits"))) { ...; return 0; }
...
if (undefinedp(exit[arg])) {
  if (repeat >= 1) me->force_me("look");
  return 0;
}
...
if (!env->valid_leave(me, arg)) return 0;
```
— a direction that is not a KEY in `exits` is rejected outright
(`"什么? south? 请用 help cmds 查询指令。"`, indistinguishable from a
genuinely nonexistent command) with `valid_leave()` never called at
all. `open/death/start.lpc` (the room every dead player lands in,
`阴曹入口`) sets:
```lpc
set("exits", ([ /* sizeof() == 3 */
  //  "up" : "/open/common/room/inn",
  //  "south" : "/open/common/room/inn",
  "north": __DIR__ "bridge1",
]));
```
— only `"north"` is a real key, but `valid_leave()` a few lines down
has a full, working implementation for BOTH `"south"` (a "do you
really want to go home" random-5-to-9-attempt gate) and `"up"` (the
actual payoff: `reincarnate()` + `move()` back to the world, printing
"恭禧你又重回人世了"). Because `go.lpc` never reaches `valid_leave()`
for either direction, both branches are 100% dead code and every
single player death in this codebase was a permanent, unrecoverable
dead end — the ONLY listed exit, `"north"`, leads deeper into an
unfinished side zone (`open/death/road2.lpc`/`road3.lpc`, the latter's
own `long` text literally reading "路的尽头 ..... 还没想到 ...." — "end
of the road, ... haven't figured it out yet ...", the original 2002
author's own placeholder) that dead-ends at a ONE-WAY gate
(`open/death/gate.lpc`'s `valid_leave()` unconditionally blocks
`"south"` once entered: "进了鬼门关就别想回去了！"). A player who
died and didn't know to try wizard-only commands had no way back
except `suicide -n`/`suicide -f` (self-destructing the character) or a
wizard's manual `goto`/`transfer` rescue. The comment `/* sizeof() ==
3 */` immediately above the mapping, plus the commented-out values
being byte-identical to the `REVIVEROOM` macro in `include/login.h`
(`"/open/common/room/inn"`), are strong evidence these two lines were
the original, correct configuration and got disabled by accident (or
an abandoned debug shortcut), not an intentional design choice.
Byte-identical file confirmed on sibling `kxkj` (`diff` clean) — same
bug present there too, unfixed as of this pass; port the same
two-line uncomment next time `kxkj` is touched.

Fix: uncomment the two lines. Verified live: killed a test character
(real death via `fight dog` in `d/snow`, not a scripted event), landed
at `阴曹入口` with only `north` listed; before the fix, `south` and
`up` were both rejected as unrecognized commands and `look` never
listed them as exits. After uncommenting and `update`-ing the file
live, `look` showed all three exits, `south` × 6 produced the
"你真的那么想回家吗？" threshold message, and `up` completed the full
cycle — "突然天中降下一团祥光...你终于从阴间偷跑回来了。" — landing
the character back at `STARTROOM` with `score` confirming intact
stats. `debug.log` stayed clean throughout (no crash — this bug's
signature is silent unreachability, not an error).

**Distinguish from §7.68/§7.76**: those are about a `call_out()`
chain (the classic `wgargoyle`/`bgargoyle` "白无常/黑无常" NPC dialogue
sequence, also present in this same lib, gated on `present(ob)` or a
stale `REVIVE_ROOM` path) abandoning its subject mid-sequence or on
its final step. This bug is upstream and unrelated to that
machinery entirely — it's a player-typed movement command being
rejected by the shared dispatcher before any death-specific code runs,
in a completely different room using a completely different (`exits`-
map-driven) recovery idiom. `kxkjii2`'s own `wgargoyle`/`bgargoyle`
chain was separately observed to correctly skip wizard-level accounts
(`wgargoyle.lpc`'s `init()` explicitly checks `!wizardp(previous_object())`)
— consistent with this project's established, deliberate
admin-exclusion pattern, not re-flagged here.

Detection pattern: on any ES2-family (or similar `exits`-map-gated
`go.lpc`) lib, grep death/resurrection rooms for a `valid_leave()`
branch on a direction string that does NOT also appear as a key in
that same file's `set("exits", ...)` call — especially a commented-out
exits entry sitting directly above an active one, or a `/* sizeof() ==
N */` comment whose N doesn't match the mapping's actual live key
count. Always drive a full, undisturbed death cycle to the point of
actually typing every documented recovery command and confirming
`look` lists it as a real exit — reaching the death room and seeing
dialogue play is not sufficient; the FINAL escape step is exactly
where this class of bug hides.

### 7.102 The shared movement dispatcher's own force-load of an exit's destination is unguarded, so ANY stale/missing exit target anywhere in the archive dumps a raw driver traceback to the player instead of a normal rejection

Found on `zzfy3`'s §10.7 deep functional test (风云3 engine family,
sibling `zzfy`, §11). `cmds/std/go.lpc` (the ONE command every typed
movement direction goes through) force-loads an exit's destination room
before checking it actually loaded:
```lpc
dest = exit[arg];

if (!(obj = find_object(dest)))
  call_other(dest, "???");
if (!(obj = find_object(dest)))
  return notify_fail("无法移动。\n");
```
When `dest` doesn't exist as a file at all (not a compile failure, a
genuinely missing path), `call_other()` **throws** an uncaught
`*call_other() couldn't find object '<dest>'` straight out of the
dispatcher — the driver's own runtime error handler intercepts it (this
codebase's `master.lpc` dumps the FULL traceback, program name, line
numbers, and call stack straight to the offending player, wizard or
not — see §7.103), but the command itself aborts mid-execution with no
`notify_fail()` shown, leaving the player staring at a raw stack trace
instead of an ordinary "you can't go that way" message. Distinct from
§7.25 (which covers a room's own `create()`/`reset()` force-loading a
companion object like a board): this is the SHARED, universal command
every single exit in the whole archive is dispatched through, so any
one stale/renamed/never-shipped room reference anywhere in the map hits
this same crash, not just one room's own population helper. Reproduced
live: `/d/fy/fqkhotel.lpc`'s `"新手学堂"` exit — the very first thing
the starting inn's own waiter NPC tells every brand-new player to
type — points at `/d/newbei/wel1`, a newbie-academy zone that does not
exist anywhere in this archive (confirmed via `find`; a genuine
missing-content gap, not a typo'd path to real content, so not
"fixed" by fabricating the zone). Sibling `zzfy` carries the byte-
identical `go.lpc` and the byte-identical broken `"新手学堂"` exit,
unfixed as of this writing — the bug was never noticed there either,
since that lib's own §10.7 pass didn't happen to try that specific
exit.

Fix: `catch()` the force-load and degrade to the same friendly
rejection already used for a confirmed-missing exit:
```lpc
if (!(obj = find_object(dest))) {
  if (catch(call_other(dest, "???")))
    return notify_fail("无法移动。\n");
}
if (!(obj = find_object(dest)))
  return notify_fail("无法移动。\n");
```
Verified live: post-fix, taking the same broken exit now shows a
caught-error trace (this codebase's standard "错误讯息被拦截" caught-
error convention, matching every other `catch()`-guarded fix in this
project) followed by the normal `"无法移动。"` rejection, and the
command dispatcher continues functioning normally afterward — confirmed
by successfully moving/fighting/dying/resurrecting in the same session.

Detection pattern: on any lib whose shared movement command force-loads
an exit's destination via a bare `call_other(dest, "???")` (or
equivalent) before confirming `find_object()` succeeded, grep every
room's `set("exits", ...)` values against `find`/`file_size()` for a
target that doesn't exist in the archive — especially exits mentioned
by an NPC's own dialogue (a "go here for X" hint), since those are the
ones a real newbie is most likely to actually type.

### 7.103 `master.lpc`'s runtime error handler dumps plain compile WARNINGS (not just genuine errors) straight to every ordinary player's screen, on nearly every lazily-compiled file

Found on `zzfy3`'s §10.7 deep functional test, same 风云3 engine family
as §7.102. `adm/obj/master.lpc`'s `log_error()` — called by the driver
for every compile diagnostic, warnings included — writes the message to
`this_player(1)` unconditionally:
```lpc
if (this_player(1)) efun::write("编译时段错误：" + message + "\n");
```
`this_player(1)` on this driver returns the raw current player
regardless of wizard status (it bypasses shadows, not privilege), so
**every** connected player — not just staff — sees a raw
`"编译时段错误：...warning: Unused local variable 'x'"`-style dump
every time ANY file with an unused-variable/unknown-`#pragma`/similar
warning gets lazily compiled for the first time this boot, which in
practice is nearly every room/NPC/command file touched during ordinary
play (confirmed live: dozens of these fired during a single
registration + a few room visits). This isn't a leftover developer
`printf()` (§7.34's shape) — it's the mudlib's own permanent error-
reporting policy simply never distinguishing "warning" from "error"
before deciding what a non-wizard should see. Sibling `zzfy` already
carries the fix independently (found via diff during this lib's own
lineage check):
```lpc
if (this_player(1) && strsrch(message, "warning:") == -1) efun::write("编译时段错误：" + message + "\n");
```
Fix: port the same `strsrch(message, "warning:") == -1` guard — genuine
errors (which don't contain the literal substring `"warning:"`) still
reach the player exactly as before; plain compile warnings are silently
dropped from the player-visible stream (still `write_file()`'d to the
per-owner log either way, for wizards to find later). Verified live:
post-fix, the same registration + movement flow that previously spammed
warning text produced none, while a real caught runtime error
(§7.102's fix, deliberately re-triggered) still showed its
"错误讯息被拦截" trace correctly.

Detection pattern: on any lib whose master.lpc/securityd-style
`log_error()` writes compile diagnostics to `this_player()`/
`this_player(1)`, check whether the write is gated on the message NOT
containing `"warning:"` (or an equivalent severity check) — if not,
every ordinary player is seeing raw compiler warning spam on ordinary
lazy-compiles, not just genuine errors. Cheap to confirm live: register
a fresh character and watch for `"编译时段错误：...warning:"`-prefixed
lines appearing unprompted during normal movement.

### 7.104 A new-account "must stay online 30 minutes or your account is revocable" policy's AUTOMATIC (netdead-timeout) cleanup path silently deletes the account with no confirmation, even though the INTERACTIVE quit path for the exact same policy requires an explicit y/n

Found on `nte`'s §10.7 round-two deep functional test (nitan/ES2-family
infrastructure shared with `ntii`) — and not found by code review, by
actually getting bitten by it: the pass's own first test character was
silently deleted mid-session because repeated `mudclient.py` connect/
disconnect cycles (each ending the TCP connection without an explicit
`quit`) accumulated past the driver's `NET_DEAD_TIMEOUT` (900s/15min),
triggering `net_dead()` → `user_dump(DUMP_NET_DEAD)` →
`QUIT_CMD->force_quit()`.

The interactive `quit` command (`cmds/usr/quit.lpc`'s `main()`) enforces
this lib's "new accounts must accumulate 30 real minutes online before
they're permanent" policy correctly: it detects `mud_age < 1800`,
prints the account-loss warning, and requires an explicit `y` via
`input_to((: confirm :), me)` before doing anything destructive — `n`
(or anything else) just cancels. But `force_quit()`, invoked by the
*automatic* netdead-timeout path (no player present to answer any
prompt), applied the exact same "<30 minutes → delete" rule
unconditionally:
```lpc
if (me->query("mud_age") < 1800 && !me->query("jieti")) {
  UPDATE_D->remove_user(me->query("id"));
  return 1;
}
me->save();
```
i.e. it treated "the connection dropped" as equivalent to an explicit
`y` confirmation — the one outcome the interactive path's confirmation
prompt exists specifically to gate. A flaky client, a brief network
blip, or (as here) a test harness that reconnects rather than issuing
`quit` all silently destroy a legitimate new account with zero warning
and zero chance to object. Fix: delete the unconfirmed branch entirely;
fall through to the same safe `save()` + `move(VOID_OB)` +
`destruct()` cleanup already used for accounts ≥30 minutes old — a
disconnected new account keeps its data exactly like an established one
does, and only the interactive path (which can actually get consent)
is allowed to delete a sub-30-minute account.

Verified live: registered a fresh account, then called
`ob->user_dump(1)` directly (the exact `DUMP_NET_DEAD` code path a real
15-minute-timeout disconnect takes) from a wizard session — pre-fix,
this deleted both save files (`data/login/`, `data/user/`); post-fix,
the identical call left both files intact.

Detection pattern: on any lib with (a) a "new account must stay online
N minutes or is revocable" policy enforced via an explicit y/n prompt
in the interactive `quit` command, AND (b) a `net_dead()`/netdead-
timeout auto-cleanup path (`user_dump(DUMP_NET_DEAD)` or equivalent)
that reuses the same account-age check — diff the two code paths' age
check against what happens next. If the automatic path calls a
`remove_user()`/delete-style function directly instead of falling
through to the ordinary safe-disconnect save, it's destroying accounts
that never got a chance to consent. Likely to recur across the whole
ES2/nitan lineage family (any sibling with this same "new account
retention" mechanic) — not yet swept, check on next contact.

### 7.105 A lib's own safe-sparring training-dummy NPC never sets the flag its shared `fight`/`hit` commands gate real-vs-mock combat on, so every "safe" spar routes through genuine lethal `kill_ob()` instead

Found on `tianxiawuxue`'s §10.7 deep functional test, by doing exactly
what the methodology's own checklist item 3 recommends — finding the
lib's documented safe-sparring mechanism before risking a real fight.
`d/shaolin/npc/mu-ren.lpc` (and 8 sibling copies across other zones — a
`mu-ren`/`muren` training dummy) has an elaborate, obviously
purpose-built `accept_fight(object ob)` override: it copies the
attacker's own skills/stats onto itself, sets `"no_die": 1`, and tracks
`fight_times` so it "breaks" after repeated use rather than ever dying
— matching `help combat`'s own promise that `fight`/`hit` never cause
real death. A **fresh, unequipped, level-0 test character died outright
on the dummy's second exchange** (`你口中喷出几口鲜血，倒在地上,死了！`).

Root cause: `cmds/std/fight.lpc`'s `main()` (and `cmds/std/hit.lpc`,
identically) only calls `obj->accept_fight(me)` inside `if
(obj->query("can_speak")) { ... }` — the `else` branch, taken whenever
`can_speak` is unset/falsy, skips `accept_fight()` entirely and instead
runs `me->fight_ob(obj); obj->kill_ob(me);`, the exact same call
`kill.lpc` would make. None of the 9 dummy files anywhere `set(
"can_speak", 1)`, so `query("can_speak")` returns `0`/undefined for
every one of them, and EVERY `fight`/`hit` against a training dummy —
lib-wide, in every zone that has one — silently took the lethal branch
instead of the safety-net branch its own code was clearly written for;
`accept_fight()` was provably 100% dead code for every instance in the
archive (confirmed via `grep -rn 'accept_fight('` — the ONLY call site
in the whole codebase is this one, in `fight.lpc`).

**Why this is a programming bug, not a design/balance judgment call**
(the §10.7 scope note's own test): this is not "the skill gap between
two REAL opponents is too large," an intentional risk `help combat`
already documents — it's a single-purpose, `no_die`-flagged practice
NPC whose entire elaborate stat-mirroring safety mechanism is
architecturally unreachable via the only command that could ever invoke
it, contradicting both its own code's obvious purpose and the command's
own player-facing help text. Confirmed byte-identical in the pristine
raw archive (not introduced by conversion).

Fix: `set("can_speak", 1);` right after `set_name(...)` in all 9 dummy
files (the dummy's own `long` description already says "如同真人一
般" — "as lifelike as a real person" — consistent with its own flavor
text, not an invented property). Narrow, zero-blast-radius: does not
touch `fight.lpc`/`hit.lpc` themselves (which route hundreds of other,
genuinely-hostile silent NPCs system-wide and were deliberately left
alone) and affects no other NPC in the lib. Verified live: before the
fix, `fight mu ren` killed the test character on the second exchange;
after the fix (and a driver restart), the identical command produced
several rounds of combat text, then the dummy conceded (matching a
sibling lib's own documented safe-spar-concedes shape) — the character
survived with stamina depleted but no injury and no death-counter
increment.

Detection pattern: for any lib with an explicit "safe sparring"
mechanic (a training dummy, a `no_die`-flagged NPC, a documented
`fight`-never-kills promise in `help`), grep the shared `fight`/`hit`
command(s) for the exact condition gating the call into
`accept_fight()` (or whatever the lib's own safe-combat entry point is
named), then confirm every intended-safe NPC actually sets whatever
property that condition tests — an NPC whose safety override exists in
source but is unreachable through the only command that could invoke it
is easy to miss by reading the NPC file alone; the gap only shows up by
tracing the CALLER's dispatch condition against what the NPC actually
sets. Always test the lib's own documented safe-sparring target with a
fresh, unequipped character before assuming "fight" is safe by
convention.

### 7.106 `cmds/wiz/update.lpc`'s first check, `present(file, environment(me))`, crashes whenever the calling wizard has no environment — confirmed independently on 3 unrelated libs this round, present unfixed in 128 more (135 total corpus-wide)

**File:line: `cmds/wiz/update.lpc`, the `main()` function's very first
conditional, typically around line 20.** A near-universal shared
command-file shape across this corpus (135 libs carried the vulnerable
form as of this sweep).

- **Symptom**: `*Bad argument 2 to present() Expected: object Got: 0.`
  — thrown the instant a wizard types `update <anything>` (including the
  extremely common `update /adm/daemons/logind` self-check) while
  `environment(me)` is `0`. Reachable any time a wizard's environment is
  genuinely unset — most commonly as a downstream symptom of a cold-start
  `enter_world()` failure (see §7.90: an eval-cost abort mid-`enter_world()`
  leaves the character with no environment for the rest of that session,
  so literally the first thing an admin tries — `update` — crashes too).
  Independently found and root-caused on `xiakexing2017`, `dtslmud`, and
  `dtxywzxzb` in the same round-two testing pass, each time initially
  investigated as if it might be an isolated bug before the shared shape
  became obvious via a corpus grep.
- **Root cause**: `present()`'s 2nd argument requires an `object`; passing
  `environment(me)` unguarded assumes `me` always has one, which isn't
  true the moment anything upstream (an eval-cost abort, a corrupted
  save, a genuinely-void `startroom`) prevented the character from ever
  being `move()`d into a real room.
- **Fix**: guard with `environment(me) &&` before the `present()` call —
  the single one-line change needed regardless of the surrounding
  `if`/assignment shape:
  ```lpc
  // most common shape:
  if ((obj = present(file, environment(me))) && interactive(obj))
  // becomes:
  if (environment(me) && (obj = present(file, environment(me))) && interactive(obj))

  // a rarer assignment-statement shape (7 libs):
  if (!obj) obj = present(file, environment(me));
  // becomes:
  if (!obj) obj = environment(me) && present(file, environment(me));
  ```
  Both shapes are syntactically and semantically safe to patch
  mechanically: the guard adds no new parentheses (paren-balance is
  preserved), and `&&`'s tighter binding than `||` means a compound
  condition like `(obj = present(...)) && playerp(obj) || (obj =
  find_player(file)) && playerp(obj)` still short-circuits correctly to
  the `find_player()` fallback when `environment(me)` is falsy.
- **Verified**: live-reproduced and fixed individually on the 3 libs that
  found it; the remaining 128 were fixed via a corpus-wide mechanical
  sweep (a Python `str.replace()` pass across every
  `libs/*/work/cmds/wiz/update.lpc`, `newline=''` to preserve CRLF/LF per
  file, matching the discipline established for the `quest_times`
  corpus sweep) — spot-checked the diff shape on several libs across
  different lineages for correctness (including the `||`-compound and
  assignment-statement variants above), then did one full live
  end-to-end verification (`fy3xd`: booted, admin login, `update
  /adm/daemons/logind` succeeded cleanly) to confirm the mechanically-
  patched file actually compiles and runs, not just that the text diff
  looks right. Did not live-test all 135 individually — matches this
  project's established "compile-check-level verification for a
  mechanical, well-understood, single-line sweep" precedent (the
  `quest_times`/`win_times` and §7.86 board-crash sweeps were verified
  the same way).
- **Detection**: `grep -L 'environment(me) &&' libs/*/work/cmds/wiz/update.lpc
  | xargs grep -l 'present(file, environment(me))'` for the common shape;
  check `grep -l 'if (!obj) obj = present(file, environment(me));'` for
  the rarer assignment-statement variant. Any new/promoted lib should be
  checked against this pattern as part of its own §10.7 pass if it
  carries this file at all.
- **Path variants, found later**: some libs carry this exact command
  under a different directory than `cmds/wiz/update.lpc` — same
  vulnerable shape, same fix, just a different path. Found so far:
  `cmds/adm/update.lpc` (the 风云3/`fy3dz` lineage plus `wdxtym`,
  `xiyouji2003`, `shenzhou`, `mohuanshiji`, `sjcs`, 6 total) and
  `cmds/imm/update.lpc` (`jh2006` plus 21 more — `bmxkx2001`, `bxsj`,
  `bxsj1`, `fqyy2`, `haiyang2`, `hy2002`, `hy3`, `hy5`, `hymud`,
  `jinyongwenzi`, `jym`, `shenzhou` again (both paths), `shujian2008`,
  `shujian3`, `sjecl`, `sjtx2`, `xkm`, `xkx2000zxb`, `xkx2001`,
  `xuanjianlu`, `zitengzhan`). The original 135-file sweep only searched
  `cmds/wiz/`, so it missed both. Re-run the detection greps above
  against `cmds/wiz/update.lpc`, `cmds/adm/update.lpc`, AND
  `cmds/imm/update.lpc` on any future lib — there may be further path
  variants (`cmds/god/`, `cmds/arch/`, etc.) not yet found; check
  whichever directory a lib's own wizard-level commands actually live
  in if none of these three exist.

---

## 8. Login and registration flow bugs

Registration is where restoration succeeds or fails: it exercises the
connection object, the security ACL, lazy compiles, the chinese-
detection stack, and the player-body class in one chain. The classes
below account for nearly every "reaches a prompt but can't actually
play" report.

### 8.1 GBK byte-range Chinese-detection checks (the most impactful bug in the project)

On this driver `str[i]` is a Unicode CODEPOINT and `strlen()` counts
CHARACTERS; every one of these libs was written against GBK bytes
(`str[i]` a raw byte, 2 bytes per hanzi). Every byte-inspecting check is
silently wrong — no error, just always-false / wrong-width:

- `str[i] > 160 && str[i] < 255` (GBK lead-byte test) — never true for
  real Chinese. Fix:

  ```lpc
  // BEFORE:  if (str[i] < 161 || str[i] > 254) return 0;
  // AFTER:
  if (str[i] < 0x4e00 || str[i] > 0x9fff) return 0;   // CJK Unified
  ```

- A length-gate variant of the same bug: `is_chinese(str) { if
  (strlen(str) >= 2 && str[0] > 160) return 1; return 0; }` — the
  `strlen(str) >= 2` was meant to require "a full 2-byte GBK pair", but
  under this driver's character-counted `strlen()` it instead rejects
  every single-character string outright, and callers that slice a name
  into variable-length tail substrings (checking `name[i..<0]`-style
  "from i to the end") end up calling `is_chinese()` on a 1-character
  slice at the LAST character position — silently rejecting any name
  whose length makes that final slice length 1, e.g. an odd total
  character count. Symptom: some Chinese names of a given length are
  accepted and others of a different length aren't, with no pattern
  obvious from a single test name (§8.1's own "test with a real Chinese
  name" rule can pass by luck if the one name tried happens to have a
  length that survives). Fix: drop the length requirement, check only
  the codepoint range of the first character: `return str[0] >= 0x4e00
  && str[0] <= 0x9fff;` (guard `!strlen(str)` first). (`dfgsiiv13b`.)

- `strlen(name) < 4` meaning "at least 2 hanzi" — halve every
  byte-calibrated bound (the Chinese error message almost always states
  the intended CHARACTER count; make the code match it). Watch for a
  SECOND combined surname+given-name length check at the caller.
- `i % 2 == 0` loop gates (landing on GBK lead bytes) — drop entirely.
- Sliding-window checks `name[i..i+3]` (2 hanzi) → `name[i..i+1]`,
  bounds adjusted.
- `PATH(name)` sharding macros using `name[0..1]` ("first GBK char") →
  `name[0..0]`.
- Byte-shift hacks (`name[j] += 128`) are meaningless against
  codepoints — replace with a plain is-Chinese check.

Fix `is_chinese`/`check_legal_name` in the lib's `chinese.lpc`/
`chinesed.lpc` AND the deeper `named.lpc` where present (nitan-shaped
libs). Leave `is_english` ASCII checks alone. Applied to every lib in
the collection; every NEW lib gets it on sight.

**The verification rule this bug taught the project (standing policy):
never mark registration verified until a REAL Chinese name (e.g. 秦风)
has been sent through the flow and accepted into the NEXT stage.** The
bug shipped undetected in 21 libs precisely because testing stopped at
"reaches the name prompt".

### 8.2 Flow shapes vary — read the callbacks, not the prompts

Registration shape differs per lib: GB/BIG5 font questions blended
invisibly into the banner, "are you a student" age gates (any answer but
"no" disconnects), literal `new` keyword vs. any-unused-id, English name
→ Chinese name with or without confirmations, surname/given-name split
prompts. And a prompt's TEXT can lie: `xyzx3`'s "请输入您的英文
名字:" is actually a hardcoded client-version gate expecting the literal
`"2060"` (and failed retries loop back to the gate, not the id prompt);
`xajhzcjh` has the same `get_version` gate live. **Always
read the actual `input_to` callback chain in `logind.lpc` before
scripting a test.** If a scripted registration produces confusing
cascading rejections, re-run with ONE `--send` at a time and read the
full transcript. (Note: connection-time gates of the uptime/anti-flood
kind are now bypassed per §1.3e.)

### 8.3 "Every post-login command silently does nothing" — the differential diagnosis

Four distinct causes produce this identical symptom (zero output, zero
log signal). Check in this order:

1. **Test-tool artifact**: a live clock/heartbeat prompt keeps the
   connection from ever looking idle, so `mudclient.py` never sends the
   queued commands. Retry with `--idle 0.3`. (`zhongjidiyu`.)
2. **`private nomask command_hook`** (§8.3a below).
3. **Dead command-table sscanf** (§8.3b below) — can COEXIST with 2;
   fixing one still leaves the lib broken (`jinyongwenzi`/`bxsj`/
   `bxsj1` had both simultaneously).
4. **Player has no environment** — the post-registration move went to a
   missing room (§7.14). Check `environment()` first when 2/3 are
   clean.

#### 8.3a `private nomask command_hook`

`feature/command.lpc` declares the central dispatch function
`private nomask`, inherits it into the player body, registers it via
`add_action("command_hook", "", 1)`. On this driver `private` demotes to
DECL_HIDDEN once inherited and `add_action`'s external dispatch silently
refuses to call it. Fix: drop `private` (keep `nomask`).

```lpc
// BEFORE:  private nomask int command_hook(string arg)
// AFTER:   nomask int command_hook(string arg)
```

Affected so far: `xuanjianlu`, `bmxkx2001`, `bxsj`, `bxsj1`,
`jinyongwenzi`, `xiakexing3`, the `jqxz2008` group,
`zhongjidiyu` (twice — main hook plus an 18-handler NPC file),
`zjdyaryl`, `tiexuejianghu`, `xzyx`, `shiji`,
`hell`, `jym` and `cctx` (found via §10.7 deep functional test) and,
via a proactive repo-wide sweep prompted by how often this kept
recurring during deep-testing (2026-08-03): `fys`, `fyzfqyy`,
`gjzddmudda`, `jh2006`, `jyqxc`, `jyqxc2`, `jyqxc2013fwq`,
`njhhdxdes2hx`, `nt1`, `shujian3`, `sj`, `sje`, `sjecl`, `tianxia`,
`wxddym`, `xjcq2000`, `xkm`, `xkx100`, `xkx2000zxb`, `xkx2017`,
`xkxc98sj`, `xkxyb`, `xkyx3b`, `xkyxciii`, `yhwhpublicfi`, `yxsj`,
`yxzsj`, `zjdy2008wzb`, `zjdywzb`, `zjmudhell` (30 libs, one commit).
The sweep grepped every lib for `private.*command_hook`, found 109
hits across 81 libs, then filtered hard before touching anything: 48
of those hits were leftover false positives (an explanatory comment
mentioning "private command_hook" sitting near an already-fixed
declaration, or a match inside `feature/command2.lpc`-style dead
files) and 31 were genuinely-dead variant files (`commandbak.lpc`,
`commandhell.lpc`, `command_new.lpc`, `command2.lpc`, personal
`u/<wizard>/command.lpc` copies) confirmed dead by grepping the whole
lib for an `inherit` statement targeting that exact path — none
found, so left untouched, same as the established `feature/
command2.lpc` precedent on `jym`. Only the 30 listed above had a
live, still-`private`, genuinely-inherited `feature/command.lpc`.
**Gotcha hit while fixing these 30 in bulk**: doing the `private` →
(nothing) removal in Python text mode silently normalized 17
originally-CRLF files to LF (invisible in a quick diff --stat glance,
`git diff` shows it as a full-file rewrite) — redone with binary-mode
`rb`/`wb` regex substitution on the raw bytes instead, which produced
a clean 1-line diff per file. Verified: all 30 boot cleanly (native
driver, one lib at a time, exact-PID kills between each to avoid the
shared-driver-process gotchas in §10.5), plus two full interactive
registration/NPC-dialogue spot checks (`xkyx3b`, `tianxia`) confirmed
the fix actually restores NPC `command()` self-call dispatch, not
just a clean compile. `hell`'s manifestation was
the sharpest yet: its ENTIRE character-creation flow (the "投胎" ritual —
`register <email>` → `decide` → walk to a personality NPC → `wash` for
talents → `born <place>`) runs through NPC `command("say/tell/nod ...")`
self-calls in `d/register/npc/shuisheng.lpc`'s `do_register()`/
`do_decide()`, so this single demotion silently broke registration for
EVERY brand-new player from the very first step — worse than the
movement/sect-join cases below, which at least let an already-registered
character reach the world. Symptom was maximally confusing: the typed
command (`register foo@bar.com`) was silently accepted (add_action
matched fine, no "什么？"), but zero reply ever came back from the NPC —
indistinguishable from a network/timing issue until the driver's own Logs
output was checked for `apply() with insufficient permission:
... function: command_hook ... needs: private, has: hidden`, timestamped
exactly when the command was sent. (`shiji`/`xzyx` both found via a deep
functional test, §10.7 — reached only through an NPC's own `command()`
call, not by any player-typed command, since ordinary typed commands
arrive via `ORIGIN_DRIVER` and bypass the privacy check that only bites
`ORIGIN_EFUN` calls; every earlier smoke test on both libs only ever
typed commands directly, so movement's auto-look and every sect-join
system silently never worked until these passes — `shiji` is the SAME
underlying game as `xzyx`, same bug, same lineage, independently
discovered). **Empirical caveat, now narrowed**: `private` command_hook
does NOT always break *player-typed* dispatch on current drivers —
`shiji` itself, `tianxia`,
and `zhonghua2` all confirmed to accept ordinary typed commands despite
it (exact conditions unestablished; possibly declaration-shape or
driver-version dependent) — but `shiji`'s own §10.7 pass proves this
exception does NOT extend to `command()`-efun self-calls, which still
silently fail. So: treat `private command_hook` as a prime suspect and
fix it on sight regardless of whether typed commands look fine, and
specifically test at least one NPC-issued `command()` path (movement
auto-look, an NPC's own recruit/attack/chat trigger) before concluding
dispatch is fully healthy — verify by actually testing `look` after the
fix, and keep hunting (§8.3b, §7.14)
if commands are still dead.

**Addendum: the same demotion breaks `call_out()`-dispatched functions
too, not just `add_action`.** Found on `xuanjianlu`'s §10.7 deep
functional test. Any `private` function invoked by name from a
driver-origin `call_out()`, inside a file meant to be `inherit`ed
(commonly `.../inherit/*.lpc` or `feature/*.lpc`), suffers the identical
`DECL_PRIVATE`→`DECL_HIDDEN`-once-inherited failure as `command_hook`,
logged as `apply() with insufficient permission: ... origin: internal,
needs: private, has: hidden`. Easy to miss: the triggering action (a
stackable item spent to zero, a timed drug/buff applied) looks
completely normal on screen, and the `call_out` has to actually *fire*
(which can lag its nominal delay under a busy driver) before the log
line appears — a quick "did it error immediately" check shows nothing.
Two confirmed instances on `xuanjianlu`: `inherit/item/combined.lpc`'s
`destruct_me()` (a stackable item — money, most impactfully — spent to
exactly 0 gets moved to `VOID_OB` and never actually destructs, a
permanently-orphaned clone) and `feature/action.lpc`'s `eval_function()`
(inherited into the player-body base class, silently no-ops the shared
"delayed status effect" primitive used by 130+ kungfu-skill/drug files
across nearly every sect — buffs, damage-over-time, poison, timed
powerups, ALL of them). Fix identically: drop `private`. Worth a
proactive grep (`private (void|int|...) NAME` + `call_out("NAME"` in the
same file) on any lib with a custom delayed-callback or
combined/stackable-item helper.

**Third confirmed instance: `zjdyaryl`'s §10.7 deep functional test**,
same `feature/action.lpc`/`eval_function()` shape (independently
confirmed on a different lineage than `xuanjianlu` — ES II → XKX →
"hell", not that lib's family). Reproduced live: `debug.log` showed
`apply() with insufficient permission: ... ob: clone/user/user#N,
function: eval_function, origin: internal, needs: private, has: hidden`
immediately after an ordinary declined `fight` command (which schedules
a `combatd.lpc` recovery call_out via `start_call_out()`). Fixed
identically (drop `private`); re-tested the same `fight` decline
post-fix and confirmed zero further `eval_function`/`insufficient
permission` lines. A second, non-inherited, likely-dead occurrence in
the same lib's `clone/questob/letter.lpc` (declares an identical
`private void eval_function`, but nothing in that file actually
`call_out()`s it) was fixed too for consistency, though it wasn't
confirmed live-triggered — the proactive grep for `private NAME` +
`call_out("NAME"` in the same file catches these even when a live
reproduction isn't easy to force.

#### 8.3b Dead command-indexer sscanf

`commandd.lpc`-style daemons rebuild their command table filtering
directory listings with `sscanf(f + "$", "%s.c$", f)` — matches nothing
after the `.lpc` rename, table stays empty forever, invisible to every
standard `.c`-reference fixer (it's a live runtime pattern, not a
string-literal path). Fix the pattern to `"%s.lpc$"`. Grep all daemons:
`grep -rn 'sscanf.*\.c[$"]' adm/ secure/`. Confirmed again on
`shujian3` (XKX/ES2-derived `commandd.lpc`) — every player command
(`look`/`score`/`quit`/anything) silently fell through to the driver's
default "什么？" fail message until fixed. Also confirmed on `jh2006`
(same `commandd.lpc` lineage) — there, `quit` and `look` happened to
work anyway (defined via `add_action` elsewhere / handled specially by
the driver), but every OTHER command, including the score-equivalent
verb, fell straight through to "什么？" until the fix; a lib where 2 of
3 sanity-check commands work is not proof the command table itself is
healthy — test a THIRD, non-`look`/`quit` command too.

**Third confirmed instance: `sjecl`**, and a useful worked example of
§8.3's own point that causes 2 and 3 can coexist and mask each other:
`sjecl` was already on §8.3a's fixed-list from an earlier repo-wide
`private command_hook` sweep, so `command_hook()` itself was already
correctly wired -- but registration still ended with 100% of commands
(`look` included) silently falling through to "什么？", because
`commandd.lpc`'s `rehash()` independently had this exact `%s.c$`
pattern, leaving `search`/`user_cmds` permanently empty regardless of
`command_hook()` being called correctly. A downstream symptom made this
one unusually loud: `adm/daemons/baoshid.lpc`'s periodic
`choose_baosi()`/`random_place()` (placing random treasure NPCs) logged
repeated `*Too long evaluation. Execution aborted.` eval-cost aborts
during the same session -- these stopped entirely once the command
table was fixed, suggesting the empty command table was causing
something (likely `EMOTE_D`/`CHANNEL_D`'s own fallback probing, hit on
literally every player keystroke) to trigger far more object-compile
pressure than normal, tipping an unrelated daemon over its eval budget.
Don't treat that kind of noisy-but-distinct-looking error as its own
separate bug before checking whether the command table itself is
healthy first -- fixing the root cause here silently resolved both.

### 8.4 Test `score`, not just `look`

`look` proves dispatch + environment; **`score` additionally proves the
player-body class compiled and its data model works** — several bugs
broke only `score` ("No program in object combatd" on the 金庸群侠传
group; is_killing() type mismatches blocking the body class). The done
bar is `look` + `score` + `quit` all correct (§2). When registration
accepts a name/password but the player never lands in the world,
suspect the player-body class failing to compile — grep debug.log for
its compile line specifically (§6.2's never-defined simul_efuns and
direct-call type mismatches are the two known root causes).

### 8.5 Player-body compile blockers

A direct (non-`->`) call with a wrong argument type is a hard compile
error here: `is_killing(ob)` where the signature says `string` (every
other call site passes `ob->query("id")`) blocked whole body classes.
Recurs constantly: `nitan_ceshi`, `nitan_san`, `tianxia`
(query_shadowed), `yhyxs`, `shenzhou`,
`zjdyaryl`/`_zhijian`, the 金庸群侠传 group,
`kxkj1`. Grep `is_killing(` for object-passing call sites
during the standard pass.

### 8.6 Anti-flood registration throttles (now bypassed, §1.3e)

Per-IP "one new registration per N minutes" throttles (bypass policy:
§1.3e) made repeat tests look like silent crashes before that policy
existed — the rejection path's write() is often commented out,
connection just drops. Diagnostic residue worth keeping in mind for any
remaining non-loopback shape: check for `IsTimeAllowed`/`NewIps`-shaped
mappings before debugging the flow (restarting the driver clears
in-memory throttles instantly), and run full registration in ONE
continuous client session, not several reconnects.

### 8.7 Stale GBK/BIG5 encoding-choice menu produces mojibake (check every lib with `set_encoding()`)

Many login flows ask the connecting player to pick their client's
charset (`"使用国标码的玩家请键入：GBK" / "使用unicode码的玩家请键入：utf-8"`
or similar) and call `ob->set_encoding(choice)`, which transcodes the
driver's internal strings to whichever charset the player named. This
project's conversion pipeline transcodes every lib's actual source to
UTF-8 (§4) — so on a converted lib, the "GBK" (or "BIG5") branch is
transcoding genuinely-UTF-8 internal strings INTO real GBK/BIG5 bytes,
then sending those bytes to a client that only understands UTF-8 (the
WASM web terminal's xterm, `mudclient.py`, any modern telnet client we
support) — corrupting every line of output from that point on, for
every player who follows the on-screen prompt's own wording. This is
not a driver bug; the code does exactly what it's designed to do — the
choice itself is simply never correct anymore for any client this
project supports.

**Fix**: find the branch that sets a non-UTF-8 encoding (grep
`set_encoding` in the lib's `logind.lpc`/equivalent) and map it to
`"utf-8"` too, so the choice can no longer break anything. Prefer this
over removing the prompt outright — READMEs/NOTES sometimes already
document the menu's wording. First found+fixed in `aoxiangtianji`
(reproduced live: banner and the whole subsequent session rendered as
mojibake with "GBK" selected, clean with "utf-8"; retested the full
admin-login+look+quit flow after the fix). **Scope check**: `grep -rl
set_encoding libs/*/work --include='*.lpc'` found 34 libs using this
pattern as of this writing — treat each as a candidate for the same
bug until verified otherwise (some may already only offer utf-8, or
may be a lib that was never GBK/BIG5-sourced to begin with).

**Second mechanism shape, seen across the whole "西游记" family**
(`xianlvqiyuan`, `xixingzhanji`, `xiyouji`/`2003`/`2006`/`450`,
`xlqy_early`, `xlqy_new2007`, `yueyingqiyuan`, `zitengzhan`): the lib's
own `feature/encoding.lpc` locally OVERRIDES `set_encoding()` as a
plain int flag (`0=GB, 1=BIG5`) — the call never reaches the driver's
real efun at all. A separate `adm/daemons/convertd.lpc` daemon reads
that flag in its `output()`/`input()` and runs a giant (~7000-line)
byte-pair GB↔BIG5 lookup table on every line whenever the flag says
BIG5. That table assumes the driver's internal strings are raw GB2312
byte pairs — true pre-conversion, false now, so picking BIG5 ran
`GB2BIG()` over genuinely-UTF-8 bytes and corrupted everything.
`encode=0` ("gb") is what `convertd.lpc` already treats as a no-op
passthrough in this family, so the fix is to map BOTH menu choices to
`encode=0`, not `"utf-8"` — same intent, different literal value,
because the local override's contract is int-flag-driven rather than
charset-name-driven. **Lesson: don't assume `set_encoding()` reaches
the driver efun — grep for a local LPC override of the same name
(`void set_encoding(...)` in a `feature/`/`adm/` file) before deciding
which value neutralizes it.** `xiaoyuxiyou` (same family) needed NO fix
— its `convertd.lpc` was already gutted to no-op stubs, so the flag
never drives any real transcoding regardless of what's selected;
verified live before concluding this, not assumed from the file being
short.

**Whether the local-override shape is a LIVE bug depends entirely on
the converter's byte-range test — always boot and select the legacy
option live, never conclude from code shape alone.** Seen across a
second family (`xyj2000f`, `mhxyqd`, `mhxy`,
`mohuanshiji` — same `feature/encoding.lpc` int-flag +
`CONVERT_D`/`LANGUAGE_D` byte-table pattern as above): some of these
libs' `SC_ISFIRSTBYTE(c)`-style test is UNBOUNDED (`c >= 0xA1`, no
upper limit) — that fires on every real Unicode CJK codepoint (all
≥0x4E00, well past 0xA1) and misreads each character as the start of a
legacy 2-byte pair, corrupting the whole output the moment BIG5 is
selected (confirmed live). Others in the very same family use a
correctly BOUNDED range (`0xA1`–`0xFE`/`0xF7`, e.g. `is_GB1`/`is_B51`
in `haiyang2`/`hymud`) that never matches real UTF-8 CJK bytes — those
are NOT bugs, selecting the legacy option already renders clean, and
patching them would be needless churn. Same fix when it IS live: map
the legacy branch to whatever value that lib's own converter treats as
a no-op (usually `encode=0`/"GB"). Also check for dead code before
fixing anything: `dtsl2`'s menu is unreachable behind an
`#ifdef GB_AND_BIG5x` typo (trailing "x" never matches the real
`#define`) that always hardcodes the safe branch — a real but harmless
bug, out of scope, don't "fix" the typo as part of this pass unless
asked.

### 8.8 `get_id()` routes ANY wiz-level id through a password check that assumes a save file already exists

A registration flow's `get_id()` sometimes has an early, wizard-specific
branch — `if (wiz_level(arg)) { input_to("get_passwdd", 1, ob); }` —
that fires purely based on the id's CURRENT wizard status, with no
check for whether a save file exists yet, and critically NO `return`
(execution falls through to the rest of the function, which later
does its own, correct `file_size(...) >= 0` check and registers a
DIFFERENT `input_to` for the normal new-character flow). The intent is
reasonable (route wizards through a richer login handler with
suicide-list/netdead-reconnect logic that a plain new-player flow
doesn't need) — but it breaks exactly the scenario this project's own
§1.5 admin-seeding convention creates: a `fluffos` id freshly granted
`(admin)` status that has never actually registered a character. The
next player input gets silently captured by the wizard-only password
handler, which reads `ob->query("password")` — unset, since
`ob->restore()` was never called for a brand-new id — so ANY password
attempt fails immediately with a generic "密码错误" (wrong password)
and the connection is destructed, with no other error trace. This
looks exactly like a send-sequence misalignment (per §8.2) but isn't
one — re-sending with a "corrected" sequence won't help, since the
bug is that a DIFFERENT, wrong `input_to` callback is intercepting the
very next input regardless of what it contains. Detection: if a lib's
registration flow works fine for an ordinary id but a freshly
wiz-flagged id fails at the very next prompt after id entry with an
unexplained password-style rejection, grep `get_id()` for an
`input_to(` call gated only on `wiz_level(...)`, with no accompanying
`file_size()`/save-existence check on the same condition. Fix: add the
missing existence check (matching whatever check the same function
does later for the ordinary new/existing-character split) and the
missing `return`, e.g. `if (wiz_level(arg) && file_size(save_file) >=
0) { input_to("get_passwdd", 1, ob); return; }`. This is a genuine
pre-existing bug in the archived source (would bite any real
deployment that grants wizard status to a not-yet-registered id), not
something the admin-seeding process introduces. (`xkm`, sibling of
`jym` — `jym` itself doesn't have this early branch at all, so don't
assume it's present just because two libs share the rest of their
`logind.lpc`/`securityd.lpc` composition.)

### 8.9 A food/water first-login initialization gate checks the wrong object's `age`, so it never fires for anyone

Found on `cctx`'s deep functional test (§10.7), second confirmed
instance on `niaoren` (same session, found specifically because
`niaoren` turned out to share `logind.lpc`/`master.lpc` source with
`cctx` — see §11's lineage note — so the same bug, byte-for-byte the
same broken condition, carried over into an independently-branded
fork), third confirmed instance on `yxjh` — an unrelated lineage
(浴血江湖/"天涯" family, no known relation to the `cctx`/`niaoren`
pair), same mistake independently made, but a slightly leaner shape:
no `!user->query("food") && !user->query("water")` guard at all, just
a bare `if (ob->query("age") == 14) { user->set("food", ...); ... }`
right after `user->setup()` — same wrong-object read, same permanent
false, same fix. Fourth confirmed instance on `ldtxii` (Century/
adm-single family, byte-identical condition to `cctx`/`niaoren`'s full
`!user->query("food") && !user->query("water") && ob->query("age") ==
14` shape, but an unrelated lineage — no known relation to either the
`cctx`/`niaoren` pair or `yxjh`) — its sibling `ldtx` carries the exact
same unfixed line at the same line number; port the fix there too when
next touched. Fifth confirmed instance on `bixiecanyang` (夕阳再现
derivative family — a fifth unrelated lineage, no known relation to
any of the previous four) — same leaner shape as `yxjh`, a bare
`if (ob->query("age") == 14) { ... }` right after `user->setup()`,
found alongside two `printf("%O\n", ob)` debug leaks (§7.34) in the
same file during the same pass. Sixth confirmed instance on `jyqxc`
(XKX/金庸群侠传 framework family — a sixth unrelated lineage), the
full `!user->query("food") && !user->query("water") &&
ob->query("age") == 14` shape byte-identical to `cctx`/`niaoren`/
`ldtxii`, found alongside a single-path `printf("%O\n", ob)` debug
leak (§7.34) in the same file. Seventh confirmed instance on `syxjl`
(ES2-family, 神州/火影/武汉站 branch — a seventh unrelated lineage),
same full shape, also alongside a single-path `printf("%O\n", ob)`
debug leak in the same file — this specific pairing (both bugs, same
file, same session) has now recurred often enough to be worth checking
both on sight whenever one is found in a `logind.lpc`. Eighth confirmed
instance on `wmkj` (夕阳再现/`bixiecanyang` lineage — a different
lineage from all seven priors), the bare leaner shape (`ob->query("age")
== 14`, no `!user->query("food")` guard), found alongside the
TWO-parallel-path `printf` variant (§7.34) this time rather than the
single-path one — the pairing recurs, but not always with the same
`printf` shape. All eight fixed identically: `ob->query("age")` →
`user->query("age")`. The `enter_world()`-
equivalent in `logind.lpc` has two live objects at once — `ob` (the
transient login/connection stub) and `user` (the freshly-`new()`'d
player body) — and after `exec(user, ob)` + `user->setup()` (which
internally sets `user`'s own `age` to 14 for a brand-new character),
the one-time food/water seeding is gated on
`!user->query("food") && !user->query("water") && ob->query("age")
== 14`. Every condition in that `&&` chain reads `user` except the
last, which reads `ob` — the login stub, whose "age" property is never
set anywhere in the whole codebase (confirmed by grepping every
`set("age"` call site: all of them target `user`/NPC objects, none
target the login-object class). `ob->query("age")` therefore always
returns the driver's default `0`, the gate is permanently false, and
`user->max_food_capacity()`/`max_water_capacity()` never get applied
to ANY new character — every single new player enters the world with
food and water both stuck at 0, triggering an immediate "你饿得直冒
金星" (starving) message on their very first `look`/`score`. Detection:
in a first-login init block, if a condition mixes `user->query(...)`
and `ob->query(...)` on what's conceptually "the same new character,"
check whether that specific property is ever actually set on the
object being read — a per-property grep for `set("<prop>"` across the
whole tree (not just the file in front of you) is the fast way to
catch a silently-always-0 default masquerading as a real gate. Fix:
use `user->query("age")` to match the object `update_age()` actually
writes to. Verified live with two side-by-side fresh characters on the
native driver: `score`'s food/water bars were both fully empty (with
an immediate "你饿得直冒金星" starving message) before the fix, and
both fully filled after — same class of "wrong object read in an
otherwise-correct multi-object function" as §7.63's missing-guard
pattern, but on a `query()` rather than a `new()` call.

Ninth confirmed instance on `jhfy2` (江湖风云II 之 辽宁风云再起,
"tianya"-map family — a ninth unrelated lineage from all priors), the
bare leaner shape (`ob->query("age") == 14`, no `!user->query("food")`
guard), found alongside the TWO-parallel-path `printf` variant (§7.34)
in the same file during the same pass — same recurring pairing noted on
`syxjl`/`wmkj` above. Notable wrinkle: unlike every prior instance,
this lib's fresh characters did NOT show empty food/water bars at
registration (`score` showed both fully filled) — some other default
elsewhere in this lib's character-creation path evidently already
covers it, making this instance currently inert/harmless in practice.
Fixed anyway or `ob->query("age")` → `user->query("age")`, matching
every prior instance's fix: **a condition being currently masked by an
unrelated default doesn't make the underlying wrong-object read
correct** — the gate should still do what its own code clearly intends,
and a future refactor of that other default would silently reintroduce
the visible bug with no warning. Don't skip an §8.9 fix just because
this pass's live test didn't observe starving characters.

Tenth confirmed instance on `jyqxc2` (XKX/金庸群侠传 framework family,
sixth instance `jyqxc`'s own sibling) — the full `!user->query("food")
&& !user->query("water") && ob->query("age") == 14` shape,
byte-identical to `jyqxc`'s own pre-fix line (this session's §10.7
deep-dive on `jyqxc2` found its `work/` tree is byte-identical to
`jyqxc`'s apart from `logind.lpc`, which was still carrying `jyqxc`'s
UNFIXED original content — the two archives are effectively the same
raw dump, `jyqxc`'s own fix from an earlier pass never having been
back-ported). Verified live: a fresh non-admin test character's `score`
showed food/water both stuck at empty pre-fix, both fully filled after
the one-line `ob->query("age")` → `user->query("age")` fix, `update
/adm/daemons/logind` hot-reloaded cleanly. Same session also removed
the file's matching §7.34 `printf("%O\n", ob)` leak.

### 8.10 A retry re-prompt after the version-handshake gate loops back to the wrong `input_to` callback, so a real player's SECOND login attempt gets falsely accused of using an unsupported client and disconnected

Found on `xiyouji2006` (a Tomud-family lineage that gates every
connection behind a hidden client-version handshake: the first thing a
real client is expected to send is the literal string `2060`, checked
in `logind.lpc`'s `get_id()`; anything else prints "你的客户端非Tomud
或者非笑傲江湖WWW客户端!!" and disconnects). The REAL "type your
English name" logic lives one function down, `get_id1()`, which
`get_id()` calls after the version check passes. Two of `get_id1()`'s
own retry paths — an illegal-ID rejection and a "no such player"
message — each re-print the "您的英文名字：" prompt and then call
`input_to("get_id", ob)` to wait for the retyped name. That's the
version-gate function, not the ID-entry one: the player's very next
keystroke (their corrected username, or `new` to register) gets
compared against the literal string `"2060"` instead of validated as
an ID, and since a real name is essentially never exactly `"2060"`,
every single player who mistypes their ID once (a digit, too short,
too long — any of the ordinary reasons `check_legal_id()` might
reject a first attempt) or types a genuinely-unregistered name gets
falsely told their client is unsupported and kicked. A third, identical
occurrence exists in `confirm_id()` but is entirely commented out
(`/* ... */`) and therefore inert — left alone, don't "fix" dead code.

Root cause reads as a copy-paste of the very first `input_to((:
get_id :), ob)` call (the one right after the banner, which correctly
starts the version handshake) into two spots that actually needed to
resume `get_id1()`'s own loop. Fix: change both live
`input_to("get_id", ob)` calls to `input_to("get_id1", ob)`. Verified
live: pre-fix, deliberately sending an invalid ID (a digit) followed by
a real, syntactically-valid retry name reproduced the false
"服务器已经和你断开连接了" disconnect every time; post-fix, the same
sequence correctly re-prompts through `get_id1()` and reaches normal
registration.

Detection: grep any Tomud/xiyouji.org-lineage `logind.lpc` for
`input_to("get_id", ob)` outside the single legitimate call site right
after the version-handshake banner — any OTHER call reaching that same
function is this bug. Confirmed present with the identical
line-for-line shape (three occurrences, same relative positions, third
one commented out) in **three sibling libs not yet given this fix**:
`mhxy`, `mhxyqd`, `shenmo` — check and apply the same two-line change
the next time any of those is touched, rather than rediscovering this
from scratch.

### 8.11 A macro reference embedded literally inside a multi-line `@TEXT` string block never gets expanded, so its literal name leaks straight to every player

Found on `xlqy_early`. Most of `adm/daemons/logind.lpc`'s player-facing
messages reference `GAME_NAME` (`#define GAME_NAME "洪荒西游"`) the
normal way — string concatenation, `"..." + GAME_NAME + "..."` — and
those all render correctly. One prompt (the "give yourself a Chinese
name" confirmation, in `confirm_id()`) was written as a `write(@TEXT
... TEXT)` multi-line raw string literal instead, with `GAME_NAME`
typed directly inside the block's text rather than concatenated in.
LPC's preprocessor does not expand macro identifiers that appear inside
a string literal (multi-line `@TEXT` blocks are still one string
literal to the lexer) — so every single player who has ever registered
on this archive has seen the literal 9-character text `GAME_NAME`
sitting where the real game name belongs: `请您给自己想一个符合〖
GAME_NAME 〗神话世界的中文名字...`. Confirmed present since the
archive's original creation (byte-identical in the raw, unconverted
source), not a conversion-pipeline artifact.

Fix: rewrite the `@TEXT` block as an ordinary `write()` call using the
same string-concatenation style already used everywhere else in the
file for `GAME_NAME`/`LIB_NAME`, so the macro is substituted at
preprocess time like normal. Detection: for any lib, grep every
`@WORD\n...\nWORD` multi-line string block in `adm/daemons/` (and any
other file with player-facing text) for identifiers matching a
`#define`d ALL-CAPS constant — a hit means that constant's value has
never actually reached a player, no matter how long the lib has run.
Verify by re-triggering the exact prompt and confirming the real value
now renders instead of the macro name.

### 8.12 A character-creation menu prompts for uppercase letters but the validation range-check only accepts lowercase, silently rejecting exactly the input the player was told to type

Found on `xbtxiii`'s §10.7 deep functional test, in
`adm/daemons/logind.lpc`'s `get_kind()` — the "pick your character's
attribute category" step, prompted as `请您选择您的人物的属性类别,
有12种类型(A,B,C,D,E,F,G,H,I,J,K,L)` and, on a bad entry, re-prompted
as `你只能在(A--L)中选择一种人物类型`. Both messages spell the valid
range in uppercase. The actual check:
```lpc
if (kind < "a" || kind > "l") { ... re-prompt ... }
```
compares against LOWERCASE bounds. Typing exactly what the prompt
says (`A`) fails the check (`"A" < "a"` is true in LPC string
ordering, since `'A'` is 65 and `'a'` is 97) and loops back to the
same re-prompt, which itself still says uppercase — a player who types
precisely what they were told gets stuck in an unwinnable retry loop
until they guess to try lowercase instead. Confirmed live: `A` at the
prompt bounced with the rejection message every time; `a` (undocumented
to the player) was accepted and proceeded normally to the gift/stat
display. Downstream code (`choice_gift()`) independently only matches
against a hardcoded lowercase alphabet (`"abcdefghijklmnopqrstuvwxyz"`),
confirming lowercase — not uppercase — is what the rest of the
codebase actually expects; the bug is squarely in the prompt/validation
mismatch, not in a downstream lookup table that could just as easily
have been "fixed" the other way. Fix: normalize the input with
`lower_case()` at the top of `get_kind()`, before the range check, so
either case works and downstream code keeps receiving the lowercase
form it already assumes:
```lpc
if (stringp(kind)) kind = lower_case(kind);
if (!stringp(kind) || kind < "a" || kind > "l") { ... }
```
Verified live: after the fix and a driver restart, typing `A` at the
identical prompt proceeded straight to the gift/stat display instead
of re-prompting. Detection pattern: any character-creation (or other)
menu whose prompt text and re-prompt/error text both display one case
convention (commonly uppercase, since single-letter menus read better
that way) while the actual comparison uses string bounds/literals in
the other case — grep for `"%s%s" NOR ...(A-`-style prompts alongside
a `kind < "a"`/`kind > "l"`-shaped guard, and check which case the
literals in the comparison actually use versus what the surrounding
`write()` calls tell the player to type.

### 8.13 A wizlist account's separate "WIZ password" login gate has no success path for the (extremely common) case where that password was never set, permanently dead-ending every login after the first

Found on `sjshv150`'s §10.7 deep functional test, on the SECOND
connection (the restore/relogin path, distinct from the
just-registered session that never exercises this code) for the
seeded `fluffos` (admin) test account. On top of this lib's already
unusual double-password scheme (a separate "管理密码"/"普通密码",
see the README), any id listed in `adm/etc/wizlist` gets a THIRD gate
in `adm/daemons/logind.lpc`'s `get_passwd()`:
```lpc
if ((id = ob->query("id")) && member_array(id, SECURITY_D->get_wizlist()) != -1) {
    write(HIR "№" WHT "『" HIG "请输入相应的WIZ密码" WHT "』" NOR "");
    input_to("get_wizpwd", 1, ob);
} else
    check_ok(ob);
```
`get_wizpwd()` itself:
```lpc
private void get_wizpwd(string pass, object user, object ob) {
  ...
  if (!user->query("wiz_password")) {
    write(HIW "你没有设定WIZ密码，请用WIZPWD来设定！\n" NOR);
  }
  if (user->query("wiz_password")) {
    if (crypt(pass, old_pass) == old_pass) { ...; check_ok(user); return; }
    else { ...; input_to("get_id", user); return; }
  }
}
```
Nothing about setting a `wiz_password` is part of registration — a
brand-new account (even a pre-seeded admin one, per §1.5) never has
one, and the ONLY way to set it is the in-game `WIZPWD` command,
which requires already being logged in. The very first time any
wizlist id reconnects (i.e. every session after the first), it hits
`get_wizpwd()` with `wiz_password` unset: the first `if` prints the
nag and falls straight through with no `check_ok()`, no re-`input_to`,
nothing — the function just returns. The player's next keystroke (in
this case, `look`) has nowhere to go: no `input_to` is armed and no
player body exists yet, so it lands on the bare connection object's
own generic `"什么？"` fail response, forever — a textbook chicken-
and-egg deadlock (can't set the password without logging in, can't
log in without the password already being set) that permanently locks
out EVERY wizlist member (not just admin — apprentice/wizard/arch too)
who has never explicitly run `WIZPWD`, which in practice is nearly
everyone on a freshly-seeded or freshly-restored archive. Confirmed
live: reconnecting as `fluffos` and answering the regular-password
prompt correctly reached `"你没有设定WIZ密码，请用WIZPWD来设定！"`,
then every subsequent input (`look`, `score`) produced only `什么？`
with no player ever entering the world, and `debug.log` showed
nothing at all (silent, not crashing). Fix: treat the unset-password
case as non-blocking, matching what the nag message actually implies
(a reminder to set one, not a hard requirement) and matching how the
game already treats it moments earlier on FIRST login (`check_ok()`'s
own post-`enter_world` code prints the identical nag with no gating
whatsoever) — call `check_ok(user)` and `return` right after the nag:
```lpc
if (!user->query("wiz_password")) {
    write(HIW "你没有设定WIZ密码，请用WIZPWD来设定！\n" NOR);
    check_ok(user);
    return;
}
```
Verified live: after the fix and a driver restart, the identical
reconnect sequence showed the same nag but then proceeded straight
into the world (landed in `〖巫师会议厅〗`, the wizard meeting room),
with `look`/`score`/`quit` all working normally and prior character
state (death count, HP) intact from the previous session. Detection
pattern: any `input_to` callback gating login behind a secondary,
separately-settable credential — grep for a conditional structure of
the shape `if (!has_secondary_cred) { <nag>; } if (has_secondary_cred)
{ <verify path> }` with no unconditional continuation after the nag
branch — the "not set yet" case must always have its own explicit
path forward (or an explicit, deliberate lockout with a clear message
this is a first-run-only setup step), never silent fallthrough with no
further `input_to` armed.

### 8.14 A custom connection-time IP ban check is fed a reverse-DNS hostname where its own implementation expects a dotted-quad IP, so it fail-closes and bans nearly every connection, silently, right after the login banner

Found on `hy3`'s §10.7 deep functional test. `adm/daemons/logind.lpc`
has an author-added anti-abuse gate right after the login banner
(comment: "added by xingyun用来禁止恶意破坏的ip login"):
```lpc
if (BAN_D->is_banned(query_ip_name(ob))) {
    write("Sorry, your ip is banned by this mud.\n");
    destruct(ob);
    return;
}
```
`band.lpc`'s `is_banned(string site)` parses its argument as a
dotted-quad IP (`sscanf(site, "%s.%s.%s.%s", ...)`) and, matching the
fail-closed convention this project has seen before (§7.5's
`securd.lpc` ACLs), treats a parse failure as "banned" — `if
(sscanf(...) != 4) return 1;` — before ever consulting the actual
`Sites` blacklist array. But the call site passes `query_ip_name(ob)`,
the REVERSE-DNS HOSTNAME, not `query_ip_number(ob)` (the actual IP) —
a few dozen lines later in the same file, a different gate
(`BAN_D->is_netclub(query_ip_number(ob))`) uses the correct efun,
confirming this is a genuine argument mix-up rather than a deliberate
hostname-based design. On a native driver, a loopback connection's
reverse lookup resolves near-instantly (glibc's `/etc/hosts` NSS hit)
to the literal string `"localhost"` — no dots at all — so the sscanf
fails and every local test connection gets banned immediately after
choosing an encoding, before the "your English name:" prompt ever
appears, with zero signal in `debug.log` (just the plain-English
banner text and a disconnect). This is not merely a local-testing
artifact either: most real remote players with a resolvable PTR
record have a hostname that isn't shaped like four dot-separated
numeric octets, so a real production deployment of this exact idiom
would ban the majority of genuine incoming connections too, not just
loopback ones — this is a real programming bug (wrong efun passed to
a function with a narrower contract than its caller assumed), not a
`§1.3b`-style loopback-only convenience gate. Fix: pass
`query_ip_number(ob)` instead, matching what `is_banned()`'s own
`sscanf` shape actually expects. Verified live: before the fix, a
tmux telnet session was disconnected with "Sorry, your ip is banned
by this mud." immediately after selecting GB encoding, every single
run; after the fix and a driver restart, the same connection
sequence proceeded normally into the id/registration prompts, and
(with the lib's `banned_sites` file empty, as shipped) no connection
was rejected. Detection pattern: any custom ban/allowlist daemon
whose matching logic assumes a specific string SHAPE (dotted-quad IP,
fixed-length code, etc.) — check what the CALLER actually passes in
against what the callee's own parsing expects, especially when the
callee's failure path is fail-closed (denies by default on a parse
miss) — a `query_ip_name()`/`query_ip_number()` mix-up is one
concrete instance of a broader class where a hostname-shaped or
otherwise differently-shaped string silently satisfies neither the
happy path nor an explicit error, just the same generic deny branch
as a real bad actor.

**Sibling instance, opposite failure direction: `jyqxc2013fwq`'s §10.7
deep functional test (same "jyqxc" architecture family as `hy3`? — no,
unrelated lineage, §11 — but the identical call-site typo).**
`adm/daemons/logind.lpc` has the exact same
`BAN_D->is_banned(query_ip_name(ob))` call (`query_ip_number(ob)` used
correctly a few lines later in the same file for an unrelated message),
but this lib's `band.lpc::is_banned()` matches candidates with
`regexp(({site}), Sites[i])` against a `banned_sites` file of literal
dotted-quad patterns, with no fail-closed default — so feeding it a
hostname instead of an IP makes the ban list **fail OPEN** (every
banned dotted-quad pattern silently never matches a hostname string),
the opposite of `hy3`'s fail-closed "bans everyone" outcome, but the
same root cause and same fix (`query_ip_number(ob)`). Also confirmed:
this lib's own already-deep-dived sibling archives `jyqxc`/`jyqxc2`
(§11) carry the byte-identical unfixed call site in their own
`logind.lpc`, missed by both of those libs' own §10.7 passes since
banning wasn't specifically exercised — worth a quick sweep on both if
picked up again. Detection pattern: don't assume this bug class only
fails closed — grep for `query_ip_name(` anywhere feeding a ban/allow
check regardless of the callee's own default-on-parse-failure
behavior, since a fail-open instance produces NO visible symptom during
ordinary play (bans just quietly never trigger) and will only surface
by reading the call site directly or testing against a real banned
entry.

### 8.15 A room's own `create()` force-loads a Windows-era-cased NPC/board filename at RUNTIME (`new()`/bare `"path"->func()`), not at compile time — so it compiles clean, ships clean, and only throws when a player is the first to actually enter that specific room

Found on `sjshwzb`'s §10.7 deep functional test, in `d/emei/huayanding.lpc`
(峨嵋 华严顶). This is a sibling of the already-cataloged case-sensitivity
classes — §7.8 (`read_file()`/data-path case mismatch) and the `#include
<Action.h>`-vs-`action.h` compile-time class documented in §6.1 — but a
third, RUNTIME-only shape neither of those covers: a bare object-reference
string passed to `new()` or used as the left side of `->` in a room's
`create()`. This compiles fine (the compiler never resolves a runtime
string), so it survives every static sweep and even a full `lpcc`/boot
check with a clean log. It only detonates the first time a real player (or
a wizard's `update`) actually walks into that specific room and the room's
own `create()`/`reset()` executes, at which point `new()`/`load_object()`
silently returns `0` for the wrong-cased path and the very next line's
`->` on that `0` throws `Bad argument 1 to EFUN call_other() ... Got:
int(0)`. Two independent hits in the same 25-line file: `set("objects",
(["npc/yingke": 1]))` — the "objects" mapping value flows into `std/room.lpc`'s
`make_inventory()` (`ob = new(file); ob->move(this_object());`), and the
actual on-disk file is `d/emei/NPC/YINGKE.C` (all-uppercase), so `new()`
returns 0 and the very next line's `ob->move(...)` crashes; and a separate,
unrelated-looking board-preload idiom, `"obj/board/emei_b"->foo();`, whose
actual on-disk file is `obj/board/EMEI_B.C` (also all-uppercase) — this one
additionally lacks the leading `/` that the lib's OTHER, working instances
of this same idiom all have (e.g. `d/city/kezhan.lpc`'s
`call_other("/obj/board/nancheng_b", "???")`), so it would still fail even
after a case fix without also adding the slash. Traced via `update
/d/emei/huayanding` as an admin, which wraps `compile_object`'s first-load
in its own `catch()` and surfaced the full stack instead of a bare
disconnect: `/std/room.lpc` line 18 (`make_inventory()`) → `reset()` line 61
→ `setup()` line 212 → `huayanding.lpc create()` line 21 (the `setup()`
call, which happened to be BEFORE the board line in source order, so the
NPC crash pre-empts the room ever reaching the board line at all on first
load). Because `update.lpc` catches the error, the driver itself survives
and logs a normal-looking recoverable trace — but an ordinary player
walking into the room for the first time each boot gets the same
uncaught-but-driver-caught runtime error with no NPC ever spawned and
(until also fixed) no board ever preloaded, and zero visible symptom
besides a possibly-truncated room description depending on where in
`create()` the throw lands relative to `set()` calls already having run.
Not fixed in this pass beyond noting it (scope was the `EMEI_B.C`
`replace_program()` fix, a different bug in the same file — see the
`§7.86` write-up in `sjshwzb`'s `NOTES.md`); flagged here as its own
class since the driving question — "why does a room that compiles clean
and boots clean still crash on first visit" — needs a different diagnostic
move (`update <room>` as admin to force a `catch()`-wrapped first
compile) than any of the other case-sensitivity entries. Detection
pattern: whenever a lib has a cluster of leftover uppercase-`.C` files
(common on any Windows/GBK-era archive — see §4's uppercase-`.C`
conversion blind spot), grep every `.lpc` file's own `new(`/bare-string
`->`/`call_other(` argument literals for a lowercase or unslashed variant
of any such filename's basename; a hit won't show up in a boot log or a
`§9` formatter pass, only by actually visiting the room or forcing a
first compile via `update`.

**Confirmed instance outside a room, `hy5`'s §10.7 deep functional
test**: the same class isn't limited to rooms — `kungfu/class/qingcheng/
yu.lpc` (a sect-master NPC template), in its own `create()`, does
`carry_object(__DIR__ "whammer")->wield()` on a 50%-random branch
(`if (i == 0) { changjian } else { whammer }`), but the on-disk file is
`kungfu/class/qingcheng/Whammer.lpc` (capital `W`) — the only reference
to it anywhere in the tree, confirmed by grep. `carry_object()` already
has its own internal `objectp()` guard and returns `0` on a failed
`new()`, but the caller doesn't check before chaining `->wield()`,
so `new()`'s case-mismatch failure surfaces one call downstream as
`*Bad argument 1 to EFUN call_other() ... Got: int(0)`. This one is
NOT tied to a room's first visit — it fires from a driver-internal
random-quest-NPC-cloning feature (`questd.lpc`'s `spread_quest()`,
itself invoked from `create()`, itself run at every preload AND on every
wizard `update` of `questd.lpc`), so it's fully deterministic given the
`random(2)` roll and reproduces on roughly half of all boots/updates,
not just once. Traced by noticing the crash's file:line
(`kungfu/class/qingcheng/yu.lpc` line 91) didn't match a `carry_object`
call for the branch the trace's own `i` value implied, then diffing the
two branches against `ls` of the directory. Fixed by correcting the
string literal's case (`"whammer"` → `"Whammer"`) to match the on-disk
name — the general lesson from the room-based instances above still
applies: grep every `.lpc` file's `new()`/`carry_object()`/bare-`->`
argument literals against the actual on-disk casing of files they
reference, not just inside room `create()`s.

### 8.16 A reconnect-kick branch re-arms `input_to()` with a wrong-typed/missing argument AND no player-visible prompt, so the player's very next arbitrary keystroke is silently misrouted into a completely different flow

Found on `yxjh`'s deep functional test (§10.7), reproduced live via two
rapid, back-to-back real reconnects. `adm/daemons/logind.lpc`'s
`confirm_relogin()` — the "kick the old, stale connection off, let the
new one take over" handler run when a player reconnects while an old
link object is still technically registered — has a fallback branch for
when `old_link` has already gone away (`user->query_temp("link_ob")` is
`0`, the old socket already closed but the driver's own cleanup hadn't
caught up yet — genuinely reachable via two disconnect/reconnect cycles
in quick succession, not a contrived edge case):

```lpc
// the else branch, old_link already gone:
input_to("get_id", ob, user);
```

`get_id()`'s real signature is `(string arg, object ob, int ip_cnt)` —
this call passes the just-reconnected `user` OBJECT into what should be
an `int` third argument, AND — the more consequential half of the bug —
does so with **no preceding `write()`/prompt at all**. The player sees
nothing on screen, but their very next arbitrary input (e.g. an
ordinary `look`) gets silently captured by `get_id()`'s callback and
processed as if it were a freshly-typed ENGLISH ID for a brand-new
registration, popping "使用 `look` 这个名字将会创造一个新的人物，您确
定吗" — a completely silent command-stream derailment that's easy to
mistake for a network glitch unless the player reads the prompt text
carefully. The identical shape (`input_to("get_id", user)`, missing the
third argument entirely rather than mistyping it) recurs independently
in the same file's `get_wizpwd()` wizard-password-retry-failure branch.

Detection: grep a lib's `logind.lpc`-equivalent for any `input_to(
"get_id", ...)` (or whatever function name resumes ID entry) call site
OTHER than the single legitimate one right after the connection banner
— per §8.10's related lesson, any such call reaching that function from
elsewhere is suspect, but check the ARGUMENT SHAPE too, not just which
function name is being resumed: an object/wrong-type argument in a slot
the target function declares as a narrower type, and/or a missing
`write()` immediately before the `input_to()` call, both independently
indicate a copy-pasted-and-not-fully-adapted reconnect branch. Reproduce
live with two rapid real reconnects (not a scripted single-shot
registration) so `old_link` is genuinely already gone by the time the
second attempt lands.

Fix: add the missing prompt (matching whatever the function's other,
correct call sites already write immediately before arming the same
`input_to`) and correct the argument to the type the callback actually
declares — here, a plain default `int` (`0`), matching every other
normal call site's convention. Verified live: before the fix, two
consecutive rapid reconnects reliably swallowed the second session's
next command into a fake-registration prompt; after the fix, the same
sequence completed normally with `look`/`score` both executing as
ordinary commands.

### 8.17 An account-existence check reads disk save-file presence only, never a live/net-dead in-memory body — so a brand-new registrant who disconnects before their very first save looks permanently "never registered" to their own reconnect attempt

Found on `xajh2`'s deep functional test (§10.7), as a downstream
consequence of an ordinary §7.14-class missing-room bug: a fresh
registration's post-`enter_world()` move to a hardcoded newbie-start
room (`/d/place/newbie/start`, a path this archive's `d/place/` never
actually ships) threw an UNCAUGHT `*call_other() couldn't find object`
error — and because that move sits textually BEFORE `user->save()`/
`ob->save()` near the tail of `enter_world()`, the throw aborts the rest
of the function outright, so **no save file is written to disk at all**
until the next periodic autosave or net-dead force-quit (both 900s
later) fires. That part alone is an ordinary instance of the
already-cataloged "guard the move, fall back to `START_ROOM`" fix
(§7.14) — the genuinely new finding is what this delayed-first-save
window exposes: `system/daemon/logind.lpc`'s `get_id()` decides "does
this id already exist" purely from
`file_size(ob->query_save_file() + __SAVE_EXTENSION__)` — it never
consults `find_body(arg)` for a live or net-dead in-memory body (that
check only happens LATER, in `get_passwd()`, which is unreachable
without first passing the disk-existence gate). A brand-new player who
disconnects uncleanly — the single most common real-world disconnect
mode — within their first ~15 minutes therefore has a genuinely live
(or net-dead, reconnectable) body sitting in server memory, but ANY
reconnect attempt during that window is told **"对不起，这个id还没有
登录过，请用new来起用这个id"** ("this id has never logged in") — reads
exactly like account/data loss to a real user, even though nothing was
actually lost.

Distinguish from §7.20/§7.21: those are both about a `net_dead()`-found
body's LOCATION not being correctly restored on reconnect — the body
IS found. Here the body is never found at all, because the very first
gate in the login flow short-circuits on disk state before any
in-memory lookup ever runs.

Detection: on any lib whose registration flow can leave a real save
write DELAYED past the initial `enter_world()` call (an uncaught throw
per §7.14/§7.33, a deliberate "must play N minutes before first save"
retention policy, or any other reason a brand-new account's first save
might not land immediately), check whether the login flow's own
"does this id exist yet" gate consults `find_body()`/an equivalent
live-body lookup BEFORE falling back to a disk check — if it's
disk-only, a legitimately-alive new account can be told it doesn't
exist. Reproduce by registering fresh, forcing (or waiting for) the
delayed-first-save condition, then reconnecting before the first real
save has landed.

Fix: guard the newbie-room move the same way §7.14 already prescribes
(`catch()`, falling back to the already-validated `startroom`) so the
save actually happens promptly in the common case; as defense in depth,
have the existence check also try `find_body(arg)` before concluding an
id has never registered, so a delayed-save window (from this cause or
any other) can't itself manufacture a false "never registered" verdict.
Verified live: post-fix, fresh registration landed in a real room (not
void) and — the primary fix already prevents the delayed-save window
from being reached in the first place for this specific trigger — a
save file existed immediately after registration, before any reconnect
was attempted.

---

## 9. LPC formatter (`~/src/fluffos/tools/lpc-syntax/`) — required checks

`find libs/<slug>/work -name '*.lpc' | node .../bin/format-corpus.mjs`
formats in place, gated on token-equivalence + idempotency self-checks.
A nonzero `errors` count (files it refused to touch) is normal on messy
legacy code. **The self-check has three known blind spots — after
formatting ANY lib, run all three checks, then re-boot and re-test:**

1. **`::` parent-call split** — `return ::do_read(arg);` mis-tokenized
   into `: : do_read(...)`, sometimes restructuring the whole statement;
   broke two libs' player-body classes (`::move()`/`::query()`).
   Detect: `grep -rnE ':\s:\s*[a-zA-Z_]+\(' libs/<slug>/work` — any hit
   is this bug. Fix by reverting just that file (`git checkout --
   <path>` — but see §10.5), not by hand-repairing the mangled output
   or rewriting the mudlib's call. The driver-repo fix for this is
   MERGED upstream; a freshly cloned/updated `fluffos` won't reproduce
   it on new formatter runs. The grep remains useful for auditing files
   formatted before the merge.
2. **`case` label + trailing `//` comment merge** — the comment swallows
   the start of the next line's statement, silently deleting it
   (`zsdsj`'s gender-selection crash). No clean grep;
   diff-review case-heavy files after formatting.
3. **Pre-existing unbalanced quotes → garbage re-spacing** — on a file
   whose quotes were ALREADY unbalanced (author typo), the formatter's
   tokenizer loses sync and re-spaces whole regions: CJK characters
   split apart with spaces, escape sequences broken (`\n` becomes
   `\ n`). Detect with a CJK-respacing diff scan — e.g. flag any
   formatted file whose diff introduces space-separated CJK sequences
   or a backslash-space-letter escape:
   `git diff -U0 -- '*.lpc' | grep -nE '^\+.*(\\ [nrt]|[一-鿿] [一-鿿] [一-鿿])'`.
   Also works at rest (no diff needed):
   `grep -rl '\\ n' libs/<slug>/work --include='*.lpc'` — on this corpus
   that signature found 214 damaged files with exactly one false
   positive (verify any hit against the file's pre-format git blob
   before reverting: if the `\ n` predates formatting it's original
   archive content, leave it). Fix by reverting the FILE (then
   optionally fix the original unbalanced quote by hand — the
   underlying typo is usually a real §6.6 bug worth fixing separately).
   Confirmed again on `kxkjii2` (6 files) — the corpus-wide grep still
   finds real instances on new libs; keep running it every pass, not
   just once.

The formatter is cosmetic; losing formatting on a handful of files is
always the right trade for correctness.

---

## 10. Testing methodology and multi-session hygiene

### 10.0 Long-sit boot watch (catches lazily-loaded daemon failures)

A registration+look+score+quit smoke test only runs for ~20-30 seconds
and only touches whatever the login flow itself loads. Daemons that are
lazily loaded by a periodic heartbeat, a scheduled `call_out`, or an
on-demand `call_other` from some OTHER subsystem never get exercised by
that test and can be silently broken (compile error, missing efun under
WASM, `Undefined function`) without anyone noticing until a player
happens to trigger them days later. `scripts/wasm_boot_watch.sh <slug>
[duration_sec]` (default 200s, i.e. >3 minutes) boots a lib under WASM,
opens one connection, and just sits there — `--idle` is set higher than
`--timeout` so it never exits early on silence — capturing the full
`print()`/`printErr()` transcript to `/tmp/wasm_boot_watch_<slug>_*.log`
and grepping it for common failure signatures as a first pass (`error`,
`Fatal`, `错误`, `Undefined function`, `cannot be loaded`, etc., with
known-noisy lines like the mudlib error-handler's own boilerplate
already filtered out). Treat the grep as a STARTING POINT, not a
verdict — read the actual transcript before concluding a lib has a
real problem; a `nosave void crash(string error, ...)` parameter named
"error" matches the same grep and means nothing. Known pre-existing
harmless line: `Unable to open log file: "log/debug.log", error: "No
such file or directory"` fires once very early in WASM boot (before
`work/log/` is mounted) and is cosmetic — the driver continues fine.

### 10.1 The verification bar

For every lib, native and WASM: fresh registration with a real Chinese
name reaching an actual room, then `look` + `score` + `quit` each
producing correct output, then a debug.log review for errors. Do the
whole flow in ONE continuous client session. Where a lib has
gender/ethnicity branches, testing both once caught real content bugs
(wrong-gender gear, missing rooms) — cheap and worth it. Re-login
(restore path) is a distinct code path from registration; verify it at
least once per lib.

### 10.2 Driving the client

`python3 scripts/mudclient.py 127.0.0.1 <port> --timeout N --send ...`.
Use `--idle 0.3`–`0.5` on any lib whose prompt shows a live clock
(§8.3 item 1). One `--send` at a time when a flow behaves confusingly. WASM:
same interface via `scripts/wasm_client.js` (§1.2).

For a flow that needs several separate sequential commands with real
state in between (a multi-step registration ritual, walking through
several rooms, a fight that needs `attack` then a few `look`s to watch
it resolve) — each `mudclient.py` invocation opens a NEW connection, so
it can't carry session state (a mid-ritual account/character) across
calls. `scripts/tmux_mud.sh {start|send|read|stop} SESSION [...]` keeps
one real telnet connection alive in a tmux session across as many
separate tool calls as needed: `start SESSION HOST PORT`, `send SESSION
"text"` (one line, or `""` for a bare Enter), `read SESSION [LINES]`
(non-blocking pane snapshot — `sleep` between send/read since there's
no generic "done producing output" signal), `stop SESSION` when done.

**`read`'s pane snapshot is cumulative scrollback, not "what happened
since your last command."** A `sendread`/`read` with a generous
`LINES` count can still show an error or message from several commands
ago sitting just above the new output, because the requested line
count doesn't line up with how much new text the last command actually
produced (long room descriptions push old lines further up, so what
looks like "the error that just happened" may be stale). Confirmed live
on `xkm`: a board-read error appeared to recur on a second `read <N>`
right after a fix was applied, but a follow-up bare `read` with a
smaller line count and a fresh, distinct command showed it was actually
gone — the first apparent recurrence was leftover scrollback from
before the fix. Before concluding a fix didn't work (or a bug is still
live), send one more clearly-distinguishable command and check that ITS
own output, not just any matching text in the captured pane, confirms
the failure.

**A local `telnet`-CLI-backed tmux session can mangle specific CJK
input bytes before they ever reach the driver — don't mistake a
transport artifact for a server-side `is_chinese()` bug.** On
`zjdywzb`, sending certain single Chinese characters (者 U+8005, 考
U+8003) through `scripts/tmux_mud.sh` got rejected at a Chinese-name
prompt with "请您用「中文」取名字" (`is_chinese()` returning false),
while other characters (老 U+8001, 王, 五, 张, 三) sent the identical
way went through fine — no consistent range/byte pattern explained
the split. Reproducing the exact same input through
`scripts/mudclient.py` (a raw socket client, no local `telnet`
process or pty in between) accepted every character cleanly,
including the ones tmux had rejected. The local `telnet` binary (or
its pty) was corrupting specific UTF-8 byte sequences in transit —
not a driver or mudlib bug at all. If a Chinese-name/text prompt
rejects a real, valid Chinese string sent via `tmux_mud.sh`, retry the
identical input through `mudclient.py` before concluding `is_chinese()`
or any name-validation code is broken; only trust the `tmux_mud.sh`
result once the raw-socket client agrees.

**`mudclient.py`'s `--idle`-based "wait for silence, then send the
next line" pacing can starve forever against a live-updating clock
prompt (per §8.3's ticking-prompt libs).** If the prompt reprints
every ~1 second, `--idle 1.0` (or any value ≈ the tick interval) races
the next tick and can lose indefinitely — commands after the first one
or two silently never get sent, and every subsequent `--send` line
(even a trivial, always-safe one like `look` or `score`) shows zero
server response, which looks identical to a hung/crashed connection.
Confirmed on `zjdywzb`: `wash`/`born <地名>`/`score` all produced no
visible output whatsoever with `--idle 1.0` against its per-second
prompt clock, and the driver/debug.log showed nothing wrong. Lowering
to `--idle 0.5` (comfortably under the tick interval) fixed it
immediately — every command got sent and answered. `scripts/tmux_mud.sh
multi`'s *fixed* `per_wait` between sends (not idle-detection) doesn't
have this failure mode and is the more robust choice against a
ticking-clock lib; if using `mudclient.py`'s reactive `--idle` pacing
against one, drop `--idle` well below the tick interval rather than
raising it.

### 10.3 Instrumentation techniques that work

- The driver swallows errors escaping `logon()` (`safe_apply` discards
  the LPC error entirely — no trace anywhere) and disconnects silently.
  A plain LPC `catch()` DOES intercept first — wrap the smallest
  enclosing statement, and print with `efun::write(err)` (reaches the
  client reliably; `write_file()` may be ACL-denied that early).
  Checkpoint-bisect with `efun::write("CKPTn\n")` lines.
- Instrument master applies with
  `efun::write_file("/DEBUG.log", sprintf("%O %O %O\n", ...))` to see
  exact ACL decisions rather than guessing from generic "access denied"
  messages.
- **Remove ALL instrumentation and restart the driver** — objects never
  recompile from disk changes on their own; a leftover checkpoint once
  shipped into a login banner because the running process predated the
  cleanup edit.
- One stray non-fatal error line in an otherwise clean boot is not
  automatically a work item — read the surrounding code and check
  whether its purpose already succeeded (§7.14 versiond example).

### 10.4 lpcc sweeps: batch mode, false positives, memory

- `scripts/lpcc_check.sh` / `lpcc --batch` boots ONE VM for the whole
  file list (15-70x faster than per-file). If you ever touch the batch
  code again: `set_eval(max_eval_cost)` must be re-armed per file (it's
  a real OS timer, not a counter — without it, later files spuriously
  fail "Too long evaluation").
- Expected false-positive categories — triage failures by error-message
  group before fixing anything: `#include`-only fragments compiled
  standalone (main_file_name()-dependent checks fail); hardcoded-path
  call_others to objects that don't exist in isolation OR genuinely
  missing content (§7.14); `valid_override` 2-arg gaps that never fire
  in a real boot. Cross-check any lpcc-only failure against the real
  boot log before believing it.
- **Memory**: batch mode never unloads; a mega-lib sweep can eat all
  host RAM (54k files ≈ 23GB host driven to <400MB free; one 7k-file
  lib with huge mapping literals did the same). Watch `free -h` during
  ANY sweep, kill it if RSS balloons — on mega-libs the boot +
  interactive test is the sufficient verification gate; the sweep is
  nice-to-have.
- `valid_override` needs the 3-arg signature
  (`valid_override(file, name, main_file)`) for `#include`d simul_efun
  fragments — apply on sight when reading master (mostly an lpcc-noise
  fix, but free and correct).

### 10.4a An ASAN/UBSAN-instrumented driver build can make a lib's preload look 10-20x slower than it really is — don't diagnose that as a content-level bug before ruling out the build

`nitan_san` had 5 separate attempts (up to 58 uninterrupted minutes
each) to boot against `~/src/fluffos/build` (ASAN/UBSAN-instrumented)
never finish preload, versus its near-identical sibling `nitan_ceshi`
finishing in 90 seconds–2 minutes on the same build. That gap led to a
documented (wrong) conclusion: "10-20x slower than a same-size sibling,
suspected content-level issue in this specific snapshot, needs a
dedicated root-cause pass (bisect preload order, comment out chunks)."
The actual cause: those attempts used the sanitizer-instrumented build.
Re-tested with `~/src/fluffos/build-debug` (uninstrumented) and preload
completed in 33 seconds — matching the sibling exactly. ASAN/UBSAN
overhead is not uniform across code shapes; it can be dramatically
worse on whatever this lib's preload happens to stress (large nested
data literals, heavy string/array churn, etc.), so a "10-20x" gap
between two similar-sized libs on an instrumented build doesn't mean
anything is wrong with the slower one's content.

**How to apply:** before spending a root-cause session on "this lib's
boot/preload is mysteriously way slower than a similar-sized sibling,"
check which driver build was used. If it was an ASAN/UBSAN build,
re-test with the plain `build-debug` (or equivalent uninstrumented
build) first — that alone has fully explained every such case seen so
far in this corpus. Only escalate to a dedicated content-level
bisection if the slowdown reproduces on an uninstrumented build too.

### 10.5 Process hygiene (multi-session/multi-agent)

- **Don't arm a background Monitor/wait around a boot-watch loop and
  then go quiet expecting it to resume you.** This has repeatedly left
  agents stuck for hours with zero progress (no live process, no file
  activity) — the orchestrator has had to notice the staleness and
  force a resume more than once. Run `scripts/wasm_boot_watch.sh` (or
  any other blocking command) directly and wait for it to return in
  the same turn; don't delegate "notify me when this finishes" to a
  Monitor for a loop you're about to sit through anyway. If you
  legitimately need to wait on something (a slow conversion script,
  say), the orchestrator's own equivalent lesson applies: verify the
  watched PID is still alive before trusting a "waiting" status is
  real, not stale.
- **Kill drivers by exact recorded PID, NEVER `pkill -f` a pattern** —
  every lib's driver shares an identical command line; broad pkills
  have twice killed other sessions' drivers mid-test. After any kill,
  VERIFY with `ss -tlnp`/`ps` — a kill command returning is not the
  process dying (one stray driver survived a failed pkill for days).
- Launch long-running drivers with `setsid nohup ... & disown` or the
  tool-provided background-run option — plain `nohup ... &` has died
  from stray SIGTERMs between tool calls in this environment.
- Parallel conversion batches worked well with: one lib per agent,
  agents never editing shared files (this file, README, numbering),
  and the coordinating session verifying each agent's key claims
  against the actual tree (fix present, exclusions applied, no
  lingering driver process) before committing.
- **`git checkout <rev> -- <path>` STAGES the restored content by
  design.** In a multi-agent working tree this contaminates someone
  else's in-progress commit with your restored files. Use
  `git restore --source=<rev> -- <path>` (unstaged) instead, or
  immediately `git restore --staged` what you didn't mean to stage.
  Never `git add -A`/commit broadly while other sessions may have
  work in flight; commit exact paths.
- **NEVER `git stash` in this shared working tree, for ANY reason,
  even briefly for debugging.** `git stash` operates on the ENTIRE
  working tree unconditionally — unlike `git checkout -- <path>`,
  there's no way to scope it to files you own. If any concurrent batch
  agent is mid-write to a file at the moment you stash, your stash
  captures whatever partial/complete state that file was in, resets it
  to HEAD, and if the other agent's tool (Edit/Write) touches that file
  again before your `stash pop`, the pop can silently clobber or lose
  their newer edit with no conflict warning — `git stash pop` reporting
  success is not proof nothing was lost. Hit directly: debugging a
  suspected regression by stashing/popping around a `git diff`
  comparison coincided with another concurrent agent's `NOTES.md`
  write for an unrelated lib, and that agent's documented "深度功能测试"
  section was missing from the file afterward even though its actual
  code fixes (committed separately, timestamped after the stash
  window) survived intact — plausible but not conclusively proven as
  the stash's fault, and that ambiguity is itself the lesson: this
  class of interference is very hard to detect after the fact. If you
  need to compare against a prior committed version while other work
  may be in flight, use `git show <rev>:<path> > /tmp/scratch` (reads
  without touching the working tree) instead of stash/checkout/reset
  on the real path.
- Runtime state must not be committed: player saves, visitor counters,
  ban lists generated during testing (the repo `.gitignore` has a
  per-lib section — extend it when a new lib's testing dirties a new
  path). Counterexample to stay alert for: a gitignore pattern meant
  for one lib's RUNTIME ban list silently excluded another lib's
  SHIPPED static `banned_name` content file (`yueyingqiyuan`),
  breaking name registration in fresh clones — prefer lib-scoped
  ignore patterns over repo-wide ones.
- **Merge queue for parallel batches: `scripts/safe_commit_batch.sh`.**
  All batch agents share ONE working tree (no per-agent worktrees), so
  several batches routinely have unstaged edits under different
  `libs/<slug>/` trees at the same moment. Never `git add -A` or
  hand-eyeball a giant `git status` dump to decide what's "this
  batch's" — use the script:
  `scripts/safe_commit_batch.sh [--dry-run] <slug1> [slug2 ...] [+ extra_path ...] -- <msg-file>`.
  It resets the index, stages only `libs/<slug>/` for each given slug
  (plus any explicit extra paths after a literal `+`), verifies every
  staged path actually falls under an owned prefix, and REFUSES (fully
  unstaging, no commit) if anything else snuck in — that's the signal
  another batch's in-flight write landed somewhere unexpected, or the
  slug list handed to it was wrong. Only on success does it commit and
  `git push origin main`. Use `--dry-run` to check a batch's isolation
  before it's actually ready to land (stages, validates, prints the
  diff, unstages, no commit/push). This formalizes — and should fully
  replace — manually re-deriving "what belongs to this batch" from
  `git status` output.
  **Caveat**: the script's per-slug staging is `git add libs/<slug>/`
  — a real directory add, which happily sweeps up any deferred/
  excluded runtime-save content sitting untracked under that lib
  (large economy-save shards, deliberately-skipped huge data files —
  `nitan170911`'s `data/bbased.o` is 157MB, over GitHub's 100MB push
  limit with no LFS configured in this repo, and got past the script's
  "stayed within the owned prefix" check since it's genuinely under
  that lib's own path). A push can fail *after* the commit already
  landed locally — recoverable with `git reset --soft HEAD^` (safe
  pre-push, nothing shared yet) followed by re-staging file-by-file
  instead of the whole slug. For any lib with a known deferred-content
  history (check its NOTES.md / earlier commit messages), stage exact
  paths by hand rather than trusting the blanket per-slug add.
- **Publishing: normal `git push origin main`.** This worktree tracks
  `origin/main` (`github.com/fluffos/mudlibs`) directly. `archives/`
  is gitignored — the original archive files live there locally for
  provenance (never published: copyrighted third-party content;
  `scripts/lib_numbering.json` maps number↔slug↔archive filename).
  Never commit anything under `archives/` or force-push over `main`.
  (Historical note: an earlier era used a filtered side-clone because
  the local history predated the filter-repo pass; that history is
  preserved on the local `backup-unfiltered-history` branch and can be
  deleted, plus `git gc`, if the ~20GB of old objects are ever needed
  back as disk space.)

### 10.6 English-language archives

Standing policy: deprioritized. Confirm what an English lib is, note
it, don't sink conversion time (`ds386` Dead Souls partial;
Discworld bundles untouched). Revisit only on request. `ds386`'s
`libs/` directory was later purged entirely as permanently out of
scope (2026-08-05, alongside four other structurally-rejected libs —
duplicates, no standalone master object, or a non-shared driver
requirement); its bug-pattern notes elsewhere in this file remain
valid precedent for future English archives even though the lib
itself is gone. Raw archive preserved at `archives/006_ds386_ds3.8.6.zip`.

### 10.7 Deep functional testing methodology (round two)

Every prior verification layer for this corpus — `lpcc --batch`
compile sweep, boot-log watch, registration-through-login smoke test —
proves the driver *starts*. None of them proves the game *works*.
Case in point: `bxsj`'s `cmds/usr/quit.lpc` unconditionally called
`TOP_CMD->add_rank(me)`, which crashed on every single `quit` for
anyone whose stale shipped leaderboard data hit the runaway-loop bug
in §7.16 — invisible to boot watch (happens at quit, not boot),
invisible to registration testing (happens after, not during, login),
and invisible even to a `quit`-and-look-at-the-screen check, because
the driver's error handler swallows the crash and the player-visible
"正在退出游戏……" message prints exactly as if nothing went wrong. The
only way this surfaced was a full, continuous playthrough session
plus a `debug.log` grep after every `quit`. That is the bar for round
two: pick a lib, actually play it, fix what breaks, write it down.

**Scope: PROGRAMMING bugs only, never game-content/design judgment
calls.** This applies to every deep-test pass — fix compile errors,
clearly-wrong efun/simul_efun usage (bad argument types, a call the
driver's own type check explicitly rejects), driver-API misuse causing
crashes (reentrancy, missing `return`s, missing `objectp()`/`stringp()`
guards, calling a create()-only primitive from `init()`), and obviously
wrong variable references (a typo'd `-` for `->`, `this_player()` used
where `this_object()` was clearly intended). Do NOT fix game balance
(an NPC seems too strong, a reward amount, a shop price), internally
consistent design choices even if surprising (death dropping items, a
"safe" spar that isn't perfectly safe, a level-gated sect), or any
content/quest question where the fix would require deciding what the
game SHOULD do rather than making its own already-intended logic
actually work. When genuinely unsure which bucket a finding falls in,
document it honestly in the lib's NOTES.md as an observation and leave
the code untouched — don't guess.

Distilled checklist, generalized from the first full pass (`bxsj`,
see `libs/bxsj/NOTES.md` "深度功能测试" for the worked example):

1. **Read the lib's own newbie help first** (`help newbie`, `help
   intro`, or equivalent — grep `cmds/` or `doc/` if the command name
   isn't obvious). It's usually the fastest way to learn the intended
   test path — starting zone, first skill, how sects/factions work —
   without guessing from source alone.
2. **One continuous session, not disjoint probes.** Register with a
   real Chinese name (per the existing verified-registration rule),
   then `look`/`score`/`i` (or the lib's equivalents) at every major
   state change: after register, after first move, after learning a
   skill, after joining a sect, after combat, after quit/relogin.
   Read room/NPC `.lpc` source when navigation isn't obvious rather
   than guessing directions blind.
3. **Find the lib's own safe-sparring mechanism before hunting a
   "weak enough" wild NPC.** Many libs ship a training dummy or
   equivalent whose `accept_fight()` mirrors the attacker's own stats
   (grep `accept_fight` plus a stat-copy loop as the pattern to look
   for) — use it for the first combat test instead of risking a real
   fight going wrong for unrelated reasons.
4. **Test skill/sect acquisition through two separate paths**: the
   organic teacher-NPC route AND any direct sect-join shortcut (newbie
   gift, admin command, etc.), since they can be gated behind each
   other in ways that only show up when both are actually exercised.
5. **`quit`, grep `debug.log`, THEN reconnect after a real wall-clock
   gap and confirm state.** Do not skip the debug.log grep just
   because the visible quit message looked normal — that's exactly
   what hid the `bxsj` bug. Note the quit-retention lockout window and
   silent-reconnect behavior (a fresh connection within the lockout
   window can skip the full login code path if the prior session
   didn't end in a real `quit`) before assuming a relogin exercised
   what you think it exercised.
6. **Budget real time for shop/economy and death/respawn, or say so.**
   These two systems are the most likely to require genuine travel,
   gold, or being deliberately outmatched to reach — code review is an
   acceptable fallback ONLY if stated explicitly as unverified-live in
   NOTES.md, never silently presented as tested.
6a. **If a death/resurrection sequence with an admin test character
   never progresses past idle NPC chatter, check the ghost-guard's
   `init()` for a `wizardp(previous_object())` exclusion before
   assuming a §7.68-class soft-lock.** Found on `hy2000`: the standard
   admin test account is itself `wizardp()`, and `d/death/npc/
   wgargoyle.lpc`'s `init()` deliberately never schedules
   `death_stage()` at all for wizard ghosts (staff are expected to
   self-recover via wizard commands, not occupy the NPC-driven revival
   flow) — this is normal, intentional design, not a bug. A
   second, non-admin test character died and resurrected cleanly and
   quickly (all stages, correct `reincarnate()`, landed at the revive
   room) on the exact same lib, proving the sequence itself was never
   broken. When an admin-account death sequence stalls, register a
   throwaway non-admin character before concluding anything is wrong.
7. **Fix what you find, in-place, and write it up immediately**: the
   bug, the file:line, the fix pattern, and the test character/state
   left as evidence — in the lib's own NOTES.md — plus a new AGENTS.md
   bug-class entry (like §7.16) if the underlying pattern is likely to
   recur in sibling or unrelated libs. Check documented siblings
   (§11) for the same pattern before moving on — a bug found this way
   in one lib has repeatedly turned out to be copy-pasted into others.

### 10.8 Long-sit soak testing can surface driver-fatal crashes invisible to `debug.log` entirely

Found on `xjcq2000`'s deep functional test (§10.7): ~25 minutes into an
otherwise-ordinary session, the whole driver process died outright —
`FATAL: Object .../d/xingxiu/silk6 ref count 0, but not destructed
(from free_svalue)`, a driver-level internal-consistency check, not a
catchable LPC error. **`debug.log` showed nothing whatsoever** — the
only reason this was caught at all was the driver's own stdout being
redirected to a file; without that, this class of failure leaves
**zero evidence** and just looks like "the connection dropped."
Established mechanism (a testing-methodology lesson, not a resolved
bug): ambient NPC `heart_beat()`→`random_move()` wandering, given
enough wall-clock time, forces lazy compilation of nearly the entire
map, including zones no test character ever visited — sustained
compiling/cloning/destructing across that much of the lib eventually
corrupts some object's refcount, silently, until an unrelated
`free_svalue()` call touches it and aborts the whole process. Not
pinned to a specific LPC file:line — flagged honestly as unresolved.
**Actionable takeaway**: capture the driver's own stdout (not just
`debug.log`) for the full duration of any extended idle-connected
session — this class of crash is otherwise completely invisible.

**Five further independent occurrences, corroborating but each still
unpinned to a reliably-reproducible trigger:**

| Lib | Signature | Timing | Trigger |
|---|---|---|---|
| `shiji` | `ref count 0, but not destructed` (`cmds/skill/recruit`) | ~20 min | admin reconnect |
| `shenzhou` | `debugmalloc: free non-malloc'd pointer` → `abort()` | ~10-11 min | driver's own periodic 5-min GC sweep |
| `xlqy_new2007` | `ref count 0, but not destructed` (`std/skill`) | idle between test steps | natural idle time, just after triggering that lib's §7.12 bug |
| `nitan170911` | `free_string called on non-shared string` | mid a net-dead soak | player's own net-dead body |
| `yhyxs` | outright `Segmentation fault`, no caught error at all | ~16 min | driver's own periodic reset sweep (`backend_run_one_gametick`→`reset_object`) |

No LPC-level fix applied or expected in any of these — this is
driver-internal memory corruption, not a mudlib bug. Six occurrences
now, across six unrelated libs/lineages, different corrupted
structures (objects, a string, a bare segfault) and different
immediate triggers, same underlying shape: silent memory corruption
during ordinary extended play that eventually kills the whole process,
invisible to `debug.log`. Corroborating evidence the class is real and
not a one-off, but still root-caused to the driver level, not any
specific mudlib pattern — worth flagging to the human maintainer for a
dedicated driver-level investigation (ASan/valgrind against a long-sit
soak) in the `~/src/fluffos` checkout itself, rather than continuing to
treat each new occurrence as a per-lib mudlib finding.

---

## 11. Lineage map — who shares code with whom

Porting proven fixes across siblings is the single biggest
time-multiplier in this project (§2.1). Families established by actual
core-file diffs (numbering from `lib_numbering.json`; members listed
base-first):

- **ES II / 东方故事 mega-family** (the region's common ancestor
  mudlib; expect §6.1 include fixes, §8.1, §7.12 message wrappers,
  §4.3 collisions): `es1_win`/`esI` (008); and ES II-derived but
  distinct games: `xkx2001`/`bmxkx2001` (017), `xuanjianlu`
  (046), `rzrmud` (016), `wuhanzhan` (040), `haiyang2` (043)
  with confirmed derivative `hymud` (043-1, byte-diff confirmed same
  codebase), `huoying` (044, Neolith), `shenzhou` (048),
  `shenmo` (049, Neolith), `zitengzhan` (051), `zhongjidiyu` (052),
  `xixingzhanji` (054), `tiexuejianghu` (056), `syxjl` (057),
  `mohuanshiji` (058), `yueyingqiyuan` (037),
  `kxkj`/`kxkj1`/`kxkjii2` (036, §7.101's "ES II/Annihilator" death-
  recovery bug — `kxkj` unfixed, port the same fix there next time it's
  touched) with a further, more distant sibling by the same `master.lpc`
  header ("for ES II mudlib / original from Lil / rewritten by
  Annihilator (11/07/94)"), `xajdxyj` (107, 西安交大西游记/《欢乐园》 —
  its own death-recovery flow is NPC-`call_out()`-driven rather than
  `exits`-map-driven, so §7.101 does not apply there, but its
  `adm/simul_efun/message.lpc`'s `shout()` had the §7.12 unguarded-
  `this_player()`-as-exclude shape, fixed),
  `yxcs` (042, hybrid ES/nitan), `xkxz2` (028),
  `dfgs2` (022), `zzhj` (061, explicit in-game
  credit: "FF 的 MUD 函數庫改寫自東方故事 II" — a small, distinctly-
  shaped ES2 extension by a different author ("Spock"), not a
  derivative of any other single member here).
- **西游记 / xiyouji.org branch of ES II** (§6.6's convertd Greek table,
  §7.6 mirror-site gates): `xiyouji` (010, the ancestor snapshot) with
  `xyj2000f`, `xiyouji2003`, `xiyouji450`, `xiyouji2006`;
  `mhxy`/`mhxyqd` (012, 梦幻西游 branding);
  `shenmo` (049) is a far-evolved fork; `wuhanzhan` (040) a 大话西游
  sibling; `aoxiangtianji` (063) is another far fork — rebranded from
  an old 西游记 base (login banner/system strings still literally say
  "西游记"/"Xi You Ji" in places despite the game itself being
  翱翔天际-branded throughout).
- **yh2003**: `yanhuangwuhun`/`yhyxs` (045).
- **金庸群侠传 engine**: `jqxz2008` + `_std` + `_deluxe`
  + `2015` + `xiakexing3` (031) — engine layer frozen across 7 years,
  fixes port 1:1.
- **书剑 (ShuJian)**: `bxsj`/`bxsj1`/`jinyongwenzi` (004) — literal
  same codebase. Unrelated to `shujian2008`/`sjtx2` (024,
  Century family) and `sjpl2` (025) despite titles.
- **Century / adm-single family** (custom securityd ACLs — §7.5 on
  sight): `shiji` (021), `shujian2008` (024), `xjcq2000` (027),
  `xkxz2` (028), `xiakexing100` (030), `zhonghua2` (023,
  related shape).
- **风云3 engine**: `zzfy`/`fy3xd`/`fy3dz` (020),
  `moniHuafu` (039, own game). `zzfy3` (139) is a NEAR-DUPLICATE of
  `zzfy` (020), not previously cross-referenced — same title (郑州风云3),
  same ~10,345-file map/engine, `diff -rq` on the two `work/` trees
  returns only 183 differing files (mostly individual NPC price/dialogue
  tweaks, a handful of already-independently-applied bugfixes on one
  side or the other, log/save-state noise) — almost certainly two
  operators' independently-run, slightly-diverged copies of the same
  original archive rather than two different games (found during
  `zzfy3`'s own §10.7 pass; not worth un-converging the two separate
  `libs/` entries retroactively, same call as the `jyqxc`/`jyqxc2`
  near-duplicate pair below — but any future fix to one should be
  cross-checked against the other, same shared files: §7.24 (death
  code overwriting startroom), §7.25 (unguarded room-population
  `new()`/`move()`), §7.102 (unguarded exit force-load in `go.lpc`),
  §7.103 (compile-warning leak in `log_error()`), and a bad
  `/obj/example/wineskin` vendor path in 13 shared NPC files were all
  found+fixed on `zzfy` first and ported to `zzfy3` in the same session
  that discovered the duplication; `zzfy` itself still carries the
  `go.lpc`/`"新手学堂"` exit bug (§7.102) unfixed, and possibly the
  §7.103 warning-leak was the only one already independently fixed on
  `zzfy`'s side — check both directions, don't assume either lib is
  strictly "ahead" of the other).
  **风云Ⅳ**: `fengyun434`/`fy2005` (009).
  **风云再起Ⅱ**: `fy2`/`fy2qh` (011). Family-wide idioms:
  securityd `resolve()` ordering (§1.3c), environment(me) quit race
  (§7.14), phone-home checks (§7.13).
- **夕阳再现 family**: `xyzxfk`/`_fengyun2`/
  `jhfy` (032); derived own-games `wmkj` (038),
  `bixiecanyang` (047), `xajhzcjh` (050).
- **XYZX/炎龙封印 branch**: `xyzx3`/`ylfyxa3`/
  `longyunmeng` (033; `longyunmeng_binary` 033-3 not convertible).
- **XO / TMI-2 / Falcon**: `xo`/`xo_final`/`xajh2`/
  `xajhxo` (019). NOT nitan, despite 笑傲江湖 titles.
- **NT / nitan / Lonely**: `nitan170911` (014), `nitan6` (015) — §7.15
  applies; `nitan_ceshi`/`nitan_san` (041) — earlier branch, §7.15
  does NOT apply. Mega-libs; §10.4 memory rules.
- **"hell" / Doing Lu**: `zjdyaryl`/`zjdyzj`
  (053). `zhongjidiyu` (052) is UNRELATED despite the identical title.
  `xkxc98sj` (113, 「侠客新传」) is a further confirmed member — its
  `adm/single/master.lpc` is byte-identical (mod CRLF) to `hell`'s,
  header included ("for ES II mudlib ... modified by Xiang for XKX
  (12/15/95) ... updated by Doing Lu for hell (2K)"); despite the
  shared "XKX"/"侠客" branding this is NOT the same codebase as the
  `xkx100`/`xkx2017` family (§2.1's naming-is-not-lineage lesson
  again — confirmed by diff, `xkx100`/`xkx2017`'s own master.lpc stops
  at "modified by Xiang for XKX", no "hell" line at all). `securd.lpc`
  has independently drifted (813 vs 796 lines, Chinese-translated with
  a further "Last modified by Jjgod Jiang for FYTX" credit) — same
  root, not a byte-identical fork. See also §7.42's Century/adm-single
  bulk-convert note (`zjdywzb`/`zjdy2008wzb`/`hell`/`xkxc98sj`/`ntii`/
  `nte` all share the "content NPC named master.c" auto-detection trap)
  and §7.81's "hell"-lineage `set_information` wrapper instances
  (`yhwhpublicfi`, `zjdy2008wzb`, `xkxc98sj`) — the wider family is
  broader than core-file-diff-confirmed here, but these are all at
  least documented as sharing recognizable idioms.
- **XLQY 仙侣情缘**: `xlqy_new2007`/`xlqy_early`/`xlqyzdb`
  (018); `xianlvqiyuan` (026) is a different, older codebase.
- **小雨西游**: `xyxy2`/`xiaoyuxiyou` (003).
  **大唐双龙**: `dtsl`/`dtslmud`/`dtsl2`
  (007).
- **Standalone/distinct**: `shzs` (001, simple/ES-derived),
  `xzyx` (002), `chidi` (005), `xiakexing2017` (013),
  `tianxia` (034), `tianxiawuxue` (035), `xkyx3b` (029),
  `zsdsj` (055, GPLv2 BIG5 life-sim, custom dispatcher —
  nothing ports in or out), `sjcs` (059) and
  `sanjieshenhua` (060, "三界神话") — share only their "三界" branding,
  NOT a lineage pair (diff-confirmed: `master.lpc`/`securityd.lpc`/
  `logind.lpc` all differ substantially in size and shape between the
  two).
- **驰骋天下 / cctx family**: `cctx` (066) and `niaoren` (062,
  "鳥人世界") — CONFIRMED same codebase (not just superficially
  similar), found via `niaoren`'s §10.7 deep functional test after its
  `logind.lpc` talent-selection prompt turned out to be a word-for-word
  match with `cctx`'s ("一個人物的天賦...俠馳騁江湖中的人物大多具
  有...", traditional/simplified conversion aside), and clinched by
  `niaoren`'s `adm/daemons/logind.lpc` still literally calling
  `read_file("/adm/etc/cctxinfo")` — a leftover filename from `cctx`'s
  own codebase, never renamed when `niaoren` forked off and rebranded
  as a Jin Yong "鳥人世界" (15-novel premise) setting. `master.lpc`/
  `logind.lpc` are close but NOT byte-identical (independently patched
  since forking — e.g. only `niaoren` had the §8.9 wrong-object food/
  water bug already fixed on `cctx`'s side by the time `niaoren` was
  tested, so the fix had to be reapplied there too). Previously
  `niaoren` was marked "unclassified... different `master.lpc`/daemon
  shapes" against the XKX family specifically (`xkx2001`/`xuanjianlu`)
  — that negative result still stands (confirmed via diff, ruled out,
  not just untested), it just wasn't compared against the right
  sibling.

14 archive files are byte-identical duplicates of another archive
(mostly browser "(1)" copies, plus a couple of differently-named same-
content repacks like `Naruto.rar`/`huoying`) — they share their
sibling's number in `lib_numbering.json` (`duplicate_of` field) and
were never processed separately.

**`jyqxc` (086, archive `金庸群侠传 (1).rar`) / `jyqxc2` (087, archive
`金庸群侠传.rar`) turned out to be a 15th instance of this same
"browser `(1)` duplicate download" shape that the original dedup pass
missed**, discovered only during `jyqxc2`'s own §10.7 deep-dive
(`diff -rq` on the two `work/` trees returned exactly 3 non-log
differences out of ~3,690 files: `jyqxc2`'s still-unfixed `logind.lpc`
vs `jyqxc`'s already-fixed one, plus each lib's own leftover single-
character test save). The raw archives themselves are equally
near-identical (`raw/jy` trees differ only by one extra `svr.exe`
binary in `jyqxc2`'s copy) — almost certainly why the dedup check
missed it, since it likely compared `.rar` container bytes rather than
extracted content, and the two `.rar`s are not byte-identical even
though everything they contain is. Both libs were already independently
converted, README'd, and (in `jyqxc`'s case) deep-tested before this
was noticed; not worth un-converging them retroactively, but any future
fix ported to one of this pair should be ported to the other in the
same pass — they are, for all practical purposes, the same codebase.

---

## 12. Driver reference — local patches and builds

One FluffOS checkout, three builds: `build/` (RelWithDebInfo),
`build-debug/` (use for all mudlib work — better diagnostics), and
`build-wasm/` (§1.1). Rebuild after `git pull`:
`cd ~/src/fluffos/build-debug && cmake --build . --target driver lpcc -- -j8`,
then boot-test one known-good lib before trusting the binary for a
sweep (a driver regression looks identical to a mudlib regression).

Local driver patches this project made/depends on — verify they are
present after any fresh checkout (`git log` in the fluffos repo):

1. **`mudlib_stats.cc` null `backbone_domain` guard** — old-MudOS
   bootstrap ordering (`author_file()`/`domain_file()` via call_other
   during master init) segfaulted `init_domain_for_ob()`; fixed with a
   null check. Without it, many libs crash at boot with a
   `f__call_other → ... → init_domain_for_ob` trace.
2. **`MAX_EXPANSION_NESTING` / `kMaxExpandStringDepth` raised to
   1024** — long macro-heavy expressions failed to compile at the old
   32/64 limits.
3. **`lpcc --batch` mode** (`src/main_lpcc.cc`) with per-file
   `set_eval()` re-arm (§10.4).
4. **MERGED**: the WASM **`query_ip_number()`/`resolve()` fixes**
   (§1.3a) — already landed; the "limited"-status IP-gated libs are a
   retest target, not a patch target, going forward.
5. **`MARCH_NATIVE:BOOL` in `build-debug`'s CMakeCache defaults to
   `ON`** (`-march=native`), which bakes in whatever instruction set
   the machine that ran `cmake`/`cmake --build` happened to have. If a
   session's underlying host later changes to older/different hardware
   (observed: an Intel Xeon L5520 — Nehalem, 2009, no AVX at all) the
   existing `build-debug/src/driver`/`build/src/driver` binaries SIGILL
   immediately on every invocation, with **zero output on stdout/stderr
   and no debug.log line at all** — `echo $?` shows 132
   (128+SIGILL), and `strace` is the fastest way to confirm
   (`--- SIGILL {si_signo=SIGILL, si_code=ILL_ILLOPN, ...} ---` right
   after the dynamic linker finishes and before any mudlib-visible
   output). This reproduces identically for EVERY lib, not just the one
   you're working on — confirm with a second, known-good lib before
   concluding it's a driver-vs-environment problem rather than a
   mudlib regression. Fix: `cmake -S ~/src/fluffos -B
   ~/src/fluffos/build-debug -DMARCH_NATIVE=OFF && cmake --build
   ~/src/fluffos/build-debug -- -j8` (full rebuild, ~5-10 minutes on 8
   cores; `build/` needs the same treatment if you use it too) — the
   resulting binary runs on any x86-64 host, at negligible runtime cost
   for this project's purposes. Since `build-debug/` is a shared
   checkout across sessions, this fix benefits every concurrent/future
   session once applied — but also means a DIFFERENT session could
   rebuild it back to `MARCH_NATIVE=ON` on a fast host and silently
   reintroduce the crash for anyone whose sandbox lands on older
   hardware later; if native driver boots start SIGILL-ing for no
   apparent reason, check this before assuming a deeper problem.
   (Found on `xajdxyj`'s §10.7 pass, mid-session, after an unrelated
   environment interruption — the driver had booted fine minutes
   earlier in the same session before the underlying host changed.)

The formatter (`tools/lpc-syntax/`) and all three of its bug fixes
(§9) also live in the fluffos repo, and are likewise MERGED upstream.

### 12.1 The WASM web terminal (`src/www/wasm/index.html`)

The actual browser page players use, also in the fluffos repo. As of
this writing it has multi-connection Game tabs + a separate Logs tab
(driver stdout/stderr routed away from the game terminal), and a
mobile-UX pass (branch `feat/wasm-mobile-ux`, PR pending) covering:

- **Keyboard-safe input bar**: iOS Safari and some Android browsers only
  shrink `window.visualViewport` when the on-screen keyboard opens, never
  the layout viewport — `body` is `position:fixed;inset:0` kept synced to
  the visual viewport's height/offset, so the input bar can't end up
  hidden behind the keyboard.
- **Boot loading progress bar**: a blank terminal during a large lib's
  download (tens of MB for the biggest libs) looked exactly like a hung
  page. `Module.setStatus`'s `"Downloading data... (loaded/total)"`
  string (from file_packager's `fetchRemotePackage()`) is the only real
  determinate signal in the whole boot — verify empirically what your
  build's generated glue actually calls before assuming a generic
  emscripten progress API exists; `fluffos.js`'s own `setStatus` never
  reports a percentage.
- **Compact chrome**: below ~620px of *visible* height (a landscape
  phone, or the keyboard eating a portrait screen — same underlying
  problem, hence one `visualViewport`-driven check rather than an
  `orientation` media query), the header merges into the tab row and
  padding tightens to the ~36px tap-target floor.
- **Fullscreen toggle**: the Fullscreen API, hidden entirely when
  unsupported (checked via feature detection, not user-agent sniffing),
  state driven by the `fullscreenchange` event rather than a toggle flag
  so it can't desync from an OS/browser-driven exit (Esc, back-swipe).

Mirrored byte-for-byte at `scripts/web_shell_override/index.html` in
this repo, which `pack_lib_for_web.sh` prefers over the release zip's
page — this is how the site gets a page improvement immediately without
waiting for a new fluffos release. **Keep both copies identical after
any change**; a manual sync race (the orchestrator copying an old
committed version over a subagent's in-progress edit, or vice versa)
has actually happened in this project — re-diff the two files
immediately before committing the mudlib-side copy, not just once.

Playwright + Chromium (`pip install --user playwright &&
python3 -m playwright install chromium`, no `--with-deps`/sudo needed
in this environment) is available for real visual verification against
a packed bundle — boot the actual driver, drive it as a touch user, and
screenshot; this caught real bugs (a touch-target CSS rule un-hiding a
button that should stay hidden, a fat-finger tap landing on the wrong
icon and dropping the connection) that reasoning from CSS alone missed
in an earlier pass. Headless Chromium here does support real
`requestFullscreen()`, so fullscreen behavior can be visually confirmed
too, not just structurally checked.
