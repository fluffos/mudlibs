# 西游记.rar → `xiyouji` (archive #84)

- **Archive**: `archives/西游记.rar` (plain, ~9.9MB). Extracted root:
  `xyj/` with the actual mudlib at `xyj/world/`, alongside a `config.cfg`,
  `start-xiyou`/`start-xiyou.BAK` launch scripts, a `readme`, and prebuilt
  Windows binaries (`mudos.exe`, `driver.exe`) — the latter ignored per
  convention, our own `build-debug` driver used throughout.
- **Self-identified name**: `config.cfg`'s `name :` field (once decoded)
  reads `西游记`; the live banner also renders `Ａ Ｊｏｕｒｎｅｙ ｔｏ
  ｔｈｅ Ｗｅｓｔ`, `Version 2.01 Copyright 1996-1998 by XYJ Wiz Group`,
  and lists mirror sites (`xiyouji.org`, plus stations in 大连/北京/珠海/
  厦门/杭州/哈尔滨) — this is clearly the **original/upstream "XYJ" ES II
  codebase**, dated 1996-1998 in its own file timestamps (the archive's
  files are stamped 1998-05 through 1998-10), i.e. OLDER than every other
  已-done 西游记-themed sibling. Kept the slug `xiyouji` (the archive's own
  title, undecorated).
- Config: `xyj/config.cfg` (MudOS 0.9.20 format, standard directive set,
  had a `port number : 5555` to replace). Converted to UTF-8 **before**
  any edit (§5), then edited for port/mudlib directory only.
- Port: **40079** (per the task's instruction — next free after
  40076-40078 reserved for archives #27/#82/#83).

## Lineage: confirmed the likely ANCESTOR of the whole "ES II / XYJ" 西游记 family, not a duplicate of any already-done sibling

Per the task's explicit instruction, read `libs/xyj2000f/NOTES.md`
(#15), `libs/mhxy/NOTES.md` (#19), `libs/mhxyqd/NOTES.md` (#56),
`libs/shenmo/NOTES.md` (#73), `libs/xiyouji2003/NOTES.md` (#81) first, then
diffed/md5sum'd this archive's `adm/obj/master.c`, `adm/daemons/chinesed.c`
(the translator daemon; the byte-check daemon is `adm/simul_efun/chinese.c`
here), and `adm/daemons/logind.c` against the raw pre-conversion files of
all five before doing any conversion work.

**Findings**:
- **`adm/obj/master.c`**: header comment reads verbatim `// for ES II
  mudlib // original from Lil // rewritten by Annihilator (11/07/94)` with
  **no additional site-branding/cracker credit line at all** — every other
  sibling's copy of this exact file adds one (`xyj2000f`: "cracked
  by vikee 2/09/2002"; `xiyouji2003`: "Last Modified By Pkyou@xyj
  2002-06-12 19:00"; `shenmo`: "rewritten by djx (09/09/2003), xfan
  3.10"). This is the earliest, least-modified copy of the family's
  master.c seen so far.
- `md5sum`s of `master.c`/`chinesed.c`/`logind.c` did **not** match any of
  the five siblings byte-for-byte (this archive is not a duplicate of
  any of them), but a line-count/structural diff against `xyj2000f`
  and `xiyouji2003` showed a large fraction of lines textually different —
  consistent with those two being LATER, more-modified snapshots of the
  same lineage (both add/change site-specific banners, extra daemons,
  patched bugs over the ~1998-2003 span) rather than unrelated codebases.
  `shenmo`'s `master.c` (also literally rooted at `xyj/` in its own raw
  archive, being a 2003+ "神魔传说" ES II/Neolith mega-fork) is the
  closest structural match by line diff count, but still not identical.
- **`adm/simul_efun/chinese.c`** here is a tiny (16-line) `is_chinese()`/
  `to_chinese()`/`chinese_number()` wrapper delegating to
  `adm/daemons/chinesed.c` (a *translator* daemon, not a byte-range
  checker) — same overall shape as the rest of the ES II family, and the
  same GBK byte-range `is_chinese()` bug (§15h) recurs verbatim.
- **`adm/daemons/logind.c`** (853 lines) has the same registration-flow
  shape as `xianlvqiyuan`/`xkxz2`-style Century/ES-family libs
  (GB/BIG5 prompt → student age-gate → English id → confirm → Chinese
  name → password → confirm password → email → gender → gift/stat-roll
  confirm), but its own `check_legal_id`/`check_legal_name` are defined
  **directly in `logind.c` itself**, not a separate `named.c`/`named.lpc`
  daemon — so the deeper `named.lpc` PATH()/sliding-window fix from §15h
  did not apply here (there's no such file in this archive at all).

**Conclusion**: this archive is a genuine, distinct member of the
"ES II / XYJ" lineage shared with `xyj2000f` (#15), `mhxy`/
`mhxyqd` (#19/#56), `shenmo` (#73), and `xiyouji2003` (#81) —
almost certainly their common **ancestor snapshot** (oldest file
timestamps, least site-specific modification) — but NOT a byte-duplicate
of any of them. Known-lineage fixes (§15h chinese-detection, dns_master
preload exclusion, master.lpc valid_write/valid_read shape) were ported
proactively; fixes specific to a LATER snapshot's added features
(convertd.lpc's Greek-table typo, §8h) were independently re-discovered
here since this codebase's own copy of convertd.lpc has the bug too (see
below) — expected, since §8h itself is documented as recurring across the
whole family.

**Flag for later cross-check**: archives #82 and #83 (processed
concurrently by sibling agents, not yet available to read at the time of
this pass) are also 西游记-themed per the task description. A future pass
should diff this archive's `adm/obj/master.c`/`adm/simul_efun/chinese.c`/
`adm/daemons/logind.c` against whatever `libs/<slug>/raw/` those two
archives extract to, to determine if either is an even-closer sibling or
duplicate of this one. (One such sibling, working under slug
`xiyouji2006`, was observed running concurrently on this same host during
this pass — its own separate NOTES.md should be consulted once available.)

## Fixes applied (with rationale)

1. **§15h — GBK byte-range Chinese-detection bug**, in
   `adm/simul_efun/chinese.lpc`'s `is_chinese()`: replaced the byte-range
   check (`strlen(str)>=2 && str[0]>160 && str[0]<255`) with a CJK
   Unicode codepoint range check (`strlen(str)>=1 && str[0]>=0x4e00 &&
   str[0]<=0x9fff`). Without this, every real Chinese name is silently
   rejected at registration (§15h's core, most-impactful finding across
   the whole project). Also fixed `check_legal_name()` in
   `adm/daemons/logind.lpc`: halved the byte-calibrated length bounds
   (`strlen<2`→`strlen<1`, `strlen>12`→`strlen>6`, matching what the
   error message already says: "一到六个中文字" = 1 to 6 Chinese
   characters) and dropped the `i%2==0 &&` byte-alignment gate on the
   per-character `is_chinese()` sliding check (every UTF-8 index is
   already one full character, not every-other-byte).
2. **§15p — proactively excluded `/adm/daemons/network/dns_master` from
   `adm/etc/preload`** before the first boot attempt. This lib's
   preload list had it listed (confirmed via `adm/daemons/network/
   dns_master.c`'s presence and its own hardcoded remote boot-server
   dependency).
3. **§15ai — a dns_master-absence shutdown(1) gate in `logind.lpc`'s
   `encoding()` callback**. Found on read-through, exactly as the task
   description flagged as a known risk of the §15p exclusion: a
   "mirror-IP-verification" check
   (`if(!find_object(DNS_MASTER) || !"/adm/daemons/band"->check_ip(...))
   shutdown(1);`) that unconditionally treated "daemon never loaded"
   (guaranteed true here, since we exclude it) as "verification failed"
   and called `shutdown(1)` on the **entire driver process** on the very
   first connection. Fixed by changing the guard from `!find_object(...)`
   to `find_object(...) && ...` — daemon absent now degrades to "skip the
   gate" instead of "gate failed", matching the established fix pattern.
   Applied proactively before ever booting (read the code first, per the
   task's explicit instruction to check every catalog section against
   the actual source before boot).
4. **§8h — `convertd.lpc`'s Greek/CJK-table stray-backslash typo**,
   recurring exactly as documented for `xyj2000f`/`mhxy`: **45
   separate lines** (not just the usual handful) had a stray literal
   backslash immediately before the closing quote of a two-character
   string entry (`"α\",` → `"α",`, `"功\",` →
   `"功",`, etc — one base character + a trailing Private-Use-Area
   companion codepoint that is itself completely legitimate content in
   this BIG5/GB conversion table, confirmed by cross-checking ~1000 other
   *unaffected* lines with the identical "char + PUA companion" shape
   compiling fine). Root-caused via `lpcc`'s exact error line + a Python
   pass over the decoded file finding every line with an odd number of
   trailing backslashes before the closing `",`/`"` — not a blind
   sed (this file's CRLF-preserving §8h counterexample was specifically
   checked for and confirmed absent: the fix script here operated on
   already-LF-normalized decoded text and verified zero remaining hits
   afterward).
5. **§3's blanket `static`→`nosave` sed collided with `"static/CRASHES"`-
   and `"static/PURGE"`-style log-path string literals** (the exact
   counterexample already documented for `moniHuafu`, archive #57):
   `adm/obj/master.lpc` (4 occurrences, `"static/CRASHES"`),
   `adm/daemons/securityd.lpc` + `adm/daemons/ss.lpc` (1 each,
   `"static/promotion"`), `cmds/usr/suicide.lpc` (`"static/SUICIDE"`),
   `cmds/arch/purge.lpc`/`purgehouse.lpc` (`"static/PURGE"`),
   `cmds/wiz/call.lpc` (`"static/CALL_PLAYER"`) — all reverted from the
   sed's `"nosave/..."` back to the original `"static/..."`, confirmed
   against the raw pre-conversion files first (cross-checked with
   `iconv`-decoded originals to be certain these strings were genuinely
   `"static` in the archive, not something the encoding pass introduced).
6. **§15w — `log_error()`/`APPLY_LOG_ERROR` broadcasting every compile
   WARNING (not just real errors) to the connected non-wizard player**.
   Found live during the FIRST full interactive registration test: the
   default error message (`你发现事情不大对了，但是又说不上来。`)
   spammed **~26 times** during ordinary post-registration play (the
   first-ever lazy compile of every never-preloaded room/feature file
   reached by `make_body()`/`enter_world()` — `std/char.lpc`'s
   `#pragma`, `feature/*.lpc`'s unused-local-variable warnings, etc — all
   harmless, but all routed through `master.lpc`'s `log_error()`, which
   didn't distinguish a warning from a fatal error). Fixed by gating the
   player-facing broadcast on `strsrch(message, "warning:")==-1` (still
   logs everything to `home + "log"` regardless). **Re-verified with a
   fresh registration after the fix and restart: zero spam.**
7. **Absolute angle-bracket `#include`, §15t pattern #1**:
   `d/obj/books-nonskill/book-qujing.lpc` had `#include
   </d/qujing/obstacle.h>` (an absolute path inside angle brackets, which
   this driver's `<...>` resolver never special-cases) — converted to
   quoted form `#include "/d/qujing/obstacle.h"`. Confirmed
   `book-qujing` is real, referenced content (`d/westway/npc/laoren.lpc`,
   `d/city/npc/jieding.lpc` both `new()`/`carry_object()` it), not dead
   content — worth fixing, not just noting.
8. **`..`-relative `#include`, §15t pattern #2**:
   `d/ourhome/honglou/npc/niu.lpc` had `#include "../honglou.h"` (this
   driver disallows `..` in `#include` paths outright) — repointed to the
   real absolute quoted path `"/d/ourhome/honglou/honglou.h"`.
9. **§8d-style local header one directory removed from its user**: three
   files under `d/kaifeng/npc/old/` (`shan.lpc`, `zhi.lpc`, `bei.lpc`)
   `#include <quest_ak.h>`/`<reporting.h>`, which exist one directory UP
   at `d/kaifeng/npc/` (this driver's `get_include_path()` fix only
   prepends the COMPILING file's own directory, not its parent, so this
   doesn't resolve automatically) — every OTHER file referencing these
   headers already lives directly alongside them and compiles fine.
   Fixed narrowly (not a generalized parent-directory search, to avoid
   unintended side effects elsewhere) by copying both headers into
   `d/kaifeng/npc/old/` too.
10. **Pre-existing typo, §10-shaped missing closing quote**:
    `d/obj/books-nonskill/hmeng014.lpc` had `string name = "《红楼梦》
    第十四回;` (missing closing `"` before the `;`), confirmed against
    12+ sibling `hmeng0NN.lpc` files in the same directory which all use
    the correct `"...";` form — fixed to match.
11. **Pre-existing typo, corrupted/dropped-byte argument**: `data/
    armor.lpc`'s `do_closecommand()` had `ob->set_alias(cmd, ");` (an
    unterminated string literal swallowing the next several lines,
    cascading into a wall of "Illegal character" errors reported much
    further down the file) — confirmed via the raw pre-conversion bytes
    that this was originally `set_alias(cmd, "<one genuinely-undecodable
    byte>");`, dropped by the lossy `iconv -c` recovery pass, and
    confirmed via the sibling `do_opencommand()` function IN THE SAME
    FILE (`ob->set_alias(cmd,0);`) what the correct call shape actually
    is — fixed to `ob->set_alias(cmd,0);` to match.
12. **Mapping-literal syntax typo**: `d/gao/obj/pen.lpc`'s `is_container()`
    had `set("objects", (["/u/bula/gao/obj/kaoji"]) );` — a mapping
    literal with a bare key and no `:value`, which this driver rejects as
    a syntax error (compared against `d/changan/playerhomes/h_croc.lpc`'s
    own, valid, `set("objects", ([ path:1, path:1 ]));` usage of the same
    `"objects"` property) — added the missing `:1`. The referenced target
    (`/u/bula/gao/obj/kaoji`) still doesn't exist anywhere in the archive
    (genuine content gap, not fabricated), so this only takes the file
    from a hard compile error to a graceful missing-content no-op.
13. **Orphaned junk data mistakenly caught by the `.c`→`.lpc` rename,
    §12 pattern**: `obj/file.c` (416 bytes of literal random binary
    noise, `file` reports "data", confirmed unreferenced anywhere via
    `grep -rn "/obj/file\b"`) — renamed to `obj/file.orphaned-junk` so it
    no longer pollutes the lpcc sweep's pass/fail signal.
14. **Corrupted pre-existing NPC-vendor save data, §15m-adjacent**: four
    `data/npc/boss/*.o` files (`city_kongfang.o`, `city_weiluqi.o`,
    `laosun.o`, `yangzhongshun.o`) are genuinely random/binary garbage
    (confirmed byte-identical to the raw un-touched archive via
    `md5sum` — not something our conversion pipeline broke), which would
    throw `*restore_object(): Illegal file format` at runtime the first
    time a player actually visits the NPC that owns one (found via the
    lpcc sweep compiling `/d/city/bookstore` in isolation, which clones
    its bookseller NPC). Moved out of the way into `data/npc/boss/
    corrupted-original-backup/` (not deleted) so `restore()` finds
    nothing and proceeds cleanly, matching the established `zhonghua2`
    precedent — this was NOT triggered during the real boot/registration
    test (the bookstore isn't on the path from the start room), so it
    wasn't blocking anything we tested, but is a real latent crash for
    normal play.
15. **§14 — `valid_override()` given the documented 3rd `main_file`
    parameter.** `master.lpc`'s copy was the old 2-arg form, and
    `adm/simul_efun/object.lpc` (an `#include`d fragment of
    `simul_efun.lpc`, not that file itself) defines its own `destruct()`
    override calling `efun::destruct()` — the 2-arg check's `file ==
    SIMUL_EFUN_OB` test is false for this fragment (file is the physical
    `object.lpc`, not `simul_efun.lpc`), which per the docs is exactly
    the scenario the 3rd parameter exists to fix. Applied proactively;
    per the catalog's own note this may never surface as a real boot
    symptom, but the fix is free and correct.

## What was checked and confirmed NOT needed

- **§4 (lazy security-daemon load in `valid_read`/`valid_write` causing
  infinite recursion)**: `master.lpc`'s `valid_write`/`valid_read` only
  do `if (ob = find_object(SECURITY_D)) return ...->valid_write(...);
  return 0;` — no `load_object()` call at all, so the recursion trap
  cannot occur. Confirmed by reading the source, not by hitting the bug.
- **§7 (missing `get_root_uid()`/`get_bb_uid()`)**: both already present
  in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID` (both defined in
  `include/globals.h`).
- **§15 (nitan-family shared simul_efun dbase architecture bug)**:
  `adm/simul_efun/wizard.lpc` (18 lines) and `adm/simul_efun/object.lpc`
  (89 lines) define no bare `set`/`query`/`delete` at all — every
  relevant object (`std/char.lpc`, `std/room.lpc`, etc) `inherit
  F_DBASE` directly instead, the architecturally-correct per-object
  pattern already confirmed safe on `rzrmud`/`xkx2001`-lineage libs.
- **§15l (master.lpc destructing `SIMUL_EFUN_OB` in `create()`)**:
  `master.lpc create()` is just `write("master: loaded
  successfully.\n");` — no destruct call at all.
- **§15ae (`private nomask` command-hook breaking `add_action` dispatch)**:
  `feature/command.lpc`'s `command_hook()` is declared plain `nomask int
  command_hook(string arg)` (no `private`) — a commented-out `// private
  nomask int command_hook(string arg)` line directly above is a stale
  doc-comment, not live code. Confirmed both by grep and by the live
  `look`/`score` test actually working.
- **§15ag (`ed_start`/`ed_cmd`/`query_ed_mode`, `__OLD_ED__`)**: zero
  hits anywhere in the tree.
- **§15al (`crypt(str,0)` random-hash-per-call footgun)**: `crypt(pass,0)`
  IS used (in `new_password()`/`cmds/usr/passwd.lpc`), but only ONCE, to
  produce the initially-STORED hash — every later comparison uses
  `crypt(candidate, stored_hash)` (a real string salt extracted from the
  stored hash), which is deterministic regardless of the `crypt(_,0)`
  quirk. Verified independently with Python's `crypt` module against an
  actual stored hash from a real registered character
  (`qinfeng`/`test1234`) — reproduces byte-for-byte. No client-side
  challenge/response protocol exists here that would need a second,
  independently-computed `crypt(_,0)` call to match (that's the failure
  shape §15al actually describes, and it doesn't apply to a plain
  password-login flow like this one).
- **§15am (`file_size()==-1` truthiness trap)**: the one `file_size(...)`
  bare-condition usage found (`adm/simul_efun/file.lpc`'s `assure_file()`)
  already correctly compares `!=-1`. `adm/obj/master.lpc`'s
  `preload()` uses `file_size(file + ".lpc") == -1` (also correct — and
  already auto-adjusted by `convert_lib.sh`'s literal-`.c`-reference
  fixer from the original `file_size(file + ".c")`, confirmed).
- **§15ac (bare `SAVE_EXTENSION` vs `__SAVE_EXTENSION__`)**: one hit
  (`include/net/ftpdsupp.h`), but dead code behind `#ifdef
  GUEST_WIZARD_FTP`, which is explicitly `#undef`'d in `ftpdconf.h` —
  never compiled.
- **§15n/§15o (custom securityd ACL blocking mid-connection lazy
  compiles / missing get_include_path)**: `securityd.lpc`'s `valid_read`
  unconditionally `return 1;` (fully open reads, the ACL logic that
  exists is commented out) — no read-permission gate exists at all, so
  §15n's specific failure mode can't occur. `master.lpc` has no
  `get_include_path()` override, but this lib has no
  `#include <local.h>`-next-to-its-user idiom in the boot/registration
  path (checked: all 58 `#include <x.h>` angle-bracket references in the
  tree resolve against the global `include/` directory, confirmed by
  name against `ls include/*.h`, except the two §15t/§8d cases fixed
  above) — not needed.
- **§15x (hardcoded `MUD_PORT` mismatch)**: `master.lpc`'s `connect()`
  doesn't reference a mudlib-side port constant at all; the driver's own
  `get_config(__MUD_PORT__)`-style dynamic lookup is used wherever the
  port is needed. No fix required.
- **§15u (dormant "phone-home" destructive license check)**: grepped
  `securityd.lpc`/`master.lpc` for `rm(`/`unlink`/`shutdown(`-on-mudlib-
  root shaped functions; none found beyond the already-addressed §15ai
  gate (which is a `shutdown(1)`, not a mass-delete).
- **§15v (`LONELY_IMPROVED`-style always-on legacy-driver flag gating
  `efun::X()` calls to nonexistent functions)**: not a "nitan/Lonely"
  lineage lib; no such flag or gating pattern present.
- **§15af (log_error calling wizardp() during compile-time before
  securityd loads)**: `master.lpc`'s `log_error()` only calls
  `wizardp(this_player(1))` **inside** an `if(this_player(1))` guard —
  during preload (before any connection exists), `this_player()` is
  always 0, so the dangerous lazy-load-triggering call never fires in
  the vulnerable early-boot window. Confirmed by reading the code, not
  by hitting a crash — this file's shape differs from `shenzhou`'s
  unguarded version.

## Fullwidth punctuation / mojibake escape sequences (harmless, not fixed)

`daemon/class/fighter/oldstuff/champion.lpc` (5 hits) and `obj/npc/
garrison.lpc` (2 hits) both have a stray literal backslash immediately
before a bare Chinese character inside a string (`"水烟阁传功\使"`,
`"许\多武林人物"`) — confirmed pre-existing in the raw archive, and
confirmed **non-fatal** (`warning: Unknown escape sequence`, not an
error) both via the lpcc sweep and by cross-referencing that these two
files are never reached by the registration/`look`/`score` test path.
Left as-is per the project's policy of fixing only what a real
error/lpcc-FAIL demonstrates matters, not every cosmetic warning.

## Genuine archive-content gaps (not fixed, not fabricated)

- **Missing `/d/city/npc/obj/*` directory entirely** (8 distinct NPC
  clothing/weapon call_other targets — `choupao`, `cloth`, `sengpao`,
  `longpao`, `changqiang`, `caidao`, `blade`) — confirmed the whole
  directory doesn't exist anywhere in the archive; several `/d/city/
  npc/*.lpc` NPC files reference it in `create()`.
- **`/obj/longsword`, `/u/mes/obj/blade`, `/d/changan/playerhomes/npc/
  {babyslimia,babycroc}`** — individually missing `call_other()`/`new()`
  targets referenced by a handful of NPC/room files, confirmed absent
  anywhere in the tree.
- **Several `daemon/class/oldstuff/*/master.lpc` and
  `daemon/class/fighter/oldstuff/*` files grant skills
  (`essencemagic`, `perception`, `celestial`, etc) that were never
  actually implemented** in this archive's skill system (`*F_SKILL: No
  such skill` at runtime) — the directory name "`oldstuff`" strongly
  suggests already-deprecated/retired class content in the *original*
  game, not something broken by this conversion.
- **`d/obj/fabao/EXAMPLE.lpc`**: a deliberate, incomplete wizard-facing
  code TEMPLATE (own header comment: "some files to inherit, include,
  and some functions to declare... notice from the declarations that the
  fabao can be used as a weapon alone") with real syntax errors — never
  referenced by any other file (`grep -rln` came up empty besides
  itself), not live game content.
- **5 genuinely TRUNCATED source files, confirmed pre-existing in the
  raw archive (not a conversion artifact)**: `cmds/imm/cast1.lpc` (a
  wizard-only "cast a spell on someone else's behalf" admin command,
  cuts off mid-string inside `main()`, 0 closing braces — encoding
  conversion of this file also needed a manual Python
  `errors='ignore'` decode pass since `convert_lib.sh`'s automated
  iconv attempt failed outright on the truncated trailing byte),
  `d/nanhai/obj/jingu2.lpc`, `d/qujing/wudidong/npc/fangzhang-jail.lpc`,
  `d/qujing/jindou/obj/zhuofake.lpc`, `d/qujing/jingjiling/jingji6.lpc`
  — all cut off mid-statement with no closing braces, all confirmed via
  `git`-free byte inspection to already be this way in the raw `.c`
  files. None of these are on the registration/`look`/`score` path (all
  deep zone/NPC content); left as-is, not fabricated.
- **`d/gao/obj/pen.lpc`'s `is_container()`** still references a
  nonexistent `/u/bula/gao/obj/kaoji` (only the mapping-syntax half of
  this was fixed, per item 12 above — the missing target itself is a
  content gap, not something to invent).

## Re-verification pass (QA sweep, later session)

Re-tested the full flow end-to-end again this pass (still clean, zero
`执行时段错误` in `debug.log`). **Found and fixed one real, shared-lineage
bug while cross-checking against sibling `xiyouji450`'s own re-verification
pass**: `adm/daemons/logind.lpc`'s `get_name()` had a stray, pre-existing
debug leftover `printf("%O\n", ob);` right after a new player's Chinese
name is accepted -- dumps a raw internal object reference (e.g.
`/obj/login#0`) straight to the connecting player, on every single
registration. Purely cosmetic (never affected registration itself --
confirmed the Chinese name still gets set and stored correctly either
way) but visibly unprofessional. **The exact same leftover was found in
all three other siblings in this session's batch**
(`xiyouji2003` -- 2 occurrences, `xiyouji2006`, `xiyouji450`), confirming
shared lineage at the source level; removed in all four. Re-verified with
a fresh registration (`qfrong`/秦荣) after restarting the driver: no
stray object-reference text anywhere in the transcript, `look`/`score`/
`quit` all still correct.

## Boot + registration + post-login command test (the actual verification)

Booted `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/xiyouji/` (via the tool's `run_in_background`, after one earlier
attempt via `nohup setsid ... & disown` died to the documented
unexplained-external-SIGTERM issue — matches AGENTS.md's own note about
this exact symptom on this host). `debug.log` shows only compiler
WARNINGS (unused locals, `#pragma` notices, "Illegal to declare nosave
function" — all cosmetic/non-fatal) and ends cleanly with `Accepting
telnet connections on 0.0.0.0:40079.` / `Initializations complete.` — zero
fatal errors, zero segfaults, zero "Too deep recursion".

Full registration + post-login command transcript (via `scripts/
mudclient.py 127.0.0.1 40079 --timeout 25 --idle 0.6`, one continuous
connection, real Chinese name), final confirmation run with a never-before-
used id (`qfengyu`) after the §15w fix landed and the driver was restarted:

```
--send "gb"                        -> GB/BIG5 charset prompt accepted
--send "no"                        -> student age-gate declined
--send "qfengyu"                   -> English id (new, unregistered)
--send "y"                         -> confirmed new-character creation
--send "秦风"                       -> REAL Chinese name, ACCEPTED on the
                                       first try (confirms §15h fix)
--send "test1234"                  -> password set
--send "test1234"                  -> password confirmed
--send "qfengyu@example.com"       -> email
--send "m"                         -> gender: male
--send "y"                         -> accepted the rolled stat block
--send "look"                      -> full room description of 南城客栈
                                       (South-City Inn), NPCs/board listed
--send "score"                     -> full character sheet: 【平民】普通
                                       百姓 秦风(Qfengyu), age/birth date,
                                       all 8 stats, HP/MP bars, food/water
                                       bars, kill counts, 潜能:99
--send "quit"                      -> clean disconnect, "欢迎下次再来！"
```

Zero occurrences of the `log_error()` default-error-message spam this
time (confirms fix #6 above); zero silent/no-op commands (confirms
`add_action` dispatch works, ruling out §15ae); zero missing-environment
symptom (confirms the character actually landed inside `/d/city/kezhan`,
ruling out §15aj). An earlier interactive test (before the §15w fix, id
`qfeng`/`qinfeng`) reached the identical successful outcome but with ~26
spurious default-error-message lines interleaved — that repro is what
found bug #6 in the first place.

`debug.log` after this session: only compile warnings from the lazy
first-time compile of `std/char.lpc`, its inherited `feature/*.lpc`
files, `std/room.lpc`, `d/city/kezhan.lpc`, `feature/equip.lpc`,
`std/bboard.lpc`, `obj/mailbox.lpc` — all cosmetic, zero errors.

## `lpcc_check.sh` sweep results

First pass (before the fixes in items 4/7-14 above): **4921/4988 pass
(98.7%)**, 67 failures.
Second pass (after fixes): **4931/4987 pass (98.9%)**, 56 failures
(`file.lpc`'s rename-away accounts for the total dropping by 1). Memory
stayed healthy throughout both runs (`free -h` never dropped below
~4.4GB free on this 23GB host) — well below the OOM-risk threshold noted
in AGENTS.md §6b, so no need to back off.

Remaining 56 failures triaged by category, all either genuine
archive-content gaps (documented above) or expected `lpcc`-isolation
artifacts per §6b (a room/NPC `create()` calling into another object or
the skill system before anything else is loaded in a bare single-file
compile — e.g. `/d/qujing/pingding/shilang1`'s "Eval interrupted... cost
limit reached" during an isolated NPC-attack-loop compile, or `/adm/
simul_efun/object.lpc` failing standalone since it's an `#include`-only
fragment of `simul_efun.lpc`) — none affect the real boot or the
registration/`look`/`score` test, which is the actual completeness gate
per AGENTS.md's "Definition of done".

## Directories/files created that weren't in the raw archive

- `data/login/{a..z}/` and `data/user/{a..z}/` — the raw archive only
  shipped `c/`, `p/`, `t/`, `w/` shards (`query_save_file()` in both
  `obj/login.lpc` and `obj/user.lpc` shards save files by
  `sprintf(DATA_DIR "login/%c/%s", id[0], id)`/`.../user/%c/%s`) — created
  all 26 letter-shard directories proactively so registration with ANY
  English id doesn't hit a missing-directory write failure (§15ah's
  general lesson, applied preventively rather than reactively here).
- `d/kaifeng/npc/old/quest_ak.h`, `d/kaifeng/npc/old/reporting.h` — see
  fix #9.
- `data/npc/boss/corrupted-original-backup/` — see fix #14.

## Standing scratch-file hygiene

No `boot_stdout.log`/`trace_lpcc.json`/similar left in `libs/xiyouji/`'s
top level or `work/` (checked and removed a stray `work/trace_lpcc.json`
before finishing). `lpcc_batch_raw.log` and `lpcc_fail.log` at the
top level are the standard `lpcc_check.sh` output artifacts, kept per the
same convention every other already-done lib in this project follows.

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  4,930 files reformatted, 53 unchanged, 4 refused (self-check failures
  on messy legacy code, expected). Confirmed the `adm/daemons/
  logind.lpc` `printf("%O\n", ob);` removal from the earlier
  re-verification pass survived reformatting untouched.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified with real Chinese name
  **秦风回** (male, id `qfrevb`), reaching the actual starting room
  (南城客栈/South City Inn), `look`/`score`/`quit` all producing
  correct output.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only expected non-fatal
  preload warnings, no `sockets` package built in). **Full registration
  + login succeeded end-to-end under WASM too** — real Chinese name
  **秦风网** (id `qfwasma`), through gb/age-gate/id/name/password/email/
  gender/gift-accept, landed in the real starting room (南城客栈),
  `look` rendered the actual room description, `quit` disconnected
  cleanly. This lib's `logon()`/registration path does not gate on
  `query_ip_number()`'s format, so it is **not** affected by the
  documented WASM IP-format limitation — a genuinely clean WASM result,
  not just a partial one.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban gates** —
   `adm/daemons/band.lpc`: added `is_local_ip(string ip)` helper
   (127.*, empty/non-string, or non-dotted-quad => local) and
   short-circuited all three entry points the login flow calls:
   `is_banned()`, `create_char_banned()`, `is_strict_banned()`
   (each now `return 0` immediately for local IPs). These gates were
   not actively blocking (shipped ban lists are empty) but are patched
   per standing policy so runtime-added bans can never lock out local/
   WASM play.
2. **Uptime startup gate**: none in this lib (checked `logind.lpc`).
3. **Anti-flood throttles**: none per-IP in this lib. The "玩家已经太多"
   gates are global player-count caps, not per-IP throttles — left
   intact. `SECURITY_D->match_wiz_site()` returns 1 when a wizard has
   no wiz_sites entry, so it does not block fluffos — left intact.
4. **Admin account seeded** — id `fluffos`, password `Mud@2026`,
   display name 浮浮 (male), registered through the real flow
   (`gb` → `no` student gate → id → y → name → password ×2 → email →
   gender → accept talents). Granted `(admin)` via `adm/etc/wizlist`
   (`fluffos (admin)`), read by `securityd.lpc::create()`. Verified
   after restart: re-login shows 目前权限：(admin),
   `update /adm/daemons/band` recompiled OK, `goto` worked. Save files:
   `work/data/user/f/fluffos.o` + `work/data/login/f/fluffos.o`
   (untracked, NOT gitignored — orchestrator must `git add`).

Retest: fresh registration (fluffos itself) reached 南城客栈 as
`(player)`, `look` correct; fluffos re-login as `(admin)` with working
wizard commands; `log/debug.log` clean (0 errors).

## 深度功能测试 / Deep functional test (2026-07-24)

Second lineage in the project's round-two deep-playthrough pass (after
`bxsj`, a completely different codebase/lineage — see
`libs/bxsj/NOTES.md`'s "深度功能测试" for the worked-example this pass
follows). Played as an ordinary new player through registration,
exploration, safe combat, organic skill-learning and sect-joining, a real
`quit`, and a real-wall-clock-gap reconnect, native driver
(`build-debug`). Read `doc/help/newbie` in full first (the single
highest-value planning resource, exactly as the methodology predicts —
it named the `fight`-vs-`kill` safety distinction, `apprentice`/`learn`
syntax, and the general command set up front). `doc/help/` also has ~90
other topic files (combat, menpai, individual sect writeups, etc.) but no
separate general-help directory beyond it.

**Test characters** (both kept, not cleaned up, as representative
playthrough evidence):
- id `shenqy`, Chinese name 沈青云, password `Test1234`, male — the main
  playthrough character. State: apprenticed to 秦富 (Qin Fu, 将军府/
  General's-Mansion sect, 4th generation — `将军府第四代弟子`), learned
  `force` (内功心法) to level 1 via the organic teacher-NPC path,
  survived a `fight` against a `huoji` NPC, quit once (dropping its
  starting 粗布衣 per this lineage's item-drop-on-quit design, see
  below) and relogged in successfully with all sect/skill state intact.
  Saves: `work/data/user/s/shenqy.o`, `work/data/login/s/shenqy.o`.
- id `shenqf`, Chinese name 沈青枫, password `Test1234`, male — a second,
  fresh-registration character used specifically to re-verify the
  `zhangmen.lpc`/`room.lpc` fix (below) end-to-end from a clean boot with
  no prior state. Saves: `work/data/user/s/shenqf.o`,
  `work/data/login/s/shenqf.o`.

### Bug found and fixed: unbounded `init()`/`reset()` recursion crashes the FIRST visit to any of the game's 9 sect-entrance rooms

**This is a genuinely new bug class for this project's catalog** — not
the §7.16 rank-decay class (bxsj's bug), and not any previously-cataloged
shape. Filed as file:line `d/jjf/npc/zhangmen.lpc:36/623` (the crash
site) and `std/room.lpc:25` (`reset()`, the structural root).

- **Symptom**: the very first time any player walks into
  `/d/jjf/front_yard2` (练武场, the courtyard housing 将军府's "senior
  disciple" NPC, directly on the only path from the sect's gate to its
  main hall where the sect's actual teacher NPC lives) the connection
  gets a caught-but-real crash: `你发现事情不大对了，但是又说不上来。`
  (this lib's generic non-wizard error message), and `log/debug.log`
  shows `Too deep recursion.` — the driver's call-stack-depth safety
  limit (`CFG_MAX_CALL_DEPTH`, a compile-time constant, currently `150`
  in this build; see "false lead" note below). The exact blamed
  file:line varies run to run (sometimes `zhangmen.lpc:36`+`:623`,
  sometimes deeper inside `reset_me()`, `feature/dbase.lpc`'s
  `query_temp()`, or `std/char.lpc`'s `setup()`) — a strong signal, in
  hindsight, that the recursion is a genuine unbounded *reentrant call*
  cycle rather than one specific buggy line: whichever mudlib function
  happens to be executing at the moment the stack finally tips over gets
  blamed, and that moment is inherently timing-sensitive.
  Player-visible impact: the room usually **still gets entered** (the
  crash is caught) but the NPCs inside render with a corrupted title
  (`0掌门大师兄 大弟子(Zhang men)` — a stray `"0"` from a `family/
  family_name` property read that resolved to `0`/undefined mid-crash),
  and on unlucky timing the move itself can silently fail entirely
  (command produces no visible room description at all). Once the room
  has been visited once and its objects are in memory, subsequent visits
  are clean — **this is a first-visit-only, fresh-boot bug**, invisible
  to any verification pass that doesn't specifically walk a brand-new
  character through content beyond the start room, and easy to miss even
  in manual testing because the crash is silently caught (exactly the
  §10.7 lesson: check debug.log, don't just eyeball the screen).
- **Root cause (two contributing mechanisms, both fixed)**:
  1. **`std/room.lpc`'s `setup()` calls `reset()` synchronously**
     (`this_object()->reset();`), and every room's `create()` ends with
     `setup()` — so `reset()` runs **twice** for a brand-new room: once
     explicitly as the last step of its own `create()`, and once more
     from the driver's own standard "give a freshly-loaded object a
     reset pass" behavior, which can fire for the same object on the
     same underlying trigger (a player's `move()` into it). `reset()`
     populates the room's NPCs via `make_inventory()` → `new(file)` →
     `move(this_object())`, and **only marks that population done at the
     very last line** (`set_temp("objects", ob)`). If a second call to
     `reset()` starts before the first one reaches that last line (i.e.
     is genuinely reentrant, not merely called-again-later), it sees
     `query_temp("objects")` still empty and clones a **second full set**
     of NPCs — and cloning+moving an NPC synchronously fires that NPC's
     `init()`, which for this lineage's `zhangmen.lpc` (below) can itself
     touch the room again, closing a cycle that repeats until the
     driver's call-depth limit aborts it.
  2. **`d/jjf/npc/zhangmen.lpc`'s `init()` self-initializes via
     `create_identity(master, where)`, called with `where` as a bare
     STRING path to the NPC's own room** (`"/d/jjf/front_yard2"`, always
     — every call site in every one of this lineage's 9 sect-`zhangmen`
     copies passes its own home room's path this same way).
     `create_identity()`'s original body, when `where` isn't already an
     object, did an unconditional `call_other(where, "???"); where_ob =
     find_object(where);` purely to force the room to be a resolvable
     object — a force-load-by-path idiom that is fine in isolation but,
     called from *inside* that very room's own first-ever `reset()` (per
     #1 above), the room may not yet be registered as "loaded" from
     `find_object()`'s point of view, so the forced `call_other()` can
     itself trigger the driver to treat the room as needing (re)compiling
     — which runs `create()`/`setup()`/`reset()` on it again, cloning
     `zhangmen` again, calling `init()`/`create_identity()` again. This
     is the second half of the same cycle, and (being *this* lineage's
     own NPC code, not shared driver plumbing) is the more surprising,
     mudlib-specific half.
  Neither mechanism alone reliably reproduced the crash in isolated
  testing (each was independently disabled and retested — see "false
  leads" below); **both together, under this driver's real reset/init
  timing, do.** The fix therefore closes both doors rather than betting
  on which one is "the" cause.
- **Fix** (both parts; each is a defensive reentrancy guard, not a
  behavior change for the normal, non-reentrant case):
  1. `std/room.lpc`: added a `nosave int resetting_now;` flag, checked at
     the top of `reset()` (`if (resetting_now) return;` before doing
     anything else) and cleared at every return path. A reentrant call
     to `reset()` on the same room object is now always a safe no-op;
     the original (outer) call still runs to completion exactly once.
     This is a **lib-wide change** (every room in the game inherits
     `std/room.lpc`) but is provably inert for the overwhelmingly common
     non-reentrant case — confirmed by re-testing several already-known
     good multi-NPC rooms (`d/city/kezhan` with its 2 NPCs, `d/city/
     center`, `d/jjf/front_yard`/`front_yard2` themselves) after the fix
     and seeing identical, correct NPC population every time.
  2. `d/jjf/npc/zhangmen.lpc` (and its 7 sibling per-sect copies, see
     below): added a `nosave int in_init_now;` flag with the same
     guard-at-entry/clear-at-every-return shape around the ENTIRE body of
     `init()`. `init()` is pure one-time setup with no reason to ever be
     legitimately reentrant on the same live object, so skipping a
     nested call is always safe.
  3. Also hardened `create_identity()`'s `where`-resolution itself
     (belt-and-suspenders, on top of #1/#2, not a substitute for them):
     since `where` is, at every real call site in this lineage, always
     the room the NPC was just cloned into, resolve it via
     `environment(this_object())` first and only fall back to the old
     `call_other(where, "???")`/`find_object(where)` force-load dance if
     that doesn't already give the right object. This removes one avenue
     of the room re-touching itself but, per the "false leads" note
     below, was NOT sufficient by itself.
  **Scope**: this lineage ships the identical `create_identity()`/`init()`
  shape in **all 9** of its sect-entrance "senior disciple" NPCs (one per
  sect, matching `help menpai`'s 9-sect list) — `d/jjf/npc/zhangmen.lpc`
  (将军府, live-reproduced and fixed), plus `d/nanhai/`, `d/sea/`,
  `d/xueshan/`, `d/death/`, `d/lingtai/`, `d/moon/`, `d/qujing/wudidong/`
  (all fixed identically, same guard shape, verified each file still
  diffs cleanly against its siblings aside from the expected per-sect
  content). **Only `/d/jjf/front_yard2` was live-reproduced and
  live-verified fixed** — the other 8 sects are scattered across the
  map (方寸山, 昆仑山月宫, 南海普陀山, 阴曹地府, 大唐将军府 done,
  龙宫, 陷空山无底洞, 大雪山, 五庄观) and a live round-trip to each was
  not pursued given the time budget; they are fixed proactively by
  code-shape match, per this project's own standing practice
  (`AGENTS.md`'s "port the sibling's proven fix" pattern, §2.1), but
  **this specific fix's live verification is honestly one-out-of-nine.**
  A future pass reaching any of the other 8 sects should spot-check its
  own `zhangmen.lpc`'s entrance room on first visit.
- **False leads worth recording** (spent real time on these; ruling them
  out is itself useful for the next person who hits this shape):
  - **`maximum call depth : 30` in `config.fluffos` is a dead setting on
    this driver build** — raising it to `150` (the driver's own
    hardcoded default) had **zero effect** on the crash. Checked the
    actual driver source (`~/src/fluffos/src/vm/internal/base/
    interpret.cc`): the enforced limit is the compile-time constant
    `CFG_MAX_CALL_DEPTH` (150); the config key is registered in `rc.cc`
    but never read by the interpreter. The archive's own "(unused
    currently)" comment on this key is, unusually, **accurate** for this
    driver build (most of this file's "(unused currently)" comments are
    stale — see `logind.lpc`'s call-depth-adjacent settings elsewhere in
    this project's other libs — so don't generalize this either way
    without checking the specific key). Left the config value unchanged
    (`30`, the archive default) with a comment recording this so a future
    agent doesn't re-spend the time. If a lib's crash trace shows "Too
    deep recursion" at a depth that looks legitimately-deep-but-finite
    (not cyclic), the fix has to be an actual code change, not a config
    tweak, on this driver.
  - Disabling *only* `create_identity()`'s call from `init()` still
    crashed (blamed `reset_me()` / `feature/dbase.lpc`'s `query_temp()`
    instead). Disabling `reset_me()`/`restore()`/`fully_recover()` too
    (leaving `init()` almost empty) *still* crashed, now blamed on
    `me->setup()`/`std/char.lpc`'s `setup()`. This is what established
    that the recursion isn't really "inside" any one of `zhangmen.lpc`'s
    own functions — it's that `init()` itself was being re-entered on the
    same object, so whatever code happened to be running when the
    call-depth limit hit varied by exact timing.
  - Applying *only* the `std/room.lpc` reentrancy guard (without the
    `zhangmen.lpc` `init()` guard) still crashed. Applying *only* the
    `zhangmen.lpc` `init()` guard (confirmed via `git stash` isolation,
    without the `room.lpc` guard) was the point at which live retesting
    stopped reproducing the crash across several repeated fresh-boot
    attempts — but `std/room.lpc`'s `setup()` calling `reset()`
    synchronously (see root cause #1) is real, structural, and shared by
    every room in the game, so the guard was kept anyway as defense in
    depth even though the `zhangmen.lpc`-side guard alone was sufficient
    in this specific reproduction.
- **Verified**: reproduced live pre-fix, multiple times, across fresh
  driver restarts (not just one lucky/unlucky run — the timing-dependent
  nature of the bug means a single run either way isn't conclusive).
  Post-fix: re-tested via `shenqy` (existing character) and a **brand
  new** registration (`shenqf`/沈青枫) from a **freshly restarted
  driver** each time, walking the full `南城客栈` → `朱雀大街` →
  `十字街头` → `青龙大街` ×2 → `answer 拜师` → `将军府` →
  `front_yard`(练武场/sandbags) → **`front_yard2`(练武场/木桩+沙坑,
  the crash site)** → `正厅`(main hall, 秦琼) route four separate
  times post-fix with zero recurrence and a clean `log/debug.log`
  (`grep -i "fatal\|too deep\|error:"` empty) every time. `zhangmen`'s
  displayed title also changed from the corrupted `0掌门大师兄 大弟子`
  to the correct `将军府掌门大师兄 大弟子` post-fix, confirming the
  crash was also silently corrupting its own state, not just producing
  a scary-looking but harmless message.

### What was tested and confirmed working

- **Registration**: two independent real Chinese names (沈青云, 沈青枫),
  full flow (gb/big5 charset choice → student age-gate → English id →
  confirm new character → Chinese name → password → confirm → email →
  gender → accept rolled talents), landing in `南城客栈` (South City
  Inn) both times.
- **Movement/exploration**: walked `南城客栈` → `朱雀大街` → `十字街头`
  (city center, 4-way hub) → `青龙大街` ×2 → `将军府`(将军府总管 秦安's
  gate, gated behind `answer 拜师`) → `练武场`(front_yard, sandbags) →
  `练武场`(front_yard2, wooden posts/sand pits — the crash site, now
  fixed) → `正厅`(keting, main hall). Room descriptions, exits, and
  day/night flavor text all correct throughout; read the underlying
  `.lpc` room files to plan the route rather than guessing (§10.7's
  explicit instruction) — this is how `/d/jjf/gate`'s `answer 拜师` gate
  (implemented in `d/jjf/npc/qinan.lpc`'s `do_answer()`) was discovered
  before blindly walking into a "你胡说什么呀？" rejection loop.
- **Character info**: `score` (title/attributes/HP-MP bars/kill count/潜能)
  and `hp` (气/神/食物/饮水/内力/法力 bars) both correct at every stage
  (fresh, post-apprentice, post-skill-learn). `i` correct throughout,
  including the `□` equipped-item marker convention (same as other ES2-
  family libs in this project).
- **Combat**: this lib's own `help combat` documents `fight` (not
  `kill`) as the intended sparring verb — battles fought with `fight`
  stop at unconsciousness/surrender/flight and don't carry grudges,
  matching `bxsj`'s "safe sparring" pattern but implemented as a command
  *contract* here rather than a dedicated stat-mirroring training-dummy
  object. **Note**: a genuine `muren.lpc`(木人/training dummy) object
  with a stat-mirroring `accept_fight()` DOES exist in this codebase
  (`d/city/obj/muren.lpc`, `d/obj/misc/muren.lpc` — byte-identical
  duplicates) but **neither copy is placed in any room's `"objects"`
  mapping anywhere in the archive** (confirmed via `grep -rn "obj/
  muren\|muren.lpc"` across the whole tree) — it's dead/orphaned
  content, not a live safe-sparring mechanism in this particular
  archive, despite the exact same idiom being wired up and reachable in
  sibling lineages (`bxsj`). Used `fight huoji` (a peaceful, low-
  `combat_exp` shop-clerk NPC in `d/city/zahuohang.lpc`, matching `help
  newbie`'s own advice to start with the weakest-looking NPCs) instead —
  produced a normal turn-by-turn exchange, both fighters ended at full
  HP after disconnecting mid-fight (confirming `fight`'s non-lethal
  auto-resolution), no crash.
- **Skills**: the organic path is `learn <skill> from <teacher>`, gated
  on `is_apprentice_of()`/family match (`cmds/std/learn.lpc`) — used
  after apprenticing (below); `learn force from qin fu` succeeded,
  `skills` correctly listed the new `内功心法 (force)` entry at level 1.
  `skills <teacher>` (e.g. `skills qin fu`) correctly lists the
  teacher's own full skill roster with `□` marking their enabled
  specials.
- **Menpai/sect**: the organic path is `apprentice`/`bai <target>`
  (`cmds/std/apprentice.lpc`), which for an NPC with `recruit`/
  `attempt_apprentice` support auto-completes in one step. Two sect NPCs
  were checked in `将军府`: `d/jjf/npc/qinqiong.lpc` (秦琼, the sect's
  actual generation-2 master) gates its own `attempt_apprentice()` on
  `combat_exp >= 100000` — correctly out of reach for a fresh character,
  and NOT a bug (matches `help jjf`'s own text: "先需寻找...", i.e. the
  game's documented design is to start under a LOWER-ranked teacher and
  work up) — while `d/jjf/npc/qinfu.lpc` (秦富, the steward,
  generation-3) has no such threshold and accepted immediately:
  `apprentice qin fu` → `你想要拜秦富为师` → auto-`recruit` →
  `恭喜您成为将军府的第四代弟子` — `score`'s title line updated to
  `将军府第四代弟子 沈青云`, `师父` line correctly showed 秦富.
  **A direct/shortcut sect-join path (a newbie-gift NPC or admin
  command) was not found in this archive** — unlike `bxsj`'s explicit
  `shizhe.lpc` gift-envoy, this lib's only join mechanism is the organic
  `apprentice` path; the closest thing, `attempt_apprentice()`'s
  auto-recruit, still requires physically finding and interacting with a
  real sect NPC. Not flagged as a gap — it's simply this lineage's
  design, and the organic path alone fully satisfies §10.7 item 4's
  "test at least one path."
- **Persistence**: confirmed at both layers present in this lineage —
  (a) *silent reconnect* (disconnecting mid-session without `quit` and
  reconnecting with the same id/password mid-scene shows `重新连线完毕`
  and resumes exactly where the character was, inventory/HP/location all
  intact, confirmed repeatedly across this session's many reconnects
  used for isolating the recursion bug above);
  (b) *full quit → real wall-clock wait (35s via a backgrounded `sleep`,
  per the standing methodology note about not idling a live connection)
  → relogin*: title (`将军府第四代弟子`), 师父 (秦富), and the learned
  `force` skill (`初学乍练 1/0`) all round-tripped correctly. Location
  resets to `南城客栈` on a full relogin regardless of where `quit` was
  called from (confirmed: quit happened in `front_yard`/练武场, relogin
  landed back at the inn) — this lineage's own designed behavior
  (`logind.lpc` doesn't restore `startroom` position across a real
  login the way the silent-reconnect path does), not a bug.
  **Item-drop-on-quit, same class as `bxsj`'s documented behavior but a
  DIFFERENT underlying mechanism**: `cmds/usr/quit.lpc`'s `main()` drops
  every non-`query_autoload()` carried item on a real `quit` (confirmed
  live: `你丢下一件粗布衣` — the starting linen robe — printed at
  `quit`), yet `i` after the relogin showed the SAME item back in
  inventory. Root cause (read, not guessed): `feature/autoload.lpc`'s
  `restore_autoload()` unconditionally grants a fresh `/obj/loginload/
  linen.lpc` (or skirt+shoes for a female character) at the end of every
  restore — the guarding `if (count==0)` check that would have made this
  conditional is commented out, so it fires every time regardless of
  whether the player already had starting clothes. (`adm/daemons/
  logind.lpc` also has an equivalent gender-based cloth-grant block, but
  it's fully commented out in THIS archive and not what's actually
  firing — `feature/autoload.lpc`'s unconditional grant is the real
  mechanism. Don't assume which of two candidate code paths is live
  without checking both.) Deliberate original-archive design (anti-
  hoarding for un-flagged gear, masked for the specific case of default
  starting clothes), not a persistence defect — noted here per the same
  "don't let a future tester misdiagnose this" reasoning as `bxsj`'s
  NOTES.md.
- **Shops/economy**: `d/city/kezhan.lpc`'s 店小二 (Xiao er) sells a
  documented menu per `help newbie` (`buy jiudai from xiao er` etc.) —
  attempted live with a fresh character's starting money (0) and
  correctly rejected with `你的钱不够` (insufficient funds) — this IS a
  real, correct economy-code exercise (the gate fired correctly), but
  **no successful purchase was completed live** since a fresh character
  starts with no money and no income source was pursued within the time
  budget. Flagged honestly as an incomplete verification, not silently
  skipped.
- **Death/respawn**: **not live-tested.** `feature/damage.lpc`'s `die()`
  was read (environment `alternative_die` hook, wizard-immortal guard,
  self-crafted-item cleanup, `COMBAT_D->announce`/`killer_reward` calls)
  and looks structurally sound, but no character was actually brought to
  death — the `fight huoji` test intentionally used the lib's own
  non-lethal `fight` verb rather than `kill`, and no `suicide`-equivalent
  or genuinely-outmatched `kill` fight was attempted. Concrete to-do for
  a future pass on this lib.

### Methodology notes (for the broader pass this seeds)

- **This is the project's SECOND deep-playthrough pass, and it found a
  DIFFERENT bug class than the first** (`bxsj`'s §7.16 stale-timestamp
  decay-loop) — exactly the point of doing a second, lineage-diverse
  pilot before deciding whether to scale the approach: the two bugs
  share almost nothing (one is data-driven and time-triggered, this one
  is a structural `init()`/`reset()` reentrancy hazard triggered purely
  by first-visit timing) but both were **invisible to every prior
  verification layer** (compile sweep, boot-log watch, registration
  smoke test) and both were only caught by a real, multi-room
  playthrough plus a disciplined debug.log grep.
- **"The room loads fine and the crash message looks vague/generic" is
  not proof of a harmless bug.** This crash's player-visible symptom
  (`你发现事情不大对了...`) is IDENTICAL to the generic warning-spam
  message this lib's own `log_error()` fix (item 6 in this file's
  earlier "Fixes applied" section) was built to suppress — meaning a
  less careful pass could easily have assumed this was "just" a stray
  compile warning being (correctly, per that earlier fix) shown to the
  player, and moved on without checking `log/debug.log` for what kind of
  error it actually was. Always read the actual debug.log line, not just
  the player-facing message's general shape.
- **A crash that reproduces "most of the time but not always" from an
  otherwise-identical fresh boot is still a real, fixable bug** — don't
  let non-100%-reproducibility be a reason to file it as "flaky/
  unexplained" (AGENTS.md §1.4 item 5 documents two such genuinely-
  unexplained WASM oddities elsewhere in this project, but this one WAS
  explained, with a concrete structural mechanism, once enough isolation
  testing was done). The isolation technique that worked here: bisect by
  disabling chunks of the suspected function's body (via commenting out
  code, not adding print statements first) and re-testing against a
  freshly restarted driver each time — adding instrumentation
  (`efun::write_file`) INSIDE the suspect function turned out to
  contaminate the experiment (the diagnostic write call itself has a
  call chain, adding stack depth and occasionally becoming the last
  straw that tipped the crash) before a cleaner "does removing this code
  entirely change the symptom" bisection cut through the noise.
- **`efun::write_file()` for diagnostic writes should target `LOG_DIR`
  (`/log/`), not an arbitrary root path.** An early diagnostic attempt
  wrote to `/DEBUG.log` and produced its own tangled secondary
  ACL/logging trace instead of the clean data expected — this lineage's
  `securityd.lpc`'s `valid_write()` unconditionally allows any
  `LOG_DIR`-prefixed `write_file()`, which is both simpler AND avoids
  the ACL-check code path becoming an unwanted extra variable in the
  experiment.
