# beimeixiakexing2001 — 侠客行 (The Quest of Oriental Chivalry, North America 2001 build)

Archive: `北美侠客行2001.rar`. Port: 40039. Status: **done** (boots
clean, full registration flow verified end-to-end including a real
Chinese name).

## What this is

"侠客行" / "The Quest of Oriental Chivalry", credited to "XiaKeXing
Gaming Group 1996-1999", MudOS v22b25. Confirmed via `diff` to be the
**same codebase lineage as `xkx2001`** (archive #25, already done):
`adm/simul_efun/chinese.c` and `adm/single/master.c` are byte-identical;
`adm/daemons/logind.c` differs by only a single commented-out IP address
line. However, many peripheral `clone/`/`cmds/` files genuinely differ
— a real, evolved snapshot at the content level, not a byte-identical
archive duplicate — so it still needed its own conversion/boot/test
pass, just with the core registration-path fixes already known.

## Fixes applied

1. **AGENTS.md §15h**: `is_chinese()`'s standard GBK lead-byte check →
   CJK codepoint check.
2. **Ported directly from `xkx2001`'s already-proven fix**:
   `check_legal_name(string name, object ob)` had the exact same
   byte-shift "auto-correct" hack (`name[j]+=128; name[j+1]+=128;`,
   meaningless against Unicode codepoints) — replaced with
   straightforward rejection, matching `xkx2001`'s fixed version
   verbatim. Bound `< 2 || > 8 || i % 2` (byte count + meaningless
   odd-byte rejection) → `< 1 || > 4` (character count).
3. **New instance of AGENTS.md §8e** (`tail` is not a real FluffOS
   efun): `adm/simul_efun/message.lpc`'s `tail(string file)` called
   `efun::tail(file)`. Unlike some other libs where this is a harmless
   dead admin command, here it's **fatal** — this function is compiled
   as part of `simul_efun.lpc` itself, so the compile error
   (`Unknown efun: tail`) took down the ENTIRE simul_efun object,
   which crashed the whole boot (`No program in object
   '/adm/single/simul_efun'!`, `The simul_efun ... and master ...
   objects must be loadable`). Fixed with the standard §8e
   reimplementation (`read_file()` + `explode()` + slice last 10 lines
   + `write(implode(...))`).
4. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. `/adm/daemons/network/http` is ALSO in preload but confirmed
   safe to leave (its socket setup is deferred via `call_out("setup",
   5)`, non-blocking to preload).
5. **Retroactive fix, AGENTS.md §15ae** (added after the original pass
   above — the original registration test here never continued past the
   password prompt, so this was missed): `feature/command.lpc` declared
   its `add_action`-dispatched command hook as `private nomask int
   command_hook(string arg)`. This driver treats `private` as opaque to
   `add_action`'s external dispatch once inherited into the player body
   class, so **every single post-login command silently did nothing at
   all** — no error, no output, indistinguishable from a hung connection.
   Found independently on `xuanjianlu` (archive #70, same underlying
   bug), which flagged this lib as also affected. Fixed by dropping
   `private` (keeping `nomask`). Re-verified with a fresh registration
   (id `hookabcd`, real Chinese name `秦淮`) followed by re-login and
   `look`/`score`, both now producing correct output.

## Interactive test result — full registration flow

This lib has a hidden pre-id prompt: **"Do you want to use BIG5
code?(y/n)"** right after the banner. Verified the complete registration
path in one continuous connection: `n` → id `bmxkxb` → confirm `y` →
**real Chinese name `秦风`** (avoiding "韦小宝"/Wei Xiaobao — a famous
Jin Yong character found in this lib's `banned_name` list) → accepted,
proceeds straight to "请设定您的密码：".

## lpcc sweep

8,145 files, 6,894 pass / 1,251 fail (84.6%). The largest single cluster
(52 failures) is the exact same missing `EDITOR_D` daemon documented in
`xkx2001`'s own NOTES.md (a bulletin-board "compile into archive"
feature, genuinely absent from this archive too — not a typo). The
remaining ~1,199 failures are the usual long tail (illegal-character/
encoding edge cases, syntax typos in individual files) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~12GB free).

## Retroactive fix (QA re-verification pass, 2026-07-23): tell_room() 2-arg call crashed the starting room (AGENTS.md §15s)

Found during a routine re-verification pass: a fresh registration reached
the password prompt fine, but the resulting character landed with **no
environment at all** — `look` printed "你的四周灰蒙蒙地一片，什么也没有。"
(the standard "you are nowhere" fallback), i.e. exactly the §15t-shaped
symptom of a new character silently ending up in the void. Root cause was
the classic §15s bug, not previously caught here: `adm/simul_efun/
message.lpc`'s `tell_room(ob, str)` 2-arg call form leaves the `varargs
object *exclude` parameter as its default `int 0`, which flows straight
into `message("tell_room", str, ob, exclude)` — this driver's `message()`
efun rejects a literal `int 0` in that 4th argument slot at runtime. The
starting room (`/d/xiakedao/shatan1.lpc`, picked randomly for every new
character) calls `tell_room()` from its own `reset()`→`make_inventory()`
chain, so this crashed the room's own creation on every single new
registration, leaving the new character with no valid environment.
Verified directly with `lpcc <config> d/xiakedao/shatan1` — reproduced the
exact crash (`*Bad argument 4 to EFUN message()`) outside a full boot.

**Fix**: `message("tell_room", str, ob, exclude || ({}));` (same pattern as
every other lib in this project with the same bug). Re-verified with
`lpcc` (clean load, no error) and a fresh full registration + `look` in a
real driver boot — the character now correctly lands on "沙滩" (the beach)
with full room text and the escort NPC's greeting, `debug.log` clean.

Also investigated (and confirmed NOT a bug) while diagnosing the above:
`score`/other non-allow-listed commands produce **no visible output** for
a few moments right after registration — this is intentional content, not
a broken command dispatcher. `d/xiakedao/shatan1.lpc`'s `init()` installs
`add_action("block_cmd", "", 1)` for any non-wizard, and `block_cmd()`
silently swallows every verb except `quit`/`goto`/`suicide`/`follow`/
`tell`/`say`/`reply`/`look` until the player follows the escort NPC to
the registration room and confirms an email via `register <email>` — the
same restriction is present in `d/xiakedao/register.lpc`'s own room too.
Confirmed via a temporary `write_file()` instrumentation of
`command_hook()` (removed after diagnosis) that `look` reaches
`find_command`/dispatch correctly while `score` never reaches
`command_hook` at all in this state — i.e. the driver's dispatch layer
itself is healthy; this is a deliberate "you can't do anything except
follow/register yet" onboarding gate, not the §15ae dead-command-hook
class of bug. `look` was used as this lib's verified post-login command.

## Re-verification pass (2026-07-23): driver rebuild + LPC formatter + WASM build

- **Formatter**: ran `format-corpus.mjs` over all of `work/` (8,146 files,
  8,090 written/reformatted, 30 already-clean, 26 refused with an error —
  expected on legacy code, not chased individually per the tool's own
  self-check policy).
- **Native retest against rebuilt driver** (`build-debug/src/driver`,
  rebuilt from latest upstream master): clean boot, zero fatal errors in
  `debug.log` (only ordinary compile-time warnings, same shapes as
  before). Full registration re-verified end-to-end on the
  now-reformatted source with a fresh real Chinese name (`秦山`): BIG5
  prompt → id `qinshan` → confirm → Chinese name → password → talent
  roll → email → gender → reaches the actual starting room (沙滩), escort
  NPC `张三` greets by name. `look` correctly redisplays the room;
  `score`'s no-output behavior is the pre-existing documented onboarding
  gate above, not a regression. No new fixes were needed — the reformat
  and the fresh driver build did not introduce any regression.
- **WASM build**: booted cleanly under `build-wasm/src` via
  `scripts/wasm_client.js` (the only preload-time complaint is
  `Undefined function socket_close` in `adm/daemons/network/http.lpc`,
  caught by the lib's own `master.lpc` error handler exactly as it is for
  a missing daemon natively — non-fatal, `Initializations complete.`
  still printed). Unlike some sibling libs, this lib's login/registration
  path does **not** gate on `query_ip_number()`'s format, so registration
  proceeded all the way through under WASM too: id `qinfeng` → Chinese
  name `秦风` → password → talent roll → email → gender → reached the
  actual starting room (沙滩), escort NPC greeted by name, `look`
  produced correct room output, `quit` exited cleanly. **This lib is
  confirmed fully playable under WASM**, not just "boots."
