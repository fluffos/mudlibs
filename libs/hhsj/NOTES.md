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

## Status: WASM playable (native boot + registration + admin all verified)

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

## Resolved (WASM pass): the "什么？" on EVERY command was a real bug, not a command-search-path gap

The open item above under-diagnosed the symptom -- the "什么？" wasn't
specific to `update`/wizard commands, it happened for `look`/`score`/
literally everything, for every freshly-registered character (not just
`fluffos`). Root cause (found via `write()`-based bisection through
`get_char()` since `log_file()` output doesn't persist across separate
WASM invocations): `adm/daemons/named.lpc`'s `create()` calls a bare
`restore()` on its own ~168KB save file, which throws
`*restore_object(): Illegal mapping format while restoring dbase.`
uncaught. On THIS driver build, an uncaught error during `create()`
leaves the object permanently non-resident (`find_object()` returns 0)
rather than crashing loudly or completing with partial state -- and
critically, a later implicit `NAME_D->invalid_new_name(...)` call-string
invocation on the still-not-resident object silently does nothing at
all (no error, no output, the call just never completes) instead of
auto-compiling it the way an explicit `load_object(NAME_D)` would. Since
`get_char()` (character creation) calls `NAME_D->invalid_new_name()`
before ever calling `make_body()`, EVERY new character creation attempt
silently died at that exact point -- no crash, no error, just an
`input_to` chain that never reaches `call_out("enter_world", ...)`,
leaving the connection wedged in the driver's default command loop with
no `path` ever set, hence every subsequent command hitting the generic
`什么？` fail message forever. Fixed with the standard corrupted-shipped-
save-data guard: `catch(restore())` in `named.lpc`'s `create()` (AGENTS.md
§7.41 class). This is a genuine mudlib bug independent of WASM -- the
native pass above hit the exact same wall and, not being able to `write()`
-debug an apparently call-that-does-nothing, incorrectly attributed it to
a command-dispatch/path question instead. Verified post-fix: full
registration → `look`/`score` → `fluffos` routed to 巫师休息室 (wizard
rest room, confirming `(boss)`/`(admin)` status is recognized) →
`update /adm/daemons/named.lpc` succeeds ("重新编译 ... ：成功！").
Also upgraded the wizlist entry from `fluffos (admin)` to `fluffos
(boss)` -- this lineage's `wiz_levels` ranks `(boss)` above `(admin)` as
the actual top tier, confirmed present in `securityd.lpc`'s
`trusted_read`/`trusted_write["/"]`.

Unrelated non-blocking runtime error observed only on the `fluffos`/
wizard-room entry path (not on regular player registration): `adm/kernel/
simul_efun/message.lpc:346`, "Bad argument 4 to EFUN message() Expected:
object, array, Got: int(0)" -- doesn't block anything (room description
still prints correctly afterward), not chased further this pass.

## LPC formatter (WASM pass)

Ran across all 24177 `.lpc`/`.h` files (24082 written). Blind-spot check
found 5 files with confirmed CJK re-spacing corruption (`d/yixing/doc/
set_bang.h`, `help/family.h`, `help/intro.h`, `help/map.h`, `u/lonely/
skybook/lianchengjue.lpc`) via a same-text-despaced-matches-old-file scan
across all 287 formatter-touched files containing CJK-space-CJK
sequences; all 5 reverted. Also directly diff-reviewed all 6 `map.lpc`
ASCII-art zone-map files in this lib (`d/shaolin`, `d/emei`, `d/city`,
`d/guanwai`, `d/gaochang`, `quest/skybook/xsfh`) since box-drawing art
doesn't match the CJK-space regex -- all 6 clean (only cosmetic
brace/spacing reformatting, string-literal content byte-identical).
Post-formatter re-verified: clean boot, zero compile errors, registration
and admin `update` both still working.

## Not yet done (out of scope for this pass)

- Full `lpcc_check.sh` compile sweep — skipped deliberately, same
  reasoning as `nitan170911` (mega-lib, single-VM sweep risks OOM without
  finding new bug classes beyond what the boot+interactive test already
  found).
- WASM export / GitHub Pages packaging — deferred to a later batch pass.
