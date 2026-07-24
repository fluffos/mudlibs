# 星战英雄.rar → `xingzhanyingxiong`

- Archive: `archives/星战英雄.rar` (1.3MB — "乱世风沙之星战英雄", a
  `xkx`-lineage MudOS lib, config labeled 0.9.20 like lib #1 but a
  different codebase; ANSI-art login banner).
- Mudlib root in archive: nested at `xz/xkx/` (config.cfg lives in `xz/`,
  one level above the actual mudlib root — NOT at the archive top level,
  unlike lib #1. Always check `mudlib directory :` in the config rather
  than assuming the archive layout).
- Port: **40002**.

## Status: DONE — boots clean, playable over telnet

Full ANSI-art banner + Chinese login flow confirmed working. This lib is
the 2nd pilot and is where the FluffOS driver bug (AGENTS.md §8) and the
`message_combatd` mudlib bug (below) were found and fixed.

## What was fixed

1. Encoding: 1942 files converted GB18030→UTF-8, 193 already UTF-8/ASCII,
   15 skipped as genuinely binary (mudos.exe/.dll etc — bundled Windows
   driver binaries, irrelevant, left alone), 30 needed the lossy `-c`
   fallback (stray invalid bytes scattered through `kungfu/skill/*`,
   `clone/book/*`, `d/fenghuang/fenghuang/*`, a few `welcome` files, and
   `data/emoted.o` — all pre-existing single-byte corruption in the
   original archive, not something our pipeline introduced).
2. `.c` → `.lpc`: 1909 files renamed. 132 literal `.c"` references
   auto-fixed by `convert_lib.sh`, 0 left over needing manual attention.
3. `static` → `nosave`: 51 files.
4. `master.lpc` does NOT have the §4 `load_object`-in-`valid_read`
   recursion bug (no `load_object` calls in this master at all) — checked,
   not needed here.
5. Config: removed 5 obsolete keys, set `port number : 40002`,
   `mudlib directory` to absolute `work/` path, fixed `log directory`
   (was `/adm/log`, changed to `/log` to match the `libs/<slug>/log/`
   convention — AGENTS.md §6).
6. **Found and fixed a FluffOS driver bug** (AGENTS.md §8): null
   `backbone_domain` dereference in `mudlib_stats.cc`'s
   `init_domain_for_ob()`, triggered because this lib's `master::
   author_file()` calls `call_other(SIMUL_EFUN_OB, "author_file", ...)`
   during master's own bootstrap (before `backbone_domain` is set),
   causing a SIGSEGV the first time that call chain loads a new object.
   Patched `~/src/fluffos/src/packages/mudlib_stats/mudlib_stats.cc`;
   rebuilt both `build/` and `build-debug/`. Systemic pattern, likely to
   recur on other libs — no re-diagnosis needed, just confirm the patched
   driver binaries are what's running.
7. **Found and fixed a mudlib bug affecting 100+ files**: every file under
   `kungfu/skill/*` calls `message_combatd(msg, me, target)` to print
   combat messages, but no such function is defined ANYWHERE in the lib
   (checked exhaustively — not a simul_efun, not on `COMBAT_D`, not
   anywhere). The signature exactly matches `message_vision()` (an
   existing, working simul_efun in `adm/simul_efun/message.lpc`) — old
   MudOS's weaker compile-time checking apparently let this ship broken
   (every combat skill's flavor-text message was silently a no-op under
   whatever driver this last ran on); this driver rejects undefined-
   function calls at load time, which is what surfaced it. Fixed by
   adding `message_combatd()` as a thin alias for `message_vision()` in
   `adm/simul_efun/message.lpc` (placed AFTER `message_vision`'s own
   definition — same-file forward-reference didn't resolve, see AGENTS.md
   §8b) rather than touching 100+ call sites.
8. Full `lpcc_check.sh` sweep: 1729/1909 pass before the `message_combatd`
   fix → 1773/1909 pass after it + the driver's macro-nesting-depth fix
   (AGENTS.md, `MAX_EXPANSION_NESTING`) fixed `clone/misc/{card,newcard}.lpc`
   too. 136 failures remain, mostly the missing-zone-content and optional-
   network-daemon categories below.

## Known remaining issues (not fixed — documented, low/no priority)

- **~60 `clone/board/*.lpc` files** reference room paths under zones that
  don't exist ANYWHERE in this archive at all (no `/d/wudang`,
  `/d/shaolin`, `/d/huashan`, `/d/emei`, `/d/tangmen`, `/d/mingjiao`, and
  many more classic wuxia-sect zones — checked, genuinely absent, not just
  uncompiled-yet). This archive shipped without most of its game-world
  content, likely a "core" release split from a much larger world pack.
  Not fabricating the missing rooms (AGENTS.md §13) — these board clones
  aren't preloaded, so this has zero effect on normal play, only lpcc-sweep
  noise.
- `/adm/daemons/network/{ms,userid,pingtcp,mail_serv,netmail,telnetd,pingd,
  inetd}.lpc` — same optional network-daemon-cluster-missing-headers issue
  as lib #1 (`config.h`/`mailer.h`/`daemons.h`/`uid.h`/`priv.h`/`post.h`
  absent from `include/`). Not on preload, not required for play.
- A handful of `d/*` room/NPC files have real syntax errors (missing
  brace/quote, `switch`/`case` shape issues similar to lib #1's rankd.lpc)
  — not yet individually triaged past the first pass; low priority since
  none are on the critical boot/login path.
- A few `F_SKILL: No such skill (...)` errors on some `clone/npc/killer-*`
  NPCs — reference skill names not present in `kungfu/skill/` under this
  archive; likely more missing-content (same shape as the board/zone gap
  above), not investigated further.

## How to run

```
cd libs/xingzhanyingxiong
~/src/fluffos/build-debug/src/driver config.fluffos
# separately:
python3 ../../scripts/mudclient.py 127.0.0.1 40002 --timeout 10 --send "" --send "look" --send "quit"
```

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

## Re-verification pass: driver rebuild + formatter + WASM (2026-07-23)

- **LPC formatter** applied to all `work/*.lpc` (1909 files): 1876
  reformatted, 19 already-clean/unchanged, 14 self-checked errors
  (skipped, expected on legacy code).
- **Native re-test against the rebuilt driver** (`~/src/fluffos/build-debug/src/driver`):
  booted clean (only pre-existing compile warnings, no fatals). Full
  registration flow re-verified end-to-end with a fresh real Chinese
  name ("秦风廿一") — English id → confirm y/n → surname/Chinese name →
  password ×2 → attribute-roll accept (y) → email → gender → entered
  the actual 新手集中营 starting zone; `look`/`score`/`quit` all
  produced correct Chinese output. `log/debug.log` free of real errors.
  Reformat + new driver build introduced no regressions.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`): boots
  cleanly — the only preload-time errors are the expected non-fatal
  `Undefined function socket_create`/`socket_bind`/`socket_close` in
  `adm/daemons/httpd.lpc` (no `sockets` package under WASM, same known
  category as other libs, does not stop the boot). Full registration
  flow **completed successfully** under WASM with a real Chinese name
  ("秦风测试") — identical prompt sequence to the native run, reaching
  the same 新手集中营 room, `look` and `quit` both producing correct
  output. This lib does **not** gate its login/registration path on
  `query_ip_number()` format, so it isn't affected by the documented
  WASM IP-formatting limitation — a clean, fully-playable WASM result.

## WASM-enablement pass (2026-07, loopback/uptime/throttle + admin seed)

Standard WASM-first pass per AGENTS.md §1.3(b)/(e) and §1.5. Loopback =
`127.0.0.1`, any `127.` prefix, or an empty/non-string/malformed IP
(covers older WASM `query_ip_number()` garbage). Gates patched:

- `adm/daemons/band.lpc::is_banned()` (~line 39): loopback/malformed-IP
  short-circuit `return 0` at the top. (Note: no live login-path caller
  of `is_banned()` was found in this lib — the ban daemon appears vestigial
  — patched anyway for safety/uniformity.)
- `adm/daemons/logind.lpc::logon()` (~line 90-110): the per-host
  multi-login cap (`log_num >= 10` destruct) is now loopback-exempt.
  (Also disentangled the original single-statement `log_num++; if(...)`
  layout into an explicit post-loop check — semantics preserved: the
  check always ran after the counting loop.)
- `adm/daemons/logind.lpc::get_passwd()` (~line 188): the 16-second
  relogin-rate throttle ("为了降低系统负荷，请稍后再login" destruct) is
  now loopback-exempt.
- No `uptime()` startup-grace gate in this lib (only a cosmetic
  cmwhod.lpc comment). The `mad_lock` gate is an explicit admin lock
  (game admin feature), kept. The `banned_name` Chinese-name blocklist
  is content, kept.

Admin seed: registered `fluffos` / display 浮浮 / password `Mud@2026`
through the real flow (id → `y` → Chinese name → password x2 → gift `y`
→ email → gender m; one stray "What?" echo mid-flow is pre-existing
prompt noise, not a failure). Granted `(admin)` by appending
`fluffos (admin)` to `/adm/etc/wizlist`. Verified after reboot: login as
fluffos → wizard-channel login broadcast + `update /adm/daemons/logind`
→ "重新编译 ...成功！".

Retest: fresh normal registration (`qfxzyx` / 秦风) re-verified
end-to-end into 新手集中营 with `look`/`score`/`quit` correct; test
saves removed. No new errors in `log/debug.log`.

Save files for the orchestrator to add (both paths tracked, not
gitignored; note `data/user/f/` and `data/login/f/` are NEW directories
— this lib previously had no ids starting with "f"):
- `libs/xingzhanyingxiong/work/data/user/f/fluffos.o`
- `libs/xingzhanyingxiong/work/data/login/f/fluffos.o`
