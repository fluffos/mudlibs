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
