# Nirvana LP312 (nirvlp312) — porting notes

Source: `git clone https://github.com/rumplemintz/Nirvlp312mudlib`
(commit `616cad7472279cc97c9693f893940f5336916ff8`, “Updated”,
2017-09-21; converted 2026-09-05). Config name `Nirvana`. Slug
`nirvlp312`, number **968**, port **40277**.

This collection’s copy is a snapshot, not a live mirror. FluffOS
compat shims mean it has diverged from upstream.

Unique Nirvana dump. Welcome: “Nirvana / An LpMud version 3.1.02-DR
/ running a modified 2.44 mudlib / established February 26, 1991”.
Dual Amylaar / LDMud master (`#ifndef __LDMUD__`). FluffOS takes the
Amylaar half. Not `lpmud141` (941; that archive has no master).
Collection `questmud` is a different first LDMud port.

Do not onboard this repo again. Do not copy the 115k-file
`players/` wizard-home tree into `work/` (only the few objects the
village greenspace clones).

## 0. Layout

Repo root **is** the mudlib. `/secure/master.c` is one line:
`inherit "/obj/master.c";`. Real master `/obj/master.c`. Simul
`/obj/simul_efun` (Amylaar) / `/secure/simul_efun`. Player
`/obj/player.c`. Village in `room/` (church, vill_green, void,
adv_guild).

`raw/` is gitignored. rsync excluded `.git`, `players/`, `pfiles/`,
`log/`, `doc/`, `post_dir/`, `LP_SWAP*`, debug logs. A handful of
`players/` files the village actually clones were copied by hand:
`players/boltar/things/{esc.h,green_bell.lpc}`,
`players/vertebraker/{ansi.h,obj/news_sign.lpc}`,
`players/sandman/NEWBIE/newbie_dispenser.lpc`,
`players/feldegast/std/color_pad.h`, `players/nooneelse/esc.h`.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=7090 converted=0 lossy=11
skipped_binary=76`. 3581 `.lpc`. 2642 `.c"` refs rewritten. 117
local angle-bracket includes. 301 files `static`→`nosave`.

`static`→`nosave` on **functions** is wrong for this dialect
(`static logon()` meant private). Keep `logon()` untyped.

Mechanical rewrite (`scratchpad/nirvlp312_rewrite.py`): 2-arg
`move_object(A,B)` → `A->move_object(resolve_ob(B))`;
`add_action(fn); add_verb(v)` → `add_action(fn, v)`.

## 2. FluffOS port

`config.fluffos`: master `/secure/master`, simul `/obj/simul_efun`,
global include `"/include/auto.h"`, port **40277**, `lazy resets : 1`,
inherit chain 80.

`work/include/auto.h`: `#define status int`, `extract()`,
`resolve_ob()`, 1-arg `move_object()` via `efun::`. Do **not** call
simul-only functions from auto.h (circular: simul compiles with
auto.h).

Amylaar half of `work/obj/master.lpc`: `get_root_uid`/`get_bb_uid`
`"root"`/`"backbone"`, `creator_file` returns string `"root"`,
`valid_*` permissive, `valid_exec` varargs returns 1, safe
`error_handler`, `epilog`/`preload` skip `players/` lines.

`room/std.h` and `room/std_old.h`: `create()` →
`call_other(..., "reset", 0)` so THREE_EXIT rooms get `set_light`.
Without this, Adventurers' guild and other std_old rooms stay dark
and `look` via `test_dark()` returns 1 with no text.

`work/obj/player.lpc`: `create()` → `reset(0)` so `name = "logon"`
before `logon2`.

### Dialect / reserved words

- `new` is reserved (`L_NEW`). Renamed in `adv_guild` (`newval`),
  `post.lpc` (`newmail`). `bull_board.lpc` still has `new(hd)` —
  extra_reset is wrapped in `catch`.
- `class` is reserved. Renamed to `klass` in armor/monster/weapon
  `set_params` / `set_*_params` and monster potential helpers.
- LDMud `array` type → `mixed *` in `bin/channel_daemon.lpc`.
- `#define EXTRA_INIT\` glued onto `add_action(...)` (no space after
  line-continuation) became a function-like macro with string
  “parameters”. `adv_guild` now uses `extra_init()`.

### Simul shims (Amylaar half)

`creator()` returns 0 for uid `root`/`backbone` (else `reset()`
treats the clone as wizard-cloned and `illegal_patch`s). Also
`cat()`, `atoi()`, `version()`, `log_file()`, `exists()`,
`add_worth` stub, `caller()`, `in_editor` stub, varargs
`remove_action`/`command`, 2-arg `snoop`, `text_contains`,
`transfer`, `pad`. Reserved-word renames in `resolv_path` /
`waxfuns` / `m_efuns`. `format.lpc` rewritten (no `raise_error`).
`wizlist.lpc` stubbed. `locklist.lpc` inits arrays.

### Anti-clone `illegal_patch`

FluffOS `object_name` is `/obj/player#N` (leading slash). Original
`ab != "obj/player"` fired on the users() loop after WELCOME.
`is_real_player_ob()` uses `strsrch(n, "obj/player")`. `reset()`
`if (creator(this_object()))` disabled.

### Commands (look / score / quit)

TMI `cmd_hook` is `add_action("cmd_hook", "")`. Empty-verb
`add_action` is silently dropped when `command_giver` is unset
(input_to / pre-room creation). `process_input()` is the catch-all.

- `look` / `l` → `/bin/play/_look.lpc` (full room long).
- `quit` → `/bin/play/_quit.lpc` → `quit()` / “Saving …”.
- `score` / `sc`: `/bin/play/_score.lpc` still throws inside
  `cmd_score()` (caught; no line in `runtime` — the apply fails
  before a useful handler write). `process_input` then prints a
  stub: name, level, exp, coins, hp/max. Full `_score` is still
  the next compile/runtime fix, not a missing verb.

`crypt(p, extract(password,0,1))` does not verify a FluffOS
`crypt(p, 0)` hash (`$6$…`). Login accepts `crypt(p, password)`
first.

`save_me()` no-ops without an environment. New characters are
saved again after `move_object` in `move_player_to_start`.

## 3. Live verification (2026-09-05, native port 40277)

Driver: `~/src/fluffos/build-debug/src/driver config.fluffos` from
`libs/nirvlp312` (debug.log opens before chdir).

Created `fluffos` / `Mud@2026` (human male 5'10" 150lbs). First
landing: Adventurers' guild (`look` shows advance/cost/raise text,
HUD, exits north/west/up). Reconnect after `quit` (“Saving
Fluffos.”) lands on **Village Green** (bell, news sign, Hall of
Apprentices). `score` stub: `Fluffos (level 1)`, exp 0, coins 0,
hp 22/26. `quit` saves `pfiles/f/fluffos.o`.

First player is **not** auto-god. Seeded as a mortal.

WASM not verified this pass.

## 4. Do not redo

Do not re-clone rumplemintz/Nirvlp312mudlib. Do not rsync
`players/`. 928/929/932 stay header-encrypted. Skip nitan.zip.
