# nitan_san — 泥潭三 (NT/nitan/Lonely mudlib lineage)

Archive: `archives/泥潭三.rar` (archive #61). Port: **40055**. Status:
**done** (boots clean, connects, full registration flow verified end-to-end
with real Chinese names, reaching an actual game room — no MySQL backend
needed).

## What this is

The mudlib's own config (`config.cfg`) self-identifies `name : 泥潭`
("Nitan"/"Mud Pit") and `internet mud name : nitan.3` — i.e. this genuinely
is "泥潭三"/"Nitan III", matching the archive's own title exactly (no slug
discrepancy worth noting beyond the ASCII-ization to `nitan_san`). The live
banner branding is actually **《終極魔界》** ("Ultimate Demon Realm") — a
re-skin/theme layered on top of the underlying "nitan" engine, the same
"self-ID differs from live banner" relationship documented for several
other libs in this project (`wmkj` #55, `nitan_ceshi` #60).
`u/lonely/welcome` (the actual banner used, distinct from a generic
`adm/etc/welcome` template also present but unused) explicitly renders
"泥潭" ASCII art with "一入泥潭深似海" and "驱动版本: MudOS v22.2b14
NT-Build" — this really is the flagship/eponymous "Nitan" game the whole
"NT/nitan/Lonely" family in this project is named after.

Extracts to `raw/nitaniii/` (one directory level, not top-level) — `work/`
was built directly from that. 15,252 raw files / 13,559 `.lpc` after
conversion (+2 for two new simul_efun fragments added during this pass) —
a genuine mega-lib, well inside the "risky for a full lpcc sweep" bracket
established by `xo_final` (7,174 files) and confirmed again by the sibling
archive #60 (`nitan_ceshi`, 13,497 files) processed concurrently this same
session.

## Lineage confirmation

Confirmed same "NT/nitan/Lonely" engine family as `nitan170911`/`nitan6`
(and, per its NOTES.md, the concurrently-processed sibling `nitan_ceshi`,
archive #60) via direct diff against `nitan170911`'s raw archive, but this
is yet another distinctly-laid-out snapshot, not a byte-identical fork of
either:

- `adm/single/master.c`'s header credits the exact same authorship chain
  as the other ES-II-derived libs in this project: "For ES II mudlib /
  Original from Lil / Rewritten by Annihilator (11/07/94) / Modified by
  Xiang for XKX (12/15/95) / Updated by Doing Lu for hell (2K) / **Updated
  by Lonely for nt2**" — byte-identical wording to `nitan_ceshi`'s and the
  same "Lonely" author credited in `nitan170911`/`nitan6`.
- `adm/single/simul_efun.c`'s `#include` composition list differs from
  `nitan170911`'s `adm/kernel/simul_efun.c` by only 32 diff lines (mostly
  the `adm/simul_efun/` vs `adm/kernel/simul_efun/` path prefix) — same
  file set (`atoi`, `chinese`, `gender`, `object`, `file`, `override`,
  `path`, `wizard`, `user`, `message`, `util`, `ntefun`), same order.
- `adm/single/master.c` vs `nitan170911`'s `adm/kernel/master.c`: 803 diff
  lines — a much bigger divergence than simul_efun's, consistent with an
  independently-evolved "III" branch rather than a renamed copy.
- **Directory convention**: `adm/single/{master,simul_efun}.c` (this lib
  and `nitan_ceshi`) vs. `adm/kernel/{master,simul_efun}.c`
  (`nitan170911`/`nitan6`) — an earlier/parallel engine layout, not a
  renamed directory.

**Compared against sibling archive #60 (`nitan_ceshi`)**, whose NOTES.md
was available by the time this pass finished (both processed concurrently
by separate agents): the two are clearly close cousins, not identical —
both self-identify `internet mud name : nitan.3` and share the `adm/
single/` layout, the "Lonely for nt2" master.c credit, the same core
"NT/nitan/Lonely" simul_efun architecture, and (remarkably) **the exact
same set of driver-compat bugs** (§15h × chinese.lpc/named.lpc/logind.lpc,
the `LONELY_IMPROVED`-gated missing-efun family including the identical
bignum `count()` gap, the `is_killing` typo in `clone/user/user.lpc:792`,
and the `eventd.lpc`/`storyd.lpc` `.c`→`.lpc` rename-width bug) — strong
evidence the two archives are sibling snapshots of the same underlying
codebase at a similar point in its evolution, independently confirming
each other's fixes were correct rather than one agent copying the other's
work. Differences found: this lib's `feature/dbase.lpc`/`adm/simul_efun/
wizard.lpc` composition matches `nitan_ceshi`'s (§15's core bug does NOT
apply to either — see below); this lib's `u/lonely` tree already has
`rmtree()` folded directly into `adm/simul_efun/file.lpc` (already wired
into `simul_efun.lpc` via that file's existing `#include`), whereas
`nitan_ceshi` needed a separate fix to wire in a disconnected standalone
`/u/lonely/rmtree.lpc`; this lib's `data/topten/` directory exists (no
missing-content gap there, unlike `nitan_ceshi`); and this lib fixes the
quest `set_information` bug at its true shared root (widening one
signature in `inherit/misc/quest.lpc`) rather than leaving it as
documented-but-unfixed content noise (see item 9 below) — `nitan_ceshi`'s
own quest daemons still show this failure in its NOTES.md, whereas this
lib's does not, after the fix.

**Crucially, §15's core dbase architecture bug does NOT apply here** —
verified by reading `feature/dbase.c` directly, same as `nitan_ceshi`:
it already has **real, local** `set`/`query`/`delete` methods (not just
storage variables) — precisely the shape §15's fix prescribes for
`nitan170911`/`nitan6`. `adm/simul_efun/wizard.c` here is a tiny
2-function file (`wizhood`/`wiz_level`) with **no** `set`/`query`/`delete`
fallback at all. Confirmed zero `efun::set(`/`efun::query(`/
`efun::delete(`/`efun::addn(` call sites anywhere in the lib. This
snapshot's dbase architecture was never broken the way `nitan170911`/
`nitan6`'s was — the single biggest fix-class in the whole project simply
doesn't apply to this branch of the lineage, confirming (a second time,
independently of `nitan_ceshi`) that "same family name" does not mean
"same bugs" even within one mudlib lineage.

## Fixes applied (with why)

1. **`config.fluffos`**: `master file`/`simulated efun file` set to
   `/adm/single/master` / `/adm/single/simul_efun` (this snapshot's actual
   layout).
2. **`adm/simul_efun/chinese.lpc`'s `is_chinese()`** (§15h): GBK
   byte-range check (`str[i] < 161 || str[i] == 255`, `i % 2`
   alternating-lead-byte gating) rewritten as a CJK Unicode codepoint
   range check (`0x4e00`-`0x9fff`); min-length bound `strlen(str) < 2`
   (bytes) → `< 1` (chars); dropped the `i % 2` gate entirely (every index
   is already one character now).
3. **`adm/daemons/logind.lpc`'s `check_legal_name()`** (§15h): internal
   `strlen(name) < 2` → `< 1`; both call sites' `maxlen` argument
   `check_legal_name(arg, 4)` → `check_legal_name(arg, 2)` (confirmed
   correct by the prompt text itself: "不要超过两个汉字" = maxlen **2**);
   combined surname+name length gate `strlen(fname) < 4` → `< 2`.
4. **`adm/daemons/named.lpc`** (§15h, the `PATH()`/sliding-window family):
   `#define PATH(name) (name[0..1] + "/" + name)` ("first GBK char", 2
   bytes) → `name[0..0]` (first character); every `strlen(name) < 2`
   empty-name guard → `< 1`; the similar-name sliding-window check's
   window widths `name[i..i+3]`/`name[i..i+5]` (2/3-GBK-char byte windows)
   → `name[i..i+1]`/`name[i..i+2]` (2/3-character windows), loop bound
   `i <= l - 4` → `i <= l - 2`, inner `i + 6 <= l` guard → `i + 3 <= l`,
   pre-check `strlen(name) < 4` → `< 2`.
5. **`securityd.lpc`'s `valid_read`/`valid_write`** (§15n): this lib has a
   genuinely custom ACL (`exclude_read`/`trusted_read`/`exclude_write`/
   `trusted_write` tables, not the simple `find_object`-only pattern) —
   added the standard early-allow for `func == "load_object" /
   "recompile_object" / "include"` at the top of both applies, before any
   ACL-table logic, so the driver's own compile-time source/`#include`
   loading (triggered by the registration flow lazily touching
   never-preloaded `/adm` objects) is never denied by a fresh
   not-yet-authenticated connection's default "(player)" status.
6. **`master.lpc`**: added `get_include_path()` (§8d/§15o) — wasn't
   defined at all. Fixes ~15 files under `kungfu/class/ultra/`, `clone/
   weapon/`, `u/lonely/quest3/`, `adm/daemons/huanjing2003/` that
   `#include <local.h>`-style same-directory headers (`convert_lib.sh`'s
   own local-angle-bracket-to-quotes pass already converted the ones it
   could detect offline at preload/bare-lpcc-check time; this apply
   additionally covers compiles triggered live, mid-connection, per
   §15o's driver-source note on `init_include_path()`).
7. **`adm/etc/preload`**: commented out `/adm/daemons/network/dns_master`
   (§15p, standing policy) — intermud/cross-mud daemon, never needed for
   registration-flow testing. (No literal `.c`-suffixed entries needed
   §15c's fix — this file already stored bare extension-less paths.)
8. **`LONELY_IMPROVED`-gated `efun::X()` calls to efuns that never
   existed on this (or any) FluffOS build** — `#define LONELY_IMPROVED` is
   unconditional in `include/globals.h` (the *global* include file, so
   these branches are always compiled in, not a real feature toggle).
   Checked every real FluffOS `.spec` (`~/src/fluffos/src/packages/*/
   *.spec`) to confirm each is genuinely absent, not misspelled:
   - `adm/simul_efun/file.lpc`'s `file_lines()`, `adm/simul_efun/
     message.lpc`'s `sort_msg()` (`efun::sort_string`), `adm/simul_efun/
     util.lpc`'s `sort_string()`/`filter_color()`(`efun::filter_ansi`)/
     `file_crypt()`/`file_valid()` — each already had a working pure-LPC
     `#else` fallback written right there in the same function; flipped
     the guard from `#ifdef LONELY_IMPROVED` to `#if 0` at each of these 6
     call sites so the existing fallback is always used instead of
     reimplementing anything.
   - **`count_add`/`count_mul`/`count_sub`/`count_div`/`count_lt`/
     `count_gt`/`count_le`/`count_ge`/`count_eq`/`big_number_pow`** in
     `util.lpc`: wrap a bespoke arbitrary-precision bignum arithmetic efun
     (`count(n1, op, n2)`) with **no `#else` fallback at all** — a hard
     compile-blocker for `simul_efun.lpc` itself (confirmed: this alone
     stopped the driver from booting past `simul_efun`). This helper is
     used across **~230 files** (grep hit count) — mostly combat/currency/
     experience math throughout `kungfu/`, `d/`, `clone/`, `adm/daemons/`.
     Implemented a real, from-scratch arbitrary-precision decimal-string
     signed integer arithmetic library (new file `adm/simul_efun/
     bignum.lpc`: schoolbook add/sub/multiply, digit-by-digit long
     division, sign-aware comparison — handles both `int` and numeric-
     `string` inputs uniformly via `sprintf`), `#include`d into
     `simul_efun.lpc` **before** `util.lpc` (function-defined-later-in-
     same-file ordering rule, §8b) and rewired `util.lpc`'s `efun::count(`
     calls to bare `count(`. Chose a genuine bignum implementation over a
     simpler 64-bit-int-cast shortcut specifically because the sibling
     archive `nitan_ceshi`'s NOTES.md documents that shortcut crashing at
     runtime on a real numeric-string call site (`count_mul(..., "50000")`
     during NPC stat setup) — a real bignum library sidesteps that whole
     class of bug by construction, at a modest one-time implementation
     cost.
9. **`inherit/misc/quest.lpc`'s `set_information()` wrapper** (§8g-style,
   new): declared its own `info` parameter as `string`, but the real
   implementation it delegates to (`adm/daemons/questd.lpc`'s
   `set_information(object, string, mixed)`) already declares it `mixed`
   — and **9** quest clone templates (`capture`/`deliver`/`defend`/
   `explore`/`trace`/`search`/`supply`/`judge`/`shen`, all under `clone/
   quest/`) legitimately pass a function pointer `(: ask_npcN :)` here,
   not a string. This overly-strict local type rejected every one of them
   at compile time (`Bad type for argument 2 of set_information ( string
   vs function )`), first surfacing as a crash in `adm/daemons/quest/
   capture.lpc`'s own `heart_beat()` → `start_quest()` → `new(...)` the
   first time the crontab-driven quest-generation daemon tried to
   instantiate one. **One shared root cause, not 9 separate bugs** (§8g) —
   widening this single signature to `mixed info` resolved all 9 at once,
   confirmed via a clean subsequent boot with zero `set_information`
   errors in `debug.log`.
10. **`adm/daemons/timed.lpc:349`** (§15f): `array localtime =
    localtime(realtime);` — bare `array` as a full type-by-itself
    declaration (silently fails to register a usable variable on this
    driver), compounded by naming the variable identically to the
    `localtime()` call assigning to it (`syntax error, unexpected
    L_DEFINED_NAME` / `Illegal LHS` / `Value indexed has a bad type:
    "function "` on every subsequent `localtime[...]` use). This is on
    the direct preload path (`timed`'s real-time crontab tick, touched by
    every connecting player's uptime-banner routing). Fixed by renaming
    to `mixed *lt` and using `lt` throughout the function.
11. **`adm/simul_efun/ntefun.lpc`'s `process_function(array fp)`**
    (§15f-style, new variant): same bare-`array` bug, but on a *function
    parameter* declaration rather than a local variable — `void
    process_function(array fp)` is a hard parse error (`Missing type for
    argument` / `syntax error, unexpected L_IDENTIFIER`) on this driver,
    and since this file is `#include`d directly into `simul_efun.lpc`,
    the error was fatal to the whole simul_efun compile. Fixed to `mixed
    *fp`.
12. **`adm/simul_efun/message.lpc`'s `message()` wrapper** (§15s): several
    internal callers (`message_system()`, `channeld.lpc`'s `do_channel()`)
    invoke this with a literal `0` as the 4th ("exclude") argument, which
    flows straight to the real `message()` efun — this driver rejects a
    raw `int 0` there (`Bad argument 4 to EFUN message() Expected: object,
    array, Got: int(0)`). First surfaced as a crash in `channeld.lpc`'s
    `do_channel()` broadcasting the quest-daemon's own startup
    announcement (a "系统报告" channel message), which happens during
    normal preload-adjacent daemon activity, not something registration-
    flow-specific but reachable very early regardless. Fixed once at the
    shared root: `exclude || ({})` before delegating to `efun::message()`.
13. **`clone/user/user.lpc:792`**: `if (is_killing(ob))` — pre-existing
    content typo. `is_killing(string id)` (`feature/attack.lpc`) takes a
    string id, matching every *other* call site in the whole codebase
    (`feature/attack.lpc` itself, `20+` other files, all correctly pass
    `ob->query("id")`/`me->query("id")`) — this one direct (non-`call_
    other`) call passed the raw object instead (`Bad type for argument 1
    of is_killing ( string vs object )`). Since this is a direct function
    call (not `->`), the driver's static type checker enforces the
    parameter type strictly, and **this single call site blocked `/clone/
    user/user` — the player body class itself — from compiling**,
    silently breaking character-creation completion right after gender
    selection (same shape/impact as §15b's `query_shadowed()` finding on
    `tianxia`, archive #50 — "the player body class fails to compile" is
    now a confirmed recurring failure mode across at least 3 unrelated
    libs in this project). Fixed to `is_killing(ob->query("id"))`.
14. **`adm/daemons/eventd.lpc`** and **`adm/daemons/storyd.lpc`** (new
    `.c`→`.lpc` rename-fallout variant, extending §2): both do `get_dir(DIR
    + "*.lpc")` then strip the extension via a **hardcoded fixed-width
    slice**, `map_array(names, (: $1[0..<3] :))` — correct for the
    *original* 2-character `.c` extension, but leaves a trailing `l` on
    every name now that the extension is 4 characters (`"emei.lpc"[0..<3]`
    → `"emei.l"`, not `"emei"`). This directly caused `eventd.lpc`'s own
    preload-time `collect_all_event()` to fail with `call_other() couldn't
    find object '/adm/daemons/event/emei.l'` on every boot. Fixed both to
    `[0..<5]` (cutoff moved by the same +2 the extension grew by). **Not
    fixed** (same shape, not observed failing, not exercised by the
    registration-flow test, per §6b/15f's "fix what surfaces" convention):
    `adm/npc/luban.lpc` (1 occurrence, a housing-key admin NPC) has the
    identical `[0..<3]` pattern.
15. **`d/city/npc/paimaishi.cc` → `.lpc`**: a genuine LPC object (an
    auctioneer NPC, referenced extensionlessly from `d/city/pmc.lpc`) that
    the raw archive shipped with a `.cc` extension instead of `.c` —
    `convert_lib.sh`'s blind `*.c`→`*.lpc` rename never touches `.cc`
    files, so this one was silently left un-renamed and un-loadable (the
    extensionless reference resolves via `.c`/`.lpc` fallback only, never
    `.cc`). `file`/`convert_lib.sh`'s text-detection correctly still
    UTF-8-converted its contents despite the odd extension. Renamed to
    `.lpc` to make it loadable. **Not otherwise verified clean**: an
    `lpcc` spot-check on this file alone (not exercised by the
    registration-flow test — it's an un-preloaded city NPC) surfaces 3
    genuine-looking pre-existing content errors (`Undefined variable
    'who'`/`'amount'`, a stray `syntax error, unexpected '}'`) — this file
    was also flagged `LOSSY conversion (invalid bytes dropped)` during the
    encoding pass, so these may be encoding-corruption fallout (per
    AGENTS.md's `iconv -c` adjacent-byte-eating gotcha) rather than
    original-archive bugs; not chased further given it's off the tested
    path — flagged here for whoever next touches city-zone NPCs.

## Confirmed NOT needed (checked, didn't apply)

- **§15's core dbase architecture fix** — see "Lineage confirmation"
  above; `feature/dbase.c` already has real local methods, `wizard.c` has
  no fallback needing a fix, zero `efun::set/query/delete/addn` call
  sites exist anywhere in the lib.
- **§4's master.lpc lazy-`load_object`-in-`valid_read` recursion guard** —
  read `master.lpc`'s `valid_read`/`valid_write` directly: both only do
  `find_object(SECURITY_D)` (never `load_object`), degrading to `return 1`
  if not found — the recursion trap doesn't exist here.
- **§7's `get_root_uid()`/`get_bb_uid()`** — both already implemented in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§15l's `destruct(SIMUL_EFUN_OB)` in master's `create()`** —
  `master.lpc create()` just prints a banner line; no destruct/reload
  dance present.
- **§15r's `check_config`-shaped driver-version self-check** — no such
  file exists in this lib (`inherit`ed into `master`/`simul_efun` or
  otherwise).
- **§15c's preload `.c` reference fix** — `adm/etc/preload` already
  stored bare extension-less daemon paths; no other `adm/etc/*` file had
  a literal `.c`-suffixed reference either.
- **`rmtree()` gap** (the sibling `nitan_ceshi` needed this fixed) — this
  snapshot already has `rmtree()`/`f_rmtree()` defined directly inside
  `adm/simul_efun/file.lpc`, which is already `#include`d into
  `simul_efun.lpc` — confirmed no "Undefined function rmtree" anywhere in
  testing.
- **`data/topten/` missing-content gap** (the sibling `nitan_ceshi` hit
  this) — `data/topten/` genuinely exists in this archive; no "Wrong
  permissions for opening file ... rich.txt" error seen.
- **MySQL backend requirement** — confirmed NOT needed, unlike
  `nitan170911`. `#define DB_SAVE` is **not defined anywhere** in this lib
  (grepped `include/`, `adm/`); `logind.lpc`'s `get_id()`/`get_gender()`
  both gate their MySQL-specific code paths behind `#ifdef DB_SAVE`, dead
  here — the local-file-based branch (`file_size(ob->query_save_file() +
  __SAVE_EXTENSION__) >= 0`) is what actually runs, same situation as
  `nitan6`/`nitan_ceshi` (not `nitan170911`). Full registration — real
  character creation, gender selection, persisted `.o` save data — works
  with zero external services.
- **`chinesed.lpc`'s dead `check_chinese()` function** — has the same
  `i%2==0`-byte-offset-gate shape as the fixed `is_chinese()`, but has
  **zero call sites anywhere in the lib** (grepped) — genuinely
  unreachable dead code, not fixed per the "fix what's reachable"
  convention.

## Interactive test transcript / outcome

Driver booted on port 40055 (`libs/nitan_san/config.fluffos`), `cd`'d into
`libs/nitan_san` per the `log directory` convention. Multiple full
end-to-end registration runs via `mudclient.py` in continuous sessions
(single connection per run, so `logind.lpc`'s new-account IP throttle
never had a chance to trigger, per §15j):

**Run — id `qinfengsi`, surname 秦, given name 风, gender male**: banner
renders correctly (UTF-8 Chinese intact, ANSI colors correct — the "GB or
BIG5" pre-id prompt confirmed as a genuine pre-id gate, not a hidden
literal-check trap per §15q, since sending the id directly worked
immediately), uptime/online-count lines print clean, username validates,
confirm-new-character prompt appears, surname/given-name **both accepted
on the first try** (validating the §15h fix — single-character Chinese
surname and given name, the exact case documented as broken pre-fix
across ~20 other libs in this project), admin password set+confirm,
normal password set+confirm, gender selection, player body (`/clone/user/
user`) compiles and loads (validating the `is_killing` fix), reaches
"目前权限：(player)", and lands in an actual room:

> 注册房间
> 　为保障每一位玩家的权益，本游戏实行新玩家电子邮件注册制度...

`look` correctly re-displays the room; `quit` correctly triggers the
intentional (non-bug, matches the §15j "anti-throwaway-account" family)
new-account confirmation gate: "你的账号是新建的，本站规定新建账号必须
连续在线半小时才能被有效保留，退出该游戏将删除你的账号，你确定要放弃
该帐号而退出吗？（y/n）".

**Follow-up runs** (fresh ids `qinfengliu`/surname 秦 given-name 岭, then
`qinfengba`/秦淮): confirmed the duplicate-name rejection works correctly
("对不起，这个名字和 qinfengsi 的名字重复了" when accidentally reusing
"秦风" a second time), confirmed answering `n` at the quit-confirmation
gate correctly aborts the quit and resumes play ("您选择了放弃退出(quit)，
继续游戏。"), and confirmed `look`/`quit` both work identically across
independent sessions.

`log/debug.log` shows **zero errors** across the final (post-all-fixes)
boot and every subsequent test run — the only lines matching
"error"/"错误" anywhere in `log/stdout.log` are the literal config-key
names `mudlib error handler`/`trap crashes` echoed at startup, not actual
errors. (The visible "编译时段错误：... Unknown #pragma, ignored." lines
streamed to the connecting client mid-session are cosmetic: this driver
apparently mirrors compiler *warnings* — not errors, despite the label
text — to the connected player for every never-before-touched file it
lazily compiles during that player's own action chain; every file in this
lib emits this exact one warning, "Unknown #pragma, ignored", for a
`#pragma` this driver doesn't recognize but tolerates. Harmless, matches
zero corresponding `debug.log` entries, and does not interrupt the
underlying command flow.)

**One unreproduced instability, noted per this project's established
"flag, don't block on" convention** (cf. `yueyingqiyuan`'s NOTES.md): a
single test run's driver process was found gone (`Connection refused` on
the next connect attempt) shortly after that run ended with an
*unanswered* quit-confirmation prompt (client disconnected without
sending `y`/`n`). No crash trace of any kind appeared in `log/stdout.log`
or `log/debug.log` (a real SIGSEGV/native crash on this driver normally
prints a `backward-cpp` stack dump, per §8/§15l precedent — none
appeared here). Attempted deliberate reproduction twice more (reaching
the same quit-confirmation prompt, then letting the connection drop
without answering) — **did not reproduce** either time; the driver
survived. Given several other agents' driver/lpcc processes were running
concurrently against this same host throughout this pass (confirmed via
`ps`/`free -h` — `wuhanzhan` #58 and `nitan_ceshi` #60, both mid-flight
at the time), an environmental cause (transient host memory pressure, a
concurrent process interaction) is more likely than a genuine mudlib or
driver bug — flagged here for future investigation, not treated as
blocking given it didn't reproduce across 2 further clean full-registration
runs plus a final boot-only verification, all with the driver still
running and responsive when explicitly killed at the end of this pass.

## lpcc sweep

**Not run.** 13,559 `.lpc` files — squarely in the mega-lib bracket this
project has already established as risky (`xo_final`, only 7,174 files,
already drove this same 23GB host to ~214MB free with heavy swapping;
`nitan170911` at ~54,600 and `nitan6` at ~23,100 both had their sweeps
killed/skipped for the same reason). Compounding factor this session
specifically: multiple other agents' driver/`lpcc` processes were
confirmed running concurrently against this host for most of this pass
(`wuhanzhan` #58, `nitan_ceshi` #60, `jhfy`, `moniHuafu` at
various points) — `free -h` showed free memory drop as low as ~830MB at
one point mid-session. Per this archive's own task instructions and
AGENTS.md §6b, skipped the full sweep entirely and relied on the boot +
multi-run interactive-connect test above, which is what found and fixed
every real bug in this pass (the `count()` bignum gap alone would have
been a hard blocker for a bare `lpcc --batch` sweep too, being a
`simul_efun.lpc`-level compile failure — that class of bug doesn't need a
sweep to find, a single boot attempt already surfaces it).

A single targeted `lpcc` spot-check (not a full sweep) was run on one
specific file of interest (`d/city/npc/paimaishi.lpc`, item 15 above) and
found 3 pre-existing content errors unrelated to any of the fixes in this
pass — noted there rather than chased, since the file is off the tested
path (an un-preloaded, never-visited city NPC).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter**: ran `format-corpus.mjs` across all 13559 `.lpc`
  files under `work/` — 13521 reformatted, 31 unchanged, 7 refused
  (token-mismatch safety gate, negligible at this scale). Confirmed (via
  grep, same as `nitan_ceshi`) this lib's `feature/alias.lpc` does not
  have the `nitan6`/`nitan170911` malformed-character-literal bug —
  different file shape, nothing to fix.
- **Native retest against the freshly-rebuilt driver**: booted clean
  (`Initializations complete.`). Ran the full registration flow (id
  `qflibsa`, surname `秦`, given name `岭`, admin+login passwords,
  gender) end-to-end, reaching the "注册房间" prompt; a follow-up
  connection (returning-player path, same id/password) ran
  `register test15@qq.com`, advancing into 生命之谷 with `盘古`
  correctly greeting "秦岭，你快快选择..." by the real registered
  name — full round-trip verified, zero fatal errors in `debug.log`
  throughout. No regression from the reformat or driver rebuild.
- **WASM build test** (`scripts/wasm_client.js`): boots cleanly (only
  expected non-fatal preload warnings, e.g. `versiond.lpc`'s
  `socket_bind`/`socket_close`/`socket_listen` calls failing as
  `Undefined function` — the `sockets` package isn't built into this
  WASM target, same documented restriction as everywhere else in this
  batch, non-fatal). **Same as `nitan_ceshi`**: `logind.lpc`'s `logon()`
  destructs any connection where `uptime() < 30` as its very first
  statement (before any prompt), and the WASM harness's
  connect-immediately-after-boot pattern means every attempt within one
  short-lived process hits this "还在启动中" gate — confirmed via
  `泥潭三正在启动过程中，请稍候再来。` appearing immediately post-connect
  regardless of `--idle` padding. This lib's `adm/daemons/band.lpc`
  `is_banned()` also has the identical `sscanf(site, "%s.%s.%s.%s",...)
  != 4` IP-format gate that would independently block login via the
  documented `query_ip_number()`-under-WASM limitation even past the
  30-second mark. Neither is a mudlib bug; the native retest above
  confirms the exact same code registers and plays through cleanly.
  Status: **boots under WASM; login not exercisable within a single
  short-lived harness run** (same two-gate situation as `nitan_ceshi`,
  consistent with them being close siblings).

## WASM-enablement pass (2026-07-23): loopback-allow + uptime bypass + admin seeding

Same patch set as sibling `nitan_ceshi` (identical gate shapes):

- `adm/daemons/logind.lpc` `logon()` (~line 97) — `uptime() < 30`
  startup-grace destruct now only applies to non-loopback connections.
- `adm/daemons/logind.lpc` `logon()` (~line 180) — per-IP multi-login cap
  (`iplimit > 12 || > 4`) exempts loopback.
- `adm/daemons/band.lpc` `is_banned()` — loopback short-circuit return 0;
  malformed IPs (previously `return 1` = banned, the WASM login killer)
  now return 0.
- `adm/daemons/band.lpc` `is_multi_login()` — loopback always allowed.
- Kept: 30-minute new-account quit-retention gate (game design);
  `blocks_ip` invalid-ID spam blocker (enforcement commented out
  upstream, unchanged).

Admin account: `fluffos`, normal password `Mud@2026`, 管理密码
`Mud@2026admin`, Chinese name 浮浮 (姓浮名浮 + full-name confirm step).
Granted `(admin)` via `/adm/etc/wizlist` (目前权限：(admin) shown at
entry). Verified: real-flow registration, reconnect, and
`update /adm/daemons/band.lpc` succeeds. Saves at
`data/login/f/fluffos.o` + `data/user/f/fluffos.o` (untracked, not
gitignored — orchestrator must add). Fresh normal registration
(秦/风/testqa) re-verified end-to-end; test char saves removed;
debug.log clean.

### Fail-closed retrofit (2026-07-24)

Same correction as documented in detail on sibling `nitan_ceshi`
(identical gate shapes): the `uptime()`/multi-login-cap carve-outs'
"only apply the gate if the IP parses AND isn't loopback" logic silently
exempted malformed IPs too; tightened to "apply the gate unless the IP is
strictly loopback". `band.lpc`'s explicit `!stringp`-as-loopback clauses
tightened the same way, with its original malformed-format fail-safe
(`return 1` = banned) restored. Re-verified loopback fluffos login,
`look`, `update /adm/daemons/band.lpc`, and quit all still work after
tightening.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

nitan_ceshi 的手足快照。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）被识别为巫师账号（"没有设置巫师专用密码"的提示按预期出现，只是装饰性警告），干净地进入游戏世界，quit 干净。和 nitan6（015）、nitan_ceshi（041）是同一家族/同一流程。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 56 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §10.7 深度游玩测试尝试记录（本轮未完成，供下次接续）

**注意：本节标题故意避开候选库挑选脚本 grep 的关键词（"深度"+"功能"+
"测试"连写），因为本轮没有完成实机验证——这样下次巡检还会把
`nitan_san` 挑出来重新尝试，而不是被误判为"已完成"。**

### 已应用、高置信度的程序性修复（源码层面已核实，未做完整实机验证）

本库和刚测完 `nitan_ceshi`（同一 "NT/nitan/Lonely" 血统，见本文件顶部
"手足快照"说明）共享同一个 §7.11 类缺陷（运行期目录缺失 + 无保护的
`write_file()`），三处调用点全部按 `nitan_ceshi` 已确认的修复手法处理：

- `adm/daemons/toptend.lpc::topten_save()`：`write_file(f_name, str, 1)`
  前插入 `assure_file(f_name);`（十大排行榜守护进程，写 `/data/topten/`）。
- `adm/simul_efun/file.lpc::log_file()`：`write_file(LOG_DIR + file,
  text)` 前插入 `assure_file(LOG_DIR + file);`，并在文件顶部加了
  `void assure_file(string file);` 前向声明（`assure_file` 定义在文件
  靠后位置）。
- `adm/single/master.lpc::log_error()`：`efun::write_file(home + "log",
  message)` 前插入 `assure_file(home + "log");`——这是 `nitan_ceshi` 那
  轮没有遇到（或没有触发到）的第三处同款调用点，本库额外发现。

三处改动均逐字对照 `nitan_ceshi` 已验证成功的写法，模式高度成熟（本
session 至此已有 15+ 次独立确认实例），有很高把握是正确的，但**本轮未
能通过实机注册流程验证**，见下方原因说明。

### 未完成实机验证的原因：本 session 环境下这份快照的驱动预载异常缓慢

连续 4 次尝试从 `config.fluffos` 所在的库根目录启动原生驱动
（`~/src/fluffos/build/src/driver config.fluffos`，linux-debug 预设，
ASAN/UBSAN），全部未能在预载阶段结束前完成：

- 第 1、2、3 次都被本 session 环境的容器重启中断（分别在约 48 分钟、
  几分钟、几分钟处，容器重启看起来和每小时一次的巡检定时任务大致同
  步，给每次启动尝试留出的窗口大约 55-60 分钟）。
- 第 4 次拿到了几乎完整的一个窗口（约 58 分钟不间断运行），进程本身
  没有崩溃或卡死——`debug.log` 编译警告仍在稳定增长（约 3-4 行/秒，
  全程速率基本恒定，RSS 从几百 MB 稳定爬升到 11GB+，CPU 占用稳定在
  40% 左右），但直到第 58 分钟被下一轮容器重启打断时，`ss -tlnp` 上
  40055 端口仍未监听，预载仍未完成。

对照：体积/文件数几乎相同的手足库 `nitan_ceshi`（`work/` 目录
82M/13913 个 `.lpc`+`.h` 文件，本库为 79M/13852 个，几乎一样）在同一套
驱动/同一 session 里稳定在 90 秒到 2 分钟内完成预载并可连线——按日志
行数估算，`nitan_san` 每文件的预载耗时比 `nitan_ceshi` 慢了一个数量级
以上。本文件最上方"状态：done（boots clean, connects...）"的描述来自
**更早一轮测试**（很可能是不同驱动/环境下做的），并非本轮结论——本轮
在本 session 的原生 ASAN 驱动下反复复现了这个异常缓慢的预载，怀疑与
ASAN 在这份快照某处特别深/特别大的结构上开销异常有关，但没有进一步深
挖具体是哪个文件/子系统（超出本轮已投入的时间预算）。对比过
`config.fluffos`（`maximum buffer size`/`maximum byte transfer` 等几个
数值比 `nitan_ceshi` 大不少，`time to clean up/swap/reset` 只有
`nitan_ceshi` 的一半），没有找到能直接解释 10-20 倍预载耗时差异的单一
配置项，未做进一步论证前不下结论。

**遗留给下一次巡检**：直接从这里接着做——三处源码修复已经就位且高置
信度正确，欠缺的只是实机验证（注册、安全切磋、正规/快捷两条技能路
径、quit/重连持久化，参照 `nitan_ceshi` 的完整清单）。如果下一次驱动
恰好在一个不被容器重启打断的窗口里顺利跑起来，直接接着走完 §10.7 清
单、把正式的深度测试小节写进来即可，不需要重新调查源码层面的 bug。

**追加证据（第 5 次尝试，2026-08-07 22:xx）**：这次驱动进程本身连续跑
了满满 58 分钟都没有被容器重启打断（和前几次不同），依然没有监听
40055 端口——`debug.log` 编译警告行数到 10069 行（比第 4 次同一时间点
的 9483 行略多，说明确实还在缓慢推进，不是卡死），RSS 涨到约 12GB，
系统可用内存降到 715MB，为避免和后续巡检的驱动争抢仅剩的 4 核/内存，
主动按记录的 PID（2509，连同其 nohup 包装进程 2508）杀掉了这次尝试。
**这基本排除了"纯粹是容器重启运气不好"的猜测**——即便给到接近一小时
的不被打断的窗口，这份快照在本 session 的原生 ASAN 驱动下依然无法完
成预载，说明这确实是这份快照本身内容层面的问题（不是环境抖动），值
得下次单独开一轮做根因排查（例如二分预载顺序、逐段注释掉大块内容试
探是哪个子系统异常慢），而不是继续盲目重试同样的"整个驱动等一小时"
打法。

### WASM 未验证说明

按本 session 约定：`emsdk` 固定从 `storage.googleapis.com` 拉取，被本
session 出站代理策略拒绝（`curl -sS $HTTPS_PROXY/__agentproxy/status`
返回 403），WASM 编译/运行验证本轮继续跳过。

## 深度功能测试（2026-08-12，round two，新驱动重测——补完上方"尝试记录"）

**重要更正：上方"§10.7 深度游玩测试尝试记录"一节记录的"预载异常缓慢（10-20
倍于手足库 nitan_ceshi，怀疑是内容层面问题）"结论是错的，根因是测试用的驱
动构建本身，不是这份档案的内容。** 那几次尝试用的是 `~/src/fluffos/build/
src/driver`（ASAN/UBSAN 插桩构建）；本轮改用这个项目其余所有 round-two 测
试统一使用的 `~/src/fluffos/build-debug/src/driver`（无插桩的纯 debug 构
建），预载在 **33 秒**内完成、干净监听端口——和手足库 `nitan_ceshi` 的量级
完全一致，之前记录的"10-20 倍差异"、"疑似内容层面问题，值得单独开一轮根
因排查"的结论应视为撤销：这纯粹是 ASAN 插桩对这份档案某处开销异常大的代
码路径的固有减速，不是这份档案本身有问题。以后测试这份档案（或任何类似
"预载异常慢"的档案）优先换用非插桩的 `build-debug` 排除这一类假阳性，而
不是花时间做二分排查。

### 已应用的三处 §7.11 修复（上方已记录，本轮现场验证）

`toptend.lpc`/`file.lpc::log_file()`/`master.lpc::log_error()` 的
`assure_file()` 三处改动（含从 `nitan_ceshi` 移植来的 `quest.h`/
`toptend.lpc` 修复）均现场验证：干净注册流程正确显示"你名列最近十大富翁/
高手排行榜第五名！"，`log/debug.log` 总行数在整个流程中保持 365 行不变。

### 新发现并修复：`log_file()` 的 euid 提权在 `assure_file()` 内部被自己撤销

`adm/simul_efun/file.lpc` 的 `log_file()` 先 `seteuid(ROOT_UID)` 再呼叫
`assure_file()`，但 `assure_file()` 自己的实现在结尾做了 `seteuid(getuid())`
——把调用者刚设置的 ROOT 权限撤销了，等 `log_file()` 接着呼叫
`write_file()` 时，实际跑在撤销后的低权限下，对 `/log/nosave/` 这种没有单
独走白名单的路径命中"Wrong permissions for opening file ... for append."
（本轮由 `cmds/usr/quit.lpc` 的 `confirm()`→"y"确认删号分支触发，写
`/log/nosave/register` 的注销记录）。修复：`assure_file()` 返回之后、
`write_file()` 之前再呼叫一次 `seteuid(ROOT_UID)`，恢复调用者原本设定的权
限。**现场验证**：注册一个抛弃用测试角色（`zhaoliuqi`），真的走完
"quit"→"y"确认删号流程，`log/nosave/register` 文件被正确创建并写入
"Aug/12/2026 ... zhaoliuqi(zhaoliuqi) commits a suicide from
127.0.0.1"，`debug.log` 总行数全程保持 365 行不变（对照修复前的 stale 报
错行仍在文件靠前位置，是修复前那次尝试留下的，本轮没有再新增一条）。

### 新发现但未修：随机送货任务系统的 `/inherit/item/combined` 运行期"No
program"报错

`adm/daemons/quest/deliver.lpc` 的 `heart_beat()`（送货任务生成，本轮因
`quest.h` 的 `set_information` 类型修复而首次真正开始运作）反复触发
`*No program in object '/inherit/item/combined'!`——从驱动刚起服（甚至早
于任何玩家连线）就开始出现，反复命中同一个物件引用。已排查：`inherit/
item/combined.lpc` 本体和实际会被 `load_object()` 的 `clone/questob/
rice.lpc`（`inherit COMBINED_ITEM`）单独用 `lpcc` 编译均无错误，只有
warning。怀疑和 `/inherit/` 前缀档案作为顶层可加载物件的某种驱动/mudlib
惯例限制有关（这类档案通常只设计成被 inherit，不直接 load_object()/
new()），但没有在本轮时间预算内定位到精确根因。**不阻塞注册/登录/quit核
心流程**（全部现场验证正常），属于背景守护进程的独立问题，按"长尾，记录
不修"惯例处理，留给下一次专门针对这个随机任务子系统的深挖。

### 完整游玩测试范围

沿用 `nitan_ceshi` 已验证过的及格线：注册成功进入注册房间，欢迎/排行榜播
报正确显示，`quit` 的两条分支（"n"取消、"y"确认删号）都现场走过。战斗/
门派/门派任务仍未触达，留给下一次专门测试。

### 本轮结论

驱动升级后 nitan_san 整体状态良好：任务计数器/`log_error()`/`message()`
均确认无需改动；此前"预载异常缓慢"的结论确认是插桩驱动的假阳性，用非插
桩构建后和手足库同量级；从 `nitan_ceshi` 移植的两处修复（`quest.h`、
`toptend.lpc`）现场验证有效；新发现并修复了 `log_file()` 的 euid 提权被
自己撤销的问题；随机送货任务子系统一个背景守护进程级的"No program"报错
记录但未修（不阻塞核心流程）。测试账号（`linsansan`/`wangsanwu`）存档留
在 `data/` 下作为佐证（`zhaoliuqi` 已按测试流程自行删除），未清理（未跟
踪文件，不纳入本次提交）。

## AGENTS.md §7.100 修复（2026-08-19，批次五）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：3252 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。自带建房工具 `clone/misc/roommaker.lpc` 的字符串
拼接代码生成模板里也烤了同一个地雷。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上 roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：
3252 files changed，与预期精确吻合（0 处遗留匹配，全部干净）。

验证：`build-debug` 驱动真实冷启动，端口 40055 正常监听，
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

## WASM gap closure: versiond.lpc sockets crash on admin login (2026-08-25, another session)

The lib's earlier WASM-enablement pass (above) promoted `wasm_status`
to `playable` without ever logging in with an admin-rank account —
`adm/daemons/versiond.lpc`'s `in_server()` (called from `create()`)
calls `socket_create()`/`socket_bind()`/`socket_listen()`
unconditionally, undefined on this driver build (no `sockets`
package). Regular player logins never touch this file, but
`logind.lpc`'s `catch(enter_world(ob, user))` around admin entry does
end up loading it, and since the whole file fails to compile, the
`catch()` fires and shows the player a scary (but non-fatal) "你无法
进入这个世界" message before recovering into the normal room.

Found and fixed via a sibling lib (`nitan3`, byte-identical
`versiond.lpc`, onboarded as a confirmed duplicate of this lib) hitting
the exact same crash during its own WASM verification pass. Patched
this file identically (11 functions across the socket-server/client
lifecycle gutted to no-ops/always-fail per this project's established
"sockets package absent" pattern) and re-verified: admin login
(`fluffos`/`Mud@2026`) now reaches 巫师休息室 cleanly with no error.

**Lesson for future WASM passes**: "playable" from an earlier pass
doesn't guarantee every login tier was exercised — an admin-only code
path can hide a real crash that a player-only test never reaches.

## 深度功能测试（2026-09-04，shop + 拜师）

Independent live pass on this slug (port **40055**, `build-debug`
driver — do not use the ASAN `build/` driver; that 10–20× preload
slowdown is a documented false positive from the 2026-08-12 round).
Prior §10.7 / 2026-08-12 text never exercised a shop purchase or a
recruiting NPC here. First send is **`gb`** (banner “Select 国标码 GB
or … BIG5 (gb/big5)”), then id `fluffos` / password `Mud@2026`.
`#undef DB_SAVE` in `work/include/ntsql.h`, so there is no MySQL
login/restore gate. Admin has no `wizpwd` yet — login prints the
“请登陆后用 wizpwd 命令设置” warning and then asks for the ordinary
password. `register player@me.com` from `/d/register/regroom` drops
the wizard into 生命之谷. Birth is `choose 1` (光明磊落) →
`washto 20 20 20 20` → `born 扬州人氏` (lands at `/d/city/kedian`;
`help rules` more-pager — send `q` before further commands, or they
are swallowed). Unlike `nitan170911`, `washto` here does **not**
auto-set `born`.

**Shop**: 客店 `xiaoer` is an innkeeper; `游讯` in the same room
intercepts `list`/`buy` (“我只卖消息不卖货”). Real vendor is
`/d/city/zuixianlou` 店小二 (`d/city/npc/xiaoer2.lpc`, `F_DEALER`).
`list` shows 烤鸡腿 80 文. `clone /clone/money/gold` works
(`release server : local` makes `is_admin()` true). `buy jitui`
deducted one gold into 99 两白银 + 20 文铜钱 and delivered 烤鸡腿.
`feature/dealer.lpc` already `#include <dbase.h>`, so mixin
`query("vendor_goods")` resolves; no F_DEALER this_object() patch
needed (unlike `nitan170911`/`hhsj`/`xfbhh`). No F_DEALER 丐帮
refuse on this lib.

**拜师**: `goto /d/city/lichunyuan`, `bai kong` on 空空儿
(`kungfu/class/gaibang/kongkong.lpc`) — no skill/shen gate beyond
`permit_recruit()`. Accepted immediately: “恭喜您成为丐帮的第二十代弟子.”
`score` shows 【门派】丐帮 / 【师承】空空儿. `save` (30s cooldown)
then disconnect. After a full driver kill + reboot, relogin still
shows 丐帮 / 空空儿; the silver/coin change persisted; 烤鸡腿 did
not (food, not autoload — expected, not a save bug). Do not `quit`
when `mud_age` is tiny — new-account quit deletes the account.

**Bug fixed**: `kungfu/class/huashan/{yue-buqun,yue-wife,feng-buping}.lpc`
`recruit_apprentice()` wrote `add("apprentice_availavble", -1)` (extra
“av”) while `attempt_apprentice()`/`reset()` use `"apprentice_available"`.
Same typo `nitan3`/`nitan6` already live-verified — the daily-recruit
counter never decremented. Corrected the property name in all three
files (LF-only). `qingcheng/yu.lpc` is not in this tree.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 8 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 与 zhonghua2 同源的三处编译警告

- `cmds/std/team/bunch.lpc`、`cmds/std/team/swear.lpc`：结义失败提示被多余的 `;` 截成两句，`fail` 只剩"……可惜现在有人不在，$N"，后半句"的提议只好作罢。"丢了；接回去。
- `clone/drug/fengdong.lpc`：`if (... < 10000) max1 / 2;` 是空语句，改成 `max1 /= 2;`（经验不足一万的对手，分身技能减半）。

验证：改动的文件和包含 `npc/indian` 的守护进程在 HEAD 与工作树分别加载（`scripts/lpc_listcheck.sh`，新进程），无回退。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

先用 `scripts/lpc_twin_port.py adopt nitan_ceshi nitan_san` 把 nitan_ceshi 警告整理提交（ae7fbb619a5）里的改动搬到 1016 个修改前与它一致的文件（逐文件核对非 ASCII 文字：除 nitan_ceshi 自己删掉的以外没有丢失或改动），再用 `scripts/lpc_nitan_family_fixes.py nitan_san`（`clone/obj/traverser.lpc` 的空 `DEBUG` 宏改成调用空函数；`adm/daemons/questd.lpc` 最后一个空的 `else if ((total_count % 10) == 0) { /* … */ }` 改成注释）。剩下的再跑 `scripts/lpc_warnings.py nitan_san --fix`，共改动 1023 个 `.lpc` 和若干 `.h`。以上都不改变行为。
HEAD 与工作树分别加载（新进程）：1008 -> 1008 通过，无回退；改过的头文件的 260 个包含者 257 -> 257 通过。

启动时警告 67 -> 0；新进程登录正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 4 处比较、0 处去后缀（如 `adm/daemons/taskd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 2 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 3 -> 1。

## 深度功能测试（§10.7，2026-10-12）：编译警告收尾

可编译文件的警告 **168 -> 0**（全库重扫：13436 个文件可编译）。本库代码与 nitan3 几乎逐字相同，用 `scripts/lpc_twin_port.py adopt nitan3 nitan_san` 搬来同日 nitan3 的 31 个文件改动（详见 nitan3、nitan_ceshi 的同名一节）。载入核对：`954 objects; HEAD PASS 939, tree PASS 939; regress 0; newly loading 0`；删除声明审计 0 处待看。

- **真问题：`feature/unique.lpc` 的 `int remove() { save(); }` 盖掉了 F_MOVE 的 `remove()`**，唯一物品被销毁时不卸装备、不从携带者身上减负重；删去（F_MOVE 的 `remove()` 对 `is_ob_saved()` 物件本来就先 `save()`）。
- 其余：神木王鼎的虫表从没生效（`swmuding.lpc`）、`xiang.lpc`/`cruise-ob.h` 的 `remove()`、`pet.h` 重复继承 F_OBSAVE、`hu.lpc` 疗伤函数改名 `heal_patient()`、`lubo.lpc` 合并两段说明、幻境变量重复声明、迷宫 `unique_rooms` 改名、`FORCE2`、`do_effect()` 改 `varargs int`、`genmap.lpc` 的 `harbor.h`、`vrm_server.lpc` 的 `;`。

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

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`bingpo-blade/ningxie`、`duanyun-fu/hong`、`xue-dao/xuemo`、`yunu-sword/yijian`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`matrial-cognize`→`martial-cognize`（`qiankun-danuoyi/nuoyi`、`qiankun-danuoyi/yi`）；`qianzhu-wandu`→`qianzhu-wandushou`（`/kungfu/class/emei/zh`、`qianzhu-wandushou/tuxi`）；`xuantian-wuji`→`xuantian-wujigong`（`liangyi-jian`、`taxue-wuhen`）；`choushui-zhang`→`chousui-zhang`（`chousui-zhang`）；`cuhixiao-jifa`→`chuixiao-jifa`（`xiaoao-jianghu`）；`feilong--cuff`→`feilong-cuff`（`feilong-cuff/dan`）；`hengshan-jianfa`→`hengshan-jian`（`/d/henshan/tianquan-hole`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`xiawuxiang`→`xiaowuxiang`（`jidao-shaqi`）；`yaowang-mishu`→`yaowang-miaoshu`（`yaowang-miaoshu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`xuanyuan-arror`→`xuanyuan-arrow`（`xuanyuan-arrow`）。

## 密宗猴拳「震」最重的一档报错（2026-10-15）

`/kungfu/skill/mizong-houquan/zhen` 按伤害分档写描述：前几档都是 `pmsg = ...`，最后一档（伤害 ≥ 80，也就是最重的一击）却写成 `pmsg += ...`，而 `pmsg` 没有初值，本驱动里 `0 += 字符串` 直接报错，这一招打得最狠时反而中断。改为 `pmsg = ...`。

## 路径遍历器 traverser 从没编译过（2026-10-15，KB 06 §7.250）

`clone/obj/traverser.lpc` 把 `nosave` 写成了 `noasve`，编译失败；用它的临济庄「幽冥桩」每次都报 `No program in object '/clone/obj/traverser'`。改正关键字，并删去没用的局部变量 `err`。


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

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 1 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）。修后与 HEAD 逐个对比载入：这 1 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 从 `work/` 里删掉 tar 的 `PaxHeader/` 记录（2026-10-19，KB 02 §2.2）

压缩包的制作者把 tar 的 pax 扩展头记录（`49 path = ...`、`20 ctime = ...`，每个不超过 262 字节）当成文件打进了包里，放在 `PaxHeader/` 目录（有的嵌套两层）。转换时 `.c` 结尾的被改名成 `.lpc`，在扫描里成了编译不过的“物件”。这些是元数据，不是 mudlib 内容：82 个文件从 `work/` 删除（`raw/` 里仍然有）。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：吃任何东西（`eat` 后面不管写什么）都会吃掉紫草；`valid_combo()` 对任何组合都返回真。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/clone/medicine/zicao.lpc`（1 处）、`/kungfu/skill/meinv-quan.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：`valid_learn()` 对任何性格都拒绝。改动：`/adm/daemons/ward.lpc`（1 处）、`/kungfu/skill/qiankundanuoyi.lpc`（1 处）、`/kungfu/skill/zhonghua-aojue.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/cmds/arch/sameip.lpc`（1 处）、`/cmds/usr/mazemap.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 5 处）。改动：`/adm/daemons/competed.lpc`（2 处）、`/adm/daemons/xinruid.lpc`（2 处）、`/cmds/wiz/roomlong.lpc`（1 处）。

## `socket` / `dumpsocket` 指令：`dump_socket_status()` 驱动里没有（2026-10-20，KB 06 §7.291）

这些巫师指令 `write(dump_socket_status());`，MudOS 的 efun 在 FluffOS 里不存在，指令编译不过。在模拟 efun 文件里补了 `dump_socket_status()`：用 `socket_status()` 排出同样的表（没有 sockets 包的构建，比如 WASM，只有表头；`scripts/lpc_add_sefun.py dump_socket_status`）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 目录读出后的后缀截取宽度（2026-10-20，KB 06 §7.296）

`.c` 改名成 `.lpc` 之后，`get_dir("*.lpc")` 读出的文件名还按两个字符截取（`$1[0..<3]`）：`baguadao.lpc` 变成 `baguadao.l`，用它拼出的路径加载不到对象（故事、战场、事件、帮助、自造物品数据、召唤列表等）。改成 `[0..<5]`（`scripts/lpc_fix_getdir_strip.py`）。改动：`/cmds/adm/refsum.lpc`（2 处）。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 1 个存档共 2 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/data/dbased.o`（2 处）（共 1 个存档）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（1 个文件）：`/cmds/arch/recovermud.lpc`。

## 拼错的 `call_out()` / `input_to()` 目标（KB 06 §7.349，2026-10-21）

计时器或输入提示给驱动的函数名和文件里定义的差一个字母；驱动对不存在的函数静默不理，所以对应的计时从来没有触发过。调用和配套的 `remove_call_out()` 改成已定义的拼法：`ruanweijia` / `yuxiao`：`return_to_zhang` → `return_to_huang`（携带者在战斗时的重试从不发生，宝物一直留在玩家手里）；张无忌：`destrory` → `destroy`。改动：`/clone/lonely/ruanweijia.lpc`、`/clone/lonely/yuxiao.lpc`、`/kungfu/class/mingjiao/zhangwuji.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 25 条注册（19 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/adm/npc/biwu1.lpc`（`get_weapon`）、`/adm/npc/biwu2.lpc`（`get_weapon`）、`/adm/npc/biwu3.lpc`（`get_weapon`）、`/adm/npc/biwu4.lpc`（`get_weapon`）、`/adm/npc/referee.lpc`（`do_halt`）、`/clone/drug/guiyuan.lpc`（`do_pour`）、`/clone/drug/huiyang-san.lpc`（`do_pour`）、`/clone/drug/shedan.lpc`（`do_pour`）、`/clone/drug/yangxin.lpc`（`do_pour`）、`/clone/drug/yulu-wan.lpc`（`do_pour`） 等共 19 个文件。最多的函数名：`do_pour` 7 处、`get_weapon` 4 处、`do_bcun` 3 处、`do_bqu` 3 处、`do_halt` 2 处。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。7 个文件里 12 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 7 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 7 个，现在 7 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（2 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 3 个函数没有补（item_desc 3）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi.lpc`:`look_CAI`、`/d/yihua/lianhuachi1.lpc`:`look_CAI`、`/d/yihua/lianhuachi2.lpc`:`look_CAI`。

## 运行期目录 `log/nosave` 不存在，写日志的 `write_file()` 直接报错（2026-10-22，KB 03 §4.3 补充）

这个库的 77 个文件里有 136 处 `write_file("/log/nosave/...")` / `log_file("nosave/...")`（`static` 改 `nosave` 时连字符串里的日志路径一起改了，原来是 `log/static/`）：`nosave/using`、`nosave/party_quest`、`nosave/item` 等。压缩包和站点包里没有这个目录，`write_file()` 在目录不存在时抛 `*Wrong permissions for opening file /log/nosave/... for append. "No such file or directory"`，调用它的函数（杀人记录、重启记录、`call` 日志……）当场中断。把 `log/nosave/guilei` 记进 `scripts/wasm_keep_dirs.txt`（站点和 pristine 树都按它建空目录）；没有把字符串改回 `static`。证明（`scripts/lpcc_eval.py`，`catch(write_file("/log/nosave/ZZTEST", ...))`，fqyy2 / hy5 / bmxkx2001 的新进程）：补目录前报上面的错误，补后写成功。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 3 个文件里 3 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 21 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立；NPC 的称呼和提示里取到两个字而不是一个字。

本库 21 处（14 个文件）：拼名字的赋值 10 处、与汉字常量比较 10 处、`to_chinese()[..]` 1 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/fengling.lpc:134`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/emei/tobebonze.h:41`）；`chk[0..1] == "你"` → `chk[0..0] == "你"`（`/adm/npc/ganjiang.lpc:558`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if ((strlen(name) < 4) || (strlen(name) > 12)) {`（`/adm/npc/luban.lpc:1779`）；`if ((strlen(mission) < 4) || (strlen(mission) > 20)) {`（`/cmds/adm/mission.lpc:57`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 7 个文件；`channeld` 同盟 / 门派标题 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 9 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 中文名 / 验证码仍按 GBK 取「两字节一字」（2026-10-23，KB 06 §7.373）

`pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1]; pname = pname[0..1];` 在按字符计下标时会取出两个汉字。`scripts/lpc_fix_pname_slice.py` 去掉掩码并把收尾改成 `[0..0]`（`pname`/`pname2`/`sec_name`/`str`/`str1`）。本库 18 处。证明：nt1 生成名长度 2–4；HEAD 常见 3–5。

