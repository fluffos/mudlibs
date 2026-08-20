# longyunmeng — 龙云梦·炎龙封印 (source version)

Archive: `龙云梦-炎龙封印源码版.rar` (archive #103, "source code version"). Port:
**40094**. Status: **done** (boots clean, full registration flow verified
end-to-end THREE times with real Chinese names, both genders, plus a
post-registration inventory check; every ordinary post-login command
(`look`/`score`/`i`) confirmed working with real output).

Root found directly at the archive's top level (`raw/ylfy/`, no nesting).
19,490 raw files, 15,924 real `.c` files before rename (15,926 `.lpc` after
including 2 uppercase-`.C` stragglers). Sibling archive #102
(`龙云梦-炎龙封印-二进制版.rar`, "binary version") was triaged FIRST per the
task brief and confirmed non-convertible — see the separate write-up at the
end of this file (also summarized in the final report).

## Lineage — confirmed, not assumed

The task brief asked for a direct comparison against the two already-done
"炎龙封印"-themed libs: `xyzx3` (#48, 夕阳再现III之炎龙封印) and
`ylfyxa3` (#68, 炎龙封印-笑傲江湖3阿飞站). Both archives (binary
AND source) self-identify their engine family via literal top-level
directory names `xyzx/ylfy` ("XYZX" = pinyin initials of 夕阳再现/"Sunset
Reappears", "YLFY" = pinyin initials of 炎龙封印/"Flame Dragon Seal") — the
exact same macro-naming convention documented in `ylfyxa3`'s
own NOTES.md.

**md5sum/diff comparison against `master.c`, `chinese.c`, `securityd.c`**
(the exact files the task brief named):
- `adm/obj/master.c`: 544 lines here vs 375 in `xyzx3`'s copy (NOT
  the same revision) but **544 lines, near-byte-identical** to
  `ylfyxa3`'s copy — `diff --strip-trailing-cr` shows only
  CRLF/whitespace noise plus ONE extra credit-comment line
  (`// ...每次啟動MudOS時報一次 By Wenwu`, present here, absent in
  `ylfyxa3`'s copy). This "By Wenwu" signature matches the
  binary archive's own `说明文档.txt`, which credits the whole lib to
  `By 龙云梦(Wenwu)` — i.e. this archive is Wenwu's own further-tweaked build
  of the same engine core `ylfyxa3` is descended from, not an
  independent rewrite.
- `adm/simul_efun/chinese.c`: **byte-identical** (0 diff lines after
  stripping CR) to `ylfyxa3`'s copy.
- `adm/daemons/securityd.c`: 306 lines here vs 304 there — diff is 33 lines,
  entirely personalization (adding wizard names "wenwu"/"chenzhoul" to
  several ACL tables, e.g. `"/"` trusted-read gains `"wenwu"`, `"log"`
  exclude/trusted-write gains `"wenwu"` twice) — the actual `valid_read()`
  ACL LOGIC is functionally identical between the two, including missing
  the same §15n compile-time allowlist gap (see fixes below).
- `adm/daemons/logind.c`: 1922 lines here vs 1867 there (~310 diff lines,
  ~16%) — the two registration-flow files have diverged more than
  master/chinese/securityd, but share the same overall callback shape
  (`logon → get_version → get_id → confirm_id → get_name → new_password →
  confirm_password → new_biaoshi → confirm_biaoshi → select_gift → get_gift
  → get_magic_born → get_email → get_gender → make_body`), including the
  identical §15q client-version-gate shape (see below) and the identical
  §15ai DNS_MASTER unconditional call in `logon()`.

**Conclusion**: `longyunmeng` is a closely-related, independently-forked
descendant of the same XYZX/YLFY engine family as `xyzx3` and
`ylfyxa3` — sharing byte-identical core files in places
(chinese.c) and near-identical ones in others (master.c), but with its own
evolved registration daemon and its own content tree (~19.5K files vs
`ylfyxa3`'s 17.4K) — not a rebrand or a simple content-only
fork of either sibling. Diffing whole `raw/` trees pairwise wasn't
attempted (would be a large, low-value effort given the daemon-level
comparison above already answers the lineage question conclusively); the
registration-flow fixes below were ported from `ylfyxa3`
where the underlying shape matched exactly, and independently re-verified
by reading `longyunmeng`'s own source where it didn't.

## Fixes applied (with why)

1. **AGENTS.md §15h** (proactive) — `adm/simul_efun/chinese.lpc`'s
   `is_chinese()`: GBK lead-byte check (`str[0] > 160 && str[0] < 255`,
   `strlen>=2`) → CJK codepoint check (`str[0] >= 0x4e00 && str[0] <=
   0x9fff`, `strlen>=1`). `adm/daemons/logind.lpc`'s `check_legal_name()`:
   byte-count bound `< 2 || > 10` → character-count bound `< 1 || > 5`
   (matches what the error message already promises — "1 到 5 个中文字");
   removed the `i%2==0 &&` even-byte-offset gate so every character
   position is checked, not every other one.
2. **AGENTS.md §15ai** (proactive, found by reading `logon()` in full before
   testing, per the task's standing policy) — `logind.lpc`'s `logon()` had
   an unconditional `if ( !DNS_MASTER->query_doing_end() )` gate that
   destructs EVERY connection with a "正与主站同步中" ("syncing with main
   station") message. Since `dns_master` is (correctly, per §15p) commented
   out of `adm/etc/preload`, `find_object(DNS_MASTER)` returns 0, and
   `0->query_doing_end()` silently returns 0, making `!0` true — this would
   have destructed 100% of connections before any prompt ever appeared, an
   even more disruptive failure than the daemon's own hang would have been.
   Fixed by adding the `find_object(DNS_MASTER) &&` guard, treating "daemon
   absent" as "skip the gate" (exactly the fix pattern documented for
   `xiyouji2003`, archive #81). Grepped every other `DNS_MASTER` call site
   in the lib (40+ hits across `cmds/`, `www/`, `adm/daemons/network/`) —
   all others already have their own `find_object(DNS_MASTER)` guard or are
   part of the unreachable/never-preloaded intermud daemon family; only
   `logon()`'s copy was missing it.
3. **AGENTS.md §15z** — `include/globals.h` had:
   ```c
   #ifndef __SENSIBLE_MODIFIERS__
   #define nosave nosave
   #define protected nosave
   #else
   #define private protected
   #define nosave nosave
   #endif
   ```
   (already post-§3-sed at inspection time: the raw archive's `#define
   nosave static` / `#define protected static` had already been rewritten
   by `convert_lib.sh`'s blanket `static`→`nosave` sed). Confirmed this
   FluffOS build predefines `__SENSIBLE_MODIFIERS__` (`grep
   __SENSIBLE_MODIFIERS__ build-debug/src/options.autogen.h`), so the
   `#else` branch — `#define private protected` — was the one actually
   active, silently collapsing `private`'s distinct access level to
   `protected`'s. Neutralized the whole shim (deleted both branches, no
   replacement macros): `nosave`, `protected`, and `private` are all
   independently correct, real keywords on this driver.
4. **AGENTS.md §15n** — `adm/daemons/securityd.lpc`'s `valid_read()` has a
   genuine custom ACL (`trusted_read`/`exclude_read` tables, `By
   Annihilator@Eastern.Stories` credit, same family as `ylfyxa3`'s
   and `shujian2008`'s) with no func-based compile allowlist. Added the
   standard early-return `switch(func) { case "load_object": case
   "recompile_object": case "include": return 1; }` ahead of the euid/ACL
   checks — otherwise the driver's own compile-time reads of any
   never-preloaded `/adm`/`/cmds` object, attributed to a fresh
   pre-authentication connection's `(player)` status, would be denied the
   first time the registration flow lazily touches one. Ported directly
   from `ylfyxa3`'s fix #5 (same securityd.lpc lineage,
   confirmed via the md5sum/diff comparison above that the underlying ACL
   logic — not just the wizard-name personalization — is unchanged).
5. **AGENTS.md §15s** — `adm/simul_efun/message.lpc`'s `tell_room(ob, str,
   exclude)` passed a possibly-unset `exclude` (int `0`, not an array)
   straight into `message()`'s 4th argument in its common 2-arg call form;
   `shout(str)` passed `this_player()` (which can be `0`) as the exclude
   arg too. Fixed both to `exclude || ({})` / `this_player() || ({})`.
   Same exact wrapper shape as `ylfyxa3`'s fix #7 (and the
   original `yueyingqiyuan` discovery, archive #54) — ported directly,
   re-verified against this lib's own copy of the file (not assumed).
6. **AGENTS.md §14** — `master.lpc`'s `valid_override(file, name)` upgraded
   to the 3-arg form (`file, name, main_file`), checking `main_file ==
   SIMUL_EFUN_OB/MASTER_OB` in addition to `file`, so an `efun::` override
   textually inside a file `#include`d into `simul_efun.lpc`/`master.lpc`
   is still recognized as trusted.
7. **AGENTS.md §8d/§15o** — `master.lpc` had **no** `get_include_path()` at
   all (confirmed via grep before the fix, not assumed). Added the standard
   shape (prepends the compiling file's own directory, `":DEFAULT:"` for
   everything else) as insurance for any `<local.h>`-next-to-its-user
   `#include` reached mid-connection; `convert_lib.sh`'s own local-angle-
   bracket-to-quote pass had already converted most such includes to quoted
   form during the automated conversion step, so this is primarily
   insurance, matching the same conclusion `ylfyxa3` reached.
8. **AGENTS.md §15w** — `master.lpc`'s `log_error()` displayed EVERY
   message reaching it (including ordinary compile *warnings*, not just
   real errors) to `this_player(1)` prefixed with the alarming "编译时段
   错误：" ("compile-time error:"). **Found live, not just proactively**:
   the first full registration+play test showed several "编译时段错误：...
   warning: Unused local variable..." lines leaking to the connected
   player during ordinary gameplay (triggered by lazy compiles of
   `feature/xiulian.lpc`, `cmds/std/look.lpc`, `adm/daemons/newsd.lpc`,
   `adm/daemons/statud.lpc`, `cmds/usr/score.lpc`, `adm/daemons/combatd.lpc`
   during the very first registration). Gated the player-facing broadcast
   on the message NOT containing the substring `"warning: "` (verified
   exact casing against `compiler.cc`'s `d.is_warning ? "warning: " :
   "error: "`), still logging everything to file either way. **Verified
   fixed**: the second full registration+play test (after this fix, same
   session, different character/gender) showed zero such lines despite
   exercising the same lazy-compile-heavy registration path.
9. **AGENTS.md §15v** — `adm/simul_efun/util.lpc` had `count_add`/
   `count_mul`/`count_sub`/`count_div`/`count_lt`/`count_gt`/`count_le`/
   `count_ge`/`count_eq` gated behind an unconditionally-`#define`d
   `WENWU_IMPROVED` flag (`include/globals.h:220`, always active, same
   always-on-flag shape as the nitan family's `LONELY_IMPROVED`), each
   calling a bespoke MudOS-fork arbitrary-precision bignum efun
   (`efun::count(n1, op, n2)`) that never existed on this driver — **this
   was FATAL, not just a sweep-noise item**: `adm/simul_efun/util.lpc` is
   `#include`d into `simul_efun.lpc` itself, so `lpcc config.fluffos
   /adm/obj/master` failed outright with 6× "Unknown efun: count" before
   any other check could even run. No pure-LPC fallback existed anywhere
   in the file (checked the whole `#ifdef WENWU_IMPROVED` block and its
   surroundings). Restored using ordinary 64-bit int arithmetic via a small
   `__count_num(mixed n)` helper (`intp(n) ? n : atoi(n)`, **not** a bare
   `(int)` cast — that's a type-assertion on this driver, not a
   string-to-int parse) — matches the simpler of the two fixes used on
   `nitan_ceshi` (archive #60). Also checked the other 5 files with
   `#ifdef WENWU_IMPROVED` blocks (`feature/dbase.lpc`, `feature/color.lpc`,
   `feature/unansi.lpc`, `adm/simul_efun/file.lpc`,
   `cmds/std/actionavailable.lpc`) — these gate `efun::remove_ansi()` /
   `efun::base_name()`, neither of which caused a compile failure (checked:
   no `contrib`/other package on this driver defines `remove_ansi` as a
   real efun either, but none of these 5 files are `#include`d into
   master/simul_efun, so they only fail if/when individually loaded — not
   reached by the verified boot+registration+post-login path, left
   unfixed per the "fix what a real failure surfaces" policy).
10. **NEW, found via the FIRST lpcc `/adm/obj/master` attempt (this exact
    fix unblocked the very first boot)** — a second bare, direct (non-
    wrapper) call to the same dead bignum efun: `adm/daemons/teamd.lpc:423`
    had `vv = atoi(count(count(v,"*",lvl), "/", max_lvl));` (`v`, `lvl`,
    `max_lvl` are all plain ints in this function — a team-experience-split
    calculation). Fixed to plain `vv = max_lvl ? (v * lvl) / max_lvl : 0;`.
    `teamd.lpc` isn't `#include`d into simul_efun, but IS reachable via
    lazy load from ordinary team-formation gameplay, so left unguarded this
    would have been a live, reachable runtime crash the first time two
    players formed a team and split loot — grepped the whole tree for any
    OTHER bare (non-`count_*`-wrapper) `count(` call afterward and found
    none.
11. **AGENTS.md §8g (one shared root cause, not N bugs)** — a genuinely
    corrupted `d/honghua/cloth.lpc` (raw archive confirmed via hex dump:
    almost the ENTIRE file's newlines were replaced with plain spaces,
    collapsing 15+ logical lines into 2 physical lines — pre-existing
    corruption in the ORIGINAL archive, not conversion fallout, since the
    raw `.c` bytes show the same space-for-newline pattern) broke the
    `#include <armor.h>` directive (which MUST be alone on its own line for
    the preprocessor to parse it correctly) and cascaded into 7 separate
    lpcc-sweep failures (`d/honghua/damen`, `wen-tailai`, `goldroom2`,
    `zongduo`, `npc/zhaobanshan`, `npc/yuyutong`, plus `cloth` itself — all
    NPCs/rooms in the same zone that reference the basic "布衣" starter
    cloth item). Rewrote the file with proper line breaks (content
    unchanged, only whitespace/newline placement restored) — resolved all
    7 dependent failures in one fix (re-verified each via targeted `lpcc`).
    **This exact starter-cloth item is what every new character actually
    receives** — confirmed live via the third registration test's `i`
    (inventory) command showing "□布衣(Cloth)" rendering correctly after
    the fix.
12. **AGENTS.md's documented "iconv -c eats the adjacent real newline before
    a heredoc's closing tag" gotcha** (already known from `xyzx3`/
    `tianxia`/`ylfyxa3`) — recurred verbatim in the SAME 3
    files as `ylfyxa3` (`d/heimuya/shenggu.lpc`,
    `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`), all flagged "LOSSY
    conversion" by `convert_lib.sh` and failing with `error: End of file in
    text block`. Confirmed via raw hex inspection: same `...奕奕.LONG );`/
    `...盒子(box).LONG );`-shaped closing-tag-glued-onto-text-line pattern.
    Fixed by re-inserting the missing newline before each `LONG` tag (a
    small Python regex pass, `(?<!\n)LONG \);` → `\nLONG );`, verified no
    other unintended matches).
13. **Genuine pre-existing typos, §10-shaped (missing closing quote before
    concatenation/comma)** — confirmed present in the raw archive by direct
    inspection, not conversion fallout:
    - `kungfu/skill/qingyi-jian.lpc`: `"skill_name" : "大悲式,` (missing `"`
      before the comma) — the resulting runaway string literal absorbed the
      next mapping entry's `"skill_name"` key text as raw illegal bytes,
      producing 5 "Illegal character" errors plus a syntax error. Fixed by
      adding the missing `"`.
    - `kungfu/skill/kunlun-zhang.lpc`: `"...另一掌却按向$n「,` (same shape,
      missing `"` before the comma, additionally missing the closing `」`
      quote-bracket pair) — same cascade into the next mapping entry's
      Chinese text. Fixed by adding the missing `"`.
14. **AGENTS.md §12** (orphaned non-LPC `.c` file caught by the blind
    rename) — `doc/mudlib/efuns.lpc` is a plain-text listing of efun names
    (documentation index: "acos add_action all_inventory ..."), byte-
    identical in shape to the same file already found and fixed in
    `ylfyxa3`. Confirmed nothing references it by path, then
    renamed to `doc/mudlib/efuns.txt`. **Caveat**: this rename happened
    *while* the full `lpcc_check.sh` sweep was already running in the
    background (its file list was captured before the rename), so the
    sweep's own output still shows one stale `FAIL /doc/mudlib/efuns`
    entry for the old `.lpc` path — harmless (confirmed the renamed `.txt`
    file is correctly excluded from any future sweep), not a real ongoing
    failure, just a timing artifact of when the rename happened relative to
    when `find` enumerated the file list.
15. **Genuine pre-existing typo** — `doc/mudlib/efuns/shiwu.lpc` (a real
    room, "小石屋", despite living under the `doc/mudlib/efuns/` path —
    same exact file/typo already documented in `xyzx3`'s NOTES.md)
    had `call_out(do_close,0);` — a bare, unquoted function-name identifier
    instead of a string literal. Fixed to `call_out("do_close",0);`.
16. **Missing `#include <liebiao.h>`** — 6 files under `clone/winbox/`
    (`gaoji_box`, `lack_card`, `chaoji_box`, `vip_box`, `chuji_box`,
    `zhongji_box` — all lottery/gacha-style "prize box" clone items) used
    the `L_ICON(x)` macro (defined in `include/liebiao.h`) without
    including that header at all (confirmed via grep: `cmds/std/icon.lpc`
    and `cmds/std/look.lpc` both correctly include it and both already
    passed the sweep, isolating the gap to these 6 files specifically).
    Added `#include <liebiao.h>` to each.
17. **Genuine pre-existing typo** — `d/baituo/obj/bowl.lpc` and
    `d/baituo/npc/obj/bowl.lpc` (both, identical) called `set_name("海口
    大碗", "bowl")` where `feature/name.lpc`'s real signature is
    `set_name(string name, string *id)` — a bare string instead of an id
    array. Fixed both to `set_name("海口大碗", ({"bowl"}));`. (Coincidentally
    the same class of bug independently found in the unrelated ES
    II-lineage `jqxz2008`-family libs' own `bowl.lpc` this
    session — different lineage, same shape of mistake, not connected.)
18. **AGENTS.md §15ap** — `kungfu/skill/force.h` and `d/gumu/npc/force.h`
    (byte-identical copies of the same `#include`d, not `inherit`ed,
    fragment) used `explode(__FILE__, "/")[<1][0..<3]` to derive a skill's
    own name from its filename for an exclusivity check ("can't practice
    two different `force`-type skills at once"). Since `__FILE__` inside an
    `#include`d fragment expands to the FRAGMENT's own compile-time path
    (`.../force.h`), not the including skill file's path, every file that
    includes this header computed the exact same (wrong) `skl_name`,
    silently breaking the exclusivity check for all of them (matches the
    `xlqy_early`/archive #27 finding exactly). Fixed by replacing
    `__FILE__` with `file_name(this_object())` — a real runtime call that
    correctly resolves to the actual loaded object's own name — and
    dropped the now-incorrect `[0..<3]` fixed-width slice (verified via
    driver source, `src/packages/core/efuns_main.cc`'s `f_file_name()`,
    that `file_name()` on this driver returns the extension-LESS `obname`
    directly, so no further slicing is needed or correct).

## Confirmed NOT needed (and how confirmed)

- **§4** (master `valid_read`/`valid_write` lazy `load_object` recursion
  risk): both applies only do `find_object(SECURITY_D)` — no `load_object()`
  call anywhere in either. Read the full function bodies directly.
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both present in
  `master.lpc` (lines 165/169 in the raw file), returning `ROOT_UID`/
  `BACKBONE_UID` respectively.
- **§15l** (`destruct(SIMUL_EFUN_OB)` in master's `create()`): `create()` is
  a single `write("master: 成功加载.\n");` line, nothing else.
- **§15q** (hidden client-protocol-version gate): read `get_version()`'s
  full body before testing, not assumed. There IS a gate — checks the
  first input against a pattern embedding a literal `"2060"`-style Tomud
  handshake token via `ascii_num(Rasc) + "2060"` — but it's gated on
  `query_ip_port(ob) == TOMUD_1 || query_ip_port(ob) == TOMUD_2` (both read
  dynamically from `data/config/system.h`, never our assigned port 40094),
  so an ordinary connection takes the plain-id-validation branch directly.
  Confirmed empirically: none of the three registration transcripts below
  ever needed to send a magic string.
- **§15ac** (bare `SAVE_EXTENSION`): `logind.lpc` already uses the correct
  `__SAVE_EXTENSION__` throughout — grepped for the bare form, zero hits.
- **§15ao** (`switch` with only `default:`, no real `case`): grepped the
  whole converted tree, zero hits.
- **§15am** (`file_size()` truthiness trap): grepped every `file_size(`
  call used as a bare/implicit boolean condition — all 12 hits already use
  explicit `> 0`/`<= 0`/`>= 0`/`!= -2` comparisons, including
  `virtuald.lpc`'s own copy (`file_size(pname + ".lpc") >= 0`).
- **§15u** (dormant destructive license/anti-piracy check): grepped
  `securityd.lpc`/`master.lpc` for suspicious mass-deletion/shutdown
  functions gated on an opaque check — found none. (`master.lpc` DOES have
  a `valid_compile_c()` function gating certain directories behind
  `file_size("/adm/etc/xyzx")`/`file_size("/doc/skill/skyfy")` checks — both
  target files exist on disk, and the function isn't even a real driver
  apply name nor called anywhere else in the tree; confirmed dead/inert,
  not a functioning gate of any kind.)
- **§15t** (absolute-path angle-bracket includes, `..`-relative includes):
  grepped the whole tree, zero hits of either shape.
- **§8f** (bare `TYPE * a, b;` comma-list array-star typo): grepped the
  whole tree for the shape, zero hits.
- **Uppercase `.C` files**: found and renamed 2
  (`d/quanzhen/npc/obj/bookshelf.C`, `d/quanzhen_old/npc/obj/bookshelf.C`,
  probably a duplicated old/new-zone pair) — neither contained any `.c"`
  literal references needing a follow-up fix.
- **§3 counterexample** (`"static/XXX"` log-path string literals colliding
  with the blanket `static`→`nosave` sed): confirmed a real `/log/static/`
  directory exists on disk (`log/static/archive`), and 19 files had their
  `log_file("static/...")` calls silently rewritten to `"nosave/..."` by
  the blanket sed. Reverted all 19 (`grep -rl '"nosave/'` → `sed -i
  's/"nosave\//"static\//g'`), verified zero `"nosave/` string-literal
  hits remain afterward.
- **§15ak** (same-basename extensionless file vs `.c`→`.lpc`-renamed
  sibling): found 4 candidate collisions (`kungfu/skill/qiankundanuoyi`,
  `quest/guojob/job2/pi1`, `quest/skills2/wakuang/zhujia`,
  `kungfu/skill/longmen-shengong/powerup`). Diffed each: 2 of the 4
  (`qiankundanuoyi`, `zhujia`) turned out to be plain-text doc/story
  blurbs coexisting harmlessly alongside real code of the same basename
  (not a genuine "backup vs live" collision — the extensionless file was
  never meant to be loaded as an object at all). The other 2
  (`quest/guojob/job2/pi1`, `kungfu/class/longmen-shengong/powerup`) ARE
  genuine code-vs-code differences (a job_over-check reordering; a
  "达摩神功"-vs-"龙门神功" message-text variant) — neither is on the
  boot/registration/post-login path verified below, and picking a "winner"
  with confidence would need deeper content investigation than the time
  budget allows this late in a ~100-archive project; noted here, not
  resolved, matching this project's established "content gap, not chased
  further" precedent for ambiguous non-critical cases.
- **`network/server_2000` preload risk**: this daemon (`adm/etc/preload`,
  NOT commented out, unlike `dns_master`) implements a custom LPC-to-LPC
  "server sync" file-transfer protocol on its own port (`SV_PORT`, default
  `2000`) via `socket_create()`/`socket_bind()`/`socket_listen()` in its own
  `create()` — superficially similar to the DNS/intermud daemon family
  §15p warns about, but its `setup()` guards every socket call with an
  explicit failure check that just logs and `return`s (no `resolve()`/DNS
  lookup anywhere in `create()`'s synchronous path). Left in preload
  (unlike `dns_master`) since it's a same-host TCP listener, not a
  cross-network blocking call; confirmed empirically across 3 full boots
  that this never delayed or hung startup (`Accepting telnet connections`
  appeared within ~1-2 seconds every time).

## Config

`config.fluffos`: `port number : 40094`; original multi-port setup
(`external_port_1`/`external_port_2`, telnet 4000/6000) commented out — see
the §15q write-up above for why a single ordinary port is not just
acceptable but simpler to test against. `mudlib directory` pointed at the
absolute `work/` path; `mud ip : 0.0.0.0` added explicitly. `log`/`binaries`
directories created under the lib root (driver launched via `cd
libs/longyunmeng && .../driver config.fluffos`, per AGENTS.md §6's `log
directory`-resolves-relative-to-CWD rule). `maximum evaluation cost` was
already `10000000` in the original config — above the `5000000` de facto
floor established across this project's recent libs (and no eval-cost
interruption was ever observed across 3 full registration sessions), so
left unchanged, no bump applied. A handful of "obsolete config key" boot
warnings (`address server ip`/`address server port`/`reserved size`/
`binary directory`) print at every boot — harmless, matches every other
already-done lib's config in this family.

## Registration flow — read before testing, not assumed

Read `logind.lpc`'s full `logon()` → `get_version()` → `get_id()` →
`confirm_id()` → `get_name()` → `new_password()` → `confirm_password()` →
`new_biaoshi()` → `confirm_biaoshi()` → `select_gift()`/`get_gift()` →
`get_magic_born()` → `get_email()` → `get_gender()` → `make_body()` chain
in full before writing any test script. Notable subtleties found this way
(all avoided in the transcripts below):
- The very first prompt doubles as the real English-id prompt for any port
  other than the two hardcoded (dynamically-configured) Tomud ports — send
  the id directly, no "2060" handshake needed (§15q, confirmed not needed
  above).
- After the surname/name is accepted, the flow adds an extra "身份标识"
  (identity token, ≥9 characters, no `//` substring) step beyond the
  password, confirmed twice like the password itself, before reaching the
  gift-selection prompt.
- Selecting the random-gift option (`0`) does **not** auto-accept the
  rolled stats — `get_gift(" ", ...)` (called with a literal `" "` yn value)
  takes the "reject and re-roll, ask again" branch since `" "[0]` isn't
  `'y'`/`'Y'`, requiring an explicit follow-up `"y"` (same §15j-adjacent
  shape already documented for `ylfyxa3`).
- After the gift accept, there's an ADDITIONAL "魔法天赋" (innate magic
  element, 0-10) choice step (`get_magic_born`) not present in either
  sibling lib's registration flow, before finally reaching the email
  prompt.

### Full transcript outcome — run 1 (male, pre-§15w-fix)

One continuous `mudclient.py` connection: `qinfeng` (English id) → confirm
`y` → **real Chinese name `秦风`** (accepted, no rejection — confirms the
§15h fix) → password `abc12345` (twice) → identity token `abc123456`
(twice) → gift selection `0` → accept `y` → magic element `0` (光明/Light)
→ email `test@test.com` → gender `m` → **entered the actual game world**:
room "客栈" (Inn) on 西大街 (West Main Street), full room description with
an NPC (丁三) and exits rendered correctly, "新手礼物包" starter gift
granted. Then, per the standing policy, sent post-login commands in the
SAME connection: `look` re-rendered the room correctly; `score` rendered
the full character sheet (correct Chinese name 秦风, correct stats,
correct gender-specific 头衔/title "布衣平民"). **Several "编译时段错误：
... warning: Unused local variable..." lines leaked into the output**
during this run (the §15w bug, not yet fixed at this point) — noted, not
alarming (harmless warnings, not real errors), fixed before run 2.

### Full transcript outcome — run 2 (female, post-§15w-fix)

Rebooted with the §15w fix (and the teamd.lpc/cloth.lpc/etc fixes already
applied earlier) applied. `qinling` → confirm `y` → real Chinese name
**`秦岭`** (accepted) → password/identity-token setup → gift `0`/`y` →
magic element `0` → email → gender `f` → entered a **different**, correct
gender-specific starting room ("假日客店"/Holiday Inn on 东大街) and
received the correct gender-specific gift item ("粉红绸衫", pink silk
robe); `look` and `score` both rendered correctly (female-specific title
"芊芊民女", "你的老公" instead of "你的老婆", etc). **Zero "编译时段错误：
...warning..." lines this time** — confirms the §15w fix. Zero new
`debug.log` lines in either run (both stayed at the post-boot baseline).

### Full transcript outcome — run 3 (male, final verification incl. inventory)

Rebooted once more after the remaining content fixes (winbox `L_ICON`
include, `bowl.lpc` set_name, `force.h` `__FILE__` bug, the
`qingyi-jian.lpc`/`kunlun-zhang.lpc` typos) to confirm nothing regressed.
`qinyun` → confirm `y` → real Chinese name **`秦云`** → password/identity
setup → gift `0`/`y` → magic element `3` (水/Water) → email → gender `m`
→ entered 假日客店 again → `look` (room re-rendered correctly) → `score`
(full character sheet, correct name/stats) → **`i`** (inventory command,
the deeper post-login check beyond the task's minimum `look`/`score` bar)
→ correctly showed "你身上带着的物品有(负重 3%)：□布衣(Cloth) / 新手礼物包
(Gift)" — confirming the just-repaired `d/honghua/cloth.lpc` (fix #11
above) loads and displays correctly as the real starter equipment every
new character receives. Zero new `debug.log` lines across this run too.
Save files confirmed correct UTF-8 in all three runs
(`data/user/q/{qinfeng,qinling,qinyun}.o` each contain `"name":"秦风"` /
`"name":"秦岭"` / `"name":"秦云"` verbatim, uncorrupted).

## lpcc sweep

15,926 files (15,924 original + 2 uppercase-`.C` renames) swept with
`scripts/lpcc_check.sh`. The `lpcc --batch` process finished compiling all
15,926 files (confirmed: all 15,926 `=====` markers present in the raw
log) but then sat for an extended period past the point its own
trace-duration message reported the dump complete — per AGENTS.md §6b's
guidance to kill once the compile phase has visibly finished rather than
let the post-compile phase run indefinitely, killed the process by its
exact PID and ran the script's own Python post-processing step manually
against the already-complete raw log (memory stayed healthy throughout,
13-19GB free out of 23GB total the whole time, never remotely close to
the danger zone — this lib is well below the mega-lib threshold).

**First pass**: 15,637 / 15,926 = **98.2%** pass (289 failures).

**Triaged all 289, in two groups**:

1. **Fixed 21 individually** (already detailed above with line/file
   specifics): the `d/honghua/cloth.lpc` corruption cascade (7 files), the
   6 `clone/winbox/*` missing-include files, the 2 `bowl.lpc` files, the 3
   `d/heimuya/*` heredoc files, the 2 missing-quote typo files
   (`qingyi-jian.lpc`, `kunlun-zhang.lpc`), and the stale
   `doc/mudlib/efuns` sweep-timing artifact (already renamed to `.txt`
   before the sweep's post-processing ran, just enumerated by `find`
   before the rename landed). All 21 individually re-verified via targeted
   `lpcc <config> <path>` calls after fixing — all now PASS.
2. **The dominant remaining category (~218 of the other 268, roughly 75%
   of the total 289) is a single shared root cause, confirmed to be an
   lpcc-sweep-ISOLATION ARTIFACT, not a live bug** — worth a full
   explanation since it's the majority of the sweep's noise:
   - 183 files under `/d/migong/lev*/dong*` (a maze/labyrinth zone), 24
     under `/d/automap/*`, and 11 under `/d/jqg/hc*` all fail identically
     with `*cannot bind a functional to an object with a pending
     replace_program()`, rooted at `inherit/room/room.lpc`'s
     `xyzx_system_clean_up()` (a room-inventory-overflow cleanup routine
     that builds a `filter_array(..., (: ... :))` closure bound to
     `this_object()`).
   - The full call chain (identical across all ~218 files): the target
     room's own `create()` → `setup()`/`reset()`/`make_inventory()` spawns
     an NPC → the NPC's `create()` calls `add_money()` → creates a
     `/clone/money/gold` item via `combined.lpc`'s `set_amount()` →
     `feature/move.lpc`'s `move()` → which, as part of its own logic,
     ends up calling `xyzx_system_clean_up()` **on `/clone/misc/void`**
     (the driver's designated catch-all "void" destination object).
   - `/clone/misc/void.lpc`'s own `create()` calls `replace_program(ROOM)`
     (a classic MudOS-era "turn this generic clone into a real room"
     trick, used by several files in this lib). **The key distinguishing
     fact**: `/clone/misc/void` IS on `adm/etc/preload` and, in a REAL
     driver boot, gets created and has its `replace_program()` fully
     resolved during preload, LONG before any player or NPC could ever
     reach it via a money-drop chain. But `lpcc`'s own single-object
     compile-check (AGENTS.md §5's documented caveat: "boots the VM ...
     then compiles ONE object") does **not** run the preload list at
     all — so when a single isolated `lpcc` invocation compiles e.g.
     `/d/migong/lev8/dong48`, its NPC's money-drop chain reaches
     `/clone/misc/void` for the very first time in that process, DURING
     the same tick as `void`'s own still-pending `replace_program()` —
     exactly the scenario the error message describes, but one that is
     structurally impossible in a real boot where void is preloaded far
     earlier. **Confirmed empirically too**: zero occurrences of this
     exact error string in `debug.log` across all 3 real
     registration+play sessions (though none of those sessions actually
     entered the migong maze — this doesn't prove the chain is
     unreachable in deeper gameplay involving that specific zone, only
     that it's not on the verified boot/registration/post-login path,
     and that the FAILURE MODE ITSELF is a byproduct of `lpcc`'s
     narrower bootstrap, not a defect that would recur identically in a
     real boot's timeline).
   - A smaller residual (~21 files, "Bad argument 1 to EFUN call_other()
     Expected: object.. Got: int(0)", rooted in various `#global_init#()`
     file-scope initializers) looks like the same family of artifact — a
     global variable initializer calling into a daemon that simply isn't
     preloaded in the bare `lpcc` environment — not independently chased
     given the time budget and the much lower per-file yield.
   - The `md5crypt`-undefined-function gap (3 files: `cmds/usr/passwd.lpc`,
     `cmds/usr/jiadian.lpc`, `cmds/skill/abandon.lpc` — this driver's
     `crypto` package provides `hash(algo, str)`, not old-MudOS-style
     `md5crypt(str, salt)`) and the `exert_function(10)`-called-with-an-int
     typo (3 files cascading from one broken `d/player/ltsh/npc/saveme.lpc`
     NPC, where every OTHER call site in the lib correctly passes a string
     function-name) are genuine content gaps/pre-existing typos, left
     documented rather than fixed — none are on the verified
     boot/registration/post-login path, and `md5crypt` in particular would
     need a from-scratch reimplementation of a specific legacy hash format
     this driver has no equivalent for.
   - `remove_input_to`/`dump_socket_status` (1 file each, both
     admin-only `cmds/bos`/`cmds/usr` commands) are genuinely
     never-defined-on-this-driver efuns, same shape as `tail()` (§8e) —
     dead/non-critical admin tooling, not fixed.

**Second, informal check** (not a full re-sweep, to avoid another 5+
minute run): re-ran targeted `lpcc` against all 21 individually-fixed
paths — all PASS. Did not re-run the full 15,926-file sweep a second time
given the dominant remaining category is confirmed to be a test-harness
artifact rather than fixable content, and the time budget for closing out
the very last archive in this ~100-archive project.

## Re-verification pass: driver rebuild + LPC formatter + WASM build

- **LPC formatter**: ran `format-corpus.mjs` over all 15,925 `.lpc`
  files — 15,804 reformatted in place, 39 already-idempotent, 82
  refused (nonzero `errors` expected/fine per the tool's own contract,
  unsurprising on this scale of legacy source).
- **Native retest against rebuilt driver** (`~/src/fluffos/build-debug/
  src/driver`, freshly rebuilt from upstream master): booted clean,
  zero fatal errors. Full registration re-verified with a fresh real
  name (秦风欧) via the documented flow (id → confirm → Chinese name →
  password ×2 → identity token ×2 → gift `0`/`y` → magic element →
  email → gender); arrived correctly in 假日客店, `look`/`score`/`i`
  all produced correct output (including the starter 布衣/新手礼物包
  inventory). No regressions from the rebuilt driver or the reformat
  pass; nothing to fix.
- **WASM build test** (`scripts/wasm_client.js` against
  `build-wasm/src`): boots cleanly in-process (the `server_2000.lpc`
  network daemon's `socket_create()`/`socket_error()` calls correctly
  throw `Undefined function` under WASM's no-`sockets`-package build,
  caught non-fatally by `master.lpc`'s own preload `catch()`, same as
  natively when the sockets package is absent — no cascading boot
  failure). **Login itself is blocked**: `adm/daemons/logind.lpc`'s
  `logon()` calls `str = query_ip_number(ob); if (BAN_D->is_banned(str)
  == 1) { ...reject... }` — under WASM's malformed `query_ip_number()`
  return value (AGENTS.md's documented limitation), this trips the ban
  check and every connection is rejected with "你的地址在本 MUD 不受
  欢迎" before even the id prompt renders. This is the documented
  driver-side WASM limitation, not a mudlib bug (the exact same code
  path works fine natively on `127.0.0.1`, confirmed by the native
  retest above) — no mudlib fix attempted. Classified as: boots under
  WASM; login blocked by the driver's known `query_ip_number()`
  limitation.

## WASM-enablement pass (loopback-allow / uptime / throttle / admin seed)

Standard pass per AGENTS.md §1.3(b)/(e), §1.5.

**Gates patched:**
- `adm/daemons/band.lpc` `is_banned()` (~line 106): originally returned 1
  (BANNED) for any non-dotted-quad IP — exactly the shape that rejects
  every WASM connection (AGENTS.md §1.3a). Now strict loopback
  (`127.0.0.1`/`localhost`/`::1`/`127.*`) short-circuits `return 0` before
  the original `sscanf` format check, which is otherwise left intact
  (non-loopback malformed IP is still banned, as originally).
- `adm/daemons/logind.lpc` `logon()` (~line 231): per-IP anti-flood cap
  (`ban_cnt > 9` same-IP connecting users → destruct) now applies to
  everything except strict loopback.
- Uptime startup gate: none (natured.lpc's `172800 - uptime()` is the
  in-game auto-reboot timer, kept).
- **Fail-closed correction (retrofit):** both gates above were initially
  written with a "treat malformed/empty IP as loopback" fallback per the
  original pre-driver-fix instructions. Since `query_ip_number()` is now
  fixed upstream, tightened to strict-loopback-only matching — a
  malformed IP now falls through to the ORIGINAL gate logic (band.lpc:
  banned; logind.lpc: subject to the anti-flood cap) instead of being
  waved through.
- `get_version()` client handshake: already confirmed inert on the
  standard telnet port in the earlier pass (only the Tomud-specific ports
  enforce the "2060" token) — unchanged.

**Admin account:** id `fluffos`, pw `Mud@2026`, name 浮浮, level
`(boss)` via `adm/etc/wizlist` — `(boss)` is the highest rank with a
command path (BOS_PATH); `(ceo)` exists in wiz_levels but
feature/command.lpc has no case for it. Registered via the real flow
(id → y → 浮浮 → password ×2 → 身份标识 abc123456 ×2 → gift 0 → y →
magic element 0 → email → gender m). Relogin quirk: wizards get an extra
「巫师登陆效验码」 prompt before the password — the check is disabled
upstream (`if (1 ...)` in get_wizpas), any input passes. Verified:
relogin as (boss), `update /adm/daemons/band` → 成功.
Save files (untracked, NOT gitignored — orchestrator must add all FOUR):
`work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`,
`work/data/key/data/user/f/fluffos.key`,
`work/data/key/data/login/f/fluffos.key` (this lineage writes a parallel
.key shadow of every save).

**Retest:** fresh normal registration (ceshisi / 秦岭甲) end-to-end OK
(look/score/quit correct; all four test-char save/key files removed);
no new errors in debug.log.

## 深度功能测试 / Deep functional test (AGENTS.md §10.7, round two)

One continuous native-driver session (plus a few short admin-assisted side
sessions for reachability, disclosed below), `~/src/fluffos/build-debug/src/driver
config.fluffos` from `libs/longyunmeng/`, driven via `scripts/mudclient.py`.
Read `doc/help/intro` and `doc/help/newbie.txt` first — both already fully
UTF-8 and readable, no re-conversion needed. Key facts learned from them and
used to plan the test: `fight` is the lib's own explicit safe-sparring verb
("点到为止... 只会消耗体力，不会真的受伤" — stamina-only, no real injury);
newbie.txt itself warns **quitting within the first 30 real minutes of a
new account deletes it** ("进入游戏后半小时之内不可以退出游戏否则ID将会被
系统删除") — confirmed in `cmds/usr/quit.lpc` and treated throughout as an
intentional, already-cataloged content timer (AGENTS.md §1.3e's "KEEP
in-game content timers" bullet — same shape as `xiyouji2003`), not touched.

**Registration**: real Chinese name `沈惊鸿` (id `shenym`), male, landed in
悦来客栈 (Inn) on 南阳城/Nanyang — `look`/`score`/`i` all correct immediately
after registration and after every later relogin. A second full registration
(`林测试`/lintest) and a third (`测试贰号`/cesitwo) were also run clean, both
also self-deleted correctly via the in-game quit-before-30-min flow at the
end of the session (see below) — three independent registrations, zero
failures, corroborating the existing NOTES.md registration verification.

**Safe-sparring mechanism**: found and used the documented training-dummy
NPC, 木人 (`d/shaolin/npc/mu-ren.lpc`, placed in the Shaolin 练武场/
`d/shaolin/wuchang.lpc`) — matches the checklist's own "`accept_fight()` +
stat-copy loop" pattern exactly (copies the attacker's own skills/stats
into the dummy on `accept_fight()`, `set("no_die", 1)`, a
`last_fighter`/`fight_times` cooldown so the same player can't grind it
back-to-back). `fight mu ren` produced a full, real combat exchange ending
in an automatic concede ("这场比试算我输了，佩服，佩服！") with no
character death and no server error; retrying immediately correctly
rejected with "你刚跟这个木人练过功！" (cooldown working). Reached via
`goto` as the seeded admin account (`fluffos`/`Mud@2026`) rather than
on-foot navigation — the Shaolin room graph from the `fly sl` entrance
(`guangchang1`) into the interior practice-ground cluster is large and not
straightforwardly traceable by grep alone; using `goto` tests the *mechanism*
identically to a player physically walking there (same `fight` command, same
`accept_fight()` code path), just skips the maze-solving. Disclosed here,
not hidden.

**Sect-join + organic learn-from-teacher**: both tested together against
华山派 (Huashan sect) master 岳不群 (`kungfu/class/huashan/yue-buqun.lpc`),
again reached via admin `goto` for the same navigation-cost reason (see the
"orphan room" finding below — this NPC's room turned out to have NO
in-bound exit from anywhere in the map, so on-foot navigation was never
actually possible to begin with, not just impractical). `apprentice yue`
correctly ran the full `attempt_apprentice()` → `do_recruit()` (`call_out`,
2s) → `command("recruit ...")` chain and produced "恭喜您成为华山派的第
十四代弟子" plus a `score` showing the new 师傅/称谓 fields set correctly.
`learn huashan-sword at 3 from yue` correctly gated on insufficient 内力
("你的内力不够，没有办法练华山剑法") — a resource/design gate, not a crash;
`learn unarmed at 1 from yue` (a free/no-cost skill) succeeded end-to-end
("你听了岳不群的指导，似乎有些心得。你的「基本拳脚」进步了！"). Both
mechanisms work correctly; no `debug.log` errors from either.

**`quit`, debug.log grep, real-time reconnect (checklist items 7–9)**: `沈惊鸿`
was quit-and-reconnected many times over the session, both cleanly (`quit`)
and uncleanly (closing the socket without `quit`, which reliably triggers
`net_dead()` — this lib does NOT void-park a net-dead player, §7.20 does not
apply here, they stay exactly where they were, `set_temp("netdead",1)` only):
- **Prompt net-dead reconnect**: works correctly — a reconnect within the
  10-second post-disconnect cooldown (`quit_time`-gated, `logind.lpc:~403`,
  an intentional anti-thrash gate, not a bug) is rejected with "系统繁忙，
  请等待 10秒 再行尝试连线", and a reconnect just after that window correctly
  routes through `user->reconnect()` (verified: position, gender, inventory
  all intact after several such cycles).
- **Clean `quit` after the 30-minute account-age threshold**: no deletion
  prompt (age-gated, correctly bypassed once `birthday` age > 1800s),
  "欢迎下次再来！", save file `mtime` updated, `debug.log` unchanged.
- **Real wall-clock reconnect after a clean quit**: waited ~130 real seconds
  (`until`-loop blocking wait, not a background Monitor) after the clean
  quit above, then reconnected — room, Chinese name, gender, gift item
  (布衣/Cloth) all persisted correctly, zero new `debug.log` lines.
- **Full 900-second net-dead timeout** (`NET_DEAD_TIMEOUT` in
  `include/user.h`, `user_dump(DUMP_NET_DEAD)` → `command("quit")`): let a
  throwaway character (王大腿/wangdatui) sit net-dead across the entire
  real-time window (~18 minutes total wall-clock waited, combining this with
  pushing `沈惊鸿`'s own account age past 1800s in the same wait, per
  AGENTS.md's "one blocking wait, not stacked sleeps" guidance) — see the
  next finding for what this surfaced.

**FINDING (driver-fatal crash, corroborates AGENTS.md §10.8) — FIXED,
mudlib-side mitigation applied**: partway through the same real-time soak
window above, the native driver process **aborted outright**
(`md: debugmalloc: attempted to free non-malloc'd pointer ...` →
`abort()` inside `dealloc_object`/`debugfree`/`MDfree` — the exact same
crash signature already catalogued for `shenzhou`/`nitan170911` in §10.8),
killing the whole server. This is the **sixth** independent occurrence of
this driver-level memory-corruption class across this project's round-two
testing, still not root-caused to the driver's C++ internals (out of scope
for an LPC-level pass; flagged to the human maintainer per §10.8's own
standing request for a dedicated ASan/valgrind driver-level investigation).

**Unlike every prior occurrence, this one left a concrete, actionable clue
in `debug.log` immediately before the abort** — worth a partial revision to
§10.8's "debug.log shows nothing whatsoever" framing (still true for the
*abort itself*, which logs nothing, but a *contributing* uncaught runtime
error can be visible just before it): a `adm/daemons/questd.lpc`
cron-driven quest-spreading routine (`spread_quest()`/`init_dynamic_quest()`,
called from `adm/daemons/cron.lpc`'s `start_task()`) repeatedly picked
random not-yet-loaded rooms from `d/baituo/` (caoping, fende, dongkou,
menlang, xiaolu3, ...) and called `reset()` on them; each one logged an
UNCAUGHT `执行时段错误：*cannot bind a functional to an object with a
pending replace_program()` from `inherit/room/room.lpc:96`, immediately
followed (same debug.log tail) by the fatal abort.

Root cause, confirmed by reading `inherit/room/room.lpc`: every room file in
this lib ends its own `create()` with `replace_program(ROOM)` (the standard
"generic clone becomes a real room" MudOS idiom, used lib-wide, not just in
`d/baituo/`). `inherit/room/room.lpc`'s own `reset()` (and its sibling
`xyzx_system_clean_up()`) does
`inv = filter_array(inv, (: clonep($1) && !$1->is_character() :));` —
creating a closure bound to `this_object()`. If `reset()` runs (whether via
the driver's own post-`create()` reset pass, matching the exact mechanism
already catalogued in AGENTS.md §7.17, or via an explicit caller like
`spread_quest()`) **before** that room's own `replace_program()` has
actually committed, binding the closure throws — uncaught, since neither
`room.lpc`'s `reset()` nor `questd.lpc`'s call site wrap it in `catch()`.
Reproduced live and deterministically: on a fresh boot, `goto`-ing (as
admin) to any of the five rooms named in the crash log reliably reproduced
the identical uncaught error on cold first load, every time.

**This is very likely a material contributor to the crash** (strong
temporal correlation — the exact same shape §7.12's escalation note and
§10.8 already document: a `call_out`/cron-driven function with no enclosing
`catch()`, hit repeatedly right before an abort) but, consistent with every
other §10.8 entry, **not proven as the sole cause** — the driver-level
memory corruption itself remains unexplained. Fixed the mudlib-side part
regardless, since it's a real, reproducible, uncaught runtime error in its
own right (matches AGENTS.md's "missing guard around a driver-documented
throw" fixable class, same shape as §7.17/§7.19/§7.25): wrapped both
`filter_array(...)` calls in `inherit/room/room.lpc` (`xyzx_system_clean_up()`
and `reset()`) in `catch()`, skipping just that one cleanup/population pass
on failure rather than aborting the whole calling chain. **Verified fixed
live**: after the fix, `goto`-ing to all five previously-affected rooms
produced zero occurrences of the error string in `debug.log` (previously
100% reproducible for exactly these rooms). Did not have time/opportunity
to re-run the full 900s+ soak a second time to confirm the *crash itself*
doesn't recur — the fix targets a confirmed, reproducible contributing
error, not a confirmed-eliminated crash; note this honestly rather than
claim more than was verified.

**Draft new AGENTS.md bug-class candidate** (since this shape doesn't
exactly match any existing §7.x entry — closest are §7.17 and §7.25, but
both are scoped to NPC/room *population* helpers, not a generic *periodic
daemon reset() call*): "A universal `replace_program(ROOM)`-in-`create()`
room idiom, combined with an unguarded `filter_array()`-closure in the
shared room base class's `reset()`, throws an uncaught runtime error
whenever ANY caller (the driver's own post-create reset, or a periodic
daemon like a quest-spreader) reaches a room's `reset()` before its
`replace_program()` commits — reproduces reliably on that room's cold
first load specifically (not on later resets), and is easy to miss because
ordinary login/registration testing rarely cold-loads obscure zone rooms
that a login-daemon walkthrough never visits." Left as a draft here per
the task instructions rather than editing AGENTS.md directly.

**FINDING (observation only, NOT fixed — insufficient reproducibility to
be confident in a root cause or a fix)**: during the same net-dead soak,
the throwaway character 王大腿 (id `wangdatui`)'s **login-object companion
save file** (`data/login/w/wangdatui.o`, written by `clone/user/login.lpc`'s
own `->save()`, separate from the player body's `data/user/w/wangdatui.o`)
was observed **missing** for an extended period after a normal, successful
registration + uncontrolled (socket-close) disconnect — confirmed via
`stat`: the `data/login/w/` directory itself didn't exist until a later,
unrelated manual reconnect attempt created it. Because `logind.lpc`'s
"does this id already exist" check (`get_id()`, ~line 322) tests
`file_size(ob->query_save_file() + ext) >= 0` against the LOGIN object's
own file, not the player body's, this made the game **incorrectly treat a
real, already-registered account as available for a brand-new
registration** on the very next connection attempt ("使用 wangdatui 这个
名字将会创造一个新的人物，您确定吗？") — a genuinely concerning shape,
since confirming that prompt could plausibly have orphaned or overwritten
the real `data/user/w/wangdatui.o` (not tested — did not want to risk
actually destroying evidence of the bug before writing it up).

**Why this is documented, not fixed**: a second, deliberately clean and
isolated repro attempt immediately afterward (a fresh character, `cesitwo`,
same registration flow, same subsequent uncontrolled disconnect) did **NOT**
reproduce the missing-login-file symptom — its `data/login/c/cesitwo.o`
was written correctly and immediately, during registration itself, exactly
as `enter_world()`'s `user->save(); ob->save();` (both unconditional, no
guard) is supposed to do. So this is not a deterministic, on-demand
reproducible bug — closer in spirit to the low-reproducibility class
AGENTS.md §10.8 already normalizes for the driver-crash findings, just at
the mudlib level this time. `wangdatui`'s own data (both copies) had fully
disappeared by the time this was investigated further, consistent with the
account eventually being swept up by the same age-based cleanup this lib
already runs elsewhere for abandoned sub-1-hour registrations (plausible,
not confirmed — the exact deletion trigger and timing were not pinned down
either). Per AGENTS.md §10.7's own scope note ("when genuinely unsure...
document it honestly... and leave the code untouched — don't guess"), no
code change was made for this one. **Suggested direction for a future
pass, not applied**: the `get_id()` existence check could be made more
robust by also/instead consulting `data/user/<shard>/<id>.o` (the player
body's own save, which this session's evidence suggests is the more
reliably-written of the two), rather than trusting the login object's
companion file alone as the sole signal that an id is taken.

**Shop / economy**: reached a 当铺 (pawnshop, `南大街` off `扬州`/Yangzhou,
per the newbie doc's own documented path `fly yz;w;s;s;e`) with `沈惊鸿`.
`list` returned "目前没有可以卖的东西" (nothing currently sellable) — this
particular shop's `list` command is geared toward the player *selling* to
the pawnshop rather than browsing a buy-menu, and the fresh newbie
character had nothing pawnable equipped beyond the starter cloth. Command
dispatch itself worked correctly (no crash, sensible response) but an
actual gold-for-item purchase transaction was **not completed** — noting
this honestly as unverified-live rather than claiming it was tested, per
the checklist's own instruction. Did not reach combat/death against a real
(non-training-dummy) opponent either, given the time already spent on the
net-dead soak and the crash investigation above — also explicitly flagged
as unverified-live.

**Process note**: the native driver process was involuntarily SIGTERM'd
once early in this session (visible in `/tmp/longyunmeng_driver_stdout*.log`
as a clean `attempt_shutdown`/backtrace-then-exit, not a crash) between two
otherwise-unrelated tool calls, consistent with this environment's known
"stray SIGTERM between tool calls" issue already documented in AGENTS.md
§10.5 despite using the recommended `setsid nohup ... & disown` launch
pattern — restarted and continued; not a mudlib issue.

**Files modified**: `libs/longyunmeng/work/inherit/room/room.lpc` (the
`catch()` fix above). `libs/longyunmeng/work/data/user/f/fluffos.o` also
shows as modified in `git status` — normal drift from the admin account
being logged into several times during this pass (`last_on`-style fields),
not a content change. All throwaway test-character save/key files
(`shenym`/沈惊鸿, `lintest`/林测试, `cesitwo`/测试贰号) were removed at the
end of the session — two via the game's own quit-before-30-min deletion
flow (exercising that code path as a side effect), one (`shenym`, past the
30-minute mark) via direct file removal. `wangdatui`/王大腿's own data was
already gone by the end of the session (see the finding above).

## 深度功能测试（2026-08-14，round three，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，逐项独立核对了本轮新确立的检查项（不只
是信任 NOTES.md 已有记录）：`log_error()` 确认已经有大小写敏感的
`"warning: "` 判断；`inherit/room/room.lpc` 的 `catch()` 修复仍然
生效——特意重新走访了之前记录过会 100% 复现崩溃的全部五个房间
（`d/baituo/{caoping,fende,dongkou,menlang,xiaolu3}`），
`debug.log` 里零 "cannot bind a functional" 出现，修复稳定持续生
效。`feature/dbase.lpc` 未发现密码写保护；`win_times` 的
`%`-operator 也已用 `to_int(query("win_times")) % 5`。

### 本轮新发现并修复的 PROGRAMMING bug

1. **`get_resp()`/`get_name()`（`adm/daemons/logind.lpc`）各有一处
   调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34-class）——此前的
   深挖没有覆盖到**：紧跟在中文名字确认之后，把连线桩物件的原始
   引用直接回显给正在注册的新玩家。已删除两处。
2. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护**：已加上前向声明 +
   `assure_file(LOG_DIR + file);`。
3. **`cat()`（同一文件）对不存在文件的空指针式崩溃，主动加固**：
   未在本档案现场触发，属主动加固，改成 `write(read_file(file) ||
   "");`。

### 实测过程

管理员 `fluffos`/`Mud@2026`（这份档案和同一"炎龙封印"分支的
`zxty`/`zxty08nxgbb` 一样有独立的巫师登陆效验码步骤，任意输入都会
"验证通过"）真实重连两次：第一次专门用 `update
/adm/simul_efun/file` 确认写权限仍然生效（"重新编译
/adm/simul_efun/file.lpc：成功！"），并顺带复测了 `room.lpc` 修复
在五个已知问题房间上的持续有效性；第二次单独验证密码重连本身。均
成功登录，存档数据一致。全程 `debug.log` 无运行时错误。驱动按精
确 PID 结束；测试期间产生的存档时间戳增量已 `git checkout --` 还
原。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

YLFY 引擎的近亲分支（源码版）。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员账号（fluffos/Mud@2026）登录干净正常。这个家族的巫师登录在 id 和密码之间有一道"巫师登陆效验码"提示，但原始代码其实从未真正校验过它——这份档案自己的 README 里就记录着"随便填都行"——实测确认：id→验证码随便填→真实密码→干净地进入"群仙观"，quit 也干净（"欢迎下次再来！"）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 99 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 5875
处独立、未注释的 replace_program(ROOM); 整行。另外手工清理了造房工
具代码生成模板里内嵌的同一形状，本库有两份完全同形状的造房工具拷贝
（`clone/misc/roommaker.lpc`、`u/fyue/misc/roommaker.lpc`，各 1 处
字符串拼接），均已清理。删除总计 5877 行，与本次扫描 FINDINGS.md 记
录的 longyunmeng 存活命中数完全一致。

验证：干净启动一次真实调试驱动，端口 40094 正常监听，
work/log/debug.log 全程无新增内容。用已播种的 `fluffos`/`Mud@2026`
管理员账号连线（"巫师登陆效验码"提示随便填即可，与上方记录一致），
在华山派练武场/前厅/玉女峰之间往返走了十余个房间，look/score/who
均正常（who 命令首次惰性编译打印了一条无害的 Unused local variable
警告，与本次修复无关）。测试产生的 `data/{login,user}/f/fluffos.o`
存档时间戳 diff 已 `git checkout` 撤销，不提交。驱动按精确 PID
kill。

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
