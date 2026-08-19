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
