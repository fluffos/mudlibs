# yanlongfengyin_xiaoao3 — 炎龙封印·笑傲江湖 (阿飞站)

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
the term "炎龙封印" with archive #48 (`xiyangzaixian3`,
"夕阳再现III之炎龙封印"). Compared core files directly:

- `master.lpc`'s `get_player_fname()`/`connect(int port)` shape and the
  exact error message text (`"现在有人正在修改使用者连线部份的程式，请待会再来。"`)
  match xiyangzaixian3's master.lpc almost verbatim — confirming a REAL
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
  xiyangzaixian3's copies. The live boot banner itself explains why: `"该
  版本由阿飞在碎梦修改的炎龙端基础上，再次修改，已不同于原先的炎龙版本了。"`
  ("this version was further modified by 阿飞/Afei based on 碎梦/Suimeng's
  own modified 炎龙[Yanlong] branch — already different from the original
  Yanlong version"). So: same ultimate engine root, but a separately/
  heavily forked descendant with its own registration-flow shape, its own
  securityd ACL, and its own bugs — **only the `is_chinese()` §15h shape
  was directly portable verbatim from xiyangzaixian3; everything else
  (master.lpc, securityd.lpc, logind.lpc's whole callback chain, the
  double-slash NPC-equip bug, the crash) needed independent discovery.**
- `xiyangzaixian3`'s §15q client-version gate (hardcoded literal `"2060"`)
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
    for `xiyangzaixian3`/`tianxia`: `@LONG ... 神彩奕奕.LONG );` (or
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
  `"2060"` (a Tomud-protocol handshake code) — but unlike xiyangzaixian3's
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
  `yanhuangyingxiongshi` NOTES.md entries** (a real bug in the
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
