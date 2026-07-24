# shiji — 世纪 (Century)

Archive: `世纪.zip`. Port: 40026. Status: **done** (boots clean, full
registration flow verified end-to-end including a real Chinese name).

## What this is

"世纪(CENTURY)" ("Century"), mudlib root at `century/lib/`, config at
`config.cfg` (referencing `mudos.exe`/`mudos.dll` — a Windows MudOS
build). Uses the `adm/single/{master,simul_efun}` layout convention (same
shape as the ES II/bxsj-family libs, though otherwise unrelated content —
its startup banner actually credits "星战英雄之乱世风沙" as the
copyright, suggesting this is a modified/rebranded fork of the
xingzhanyingxiong (archive #2) codebase or a shared common ancestor).
~3,554 raw files.

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**: `adm/single/master.lpc`'s
   `valid_write` called `load_object(SECURITY_D)` unconditionally on
   every call (wrapped only in a bare `catch()`, no re-entrancy guard).
   Applied the standard `nosave` flag + `find_object()` gate fix.
   `valid_read` was already a hardcoded `return 1;` — no fix needed
   there.
2. **AGENTS.md §15h (GBK byte-range Chinese detection)**: `adm/simul_efun/
   chinese.lpc`'s `is_chinese()` (GBK lead-byte range → CJK codepoint
   range) and `adm/daemons/logind.lpc`'s `check_legal_name()` (byte-count
   bound `< 2 || > 10` → character-count bound `< 1 || > 5`, removed the
   `i%2==0` even-byte-offset gate). Both applied proactively before first
   boot, recognized on sight from the identical shape seen in every prior
   lib.
3. **New: case-sensitive filename mismatch on a DATA file, not a
   `#include`** (generalizes §15g beyond source includes — see new
   catalog entry §15k below). `adm/daemons/logind.lpc`'s
   `howmany_visitor()` does `read_file("/adm/single/MUDVISITOR")`
   (hardcoded uppercase), but the actual file extracted from the archive
   is `adm/single/mudvisitor` (lowercase) — silently resolved on the
   original Windows build's case-insensitive filesystem, hard-fails
   here. Symptom was much nastier than a compile error: `read_file()`
   returns `0` (not found) instead of a string, and the following
   `sscanf(content, "%s %d", format, num)` crashes with "Bad argument 1
   to sscanf, Expected: string Got: 0", which happens inside
   `logon()` → `howmany_visitor()`, i.e. on literally every single new
   connection's `new_conn_handler`, immediately disconnecting the user
   before any prompt renders (empty `mudclient.py` transcript, looked
   like a totally dead server on the first probe). Fixed by copying the
   file to the uppercase name the code expects (kept the original
   lowercase file alongside, untouched, in case anything else reads it).

## Re-verification pass (2026-07-23) — found and fixed two new bugs

The original pass above only tested registration up through Chinese-name
acceptance, never a post-login command — exactly the gap AGENTS.md §15ae's
standing policy warns about. Re-running the full flow through `look`/
`score`/`quit` surfaced two real, previously-undiscovered bugs in
`adm/single/master.lpc`:

1. **AGENTS.md §15w** (`log_error()` broadcasting every compile *warning*
   to the connected player as if it were a fatal crash): `log_error()` did
   `if(this_player(1)) efun::write(HIW+"\n编译时段错误：" + HIG +message)`
   unconditionally. Since almost every lazily-compiled file in this old
   codebase emits at least one harmless `warning:` (unused locals, `Illegal
   to declare nosave function`, etc.), a freshly registered player's very
   first `look`/`score`/etc. produced a wall of `编译时段错误：...warning:...`
   lines that look exactly like real crashes. **Fixed**: gated the
   broadcast on the message NOT containing `"warning:"` (still logged to
   file regardless), same pattern already applied in `shenmo`/`shenzhou`.
2. **AGENTS.md §4/§15af variant, worse than the exact catalogued shape**:
   `error_handler()`'s `standard_trace()` calls `CHANNEL_D->do_channel(...)`
   unconditionally, and `log_error()` calls `efun::write_file(home +
   "error.log", ...)` unconditionally — both fire the very first time
   ANY compile warning appears anywhere in the preload chain, including
   warnings from `/feature/treemap.lpc` (inherited by `/feature/dbase`,
   inherited by `securd` itself) that fire WHILE `securd` (=`SECURITY_D`)
   is still mid-compile. `write_file()`'s `valid_write()` then tries to
   `load_object(SECURITY_D)` while that exact object is mid-compile — this
   driver forbids that, AND (verified empirically, worse than the §4
   catalog entry's documented shape) **this specific compile-abort
   condition is not catchable at this call site even when wrapped in an
   explicit `catch()`** — it still cascaded into `Error in error handler`/
   `Error in mudlib error handler` noise in `debug.log` on every boot,
   dozens of times, though never reaching a connected player (purely a
   preload-time-only artifact, boot never crashed). **Fixed differently
   from the catalogued §4 pattern**: since `catch()` doesn't help here,
   guarded both calls with `find_object(SECURITY_D)`/`find_object(CHANNEL_D)`
   and skip entirely (not even try) when the target isn't loaded yet,
   rather than try-and-catch. Verified via a clean re-boot: zero `Error in
   error handler` lines anywhere in `debug.log` afterward, across two full
   registration sessions.

Re-verified end-to-end after both fixes: fresh registration (id `sjqftwo`,
real Chinese name `秦岭儿`, gender f) → `look`/`score`/`quit` all produced
correct real output with **zero** `编译时段错误` spam and **zero**
`Error in error handler` lines in `debug.log`. A second session using the
already-registered `sjqfid` (an existing-login re-test) also came through
clean via the password-login path.

## Interactive test result — full registration flow (original pass)

Verified the complete registration path in one continuous connection:

1. Connect → ASCII-art banner + status screen → English-id(ID) prompt.
2. Empty input / an id outside the 3-8 character bound is correctly
   rejected with a clear message and re-prompts (not a bug).
3. `sjitest` → passes `check_legal_id`, reaches the "创造一个新的人物，
   您确定吗(y/n)？" confirmation.
4. `y` → reaches the Chinese-name prompt.
5. **Real Chinese name `萧峰`** → accepted by the fixed
   `check_legal_name` (no rejection message), confirmed via the summary
   screen printing "你的帐号:sjitest / 你的名字:萧峰" — proceeds straight
   to the password-setup prompt. This is the actual proof the §15h fix
   works, not just that the prompt renders.

## lpcc sweep

2642 files, 2474 pass / 168 fail (93.6%). Failure tail is the usual shape
(missing `QUEST_D` daemon accounting for 26 of the 168, a handful of
genuine syntax typos, a few missing headers) — not triaged individually
per AGENTS.md §6b/§13, boot + full interactive registration test is the
verification gate. Memory stayed healthy throughout (~17GB free
consistently, no pressure — this is a small lib).

## Rebuilt-driver / formatter / WASM re-verification pass (2026-07-23)

1. **LPC formatter** (`tools/lpc-syntax/format-corpus.mjs`) applied across
   all 2642 `.lpc` files in `work/`: `{"total":2642,"written":2600,
   "wouldChange":0,"unchanged":20,"errors":22}`. Spot-checked
   `adm/single/master.lpc` afterward — the §4/§15af `find_object
   (SECURITY_D)`/`find_object(CHANNEL_D)` guards and the `"warning:"`
   §15w gate all survived reformatting intact (grepped for the exact
   lines post-format).
2. **Native re-test against the rebuilt `build-debug/src/driver`**: booted
   clean (zero fatal errors, only the usual harmless compile warnings, in
   `log/debug.log`). Full registration verified end-to-end via
   `mudclient.py` with id `sjrfmtc` / real Chinese name **`秦风十`**:
   id → confirm → name → password ×2 → stat-roll accept → email → gender
   → entered the game world at 天狼中心, `look` rendered the room,
   `score` showed a correct character sheet matching the just-entered
   stats, `quit` produced the game's own drop-items-then-disconnect
   sequence. `debug.log` for the session: zero `error in error
   handler`/`denied`/`undefined function`/`bad argument` lines. Confirms
   the reformatted source + rebuilt driver combination is still fully
   sound; no new fixes needed.
3. **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
   boots cleanly (`Initializations complete`, only the expected
   `Undefined function socket_create`/`socket_bind`/`socket_close`
   compile errors from `dns_master.lpc`/`ftpd.lpc` — no sockets package
   under wasm, non-fatal to preload itself). **However, the very first
   live connection crashes**: `adm/daemons/logind.lpc`'s `logon()`
   unconditionally calls `DNS_MASTER->query_muds()` a few lines after
   printing the ID prompt, with no `find_object()`/`catch()` guard.
   Since `dns_master.lpc` failed to compile under wasm (no sockets
   package), that object has no program, and the call throws `*No
   program in object '/adm/daemons/network/dns_master'!`, which
   `new_conn_handler` catches by destructing and disconnecting the
   connection (`logon() on object clone/user/login#0 has failed, the
   user is disconnected`). The driver/harness then re-creates a fresh
   login object and shows the banner + ID prompt a second time, but
   further scripted input in the same harness invocation didn't land on
   this second instance (single in-process connection, not a real
   reconnect) — so a full registration playthrough could not be driven
   to completion via this harness for this lib specifically. Also
   confirmed the already-documented `query_ip_number()` limitation
   independently: "你所在IP" prints blank (rather than `127.0.0.1`)
   under wasm. **This DNS_MASTER crash is a wasm-specific gap, not a
   mudlib bug** — natively the sockets package is present, `dns_master`
   compiles fine, and the call never fails; `shujian2008`/
   `shujiantianxia` share this exact same `adm/etc/preload`-included
   `dns_master` + unconditional `logind.lpc` call shape and hit the
   identical crash under wasm (see their own NOTES.md). Not patched, per
   the task's standing policy for wasm-only gaps — documented here
   instead. **Assessment: boots under wasm; login cannot complete in
   this harness due to a wasm-only dns_master-preload/no-sockets
   interaction, orthogonal to the already-known query_ip_number
   limitation.**

## WASM-enablement pass (2026-07-23)

Standard four-change pass (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback-allow**: `adm/daemons/logind.lpc` `logon()` (~line 149) — the
   `BAN_D->is_banned(query_ip_name(ob))` ban gate and the `iplimit > 3`
   same-IP multi-login cap are now both skipped entirely when
   `query_ip_number(ob)` is empty/non-string/`127.*` (loopback or the
   malformed IP older WASM builds produce). `check_player_allowip()`
   (same file, ~line 510) extended: previously only exact `"127.0.0.1"`
   was always-allowed, now any 127.* / empty / non-string IP passes.
   `adm/daemons/band.lpc` `is_banned()` also short-circuits to 0 for
   loopback/localhost/malformed sites.
2. **Uptime gate**: none active (the `uptime()<10` gate was already
   commented out in the original source). Nothing to do.
3. **Anti-flood throttle**: none present beyond the multi-login cap
   covered in (1).
4. **WASM dns_master crash FIXED** (was previously documented-only): in
   `logon()`, the `if (!find_object(DNS_MASTER))` fallback branch printed
   the banner and prompted for the id but then FELL THROUGH into
   `DNS_MASTER->query_muds()`, crashing every WASM connection (no sockets
   package → dns_master never compiles). Added the missing `return;`
   after `input_to("get_id", ob)`. Native behavior unchanged (daemon
   present → branch not taken).
5. **Admin account seeded**: `fluffos` / `Mud@2026` / 浮浮, granted
   `(zhuguan)` (top rank) via `wiz_status` in `adm/daemons/securd.o`
   (binary-safe edit — file is CRLF, a newline-normalizing edit breaks
   `restore_object()` and zeroes securd's globals; keep \r\n intact).
   Save files: `work/data/login/f/fluffos.o` (account+password),
   `work/data/user/f/fluffos.o` (body). Verified live: password login →
   `update /feature/name.lpc` → 重新编译成功.
6. **Runtime dir**: created `work/log/nosave/` — every `quit` logged a
   caught "Wrong permissions opening /log/nosave/EXP" error without it
   (§7.11 class; log/ is gitignored so this is a local/runtime fix only).

Retest: fresh registration (qftest/秦风, deleted after test) end-to-end OK,
fluffos login + wizard `update` OK, debug.log clean apart from the usual
compile warnings (and the now-fixed /log/nosave/EXP error).

### Retrofit: fail-closed loopback check (2026-07-24)

The loopback-allow gates above were originally written per the (now
superseded) defensive instruction to also treat an empty/non-string/
malformed `query_ip_number()` result as loopback, since older WASM
driver builds returned garbage. That driver bug is now fixed upstream
(`query_ip_number()`/`resolve()` return real values under WASM too), so
the "malformed IP = trust it" fallback was a fail-open bypass with no
remaining justification. Tightened every gate listed above to the
strict pattern: loopback is ONLY `ip == "127.0.0.1"`, `ip == "::1"`, or
a leading `"127."` prefix — a non-string/empty/malformed IP is now
treated as untrusted/remote and subject to the gate normally, not
silently allowed through. Retested: fluffos login (127.0.0.1, real
value under the current driver) still passes every gate; debug.log
stayed clean of `denied`/`undefined function`/`error in error handler`.
