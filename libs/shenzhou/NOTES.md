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
lineage already seen on es1_win/esI/xkx2001/rzrmud/xo/beimeixiakexing2001/
xinkuangxiangkongjian2/yueyingqiyuan/wuhanzhan/haiyang2/yanhuangwuhun/
yanhuangyingxiongshi/xuanjianlu. Layout is `adm/single/{master,simul_efun}`
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
   `beimeixiakexing2001` (#45). Fixed by dropping `private` (kept
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
    `nitan_ceshi`/`yanhuangyingxiongshi` findings): `feature/attack.lpc`
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
  like `xiyangzaixian3`'s finding. No hidden gate found.
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
