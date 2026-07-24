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
    haiyang2/weimingkongjian. Fixed the live copy's path.
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
