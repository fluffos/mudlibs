# Acme MUD (acme) — porting notes

Source: assembled from four GitHub repos (all `acmemud/*`, author
bobalu113 / `devo@eotl`):

- `https://github.com/acmemud/acme-mudlib` commit
  `8bfa42587d1cb4a7606b73cdce760673582a924d` (“renamed project”,
  2017-01-15) — mudlib root (`secure/master.c`, `.gitmodules`)
- `https://github.com/acmemud/acme-platform` commit
  `d210b0335889c82266cef22bef296666eb14ac9f` (2017-02-01)
- `https://github.com/acmemud/acme-flavor-basic` commit
  `af56a1b8d56943362d0b4e92b399c3945d98356d` (2017-01-15)
- `https://github.com/acmemud/acme-flavor-rpg` commit
  `c2b2160727f84d0405e0e751c164962cbdf17daf` (“got login prompt
  working”, 2016-04-09)

Converted 2026-09-05. Config name `Acme`. Slug `acme`, number **969**,
port **40278**. This collection’s copy is a snapshot, not a live
mirror.

Unique experimental LDMud 3.x framework (welcome: “Welcome to Acme MUD,
formerly untitled gamification platform.”). Not a duplicate of any
existing lib. `Cloudxtreme/eotl-mudlib` is only a utility fragment and
was not onboarded.

Do not onboard `acmemud/acme-mudlib` (or its three sibling repos)
again. Do not treat the original `/platform/.obj/login` path as the
live FluffOS login — it does not compile here.

## 0. Layout

Repo root **is** the mudlib, but the published `acme-mudlib` git
checkout is a submodule stub (`platform`, `flavor/acme-basic`,
`flavor/acme-rpg` via SSH URLs). Those three sibling repos were cloned
over HTTPS and rsync’d into `raw/` so the tree is complete.

`/secure/master.c` is an LDMud 3.x master (`set_driver_hook`,
`unbound_lambda`, `#'` closures, `inaugurate_master`). Simul
`/secure/simul_efun.c` raises on `write()`/`say()`/`printf()`
(“deprecated, use MessageLib”). Login is
`/platform/.obj/login.c`. Flavor `acme-rpg` is a single
`.module/combat.c`. The only shipped room is
`platform/.etc/skel/.room/workroom.c` (`inherit RoomCode;`). There is
no playable world in the archive.

`raw/` is gitignored.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=227 converted=0 lossy=0
skipped_binary=0`. 146 `.lpc`. 11 `.c"` refs rewritten. 3 local
angle-bracket includes. 1 file `static`→`nosave`
(`flavor/acme-basic/.module/mobile.lpc` variable `followers` /
`following` — correct here).

## 2. FluffOS port

The archive is **modern LDMud 3.x**, not the older LDMud dialect
`questmud` used. First-class closures (`#'welcome`, `unbound_lambda`,
`funcall`), `virtual inherit` / `private inherit`, `foreach (x : y)`,
`struct Message`, multi-value mappings, XML domain/command specs,
SQLite/MySQL/Postgres clients, and a MessageLib that replaces
`write()`. FluffOS has none of `set_driver_hook`, `closure`,
`unbound_lambda`, or `virtual inherit` (confirmed in
`~/src/fluffos/src`). A mechanical dialect rewrite of the 146 LPC
files is not a one-slice job; the original login/command stack is
kept as source and not loaded.

`config.fluffos`: master `/secure/master`, simul `/secure/simul_efun`,
global include `"/include/auto.h"`, port **40278**, `lazy resets : 1`.

Original master/simul saved as `/secure/master_ldmud.lpc` and
`/secure/simul_efun_ldmud.lpc`.

New FluffOS master (questmud / AGENTS.md §7.158 cluster):
`get_root_uid`/`get_bb_uid` `"ROOT"`/`"BACKBONE"`, `creator_file`
always returns the string `"BACKBONE"`, `valid_read` includes
`load_object`/`recompile_object`/`include`/`restore_object`,
`valid_override` returns 1, `error_handler` writes `/log/catch`.

Catalog overlay (not the original MessageLib path):

- `/obj/login.lpc` — name / new-or-existing password; `exec` into
  `/obj/player`
- `/obj/player.lpc` — `look`/`score`/`quit` plus north/south into the
  two catalog rooms; `process_input` is `mixed` (returning `1` swallows
  the command; a `string` return type plus forward-refs failed compile
  with “No program in object '/obj/player'”)
- `/room/void.lpc`, `/room/workshop.lpc` — start + one adjacent room.
  The archive has no world to port.

`crypt(p, stored)` accepts FluffOS `$6$…` hashes on reconnect.

### Live-verified (native, port 40278)

Created `fluffos` / `Mud@2026`. Lands in The Void; `look` / `score`
(`Fluffos (level 1)`, hp 20/20) / `north` (workshop) / `south` /
`quit` (“Saving Fluffos.”). Reconnect after a cold driver restart
reloads `data/f/fluffos.o`. First player is not auto-god.

`/log/catch` and `/log/compile` were only written on the first failed
`/obj/player` compile (missing prototypes); they were not touched on
the successful create, reconnect, or cold-boot reconnect.

WASM not verified. `unique_games` stays counting numbers `< 900`; 969
is still listed as a lib.

## 深度功能测试（§10.7, 2026-09-05）

Catalog overlay only — the archive has no playable world. Organic
`fluffos` / `Mud@2026` on native 40278: Void `look` / `score`
(level 1, hp 20/20) / `inventory` (empty-handed) / `north`
workshop / `south` back / `quit` persist. Reconnect same session:
Void `look` / `score` / `quit`. Shop, combat, guild, death: **N/A**
(original MessageLib / acme-rpg combat / XML cmds are not loaded).

Logs this boot (PID started 20:07:44, live fd
`libs/acme/log/debug.log`): driver stdout + debug.log had no LPC
errors across the playthrough. `work/log/catch` handler proven live
with a one-shot `catchprobe` (`CAUGHT /obj/player.lpc *catch-path-probe`)
then reverted; play itself left no other catch lines.

## 3. What was not ported

- Original `/platform/.obj/login` (closures + ConnectionTracker telnet
  negotiation + MessageLib/PostalService)
- XML command controllers, logger factory, SQL clients, HookService
- `acme-basic` look/say/walk (those commands call `write()`, which the
  original simul raises on)
- `acme-rpg` combat (one unfinished file)
