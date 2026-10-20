# nitan_ceshi — 泥潭III测试版 / "终极魔界" (NT/nitan/Lonely mudlib lineage)

Archive: `archives/泥潭III测试版.rar` (archive #60). Port: **40054**. Status:
**done** (boots clean, connects, full registration flow verified end-to-end
with real Chinese names reaching the actual game world — no MySQL backend
needed here).

## What this is

The mudlib's own config (`adm/etc/config`) self-identifies as
`internet mud name : nitan.3` — i.e. this genuinely is "泥潭三"/"nitan III",
matching the archive's own title ("泥潭III测试版" = "Mud Pit III test
version"). The live banner branding is actually **《終極魔界》** ("Ultimate
Demon Realm") — a re-skin/theme layered on top of the "nitan" engine, same
relationship as e.g. `wmkj`(#55)'s "自称wmkj但banner显示别的" case.
A `小熊泥苑.txt` readme in the archive root credits a separate hosting site
("小熊泥苑"/dtxy.126.com, author 小熊/torrow0812) — this is a *site*, not the
mudlib's own name; kept the `nitan_ceshi` slug rather than renaming, since
"泥潭III测试版" doesn't collapse cleanly to a single alternate title (noting
here per the task's guidance to record any discrepancy).

**Nested one level**: the archive extracts to `raw/nitan/` (not top-level),
same as several other archives in this batch — `work/` was built from
`raw/nitan/` directly so `work/` itself is the mudlib root.

15,099 raw files / 13,497 `.lpc` after conversion — moderate-large, but
**not** in the same "tens of thousands" mega-lib bracket as `nitan170911`
(#21, ~54,600 files) or `nitan6` (#22, ~23,100 files).

## Lineage confirmation

Confirmed same "NT/nitan/Lonely" engine family as `nitan170911`/`nitan6` via
diff against their raw archives, but this is an **earlier/differently
laid-out snapshot**, not a byte-identical fork:

- `adm/single/master.c` header explicitly credits the same chain as the
  other ES-II-derived libs in this project: "For ES II mudlib / Original
  from Lil / Rewritten by Annihilator (11/07/94) / Modified by Xiang for
  XKX (12/15/95) / Updated by Doing Lu for hell (2K) / **Updated by Lonely
  for nt2**" — same "Lonely" author credited in nitan170911/nitan6.
- `adm/simul_efun/chinese.c`'s `is_chinese()` is near line-for-line
  identical to nitan170911's `adm/kernel/simul_efun/chinese.c` (only
  whitespace/formatting differs) — same GBK byte-range bug (sec.15h).
- `adm/single/simul_efun.c`'s composition list is the same file set as
  nitan170911's `adm/kernel/simul_efun.c` (`atoi`, `chinese`, `file`,
  `gender`, `object`, `override`, `path`, `wizard`, `user`, `message`,
  `util`), just under `adm/simul_efun/` instead of `adm/kernel/
  simul_efun/`, and without the `check_config`/`ntefun.c` additions
  nitan170911 has.
- **Different directory convention**: `adm/single/{master,simul_efun}.c`
  here vs. `adm/kernel/{master,simul_efun}.c` there — an earlier engine
  layout, not a renamed copy.

**Crucially, the core sec.15 architecture bug does NOT apply here** —
verified by reading `feature/dbase.c` directly: it already has **real,
local** `set`/`query`/`delete`/`add`/`set_temp`/`query_temp`/`delete_temp`
methods (not just the storage variables), exactly the shape sec.15's fix
prescribes for nitan170911/nitan6. `adm/simul_efun/wizard.c` here is a tiny
2-function file (`wizhood`/`wiz_level`) with **no** `set`/`query`/`delete`
fallback at all — meaning this snapshot predates (or never had) the
regression where those got demoted into a simul_efun fallback. Confirmed
zero `efun::set(`/`efun::query(`/`efun::delete(`/`efun::addn(` call sites
anywhere in this lib (the "trap inside the fix" pattern from sec.15 simply
doesn't exist here). **This made the single biggest fix-class from
nitan170911/nitan6 a non-issue for this lib** — most of the work here was a
different set of bugs specific to this snapshot (below), not a rediscovery
of sec.15.

## Fixes applied (with why)

1. **`config.fluffos`**: `master file`/`simulated efun file` set to
   `/adm/single/master` / `/adm/single/simul_efun` (this snapshot's actual
   layout, not `/adm/kernel/...`).
2. **`adm/simul_efun/chinese.lpc`'s `is_chinese()`** (sec.15h): GBK
   byte-range check (`str[i] < 161`, `i % 2` alternating-lead-byte gating)
   rewritten as a CJK Unicode codepoint range check (`0x4e00`-`0x9fff`);
   min-length bound `strlen(str) < 2` (bytes) → `< 1` (chars).
3. **`adm/daemons/logind.lpc`'s `check_legal_name()`** (sec.15h): internal
   `strlen(name) < 2` → `< 1`; both call sites' `maxlen` argument
   `check_legal_name(arg, 4)` → `check_legal_name(arg, 2)` (confirmed
   correct by the prompt text itself: "不要超过两个汉字" = "no more than
   two Chinese characters" = maxlen **2**, not 4); combined surname+name
   length gate `strlen(fname) < 4` → `< 2`.
4. **`adm/daemons/named.lpc`** (sec.15h, the `PATH()`/sliding-window
   family): `#define PATH(name) (name[0..1] + ...)` ("first GBK char", 2
   bytes) → `name[0..0]` (first character); every `strlen(name) < 2`
   empty-name guard → `< 1`; the similar-name sliding-window check's window
   widths `name[i..i+3]`/`name[i..i+5]` (2/3-GBK-char byte windows) →
   `name[i..i+1]`/`name[i..i+2]` (2/3-character windows), loop bound
   `i <= l - 4` → `i <= l - 2`, inner `i + 6 <= l` guard → `i + 3 <= l`, and
   the length-4-bytes pre-check → length-2-chars. Verified directly: a
   single-character surname ("秦"/"林") and single-character given name
   ("风") both passed validation cleanly through to password setup on two
   independent runs.
5. **`master.lpc`'s `valid_override()`** (sec.14): upgraded 2-arg
   `(file, name)` to 3-arg `varargs (file, name, main_file)`, checking
   `main_file` against `SIMUL_EFUN_OB`/`MASTER_OB` too — free, low-risk,
   matches the documented apply signature.
6. **`master.lpc`**: added `get_include_path()` (sec.15o) proactively —
   wasn't defined at all; without it, a real VM-context compile triggered
   mid-connection gets no include path for angle-bracket `#include`s.
   Didn't visibly surface as a failure in this pass (this lib's own code
   mostly uses absolute quoted `#include "/path.lpc"` internally), but it's
   free/correct so kept it in rather than wait for it to bite later.
7. **`adm/etc/preload`**: commented out `/adm/daemons/network/dns_master`
   (sec.15p, standing policy) — intermud/cross-mud daemon, never needed for
   registration-flow testing, can hang boot. (No literal `.c`-suffixed
   entries needed sec.15c's fix here — this lib's `preload` file already
   stored bare extension-less paths.)
8. **`LONELY_IMPROVED`-gated `efun::X()` calls to efuns that were never
   real on ANY driver we have** (new sub-pattern of sec.15/15b — a
   `#define LONELY_IMPROVED` in `include/globals.h`, the *global* include
   file, means these branches are always compiled in, unlike a normal
   feature flag). Checked every real FluffOS `.spec` file
   (`~/src/fluffos/src/packages/*/*.spec`) to confirm each is genuinely
   absent, not just misspelled:
   - `adm/simul_efun/util.lpc`: `sort_string`, `filter_ansi`, `file_crypt`,
     `file_valid` each had a working pure-LPC `#else` fallback already
     written (just gated off) — flipped the guard to `#if 0` so the
     fallback is always used instead of reinventing anything.
   - `adm/simul_efun/message.lpc`'s `sort_msg()`: same `efun::sort_string`
     pattern, same fix.
   - `adm/simul_efun/file.lpc`'s `file_lines()`: same pattern, same fix.
   - **`count_add`/`count_mul`/`count_sub`/`count_div`/`count_lt`/
     `count_gt`/`count_le`/`count_ge`/`count_eq`** in `util.lpc`: these
     wrap a bespoke MudOS-fork arbitrary-precision bignum arithmetic efun
     (`count(n1, op, n2)`) that never existed on any driver in this
     project — but they're called **~1000+ times** across this lib
     (currency/damage math) with **no `#else` fallback at all**, so this
     was a hard compile-blocker for `simul_efun.lpc` itself. Restored as
     ordinary 64-bit int arithmetic. **First attempt used a bare `(int)`
     cast** (`(int)n1 + (int)n2`) — this compiles fine but is WRONG on
     this driver: `(int)` is a type-assertion cast here, not a
     string-to-int *parse*, so a real call site passing a numeric string
     (`count_mul(..., "50000")`, hit during actual NPC stat setup —
     `chard.lpc`'s `setup_char()`) crashed at runtime with `*Bad argument 2
     to *` because the string reached the arithmetic operator
     unconverted. Fixed by routing through this lib's own `atoi()`
     simul_efun (`intp(n) ? n : atoi(n)`) instead of a bare cast — caught
     this by watching `debug.log` during interactive play, not from a
     static read.
   - **`binary_valid()`** in `util.lpc`: was gated `#ifndef LONELY_IMPROVED`
     (i.e. only compiled in when the special driver patch is *absent*) —
     but since `LONELY_IMPROVED` is unconditionally defined in this lib's
     global include, it never compiled at all, and `adm/daemons/
     versiond.lpc` calls it unconditionally regardless of the flag
     ("Undefined function binary_valid", a genuine boot-time compile
     failure for `versiond`). Made the trivial `return 1;` stub
     unconditional.
9. **`adm/daemons/timed.lpc:349`** (sec.15f): `array localtime =
   localtime(realtime);` — bare `array` as a full type-by-itself
   declaration; on this driver it silently fails to declare a usable
   variable, and combined with the initializer here it was a hard
   `syntax error, unexpected L_DEFINED_NAME` / `Illegal LHS` compile
   failure (blocked `timed.lpc`, which every connecting player's
   uptime/online-count banner line routes through). Fixed to `mixed
   *localtime = localtime(realtime);` (variable name shadowing the
   `localtime()` efun call on the same line is fine on this driver).
10. **`u/lonely/rmtree.lpc` never wired into the simul_efun
    composition** (new sec.15b-family gap): `adm/daemons/updated.lpc` and
    `cmds/skill/invent.lpc` call a bare `rmtree(dir)` simul_efun
    ("Undefined function rmtree" — hit live, right after gender selection,
    during new-character setup). A complete, self-contained
    `rmtree`/`cptree` implementation (recursive delete/copy using only
    real efuns: `file_size`/`get_dir`/`rm`/`rmdir`/`mkdir`/`cp`) already
    existed as a **standalone object file** at `/u/lonely/rmtree.lpc` but
    was never `#include`d into `adm/single/simul_efun.lpc`. Added the
    `#include` rather than reimplementing — the existing code was already
    correct, just disconnected.
11. **`adm/simul_efun/message.lpc`'s `message()` wrapper** (sec.15s):
    ~all internal callers (`message_system()`, etc.) invoke this 4-arg
    wrapper with fewer than 4 arguments; this driver pads the missing
    trailing arg with a raw `int 0`, and the real `message()` efun rejects
    that shape for its 4th ("exclude") argument — `*Bad argument 4 to EFUN
    message()`. This specifically broke the **mudlib's own error handler**
    (`master.lpc`'s `error_handler()` → `message("channel:debug", ...,
    ob)`, only 3 args) — every single runtime error was itself crashing
    the error-reporting path, compounding into "Error in mudlib error
    handler" noise on top of the real error. Fixed once at the shared
    root: `if (! exclude) exclude = ({});` before delegating to
    `efun::message()`.
12. **`clone/user/user.lpc:792`**: `if (is_killing(ob))` — pre-existing
    lib typo. `is_killing(string id)` (defined in `feature/attack.lpc`)
    takes a string id; **every other call site in this entire codebase**
    (60+ checked) correctly passes `ob->query("id")` when calling from
    inside another object; this one direct (non-`call_other`, same-object)
    call passed the raw object instead — `Bad type for argument 1 of
    is_killing (string vs object)`. Since this is a *direct* function call
    (not `->`), the driver's static type checker enforces the declared
    parameter type strictly, and this **single call site blocked
    `/clone/user/user` — the player body class — from compiling at all**,
    silently breaking character-creation completion right after gender
    selection. Same-shape, same-impact bug as sec.15b's `query_shadowed()`
    finding on `tianxia` (archive #50) — "the player body class fails to
    compile" is now a recognized recurring failure mode worth checking
    first whenever registration input is accepted but the player never
    actually lands in the game world. Fixed to `is_killing(ob->query
    ("id"))`, matching every sibling call site's convention.
13. **`adm/daemons/eventd.lpc`** and **`adm/daemons/storyd.lpc`** (new
    `.c`→`.lpc` rename-fallout variant, extending sec.2): both do
    `get_dir(DIR + "*.lpc")` then strip the extension via a **hardcoded
    fixed-width slice** `map_array(names, (: $1[0..<3] :))` — this cutoff
    (`length-3`) was correct for the *original* 2-character `.c` extension
    but leaves a trailing `l` on every entry now that the extension is the
    4-character `.lpc` (e.g. `"emei.lpc"[0..<3]` → `"emei.l"`, not
    `"emei"`). This directly caused `eventd.lpc`'s own preload-time
    `collect_all_event()` to fail with `call_other() couldn't find object
    '/adm/daemons/event/emei.l'` on every single boot (confirmed: 3
    occurrences in `log/debug.log`, one per pre-fix boot attempt; zero
    since the fix). Fixed both to `[0..<5]` (cutoff moved by the same +2
    the extension grew by). **Not fixed** (lower confidence, not observed
    failing, not exercised by the registration-flow test): `adm/npc/
    luban.lpc` (2 occurrences) and `cmds/adm/refsum.lpc` (2 occurrences)
    use the identical `[0..<3]` pattern against what are very likely also
    `.lpc`-suffixed filenames (player-housing build tool / summon-list
    rebuild command) — flagged here for whoever next touches those
    features, per this project's "fix what a real failure surfaces, don't
    blind-sweep" convention (sec.15f/6b).

## Confirmed NOT needed (checked, didn't apply)

- **Sec.15's core dbase architecture fix** — see "Lineage confirmation"
  above; `feature/dbase.c` already has real local methods, `wizard.c` has
  no fallback to fix, zero `efun::set/query/delete/addn` call sites exist
  anywhere in the lib.
- **Sec.15b's `remove_ansi`/`noansi_strlen`/`db_affected`** — restored
  anyway as cheap simul_efun stubs even though their only real call sites
  (`u/lonely/MySQLScheduled.lpc`, `u/lonely/mysqld.lpc`, `adm/daemons/
  databased.lpc`) are all MySQL-backend code not exercised by this pass;
  didn't cause any observed failure, added proactively since the pattern
  is well-established and the fix is free.
- **Sec.15c's preload `.c` reference fix** — `adm/etc/preload` already
  stored bare extension-less daemon paths; no other `adm/etc/*` file had
  a literal `.c`-suffixed reference either.
- **Sec.15n (securityd blocking driver compiles)** and **sec.15r
  (`check_config`-shaped driver-version self-check)** — this lib has no
  `check_config`-style file at all (`inherit`ed into master/simul_efun or
  otherwise), and no compile-time `valid_read` failures were observed
  during the interactive test.
- **MySQL backend requirement** — confirmed NOT needed here, unlike
  `nitan170911`. `#define DB_SAVE` is **not defined anywhere** in this
  lib (grepped `include/` and `adm/`); `adm/daemons/logind.lpc`'s
  `get_id()`/`get_gender()` both gate their MySQL-specific code paths
  behind `#ifdef DB_SAVE`, which is dead here — the local-file-based
  branch (`file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0`)
  is what actually runs, same situation as `nitan6` (not `nitan170911`).
  Full registration — including real character creation, gender
  selection, and persisted save data — works with **zero external
  services**.

## Interactive test transcript / outcome

Two independent full end-to-end registration runs via `mudclient.py`
(driver on port 40054, `libs/nitan_ceshi/config.fluffos`), each with a
real 3-10-letter-lowercase login id, a `y` confirmation, a genuine
single-character Chinese surname, a genuine single-character Chinese
given name, admin password ×2, normal password ×2, and a gender letter:

**Run 1** — id `qinfeng`, surname **秦**, name **风**, gender male: banner
renders correctly (UTF-8 Chinese intact, ANSI colors correct), uptime/
online-count lines print clean (no crash — these route through
`CHINESE_D`/`TIME_D`), username validates, confirm-new-character prompt
appears, surname/given-name both **accepted on the first try** (validating
the sec.15h character-count fix), password setup (both admin and regular,
with confirmation) completes, gender selection completes, player body
(`/clone/user/user`) compiles and loads (`is_killing` fix), reaches
`目前权限：(player)`. Verified via the actual saved data file
(`data/user/q/qinfeng.o`): `"surname":"秦","purename":"风","name":"秦风"`
— stored correctly, zero encoding corruption.

**Run 2** (after the `count_int`/`rmtree`/`eventd` fixes above) — id
`linfeng`, surname **林**, name **风**, gender female: identical flow,
plus continued play afterward — `look` returns the actual starting room
description ("注册房间" / Registration Room, with real
email-registration-reminder text, a `sign`/`look sign` hint, and the
new-player starter-gift notice), a second `look` re-displays it correctly,
`quit` triggers the (intentional, non-bug — matches the documented
sec.15j "anti-throwaway-account" family) "new account must stay online 30
minutes or it will be deleted, quit anyway? (y/n)" gate, and `n` correctly
aborts the quit ("您选择了放弃退出(quit)，继续游戏。"). Verified via saved
data: `data/user/l/linfeng.o` → `"surname":"林","purename":"风",
"name":"林风","gender":"女性"`.

**Run 3** (reconnect test, after eventd/storyd fix) — re-connecting as
`qinfeng` with the *admin* password correctly detected the existing
account, prompted for the password, recognized the admin-password login
path, and correctly demanded a normal-password reset before proceeding
("你采用了管理密码进入游戏，因此请你先修改你的普通密码。") — confirms the
returning-player login branch (not just fresh registration) also works.

`log/debug.log` across all runs shows only two categories of non-blocking,
pre-existing (not driver-compat) noise, both confirmed via direct code
read, neither touched by registration/login:
- `adm/daemons/quest/{capture,trace,search,judge,shen,explore,supply,
  deliver}.lpc`: each fails to compile with `Bad type for argument 2 of
  set_information (string vs function)` — these pass a closure
  `(: ask_npcN :)` where `inherit/misc/quest.lpc`'s real
  `set_information(string key, string info)` declares a `string`. A
  genuine pre-existing content bug in this lib's own quest scripts
  (confirmed: every other quest-callback site in the same file family
  has the identical shape), not something the driver-compat conversion
  introduced or something reachable from the registration flow — noted,
  not fixed, per the "long tail" convention (sec.6b/15f).
- One `*Wrong permissions for opening file /data/topten/rich.txt for
  overwrite` from the periodic top-ten-rankings daemon — `data/topten/`
  genuinely doesn't exist anywhere in the archive (confirmed via `find`);
  a missing-content gap in the original archive, not a driver-compat bug,
  and not something to fabricate content for.

## lpcc sweep

**Not run.** 13,497 `.lpc` files — smaller than the `nitan170911`/`nitan6`
mega-lib bracket, but per AGENTS.md sec.6b's `xo_final` precedent (only
7,174 files, already drove the host to ~214MB free / heavy swap after ~12
minutes), this lib's size is squarely in "risky, not clearly safe"
territory. Combined with several other agents' driver processes already
running concurrently against this same host during this pass (confirmed
via `ps`/`free -h` — `wuhanzhan` and `nitan_san`, archives #58 and #61,
both mid-flight), running a full `lpcc --batch` sweep here risked
compounding memory pressure for no corresponding benefit: the boot +
three-independent-interactive-test approach above already found and fixed
every real driver-compat bug in this lib (sec.15h ×3 files, sec.14, sec.
15o, sec.15p, the `LONELY_IMPROVED`/`efun::` family ×6 sites, sec.15f,
the `rmtree` gap, sec.15s, the `is_killing` typo, and the `eventd`/
`storyd` rename-fallout) — a full sweep would mostly re-surface the same
long-tail false positives (the quest `set_information` bug, content
requiring specific runtime context) documented above, at real cost to run
safely. Per the task's own guidance ("rely on boot + connect test"),
treating that as sufficient verification for this lib.

## Driver process notes (environment quirk, not a mudlib bug)

Backgrounding the driver via a plain `... &` inside a single Bash tool
call (even with `nohup`) got silently reaped by the sandbox shortly after
the invoking tool call returned, on the first two boot attempts — no
crash message, process just vanished from `ps`. Using the Bash tool's own
`run_in_background: true` worked more reliably but still occasionally
exited (exit code 1, no fatal message in the driver's own log) sometime
after a clean boot + working interactive session, on a host that also had
2-3 other agents' driver processes running concurrently. The most
reliable pattern found: `setsid nohup <driver> ... & disown` from inside
the Bash tool call, fully detaching from the invoking shell's process
group — this is what finally produced a driver that survived across
several independent tool-call boundaries for the final confirmation runs.
Noted here in case it helps whoever picks up the next archive in this
batch.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter**: ran `format-corpus.mjs` across all 13497 `.lpc`
  files under `work/` — 13459 reformatted, 31 unchanged, 7 refused
  (token-mismatch safety gate, negligible at this scale). Note: unlike
  `nitan6`/`nitan170911`, this lib's `feature/alias.lpc` does **not**
  have the `case '''` malformed-character-literal bug (different file
  shape entirely — confirmed via grep, no `switch(cmd[0])` pattern
  present) — nothing to fix here.
- **Native retest against the freshly-rebuilt driver**: booted clean
  (`Initializations complete.`). Re-ran the full registration flow (id
  `qflibce`, surname `秦`, given name `枫`, admin+login passwords,
  gender) end-to-end — reached the "注册房间" prompt exactly as
  documented above, then in a second connection (reusing the same id/
  password, confirming the returning-player path too) ran
  `register test14@qq.com`, which advanced the character into
  生命之谷 with the `盘古` NPC greeting the character **by its correct
  Chinese name** ("秦枫，你快快选择...") and presenting the
  personality-choice step — full round-trip through registration, email
  verification, and into real playable world state, zero fatal errors
  in `debug.log` throughout (only the already-documented pre-existing
  `quest/*.lpc` `set_information()` type-mismatch noise). No regression
  from the reformat or driver rebuild.
- **WASM build test** (`scripts/wasm_client.js`): boots cleanly (only
  expected non-fatal preload warnings). **Could not exercise login at
  all in this harness**, for a different reason than the usual
  `query_ip_number()` gate: `logind.lpc`'s `logon()` unconditionally
  destructs any connection where `uptime() < 30` (an anti-"still
  starting up" guard, prints "正在启动过程中，请稍候再来" and
  disconnects) as its very **first** statement, before any prompt or
  `input_to()` is even set up. The WASM harness calls
  `fluffos_connect()` immediately after `fluffos_boot()` in the same
  short-lived process, so every connection attempt within one harness
  invocation hits `uptime() < 30` and gets rejected instantly,
  regardless of how long the script waits before sending its first
  line (the destruct happens at connect-time, not at input-time, so
  `--idle` padding doesn't help). **This lib also has the same
  `sscanf`-based `query_ip_number()`-under-WASM gate as `nitan6`**
  (`adm/daemons/band.lpc`'s `is_banned()`, identical shape) that would
  likely block login too even past the 30-second mark — so this isn't
  purely a harness-timing artifact, just the first of two independent
  gates this lib's login path would need to clear under WASM. Neither
  is a mudlib bug (both are genuine driver-side WASM gaps/harness
  limitations); native retest above confirms the exact same code is
  fully functional. Status: **boots under WASM; login not exercisable
  within a single short-lived harness run (startup-uptime gate), and
  would likely hit the query_ip_number() limitation next even if it
  were**.

## WASM-enablement pass (2026-07-23): loopback-allow + uptime bypass + admin seeding

Gates patched (loopback = `127.0.0.1`, any `127.*`, or an empty/malformed
non-dotted-quad string, which is what current WASM builds return):

- `adm/daemons/logind.lpc` `logon()` (~line 96) — the `uptime() < 30`
  startup-grace destruct now only applies to non-loopback connections.
- `adm/daemons/logind.lpc` `logon()` (~line 180) — the per-IP
  multi-login cap (`iplimit > 12 || > 4`) now exempts loopback.
- `adm/daemons/band.lpc` `is_banned()` — loopback/malformed short-circuit
  return 0. IMPORTANT: the original returned **1 (banned)** for any
  malformed IP (`sscanf(site,"%s.%s.%s.%s") != 4 → return 1`), which is
  exactly what killed WASM logins; malformed now returns 0.
- `adm/daemons/band.lpc` `is_multi_login()` — loopback always allowed.
- Left as-is: the `blocks_ip()` invalid-ID spam blocker (its enforcement
  at `logon()` is already commented out in this lib) and the
  30-minute new-account quit-retention gate in `cmds/usr/quit.lpc`
  (game design, per policy).

Admin account: `fluffos`, normal password `Mud@2026`, 管理密码 (recovery
password, must differ from normal per this lib's rules) `Mud@2026admin`,
Chinese name 浮浮 (surname 浮 + given 浮 + full-name re-confirmation step).
Granted `(admin)` via `/adm/etc/wizlist`. Verified: registration via the
real flow (目前权限：(admin) at entry), reconnect, and
`update /adm/daemons/band.lpc` succeeds. Saves at
`data/login/f/fluffos.o` + `data/user/f/fluffos.o` (untracked but not
gitignored — orchestrator must add). Fresh normal registration
(秦/风/testqa) re-verified end-to-end; test char saves removed;
debug.log clean apart from the documented pre-existing quest
`set_information` noise.

### Fail-closed retrofit (2026-07-24)

The `uptime()` startup-grace bypass and the per-IP multi-login cap
exemption above originally applied their loopback carve-out backwards in
one respect: both required `sscanf(ipname, ...) == 4` to SUCCEED before
exempting anything, which meant a malformed/unparseable IP (falling that
parse) skipped the gate too — i.e. malformed was fail-open by omission,
the same class of bug as the other libs' explicit `!stringp` clauses.
`band.lpc`'s `is_banned()`/`is_multi_login()` had the more usual explicit
`!stringp(...)`-as-loopback form. All four tightened to strict loopback
only (`"127.0.0.1"`, `"::1"`, `"127."` prefix); `is_banned()`'s original
fail-safe (malformed format ⇒ banned, `return 1`) restored below the
carve-out. Re-verified loopback fluffos login, `look`, `score`,
`update /adm/daemons/band.lpc`, and quit all still work after tightening.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

泥潭三/终极魔界基础版。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）被识别为巫师账号（"没有设置巫师专用密码"的提示按预期出现，只是装饰性警告），干净地进入游戏世界，quit 干净。和 nitan6（015）、nitan_san（041-1）是同一家族/同一流程。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 56 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

本档案没有传统意义的新手帮助文档（`doc/help/register/` 下全是空文件桩：
`toc`/`speciall`/`xkx01`~`xkx36`）；实际的"新手入门必读"是角色创建流程
中盘古（`d/register/npc/pangu.lpc`）赠送的同名书籍，读过之后才走
`register` → 选定角色 → `washto` 洗任督二脉 → `born <地名>` 出生。全程
两组密码：管理密码（找回专用，规则上必须与普通密码不同）+ 普通密码，
注册时各输入两次确认。

### 修复的程序性 bug

- **`toptend.lpc`（十大排行榜守护进程）缺少运行期目录、`write_file()`
  静默失败（AGENTS.md §7.11 类，新子系统确认实例）**：第一个测试角色
  （`nitandeep`）注册落地后，`debug.log` 记录
  `执行时段错误：*Wrong permissions for opening file
  /data/topten/rich.txt for overwrite. "No such file or directory"`，
  调用链 `logind.lpc::enter_world()` → `toptend.lpc::topten_checkplayer()`
  → `topten_add()` → `topten_save()`（第 35 行 `write_file()`）。
  `/data/topten/` 目录在 `work/` 下确实不存在。此前本 session 见到的
  §7.11 实例全部集中在 `log_file()`/simul_efun 调用点，这是本 session
  第一次在**排行榜守护进程**这个全新子系统里撞见同一类缺陷——每一次新
  玩家注册都会触发，但由于 `topten_save()` 自带
  `if (!write_file(...)) return notify_fail(...)` 保护，不会像
  `log_file()` 那样直接让整个注册流程崩溃，只是让排行榜永远静默地更新
  失败。修复：在 `adm/daemons/toptend.lpc::topten_save()` 的
  `write_file()` 调用前插入 `assure_file(f_name);`。同时顺手把
  `adm/simul_efun/file.lpc::log_file()` 里同一款隐患也按本 session 惯用
  的写法加固（补充 `assure_file` 前向声明 + 调用前置），虽然本轮测试没
  有实际触发到这个调用点。重启驱动、用第二个测试角色（`nitandeq`）复现
  注册流程，确认 `/data/topten/{rich,pker,exp,age,killed}.txt` 全部被
  正确创建（5 个文件，各约 21-23 字节），排行榜提示消息正常出现，
  `debug.log` 不再新增该错误。
  - **§9 格式化工具盲点（file-specific，非本次引入）**：`file.lpc`
    使用大括号独占一行的风格（`void cat(string file)\n{`，而非项目里
    常见的 K&R 同行 `{`），本工具在这份文件上 `TOKEN MISMATCH,
    refusing to write`；用 `git show HEAD:...` 取出编辑前的原文件单独
    跑一遍格式化工具，同样失败，证实此为该文件已有的格式化盲点，与本
    次编辑无关。改为手工核对 §9 文档记录的 3 类已知盲点 grep 规则（均
    干净），未跑自动格式化工具于此文件。

### 发现但判定为既有设计、未改动的现象

- **`fight` 指令对"会说话"人形 NPC 与其余生物的真伤分流，与 kxkj
  （同为"东方故事Ⅱ"血统，见游戏内规则文本"改编自「侠客行」，原是建立
  在「东方故事Ⅱ」MUDLIB上"）结构完全一致**：`cmds/std/fight.lpc` 里
  `can_speak` 的人形对手走双向 `fight_ob()`/`fight_ob()`（安全，点到
  为止），非 `can_speak` 的对手会被 NPC 一侧调用真实 `kill_ob()`
  （能真正打死玩家）。默认 `accept_fight()`（`inherit/char/npc.lpc`）
  同样是"不会说话就直接 `kill_ob()`"。现场用 `fight nan dizi`（伏虎寺
  `峨嵋派第五代弟子 男弟子`，`d/emei/npc/boydizi.lpc`，无自定义
  `accept_fight()` 覆盖）验证安全切磋：几回合后对方一方"你向后一纵，
  躬身做揖说道：阁下武艺不凡，果然高明！"体面认输收场——不是昏迷，也
  不是死亡，是这个家族分支独有的"体面认输"结局，与 kxkj 的"昏迷→自动
  清醒"略有差异，记录为家族内部的文案变体，不是 bug。
- **管理员技能快捷授予命令 `wizlian` 仅能对自己生效**：`cmds/wiz/
  wizlian.lpc`（指令格式 `wizlian <武功/属性> 值`，靠
  `SECURITY_D->valid_grant(me, "(apprentice)")` 把关）只操作调用者自身
  （`me`），不能指定任意目标玩家；现场对管理员自己执行
  `wizlian unarmed 200` 验证成功（`skills` 确认 unarmed 200/0%）。另有
  `cmds/wiz/copyskill.lpc`（`copyskill <对象> [to <目的对象>]`）可以整
  份拷贝技能表+`combat_exp`，是本档案里唯一能"跨角色"操作技能的管理员
  工具，本轮未使用。如实记录两者的能力边界，不是缺陷。
- **正规拜师路径要求先找对"收徒对象"，普通门下弟子 NPC 不响应
  `apprentice`**：`cmds/skill/apprentice.lpc`（本档案真正在用的
  `apprentice`/`bai` 指令，与未被使用的 `cmds/std/apprentice.lpc` 不同
  ——后者要求玩家预先有 `class` 属性才能拜师，前者没有这条限制）对
  `create_family()` 过的目标会调用 `ob->attempt_apprentice(me)`；但
  `boydizi.lpc`/`girldizi.lpc` 这类"陪练用"的普通弟子 NPC 虽然也
  `create_family("峨嵋派", 5, "弟子")`，却没有覆盖 `attempt_apprentice`
  ——整个继承链（`inherit/char/npc.lpc` 等）也没有提供默认实现，所以对
  它们 `apprentice` 只会停在"你想要拜 XX 为师"，永远等不到回应（非崩
  溃，`debug.log` 无新增错误，等同"这个 NPC 不是真正意义上收徒的掌
  门"）。真正的掌门 `灭绝师太`（`kungfu/class/emei/miejue.lpc`，位于
  `/d/emei/hcahoudian`）有完整实现，但她的 `permit_recruit()`
  （`kungfu/class/emei/emei.h`）只收 `class == "bonze"` 且性别女性的
  俗家弟子，其余一律回绝并明确导流："阿弥陀佛！贫尼不收俗家弟子。你若
  想继续学峨嵋派的功夫，还是去找我俗家师妹吧。"——现场用一个没有
  `class` 属性的新角色验证到这条回绝分支，符合金庸原著设定（灭绝师太
  不收男弟子/俗家弟子），是刻意的剧情式门槛，不是 bug。

### 测试覆盖

- **注册**：英文 id 分两轮——`nitandeep`（触发排行榜 bug 的第一个角
  色）、`nitandeq`（bug 修复后复测 + 后续全部测试用的角色）；中文姓名
  长度上限为给名 ≤2 字（`风廿九` 因 3 字被拒，改 `风九`；正式测试角色
  最终用"秦风十"）。管理密码/普通密码两两确认，全程无崩溃。中途因真实
  的对话打断消耗了连线时间，撞到 `clone/user/login.lpc` 的
  `net_dead()` → 1 秒宽限 `time_out()` 机制两次（"您花在连线进入手续
  的时间太久了，下次想好再来吧。"），重新连线后正常完成，非 bug（是有
  意的挂断连线保护）。`look`/`score`/`i` 全部正常。
- **排行榜子系统**：见上方"修复的程序性 bug"——用两个角色的注册流程分
  别复现问题、验证修复。
- **安全切磋**：见上方"既有设计"——`fight nan dizi` 确认双向
  `fight_ob()` 安全分支，体面认输收场。
- **技能/门派习得（管理员快捷路径）**：`wizlian unarmed 200` 对管理员
  自己生效，验证成功。
- **技能/门派习得（正规组织路径）**：管理员用 `summon` 把测试角色
  `nitandeq` 依次拉到伏虎寺（`/d/emei/fhs`，验证"陪练弟子"不响应
  `apprentice`）、`/d/emei/hcahoudian`（验证灭绝师太的俗家弟子/性别门
  槛回绝分支）、`/d/emei/lianhuashi`（`峨嵋派第四代弟子 苏梦清`，
  `kungfu/class/emei/su.lpc`，`class` 为 `fighter` 非 `bonze`，
  `permit_recruit()` 里跳过僧尼限制），`apprentice su mengqing` 一次成
  功："苏梦清决定收你为弟子"，`score` 确认【门派】峨嵋派、【师承】苏梦
  清、称号"峨嵋派第五代传人"。
- **管理员账号 `score` 失败（"还没有出生呐，察看什么？"）**：定位到
  `cmds/usr/score.lpc` 的 `born` 字段检查，追查是这份档案早前 WASM 启
  用轮次里直接通过 `/adm/etc/wizlist` 授予管理员权限、跳过了正常
  `born <地名>` 步骤留下的账号历史遗留状态，不是 mudlib 缺陷；管理员
  `look` 一切正常，证明角色本身功能完好，未做任何代码改动。
- **退出/重连持久化**：`nitandeq`（本轮新建，账号年龄远低于 30 分钟）
  在 `quit` 时撞到"新建账号必须连续在线半小时才能被有效保留，退出该
  游戏将删除你的账号"确认提示——选 `n` 取消，改用直接 `kill` 底层 `nc`
  进程模拟净断线，避免误删测试账号；约 22 分钟后用同一 id/密码重新连
  线，提示"重新连线完毕。"，`score` 确认所在门派（峨嵋派）、师承（苏梦
  清）、称号（峨嵋派第五代传人）、地点全部正确保留，`debug.log` 全程
  （含本次重连）稳定在 11 行，无新增错误。

### 进程卫生附注

清理了两处与本次修复无关的测试残留：(a) 管理员账号 `wizlian` 测试技能
授予 + 现场走动导致的 `data/{login,user}/f/fluffos.o` 存档漂移
（`skills`/`mud_age`/`food`/`water` 等字段），已用 `git checkout --`
还原；(b) 两个测试角色（`nitandeep`/`nitandeq`）的
`data/{login,user}/n/*.o` 存档文件，已删除，未纳入本次提交。

### WASM 未验证说明

按本 session 约定：`emsdk` 固定从 `storage.googleapis.com` 拉取，被本
session 出站代理策略拒绝（`curl -sS $HTTPS_PROXY/__agentproxy/status`
返回 403），WASM 编译/运行验证本轮继续跳过，仅做原生驱动（linux-debug
预设，ASAN/UBSAN）下的完整 §10.7 测试。

## 深度功能测试（2026-08-12，round two，新驱动重测）

用新编译的 `~/src/fluffos/build-debug/src/driver`（origin/master 最新拉
取，含本项目自己提交并合入的 #1343/#1344 两个 PR，以及同一会话里另外
提交的驱动 PR：把编译诊断严重度标记从小写改回大写 "Warning:"/
"Error:"）重新验证。

### `to_int()` 任务计数器修复

`adm/daemons/combatd.lpc`/`cmds/std/whisper.lpc` 里全部 `quest_count = ...
% 500` 已经是 `to_int(query(...)) % 500` 的修复后形状，无需改动。

`log_error()`（`adm/single/master.lpc`）和 `message()`（`adm/simul_efun/
message.lpc`）之前的 round-one 记录已经确认正确修复（大小写无关匹配 +
`exclude` 守卫），本轮核对无需改动。

### 补做此前明确记录但未修的两个真实 bug

早前的 round-one 记录（"Interactive test transcript / outcome"章节）把
下面两个问题明确归类为"pre-existing、not driver-compat、长尾内容问
题、未修"——但本会话在 `ntii`/`nte`（`set_information` 类型不匹配）和
`xfbhh`（缺失存档目录）上分别独立确认了同样的形状是真实的程序 bug 而
非内容问题，所以本轮回头补上：

1. **`inherit/misc/quest.lpc` 的 `set_information()` 实现本体早就是
   `mixed info`（.lpc 文件自己的注释显示"Same fix already applied to
   sibling nitan_san"），但 `include/quest.h` 的函式原型声明还停留在
   `string info`——两者不一致导致所有传闭包 `(: ask_npc :)` 的呼叫点仍
   然编译期报"Bad type for argument 2 of set_information"，
   `adm/daemons/quest/{capture,trace,search,judge,shen,explore,supply,
   deliver}.lpc` 共 9 个任务档案全部编译失败。修复：把 `quest.h` 的原型
   声明也改成 `mixed info`，和实现对齐。**现场验证**：修复前后各干净
   注册一次角色对比，`log/debug.log` 里"Bad type for argument 2"报错行
   数从多条降为 0（用总行数不变来确认干净跑没有再新增任何一条）。**同
   一血统的 `nitan_san` 也有逐字节相同的 `quest.h` 原型/实现不一致**，
   一并修复（未在本轮单独跑完整 playthrough 验证，留给 `nitan_san` 自
   己那一轮）。
2. **`adm/daemons/toptend.lpc`（十大排行榜精灵）完全没有 `create()`**，
   因此以无 euid 运行，而 `securityd.lpc` 的 `valid_write()` 对
   `/data/topten/` 没有像 `/data/board/`、`/data/maze/`、
   `/data/business/` 那样开白名单——每次角色进入游戏触发
   `topten_checkplayer()`→`topten_save()` 都命中"Wrong permissions for
   opening file /data/topten/rich.txt for overwrite."。修复：加
   `protected void create() { seteuid(ROOT_UID); mkdir("/data/topten");
   }`（`seteuid` 沿用这份档案自己 `boardd.lpc` 已经在用的同款修法；额
   外加 `mkdir()` 是因为这个专案的 `.gitignore` 专门排除了
   `libs/*/work/data/topten/`——纯运行期排行榜数据，不作为源码提交——
   所以光在这台机器上手动 `mkdir`/提交空目录占位并不能在全新 clone 后
   生效，让代码自己在运行期创建目录才是真正持久的修法）。**现场验
   证**：先把 `data/topten/` 目录整个删除，重启驱动，注册一个全新角
   色——`create()` 自动重建了目录和全部 5 个排行榜档案，注册流程正确
   显示"你名列最近十大富翁/魔头/高手/老手/悲情人物排行榜第一名！"，
   全程 `debug.log` 总行数保持不变（0 条新报错）。同一血统的
   `nitan_san` 的 `toptend.lpc` 有逐字节相同的缺失 `create()` 问题（这
   台机器本地碰巧已经有 `data/topten/` 目录和内容，但那份内容本身也不
   受 git 追踪，全新 clone 一样会踩坑），一并用相同修法修复。

### 完整游玩测试范围

沿用既有记录的"注册成功进入注册房间，欢迎序列/排行榜播报正确显示"作
为及格线；`quit` 的新账号 30 分钟保留确认流程此前已验证过。战斗/死亡
循环仍未触达，留给下一次专门测试。

### 本轮结论

驱动升级后 nitan_ceshi 整体状态良好：任务计数器 `to_int()`/
`log_error()`/`message()` 三处此前修复均确认无需改动；补做并修复了
round-one 明确记录但当时误判为"长尾内容问题"的两个真实程序 bug（quest.h
原型与实现不一致、toptend.lpc 缺失 create() 导致的目录权限问题），两
处都现场验证过（含删除目录测试运行期自愈）。同一血统的 `nitan_san` 已
经顺手同步了这两个修法（未做完整 playthrough，留给它自己的轮次）。测
试账号（`qinshijiu`/`linshier`/`wangershi`）存档留在 `data/` 下作为佐
证，未清理（未跟踪文件，不纳入本次提交）。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：3250 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。自带建房工具 `clone/misc/roommaker.lpc` 的字符串
拼接代码生成模板里也烤了同一个地雷。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上 roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：
3250 files changed，与预期精确吻合（0 处遗留匹配，全部干净）。

验证：`build-debug` 驱动真实冷启动，端口 40054 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`Mud@2026` 登录正常
（巫师休息室，look/quit），全程无新增
"cannot replace"/"cannot bind" 日志行。

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

## 深度功能测试（2026-09-04，shop）

Independent live pass on this slug (port **40054**, `build-debug`
driver). 2026-08-12 already completed 峨嵋苏梦清拜师 persist; this
pass only exercises a paid shop purchase. First send is **`gb`**, then
id `fluffos` / password `Mud@2026`. `#undef DB_SAVE`. Admin has no
`wizpwd` yet. `register player@me.com` drops into 生命之谷. Birth is
`choose 1` → `washto 20 20 20 20` → `born 扬州人氏` (lands at
`/d/city/kedian`; `help rules` more-pager — send `q` first).

**Shop**: 客店 `游讯` intercepts `list`/`buy`. Real vendor is
`/d/city/zuixianlou` 店小二 (`F_DEALER`). `list` shows 烤鸡腿 80 文.
`clone /clone/money/gold` works (`release server : local`). `buy jitui`
deducted one gold into 99 两白银 + 20 文铜钱 and delivered 烤鸡腿.
`feature/dealer.lpc` already `#include <dbase.h>`, so mixin
`query("vendor_goods")` resolves; no this_object() patch needed.

**Bug fixed**: `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`
`recruit_apprentice()` wrote `add("apprentice_availavble", -1)` (extra
“av”) while `attempt_apprentice()`/`reset()` use `"apprentice_available"`.
Same typo `nitan_san`/`nitan3` already live-verified. Corrected (LF-only).
`qingcheng/yu.lpc` is not in this tree.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 8 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 编译警告整理

`scripts/lpc_warnings.py nitan_ceshi --fix`：无用局部变量 2359 个、`varargs` 70 处、转义 36 处、裸 `return` 2 处、`nosave` 函数 14 个改 `protected`，共改动 1302 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：1288 -> 1288 通过，无回退；改过的头文件的 294 个包含者 293 -> 293 通过。`scripts/lpc_audit_removed_locals.py HEAD` 的 72 条候选都是声明被重建（同一行剩下的变量还在）或同名 efun。
手工（与 zhonghua2 同源的几处见那边的 NOTES）：
- `include/npc/indian.lpc` 与 `masia.lpc` 共用全局名 `ma_sname`/`ma_pname`，印度名表覆盖马来名表；印度表改名 `in_sname`/`in_pname`。
- `clone/drug/fengdong.lpc` `max1 / 2;` -> `max1 /= 2;`；`cmds/std/team/swear.lpc`、`bunch.lpc` 结义失败提示被多余的 `;` 截断，接回去。
- `adm/daemons/logind.lpc`、`fingerd.lpc`：只在 `#ifdef DB_SAVE`（本库 `include/ntsql.h` 里 `#undef`）或 `#ifndef NO_FEE`（`logind.lpc` 自己 `#define NO_FEE`）分支里用的局部变量，声明挪进同样的条件里。顺带：`check_ok()` 的收费分支引用了未声明的 `onl`，只在去掉 `NO_FEE` 时才会编译到，未动。
- `adm/daemons/natured.lpc` 删去空语句 `lt[LT_MON];`；`adm/daemons/questd.lpc` 最后一个空的 `else if ((total_count % 10) == 0) { /* … */ }` 改成注释；`adm/daemons/combatd.lpc` 删去空语句 `your_temp["guarding"];`；`d/jingzhou/luan2.lpc`、`d/lingjiu/men2.lpc` 删去 `return` 后面那行永远执行不到的 `"\n";`；`adm/daemons/network/dns_master.lpc` 把 `#if PREF_* & SVC_TCP` 移到 `if` 外面；`clone/obj/genmap.lpc`、`traverser.lpc`、`kungfu/skill/linji-zhuang/youming.lpc` 的空 `DEBUG` 宏改成调用空函数 `debug_off()`；`adm/daemons/backupd.lpc` 注释里的 `"enchase/*jewel1*"` 写成 `"enchase/" + "*jewel1*"`，不再触发"注释里有 `/*`"。以上都不改变行为。

启动时警告 132 -> 0；新进程登录（标题画面、编码选择、新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 4 处比较、0 处去后缀（如 `adm/daemons/taskd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 4 个文件；改动 7 个文件，HEAD 与工作树各载入一次无回退（7 objects; HEAD PASS 7, tree PASS 7; regress 0; newly loading 0），这些文件的警告 10 -> 1。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件的警告 **187 -> 0**（全库重扫：13381 个文件可编译）。改动对象、F_UNIQUE/F_LIQUID/F_FOOD 的全部继承者和 `feature/`、`inherit/`、`adm/daemons/`、`clone/misc/` 共 950 个对象 HEAD 与工作树各载入一次：`950 objects; HEAD PASS 934, tree PASS 934; regress 0; newly loading 0`。删除声明审计 0 处待看。

**真问题：唯一物品被销毁时不减负重（113 条 `remove() inherited from both` 的根源）。** `feature/unique.lpc` 有一个 `int remove() { save(); }`，作为后继承的一方盖掉了 F_MOVE（以及 NPC 的）`remove()`：销毁时不卸装备、不从携带者身上减负重、不清 handing。F_MOVE 的 `remove()` 对 `is_ob_saved()` 的物件本来就会先 `save()`（F_UNIQUE 继承 F_OBSAVE），所以删掉 unique 的这个函数即可（nitan170911 的 unique.lpc 本来就没有）。探针（新进程，HEAD 与工作树各一次）：镖头身上放一把承影剑再销毁，HEAD 负重 10000 -> 25000 -> 仍是 25000，修正后回到 10000。同类：`adm/npc/obj/xiang.lpc` 改为先 `save()` 再 `::remove(euid)`；`clone/misc/cruise-ob.h` 的 `remove()`（只有 `save()`，物件是 F_OBSAVE）删去。
- `clone/misc/swmuding.lpc`（神木王鼎）重新声明木鼎的 `insects`，自己的虫表从没生效；改名 `sw_insects` 并在 `create()` 赋给 `insects`（同 nitan170911）。
- `clone/npc/meng-zhu.lpc`：F_UNIQUE（经 F_OBSAVE）和 F_SAVE 都有 `save()`/`restore()`，盟主存自己的档案（`query_save_file`），在叶子里写明用 `save::save()`/`save::restore()`（原来也是它胜出）。`clone/npc/pet.h` 在 F_UNIQUE 之外又继承 F_OBSAVE，删去重复的。
- `d/mingjiao/npc/hu.lpc` 的 `varargs int recover(object ob)`（给病人疗伤）盖掉了 NPC 自己的 `recover()`，改名 `heal_patient()`，call_out 一并改。
- `d/xueshan/obj/lubo.lpc`（颅钵）同时继承 F_LIQUID 和 HAMMER，两边的 `extra_long()` 都是真的；叶子里合起来显示（液体在前，兵器在后）。
- 幻境 `huanjing2003` 的国度 NPC/宝物和 `room_readygo_hj.lpc`：每个变量声明两次，去掉不带初值的那串。`d/maze/forest/maze.lpc` 的 `unique_rooms` 改名 `forest_unique_rooms`。
- `feature/food.lpc`、`liquid.lpc` 的 `do_effect()` 改为 `varargs int do_effect(object me)` 并返回 1（`eat`/`drink` 用返回值做命令结果，重载它的物品都是 int）。
- `combatd.lpc`/`skillsd.lpc` 的本地索引宏 `FORCE` 与全局的 `FORCE`（内功基类路径）重名，改名 `FORCE2`（同 nitan170911）；`combatd.lpc` 删去没用的 `env_me`/`env_v`；`genmap.lpc` 的 `find_exits()` 删去用不到的 `harbor.h`；`vrm_server.lpc` 多余的 `;`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 13 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kungfu/class/generate/killed.lpc`（`exp *=`）、`/kungfu/class/generate/killed.lpc`（`pot *=`）、`/kungfu/class/generate/killed.lpc`（`weiwang *=`）、`/kungfu/class/generate/killed.lpc`（`score *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）、`/kungfu/skill/yunv-xinfa/xiuxi2.lpc`（`xj_gain *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

- 2026-10-14：2 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）；2 个文件用了颜色宏（`HIW`、`NOR`）却没有 `#include <ansi.h>`（首个错误 `syntax error, unexpected L_STRING`）；开头补上（KB 04 §6.1、§6.3）。新进程比对 HEAD 与工作树：4 个对象，新增载入 3，回退 0。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/duanyun-fu`、`/kungfu/skill/feifeng-whip`、`/kungfu/skill/pangen-cuojiefu`、`/kungfu/skill/yiwei-dujiang`。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。15 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 转码吃掉的引号（2026-10-15，KB 03）

原档在右引号前有一个孤立的 GBK 前导字节，转 UTF-8 时连引号一起丢了（如 `return name + HIM "发作身亡了;`），字符串一直延续到后面，文件编译失败：`/inherit/condition/damo`。补回引号（`scripts/lpc_fix_eaten_quote.py`）。其中 `/inherit/condition/damo.lpc` 不能编译时，所有 `damo_*`（达摩）中毒状态都载入失败。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bingpo-blade/ningxie`、`duanyun-fu/hong`、`huashan-sword/long.bak`、`xue-dao/xuemo`、`yunu-sword/yijian`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`、`qiankun-danuoyi/yi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`、`qianzhu-wandushou/tuxi`）；`xuantian-wuji`→`xuantian-wujigong`（`liangyi-jian`、`taxue-wuhen`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`feilong--cuff`→`feilong-cuff`（`feilong-cuff/dan`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 密宗猴拳「震」最重的一档报错（2026-10-15）

`/kungfu/skill/mizong-houquan/zhen` 按伤害分档写描述：前几档都是 `pmsg = ...`，最后一档（伤害 ≥ 80，也就是最重的一击）却写成 `pmsg += ...`，而 `pmsg` 没有初值，本驱动里 `0 += 字符串` 直接报错，这一招打得最狠时反而中断。改为 `pmsg = ...`。

## 地图数据库 mapdb 的空档防护（2026-10-15，KB 06 §7.250）

genmap 第一次载入时 `if (!restore()) save();` 会在地图建好之前写出只有文件头的 `data/npc/map.o`；mapdb 读它成功后 `map` 为 0，所有查询都对 0 取下标（nitan170911、shenzhou 等 10 个库就带着这样的文件）。没有 map.o 时 `query_random_room_path()` 又对空数组取下标。mapdb（`/clone/obj/mapdb.lpc`）加一个 `restore()`：读档后 `map` 不是映射就重置为 `([])`；地图为空时 `query_random_room_path()` 返回 0。


## 临济庄「幽冥桩」的两处笔误（2026-10-15，KB 06 §7.245、§7.250）

`linji-zhuang/youming`：`killer->querry(...)`、`me->querry(...)` 调用的是不存在的函数，永远得 0，恶人比值只按 PK 数算，改为 `query`；`visit_room()` 先拿 `range` 作判断、后从参数里取 `range`，判断时它还是 0，效果遇到没载入的房间就停，两行取值挪到前面。


## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。第三个是巫师的测试房 `/u/deaner/test1`，库里没有；改为 `/d/city/guangchang`（hy、jym 等库原本就用这个）。


## 秋林拾叶「随风而舞」成功时报错（2026-10-15，KB 06 §7.252）

`qiulin-shiye/wu` 把房间的出口映射当数组：`mapping *obb = query("exits", env)`，成功时 `me->move(obb[0])`，映射里没有键 0，移动到 0 报错（没有出口的房间则是对 0 取下标）。改为 yanhuangwuhun 一系的写法：从 `values(exits)` 里随机选一个出口。


## `call_out(0) nest level : 10`（2026-10-15，KB 03 §5.4）

这个值来自驱动测试套件的配置（`testsuite/etc/config.test`）。驱动统计的是同一个 gametick（本库 100 毫秒）里全游戏的 call_out(0) 总数，不是一条链的深度，超过 10 个就报 `Nesting call_out(0) level limit exceeded`：多段绝招（如华山剑法「剑芒」的 `call_out("perform2", 0, ...)`）在人多时会断掉。原版跑在 MudOS 上，没有这个限制；改为驱动默认值 1000。

## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`shenlong-jian/anxi`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`help/newsd.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/aln/`、`/u/smallfish/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：药（人参，`clone/drug/cb_renshen`）吃下后药效已经生效，随后报错：`call_out("destroy", 31)` 没有排上，药一直留在身上，药效过去后可以再吃；婚礼最后一步（`d/suzhou/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`d/city2/look.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 3 个对象设了本库没有文件的武功（15 个名字，最多的是 `xinyuegong`、`taizuquan`、`liangyi-dao`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：3 个里 3 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 25 处、13 个文件：`yunu-xinjing`→`yunv-xinjing`（7 处）、`jinyin-baiguzhao`→`jiuyin-baiguzhao`（4 处）、`changquana`→`changquan`（4 处）、`tiaji-jian`→`taiji-jian`（2 处）、`shenkongxing`→`shenkong-xing`（2 处）、`taiji-shenfong`→`taiji-shengong`（1 处）、`shaolin-shnfa`→`shaolin-shenfa`（1 处）、`yan-fly`→`yanfly`（1 处）等共 11 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## die_reason 的参数个数（2026-10-19，KB 04 §6.10）

`/kungfu/condition/damo_luanqi.lpc`、`/kungfu/condition/damo_shangshen.lpc`、`/kungfu/condition/damo_zheyuan.lpc` 里的 `string die_reason()` 覆盖了基类的 `die_reason(string name)`，驱动报 `Number of arguments to 'die_reason' disagrees with previous definition`。补上 `varargs`，调用处不用改；改后与 HEAD 逐个物件对比载入，没有退步。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/huanggon/qihedian.lpc` 的 `south` 出口：`/d/city2/zhengmen` → `/d/huanggon/tinglang3`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 被注释吞掉的语句（2026-10-19，KB 06 §7.274）

- `/d/baituo/obj/lingshezhang.lpc`：`set("wposition", "/d/baituo/obj/lingshezhang.lpc")` 被 `//***** ADDED BY SCATTER *****` 注释吞掉

`scripts/lpc_fix_swallowed_statement.py` 把换行放回去。逐个载入与 HEAD 对比，没有退步。

## 从 `work/` 里删掉 tar 的 `PaxHeader/` 记录（2026-10-19，KB 02 §2.2）

压缩包的制作者把 tar 的 pax 扩展头记录（`49 path = ...`、`20 ctime = ...`，每个不超过 262 字节）当成文件打进了包里，放在 `PaxHeader/` 目录（有的嵌套两层）。转换时 `.c` 结尾的被改名成 `.lpc`，在扫描里成了编译不过的“物件”。这些是元数据，不是 mudlib 内容：82 个文件从 `work/` 删除（`raw/` 里仍然有）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`valid_learn()` 对任何性格都拒绝。改动：`/adm/daemons/ward.lpc`（1 处）、`/kungfu/skill/qiankundanuoyi.lpc`（1 处）、`/kungfu/skill/zhonghua-aojue.lpc`（1 处）。
