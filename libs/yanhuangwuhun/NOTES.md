# yanhuangwuhun — 炎黄武魂 conversion notes

## What this is

Archive `炎黄武魂_64bit.rar` (#66). Self-identifies (config.cfg `name :` field,
and the `adm/etc/welcome` banner) as **「武林群侠传」之炎黄武魂Ⅱ** ("Wulin
Qunxia Zhuan: Yanhuang Wuhun II" — "Chronicles of Martial Heroes: Soul of
the Yellow Emperor II"). Two bundled `.doc`/`.docx` files at the archive
root ("武林群侠传2（炎黄武魂）修改更新说明.doc" and "炎黄武魂终极版修改思路
及说明.docx") confirm the same real title. The slug `yanhuangwuhun` (from
the archive filename) differs slightly from the self-identified name but
was kept as-is per the task's port-assignment convention — noted here per
instructions.

**Lineage**: `master.lpc`'s header comment is the giveaway — "for ES II
mudlib / original from Lil / rewritten by Annihilator (11/07/94) /
modified by Xiang for XKX (12/15/95) / updated by Doing Lu for hell (2K) /
**Modify By Linux@lxtx for yh 2003.3**" ("yh" = 炎黄/Yanhuang). This is the
same **ES II lineage** already seen in es1_win/esI/xkx2001/rzrmud/xo/
beimeixiakexing2001/xinkuangxiangkongjian2/yueyingqiyuan/wuhanzhan (a 2003
fork of that common ancestor, done by an author using the handle "lxtx").
`adm/single/{master,simul_efun}.c` layout (not `adm/obj/`) matches the
xkx2001/rzrmud branch of that family most closely.

**"64bit" in the archive name refers to a bundled prebuilt driver, not the
mudlib**: the raw archive contains `mudos.exe` (a 2006 Win32 MudOS binary)
at the top level AND a separate `fluffos64/` directory holding a full
Cygwin-based 64-bit FluffOS driver build (`driver.exe` + a dozen
`cygwhatever.dll`s, dated Oct 2016) plus a `start64.bat` launcher. Both
were ignored entirely, per standing project policy — only the LPC mudlib
source was extracted/converted/run through this project's own FluffOS
build.

- Raw size: ~10,756 `.c`/`.lpc` files (~87MB raw). Normal-sized lib, NOT a
  mega-lib — full `lpcc_check.sh` sweep was run (no memory concerns; host
  had >2GB free / 16GB+ available throughout).
- Port assigned: **40060** (next free per TODO.md after 40056-40059).

## Pipeline steps

1. Extracted `archives/炎黄武魂_64bit.rar` → `libs/yanhuangwuhun/raw/` with
   `scripts/extract.sh` (plain `unrar`, no password/SFX issues).
2. Converted `raw/` → `work/` with `scripts/convert_lib.sh`:
   - encoding: `already_utf8=475 converted=11549 lossy=8 skipped_binary=41`
     (the 8 lossy files: 2 `.bak` quest-daemon files, 2 `adm/etc/ip/`
     banned-IP data files, 1 `cmds/arch/recovermud.c` admin tool — all
     non-critical data/dead-tooling, not on the boot/registration path)
   - renamed to 10,756 `.lpc` files (0 stray `.c` remaining)
   - fixed 395 literal `".c"` references (`.lpc`/`.h` scope) + 5
     `#include <....c>` angle-bracket refs + converted 9 local
     angle-bracket `<x.lpc>` includes to quoted form
   - `static` → `nosave` touched 63 files (see the counterexample fix
     below — this one had an unusually large false-positive collision)
3. Wrote `libs/yanhuangwuhun/config.fluffos` (port 40060, mudlib directory
   pointed at `work/`, config's original name field `炎黄武魂Ⅱ` kept).
   Created `log/`, `binaries/`, `adm/tmp/` dirs (didn't exist in the raw
   archive).
4. Read `master.lpc`/`securityd.lpc`/`chinese.lpc`/`named.lpc`/
   `logind.lpc`/`message.lpc` proactively before first boot and applied
   every applicable catalog fix (below) before ever attempting a full
   driver boot.
5. Booted `build-debug/src/driver` on port 40060 — required two rounds of
   fix-then-reboot (see "Fixes found only via a real boot" below) before
   reaching a fully clean boot with zero errors.
6. Verified the full registration flow with `mudclient.py` three
   independent times, each in one continuous connection, each reaching an
   actual room in the game world.
7. Ran the full `lpcc_check.sh` sweep (normal-sized lib, no §6b OOM
   concern) — iterated twice more after the first sweep to fix newly
   discovered content bugs, ending at **10747/10756 = 99.92% pass**.
8. Killed the driver by exact PID when done (never used a broad
   `pkill -f` — verified other agents' concurrently-running drivers
   for other libs, e.g. `huoying`, `yuxuechongsheng`, `haiyang2`, were
   never touched).

## Fixes applied proactively (before first boot), per the AGENTS.md catalog

- **§15h (is_chinese GBK byte-range check)** — `adm/simul_efun/chinese.lpc`'s
  `is_chinese()` was the classic whole-string GBK lead/trail-byte-range
  check (`str[i] < 161`, `str[i] < 176 || str[i] >= 248` gated on
  `i%2==0`). Rewrote as a CJK Unified Ideographs codepoint range check
  (`str[i] >= 0x4e00 && str[i] <= 0x9fff`), dropped the `i%2==0` byte-lead
  gate, and changed the length floor from `< 2` (byte-oriented) to `< 1`
  (character-oriented).
- **§15h (check_legal_name length bounds)** — `adm/daemons/logind.lpc`'s
  `check_legal_name(name, maxlen)` had `strlen(name) < 2 || strlen(name) >
  maxlen` (both call sites pass `maxlen=4`, a byte-oriented "2 Chinese
  characters" bound). Fixed to `strlen(name) < 1 || strlen(name) > maxlen
  / 2` (halves the effective bound to match character counting; call
  sites unchanged). Also fixed the SEPARATE combined-length check in
  `get_name()` (surname+given-name concatenation): `strlen(fname) < 4` →
  `< 2`, matching the message text's own stated "at least two Chinese
  characters."
- **§15h (named.lpc deep fix)** — `adm/daemons/named.lpc` has the full
  "deep" shape documented in the catalog:
  - `#define PATH(name) (name[0..1] + "/" + name)` (first GBK char, 2
    bytes) → `name[0..0]` (first character).
  - Every `strlen(name) < 2` guard (in `remove_name`, `map_name`,
    `who_is`, `invalid_new_name`) → `< 1`.
  - A `name[0..1]` bucket-key reference in `remove_name` → `name[0..0]`.
  - `invalid_new_name()`'s sliding-window similar-name check: guard
    `strlen(name) < 4` → `< 2`; loop bound `i <= l - 4` → `i <= l - 2`;
    2-char-window slices `name[i..i+3]` (4 bytes) → `name[i..i+1]`;
    3-char-window slices `name[i..i+5]` (6 bytes, guarded by `i+6<=l`) →
    `name[i..i+2]` (guarded by `i+3<=l`).
- **§15p (DNS/intermud daemon exclusion)** — checked `adm/etc/preload`:
  `dns_master` (which DOES exist as a file, `adm/daemons/network/
  dns_master.lpc`) is simply **not listed** in preload at all. Nothing to
  exclude — confirmed via `grep -rl dns_master` across the whole tree
  that it's referenced only from its own header file, never invoked.
- **§14 (valid_override 3-arg)** — `master.lpc`'s `valid_override(file,
  name)` only checked the 2-arg `file == SIMUL_EFUN_OB` form. Upgraded to
  the 3-arg `(file, name, main_file)` signature, added `main_file ==
  SIMUL_EFUN_OB || main_file == MASTER_OB` to the same early-allow check
  (free insurance fix; per §14 this may never surface on a real boot, and
  didn't here either — no `valid_override`-related errors appeared in any
  boot log).
- **§15n (custom securityd valid_read blocking compile-time access)** —
  `adm/daemons/securityd.lpc` has a genuine custom ACL (`exclude_read`/
  `trusted_read` tables keyed by directory + wiz-status, default-DENY
  unless a rule matches). Added the standard early-allow for
  `func == "load_object"/"recompile_object"/"include"` right after the
  existing `func == "file_size"` allow. Applied proactively — did NOT
  wait to see the "Read access denied" crash (unlike shujian2008, where
  this was originally discovered), since the ACL shape was immediately
  recognizable from a plain read-through.

## Fixes found only via a real boot / registration test (not visible from source review alone)

- **NEW variant of §15s (message() 4th-arg + a §8b forward-reference
  interaction)** — `adm/simul_efun/message.lpc`'s local `message(mixed
  arg, string message, mixed target, mixed exclude)` wrapper delegates to
  `efun::message(...)`, whose 4th ("exclude") parameter is declared `void
  | object | object *` — an explicit `int 0` (as every `tell_room()` call
  with no exclude list produces) fails that type check at runtime
  ("Bad argument 4 to EFUN message()"). This crashed EVERY daemon whose
  `create()` calls `CHANNEL_D->do_channel(...)` → `tell_room()` during
  preload (natured, punishd, storyd, eventd, pkd, memoryd, cpud,
  analectad, rzr_d — 9 preload daemons hit this on the very first boot).
  First fix attempt (guard `if (!exclude) efun::message(arg,message,
  target); else ...`) did NOT fully resolve it — the SAME error still
  fired afterward but this time from `tell_room()` itself, in a live
  gameplay session (a preloaded room's own NPC/daemon calling
  `tell_room()`), tracing to `simul_efun.lpc` line 308 (the `tell_room()`
  body itself), not to the guarded `message()` function. Root cause: per
  **§8b** (same-file forward-reference gotcha), `tell_object()`/
  `tell_room()`/`shout()`/`write()`/`say()` are all defined textually
  BEFORE `message()`'s own definition in the same composed file, and they
  call the bare (unprefixed) name `message(...)` — without a prior
  declaration, the compiler falls back to binding that bare identifier
  directly to the real EFUN at each of those call sites (since "message"
  is a known valid symbol, a real efun, rather than an "Undefined
  function" error), **completely bypassing the local override and its
  guard**. Fixed by adding a `varargs void message(mixed, string, mixed,
  mixed);` forward declaration at the top of the file, before any of its
  callers. (The forward declaration itself needed `varargs` too — a
  first attempt at a strict 4-arg-required declaration broke every 3-arg
  call site, e.g. `message("tell_object", str, ob)`, with "Wrong number
  of arguments" compile errors.) Verified via `lpcc` recompile + a second
  clean boot + two more full registration-flow tests: zero
  `message()`-related errors in any subsequent run.
- **Rename-width bug (`.c`→`.lpc` extension-strip, same shape as the
  nitan_ceshi/nitan_san precedent)** — `adm/daemons/eventd.lpc` and
  `adm/daemons/storyd.lpc` both do `get_dir(DIR + "*.lpc")` then
  `map_array(names, (: $1[0..<3] :))` to strip the extension for a
  `find_object()`/`destruct()` pass over stale preload state — `[0..<3]`
  was correct for stripping the OLD 2-character `.c` extension but leaves
  a trailing `.l` after the rename (`"emei.lpc"[0..<3]` → `"emei.l"`, not
  `"emei"`). This surfaced as `call_other() couldn't find object
  '/adm/daemons/event/emei.l'` during `eventd`'s preload. Widened both
  (and two further instances of the identical idiom in `adm/npc/
  luban.lpc`, a "player-built house" NPC that lists/clears/rewrites
  dynamically-generated room files by the same convention) from `[0..<3]`
  to `[0..<5]` (the extension grew by 2 characters, so the cutoff widens
  by 2).
- **§3 counterexample (moniHuafu-style `static`/`nosave` string-literal
  collateral) — unusually large this time**: the blanket `\bstatic\b` →
  `nosave` sed hit **105 occurrences across 60 files**, all instances of
  the pre-existing `log/static/` log-subdirectory naming convention
  (`log_file("static/CRASHES", ...)`, `"static/killrecord"`,
  `"static/security"`, `"static/quest"`, etc. — the real `log/static/`
  directory exists on disk) AND several `set`/`query`/`add`/`delete`
  dbase property KEYS using the same word as a namespace prefix
  (`me->query("static/sadly")`, `me->add("static/marry", 1)`,
  `me->delete("static")`). None of these are the `static`/`nosave`
  keyword — reverted all 105 via `sed -i 's/"nosave/"static/g'` scoped to
  files that had the collision (safe: the pattern requires an opening
  quote immediately before the word, which never collides with the real
  keyword substitution). Verified afterward: zero remaining `"nosave`
  string-literal hits, and a separate grep confirmed no bare `static
  <type> name(...)` function declarations survived anywhere (the actual
  intended fix is intact).

## Content bugs found via the `lpcc_check.sh` sweep (fixed)

Sweep pass rate before any content fixes: 10732/10756 = **99.78%** (24
failures). After fixing the shared-root and individually-diagnosed bugs
below: 10747/10756 = **99.92%** (9 failures remaining, all confirmed
non-bugs or genuine content gaps — see next section).

- **§10 (missing closing quote) — the actual root cause of a 4-file
  cascade**: `inherit/condition/damo.lpc`'s `die_reason()` had `return
  name + HIM "发作身亡了;` — the string literal never closed before the
  `;`, which swallowed the rest of the file's text as string content
  until the parser happened to hit the next real `"` much further down,
  producing a confusing "syntax error" + a run of "Illegal character"
  errors at seemingly unrelated later lines (a moved/renumbered version
  of this same symptom reappeared after an EARLIER, unrelated typo fix
  in the same file — see below — until this real root cause was found).
  Fixed by closing the string. This one file is `inherit`ed by
  `kungfu/condition/damo_luanqi.lpc`, `damo_shangshen.lpc`, and
  `damo_zheyuan.lpc` — fixing the shared base resolved all 4 sweep
  failures at once (§8g pattern).
- A SEPARATE, also pre-existing bracket typo in the same file
  (`update_condition()`): `if (! intp(cnd["level"]) || ! intp(cnd["remain"]
  || ! stringp(cnd["id"])))` — a misplaced/missing `)` nested the rest of
  the condition inside `intp()`'s own argument list. Fixed to `if (!
  intp(cnd["level"]) || ! intp(cnd["remain"]) || ! stringp(cnd["id"]))`.
  (This was the FIRST bug found in this file; fixing it alone didn't
  fully resolve the sweep failure because the §10 quote bug further down
  the same file was the deeper, still-unfixed cause of the cascade.)
- **Missing macro, §8g-style (target file exists, macro was just never
  defined)**: `TEXT2PIC_D` — `adm/daemons/text2pic_d.lpc` exists on disk,
  but `include/globals.h` never defined a macro pointing at it. Used by
  `d/beijing/npc/kangxi.lpc` and (transitively) `d/beijing/hg.lpc`.
  Added `#define TEXT2PIC_D "/adm/daemons/text2pic_d"` next to its
  siblings, resolving both failures at once.
- **Missing macro, §8g-style**: `TYPE_CHARM` — `include/armor.h` defines
  a `TYPE_HEAD`/`TYPE_NECK`/`TYPE_CLOTH`/.../`TYPE_BOOTS` family of
  equipment-slot constants but was simply missing a `charm` slot, needed
  by `inherit/armor/charm.lpc`. Added `#define TYPE_CHARM "charm"`
  matching the existing naming convention exactly.
- **§9 (fullwidth punctuation as code syntax)**: `d/death/npc/mamian.lpc`
  had 14 `set_skill("...", 650）;` calls using a fullwidth right
  parenthesis `）` (U+FF09) instead of ASCII `)` as the actual closing
  token of the function call (confirmed in code position, not inside a
  string). Fixed all 14 occurrences (`sed 's/650）;/650);/g'`); this also
  resolved the separate sweep failure on `d/death/yinyangta17.lpc`
  (which references `mamian`).
- **Missing local variable declarations** (typo): `kungfu/skill/
  riyue-bian/chan.lpc`'s `perform()` used `ap`/`dp` without ever
  declaring them. Added `int ap, dp;` alongside the function's other
  locals.
- **Missing semicolon** (typo): `kungfu/skill/kuihua-mogong/perform/
  wswd.lpc`'s `check_wd()` had `x = me->query("int")` with no terminating
  `;` before the next statement, producing a cascading syntax error two
  lines further down. Added the semicolon.
- **Wrong argument type to `set_name()`** (typo): `d/baituo/obj/bowl.lpc`
  called `set_name("海口大碗", "bowl")` — the 2nd arg must be a `string
  *` (alias array), not a bare string, per this driver's `set_name()`
  signature (and every sibling item file in this lib already uses the
  array form). Fixed to `set_name("海口大碗", ({"bowl"}))`.
- **Duplicate function definition** (copy-paste typo): `d/beijing/npc/
  dan/danB_6.lpc` defined `query_autoload()` twice, byte-identical bodies.
  Removed the second (dead) copy.
- **§15f (bare `array` type)**: `cmds/help2.lpc` had `array efun_search =
  DEFAULT_EFUN_PATHS;` / `array help_search = DEFAULT_HELP_PATHS;` — the
  combined declare+initialize form with a bare `array` type doesn't parse
  on this driver ("syntax error, unexpected L_IDENTIFIER" pointing at the
  variable name). Changed both to `mixed *`.
- **Wrong `query()` calling convention** (genuine content bug, not an
  encoding/rename artifact): `kungfu/class/generate/spekilled.lpc`'s
  `set_from_me()` did `exp = query("combat_exp", me) * 11 / 10;` — but
  this lib's local `F_DBASE::query(string prop, int raw)` takes a RAW
  flag as its 2nd argument, not a target object (unlike the "nitan"
  lineage's `query(prop, ob)` redirect convention, which this lib does
  NOT use — see "confirmed not needed" below). Reading a DIFFERENT
  object's own property needs an ordinary `call_other`. Fixed to
  `(int)me->query("combat_exp") * 11 / 10`.

## Remaining sweep failures (9) — confirmed non-bugs or genuine content gaps, not fixed

- **`/adm/daemons/story/guigu` and `/adm/daemons/story/mengzi`** —
  CONFIRMED sweep artifacts, not bugs: both daemons' `create()` calls
  `select_character()`, which filters `all_interactive()` (real connected
  non-wizard players) for a suitable recipient of a random "story" item;
  if none qualifies (always true under an isolated `lpcc` compile with no
  live connections), the daemon deliberately `destruct()`s itself — by
  design, not an error. Confirmed by reading both files' full source;
  neither produces any error in the real boot log, and neither is even on
  the `adm/etc/preload` list (loaded lazily by `storyd.lpc`'s directory
  scan, never actually instantiated without a live candidate player).
- **`/kungfu/skill/qingyun-bian`** — genuine but very low-impact content
  bug: its global `mapping *action` table computes `"force"`/`"damage"`
  values via `(int)this_player()->query(...)` directly in the top-level
  variable initializer (evaluated once at compile/load time, when there
  is no real player context — `this_player()` is 0). Every sibling skill
  file in `kungfu/skill/` uses fixed numeric literals in this same table
  shape instead (confirmed by checking several neighbors, e.g.
  `dugu-jiujian.lpc`). This is a genuine authoring bug in one skill's
  action table, but restructuring it to compute the values inside the
  `perform()` function (rather than a global initializer) is a real
  content change beyond a minimal fix — documented here rather than
  guessing at the intended numeric values. Only affects players who
  specifically use the "青云鞭"（Qingyun Whip) skill; does not affect
  registration, boot, or any other tested path.
- **`/d/baituo/obj/shedan`** — `inherit PILL;` (macro
  `#define PILL "/inherit/medicine/pill"` in `globals.h`) but no such
  file exists anywhere in the archive (`inherit/medicine/` only has
  `powder.lpc`). Genuine missing-content gap, affecting exactly this one
  poison/pill item; not fabricated a replacement base class per the
  project's standing policy on missing content (§11/§13).
- **`/adm/daemons/vrm_server` and `/d/death/heisenlin`** — reference
  `SCHEDULE_D`, a macro that is never defined anywhere in this archive,
  and there is no `scheduled`/`schedule_d`-named daemon file at all (only
  a `help/schedule` help-text file exists). Genuine missing-content gap —
  not fabricated a stand-in daemon.
- **`/adm/daemons/huanjing2003/temp/check_room`,
  `huanjing1_pro_b`, `hj_room_created`** — all three live under a
  `huanjing2003/temp/` scratch subdirectory, are not `#include`d,
  inherited, referenced by path, or preloaded ANYWHERE else in the lib
  (confirmed via `grep -rl` for each basename), and reference genuinely
  nonexistent headers/simul_efuns (`max_min.h`, `ctime_format()`).
  Orphaned dev/test leftovers (§13-style dead content), left as-is.

## Confirmed NOT needed (verified by reading source, not by hitting a crash)

- **§4 (lazy security-daemon `load_object` recursion)** — `master.lpc`'s
  `valid_read`/`valid_write` only call `find_object(SECURITY_D)`, never
  `load_object()`. No recursion risk; confirmed by reading both functions
  in full.
- **§7 (missing `get_root_uid`/`get_bb_uid`)** — both already implemented
  in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`.
- **§8c (`this_player()`-override footgun in `valid_read`)** —
  `securityd.lpc`'s `valid_read`/`valid_write` use the passed-in `user`
  parameter's `geteuid()` directly; neither ever overrides `user` with
  `this_player()`. Confirmed by reading both functions in full — no
  `if (this_player()) user = this_player();`-shaped code anywhere.
- **§8d/§15o (`get_include_path()`)** — checked whether this master.lpc
  needed the apply (all headers here live under the single shared
  `include/` directory, already covered by config's `include directories`
  setting) and additionally verified directly against the ACTUAL FluffOS
  driver source (`compiler/internal/lexer_utils.cc`'s
  `init_include_path()`): when `master::get_include_path()` is undefined,
  `safe_apply_master_ob()` returns a null/error sentinel and the function
  returns WITHOUT touching `inc_path`, which was already reset to the
  config default (`inc_list`) by the previous compile's
  `deinit_include_path()` — i.e. the config default silently continues to
  apply, contrary to one possible reading of the catalog's §15o
  write-up. Empirically confirmed too: three full registration-flow tests
  each triggered dozens of live, mid-connection lazy compiles (rooms,
  NPCs, the player body class, items) using `<ansi.h>`/`<room.h>`/etc,
  none of which failed to resolve their includes.
- **§15l (`SIMUL_EFUN_OB` destruct-in-`master::create()` crash)** —
  `master.lpc create()` only does `write(...)` + none of `create()` calls
  `destruct()`/`efun::destruct()` at all. Confirmed by reading the whole
  function.
- **§15m (stale `restore()` crash masquerading as a maintenance gate)** —
  `adm/daemons/versiond.lpc` (this lib's version-sync daemon, same
  family as zhonghua2's bug) calls `restore()` unguarded in `create()`,
  but (a) no stale/corrupted `data/versiond.o` was shipped in this
  archive (checked `data/` — only 8 unrelated `.o` files exist, no
  `versiond.o`), and (b) `adm/etc/config`'s `release server : local`
  setting makes `setup()` set `version_ok = 1` immediately regardless of
  `restore()`'s outcome. No maintenance-gate message ever appeared in any
  boot/test session.
- **§15p (DNS daemon preload exclusion)** — see above, nothing was
  actually preloaded, so nothing to exclude.
- **§15u (dormant phone-home/self-destruct license check)** — grepped
  `securityd.lpc`/`master.lpc` for `rm`/`unlink`/`shutdown`/`rmdir`
  combined with a suspicious opaque gate; found none.
- **§15v (`LONELY_IMPROVED`-style `efun::` gating family)** — not
  applicable; this is ES II lineage, not the NT/nitan/Lonely lineage that
  bug is specific to. No such flag/pattern exists anywhere in this lib.
- **§15w (`log_error()`/`error_handler()` warning-vs-error conflation)** —
  `master.lpc`'s `log_error()` has its player-facing broadcast lines
  ALREADY commented out by the original author (`//if (this_player(1))
  efun::write(...) else //if (this_player()) tell_object(...)`) — only
  `efun::write_file(LOG_DIR + "log", message)` is live, so compile
  warnings routed through this apply are written to a log file only,
  never shown to a connected player. Confirmed both by reading the
  function AND empirically: three full registration + gameplay sessions
  produced zero unexpected system messages.
- **The "nitan"-lineage simul_efun/dbase architecture bug (§15)** — this
  lib's `adm/simul_efun/*.lpc` files have no bare `set`/`query`/`delete`
  simul_efun definitions at all (confirmed: `wizard.lpc`, `object.lpc`,
  `message.lpc`, `override.lpc`, `path.lpc`, `user.lpc`, `gender.lpc`,
  `atoi.lpc`, `util.lpc`, `file.lpc` — none define these). Property
  storage goes through `F_DBASE` (`feature/dbase.lpc`) inherited directly
  by each object, the architecturally-correct pattern (same conclusion as
  rzrmud/es1_win/xkx2001 and the rest of the ES II family). The §15b
  family of "only ever called, never defined" nitan-lineage simul_efuns
  (`remove_ansi`, `noansi_strlen`, `B2G`, `db_affected`, `clr_ansi`,
  `changed_match_path`, `query_bandwide`, `query_shadowed`, `addn_temp`)
  were each grepped for call sites: all 0 hits except `chinese_number`
  (real, already implemented, delegates to `CHINESE_D`) and 2 commented-
  out `addn(...)` calls (dead code).

## Registration flow — read before testing

`adm/daemons/logind.lpc`'s callback chain: `logon()` → banner → `get_id`
(English id, `check_legal_id`: lowercase letters only, 3-10 chars, no
digits — using an id with a digit produces a confusing rejection cascade
that consumes subsequent `--send` lines as retries; learned this the hard
way on this lib too, see transcript below) → `confirm_id` (y/n, new
character if yes) → `get_surname` (Chinese, ≤2 chars, optional — blank
skips) → `get_name` (Chinese, ≤2 chars) → combined-length check →
`NAME_D->invalid_new_name()` (duplicate/similar-name/compound-surname
check) → `new_ad_password`/`confirm_ad_password` (≥5 chars, admin/backup
password) → `new_password`/`confirm_password` (≥3 chars, must differ from
admin password) → `get_type` (1-5 character archetype, blank defaults to
5/"均衡型") → `get_gender` (m/f) → `make_body()` → `enter_world()`. No
hidden BIG5/student/client-version pre-id gate — the very first prompt IS
the real id prompt (unlike xiyangzaixian3/xiakexinzhuan2). "new"/"none"/
"guest"/"cancel" are explicitly banned ids (routed to a guest/deny path,
not character creation), matching several other libs in this project.

## Registration flow — verified transcripts (3 independent runs, one continuous connection each)

**Run 1** — id `qinfeng`, surname `秦`, given name `风`, type 均衡型
(default/blank), gender m:
```
您的英文名字...：qinfeng
使用[qinfeng]...您确定吗(y/n)？y
您的中文姓氏...：秦
您的中文名字...：风
请设定您的管理密码：admin1234
请再输入一次...：admin1234
请输入你的普通密码：pass123
请再输入一次...：pass123
请您选择...类型：(blank -> 均衡型)
您要扮演男性(m)的角色或女性(f)的角色？m
你连线进入炎黄武魂Ⅱ。
世外桃源 - ...(full room description, exits west/east/north/south, NPCs 水笙/狄云 present)
> look  -> re-displays the same room correctly
> quit  -> 欢迎下次再来！
```
Zero errors in `debug.log` for this run (this WAS the run that first
exposed the `message()`/`tell_room()` bug during PRELOAD, before login —
by the time registration itself ran, that had already been fixed).

**Run 2** — id `qinling`, surname `秦`, given name `岭`, type 耐力型,
gender f: identical successful flow, reached the same starting room
(世外桃源), `look`/`quit` both worked. Zero errors in `debug.log`.

**Run 3 (final, post-all-fixes)** — id `qinhuai`, surname `秦`, given name
`淮`, type 智慧型, gender f: identical successful flow, reached the same
starting room, `look`/`quit` both worked. **Zero errors in `debug.log`**
for the entire session (confirms the `message()`/`tell_room()`
forward-declaration fix is fully effective, not just partially).

All three characters' save data confirmed written to disk:
`data/login/q/{qinfeng,qinling,qinhuai}.o` and
`data/user/q/{qinfeng,qinling,qinhuai}.o`.

**Gotcha hit twice while testing** (worth flagging for future libs): using
a login id containing a digit (`qinfeng2`, `qinfeng5`) fails
`check_legal_id`'s letters-only check, and the resulting rejection loop
silently consumes every subsequent `--send` argument as a retry attempt at
the SAME prompt — by the time the script runs out of arguments, the
session is stuck mid-flow with no obvious error. Not a mudlib bug (the
letters-only id rule is intentional and correctly implemented) — just a
reminder to keep test ids simple/pure-alphabetic.

## lpcc sweep result

**10747 / 10756 = 99.92% pass** (9 failures, all confirmed non-bugs/
content gaps documented above — none affect boot, registration, or normal
gameplay reachable from the tested paths).

## Files changed (relative to `libs/yanhuangwuhun/work/`)

- `adm/simul_efun/chinese.lpc` — §15h `is_chinese()` fix
- `adm/daemons/logind.lpc` — §15h `check_legal_name()` + combined-length
  fix
- `adm/daemons/named.lpc` — §15h deep fix (PATH macro + sliding window)
- `adm/daemons/securityd.lpc` — §15n compile-time-access allowlist
- `adm/single/master.lpc` — §14 `valid_override` 3-arg upgrade
- `adm/simul_efun/message.lpc` — §15s guard + forward declaration
- `adm/daemons/eventd.lpc`, `adm/daemons/storyd.lpc`, `adm/npc/luban.lpc`
  (2 sites) — extension-rename-width `[0..<3]` → `[0..<5]` fix
- 60 files (105 occurrences) — reverted `static`/`nosave` string-literal
  collateral (see list logic above; not itemized individually here, all
  were `"static/..."`-shaped log paths or dbase property key names)
- `inherit/condition/damo.lpc` — §10 missing quote + bracket-mismatch fix
- `include/globals.h` — added `TEXT2PIC_D` macro
- `include/armor.h` — added `TYPE_CHARM` macro
- `d/death/npc/mamian.lpc` — §9 fullwidth-paren fix (14 occurrences)
- `kungfu/skill/riyue-bian/chan.lpc` — missing local var declarations
- `kungfu/skill/kuihua-mogong/perform/wswd.lpc` — missing semicolon
- `d/baituo/obj/bowl.lpc` — `set_name()` argument type fix
- `d/beijing/npc/dan/danB_6.lpc` — removed duplicate function
- `cmds/help2.lpc` — §15f bare `array` → `mixed *` (2 declarations)
- `kungfu/class/generate/spekilled.lpc` — wrong `query()` call convention
  fixed to `call_other`

## 2026-07-23: driver rebuild retest + LPC formatter + WASM check

- **Formatter**: ran `tools/lpc-syntax`'s `format-corpus.mjs` over all
  10756 `.lpc` files in `work/`; 10722 written, 30 already-conformant,
  4 errors (files it refused to touch). **Found a real formatter bug**
  while spot-checking: the formatter corrupts a same-line `::PARENT_FUNC(...)`
  call when the `if (` condition wraps across the closing paren onto its
  own line — it splits `::` into `: :` across a line break and drops the
  matching close-paren, producing invalid syntax (`if (: : move(dest,
  silent)\n)\n{ ... }`, an extra stray `}` left dangling). This is a bug
  in the formatter itself, not a lib-specific issue — the exact same
  corruption pattern was found and fixed in 2 other files in *this* lib
  (`inherit/item/task.lpc`'s `::move`, `kungfu/class/huashan/yue-wife.lpc`'s
  `::recruit_apprentice`) plus 2 `return (::FUNC(...))`-shaped variants
  (`kungfu/skill/{biyun-xinfa,sanku-shengong}.lpc`'s `::valid_learn`,
  `d/fuzhou/mishi.lpc`'s `::valid_leave`), and independently in 5 sibling
  libs in this same pass (`xlqy_early`/`xlqy_new2007`'s shared
  `d/sky/xitian.lpc`, `xo_final`'s `system/daemon/user.lpc`, 4 files in
  `xuanjianlu`, `yanhuangyingxiongshi`'s own copies of this lib's 2
  `combined.lpc`/`yue-wife.lpc` bugs, and 18 files in
  `yanlongfengyin_xiaoao3`). Fixed all 6 instances in this lib by hand
  (restored the original `::FUNC(...)` call and matching brace structure,
  verified byte-for-byte against the pre-format git blob to make sure the
  original control flow — e.g. `combined.lpc`'s `return 1` staying
  *inside* the `if (::move(...))` block, not hoisted out — was preserved
  exactly), then re-ran the formatter over just those files, which now
  formats them correctly (confirms the bug is specifically the
  line-wrapped variant, not `::` in general). Verified all 3 files
  compile clean via `lpcc`. **Worth reporting upstream to whoever owns
  `tools/lpc-syntax`** — this is a real, if narrow, formatter
  regression risk for any `::`-heavy mudlib, not specific to this batch.
- **Native retest**: rebuilt `~/src/fluffos/build-debug/src/driver`
  booted clean after the formatter-bug fixes above (zero fatal
  `debug.log` errors). Full registration re-verified with a real
  Chinese name (秦岭, id `qinlingnew` to dodge a stale same-session name
  collision from an earlier throwaway attempt): id/confirm/surname/
  given-name/admin-password/password/type/gender all completed, landed
  in 世外桃源 exactly as the original pass found; `look` correctly
  re-displayed the room, `quit` gave the correct farewell. Zero real
  debug.log errors.
- **WASM**: booted with the expected non-fatal `socket_*`/"Undefined
  function" preload noise (missing `sockets` package). **Found a real,
  reproducible WASM-specific registration blocker**: `adm/daemons/
  logind.lpc`'s `logon()` calls `!VERSION_D->is_version_ok()` directly
  (uncaught — unlike the immediately-preceding `catch(MUDLIST_CMD->
  main())` on the line above) as part of printing the login banner,
  *before* the username prompt. Since `adm/daemons/versiond.lpc` uses
  `socket_create`/`socket_bind`/`socket_listen` and fails to compile
  entirely under this WASM build (no `sockets` package), calling
  `VERSION_D->is_version_ok()` throws "*No program in object" — and
  because this call is unguarded, the error aborts `logon()` entirely
  right there, so **the username prompt itself never appears** and
  registration cannot proceed at all under WASM. Confirmed reproducible
  across multiple attempts/timeouts (60s+); confirmed this is NOT
  present natively (versiond compiles fine there, full playthrough
  above was clean). This is a different (and more severe) manifestation
  of the same documented "no sockets package under WASM" restriction —
  not a mudlib bug (native is completely unaffected) and not the
  `query_ip_number()` limitation either. **Not patched** (would require
  either adding a `catch()` around a call the mudlib author didn't
  guard, or a driver-level sockets stub, both out of scope for this
  smoke-test pass) — documented here and in the README as "does not
  boot into registration under WASM" rather than "playable."
  **UPDATE (WASM-enablement pass): now patched** — see next section;
  both VERSION_D call sites are `find_object()`-guarded per the new
  §1.3c policy, which should unblock WASM registration (needs a WASM
  re-test to confirm).

## WASM-enablement pass (loopback-allow / gate bypass / admin seed)

Standard WASM-first pass per AGENTS.md §1.3b/c/e and §1.5. Gates
patched:

- `adm/daemons/band.lpc` `is_banned()` (~line 38) — loopback / empty /
  malformed-IP short-circuit `return 0;` at the top.
- `adm/daemons/logind.lpc` — added `is_loopback_conn(object)` helper,
  and:
  - `logon()` `BAN_D->is_banned()` gate (~line 75) — loopback exempt.
  - `logon()` same-IP multi-login cap (`iplimit > 9`, ~line 106) —
    loopback exempt.
  - **the WASM registration blocker**: both unguarded
    `VERSION_D->is_version_ok()` call sites (banner ~line 87, get_id
    hard gate ~line 161) now guarded with `find_object(VERSION_D)` —
    daemon absent (as under WASM, where versiond's sockets usage keeps
    it from compiling) ⇒ notice/gate skipped. This was the documented
    "no id prompt under WASM" hard blocker.
  - No `uptime()` startup-grace gate or registration-rate throttle in
    this lineage's logind (MAX_USERS capacity cap left intact).

Admin account seeded: id `fluffos`, 普通密码(login pw) `Mud@2026`,
管理密码(recovery pw) `Admin2026`, display name 浮浮 (surname prompt
skipped with bare ENTER — the lineage's surname+given-name split flow
rejects 姓=名, so "浮"+"浮" does NOT work; skip the surname instead).
Granted `(admin)` via `fluffos (admin)` appended to `adm/etc/wizlist`.
Verified: real registration flow end-to-end into 世外桃源, relogin →
`update /adm/daemons/band` → 成功 (`score` correctly says 还没有出生
until the newbie quality-selection is done — game design). Retest:
fresh normal registration (姓 秦 名 风, f) end-to-end, look/quit
correct; test char saves removed; zero new debug.log errors.

**Save files for the orchestrator to add** (none gitignored, normal
add):
- `libs/yanhuangwuhun/work/data/user/f/fluffos.o`
- `libs/yanhuangwuhun/work/data/login/f/fluffos.o`


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
