# 北大侠客行 (pkuxkx) — porting notes

Source: `git clone https://github.com/ly19811105/pkuxkx-utf8` (commit
`0eaf237c9970795a51aa4cc04b5b762003300cbd`, “清理备份文件”,
2021-04-09; converted 2026-09-05). Config name `北大侠客行`. Slug
`pkuxkx`, number 966, port 40274.

This collection’s copy is a snapshot, not a live mirror. Local
driver-compat and login-encoding fixes mean it has diverged from
upstream.

Not the same game as collection `xkx100` / `xkx2017` / `xkx2001`.
Those are the older Xiang/ES-II “侠客行一百” family. This tree is
PKUXKX (北大侠客行): same distant ES-II ancestry, a much larger
original PKU mudlib (21981 `.lpc` after convert), its own newbie
valley (未明谷), and a dual-port GBK/UTF-8 login that we collapsed
to always-UTF-8.

## 0. Layout

Repo root **is** the mudlib. Copied wholesale into `raw/` then
`convert_lib.sh`. Ignored for play: nothing extra (no bundled
driver). Original `config.ini`: `master : /adm/single/master`,
`simul_efun : /adm/single/simul_efun`, `global include : <globals.h>`,
ports 5555 GBK / 6666 UTF-8 / 8888 websocket. This project uses a
single telnet port **40274**.

`raw/` is gitignored. Do not re-clone or re-convert.

## 1. Convert (already finished 2026-09-05)

`convert_lib.sh` UTF-8 pass: `already_utf8=28594 converted=0 lossy=5
skipped_binary=79`. 21981 `.lpc`. Literal `.c"` refs rewritten.
Local angle-bracket includes folded to quotes. `static` → `nosave`
on 93 files. Exit 0.

The upstream repo already claimed UTF-8. `file` on
`adm/single/master.lpc` is UTF-8. `CHINESE_D->is_chinese_character()`
is `pcre_match(str, "^\\p{Han}+$")`, so Chinese-name registration
works after convert without a GBK width hack.

## 2. Always-UTF-8 login — do not set the UTF8 temp flag

Upstream `connect()` did `set_encoding("GBK")` then, only on port
6666, `set_temp("UTF8", 1)` + `set_encoding("UTF8")`. The UTF8 temp
flag makes `feature/message.lpc` and `clone/user/login.lpc` run
`gb_to_utf8()` on every outgoing string.

After convert the whole corpus is UTF-8. Setting that flag would
**double-encode**. The patch is: `set_encoding("utf-8")` on every
connect, and do **not** set `UTF8`. Native registration of `秦风`
printed clean Chinese on look/score/who/quit.

## 3. MySQL is optional

`bsd.lpc` `db_connect("127.0.0.1","pkuxkx","pkuxkx")` fails soft
(`write` + return). Not in preload. Play does not need a database.
WASM is **playable**.

## 4. Bugs fixed this onboard

1. **`natured.lpc` empty-`users()` OOB (AGENTS.md §7.14).**
   `do_event1`–`do_event6` used `if (!(u = users())) return;` then
   `u[random(sizeof(u))]`. An empty array is truthy; `random(0)` is
   0; `u[0]` throws `*Array index out of bounds`. First boot hit
   this because the shipped `/adm/etc/meteoric` timestamp was already
   in the past, so `update_day_phase()` fired a meteor with nobody
   logged in. Guard is `!sizeof(u)` on all six events.

2. **`newsd.lpc` unguarded `restore()` (AGENTS.md §7.7).**
   `data/news/newsd.o` is a shipped 387KB save (almost no newlines,
   3708 embedded CRs, paren count 1293/1295). `restore_object()`
   throws `Illegal array format while restoring news` on first
   `enter_world()`. Wrapped in `catch(restore())` and fall back to
   `news = ({})` when the value is not an array. News listing is
   empty until someone posts; login no longer faults.

3. **`log_error()` warning filter (AGENTS.md §7.10 / §7.34).**
   `strsrch(message, "Warning")` → `strsrch(message, "arning:")` so
   lowercase `warning:` is not written as a hard error.

## 5. Registration / admin

Flow: `new` → English id → `y` → Chinese name (1–6 Han characters,
`pcre` `\p{Han}`) → password (length ≥6 and ≥2 of
upper/lower/digit/special) → confirm → email (`id@address`) →
`m`/`f`.

New characters with `combat_exp < 2000` and no
`newbie_village/done` land in **未明谷**
(`/d/newbie_lxsz/weiminggu.lpc`), not the Yangzhou inn
(`START_ROOM` `/d/city/kedian.lpc`).

Password used for the seeded admin: `Mud@2026` (complexity 16).
`adm/etc/wizlist` has `fluffos (admin)` (kept upstream `mudren
(admin)`). Live `who` listed 秦风 as 巫师; enter_world printed
`目前权限：(admin)`.

`LOGIN_TIMEOUT` is 60 seconds — finish the wizard in one session.

`allowed_sites` already includes `127.0.0.1`. `WIZ_LOCK_LEVEL` is 0.
`command_hook` is `nomask`, not `private`.

## 6. Not done this pass

No §10.7 shop/拜师/combat dive. No news-save reconstruct (the
shipped `newsd.o` is corrupt; catch is enough). No full §9 format of
the 21981-file tree (only the files we edited). `im_d` is already
commented out of preload — no outbound I3.

## 7. Local run

```
cd libs/pkuxkx
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40274**.

```
python3 scripts/mudclient.py 127.0.0.1 40274 --timeout 40 --idle 0.5 \
  --send "fluffos" --send "Mud@2026" \
  --send "look" --send "score" --send "quit"
```
