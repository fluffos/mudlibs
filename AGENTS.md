# AGENTS.md — handbook for restoring and polishing these mudlibs

This is the accumulated knowledge base of a ~100-archive restoration
project, rewritten as a durable reference for whoever (human or agent)
continues the work. Read the section relevant to your task before touching
a lib; almost every problem you will hit has been hit before and is
cataloged here with its fix.

**Current state**: 98 Chinese LPC mudlibs converted and committed, 97 of
them fully WASM-playable end to end (plus `ds386`/Dead Souls, English,
deliberately left native-only/partial per §10.6) — every converted lib
has now also been through the long-sit boot-log sweep (§10.0), not just
a quick login check. The corpus keeps growing as new archives get
dropped in; `README.md`'s table and `lib_numbering.json` are the current
source of truth for the exact count, not the number above. Every lib has
a number: `NNN` per unique game, `NNN-M` for confirmed derivatives of the
same codebase, `9xx` for non-LPC archives (one, `033-3`, is a cataloged
binary-only release that was never convertible and has no `libs/` dir).
This file refers to libs by **slug** (`libs/<slug>/`) and number, never by
"archive #N" (a retired convention) or by any machine-local path.

**The mission now: every lib fully playable under WASM.** The browser
build is the primary distribution channel; native telnet is the
development/verification environment. §1 is the triage playbook.

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
   Check every `adm/etc/`-style data file for bare `/path.c` lines.
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

### 7.10 `log_error()` receives WARNINGS too — and must not touch the ACL

Two independent traps in the same apply:

- This driver funnels soft compile warnings (e.g. §4.3's nosave
  warning) through `APPLY_LOG_ERROR` alongside real errors; a mudlib
  that broadcasts them to players spams everyone with scary messages
  (98 in one session on `wuhanzhan`). Gate the broadcast on the message
  not containing `"warning:"` — LOWERCASE; the driver's diagnostic text
  is lowercase, and a `"Warning:"` check silently never fires
  (`shenzhou`, `bmxkx2001` shipped with the broken-case gate).
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
reach, not just runtime errors. Not worth a separate numbered class —
the uncatchable-crash-during-cold-first-compile shape is the same
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
`bixiecanyang`, `fy330`, `fy2mg`, and `wmkj` (each the SAME `printf("%O\n",
ob)` line duplicated across TWO parallel name-entry code paths —
accept a system-suggested random name vs type your own — both landing
right before the password prompt, both found and fixed together;
`fy330`'s own sibling `fy2` carries the byte-identical line but was
previously left unfixed as "harmless" — worth revisiting that call the
next time `fy2` is touched, now that this round treats the pattern as
a routine, safe-to-fix hit rather than a judgment call), `sanjieshenhua`, `ldtxii`,
`yszz`, `mohuanshiji`, `jyqxc`, and `syxjl` (each the same bare `printf("%O\n", ob)`
right before the Chinese-name is set — `ldtxii`'s sibling `ldtx` has
the byte-identical line, unfixed; port the same one-line deletion
there too when next touching that lib), and noted-but-left-alone on
`fy2` (a
similar stray `printf` in `logind.lpc`, existing precedent from `zzfy`
treats it as harmless). A leftover diagnostic write/printf with no
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

### 7.68 A multi-stage `call_out()` sequence gated on `present(ob)` silently and PERMANENTLY abandons its subject if something else moves it away mid-sequence — no error, no retry, no recovery

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
correctly post-fix (fresh 【平民】status, full stat bars, at the
expected revive room); a second death, disturbed by the same tour-guide
NPC mid-sequence exactly as before, this time still resulted in the
character ending up alive and freely mobile afterward (a ghost cannot
move on its own, so free movement is itself proof of resurrection).
General lesson: a `present()`/liveness guard inside a multi-stage
`call_out()` chain that's meant to protect against a subject going away
permanently should default to RETRY on ambiguous absence, not permanent
abandonment — reserve the hard stop for a genuinely-destructed/gone
object, since "briefly not here" and "gone forever" are different
failure modes.

**Second confirmed instance: `bixiecanyang`** (夕阳再现-derivative
lineage — unrelated to `bmxkx2001`'s branded content, but clearly
shares this same underlying death-system component somewhere upstream
in the broader ES2 mega-family, byte-for-byte the same `if (!ob ||
!present(ob)) return;` guard in both `d/death/npc/wgargoyle.lpc` and
`d/death/npc/bgargoyle.lpc`). Found via §10.7 deep functional test —
died fighting an NPC, landed at 鬼门关 with the same 白无常/黑无常
ghost-guard pair. Applied the identical fix to both files before the
soft-lock was ever actually triggered live here (the interaction that
exposed it in `bmxkx2001` — an unrelated forced-move NPC colliding
with an in-progress resurrection — wasn't reproduced in this session,
but the vulnerable code shape is identical, so the fix was applied
proactively rather than waiting for a live repro). Worth checking any
other ES2-family lib's `d/death/npc/*gargoyle*.lpc` (or equivalently
named ghost-guard files) for this same guard shape on sight, since it
appears to be shared infrastructure, not lib-specific code.

**Third confirmed instance: `fy330`** (风云Ⅲ, a different branch of the
same broad ES2/古龙-flavored mega-family, sharing the "朱笔判官"
ghost-judge naming and flavor text already seen in `mohuanshiji`/
`yszz`), found in `d/death/npc/panguan.lpc`'s `death_stage()`: `if (!ob
|| !present(ob) || (int)ob->query("combat_exp") > MAX_EXP) return;` —
same bug, with an extra legitimate content-gate (`combat_exp >
MAX_EXP`, a real design choice to route over-leveled characters to a
different judge) bundled into the same condition. Fixed by splitting
`!present(ob)` out into its own reschedule branch while leaving the
`!ob`/`combat_exp` checks as permanent aborts (both are genuine
disqualifications, not transient absence). Found via §10.7 deep
functional test via code reading, not a live repro — the test
character's auto-flee-from-combat safety mechanic reliably rescued it
from actual death against every NPC tried this session, so the
resurrection sequence itself was never driven live end-to-end here;
documented honestly as an unverified-live fix in `fy330`'s own
NOTES.md. **Also checked and deliberately left alone**: the same
directory's `d/death/npc/panguan2.lpc` has the identical-looking `if
(!ob || !present(ob)) return;` line, but it's a single-shot "attack a
living trespasser in the underworld" check with no multi-stage
`call_out` chain and nothing to abandon — absence there just means
"nothing to punish," which is correct as-is, not an instance of this
bug class. Don't pattern-match on the guard text alone; confirm the
function actually drives a multi-stage resurrection sequence before
treating a `!present(ob)` bare-return as this bug.

**Fourth confirmed instance: `fy2mg`** (风云Ⅱ美国版本, `fy330`'s own
XKX-framework sibling — same `adm/obj/master.lpc` euid/check_legal_name
bug pair as `fy330`, and it turns out the same death system too):
`d/death/npc/{wgargoyle,bgargoyle}.lpc` (白无常/黑无常), byte-identical
`revive_loc`/`death_msg` text to `bixiecanyang`'s pair of the same
filenames — this shared "白无常/黑无常 gargoyle" death subsystem spans
at least two otherwise-unrelated top-level lineages now (夕阳再现-family
`bixiecanyang` and XKX-family `fy2mg`), not just one. Both files had the
same `if (!ob || !present(ob)) return;`; `bgargoyle.lpc` additionally
has a "not yet a ghost → attack the trespasser" branch BEFORE the
revival-stage loop (same shape as `fy330`'s `panguan2.lpc`), but unlike
`panguan2.lpc` it falls through into the same multi-stage
`death_stage()` as `wgargoyle.lpc` rather than being a separate
single-shot function — so both files here needed the fix, unlike
`fy330` where only one of the two death-NPC files did. Fixed with the
same split-guard pattern. Also not verified with a live disturbed-
sequence repro: three separate combat engagements against
progressively stronger NPCs (including one that actively pursued the
player between rooms, unlike every other instance's engagements) all
ended in the character's own auto-flee-at-critical-hp safety mechanic
saving it, down to as low as 11% of a combat-shrunken max-HP pool,
never actual death — worth noting as a recurring property of this
whole mega-family's core combat loop, not just bad luck: the auto-flee
safety net has now reliably prevented a live repro of this bug class
across `fy330` and `fy2mg` both.

**Fifth confirmed instance: `jyqxc`** (金庸群侠传, another XKX-framework
sibling of `fy330`/`fy2mg`, sharing the same `adm/obj/master.lpc`) —
THREE death-NPC files this time: `d/death/npc/{newgargoyle,bgargoyle,
wgargoyle}.lpc` (实习无常/黑无常/白无常 — a third "trainee gargoyle"
ghost-guard role alongside the usual white/black pair). All three had
the same `if (!ob || !present(ob)) return;`; `bgargoyle.lpc` again has
the pre-revival "attack the live trespasser" branch that falls through
into the same multi-stage loop (same shape as `fy2mg`'s `bgargoyle.lpc`,
not `fy330`'s separate-file `panguan2.lpc`), so all three files needed
the fix. **Unlike `fy330`/`fy2mg`, this one WAS verified with an actual
live death**: the newbie-guide-recommended "safe" `fight` command
(auto-halts at 50% HP) still didn't save the test character against an
overwhelming named NPC (欧阳克, a Jin Yong villain standing on an
ordinary street) — a single blow went from full health to dead, too
fast for the 50%-threshold check to ever fire — landing the character
at 鬼门关 with the just-fixed `newgargoyle.lpc`'s "实习无常" and
`wgargoyle.lpc`'s "白无常" both present. Left the sequence fully
undisturbed (no forced mid-sequence move this time) and confirmed via
reconnect that the character resurrected correctly at the revive room,
alive, mobile, with the expected 40%-精气 death penalty and full food/
water — the first live, end-to-end confirmation of this fix's
undisturbed path in this bug class's whole history in this project
(every prior instance either code-reviewed the fix or got saved by
auto-flee before death). Still didn't reproduce the ORIGINAL
disturbed-mid-sequence trigger (an unrelated NPC forcibly moving the
ghost away mid-revival) — that remains verified only on `bmxkx2001`.

**A genuinely novel variant of this same bug class, unrelated to
death/resurrection**: `d/shaolin/npc/yu-zu2.lpc` ("狱卒", a Shaolin
prison guard) uses the identical `if (!ob || !present(ob)) return;`
inside its own multi-stage `call_out()` chain — but this one drives a
"jail" punishment mechanic (60-second ticks advancing the jailer's
dialogue, eventually releasing the prisoner via `move()`), not the
underworld revival system at all. Confirms this bug class isn't tied
to any one narrative wrapper: ANY multi-stage `call_out()` sequence
that's supposed to eventually release/resolve its subject, gated on a
combined `!ob || !present(ob)` bare-return, is vulnerable — a jailed
player who happens to be absent for one tick would be stuck in jail
forever, exactly like a ghost stuck unable to reincarnate. Fixed with
the same split-guard pattern. When scanning a new lib for this bug
class, grep for the guard SHAPE (`!ob || !present(ob)) return`) across
the whole tree, not just `d/death/`.

**Sixth confirmed instance: `yhyxs`** (yh2003/炎黄英雄史 lineage, sibling
of `yanhuangwuhun` — an unrelated top-level lineage from every prior
instance) — `d/death/npc/{hei,bai}.lpc` (黑无常/白无常), the same
`if (!ob || !present(ob)) return;` inside a five-stage `death_stage()`
revival loop. Fixed with the same split-guard pattern. **Verified with
a second genuine live undisturbed death-and-resurrection repro** (the
first being `jyqxc`'s): fought and lost to an overwhelming named NPC
(欧阳克, the same Jin Yong villain encountered independently on
`jyqxc`'s own street — apparently recurring set-dressing across
multiple unrelated lineages) — combat damage combined with an active
winter-weather frostbite effect for a flavorful "被活活冻死了" (froze
to death) kill message — landed at 鬼门关 with the just-fixed
`bai.lpc`'s 白无常 present, left the sequence fully undisturbed, and
confirmed via reconnect the character resurrected correctly at 武庙
(扬州), alive, mobile, full 精气/气血, 潜能 halved as the expected
death penalty.

**Seventh confirmed instance: `yanhuangwuhun`** (yh2003 lineage,
`yhyxs`'s own sibling) — this archive ships TWO complete death
systems: `d/death/` (the one `DEATH_ROOM` in `include/login.h`
actually points at — live) and `d/death22/` (never referenced by any
room, code path, or macro anywhere in the tree — dead content,
paired with an equally-unreferenced `adm/daemons/logind2.lpc`,
apparently a whole bundled-but-never-wired-up alternate version).
`d/death/npc/{hei,bai}.lpc` (live) and `d/death22/npc/{hei,bai}.lpc`
(dead) all four have the identical `if (!ob || !present(ob)) return;`
guard; fixed all four with the same split-guard pattern — the two
dead-code ones cost nothing to fix now and are ready if that content
is ever wired up later. **Verified with a third genuine live
undisturbed death-and-resurrection repro**, once again via 欧阳克 (now
confirmed recurring across three unrelated lineages —
`jyqxc`/`yhyxs`/`yanhuangwuhun` — as shared ES2-family set-dressing,
not a coincidence): this time the character's own `wimpy` auto-flee
attempt was actively blocked by the opponent ("欧阳克飞身一闪，已将
你的退路封死" — a first: every prior instance's auto-flee always
succeeded), then two more hits plus the same active winter-frostbite
stacking killed the character. Resurrection at 武庙 confirmed via
reconnect exactly as the prior two instances.

**An interesting NEAR-miss found only in the dead `d/death` code**:
`d/death/npc/{wgargoyle,bgargoyle}.lpc` — an older "gargoyle"-named
implementation of the same 黑无常/白无常 pair, superseded by
`hei.lpc`/`bai.lpc` in the same directory and, like `d/death22`,
referenced by no room at all. Both carry the same §7.68 guard, but
`bgargoyle.lpc`'s `init()` ALSO has its `wizardp()` check inverted:
`!wizardp(previous_object())` where every sibling (including its own
neighbor `hei.lpc`) correctly has bare `wizardp(previous_object())`
(the intent: skip scheduling revival for wizard ghosts, who get
handled elsewhere). Inverted, this reads "skip scheduling revival for
NON-wizard ghosts" — meaning if this file were ever live, ordinary
players would NEVER get their `death_stage()` call_out scheduled at
all and would be permanently stuck as ghosts, while wizards (who
don't need this path) would be the only ones it worked for. **Left
unfixed**, per the project's confirmed-unreachable-content convention
(§13) — this file is provably dead code (no references found anywhere
in the tree), so the inverted condition can never actually fire.
Recorded here as a real bug that happens to be inert, likely
introduced during this lineage's own rename from "gargoyle.c" to
"hei.c"/"bai.c" at some point in its history, with the newer files
getting the condition right and the superseded ones keeping the typo.
Worth grep'ing for `!wizardp(previous_object())` (the inverted shape,
not just the §7.68 guard shape) on sight in any lib with multiple
death-NPC implementations, in case a future archive has this same
typo in a file that turns out to actually be live.

**Eighth confirmed instance: `syxjl`** (随缘洗剑录, ES2-family but a
distinct branch from every prior instance's lineage — shares code with
神州/火影/武汉站, not the XKX or yh2003 families) —
`d/death/npc/wgargoyle.lpc` (白无常, the one `DEATH_ROOM` actually
points at). Fixed with the standard split-guard pattern. **Verified
with a fourth genuine live undisturbed death-and-resurrection repro**
(after `jyqxc`/`yhyxs`/`yanhuangwuhun`) — killed by 欧阳克 again (now
confirmed recurring across FOUR unrelated lineages as shared ES2-family
set-dressing), landed at 鬼门关, left undisturbed, confirmed via
reconnect the character resurrected at 武庙 with the expected
half-精气/full-food-water state. Also confirmed live that a fresh
ghost cannot move at all ("你已经没有力气再走路了，休息一下吧。") —
worth remembering when judging whether an adjacent room's death-NPC
variant is practically reachable, not just technically referenced by
an exit (see §7.71's `bgargoyle.lpc`/`gateway.lpc` case on this same
lib, which turned out to be exactly this kind of technically-linked-
but-practically-unreachable room). Also fixed the same jail-mechanic
variant already cataloged from `jyqxc` (`d/shaolin/npc/yu-zu2.lpc`,
confirmed dead — superseded by a `yu-zu.lpc` with no jail mechanic at
all) for consistency at negligible cost.

**Ninth confirmed instance: `wmkj`** (夕阳再现/`bixiecanyang` lineage —
sibling to `bixiecanyang`, sharing the same `chinese.lpc`/`securityd.lpc`
tooling files) — `d/death/npc/wgargoyle.lpc` (live, `DEATH_ROOM` points
at its room) plus the same two already-cataloged dead-code variants
(`bgargoyle.lpc`, confirmed unreferenced by any room; `d/shaolin/npc/
yu-zu2.lpc`, superseded by a jail-mechanic-free `yu-zu.lpc`), all fixed
with the standard split-guard pattern. Verified via debug instrumentation
(not just a clean reconnect) that the fix itself works exactly as
intended: all five `death_msg` stages play in full and `reincarnate()`
completes successfully. See §7.74 for a DIFFERENT, deeper, and
UNRESOLVED anomaly found immediately downstream of this fix on the same
lib — the character never actually arrives at `REVIVE_ROOM` despite the
dialogue and `reincarnate()` both completing correctly, which is NOT
this bug class and was not introduced by this fix (confirmed: without
this fix, the sequence would abort even earlier, at the missing-present
check, never even reaching the point where the new anomaly occurs).

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
Discworld bundles untouched). Revisit only on request.

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
7. **Fix what you find, in-place, and write it up immediately**: the
   bug, the file:line, the fix pattern, and the test character/state
   left as evidence — in the lib's own NOTES.md — plus a new AGENTS.md
   bug-class entry (like §7.16) if the underlying pattern is likely to
   recur in sibling or unrelated libs. Check documented siblings
   (§11) for the same pattern before moving on — a bug found this way
   in one lib has repeatedly turned out to be copy-pasted into others.

### 10.8 Long-sit soak testing can surface driver-fatal crashes invisible to `debug.log` entirely

Found on `xjcq2000`'s deep functional test (§10.7): roughly 25
minutes into an otherwise-ordinary session, the whole driver process
died outright — `FATAL ERROR: FATAL: Object .../d/xingxiu/silk6 ref
count 0, but not destructed (from free_svalue).`, a driver-level
internal consistency check, not a catchable LPC error. **`debug.log`
showed nothing whatsoever** — it stayed at its exact pre-crash line
count through the crash. The only reason this was caught at all was
that the agent happened to have the driver's own stdout redirected to a
file; without that, this class of failure leaves **zero evidence** and
would simply look like "the connection dropped" to anyone testing live.

Established mechanism (not a fix — this is a testing-methodology
lesson, not a resolved bug): this lib's ambient world simulation is not
idle even with no player commands — roaming NPCs' `heart_beat()` →
`random_move()` chains walk them through real exits continuously, and
given enough real wall-clock time this forces lazy compilation of
essentially the entire map, including zones no test character ever
visited. Sustained compiling/cloning/destructing across that much of
the lib eventually corrupted some object's reference count to 0 without
it actually being destructed — silent until the next unrelated
`free_svalue()` call touches it, which is what aborted the whole
process. The exact LPC-level trigger of the corruption was **not**
pinned to a specific file:line — flagged honestly as unresolved, not
silently presented as fixed. Several genuinely broken pre-existing
files surfaced by the same mass-compile (an inherit pointing at a
nonexistent sibling file, illegal-format board-post save data) are
plausible contributing factors but not proven causes.

**Actionable takeaway for any future long-sit / soak-testing pass**:
capture the driver's own stdout to a file (not just `debug.log`) for
the full duration of any extended idle-connected session — this class
of crash is otherwise completely invisible. If reproduced with a
pinned root cause on any lib, promote this into a proper numbered §7.x
bug-class entry with an actual fix; until then, treat "the process was
still alive at the end of a long session" as itself a thing worth
explicitly checking, not assuming.

**Second independent occurrence — corroborating, still unpinned**:
`shiji`'s deep functional test hit the SAME class of failure
(`FATAL: Object .../cmds/skill/recruit ref count 0, but not destructed
(from free_svalue)`) roughly 20 minutes into an unrelated session, this
time during an admin reconnect rather than ambient NPC wandering, and
on a completely different lib/lineage from `xjcq2000`. Two
follow-up attempts to reproduce the exact triggering sequence on a
fresh character immediately after restart did not reproduce it, nor did
another ~15 minutes of further play.

**Third and fourth independent occurrences**: `shenzhou`'s deep
functional test hit the same class (`debugmalloc: attempted to free
non-malloc'd pointer` → `abort()`) at ~10-11 minutes into a session,
this time triggered by the driver's own ordinary periodic 5-minute
`remove_destructed_objects()` GC sweep — unrelated to that player's own
net-dead timer (hadn't fired yet) and unrelated to §7.12's `tell_room()`
bug (already fixed on that lib, confirmed). A full C++ backtrace was
captured for the first time for this class (described in prose in
`shenzhou`'s NOTES.md, not committed as a file, per `dtsl`'s
established precedent). Separately and independently, `xlqy_new2007`'s
deep functional test also hit the same class
(`FATAL: Object .../std/skill ref count 0, but not destructed`) during
naturally-occurring idle time between test steps (not a deliberate
wait), moments after triggering that lib's own §7.12 `tell_room()` bug
— plausibly the same mechanism §7.12's escalation note already
predicts, though not proven as the sole cause.

**Fifth independent occurrence**: `nitan170911`'s deep functional test
hit a related-but-distinct signature (`stralloc.c: free_string called on
non-shared string`) mid a net-dead soak — the corrupted structure this
time was a STRING, not an object, the first occurrence not matching the
`ref count 0, but not destructed` wording exactly, but the same
underlying shape (a driver-internal consistency check aborting the whole
process during ordinary extended play, no mudlib-catchable error, no
`debug.log` trace). Triggered by the player's own net-dead body, not
ambient activity.

**Sixth independent occurrence**: `yhyxs`'s deep functional test — a
genuine outright `Segmentation fault` this time (not a caught
`FATAL ERROR`/`abort()`), roughly 16 minutes into an ordinary session,
between two otherwise-unremarkable client reconnects (the previous
command was a plain `hp`; the next connection attempt got
`CONNECT_FAILED: Connection refused`). `debug.log` again showed
nothing — its last lines were ordinary `Unknown #pragma` compile
warnings. The driver's own captured stdout (`boot.log`) had the full
C++ crash backtrace: the fault was inside the driver's OWN periodic
game-tick reset sweep (`backend_run_one_gametick` →
`look_for_objects_to_swap` → `reset_object` → `object_visible`,
crashing on the write to `ob->next_reset`), not inside any callable
LPC function or player command at all — the closest thing to a
"trigger" in the log is a long run of lazy first-time compiles of
zones the test character never visited (青城/洛阳/泉州/开封 and others),
matching `xjcq2000`'s original "ambient world simulation forces mass
lazy compilation, eventually corrupts something" mechanism almost
exactly, just caught one step further downstream (a bad object
pointer during reset, rather than a bad refcount during
`free_svalue`). No LPC-level fix applied or attempted — this is
driver-internal memory corruption, not a mudlib bug, consistent with
every prior occurrence.

Six independent occurrences now, across six unrelated libs/lineages,
different corrupted structures (objects, a string, and now a
segfault with no caught error at all), different immediate trigger
paths (ambient NPC wandering, admin reconnect, periodic GC sweep,
natural idle time, a player's own net-dead body, the driver's own
periodic reset sweep), same underlying shape (silent memory
corruption during ordinary extended play that eventually kills the
whole process, invisible to `debug.log`). This is corroborating
evidence the underlying driver-level memory-corruption class is real
and not a one-off, but it remains genuinely low-reproducibility and
root-caused to the driver level (not mudlib-fixable), not any
specific mudlib source pattern — no single occurrence has yet pinned
down a REPRODUCIBLE trigger (one that fires reliably on demand, not
just "eventually during a long-enough session"). Given the occurrence
count, this is worth flagging to the human maintainer for a possible
dedicated driver-level investigation (ASan/valgrind against a
long-sit soak) in the `~/src/fluffos` checkout itself, rather than
continuing to treat each new occurrence as a per-lib mudlib finding.

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
  `kxkj`/`kxkj1` (036),
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
  `moniHuafu` (039, own game). **风云Ⅳ**: `fengyun434`/`fy2005` (009).
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
