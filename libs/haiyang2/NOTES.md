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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

此前被错误标记为某个不存在于本项目任何档案的原始压缩包文件名的 duplicate_of；这里的内容其实是完全独立、可游玩的游戏（有自己的 -N 变体编号、自己的端口、自己的 README）——duplicate_of 已清除。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 61 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-13，round two，新驱动重测）

Re-tested against the freshly-rebuilt `build-debug/src/driver`（post
全库 `quest_times`/`win_times` `%`-operator 修复 + Warning/warning
驱动文本回退）。这份档案是本轮"XKX/hy 家族" log_error() 扫荡里唯一
**已经提前修复过**的一个——`adm/single/master.lpc` 的 `log_error()`
早就有正确的 `strsrch(message, "arning:")` 判断（注释里引用了更早一
轮的 "AGENTS.md #15w"），管理员账号 `fluffos` 也早已用真实注册流程
创建并提交（`work/data/{login,user}/f/fluffos.o`，WASM-enablement 那
次提交）。本轮只发现一处新 bug：

### 发现并修复的 PROGRAMMING bug

1. **`log_file()`（`adm/simul_efun/file.lpc`）完全没有 `assure_file()`
   保护（AGENTS.md §7.11-class 的又一确认实例，与 `fqyy2`/`fy2mg`/
   `fys` 同一形状）**：全档案 `quest/shenshu/man.lpc` 等文件多处
   `log_file("nosave/ZS", ...)` 调用依赖 `LOG_DIR` 下的 `nosave/`
   子目录存在。这台开发机本地的 `work/log/nosave/` 目录当前确实存
   在（一个 `EXP` 文件，`Jul 24` 的旧测试痕迹），但 `work/log/` 整
   条路径被项目级 `.gitignore` 规则（`libs/*/work/**/log`）排除在
   外，本地存在不代表新检出安全——真正的一次全新 clone 仍会在首次
   触发这条路径时未捕获抛出。修复：补上
   `assure_file(LOG_DIR + file);`（含前向声明），使其与目录是否被
   提交无关，运行时自愈。

### Proactive checks（无需改动）

- `win_times` 修复确认存在且正确：`d/city2/npc/refereew.lpc:177`/
  `d/beijing/npc/refereew.lpc:177` 均已用
  `(string)(to_int(query("win_times")) % 5)`。
- 未发现 `message()` simul_efun 包装函数——不适用
  message()-missing-varargs 这一类 bug。
- `assure_file()` 本身末尾不做 `seteuid(getuid())` 重置，不属于
  euid-reset 那一类形状。

### 实测过程

以已提交的管理员账号 `fluffos`/`Mud@2026` 登录（连线后有一个
GB/Big5 选码提示，选 `g`），`score`/`update /adm/simul_efun/file`
（就是本轮改过的那个文件）确认可正常重新编译，屏幕上零次诊断刷
屏。`log/debug.log` 时间戳全程未变化，确认无新增未捕获运行期错
误。登录本身产生的存档时间戳类微小 diff（`data/user/f/fluffos.o`
的 `last_on` 字段）已用 `git checkout` 撤销，不提交。驱动最终按精确
PID kill，`ps -p` 确认已退出。

## Round three deep functional test (2026-08-18, AGENTS.md §10.7)

Went deeper than round two's zone-walk/net-dead pass: real board post/read,
a real weak-NPC kill (not just training-dummy sparring), shop `list`/`buy`,
and a targeted live stress-test of the death corridor for the newly
catalogued §7.112 pattern. Also checked the two other newly catalogued
2026-08-18 bug shapes (§7.111 `standard_trace()`, `logind.lpc`
`enter_world()` missing `->save()`) — neither applies here (details below).

### Proactive checks — not applicable

- **§7.111** (`file_name(error["object"])` unguarded in `standard_trace()`):
  the *live* master file (`master file : /adm/single/master` in
  `config.fluffos`) never calls `file_name(error["object"])` at all — its
  `standard_trace()` has that argument commented out entirely (dead/inert
  code, predates this pass). A stray `adm/obj/master.lpc` (already has the
  §7.111-shaped guard applied from some earlier pass) and an unused
  `adm/obj/masterold.lpc` (has the true unguarded shape) both exist on disk
  but are **not** the file the driver actually loads as master — dead
  duplicates, confirmed via `config.fluffos` and `grep -rl masterold`
  finding zero real references. Nothing to fix.
- **`logind.lpc` `enter_world()` missing `->save()`**: present and not
  commented out — `user->save(); ob->save();` right after `user->setup()`
  (around line 1256). Not applicable.

### Bug found and fixed: §7.112 — unguarded staged `init()` → `call_out()`
chains, duplicated by a reconnect's `enable_commands()` re-broadcast

Same pattern as the freshly catalogued §7.112 class. Grepped the whole tree
for `call_out` inside files defining `init()`, narrowed with a `*_stage`
naming heuristic, and manually inspected every hit outside `d/death/npc/`
(the directory the task briefing specifically flagged). Found the exact
unguarded shape — `init()` unconditionally calling
`call_out("death_stage"/"..._stage", N, previous_object(), ...)` with no
per-target idempotency flag — in **13 files**, all fixed the same way
(`jym`/`xuanjianlu` `wgargoyle.lpc` reference shape: a `set_temp`/
`query_temp`/`delete_temp("death_stage_active")` guard around the
scheduling call in `init()`, cleared at every exit point of the
callback):

1. **`d/death/npc/{wgargoyle,bgargoyle,mengpo,panguan,panguan2,pusa}.lpc`**
   (6 files) — the actual post-death ghost-realm corridor
   (`d/death/{gate,gateway,naihe2,yanluo,mengpo,dizang}.lpc`, walked by
   every player who dies), each NPC's `init()` scheduling its own
   multi-stage `death_stage` dialogue/reincarnation chain with zero guard.
   A player who reconnects (or has `enable_commands()` invoked on them by
   any other path) while standing in one of these rooms would get a
   second, fully-independent `death_stage` chain stacked on top of the
   first — duplicate dialogue, and for `wgargoyle`/`bgargoyle`/`pusa`,
   double execution of `reincarnate()`/inventory-drop/`move()`/`save()`
   side effects.
2. **`d/shaolin/npc/yu-zu2.lpc`** — identical shape, a 少林 "jailer" NPC
   running its own 5-stage `death_stage` chain (its own `reincarnate()`
   call is already commented out from an earlier edit, but the
   `tell_object`/`move()` side effects still duplicate without the guard).
3. **`d/bwdh/{sjsz,sjsz2,sjsz3}/{east,west}_xiangfang.lpc`** (6 files) —
   NOT an NPC; these are the 比武场 (PK-arena) staging **rooms** for the
   门派论剑 (sect tournament) event. Unlike the death-corridor NPCs, this
   `init()` has **no** `wizardp()` exclusion at all, so literally anyone
   (player or wizard) entering the room schedules a 90-second
   `death_stage` (misleadingly named — it's actually the
   team-assignment/bodyguard-spawn callback, nothing to do with dying)
   that assigns a team, teleports the player into the arena, and can spawn
   an extra `weishi` (guard) NPC. A reconnect while waiting in this room
   would duplicate all of that — most consequentially, an extra `weishi`
   spawned per stray reconnect, silently inflating one team's guard count
   in a competitive event.

**Live verification** (fresh driver rebuild, both scenarios): used the
committed admin account (`fluffos`) plus a fresh test character
(`qintongshan`) in two separate sockets, teleported the test character
into `/d/death/gate` (via `summon`) and separately into
`/d/bwdh/sjsz/west_xiangfang`, and used the `callouts death_stage` wizard
command (`cmds/arch/callouts.lpc`) as ground truth for exactly how many
`death_stage` call_outs are live system-wide:

- **Death corridor**: after the real `init()` broadcast from `summon`,
  `callouts death_stage` showed exactly **1** entry
  (`/d/death/npc/wgargoyle#... death_stage`) and
  `qintongshan->query_temp("death_stage_active")` was `1`. Called
  `qintongshan->enable_commands()` three times via admin `call` (the exact
  driver-level effect a real reconnect has) — `callouts death_stage`
  still showed exactly **1** entry throughout (delay ticking down
  naturally, not reset), confirming no duplicate stacking. Let the chain
  run to completion: `callouts death_stage` went to **0** entries and
  `query_temp("death_stage_active")` correctly dropped back to `0` —
  the guard clears itself on both the abort and completion paths, not
  just blocking re-entry.
- **PK-arena room**: teleported admin into `west_xiangfang` (which,
  correctly, also scheduled admin's own `death_stage` entry — this room
  has no wizard exclusion by design) then `summon`ed `qintongshan` in —
  `callouts death_stage` showed **2** entries (one per distinct
  `previous_object()`, i.e. admin and the player each get their own,
  which is correct — the guard is per-target, not global). Three more
  `enable_commands()` calls on `qintongshan` left the count at exactly
  **2** throughout, confirming the fix works for the room-init shape too.
- `debug.log` never came into existence during any of this (fresh driver,
  full registration + death-corridor stress test + board/shop/combat
  testing below, all in one session) — zero runtime errors of any kind.

**Files modified**: the 13 files listed above (one-line `init()` guard +
one-line clear at each `death_stage`/`..._stage` exit point, same shape
throughout). `git diff --stat` confirms no other lines changed in any of
them — the `_xiangfang.lpc` files originally have mixed CRLF/LF line
endings, so those six were fixed with a binary-mode (`rb`/`wb`) Python
literal-byte replacement rather than the text-mode Edit tool, after the
first Edit-tool attempt was caught silently normalizing the whole file's
line endings to LF (reverted via `git checkout` and redone).

**Lineage note**: worth a proactive `call_out.*_stage` + missing-guard grep
on other libs sharing this "ES II" / `bwdh` 门派论剑 content family —
out of scope for this pass (single-lib rule), flagging per the task
briefing's "recurring pattern, don't fix elsewhere yourself" instruction.

### Other round-three coverage (all clean, no new findings)

- **Board post/read**: `客店留言板` (`clone/board/kedian_b.lpc`,
  `inherit BULLETIN_BOARD`) at 客店 (kedian). `post <title>` → editor
  prompt → message body → `.` → "留言完毕。", confirmed successful; `read`
  with no argument correctly prompts "您要读哪一封信？" instead of
  crashing. No errors.
- **Real combat + kill** (not just the training-dummy spar rounds one/two
  already covered): fought and killed `小混混` (`d/city/npc/hunhun.lpc`,
  `combat_exp` 200, 十里长街/nandajie1) with the default starting
  character build — full multi-round fight resolved correctly, `杀死人数`
  incremented from 零 to 一 on `score`, no errors.
- **Shop mechanics**: `药铺` (`d/city/npc/huoji.lpc`, `inherit F_DEALER`)
  — `list` correctly prices and lists all `vendor_goods`; `buy <id>`
  correctly rejects an unmatched Chinese display-name argument
  (`is_vendor_good()` matches against the goods object's `id()` keyword
  list, not its Chinese short name — expected/correct dealer behavior,
  not a bug, confirmed by reading `feature/dealer.lpc`).
- **Death/reincarnation full-cycle completion**: covered above as part of
  the §7.112 verification — the `wgargoyle` chain was allowed to run to
  natural completion (not just stress-tested for duplication), ending
  with the player correctly reincarnated and the guard flag cleared.
- Sect-joining (`bai`) not re-attempted this round — round two already
  confirmed the design-gate behavior (flavor recruiter NPC correctly
  rejects, real sect masters are out-of-reach without a lengthy walk);
  nothing new to add without an unreasonable time investment for a single
  data point already established as "working as designed."

### Process hygiene

Native driver, port 40057, rebuilt/restarted once after the §7.112 fixes
to confirm clean compilation and re-verify live. Both sessions' PIDs
(58051, then 61890) confirmed via `readlink -f /proc/<pid>/cwd` matching
this lib's `work/` before every kill; killed by exact PID each time.
Runtime-churn saves from testing (`data/board/kedian_b.o`,
`data/npc/menpai.o`/`menpai1.o` — an unrelated periodic sect-of-the-day
daemon effect, not caused by this pass — `data/topten.o`,
`data/user/f/fluffos.o`) reverted via `git checkout`; test character
`qintongshan`'s save files removed (not committed). `boot.log` scratch
file removed. `git status --short` confirmed clean except the 13
intentional source fixes before committing.

## §7.100 跨库扫描修复（ROOM 冗余 replace_program() 关闭包炸弹，2026-08-19）

同一形状覆盖到几乎所有房间基类（机制详见 AGENTS.md §7.100）。本库属
于该扫描已知最大规模的 10 个库之一。二进制模式脚本机械删除了 8340
个文件里 8341 处独立、未注释的 replace_program(ROOM); 整行（其中一
个文件 d/huangshan/banshan.lpc 里同一 create() 有两处独立冗余调用，
分别在 setup() 前后各一处，均属同一 bug 形状，一并删除）。另外手工
清理了造房工具 clone/misc/roommaker.lpc/adm/roommaker.lpc 代码生成
模板里内嵌的同一形状（4 处，含一处 heredoc、三处字符串拼接）。删除
总计 8345 行，与本次扫描 FINDINGS.md 记录的 haiyang2 存活命中数完全
一致，git diff --stat 与脚本自报数字吻合。

验证：干净启动一次真实调试驱动，端口 40057 正常监听，
work/log/debug.log 全程无新增内容。用已播种的 fluffos/Mud@2026 管理
员账号连线，在欢迎村新手教学区往返走了十余个房间
（newbie1/newbie2/newbie4），look/who 均正常。未产生需要撤销的存档
改动。驱动按精确 PID kill。

## Round four deep functional test (2026-08-20, AGENTS.md §10.7)

Targeted pass closing the three gaps round three's own NOTES explicitly
left open (sect apprenticeship + skill learning, shop purchase, combat
death/respawn), plus a fast standard-checklist sanity re-confirm. Native
driver, port 40057, PID 850332 (confirmed via `readlink -f
/proc/850332/cwd` before every action and before the final kill), driven
via two persistent raw-socket Python sessions (a FIFO-fed telnet client
written for this pass, `/tmp/.../mudsession.py`, since `mudclient.py`'s
one-shot `--send` list doesn't support inspecting a response before
deciding the next command) — one for the committed admin account
(`fluffos`/`Mud@2026`), one for a fresh test character (`qinwudang`/秦武当).

### 1. Real sect apprenticeship + skill learning — RESOLVED, fully completed live

Traced `cmds/skill/bai.lpc`'s real gate (`mapp(ob->query("family"))`) back
to `feature/apprentice.lpc`'s `create_family()`, then grepped for
generation-1 (`create_family(".*", 1, ...)`) callers to find genuine
grandmaster NPCs rather than guessing. Picked `kungfu/class/wudang/
zhang.lpc` (张三丰/Zhang Sanfeng, 武当派 generation-1 grandmaster,
`combat_exp` 9,000,000) — placed in `/d/wudang/xiaoyuan.lpc` ("后山小
院"), reachable in-fiction via `/d/xiangyang/caodi6.lpc`'s `south` exit
(`/d/wudang/wdroad5`) from the 襄阳 (xy) hub off the welcome room, several
rooms deep. Used admin `goto`/`summon` to reach it directly (the
established precedent from round three's death-corridor test) rather than
spending the session's budget on the walk itself, since the goal was to
exercise the real `bai`/`xue` mechanics at a genuine family-holding
master, not re-prove pathfinding.

`zhang.lpc`'s own `attempt_apprentice()` gates recruitment behind real
stat thresholds (`guarded>=5`, `taiji-shengong>=60`, `taoism>=80`,
`shen>=2000`, `int>=30` — a deliberately steep, legitimate late-game
questline, not a bug) — used admin `call qinwudang->set(...)`/`set_skill(...)`
to satisfy them directly (same "reach real content without an unreasonable
grind" precedent as round three's `combat_exp` bump). First `bai zhang`
attempt (before the stats were set) correctly failed with the loyalty
message and left `pending/apprentice` set; a bare retry after setting
stats was **silently absorbed by `bai.lpc`'s own "still pending, ask
again later" short-circuit** (`if (ob == old_app) return notify_fail(...)`
— it does NOT re-invoke `attempt_apprentice()` on a repeat call) — this is
correct, intentional command semantics (you must `bai cancel` first to
retry), not a bug; re-tested with `bai cancel` → `bai zhang` and got a
full, real recruitment: "张三丰决定收你为弟子。...恭喜您成为武当派的第
二代弟子。" (real `family` mapping populated, generation 2, confirmed via
`score`).

Followed with a full `xue` cycle: `xue zhang force 1` was first rejected
by `inherit/char/master.lpc`'s `prevent_learn()` (`shen > 0 && me->query("shen")
< shen` — Zhang's own `shen` is 200000, a legitimately steep "your moral
standing isn't high enough yet" master-teaching gate, not a bug) —
bumped `shen` to 250000 via admin `call` (same rationale as above) and
retried: **"你向张三丰请教了一句有关「基本内功」的疑问。你听了张三丰的
指导，似乎有些心得。你的「基本内功」进步了！"** — real skill acquisition,
confirmed via `query_skill("force", 1)` going from `0` to `1`. Zero
`debug.log` errors throughout either the `bai` or `xue` sequence.

**Real bug found and fixed during this investigation — 3rd confirmed
instance of AGENTS.md §7.30** (mapping-typed accessor returning its raw
never-initialized `int 0` instead of an empty mapping): `feature/
skill.lpc`'s `query_skills()`/`query_learned()`/`query_skill_map()`/
`query_skill_prepare()`/`query_wprepare()` all had the exact bare-`return
<instance var>;` shape previously confirmed crashing on `xiakexing2017`
and `jqxz2015` (same lineage family). Grepped every call site of
`query_skills()` (164 files) across the whole tree for unguarded
`keys(...)`/`sizeof(...)`/direct-index usage and found real,
live-reachable unguarded crashes:
- `kungfu/skill/bingxue-xinfa.lpc:12` — `sname = keys(skl);` with zero
  guard, unconditionally executed at the very top of `valid_learn()` —
  **any player with zero skills learned so far attempting to learn this
  skill would crash immediately** with `Bad argument 1 to keys() Expected:
  mapping Got: 0`, directly in the `xue` skill-learn path this very task
  item exercises.
- `kungfu/class/mingjiao/yangxiao.lpc:123`, `kungfu/class/shaolin/
  qing-le.lpc:88` and `:116` — three sect-reward-command functions
  (明教 tie-token / 少林 达摩令·手谕), unguarded `keys(skl)` on a
  freshly-recruited sect member's own `query_skills()`.
- `kungfu/condition/lyjob.lpc:47-48` — a different but related shape:
  `learned = me->query_learned(); if (undefinedp(learned["buddhism"]))
  learned["buddhism"] = 0;` indexes the raw `query_learned()` return
  directly with no guard — crashes for any never-trained player reciting
  scripture (诵经) at 灵隐寺 (a generically reachable training spot, not
  sect-gated).
- `cmds/wiz/wizlian.lpc:177` — unguarded `keys(me->query_skills())` in a
  wizard "reset to origin" admin command; lower severity (wizard-only)
  but a real crash risk on a target with zero skills.
(`d/zangbei/npc/xiaodie.lpc`, `d/zangbei/star_room3.lpc`'s own
`keys(...)` call sites were already correctly truthiness-guarded —
confirmed clean, not fixed.)

**Fix**: applied the documented §7.30 remedy at the accessor level rather
than patching every call site — `return mapp(x) ? x : ([]);` for all five
`feature/skill.lpc` mapping accessors (`skills`, `learned`, `skill_map`,
`skill_prepare`, `wprepare`). This closes all found and any not-yet-found
call sites at once (confirmed via `grep`: 164 files call `query_skills()`
alone), including the `lyjob.lpc` indexing case (an always-real mapping
now safely returns `0` for an absent key instead of crashing on the index
itself). Verified live: the `bai`/`xue` cycle above was run *after* this
fix was applied, so the real skill-learning path was exercised
post-fix with zero errors. `git diff` confirms only `libs/haiyang2/work/
feature/skill.lpc` changed (5 one-line accessor bodies).

### 2. Shop purchase — RESOLVED, fully completed live

`药铺` (`d/city/npc/huoji.lpc`, room `d/city/yaopu.lpc`) — same shop
round three used for `list`. Granted spendable coin via the sanctioned
admin `clone`+`give` pattern for this lib's actual coin objects
(`/clone/money/gold`, `set_amount()`, `give <item> to <target>` — note
`give.lpc`'s own arg-parsing quirk: `give <target> <item>` mis-parses as
`target=<item> item=<target>` for the no-"to" form, so `give X to Y` is
the reliable syntax). `buy dust` (化尸粉, the cheapest listed item at 70
base copper) succeeded: **"你从药铺伙计那里买下了一颗化尸粉。你的「讨价
还价」进步了！"** — item received (confirmed via `i`), price correctly
deducted with correct change-making across all three coin denominations
(50000 base units in, item cost 70, result 4 gold + 99 silver + 30 copper
= 49930, exact). Zero `debug.log` errors.

### 3. Combat leading to death/respawn — RESOLVED, fully completed live, real organic death

Per this session's cross-lib precedent, checked `kill.lpc` directly rather
than assuming a spar-gate applies — confirmed no such gate exists for
real NPC targets. First `kill zhang` (against the same Zhang Sanfeng, a
massively overtuned combat_exp-9,000,000 opponent, guaranteeing a fast
loss) hit `feature/damage.lpc`'s **"新手不死" (newbies don't die)**
mechanic: any `userp()` character with `combat_exp < 2,500,000` (and not
already flagged a killer/high-PK/`zhuanshen`) who would die is instead
rescued with a "白光" (white light) message, healed, and moved to `/d/
pingan/guangchang` — a deliberate, clearly-commented, intentional design
gate (same category as this lib's already-documented aggressive netdead
newbie reaper), **not** a bug, left alone. Bumped `combat_exp` to
3,000,000 via admin `call` (same "clear a design gate to reach the real
mechanic" rationale used throughout this pass) and retried: real death
this time — **"你「啪」地一声倒在地上，嘴角溢出几丝鲜血，痛苦的挣扎了几
下就死了。"** — moved to `/d/death/gate`'s "鬼门关" (Ghost Gate) death
corridor with 白无常 (`d/death/npc/wgargoyle.lpc`, one of the 13 files
fixed for §7.112 in round three) present.

Let the full `death_stage` dialogue chain run to natural completion
(5 stages, ~5s apart) rather than short-circuiting it — this is the
**first genuinely organic real-combat death** this lib has seen tested
(round three's §7.112 verification used admin `summon` directly into the
death corridor, not a real `kill`-triggered death), giving the strongest
possible confirmation of that fix: reincarnation completed correctly,
character landed in `/d/city/wumiao` ("武庙", matching the lib's own
documented death-respawn room), and `callouts death_stage` plus
`qinwudang->query_temp("death_stage_active")` both confirmed **0**
afterward — the guard cleared itself with zero stacking, fully organically
triggered. `score` post-respawn showed consistent, correctly-updated
state (离奇死亡: 一, 上次死因: 被zhang sanfeng杀死, `combat_exp` reduced
from 3,000,000 to 2,970,075 as an expected death penalty). Zero
`debug.log` errors across the entire combat → death → reincarnation
sequence. (The doubled "你有武功为零级了，请重新enable 所有的武功，特别
是force！" notice from `feature/skill.lpc`'s post-death skill-reset
handling printed twice, from two separate call sites — cosmetic UI
messaging, no error signature, not chased per scope.)

### Standard checklist re-confirm (all clean, no new findings)

- **§7.90** (`config.fluffos` eval cost): `maximum evaluation cost :
  30000000` — already well above the documented `5000000` remedy floor.
  Not applicable.
- **§7.100** (live `replace_program(ROOM);`): 385 raw-text hits across the
  tree, but every single one is either a non-`.lpc` dead/backup file
  (`.C`/`.bak`/`.old`/`.txt`/`.java`/`.vns`/`.jas`, a stray `log/edit`
  entry) or, within real `.lpc` files (256 hits), already commented out
  (`//`) — confirmed via a targeted follow-up grep excluding `//`-prefixed
  lines, zero live matches. Already fully closed by the 2026-08-19
  cross-lib sweep documented above.
- **§7.111** (`file_name(error["object"])` unguarded in the real master's
  `standard_trace()`): re-confirmed still not applicable, matching round
  three's own finding — the live master (`/adm/single/master`) never
  calls that pattern at all.
- **§7.112** (`death_stage()` reentrancy): manually re-read all 7 death-
  corridor/shaolin NPC files' full `death_stage()` bodies (not just
  grepped for the guard string) confirming every exit branch clears
  `death_stage_active`, and all 6 `bwdh/*_xiangfang.lpc` PK-arena room
  files clear the guard unconditionally at the top of the function before
  any branching — all 13 originally-fixed files verified structurally
  sound, then re-confirmed live end-to-end via the real combat death above
  (see item 3).
- **§7.79** (bare 2-arg `addn()`/`addn_temp()`): zero hits anywhere in the
  tree.
- **§7.108** (`reconnect()` calling `enable_commands()`): re-confirmed
  present — `clone/user/user.lpc`'s `reconnect()` still calls
  `enable_commands()` first thing, matching round three's finding.
- **§7.30** (uninitialized-mapping accessor crashing `keys()`): found and
  fixed a real, 3rd-corpus-wide-confirmed instance — see item 1 above.

### Process hygiene

Driver PID 850332 (`readlink -f /proc/850332/cwd` confirmed matching this
lib's `work/` both before every `call`/teleport action and immediately
before the final kill). Both test sessions quit cleanly (`quit` from
`qinwudang`, `quit` from `fluffos`) before the driver was killed. Runtime
churn from testing (`data/login/f/fluffos.o`, `data/user/f/fluffos.o`,
`data/npc/menpai.o`/`menpai1.o` — the same unrelated periodic sect-of-
the-day daemon effect round three noted) reverted via `git checkout`;
test character `qinwudang`'s save files (`data/login/q/qinwudang.o`,
`data/user/q/qinwudang.o`) deleted, not committed. `git status --short`
confirmed clean except the one intentional `feature/skill.lpc` fix before
committing.

## Round five deep functional test (2026-08-27, AGENTS.md §10.7, new driver + 13-pattern sweep)

Follow-up pass on the freshly-rebuilt driver, focused on the 13 newly
catalogued cross-cutting bug shapes (§7.121/§8.3a/§7.122/§7.123/§7.124/
§7.126/§7.129/§7.130/§7.131/§7.132/§7.133/§7.134/§7.135) plus one more
full continuous playthrough (registration → exploration → safe-spar →
sect-recruiter gate → real combat → quit/debug.log/reconnect-after-real-
gap). Rounds two/three/four (above) already delivered full live coverage
of sect apprenticeship+`xue`, shop purchase, and a complete organic
combat-death-reincarnation cycle, so this round did not repeat those in
full — it re-confirmed general soundness post-fix and went deep only on
the newly catalogued patterns.

### Bug found and fixed: 4th confirmed instance of AGENTS.md's uninitialized-mapping-accessor class (this lib's own §7.30 sibling shape, but on `F_DBASE` itself), matches §7.135's "one accessor missing the sibling guard" fingerprint

`feature/dbase.lpc` is this lib's core per-object property store (`set()`/
`query()`/`delete()`/`add()` on a `mapping dbase;` with no initializer).
Every real accessor/mutator consistently guards the uninitialized case —
`set()` does `if (!mapp(dbase)) dbase = ([]);`, `query()`/`delete()` do
`if (!mapp(dbase)) return 0;` — **except `query_entire_dbase()`, which
did a bare `return dbase;`** with no guard at all (and the parallel
`tmp_dbase`/`query_entire_temp_dbase()` pair had the identical gap).
`query_entire_dbase()` is used at 90+ call sites project-wide, including
the core combat daemon (`adm/daemons/combatd.lpc`), `score`/`hp`
commands, and `inherit/char/char.lpc`'s own `heart_beat()` — any of which
indexing the bare `0` this would return (e.g. `my["eff_qi"]`) would throw
a hard "indexing a value that is not an array/mapping" error.

**Practically unreachable in this specific lib**, confirmed by reading
every real call path: `dbase` gets lazily created by the very first
`set()` call, and every object that ever reaches `query_entire_dbase()`
(a real player mid-registration, or an NPC inside `CHAR_D->setup_char()`)
has already had at least one `set()` run on it first (registration writes
stats immediately; `setup_char()` calls the race-specific `setup_human()`/
`setup_beast()`/`setup_monster()`, which itself calls `set()`, before ever
querying `query_entire_dbase()`). No live crash was reproduced or
expected under ordinary play. Fixed anyway, following this session's own
established §7.30 remedy and the explicit "worth checking for a bare,
uninitialized declaration" guidance under §7.134/§7.135 in AGENTS.md,
since it costs nothing and closes the class for any future caller that
doesn't share this lib's own "always `set()` before `query_entire_dbase()`"
invariant:

```lpc
// feature/dbase.lpc
mapping query_entire_dbase() {
  return mapp(dbase) ? dbase : ([]);
}
mapping query_entire_temp_dbase() {
  return mapp(tmp_dbase) ? tmp_dbase : ([]);
}
```

Verified: driver rebuilds clean, and the live playthrough below (which
exercises `score`/`hp`/combat, all real `query_entire_dbase()` callers)
ran with zero `debug.log` errors after the fix.

### Empirical finding: §7.121/§7.124-shaped "declared `int`, computed via float arithmetic, no `to_int()`" is NOT a live bug on this codebase+driver combination — verified by direct test, not assumed

This lib's ES-lineage skill/level-curve code has a widespread recurring
idiom, `level = ceil(pow(exper * 10.0, 0.333333));` into a declared-`int`
local (12+ files: `quest/menpaijob/baituo/qiandan.lpc`,
`d/wudang/sanqingdian.lpc`, `d/feitian/shulin{,1,2,3,4}.lpc`,
`d/shaolin/wuchang.lpc`, `cmds/usr/hp.lpc`/`cmds/imm/hpt.lpc`,
`adm/daemons/chard.lpc`, etc.) and two skill files
(`kungfu/skill/fengyun-shou/foguang.lpc`,
`kungfu/skill/taiji-quan/zhenup.lpc`) that do `int damage; ...; damage *=
at;` where `at` is a `float` ratio — the exact shape flagged by §7.121/
§7.124 on other libs (`nightmare4`, `ninetears`, `dsIII`). Rather than
pattern-match and "fix" ~14 files by inspection, this was verified
directly against the live driver: a throwaway test file
(`/tmp_test_random.lpc`, compiled via `update`, exercised via the admin
`call` command, deleted before committing) confirmed that **on this
project's current FluffOS build, assigning/returning a float value
through a declared-`int` local, global, function-return, or compound
`*=` target is silently truncated to a real integer at the point of
assignment/return** — e.g. `int test3() { float x = 100.0/3.0; return
x; }` returned `33` (not a float, not `33.333333`), and `int damage=100;
damage *= 3.5;` produced `300` (i.e. the float operand itself gets
truncated toward int before the multiply — `100*(int)3.5`), and a
`random(damage/2)` call immediately downstream of that same contaminated
`damage` did **not** crash. Live `hp`/`score` output on a real freshly
registered character also showed clean integer values (`潜能...上限
[50000]`, no stray `.000000`). This is a materially different result
from the (int)-cast-is-compile-time-only reference note and from the
other libs' confirmed §7.121/§7.124 instances — most likely because
those bugs involved a **field assigned a float literal directly with no
arithmetic** (a compile-time-foldable constant) combined with a
declared-`float` setter/getter pair that re-widened the value after the
fact, a combination not present anywhere in `haiyang2`. **Conclusion:
checked thoroughly, not applicable here** — left untouched. Worth
re-verifying with the same direct-eval technique (not just code reading)
before "fixing" this idiom on any ES-family sibling, since the fix would
be a no-op change on a driver where this already doesn't crash.

### §7.122 (autoload/class-marker duplication on reconnect) — checked, structurally NOT vulnerable, and confirmed live

`feature/autoload.lpc` is this lib's own version of the TMI-2-style
"reconstruct untracked-but-persistent items on login" mechanism (also
used by real money objects — `inherit/item/money.lpc` defines
`query_autoload()` too, so a duplication bug here would double actual
currency, not just class-marker trinkets). Unlike the confirmed-buggy
`mortremains`/`tmi2`/`es1` shape, `restore_autoload()` here **does**
self-guard: `if (!pointerp(autoload)) return;` at the top, and
`clean_up_autoload()` (called at the end of every `restore_autoload()`)
sets `autoload = 0`, so a second call before a fresh `save_autoload()`
repopulates it is a guaranteed no-op. Traced every real call site of
`setup()`/`restore_autoload()`: `clone/user/user.lpc`'s `reconnect()`
(the net-dead-recovery path) never calls `setup()` at all — confirmed by
reading it directly, matching round two/three's own independent finding
that a real reconnect lands the player back in their pre-disconnect room
with zero re-initialization. `adm/daemons/logind.lpc`'s own
`reconnect()` likewise only calls `user->reconnect()`, never
`user->setup()`. The only other `setup()` call site touching a live
player body is `cmds/usr/quit.lpc`'s "return from a possessed body"
branch (`link_ob->is_character()`), an unrelated niche mechanic, not the
ordinary reconnect path.

**Verified live** with the admin account (`fluffos`): cloned one
`/clone/family/jade` marker item and one `/clone/money/gold` (both
`query_autoload()`-tracked) into inventory, then (1) a real `quit` +
fresh relogin — inventory showed exactly 1 jade + 1 gold, not 2; (2) an
abrupt disconnect (killed the raw socket process, no `quit` sent) +
reconnect — `fluffos`'s own low `combat_exp` triggered the fast
1-second `user_dump(DUMP_NET_DEAD)` force-quit-and-save path (same
mechanic round two documented), landing on a genuinely fresh
`restore()`+`setup()` cycle on relogin — inventory again showed exactly
1 jade + 1 gold. No duplication in either case. **Not applicable** —
this lib's self-clearing guard already closes the exact gap `es1` (its
own direct ancestor!) was found vulnerable to; worth noting for the
wider ES-family sweep that this specific fork does NOT need the
`es1`/`tmi2`/`mortremains` fix.

### Remaining 10 patterns — checked, not applicable (no live/structural instance found)

- **§8.3a** (`private nomask command_hook`): the live `feature/command.lpc`
  already has `private` commented out (fixed in round two's own §7.28
  pass); `feature/commandhell.lpc` has the raw `private` form but zero
  `inherit` references anywhere in the tree (confirmed dead, same as the
  established `commandbak.lpc`/`command2.lpc` precedent elsewhere in this
  project). Nothing live to fix.
- **§7.123** (bare file-scope `IDENT = (...);` killing a compile): grepped
  for the exact shape tree-wide; the only 3 hits are legitimate
  multi-declarator statements (`mapping tiles = allocate_mapping(2),
  cchar = ([...]);` and `private mapping B2G_Cache = ([]), G2B_Cache =
  ([]);`) — real declarations with a type keyword earlier in the same
  statement, not the buggy bare-reassignment shape. Zero real instances.
- **§7.126** (stale pre-`.lpc` extension in AREA save data via a
  `__DIR__`-style macro placeholder): this lib has no coordinate-grid
  `AREA`/`std/area/map.lpc`-style world framework at all — ordinary
  discrete room files throughout. Not applicable.
- **§7.129** (`tell_room()` wrapper forwarding omitted `exclude` as literal
  `0`): already fixed pre-session per this lib's own `§15s` code comment
  in `adm/simul_efun/message.lpc` (both `tell_room()` and `shout()`),
  matching AGENTS.md's own "ES2-family corpus sweep (2026-08-27)" note
  that lists `haiyang2` among the libs already fixed before this pass.
  Re-confirmed by reading the live file.
- **§7.130** (net-dead heart_beat calling `query_idle()` unconditionally
  after already-detected non-interactivity): `inherit/char/char.lpc`'s
  `heart_beat()` correctly guards with `if (!interactive(this_object()))
  return;` immediately before its only `query_idle()` call. Not
  applicable.
- **§7.131** (`find_living()`/`find_player()` needing `set_living_name()`):
  the live `feature/command.lpc`'s `enable_player()` already calls
  `set_living_name(query("id"))`/`set_living_name(query("name"))`. Not
  applicable.
- **§7.132** (`map()`-over-a-mapping bound to the wrong argument): zero
  `map()`-over-a-mapping call sites anywhere in the tree (confirmed via
  `grep -rn "= map("` — no hits at all). Not applicable.
- **§7.133** (`net_dead()` apply never defined): `clone/user/user.lpc`
  defines `private void net_dead()` and it is reachable (confirmed live
  via the abrupt-disconnect test above, which exercised this exact code
  path). Not applicable.
- **§7.134** (uninitialized "extra descriptions from present items"
  accumulator crashing every room's `long()`): this lib has no
  `add_my_desc()`/`room_descs`-style mechanism at all. Not applicable.
- **§7.135**: see the `feature/dbase.lpc` fix above — the one real
  instance found this round.

### Live playthrough summary

New test character `qintester`/秦测风 (3-character Chinese name,
gift `0`/random, password `Test123`, matching this lib's documented
password policy). One continuous session: registration → `look`/
`score`/`i` (clean) → `wg`→`north`→`west`→`west` to 西练武场 →
`da muren zhuang` safe-sparring (学习潜力 99→100, confirmed via `score`
before/after) → `bai xingxiu dizi` sect-recruiter gate (correctly
rejected, matching round two) → clean `quit` (debug.log grepped
immediately after: **no `log/debug.log` file exists at all**, i.e. zero
runtime errors logged this entire session) → real wall-clock gap
(~5 minutes) → reconnect: landed in the correct saved `startroom`
(welcome room), `score` showed 学习潜力=100 persisted correctly → admin
`summon`ed into `/d/city/nandajie1` and fought the real (not
admin-boosted) `小混混`/hunhun (`combat_exp` 200 vs. a brand-new
character) — lost the fight, correctly caught by the documented
"新手不死" newbie-protection rescue (`combat_exp < 2,500,000`, white-light
rescue to `/d/pingan/guangchang`, `上次死因` stayed "无" since a rescue
isn't a real death) — confirmed via `score` post-rescue. `log/debug.log`
still did not exist after the combat sequence — zero errors end to end.

### Process hygiene

Native driver, port 40057, PID 1708062 (confirmed via `readlink -f
/proc/1708062/cwd` before every teleport/call action and immediately
before the final kill). Three raw-socket Python sessions used throughout
(admin `fluffos`/`Mud@2026`, test character `qintester`, plus a brief
second admin reconnect to exercise the abrupt-disconnect autoload test);
all quit cleanly before the driver was killed by exact PID. The
throwaway `/tmp_test_random.lpc` diagnostic file (used only for the
§7.121/§7.124 empirical test above) was deleted before committing — `git
status` never showed it as untracked at commit time. Runtime churn from
testing (`data/login/f/fluffos.o`, `data/user/f/fluffos.o`,
`data/npc/menpai.o`/`menpai1.o` — the same unrelated periodic
sect-of-the-day daemon effect prior rounds noted) reverted via `git
checkout`; test character `qintester`'s save files
(`data/login/q/qintester.o`, `data/user/q/qintester.o`) deleted, not
committed. `git status --short` confirmed clean except the one
intentional `feature/dbase.lpc` fix before committing.
