# immaster -- porting notes

Source: `git clone https://github.com/flyinrookie/immaster` (commit `43382dc`,
July 2020, last commit "modify notes"). The upstream README describes it
plainly: "Ongoing building of the mudlib, as a learning project." It is a
real, from-scratch Chinese LPC tutorial/learning project, genuinely new to
this collection (not a duplicate of any existing lib).

## 0. Not a standalone mudlib -- a thin content layer on a pinned engine

immaster's own `README.md` is explicit that it is built on "MudCore" (a
separate, actively-developed FluffOS-native engine framework,
<https://github.com/oiuv/mudcore>) via two `git submodule`s declared in
`.gitmodules` (`ext/mudcore` and a stale unused duplicate `engine/mudcore`
entry, plus `ext/www`/`engine/www` for a browser terminal client). Every
`#define` in immaster's own `system/include/globals.h`
(`MASTER_OB`/`LOGIN_D`/`COMMAND_D`/`ROOM`/etc.) resolves to a one-line
`inherit CORE_X;` wrapper file that points at the matching MudCore object
(`CORE_MASTER_OB` etc., defined in MudCore's own `include/mudcore.h`).
Without MudCore, `system/core/kernel/master.lpc`'s `inherit CORE_MASTER_OB;`
alone fails to resolve and nothing compiles. **This is a required build
dependency, not optional bundled content** -- unlike `imud`'s optional-only
Intermud-3 extension modules (AGENTS.md §2.3), immaster's entire engine
(login/registration, save/restore, movement, command dispatch, wizard
tools, combat/chat/database/time-of-day/virtual-object daemons) lives
in MudCore, not in immaster itself.

`git ls-tree` on immaster's own commit records the exact pinned submodule
commit: `ext/mudcore` -> `88d5d3a6db7054f4934a6bb3dc753c5cc295e595`
(May 2020, close in time to immaster's own last commit -- a compatible,
contemporaneous snapshot, not whatever MudCore looks like today; the live
MudCore repo has moved on substantially through 2025 and was NOT used).
That exact commit was fetched from MudCore's real git history and merged
into this lib's `work/ext/mudcore/` tree, exactly as `git submodule
update` would have produced. `ext/www` (a static HTML/JS xterm.js browser
client pinned to `513af2e`, MudRen/www) was deliberately **not** included:
it is plain browser-side JS/CSS, not LPC, contributes nothing to the
driver-side mudlib, and is unrelated to the raw-socket verification this
project uses -- immaster's own README calls it optional ("using the web
client included in ext/www can access the game from browser").
`.gitmodules` itself was removed from `work/` (no real submodules exist
in this project's flat `work/` layout, and it referenced the stale
duplicate `engine/`-prefixed paths that were never populated).

`config.example.ini`'s `websocket http dir : www` / `external_port_1 :
websocket 8000` (a second, browser-facing listen port MudCore optionally
supports, backed by `include/mysql.h`... no, by `ext/www`) was likewise
not configured -- this project's `config.fluffos` opens a single plain
telnet port, matching every other lib in this collection.

## 0.5 One filename-level tooling fix (not a driver-compat fix)

`doc/notes/driver工作流程.md` (a Chinese-language *filename*, not just
content) was renamed to `doc/notes/driver-workflow-notes.md`. This is
unrelated to the LPC/driver conversion -- the file compiles/loads nothing,
it's plain documentation -- but this project's own `git`-based tooling
(`scripts/safe_commit_batch.sh`'s owned-path check, which reads `git diff
--cached --name-only`) breaks on a non-ASCII filename because `git`
octal-escapes it by default (`core.quotePath`), producing a string that
no longer starts with the literal `libs/<slug>/` prefix the script checks
for. Renaming the one offending file sidesteps this cleanly without
touching the shared script. Its content (in Chinese) was left untouched.

## 1. Conversion

Pure-ASCII/UTF-8 archive already (GitHub-native, written directly in
UTF-8) -- confirmed by `convert_lib.sh`: 192/211 files already valid
UTF-8, 19 correctly skipped as genuinely binary (map JPG/SVG images under
`doc/map/`), **zero** lossy conversions. 128 files renamed `.c`->`.lpc`.

**Critical: the `.c`->`.lpc` rename hit the §7.118 `file_size(X+".c")`
gate-check bug family in 6 separate MudCore engine sites**, all
auto-fixed by `convert_lib.sh`'s own literal-`.c"`-reference sed pass
(confirmed by direct inspection before ever running `lpcc`, matching the
`dreamofseven` precedent in AGENTS.md's bug catalog):

- **`ext/mudcore/system/daemons/command_d.lpc`'s `find_command()`** --
  the function EVERY player command (and every wizard command) resolves
  through: `if (file_size(p + verb + ".c") > 0 && objectp(file =
  load_object(p + verb))) return file;`. Pre-fix, this would have
  returned 0 for literally every verb after the rename -- an "every
  command fails silently" bug with zero compile errors, the single
  highest-severity finding in this port (same shape/severity as
  `sunshadow`'s command-dispatch corruption in the AGENTS.md catalog,
  though the root cause here is a wrong-extension gate rather than
  slice arithmetic). Verified fixed: `sed` correctly produced
  `file_size(p + verb + ".lpc")`, and a live boot's `find_command`
  cleanly resolves `look`/`go`/`say`/`help`/`test`/`quit` and (for the
  wizard account) `eval`/`whoami`.
- **`ext/mudcore/system/kernel/master/preload.lpc`'s `preload()`** --
  gated every preload attempt the same way (`file_size(file + ".c") ==
  -1`); confirmed fixed and confirmed live (the boot log shows all ten
  daemons -- login_d, channel_d, char_d, chinese_d, combat_d, dbase_d,
  emote_d, time_d, nature_d, virtual_d -- preloading in order).
- **`ext/mudcore/system/daemons/virtual_d.lpc`'s `compile_area()`/
  `compile_mob()`** (2 sites) -- virtual-object/maze room resolution,
  called from `master.lpc`'s `compile_object()` apply. Not exercised by
  this archive's content (no virtual/maze rooms are actually used
  anywhere in `game/world/tutorial/`), but fixed for correctness/
  consistency with the rest of the sweep.
- **`ext/mudcore/system/daemons/dbase_d.lpc`'s
  `cleanup_all_save_object()`** -- a save-dbase garbage-collection helper
  (`file_size(e[i] + ".c") < 0`); also fixed.
- **`ext/mudcore/inherit/vrm.lpc`'s `set_inherit_room()`** (2 sites,
  `file_size(sprintf("%s.c", ...))`) -- part of the same virtual random
  maze (VRM) feature as `virtual_d.lpc` above; not used by this archive's
  content, fixed for consistency.

Also auto-fixed by the same sed pass: `master.lpc`'s own `#include
"master/error.c"` / `"master/valid.c"` / `"master/preload.c"` (raw
C-preprocessor `#include` of what are themselves `.c`-turned-`.lpc`
files) and `simul_efun.lpc`'s equivalent 14-file `#include` chain -- all
16 literal `.c"` references correctly became `.lpc"`.

One additional non-gate `.c`->`.lpc` reference was auto-fixed as a side
effect and is harmless/cosmetically-correct either way:
`simul_efun/path.lpc`'s `resolve_path("here")` branch used to return
`file_name(environment(this_player())) + ".c"` (a cosmetic path label for
a wizard `cd here`-style shell helper, never itself used as a
`file_size()`/`load_object()` argument); it now returns `+ ".lpc"`
instead, which is if anything more accurate post-rename.

Zero manual `static`->`nosave`/`protected` collisions (the codebase
already uses `nosave`/`private`/`protected`/`nomask` natively -- zero raw
`static` keyword occurrences anywhere in the tree, matching a codebase
written directly against a modern `__SENSIBLE_MODIFIERS__` driver).

## 2. `lpcc_check.sh`: 127/128 pass

Followed the mandatory §10.4 discipline given the fresh, previously-
unverified MudCore engine merge: compiled all 25 MudCore/immaster base
classes (`master`, `simul_efun`, all 16 `inherit/*`, all 4 `std/room/*`,
both `std/living/*`, `login`/`user`/`void`) individually first -- all 25
passed clean -- before running the one full batch sweep. RSS stayed
trivial throughout (a ~3.8MB combined tree); no memory concern
materialized.

The one failure, `/system/core/daemons/nature_d.core` (note the unusual
`.core` in the filename, not a typo introduced by this port -- it exists
verbatim in the upstream git history, added by commit `61cddc2 nature_d`
and never renamed despite a later commit literally titled `23e3192 fix
time_d file name`), is a **genuine pre-existing dead-code/content gap in
the original archive, not a conversion regression**:

- `grep -rn "nature_d.core"` across the entire tree returns zero hits
  outside the file itself -- nothing `inherit`s it, `#include`s it, or
  `call_other()`s it. The live daemon MudCore/immaster actually use is
  the adjacent, correctly-named, correctly-functioning
  `system/core/daemons/nature_d.lpc` (a one-line `inherit CORE_NATURE_D;`
  wrapper, confirmed loading cleanly in every boot's preload sequence).
  `nature_d.core.lpc` is orphaned scaffolding left over from whatever the
  original author was iterating on -- confirmed by MudCore's own docs
  (`ext/mudcore/docs/daemons/*.md`) describing the CORE_NATURE_D
  day/night-cycle feature abstractly, with no mention of this file.
- Its actual failure (isolated via a direct single-file `lpcc` run,
  since the batch harness's terse "Fail to load object" gives no detail
  on its own) is a **runtime** error in `create()`, not a compile error:
  `read_table(NATURE_DIR "day_phase")` calls `explode(read_file(file),
  "\n")`, and `read_file()` returns 0 because
  `system/core/etc/nature/day_phase` -- the data table the day/night
  flavor-text system is supposed to read -- was never actually shipped
  anywhere in the archive (`system/core/etc/` contains only `motd`).
  `explode(0, "\n")` then throws `Bad argument 1 to explode(): Expected
  string, Got 0`, which is why the object fails to load at all. This is
  a genuine authoring gap in the shipped repo (missing data file +
  orphaned/never-inherited scaffolding file), not a driver-compat issue,
  and per this project's standing rule against inventing content, no
  `day_phase` data file was fabricated and the dead file was left as-is.

## 3. Boot and live verification

Booted `~/src/fluffos/build-debug/src/driver` against `config.fluffos`
repeatedly with `Initializations complete.` and all ten daemons
preloading cleanly every time. `__USE_MYSQL__` is defined in this build,
and the shipped `mysql.h`/`valid_database()` apply reference a
(fake, placeholder) local DB credential set, but **no code anywhere in
either immaster or MudCore actually calls `db_connect()`/`db_exec()`/any
`db_*` efun** -- confirmed by a whole-tree grep -- so this is completely
inert; the mysql package being compiled into the driver never gets
exercised.

Raw Python socket sessions (this project's preferred verification
method) confirmed the full, real registration/login flow: connecting
prompts for GBK-encoding preference (answered `n`, since this archive's
`is_chinese()`/`is_english()` are already Unicode-codepoint-aware --
`pcre_match(str, "^\\p{Han}+$")` and a plain a-z/A-Z range check
respectively, not GBK-byte range tests, so none of the classic §8.1
byte-range bugs apply here at all), an English-letters-only login ID
(digits are rejected by `is_english()` -- confirmed this is the archive's
own intentional design, not a bug: a purely-numeric or alphanumeric ID
loops back to re-prompt rather than crashing), new-account confirmation,
a 2-10 character pure-Chinese character name (`is_chinese()`), a
password + confirmation (`crypt()`-hashed), and a gender choice --
landing the new character in the real `game/world/tutorial/start_room`
with correct room text and exits. Verified further: `look`, movement
(`south` from the start room correctly reaches `courtyard`, matching the
room's own `set("exits", ...)`), `say`, `help` (falls back to
`game/help/tutorial`'s real static help text when given no argument, per
`system/cmds/player/help.lpc`'s own default), the archive's own `test`
command (`system/cmds/player/test.lpc`, prints a literal placeholder
string -- clearly a scaffolding command the author left in, not
something this port added or should remove), and a clean `quit`.

**Save/restore verified across a real driver restart** (per the AGENTS.md
§7.120 lesson that a single continuous session can mask a save-integrity
bug): killed the driver, restarted it fresh, reconnected with the same
account ID and password -- password check and `restore()` both succeeded
and the character reappeared in the correct room with its saved state
intact.

**Wizard/admin access is account-name-based, not seeded separately**:
MudCore's `inherit/command.c`'s `enable_living()` grants
`enable_wizard()` unconditionally to any connecting account whose
`getuid()` equals the hardcoded constant `WIZARD` (immaster's
`globals.h` sets this to `"teamug"`, overriding MudCore's own default
`"mudren"`). Registering a new account with the login ID `teamug`
was confirmed live to grant working wizard commands (`eval`, `whoami`,
and by extension the rest of `ext/mudcore/cmds/wizard/*` --
`update`/`dump`/`get_dir`/`call_other`/etc.) with no other setup step.
This plays the same functional role as this project's usual §1.5
admin-account seeding, just via a fixed reserved username rather than a
config file or database row -- there is nothing further to seed.

## 4. No outbound network

Grepped the whole tree (immaster + the merged MudCore engine) for
`socket_create`/`socket_connect`/`socket_bind`/`socket_listen`/
`socket_accept`/`external_start`/`dns_master`/`intermud`: zero hits.
`HTTP_PORT`/MudCore's optional websocket listen port is inbound-only (a
second local listen socket for the bundled browser client, which this
port doesn't configure or need) and was not enabled in `config.fluffos`.
This is a fully offline, sandboxed archive like the overwhelming majority
of this collection.

## 5. Scope: a genuinely thin tutorial map, by design (imud/lil precedent)

Per AGENTS.md §2.3's precedent (`imud`) and the parallel `lil` case: a
thin surface here is the archive working as designed, not a conversion
failure. `game/world/tutorial/` ships ~12 connected outdoor/indoor rooms
(start room, courtyard, backyard, forest, stream, waterfall, cave +
cave entrance, tomb, cliff, treehouse, two trail segments) with real,
polished Chinese room descriptions and a coherent map (see
`doc/map/tutorial/TutorialArea.{jpg,svg}`, kept as reference images) --
but genuinely no NPCs, no items, and no combat content anywhere in this
specific archive. This is not a missing-content bug: `STD_NPC`/`STD_MOB`
(immaster's own room/living templates, wired up correctly in
`system/include/stdob.h`) are never referenced by any file in
`game/world/`, and MudCore's own combat/char/virtual-object daemons all
compile and preload cleanly despite having nothing in this specific
lib's content to act on. immaster's own README frames the whole project
as "ongoing" ("正在建设中" in spirit) -- ended, per its git history, after
about 6 weeks of active commits in mid-2020. Documented here explicitly,
per the standing project rule, so a future re-check doesn't mistake
"just rooms to explore, nothing to fight or pick up" for a bug needing a
fix: it is this archive's real, final, intentionally-thin state.
