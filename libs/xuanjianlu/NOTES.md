# 玄剑录 (xuanjianlu) — archive #70

## What this is

`archives/玄剑录.rar`, root at `raw/xjl/`. `config.xjl`'s `name :` field and
the live connect banner both confirm the game's own self-identified name is
**玄剑录** ("Record of the Mysterious Sword") — matches the slug, no
divergence to note. Distributed by the same "小熊泥苑" collector/hosting
site seen on shujian2008/sjtx2 (archive #35/#36) — `小熊泥苑.txt`
sits alongside the mudlib root in the raw archive, just site branding, not
part of the mudlib.

**Lineage**: confirmed via `md5sum` that `adm/simul_efun/chinese.c` and
`adm/single/master.c` are **byte-identical** to `xkx2001` (archive #25) and
`bmxkx2001` (archive #45) — this is the same "ES II" engine
family (master.c header credits "original from Lil", "rewritten by
Annihilator", "modified by Xiang/Xuy for XKX"). `adm/register/xkxreg`,
`xkxrestore`, `xkx_monitor` filenames further confirm the "XKX" (侠客行)
codebase ancestry, even though this game's own live content/world is a
distinct wuxia setting (Ming-cult/明教/昆仑/侠客岛 zones, its own NPCs).
`adm/daemons/logind.c` differs from both siblings (its own registration
flow/banner), consistent with "shared engine, distinct game-world content"
seen across this whole ES II family (es1_win/esI/xkx2001/rzrmud/xo/
bmxkx2001/kxkj/yueyingqiyuan/wuhanzhan/
yanhuangwuhun/haiyang2).

Layout: `adm/single/{master,simul_efun}` + `adm/daemons/*` + `adm/simul_efun/*`
+ `adm/register/*` (the last one XKX-specific, holds a MySQL-free
registration helper set, not used by the live registration flow tested
here).

Size: 11,492 raw files, 10,605 `.lpc`/`.c` files after conversion — a
normal-sized lib for this project, not a mega-lib; the full `lpcc_check.sh`
sweep was run without incident (see below).

## Fixes applied (and why)

### Standard/catalog fixes, applied proactively

1. **AGENTS.md §15h** (`is_chinese`/`check_legal_name` GBK byte-range bug —
   nearly universal, confirmed present here too):
   - `adm/simul_efun/chinese.lpc`'s `is_chinese(str)`: was
     `strlen(str)>=2 && str[0] > 160 && str[0] < 255` (a GBK lead-byte
     range check, always false against UTF-8 codepoints) → replaced with
     `strlen(str)>=1 && str[0] >= 0x4e00 && str[0] <= 0x9fff` (CJK Unified
     Ideographs codepoint range).
   - `adm/daemons/logind.lpc`'s `check_legal_name(name, ob)`: bound
     `(strlen(name) < 2) || (strlen(name) > 8) || i % 2` (byte-count bound
     + a meaningless parity check) → `(strlen(name) < 1) || (strlen(name)
     > 4)` (character count; the message text already promised "1 到 4
     个中文字" — 1 to 4 Chinese characters — so halving 2/8→1/4 matches
     what the message always said, not a guess). Its per-character
     sliding-window loop `if( j%2==0 && !is_chinese(name[j..j+1]) ) {
     name[j]+=128; name[j+1]+=128; }` (byte-offset gate + a byte-shift
     "auto-correct" hack that has no valid meaning against Unicode
     codepoints) → `if( !is_chinese(name[j..j]) ) { <reject>; }`, using
     the exact reject message the original author had already written
     but left commented out.
   - Verified via 3 independent full registration tests (see below) that
     real single/double-character Chinese names are accepted correctly
     and rejected names really are rejected (not just "doesn't crash").

2. **AGENTS.md §15p** (DNS/intermud daemon preload exclusion): `adm/etc/
   preload` listed `/adm/daemons/network/dns_master` — removed
   proactively before the first boot attempt. (A second, unrelated copy
   of the same file sits at `adm/daemons/dns_master.lpc`, outside
   `network/` — confirmed it's not the one the `DNS_MASTER` macro
   resolves to, `include/net/daemons.h` points at the `network/` copy
   only, so nothing else needed touching.) Also checked §15ab's "inline
   DNS calls outside preload" variant: `logind.lpc`'s `logon()` does call
   `MUDLIST_CMD->main(...)` unconditionally on every connect, and that
   command does call into `DNS_MASTER`, but it's guarded by its own
   `find_object(DNS_MASTER)` check and degrades to a harmless
   `notify_fail()` when not loaded — confirmed safe by inspection and by
   zero hangs/errors across every boot+test cycle.

3. **AGENTS.md §14** (`valid_override` 3-arg upgrade): `master.lpc`'s
   `valid_override(file, name)` was 2-arg — upgraded to `(file, name,
   main_file)` and added `main_file == SIMUL_EFUN_OB || main_file ==
   MASTER_OB` to the allow-check, so an `efun::` override written inside
   a file `#include`d into `simul_efun.lpc` is still recognized.

4. **AGENTS.md §8d/§15o** (`get_include_path()` insurance): `master.lpc`
   had no `get_include_path()` apply at all — added the standard
   directory-prepending implementation as insurance for any live,
   mid-connection compile of a file using a local (same-directory)
   `#include`. (`convert_lib.sh`'s own §8d pass already converted 24
   local angle-bracket includes to quoted form, which resolves without
   needing this apply at all — this addition is pure insurance, not a
   fix for an observed failure.)

5. **AGENTS.md §8e** (`tail` is not a real FluffOS efun) — **fatal here**,
   confirmed on the very first boot attempt: `adm/simul_efun/message.lpc`'s
   `tail(string file)` called `efun::tail(file)`, and since this file is
   `#include`d directly into `simul_efun.lpc`, the compile error
   (`Unknown efun: tail`) took down the *entire* simul_efun object,
   which the driver refuses to boot without (`*No program in object
   '/adm/single/simul_efun'!`). Reimplemented in plain LPC (read the
   file, split lines, take the last N, write them) — same pattern as
   catalogued in AGENTS.md, same severity as the `bmxkx2001`
   instance of this exact bug (that lib shares this codebase family too).

6. **AGENTS.md §15c** (`adm/etc/preload`-style bare-`.c` data-file refs):
   found a SEPARATE instance in `adm/etc/task/task_list` (a plain-text
   list of NPC-quest object paths read by `adm/daemons/taskd.lpc`'s
   `random_place()`/`update_task()`), still listing the pre-rename
   `/adm/etc/task/obj/*.c` paths. After the `.c`→`.lpc` rename these
   `new()` calls returned `0` silently, and the caller's very next line
   (`ob->query("task_owner")`, no `objectp()` guard — see AGENTS.md §15e)
   threw `*Bad argument 1 to EFUN call_other() ... Got: int(0)` every
   time this daemon's periodic job fired. Fixed with `sed -i 's/\.c$//'`
   on the data file, same fix shape as the catalog entry.

### New findings from this pass (not yet in AGENTS.md's catalog as of this write-up)

7. **`private` on an `add_action`-bound dispatcher, once inherited, gets
   demoted to `DECL_HIDDEN` and the driver refuses to call it — silently
   breaking EVERY player command post-login.** This is the single most
   impactful bug found in this lib and, as far as I can tell, a genuinely
   new bug class for this whole project's catalog.

   `feature/command.lpc` (inherited by `inherit/char/char.lpc`, the
   player body base class) declares:
   ```lpc
   private nomask int command_hook(string arg)
   ```
   bound via `add_action("command_hook", "", 1)` in `enable_player()`.
   This function is the *sole* generic dispatcher for movement, verbs,
   emotes, and channels — literally every command a connected player
   types. On this driver (`vm/internal/apply.cc`'s `apply()`), a
   driver-origin `add_action` callback dispatched against an object
   requires at least `DECL_PRIVATE` access when `current_object == ob`
   — but `DECL_PRIVATE` ("can't be inherited") demotes a private
   function to `DECL_HIDDEN` once it's compiled as part of an
   *inheriting* program rather than its own defining file, and `command_hook`
   is only ever invoked as a member of the inheriting player-body class,
   never as a member of `feature/command.lpc` itself. Symptom: full
   registration completes cleanly, the character lands in the actual
   start room with a correct room description on entry, but **every
   subsequent typed command (even `look`) silently produces only the
   config's `default error message`**, with a matching debug.log entry:
   ```
   apply() with insufficient permission:
   cob: clone/user/user#1, ob: clone/user/user#1, function: command_hook,
   origin: efun, needs: private, has: hidden
   ```
   **How this was missed on 2 prior sibling libs**: `xkx2001`'s own copy
   of this file has `nomask int command_hook` (no `private` at all) — so
   `xkx2001` never hit this. `bmxkx2001` (archive #45) *does*
   have the identical `private nomask` shape, but that lib's own NOTES.md
   confirms testing stopped right at "reaches the password prompt" and
   never issued a real post-login command — so the bug was live there
   too and never caught. This is exactly the class of gap this task's
   instructions specifically warn about: "boots and reaches a prompt" is
   not "the feature actually works."

   **Fix**: drop `private` (`nomask int command_hook(string arg)`),
   matching `xkx2001`'s own already-safe version verbatim. `nomask` alone
   still prevents any override.

   **Recommendation for AGENTS.md**: worth its own catalog entry (a new
   §15ac or similar) — check any lib's core `add_action`-bound dispatcher
   function (commonly named `command_hook`/`parse_command`/similar,
   defined in a `feature/`-style file and inherited into the player body)
   for a `private` access modifier, and always issue at least one real
   post-login command (not just `look` at the banner) before considering
   a lib's gameplay loop verified.

8. **`securityd.lpc`'s ACL mappings are never initialized when the
   archive ships with no seed save data for the daemon** — a second,
   related bug that surfaced immediately after fixing #7 above (the very
   first real command that could finally reach `command_hook` then hit
   this one).

   `securityd.lpc create()` calls `restore()`, and only if that FAILS
   does it fall back to manually initializing `wiz_status`/`wiz_sites` —
   but `trusted_read`/`exclude_read`/`trusted_write`/`exclude_write`/
   `authorized_cmds`/`exclude_cmds` are never initialized in that
   fallback branch at all (only `authorized_cmds` gets a lazy
   `if(!authorized_cmds) authorized_cmds = allocate_mapping(...)` inside
   `valid_cmd()` itself — the other five don't get equivalent treatment
   anywhere). This archive has no `/data/securityd.o` seed file at all
   (confirmed: the only `securityd.o` anywhere in the tree is a wizard's
   unrelated personal-sandbox copy under `clone/obj/u/xuanyuan/daemons/`),
   so `restore()` always fails. Symptom: `valid_cmd()`'s very first
   `exclude_cmds[dir]` lookup on the still-`0` mapping threw `*Value
   being indexed is zero.` for literally every player command.

   **Fix**: added lazy `if(!X) X = allocate_mapping(1000);` for all six
   ACL mappings once, at the end of `create()`.

   **A second layer of the same root cause**: once the mappings
   themselves were guaranteed non-zero, the *next* line down hit a
   related but distinct crash — `authorized_cmds["cmds"]`/
   `trusted_write["/"]`/`trusted_read["/"]` are looked up directly (not
   via the `undefinedp()`-guarded loop the rest of the function uses) and
   passed straight into `member_array()`, which rejects an `int` (the
   `0` you get from a missing mapping key) for its 2nd argument
   (`Expected: string or array Got: 0`). Fixed by pre-seeding exactly
   these three well-known keys as `({})` in the same `create()` block.

   Both of these are latent/dormant in every sibling lib that ships with
   real save data for this daemon (a populated ACL is the normal case) —
   this is specific to this archive's snapshot shipping without one, not
   a systemic driver-compat bug the way #7 is. Worth a narrower catalog
   note (checking whether `restore()` ever actually succeeds, and adding
   defensive `allocate_mapping()`/`({})` fallbacks in any lib's
   `securityd.lpc create()` when it doesn't) rather than a blanket rule.

### `static`→`nosave` blanket-sed collateral damage (§3 counterexample, recurring)

Same shape as the `moniHuafu`/`yanhuangwuhun` precedent already in
AGENTS.md, but a wider blast radius here (**23 files**, the leading-slash
variant `"/static/..."` rather than just `"static...`): this lib logs
extensively via `log_file("static/XXX", ...)` / `log_file("/static/XXX",
...)` (a real `log/static/` directory ships in the archive) for crash
logs, read/write/cmd-denial audit logs, clone logs, award logs, etc. —
`convert_lib.sh`'s blanket `\bstatic\b`→`nosave` sed rewrote every one of
these path literals to `"nosave/..."`/`"/nosave/..."`, silently
orphaning the real `log/static/` seed directory. Found and reverted with
`grep -arl '"nosave\|/nosave/'` across the whole `work/` tree (not just
the narrower `"nosave` check used on prior libs, which would have missed
the leading-slash form) → `sed 's/"nosave/"static/g; s/\/nosave\//\/static\//g'`
on every hit. Affected: `adm/single/master.lpc` (`crash()`'s
`static/CRASHES`), `adm/simul_efun/message.lpc` (5 sites),
`adm/daemons/securityd.lpc` (5 sites), its wizard-sandbox duplicate at
`clone/obj/u/xuanyuan/daemons/securityd.lpc` and `.../logind.lpc`, several
`cmds/`/`u/`-tree files' `AWARD_LOG`/`SUICIDE_LIST`/etc, and — a distinct
sub-case — the *historical audit log data* file `log/static/more.lpc`
itself (a `更 record of who ran the `more` command on what file, plain
text, mistakenly renamed from `.c`→`.lpc` and then swept by the same sed
since it now had a `.lpc` extension, corrupting its own **content**, not
code — its lines record historical paths like `/log/static/suicide.c`).
Reverted that one too even though it's just cosmetic seed-log text, for
consistency. **A separate mid-pass mistake, corrected**: while iterating
on this, an over-broad `rm -rf work/log` (intending only to clear
player-save-state under `work/data`) also deleted this lib's entire
`work/log/` seed-data subtree (crash logs, `WIZ_LOGIN`, `MONEY`, etc, and
the `regban.log` that `adm/daemons/regband.lpc`'s `is_banned()` writes to
on every connection attempt) — this reintroduced the exact `check_legal_id`-adjacent
crash described above (`*Wrong permissions for opening file /log/regban.log
for append.` / `No such file or directory`, silently aborting `get_id()`
mid-connection). Recovered by re-running `convert_lib.sh` into a scratch
directory (raw→work conversion is idempotent given the same raw source)
and copying just the regenerated `log/` subtree back in, re-applying the
same static/nosave revert to it. **Lesson for future sessions**: `work/log/`
(the *mudlib's own* virtual `/log/` tree, seed content) and the sibling
`libs/<slug>/log/` (the *driver's* debug-log output directory, safe to
clear) are two different things with the same basename — don't `rm -rf`
both in one command.

### lpcc sweep content fixes (found via the sweep, applied where cheap and correct)

- **Missing shared header, restored (AGENTS.md §8g variant)**:
  `kungfu/skill/liumai-shenjian/eff_msg.h` (generic combat-message helper
  functions `damage_msg()`/`eff_status_msg()`, nothing liumai-specific in
  its content at all) was referenced by 10 unrelated skill files via the
  absolute path `#include "/kungfu/skill/eff_msg.h"` — i.e. the shared
  root location, not the nested one it actually shipped at. Copied the
  file to `kungfu/skill/eff_msg.h` (the referenced root) rather than
  touch 10 call sites — resolves all 10 `Cannot #include` failures in one
  shot.
- **Missing `HALBERD` macro (AGENTS.md §8g variant)**: `include/weapon.h`
  defines `AXE`/`BLADE`/`DAGGER`/.../`BOW` macros pointing at
  `/inherit/weapon/*` base classes, but never defined a plain `HALBERD`
  macro (only its internal `F_HALBERD` variant) even though
  `/inherit/weapon/halberd.lpc` exists on disk and 17 files do `inherit
  HALBERD;`. Added `#define HALBERD "/inherit/weapon/halberd"` in the
  same block as its siblings — resolved all 17 `inherit HALBERD` syntax
  errors at once.
- **Misplaced relative `#include`, fixed at 3 call sites**:
  `d/kunlun/zhang.lpc`, `d/kunlun/xiaozhao.lpc` (张无忌/小昭, the
  Ming-cult zone's two named NPCs), and `u/lbc/yangxiao.lpc` did
  `#include "mingjiao_npc.lpc"` (bare filename, quoted) while sitting one
  directory level above where that header actually lives
  (`d/kunlun/npc/mingjiao_npc.lpc`) — every SIBLING NPC file in
  `d/kunlun/npc/` uses the identical bare-filename include and resolves
  fine (same directory). Fixed the 3 outliers to the full absolute path
  `"/d/kunlun/npc/mingjiao_npc.lpc"`.
- **Lossy-conversion merged closing-tag typo (the documented "iconv -c
  eats the adjacent real newline too" gotcha)**: `d/kunlun/mj_center.lpc`
  and its byte-identical sibling copy
  `u/feitian/mingjiao/d/mingjiao/mj_center.lpc` (both flagged `LOSSY
  conversion` in the pipeline log) had their `set("long", @LONG ... LONG)`
  text block's closing `LONG` tag merged onto the preceding Chinese text
  line (`...些数据。LONG` on one physical line instead of two) — "End of
  file in text block" as predicted by the catalog entry. Fixed by
  re-inserting the newline at the exact merge point in both files.
- **Orphaned non-LPC content (AGENTS.md §12)**: `d/kunlun/map_mingjiao.c`
  (pure ASCII-art, `◆明教地图◆` and nothing else, zero LPC syntax) got
  swept into `.lpc` by the blanket rename despite not being code and not
  being referenced by anything (`grep -rl` across the whole tree, only
  self-match). Renamed to `map_mingjiao.orphaned.txt`, matching the
  precedent's exact recommendation.

## What I confirmed was NOT needed, and how

- **§4** (master lazily `load_object()`ing a security daemon inside
  `valid_read`/`valid_write`, recursion risk): read `master.lpc` in full —
  `valid_write` only does `find_object(SECURITY_D)` (no `load_object`),
  returns `0` if not found; `valid_read` is a hardcoded `return 1;` with
  no daemon lookup at all. No lazy-load pattern present.
- **§7** (`get_root_uid()`/`get_bb_uid()` master applies): both already
  implemented in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
  Confirmed present by direct read, no fix needed.
- **§8c** (`valid_read`/`valid_write` overriding `user` with
  `this_player()` unconditionally): read `securityd.lpc`'s `valid_read`/
  `valid_write` in full — neither does this; `user` is taken as passed
  and only `geteuid(user)` is derived from it directly, no
  `this_player()` substitution anywhere in either function.
- **§15n** (custom securityd ACL blocking the driver's own compile-time
  `load_object`/`include` reads): confirmed structurally impossible here
  — `master.lpc`'s own `valid_read` **never calls `SECURITY_D` at all**
  (hardcoded `return 1`), so `securityd.lpc`'s `valid_read` ACL logic
  (with its `exclude_read`/`trusted_read` tables) is dead code from the
  driver's perspective; only `valid_write` is actually wired through to
  the daemon. Confirmed via direct read of both files, not by
  guessing from symptoms.
- **§15l** (master `create()` destructing `SIMUL_EFUN_OB`): `master.lpc
  create()` is a single `write("master: loaded successfully.\n");` line,
  no `destruct()`/`efun::destruct()` call anywhere in the file.
- **§15u** (dormant "phone-home"/mass-deletion function in securityd):
  grepped `securityd.lpc`/`master.lpc` for `rm(`/`rmdir(`/`shutdown(`
  gated on suspicious checks — found nothing resembling this pattern (the
  only `rm()` call in securityd is the ordinary `.edrc` cleanup in
  `save_ed_setup`, unrelated).
- **§15s** (`tell_room`/`message()` 4th-arg `int 0` rejection): checked
  `message.lpc`'s `tell_room`/`shout` wrappers — both DO pass a
  potentially-`0` value (`exclude`, `this_player()`) as the 4th
  `message()` argument in their 2-arg call forms. Applied the standard
  defensive fix (`exclude || ({})`, `this_player() || ({})`) proactively
  even though no crash from this specific shape was actually observed in
  any of the 3 full interactive test sessions — cheap, correct, and
  consistent with the catalog's stated risk (a preloaded room's own
  heartbeat is the classic trigger, and this lib does have many
  preloaded/auto-reset rooms).
- **§8f** (`TYPE * name1, name2;` comma-declarator array-modifier bug): a
  broad regex sweep for the shape flagged 235 candidate lines, but
  cross-checked against the REAL lpcc sweep's failure categories — only
  11 `Bad assignment` failures exist in the whole lib, and every one of
  them traces to a genuinely undefined function call (`who_i_fight`,
  `unew`, `offensive_target`, all in wizard-sandbox files already
  documented as noise below), none to a forgotten `*` on a second
  declarator. Concluded the regex was over-matching (as AGENTS.md's own
  §8f note warns can happen without the narrower Python-based check) and
  this bug class is not actually present here.
- **§15t** (absolute path in `<>`, `..`-relative includes, inherit-after-
  globals): grepped for all three shapes — zero hits for an absolute
  path inside angle brackets, zero `#include "../..."` patterns, and zero
  `Illegal to inherit after defining global variables` errors anywhere in
  the full lpcc sweep output.
- **§15v** (`LONELY_IMPROVED`-gated `efun::X()` calls / NT-nitan-lineage
  `count()` bignum efun): not applicable — this is the ES II/XKX lineage,
  not the NT/nitan/Lonely family; `adm/single/simul_efun.lpc` has no
  global `set`/`query`/`delete` simul_efun definitions at all (per-object
  property storage is handled by ordinary `inherit F_DBASE`-style base
  classes), so the core §15 dbase architecture bug doesn't apply either.
  Confirmed by reading `adm/single/simul_efun.lpc`'s `#include` list.

## lpcc sweep — triage of remaining noise (361/10605 fail, 96.6% pass, up from 96.4%/383-fail pre-fix)

Grouped the 361 remaining failures by top-level directory before
accepting them as noise (not exhaustively fixed, per AGENTS.md §6b):

- **`u/dns` (46), `clone/obj` (29, almost entirely `u/xuanyuan`), `u/feitian`
  (20), `u/lbc` (a few)**: wizard personal sandbox/scratch directories
  (builders' own work-in-progress skill/NPC files, several explicitly
  under a `tmp/` path). Sampled several — failures trace to genuinely
  undefined helper functions (`test_zouhuorumo`, `BINGQI_D` used as a bare
  call, `create_communion`, `who_i_fight`) that only ever existed as
  private conveniences in whatever personal dev environment these
  wizards used, never part of the shipped shared codebase. Not fixed —
  dead/scratch content, matches the established "personal builder
  sandbox" noise category seen on other libs in this family.
- **`log/static` (16) + `log/test` (12)**: pure historical log/audit-data
  files (chat logs, command-usage history, crash dumps) that happen to
  have shipped with a `.c` extension and got swept into the `.lpc` rename
  — not code at all (matches AGENTS.md §12's `map_mingjiao` precedent
  exactly, just not worth individually renaming 28 pure-data files back
  to `.txt` the way the one referenced-and-visible `map_mingjiao` case
  was). Confirmed via sampling a few: plain Chinese log text, zero LPC
  syntax.
- **`adm/daemons` (13, entirely `network/*` + `adsd`/`questd`/`socket`)**:
  the DNS/intermud/mail/telnet network subsystem (deliberately excluded
  from preload) plus two unrelated daemons (`adsd` crashes in its own
  `create()` on a runtime `explode()` call, `questd` only has unused-
  variable warnings misclassified as FAIL by the sweep harness) — none
  are preloaded, none reachable from registration or basic gameplay.
- **Zone content (`d/henshan` 12, `d/city` 11, `d/wudang` 8, `d/shaolin`
  8, `clone/board` 8, `d/taihu` 7, `d/m_weapon` 7, `d/quanzhou` 6,
  `d/beijing` 6, `d/kunlun` 10 remaining after fixes, and a long tail of
  1-5-failure zones)**: sampled several — genuine per-room/per-item
  content gaps (missing referenced NPCs/rooms that don't exist anywhere
  in the archive, matching AGENTS.md §13) and a handful of pre-existing
  typos/illegal-characters not on the boot or registration critical
  path. Not chased further given the breadth-over-depth policy and the
  clean, fully-verified boot+registration+gameplay result already in
  hand.
- **`kungfu/class` (10)**: similar per-skill content-reference gaps,
  same treatment.

## Interactive test result — full registration + real gameplay commands

Read `adm/daemons/logind.lpc`'s actual `input_to` chain before scripting
(`logon → confirm_big5 → get_id → confirm_id → get_name → new_password →
confirm_password → specify_gifttype → get_gift → get_email → get_gender →
enter_world`) — confirms a hidden pre-id **BIG5/GB font prompt**
("Do you want to use BIG5 code?(y/n)") right after the banner, exactly the
kind of hidden gate AGENTS.md's "hidden pre-id prompt" family warns about.

Ran **3 independent full registrations in 3 separate continuous
`mudclient.py` sessions**, each covering registration all the way through
real post-login commands (not just reaching a prompt):

1. `n` (GB code) → id `qinling` → confirm `y` → **real Chinese name `秦岭`**
   → password `test12345` (×2) → gift type `0` → accept gift `y` → email
   `test@test.com` → gender `f` → **lands in the actual start room**
   (`沙滩` — a beach zone, full room description with exits/NPC rendered
   correctly) → `look` **now correctly re-displays the room** (this was
   the run where the `command_hook`/`securityd` fixes were validated —
   before them, `look` produced only the config's default error message
   with a debug.log crash trace) → `score` → `quit` → "开始退出游戏，
   进行中 ..." (graceful quit).
2. `n` → id `linfeng` → `y` → **real Chinese name `林风`** → same flow →
   lands in the same start room, an NPC ("「罚恶使」李四") correctly
   greets the character **by name** ("恭迎林风") → zero debug.log errors
   for the entire session.
3. `n` → id `qinfeng` → `y` → **real Chinese name `秦风`** → same flow →
   lands in the start room, a different greeter NPC ("「赏善使」张三")
   greets by name ("恭迎秦风") → `look` → `i` → `quit` → **zero
   debug.log errors of any kind** (`执行时段错误`/`Bad argument`/
   `Undefined function`/`Value being indexed`/`insufficient permission`:
   all zero hits) — this is the final, fully-clean run after every fix
   in this document was applied.

All three names are real, valid Chinese input (2-character names, both
characters within the CJK range, not on the lib's `banned_name` list),
confirming the §15h fix actually works end-to-end and the flow proceeds
correctly past registration into fully-playable post-login gameplay, not
just "reaches a prompt."

## Port / process

Port **40064**. Driver launched via `setsid nohup ... & disown` per
AGENTS.md's guidance; killed by exact PID after each test cycle, never a
broad `pkill` pattern (several other agents had drivers running
concurrently throughout this session). No driver process left running at
the end of this pass; `work/data` (player save state from testing) and
`log/debug.log` cleared before finishing.

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  10605 `.lpc` files in `work/`; only 2088 written (8450 were already
  formatter-conformant — this lib evidently got substantial formatting
  attention in an earlier pass), 67 errors (files it refused to touch,
  fine/expected). Specifically verified the `nomask int command_hook`
  fix (no `private`, §15ae's origin bug) in `feature/command.lpc`
  survived the reformat unchanged in substance.
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted clean (`Accepting telnet connections`/`Initializations
  complete`); the only debug.log noise during preload is a repeating,
  **caught** (via `CATCH()` in `master.lpc`'s `preload()`) "执行时段
  错误：*Object cannot be loaded during compilation" from
  `simul_efun.lpc`'s `wizardp()` — this is the same shape as AGENTS.md
  §15af (`log_error()` calling `wizardp(this_player(1))` during a
  compile-time warning, lazily loading securityd mid-compile), but
  since it's wrapped in `master.lpc`'s own `CATCH()` here it's fully
  non-fatal and boot completes normally; not previously flagged for
  this lib, noting it here as a §15af-shaped (but harmless) instance.
  Ran 3 fresh full registration sessions with real Chinese names
  (秦风波/秦风陈/秦风戊): id/confirm/Chinese-name/password/gift-type/
  email/gender all completed, landed in the same 沙滩 start room seen
  in the original pass, with the escort NPC's name-greeting working
  correctly; `look`/`i`/`quit` all reproduced the original pass's
  clean results (zero real debug.log errors). **New observation**:
  `score` (not part of the original pass's tested command set)
  produced no visible output at all in every attempt tried, both
  immediately after landing and after `look`; `cmds/usr/score.lpc`
  never appears in `debug.log` at all (unlike `look`/`quit`/`drop`,
  which show their lazy-compile warnings), meaning `find_command`
  never resolves it to a compile attempt — worth a closer look in a
  future pass, but not chased further here since it's a newly-noticed
  gap outside the previously-verified/committed command set, not a
  regression from this pass's reformat or driver rebuild (both are
  read-only w.r.t. `cmds/usr/score.lpc`'s logic).
- **WASM**: booted with the same non-fatal preload noise as native
  (the §15af-shaped caught cascade above, plus the expected
  `socket_create`/`socket_close`/`Bad left argument` compile errors
  from `ftpd.lpc`/`network/http.lpc` since the `sockets` package isn't
  built into this WASM binary). **Full registration + gameplay flow
  verified end-to-end** with a real Chinese name (秦风武): same
  id/confirm/name/password/gift/email/gender flow, landed in 沙滩,
  `look` and `quit` both worked correctly matching the native result.
  The "上次连线地址" (last-connect-address) line printed
  `0( Wed Dec 31 16:00:00 1969 )` instead of a real IP+timestamp — a
  cosmetic manifestation of the documented `query_ip_number()`-under-
  WASM limitation (epoch 0 formatted as a date), non-fatal, doesn't
  gate login since this lib has no IP-based site restriction. **Verdict:
  playable under WASM** (matching the native command set actually
  re-verified this pass), with the same cosmetic IP-display glitch
  common to this driver's WASM build.

## 2026-07-23 (integrity review): the "score produces no output" observation is INTENTIONAL design, not a bug

Investigated the previous pass's open observation that `score` silently
produced no output for a fresh character. Root cause: **this lib's own
onboarding/registration gate**, the same design family as
`bmxkx2001`'s `block_cmd` gate:

- `adm/daemons/logind.lpc` (enter_world): any player with
  `query("registered") != "yes"` (and `(player)` wizhood) is moved to
  `/d/xiakedao/shatan1` instead of their normal start room.
- `/d/xiakedao/shatan1.lpc`'s `init()` does `add_action("block_cmd", "", 1)`
  for non-wizards; its `block_cmd()` returns 1 (silently swallowing the
  command, zero output by design) for every verb EXCEPT
  `quit/goto/suicide/follow/tell/say/reply/look`. So `score`, `hp`, `help`,
  `i` etc. are all deliberately dead-air in the arrival room — `look` and
  `quit` (the commands the earlier passes tested) are on the allowlist,
  which is why only `score` looked broken.
- The intended flow: `follow zhang san` (or li si) → escort teleports you
  to `/d/xiakedao/register` (its own block_cmd allowlist adds `register`)
  → `register you@example.com` → REGI_D issues a NEW random password and
  disconnects you → re-login with that password → `registered == "yes"`,
  you land in the real `/d/xiakedao/shatan` (exits, fisherman NPC), and
  `score` works fully.

Verified end-to-end interactively: completed the whole
follow/register/re-login flow with a test character; `score` then printed
the complete character sheet (【玄剑录个人档案】). No fix needed — do not
"fix" the silence in shatan1/register, it is the original game's
anti-unregistered-play gate working as designed. (Side note for future
testers: the register step's issued-password disconnect is easy to
mistake for a crash; it prints 您的新密码是XXXXX then closes the link.)

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/e and §1.5. Gates patched:

- `adm/daemons/logind.lpc` — added `is_loopback_conn(object)` helper
  (loopback / empty / malformed `query_ip_number()` → local), and:
  - `logon()`'s `BAN_D->is_banned(query_ip_name(ob))` gate (~line 173) —
    now skipped for loopback connections.
  - `get_id()`'s `REGBAN_D->is_banned(query_ip_name(ob))` registration
    ban (~line 285) — skipped for loopback.
  - No `uptime()` startup gate and no per-IP flood throttle exist in
    this logind (MAX_USERS capacity cap left intact — hosting capacity,
    not per-IP).
- `adm/daemons/band.lpc` `is_banned()` (~line 40) — defensive
  short-circuit for non-string/empty/localhost/127.0.0.1 site strings
  (these gates receive query_ip_name(), i.e. hostnames — the
  dotted-quad-malformed test deliberately NOT used here so genuine
  remote hostnames still hit the ban list).
- `adm/daemons/regband.lpc` `is_banned()` (~line 43) — same defensive
  short-circuit (also fixes a latent crash: `lower_case(site)` on a
  non-string under WASM).
- `adm/daemons/securityd.lpc` — two fixes required by admin seeding:
  - `wiz_levels` rank table made `nosave` (restore() from the new
    `/data/securityd.o` was ZEROING it per §7.7, crashing
    `get_wiz_level()` → every `wiz_level()` call → login desync).
  - `create()` ACL seeding extended: `authorized_cmds` now seeds
    `cmds/adm`/`cmds/arch`/`cmds/wiz`/`cmds/imm` status arrays. Without
    this, valid_cmd() denied every wizard command for every rank
    including `(admin)` (the legacy lazy-init inside valid_cmd() can
    never fire once create() makes the mapping non-null — pre-existing
    latent bug, exposed by the first real wizard this lib ever had).

Admin account seeded: id `fluffos`, pw `Mud@2026`, name 浮浮, granted
`(admin)` via a hand-seeded `/data/securityd.o`
(`wiz_status["fluffos"]="(admin)"`, `wiz_sites["fluffos"]=".*"`; "npc"
entries kept from the daemon's own defaults). This lineage's wizard
login additionally requires a `wizard_password` field on the login save
— seeded into `data/login/f/fluffos.o` as the same crypt hash as the
password, so the 巫师验证码 is also `Mud@2026`. Verified: real
registration flow (n/fluffos/y/浮浮/pw×2/0/y/email/m → landed on 沙滩),
relogin as fluffos (password + 验证码) →
`update /adm/daemons/band.lpc` → 成功, `score` correct. Retest: fresh
normal registration (秦风 m) end-to-end, look/quit correct; test char
saves removed; zero new debug.log errors.

**Save files for the orchestrator to add** (none gitignored, normal add):
- `libs/xuanjianlu/work/data/user/f/fluffos.o` (player body)
- `libs/xuanjianlu/work/data/login/f/fluffos.o` (login/link object —
  holds password + wizard_password)
- `libs/xuanjianlu/work/data/securityd.o` (admin grant)


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

## 深度功能测试 / Deep functional test (2026-07-24, round two)

First real *playthrough* pass on this lib per AGENTS.md §10.7 (all prior
passes verified registration + `look`/`score`/`quit`/admin-login, or
watched boot output, but never played the actual game systems). Native
driver (`build-debug`), one continuous `mudclient.py` session per phase,
real Chinese names throughout, real wall-clock waits for the two
timer-gated systems this lib turned out to have (see below).

**Read first**: `doc/help/intro` (the closest thing to a newbie primer
this lib ships — no plain `doc/help/newbie` file, only
`newbie_wudang`/`newbie_gumu`/`newbie_lingjiu`/`newbie_baituo`/
`newbie_job` per-sect/topic variants) — explains the 14-sect roster,
attributes, `fight`/`kill`/`hit` combat-verb distinction, and the
`xue`/`du`/`lian` three ways to learn skills, matching what was tested
below almost exactly.

**Test character**: id `wentian`, real Chinese name 闻天笑, password
`Test12345` → after completing this lib's own two-stage registration
(see below) a NEW password `doeal` was issued and is now the live login
password. **Kept** (not cleaned up) as the representative playthrough
character — final state: registered, `strike` skill learned (1 point),
standing in 沙滩 (the real post-registration start room). Save files:
`work/data/user/w/wentian.o`, `work/data/login/w/wentian.o`. Two other
characters created while probing the registration-loop edge cases
(`shiying`/上官虹, `shangfei`/上官飞, both abandoned mid-tutorial,
`registered:"no"`) were deleted before finishing — pure test debris, not
representative state worth keeping.

### This lib's registration is TWO-STAGE, and the second stage is the real "tutorial"

Already documented above (the `shatan1`/`block_cmd` section) that a
freshly-registered character is unregistered (`query("registered") ==
"no"`) and dropped in `/d/xiakedao/shatan1` with almost every command
silently swallowed. What that earlier pass didn't walk end-to-end: the
escort NPC (`d/xiakedao/npc/li4.lpc`/`zhangli.h`'s shared
`greeting()`/`check_follow()` call_out chain) auto-teleports the
character to `/d/xiakedao/register` **5-15 real seconds** after a
`follow li4`, where a second NPC (`mux.lpc`) explains `register
<email>`; running that command calls `adm/daemons/regid.lpc`'s
`register_char()`, which **issues a brand-new random 5-letter password**
or wall NOR — ("您的新密码是XXXXX请用新的密码连线") and
**immediately disconnects the link** — easy to mistake for a crash if
you don't already know this is by design (same category of trap
`bxsj`/`xiyouji`'s NOTES already warn about: a "disconnect" that is
actually correct game behavior). Reconnecting with the new password
lands the character in the REAL start room `/d/xiakedao/沙滩` (a
different room object from the `shatan1` gate, same short name
"沙滩" — confusingly) with a fisherman NPC, full `score`/`i` access, and
the actual 侠客岛 (Ke Xia island) content available. Verified end-to-end
live, twice (once organically stepping through each `input_to` prompt,
once after a same-character reconnect mid-flow — the escort/register
state genuinely survives a real disconnect+reconnect, confirming this
part of the flow is robust).

### Exploring the starting zone — 侠客岛 is a self-contained tutorial island

Read room `.lpc` source throughout rather than guessing blind — exits
are not always neighbors-of-neighbors intuitive here (a hidden `enter`
exit that only exists for a 15-second real-time window after a
`call_out`, a `climb tree`/`wear coat`/`jump fall` puzzle gating one
internal passage). Confirmed working, all via `wentian`:

- **Safe skill-teacher NPC, reachable without leaving the island**:
  `/d/xiakedao/pubu` (瀑布, reached `shatan`→n→n→n→n→northup`) hosts
  `npc/master2.lpc` (蓝衣弟子), whose `recognize_apprentice()` is
  hardcoded `return 1` — teaches `strike`/`force`/`parry`/`dodge` to
  anyone. `xue dizi strike` (his short alias) produced "你向蓝衣弟子
  请教有关「strike」的疑问...你的「strike」进步了！", and `skills`
  immediately showed `strike (strike) - 初学乍练 1/0`. This is the
  organic first-skill path the task asked for; done live, not by code
  review.
- **Sect join is deliberately NOT available at the island's sect-rep
  NPCs** — and this is correct design, not a bug worth "fixing". A
  guided-tour escort (`龙五`) drags a fresh character through a cave
  complex lined with one low-generation representative NPC per sect
  (`d/xiakedao/npc/{baituo,xingxiu,xueshan,wudang,emei,...}.lpc`, each
  calling `create_family(name, generation, "弟子")` — so they DO have a
  real `family`, unlike the purely-informational island NPCs read in an
  earlier pass). Tried `bai xueshan dizi` on one (金轮, generation 13)
  live: "金轮说道：要拜师，你得去拜我师父" (to become a disciple you
  must go worship MY master) — traced to the shared
  `d/xiakedao/npc/xkdnpc.h`'s `attempt_apprentice()`, which is
  **hardcoded to always refuse** for every one of these NPCs. Real
  recruitment requires reaching an actual sect hall on the mainland
  (`d/wudang`, `d/shaolin`, etc.), gated behind the same boat/cart
  transit as everything else off-island (below). Confirmed by reading
  `feature/apprentice.lpc`'s `recruit_apprentice()` (a real, un-gated
  implementation) plus every island rep NPC's shared header — not a
  guess.
- **Shop / economy**: `牛掌柜`'s 聚金阁 (`d/city/jujinge`, mainland —
  reached via admin `goto`, see below) correctly listed prices (`list`)
  and correctly rejected a purchase with insufficient funds ("穷光蛋，
  一边呆着去！"); after admin-cloning 5 silver (spending the WHOLE
  stack, i.e. exactly the shape that triggers the bug documented below)
  `buy tong jing` succeeded ("你从牛掌柜那里买下了一面铜镜。"),
  inventory correctly showed the mirror and zero silver left. A real
  player reaches this shop with the 20 silver `init_new_player()`
  grants at registration (`adm/daemons/logind.lpc`); this was
  admin-currency-assisted (see "not verified live" below for why).

### Off-island travel is real-time-gated and genuinely slow to test solo

`/d/xiakedao/shatan`'s fisherman auto-offers a boat `enter` exit exactly
once, ~1 real second after the room is entered, via a `call_out` chain
(`check_trigger`→`on_board`(+15s)→`arrive`(+20s)→`close_passage`(+20s));
missing the initial 15-second boarding window leaves the underlying
`chuan` (boat) room's `yell_trigger` flag SET until `shatan`'s own next
driver-scheduled `reset()` (this lib's `config.fluffos` sets `time to
reset : 1800`, i.e. up to 30 real minutes) — `shatan.lpc:111`'s
`reset()` is the ONLY code that clears it. Missed the window on the
first live attempt (normal exploratory-testing pace, not a bug); a
driver restart (unrelated, see "an unrelated process died" below)
incidentally reset all in-memory room state and gave a second live
window, which was also missed testing navigation. Reaching the mainland
past this point (to independently verify a real sect join, a
skill-teacher NPC outside the island, or a player-currency shop
purchase) was **NOT completed within this session's time budget** — see
explicit list below. Scouted the mainland via wizard `goto` instead
(shop test above; sect-hall NPCs not individually walked to).

### Bugs found and fixed

**1. `inherit/item/combined.lpc:19` (originally) — stackable items spent to exactly zero silently never self-destruct (money in particular). NEW manifestation of the AGENTS.md §8.3a bug class (`private` function bound to a driver-origin dispatch, demoted to `DECL_HIDDEN` once inherited), via `call_out` instead of `add_action`.**

- Found organically: cloned 5 silver as admin, bought a 5-silver item
  (spending the WHOLE stack to exactly 0) at `d/city/jujinge`. The
  purchase itself succeeded and looked completely normal on screen —
  but `debug.log` immediately logged:
  ```
  apply() with insufficient permission:
  cob: null, ob: clone/money/silver#295, function: destruct_me,
  origin: internal, needs: private, has: hidden
  ```
- Root cause: `set_amount(0)` (line ~23) does
  `::move(VOID_OB); call_out("destruct_me", 1);` to clean up an
  emptied stack — but `destruct_me()` was declared `private void`.
  `inherit/item/combined.lpc` is inherited (via `inherit/item/money.lpc`)
  by every stackable item — silver, gold, coin, and any other combined
  item — so `private` demotes to `DECL_HIDDEN` on the compiled
  money/item class, and the driver refuses the `call_out` apply exactly
  the same way it used to refuse `command_hook`'s `add_action` apply in
  §8.3a's original instance. The zeroed clone is moved to `VOID_OB`
  correctly (that part isn't gated) but then just sits there forever,
  never actually destructing — a permanently-orphaned zero-amount
  object per occurrence, one denied-apply log line each time.
- Fix: dropped `private` (no `nomask` was present to preserve):
  ```lpc
  // BEFORE: private void destruct_me() { destruct(this_object()); }
  // AFTER:  void destruct_me() { destruct(this_object()); }
  ```
- Found and fixed the **identical** pre-existing copy in
  `d/xueshan/inherit/liquid_content.lpc:26` (inherited by
  `d/xueshan/obj/suyou.lpc`, a bottled-liquid item) by code-shape match
  — not independently live-reproduced, but byte-for-byte the same
  `private void destruct_me() {...}` / `call_out("destruct_me", 1)`
  pair inside a file whose own directory name (`.../inherit/...`) says
  it's meant to be inherited.
- Verified: fresh driver restart with the fix in place, repeated the
  exact clone-5-silver/spend-to-zero repro — zero `insufficient
  permission` lines in `debug.log`, purchase behaves identically from
  the player's perspective (the bug was always invisible on-screen;
  only the orphaned-object leak and the log spam are new-fixed).

**2. `feature/action.lpc:70` (originally) — same bug class, much higher blast radius: EVERY timed kungfu-skill/drug status effect in the game silently never fires for players.**

- `feature/action.lpc` (aliased `F_ACTION`) is `inherit`ed directly by
  `inherit/char/char.lpc` — the player-body base class itself. Its
  `start_call_out(function fun, int delay)` is the lib's single shared
  primitve for "run this closure after a delay, robust to the object
  that scheduled it being destroyed first" (used for poison/drug timers,
  kungfu buff/debuff expiry, multi-hit combo follow-ups, etc.) — grep
  found call sites in **over 130** `kungfu/skill/*`, `kungfu/class/*`,
  and `clone/drug/*` files, i.e. the large majority of this lib's
  special-move and medicine content. It works by scheduling
  `call_out("eval_function", delay, fun)`, and `eval_function` was
  declared `private void`.
- This one took real effort to pin down live — the natural trigger
  (`fu hu gu`, taking a 虎骨/tiger-bone drug that schedules a
  `remove_effect` callback after `query("con")` real seconds) produced
  no visible symptom and, on a first check, no error either; the
  `call_out` genuinely needs to actually FIRE before the denied-apply
  line appears, and on a driver busy with background NPC activity that
  took closer to a minute of real wall-clock than the drug's own
  ~17-second nominal delay. Confirmed definitively with the wizard
  `call` command (`call me->start_call_out(1,3)`, a direct, unambiguous
  repro) plus a genuinely patient wait:
  ```
  apply() with insufficient permission:
  cob: null, ob: clone/user/user#1, function: eval_function,
  origin: internal, needs: private, has: hidden
  ```
- Fix: dropped `private` (no `nomask` present):
  ```lpc
  // BEFORE: private void eval_function(function fun) { evaluate(fun); }
  // AFTER:  void eval_function(function fun) { evaluate(fun); }
  ```
- Verified clean post-fix with the same direct `call me->start_call_out(...)`
  repro, waiting a full 75+ real seconds afterward: zero `insufficient
  permission`/`eval_function` lines. Also re-ran the organic `fu hu gu`
  drug-consumption path post-fix — clean.
- **This is worth its own generalization of AGENTS.md §8.3a**: the
  existing entry is scoped to `add_action`-bound dispatchers
  (`command_hook`); this project now has two more instances (one in
  this lib, both via `call_out` instead) proving the SAME
  `DECL_PRIVATE`→`DECL_HIDDEN`-once-inherited mechanism applies to
  *any* driver-origin apply that dispatches by function-name string —
  `call_out()` and (per the existing entry) `add_action()` at minimum,
  quite possibly `set_heart_beat()`'s implicit `heart_beat()` call too
  (not tested here). See draft catalog text in the final report for a
  §8.3a addendum.

**3. `clone/npc/shan.lpc:181` — pre-existing missing closing quote crashes this NPC's entire program, taking down any room/NPC interaction chain that happens to reference it.**

- Found via the `call`-command trace investigation above (an unrelated
  wandering NPC's `random_move()`/`chat()` heartbeat routed through a
  room containing `shan.lpc`, at which point `debug.log` showed a
  cascade of `Illegal character 0x.. ` errors and finally `执行时段
  错误：*No program in object '/clone/npc/shan'!`).
- Root cause (AGENTS.md §6.6 "missing closing quote" class, textbook
  instance): `command("say 这种私人恩怨太多了，你还是自强不息啊);` —
  the string literal is missing its closing `"` before the `)`,
  swallowing the rest of the file's text into one giant unterminated
  string until the compiler's tokenizer desyncs and finally trips on
  raw non-ASCII bytes several lines later (line 186's Chinese text,
  now sitting OUTSIDE any string literal) — this is why the reported
  "illegal character" line is nowhere near the real defect.
- Fix: added the missing quote and full-width period (matching every
  sibling `command("say ...")` line's style in the same function):
  ```lpc
  // BEFORE: command("say 这种私人恩怨太多了，你还是自强不息啊);
  // AFTER:  command("say 这种私人恩怨太多了，你还是自强不息啊。");
  ```
- Verified: `update /clone/npc/shan.lpc` → "重新编译
  /clone/npc/shan.lpc：成功！" (previously this same command would have
  failed the same way the original crash did).
- Not independently chased further (e.g. whether `shan.lpc` is reachable
  from a fresh character's normal playthrough) — flagged here because
  it was a genuine, currently-live crash surfaced by this pass, fixed
  on sight per the standard proactive-fix policy, not because it was
  part of the planned test route.

### An unrelated process died mid-session (environment note, not a mudlib bug)

The native driver process (a plain `setsid nohup .../driver
config.fluffos &`, PID recorded and monitored per AGENTS.md §10.5) was
found dead partway through this session with **no crash trace at all**
in `debug.log` (no `FATAL ERROR`, no `SIGTERM` line, nothing — the log
just stops mid-preload-warning-spam). Given this is a shared multi-agent
environment (other libs' driver processes were visibly running
throughout, per `ss -tlnp`/`ps aux`), this reads as an external
kill/OOM rather than anything the mudlib did — restarted cleanly
(`Accepting telnet connections`/`Initializations complete`), all prior
save-file state intact, no fix needed or applicable. Noted here in case
a future session sees the same "driver just isn't there anymore, zero
debug.log explanation" symptom.

### Explicitly NOT verified live, and why

- **A player reaching the mainland organically** (via the `chuan` boat
  → `da che` carriage chain) — the boat's one-shot 15-second boarding
  window was missed twice (normal testing pace the first time; a
  same-second navigation slip the second, right after the unrelated
  driver restart reset the trigger state) and the underlying
  `yell_trigger` flag then blocks a retry until `shatan`'s own
  driver-scheduled `reset()`, up to 30 real minutes per
  `config.fluffos`'s `time to reset : 1800` — outside this session's
  budget. **This also means**: a real sect join (`bai`/`apprentice` on
  an actual mainland sect-hall master with a low `family/generation`),
  a mainland skill teacher, and a player-currency (not admin-cloned)
  shop purchase were none of them completed by the ORGANIC player
  character. The shop mechanic itself (list/insufficient-funds/
  successful-purchase-to-exactly-zero) WAS verified live, just with
  admin-cloned currency rather than `wentian`'s own starting 20 silver.
- **Real combat** (`fight`/`kill`/`hit`) was not exercised at all — no
  stat-mirroring "training dummy" NPC was found anywhere on 侠客岛
  itself (the real `mu-ren.lpc`/`xiangpi-ren.lpc`-style dummies live at
  `d/shaolin`, `d/taihu`, `d/xueshan`, `d/chengdu` — all mainland,
  behind the same travel gate above); the closest in-budget candidate,
  `d/xiakedao/liangong`'s `npc/shaonian.lpc` (练功室, "peaceful"
  attitude, default `accept_fight()` from `inherit/char/npc.lpc` would
  accept a `fight` challenge per its own logic), was read but never
  actually challenged live — reaching it also requires the
  `climb tree`/`wear coat`/`jump fall` puzzle at `pubu`, and time ran
  out before combining that with a genuine `fight` attempt.
- **Death/respawn** — not attempted at all; would need either the
  above-blocked real combat or an admin-forced kill, and was
  deprioritized in favor of the two confirmed high-impact bugs above.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

基于 XKX 引擎的自制游戏。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 53 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。
