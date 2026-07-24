# dongfanggushi2 — 东方故事Ⅱ之天朝帝国 (Eastern Story II: The Celestial Empire)

Archive: `东方故事二.rar` (byte-identical duplicate: `东方故事二 (1).rar`,
already listed in AGENTS.md's Duplicate archives table — this row covers
both). Port: 40027. Status: **done** (boots clean, full registration
flow verified end-to-end through an unusually long chain, including a
real Chinese name).

## What this is

"东方故事Ⅱ之天朝帝国" ("Eastern Story II: The Celestial Empire"),
credited to Annihilator and Phoebus.suny, "建立架构 Nov 6, 1995" / "测试
游戏制度 Apr 22, 1996". Mudlib root at `es2/es2/`, config at
`es2/config.cfg`. Same `adm/obj/{master,simul_efun}` layout convention as
`es1_win`/`esI` (archives #12/#13, also "东方故事" lineage) — but a
genuinely **different, smaller, distinct codebase** (564 raw files vs.
es1_win's ~8000+), not a snapshot of the same tree: no `std/object/
prop.lpc` angle-bracket-include bug here, different `domain_file()`
implementation (no `explode("/","/")` empty-array bug). Don't assume
lineage-shared fixes transfer 1:1 just because the directory layout
matches — verify each one is actually present before applying it.

## Fixes applied

1. **AGENTS.md §4 (lazy security-daemon load)**, applied to **both**
   `valid_write` AND `valid_read` in `adm/obj/master.lpc` — unlike most
   libs processed so far (where `valid_read` is often a hardcoded
   `return 1`), this build's `valid_read` ALSO called
   `load_object(SECURITY_D)` unconditionally with no re-entrancy guard.
   Both fixed with the standard `nosave` flag + `find_object()` gate.
2. **AGENTS.md §15h (GBK byte-range Chinese detection)**: `adm/
   simul_efun/chinese.lpc`'s `is_chinese()` and `adm/daemons/logind.lpc`'s
   `check_legal_name()` (byte-count bound `< 2 || > 12` → `< 1 || > 6`,
   removed `i%2==0` gate) — same shape as every prior lib. Also found a
   **new sub-variant of fix pattern #5** (sliding-window byte-width):
   `check_legal_name()` had a *separate* full-width-space rejection check,
   `if( name[i..i+1]=="　" )`, a 2-BYTE window under the old GBK
   assumption — under UTF-8 this is a 2-CHARACTER slice that can never
   equal the 1-character string `"　"`, so the check silently never
   fired. Fixed to `name[i..i]` (1-character slice, matching the fixed
   `is_chinese`'s per-character indexing used elsewhere in the same
   function).
3. **New: a driver-crash bug, not a compile error** — `master.lpc`'s
   `create()` unconditionally did:
   ```lpc
   if( ob = find_object(SIMUL_EFUN_OB) ) {
       efun::destruct(ob);
       call_other(SIMUL_EFUN_OB, "???");
   }
   ```
   an old-MudOS trick to force-reload simul_efun. On this driver,
   destructing the simul_efun object from inside master's OWN `create()`
   — i.e. during the driver's own early bootstrap, before
   `master_ob`/`simul_efun_ob` are fully settled — **segfaults the whole
   driver process**, crash trace rooted in `destruct_object()` dereferencing
   `master_ob->obname` on a not-yet-initialized pointer (`vm/internal/
   simulate.cc`). Not an LPC-level error at all — nothing in `debug.log`
   short of the raw backward-cpp stack dump gave any clue beyond "it
   segfaults right after boot starts." Fixed by simply dropping the
   destruct+reload dance entirely: the driver already loads simul_efun
   fresh before master's `create()` ever runs, so there was nothing stale
   to work around here in the first place.

## Interactive test result — full registration flow

This build's registration chain is noticeably longer than every other
lib processed so far — `id → confirm → password → confirm password →
email → race select → gender → THEN Chinese name` (most libs go straight
from id-confirm to Chinese name). Verified the ENTIRE chain in one
continuous connection:

1. `dfgstwo` → passes `check_legal_id` (letters only, no digits — an
   earlier attempt with a digit in the id, e.g. `dfgs2test`, was
   correctly rejected, not a bug).
2. `y` → password prompt.
3. `password1` (twice, matching) → accepted, email prompt.
4. `a@b.com` → race selection prompt (`human`/`yenhold`/`woochan`/
   `jiaojao`).
5. `human` → gender prompt.
6. `m` → **real Chinese name prompt**.
7. **`萧峰`** → accepted by the fixed `check_legal_name` — and this time
   verification went all the way to actually **entering the game world**:
   the session landed in an actual room ("小客栈" / Small Inn) with a
   full room description, not just a password/next-step prompt. This is
   the deepest registration verification done on any lib so far in this
   project.

## Known remaining issues (documented, not fixed)

(none outstanding — the `eval_chat()` issue formerly documented here was
fixed during the 2026-07-23 QA re-verification pass; see below.)

## Retroactive fixes (QA re-verification pass, 2026-07-23)

Found during a routine re-verification pass (full registration + post-login
`look`/`score`/`quit` test in a fresh session) — both are genuine bugs, not
present in the original conversion notes above:

1. **`adm/obj/master.lpc`'s `log_error()` showed raw compiler diagnostics
   (including harmless warnings) to ANY connected player, not just
   wizards** (AGENTS.md §15af family, but a distinct/worse variant: this
   lib's version had no `wizardp()` gate at all, so ordinary players saw
   the full `"编译时段错误：" + message` text — file paths, line numbers,
   "Unused local variable" noise — every time an as-yet-uncompiled
   room/NPC was first touched, e.g. simply typing `look` in the starting
   room). Fixed to only show the full diagnostic to a wizard, and only
   alarm an ordinary player with the generic `default error message` for
   a genuine compile **error** (gated on absence of `"warning:"` in the
   message, same pattern as `dtsl`/`wuhanzhan`/`shenzhou`). This also
   required `#include "/include/runtime_config.h"` at the top of
   `master.lpc` (for the `__DEFAULT_ERROR_MESSAGE__` macro used in the
   fix) since the file had no includes at all before.
2. **The previously-documented `eval_chat()` bug (see git history) was
   actually blocking the starting-room innkeeper NPC from compiling at
   all** — once (1) above stopped masking it with raw compiler spam, it
   became clear this fires on literally every single new character's
   first room entry (`/d/snow/npc/innkeeper` inherits the broken
   `std/char/npc.lpc`). Given the outsized, first-impression impact and
   the trivial/safe fix, this was resolved rather than left as a
   documented gap: `eval_chat()`'s `switch(typeof(chat))` had a dead
   `case MATCH:` (an int constant, `0x102`) with a body byte-identical to
   the preceding `case STRING:` — this driver's `typeof()` returns string
   type-name constants (`STRING`/`ARRAY`/`FUNCTION` from `include/type.h`
   are themselves strings), so mixing the stray int case label in was a
   hard "Mixed case label list not allowed" compile error, not a
   different behavior being lost. Removed the redundant `case MATCH:`
   label (its body was already covered by `case STRING:`) — not
   fabricating new behavior, just deleting dead/incorrect duplicate code.

Re-verified with a fresh registration (real name `秦兰`, female) followed
by `look`/`score`/`quit`: the innkeeper NPC now greets the player
correctly ("掌柜说道：欢迎！欢迎！请里面坐！"), zero spam, zero real
`error:` lines in `debug.log`.

## lpcc sweep

427 files, 367 pass / 60 fail (85.9%). Memory stayed healthy throughout
(~17GB free, no pressure — this is a small lib). Failure tail not
triaged individually per AGENTS.md §6b/§13 — the full interactive
registration test (which went deeper than any prior lib, reaching an
actual room) is the verification gate.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (427 files,
  426 written/reformatted, 1 already-clean, 0 errors).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log`. Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦凡`, ID
  `qinfan`, following this lib's own long ID→confirm→password→email→
  race→gender→Chinese-name flow, race `human`) reaching the actual game
  world (小客栈 starting room), innkeeper NPC greeting correctly
  ("掌柜说道：欢迎！欢迎！请里面坐！"); `look`/`score`/`quit` all
  produced correct output (full 精气神 status bars rendered correctly),
  zero real errors in `debug.log`. No regressions from the reformat or
  the fresh driver build.
- **WASM build**: preload completes with only the expected non-fatal
  `sockets`-package gap (`adm/daemons/ftpd.lpc`'s
  `socket_create`/`socket_bind`/`socket_close` → `Undefined function`,
  caught non-fatally, `Initializations complete.` still printed). Like
  `datangshuanglong`, this lib's login path does **not** gate on
  `query_ip_number()`'s format, so a full registration proceeded all
  the way through under WASM too: ID `qinlan` → password → email →
  race `human` → gender `f` → Chinese name `秦岚` → reached the actual
  game world (小客栈), innkeeper NPC greeted correctly, `look` produced
  correct room output, `quit` exited cleanly. **This lib is confirmed
  fully playable under WASM**, not just "boots."

## WASM-enablement pass (2026-07 standard: loopback-allow, throttle exempt, admin seed)

Gates patched (fail-closed: only an exact `127.0.0.1`/`127.`-prefix
match is exempt; a malformed/non-string address is treated as remote):

- `adm/daemons/logind.lpc` `logon()` (~line 56): the `ANTI_BUZZER`
  per-IP character-creation throttle (`buzzer_ip[ip] >= 10` ->
  `destruct(ob)`) now exempts loopback. `ANTI_BUZZER` IS defined
  (`include/login.h`), so this gate is live, unlike some other
  `#ifdef`-gated checks in this file.
- No live ban-site/site-restriction daemon (no `band.lpc`/`sited.lpc`
  shipped or preloaded in this lib). `get_id()`'s `ENABLE_BAN_SITE`
  block (~line 117) IS defined and live, but only applies to
  `wizhood(arg) == "(player)"` accounts against a 2-entry static IP
  list (`202.96.134.135`, `202.102.111.2`) that can never match
  loopback -- left unpatched as genuinely out of scope (not a
  loopback-relevant gate).
- No `uptime()` startup-grace gate found (the `UPTIME_CMD->main()` call
  in `logon()` is a cosmetic "uptime so far" banner, not a grace-period
  check).

**Real bug found and fixed while verifying re-login (distinct from
registration) as required by AGENTS.md §10.1** -- this is the more
significant fix from this pass, not loopback-related:
`adm/daemons/securityd.lpc`'s `valid_read()` had a `restore_object`
special case intended to let the login object read back its own save
file:
```
if (func == "restore_object")
  if (sscanf(base_name(user), "/obj/%*s") && sscanf(file, "/data/%*s")
      && file == (string)user->query_save_file())
    return 1;
```
but the driver's `restore_object()` (`vm/internal/base/object.cc`)
always appends the save extension (`.o`) to the `file` argument passed
to `valid_read`, while `obj/login.lpc`'s `query_save_file()` returns the
bare path with no extension -- so `file == query_save_file()` was
**always false**. The euid-based fallback below it also always denied,
because `obj/login.lpc`'s own `logon()` deliberately clears the login
object's OWN euid to null (`seteuid(0); // Let LOGIN_D export proper uid
to us.`) so that `LOGIN_D`'s later `export_uid(ob)` call (which only
succeeds when `ob->euid` is falsy, per the driver's `f_export_uid`) can
set `ob`'s UID -- `export_uid()` only ever sets `uid`, never `euid`
(confirmed by reading `packages/uids/uids.cc`), so the login object's
euid stays null for its entire life by design. Net effect: **every
returning player's `restore_object()` call was permission-denied,
100% of the time** -- confirmed via `catch()`+`efun::write()`
instrumentation showing `euid=0 uid=fluffos ... err=*restore_object:
read permission denied`. This silently dropped straight into "对不起，
您的人物储存挡出了一些问题" and destructed the connection on EVERY
re-login attempt for EVERY account, not just the newly-seeded admin --
a pre-existing bug, invisible until now because every prior
verification pass in this lib's history tested registration through to
`quit` but never a SECOND connection logging back into the same id
(exactly the gap AGENTS.md §10.1 warns about). Fixed by accepting the
save-extension-qualified path too (`file == save_file || file ==
save_file + ".o"`), which is the minimal correct fix (the intended
"user may read back their own save file" grant, just written against
the wrong path shape). Verified: both `fluffos` and a fresh throwaway
player (`ceshiba`) can now fully disconnect and reconnect into their
existing character. This was NOT present in the original registration-
only NOTES above and NOT something this pass introduced -- it dates to
however this lineage's `securityd.lpc` was originally authored/forked.

Admin account: id `fluffos` / `Mud@2026` / 浮浮, registered through the
normal long flow (id -> confirm y -> password x2 -> email -> race
`human` -> gender -> Chinese name 浮浮), pre-granted `(admin)` via
`adm/etc/wizlist` (`fluffos (admin)` line, `test`'s existing entry kept)
before registration so the account came out already showing "目前权限：
(admin)". Verified on a SEPARATE re-login (exercising the restore-path
fix above): password accepted, `update /d/snow/inn_hall` succeeded
("重新编译 /d/snow/inn_hall.lpc ...Ok."). Save files
(`data/user/f/fluffos.o`, `data/login/f/fluffos.o`) are plain untracked
paths, not covered by any `.gitignore` pattern -- a normal
`git add libs/dongfanggushi2/` picks them up, no force-add needed.

Retest: fresh normal registration (id `ceshiba`, name 秦月, female)
reached 小客栈, innkeeper greeted correctly, look/quit correct; a
SECOND connection re-logging into `ceshiba` (the restore path) also
succeeded post-fix. debug.log clean across all four driver runs this
pass (only expected boot-time config dump and SIGTERM-on-kill lines).
Four driver instances started/killed by exact PID during this pass
(one extra cycle for the diagnostic instrumentation added and then
removed while root-causing the restore bug). Test character `ceshiba`'s
saves removed afterward; `fluffos`'s kept.
