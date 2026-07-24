# rzrmud — 大唐西游 YWX人造人 (Great Tang Journey to the West)

Archive: `rzrmud.20130220.tar.gz`. Port: 40020. Status: **done** (boots
clean, connects, plays through the age-verification gate, MOTD, username
validation, and into new-player registration with zero crashes).

## What this is

A different lineage from the "NT/nitan/Lonely" family (archives #21/#22)
— generic-looking MudOS 0.9.20-era mudlib, 9096 `.c` files, bundled with
prebuilt 32-bit Linux driver binaries (`driver`, `driver_2s_64bit_int`,
ignored — we use our own fluffos build). Archive nests the actual mudlib
root one level down at `rzrmud/world/`.

Notably, this lib's `adm/obj/simul_efun.lpc` does **not** define a global
`set`/`query`/`delete` at all (unlike the nitan family) — every object
that uses bare `query(...)`/`set(...)` relies entirely on its own
`inherit NPC;`-style base class providing them locally. This is the
architecturally *correct* pattern (see AGENTS.md §15's writeup of why the
nitan family's simul_efun-based version is broken on this driver) — no
`this_object()`-during-simul_efun-call trap here since the fallback path
essentially isn't used.

## Fixes applied

None beyond the standard mechanical pipeline (`convert_lib.sh`'s
encoding/rename/ref-fix/static→nosave passes). Booted clean and reached
deep into the login flow (age gate → MOTD → username validation → "new
player" registration sub-flow asking for an English name) on the **first
attempt**, zero runtime or compile errors in `debug.log`.

## Known content gap (not fixed — see AGENTS.md §13)

`scripts/lpcc_check.sh` sweep: 9096 files, 8865 pass / 231 fail (97.5%).
The largest failure clusters are a genuine but narrow content gap, not an
engine bug:

- **~55 files** under `d/kaifeng/npc/quest_*.lpc` (e.g. `quest_wr.lpc`,
  `quest_wp.lpc`) `#include` a shared `quest.lpc` fragment that calls bare
  `query("id")` and `::setup()`, but — unlike their sibling NPC files in
  the same directory (e.g. `chen.lpc`, which correctly has `inherit NPC;`
  before its own `#include "quest_ak.lpc"`) — these ~55 files have **no
  `inherit` statement of their own at all**, so there's no base class to
  provide `query`/`setup` and no simul_efun fallback either (this lib
  doesn't have one, see above). Nothing else in the mudlib references
  these files by path, so this can't be diagnosed as "meant to be
  `#include`d elsewhere instead" — it looks like a genuine omission in
  the original archive (a missing `inherit NPC;` line), scoped to one
  city's quest-giver NPCs. **Not fixed** — 55 near-identical one-line
  fixes for content in a single zone is out of proportion to this pass's
  goal (verify the engine boots/connects/plays); note here in case a
  future pass wants to batch-fix it (`sed` in `inherit NPC;` as the first
  line after any leading `#include <ansi.h>` for each affected file,
  verify each doesn't already get a base class some other way first).
- The remaining ~176 failures are a typical long tail (missing
  `#include` headers for specific quest content, a handful of genuine
  one-off syntax typos in individual room/npc files, a few raw non-UTF8
  bytes that survived the lossy encoding pass) — not investigated
  individually, consistent with AGENTS.md §6b/§13's guidance on sweep
  noise at this scale.

## Interactive test result

Connects, full ASCII-art banner renders, no crashes through: age-
verification prompt → MOTD/rules screen → username prompt (validates
length/alphabetic correctly) → "new" registration path → English-name
sub-prompt (also validates correctly). Did not create a full character
or play further into the game world (out of scope for this pass).

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

- **LPC formatter**: ran `format-corpus.mjs` across all 9096 `.lpc` files
  under `work/` — 8959 reformatted, 135 unchanged, 2 refused
  (token-mismatch safety gate, negligible on this lib).
- **Native retest against the freshly-rebuilt driver**: booted clean
  (`Initializations complete.`, zero fatal errors). This pass went
  further than the original conversion pass's test (which stopped at the
  English-name sub-prompt): ran the **complete** registration flow —
  encoding → age-gate → `new` → English id → Chinese name (`秦风九`) →
  admin/"super" password ×2 → login password ×2 → email (needs an
  `x@y.z`-shaped address) → gender → an in-game gift-allocation wizard
  (`9`/`y` to accept defaults) — and reached the actual starting room
  (南城客栈) with working NPCs/exits, `score` rendering a complete
  correct character sheet, and `quit` (with the standard "played <2
  minutes, still want to keep this account?" new-account prompt)
  working correctly. Zero fatal errors in `debug.log` across the whole
  session. No regression from the reformat or driver rebuild.
- **WASM build test** (`scripts/wasm_client.js`): **fully playable**,
  including a full real-name registration (`秦风十一` / id `qflibrv`)
  reaching 南城客栈 with correct room/NPC text, a correct `score` sheet,
  and a working `quit`. As with `mohuanshiji`, `debug.log` shows one
  non-fatal `*Array index out of bounds` trace from `adm/daemons/
  ipd.lpc`'s `seek_ip_address()` — the shared-lineage
  `query_ip_number()`-under-WASM limitation (an empty IP string breaks
  `explode(ip, ".")[1]` indexing) — but it fires from `enter_world()`'s
  cosmetic "connecting from…" welcome text, *after* the character
  already exists and is in the world, so it doesn't block anything.
  **Note for future passes**: this lib's `SECURITY_D->match_wiz_site()` /
  `"/adm/daemons/band"->is_banned()`/`create_char_banned()` calls (both
  IP-based) also depend on `query_ip_number()`, but neither fired during
  this test — `match_wiz_site` only gates *wizard*-level logins (not
  exercised here), and `is_banned`/`create_char_banned` evidently
  tolerate the WASM-mode IP string without throwing. Status: **fully
  playable under WASM** (same cosmetic, non-blocking IP-lookup error as
  `mohuanshiji`, not the login-blocking shape seen in `mhxy`/
  `moniHuafu`).

## WASM-enablement pass (2026-07-24): loopback-allow + admin seeding

Gates patched (same 西游记-lineage shapes as `mhxy`/`mohuanshiji`;
loopback = `127.0.0.1`, any `127.*`, or an empty/malformed
non-dotted-quad string, which is what current WASM builds return):

- `adm/daemons/band.lpc` — `is_banned()`, `create_char_banned()`,
  `is_strict_banned()` short-circuit return 0 for loopback;
  `allow_multi_login()` returns 1000 for loopback.
- `adm/daemons/logind.lpc` `encoding()` — new `local_conn` flag; the
  `!ip_name` destruct and the "Non_number" IP-character-scan destruct are
  skipped for loopback/malformed IPs.
- `adm/daemons/ipd.lpc` `seek_ip_address()` — returns "本地连接" for
  loopback/short IPs instead of the `explode(ip,".")[1]` out-of-bounds
  throw (previously cosmetic-only under WASM here, now gone entirely).
- `adm/daemons/securityd.lpc` `match_wiz_site()` — loopback always passes
  wizard site restrictions.
- No `uptime()` startup gate or reconnect throttle in this lib (checked);
  the `kickout_time` 10-minute punishment timer kept (game design).

Admin account: `fluffos`, 登陆密码 `Mud@2026`, 管理密码 `Mud@2026admin`
(this lineage sets the admin/recovery password FIRST and requires the two
to differ), Chinese name 浮浮, granted `(admin)` via `/adm/etc/wizlist`
(normalized CRLF→LF). Verified: real-flow registration reaching 南城客栈,
re-login ("您使用了登陆密码成功登陆！"), `update /adm/daemons/band.lpc`
succeeds. Saves at `data/login/f/fluffos.o` + `data/user/f/fluffos.o`
(untracked, not gitignored — orchestrator must add; note this lib also
ships a large pre-existing tracked player base under `data/user/`, which
was left untouched). Fresh normal registration (秦风/testqa) re-verified
end-to-end and its saves removed. debug.log: only transient cold-cache
"Eval interrupted / Too long evaluation" lines during the first world
entry (lazy compiles of big content files; a warm-cache login+look+score
session afterwards added zero new error lines) — same known mega-content
shape as `mhxy`, not introduced by this pass.

### Fail-closed retrofit (2026-07-24)

Same correction as the sibling `mhxy`/`mohuanshiji`: the loopback
carve-out originally ALSO treated any empty/non-string/unparseable IP as
trusted-local (fail-open, defensive against an older WASM
`query_ip_number()` bug now fixed upstream). Tightened to strict loopback
only across `band.lpc` (×4), `securityd.lpc`'s `match_wiz_site`,
`ipd.lpc` (falls back to "未知地区" for unparseable input instead of
"本地连接"), and `logind.lpc`'s `local_conn` flag. Re-verified loopback
login, `look`, `update`, and quit all still work after tightening.
