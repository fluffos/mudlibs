# 三界传说.rar → `sanjiechuanshuo`

- Archive: `archives/三界传说.rar`, nested at `sjcs/sjcs/` inside the RAR
  (mudlib root one level down from the archive top). ~12.8k raw files,
  10,873 `.lpc` files after conversion.
- Proposed number: **059** (new, unique — see "Lineage/triage" below).
- Port: **40097** (as assigned; confirmed free against every other lib's
  `config.fluffos` before use).
- Status: **DONE** — boots clean, full registration verified end-to-end
  with a real Chinese name (秦风) natively AND under WASM, admin (`fluffos`)
  verified via `update` on both drivers.

## Triage / lineage

`grep -rIl inherit` finds thousands of hits — genuine LPC mudlib, not a
non-LPC engine. Diffed core files (`master.lpc`, `securityd.lpc`,
`logind.lpc`) against sibling `sanjieshenhua` (also assigned to this
batch, same "三界" branding) — all three differ substantially in line
count and content (495 vs 416 lines for `master.lpc`, 316 vs 747 for
`securityd.lpc`, etc.) — **not** a derivative pair despite the shared
title prefix (per AGENTS.md §2.1's warning that titles are not a lineage
signal). One coincidental match: both libs ship a byte-identical corrupted
`d/sea/npc/beast1.lpc` (see below) — most likely just shared common
ancestry several forks back (both plausibly ES-II-mega-family descendants,
per AGENTS.md §11), not evidence the two archives are the same codebase.
Treated as a fully independent unique game.

## State at handoff (this session)

A previous agent session had already: extracted the archive, run the
encoding+rename conversion, written `config.fluffos` (port 40097), applied
the loopback-allow patch to `band.lpc`/`securityd.lpc`, fixed the
`private`→`nomask` `command_hook` bug (3 files), disabled `dns_master` in
preload, and registered+admin-seeded the `fluffos` account (wizlist entry
`fluffos (admin)` already present, character already existed with
Chinese name 浮浮). No NOTES.md/README.md existed yet. This session
picked up from there, verified the existing work, and found/fixed two
things the interrupted session hadn't reached yet (below).

## Fixes applied this session

1. **166 files stuck as literal uppercase `.C`** (not renamed to `.lpc`)
   — exactly AGENTS.md §4.2 item 7's known trap (the rename glob and the
   forced-text-extension conversion check are both case-sensitive).
   Spread across `clone/armor/`, `clone/bq/`, `cmds/adm/`, `d/qujing/...`,
   `u/tonggang/...` — mostly clonable weapon/armor templates and a few
   NPCs/commands. Verified no lowercase `.c`/`.lpc` sibling existed at the
   same path (so no "which one is authoritative" ambiguity, unlike
   AGENTS.md's `zitengzhan` case) before a blanket `.C`→`.lpc` rename.
   Most were already correctly UTF-8 (the conversion pass's `file`-based
   text detection caught them fine even with the wrong extension); 6 were
   still raw GBK and needed an explicit `iconv -f GB18030 -t UTF-8` pass
   after the rename (`adm/CL/{SHUSHAN,HELL,MOON,LONGGONG,JJF,QIANG}.lpc`).
2. **2 genuinely-corrupted files** found by a full tree-wide Python
   UTF-8-decode scan (AGENTS.md §4.1's "stronger check"), both truncated
   mid-statement with a garbage binary tail in the RAW archive itself
   (confirmed via `xxd` against `raw/sjcs/sjcs/world/...` — not something
   the conversion pipeline broke):
   - `d/qujing/start/24/12.lpc` — truncated mid-`carry_object(...)` call;
     closed the file after the last complete statement with a comment
     noting the drop, per AGENTS.md §6.6 ("close truncated files with an
     empty body; don't fabricate content").
   - `d/obj/quest/shuijingqiu.lpc` — truncated mid-call
     (`...locate_quest(this_player(),arg` + garbage); completed the
     obviously-intended `);\n}` (matching the sibling `do_task()`
     function's identical one-statement-else shape) rather than stubbing
     it out, since the completion was unambiguous.
   - `d/sea/npc/beast1.lpc` — trailing 2 garbage bytes (`\xff\xba`) right
     after a clean `}\n\n` ending; simply truncated the 2 bytes. (Same
     exact corruption, same byte offset, found in sibling `sanjieshenhua`
     — see that lib's NOTES.md.)

## Verification (native)

Booted `cd libs/sanjiechuanshuo && ~/src/fluffos/build-debug/src/driver
config.fluffos` — clean boot, zero fatal errors in `log/debug.log` (only
the usual `#pragma`/unused-variable warnings).

Full registration flow (fresh id `wenshua`, real Chinese name **秦风**):
`gb` (encoding) → `no` (not-a-student gate) → `new` → English id (3-8
lowercase letters only) → Chinese name → password → confirm → email →
gender (m/f) → gift/stat menu (`9` to accept defaults, `y` to confirm) →
entered `南城客栈` (starting room). `look`, `score` (full 个人档案 stat
card), and `quit` all produced correct output.

Admin: logged in as `fluffos`/`Mud@2026` (already registered by the prior
session, character name 浮浮, `fluffos (admin)` line in
`adm/etc/wizlist`) → `update /adm/obj/master.lpc` → `重新编译
/adm/obj/master.lpc：成功！` (wizard write ACL confirmed working) →
`quit` clean.

## Verification (WASM)

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/sanjiechuanshuo` — same full registration flow (fresh id `wenshua`,
name 秦风) reached the same starting room; `look`/`score`/`quit` all
correct. Admin login as `fluffos` + `update /adm/obj/master.lpc` also
succeeded under WASM. **This lib is fully playable under WASM**, not just
"boots" — no IP-format/sockets-absent blockers hit on this lineage's
login path.

## Known remaining issues (documented, not fixed)

- The lpcc batch sweep (`lpcc_batch_raw.log`/`lpcc_fail.log`, retained in
  this dir) shows 422 failures out of ~10.8k files — not triaged
  individually past the two real content bugs above; per AGENTS.md §10.4
  most of these are expected false positives (missing daemons like
  `CLUB_D`/`F_DISASTER` that don't exist in this archive, `tail()` not a
  real efun here, `dump_socket_status()` admin-only debug commands) —
  cross-checked against the clean real boot log, none of them block the
  verified login/play path.
- A minor cosmetic gap: the first preload compile logs "Wrong permissions
  for opening file /u/feizei/log for append" (missing per-user log
  subdirectory for one wizard's home dir) — harmless, caught by the
  driver's own error handler, does not affect play.

## How to run

```
cd libs/sanjiechuanshuo
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40097 --timeout 15 \
  --send "gb" --send "no" --send "new" --send "yourid" \
  --send "你的中文名" --send "yourpass" --send "yourpass" \
  --send "you@example.com" --send "m" --send "9" --send "y" \
  --send "look" --send "score" --send "quit"
```

## 深度功能测试 / Deep functional test (round two, AGENTS.md §10.7)

Native driver, port 40097, tested via raw socket (finer control over
timing than `mudclient.py` for this lib's charset→age-check→id/New→
Chinese-name→password×2→email→gender→gift-selection wizard). Test
characters: `qfthree`/秦风三 (password `TestPassA`) is a clean, fully-
completed registration used for the main playthrough; `qftester` and
`qftwo` are two earlier registrations deliberately left stuck mid-gift-
wizard (see bug below) and kept as before/after evidence.

**Bug found and fixed, live-reproduced and re-verified**: `d/wiz/init.lpc`'s
`init()` schedules `call_out("get_start0", 0, me)` on every reconnect
while the account's gift-selection wizard is still incomplete
(`no_gift` still set), meant to automatically re-show the gift menu so
the player isn't left wondering what happened. `get_start0()` tried to
do this via `me->command("start")` — but the real `command()` efun
(`core.spec`: `int command(string)`) takes no object argument, so this
is a call_other to a method named `command` that is not defined
anywhere on the player object (confirmed via a lib-wide grep). FluffOS
silently no-ops an undefined call_other with no error raised anywhere
(not even in debug.log), so this reconnect path produced **zero visible
output**: a player reconnecting mid-wizard saw nothing at all after
"重新连线完毕。" — no menu, no error, no hint — and the only way out
was to already know to type the undocumented `start` command
themselves (confirmed live: typing `start` manually DID correctly
redisplay the menu, since that add_action registration itself works
fine). Root-caused by directly inspecting `data/user/q/*.o` for
`no_gift`, then confirming live with a raw-socket test that showed
identical silence even after a genuine 10-second wait.

Fixed by rewriting `get_start0()` to replicate `get_start1()`'s body
directly (using `tell_object(me, ...)` instead of `write()`, since
`write()` implicitly targets `this_player()`, which is unset inside a
call_out) and calling `get_start(me)` directly instead of round-
tripping through the broken `command()` call. Also fixed `show_gift()`
the same way (`write()` → `tell_object(me, ...)`), since it's reached
via the same call_out path. Verified live: after the fix, reconnecting
to a mid-wizard account (`qftwo`) auto-displays the full gift menu
within seconds with no manual `start` needed, matching the intended
"重新连线完毕" → immediate resume UX. A fresh, uninterrupted
registration (id → New → Chinese name → password ×2 → email → gender →
gift accept `9`+`y`) was independently confirmed to already work
correctly end-to-end (lands cleanly in 南城客栈/South City Inn per the
newbie doc), so this bug specifically affects the reconnect-while-
mid-wizard path, not first-time registration.

**Verified working**: full registration flow, `look`/`score`/`hp` all
render correctly with rich, properly-escaped ANSI formatting (no
orphaned escape sequences), clean `quit`. debug.log/driver stdout show
only pre-existing harmless compile warnings (unused locals, unknown
`#pragma`) throughout — no new runtime errors from any of this session's
testing.

**Not verified live this pass** (time budget went to the reconnect-
wizard investigation above): net-dead disconnect/reconnect after actual
gameplay has begun, skill learning, sect/faction join, shop purchase,
combat. Given the newbie doc's own detailed skill/combat/shop
instructions, this lib very likely has full playable content beyond
the registration wizard — a future pass should pick up from a
`qfthree`-style completed character and continue the rest of the §10.7
checklist.

**Files modified**: `libs/sanjiechuanshuo/work/d/wiz/init.lpc` (the fix
above). Test character saves kept as before/after evidence rather than
removed.
