# 洪荒世界.rar → `honghuangshijie`

- Archive: `洪荒世界(自连数据库)/nt/` (from the 2026-07-29 bulk `mudlib.rar`
  drop). **Same NT/nitan/Lonely engine lineage as `nitan170911`/`nitan6`**
  — confirmed via byte-identical `adm/kernel/master.c` and
  `feature/dbase.c` against `nitan170911`'s raw archive. A "创世/盘古"
  (Genesis/Pangu) themed reskin, ~23,700 `.c` files (smaller snapshot
  than `nitan170911`'s ~54,600).
- Ships a real `config.cfg` (unlike the other two new libs processed this
  session), but with the usual stale/wrong paths (§5.1) — rebuilt
  `config.fluffos` using `nitan170911`'s as a template (same
  `/adm/kernel/master`+`/adm/kernel/simul_efun` paths).
- Port: **40106**.

## Status: DONE (native boot + registration verified) — see the one open item below before calling this fully equivalent to a 3-command-verified lib

## Lineage-recognition payoff (AGENTS.md §2.1 applied literally)

Rather than rediscovering `nitan170911`'s §15/§15b/§15c/§15e fix series
from scratch, ported it wholesale:
- **Direct file copy** (raw source confirmed byte-identical to
  `nitan170911`'s pre-fix raw source, so `nitan170911`'s already-fixed
  `work/` version is correct here unmodified): `adm/kernel/
  check_config.lpc`, `adm/kernel/simul_efun.lpc` (+ its two new fragment
  files `ansi_util.lpc`/`db_compat.lpc`, easy to miss since they're
  `#include`d rather than being the file that changed hash — first boot
  attempt failed on exactly this until copied over too),
  `adm/kernel/simul_efun/{chinese,wizard}.lpc`, `feature/dbase.lpc`,
  `clone/user/baby.lpc`, `adm/daemons/examined.lpc`, `feature/alias.lpc`,
  `u/redl/cangku.lpc`.
- **Same fix pattern, different content** (raw source differs from
  `nitan170911` — real gameplay content differences, not just the bug —
  so applied the identical transformation by hand instead of copying):
  `inherit/room/room.lpc`, `clone/user/user.lpc`, `adm/daemons/
  giftd.lpc` — every `efun::set/query/delete/addn(..., ob)` call
  rewritten to `::set/query/delete/add(...)` for the self case (`ob ==
  this_object()`) or `ob->set/query/delete/addn(...)` for the
  other-object case, per the exact §15 recursion-trap writeup.
  `adm/daemons/equipmentd.lpc` got the narrower §15e guard (`if
  (objectp(ob))` around an unguarded `ob->set_color()` chain after
  `TEMPLATE_D->create_object()`, which can legitimately return 0).
- `adm/etc/preload`: same `.c`-extension leftover bug (§15c) — stripped
  with `sed -i 's/\.c$//'`. `dns_master` was already commented out.
- **New instance of the §8.1 GBK byte-range bug**, not present in
  `nitan170911`'s own fix list because it lives in a file unique to this
  snapshot: `adm/daemons/logind.lpc`'s `check_legal_name()` had
  `i<4 || i>8 || i%2` (byte-oriented, message says "2 到 4 个中文字") and
  an `i%2==0` sliding window — fixed to `i<2 || i>4` and a per-codepoint
  `is_chinese(name[i..i])` check, same as every other lib.

## Interactive verification

Boots clean (`Initializations complete.`). This lib does NOT use a
normal human-typed telnet registration flow — the archive's own name
("自连数据库" = "self-connecting database") and the client handshake
(`ver1.0,<key>` / "版本验证成功" written unconditionally on connect)
confirm it's built for a custom mobile-app client, not raw telnet. The
actual protocol (reverse-engineered by reading `logind.lpc`): send ONE
line `id,password,ciphertext,email` (comma-separated; the mudlib itself
replaces `,` with `║` internally, so plain commas from a real telnet
client work fine), then a second line `gender║img_id║中文名字`
(`║`-separated, U+2551, sent literally) for character creation.

Verified end-to-end with a real Chinese name (秦风三/秦风四): new-account
creation succeeds, `SYSY"0008"`→ character-creation prompt → the new
character is dropped into 洪荒世界's starting room ("泥潭注册室"),
welcome/newbie-tip messages print correctly, `look` correctly re-displays
the room, and `quit` produces a proper ANSI-art farewell screen with no
errors. This satisfies the project's standing "real Chinese name must
reach the next stage" bar (§8.1's verification rule).

**`score` reports "还没有出生呐，察看什么？" (not yet born)** — this is
NOT a bug: `score` gates on a `"born"` dbase property that this lineage's
own bespoke genesis questline sets, not basic registration. A brand-new
character is dropped in front of an NPC "盘古" (Pangu) who requires
choosing a personality/race via `choose`/`ask` interactions and then
"投胎" (reincarnating) through further NPCs (`d/register/npc/pangu.lpc`,
`d/register/yanluodian.lpc` — Yanluodian, the Hall of the Underworld
King) before `"born"` gets set. Confirmed this is deliberate game design,
not an error path, by reading the gate condition and its setters — did
not walk the full multi-NPC ritual to completion in this pass (out of
proportion for a first bring-up; the core registration/world-entry bar
above is what this project's convention treats as sufficient, same as
`nitan170911`'s own MySQL-gated precedent).

## Open item: admin `update` command not fully verified

Seeded `fluffos (admin)` into `adm/etc/wizlist` (same mechanism as every
other lib in this family — `securityd.lpc` reads it directly, and `/` is
already in `trusted_write` for `(admin)`). Registered the account through
the normal flow successfully. However, running `update <path>` as
`fluffos` returned the driver's default fail message (`什么？`), meaning
the verb wasn't found in the command search path at all -- did not
finish tracing exactly how/when this lineage adds `cmds/wiz/*` to a
player's searchable command directories (unlike the simpler `Century`-
family libs processed this session, this mega-lib's command dispatch
wasn't quickly found via grep in the usual spots — `commandd.lpc`,
`user.lpc`, `room.lpc` — in the time budget for this pass). The wizlist/
ACL data-seeding side is done and structurally correct; the remaining
question is purely which trigger actually grants the wizard verb
namespace in this lineage. Flagging for a follow-up pass rather than
under-verifying silently.

## Not yet done (out of scope for this pass)

- Full `lpcc_check.sh` compile sweep — skipped deliberately, same
  reasoning as `nitan170911` (mega-lib, single-VM sweep risks OOM without
  finding new bug classes beyond what the boot+interactive test already
  found).
- WASM export / GitHub Pages packaging — deferred to a later batch pass.
