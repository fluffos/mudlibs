# moniHuafu — 模拟华附 (Simulated Huafu)

Archive: `模拟华附.zip`. Port: 40051. Status: **done** (boots clean, full
registration + save/restore + gameplay flow verified end-to-end with a
real Chinese name).

## What this is

`config.cfg`'s own `name :` field and `readme.txt` both self-identify this
lib as **模拟华附** ("Simulated Huafu" — 华附 = 华南师范大学附中,
a well-known Guangzhou high school). Archive root is nested one level at
`vrhf/` (not top-level) — mudlib root confirmed via `config.cfg`'s `master
file : /adm/obj/master`. Author "阿飞"/"Jjgod" (糊涂泥巴工作室), dated
2000/12/07 per the readme's changelog. ~1500 raw files, 945 `.c` files —
a small/medium lib.

**Lineage**: readme.txt's own credits list confirm this is built on the
**风云3 (Fengyun 3) engine** ("底层系统：风云3") — same lineage already
processed as `zzfy`/`fy2`/`fy2005`/`fengyun434` (archives #14, #16, #17,
#30). Confirmed structurally: `adm/obj/master.c` is 351 lines here vs 346
in `zzfy`'s `fy3/adm/obj/master.c`, near-identical shape/content (`diff`
shows the same functions almost verbatim, e.g. the same
`crash()`/`compile_object()`/`valid_write` boilerplate). This is a themed
skin (Huafu high-school setting) built on top of the 风云3 base engine,
with a `cmds`/`std`/`feature`/`obj`/`adm` layout matching that family, plus
custom content (`d/huafu/` zone, school-themed items like 校服/文具盒/
运动鞋, a class-registration wizard, sports-team/campus-card systems per
the readme's changelog).

## Fixes applied

**AGENTS.md §15p (DNS/intermud daemon preload exclusion)**, applied
proactively before first boot: `adm/etc/preload` listed
`/adm/daemons/network/dns_master` — removed it (unreachable boot-server
handshake, causes hangs in this sandboxed environment per standing
policy).

**AGENTS.md §15h (GBK byte-range Chinese detection)** — the exact same
shape as the other 风云3-family libs (zzfy/fy2/fy2005/fengyun434),
applied proactively:
- `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range check
  (`str[0] > 160 && str[0] < 255`, guarded by `strlen(str)>=2`) → CJK
  Unicode codepoint range check (`str[0] >= 0x4e00 && str[0] <= 0x9fff`).
  Also halved the `strlen` guard from `>=2` to `>=1` — required because
  `logind.lpc`'s `check_legal_name` calls this per-*character*
  (`is_chinese(name[i..<0])`, a length-1 substring for the last
  character), and the old `>=2` byte-pair guard would otherwise always
  reject that final character even after fixing the codepoint range.
- `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count length
  bound (`< 2 || > 12`, message promises "一到六个中文字" — 1 to 6
  Chinese characters) halved to character count (`< 1 || > 6`); removed
  the `i%2==0` even-byte-offset gate so every character position is
  actually checked (not just every other one, which used to land on GBK
  lead bytes).

**New bug, this lib (unguarded `read_file()` feeding straight into
`write()`)**: `cmds/usr/uptime.lpc`'s `main()` — called from
`logind.lpc`'s `logon()` on **every single connection** (via
`UPTIME_CMD->main()`) — ended with `write(read_file("/log/nosave/
LASTCRASH"))`. The archive shipped with no `LASTCRASH` file matching that
exact path (see next finding for why), so `read_file()` returned `0`
(int), and `write(0)` threw `*Bad argument 1 to receive(): Expected:
string or buffer Got: 0` — a **fatal, uncaught error inside `logon()`**,
so the driver's `new_conn_handler` silently disconnected every single
connection attempt with **zero prompt ever appearing**, right after the
ASCII-art banner. Fixed with `read_file(...) || "无。\n"` (same
"guard the un-checked call" pattern as AGENTS.md §15e).

**New bug, this lib (blanket `static`→`nosave` sed corrupting *string
literals*, not just the keyword)**: while diagnosing the above, found
that `/log/nosave/LASTCRASH` (and `/log/nosave/CRASHES`,
`/log/nosave/promotion`, `/log/nosave/PURGE`, `/log/nosave/SUICIDE`,
`/log/nosave/CALL_PLAYER`, `/log/nosave/ATTEMP_KILL`, `/log/nosave/VI`
— 10 files total) were **originally** `/log/static/...` in the raw
archive — confirmed both by `diff`-checking the raw pre-conversion
`master.c` (has `"static/CRASHES"`) and by finding the archive's own
pre-existing seed data physically sitting at `work/log/static/`
(`CRASHES`, `LASTCRASH`, `CALL_PLAYER` — real historical log entries from
the original site, e.g. `LASTCRASH` contained a genuine "palmy重新启动
模拟华附于：Fri Dec 08 13:20:07 2000" entry). `convert_lib.sh`'s
blanket `\bstatic\b` → `nosave` word-boundary sed (AGENTS.md §3, meant for
the `static <type> function()` FUNCTION-modifier parse-error fix) doesn't
distinguish code position from string-literal content — a bare `static`
inside a string like `"static/CRASHES"` matches the same word-boundary
regex and got silently rewritten too. This is a **new, previously
undocumented collateral-damage variant of the known §3 risk** (the
existing AGENTS.md caveat only calls out spot-checking for false
positives on IDENTIFIERS, not on string-literal directory-name
collisions). **Fixed**: reverted all 10 files' `nosave/` log-path string
literals back to `static/` (targeted `sed 's/nosave\//static\//g'` on the
specific 10 files that had this pattern, verified none of them had any
*other* legitimate use of the word `nosave` that would need to stay
changed). This both fixes the crash AND restores read access to the
archive's real pre-existing `LASTCRASH`/`CRASHES` seed data instead of
silently losing it under an unused new path. **Lesson for future libs**:
after the static→nosave sed, also grep for `nosave/` as a literal string
path pattern (`grep -rn '"nosave/\|nosave/[A-Z]' work --include="*.lpc"`)
and cross-check the physical directory tree (`find work/log -maxdepth 1
-type d`) for a same-named `static/` directory that already has data in
it — a strong sign the string was originally `"static/..."` and the sed
over-matched.

**New landmine, neutralized (not a compat bug, a dormant destructive
function)**: `adm/daemons/securityd.lpc` has a `checking_status(mapping
info)` function (labeled in its own Chinese comment "下面就是恐怖的风云3
自毁灭程序" — "below is the terrifying 风云3 self-destruct program") that,
if called with a payload whose `info["MSG"]` matches a hardcoded
`crypt()` hash, calls `rmhirdir("")` (recursively deletes **every file
under the mudlib root**) then `shutdown(0)`s the server — apparently a
phone-home anti-piracy/license-check mechanism from the original fy3
distribution model, meant to be triggered externally by some
"registration server" handshake. Confirmed via `grep` across the entire
lib that **nothing in this archive's own LPC source ever calls
`checking_status()`** — it's unreachable in this sandboxed environment
(no such external handshake exists, no other daemon on the preload list
calls it, `resolve_callback()` — the only thing wired up to fire
automatically via `resolve()` in `create()` — merely logs the peer IP and
returns). Left dormant/never-triggered would probably be safe, but
**neutralized the destructive body anyway as cheap insurance** (replaced
with a log-only stub) rather than rely on it staying unreachable forever
across future edits to this lib.

**AGENTS.md §14 (valid_override 3-arg upgrade)**: `master.lpc`'s
`valid_override(file, name)` was still 2-arg; `adm/simul_efun/object.lpc`
(an `#include`d fragment inside `simul_efun.lpc`) has an `efun::
destruct(ob)` override, the exact shape §14 warns about. Upgraded to the
3-arg `valid_override(file, name, main_file)` signature, checking both
`file` and `main_file` against `SIMUL_EFUN_OB`/`MASTER_OB`. Applied
proactively as free/correct insurance; per §14's own note this "may never
surface in a real boot" — confirmed true here too (see lpcc sweep notes
below: it only shows up as an lpcc-sweep artifact when `object.lpc` is
compiled standalone as its own top-level unit, never during the real
boot or any interactive test).

## What was checked and confirmed NOT needed

- **§4 (lazy security-daemon `load_object` recursion in `valid_read`/
  `valid_write`)**: not present. `master.lpc`'s `valid_write` only calls
  `find_object(SECURITY_D)` (no `load_object`), and `valid_read` just
  unconditionally `return 1;` — no recursion risk either way. Confirmed
  by reading the full file.
- **§7 (missing `get_root_uid`/`get_bb_uid`)**: both already implemented
  in `master.lpc`, returning `ROOT_UID`/`BACKBONE_UID`. Confirmed present.
- **§15l (`master.lpc create()` destructing `SIMUL_EFUN_OB`)**: `create()`
  here is a one-liner (`write("master: loaded successfully.\n");`) — no
  destruct/reload dance at all. Confirmed by reading the file.
- **§15n/§15o (custom securityd `valid_read` blocking mid-connection lazy
  compiles / missing `get_include_path()`)**: `securityd.lpc` only
  implements `valid_write` (no custom `valid_read` at all — `master.lpc`'s
  own `valid_read` unconditionally allows everything), so the specific
  §15n gap (a custom ACL denying the driver's own compile-time `func==
  "load_object"/"include"` checks) doesn't apply here. Confirmed by
  reading `securityd.lpc` in full — no `valid_read` function exists in it.
- **§15 / the "nitan" family's simul_efun-`set`/`query`/`delete`-as-shared-
  dbase architecture bug**: not applicable — `adm/simul_efun/wizard.lpc`
  is only 11 lines (no generic property-storage `set`/`query`/`delete`
  implementation at all), confirming this lib does NOT use that
  architecture (same conclusion as `zzfy`/`rzrmud`, other non-nitan-family
  libs). Confirmed by reading the file.
- **§8e (`tail()` missing efun)**: no `tail(` call anywhere in the lib
  (checked via grep). Not needed.
- **§8d/§15o (`<local.h>`-style angle-bracket local includes)**:
  `convert_lib.sh`'s automatic local-angle-bracket-to-quote conversion
  found and fixed 7 instances during the mechanical conversion pass; no
  `master.lpc get_include_path()` override was needed beyond that (the
  remaining 829 angle-bracket includes all resolve against the configured
  `include directories : /include` path correctly, confirmed by the clean
  master/simul_efun boot and the full lpcc sweep having zero
  `Cannot #include` failures for anything reachable).
- **§15t (absolute-path-in-angle-brackets / `..`-relative includes /
  inherit-after-globals ordering)**: none of the three patterns found.
  Checked via `grep -rn '#include *<\s*/'` (0 hits — no absolute paths
  inside angle brackets) and `grep -rn '#include *"\.\./'` (0 hits — no
  `..`-relative quoted includes). No header file contains an `inherit`
  statement, ruling out the inherit-after-globals variant too.
- **§15b family (`clr_ansi`/`chinese_number`/`changed_match_path`/
  `query_bandwide`/`query_shadowed`/`remove_ansi`/`noansi_strlen`/`B2G`/
  `db_affected`/`addn`)**: `chinese_number()` IS defined in this lib
  (delegates to `CHINESE_D->chinese_number(i)`, a real daemon method, not
  a gap) and is used correctly by `logind.lpc`/`uptime.lpc`. None of the
  other names in this family appear anywhere in the lib (checked via
  grep) — this lib's own simul_efun set doesn't share that particular gap
  list, confirming (as already noted for `rzrmud`/`zzfy`) that this bug
  class is lineage-specific, not universal.
- **`named.lpc`/`PATH()` macro sliding-window bug**: no `named.lpc` (or
  equivalent) exists in this lib at all — confirmed via `find -iname
  "named.*"` (no hits) and `grep -rn "define PATH"` (only an unrelated FTP
  protocol constant in `include/net/ftpd.h`, not a Chinese-character
  sharding macro).

## Interactive registration + gameplay test — full transcript outcome

Ran the complete flow in ONE continuous `mudclient.py` connection first
(read `logind.lpc`'s actual `logon()`/`get_id`/`confirm_id`/`get_name`/
`new_password`/`confirm_password`/`get_email`/`get_gender`/`get_nresp`
callback chain beforehand — no hidden BIG5/client-version pre-id gate
here; the very first prompt IS the real English-id prompt):

1. Connect → ASCII-art banner + MOTD poem + uptime/visitor-count banner
   (this is where the uptime.lpc bug lived — fixed, confirmed clean here)
   → `您的英文名字：` prompt.
2. `qinfeng` → passes `check_legal_id` (3-10 lowercase letters, not in
   `banned_id`) → `使用"qinfeng"这个名字将会创造一个新的人物，您确定吗
   (y/n)？`
3. `y` → registration wizard step 1 banner → `好的，现在请输入您的中文
   名字：`
4. **Real Chinese name `秦风`** → accepted immediately, NO rejection
   message (the direct proof the §15h fix works — this exact input
   would previously have failed `is_chinese()`'s always-false GBK
   byte-range check) → registration wizard step 2 banner (password rules)
   → `好的，下面请设定您的密码：`.
   (Note: my scripted extra `y` send meant for a name-confirmation step
   that turns out not to exist in this lib's flow — `get_name` goes
   straight to password on a successful name, no `get_resp` y/n step —
   was harmlessly consumed as a too-short password attempt and correctly
   rejected by `check_legal_password`, then the real `Aa123456` password
   was accepted on the very next line. Documented here per the project's
   "hidden prompt / flow-shape" caution — the flow shape itself is
   simpler than some other libs', not a bug.)
5. `Aa123456` (password, passes: ≥6 chars, has upper+lower+digit, not
   substring-similar to id) → `请再输入一次您的密码...`
6. `Aa123456` (confirm) → matches → `您的电子邮件地址：`
7. `test@example.com` → registration wizard step 3 banner (gender/class
   type) → `您要扮演男性(m)的角色或女性(f)的角色？`
8. `m` → class-type menu → `请选择你在模拟华附中扮演的人物类型
   （0，1，2，3）：`
9. `0` (聪明好学型) → character created, `enter_world()` called →
   **actual game room**: "模拟华附军训课程" (orientation room), full room
   description, exits `east`/`south`, an NPC (`模拟华附新生指导员`)
   greeting the new player by name, a server-wide welcome broadcast
   (`【华附时空】...我们的同学秦风(qinfeng)前来上学了`), a top-10
   ranking notice, and starting inventory drop-on-quit messages.
10. `look` and `quit` both processed normally — quit correctly dropped
    starting inventory (文具盒/运动鞋/校服) and broadcast a departure
    message (`秦风(qinfeng)回家了`).

**Second independent test** (separate `mudclient.py` connection, same
driver process, no restart): reconnected with the just-created `qinfeng`
id + password `Aa123456` → correctly detected the existing save file,
prompted for password, `restore()`d the saved character successfully,
re-entered the SAME starting room via the normal login path (not
character-creation), `look`/`quit` worked identically. Confirms the
save/restore login path (not just first-time registration) also works
end-to-end with the real Chinese-named character.

`debug.log` reviewed in full across both sessions: zero fatal errors,
zero `Undefined function`, zero `Read access denied`, zero `Too deep
recursion` — only routine `Unused local variable`/`Unknown #pragma`
compile warnings (harmless, this lib's own `log_error()` mislabels
compile warnings as "编译时段错误" [compile-time error] in the log
output, a pre-existing cosmetic quirk of this mudlib's error handler, not
something introduced by this port).

## lpcc sweep

945 files, 933 pass / 12 fail (**98.7%**). All 12 failures triaged and
confirmed non-critical, not fixed:

- **10 files**: `adm/daemons/network/{ms,userid,pingtcp,name_server,
  mail_serv,netmail,telnetd,pingd,inetd}` + one more — legacy
  intermud/mail/telnet-proxy network services, missing headers
  (`Cannot #include config.h`/`mailer.h`/`daemons.h`/`uid.h`) and
  undefined globals (`MAILDIR`, `THIS_MUD`, `member_group`) that were
  never fully wired up even in the original archive. **Confirmed
  harmless**: none of these files are on `adm/etc/preload` or referenced
  by any other `.lpc` file in the lib (checked via grep) — genuinely dead/
  incomplete content, same category as AGENTS.md §13's missing-zone
  pattern, just for network-service daemons instead of rooms.
- **`/obj/example/temp`**: runtime error `*F_SKILL: No such skill
  (meihua-shou)` in its own `create()`. An example/template NPC file
  referencing a skill that was never implemented in this archive.
  Confirmed unreferenced by anything else in the lib (grep for
  `example/temp` finds only the file itself) — orphaned example content,
  not on any load path.
- **`/obj/home`**: compile error `Undefined function set_max_items`.
  Confirmed `set_max_items` is defined nowhere in the entire lib (grep),
  and `/obj/home` itself is never referenced by any other file — another
  orphaned/incomplete example file, never reached by any real code path.
- **`/adm/simul_efun/object`**: `error: Invalid simulated efunction
  override` on its `efun::destruct(ob)` line. This is the exact AGENTS.md
  §14 sweep-artifact case — `lpcc` compiling this `#include`-only
  fragment as its own standalone top-level object means `main_file`
  (added by this session's 3-arg `valid_override` upgrade) equals the
  fragment's own path, not `SIMUL_EFUN_OB`, so the check still (correctly,
  per the file's real identity when compiled ALONE) rejects it. Verified
  against the real driver boot log: `grep` for this exact error string in
  `debug.log` across both interactive test sessions comes up empty — the
  composed `simul_efun.lpc` (which `#include`s this fragment as part of
  ONE real compilation unit, `main_file == SIMUL_EFUN_OB` in that context)
  compiled and ran cleanly. Confirmed sweep-only artifact, not a live bug.

Memory stayed healthy throughout (host had ~4GB free / ~19GB available
before the sweep on this small, 945-file lib — nowhere near the §6b
mega-lib OOM risk threshold).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter**: ran `format-corpus.mjs` across all 945 `.lpc` files
  under `work/` — 932 reformatted, 3 already-idempotent/unchanged, 10
  refused (token-mismatch safety gate, expected on messy legacy code, not
  investigated further per the formatter's own self-check guarantee).
- **Native retest against the freshly-rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): booted clean, zero fatal errors in `debug.log`. Ran a full
  interactive registration with a real Chinese name (`秦风二` / id
  `qflibtwo`) through all three registration-wizard steps (name →
  password → email → gender → class-type), reached the actual starting
  room (模拟华附军训课程), and confirmed `look`/`score`/`quit` all
  produce correct output (score sheet renders the character's real
  stats; quit drops starting inventory and broadcasts departure). The
  post-formatter reformatted source behaves identically to the
  pre-formatter tree — no regression from either the driver rebuild or
  the reformat.
- **WASM build test** (`scripts/wasm_client.js` against
  `build-wasm/src`): the lib **boots cleanly** under WASM
  (`Initializations complete.`, only the expected non-fatal preload
  warnings). However, **interactive registration is blocked by a real,
  driver-documented WASM limitation, distinct from the
  `query_ip_number()` gate**: `adm/daemons/securityd.lpc`'s `create()`
  unconditionally calls `resolve(query_host_name(), "resolve_callback")`
  (a DNS-lookup efun) with no guard around it. Per
  `~/src/fluffos/docs/build-wasm.md`'s own "Notes & limits" section,
  `resolve()` raises `"DNS resolver is not available"` on this WASM
  build. Because `securityd` is lazily loaded (not preloaded) the first
  time `master.lpc`'s `valid_write()` needs it — which happens on the
  very first login attempt — the raised error aborts `create()` partway
  through, before `wiz_status = allocate_mapping(...)` runs. The very
  next call to `get_status()` then does `wiz_status[euid]` against an
  uninitialized (zero) mapping and throws `*Value being indexed is
  zero.`, which corrupts that connection's `input_to()` callback chain
  (the session falls out of the name-entry prompt into a bare, bodyless
  command loop that just replies "什么？" to everything). **This is a
  WASM-driver-level gap (an unavailable/throwing efun the lib doesn't
  guard against), not a mudlib bug** — confirmed by two clean, complete,
  end-to-end native registrations (this pass and the original conversion
  pass) hitting this exact same `securityd.lpc` code with zero issue,
  because the native driver's `resolve()` actually works. Not patched,
  per the standing "don't fix WASM-only driver gaps in the mudlib"
  policy — documented here instead. Status: **boots under WASM;
  interactive login blocked by a resolve()-under-WASM limitation
  (WASM-driver gap, not this lib's bug)**.

## WASM-enablement pass (2026-07-23): loopback-allow + admin seeding

Gates patched:

- `adm/daemons/band.lpc` `is_banned()` (~line 51) — short-circuit return 0
  for loopback ("127.0.0.1"/"localhost"/any "127." prefix) or
  empty/non-string input (WASM builds pass garbage; this gate is called
  with both `query_ip_name()` and `query_ip_number()` from `logind.lpc`
  `logon()`).
- `adm/daemons/logind.lpc` `logon()` (~line 80) — the per-IP
  three-connections cap now fully exempts loopback/malformed-IP
  connections (previously it only special-cased the literal ip_name
  "127.0.0.1", which WASM never produces).
- `adm/daemons/securityd.lpc` `create()` — the unguarded
  `resolve(query_host_name(), ...)` call was moved AFTER the
  `wiz_status` state init and wrapped in `catch()` (the AGENTS.md §1.3c
  风云-family idiom): under WASM the throw used to abort `create()`
  mid-way, leaving `wiz_status` uninitialized and crashing the first ACL
  lookup ("*Value being indexed is zero"). This unblocks the documented
  WASM login blocker for this lib.
- No `uptime()` startup gate and no registration throttle exist here
  (checked).

Admin account: `fluffos` / `Mud@2026`, Chinese name 浮浮, granted
`(admin)` via `/adm/etc/wizlist` (file normalized CRLF→LF). Verified:
registration via the real flow, re-login restore path, and
`update /adm/daemons/band.lpc` succeeds. Saves at
`data/login/f/fluffos/fluffos.o` + `data/user/f/fluffos/fluffos.o` (not
gitignored). Fresh normal registration (秦风/testqa) re-verified
end-to-end and the test char removed; debug.log clean.

### Fail-closed retrofit (2026-07-24)

The `band.lpc` `is_banned()` carve-out and `logind.lpc`'s `nowip`
multi-login-cap bypass originally ALSO treated any empty/non-string/
unparseable IP (or `query_ip_name()` value) as trusted-local (fail-open,
defensive against an older WASM `query_ip_number()`/`resolve()` bug now
fixed upstream). Tightened both to strict loopback only (`"127.0.0.1"`,
`"::1"`, `"localhost"`, or a `"127."` prefix) — malformed input now falls
through to the same regexp-based ban check / multi-login count as any
other site string (this lib's original `is_banned()` had no separate
non-string fast-path, so no additional fail-safe was needed there).
Re-verified loopback login, `look`, `update`, and quit all still work
after tightening.
