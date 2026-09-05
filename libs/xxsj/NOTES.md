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

Quest NPC spawn in the square was commented out upstream
(“暂时禁用”); §10.7 re-enabled `call_out("create_npc", 1)` and
spawned the same 任务执事 in the 任务大厅. `look` still does not
list the NPC under [这里有] unless `living()` sees it; `talk 执事`
has a room-short fallback.

## 深度功能测试（§10.7，2026-09-05）

管理员/玩家 `秦风` / `Mud@2026`（冰灵根，凡人）和 `fluffos` /
`Mud@2026`（金灵根）from onboard. Driver PID this boot **982456**
(restart after the LPC edits; earlier this-turn PID 980052), cwd
`libs/xxsj/work`, port **40279**. Live `debug.log` is
`libs/xxsj/log/debug.log`（Boot Time Sat Sep 5 12:34:45 2026）—
slug-level `log/` so the pre-chdir fopen succeeds. `work/log/` stayed
empty. No new `error:` lines after login compiled the patched user
object.

This is a 12-room 修仙 lib. There is no `buy`/`list` and no
`apprentice`/`bai` family. The organic stand-ins are `craft` at the
武器坊, `learn` from the 藏经阁 白发长老, and `kill` on 后山 野狼.
Help already advertised `kill`/`gather`/`craft`/`learn`-adjacent
verbs; `process_input` only handled look/status/xiulian/go/quit and
silently printed `>` for the rest.

### 实测过程

1. **Shop (武器坊 craft).** `go down` from 宗门广场. Room lists
   木剑 (铁矿x2). First pass: `craft 木剑` was swallowed (`>` only).
   After the verb was wired: gathered 铁矿 x2 on 后山, `craft 木剑`
   → 「你锻造成功，获得「木剑」」 and attack 10→15. No copper
   `buy`; this is a gather/craft stall, not a cash shop. Do not
   invent a buy system.
2. **拜师 (藏经阁).** 白发长老 and 《基础剑诀》/《御风术》/
   《炼气心法》 are flavor in the room long. First pass: `talk
   白发长老` / `learn 基础剑诀` swallowed. After the fix: `talk`
   prompts `learn 基础剑诀`; `learn` → 「白发长老点头…传于你」,
   attack 15→18. Second `learn 基础剑诀` after relogin: 「你已经
   学过」. `bai` is an alias of `learn`.
3. **Quest.** `quest list` / `accept 1` (采集灵药) / `status` work
   from any room. Five `gather 灵芝` in 灵药园 then `quest complete`
   paid 修为 +50 and 灵石 x1 (20→70). 灵芝 x5 removed from the pack.
4. **Combat.** `kill 野狼` on 后山: 50 HP, six rounds, 秦风
   100→85, 「你击败了「野狼」」, 修为 +20, 80% 兽皮 drop landed.
   `go 后山` from 任务大厅 correctly refused (the old global
   地名→north map would have walked into 修炼室 from the square).
5. **Quit / persist.** Relogin in 藏经阁. 修为 70, 攻击 18, pack
   兽皮/木剑/灵石, 无进行中任务, 基础剑诀 still learned. Password
   hash survived (onboard fix still holds).

### Bugs fixed this pass

1. **`clone/xiuxian_user.lpc` `process_input` dead verbs.** Help
   and room longs document `gather`/`kill`/`craft`/`hp`/`linggen`;
   the switch ignored them. Wired those plus `talk`/`quest`/`learn`
   (`bai` alias). Inventory helpers `add_item`/`count_item`/
   `remove_item`. Persist `current_quest` / `learned_gongfa` /
   `wolves_killed`.
2. **`do_go` 地名 map.** Adjacent-room `query_short` match first;
   the hardcoded 后山→north table now applies only when that
   exit’s destination short is actually 后山.
3. **Quest NPC spawn.** Square `create_npc` uncommented; 任务大厅
   also `call_out("create_npc", 1)`. `quest_master` `enable_commands`
   + `set_living_name`; `accept_quest` calls `me->do_quest(sprintf(
   "accept %d", quest_id))`.

LPC stays CRLF. Admin/player saves not committed. No new AGENTS.md
class.

### Log re-check (2026-09-05, same afternoon)

User follow-up: do not treat a boot-banner `debug.log` as a clean
playthrough. Re-booted on port **40279**, driver PID **995489**, cwd
`libs/xxsj/work`. Live `debug.log` confirmed via `/proc/995489/fd/3`
→ `libs/xxsj/log/debug.log` (Boot Time Sat Sep 5 12:54:22 2026).
`error_handler()` writes `/log/catch` (`work/log/catch`);
`log_error()`/`write()` also land on captured driver stdout.

Organic replay (秦风 / `Mud@2026`): look/score/i, 藏经阁→广场→灵药园
`gather 灵芝`, 后山 `gather 铁矿` x2 + `kill 野狼` (修为 70→90), 武器坊
`craft 木剑`, 藏经阁 `learn 基础剑诀` (「你已经学过」), `quest list` /
`status` (无进行中任务), quit. After that session, before any probe:

- live `debug.log` still 6098 bytes / unchanged mtime — boot banner,
  `*Warning: unable to open stat file domain_stats/author_stats`,
  `Accepting telnet…` only. No LPC `error:` / 运行时 traces.
- `work/log/catch` did not exist.
- driver stdout had no `编译错误` / `运行时错误` / `心跳错误`.

Then a one-shot `error("log-liveness-probe")` (temporary `zerr` verb,
reverted, not shipped) wrote the same 运行时 block to `work/log/catch`,
driver stdout, **and** the live `debug.log` (6098→6335). So the
handler path is alive; the empty catch after the organic path was a
real clean run, not a dead log. Cosmetic only: config
`external_port_1` vs `port number`, and the two stat-file warnings.
