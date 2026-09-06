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
  `post.lpc` (`newmail`), `bull_board.lpc` (`new_note`).
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

## 4. Catch-log reset spam (2026-09-05)

Not a full §10.7. The onboard driver (PID 579874, started 02:21)
was left running after look/score/quit — we forgot to kill it,
then later timer turns treated “not this-turn” as a hard
do-not-kill. User 2026-09-05: that leftover was our own abandoned
boot, not a concurrent session. Killed; 40277 freed.

Its `error_handler` (`/log/catch` vs `/log/runtime`) recorded a
caught `*Bad argument 1 to EFUN call_other() ... Got: int(0)`
on `/room/vill_green.lpc:31` every ~10 minutes for the whole
sit. `clone_object("players/snow/ITEMS/notice")->move_object(...)`
— that path was never copied into `work/` (only a handful of
`players/` objects were). `catch()` hid it from the player;
`clone_object` returning 0 still threw on the chained `->`.
§7.147 store-then-guard. The board itself is missing; we do
not invent a substitute.

Same catch file also had `*No program in object '/obj/bull_board'`
from `adv_guild` extra_reset. Function was still named `new(hd)`
(`L_NEW`). Renamed to `new_note` / `add_action("new_note", "note")`
like the onboard `adv_guild`/`post.lpc` reserved-word pass.
Player verb stays `note`.

Cold boot 2026-09-05 17:52 confirmed the 10-minute vill_green
spam is gone.

## 5. 深度功能测试（§10.7, 2026-09-05）

Native port 40277. Driver PID this pass ended 1195821. Live
`debug.log` via `/proc/<pid>/fd/3` → `libs/nirvlp312/log/debug.log`
(Boot Time Sat Sep 5 18:00:29). `error_handler` → `/log/catch`
and `/log/runtime`. Organic `fluffos` / `Mud@2026`.

Path: Village Green → `enter hall` → east Armory (`browse` /
`grab sword` / `wield sword`) → out → east/east/east vill_road2
→ north shop (`look at sign`, `list` empty) → south Adventurer's
guild (`cost`: must be closer to next level; `advance`: not
enough gold) → `kill harry` (multi-round; Harry hits; we die:
corpse, tombstone, tunnel of white light) → reconnect ghost →
church `pray` / `y` → “more solid form”, score HP 10/26 → quit
persist (`ghost` cleared, `pfiles/f/fluffos.o`).

Fixes this pass:

- `/room/room.lpc` `query_numbers()`: FluffOS `file_name()` is
  `/room/room`, so the `"room/room"` equality failed and every
  inheritor called `"/room/room"->query_numbers()` → too-deep
  recursion on village-road `look`. Same leading-slash class as
  onboard `is_real_player_ob()`.
- `/room/store.lpc`: `int new` → `idx` (`L_NEW`). Shop
  `call_other("/room/store")` had been aborting reset, so north
  from the road silently failed.
- `/obj/soul_com.lpc`: FluffOS flag 1 is `V_SHORT` (abbrev), not
  Amylaar xverb. `cost` was matching `c` and overwriting the
  guild `notify_fail`. Now flag 3 (`V_NOSPACE`) and `chat()`
  returns 0 when the remainder is not `channel message`.
- `/obj/user/testchar-d.lpc`: `read_file` of a missing
  `/log/user/testChars.txt` returned 0; `sscanf` threw on every
  login. Guard empty text.
- `/obj/monster.lpc`, `/obj/weapon.lpc`, `/room/prison.lpc`:
  FluffOS `create()` never called `reset(0)`, so monsters were
  not `living()` (Harry: “is not alive”), newbie swords had no
  `set_name` (inventory empty after `grab`), and `prisoners` stayed
  0 (`member_array` on login). Same hook as onboard `player.lpc`.
- Hall of Apprentices: copied only
  `players/softly/{closed/ansi.h,nhall/{notice,rooms/n1-n4,obj/*}}`
  and `players/maledicta/ansi.h` from upstream 616cad7. `notice`
  `new` → `new_note`. Still do not rsync the 115k `players/` tree.
  North school / south blacksmith / mokri farseer / newbie bag
  still uncopied — those exits/items fail, documented.
- `/daemons/combat.lpc` and `/bin/wiz/_combat.lpc` inherited
  missing `/players/earwax/lib/waxfuns`. Pointed at the already-
  ported `/obj/simul_efun/waxfuns.lpc`.
- `/obj/simul_efun/destruct.lpc`: no-op when `ob` is 0 (sword
  `drop()` already `destruct`s itself).

Final cold boot catch/runtime/debug.log/stdout: no new lines
across hall / shop / guild / Harry fight / death / pray / quit.
(Older leftover catch/runtime lines from the abandoned onboard
sit remain in those files.)

`score` via `/bin/play/_score.lpc` works for a living player;
ghosts get “immaterial state with no scores” (design).

## 6. Do not redo

Do not re-clone rumplemintz/Nirvlp312mudlib. Do not rsync
`players/`. Do not redo nirvlp312 §10.7. 928/929/932 stay
header-encrypted. Skip nitan.zip.
