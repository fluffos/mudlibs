# xlqy_early — 仙侣情缘 (early/incomplete "driver test" snapshot)

Archive: `xlqy-解压看readme.rar` (archive #27). Port: 40076. Status: **done**
(boots clean, full registration flow verified end-to-end multiple times
incl. real Chinese names, `score`/`look`/`quit` all confirmed working
post-login).

## What this is / lineage confirmation vs xlqy_new2007 (#26)

Extracts cleanly (no password/special step needed despite the `xlqy-解压看
readme.rar` "unzip and read the readme" filename) to a root `xlqy/`
directory. `readme.txt`'s own text (translated): *"start with
`startxlqy64.bat`... this lib is very incomplete, mainly used to test the
driver... you can open the `rzr` channel, it's mostly `rzr` [artificial
NPCs] running around... configure the number of `rzr` in
`/adm/daemons/manmade_npcd`'s `max_npcs`... the underlying engine has been
heavily rewritten, many things are incompatible, no tech support
provided."* — an unpolished, pre-#26 snapshot of the same "仙侣情缘"
codebase, explicitly shipped for driver-compatibility testing rather than
play.

**Lineage confirmed via diff, not assumed from the shared title** (this
project's own repeated lesson: similar Chinese titles are not a reliable
lineage signal — see xianlvqiyuan vs xlqy_new2007, sjpl2 vs
shujian2008):
- `adm/simul_efun/chinese.lpc` — identical logic to xlqy_new2007's copy,
  differing only in whitespace/brace style (`diff` shows only reformatting,
  confirmed with `diff -bw` too — same GBK-byte `is_chinese()` bug, same
  §15h fix needed).
- `adm/obj/master.lpc` — same story: `diff -bw` shows only brace-style/
  whitespace reformatting, not a content fork; same `valid_read`/
  `valid_write`/`valid_override`/`get_root_uid`/`get_bb_uid` shapes as #26.
- `adm/daemons/logind.lpc`, `adm/daemons/chinesed.lpc` — **do** differ
  substantially in content (1957 and 309 diff lines respectively) — this
  is a genuinely earlier/rougher build of the same game, not a byte-clone.
- File counts: 9177 raw `.c` files here vs 9060 in xlqy_new2007's raw
  archive (matches the pre-existing TODO.md note of "9174 vs 9060").

**Net conclusion**: same base engine/authorship (`bugbug & alading @
缥缈水云间, 2003-4-5` credited in nearly every file header), an earlier
development snapshot with a rougher/smaller `logind.lpc`/`chinesed.lpc`,
NOT a duplicate archive. xlqy_new2007's proven `master.lpc`/`chinese.lpc`
fixes ported directly and worked unchanged; `logind.lpc`'s
`check_legal_name` needed its own independent §15h fix since that file's
content differs.

## Fixes applied

1. **AGENTS.md §15h (chinese.lpc)**: `is_chinese()`'s GBK lead-byte range
   check (`str[0] > 160 && str[0] < 255`, `strlen(str) >= 2`) replaced with
   a CJK Unicode codepoint range check (`str[0] >= 0x4e00 && str[0] <=
   0x9fff`, `strlen(str) >= 1`). Ported the same shape already proven on
   xlqy_new2007.
2. **AGENTS.md §15h (logind.lpc `check_legal_name`)**: byte-calibrated
   bound `strlen(name) < 2 || > 12` → `< 1 || > 6` (message already says
   "必须是一到六个中文字" — 1 to 6 Chinese characters — halving the byte
   bound just makes the code match what the message already promised);
   dropped the `i%2==0 &&` GBK-lead-byte-alternation gate from the
   sliding-window loop so every character position is checked, not every
   other one.
3. **AGENTS.md §14 (`valid_override`)**: upgraded from the 2-arg
   `(file, name)` signature to the documented 3-arg `(file, name,
   main_file)` form, checking `main_file == SIMUL_EFUN_OB/MASTER_OB` too
   — free insurance for `#include`-composed simul_efun fragments (confirmed
   this specific gap causes an lpcc-sweep-only failure on
   `adm/simul_efun/object.lpc`, see lpcc section below; never actually
   surfaces on a real boot).
4. **AGENTS.md §8d/§15o (`get_include_path()`)**: added to `master.lpc`
   (was entirely absent) — prepends the compiling file's own directory to
   the include search path so `#include "local.h"`-next-to-its-user
   resolves for compiles triggered live mid-connection (this lineage has
   several such local headers: `d/city/workroom.h`, `d/obj/misc/
   message.h`, `d/obj/quest/quest.h`, `d/*/npc/reporting.h`,
   `d/city/misc/banned.h`).
5. **AGENTS.md §15w (`log_error`)**: gated the player-facing broadcast on
   the message NOT containing `"warning:"` (this driver funnels every
   compile *warning* — e.g. the harmless `nosave`-function warnings that
   `static`→`nosave` renaming produces — through the same apply as real
   fatal errors; without the gate, any lazily-compiled file with a
   cosmetic warning would flash the scary default-error message at
   whichever player happened to be online).
6. **AGENTS.md §8h (`convertd.lpc` Greek-table typo)**: one instance,
   line 258, `"α\",` → `"α",` (plain LF file, verified with `cat -A`
   before choosing the non-CRLF sed pattern per the documented lesson).
7. **`niu.lpc` disallowed `..`-relative include (§15t #2)**:
   `d/ourhome/honglou/npc/niu.lpc` had `#include "../honglou.h"` — this
   driver disallows `..` in `#include` paths outright. Fixed to the real
   absolute quoted path `"/d/ourhome/honglou/honglou.h"`.
8. **`eventd.lpc` fixed-width extension-strip bug (AGENTS.md §2's
   `[0..<3]`→`[0..<5]` nitan-family-shaped variant, found independently
   here in a non-nitan-lineage lib)**: `collect_all_event()`'s
   `map_array(get_dir(EVENT_DIR+"*.lpc"), (: $1[0..<3] :))` was correct
   for stripping the original 2-char `.c` extension but left a stray
   trailing `.l` after the `.c`→`.lpc` rename (`"emei.lpc"[0..<3]` →
   `"emei.l"`, not `"emei"`) — every event failed to resolve
   (`call_other() couldn't find object '.../emei.l'`, one per preload,
   non-fatal since wrapped in the daemon's own `catch()`). Widened to
   `[0..<5]` per the established +2 formula.
9. **`d/city/workroom.h` broken `__FILE__` usage (new finding, not yet in
   AGENTS.md)**: this header is `#include`d (not inherited) into 3
   sibling rooms (`workroom1/2/3.lpc`), and used `__FILE__` inside a
   `start_busy()` closure intending "the room that's actually running
   this code" — but `__FILE__` is a preprocessor macro that expands to
   whatever file is textually being *scanned* at that point, which for a
   `#include`d fragment is always the header's own path
   (`/d/city/workroom.h`, never a loadable object on its own), not
   whichever of the 3 rooms actually included it. This produced ~130+
   `call_other() couldn't find object '/d/city/workroom.h'` runtime
   errors per test session (the highest-volume error category by far,
   generated continuously by autonomous NPCs' "work for money" AI
   behavior in these rooms). Fixed by replacing both `__FILE__` uses with
   `file_name(this_object())` (resolves correctly at runtime regardless
   of which of the 3 rooms is actually executing). **Worth adding to
   AGENTS.md as a new catalog entry** — this is a generic trap for any
   lib with a `#include`d (not inherited) fragment that uses `__FILE__`
   expecting "the including object," since standard C-style preprocessor
   semantics (this driver's `__FILE__` genuinely matches plain C here,
   confirmed by reading `lexer_rules_pp.cc`) never behaved that way.
10. **`daemon/skill/dao/taijitu.lpc` — AGENTS.md §15aa-shaped same-file
    forward-reference bug (new instance, different mechanism than §15aa's
    original "same name as a real efun" trap)**: `cast_person()` (defined
    early in the file) calls `remove_effect_using(me, target)` before the
    file's OWN 2-arg `(object me, object target)` override of that name
    is defined later in the file. Because the base class `std/sserver.lpc`
    (reached via `inherit FAMILYSKILL`) already defines an INHERITED
    `remove_effect_using(object me, string file)`, the compiler bound the
    early call to that inherited (wrong-arity) version instead — `error:
    Bad type for argument 2 of remove_effect_using ( string vs object
    )`. A first attempt at a fix (changing the call site to pass
    `__FILE__` instead of `target`, matching every sibling skill file's
    convention) compiled but was WRONG: it silently changed behavior to
    call the generic inherited cleanup instead of this file's own
    invisibility-removal/room-restoration logic. **Corrected fix**: moved
    the actual function body (not just a prototype — a bare forward
    *declaration* alone was insufficient here, still bound to the wrong
    inherited version) to appear before `cast_person()`'s first call to
    it. Confirmed clean via `lpcc` before and after. This skill is only
    reachable via actual "太极图" (taijitu) spell casting in combat, not
    the registration/boot path, but was a real semantic bug worth fixing
    correctly rather than papering over.
11. **`adm/daemons/cndd.lpc` — THREE separate undeclared-variable/
    forward-reference bugs in the condition-tracking daemon, found via the
    lpcc sweep, all pre-existing in the raw archive (confirmed by
    grepping the raw `.c` file directly — none of these declarations were
    ever present, not something our conversion dropped)**:
    - `clear_condition(object me, string cnd)` used a bare `conditions`
      mapping throughout with NO declaration/fetch at all. Every sibling
      function in the same file (`query_entire_conditions()` right above
      it) fetches the equivalent value via
      `me->query_temp("conditions")` — added the same fetch as a local
      declaration at the top of the function (unambiguous fix, not a
      guess, matching an existing sibling idiom in the same file).
    - `clear_conditions_by_type(string required_type)` had the identical
      `conditions`-undeclared bug, but this function takes NO `me`
      parameter (unlike `clear_condition`) — fixed via
      `this_object()->query_temp("conditions")` instead.
    - A SEPARATE, parallel `hb_conditions` mapping (heartbeat-scoped
      condition store, used by `update_hb_condition()`/
      `apply_hb_condition()`/`query_hb_condition()`/
      `clear_hb_condition()`) was used identically across all four
      functions with **no declaration anywhere in the file at all** (not
      even a `query_temp` fetch — this one is genuinely meant to be a
      persistent per-object global, since it needs to survive across
      calls with no explicit save-back). Added
      `nosave mapping hb_conditions;` as a real file-level global,
      resolving all four call sites at once.
    - Bonus: `clear_condition()` calls `clear_hb_condition()` (defined
      much later in the same file) before that definition appears —
      "Undefined function clear_hb_condition" (AGENTS.md §8b's classic
      "same-file forward reference" shape). Fixed with a one-line forward
      declaration near the top of the file (this one DID work as a bare
      declaration — unlike the taijitu.lpc case above, since there's no
      competing inherited function of the same name to shadow it).
    - Verified compiles clean via `lpcc` after all four fixes.
12. **Uppercase `.C` rename (AGENTS.md's "watch for uppercase .C" check)**:
    3 files missed by `convert_lib.sh`'s lowercase-only glob
    (`d/obj/drug/YUNDAN.C`, `d/guzhanchang/obj/{DIAMOND,BAG}.C`) —
    manually renamed to `.lpc`; all three were already UTF-8 (not GBK),
    so no additional encoding pass was needed. Confirmed no dangling `.c`/
    `.C`-suffixed string references to these three basenames anywhere
    else in the lib (only stale `.bak`/timestamp-suffixed backup copies
    reference the related zone, none of them live `.lpc` code).
13. **Created missing save-data directories** (not present anywhere in
    the raw archive — `data/` shipped completely empty): `data/{login,
    user,npc,fabao,gold,pet}/{a..z}/` — this driver's `save_object()`
    (`vm/internal/base/object.cc`) does a plain `fopen()` with **no
    mkdir**, so saving to a nonexistent sharded directory throws an
    uncaught `error()` ("Could not open ... for a save"). Since
    `enter_world()`'s `user->save(); ob->save();` calls have no
    `catch()` around them, this would have silently killed every new
    registration right after gender selection (the same failure shape as
    AGENTS.md §15ah, just for `save_object()` rather than `log_file()`).
    Also created `log/nosave/` (referenced by `master.lpc`'s crash
    handler and several `log_file("nosave/...")` calls, same §15ah
    pattern, lower-impact since only reachable on an actual crash).

## Confirmed NOT needed (checked via source reading, not assumption)

- **§4** (lazy `load_object(SECURITY_D)` recursion in `valid_read`/
  `valid_write`): `master.lpc`'s versions only do `find_object()`, never
  `load_object()` — same as xlqy_new2007, not the recursion-prone shape.
- **§7** (`get_root_uid`/`get_bb_uid` missing): both already present.
- **§15n/§15o func-allowlist** for a custom `securityd.lpc` ACL: this
  lib's `valid_read`/`valid_write` already use an allow-by-default-
  unless-a-known-data-op pattern (`if (func != "read_file" && func !=
  "file_size" && func != "stat" && func != "read_bytes" && func != "tail"
  && func != "ed_start") return 1;`) that already implicitly allows
  `load_object`/`recompile_object`/`include` without needing an explicit
  allowlist addition — confirmed by reading the function body, not by
  hitting the crash.
- **§8c** (`this_player()`-override-in-valid_read footgun): `get_status()`
  is called directly with the passed `user`, no `this_player()`
  substitution anywhere in `securityd.lpc`.
- **§15p** (dns_master preload exclusion): `adm/etc/preload` never
  listed `dns_master`/`network/dns_master` to begin with — nothing to
  exclude. The `adm/daemons/network/` tree exists (intermud daemons,
  mail/ping/telnet services) but is entirely unreachable from
  registration/normal play; its own missing headers (`post.h`, `uid.h`,
  `priv.h` — genuinely absent from the archive) only surface as lpcc-sweep
  noise (see below), never a boot/connect issue.
- **§15l** (`destruct(SIMUL_EFUN_OB)` in master's `create()`): no such
  call anywhere in `master.lpc`.
- **§15ae** (`private nomask command_hook` breaking post-login commands):
  `feature/command.lpc`'s `command_hook` is already `nomask int
  command_hook(...)` with `private` **commented out** in the source
  (`// private nomask int command_hook(string arg)`) — already fixed by
  whoever last touched this codebase (or never had the bug). Confirmed
  both by reading the source AND empirically: `score`/`look`/`quit` all
  produced correct real output in every test run.
- **§15ag** (`ed_start`/`ed_cmd`/`query_ed_mode`): only appears as a
  string literal inside `securityd.lpc`'s func-name comparison list
  (classifying which read ops are "sensitive"), never actually called.
- **§15al** (`crypt(str, 0)` random-hash trap): `logind.lpc` uses
  `crypt(pass, 0)` only to set a NEW password at registration time (the
  resulting hash string itself, containing its own embedded salt, is
  what gets compared against on subsequent logins via `crypt(pass,
  my_pass)` — the stored hash IS the salt for verification, so a fresh
  random salt at set-time is completely fine here). This is the ordinary
  password-hashing idiom, not the client-challenge-handshake shape §15al
  actually warns about (no client-side independent computation of the
  hash is expected anywhere in this lib).
- **§15am** (`file_size()==-1` truthiness trap): the two `file_size(...)
  >= 0` checks in `logind.lpc` are already written correctly.
- **§8e** (`tail()` missing efun): only reachable from `cmds/wiz/tail.lpc`
  (an admin command, confirmed non-fatal, not on the boot/simul_efun
  compile path) — never touches the fatal `adm/simul_efun/file.lpc`
  case some other libs hit.
- **LONELY_IMPROVED / `count()` bignum family**: zero hits — this is not
  a nitan/Lonely-lineage lib, no `efun::set/query/delete`-family
  simul_efun architecture bug applies either (this codebase's `feature/
  dbase.lpc` already implements real per-object `set`/`query`/`delete`).
- **§15u dormant anti-piracy self-destruct**: no `shutdown()`/mass-delete
  pattern found in `securityd.lpc`/`master.lpc`.
- **§15z `#define nosave static`/`#define protected static` shim
  collision**: no such compatibility macro present anywhere.

## Interactive test results — full registration + post-login commands

Registration shape (read from `logind.lpc`'s actual callback chain, not
inferred from prompt text): GB/BIG5 selection → "are you a student"
age-gate (any non-"no" ends the session) → English id prompt (`new` must
be typed literally) → English id → **no y/n confirmation step** → Chinese
name prompt → password → password confirmation → email → gender (m/f) →
an always-instant, non-interactive "gift allocation" step (the `d/wiz/
init.lpc` room's own `input_to("get_input", ...)` line is commented out
in the source, so `get_start()` calls `do_finish()` synchronously via a
`call_out(0)` right when the player enters — no real stat customization
ever happens, matching the archive's own "not fully finished" nature) →
drops the new character into an actual starting room (`聚见亭`, chosen at
random from several candidates per `d/wiz/init.lpc`'s own logic).

**Verified successfully in FOUR independent full continuous sessions**,
each incl. a real Chinese name reaching the actual game world and at
least one post-login command producing correct output:
- **秦风 (Qinfeng, male)** — fast/clean run right after a cold boot.
  `look` → room description (聚见亭) with correct NPCs listed; `score` →
  full, correct character sheet (仙衔/职称/attributes/gender all correct);
  `quit` → correct farewell flavor text. Zero `debug.log` errors this
  session.
- **秦岭 (Qinling, female)** — same result, incl. correct female
  honorific/gender fields on the character sheet.
- **秦天 (Qintian, male)** — same result again after a full driver
  restart with every fix above applied (including the corrected
  `taijitu.lpc`/`cndd.lpc` fixes), confirming a clean state from a fresh
  boot: `score` produced the correct sheet, `quit` the correct farewell,
  zero `debug.log` runtime errors for the whole session.
- **秦水 (Qinshui, male)** — registered successfully under heavy
  background CPU load (see below); confirmed via the actual saved
  `data/user/q/qinshui.o`/`data/login/q/qinshui.o` files (correct name,
  gender, stats, SHA-512 password hash) even though the live telnet
  transcript itself got cut short by the test script's own timeout
  budget before showing the final room — not a functional failure, see
  next section.

One recurring, understood-and-benign cosmetic quirk: `get_name()` in
`logind.lpc` has a leftover debug statement, `printf("%O\n", ob);`,
printed right after a Chinese name is accepted — shows the raw login
object reference (e.g. `/obj/login#16`) to the player. Pre-existing in
the original source (not something this pass introduced), purely
cosmetic, does not block anything. A second cosmetic-only artifact seen
once: sending an early command (`9`/`look`) in the split-second window
between entering `d/wiz/init` and its `call_out(0)`-triggered
`do_finish()` firing can get silently swallowed by `d/wiz/init.lpc`'s own
`add_action("do_block", "", 1)` catch-all (which only allows `look`/
`help`/`story`/`say` while in that room) and shows the driver's generic
`default fail message` ("什么？") once — harmless, and the very next
line in every affected transcript is the correct room entry/gift
completion; not a registration or command-dispatch defect.

## Known characteristic, not a bug: heavy CPU load from autonomous "rzr" NPC roaming

This archive ships with `adm/daemons/manmade_npcd.lpc`'s `max_npcs = 100`
— per the readme's own description, up to 100 autonomous "rzr" (人造人/
artificial-human) NPCs wander the ~9,177-file map continuously from boot,
lazily compiling every room/NPC/item file they touch for the first time.
Observed: driver CPU climbed from ~7-20% right after boot to a sustained
75-85% within a few minutes and stayed there for the ~12+ minutes this
pass kept the driver running, visible in `debug.log` as a continuous
stream of "In file included from ..." compile-cascade lines across every
zone in the map. This is a genuine, intentional feature of this
particular "for driver testing" snapshot (explicitly what the readme
describes), not a conversion defect — no crash, no fatal error, the
driver stayed fully responsive to new connections throughout (confirmed:
a fresh registration completed correctly even while this was happening,
just with higher latency on some responses since this driver's game-tick
processing is single-threaded and a heavy background lazy-compile pass
competes for the same thread). Two of the six test connections in this
pass hit this slowdown directly (the `qinbao`/`qinchuan`/`qinhuai` runs
issued in the middle of this pass, while the storm was in full swing,
never actually completed within their allotted test-script timeout
budgets — confirmed via the absence of a corresponding `data/user/`/
`data/login/` save file for those three ids, i.e. these were test-harness
timeouts, not silent registration failures). Not fixed/tuned down since
it's original game-balance content, not a driver-compat defect; flagging
here so a future session isn't surprised by it.

## lpcc sweep

**9177 files, 9070 pass / 107 fail (98.8%)** (`libs/xlqy_early/
lpcc_batch_raw.log` / `lpcc_fail.log`, both left in place per the
established per-lib convention). Triaged by category rather than fixing
all 107 blind, per AGENTS.md §6b:

- **~26 files** (`d/kaifeng/npc/**/quest*.lpc`, incl. `.../backup/` and a
  `d/dntg/yunlou/npc/**/quest.lpc` sibling): `Cannot #include colors.h` /
  `reporting.h`, cascading into `Undefined function query`/`Unable to
  find inherited function 'setup'` etc. Root cause: these files live one
  directory level below (`.../kaifeng/npc/kaifeng/`) where `colors.h`/
  `reporting.h` actually reside (`.../kaifeng/npc/`), so a plain quoted
  `#include` fails to find them **specifically when compiled via bare
  `lpcc`** — the newly-added `get_include_path()` (fix #4 above) computes
  exactly the right parent directory for real mid-connection compiles,
  but per AGENTS.md §15o's documented caveat, `get_include_path()` is
  never consulted for `lpcc`-batch/no-VM-context compiles at all, so this
  category is expected sweep noise, not a live defect — confirmed absent
  from every real boot/interactive-test `debug.log` in this pass (grepped
  for both header names, zero hits). Not independently proven at true
  runtime (none of our test sessions happened to visit this specific
  Kaifeng zone), but matches the well-established pattern from many prior
  libs closely enough to trust without further chasing.
- **~16 files** in directories literally named `old`/`backup` (`d/baoshi/
  obj/old/{bs,js}_{b,g,r,y,z}1.lpc`, `d/kaifeng/npc/{old,backup/old}/
  {bei,shan,zhi}.lpc`): missing `build_gold.h`/similar shared headers.
  Confirmed via `grep -rl` that nothing outside these `old`/`backup`
  directories references any of these files by path — genuinely dead,
  superseded content, not reachable in play.
- **6 files** under `adm/daemons/network/` (`mail_serv`, `netmail`,
  `pingd`, `pingtcp`, `telnetd`, `userid`): missing `post.h`/`uid.h`/
  `priv.h` — confirmed genuinely absent from the whole archive (not a
  local-include-path issue), an entire never-fully-shipped intermud/mail
  subsystem. None of these files are in `adm/etc/preload` and none are
  reachable from registration/ordinary play.
- **7 files** with genuine raw pre-existing byte corruption (`Illegal
  character` errors decoding to garbage/mixed CJK+control bytes):
  `quest/xunbao/obj/shuijingqiu.lpc` (+ its `d/obj/quest/` duplicate),
  `d/moon/obj/poem.lpc`, `d/obj/books-nonskill/hmeng014.lpc`,
  `d/shendian/obj/niepan.lpc`, `d/wiz/angell/hp.lpc`, `story/
  pifeng2.lpc`. Confirmed for `shuijingqiu.c` by inspecting the RAW
  pre-conversion bytes directly (`locate_quest(this_player(),arg` followed
  immediately by `\xab\xc9\x85w)\xf6\xe6\xbb6o~m#\xa3y\x9e\xf4\x8a`) — this
  garbage is already present in the original archive, not introduced by
  our GB18030 conversion (iconv just decoded already-corrupt bytes into
  equally nonsensical but valid UTF-8). Not reconstructed/guessed at;
  documented as pre-existing archive bit-rot.
- **2 genuine bugs found and FIXED** (see Fixes #10/#11 above):
  `daemon/skill/dao/taijitu.lpc` (same-file forward-reference
  mis-binding) and `adm/daemons/cndd.lpc` (3 separate undeclared-variable/
  forward-reference issues). Both now compile clean, verified via
  individual `lpcc` re-checks (a full re-sweep was not re-run afterward
  to conserve host resources given other agents were sweeping
  concurrently — memory stayed healthy throughout this pass's own sweep,
  15-19GB available the whole time, well clear of the danger zone).
- **`adm/simul_efun/object.lpc`**: `Invalid simulated efunction override`
  — this is precisely AGENTS.md §14's documented "only ever surfaces when
  `lpcc` compiles the fragment as a standalone top-level object" false
  positive; the 3-arg `valid_override()` fix (#3 above) is already in
  place and this error is confirmed absent from every real boot's
  `debug.log`.
- **`cmds/wiz/tail.lpc`**: `Undefined function tail` — AGENTS.md §8e's
  documented benign case (admin command only, not the fatal
  simul_efun-compile-path variant).
- **`cmds/adm/{socket,dumpsocket}.lpc`**: `Undefined function
  dump_socket_status` — peripheral admin socket-debugging tools, never
  reached by registration/ordinary play, not chased further.
- **Remaining ~40 files**: a long tail of individual NPC/item/room
  content, one example fully diagnosed (`d/city/npc/aluoben.lpc` — the
  file itself compiles with ZERO errors, but its `create()` calls
  `carry_object("/d/city/npc/obj/sengpao")` for a monk's-robe item that
  doesn't exist anywhere in this archive — a genuine, narrow missing-item
  content gap, AGENTS.md §13/§15e's category, not a driver-compat bug).
  The rest were not individually opened given the sample already
  confirmed the expected mix (missing-content gaps and isolated
  pre-existing content typos) rather than a shared systemic cause, per
  §6b's explicit guidance not to exhaustively diagnose every last item on
  a lib this size once the failure categories are understood.

## Suggested new AGENTS.md catalog entries (not added — instructed not to edit AGENTS.md directly)

- A `#include`d (not inherited) fragment file using `__FILE__` to mean
  "whichever object actually included me" is always wrong on this driver
  — `__FILE__` expands to the file currently being *lexically scanned*
  (standard C-preprocessor semantics, confirmed in `lexer_rules_pp.cc`),
  which for an `#include`d header is the header's own path, never the
  includer's. Fix: `file_name(this_object())` instead, which resolves
  correctly at runtime. Found in `d/city/workroom.h`, the highest-volume
  single error source in this lib's own testing (100+ runtime errors per
  session from autonomous NPCs repeatedly triggering the broken path).
- A same-file forward-reference to a locally-overridden function name
  that ALSO exists on an inherited base class can bind to the WRONG
  (inherited) version even with an explicit forward *declaration*
  present — only moving the real function body (not just a prototype)
  above its first caller fixed it in this instance
  (`daemon/skill/dao/taijitu.lpc`'s `remove_effect_using`). This is a
  stronger/different failure mode than §15aa's original finding (which
  was specifically about a same-named-as-a-real-*efun* wrapper); here the
  name collision is with an ordinary *inherited* function, and a bare
  prototype-only forward declaration was NOT sufficient insurance the way
  it normally would be for an unrelated new name.

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  9177 `.lpc` files in `work/`; 9168 written, 9 already-conformant,
  0 errors (a clean, error-free run — unusual for this batch's messier
  libs, consistent with this codebase's otherwise-tidy source).
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted this lib clean (zero fatal errors in `log/debug.log`, only the
  routine `Unknown #pragma`/unused-local warnings already known from
  earlier passes). Full registration flow verified end-to-end with a
  fresh real Chinese name (秦月) — gb/no/new/english-id/Chinese
  name/password/email/gender/gift-allocation all completed, landed in
  聚见亭; `look` showed the correct room+NPCs, `score` produced a
  correct full character sheet, `quit` gave the correct farewell text.
  Zero `debug.log` errors this session. The reformat did not disturb
  anything — same clean result as prior passes.
- **WASM**: booted cleanly under `build-wasm` (only the expected
  non-fatal preload warnings, no fatal errors). Full registration flow
  (gb/no/new/english-id/Chinese name 秦波/password/email/gender) also
  completed successfully under WASM, reaching the same 聚见亭 starting
  room; `look` and `quit` both worked correctly. This lib's
  registration does **not** gate on `query_ip_number()` format, so it
  is unaffected by the known WASM IP-formatting limitation — however,
  the "上次连线的地址" (last-connected-address) display line, which
  normally prints an IP, printed a garbled/misformatted value (a
  timestamp-looking string) under WASM instead. This is a purely
  cosmetic manifestation of the same known `query_ip_number()`-under-WASM
  driver limitation (see AGENTS.md's WASM section) — not a functional
  blocker, registration/login/commands all still work. **Verdict: fully
  playable under WASM**, one cosmetic IP-display glitch noted, not fixed
  (driver-side, out of scope).

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched:

- `adm/daemons/band.lpc` — added `is_loopback_site(string)` helper
  (loopback / empty / malformed-IP → treated as local) and short-circuit
  `return 0;` at the top of `is_banned()`, `create_char_banned()`,
  `is_strict_banned()` (the three IP ban gates the login flow calls).
- `adm/daemons/logind.lpc` — added `is_loopback_conn(object)` helper
  (same test on `query_ip_number(ob)`), and:
  - `logon()` reconnect-flood throttle (`last_ip==ip && time+5>time`,
    ~line 79) — now `!is_loopback_conn(ob) && ...`, loopback exempt.
  - `logon()` "too many from this IP" cap (`logon_cnt > 10`, ~line 98) —
    loopback exempt.
  - `encoding()` `!ip_name` destruct + the dotted-quad char-loop format
    validator (~lines 163-173) — whole block now guarded by
    `if (!is_loopback_conn(ob)) { ... }`, so loopback/garbage-IP
    connections skip both. This was the WASM-fatal gate
    (query_ip_name/number return garbage under WASM).
  - No `uptime() < N` startup-grace *destruct* gate exists in this lib;
    the `uptime()` use at ~line 132 is the newid registration-throttle
    window (game content) — left intact.

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` by adding `fluffos (admin)` to `adm/etc/wizlist`. Verified via
real registration flow (gb/no/new/fluffos/浮浮/Mud@2026/.../m → entered
world) then relogin + `update /adm/daemons/logind` → "成功" and status
line shows `(admin)`. Retest: fresh normal registration still works,
zero new debug.log errors. Save file:
`work/data/user/f/fluffos.o` (tracked, NOT gitignored — no force-add
needed).


## Fail-closed retrofit for the loopback-allow gate (2026-07-24)

The loopback helper above was originally written matching the
project-wide convention at patch time (AGENTS.md §1.3b), which also
treated an empty/non-string/malformed `query_ip_number()` result as
loopback, defensively, because the WASM driver used to return garbage
there. That underlying driver bug is now fixed (fluffos commits
`e33bb5da` "fix: query_ip_number() returned uninitialized garbage under
WASM" and `007bb863` "feat: synthetic resolve() on WASM instead of
raising an LPC error", both 2026-07-23; the locally-built
`build-debug`/`build-wasm` binaries already postdate both commits), so
treating unparseable IPs as trusted is a fail-open gap with no remaining
justification. Retrofitted to fail-closed: loopback is now strictly
`ip == "127.0.0.1" || ip == "::1" || ip[0..3] == "127."` (with a
`stringp()` guard before the slice) — a malformed/empty IP now falls
through to the NORMAL gate instead of being treated as local. Retested
after tightening: fresh driver boot clean, `fluffos` loopback login and
its wizard `update` command both still work; zero new debug.log errors.

## 深度功能测试 / Deep functional test (2026-08-06/07)

第一次完整游玩测试（原生驱动 `build`，ASAN/UBSAN debug 构建）。测试角
色 id `xlqytstb`，中文名 小仙女。本轮 WASM 未重新验证：emsdk 工具链
下载硬编码指向 `storage.googleapis.com`，本次会话的出口代理策略性拒
绝该域名（403，已用 `curl $HTTPS_PROXY/__agentproxy/status` 确认是策
略拒绝而非临时故障），本地无法构建 WASM 驱动。

### 发现并修复：`maximum evaluation cost` 过低，开机预载阶段真实崩溃过一次（AGENTS.md §7.90 新实例）

- **症状**：驱动首次启动（未做任何修复前），`debug.log` 出现
  `Eval interrupted: object adm/daemons/leveld cost limit reached,
  limit: 500000 usec.` 以及更严重的一条`*Can't catch eval cost too big
  error.`（连 `catch()` 都拦不住的版本），栈追踪指向
  `adm/obj/master.lpc:139` 的 `preload("/adm/daemons/leveld")` 调用。
- **根因**：`config.fluffos` 的 `maximum evaluation cost : 500000` 比
  这个项目常见的 700000 模板默认值还低。`leveld.lpc` 的 `create()`
  内建一个真实的、合法的双层循环（为每个等级预计算升级所需经验/道行
  表，`levelup_cfg` 有多个等级分段），本身不是死循环或 bug，只是这份
  预载计算的开销天然超过了 500000 usec 的预算。
- **修复**：提高到 `5000000`（本项目 30+ 份档案验证过安全的数值，与
  `xyj2000f`/`xiyouji450`/`xiyouji2006` 系列同一处理方式，虽然血缘家
  族不同）。
- **验证**：修复前重启驱动，`debug.log` 稳定复现上述两条错误；修复
  后重启，同样的预载流程（含这份档案自带的 100 个自动游走"人造人"
  NPC 在开机后几分钟内陆续触发全图房间编译，是这份档案的已知特色负
  载）全程无任何 eval-cost 中止或"can't catch"错误，即使在这个持续
  高负载窗口内也没有复发。

### 发现并修复：注册流程遗留的 `printf("%O", ob)` 调试输出（AGENTS.md §7.34 已知模式的又一实例）

`adm/daemons/logind.lpc` 中文名确认成功分支有一行未加注释的
`printf("%O\n", ob);`，同一文件里没有找到第二条并行路径的重复实例。
按 §7.34 既定修法直接删除。修复前用第一个测试账号亲眼看到裸露的对象
路径（如 `/obj/login#N`）夹在提示语之间；修复后第二次注册未再出现。
`§9` 格式化自检通过。

### 发现并修复：中文名确认提示里的 `GAME_NAME` 宏字面量泄漏（新发现的模式，未见于此前任何一份档案的记录）

- **症状**：注册流程走到确认中文名的提示时，玩家会看到字面的英文单
  词 `GAME_NAME` 出现在原本应该显示游戏真实名称（"洪荒西游"）的地
  方：`请您给自己想一个符合〖 GAME_NAME 〗神话世界的中文名字...`。
- **根因**：`adm/daemons/logind.lpc` 的 `confirm_id()` 用
  `write(@TEXT ... TEXT)` 多行原始字符串字面量输出这段提示，`GAME_NAME`
  被直接打在字符串内部而不是像同一文件里其它十几处那样用
  `+ GAME_NAME +` 字符串拼接引用宏。LPC 的宏预处理不会展开多行字符串
  字面量内部的标识符，所以这两处 `GAME_NAME` 从未真正被替换成
  `#define GAME_NAME "洪荒西游"` 的实际值，从这份档案诞生起就一直原
  样显示给每一个新注册的玩家。
- **修复**：把这段 `@TEXT` 块改写成普通的 `write()` 字符串拼接（与文
  件里其它 `GAME_NAME` 引用点写法一致），让宏值正确代入。
- **验证**：修复前实测复现（提示语里的字面 `GAME_NAME`）；修复后同
  一提示正确显示"洪荒西游"。已用脚本扫描全档案 `adm/daemons/` 目录
  下所有 `@WORD ... WORD` 多行字符串块，确认没有其它 `GAME_NAME`/
  `LIB_NAME` 被同样错误地嵌入字符串内部的情况。这类"宏字面量嵌进多
  行字符串导致原样泄漏给玩家"是一个新观察到的模式，值得在检查其它档
  案的登录流程时留意（检测方法：grep 每个 `@WORD ... WORD` 块内容是
  否含有已 `#define` 的大写常量名）。

### 测试内容与结果

- **注册**：GB 编码 → 是否中小学生（no）→ `new` → 英文名（8 字符上限，
  超长会被拒绝）→ 中文名（小仙女，确认了上面两个 bug 均已修复）→ 密
  码 ×2 → 邮箱 → 性别（f），全程顺利进入起始房间〖聚见亭〗。
- **门派/技能捷径**：驻留在起始房间的"发礼物的 小老头"（`d/ourhome/
  npc/laotou.lpc`）——`ask laotou about 礼物` 一次性授予 9 项技能（等
  级 100）及 100 万点战斗经验/道行/潜能，`skills` 命令确认发放正确，
  与 `bxsj`/`xiyouji2006` 系的"赠礼 NPC"捷径同类设计，非 bug。附带触
  发了一条"存款不够,需要一两黄金"的消息（疑似自动升级检查在零存款下
  被部分拒绝）——未深究，属于经济系统内部逻辑，不在本轮"仅修程序
  bug"范围内，如实记录为观察而非缺陷。
- **持久化**：真实 `quit`（无反滥用二次确认，直接产生告别文字）后重
  新登录，技能/经验/道行等级全部正确复原（`score` 显示 `[驾轻就熟]`
  与 quit 前一致），但房间重置回了起始房间〖聚见亭〗而非 quit 时所在
  的〖荒郊小店〗——与本轮之前测试过的 `xyj2000f`/`xiyouji450`/
  `xiyouji2006` 三份档案（不同血缘家族）表现出的"固定登录入口"设计完
  全一致，判断为这一批"西游"题材 MUD 共有的既定设计，不是位置持久化
  bug。
- **管理员账号**：`fluffos`/`Mud@2026` 登录，`update /adm/daemons/
  logind` 热更新成功（含本轮三处修复），确认写 ACL 正常——本轮实测
  中这份档案因为 100 个人造人 NPC 的持续后台编译负载，响应延迟明显
  比其它档案更高，命令确认经常要等待数秒才能收到，属于已知的特色负
  载而非 bug，测试时相应放宽了等待时间。
- **战斗、门派拜师（组织路线）、经济/商店**：**未覆盖**——沿着起始
  房间往北探索了数个房间（荒郊野外若干段、荒郊小店），全程未遇到任
  何主动可挑战的敌对目标，源码里唯一疑似"安全陪练木人"的两份文件
  （`d/city/obj/muren.lpc`、`d/obj/misc/muren.lpc`）在 `work/d/` 里没
  有任何房间引用它们，很可能是这份"半成品测试版"存档里从未真正接入
  地图的遗留内容。如实标注为本轮未覆盖，而非默认"和同代码库的其它档
  案一样所以没问题"。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

同一套代码库，更早的一份粗糙快照。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BBS_BOARD`、`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 40 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 332 live occurrences deleted: 331 via scripted sweep (`fix_710_room.py`), plus 1 hand-fixed roommaker-tool template (`obj/roommaker.lpc`, simple string-builder variant, same shape as sibling `xlqy_new2007`). 10 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40076 listening, zero new "cannot replace"/"cannot bind" debug.log lines.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## Round-four follow-up: combat / shop / sect apprenticeship (2026-08-24)

Closed the three gaps flagged as "未覆盖" above. Walking exploration from
the starting room again turned up nothing (the only exits are `north`
into a short dead-end path, and `out` into a fogged teleport) — reachable
hostile NPCs, a working shop, and the three real sect masters all live in
completely separate map regions (`/d/dntg/hgs/*`, `/d/lingtai/*`) with no
room-file path connecting them back to the start area, so this pass used
the admin account's `goto` to reach them directly, per the task's
"map-reading tools" allowance.

- **Combat**: `goto`'d to `/d/dntg/hgs/dongnei` (水帘洞内) and fought
  `混世魔王` (`attitude: "killer"`, one of the few genuinely aggressive
  NPCs in this archive — most `d/dntg/hgs` NPCs are `"peaceful"`/
  `"friendly"`). Combat ran to resolution (the under-powered admin lost
  and was moved to a recovery inn with health restored) with zero new
  lines in `debug.log` — confirmed clean, no bug.
- **Shop/economy**: `吴家当铺` (`/d/dntg/hgs/pownshop`, `HOCKSHOP`/
  `std/room/hockshop.lpc`). Cloned two `mujian` (木剑, value 100),
  `sell`'d both for 50 copper each (matches the coded 50% sell price),
  confirmed the shop's `list` then showed "木剑(mu jian)：一两白银：还
  剩二柄" (100 = the item's real `value`, matches `do_buy`'s full-price
  logic). Sell math, list math, and inventory bookkeeping all checked
  out — no bug found.
- **Sect apprenticeship — real bug found and fixed.** `std/char/
  familymaster.lpc`'s `attempt_apprentice()` (the function every
  NPC-initiated `apprentice <master>` call routes through, per
  `cmds/std/apprentice.lpc`'s `else ob->attempt_apprentice(me)` branch)
  had:
  ```
  if (who->query_family() != me->query_family()) {
    ... "我不收外门弟子" (reject) ...
  }
  ```
  `query_family()` returns `query("family/family_name")`, which is
  `0`/undefined for any player who has never joined a sect — i.e.
  **every single first-time applicant**, always. Since `0` never equals
  the master's own family-name string, this check rejected 100% of
  fresh apprenticeship attempts at all three of the archive's real,
  reachable sect masters (`master yunyang`/方寸山三星洞,
  `ma gu`/月宫, `tidu seng`/南海普陀山 — all three inherit
  `FAMILYMASTER` directly and share this one broken method), making
  organic/in-person sect-joining completely unreachable game-wide. This
  is the same missing-existence-guard shape as AGENTS.md §7.117, just in
  a different file than that sweep covered (`cmds/std/apprentice.lpc`
  and `cmds/std/recruit.lpc` in this archive already had the correct
  `who->query("family") && ...` guard — only `familymaster.lpc`'s
  independent copy of the same check was missing it). The file's other
  4 occurrences of the identical-looking `who->query_family() !=
  me->query_family()` comparison (`expell_me`, `ask_mieyao`,
  `rank_player`, `ask_equip`) were left untouched — those correctly gate
  "must already be a member" actions, where rejecting a family-less
  caller is the intended behavior.
  - **Fix**: `if (who->query_family() && who->query_family() != me->query_family())`.
  - **Verified live**: pre-fix, `apprentice master yunyang` (after using
    admin privilege only to satisfy the unrelated `LEVEL_D->
    can_apprentice()` level-100 gate, and the documented starting-room
    gift NPC for `combat_exp`) reliably produced "我不收外门弟子，小兄
    弟还是另寻他人吧！". After the fix + a full driver restart (an
    in-place `update` of the file recompiles the blueprint but not
    already-`clone()`d room NPC instances, so a hot-reload alone did
    **not** pick up the fix — worth remembering for future spot-fixes
    of files reached only through room-populated clones), the same
    command produced "云阳真人决定收你为弟子" / "你跪了下来...磕了四
    个响头" and `score` correctly showed 门派：`[方寸山三星洞]`,
    师承：`[方寸山三星洞云阳真人]`, 职称: `方寸山三星洞第四代弟子`.
  - Test-account pollution (the `level`/`family` properties set on the
    admin account purely to reach/pass the prerequisite gates) was
    reverted via `call me->delete("family")` / `call me->delete(
    "level")` and saved before logging out; the granted skills/
    combat_exp from the starting-room gift NPC were left as-is since
    that gift is the documented, already-tested normal early-game path
    and a prior session's `save()` already carried the same values.

Driver-side observation (not a mudlib bug, noted for future testers of
this specific archive): this lib's ~100 background `rzr` NPC objects
create a genuinely heavy, **growing** memory/CPU load — an unconstrained
boot reached ~21GB RSS (86% of a 23GB box) within ~14 minutes uptime,
risking a real system OOM. A `ulimit -v` cap of 8GB was too tight (the
driver aborted on `bad_alloc` under real background-NPC load); 18GB was
sufficient for a short test session. Future testers of this lib should
either boot under a generous `ulimit -v` or keep sessions short and
watch `free -h`.


## 深度功能测试 round three batch 4 新角度测试 (2026-09-01)：战斗/拜师/经济角度补完

Dispatched specifically to re-verify combat/apprenticeship/economy for
this archive, under the impression (from the original 2026-08-06/07
entry above) that these three angles were still "未覆盖". They were
**not** — the "Round-four follow-up" section immediately above this one
(dated 2026-08-24) already closed all three gaps and fixed a real bug
(`familymaster.lpc`'s `attempt_apprentice()`). This session's own
findings, to avoid future duplicate effort:

- **Map-connectivity correction to the 2026-08-24 entry**: that pass
  states "no room-file path connecting them back to the start area" for
  `/d/dntg/hgs/*` and had to use admin `goto`. This is not quite right —
  `/d/ourhome/xiaoting.lpc`'s (`聚见亭`, the fixed start room) `out`
  command (`do_out()`) directly `ob->move("/d/dntg/hgs/entrance")`s the
  player, no wizard privilege needed. A plain new player who types `out`
  (the room's own long-desc explicitly invites this: "跨出栏杆往外一
  走(out)") lands in `〖仙石〗` (Huaguoshan) and can walk the entire real
  map — `southdown→westdown→southdown→west→south→south→east→south→
  south` reaches 傲来国 (Aolai) and its 东方武馆 (a *second*,
  fully-independent apprenticeship system from the one the 2026-08-24
  fix covers, see below). Re-tested this exact `out` path fresh this
  session and it works. Worth flagging since "no path, must use goto"
  in the prior entry could misdirect a future tester into assuming
  ordinary players can't reach the real content — they can.
- **Combat — re-confirmed clean, real damage, real death**: fought
  `小猴子` (monkey1.lpc, `combat_exp` 50) and `大马猴` (monkey2.lpc,
  `combat_exp` 5000) at `/d/dntg/hgs/up1` with a fresh level-0 test
  character (`xlqytsti`/小仙女) — both died to real, narrated combat
  ("小猴子死了。"/"大马猴死了。"), `score`'s 死亡 counter incremented
  correctly (`杀死敌人：1 名` → `2 名`). Zero new `debug.log` lines
  either fight.
- **Player death + revival — new, not covered by either prior pass**
  (2026-08-24's combat test only exercised the *admin* account losing a
  fight). Forced with `smash xlqytsti` from an admin session: "只见天上
  一道闪电不偏不倚地击中你。你死了。" — character revived cleanly and
  immediately at `〖南城客栈〗` (a different, dedicated revival room from
  the fixed quit/reconnect start room), health bar back to full
  (`〖气血〗` full/`充沛`), inventory fully intact (money + worn login
  clothes untouched), `score`'s 死亡 counter unaffected (only affects
  杀死敌人, not a death tally shown here). Zero `debug.log` errors
  across the whole death→revival sequence.
- **Sect apprenticeship, second independent system — works, not the
  same code path as the 2026-08-24 fix**. `/d/dntg/hgs/wuguan/*`
  (东方武馆, the Dongfang family's martial hall in Aolai) is a
  completely separate custom implementation (`npc/zongguan.lpc`'s
  `ask_join()`, triggered by `ask boyu about join`) — it does NOT
  inherit `FAMILYMASTER` and does not call `attempt_apprentice()`, so
  it was never touched by the `familymaster.lpc` fix. Tested fresh:
  `ask boyu about join` (with a level-0, age-14 test character, both
  under the master's `age>17`/`combat_exp>60000` reject thresholds)
  correctly set `wuguan/join`, and the previously-locked `skills
  dongfang cong` command (gated on `query("wuguan/join")`) immediately
  started working, printing the instructor's real 6-skill roster. No
  bug found in this second system either.
- **Economy/shop — re-confirmed clean, exercised further than
  2026-08-24's plain buy/sell.** `吴家当铺` (`/d/dntg/hgs/pownshop`,
  same shop as the prior pass). This time funded the test character via
  admin `clone`+`give` (3 gold total, then a `choupao` robe) and
  exercised `value`/`pawn`/`retrieve`, not just `list`/`sell`:
  `value choupao` → "绸袍价值六两白银...典当可以拿到一张当票...卖断可
  以拿到三两白银" (correct pawn-vs-sell price split); `pawn choupao` →
  correctly moved the robe out of inventory in exchange for a `当票`
  (pawn stamp), no `destruct` on a still-owned item; `retrieve stamp` →
  correctly returned the robe AND deducted a real 60-wen redemption fee
  from the character's own carried cash, with **correct
  gold→silver→coin denomination-breaking change** (3 gold → 2 gold +
  99 silver + 40 coin after the 60-wen fee) — this is real, working
  multi-denomination currency math, not a stub.
- **`give <item> to <player>` — real transfer confirmed, not the
  §7.199 pattern.** This archive's `cmds/std/give.lpc` is a different,
  independent implementation from the one that had the §7.202-adjacent
  money-destruction bug on `fysjmb` — its whole-item path does a real
  `obj->move(who)` unconditionally for any `userp(who)` recipient, no
  `query_is_money()`+`destruct()` shortcut anywhere in the file. Live
  `give gold to xlqytsti` (admin→player) correctly moved a real,
  spendable 3-tael gold stack (confirmed via the pawnshop transaction
  above, and again after a real quit+reconnect — see next point).
- **Currency persistence — independently checked, this archive is
  NOT in the AGENTS.md §7.199 `fysjmb`-lineage 16-lib list, confirmed
  why.** `work/std/money.lpc`'s `query_autoload()` is live/uncommented
  (`string query_autoload() { return query_amount() + ""; }`) — the
  exact opposite of the §7.199 bug shape. Verified live: a real `quit`
  while carrying 3 gold's worth of currency produced NO "你丢下" drop
  message for the money (only for an unrelated carried robe, see
  below), and a fresh reconnect showed the exact same currency
  (`四十文钱`/`九十九两银子`/`二两黄金`) still in inventory. Money
  persistence across quit is fully correct here.
- **Investigated but NOT a bug — ordinary equipment (as opposed to
  money) does not survive a normal `quit`, by design.** Carrying a
  cloned `choupao` (绸袍/robe, an ordinary `CLOTH`-class item, not a
  quest item) through `quit` produced "你丢下一件绸袍。" — dropped in
  whatever room the player happened to quit in, not saved. Traced to
  `std/equip.lpc`'s `query_autoload()` being hardcoded `return 0;`
  (unconditional, not a disabled/commented accessor like the §7.199
  money case) with **no matching `autoload(string param)` receiver
  defined anywhere in the whole EQUIP class hierarchy** — so even
  flipping this one return value would not actually restore anything
  (a freshly-`new()`'d item would come back blank, since there's
  nothing to call `->autoload(param)` on). This is a structurally
  different shape from §7.199 (that class had BOTH an intact receiver
  and a merely-disabled accessor — a true one-line regression; this
  class has neither half of a working pair, so there is nothing to
  "restore"). Corpus-check: `xlqy_new2007` and `xyj2000f` (both
  confirmed siblings/lineage-mates of this archive) carry the
  byte-identical `int query_autoload() { return 0; }`, and an unrelated
  lineage (`rzrmud`) has the same line too — while `shzs` (a genuinely
  different, unrelated codebase) has a real working
  `query_autoload()`/equip-state pair, proving the *concept* is a
  normal thing for this class of mudlib to support, just not
  implemented here. Strong evidence this is deliberate, not an
  oversight: `feature/autoload.lpc`'s `restore_autoload()` unconditionally
  re-grants every female character a fresh `/obj/loginload/skirt.lpc` +
  `/obj/loginload/shoes.lpc` (male: `linen.lpc`) on every single
  login/reconnect regardless of what they were wearing before — a
  dedicated "you'll never end up literally naked" safety net that only
  makes sense to build if the designers already expected ordinary worn
  equipment to NOT survive a quit. Left untouched, documented as an
  observation per this project's "never fix content/design choices"
  rule — flagging for any future tester who finds it again so it isn't
  re-investigated from scratch.
  - Narrower, separate anomaly noticed in passing, also left unfixed:
    `d/obj/cloth/shoes.lpc` and `d/obj/cloth/skirt.lpc` (a *different*,
    loot/shop-obtainable pair from the `/obj/loginload/` login-freebie
    pair above) each carry a commented-out
    `//int query_autoload() { return 1; }` — the literal §7.199 shape
    (disabled override on a class with the base already at 0). But
    `skirt.lpc` has `set("value", 0)` (worthless) and both are
    `female_only` cosmetic items with no other special-cased state;
    uncommenting either alone would not achieve real persistence either
    (equip's base class still has no `autoload()` receiver, same
    problem as above) and would just make these 2 minor items behave
    identically to the several dozen *other* individually-opted-in
    special items already in the codebase (`shen_cloth.lpc`,
    `gold_cloth.lpc`, the `obj/club/*_mark.lpc` quest tokens, etc. —
    all `return 1;`, uncommented, and presumably each paired with its
    own bespoke restore logic this survey didn't audit). Not confident
    enough this is a real regression (vs. two dev leftovers with no
    functional difference from the base-class default either way) to
    touch; documented for anyone who revisits equip-persistence in this
    lineage.
- **Testing-methodology finding, not a mudlib bug**: `scripts/
  tmux_mud.sh`'s `telnet` launcher is **not 8-bit clean** in this
  environment — typing a literal multi-byte UTF-8 Chinese name (e.g.
  `小仙女`) through it and reading it back via `tmux capture-pane`
  showed the correct characters (that's the local pty's own echo, not
  what actually reached the server), but the driver-side
  `check_legal_name()`/`is_chinese()` check reliably rejected the exact
  same name that a raw-socket client (`scripts/mudclient.py`, or `nc`
  launched inside the same `tmux_mud.sh` harness in place of `telnet`)
  accepted immediately, no rejection, first try. `telnet -8` did NOT
  fix it. This is almost certainly BSD/inetutils `telnet`'s classic
  NVT-ASCII high-bit stripping on the outbound half of the connection,
  unrelated to this archive's own `AGENTS.md §15h` UTF-8 fix (which is
  correctly in place and works fine once the bytes actually arrive
  intact). **Actionable for future testers of any lib**: if a Chinese
  name/input is spuriously rejected by `is_chinese()`-style checks
  through a `tmux_mud.sh` telnet session, re-test with `nc` in the same
  tmux pane (`tmux send-keys ... "nc HOST PORT"` in place of
  `"telnet HOST PORT"`) before concluding it's a real mudlib bug — this
  cost significant time on this session before the raw-socket
  cross-check caught it.
- **Boot-time responsiveness, amplifying the existing "heavy CPU load"
  observation above**: this session's fresh boot took **15-20+ minutes**
  before the socket layer was usably responsive to real player input —
  far worse than the "several seconds" the original 2026-08-06/07 entry
  reported, and the growing-RSS/OOM-risk entry above didn't measure
  responsiveness at all. Root cause confirmed via source read:
  `manmade_npcd.lpc`'s `generate_npc()` call_out fires every 5 real
  seconds and spawns one new autonomous NPC into a random location from
  a ~70-entry sitewide list until `max_npcs` (100) is reached — each
  spawn's first-ever visit to its target room triggers a real lazy
  compile of that room and everything it pulls in, and under this
  ASAN/UBSAN debug driver those compiles are slow enough that the
  *entire* backend loop (including accepting new connections and
  servicing existing ones) stalls for the whole ramp. Confirmed the
  ramp is genuinely bounded (CPU dropped to idle and the socket layer
  became immediately responsive within seconds of a re-boot with the
  ramp's two `call_out()`s temporarily commented out, then reverted
  before committing — this was a throwaway local test edit only, never
  part of the committed diff). Not a bug — the ramp completing is the
  intended one-time-per-30-minutes behavior
  (`shuffle_npc`/`generate_npc` re-arm on a 1800s/5s cycle respectively)
  — but worth recording the real magnitude for whoever next needs a
  fast, usable boot of this specific archive: expect 15-20 minutes of
  near-unresponsiveness after every cold boot before testing normally,
  or temporarily comment out the two `call_out()` lines at the end of
  `manmade_npcd.lpc create()` for a fast local test session (revert
  before any commit).

No new mudlib bug found or fixed this session — this was a genuine,
thorough re-attempt at the three flagged angles (plus a fourth,
previously-untested apprenticeship variant) and all of it held up.


## AGENTS.md §7.19 fix: enable_player() reentrancy from init()

`feature/command.lpc`'s `enable_player()` (wrapper around
`enable_commands()`) was reachable from an NPC's `init()` (via the
shared `std/char.lpc` `setup()` chain), and `enable_commands()` is only
safe to call from `create()` -- calling it again on an object already
`living()` makes the driver re-invoke that same object's `init()` as a
side effect, which recursed back into `enable_player()` on the same call
stack until "Too deep recursion" aborted the boot on a room's first-ever
visit. Fixed with a true reentrancy flag (`in_enable_player_now`, set at
entry, cleared before every return), NOT a `living()`-gated guard --
`disable_player()` in the same file legitimately re-calls
`enable_commands()` while already `living()` (sleep/wakeup via
`cmds/std/sleep.lpc`, revive via `feature/damage.lpc`), which a
`living()` guard would silently break. Verified via `lpcc --batch`
single-file compile check (PASS). Part of the corpus-wide §7.19 sweep
(Batch C).
