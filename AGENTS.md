# AGENTS.md — handbook for restoring and polishing these mudlibs

This is the accumulated knowledge base of a ~100-archive restoration
project, rewritten as a durable reference for whoever (human or agent)
continues the work. Read the section relevant to your task before touching
a lib; almost every problem you will hit has been hit before and is
cataloged here with its fix.

**Current state**: all 103 archives triaged; 91 Chinese LPC mudlibs fully
converted, playable, and committed (plus `ds386`/Dead Souls, English,
deliberately left partial). Every lib has a number (see `README.md`'s
table and `lib_numbering.json`): `NNN` per unique game, `NNN-M` for
confirmed derivatives of the same codebase, `9xx` for non-LPC archives.
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
  README table. 40001–40094 are assigned; **next free port: 40095**.
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
are encouraged** for everything in this section except the
`query_ip_number()` bug itself (which has a proper driver fix in
progress).

#### (a) `query_ip_number()` returns garbage — driver bug, fix in progress

On the current WASM build, `query_ip_number()` on an in-process
connection does not return a real dotted-quad (observed returning `"("`),
despite the driver setting `INADDR_LOOPBACK` internally. Any login path
that parses/validates the IP breaks. Three recurring shapes, all one root
cause:

- `sscanf(ip, "%d.%d.%*d.%*d", ...)`-style site/ban daemons reject every
  login (e.g. `bxsj`'s `sited.lpc`, many `band.lpc`/`BAN_D` variants) —
  usually a clean "not welcome" rejection message.
- `explode(query_ip_number(ob), ".")[1]`-style indexing throws an
  **uncaught `Array index out of bounds`** and silently desyncs the whole
  prompt chain before the id prompt (e.g. `menghuanxiyou2002`/`mhxy`'s
  `ipd.lpc`, `zitengzhan`'s `band.lpc`).
- Cosmetic-only uses (displaying the IP in a banner) — harmless, ignore.

**Two driver-side fixes are in progress**, and this is the contract a
future agent can rely on once they land:

1. `query_ip_number()` on a WASM connection returns a real
   `"127.0.0.1"` dotted-quad (and `query_ip_name()` something sane like
   `"localhost"`).
2. `resolve()` under WASM no longer raises "DNS resolver is not
   available" — it mirrors the native contract exactly but with
   synthetic success: the callback is scheduled on the next tick, any
   hostname resolves to `"127.0.0.1"`, reverse lookups to
   `"localhost"`.

**Implication: once these land, do NOT patch mudlibs around IP-format or
`resolve()` crashes under WASM — rebuild the WASM driver and RE-TEST the
~30 libs whose status is "limited" with an IP-related reason (grep
`scripts/wasm_status.json` for
`query_ip_number\|IP\|band.lpc\|BAN_D\|sited\|ipd`).** Mudlib-side
patches already made for these two classes are legacy and can be
simplified away over time. The mudlib-side policies that DO remain
regardless: the loopback-allow-through-ban-gates patch (b), the
uptime-gate/throttle bypass (e), and the `fluffos`/`Mud@2026` admin
seeding (§1.5).

#### (b) The loopback-allow patch (standard, per user direction)

Every lib gets a small patch making connections from `127.0.0.1` (and,
defensively, any *malformed* IP string, which is what WASM currently
produces) bypass ban lists, site-restriction gates, and per-IP
registration throttles. Shape — short-circuit at the TOP of the gating
function(s), before any parsing of the IP:

```lpc
// in BAN_D/band.lpc's is_banned(), sited.lpc's site check,
// logind.lpc's inline gate, etc.
int is_banned(object ob)
{
    string ip = query_ip_number(ob);
    // local/WASM connections are always allowed; also guards against
    // malformed IP strings crashing the parser below.
    if (!stringp(ip) || ip == "127.0.0.1" || sscanf(ip, "%*d.%*d.%*d.%*d") != 4)
        return 0;
    ... original logic unchanged ...
}
```

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
  NOTE: the in-progress `resolve()` driver fix (§1.3a) makes the
  `catch()` unnecessary going forward — but the reordering is correct
  defensive style anyway, and the state-init-before-network-call lesson
  generalizes.
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
  user-facing strings catches it (`huoying`'s `config.cfg`). Re-decode
  just the affected lines with BIG5.
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
  `kuangxiangkongjian`, recurs across ES II.)
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
`zhongjidiyu_airuoyoulan`, `tiexuejianghu`. **Empirical caveat: a
`private` command_hook does NOT always break dispatch on current
drivers** — `shiji`, `tianxia`, and `zhonghua2` work despite it (exact
conditions unestablished; possibly declaration-shape or driver-version
dependent). So: treat `private command_hook` as a prime suspect and fix
it on sight, but do not *assume* it is the (only) cause — verify by
actually testing `look` after the fix, and keep hunting (§8.3b, §7.14)
if commands are still dead.

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
   or rewriting the mudlib's call. A driver-repo fix was dispatched
   upstream; until confirmed merged, keep running this check.
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

### 10.6 English-language archives

Standing policy: deprioritized. Confirm what an English lib is, note
it, don't sink conversion time (`ds386` Dead Souls partial;
Discworld bundles untouched). Revisit only on request.

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
4. In progress: the **WASM `query_ip_number()`/`resolve()` fixes**
   (§1.3a) — the trigger to retest, not patch, the IP-gated libs.

The formatter (`tools/lpc-syntax/`) and its pending `::` fix also live
in the fluffos repo (§9).
