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
xzyx (archive #2) codebase or a shared common ancestor).
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
   `sjtx2` share this exact same `adm/etc/preload`-included
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

## 深度功能测试 / Deep functional test (2026-07-24)

First real *playthrough* pass on this lib per AGENTS.md §10.7 (all prior
passes verified only registration + `look`/`score`/`quit` + admin login,
never a continuous session through movement, sects, skills, a shop, or
combat). Native driver (`build-debug`), one continuous session per
character, `scripts/mudclient.py`. Read `work/doc/help/newbie` first
(this lib's own newbie guide, credited to 天星/1999, is written for the
"星战英雄" game this codebase is branded/forked from — see "What this
is" above) — it documents the `fight`/较量 safe-spar convention, the
`bai`/`xue`/`cha` teacher-apprentice loop, and the sect list (特种部队/
皇族/凤凰星/圣殿) up front, which is exactly what made the rest of this
pass tractable.

**Test characters** (kept, not cleaned up, as playthrough evidence):
- `guanyu` / 关羽 / `TestPass99#` — the main playthrough character.
  Joined 特种部队 (recruited by 蒋师庞, 4th-generation disciple/小队长),
  learned 机器改造 (`jiqi-gaizao`) from him via `xue`, fought and
  **died** to 蒋师庞 via the "safe" `fight` command (see finding below),
  revived automatically at 太空港口 and continued playing normally
  afterward. Ended the session with a clean `quit`. Save files:
  `work/data/user/g/guanyu.o`, `work/data/login/g/guanyu.o`.
- `zhangfei` / 张飞 / `TestPassAA#` — used for the shop-purchase test
  (bought 能量之泉/`Power` at 特种药铺 for 580 electronic currency,
  confirmed in `i`) and for the "reconnect after a real wall-clock wait"
  test. Save files: `work/data/user/z/zhangfei.o`,
  `work/data/login/z/zhangfei.o`.
- Several other throwaway ids (`linfeng`/`chenwei`/`zhaoyun`/`maliang`/
  `sunquan`/`wangjun`) were used earlier in the pass to chase down a
  suspected quit/net-dead race (see "false lead" below) and have been
  deleted again — they added no evidence beyond what `guanyu`/`zhangfei`
  already demonstrate.
- Admin account `fluffos`/`Mud@2026`/浮浮 (already seeded, see
  "WASM-enablement pass" above) was reused for a `goto` teleport attempt
  during the shop hunt; its save file's mtime changed as an incidental
  side effect of a normal reconnect (nothing about its own data was
  intentionally modified).

### Bug found and fixed: `private command_hook` breaks every `command()`-efun self-call (AGENTS.md §8.3a's ORIGIN_EFUN caveat, confirmed on this lib)

`feature/command.lpc:27` had `private nomask int command_hook(string arg)`.
AGENTS.md §8.3a already lists `shiji` as one of the libs where this does
**not** break ordinary typed-command dispatch (confirmed again this pass:
`look`/`score`/`quit`/movement typed directly by a connected player all
worked before this fix, since typed input arrives via `ORIGIN_DRIVER` and
bypasses the privacy check). But §8.3a's own addendum warns not to assume
that finding transfers to other call shapes — and it doesn't here either:
any code that calls the bare `command()` efun **on itself**
(`this_object()` = the object whose own method is running, origin =
`ORIGIN_EFUN`) hits the exact same `DECL_PRIVATE`-once-inherited
permission wall, silently no-oping. Two confirmed, live-reproduced
instances on this lib alone:

1. **`feature/move.lpc:102`** — every room move without brief mode
   (`query("env/brief")` false, the default) ends with `command("look")`
   to auto-show the new room. This silently failed for **every single
   move by every player**, all game long: `debug.log` showed
   `apply() with insufficient permission: ... function: command_hook,
   origin: efun, needs: private, has: hidden` on literally the very
   first `move()` (entering the start room at registration), and again
   on every subsequent walk. Player-visible symptom: no room description
   after moving unless you separately typed `look` yourself — easy to
   write off as "this lib just doesn't auto-look", since nothing ever
   crashed or looked broken, it just silently did nothing.
2. **The entire family/sect-join system** — every sect-master NPC's
   `attempt_apprentice()` (`kungfu/class/budui/{jiang,bei,su,master}.lpc`,
   `kungfu/class/huang/{tian,jiang,jiang2,jiaoguan}.lpc`,
   `kungfu/class/anhei/{sour,deathgod,song}.lpc`, at least 10 copies of
   the identical shape) calls bare `command("say ...")` and
   `command("recruit " + id)` **on itself** to recruit a new disciple.
   Before the fix, `bai <master>` → `attempt_apprentice()` →
   `command("recruit ...")` silently failed every time — a player could
   type `bai` all day and nothing would happen (no error, no rejection
   message, just apparent no-op), because the NPC's own `command()`
   efun call is `ORIGIN_EFUN` on itself, same as move()'s case. This is
   the identical shape AGENTS.md already documents for
   `xzyx` (the game this lib's banner is copyrighted to!)
   — the exact same bug, independently present in what looks like a
   sibling/fork codebase.

**Fix** (the standard §8.3a pattern): dropped `private` —
```lpc
// BEFORE: private nomask int command_hook(string arg) {
// AFTER:  nomask int command_hook(string arg) {
```
Single choke point, `feature/command.lpc:27`; no other file needed
changing since every command dispatch (typed AND self-`command()`)
funnels through this one hook.

**Verified live, before/after**:
- Before: `debug.log` had 4 `insufficient permission ... command_hook`
  lines after nothing more than 3-4 fresh registrations (each one's
  first `move()` into the start room). `bai jiang jipang` against 蒋师庞
  (特种部队's recruiting sergeant, no skill gate) produced only the
  "$N想要拜$n为师" pending message and then **nothing** — no `recruit`
  response ever arrived, exactly matching "attempt_apprentice's
  command() silently no-ops".
- After: restarted the driver, fresh `guanyu` registration through the
  same NPC. `south`/`north`/`east`/`west` all auto-printed the new
  room's description with zero further `debug.log` errors. `bai jiang
  jipang` produced the full live sequence: "你想要拜蒋师庞为师。蒋师庞
  说道：好吧，我就收下你了。...你跪了下来...恭喜您成为特种部队的第四
  代弟子。", confirmed via `score` showing title "特种部队第四代小队长"
  and "师傅: 蒋师庞". `xue jiang jiqi-gaizao` (organic teacher-NPC skill
  path) afterward correctly taught 机器改造, confirmed via `cha`. Zero
  `insufficient permission` lines in `debug.log` for the rest of the
  session (several more registrations, sect joins, a full combat/death/
  respawn cycle, multiple quits and reconnects).

This is not a new bug class — it's an additional, live-confirmed
instance of AGENTS.md §8.3a's `command()`-self-call variant (first found
on `xuanjianlu`'s `call_out`-dispatched flavor; this is the more direct
"NPC's own `attempt_apprentice()` calling bare `command()`" flavor
already anticipated by that section's wording). Worth flagging in case
whoever reads this next assumes §8.3a's "shiji is an empirical exception"
note means `private command_hook` is a non-issue here — it only doesn't
break *typed* commands; it silently breaks *every* self-referential
`command()` call in the lib, which turned out to be both the auto-look
feature and the entire sect-recruitment system.

### Serious finding, NOT fixed here: one-time driver FATAL crash, cause not conclusively established

About 20 minutes and several dozen commands into this pass (well after
the `command_hook` fix above, during an admin (`fluffos`) reconnect +
`goto` attempt, unrelated on its face to anything just typed), the
native driver crashed the whole process:

```
******** FATAL ERROR: FATAL: Object 0x5620bc786ce8 /cmds/skill/recruit
ref count 0, but not destructed (from free_svalue).
(current object was /clone/user/user#32)
--- frame 1 ---
Object: /adm/daemons/logind, Program: /adm/daemons/logind.lpc
   in reconnect() at /adm/daemons/logind.lpc:926
arguments: [/clone/user/login#91, /clone/user/user#32 ("浮浮"), 0]
```

This is a driver-level reference-count assertion failure, not a caught
mudlib runtime error — it took the entire process down (`Connection
refused` on the next connect attempt), unlike every other error class in
this catalog which the driver's error handler swallows. `cmds/skill/
recruit.lpc` is exactly the shared, non-cloned, `inherit F_CLEAN_UP`
command file that the fix above newly made reachable via `command()`
efun calls from NPC code (previously always silently blocked). Plausible
mechanism (not confirmed): `F_CLEAN_UP`'s `clean_up()` self-destructs a
shared command object once it has no `environment()` and no interactive
inventory — if the driver's own periodic clean-up sweep destructs the
shared `recruit.lpc` master at some point after a `command("recruit
...")` call chain has left some structure (a `call_out`, a stale
mapping entry) still holding a reference to it, a later access could
plausibly produce exactly this "ref count reached 0 without an explicit
`destruct()`" driver-internal inconsistency. This is a hypothesis, not a
verified root cause.

**Why not fixed here**: this is a driver (`~/src/fluffos`) internal
reference-counting bug, not mudlib LPC source — fixing it blind, under
this task's time budget, without being able to reliably reproduce it
(see below), would be guessing at C++ interpreter internals. Per
AGENTS.md §12 conventions, driver-level issues belong in the fluffos
checkout, not patched per-mudlib.

**Reproduction attempts**: tried twice more to reproduce by repeating
the exact `bai`/`recruit` sequence on a fresh character (`zhangfei`)
immediately after a driver restart — no crash either time, and the rest
of this pass (including a full combat/death/respawn cycle, several more
quits, several netdead reconnects) ran for another ~15 minutes total
without a repeat. **Not reliably reproducible in this pass** — logged
here as a serious but low-frequency, timing-dependent finding for
whoever next touches this lib's WASM packaging or does a long-sit
soak test (AGENTS.md §10.0), rather than presented as fixed. If it
recurs, capture a fresh trace (the object address and exact frame will
differ) and compare against this one before assuming the same root
cause.

### What was tested and confirmed working

- **Registration**: real Chinese names (关羽, 张飞) through the full
  flow (id → confirm → name → password ×2 → talent roll/accept → email →
  gender) — already known-good, reconfirmed.
- **Movement/exploration**: walked from 天狼中心 (start) through the
  city's side streets, the sect-selection hub (`/d/city/startroom`,
  `太空总处`), and a multi-room trek down into 特种部队's zone (`luxingchu`
  → `bdguangchang2` → `bdguangchang1` → `bdguangchang` → `ondidao` →
  `rukou`/入口) — every room's `long`/exits rendered correctly, and
  (post-fix) every move auto-printed the destination room.
- **Sect join** (`bai`/`recruit`, organic NPC path): `bai jiang jipang`
  against 蒋师庞 in 特种部队's 入口 succeeded, assigning family
  "特种部队" generation 4, title "特种部队第四代小队长" — confirmed via
  `score`.
- **Skill learning** (organic teacher-NPC path, `xue`/`cha`): after the
  `bai` above, `xue jiang jiqi-gaizao` taught 机器改造 (skill level
  1/0), confirmed via `cha`.
- **Shop purchase**: at 特种药铺 (off 特种部队联盟镇第二层), `list`
  showed 能量之泉(580)/最终能量之泉(1000), `buy power` correctly
  deducted money and added the item, confirmed via `i`.
- **Combat and death**: used the lib's own documented safe-sparring
  command, `fight <target>` (`cmds/std/fight.lpc`, help text promises
  "点到为止...不会真的受伤" — stamina-only, no real injury), against
  蒋师庞. Contrary to that promise, `guanyu` (a fresh level-0 character)
  was actually killed in a handful of rounds (蒋师庞's gun attack put him
  in "已经受伤过重" and then "你光荣牺牲了") and moved to the death realm
  (鬼门关). **Not confirmed as a conversion bug** — `fight_ob()`'s halt
  condition is keyed off 气/精 (stamina-type resources), not 生命力
  (HP), per the lib's own newbie-help wording ("当任何一方的气或精跌到
  50%或以下...打斗便会停下来"), so a wildly mismatched opponent (a
  level-3 中队长 with a weapon and 200,000 combat_exp vs. a level-0
  fresh character) can plausibly still land a lethal HP hit before the
  stamina-based halt would ever trigger — this reads as a genuine gap
  between the help text's blanket "不会真的受伤" promise and the actual
  mechanic (which only prevents a *mutual-agreement* stalemate, not
  guaranteed survival), most likely predating this project's conversion
  rather than introduced by it. Noted here rather than silently passed
  over, but not fixed, since diagnosing which side (the help text or the
  halt condition) is "wrong" would require reading the entirety of
  `combatd.lpc`'s halt logic, which this pass's time budget did not
  cover. Death/respawn itself worked correctly regardless: `guanyu` was
  automatically revived at 太空港口 (a fixed respawn point) with HP
  recovering normally afterward, and the rest of the session continued
  without incident.
- **Quit, `debug.log` grep**: every `quit` in this pass (allowed to run
  the full 3-second `later_quit` call_out to completion) produced zero
  new `error`/`Too deep recursion`/`error in error handler` lines in
  `debug.log` — only the pre-existing harmless lazy-compile `warning:`
  lines.
- **Unclean disconnect (net-dead) and reconnect**: repeatedly closed the
  raw socket without `quit` (simulating a client crash/network drop) and
  reconnected both promptly (a few seconds later) and after a real
  30+-second wall-clock wait. Every reconnect correctly went through
  `logind.lpc`'s `netdead` branch (`user->query_temp("netdead")` →
  `reconnect(ob, user)`), printed "重新连线完毕", and resumed the
  player in their exact pre-disconnect room with inventory/family/skill
  state intact — no §7.20-style void-stranding, no permanent "already
  online" lockout. **One real login-flow quirk worth documenting for
  future scripted testing of this lib** (not a bug): after the password
  is accepted, `logind.lpc`'s `get_passwd()` prints "系统确认！请按
  ENTER进入！" and does a SECOND `input_to("get_passwd_ok", ...)` before
  actually logging in/reconnecting — a scripted client that doesn't
  send one extra blank line here has its first real game command
  silently consumed as the "press enter to continue" line instead
  (looks exactly like "the first post-login command did nothing", which
  cost significant time to correctly diagnose during this pass before
  realizing it was a scripting gap, not a mudlib bug — see AGENTS.md
  §8.2's standing lesson).
- **Quit-then-reconnect after a real wait, clean-quit case**: `zhangfei`
  was `quit` cleanly (full 3-second grace window observed), then
  reconnected after an actual 35-second wall-clock wait (past the
  30-second same-id relogin throttle) — correctly went through a fresh
  (non-netdead) login and resumed at the exact pre-quit room (特种药铺),
  confirming `later_quit`'s `startroom` save works correctly for a
  normal, uninterrupted quit.

### False lead worth recording (no bug, wasted significant time)

Early in this pass, a `quit` immediately followed by an abrupt socket
close (before the 3-second `later_quit` call_out fires) appeared, twice,
to leave the character permanently "stuck" (repeated "已经在线，是否
踢掉？" kick-confirmation loops on reconnect that never resolved
cleanly). This looked exactly like a new instance of the §7.20 net-dead
class and consumed a large fraction of this pass chasing it, including
temporary `efun::write_file()` instrumentation added to and then
reverted from `cmds/usr/quit.lpc` (no trace of that instrumentation
remains — reverted to the original source, diffed clean). Result: **not
reproducible** — three deliberate, instrumented repeats of the identical
"quit, then close the socket before 3 seconds elapse" sequence all
completed `later_quit()` correctly (verified via write-file tracing that
`link_ob` legitimately goes stale when `net_dead()` fires first, but the
function still reaches its trailer and destructs the player normally
regardless). The two "stuck" instances earlier in the pass are most
likely explained by reconnecting *during* the pending 3-second window
itself (a genuine edge case: the reconnect attempt's own "kick the old
session?" flow racing a `later_quit()` that's about to destruct the very
`user` object the kick-prompt is holding a reference to) rather than any
issue with a delayed disconnect per se — not chased further given the
time already spent and the inability to get a clean repro. Recorded here
so nobody re-treads this exact investigation from scratch.

### Not verified live

Everything in the §10.7 checklist was reached this pass except:
- **PK / player-vs-player combat**: only one character was active at a
  time in every test session, so player-vs-player `kill`/`fight` was not
  exercised. Code-reviewed only (`cmds/std/fight.lpc`'s `userp(obj)`
  branch, requiring mutual `fight` consent).
- **The `fight`-vs-death help-text discrepancy** above: observed and
  documented, but not root-caused inside `combatd.lpc`.
- **The FATAL crash's exact trigger**: documented with full trace above,
  hypothesis given, not conclusively reproduced or root-caused (driver
  internals, out of scope for a mudlib-level fix).

## WASM 修复摘要（迁移自 meta.json 的 group_note）

Century/adm-single 家族（自定义 securityd ACL 表）。状态已从过时的 limited 修正——这份档案自己的 README 里从未记录过任何缺陷说明，本轮重新测试也没有发现：管理员登录（fluffos/Mud@2026）干净正常，画面上确认了这份档案自己的顶层巫师称号字符串（"★目前权限：〖宇宙特警〗(zhuguan)"，通过 /adm/daemons/securd.o 的 wiz_status 映射授予，而不是 wizlist 档案）。

## §7.86 跨库扫描修复（留言板 `post` 崩溃）

- **`BULLETIN_BOARD`、`W_BOARD` `inherit` + 多余 `replace_program()` 致命形状（AGENTS.md §7.86，`post` 命令崩溃）**：全档案 19 处命中，已删除多余的 `replace_program(...)` 调用（保留 `inherit`），逐文件保留原有行尾格式（CRLF/LF 按文件原样）。本次为跨库 §7.86 扫描修复（触发原因：该 bug 已在 6+ 个互不相关的血统家族独立确认，属于近乎普遍的拷贝粘贴模式），仅做编译检查（驱动干净启动、端口正常监听），未做完整 §10.7 深度游玩测试。

## 深度功能测试第二轮 / Deep functional test round two (2026-08-15, post driver-upgrade re-test)

驱动于 2026-08-12 升级后的重测。标准检查清单发现并修复三处问题：

1. **`cmds/app/update.lpc`（AGENTS.md §7.106）**：`present(file,
   environment(me))` 缺少 `environment(me) &&` 前置防护，补上。
2. **`adm/simul_efun/file.lpc`**：`log_file()` 没有 `assure_file()`
   目录预建保护，补上调用及前向声明；`cat()` 补上
   `read_file() || ""` 空值防护。
3. **`clone/user/user.lpc::reconnect()`（AGENTS.md §7.108，本轮在
   `shenzhou` 发现的同一类 bug——第二条独立确认的血统）**：本档案的
   `adm/daemons/logind.lpc` 同样有 `exec(old_link, user);
   destruct(old_link);` 踢掉重复登录的写法，而 `reconnect()` 逐字节
   与 `shenzhou` 修复前的版本一致——完全没有 `enable_commands()`。
   按 §7.108 记录的写法预防性加了同一行修复（未先在本档案单独复现
   修复前的崩溃再修——鉴于代码逐字节一致，直接套用已在 `shenzhou`
   验证过的修法），现场用两个真实连线复现"保持第一个连线不断开→第
   二个连线登录→答 y 踢掉旧连线"的完整流程做修复后验证：`score`
   立即正常显示完整角色档案，确认修复本身不会引入新问题。

`master.lpc::log_error()` 已经是正确的 `"arning:"` 大小写无关写法，
`maximum evaluation cost` 已经是 `5000000`，均无需改动；本档案无
`adm/daemons/closed.lpc`，不受 §7.107 影响。

### 现场验证摘要

驱动干净启动，管理员 `fluffos`/`Mud@2026` 登录确认权限
`〖宇宙特警〗`，`update /adm/daemons/logind` 成功验证真实写入权限。
踢掉重复登录重连路径现场验证通过（见上）。`debug.log` 全程干净
（507 行，无真实错误）。

### 本轮修改的文件

- `work/adm/simul_efun/file.lpc`
- `work/cmds/app/update.lpc`
- `work/clone/user/user.lpc`

## §7.100 sweep (2026-08-19)

Fixed the corpus-wide `inherit ROOM; ... replace_program(ROOM);` redundant-replace bug (AGENTS.md §7.100). 378 live occurrences deleted: 374 via scripted sweep (`fix_710_room.py`), plus 4 hand-fixed irregular shapes identical in shape to sibling lib `sj` — `clone/misc/roommaker.lpc`'s string-builder, two copies of `d/fenghuang/fenghuang/taikong.lpc` (space before semicolon), and `d/huang/zoulang4.lpc` (two redundant calls on one CRLF line). 4 already-commented-out instances left untouched. No real `.lpc` source found under `work/data/`. Verified via `build-debug` driver boot: clean compile, port 40026 listening, zero new "cannot replace"/"cannot bind" debug.log lines.
