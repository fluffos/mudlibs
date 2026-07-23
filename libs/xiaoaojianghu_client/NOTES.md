# xiaoaojianghu_client — 「笑傲江湖」之「重出江湖」 (archive #76)

Archive: `笑傲江湖服务端+客户端.rar` ("Laughing in the Wind, server + client
bundle"). Port: **40070**. Status: **done** (boots clean, full registration
flow verified twice end-to-end including real post-login commands `look`
and `score`).

## Triage: client-vs-mudlib determination

Despite the archive's name suggesting a bundled player client (following
the precedent of archive #24, `TOMud_VC源代码.rar`, which really was
client-only), this archive is **genuine LPC mudlib source, no separate
client bundled at all**:

- The entire archive is one directory, `mud4/`, with a classic wuxia-mudlib
  layout: `adm/{daemons,obj,simul_efun,etc}`, `clone/`, `cmds/`, `d/`
  (rooms/zones), `feature/`, `inherit/`, `kungfu/` (skills/classes),
  `meskill/`, `quest/`, `topten/`, `data/`, `log/`, `doc/`, `include/` —
  12378 raw files, 11413 of them `.c` (LPC source).
- **No MFC/VC++/dialog/client-shaped files anywhere** — searched for the
  archive-#24 precedent's markers (`MainFrm.cpp`, `DialogXxx.cpp`,
  `*Sock.cpp`, `.dsp`/`.dsw`/`.vcproj`/`.sln`/`.rc`/`resource.h`/
  `stdafx.*`): zero hits. The only non-source binaries are two **prebuilt
  Windows MudOS *driver* executables** (`mud4/mudos22.exe`,
  `mud4/"new mudos.exe"`) — i.e. the "服务端" (server) half of the
  archive's name refers to these bundled driver binaries, not to anything
  we need (we use our own FluffOS build). Both ignored per the established
  "ignore bundled drivers" precedent.
- The "客户端" (client) half of the archive's name is explained by the
  bundled readme (`mud4/碧血残阳说明.txt`, the author's own writeup):
  this mudlib supports **two connection protocols on two different
  ports** — a plain telnet/ZMUD port and a "TOMUD" menu-client protocol
  port (`tomud连入端口：8888 / ZMUD连入端口：6666` per the readme) — i.e.
  "client" here means "which of the two wire protocols you dial in on",
  not a bundled GUI program. Confirmed live: `adm/obj/master.lpc`'s
  `connect(int port)` sets a cosmetic `"tomud"` temp flag when `port ==
  TOMUD_PORT` (`#define TOMUD_PORT 9999`); no separate client source
  exists anywhere to implement that protocol on the other end.
- A handful of files carry non-LPC extensions from what look like editor
  artifacts (`.java` × 15, `.vns` × 20 under `kungfu/skill/`, `d/heimuya/`,
  etc.) — inspected several; these are ordinary LPC/text content that
  happened to get renamed with an odd extension at some point in the
  archive's history (`mud4/clone/misc/mailbox.java` starts with normal LPC
  header comments, not Java), not a real Java/VNS client component. Left
  as-is (not part of the `.c`→`.lpc` rename scope either way).

**Conclusion: proceeded with the full standard conversion pipeline.**

## Lineage

**Not** related to any of the three existing "Laughing in the Wind" libs
(explicitly checked per task instructions, via `md5sum`/`diff` against
raw archives and directory-layout comparison):

- **`nitan6`** (archive #22): NT/nitan/Lonely lineage, `nitan/nitan/adm/
  kernel/...` layout. This archive uses `adm/{daemons,obj,simul_efun}`
  (no `adm/kernel/` at all) — structurally unrelated.
- **`xo`/`xo_final`** (archives #28/#29): TMI-2/ES2 lineage,
  `mudlib/secure/{system,daemon}` / `xo_new/secure/...` layout (a `secure/`
  tree). This archive has no `secure/` directory anywhere — structurally
  unrelated.
- Also cross-checked against `yanlongfengyin_xiaoao3` (archive #68, also
  themed 笑傲江湖 within the **夕阳再现** family this archive turned out to
  belong to, see below): different `adm/simul_efun/chinese.c` md5
  (`961d77af...` here vs `c7c5c596...` there), different `adm/obj/
  master.c` md5, and a very different file count (12378 raw here vs
  17380 there raw) — confirmed a distinct fork, not a duplicate.

**This archive IS a member of the 夕阳再现 (Xiyangzaixian)/"XYZX" lineage**
already established across archives #46 (`xiyangzaixian_fengkuang`), #47
(`xiyangzaixian_fengyun2`), #48 (`xiyangzaixian3`), #55 (`weimingkongjian`),
#59 (`jianghufengyun`), #68 (`yanlongfengyin_xiaoao3`), and #71
(`bixiecanyang`) — confirmed via the bundled readme (`碧血残阳说明.txt`,
titled "关于笑傲江湖－重出江湖的说明", explicitly self-identifying its
base as **"夕阳再现－江湖风云2－风云再起"**, credited to author "AKAI",
same author credited in bixiecanyang's own readme) **and** via `md5sum`:

- `adm/daemons/chinesed.lpc`: **byte-identical**
  (`fe293044de377c1fff169db903a6b2b3`) to `bixiecanyang`,
  `xiyangzaixian_fengkuang`, `xiyangzaixian_fengyun2`, and
  `jianghufengyun`'s copies.
- `adm/simul_efun/chinese.lpc` (the `is_chinese()` file): **byte-identical**
  (`961d77af057bb93db320af05be5883fc`) to `bixiecanyang`'s copy specifically.
- `adm/daemons/securityd.lpc`: **differs** from `bixiecanyang` (own md5
  `70fc2c07...` vs `032452f5...`) — this archive's own securityd is a much
  simpler ACL (`valid_read` unconditionally returns 1, no
  `exclude_read`/`trusted_read` tables at all) than bixiecanyang's/
  fengyun2's shared custom ACL.
- `adm/obj/master.lpc` and `adm/daemons/logind.lpc`: both differ from
  every sibling (own content, own line counts) — same pattern as every
  other fork pair in this family: shared low-level engine utility files
  (`chinesed`, `chinese.lpc`), fully independent site-specific
  daemons/game content otherwise.
- **`config.bxcy`** (the raw config filename) is again present here too,
  matching the same filename-convention fingerprint already noted for
  bixiecanyang/datangshuanglong — further (weak, config-template-only)
  evidence of the shared AKAI-lineage ancestry, not itself a content match.
  Content differs from bixiecanyang's own `config.bxcy` (different
  `name`/port/path fields, as expected for an independently-run site).

This archive's own in-game identity is **「笑傲江湖」之「重出江湖」**
("Laughing in the Wind" — "Return to Jianghu"), a *different*, independent
game-content fork within the same shared 夕阳再现 engine family — not a
duplicate of any processed archive (12378 raw files here vs bixiecanyang's
~13580, yanlongfengyin_xiaoao3's ~17380, etc; distinct `master.lpc`/
`logind.lpc`/`securityd.lpc` content in every case).

## Fixes applied

Ported/cross-checked against the 夕阳再现-family playbook
(bixiecanyang/#71, xiyangzaixian_fengyun2/#47) where lineage matches, plus
fresh findings from this archive's own content:

1. **AGENTS.md §15h** (`adm/simul_efun/chinese.lpc`'s `is_chinese()`): GBK
   lead-byte range check (`strlen(str)>=2 && str[0] > 160 && str[0] <
   255`) → CJK Unicode codepoint range check (`strlen(str)>=1 &&
   str[0] >= 0x4e00 && str[0] <= 0x9fff`).
2. **AGENTS.md §15h** (`adm/daemons/logind.lpc`'s `check_legal_name()`):
   byte-count bound `strlen(name) < 2 || > 10` → character-count bound
   `< 1 || > 5` (matches the message's own stated "1 到 5 个中文字"); the
   sliding-window gate `i%2==0 && !is_chinese(name[i..<0])` had its
   `i%2==0 &&` dropped so every character position is checked (same
   reasoning as bixiecanyang: `is_chinese()` only inspects index 0 of
   whatever's passed, so a full-length suffix slice is functionally a
   single-character check either way).
3. **AGENTS.md §15z** (3 files: `include/globals.h`, `adm/obj/master.lpc`,
   `adm/obj/simul_efun.lpc`): each carried an `#ifndef
   __SENSIBLE_MODIFIERS__` / `#define nosave static` / `#define protected
   static` compatibility shim, and `convert_lib.sh`'s blanket
   `static`→`nosave` sed rewrote the shim's own lines to `#define nosave
   nosave` / `#define protected nosave` (silently aliasing `protected` to
   `nosave`). Neutralized the whole shim (replaced with a one-line
   comment) in all 3 files. **New nuance for the catalog**: this
   driver build's own predefine table (dumped at boot) DOES include
   `#define __SENSIBLE_MODIFIERS__` — meaning the `#ifndef` guard is
   actually **false** here and the buggy branch is dead code at compile
   time regardless. The textual sed-collision still happened (the sed
   doesn't know about `#ifdef` state), so the fix was still applied as
   free, harmless insurance, but it may not have been live either way on
   this particular driver build/config. Worth checking `__SENSIBLE_
   MODIFIERS__`'s presence in the predefine dump on future libs before
   assuming §15z is *always* a live bug versus just a latent one.
4. **AGENTS.md §3 counterexample** (7 files): the same blanket sed hit
   `log_file("static/XXX", ...)` string literals (a real on-disk log
   subdirectory name), rewriting them to `"nosave/XXX"`. Reverted all
   occurrences back to `"static/XXX"` in: `clone/misc/dan.lpc`,
   `adm/simul_efun/override.lpc` (×5), `adm/daemons/securityd.lpc`,
   `adm/obj/master.lpc` (×5), `cmds/std/give.lpc`, `cmds/std/suicide.lpc`,
   and `adm/daemons/复件 securityd.lpc` (see item 10 below).
5. **AGENTS.md §14** (`adm/obj/master.lpc`'s `valid_override`): upgraded
   from the 2-arg signature to the documented 3-arg `(file, name,
   main_file)` form, checking `main_file == SIMUL_EFUN_OB || main_file ==
   MASTER_OB` in addition to the original `file` check — `simul_efun.lpc`
   is a pure `#include` composer (pulls in `object.lpc`, `message.lpc`,
   etc, several with `efun::` overrides), so `file` alone never equals
   `SIMUL_EFUN_OB` for those fragments. No live boot/registration failure
   observed without this fix (consistent with the catalog's note this may
   never surface on a real boot) but applied as free insurance.
6. **AGENTS.md §15s** (`adm/simul_efun/message.lpc`'s `tell_room()`): the
   dominant 2-arg call form (275+ of 332 call sites in this archive)
   leaves `varargs object *exclude` at its default int `0`, which then
   flows straight into `message("tell_room", str, ob, exclude)` — this
   driver's `message()` rejects a raw int `0` for its 4th
   (`void|object|object*`) argument. Fixed at the shared root:
   `exclude || ({})`. **Also found and fixed the same shape in `shout()`**
   (a variant not previously seen written exactly this way): `message(
   "shout", str, users(), this_player())` — `this_player()` can itself be
   `0` outside a genuine player context, hitting the identical rejection;
   fixed by wrapping in `me ? ({ me }) : ({})`.
7. **New §15b-style gap** (`adm/simul_efun/message.lpc`): two functions
   called throughout the lib but never defined anywhere —
   `message_combatd(msg, me, you)` (called from `adm/daemons/itemd.lpc`
   and 2 `kungfu/skill/` files) and `message_sort(msg, me, you)` (called
   4× from `adm/daemons/itemd.lpc`). Both aliased to the already-defined
   `message_vision()` (identical 3-arg shape), added right after it in the
   same file (safe ordering, no §15aa risk since `message_vision` is
   textually first).
8. **§15ac-style bare macro** (3 files: `d/quanzhou/npc/tang3.lpc`,
   `d/taishan/tang3.lpc`, `adm/daemons/network/netmail.lpc`): bare
   `SAVE_EXTENSION` (never defined anywhere in this lib) → this driver's
   real autogenerated `__SAVE_EXTENSION__` constant.
9. **AGENTS.md §15ab** (`clone/user/login.lpc`'s `receive_message()`): the
   pre-login connection object's copy was missing the `!stringp(str)`
   guard that the post-login player body's copy (`feature/message.lpc`)
   already has — added proactively as insurance (no live crash observed
   here since the two files this pattern usually trips on, `motd`/
   `welcome`, both exist with real content in this archive, but the gap
   is real and cheap to close).
10. **Orphaned backup file** (`adm/daemons/复件 securityd.lpc`, Chinese for
    "copy of securityd.c" — a stray backup with a different, older, and
    genuinely broken shape than the real `securityd.lpc`, not referenced
    by anything in the tree): renamed to
    `复件securityd.orphaned-backup` so it can't be mistaken for a live
    compilable object (same treatment as AGENTS.md §12's precedent).
11. **AGENTS.md §15w** (`adm/obj/master.lpc`'s `log_error()`): broadcast
    to the connected player was unconditional (`if (this_player(1))
    efun::write(...)`) even for ordinary compile *warnings*, not just real
    errors. Gated the broadcast on the message NOT containing
    `"warning:"` (log-file write is unchanged/unconditional).
12. **New content-gap fix, single shared root** (`d/city/obj/cloth.lpc`,
    file did not exist at all in the raw archive — `d/city/obj/` only
    shipped `box/gourou/jitui/table/zhubang.lpc`): **47 different NPC
    files spread across at least a dozen different zones** (`city2`,
    `wudujiao`, `tangmen`, `guanwai`, `village`, `mingjiao`, `quanzhou`,
    `lingshedao`, `gumu`, `kungfu/class/{gumu,npc}`, `migong`, etc.) all
    hardcode the literal `carry_object("/d/city/obj/cloth")->wear();` as
    their standard starting-garment call (clearly one shared boilerplate
    template copy-pasted verbatim into dozens of zone-specific NPC files,
    never updated to each zone's own local `obj/cloth.lpc` the way most
    other zones' NPCs correctly do), and since the target never existed,
    `carry_object(...)` returned `0` and `->wear()` on it crashed silently
    during each NPC's own `create()` (the crash is swallowed with no
    printed diagnostic — same silent-nested-compile-failure shape as
    AGENTS.md §15d, just triggered by a genuinely-missing file instead of
    an ACL denial). This was the single highest-impact lpcc-sweep fix:
    restoring ONE file (copied verbatim from the byte-for-byte-identical
    sibling template at `d/city/npc/obj/cloth.lpc`/`d/village/npc/obj/
    cloth.lpc`/`d/tangmen/obj/cloth.lpc` — all three are the same
    "basic starting cloth" boilerplate, confirmed by direct comparison
    before reconstructing, not fabricated content) dropped the lpcc
    sweep's failure count from 336 to 285 in one shot (see "lpcc sweep"
    below for the exact before/after numbers).
13. **3 small genuine pre-existing typos found via the lpcc sweep**:
    - `d/baituo/obj/bowl.lpc` and `d/baituo/npc/obj/bowl.lpc`:
      `set_name("海口大碗", "bowl")` — second arg is a bare string where
      `set_name()` expects `string*` (the alias-list idiom used
      everywhere else in this lib, e.g. `set_name("布衣", ({ "cloth" }))`).
      Fixed to `({ "bowl" })`.
    - `clone/book/lbook5.lpc` and `clone/book/pixie_book.lpc`: each had a
      literal duplicate `int query_autoload() { return 1; }` declaration
      (copy-paste artifact) causing "Redeclaration of function". Removed
      the redundant second copy in both.
    - `d/npc/m_weapon/weapon/m_bian.lpc`: two `void create()` definitions
      — the first is the complete, correct item setup (name/weight/
      wield-messages/`init_whip`); the second is a short, clearly
      incomplete leftover fragment (`unit`/`no_get`/`no_drop`/`setup()`
      only). Removed the second (dead/incomplete) one, keeping the first.
14. **5-file iconv-eaten-newline fix** (matches the documented Encoding
    gotcha: `iconv -c`'s invalid-byte recovery can eat the adjacent REAL
    newline too, merging a `@LONG`...`LONG` text block's closing tag onto
    the preceding text line): `d/heimuya/tang.lpc`, `d/heimuya/npc/
    tang.lpc`, `d/heimuya/shenggu.lpc`, `d/quanzhen_old/manglin1.lpc`,
    `d/quanzhen_old/manglin2.lpc` — all 5 showed `error: End of file in
    text block` from a merged `...文本.LONG );` (or CRLF `。LONG\r\n`)
    line. Confirmed against the raw pre-conversion bytes in each case
    (an invalid/truncated GBK byte immediately followed by a literal
    newline) before inserting the newline back in at the exact point
    indicated by the raw byte layout — not a guess. All 5 verified
    compiling clean afterward via standalone `lpcc`.

## Confirmed NOT needed (verified by reading source)

- **§4** (lazy security-daemon `load_object` recursion in
  `valid_read`/`valid_write`): `master.lpc`'s `valid_write` only
  `find_object(SECURITY_D)` (returns `0` if absent, never lazily loads
  it); `valid_read` does the same, defaulting to `1` (allow) if absent.
  No `load_object()` call anywhere in either apply.
- **§7** (`get_root_uid`/`get_bb_uid`): both present and correct in
  `master.lpc` (`return ROOT_UID;` / `return BACKBONE_UID;`).
- **§15l** (`destruct(SIMUL_EFUN_OB)` in master's `create()`): `create()`
  is a one-line `write("master:  成功加载.\n");` — no destruct/reload
  dance present.
- **§15n** (custom `securityd.lpc` ACL denying "(player)"-status reads,
  blocking mid-connection lazy compiles): this lib's `securityd.lpc`'s
  `valid_read` unconditionally `return 1;` — no ACL table exists at all
  to deny anything. Confirmed further by zero "Read access denied" in
  `debug.log` across two full interactive sessions.
- **§8c** (`this_player()`-override footgun in `valid_read`/`valid_write`):
  grepped `securityd.lpc` for the `if (this_player()) user =
  this_player();` shape — not present.
- **§15u** (dormant "phone-home license check" self-destruct function):
  grepped `securityd.lpc`/`master.lpc` for `checking_status`/mass
  deletion/`shutdown()`-gated-on-opaque-check shapes — none found.
- **§8d/§15o** (`get_include_path()` / local `<header.h>`-next-to-its-user
  angle-bracket includes): `convert_lib.sh`'s automatic local-include-to-
  quotes pass converted 22 such includes to quoted form during
  conversion; a follow-up scripted check confirmed zero remaining
  case-sensitivity mismatches between any `#include` target and its
  actual on-disk filename. No `master.lpc get_include_path()` addition
  needed.
- **Nitan-family simul_efun-dbase architecture bug (§15)**: not present.
  `adm/obj/simul_efun.lpc` is a pure `#include` composer; `feature/
  dbase.lpc` implements real local `set`/`query`/`delete` methods
  directly (correct inherit-based architecture, not the bare-simul_efun
  pattern).
- **§8e** (`tail()` missing-efun bug): no `tail(` call anywhere in the lib.
- **§8f** (`TYPE * name1, name2;` array-modifier-doesn't-propagate bug):
  spot-checked ~15 of the 42 grep hits for this shape across the lib —
  every one is an intentional array+scalar declaration (e.g. `object
  *enemy, ob;` where `ob` is later assigned a single element and used as
  a scalar throughout), the correct/intended idiom in this lineage, not
  the Dead-Souls-specific "both should be arrays" bug. No fix applied.
- **§15p** (DNS/intermud daemon preload hang): `adm/etc/preload` is
  **entirely empty** in this archive (just blank/CRLF lines) — nothing
  preloads at all in this lib (confirmed live: the boot log goes straight
  from "Loading master file" to "Accepting telnet connections", no
  preload activity logged). `network/dns_master.lpc` exists on disk but
  is never referenced from `logind.lpc`'s connection path — grepped for
  `DNS_MASTER`/`dns_master`/`gb_big5`/`Mud_name(` in `logind.lpc`, zero
  hits. Nothing to exclude.
- **§15x** (hardcoded `MUD_PORT` mismatch silently rejecting every
  connection): `master.lpc` has `#define TOMUD_PORT 9999`, but — exactly
  like bixiecanyang's finding — it's only used to set a cosmetic
  `"tomud"` temp flag, never to reject a connection. Confirmed no
  rejection via two successful end-to-end interactive tests on port
  40070 (≠ 9999).
- **§15q-shaped hidden gate — but here it IS live, unlike bixiecanyang**:
  see "Registration flow" below — this archive's version of the gate is
  NOT conditioned on the `TOMUD_PORT`/`"tomud"` flag the way
  bixiecanyang's was (structurally unreachable there); here `get_version`
  is the unconditional FIRST callback on every connection, so the literal
  `"2060"` handshake must always be sent first. Confirmed by reading
  `logind.lpc`'s `logon()` directly (no gating `if` around the
  `input_to("get_version", ...)` call) and by the live transcript (the
  gate fired on both test runs).

## Registration flow (read from `logind.lpc`'s actual `input_to` chain)

`logon()` → **`get_version`** (unconditional; the prompt reads "请输入您
的英文名字：" — textually indistinguishable from a normal id prompt, but
the real check is `arg[0..3] != "2060"`; sending anything else prints an
"警告！本游戏必须使用TOMUD客户端..." alert and disconnects — a live
instance of AGENTS.md §15q) → **English id** (`get_id`; `"new"` branches to
registration) → **`GetNewId`** (english id, must not be `"new"`/`"quit"`,
must be unused) → **`confirm_id`** (y/n) → **`get_name`** (Chinese name,
1-5 characters; typing a name directly skips the `get_resp` y/n loop
entirely — that loop only fires for the **empty-input** → `random_name()`
path) → **`new_wizpwd`** (an "admin password", ≥5 chars) → **`confirm_
wizpwd`** → **`new_password`** (the real login password, ≥5 chars, must
differ from the admin password) → **`confirm_password`** →
**`select_gift`** (attribute roll, 0-4; 0 = system-random via `get_gift`'s
y/n accept loop) → **`get_email`** (`id@x.x` format required) →
**`get_gender`** (m/f) → `enter_world()`.

`banned_name` list: 你/你的/我/我的/自己/屁/他/他的/她/她的/它/它的/鬼王/
风云/流氓/爸/妈/祖先/祖宗/爷/奶/毛泽东/邓小平/江泽民/【/】/马克思/恩格斯/
列宁/抄/手淫/老百姓 — checked before testing; neither "秦风" nor "林风"
match any entry.

## Interactive test #1 — full registration + post-login commands, real name "秦风"

Single continuous `mudclient.py` session, in order:
- `2060` → passes the client-version gate, reaches the id prompt.
- `new` → enters the registration sub-flow.
- `qinfeng` → accepted as the new english id, "...您确定吗(y/n)？" prompt.
- `y` → confirms, shows the "give yourself a name" banner.
- **`秦风` (real Chinese name)** → accepted silently on the first try, no
  rejection, straight to "请设定您的管理密码：" — confirms the §15h fix
  works end-to-end.
- (a stray extra `y` in my script landed on the admin-password prompt
  instead of a nonexistent `get_resp` confirmation — rejected for being
  too short, exactly as `new_wizpwd`'s own length check should, then
  `admin12345`/`admin12345` succeeded for wizpwd+confirm,
  `player12345`/`player12345` for the real password+confirm — incidental
  but useful confirmation that the length-check rejection path also works
  correctly)
- `0` → system-random gift roll (膂力20/悟性20/根骨23/身法17).
- `y` → accepts the rolled gift.
- `qinfeng@163.com` → accepted as email.
- `m` → male gender.
- Character **actually entered the game world**, landing at
  `/d/quanzhou/tieqiang` (铁枪庙/"Iron Spear Temple", one of the 4
  configured `start_room`s), saw real NPCs (乌鸦×4/"crows") and room
  content render correctly. `〖有间客栈〗` channel broadcast "听说又来了
  一位叫做秦风的少年侠士" with the correct real name embedded.
- `look` → re-displayed the exact same room correctly (confirmed by the
  identical room-description block appearing a second time in the
  transcript, immediately following the entry banner/system alert).
- `quit` → dropped the starting "布衣" garment and disconnected gracefully
  with "欢迎下次再来！" ("welcome back next time").

Zero real `error:`/"Read access denied"/"Bad argument"/"Too deep
recursion" lines anywhere in `debug.log` for this session — only the same
benign `Unknown #pragma, ignored` / `Unused local variable` compile
*warnings* seen throughout every other lib in this family.

## Interactive test #2 (after ALL fixes above, fresh driver restart) — real name "林风", female, incl. `score`

Per AGENTS.md's own diagnosis-technique note ("LPC objects don't recompile
just because their source file changed on disk; you must restart the
driver process"), the driver was killed and rebooted fresh after every
fix in this NOTES.md was applied (several touched
`adm/simul_efun/message.lpc`, a file every room/NPC's heartbeat/emote
path depends on) before this second, independent verification run:

- `2060` → `new` → `linfeng` → `y` → **`林风`** (real Chinese name) →
  accepted silently, straight to wizpwd prompt (no stray extra input this
  time) → `wizpass12`/`wizpass12` → `realpass34`/`realpass34` → `0` → `y`
  (gift roll: 膂力29/悟性22/根骨15/身法14) → `linfeng@163.com` → **`f`**
  (female).
- Character entered the game world at `/d/city/wumiao` (武庙/"Yue Fei
  Temple"), with the **gender-correct** starting garment
  ("粉红绸衫"/pink silk garment, not the male "布衣") and gender-correct
  in-game description ("你是一位十四岁的女性人类...").
- `look` → re-displayed the room correctly (room description block
  repeated a second time in the transcript).
- **`score`** → a full, correctly-rendered character sheet: age/gender/
  birth-time flavor text, all 4 attributes (膂力/悟性/根骨/身法) matching
  the rolled values, 精/气 (essence/qi) bars, combat attack/defense power,
  food/water bars, kill count, 潜能 (potential)/实战经验 (combat
  experience) — confirms the post-login command-dispatch pipeline works
  for more than just `look` (a second, entirely different `cmds/`
  command file), satisfying AGENTS.md §15ae's standing policy with a
  stronger signal than a single command would.
- `quit` → dropped the "粉红绸衫" garment and disconnected gracefully.

Zero real `error:`/"denied"/"crash"/"undefined"/"bad argument" lines in
`debug.log` for this second, post-fix session either (grepped explicitly,
excluding the harmless config-table dump lines that happen to contain the
word "error"/"crash" in key names like `mudlib error handler`/`trap
crashes`).

## lpcc sweep

Ran 3 times (before content-gap fix / after the `d/city/obj/cloth.lpc`
content-gap fix / after all remaining typo fixes), memory monitored
throughout (well within budget — 11413 files, never dropped below ~17GB
free on this 23GB host, nowhere near the §6b mega-lib danger zone):

| Pass | Pass | Fail | Total | Pass rate |
|---|---|---|---|---|
| 1 (pre-fix) | 11076 | 336 | 11412 | 97.06% |
| 2 (after cloth.lpc fix) | 11128 | 285 | 11413 | 97.50% |
| 3 (final, after typo fixes) | 11138 | 275 | 11413 | 97.59% |

**Triage of the failures** (per AGENTS.md §6b's "categorize before fixing"
guidance):

- **~211 of the final 275 failures are a "blank" shape** (`Fail to load
  object X.` with zero further diagnostic text) — spot-checked ~6 of these
  across different zone clusters (`d/migong/lev7/dong99`, `/kungfu/class/
  xueshan/jiamu`, `d/migong/lev7/dong82`) by re-running them standalone
  via bare `lpcc`: **every one compiled clean in isolation**, confirming
  this is the documented §6b/§15d-shaped false-positive category (a
  file that's fine on its own but shows as failed when it's one of
  11000+ objects compiled into a single shared-VM batch session — some
  state/ordering interaction across the giant batch, not a per-file
  bug). Verified this isn't purely "batch size" by re-running just the
  256 originally-blank files as their OWN smaller batch: most (240/256)
  still failed even at 1/45th the batch size, ruling out a simple
  size/table-capacity threshold — the real common thread turned out to
  be the missing-content cascade below, not batch size per se.
- **The single highest-leverage real cause, found and fixed**: 47 files'
  `carry_object("/d/city/obj/cloth")->wear()` referencing a file that
  genuinely didn't exist in the raw archive at all (see fix #12 above) —
  this alone explains the bulk of the "blank" shape's drop from 256 to
  211 files between sweep passes 1 and 2/3 (a missing target makes
  `carry_object()` return 0, and `->wear()` on that crashes silently
  during the referencing NPC's own `create()`, exactly matching the
  "no visible diagnostic" symptom).
- **The 74→(post-fix)~64 failures with real diagnostic text** were
  triaged by error-message category (per §6b/§8g): fixed all the
  genuinely cheap, real, non-network-daemon ones (2× Redeclaration, 2×
  Bad-type set_name, 5× iconv-eaten-newline, the message_combatd/
  message_sort gaps, the 3× SAVE_EXTENSION macro, the m_bian duplicate
  create()); confirmed the `is_root`-undefined-function cluster (5×) is
  dead code inside the never-`#include`d `adm/simul_efun/override.lpc`
  (see below); confirmed the `Cannot #include {uid,config,daemons,
  mailer}.h` cluster (12×) and the `Undefined function {member_group,
  data_netmail_file, mud_name, file_exists}` cluster (6×) are entirely
  inside `adm/daemons/network/*` intermud/DNS daemon files, never
  preloaded (preload is empty) and never referenced from `logind.lpc`'s
  live connection path — out of scope, matches the project's established
  "don't chase unreached network daemons" precedent. The remaining
  scattered "Undefined variable"/syntax-error singletons (mostly inside
  `feature/vendor_sale.lpc`, see below, and a handful of one-off
  `kungfu/skill/`/`d/`-zone files not on any preload/registration path)
  are noted here as known, low-impact gaps rather than hand-fixed one at
  a time, consistent with the project's "prioritize breadth over
  exhausting every last content bug" policy.
- **`feature/vendor_sale.lpc`** (a shop/vendor-NPC feature file, `#include`d
  by/`inherit`ed into `kungfu/class/npc/xiaoer.lpc` — 2 files affected):
  genuinely, severely mangled in the **raw, pre-conversion archive itself**
  (confirmed via `diff` against the raw `.c` — byte-identical, not
  something our pipeline introduced) — roughly the back third of the file
  (`pay_back`/`do_deposit`/`do_setprice`) is missing semicolons and closing
  parens on nearly every line, looks like a botched find/replace or
  half-finished edit from the original 1999-era author (file header says
  "modify by ronger 99/02"). Per AGENTS.md's guidance on genuinely broken
  pre-existing content of this scale (as opposed to a single-line typo),
  **left unfixed and documented here** rather than guessing at the
  intended reconstruction of a decades-old half-edited shop-payment
  function — a real, pre-existing archive content gap, not a
  driver-compat bug.
- **`adm/simul_efun/override.lpc`/`user.lpc`/`util.lpc`**: contain `efun::`
  overrides (`snoop`, `shutdown`, `destruct`, etc.) and call `is_root()`
  (undefined), but **none of these three files are `#include`d by
  `adm/obj/simul_efun.lpc` or anything else in the tree** (confirmed via
  grep) — `simul_efun.lpc` implements its own inline `snoop`/`shutdown`/
  `destruct` overrides directly instead. These 3 files are dead/orphaned
  content from an earlier engine revision; their lpcc-sweep failures are
  pure noise, not live bugs.

## Re-verification pass (2026-07-23)

Clean re-boot confirmed (zero fatal errors, empty `etc/preload` boots in
well under 5 seconds). Ran the full registration + `look`/`score`/`quit`
flow once more in a single continuous connection (id `qinchuan`, real
Chinese name `秦川`, male): `2060` client-version gate → `new` → id →
`y` confirm → Chinese name accepted → admin password (2x) → real
password (2x) → gift roll `0`/`y` → email → gender `m` → entered the
world at 客店/"the inn", saw real NPC (店小二/innkeeper) and board
content, `look` re-rendered the room correctly, `score` produced the
full character sheet, `quit` disconnected cleanly ("欢迎下次再来！"). Zero
runtime errors in `debug.log`. No code changes needed — clean
re-confirmation of the original pass's findings.

## Config notes

`config.fluffos` adapted from the raw `config.cfg` (name "夕阳再现", the
generic engine name — the live banner shows the game's real identity,
「笑傲江湖」之「重出江湖」). Dropped obsolete keys per driver warnings:
`address server ip`, `address server port`, `reserved size`, `binary
directory`, `swap file`. Port set to **40070**; `mudlib directory` points
at this lib's `work/`; `log directory` is the usual `/log` (sibling of
`config.fluffos`, driver always launched via `cd` into this directory
first, per AGENTS.md §6).

## Encoding

`convert_lib.sh` reported 29 lossy conversions (invalid bytes dropped) out
of 12378 files — all but 5 (see fix #14 above) turned out to be genuinely
harmless (either non-code data/save files, or code positions where the
dropped byte didn't touch anything load-bearing). No stragglers found by
the standard post-conversion `file -b` sweep beyond one false positive
(`d/emei/shenshuige.lpc`, a normal, fully-valid UTF-8 room file that `file`
misclassifies as "data" for unrelated heuristic reasons — confirmed by a
full Python UTF-8 decode, not a real encoding problem).

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** run over all `work/*.lpc`: 11,413 total, 11,324
  written, 35 already-idempotent, 54 refused (self-check errors,
  expected on messy legacy code). One formatter regression found and
  fixed (same bug class as found live-breaking a sibling lib this pass):
  `clone/misc/board.lpc`'s `short()` had
  `return ::name(1) + "(" + capitalize(::query("id")) + ")";` mangled
  into `capitalize (: : query("id")\n)\n+ ")"` — the formatter corrupts
  the `::methodname(...)` parent-call scope operator when immediately
  followed by `(`. Fixed by hand-restoring the original single-line
  form. (A second, unrelated `: :` match in `d/migong/12gong/renma.lpc`
  turned out to be ASCII-art map content inside a string/comment block,
  not code — left untouched.)
- **Native retest against the freshly-rebuilt driver**: clean boot, zero
  fatal/syntax errors. Full registration flow (client-version gate
  `2060` → `new` → id → confirm → real Chinese name → admin password ×2
  → real password ×2 → gift roll → email → gender) plus post-login
  commands re-verified in one continuous connection (id `qinchuanc`,
  real Chinese name `秦川岭`, gender `m`): entered the game world (this
  run landed at 北疆小镇/a Xinjiang-themed town rather than the 客店/inn
  from the prior pass's run — expected variance from the gift/race
  roll, not a bug), `look` showed real room + NPC content, the
  character sheet displayed correctly, `quit` disconnected cleanly with
  "欢迎下次再来！". Zero runtime errors in `debug.log`.
- **WASM test**: boots clean (only the expected non-fatal preload
  warnings). Found a genuine, reproducible **WASM-harness/mudlib timing
  gotcha, not a mudlib bug**: `adm/daemons/logind.lpc`'s `logon()` has
  `if (uptime() < 10) { write("游戏服务器正在启动过程中，请稍等10秒后再
  连线。\n"); destruct(ob); return; }` — a deliberate 10-second post-boot
  grace period, present in the original archive, that natively is a
  non-issue (the real-world overhead of spawning the driver process,
  `ss` port-checking, and starting a Python client naturally exceeds 10
  seconds by the time a real connection attempt lands). Under
  `wasm_client.js`, `fluffos_connect()` is called synchronously
  immediately after `fluffos_boot()` returns, with no equivalent
  real-world gap — so every WASM test attempt hits this gate
  deterministically and the connection is destructed before the
  English-name prompt is ever reached. Confirmed this isn't recoverable
  by waiting longer via `--send`/`--idle` after connecting (the
  `uptime()` check runs once, at `logon()` time, which is effectively
  t≈0 in the WASM harness's clock) — the harness would need to delay the
  `fluffos_connect()` call itself by 10+ simulated seconds, which its
  current CLI surface doesn't expose. **Not patched** — modifying the
  shared harness is out of this pass's scope, and the mudlib's own
  10-second gate is intentional, pre-existing design, not a bug.
  Documenting as a known WASM-testing limitation distinct from the
  `query_ip_number()` one.
