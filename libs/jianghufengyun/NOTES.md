# jianghufengyun — 江湖风云

Archive: `江湖风云.rar` (#59, byte-identical duplicate: `江湖风云 (1).rar`,
already listed in AGENTS.md's Duplicate archives table — only this one
processed; confirmed via `md5sum` before extracting,
`5607c63bab7ebe67dd44896b145ccda7` for both). Port: **40053**. Status:
**done** (boots clean, full registration flow verified end-to-end three
times across two driver sessions, with three different real Chinese names,
all reaching the actual game world).

## What this is

The archive extracts to `raw/Jhfy/`, a Windows MudOS 0.9.20 bundle
(`mudos.exe`, `mudos.dll`, `mud.log`) with the actual mudlib root at
`Jhfy/world/` (confirmed via `Jhfy/config.jh`'s `mudlib directory : ./world`
/ `master file : /adm/obj/master` directives — the archive's own config
file, not a guess). `config.jh`'s `name` field decodes (GB18030→UTF-8) to
**"江湖风云单机"** ("Jianghu Fengyun — standalone/single-player build"),
matching the archive's own filename — no slug rename needed, `jianghufengyun`
is a direct, accurate transliteration. ~8,979 raw files, 8,071 `.lpc` after
the rename — a mid-sized lib for this batch.

Layout: `adm/{daemons,obj,simul_efun,etc,tmp}` (not `adm/single/`).

### Lineage: a genuine third fork of the 夕阳再现 ("Sunset Reappears") family

The task brief flagged that two already-done libs in this repo —
`xiyangzaixian_fengkuang` (#46, 夕阳再现-疯狂江湖.rar) and
`weimingkongjian` (#55, 未明空间.rar, live banner "江湖风云之夕阳再现") —
both show a "江湖风云" name somewhere. Checked via `md5sum` on the three
core files, per AGENTS.md's standing "verify via diff, never assume from
title alone" rule, **before** doing anything else:

| file | jianghufengyun | xiyangzaixian_fengkuang (#46) | weimingkongjian (#55) |
|---|---|---|---|
| `adm/simul_efun/chinese.c` | `961d77af...` | `961d77af...` (**same**) | `961d77af...` (**same**) |
| `adm/obj/master.c` | `8841d611...` | `861c587c...` (different) | `8841d611...` (**same**) |
| `adm/daemons/securityd.c` | `d1bd5477...` | `d1bd5477...` (**same**) | `a33cb521...` (different) |
| `adm/daemons/logind.c` | `24ef0ce8...` | `dbc4a7af...` (different) | `efd6e03e...` (different) |

This is a genuine three-way shared lineage, not a coincidence of title: this
lib's `chinese.c` is byte-identical to BOTH #46 and #55; its `master.c` is
byte-identical to #55's; its `securityd.c` is byte-identical to #46's; only
`logind.c` (and the room/world content) is independently maintained in each
fork. This lib's own `logind.lpc` banner literally reads **"夕阳再现" / 之 /
「江湖风云」** — i.e. this archive is very plausibly close to (or is) the
actual upstream "夕阳再现之江湖风云" build that both #46 and #55 forked
from/around, given it shares the *most* files (2 of 3 core files matched,
vs. 1 of 3 for each of the other two). Confirmed further during the lpcc
sweep: `d/quanzhen*/hudi{4,5,6}.lpc`, `d/player/fyue_room.lpc`, and several
`u/fyue/huashan/*` files are the exact same room content (same filenames,
same pre-existing typos) already documented in `weimingkongjian`'s NOTES.md
— genuine shared world-content, not independently authored.

**All of #46's and #55's proven fixes were ported/re-verified directly
against this lib's actual source** rather than rediscovered from scratch,
per the task brief's instruction — see below for exactly which applied,
which didn't, and how each was confirmed.

## Fixes applied

1. **AGENTS.md §15h** (standard shape, ported from #46/#55 — verified this
   lib's `chinese.c` is the identical file, so the identical fix applies):
   `adm/simul_efun/chinese.lpc`'s `is_chinese()` — GBK lead-byte range check
   (`strlen(str)>=2 && str[0]>160 && str[0]<255`) rewritten to a CJK
   Unicode codepoint check (`strlen(str)>=1 && str[0]>=0x4e00 &&
   str[0]<=0x9fff`).
2. **AGENTS.md §15h**, `check_legal_name()` in `adm/daemons/logind.lpc`
   (this lib, like #55, has no separate `named.lpc` — `check_legal_name`
   is defined directly in `logind.lpc`, and its shape is NOT byte-identical
   to #55's copy since `logind.c` is one of the files that differs across
   this family — read and fixed independently, not blind-ported):
   - Byte-count bound `strlen(name) < 2 || > 10` → character-count bound
     `< 1 || > 5` (message text "必须是 1 到 5 个中文字" already stated the
     correct intended character count).
   - Sliding check `i%2==0 && !is_chinese(name[i..<0])` (alternating
     GBK-lead-byte offsets, variable-length tail slice) → `!is_chinese(name[i..i])`
     on every index (one whole character per index under UTF-8).
3. **AGENTS.md §15p**: `adm/etc/preload` had
   `/adm/daemons/network/dns_master` live — commented out proactively
   before the first boot attempt (CRLF-terminated file, edited carefully to
   preserve line endings elsewhere).

## Confirmed NOT needed (verified by reading source directly, not assumed)

- **§4** (master.lpc `load_object()`-during-compile recursion in
  `valid_read`/`valid_write`): read the full `master.c` before the first
  boot — both applies only ever call `find_object(SECURITY_D)`, never
  `load_object()`. No lazy-load recursion possible.
- **§7** (missing `get_root_uid()`/`get_bb_uid()`): both present and
  correct (`return ROOT_UID;` / `return BACKBONE_UID;`).
- **§15l** (master.lpc `create()` destructing `SIMUL_EFUN_OB`): this lib's
  `master.lpc create()` is a single `write()` line, nothing else.
- **§15 / nitan-family shared-simul_efun dbase architecture bug**:
  `feature/dbase.lpc` implements real local `set`/`query`/`delete`/`add`
  (+ `_temp` variants) as genuine functions (inherited via `F_TREEMAP`),
  and the simul_efun fragment `adm/simul_efun/wizard.lpc` defines only
  `wizhood()`/`wiz_level()` — no bare `set`/`query`/`delete` simul_efuns at
  all. Confirmed architecturally correct (same family as `rzrmud`/
  `weimingkongjian`), not the bug.
- **§15b family** (`addn`, `remove_ansi`, `noansi_strlen`, `B2G`,
  `db_affected`, `clr_ansi`, `changed_match_path`, `query_bandwide`,
  `query_shadowed`, `tail()`): grepped the whole lib for each — zero hits
  except `remove_ansi`, which IS locally defined (not a simul_efun gap) in
  both files that call it (`u/fyue/score1.lpc`, `cmds/wiz/score1.lpc`).
  `message_combatd` (a real gap in #55) is only referenced from **commented-out**
  code here (`kungfu/skill/{yuxiao-jianfa/tianwai,tiangang-zhi/lingkong}.lpc`)
  — confirmed dead, not a live call site, so not fixed.
- **§14** (2-arg `valid_override`): this lib's `master.lpc` has the old
  2-arg signature. Checked every `#include`d simul_efun fragment (`atoi`,
  `chinese`, `gender`, `object`, `path`, `wizard`, `message`, `file`) for an
  `efun::destruct`/`efun::move_object` override written inside a fragment
  — the only `efun::destruct` override in the whole composition is in
  `adm/obj/simul_efun.lpc` itself (the real `SIMUL_EFUN_OB`, which already
  passes the existing check's `file == SIMUL_EFUN_OB` branch). Gap is real
  but provably unreachable; left as-is (matches #55's identical finding).
- **§15n/§15o custom-securityd func-discrimination gap**: `securityd.lpc`
  (byte-identical to #46's) IS a genuinely custom ACL (`trusted_read`/
  `exclude_read` mappings keyed by directory + wizard-status), but its
  `valid_read` already has the same escape hatch documented safe in #55:
  `if (!sscanf(base_name(user),"/clone/user/%*s") &&
  author_file(base_name(user))==ROOT_UID) return 1;` — any read attributed
  to a ROOT-owned system caller is allowed unconditionally. Confirmed no
  `Read access denied` anywhere across three full interactive test sessions'
  `debug.log`.
- **§8d/§15o `<local.h>`-next-to-its-user / mid-connection #include gap**:
  `convert_lib.sh`'s automated pass already converts every bare (no-slash)
  angle-bracket local include to quoted form (`converted 50 local
  angle-bracket includes to quotes` — logged during conversion), and quotes
  resolve against the including file's own directory **unconditionally**,
  with no VM-context dependency — meaning this class of bug is fixed at
  the mechanical-conversion stage, not something `master::get_include_path()`
  needs to paper over. Verified zero remaining bare `<x.h>`-with-no-slash
  includes anywhere in `work/` after conversion (`grep` came up empty), and
  zero absolute-path-in-angle-brackets (§15t item 1) or `..`-relative
  includes (§15t item 2) anywhere in the lib either. `master.lpc` has no
  `get_include_path()` apply and none was added — nothing in this lib
  needs it.
- **§8f** (`TYPE * name1, name2;` array-modifier-doesn't-propagate bug,
  Dead-Souls lineage): 107 lines matched the shape via grep; spot-checked
  3 (`feature/equip.lpc:9`'s `type`, `feature/alias.lpc:13`'s several,
  `kungfu/skill/kumu-shengong.lpc:11`'s `master`) — all genuinely used as
  plain scalars later in the same function, correctly-written C-style
  declarations. This bug class does not recur in this lineage (confirmed
  again, matching #55's identical finding); left unfixed.
- **§8e** (`tail()` non-efun): zero call sites (`grep -rn '\btail('`).
- **§15j** (per-IP registration throttle): grepped `adm/daemons/band.lpc`
  for `IsTimeAllowed`/`NewIps`-shaped anti-flood logic — not present; no
  throttle to interfere with repeated registration testing.

## Registration-flow verification (the critical check)

Read `adm/daemons/logind.lpc`'s full callback chain (`logon → get_id →
confirm_id → get_name/get_resp → new_password → confirm_password →
select_gift/set_gift/get_gift → get_email → get_gender →
init_new_player/enter_world`) before scripting any test. **No hidden pre-id
BIG5/student/client-version gate** — the very first prompt
("请输入您的英文名字：") really is `get_id`, gated only by `check_legal_id()`
(3-14 lowercase English letters **only** — no digits, confirmed the hard
way, see below) and a `banned_id` substring check (`admin`, `arch`,
`wizard`, `apprentice`, `immortal`, `player`, `fuck`) plus a literal
`"guest"` ban. A valid non-empty Chinese name is accepted **with no y/n
confirmation step** — straight into the password prompt.

**Gotcha hit and documented**: a first attempt used id `qinfeng2` (digit in
the English id) — `check_legal_id()` only allows `a`-`z`, so it was
rejected, and every subsequent scripted `--send` line landed on the
still-active "please re-enter your English name" prompt, cascading into a
confusing multi-line rejection sequence (exactly the class of gotcha
AGENTS.md warns about: re-verify with a clean id, don't assume the
Chinese-name fix is broken from a cascaded transcript). Confirmed by
re-running with an all-letters id.

**Test 1** (first successful full run) —
`python3 scripts/mudclient.py 127.0.0.1 40053 --timeout 30 --idle 2
--send "qinfengsan" --send "y" --send "秦风三" --send "test1234" --send
"test1234" --send "0" --send "y" --send "test@test.com" --send "m" --send
"look" --send "quit"`:
- `qinfengsan` accepted as new id → confirm prompt → `y` → Chinese-name
  prompt.
- **Real Chinese name "秦风三" (3 characters) accepted on the first try**
  (no rejection loop) → password set → gift selection (`0`=random,
  `y`=accept) → email accepted → gender `m` accepted → `init_new_player`/
  `enter_world` ran → landed in "客店" (Inn) room, one of the 4
  `start_room` entries → chat broadcast confirmed correctly-rendered
  Chinese: `听说又来了一位叫做秦风三的少年侠士`. `look` and `quit` both
  worked (dropped starting cloth/token items, printed "欢迎下次再来！").

**Test 2** (independent, after all content fixes below were applied and the
driver was restarted — LPC objects don't recompile from an on-disk edit
alone) — same script, id `linfeng` / name `林风` (2 characters), gender
`f`: accepted through the identical full chain, landed in a **different**
start room this time (`/d/xingxiu/beijiang`, "北疆小镇" / Northern Frontier
Town — confirming the `random(4)` start-room pick works), correct
gender-appropriate broadcast (`听说又来了一位叫做林风的小姑娘`), `look`/
`quit` both worked.

**Test 3** (final re-verification after ALL fixes, on a fresh driver
restart) — id `qinfengsi` / name `秦风四` (3 characters), gender `m`:
accepted immediately again, landed in "铁枪庙" (Iron Spear Temple) — a
third distinct start room — `quit` worked cleanly.

All three sessions' `debug.log` grep clean for `error`/`denied`/
`segmentation`/`Undefined function` beyond the two expected benign
boot-time echo lines (`mudlib error handler : 1`, a config-flag echo, not
an actual error) and the intentional live `log_error()`-to-player mechanism
surfacing harmless `Unknown #pragma, ignored` / `Unused local variable`
compiler warnings to whoever triggers a lazy compile (original mudlib
behavior, not a bug introduced here).

**Driver process management note**: the very first boot (launched via a
plain `nohup ... & disown` from a Bash tool call) was killed by an
unexplained external `SIGTERM` sometime between two tool-call turns, even
though `ps` confirmed it alive and had already served one full successful
test in between — strongly suggests the sandbox's per-tool-call process
group cleanup can reap a background process that isn't in its own session.
**Fix: launch with `setsid nohup ... & disown`** (own session id, `ps -o
pgid,sid` confirms `PGID==SID==PID`) — the driver then survived cleanly
across every subsequent tool call for the remainder of testing.

All driver processes were killed (`kill -TERM`) after each round of
testing; no driver process is left running on port 40053.

## lpcc_check.sh sweep

8,071 files. Host memory stayed healthy throughout (`free -h`: 3.7-4.2GB
free / ~3.6GB used out of 23GB at every check — nowhere near AGENTS.md
§6b's OOM-risk territory; other agents' concurrent conversions for
archives #58/#61 were also running on the same host at points during this
pass without issue).

| Pass | Result |
|---|---|
| 1 (pre-fix) | 7933 / 8071 = 98.3% |
| 2 (+ 20 file fixes, see below) | 7953 / 8071 = 98.5% |
| 3 (+ 8 more file fixes) | **7959 / 8071 = 98.6%** (final) |

### Content bugs found and fixed via the sweep (all pre-existing, confirmed
against raw pre-conversion bytes where relevant — not introduced by this
pipeline)

- **6 files, "closing heredoc tag merged onto the preceding text line"**
  (`@LONG ... LONG` needs `LONG` on its own line): `d/heimuya/npc/tang.lpc`,
  `d/heimuya/tang.lpc`, `d/quanzhen/manglin{1,2}.lpc`,
  `d/quanzhen_old/manglin{1,2}.lpc` — inserted the missing newline before
  the closing `LONG` tag. (First automated attempt via a blind regex also
  matched the *opening* `@LONG` tag and incorrectly split it into
  `@\nLONG`, breaking the heredoc start — caught and corrected before
  re-testing; a reminder that even a "safe-looking" regex bulk-fix across a
  handful of files needs a diff-check, per AGENTS.md §15t's own precedent.)
- **4 files, missing opening quote before a `set("long", <bare text>`
  block** (§10-shape, exact same room content as documented in
  `weimingkongjian`'s NOTES.md — same filenames, confirming shared world
  content): `d/quanzhen/hudi6.lpc`, `d/quanzhen_old/hudi{4,6}.lpc` (missing
  opening quote only), `d/quanzhen_old/hudi5.lpc` (missing **both** opening
  and closing quote/`\n`), `d/player/fyue_room.lpc` (missing opening quote
  and closing `\n"`).
- **1 file, invalid-GBK-lead-byte-eaten-adjacent-newline** (the `iconv -c`
  gotcha from AGENTS.md's Encoding section, confirmed via raw-byte
  inspection: `xxd` on the pre-conversion file shows a genuine invalid GBK
  lead byte `0xa3` immediately followed by a literal `0x0a` newline at the
  exact failure point): `d/heimuya/shenggu.lpc` — re-inserted the dropped
  newline before the closing `LONG` heredoc tag (the single fullwidth
  character that was consumed alongside the newline could not be
  recovered, but the sentence reads complete without it).
- **1 file, entire `do_out()`/`look_out()` function's string literals
  written completely unquoted** (identical shape to the exact bug already
  documented for `weimingkongjian`'s `d/city/sj.lpc` — same filename, same
  content): `d/city/sj.lpc` — quoted every literal, initialized the
  previously-declared-but-never-assigned `object me;` to `this_player()`
  (the function is bound via `add_action`, so that's the correct actor).
- **4 files, `#include __DIR_"feng.h"` typo** (missing the second
  underscore in `__DIR__`, an undefined token — same exact bug already
  documented for `weimingkongjian`): `d/wudang/taoyuan/tyroad{4,5,6,7}.lpc`
  — fixed to `#include "../feng.h"` (confirmed `feng.h` lives one directory
  up from `taoyuan/`, matching sibling rooms that already correctly
  `#include "feng.h"` from `d/wudang/` itself directly).
- **1 file, copy-paste inherit bug** (same exact bug already documented for
  `weimingkongjian`): `clone/weapon/panguanbi.lpc` (判官笔, "judge's
  writing-brush") did `inherit PEN; ... init_pen(25);` — `PEN`/`init_pen`
  don't exist anywhere in this archive. The file's own description
  ("这是一柄普通的精钢剑" — "an ordinary refined-steel **sword**") matches
  the `SWORD` template exactly. Fixed to `inherit SWORD; ...
  init_sword(25);`.
- **2 files, `set_name()` called with a bare string instead of an array**
  for the second (id-list) argument: `d/baituo/{obj,npc/obj}/bowl.lpc`
  (`set_name("海口大碗", "bowl")` → `set_name("海口大碗", ({ "bowl" }))`),
  confirmed against `feature/name.lpc`'s real signature
  (`void set_name(string name, string *id)`).
- **1 file, single-character typo breaking the very first line**:
  `d/quanzhen_old/obj/cloth.lpc` started with a literal `/ cloth.txt`
  (single slash, not `//`) — confirmed present in the raw pre-conversion
  bytes too (`xxd`), a genuine pre-existing typo, not a conversion
  artifact. Fixed to `// cloth.txt`.
- **4 files, shared root cause — a variable literally named `new`**
  (§8g-shape: identical `do_clone()`-style sect-succession function
  copy-pasted across multiple sect NPC files, all with the same bug):
  `object *inv, new;` collides with this driver's `new()` keyword/efun
  (`L_NEW` token), producing a cascade of "unexpected L_NEW"/"unexpected
  L_ASSIGN"/"unexpected L_ARROW" errors at every later use. Found in
  `d/quanzhou/npc/tang3.lpc`, `d/taishan/xingtang.lpc`,
  `d/taishan/tang2.lpc`, `d/taishan/tang3.lpc` — renamed the variable to
  `newob` in all 4 (declaration + both use sites each). Two of the same
  four files (`d/quanzhou/npc/tang3.lpc`, `d/taishan/tang3.lpc`) also used
  a bare, never-`#define`d `SAVE_EXTENSION` instead of the real driver
  macro `__SAVE_EXTENSION__` (used correctly elsewhere in this lib, e.g.
  `logind.lpc`) — fixed both occurrences in each file.
- **1 file, literal two-character `"^M"` text stuck mid-statement** (not an
  actual carriage-return byte — confirmed via `xxd` on the raw
  pre-conversion file: genuinely the two ASCII characters caret+M, `0x5E
  0x4D`, immediately followed by a real `\r\n` — some past editor's visual
  "showing CR as ^M" display got typed as literal text into the file by
  mistake) plus two dangling, discarded-result comma-expression statements
  left over from what was probably an edited/shortened `message_vision()`
  call: `d/mingjiao/banshanyao.lpc` — removed the literal `^M` text and the
  two inert orphaned expression statements (their results were already
  being discarded; removing them changes no behavior).
- **1 file, duplicate `create()` function** (copy-paste leftover — the
  second, incomplete definition never calls `init_whip()`/`set_name()`/etc
  and is clearly superseded by the first, complete one):
  `d/npc/m_weapon/weapon/m_bian.lpc` — deleted the second, redundant
  `create()`.

### Remaining 112 failures — triaged by category, not fixed further (per
AGENTS.md §6b: fix genuine shared/impactful bugs, document the rest; this
matches the same triage rigor applied on `weimingkongjian`)

- **71 of 112 (63%)** have **no error message at all** — a bare "Fail to
  load object". This is the exact `lpcc --batch`-from-a-near-empty-file-list
  artifact directly reproduced and documented in `weimingkongjian`'s
  NOTES.md (a from-scratch VM session needing some inherit-chain "warm-up"
  before certain compiles resolve correctly against a short file list, not
  a real bug) — not re-derived from scratch here, just cross-checked that
  the files in this category are the expected shape (personal wizard-zone
  content under `u/fyue/huashan/*`, various `d/*` room/NPC files not on the
  registration/boot path) and confirmed none of their names appear anywhere
  in any of the three clean interactive-test `debug.log`s.
- **8 files** (`adm/daemons/network/{ms,userid,pingtcp,mail_serv,netmail,
  telnetd,pingd,inetd}.lpc`, `Cannot #include {config,priv,uid,mailer,
  daemons,post}.h` + assorted undefined variables/functions): the dead
  intermud/mail/telnet-daemon sibling suite that `dns_master` itself
  belongs to — confirmed none of these are referenced anywhere in
  `adm/etc/preload` (only `dns_master` was, and it's now commented out) or
  reachable from the registration path. Matches AGENTS.md §15p's "this
  whole daemon family is dead weight in this environment" finding exactly.
- **3 files** (`meskill/skill_model_{unarmed,default,weapon}.lpc`,
  `Undefined variable SKILL_CH_NAME/SKILL_BASE_NAME/SKILL_EN_NAME/action`,
  `Undefined function NewRandom`): confirmed (same conclusion as
  `weimingkongjian`) these are **code templates** read as plain text and
  macro-substituted by an in-game skill-authoring tool — the macros are
  deliberately never `#define`d anywhere, by design, meant to be filled in
  by the generator at runtime, not compiled directly.
- **1 file** (`adm/obj/simul_efun_bak.lpc`, `Invalid simulated efunction
  override`): a `_bak` suffix backup copy of `simul_efun.lpc` (alongside
  `adm/obj/master.c.bak`/`.org`, also unused) — not referenced by
  `config.fluffos`'s `simulated efun file` directive, dead by construction.
- **2 files** (`feature/vendor_sale.lpc`, its inheritor
  `kungfu/class/npc/xiaoer.lpc`): a large, genuinely pre-existing syntax
  breakage — confirmed byte-identical to the raw pre-conversion file (no
  diff), so this was **already broken in the original archive**, not
  something introduced here. The `do_deposit()`/`do_setprice()`/`pay_back()`
  functions are missing nearly every semicolon and several closing
  parentheses throughout ~60 lines — far beyond a single-typo fix, and this
  file's own NPC (`kungfu/class/npc/xiaoer`, a kung-fu-hall shopkeeper) is
  **not** the same file as the actual start-room innkeeper NPC
  (`/d/city/npc/xiaoer`, a completely separate, working file) that appeared
  live in every interactive test. Documented as a known, non-critical,
  pre-existing content gap — not attempted (would require guessing the
  author's intended statement boundaries throughout, i.e. fabricating
  content, not fixing a diagnosable bug).
- **2 files** (`d/player/ltsh/npc/saveme.lpc`, its inheritor
  `d/player/ltsh/tst.lpc`, `Bad type for argument 1 of exert_function
  (string vs int)`): **the exact same file, same bug, already documented
  and left unfixed in `weimingkongjian`'s NOTES.md** — `exert_function`
  expects a string skill-name (confirmed against ~100+ other call sites in
  this lib that all pass one), but this file passes a bare int `10` with
  no surrounding context indicating what string was intended. Confirmed
  genuinely shared content (not independently duplicated) and left unfixed
  for the same reason as before: fabricating a guessed skill name would be
  inventing content, not fixing a diagnosable bug. Decorative/minor NPC
  file, not on the registration path.
- **2 files** (`d/kaifeng/east.lpc` missing `guanli.h`, `d/city/npc/
  zhuziliu.lpc` missing `/u/fyue/job/askjob.h`): genuinely missing headers
  — confirmed absent anywhere in the archive (§13-style content gap, not a
  reference-fixing bug). `guanli.h` missing matches the exact gap already
  documented in `weimingkongjian`'s NOTES.md for the same file family.
- **3 files** (`d/gumu/duanchang.lpc` + the shared `d/gumu/tiao.h` it
  `#include`s, and its siblings `d/shaolin/houdian.lpc`/`d/shaolin/npc/obj/
  houdian.lpc` which also `#include` it — the latter two happen to compile
  clean standalone despite sharing the include): `tiao.h` is, on
  inspection, not really a header at all — it's a **complete standalone
  room definition** (its own `inherit ROOM; void create() {...} void
  init() {...}`) for a "跳崖" (cliff-jump) minigame room, mistakenly given a
  `.h` extension and `#include`d into `duanchang.lpc` rather than existing
  as its own loadable `.lpc` object. Since `duanchang.lpc` already has its
  own `inherit ROOM`/`create()`/`init()`, the `#include` causes
  "Illegal to redefine 'nomask' function `_set`/`_delete`/`_query`" (via
  the doubled `ROOM`→`F_DBASE` inherit chain) and "Redeclaration of
  function `create`/`init`". Left unfixed: untangling which parts of
  `tiao.h` were meant to be inherited *behavior* (the `do_tiao`/`do_yes`/
  `do_no`/`win`/`fail` cliff-jump functions) versus which were leftover
  *room* boilerplate that should never have been in a `#include`d fragment
  requires a design decision this pass isn't positioned to make safely
  without either dropping real content or guessing wrong; decorative
  side-content, not on the registration/boot path.
- **A handful of one-off pre-existing gaps**, each confirmed non-critical
  and not chased further given diminishing returns (all are admin tools,
  personal wizard-zone content, decorative kung-fu skill files, or doc
  reference material — none appear in any of the three clean interactive
  test transcripts): `doc/mudlib/efuns.lpc` (a plain-text efun-name
  reference list, not code, caught by the blanket `.c`→`.lpc` rename —
  same AGENTS.md §12 shape as the `shenminmap.c` precedent) and
  `doc/mudlib/efuns/shiwu.lpc`; `quest/murong/qlist3.lpc`; `clone/misc/
  objmaker.lpc` (a builder tool); `clone/topten/gaoshou.lpc` (missing
  `GAOSHOU` macro); `d/city2/npc/zhengmen.lpc` (unbalanced braces);
  `d/npc/master.lpc` (a bare `set("inquiry", ...)` fragment with no
  `create()`/`inherit` at all — looks like an NPC-dialogue-table fragment
  meant to be `#include`d elsewhere, but no other file references it by
  this exact path; likely orphaned); `d/huashan/npc/doctor.lpc` + its
  inheritor `d/huashan/doctorroom.lpc`; `d/huashan/map.lpc` and `u/fyue/
  huashan/map.lpc` (both pure ASCII-art room-layout maps, not a line of
  LPC — same §12 shape as `doc/mudlib/efuns.lpc`, `grep -rl` for their
  basenames elsewhere comes up empty); `d/shaolin/npc/obj/shuitan.lpc`
  (one undefined variable, `ging_cost`, likely a typo'd variable name);
  `d/quanzhen_old/npc/haodatong.lpc`; `u/snow/who.lpc` and `u/fyue/user.lpc`
  (personal wizard-sandbox admin tooling); `cmds/usr/whotest.lpc` (a
  "test" command, name suggests experimental/dead); `cmds/bos/socket.lpc`
  (`dump_socket_status`, a debug efun with no equivalent in this driver's
  socket package); and several `kungfu/skill/*.lpc` one-off syntax errors
  (`iceforce/chillgaze`, `hanbing-mianzhang2`, `huang`, `xixi-unarmed`,
  `quanzhen-xinfa`) — decorative combat-skill content, none reachable from
  the registration flow or the interactive test's actual path.

## Encoding

`convert_lib.sh`'s automated pass: 8,649 converted cleanly, 295
already-UTF-8, 33 lossy (invalid bytes dropped via `iconv -c` fallback —
mostly NPC/room/data files, e.g. `d/quanzhen_old/obj/bookshelf.c`,
`u/fyue/huashan/{map.c,intro}`, `cmds/usr/{nick.c,whotest.c}`), 2 skipped as
genuinely binary. One of the lossy files (`d/heimuya/shenggu.c`) was
confirmed via `xxd` to have a genuine invalid-GBK-lead-byte-then-newline
sequence at the exact failure point — the specific "iconv -c eats an
adjacent real newline" gotcha from AGENTS.md's Encoding section, fixed as
described above. No un-converted GBK stragglers found (re-ran the
AGENTS.md straggler check: `file -b` reports text/script/empty for every
`.lpc`/`.h` in `work/`).

## Config

`config.fluffos` adapted from `Jhfy/config.jh` (labeled "MudOS 0.9.20",
GBK→UTF-8 converted **before** any other edit, per AGENTS.md §5). Original
`port number : 6666` replaced with **40053** (this project's port
assignment for archive #59, per the task brief — next free port after
40051-40052 reserved for archives #57-58). `mudlib directory` points at
`/home/sunyc/src/mudlib/libs/jianghufengyun/work` (absolute path). All
other directives carried over, matching the tuning-knob template used for
the last several libs in this batch (`weimingkongjian`/`xiakexing3` shape).
`log/` directory created as a sibling of `config.fluffos` (not inside
`work/`), driver always launched via `cd libs/jianghufengyun && setsid
nohup .../driver config.fluffos` (see the "Driver process management note"
above for why `setsid` specifically was needed in this session).
