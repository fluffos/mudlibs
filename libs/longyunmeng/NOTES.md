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
"炎龙封印"-themed libs: `xiyangzaixian3` (#48, 夕阳再现III之炎龙封印) and
`yanlongfengyin_xiaoao3` (#68, 炎龙封印-笑傲江湖3阿飞站). Both archives (binary
AND source) self-identify their engine family via literal top-level
directory names `xyzx/ylfy` ("XYZX" = pinyin initials of 夕阳再现/"Sunset
Reappears", "YLFY" = pinyin initials of 炎龙封印/"Flame Dragon Seal") — the
exact same macro-naming convention documented in `yanlongfengyin_xiaoao3`'s
own NOTES.md.

**md5sum/diff comparison against `master.c`, `chinese.c`, `securityd.c`**
(the exact files the task brief named):
- `adm/obj/master.c`: 544 lines here vs 375 in `xiyangzaixian3`'s copy (NOT
  the same revision) but **544 lines, near-byte-identical** to
  `yanlongfengyin_xiaoao3`'s copy — `diff --strip-trailing-cr` shows only
  CRLF/whitespace noise plus ONE extra credit-comment line
  (`// ...每次啟動MudOS時報一次 By Wenwu`, present here, absent in
  `yanlongfengyin_xiaoao3`'s copy). This "By Wenwu" signature matches the
  binary archive's own `说明文档.txt`, which credits the whole lib to
  `By 龙云梦(Wenwu)` — i.e. this archive is Wenwu's own further-tweaked build
  of the same engine core `yanlongfengyin_xiaoao3` is descended from, not an
  independent rewrite.
- `adm/simul_efun/chinese.c`: **byte-identical** (0 diff lines after
  stripping CR) to `yanlongfengyin_xiaoao3`'s copy.
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
descendant of the same XYZX/YLFY engine family as `xiyangzaixian3` and
`yanlongfengyin_xiaoao3` — sharing byte-identical core files in places
(chinese.c) and near-identical ones in others (master.c), but with its own
evolved registration daemon and its own content tree (~19.5K files vs
`yanlongfengyin_xiaoao3`'s 17.4K) — not a rebrand or a simple content-only
fork of either sibling. Diffing whole `raw/` trees pairwise wasn't
attempted (would be a large, low-value effort given the daemon-level
comparison above already answers the lineage question conclusively); the
registration-flow fixes below were ported from `yanlongfengyin_xiaoao3`
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
   Annihilator@Eastern.Stories` credit, same family as `yanlongfengyin_xiaoao3`'s
   and `shujian2008`'s) with no func-based compile allowlist. Added the
   standard early-return `switch(func) { case "load_object": case
   "recompile_object": case "include": return 1; }` ahead of the euid/ACL
   checks — otherwise the driver's own compile-time reads of any
   never-preloaded `/adm`/`/cmds` object, attributed to a fresh
   pre-authentication connection's `(player)` status, would be denied the
   first time the registration flow lazily touches one. Ported directly
   from `yanlongfengyin_xiaoao3`'s fix #5 (same securityd.lpc lineage,
   confirmed via the md5sum/diff comparison above that the underlying ACL
   logic — not just the wizard-name personalization — is unchanged).
5. **AGENTS.md §15s** — `adm/simul_efun/message.lpc`'s `tell_room(ob, str,
   exclude)` passed a possibly-unset `exclude` (int `0`, not an array)
   straight into `message()`'s 4th argument in its common 2-arg call form;
   `shout(str)` passed `this_player()` (which can be `0`) as the exclude
   arg too. Fixed both to `exclude || ({})` / `this_player() || ({})`.
   Same exact wrapper shape as `yanlongfengyin_xiaoao3`'s fix #7 (and the
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
   insurance, matching the same conclusion `yanlongfengyin_xiaoao3` reached.
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
    a heredoc's closing tag" gotcha** (already known from `xiyangzaixian3`/
    `tianxia`/`yanlongfengyin_xiaoao3`) — recurred verbatim in the SAME 3
    files as `yanlongfengyin_xiaoao3` (`d/heimuya/shenggu.lpc`,
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
    `yanlongfengyin_xiaoao3`. Confirmed nothing references it by path, then
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
    same exact file/typo already documented in `xiyangzaixian3`'s NOTES.md)
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
    II-lineage `jinyongqunxiazhuan2008`-family libs' own `bowl.lpc` this
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
  shape already documented for `yanlongfengyin_xiaoao3`).
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
