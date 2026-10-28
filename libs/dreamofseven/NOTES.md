# dreamofseven (夢幻七域 / The Dream of Seven) -- porting notes

Source: `git clone https://github.com/MudRen/mudos-game-ds` (commit
`07ea84ebdff5ee49cb482a520bdf1aaeda886cd0`, cloned 2026-08-26). The
repo's own `README.md` names the game "The Dream of Seven" / "夢幻七域"
and lists a live BBS mirror (`telnet://140.128.9.202:23 DS_MUD`) and a
website (`http://ds.redirect.hm`). Slug `dreamofseven`, number 938, port
40240. Quick `ls libs/` sanity check against the rest of the collection
found nothing else with this title or an obviously-related codebase
(the closest superficial name match, `ds386`, is an unrelated English
Dead Souls partial noted as permanently out of scope in AGENTS.md §10.6).

## Lineage -- ES II / Annihilator base, but NOT any already-catalogued sub-branch

`adm/obj/master.lpc`'s header comment is just:

```
// for ES II mudlib
// original from Lil
// rewritten by Annihilator (11/07/94)
```

-- notably missing the "modified by Xiang for XKX (12/15/95)" and
"updated by Doing Lu for hell (2K)" / "Modify By Linux@lxtx for yh
2003.3" lines that mark every other ES2-descended family already in
this collection (`hell`/`zjdyaryl`/`xkxc98sj`, `yanhuangwuhun`/`zhyx`,
`xkx100`/`xkx2017`, etc. -- see AGENTS.md §11). The boot banner
(`adm/etc/welcome`) confirms this independently and gives an exact
founding date: "夢幻七域<建立架構 Feb 7, 1999>其精神源自ES2 Mudlib架構
，特此感謝Annihilator。" This makes it a more distant, independently-
forked member of the wider "ES II / 東方故事 mega-family" (AGENTS.md
§11 already lists "a further, more distant sibling by the same
master.lpc header" alongside `kxkj`/`kxkj1`/`kxkjii2` -- this lib is
consistent with that same distant-ES2 shape, though not verified
byte-identical to any specific already-catalogued member). File/dir
layout (`adm/obj/master`+`adm/obj/simul_efun`, not `adm/single/` or
`adm/obj/master.c` alongside a `secure/`) and the whole registration
flow (English login id -> confirm -> Chinese name -> dual password ->
email -> race selection -> confirm -> gender -> world entry) match the
general ES2 shape but are this codebase's own independent
implementation -- not diffed against any sibling since none in this
collection shares this specific distant-ES2 shape closely enough to be
worth porting fixes from wholesale; every fix below was independently
diagnosed from this archive's own code and its own compile/boot output.

Raw archive: 32,946 files (~168MB) under `ds/` (a `README.md`,
`player-manual/`, `ReferenceMaterials/`, `Wizard/` manual tree, and
`welcome.png` sit alongside it at the repo root but are not mudlib
source). Two full playable regions, `open/world1/` and `open/world2/`,
plus a curious `open/world1/world2/` subtree that duplicates most of
`open/world2/`'s content near-identically (not byte-for-byte -- `diff
-rq` shows real per-file differences, mostly small) -- present
identically in the raw, pre-conversion archive, so this is the
upstream author's own layout (very likely a "portal copy" of world2
content reachable from within world1), not a conversion artifact.

## Pipeline

1. Cloned directly into `libs/dreamofseven/raw/ds/ds/` (git-hosted
   source, `.git` stripped before copying in). The actual mudlib root
   is the inner `ds/ds/` directory (`ds.config`'s `master file : /adm/obj/master`
   confirms it) -- one level down from where the outer clone lands the
   repo's own top-level `README.md`/manual folders.
2. **Encoding: BIG5, not GB18030** -- confirmed via `chardet` (99%
   confidence) and by eyeballing a decoded `write(...)` string in
   `adm/obj/master.c` before running anything (a GB18030 decode of the
   same bytes silently "succeeds" into wrong-but-plausible-looking
   mojibake, per AGENTS.md §4.1's standing warning that GB18030 rarely
   hard-errors on real BIG5 text). `scripts/convert_lib.sh
   libs/dreamofseven/raw/ds/ds libs/dreamofseven/work BIG5`:
   `already_utf8=793 converted=31556 lossy=384 skipped_binary=213`;
   renamed 29,831 files to `.lpc`; fixed 6,427 literal `.c"` references
   (this pass turned out to be load-bearing far beyond cosmetic
   reference cleanup -- see the `preload()`/`new_ob()` finding below);
   `static`->`nosave` touched 95 files. No uppercase-`.C` stragglers,
   no `"static/...` string-literal collision, no `#define
   nosave/protected static` shim collision (all three checked and
   clear).
3. No full extensionless/whole-tree UTF-8 straggler sweep was run this
   session beyond `convert_lib.sh`'s own extension-based pass (large
   archive, and no symptom -- garbled banner text, "COM executable for
   DOS" false positives, etc. -- turned up during boot/registration
   testing that would indicate a missed file). Worth a dedicated
   Python whole-tree decode-scan pass in a future session per AGENTS.md
   §4.1's standing recommendation, especially against `doc/`/`adm/etc/`
   extensionless text.

## Fixes applied (driver-incompatibility bugs)

- **`log_error()` had NO warning-vs-error distinction at all** (the
  same worse variant already documented for `revive`, not the
  miscapitalized-check version in `zhyx`/`naruto`) -- `adm/obj/
  master.lpc`'s `log_error(file, message)` did
  `if(this_player(1)) efun::write("編譯時段錯誤﹕" + message+"\n");`
  unconditionally, with no substring check on `message` at all, so
  every ordinary lazy-compile warning (this driver calls the
  `log_error` master-apply for warnings too, not just real errors) was
  broadcast as a hard-error notice to whichever player happened to be
  connected. Fixed with the standard filter:
  ```lpc
  if(this_player(1) && strsrch(message, "Warning") == -1 && strsrch(message, "warning") == -1)
      efun::write("編譯時段錯誤﹕" + message+"\n");
  ```
- **§8.1 GBK/BIG5 byte-range `is_chinese()`, the length-gate variant**
  -- `adm/simul_efun/chinese.lpc`:
  ```lpc
  // BEFORE:
  int is_chinese(string str)
  {
      if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 ) return 1;
      return 0;
  }
  ```
  The `strlen(str)>=2` was meant to require "a full 2-byte BIG5 pair"
  under the original byte-oriented `strlen()`; under this driver's
  character-counted `strlen()` it instead rejects every 1-character
  string outright -- exactly the "length-gate variant" documented in
  AGENTS.md §8.1 (`dfgsiiv13b`'s precedent), which matters here because
  `check_legal_name()` (below) probes `is_chinese()` on single-character
  suffix slices. Fixed by dropping the length requirement and checking
  only the first character's codepoint:
  ```lpc
  int is_chinese(string str)
  {
      if( !strlen(str) ) return 0;
      if( str[0] >= 0x4e00 && str[0] <= 0x9fff ) return 1;
      return 0;
  }
  ```
- **`check_legal_name()`'s byte-calibrated length bound and sliding
  gate** -- `adm/daemons/logind.lpc`. The bound (`strlen(name) < 2 ||
  strlen(name) > 12`) contradicted its own error message ("必須是 1 到
  6 個中文字", i.e. 1 to 6 Chinese characters) by exactly the
  2-bytes-per-character factor; fixed to `< 1 || > 6`. The
  per-character loop additionally gated on `i%2==0` (a GBK/BIG5
  lead-byte-position skip) before calling `is_chinese(name[i..<0])` on
  each trailing suffix -- since `is_chinese()` now only inspects its
  first character, this gate needs to be dropped entirely so every
  character position is actually checked, not just every other one:
  ```lpc
  // BEFORE: if( i%2==0 && !is_chinese(name[i..<0]) ) { ... }
  // AFTER:  if( !is_chinese(name[i..<0]) ) { ... }
  ```
  This lineage has no separate `named.lpc` sharding daemon (unlike the
  yh2003/hell families), so the fix is fully contained to these two
  functions.
- **§7.1-class: `master.lpc`'s `valid_write()` calls
  `load_object(SECURITY_D)` unconditionally, no re-entrancy guard** --
  ```lpc
  // BEFORE:
  int valid_write( string file, mixed user, string func )
  {
      object ob;
      if( !catch(ob = load_object(SECURITY_D)) )
          return (int)ob->valid_write(file, user, func);
      return 0;
  }
  ```
  Every `valid_write` call re-attempts `load_object(SECURITY_D)` even
  after it's already resident, and has no guard against the
  compile-time re-entrancy trap this section of AGENTS.md documents
  extensively (a write happening while `securityd.lpc` itself is still
  mid-compile would recurse). `valid_read` in the same file already
  degrades correctly (`find_object` only, returns 1 if absent -- no fix
  needed there). Fixed with the standard reentrancy-flag pattern:
  ```lpc
  private nosave int loading_security_d;
  int valid_write( string file, mixed user, string func )
  {
      object ob;
      if (!(ob = find_object(SECURITY_D))) {
          if (loading_security_d) return 0;
          loading_security_d = 1;
          catch(ob = load_object(SECURITY_D));
          loading_security_d = 0;
      }
      if (ob) return (int)ob->valid_write(file, user, func);
      return 0;
  }
  ```
- **`message()`/`tell_room()`/`shout()` unconditional exclude argument**
  -- `adm/simul_efun/message.lpc` has no local override of the bare
  `message()` efun itself (unlike `zhyx`/`revive`'s instance of this
  bug), but `tell_room()`'s and `shout()`'s own call sites pass a
  falsy 4th argument (an unset `object *exclude` defaulting to `0`, and
  `this_player()` when it can legitimately be 0) straight through to
  the real `message()` efun on every ordinary call -- the same
  `void|object|object*` 4th-arg strictness already documented for this
  driver. Guarded both on truthiness:
  ```lpc
  if (exclude)
      message("tell_room", str, ob, exclude);
  else
      message("tell_room", str, ob);
  ...
  if (this_player())
      message("shout", str, users(), this_player());
  else
      message("shout", str, users());
  ```
- **SEVERE, new bug class: `adm/obj/master.lpc`'s `preload()` gated
  every preload attempt behind a hardcoded `.c` extension check.**
  ```lpc
  void preload(string file)
  {
      ...
      if (file_size(file + ".c") == -1)
          return;
      ...
      err = catch(call_other(file, "??"));
      ...
  }
  ```
  The driver calls this apply once per entry in `master::epilog()`'s
  returned preload list (confirmed by reading
  `~/src/fluffos/src/vm/internal/vm.cc`'s `preload_objects()` --
  `epilog()` returns the file list, the driver then calls
  `APPLY_PRELOAD` once per file). After this project's standard
  `.c`->`.lpc` rename, `file_size(file + ".c")` would return `-1` for
  every single entry -- meaning `securityd`, `virtuald`, `logind`,
  `cmd_d`, `chinesed`, `emoted`, `aliasd`, `fingerd`, `channeld`, and
  `natured` would ALL silently never preload, with zero error output
  (the function just returns early). This was **auto-fixed by
  `convert_lib.sh`'s own literal-`.c"`-reference sed pass**, since the
  extension appears as its own standalone string literal
  (`file_size(file + ".c")` -> `file_size(file + ".lpc")`) -- confirmed
  by direct inspection of the converted file before ever running
  `lpcc`, and then confirmed live: the real boot's preload list shows
  all ten daemons loading in order. Documented here in detail because
  had the sed fixer NOT caught this (e.g. on a future archive using a
  different quoting style), the failure mode would be maximally
  confusing: a driver that boots with `Initializations complete.` and
  accepts connections, but where literally nothing behind
  `logind`/`securityd`/etc. actually works.
- **SEVERE, same shape, much wider blast radius: `adm/simul_efun/
  object.lpc`'s `new_ob()` (the central NPC/item-spawning wrapper).**
  ```lpc
  object new_ob(string files)
  {
      ...
      if( sscanf(files, "%*s.c") != 1 ) files += ".c";
      if(strsrch(files,"..")==-1)
      {
          if(file_size(files)>0) return efun::new(files);
          else return 0;
      }
      ...
  }
  ```
  `new_ob()` is called from `adm/daemons/roomd.lpc`'s room-population
  code (the "objects" mapping every room's `create()` sets), plus
  60+ direct call sites across `std/`, `feature/`, `daemon/`, and
  dozens of `open/`/`u/` content files -- effectively every NPC/item
  spawn in the game goes through it. Callers pass extensionless paths
  (e.g. `new_ob("/open/world1/mob/sacer")`); `new_ob()`'s own logic
  appends a hardcoded `.c` when the path doesn't already end in one.
  After the `.c`->`.lpc` rename, `sscanf(files, "%*s.c")` never matches
  (a path ending in `.lpc` does not end in the literal 2 characters
  `.c`), so `.c` gets appended to EVERY call, producing a filename that
  no longer exists on disk -- `file_size()` then correctly reports "no
  such file" and `new_ob()` returns `0` for every single spawn,
  site-wide. **Also auto-fixed by `convert_lib.sh`'s literal-`.c"`
  sed** (the same string-literal-boundary reasoning as `preload()`
  above: `"%*s.c"` -> `"%*s.lpc"`, `files += ".c"` -> `files +=
  ".lpc"`), confirmed by direct inspection before the first `lpcc`
  run and then confirmed live via a fully populated starting room (an
  NPC "新手導師"/"店小二" both present, an in-room board with 578
  messages). The same hardcoded-`.c`-suffix shape recurred
  independently in `feature/skill.lpc`, `feature/spell.lpc`, `std/
  skill.lpc`, `std/char.lpc`, `std/room/bank.lpc`,
  `adm/daemons/{chard,combined,virtuald,idcheckd,newquestd,
  enhanced}.lpc`, and ~55 more files across `open/`/`u/` (mostly
  `file_size(X+".c")`-style existence probes analogous to the
  well-documented §7.5 "hy2002" ACL-shaped false-negative, except the
  root cause here is the literal extension mismatch, not an ACL) --
  all mechanically covered by the same sed pass; spot-checked several
  post-conversion (`feature/skill.lpc`, `feature/spell.lpc`,
  `adm/obj/master.lpc`) to confirm the fix landed correctly rather than
  assuming uniform coverage.
- **New robustness gap, same family as §7.25 (unguarded room-population
  `new()`/`move()`): `adm/daemons/roomd.lpc`'s `make_inventory()`/
  `reset_room()` had no catch() around a spawned object's own
  `create()`, and `reset_room()`'s single-instance branch treated a
  failed spawn as fatal.** `make_inventory()` called `new_ob(file)`
  directly with no `catch()`; if the spawned NPC/item's own `create()`
  throws an uncaught error (e.g. `feature/skill.lpc`'s `set_skill()`
  erroring "F_SKILL: 沒有此SKILL" for a skill file the archive doesn't
  ship -- see "Confirmed content gaps" below), that error propagates
  all the way up through `create()` -> `reset()` -> `reset_room()` ->
  `make_inventory()` and aborts the ENTIRE room's load -- not just the
  one missing NPC. Separately, `reset_room()`'s `case 1:` branch (the
  "exactly one of this object" population path) explicitly
  `error()`ed when the resulting object was still falsy after the
  `make_inventory()` call, while the `default:` (multi-instance) branch
  right below it already degrades gracefully (`continue`s past a
  missing slot). First caught live via the compile sweep: 237 distinct
  files failed to load with a `Fail to load object` wrapping a runtime
  error several frames deep inside some spawned child's own `create()`
  (missing skills, missing content, `AS_FEATURE` fragments never meant
  to load standalone -- see below). Fixed both narrowly, without
  fabricating any of the underlying missing content:
  ```lpc
  // make_inventory():
  catch(ob = new_ob(file));
  if( !objectp(ob) ) return 0;
  ...
  // reset_room()'s case 1: branch:
  if( !ob[list[i]] )
      log_file("ROOM_LOAD_FAIL", base_name(room)+": can't load object : "+list[i]+"\n");
  else if( ... ) { ... }
  ```
  Verified: `/open/world1/tmr/quanzhen/chufang` (a room whose "objects"
  mapping spawns an NPC that references the unshipped "xiantian-qigong"
  skill) now loads cleanly instead of failing outright; the same class
  of fix converts the bulk of the compile sweep's "Fail to load object"
  entries whose actual error is several frames deep in a spawned
  child's `create()` into "the room loads, one item/NPC is silently
  absent" -- a narrow content gap, not a driver crash.
- **Pre-existing (not conversion-introduced) authorial typo class: a
  stray backslash immediately before a string's closing quote**,
  confirmed present byte-for-byte in the raw BIG5 source (verified with
  a direct `iconv -f BIG5` decode of the exact raw bytes before
  trusting it wasn't a transcoding artifact) -- e.g. `set("cover_name",
  "鐵蓋\");` (a literal `\"` swallows the string's own closing quote,
  corrupting everything after it until the next real, unescaped quote
  in the file). Confirmed via the compile sweep's own "syntax error,
  unexpected L_IDENTIFIER" / "Illegal character 0xXX" cascades landing
  well past the actual defect line. This exact "鐵蓋\" (iron lid)"
  shape recurred in **13 separate box-item files** copy-pasted across
  `open/world1/{god_club,manto,ksj/thief,cominging/shengsan/aovandis}/`,
  `u/m/manto/`, and `example/` (the same template item cloned into many
  personal/area trees), plus 12 more one-off instances (`連詳馬廄\")`
  in `bhorse.lpc`, `輕功\")` in two copies of `fon.lpc`, `妖精之淚\")`
  in `treeking.lpc`, `罡\"HIC"」"` shared verbatim across 3 skill files
  `daemon/skill/{sevenstar-sword,sorsin_force,sorsin_force3}.lpc`, `餐
  \"NOR` shared across 4 copies of the "map" command
  (`cmds/{usr/map,usr/bigmap,imm/map2}.lpc`, `example/LukyOpenSrc/
  map.lpc`), and 5 further individually-diagnosed instances (`塑膠蓋`,
  `武功`, `一公升的眼淚`, `我最搖擺`, `野豹`/`豹`, `地窖鐵蓋` x2, `柔腸
  一寸愁千縷`) -- 25 files fixed by removing the stray backslash.
  Two further, structurally different one-off typos found the same
  way: `example/baalbug/item/ming_mark.lpc` was missing a closing quote
  entirely (`"風雷堂,"闇燄堂"` -> `"風雷堂","闇燄堂"`, a plain missing-
  comma-adjacent-quote typo, not the backslash shape) and
  `example/npc/chiang.lpc` had a corrupted `call_out("meet_eagle"t",
  3,me);` (a stray `t"` fragment, fixed to `call_out("meet_eagle",3,
  me);`). None of these 27 files are on the registration/starting-room
  path; found via the compile sweep, not live testing.

## Confirmed content gaps (NOT fixed, per project policy)

- **(Resolved 2026-10-27)** wizard "tmr"'s multi-zone questing area
  `#include <npc.h>` gap: header + `feature/npc/*` + Aug compat shims
  now ship (see Aug npc.h section below). Rooms that only failed
  because their NPCs could not load should load again; remaining
  content-level skill/feature gaps in those zones are unchanged.

- **`F_SKILL: No such skill` gaps** -- several NPCs (mostly in the
  `tmr` zones above, but not exclusively) `set_skill()` a skill name
  with no corresponding file under `daemon/skill/` (e.g.
  "xiantian-qigong" in `open/world1/tmr/quanzhen/npc/huogong.lpc`).
  Narrow, individually-diagnosed missing content, not fixed; no longer
  crashes the containing room thanks to the `make_inventory()` fix.
- **`std/weapon/_{hammer,needle,dagger,fork,whip,staff,blade,axe,
  sword}.lpc`** -- these `#define AS_FEATURE` then `#include` their
  non-underscore sibling (`hammer.lpc`, etc.), which under
  `AS_FEATURE` only `#include`s `<dbase.h>` (no `inherit EQUIP;`) --
  i.e. these files are meant to be `#include`d as a feature fragment
  into some OTHER class that already provides `weight()`/`setup()`/
  `set_durable()` via its own EQUIP inheritance, not loaded standalone.
  Confirmed dead as standalone objects: every `HAMMER`/`F_HAMMER`-style
  macro reference to these paths across the whole archive is inside a
  commented-out line in a handful of personal wizard sandbox files
  (`u/l/luky/npc/wp/*.lpc`, `u/f/faceoff/gun.lpc`). Fails the compile
  sweep's standalone-compile check (§10.4's documented false-positive
  category) but is never actually instantiated this way in live
  content; not fixed.
- **`doc/wiz/{人類,野獸}.lpc`** (and personal-sandbox copies
  `u/h/hack/{人類,野獸}.lpc`) -- documentation/example files under
  `doc/wiz/` that inherit `NPC` twice-over in a way that redefines
  several `nomask` functions (`query_busy`, `is_busy`, `is_block`,
  `command_hook`, `set_path`), plus a handful of personal-sandbox files
  with the same shape (`u/l/luky/lukylab{1,2}.lpc`, `u/m/mulder/area/
  road16.lpc`, `u/z/zorg/obj/darkhat.lpc`, `open/world1/uchimaha/bird/
  {bird20,bird21,bird23,bird24,bird25,bird26,en3,en4,en7,en8,
  en9}.lpc`) -- pre-existing authorial bugs in documentation/example
  and personal-sandbox content, not fixed.
- **"Bad argument 1 to EFUN call_other()"/"Bad argument 1 to
  wizardp()" batch-sweep artifacts** -- several dozen files' `create()`
  call `this_player()->query(...)` or similar unconditionally (e.g.
  `open/world1/moonhide/area/empty-god-prey.lpc`'s
  `random(this_player()->query("level")/3)`), which is `0` (no player)
  under `lpcc_check.sh`'s batch-compile context but would be a real
  player object in an actual live boot (a room/NPC created in response
  to a player entering). Per AGENTS.md §10.4, this is the standard
  "cross-check any lpcc-only failure against the real boot log before
  believing it" false-positive class; the live boot/registration test
  below never hit this. Not fixed (fixing it would mean guessing at
  fallback behavior for genuinely player-triggered content).

## Boot / registration verification

- `~/src/fluffos/build-debug/src/lpcc`, single-file: `adm/obj/master`
  and `adm/obj/simul_efun` (which `#include`s `atoi.lpc`, `chinese.lpc`,
  `file.lpc`, `gender.lpc`, `object.lpc`, `path.lpc`, `wizard.lpc`,
  `overrides.lpc`, `message.lpc`) both confirmed clean before ever
  running a full batch sweep. A scoped `--batch` run over all 56
  `feature/*.lpc` + `std/*.lpc` files (the widest-reaching base
  classes) passed 56/56 on the first attempt.
- Full `lpcc_check.sh` batch sweep, run **twice** (once before and once
  after the fixes above): first pass peaked at ~5.1GB RSS (well under
  the 10GB safety threshold, monitored every 15-20s throughout per this
  project's RAM-safety discipline), completed in a few minutes;
  **28,734/29,831 = 96.3%** pass. After fixing the 27 stray-backslash/
  typo files and the `make_inventory()`/`reset_room()` guard, a second
  full sweep (~5GB peak again) improved to **28,795/29,831 = 96.5%**
  pass, 1,036 failures remaining -- of which **275 collapse to the
  single shared `tmr/npc.h` gap** above, and the large majority of the
  rest cascade from that same gap (rooms/items in those same ~15
  sub-areas referencing the broken NPCs) or from the `AS_FEATURE`
  standalone-compile artifacts and batch-sweep `this_player()`-is-0
  false positives documented above. None of the remaining failures are
  on the registration/starting-room path actually exercised below.
- Real `build-debug` driver boot on port 40240: clean both times
  (before and after moving aside a corrupt legacy save, see below),
  zero fatal `debug.log` errors, only the two expected benign compile
  warnings (a stray-backslash-before-Chinese-text "Unknown escape
  sequence" warning in `logind.lpc`/`fingerd.lpc` -- see "Not fixed"
  below -- and one "Unused local variable" in `channeld.lpc`), both
  correctly routed to the log only, never shown to a connecting player,
  confirming the `log_error()` fix.
- **One corrupt legacy save moved aside**: `data/chinese.o` (the
  `chinesed.lpc` translation-dictionary cache) failed to `restore()`
  with "Illegal mapping format while restoring dict" on every boot --
  caught by `chinesed.lpc`'s own `create()`/`restore()` chain (no
  crash, `chinesed` just starts with an empty dictionary), but per the
  §7.7 "move the corrupt save aside" convention, relocated to
  `data/_pre_conversion_incompatible_saves/chinese.o.pre-conversion`
  so the boot log is fully clean rather than showing a caught-but-
  visible error on every single restart.
- Full registration flow verified via a purpose-built raw Python
  socket script (telnet IAC-stripping, one line sent at a time with a
  short wait, matching this project's documented "one `--send` at a
  time when a flow behaves confusingly" rule -- `mudclient.py`'s
  multi-send-per-connection mode raced ahead of this lineage's
  synchronous-but-strict prompt validation on the first attempt, not a
  server-side bug: every early input was simply an invalid English id
  attempt, e.g. containing a digit or too short, and each got its own
  correct rejection + re-prompt in order): id/Chinese name `qinfeng`/
  秦風, password `Mud2026pw`, race `human`, gender `m` -- reached the
  actual starting room "朝天樓" ("Chaotian Tower", an inn near the
  fictional "朝天湖"/Chaotian Lake, 2 NPCs present -- 新手導師/Master,
  店小二/Waiter -- plus a 578-message board), `look` correctly
  re-displaying it, `score` returning a fully-formatted character
  sheet (level 1, race human, gender 男性, base stats, HP/MP/AP,
  777 starting exp matching `init_new_player()`'s hardcoded value), and
  `quit` cleanly returning "～～ 辛苦了! 休息一下吧 ～～". A second,
  independent run verified the **restore path** (a distinct code path
  from registration, per AGENTS.md §10.1): reconnecting with the same
  id/password after a clean quit restored the same character into the
  same room with no re-registration prompt.
- Admin account seeded: id `fluffos`, password `Mud@2026`, display name
  浮浮 (surname skipped with a bare newline is N/A for this lineage --
  registration only asks for one combined Chinese name, not a
  surname/given-name split; `浮浮` given directly). Granted `(admin)`
  via `fluffos (admin)` appended to `adm/etc/wizlist` (the same
  plain-text `wiz_name status` format as the existing `whoami
  (immortal)`/`mudren (admin)`/`acme (admin)` entries), verified after
  a driver restart: `fluffos`/`Mud@2026` login succeeds, the room
  display gains the wizard-only `/open/world1/tmr/area/hotel` path
  suffix and the command prompt changes from `>` to `/>`, confirming
  `(admin)` status is live; `quit` clean.
- Save files for the orchestrator to add (not gitignored, normal add):
  `libs/dreamofseven/work/data/user/f/fluffos.o`,
  `libs/dreamofseven/work/data/login/f/fluffos.o`. The throwaway test
  character's save data (`qinfeng`, one id used across both the
  registration and restore-path tests) was deleted before finishing,
  per convention.
- **Outbound network check (per task step 6): no live side effect
  observed.** `adm/etc/preload` already has `dns_master`/`ftpd`
  commented out by the original author (with a comment noting Windows-
  MudOS compatibility). Two live-network-capable daemons exist in the
  source but were confirmed unreachable from preload or from the
  registration/gameplay path actually exercised: `adm/daemons/
  dictd.lpc` (hardcodes a `socket_connect` to a real external IP,
  `211.20.181.29 80`, for an online-dictionary lookup feature) is only
  referenced from two personal wizard sandbox test files
  (`u/c/cominging/test/testa.lpc`, `u/k/kkeenn/obj/query.lpc`), neither
  reachable in normal play; `adm/daemons/userid.lpc` (an ident/RFC1413
  lookup on port 113) has no live callers anywhere in the tree. No
  `socket_create`/`socket_connect`/`socket_bind` calls appeared in
  `debug.log` during either boot or the full registration+restore
  test session. This lib is safe to include in ordinary automated
  reboot loops, unlike `zhyx`/`revive`'s documented live-network
  exceptions.

## Not run this session

- **Whole-tree Python UTF-8-decode straggler sweep** (AGENTS.md §4.1,
  beyond `convert_lib.sh`'s own extension-based scan) -- not run this
  session given the archive's size and the absence of any symptom
  (garbled banner/help text, `file(1)` false positives) during
  boot/registration testing; worth a dedicated pass in a future
  session, particularly against `doc/`/`adm/etc/` extensionless files
  per this project's own repeated precedent of finding un-transcoded
  help/banner text there on other libs.
- **LPC formatter (§9)**: not run against the edits above. Every edit
  this session was small (a handful of lines each, or a single
  character removed) and manually reviewed against the surrounding
  code's own indentation/brace style.
- **Full deep §10.7-style playthrough / WASM pass**: out of scope for
  this onboarding session per the task brief (native boot +
  registration + restore-path verification only). The `tmr` zone's
  `npc.h` gap and the various content-level skill/feature gaps
  documented above are worth a wider sweep in any future deep-testing
  pass on this lib, now that a missing spawn safely degrades instead
  of crashing the containing room.

## 深度功能測試（§10.7 round two, 2026-08-27）

One continuous session with a fresh Chinese-named character (`shenzhi`
/ 沈知, human, male), following `doc/help/newbie/newbie1`'s own
described test path (free-drink refill points, `slist`/`train`/
`advance`/`level` for skills, the "master" sect-teacher alias route).
Two real programming bugs found and fixed live; one design-shaped
finding documented but left untouched; the seven standing
cross-cutting patterns (§7.121/§8.3a/§7.122/§7.123/§7.124/§7.126/
§7.128) checked systematically, one confirmed hit (§7.126, new
variant, also added to that AGENTS.md entry's "confirmed instances").

### Bug 1 (fixed): `printf("%O", ob)` debug leftover leaked a raw object reference to every new player during registration

`adm/daemons/logind.lpc`'s `get_name()` (the Chinese-name-acceptance
handler, called for every single character creation) had a stray
`printf("%O\n", ob);` immediately after validating the name — present
byte-for-byte in the raw pre-conversion archive (`raw/ds/ds/adm/
daemons/logind.c:435`), so this is a pre-existing authorial debug
leftover, not a conversion artifact. Reproduced live: right after
typing a Chinese name, the client received a literal `/obj/login#4`
line before the password prompt — meaningless and slightly alarming
internal-object-reference noise shown to every brand-new player,
serving no game purpose. Fixed by deleting the one line; verified live
that the password prompt now follows immediately with no extraneous
output.

### Bug 2 (fixed, SEVERE): starting room's `newbie` exit was unreachable for every real player due to an operator-precedence typo

`open/world1/tmr/area/hotel.lpc`'s `valid_leave()`:
```lpc
// BEFORE:
if( dir=="newbie" || dir=="bug" && !userp(me))
        return notify_fail("那裡只有玩家才能進去。\n");
```
`&&` binds tighter than `||` on this driver (standard C-family
precedence), so this parses as `dir=="newbie" || (dir=="bug" &&
!userp(me))` — meaning the `newbie` branch is **blocked
unconditionally, for every player and every NPC alike**, regardless of
`userp(me)`, while the clearly-intended logic (per the very next line's
own `dir=="newbie"` branch, and per two sibling files in this same
archive that implement the identical "only real players may use this
exit" gate) was `(dir=="newbie" || dir=="bug") && !userp(me)` — block
only non-player wanderers, let real players through. Confirmed via
`grep -rn 'dir==.*||.*dir==.*&&.*userp'`: `u/s/suez/port/port_21.lpc`
and `u/s/suez/port/port_06.lpc` both correctly parenthesize the same
shape (`(dir=="east"||dir=="south") && !userp(me)`), making this an
isolated authorial typo on this one file, not a lineage-wide pattern.

Reproduced live: a brand-new player at the starting room 朝天樓 typing
`newbie` got **zero output and no movement** (see Bug 3/observation
below for why the failure was silent rather than showing the
"only players may enter" message) — the entire tutorial "新手教室"
room (two teaching books plus a help sign, the ONLY place `doc/help/
newbie/newbie1` tells brand-new players to start) was completely
unreachable for every player, from this codebase's first-ever
character onward. Fixed by adding the missing parentheses; verified
live post-fix: a real (non-wizard) test character typing `newbie` from
朝天樓 now correctly moves to `open/world1/tmr/area/school/school1`
("新手教室") and can read both books.

### Observation (NOT fixed, authorial pre-existing design choice): `cmds/std/go.lpc` discards every blocked exit's `notify_fail()` message

Both `stringp(dest)` and `objectp(dest)` branches of `go.lpc`'s `main()`
do:
```lpc
if( !env->valid_leave(me, arg) ) return 1; // alick return 0->1
```
On this (and any standard LPC-family) driver, an `add_action`-registered
handler returning a nonzero int tells the driver "handled, don't show
the stored `notify_fail()` message" — so every `valid_leave()` rejection
anywhere in this entire codebase (walls, locked doors, the
newbie/bug-only gate above, sect-specific area gates, etc.) fails
completely silently: no movement, no error text, nothing. Confirmed
present byte-for-byte in the raw pre-conversion archive
(`raw/ds/ds/cmds/std/go.c:104,118`, same `// alick return 0->1` comment)
— a deliberate, already-commented authorial change from the more usual
`return 0`, not a conversion regression. Left untouched per this
project's scope boundary: a plausible reason for the trade-off exists
(preventing the driver's `safe_parse_command()` fallback from re-trying
OTHER handlers registered under the same direction-word verb after a
blocked move — a `return 0` would fall through to those instead of
stopping cleanly), and reversing it site-wide would be a broad,
speculative behavioral change with no way to verify it doesn't break
something else this large archive relies on. Documented here as an
honest observation per the "when unsure, document and leave it" rule,
not fixed.

### Seven standing cross-cutting patterns — one confirmed hit (§7.126), six clean

- **§7.121** (float arithmetic in a declared-`int` function): checked
  `adm/daemons/bankd.lpc` (the only real economy/exchange-rate daemon),
  `cmds/usr/exchange.lpc`, and did a repo-wide grep for
  `IDENT = 0\.[0-9]+;` assigned to money/exp/rate-shaped fields — no
  hits. `bankd.lpc`'s own interest-rate math (`bank_amount["past"] *
  ratio / 100`) is pure integer arithmetic throughout (and is dead code
  besides — `clockd.lpc`'s call to `interest_receive()` has been
  commented out by the original author since before conversion). Clean.
- **§8.3a** (`private`-declared dispatch/callback function demoted on
  inherit): the central dispatcher (`feature/command.lpc`'s
  `command_hook`) is declared `protected nomask`, not `private nomask`
  — `protected` is not subject to the DECL_HIDDEN-on-inherit demotion
  this pattern describes, so no bug. A repo-wide grep for `private
  nomask` (or bare `private` in `feature/`/`std/`/`adm/daemons/`) found
  only `adm/daemons/network/socket.lpc`'s five callback functions,
  which are self-referential closures bound within that same
  never-inherited file — not at risk. Clean.
- **§7.122** (TMI-2-style autoload item duplication): grepped for
  `compute_autoload_array`/`destroy_autoload_obj`/`load_autoload_obj`
  — zero hits anywhere in the tree. This ES2/Annihilator-lineage
  codebase doesn't use that mechanism at all (its `set("auto_load",
  1)`-style per-item flag, seen on `std/equip.lpc` etc., is the
  ordinary driver-level auto-clone-on-login convention, a different and
  unrelated mechanism). Not applicable.
- **§7.123** (bare file-scope `IDENT = (...)`  statement): grepped for
  `^IDENT = (` patterns repo-wide; every hit (`obj/cch.lpc`,
  `u/w/whoami/red-envelope.lpc`, `u/w/whoami/Qoldman.lpc`, several
  `u/l/luky/pearl/pearl_*.lpc` files, a handful of unindented
  `damage=(...)` lines) was hand-verified to sit inside a real function
  body (this codebase frequently doesn't indent function-body code),
  none at true file scope. Clean.
- **§7.124** (0.0-1.0 fraction where an int 0-100 percentage was meant):
  checked the `wimpy` auto-flee threshold end-to-end (`std/char.lpc`,
  `cmds/std/wimpy.lpc`, and every NPC `set("wimpy", N)` call site) —
  all integers, all consistent, no fractional literal anywhere. No
  other percentage/threshold field with a suspicious `= 0\.NN;`
  assignment turned up in a repo-wide grep. Clean.
- **§7.126** (stale `.c` extension in `.o` save data feeding
  `load_object()`): **CONFIRMED, FIXED** — see "New bug class" below
  (a new variant of this existing AGENTS.md entry; the entry itself has
  been extended with this instance rather than adding a new number).
- **§7.128** (`process_input()` returning a string when the lib never
  really uses `add_action`): `feature/alias.lpc`'s `process_input()`
  does return a string (alias-expanded or raw), but this codebase DOES
  register real verbs via the driver's native `add_action()`
  (`feature/command.lpc`'s `add_action("command_hook", "", 1)` plus
  every individual `cmds/*/*.lpc` file) — this is the CORRECT, intended
  contract for a lib built around `add_action`, not the anti-pattern
  §7.128 describes (which only bites a lib that bypasses `add_action`
  entirely). Confirmed no stray "什麼？"-after-every-command artifact
  during the whole live session. Clean/not applicable.
- **Residual `file_size(...+".c")`/filename-slice sweep**: repeated the
  onboarding-session's search post-fix — zero remaining hits anywhere
  in the tree (the only remaining literal `".c"` string in any `.lpc`
  file is inside our own new `resolve_location()` helper below).

### New bug class confirmed (extends existing AGENTS.md §7.126, no new number): `adm/daemons/bankd.lpc`'s club "location" field

Two of this lib's four shipped club-bank save files (`data/club_bank/
god.o`, `data/club_bank/dragon.o`) store their physical bank-room path
with the stale pre-conversion `.c` extension baked in
(`"location":"/open/world1/god_club/bank.c"`), while the other two
("moon", "sky") were already extensionless in the raw archive and are
unaffected — proof the field is meant to be extensionless. `bankd.lpc`
reads this value straight into `load_object(dbase["location"])->
create()` in two places: `clear_data()` (reachable live via a player's
own `clear <deposit|withdraw>` command in `std/room/club_bank.lpc`,
AND automatically whenever `do_save()`'s bank-log string grows past
1200 characters during ordinary deposit/withdraw activity) and the
disabled `interest_receive()`. For the "god"/"dragon" clubs this would
throw ("Applying a function… on a destructed or non-object") the very
next time either path fires. Fixed with a small helper mirroring the
project's standard §7.126 fix shape:
```lpc
string resolve_location(string dir)
{
        if( stringp(dir) && strlen(dir) > 2 && dir[strlen(dir)-2..] == ".c" )
                dir = dir[0..strlen(dir)-3];
        return dir;
}
```
...used at both `load_object(dbase["location"])` call sites. See
AGENTS.md §7.126's now-extended entry for the general lesson (a plain
literal path stored in save-file `dbase` data is just as susceptible
as a macro-placeholder AREA-engine value — the mechanism differs but
the root cause and fix shape are identical).

### Sect join, skill training, combat — all verified clean

- **Sect join** (organic path only; no separate admin shortcut command
  exists in this codebase): 李書文 (`open/world1/tmr/area/s_house.lpc`,
  the 八極門 sect teacher) requires `join 八極門` → `speak 劈掛參八極，
  英雄歎莫及` (a password phrase carved into the room's own wall
  plaque, discoverable via `look`) → `join 八極門` again. Verified live
  end-to-end on the admin test account: `score`'s title correctly
  changed from `【 大 神 】` to `八極門第七代俠客`, matching
  `create_family("八極門",7,"俠客")`.
- **Skill training**: `slist`/`train <skill>`/`level`/`advance <stat>`
  all verified live and correctly reflected in subsequent `slist`/
  `score` output (no float-display corruption, no silent no-op).
- **Combat**: `kill` on a low-level "peaceful"-attitude wild NPC
  (旅客/Traveler at 朝天湖, whose own `accept_fight()` unconditionally
  refuses a formal duel but does not block a direct `kill`, matching
  this project's well-documented cross-lib `kill`-bypasses-safety-gate
  finding) produced normal two-way damage, several live skill-ups
  (`unarmed`/`dodge`/`combat`), and a clean NPC death with a corpse
  object — no crash, no `debug.log` signal. No lib-specific safe-spar
  mechanism (dummy/strawman) was found to exist in this codebase
  (grepped for one before falling back to a wild NPC, per methodology
  step 3). Player-death/resurrection was not reached live this session
  (budget); left as an explicit gap rather than silently skipped.

### Quit / relogin persistence — verified clean, with a methodology note

A real `quit` → reconnect cycle (character `shenzhi`, `train sword` →
`slist` confirms level 1 → `quit` → reconnect on the SAME driver
process → `slist` still shows level 1) confirms save/restore across a
genuine quit is correct. `debug.log` grepped after every single `quit`
throughout the whole session (registration, sect join, skill training,
combat, multiple reconnects): **zero fatal errors, zero "Fail to load
object", zero uncaught-error traces** — only the pre-existing benign
lazy-compile warnings already noted at onboarding (stray-backslash
`\` escape-sequence warnings, one unused-variable warning).

Room position is intentionally reset to `START_ROOM_PAST`
(`/open/world1/tmr/area/hotel`, `include/login.h`) on every `quit`
regardless of where the player currently is (`cmds/std/quit.lpc`'s
unconditional `me->set("startroom", START_ROOM_PAST)`) — confirmed
this is deliberate, pre-existing design (an "always return to the inn"
convention), not a bug, since the very same file also independently
calls `me->save()` correctly.

**Methodology note for future sessions on this lib (or any lib)**: a
mid-playtest driver restart (needed here to pick up the two live-coded
fixes above) destroys any in-memory progress made since the character's
last real `save()`/`quit` — this produced a confusing false alarm
mid-session (a trained skill appeared to have been silently wiped by
`quit`+relogin) that was fully explained by the driver restart having
happened *between* the training and the eventual clean quit, not by
any bug in the save/restore path itself. Confirmed by re-running the
exact same train→quit→relogin sequence with no restart in between,
which persisted correctly. Always redo a clean, no-restart-in-between
save/quit/relogin cycle before trusting a persistence verdict if a
driver restart happened anywhere in the preceding session.

### Confirmed content gap (NOT fixed, per project policy)

- `doc/help/newbie/newbie1` explicitly tells new players to run `help
  start_1` for sect explanations ("關於門派，請參考help start_1"), but
  no such help topic exists anywhere in the archive (`help start_1`
  returns "沒有針對這項主題的說明文件。"; `find doc/help -iname
  '*start_1*'` returns nothing). Pre-existing upstream documentation
  gap, not a conversion artifact (the raw archive has no such file
  either); not fabricated.

### Test/verification housekeeping

- Test character `shenzhi`/沈知 fully deleted (`data/user/s/
  shenzhi.o`, `data/login/s/shenzhi.o`) before finishing.
- Admin account `fluffos`/`Mud@2026` picked up incidental state during
  the sect-join/combat speed-tests above (used as the fast-travel
  account via `goto`, since walking the ~35-step alias path to the
  sect teacher was impractical within budget) — re-seeded fresh
  (deleted and re-registered) to restore the clean baseline documented
  at onboarding: level 1, 777 exp, no `class1`, human/male, `(admin)`
  wizlist status reverified live post-reseed.
- `libs/dreamofseven/work/data/record.o` and `.../data/usrlist` show
  routine boot-churn diffs (uptime/cmds-per-second display caches) from
  the several reboots this session required; committed alongside, no
  action needed (matches this project's standard save-churn precedent).

## 商店付费购买（2026-09-04 librarian shop slice）

拜师（八極門 / 李書文）已在 2026-08-27 深度测试中 live 验证，本轮不重做。

起始房间朝天樓的店小二 (`open/world1/tmr/area/npc/waiter.lpc`，继承
`SELLMAN`) `list` 给出真实标价清单：馒头 10、水袋 20、鸡汤 40、火把 10
等。货币是 world1 实物 `past_money`（`/obj/money/coin.lpc` 古幣），不是
整数钱包；`buy` 另外扣 `supply_point`（馒头这一档扣 8 点，见
`sell_list` 的 mapping value）。新号 `supply_point` 默认为 0，心跳里
`feature/damage.lpc` 才会慢慢补到 `level*20+40`。

Admin `fluffos`/`Mud@2026` 进房后（隐形问 n）：
`eval this_player()->set("supply_point", 60)` 与
`eval this_player()->receive_money(100)` 各成功一次（`eval` 需要
`/u/f/fluffos/` 工作目录存在，本机临时建了空目录，不入库）。
`i` 见到「一百枚古幣」。`buy manto` live 回「你花了10枚古幣向店小二買了
一個饅頭」，随后 `i` 为九十枚古幣 + 饅頭(Manto)
`/open/world1/tmr/area/npc/obj/manto`。没有崩溃，没有「钱不够」误报。
`log/debug.log` 是本次开机（2026-09-04 14:20）的 live 档，只有既有的
反斜杠 warning，没有 fatal。

## Upstream check: `zwshen/mudos-game-ds` (2026-09-04)

MudRen's copy is a fork of `https://github.com/zwshen/mudos-game-ds`
(the original). Compared our snapshot commit `07ea84ebdff5` to zwshen
`master`: zwshen is **1 commit ahead**, and that commit only adds
`ds/GEMINI.md`. No mudlib source change. Do not re-onboard.

## 深度功能测试（§10.7，2026-10-04）— negative range ends

`scripts/lpc_fix_negative_ranges.py`: 5 line(s) in 2 file(s) count a range from the end with `<` (`x[a..-1]` -> `x[a..<1]`, `x[-2..]` -> `x[<2..]`; KB 06 §7.209). In this driver a negative constant end gave `""` / `({ })` and a negative start the whole value, so each of these returned the wrong slice; the compile warning `A negative constant as the second element of arr[x..y]` is gone from the files that compile. Range lvalues (`s[0..-1] = text`, the prepend idiom) are left alone. A paired compile of the changed files at HEAD and in the working tree showed no new error.

## 深度功能测试（§10.7，2026-10-04）— stray backslash before a closing quote

A Big5 character whose second byte is 0x5C was written with one extra backslash after it (the old driver read `5C 5C` as one backslash and so completed the character) and the UTF-8 conversion kept it (KB 03 §4.4). Before a closing quote it escapes the quote, the string runs into the next line and the file does not compile. `scripts/lpc_fix_big5_quote_backslash.py` deletes it when the character before it encodes to cp950 with 0x5C as second byte and the quote ends an expression. Here: `open/world1/tmr/quanzhen/npc/yunbao.lpc` and `open/world1/npc/god_leopard.lpc` (`set_name("…豹\", …)`), `u/s/sdo/pwest/npc/obj/tearofelf.lpc`, and the two `backup/15.lpc` quiz files (`string ans = "…枯\";`). All five load now (HEAD: none).

## 深度功能测试（§10.7，2026-10-05）— here-document terminators

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 10 here-document block(s) repaired (5 with the terminator glued to the last text line, 5 with it indented), so `End of file in text block` no longer hides the room or object behind them: `daemon/skill/moon_force.2000.5.15.lpc`, `daemon/skill/moon_force2.lpc`, `u/m/matlab/area/r5.lpc`, `u/j/jsh/area2/under/npc/obj/eouwang-woojin.lpc`, `u/j/jsh/underground/kingroom.lpc`, `u/j/jsh/underground/test.lpc` and 4 more. The terminator must start its line (the lexer's own test, KB 04 §6.10); a glued one lost its newline in the GBK -> UTF-8 conversion together with a half character, which stays out.

## 深度功能测试（§10.7，2026-10-05）— here-document terminators (opener line, case)

`scripts/lpc_fix_heredoc_terminator.py --all --apply`: 5 more block(s) repaired: 4 with the terminator spelled in another case than the opener (`@MING_PART ... MING_part`: the lexer compares case-sensitively, so the block never ended); 1 where the text sits on the opener's line (`@LONG   text...LONG`, the newlines were lost): `u/b/baal/backup/ming_mark.lpc`, `u/b/baal/ming_clan/ming_mark.lpc`, `u/b/baal/ming_clan/item/ming_mark.lpc`, `u/s/sexking/bear_cloth.lpc`, `u/h/hack/aaa.lpc`.

## 深度功能测试（§10.7，2026-10-04）— paths named in another case

The archive comes from a case-insensitive host: files are stored as `BAGUA0.lpc`, `longjing.C`, `d/SHAOLIN/`, the code names them in lower
case (`__DIR__ "bagua0"`, `"tea/longjing"`, `"/d/shaolin/..."`), so the rooms, NPCs and items behind them could not be loaded (a `.C` file is
not an `.lpc` file; KB 03 §4.5). `scripts/lpc_case_paths.py --convert --apply dreamofseven`: 3 file(s) renamed to lower case (`.C` -> `.lpc`,
`.H` -> `.h`) and 0 path reference(s) in 0 file(s) rewritten to the new spelling; 0 skipped, 0 ambiguous. Load check of the 4 objects that were renamed, edited or name a renamed path (HEAD against the working tree, an object is the same under any spelling of its path): 1 PASS -> 4 PASS, 0 that loaded before fail now, 3 more load.

3 files moved (3 `.C`); mostly under `u/t/truewind` (3). A rescan with `scripts/lpc_warnings.py dreamofseven` is still due: the renamed files are compiled for the first time.

## 深度功能测试（§10.7，2026-10-08）— 编译警告整理

`scripts/lpc_warnings.py dreamofseven --fix` 加 `scripts/lpc_fix_no_effect.py --apply`，共改动 2018 个 `.lpc`（多为删去未用的局部变量）。HEAD 与工作树分别加载（新进程）：1918 -> 1918 通过，无回退。启动时警告 3 -> 0；新进程登录（输入名字）正常。

## 深度功能测试（§10.7，2026-10-08）— `.lpc` 后缀的定宽切片

`.c` 改名 `.lpc` 时只改了字符串没改切片宽度：`f[<2..] == ".lpc"` 拿两个字符比四个字符，永远不成立（`!=` 永远成立），按后缀筛文件、去后缀的代码因此从不运行或截成 `x.l`（KB 06 §7.238）。`scripts/lpc_lpc_suffix_slice.py --apply` 改了 1 处比较、0 处去后缀（如 `adm/daemons/httpd.lpc`）；改动的文件 HEAD 与工作树分别加载（新进程），无回退。

- 2026-10-10：仓库顶层 `.gitignore` 的 `libs/*/work/**/log` 本为运行日志而设，却把存档里名为 `log` 的源码目录也挡在版本库外（站点下载缺这些文件）：`u/a/alickyuen/www/board/log/`（1 个文件）。已 `git add -f`（KB 02 §2.2）。

- 2026-10-11：编译警告第二轮（按驱动报告逐条修）：按位 & 改逻辑运算 0 处，返回类型/原型 5 处，NPC+F_UNIQUE 的 init() 0 个，带初始化的未用局部变量 1 个，只在 #if 分支用的声明移进分支 0 个文件；改动 6 个文件，HEAD 与工作树各载入一次无回退（6 objects; HEAD PASS 5, tree PASS 5; regress 0; newly loading 0），这些文件的警告 6 -> 0。

## 深度功能测试（§10.7，2026-10-11）：“无副作用表达式”警告复查

- 14 个 NPC（`open/world1/faceoff/bird/npc/prayer.lpc`、`woodguard.lpc` 及 `u/` 下的同类拷贝）：`set("chat_chance_combat", N);` 下一行只剩 `(:command,"say …":),`，`set("chat_msg_combat", ({` 外壳丢了，逗号把函数并进 `setup()`，战斗喊话从不出现；补回外壳（`garrison_1`/`guard_2` 是 `chat_msg`）。
- `adm/daemons/event/tidy.lpc`：`"…十分壯觀。\n";NOR;` 分号把 `NOR` 隔成独立语句，颜色不复位；改为 `"…" NOR;`。
- `std/item/box_log.lpc`：`else HIR"BOX_LOG 錯誤…";` 少了 `str +=`，错误提示从不显示；补上并加 `NOR`。
- `u/f/faceoff/skills/godvenison.lpc`、`u/a/acme/skill/test.lpc`：`target==me;` 应为 `target = me;`。`u/j/jsh/play/test.lpc` `(: command("hmm"):);`、`u/t/tmr/eval.tmr.lpc` `time;` 同类，一并改正；`u/a/alickyuen/www/obj/backup/mary.lpc` 的 `"無";` 改为 `ip = "無";`，空的 `"";` 分支改为 `{}`。
- 21 个对象 HEAD 与工作区都能载入，无回退。

- 2026-10-14：新驱动（FluffOS 970d9f09）报 `Float value truncated to int`（#1426）。8 个文件 11 处：赋值、初始化、return 改写成 `to_int(...)`（值不变，只是写明截断）。改动的对象新进程各载入一次，无回退（`scripts/lpc_fix_float_trunc.py`，KB 04 §6.10）。
- 2026-10-14：同一次重扫的其余 64 条（多在巫师目录 `/u/`、`/open/`）：
  - naboo 区 6 个 NPC 的 `chat_msg` 写成 `(: "random_move" :)`，在本驱动里只是返回字符串，NPC 从不走动；改为 `(: random_move :)`。
  - `u/s/suez/skills/handing-dagger.lpc` 把公式分四行写成四个 `int h` 全局变量，每一步读到的是新变量的 0，伤害加成从未按注释里的公式算；合成一个 `h`。
  - `include/marry.h` 的 `擺\設` 是 BIG5 0x5C 转码遗留（KB 03），去掉多余的 `\`。
  - 剑类 `attack()` 写成 `int`（基类 `void`，没有调用者用返回值）改 `void`。
  - 重复声明：`mapmaker2` 自己的灯光开关 `light` 与 `feature/move.lpc` 同名，改 `room_light`；两个 roommaker 的第一张 `special_props` 表、`meo_chung` 的第一个 `int x`、`clockd` 的第二个 `current_week`、银行房间没用到的 `mapping info` 都是死声明，删去。
  - `yelvqi` 与 6 个 `F_CLEAN_UP` 文件在基类已有的情况下又继承一次，删掉多余的继承；其余跨文件同名函数写明胜出者（行为不变）；`NOR`、`LUKY` 宏重定义前加 `#undef`；`pot.lpc` 多余的 `;`。
  - 改动及受影响的 444 个对象新进程各载入一次：438 -> 438，无回退。

- 2026-10-14：`data/ip_d.o`（网咖管理器的存档）还是原档案的 BIG5 编码，没有转成 UTF-8，`restore_object()` 报 `Invalid utf8 string` 后以空数据启动；`scripts/lpc_save_encoding.py` 按 BIG5 转码，结果按存档格式解析通过才写回（KB 03 §4）。`data/board/` 下 5 个留言板存档按任何编码都解析不了，未动。
- 2026-10-14（续）：留言板存档里有 BBS 彩色字，彩色控制码夹在一个双字节字的两个字节中间（前字节、`ESC[1m`、后字节），另外有被截断的半个字，所以整份文件按任何编码都解不开，留言板一直是空的。`scripts/lpc_save_encoding.py` 先把控制码挪到字后面、丢掉孤立的前字节，再按本库的编码转成 UTF-8，结果按存档格式解析通过才写回。

- 2026-10-14：1 个文件因 `Illegal to inherit after defining global variables` 整份不编译：FluffOS 要求所有 `inherit` 写在第一个全局变量之前，MudOS 不管。`scripts/lpc_fix_inherit_order.py` 把写在 `inherit` 之前的全局变量（以及声明全局变量的头文件的 `#include`）挪到最后一个 `inherit` 之后（KB 04 §6.3）。

- 2026-10-14：9 个文件因 `Type of returned value doesn't match function return type ( int vs void )` 整份不编译：声明为 `void`（或没写类型）的函数却返回值，旧驱动照样把值交给调用者。调用者要用返回值的（add_action 处理函数、命令、辅助函数）改为它实际返回的类型：`attempt_apprentice()`、`cover()`、`do_back()`、`do_change()`、`get_paper()`、`is_fighting()`、`relay_say()`。新进程比对 HEAD 与工作树：12 个对象，新增载入 10，回退 0（`scripts/lpc_fix_void_return.py`，KB 04 §6.3）。

- 2026-10-14：2 个文件把 `array` 单独当类型用（`array names;`），本驱动当成普通名字，报 `Illegal lvalue` 整份不编译；改为 `mixed *`，每个声明都带星号（`scripts/lpc_fix_array_type.py`）（KB 04 §6.1、§6.3）。新编译出来的文件露出的警告一并清掉（删去未用局部变量，有返回值函数里的空 `return;` 改为 `return 0;`）。新进程比对 HEAD 与工作树：12 个对象，新增载入 10，回退 0。

## 存档读不出来：BIG5/GBK 0x5C 字后的反斜杠（2026-10-15，KB 03 §4.4）

`/data/board/bug_b.o`、`/data/board/jail_board.o`、`/data/board/moon_room6_b.o`、`/data/board/past_b.o`、`/data/board/tmr_b.o`、`/data/board/tmr_future_b.o`、`/u/l/linjack/past_b.o`：第二字节为 0x5C 的字（功、许、么、俞、賊……）MudOS 存档时写成 `\\`，转成 GB 后字保留，多出的一个反斜杠转义了后面的引号（`成功\",` 字符串收不了尾），或反过来，MudOS 当作被 0x5C 转义的引号成了字符串的结尾（`出\"俞" >`）。`restore_object()` 报 `Illegal mapping format`，留言板等从空白开始。在出错处去掉或补上这一个反斜杠，直到能读回（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回。

## 存档读不出来：字符串里的换行、空行（2026-10-15，KB 03 §4.4）

`data/board/query_b.o`、`u/a/alickyuen/aut.o`、`u/a/alickyuen/aut_login.o`：字符串里有原样的换行（`save_object()` 存成 `\r`，`restore_object()` 逐行读，原样的换行让字符串收不了尾），或有空行（`Illegal file format`），读档的对象（留言板、NPC、玩家）从空白开始。换行改写成 `\r`、删去空行（`scripts/lpc_save_encoding.py --from-raw`），驱动核对全部能读回（`scripts/lpc_save_restore_check.py`）。

## 移进不存在的巫师房间（2026-10-15，KB 06 §7.251）

用完的物品、要“离开”的 NPC、掷在空中的兵器被移进巫师的工作室（`/u/llm/`），本库没有这些房间。本库的 `move()` 用 `call_other(dest, "???")` 载入目的地，找不到文件就报 `call_other() couldn't find object`，后面的语句都不执行：婚礼最后一步（`example/marry/npc/meipo` 的 `last_marry`）先把月老送走，在这里报错：新人不会被送上花轿去迎宾楼，喜宴没有了；喜宴结束、礼金付出之后，喜来福（`example/marry/npc/xi-laifu`）退回内堂时报错，留在楼上。2 个文件改为移进本库的虚空房间 `VOID_OB`（`/obj/void`），与原作把它们“停放”在巫师房间的用意相同（haiyang2 的维护者把月老送进 `/d/city/empty`，也是同样的做法）。

## 补回丢掉的基类宏（2026-10-18，KB 04 §6.13）

`inherit F_XXX;` 里的宏本库任何头文件都没有定义，报 `syntax error, unexpected L_IDENTIFIER, expecting L_STRING or '('`，整个对象载入不了；宏指向的基类文件本库其实有，别的库都把这个宏定义成同一个路径。在全局头文件 `include/globals.h` 里补上：`F_LIQUID` → `/feature/liquid`（1 个文件）。（`scripts/lpc_restore_macros.py`）改后用 `lpcc` 逐个载入这些对象：1 个里 1 个通过。

## `set_skill()` 遇到本库没有文件的武功不再抛错（2026-10-18，KB 06 §7.256）

`feature/skill.lpc` 里的 `set_skill()`、`map_skill()`、`prepare_skill()` 碰到没有武功文件的名字就 `error("F_SKILL: No such skill (…)")`，调用它们的 NPC `create()` 整个中断：NPC 载入不了，刷出它的房间也少一个人。本库有 10 个对象设了本库没有文件的武功（27 个名字，最多的是 `magic`、`celestial`、`celestrike`）。三处都改成 `return`：这一门武功不给、不映射，对象照常载入，只是少了它（缺的武功本身仍是内容缺口）。抽样载入这些对象：10 个里 10 个通过。（`scripts/lpc_guard_set_skill.py`）

## 武功名拼错的 NPC（2026-10-19，KB 06 §7.258）

`set_skill("kunlun-shnfa", …)`、`map_skill("dodge", "shaolin-shnfa")` 这样的调用把武功名拼错了：本库没有这个武功文件，有的是拼对的那个。以前这种 NPC 在 `create()` 里报 `No such skill` 载入不了；武功缺失时跳过之后它们能载入，可是少了那门武功（`set_skill` 被跳过，`map_skill` 映射不到，门派弟子用普通轻功/拳脚）。按核对过的对照表改正，共 2 处、1 个文件：`heart_dodge`→`heartdodge`（2 处）。（`scripts/lpc_fix_skill_names.py`）

## RANK_D 对 0 的称呼（2026-10-19，KB 06 §7.273）

`adm/daemons/rankd.lpc` 的 `query_respect()`、`query_rude()`、`query_self()`、`query_self_rude()` 里 4 个函数开头补上 `if (!objectp(ob)) ob = this_object();`。NPC 在 `create()` 里写 `"…" + RANK_D->query_respect(this_player()) + "…"`（`inquiry` 对话、`chat_msg`），驱动自己跑 `reset()` 时没有人在场，`this_player()` 是 0。旧驱动里 `0->query("age")` 返回 0，称呼走默认分支；新驱动直接报 `Bad argument 1 to EFUN call_other()`，房间的 `make_inventory()` 吞掉错误，被打死的 NPC 再也刷新不回来。用 `scripts/lpc_reach_census.py --walk` 找到（xkx100 的武当弟子、一灯、汴梁书生…）；修在守护程序里，不动 1,800 个 NPC 文件。

## 标准整理轮（2026-10-19，`scripts/toolkit_fix.sh`）

本库在新驱动下重扫，机械修复：4 处重复的 inherit。修后与 HEAD 逐个物件对比载入，没有退步。

## 补回丢失的标点（2026-10-19，KB 03 §4.6）

转换时丢掉的分号、逗号、引号或文件末尾的 `}`，共 3 个文件，修前 HEAD 载入失败。文件末尾少了 `}`（最后一个或两个字节丢了），补上：`/u/a/alickyuen/saint/obj/pot.lpc`、`/u/b/baal/area/pill/npc/master.lpc`（2 个）、`/u/b/basic/wp/sword2.lpc`。修后与 HEAD 逐个对比载入：这 3 个物件全部载入，没有退步（`scripts/lpc_restore_from_twin.py`、`lpc_fix_eaten_quote.py --comma`、`lpc_fix_eof_braces.py`）。

## 旧驱动的类型宽松：缺省参数、无类型形参、数组初始化、`class` 变量（2026-10-19，KB 04 §6.19、§6.20）

原来的 MudOS 把调用少传的参数补 0、把没写类型的形参当 `mixed`、不检查变量的声明类型与初始值，也允许变量叫 `class`；这个驱动在编译时全部拒绝，整个物件载入失败。修了 2 个文件：`/u/a/aoe/npc.lpc`、`/u/l/linjack/npcmaker.lpc`（`scripts/lpc_round_files.py` 的修复轮：调用处补写 `0`、无类型形参补 `mixed`、`string X = ({...})` 补星号、void 函数的返回值，以及 `class` 变量改名 `pick_class`）。逐个文件在 HEAD 和改后载入对比：这些文件里 1 个原来载入失败、现在载入，没有退步。

## `member_array('/', str)` 改为 `strsrch(str, "/")`：字符字面量的 member_array 按字节搜索（2026-10-20，KB 06 §7.283）

`member_array('/', str)` 里的 `'/'` 是整数，驱动按 UTF-8 **字节**搜索，返回字节偏移（带第三个参数时起点也是字节）；最新的 FluffOS（923cdbc0）在字符串里有非 ASCII 文字时，对每个调用点警告一次（`Warning: member_array(int, string) searches BYTES`）。而 `str[0..idx-1]` 按字符切，中文字符串会在错误的位置截断。改为 `strsrch(str, "/")`（找不到同样返回 -1，按字符计数；`scripts/lpc_fix_member_array_char.py`，JSON 编码器等少数几处手改）。改动：`/adm/daemons/virtual/vrm_server.lpc`（1 处）。

## `call_out_info()` 的每一项只有 3 个元素（2026-10-20，KB 06 §7.287）

驱动返回的是 `({ 物件, 函数, 延迟 })`，不带 call_out 的参数，旧代码读第 4 项 `info[i][3]`（`callouts` 指令、`calloutd`、`cod` 工具）一读就报 `Array index out of bounds`，指令从第一行起什么也打印不出来。改为 `(sizeof(info[i]) > 3 ? info[i][3] : 0)`（`scripts/lpc_fix_callout_info.py`）。改动：`/cmds/arch/callouts.lpc`（1 处）、`/cmds/wiz/callouts.lpc`（1 处）。

## `if (x = 常量)`：条件里写成赋值的比较（2026-10-20，KB 06 §7.290）

`if (arg = "button" || arg = "按钮")`、`if (!arg || arg = "") return 0;`、`else if (check = 0 && tempB != "")`：把 `==` 写成了 `=`，条件的值就是那个常量，分支对所有非零数和任何字符串（连 `""` 都算）永远成立、对 0 永远不成立，变量还被覆盖；驱动对此没有任何警告。每一处 `=` 改成 `==`（`scripts/lpc_fix_cond_assign.py`，共 9 处）。改动：`/obj/mjlady1.lpc`（3 处）、`/obj/mjlady2.lpc`（3 处）、`/obj/mjlady3.lpc`（3 处）。

## 登录密码超过 255 字节：`crypt()` 抛错（2026-10-20，KB 06 §7.294）

驱动的 `crypt()` 对超过 255 字节的密钥直接报错（`Error in crypt(), check your salt`），老驱动则按任意长度散列。在登录提示符下输入 256 字节以上的密码，密码检查那一行就抛错，连线停在一个裸的 `> ` 提示符上，登录走不完（`password` 指令的旧密码检查同样）；用 300 个 `x` 当参数的扫描发现的。`/adm/obj/simul_efun.lpc` 里补了一个同名的 simul_efun `crypt(key, salt)`：只有超长的密钥才被截短（先截到 255 个字符，再逐字符截到 `sizeof(to_buffer(key)) <= 255`，限制按字节算，一个汉字占三个字节），再交给 `efun::crypt()`；普通密码原样散列，已存的密码散列不受影响（`scripts/lpc_add_sefun.py crypt`）。

## sefun `cat()`：缺文件时 `write(0)` 报错（2026-10-20，KB 06 §7.297）

`void cat(string file) { write(read_file(file)); }`：文件不存在（压缩包没带的欢迎/公告文件，或只有运行中的 mud 才会写的日志）时 `read_file()` 回 0，`write(0)` 在本驱动里报 `Bad argument 1 to receive()`，调用者（登录对话、`cat` 指令）被中断；老驱动什么也不打印。改成 `write(read_file(file) || "");`（`scripts/lpc_fix_cat_unchecked.py`）。改动：`/adm/simul_efun/file.lpc`。

## 翻页器 `start_more(read_file(...))`：文件缺失时 `explode(0)`（2026-10-20，KB 06 §7.300）

东方故事系的翻页器 `void start_more(string msg) { ... explode(msg, "\n") ... }` 被这样调用：`start_more(read_file(HELP_DIR + "help/topics"))`、`start_more(read_file(NEWS))`。压缩包没带的文件使 `read_file()` 回 0，`explode(0, ...)` 在本驱动里报 `Bad argument 1 to explode()`（不带参数的 `help` 指令就是这样出错的），老驱动把 0 当空文本。在 `start_more` 开头加了 `if (!stringp(msg)) return;`（`scripts/lpc_fix_start_more.py`）。改动：`/feature/more.lpc`。

## `multi_arrow`、`mindkill`、`mk`：变量名 `in` 是保留字（2026-10-20，KB 04 §6.26）

`daemon/skill/multi_arrow.lpc`、`u/h/hack/skill/multi_arrow.lpc`、`u/m/morral/mindkill.lpc`、`mk.lpc` 里有叫 `in` 的变量或参数：`syntax error, unexpected L_IN`。`scripts/lpc_fix_in_ident.py` 改名为 `in_var`。加载检查 4/4，HEAD FAIL → tree PASS。

## NPC 的 `chat()` 在 `chat_msg` 为空数组时下标越界（2026-10-21，KB 06 §7.334）

NPC 基类的 `chat()` 是 `if (arrayp(msg = query(...))) { if (random(100) < chance) { rnd = random(sizeof(msg)); if (stringp(msg[rnd])) ...`，不检查列表是否为空。本库有 9 个 NPC 文件写成空 `chat_msg`（例如 `/daemon/class.es/ronin/master.lpc`、`/open/world1/sdo/christmas/awardmiss.lpc`），它们走的基类 `chat()` 本来已经检查了列表大小（或碰巧不出错），不受影响；下面这些文件各自带着一份没有检查的 `chat()`（NPC 里的副本、旧版基类），一并加上守卫。在 `random(100) < chance` 前面加 `sizeof(msg) &&`（`scripts/lpc_fix_chat_empty.py`；`if (random(100) > chance) return 0;` 的写法是 `!sizeof(msg) ||`）。改动：`/u/l/linjack/npc.lpc`（共 1 个文件）。

## 存档里的 `.c` 文件名改成 `.lpc`（2026-10-21，KB 03 §4.2 第 9 项）

存档里写着 `"/d/city/npc/wei.c"` 这样的文件名；extract 时源文件已经全部改成 `.lpc`，而驱动对带扩展名的路径只认字面，`new()` / `load_object()` / `move()` 都找不到它，调用方多半把失败当成「没有这个东西」悄悄跳过。本库 5 个存档共 167 处按 `scripts/lpc_fix_save_dotc.py` 改成 `.lpc`（只改 `.lpc` 存在而 `.c` 不存在的字符串；玩家存档、备份、留言板、巫师目录和文件索引缓存不动）。`data/questd.o`（`newquestd.lpc` 的 `assigner`，NPC 文件当键、任务文件当值）两边都改成 `.lpc`。改动：`/data/club_bank/dragon.o`（1 处）、`/data/club_bank/god.o`（1 处）、`/data/game/ma_game.o`（5 处）、`/data/questd.o`（158 处）（等共 5 个存档）。

## 巫师命令不带参数时对 0 调用 efun（2026-10-21，KB 06 §7.336）

巫师（管理员）把命令敲成不带参数时，驱动把 0 传给字符串参数；下面的命令第一句就把这个 0 交给 efun，运行时报 `Bad argument 1 to ...`，这条指令从来没有用过。用 `scripts/lpcc_bare.py` 不登录、在一次 `lpcc` 求值里以 0 调用 `main()` 逐个确认后，由 `scripts/lpc_fix_bare_arg.py` 在第一处使用参数的语句前加守卫：没有 `help()` 的是 `return notify_fail("…\n");`。改动（1 个文件，括号里是接住 0 的 efun）：`/cmds/adm/destusr.lpc`（`find_player`）。加载检查 HEAD 与工作树对照，没有退步。

## 注册到不存在函数的 `add_action`（2026-10-21，KB 06 §7.349）

`add_action("函数", "动词")` 绑定的函数，在对象本身、它包含的头文件、它继承的父类和继承它的子类里都没有定义（`scripts/lpc_scan_callout_targets.py` 静态解析，子类用传递闭包复核，`scripts/lpc_verify_handlers.py` 运行时 `function_exists()` 复核）。驱动从玩家最新的一条动作往回找，遇到这样的句子就报 `*Function for verb 'drop' not found.`，同一个动词的其他处理函数不再尝试（不是最新的一条就悄悄跳过）。删除了 1 条注册（1 个文件，`scripts/lpc_fix_dead_add_action.py`），动词留给别的处理函数：`/obj/areamaker.lpc`（`do_mkareamap`）。最多的函数名：`do_mkareamap` 1 处。

## 对象路径里的 `..`：`new(__DIR__ "../obj/x")` 报 `Read access denied`（2026-10-22，KB 06 §7.351）

`__DIR__` 是当前文件所在目录（带结尾斜杠），`__DIR__ "../obj/x"` 就是 `/d/zhiye/npc/../obj/x`；驱动的 `legal_path()` 不接受带 `..` 的路径，`new()` / `load_object()` 直接抛 `*Read access denied.`（实测，`find_object()` 对它答 0）。走库自己的 `carry_object()` / 房间 `objects` 表的路径，库的基类会先规范化，能用；直接把路径交给 `new()` / `clone_object()` / `load_object()` / `move()` 的不行，调用到那一步才报错。改成规范化后的绝对路径（`scripts/lpc_fix_dotdot_dir.py --direct`）：`/open/world1/kkeenn/love/npc/master_1.lpc`（`__DIR__ "../room30"` → `"/open/world1/kkeenn/love/room30"`）, `/open/world1/kkeenn/love/npc/master_2.lpc`（`__DIR__ "../room1.lpc"` → `"/open/world1/kkeenn/love/room1.lpc"`）, `/open/world1/kkeenn/love/npc/master_2.lpc`（`__DIR__ "../room8"` → `"/open/world1/kkeenn/love/room8"`）, `/open/world1/kkeenn/love/npc/master_2.lpc`（`__DIR__ "../room9"` → `"/open/world1/kkeenn/love/room9"`） 等共 63 处。

## `/example` 目录里缺失物品的 `carry_object()`（2026-10-22，KB 06 §7.73 补充）

`scripts/lpc_guard_carry_object.py` 跳过名叫 `example` 的目录，而这个库的 `/example` 是真正的区域（婚礼区 `/example/marry`、样板 NPC 和房间），goto 探测进了 `/example/marry/yamen-datang`，控制台报 `*Bad argument 1 to EFUN call_other() Got int(0)`：`/example/marry/npc/jiang-yaoting.lpc` 第 39 行 `carry_object("/clone/misc/cloth")->wear()`，这个库没有 `/clone/misc/`。10 个文件里 22 处（衙役、月老、媒婆、`/example/ka` 等）改成 `{ object carried_ob = carry_object(..); if (carried_ob) carried_ob->wear(); }`。证明（`scripts/lpcc_eval.py`，对 10 个 NPC 各 `new()` 一次，HEAD 与工作区各一个新进程）：HEAD 只有 1 个能克隆，现在 9 个；剩下的 `xi-laifu` 在 HEAD 和工作区都不能编译：它调用 `MONEY_D->price_str()`，这个库既没有 `MONEY_D` 宏也没有钱庄守护进程（内容缺失，没动）。

## `(: 函数 :)` 指针指向对象自己没有定义的函数（2026-10-22，KB 06 §7.355）

`item_desc` / `inquiry` / `chat_msg_combat` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：编译不报错，用到时驱动报 `*Undefined lfun pointer called: 函数名`（`look 某物`、`ask NPC about 话题` 直接出错，战斗 / 闲聊里的指针在 NPC 的 `chat()` 里出错，这一拍心跳的后半段被跳过）。`scripts/lpc_scan_callout_targets.py --kinds=lfun`。 另有 1 处函数体被作者整段注释掉（指针没跟着删），是有意关掉的，没动。

## `(: 函数名 :)` 指针指向本库没有的函数：只含这个指针的行加了注释（2026-10-22，KB 06 §7.355 补充）

`inquiry` / `item_desc` / `chat_msg*` 里的 `(: 函数名 :)` 指向本对象（含包含文件、继承的父类）没有函数体的函数：用到时（`ask`、`look`、NPC 闲聊）驱动抛 `*Undefined lfun pointer called: 函数名`，这一拍心跳的后半段被跳过。这些函数没有可以补回的来源（别的库同一路径的文件里没有，或者它还要用本库没有的东西），所以 1 个文件里 2 行只含这个指针的行（`"剃度" : (: ask_for_join :),` `"出家" : (: ask_for_join :),`）加了注释，原文保留并写明原因，这一项当作没有这个话题 / 物品 / 闲聊条目（`scripts/lpc_fix_dangling_lfun.py`；`#include` 的文件在库里缺失的对象、指针不在整行上的写法没动）。 前提（`function_exists()`）和加载检查（HEAD 与工作区对比，本库改动的 `.lpc` 文件）的结果见 KB 06 §7.355：没有一个回归。

## 汉字按字节切片的老写法没有换成按字符：改法名 `"澄" + name[2..3]`、辈分判断 `name[0..1] == "澄"` 等 1 处（2026-10-22，KB 06 §7.360）

原档按字节算字符串区间（一个汉字 2 字节）：`name[2..3]` 是名字的第二个字，`name[0..1] == "澄"` 问名字是不是以「澄」开头。转成 UTF-8 之后，这个驱动的区间和 `strlen()` 都按字符算（`strlen("澄观")` 是 2，`"澄观"[0..1]` 是两个字），老算术原样留着、意思全变：拜入少林 / 武当 / 峨嵋等派的玩家被改成错误的法名（二字名 `张三` 变成一个字的 `澄`，更长的名字取到第三个字）。

本库 1 处（1 个文件）：拼名字的赋值 1 处。例：`name[0..1]` → `name[0..0]`（`/daemon/class.es/bonze/master.lpc:104`）。`scripts/lpc_fix_gbk_slice.py` 把下标按字符重算（社区的 UTF-8 版 `xkx100utf8` 里就是同样的写法，作对照）；没有改的：截断（`name = name[0..7]`，现在最多 8 个字，只是放宽）、ASCII 的区间（`fname[0..3] == "room"`、`ctime(time())[4..19]`）和上下文看不出是汉字的区间。证明（`scripts/lpcc_eval.py`，bixiecanyang；其余各库是同一份文本）：让澄字辈掌门 `attempt_apprentice()` 一个名叫「张三」的访客，HEAD 的法名是 `慧`，改后是 `慧三`；抽样 28 个库的 HEAD / 工作树加载对比 0 退步。工具不幂等（`[0..3]` 折半得 `[0..1]`，又是对齐区间），改过的文件记在 `scripts/gbk_slice_converted.txt`，不要重跑。

## 按字节写的汉字循环、茶馆猜诗和同盟频道标题（2026-10-23，KB 06 §7.363）

老档按字节做「一个汉字」：`while (i--) if (i % 2 == 0 && !is_chinese(name[i..<0]))` 只检查偶数下标，奇数位上的拉丁字母（`张a`）会过；茶馆猜诗 `mixup()` 用 `strlen(str)/2` 再 `j=j+j`、`str[k..k+1]` 交换两字节；泥潭系 `channeld` 的 `switch (strlen(fname)) case 4/6/8/10` 和 `strlen(family)==4/6` 按字节长度给同盟 / 门派名加空格。本驱动的 `strlen()` 和区间都按字符算。`scripts/lpc_fix_byte_char.py`：去掉奇偶项、把区间改成 `name[i..i]`，按字符重写 `mixup()` 并把 `strlen(first)>=14` 折成 7，频道标题的 case / 门派长度改成字符数（对照 aoxiangtianji）。本库 汉字循环 / `is_chinese` 区间 2 个文件。证明（`scripts/lpcc_eval.py`）：sjplii 的 `check_legal_name` 在 HEAD 接受「张a」、改后拒绝，两边都接受「张三」；xkx100 的 `clubpoem->mixup("离离原上草")` 得到「离离原草上」（真交换汉字）；nitan_san 两字同盟名得到 `【 兄  弟 】`。关键对象加载通过。

## 巫师区出口 faceoff / rence / niulang / yihua（2026-10-23，KB 06 §7.372）

`/u/f/faceoff/`、`/u/r/rence/`、`/u/onskyer/niulang/`、`/u/skinys/yihua/` 对应区域已在 `/open/world1/faceoff/bird/`、`/open/prayer/`、`/d/niulang/`、`/d/yihua/`。`scripts/lpc_fix_wizard_area_exits.py` 在目标存在时改写，仍缺失的出口行删除。本库 24 处。证明：dreamofseven wood5 四向可加载；xlqy_new2007 天河东西向 niulang；kxkj kitchen7 → prayer。


## `/open/` 上残留的恒真/恒假比较链（2026-10-23，KB 06 §7.282 Also）

`cominging/.../ravager.lpc`：`arg != "man" || arg != "revage man"` 恒真 → `&&`（`kill man` 才进战斗）。
`acme/area/l2.lpc`：`arg=="south" && arg=="north"` 恒假 → `||`（游泳临时标记才能清掉）。
证明：两对象可加载；visitor/`man` 形状求值正确。

## `/open/` 上残留的条件赋值（2026-10-23，KB 06 §7.290 Also）

`lpc_scan_cond_assign.TOP` 曾跳过 `/open/`。本批：`acme/area2/may*`、`faceoff/sky/ten*`、`cominging/wh_1`、麻将 NPC 等共 34 文件，`if (arg = "")` 等改为 `==`。
证明：`may1` 可加载；空串比较求值正确。

## /open/ 上残留的法名切片（2026-10-23，KB 06 §7.360 Also）

`lpc_fix_gbk_slice.py` 曾把 `/open/` 当巫师家跳过。`open/world1/acme/bonze/npc/master.lpc` 的 `do_kneel`：`new_name = prename[...] + name[0..1]` 在字符区间下取了两个汉字。改为 `name[0..0]`。证明：`lpcc_eval` 对「王小明」拼出 HEAD「空王小」、改后「空王」。

## /open/ 上残留的负伤害（2026-10-23，KB 06 §7.241 Also）

`lpc_fix_damage_calls.py` 曾跳过 `/open/`。`open/world1/tmr/north_forest/class/skill/2.lpc`：`receive_damage("ap",-200)` 在本库 `damage.lpc` 上会 `error`。改为正数 200。证明：对象可加载。

## /open/ 上残留的技能名拼写（2026-10-23，KB 06 §7.249 Also）

`lpc_fix_skill_typo.py` 曾跳过 `/open/`。`open/world1/uchimaha/bird/bird22.lpc`：`query_skill("birdeight")` 恒为 0（技能文件是 `bird-eight`），练步入口永远 return 0。改为 `bird-eight`。证明：`lpcc_eval` 对已学会的 `bird-eight` 查询非 0，`birdeight` 为 0；房间可加载。

## /open/ 上残留的 family 映射门（2026-10-24，KB 05 §7.30 Also）

`lpc_fix_family_guard.py` 曾跳过 `/open/`。`open/world1/tmr/xiangyang/task/scjob.lpc`：`mapping my_fam = me->query("family");` 后直接 `my_fam["family_name"]`，无门派玩家触发 `Value being indexed is zero`。同文件加 `if (!mapp(my_fam)) my_fam = ([ ]);`。证明：`lpcc_eval` 无 family 时 HEAD 索引报错，改后为 0；对象可加载。


## open 下 set_name 多段字符串 id（2026-10-27，KB 06 §7.260 Also）

`feature/name.lpc` 的 `set_name(string name, string *id)` 要数组，但 `open/world1/tmr/...` 八处写成 `set_name("名", "id1", "id2")`。`lpc_fix_set_name_id` / `missing_foo` 的 SKIP 不再把 `/open/` 当巫师目录；本批把这八处收成 `({ ... })`。证明：HEAD `book.lpc` 仍是三字符串参数，改后为数组。

## F_CLOTH → CLOTH（2026-10-27，KB 04 §6.25 Also）

七件 tmr 区衣物写 `inherit F_CLOTH` / `setup_cloth()`，本库 `armor.h` 无该宏（手足多用 `CLOTH`），驱动报 `unexpected L_IDENTIFIER`。改为 `inherit CLOTH`，把 `apply_armor/cloth` 的护甲值写入 `armor_prop/armor`。证明：HEAD guard-cloth 失败；改后七件均加载。

## Aug F_* 防具宏 → 本库 ARMOR/BOOTS/…（2026-10-27，KB 04 §6.25 Also）

tmr 区约 45 件防具写 `inherit F_ARMOR` / `F_HEAD_EQ` / `F_HAND_EQ` / `F_FEET_EQ` / `F_FINGER_EQ` / `F_NECK_EQ` / `F_WAIST_EQ` 并调用 `setup_*()`，本库无这些宏。一律改为 `armor.h` 已有的 `ARMOR`/`HEAD`/`HANDS`/`BOOTS`/`FINGER`/`NECK`/`WAIST`，把 `apply_armor/...` 里的数值写入 `armor_prop/*`。证明：HEAD guard-armor 失败；改后抽样 10 件均加载。

## F_PANTS → PANTS（2026-10-27，KB 04 §6.25 Also）

三件裤子写 `inherit F_PANTS` / `setup_pants()`，本库无该宏（已有 `PANTS`）。改为 `inherit PANTS`，护甲写入 `armor_prop/armor`。证明：HEAD 失败；改后三件均加载。

## F_BLADE / F_PIKE / F_BLUNT → BLADE/FORK/HAMMER/STAFF（2026-10-27，KB 04 §6.25 Also）

tmr 区 20 件武器写 Aug `inherit F_BLADE`（本库 `_blade` 作 feature 缺 `EQUIP::setup`/`weight`）或未定义的 `F_PIKE`/`F_BLUNT`，并调用 `setup_blade`/`setup_pike`/`setup_blunt`。改为本库 `BLADE`/`FORK`（枪）/`HAMMER`（棒）/`STAFF`（钓竿），`init_*` 伤害取 Aug 的 range；`apply_weapon/...` 写入 `weapon_prop/*`。证明：HEAD wood-blade 失败；改后 20/20 加载。

## F_SWORD / F_AXE / F_WHIP / F_DAGGER → 本库基类（2026-10-27，KB 04 §6.25 Also）

续上批：23 件 tmr 武器仍写 Aug `inherit F_SWORD`/`F_AXE`/`F_WHIP`/`F_DAGGER`（指向 `_sword` 等 feature，同样缺 `EQUIP::setup`/`weight`）。改为 `SWORD`/`AXE`/`WHIP`/`DAGGER`，`init_*` 伤害取 Aug range；`apply_weapon/...` → `weapon_prop/*`。残渣 0。证明：HEAD white-sword 失败；改后 23/23 加载。

## F_STUDY 宏 + feature/study（2026-10-27，KB 04 §6.16 Also）

四处 tmr 书籍 `inherit F_STUDY`，本库无宏且无 `/feature/study.lpc`。自 dfgsiiv13b 采纳 `feature/study.lpc`，并在 `globals.h` 增加 `#define F_STUDY`。证明：HEAD book 失败；改后四本均加载。

## Aug npc.h + set_race 栈（2026-10-27，KB 04 §6.16 Also）

tmr 区 112 个 NPC `#include <npc.h>` 并调用 Aug 的 `set_race`/`set_attr`/`set_stat_*`/`carry_money` 等，档案从未带入该头与 `feature/npc/*`。补上 `include/npc.h`、自 dfgs2 采纳 reaction 模块，并加 `aug_compat.lpc` 把 Aug 属性映射到本库 `hp`/`mp`/`ap`/`str`…；`beast_base/.../action.lpc` 的未定义 `HIK` 改为本库 `HBK`。证明：HEAD `Cannot #include npc.h`；改后 112/112 加载。

## 深度功能测试（2026-10-27，§6.25 #inherit）

`u/t/tako.tmp/man`：`#inherit NPC` → `inherit`；`delete_temp` 被折行成 `dele`/`te_temp` 一并修。

## 深度功能测试（2026-10-27，§6.25 traveler 去引号）

`u/t/tako.tmp/traveler` 整文件去引号；按同目录完整 `traveller` 重写（保留 walk man / level 5）。

## 深度功能测试（2026-10-27，§6.25 star_necklace tell_object 引号错位）

`…/star_necklace` 的 `tell_object("me, …")` 同形，改为 `tell_object(me, "…")`。证明：改后加载。

## 深度功能测试（2026-10-27，§6.25 ddl message_vision 截断）

`u/r/romeo/area/npc/wp/ddl` 的 `message_vision` 丢了收尾 `"NOR, me, victim);`。补上。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 dsword 引号/截断）

`u/r/romeo/area/npc/wp/dsword` 多处截断（`set_name(... ({;`、`message_vision` 无收尾、`init_blade` 对 SWORD）。按残片重写：补 ids、收尾字符串、改 `init_sword`。证明：HEAD 失败；改后加载。

## 深度功能测试（2026-10-27，§6.25 tmr master 缺头/截断）

`u/t/tmr/room/npc/master` 含不存在的 `#include "/u/a/anfernee/anfernee.h"`、`inherit GUILDMASTER` 而宏路径未进编译单元，且 `greeting` 的 `say` 字符串截断。用完好的 `open/world2/anfernee/start/npc/master` 覆盖。证明：HEAD 失败；改后加载。
