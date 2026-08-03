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
