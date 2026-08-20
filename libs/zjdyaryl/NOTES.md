# 终极地狱之爱若幽兰 (Ultimate Hell: Love Like Orchid) — archive #79

Source archive: `archives/终极地狱之爱若幽兰1.166正式版.rar`
Slug: `zjdyaryl` (matches the archive title; no discrepancy —
the config's own `name` field is `№㊣地狱泥潭---爱若幽兰㊣№......`, i.e.
"地狱泥潭" (Hell Nitan/Swamp) + "爱若幽兰" (Love Like Orchid), matching
the archive title exactly). Port: **40073**.

**Real mudlib root**: the archive's top level is
`终极地狱之爱若幽兰1.166正式版/`, containing:
- `doing/config.revive` (the real config file) + `doing/doing_hell/` — the
  actual mudlib (this is what got extracted/converted).
- `doing/mudos.dll` + `doing/osxp.exe` — a prebuilt Windows MudOS driver,
  ignored (we use our own FluffOS build).
- `客户端1.166/` — a Windows GUI mud client (`mud.exe`, `.OCX`, `.CHM`
  help), not part of the mudlib, ignored.
- `套装说明/文件/` — documentation with illustrative example `.c` snippets
  (`score.c`, `arm.c`, `equip.c`, `attribute.c`, `skills.c`, `suit.c`,
  `skill.c`) showing site admins how to add equipment "suits" — NOT the
  real mudlib source, just docs, ignored (not converted).
- `angelus1.166说明（务必看看）.txt` — readme; in-game banner credits
  author "ANGELSS" and a QQ contact number.

**Lineage**: confirmed ES II → XKX → "hell" fork via `adm/single/master.lpc`'s
own header credit chain: `"for ES II mudlib / original from Lil / rewritten
by Annihilator (11/07/94) / modified by Xiang for XKX (12/15/95) / updated
by Doing Lu for hell (2K)"`, and `adm/daemons/securityd.lpc`'s matching
`"Modified by Xiang for XKX / Updated by DOing Lu for ULTRA HELL"`. Same
`adm/single/{master,simul_efun}.lpc` + `adm/daemons/*` "Century"-style
layout as es1_win/esI/xkx2001/rzrmud/bmxkx2001/
kxkj/yueyingqiyuan/wuhanzhan/yanhuangwuhun/haiyang2/
kxkj1/xuanjianlu/shenzhou/shenmo. **NOT related to the
nitan/NT/Lonely lineage** despite "泥潭" appearing in the display name —
that word is just part of this fork's own branding ("Hell Swamp"), not a
signal of the NT/nitan/Lonely engine family; confirmed via `feature/
dbase.lpc` (real local `set`/`query`/`delete` methods, not the bare
simul_efun dbase-sharing architecture bug of §15).

**CROSS-CHECK FLAG for the main session**: archives #78 (`终极地狱.rar`)
and #80 (`终极地狱-指间mud版服务端.rar`) share the "终极地狱" name and were
being processed by sibling agents concurrently with this one — could NOT
cross-check lineage/duplication against them here. Per this project's
repeated experience (documented many times in TODO.md — sjpl2
vs shujian2008, xianlvqiyuan vs xlqy_new2007, kxkj1 vs
kxkj, etc.), **similar/identical Chinese titles are NOT
a reliable lineage signal** — verify via `diff`/`md5sum` on core files
(`master.c`, `chinese.c`, `securityd.c`, `logind.c`) once all three
archives are done, rather than assuming they're the same game or
unrelated just from the shared name.

## Fixes applied

### Proactive (applied before first boot, from the AGENTS.md catalog)

1. **§15h `is_chinese()`** (`adm/simul_efun/chinese.lpc`) — GBK byte-range
   check (`str[i] < 176 || str[i] >= 248`, paired-byte loop) replaced with
   a CJK Unified Ideographs codepoint range check (`0x4e00..0x9fff`), one
   character per index. Standard fix; this WAS the blocker for real
   registration in every earlier-processed lib until §15h was discovered.
2. **§15h deep `named.lpc` fix** (`adm/daemons/named.lpc`) — this lib has
   the full "nitan-family-shaped" deep pattern despite not being nitan
   lineage:
   - `PATH(name)` macro: `name[0..1]` (first GBK byte-pair) → `name[0..0]`
     (first character).
   - `strlen(name) < 2` (×3 call sites: `remove_name`, `who_is`,
     `invalid_new_name`'s initial null-check) → `strlen(name) < 1`.
   - `invalid_new_name`'s combined-length gate `strlen(name) < 4` → `< 2`.
   - Sliding-window substring checks: `name[i..i+3]` (4-byte/2-char
     window) → `name[i..i+1]`; `name[i..i+5]` (6-byte/3-char window) →
     `name[i..i+2]`; loop bound `i <= l - 4` → `i <= l - 2`; inner guard
     `i + 6 <= l` → `i + 3 <= l`.
3. **§15h `logind.lpc check_legal_name`** — byte-width bound `maxlen`
   halved (`strlen(name) > maxlen` → `> maxlen / 2`; lower bound `< 2` →
   `< 1`), plus the separate combined surname+given-name length check
   (`strlen(fname) < 4` → `< 2`) in `get_name()`. Both match the
   in-game prompt text exactly ("不要超过两个汉字" = max 2 characters;
   "姓和名的组合至少要有两个汉字" = combined min 2 characters).
4. **§14 `valid_override` 3-arg upgrade** (`master.lpc`) — added the
   `main_file` parameter and an `main_file == SIMUL_EFUN_OB/MASTER_OB`
   check, insurance for any `efun::`-override fragment `#include`d into
   `simul_efun.lpc`/`master.lpc` rather than being that file itself.
5. **§8d/§15o `get_include_path()`** (`master.lpc`) — was completely
   absent; added the standard "prepend the compiling file's own
   directory" implementation so mid-connection lazy compiles of any
   same-directory `#include` resolve correctly (compile-time-only/preload
   compiles already work via the config's `include directories`, but a
   live compile triggered from inside a connection needs this apply).
6. **§15n `securityd.lpc` custom-ACL allowlist** — this lib has a
   genuinely custom `exclude_read`/`trusted_read` ACL (not the simpler
   `find_object(SECURITY_D)`-only `master.lpc` pattern), so added the
   standard `switch(func) { case "load_object": case "recompile_object":
   case "include": return 1; }` early-allow to `valid_read()` before any
   euid/status logic — compiling/including code should never be gated by
   a fresh, not-yet-authenticated connection's `(player)` ACL status.
7. **§15p `dns_master` preload exclusion** — `/adm/daemons/network/
   dns_master` was present in `adm/etc/preload`; commented out (the
   `master.lpc`'s own `update_file()` already strips `#`-prefixed lines,
   confirmed by reading it before relying on the comment-out).
8. **§15ae `command_hook` `private` bug** — `feature/command.lpc` declared
   its central `add_action` dispatch hook as `private nomask int
   command_hook(string arg)`. This driver treats `private` as hidden from
   `add_action`'s external dispatch once inherited into another object
   (the player body class here) — would have silently broken **every**
   post-login command (including `look`) with zero visible error anywhere.
   Dropped `private`, kept `nomask`. **Confirmed via testing this was the
   single most important fix** — verified `look`/`score`/`i` all actually
   dispatch and produce real output, not silence.
9. **§15w `log_error()` warning-spam gate** (`master.lpc`) — applied
   proactively as insurance: gated the player-facing broadcast
   (`efun::write`/`tell_object`) on the message NOT containing
   `"warning:"`, so ordinary compile warnings (e.g. the `nosave`-function
   warnings from fix #10 below) don't spam a connected wizard-level
   player during any lazy compile. Everything still gets logged to
   `/log/log` unconditionally.

### Found reactively (boot + lpcc sweep)

10. **§3 `static`→`nosave` blanket sed, and its counterexample** —
    `convert_lib.sh`'s automated pass touched 128 files. As expected from
    the moniHuafu precedent, this lib ALSO uses a `"static/xxx"` naming
    convention extensively — both as `log_file("static/XXX", ...)` paths
    (a REAL `/log/static/` directory ships in the raw archive) **and** as
    dbase property-key namespacing (`->query("static/marry")`,
    `->query("static/sadly")`, etc — internally self-consistent either
    way, but reverted anyway for clarity/no-surprises). Found **51
    files** with `"nosave/...` string-literal corruption after the sed;
    reverted all of them back to `"static/...` with a scoped
    quote-anchored sed (`"nosave/` → `"static/`), verified zero remaining
    `"nosave/` hits afterward. `feature/treemap.lpc`'s `nosave nomask`
    (originally `static nomask`) function declarations compile fine — no
    ordering/collision issue there.
11. **§15s `message()`-wrapper crash** (`adm/simul_efun/message.lpc`) —
    the local `message(mixed arg, string message, mixed target, mixed
    exclude)` override forwarded straight to `efun::message(...)`, but
    `tell_room()`'s common 2-arg form (`tell_room(room, msg)`, no
    `exclude`) leaves `exclude` at its varargs default of raw `int 0`,
    which this driver's real `message()` efun rejects (`Expected: object,
    array, Got: int(0)`). This crashed **every** `do_channel()` broadcast
    at preload time (channeld.lpc → message() → simul_efun's message())
    — 8+ daemons hit it during preload alone (natured, punishd, storyd,
    eventd, memoryd, backupd, ftpd, cpud, questd). Fixed once at the
    shared root: normalize `exclude` to `({})` when it's neither an
    object nor an array before delegating to the real efun. Confirmed
    fully resolved — zero `Bad argument 4 to EFUN message()` errors in a
    fresh boot after the fix (down from ~10 per boot before it).
12. **§2 `.c`→`.lpc` rename-width bug** (`[0..<3]` → `[0..<5]`) — found
    5 genuine sites (all listing/stripping a `*.lpc`-glob'd filename's
    extension): `adm/daemons/storyd.lpc`, `adm/daemons/eventd.lpc`,
    `adm/single/importer.lpc` (one of its two `[0..<3]` sites — the
    `sprintf("...item/%c/%s", ..., item_name[0..<3])` one, explicitly
    commented "去掉后面的 .c 字样" / "strip the trailing .c"), and
    `adm/npc/luban.lpc` (2 sites, both stripping a player-built room's
    `.lpc` filename before a `DBASE_D->clear_object()` call). **Left
    alone**: `importer.lpc`'s OTHER `[0..<3]` site inside
    `get_user_list()` — that one strips a DIFFERENT, unrelated
    (2-char, `.o`-shaped) save-data filename extension, not something
    our `.c`→`.lpc` rename touched; it's part of a legacy migration tool
    not on the registration/gameplay path, so left as pre-existing
    (possibly already buggy, out of scope).
13. **§15b `is_killing()` type mismatches** (direct calls passing an
    `object` where the function declares `string id`, only caught by this
    driver's static type checker on DIRECT calls, not `->`-based
    call_other):
    - `clone/user/user.lpc`'s `accept_kill(object ob)` — `is_killing(ob)`
      → `is_killing(ob->query("id"))`. **This is the player body class**
      — broke `make_body()` silently, exactly matching this bug's
      documented signature (registration completes through gender
      selection, then the character never actually lands, with zero
      visible error). Confirmed by testing: after the fix, both test
      runs reached the actual starting room.
    - `d/city/npc/guidao.lpc`'s `ask_me()` — `is_killing(who)` →
      `is_killing(who->query("id"))` (a quest/story NPC, not on the
      critical registration path, but fixed anyway since it was found via
      the sweep).
14. **New §8g-shaped shared-root bug: `inherit/misc/quest.lpc`'s
    `set_information()` parameter too narrowly typed** — declared `void
    set_information(string key, string info)`, but `QUEST_D`'s own real
    `set_information(object qob, string key, mixed info)` already accepts
    (and many quest files pass) a **function pointer** (e.g.
    `set_information(NPC_NAME, (: ask_npc :))`) as the "info" — this thin
    wrapper's own narrower `string info` parameter rejected every such
    call with `Bad type for argument 2 ( string vs function )`. Fixed at
    the single shared root (`info` retyped `mixed`), resolving **7 quest
    clone files at once**: `supply`, `explore`, `capture`, `deliver`,
    `judge`, `shen`, `search`.
15. **Genuine pre-existing typos found via the lpcc sweep** (none related
    to encoding/rename — confirmed by checking the raw archive):
    - `inherit/condition/damo.lpc` had **two independent bugs in one
      file**, both cascading into confusing-looking downstream noise:
      (a) line 215, `return name + HIM "发作身亡了;` — missing closing
      `"` before the semicolon. This single dropped quote swallowed
      ~13 lines of subsequent code as string-literal content, surfacing
      as a "syntax error, unexpected L_IDENTIFIER" at a COMPLETELY
      different line (228) and "Illegal character 0xe9/0x95/0xbf" errors
      at yet another line (281) that are actually perfectly valid UTF-8
      bytes for 长/长/的/吁 — pure lexer-desync fallout from the one
      missing quote, not real illegal-character bugs (matches §9/§10's
      documented cascading-noise pattern exactly). (b) line 228 itself,
      independently: `intp(cnd["remain"] || ! stringp(cnd["id"]))` was
      missing a `]` — `intp()` was being called with a whole boolean
      OR-expression as its argument instead of just `cnd["remain"]`;
      fixed to `intp(cnd["remain"]) || ! stringp(cnd["id"])`. Fixing both
      resolved this file plus its 3 sibling clones (`kungfu/condition/
      damo_luanqi`, `damo_shangshen`, `damo_zheyuan`, all of which
      `inherit` it) — 4 files from 2 bugs in 1 shared file.
    - `kungfu/class/generate/girl.lpc:579` — `query_per()` called with 0
      args where `feature/attribute.lpc`'s `int query_per(string arg)`
      requires 1 (the parameter is never actually used in the function
      body, and every OTHER of the 5 real call sites elsewhere goes
      through `->query_per()`/call_other, which this driver's strict
      arg-count check doesn't enforce the same way as a direct call).
      Fixed by passing `0` explicitly.
    - `d/village/npc/obj/shoes.lpc` — a `set("icon","05047");` statement
      got accidentally interleaved mid-argument into a `set("long",
      ...)` call (`set("long", \n set("icon","05047"); \n"这是...");`),
      splitting one statement into a syntax error. Reordered so each
      `set()` call is complete on its own.
    - `d/baituo/obj/bowl.lpc` + `d/baituo/npc/obj/bowl.lpc` (identical
      duplicate content shipped in two different zone directories) —
      `set_name("海口大碗", "bowl")` passed a bare string where
      `set_name(string name, string *id)` requires an array; fixed both
      to `set_name("海口大碗", ({ "bowl" }))`.

## Confirmed NOT needed (checked, absent)

- **§4** (lazy `load_object`-in-`valid_read`/`valid_write` recursion) —
  `master.lpc`'s `valid_read`/`valid_write` only do `find_object
  (SECURITY_D)`, no `load_object()` call at all; nothing to guard.
- **§7** `get_root_uid`/`get_bb_uid` — already present and correct in
  `master.lpc`.
- **§15l** `SIMUL_EFUN_OB` destruct in `master.lpc create()` — not
  present; `create()` just does `write("master: loaded successfully.\n")`.
- **§15z** `#define nosave static`/`#define protected static`
  compatibility shim — not present anywhere in this lib.
- **§15ag** `ed_start`/`ed_cmd`/`query_ed_mode` — zero matches anywhere in
  the tree; this lib's editor path doesn't use them.
- **§15u** dormant "phone-home license check" self-destruct function —
  read through `securityd.lpc`/`master.lpc` in full, found no such
  function.
- **§15x** hardcoded `MUD_PORT` connection gate — `master.lpc`'s
  `connect()` doesn't check any port constant at all; the only
  port-dependent code is `versiond.lpc`'s admin-only "version sync"
  feature, which reads the port dynamically via `get_config
  (__MUD_PORT__)` (not hardcoded) and is non-fatal anyway (see below).
- **§8e** `tail()` missing efun — not called anywhere reachable in this
  session's testing or the lpcc sweep.
- **§15ab** `receive_message()` missing `!stringp` guard — `clone/user/
  login.lpc`'s `cat()`/`color_cat()` (in `adm/simul_efun/file.lpc`) ARE
  unguarded against a missing file (`write(read_file(file))` with no
  `stringp` check), matching the general risk pattern — but every file
  path actually referenced during connection setup (`WELCOME`, `MOTD`,
  `UNREG_MOTD`, `WIZLIST`) exists on disk with matching case, so this
  null-string path is never actually exercised by this archive's content.
- **§15k** case-sensitive data-file mismatch — checked every hardcoded
  path constant in `include/login.h` against the actual on-disk filename
  case; all matched exactly.
- **§15ac** bare `SAVE_EXTENSION` — the only match found
  (`cmds/arch/p2.lpc`) is a genuine local `#define SAVE_EXTENSION ".o"`
  in that same file, not a reference to a nonexistent global constant.
- **§15af** `log_error()` calling `wizardp()`/lazy-loading the security
  daemon during a compile warning — `master.lpc`'s `log_error()` only
  checks `this_player(1)`/`this_player()` directly, no `wizardp()` call.
- **§15/§15v** nitan-family simul_efun dbase architecture bug /
  `LONELY_IMPROVED`-gated `efun::` family — confirmed not this lineage;
  `feature/dbase.lpc` implements genuine real local `set`/`query`/
  `delete` methods (per-object storage via `inherit`), not a bare
  simul_efun call pattern.

## Confirmed harmless, left unfixed (documented, not chased further)

- **`versiond.lpc`/DNS-daemon config-ID mismatch** (§15ad-shaped): `adm/
  daemons/versiond.lpc`'s `in_server()` (fired via `call_out` 2s after
  boot, since `RELEASE_SERVER()=="local"` in `adm/etc/config`) calls
  `get_config(__MUD_PORT__) + VERSION_PORT` — on this driver that
  produces the STRING `"12"` (not int `40085`), so
  `socket_bind(vfd, "12")` throws `*Bad argument 2 to socket_bind()
  Expected: int Got: "12"`. Confirmed harmless: `versiond`'s real job
  (`version_ok = 1`) already completes **synchronously**, several lines
  earlier in the same `setup()` call, before this broken call ever fires.
  Appears exactly once per boot in `debug.log`, every single time
  (both before and after all other fixes) — not chased further, matches
  the §15ad precedent exactly. The same underlying config-ID/`get_config`
  mismatch also fires (harmlessly) inside the standalone `lpcc`-sweep
  compiles of `adm/daemons/network/services/ping_q.lpc` and `adm/
  daemons/network/messaged.lpc` (both DNS/intermud daemons, both excluded
  from real gameplay by the `dns_master` preload exclusion — their
  `startup_udp()` hits the same `get_config()`-returns-a-string bug with
  a different numeric offset, again non-fatal, again not chased).
- **11 `adm/daemons/story/*.lpc` files fail the lpcc sweep by design, not
  bug**: `anthem`, `bizhen`, `jiuyang`, `sanfenjian`, `shenzhao`, `master`,
  `pangtong`, `baguadao`, `huanyin`, `jiuzhuan`, `mengzi`. Each one's
  `create()` calls a `select_character()`/`select_characters()` that
  filters `all_interactive()` for an eligible **currently-connected**
  player and calls `destruct(this_object())` if none qualifies — by
  design, these are one-shot "random story/encounter" triggers that only
  exist transiently while a real player is online. In a bare `lpcc`
  compile-and-load test (no interactive connections at all), every one of
  them immediately self-destructs, which the sweep script correctly (but
  misleadingly) reports as "Fail to load object" / FAIL. Verified this
  shape in a sample (`anthem`, `master`) and confirmed all 11 share the
  identical `all_interactive()`-gated pattern — genuinely not a bug, a
  §6b-class "divorced from real runtime context" sweep artifact.
- **`adm/single/importer.lpc`** fails the sweep with **zero error text**
  at all (`Fail to load object`, no diagnostic anywhere, not even in
  `debug.log`). This is a legacy data-migration/import admin tool (not on
  the preload list, not reachable from registration or ordinary
  gameplay) — not chased further per this project's stated policy of not
  sinking deep debugging time into every edge case across ~100 archives;
  noted here for whoever revisits it.

## Verification

**Boot**: `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/zjdyaryl/`, port 40073. Clean boot, `Accepting
telnet connections on 0.0.0.0:40073. Initializations complete.` — zero
fatal errors, only the one known-harmless `versiond.lpc socket_bind()`
line in `debug.log` (present on every boot, before and after all fixes).

**Full registration + post-login flow**, verified in **two separate
driver sessions**, each a SINGLE continuous `mudclient.py` connection:

- Run 1 (before the sweep-driven fixes, i.e. only the proactive fixes
  applied): English id `qinfeng` → confirm new id `y` → surname `秦` →
  given name `风` → admin password ×2 → normal password ×2 → character
  type `1` (猛士型/warrior) → gender `m` → **reached the actual starting
  room** 世外桃源 ("Peach Blossom Spring", a 连城诀-novel-themed room
  with NPCs 狄云/水笙 present) → `look` (redisplayed the room correctly)
  → `score` (returned "还没有出生呐，察看什么？" — a legitimate
  pre-birth/pre-registration gate: new characters must `register
  <email>` then choose attributes/"投胎做人" (be reincarnated) before
  `score` has real content to show; confirmed intentional via the
  welcome banner's own text, NOT a crash or silent failure) → `quit`
  (clean "欢迎下次再来！").
- Run 2 (after ALL sweep-driven fixes, fresh reboot): English id
  `qinling` → surname `秦` → given name `岭` → character type `2`
  (智慧型/wisdom) → gender `f` → reached the SAME starting room with
  correctly gender-specific starting equipment (散花衣/绣花小鞋 vs run
  1's 黑色劲装/牛皮靴) → `look`, `score` (same legitimate pre-birth
  message, consistent), `i` (inventory — correctly listed 2 items with
  weight%) all produced real, correct output → `quit` clean.
- `debug.log` in both sessions: **zero new errors** beyond the single
  pre-existing harmless `versiond.lpc` boot-time line.
- Confirmed `add_action`-dispatched `command_hook` in `feature/
  command.lpc` is NOT `private` (per the §15ae standing policy) — was
  found `private` initially, fixed, and the fix was empirically verified
  by `look`/`score`/`i` all actually producing dispatched output rather
  than silence.

**lpcc_check.sh sweep**: 7303 total `.lpc` files. First pass (before
sweep-driven fixes): 7272 pass / 31 fail (99.6%). After fixing the
genuine bugs found (damo.lpc ×2, quest.lpc shared-root, girl.lpc,
guidao.lpc, shoes.lpc, bowl.lpc ×2): **7289 pass / 14 fail (99.81%)** —
the remaining 14 are all confirmed-expected noise (11 story-daemon
self-destruct-when-no-players files + 2 DNS/intermud config-ID-mismatch
daemons + 1 legacy importer with no diagnostic), documented above, none
of them real bugs worth fixing.

Driver was launched via `Bash`'s `run_in_background`-equivalent
(`setsid nohup ... & disown`) each time and killed by exact PID after
each test — no `pkill -f` pattern used.

## Status for TODO.md

`playable` / `done` — full registration + post-login command flow
verified end-to-end twice, 99.81% lpcc pass rate, zero unexplained
debug.log errors. Cross-check against archives #78/#80 flagged above for
the main session once all three are complete.

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (7,303 total,
  7,273 written, 25 unchanged, 5 self-checked errors left untouched).
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`): clean boot, only the
  pre-existing benign `versiond.lpc`/`socket_bind()` line in
  `debug.log`. Full registration flow re-verified end-to-end with a
  fresh id/real Chinese surname+given-name (`aryretest`/秦岚), admin +
  regular password, character type 2 (智慧型), gender f, reaching 世外
  桃源 with correct gender-specific starting gear (鹅黄夹袄/绣花小鞋);
  `look`/`score` (correct pre-投胎 message)/`quit` all produced correct
  output.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots, but **every connection is disconnected immediately after the
  banner**, before the id prompt appears — root cause is DIFFERENT from
  the `zhonghua2`/`zhongjidiyu` finding in this same batch, and is a
  **test-harness gap, not a mudlib bug or a WASM-driver limitation**:
  `clone/user/login.lpc`'s `logon()` unconditionally calls `log_file(
  "static/logon", ...)` as its very first statement, with no `catch()`.
  This lib genuinely ships a real `/log/static/` directory in the raw
  archive (see fix #10 above — the `static`↔`nosave` naming collision
  section), so natively this always succeeds. But `scripts/
  wasm_client.js`'s `copyDir()` deliberately skips copying the CONTENTS
  of any `log/` directory (to avoid wasting time/memory on runtime-churn
  log data) and only recreates the bare `log/` directory itself in the
  in-memory FS — it does **not** recreate `log/`'s real SUBdirectories
  (`static/`, `user/`, `channel/`, `file/`, etc.), so `log_file(
  "static/logon", ...)` throws `Wrong permissions for opening file
  /log/static/logon for append. "No such file or directory"` uncaught,
  and the driver's `new_conn_handler()` disconnects the connection
  before `LOGIN_D->logon()` (the real registration flow) is ever
  reached. Confirmed via the raw harness log (the error appears, then
  immediately `new_conn_handler: logon() on object clone/user/
  login#0 has failed, the user is disconnected.`, well before any
  `versiond`-related message). **Flagged for the orchestrating session**:
  `scripts/wasm_client.js`'s `copyDir()` should also recreate `log/`'s
  known real subdirectories (or generically walk the on-disk `log/` tree
  creating directories-only, skipping only file contents) — this likely
  affects every OTHER lib in the project whose `logon()`/registration
  path writes to a `log/<subdir>/` path unconditionally at connection
  time, not just this one. Not something I patched myself since
  `scripts/wasm_client.js` is a shared script used by other agents'
  concurrent sessions. Separately, this lib ALSO shares the exact same
  unguarded `VERSION_D->is_version_ok()` pattern found on `zhonghua2`/
  `zhongjidiyu` in this batch (confirmed by grep — `adm/daemons/
  logind.lpc` has the identical `catch(MUDLIST_CMD->main()); ... if
  (!VERSION_D->is_version_ok() ...)` shape with no catch on the second
  call), so even after a harness fix for the `log/static/` gap, this lib
  would likely still hit that second, WASM-driver-level (`sockets`
  package unavailable) limitation — not chased further since the first
  blocker (harness-level) already fully explains the observed failure.
  (The VERSION_D gate is now patched — see the 2026-07 WASM-enablement
  pass below.)

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3c/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper; `is_banned()`
  returns 0 for loopback/empty/malformed IPs.
- `adm/daemons/logind.lpc` `logon()` (~line 76) and `get_id()`
  (~line 139): `VERSION_D->is_version_ok()` gates guarded with
  `find_object(VERSION_D)` (absent ⇒ version ok) — removes the
  WASM-blocking uncaught throw documented above.
- `adm/daemons/closed.lpc` `heart_beat()` and `adm/daemons/questd.lpc`
  `start_all_quest()`: same guard (both preloaded).
- The `iplimit > 3` per-IP cap in `logon()` is already `#if 0`-disabled
  upstream; no uptime()/anti-flood gates otherwise.
- **NEW pre-existing bug found & fixed — first login after every boot had
  ALL commands dead** (`update`, even `quit` → 什么？), working only from
  the second login on: `logind.lpc check_ok()` lazily loads `MESSAGE_D`
  (`/adm/daemons/network/messaged`), whose `create()` →
  `startup_udp()` → `socket_bind(fd, "10")` throws (the §15ad
  get_config-returns-string port bug), uncaught, aborting the rest of
  that first login's setup after enter_world (command path never set).
  Fixed twice over: `messaged.lpc create()` now `catch()`es
  `startup_udp()` (the UDP intermud messaging is non-essential and also
  can't work under WASM), and `check_ok()` wraps the
  `MESSAGE_D->find_chatter()` call in `catch()` (under WASM messaged
  fails to compile entirely, so the call itself would throw). Verified:
  first login after a fresh boot now has working commands.
- **§15aa second instance fixed** (`adm/simul_efun/message.lpc`): the
  local `message()` override lacked a forward declaration, so
  textually-earlier callers (`tell_room` et al) bound to the raw efun —
  surfaced as `Bad argument 4 to EFUN message()` when `update` moved the
  player (tell_room with exclude=0) despite the earlier §15s
  normalization inside the override. Added the top-of-file
  `varargs void message(...)` forward declaration (same fix as sibling
  zhongjidiyu) and made the definition `varargs`.
- Admin seeded: `fluffos` / 浮云, rank `(admin)` via `adm/etc/wizlist`.
  Two-password lineage: 管理密码 `Admin@2026`, 普通密码 `Mud@2026`
  (must differ — deviation documented in README). Registered as plain
  player first, wizlist entry + restart after. Verified: 目前权限：
  (admin), `update /d/register/entry.lpc` → 成功, clean quit, no errors.
- Retest: fresh registration (`regtest`/秦风) into 世外桃源 + relogin as
  regtest (restore path OK — this lib's sec_id checksum is the real
  implementation, unlike sibling zhongjidiyu's broken stub) + look/
  score/quit correct; test saves removed. debug.log: only the known
  versiond socket_bind line plus the now-`catch()`ed messaged
  socket_bind (logged as intercepted) — no new error classes.

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: `ftpd.lpc`/`versiond.lpc`
sockets-absent preload errors match the already-documented §1.3c class
(caught by `master.lpc`'s preload `catch()`, cosmetic); `versiond`
compile-and-fail recurs twice in one boot (two separate unguarded
callers reach `load_object`), same known class, harmless. Proactively
ported two fixes found live on sibling `zhonghua2` (shares the
identical `inherit/item/combined.lpc` and `adm/simul_efun/object.lpc`
byte-for-byte): dropped `private` on `combined.lpc`'s `destruct_me()`
(call_out-self-invocation denied under `private`→DECL_HIDDEN
inheritance, so spent-down money stacks never self-destruct), and
fixed `object.lpc`'s `file_owner()` (`return name` → `return dir`,
misattributes 3-level-deep `/u/<wiz>/<subdir>/<file>` log_error writes).
Neither fired visibly in this lib's own sit. Retest: fresh registration
(id `arysanb`) into 世外桃源, look/quit clean, no regressions.

## WASM 修复摘要（迁移自 meta.json 的 group_note）

'hell'/Doing-Lu 引擎基础版。状态已从过时的 limited 修正——本轮修复了一个真实的 bug：clone/user/login.lpc 的 query_save_file() 只防范了 id 不是字符串的情况（!stringp(id)），没有防范空字符串的情况——对 "" 取 id[0] 会回传整数 0，而 sprintf 的 %c 格式会拒绝这个值（'Incorrect argument to type %c, must be valid UTF8 char'），在任何 id 被输入之前，第一次自动呼叫 query_save_file() 就会崩溃（每一次连线尝试都会现场触发，把 id 提示搞坏）。已通过额外检查 id == "" 修复（手足档案 zhongjidiyu（052）和 zjdyzj（054）上也应用了同样的修复）。修复后重新验证管理员登录（fluffos/Mud@2026）干净正常，'目前权限：(admin)'，quit 正常。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 44 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试 / Deep functional test (AGENTS.md §10.7)

Native driver only (`~/src/fluffos/build/src/driver`, `-DPACKAGE_DB=OFF`
ASAN/UBSAN preset), booted from the lib root (`libs/zjdyaryl/`, port
40073) per §5.2. Client: `scripts/mudclient.py` (raw-socket, single
continuous connection per invocation) — `scripts/tmux_mud.sh` was tried
first but this container has no `telnet` binary at all, so every
session below is a `mudclient.py` invocation carrying the full
send-sequence in one shot (one TCP connection = one continuous session).

### Pre-boot environment gotcha (not a code bug)

First boot in this container hit `*Wrong permissions for opening file
/log/log for append. "No such file or directory"` (spammed once per
preloaded daemon, caught by `master.lpc`'s own `catch()`, non-fatal) —
neither `libs/zjdyaryl/log/` (lib-root, for `debug.log` itself, driver
CWD-relative per §5.2) nor `libs/zjdyaryl/work/log/{static,user}/`
(mudlib-virtual-root, for `log_file()`/`assure_file()` targets like
`clone/user/login.lpc`'s `log_file("static/logon", ...)`) existed yet in
this fresh container — both are gitignored runtime directories that a
prior pass's WASM-enablement notes assumed were already present. Created
both (`mkdir -p log log/static log/user`, lib-root and `work/`
respectively) before the real test boot; zero `Wrong permissions` lines
in every subsequent boot. Not committed (gitignored), noted here so a
future dive in a fresh container doesn't misread the same symptom as a
regression in the already-fixed `log_file()`/`assure_file()` pair
(`adm/simul_efun/file.lpc`'s `log_file()` genuinely still lacks its own
`assure_file()` guard, matching this lineage's known §7.11 shape, but
every actual call site either goes through an already-`assure_file()`d
caller — e.g. `channeld.lpc` — or targets a directory that exists once
the above `mkdir -p` is done; no live crash reproduced from it this
pass).

### Newbie material

`clone/misc/newbie.lpc`("新手必读") is a `read book` → `HELP_CMD->main(me,
"feature")` pointer, but the real onboarding path is entirely
NPC-driven: land in 世外桃源 (`d/register/entry.lpc`) →
水笙(shuisheng)'s `greeting()`/`do_register()` prompts `register
<email>` → `decide` → walk to one of 4 personality-NPC rooms (`east` =
陆天抒/"光明磊落") → `out` → 阎罗殿(`yanluodian.lpc`) → `wash` (roll the
4 stats per chosen 猛士/智慧/耐力/敏捷/均衡 type) → `born <地名>` (e.g.
`born 扬州人氏`) lands in a real starting city (`/d/city/kedian`).

### Registration + state verification (two independent continuous sessions)

- **卫长风** (id `weifeng`, male, 敏捷型): full register→decide→east→
  out→wash→`born 扬州人氏` in one connection, `look`/`score`/`i` at every
  state change (pre-birth `还没有出生呐` message pre-`born`, correct
  gender-appropriate starting gear post-`born`), landed in 客店 →
  `west` to 北大街.
- **蓝天** (id `lantian`, female, 耐力型): identical flow, independently
  verified gender-specific gear (绣花小鞋/粉红绸衫) and stat allocation
  (根骨 highest, matching 耐力型).
- Cosmetic note, not a bug: the starting `cloth` clone's displayed name
  re-rolls a random flavor variant on each fresh `create()` (短打劲装 /
  黑色劲装 across weifeng's own sessions) — core inventory count, weight%
  and all persisted stats stayed exactly consistent across reconnects.

### Combat mechanism

Read `cmds/std/fight.lpc` before testing, per this session's standing
lead: confirmed the exact `can_speak`-gated split it was looking for —
`obj->query("can_speak")` true → routes through `obj->accept_fight(me)`
(decline-or-spar, "点到为止...不会真的受伤" per `fight`'s own help text);
false → unconditionally `obj->kill_ob(me)`, a real fight. Default
`accept_fight()` (`inherit/char/npc.lpc`) itself calls `kill_ob()`
directly when `!can_speak`, so the split is enforced at both call sites,
consistently — existing, intentional design, not a bug (matches the
pattern already documented project-wide; did not test the non-`can_speak`
branch against a live creature, by design, since that branch is
genuinely lethal).

Live test: `fight ouyang ke` (欧阳克, a human/`can_speak` story NPC at
北大街) correctly invoked `accept_fight()` — declined in-character
("在下怎么可能是小兄弟的对手？" / "看起来欧阳克并不想跟你较量。") because
its `attitude` is `"friendly"` and its qi/jing were both at 100%
(`inherit/char/npc.lpc`'s default `accept_fight()`: `"friendly"` +
≥75% qi/jing → decline). A real, clean exercise of the safe branch with
a negative outcome — no damage, no crash, no error. (This same fight
attempt is also what first reproduced the `eval_function` bug below, via
`combatd.lpc`'s post-fight-request `start_call_out()`.)

### Skill/sect acquisition — both paths

- **Organic**: `apprentice ouyang ke` correctly dispatched
  `attempt_apprentice()` → `permit_recruit()` (`kungfu/class/ouyang/
  ouyang.h`) → declined in-character ("你不是我们欧阳家的人，我怎能收你
  为徒？") because the test character's `born_family` wasn't 欧阳世家.
  Confirmed the full mechanism runs end-to-end without error; a
  successful join would require `born 欧阳世家` instead of `born
  扬州人氏` at registration (not repeated with a 3rd character, given
  time budget — the declining path already proves
  `apprentice`→`attempt_apprentice`→`permit_recruit` all resolve and
  execute correctly, which is what this session was actually checking
  for after `permit_recruit()` initially looked suspiciously undefined
  by a too-narrow grep — see below).
- **Admin shortcut**: `cmds/arch/setsk.lpc` (`setsk [<对象>] <技能>
  <级别>`, `(arch)`-gated) — confirmed working live on the admin account
  itself (`setsk force 30` → 目标：浮云(fluffos) 设定技能：force 等级：
  30; `setsk force 0` → 取消技能：force). `cmds/wiz/copyskill.lpc`
  (`(wizard)`-gated, copies an existing character's whole skill/stat set
  onto another) is a second, independent shortcut. Could not test
  `setsk`/`copyskill` against the offline test characters directly
  (both commands require the *target* to be a currently-loaded/online
  `living()` object, not just a save file — correct, intentional
  behavior, reproduced as "目标不存在，如果是设定自身技能，目标参数可
  作缺省。" when targeting an offline `lantian`), so verified the
  mechanism on the admin's own account instead.
- **False-alarm investigated and cleared**: `permit_recruit()` (called
  unqualified from every sect-master NPC's `attempt_apprentice()`, 125+
  call sites under `kungfu/class/*/`) appeared completely undefined
  anywhere in the tree on a first grep — worth flagging since an
  undefined local function call would be a genuine crash-on-every-
  apprentice-attempt bug. Root cause of the false alarm: my own filter
  excluded `kungfu/class/` from the search entirely. Each sect actually
  defines its own `permit_recruit()` in a shared per-sect header
  (`kungfu/class/ouyang/ouyang.h`, `kungfu/class/quanzhen/quanzhen.h`,
  etc., byte-identical to sibling `zjdyzj`/`zjdywzb`/`zjdy2008wzb`),
  `#include`d by every NPC file in that sect directory. Confirmed via
  `lpcc --batch` compiling `kungfu/class/ouyang/ouyangke` cleanly and
  the live `apprentice` test above actually reaching `permit_recruit()`'s
  real decline logic. No bug here — noted so a future pass doesn't
  re-walk the same dead end.

### quit / reconnect / persistence

`cmds/usr/quit.lpc` has no new-account grace-period or delete-on-quit
logic (checked before testing) — ordinary `quit` is always safe here,
no need to simulate a raw disconnect instead. Existing design, not a
bug: non-wizards get all non-equipped, non-autoload inventory dropped on
`quit` (anti-hoarding-while-offline mechanic).

- `weifeng`: registered → played → **reconnected mid-test** (prior
  connection had ended without an explicit `quit`, so the driver
  correctly treated the next connection as "重新连线完毕" / link-dead
  reconnect rather than a fresh login — same character, same room) →
  `look`/`quit` clean ("欢迎下次再来！").
- `lantian`: registered → played → clean `quit` → **driver fully
  restarted** (killed by exact PID, rebooted with the `maximum
  evaluation cost` fix below applied) → real wall-clock gap while this
  fix was written up and the driver reboot completed → reconnected:
  name/gender/stats/location/inventory/`born`/`registered` status all
  persisted correctly from the on-disk save, unchanged. `debug.log`
  after every session in this pass: zero unexplained errors (grepped
  both `libs/zjdyaryl/log/debug.log`, the only `debug.log` this lib
  produces — no separate `work/log/debug.log` exists, `log directory`
  is lib-root-relative per §5.2 here).

## Bugs found and fixed

1. **§8.3a addendum, 3rd confirmed instance: `feature/action.lpc`'s
   `eval_function()` declared `private`.** `private`→`DECL_HIDDEN`
   demotion-on-inheritance (this file is `inherit`ed into every
   character via `inherit/char/char.lpc`) silently blocks the
   `call_out("eval_function", ...)` dispatch that `start_call_out()`
   (this file's own general-purpose "run this function after a delay"
   primitive) relies on — 91 files across the tree call
   `start_call_out()`, including `adm/daemons/combatd.lpc` and 80+
   `kungfu/skill/`/`kungfu/special/` buff/poison/powerup files. Reproduced
   live: `debug.log` showed `apply() with insufficient permission: ...
   ob: clone/user/user#N, function: eval_function, origin: internal,
   needs: private, has: hidden` immediately after an ordinary declined
   `fight` command (which schedules a `combatd.lpc` recovery callback via
   `start_call_out()`). **Fix**: dropped `private`
   (`void eval_function(function fun) { evaluate(fun); }`). Re-tested the
   identical `fight` decline post-fix, fresh boot: zero further
   `eval_function`/`insufficient permission` lines. Also fixed the
   identically-shaped `clone/questob/letter.lpc:private void
   eval_function(...)` for consistency — not confirmed live-triggered
   (nothing in that file actually schedules a `call_out("eval_function"`
   itself, so it may be dead code), but same bug shape, same trivial fix,
   zero risk.
2. **§7.90, 5th confirmed instance (new lineage): `maximum evaluation
   cost : 2000000`** (`config.fluffos`) was too tight — not tripped by
   registration or movement, but by ordinary background daemon activity:
   `adm/daemons/quest/capture.lpc`'s periodic `heart_beat()` spawning a
   `kungfu/class/generate/capturenpc3` NPC whose randomly-chosen
   `setup_family()` branch (`from_xueshan()`) hit `Eval interrupted: ...
   cost limit reached, limit: 2000000 usec` mid-`set_skill()`/ACL-check,
   roughly 20 minutes into an otherwise-idle boot with no player nearby.
   **Fix**: raised to `5000000` (established §7.90 remedy value, already
   used by 30+ other libs). Verified: fresh boot + full replay of both
   registration sessions + the `fight`/`apprentice`/`setsk` tests above,
   zero further `cost limit reached` lines in `debug.log`.

## 发现但判定为既有设计、未改动的现象 (observations, not bugs)

- `fight` command's `can_speak` split (safe spar vs. real `kill_ob()`) —
  confirmed intentional, documented in the command's own `help fight`
  text; only the `can_speak` branch was exercised, by design.
- 欧阳克 declining `fight` (friendly attitude, full qi/jing) and 欧阳克
  declining `apprentice` (wrong `born_family`) — both correct,
  in-character existing gating logic, not bugs.
- Starting `cloth` clone's cosmetic flavor-name re-roll across sessions
  — cosmetic only, no data-persistence issue (see above).
- `setsk`/`copyskill` requiring a *loaded* (online) target object rather
  than accepting an offline save file — correct, intentional behavior
  for a live-stat-copy command, not a limitation worth changing.

## WASM 未验证说明

Not re-verified under WASM this pass (native-only, per this project's
current WASM build blocker). Confirm via:
`curl -sS "$HTTPS_PROXY/__agentproxy/status"` — emsdk's
`storage.googleapis.com` dependency is denied by the proxy, unchanged
from every other lib checked this session. This lib's own prior
WASM-enablement pass (2026-07, above) already covers WASM-specific gates
(`VERSION_D`, `messaged.lpc` socket_bind, loopback allow); the two fixes
in this pass (`eval_function` visibility, eval-cost ceiling) are
driver-behavior-general and apply identically under WASM once it's
buildable again in this environment.

## 深度功能测试第二轮 / Deep functional test round 2 (2026-08-15, post driver-upgrade re-test)

Round-two re-verification against the current native `build-debug` driver
(post-upgrade — pulls in PRs #1343/#1344 and the corpus-wide `%`-operator
float-crash fix). Standard checklist + live playthrough-style verification.
The prior pass's own reconnect test only covered the link-dead/wall-clock-
gap path, not the kick-duplicate-login confirmation path — this round adds
that.

Findings:

1. **AGENTS.md §7.107** (`adm/daemons/closed.lpc`'s `load_all_users()`
   calling `login_ob->restore()`/`user_ob->restore()` with no `catch()`
   guard): a corrupted closed-cultivation account's save data would throw
   uncaught, aborting the whole `heart_beat()` tick before the cleanup
   (`destruct()`+`map_delete()`) runs, and retrying forever. Fixed by
   wrapping both `restore()` calls in `catch()` with an `ok` flag, same
   pattern as the other confirmed instances of this class this window.
2. **AGENTS.md §7.108** (`clone/user/user.lpc`'s `reconnect()` missing
   `enable_commands()`): confirmed active `LOGIN_D` (`adm/daemons/logind.lpc`)
   calls `user->reconnect()` on the character body after `exec(old_link,
   user)`. Fixed by adding `enable_commands();` as the first statement.
   Live-verified with two concurrent telnet sessions: session 2 logged in
   as `fluffos` (this lib's regular login password `Mud@2026`), confirmed
   the "赶出去，取而代之吗？(y/n)" prompt with `y`, and the resulting
   session correctly dispatched `look` (real room description). `score`
   returned "还没有出生呐" — expected content-gated response for this
   still-unregistered admin account (not a bug; same pattern as
   previously confirmed on sibling lib xkxz2), confirmed harmless by
   cross-checking with `look`.
3. **`adm/simul_efun/file.lpc`**: `log_file()` never called `assure_file()`
   before `write_file()`; added the call (plus a forward declaration).
   `cat()`'s `write(read_file(file))` had no null-guard; changed to
   `write(read_file(file) || "")`.
4. **Already correct, no change needed**: `cmds/wiz/update.lpc` already
   guards with `environment(me) &&`. `adm/single/master.lpc`'s
   `log_error()` already uses the case-agnostic `"arning:"` filter
   (AGENTS.md §7.10). `maximum evaluation cost` was already `5000000`
   (raised in an earlier pass per this NOTES.md's own §8.3a section).

Live verification summary: booted the native driver on port 40073 (the
known-harmless, previously-documented `versiond.lpc socket_bind()`
argument-type error fired again at boot as expected, non-fatal;
`Initializations complete` / `Accepting telnet connections` both
printed). Logged in as the seeded `fluffos` admin (`Mud@2026`), confirmed
real write access via `update /adm/simul_efun/file` (recompiled
successfully). Ran the two-session kick-duplicate-login reconnect test
described above and confirmed the §7.108 fix live — this specific path
(distinct from the link-dead reconnect this lib's earlier passes already
covered) had not been exercised before. No new error classes in
`log/debug.log` beyond the known `versiond`/boot-time line. Killed the
driver by exact PID when done.

本轮修改的文件 / Files modified this round:
- `libs/zjdyaryl/work/adm/daemons/closed.lpc`
- `libs/zjdyaryl/work/clone/user/user.lpc`
- `libs/zjdyaryl/work/adm/simul_efun/file.lpc`

## AGENTS.md §7.100 fix (2026-08-19): redundant replace_program(ROOM) landmine

Same corpus-wide bug as the batch-1-6 sweep (`ROOM` macro
`"/inherit/room/room"` from `include/globals.h`). Deleted 2,315 live
standalone `replace_program(ROOM);` lines under `work/` via
`fix_710_room.py`, plus hand-fixed the room-building tool's
string-builder template (`work/clone/misc/roommaker.lpc`). No `.lpc`
files under `work/data/`, so no false-negative risk. Remaining matches
after the fix are all pre-existing `//`-commented.

Verified: clean `build-debug` boot (zero new compile errors, zero
"cannot replace"/"cannot bind" in `debug.log`), live admin login
(`fluffos`/`Mud@2026`) into the game world, `look`/`quit` worked
cleanly (`score`'s "还没有出生呐" is pre-existing admin-account
behavior). Incidental `data/{login,user}/f/fluffos.o` save drift from
the login test was reverted via `git checkout HEAD` before
committing.

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 5 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.
