# 神州 (shenzhou) — archive #72

## What this is

`archives/神州.rar`, root nested two levels deep at `raw/sznew/sznew/`
(the outer `sznew/` directory is just the archive's top-level wrapper, the
real mudlib root is `sznew/sznew/`). `bin/config.sz`'s own `name :` field
decodes (GB18030) to **`【 神州 】`** — the game's own self-identified name
matches the archive title exactly ("神州" = "Divine Land/Land of the
Gods"), no slug divergence to note. The bundled `readme.txt` (author
unclear, dated Nov 2002) describes it as "a very messy mudlib... according
to Hxsd it's ShenZhou" and complains about wizards leaving junk under `/u`
— an accurate warning: this archive has an unusually large number of
personal wizard sandbox directories (`u/<name>/`) with duplicate/backup
copies of core files, dead experiments, and stray content, on top of the
live game tree.

**Lineage**: `adm/single/master.c`'s header comment traces the full
"ES II" engine chain explicitly — `// for ES II mudlib`, `// original from
Lil`, `// rewritten by Annihilator (11/07/94)`, `// modified by Xiang for
XKX (12/15/95)`, `// modified by Xuy for XKX (08/21/97)` — the same
lineage already seen on es1_win/esI/xkx2001/rzrmud/xo/bmxkx2001/
kxkj/yueyingqiyuan/wuhanzhan/haiyang2/yanhuangwuhun/
yhyxs/xuanjianlu. Layout is `adm/single/{master,simul_efun}`
+ `adm/daemons/*` + `adm/simul_efun/*` (fragments `#include`d into
`simul_efun.c`), matching that whole family. A further ShenZhou-specific
layer was added on top by a "Karlopex@sz" (site admin, credited in several
comments dated 06/03/2002) and "sdong"/"buwu" (earlier maintainers, dated
1998) — this looks like a multi-generation fork rather than a fresh ES II
checkout.

Size: 14,497 raw files, 12,740 `.lpc`/`.c` files after conversion (86MB) —
a normal-sized lib for this project, not a mega-lib; the full
`lpcc_check.sh` sweep ran twice without any memory pressure (peaked at
~1.6GB RSS on the `lpcc` process, host had 8-19GB free throughout both
runs).

## Fixes applied (and why)

### Standard/catalog fixes, applied proactively before first boot

1. **AGENTS.md §15h** (`is_chinese`/`check_legal_name` GBK byte-range bug
   — nearly universal): `adm/simul_efun/chinese.lpc`'s `is_chinese(str)`
   was `strlen(str)>=2 && str[i] >= 161 && str[i] != 255 && (i%2==0 implies
   str[i] in 176..247)` (a GBK lead/trail-byte range check, always false
   against UTF-8 codepoints) → replaced with `strlen(str)>=1 && str[i] >=
   0x4e00 && str[i] <= 0x9fff` (CJK Unified Ideographs codepoint range,
   checked per character, no byte-parity gating). `adm/daemons/
   logind.lpc`'s `check_legal_name(name, ob)`: bound `(strlen(name) < 2)
   || (strlen(name) > 8) || i%2` (byte-count bound + meaningless parity
   check) → `(strlen(name) < 1) || (strlen(name) > 4)` — the message text
   already said "必须是 1 到 4 个中文字" (1 to 4 Chinese characters), so
   halving 2/8→1/4 matches what the message always promised, not a guess.
   Its sliding-window loop `if( j%2==0 && !is_chinese(name[j..j+1]) ) {
   name[j]+=128; name[j+1]+=128; }` (a GBK/BIG5 byte-shift "auto-correct"
   hack with no valid meaning against Unicode codepoints, per §15h item 4)
   → `if( !is_chinese(name[j..j]) ) { <reject>; }`, using the reject
   message text the original author had already written but left
   commented out. Verified via 2 independent full registration tests
   (below) that real Chinese names ("秦风", "林风") are accepted.

2. **AGENTS.md §15p** (DNS/intermud daemon preload exclusion): `adm/etc/
   preload` listed `/adm/daemons/network/dns_master` — removed
   proactively before the first boot attempt (along with a dead
   `/adm/daemons/network/https` entry pointing at a file that doesn't
   exist anywhere in the archive — harmless either way, but cleaned up
   for tidiness). Also checked §15ab's "inline DNS call outside preload"
   variant: `cmds/usr/mudlist.c`'s `main()` does call `DNS_MASTER->
   query_muds()`, but it's guarded by its own `find_object(DNS_MASTER)`
   check first and degrades to a harmless `notify_fail()` when not
   loaded — confirmed safe by inspection (this command is never invoked
   during boot or the registration flow itself) and by zero related
   errors across every boot+test cycle.

3. **AGENTS.md §14** (`valid_override` 3-arg upgrade): `master.lpc`'s
   `valid_override(file, name)` was 2-arg — upgraded to `(file, name,
   main_file)`, added `main_file == SIMUL_EFUN_OB || main_file ==
   MASTER_OB` to the allow-check, so an `efun::` override written inside
   a file `#include`d into `simul_efun.lpc`/`master.lpc` (this lib has
   several: `chinese.lpc`, `message.lpc`, `object.lpc`, etc, all
   `#include`d into `adm/single/simul_efun.lpc`) is still recognized as
   legitimate.

4. **AGENTS.md §8d/§15o** (`get_include_path()` insurance): `master.lpc`
   had no `get_include_path()` apply at all — added the standard
   directory-prepending implementation as insurance for any live,
   mid-connection compile using a local (same-directory) `#include`.
   Pure insurance; not needed to unblock the observed boot/registration
   path itself (see "confirmed not needed" below), but free and matches
   the established per-lib checklist.

5. **AGENTS.md §15ae** (`private nomask` command-hook, the newest catalog
   entry, standing policy for this session) — **checked proactively and
   found present**: `feature/command.lpc` declares `private nomask int
   command_hook(string arg)`, inherited into the player body and
   registered via `add_action("command_hook", "", 1)` in `enable_player()`.
   Exactly the pattern that broke every post-login command with zero
   visible error on `xuanjianlu` (#70) and retroactively on
   `bmxkx2001` (#45). Fixed by dropping `private` (kept
   `nomask`) BEFORE the first boot attempt, then verified with a real
   post-login `look`/`score`/`i`/`quit` sequence (see transcript below) —
   this is exactly the check the task's standing policy requires, and it
   would have silently broken this lib's entire gameplay loop if skipped.

6. **AGENTS.md §8e** (`tail` is not a real FluffOS efun) — **fatal here**:
   `adm/simul_efun/message.lpc`'s `tail(string file)` called
   `efun::tail(file)`; since this file is `#include`d directly into
   `adm/single/simul_efun.lpc`, the compile error (`Unknown efun: tail`)
   would take down the entire simul_efun object and the boot with it.
   Reimplemented in plain LPC (read file, split on `\n`, take the last 10
   lines, write them). A second, non-fatal instance survives in
   `cmds/wiz/tail.lpc`/`cmds/imm/checkgx.lpc`, but those call the bare
   (now-fixed) simul_efun `tail()`, not `efun::tail()` directly, so no
   further change was needed there. A THIRD instance also exists at
   `u/karlopex/backup/adm/simul_efun/message.lpc` — confirmed this is a
   stale personal backup copy of the pre-fix file under a wizard's own
   `u/karlopex/backup/` sandbox, never loaded by anything else (not the
   live `/adm/simul_efun/message` the real `simul_efun.lpc` `#include`s) —
   left as-is, it only shows up as `lpcc`-sweep noise.

7. **AGENTS.md §15s** (`message()` 4th-arg int-0 rejection): `adm/
   simul_efun/message.lpc`'s `tell_room(ob, str, exclude)` passed a bare
   `exclude` (defaults to `int 0` when called in the common 2-arg form)
   straight through as `message()`'s 4th argument, which this driver's
   `message()` efun (typed `void | object | object *`) rejects when given
   explicitly. Fixed with `exclude || ({})`.

### New finding this pass — NOT yet in AGENTS.md's catalog

8. **A `log_error()` compile-warning handler unconditionally calling
   `wizardp(this_player(1))`, which lazily `load_object()`s the security
   daemon mid-compile — a fatal boot crash on the very first preloaded
   daemon, on every fresh boot, before this fix.** This is a new,
   specific manifestation of the §4/§15w family worth its own catalog
   note.

   `master.lpc`'s `log_error(string file, string message)`:
   ```lpc
   if(wizardp(this_player(1))&&(strsrch(message,"Warning:")==-1))
       efun::write("编译时段错误：" + message+"\n");
   ```
   Two compounding bugs:
   - **(a)** `wizardp(this_player(1))` was called **unconditionally**,
     even when `this_player(1)` is `0` (there is no player at all during
     preload). `wizardp()` (`adm/simul_efun/wizard.lpc`) does
     `SECURITY_D->get_wiz_level(ob)` — an ordinary `call_other`, which
     lazily `load_object()`s `securityd` the first time anything invokes
     it. Since this driver funnels compile **warnings** through
     `log_error()` too (§15w — confirmed here: `/feature/treemap.lpc:2:
     warning: Unknown #pragma, ignored` is what triggered it), and the
     very FIRST preloaded daemon (`storyd`, which pulls in `feature/
     dbase` → `feature/treemap`) fires this warning before `securityd`
     (later in `adm/etc/preload`) has ever loaded, `SECURITY_D->
     get_wiz_level()`'s lazy load attempt threw `*Object cannot be loaded
     during compilation.` — on EVERY boot, unconditionally, before any
     daemon finished preloading. Because this error itself then escalated
     to `master.lpc`'s `error_handler()`, which ALSO does an unguarded
     `new(CHANNEL_D)` (another mid-compile object instantiation, since
     `channeld` hadn't loaded yet either at this point in the preload
     order), the driver printed a further `Error in mudlib error
     handler:` cascade. This did **not** infinite-loop (unlike §4's
     `valid_read`/`valid_write` shape) since `error_handler()` isn't
     re-entered a second time for its own secondary failure, so the boot
     did NOT hang or crash outright — but it produced boot-time noise
     and, more importantly, would recur (with the same crash-and-cascade
     shape) for literally any compile warning anywhere, at any time
     post-boot too, since `SECURITY_D`/`CHANNEL_D` being loaded by the
     time of a LATER warning is not guaranteed either.
   - **(b)** `strsrch(message,"Warning:")` (capital W) never matches this
     driver's actual lowercase `warning:` prefix, so the intended
     warning-suppression (skip broadcasting warnings, only broadcast real
     errors) never fired at all — every single compile warning would have
     been broadcast to any connected wizard as if it were a serious
     runtime bug, compounding §15w's usual noise problem.

   **Fix**: guard `wizardp(this_player(1))` behind `this_player(1) &&`
   (skip the whole wizard-hood check — and so the lazy `securityd` load —
   when there's no player at all, which covers every preload-time
   warning), and fixed the case-sensitive `"Warning:"` check to
   `strsrch(lower_case(message), "warning:")`. Also hardened `master.lpc`'s
   `error_handler()` itself as cheap insurance (matching §4/§15w's spirit):
   wrapped its `new(CHANNEL_D)`/`do_channel()`/`destruct()` sequence in a
   `catch { }` block, and added a permanent `efun::write_file("/log/
   RUNTIME_ERRORS", ...)` write before that, so a real runtime error is
   never silently lost even if `CHANNEL_D` happens to be unavailable when
   it fires. **Found and fixed BEFORE the first real driver boot** (via
   `lpcc` compiling `/adm/single/simul_efun` in isolation first, per the
   pipeline's step 5) — confirmed by re-running the same `lpcc` compile
   after the fix: the crash cascade is gone, `storyd`'s warning is now
   silently absorbed as intended, and the real driver boot afterward
   produced a completely clean `log/debug.log` (zero `cannot`/`denied`/
   `crash`/`fatal` hits) across the whole session, including two full
   registration flows.

9. **AGENTS.md §15n** (custom `securityd.lpc` ACL blocking the driver's
   own mid-connection compiles) — **checked proactively and found
   present**: `adm/daemons/securityd.lpc`'s `valid_read()` is a genuine
   custom ACL (`exclude_read`/`trusted_read` mappings keyed by directory
   and wizard-status, not just a `find_object()`-only stub), and only
   allowed `func == "file_size"/"stat"` early — missing the
   `load_object`/`recompile_object`/`include` allowance. Added
   proactively before the first boot, since a fresh unauthenticated
   connection's default `(player)` status would otherwise deny the FIRST
   never-preloaded `/adm` or `/cmds` object the registration flow happens
   to lazily touch. (Its `valid_write` counterpart already had a
   suf­ficiently permissive shape and needed no change.)

10. **§3 counterexample, wide blast radius (52 files)**: `convert_lib.sh`'s
    blanket `\bstatic\b`→`nosave` sed rewrote every `log_file("static/
    XXX", ...)`/`"/static/XXX"` path-literal reference (this lib logs
    extensively to a real `log/static/` seed directory — crash logs,
    read/write-denial audit logs, promotion logs, editor-session logs,
    etc.) to `"nosave/XXX"`, silently orphaning that real directory.
    Found via `grep -rlas '"nosave/\|"/nosave/'` (52 files hit — `master.
    lpc`, `securityd.lpc`, `message.lpc`, and 49 further `cmds/`/`d/`/
    `kungfu/`/`u/`-tree files) and reverted with a targeted `sed -i
    's/nosave\//static\//g'` scoped to just those 52 files (safe: the
    bare keyword `nosave`/`static` never appears immediately followed by
    a `/` anywhere else in this lib, confirmed by re-checking for zero
    remaining `"nosave/` hits after the revert). Also confirmed the
    physical `log/static/` seed directory (containing `CRASHES.lpc`,
    `LASTCRASH`, `CALL_PLAYER.lpc`, etc — already renamed `.c`→`.lpc` by
    the same blanket rename, consistent with what `log_file()`'s own
    `+ ".lpc"` suffix now expects) is intact and untouched.

### Content-level fixes found via the `lpcc_check.sh` sweep (genuine bugs, not sweep artifacts)

11. **`is_killing(who)` type mismatch (object vs the declared `string
    id`)** — the same class of copy-paste bug already catalogued (§15b's
    `nitan_ceshi`/`yhyxs` findings): `feature/attack.lpc`
    declares `varargs int is_killing(string id)` and every correct call
    site does `is_killing(ob->query("id"))`, but 5 files (all clearly
    copy-pasted from one template, sharing the exact same line/dialogue
    text) call `is_killing(who)` with a raw object instead:
    `clone/npc/guidao.lpc`, `clone/npc/guidaobak.lpc`,
    `d/city/npc/guidao.lpc`, `d/shaolin/npc/chengkun.lpc`,
    `d/shaolin/shaolin/npc/chengkun.lpc`. Since this driver's static type
    checker enforces the declared parameter type strictly on a *direct*
    (non-`->`) call, all 5 failed to compile entirely. Fixed by changing
    each to `is_killing(who->query("id"))`. (These are individual NPC
    files, not the player-body class — unlike `tianxia`'s/`nitan_ceshi`'s
    finding, this did NOT block character creation; found purely via the
    `lpcc` sweep, not via any interactive-test crash.)

12. **A genuinely corrupted stale save file crashing `create()`** (§15m
    shape): `clone/obj/genmap.lpc`/`clone/obj/mapdb.lpc` (an
    auto-generated NPC-map cache feature, share one save file,
    `/data/npc/map`) both threw `*restore_object(): Illegal mapping
    format while restoring map.` — confirmed this was NOT reachable
    during the real boot + 2 full registration/post-login sessions
    (zero hits for "genmap"/"mapdb"/"Illegal mapping" in `log/debug.log`)
    — this feature is never preloaded and never touched by ordinary
    registration/play, so it's an `lpcc`-sweep-only finding, not a live
    boot defect. Fixed anyway (cheap, matches precedent): moved the
    stale `data/npc/map.o` aside to `map.o.stale-corrupted-orig` so
    `restore()` finds nothing (not an error) and `create()`'s own
    fallback (`if (!restore()) save();`) produces a fresh file instead.
    Re-verified clean via `lpcc` afterward.

13. **Two dead pure-ASCII-art zone maps mistakenly caught by the blanket
    `.c`→`.lpc` rename** (§12 pattern): `d/mingjiao/map_mingjiao.c` (a
    "明教地图"/Ming-Cult-zone box-drawing map, zero LPC code) and
    `d/hangzhou/hangzhou.c` (a "杭州"/Hangzhou-zone map, likewise zero
    code) — confirmed via `grep -rl` that nothing else in the whole tree
    references either by name. Renamed to `.txt`/`.txt.mapart`
    respectively so the sweep's pass/fail signal stays meaningful for
    files that actually matter.

14. **Pre-existing single-byte GBK corruption + missing closing quote,
    confirmed present in the RAW archive itself (not introduced by our
    conversion)** — found in `d/shenlong/sea.lpc`/`sea2.lpc`: a
    `message("vision", "...");` call had a garbled mid-string segment
    ("不傻米呓豢矗词") ending in an unclosed string literal before a `+`.
    Root-caused by direct raw-byte inspection of the pre-conversion
    archive (`d/shenlong/sea.c`): the raw GBK bytes contain 3 genuine
    Private-Use-Area-mapped characters (U+E3DD, U+E0EF, U+E139 once
    decoded under `gb18030`, matching the `xo_final`/"mohe-zhi.lpc"
    precedent) immediately followed by an isolated, non-GBK-pairable
    byte `0xc7` sitting directly before the closing `"` — this exact
    byte is ALREADY malformed in the raw archive (confirmed: decoding the
    raw bytes with Python's `gb18030` codec fails at that exact byte,
    independent of any tool of ours), and `convert_lib.sh`'s `iconv -c`
    lossy-recovery pass ate that byte's would-be-partner AND the
    adjacent closing quote together (the exact `iconv -c`
    adjacent-real-byte-loss pitfall documented in AGENTS.md's Encoding
    section). A THIRD, uncorrupted sibling copy of this exact same
    message (`d/shenlong/jushi.lpc`, appearing twice) confirmed the
    original, undamaged phrasing — "你发现一个浑身水淋淋的家伙被海水冲
    上岸来，不由得走近一看，原来是" — which was used to restore
    `sea.lpc`/`sea2.lpc` to match exactly (not a guess: cross-confirmed
    against live, working sibling content in the same zone, same author).
    All 3 files ALSO used an old-MudOS-era **octal byte escape**
    (`"\241\243"`, meaning "raw GBK bytes 0xA1 0xA3" under the ORIGINAL
    byte-oriented driver — which happen to form "。", the full-width
    Chinese period) to represent one character instead of embedding it
    directly; under this driver's UTF-8-native strings, decoding those 2
    raw byte-escape values as if they were 2 separate codepoints does not
    form valid UTF-8, producing `error: Invalid UTF8 codepoint in string
    literal`. Fixed by replacing the `\241\243` escape with the literal
    `。` character in all 3 files (`sea.lpc`, `sea2.lpc`, `jushi.lpc`).
    **New pattern worth flagging for AGENTS.md**: an old-MudOS-era octal
    escape sequence (`\NNN\NNN`) inside a string literal, meant to
    represent raw GBK/BIG5 bytes for one Chinese character under a
    byte-oriented driver, is invalid UTF-8 once evaluated by this
    UTF-8-native driver and must be replaced with the literal character
    it was meant to produce — grep for `\\[0-7]{3}\\[0-7]{3}` inside
    string literals as a proactive check on any new lib (only 3 files
    affected here, all in the same `d/shenlong/` zone, presumably
    authored/edited together).

15. **A single missing-shared-header cascade (§8g variant, 7 files at
    once)**: `d/zhongnan/npc/move_file/{ma,liu,zhao,tan,hao,wang,sun}.lpc`
    all did `#include "auto_perform.h"` (quoted, relative) but the real
    header lives one directory UP, at `d/zhongnan/npc/auto_perform.h` —
    quoted includes search the including file's own directory first,
    then the configured include path, but never an ancestor directory,
    so all 7 failed identically with `Cannot #include auto_perform.h`.
    Fixed by copying the existing (generic, author-credited) header
    verbatim into `d/zhongnan/npc/move_file/auto_perform.h` — not
    fabricated content, just duplicating a real header into the one
    additional location quoted-include resolution actually needs.
    Resolved all 7 failures in one shot.

16. **Stale absolute-path prefix leftover from the original server's own
    mount point** (2 files): `d/kunlun/obj/guzheng.lpc` did `#include
    "/shenzhou/d/kunlun/obj/flute.h"` and `u/comfort/comfort_work.lpc`
    had a data-mapping value `"yz" : "/shenzhou/d/city/kedian.lpc"` —
    both referencing a `/shenzhou/` absolute-path prefix that doesn't
    exist in our mudlib root at all (our mudlib root doesn't nest a
    `shenzhou/` subdirectory; this must be a leftover from however the
    original site's own filesystem was laid out, e.g. `/shenzhou/` was
    literally their mudlib's real absolute mount point on the original
    server, baked into a couple of hardcoded paths by mistake). Both
    real target files (`flute.h`, `kedian.lpc`) exist at the equivalent
    path with the `/shenzhou` prefix simply dropped — fixed both
    occurrences (confirmed via `grep -rlas '/shenzhou/'` that these were
    the ONLY 2 occurrences anywhere in the whole lib).

17. **Pre-existing single-byte GBK corruption merging a string literal
    across a line break** (a distinct instance from #14, same general
    shape): `d/changbai/damk.lpc` had `"...地对洞\n                "了
    出去。\n"` — confirmed via raw-byte inspection of the pre-conversion
    archive that the ORIGINAL archive already has a malformed
    (non-decodable even under `gb18030`) byte sitting between "洞" and
    the string's closing quote, predating our conversion entirely (the
    raw file already shows a `U+FFFD`-shaped replacement artifact at
    that exact position when decoded permissively). Fixed by merging the
    two line fragments into one properly-closed string literal on a
    single line, dropping just the one corrupted byte, preserving every
    other character exactly.

## What I confirmed was NOT needed (and how)

- **§4 (master's lazy security-daemon `load_object` recursion)**: grepped
  `master.lpc` for `load_object` — zero hits. `valid_write`/`valid_read`
  only ever use `find_object(SECURITY_D)`, never a lazy `load_object()`,
  so the recursion-via-repeated-failed-load shape (§4's specific
  crash-to-stack-overflow signature) cannot occur here. (The DIFFERENT,
  new §4-shaped bug that WAS present — item 8 above, via `log_error()`'s
  `wizardp()` call — is a distinct code path master.lpc's own valid_read/
  valid_write don't share.)
- **§7 (missing `get_root_uid()`/`get_bb_uid()`)**: both present in
  `master.lpc` (`get_root_uid()`→`ROOT_UID`, `get_bb_uid()`→
  `BACKBONE_UID`), confirmed by reading the file directly.
- **§8f (bare `TYPE * name1, name2;` comma-list array-modifier bug)**: not
  checked exhaustively line-by-line, but no such symptom (`Bad assignment
  (TYPE vs TYPE *)`) appeared anywhere in either full `lpcc` sweep or the
  real boot/registration test.
- **§15f (bare `array name;` declaration)**: `grep -rEn '^\s*array\s+
  [a-zA-Z_]+\s*(=|;)'` across the whole `work/` tree returned zero hits.
- **§15l (master's `create()` destructing `SIMUL_EFUN_OB`)**: `master.
  lpc`'s `create()` is a one-line `write("master: loaded
  successfully.\n");` — no `destruct()` call anywhere in it.
- **§15r (`check_config.lpc`-style driver-version self-check)**: no file
  matching that name/shape exists in this lib, and neither `master.lpc`
  nor `simul_efun.lpc` `inherit`/`#include` anything resembling it.
- **§15u (dormant "phone-home license check" in `securityd.lpc`)**:
  read through the whole 775-line `securityd.lpc` — no function doing
  mass deletion, `shutdown()`, or anything resembling an anti-piracy
  gate; this ACL is purely read/write/cmd permission bookkeeping.
- **§15v (`LONELY_IMPROVED`-style always-on flag gating dead `efun::X()`
  calls)**: `adm/simul_efun/util.c`/`file.c` DO have this exact shape
  (`#ifdef DOING_IMPROVED ... efun::sort_string/filter_ansi/file_crypt/
  file_valid/file_lines ... #else <real pure-LPC implementation> #endif`)
  — but `DOING_IMPROVED` is never `#define`d anywhere in this archive
  (confirmed via `grep -rn "DOING_IMPROVED"`, only 1 hit: the `#ifdef`
  itself), so the `#else` branch (a real, working pure-LPC
  implementation the original author already wrote) is what actually
  compiles. Zero fix needed — dead branch, confirmed via source read
  before assuming it needed the same restoration work as `nitan_ceshi`/
  `nitan_san`'s bignum-efun finding.
- **§15x (hardcoded `MUD_PORT` mismatch)**: `master.lpc`'s `connect()`
  apply does not check any port constant at all (just
  `catch(login_ob = new(LOGIN_OB))`) — confirmed via source read, no
  hardcoded port gate exists to mismatch in the first place.
- **§15z (`#define nosave static`/`#define protected static` shim
  colliding with the blanket sed)**: `grep -rn "#define nosave\|#define
  protected"` across `include/*.h` returned zero hits — this lib has no
  such compatibility shim.
- **The core §15 "simul_efun-based generic set/query/delete, `this_object()`
  is the simul_efun object during a bare simul_efun call" architecture
  bug (nitan/Lonely-lineage-specific)**: confirmed `feature/dbase.lpc`
  already defines real, local `set`/`query`/`delete`/`add` methods (not
  just a storage variable) — the standard, architecturally-correct ES II
  pattern, not the nitan-family footgun. Confirmed by reading
  `feature/dbase.lpc` directly rather than assuming from the lib's size/
  vintage.
- **`SAVE_EXTENSION` bare-macro gap (§15ac)**: this lib `#define`s its
  OWN `SAVE_EXTENSION ".o"` in `include/globals.h` (self-consistent, does
  not rely on the driver's autogenerated `__SAVE_EXTENSION__` at all) —
  confirmed via grep, no fix needed.
- **A hidden pre-id prompt / client-version gate (§15q)**: read the
  actual `logon()` → `confirm_big5` → `get_id` → `confirm_id` → `get_name`
  callback chain in full before scripting the registration test. The
  BIG5 prompt (`"Are you using BIG5 font(Y/N)?"`) is a genuine, simple
  either-way branch (any non-"y"/"yes" input defaults to `"GB"`, no
  rejection path at all) — not a disguised client-version literal check
  like `xyzx3`'s finding. No hidden gate found.
- **Anti-flood registration throttle (§15j)**: grepped for
  `IsTimeAllowed`/`NewIps`-shaped throttles — none found; ran two full
  independent registration sessions back-to-back from the same driver
  process with no rejection.

## Registration flow + post-login command verification

Read the actual `adm/daemons/logind.lpc` `get_id`/`confirm_id`/
`get_name`/`new_password`/`confirm_password`/`check_password`/
`confirm_check_password`/`select_gift`/`get_gift`/`get_email`/
`get_gender` callback chain before scripting the test. Full flow for a
brand-new character: BIG5 y/n → English id (3-8 lowercase letters,
`new`-keyword-free — any unused id goes straight to character creation,
`confirm_id` y/n) → Chinese name → use-password (min 5 chars, entered
twice) → a SEPARATE 保密密码/"security/recovery password" (min 10 chars,
entered twice — used for password-recovery, not the login password
itself) → a gift/attribute-point selection (`0`-`4`, `0` = fully random)
→ accept-the-rolled-gift (y/n) → email address (`id@domain` format
required) → gender (m/f) → `enter_world()`.

**Driver boot**: `cd libs/shenzhou && setsid nohup
~/src/fluffos/build-debug/src/driver config.fluffos & disown` (via the
Bash tool's own `run_in_background`) → `Accepting telnet connections on
0.0.0.0:40066.` / `Initializations complete.` with **zero** errors of any
kind in the preload log (after the log_error/wizardp fix — before it,
every single boot crashed/spammed on the very first preloaded daemon,
`storyd`).

**Registration test 1** (`mudclient.py`, one continuous connection):
```
--send "n" --send "qinfeng" --send "y" --send "秦风"
--send "mypassword1" --send "mypassword1"
--send "checkpassword1234" --send "checkpassword1234"
--send "0" --send "y" --send "test@test.com" --send "m"
--send "look" --send "score" --send "quit"
```
Result: BIG5 prompt → GB accepted; id "qinfeng" accepted; character
creation confirmed; Chinese name "秦风" accepted (proves the §15h fix
works — this is the single most important check per the standing
policy); use-password/security-password both set; gift rolled
(膂力24/悟性16/根骨20/身法18/剩余22), accepted; email accepted; gender
male → **entered the actual game world** ("新手的殿堂"/Hall of Newbies,
full room description + exits `down`/`enter`/`xkd`). `look` re-displayed
the room correctly. **`score` displayed the full character status sheet**
(身份卡: age, gender, birth-time, sect, attributes, HP/qi/food/water/
potential bars, kill/death counts, faction/property/residence/job/level/
income fields) — this is the definitive proof the `command_hook` fix
(§15ae) actually works, since `score` is dispatched through the exact
`add_action`-bound `command_hook` this task's standing policy warns
about. `quit` produced a clean "你丢下一件布衣...欢迎下次再来！" farewell.
**Zero errors of any kind in `log/debug.log`** across this entire session.

**Registration test 2** (independent, same continuous-connection
discipline, different name/gender to also check dup-name handling isn't
accidentally triggered and a second gender path works):
```
--send "n" --send "linfeng" --send "y" --send "林风"
--send "mypassword1" --send "mypassword1"
--send "checkpassword1234" --send "checkpassword1234"
--send "0" --send "y" --send "test2@test.com" --send "f"
--send "i" --send "quit"
```
Result: identical flow, female gender accepted, entered the same starting
room ("新手的殿堂"). **`i` (inventory) command** — another
`command_hook`-dispatched command, distinct from `look`/`score` — listed
real starting items (布衣/Cloth, 乾坤地图/Newbie maps, 林风的锦囊/a
name-personalized pouch, confirming the character's own name correctly
threads through generated item descriptions). `quit` again clean.
**Zero errors of any kind in `log/debug.log`** across this second session
too (cumulative debug.log after both sessions: 598 lines, no `error`/
`denied`/`cannot`/`bad argument`/`undefined` hits at all).

Driver killed by exact PID (`kill <pid>`) after testing completed — not a
pattern-match kill (other agents had concurrent driver processes running
on other ports at the time; confirmed by `cwd`/listening-port before
touching anything).

## `lpcc_check.sh` sweep

Ran twice (once before the content-level fixes in items 11-17 above, once
after, to get an accurate final number). Final: **12,481 / 12,742 pass
(97.95%)**, up from 12,459/12,740 (97.79%) before the second pass's
fixes — net +22 passes from ~20 files' worth of fixes (a few fixes
resolved multiple files at once: the `auto_perform.h` header copy alone
resolved 7).

**Remaining 261 failures, triaged by category (spot-checked a
representative sample of each, cross-referenced against the real boot's
completely clean `debug.log` to confirm none of these are live bugs)**:
- **`#include`-only fragment files compiled standalone** (§6b's
  documented false-positive category) — the majority of the
  `Undefined variable`/`Undefined function set|query|delete|
  perform_action|map_skill|...` failures. Spot-checked `p/fystreet/
  outdoor_func.lpc` (called from `p/fystreet/street100.lpc` etc. via
  `#include "outdoor_func.lpc"`) and `clone/obj/npc_setup.lpc`
  (`#include`d the same way from several `d/*/npc/*.lpc` files) —
  confirmed both are fragments, never loaded standalone, and zero
  related errors appear anywhere in the real boot's `debug.log`.
- **Orphaned plain-text log/help/data files caught by the blanket
  `.c`→`.lpc` rename** (§12's exact pattern) — ~20 files, all under
  `log/`, `u/*/tmp/`, or genuinely misnamed (`u/gateopen/reame` — a typo
  for "readme"), flagged as `Illegal character` since they're prose text,
  not code. None of these are ever `load_object()`'d.
- **The already-known-orphaned `ftp/family/clone/obj/job/*` subtree**
  (see "Orphaned content" below) — confirmed zero references anywhere
  else in the lib, contributes a chunk of both the `Illegal character`
  and `syntax error` categories.
- **Genuinely-missing legacy network/intermud daemon headers**
  (`uid.h`, `net/socket_err.h`, `mailer.h`, `post.h`, `priv.h`) in
  `adm/daemons/network/{pingd,telnetd,socket,pingtcp,userid,mail_serv,
  ms,netmail}.lpc` and their `u/karlopex/backup/` duplicates — none of
  these are in `adm/etc/preload`, none are reachable from the
  registration flow, and the headers genuinely don't exist anywhere in
  this archive (confirmed via `find -iname`). Consistent with §13's
  "archive shipped without this content" pattern — this whole
  intermud-service layer looks like it was never fully bundled with this
  particular snapshot. Not fabricated/fixed.
- **A handful of personal wizard-sandbox files with their own
  independent, pre-existing content bugs** (e.g. `u/felix/shaolin/
  jingmo.lpc`: a genuine unbalanced-parenthesis typo,
  `sp = ((...)*105/100;` missing a `)`) — confirmed not referenced by
  anything else in the live tree (a different, correct file with the
  same base name exists elsewhere: `kungfu/skill/yizhi-chan/jingmo.lpc`).
  Left as-is per the project's established practice of not deep-diving
  into every wizard's personal, non-live sandbox content.

## Orphaned/known content gaps (not fixed, documented per §13)

- **`ftp/family/clone/obj/job/*`** (a "job"/family-crafting subsystem, ~15
  files under `.h`/`.c`): confirmed via `grep -rl "ftp/family"` that
  NOTHING else in the entire lib references this subtree — it looks like
  a separate feature package that was uploaded to an `ftp/` staging area
  but never actually wired into the live game (no `inherit`, `#include`,
  or `load_object` pointing at it from anywhere in `d/`, `cmds/`,
  `feature/`, or `adm/`). A few of its files also failed to fully
  GB18030-decode during conversion (`convert_lib.sh` logged them as
  `FAILED to convert` — left as raw bytes, harmless since nothing loads
  them). Not fabricated/completed — out of scope per this project's
  "don't complete missing content" convention.
- **Legacy network/intermud service layer** (see sweep triage above) —
  the archive's `adm/daemons/network/` directory has files referencing
  headers (`uid.h`, `mailer.h`, `post.h`, `priv.h`, `net/socket_err.h`)
  that don't exist anywhere in the archive at all. This whole layer
  (mail server, ping service, telnet gateway, user-id lookup) appears to
  have been stripped from this particular snapshot, consistent with
  §13's "core/skeleton release, missing content" pattern. None of it is
  in `adm/etc/preload` or reachable from registration/normal play.

## Config

`config.fluffos`: port **40066**, `mudlib directory` → `libs/shenzhou/
work` (absolute), `master file` → `/adm/single/master`, `simulated efun
file` → `/adm/single/simul_efun`, `log directory` → `/log` (resolved
relative to the driver's CWD per §6 — `libs/shenzhou/log/`, driver always
launched via `cd libs/shenzhou && ... driver config.fluffos`). Converted
from the original `bin/config.sz` (GB18030→UTF-8 done FIRST per §5,
before any other edit) — original `name`/`default fail message`/`default
error message` fields carried over unchanged (`【 神州 】` / `什么？` /
`你发现事情不大对了，但是又说不上来。`). A second nearly-identical
original config, `bin/config.sz2`, existed with slightly larger resource
limits (`external_port_1` style port directive instead of `port number`,
larger array/mapping/string-length caps) — `config.sz` was used as the
base since it uses the plain `port number` directive this driver reads
directly; the resource-limit deltas between the two originals are minor
and not consequential for this environment.

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** applied across all 12,742 `.lpc` files in `work/`:
   `{"total":12742,"written":12597,"wouldChange":0,"unchanged":89,
   "errors":56}`. Checked for the `copy(::fn())`-adjacent formatter bug
   found elsewhere this pass (see `tianxia/NOTES.md` for the full
   writeup) — zero hits of the broken `(: :` signature anywhere in this
   lib's reformatted tree. `feature/command.lpc`'s `command_hook` is
   still plain `nomask`.
2. **Native re-test against the rebuilt `build-debug/src/driver`**:
   booted clean (zero fatal errors). Full registration verified
   end-to-end via `mudclient.py` (this lib asks a BIG5-font Y/N question
   before the ID prompt, has a separate ≥10-character "保密密码"
   recovery-password step in addition to the normal login password, and
   caps Chinese names at 4 characters — all discovered by iterating the
   flow live rather than assumed): id `szfmte` → confirm → real Chinese
   name **`秦风戊`** → login password ×2 → recovery password ×2 →
   attribute roll (`0`/random) → accept → email `abc@abc.com` → gender
   `m` → entered the game world at 新手的殿堂, `look`/`score`/`i`/`quit`
   all producing correct real output (character sheet stats matched the
   just-rolled attributes). `debug.log`: zero `error in error
   handler`/`denied`/`undefined function`/`bad argument` lines. No new
   fixes needed.
3. **WASM test**: boots cleanly with **zero** `Undefined function`/
   `denied`/`Bad argument` lines anywhere (this lib apparently doesn't
   preload any socket/db-dependent daemon that would hit the
   no-sockets-package wasm restriction). **Full registration completed
   successfully under wasm**, same flow as the native test above,
   through to `look`/`quit` producing correct real output at 新手的殿堂.
   This lib has **no IP-format-dependent login gate**, so — like
   `sjpl2` — it is **fully playable under wasm**, one of the
   best wasm results in this batch.

## WASM-enablement pass (2026-07-24)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback-allow** (empty/non-string/`127.*` IP treated as loopback):
   - `adm/daemons/logind.lpc` `logon()` — `BAN_D->is_banned()` gate and
     the `iplimit > 20` same-IP online cap skipped for loopback.
   - `adm/daemons/logind.lpc` `get_id()` — `REGBAN_D->is_banned()`
     registration-ban gate skipped for loopback.
   - `adm/daemons/securityd.lpc` `valid_wiz_login()` — wizard logins
     from loopback always allowed (otherwise a wizard id absent from
     `wiz_sites` is refused outright: "请从登记的地址使用巫师帐号").
   - `adm/daemons/band.lpc` + `adm/daemons/regband.lpc` `is_banned()` —
     loopback/localhost/malformed sites never banned.
2. **Uptime gate**: none present. **Other throttles**: none beyond the
   above.
3. **Admin seeded**: `fluffos` / `Mud@2026` / 浮浮 → `(admin)` via
   `data/securityd.o` (`wiz_status` + `wiz_sites` `".*"` + `wiz_renwus`;
   CRLF file, edited binary-safe). Registration also required the lib's
   separate >=10-char recovery password: `Recovery@2026`. Save files:
   `work/data/login/f/fluffos.o`, `work/data/user/f/fluffos.o` (data/
   not gitignored). Verified: `update /cmds/usr/score` → 成功 with the
   system-wide update announcement.
4. Retest: fresh registration (szqfa/秦风, deleted after test) into
   新手的殿堂 with look/score/quit OK; debug.log completely free of
   runtime errors.

### Retrofit: fail-closed loopback check (2026-07-24)

The loopback-allow gates above were originally written per the (now
superseded) defensive instruction to also treat an empty/non-string/
malformed `query_ip_number()` result as loopback, since older WASM
driver builds returned garbage. That driver bug is now fixed upstream
(`query_ip_number()`/`resolve()` return real values under WASM too), so
the "malformed IP = trust it" fallback was a fail-open bypass with no
remaining justification. Tightened every gate listed above to the
strict pattern: loopback is ONLY `ip == "127.0.0.1"`, `ip == "::1"`, or
a leading `"127."` prefix — a non-string/empty/malformed IP is now
treated as untrusted/remote and subject to the gate normally, not
silently allowed through. Retested: fluffos login (127.0.0.1, real
value under the current driver) still passes every gate; debug.log
stayed clean of `denied`/`undefined function`/`error in error handler`.

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib (every prior pass verified only
registration + `look`/`score`/`quit` + admin login, never real exploration/
combat/sect/net-dead). Read `doc/help/newbie` in full first — it names the
`down`/`enter` choice out of 新手的殿堂, the chat channels, `fight` (safe
sparring — "双方都不会打死对方") vs `kill`, `bai`/`xue`/`cha` for
sect-join and skill learning, and the wimpy/death mechanics, matching
§10.7's prediction that it's the fastest way to learn the intended path.
Confirmed the two bugs AGENTS.md §7.10 already documents for this exact
lib (log_error()'s broken-case `"Warning:"` gate and its unconditional
`wizardp(this_player(1))` lazy-securityd-load crash, both in
`adm/single/master.lpc`'s `log_error()`) are **still correctly fixed**
from the earlier pass — read the current code directly (see excerpt
below), did not re-diagnose as new.

**Test character** (kept, representative playthrough evidence): id
`qinfengw`, Chinese name 秦风武 (male), password `Wuxia2026`, security/
recovery password `Recovery2026zz`. State: rolled gift attributes (膂力
21/悟性20/根骨21/身法22), explored from 新手的殿堂 → 客店 (down) →
北集市 → 东大街 → 中央广场, sparred `流氓头` via `fight` (safe — the
match self-terminated once qi dropped below the documented ~50%
threshold, no death, +1 exp), attempted `bai`/`xue` against 流氓头
(correctly rejected — he belongs to no sect), attempted a shop purchase
at the 鲜花店 flower shop (correctly rejected — new character starts
with 0 cash), survived a clean `quit` → real ~2-minute wait → relogin
with location/stats/exp intact, and survived a genuine unclean
(net-dead) disconnect → prompt relogin with location/stats intact.
Saves: `work/data/user/q/qinfengw.o`, `work/data/login/q/qinfengw.o`.
Two throwaway characters used to reproduce/diagnose Bug 1 below were
also left in place as evidence rather than risk clobbering the repro:
`hemuzhi`/何目之 (the very first character that hit the crash, still
sitting in a stale pre-fix netdead state from that session — harmless,
a future login just re-authenticates normally) and `cezhice`/策之测
(used to confirm the SECOND symptom — a permanently-broken board object
crashing every subsequent `look` for the rest of that boot, before the
fix). All three passwords `Wuxia2026`.

### Bug 1 (matches AGENTS.md §7.25's "closely related shape", not a new class): an unguarded companion-board force-load in `d/city/kedian.lpc`'s `create()` let one raw-GBK save file crash the city's central hub room's first-ever visit each boot — and PERMANENTLY corrupted the board object for the rest of that boot, breaking `look` for every player in that room, not just the first visitor

**Files: `work/feature/save.lpc`'s `restore()` (the fix); root-caused
data at `work/data/board/kedian_b.o`; triggering unguarded call site at
`d/city/kedian.lpc:71` (`"/clone/board/kedian_b"->foo();`), one of 71
structurally-identical `"/clone/board/<id>"->foo()`/`->"???"()`
force-load call sites across the lib's rooms.**

- **How this was found**: `down` from the newbie hall (新手的殿堂) is
  the FIRST real move any new player makes per `doc/help/newbie`'s own
  instructions ("如果你...很熟...请键入down"), landing in `/d/city/kedian`
  (客店), the game's central hub. On a cold boot, the very first `down`
  a fresh registration completed with hard-failed: the player saw the
  driver's default "error" message (`你发现事情不大对了，可是又说不上
  来。`) instead of moving, and — far worse — every subsequent typed
  command (`look`, movement, etc.) in that SAME room then failed with
  the driver's default "unrecognized command" message (`什么？`) for the
  rest of that session, looking exactly like the command dispatcher
  itself had silently broken (the §8.3 symptom shape), even though
  `command_hook` itself was completely healthy.
- **Root cause (data)**: `data/board/kedian_b.o` — the shipped save file
  for 客店's message board — was never converted from GB18030 to UTF-8
  by the original conversion pass (an AGENTS.md §4.1-class gap: "plain-
  text `.o` save data are all GBK" — this is the one file in the whole
  lib that slipped through; confirmed via a full-tree scan that all
  other 128 `.o` files under `work/` decode as valid UTF-8, only this
  one didn't). `restore_object()` on this driver throws
  `*restore_object(): Invalid utf8 string while restoring dbase.` on
  invalid UTF-8 instead of silently degrading.
- **Root cause (code, the part that turns one bad data file into a
  crash)**: `d/city/kedian.lpc`'s `create()` ends with an UNGUARDED
  `"/clone/board/kedian_b"->foo();` — a force-load idiom (`foo` isn't a
  real method; the call's only purpose is to trigger the object's
  compile/`create()` as a side effect of `call_other()` resolving the
  reference) with no `catch()`. `kedian_b.lpc`'s own `create()` does
  `set_name(...); set("location",...); set("board_id",...);
  set("long",...); setup();` — and `setup()` (`inherit/misc/bboard.lpc`)
  calls `restore()`, which throws on this file. The throw is uncaught
  all the way up: `bboard.lpc setup()` → `kedian_b.lpc create()` →
  `kedian.lpc create()` (aborting the room's own `create()` before its
  trailing statements) → the `move()`/`go.lpc main()`/`command_hook()`
  call chain that triggered the whole compile in the first place — this
  is EXACTLY the "closely related shape" AGENTS.md §7.25 already
  describes ("rooms that force-load a companion object (commonly a
  message board) via `call_other(\"<path>\", \"???\")` in their own
  `create()`... same fix (`catch()` around the call)") — the only
  difference from §7.25's literal wording is the failure mode (corrupt
  save data throwing inside `restore()`, vs. a missing/uncompilable
  file), the shape and the fix are identical, so this is filed as §7.25,
  not drafted as a new class.
- **Second-order effect, worse than the initial crash and specific to
  this data-corruption flavor of the bug**: `restore_object()` doesn't
  just fail cleanly on the bad file — per AGENTS.md §7.7's documented
  general mechanic ("`restore_object(file)` without flag 1 ZEROES every
  global variable absent from the save file"), the failed restore
  attempt wipes the `dbase` mapping backing ALL of `kedian_b`'s
  properties, INCLUDING the ones `create()` had already legitimately
  set via `set_name()`/`set()` a few lines earlier in the SAME
  `create()` call (`name`, `id`, `location`, `board_id`, `long`) — so
  `query("id")` on the object permanently returns `0` for the rest of
  the boot. Confirmed live with a second throwaway character
  (`cezhice`): the room's own `look` (which renders the board's
  one-line summary via `bboard.lpc short()` → `feature/name.lpc short()`
  → `capitalize(query("id"))`) then crashed on EVERY subsequent visit
  to 客店 by ANY player for the rest of that boot with `*Bad argument 1
  to capitalize() Expected: string Got: 0`, not just the first — this
  is a strictly worse blast radius than AGENTS.md §7.17/§7.19/§7.22/
  §7.25's usual "first-visit-only" framing, because the crashed object
  stays resident in memory in its broken state rather than getting a
  clean retry on the next load.
- **Fix, two parts**:
  1. **Root data fix**: converted `data/board/kedian_b.o` from GB18030
     to UTF-8 with `iconv` (confirmed the whole file decodes cleanly as
     GB18030 with zero loss — this is exactly a missed conversion, not
     genuinely-corrupted bytes) — this restores the REAL board post
     history (14 posts, real author names/messages) instead of losing
     it, and is what actually makes `down` succeed cleanly on a fresh
     boot again. Also normalized the save file's header comment
     (`#/inherit/misc/bboard.c` → `.lpc`) to match every other data
     file's already-renamed convention (cosmetic, harmless either way,
     just consistency).
  2. **Structural insurance, `feature/save.lpc`'s `restore()`**
     (matches §7.25's own stated fix pattern — `catch()` around the
     risky call — applied at the single shared choke point instead of
     the 71 individual call sites, since `restore()` is what actually
     throws):
     ```lpc
     // BEFORE:
     int restore() {
       string file;
       if (stringp(file = this_object()->query_save_file()))
         return restore_object(file);
       return 0;
     }
     // AFTER:
     int restore() {
       string file;
       int ret;
       if (stringp(file = this_object()->query_save_file())) {
         catch(ret = restore_object(file));
         return ret;
       }
       return 0;
     }
     ```
     This makes ANY future corrupted save file (board, or anything else
     that inherits this same `feature/save.lpc` helper) degrade to
     "restore failed, return 0" — the same as a genuinely-missing file
     already does, and the same fallback several callers (e.g. the
     already-documented `clone/obj/genmap.lpc` `if (!restore())
     save();` pattern) already rely on — instead of crashing the whole
     calling chain and potentially corrupting the object's own
     already-set state. It does NOT recover data from a bad file (that
     needs the data-level fix above); it only stops a bad file from
     taking the room/board down with it.
- **Verified**: killed and restarted the driver (fresh boot, so the
  fix's code AND the fixed data file are both picked up — LPC objects
  don't recompile from disk edits without a restart). Fresh character
  `qinfengw`/秦风武: `down` now succeeds cleanly on the very first visit,
  `look` shows the board with its real recovered content
  (`客店留言板(Board) [ 14 张留言，14 张未读，1 篇回复未读 ]`), and
  `look`/`score`/`i` all work normally afterward. `debug.log` for that
  whole session: zero `error`/`denied`/`Bad argument`/`Undefined`/
  `cannot`/`Fatal` hits. Also spot-checked the other 70 force-load call
  sites are the same idiom (not individually re-tested live — the fix
  is at the shared `restore()` choke point, so it protects all of them
  uniformly; only `kedian_b` had corrupted data to actually exercise the
  path).
- **Lineage scope**: `feature/save.lpc` and the `"/clone/board/<id>"->
  foo()` force-load idiom are ES II-family conventions (AGENTS.md §11's
  ES II mega-family, which `shenzhou` belongs to) — worth a proactive
  grep (`"/clone/board/[a-zA-Z0-9_]*"->foo\(\)` or `->"???"\(\)`) on any
  sibling lib doing a deep pass, though the SPECIFIC trigger here (one
  missed-conversion save file) is lib-specific, not necessarily present
  elsewhere.

### Confirmed working, no fix needed

- **§7.10's two documented fixes, re-verified present and correct**:
  `adm/single/master.lpc`'s `log_error()` guards `wizardp(this_player(1))`
  behind `this_player(1) &&` (no crash from a preload-time compile
  warning with no player context) and checks
  `strsrch(lower_case(message), "warning:")` (lowercase-normalized, so
  the intended warning-suppression actually fires). Read the live file
  directly rather than trusting NOTES.md's earlier claim.
- **Safe sparring (`fight`)**: `doc/help/newbie`'s own description
  ("较量（fight）...双方都不会打死对方...当任何一方的气或精跌到50%或
  以下...便会停下来") matches live behavior exactly — `fight liu`
  against 流氓头 (a generic NPC using the unmodified base
  `inherit/char/npc.lpc accept_fight()`, confirmed via grep that this
  NPC has no local override) ran several exchanges, self-terminated once
  qi dropped to ~17%, no death, character gained 1 exp. This is a
  content/design mechanic, not a programming bug, and works as intended
  — noted per the task's scope filter, not touched.
- **`bai`/`xue` sect/teacher mechanism**: both commands' rejection
  branches exercised live against a real, stationary, non-sect NPC
  (流氓头): `bai liu` → "流氓头既不属於任何门派，也没有开山立派，不能拜
  师。" (the `!mapp(ob->query("family"))` branch in `cmds/skill/bai.lpc`);
  `xue liu hand` → a random `reject_msg` (the "not your apprentice"
  branch in `cmds/skill/xue.lpc`). Both are correct, intentional
  rejections, not bugs.
- **Shop purchase (`list`/`buy`)**: exercised live at the 鲜花店 flower
  shop — `list` correctly showed the real price sheet (14 flower types,
  25–100 copper/silver each); `buy 1 qingren cao` was correctly rejected
  ("穷光蛋，一边呆着去！") since a brand-new character starts with zero
  cash. This is expected game economy, not a bug.
- **Unclean (net-dead) disconnect + prompt reconnect**: closed the
  socket without `quit` mid-session, confirmed the driver's own
  `net_dead()` (`clone/user/user.lpc`) does NOT park the player in a
  void room (unlike AGENTS.md §7.20's pattern — this lib just leaves the
  body in its current room with `set_heart_beat(0)` and a scheduled
  `call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD)`), reconnected
  promptly — `adm/daemons/logind.lpc:1073` genuinely calls
  `user->reconnect()` (confirmed via grep, ruling out AGENTS.md §7.20's
  "flavor 2" — a `reconnect()` apply that exists but nothing calls),
  which restored the live session cleanly ("重新连线完毕"), location/
  stats/exp all intact. **§7.20 does not apply to this lib.**
- **§7.12's `tell_room()` 2-arg type-crash class**: already fixed here
  (see fix #7 earlier in this file, `exclude || ({})`), confirmed by
  reading the live `adm/simul_efun/message.lpc` directly — this matters
  because `clone/user/user.lpc`'s `user_dump()` DUMP_NET_DEAD branch
  calls `tell_room(environment(), ...)` in exactly the vulnerable 2-arg
  form that crashed `dtsl` fatally (§7.12's escalation) — here it's
  already safe. **Confirmed this specific class is closed on this lib.**

### Corroborating evidence for AGENTS.md §10.8 (driver-level, NOT mudlib-fixable) — a THIRD occurrence of the fatal refcount/double-free crash class, this time with a full C++ backtrace captured

Per the task's explicit instruction to attempt a **real, full-duration**
net-dead wait: net-deaded `qinfengw` for real (closed the socket, no
`quit`) and blocked in the foreground for the genuine 900-second
(`NET_DEAD_TIMEOUT`, `include/user.h:11`) window, checking the driver's
own PID/RSS every ~50s (stayed stable, 109→116MB, no runaway growth —
ruled out AGENTS.md §10.8's own "unbounded RSS growth" concern
separately). **At roughly the 10–11 minute mark (before the 15-minute
net-dead timer itself ever fired — confirmed via save-file mtimes that
this player's own `user_dump()` never ran), the driver process aborted
outright** — `ss`/`ps` confirmed the PID and the port both gone. This is
NOT the mudlib bug above; it is the SAME driver-level class already
documented in AGENTS.md §10.8 (`xjcq2000`, `shiji`) — this is
the **third independent lib** to hit it, and the first time (of these
three) the exact C-level signature was captured with a full backtrace
(driver launched with stdout redirected to a file, per §10.8's own
"actionable takeaway"):

```
md: debugmalloc: attempted to free non-malloc'd pointer 562a0822e780
...
#13  vm.cc:156  remove_destructed_objects()
#14  backend.cc:123  call_remove_destructed_objects()  [the periodic 5-minute GC tick]
...
#6   svalue.cc:187  int_free_svalue() -> dealloc_object()
#5   object.cc:2044  dealloc_object() -> FREE()
#4   debugmalloc.cc:83 debugfree()
#3   md.cc:183  MDfree() -> "attempted to free non-malloc'd pointer" -> abort()
```

Unlike `dtsl`'s occurrence (which correlated with the §7.12 `tell_room()`
type-crash inside `user_dump()` itself, already ruled out as present on
this lib above), this crash fired from the ordinary **periodic 5-minute
`remove_destructed_objects()` GC sweep** — nothing to do with this
specific player's own net-dead timer, which hadn't even fired yet. This
strengthens §10.8's own conclusion that the underlying corruption is a
general driver-level object-lifecycle bug triggerable by ordinary
long-running gameplay (NPC wandering/dying, temp-object cleanup, etc.),
not specific to any one lib's mudlib code — no LPC-level fix is
possible or attempted here, matching §10.8's existing verdict. One
difference from the prior two occurrences worth noting: **this time
`log/debug.log` DID capture the `md: debugmalloc:...` line** (unlike
`xjcq2000`'s "debug.log showed nothing whatsoever") — though the
full C++ backtrace was still only in the driver's own redirected
stdout, so capturing driver stdout during any long-sit session remains
the only way to get the actionable detail. Per the task's cleanup
instructions and `dtsl`'s own precedent, the raw backtrace file was
NOT left in the repo (described here in prose instead); restarted the
driver cleanly afterward and confirmed `qinfengw`'s last-saved state
(from the earlier clean `quit`, before this net-dead attempt) reloaded
correctly with no corruption or stuck state — the crash cost real
uptime but not player data, since nothing autosaves mid-netdead.
**Recommend escalating to a driver-level investigation per §10.8's own
suggested next step**, now that a third occurrence with a full
backtrace exists.

### Explicitly not verified live (say-so per task instructions)

- **纪晓芙 (峨嵋派 4th-generation disciple) sect-join success**: found
  a real, reachable, family-having sect NPC placed directly in the town
  square (`d/city/guangchang.lpc`'s `CLASS_D("emei") + "/ji"`), but she
  roams (confirmed: gone from the room within the time a scripted
  client takes to arrive, and still absent after ~40s of repeated
  `look` polling) — a scripted session could not reliably catch her in
  place to complete a full `bai`→`recruit` round trip within this pass's
  time budget. The `bai`/`xue` CODE PATHS themselves were genuinely
  exercised live (against a stationary non-sect NPC, see above), just
  not a full SUCCESSFUL sect recruitment. Not treated as a bug — pure
  scripted-testing-vs-roaming-NPC timing limitation.
- **A successful (non-rejected) shop purchase**: `qinfengw` never
  earned any money during this pass (no combat kills that drop coin,
  no jobs attempted) — reaching a real purchase would need either
  grinding currency or admin-granting some, out of this pass's time
  budget. The purchase FLOW (`list` + `buy`) was genuinely exercised and
  correctly rejected for insufficient funds, which is as far as this
  pass got, stated explicitly rather than silently skipped.
- **Death/respawn**: not reached — the only real combat this pass did
  was the intentionally-safe `fight` sparring match, which by design
  never risks death. Reaching a real death would need deliberately
  seeking out a hostile/lethal NPC (`kill`, not `fight`), out of this
  pass's time budget alongside the extended net-dead wait above.

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 229 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单（`cmds/imm/update.lpc`、
`cmds/adm/update.lpc` 的 §7.106 防护、`master.lpc::log_error()` 的
§7.10 大小写无关 `"arning:"` 过滤门、`maximum evaluation cost`）全部
确认已是正确/安全状态，无需改动；本档案无 `adm/daemons/closed.lpc`，
不受 §7.107 影响。

### 新发现并修复的 bug（AGENTS.md 新增 §7.108）

**"踢掉重复登录"重连路径导致角色永久无法接收任何指令**——现场用两
个真实 telnet 连线复现：先用 `fluffos` 登录并保持连线不断开，再用同
一账号从第二个连线登录，触发"您要将另一个连线中的相同人物赶出去，
取而代之吗？(y/n)"提示，答 `y` 后显示"重新连线完毕"、房间内 NPC 环
境对话正常继续刷新，但此后 `score`/`look` 等任何指令一律只回应
"什么？"（未知指令），角色实质性瘫痪。

与之对照：单纯"断线不 quit，等驱动判定净断线后重连"这条路径（本项
目 §10.7 checklist 更常规测试的那条）用同一账号复测完全正常——问题
专门出在"旧连线仍活着、主动踢掉它"这条分支。根因追查到
`adm/daemons/logind.lpc::confirm_relogin()`（`y`分支）的
`exec(old_link, user); destruct(old_link);` 顺序——把角色的活跃连线
转移到旧的、即将销毁的 login 外壳物件上后再销毁它，这个"瞬间失去
interactive"的过程似乎连带清空了指令派发表，而随后
`reconnect(ob, user)` 自己的 `exec(user, ob)` 只恢复了连线本身，没有
重新注册指令。`clone/user/user.lpc::reconnect()`（角色类自己的重连
回调）本身也从未呼叫 `enable_commands()`——净断线重连路径因为角色物
件全程没有真的失去 interactive，所以从未暴露过这个缺口。

**修复**：在 `reconnect()` 开头无条件加一行 `enable_commands();`
（幂等，两条重连路径都安全）：
```lpc
void reconnect() {
  enable_commands();
  set_heart_beat(1);
  ...
```

**验证**：重启驱动加载修复后，用完全相同的"保持第一个连线不断开→
第二个连线登录→答 y 踢掉旧连线"复现步骤，`score` 修复后立即正常显
示完整角色档案；净断线超时重连路径复测依旧正常（确认没有破坏原本
就工作的分支）。

**规模提示，本轮未展开成扫描**：`grep -rl 'exec(old_link'
libs/*/work` 命中 140+ 个档案、覆盖相当一部分语料库（经由共享的
`logind.lpc` 传承/惯例扩散，不是单一血统），但和 §7.106/§7.107 那种
逐字节一致的形状不同，各档案 `reconnect()` 自己的实现差异较大，不
适合盲目机械扫描——已记录进 AGENTS.md §7.108，标记为未来任何库做
§10.7 时的一个建议检查项（专门测"踢掉重复登录"这条路径，不能只测净
断线超时）。

### 现场验证摘要

驱动干净启动（`build-debug`），管理员 `fluffos`/`Mud@2026` 登录确认
`目前权限：(admin)`，`update /adm/daemons/logind` 成功验证真实写入权
限。净断线重连、踢掉重复登录重连两条路径均已现场验证（见上）。
`debug.log` 全程干净（569 行，无真实错误）。

### 本轮修改的文件

- `work/clone/user/user.lpc`
