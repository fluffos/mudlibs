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
