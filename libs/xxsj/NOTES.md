# 修仙世界 (xxsj) — porting notes

Source: `git clone https://github.com/Nuiio/fluffos-xiuxian-mud`
(commit `d46eef2c8a5ef90d0b07216e59d6e3a52703d15e`, merge of
`mud-patch-1`, 2026-06-07; converted 2026-09-05). Config name
`修仙世界`. Slug `xxsj`, number **970**, port **40279**.

This collection’s copy is a snapshot, not a live mirror. The repo’s
bundled `fluffos/` driver tree was not converted — this project uses
its own driver.

Small original FluffOS 2019 修仙 lib (青云宗). Welcome: “欢迎来到修仙
世界！”. Unique; not `xxcq` / `xxcqii`. Do not onboard
`Nuiio/fluffos-xiuxian-mud` again.

## 0. Layout

Mudlib root is `mymud/`. Master `/single/master`, simul
`/single/simul_efun`, login helper `/single/login`, player
`/clone/xiuxian_user`, start room `/room/xiuxian/square` (宗门广场).
12 rooms under `room/xiuxian/`. Commands live on the player object’s
`process_input` (`look`/`status`/`xiulian`/`quit`/…), not only
`command/*.lpc`.

`raw/` is gitignored. rsync excluded `.git`, bundled `fluffos/`,
`Source.zip`, `*.backup`.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=37 converted=0 lossy=1
skipped_binary=0` (lossy was `项目结构.txt`). 25 `.lpc`. No `.c"`
rewrites. No `static`→`nosave`.

## 2. FluffOS port

Already FluffOS-native. `config.fluffos`: master `/single/master`,
simul `/single/simul_efun`, global include `"/include/globals.h"`,
port **40279**.

Master: `valid_read` accepts `load_object`/`include`/`restore_object`,
`get_simul_efun` returns the path string, `epilog` is `varargs`,
`error_handler` writes `/log/catch`.

### Bugs fixed

- **`tell_room` 2-arg simul vs 3-arg call sites.**
  `/single/simul_efun` overrode `tell_room(room, msg)` but
  `xiuxian_user` always calls `tell_room(room, msg, ({ this_object() }))`
  (enter/leave/quit/breakthrough). Made the simul `varargs` and honor
  the exclude list.
- **First quit wiped the password hash.** Registration wrote
  `crypt()` into `data/users/<name>.o`, then `confirm_password`
  replaced in-memory `user_data` with a mapping that had no
  `password`. `quit` → `save_me` → `save_user` rewrote the file;
  the next login’s `crypt(p, stored)` failed. Confirmed live (秦风
  created, quit, “密码错误”). Fix: load the just-created record
  (keeps the hash) and `save_user` copies an existing hash when the
  incoming mapping omitted it.
- **`save_me` called `file_name(environment())` with no room.**
  Guarded.
- **`score` was missing.** Help/README talk about 状态 (`status`/`st`).
  Aliased `score`/`sc` to `do_status()` so the collection look/score/quit
  bar works.

### Live-verified (native, port 40279)

Created 秦风 / `Mud@2026` (冰灵根, 凡人) and fluffos / `Mud@2026`
(金灵根). Both land on 宗门广场; `look` / `score` / `go north` (修炼室)
/ `quit`; reconnect after quit works after the password-save fix.
First player is not auto-god.

WASM not verified. `unique_games` stays counting numbers `< 900`; 970
is still listed as a lib.

Quest NPC spawn in the square is commented out upstream (“暂时禁用”).
Left as-is.
