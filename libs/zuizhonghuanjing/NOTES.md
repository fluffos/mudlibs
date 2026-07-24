# 最终幻境.zip → `zuizhonghuanjing`

- Archive: `archives/最终幻境.zip`. Mudlib root at the archive top level,
  alongside a bundled Windows `mudos.exe`/`mudos.log` (ignored — our own
  driver is used). ~1.6k raw files, 643 `.lpc` files after conversion —
  a small, focused lib (not a mega-lib).
- Identified via the archive's own `README`/`readme.txt`: this is
  **"The Final Frontier" v0.6e** ("最终边界"/"最终幻境"), an ES2-mudlib
  extension by Spock (`bbs.csmc.edu.tw/spock`), Traditional
  Chinese/BIG5-origin ("由著名的『打混蟑螂史巴克』所創立" — in-game
  banner credits "Spock, the roach"). `config.cfg`'s `name :` field and
  the in-game banner both confirm **最终幻境/The Final Frontier** as the
  actual mud name — matches the archive filename, no stale-name surprise
  (contrast AGENTS.md §5.1's `datangshuanglong`/`xiakexinzhuan2` cases).
- Proposed number: **061** (new, unique).
- Port: **40099** (as assigned; confirmed free).
- Status: **DONE** — boots clean, full registration verified end-to-end
  with a real Chinese name (韩风 natively, 沐晨 under WASM), admin
  (`fluffos`) verified via `update` on both drivers.

## Triage / lineage

Genuine LPC mudlib. This is the **ES II / 东方故事 mega-family** per
AGENTS.md §11 (explicit in-game credit: "FF 的 MUD 函數庫改寫自東方故事
II, 在此叩謝" — "FF's MUD library is adapted from ES2, thanks"), but a
distinct, much smaller/differently-shaped game from either
`sanjiechuanshuo` or `sanjieshenhua` — confirmed via diff (369-line
`master.lpc`/331-line `securityd.lpc`/658-line `logind.lpc` here vs
495/416 and 316/747 for the other two). Not a derivative of either
sibling in this batch.

## State at handoff (this session)

A previous agent session had already: extracted the archive, converted
encoding/renamed, written `config.fluffos` (port 40099), applied the §7.1
`load_object(SECURITY_D)` recursion guard in `master.lpc`, fixed
`private`→`nosave nomask` on `command_hook` (old copy kept alongside as
`feature/command.c.old` for reference), disabled `dns_master` in preload,
seeded `fluffos (admin)` in `adm/etc/wizlist`, and had ALREADY run a full
registration test through to a real Chinese name (`fluffos`/浮浮 and a
second test account `qinfeng`/秦风 both have complete `.o` saves under
`data/user/`/`data/login/`). This lib had no ban/site/uptime gates to
begin with (grepped for `is_banned`/`sited`/`uptime()`-gates — none
found), so no loopback-allow patch was needed here (documented as a
deliberate no-op, not an oversight). No NOTES.md/README.md existed yet.
This session verified the existing work end-to-end (native + WASM,
including the admin `update` check that hadn't been run yet) and found no
further code fixes were needed — `default_trusted_write` here already
includes `"(admin)"` for `/` out of the box (unlike sibling
`sanjieshenhua`'s commented-out default), so the admin write-ACL just
worked on the first try.

## Verification (native)

Booted `cd libs/zuizhonghuanjing && ~/src/fluffos/build-debug/src/driver
config.fluffos` — clean boot, zero fatal errors in `log/debug.log`.

Full registration flow (fresh id `haifengc`, real Chinese name **韩风**):
English id (3-20 lowercase letters; note — unlike the two 三界 siblings,
this lib has **no** special `new` keyword: ANY unregistered id goes
straight to a "create new character?" confirm) → `y` → Chinese name (1-10
hanzi) → password (≥5 chars) → confirm → email → **6-attribute point-buy**
(`str`/`dex`/`int`/`not`/`con`/`tec`, each within a fixed per-attribute
range, must sum to exactly 60 — e.g. `10 10 10 10 10 10`) → gender (m/f)
→ entered `FF 新手學院大廳` (newbie academy hall). `look`, `score` (full
attribute+combat stat card), and `quit` all correct.

Admin: logged in as `fluffos`/`Mud@2026` (already registered by the prior
session, display name 浮浮, `(admin)` status shown immediately via the
pre-seeded wizlist line) → `update /adm/obj/master.lpc` →
`重新編譯 /adm/obj/master.lpc﹕成功﹗` → `quit` clean. No data-file fix
needed (unlike `sanjieshenhua`) — this lib's `securityd.lpc` ships a live
(uncommented) `"/" : ({"Root","(admin)","(arch)"})` in
`default_trusted_write`.

## Verification (WASM)

`node scripts/wasm_client.js ~/src/fluffos/build-wasm/src
libs/zuizhonghuanjing` — same full registration flow (fresh id
`wasmren`, real Chinese name 沐晨) reached the same starting room;
`look`/`score`/`quit` all correct. Admin login as `fluffos` +
`update /adm/obj/master.lpc` also succeeded under WASM. **This lib is
fully playable under WASM** — no IP-format/sockets-absent blockers hit on
this login path, and no ban/site gate existed to need a loopback patch in
the first place.

## Known remaining issues (documented, not fixed)

- The archive's own in-game banner states the mud is no longer under
  active development by its original author ("即日起, 本 mud 停止研發") —
  cosmetic/historical, does not affect playability.
- lpcc sweep not re-run this session (no fresh `lpcc_fail.log`); the real
  boot + full interactive registration/admin test on both drivers is the
  verification gate actually used here (small lib, fast enough to fully
  play-test directly).

## How to run

```
cd libs/zuizhonghuanjing
~/src/fluffos/build-debug/src/driver config.fluffos
python3 ../../scripts/mudclient.py 127.0.0.1 40099 --timeout 20 --idle 1.0 \
  --send "yourid" --send "y" --send "你的中文名" \
  --send "yourpass" --send "yourpass" --send "you@example.com" \
  --send "10 10 10 10 10 10" --send "m" \
  --send "look" --send "score" --send "quit"
```
