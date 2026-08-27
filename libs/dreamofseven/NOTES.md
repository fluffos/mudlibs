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

- **SEVERE-scale but confined: wizard "tmr"'s entire personal
  multi-zone questing area (275 NPC/item files, ~15 sub-areas:
  `batogiya_dtl`, `barbarian_island`, `beast_base`, `crush_bone`,
  `dead_forest`, `down_cave`, `duli_forest`, `duli_port`,
  `duli_village`, `mist_forest`, `quanzhen`, `whale_forest`,
  `whale_river`) `#include <npc.h>`, a local convention header that
  does not exist ANYWHERE in this 32,946-file archive (`find . -iname
  npc.h` returns zero hits, checked archive-wide before concluding
  this). This collapses to ONE shared root cause (AGENTS.md §6.4), not
  275 independent bugs -- confirmed by reading several of the
  `#include`-failing files and finding no other defect once the
  missing header is accounted for. A genuine, pre-existing upstream
  completeness gap (this wizard's own header apparently never made it
  into the pushed archive), not a conversion artifact and not
  fabricated. **Not on the registration/starting-room path** -- the
  actual start room (`/open/world1/tmr/area/hotel`, "朝天樓") and its
  two NPCs (`Master`/`Waiter`) live directly under `tmr/area/`, a
  sibling of these broken sub-zones, and compile/load cleanly on their
  own. The `make_inventory()`/`reset_room()` fix above ensures none of
  this cascades into crashing unrelated rooms that happen to reference
  this content.
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
