# revive (终极地狱-轩辕传说) -- porting notes

Source: `git clone https://github.com/MudRen/revive` (commit
`240ea5c4c7cd8cf2d854781648a16398e6df3b16`, cloned 2026-08-26). The
GitHub repo's own description is "终极地狱-轩辕传说 mud 底层代码"
("Ultimate Hell - Legend of Xuanyuan, MUD base/engine code"). Slug
`revive`, number 934, port 40236.

## Lineage -- same Doing-Lu "hell" family already in this collection

`adm/single/master.lpc`'s header comment is byte-identical to
`hell`/`hellxg`/`zjmudhell`'s: "for ES II mudlib / original from Lil /
rewritten by Annihilator (11/07/94) / modified by Xiang for XKX
(12/15/95) / **updated by Doing Lu for hell (2K)**" (no yh2003-specific
"Modify By Linux@lxtx" line, distinguishing it from the separate
yanhuangwuhun/zhyx sub-family). The raw archive's `adm/etc/welcome`
banner reads "EMPEROR OF ULTRA HELL(BLOOD & MAGIC) FROM 1999.12.12",
`internet mud name : hell.local`, and `smtp sender : doinglu@163.net`
in `adm/etc/config` -- the same author/codebase as `hell`'s own "REVIVE
OF ULTRA HELL...FROM 1999.11.13" banner, just a different dated
snapshot. A whitespace/brace-style-normalized diff of `master.c`
against `hell`'s already-converted `master.lpc` produced only cosmetic
differences (indentation, `static`->`nosave`, `.c`->`.lpc` -- the same
mechanical transforms `convert_lib.sh` already applies), confirming
this is the same underlying codebase, not merely a similar title (per
AGENTS.md's standing caveat that similar Chinese titles alone are NOT a
lineage signal in either direction -- this one was verified by diff).

**Not a duplicate, but a MUCH smaller release than its `hell` sibling**:
1,901 files total (vs. `hell`'s 8,549) and only 3 of the original
domain directories under `d/` -- `death`, `pk`, `register` -- vs.
`hell`'s ~54 (`baituo`, `beijing`, `changan`, `dali`, `emei`, `fuzhou`,
`gaibang`, `hangzhou`, `huashan`, `kunlun`, `shaolin`, `songshan`,
`suzhou`, `wudang`, `xiaoyao`, `xingxiu`, ...). `kungfu/skill/` doesn't
exist at all in this archive (only `kungfu/special` and
`kungfu/condition`, the skill *framework*, survive). This matches the
repo's own self-description as "底层代码" (base/engine code) -- it
reads as a stripped release of the shared Doing-Lu engine with the
actual built-out game world/content held back, not a conversion
failure or an accidental subset.

## Pipeline

1. Cloned directly into `libs/revive/raw/revive/` (git-hosted source,
   `.git` stripped before copying in, per this project's convention).
2. `scripts/convert_lib.sh libs/revive/raw/revive libs/revive/work
   GB18030`: `already_utf8=422 converted=1461 lossy=11
   skipped_binary=7`; renamed 1,169 files to `.lpc`; fixed 252 literal
   `.c"` references + 5 `#include <....c>` refs; converted 9 local
   angle-bracket includes to quotes; `static`->`nosave` touched 106
   files. No string-literal (`"static/...`) or
   `#define nosave/protected static` shim collisions found on
   inspection (both known §4.3 classes checked and clear).
3. Full-tree straggler sweep (plain Python UTF-8-decode walk, per
   AGENTS.md §4.1 beyond what the extension-based scan covers): 6
   non-UTF8 files remained after the main pass, all genuine GB18030
   text that `file(1)`'s binary heuristic had misclassified
   (`skipped_binary=7` counted these plus one genuinely-tiny
   no-magic file, `adm/etc/banned_sites`, correctly left alone):
   `doc/board/{yb010,yb028}`, `doc/legend/xkx10` (dev-era player
   message-board/story archive text, same extensionless-help-text gap
   class already documented for `zhyx`/`yanhuangwuhun`, though
   different specific files) and `clone/game/{8_hlp,helppai,21_hlp}`
   (card-minigame help text -- again the same class, different
   content, as `zhyx`'s `8_hlp`/`21_hlp`). Converted with
   `iconv -f GB18030 -t UTF-8` in place.
   No uppercase-`.C` stragglers found (unlike `zhyx`).
4. No hardcoded `MUD_PORT`/`PORTNO` constant found in `include/*.h`
   (§5.3 checked, clear).

## Fixes applied (driver-incompatibility / robustness bugs)

- **`log_error()` had NO warning-vs-error distinction at all** (a
  worse variant of the miscapitalized-check bug documented for
  `zhyx`/`naruto`) -- `adm/single/master.lpc`'s `log_error(file,
  message)` unconditionally echoed every compiler diagnostic straight
  to whichever player/wizard was connected at that moment
  (`"\n编译时段错误：" + message`), with no substring check on
  `message` at all. Since this driver's compiler calls the
  `log_error` master-apply for every diagnostic including plain
  `warning: ...` messages (confirmed by reading
  `~/src/fluffos/src/compiler/internal/compiler_utils.cc`'s
  `smart_log()`/`report_compile_diagnostic()` -- both call
  `APPLY_LOG_ERROR` unconditionally, gated only by whether a VM
  context exists), this meant every lazy-load compile warning site-wide
  was broadcast as a hard-error notice. Fixed by adding the same
  case-insensitive filter this lineage's sibling libs use:
  ```lpc
  if (strsrch(message, "Warning") == -1 && strsrch(message, "warning") == -1)
  ```
- **`is_chinese()` GBK byte-range check** (`adm/simul_efun/chinese.lpc`)
  -- the classic whole-string lead/trail-byte-range check
  (`str[i] < 161`, `i%2==0` lead-byte gate, `str[i] < 176 || str[i] >=
  248`). Rewritten as a CJK Unified Ideographs codepoint range check
  (`str[i] >= 0x4e00 && str[i] <= 0x9fff`), matching `hell`'s own
  already-fixed copy exactly; floor changed `< 2` -> `< 1`.
- **`check_legal_name()`/`named.lpc` "deep" length-halving family**
  (`adm/daemons/logind.lpc`, `adm/daemons/named.lpc`) -- the full shape
  already documented for `zhyx`/`yanhuangwuhun`:
  - `check_legal_name(name, maxlen)`: `strlen(name) < 2 ||
    strlen(name) > maxlen` -> `< 1 || > maxlen / 2`.
  - `get_name()`'s combined surname+given-name floor: `strlen(fname) <
    4` -> `< 2`.
  - `named.lpc`'s `#define PATH(name) (name[0..1] + "/" + name)` ->
    `name[0..0]`; every `strlen(name) < 2` guard (`remove_name`,
    `map_name`, `who_is`, `invalid_new_name`) -> `< 1`; the
    `name[0..1]` bucket-key reference in `remove_name` -> `name[0..0]`;
    `invalid_new_name()`'s sliding-window near-duplicate check: guard
    `strlen(name) < 4` -> `< 2`, loop bound `i <= l - 4` -> `i <= l -
    2`, 2-char window `name[i..i+3]` -> `name[i..i+1]`, 3-char window
    `name[i..i+5]` (guarded `i+6<=l`) -> `name[i..i+2]` (guarded
    `i+3<=l`).
- **`command.lpc`'s `command_hook` wrongly declared `private`**
  (AGENTS.md §8.3a) -- `feature/command.lpc`'s
  `private nomask int command_hook(string arg)` silently downgrades
  the `add_action("command_hook", "", 1)` catch-all registration for
  any `ORIGIN_EFUN` call (i.e. any NPC using the `command()` efun to
  script another object's input, not a player's own direct typing).
  This lineage's water/scenery NPC dialogue (`水笙` in the register
  entry room) drives itself this way. Fixed: dropped `private`, kept
  `nomask`.
- **`message()`'s unconditional 4-arg `efun::message()` call**
  (`adm/simul_efun/message.lpc`) -- same shape already documented for
  `zhyx`/`yanhuangwuhun`: `tell_room()`'s call site passes a bare
  `int 0` for the exclude-list argument on every ordinary call, which
  fails `efun::message()`'s `void|object|object*` 4th-arg type check.
  Fixed by guarding on truthiness (call the 3-arg efun form when
  `exclude` is falsy).
- **`.c`->`.lpc` rename-width bug** (`[0..<3]` -> `[0..<5]`, same shape
  as `zhyx`/`yanhuangwuhun`/`nitan_ceshi`) -- `adm/daemons/eventd.lpc`,
  `adm/daemons/storyd.lpc`, and 2 sites in `adm/npc/luban.lpc` all
  strip what used to be the 2-character `.c` extension from a
  `get_dir()`/filename result with `[0..<3]`, now leaving a stray `.l`
  on every `.lpc` filename. All 4 sites widened to `[0..<5]`.
- **`get_config(__MUD_PORT__)` under a bare `(int)` cast** (this
  driver's `(int)` cast is compile-time-only bookkeeping, not a real
  runtime conversion -- this project's own standing reference note) --
  hit in both `adm/daemons/versiond.lpc`'s `in_server()`
  (`port = get_config(__MUD_PORT__) + VERSION_PORT`) and the shared
  `include/getconfig.h`'s `LOCAL_PORT()` macro (used by
  `adm/daemons/network/messaged.lpc`'s `startup_udp()`). Both switched
  to `to_int(get_config(__MUD_PORT__))`.
- **UDP DATAGRAM socket `read_callback` declared `string`, receives a
  `BUFFER`** -- both `adm/daemons/network/dns_master.lpc` (on the real
  preload list) and `adm/daemons/network/messaged.lpc` (also
  preloaded, and its `create()` unconditionally calls `startup_udp()`)
  declare `read_callback(int sock, string msg, string addr)`, but this
  driver's `socket_create(DATAGRAM, ...)` delivers the packet as a
  `buffer`. Widened both to `mixed msg` and added
  `if (bufferp(msg)) msg = string_decode(msg, "UTF8");` at the top of
  each callback, matching the `zhyx` `dns_master.lpc` fix exactly.
- **`accept_kill()` passes an object where `is_killing()` expects a
  string id** (AGENTS.md §7.50, the same-lineage bug already fixed in
  `hell` itself) -- `clone/user/user.lpc`'s `accept_kill(object ob)`
  called `is_killing(ob)` (an object) against `feature/attack.lpc`'s
  `varargs int is_killing(string id)`. Fixed:
  `is_killing(ob->query("id"))`.
- **A genuine pre-existing syntax typo, not a conversion artifact** --
  `clone/user/user.lpc`'s `calc_sec_id()` stub (see below) was missing
  a semicolon on its `return "none"` line, which cascaded into 4
  further spurious parse errors through the rest of the file
  (`query_info()`'s body). This is the single bug that actually
  blocked the player-body class (`USER_OB`) from compiling at all --
  found live, mid-registration, the moment a new character reached
  gender selection (the first point `make_body()`/`USER_OB` gets
  compiled). Fixed by adding the missing `;`.
- **`virtuald.lpc`'s virtual-room file-existence check was truthy for
  `-1` (file-not-found), turning any reference to genuinely-missing
  content into infinite mutual recursion instead of a clean "no such
  object"** -- new bug class, not previously seen in this collection.
  `adm/daemons/virtuald.lpc::compile_object(file)` (the handler
  `master.lpc::compile_object()` calls whenever the driver can't find
  a file to load) does `if (file_size(name + ".lpc")) { ob =
  name->query_virtual_room(...); ... }` -- `file_size()` returns `-1`
  for a missing file, and `-1` is truthy in LPC, so a target that does
  NOT exist was treated as if it DID, and `name->query_virtual_room()`
  triggered another attempt to load/compile `name` itself, which
  (since `name` still doesn't exist) recurses into
  `master::compile_object()` -> `virtuald::compile_object()` again,
  forever, until "*Inherit chain too deep: > 60 when trying to load
  '/d/city'." First caught trying to load `/d/register/entry` (the
  actual registration entry room -- see below), and reproduced
  identically for every `/d/<missing-city>/...` reference this
  stripped archive's own board/NPC/item content still makes (60+
  `clone/board/*_b.lpc` city-board clones, several `adm/npc/*.lpc`
  content NPCs, etc. -- see "Confirmed content gaps" below). Fixed the
  actual logic bug: `if (file_size(name + ".lpc") > 0)`. This alone
  turns every one of those references into a clean, standard
  `*call_other() couldn't find object '/d/<city>/...'` runtime error
  (still a failure, since the content genuinely isn't shipped, but no
  longer a driver-endangering infinite-recursion crash).
- **`inherit/room/room.lpc`'s room-population helper had no guard
  around `new()`/`->set()`/`->move()`, the exact shape already
  documented in AGENTS.md §7.25** -- once the `virtuald.lpc` fix above
  turned the missing-content case into an ordinary runtime error
  instead of infinite recursion, that error was still UNCAUGHT: the
  registration entry room's own `d/register/npc/diyun.lpc` NPC does
  `carry_object("/d/city/obj/cloth.lpc")->wear()` in its `create()`
  (a wardrobe item from the missing `/d/city` domain), and
  `inherit/room/room.lpc::make_inventory()` called `new(file)` with no
  `catch()` at all -- so this ONE missing content item's failure
  propagated all the way up through `diyun`'s `create()` ->
  `make_inventory()` -> `reset()` -> the entry room's own `create()`,
  making `/d/register/entry` -- **the actual starting/registration
  room every new player is moved into** -- fail to load entirely.
  `logind.lpc::enter_world()`'s own `catch(load_object(startroom))`
  then (correctly, defensively) fell back to `START_ROOM =
  "/d/city/kedian"` -- which ALSO doesn't exist in this stripped
  archive, so the fallback itself then threw a second, uncaught error.
  Net effect before this fix: **every single new-player registration
  died silently right at the world-entry step**, with no visible error
  to the player and no crash to the driver -- just a broken session.
  Fixed per the established §7.25 pattern, guarding the population
  helper without fabricating any missing content:
  ```lpc
  object make_inventory(string file)
  {
          object ob;

          catch(ob = new(file));
          if (! objectp(ob))
                  return 0;
          catch(ob->set("startroom", base_name(this_object())));
          catch(ob->move(this_object()));
          return ob;
  }
  ```
  ...plus an `objectp(ob[list[i]])` guard added to `reset()`'s `case 1`
  branch before its own subsequent `environment(ob[list[i]])` call
  (the `default` branch already guarded correctly via its
  `! objectp(...) { ...; continue; }` shape -- only `case 1` needed the
  fix). With both changes, `/d/register/entry` loads cleanly (`diyun`
  just silently has no clothes, a narrow, cosmetic content gap) and
  every new player reaches the actual game world.
- **SEVERE: `calc_sec_id()` shipped as a never-implemented placeholder,
  permanently locking every player out of their own saved character
  after any driver restart.** `clone/user/user.lpc`'s own comment
  reads "自行设计计算完整性数据和的方法" ("design your own way to
  compute the integrity checksum") -- this codebase's author left an
  intentional customization hook, but the function that actually
  shipped in THIS archive is just:
  ```lpc
  string calc_sec_id(int raw) { return "none"; }
  ```
  `save()` stores this raw, un-hashed placeholder verbatim
  (`set("sec_id", calc_sec_id())`); `restore()` then checks
  `crypt(calc_sec_id(1), sec_id) != sec_id` -- i.e. re-hashes the SAME
  literal `"none"` using the stored value as the crypt salt, and
  compares the result against that same stored value. Since the stored
  value is the raw plaintext `"none"`, not a real crypt hash, `crypt()`
  can never reproduce it byte-for-byte, so this check **failed
  unconditionally, for every account, every time**, setting
  `user_cracked = 1` and making `restore()` return `0`. Traced through
  `adm/daemons/logind.lpc::check_ok()`'s `if (user->restore()) {
  ...enter_world...} else { destruct(user); write("无法读取你的数据
  档案，您需要和巫师联系。\n"); ... }` -- confirmed live: a freshly
  registered, fully-saved character (`testqin`, real Chinese name,
  admin+regular passwords, full stat block on disk) could complete
  registration and play normally within the SAME driver session (any
  still-net-dead reconnect skips `restore()` entirely via a different
  `check_ok()` branch), but **could never log back in again after any
  driver restart** -- exactly reproduced, then fixed and reproduced
  clean, via two full kill+reboot+reconnect cycles. This is the same
  structural idiom already used correctly, with a REAL non-stub
  implementation, by sibling lib `hell`'s own `calc_sec_id()`
  (`clone/user/user.lpc:932`, a genuine checksum over the whole
  dbase/skills/inventory, gated by the exact same `if (!raw) str =
  crypt(str, 0); return str;` shape) -- confirming this placeholder was
  simply never finished in this specific archive, not a driver
  incompatibility invented by conversion. Rather than inventing a real
  checksum algorithm (out of scope -- that would be completing missing
  game-content logic the original author explicitly punted on), this
  was fixed as a narrow, mechanical round-trip correction: restore the
  missing `crypt()`-salt gating so the SAME placeholder value
  round-trips consistently (i.e. make the un-implemented check a true
  no-op instead of an always-fail trap), reusing the exact gating shape
  already present verbatim in `hell`:
  ```lpc
  string calc_sec_id(int raw)
  {
          string str;

          str = "none";
          if (! raw)
                  str = crypt(str, 0);
          return str;
  }
  ```
  Verified: a fresh account registered, saved, and quit; driver killed
  and restarted; the SAME account reconnected cleanly all the way back
  into the game world ("你连线进入revive" / room redisplay / clean
  `quit`) -- reproduced the failure once pre-fix (exact "无法读取你的
  数据档案" message) and the fix twice post-fix (including once through
  this lineage's legitimate, unrelated 30-second reconnect-cooldown
  gate, which is intentional throttling, not a bug).
- **Missing runtime directory, the §7.11 pattern**: `/log/nosave/`
  (referenced by `clone/user/user.lpc`'s own `sec_id`-mismatch logger,
  `clone/medicine/{wuchang,shengsheng,jiuhua}.lpc`, `clone/ultra/
  xuanhuang.lpc`, `adm/daemons/eventd.lpc`, `feature/vi.lpc`, and
  others) never shipped in this archive and was created as part of
  pre-boot setup, alongside the full `data/{login,user}/{a-z}/` shard
  tree, `data/{npc,item,board,room}/`, `backup/`, `version/`, `dump/`,
  `temp/`, and `binaries/` (all referenced by `adm/daemons/versiond.lpc
  exclude_dir`/various `DATA_DIR`+subpath writes, none shipped in this
  stripped archive either). Before this directory existed, the exact
  same `calc_sec_id()` mismatch above additionally crashed with an
  UNCAUGHT `*Wrong permissions for opening file /log/nosave/user for
  append` on every single login attempt (a second, independent failure
  mode stacked on top of the always-mismatching check itself).

## Confirmed content gaps (NOT fixed, per project policy)

- **51 of the original ~54 domains never shipped in this archive** --
  `/d/city` (this archive's own `START_ROOM` target,
  `/d/city/kedian`), `/d/wudang`, `/d/shaolin`, `/d/emei`, etc. all
  simply don't exist. Every `clone/board/*_b.lpc` city message-board
  clone (60+ files), several `adm/npc/{ganjiang,moye,youxun}.lpc`
  content NPCs, `clone/weapon/{jsbaojia,xtbishou}.lpc`, and the
  `data/room/moman/*` subtree all reference rooms/items in these
  missing domains and fail to load with a clean (post-`virtuald.lpc`
  fix) `*call_other() couldn't find object '/d/...'` -- narrow,
  individually-diagnosed content gaps, not fixed.
- **`kungfu/skill/` doesn't exist at all** -- only the skill
  *framework* (`kungfu/special`, `kungfu/condition`, `feature/
  skill.lpc`) survived this stripped release. `adm/npc/luban.lpc`
  (`set_skill("literate", ...)`), `d/death/npc/{bgargoyle,
  wgargoyle}.lpc` (`dodge` skill -- these ARE inside the one domain
  that DOES ship, `d/death`, but reference a skill this archive
  doesn't), and `clone/npc/killer.lpc` (`blade` skill) all fail with
  `*F_SKILL: No such skill (...)`. Not fixed -- inventing an entire
  skill-content tree is squarely out of scope.
- **`adm/daemons/cruised.lpc`, entirely dead/unreachable code with
  pre-existing author bugs** -- not on the preload list, not
  referenced by any macro or call site anywhere else in the archive
  (`grep`-confirmed). Fails to compile on its own merits regardless of
  content gaps: missing `#include <net/socket.h>` (undefined
  `STREAM_BINARY`), missing `inherit F_DBASE` (undefined `set()`), and
  a genuine typo (`CAHNNEL_D` for `CHANNEL_D`). Per this project's
  standing "don't spend time making dead code compile" policy (§2.3),
  left as-is.
- **`adm/daemons/quest/girl.lpc`**: references undefined variables
  (`rcv_npcs`, `supply_objs`) that are presumably meant to come from a
  shared base class this stripped archive's `adm/daemons/quest/`
  subtree doesn't fully carry -- a genuine incomplete-content gap in
  the shipped quest-daemon set, not fixed.
- **`adm/daemons/story/{master,pangtong,baguadao}.lpc` "fail to load"
  with NO error text at all -- confirmed NOT a bug.** Read each
  file's `create()`: `story/master.lpc` self-destructs unless
  `uptime() >= 86400` (a 24-hour-gated "华山论剑" special event, by
  design); `pangtong.lpc`/`baguadao.lpc` self-destruct whenever their
  own `select_character()` helper can't find a qualifying live player
  to feature (also by design -- these are special "current server
  population" narrative-event objects, not meant to persist in an
  empty/freshly-booted world). `story/{caishen,dabei,beihai,hyshan,
  ...}.lpc` (no such uptime/population gate) load and pass cleanly in
  the same batch sweep, confirming the difference is each file's own
  intentional self-destruct condition, not a shared bug.
- **`adm/simul_efun/{message,util}.lpc` "fail to load" standalone --
  confirmed a batch-sweep artifact, not a real bug.** Both files are
  textually `#include`d into `/adm/single/simul_efun.lpc` (after
  `#include <ansi.h>`/`<localtime.h>` already appear there) and rely
  entirely on that inclusion context for their own ANSI-color-macro
  references (`HIW`, `NOR`, etc. -- `message.lpc`) and
  `<localtime.h>`-derived macros (`util.lpc`); neither file `#include`s
  those headers itself. `lpcc_check.sh`'s batch sweep tries to compile
  every physical `.lpc` file as its OWN standalone object, which
  correctly fails for these two (their macros are genuinely undefined
  in that isolated context) -- but the REAL simul_efun object
  (`/adm/single/simul_efun`, which DOES textually include both files
  in the right order) compiles and boots 100% clean, confirmed via a
  direct single-file `lpcc` run before ever touching the full batch
  sweep. Not a bug; not fixed.

## Boot / registration verification

- `~/src/fluffos/build-debug/src/lpcc`, single-file, confirmed clean on
  the master (`adm/single/master`) and simul_efun
  (`adm/single/simul_efun`) chain first, then a scoped `--batch` run
  over all 110 `feature/*.lpc` + `inherit/**/*.lpc` files -- 110/110
  passed on the first attempt (per this project's RAM-safety
  discipline: core base classes verified individually/in a small
  scoped batch BEFORE ever running the full sweep).
- Full `lpcc_check.sh` batch sweep (all 1,169 objects): peaked at
  ~2.6GB RSS (well under the 10GB safety threshold, monitored every
  ~5s throughout), completed in well under a minute each of the 3
  times it was run this session. Final count: **1,081 / 1,169 = 92.5%
  pass** (88 failures, all triaged above into: missing city-domain
  content, missing skill-tree content, one dead/unreferenced file with
  pre-existing author bugs, one incomplete quest daemon, 3
  self-destruct-by-design story-event objects, and 2 batch-sweep-only
  standalone-compile artifacts). None of the 88 affect the actual
  boot/registration/gameplay path exercised below.
- Real `build-debug` driver boot on port 40236: clean, zero fatal
  `debug.log` errors after all fixes above (only benign compile
  warnings, correctly routed to the master's own log file after the
  `log_error()` fix, never shown to a connecting player).
- Full registration flow verified via raw Python socket scripts
  (telnet IAC-stripping, scripted `input_to()` sequence with
  per-prompt waits -- `mudclient.py`'s idle-based receive loop proved
  unreliable against this lineage's live per-second clock prompt, the
  documented "recv loop breaks on live clock prompt" gotcha, so a
  purpose-built raw socket script was used instead), **4 independent
  full runs** with real Chinese names (surname/given-name: 秦/风,
  秦/云, 秦/测, plus the admin account below), covering all 5
  character-type options and both genders across the runs: each
  reached the actual starting room "世外桃源" ("Peach Blossom Land" --
  the same entry room already documented for the wider yh2003/ES2
  family in `zhyx`'s notes), with NPC 水笙 present and reactively
  greeting the new arrival, `look` correctly re-displaying the room,
  `score` correctly returning the graceful "还没有出生呐，察看什么？"
  (not-yet-born, matching this lineage's own intentional pre-birth
  response, not an error), and `quit` cleanly returning "欢迎下次再来
  ！". One of the 4 runs (the first, before the `calc_sec_id()` fix)
  demonstrated the SEVERE bug directly: a same-session net-dead
  reconnect worked, but a clean reconnect after a driver restart hit
  "无法读取你的数据档案" every time -- reproduced twice pre-fix,
  disproven twice post-fix (including once through the lineage's own
  legitimate 30-second reconnect-cooldown gate).
- Admin account seeded: id `fluffos`, 普通密码(login) `Mud@2026`,
  管理密码(recovery) `Mud@2026Adm`, display name 浮浮 (surname
  skipped with a bare newline -- a lone `浮` alone is rejected by the
  2-character-minimum combined-name check, the same intentional-content
  floor already documented for `zhyx`; given name `浮浮` instead).
  Granted `(admin)` via `fluffos (admin)` appended to `adm/etc/wizlist`
  (same plain-text `wiz_name status` format as the existing `ivy
  (admin)` entry). Verified across a driver restart: `fluffos`/
  `Mud@2026` login succeeds, the online-count banner correctly counts
  1 巫师 (wizard) rather than 1 玩家 (player), and `look` shows the
  wizard-only room-path suffix (`世外桃源 - /d/register/entry`),
  confirming `(admin)` status is live; `quit` clean.
- Save files for the orchestrator to add (not gitignored, normal add):
  `libs/revive/work/data/user/f/fluffos.o`,
  `libs/revive/work/data/login/f/fluffos.o`. All other test characters'
  save data (`testqin`, `qinfeng`, `qinyun` -- 3 throwaway ids across
  the session, one per major fix-verification pass) was deleted before
  finishing, per convention.
- Outbound network check (per task step 6): **a real, active listening
  side effect confirmed** -- `adm/daemons/ftpd.lpc` is on the preload
  list and, in this sandboxed test environment, successfully bound and
  LISTENed on TCP port `mud_port + 21` (`40257`, confirmed via `ss
  -ltnp` showing a live `LISTEN` socket owned by the driver process)
  the moment the driver booted. Separately, `adm/daemons/network/
  dns_master.lpc` and `adm/daemons/network/messaged.lpc` (both
  preloaded) and `adm/daemons/versiond.lpc` (lazily loaded on the
  first connection attempt, via `logind.lpc::logon()`'s
  `VERSION_D->is_version_ok()` call) each unconditionally attempt a
  real `socket_create()`/`socket_bind()` at boot for UDP ports
  `mud_port+4`/`mud_port+10` and TCP port `mud_port+12` respectively --
  all 3 FAILED in this specific sandboxed environment
  (`log/{dns_master,messaged,version}` show repeated "Failed to bind
  socket ... error = -10", almost certainly a sandbox network-namespace
  restriction rather than a port conflict), but the code path is
  identical to `zhyx`'s already-documented `dns_master.lpc` finding and
  would very likely succeed on an unrestricted host. **This lib should
  therefore NOT be swept into high-frequency automated reboot loops**
  (§10.0-style long-sit scans, round-two/round-three re-test cron) the
  way most sandboxed libs in this collection safely can be -- `ftpd`'s
  listening socket in particular is a real, unauthenticated network
  service exposed at every single boot in an environment where the
  bind actually succeeds.

## Not run this session

- **LPC formatter (§9)**: not run against the edits above (matches the
  precedent set by `zhyx`, where `node` was unavailable in that
  session's environment too). Every edit in this session was small
  (a handful of lines each) and manually reviewed against the
  surrounding code's own indentation/brace style.
- **Full deep §10.7-style playthrough / WASM pass**: out of scope for
  this onboarding session per the task brief (native boot +
  registration verification only). The `ftpd`/`dns_master`/`messaged`/
  `versiond` real-network side effects are an extra reason to be
  deliberate about how often this lib gets rebooted in any future
  automated long-sit/WASM-enablement pass.

## 2026-08-27 深度功能测试 / Deep functional test (round two, §10.7)

Read `help/newbie` first (registration -> pick personality via `out` in
one of 4 rooms -> `wash` for stats -> `born <地名>` into the world).
Ran a real, continuous session with a fresh Chinese-named test
character (surname/given-name 秦/石, then 秦/言 for a second,
never-born control character used for the restart/reconnect check),
plus the seeded `fluffos`/`Mud@2026` admin for `goto`-based exploration
of the two non-register domains. Native `build-debug` driver, port
40236, one lib at a time, killed by exact PID between reboots.

### SEVERE, confirmed live: every new player's first move out of the
registration room threw an uncaught driver error (`d/register/npc/
diyun.lpc`'s unguarded `carry_object()->wear()`)

`d/register/npc/diyun.lpc::create()` (the "狄云" NPC who sees new
players off at the register-room exit) did:
```lpc
carry_object("/d/city/obj/cloth.lpc")->wear();
```
`/d/city` is one of the ~51 domains this stripped archive never
shipped (already documented above), so `carry_object()` (`inherit/
char/npc.lpc`) correctly returns `0` on the missing file -- but the
call site immediately dot-calls `->wear()` on that `0` with no
`objectp()` guard, which the driver rejects as `*Bad argument 1 to
EFUN call_other() Expected: object, string, array, Got: int(0)`.
Reproduced live: a freshly-registered character's very first `east`
(or any exit) out of `/d/register/entry` triggered `d/register/
entry.lpc::valid_leave()`'s own ad-hoc `new(__DIR__"npc/diyun")` (not
the room's normal `make_inventory()`-populated `objects` list, so the
onboarding session's `make_inventory()` `catch()` fix -- which only
covers population via `reset()` -- never protected this path), which
ran `diyun`'s `create()` uncaught, dumping a full driver stack trace
straight to the connecting player:
```
执行时段错误：*Bad argument 1 to EFUN call_other()
程式：/d/register/npc/diyun.lpc 第 16 行
```
This is universal -- every single player who successfully registers
and decides hits it on their first move, though it's non-fatal (the
error is swallowed after being printed and the move itself still
succeeds; `diyun` just has no visible clothes afterward). **Fix**
(same shape as the onboarding `make_inventory()` fix, §7.25 family --
guard the call, don't fabricate the missing content):
```lpc
object cloth;
...
if (objectp(cloth = carry_object("/d/city/obj/cloth.lpc")))
        cloth->wear();
```
Verified live post-fix: `east` out of `/d/register/entry` now prints
only "狄云对你一抱拳，道：人生路全靠自己走，朋友走好！" with zero
error trace, across a fresh boot.

**Same exact unguarded `carry_object(missing)->wear()/->wield()` shape
found and fixed at 3 sibling call sites** (grepped every `carry_object(
...)->` call site in the tree, cross-checked which referenced targets
are actually missing in this archive vs. real, shipped `/clone/...`
items -- most of the ~30 hits are fine, these 3 aren't):
- `adm/npc/youxun.lpc` (`carry_object("d/city/obj/cloth")->wear()`) --
  not reachable in normal play (its home city is missing) but crashes
  the instant anything clones/loads it (confirmed via a scoped `lpcc`
  run: post-fix it correctly falls through to the already-documented,
  separate "kungfu/skill/ doesn't exist" content gap instead).
- `clone/npc/meng-zhu.lpc` (2 sites: `/d/shaolin/obj/changjian` +
  `/d/city/obj/cloth`, plus a 3rd/4th site in the `restore()`-branch
  using a saved `weapon`/`armor` path that could equally be stale) --
  same treatment, same post-fix fallback to the skill-content gap.
- `clone/megazine/room/npc/mm.lpc` (`/d/city/npc/obj/qunzi`) -- this
  one now compiles and loads 100% clean post-fix (no residual content
  gap behind it).

All 4 fixes verified via a scoped `lpcc --batch` run before and after
(diyun and mm flipped FAIL->PASS cleanly; youxun/meng-zhu flipped from
the `wear()`-crash FAIL to the pre-existing, correctly-untouched
`*F_SKILL: No such skill` FAIL) and a full `lpcc_check.sh` sweep
(1081/1169 -> 1087/1169, zero new failures anywhere else). **Likely to
recur in `hell`/`hellxg`/`zjmudhell`**: this is boilerplate NPC-dressing
code copied across many files in this lineage; those siblings ship the
full city content so their own `carry_object()` targets probably
resolve, but it's worth a quick grep of `carry_object(...)->` there too
in case any of *their* target paths are themselves stale/renamed.

### SEVERE, confirmed via `lpcc`: the entire quest subsystem (5 of 6
quest-type files) failed to compile -- a shared wrapper's parameter
type didn't match how every real caller used it

`inherit/misc/quest.lpc::set_information(string key, string info)` --
but `clone/quest/{shen,supply,explore,search,judge}.lpc` (every quest
type except the already-content-gapped `girl.lpc` and the plain
`avoid.lpc`) call it with a **function pointer** as the second
argument (`set_information(NPC1_NAME, (: ask_npc1 :))`, etc.) so an
NPC's own name/id can trigger a dynamic answer instead of a fixed
string. The underlying daemon side (`adm/daemons/questd.lpc::
set_information(object qob, string key, mixed info)`) already declares
`info` as `mixed` and handles this fine -- only the thin per-quest-
object wrapper in `quest.lpc` had the wrong, narrower `string`
declaration, which this driver enforces strictly at compile time:
```
error: Bad type for argument 2 of set_information ( string vs function )
```
Since EVERY quest-type file needs this call, all 5 real quest classes
failed to compile entirely, and the quest daemon's own `heart_beat()`-
driven `start_quest()` (an ambient, ~15-minute-interval background
process, ran unprompted mid-session) threw a fresh uncaught `*No
program in object '/clone/quest/search'!` (and identically for the
other 4) every time it tried to spin one up -- caught by the driver's
error handler so it didn't crash the mud, but it silently broke 100%
of this stripped archive's quest content and spammed `debug.log`
forever. **Fix**: widen the one declaration to match its own daemon
counterpart and every real caller:
```lpc
void set_information(string key, mixed info)
```
Verified via `lpcc --batch`: all 6 quest files (`shen`, `supply`,
`explore`, `search`, `judge`, `avoid`) now PASS; `girl.lpc` still fails
on its own, separate, already-documented undefined-variable content
gap (untouched, correctly). This is a narrow shared-file type-
declaration bug, not a content decision -- fixing it doesn't invent
any of the missing quest content, it just lets the existing quest
*code* run instead of refusing to compile.

**Companion fix, found via the same ambient heart_beat error**:
`adm/daemons/quest/{supply,explore}.lpc::start_quest()` both do
`env = get_object(room); ...present(rcv_npcs[room], env)...` with no
`objectp(env)` check -- since `rcv_npcs`' keys are real, well-formed
room paths but every single one of them lives in a domain this
archive never shipped (`/d/city3`, `/d/dali`, `/d/changan`, `/d/city`,
`/d/beijing`, `/d/shaolin`, `/d/suzhou`, `/d/hangzhou`, `/d/fuzhou`,
`/d/quanzhou`, `/d/lingzhou` -- a pure content gap, not a code bug),
`get_object()` always returns a non-object, and `present(x, 0)` throws
`*Bad argument 2 to present() Expected: object Got: 0`, also caught
but also spamming `debug.log` every ~heart_beat forever. Fixed with a
one-line `! objectp(env)` guard added to each, mirroring the
already-fixed `quest/girl.lpc` sibling (which coincidentally can't
even reach this line, since it fails to compile first on its own
undefined-variable gap). `adm/daemons/quest/{judge,search,shen}.lpc`
use a different, already-guarded room-selection shape and needed no
change at THIS call site -- but see the next finding, which hit all
three of them at a different call site.

**Second content gap uncovered by the same `set_information()` fix,
in the very next line the fix unblocked**: once the quest files could
actually compile, letting the daemon's `heart_beat()` reach past the
old compile failure, `clone/quest/{search,judge}.lpc::init_quest()`
(`npc1 = new(CLASS_D("generate") + "/questnpc"); ... npc1->set_temp(
...)`) and `clone/quest/shen.lpc::init_quest()` (same shape, single
`npc`/`"/shennpc"`) immediately hit a FRESH ambient uncaught error,
live, unprompted, within the very next heart_beat cycle after the
reboot:
```
执行时段错误：*Bad argument 1 to EFUN call_other()
Expected: object, string, array,  Got: int(0).
程式：/clone/quest/search.lpc 第 67 行
```
Root cause: `CLASS_D("generate")` expands to `/kungfu/class/generate`,
and this WHOLE directory -- not just `/kungfu/skill/`, a separate,
already-documented gap -- never shipped in this stripped archive
(confirmed: `find . -path "*kungfu/class*"` returns nothing at all).
`new()` on the missing `.../questnpc`/`.../shennpc` template correctly
returns `0` (per the onboarding session's `virtuald.lpc` fix), but
none of the three call sites checked before dot-calling `->set_temp()`
on the result -- the exact same missing-guard shape as the `carry_
object()->wear()` family above, just one more content-gap directory
deep. **Fix**, same established pattern (guard + self-destruct via the
function's own pre-existing "can't proceed" idiom, already used one
branch up in the very same functions for the "item already claimed by
another quest" case):
```lpc
npc1 = new(CLASS_D("generate") + "/questnpc");
npc2 = new(CLASS_D("generate") + "/questnpc");
if (! objectp(npc1) || ! objectp(npc2))
{
        destruct(this_object());
        return;
}
```
(single-`npc` variant for `shen.lpc`). Verified via `lpcc --batch`
(all 3 still PASS) and live: rebooted again, let the driver idle
through 3+ heart_beat cycles (supply/explore/search/judge/shen all
fire on their own timers), `debug.log` grepped clean of any `执行时段
错误`/`*`-prefixed runtime error for the whole idle window post-fix.

**`/kungfu/class/generate/` is a third, previously-undocumented missing
content subtree** (distinct from `/kungfu/skill/`), also referenced
unguarded by `adm/daemons/questd.lpc` (`receiver.lpc`, `killed.lpc` --
the letter-delivery and bounty-quest NPC generators) and `adm/daemons/
npcd.lpc` (`chinese`/`japanese`/`european`/`indian` generic-NPC
templates). Those 6 additional call sites were deliberately **left
unfixed**: unlike the 3 quest-heart_beat sites above, none of them are
reachable via any live path in this archive -- they only fire from
inside quest-giver dialogue that no NPC in the 3 shipped domains
actually offers, so fixing them would be speculative hardening against
an unreachable trigger rather than a live, in-scope bug, and the
missing-content directory itself is the same well-established
"don't fabricate content" boundary as `/kungfu/skill/`. Flagged here so
a future session doesn't have to rediscover the same gap from scratch,
and doesn't mistake "reachable via heart_beat" for "reachable at all"
when triaging which of a batch of similar-looking call sites are worth
fixing.

### §8.3a variant confirmed: two more `private` mixin functions
dispatched by name via `call_out()`, not just `add_action()`

Grepped every `private`-declared function in the tree against same-
file `call_out("name", ...)` / `add_action("name", ...)` call sites,
then filtered out the (majority) false positives where the private
function lives in a standalone daemon/NPC/command file that's never
`inherit`ed into a different top-level body (for those, the driver's
own internal dispatch on `this_object()` never crosses the
private/DECL_HIDDEN boundary, so there's no bug). Two real, live mixin
instances remained, **both already named verbatim in this project's
own §8.3a catalog as confirmed `demonangel` sibling instances** of the
exact same class:
- `feature/action.lpc::start_call_out()` does
  `call_out("eval_function", delay, fun)`, but `eval_function` was
  `private`. `feature/action.lpc` is `F_ACTION`, inherited by
  `inherit/char/char.lpc` (`CHARACTER`), inherited by `clone/user/
  user.lpc` -- i.e. the actual player body. `start_call_out()` is the
  ONLY delayed-callback primitive used throughout this codebase for
  anything that must survive the calling object being destructed
  mid-delay (its own header comment explains why): kungfu temporary-
  condition effects (`kungfu/special/{agile,hatred,power}.lpc`'s
  `remove_effect`), sleep/meditation wakeup (`cmds/std/sleep.lpc`,
  `cmds/skill/jingzuo.lpc`), room-cart arrival (`inherit/room/
  trans.lpc`), combat's own `continue_attack` (`adm/daemons/
  combatd.lpc`, 6 sites), `steal`'s completion, `makelove`'s
  `do_over`, the quest daemon's own follow-up callbacks, and several
  more -- a very wide, central blast radius, though not independently
  live-reproduced this session (no reachable room in this stripped
  archive has `sleep_room` set, and there's no `eval`-equivalent
  wizard command to force a synthetic repro; the fix rests on the
  identical, already-proven-live `demonangel` precedent plus a clean
  `lpcc` recompile).
- `inherit/item/combined.lpc::set_amount(0)` does `call_out(
  "destruct_me", 0)` to self-destruct an emptied stackable item
  (money down to 0, a depleted material stack, etc.), but `destruct_me`
  was `private`. `COMBINED_ITEM` is inherited by `inherit/item/
  money.lpc`, `inherit/weapon/throwing.lpc`, `inherit/medicine/
  powder.lpc` and several `clone/misc/*.lpc` items -- meaning every
  coin/silver/gold object, thrown weapon, medicine powder, etc. that
  ever gets reduced to a zero count would silently never self-destruct
  and instead linger as an inert zero-quantity husk forever.

**Fix** (both, matching the established pattern): drop `private`, keep
the function otherwise unchanged --
```lpc
// feature/action.lpc
void eval_function(function fun) { evaluate(fun); }
// inherit/item/combined.lpc
void destruct_me() { destruct(this_object()); }
```
Verified via `lpcc --batch`: no regressions (all previously-passing
files affected by either inherit chain still pass). **Likely to recur
in `hell`/`hellxg`/`zjmudhell`**: `feature/action.lpc` and `inherit/
item/combined.lpc` read as core, shared engine files in this lineage
(not stripped-archive-specific content), so this exact
`start_call_out`/`eval_function` and `combined_item`/`destruct_me`
shape is a strong candidate to check on those 3 siblings the next time
any of them gets a §10.7 pass -- grep `private.*eval_function` and
`private.*destruct_me` directly.

### Confirmed clean (all six standing cross-cutting patterns checked)

- **§7.121** (float-arithmetic function declared `int`, no
  `to_int()`): no currency/economy function in this lib does real
  float math -- `inherit/item/money.lpc::value()`, `feature/
  banker.lpc::do_convert()`, and `feature/dealer.lpc` all use plain
  integer division/multiplication throughout; every `base_value` is a
  literal integer. Clean.
- **§8.3a** (`private` mixin function dispatched by name): the
  already-fixed `command_hook` instance holds (confirmed live --
  `d/register/npc/lu.lpc`'s `command("chat ...")` on personality
  selection worked with zero error). Two NEW instances found and
  fixed this session, see above. A full grep of every other `private`
  function against same-file `call_out`/`add_action` targets found no
  further live (inherited-mixin) instances -- the remaining ~25 hits
  are all standalone daemon/NPC/command files, correctly unaffected.
- **§7.122** (autoload-class marker-item duplication): this codebase
  has no `compute_autoload_array`/`destroy_autoload_obj`/
  `load_autoload_obj`/`query_auto_load` mechanism at all (grepped,
  zero hits) -- not applicable to this lineage.
- **§7.123** (bare file-scope `IDENT = (...)` statement): grepped for
  a column-zero `IDENT = ([`/`({` pattern across every `.lpc` file --
  zero hits (every match found was properly indented, i.e. inside a
  function body). Clean.
- **§7.124** (0.0-1.0 fraction vs. 0-100 percentage threshold): `wimpy`
  (the auto-flee threshold, `inherit/char/char.lpc` + `cmds/usr/
  wimpy.lpc`) defaults to plain integer `0` and is set/compared as a
  0-100 percentage throughout, matching its own field type
  consistently -- no float-literal mismatch anywhere. Grepped the
  whole tree for `= 0\.[0-9]+;` assigned to an `int`-declared field:
  zero hits. Clean.
- **§7.126** (stale pre-`.lpc` extension in a door/exit save-file
  macro-placeholder resolved by a custom `file_path()`-style helper):
  this codebase has no coordinate-grid `AREA`/`file_path()` engine at
  all -- rooms use plain hard string exits, resolved directly by
  `load_object()`, no macro substitution layer. The one place a stale
  `.c` extension WAS found in persisted data (`data/dbased.o`'s
  `/d/huashan/ziqitai` entry, `"test":"/data/room/doing/xiaoyuan.c"`)
  is dead, unreachable data -- `/d/huashan` is itself one of the ~51
  missing domains in this stripped archive, so this exact save-file
  entry can never actually be loaded/hit regardless of the stale
  extension; confirmed via `inherit/room/room.lpc` never consuming any
  dbase-stored `"exits"` data at all for exit resolution in this
  archive. Not a live bug, not fixed.

### Registration / personality / born / quit-reconnect -- all confirmed
working correctly (post-fixes)

Full continuous session with `秦石` (male, 光明磊落 personality via
the east-room NPC 陆天抒, matching the newbie-help-documented flow
exactly): register -> decide -> `out` of the east personality room ->
arrived at 阎罗殿 (`d/register/yanluodian.lpc`) -> `wash` (rolled
str/int/con/dex 19/22/19/20) -> `born 扬州人氏` correctly failed
gracefully ("牛头一呆，搔搔头说：怎么好像有问题...", the
already-documented `/d/city` content gap, zero crash) -> `score`/`i`
both rendered a full, sensible status display (age 14, personality,
starting clothes from account creation) despite the failed born.
`quit` was clean both times tested (dropped the now-worthless newbie
book, correct farewell message), `debug.log` grepped after each quit
(clean both times, post-fix). A second, never-`wash`ed/never-`born`
control character (`秦言`) was registered specifically to verify the
onboarding session's `calc_sec_id()` restart-lockout fix still holds
after this session's edits: registered -> `decide` -> `quit` -> driver
killed by exact PID and rebooted -> reconnected after the restart ->
correctly restored into `/d/register/entry` with the right "上次光临"
timestamp and pre-birth `score` message -> `quit` cleanly again. The
fix holds.

**One notable downstream interaction, not a new bug**: `d/register/
yanluodian.lpc::do_born()` sets `me->set("startroom", dest)` *before*
checking whether the destination object actually loaded, so a failed
born (this archive's universal case, since every `born` target is a
missing domain) still permanently records a nonexistent `startroom`.
A player in this state who later `quit`s and reconnects will hit
`logind.lpc::enter_world()`'s own `catch(load_object(startroom))`
failing (a SEPARATE, already-existing catch from the onboarding
session, working exactly as designed) and land in the graceful "你无
法进入这个世界" fallback message with no environment, rather than
back in the register room -- reproduced live on `秦石` post-fix-boot.
This is a downstream consequence of the well-documented, deliberately-
untouched missing-city-domains content gap (not a new code bug: the
existing catch already prevents a crash, and there is no live-
reachable `born` target in this archive that would ever leave a
character in this state on a fully-built release), so left as-is --
flagged here only so a future session doesn't mistake it for a new
regression.

### Combat / skill / sect / shop / death-respawn: **not reachable
live in this stripped archive** -- content gap, not a code bug

Confirmed via direct testing that `born` cannot succeed for ANY of the
18 listed destinations (every single one targets a domain this
archive never shipped: `/d/city`, `/d/guanwai`, `/d/beijing`, `/d/
taishan`, `/d/changan`, `/d/shaolin`, `/d/xingxiu`, `/d/xiangyang`,
`/d/suzhou`, `/d/hangzhou`, `/d/fuzhou`, `/d/city3`, `/d/dali`, `/d/
foshan`, `/d/baituo`, `/d/yanziwu`, or the intentionally-disabled `0`
placeholders for 蒙古/黔中), so a player can never leave the register
domain through the game's own intended path. The only other two
shipped domains (`d/death`, `d/pk`) were explored directly via admin
`goto` instead:
- `d/pk` (`entry`/`ready`/`turen1-12`) is a scheduled PK-tournament
  arena (`乌老大`/`wu laoda` signs players up for an uptime-gated
  "屠人大赛" event, matching the `story/master.lpc`-style 24-hour-gate
  pattern already documented above) -- no safe-sparring dummy exists
  here or anywhere else in the shipped content (grepped `accept_fight`
  project-wide: the only hit outside `inherit/char/{fighter,npc,
  punisher,challenger}.lpc`'s shared base logic is `cmds/std/
  fight.lpc`, the "较量" command documented in `help newbie` itself --
  but it requires a real opposing character, and the only NPCs in the
  3 shipped domains are non-combative dialogue/quest-giver roles).
- `d/death` (`gate`/`gateway`/`road1-3`/`inn1-2`/`block`) is the
  ghost-gate/resurrection domain matching `help newbie`'s own
  description. All rooms load and render cleanly via `goto`. Its two
  guard NPCs (`黑无常`/`bgargoyle`, `白无常`/`wgargoyle`) hit the
  already-documented "`kungfu/skill/` doesn't exist" content gap
  (`*F_SKILL: No such skill (dodge)`) inside their own `create()` --
  correctly swallowed by the onboarding session's `make_inventory()`
  `catch()` fix, so the room still loads fine, just without the NPC
  present. Both gate rooms are `no_fight` zones (confirmed via `kill`
  returning "这里不准战斗。").

Net: skill/sect acquisition, real combat, shop/economy, and death/
respawn are **all unreachable via any live path in this archive** --
not a testing gap, a genuine, already-well-documented content gap (no
`kungfu/skill/` tree, no sect NPCs, no shops, no city domains at all
survive in this "engine only" release). This was verified directly
this session rather than assumed from the onboarding notes.

## wasm_status 审计（2026-09-01）：VERSION_D 登入闸门缺 find_object() 守卫，验证为 playable

`meta.json` 的 `wasm_status` 此前一直留空（此前只做过原生驱动验证，
`NOTES.md` 已注明 WASM/§10.7 深测"out of scope for this onboarding
session"）。本次批量审计（见 [[project_wasm_status_audit]]）补上这
一步。

`scripts/wasm_client.js` 起跑本身没有触发编译期致命错误（这份
"底层代码"精简发行版没有自己的 simul_efun 级 socket 依赖），但每一
个新玩家连线都会被 `adm/daemons/logind.lpc` 直接踢掉，提示"现在本站
正在同步版本中，暂时不能登录，请稍候再尝试。"——这正是 AGENTS.md
§1.3(c) 目录里"中华英雄/终极地狱血统家族的 VERSION_D->is_version_ok()
式闸门"那一类（此前在 `zhonghua2`/`zhongjidiyu`/`zjdyzj`/
`yanhuangwuhun`/`yhyxs` 都出现过）：`adm/daemons/versiond.lpc` 自己
的 `socket_create()`/`socket_bind()`/`socket_listen()`/`socket_close()`
调用在 WASM 下编译失败（没有 `sockets` 包），使得 `VERSION_D` 这个
对象始终"不存在"，`VERSION_D->is_version_ok()` 每次都以运行期错误
收场、等效于返回 0，而 `logind.lpc` 把"未确认在线"当成"正在同步
版本"直接拒绝所有非巫师连线。

修复（标准 `find_object()` 守卫，缺席即放行，与 AGENTS.md 现有目录
写法一致）：`adm/daemons/logind.lpc` 两处新玩家/老玩家登入检查、
`adm/daemons/questd.lpc` 的任务系统启动检查、`adm/daemons/closed.lpc`
的 `heart_beat()`（从开机起每 3 秒执行一次，此前每次都要重新尝试
编译一遍上千行的 `versiond.lpc`，是明显的额外开销）都加上
`find_object(VERSION_D) &&` 前缀。`cmds/arch/version.lpc`（巫师手动
`version` 指令）未改，不在登入路径上，属正常的"外围指令编译失败"。

修复后跑通一次完整会话：英文 ID（3-10 个英文字母）→ 中文姓氏（留空）
→ 中文名字 → 管理密码×2 → 普通密码×2 → 角色资质(3)→ 性别(m) →
落地"世外桃源"，水笙/狄云 NPC 均在场，水笙主动提示注册 email →
`look` 正常显示房间描述 → `quit` 干净退出（"欢迎下次再来！"），全程
无未捕获错误。**踩到一个纯测试脚本层面的坑，记录以免下次误判为
bug**：这个 lineage 的游戏内提示符自带每秒刷新的实时时钟
（`19:43:47>` 这种），`wasm_client.js` 的空闲检测是"距离上一次驱动
输出满 N 秒才发送下一条指令"——只要 `--idle` 设得比 1 秒长，输出
永远赶在空闲阈值之前刷新一次，后续指令就会一直排队发不出去，直到
外层 `--timeout` 超时为止（观察到的现象是：注册正常走完、进入
游戏、然后卡住不再有任何指令生效）。换成 `--idle 0.3`（小于时钟
刷新间隔）后 `look`/`quit` 才能正常送达并看到回显。`wasm_status`
设为 `playable`。
