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
other libs in this project (`weimingkongjian` #55, `nitan_ceshi` #60).
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
(`wuhanzhan` #58, `nitan_ceshi` #60, `jianghufengyun`, `moniHuafu` at
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
