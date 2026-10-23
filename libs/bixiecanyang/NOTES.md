# bixiecanyang — 碧血残阳 之「豪侠晚歌」

Archive: `碧血残阳之豪侠晚歌.rar` (archive #71). Port: 40065. Status:
**done** (boots clean, full registration flow verified end-to-end
including a real Chinese name reaching the actual game world).

## What this is

"碧血残阳" ("Blood on the Setting Sun"), subtitle "「豪侠晚歌」" ("Ballad
of the Gallant Hero"), domain akai.isme.net, dual-port config (ZMUD 6666 /
TOMUD 8888 in the raw config; reassigned to a single port 40065 here).
`adm/obj/{master,simul_efun}` layout. The bundled `碧血残阳说明.txt`
(author's own readme) explicitly states this lib is built on top of
**"夕阳再现－江湖风云2－风云再起"** ("Sunset Reappears - Jianghu Fengyun 2
- Storm Rises Again") — i.e. this is a member of the same **夕阳再现
(Xiyangzaixian)** lineage as archives #46 (`xyzxfk`), #47
(`xyzxfy2`), #55 (`wmkj`), and #59
(`jhfy`), not a standalone codebase.

**Lineage confirmed via md5sum, not just the readme's claim**:
- `adm/simul_efun/chinese.c`: **byte-identical** (md5 `961d77af057bb93db320af05be5883fc`)
  across all 5 archives (#46/#47/#55/#59 and this one).
- `adm/daemons/securityd.c`: **byte-identical** (md5 `032452f57e844ff416d4747b12b85d27`)
  specifically to `xyzxfy2` (#47)'s copy — closest sibling
  in this family.
- `adm/obj/master.c` and `adm/daemons/logind.c` are each distinct from
  every sibling (own md5sums, different line counts) — same pattern as
  every other pair of forks in this family: shared engine utility files,
  divergent site-specific daemons.

## Cross-check against dtsl2 (#49) — required by task instructions

`libs/dtsl2/NOTES.md` documents that its raw config file's own
`name` field contained the **exact string "碧血残阳 之 豪侠晚歌"** — this
archive's own title — as a confirmed-stale copy-paste leftover, not a sign
that dtsl2 is secretly a duplicate of this archive. Verified the
reverse direction too, as instructed, via direct `md5sum`/`diff` on both
raw archives (not work copies):

- `adm/simul_efun/chinese.c`: **differs** — this archive's md5 is
  `961d77af...` (the 夕阳再现-family shape: `strlen(str)>=2 && str[0] > 160
  && str[0] < 255`, 14 lines); dtsl2's is `a619b926...` (a
  different GBK-range formula: `str[0] < 176 || str[0] > 247` +
  `str[1]` checks, 19 lines). Not the same file at all.
- `adm/obj/master.c`: **differs substantially** — this archive's is 342
  lines with a `TOMUD_PORT`/`get_player_fname()` backup-login-object
  fallback mechanism and a `"change by Fan@wanxia"` credit header, none of
  which appear in dtsl2's (302-line, no TOMUD/backup-login
  logic, no Fan@wanxia credit) — full diff is 646 lines of changes out of
  ~342, i.e. almost entirely different content past the shared
  `connect()`/`compile_object()` skeleton wording.
- `adm/daemons/logind.c`: 1007 lines here vs 917 in dtsl2 —
  different.
- **Interesting second piece of evidence for the copy-paste theory**:
  dtsl2's raw archive's own config file is **also literally
  named `config.bxcy`** (verified: `libs/dtsl2/raw/DTSL/config.bxcy`
  exists) — the same filename as this archive's `config.bxcy`. This means
  not just the `name` field's *text* but the config file's *filename
  convention itself* was copy-pasted from a bixiecanyang-lineage template
  into whatever base dtsl2 forked from, while the actual
  mudlib code (chinese.c/master.c/logind.c) diverged completely.

**Conclusion**: confirmed NOT related in either direction. This archive is
squarely 夕阳再现/Xiyangzaixian-lineage (shares chinese.c/securityd.c with
#46/#47/#55/#59); dtsl2 is squarely dtsl(#8)/大唐双龙-lineage
(shares chinese.c/F_UNIQUE-macro-gap/diamond-inherit-bug with #8/#18). The
coincidence is purely a copy-pasted config template/field, confirmed twice
over (stale name field + stale filename convention), never a sign of
shared mudlib content.

## Fixes applied (ported/cross-checked against #47's proven fix list where lineage matches, applied proactively before first boot)

1. **AGENTS.md §15h** (`adm/simul_efun/chinese.lpc`'s `is_chinese()`): GBK
   lead-byte range check (`strlen(str)>=2 && str[0] > 160 && str[0] < 255`)
   → CJK Unicode codepoint range check (`strlen(str)>=1 && str[0] >= 0x4e00
   && str[0] <= 0x9fff`).
2. **AGENTS.md §15h** (`adm/daemons/logind.lpc`'s `check_legal_name()`):
   byte-count bound `strlen(name) < 2 || > 10` → character-count bound
   `< 1 || > 5` (matches the message's own stated "1 到 5 个中文字"); the
   sliding-window gate `i%2==0 && !is_chinese(name[i..<0])` had its
   `i%2==0 &&` dropped so every character position is checked (the
   `name[i..<0]` slice itself needed no change since `is_chinese()` only
   ever inspects index 0 of whatever's passed to it — a full-length
   suffix slice starting at `i` is functionally equivalent to a
   single-character check either way).
3. **AGENTS.md §15z** (5 files: `include/globals.h`, `adm/obj/master.lpc`,
   `adm/obj/simul_efun.lpc`, `adm/obj/simul_efun_bak.lpc`,
   `u/isle/ToMud/globals.h`): each carried an
   `#ifndef __SENSIBLE_MODIFIERS__` / `#define nosave static` / `#define
   protected static` compatibility shim (this driver never defines
   `__SENSIBLE_MODIFIERS__`, so the shim is always active). `convert_lib.sh`'s
   blanket `static`→`nosave` sed rewrote the shim's own lines too, turning
   `#define protected static` into `#define protected nosave` — silently
   aliasing `protected` to `nosave` instead of leaving it as its own
   distinct, correctly-behaving keyword. Fixed to `#define protected
   protected` (self-map, matching the already-correct `#define nosave
   nosave` sibling line) in all 5 files.
4. **AGENTS.md §3 counterexample** (22 files): the same blanket sed also
   hit `log_file("static/XXX", ...)` string literals (a real on-disk log
   subdirectory name, unrelated to the `static`/`nosave` keyword),
   rewriting them to `"nosave/XXX"` and orphaning the archive's real seed
   data at `log/static/` (confirmed present on disk: `archive`,
   `banned_sites`, `CALL_PLAYER`, `CRASHES`, `EAT_DAN`, etc.). Reverted all
   22 occurrences (`clone/misc/dan.lpc`, `cmds/{arch,adm}/{call,purge,setskill}.lpc`,
   `cmds/wiz/call.lpc`, `cmds/std/suicide.lpc`, `adm/simul_efun/override.lpc`
   ×5, `adm/daemons/securityd.lpc`, `adm/obj/master.lpc` ×5) back to
   `"static/XXX"`.
5. **AGENTS.md §14** (`adm/obj/master.lpc`'s `valid_override`): upgraded
   from the 2-arg signature to the documented 3-arg
   `(file, name, main_file)` form, checking `main_file == SIMUL_EFUN_OB ||
   main_file == MASTER_OB` in addition to the original `file` check — this
   lib's `simul_efun.lpc` is a pure `#include` composer (pulls in
   `object.lpc`/`message.lpc`/`wizard.lpc`/etc., several of which contain
   `efun::` overrides like `object.lpc`'s `destruct()`), so `file` alone
   (the physically-containing fragment) never equals `SIMUL_EFUN_OB` for
   those. No live boot/registration failure was observed from the 2-arg
   gap (consistent with AGENTS.md's note that this may never surface on a
   real boot, only under isolated `lpcc` checks) but applied as free
   insurance per the catalog's standing guidance.
6. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was present (live,
   uncommented) in `adm/etc/preload` — commented out proactively before
   the first boot attempt. Checked every other preload entry's own source
   (`securityd`, `virtuald`, `logind`, `rankd`, `preload`, `commandd`,
   `chinesed`, `emoted`, `aliasd`, `fingerd`, `autosaved`, `channeld`,
   `natured`, `monitord`, `storyd`) for `socket_create`/`resolve()` calls —
   none found, confirmed safe to leave active. `httpd` was already
   commented out in the shipped preload file.
7. **AGENTS.md §15s** (`adm/simul_efun/message.lpc`'s `tell_room()`): the
   common 2-arg call form (`tell_room(ob, str)`, confirmed via grep to be
   the overwhelmingly dominant call shape across ~155 files in this
   archive) leaves the `varargs object *exclude` parameter as its default
   int `0`, which then flows straight into `message("tell_room", str, ob,
   exclude)` — this driver's `message()` efun declares its 4th argument
   `void | object | object *` (a real type union, not "any"), so a literal
   int `0` is rejected at runtime (`Bad argument 4 to message()`) the
   first time any room's heartbeat/emote broadcast calls the wrapper with
   only 2 args. Fixed at the single shared root: `message("tell_room",
   str, ob, exclude || ({}));`. (File is CRLF-terminated — used a
   byte-exact Python replace rather than a line-oriented `sed`/`Edit` to
   avoid the line-ending pitfalls documented elsewhere in AGENTS.md.)

## Confirmed NOT needed (verified by reading source, not by hitting a crash)

- **§4** (lazy security-daemon `load_object` recursion in
  `valid_read`/`valid_write`): `master.lpc`'s `valid_write` only ever
  `find_object(SECURITY_D)` (returns `0` if absent, never lazily loads
  it); `valid_read` does the same plus an early `return 1` for callers
  with no resolvable `previous_object()`. No `load_object()` call
  anywhere in either apply — no reentrancy guard needed.
- **§7** (`get_root_uid`/`get_bb_uid`): both present and correct
  (`return ROOT_UID;` / `return BACKBONE_UID;`).
- **§15l** (`destruct(SIMUL_EFUN_OB)` in master's `create()`): `create()`
  is a one-line `write("master: 成功加载.\n");` — no destruct/reload
  dance present at all.
- **§15n** (custom `securityd.lpc` ACL denying "(player)"-status reads
  under `/adm`/`/cmds`, blocking mid-connection lazy compiles): this
  lib's `securityd.lpc` (byte-identical to #47's, confirmed above) IS a
  genuinely custom ACL with real `exclude_read`/`trusted_read` tables,
  but — read directly, not assumed from the sibling's writeup —
  `exclude_read` never lists `"(player)"` in any of its directory entries
  (`adm`/`d`/`data`/`userdata`/`feature`/`cmds`/`u`/`clone`/`include`/
  `inherit`/`kungfu`/`quest`/`log` all key off wizard-tier statuses only),
  and `valid_read` itself returns `1` early whenever the caller has no
  resolvable euid/status (`if( !euid ) return 1;`) and again whenever the
  file's author matches root (`author_file(...)==ROOT_UID`). The §15n
  failure mode genuinely cannot trigger here. Confirmed further by the
  clean interactive test — zero "Read access denied" anywhere in
  `debug.log`.
- **§15u** (dormant "phone-home license check" self-destruct function):
  grepped `securityd.lpc`/`master.lpc` for `checking_status`/mass
  deletion/`shutdown()`-gated-on-opaque-check shapes — none found.
- **§8d/§15o** (`get_include_path()` / local `<header.h>`-next-to-its-user
  angle-bracket includes): `convert_lib.sh`'s automatic local-include-to-
  quotes pass already converted 57 such includes to quoted form during
  conversion (quotes resolve regardless of VM context, unconditionally
  fixing this whole class) — no `master.lpc get_include_path()` addition
  needed on top of that.
- **Nitan-family simul_efun-dbase architecture bug (§15)**: not present.
  `adm/obj/simul_efun.lpc` is a pure `#include` composer with no bare
  `set`/`query`/`delete` definitions anywhere in its included fragments;
  `feature/dbase.lpc` (F_DBASE, widely inherited) implements real local
  `set`/`query`/`delete` methods directly. Correct inherit-based
  architecture.
- **No `named.lpc` daemon exists in this lib at all** (grep came up
  empty) — the deep §15h `PATH()`/sliding-window fix doesn't apply;
  `chinesed.lpc` only handles `chinese_number()`/dictionary translation,
  not name validation.
- **§8e** (`tail()` missing-efun bug): `adm/simul_efun/file.c` has no
  `tail()` call anywhere.
- **§15x** (hardcoded `MUD_PORT` mismatch silently rejecting every
  connection): `master.lpc`'s `connect(int port)` does have a hardcoded
  `#define TOMUD_PORT 8888` constant, but it's only used to conditionally
  set an optional `"tomud"` temp flag (`if (port == TOMUD_PORT)
  login_ob->set_temp("tomud", 1);`) — it never rejects a connection on a
  port mismatch. Since this project's assigned port (40065) never equals
  8888, the flag is simply never set; confirmed no rejection occurs via
  the successful end-to-end interactive test.
- **A related §15q-shaped hidden gate DOES exist but is provably inert
  here**: `logind.lpc`'s `logon()` has `if (ob->query_temp("tomud")) {
  ... input_to("get_version", ob, ip_cnt); }` — `get_version()` checks the
  input against a hardcoded literal `"2060"` (a TOMUD client-handshake
  code) and disconnects on any mismatch, exactly like the gate documented
  in §15q on `xyzx3`. But this branch is itself gated behind the
  same `TOMUD_PORT`-only flag described above, which (per the point just
  above) never gets set on this project's assigned port — so the gate is
  present in the source but structurally unreachable for our single-port
  setup. Confirmed by the transcript: no `"2060"` prompt appeared at any
  point, `get_id` was reached directly after the banner as expected.

## Interactive test result — full registration flow

Read `logind.lpc`'s actual `input_to` callback chain before testing (not
assumed from a sibling lib). Flow: `logon()` → (no `get_version`, per
above) → **English id** (`get_id`, 3-14 bytes / a-z only) → **y/n
create-confirmation** (`confirm_id`) → **Chinese name** (`get_name`,
1-5 characters, NO separate y/n confirmation for a typed name — the y/n
loop in `get_resp` only fires for the auto-generated `random_name()` path,
triggered by submitting an empty name) → 管理密码/wizpwd (`new_wizpwd`,
≥5 chars) → confirm wizpwd (`confirm_wizpwd`) → real login password
(`new_password`, ≥5 chars) → confirm password (`confirm_password`) →
attribute-gift selection (`select_gift`, 0-4; 0 = system random via
`get_gift`'s y/n reroll loop) → email (`get_email`, `id@x.x` format
required) → gender (`get_gender`, m/f) → `enter_world()`.

`banned_name` list: 你/你的/我/我的/自己/屁/他/他的/她/她的/它/它的/鬼王/
风云/流氓/爸/妈/祖先/祖宗/爷/奶/毛泽东/邓小平/江泽民/【/】/马克思/恩格斯/
列宁/抄/手淫/老百姓 — checked before testing, "秦风" doesn't match any
entry (note "风云" alone is banned, but "秦风" isn't a substring match for
it in either direction as tested — the real driver accepted it cleanly).

Verified the **complete** registration path in **one continuous
`mudclient.py` connection**:
- `""` → correctly rejected ("必须是 3 到 10 个英文字母"), confirming
  `check_legal_id` is live and the empty-input retry loop works.
- `qinfeng` → accepted, "您确定吗(y/n)？" prompt.
- `y` → confirms new character, shows the "give yourself a name" banner.
- **`秦风` (real Chinese name)** → accepted silently, no rejection,
  proceeds straight to "请设定您的管理密码：" — confirms the §15h fix
  works correctly end-to-end, not just at the prompt-rendering level.
- `pass1234` / `pass1234` (wizpwd + confirm) → accepted.
- `pass5678` / `pass5678` (real password + confirm) → accepted, shows the
  attribute-gift explanation banner (膂力/悟性/根骨/身法/福缘/容貌).
- `0` → system-random gift roll (rolled 膂力18/悟性22/根骨22/身法18).
- `y` → accepts the rolled gift.
- `test@test.com` → accepted as email.
- `m` → male gender.
- Character **actually entered the game world**, landing in `/d/city/wumiao`
  ("武庙"/Wumiao — Yue Fei Temple, one of the 4 configured `start_room`s),
  saw NPCs render correctly (紫衣神女小玲儿, 千里眼, 阿凯哥哥) and the
  bulletin board object. `CHANNEL_D` broadcast "听说又来了一位叫做秦风的
  少年侠士" (new-player channel announcement) with the correct Chinese
  name embedded, confirming the character record itself carries the real
  name, not just the prompt accepting it.
- `look` → re-displayed the room correctly.
- `quit` → dropped a starting item ("布衣") and disconnected gracefully
  with "欢迎下次再来！" ("welcome back next time").

Zero real `error:` lines, zero "Read access denied"/"Bad argument"/"Too
deep recursion"/segfault signatures anywhere in `debug.log` across the
whole session — only the same cosmetic `编译时段错误：... warning:
Unknown #pragma, ignored` lines seen in `xyzxfy2` (this
lib's own `error_handler()`/`log_error()` mislabels compile-time
*warnings* as "compile-time errors" in its Chinese message text; harmless,
matches every other lib in this lineage family).

## Second independent registration-flow verification (different session, different name/gender)

Rebooted the driver fresh (new PID) after the lpcc-sweep-driven fixes below
(several of which touched `adm/simul_efun/message.lpc`, a preload-critical
file) to make sure nothing regressed. Ran a second, independent
`mudclient.py` test with a different id/Chinese name/gender combination in
one continuous connection:

- id `linfeng` → confirm `y` → **real Chinese name `林风`** → accepted
  silently, straight to wizpwd prompt.
- `wizpass12`/`wizpass12` (wizpwd+confirm) → accepted.
- `realpass34`/`realpass34` (password+confirm) → accepted.
- `0` → random gift roll, `y` → accepted.
- `linfeng@test.com` → accepted.
- `f` → **female** gender this time (previous test used male) → correctly
  set `"gender"` to `女性`.
- Character entered the game world in a **different** start room this
  time, `/d/xingxiu/beijiang` ("北疆小镇"/Beijiang Town — one of the same 4
  configured `start_room`s, picked by the lib's own random selection logic),
  saw 2 "维吾尔族妇女" (Uyghur woman) NPCs, one of which reacted
  interactively ("维吾尔族妇女看着你笑了起来" / "the Uyghur woman looks at
  you and smiles"). `CHANNEL_D` broadcast "听说又来了一位叫做林风的**妙龄
  少女**" (note: correctly used the female-appropriate honorific "妙龄少女"
  /"young maiden", not the male "少年侠士" from the first test — confirms
  gender-conditional text is also working correctly).
- `look` → re-displayed the room.
- `quit` → dropped a starting item ("粉红绸衫") and disconnected gracefully.

Zero real `error:`/"Read access denied"/"Bad argument"/"Too deep
recursion"/"Undefined function" lines in `debug.log` for this second run
either — confirms the message.lpc/simul_efun.lpc changes made during the
lpcc-sweep triage (below) didn't regress anything.

## lpcc sweep

13,560 files initially (`.lpc`/`.c` count after rename — matching
`xyzxfy2`'s file count almost exactly, same-generation
snapshot of a similar world size); 13,559 after reclassifying 2 non-LPC
files (below).

**First full sweep** (after only the proactive pre-boot fixes above, before
any sweep-driven triage): **13,355 / 13,560 pass (98.5%)**, 205 failures.

**Triaged the 205 failures and fixed every genuine driver-compat/typo bug
found** (leaving only true content-gap/context-dependent noise, per
AGENTS.md §6b's "verify against the real boot log before trusting an
lpcc-only failure" guidance and its "fix genuine one-off typos, don't
chase call_other/couldn't-find-object noise" triage method):

1. **3× missing-opening-quote typos** (`d/quanzhen_old/hudi4.lpc`,
   `hudi6.lpc`) and **1× missing-both-quotes typo** (`hudi5.lpc`) in
   `set("long", <bare Chinese text>)` calls — same §10 shape documented
   project-wide. Confirmed pre-existing in the raw archive (not a
   conversion artifact) via direct byte inspection.
2. **1× missing-closing-quote typo** (`kungfu/skill/qingyi-jian.lpc`):
   `"skill_name" : "大悲式,` → `"skill_name" : "大悲式",` (file has
   unusual `\r\r\r\n` line endings — fixed via exact byte-level Python
   replace, not a line-oriented sed/Edit).
3. **1× dropped-closing-quote typo mid-string-concat**
   (`kungfu/skill/kunlun-zhang.lpc`): a Chinese sentence ending in the
   opening bracket "「" with no closing quote before the following comma —
   added the missing `"` (left the "「" as-is rather than guess at the
   sentence's real missing continuation, per AGENTS.md's "don't fabricate
   content" principle).
4. **1× missing-semicolon typo** (`kungfu/skill/huang.lpc`):
   `set_skill("yuxiao-jian", 550)` (no `;`) merged into the next
   statement, causing "unexpected map_skill". Now compiles clean but
   still shows "Fail to load object" for an unrelated context-dependent
   reason (NPC create() logic) — moved from a real compile bug to the
   same benign "Fail to load object" bucket as everything else below.
5. **1× stray leading character** (`kungfu/skill/xixi-unarmed.lpc`): a
   bare `c` on line 1 (before the file's own header comment) made
   `inherit SKILL;` a few lines later illegal ("inherit after defining
   global variables"-shaped error, AGENTS.md §15t#3's failure mode from a
   different root cause). Removed the stray character.
6. **1× broken `for` loop + 1× same-file duplicate function**
   (`clone/misc/objmaker.lpc`): `for(i=0; i if(...) continue;` was
   missing its condition/increment clause and opening brace (confirmed
   pre-existing in the raw archive) — restored to
   `for(i=0; i<sizeof(name1); i++) {` matching this codebase's universal
   idiom; separately, a duplicate `int query_autoload() { return 1; }`
   later in the same file (harmless copy-paste, same shape as objmaker's
   two `query_autoload` originally, see #9 below) was removed.
7. **1× missing comma between mapping-array elements**
   (`quest/murong/qlist3.lpc`): a `])` closing one quest entry wasn't
   followed by a comma before the next `([` entry.
8. **1× stray backtick typo** (`kungfu/skill/hanbing-mianzhang2.lpc`):
   `` `random(...) `` — a leading backtick before a `random()` call
   (confirmed pre-existing in the raw archive) caused "End of file in
   template literal" since the lexer treated it as an unterminated
   literal. Removed the stray backtick.
9. **Same-file/base-class `query_autoload()` duplicate-definition
   cluster** (5 files: `d/obj/quest/{chai,chai1,chai3}.lpc`,
   `clone/book/{lbook5,pixie_book}.lpc`): `chai.lpc`/`chai1.lpc`/
   `chai3.lpc` each `#include "task.h"` (a per-directory local header that
   ALREADY defines `query_autoload()`) and then redundantly redefined the
   identical function themselves; `lbook5.lpc`/`pixie_book.lpc` each had
   the exact same one-liner defined twice within their own file. Removed
   the redundant copy in each of the 5.
10. **1× duplicate `create()` function** (`d/npc/m_weapon/weapon/m_bian.lpc`):
    a full, content-rich `create()` (name/weight/messages/`init_whip`) was
    followed later in the same file by a second, generic stub `create()`
    (missing all the specific weapon details) — clearly a copy-paste
    template leftover. Removed the redundant stub, kept the real one.
11. **2× lossy-conversion-shaped "End of file in text block"**
    (`d/quanzhen_old/manglin1.lpc`, `manglin2.lpc`): the `@LONG ... LONG`
    text block's closing `LONG` tag was merged onto the end of the
    preceding text line with no newline — **confirmed via the raw
    pre-conversion archive bytes that this is a PRE-EXISTING authoring
    typo, not an iconv/lossy-conversion artifact** (unlike the similar-
    looking cases documented elsewhere in AGENTS.md) — the original GBK
    bytes already had "...耳际。LONG\r\n" with zero separator. Inserted
    the missing newline before `LONG` in both files.
12. **`message_combatd()` — a 3rd `message_vision`-family alias gap**
    (called live by `kungfu/skill/yunv-xinfa/roar.lpc`, 2 more call sites
    commented out elsewhere): never defined anywhere in this archive,
    same "§15b-style called-everywhere-defined-nowhere" gap already fixed
    on `xzyx`/`wmkj` for the identical function
    name. Added as a thin alias to `message_vision()` in
    `adm/simul_efun/message.lpc`. **Hit the exact §15aa/§8b trap while
    adding it**: an earlier attempt placed the alias BEFORE
    `message_vision`'s own textual definition in the same file, which
    made `adm/obj/simul_efun.lpc` itself fail to load
    ("Undefined function message_vision") — moved the alias to AFTER
    `message_vision`'s closing brace, which fixed it immediately. Re-ran
    the FULL boot + registration test after this specific change (since it
    touches a preload-critical file) to confirm no regression — see below.
13. **2 non-LPC files caught by the blind `.c`→`.lpc` rename** (AGENTS.md
    §12): `doc/mudlib/efuns.lpc` (a plain columnar list of efun names —
    pure documentation, not compilable code, nothing references it) and
    `d/huashan/map.lpc` (a pure ASCII-art room-layout map, not a single
    line of LPC, nothing references it either). Both renamed to `.txt` to
    keep the sweep's pass/fail signal meaningful.
14. **1 genuine typo, unrelated context** (`doc/mudlib/efuns/shiwu.lpc`,
    an example/tutorial room under `doc/`): `call_out(do_close,0);` —
    `do_close` used as a bare unquoted identifier instead of the string
    literal `call_out()` requires (`"do_close"`). Fixed; the file now
    compiles (still shows "Fail to load object" for the same
    context-dependent reason as ordinary room files below, not a compile
    bug anymore).

**Second full sweep** (after all fixes above, and after reclassifying the
2 non-LPC files so the total file count is 13,559): **13,374 / 13,559
pass (98.6%)**.

**Remaining ~185 failures, triaged by category, confirmed as expected
noise (not fixed further)**:
- **~49× generic "Fail to load object" with no compile-error text at
  all** (`d/migong/lev*/dong*` — 35 deep-dungeon-maze rooms;
  `clone/gem/ring*` — 11 loot rings whose `setup()`/`init_sockets()` chain
  calls `this_player()`, which is null in `lpcc`'s bare `find_object()`
  load context; several individual `kungfu/skill/*`, `kungfu/class/*`,
  `clone/npc/*`, `clone/misc/*`, `quest/*` items/NPCs). **Confirmed via
  the real boot+interactive-test `debug.log` that NONE of these paths are
  ever touched** (`grep -i "migong\|clone/gem"` on the log came up empty)
  — none are on the preload/registration path, matching the exact
  category documented in `xyzxfy2`'s own NOTES.md for the
  same shape of failure. Standalone `lpcc` re-checks of a sample (e.g.
  `/clone/gem/ring4`, whose `inherit/gems/ring.lpc` base class itself
  compiles clean standalone) confirm this is a bare-test-context
  limitation (no real player/room graph), not a genuine bug.
- **~8× `/u/snow/wudujiao/...` `Cannot #include globals.h`**: the exact
  same personal-wizard-scratch-directory VM-context-dependent include gap
  already documented (and left unfixed, for the same reason) in
  `xyzxfy2`'s own NOTES.md — this world content is shared
  between the two forks. Not on the registration/preload path.
- **`feature/vendor_sale.lpc`**: significantly corrupted in the RAW
  archive itself (confirmed via direct byte comparison, not a conversion
  artifact) — dozens of missing semicolons/parens and what looks like a
  fragment of a DIFFERENT function's `if` clause spliced into the middle
  of a string literal, spanning ~60 lines. This goes well beyond a
  single-line typo fix; reconstructing the intended shop-transaction
  logic would mean fabricating business logic, not restoring a
  known-correct original — left as a documented, unfixed content-
  corruption gap (matches AGENTS.md §13's "missing/broken content is a
  real archive gap" philosophy). Confirmed unreachable: nothing in the
  tree `inherit`s or otherwise references this file at all (dead code as
  far as this archive goes).
- **`d/player/ltsh/npc/saveme.lpc`**: `exert_function(10)` passes an int
  literal where every other ~60 call sites in this archive pass a
  function-name STRING (e.g. `exert_function("recover")`,
  `(: exert_function, "recover" :)`), per `inherit/char/npc.lpc`'s
  `int exert_function(string func)` signature. Genuine isolated typo, but
  the "correct" intended string can't be recovered without guessing — a
  single obscure healer-NPC's `chat_msg` config, not on any critical path.
  Left as a documented, unfixed typo.
- **`clone/weapon/panguanbi.lpc`**: `inherit PEN;` — `PEN` is never
  `#define`d anywhere (`include/weapon.h` defines every other weapon-type
  macro — AXE/BLADE/DAGGER/FORK/HAMMER/SWORD/STAFF/CLUB/THROWING/WHIP/RING
  — but never PEN), and no `/inherit/weapon/pen` file exists either.
  Exact same shape as the already-documented `CLUB`/`WEAPON_COMBO`/
  `BBS_BOARD` gaps on `dtsl2`(#49) — a missing macro with no
  clear matching target file to point it at, so guessing a mapping (e.g.
  to `STICK`) would be fabricating behavior rather than restoring a
  documented gap. Left unfixed, single file affected.
- **3× `d/heimuya/{shenggu,tang}.lpc`, `d/heimuya/npc/tang.lpc`**: "End of
  file in text block" — all 3 were also flagged `LOSSY conversion` during
  the encoding pass, matching the genuine iconv-eaten-newline variant
  documented in AGENTS.md's Encoding section (as opposed to #11 above,
  which was confirmed pre-existing in the raw bytes) — not chased further
  given the small scope (3 files, none on the registration path).
- Remainder (~20 files) is the usual long tail of scattered one-off
  undefined variables/functions, a `Bad type for argument` on
  `set_name()` (string vs string*, 2 files), a `Redeclaration`, and a
  couple more isolated syntax errors in unrelated content files (quest
  NPCs, weapon templates) — consistent with every other lib in this
  project's own long tail, not triaged file-by-file per AGENTS.md §6b.

Memory stayed healthy throughout every sweep pass on this 23GB host,
though two of the three sweep runs briefly hit low-availability windows
(<1.2GB) caused by OTHER concurrently-running agents' own lpcc sweeps on
different libs (confirmed via `ps aux` — not this lib's own process) —
the affected runs were killed and cleanly retried once the concurrent
load eased, per AGENTS.md §6b's monitoring guidance.

## How to run

```
cd libs/bixiecanyang
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40065 --timeout 25 --idle 1.5 \
  --send "" --send "<newid>" --send "y" --send "<中文名字>" \
  --send "<wizpwd>" --send "<wizpwd>" \
  --send "<password>" --send "<password>" \
  --send "0" --send "y" \
  --send "you@example.com" --send "m" \
  --send "look" --send "quit"
```

## Retroactive fix (QA re-verification pass, 2026-07-23): log_error() compile-warning spam (AGENTS.md §15af)

Found (proactively, before the first re-verification boot — same shape as
several sibling libs in this project's ES II/夕阳再现-adjacent families)
during a routine re-verification pass: `adm/obj/master.lpc`'s
`log_error()` showed the raw compiler diagnostic text to ANY connected
player, not just wizards — no `wizardp()` gate at all — for every compile
diagnostic funneled through `APPLY_LOG_ERROR`, including harmless "Unused
local variable" warnings triggered by the first lazy compile of an
ordinary room/command file. Fixed proactively before booting (same pattern
as `dtsl`/`dtsl2`/`dfgs2`/`wuhanzhan`/`shenzhou`): only
show the full diagnostic to a wizard; only alarm an ordinary player with
the generic `default error message` for a genuine compile **error** (gated
on absence of `"warning:"` in the message) — `#include <runtime_config.h>`
was already present, so no additional include was needed here.

Re-verified with a fresh full registration (real name `秦湖`, following the
documented wizpwd→password→gift→email→gender flow) reaching the actual
game world (铁枪庙 starting room), then `look`/`score` both producing
correct, clean output with zero compiler-warning spam and zero real
`error:`/`denied`/`too deep recursion` lines in `debug.log`.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (13,558
  files, 13,459 written/reformatted, 37 already-clean, 62 refused with an
  error — expected on legacy code, not chased individually).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦岳`), reaching
  the actual game world (武庙 starting room); `look`/`score`/`quit` all
  produced correct output (score's full character-sheet box rendered
  correctly), zero real errors in `debug.log`. No regressions from the
  reformat or the fresh driver build.
- **WASM build**: preload completes and prints `Initializations
  complete.` cleanly. Login is blocked by **two** issues, neither of
  which is a mudlib bug and both already anticipated by this project's
  known-limitations list:
  1. `adm/daemons/logind.lpc`'s `logon()` enforces an intentional
     `uptime() < 30` post-boot grace period (an anti-crash-loop
     safeguard, same pattern this lib already needed natively — see the
     30s config-startup message players see for real). The stock
     `scripts/wasm_client.js` calls `fluffos_connect()` immediately after
     boot with no delay, so it always trips this gate before any
     `--send` is even processed (`logon()` runs at connect time, before
     the first line of input). Confirmed this is purely a
     harness-timing artifact, not a WASM defect, by testing with a
     scratch variant of the harness that adds a real 31s delay before
     calling `fluffos_connect()` — after that delay, login proceeds past
     this check.
  2. Past that point, login hits `adm/daemons/band.lpc`'s `is_banned()`,
     which does `sscanf(site, "%s.%s.%s.%s", ...) != 4` on
     `query_ip_number(ob)` and treats a non-matching result as banned —
     this is exactly the documented `query_ip_number()` WASM-mode
     limitation (AGENTS.md's post-conversion-tooling section): the wasm
     build's loopback connection doesn't format as a real dotted-quad,
     so the sscanf never matches 4 parts and every login is rejected as
     "banned" (`你的地址在本 MUD 不受欢迎...`). **Not a mudlib bug** — do
     not patch; this lib is a second concrete example of the same
     driver-side gap `bxsj`'s `sited.lpc` demonstrates.
  - **Verdict**: boots cleanly under WASM; login cannot complete due to
    the driver's documented `query_ip_number()` limitation (once the
    unrelated 30s harness-timing artifact is worked around). Not a
    regression, not a mudlib bug.

## WASM-enablement pass (2026-07 standard: loopback-allow, uptime bypass, admin seed)

Gates patched:

- `adm/daemons/logind.lpc` `logon()` (~line 80): the `uptime() < 30`
  startup-grace destruct now applies only to real remote dotted-quad
  addresses; loopback and malformed/empty IPs (current WASM driver
  behavior) are exempt. (Previously documented as a WASM blocker; now
  bypassed per the standing §1.3e policy.)
- `adm/daemons/band.lpc` `is_banned()` (~line 108): loopback / `127.`
  prefix / empty / non-string / non-dotted-quad → return 0. This also
  supersedes the original "malformed IP => banned" behavior that was the
  second documented WASM blocker for this lib.
- The per-IP cap in `get_id()` (`ip_cnt > 8`) counts users sharing the
  connecting IP; under loopback-only local play this could in theory
  trigger with 9+ tabs, but `ip_cnt` is computed in `logon()` before the
  gate and the limit is generous; left unpatched (wiz_level>=2 and
  welcome-listed users are already exempt; fluffos is admin). Note if
  9-tab local testing is ever needed, add a loopback exemption here.

Admin account: id `fluffos`, login password `Mud@2026`, wizpwd `Wiz@2026`
(this lineage's separate "管理密码" asked during registration), display
name 浮浮, `(admin)` via `adm/etc/wizlist`. Because wizlist was seeded
before registration, the account came out of registration already with
wizard view; verified `update /d/quanzhou/tieqiang` → 成功 on re-login.
**Save files for the orchestrator to force-add:
`libs/bixiecanyang/work/data/user/f/fluffos.o` and
`libs/bixiecanyang/work/data/login/f/fluffos.o`** (untracked dirs).

Retest: fresh normal registration (id `ceshisan`, name 秦风, female)
end-to-end into the world, look/score/quit correct, 0 new errors in
debug.log; test char saves removed.


## Retrofit (2026-07-24): fail-closed loopback check (security correction)

The loopback-allow gate patched above originally also treated a
non-string/empty/malformed `query_ip_number()` result as loopback (a
defensive stand-in for the WASM driver bug). That driver bug is now fixed
upstream, so this was tightened to fail-closed: only an exact
`"127.0.0.1"` / `"127."`-prefix / `"::1"` match bypasses the gate; a
malformed or non-string address now falls through to the original gate
logic (treated as untrusted/remote) instead of being auto-allowed.
Re-verified fluffos login still works after tightening.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

基于"夕阳再现"衍生引擎的独立游戏。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：一次完整的 WASM 注册流程（英文 id 仅限小写字母 → 确认 → 中文名字 → 管理密码+确认 → 登录密码+确认 → 天赋摇点，0 为随机 → 接受 → 电子邮件，需 id@address 格式 → 性别）全程无错误地进入"武庙"起始区域（"你连线进入这个世界，开始了自己的江湖生涯"），预先播种的管理员账号（fluffos/Mud@2026）也能正常登录（"您目前权限：(admin)"）。

## 深度功能测试（第二轮，2026-08-04）

按 §10.7 方法论用原生 driver（端口 40065）跑了一遍超出注册流程的完整游玩
——移动、战斗、死亡/复活体系，并在此过程中主动核对了 AGENTS.md 已归档
的几类高发 bug。

**主动检查命中 3 处，全部在 `adm/daemons/logind.lpc` 里**：

1. `printf("%O\n", ob)`（§7.34）——随机接受姓名的分支，紧挨在
   `ob->set("name", Rname);`（"请设定您的管理密码："提示之前）。
2. `printf("%O\n", ob)`（§7.34）——手动输入姓名的分支，同样紧挨在
   `ob->set("name", arg);` 之前，与上一条是同一 bug 的两条平行路径
   （加入 AGENTS.md §7.34 的"两条平行路径"分组，与 `hc`/`yxjh`/
   `xkyx3b`/`mnhf` 同类）。
3. `if (ob->query("age") == 14) { ... }`（§8.9）——`user->setup()` 之后
   的食物/饮水初始化判断，用的是登录桩对象 `ob` 而不是玩家本体
   `user` 的 age（只有 `user` 会在 `update_age()` 里被设成 14），错的
   对象上永远读不到 14，食物/饮水永远不会走到这段初始化逻辑里。这是
   AGENTS.md §8.9 的第五个独立血统实例（前四个是 cctx/niaoren 共祖对、
   yxjh、ldtxii/ldtx 共祖对），用的是 `yxjh` 那种精简写法（裸
   `if`，没有额外的 `!user->query("food")` 门槛）。

三处一次性改完，跑了 formatter（首次接触触发全文件重排版，用
`git diff | grep -B2 -A2 "printf\|query(\"age\")"` 核实过只有这三处语义
改动，其余全是空白/大括号风格规整）。修完后注册新角色食物/饮水条显示
满格（16/16），确认 §8.9 修复生效。

**注册流程本身有几个容易搞反的细节**（本轮踩过坑，供后续参考）：
双密码系统里，第一组输的是"管理密码"（wizpwd），第二组才是真正登录
用的"普通密码"——用第一组去登录会被强制要求重设普通密码
（"您输入的是管理密码，请重新设定您的普通密码"）；天赋分配菜单要走
"0"（系统随机）再 "y"（确认接受），漏掉任一步都会卡在原地重问。

**游玩内容**：注册成功的测试角色（沐豪侠 / id `bxcyfu`）从"北疆小镇"
出发，逛了赛马场（"姑娘追"维吾尔族特色内容）、草原、峡谷——沿途遇到
的 NPC 全是 `attitude` "friendly"，`fight` 指令一律被判定不同意开战。
确认 `kill` 指令能绕开这层 friendly 同意门槛，对赛马场的"阿拉木罕"
（combat_exp 5000）直接 `kill`，触发了一整套战斗流程并以测试角色死亡
告终。

**死亡后发现死亡/复活系统与 `bmxkx2001`/`yszz` 同宗**：死亡后被送到
"鬼门关"，NPC 是"白无常"，判词、场景描述、`death_stage()` 的多阶段
`call_out` 结构与 `d/death/npc/{wgargoyle,bgargoyle}.lpc` 几乎逐字一致
——这是 AGENTS.md §7.68 已归档的复活软锁死 bug 类的又一实例。核对
`wgargoyle.lpc`/`bgargoyle.lpc`，两个文件都是同样的
`if (!ob || !present(ob)) return;`——只要复活序列进行中的任意一瞬间
`present(ob)` 判假（哪怕只是暂时不在场，不是真的走了），整个复活流程
就会被无声永久放弃，角色卡成鬼魂再也无法复活，没有任何报错提示。

按 §7.68 已验证过的修法，把守卫拆成两段：`!ob`（对象真的已销毁）才
永久放弃；`!present(ob)`（此刻只是不在场）改为 5 秒后重试同一阶段，不
再放弃。两个文件应用完全相同的改法，formatter 跑完确认 diff 干净（各
`9 ++++++++-`，非全文件重排）。

**验证**：重启 driver 让改动生效后，用新一轮 `kill guo jing`（郭靖，
北大街的另一个高战力 NPC）复现了一次死亡，角色被送到鬼门关的白无常
处。这次没有主动制造"复活序列进行中被挪走"的中断场景（不像
`bmxkx2001` 当时是被一个无关 NPC 的强制移动撞上），而是让连接在等待
过程中断线重连——`call_out` 链本来就不依赖网络连接是否在线，所以这个
测试严格来说只验证了"正常、未被打断"路径在改动后仍然完整走完：断线
期间复活序列在服务端自行跑完，重新连线时角色已经复活、站在起始房间
"武庙"，`score` 显示"你共死亡：1 次"、精/气条降到一半（符合死亡惩罚），
食物/饮水满格，没有任何异常。也就是说，这个具体实例上的修复是照搬
已证实的 bug 类模式应用的，没有在 `bixiecanyang` 里独立复现出"中途被
打断导致永久卡死"的原始故障场景——诚实记录：如果以后有更方便强制
挪动鬼魂 NPC 的手段，值得回来专门验证一次中断场景。

`git status --short libs/bixiecanyang/` 复查干净：只有三个源文件的修改
是跟踪变更，测试角色的新存档（`data/{user,login}/b/`）保持未跟踪状态，
未纳入提交（沿用本项目约定，测试角色存档不提交，只有预置的 fluffos
管理员账号存档例外）。


## 更正（2026-08-05）：§7.68 复活软锁"修复"已撤销

上面提到的"鬼魂离开/不在场时被永久放弃复活流程"曾被当作 AGENTS.md
§7.68 记录的一类 bug 修复（把单次判定改成每 5 秒重试）。经用户指出并
重新审视：这更可能是**有意的游戏设计**，不是 bug——大多数这类档案里
鬼魂根本无法自行移动，所以"不在场"要么从未真正发生，要么是"离开去
在阴间游荡，想回来时再走回这个房间、流程会通过 init() 重新从头开始"
这种有意为之的宽松机制，而不是需要强制追上玩家的错误。强行重试还可能
引入新问题：如果鬼魂之后又走回这个房间，旧的重试和 init() 重新触发的
新一轮流程可能同时运行，导致对话重叠错乱。已把这处改动撤销，恢复成
原始的 `if (!ob || !present(ob)) return;` 单次判定写法（`bmxkx2001`
除外——那份档案里这确实是一个真实存在、经过实际复现验证的 bug：鬼魂
本身完全无法移动，是另一个不相关的 NPC 强行把鬼魂拖走导致的）。详见
AGENTS.md §7.68 顶部的撤销说明。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 100 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-14，round two，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，逐项独立核对了本 session 新确立的检查
项（不只是信任 NOTES.md 已有记录）：`log_error()` 确认已经有更精
细的巫师/玩家分流+严重度判断（§15af 记录的修复）；§8.9、printf 泄
漏、§7.68 撤销均确认代码状态和记录一致；`feature/dbase.lpc` 未发
现密码写保护，不适用 tybxjh/wlhd 那一类 bug；`win_times` 的
`%`-operator 也已用 `to_int(query("win_times")) % 5`
（`d/city2/npc/refereew.lpc:146`）。

### 本轮新发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护（AGENTS.md §7.11-class）**：已加上前向声明
   + `assure_file(LOG_DIR + file);`。
2. **`cat()`（同一文件）对不存在文件的空指针式崩溃，主动加固**：
   未在本档案现场触发，属主动加固，改成 `write(read_file(file) ||
   "");`。

### 实测过程

管理员 `fluffos`/`Mud@2026`（此前已注册，`(admin)` 权限此前已确
认）真实重连两次：第一次专门用 `update /adm/simul_efun/file` 确认
写权限仍然生效（"重新编译 /adm/simul_efun/file.lpc：成功！"），第
二次单独验证密码重连本身。均成功登录，存档数据一致。全程
`debug.log` 无运行时错误。驱动按精确 PID 结束；测试期间产生的存
档时间戳增量已 `git checkout --` 还原。

## Round three deep functional test (2026-08-18)

Registered a fresh character (`killguoj`) and ran it through a full
死亡/复活 playthrough — combat kill by a `d/death/npc/{bgargoyle,
wgargoyle}.lpc` (鬼门关) death sequence — with a deliberate mid-chain
disconnect/reconnect, mirroring the reconnect-race scenario documented
in AGENTS.md §7.112.

### Bug found and fixed: AGENTS.md §7.112 (duplicate `death_stage()` call_out chain on reconnect)

Both `d/death/npc/bgargoyle.lpc` and `d/death/npc/wgargoyle.lpc` had the
textbook vulnerable shape: `init()` unconditionally scheduled a 5-stage
`death_stage()` `call_out` chain with no re-entry guard. Because
`enable_commands()` re-broadcasts `init()` to every object in the room
and this lib's `clone/user/user.lpc::reconnect()` calls
`enable_commands()` on every reconnect, any ghost sitting in 鬼门关 who
reconnects even once mid-sequence would get a second, independent copy
of the whole chain stacked on top of the first — the two chains racing
to move/reincarnate the player, potentially double-applying the death
penalty or misrouting the revival.

Fix (matches the reference shape from `dtsl`/`sj`/`yueyingqiyuan` etc.
in §7.112): added a per-victim `set_temp("death_stage_active", 1)` /
`query_temp(...)` guard around the `call_out()` scheduling in `init()`,
cleared at every exit point of `death_stage()` (early return on
`!present(ob)`, the aggressive-living-player branch, and the final
reincarnation branch).

**Live-verified**: registered `killguoj`, walked to 铁枪庙, picked a
fight with 乌鸦 to die, landed in 鬼门关 with 白无常
(`wgargoyle.lpc`). Deliberately dropped the connection ~2s after the
death-stage chain had already started, then reconnected as the same
character mid-chain (which re-triggers `init()` via
`enable_commands()`). Post-fix behavior: each of the 5 `death_msg[]`
lines appeared exactly once, in order, 5 seconds apart, with no
interleaving or duplication; the final stage reincarnated the character
exactly once (moved to 武庙, `startroom` reset, inventory dropped) and
`score` afterward showed "你共死亡：1 次" — a single, correctly-counted
death, not a doubled one. Confirms the guard suppresses the duplicate
chain without breaking the normal single-chain path.

### Standing round-three checklist — other items checked

- **§7.111** (`master.lpc` `standard_trace()` crash on `error["object"]
  == 0`): already fixed in this lib — `adm/obj/master.lpc:221` already
  guards with `objectp(error["object"]) ? file_name(error["object"]) :
  "<none>"`. Clean, no action needed.
- **§7.113** (netdead reconnect never restores `heart_beat`): checked
  the real reconnect path (`adm/daemons/logind.lpc::reconnect()` →
  `clone/user/user.lpc::reconnect()`). Unlike `shzs`, this lib's actual
  reconnect function correctly calls `set_heart_beat(1)`
  (`clone/user/user.lpc:198`), matching its `net_dead()`'s
  `set_heart_beat(0)`. Clean, not applicable.
- **§7.90** (eval-cost too low for this lib's NPC-creation cost):
  `config.fluffos` already sets `maximum evaluation cost : 50000000`,
  far above the 700000 template default that triggers this class of
  bug. No `cost limit reached` aborts observed anywhere in this
  session's testing (combat, room movement, death, reincarnation, two
  full reconnects). Clean, not applicable.
- **§7.11 nosave-dir pattern / logind.lpc save path**: this lib's
  `log_file()` simul_efun was already hardened with `assure_file()` in
  the round-two pass above, so every `log_file()` call site in
  `logind.lpc` (registration id-creation log, etc.) is covered.
  Separately checked `adm/daemons/toptend.lpc::topten_save()`'s
  unguarded `write_file(f_name, ...)` (the `nitan_ceshi`-class
  non-fatal §7.11 variant) — its target directory `/topten/` ships with
  the archive and is present (`rich.txt`, `exp.txt`, etc. all exist), so
  this write path is not broken here. `logind.lpc`'s other
  `write_file()` calls (`users`, `maxonline`, `iduser` counters) target
  its own `adm/daemons/` directory, which obviously exists. Registration
  itself was live-verified working end-to-end (new character reached
  `score` successfully). Clean, not applicable.

### Test hygiene

Driver ended by exact PID. Test-character save files (`killguoj`,
`deathtst`, `deathwu` and their `.o` twins under `data/{login,user}/`)
were left untracked and deleted, not committed — only the two source
fixes (`bgargoyle.lpc`, `wgargoyle.lpc`) are part of this commit, per
this project's convention that test-character saves never get
committed.

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 5241
处独立、未注释的 replace_program(ROOM); 整行。另外手工清理了造房工
具代码生成模板里内嵌的同一形状，本库有两份完全同形状的拷贝
（`clone/misc/roommaker.lpc`、`u/fyue/misc/roommaker.lpc`，各 1 处
字符串拼接，和同一 XYZX 血统的 longyunmeng/xyzxfk/xyzx 完全一样的形
状）。删除总计 5243 行，与本次扫描 FINDINGS.md 记录的 bixiecanyang
存活命中数完全一致。

验证：干净启动一次真实调试驱动，端口 40065 正常监听，
work/log/debug.log 全程无新增内容。用已播种的 `fluffos`/`Mud@2026`
管理员账号连线，在北疆小镇/巴依家庭院/巴依家客厅之间往返走了十余个
房间（含 NPC 互动），look/score/who 均正常（score 首次惰性编译
`adm/daemons/combatd.lpc` 打印了一条无害的 Unknown #pragma 警告，与
本次修复无关），未见任何 "cannot replace"/"cannot bind" 或崩溃迹
象。测试产生的 `data/{login,user}/f/fluffos.o` 存档时间戳 diff 已
`git checkout` 撤销，不提交。驱动按精确 PID kill。

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

## 深度功能测试（2026-09-04，round three，shop + 拜师）

新角度：醉仙楼购物 + 丐帮左全拜师。2026-08-04 / 2026-08-14 / 2026-08-18
三轮覆盖了注册、战斗、死亡/复活和 `log_file`，没有买东西、也没有拜师。
这是真正的夕阳再现/江湖风云血统（`d/city/sj.lpc` 与 `xyzx` 逐字节相同），
不是天涯家族；拜师路线仍是扬州树洞左全，不是华山。TOMUD 的 2060 握手
只在 `query_temp("tomud")` 时走 `get_version()`，标准端口 40065 第一
输入就是「请输入您的英文名字：」，不要发 2060。

### 实测过程

管理员 `fluffos` / `Mud@2026`（wizpwd `Wiz@2026` 不是登录密码）。落地
北疆小镇 `/d/xingxiu/beijiang`。游戏内时间是「盛夏的清晨」，醉仙楼
`F_DEALER` 在 night/midnight/dawn 会打烊，本轮赶上可买窗口。

`goto /d/city/zuixianlou`，`list` 烤鸡腿八十文钱 / 牛皮酒袋一两白银 /
包子五十文钱（`jitui` `value` 80，不是 `xyzxfk` 那种八十两黄金标价）。
`clone /clone/money/gold` 后 `buy jitui` 成功（「你向店小二买下一根烤
鸡腿」）。当场 `i` 就是九十九两银子 + 二十个铜板 + 烤鸡腿，黄金条目
已消失（找零 10000−80 = 9920）。`F_DEALER` 对丐帮拒绝购买（穷叫化），
必须先买再拜。

`goto /d/gaibang/inhole`，左全源码是 `kungfu/class/gaibang/zuo-qu.lpc`
（文件名少一个 n），`apprentice zuo` 一次成功：左全收徒，`score` 「丐
帮第二十代弟子」、师傅左全。`cmds/usr/save.lpc` 真正调用两个 `save()`
（60 秒内再 save 会假「档案储存完毕」不写盘，本轮只 save 一次）。
`user.o` 立刻带上 `family_name":"丐帮"` / `master_name":"左全"` /
`generation":20`。断线后再连（「重新连线完毕」），称谓/师傅/银子还在。
左全只收男性。烤鸡腿未进 autoload 列表（身上还在是因为这次是 linkdead
重连，不是冷启动读档）。

本轮没有新的 programming bug。巫师账号登录时 `score` 刷了一条
`combatd.lpc` Unknown #pragma，是 2026-07-23 §15af 已记录的「巫师看全
部诊断、玩家只看真正错误」分流，不是漏网。live `debug.log` 是
`libs/bixiecanyang/log/debug.log`（Boot Time Fri Sep 4 02:01:32 2026），
无 `error:` / `Too deep recursion`。`error_handler` 把轨迹交回驱动
debug.log。`work/log/log` 只有编译期 pragma/unused 警告；`move.bug`
停在 2026-07-22。管理员存档未提交。

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 3 here-document block(s) repaired (3 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/heimuya/shenggu.lpc`, `d/heimuya/tang.lpc`, `d/heimuya/npc/tang.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply bixiecanyang`: 1 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 2 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 0 PASS -> 2 PASS, 0 that loaded before fail now, 2 more load.

1 files moved (1 `.C`); mostly under `d/city/npc` (1). A rescan with `scripts/lpc_warnings.py bixiecanyang` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— tail() simul_efun

`scripts/lpc_add_tail.py --apply`: `cmds/app/tail.lpc`, `cmds/wiz/tail.lpc` call `tail(file)`, an efun of the MudOS this archive ran on that FluffOS does not have (`Undefined function tail`: the command did not compile). `adm/simul_efun/file.lpc` now defines `void tail(string file)`: the last 10 lines of the file, written to the player. Load check (HEAD against the working tree): 1 of the 2 tail command file(s) failed to load at HEAD, all load now, and the simul_efun file loads. KB 04 §6.2.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`d/obj/quest/dynamic_location`、`d/obj/quest/dynamic_quest` 里 86 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/questd.lpc`、`u/fyue/questd.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 1 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：2 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成；`cmds/std/look.lpc` 夜间检查的 `!present("fire", this_player())` 前加 `objectp(this_player()) &&`（房间 `reset()` 销毁物品时 `/feature/move.lpc` 的 `remove()` 会调用 `look_room()`，此时没有 this_player()，`present(…, 0)` 报 `Bad argument 2 to present()`）。
验证：`adm/daemons/questd.lpc`、`u/fyue/questd.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 2 个，工作树三次分别通过 2、2、2 个（共 3 个），无回退；`u/fyue/questd.lpc` 在 HEAD 与工作树都加载失败，另有原因，与本次无关。
验证：改动过的 `adm/daemons/questd.lpc`、`cmds/std/look.lpc`、`u/fyue/questd.lpc` 在新进程里加载，HEAD 通过 2 个、工作树通过 2 个（共 3 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 空的 `if (current_water == 0) {}`

5 个房间的 `valid_leave()` 里有一行什么也不做的 `if (current_water == 0) {}`（编译警告 `Expression has no side effects`），删去，行为不变：`d/gaochang/room11.lpc`、`d/gaochang/room12.lpc`、`d/gaochang/room13.lpc`、`d/gaochang/room14.lpc`、`d/xingxiu/shanjiao.lpc`。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py bixiecanyang --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 528 个 `.lpc` 和 4 个 `.h`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：474 -> 474 通过，无回退；改过的头文件的 39 个包含者 39 -> 39 通过。启动时警告 8 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 4 处比较、1 处去后缀（如 `cmds/imm/ls.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：`/u/snow/wudujiao/mishi.lpc` 的技能判断用按位 `&` 连接两个比较（如 `tjss > 10000 & taoism > 10000`），改为逻辑 `&&`。两边都是 0/1 比较结果，行为不变，只是写法纠正。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 29 处，返回类型/原型 36 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 2 个文件；改动 63 个文件，HEAD 与工作树各载入一次无回退（63 objects; HEAD PASS 53, tree PASS 53; regress 0; newly loading 0），这些文件的警告 67 -> 0。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 8 处，`F_CLEAN_UP` 等在基类之外又直接继承一遍）后手工补两处，能编译的文件警告清零。改动的 10 个对象 HEAD 与工作树各载入一次：HEAD PASS 7，tree PASS 7，regress 0。

- `u/isle/ToMud/tomud.h`（巫师的 ToMud 客户端协议试验目录）有意把 `TMA`/`TMB` 从客户端控制字符 `\\x19`/`\\x1A` 换成可见的 `*`，与全局 `include/tomud.h` 撞名；文件头加 `#undef TMI`/`TMA`/`TMB`，取值不变。
- `kungfu/skill/huashan-jian.lpc` 招式表后多余的 `;`。

- 2026-10-15：`kungfu/skill/guangming-blade.lpc`（光明刀法）是从五虎断门刀抄来的，`query_action()` 里仍按 `wuhu-duanmendao` 的等级挑招式：没练五虎断门刀的人出招时一招都匹配不上，`a_action` 为 0，接着赋值报错。改为按 `guangming-blade` 自己的等级。（武功运行期探针发现。）

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。13 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。10 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 8 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 6 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。


## family 映射（补）（2026-10-15）

`mapping fam = (mapping)me->query("family");`（带类型转换的写法）同样直接取下标，1 处补上 `if (!mapp(fam)) fam = ([ ]);`。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。5 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。


## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/kungfu/condition/sanpoison`。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。4 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## `find_player()` 只认在世界里的身体（2026-10-15，KB 07 §8.26）

simul_efun 的 `filter_player()` 加上 `environment(ob)`：注册中途断线留下的、不在任何房间的身体不再被当成玩家，两个以上时 `find_player()` 不会再报 `The player(<id>) has existed in the world.`（wllz3 实测过的问题）。本库若注册流程不会留下带玩家 uid 的身体，这一改动不改变行为。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`dagou-bang/ban`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

当前内力、精这类名字有时指的是内功技能，逐处读过后手改：落英缤纷 `luoying-shenjian/lybf`：自己的注释说成功率由“精神高低”决定，两处 `query_skill("jing")` 改为 `query("jing")`。

## 碧海生潮曲空手报错（2026-10-15，KB 06 §7.246）

`iceforce/roar`（碧海生潮曲）先 `ob = me->query_temp("weapon")`，再直接拿 `base_name(ob)` 判断是不是玉箫；空手 `exert roar` 时 `base_name(0)` 报错，提示“你必须先找一只玉萧来才可以吹－－曲”根本出不来。条件前补 `!objectp(ob) ||`。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/npc/obj/shu1`、`/d/mr/obj/shu1`）；`beimin-shengong`→`beiming-shengong`（`/d/quanzhen_old/kungfu/skill/xiantian-qigong`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`mizongxinfa`→`mizong-xinfa`（`longxiang/fanchang`）；`yihua-jimu`→`yihua-jiemu`（`yihua-jiemu`）；`zhenfen-xinfa`→`zhenfeng-xinfa`（`zfwy-bu`）。

## 文件首行注释少了一个斜杠（2026-10-15）

首行的说明注释只剩一个 `/`（如 `/kuangwu.c金蛇狂舞`、`/ cloth.txt  //`），文件第一行就语法错误、编译失败：全真教的布衣 `/d/quanzhen_old/obj/cloth` 因此从来载入不了。补回斜杠成为 `//` 注释，现在都能载入。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`hujian-daofa`→`hujia-daofa`（`hujia-daofa`）；`jinggang-quan`→`jingang-quan`（`jingang-quan`）；`xuantie-jiafa`→`xuantie-jianfa`（`xuantie-jianfa`）；`xuanxie-jianfa`→`xuantie-jianfa`（`xuantie-jianfa`）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。8 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 用兵器的绝招空手施展时报错（内联写法）（2026-10-15，KB 06 §7.246）

绝招不存兵器变量，直接写 `(me->query_temp("weapon"))->query("name")`（或在拒绝判断里写 `(weapon = me->query_temp("weapon"))->query("skill_type")`），之前又没检查兵器：空手 `perform` 时报 `Bad argument 1 to EFUN call_other()`，内力等往往已经扣掉。在第一次用到它的那条语句前补上“你必须手持兵器才能使用这一招”的拒绝（`scripts/lpc_fix_perform_weapon.py`）：`yunv-jian/suxin`。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`、`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `load_object()` 找目的地，找不到就返回 0，不报错，东西留在原处：被雇来打晕或杀人的李凌（`d/city2/npc/liling2`）办完事后没有离开，留在原地；婚礼结束（`d/nanyang/npc/meipo` 的 `last_marry`）时月老没有离开喜堂，每办一次婚礼喜堂里就多一个月老；喜宴结束后喜来福（`d/nanyang/npc/xi-laifu`）没有退回内堂，每办一次婚礼迎宾楼就多一个喜来福。3 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 玉女剑法「合壁」用一次就永久改动经验和剑法（2026-10-15，KB 06 §7.253）

收尾的 `hebi()` 声明时没有参数（`void hebi() { object me, target, env; int i, j, o, p, count; ...`），call_out 传进去的人和数值全被同名的局部变量（0）挡住，开头的 `if (!me && !target) return;` 每次都返回：合壁的攻击、闪避加成和 `hebi` 标记要到重新登录才消失。更糟的是夫妻判断写成了 `target->querry("id")`（没有这个函数，得 0），没成亲的人 `marry/id` 也是 0，于是人人都被当成夫妻：自己的玉女剑法和经验乘以玉女素心功的级数/80（至少变成浮点数，160 级以上翻倍），随后给对方 `set_skill("combat_exp", ...)` 时报 `No such skill`，收尾的 call_out 也就没排上，乘过的等级和经验永远不还原。测试里用一次合壁，经验 100000 变成 200000.0、剑法 100 变成 200.0。改正：`hebi()` 按它自己再次 call_out 时传的八个参数声明，`perform` 的 call_out 去掉多余的 `h, k`，`querry` 改为 `query`，给对方的 `set_skill("combat_exp")` 改为与上一行一样的 `set("combat_exp")`。测试里加成照常生效，`hebi()` 结束时还原并清除标记，没成亲的人经验和剑法不变。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

5 个文件、10 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/obj/cloth/cloth`、`/obj/weapon/blade`、`/d/gumu/obj/fuchen`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 5 个（5 个原来载入不了），没有退步。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/usr/inventory2.lpc`、`feature/move.lpc`、`feature/move2.lpc`、`feature/复件 move.lpc`。

## 去掉的预定义宏 `SAVE_EXTENSION`（2026-10-18，KB 04 §6.11）

老版 MudOS 给每个 LPC 对象预先定义了 `SAVE_EXTENSION`（`".o"`）；FluffOS 的 ChangeLog（COMPAT_BUSTER 一条）把它删了，改用 `__SAVE_EXTENSION__`。本库没有自己 `#define` 这个宏，用到它的文件一律 `Undefined variable 'SAVE_EXTENSION'`，整个对象载入不了。改成 `__SAVE_EXTENSION__`（`scripts/lpc_fix_predefined_macro.py`）：`adm/daemons/network/netmail.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang3.lpc`。`tang3`/`tang`/`meng-zhu` 是武林盟主一类的 NPC，原来一个都载入不了；`netmail` 是网络邮件守护进程（本库缺 `mailer.h` 等头文件，改后仍载入不了）。改后用 `lpcc` 逐个载入这些对象：2 个通过，1 个还有别的错误（`adm/daemons/network/netmail`：/adm/daemons/network/netmail.lpc:17: error: Cannot #include mailer.h）。


## 水潭里 `ging_cost` 是 `jing_cost` 的笔误（2026-10-18）

`shuitan` 先算 `jing_cost`，倒水时却扣 `receive_damage("jing", ging_cost)`，`ging_cost` 从没声明过：`Undefined variable 'ging_cost'`，整个物件载入不了。改成 `jing_cost`：`d/shaolin/npc/obj/shuitan.lpc`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 全真心法 `valid_learn()` 里没声明的 `lvl`（2026-10-18）

`kungfu/skill/quanzhen-xinfa.lpc` 的 `valid_learn()` 判断 `me->query("gender") == "无性" && lvl > 49`，可是函数里只有 `nk`、`nf`、`nh`、`ns` 四个变量，没有 `lvl`：`Undefined variable 'lvl'`，这门心法的文件载入不了，学它、用它都失败。`nh` 正是全真心法的等级（`nh = query_skill("quanzhen-xinfa", 1)`），改成 `nh > 49`。改后用 `lpcc` 逐个载入这些对象：1 个通过。


## 武林盟主类 NPC 的存档里 `weapon`／`armor` 是个 mapping（2026-10-18）

盟主、`fa-e`、`shang-shan`、`tang3`/`tang2`/`xingtang` 这几个 NPC 在 `create()` 里 `restore()` 之后直接 `carry_object(query("weapon"))`。换盟主时 `do_recopy()` 把玩家整个 dbase 抄进来，玩家的 `weapon` 若是自制兵器的 mapping，存进 `data/npc/*.o` 以后下次载入就是 `new(mapping)`：`Bad argument 1 to EFUN new()`，NPC 载入失败。本库的存档里确实有这种 mapping。两行都加 `stringp()` 判断，mapping 时不拿武器（NPC 空手）：`clone/npc/fa-e.lpc`、`clone/npc/meng-zhu.lpc`、`clone/npc/shang-shan.lpc`、`d/quanzhou/npc/tang3.lpc`、`d/taishan/tang2.lpc`、`d/taishan/tang3.lpc`、`d/taishan/xingtang.lpc`。改后用 `lpcc` 逐个载入这些对象：7 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 6 个对象设了本库没有文件的武功（9 个名字，最多的是 `hunyuan-force`、`ruyi-blade`、`taxue-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：6 个里 6 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 27 处、25 个文件：`kunlun-shnfa`→`kunlun-shenfa`（4 处）、`yan-fly`→`yanfly`（3 处）、`xinxiu-duzhang`→`xingxiu-duzhang`（2 处）、`tiaji-jian`→`taiji-jian`（2 处）、`kongmingquan`→`kongming-quan`（2 处）、`shaolin-shnfa`→`shaolin-shenfa`（2 处）、`taiji-shenfong`→`taiji-shengong`（2 处）、`lingbo-weibu`→`lingboweibu`（2 处）等共 16 个名字。（`scripts/lpc_fix_skill_names.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## 删掉 exert_function(整数)（2026-10-19，KB 06 §7.266）

`/d/player/ltsh/npc/saveme.lpc` `create()` 里的 `exert_function(10);` 把整数传给了要字符串的直接调用（让 NPC 闲聊时自己运功），驱动报 `Bad type for argument 1 of exert_function ( string vs int )`，整个 NPC 载入不了。这是存档里的笔误，不知道作者想传哪个字符串，删掉这一句（只影响闲聊时的运功表现）。chidi 的同一个 NPC 早先就是这样处理的。

## 找不到父类函数的 ::fn() 调用（2026-10-19，KB 06 §7.259）

`/d/city3/jiulou2/obj/food.lpc`共 1 个物件里写着 `::create();`、`::init();` 这类调用，而它们继承的基类并没有这个函数。老驱动把这种调用当成什么都不做、返回 0 的空调用，本驱动在编译时报 `Unable to find the inherited function 'init'.`，整个物件载入不了。这些物件的错误只有这一种（其他错误清掉之后才露出来的），逐个删掉这些调用（`return ::fn(...)` 改成 `return 0;`）。（`scripts/lpc_fix_dangling_super.py`）

## 区域物件的零碎修正（2026-10-19，KB 06 §7.267–§7.271）

- `/d/board/mingjiao_b.lpc` 的 `location` 从不存在的 `/d/mj/guangming-ding` 改成 `/d/mingjiao/guangming-ding`（载入明教留言板失败会让光明顶房间载入不了）
- 5 个 NPC 文件、5 处 `create()` 里的 `this_player()->carry_object(` 改成 `carry_object(`（没人在场时 `this_player()` 是 0，NPC 载入不了；有玩家在场时衣服武器落到玩家手里）

逐个物件与 HEAD 对比载入，没有退步。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 5 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/quanzhen_old/obj/allow-letter.lpc`、`/d/quanzhen_old/obj/greenrobe.lpc`、`/d/quanzhen_old/obj/greyrobe.lpc`、`/d/quanzhen_old/obj/hanzhu.lpc`、`/d/quanzhen_old/obj/shenmu.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板被 NPC 带上（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_club.lpc`、`/d/npc/m_weapon/weapon/m_sword.lpc`（共 2 个）的 `create()` 用 `this_player()` 读打造数据（`me->query("weapon/lv")` 等）。NPC 的 `weapon` 属性是兵器文件名（字符串），NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板时，`set_desc()` 里 `switch (w_lv)` 拿到的是那个字符串，驱动报 `Bad argument 1 to switch`，房间和 NPC 都载入不了（旧驱动里 switch 落到 default）。把 `if (me) {` 改成 `if (me && mapp(me->query("weapon"))) {`，玩家打造的流程不变。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/m_weapon/weapon/m_hammer.lpc`、`/d/npc/m_weapon/weapon/m_staff.lpc`、`/d/npc/m_weapon/weapon/m_whip.lpc`、`/d/quanzhen/npc/obj/m_sword.lpc`、`/d/quanzhen_old/npc/obj/m_sword.lpc`（共 5 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/baituo/npc/obj/bowl.lpc`（cctx）、`/d/baituo/obj/bowl.lpc`（jhfy3）。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 玩家买店用的 `feature/vendor_sale.lpc` 补回（2026-10-19，KB 03 §4.6 第四轮）

`/feature/vendor_sale.lpc`（`/kungfu/class/npc/xiaoer.lpc` 继承它）从 `pay_back` 起约 160 行的行尾丢了最后一个字符（`;` `)` `{` `}`，`else {` 只剩 `els`，`msg` 只剩 `ms`），另有一行 `if(wizardp(who) || getuid(who)==owner_id)` 被拼进了前面的 `log_file(` 调用里。文件载入失败，继承它的物件也跟着失败。别的库（ldtx、ldtxii、xhcii、syxjl、hy3）里有这个文件的完好副本，但那是另一个版本：没有作者后来加的投标公告（`string mesg;` 和 `message("channel:chat", ...)`）。所以按完好副本补回丢失的字符（`scripts/lpc_restore_from_twin.py --diff --extra`），公告两段原样保留；被拼到别处的 `if(...)` 放回完好副本里它所在的 `write("\n盈利` 之前；`message_vision("channel:chat", ...)` 多出来的第一个参数删掉（`message_vision` 的签名是 `(string, object, object)`，每次 `bid` 在扣完款之后都会报错）。补完后文件和继承它的物件都能载入，没有警告，也没有退步（HEAD 上两个都载入失败）。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女对古墓弟子的机关暗门提示永远给不出来（5 处）；孙婆婆的“你去吧”只对 class 没设置的人生效；性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/class/gumu/long.lpc`（5 处）、`/kungfu/class/gumu/sunpopo.lpc`（1 处）、`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）。

## 行编辑器指令编译失败：`(: this_object(), ({ "do_to", me, arg }) :)`（2026-10-20，KB 06 §7.284）

`Illegal to use local variable in functional.`：call_other 形式的函数指针 `(: ob, ({ "函数", 参数 }) :)` 的数组里只能是常量，写了局部变量 `me` / `arg` 整个指令就编译不过，`to` 这类先开编辑器、再回调自己的指令因此从未能用。改成 `(: call_other, this_object(), "do_to", me, arg :)`（参数在建立指针时绑定，编辑器再把输入的文字接在最后，`do_to(me, arg, text)` 收到全文；`scripts/lpc_fix_functional_locals.py`）。改动：`/cmds/wiz/to.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/d/migong/obj/npc1.lpc`、`/inherit/char/npc.lpc`（共 2 个文件）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/wiz/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（3 个文件）：`/cmds/adm/recover1.lpc`、`/cmds/arch/blockade.lpc`、`/cmds/arch/recover1.lpc`。

## `obj.h.es2`：`blockade` / `recover` 包含的头文件档案里没有（2026-10-21，KB 04 §6.23）

`blockade.lpc`、`recover*.lpc` `#include <obj.h.es2>`（`OBJ_*`、`NPC_*` 路径的 ES2 头文件，hy5、xkx100 等 33 个库带着），本库的 include 目录没有它，这些指令从来编译不了（`Cannot #include obj.h.es2`），`data/keep` 的修补也无从生效。指令本身不用里面的宏；从同系的 xkx100 复制一份头文件，加载检查 HEAD 与工作树对照：3 个对象原来加载失败，现在通过，没有退步。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/std/actionavailable.lpc`（`sscanf`）。加载检查 HEAD 与工作树对照，没有退步。

## `socket`：`dump_socket_status()` 在本库没有（2026-10-21，KB 06 §7.291）

管理员扫描里 `socket` 指令（`/cmds/bos/socket.lpc`）编译不了：`write(dump_socket_status());` 用的是 MudOS 有、本驱动没有的 efun。2026-10-20 的补丁只按名字找了巫师目录里的同名指令，这一条在 `cmds/bos`、`cmds/hufa`、`cmds/island`、`cmds/ser` 这类目录里；用 `scripts/lpc_add_sefun.py dump_socket_status` 在 `/adm/obj/simul_efun.lpc` 末尾补了一个由 `socket_status()` 构造表格的 simul_efun（没有 sockets 包的构建，比如 WASM，只打印表头）。指令 HEAD 编译失败，现在通过。

## 睡袋：`/cmds/adm/bag` 本库没有，使用者被留在聋哑状态（2026-10-21，KB 06 §7.344）

`clone/misc/sleepbag.lpc`、`sleepbag2.lpc` 的 `do_sleep()` 在设好 `block_msg/all`、`no_get` 和房间的 `sleeping_person` 之后调用 `"/cmds/adm/bag"->main(me, "<休息中>")`。这条巫师指令只有 hc、tianxiawuxue 带着，本库没有：`call_other() couldn't find object '/cmds/adm/bag'`，玩家之后什么消息也收不到（`look` 一片空白），十秒后的 `wakeup` call_out 没有排上，房间一直 `no_fight`。城里的小贩 `xiaofan` 卖这个睡袋，没有人在扫描里买过它。`bag` 的全部内容就是 `me->disable_player(msg)`（`feature/command.lpc` 里的 `nomask void disable_player(string type)`，没有权限检查），两个文件都改成直接 `me->disable_player("<休息中>");`。chidi 上实测：`sleep` 之后十秒 "你一觉醒来，只觉精力充沛"，`look` 正常（HEAD 上玩家被留在空白屏里，`log/debug.log` 有 trace）。改动：`/clone/misc/sleepbag.lpc`、`/clone/misc/sleepbag2.lpc`。

## 香烟 `smoke.lpc`：`do_smoking()` 读没赋值的 `me`（2026-10-21，KB 06 §7.348）

`smoke` 指令的第一句是 `jing = me->query("jing")`，`me` 声明了没赋值，每次抽烟都抛 `Bad argument 1 to call_other()`。补 `me = this_player();`（后面的 `this_player()` 调用不变）。改动：`/d/emei/user-room/melodies/smoke.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 32 条注册（32 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/d/changan/qinhuang/shidao5.lpc`（`do_train`）、`/d/city/chatroom2.lpc`（`do_jump`）、`/d/city/npc/wei.lpc`（`do_sell`）、`/d/city2/qishi.lpc`（`do_pass`）、`/d/city3/npc/sister.lpc`（`do_vendor_list`）、`/d/flypproom/npc/flypp.lpc`（`do_sell`）、`/d/npc/m_weapon/npc/jia.lpc`（`do_levelup`）、`/d/player/yysz/hupan.lpc`（`do_han`）、`/d/quanzhen/npc/haodatong.lpc`（`do_decide`）、`/d/quanzhen/npc/mayu.lpc`（`do_decide`） 等共 32 个文件。最多的函数名：`do_send` 15 处、`do_decide` 7 处、`do_train` 2 处、`do_sell` 2 处、`do_jump` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 2 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`room_event_fun()`（9 处调用）；`/adm/daemons/natured.lpc` ← chidi：`outdoor_room_outcolor()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 1 个函数没有补（item_desc 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/d/yihua/lianhuachi.lpc`:`look_CAI`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`"CAI": (: look_CAI :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 写死的 `"/路径"->函数()` 指向库里没有的文件：改成现存的同名文件（2026-10-22，KB 06 §7.359）

1 处语句级的 `call_other` 字面量路径，库里没有这个文件（区域改了名 / 大小写不对 / 差一个字母 / 文件挪了地方）：`"/d/mj/obj/baihong-jian"->move()`（`/d/mingjiao/npc/yingwang.lpc`）→ `"/d/mingjiao/obj/baihong-jian"`。`call_other()` 对不存在的对象抛 `couldn't find object`，所在函数当场中断。改成库里现存、并且定义了被调用函数的文件（`scripts/lpc_fix_call_path.py`；巫师目录、备份目录、名字不同的兄弟文件都不算候选）。 其中殷天正（白眉鹰王）的 `do_answer()`：玩家念对暗语（`answer 怜我世人，忧患实多；保护教主，同抗外敌`）时把白虹剑 `move` 给玩家，区域目录改名 `mingjiao` 之后这个路径没跟着改，回答暗语只得到 `couldn't find object`，剑永远发不出来。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 19 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 19 处（14 个文件）：拼名字的赋值 11 处、与汉字常量比较 8 处。例：`name[2..3]` → `name[1..1]`（`/kungfu/class/emei/jingxin.lpc:101`）；`name[0..1]` → `name[0..0]`（`/kungfu/class/shaolin/qing-fa.lpc:100`）；`name[0..1] == "慧"` → `name[0..0] == "慧"`（`/kungfu/class/shaolin/cheng.h:108`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：10 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 10 处（5 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 12)) {`（`/cmds/bakcmds/csc.lpc:611`）；`if ((strlen(name) < 4) || (strlen(name) > 30)) {`（`/cmds/usr/found.lpc:73`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 5 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 8 处（4 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## Beyond 出口仍指向 /u/beyond（2026-10-23，KB 06 §7.368）

宁波 / 苏州 / 慕容等区域已进 `/d/ningbo`、`/d/suzhou`、`/d/mr`、`/d/hz`，出口与任务物路径仍写 `/u/beyond/…`。`scripts/lpc_fix_beyond_exits.py` 在目标 `.lpc` 存在时改写（`murong`→`mr`）。本库 1 处。证明：sjplii `xikou` HEAD 西向 `/u/beyond/ningbo/aywsi`，改后 `/d/ningbo/aywsi` 可加载；bxsj `hubian1` 三向均可加载。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 4 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。

