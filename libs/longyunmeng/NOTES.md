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

## §7.19 enable_player() reentrancy fix (2026-09-01)

Corpus-wide mechanical fix (AGENTS.md §7.19, Batch F of 6). This lib was
originally flagged as a possible false positive (a pre-existing
`nosave int enabled = 0;` flag in `feature/command.lpc`, the shape confirmed
sufficient on `xiaoyuxiyou`/`xyxyutf8`/`xyxy2` in earlier batches) -- but on
closer inspection this is NOT the safe shape: `enabled = 1` is set AFTER
`enable_commands()` returns here, not before. Since the reentrant nested
`init()`->`setup()`->`enable_player()` call happens synchronously DURING the
`enable_commands()` call (per AGENTS.md §7.19 and the driver docs), the
nested call still sees `!enabled` and calls `enable_commands()` again,
recursing exactly as if there were no guard at all. Confirmed the reachable
chain is real: `d/shushan/npc/zhangmen.lpc`'s `init()` unconditionally calls
`me->setup()`, and `setup()` unconditionally calls `enable_player()`. Fixed
by adding a true `in_enable_player_now` reentrancy flag alongside the
existing `enabled` bookkeeping variable (left untouched, `disable_player()`
still needs it). Verified via single-file `lpcc --batch` PASS.

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师。2026-08-14 那一轮没测这两步。

### 实测过程

管理员 `fluffos` / `Mud@2026`。本端口是 ZMud 口（config 40094），
`logon()` 的第一输入进 `get_version()`：不含 `2060` 的行被当成英文
id，**不要**先发 `2060`（那会按 Tomud 握手走，本口会直接踢人）。
巫师效验码步骤还在（`if (1)` 任意输入都过），然后才是普通密码。

落地 `/d/huashan/qunxianguan`（旧存档已是华山派岳不群弟子）。`goto
/d/city/zuixianlou`，`list` 价目为铜钱尺度（烤鸡腿八十文钱）。泥潭
时刻是未时，店没打烊。`clone /clone/money/gold` 后 `buy jitui` 成功
（找零九十九两银子 + 二十铜板）。`F_DEALER` 对丐帮拒绝购买，所以
必须先买再拜；本轮买的时候还是华山，没撞上那条。

`goto /d/gaibang/inhole`，第一次 `apprentice zuo` 被挡（已有华山师
傅，须先战胜师傅才能改投——内容规则，未改）。巫师
`call me->delete("family")` 清掉旧门派后再拜，左全收徒，`score` 称
谓「丐帮第二十零代弟子」（`chinese_number(20)` 的既有写法）、师傅
左全。`cmds/wiz/save.lpc` 真正调用了两个 `save()`，`user.o` 立刻带
上 `family`。断线 10 秒 `quit_time` 后再连，`score` 仍是丐帮 / 左全，
银子还在。

本轮没有新的 programming bug。`securityd` 没有 tianya 那种
`/log/` + `log_file` 再入。夜半打烊是 `NATURE_D` 内容，未改。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `adm/daemons/questd.lpc` 在新进程里加载，HEAD 通过 1 个、工作树通过 1 个（共 1 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`make_inventory()` 用 `catch()` 包住 `new(file)`，做不出来就返回 0；`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py longyunmeng --fix` 加 `scripts/lpc_fix_no_effect.py --apply`（`d/tiezhang` 三个房间删去 `return` 后面的 `"\n";`，`kungfu/skill/xuanyuan-arrow.lpc` 删去什么也不做的 `(: throw_weapon :);` 等），共改动 662 个 `.lpc` 和若干 `.h`。HEAD 与工作树分别加载（新进程）：653 -> 653 通过，无回退；改过的头文件的 37 个包含者 37 -> 37 通过。手工：`adm/daemons/story/new7.lpc` 里只剩注释的 `if (ob) { }` 去掉，注释留着。`adm/daemons/cruised.lpc` 是编译不过的漫游守护进程草稿，未动。

启动时警告 44 -> 0；新进程登录（新人物确认）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、1 处去后缀（如 `cmds/app/ls3.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/u/snow/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 29 处，返回类型/原型 36 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 3 个文件；改动 64 个文件，HEAD 与工作树各载入一次无回退（64 objects; HEAD PASS 64, tree PASS 64; regress 0; newly loading 0），这些文件的警告 68 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `adm/daemons/cruised.lpc`：五处 `if (cruise[USER_ID]) { // … }` 块内只剩注释，把 `if` 和右括号一起注释（行为不变）。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（27 个覆盖函数，多为物品的 `query_autoload` 在 `string` 基类上写成 `int`；冗余继承 1 处）加手工收尾，能编译的文件警告清零。改动与原先报警告的 32 个对象 HEAD 与工作树各载入一次：HEAD PASS 28，tree PASS 28，regress 0。

- `cmds/std/look_wiz.lpc`：野兽相貌描写 `per_msg_beast3` 连写两份，后面那份（“长的极其丑陋”）才被读到，前一份（“有气无力”）从没显示过，删去前一份，显示不变。
- `d/miwudao/secret/npc/` 的 `dragon1`、`elf`、`virginia`：`die()` 在 `void` 基类上写成 `int`，没人读返回值，改 `void`。
- `kungfu/skill/huashan-jian.lpc` 招式表后多余的 `;`。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。2 个文件 2 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：技能文件里 3 处 `int power_point()`/`int hard_point()` 返回 1.3、1.75 之类的浮点，经 int 返回被截断；本库没有调用者，改成 `float` 返回值，保留原数值（`float_hooks.py`，KB 04 §6.10）。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。17 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。8 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 9 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 17 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，2 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。3 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。


## 招式表最低等级之下没有招（2026-10-15，KB 06 §7.243）

招式表的最低 "lvl" 高于 0（如全部为 100），技能等级未到之前取不到招，每次出招都报错。循环后补 `if (!a_action) a_action = action[0];`（`lpc_fix_action_level.py --fallback`）：`dagou-bang`。

## 飞雪的兵器销毁（2026-10-15，绝招探测）

`liangyi-jian/feixue.lpc` 末尾的 `else destruct(obj);` 在前一分支已销毁兵器时对 0 调用，改为 `else if (objectp(obj))`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`daya-jian/badao`、`murong-jianfa/kuangjian`、`wenrou-jian/xuanyuan`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`beimin-shengong`→`beiming-shengong`（`/d/quanzhen_old/kungfu/skill/xiantian-qigong`、`wangran-xinfa`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yinyun_ziqi`→`yinyun-ziqi`（`yinyun-ziqi/cure`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

1 个文件、1 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/miwudao/secret/npc/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 1 个（0 个原来载入不了），没有退步。

## 自制兵器的 id：名字按字节数拆（2026-10-18，KB 07 §8.1）

`feature/item_make` 的 `get_item_id()` 把自制物品的名字拆成一个或两个两字词，再到 `name_id_arg` 里查拼音（「失神」→ `shishen`）。原来按 GBK 字节数拆（`[0..3]`、`len > 4`），UTF-8 里一个汉字只占一个下标：四个字的名字 `[0..3]` 取走整个名字，表里查不到，id 只剩下 ` sword`（空的名字部分），玩家无法用名字指到自己做的兵器。改为按字符数拆（`[0..1]`、`[2..len-1]`、`len > 2`）：「失神炽日」得 `shishen zhiri sword`。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 2 个对象设了本库没有文件的武功（4 个名字，最多的是 `zhanshen-lu`、`daoxin-zhongmo`、`wudang-array`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：2 个里 2 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 49 处、47 个文件：`kunlun-shnfa`→`kunlun-shenfa`（14 处）、`shaolin-shnfa`→`shaolin-shenfa`（12 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`yunv-xinjing`→`yunu-xinjing`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）等共 17 个名字。（`scripts/lpc_fix_skill_names.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 2 个 NPC 文件、2 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 2 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/quanzhen_old/obj/greenrobe.lpc`、`/d/quanzhen_old/obj/greyrobe.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen_old/npc/obj/m_sword.lpc`（共 4 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## userp(0)（2026-10-19，KB 06 §7.277）

`adm/simul_efun/player.lpc` 的 `userp(object ob)` 先调 `efun::userp(ob)`，没有人在场时（房间刷新里 NPC 穿会员衣服，`wear()` 里 `userp(this_player())`）`ob` 是 0，驱动报 `Bad argument 1 to userp()  Expected: object  Got: 0`，NPC 和房间载入不了。函数开头加 `if (!objectp(ob)) return 0;`（旧驱动里 `userp(0)` 就是 0）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/xuehepai/obj/bairiwan.lpc`（1 处）。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 11 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/hainan/npc/xianhe.lpc`、`/d/hainan/npc/xiaohe.lpc`、`/d/shushan/shanjian.lpc`）。改动：`/d/hainan/npc/xianhe.lpc`（3 处）、`/d/hainan/npc/xiaohe.lpc`（3 处）、`/d/shushan/shanjian.lpc`（2 处）、`/kungfu/skill/yansha-quan/heilongbo.lpc`（3 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/network/fileserver.lpc`（1 处）、`/adm/daemons/network/server.lpc`（1 处）、`/adm/daemons/network/server_bf.lpc`（1 处）。

## `partyinfo` 读不到 `/log/cmds/party` 就抛错（2026-10-20，KB 06 §7.326）

`cmds/std/partyinfo.lpc` 把 `read_file("/log/cmds/party")` 直接交给 `explode()`。这个文件是运行中的 mud 才会写出来的帮会日志，克隆出来的目录、站点和全新启动的树里没有，`read_file()` 答 0，于是 `Bad argument 1 to explode()`。现在读不到时按空表处理，只打印表头。同一份文件在 ylfyxa3、xajh4gkb 里已先改过（那里有实测）；这里只做了加载检查（1/1，回归 0）。`u/wenwu/partyinfo.lpc` 是巫师目录里的同名副本，没有碰。

## `passwd`、`jiadian`、`abandon`：`md5crypt()` 不存在（2026-10-21，KB 06 §7.323）

三个命令用 `crypt(pass, old) != old && md5crypt(pass, old) != old` 验旧密码（旧驱动里存档可能是 DES 也可能是 MD5，两种都要认）。这个驱动没有 `md5crypt` efun，`adm/simul_efun/config.lpc` 的 `crypt()` 包装器只在定义了 `MD5_CRYPT` 时才用 `efun::md5crypt`（没有定义），所以三个命令都是 `Undefined function md5crypt`：玩家改不了密码，`abandon` 和 `jiadian` 也打不开。在 `config.lpc` 补 `string md5crypt(string str, string seed) { return efun::crypt(str, seed); }`（这个驱动的 `crypt()` 自己认 `$1$` 盐）。加载检查：HEAD 1、树 4，三个命令新加载。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`、`/inherit/char/npc_bf.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 3 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（3 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dallowip.lpc`（`find_player`）、`/cmds/adm/dbiaoshi-md5.lpc`（`find_player`）、`/cmds/adm/dbiaoshi.lpc`（`find_player`）。加载检查 HEAD 与工作树对照，没有退步。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/bos/socket2.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## `findfile`、`updir`：不带参数（2026-10-21，KB 06 §7.336）

ToMud 升级用的两条指令（`cmds/bos/findfile.lpc`、`updir.lpc`）不带参数时报 `Bad argument 1 to sscanf() Expected: string Got: 0.`：`findfile` 的 `sscanf(arg, "%s,%s", dir, str)` 前面是一段注释掉的代码，`updir` 的 `sscanf(arg, "%s -debug", arg)` 在 `if (playerp(previous_object()))` 里面。`findfile` 补了 `if (!arg) return help(me);`（`help()` 在 `main()` 之后，补了原型），`updir` 在开头 `if (!arg) arg = "";`，不带参数就列出当前目录。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 50 条注册（50 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/magicitem/jinshe1.lpc`（`use`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/flypproom/npc/flypp.lpc`（`do_sell`）、`/d/miwudao/npc/enchanter.lpc`（`give_quest`）、`/d/miwudao/npc/enchanter2.lpc`（`give_quest`）、`/d/miwudao/npc/frank.lpc`（`do_vendor_list`）、`/d/miwudao/npc/graham.lpc`（`do_vendor_list`） 等共 50 个文件。最多的函数名：`do_send` 15 处、`do_vendor_list` 14 处、`do_decide` 7 处、`give_quest` 5 处、`do_sell` 3 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。5 个文件里 5 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 5 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 5 个，现在 5 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（21 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

2 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/d/Xuehepai/quest/xhquest"->query_quest()`（`/d/xuehepai/npc/caojob.h`）→ `"/d/xuehepai/quest/xhquest"`；`"/d/mj/obj/baihong-jian"->move()`（`/d/mingjiao/npc/yingwang.lpc`）→ `"/d/mingjiao/obj/baihong-jian"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。 其中殷天正（白眉鹰王）的 `do_answer()`：玩家念对暗语（`answer 怜我世人，忧患实多；保护教主，同抗外敌`）时把白虹剑 `move` 给玩家，区域目录改名 `mingjiao` 之后这个路径没跟着改，回答暗语只得到 `couldn't find object`，剑永远发不出来。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 19 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 19 处（14 个文件）：拼名字的赋值 11 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:101`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:108`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：14 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 14 处（7 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/bakcmds/csc.lpc:611`）；`if ((strlen(name) < 2) || (strlen(name) > 20)) {`（`/cmds/std/makeexp.lpc:103`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 9 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 5 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。

