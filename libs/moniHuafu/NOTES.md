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

## WASM 修复摘要（迁移自 meta.json 的 group_note）

和 mnhf 逐字节相同的重复压缩包档案。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 4 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试（2026-08-17，round one）——两个真实 bug：移植自双胞胎档案的 §7.34，加上一个本档案独有的冷启动 eval-cost 崩溃

这份档案的原始压缩包和 `mnhf`（archive #14，已确认完全同源）在
meta.json 里就标了 `duplicate_of: mnhf`——先检查了 `mnhf` 是否已经
做过 §10.7 深度测试而不是从零重跑，果然找到 `mnhf/NOTES.md` 记录的
"第二轮"深度测试（注册 → 军训引导 → quest → 完整战斗 10+ 回合 → 干
净 quit，全程 debug.log 零报错），并在那一轮里发现并修复了一个
`logind.lpc` 里的调试残留 `printf("%O\n", ob)`（AGENTS.md §7.34 已归
档的确认实例之一）。

**移植修复 1**：对照检查后确认这份档案自己的 `logind.lpc` **仍然带
着**同样两处 `printf("%O\n", ob)` 残留（`get_resp()`/`get_name()` 各一
处）——虽然是同源代码，但两份档案各自独立经历过转档管线，`mnhf`
那边的修复从未同步过来。直接删除这两行（和 `mnhf` 的修法逐字节一
致），`lpcc_check.sh` 确认 `logind.lpc` 编译干净。

**新发现并修复的问题，本档案独有**：`lpcc_check.sh` 全档案编译检查
（945 个档案）比 NOTES.md 早前记录的 12 个失败多出 2 个新失败——
`/std/char/npc`（角色基类本身！）和 `/d/death/yanluo`（死亡区"阎罗
殿"房间）——都是同一类：`Eval interrupted: ... cost limit reached,
limit: 300000 usec.`，和本项目 AGENTS.md §7.90 已归档的冷启动
eval-cost 级联完全同类（这次撞的是 `master.lpc` 的 `valid_read()` 和
`d/death/npc/panguan2.lpc`（阎罗殿判官 NPC）首次编译时的
`feature/dbase.lpc`/`attribute.lpc` 调用链）。`config.fluffos` 的
`maximum evaluation cost` 只有 `300000`——比本项目最常见的 `700000`
默认值还要低（文件里甚至留着一行被注释掉的更低值
`#maximum evaluation cost : 100000`，说明之前就有人调过这个数字但
调得还不够），是本项目已知范围里偏低的一档。

**移植修复 2 / 新修复**：把 `maximum evaluation cost` 从 `300000` 提到
`5000000`（AGENTS.md §7.90 的标准补救值，本项目 30+ 档案已使用）。
**现场验证**：重开一个全新驱动进程，用管理员账号 `fluffos` `goto
/d/death/yanluo`——修复前这个房间在 `lpcc` 批量编译时必现上述崩溃；
修复后干净渲染出完整房间描述、阎王爷（Death-god）和四名判官
（Death-judge/Niutou/Mamian）NPC，`debug.log` 全程零 `cost limit
reached`/`Too long evaluation` 记录。孪生档案 `mnhf` 自己的
`config.fluffos` 用的是 `700000`（比这份档案高，但仍属于本项目已知
"偏低、部分档案不够用"的那一档）——`mnhf` 早前的战斗测试之所以没撞
上这个问题，很可能是同一会话内先做过的注册/quest 尝试已经把
`std/char`/`feature/*` 这条昂贵编译链"预热"过了（和 AGENTS.md §7.90
第三个实例记录的"同会话内重试掩盖首次编译代价"效应一致），不代表
`mnhf` 真的没有这个风险；本次会话未去动 `mnhf` 自己的配置（超出本
轮任务范围），留给未来专门测试 `mnhf` 时一并核实。

**战斗/死亡循环**：鉴于孪生档案 `mnhf` 已经用同一份共享代码验证过
完整战斗流程（10+ 回合攻防判定正常），本轮聚焦在冷启动 eval-cost 崩
溃这个 `mnhf` 测试没有触及、且这份档案独有偏低配置值导致的具体问
题上，未重复完整战斗/复活/留言板测试——`goto` 死亡区确认房间和
NPC 都能正常载入即视为该风险点已解除。测试账号 `fluffos` 死亡/移
动产生的存档变化已还原，未纳入本次提交。

## §7.100 sub-threshold instance (2026-08-20)

Found during the §7.100 tail-sweep (below the original 166-lib survey's
>=100-occurrence threshold, never checked). Sibling of `mnhf`
(diverged fork, but shares this exact bug in the same 61 files): 61
live `replace_program(ROOM);` occurrences deleted (`obj/void.lpc`,
`d/huafu/*.lpc`, `d/new/wel1-3.lpc`, `d/wiz/jobroom.lpc`, and a large
`d/death/*.lpc` cluster of 38 rooms). No room-building tool exists in
this lib. Verified via a clean native driver boot (zero new
`debug.log` errors, port listening, killed by exact PID after ~8s).

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 3 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试 round three batch 4 新角度测试 (2026-09-01) —— 补齐 round one 明确跳过的真实战斗/死亡/留言板/货币持久性测试，找到并修复一个 `buy.lpc` 价格显示 bug（`mnhf` 共享）

Round one（见上文 2026-08-17 一节）明确承认"鉴于孪生档案 `mnhf`
已经验证过完整战斗流程，本轮未重复完整战斗/复活/留言板测试"，只
用 `goto` 确认了死亡区房间能载入。本轮按任务要求，在 `moniHuafu`
自己身上独立补测这些从未真正跑过的角度，不再依赖孪生档案的"代理
覆盖"。

**测试账号**：新注册真实玩家角色 `testqaz`（中文名"测试生"，密码
`TestPass1`），管理员账号复用既有的 `fluffos`/`Mud@2026`（已在
wizlist 里，有真实存档）。全程用 `scripts/tmux_mud.sh` 交互操作，
`goto`/`summon` 由管理员执行，实际游戏动作全部由 `testqaz` 这个
普通玩家账号真人指令驱动。

**1. 注册环节对抗性输入**：英文名字阶段输入含数字的
`testqa4`（正确拒绝："对不起，你的英文名字只能用英文字母"）；
y/n 确认阶段发送 3000 字节纯 ASCII 垃圾字符串（被当成非
"y" 处理，正常回落到重新输入英文名字，无崩溃）；中文名字阶段发
送 2000 字符的"测试"重复垃圾字符串（正确拒绝："你的中文名字必须
是一到六个中文字"）；邮件地址阶段发送空白回车（正常放行，不强
制要求邮箱）。全程 `debug.log` 零新增错误。

**2. 真实战斗到实际死亡 + 完整复活流程**（round one 从未做过）：
`testqaz` 在 `/d/huafu/caoping`（草坪，`valid_startroom` 新手练功
点，5 只 `npc/bird`）对 `小鸟` 发起 `kill bird`，交手 7-8 回合后
气血降到临界值触发游戏自带的自动逃跑安全阀（"看来该找机会逃跑
了..." → 自动往西逃到 `/d/huafu/zhxd1`），这是设计好的保护机制，
不是 bug。为了真正走完死亡流程（不是设计出来阻止死亡的安全阀），
管理员 `fluffos` 追上去用 `smash testqaz` 强制致死（AGENTS.md 记
录过的"管理员 smash/die() 绕过自动逃跑"标准做法）——测试角色正
确传送到 `/d/death/`（"高三鬼门关"死亡区），`监考官`/`铁索 数学
老师`/`枷铐 语文老师` 三个死神系 NPC 正常互动对话，几秒后"一股
阴冷的浓雾突然出现，很快地包围了你"，自动传送回 `/d/huafu/juqing`
（聚清园，复活点）。复活后角色 `hp`：气血 31/369、精力 70/499、
潜能 150（死前 299）、学分 491（死前 501）——正确应用了死亡惩罚
（潜能/学分扣减），`i` 显示"目前你身上没有任何东西"（死亡时随身
物品/装备全部清空，这也是死亡惩罚设计的一部分）。全程 `debug.log`
零新增错误，这是本档案第一次真正验证"战斗判定→致死→死亡区→复
活→惩罚结算"这条此前完全没测过的完整链路。

**3. 货币持久性（quit → 重连）验证，针对任务里点名的 §7.199 风险
点**：`grep` 检查 `work/std/money.lpc` 和 `work/std/item/money.lpc`
两份货币基类，`query_autoload()`（`return query_amount() + "";`）
和配套的 `void autoload(string param)` 都是**完整、未被注释掉**
的——不是 AGENTS.md §7.199 那种"`autoload()` 收方在、`query_autoload()`
访问器被注释掉"的半吊子形状。**这份档案（以及孪生档案 `mnhf`）都
不在 §7.199 已确认的 16 个风云家族档案名单里**（`fysjmb`/
`fengyun434`/`fy2`/`fy2005`/`fy2mg`/`fy2qh`/`fy330`/`fy3dz`/`fy3xd`/
`sjpl2`/`sjplgfjxb`/`sjplii`/`wqfy`/`xsfyssjb`/`zzfy`/`zzfy3`），本
轮现场验证印证了这一点，不是巧合漏查。**现场验证**：管理员
`clone /obj/money/gold` + `give gold to testqaz` 给测试角色一张
"一百元人民币"；`quit` 干净退出（无"你丢下"提示，因为这是唯一支
持 `query_autoload()` 的随身物品）；重新连线登入后 `i` 正确显示
钱款仍在（自动转成了找零后的"九十八元人民币(Silver)"面额——见下
一条商店测试），排行榜也正确显示"十大富翁排行榜第三名"。货币
quit/reconnect 持久性**完全正常，没有数据丢失**。

（附带发现，非 bug）：`i` 里"测试生的运动鞋(Shoe)"/"测试生的校
服(Cloth)"/"测试生的文具盒(Wj case)" 这三件新手装备在死亡后清
空、在下一次 `quit` 后也会被 `quit.lpc` 当成"不支持
`query_autoload()`" 的普通物品丢在原地（提示"因为这样东西并不值
钱，所以人们并不会注意到它的存在"），但下次连线 `enter_world()`
（`adm/daemons/logind.lpc:617-624`）**无条件**重新 `new()` 一套全
新的鞋/校服/文具盒发给玩家，不检查玩家是否已经有一套。源代码注
释就写着"// This is the basic equip for players just login."——这
是刻意设计的"每次连线发一套新校服"机制（这三样东西都没有设
`"value"` 属性，等同于 0 元不可变卖，不构成经济漏洞），不是数据
损坏/丢失类 bug，未改动。

**4. 商店购买 + 真实发现并修复的价格显示 bug（`mnhf` 共享）**：
管理员 `summon testqaz` 到 `/d/huafu/xmbu`（小卖部），`list` 正确
显示"水果面包 fruitbread：2元"；`buy fruitbread from seller` 成功
扣款（`i` 确认从 100 元变成"九十八元人民币(Silver)"找零，扣款金
额正确），但游戏回显的确认信息却是**"价格：200。"**——比商店
`list` 标示的"2元"整整大了 100 倍。

根因：`cmds/std/buy.lpc` 内部金额单位是"分"（`pay_him()`/
`affordable()` 用 `SILVER_OB`/`GOLD_OB` 等面额换算全部按分计
算，1 元 = 100 分，与 `feature/vendor.lpc` 的 `buy_object()`/
`do_vendor_list()` 一致），`do_vendor_list()`（`list` 指令）用
`price_string(v)` 把内部分值正确转成"N元"再显示，但 `buy.lpc`
第 31、37 行的两处 `write("价格：" + price + "。\n");` 直接把内部
分值原样打印出来，从未转换成元，导致每次购买确认信息都比商店价
目表大 100 倍（这次买 2 元的东西显示"价格：200"）。这是纯粹的显
示层 bug——实际扣款金额是对的（分制内部账本本身没有算错），只
是回显给玩家的确认文字用错了单位，容易让玩家误以为被多扣了钱。

**修复**：把两处 `write("价格：" + price + "。\n");` 改成
`write("价格：" + owner->price_string(price) + "。\n");`——`owner`
（卖家 NPC）经由 `F_VENDOR` 继承了 `price_string()`，与 `list`
指令用的是同一个格式化函数，保证两处显示口径一致。**现场验证**：
管理员 `update /cmds/std/buy` 热重载（"重新编译
/cmds/std/buy.lpc：OK！成功了！"），`testqaz` 紧接着
`buy chizi from seller`（商店标价 7 元），确认信息正确变成
"价格：7元。"（改前会显示"价格：700。"），`debug.log` 全程零新
增错误/警告变化。

**共享风险**：`diff` 确认 `mnhf` 的 `cmds/std/buy.lpc` 与本档案**逐
字节相同**——这是两份档案共享的同一个 bug，`mnhf` 自己至今没有被
验证过真实的 buy 交互（`mnhf` 的 round two 深度测试记录未提及测过
商店购买），大概率同样受影响。本次会话未去动 `mnhf`，留给未来专
门测试或跨库扫描 `cmds/std/buy.lpc` 时一并处理（只在这一个共享文
件里出现两次，属于孤立的小范围问题，未达到本项目"3+ 独立血统"才
发起机械化跨库 sweep 的门槛，暂不单独立项）。

**5. 留言板 post/read**：`testqaz` 走到 `/d/huafu/zhting`（南楼中
厅）的 `校园公告栏(Board)`，`post board` 成功发帖（留言计数从 47
正确增加到 48），`read <编号>` 能正确读回刚发的帖子。**方法论踩
坑记录（不是 mudlib bug，是本次测试工具的假阳性）**：最初两次
（一次论坛留言，一次后面的站内信）都是通过 `tmux send-keys` 发送
含"内"字（UTF-8 三字节 `E5 86 85`）的中文测试语句，`read`/`from`
回显和磁盘落地文件里那个"内"字都被替换成了 Unicode 替换字符
`U+FFFD`（`EF BF BD`）——一度怀疑是驱动/mudlib 层的编码 bug。改
用绕过 tmux/pty、直接进程内 Python `socket` 连接发送完全相同的字
节序列后，`read`/落地文件里的"内"字**完全正确**，证明这是
`tmux send-keys` 本身在处理这个特定字节序列时的终端层问题（很可
能与 `0x85` 单独出现时被某层当成 NEL 控制字符处理有关），不是
`moniHuafu`/驱动的真实 bug——记录在这里防止未来测试重蹈覆辙，避
免误报。

**6. 站内信（邮局系统）**：`testqaz` 在 `/d/huafu/youju`（石牌邮
局）用 `ask officer about 寄信` 拿到信箱物品（`obj/mailbox.lpc`），
`mail fluffos` 走完标题→正文→是否留底三步流程，成功寄出。收件人
`fluffos`（在线）用 `ask officer about 收信` 拿到自己的信箱，
`from` 正确显示"你的信箱中现在共有 1 封信件"，`read 1` 正确显示
标题/寄信人/正文（用绕过 tmux 的原始 socket 复测过第二封信，字节
完全正确，见上一条）。**邮箱存档目录自动创建验证**：`work/data/mail/`
原本只有 `g`/`j` 两个字母子目录，`testqaz`（t 开头）和 `fluffos`
（f 开头）对应的 `t`/`f` 子目录此前都不存在——`feature/save.lpc`
的 `save()` 在 `save_object()` 之前调用了 `assure_file()`，两个缺
失目录都被正确自动创建，没有触发 AGENTS.md 记录过的"目录不存在
导致 `log_file()`/`save_object()` 崩溃"那一类 bug（`dock9` 那次是
真的崩溃，这里是正常的自愈行为）。

**未发现的问题**：本轮压力测试的角度里，除上述已修复的 `buy.lpc`
显示 bug 外，注册对抗性输入、战斗/死亡/复活、货币持久性、留言板、
邮局系统均**完全干净**，`debug.log` 全程零新增报错。测试账号
`testqaz` 的存档变化（等级、货币、邮件等）随本次提交一并保留，
`fluffos` 管理员账号的信箱/位置变化同样保留（历次深度测试的标准
可复用巫师账号，累积游玩痕迹属预期行为）。
