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

## §7.30 uninitialized-mapping accessor sweep (2026-08-20)

Corpus-wide mechanical sweep of the `feature/skill.lpc` shared-lineage
bug (confirmed independently on `xiakexing2017`/`jqxz2015`/`haiyang2`
via round-four testing): 4 accessor(s) in this file returned a raw
never-initialized `mapping` instance variable (defaults to `int 0`,
not `([])`, until first assigned), crashing any unguarded
`keys()`/`sizeof()`/indexing caller for a fresh/untrained character.
Fixed at the accessor level (`mapp(x) ? x : ([])`) per the documented
remedy. Verified via `lpcc --batch` static compile check only (not a
live boot) as part of a large mechanical sweep; not individually
functionally re-tested live on this lib.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 1 here-document block(s) repaired (1 with the terminator glued to the last text line, 0 with it indented), so `End of file in text block` no longer hides the room or object behind them: `u/xinyi/bedroom.lpc`. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply shiji`: 178 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 1 ambiguous. Load check of the 241 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 24 PASS -> 173 PASS, 0 that loaded before fail now, 149 more load.

178 files moved (164 `.C`, 9 `.lpc`, 5 `(none)`); mostly under `u/zhangm/fenghuang` (99), `u/SEAKING/NPC` (3), `u/SZY/ROOM1.C` (1), `u/ZXCDZXCD/BANK.C` (1). A rescan with `scripts/lpc_warnings.py shiji` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-05）— room base survives a raising NPC

`scripts/lpc_resilient_room.py --apply`: `make_inventory()` of `inherit/room/room.lpc` loads each inventory object as `if (catch(ob = new(file)) || !objectp(ob)) return 0;`. `new()` of a file that is not there returns 0 (the room just lacks that NPC), but `new()` of a file whose `create()` raises (a skill file for `set_skill()` this archive never had, a `carry_object()` item that is not there, a header that never shipped) raised inside the room and the room did not load at all. The wrong-case renames of this lib (the section above) make the NPCs behind them reachable for the first time, so a room that holds one with such a content gap would have gone from "NPC missing" to "room missing"; now it loads without that NPC, as it did before. The room base compiles and loads with the change (HEAD against the working tree). KB 03 §4.5.

## 深度功能测试（§10.7，2026-10-05）— 房间列出的物件缺档时房间照常加载

房间基类 `inherit/room/room.lpc`：`reset()` 的 `case 1:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]])) break;`）；`reset()` 的 `default:` 拿到 0 就跳过这一项（`if (!objectp(ob[list[i]][j])) continue;`）。档案里没有的 NPC 或物品（或 `create()` 出错的物件）原先会让列出它的房间整个加载失败（`Bad argument 1 to environment()`，或对 0 的 `call_other()`），连带这个房间后面的区域；现在房间照常加载，只是少了那个物件，下次 `reset()` 再试（KB 05 §7.25；`scripts/lpc_resilient_room.py`、`scripts/lpc_room_reset_guard.py`）。
验证：探针（`scripts/lpc_room_reset_probe.py`：房间基类列出一个不存在的物件，再调用 `reset()`）HEAD 单件 崩溃、多件 崩溃，工作树 单件 OK、多件 OK。

## 深度功能测试（§10.7，2026-10-07）— 编译警告整理

`scripts/lpc_warnings.py shiji --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 354 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：323 -> 323 通过，无回退。`smtp/smtp_d.lpc` HEAD 起就编译不过，这里只删了未用的 `newbie_reg`（已看过）。启动时警告 40 -> 0；新进程登录（新人物确认）正常。

- 2026-10-10：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 3 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 0 个，只在 #if 分支用的声明移进分支 0 个文件；改动 2 个文件，HEAD 与工作树各载入一次无回退（2 objects; HEAD PASS 2, tree PASS 2; regress 0; newly loading 0），这些文件的警告 3 -> 0。

## 编译警告收尾（2026-10-12）

`scripts/toolkit_fix.sh` 一轮（冗余继承 12 处，覆盖函数 2 个）加手工收尾，能编译的文件警告清零。改动的 24 个对象 HEAD 与工作树各载入一次：HEAD PASS 23，tree PASS 23，regress 0。

- `clean_up()` 两条路进来（`F_BANKER`/`F_SSERVER` 与 NPC/武器基类都带 `F_CLEAN_UP`）：钱庄老板 5 个、`d/death/god1.lpc`、两把刀等 9 个文件用 `lpc_name_winner.py` 写明驱动本来就选的那个。
- `d/shendian/npc/mentu.lpc`：一个空的全局 `string *skills = ({});` 与 `F_SKILL` 的技能表 `skills` 同名，`create()` 用的是自己的局部变量，删去空表。
- 未改：`include/daemons.h` 是从 Lima 带来的头文件（`/daemons/channel_d` 等路径本库没有），只被编不过的 `adm/daemons/network/ms.lpc`、`mail_serv.lpc` 包含，那里报的宏重定义不在能编译的文件里。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。1 个文件 1 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14（同一次重扫）：`include/daemons.h` 里重定义的宏先 `#undef`。

- 2026-10-14：1 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。驱动忽略返回值的 apply（`init`、`reset`、`heart_beat`、`create`）里改成空 `return;`（`return ::init();` 改为 `{ ::init(); return; }`，调用照旧）。新进程比对 HEAD 与工作树：1 个对象，新增载入 1，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

## 内力/精力当作伤害种类（2026-10-15，KB 06 §7.241 第二类）

本库 `feature/damage.lpc` 的 `receive_damage()` 不接受 `jingli`/`neili`/`force` 等种类，`me->receive_damage("jingli", 30)` 之类在练功、绝招、吸取时报 `F_DAMAGE: 伤害种类错误`。2 处改为 `add(type, -N)`（`scripts/lpc_fix_damage_calls.py` 第二步）。

## 无门派玩家的 family 映射（2026-10-15，KB 05 §7.30 第三种）

`mapping fam = ob->query("family");` 之后直接 `fam["family_name"]`：没有门派（新人或叛师后）的玩家在学习、练功、拜师、进入门派房间时报 `Value being indexed is zero`，而不是作者写好的提示。1 处在声明行加上 `if (!mapp(fam)) fam = ([ ]);`（`scripts/lpc_fix_family_guard.py`）。


## 东方故事/西游记体系的技能文件（2026-10-15，KB 06 §7.241 第三类）

这些 `kungfu/skill` 文件来自 gin/kee/sen/force 体系，本库人物只有 jing/qi/neili：`receive_damage("kee", 30)` 报 `伤害种类错误`，`query("force")` 永远为 0，技能学不了也练不了。按 kee→qi、gin/sen→jing、force→neili、max_force→max_neili、force_factor→jiali 改了属性名（`scripts/lpc_port_es_props.py`），共 1 个文件。

## 其他体系的属性名（2026-10-15，KB 06 §7.241 第三类，`--any-file`）

另有 1 个文件（绝招、状态、物品、NPC 等，不限于 kungfu/skill）来自 gin/kee/sen/force 体系，同样按 kee→qi、gin/sen→jing、force→neili 改名（`scripts/lpc_port_es_props.py --any-file`）。

## 所有状态都指向自动存盘守护进程（2026-10-15，KB 06 §7.244）

原档 `include/globals.h` 写的是 `#define CONDITION_D(x) ("/adm/daemons/autosaved")`：F_CONDITION 把每一种状态（中毒、监禁、杀人犯标记……）都交给 autosaved 处理，它在 `sys` 频道广播 `Auto_save has been started`、几次心跳后给所有在线玩家存盘，并返回 0 让原来的状态立刻消失。`kungfu/condition` 里的 46 个状态文件从未被调用过。改回 `("/kungfu/condition/" + x)`（定时存盘另由 `natured.lpc` 的 `auto_save` 负责）；这些状态里沿用东方故事体系的毒同时按 kee→qi、gin/sen→jing 改名（`scripts/lpc_port_es_props.py --any-file`）。实测：中火玫瑰毒一次心跳扣 10 点气、20 点精上限。

## `message_vision(msg, environment(me), me)`（2026-10-15，KB 06 §7.242）

把房间当成了动作者：`message_vision()` 取房间的 `name()` 得 0，`replace_string(msg, "$N", 0)` 报错。在状态（中毒）里，这个错误发生在 `apply_condition(name, duration - 1)` 之前，状态永不结束，心跳里后面的恢复也每次被跳过。改为 `message_vision(msg, me)`：`/d/jianyu/npc/yuzu`、`/d/jianyu/yuzu`、`/kungfu/class/budui/shitailong`。

## 技能按另一门武功的等级取招（2026-10-15，KB 06 §7.243）

这些技能文件是从别的武功复制改名来的，`query_action()` 仍用原武功的等级查招式表：只会本技能的人等级为 0，取不到招，每次出招都报错。改为读本技能自己的等级（`scripts/lpc_fix_action_level.py`）：`duzun-shou`。

## 空手使用兵器绝招（2026-10-15，KB 06 §7.246）

`perform` 指令允许直接点名招式（如 `perform stick.ban`），这些绝招读了 `me->query_temp("weapon")` 却从不检查，空手时 `weapon->name()` 报错（有的已先扣了内力）。在赋值后补 `if (!objectp(weapon)) return notify_fail("你必须手持兵器才能使用这一招。\n");`（`scripts/lpc_fix_perform_weapon.py`）：`wuyue-blade/jiao`。

## 把经验、属性、内力当技能读（2026-10-15，KB 06 §7.247）

经验、属性、内力上限不是技能，xkx/ES 的 `query_skill()` 对它们只返回 0（风云的还会去载入同名技能文件而报错）。改为 `query("...")`（`scripts/lpc_fix_pool_as_skill.py`）：`liancheng-jian/ci`、`liancheng-jian/erguang`（`random(me->query_skill("combat_exp")) > target->query_skill("combat_exp")` 恒为 0 > 0，这一招永远不成功）。

## 圣火令法「吸焰令」从未编译通过（2026-10-15）

`shenghuo-lingfa/xiyanling` 原档 `else if (!objectp(weapon = target->query_temp("weapon"))` 少一个右括号，文件编译失败，这一招从来用不了；后面的兵器判断 `skill_type != "tieling" || skill_type != "shenghuo-ling"` 恒为真，就算编译通过也只会说“你使用的武器不对”。补上括号，兵器判断照同目录的 `duo` 改为 `skill_type != "lingfa"`（本库的铁令、圣火令都是 lingfa 类兵器，`shenghuo-lingfa` 也只能 enable 为 lingfa）。

## 技能名拼错（2026-10-15，KB 06 §7.249）

`query_skill()` 里的技能名拼错了，或用的是本库改名前的旧名；本库没有这个技能，调用永远得 0：门槛（`< N` 就拒绝）永远过不去，相关功夫或绝招学不了、用不了；内功互斥（`> N` 就拒绝）从不生效；公式里这一项一直是 0。经汉字名（提示文字或中文名词典）或纯拼写差异（`_`/`-`、少一个连字符、相邻字母颠倒）核对后，改为本库的技能名（`scripts/lpc_fix_skill_typo.py`）：`yan-fly`→`yanfly`（`yanfly`）。

## 柔云步法「柔云纵」有时报错（2026-10-15，KB 06 §7.251）

`rouyun-steps/zong` 随机把人送到三个房间之一：精、精力已经扣了，“乘云而去了”也说了，送不过去时人留在战斗里并报错。本库的城市（都市中心）也没有 `/d/city/wumiao`、`/d/city/kedian`，三处都会报错；改用本库的 `/d/city/guangchang`（都市中心）和 `/d/city/jiudian`（星际大酒店）。


## 银索金铃「点穴」对空手的对手报错（2026-10-15，KB 06 §7.246）

`yinsuo-jinling/dian` 失手时三种描写之一是“真气贯注”加对手兵器的名字，对手空手时 `ob` 为 0，三次失手有一次报错。改为 `(objectp(ob) ? ob->query("name") : "全身")`（泥潭一系原本就写作“真气贯注全身”）。

## family 映射内联取下标（2026-10-15，KB 05 §7.30）

`ob->query("family")["master_name"]`、`me->query("family")["family_name"]`（泥潭式为 `query("family", ob)[...]`）直接对门派映射取下标：没有门派的人（新玩家、叛师者、大多数 NPC）在 NPC 的打招呼和问话、绝招的门派判断、房间的 `valid_leave` 里报 `Value being indexed is zero`，而不是得到拒绝。6 处（6 个文件）改为 dbase 路径查询 `query("family/master_name")`：有门派时值相同，没有时得 0；原有的判断照常生效（`scripts/lpc_fix_family_index.py`）。给映射赋值的写法未动。


## 血刀刀法「祭血神刀」正神时报错（2026-10-15，KB 06 §7.241）

`xue-dao/shendao` 的伤害是 `random(shen / -1000) + shen / -3000`，越邪恶伤害越高；正神的人算出负数，`receive_damage()` 报“伤害值为负值”。补 `if (damage < 0) damage = 0;`，设计不变（正派用不出伤害），不再报错。

## NPC 带着本库没有的物品，载入失败（2026-10-15，KB 06 §7.73）

8 个文件、11 处在 `create()` 里 `carry_object("<本库没有的文件>")->wear()`（或 `wield()`、`set_amount()`）：`carry_object()` 得 0，接着的调用报 `Bad argument 1 to EFUN call_other()`，NPC 根本载入不了，该有它的房间里就少了这个人。多是从别的系统搬来的 NPC 用了原系统的物品路径（最常见：`/d/shaolin/obj/changjian`、`/d/city/obj/gangjian`、`/d/diyu/obj/long-jian`）。每处改为 `{ object carried_ob = carry_object(...); if (carried_ob) carried_ob->wear(); }`（`scripts/lpc_guard_carry_object.py`）：NPC 照常出现，只是不带这件东西；文件补回来（或是虚拟对象）照样会带上。载入检查：改动的文件改前能载入 0 个，改后 3 个（3 个原来载入不了），没有退步；其余 5 个另有原因（多为 `set_skill()` 了本库没有的武功）。

## 物品清单把名字的第一个字吃掉（2026-10-18，KB 07 §8.1）

`inventory`、房间的物品列表（`feature/move`）和部分 `look` 把同名物品合并计数，键是 `query("unit") + short()`，只有一件时按 `key[2..]` 去掉量词。量词是一个汉字，在原来的 GBK 里占 2 字节，`[2..]` 正好去掉量词；转成 UTF-8 以后一个汉字只占一个下标，这一刀把名字的第一个字也切掉了（「把长剑」只显示「剑」，带颜色的名字切掉的是转义序列开头）。改为 `[1..]`（`scripts/lpc_fix_unit_cut.py`）：`cmds/std/look2.lpc`。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 5 个对象设了本库没有文件的武功（13 个名字，最多的是 `qiankun-danuoyi`、`bibo-shengong`、`anying-fuxiang`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：5 个里 5 个通过。（`scripts/lpc_guard_set_skill.py`）

## 通向不存在房间的出口，按对面房间的回头出口改正（2026-10-18，KB 06 §7.257）

房间出口 `"west": __DIR__"xxx"` 指向的文件本库没有，玩家走过去就被卡住（笔误、改过名的房间，或者没带进档案的编号房间）。对面的房间存在、并且它相反方向的出口正好指回这个房间，说明出口原本就是通向它：`/d/ziyang/ziyanggong/guankou` 的 `east`：`street2` → `/d/ziyang/ziyangcheng/street1`。改动后每个出口都能解析到本库的文件（`scripts/lpc_fix_dead_exits.py`；目标在运行时本来就能载入的库——虚拟房间——不动）。

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 2 处、2 个文件：`xinxiu-duzhang`→`xingxiu-duzhang`（1 处）、`shujian-yidong`→`shunjian-yidong`（1 处）。（`scripts/lpc_fix_skill_names.py`）

## 调用了父类没有的函数的对象（2026-10-19，KB 06 §7.259）

`::create();`、`::init();`、`return ::buy_object(who, item);` 这类调用写的是父类里有这个函数的版本；本库的父类没有，旧驱动把它当空操作（返回 0），现在的驱动在编译时就报 `Unable to find the inherited function`，整个对象载入不了。单独成句的调用删掉，`return ::f(...)` 改成 `return 0;`（void 函数里是 `return;`），与旧驱动的行为一致。共 1 处、1 个文件：`::setup()`（1 处）。只改了出错原因全是这一类的文件；还带着别的错误（多半是父类本身没了）的文件没动，等父类补回后再看。（`scripts/lpc_fix_dangling_super.py`）

## 一行写完的源文件还原（2026-10-19，KB 06 §7.272）

下列 5 个文件的整个源码挤在开头的一行 `//` 注释里（档案的编辑器丢了换行），驱动只编译出一个空程序，物件载入后没有名字、没有 id、拿不到手上：`/d/fenghuang/fenghuang/obj/junfu.lpc`、`/d/fenghuang/fenghuang/obj/junfu1.lpc`、`/u/zhangm/fenghuang/fenghuang/obj/junfu.lpc`、`/u/zhangm/fenghuang/fenghuang/obj/junfu1.lpc`、`/u/zhangm/fenghuang/obj/junfu.lpc`。`scripts/lpc_uncollapse.py` 按语句、语句块、`#include` 重新分行，再过一遍格式化。还原后逐个载入没有退步，`new()` 出来的物件有名字和属性。

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 玩家打造兵器模板没有打造者时（2026-10-19，KB 06 §7.275）

`/d/npc/obj/m_blade.lpc`（共 1 个）的 `create()` 开头 `me = this_player();` 之后无条件读 `me->query("weapon/name")` 等打造数据。房间刷新时没有人在场（`me` 为 0），或者 NPC 在别的 NPC 的命令环境里 `carry_object()` 这个模板（NPC 的 `weapon` 属性是文件名字符串），旧驱动里读出来是 0 或字符串，`switch` 照样落到 default；新驱动报 `Bad argument 1 to EFUN call_other()` / `Bad argument 1 to switch`，NPC 和它所在的房间载入不了（`--walk` 普查里一个玩家走进房间就触发）。在 `//读入数据` 之后加 `if (!me || !mapp(me->query("weapon"))) { setup(); return; }`：没有打造者就留一个没有名字的空模板，玩家打造的流程不变。

## `== !"字符串"` 多出来的 `!`（2026-10-19，KB 06 §7.280）

`!"taoist"` 是整数 0，`x == !"taoist"` 就是“x 等于 0”，作者为其余所有人写的那一支永远走不到。具体是：性别检查（“你不是女的，无法领会其中至阴之理”）永远不拦人，男的照样能学玉女心法。全部改成 `!= "字符串"`（`scripts/lpc_fix_not_literal_cmp.py`）：`/kungfu/skill/yunu-xinfa.lpc`（1 处）。同样的行在 xkx 一系的 35 个库里都有。

## `x != "a" || x != "b"` 和 `x == "a" && x == "b"`：同一个值的比较链永远成立/永远不成立（2026-10-20，KB 06 §7.282）

`if (arg != "wan" || arg != "丸") return notify_fail(...)` 对任何 `arg` 都为真，`dir == "south" && dir == "north"` 永远为假：条件下面的守卫要么永远拦、要么永远不拦。作者要的是“既不是 A 也不是 B”（`&&`）或“是 A 或 B”（`||`）。`!=` 链的 `||` 改成 `&&`（仅当条件下面是 `return` 的拒绝/守卫），`==` 链的 `&&` 改成 `||`（`scripts/lpc_fix_cmp_chain.py`）。改动：`/d/city/xiaolu1.lpc`（1 处）。

## `boss` 指令：`/open/shit.txt` 不在存档里，`write(0)` 报错（2026-10-20，KB 06 §7.285）

`boss 1` 先清屏、屏蔽所有消息，再 `msg = read_file("/open/shit.txt"); write(msg);`。`/open/` 是巫师目录，存档里没有这个文件，`read_file()` 返回 0，`write(0)` 报 `Bad argument 1 to receive()`，玩家的屏幕还被屏蔽着。改为 `if (stringp(msg)) write(msg);`（`cmds/usr/boss.lpc`）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 7 处）。改动：`/adm/daemons/logind2.lpc`（2 处）、`/cmds/adm/watch.lpc`（1 处）、`/d/fenghuang/fenghuang/npc/mj.lpc`（3 处）、`/d/tianlang/npc/mei_po.lpc`（1 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/single/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## 访客计数 `howmany_visitor()` 读文件不检查（2026-10-20，KB 06 §7.301）

`howmany_visitor()` 读访客计数文件（`VISITORS` / `COUNTER` / `BBSVISITOR`，只有运行中的 mud 才会写；`.gitignore` 把它排除在仓库之外），新检出的树里没有，`read_file()` 回 0，`sscanf(0, ...)` 报错。这份副本登录时不一定走到它，但调用时同样会出错。在读文件之后加了 `if (!stringp(content)) return 0;`（xkx100、xiakexing100、zzfy 早先的写法，`scripts/lpc_fix_visitor_count.py`）。改动：`/adm/daemons/logind.lpc`。

## 首次登录时 `cp()` 缺失的模板文件（2026-10-20，KB 06 §7.310）

同 sj：`toptend::query_top()` 的 `cp(TOPTEN_SOURCE, TOPTEN_FILE)` 面对压缩包没带的 `topten/source` 会抛错（`lstat failed`）。在 `cp()` 前加了 `file_size(TOPTEN_SOURCE) < 0 ||`。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库现有的 NPC 文件里没有字面写成空 `chat_msg` 的（扫描只认 `set("chat_msg", ({ }))`）；守卫挡的是运行时才为空的列表和以后新增的 NPC。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/inherit/char/npc.lpc`（共 1 个文件）。

## `blockade` / `recover`：`data/keep` 不存在，解封之后世界仍然锁着（2026-10-21，KB 06 §7.340）

管理员扫描里 `blockade` 报 `Error copying file from /data/user/f/fluffos.o to /data/keep/fluffos, Error: No such file or directory`，随后的 `recover` 在第一个 `cp()` 上死于 `*/data/keep/fluffos: lstat failed`，来不及执行最后的 `LOGIN_D->set_madlock(0)`：封锁解不开。`data/keep/` 是运行时目录，git 克隆里没有空目录。`blockade` 在第一次写之前 `if (file_size("/data/keep") != -2) mkdir("/data/keep");`（`mkdir()` 失败答 0，不抛错），`recover` 对没有保存档的玩家 `if (file_size(src) < 0) continue;`，其余照常恢复、照常解锁（`scripts/lpc_fix_keep_dir.py`，hy5 上实测：没有保存档时 `recover` 答“时空解封完毕”，`blockade` 建出 `data/keep` 并保存，`recover` 取回并删除）。改动（2 个文件）：`/cmds/arch/blockade.lpc`、`/cmds/arch/recover.lpc`。

## 不带参数的指令对 0 调用 efun：不在 wiz / adm 目录里的指令（2026-10-21，KB 06 §7.336）

指令敲成不带参数时，驱动把 0 传给字符串参数；下面的指令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`。它们在 `cmds/std`、`cmds/usr`、`cmds/bos`、`cmds/app` 这类目录里，上一轮的扫描只看巫师目录。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py --all-dirs` 在第一处使用参数的语句前加守卫：文件自带 `int help(object me)` 的，守卫是 `if (!arg) return help(me);`（`help()` 定义在 `main()` 之后的 1 个文件补了原型 `int help(object me);`，否则编译报 `Undefined function help`）；没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/app/test.lpc`（`present`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 9 条注册（6 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/clone/misc/bm.lpc`（`do_bselect`）、`/d/budui/obj/topless.lpc`（`do_people`）、`/d/city/npc/jiashen.lpc`（`do_chanhui`）、`/d/shendian/npc/baoyi.lpc`（`do_ban`、`do_gan`、`super_die`、`wave`）、`/inherit/misc/fboard.lpc`（`do_list`）、`/inherit/misc2/fboard.lpc`（`do_list`）。最多的函数名：`do_list` 2 处、`do_bselect` 1 处、`do_people` 1 处、`do_chanhui` 1 处、`do_ban` 1 处。改名：`/d/shendian/npc/wushi2.lpc` 的注册 `do_guozao` → `do_guozhao`（文件里定义的是 `do_guozhao`）。

## 调用了、但这个库自己的守护进程里没有的函数（2026-10-22，KB 06 §7.354）

`MACRO->函数()` 调用的函数在这个库的守护进程里不存在：`call_other()` 对不存在的函数不报错、只返回 0，所以这些功能（时间显示、昼夜事件、名字检查、价格文字……）一直没起作用。同一血统另一个库的同名守护进程里有这些函数，原文照抄到本库守护进程末尾（`scripts/lpc_port_function.py`；调用处传的参数个数、函数体用到的函数 / 全局变量 / 宏 / 字符串键都在本库里有，已核对；守护进程在 HEAD 和工作区都能加载，每个函数用固定参数各调用一次：HEAD 返回 0，现在返回正常的值）：`/adm/daemons/chinesed.lpc` ← bxsj：`chinese_time()`（1 处调用）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 还剩 2 个函数没有补（other 1, chat_msg_combat 1）：原型还在函数体丢了、或者根本没写过，没有可以直接补回的捐赠（别的库同一路径的文件里没有这个函数，或者它还要用本库没有的辅助函数、签名不同），不编造：`/cmds/usr/help.lpc`:`confirm_l_choice`、`/d/shendian/npc/ma.lpc`:`recover_ob`。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 1 行只含这个指针的行（`(: recover_ob :)`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 5 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：各派掌门的辈分判断（`name[0..1] == "澄"`）永远不成立。

本库 5 处（1 个文件）：与汉字常量比较 5 处。例：`s1[0..1] == "。"` → `s1[0..0] == "。"`（`/adm/npc/luban.lpc:1999`）；`s1[0..1] == "！"` → `s1[0..0] == "！"`（`/adm/npc/luban.lpc:1999`）；`s1[0..1] == "；"` → `s1[0..0] == "；"`（`/adm/npc/luban.lpc:1999`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 长度检查按字节写，旁边的提示按汉字写：7 处（2026-10-22，KB 06 §7.362）

老档的 `strlen()` 数字节（一个汉字 2 字节），转成 UTF-8 后它数字符：提示写「必须是 2 到 6 个中文字」的检查还是 `strlen(name) < 4 || strlen(name) > 12`，于是两三个字的房名、帮会名、群名、聊天室名、称号被提示自己说允许的那句话拒绝，上限却是提示的两倍；留言板的标题检查 `i < 4 || i > 24 || i % 2` 还会拒绝所有奇数个字的标题（`post 你好吗`）。本库 7 处（3 个文件）：`if ((strlen(name) < 2) || (strlen(name) > 8)) {`（`/adm/daemons/logind2.lpc:839`）；`if ((strlen(name) < 4) || (strlen(name) > 16)) {`（`/adm/npc/luban.lpc:1243`）。`scripts/lpc_fix_strlen_gate.py` 以提示为准：条件里每个 `strlen` 门槛都恰是提示所说数字的两倍才折半，存长度的变量（`i = strlen(arg);`）的门槛和 `|| i % 2` 奇偶项、其后循环的 `i % 2 == 0 &&` 一并处理；提示里有英文 / 字母 / 字节的不动。证明（`scripts/lpcc_eval.py`，bxsj 的留言板，求值对象继承 NPC 并重写 `edit()` 记录调用，`command("post 标题")`）：HEAD 拒绝「你好」和「你好吗」、放行 23 个字的标题；改后接受前两个、拒绝第三个；shenmo 的 `named.lpc invalid_new_name("张三")`：HEAD 回 `名字只能是2-4个中文字。`，改后回 0。抽样 24 + 15 个库的 HEAD / 工作树加载对比 0 退步。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 4 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 血条 / 表情标题按字节算显示宽度（2026-10-23，KB 06 §7.365）

老档把汉字当两字节：`bar_string[0..(val * N / max) * 2 - 1]` 把「格数」换成字节下标，半格血条在本驱动（按字符算区间）上会整条画满；巫师表情 `edemote` 的 `repeat_string("─", 13 - (strlen(emotion) / 2))` 也会少减汉字宽度。`scripts/lpc_fix_display_pad.py`：去掉 CJK 血条 / 空白条上的 `* 2`（`jings`/`qis` 赋值和 `blank_string3[0..(23-a)]` 的 23→11 一并改），表情标题去掉 `/ 2`；ASCII 空格的 `none_string` / `empty_string` 仍保留 `* 2`（一格两个空格）。本库 4 处（2 个文件）。证明（`lpcc_eval.py` hhsj）：`tribar_graph(6,9,12)` 在 HEAD 画出整条 12 个■，改后为 6 个■+3 个□；麻将 `strlen(tempB)/2` 是两字符牌码，未改。


## jiguang-dao inherit .h → gun（2026-10-27，KB 04 §6.25 Also）

`d/budui/obj/jiguang-dao` 写 `inherit "inherit/weapon/blade.h"`（无此对象）却调用 `init_gun(50)`，无法加载。同目录 `jiguangqiang` 用 `inherit "/inherit/weapon/gun"`。改为后者。证明：HEAD 失败；改后加载。
