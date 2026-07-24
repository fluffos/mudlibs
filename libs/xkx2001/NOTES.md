# xkx2001 — 侠客行 Ⅰ (Xiakexing/The Quest of Oriental Chivalry, 2001 test lib)

Archive: `xkx2001测试用老lib.zip`. Port: 40021. Status: **done** (boots
clean, connects, plays through login into "create new character?"
confirmation with zero crashes).

## What this is

"ES II mudlib" lineage (comment header in `adm/single/master.c`: "for ES
II mudlib... modified by Xiang for XKX"), same family as `rzrmud`
(archive #23, "大唐西游") — shares the exact same `master.c` function set
(`connect`/`epilog`/`preload`/`log_error`/`valid_*`/`standard_trace`/
`error_handler`) almost verbatim, both apparently descended from the
same "XKX"(侠客行)-authored base. `adm/single/master.c` +
`adm/single/simul_efun.c` layout, same as `bxsj`/`bxsj1` (archives #4/#5)
— but NOT the same lineage as those (checked: no `log_error()`/
`CHANNEL_D` reentrancy call, no lazy-load-in-valid_read pattern, 2-arg
`valid_override` but no allow-list issue hit in testing). MudOS v22b25,
"XiaKeXing Gaming Group 1996-2003".

## Fixes applied

None — booted clean with zero fixes on the first attempt (mechanical
`convert_lib.sh` pipeline only), same as `rzrmud`. Before starting,
checked this lib's `master.c` against the known bxsj-lineage bugs (§4
CHANNEL_D reentrancy, §14 valid_override 3-arg, §8c this_player()-override
footgun) since the `adm/single/` path layout matches bxsj/bxsj1 — none of
those specific bugs are present in this master.c despite the similar
directory layout, confirming layout similarity alone doesn't mean shared
bugs; the actual `master.c` *content* here is closer to rzrmud's.

## Known content gap (not fixed — see AGENTS.md §13)

lpcc sweep: 8124 files, 6884 pass / 1240 fail (84.7%). Largest cluster
(52 failures, one root cause per AGENTS.md §8g): `inherit/misc/
bboard.lpc` (and its `.bad.lpc` backup copy) calls `EDITOR_D->add(...)`/
`EDITOR_D->get_file_num(...)` — a whole daemon (`EDITOR_D`, apparently an
"anthology/featured-posts editor" service for bulletin boards) that
doesn't exist anywhere in this archive at all, not a typo or missing
`#define`. Genuine missing content (an entire daemon file), affecting
only the bulletin-board "compile into archive" feature — not fixed, out
of scope. The remaining ~1188 failures are the usual long tail (illegal-
character/encoding edge cases, syntax typos in individual files,
`#include`-only fragments failing standalone per §6b) — not triaged
individually.

## Interactive test result

Connects, ASCII banner + mudlist status table render correctly (Chinese
intact), GB/BIG5 charset prompt works, username length/alphabetic
validation works correctly (rejected both a too-long and an all-Chinese
attempt before accepting a valid one), and a valid new username reaches
the "create new character?" (y/n) confirmation prompt with zero crashes.
Did not create a full character or play further (out of scope).

## Re-verification pass (QA sweep, later session)

Earlier passes never tested past the "create new character?" confirmation
prompt / the password-setup step, so the full registration -> post-login
command flow (per the project's standing §15ae policy) had never actually
been exercised here. Re-tested end-to-end this pass and found two real,
fixed bugs, plus clarified one thing that looked exactly like a bug but
wasn't:

1. **§15s — `adm/simul_efun/message.lpc`'s `tell_room()` passed a raw,
   unset `int 0` as `message()`'s 4th ("exclude") argument** whenever
   called in its common 2-arg form. This driver's `message()` rejects that
   shape (`Bad argument 4 to EFUN message() ... Got: int(0)`), and since
   `tell_room()` fires from a room's own `create()`/`reset()`/
   `make_inventory()` chain (an NPC's arrival announcement) the very first
   time ANY room is lazily compiled, the uncaught error aborted the
   in-progress `move()` call that placed a brand-new character into their
   starting room -- leaving the character with **no environment at all**
   (`look` showed "你的四周灰蒙蒙地一片，什么也没有", `environment(me)` was
   0, every subsequent command touching `environment()` crashed). Fixed
   with the standard pattern: `exclude || ({})`. Re-verified: after the
   fix, `move()` into the starting room completes cleanly and `look`
   renders the real room every time.
2. **§15af — `master.lpc`'s `log_error()` called `wizardp(this_player(1))`
   unconditionally**, including during PRELOAD when no player is
   connected (`this_player(1)` is 0) -- `wizardp()` calls into
   `SECURITY_D` via `call_other`, which can lazily `load_object()` the
   security daemon; doing so while the driver is still mid-compile of
   some unrelated file throws `Object cannot be loaded during
   compilation.` (seen 23 times on a clean boot, all during preload, all
   non-fatal here but pure log noise plus latent-crash risk of the kind
   documented for `shenzhou`). Also fixed the same function's
   `"Warning:"` vs the driver's real lowercase `"warning:"`
   case-sensitivity bug while touching this line (the filter never
   actually matched anything before). Fixed by guarding the whole check
   behind `this_player(1) &&` first. Re-verified: a clean boot now shows
   **zero** `执行时段错误` lines at all (was 23).
3. **Missing `/log/nosave/` directory** (§15ah-shaped): `securityd.lpc`'s
   own denial-logging (`log_file("/nosave/WRITE_LOG", ...)`) and
   `message.lpc`'s read/write audit log both target this subdirectory,
   which the raw archive never shipped. Created
   `libs/xkx2001/work/log/nosave/` proactively.
4. **Not a bug -- clarified a red herring that looked exactly like a
   silent-command-dispatch bug (§15ae's symptom shape) but has a totally
   different, legitimate cause**: every brand-new (non-wizard) character
   lands on the "侠客岛" landing beach (`d/xiakedao/shatan1.lpc`), whose
   own `init()` calls `add_action("block_cmd","",1)` -- a DELIBERATE,
   hand-written onboarding gate that blocks every command except `quit`,
   `goto`, `suicide`, `follow`, `tell`, `say`, `reply`, `look` until the
   player follows the greeter NPC (auto-drags them after ~15s regardless)
   to the "侠客岛挂名处" (registration desk) and types
   `register <email>` -- which the mudlib code implements as generating
   and returning a **brand-new system password** and disconnecting the
   session (an authentic 1990s-era anti-multi-accounting mechanic, not a
   crash). `block_cmd()` returns 1 (block) with **no message at all** for
   anything outside that whitelist, so `score`/`inventory`/`help`/`who`/
   etc. silently doing nothing at this stage is completely expected
   in-game behavior, not a driver-compat regression -- confirmed by
   reconnecting with the new password afterward and finding `look`/
   `score`/`quit` all work perfectly in the real starting room. Spent
   real diagnostic effort here (temporary `efun::write_file()` tracing in
   `process_input()`/`command_hook()`/`find_command()`, all removed
   afterward) before finding `shatan1.lpc`'s `block_cmd()` -- worth
   flagging in AGENTS.md as a new variant of the "commands silently do
   nothing after registration" family (distinct from §15ae's private-
   command-hook cause and §15aj's missing-environment cause): a
   deliberate, narrow post-registration command whitelist gate with a
   silent (no-notify_fail) block response.

Full clean re-verification (fresh boot, after all fixes): registration
with real Chinese names 秦云(female)/秦伟(male), through the
follow-NPC -> auto-escort -> `register <email>` -> new-password ->
reconnect -> `look`/`score`/`quit` flow, zero `执行时段错误` in
`debug.log` across the entire session.

## Post-hoc fix: UTF8-native is_chinese/registration (AGENTS.md §15h)

Applied in a later batch pass across the whole project: `is_chinese`/`is_chinese2`
in the shared `chinese.lpc` simul_efun fragment used GBK byte-range checks that
silently never match real Chinese text once strings are UTF-8 (this driver's
`str[i]` returns a Unicode codepoint, not a GBK byte). This broke character
registration specifically -- any real Chinese name was rejected. Fixed the
range check to test the CJK Unicode block instead, and halved the
GBK-byte-calibrated length bounds in `check_legal_name` to match. See
AGENTS.md §15h for the full writeup; confirmed via a real interactive
registration test (Chinese surname + given name reaching the next prompt).

## Driver-rebuild retest + LPC reformat + WASM pass (this session)

- **LPC formatter applied** (`tools/lpc-syntax`, all `work/*.lpc`):
  8,074 files reformatted, 46 unchanged, 9 refused (self-check failures
  on messy legacy code, expected). Confirmed the §15s `tell_room()` fix
  in `adm/simul_efun/message.lpc` survived reformatting intact.
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`, rebuilt from latest upstream
  master): boots clean, zero `FATAL`/`SIGSEGV`/`执行时段错误` in
  `debug.log`. Full registration verified end-to-end with real Chinese
  names, including this lib's distinctive onboarding mechanic: id/name/
  password/gift/email/gender -> lands on the "侠客岛" beach ->
  greeter NPC `follow`-escorts the player (auto-drags after a delay) to
  the "侠客岛挂名处" (registration desk) -> `register <email>` generates
  a brand-new system password and disconnects -> reconnect with the new
  id+password -> `look`/`score`/`quit` all correct in the real starting
  room. Verified with id `qretkxr`/real name **秦云归来** (male),
  new password `ychif` issued by `register`, reconnect succeeded and
  reached the beach's continuation room with correct character sheet.
- **WASM build tested** (`~/src/fluffos/build-wasm/src` via
  `scripts/wasm_client.js`): boots cleanly (only expected non-fatal
  preload warnings, e.g. `Macro 'ROOM' redefined` and no-`sockets`-
  package notices). **Registration succeeded end-to-end under WASM,
  including the full beach -> follow -> register-desk -> new-password
  flow** — real Chinese name **秦云网四** (id `qfwaskc`), `register`
  correctly issued a new password (`slrze`) and disconnected, exactly
  matching native behavior. **Contrary to this project's general
  expectation for this lib** (this lib's own login/ban checks —
  `BAN_D->is_banned(query_ip_name(ob))` and
  `REGBAN_D->is_banned(query_ip_name(ob))` in `logind.lpc` — use
  `query_ip_name()`, not `query_ip_number()`, and neither gated the
  registration path in this pass's testing), **this lib's own
  registration flow was NOT observed to be blocked by the documented
  `query_ip_number()`-format WASM limitation** in the portion tested.
  The one step not further exercised under WASM: reconnecting with the
  `register`-issued new password to complete the loop, since
  `wasm_client.js` boots a fresh in-memory filesystem per invocation
  and has no built-in way to reconnect to an already-disconnected
  session within one process (a harness limitation, not a mudlib or
  driver bug) — the native re-test above already fully covers that
  final step. The general `query_ip_number()` WASM limitation described
  in AGENTS.md remains real and does affect other libs in this batch
  (see `xiyangzaixian_fengkuang`/`xiyangzaixian_fengyun2`'s NOTES.md,
  whose `BAN_D` checks use `query_ip_number()` directly) — it just
  doesn't reach this particular lib's tested registration path.

## WASM-enablement pass (loopback-allow + admin seed)

Applied the standard WASM-first changes (AGENTS.md §1.3b/§1.3e/§1.5):

1. **Loopback always allowed through ban gates** — this lineage gates on
   `query_ip_name()` (hostname), not the IP:
   - `adm/daemons/band.lpc`: added `is_local_ip(string site)` helper
     (empty/non-string, `localhost`, `127.*` => local) and
     short-circuited `is_banned()` to `return 0` for local sites.
   - `adm/daemons/regband.lpc` `is_banned()` (the registration-ban gate
     called from `logind.lpc` before new-character creation): same
     inline local short-circuit. (regband is also matched against email
     patterns; the local check only matches localhost-shaped strings so
     email matching is unaffected.)
2. **Uptime startup gate**: none in this lib.
3. **Anti-flood throttles**: none per-IP (`MAX_USERS` is a global cap —
   left intact). `SECURITY_D->valid_wiz_login()` requires a wiz_sites
   entry for every wizard — fluffos is seeded with pattern `.*` so this
   gate passes from anywhere including WASM garbage IPs; gate itself
   left intact.
4. **Admin account seeded** — id `fluffos`, display name 浮浮 (male).
   Registered through the REAL flow including this lib's quirks:
   initial password at creation, landing on the 侠客岛 beach, escort to
   侠客岛挂名处, `register fluffos@mud.local` which ASSIGNS A RANDOM
   password (was `zfbod`) and disconnects. Then granted `(admin)` by
   editing `data/securityd.o` (the lineage's ACL save data — NOT the
   `adm/etc/wizlist.h` file, which this securityd only uses as a
   fallback when the save is absent): added
   `"fluffos":"(admin)"` to `wiz_status` and `"fluffos":".*"` to
   `wiz_sites` (required by `valid_wiz_login`). After restart, logged
   in and used the game's own `passwd` command to change the random
   password to the standard `Mud@2026`. Verified: 目前权限：(admin),
   `update /adm/daemons/band` recompiled OK, wizard-view `look` shows
   file paths. (`goto` on a non-room daemon object is a no-op in this
   lib; `update` is the canonical ACL check.) Save files:
   `work/data/user/f/fluffos.o` + `work/data/login/f/fluffos.o`
   (untracked, NOT gitignored — orchestrator must `git add`), plus the
   modified `work/data/securityd.o` (already tracked).

Retest: fresh registration (fluffos itself) through beach → 挂名处 →
`register` → random password → re-login all worked natively; fluffos
re-login with `Mud@2026` + `update` verified; debug.log free of runtime
errors.
