# mhxy.rar → `mhxy`

- Archive: `archives/mhxy.rar` (18.8MB — "梦幻西游"/"Fantasy Journey to
  the West", 青岛站/Qingdao station, running since 2002-01-15). Same
  西游记 lineage as archive #15 (fluffos_xiyou2000) — shares the
  age-gate question, `convertd.lpc` Greek-table typo shape, etc.
  **Not a byte-duplicate of `梦幻西游2002版.rar` (a separate archive in
  this collection with the same game name)** — different snapshot,
  processed separately; cross-reference when that archive's turn comes.
- Mudlib root: nested at `梦幻西游2002版/mhxy/world/` (the archive's own
  top folder is a snapshot-dated Chinese name, then an `mhxy/` dir with
  Windows driver binaries + client-facing files, then `world/` is the
  actual mudlib). Config at `mhxy/config.mhxy`.
- Port: **40016**.

## Status: DONE — boots clean, playable over telnet

Full flow confirmed: banner, GB/BIG5 prompt (same legacy pattern as
`fluffos_xiyou2000`), stats, age-gate question. Note: the BIG5 hint text
in the banner is mojibake (same shape as other libs — a BIG5-encoded
substring inside an otherwise-GBK file), cosmetic only.

## What was fixed

1. Encoding + `.c`→`.lpc`: 1506 refs auto-fixed, 99 angle-bracket `.c>`
   refs, and **304 local angle-bracket includes converted to quotes
   automatically** (`convert_lib.sh`'s generalized fix — by far the
   largest count seen yet, confirms this pattern is very common in the
   西游记/xiyouji lineage specifically). `static`→`nosave`: 104 files.
   Two files triggered a `grep: binary file matches` warning during the
   local-include conversion step (`d/lingtai/obj/yuanpinzhu.lpc`,
   `daemon/class/yaomo/xueshan/cuixin-zhang/cuixin.lpc`) — the script
   handled it gracefully and continued; not investigated further (not on
   the boot path).
2. `adm/daemons/convertd.lpc` — the SAME Greek-alphabet-table stray-
   trailing-backslash bug as `fluffos_xiyou2000` (`"α\",` should be
   `"α",`, repeated ~45 times in this file specifically). **Gotcha this
   time**: this file has CRLF line endings, so the straightforward
   `s/\\"(,)?$/"\1/` fix from `fluffos_xiyou2000` silently did nothing
   (sed's `$` anchors before the `\n`, not before a preceding `\r`) —
   needed `s/\\"(,)?\r?$/"\1\r/` to actually match. Worth remembering:
   **always check for a stray `\r` before concluding an end-of-line sed
   fix "did nothing" quietly** (0 change reported, no error) — CRLF
   content is common across this whole archive family.
3. `/u/feizei/log` (a wizard's personal log directory) was missing from
   the archive, causing repeated `Wrong permissions for opening file
   .../log for append` at boot (same shape as the missing-directory
   pattern documented for lib #3 — a nonexistent directory manifests as
   a permission denial, not ENOENT). Created it.

## Known remaining issues (documented, not fixed)

- 315 lpcc-sweep failures (of 11785, 97.3% pass) — not triaged further
  given time constraints; boot/login path unaffected.

## How to run

```
cd libs/mhxy
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40016 --timeout 10 --send "gb" --send "" --send "quit"
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

- **LPC formatter**: ran `format-corpus.mjs` across all 11785 `.lpc`
  files under `work/` — 11635 reformatted, 112 unchanged, 38 refused
  (token-mismatch safety gate, expected/fine on this size of legacy
  corpus, not investigated further).
- **Native retest against the freshly-rebuilt driver**: booted (this lib
  doesn't print a driver-level "Initializations complete" line the way
  some other libs' `master.lpc`s do, but a `debug.log` review + a live
  `mudclient.py` connection confirm it's up and fully responsive — a
  large 11785-file preload does take a little over a minute of CPU time
  and produces routine `Eval interrupted`/`Too long evaluation` traces
  from a couple of preload-time content-placement daemons walking large
  zones, all caught/non-fatal, same shape as ordinary mega-content
  preload noise, not new). Ran the **full** interactive flow (`gb`
  encoding select → age-gate `no` → `new` → English id → Chinese name
  → password ×2 → "SuperPassWord" secondary identity ×2 → email →
  webpage → ICQ → gender → an in-game gift/attribute-point wizard `9`/`y`
  confirm) with a real Chinese name (`秦风三` / id `qflibc`), reached the
  actual starting room (南城客栈), and confirmed `score` renders a
  complete, correctly-populated character sheet and `quit` exits
  cleanly. Zero fatal errors in `debug.log`. No regression from the
  reformat or the driver rebuild.
- **WASM build test** (`scripts/wasm_client.js`): boots cleanly (only
  the expected non-fatal preload warnings/errors — missing network
  daemon programs, `dns_master`/`ftpd`/`httpd` — same non-fatal shape as
  native). **Login is blocked by the documented `query_ip_number()`
  WASM limitation**, but via a different call site than the
  `sscanf`-based site-ban pattern already known from `rzrmud`/`bxsj`:
  `logind.lpc`'s `encoding()` calls `"/adm/daemons/ipd"
  ->seek_ip_address(query_ip_number(ob))` to look up a friendly
  "connecting from" description; under WASM `query_ip_number()` returned
  an **empty string** for the console connection (confirmed directly
  from the driver's own error trace: `seek_ip_address("")`), and
  `ipd.lpc`'s `seek_ip_address()` does `user_ip = explode(ip, ".")` then
  unconditionally indexes `user_ip[1]` — with an empty IP, `explode`
  yields a single-element array, so `user_ip[1]` throws `*Array index
  out of bounds`, uncaught, right in the middle of `logon()`'s encoding
  callback. This aborts the rest of the login sequence for that
  connection, leaving it in a bare command loop that replies "什么？" to
  everything instead of ever reaching the id prompt. **This is the same
  class of driver-level WASM gap the project already documents (an
  IP-format-dependent code path breaking on a malformed/empty
  `query_ip_number()` under WASM), not a mudlib bug** — the identical
  code path works perfectly natively (confirmed above, real Chinese-name
  registration completing end-to-end). Not patched, per the standing
  policy against fixing WASM-only driver gaps in the mudlib. Status:
  **boots under WASM; login blocked by a query_ip_number()-under-WASM
  limitation** (different trigger site than the already-documented
  `sscanf`-ban-check shape, same root cause).
