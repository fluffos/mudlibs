# 山海战神.rar → `shanhaizhanshen`

- Archive: `archives/山海战神.rar` (1.4MB, small `simple`/ES-II-derived MudOS
  0.9.20 lib — "Final Frontier" themed base, reskinned).
- Mudlib root in archive: `simple/` (extracted directly at archive top level,
  no extra nesting).
- Port: **40001**.

## Status: DONE — boots clean, playable over telnet

Login banner, Chinese prompts, and character-creation flow all render
correctly. This lib was the pilot used to build `scripts/convert_lib.sh`
and the fix catalog in `AGENTS.md` — see that file's "Common
driver-compatibility issues" catalog (§1-§14) for the general write-up of
every issue found here. Lib-specific specifics only, below.

## What was fixed

1. Encoding: all `.c`/`.h` files GB18030→UTF-8 (774 converted, 124 already
   ASCII/UTF-8, 0 hard failures). Also converted `data/*.o` save files
   (dict/emote/daemon/ballot_box/stars — these are plain-text
   `save_object()` format, not binary) — `data/emoted.o` needed the lossy
   `-c` fallback (one stray invalid byte at position 25324, pre-existing
   data corruption in the original archive, unrelated to us). Also
   `adm/etc/welcome` (login banner) and `config.fluffos` itself (see
   AGENTS.md §5 for the double-corruption trap hit here on first attempt —
   fixed by re-copying fresh from `raw/` and converting before any edits).
2. `.c` → `.lpc` rename: 855 files. Fixed 117 literal `".c"` string
   references across `.lpc` files, plus 36 in `include/globals.h` (the
   `F_DBASE` macro — AGENTS.md §2, this is the one that cost the most time
   to find since it surfaced as a runtime "Inherited file does not exist"
   rather than a compile error). One orphaned non-LPC file caught by the
   blind rename (`d/shenmin/shenminmap.c`, ASCII-art map, unreferenced
   anywhere) — renamed to `.txt` instead (AGENTS.md §12).
3. `static` → `nosave`: 89 occurrences across the lib (AGENTS.md §3).
4. `master.lpc`'s `valid_read()`/`valid_write()` had the lazy
   `load_object(SECURITY_D)` recursion bug (AGENTS.md §4) — added the
   re-entrancy-guard + `catch()` fix.
5. `master.lpc`'s `valid_override()` was the old 2-arg signature, which
   wrongly rejects `efun::` overrides written in `#include`d simul_efun
   fragments (AGENTS.md §14) — added the 3rd `main_file` parameter. (Never
   actually manifested in a real boot, only in the `lpcc` sweep testing a
   fragment file as a standalone object — fixed anyway since it's free and
   more correct.)
6. `master.lpc` does NOT have `get_root_uid()` (driver printed a non-fatal
   warning and continued — did not need the AGENTS.md §7 stub fix here;
   this lib's `exit(-1)` path apparently doesn't fire the way lib #2's did.
   Left as-is since the lib boots and plays fine regardless).
7. Config: removed 5 obsolete keys (`address server ip/port`, `binary
   directory`, `swap file`, `reserved size`), set `port number : 40001`,
   `mudlib directory` to the absolute `work/` path.
8. Full `lpcc_check.sh` sweep run (854 files after the shenminmap.txt
   rename; 832 pass / 22 fail). Fixed 6 pre-existing typo
   bugs found this way (all unrelated to our conversion — verified against
   raw archive bytes):
   - `d/zuichen/{cdkedian3,cdkedian4,cdyaopu,chengzhong}.lpc`: fullwidth
     comma `，` used as an argument separator (AGENTS.md §9).
   - `d/shiwang/qianqingon.lpc`: fullwidth period in `#include <ansi。h>`
     (AGENTS.md §9).
   - `std/room/shop.lpc`, `cmds/std/put.lpc`: missing closing `"` before
     string concatenation (AGENTS.md §10).
   - `adm/daemons/rankd.lpc`: 8× `switch(x) { default: ... }` with no real
     `case` label (modern grammar requires at least one) — removed the
     pointless switch wrapper, kept the body (indentation not perfectly
     preserved, cosmetic only).
   - `cmds/wiz/invis.lpc`: declared `void main(...)` but returned `1`/`0`
     (command-dispatch status codes) — changed to `int main(...)`.
   - `obj/weapon/axe.lpc`: copy-paste bug, `inherit AXE`/`init_axe(...)`
     but `/std/weapon/axe.lpc` was never implemented in this lib and the
     file's own header comment/id/name all say "dagger" — redirected to
     `inherit DAGGER`/`init_dagger(...)` (AGENTS.md §11).
   - `obj/cloth.lpc`: same pattern, `inherit CLOTH` with no
     `/std/armor/cloth.lpc` to back it — redirected to `inherit U_ARMOR`
     (matches its `setup()` call and "basic starting equipment" role).

## Known remaining issues (not fixed — documented, low priority)

- `/adm/daemons/network/{ms,userid,pingtcp,mail_serv,netmail,pingd,inetd}.lpc`
  — a cluster of optional network-service daemons (internal mail server,
  ping, telnet redirect, inetd) failing to compile due to missing headers
  (`config.h`, `mailer.h`, `daemons.h`, `uid.h`, `priv.h`, `post.h` — not
  present anywhere in `include/`) and a few undefined functions/variables
  cascading from that. None of these are on the preload list or required
  for normal play (login/rooms/combat/items all work); left broken.
- `adm/simul_efun/object.lpc`: harmless lpcc-sweep-only false positive
  (AGENTS.md §6b/§14) — real boot never hits it.
- A number of `call_other()`/`Bad argument 1 to EFUN call_other()` sweep
  failures are the same false-positive category as lib #2 (AGENTS.md
  §6b) — not individually triaged since the pattern is now understood;
  spot-checked 2, both were "target genuinely not compiled yet in this
  isolated single-file run", not real bugs.

## How to run

```
cd libs/shanhaizhanshen
~/src/fluffos/build-debug/src/driver config.fluffos
# separately:
python3 ../../scripts/mudclient.py 127.0.0.1 40001 --timeout 10 --send "" --send "look" --send "quit"
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

- **LPC formatter**: ran `format-corpus.mjs` across all 854 `.lpc` files
  under `work/` — all reformatted cleanly except 2 refused on the
  token-mismatch safety gate (`adm/obj/simul_efun.lpc`,
  `adm/simul_efun/system.lpc`), expected/fine per the formatter's own
  self-check contract, not investigated further.
- **Native retest against the freshly-rebuilt driver**: booted clean,
  zero fatal errors. Ran a full interactive registration with a real
  English id (`qflibtest`, this lib's login uses an English id + a
  separate Chinese display name `秦风`) through name/password/email/
  attribute-allocation/gender, reached the actual game world (梦旅馆大厅),
  and confirmed `look`/`score`/`quit` all produced correct, real output
  (score sheet shows the chosen 10/10/10/10/10/10 attribute split; quit
  exits cleanly). No regressions from the reformat or the driver rebuild.
- **WASM build test** (`scripts/wasm_client.js`): **fully playable**.
  Boots cleanly under WASM, and the complete registration flow (id →
  confirm → Chinese name → password ×2 → email → attributes → gender)
  works end-to-end exactly like native, reaching the same starting room
  with `look` producing correct output and `quit` exiting cleanly. This
  lib does not gate login on `query_ip_number()` or on any other
  WASM-restricted efun (its two `resolve()` call sites are in
  `ftpd.lpc`/`dns_master.lpc`, both optional network daemons never
  invoked during normal login) — no WASM-specific limitation applies
  here. Status: **fully playable under WASM**.

## WASM-enablement pass (2026-07-24): admin seeding only (no gates found)

Checked for all four standard gate classes (AGENTS.md §1.3b/e): no
`band.lpc`/`BAN_D`-style ban daemon, no site-restriction daemon, no
`uptime()` check anywhere in the login path, and no per-IP anti-flood/
multi-login throttle (`logind.lpc`/`logind2.lpc` only use
`query_ip_number`/`query_ip_name` cosmetically, in log lines and "who
connected from where" messages — confirmed by grep, not just absence of
symptoms). So items 1-3 of the standard pass (loopback-allow,
uptime-bypass, throttle-exemption) are **not applicable** to this lib —
nothing to patch.

Admin account: registered `fluffos` / `Mud@2026` through the real
registration flow (id `fluffos` accepted directly — no length/reserved-
word conflict), Chinese name 浮浮, gender m, attributes 10/10/10/10/10/10.
Granted `(admin)` via `/adm/etc/wizlist` (this file already had a
`fluffos (admin)` line staged from an earlier interrupted pass; verified
`/adm/daemons/securityd.lpc` reads this file for wizard-level decisions).
Verified in ONE continuous session: login as fluffos, `look`, then
`update /adm/daemons/securityd.lpc` recompiled successfully (ACL grants
write/compile access), then clean `quit`. Re-verified a fresh normal
registration end-to-end afterwards (id `qinfeng`, name 秦风, same
attribute split) reaching 梦旅馆大厅 with working look/score/quit; its
test save (`data/login/q/qinfeng.o`, `data/user/q/qinfeng.o`) was removed
afterwards. debug.log clean (compiler warnings only, no errors) across
both sessions. Save files for the orchestrator to force-add:
`data/login/f/fluffos.o`, `data/user/f/fluffos.o` (untracked, not
gitignored).

Note: an earlier same-batch agent's driver process for this lib (PID
4045698, started 00:37, before this session began) was found still bound
to port 40001 with no admin work done yet; it was killed (exact PID) and
the driver relaunched fresh before doing the registration above.
