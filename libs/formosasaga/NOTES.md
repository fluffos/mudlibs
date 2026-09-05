# 源流福爾摩沙 (formosasaga) — porting notes

Source: `git clone https://github.com/wade-fs/FormosaSaga` (commit
`a700cf5de8266868d574eb374e0b11da0b5877f5`, “整理 python scripts”,
2026-06-28; converted 2026-09-05). Config name `源流福爾摩沙`. Slug
`formosasaga`, number **967**, port **40276**.

This collection’s copy is a snapshot, not a live mirror. The upstream
tree is a Go MudOS-v22 simulator plus a browser/HTTP client (port
8080). This project runs the mudlib on FluffOS telnet. Local
driver-compat shims mean it has diverged from upstream.

Unique original Taiwan-history LPC lib. Not a derivative of any
collection game. Do not onboard the repo again.

## 0. Layout

Upstream repo root is the Go driver + `mudlib/`. Only `mudlib/` was
rsync’d (exclude `.git`) into `raw/` then `convert_lib.sh`. Do not
copy `.git` into `work/` (submodule trap).

`raw/` is gitignored. Do not re-clone or re-convert.

Master `/master`, simul_efun `/secure/simul_efun`. World data is
~3500 YAML files under `data/yaml/` (converted in-place to JSON so
`yaml_decode` can be `json_decode`). Start room
`/area/settlements/minxiong.lpc` (民雄鄉 / 打貓社).

Original `connect(string lang)` is not FluffOS `connect(int port)`.

## 1. Convert (2026-09-05)

`convert_lib.sh` UTF-8: `already_utf8=3785 converted=0 lossy=0
skipped_binary=9`. 258 `.lpc`. 449 `.c"` refs rewritten. Exit 0.

Upstream was already UTF-8 (zh-TW).

## 2. First-of-lineage: Go MudOS-v22 → FluffOS

This is the first lib in the collection from this driver. A clean
compile is not a port. Architecture gaps that had to be shimmed or
rewritten:

1. **Go efuns** in `/secure/simul_efun.lpc`: `substr`, `yaml_decode`
   / `yaml_encode` (JSON after convert), `errorp`, `getenv`,
   `m_delete`, `member`, `is_web_client`, `is_interactive`, `nullp`,
   `p2p_broadcast`, `query_uuid` / `find_by_uuid`, `md5`
   (`hash("md5", s)`), `generate_uuid`, `pad_str`, `sleep` no-op,
   `write_raw`, varargs `crypt`, `$HIW$` ANSI via `write` /
   `tell_object`, `object_name` (`file_name`), `to_string`,
   `resolve_path`. JSON encode/decode is lima’s `/secure/json.lpc`
   (do not leak its `#define to_string` into simul_efun).
2. **`nil` is not a FluffOS token.** `site.lpc` `look_room` and
   `incident_d.lpc` used `nil`; replaced with `0`. That compile
   failure blocked 民雄 from loading.
3. **`connect(mixed)`** ignores the FluffOS port int; default lang
   `zh-TW`. `set_encoding("utf-8")` on login.
4. **`valid_*`**: FluffOS passes an euid string, not the calling
   object. `valid.lpc` treats `!objectp(user)` as allow; string
   denials become `0`.
5. **`move_object` is 1-arg.** Wrapper on `/std/object.lpc` plus the
   usual `A->move_object(B)` rewrite.
6. **Inherit after globals is illegal.** `command_d`, `crafting_d`,
   `party_d`, `skill_d`, `channel_d`, `combat_d`.
7. **Mixin files that touch parent vars** (`combat.lpc`) must be
   `#include`d, not `inherit`ed.
8. **`save_object("/path.o")` is wrong** — drop the `.o` suffix
   (`system_d`).
9. **Upstream JSON `.o` saves** (`timeline.o`, settlement state,
   `user/wade.o`) throw on FluffOS `restore_object`. Renamed to
   `*.o.gojson`. Wrap `restore` in `catch`.
10. **`global include file : <globals.h>`** must be set even when
    empty; omitting it left a stale `scan_config_line` buffer that
    made every file fail `#include` at line 1.
11. **`command_d` rehash** must `catch(load_object)` / `query_verbs`.
    A single failed cmd (`cmd_help` 2-arg `main` recurse) used to
    abort the hash, so `look`/`info`/`quit` never registered.
    Default fail message is `什麼？`.
12. **`INCIDENT_D` / `EVENT_D` / `YAML_D`.** Several files used
    formosa.h macros without including it (`cmd_ask`, `cmd_help`
    callers, `npc.lpc`). `incident_d` called a non-existent
    `YAML_D->parse_file`; now `yaml_decode(read_file(...))`.
13. **Web-UI JSON** in `logon()` / `setup()` is `catch()`’d so telnet
    is not dropped. `setup()` itself is `catch()`’d in login so
    `登入成功` still prints.

## 3. Registration / admin

Flow: language `1`/`2`/`3` → id → password → nickname → race
(`1`矮人 `2`精靈 `3`人類 `4`獸人) → nature (`1`靈動 `2`勇猛 `3`堅毅
`4`睿智) → first player names the mud and becomes **god**.

Live: `2` (zh-TW) → `fluffos` / `Mud@2026` / 秦風 / race `3` / nature
`2` / mud name `Formosa Saga`. Printed `【創世神】` god. Start:
**打貓社 / 民雄鄉** (榕樹、甘蔗車、travel 到民雄車站…). `info` shows
秦風 level 1, 135/135 HP. `quit` saves and returns to the language
prompt. NPC 老站長 is present after `/std/npc.lpc` included
`formosa.h`.

Password `input_to(..., 1)` hides echo. `crypt()` 1-arg at create;
login compares `crypt(pass, saved) == saved`.

## 4. WASM

No MySQL. Heartbeat/UI JSON is noise on telnet but not required.
**playable.**

## 5. Not done this pass

A handful of cmd files still fail to compile (`cmd_party` mid-block
decls, `cmd_suicide` `strftime` arity, `cmd_record` missing `HMAG`);
rehash skips them. No outbound I3. §10.7 travel/quest/combat is below.

## 深度功能测试（§10.7，2026-09-05）

管理员 `fluffos` / `Mud@2026` god，秦風，打貓社 / 民雄鄉。Telnet
login `2` (zh-TW). Driver PID this boot 968057，cwd
`libs/formosasaga/work`，port 40276。Live `debug.log` is
`libs/formosasaga/log/debug.log`（Boot Time Sat Sep 5 12:15:02 2026）
— slug-level `log/` so the pre-chdir fopen succeeds. Look dumps a
huge Web-UI JSON map; heartbeat `cmd_info` is silent on telnet
(empty verb). `--idle 3` after the first-login YAML load is enough.

This is not a 武侠 family/shop lib. There is no `buy` / `list`
verb and no `apprentice` / `bai`. The organic stand-ins are
narrative shop sites, `guild join`, and `kill`.

### 实测过程

1. **Bank.** `bank` 冒險者銀行, cash 0 / deposit 0. After quest gold:
   deposit 10000 銅幣 (1 金幣) → cash 89 金幣, bank 10000 銅幣.
   `1 gold = 10000 copper`. Ledger math ok.
2. **Shop.** 民雄公有市場 市場阿嬤 `ask … about 菜` → 「你要買否？」
   but `buy` / `list` print `什麼？`. `travel pharmacy` from the
   market reaches a stub site titled `【pharmacy】` with no 藥舖老闆
   spawned. `travel pharmacy` from 打貓社 is not on that room's
   route list (`找不到「pharmacy」`). Conversation-only shops;
   do not invent a buy system.
3. **Guild (拜师 stand-in).** Bare `guild` crashed
   `*(s)printf(): Incorrect argument to type %s` because
   `guilds/*.yaml` `name` is a `{en, zh-TW, zh-CN}` mapping.
   After the fix: lists 魔法師集會 / 戰士盟約 / 冒險者公會.
   `guild join adventurer` → 新手冒險者. `guild` then shows name /
   rank / 貢獻. Daemon `join_guild()` existed; the player verb did
   not.
4. **Quest.** Bare `quest` crashed `*No program in object
   '/daemon/quest_d'!` — `quest_d.lpc` failed to compile
   (`FOOTPRINT_D` / `EVENT_D` used without `#include formosa.h`),
   and `cmd_quest` loaded it *before* the empty-quest return.
   After the fix: `quest accept old_station_master_wish` (老站長的
   心願), travel 民雄公有市場 already held footprint
   `sugar_railway_minxiong`, `quest complete` paid 150 exp + 80
   金幣 + 公會貢獻 30. Reward YAML path is `.c`; tree is `.lpc`.
   `ask 老站長 糖鐵` is narrative only (same canned line with or
   without the footprint).
5. **Combat.** `kill 行腳商人` at the market: 85 HP, three rounds,
   秦風 135→127. Win printed `你擊敗了` then
   `👻 你感覺到靈魂正在脫離肉體... 你死了` and `你在祈禱室緩緩睜開
   雙眼` — `write()` in `living::die()` goes to `this_player()`.
   Player HP/gold unchanged (not actually dead); NPC
   `on_death()` rewards never ran. After `npc::die()` →
   `on_death()`: cloned `/std/npc` 怪物, 85→0, `怪物 倒下了`,
   +50 exp, +10 金幣 (80→90). No fake player-death line.
6. **Quit / persist.** `quit` / relogin landed back in 民雄公有市場
   then later pharmacy. 冒險者公會 / 新手冒險者 / 貢獻 30 /
   已完成 老站長的心願 / 80 then 89 金幣 persisted. Reward ticket
   id works (`乘車券`) but pre-fix clone still shows as 某個東西
   in `i` (old object kept default short).

### Bugs fixed this pass

1. **`cmds/player/cmd_guild.lpc` sprintf / join.** `select_lang()`
   on mapping `name`/`desc`. Added `guild join <id>` so
   `join_guild()` is reachable. Help updated.
2. **`daemon/quest_d.lpc` include + `.c` rewards.**
   `#include "/include/formosa.h"` for `FOOTPRINT_D` / `EVENT_D`.
   `clone_reward_item()` retries a `.c` path as `.lpc`.
3. **`cmds/player/cmd_quest.lpc`.** Do not load `quest_d` on an
   empty quest list; `catch(load_object)` if the daemon is dead;
   `select_lang` on quest name/desc; `quest accept` / `quest
   complete` verbs for the existing daemon API.
4. **`std/npc.lpc` `die()`.** Override to `on_death()` so combat's
   `target->die()` does not run the player prayer-room path on an
   NPC (fake `write()` death + skipped kill rewards).
5. **`std/object.lpc` `set_name`.** If `short_name` is still the
   default 某個東西, copy the name so reward items that only
   `set_name()` display. `item/old_station_ticket.lpc` also sets
   `set_short`.

Onboard leftover compile failures (`cmd_party`, `cmd_suicide`,
`cmd_record`, `cmd_rm`, `cmd_yamllint`, `cmd_incident`) not in
this pass. Admin save / `work/data/*.gojson` not committed.

## 6. Local run

```
cd libs/formosasaga
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40276**. Setup after password can take several seconds
(YAML/JSON world load) — use `--idle 8` with mudclient.

```
python3 scripts/mudclient.py 127.0.0.1 40276 --timeout 70 --idle 8 \
  --send "2" --send "fluffos" --send "Mud@2026" \
  --send "look" --send "info" --send "quit"
```
