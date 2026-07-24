# zzfy — 郑州风云3 (Zhengzhou Fengyun 3)

Archive: `zzfy (full).rar`. Port: 40025. Status: **done** (boots clean,
full registration flow verified end-to-end including a real Chinese name).

## What this is

Same 风云 (Fengyun) lineage as `fy2`/`fy2005`/`fengyun434` (archives #14,
#16, #17) — `adm/obj/master.lpc`/`adm/obj/simul_efun.lpc` layout, same
`adm/daemons/chinesed.lpc` + `adm/simul_efun/chinese.lpc` shape. Mudlib
root at `zzfy/fy3/`, config at `zzfy/config.fy3`. `readme.txt` says this
build ("郑州风云3") is provided by "长孙无情", described as one of the
more stable/established 风云-family sites, admin access via ID `xgchen`.
~10,293 raw files.

Registration flow here is architecturally simpler than the TMI-2/nitan
family processed earlier: there's no separate `new` keyword branch in
`get_id()` — every English id typed goes straight through
`check_legal_id()`, and if no save file exists for it, straight to the
"create new character?" confirmation. `"new"` is itself in the
`banned_id` list (line 20 of `logind.lpc`), so typing literal `new` is
correctly rejected as an illegal id, not a special command — don't
mistake this for a bug when retesting.

## Fixes applied

**AGENTS.md §15h (GBK byte-range Chinese detection)**, applied proactively
before first boot, same shape as the other fengyun-family libs:
- `adm/simul_efun/chinese.lpc`'s `is_chinese()`: GBK lead-byte range check
  (`str[0] > 160 && str[0] < 255`) → CJK Unicode codepoint range check
  (`str[0] >= 0x4e00 && str[0] <= 0x9fff`).
- `adm/daemons/logind.lpc`'s `check_legal_name()`: byte-count length bound
  (`< 2 || > 12`, "1 到 6 个中文字") halved to character count
  (`< 1 || > 6`); removed the `i%2==0` even-byte-offset gate so every
  character position is actually checked (not just every other one).

**§4 (lazy security-daemon load)**: not needed — `master.lpc`'s
`valid_write`/`valid_read` already gate `load_object(SECURITY_D)` behind
`find_object()` in this build.

## Interactive test result — full registration flow

Verified the complete registration path in one continuous connection:

1. Connect → banner → English-id prompt.
2. `zzfytest` → passes `check_legal_id`, reaches "使用 zzfytest
   这个名字将会创造一个新的人物，您确定吗(y/n)？".
3. `y` → reaches the Chinese-name prompt.
4. **Real Chinese name `萧峰`** → accepted by the fixed `check_legal_name`
   (no rejection message), proceeds straight to "请设定您的密码：" — the
   actual proof the §15h fix works, not just that the prompt renders.

Noted, not a bug: `get_name()` has a pre-existing `printf("%O\n", ob);`
debug line (prints the login object's default toString, e.g.
`/obj/login#0`) that fires right before the password prompt on a
successful name — leftover debug output from the original author,
harmless, left as-is (out of scope for a UTF-8 compatibility pass).

## lpcc sweep

9223 files, 8251 pass / 972 fail (89.5%). Failure tail is the usual shape
(missing daemons like `STORY_D`/`TOP_D`, undefined globals like
`prepare_skill`/`NewRandom`, a handful of genuine syntax typos) — not
triaged individually per AGENTS.md §6b/§13, boot + full interactive
registration test is the verification gate. Memory stayed healthy
throughout the sweep (~17-18GB free the whole time, no pressure).

## Re-verification pass: driver rebuild + formatter + WASM (2026-07)

- **LPC formatter** applied to all `.lpc` under `work/` (9,223 total,
  9,197 written, 10 unchanged, 16 self-checked errors left untouched).
- **Native re-test against the freshly rebuilt driver**
  (`~/src/fluffos/build-debug/src/driver`): clean boot, zero errors of
  any kind in `debug.log`. Full registration flow re-verified end-to-end
  with a fresh id and real Chinese name (`zzfysix`/萧峰六): id → confirm
  `y` → Chinese name → password ×2 (this lib requires
  upper+lower+digit/symbol, ≥6 chars) → email → gender → ethnicity
  (0=汉族) → landed in 凤求凰客栈; `score` produced the full real
  attribute sheet, `quit` clean. Same live-clock-prompt `--idle 0.4`
  pacing adjustment as other libs in this batch was needed here too.
- **WASM test** (`scripts/wasm_client.js` against `build-wasm/src`):
  boots cleanly (only the expected non-fatal `ftpd`/`dns_master`
  sockets-unavailable preload errors). **Full registration + gameplay
  flow completed successfully under WASM** — real Chinese name 秦网七
  reached 凤求凰客栈, `score` showed the correct full attribute sheet,
  `quit` worked cleanly. This lib's registration path does not gate on
  `query_ip_number()`'s format. Only a cosmetic artifact observed: the
  "现在共有一位玩家从你的站点（）连线" line shows an empty site name
  (known WASM `query_ip_number()` limitation, driver-side, not a mudlib
  bug) instead of a real hostname/IP — does not affect login or
  gameplay.

## WASM-enablement pass (2026-07): loopback gates + admin seeding

Standard pass per AGENTS.md §1.3b/§1.3e/§1.5:

- `adm/daemons/band.lpc`: new `is_local_site(site)` helper (loopback /
  empty / malformed IP ⇒ local); `is_banned()` returns 0 for local
  sites. (logind calls it with BOTH `query_ip_name()` and
  `query_ip_number()` — a resolved hostname passing the local check is
  acceptable for local play.)
- `adm/daemons/logind.lpc`:
  - `logon()`: `iplimit > 15` per-IP multi-login cap — loopback exempt.
  - `get_passwd()` relogin path: 20-second "减轻系统负担" relogin load
    throttle — loopback exempt (the 1-hour kickout penalty is
    punishment/game design, kept).
- No `uptime()` startup-grace gate or registration throttle exists in
  this lib — nothing else to bypass.
- Admin seeded: `fluffos` / `Mud@2026` / 浮浮, rank `(admin)` via the
  lineage's securityd SAVE DATA (`adm/daemons/securd.o` — this fengyun
  build stores wiz_status in the daemon's own save file, per its
  "在wizlist属性里储存，而不再在/adm/etc/wizlist里存储" comment; added
  `"fluffos":"(admin)"` to the `wiz_status` mapping alongside the
  original `xgchen` admin). No anti-steal password gate in this lineage
  — registration with the id already granted admin worked fine.
  Verified: relogin + `update /d/fy/fqkhotel.lpc` → 成功 (wizard-style
  room path display also confirms wizhood).
- Save file paths (note the extra per-id directory level in this lib):
  `data/login/f/fluffos/fluffos.o` + `data/user/f/fluffos/fluffos.o`.
- Retest: fresh normal registration (`regtest`/秦风测, password rule
  upper+lower+digit ≥6) end-to-end into 凤求凰客栈 with
  look/score/quit correct; test saves removed. debug.log clean (no
  error lines).

## WASM long-sit boot-watch pass (2026-07)

200s `scripts/wasm_boot_watch.sh` sit: no new findings beyond the
already-documented sockets-absent preload compile errors (`ftpd.lpc`,
`adm/daemons/network/dns_master.lpc` — caught by `master.lpc`'s
preload `catch()`, cosmetic). Proactively fixed
`adm/simul_efun/object.lpc`'s `file_owner()` (`return name` → `return
dir`) as part of a repo-wide port of a bug found live on sibling
`zhonghua2` (misattributes 3-level-deep `/u/<wiz>/<subdir>/<file>`
log_error writes to a bogus path); didn't fire in this lib's own sit,
fixed proactively since it's the identical shared file. Retest: fresh
registration (id `zzfsanty`) through look/score/quit, clean.
