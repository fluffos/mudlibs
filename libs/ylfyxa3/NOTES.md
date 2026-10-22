# ylfyxa3 — 炎龙封印·笑傲江湖 (阿飞站)

Archive: `炎龙封印-笑傲江湖3阿飞站.rar` (archive #68). Port: **40062**. Status:
**done** (boots clean, full registration flow verified end-to-end twice —
once per gender — both reaching the actual game world with real Chinese
names; a driver segfault found and fixed; lpcc sweep 99.95% pass).

## What this is / lineage

The extracted root (`raw/炎龙封印-笑傲江湖3/`) self-identifies via its own
`configs.cfg` as `name : 炎龙封印` ("Flame Dragon Seal"), and the live boot
banner shows a compound name: `「夕阳再现」之「笑傲江湖」` ("Sunset Reappears" —
the underlying engine family name — branded as "Laughing in the Wind" for
this particular site). `adm/obj/` layout (`master file : /adm/obj/master`,
`simulated efun file : /adm/obj/simul_efun`), MudOS v21-era config, root
found directly at the archive's top level (no nesting). ~16,182 `.c` files
before rename (17,380 raw files total, several of which are a bundled
Windows/Linux `fluffos32`/`fluffos64` prebuilt driver binary + `.bat`
launchers — ignored, we use our own driver build).

**Lineage check requested by the task brief**: this archive's title shares
the term "炎龙封印" with archive #48 (`xyzx3`,
"夕阳再现III之炎龙封印"). Compared core files directly:

- `master.lpc`'s `get_player_fname()`/`connect(int port)` shape and the
  exact error message text (`"现在有人正在修改使用者连线部份的程式，请待会再来。"`)
  match xyzx3's master.lpc almost verbatim — confirming a REAL
  shared root lineage (the "XYZX"/夕阳再现 engine family; `#define
  XYZX_YLFY_DEBUG`-style macros and `XYZX_NAME_1`/`XYZX_NAME_2` config keys
  in this lib's own `logind.lpc` spell out "XYZX" = pinyin initials of
  夕阳再现, "YLFY" = pinyin initials of 炎龙封印 — self-confirming the family
  name).
- **However this is NOT a near-duplicate/simple rebrand** the way some
  other same-titled pairs in this project turned out to be identical or
  near-identical: `master.lpc` (544 vs 375 lines), `chinesed.lpc` (307 vs
  220), `logind.lpc` (1867 vs 882 — **more than double**), `securityd.lpc`
  (304 vs 124) are all substantially larger/heavily rewritten compared to
  xyzx3's copies. The live boot banner itself explains why: `"该
  版本由阿飞在碎梦修改的炎龙端基础上，再次修改，已不同于原先的炎龙版本了。"`
  ("this version was further modified by 阿飞/Afei based on 碎梦/Suimeng's
  own modified 炎龙[Yanlong] branch — already different from the original
  Yanlong version"). So: same ultimate engine root, but a separately/
  heavily forked descendant with its own registration-flow shape, its own
  securityd ACL, and its own bugs — **only the `is_chinese()` §15h shape
  was directly portable verbatim from xyzx3; everything else
  (master.lpc, securityd.lpc, logind.lpc's whole callback chain, the
  double-slash NPC-equip bug, the crash) needed independent discovery.**
- `xyzx3`'s §15q client-version gate (hardcoded literal `"2060"`)
  **does recur here**, but in a meaningfully different, PORT-gated shape —
  see "Registration flow" below; it did not need porting since our port
  assignment transparently bypasses it rather than requiring the literal
  reply.

## Fixes applied (with why)

1. **AGENTS.md §15h** (proactive, per assignment brief) —
   `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte check
   (`str[0] > 160 && str[0] < 255`, `strlen>=2`) → CJK codepoint check
   (`str[0] >= 0x4e00 && str[0] <= 0x9fff`, `strlen>=1`).
   `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count bound
   `< 2 || > 10` → character-count bound `< 1 || > 5` (matches what the
   error message already promises — "1 到 5 个中文字"); removed the
   `i%2==0 &&` even-byte-offset gate so every character position is
   checked, not every other one.
2. **AGENTS.md §15p** (proactive) — checked `adm/etc/preload`: DNS/intermud
   daemon was **already commented out in the raw archive itself**
   (`#/adm/daemons/network/dns_master`), nothing to do. Also grepped for
   inline DNS_MASTER calls reachable from the login/display path per
   §15ab's extension of this rule: `logind.lpc`'s `logon()` has exactly one
   such call (`DNS_MASTER->query_doing_end()`), but it's **already
   commented out by the original author** (with their own comment "这段没
   鸟用" — "this part is useless"). No action needed, confirmed by reading
   the source, not assumed.
3. **AGENTS.md §14** — `master.lpc`'s `valid_override(file, name)` upgraded
   to the 3-arg form (`file, name, main_file`), checking `main_file ==
   SIMUL_EFUN_OB/MASTER_OB` in addition to `file`, so an `efun::` override
   inside a file `#include`d into `simul_efun.lpc` is still recognized as
   trusted.
4. **AGENTS.md §8d/§15o** — `master.lpc` had **no** `get_include_path()` at
   all. Added the standard shape (prepends the compiling file's own
   directory, `":DEFAULT:"` for everything else). Found 35+ files (mostly
   `d/obj/quest/*.c`, `#include <task.h>` with a sibling `task.h` in the
   same directory) that need this for any live/mid-connection compile;
   `convert_lib.sh`'s own local-angle-bracket-to-quote pass (§8d's simpler
   half) had *already* converted all of these to `#include "task.h"` during
   the automated conversion step, so `get_include_path()` here is mostly
   insurance for anything that pass might have missed, not something that
   was independently required to fix a live failure.
5. **AGENTS.md §15n** — `adm/daemons/securityd.lpc` has a genuinely custom
   ACL (`trusted_read`/`exclude_read` mappings, `Annihilator@Eastern.Stories`
   credit — same family as `shujian2008`'s custom securityd), with no
   func-based allowlist. Added the standard `switch(func) { case
   "load_object": case "recompile_object": case "include": return 1; }`
   early-return to its `valid_read()`, ahead of the euid/status checks —
   otherwise the driver's own compile-time reads of any never-preloaded
   `/adm`/`/cmds` daemon, attributed to a fresh pre-login connection object
   with `(player)` status, would be denied by the `exclude_read` table the
   first time the registration flow touches one.
6. **AGENTS.md §15w** — `master.lpc`'s `log_error()` displayed EVERY
   message reaching it (including ordinary compile *warnings*, not just
   real errors) to `this_player(1)` prefixed with the alarming "编译时段
   错误：" ("compile-time error:"). Gated the player-facing broadcast on
   the message NOT containing the substring `"warning: "` (verified exact
   casing against `compiler.cc`'s `d.is_warning ? "warning: " : "error: "`),
   still logging everything to file either way.
7. **AGENTS.md §15s** — `adm/simul_efun/message.lpc`'s `tell_room(ob, str,
   exclude)` passed a bare unset `exclude` (int `0`, not an empty array)
   straight into the `message()` efun's 4th argument when called in its
   common 2-arg form (453 call sites in this lib); same shape for `shout()`
   passing `this_player()` (which can be `0`) as the exclude arg. Fixed
   both to `exclude || ({})` / `this_player() || ({})` — this driver
   requires that argument to be omitted, an object, or an object array.
8. **AGENTS.md §3 counterexample** — the blanket `static`→`nosave` sed
   (part of `convert_lib.sh`) rewrote 13 files' `log_file("static/XXX",
   ...)` string-literal path arguments to `log_file("nosave/XXX", ...)`
   (this lib uses a real, pre-existing `/log/static/` directory as a
   log-file naming convention, confirmed present on disk —
   `work/log/static/`). Reverted all 13 occurrences (`grep -rl '"nosave/'`
   → `sed -i 's/"nosave\//"static\//g'`) back to the correct path.
9. **New variant of the same static/nosave collision family (§15z-shaped,
   but with an extra twist)** — `include/globals.h` had:
   ```c
   #ifndef __SENSIBLE_MODIFIERS__
   #define nosave nosave
   #define protected nosave
   #else
   #define private protected
   #define nosave nosave
   #endif
   ```
   Confirmed via the boot log's own `#define` dump that **this FluffOS
   build DOES predefine `__SENSIBLE_MODIFIERS__`** (`src/local_options:35`),
   so the `#else` branch (not the `#ifndef` one) is the one actually
   compiled in here — meaning `#define private protected` would be ACTIVE.
   That's independently wrong on this driver regardless of the §3 sed:
   `private` is its own real, distinct `L_TYPE_MODIFIER`
   (`DECL_PRIVATE`, `lexer_utils.cc`) on this build, not merely an alias
   for `protected` the way it may have been on whatever older driver this
   shim targeted. Neutralized the WHOLE shim (both branches deleted, no
   replacement macros) rather than trying to preserve a "corrected"
   version of either branch — `nosave`, `protected`, and `private` are all
   independently correct, real keywords here and need no translation.
10. **NEW bug, and the likely root cause of a driver segfault** — a
    pre-existing double-leading-slash typo, `carry_object("//clone/cloth/
    ...")` (confirmed present in the RAW pre-conversion archive too, not
    conversion fallout), found in **31 `kungfu/class/*` NPC files** (famous
    Jin Yong characters: 岳不群/Yue Buqun, 宁中则/Ning Zhongze, 何足道/He
    Zudao, 卫四娘/Wei Siniang, 鲁有脚/Lu Youjiao, etc.) plus one more
    instance in `adm/daemons/logind.lpc`'s under-18-first-reconnect
    free-clothing gift (`new("//clone/cloth/pink_cloth")`). The extra
    leading slash caused `new()`/`carry_object()`'s inner `new(file)` to
    fail with `*Read access denied.` (confirmed the target files exist and
    load fine under their correct single-slash path). Fixed all 32 sites
    (`sed 's#carry_object("//#carry_object("/#g'` across the 31 files +
    one manual fix in `logind.lpc`).

    **Why this mattered beyond the NPCs' own equip failures**: the FIRST
    boot session (before this fix was discovered/applied) segfaulted the
    whole driver process a few minutes after "Initializations complete.",
    with a C++ stack trace rooted in `apply_low()` (`vm/internal/
    apply.cc:201`, dereferencing a `shadowed` object pointer) reached via
    a `call_out`-triggered simul_efun call (`adm/daemons/natured.lpc`'s
    day/night-cycle `update_day_phase()`/`event_sunrise()`/`jobd.lpc`'s
    `get_job()`, both of which touch the exact NPCs affected by this bug —
    `/d/dali/npc/liumang` and `/kungfu/class/huashan/yue` — immediately
    beforehand in the log). The precise mechanism (how a failed
    `carry_object()`/`new()` on one of these NPCs leaves behind a
    dangling/corrupted object whose later `call_out` callback walks an
    invalid `shadowed` pointer) wasn't fully root-caused at the C++ level,
    but the correlation is strong and the fix is cheap and independently
    correct regardless. **Verification**: rebooted with the fix applied,
    ran two full registration flows, then left the driver running
    (idle, past the point the previous crash occurred in wall-clock terms)
    for 6.5+ minutes straight — zero crashes, zero new `debug.log` lines
    at all after boot. Not a 100%-certain proof (the natural-cycle daemon's
    exact next trigger time is data-driven and wasn't pinned down further),
    but a strong positive signal given the timing/content correlation.
11. **NEW bug — mixed-encoding comment eating the following `set_name()`
    call**, found in 4 files (`d/tianlongsi/npc/xiaoshami.lpc`,
    `d/hangzhou/honghua/shi.lpc`, `d/mr/npc/xiaotong.lpc`,
    `d/gaochang/npc/tuying.lpc`): each has a `//2016.5.22阿飞调整NPC属性`
    comment written in **UTF-8** while the surrounding file is GBK
    (confirmed via raw hex inspection: the comment's bytes are valid
    3-byte UTF-8 sequences, decoding a completely different — and here,
    coincidentally still Chinese-looking — text than what GB18030 would
    produce from the same bytes; this is the `§15y`-shaped "mixed
    encodings in one file" gotcha, just UTF-8-inside-GBK rather than
    BIG5-inside-GBK). Decoding the WHOLE file as GB18030 (correct for
    99% of it) hits an invalid byte sequence inside this one comment,
    triggering `convert_lib.sh`'s `iconv -c` lossy fallback — which, per
    the already-documented encoding gotcha, ate the **real adjacent
    newline** right after the comment along with the invalid bytes,
    merging the comment onto the SAME line as the following `set_name(...)`
    call. Since `//` comments run to end-of-line, this **silently deleted
    the entire `set_name()` call** for all 4 NPCs — their `id`/`name` were
    NEVER set. Symptom: `*Bad argument 1 to set_living_name() Expected:
    string Got: 0` whenever a room spawned one of these NPCs and called
    `enable_player()` (via `feature/command.lpc`), affecting 5 downstream
    rooms too (`d/tianlongsi/{qingxinge,wulege,wujingge,wuwoge,wuchangge}`,
    `d/hangzhou/liuhe4`, `d/mr/c14-5`). A 5th file with the exact same
    garbled-comment marker (`d/city/npc/ping.lpc`) was checked and found
    to NOT have this problem (its `set_name()` is correctly on its own
    line) — confirming the corruption is per-file/positional, not a
    blanket effect of the marker's mere presence. **Fix**: re-inserted the
    missing newline right after the comment's mojibake tail in each of the
    4 broken files (Python script matching the mojibake tail string
    `灞炴` and splitting the line there). Verified via targeted `lpcc`
    calls: all 4 NPCs + their 7 dependent rooms now PASS.
12. **AGENTS.md's documented "iconv -c eats the adjacent real newline
    before a heredoc's closing tag" gotcha** — recurred in 3 files under
    `d/heimuya/` (`shenggu.lpc`, `tang.lpc`, `npc/tang.lpc`), all flagged
    "LOSSY conversion" by `convert_lib.sh`. Same exact shape as documented
    for `xyzx3`/`tianxia`: `@LONG ... 神彩奕奕.LONG );` (or
    similar) with the closing `LONG` tag glued onto the last text line.
    Fixed by re-inserting the missing newline before each `LONG` tag.
13. **Genuine pre-existing typo, unrelated to conversion** —
    `doc/mudlib/efuns/shiwu.lpc` (a real room, "小石屋", despite living
    under the `doc/mudlib/efuns/` path) had `call_out(do_close,0);` — a
    **bare, unquoted** function-name identifier instead of a string
    literal, so the compiler tried (and failed) to resolve `do_close` as a
    variable (`error: Undefined variable 'do_close'`). Fixed to
    `call_out("do_close",0);`.
14. **AGENTS.md §12** (orphaned non-LPC `.c` file caught by the blind
    rename) — `doc/mudlib/efuns.lpc` is a plain-text listing of efun names
    (documentation index: "acos add_action all_inventory ..."), not a
    single line of LPC, and isn't referenced anywhere. Renamed to
    `doc/mudlib/efuns.txt`.
15. **Mechanical, already handled by `convert_lib.sh` automatically** (no
    manual intervention needed, verified after the fact): the literal
    `".c"` quote-fixer already turned `master.lpc`'s `preload()` function's
    `file_size(file + ".c")` check into `file_size(file + ".lpc")`
    (otherwise every single preload entry would have silently been
    skipped, since after the rename no `.c` file exists anymore) and fixed
    `F_MOVE`'s `"/feature/move.c"` macro definition in `globals.h` to
    `.lpc`. Confirmed both are correct in the final `work/` tree by
    direct inspection.

## Confirmed NOT needed (and how confirmed)

- **§4** (master `valid_read`/`valid_write` lazy `load_object` recursion
  risk): both applies in `master.lpc` only do `find_object(SECURITY_D)` —
  no `load_object()` call anywhere in either. Read the full source
  directly; no guard needed.
- **§15l** (`destruct(SIMUL_EFUN_OB)` in master's `create()`): `create()`
  is a single `write("master: 成功加载.\n");` line, nothing else. Confirmed
  by reading the function body.
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both present in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID` respectively.
- **§8e** (missing `tail()` efun): grepped the whole tree for `\btail(` —
  zero real LPC call sites (only doc-text mentions of the word "tail" in
  `doc/help/wizcmds`/`doc/mudlib/efuns/tail`).
- **§15 / the nitan-family bare-simul_efun dbase architecture bug**:
  `feature/dbase.lpc` (inherited by `char`/`room`/etc via `F_DBASE`) has
  real, local `set`/`query`/`delete`/`add` methods backed by a
  `F_TREEMAP`-based mapping — the architecturally correct pattern, not the
  bare-simul_efun-call footgun. Grepped the whole converted tree for
  `efun::set(`/`efun::query(`/`efun::delete(`/`efun::addn(`/`efun::tail(` —
  zero hits. No `named.c`/`named.lpc` file exists anywhere in this lib.
  This lineage (ES/Annihilator/XKX-descended "XYZX" engine) never had this
  bug class to begin with.
- **§15q** (hidden client-protocol-version gate): read `logind.lpc`'s full
  `logon()`→`get_version()`→`get_id()`→`confirm_id()`→`get_name()` callback
  chain before scripting any test. There IS a gate — `get_version()`
  checks the very first input against a pattern embedding the literal
  `"2060"` (a Tomud-protocol handshake code) — but unlike xyzx3's
  unconditional version, this one is **gated on `query_ip_port(ob)`
  matching one of the original archive's hardcoded `TOMUD_1`/`TOMUD_2`
  port numbers (6000/9999, read from `/data/config/system.h`)**. Since
  this project assigns each lib a single unique port (40062, never equal
  to 6000/9999), an ordinary telnet connection's `query_ip_port()` never
  matches, so the code takes the "not-Tomud-port" branch and validates the
  first input directly as the real English id — **no magic string needed
  at all for our setup**. Confirmed empirically: the registration
  transcripts below never had to send "2060".
- **§8c-shaped footgun**: `master.lpc`'s own `valid_read` DOES reassign
  `user = previous_object()` unconditionally when the passed-in `user` is
  defined (a related but distinct footgun from the classic `this_player()`
  version) — but it degrades to `return 1` (allow) whenever
  `previous_object()` isn't an object, and in practice never produced a
  single "Read access denied" in either full registration test's
  `debug.log` (zero new lines logged past boot in both runs). Not fixed
  since it never manifested as a live bug; noted here for whoever revisits
  this lib.
- **§8f** (bare `TYPE * a, b;` comma-list array-star bug): spot-checked
  several matching declarations across the lib; none surfaced as an lpcc
  or interactive-test failure. Not blanket-fixed, per AGENTS.md's own
  "fix what a real failure surfaces, not everything a regex matches"
  guidance for this pattern specifically.
- **§13-shaped content gaps** (documented, not fabricated): `d/quanzhen/
  cangjingge2.lpc` references `__DIR__"obj/bookshelf"`, which doesn't
  exist anywhere in the archive (its sibling `npc/qiuchuji` does exist);
  `doc/mudlib/efuns/shiwu.lpc` (the room, see fix #13 above) also
  references a missing `npc/yang`; `clone/magic/lightman.lpc` sets a skill
  `"magic-light"` that has no corresponding skill definition anywhere;
  `adm/etc/preload` lists `/adm/daemons/preload` as a daemon to load, but
  no such file exists on disk at all (harmless — `master.lpc`'s own
  `preload()` already guards with a `file_size(...) == -1` early return
  for exactly this case).
- **Isolated-lpcc-only false positives** (§6b): `d/kaifeng/obj/blade2.lpc`,
  `d/hangzhou/obj/jiasha.lpc`, `d/npc/m_weapon/weapon/m_whip.lpc`,
  `d/npc/m_weapon/weapon/m_staff.lpc` all fail ONLY when `lpcc` compiles
  them as an isolated top-level object (no real connected player, so
  `this_player()` is `0`, and `wizardp(0)`/`0->set_skill(...)` throw) —
  each is legitimately only ever created interactively by a real wizard/
  player (custom weapon-naming, admin item-creation), confirmed by reading
  each file's own logic. Not bugs.
- `adm/daemons/network/server.lpc` (the whole intermud/DNS network-daemon
  family): fails standalone (`socket_bind()` bad argument) but is never
  preloaded and unreachable in this environment — same standing policy as
  every other lib's DNS/intermud subtree.

## Config

`config.fluffos`: `port number : 40062`; the original 4-port multi-protocol
setup (`external_port_1..4`, telnet 4000/5555/6000/9999 for
ZMud/ToMud-specific client handshakes) commented out — see the §15q
write-up above for why a single ordinary port is not just acceptable but
actually *simpler* to test against here. `mudlib directory` pointed at the
absolute `work/` path; `log`/`binaries`/`adm/tmp` directories created.
`maximum evaluation cost` was already `10000000000` in the original
config — no bump needed (unlike several other libs in this batch whose
original value was too tight for this driver's real-time-microsecond
semantics). A handful of "obsolete config key" warnings
(`binary directory`, `swap file`, `wombles`, `warn tab`) print at every
boot — harmless, matches several other already-done libs' configs, not
cleaned up.

## Registration flow — read before testing, not assumed

Read `logind.lpc`'s actual `logon()`→`get_version()`→`get_id()`→
`confirm_id()`→`get_name()`→`new_password()`→`confirm_password()`→
`new_biaoshi()`→`confirm_biaoshi()`→`select_gift()`/`get_gift()`→
`get_email()`→`get_gender()`→`enter_world()` callback chain in full before
writing any test script. Two gotchas found this way, both avoided in the
final test:
- The very first prompt (`get_version()`) doubles as the real
  English-id prompt for any port other than the hardcoded Tomud ports (see
  above) — send the id directly, no "2060" handshake needed.
- Selecting the random-gift option (`0`) at the "0-4" prompt does **not**
  auto-accept the rolled stats — it calls `get_gift(" ", ...)`, which
  (since `" "[0]` isn't `'y'`/`'Y'`) takes the "reject and re-roll" branch
  and asks "您同意这一组天赋吗？" (do you accept this set?) — a **separate
  y/n confirmation** is required before the flow proceeds to email/gender.
  (First test attempt sent a plain `"0"` with no follow-up `"y"` and got
  stuck in an infinite re-roll loop, silently consuming every subsequent
  scripted `--send` as another rejected answer — corrected by adding an
  explicit `"y"` after the gift-selection digit.)

### Full transcript outcome — run 1 (male)

One continuous `mudclient.py` connection:
`qinfengsan` (English id, no digits — the `"qinfeng2"` id containing a
digit was rejected by `check_legal_id`'s letters-only rule in an earlier
attempt, unrelated to any bug) → confirm `y` → **real Chinese name `秦风`**
(accepted, no rejection — confirms the §15h fix) → password `abc12345`
(twice) → identity token `abc123456` (twice) → gift selection `0` → accept
`y` → email `test@test.com` → gender `m` → **entered the actual game
world**: room "悦来客栈" (Yuelai Inn) near 南阳城 (Nanyang), full room
description with an NPC (店小二, waiter) and a exits list rendered
correctly, welcome messages and a "新手礼物包" starter gift item granted.
Save files confirmed written and correctly UTF-8: `data/user/q/
qinfengsan.o` contains `"name":"秦风"` verbatim, uncorrupted. Zero new
`debug.log` lines during the entire flow (still exactly 209 lines, same as
right after boot).

### Full transcript outcome — run 2 (female, post-crash-fix reboot)

Rebooted with all fixes (including the double-slash crash fix) applied,
ran a second full flow from scratch: `qinfengsi` → confirm `y` → real
Chinese name **`秦岭`** (accepted) → password/identity-token setup →
gift `0`/`y` → email → gender `f` → entered a **different** starting room
("客栈"/inn on 西大街/West Main Street, near a different NPC 丁三) and
received the correct gender-specific gift item ("粉红绸衫", pink silk
robe). Again zero new `debug.log` lines. Driver then left running idle
for 6.5+ minutes afterward with no crash (see fix #10's writeup) —
`data/user/q/qinfengsi.o` confirms `秦岭` saved correctly.

## Driver-process notes for whoever reviews this

The FIRST boot attempt (before the double-leading-slash equip-typo fix was
discovered) segfaulted the whole driver process a few minutes after boot,
rooted in a `call_out`→simul_efun→`call_other`→`apply_low`'s
shadow-pointer-chain walk (see fix #10). This was diagnosed from the raw
stdout capture (`Stack trace (most recent call last):` + a C++ backtrace
through `vm/internal/apply.cc:201`), not from `debug.log` (a process-level
segfault doesn't get a chance to write an LPC-level error there). After
applying the fix and rebooting, two full registration flows plus 6.5+
minutes of idle runtime produced no further crash — treated as sufficient
verification given the strong content/timing correlation (the exact two
NPCs referenced in the `debug.log` lines immediately preceding the crash
were both instances of the very same typo).

Both driver launches used the tool's own `run_in_background`-equivalent
foregrounding via a subshell + `echo $! > pidfile` (not `nohup ... &
disown`, though that pattern is also documented as reliable in
AGENTS.md) and were killed by their exact recorded PID
(`kill 2200142` for the first crashed session's already-dead PID cleanup,
`kill 2252883` for the second/final session) — no broad `pkill -f`
pattern was used at any point, since other agents' driver processes were
confirmed running concurrently on this host throughout this session (own
process list showed at least 2 other `build-debug/src/driver` instances
at various points, e.g. archives #67/#71 in progress).

## lpcc sweep

16,181 files (16,182 minus the one `.txt`-renamed doc file) swept with
`scripts/lpcc_check.sh`. **First run** (before any of the content fixes in
#10-#13 above): 16,149 pass / 33 fail (99.8%) — memory pressure from lpcc
`--batch`'s single-VM-for-everything design pushed this 23GB host down to
~1.1GB free during the run's tail end (concurrent sibling agents were also
running sweeps at the time); per AGENTS.md §6b, killed the process once
the actual compile phase had visibly finished (all 16,181 `=====` markers
present in the raw log) rather than let it proceed into its own
post-compile profiling/trace-dump phase, which is what was actually
driving the runaway memory use, not the compile work itself.

Triaged all 33 original failures, fixed 23 (the `set_name`-swallowing
comment bug, the `heimuya` heredoc-newline bug, and the double-slash equip
typo, all detailed above) and confirmed each fix via a fast **targeted**
`lpcc` call per affected object (not a second full batch sweep, to avoid
repeating the same memory-pressure risk) — all 23 now individually PASS.
Re-ran the FULL sweep once more anyway (memory had fully recovered by
then, ~16GB free) to get a real, complete, fresh number rather than rely
on arithmetic: **16,173 / 16,181 = 99.95%** pass, with the same kill-after-
compile-phase discipline applied again (compile phase finished cleanly at
~6.4GB free, well above the danger zone this time). The remaining 8
failures are exactly the confirmed-not-a-bug categories from the section
above: 3 genuine missing-content gaps (`cangjingge2`, `shiwu`'s missing
`npc/yang`, `lightman`'s missing skill), 4 isolated-compile-only false
positives (no real player), and 1 dead/unreachable DNS daemon file.

## Files touched (for reference)

- `include/globals.h` — neutralized the `nosave`/`protected`/`private`
  compatibility shim (fix #9); `F_MOVE`/`SECURITY_D`/etc `.c`→`.lpc` macro
  fixes were automatic via `convert_lib.sh`.
- `adm/obj/master.lpc` — `log_error()` warning-gate (#6), `valid_override`
  3-arg (#4), added `get_include_path()` (#4), `preload()`'s
  `file_size(...)` extension fix was automatic.
- `adm/daemons/securityd.lpc` — `valid_read()` func-allowlist (#5).
- `adm/simul_efun/chinese.lpc` — `is_chinese()` (#1).
- `adm/daemons/logind.lpc` — `check_legal_name()` (#1), one double-slash
  fix (#10).
- `adm/simul_efun/message.lpc` — `tell_room()`/`shout()` (#7).
- 13 files (`adm/obj/master.lpc`, `adm/daemons/securityd.lpc`,
  `cmds/adm/promote.lpc`, `cmds/adm/purge.lpc` (×2), `cmds/adm/setskill.lpc`,
  `cmds/adm/call.lpc`, `cmds/usr/inicki.lpc`, `cmds/usr/quitfyup.lpc`,
  `cmds/bos/quittest.lpc`, `cmds/usr/quit.lpc`, `adm/daemons/cron.lpc`,
  `d/liandan/xdan/dan11.lpc`) — reverted `"nosave/XXX"` log-path literals
  back to `"static/XXX"` (#8).
- 31 `kungfu/class/*` NPC files + `adm/daemons/logind.lpc` — double-slash
  `carry_object`/`new` fix (#10).
- `d/tianlongsi/npc/xiaoshami.lpc`, `d/hangzhou/honghua/shi.lpc`,
  `d/mr/npc/xiaotong.lpc`, `d/gaochang/npc/tuying.lpc` — restored the
  swallowed `set_name()` call (#11).
- `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`
  — heredoc closing-tag newline (#12).
- `doc/mudlib/efuns/shiwu.lpc` — `call_out()` string-quote fix (#13).
- `doc/mudlib/efuns.lpc` → renamed to `doc/mudlib/efuns.txt` (#14).

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  16181 `.lpc` files in `work/`; 16149 written, 32 already-conformant,
  0 errors. **Found and fixed the same `::PARENT_FUNC(...)` line-wrap
  corruption bug documented in this pass's `yanhuangwuhun`/
  `yhyxs` NOTES.md entries** (a real bug in the
  formatter itself, not lib-specific) in **19 files here** — the
  largest count of any lib in this batch: 5 `clone/armor/xunzhang*
  .lpc`/`xiongka1.lpc` files' `wear()`/`unequip()` (10 occurrences), 12
  `clone/suit/jianming/jm-*.lpc` files' `wear()`/`unequip()` (24
  occurrences), `d/obj/sword.lpc`'s `wield()`/`unequip()` (2
  occurrences), and `clone/misc/board.lpc`'s `capitalize(::query("id"))`
  (a `return (: : query("id")\n)\n+ ")"` variant, distinct shape from
  the `if (::FUNC())` pattern but the same root corruption). All 19
  fixed by restoring the exact original `::FUNC(...)` call + brace/
  paren structure (verified against the pre-format git blob for each),
  then re-ran the formatter over just those files, which now formats
  them correctly (confirming the bug is specifically the line-wrapped
  variant of `::`, not `::` in general). Given the volume, wrote a
  small one-off Python script to apply the identical `wear()`/
  `unequip()`/`wield()` fix mechanically across all 18 same-shaped
  files at once, after manually verifying the fix on the first one.
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted clean (zero fatal `debug.log` errors) after the formatter-bug
  fixes above. Full registration re-verified with a real Chinese name
  (秦波, id `qinbob`): id/confirm/name/password/identity-token/gift-
  selection(`0`+`y`)/email/gender all completed, landed in 悦来客栈
  (南阳城) exactly as the original pass found, complete with the
  starter-gift welcome message; `look` re-displayed the room, `score`
  produced a correct full character sheet, and the "注册不满 30
  分钟退出将删除账号" warning correctly appeared at `quit` (matching
  documented behavior, not a bug). Zero debug.log errors.
- **WASM**: booted cleanly (only the expected non-fatal `sockets`-
  package preload noise). Registration is **blocked immediately** by
  this lib's own IP site-restriction check: `adm/daemons/logind.lpc`'s
  `logon()` does `str = query_ip_number(ob); if (BAN_D->is_banned(str)
  == 1) { ...你的地址在本MUD不受欢迎... ; destruct(ob); }` — since
  `query_ip_number()` doesn't format correctly under this WASM build
  (documented driver-level limitation, not a mudlib bug), the
  malformed string spuriously matches `BAN_D`'s ban check and every
  connection gets rejected before the username prompt. This is
  **exactly** the documented, acceptable `query_ip_number()`-under-WASM
  limitation described in AGENTS.md's WASM section — confirmed by
  reading the exact code path, not just inferred. **Not patched**, per
  the standing instruction not to "fix" this driver-level gap in the
  mudlib. Native play is completely unaffected (verified above).
  **UPDATE (WASM-enablement pass): now patched** — see next section;
  the exact gate identified above (`BAN_D->is_banned()`'s dotted-quad
  sscanf() falling through to "return 1"=banned on a malformed IP) now
  short-circuits to "allowed" for loopback first, so this should
  unblock WASM registration (needs a WASM re-test to confirm — not
  re-run this pass since the local `build-wasm` binary wasn't
  rebuilt during this session; native retest below is complete).

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. This lib had
not been touched by any previous pass (fresh `git status`, no existing
「管理员账号」section) — full pass done from scratch.

Gates found + patched:

- `adm/daemons/band.lpc` `is_banned()` (~line 106) — **this was the
  documented WASM-fatal gate** identified in the note above: the
  function opened with `if (!site) return 1;` then
  `if (sscanf(site, "%s.%s.%s.%s", ...) != 4) return 1;` — i.e. any
  string that isn't a clean dotted-quad (what a malformed
  `query_ip_number()` under WASM produces) fell straight into
  "banned". Added a loopback short-circuit `return 0;` at the very top
  (before the `!site`/sscanf checks), fail-closed per the 2026-07-24
  driver-fix correction: only `site == "127.0.0.1"`, `"::1"`, or a
  `"127."` prefix qualify — a genuinely malformed/empty string still
  falls through to the original `return 1` (banned), unchanged.
- `adm/daemons/logind.lpc` — added `is_loopback_conn(object)` helper
  and exempted loopback from two per-IP throttles that are NOT routed
  through `band.lpc`:
  - `logon()`'s `ban_cnt > 1` "too many connections from this IP right
    now" cap (~line 238).
  - `get_id()`'s `ip_cnt > 9` "too many players from this IP" cap
    (~line 317, only reachable for non-`is_welcome()` ids — matches
    the family's usual whitelist-then-cap shape).
  - No live `uptime()` startup-grace gate — the only `uptime()` check
    in `logon()` (~line 129) is already commented out in the original
    archive; left as-is, noted only.
  - `BAN_D->is_banned(query_ip_number(ob))` at `logon()`'s top
    (~line 141) needed no separate guard: `band.lpc`'s own
    `is_banned()` fix above already covers it.
  - Did NOT touch `BAN_D->vaild_allow_address()` (called from
    `get_passwd()`) — that gate enforces a PLAYER's own opt-in
    `allowip` address whitelist (a content feature, not hosting
    protection), and already defaults to "allowed" (`return 1`) when
    the player hasn't set one, so it needs no loopback carve-out.

Admin account seeded: id `fluffos`, password `Mud@2026`, identity
string (身份标识, used only for password recovery, cannot be changed)
`fluffosid2026identity`, Chinese display name 浮浮 — this lineage takes
the Chinese name as a single field (no surname/given-name split), so
no name-collision workaround was needed. Granted `(boss)` — the top
rank in this lineage's `wiz_levels` table, same as the existing
`afei (boss)` entry — via `fluffos (boss)` appended to
`adm/etc/wizlist`; restarted the driver to pick up the new entry (read
at `securityd.lpc`'s `create()`). Verified: real registration flow
(fluffos/y/浮浮/[pw]×2 — note: an off-by-one `y`/name-confirm send in
my first test transcript was harmlessly absorbed by the password
length check and self-corrected, see raw transcript if replaying this
exactly)/[identity]×2/0/y/[email]/m → entered 客栈; relogin as fluffos
→ `update /adm/daemons/band` → "重新编译 /adm/daemons/band.lpc：成功！",
`quit` → "欢迎下次再来！".

Retest: fresh normal registration (id `qintestchar`, name 秦风, gender
m) end-to-end — `look` showed correct room, `score` produced a full,
correctly-rendered character sheet (膂力/悟性/根骨/身法/福缘/容貌 etc.),
confirming the player-body class and data model both work; hit the
documented "new account, quit within 30 min deletes it" content prompt
on `quit` (expected, kept per policy — this is game design, not a
hosting gate). Test character save removed afterward
(`data/user/q/qintestchar.o`, `data/login/q/qintestchar.o`). Zero new
`debug.log` errors across the whole session (boot + two registrations +
two admin logins + retests).

**Save files for the orchestrator to add** (none gitignored, normal
add):
- `libs/ylfyxa3/work/data/user/f/fluffos.o`
- `libs/ylfyxa3/work/data/login/f/fluffos.o`

## WASM 修复摘要（迁移自 meta.json 的 group_note）

XYZX/YLFY 引擎的更大改动分支。状态已从过时的 limited 修正——这份档案自己的 README 和 group_note 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，'★ 您目前的权限：(boss)'，quit 正常。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 62 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

先读 `doc/help/newbie.txt`：本档案（阿飞在"碎梦"炎龙分支上再次深改）的核
心玩法是"挂副本、刷经验、自练技能"，与同为 §11"XYZX/炎龙封印分支"的
`xyzx3`/`longyunmeng` 那种早期"拜师即起步"的传统流程明显不同——这个差
异不是测试失误，而是这份档案自己的既定设计（见下）。此外确认：本站三
个连接端口（4000/5555/6000/9999）均非本项目分配的 40062 端口，`get_
version()` 的"2060"客户端暗号门槛不会命中（同 NOTES.md 上方 WASM 段落
已记录），英文 id 直接进普通注册流程；新号半小时内退出会被删号（README
已载，站方明确设计，未触碰 `cmds/usr/quit.lpc`）。

### 修复的程序性 bug

1. **§7.11（`log_file()` 未确保目录存在，注册必崩）**：`adm/simul_efun/
   file.lpc` 的 `log_file()` 是裸 `write_file(LOG_DIR + file, text)`，
   `logind.lpc::get_gender()`（角色创建的最后一步，紧接在性别选择之后）
   调用它写 `/log/login/newid.log`，该目录在 `work/` 里不存在——现场复
   现：第一次注册测试角色（`ylfydeep`）在选完性别后卡在裸 `>` 提示符，
   `look` 返回"什么？"，`debug.log` 记录
   `*Wrong permissions for opening file /log/login/newid.log for
   append."No such file or directory"`，与本 session 内 jqxz2015→
   xyzxfk→xyzxfy2→xyzx3 这 4 次连续命中的 §7.11 崩溃现场完全一致（本次
   是第 5 次，第一次出现在"XYZX/炎龙封印分支"内部但与其它三支代码分叉
   较大的这个"阿飞"改版身上，进一步印证这是跨血统、跨分支的通病，不是
   某一支代码库特有）。修法与既有惯例一致：把 `assure_file()` 挪到
   `log_file()` 之前（本驱动编译器要求同文件内被调函数先声明/定义），
   `log_file()` 内部改为先 `assure_file(LOG_DIR + file)` 再
   `write_file()`；同一 `adm/simul_efun/file.lpc` 里的 `cat()` 也顺手
   加固（见下）。用重新注册的第二个测试角色（`ylfydeeptwo`）验证：性
   别选择后正常落地悦来客栈，`/log/login/newid.log` 成功写入，
   `debug.log` 全程零新增错误。
2. **`cat()` 对不存在文件的空指针式崩溃**：同一文件里的 `cat(string
   file)` 在 `file_size(file) == -1`（文件不存在）时会走
   `write(read_file(file))` 分支，`read_file()` 对不存在的文件返回 `0`
   （非字符串），传给 `write()` 会在 `receive_message()` 层触发运行时
   错误——与本 session 在 `xyzx3` 上刚确认过的同一类问题（该 lib 的
   `cat()` 实现细节不同但病灶相同：未检查 `read_file()` 的返回值）。本
   档案里暂未现场触发（未找到会 `cat()` 一个不存在文件的调用路径），
   属主动加固，修法同样是 `write(read_file(file) || "")`。
3. **§7.34（登录流程遗留调试 `printf("%O")` 泄漏原始对象路径）新增确
   认实例**：`logind.lpc` 的 `get_resp()`（接受系统随机中文名分支）和
   `get_name()`（自定输入中文名分支）都各有一行裸 `printf("%O\n", ob)`，
   在设置角色中文名之后、密码提示之前，把 `/clone/user/login#9` 这样的
   驱动内部对象路径直接输出给玩家——第一次注册测试时现场观察到
   （"楚风烈" → 紧接着一行 `/clone/user/login#9`）。两条并列路径的同一
   行遗留调试输出，与 §7.34 已记录的"接受系统建议名 vs 自己输入名"两条
   平行分支各带一份同款 `printf` 的模式完全一致（`fy330`/`fy2mg`/
   `wmkj`/`jhfy2` 等实例）。两处均已删除，已在 AGENTS.md §7.34 补充这
   第二个"XYZX/炎龙封印分支"内的确认实例。

### §8.9 食物/饮水初始化——不适用

直接读 `logind.lpc::enter_world()`（第 1007 行起）确认：`if (user->
query("age") == 14)` 已经用的是 `user`（真正的玩家 body），不是 `ob`
（登录桩对象）——本档案这处从一开始就是对的，不是本 session 反复遇到
的那个 bug，未改动。（这份 UI 的 `score` 面板本身也没有食物/饮水条位
——采用不同的资源展示模型，"气"/"精"另计，不影响判断。）

### 测试覆盖

- **注册**：英文 id `ylfydeeptwo` → 中文名 **秦风烈** → 密码 `abc12345`
  （×2）→ 身份标识 `qinfenglietwoid2026`（×2，找回密码专用、不可改，
  README 已注明）→ 天资随机 `0`（膂力17/悟性19/根骨20/身法24）→ 邮箱 →
  性别 `m` → 落地南阳城「悦来客栈」，赠送布衣。`look`/`score`/`i` 均正
  常；`score` 面板显示门派/命中/闪避/招架等本档案自有的独立数值体系，
  与 XYZX 主干的"气/精/食物/饮水"条完全不同，符合该档案"深改版"定位。
  全程 debug.log 零新增错误，确认 §7.11 修复解决了注册必崩问题。
- **新手礼物**：`doc/help/newbie.txt` 文档路径 `fly yz;w;n;w;pick
  gift;chai gift` 实测语法不支持分号连写（每条须单独发送），逐条执行后
  在武庙成功 `pick gift`（自动拆开，天资 17/19/20/24 → 47/49/50/54，
  潜能涨至 10 万）；`chai gift` 提示"呀~你该已经拿过了吧~"（武庙自己
  另有一份公共礼物已被拿过，属正常内容分支，非 bug）。
- **安全切磋**：`fight.lpc` 自带 help 文本同样声称"点到为止，只会消耗
  体力，不会真的受伤"，但读 `d/city/npc/mu-ren.lpc::accept_fight()`
  发现：这个木人会把挑战者自己的技能等级、内力/精力/属性全部复制到自
  己身上（"镜像对手"设计），`no_die` 只保证木人不会被打死，**并不保护
  挑战者本人**——用 (boss) 管理员账号（`goto /d/city2/wuchang`，因为
  这里没有类似少林山门那样的进入门槛）实测 `fight mu ren`：一轮較长
  的你来我往之后被木人一记"非常可怕的严重抓伤"（577点）打到"半昏迷状
  态"、"眼前一黑"（陷入昏迷）；等待约 10 余秒后自动"慢慢地你终于又有
  了知觉...."恢复，`score` 确认死亡次数仍为 0、状态完全正常——确认这
  是一个会自我恢复的"较量落败"惩罚状态，不是真实伤害或死亡，符合"点
  到为止"在更宏观意义上的设计初衷（消耗但不致命），只是字面上"不会真
  的受伤"这句 help 文本与实际的"可能被打到昏迷"体验有出入——**判定为
  文案与实现的语气不完全一致，不是程序 bug，未改动**。冷却期内重复
  `fight mu ren` 正确被拒绝（"你刚跟这个木人练过功！"）。
- **技能习得（管理员快捷路径）**：`cmds/adm/setskill.lpc` 已是正常的
  `.lpc`（无 §7.94 问题），`setskill ylfydeeptwo force 1`/`150` 均现
  场验证成功写入，`skills` 面板确认对应技能等级更新。
- **技能习得（正规/组织路径）——拜师门槛过高，改测自练**：尝试
  `apprentice yue`（华山派掌门岳不群，`goto /d/huashan/qunxianguan`
  到达）：`cmds/skill/apprentice.lpc` 第 41-44 行的经验门槛公式
  `me_exp < (ob_exp² + 100) / (ob_exp + 5000)`，岳不群 `xyzx_sys/level`
  硬编码 4000，换算门槛约等级 1778，任何等级为 0 的新角色都不可能满
  足——现场复现管理员账号也被拒绝（"就你这种实力还想拜师？我不收无能
  之人。"），换查过本档案 `kungfu/class/huashan/` 目录下所有具名弟子
  最低等级门槛也要约 571（`linghu.lpc`，等级 2000）。**结论：具名拜师
  在这份档案里根本不是新手起步流程的一部分**，与 `newbie.txt` 自己强
  调"自练技能"（而非"先拜师"）的说法互相印证，不是测试环境问题，也不
  是 bug，是这份"阿飞深改版"的既定设计取向（副本刷级优先于传统拜师）。
  改测该档案自己文档记载的正规自练路径：`cmds/skill/exercise.lpc`
  （"打坐吸气"提升基本内功）要求 `force` 技能先达到 100 级（第 30 行
  `me->query_skill("force", 1) < 100` 门槛），用 setskill 先补到 150
  后，`exercise 20` 在北大街（无 `no_fight` 限制的房间）成功执行，收
  到"你坐下来运气用功...你运功完毕"的完整流程反馈；此前在武庙尝试
  `exercise`/`practice` 均被房间的 `no_fight`/`enable` 限定条件正确拒
  绝（"这里是是非之地，不可久留" / "你只能练习用 enable 指定的特殊技
  能"），均为设计内网关，未改动。
- **退出/重连**：`quit` 触发本档案自己的"半小时内退号删账号"规则（
  README 已载），选 `N` 取消；改用断开原始 socket 连接（模拟净断线）
  代替，等待约 10 分钟真实时间后用同一 id/密码重连，提示"重新连线完
  毕"，`skills` 确认 `force` 等级 150 完整保留、所在房间未变。
- **未测试/超出范围**：完整 900 秒 `NET_DEAD_TIMEOUT` 净断线软测试
  （本轮时间预算内用更短的真实等待代替，未做满 900 秒）；副本
  （instance dungeon）实际进入与掉落验证（该玩法是本档案核心内容但需
  要远高于新手初始等级的资源投入，超出单次 §10.7 测试窗口）；当铺购
  买全流程。

### 进程卫生附注

清理了一次由本轮测试期间 cron 驱动的门派仇杀世界事件（"明教"vs"少林
派"广播）连带触发的 `data/npc/menpai.o`/`menpai1.o` 状态文件漂移
（与本次修复无关的背景世界模拟状态），已用 `git checkout HEAD --` 还
原到测试前的内容，未纳入本次提交。

### WASM 未验证说明

按本 session 约定：`emsdk` 固定从 `storage.googleapis.com` 拉取，被本
session 出站代理策略拒绝（`curl -sS $HTTPS_PROXY/__agentproxy/status`
返回 403），WASM 编译/运行验证本轮继续跳过，仅做原生驱动（linux-debug
预设，ASAN/UBSAN）下的完整 §10.7 测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测。核对上面记录的所有修复（§7.11
`log_file()`、`cat()` 空指针加固、§7.34 printf 泄漏、`log_error()`
severity 判断）逐项确认代码仍然生效；`win_times` 的 `%`-operator 也
已用 `to_int(query("win_times")) % 5`（`d/city2/npc/refereew.lpc:149`）；
`feature/dbase.lpc` 未发现 tybxjh/wlhd 那种密码写保护，不适用。管
理员 `fluffos`/`Mud@2026`（无需身份标识，登录只用密码）真实重连验
证两次：落地此前保存的地点，"最后对手：木人"等历史状态完整保留，
`score` 显示"【布衣平民】"头衔，`debug.log` 全程干净。驱动按精确
PID 结束；测试期间产生的存档时间戳增量已 `git checkout --` 还原，
本轮无需新代码改动。

## 深度功能测试（2026-08-19，round four：当铺全流程 + 完整 900 秒净断线）

针对 round two 遗留的三项未测项目中的两项做补测（副本进入/掉落仍按任
务要求跳过，超出单次测试窗口）：当铺（典当行）完整购买/典当/赎回/
卖断流程，以及完整 900 秒 `NET_DEAD_TIMEOUT` 净断线软测试（此前只用
约 10 分钟真实等待代替过）。全程用管理员 `fluffos`/`Mud@2026` 与既有
测试角色 `ylfydeeptwo`（秦风烈，密码 `abc12345`）操作，`log/debug.log`
在整个测试窗口（含 900 秒等待）始终保持 209 行，零新增错误。

### 当铺（d/city/dangpu，NPC 唐楠 `tang.lpc`，经 `feature/dealer.lpc`）

用管理员账号 `clone /clone/weapon/gangdao`（钢刀，原始 value 1000，
`set_name` 的 id 是 `blade` 不是文件名 `gangdao`，用 `blade` 才能被
`present()` 找到）逐一验证：

- `value blade` → "一柄钢刀价值十两白银。如果你要典当(pawn)，可以拿
  到六两白银。如果卖断(sell)，可以拿到八两白银。"（60%/80% 报价公式
  与 `feature/dealer.lpc::do_value()` 代码一致）。
- `sell blade` → 实际支付八两白银（80% of 1000），玩家身上正确生成
  `silver_money` 物件。
- `pawn blade` → 实际支付六两白银（60% of 1000）；`check` 在"已典当
  过东西"状态下正确列出典当清单；`redeem blade` 按原价 1000 扣款并
  归还物品，物品与 `pawns` 清单联动正确。
- **普通杂物卖断后不会进入唐楠的可购清单，是设计不是 bug**：
  `do_sell()` 尾部对 `value < 100000` 的物品会 `destruct(obj)`，只有
  `xyzx_save_item`/`owner_id`/`zhubao_save`（宝石类/绑定动态物品）或
  value ≥ 100000 的贵重物品才会保留供其他玩家 `buy` 回。现场把测试武
  器的 `value` 临时改成 200000（管理员 `call blade->set("value",
  200000)`）验证：卖断后 `list` 正确显示、`buy blade` 正确按其
  `value`（200000，不打折）扣款并拿回物品——完整验证了"当铺确实卖东
  西"这条路径本身没有问题，只是绝大多数便宜杂物走的是"当铺回收即销
  毁"分支，这与 hell 档案那次典当行误判（普通商店不支持 `sell` 被误
  判为 bug、后被撤销）性质相反但同源：都是"这一支代码本身自洽的既定
  经济设计"，未改动。
- **重要经济设计说明（非 bug，记录以免下次测试误判）**：`sell`/
  `pawn` 的收款走 `feature/dealer.lpc::pay_player()`，直接在玩家身
  上生成实体 `gold_money`/`silver_money`/`coin_money` 物件；而
  `buy`/`redeem` 走 `feature/finance.lpc::can_afford()`/`pay_money()`
  （项目内所有商人共用），检查/扣的是玩家 `money`/`more_money` 两个
  抽象属性——也就是 `score` 面板上的"钱庄存款"。这两套货币**不会自
  动互通**：卖/当得到的实体铜钱必须先拿到钱庄柜台（`feature/
  banker.lpc`，本档案是 d/city/qianzhuang 的 NPC 钱眼开）用
  `deposit <数量> <gold|silver|coin>` 存进钱庄余额，才能在任何商铺
  `buy`/`redeem`。现场完整验证：卖断得到的一百十六两黄金+当铺赎回
  剩下的十四两白银，`deposit all gold`/`deposit all silver` 后
  `score` 面板"钱庄存款"正确更新为"一百十六两黄金二十四两白银"，随
  后 `buy blade`（200000 价）在 dangpu 成功扣款拿回武器。这是本档案
  故意的双层货币设计（另有 `withdraw`/`convert`/`zhuan` 转账指令），
  未改动、未上报为 bug。
- **观察记录（非 bug，未改动）**：在唐楠这里从未典当过任何东西时，
  裸 `check` 命令会被一个完全无关的全局 `check`（`cmds/std/
  check.lpc`，丐帮专属"打探他人技能"指令）接管，显示"只有乞丐才能
  打探别人的技能！"而不是唐楠自己的"客官并未在本店典当过任何物品"提
  示；典当过东西之后再 `check` 则正确显示唐楠自己的清单。根因：
  `do_check()` 在无典当记录时 `return notify_fail(...)`，
  `notify_fail()` 求值为 0，LPC 的 `add_action` 语义把返回 0 当作"未
  处理"，继续尝试同一动词绑定的下一个处理函数，于是落到了
  `cmds/std/check.lpc`。没有崩溃、没有 debug.log 报错、没有数据损
  坏，只是空典当记录这一特定情形下提示语不对题——按本轮任务的严格判
  定标准（无编译/运行时错误即视为内容而非 bug）未修复，仅记录。

### 完整 900 秒 NET_DEAD_TIMEOUT 净断线测试

先读代码确认预期行为：`clone/user/user.lpc::net_dead()` 在
`call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD)`
（`include/user.h` 定义 `NET_DEAD_TIMEOUT` 为 900）；`user_dump()` 的
`DUMP_NET_DEAD` 分支无条件执行 `command("quit")`（`in_input`/
`in_edit` 只影响是否额外广播一条房间提示，不影响是否退出）；
`cmds/usr/quit.lpc` 在非交互（`!interactive(me)`）且账号年龄 ≥ 3600
秒时走正常退出收尾（不触发"注册不足一小时删档"分支，`ylfydeeptwo`
账号已存在多轮，远超一小时）。预期：净断线满 900 秒后角色应被强制
`quit`（对象被 `destruct`），此后重连应该是"账号已存在、正常直接进
入游戏"的全新会话，而不是 `reconnect()` 那种"重新连线完毕"的续接。

实测：`ylfydeeptwo` 登录确认（落地"假日客店"，`score`/`skills` 显示
`force` 技能等级 1、潜能 100000、钱庄存款一两黄金），记录断线发起的
精确 unix 时间戳后，直接断开原始 socket（不发 `quit`，真实模拟净断
线）。之后**真实阻塞等待了完整 900+ 秒**（未用任何缩短的替代等待）。
900 秒时间点到达后：

- `debug.log` 全程保持 209 行，无新增错误——净断线本身与后续强制退
  出都没有触发任何运行时报错。
- 重新用同一 id/密码连线：**没有出现"重新连线完毕"提示**，而是走了
  完整的"欢迎光临"banner→会员资格→权限等级→上次连线信息→房间描述→
  新手礼物提示的全新登录流程——这正是 `logind.lpc` 里
  `find_body(id)` 找不到存活对象、退回 `make_body()`+`restore()` 分
  支时才会出现的输出形状，证明旧的净断线角色对象**已经被 900 秒后
  的 `user_dump` 强制 `quit`（destruct）**，而不是仍挂在内存里等待
  重连。
- 存档完整性确认：`skills`（`force` 等级 1、其余技能等级不变）、
  `score`（潜能 100000/>100%、钱庄存款一两黄金）与断线前完全一致，
  证明净断线→超时强制退出→重连整个链条没有丢数据、没有状态损坏。
  落地房间从"假日客店"变成了"最後乐园"（VOID）——核对
  `logind.lpc::enter_world()` 代码确认这是因为该测试角色存档里从来
  没有 `startroom` 字段（`!stringp(startroom = user->query
  ("startroom"))` 时随机取 `start_room[i]` 四个候选之一），断线前后
  两次都命中了这个"无有效存档房间→随机新手房"分支，与本次净断线超
  时逻辑本身无关，是该角色存档的既有状态，不是本轮引入或发现的新
  问题。
- 结论：**900 秒 `NET_DEAD_TIMEOUT` 行为符合代码预期，完整验证通
  过，本轮完成了完整真实等待，没有用缩短等待代替。**

### §7.90/§7.111/§7.112/§7.113/§7.114/§7.115 标准清单巡检——本档案均已干净

- §7.90（eval-cost）：`config.fluffos` 的 `maximum evaluation cost`
  仍是 `10000000000`，未回退。
- §7.111（`master.lpc::standard_trace()` 的 `file_name(error["object"
  ])` 未加保护）：`adm/obj/master.lpc` 第 198-199 行已是
  `error["object"] ? file_name(error["object"]) : "0"`，已加保护。
- §7.112（`death_stage` 重连/重复调度的 `call_out` 叠加）：
  `d/death/npc/wgargoyle.lpc`/`bgargoyle.lpc` 在 `call_out
  ("death_stage", ...)` 前已有 `query_temp("death_stage_active")` 防
  重入判断。
- §7.113（净断线重连后 `heart_beat` 未恢复）：`clone/user/
  user.lpc::reconnect()` 无条件 `set_heart_beat(1)`，
  `adm/daemons/logind.lpc` 的 `reconnect()` 两条净断线重连分支都无
  条件调用 `user->reconnect()`——本轮净断线测试也侧面验证了这条链路
  （见上）。
- §7.114（`private` 声明的 `input_to()` 编辑器 mixin 回调）：全档案
  `grep -rl "private.*input_line"` 零命中。
- §7.115（`QUEST` 宏指向不存在的文件）：`include/globals.h` 里
  `QUEST` 是 `"/inherit/quest"`，`inherit/quest.lpc` 文件本身确实存
  在（385 字节），目标文件不缺失，不适用本档案。

### 进程卫生附注

驱动按精确 PID（`360392`）结束，未使用 `pkill -f` 模式匹配。测试期
间产生的存档漂移（`data/user/f/fluffos.o`、`data/login/f/fluffos.o`、
`data/user/y/ylfydeeptwo.o`、`data/login/y/ylfydeeptwo.o`，以及测试
窗口内背景世界模拟触发的 `data/npc/menpai.o`/`menpai1.o` 状态漂移）
已 `git checkout HEAD --` 还原，未纳入本次提交；未新建任何测试账号
（全程复用既有的 `fluffos` 管理员与 `ylfydeeptwo` 测试角色），无需
额外账号清理。本轮无代码改动，仅测试与记录。

## AGENTS.md §7.100 修复（2026-08-19，批次三）

`ROOM` 基类冗余 `replace_program(ROOM);` 自崩溃地雷（详见 AGENTS.md
§7.100）：4691 个房间文件的 `create()` 里紧跟 `inherit ROOM;` 之后
都有这一行多余调用，永久设下"待替换"标记，第一次对该房间对象绑
定闭包就会崩溃。自带建房工具 `clone/misc/roommaker.lpc` 的字符串
拼接代码生成模板里也烤了同一个地雷。

修复：脚本化删除所有房间文件里独立成行的 `replace_program(ROOM);`，
加上 roommaker.lpc 里手动摘除字符串拼接片段。`git diff --stat`：
4691 files changed，与预期精确吻合（103 处仍存在的匹配全部是既有
注释，未改动）。

验证：`build-debug` 驱动真实冷启动，端口 40062 正常监听，
`debug.log` 全程干净。既有管理员账号 `fluffos`/`Mud@2026` 登录正常
（华山派场景，练武场/兵器房多房间走访），`score` 正确显示，
`quit` 干净退出，全程无新增 "cannot replace"/"cannot bind" 日志行。

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
originally flagged as a possible false positive (it has a pre-existing
`nosave int enabled = 0;` flag in `feature/command.lpc`, the same shape
confirmed genuinely sufficient on `xiaoyuxiyou`/`xyxyutf8`/`xyxy2` in earlier
batches) -- but on closer inspection this is NOT the safe shape: those
libs set `enabled = 1` BEFORE calling `enable_commands()`, while here
`enabled = 1` is set AFTER `enable_commands()` returns. Since the reentrant
nested `init()`->`setup()`->`enable_player()` call (per AGENTS.md §7.19 and
driver docs) happens synchronously DURING the `enable_commands()` call --
before it returns -- the nested call still sees `!enabled` and calls
`enable_commands()` again, recursing exactly as if there were no guard at
all. Confirmed the reachable chain is real: `d/shushan/npc/zhangmen.lpc`'s
`init()` unconditionally calls `me->setup()`, and `inherit/char/char.lpc`'s
`setup()` unconditionally calls `enable_player()`. Fixed by adding a true
`in_enable_player_now` reentrancy flag (checked/set before anything else,
cleared before the function's single return path) alongside the existing
`enabled` bookkeeping variable, which is left untouched since
`disable_player()` still needs it. Verified via single-file `lpcc --batch`
PASS.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 4 line(s) in 1 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply ylfyxa3`: 7 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 12 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 4 PASS -> 12 PASS, 0 that loaded before fail now, 8 more load.

7 files moved (7 `.C`); mostly under `d/feitian/ximen.C` (1), `d/japan/path1.C` (1), `d/japan/senlin1.C` (1), `d/japan/senlin2.C` (1). A rescan with `scripts/lpc_warnings.py ylfyxa3` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_quest_guard.py`：1 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：改动过的 `adm/daemons/questd.lpc` 在新进程里加载，HEAD 通过 1 个、工作树通过 1 个（共 1 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 2 处比较、1 处去后缀（如 `cmds/app/ls3.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

## 深度功能测试（§10.7，2026-10-10）— 编译警告整理

`scripts/lpc_warnings.py ylfyxa3 --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 7 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：7 -> 7 通过，无回退。启动时警告 0 -> 0；新进程登录（输入名字）正常。

- 2026-10-10（续）：余下 6 条警告手工处理：`adm/daemons/cruised.lpc` 五处 `if (cruise[USER_ID]) { /* 只剩注释 */ }` 空分支连同条件一并注释掉（与 xajh4gkb 已修的副本相同）；`d/tianlongsi/npc/yideng.lpc` 的 `checking()` 原型由 `void` 改为与定义一致的 `int`。两文件 HEAD 与工作树都能载入，警告清零。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。9 个文件 9 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。13 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。3 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。

## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，3 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/cmds/skill/exercise`、`/cmds/skill/respitate`、`/kungfu/condition/emerald_poison`、`/kungfu/condition/sanpoison`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。5 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`/d/mr/npc/murong-bo`、`/d/mr/npc/murong-fu` 的拜师条件（悟性、身法、阅历门槛永远不过，拜不了师）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`bibo-shengongg`→`bibo-shengong`（`tanzhi-shentong/tan`）；`hujia-daofa`→`hujia-dao`（`/d/zhongzhou/obj/lengyuedao`）；`meinv-quan`→`meinv-quanfa`（`yunv-jian`）；`mingyu-shnegong`→`mingyu-shengong`（`mingyu-shengong`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`yuv-jianfa`→`yunv-jianfa`（`/d/gumu/gmlg3`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`jinggang-quan`→`jingang-quan`（`jingang-quan`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（5 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

1 个文件、1 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/shushan/npc/obj/cloth`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 1 个，改后 1 个（0 个原来载入不了），没有退步。

## 自制兵器的 id：名字按字节数拆（2026-10-18，KB 07 §8.1）

`feature/item_make` 的 `get_item_id()` 把自制物品的名字拆成一个或两个两字词，再到 `name_id_arg` 里查拼音（「失神」→ `shishen`）。原来按 GBK 字节数拆（`[0..3]`、`len > 4`），UTF-8 里一个汉字只占一个下标：四个字的名字 `[0..3]` 取走整个名字，表里查不到，id 只剩下 ` sword`（空的名字部分），玩家无法用名字指到自己做的兵器。改为按字符数拆（`[0..1]`、`[2..len-1]`、`len > 2`）：「失神炽日」得 `shishen zhiri sword`。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory.lpc`、`feature/move.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 4 个对象设了本库没有文件的武功（8 个名字，最多的是 `qiankun-danuoyi`、`magic-light`、`westsword`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：4 个里 4 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 42 处、37 个文件：`kunlun-shnfa`→`kunlun-shenfa`（14 处）、`shaolin-shnfa`→`shaolin-shenfa`（12 处）、`qiankun-danuoyi`→`qiankundanuoyi`（6 处）、`tiaji-jian`→`taiji-jian`（2 处）、`meimv-quanfa`→`meinv-quanfa`（2 处）、`qinashou`→`qinnashou`（1 处）、`kongmingquan`→`kongming-quan`（1 处）、`taiji-shenfong`→`taiji-shengong`（1 处）等共 11 个名字。（`scripts/lpc_fix_skill_names.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_axe.lpc`、`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_dagger.lpc`、`/d/npc/m_weapon/weapon/m_fork.lpc`、`/d/npc/m_weapon/weapon/m_spear.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 6 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`（共 2 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## userp(0)（2026-10-19，KB 06 §7.277）

`adm/simul_efun/player.lpc` 的 `userp(object ob)` 先调 `efun::userp(ob)`，没有人在场时（房间刷新里 NPC 穿会员衣服，`wear()` 里 `userp(this_player())`）`ob` 是 0，驱动报 `Bad argument 1 to userp()  Expected: object  Got: 0`，NPC 和房间载入不了。函数开头加 `if (!objectp(ob)) return 0;`（旧驱动里 `userp(0)` 就是 0）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：孙婆婆的“你去吧”只对 class 没设置的人生效。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/sunpopo.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/xuehepai/obj/bairiwan.lpc`（1 处）、`/kungfu/skill/yunshang-xinjing.lpc`（1 处）。另有 `/d/hainan/npc/ziyun.lpc`（1 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 9 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/hainan/npc/xianhe.lpc`、`/d/hainan/npc/xiaohe.lpc`、`/d/shushan/shanjian.lpc`）。改动：`/clone/npc/man.lpc`（1 处）、`/d/hainan/npc/xianhe.lpc`（3 处）、`/d/hainan/npc/xiaohe.lpc`（3 处）、`/d/shushan/shanjian.lpc`（2 处）。

## `get_config(__MUD_PORT__)` 经旧版 `runtime_config.h` 得到字符串（2026-10-20，KB 06 §7.302）

本库的 `include/runtime_config.h` 是老 MudOS 的编号（整数设置从 15 起，本驱动从 256 起），`get_config(__MUD_PORT__)` 读到的是另一项设置（字符串），`(int)` 又只是编译期标注，于是 `socket_bind(fd, LOCAL_PORT())` 报 `Bad argument 2 to socket_bind()`，版本守护进程 `port = get_config(__MUD_PORT__) + VERSION_PORT` 是字符串相加。头文件自己的注释写明 `get_config(__MUD_PORT__) == __PORT__`，所以代码里的这个调用（连同外面的 `(int)` / `to_int()`）改成了驱动的预定义 `__PORT__`（`scripts/lpc_fix_mud_port.py`）。改动：`/adm/daemons/network/fileserver.lpc`（1 处）、`/adm/daemons/network/server.lpc`（1 处）。

## `chglog`、`jnlog`、`partyinfo` 读不到运行日志就抛错（2026-10-20，KB 06 §7.326）

`chglog` 和 `jnlog` 把 `/log/chglog.txt`、`/log/jnlog.txt` 交给 `trans_color(read_file(file))`，`partyinfo` 把 `read_file("/log/cmds/party")` 直接 `explode()`。这三个文件都是运行中的 mud 才会写出来的日志，克隆出来的目录、站点和全新启动的树里没有，`read_file()` 答 0，于是 `Bad argument 1 to replace_string()`（在 `trans_color()` 里）和 `Bad argument 1 to explode()`。前两个现在先测 `file_size(file) <= 0`，用原来那句 `没有找到/log/....txt。` 回答；`partyinfo` 读不到时按空表处理，只打印表头。实测（ylfyxa3 的全新树，机器人登录）：三条指令都答出上面的结果，控制台没有错误；加载检查 3/3，回归 0。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 2 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（2 个文件，括号里是接住 0 的 efun）：`/cmds/adm/dallowip.lpc`（`find_player`）、`/cmds/adm/dbiaoshi.lpc`（`find_player`）。加载检查 HEAD 与工作树对照，没有退步。

## `findfile`、`updir`：不带参数（2026-10-21，KB 06 §7.336）

ToMud 升级用的两条指令（`cmds/bos/findfile.lpc`、`updir.lpc`）不带参数时报 `Bad argument 1 to sscanf() Expected: string Got: 0.`：`findfile` 的 `sscanf(arg, "%s,%s", dir, str)` 前面是一段注释掉的代码，`updir` 的 `sscanf(arg, "%s -debug", arg)` 在 `if (playerp(previous_object()))` 里面。`findfile` 补了 `if (!arg) return help(me);`（`help()` 在 `main()` 之后，补了原型），`updir` 在开头 `if (!arg) arg = "";`，不带参数就列出当前目录。

## 丘处机、觉远的 `accept_object()`：参数和局部变量的名字对不上（2026-10-21，KB 06 §7.348）

yxxcii 的 `qiu.lpc`、`qiu1.lpc`：`accept_object(object me, object ob)` 里判断的是 `obj->query("name")`，`obj` 是没赋值的局部，交上药材一律抛错。ylfyxa3 的 `jueyuan.lpc` 把参数表丢了（`int accept_object()`），函数里读 `obj`（xajh4gkb 的同一份文件是 `accept_object(object me, object ob)`）。把参数名改回来。改动：`/d/shaolin/npc/jueyuan.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 19 条注册（19 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/counter.lpc`（`do_killing`）、`/d/city/warehousenew.lpc`（`do_zhuan`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/flypproom/npc/flypp.lpc`（`do_sell`）、`/d/kunlun/obj/jwqin.lpc`（`do_play`）、`/d/mingjiao/npc/changjinpeng.lpc`（`do_join`）、`/d/mingjiao/npc/chengchaofeng.lpc`（`do_join`）、`/d/mingjiao/npc/fenggongying.lpc`（`do_join`）、`/d/mingjiao/npc/gaoshanwang.lpc`（`do_join`） 等共 19 个文件。最多的函数名：`do_decide` 7 处、`do_join` 4 处、`do_jump` 1 处、`do_killing` 1 处、`do_zhuan` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。6 个文件里 6 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 6 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 6 个，现在 6 个（新增可加载 0 个，回归 0 个）。
