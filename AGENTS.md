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
  fix (with code) → how to detect → which lineages it affects.

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
  prompt chain before the id prompt (e.g. `menghuanxiyou2002`/`mhxy`'s
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
  gate". (Seen: `shiji`, `fluffos_xiyou2000`, `xiyouji450`,
  `suiyuanxijianlu` — note the check can hide inside the *absent* branch
  of an earlier `find_object()` test, as on `fluffos_xiyou2000`.)
- **`VERSION_D->is_version_ok()`-style gates** (the 中华英雄/终极地狱
  lineage idiom) — same fix: `find_object()` guard, absent ⇒ allow.
  (Seen: `zhonghua2`, `zhongjidiyu`, `zhongjidiyu_zhijian`,
  `yanhuangwuhun`, `yanhuangyingxiongshi`.)
- **`resolve()` called in a security daemon's `create()`** before it
  initializes its own state — under WASM the throw aborts `create()`
  mid-way, leaving globals (e.g. `wiz_status`) uninitialized, and the
  *first ACL lookup* crashes later with no obvious link to the cause.
  Fix: reorder state init before the `resolve()` call AND wrap it in
  `catch()`. (Seen: `fengyun3dianzang`, `moniHuafu`, `fengyun434`/
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

`chongshengdeshijie` (055) is the one known no-boot: its
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
  `unknownlib20150716`, `xiaoyuxiyou`, `bixiecanyang`,
  `xiyangzaixian_fengyun2`, `fy2005` (5 min), `nitan_ceshi`,
  `nitan_san`, `xiaoaojianghu_client` (uptime()<10), `tianxia`.
- **Per-IP anti-flood / registration throttles** — "one new registration
  per N minutes per IP" mappings (`xo_final`'s `BAN_D` 3-minute
  throttle, `xiaoaojianghu2`'s per-IP throttle) whose rejection path is
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
points before quit saves", `xiaoaojianghu2`), skill/combat cooldowns —
those are game design, not hosting protection. Record every bypassed
gate in the lib's NOTES.md.

### 1.4 WASM triage playbook (per lib)

Status lives in `scripts/wasm_status.json` (generated), the README table,
and each lib's NOTES.md. For every lib not yet `playable`:

1. Reproduce: `wasm_client.js` with the lib's documented login sequence
   (read its README/NOTES for the flow — id, hidden prompts, Chinese
   name). Read the FULL transcript plus captured driver output.
2. Classify against §1.3: IP-parse rejection/crash (a) → wait for the
   driver fix, or apply the loopback patch (b); sockets-absent daemon
   crash (c) → guard; pcre (d) → rewrite; instant silent disconnect at
   connect-time (e) → uptime gate; `log/`-path ENOENT → harness dir shape
   (§1.2); anything else → treat as a real mudlib bug, native rules apply
   (§6–§8) — first check whether it reproduces natively, since a
   WASM-only genuine mudlib bug is rare.
3. Fix, re-run the FULL flow (registration with a real Chinese name →
   `look` → `score` → `quit`, same standard as native, §10.1).
4. Update `wasm_status.json`'s source (the status is generated — fix the
   underlying record, currently the per-lib notes it is generated from),
   the lib's NOTES.md, and README table status.
5. Known one-off oddities to not rediscover: `xo` reaches the gender
   prompt then hangs at world-entry under WASM only (not IP-related, not
   reproducible on sibling `xo_final` — unexplained, flagged);
   `xiaoaojianghu_xo`'s character-creation finalization is flaky under
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
`nitan170911`, `shujiantianxia` from `shujian2008`,
`menghuanxiyou2002` from `mhxy`, the whole `jinyongqunxiazhuan2008`
group, `fengyun2qinghua` from `fy2`). §11 maps the known families.

Two hard-won caveats:
- **Similar Chinese titles are NOT a lineage signal, in either
  direction.** Same-titled libs proved unrelated (`shujianpiaoling2` vs
  `shujian2008`; `zhongjidiyu` vs the other two 终极地狱;
  `kuangxiangkongjian` vs `xinkuangxiangkongjian2` are same game but
  different snapshots; `xianlvqiyuan` vs `xlqy_new2007` different
  codebases) and different-titled libs proved identical
  (`xiakexing3` = `jinyongqunxiazhuan2008`; `jinyongwenzi` = `bxsj`).
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
  (`fluffos_xiyou2000`: mudlib in `world.tar.gz` inside the tarball).
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
  back to `-f BIG5` when GB18030 errors (`chongshengdeshijie` is fully
  BIG5/CP950). Some files are already UTF-8 (mixed-era edits) — detect
  with a UTF-8 round-trip before converting.
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
  because their extension was uppercase `.C`).
- **`iconv -c` can eat an adjacent REAL byte** along with an invalid one
  — most damagingly a newline or closing quote, producing "End of file
  in text block" / missing-quote errors at compile time (a heredoc's
  closing `LONG` tag merged onto the previous line). Any compile error
  of that shape in a file flagged "LOSSY conversion" in the conversion
  log ⇒ diff against the raw bytes and re-insert the exact dropped
  character. Seen on `tianxia`, `xo_final`, `shujian2008`,
  `xianlvqiyuan`, `yanlongfengyin_xiaoao3` (where it silently deleted
  NPC `set_name()` lines).
- **Mixed encodings within ONE file**: BIG5 lines inside an otherwise-GBK
  file decode via GB18030 *without error* into valid-but-wrong mojibake —
  undetectable by the lossy-conversion log. Only a human skim of
  user-facing strings catches it (`huoying`'s `config.cfg`; also found
  live during a §10.7 deep functional test on `shanhaizhanshen` — 9
  `指令格式：` command-help headers mixing this lib's BIG5-heritage ES2
  base text with GBK text a later Chinese-reskin author appended without
  re-encoding; a broader automated scan of the same lib found the
  corruption is likely more widespread than any single pass caught,
  since the scanner has a real false-negative gap when BIG5-as-GBK lands
  on other valid-looking CJK — flag for a dedicated cleanup pass rather
  than assuming one spot-check found everything). Re-decode just the
  affected lines with BIG5.
- **Whole help/motd/broadcast files skipped entirely by an earlier
  conversion pass**: `shanhaizhanshen`'s `doc/help/{topics,cmds,story}`,
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
  `yuxuechongsheng`, `yanlongfengyin_xiaoao3`, `zitengzhan`,
  `xiaoaojianghu_client`.

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
field (stale copy-paste from other muds is common — `datangshuanglong`
ships a 碧血残阳 name field and even a `config.bxcy` filename;
`tiexuejianghu` ships 风云三; `xiakexinzhuan2` ships 海洋II).

### 5.2 `log directory` resolves against the driver's CWD

Unlike nearly every other path (mudlib-relative), `log directory` is
relative to the launch CWD. Convention: `libs/<slug>/log/` and ALWAYS
launch via `cd libs/<slug> && .../driver config.fluffos` — otherwise you
silently get no `debug.log` at all.

### 5.3 Ports hardcoded in mudlib source

A `MUD_PORT`/`PORTNO` constant in `globals.h` used by `master.lpc`'s
`connect(port)` dispatch silently rejects EVERY connection when it
doesn't match the assigned port — clean boot log, dead server
(`huoying`, hardcoded 8000). Grep for hardcoded port constants during
the standard pass. Related but distinct: a hardcoded `TOMUD_PORT`-style
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
  family everywhere; first found on `unknownlib20150716`.)
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
  quoted form. (359 files on `xinkuangxiangkongjian2`, 172 on
  `kuangxiangkongjian`, recurs across ES II. Also found live on
  `wuhanzhan` via its §10.7 deep functional test — a single surviving
  instance that an earlier grep-based sweep missed because the grep
  pattern was case-sensitive and only matched uppercase absolute paths
  (`<ABS/...>`); this one was lowercase (`<d/qujing/...>`). When
  re-sweeping for this class, grep case-insensitively.)
  **Alternative fix when quoting individual `#include` lines is
  impractical (many scattered occurrences, or the exact same shape
  keeps recurring across new content)**: found on `unknownlib20150716`'s
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
  without touching individual files.
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
  `shanhaizhanshen` benign.)
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
  Grep `ed_start\|ed_cmd\|query_ed_mode` early. (`xiaoaojianghu2`.)
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
  470 occurrences on `chongshengdeshijie` where bulk-fix WAS warranted.)
- **`TYPE * a, b;`** — the `*` binds to the first declarator only
  (C-style); old code intends both as arrays. Symptom: `Bad assignment
  ( TYPE vs TYPE * )` in scattered files. Script-fix the narrow
  declaration-line shape. (`ds386`, 33 files; an English-lib habit.)
- **`switch` with only `default:`** — hard parse error ("need case
  statements"), fatal when it's `master.lpc`'s `connect()`. Rewrite as a
  plain block. Grep `switch\s*([^)]*)\s*{\s*default:`.
  (`xixingzhanji`, `suiyuanxijianlu`.)
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
absent from `globals.h`) fixed 81 (`xiyangzaixian3`); missing
`GROUP_TASK`/`EXERT_DIR`/armor macros fixed cascades on
`xiaoaojianghu_xo`/`tiexuejianghu`. Extract the exact underlying error
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
on `shanhaizhanshen`.)

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
to lpcc, only crashes a real boot. (`dongfanggushi2`.)

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
  `suiyuanxijianlu`, `longyunmeng`.) Same idiom family as the WASM
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
`xiakexing100`, `xiyouji2006`, `zitengzhan`, `zzfy`, `yueyingqiyuan`;
also the `uptime.lpc` `write(read_file(LASTCRASH))` variant
(`xianjianchuanqi`, `moniHuafu`, `suiyuanxijianlu` — see also §7.11 for
the receiving side). Grep:
`grep -rn "sscanf(read_file\|write(read_file" work/`.

### 7.10 `log_error()` receives WARNINGS too — and must not touch the ACL

Two independent traps in the same apply:

- This driver funnels soft compile warnings (e.g. §4.3's nosave
  warning) through `APPLY_LOG_ERROR` alongside real errors; a mudlib
  that broadcasts them to players spams everyone with scary messages
  (98 in one session on `wuhanzhan`). Gate the broadcast on the message
  not containing `"warning:"` — LOWERCASE; the driver's diagnostic text
  is lowercase, and a `"Warning:"` check silently never fires
  (`shenzhou`, `beimeixiakexing2001` shipped with the broken-case gate).
- `log_error()` calling `wizardp(this_player(1))` (or anything that
  lazily loads the security daemon) can fire from the FIRST preload
  compile, before securityd exists — crashing every boot at the
  earliest possible point (`shenzhou`), or generating dozens of caught
  error-traces per boot (`beimeixiakexing2001`). Guard with
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
  `xiaoaojianghu2` it appeared only in the lib's own custom
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
sometimes dormant, sometimes genuinely reachable (`fengyun3dianzang`
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
  (`zhongjidiyu_zhijian`; fixed with an explicit string salt `"zj"`).
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
  `fengyun2qinghua`, `fengyun434`, `fengyun3xiuding`,
  `fengyun3dianzang`, `fluffos_xiyou2000`, `esI`) — when fixing it in
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
  (`yanhuangyingxiongshi`.)

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
already present), `rzrmud`/`suiyuanxijianlu`/`xiaoaojianghu2`/
`yuxuechongsheng` have real per-object storage. Check whether the
simul_efun actually defines global set/query before assuming.

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

Found on `shanhaizhanshen`'s deep functional test (§10.7). **Zero signal
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
`beimeixiakexing2001` (documented sibling of `xkx2001`) carries a
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

Lineages likely affected: `menghuanxiyou2002`, `fluffos_xiyou2000`,
`xiyouji2003`, `xiyouji2006` (confirmed via grep to carry identical
code, not yet fixed there — out of scope for the pass that found this).

### 7.27 (RETRACTED — false positive, see §10.7's scope note) A time-gated transit room deleting its exit on window-close

Originally found on `unknownlib20150716`'s deep functional test (§10.7)
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
prompts. And a prompt's TEXT can lie: `xiyangzaixian3`'s "请输入您的英文
名字:" is actually a hardcoded client-version gate expecting the literal
`"2060"` (and failed retries loop back to the gate, not the id prompt);
`xiaoaojianghu_client` has the same `get_version` gate live. **Always
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

Affected so far: `xuanjianlu`, `beimeixiakexing2001`, `bxsj`, `bxsj1`,
`jinyongwenzi`, `xiakexing3`, the `jinyongqunxiazhuan2008` group,
`zhongjidiyu` (twice — main hook plus an 18-handler NPC file),
`zhongjidiyu_airuoyoulan`, `tiexuejianghu`, `xingzhanyingxiong` and
`shiji` (both found via a deep functional test, §10.7 — reached only
through an NPC's own `command()` call, not by any player-typed command,
since ordinary typed commands arrive via `ORIGIN_DRIVER` and bypass the
privacy check that only bites `ORIGIN_EFUN` calls; every earlier smoke
test on both libs only ever typed commands directly, so movement's
auto-look and every sect-join system silently never worked until these
passes — `shiji` is the SAME underlying game as `xingzhanyingxiong`,
same bug, same lineage, independently discovered). **Empirical caveat,
now narrowed**: `private` command_hook does NOT always break
*player-typed* dispatch on current drivers — `shiji` itself, `tianxia`,
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
`grep -rn 'sscanf.*\.c[$"]' adm/ secure/`.

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
(query_shadowed), `yanhuangyingxiongshi`, `shenzhou`,
`zhongjidiyu_airuoyoulan`/`_zhijian`, the 金庸群侠传 group,
`kuangxiangkongjian`. Grep `is_killing(` for object-passing call sites
during the standard pass.

### 8.6 Anti-flood registration throttles (now bypassed)

Per-IP "one new registration per N minutes" throttles made repeat tests
look like silent crashes (the rejection path's write() is often
commented out — connection just drops). These are now bypassed for
loopback per §1.3e; the diagnostic lesson stands for any remaining
non-loopback shape: a `new → id` sequence that worked minutes ago and
now produces nothing ⇒ check for `IsTimeAllowed`/`NewIps`-shaped
mappings before debugging the flow; restarting the driver clears
in-memory throttles instantly. Run full registration in ONE continuous
client session, not several reconnects.

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
second family (`fluffos_xiyou2000`, `menghuanxiyou2002`, `mhxy`,
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
fixing anything: `datangshuanglong`'s menu is unreachable behind an
`#ifdef GB_AND_BIG5x` typo (trailing "x" never matches the real
`#define`) that always hardcodes the safe branch — a real but harmless
bug, out of scope, don't "fix" the typo as part of this pass unless
asked.

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
   (`chongshengdeshijie`'s gender-selection crash). No clean grep;
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

Found on `xianjianchuanqi`'s deep functional test (§10.7): roughly 25
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
on a completely different lib/lineage from `xianjianchuanqi`. Two
follow-up attempts to reproduce the exact triggering sequence on a
fresh character immediately after restart did not reproduce it, nor did
another ~15 minutes of further play. This is now corroborating evidence
that the underlying driver-level refcount-corruption class is real and
not a one-off — two independent libs, two different objects, two
different immediate trigger paths, same fatal signature — but it
remains genuinely low-reproducibility and root-caused to the driver
level (not mudlib-fixable), not any specific mudlib source pattern. If
a third occurrence pins down a reproducible trigger, this is worth
escalating as a driver-level investigation in the `~/src/fluffos`
checkout itself rather than continuing to treat it as a per-lib mudlib
finding.

---

## 11. Lineage map — who shares code with whom

Porting proven fixes across siblings is the single biggest
time-multiplier in this project (§2.1). Families established by actual
core-file diffs (numbering from `lib_numbering.json`; members listed
base-first):

- **ES II / 东方故事 mega-family** (the region's common ancestor
  mudlib; expect §6.1 include fixes, §8.1, §7.12 message wrappers,
  §4.3 collisions): `es1_win`/`esI` (008); and ES II-derived but
  distinct games: `xkx2001`/`beimeixiakexing2001` (017), `xuanjianlu`
  (046), `rzrmud` (016), `wuhanzhan` (040), `haiyang2` (043),
  `huoying` (044, Neolith), `shenzhou` (048), `shenmo` (049, Neolith),
  `zitengzhan` (051), `zhongjidiyu` (052), `xixingzhanji` (054),
  `tiexuejianghu` (056), `suiyuanxijianlu` (057), `mohuanshiji` (058),
  `yueyingqiyuan` (037), `xinkuangxiangkongjian2`/`kuangxiangkongjian`
  (036), `yuxuechongsheng` (042, hybrid ES/nitan),
  `xiakexinzhuan2` (028), `dongfanggushi2` (022).
- **西游记 / xiyouji.org branch of ES II** (§6.6's convertd Greek table,
  §7.6 mirror-site gates): `xiyouji` (010, the ancestor snapshot) with
  `fluffos_xiyou2000`, `xiyouji2003`, `xiyouji450`, `xiyouji2006`;
  `mhxy`/`menghuanxiyou2002` (012, 梦幻西游 branding);
  `shenmo` (049) is a far-evolved fork; `wuhanzhan` (040) a 大话西游
  sibling.
- **yh2003**: `yanhuangwuhun`/`yanhuangyingxiongshi` (045).
- **金庸群侠传 engine**: `jinyongqunxiazhuan2008` + `_std` + `_deluxe`
  + `2015` + `xiakexing3` (031) — engine layer frozen across 7 years,
  fixes port 1:1.
- **书剑 (ShuJian)**: `bxsj`/`bxsj1`/`jinyongwenzi` (004) — literal
  same codebase. Unrelated to `shujian2008`/`shujiantianxia` (024,
  Century family) and `shujianpiaoling2` (025) despite titles.
- **Century / adm-single family** (custom securityd ACLs — §7.5 on
  sight): `shiji` (021), `shujian2008` (024), `xianjianchuanqi` (027),
  `xiakexinzhuan2` (028), `xiakexing100` (030), `zhonghua2` (023,
  related shape).
- **风云3 engine**: `zzfy`/`fengyun3xiuding`/`fengyun3dianzang` (020),
  `moniHuafu` (039, own game). **风云Ⅳ**: `fengyun434`/`fy2005` (009).
  **风云再起Ⅱ**: `fy2`/`fengyun2qinghua` (011). Family-wide idioms:
  securityd `resolve()` ordering (§1.3c), environment(me) quit race
  (§7.14), phone-home checks (§7.13).
- **夕阳再现 family**: `xiyangzaixian_fengkuang`/`_fengyun2`/
  `jianghufengyun` (032); derived own-games `weimingkongjian` (038),
  `bixiecanyang` (047), `xiaoaojianghu_client` (050).
- **XYZX/炎龙封印 branch**: `xiyangzaixian3`/`yanlongfengyin_xiaoao3`/
  `longyunmeng` (033; `longyunmeng_binary` 033-3 not convertible).
- **XO / TMI-2 / Falcon**: `xo`/`xo_final`/`xiaoaojianghu2`/
  `xiaoaojianghu_xo` (019). NOT nitan, despite 笑傲江湖 titles.
- **NT / nitan / Lonely**: `nitan170911` (014), `nitan6` (015) — §7.15
  applies; `nitan_ceshi`/`nitan_san` (041) — earlier branch, §7.15
  does NOT apply. Mega-libs; §10.4 memory rules.
- **"hell" / Doing Lu**: `zhongjidiyu_airuoyoulan`/`zhongjidiyu_zhijian`
  (053). `zhongjidiyu` (052) is UNRELATED despite the identical title.
- **XLQY 仙侣情缘**: `xlqy_new2007`/`xlqy_early`/`xianlvqingyuanzheda`
  (018); `xianlvqiyuan` (026) is a different, older codebase.
- **小雨西游**: `unknownlib20150716`/`xiaoyuxiyou` (003).
  **大唐双龙**: `dtsl`/`llmud_datangshuanglong`/`datangshuanglong`
  (007).
- **Standalone/distinct**: `shanhaizhanshen` (001, simple/ES-derived),
  `xingzhanyingxiong` (002), `chidi` (005), `xiakexing2017` (013),
  `tianxia` (034), `tianxiawuxue` (035), `xiakeyingxiong3` (029),
  `chongshengdeshijie` (055, GPLv2 BIG5 life-sim, custom dispatcher —
  nothing ports in or out).

Ten archive files are byte-identical duplicates of another archive
(browser "(1)" copies) — they share their sibling's number in
`lib_numbering.json` (`duplicate_of` field) and were never processed
separately.

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
