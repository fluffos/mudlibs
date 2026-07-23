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

Per the task's explicit instruction, read `libs/fluffos_xiyou2000/NOTES.md`
(#15), `libs/mhxy/NOTES.md` (#19), `libs/menghuanxiyou2002/NOTES.md` (#56),
`libs/shenmo/NOTES.md` (#73), `libs/xiyouji2003/NOTES.md` (#81) first, then
diffed/md5sum'd this archive's `adm/obj/master.c`, `adm/daemons/chinesed.c`
(the translator daemon; the byte-check daemon is `adm/simul_efun/chinese.c`
here), and `adm/daemons/logind.c` against the raw pre-conversion files of
all five before doing any conversion work.

**Findings**:
- **`adm/obj/master.c`**: header comment reads verbatim `// for ES II
  mudlib // original from Lil // rewritten by Annihilator (11/07/94)` with
  **no additional site-branding/cracker credit line at all** — every other
  sibling's copy of this exact file adds one (`fluffos_xiyou2000`: "cracked
  by vikee 2/09/2002"; `xiyouji2003`: "Last Modified By Pkyou@xyj
  2002-06-12 19:00"; `shenmo`: "rewritten by djx (09/09/2003), xfan
  3.10"). This is the earliest, least-modified copy of the family's
  master.c seen so far.
- `md5sum`s of `master.c`/`chinesed.c`/`logind.c` did **not** match any of
  the five siblings byte-for-byte (this archive is not a duplicate of
  any of them), but a line-count/structural diff against `fluffos_xiyou2000`
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
  shape as `xianlvqiyuan`/`xiakexinzhuan2`-style Century/ES-family libs
  (GB/BIG5 prompt → student age-gate → English id → confirm → Chinese
  name → password → confirm password → email → gender → gift/stat-roll
  confirm), but its own `check_legal_id`/`check_legal_name` are defined
  **directly in `logind.c` itself**, not a separate `named.c`/`named.lpc`
  daemon — so the deeper `named.lpc` PATH()/sliding-window fix from §15h
  did not apply here (there's no such file in this archive at all).

**Conclusion**: this archive is a genuine, distinct member of the
"ES II / XYJ" lineage shared with `fluffos_xiyou2000` (#15), `mhxy`/
`menghuanxiyou2002` (#19/#56), `shenmo` (#73), and `xiyouji2003` (#81) —
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
   recurring exactly as documented for `fluffos_xiyou2000`/`mhxy`: **45
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
