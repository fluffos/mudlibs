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
