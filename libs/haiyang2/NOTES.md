# haiyang2 — 海洋II (Ocean II)

Archive: `海洋II 2010 正式无错完整版下载.rar` (archive #63; dup:
`海洋II 2010 正式无错完整版下载 (1).rar`, not processed, per AGENTS.md's
duplicate-archives table). Port: **40057**. Status: **done** (boots
clean, full registration flow verified end-to-end twice with two
different real Chinese names, both reaching the actual game world with
zero runtime errors on the second clean run).

## What this is

The raw archive extracts to a top-level `bin/` (a prebuilt Windows MudOS
binary release: `MudOS.exe`, `runmud`, `runqym`, ini files — ignored, we
use our own driver) plus the real mudlib root at `hy3/`. The mudlib's own
config file (`bin/config.hy`, labeled "MudOS 0.9.20") self-identifies via
`name : HY2`; `include/mudlib.h`'s `MUDLIB_NAME`/`INTERMUD_MUD_NAME`
constants decode (GBK) to **"海洋II"** ("Ocean II"), matching the
archive's own title, and the live in-game banner says "〖海洋II〗" /
"星月传奇" ("Star-Moon Legend", an alternate/sub-brand name used
throughout the UI text) — so the archive's Chinese title is accurate, no
identity mismatch to flag (unlike several previous libs in this batch).

Lineage: `adm/single/{master,simul_efun}.c` layout, `master.c`'s own
header comment says **"for ES II mudlib... original from Lil...
rewritten by Annihilator... modified by Xiang for XKX"** — this is the
same "ES II" lineage already seen many times in this project (es1_win,
esI, xkx2001, rzrmud, xo/xo_final, bmxkx2001,
kxkj, yueyingqiyuan, wuhanzhan, ...). Small simul_efun
set (`atoi`, `chinese`, `file`, `gender`, `object`, `path`, `wizard`,
`message` — 7 files, ~350 lines total) confirms the correctly-architected
per-object `F_DBASE` storage pattern (verified: `feature/dbase.lpc` has
real local `set`/`query`/`delete`, and `grep` for `efun::set(`/
`efun::query(`/`efun::delete(` across the whole tree comes up empty) — the
nitan-family §15 shared-simul_efun-dbase architecture bug does **not**
apply here, confirmed by reading the source rather than assumed.

Size: 29,689 raw files, 26,184 `.c` files, 26,182 `.lpc` files after the
rename (one directory-named-like-a-file quirk below reduced the count by
one net item). This puts it in the "tens of thousands of files" range
AGENTS.md §6b flags as a real memory-pressure risk for the full `lpcc_check.sh`
sweep (comparable to `nitan6`'s 23,100 files, which was skipped entirely) —
ran it anyway with active `free -h`/RSS monitoring throughout and it
completed without concerning memory pressure; see "lpcc sweep" below for
the actual numbers observed.

## Fixes applied

1. **AGENTS.md §15h (is_chinese)** — `adm/simul_efun/chinese.lpc`'s
   `is_chinese()` used the GBK lead-byte range check
   (`strlen(str)>=2 && str[0]>160 && str[0]<255`), always false against
   this driver's UTF-8 codepoints. Rewritten to
   `strlen(str)>=1 && str[0]>=0x4e00 && str[0]<=0x9fff` (also relaxed the
   length floor from 2 to 1 — the sliding-window caller in
   `check_legal_name` calls this with genuine 1-character suffixes at the
   last loop position, which the old `>=2` guard would always fail).
2. **AGENTS.md §15h (check_legal_name)** — `adm/daemons/logind.lpc`'s
   `check_legal_name()`: halved the byte-calibrated length bound
   (`strlen(name)<4||>10` → `<2||>5`, matching the message text's own "2
   到 5 个中文字" which was already correct) and dropped the `i%2==0 &&`
   GBK-byte-parity gate from both sliding-window `is_chinese()` checks (now
   checks every character position, not every other one).
3. **AGENTS.md §15h (chinesed.lpc, dead code)** — `adm/daemons/chinesed.lpc`'s
   `check_chinese()` had the identical `i%2==0 &&` shape; fixed the same way
   for consistency even though `grep` confirms it has zero callers anywhere
   in the lib (harmless dead code, fixed as cheap insurance/consistency).
4. **AGENTS.md §14 (valid_override 3-arg)** — `adm/single/master.lpc`'s
   `valid_override(file, name)` upgraded to the documented 3-arg
   `(file, name, main_file)` signature, checking `main_file` too so a
   fragment `#include`d into `simul_efun.lpc`/`master.lpc` can legitimately
   `efun::` override.
5. **AGENTS.md §8d/§15o (get_include_path)** — `master.lpc` had no
   `get_include_path()` apply at all. Added the standard one (prepends the
   compiling file's own directory + `:DEFAULT:`). Needed because this lib
   has genuine per-directory local headers, e.g. `d/marry/hunyin.h` sitting
   next to `d/marry/chen.c`/`d/pingan/marry/chen.c`, included via
   `#include <hunyin.h>` (angle brackets, which only search the configured
   include path without this apply). `convert_lib.sh`'s own automated pass
   already converted 13 other local angle-bracket includes to quoted form
   directly; this apply is additional insurance for any it didn't catch
   and for mid-connection lazy compiles (§8d's documented preload-time
   consult gap).
6. **AGENTS.md §15n (custom securd.lpc ACL blocking compile-time reads)** —
   `adm/daemons/securd.lpc` (`SECURITY_D`) is a genuinely custom ACL
   daemon (per-directory `exclude_read`/`trusted_read` tables, not the
   simpler `find_object`-only pattern) with no `func`-discrimination for
   compile-time operations at all. Added an early
   `switch(func){case "load_object": case "recompile_object": case
   "include": return 1;}` to `valid_read()`, before the real ACL logic —
   confirmed necessary: `adm/daemons/logind.lpc`'s `gb_big5()` (part of
   the very first thing every connection runs) unconditionally calls
   `BAN_D->is_banned(...)` and `UPTIME_CMD->main()`, neither of which is
   ever preloaded, and a fresh unauthenticated connection's default
   `this_player()` status is `(player)` — without this fix the very first
   connection's lazy compile of `band.lpc`/`uptime.lpc` would hit "Read
   access denied" (this exact failure mode was reproduced and fixed on
   `shujian2008`, the precedent for §15n).
7. **Preload path typo** (both `adm/etc/preload`, the live path per
   `master.lpc`'s `epilog()` reading `CONFIG_DIR+"preload"` where
   `CONFIG_DIR = "/adm/etc/"`, AND the stray unused `adm/daemons/preload`
   decoy copy — same "dead duplicate preload file" shape documented for
   `wmkj`/archive #55): both listed `/adm/daemons/securityd`,
   but the real file on disk is `adm/daemons/securd.c`/`.lpc` (matches
   `include/globals.h`'s `#define SECURITY_D "/adm/daemons/securd"`).
   Fixed both copies' typo'd path so the security daemon actually
   preloads (with proper `create()`/`restore_list()` bootstrap ordering)
   instead of silently never loading via this entry (it would still get
   lazily loaded on first real access either way, per §15n's fix above,
   but preloading it properly is the correct/intended behavior and avoids
   any ordering surprises).
8. **New §15p manifestation: `DNS_MASTER` triggered from inline
   registration-flow code, not preload.** `adm/etc/preload` does NOT list
   `dns_master` (nothing to exclude there — checked proactively per
   standing policy) — but `adm/daemons/logind.lpc`'s `gb_big5()` (again,
   the very first thing every connection executes) unconditionally calls
   `DNS_MASTER->query_muds()`/`DNS_MASTER->query_svc()` to render an
   intermud "connected MUDs" table. `DNS_MASTER`
   (`/adm/daemons/network/dns_master`) does real `resolve()`/
   `socket_create()`/`socket_bind()` work in its `create()` against a
   hardcoded intermud boot server unreachable in this environment — the
   same hang risk class documented in AGENTS.md §15p, just reached via a
   direct call instead of a preload entry. Since the whole block is purely
   cosmetic (a table of other connected MUDs, never needed for
   registration), disabled it: `mud_list`/`mud_svc` are now set to empty
   mappings directly instead of ever touching `DNS_MASTER`. Separately,
   the `Mud_name()` macro (`include/net/macros.h`) — used unconditionally
   elsewhere too, e.g. `adm/daemons/channeld.lpc`'s chat-verb formatting —
   also force-loads `DNS_MASTER` on every call; since `DNS_MASTER`'s own
   `query_mud_name()` just returns the constant `INTERMUD_MUD_NAME`,
   redefined the macro to return that constant directly
   (`#define Mud_name() INTERMUD_MUD_NAME`), byte-for-byte equivalent
   behavior with zero risk of ever loading `dns_master`. Verified via
   `grep` that no other macro in that header (`udp_port()`, `index_add`,
   `index_call`, `dns_log`, `dns_warning`) is used anywhere outside
   `adm/daemons/network/` (the network daemon family itself, never
   preloaded/reachable) — only `Mud_name()`/`mud_nname()` needed the fix.
9. **NEW bug (not yet in AGENTS.md's catalog as of this pass):
   `securd.lpc`'s `get_status()` crashes on any object with no euid/uid
   assigned yet.** `get_status(mixed ob)` falls through both the
   `objectp`/`stringp` branches when `ob` is an object whose `geteuid()`
   AND `getuid()` are both null (common for a freshly-loaded/cloned object
   before anything ever calls `seteuid()` on it — e.g. any quest NPC clone
   at `create()` time, and even `master_ob` itself early in boot, since
   `master.lpc`'s own `create()` never calls `seteuid()`), leaving `euid`
   as the plain int `0`. The very next line, `member_array(euid,
   wiz_levels)`, then throws `*Bad argument 2 to member_array(): Expected:
   string or array Got: 0` — reproduced live during boot's own preload
   (every quest NPC created via `questd.lpc`'s `spread_quest()` calling
   `set_skill()`/`map_skill()`, which do a `file_size()` check that flows
   through `valid_read()` → `get_status()`) and would recur for any other
   not-yet-euid'd object performing a file operation. Fixed by returning
   `"(player)"` (the function's own existing final-fallback value, so a
   null/absent euid gets exactly the same "no elevated privilege" outcome
   the code already intended for a merely-unrecognized real euid string)
   whenever `euid` isn't a real string, before the `member_array()` call.
   This single fix also benefits `wiz_level()`/`get_wiz_level()` (the
   `adm/simul_efun/wizard.lpc` simul_efun, called pervasively including
   from `logind.lpc`'s own `wiz_level(arg) < wiz_lock_level` check), which
   route through the same `get_status()`.
10. **NEW bug: `clone/user/login.lpc`'s `receive_message()` missing a
    `!stringp(str)` guard.** Unlike the real player body's copy
    (`feature/message.lpc`/`feature/message1.lpc`, both correctly start
    with `if (!stringp(msg)) return;`), the pre-login connection object's
    `receive_message()` called `receive(str)` unconditionally. `write(0)`
    is a routine idiom throughout this lineage (`cmds/usr/uptime.lpc`'s
    `write(read_file("/log/nosave/LASTCRASH"))`, which legitimately
    returns `0` on a fresh install with no crash history yet) — that flows
    through `message.lpc`'s `write()` simul_efun → `message("write", 0,
    this_player())` → `login.lpc`'s `receive_message("write", 0)` →
    `receive(0)`, which this driver rejects with `*Bad argument 1 to
    receive(): Expected: string or buffer Got: 0`, silently killing
    **every single fresh connection** right at the very first banner
    (before the GB/Big5 prompt even fully renders) — this was the very
    first crash found, reproduced on the first interactive test attempt.
    Fixed by adding the same `if (!stringp(str)) return;` guard the real
    player body already has.
11. **AGENTS.md §15s (message() 4th-arg type rejection)** —
    `adm/simul_efun/message.lpc`'s `tell_room(ob, str, exclude)` (varargs,
    `exclude` defaults to int `0` when called with only 2 args — the
    overwhelmingly common call shape) passed that literal `0` straight
    through to the real `message()` efun's 4th ("exclude") parameter,
    declared `void | object | object *` — a literal `0` argument doesn't
    satisfy that union (only *omitting* the argument, or a real
    object/array, does), throwing `*Bad argument 4 to EFUN message():
    Expected: object, array, Got: int(0)`. Reproduced live: every `quit`
    triggers `clone/user/user.lpc`'s `user_dump()` →
    `tell_room()`, which hit this on the very first full successful
    registration run (the connection/save still completed fine, but the
    "player entered the room"-style broadcast silently failed and the
    error was logged). Fixed with `exclude || ({})`. Also hardened
    `shout(str)` the same way (`this_player()` can legitimately be `0`)
    even though no live call site was observed to actually hit it during
    testing — same shape, same shared root file, cheap insurance.
    Confirmed via `grep` that no other direct 4-arg `message()` call site
    anywhere in the ~26,000-file tree passes a bare possibly-falsy
    variable as the 4th arg (the only other 4-arg calls found are
    `message_vision`/`message_combatd`'s `({me, you})`, always a real
    array).

## Directory-named-like-a-file quirk (AGENTS.md's tooling edge case)

`convert_lib.sh`'s blind `.c`→`.lpc` rename hit a directory literally
named `u/hxsd/workrom.c/` (containing one file, `workroom.c`, itself never
renamed since the rename only recurses into files) — the classic
"orphaned duplicate-content directory" pattern already seen on
`xjcq2000` (archive #40). Confirmed nothing references
`workrom`/`workrom.c` anywhere else in the tree (`grep` came up empty
besides the directory's own contents), and a real `workroom.lpc` file
already exists as a sibling — renamed the directory to
`workrom.orphaned-dir` so it's never mistaken for a compilable object.

## Encoding

`convert_lib.sh`'s automated pass: 28,007 converted, 1,085 already-UTF8,
117 lossy (invalid bytes dropped via the `iconv -c` fallback — mostly
skill/NPC/room content files: `d/gaibang/mishi.c`, `d/gaochang/obj/{map,
wenbook01,fake_map}.c`, `d/gaochang/npc/obj/map.c`, `d/yanjing/biwu/mu.c`,
`u/yaodm/skill/{qingyi-jian.c,readme}`, `u/hxsd/tangmen/skill/
zhuihun-biao.c`, `u/hxsd/skill/{qingyi-jian.c,readme}`, `cmds/{imm/hpt.c,
usr/hp.c,arch/recover.c,adm/adup.c}` — 15 distinct lossy-conversion
warnings across the run), 480 skipped as genuinely binary.

**One additional GBK straggler found and fixed manually** (NOT caught by
`convert_lib.sh`'s text-extension allowlist, since `.o` is deliberately
excluded from the forced-text list per AGENTS.md's own documented
rationale — genuine binary `.o` files exist alongside plain-text
save-data `.o` files in this ecosystem): `adm/daemons/securd.o`
(`SECURITY_D`'s own save file) had one un-converted GBK run
(`\xb0\xb2\xc8\xab\xbe\xab\xc1\xe9`, decoding to "安全精灵") embedded in
its `channel_id` field — `file` classified the whole file as generic
"data" so the automated pass skipped it. This was NOT cosmetic: it
crashed `securd.lpc`'s own `create()` → `restore()` with
`*restore_object(): Invalid utf8 string while restoring dbase`
(non-fatal only because `master.lpc`'s `preload()` wraps the `call_other`
in `catch()` — but it meant `restore_list()` never ran, silently leaving
every ACL table empty/default instead of restored). Converted the file
directly with `iconv -f GB18030 -t UTF-8`; re-checked all 561 `.o` files
in the tree afterward (byte-by-byte UTF-8 validation) and confirmed this
was the only offender. Also re-ran the full straggler check across all
26,407 `.lpc`/`.h` files (per AGENTS.md's documented check) — zero hits,
confirming no other un-converted GBK text remains.

## Config

`config.fluffos` adapted from `bin/config.hy` (labeled "MudOS 0.9.20",
GBK→UTF-8 converted **before** any other edit, per AGENTS.md §5). Port
changed from the original `8888` to **40057**. `mudlib directory` points
at `/home/sunyc/src/mudlib/libs/haiyang2/work` (absolute path). `log
directory` set to `/log` (resolves relative to the driver's CWD per §6 —
`libs/haiyang2/log/`, sibling of `config.fluffos`, driver always launched
via `cd libs/haiyang2 && setsid nohup .../driver config.fluffos`). Tuning
knobs (eval cost, array/mapping/string size limits, etc) copied from the
established template used for the last many libs in this batch (matches
`xkx2001`'s config shape, same ES II lineage). `name : HY2` kept as-is
(matches the original; no code anywhere depends on the literal string
`"HY2"` except a `wizlist.lpc` display banner, checked via `grep`).

## What was checked and confirmed NOT needed

- **§4 (lazy security-daemon load recursion in valid_read/valid_write)**:
  `master.lpc`'s `valid_read`/`valid_write` only ever do
  `find_object(SECURITY_D)`, never `load_object()` — confirmed by reading
  the actual source before touching anything. Not applicable.
- **§7 (missing get_root_uid/get_bb_uid)**: both already present in
  `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID` — confirmed present,
  no stub needed.
- **§8c (this_player()-override footgun in valid_read/valid_write)**:
  `securd.lpc`'s `valid_read`/`valid_write` use the passed-in `user`
  argument directly, never call `this_player()` to override it — confirmed
  by reading the actual function bodies. Not applicable.
- **§15l (master.lpc destructing SIMUL_EFUN_OB in create())**: `master.lpc`'s
  `create()` is just `write(...)` — no `destruct()` call anywhere in it.
  Confirmed via direct read. Not applicable.
- **§15 (nitan-family shared-simul_efun-dbase architecture bug)**: this
  lib's `feature/dbase.lpc` already implements real local `set`/`query`/
  `delete`, and a `grep` for `efun::set(`/`efun::query(`/`efun::delete(`/
  `efun::addn(` across the entire ~26,000-file tree came up completely
  empty. Confirmed via source read + grep, not assumed from lineage alone.
- **§8h (convertd.lpc Greek-table backslash typo)**: `grep` for the
  `\"(,)?$`-shaped stray-backslash pattern in `adm/daemons/convertd.lpc`
  came up empty. Not present in this copy.
- **named.lpc-style deep PATH()/sliding-window macro**: this lib has no
  separate `named.lpc` at all (checked: `find -iname "named*"` came up
  empty) — the equivalent `check_legal_name`/`is_chinese` logic lives
  directly in `logind.lpc`/`chinese.lpc`, fixed there per §15h above.
- **`uid.h`/`priv.h`/`mimi.h`/`renwu.h`/bare `daemons.h`**: genuinely
  missing headers, but confirmed (via `grep -rl`) referenced ONLY by
  `adm/daemons/network/*` (an unused/never-preloaded network-daemon
  family — `te.c`, `pingd.c`, `pingtcp.c`, `telnetd.c`, `ms.c`,
  `mail_serv.c`, `userid.c`, `userid1.c`, none reachable from
  registration/boot) and by exactly 3 room/NPC files (`d/feihu/midong.lpc`,
  `d/gaochang/entrance.lpc` for `mimi.h`; `d/japan/npc/li.lpc` for
  `renwu.h`) whose headers genuinely don't exist anywhere in the archive
  (a real content gap per AGENTS.md §13, not a bug — not fabricated).

## Registration flow — verified end-to-end, twice, in two separate clean sessions

Read `logind.lpc`'s actual `input_to` callback chain before scripting the
test (not inferred from prompt text): `logon()` → `gb_big5` (GB/Big5
charset prompt — no hidden BIG5/age-gate/client-version question beyond
this one) → `get_id` (English id, 3-12 lowercase letters, several
reserved words banned) → `confirm_id` (y/n to create a new character;
**also a 60-second same-source-IP registration throttle**, shared
`static` variables across the whole driver process — confirmed by
reading the code, not hit blind) → `get_name` (real Chinese name,
`check_legal_name`) → `new_password`/`confirm_password` (6+ chars,
needs upper+lower+digit) → `select_gift`/`get_gift` (0-4 choice, then a
y/n to accept a randomly-rolled attribute spread) → `get_email` →
`get_gender` (m/f) → `init_new_player`/`enter_world`.

**Run 1** (before the `message()`/§15s fix was applied): id `qinfeng`,
real Chinese name **秦风** (accepted immediately, no rejection — confirms
the §15h fix works), password `Test123`/`Test123`, gift `0`→`y`, email
`test@test.com`, gender `m` — reached the actual starting room (金庸
NPC, exits to 8 zones), `look` worked, `quit` saved cleanly
("您的档案已经自动存盘"). `debug.log` showed exactly one runtime error
during this run: the §15s `message()` 4th-arg crash (see fix #11 above),
triggered by `quit`'s own `user_dump()`/`tell_room()` call — found here,
fixed, and reverified clean below.

**Run 2** (after ALL fixes, completely clean): id `qinling`, real Chinese
name **秦岭** (2 characters — also exercises the different length end of
the 2-5 character bound), password `Test123`/`Test123`, gift `0`→`y`,
email `test2@test.com`, gender `f` — reached the actual starting room,
"【江湖通告】：热烈欢迎新玩家 秦岭(qinling)来到HY2" broadcast rendered
correctly, `look` worked, `quit` saved cleanly. **`debug.log` for this
entire run: zero matches for `bad argument|denied|recursion|segmentation|
undefined function|cannot #include|couldn't find object|too deep|abort|
fatal`** (only the expected non-fatal `Unknown #pragma`/`Unused local
variable` compile warnings, streamed to the connecting client the first
time each never-preloaded file is lazily compiled — cosmetic noise, not
errors).

Save file confirmed correct: `data/login/q/qinling.o` contains
`"name":"秦岭"` as clean UTF-8, alongside a properly-hashed password and
all the other registration fields.

## lpcc sweep

Ran the full sweep (26,182 `.lpc` files is in the "tens of thousands"
range AGENTS.md §6b flags as a real OOM risk — comparable to `nitan6`'s
23,100 files — so it was run with active `free -h`/RSS monitoring
throughout rather than skipped outright). Peak `lpcc --batch` RSS
observed: **~5.8GB**, system available memory never dropped below
**~14.6GB** (out of 23GB total) at any point — well within safe margins,
no OOM risk materialized, unlike the `nitan170911`/`xo_final` precedents
that had to be killed early.

**Result: 26,183 objects tested, 25,242 PASS / 941 FAIL = 96.4% pass rate.**

Triaged the 941 failures by error-message category (AGENTS.md §6b/§8g
method) rather than treating each as an independent bug:

- **~40+ failures, ONE shared root cause (§8g)**: `d/mingjiao/npc/xkxnpc/`
  (5 NPC files: `zhuangzheng`, `yanyuan`, `wujincao`, `tangyang`,
  `wencangsong`) all `#include mingjiao_npc.lpc`, which doesn't exist
  anywhere in the archive — a genuine content gap (§13), not a typo (the
  cascading "Undefined function query" / "== always false because of
  incompatible types" errors in `mingjiao_job.h` are downstream fallout
  from the same missing include, not separate bugs). One zone's NPC
  content, not on the registration/boot path.
- **~21 files, `Illegal character 0xNN` (multi-byte UTF-8 fragments)**:
  cross-checked against the Encoding section above — these are exactly
  the files already flagged `LOSSY conversion (invalid bytes dropped)`
  during `convert_lib.sh`'s pass (`kungfu/skill/qingyi-jian.lpc`,
  `kungfu/skill/zhuihun-biao.lpc`/`diwangquan.lpc`/`qxxy-shou.lpc` and
  others) — pre-existing corrupted/truncated multi-byte sequences in the
  original archive's GBK bytes (confirmed via the same "LOSSY conversion"
  cross-reference technique documented in AGENTS.md's Encoding section),
  not a fresh bug from this pass. Decorative kung-fu skill-table content,
  not reachable from registration.
- **8 failures, `Bad type for argument 1 of is_killing (string vs
  object)`**: a handful of NPC files (`clone/demogorgon.lpc` (in 2
  locations on disk), `d/city/npc/guidao.lpc`, `d/xiangyang/npc/
  xiaosong.lpc`) call `is_killing(this_player())` (an object) where
  `is_killing()` is declared to take a `string` id — the mirror-image of
  the `is_killing()` type-mismatch bug documented for `nitan_ceshi`
  (archive #60), but affecting only decorative NPC combat-dialogue files
  here, **not** the player body class (confirmed: `grep` for `clone/user/
  user` in the failure log comes up empty — the actual body class
  compiles clean, matching the successful interactive test). Pre-existing
  content bug, not fixed (out of scope per the "breadth over depth"
  policy — these are scattered one-off NPC files, not a registration-path
  blocker).
- **~6 files, `Cannot #include uid.h`/`priv.h`/bare `daemons.h`**:
  confirmed (see "checked and confirmed NOT needed" above) referenced
  only by the unused `adm/daemons/network/` daemon family (never
  preloaded, never reachable).
- **~60 files, scattered `syntax error` / `Illegal LHS` / `Undefined
  variable` / etc, no shared root**: a long tail of pre-existing
  authoring typos spread across kung-fu skill files, quest files, and
  several wizards' personal sandbox directories (`u/yaodm/`, `u/hxsd/`,
  `u/lubinh/`, `u/tod/`) plus one zone's NPC cluster (`d/quanzhou/npc/
  tang{,1,2,3}.lpc`) — not chased individually given diminishing returns
  on a single archive among ~100; none appear anywhere in either clean
  interactive test transcript.

None of the failing files are on the master/simul_efun/preload/
registration/starting-room path exercised by the two successful
interactive tests above — consistent with this being real long-tail
content-gap/typo noise rather than anything blocking the lib's core
functionality.

## 2026-07-23 re-verification pass (driver rebuild + formatter + WASM)

- **LPC reformat**: ran `format-corpus.mjs` over all of `work/` (26,182
  `.lpc` files) — 25,931 written, 19 already-idempotent/unchanged, 232
  refused (self-checked token/byte-safety failures on messy legacy
  syntax, expected and not chased per the tool's own contract).
- **Native retest against the freshly-rebuilt driver** (`build-debug/src/
  driver` rebuilt from latest upstream master today): booted clean on
  port 40057, zero fatal preload errors. Full registration flow run with
  a fresh real Chinese name ("秦岭丁"/`qinlingding`) through the complete
  wizard (encoding select → id → confirm → Chinese name → password →
  gift stat roll → email → gender) all the way into the actual game
  world; `look`, `score`, and `quit` all produced correct output and the
  character saved cleanly on quit. **New (non-blocking) finding**: `quit`
  triggers a caught runtime error, `*Value being indexed is zero` in
  `/clone/topten/magic-rice.lpc`'s `simple_sort_skill()` (line 223,
  called via `savetopten()`'s `pks_topten`/`club_topten` entries) —
  root-caused to the shipped `data/topten.o` save file predating the
  `pks_topten`/`club_topten` fields added later in this leaderboard code
  (`grep` of `data/topten.o` confirms both keys are absent from the
  saved mapping, so `query("pks_topten")` returns `0` after `restore()`,
  overwriting the good in-source default array with a bare `0`, and
  indexing `0[i]` throws). This is a **pre-existing content/save-data
  bug**, unrelated to today's reformat or driver rebuild (same shipped
  `.o` file, same source logic, just never previously exercised by a
  `quit` at this exact leaderboard). It's non-fatal — caught by the
  driver's error handler, `quit`'s save-and-disconnect completes
  normally regardless — so left undocumented-as-fixed rather than
  patched, consistent with this project's "breadth over depth" policy
  for scattered non-blocking content bugs. No regressions from the
  reformat or the new driver binary itself.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly, same preload warnings as native (no fatal preload
  errors). Registration is blocked, but **not** by the documented
  `query_ip_number()` limitation — instead by a distinct WASM-harness
  gap: `wasm_client.js`'s `copyDir()` only `mkdir`s the top-level
  `work/log` directory when it decides to skip copying "runtime churn"
  contents, but never recreates the directory *structure* beneath it.
  This lib's `adm/daemons/logind.lpc` calls `set_visitor()` →
  `write_file("/log/mud/MUDVISITOR", ...)` unconditionally on every
  connection's very first successful GB/Big5 encoding selection (before
  the "英文名字" prompt); under WASM the `mud/` subdirectory was never
  created, so the write throws `Wrong permissions...No such file or
  directory`, which aborts `gb_big5()` mid-function — it never reaches
  `input_to("get_id", ob)`, so the connection is left with no input
  handler and every subsequent line (login id, etc.) is misinterpreted
  as an unrecognized command. Confirmed via direct source read, not
  guessed; confirmed **not** a mudlib bug — the identical `write_file()`
  call succeeds natively because `work/log/mud/` already exists on disk
  from prior test runs (both are gitignored runtime-churn paths per this
  repo's `.gitignore`, so a truly fresh checkout would need it created
  either way — the gap is that the harness's `mkdir` is not recursive
  into pre-existing subdirectories under `log/`). Not patched (out of
  scope — a shared test-harness limitation, not this mudlib's code);
  reported upstream to the orchestrating session as a general
  `wasm_client.js` gap likely affecting other libs that keep real data
  under a nested `work/log/<subdir>/` path.
- Test character (`qinlingding`) save files removed after testing;
  driver (native, PID 2126338) killed by exact PID; no scratch files
  left behind.

## WASM-enablement pass (2026-07: loopback-allow + throttle exemptions + admin seeding)

Standard pass per AGENTS.md §1.3b/e + §1.5. Gates found and patched
(loopback = `query_ip_number()` of `127.0.0.1`, any `127.*`, an empty
string, or a non-string/malformed non-dotted-quad value — the latter two
defend against WASM builds where the efun returns garbage):

- `adm/daemons/band.lpc:39` `is_banned()`: short-circuit `return 0` for
  loopback/empty/malformed site strings before the regexp ban-list scan.
- `adm/daemons/logind.lpc:153` new helper `is_loopback_conn()` (forward
  declared at :19); used to exempt loopback from:
  - `:331`/`:338` — per-IP concurrent-connection caps (iplimit > 50 /
    NATSERV > 80);
  - `:544` — "同一IP login 1人" one-login-attempt-per-IP-at-a-time gate;
  - `:573` — 60-second relogin-after-quit throttle;
  - `:580` — 10-second wrong-password retry throttle (same-IP branch);
  - `:704` — `confirm_id()`'s 60-second same-IP new-registration
    throttle (the one documented in the registration-flow section above).
- No `uptime()` startup-grace gate exists in this lib (checked; all
  `uptime()` uses are content timers/randomness — left alone).

Admin account: `fluffos` / `Mud@2026` / 浮浮, registered through the real
native flow (encoding `g` → id → y → name → password ×2 → gift 0/y →
email → gender m). Granted `(admin)` via `adm/daemons/securd.lpc:34`'s
hardcoded-door mechanism (same idiom as the author's own `hxsd` entry in
`restore_list()` — survives `securd.o` resets). Verified after restart:
login shows `目前权限：(admin)`, `update /cmds/wiz/update` recompiles
successfully. Save files (must be committed):
`work/data/user/f/fluffos.o`, `work/data/login/f/fluffos.o`.

Retest: fresh registration (秦风/ceshizhe) end-to-end + look/score/quit
clean; fluffos login + update clean; debug.log free of new errors; test
character saves removed; `data/topten.o` runtime churn reverted.

## Dual-mode verification pass (2026-07-24)

- **Native** (driver rebuilt from master, port 40057): fresh registration
  `ceshier`/秦风 end-to-end (encoding g → id → y → name → password ×2 →
  gift 0/y → email → gender m) into the starting room; look/score/quit
  all correct. `fluffos`/`Mud@2026` admin login shows `目前权限：(admin)`
  and `update /cmds/wiz/update` recompiles successfully. debug.log:
  compile warnings only, zero runtime errors. Driver killed by exact PID.
  (The login-time notice "有新文件update错误，立即查看 /log/log" is the
  lib's own wizard file-size-change monitor firing because /log/log is
  absent — cosmetic, pre-existing, not an error.)
- **WASM** (build-wasm with query_ip_number/resolve fixes + recursive
  log/ dir harness fix): the previously-documented harness gap is GONE.
  Fresh registration `wasmceshi`/秦风 end-to-end + look/score/quit all
  correct; second invocation: `fluffos` admin login `(admin)` + `update`
  succeeds. **Verdict: native OK + wasm OK.** No mudlib changes needed
  this pass. Test character saves removed; runtime churn
  (topten.o/fluffos.o timestamps) reverted.

## 深度功能测试 / Deep functional test (2026-07-24, AGENTS.md §10.7)

Full hands-on playthrough per the round-two methodology (this lib had
already been boot/registration-verified many times over per the sections
above, but never actually *played* through zones/training/reconnect
edge cases). One real character, `qixiazi` / 祁侠子 (3-character real
Chinese name, gift `0`/random, password `Test123`), taken through
registration → exploration → a safe-training mechanic → sect-recruiter
interaction → clean quit → unclean (net-dead) disconnect/reconnect ×2
→ clean quit + real wall-clock wait + reconnect. Also cross-checked
against the sibling lineage note: `hymud`'s own investigation (documented
in the orchestrating session, not in this repo) looked for a
command-dispatch bug reachable via `command_hook`/`add_action` and did
NOT find a reproducible one on that lib. This pass DID find one on
`haiyang2` — see the bug below. Both share the ES II
`feature/command.lpc`-style dispatcher; worth checking `hymud`'s own
`enable_player()` for the identical shape (see "Lineage" note at the
end).

**1. Newbie help**: read `doc/help/newbie` in full before touching the
client. Confirms: start room is 扬州客店 (or 武庙 after death), the
`fight`/较量 command is the intended safe-PvP-avoiding spar (stops at
50% qi/jing or on `halt`), and several sects (少林/武当/峨嵋/华山/桃花岛)
have their own 木人 (wooden dummy) for safe combat practice — the
general 武馆 (dojo, reachable directly from the welcome room's `wg`
exit, no sect commitment required) has the same mechanic via its own
木人桩 (`da muren zhuang`).

**2/3. Registration + continuous session**: native driver, port 40057,
`scripts/mudclient.py`, one `--send` verified at a time through the
wizard (encoding `gb` → English id → `y` confirm → real Chinese name
祁侠子 → password ×2 → gift `0`→accept → email → gender `m`) — matches
the documented flow above exactly, no desync. Landed in `/d/welcome/
welcome` (the actual `START_ROOM`); `look`/`score`/`i` all correct
immediately after registration and again after re-login. **Mid-pass
interruption, not a mudlib bug**: the driver process died to a bare
`SIGTERM` from the shared test environment ~2 minutes into the first
session (`FATAL ERROR: SIGTERM: Process terminated` in the driver's own
stdout, zero mudlib-side cause — consistent with AGENTS.md §10.5's
documented "stray SIGTERM" environment hazard, not §10.8's
driver-internal-corruption class). Restarted by exact PID/cwd
verification and continued on the same saved character without any data
loss (confirms the save-on-quit/relogin path is itself sound).

**4. Exploring the starting zone**: `wg` (welcome room's direct exit to
the general dojo) → `武馆大门` → `north` (大院) → `west` (长廊) →
`west` (西练武场). All room descriptions, exits, and NPC listings
rendered correctly at each step; read `d/wuguan/*.lpc` source to confirm
the path rather than guessing blind.

**5. Safe-sparring mechanism**: `西练武场` (`d/wuguan/wuchang1.lpc`) has
a 木人桩 (training dummy stake); `da muren zhuang` worked correctly —
"你站好马步，运气于拳，开始和木人桩对打起来。", consumed a small,
bounded amount of jing/qi (visible via before/after `score`), no risk of
death or PK. Used this instead of hunting a "weak enough" live NPC, per
the checklist.

**6. Skill/sect path**: a 星宿弟子 (Xingxiu-sect recruiter) NPC present
in the same training room responded correctly to both an informational
approach (`加入星宿...看 help xingxiu`) and a direct `bai xingxiu dizi`
attempt (correctly rejected: "既不属於任何门派，也没有开山立派，不能拜师"
— this recruiter is a flavor/pointer NPC, not itself a real sect master,
matching the code in `cmds/skill/bai.lpc`'s `mapp(ob->query("family"))`
gate). This is working as designed, not a bug — real sect masters live
in each sect's own remote zone, out of scope to reach given the time
budget for a single pass; **not verified live**: actually completing a
`bai` onto a real family-holding master and a full `xue` skill-learn
cycle. Documented here as an explicit gap rather than silently assumed
tested.

**7. Clean quit + debug.log**: `quit` printed the expected "正在退出游戏
,档案保存中......"; `debug.log` grepped immediately after (both the
raw tail and the standard `bad argument|denied|recursion|segmentation|
undefined function|cannot #include|couldn't find object|too deep|abort|
fatal` pattern) — zero matches beyond the expected first-compile
warnings for lazily-loaded files. Repeated after every subsequent
quit/reconnect cycle in this pass — always clean.

**8. Unclean (net-dead) disconnect, twice, two different code paths**:
- **First attempt** (fresh newbie, `combat_exp` == 0): abrupt socket
  close (no `quit` sent) while sitting in `西练武场`, reconnected ~3s
  later. Landed back in the welcome room, **not** the room where the
  disconnect happened. Root-caused via source read (`clone/user/
  user.lpc`'s `net_dead()`): for any player with `combat_exp < 100` the
  lib deliberately schedules `user_dump(DUMP_NET_DEAD)` after just
  **1 second** (`call_out("user_dump", 1, DUMP_NET_DEAD)`), instead of
  the normal `NET_DEAD_TIMEOUT` (900s) grace period used for everyone
  else — i.e. a genuine, immediate force-quit-and-save, not a stall or a
  void-park. Since `西练武场` never sets `valid_startroom`, the
  force-quit correctly left `startroom` unchanged (still the welcome
  room) rather than saving a bogus location — so this is **not** the
  §7.20 void-stranding shape (no void room, no permanently-corrupted
  save field, exits all present) — it's a real, working quit-and-save,
  just triggered unusually fast for brand-new characters. Flagged as an
  **observation, not fixed**: this looks like a deliberate design choice
  (an aggressive newbie-idle-connection reaper, maybe to keep player
  slots/objects from lingering for barely-started characters) rather
  than a missing-guard/typo shape; genuinely ambiguous whether it's
  intentional, so left untouched per the scope note.
- **Second attempt** (same character, `combat_exp` bumped to 5000 via
  the admin `call` command specifically to exercise the *normal*
  900-second-grace-period branch instead): killed the connection process
  abruptly again while in `长廊`, reconnected ~a few seconds later.
  `logind.lpc` correctly detected the still-live, still-`netdead`-flagged
  body via `find_body()`, called `user->reconnect()` (confirmed reachable
  — `grep -n "\->reconnect(" adm/daemons/logind.lpc` finds a real call
  site, unlike the §7.20 "zero hits" tell), printed "重新连线完毕。",
  and **the very next `look` showed `长廊` again** — the exact
  pre-disconnect room, not the welcome room and not a void. This is the
  correctly-implemented case and confirms the lib's `net_dead()`/
  `reconnect()` pair works as intended for any player past the first few
  minutes of play (the overwhelming majority of real sessions). No
  §7.20/§7.21-shaped bug present here.

**9. Clean quit + real wall-clock wait + reconnect**: quit cleanly with
`combat_exp` at 5000, waited a genuine ~90 real seconds, reconnected.
Landed in the welcome room (the correct, saved `startroom`); `score`
showed `实战经验：5000`, confirming persistence across a real gap, not
just an in-process resume. (Also incidentally resolved a red herring
from earlier in the pass: the very first post-registration re-login
showed "你上次光临海洋II是 Wed Dec 31 16:00:00 1969" — epoch 0 — for
the `last_on`/`last_from` fields; this was an artifact of that first
session's driver having died to the stray SIGTERM described above
*before* a real quit ever ran, not a mudlib bug — every subsequent
clean-quit-then-reconnect in this pass showed the correct real
timestamp.)

**10. Shop/combat/death**: **not verified live**, stated explicitly per
the checklist's own fallback clause. Reaching a real shop purchase or
death/respawn would have required either a lengthy walk to a priced shop
+ earning/being granted spendable coin, or deliberately losing a real
fight — both reasonable but out of this pass's time budget given the
NEW bug found and root-caused below. Left as an honest gap, not silently
presented as tested.

### Bug found and fixed: unguarded `add_action("command_hook", ...)` in `enable_player()` — matches AGENTS.md §7.28

`feature/command.lpc`'s `enable_player()` (the shared function that
registers the central command dispatcher, called once from
`inherit/char/char.lpc`'s `create()` on every login/registration) had no
idempotency guard around its `add_action("command_hook", "", 1)` call.
`grep -rn "enable_player()" --include='*.lpc' .` (excluding the
definition itself) finds **17 other call sites** across the tree that
legitimately re-invoke it mid-session on the SAME already-`living()`
player object — the two most universally reachable, ordinary-gameplay
ones being:
- `feature/damage.lpc:194` (`revive()`, called after a player is knocked
  unconscious in a real fight — i.e. any newbie losing a real, non-spar
  fight against an NPC, an extremely common event per the newbie guide's
  own "低水平玩家稍有不甚就会送命" warning), and
- `cmds/std/sleep.lpc:169`/`:196` (`wakeup()`/`wakeup2()`, called after
  ordinary `sleep` — available to ANY player in a `sleep_room`-flagged
  inn bedroom, not sect-gated; sleeping to regen is routine, repeatable
  play, not an edge case).

Each such re-invocation calls the bare, non-idempotent `add_action()`
again, stacking one more duplicate wildcard sentence for the identical
`command_hook` dispatcher on the same object — exactly the §7.28 shape
("Redundant `enable_player()`/`enable_commands()` calls stack duplicate
`add_action` sentences, silently re-running FAILED commands' side
effects"), previously found on `dtsl`. Confirmed **live**, not just by
code inspection, via the `commands()` efun (exposed by this lib's own
`query_commands()` wrapper) inspected through the admin `call` command
(`cmds/arch/call.lpc`):

- Baseline on a freshly-logged-in character: `query_commands()` shows
  exactly **one** `command_hook` sentence.
- `call qixiazi->enable_player()` invoked twice more (simulating what
  `revive()`/`wakeup()` do) → `query_commands()` now shows **three**
  `command_hook` sentences on the same object — direct, unambiguous
  proof of the stacking, independent of chasing a specific double-charge
  reproduction through the full apprentice/skill-purchase chain (the
  `cmds/skill/xue.lpc` learn-from-teacher command has the exact same
  "unconditional `printf()`-before-a-later-`notify_fail()`" shape as
  `dtsl`'s originally-reproduced case — see its `"你向%s请教了...疑问"`
  message printed before three later possible failure returns — but
  actually reproducing it live needs a real sect master relationship,
  out of this pass's time budget; the direct `commands()` proof above
  stands on its own).

**Fix** (the same pattern §7.28 already documents — a `mhxy`-style
`living()`-gated guard was deliberately NOT used, since this lib's own
`disable_player()` legitimately calls bare `enable_commands()` again
while already `living()`, which a `living()` guard would wrongly no-op):

```lpc
// feature/command.lpc, enable_player():
  delete_temp("disabled");
  enable_commands();
  remove_action("command_hook", "");   // added — guarantees exactly one
  add_action("command_hook", "", 1);   // sentence regardless of call count
```

**Verified live, post-fix, driver restarted from disk**: baseline
`query_commands()` → 1 `command_hook` entry; `enable_player()` invoked
**three** additional times via admin `call` → still exactly **1** entry.
Ordinary `look`/`score`/`i` dispatch confirmed still correct (single,
non-duplicated output) on a fresh login afterward. `git diff` confirms
`feature/command.lpc` is the only file touched by this pass.

**Lineage note**: `haiyang2`'s documented sibling `hymud` (per
AGENTS.md's ES II family list) very likely shares this exact
`feature/command.lpc`-shaped `enable_player()` — the orchestrating
session's own targeted `hymud` investigation (looking for a
command-dispatch bug from a different angle, a player-reported
"can't do commands after registering") did not find or fix this specific
shape. Worth a proactive grep (`enable_player()` call count +
`add_action("command_hook"` guard) on `hymud` and other ES II-lineage
siblings sharing this dispatcher file, out of scope for this pass.

**Files modified**: `libs/haiyang2/work/feature/command.lpc` (one-line
fix, see above).

**Process hygiene**: driver run natively on port 40057 throughout
(PID confirmed via `readlink -f /proc/<pid>/cwd` before every kill,
never a broad pkill); killed by exact PID at the end of the pass. Test
character `qixiazi` save files (`data/user/q/qixiazi.o`,
`data/login/q/qixiazi.o`) removed after testing; `data/topten.o` and
`data/user/f/fluffos.o` runtime-churn timestamps reverted via `git
checkout`. No instrumentation was left in place — the only diff against
HEAD is the one-line `remove_action()` fix above.
