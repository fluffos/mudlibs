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
