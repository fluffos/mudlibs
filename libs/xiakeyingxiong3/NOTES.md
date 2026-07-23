# xiakeyingxiong3 — 侠客英雄传 III

Archive: `侠客英雄传III 可用.zip`. Port: 40036. Status: **done** (boots
clean and quick, full registration flow verified end-to-end including a
real Chinese name).

## What this is

"侠客英雄传" — its own connection banner describes the setting as "以
金庸小说、西欧中世纪传说及漫画为背景的世界" (a world set against a
backdrop of Jin Yong novels, Western European medieval legend, and
manga — an unusual crossover premise). `adm/obj/{master,simul_efun}`
layout. Small lib, ~3,839 raw files.

## Fixes applied

1. **AGENTS.md §15h**, with a pre-existing (non-UTF8) typo along for the
   ride: `adm/daemons/chinesed.c`'s `is_chinese()` had a `for` loop that
   always checked `str[0]` instead of `str[i]` — a genuine authoring bug
   predating this pass, not introduced by conversion. It was **harmless
   in practice** because the only caller, `logind.lpc`'s
   `check_legal_name()`, always invokes it with a fresh per-character
   slice (`CHINESE_D->is_chinese(name[i..<0])`) — so "always check index
   0 of whatever was passed" is equivalent to "check character i of the
   original name." Fixed to the standard single-character CJK codepoint
   check, which preserves this same effective (harmless) behavior while
   correcting the actual GBK byte-range logic (dropped the now-
   meaningless even-byte-length check and the loop, since only the first
   character of the argument ever mattered anyway).
2. `check_legal_name()`'s bound `strlen(name) < 2 || > 12` → `< 1 || > 6`
   (halved to character count), removed the `i % 2==0` even-byte-offset
   gate.
3. **AGENTS.md §15p**: `/adm/daemons/network/dns_master` was in
   `adm/etc/preload` — removed proactively before the first boot
   attempt. Booted clean in well under 10 seconds, zero compile errors,
   no hang.

## Interactive test result — full registration flow

No hidden pre-id prompts here (banner → stats → straight to the English
id prompt). Verified the complete registration path in one continuous
connection: id `xkyxbtest` → confirm `y` → **real Chinese name `秦风`**
(avoiding "张三丰"/Zhang Sanfeng — a real historical/wuxia figure found
in this lib's `banned_name` list, alongside game-specific terms) →
accepted, proceeds straight to "请设定您的密码：".

## lpcc sweep

3,178 files, 3,116 pass / 62 fail (98.0%). Failure tail is the usual
shape (missing globals, a handful of syntax typos) — not triaged
individually per AGENTS.md §6b/§13. Memory stayed healthy throughout
(~13GB free).

## Re-verification pass (2026-07-23)

Boot + registration re-tested end-to-end (real Chinese name 秦岭, English
id + race selection this time, since the original pass only verified up
to the password prompt). Found and fixed one new regression, same bug
class as AGENTS.md §15ah:

- **Missing `/log/nosave/` directory** (archive shipped without it, same
  "RAR/zip drops empty dirs" class as several sibling libs): `enter_world()`
  in `adm/daemons/logind.lpc` unconditionally `log_file("nosave/WARNING",
  ...)`s a potential/exp sanity-check note for every new player, and
  `adm/simul_efun/file.lpc`'s `log_file()` did an unguarded
  `write_file()` with no directory to write into — this **runtime error
  aborted the rest of `enter_world()`**, so the new character was never
  actually `move()`d to the start room (`look` showed the literal empty
  void, "你的四周灰蒙蒙地一片"), and `quit`'s `message("system", ...,
  environment(me), me)` then crashed on `environment(me)` being `0`
  (`Bad argument 3 to EFUN message()`). Fixed by creating `work/log/nosave/`
  and hardening `log_file()` (wrap `write_file()` in `catch()`) and `cat()`
  (guard with `stringp()`) in `adm/simul_efun/file.lpc`, matching the
  established pattern from sibling libs. Re-verified with a fresh
  registration (id `xkyxfixver`, name `秦岭`): `look` now shows the real
  start room content (the color-dog greeting from `d/beginner/start1.lpc`),
  `score` renders correctly, and `quit` completes cleanly with zero
  runtime errors in `debug.log`.

## Driver rebuild / formatter / WASM pass (2026-07-23)

- **LPC formatter** (`tools/lpc-syntax/format-corpus.mjs`) run over all
  `work/*.lpc`: 3,178 total, 3,146 written, 21 already-idempotent, 11
  refused (self-check errors — expected on messy legacy code, not chased).
- **Native retest against the freshly-rebuilt driver** (`build-debug`,
  rebuilt from latest upstream master today): clean boot, zero fatal
  errors. Full registration flow re-verified end-to-end in one continuous
  connection (id `qinlingueb`, real Chinese name `秦岭岳`, race `0`/human,
  gender `m`): `look` showed the real 小花狗/color-dog start-room greeting,
  `score` rendered the full character sheet, `quit` completed cleanly.
  Zero code changes needed — the reformatted source booted and played
  identically to before formatting.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm`): boots
  clean through preload (only the expected non-fatal `ftpd` preload
  error, same shape as native). The banner displays correctly, but the
  single WASM connection then dies during `logind.lpc`'s
  visitor-counter bookkeeping (`write_file(LOG_DIR "login/users", ...)`)
  before the English-name prompt is ever reached — **not the documented
  `query_ip_number()` limitation**, but a different WASM-harness gap:
  `wasm_client.js`'s `copyDir()` deliberately only creates a bare `log/`
  directory in the in-memory FS (skips copying subdirectory contents to
  avoid runtime-churn bloat), so `log/login/` doesn't exist inside the
  WASM instance even though it's a real, populated directory in the
  native `work/` tree. The unguarded `write_file()` in `logind.lpc`
  (not the hardened `log_file()` simul_efun) throws, and the connection
  is dropped. **Not a mudlib bug** — natively this directory exists and
  the counter update works fine — and not patched here (out of this
  pass's scope to modify the shared test harness or add defensive
  wrapping for a directory that's only missing under this specific
  test tool). Playability under WASM for this lib should be considered
  "boots, but blocked at the very first prompt by a harness FS gap,"
  distinct from the true IP-gating limitation seen on other libs.
