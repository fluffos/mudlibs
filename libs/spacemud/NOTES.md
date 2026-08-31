# spacemud -- porting notes

Source: `gh repo clone limalib/spacemud` (HEAD `f4428ee`, 2026-08-30).
1,786 files under the repo's `lib/` directory (the mudlib root --
`adm/`, `bin/`, `resources/`, and the top-level docs/license files are
project scaffolding, not part of the mudlib, and were not converted).
Slug `spacemud`, number 957, port 40259. Description: "A Space themed
mudlib that uses the LIMA Mudlib without modifying it."

## -1. This lib makes a REAL outbound network connection at boot (Intermud-3), like `imud`

`daemons/imud_d.lpc` (loaded via `data/config/preload`, i.e. every
normal boot, not just on demand) hardcodes a REAL public Intermud-3
router address -- `#define ROUTER "*dalet"` / `#define ROUTER_ADDRESS
"97.107.133.86 8787"` -- and its `create()` calls
`trigger_reconnect("router")` unconditionally, i.e. it attempts a real
outbound `socket_connect()` to a live third-party host on the public
internet the moment the daemon loads, exactly the class of side effect
AGENTS.md §2.3 documents for `imud` (161). Confirmed during this
session's testing: `data/i3_errors` accumulated a real
"not-allowed: Not in allow list for elephant_link" response from the
live router, meaning the connection genuinely succeeded and exchanged
real traffic with the public I3 network (that file was deleted before
committing, along with other session-local runtime-log cruft -- see
the save-state cleanup note near the end of this file). **This means,
like `imud`, `spacemud` should NOT be swept into high-frequency
automated re-boot loops** (long-sit boot watches, round-two/round-
three re-test cron, etc.) the way the rest of this corpus safely can
be -- each boot is a real network event against a real third party
that briefly registers this host's public IP under the mud's name on
the live I3 mudlist. Unlike `imud`, this is NOT the lib's whole
point (Intermud is a minor background feature here, not the point of
the archive), so if this ever becomes a problem for repeated
CI-style testing, commenting out `/daemons/imud_d` in `data/config/
preload` would be the least invasive way to disable it without
touching the daemon's own code.

## 0. Driver build: reuses `~/src/fluffos-lima`, no new worktree needed

This is a THIRD Lima-lineage archive in this collection (after
`libs/lima` and `libs/wilderness`, see AGENTS.md §7.46). Its own
`secure/check_config.c` was diffed line-by-line against both:

- Against `libs/lima`'s `check_config.lpc`: identical flag list, only
  cosmetic string/version differences (this fork's own updated banner
  text and FluffOS-version gate). In particular `#ifdef
  __ARRAY_RESERVED_WORD__ need("#undef ARRAY_RESERVED_WORD")` --
  same requirement as `libs/lima`'s modern fork.
- Against `libs/wilderness`'s check_config (the ~2000-era snapshot
  that needs the OPPOSITE `ARRAY_RESERVED_WORD` direction): different.

Confirmed empirically too: `~/src/fluffos-lima/build-debug/src/
options.autogen.h` already defines `__NO_LIGHT__`/`__NO_ADD_ACTION__`/
`__NO_WIZARDS__`/`__PACKAGE_PARSER__`/`__PACKAGE_CONTRIB__` and
does NOT define `__ARRAY_RESERVED_WORD__`/`__OLD_ED__`/
`__PACKAGE_UIDS__`/`__CAST_CALL_OTHERS__`/`__NO_ENVIRONMENT__`/
`__OLD_RANGE_BEHAVIOR__` -- exactly what this lib's `check_config.lpc`
needs. **No third worktree was built; `config.fluffos` and
`scripts/lpcc_check.sh` both point at
`~/src/fluffos-lima/build-debug/src/{driver,lpcc}`, same as
`libs/lima` itself.** Corpus-wide corroboration: no bare `array`
declarations exist anywhere in this repo (the `ARRAY_RESERVED_WORD`
bug class documented for `libs/wilderness` doesn't apply here -- this
codebase already uses `mixed *` throughout, consistent with being a
modern fork of the same lineage as `libs/lima`, not the old snapshot).

Compile sweep: `LPCC=~/src/fluffos-lima/build-debug/src/lpcc bash
scripts/lpcc_check.sh libs/spacemud/config.fluffos libs/spacemud/work`,
wrapped in `(ulimit -v 8388608; ...)` per the standard memory-heavy-sweep
precaution.

## 1. Conversion

Pure UTF-8 archive already (`iconv -f UTF-8 -t UTF-8` round-tripped
clean on every byte-flagged file; the only non-ASCII bytes found were
genuine multi-byte UTF-8 -- a currency symbol `¤`, `±`, and an accented
`é` in a room description). `scripts/convert_lib.sh` ran with `UTF-8`
as the source encoding (rename + reference-fixup only, no transcode):
1,400 `.c` files renamed to `.lpc`, 112 literal `.c"` references fixed,
10 local angle-bracket `#include`s converted to quotes, 7 files hit by
the `static`->`nosave` sweep.

- **Same `finger_d` extension-missing-duplicate trap as `libs/lima`/
  `libs/wilderness` (AGENTS.md §4.2 item 5)**: `secure/daemons/
  finger_d` (no extension) and `finger_d.c` (renamed to `.lpc`) are
  different content -- the extensionless one has an older,
  single-character multi-user-aware version; `git log` confirms the
  `.c`-suffixed file was touched by real commits (`Reformatted all .c
  files with VS Code for consistency`, `First attempt for multi
  character support in finger`) while the extensionless one hasn't
  been touched since the original `lima_v1_fluffos.zip` import. Driver
  path resolution only ever reaches the extension-bearing file, so the
  bare-named one was dead on any driver, past or present. Deleted.
- **Same `static`->`nosave` false-positive collisions as `libs/lima`/
  `libs/wilderness`, same shared files**: `include/global.h`'s
  `#ifndef __SENSIBLE_MODIFIERS__` compatibility shim (dead code on
  this driver) had its own `static` RHS tokens corrupted to `nosave`;
  reverted for source fidelity. Two more genuine string-literal false
  positives, confirmed by diffing against the pre-conversion raw copy:
  `domains/std/lima/workroom_ob.lpc`'s "a burst of *static* darts"
  (the exact same Lima Bean workroom scene `libs/lima`'s own notes
  flag) and `domains/common/item/ship_nav.lpc`'s "a *static* electronic
  sound" (this one is spacemud's own bespoke content, not shared with
  Lima). Both restored. `std/modules/m_rstview.lpc`'s `decls` array
  literal (a list of LPC declaration keywords used by its own
  source-formatting logic, containing the literal string `"static "`)
  and `domains/omega/room/floor8/n_coffice.lpc`'s "the occasional
  crackle of *static* from [maintenance radios]" were two more real
  string-literal hits, both restored.
- `obj/secure/shell/shellfuncs.lpc`/`shellvars.lpc` were flagged by
  the raw-vs-converted diff heuristic but turned out to already use
  `nosave` natively in the original source (no `static`->`nosave`
  substitution actually happened there) -- a false alarm in the
  detection method, not a real conversion issue.

## 2. §7.46 confirmation: same flags as `libs/lima`, not `libs/wilderness`

See §0 above -- the load-bearing finding of this onboarding's driver
setup. Recorded here too since it's the first concrete confirmation
that AGENTS.md §7.46's "check each `check_config.lpc` individually,
don't assume the direction from a prior lib" advice cuts BOTH ways: a
new archive can also turn out to match an EXISTING worktree exactly,
saving a fresh build.

## 3. Real programming bugs found and fixed (new catalog entries: AGENTS.md §7.166, §7.167)

Full writeups are in AGENTS.md itself (§7.166 and §7.167) since both
are driver-dialect-adjacent bug CLASSES likely to recur in other libs,
not one-off content issues. Summarized here with the spacemud-specific
impact:

1. **`daemons/method_d.lpc` and `daemons/space_d.lpc` both call one of
   their own `check_privilege()`-gated mutators directly from
   `create()`** (AGENTS.md §7.166) -- `check_privilege()`'s design
   requires a real connected `this_user()` at the end of the call
   chain if the object-privilege walk doesn't resolve earlier, which
   never exists at boot. Confirmed via a temporary `debug_message()`
   instrumenting `all_previous_objects()` inside `check_privilege()`:
   the failing stack was exactly `({simul_efun, method_d-or-space_d
   (self), master})`, no user frame. Masked from ordinary boot logs by
   `secure/master.lpc`'s `preload()` wrapping every preload
   `load_object()` in a bare `catch()` -- the thrown `error()` never
   surfaces, it just silently aborts partway through `create()`.
   - `method_d.lpc`: `load_config_from_file()` (which populates the
     `methods` mapping used by `m_complex_exit.lpc`'s `set_method()`
     for door/elevator "go" verbs) called `add_method()`/
     `add_method_equivalents()` directly -- **every single boot, the
     `methods` mapping stayed permanently empty**, and `log/runtime`
     showed `*Cannot set method 'go'. Method is either too ambiguous
     or should be added to METHOD_D` for every complex-exit door and
     elevator in the game (confirmed for `service_hatch`,
     `elevator_door`, and more, all cascading from the same root
     cause). This is a SPACEMUD REGRESSION, not a stock-Lima bug --
     `libs/lima`'s own `method_d.lpc` hardcodes its `methods` mapping
     as a literal (no config-file loading, no `add_method()` calls at
     boot at all), so it never hits this trap; spacemud's author
     rewrote it to load from `/data/config/methods` and introduced the
     always-fails privilege check in the process.
   - `space_d.lpc`: `create()` called `generate_starsystems()`
     directly when `starsystems` was empty -- **the procedural
     universe never got generated on any fresh install.**
   - Fix (both): route the boot-time call through `unguarded(1, ( :
     function, args... : ))`, the SAME mechanism `M_DAEMON_DATA`'s own
     `save_me()`/`restore_me()` already use in this exact codebase for
     this exact "trusted self-action, no live user" scenario. Verified
     live: after the fix, `log/runtime` is empty across a fresh boot
     (no more `Cannot set method`), `data/daemons/space.o` gets a
     real, populated `starsystems` mapping, and `data/daemons/
     method.o` gets a real, populated `methods` mapping -- confirmed
     the door/elevator "go" verb works navigating through the space
     station's maintenance corridors in a live playthrough.
2. **`daemons/crafting_d.lpc`'s `create()` used `materials == ([])`**
   (mapping IDENTITY equality, not value equality -- AGENTS.md §7.167a)
   to decide whether `load_config_from_file()` (which parses
   `/data/config/crafting-materials`, a real, correctly-populated
   config file listing `metal`/`textile`/`plastic`/`mechanic`/etc.
   material categories) needed to run. `([]) == ([])` is `0` on this
   driver (confirmed with an isolated one-file `debug_message()` test
   -- mappings and non-empty arrays compare by reference, only
   zero-length ARRAYS get a lucky pass via a shared-singleton
   optimization). Since `materials` is a saved/restored variable that
   starts genuinely empty (`([])`) on a fresh install, the identity
   check was ALWAYS false and the config never loaded, on ANY boot,
   ever -- **every `set_salvageable()` call anywhere in the codebase
   (every weapon/armor built with `std/modules/m_salvageable.lpc`)
   threw `*Invalid salvage type: X` and aborted that object's
   `setup()` partway through**, for every category (not just
   "textile", which is just the first one any given object happened
   to reference) -- a severe, corpus-wide breakage confirmed via
   `log/runtime` showing the identical error for chainmail, swords,
   `hyperspace_hoodie` (omega's own bespoke armour), and more, all
   cascading from this single root cause. Fixed with `if
   (!sizeof(materials))`, the idiom this SAME codebase already uses
   correctly elsewhere (`space_d.lpc`'s `!sizeof(keys(starsystems))`,
   `method_d.lpc`'s `!sizeof(keys(methods))`). Verified live: a fresh
   `data/daemons/crafting.o` now contains all 9 material categories
   including `textile`, and a live playthrough's `get chainmail
   shirt` + `salvage chainmail shirt` in the armour-tutorial room
   correctly yields "a copper scrap, a lead scrap, and a steel scrap".
   By far the single highest-impact fix this session (fixed the ENTIRE
   crafting/salvage feature, not one item).
3. **`std/modules/m_frame.lpc`'s `first_colour()`/`last_colour()`
   crash on the built-in "none" colour theme** (AGENTS.md §7.167b) --
   a bespoke ASCII-frame colour-theme system spacemud added on top of
   Lima (no stock-Lima equivalent; `include/frame_themes.h` and this
   module's colour-handling functions don't exist in `libs/lima`).
   `explode(hcolours[0], ",")[0]`/`[< 1]` assumed `explode()` always
   returns at least one element, but `hcolours[0]` is legitimately the
   empty string `""` for the built-in `"none"` theme, and `explode("",
   ",")` returns a ZERO-element array on this driver (confirmed with
   an isolated test) -- `[0]`/`[< 1]` then throws `Array index out of
   bounds`. `"none"` is the DEFAULT `frame_colour` for any connection
   whose telnet negotiation doesn't report `xterm`
   (`obj/secure/shell/shellvars.lpc`'s `default_variables()`), i.e.
   any plain/non-MTTS client -- not a misconfiguration, an ordinary
   case. Reproduced live: the raw scriptable test client (which
   doesn't negotiate MTTS) crashed with `*Array index out of bounds`
   in `log/catch` the very first time it pressed `s` (select
   character) in the account menu, corrupting the character-list
   screen (`obj/usermenu/usermenu.lpc`'s `list_chars()`, which builds
   its header row via `last_colour()`). Root-caused by temporarily
   instrumenting `first_colour()` with a `debug_message()` dump of
   `hcolours`/`this_user()->frames_colour()`, then confirming
   `explode("", ",")`'s return shape with an isolated one-file test.
   Fixed by guarding on `sizeof()` of the exploded result before
   indexing, returning an empty colour tag (`""`) when the theme's
   colour string is empty -- matches the evident intent of the `none`
   theme (no colour codes at all). Verified live: after the fix and a
   driver restart, a brand-new character's very first `s` press in
   the account menu renders the character table correctly with no
   crash.
4. **Stale path reference after spacemud's own `domains/std/`
   reorganization**: `domains/std/school/R/object01.lpc`/`object02.lpc`
   (tutorial rooms) still referenced `"/domains/std/map"` in their
   `set_objects()` mappings, but spacemud moved this object (along
   with a whole batch of other generic props -- `backpack`, `candle`,
   `dead_adventurer`, `dock`, `gate`, etc.) into a new `domains/std/
   object/` subdirectory that doesn't exist in stock Lima. Grepped
   every one of the ~19 relocated object basenames against the whole
   tree; `map` was the only one with a stale reference (the others
   were all updated correctly during whatever refactor moved them).
   Fixed both references to `"/domains/std/object/map"`. This is the
   same *shape* of bug AGENTS.md §7.159 already catalogs (a directory
   reorganization leaving one reference pointing at the old location),
   just a different concrete instance.
5. **Two American/British spelling typos in new content**:
   `domains/std/guild/yakitori/armor/uniform.lpc` (a real, new item in
   spacemud's own delivery-guild content) had `inherit ARMOR;` (should
   be `ARMOUR` -- this whole codebase, like stock Lima, consistently
   uses the British spelling: `include/mudlib.h`'s `#define ARMOUR
   "/std/armour"`, `std/armour.lpc`, `set_armour_class()`) and, once
   that was fixed, `set_armor_class(10)` in the same file's `setup()`
   (should be `set_armour_class`, the function `std/modules/
   m_damage_sink.lpc` actually defines). Both are one-off typos in a
   single new file, not a corpus-wide pattern -- grepped the whole
   tree for both `set_armor_class`/`inherit ARMOR\b` and found no
   other instances.
6. **A superfluous, non-existent `#include <menu.h>`** blocked two
   real `omega` items outright: `domains/omega/item/control_terminal.
   lpc` and `communication_panel.lpc` both `#include <menu.h>`, but
   this header doesn't exist anywhere in this repo (`libs/lima` DOES
   ship one, defining just `MENU`/`MENU_ITEM` as aliases for `class
   menu`/`class menu_item`) -- and neither file actually uses `MENU`/
   `MENU_ITEM`/`class menu` anywhere (confirmed by grep: the only
   `MENU`-token hits anywhere near player-facing menu objects like
   `ship_nav_menu.lpc` are inside a COMMENTED-OUT line). A pure
   leftover from development, safe to delete outright rather than
   restore the missing header. This cascaded into 5 more room compile
   failures (`w_hall3`, `maint2`, `maint6`, `maint7`, `maint12`, all of
   which `set_objects()` one of these two items) -- all resolved by
   the same one-line fix per file.
7. **A call to a function that was never implemented anywhere**:
   `domains/common/item/electronic_door.lpc`'s `setup()` called
   `set_strength_vs_override(10 + (random(5) * 10))`, but no such
   function is defined ANYWHERE in the codebase (grepped for
   `vs_override`/`override.*strength` corpus-wide: zero other hits).
   The feature it would gate -- an "override electronics" skill/
   command (`cmds/guild/lfe/override.lpc` calls `ob->override_unlock()`/
   `ob->override_failed()` on lockable/turret objects) -- is ALSO
   entirely unimplemented (no `override_unlock()`/`override_failed()`
   defined anywhere either), confirming this is genuinely unfinished,
   never-completed WIP content, not a typo with an obvious intended
   fix. Per AGENTS.md §7.51's precedent (delete calls to a genuinely
   unavailable, non-invented feature rather than guessing at behavior)
   removed the call with an explanatory comment, rather than inventing
   the missing mechanic. This one call was blocking the ENTIRE
   `electronic_door` object from compiling at all (not just the
   override feature), so removing it restores basic door/lock
   functionality for every electronic door in the game.

## 4. Confirmed pre-existing stock-Lima gaps, left alone (same verdict as `libs/lima`'s own onboarding)

A residual ~23-file tail remains in `lpcc_check.sh` after all of the
above (down from an initial 83). Every remaining failure was diffed
directly against `libs/lima/work`'s equivalent file (where one exists)
or checked against `libs/lima/NOTES.md`'s own documented, deliberately-
unfixed gap list -- confirming these are shared stock-Lima content
issues (or in two cases, structurally-identical variants under a
renamed path), not spacemud regressions, and following the SAME
"content/design judgment, don't touch" verdict `libs/lima`'s own
onboarding already reached:

- `std/behaviour/test.lpc` (`inherit` after a global-variable
  declaration -- illegal on this driver) -- byte-identical to
  `libs/lima`'s own copy, an unreachable scratch/test file with no
  inbound references anywhere.
- `std/modules/m_react.lpc` (used by `domains/std/attic/{beavis,
  butthead}.lpc`) -- a genuine pre-existing type bug (`x++` on a
  string) PLUS a same-line-heredoc-start compile error (fixed
  trivially, matching `libs/lima`'s own `troll.lpc` fix, since it's
  safe and correct regardless) that still doesn't fully resolve the
  file because of a SECOND, deeper heredoc issue (the closing `END;`
  marker isn't at column 0) layered on top of the type bug --
  `libs/lima`'s own copy has the identical unfixed state (confirmed:
  `libs/lima/work/std/modules/m_react.lpc`'s `ret = @END object
  actor;` line is untouched there too) and its own NOTES.md explicitly
  dismisses this as "content archival, not on the core-gameplay
  path" since `beavis`/`butthead` are two easter-egg NPCs, unreferenced
  by anything reachable in either lib.
- `WWW/cgi/{autodoc,mudinfo}.lpc` -- byte-identical to `libs/lima`'s
  own copies (a heredoc-end-not-at-column-0 issue and a `mixed array
  data;` old-style array declaration respectively, both AGENTS.md-
  catalogued classes); `http_d` (the only daemon that would ever load
  these) is commented out in `data/config/preload` in both libs.
- `obj/secure/mailers/{mailer,Mh,standard}.lpc` -- byte-identical
  logic to `libs/lima`'s own copies (a missing `trim_spaces()`
  function plus a "functional using a local variable" driver
  restriction); `libs/lima/NOTES.md` explicitly dismisses fixing this
  as guessing at unwritten behavior rather than a clear typo fix.
- `secure/daemons/ftp_d.lpc` -- byte-identical "functional using a
  local variable" issue to `libs/lima`'s own copy; `ftp_d` isn't in
  either lib's default preload list.
- `contrib/{bboard,marriage,roommaker,transient_effect}/*` -- the
  archive's own `contrib/` (optional/contributed extensions,
  byte-identical to `libs/lima`'s copies for every file checked,
  including `contrib/marriage/finger_d.lpc`'s well-known missing
  `class finger` `spouse` member). `contrib/bboard/news_d.lpc`'s
  runtime `*Permission denied: /data/news/news_d.o` and `contrib/
  board.lpc`'s/`contrib/boards/board.lpc`'s missing inherited files
  (`/open/hiccups/bboard`, `/transient_effect`) confirm this content
  was never fully wired up even in the archive it came from.
- `domains/std/room/labyrinth/0,0.lpc` and `domains/std/room/caves/
  Sloping_Tunnel.lpc` -- not present in `libs/lima` under these exact
  paths, but structurally the same "incomplete tutorial-area content"
  class `libs/lima/NOTES.md` already calls out generically for
  `domains/std/school/`/`domains/std/rooms/{caves,labyrinth}`
  (referencing a nonexistent sibling room / an undefined
  `set_default_exit()` helper respectively) -- i.e. the SAME
  never-finished demo content class, just spacemud's own copy of it.
- `domains/std/object/portable_board.lpc` -- `inherit BOARD_OB;` where
  `BOARD_OB` is never defined as a macro anywhere; byte-identical bug
  to `libs/lima/work/domains/std/objects/portable_board.lpc` (note the
  path itself changed from `objects/` to `object/` in spacemud's own
  reorg, same as the `map.lpc` case in §3.4 above, but this ONE
  reference was never going to resolve either way since the target
  macro doesn't exist in either lib).

## 5. On-sight checklist (§2.2) results

- `secure/master.lpc` has real `load_object()`/`valid_override()`
  implementations (a proper capability-based master, not a from-
  scratch stub) -- no `get_root_uid()`/`get_bb_uid()` (intentional,
  see `libs/lima/NOTES.md`'s architecture writeup: this whole mudlib
  family doesn't use the uid security model at all).
  `valid_override()` already uses the 3-arg signature.
- No hardcoded `MUD_PORT`/`PORTNO`, no `shutdown`/`rm()`/`unlink()` in
  the security daemon outside `valid_*` checks.
- No `private`/`nomask` `command_hook` issues, no bare `array`
  declarations (confirmed corpus-wide, see §0), no `switch { default:
  }` grammar-strictness hits, no `efun::set/query/delete()` legacy-uid
  calls.
- `ed_start()`/`ed_cmd()` used by `trans/cmds/{locate,grep,replace}.lpc`
  -- fine under this build's `#undef OLD_ED` (same as `libs/lima`).

## 6. Playthrough verification

Full registration-to-gameplay round trip run live against
`~/src/fluffos-lima/build-debug/src/driver` via `scripts/mudclient.py`
(a raw scriptable telnet client, more reliable for pacing than
`tmux_mud.sh` for this many sequential prompts):

1. Fresh account registration: name (`Is 'X' correct?` confirmation,
   alphabetic-only name validation confirmed both accept and reject
   paths), password (5+ chars, confirmed twice, mismatch-retry path
   not separately re-tested but code-reviewed), gender/email/real
   name/homepage/referral question sequence (all six matching
   `libs/lima`'s own documented flow).
2. Character creation via the account menu's `c` (spacemud's own
   bespoke `Spacemud User Menu`, not stock Lima's `obj/usermenu/
   usermenu.lpc` menu chrome, though it reuses the same underlying
   `create_char()`/`select_char()` logic): character name, gender
   (1/2/3 numeric menu), race (typed name, both a rejected `1` numeric
   guess and an accepted `human` verified).
3. `s` (select character) -- reproduced the §7.167b crash on the
   FIRST test run (before the `m_frame.lpc` fix was live), then
   re-verified clean on a fresh character after the fix + driver
   restart.
4. `p` (enter game) -- lands in the Grand Hall (Lima's own
   wizard-guild start room; first character gets `AUTO_WIZ`'d per
   Lima's documented, intentional behaviour, exactly as `libs/lima`
   itself does).
5. `look`/`score`/`inventory`/`who` -- all correct (ASCII-art frames
   render properly with a real xterm-negotiating... actually
   NON-negotiating raw client, confirming the `none`-theme fix handles
   the no-colour path correctly end-to-end, not just in isolation).
6. `goto /domains/omega/room/floor1/wakeup_room` (admin teleport, used
   deliberately to reach the space-themed content directly rather than
   walking the whole Lima demo map first) -- lands in "A small recovery
   room" with the space-station framing text and an NPC (Dr. Green).
   `open door` + `south` successfully moves into "North Hallway" (one
   of the `method_d`-gated complex exits -- exercises the §7.166 fix
   live), then further `south`/`south` through two more maintenance
   corridor rooms, all rendering correctly with zero errors in
   `log/runtime`.
7. `goto /domains/std/school/R/chainmail01` (the armour-building
   tutorial room) -- `get chainmail shirt` + `salvage chainmail shirt`
   correctly yields "You salvage a copper scrap, a lead scrap, and a
   steel scrap from the chainmail shirt." (exercises the §7.167a
   crafting_d fix live, end to end).
8. `quit` -- clean, `[announce]` channel correctly broadcasts the
   departure, returns to the account menu (Lima's own quit semantics:
   returns to account menu rather than a full disconnect).

`log/runtime` and `log/catch` are empty after this whole session (the
only entries logged during the WHOLE onboarding process were the ones
diagnosed and fixed above, plus the residual §4 stock-Lima gaps
surfaced by `RST_D`'s own one-time boot-time documentation scan, which
is cosmetic and doesn't affect gameplay).

**Committed save state cleanup**: the verification pass above used a
throwaway account (whose character happened to be the first ever
entered into the game, and so was auto-promoted to admin per
`sw_body.lpc`'s `sw_body_handle_new_logon()` -- admin status is
tracked via `secure_d`'s own persisted `domainlists`/`domains` data,
keyed on account userid, not simply "the very first character ever
created"). Before committing, all of that throwaway account/character/
shell-state data (`data/{links,players,wshells}/*/*.o`) and `secure_d`'s
own accumulated privilege state (`data/secure/{access,access_backup}.o`,
which has no shipped default in the raw archive -- it's entirely
runtime-generated on first boot) were deleted and the driver restarted
clean, then ONE canonical `fluffos`/`Mud12345` account was registered
from scratch through the full flow end to end (confirming, again, that
the §7.167b character-select fix holds and that a truly fresh
`secure_d` state correctly re-grants admin to this first-ever
character) -- matching `libs/lima`'s and `libs/wilderness`'s own
`fluffos` admin-seed convention. The other daemon-level save files
generated during testing (`data/daemons/{crafting,method,space,
messages,damage,help,imud,last_login,rst}.o`, `data/secure/daemons/
user.o`, `data/news/*`, `data/referrals`) carry no player-identifying
data and are the correct, fixed, first-boot-generated state (the
whole point of the §7.166/§7.167a fixes above) -- left in place rather
than deleted.

WASM status: not attempted this session (native-only, matching this
session's scope) -- would need the same `emcmake`-plus-`local_options`
treatment `libs/lima`'s own WASM pass would need, left as future work.
