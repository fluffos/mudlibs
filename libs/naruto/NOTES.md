# naruto — 獵火影忍者人 / "Naruto X Hunter" (ES2/Neolith lineage)

Source: `git clone https://github.com/MudRen/mudos-game-naruto` (commit
`000f286645e810e1cd786130c52d7b9c1747cae8`, cloned 2026-08-26). Slug
`naruto`, number 933, port 40235 (932/40234 were picked first but
collided live with a concurrent session's `nightmare4` onboarding;
reassigned before first boot). GitHub self-describes the repo as
"source code of Naruto X Hunter mud"; a sibling repo `MudRen/Naruto`
(no relation confirmed below) was a tiny, effectively-empty stub and
not the archive used here.

## Relationship to the already-onboarded `huoying` — read before assuming duplicate

**This is the same base engine as `huoying`, not the same game.**
`huoying`'s `adm/obj/master.c`/`.lpc` is byte-identical in structure to
this archive's (same copyright header, same `connect(int port)`
`MUD_PORT`/`HTTP_PORT` switch, same function bodies — diffed directly,
confirmed) — both trace to the same "Neolith 0.0.2" / ES2 (Annihilator)
Naruto-reskin bootstrap template, and huoying's own NOTES.md already
documents the identical hardcoded-`MUD_PORT` bug class this archive
also has. But content-wise they are not comparable: `huoying`'s
`world/area/` contains exactly one subdirectory (`wizard`, the bare
template's own test room, no built-out game world at all — its own
archive was sourced from a `Naruto.rar` distribution, presumably an
early/minimal snapshot), while this archive has ~20 fully-built domains
(`muye`, `sand_hole`, `four_wheel_tower`, `god_forest`, `whale_island`,
etc.) plus a large multi-wizard `u/` personal-build tree, and — per its
own GitHub description and its own in-game login banners/system
announcements (see below) — has evolved into an explicit crossover with
a *second* anime franchise (Hunter × Hunter), not just a bigger Naruto
game. Treated as a legitimate, independently-developed sibling in the
same spirit as this collection's existing `zhyx`/`yanhuangwuhun`/
`demonangel`/`es2`/`haiyang2` ES2-family cluster (shared engine
ancestry, explicitly cross-referenced, but each with its own
substantively distinct game world) — **not** marked `duplicate_of`
`huoying`. Flagging this relationship explicitly per this project's own
convention for shared-lineage siblings, and because the evidence (a
byte-identical shared boilerplate file, literally overlapping
"火影"/Naruto branding) is unusually strong compared to the typical
"shared framework, independently diverged" case.

The game's own branding is genuinely dual/crossover, not just
Naruto-themed: the login sequence displays two separate ANSI-art
banners in sequence (one captioned "Hunter X Hunter", one captioned
"火影忍者"), the repo ships both `hunter_welcome.jpg` and
`naruto_welcome.jpg` screenshots, an in-game system announcement reads
"獵火影忍者人(NaHu) 重大公告" (literally 獵人 "Hunter" + 火影忍者
"Naruto" + 人 "person", stitched into one portmanteau with an explicit
"NaHu" abbreviation), and the daemon/class + daemon/skill trees contain
parallel `daemon/class/naruto/*` (ninjutsu) and `daemon/class/hxh/*`
(Hunter license classes, with Hunter x Hunter's six Nen categories —
放出/操作/変化/特質/具現化/強化 — implemented as real skill
categories, e.g. `skill:emit` for 放出系). This dual branding/content
is original to the archive, not something introduced by this porting
pass.

## Encoding

`file(1)` initially misidentified the raw archive as ISO-8859 text with
occasional escape sequences; decoding a sample string with both GB18030
and BIG5 and eyeballing a `write("...")` literal (`naruto.conf`'s own
`name : 火影` line) confirmed **BIG5** (Traditional Chinese, Taiwan
origin), not the mainland GBK/GB18030 default this collection's other
archives mostly use.

`scripts/convert_lib.sh libs/naruto/raw/naruto libs/naruto/work BIG5`:
`already_utf8=262 converted=4168 lossy=22 skipped_binary=20`; renamed
2,895 files to `.lpc`; fixed 2,653 literal `.c"` references; converted
1 local angle-bracket include to quotes; `static`→`nosave` touched 15
files.

- **`static`→`nosave` string-literal collision** (AGENTS.md §4.3,
  same class already documented for `demonangel`/`es2`/`zhyx`): all 18
  hits were `log_file("static/...")` path literals (`master.lpc`'s
  `"static/CRASHES"`, plus `"static/OUTWARD"`, `"static/GIVE"`,
  `"static/PURGE"`, `"static/CLONE"`, `"static/promotion"`,
  `"static/OKIP"`, `"static/RESTORE"`, `"static/SUICIDE"`,
  `"static/CHPASS"`, `"static/CALL_PLAYER"`, `"static/UPDATE"`,
  `"static/SUMMON"`, one commented-out `"static/DROP"`) — confirmed a
  real `log/static/` directory exists in the raw archive; reverted all
  18 back to `"static/...`.  No `#define nosave static` shim collision
  found (`include/globals.h` only has a harmless `#define nosave
  nosave` self-definition).
- **Two extension-based-scan stragglers `file(1)` misclassified as
  binary**, found via a full-tree UTF-8-decode walk beyond
  `convert_lib.sh`'s own coverage:
  - `doc/help/class/hunter/skill/variation/variation` (52 bytes) —
    `file(1)` reported "OpenPGP Secret Key" purely because its first
    byte happened to match that format's tag byte (the claimed
    packet length, 7524, wildly exceeds the actual 52-byte file size,
    confirming the false positive); actual content is a two-line BIG5
    help-text snippet ("變化系程度 (variation)"). Converted with
    `iconv -f BIG5 -t UTF-8`.
  - `u/r/roger/book` — genuinely binary (a directory-listing-style
    dump embedding filenames like `e100-ar1.c`), zero references
    anywhere in the tree by that name; a personal wizard's orphaned
    scratch file. Left as-is, matching this project's standard
    "genuine binary, correctly left alone" handling.
- Both `.gitignore`/`.DS_Store` artifacts (macOS metadata, present in
  several subdirectories of the raw archive) were deleted from `work/`
  before the compile sweep.

## Fixes applied (driver-incompatibility bugs)

- **§5.3-class: hardcoded `MUD_PORT` in `master.lpc`'s `connect()`
  dispatch** — `include/globals.h` had `#define MUD_PORT 8000` (the
  archive's original port), but `adm/obj/master.lpc`'s `connect(int
  port)` `switch`es on the literal incoming port with no `default`
  case, so every real connection to this lib's assigned port (40235)
  fell through the switch with nothing returned. Boots clean, banner
  prints, `Accepting telnet connections` line appears — but every real
  client immediately got `Can not accept connection from ... due to
  error in connect().` with zero LPC-level error. **This exact bug
  class, with this exact fix, is already documented in the
  already-onboarded `huoying`'s own NOTES.md** (same engine lineage —
  see above). Fixed identically: `#define MUD_PORT 40235` (updated
  again to 40235 after the port was reassigned from an initial
  40234/932 that collided with a concurrent session).
- **§15w-class: `master.lpc`'s `log_error()` checked for capitalized
  `"Warning"`, this driver emits lowercase `"warning:"`** — identical
  bug and identical fix to the one already documented in this
  collection's `zhyx` (a different, unrelated ES2/yh2003-family lib)
  and independently in `huoying` (same lineage as this lib). Every
  ordinary compile warning from every lazily-loaded file (e.g. a
  routine "Unused local variable" — extremely common throughout this
  archive) was broadcast to whichever player happened to be connected:
  the garbled ANSI-punctuation line `！·#￥%……—*（` for a regular
  player (from `master.lpc`'s own literal fallback string), or
  `#ERROR：<message>` for a wizard. Confirmed live and very
  reproducible before the fix — a single fresh registration showed the
  garbled line repeatedly (once per lazily-compiled dependency with any
  warning) — and confirmed gone (0 occurrences across 3 independent
  fresh-registration test runs) after. Fixed by matching both cases:
  ```lpc
  if (strsrch(message, "Warning") == -1 && strsrch(message, "warning") == -1)
  ```
- **Corrupted historical save data, stray-backslash class (same shape
  as `demonangel`'s "马厩\" typo, but in shipped *data*, not source)**
  — `data/chinese.o` (the live, preloaded `adm/daemons/chinesed.lpc`'s
  entire English↔Chinese translation dictionary, restored via
  `restore_object(file, 1)` on every boot) failed with
  `*restore_object(): Illegal mapping format while restoring dict.`
  every single boot, silently leaving the whole in-game translation
  feature permanently empty (caught by `master.lpc`'s own `preload()`
  `catch()`, so non-fatal but invisible unless you check
  `log/preload.log`). Root-caused by embedding the save file's one
  `dict (["..."])` line into a throwaway test `.lpc` file and compiling
  it with `lpcc` directly (far more precise than reasoning about
  `restore_object()`'s own generic error text) — found a genuine
  syntax error, not just a suspicious control byte: one dictionary
  entry, `"outfit kick":"踢技全餐\","anemometer":"風速計"`, has a
  stray backslash immediately before what should have been the value
  string's closing quote (`踢技全餐\"` instead of `踢技全餐"`), which
  escapes past the intended closing quote and swallows the rest of the
  mapping literal into one string until the next real unescaped quote.
  Fixed by removing the stray backslash directly in the shipped
  `data/chinese.o`; re-verified restore succeeds cleanly (confirmed via
  the same throwaway-test-file technique, then via a real boot showing
  an empty `log/preload.log`).
- **The identical stray-backslash-before-closing-quote typo, repeated
  independently across 9 more source files** — found by grepping the
  whole tree for `\",` after the `chinese.o` diagnosis above suggested
  it might not be a one-off. 2 of the 11 total hits found this way
  turned out to be unrelated, correctly-escaped `\"` sequences inside
  ordinary strings (`obj/roommaker.lpc`, `adm/daemons/buildingd.lpc` —
  both compile fine, left untouched). The other 9 are genuine hard
  compile failures, all fixed by removing the stray backslash:
  - `world/area/four_wheel_tower/npc/fire_sk.h` (a **shared** combat
    message string, `message_vision(sprintf("...龜派氣功\"NOR"...`,
    `\"` immediately before what should be the closing quote of a
    string-macro-string concatenation chain) — this single header is
    `#include`d by **10** NPC files (`monkey1/2/3`, `kingkong1/2/3`,
    `ape1/2/3`, `baboon3`), all 10 of which failed to compile until
    this one shared fix.
  - `world/area/muye/npc/nightkid.lpc` (5 instances in one acupoint-name
    array literal — `"腎俞\"`, `"肺俞\"`, `"心俞\"`, `"氣海俞\"`,
    `"厥陰俞\"`).
  - `world/area/sand_hole/npc/doctor.lpc` (`"阿蓋\"`), `world/eq/leg/gai.lpc`
    (`set_name(HIG"阿蓋\"NOR, ...)` — a real, reachable equipment item,
    not personal-sandbox content).
  - 6 further `daemon/skill/piece/martial/*.lpc` files
    (`gun_finger`, `gun_ten`, `gun_gentian`, `animal_yan`,
    `briar_suffuse`, `gun_ban`, `gun_whip` — all sharing one
    copy-pasted `"膝蓋\", "膝部", ...` body-part-list literal).
  - `u/r/roger/work_q/wwizall.lpc` (a slightly different shape: not a
    missing backslash-escape but a misplaced closing quote —
    `set_name("【"HIR"神化"HIW"卷軸"NOR"】, ({ "book"...` was missing
    the `"` that should have closed the string right after `】`, so
    the string swallowed the following `, ({ ` and the bare identifier
    `book` broke the syntax on the next token; fixed by adding the
    missing `"` in the right place: `"】", ({ "book"...`).
  - `u/s/savior/board/savior.lpc`: unrelated one-off typo found in the
    same investigation pass — `inherit BULLETIN_BOARD` missing its
    terminating semicolon. Added it.
- **Unguarded `load_object(0)` in `logind.lpc`'s `enter_world()`** —
  `err = catch(room=load_object(user->query("startroom")))` passes
  whatever `query("startroom")` returns straight to `load_object()`
  with no type check; for a brand-new character (unset `startroom`/
  `recoverroom` properties — always the case on first login) this is a
  bare `int 0`, and this driver throws `*Bad argument 1 to
  find_object() Expected: string Got: 0` instead of MudOS's more
  tolerant nil-coercion. The `catch()` already present meant this
  never blocked login in practice (the very next fallback,
  `load_object(START_ROOM)`, always succeeds and the character lands
  correctly — confirmed live, `look` always showed the correct
  starting room even before this fix) — but it silently wrote 1-2
  runtime-error entries to `log/catch_error` on **every single new
  registration**, an "MudOS tolerated a nil call/load, this driver
  enforces strict typing" case matching the class already catalogued
  for the ES2 family elsewhere in this collection (e.g. `demonangel`'s
  `carry_object()`/`move()` fixes). Fixed by guarding both call sites
  with `stringp()`:
  ```lpc
  room = 0;
  if( stringp(user->query("startroom")) )
      err = catch(room=load_object(user->query("startroom")));
  ...
  room = 0;
  if( stringp(user->query("recoverroom")) )
      err = catch(room = load_object(user->query("recoverroom")));
  ```
  Verified: `log/catch_error` is empty after a fresh registration,
  where it previously always had these two entries.
- **`feature/save.lpc`'s shared `restore()` mixin left
  `restore_object()` uncaught** — this one function backs `restore()`
  for essentially every persistent class in the archive (daemons,
  areas, bulletin boards, etc., via `inherit F_SAVE`). The overwhelming
  majority of shipped saves restore cleanly (confirmed: the
  `chinese.o` fix above was the only *dictionary-class* corruption
  found), but at least two old bulletin-board saves are corrupted in a
  way that isn't a simple stray-backslash typo and wasn't chased down
  line-by-line (they're large files of genuine multi-year, multi-line
  **real historical player post content**, not something to
  hand-edit/guess-fix per this project's "don't invent or restore
  content" boundary — see AGENTS.md §7.7's identical `jyqxc` precedent
  for "reformatting legacy corrupted saves is out of scope, fix the
  code path instead"): `data/board/propose.o` (`*restore_object():
  Illegal mapping format while restoring dbase.`) and
  `data/board/bug.o` (`*restore_object(): Invalid utf8 string while
  restoring dbase.`). Confirmed live: a wandering wizard-homage NPC
  (`world/area/wizard/npc/luky`/`annihilator`, both on the
  preloaded-area's own random-walk AI) stepping into
  `world/area/wizard/{propose,bug}` triggers each room's own
  `create()` → its bulletin board's `create()` → `setup()` →
  `restore()`, hard-erroring `create()` uncaught before this fix (the
  room/board object simply fails to finish loading — this is also why
  both `/world/area/wizard/bug` and `/world/area/wizard/propose`
  appeared as bare, textless `lpcc_check.sh` "Fail to load object"
  failures with no visible error text: `lpcc`'s per-target invocation
  doesn't surface uncaught *runtime* create() errors as diagnostic
  text the way it does compile-time syntax errors). Fixed at the
  shared mixin, benefiting every caller uniformly (same "fix once at
  the shared utility" shape as `demonangel`'s `feature/move.lpc` catch()
  fix):
  ```lpc
  int restore()
  {
      string file;
      mixed err;
      int ret;
      seteuid(getuid());
      if( stringp(file = this_object()->query_save_file()) ) {
          err = catch(ret = restore_object(file, 1));
          if( err ) return 0;
          return ret;
      }
      return 0;
  }
  ```
  Verified live: both boards' rooms now load without error; the two
  still-corrupt saves surface as caught, properly-logged
  `log/catch_error` entries (routed through `master.lpc`'s real
  `error_handler()` apply) instead of aborting anything. The
  underlying board *content* remains genuinely corrupted/unreadable
  (both boards effectively start empty) — a pre-existing data
  integrity gap, not something restored.

## Confirmed NOT needed / pre-existing content, not fixed

- **`daemon/class/naruto/assassin.lpc`, `daemon/condition/hair_cd.lpc`,
  `daemon/condition/rain.lpc`** — each fails to load with a generic,
  textless `lpcc_check.sh` "Fail to load object" (same
  runtime-error-not-surfaced-by-lpcc limitation noted above). Root
  cause, found by reading `adm/daemons/daemond.lpc`'s
  `register_class_daemon()`/`register_condition_daemon()`: each throws
  a real `error("DAEMON_D: registration conflict, and access
  denied.\n")` when a file registers a class/condition name that the
  daemon's own saved registry (`data/daemon.o`) already maps to a
  *different* file. Checked `data/daemon.o` directly: `"class:assassin"`
  is registered to `/daemon/class/naruto/police` (not `assassin`),
  `"condition:hair_cd"` to `/daemon/condition/hundred_cd`, and
  `"condition:rain"` to `/daemon/condition/elf` — all three of *these*
  specific files are confirmed-orphaned duplicates/superseded drafts
  (zero references anywhere else in the tree by their own path), not
  the live, currently-registered owner of that class/condition name.
  Genuine pre-existing content state (an old renamed/duplicated
  skill-class file left behind), not a driver-compat bug — not fixed.
- **The remaining ~45 `lpcc_check.sh` failures** are entirely personal
  wizard sandbox content under `u/` (`byron`, `savior/area/abaddon`,
  `york`, `mouse` — by far the largest cluster, `roger`, `hitomi`,
  `alickyuen`, `acme`, `flying`) plus 2 plain-text `doc/wiz/{ref,concepts}/
  lpc` files that `convert_lib.sh`'s extension-based rename swept up
  (Usenet-post-style prose, not real LPC source, same class as
  `demonangel`'s identical `doc/ref/lpc.lpc` finding). Spot-checked
  several: some are genuinely broken/incomplete personal drafts
  (`u/b/byron/skyclub/area01.lpc` ends mid-statement with a bare stray
  `x` token — an unfinished edit, not something to guess-complete;
  `u/m/mouse/shadow/copy.lpc` calls `::evade()` against a parent that
  never defines `evade()`; `u/m/mouse/lv60/npc.lpc` references an
  undefined `do_fight` in a closure), others are simply unreferenced by
  anything else in the tree (`u/m/mouse/bone/marsh.lpc` — confirmed via
  `grep -rl`). None of the 48 remaining failures are reachable from the
  registration/gameplay path exercised below.

## Network / outbound-connections check (AGENTS.md caveat)

Two real socket-touching subsystems exist in this archive:
`adm/intermud/i2d.lpc` (a full Intermud-2 UDP service — `create()`
immediately does `socket_create(DATAGRAM, ...)` +
`socket_bind()` + `resolve()`) and `adm/daemons/userid.lpc` (a
port-113 ident-lookup client). **Neither is preloaded**
(`adm/etc/preload` has no `i2d`/`userid`/`dns_master` entry — the
archive doesn't even ship a `dns_master.lpc`), and grepping every
caller: `i2d.lpc`'s only non-`adm/intermud/`-internal caller is
`cmds/wiz/mudlist.lpc` (an explicit wizard-only command); `userid.lpc`'s
only two call sites, both in `logind.lpc`'s `enter_world()`, are
**commented out** (`// IDENT_D->query_userid(...)`) — confirmed dead on
the actual login path (a `cmds/wiz/userid.lpc` wizard command is the
only live caller). This lib makes **zero outbound network connections**
during boot or during the full registration/gameplay test below; safe
for an automated reboot loop.

## Boot / registration verification

- `~/src/fluffos/build-debug/src/lpcc`, single-file, confirmed clean on
  all core base classes before ever running a full batch sweep (per
  this project's RAM-safety discipline): `adm/obj/master`,
  `adm/obj/simul_efun`, and a scoped `--batch` run over all 74
  `std/*.lpc` + `feature/*.lpc` files — 74/74 passed (peak RSS
  14MB, ~1s).
- Full `lpcc_check.sh` batch sweep (all 2,895 objects): peaked around
  ~670MB RSS (well under the 10GB safety threshold), completed in well
  under a minute. First pass: 2,828/2,895 (97.7%) before any fixes.
  After applying all fixes above: **2,847/2,895 = 98.3%** pass, 48
  failures remaining, all confirmed personal-sandbox/dead-content per
  the section above.
- Real `build-debug` driver boot on port 40235: clean, `Accepting
  telnet connections` banner, zero fatal `debug.log` errors (only
  benign compile warnings, correctly routed to `log/log` after the
  `log_error()` fix, never shown to a connecting player).
- Full registration flow verified via raw socket scripts
  (`scripts/mudclient.py`), multiple independent runs with real
  Chinese names (`qinfeng`/秦風, `qinfengb`/秦楓, `qinfengc`/秦雪,
  `fluffos`/浮浮): English id (3-10 letters only — digits rejected
  with a clear message) → confirm new character (y/n) → password
  (entered twice) → email address → gender (m/f) → Chinese display
  name → lands in 巫師神殿 ("Wizard's Temple",
  `/world/area/wizard/guildhall`, populated by several
  homage/lineage NPCs including 天朝帝國 阿奈雷特(Annihilator), the
  original ES2 author). `look` correctly re-displays the room; `score`
  shows a fully populated character sheet (level/age/race/gender, six
  attributes, HP/MP/energy bars, an ASCII equipment-slot diagram);
  `who` shows the correct player-list table; `say` produces the
  correct self-echo; `whoami` shows the correct UID/EUID; relogin
  (restore path) works cleanly with no re-registration prompt; `quit`
  produces a clean "歡迎下次再來！" every time. **Zero occurrences**
  of the garbled `！·#￥%……—*（` line and **empty** `log/catch_error`
  across the final verification runs (both were reliably present/
  non-empty on every run before the `log_error()` and `load_object(0)`
  fixes above).
- Admin account seeded: id `fluffos`, password `Mud@2026`, display
  name 浮浮 (title shown in-game: 天尊). Granted `(admin)` via this
  lineage's own mechanism (identical to `huoying`/`demonangel`/`zhyx`):
  appended `fluffos (admin)` to `adm/etc/wizlist` (plain `<euid>
  (status)` text format) alongside the pre-existing `mudren (admin)`
  entry. Verified: `fluffos`/`Mud@2026` login succeeds, `look` shows
  the wizard-only room-path suffix (`/world/area/wizard/guildhall`),
  `update /adm/obj/master` succeeds ("master: loaded successfully.
  重新編譯 /adm/obj/master.lpc ... 成功。") — the canonical
  read+compile ACL check per AGENTS.md §1.5.
- Save files for the orchestrator to add (not gitignored, normal add):
  `libs/naruto/work/data/login/f/fluffos.o`,
  `libs/naruto/work/data/user/f/fluffos.o`. All other test characters'
  save data (`qinfeng`, `qinfengb`, `qinfengc`) was deleted before
  finishing, per convention.

## Not run this session

- **LPC formatter (§9)**: not run — every edit this session was small
  (a handful of lines each: one macro constant, one string-literal
  backslash removal repeated across a handful of files, one shared
  mixin's `catch()` guard) and manually reviewed against the
  surrounding code's existing style rather than auto-formatted.
- **Full deep §10.7-style playthrough / WASM pass**: out of scope for
  this onboarding session per the task brief (native boot +
  registration verification only).
