# hymud — 海洋V·星月传奇 (Ocean V / Star-Moon Legend)

Archive: `hymud-main.zip` (GitHub repo download, commit
b9433df6cf48e936b07252b15b60806ff55bb2f3, files dated 2021-04-07). Port:
**40103**. Status: **done** (boots clean, full registration flow
verified end-to-end natively AND under WASM, admin account seeded and
verified).

## What this is

Despite the "-main" GitHub suffix suggesting a modern maintained repo,
this is NOT FluffOS-ready out of the box: it is a GBK-encoded, `.c`-
extension MudOS-era mudlib (bundled `MudOS.exe`, `config.cfg` labeled
"MudOS V22.2b13的可定制运行配置文件") that someone happened to keep in a
git repo. The repo owner DID do some partial modernization before us:
`adm/single/master.c` used `protected` instead of `static` on functions
(behind a now-neutralized `#ifndef __SENSIBLE_MODIFIERS__` compat shim),
and `feature/command.c`'s `command_hook` already had its `private`
dropped (the original line survives as a comment). Everything else
(encoding, extensions, GBK byte-range Chinese checks) needed the full
standard conversion pipeline — this was not a near-no-op.

Identity: `include/mudlib.h`'s `INTERMUD_MUD_NAME`/`CHINESE_MUD_NAME` =
**海洋V**; the live login banner says 〖海洋V-星月传奇〗; the bundled
`readme.txt` is an old 海洋II 2002 新春特别版 release note (mismatched
vintage — cosmetic, not a real identity conflict, matching a pattern
this project has seen before with stale bundled docs).

Size: 60,064 raw files, 57,097 `.c` files, 286 MB — the largest lib in
this collection so far (~2x haiyang2's ~29,700). Ran the full conversion
+ testing without memory issues (single-machine interactive test, not
the `lpcc_check.sh` batch sweep — skipped given the size and that the
interactive test already covers the boot + registration path per
AGENTS.md §10.4's mega-lib guidance).

## Lineage: 043-1 (derivative of haiyang2 / 海洋II, same codebase)

Confirmed by diff (GB18030-decoded, CR-stripped, whitespace-normalized)
against `haiyang2`'s raw archive:

- `adm/obj/master.c` (the unused duplicate copy in both libs): **0
  normalized diff lines** — byte-identical modulo encoding/CRLF.
- `adm/daemons/chinesed.c`, `adm/daemons/combatd.c`, `feature/dbase.c`:
  **0 normalized diff lines** vs haiyang2's copies.
- The LIVE `adm/single/master.c`: 385 diff lines, but every one is
  cosmetic/mechanical — `static`→`protected` modifier swap, whitespace,
  and an added `XMUD_PORT`-gated cosmetic `connect()` branch (harmless,
  matches AGENTS.md §5.3's "hardcoded port constant only sets a cosmetic
  flag" precedent — read what it gates before "fixing" it: here it just
  sets `set_temp("xmud",1)`, never touched further since nothing in this
  build listens on that port).
- Same custom `adm/daemons/securd.lpc` ACL daemon (identical function
  set, identical `restore_list()` `hxsd` hardcoded-admin-backdoor idiom).
- Same `adm/single` layout, same `feature/dbase.lpc` real per-object
  storage (confirmed via `grep` for `efun::set(`/`efun::query(`/
  `efun::delete(` across the whole tree — comes up empty, so the nitan-
  family shared-simul_efun-dbase bug, AGENTS.md §7.15, does NOT apply
  here, same conclusion as haiyang2).
- `logind.lpc` is a further-edited descendant of haiyang2's copy (live
  DNS_MASTER intermud mud-list rendering that haiyang2 had already
  disabled/rewritten, extra per-IP connection-count limits, a different
  registration throttle) — clearly the same lineage, independently
  drifted, not a byte match, consistent with AGENTS.md §2.1's "ported
  fixes still need per-lib verification" caveat.

**Numbering proposal: `043-1`**, slug `hymud`, alongside `haiyang2`
(043) in the 海洋 (Ocean) family group.

## Fixes applied

1. **Tooling quirk (§4.2 item 6, directory-named-like-a-file)**: the
   blind `.c`→`.lpc` rename hit three directories literally named
   `<name>.c/` (containing a single file inside): `u/hxsd/workrom.c/`
   (containing `workroom.c` — **the exact same path/quirk documented for
   haiyang2**, further confirming the shared lineage; a real sibling
   `workroom.lpc` already exists, so this is genuinely dead/orphaned),
   `u/spraydew/teamjob.c/teamjob.c`, and `u/hxsd/taskd.c/taskd.c` (no
   sibling for these two, but `grep` across the whole tree confirms zero
   references to either path anywhere — dead wizard-sandbox content).
   Renamed all three directories to `.orphaned-dir` and their inner
   files to `.lpc` for tidiness.
2. **256 uppercase `.C` files** (§4.2 item 7) — missed by both the
   rename glob and the forced-text-extension conversion check (both
   case-sensitive). All 256 were ALREADY valid UTF-8 (not GBK) —
   confirmed via a Python UTF-8-decode pass before renaming, so no
   re-encoding was needed, just the extension fix. Cross-checked (single
   combined-regex grep) that no source file anywhere references the old
   uppercase `.C` spelling literally — zero hits, safe.
3. **One GBK straggler `convert_lib.sh` missed**:
   `d/xiyou/sea/npc/beast1.lpc` — `file(1)` classified it as generic
   "data" (not text) because of 2 trailing garbage bytes (`\xff\xba`,
   not valid GB18030 or UTF-8) sitting right after the file's final
   closing brace, so the automated pass skipped it entirely and it
   stayed raw GBK. Found via a full Python UTF-8-decode validation scan
   across every `.lpc`/`.h` file (AGENTS.md §4.1's stronger check).
   Fixed: stripped the 2 trailing garbage bytes, then GB18030→UTF-8
   decoded the rest.
4. **20 additional GBK-text stragglers** outside the forced-text
   extension list — extensionless help/map/poem/board content files
   (`doc/board/yb029.java`, `doc/board/yb010`, `doc/board/yb028`,
   `doc/map/{gaoli,paiyun}`, `doc/help/{map_py,newbie_mr,map_xiy,map_gl}`,
   `doc/legend/xkx10`, `doc/help.java/helpdoc`, `clone/game/{8_hlp,
   helppai,21_hlp}`, `d/city4/poem/{poem228,poem74,poem175}`,
   `d/heifeng/map_py`, `d/mingjiao/hsqtan`, `d/paiyun/map_py`) that
   `file(1)` misclassified as DOS `.COM` executables / OpenPGP keys
   (raw GBK bytes coincidentally matching those magic signatures).
   Verified each decodes cleanly as GB18030 before converting (one
   near-miss, `d/city4/mj/mj.MUD`, turned out to be genuine binary
   compiled map-editor state, left untouched). A handful of other
   `file`-misclassified hits (`gift.f`, `fightnpc1.err`,
   `pianzi.c.old`/`.old`, `yanbook.c2`, `.swp`, `.rar` files, and the GBK
   bitmap font files under `adm/etc/language/`) were confirmed genuinely
   binary/non-source via a raw-byte peek and left alone.
5. **AGENTS.md §8.1 (is_chinese, GBK byte-range check)** —
   `adm/simul_efun/chinese.lpc`'s `is_chinese()` used the GBK lead-byte
   range test (`str[0]>160 && str[0]<255`), always false against this
   driver's Unicode codepoints. Rewritten to the CJK Unified Ideographs
   range check; length floor relaxed 2→1 for the sliding-window
   caller's 1-character suffix case.
6. **AGENTS.md §8.1 (chinesed.lpc's check_chinese, dead code)** — same
   GBK-byte-parity `i%2==0` shape, fixed for consistency even though
   `grep` confirms zero callers anywhere in the tree.
7. **AGENTS.md §8.1 (logind.lpc's check_legal_name, THE live check)** —
   halved the byte-calibrated length bound (`strlen<4||>10` → `<2||>5`,
   matching the message text's own "2 到 5 个中文字"), and dropped the
   `i%2==0` GBK-byte-parity gate from both sliding-window `is_chinese()`
   checks. **Verified live**: a real Chinese name (秦风, then 秦岭) was
   accepted immediately with no rejection, all the way into the game
   world, in both native and WASM test runs.
8. **AGENTS.md §1.3b (loopback-allow, ban gate)** — `logind.lpc`'s
   `BAN_D->is_banned(query_ip_name(ob))` call site (site-ban check)
   short-circuited for loopback/malformed IPs before ever calling
   `is_banned()`.
9. **AGENTS.md §1.3e (legacy connection-time gates, bypassed for
   loopback)** — four distinct circa-2000 hosting-protection gates in
   `logind.lpc`, each real and each independently discovered by actually
   running the interactive flow multiple times from the same test
   machine:
   - per-IP simultaneous-connection cap (`iplimit>22`, two branches);
   - "one concurrent login per source IP" gate (blocks a second
     connection from the same IP while the first is mid-login);
   - the new-registration per-IP throttle (`loginnip`/`loginntime`,
     labelled "60秒" in the message though the code itself only checks
     1 second — a pre-existing discrepancy in the original, left as-is
     since the loopback bypass makes it moot either way);
   - the re-login throttle (`time_rl<=60 && !wizpwd`) AND the
     wrong-password lockout (`time_pwd<=30`) in `get_passwd()` — both
     discovered while setting up and testing the admin account, since
     rapid repeat test logins from the same test harness tripped them
     immediately.
   All four now exempt `query_ip_number(ob) == "127.0.0.1"`.
10. **AGENTS.md §1.3c (DNS_MASTER, inline call not preload)** —
    `logind.lpc`'s `gb_big5()` (the very first thing every connection
    runs) unconditionally called `DNS_MASTER->query_muds()`/
    `query_svc()` to render an intermud "connected MUDs" table.
    `DNS_MASTER` is never preloaded and its `create()` does real
    `resolve()`/`socket_create()` work against a hardcoded remote
    intermud boot server. Disabled: `mud_list`/`mud_svc` set to empty
    mappings directly, never touching `DNS_MASTER`. Also redefined the
    `Mud_name()` macro (`include/net/macros.h`) to return the
    `INTERMUD_MUD_NAME` constant directly instead of calling
    `DNS_MASTER->query_mud_name()` — confirmed via `grep` this macro is
    the only one from that header used anywhere outside the (never
    reachable) network-daemon family itself.
11. **AGENTS.md §7.9 (sscanf/write(read_file) crash bomb)** —
    `cmds/usr/uptime.lpc` (called unconditionally from `logind.lpc`'s
    `gb_big5()`, before the id prompt) did
    `write(read_file("/log/nosave/LASTCRASH")+"\n"NOR)` unguarded;
    LASTCRASH is runtime data, absent on a fresh checkout, so
    `read_file()` returns 0 and the `+` against a bare int would crash
    every fresh connection. Guarded with `stringp()`.
12. **AGENTS.md §7.11 (pre-login receive_message twin)** —
    `clone/user/login.lpc`'s `receive_message()` lacked the
    `!stringp(str)` guard the real player body's copy
    (`feature/message.lpc`) already has; `write(0)` is a routine idiom
    in this lineage. Added the guard.
13. **AGENTS.md §7.12/§8.1(15s) (message() 4th-arg type rejection)** —
    `adm/simul_efun/message.lpc`'s `tell_room(ob, str, exclude)`
    (varargs, `exclude` defaults to bare int 0 on the overwhelmingly
    common 2-arg call) passed that literal 0 into the real `message()`
    efun's 4th arg, declared `void|object|object*` — doesn't accept a
    literal int. Fixed with `exclude || ({})`. Hardened `shout()`
    identically (`this_player() || ({})`).
14. **AGENTS.md §7.5 (custom ACL, no compile-time discrimination)** —
    `adm/daemons/securd.lpc`'s `valid_read()` had zero `func`
    discrimination for compile-time access at all. Added the standard
    early `switch(func){case "load_object": case "recompile_object":
    case "include": return 1;}` allowlist.
15. **AGENTS.md §10.4 (valid_override 3-arg)** — `adm/single/master.lpc`
    upgraded from the 2-arg to the 3-arg `(file, name, main_file)`
    signature.
16. **AGENTS.md §6.1/§8d (get_include_path missing entirely)** —
    `master.lpc` had NO `get_include_path()` apply at all; added the
    standard one (prepends the compiling file's own directory).
17. **AGENTS.md §4.3 (nosave/protected compat-shim collision)** — the
    blind `static`→`nosave` sed turned `#ifndef __SENSIBLE_MODIFIERS__ /
    #define nosave static / #define protected static` into
    `#define protected nosave`, which would have silently aliased
    `protected` to `nosave` (both are real, distinct keywords on this
    driver — no shim needed at all). Neutralized the whole shim.
18. **AGENTS.md §4.3 (quoted-string static/ path collision)** — the same
    blind sed corrupted 31 files' quoted `"static/XXX"` log/save path
    literals into `"nosave/XXX"` (e.g. `"static/CRASHES"`,
    `"static/VI"`, `"static/ZS"`, `"static/EXP"`, `"static/CALL_PLAYER"`
    across several `u/<wizard>/` sandbox copies, `securd.lpc`,
    `master.lpc`/`masterold.lpc`, several `quit`/`purge`/`call`
    commands). Verified every single hit against the raw archive bytes
    (all 31 confirmed genuine collisions, zero false positives —
    checked that none of the 31 files had a pre-existing genuine
    `"nosave/` string in the original) and reverted `"nosave/` →
    `"static/` in exactly those files.
19. **AGENTS.md §7.14 (environment(me) quit race)** —
    `cmds/usr/quitgame.lpc` (called directly, not via verb dispatch,
    from net-dead/idle-timeout auto-quit paths in `clone/user/user.lpc`
    and `d/welcome/welcome.lpc`) had an unguarded
    `environment(me)->query("valid_startroom")`. Guarded with
    `environment(me) &&`.
20. **Preload path typo** — both `adm/etc/preload` (the live one,
    matching `CONFIG_DIR`) and the unused `adm/daemons/preload` decoy
    copy listed `/adm/daemons/securityd`, but the real file is
    `securd.c`/`.lpc` (matches `include/globals.h`'s `#define
    SECURITY_D "/adm/daemons/securd"`) — same typo shape documented for
    haiyang2/wmkj. Fixed the live copy's path.
21. **Missing save-data shard directories (§7.11)** — `data/user/` and
    `data/login/` shipped completely EMPTY (no `a`-`z` subdirectories at
    all), so the very first registration's `save_object()` (a bare
    fopen, no mkdir) would have failed silently. Also `data/mail/` uses
    the same `<letter>/` sharding. Created all 26 lowercase shard dirs
    for `user`, `login`, and `mail`; created `libs/hymud/work/log/mud/`
    for the `VISITORS`/`GIFTCARD` counter writes (mudlib-relative path,
    independent of the driver's CWD-relative `log directory` config
    setting); created `libs/hymud/log/` (the driver's own debug-log
    directory, sibling of `config.fluffos`, per AGENTS.md §5.2).
    **Known limitation, matching existing project precedent
    (`haiyang2` has the identical shape)**: git does not track empty
    directories, so on a truly fresh clone only the shard letters that
    end up containing at least one real save file (from testing) will
    persist — e.g. `data/user/f/` (the seeded `fluffos` admin) survives,
    but an untested letter would still hit the missing-directory bug on
    a real player's first registration post-clone. Not solved more
    thoroughly here than the rest of the project has solved it for
    other libs; flagged for whoever eventually addresses it project-wide
    (e.g. a `.gitkeep`-per-shard convention, or a boot-time
    `mkdir_p_all_shards()` call in `master.lpc`'s `create()`).

## What was checked and confirmed NOT needed

- **§7.1 (lazy security-daemon load recursion)**: `master.lpc`'s
  `valid_read`/`valid_write` only ever `find_object(SECURITY_D)`, never
  `load_object()`. Not applicable.
- **§7.2 (missing get_root_uid/get_bb_uid)**: both already present.
- **§7.3 (destruct SIMUL_EFUN_OB in create())**: `master.lpc`'s
  `create()` is just a `write()`. Not applicable.
- **§7.4 (this_player() ACL-identity override)**: `securd.lpc`'s
  `valid_read`/`valid_write` use the passed-in `user` argument directly,
  never call `this_player()`. Not applicable.
- **§6.1/6.3 grammar traps** (`ed_start`/`ed_cmd`, switch-default-only,
  `MACRO.0` float trick, multi-char literals, bare `array x;`): none
  present, confirmed by targeted greps.
- **§6.6 (convertd.lpc Greek-table stray backslash)**: not present in
  this copy.
- **§7.15 (nitan-family shared-simul_efun-dbase bug)**: confirmed real
  per-object storage in `feature/dbase.lpc`; `efun::set/query/delete`
  grep across the whole tree is empty. Not applicable (same conclusion
  as haiyang2, independently re-verified here).
- **§8.3a (private command_hook)**: already fixed upstream by the repo's
  own author (the `private` keyword survives only in a comment).
- **§8.3b (dead command-indexer sscanf)**: `commandd.lpc`'s
  `sscanf(cmds[i], "%s.c", cmds[i])` was already caught and fixed by
  `convert_lib.sh`'s blind literal-`.c"`-reference fixer (the format
  string `"%s.c"` matches that regex too) — confirmed the file now
  reads `"%s.lpc"`. No manual fix needed.
- **`message_sort` never-defined simul_efun**: called from exactly 2
  kung-fu skill files, but the call site is commented out (dead code) in
  both. Not reachable, not fixed.
- **`remove_ansi`/`noansi_strlen` never-defined simul_efuns**: called
  only from decorative kung-fu skill content files and one wizard's
  personal sandbox `channeld.lpc` copy (`u/lonely/`) — never on the
  boot/registration/live-daemon path. Logged, not fixed (breadth over
  depth).

## Non-blocking pre-existing content bug (logged, not fixed)

`adm/daemons/taskd.lpc`'s periodic `auto_save()`/`give_gift()` (a
delivery-quest scheduler, reached via `call_out`/heartbeat, independent
of any player connecting) hits `*Bad argument 1 to EFUN call_other():
Expected: object, string, array, Got: int(0)` at taskd.lpc line 889 —
caught by the driver's error handler each time, non-fatal, recurs
periodically regardless of whether anyone is logged in. Also one
one-off instance of the same error class during preload
(`/kungfu/class/qingcheng/yu.lpc` create() chain via `questd`'s
`spread_quest()`). Neither is on the registration/login/look/score/quit
path exercised by verification; not chased further given the "breadth
over depth" policy for a single archive among ~100.

## Registration flow (read from logind.lpc's input_to chain)

`logon()` → `gb_big5` (GB/Big5 charset prompt; renders the now-disabled
intermud mud-list, calls `UPTIME_CMD->main()`, ban check, per-IP
connection-count cap, visitor counters) → `get_id` (English id;
same-id and same-IP concurrent-login gates) → `confirm_id` (y/n; 1-second
same-IP registration throttle, message says "60秒") → `get_name`
(Chinese name via `check_legal_name` — no confirm step for a typed name;
`get_resp` confirm only fires for the random-name path when you press
Enter with no input) → `new_password`/`confirm_password` (6+ chars,
needs upper+lower+digit, `check_legal_password` message text says "六个
字符" but the actual length floor is 5) → `select_gift`/`get_gift` (0-4
choice, then y/n to accept a randomly-rolled attribute spread) →
`get_email` → `get_gender` (m/f) → `enter_world`. START_ROOM =
`/d/welcome/welcome` ("世界之树" / World Tree, a hub room with exits in
all 4 directions to different zones).

Re-login (existing account) additionally goes through `get_passwd()`,
which is where the re-login throttle and wrong-password lockout live
(fixed above, item 9).

## Native verification — registration run 1 (before item 8/9/etc fixes)

id `qinfeng`, real Chinese name **秦风** (accepted immediately, no
rejection — confirms the §8.1 fix), password `Test123`/`Test123`, gift
`0`→`y`, gender `m` — reached 世界之树, `look` and `score` both correct
(score showed 秦风/Qinfeng, correct gender/age/stats table).

## Native verification — registration run 2 (after all fixes, clean run)

id `qinling`, real Chinese name **秦岭** (2 characters — exercises the
lower end of the 2-5 character bound), password `Test123`/`Test123`,
gift `0`→`y`, gender `f` — reached 世界之树, "【江湖通告】：热烈欢迎新
玩家 秦岭(qinling)来到HYMUD！" broadcast rendered correctly, `look`
correct, `score` correct (showed 秦岭/Qinling, 女性人类), `quit` saved
cleanly ("正在退出游戏 ,档案保存中......"). `debug.log` for the full
session: zero matches for `bad argument|denied|recursion|segmentation|
undefined function|cannot #include|couldn't find object|too deep|abort|
fatal` outside the two known non-blocking `taskd.lpc` timer errors
(see above) — only expected cosmetic "unused local variable" compile
warnings.

## Admin account seeding

1. Registered `fluffos` through the NORMAL registration flow (id
   `fluffos`, real Chinese name **浮浮**, password `Mud@2026`, gender
   `m`) — accepted with no id-length/reserved-word rejection.
2. Granted `(admin)` via `adm/daemons/securd.lpc`'s own
   `restore_list()` hardcoded-backdoor mechanism, the exact same idiom
   the original author used to guarantee `hxsd` always has admin:
   added a parallel `set("wiz_status/fluffos","(admin)")` line
   immediately after the existing `hxsd` one. This re-applies on every
   boot regardless of `securd.o`'s saved content, so it survives a save
   file reset.
3. **Verified**: logged in as `fluffos`/`Mud@2026`, set the account's
   separate WIZ password (`wizpwd` command — this lineage's login flow
   asks for id → **WIZ password** (once `wizpwd` is set) → account
   password, in that order) to `Mud@2026` as well, then ran
   `update /adm/daemons/logind` — recompiled successfully ("成功！"),
   confirming both the wizard-level command-path resolution
   (`(admin)` → `ADM_PATH` → `cmds/adm/`, `cmds/arch/`, `cmds/wiz/`,
   `cmds/imm/`, ...) and the `securd.lpc` ACL's compile-time allowlist
   (item 14 above) both work correctly. Room descriptions for `fluffos`
   also show the file path suffix (e.g. "【世界之树】 -
   /d/welcome/welcome"), a wizard-only display feature, confirming
   elevated status end-to-end.
4. **Discovered and fixed while testing this**: the re-login throttle
   and wrong-password lockout (item 9 above) — rapid repeated test
   logins from the same loopback address tripped both, which is exactly
   the kind of gate AGENTS.md §1.3e calls out for bypass.

Save files: `data/login/f/fluffos.o`, `data/user/f/fluffos.o`.

## WASM verification

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src libs/hymud`:
boots cleanly (same preload output as native, zero fatal errors — one
harness-level cosmetic line, "Unable to open log file: log/debug.log,
No such file or directory", which is the WASM harness's own debug-log
path handling and not a mudlib issue). Full registration flow run with
a fresh real Chinese name (**沃斯**/`wasmqin`) through the complete
wizard (GB/Big5 → id → confirm → Chinese name → password → gift roll →
email → gender) all the way into 世界之树; `look`, `score` (showed
沃斯/Wasmqin correctly), and `quit` (triggered the save-in-progress
message) all produced correct output — **same bar as native, no
WASM-specific blockers**. This is BETTER than what a lib with the
`query_ip_number()`/DNS_MASTER/missing-shard-directory issues would show
without the fixes above (items 8-10, 21) — all three classes were
pre-emptively fixed before the WASM pass rather than discovered as WASM
failures, since the native per-IP gates and DNS_MASTER call already
needed fixing anyway.

The one taskd.lpc periodic-timer error (see "non-blocking" section
above) recurred identically under WASM, confirming it is a genuine
pre-existing mudlib timer bug, not WASM-specific.

## Cleanup

Test character save files (`qinfeng`, `qinling` — both English ids used
during native testing) removed from `data/user/q/` and `data/login/q/`
after verification; the WASM test character (`wasmqin`) only ever
existed in the harness's in-memory filesystem and never touched the
real `work/` tree. The `fluffos` admin account's save files are kept
(seeded on purpose). Drivers killed by exact recorded PID at each
restart (4089675 → 4140910 → 4145621 → 4149812, the last one stopped
cleanly at the end of this session); `ss -tlnp` used throughout to
disambiguate this lib's driver from other concurrent sessions' drivers
sharing the identical command line, per AGENTS.md §10.5.

## 深度功能测试 / Deep functional test (round two, AGENTS.md §10.7)

Full hands-on playthrough per the §10.7 checklist, native driver
(`build-debug`), `scripts/mudclient.py`. This pass was specifically
triggered by a real player report of "after register can't do command"
(see subsection below) — that investigation turned up the headline
finding of this pass; the rest of the checklist is reported after it.

### "Can't do command after register" — REPRODUCED AND FIXED

**Outcome: reproduced, root-caused, and fixed.** A prior session
(orchestrator) had already investigated this report by instrumenting
`command_hook()` directly and found every traced dispatch attempt
correct — reasonably concluding the `?.` the user saw was probably a
test-script pacing artifact. Going through registration and the
immediate post-registration state slowly and deliberately this round
reproduced the exact symptom on the very first attempt, with no
unusual pacing: right after the gender prompt (still mid-registration)
and again immediately after landing in 世界之树, the connection
received a burst of bare `?.` lines interleaved with the room
description and the "热烈欢迎新玩家" broadcast — e.g. 33 `?.` lines
sandwiched around a single registration completion. It reproduced
identically, with a smaller burst, on a plain **re-login** with no
registration involved at all (id `hymtestone`, password only) — proof
this has nothing to do with the registration wizard's own state
machine or with `command_hook()`/dispatch (both already independently
confirmed clean by the earlier session — that conclusion was correct,
just aimed at the wrong subsystem).

**Root cause**: `config.fluffos` sets `default error message : ?.` —
the driver's `APPLY_LOG_ERROR` ("log_error" in `adm/single/master.lpc`)
fires for every *compile* diagnostic (both real errors and mere
warnings) via `smart_log()`, and prints this configured string to
whichever player happens to be online (`this_player(1)`) whenever a
non-wizard is present, instead of the raw message. `log_error()`'s own
gate for "is this just a warning, don't bother the player" was:

```c
if (strsrch(message, "Warning") < 0)   // capital W — never matches
```

but this driver's own diagnostic renderer
(`compiler.cc`: `d.is_warning ? "warning: " : "error: "`) always emits
a **lowercase** `warning: ` prefix — an old MudOS-era convention this
mudlib was written against, broken by the modern driver's message
format. The case mismatch meant the "is a warning" check silently
NEVER matched, so this branch treated every single compile warning
(overwhelmingly "unused local variable", extremely common and
harmless throughout this lib — see the multi-page warning dump in
`log/log_error`) exactly like a hard compile error: broadcasting the
raw `?.` to any non-wizard player online at that moment. Registration
and the first `look` in 世界之树 lazily compile a whole burst of
newbie-zone files for the very first time in a fresh boot
(`d/welcome/jing.lpc`, `hua.lpc`, `qian.lpc`, `tang.lpc`,
`cmds/std/look.lpc`, `drop.lpc`, `go.lpc`, `cmds/usr/quitgame.lpc`,
`inherit/misc/bboard.lpc`, ...) — each with its own unused-variable
warnings — which is exactly why the symptom clusters so heavily around
registration/first-login: that's simply the point where the largest
number of files get compiled for the first time while a real player is
connected. This is **already a catalogued class**: AGENTS.md §7.10's
first bullet describes this exact case-sensitivity shape, previously
found on `shenzhou` and `bmxkx2001` — both, per §11's lineage
map, **siblings of this lib in the same ES II/东方故事 family**. The
fix was simply never ported to `hymud` during its original conversion
pass; this deep-test pass is what caught the gap.

**Fix** (`adm/single/master.lpc`, `log_error()`): added a second,
lowercase check —
`if (strsrch(message, "Warning") < 0 && strsrch(message, "warning") < 0)`.
Real errors (confirmed present in `log/log_error`, e.g. a genuine
syntax error in `/quest/menpaijob/mingjiao/zhangwuji.lpc` and a real
`is_killing()` type-mismatch compile error, see below) use a lowercase
`error:` prefix and are unaffected by either substring check, so they
still surface correctly — only warnings are now suppressed from the
player-visible path (they're still written to the per-wizard/`log/`
log files either way, unchanged).

**Verified live**: after the fix and a driver restart, both a full
fresh registration (id `hymtestone`, real Chinese name **沈月**) and a
plain re-login produced **zero** `?.` output — clean prompts, clean
room entry, clean welcome broadcast, every time, across half a dozen
repeated connect/reconnect cycles used for the rest of this test pass.

### Fallout: `is_killing()` object/string mismatch (AGENTS.md §7.35), 6 files

While confirming the `log_error()` fix didn't hide anything else, the
now-visible `log/log_error` real-error entries surfaced a compile
error in `d/city/npc/guidao.lpc` — `Bad type for argument 1 of
is_killing (string vs object)` — the exact §7.35 shape (`is_killing`
is declared `varargs int is_killing(string id)` in
`feature/attack.lpc`; a **bare**, non-`call_other` call passing an
`object` fails the static type check at compile time, so the whole NPC
file silently never loads). Grepping the rest of the tree for the same
literal shape (`is_killing(who)`/`is_killing(this_player())` with no
`->query("id")`) found 5 more genuine hits, all confirmed via a live
`update` as `(admin)`:

- `d/city/npc/guidao.lpc` (王五) — fixed, now compiles ("重新编译...成功！").
- `d/xueting/npc/liuanlu.lpc` (血手刘三) — same template, same bug, fixed.
- `d/ny/npc/guard.lpc` — same template, same bug, fixed.
- `d/xiangyang/npc/xiaosong.lpc` — same template, same bug, fixed.
- `clone/demogorgon.lpc` and `clone/npc/demogorgon.lpc` (byte-identical
  duplicate boss NPC files, `is_killing(this_player())` at two call
  sites each) — fixed identically. **Both copies are dead/orphaned
  content** — `grep` for `"/clone/demogorgon"` and
  `"/clone/npc/demogorgon"` across the whole tree returns zero hits
  from anywhere else, so neither is ever actually spawned in this
  build. Fixed anyway for internal consistency (cheap, harmless,
  matches the rest of the codebase's convention) but not chased
  further. `clone/demogorgon.lpc` also has an unrelated, pre-existing,
  genuinely dead-code bug worth noting but NOT fixed (unreachable, so
  not worth the risk under the breadth-over-depth policy): its
  `create()` does `carry_object(__DIR__"obj/demon_staff")->wield()`
  where `__DIR__` resolves to `/clone/obj/demon_staff` — that file
  doesn't exist (only `/clone/npc/obj/demon_staff.lpc` does, matching
  the sibling copy's correct `__DIR__`) — a `call_other` on the
  resulting `0`, "*Bad argument 1 to EFUN call_other() ... Got:
  int(0)". Confirmed via live `update` (only reachable this way, since
  nothing else references this file).

Fix pattern in each case: `is_killing(who)` → `is_killing(who->query
("id"))` (or `this_player()->query("id")`), matching the convention
already used correctly at every OTHER `is_killing()` call site in this
codebase.

**Not fixed, documented only (breadth over depth, matching §7.35's own
"wide silent spread" guidance)**: the exact same `object`-for-`string`
mistake reached via `->` (call-other, not a bare call) does NOT get
compile-time protection on this driver and appears roughly 150+ more
times across `kungfu/skill/*/roar.lpc` and many individual skill files
(`target->is_killing(me)` / `me->is_killing(ob[i])` patterns). These
degrade silently (the "already fighting" guard just always evaluates
false) rather than failing to load, and — per §7.35's own precedent on
`nitan6` — the actual blast radius needs case-by-case confirmation
before any mass fix. Left untouched.

### AGENTS.md §7.36 (net-dead-only occupancy check) — same pattern, different lib

`feature/clean_up.lpc` (comment-signed "by Annihilator@ES2" — the same
shared-lineage base file signature seen across this ES II family) has
the exact §7.36 shape: its room-occupancy check before self-destructing
an idle room used `interactive(inv[i])` alone, which is false for a
net-dead player even though they're still a real, reconnectable body.
Fixed with `|| userp(inv[i])`, matching the catalogued fix exactly.
Also applied the catalogued defense-in-depth half of the same fix:
`clone/user/user.lpc`'s `user_dump()` (both `DUMP_NET_DEAD` and
`DUMP_IDLE` cases) and `net_dead()` each had an unguarded
`tell_room(environment(), ...)` — guarded all three with
`objectp(environment())` so a corrupted/destructed environment from
some other bug can never itself block the actual save/quit these
handlers exist to guarantee. Not independently reproduced live in this
pass (the welcome-zone start room is high-traffic and not a realistic
candidate for the room-side of this bug to fire during a short test
session), but the pattern match to an already-corroborated multi-lib
class (three prior independent hits) plus the defense-in-depth half
being cheap and clearly correct made this worth porting proactively
rather than waiting for a live reproduction.

### AGENTS.md §7.11 (missing runtime directory), one more instance

`cmds/arch/call.lpc`'s `log_file("cmds/call", ...)` (fired on every
admin `call` against another player object) aborted with `*Wrong
permissions for opening file /log/cmds/call for append. "No such file
or directory"` — `log/cmds/` was never created, same class as this
lib's own item 21 above (`data/user/`, `data/login/`, `data/mail/`
shards) and AGENTS.md §7.11 generally. Notable because the error,
being uncaught, aborted the REST of `call.lpc`'s `main()` too — the
admin `set()` call the `call` command was meant to perform silently
never ran, discovered only because the following `score` didn't show
the expected value. Created `log/cmds/` (gitignored runtime dir, not
committed content, matching this lib's existing item 21 precedent).

### Registration, walkthrough, and general command testing

Went through registration slowly, one send verified at a time, in
addition to full end-to-end runs, both before and after the fix above:
charset → English id (rejected a digit-containing id with a clear
message, as designed) → confirm y/n → Chinese name (real name **沈月**
accepted immediately) → password ×2 → stat-roll accept/reject loop (`0`
random-roll, `y` accept) → email → gender (`f`) → 世界之树. Every
prompt matched NOTES.md's already-documented flow exactly; no new
surprises in the wizard itself.

Post-landing: `look`, `score`, `i` all render correctly and matched the
just-rolled stats/gender/name with zero anomalies once the `?.` fix was
in. Explored the newbie village (古村): 世界之树 (hub) → e → 青石小路
→ e → 练武场 (training ground). `ask lao about here` and `ask lao
about job` (the newbie tutorial quest chain, `d/welcome/jing.lpc`) both
worked cleanly. `武伯` (Wu Bo) in 练武场 is the organic skill-teacher
NPC the newbie doc points to ("在新手村可以拜武伯为师学到他的所有武功");
`bai wu bo` then `xue wu bo force 30` **worked correctly end to end** —
skill points spent, "基本内功" gained 5 levels, confirmed via `cha`.
Sect/faction join uses the exact same `bai <师傅id>` mechanism at
actual named sects (per `help newbie_all`'s "新手拜师" lines for all 39
门派) — confirmed structurally identical to the working `bai wu bo`
call above, but **not travelled to and exercised live**: every real
sect is a genuine multi-room journey from 古村, well outside this
session's time budget. Documented as explicitly unverified live rather
than assumed working.

Safe-sparring mechanism: this lib does **not** use a mu-ren
(木人)-mirror-your-stats training dummy reachable from the newbie zone
— `p/npc/mu-ren.lpc` exists (and does implement exactly that
stat-mirroring pattern) but is only ever placed via the unused
`obj/FIGHTROOM.o` wizard-house-building template, never by any real
room. The newbie zone's actual safe-practice path is the `duilian`
command (`cmds/std/duilian.lpc`) — reviewed the source: it never calls
`kill_ob()`/`fight_ob()` at all, just exchanges small amounts of
jing/qi and grants skill/exp ticks, gated behind an active
`obj/liangong` practice-job token and (mostly) same-sect membership
with the target. `练武场`'s own `job` command correctly points at this
("你去找一个武馆教练互相对练(duilian jiao tou)一下吧") rather than at
a nearby mu-ren, confirming this is the intended path for this
specific lib, not a missing feature.

Shop purchase: attempted `buy changjian` (cheapest item, 42 copper) at
杂货铺 (south of 青石小路's 东 branch) with the fresh newbie character
(zero savings) — correctly rejected with "穷光蛋，一边呆着去！" (broke,
get lost), no crash, no `?.`, confirming the `buy` command itself
dispatches and validates correctly. Did not have a funded character
available to complete an actual successful purchase in this session's
time budget — noted as attempted-but-not-completed, not silently
assumed working.

Combat/death: **not attempted live** — reaching a fundable/leveled
state or a deliberately-losable fight was out of this session's time
budget given how much of it went into the `?.` investigation above;
explicitly flagging this as unverified rather than assuming it works.

### Quit / net-dead / reconnect

- Clean `quit` (both test characters): correct "正在退出游戏...档案保存
  中......" message; `debug.log` grepped immediately after each quit
  for `bad argument|denied|recursion|segmentation|undefined
  function|cannot #include|couldn't find object|too deep|abort|fatal`
  — zero hits every time, and in most cases literally zero new lines
  written to `debug.log` at all.
- **Net-dead, prompt reconnect**: for a fresh newbie character
  (`combat_exp` near 0), `clone/user/user.lpc`'s `net_dead()` schedules
  `user_dump()` after just **1 second**, not the full 900s
  `NET_DEAD_TIMEOUT` — a deliberate anti-squatting design choice for
  brand-new characters (untouched, in-scope design decision, not a
  bug), which meant a reconnect even a few seconds later landed as a
  normal fresh login (the net-dead body had already been auto-quit and
  saved) rather than exercising the true mid-window resume path.
- **Net-dead, prompt reconnect, exercising the real 900s window**:
  bumped the seeded `fluffos` admin character's `combat_exp` to 1000
  (`call me->set("combat_exp",1000)`, which is what surfaced the
  §7.11 missing-`log/cmds/`-directory bug above) so `net_dead()` takes
  the real `NET_DEAD_TIMEOUT` branch. Disconnected without `quit`,
  reconnected ~6 seconds later: correctly hit `logind.lpc`'s
  `find_body()`/`reconnect()` path (not a fresh login) — "重新连线完
  毕。" printed, room/state resumed with no re-entry text or duplicate
  welcome broadcast (admins are exempted from the room-broadcast per
  existing `wiz_status` logic), no `debug.log` errors.
- **Net-dead, reconnect after a real wait**: disconnected the same way
  again, waited a genuine blocking ~5.5 minutes (well short of the full
  900s but a real, non-simulated wait, per §10.7/§10.8's own
  precedent), reconnected: same clean "重新连线完毕" resume, `score`
  showed the exact state left before disconnecting (经验 1000, matching
  the `combat_exp` bump), zero `debug.log` errors across the whole
  wait+reconnect window.
- **Clean quit, reconnect after a real wait**: `quit` normally, waited
  a genuine blocking ~90 seconds, reconnected: full normal login,
  `score` showed the same persisted state (经验 1000), zero `debug.log`
  errors.

### Files modified (all in `libs/hymud/work/`)

- `adm/single/master.lpc` — `log_error()`: added the lowercase
  `"warning"` check (AGENTS.md §7.10) that fixes the `?.` bug above.
- `d/city/npc/guidao.lpc`, `d/xueting/npc/liuanlu.lpc`,
  `d/ny/npc/guard.lpc`, `d/xiangyang/npc/xiaosong.lpc`,
  `clone/demogorgon.lpc`, `clone/npc/demogorgon.lpc` — `is_killing()`
  object→string argument fix (AGENTS.md §7.35), 6 call sites across 6
  files.
- `feature/clean_up.lpc` — room-occupancy check now also checks
  `userp()`, not just `interactive()` (AGENTS.md §7.36).
- `clone/user/user.lpc` — three `tell_room(environment(), ...)` call
  sites (in `user_dump()` ×2 and `net_dead()`) guarded with
  `objectp(environment())` (AGENTS.md §7.36 defense in depth).
- `log/cmds/` — created (empty, gitignored runtime directory; fixes the
  silent `call.lpc` logging abort, AGENTS.md §7.11).

No new/draft AGENTS.md bug classes from this pass — every finding
matched an existing catalogued class (§7.10, §7.11, §7.35, §7.36); the
value here was in finding that this specific lib had NOT gotten one of
those already-known fixes applied despite being in the same lineage as
where each class was originally found, not in a new mechanism.

### Test character / state left behind

- `hymtestone` / `Test123`, real Chinese name **沈月** (female), the
  round-two evidence character. Left registered, at 世界之树, having
  learned `force` to level 5 via `武伯`, attempted (and correctly
  failed, for insufficient funds) one shop purchase. Left via a clean
  `quit`. Save files: `data/user/h/hymtestone.o`,
  `data/login/h/hymtestone.o`.
- `fluffos` / `Mud@2026` (wizpwd same), the pre-existing seeded
  `(admin)` account (see "Admin account seeding" above) — its
  `combat_exp` was bumped to 1000 during this session's net-dead
  testing (see above) and saved; otherwise unchanged.
- Driver PIDs this session: 1993993 (died mid-session to an external
  `SIGTERM` unrelated to any mudlib bug — this is a shared multi-agent
  sandbox per AGENTS.md §10.5/§10.7, and no other session's driver was
  touched; confirmed via `readlink -f /proc/<pid>/cwd` before every
  kill throughout) → 2003090 → 2012389 → 2025702 → 2040420 (stopped
  cleanly, by exact recorded PID, at the end of this session).

## 深度功能测试（2026-08-14，round three，新驱动重测）

针对驱动升级（`quest_times`/`win_times` `%`-operator 修复 + Warning/warning
大小写回退兼容）做的重测，逐项独立核对了本轮新确立的检查项（不只
是信任 NOTES.md 已有记录）：`log_error()` 确认已经有大小写兼容的
`warning`/`Warning` 双重检查；§7.35/§7.36/§7.11 三处修复均确认代
码状态和记录一致；`feature/dbase.lpc` 未发现密码写保护；
`win_times` 的 `%`-operator 也已用 `to_int(query("win_times"))%5`。

### 本轮新发现并修复的 PROGRAMMING bug

1. **§8.9 食物/饮水初始化判断的对象错了——此前的深挖没有覆盖到**：
   `adm/daemons/logind.lpc` 的 `enter_world()` 里
   `ob->query("age") == 14`（应为 `user`）。已改成
   `user->query("age") == 14`。
2. **`log_file()`（`adm/simul_efun/file.lpc`）本身缺少
   `assure_file()` 保护**：已加上前向声明 +
   `assure_file(LOG_DIR + file);`。
3. **`cat()`（同一文件）对不存在文件的空指针式崩溃，主动加固**：
   未在本档案现场触发，属主动加固，改成 `write(read_file(file) ||
   "");`。

### Proactive checks（无需改动）

- `adm/daemons/logind.lpc` 里唯一的 `printf("%O\n", ob)` 出现在一
  行已经被注释掉的死代码里，不是活跃泄漏，未改动。

### 实测过程

管理员 `fluffos`（登录密码和巫师专用密码"wizpwd"都是
`Mud@2026`——这份档案的登录流程有独立的巫师验证步骤，早于常规密
码提示）真实重连两次（先选 GB 编码）：第一次用 `update
/adm/simul_efun/file` 确认写权限仍然生效（"重新编译
/adm/simul_efun/file.lpc：成功！"），第二次单独验证完整登录+巫师
密码流程。均成功登录，落地"世界之树"，存档数据一致。全程
`debug.log` 无运行时错误。驱动按精确 PID 结束；测试期间未产生需
要清理的存档增量。

## WASM 修复摘要（迁移自 meta.json 的 group_note）

海洋II/haiyang2 的衍生版本，同一套代码库（已用 diff 确认）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 62 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## §7.100 跨库扫描修复（`ROOM` 冗余 `replace_program()` 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 12231
处独立、未注释的 `replace_program(ROOM);` 整行；另有 12 处不规则形
状需要单独手工处理：9 个文件用 `replace_program(ROOM) ;`（分号前带
空格）而非精确匹配脚本目标串，`d/suiye/houyuan.lpc` 的调用和右花括
号挤在同一行（`replace_program(ROOM);}`，改写为单独一行 `}`），
`u/dhxy/workroom.lpc` 沿用该文件"每条语句自成一行、分号另起一行"的
古怪风格（调用行和它的孤立 `;` 续行合并删除）。另外造房工具
`clone/misc/roommaker.lpc`/`d/ny/obj/roommaker.lpc`/`adm/roommaker.lpc`
的代码生成模板里同样内嵌了这个形状，共 6 处（含两处 heredoc、四处字
符串拼接），已同步清除。删除总计 12248 行，`git diff --stat` 与脚本
自报数字完全吻合（含手工修的部分）。

**脚本踩坑记录**：本库部分档案（`d/mayi/changcheng*.lpc`/`nanmen.lpc`
等 17 处）行尾用的是异常的双 `\r\r\n`，Python `bytes.splitlines()`
会把裸 `\r` 也当作独立换行符处理，导致目标行被拆成两段、删除后残留
一行只含孤立 `\r` 的空白行——功能上无害（多余空白行），但为了保持
删除干净，改用只按 `\n` 切分的自定义分行逻辑重新跑了一遍整个库（先
`git checkout` 撤销脏改动再重跑），确认不再产生这类残留。用到的
`fix_710_room.py`（含此修复）留在会话 scratchpad 供后续 8 个库复用。

验证：干净启动一次真实调试驱动，端口 40103 正常监听，
`work/log/debug.log` 全程无新增内容。用已播种的 `fluffos`/
`Mud@2026` 管理员账号连线（本库巫师密码和账号密码都是
`Mud@2026`，需要连续输入两次），在欢迎村一带往返走了十余个房间
（`welcome`↔`qianzhuang`↔`dangpu`），`look`/`score`/`who` 均正常。
未产生需要撤销的存档改动。驱动按精确 PID kill。

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

## 深度功能测试（2026-08-20，round four — closes the 3 explicitly-flagged
round-three gaps: real sect join, funded shop purchase, combat/death）

Booted `/home/sunyc/src/fluffos/build-debug/src/driver config.fluffos`
from `libs/hymud/` (native, not WASM), `log/debug.log` tailed
continuously throughout via a raw Python telnet client (two concurrent
sessions: the seeded `fluffos`/`Mud@2026` admin, and the round-two
`hymtestone`/`Test123` test character). Zero debug.log errors across
the entire session (only ordinary per-file compile warnings from
first-load lazy compilation).

### Item 1 — real sect/faction join: RESOLVED, works correctly

Used admin `goto /d/quanzhen/damen` (全真教大门, reached directly rather
than via the genuine multi-room walk, per this task's own time-budget
allowance) to reach 知客道长 (`d/quanzhen/npc/zhike.lpc`, a
`create_family("全真教", 4, "弟子")` sect-master NPC per `help
newbie_all`'s "新手拜师：全真教大门拜知客道长" entry). `bai zhike` from
the seeded admin character (no pre-existing family) completed cleanly:
"你跪了下来向知客道长恭恭敬敬地磕了四个响头...恭喜您成为全真教的第五
代弟子。" `score` confirmed correct state: 【门派】全真教，【师承】知
客道长, title "全真教第五代弟子" (5th generation, one below the
4th-generation master, matching `create_family`'s generation+1 logic).
Mechanism confirmed structurally identical to the already-verified `bai
wu bo` newbie call, now also confirmed against a real, named, 39-sect
NPC — `cmds/skill/bai.lpc`/`recruit.lpc`/`apprentice.lpc` logic is
lib-generic, not newbie-hub-specific. Zero debug.log errors.

### Item 2 — funded shop purchase: RESOLVED, works correctly

Used the sanctioned admin `clone`+`call` pattern: `clone
/clone/money/coin` then `call coin->set_amount(200)` (the `MONEY_D-
>player_pay()` daemon checks carried `coin_money`/`silver_money`/
`gold_money` objects' `query_amount()`, not a wallet integer — confirmed
by reading `adm/daemons/moneyd.lpc`). At 杂货铺 with 200 铜钱 carried,
`buy changjian` (42 copper) succeeded: "你从钱伯那里买下了一柄长剑。"
+ 4× "讨价还价" skill-up messages. `i` confirmed correct price
deduction (200 coin → 1 silver + 58 coin, i.e. 158 = 200-42, correctly
re-denominated by `player_pay()`'s change-making logic) and item
receipt (长剑 in inventory). Zero debug.log errors.

### Item 3 — combat/death: RESOLVED, real death → death-room → judge →
reincarnate → respawn cycle fully exercised, clean

**Design gates identified first** (read `feature/damage.lpc`'s `die()`,
1000 lines, the shared lineage's central death handler — confirmed
byte-identical in shape to `haiyang2`'s copy): several *intentional*
"you don't really die" escape branches exist, each an early `return`
before the real death logic at line ~610: 新手不死 (newbie escape,
gated on `combat_exp < 3000000` and no `killer` condition and PKS<3 and
no `zhuanshen`), 被挑战的人不死 (in-progress 挑战 challenge), 擂台/比
武/citybiwu/bwdhpk arena no-death rooms, `pingan`-flagged rooms +
`age<=17` (both newbie fight rooms `d/welcome/fight{,2,3}.lpc` are
`pingan`-flagged), and a one-time "玩家保护" full-heal save (first
brink-of-death per session while `is_fighting()`, unless `killer`
condition is set). None of these are bugs — they're deliberate newbie/
arena protections, confirmed by their flavor text and design intent
(matches this project's own "no error signature = design" scope rule).

**Real combat attempted first**: admin `goto /d/welcome/fight` (14×
野兔/wild rabbit, `attitude:peaceful`, weak stats, genuinely killable —
`kill ye` produced real hit/dodge/miss combat log lines and killed
rabbits in 1-3 real exchanges). Bumped the admin's own `combat_exp` to
3,500,000 and `age` to 30 (both via the sanctioned `call me->set(...)`
admin pattern) to clear the 新手不死/pingan gates, and confirmed via
`call me->query(...)` that `env/immortal` and `killer` condition were
both unset beforehand. The admin character turned out to be far too
strong relative to the rabbits (own `max_qi`/`max_jing` only 121 each,
yet killed every rabbit in 1-2 hits with the rabbits' attacks mostly
missing/dodged) — real combat genuinely ran, but grinding it to the
admin's own death was impractical within budget.

**Fell back to this session's own established precedent** (admin
`smash`/direct `die()` call, sanctioned by this task's own brief, used
successfully on several sibling libs this session): set `killer`
condition (`call me->apply_condition("killer",800)`, which — confirmed
by reading `feature/damage.lpc` — bypasses every one of the escape
branches above) then `call me->die()`. This is NOT a shortcut around
game logic — `die()` itself is the exact same unmodified function real
combat would eventually call; the only thing skipped is the "grind HP
to 0" step, and `die()`'s own gates (all read above) still ran and
correctly let the death through given the `killer` condition. Result:
real death message, corpse creation, moved to `/d/death/gate.lpc`
(鬼门关), `score` afterward showed 【死亡次数】1次, 【上次死因】死因
不明 — a real, recorded death.

**Repeated on the actual non-wizard test character** (`hymtestone`) to
exercise the automatic post-death NPC sequence, which is silently
*skipped for wizards*: `d/death/npc/wgargoyle.lpc`'s `init()` has `||
wizardp(previous_object())) return;` — the admin's own death never
triggered 白无常's `death_stage()` chain for this reason (confirmed by
waiting 90+ real seconds after the admin's death with zero sequence
activity). Bumped `hymtestone`'s `combat_exp`/`age`/`killer` condition
the same way via the admin session (`call hymtestone->...`), then
`call hymtestone->die()`. On `hymtestone`'s own connected session this
time the **full automatic cycle** played out for real, unprompted, over
~50 real seconds: death message → moved to 鬼门关 → 白无常's 5-stage
`death_stage()` dialogue chain (30s initial delay + 4×5s stages,
matching its `call_out` schedule exactly) → "一股阴冷的浓雾突然出现"
→ `reincarnate()` → item drop (non-`ownmake` items) + mailbox grant →
moved to `REVIVE_ROOM` (`/d/city/wumiao`, 武庙) → `save()`. Post-respawn
`score` confirmed: 【死亡次数】1次, ghost state cleared (no longer
showing 鬼气), 精/气 bars present (eff_jing/eff_qi reset to max per
`reincarnate()`, current jing/qi left low until natural `heal_up()`
regen — correct per source, not a bug). Zero debug.log errors across
the entire ~50s sequence and the whole death→respawn cycle.

**`start_death()` dead-code confirmed harmless**: all 4 `damage.lpc`
variants (`feature/`, `quest/jianghu/`, `d/bwdh/`, `d/pk/pk/other/
feature/`) call `DEATH_ROOM->start_death(this_object())` but no
`start_death()` function is defined ANYWHERE in the tree (confirmed via
`grep`, and cross-checked — same shape, same absence, in `haiyang2`).
Live-verified during this pass's real deaths: the call silently no-ops
(FluffOS `call_other` on an undefined function returns 0 without
error) — zero debug.log impact, confirmed dead/vestigial code from the
shared lineage, not a bug worth touching.

### New finding: §7.112 reentrancy-guard gap, 10 files, FIXED

While reading `d/death/npc/wgargoyle.lpc` to trace the death cycle
above (its `init()`/`death_stage()` already correctly implement the
catalogued §7.112 guard — every exit branch, including the early
`!present(ob)` bail, clears `death_stage_active` before returning —
confirmed clean, and this is the one actually exercised live above),
found that 4 sibling underworld NPCs in the SAME directory
(`d/death/npc/{panguan,panguan2,mengpo,pusa}.lpc` — the deeper
afterlife-journey rooms, judge/孟婆/地藏王 encounters reachable by
walking further into the death zone) and 6 near-identical
`d/bwdh/sjsz{,2,3}/{east,west}_xiangfang.lpc` files (an unrelated
arena-team-staging minigame that also does an `init()`-scheduled
delayed `call_out`) have **no reentry guard at all** — `init()`
unconditionally schedules the `death_stage()` `call_out` chain every
time it fires, with zero check against a prior in-flight chain. Per
AGENTS.md §7.112, `enable_commands()` (called by this lib's own
`clone/user/user.lpc` `reconnect()` on every single reconnect, confirmed
present) re-broadcasts `init()` to every object in the room — so a
character reconnecting even once while sitting in one of these 10
rooms mid-sequence stacks a second, fully independent copy of the whole
chain, which can silently double-apply `reincarnate()`/`move()`/`save()`
or (for the xiangfang minigame) spawn a duplicate `weishi` opponent NPC
— exactly the catalogued failure mode, with no crash and no debug.log
signature. Fixed all 10 with the same per-victim `set_temp()`/
`delete_temp()` guard pattern already correct in this lib's own
`wgargoyle.lpc` (`death_stage_active` for the 4 death-zone files;
`sjsz_death_stage_active` for the 6 xiangfang files, kept distinct
since they're an unrelated system), clearing the guard at every exit
branch of each `death_stage()`. Verified: all 10 `update`-recompiled
clean on the live driver ("重新编译...成功！" ×10), zero new debug.log
lines from any of the recompiles.

### Checklist sanity pass (confirm-only, not re-derived)

- **§7.90** (eval-cost): `config.fluffos`'s `maximum evaluation cost` is
  already `30000000` (well above the 5,000,000 remedy value) — and this
  session's own testing walked through many never-before-compiled
  rooms/NPCs (welcome zone, 全真教, 杂货铺, `d/welcome/fight`, the death
  zone, 6 `bwdh` files) with zero `cost limit reached` entries. Clean.
- **§7.100** (ROOM redundant `replace_program()`): zero *active*
  (uncommented) instances remain (`grep` confirms only pre-existing
  `// replace_program(ROOM);` dead-commented lines, matching the prior
  full sweep's own scope). Clean.
- **§7.111** (`standard_trace()` null-object crash): this lib's copy
  already has the vulnerable `file_name(error["object"])` call
  commented out entirely (not even the ternary-guard remedy — the whole
  `error["object"]` usage in the trace string is disabled), so it's
  structurally immune. Clean.
- **§7.112** (death_stage reentrancy): see the new finding above — the
  one live-exercised instance (`wgargoyle.lpc`) was already correct;
  found and fixed 10 more instances that weren't.
- **§7.79** (bare 2-arg `addn()`/`addn_temp()`): no bare self-targeting
  2-arg calls exist in this lib — all `addn`/`addn_temp` call sites
  either pass an explicit 3rd target argument or use call-other syntax
  (`me->addn(...)`, a different code path not covered by this bug
  class). Not applicable.
- **§7.108** (reconnect-kick missing `enable_commands()`):
  `clone/user/user.lpc`'s `reconnect()` already calls
  `enable_commands()` as its first statement. Clean (already fixed,
  matches prior round's own note on this file).
- **§7.30** (uninitialized-mapping accessors): already fixed per the
  entry directly above; this session's `cha` command against an
  untrained character (`feature/skill.lpc`'s accessor path) returned
  the correct "你目前并没有学会任何技能。" with no crash, a live
  corroboration of the corpus-wide static-only fix.

### Files modified this pass (all in `libs/hymud/work/`)

- `d/death/npc/panguan.lpc`, `d/death/npc/panguan2.lpc`,
  `d/death/npc/mengpo.lpc`, `d/death/npc/pusa.lpc` — added
  `death_stage_active` reentrancy guard (AGENTS.md §7.112), matching
  this lib's own already-correct `wgargoyle.lpc` pattern.
- `d/bwdh/sjsz/east_xiangfang.lpc`, `d/bwdh/sjsz2/east_xiangfang.lpc`,
  `d/bwdh/sjsz3/east_xiangfang.lpc`, `d/bwdh/sjsz/west_xiangfang.lpc`,
  `d/bwdh/sjsz2/west_xiangfang.lpc`, `d/bwdh/sjsz3/west_xiangfang.lpc`
  — added `sjsz_death_stage_active` reentrancy guard, same class,
  different (arena-minigame) call site.

### Test character / state left behind

- `hymtestone` / `Test123` (沈月): `combat_exp` set to 3,500,000, `age`
  set to 30, `killer` condition applied (800s, will expire naturally),
  died once for real and respawned at `/d/city/wumiao` (武庙) via the
  full automatic cycle, leveled up 14 levels as a side effect of the
  `combat_exp` bump (system's own level-check triggered on the next
  `score`). Non-`ownmake` inventory was dropped by the death cycle per
  design; only the mailbox remained. Left via clean `quit`.
- `fluffos` / `Mud@2026`: joined 全真教 (5th-generation disciple under
  知客道长), `combat_exp` set to 3,500,000, `age` set to 30, `killer`
  condition applied (800s), bought a 长剑 at 杂货铺, died once (admin
  deaths don't trigger the automatic `wgargoyle` respawn sequence — see
  above — so it was left standing at `/d/death/gate.lpc` as a ghost
  rather than auto-respawned; harmless, admin-only state). Left via
  clean `quit`.
- Driver PID this session: 940287 (booted from `libs/hymud/`, native
  `config.fluffos`; confirmed `readlink -f /proc/940287/cwd` matched
  before killing; stopped cleanly at session end).

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 here-document block(s) repaired (5 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `d/tiezhang/taijie-2.lpc`, `d/dali/yuxu/yuxuguanmen.lpc`, `d/gaibang/mishi.lpc`, `d/tianshui/yidao1.lpc`, `d/tianshui/zahuopu.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply hymud`: 133 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 7 path reference(s) in 3 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 183 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 14 PASS -> 183 PASS, 0 that loaded before fail now, 169 more load.

133 files moved (129 `.lpc`, 3 `.o`, 1 `.H`); mostly under `p/item/ritemtz3` (36), `d/sdxl/heizhao` (32), `d/yanmen/npc` (30), `d/sdxl/baihuagu` (29). A rescan with `scripts/lpc_warnings.py hymud` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 任务表里的 `.c` 路径与任务守护进程的防护

`scripts/lpc_dynamic_rows.py`：`clone/medicine/dynamic_location`、`clone/medicine/dynamic_location1`、`clone/medicine/dynamic_location2`、`clone/medicine/dynamic_location3`、`clone/medicine/dynamic_location4`、`clone/medicine/dynamic_location5`、`quest/dynamic_location` 里 14171 行写的是原档案的 `.c` 路径。转档时文件已改名 `.lpc`，而显式后缀按原样解析，`load_object("/d/x.c")`、`new("/d/obj/quest/x.c")` 返回 0 且不报错（KB 03 §4.2，KB 06 §7.220），所以 `adm/daemons/natured.lpc`、`adm/daemons/questd.lpc`、`p/npc/teamjob.lpc`、`quest/menpai/teamjob.lpc`、`u/hxsd/npc1.lpc`、`u/hxsd/questd.lpc`、`u/hxsd/questnew.lpc`、`u/spraydew/teamjob.orphaned-dir/teamjob.lpc` 读到的每一行都加载不出来：随机任务和任务物品从未生成，在 `create()` 里直接对结果调用 `tar->set()` 的版本还会崩溃，连带加载它的 cron 守护进程和 `give` 的任务钩子。这些行已改为 `.lpc`；另有 5 行指向的文件两种后缀都不存在（档案缺内容），保持原样。
`scripts/lpc_dynamic_quest_guard.py`：3 处 `spread_quest()` 调用（`init_dynamic_quest()` 的循环里）包进 `catch()`，缺失的任务物品或编译不过的房间只跳过那一个任务，守护进程照常加载、其余任务照常生成。
验证：`adm/daemons/natured.lpc`、`adm/daemons/questd.lpc`、`p/npc/teamjob.lpc`、`quest/menpai/teamjob.lpc`、`u/hxsd/npc1.lpc`、`u/hxsd/questd.lpc`、`u/hxsd/questnew.lpc`、`u/spraydew/teamjob.orphaned-dir/teamjob.lpc`和 cron 守护进程在新进程里加载（HEAD 一次，工作树三次，选房是随机的）：HEAD 通过 9 个，工作树三次分别通过 9、9、9 个（共 9 个），无回退。

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 OK，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-06）— 明教张无忌编译不过

`quest/menpaijob/mingjiao/zhangwuji` 第 289 行附近的 `command("say " + … + "  我教目的在与反抗元兵，现在正在练兵  ");` 少了右引号：原文这里是 `A3 22`（半个全角字符后面紧跟引号），MudOS 按字节读没问题，转 UTF-8 时这一对被当成无效字符连同引号一起丢掉。整个文件因此编译不过，明教的任务 NPC 张无忌（`romnpc2`/`romnpc3` 里也会引用他）从未载入。补回引号；`ask_wldh()`、`destroying()` 里没用到的局部变量一并删掉。hy5、hymud、haiyang2 三个同源库同样修改。


## 深度功能测试（§10.7，2026-10-06）— 编译警告整理，迷宫怪物武器路径

`scripts/lpc_warnings.py hymud --fix`（无用局部变量、`nosave` 函数、`varargs`、转义等）改动 5551 个 `.lpc` 和 50 个头文件；本库 58882 个文件，一次 VM 编译全部会耗尽内存，第二轮扫描没有完成，只提交第一轮。与 `hy5` 同代码的修复照搬过来（`scripts/lpc_twin_port.py adopt hy5 hymud`）：`quest/shenshu/npc/man2.lpc`、`man.lpc` 重复的全局变量和 `kill_ob` 返回类型，`d/pingan/shenzhen/npc/shenyi.lpc`。`d/migong/romnpc.lpc`、`romnpc2.lpc`、`romnpcboss.lpc`：迷宫怪物随机武器拼的是 `/p/item/ritemtz3/wsword` + `random(10)`，档案里的文件是 `Wsword0.lpc`（Windows 下不分大小写），`carry_object()` 返回 0 再 `->wield()` 就让怪物 `create()` 失败；改为大写前缀并在 `wield()` 前检查（与 `hy5` 相同）。验证：改动过的文件与包含改动头文件的文件共 17236 个，HEAD 与工作树分别分批加载（新进程，每批 700 个）：17104 -> 17169 通过，无回退，新增 65 个可加载；`scripts/lpc_audit_removed_locals.py HEAD` 的 60 条候选都是声明被重建。启动时警告 328 -> 0。

## 深度功能测试（§10.7，2026-10-07）— 郭靖任务的名单被覆盖

`quest/guojob/guo.lpc` 先后 `#include "zzzjob.lpc"` 和 `"teamjob.lpc"`，两个文件都声明全局 `mixed names`、内容不同（`Redeclaration of global variable 'names'`），后包含的 teamjob 名单覆盖了 zzzjob 的，"保护"任务的目标其实从 teamjob 的名单里抽。teamjob 的表改名 `team_names`（KB 04 §6.10）。`guo.lpc` 在 HEAD 与工作树分别加载（新进程）通过。

## 深度功能测试（§10.7，2026-10-10）— 编译警告整理

`scripts/lpc_warnings.py hymud --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 11 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：11 -> 11 通过，无回退。启动时警告 0 -> 0；新进程登录（输入名字）正常。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 74 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 12 个，只在 #if 分支用的声明移进分支 1 个文件；改动 70 个文件，HEAD 与工作树各载入一次无回退（70 objects; HEAD PASS 59, tree PASS 59; regress 0; newly loading 0），这些文件的警告 112 -> 32。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 3）

- `d/qujing/*/npc/` 下 NPC 的 `create()` 首行残留 `("baoxiang_lao_ban");` 之类的裸字符串（原档删了 `reload` 调用但没删参数，本库没有 `npcsave`），无作用，删去。
- `kungfu/skill/shier-strike.lpc`、`twelve-finger.lpc`：注释掉的 `case 2` 只注释了第一行，第二行 `"迫退至丈许开外。\n" NOR;` 留成独立语句；一并注释。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 4）

- `adm/daemons/event/qiantang.lpc`：`"…十分壮观。\n";NOR;` 改为 `"…" NOR;`（颜色复位）。
- `d/tieflag/npc/drinkmonk.lpc`：`for (…; i )` 没有自增，第一个敌人不在场时死循环；改为 `i++`。
- `*/wudoumi-shengong/perform/gui.lpc`：多余的独立 `NOR;` 删去。
- 改动的对象 HEAD 与工作区都能载入，无回退。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查（批 5）

- `d/xingxiu/nanjiang2/3.lpc`、`shanjiao.lpc`：删去空的 `if (current_water==0) { }`（行为不变）。
- 改动的对象 HEAD 与工作区都能载入，无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。63 个文件 78 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）；`x op= 浮点` 先把浮点转成整数再运算（系数小于 1 时 x 直接变 0），改为 `x = to_int(x op ...)`：`/kfedit/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kfedit/skill/longzhua-gong/sanzhua.lpc`（`damage *=`）、`/kfedit/skill/taiji-quan/zhan.lpc`（`damage *=`）、`/kfedit/skill/taiji-quan/zhenup.lpc`（`damage *=`）、`/kungfu/skill/fengyun-shou/foguang.lpc`（`damage *=`）、`/kungfu/skill/longzhua-gong/sanzhua.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhan.lpc`（`damage *=`）、`/kungfu/skill/taiji-quan/zhenup.lpc`（`damage *=`）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫，手工部分，与 hy5 同源同修）：
  - `p/npc`、`quest` 下 7 个 boss/baowu 文件里，较短的旧 `order`/`data` 表删去，代码读的是后一份。
  - `p/migong` 三个迷宫的 `unique_rooms` 改名 `maze_unique_rooms`，与 `VRM_SERVER` 的同名变量分开。
  - `feature/alias.lpc` 的 `last_time` 改名 `last_cmd_time`，`ping.lpc` 的重复声明删去。
  - 四份 `control.lpc` 的 `void auto_check` 原型删去。
  - 21 个 `kill_ob`/`die` 改 `void`。
  - `roommaker` 删去被覆盖的表；`gboxa` 去掉注释里嵌套的 `/*`。
  - `d/xiyou/wudidong/npc/smith.lpc`、`waiter.lpc` 里有一句只剩括号的 `("wudidong_blacksmith");`。其他库这里是 `reload(...)`，本库没有 `reload()`，函数名被删掉后这句什么也不做，现删去。
  - 改动的 149 个对象 HEAD 与工作树各载入一次，无回退。

## 负数伤害当作消耗（2026-10-15，KB 06 §7.241）

`receive_damage("neili", -52)`、`receive_damage("qi", -12)` 之类把 `add()` 的负数写进了 `receive_damage()`：本库 `feature/damage.lpc` 对负数伤害报错（或归零），练功/运功时报 `F_DAMAGE: 伤害值为负值` 或消耗失效。已改为正数伤害，内力/精力类改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py`）：`/kungfu/skill/shaolin-tantui`。

## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 7 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 17 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 治疗/疗伤的属性名（2026-10-15，KB 06 §7.241）

`receive_heal()`/`receive_curing()` 也只接受本库的种类。1 个文件（多为只调用 `receive_heal`/`receive_curing` 的药物、NPC）来自其他体系，按本库的属性名改名（`scripts/lpc_port_es_props.py --any-file`）。

## family 映射（再补）（2026-10-15，KB 05 §7.30）

`mapping fam; fam = (mapping)ob->query("family");`（先声明后赋值）和泥潭式的 `query("family", me)` 同样直接取下标：无门派的新人拜师（`attempt_apprentice`/`recognize_apprentice`）、NPC 的 `greeting`、房间的 `valid_leave`、`ask_me` 等报 `Value being indexed is zero`。14 处补上 `if (!mapp(fam)) fam = ([ ]);`（刚 `recruit_apprentice()` 之后的除外）。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`tmjian/jianshen`、`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：屠龙刀法 `/kfedit/skill/yitian-tulong/tulong`、`/kungfu/skill/yitian-tulong/tulong`（比较经验时目标一侧读成 0）。

## 妙手回春的银针检查（2026-10-15）

`miaoshouhuichun` 的 `valid_learn()` 用了未赋值的 `object ob`，`ob->query_temp("weapon")` 每次都报错，谁也学不了；还把兵器对象和字符串 "银针" 比较。照 chidi 的修法改为 `ob = me->query_temp("weapon")`，再用 `id("yin zhen")`/`id("yinzhen")` 判断是否银针。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yinyun_ziqi`→`yinyun-ziqi`（`/kfedit/skill/yinyun-ziqi/cure`、`yinyun-ziqi/cure`）；`buddhsim`→`buddhism`（`qianye-shou`）；`douzhuan-xignyi`→`douzhuan-xingyi`（`/d/mr/obj/shu1`）；`jinwu-dao`→`jinwu-daofa`（`jinwu-daofa`）；`zhengqi-jue`→`zhengqijue`（`/d/bwdh/human`）。

## 嵩山剑法「蓄力」没穿布衣时报错（2026-10-15）

`songshan-jian/xuli` 用 `cloth = me->query_temp("armor/cloth")` 取衣服，随后直接 `cloth->query("material")` 判断要不要显示“衣袖鼓起”的描写；身上没有布衣时（裸身或只穿铠甲）这里报错，而此时 `apply/speed` 已经扣掉、复原的 call_out 还没排上，身法就一直少了一截。两处判断前补 `objectp(cloth) &&`。

## 技能名拼错：技能文件里拼错自己的名字（2026-10-15，KB 06 §7.249）

技能自己的文件（或它的绝招目录）里，`query_skill()` 读的是差一个字母的自己的名字，永远得 0：“基本功夫要高过本技能”之类的限制从不生效，按等级取招、计算伤害的那一项一直是 0。改为本技能的名字（`scripts/lpc_fix_skill_typo.py` 的 self 判据）：`baniao-jian`→`bainiao-jian`（`/kfedit/skill/bainiao-jian/bnzh`、`bainiao-jian/bnzh`）；`chanyun-tui`→`chuanyun-tui`（`/kfedit/skill/chuanyun-tui/shuangjue`、`chuanyun-tui/shuangjue`）；`frht-hamer`→`frht-hammer`（`/kfedit/skill/frht-hammer/san`、`frht-hammer/san`）；`lenyue-shengong`→`lengyue-shengong`（`lengyue-shengong`）；`liuyan-dao`→`lieyan-dao`（`lieyan-dao`）；`shenhuo-ling`→`shenghuo-ling`（`shenghuo-ling`）；`xiyu-tiezhang`→`xiyu-tiezheng`（`xiyu-tiezheng`）。

## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。2 处（1 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`clone/gift/npc/bingqipu.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/wind/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：被雇来打晕或杀人的李凌（`d/jingzhou/npc/liling2`）办完事要离开时报错，留在原地。1 个文件改为移进本库的虚空房间 `VOID_OB`（`/clone/misc/void`），与原作把它们“停放”在巫师房间的用意相同。

## 燃木刀法「焚天」的效果一秒就消失（2026-10-15，KB 06 §7.246）

每秒检查的 `check_fight()` 声明了 `object weapon;` 却从不赋值，条件里的 `!weapon` 永远为真，效果在第一次检查时就被撤掉。把这一项改为 `!objectp(weapon = me->query_temp("weapon"))`，先存兵器再判断刀的种类。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

1 个文件、1 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/city/obj/tudao`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 2 个（2 个原来载入不了），没有退步。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/xmud/xnventory.lpc`。

## `kungfu/skill/qingyi-jian` 第一式的 `skill_name` 丢了收尾引号（2026-10-18，KB 03 §4.6）

`"skill_name" : "大悲式,` 的收尾引号没了（转码时跟半个汉字一起丢了），字符串连到下一行，`damage_type` 成了代码：`Illegal character 0xe5`，整个武功载入不了。补回 `",`（同系的 bixiecanyang、syxjl 等库里有完好的同名文件）。载入：通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 8 个对象设了本库没有文件的武功（42 个名字，最多的是 `moon-blade`、`yue-strike`、`anxiang-steps`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：8 个里 8 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 90 处、71 个文件：`bixie-sword`→`pixie-sword`（34 处）、`kunlun-shnfa`→`kunlun-shenfa`（16 处）、`shaolin-shnfa`→`shaolin-shenfa`（12 处）、`tiaji-jian`→`taiji-jian`（4 处）、`lingbo-weibu`→`lingboweibu`（4 处）、`yunu-xinfa`→`yunv-xinfa`（4 处）、`xiuluao-dao`→`xiuluo-dao`（3 处）、`yiyangzhi`→`yiyang-zhi`（2 处）等共 16 个名字。（`scripts/lpc_fix_skill_names.py`）

## set_name 的 id 参数传成字符串（2026-10-19，KB 06 §7.260）

`set_name("海口大碗", "bowl");` 把物品的 id 写成了字符串，本库的 `set_name(string name, string *id)` 要的是数组，驱动在编译时报 `Bad type for argument 2 of set_name ( string * vs string )`，整个物件载入不了；旧驱动不检查参数类型，字符串里照样找得到这个词，物品能用 id 称呼。改成 `({ "bowl" })`，共 1 个文件：`/d/baituo/npc/obj/bowl.lpc`。（`scripts/lpc_fix_set_name_id.py`）

## feature/damage.lpc 丢了 set_ghost()（2026-10-19，KB 06 §7.262）

`feature/damage.lpc` 里有 `int ghost` 和 `is_ghost()`，没有 `set_ghost(int i)`；木人、狼等 NPC 在 `create()` 里调用它，整个 NPC 报 `Undefined function set_ghost` 载入不了。从 xkx100 补回这一行函数，受益 NPC 9 个：`d/nanshaolin/npc/muren-fighter1`、`d/nanshaolin/npc/muren-fighter2`、`d/nanshaolin/npc/muren-fighter3`。（`scripts/lpc_transplant_function.py`）

## 全局头文件丢了 1 个宏（2026-10-19，KB 04 §6.16）

`/include/globals.h` 里没有定义 `MAILDIR`，用到它们的物件（名单里 1 个）编译时报 `Undefined variable`/`Undefined function`，整个物件载入不了（编译器在第一个未定义的名字上停下，后面的错误和警告都看不到）。同系的库在各自的头文件里都有这几行：照其中和本库共有文件最多的那个库，原样补到 `/include/globals.h` 最后一个 `#define` 之后，宏体里出现的路径在本库里都存在。名单里的物件除了这几个宏之外还有别的错误，暂时仍载入不了。（`scripts/lpc_restore_defines.py`）

## sanniang 的 query(environment(...))->query（2026-10-19，KB 06 §7.266）

`d/biancheng/npc/sanniang.lpc`（边城的三娘）里写成了 `query(environment(this_object()))->query("discussion_shen")`，多了外面一层 `query(`，驱动报 `Bad type for argument 1 of query ( string vs object )`，整个 NPC 载入不了；同一个文件另一处正确写成 `environment(ob)->query("discussion_shen")`。去掉多余的 `query(`。

## 出口指向不存在的房间（2026-10-19，KB 06 §7.257）

下列房间的出口写的文件不存在，而对面恰好只有一个房间的出口指回本房间，所以按对面的房间改正（笔误、大小写、路径少了一级）：

- `/d/xiyou/death/new-walk5.lpc` 的 `north` 出口：`/d/death/zhengtang` → `/d/xiyou/death/zhengtang`
- `/d/yanmen/shance.lpc` 的 `north` 出口：`CANYON7` → `canyon7`

改后房间照常载入（与 HEAD 逐个对比，没有退步），出口现在指向存在的房间。

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 1 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/taoyuan/npc/kid.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 两个斜杠开头的物件路径（2026-10-19，KB 06 §7.276）

1 个文件、1 处物件路径写成 `//…`（如 `carry_object("//clone/cloth/hic_cloth")`）：`/d/gaoli/npc/xiake.lpc`。当年的驱动不介意（路径先被规范化）；新驱动把原样的字符串交给 master 的 `valid_read()`，securityd 按 `//clone` 查目录，NPC 的 euid 没有权限，报 `Read access denied.`，NPC 载入不了。改成一个斜杠。

## 手工收尾（2026-10-19，KB 04 §6.10）

- `d/taoyuan/npc/kid.lpc`：`create()` 里没有用到的 `int i, amun;` 删掉（与 hy5 同一个文件，同样的修改）。

与 hy5 的拷贝逐字相同，hy5 里载入对比过：没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 2 个文件，修前 HEAD 载入失败。别的库里同路径的完好副本只比这里少几个标点，按它补回（括号里是那个库）：`/d/city2/npc/zhengmen.lpc`（jqxz2008）。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/kfedit/condition/wuhudu_poison.lpc`。修后与 HEAD 逐个对比载入：这 2 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 5 个文件：`/u/dhxy/gem.lpc`、`/u/dhxy/gem2.lpc`、`/u/guaf/gem.lpc`、`/u/hxsd/gemw.lpc`、`/u/hxsd/hxsdm.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 5 个原来载入失败、现在载入，没有退步。

## 两个技能文件丢掉的引号，用另一条线的完好副本补回（2026-10-19，KB 03 §4.6）

`kungfu/skill/huanhe-dao.lpc`（`"zhaoshi" : "「谁能书 笙隆,` 少了结尾的引号）和 `kungfu/skill/kunlun-zhang.lpc`（`……另一掌却按向$n「,` 同样）：别的库里的完好副本（hy5）是这两个文件去掉几处标点后的样子，补回标点（`lpc_restore_from_twin.py --diff --extra`，本库多出来的局部变量声明保留，然后按载入警告删掉没用到的 `level`、`time`、`level2`、`i`、`ap`、`dpp`、`dpd`、`dpf`、`weapon2`、`type`、`msg`、`jiali`、`damage`）。修前 HEAD 两个都载入失败，修后都载入，没有警告，没有回归。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：龙女的 class 判断永远走不到“不是道士”那一支；龙女的 class 判断永远走不到“不是道士”那一支。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/d/gumu/npc/longnv.lpc`（3 处）、`/quest/menpaijob/gumu/zf/longnv.lpc`（3 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x == "a" || "b"`：后面的字符串常量永远为真（2026-10-19，KB 06 §7.281）

`if (arg == "yuyou" || "yu you")` 里的 `"yu you"` 是非空字符串，永远为真，整个条件对任何 `arg` 都成立；作者要的是每个字符串都和变量比较。具体是：离开时清除“砍柴”标记只在往北走时才生效，往南不清。在每个字符串前补上变量和运算符（`scripts/lpc_fix_literal_or.py`；`forrest2.lpc` 是 `dir == "north" && "south"`，手工改成 `(dir == "north" || dir == "south") && ...`）：`/d/xiyou/lingtai/forrest2.lpc`（1 处）。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。具体是：客栈小二从不拦住付了房钱又往南/往北走的客人。改动：`/d/changan/ca2.lpc`（1 处）、`/d/mingjiao/shanmen.lpc`（1 处）、`/d/sdxl/baihuagu/yangfeng.h`（1 处）、`/d/taiyuan/shanxi/obj/jiuwan.lpc`（1 处）。另有 `/d/city/npc/majiang.lpc`（2 处）、`/d/jinan/npc/mj.lpc`（2 处） 的条件下面做的是别的事（`==` 和 `||` 也可能是本意），保持原样。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/vrm_server.lpc`（1 处）、`/adm/daemons/vrm_server2.lpc`（1 处）、`/adm/daemons/vrm_servertnew.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 61 处）；其后 `x == "a" && x == "b"` / `x == "a" || "b"` 这类被 `==` 暴露出来的链也随之改成 `||` 或补全变量（`/d/hainan/npc/xiaohe.lpc`）。改动：`/adm/daemons/combatd.lpc`（11 处）、`/adm/daemons/combatdtest.lpc`（1 处）、`/clone/npc/man.lpc`（1 处）、`/cmds/usr/bangding.lpc`（1 处）、`/d/baiyun/shanliu/npc/xiucai.lpc`（1 处）、`/d/city/npc/matong.lpc`（3 处）、`/d/city/shufengguan.lpc`（1 处）、`/d/city4/mj/1mj.lpc`（3 处）、`/d/city4/mj/mj.lpc`（3 处）、`/d/city4/npc/majiang.lpc`（3 处）、`/d/city4/npc/matong.lpc`（3 处）、`/d/city4/obj/mj.lpc`（3 处） 等 29 个文件。

## `callouts`：`sizeof(info[i]) == 4` 把每一行都挡掉了（2026-10-20，KB 06 §7.287）

驱动的 `call_out_info()` 每项只有 3 个元素，输出行前的守卫 `if (sizeof(info[i]) == 4)` 永远不成立，指令只打印表头。改为 `>= 3`。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `mcheck`：`query_ip_rport()` 驱动里没有（2026-10-20，KB 06 §7.291）

指令要显示连线的远端端口，MudOS 时代的 `query_ip_rport()` 在 FluffOS 里不存在（`query_ip_port()` 给的是本地端口），指令编译不过。文件里加了一个返回 `"?"` 的占位函数（dtsl 的同名指令早就这么做）。改动：`/cmds/imm/mcheck.lpc`。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/adm/daemons/logind.lpc`。

## 缺少的 `men.h`：楚州四个城门房间不能加载（2026-10-20，KB 04 §6.23）

`d/zhongyuan/chuzhou/` 的 `nan_men.lpc`、`bei_men.lpc`、`dong_men.lpc`、`matou.lpc` 从自己的目录 `#include <men.h>`（xkx 城门榜文的辅助函数），存档里没有这个文件，启动预载时每个房间报 `Cannot #include men.h`（共 5 次）。兄弟库 hy5 在同一路径放着一个空的 `men.h`，这四个房间也没有用到里面的任何东西，所以补一个只有注释的 `men.h`。加载检查：HEAD 0 通过 / 4 失败，工作树 4 通过。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 82 个 NPC 文件写成空 `chat_msg`（例如 `/d/baiyun/shanliu/npc/shanliu.lpc`、`/d/baiyun/shanliu/npc/slmanager.lpc`），它们走的基类 `chat()` 本来已经检查了列表大小（或碰巧不出错），不受影响；下面这些文件各自带着一份没有检查的 `chat()`（NPC 里的副本、旧版基类），一并加上守卫。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/clone/guard/baoer.lpc`、`/clone/guard/long2.lpc`、`/clone/npc/npc.lpc`、`/clone/npc/npc1.lpc`、`/d/chengdu/npc/npc1.lpc`、`/d/chengdu/npc/npc2.lpc`（等共 36 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 7 个存档共 7 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。改动：`/p/migong/migong/boss.o`（1 处）、`/p/migong/migong/npc.o`（1 处）、`/p/residence/beg1434617478.o`（1 处）、`/p/residence/name1433777592.o`（1 处）（等共 7 个存档）。

## `lsusers`：用档案里没有的 `/clone/misc/player`（2026-10-21，KB 06 §7.299）

管理员扫描里 `lsusers` 报 `Bad argument 1 to EFUN call_other() Got: int(0)`（`cmds/adm/lsusers.lpc`）：指令 `new("/clone/misc/player")` 一个对象，用它的 `new_object(name)` 逐个还原玩家存档；本库没有 `/clone/misc/player.lpc`（同系的 hy3、jhfy、xyzx 等 27 个库带着它，`new_object()` 只定义在那里），`new()` 答 0，后面就是对 0 的调用。`new()` 之后加 `if (!ob) return notify_fail(...)`，指令回一句话而不是系统错误；文件本身补不上，那个旧的玩家对象已经不是本库的用户对象了。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## 富贵山庄裁缝 `clothlady`：一行丢了换行，`obj = new(..)` 成了注释（2026-10-21，KB 06 §7.346）

`//    say (...);                    obj = new(__DIR__"obj/notecase");` 在文件里是一行（档案丢了换行），`new()` 被 `//` 吞掉，`obj->move(this_player())` 对 0 调用。拆回两行（fengyun434 的同一份文件是两行）。

## `selfthinking`、`qlian`：缺乏实战经验的提示读了不存在的老师（2026-10-21，KB 06 §7.348）

自创武功的自习指令在“技能等级³/10 大于实战经验”时打印 `printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name())`。这一句是从 `learn` 抄来的，`ob` 是老师；自习没有老师，`object ob;` 从没赋值，`ob->name()` 抛 `call_other() ... Got: int(0)`。改成 `你对「%s」的疑问总是无法领会` 加 `to_chinese(skillname)`，去掉没用的 `object ob;`。改动：`/cmds/skill/selfthinking.lpc`。

## 黄蓉 `ask_husband`：找优胜者的那段被注释掉，`user` 没赋值（2026-10-21，KB 06 §7.348）

`ask rong about 丈夫` 对谁都抛 `Bad argument 1 to call_other() ... Got: int(0)`：优胜者（`nvxu->query("winner")`）不是提问的人时，原来先 `find_player(id)`，找不到就 `new(USER_OB, id)->restore()` 把离线的人读出来；这段被注释掉，下面的 `user->query("death_count")` 照用。默认没有优胜者（`winner` 为 0）。改成只找在线的优胜者（`user = stringp(id) ? find_player(id) : 0`），没有优胜者或优胜者离线时直接回答“我的丈夫就是”加女婿 NPC 的名字。hy5 上实测：HEAD 抛错，改后 “黄蓉说道：我的丈夫就是精确！”。改动：`/kungfu/class/taohua/rong.lpc`。

## `xue`：禁学技能的检查读了还没有赋值的 `ob`（2026-10-21，KB 06 §7.348）

`cmds/skill/xue.lpc` 在解析参数、找老师之前就判断 `ob->query_temp("no_kill") || userp(ob)`，`ob` 是 0，进来就抛错（`lpcc_bare.py`：HEAD `Bad argument 1 to EFUN call_other()`，改后正常；游戏里 `xue` 这个动词在 hy5 上走的是 `learn`，敲 `xue` 看不出来，直接调用文件才暴露）。同一段在 `learn.lpc` 里没有 `ob`。加 `objectp(ob) &&`，效果和 `learn.lpc` 一样（这一段在解析之前永远不触发）。改动：`/cmds/skill/xue.lpc`。

## 铁扇公主 `unconcious()`：声明里的 `present("tie shan", me)`（2026-10-21，KB 06 §7.348）

`object tieshan = present("tie shan", me);` 写在 `me = query_temp("last_damage_from")` 之前，`present(.., 0)` 抛错：公主一昏迷就抛错，火焰山的铁扇交不出来。铁扇是公主身上的（`give_tieshan()` 里同样是 `present("tie shan", me)`，那里的 `me` 是公主），改成先 `ob = this_object();`，再 `tieshan = present("tie shan", ob);`。hy5 上 `call princess->unconcious()`：HEAD 抛错，改后返回。改动：`/d/qujing/firemount/npc/princess.lpc`。

## 岳飞 `imbue_event()`：`obj = me->query_temp("weapon")` 却读 `weapon`（2026-10-21，KB 06 §7.348）

梦醒之后给武器“附红缨”的事件：赋值写给了 `obj`，消息里读的是没赋值的 `weapon->name()`，每次都抛错。改成 `weapon = ...`，没拿武器的返回 0（`imbue/yuefei` 没设，下次还能触发）。改动：`/d/tieflag/dreamland/npc/yue.lpc`。

## 黑玉石门 `stonedoor.lpc`：第五块玉 `white` 从没赋值（2026-10-21，KB 06 §7.348）

`check_needles()` 只检查绿、黑、黄、红四块玉，最后却 `white->move(env); destruct(white);`：四块玉对上之后红、绿、黄先被销毁，再在 `white` 抛错，门打不开，玉也没了。风云的上游把整段注释掉了；这里去掉 `white` 这一句和声明，四块玉对上门就开。改动：`/d/eren/eren2/obj/stonedoor.lpc`、`/d/eren/obj/stonedoor.lpc`。

## 妙手回春 `valid_learn()`：先读 `ob->query_temp("weapon")` 再给 `ob` 赋值（2026-10-21，KB 06 §7.348）

学这门暗器技能时 `valid_learn()` 第一个武器检查读的是没赋值的 `ob`，`xue` / `learn` 在这里抛错；后面 `ob = me->query_temp("weapon")` 的检查才是对的。有两种写法：`if (!ob->query_temp("weapon"))` 改成 `me->query_temp("weapon")`；`if ((string)ob->query_temp("weapon") != "银针")`（拿一个对象和字符串比较，永远不等，补上 `ob` 之后这门技能也学不成）改成后一种写法里的 `!objectp(ob = me->query_temp("weapon")) || !(ob->id("yin zhen") || ob->id("yinzhen"))`。改动：`/d/pingan/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/d/pingan/shenzhen/skills/miaoshouhuichun.lpc`、`/kungfu/skill/miaoshouhuichun.lpc`。

## 守卫 `clone/guard/baoer.lpc`：`do_send()` 里丢了收尾引号，整个文件从来没编译过（2026-10-21，KB 03 §4.6 第五轮、KB 06 §7.349）

`new_id=ob->query("id")+"'s bao er;` 少了字符串结尾的引号：字符串一直读到下一行的引号，后面的汉字全成了 `Illegal character 0xe5`（几千行错误，批量验证器里的表现是“没有答案”）。补成 `"'s bao er";`。文件第一次能编译后带出 11 个 `Unused local variable` 警告（`host_id`、`i`、`obj`、`shape`、`emotes`、`inv`、`msg`、`same_place`、`couple_id`、`couple_name`、`couple`），按 KB 04 §6.10 删掉。文件里的 `do_heji` / `do_lian` / `do_order` / `do_title` / `do_ticks` / `do_sha` / `do_shape` / `do_hulian` / `do_quit` 等处理函数都有定义（静态扫描因为引号没闭合把它们当成字符串里的文字，补引号后运行时 `function_exists()` 全部证实存在），所以这个文件的 `add_action` 不属于死登记，没有动。改动：`/clone/guard/baoer.lpc`。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 154 条注册（129 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/medicine/nostrum/gaoyao.lpc`（`do_eat`）、`/d/baiyun/beach1.lpc`（`do_dive`）、`/d/baiyun/npc/hockowner.lpc`（`do_redeem`）、`/d/baiyun/shanliu/npc/taoist1.lpc`（`do_answer`）、`/d/baiyun/shanliu/npc/yang.lpc`（`do_answer`）、`/d/baling/npc/zhou.lpc`（`do_redeem`）、`/d/beijing/npc/guanfuzi.lpc`（`do_join`）、`/d/beijing/npc/xutianchuan.lpc`（`do_skills`）、`/d/biancheng/npc/gwaiter.lpc`（`do_redeem`）、`/d/biancheng/npc/oldman.lpc`（`do_vendor_list`） 等共 129 个文件。最多的函数名：`do_eat` 27 处、`do_redeem` 22 处、`do_send` 15 处、`do_qiecuo` 12 处、`do_drink` 10 处。没有动（读过）：`/d/tieflag/huashan/npc/snake.lpc` 的 `do_train`（不是单独一行的语句（`obj->add_action()`、宏或没有分号的写法））。

## 基类的 `add_action` 登记：处理函数只在后代里定义，基类自己被加载时报错（2026-10-21，KB 06 §7.349）

房间、NPC、公告板这类基类，`init()` 里登记的 `add_action("函数", "动词")` 的函数只由继承它的后代定义；基类对象自己被直接加载（房间可以走进去、NPC 可以克隆）时，访客输入这个动词，驱动报 `*Function for verb 'x' not found.`（第一轮扫描把这些当成“有后代定义，是活的”放过了，`scripts/lpc_verify_handlers.py` 在基类对象上跑 `function_exists()` 才看出来）。登记前加 `if (function_exists("函数", this_object(), 1))`（第三个参数 1：默认 `function_exists()` 把 `protected` / `private` 函数当作没有定义），后代照常登记。共 6 处、1 个文件（`scripts/lpc_fix_dead_add_action.py --guard`）：`/d/bwdh/kantai.lpc`（`do_abandon`、`do_practice`、`do_study`）。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/d/wudang/npc/xiaocui.lpc`（`__DIR__ "../obj/nuerxiang"` → `"/d/wudang/obj/nuerxiang"`）。

## 商人的 `list` 命令：登记的是另一个血统的函数名（2026-10-22，KB 06 §7.349）

第 42 批把 `add_action("do_vendor_list", "list");` 当成死登记删掉了（这些文件里没有 `do_vendor_list`，输入 `list` 只会得到 `*Function for verb 'list' not found.`），但它们的商人基类里同一个工作的函数叫 `do_list`，`list` 动词就此没了：`/d/death/npc/waiter.lpc`, `/d/huangshan/npc/xiaofan.lpc`, `/d/jinling/npc/armorseller.lpc`。按真正存在的函数名放回 `add_action("do_list", "list");`；用库的管理员账号克隆 NPC 再输入 `list` 实测（`/d/death/npc/waiter.lpc`：`您想看哪一种货物(armor, book, misc, weapon)？ ⊙马老四咳道：这位小兄弟，进来喝几盅小店的还阳`），每个文件都列出商品或问要看哪一类。同一批里放回去后仍答 `什麼？`、没有商品或者列表时报错（货品文件缺失）的商人没有动。

## 缺失物品的 `new()` / `carry_object()` 调用链加了保护（2026-10-22，KB 06 §7.73 补充）

`new(路径)->move(...);` / `carry_object(宏("x"))->wear();` 这类语句，路径指向的文件在这个压缩包里没有：`new()` 返回 0，`->move()` 在 0 上报 `Bad argument 1 to EFUN call_other()`。在 `create()` 里这个对象永远加载不了，在 `reset()` 里第一个缺失物品之后的刷新每次 reset 都被跳过。2 个文件里 3 处（`new`）改成 `{ object new_ob = new(路径); if (new_ob) new_ob->move(...); }`（`scripts/lpc_guard_carry_object.py --new`：路径按这个文件自己看到的宏解析，宏名冲突、虚拟对象路径一律跳过）。 对这 2 个改动文件做加载检查（HEAD 与工作区对比）：HEAD 能加载 2 个，现在 2 个（新增可加载 0 个，回归 0 个）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← aoxiangtianji：`chinese_month()`（2 处调用）、`chinese_period()`（4 处调用）；`/adm/daemons/natured.lpc` ← aoxiangtianji：`outdoor_room_event()`（6 处调用）；`/adm/daemons/natured.lpc` ← fengyun434：`get_current_day_phase()`（3 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 已补回 `/d/tanggu/kongchangdi.lpc` 的 `look_leitai()`（原型还在、函数体丢了；bxsj 里同一文件有完整函数，原样补到文件末尾，`scripts/lpc_port_function.py --lfun`；真机会话里 `look leitai`：HEAD 报上面的错误，改后正常输出）；`/d/fugui/npc/cai.lpc` 的 `test_dart()`（原型还在、函数体丢了；fengyun434 里同一文件有完整函数，原样补到文件末尾，`scripts/lpc_port_function.py --lfun`；真机会话里 `ask cai about 任务`：HEAD 报上面的错误，改后正常输出）。 还剩 89 个函数没有补（chat_msg_combat 47, inquiry 29, item_desc 6, other 5, chat_msg 2）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/imm/help2.lpc`:`confirm_l_choice`、`/d/beijing/npc/yi.lpc`:`ask_jiaobiao`、`/d/biwu/chen.lpc`:`ask_weiwang`、`/d/biwu/chen.lpc`:`ask_me`、`/d/biwu/chen.lpc`:`ask_tuihui`、`/d/biwu/ding.lpc`:`ask_me`、`/d/biwu/ding.lpc`:`ask_du1`、`/d/biwu/ding.lpc`:`ask_du2`、`/d/biwu/huang.lpc`:`ask_me`、`/d/biwu/miejue.lpc`:`ask_for_quit` 等另外 79 个。

## 读不到的留言板：`"/clone/board/x"->foo();` 在 `create()` 里报错（2026-10-22，KB 06 §7.357）

xkx 系的房间在 `setup()` 之后写 `"/clone/board/gaibang_r"->foo();` 来加载留言板（`foo()` 本来就没有定义，只为了触发加载）。这个库没有这个文件，`call_other()` 报 `*call_other() couldn't find object '/clone/board/gaibang_r'`，对象留在内存里、`load_object()` 却抛错：玩家第一次走进房间就看到错误，写在 `create()` 中间的还会切掉后半段。`scripts/lpc_fix_missing_foo.py` 把 1 条单独成行的语句（`/clone/board/jail_b`；`/d/city2/jail.lpc`）注释掉并写明原因（别的房间里同样的语句本来就是作者自己注释掉的）。证明和 45 个库的整体加载检查见 KB 06 §7.357。

## `log/` 下的日志子目录没有人建：写日志的 `write_file()` / `log_file()` 报错（2026-10-22，KB 06 §7.358）

这个库的代码往 `log/` 的 2 个子目录写日志：`log/html`（`clone/npc/robot-judge.lpc`）、`log/test`（`d/hangzhou/obj/jiasha.lpc`）。压缩包、`git clone` 和站点包里都没有这些目录（本地启动没有写过它们，`gen_keep_dirs.py` 没记），`write_file()` 对不存在的目录抛 `*Wrong permissions for opening file /log/dlog/money for append. "No such file or directory"`，调用它的函数在写日志那一行中断，后面的奖励、标志、步骤都没有执行。本库的 `log_file()` 会自己建目录（实测，或读源码：nitan 系的 `assure_file()`），所以这里只记了直接用 `write_file()` / `save_object()` 写的目录。把 `log/html`、`log/test` 记进 `scripts/wasm_keep_dirs.txt`（`scripts/lpc_keep_log_dirs.py`；站点和 pristine 树按它建空目录）。证明（`scripts/lpcc_eval.py`，在 `/adm/daemons` 这类目录下的求值对象里写 `/log/zzdirprobe/...`，新进程）见 KB 06 §7.358 的实测表。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 75 个文件里 95 行只含这个指针的行（`"交镖"   : (: ask_jiaobiao :),` `"finish" : (: ask_jiaobiao :),` `"威望" :  (: ask_weiwang :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 38 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）；各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 38 处（32 个文件）：拼名字的赋值 25 处、与汉字常量比较 10 处、对切片赋值 3 处。例：`name[2..3]` → `name[1..1]`（`/d/mr/murong-bo.lpc:98`）；`name[0..1]` → `name[0..0]`（`/d/mr/npc/bo.h:17`）；`old_name[0..3]` → `old_name[0..1]`（`/kungfu/class/taohua/huang.lpc:249`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：24 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 24 处（12 个文件）：`if( (strlen(name) < 8) || (strlen(name) > 20 ) ) {`（`/clone/guard/baoer.lpc:1799`）；`if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {`（`/cmds/skill/creatskill.lpc:687`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 17 个文件；茶馆猜诗 `mixup` 1 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 11 处（3 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## 死巫师出口 gold/dock、sunrise、mei（2026-10-23，KB 06 §7.370）

`/d/wanjiegu/road4` 东向 `/u/g/gold/dock`、峨眉寿星居南向 `/u/xinyue/sunrise_room`、玩家卧室通往 `/u/mei/…` 均无对应房间。`scripts/lpc_fix_drop_dead_u_exits.py` 删除这些出口行，并去掉同方向的 `create_door`（否则 `create_door` 无出口会炸）。本库 1 处。证明：zxty08nxgbb 的 road4 HEAD 有东向，改后没有；mei_room1 可加载。


## 深度功能测试（2026-10-27，§6.25 zhongling tell_object 引号错位）

`d/wanjiegu/npc/zhongling`（及同路径副本）的 `tell_object("who, 钟灵脱下一双绣花鞋。\n")` 把对象参数写进了字符串；改为 `tell_object(who, "…")`。证明：原文错位；改后加载，语料残渣 0。

## 深度功能测试（2026-10-27，§6.25 tell_object 参数顺序）

`tell_object("…", me/who)` 参数颠倒（消息当对象）；改为 `tell_object(me/who, "…")`（rukou.lpc）。证明：残渣 0；抽样 guest/rukou/forest_c 加载。

## 深度功能测试（2026-10-27，§6.25 tell_object 路径当房间）

`tell_object("/…", …)` → `tell_room(load_object("/…"), …)`（去掉 `.lpc`）。

