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
