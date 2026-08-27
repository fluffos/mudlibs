# ds-hakkard ("Hakkard World") -- porting notes

Source: `git clone https://github.com/hakkard-dev-team/ds-hakkard`
(commit `06cb87d3cf026ec393cb40969ab14e2426df7f7b`, cloned 2026-08-26).
A prior research pass already confirmed this is genuinely distinct
content, not a duplicate of any lib already in this collection, so this
session went straight to a full onboarding pipeline. Repo top level:
`README.txt`, `UNIX_INSTRUCTIONS.txt`/`WINDOWS_INSTRUCTIONS.txt`,
`License.txt`, `bin/` (driver-config scaffolding, ignored -- this
project uses its own driver), `extra/` (build scaffolding, ignored),
`lib/` (the real mudlib root). Slug `dshakkard`, number 185, port
40230.

## 1. The real finding: this is a ds386-based GAME, not a distinct Dead Souls release -- and its engine layer was never committed to git

The task brief (based on domain-name overlap with `dsII`) suggested
checking `dsII`/`dsIII`'s fix catalog first. That produced a more
specific and more important finding: **this repo's engine is
`ds386`/`deadsouls_fluffos` (Dead Souls 3.8.6), not `dsII`**, and the
repo **never once committed its `secure/` directory, or its top-level
`log`/`save` directories, to git history at all**.

- `README.txt`'s banner ("The Dead Souls 2 Mud Library / Released
  December 2005... This document last updated: 28 Jan 2008") is the
  exact same stale placeholder text `dsIII`'s NOTES.md already flagged
  as predating that archive's real content -- not evidence this is
  actually a 2006 "Dead Souls II" release.
- **Domain roster is the real signal**: `lib/domains/` has `campus`,
  `cave`, `default`, `examples`, `learning`, `Praxis`, `town`, `Ylsrim`
  -- exactly `ds386`'s 9 domains minus `amigara` -- plus three genuinely
  bespoke domains, `lennar`, `lennarmanor`, `northernwastes` (a custom
  fantasy setting: manor rooms, NPCs, a shared `virtual/` room-server
  trio). `dsII` only ever had 4 domains (`campus`, `default`, `town`,
  `Ylsrim`) and never had `cave`/`examples`/`Praxis`/`learning` at all
  -- those are exclusively `ds386`-generation content.
- **Directory-layout match**: `lib/`'s own top-level dirs (`cfg cmds
  daemon doc domains estates ftp include lib log news obj open powers
  realms save shadows std tmp verbs www`, plus a gitignored `secure`)
  are the exact same set as `ds386`'s raw archive at the same level.
- **Byte-level match on shared files**: `lib/daemon/command.c` (the
  command-dispatch table) is byte-identical to `ds386`'s raw
  `daemon/command.c` except for the exact two bugs `ds386`'s own port
  already found and fixed there (`static`->`nosave`, and the
  `file[0..<3]` slice-arithmetic bug). `lib/include/*.h` (32 files) is
  an exact filename-set match to `ds386`'s own top-level `include/`.
- **The `secure/` gap**: `.gitignore` contains exactly `lib/secure`,
  `lib/save`, `lib/log`, `fluffos-2.23-ds03/`, `*.bak`. `git log --all
  --oneline -- lib/secure` returns **zero commits, ever** -- this
  directory (containing `secure/daemon/master.lpc`, the whole
  `PACKAGE_UIDS` master-apply layer, `secure/sefun/sefun.lpc`, the
  admin-installer, etc.) is not recoverable from this public repo by
  any means (no tag, no branch, no reflog-adjacent commit touches it).
  Likewise the top-level `log`/`save` runtime directories were never
  committed.

This is best understood as: the `hakkard-dev-team` built their game's
custom domains and top-level content on top of a private/shared copy of
the stock Dead Souls 3.8.6 engine, and only ever published the
game-specific layer to this public repo -- the engine's `secure/`
scaffolding (and the empty runtime `log`/`save` dirs) were deliberately
or incidentally excluded via `.gitignore` and never appear anywhere in
this repository's history.

### 1.1 Filling the gap: sourcing `secure/` from `ds386`, verified file-by-file

Since `ds386` (already onboarded in this collection, already fully
driver-compat-fixed) is confirmed byte-identical to this repo wherever
they overlap, its raw `secure/` tree is the correct substitute --
supplying the SAME engine version this game was actually built against,
not inventing new content. Before trusting this, every `/secure/*` path
literally referenced anywhere in ds-hakkard's own non-secure code was
checked for existence in `ds386`'s `secure/`: of 34 distinct references,
only 4 didn't resolve, and all 4 are benign:

- `/secure/lib/net/ftp.c` -- only appears in `doc/old/CHANGES`
  (historical prose), not real code.
- `/secure/obj/roommaker` -- the one real reference
  (`domains/town/obj/chest.c:18`) is commented out.
- `/secure/obj/txt/spam.txt` -- read via `unguarded((: read_file(...)
  :))`, which returns `0` gracefully on a missing file; a genuine but
  harmless pre-existing content gap (this text file was never shipped
  in either archive), left undone.
- `/secure/save/users/d/descartes` -- only appears in doc-comment prose
  (`Example: SetMenuItems(...)`), not real code.

`raw/ds-hakkard/secure` was built as `ds386`'s raw
`secure/` copied in wholesale, then run through this project's own
`convert_lib.sh` alongside the rest of the tree so the whole `work/`
copy gets one consistent encoding/rename/`static`->`nosave` pass. The
resulting `work/secure` was then wholesale-replaced with `ds386`'s own
**already driver-compat-fixed** `work/secure` (confirmed byte-identical
raw source first via `diff -rq`), reusing that entire fix catalog for
free rather than re-deriving it:

- Missing `get_root_uid()`/`get_bb_uid()`/`creator_file()` master
  applies, `log_error()`-during-compile recursion guard (also found a
  second, ds-hakkard-specific instance of this same pattern class via
  `secure/sefun/timestamp.lpc`'s `TIME_D` call, already fixed in the
  synced copy),
- the stale `runtime_config.h` slot-numbering fix,
- `OLD_ED` vs. split editor API (`lib/editor.lpc`+
  `secure/cmds/creators/lsed.lpc` full rewrites),
- `__DIR__`/`__FLUFFOS__` macro collisions (`sconv.lpc`),
- `LIB_REMOTE` path fix,
- `SetLong`/`SetExternalDesc`/`SetInternalDesc` widened to
  `mixed`/`mixed *`,
- `daemon/books.lpc`'s mapping-vs-array mismatch,
- `domains/Praxis/supply2.lpc`'s `set_pre_exit_functions()` comment-out
  (ds-hakkard's own copy of this file differs from `ds386`'s only in
  `shop_long()`'s indentation -- the buggy call itself is untouched, so
  the identical fix/comment was applied here too).

**Two runtime-state directories under `secure/` needed care**: `ds386`'s
own `work/secure/{save,log,tmp}` are NOT pristine -- they carry `ds386`'s
own accumulated test-boot output (a populated Intermud `MudList` cache
in `save/mudinfo.o`, `ds386`'s own player/creator saves, etc.). These
three subtrees were rebuilt from the pristine RAW `secure/{save,log,tmp}`
(re-verified as pure ASCII, no encoding fixes needed) instead of copied
from `ds386`'s polluted `work/` copy, so ds-hakkard's committed state
reflects only this session's own fresh test boot, not `ds386`'s.

**A second, subtler instance of the same problem: `secure/lib/connect.lpc`
had already self-swapped.** `ds386`'s own admin-install test already
consumed its one-time installer -- `secure/lib/connect.lpc` in `ds386`'s
`work/` is no longer the 6,652-byte installer, it's the 30,913-byte
ongoing-login object (`connect.real`'s content), with the original
installer preserved alongside as `connect.first.lpc`. Copying `ds386`'s
`work/secure` wholesale therefore ALSO copied this post-install swap,
which silently broke the first-boot admin wizard test (a first attempt
produced an ordinary player account, not an admin, since the "installer"
being served was actually the normal registration flow). Fixed by
restoring `secure/lib/connect.lpc` from the still-present, still-correctly
-fixed `connect.first.lpc` before live-testing. `secure/cfg/groups.cfg`
and `secure/include/config.h`'s `DEBUGGER` define had the same
issue for the same reason (both already said `fluffos`, `ds386`'s own
installed admin name, instead of the `ADMIN`/`DEBUG_NAME` placeholder
tokens the raw archive ships) -- restored from the pristine raw values
before testing, then correctly re-populated by ds-hakkard's own,
freshly-run installer.

## 2. Conversion

`scripts/convert_lib.sh` against the combined `raw/ds-hakkard` tree
(ds-hakkard's own non-secure `lib/` plus the substituted `secure/`,
4,656 files): 4,622/4,656 already valid UTF-8, 2 clean re-conversions,
5 lossy (all in files shared byte-identically with `ds386`, whose own
already-fixed versions were copied in directly rather than re-deriving
the same Latin-1/mixed-encoding fixes: `doc/CREDITS`, `doc/help/players/
credits`, `domains/town/txt/mystery.txt`, `secure/sefun/translate.lpc`'s
mixed Latin-1/UTF-8 `FLUBS` curse-word array, `secure/save/functions.o`
deleted as a stale cache and regenerated fresh on first boot -- same
precedent as `ds386`/`dsIII`). 2,363 `.c` files renamed to `.lpc`, 1,490
files touched by the `static`->`nosave` sweep.

A whole-tree sync pass (custom Python script, not part of
`convert_lib.sh`) then compared every non-secure raw file against
`ds386`'s raw archive at the same relative path: **3,749 files were
byte-identical** and got `ds386`'s own already-fixed `work/` content
copied in directly; 257 files differ from `ds386` (ds-hakkard's own
customizations to shared stock files) and 82 exist only in ds-hakkard
(the bespoke domains plus a builder's personal realm, `realms/muirrum`)
-- these 339 files needed the fixes below applied fresh.

## 3. Driver-compat fixes applied to ds-hakkard's own (non-synced) files

### 3.1 Old-MudOS `TYPE array NAME` dialect (28 files, 109 sites)

Wrote a masked-text (string/comment-aware) Python regex fixer handling
the same shapes `dsII`/`dsIII` documented: single/multi-name
declarators, bare `array`, `class TYPENAME array NAME`, cast forms,
function return types. **Caught a real bug in the first draft before
trusting it on the whole tree**: the multi-name-list parser didn't
distinguish a genuine same-type comma list (`string array a, b;`) from
a FUNCTION PARAMETER LIST where a comma introduces a brand-new type
(`string array guilds, string other_param`) -- it mis-fired and
produced syntactically broken output (`string *guilds,*string
other_param`) on a test file. Fixed by peeking past each comma for a
new type-keyword before treating it as a continuation name; re-verified
against a battery of the exact shapes `dsIII`'s own session had to
hand-fix (function params, `class TYPENAME array Func()`, bare-array
return types, multi-name lists with a default value) before running it
for real. Ran clean: 28 files, 109 sites, including a real un-starred
`string oldparties = PARTY_D->GetOldParties();` bug in `lib/player.lpc`
(should be `string *oldparties` -- confirmed present byte-identically
in `ds386`'s own raw archive too, fixed the same way `ds386`'s own port
fixed it) and `lib/std/room.lpc`'s `SetLong()` wrapper (same too-narrow
`string`-only declaration `ds386`'s port widened, needed again here
since this file is one of ds-hakkard's own customized copies).

### 3.2 `OLD_ED` gaps in ds-hakkard's own customized files

`lib/nmsh.lpc` (a "differing" file) still called the undefined
`query_ed_mode()`; `lib/interactive.lpc` (also "differing") still
called the undefined `ed_cmd()` three times in its quit-path cleanup.
Both are the exact same OLD_ED-vs-split-editor-API bug `ds386`'s own
port already solved in its stock copies of these two files (confirmed
via `diff` that the surrounding code is otherwise identical) -- applied
`ds386`'s exact fixes: `nmsh.lpc`'s custom-prompt branch collapsed to
`if(0){...}` dead code, `interactive.lpc`'s three `ed_cmd()` calls
removed (the driver's own `destruct_object()` already calls
`save_ed_buffer()` automatically for a live `ed_buffer` under `OLD_ED`,
so this was only ever a redundant manual save).

### 3.3 `#define __DIR__` collisions in the bespoke domains

`domains/{lennar,lennarmanor,northernwastes}/virtual/{void,server}.lpc`
(6 files total, all new to this repo, not present in `ds386` at all)
had the old manual `#define __DIR__ "..."` idiom this driver's native
`__DIR__` predefine collides with. Removed all 6; the native value is
identical.

### 3.4 `domains/Praxis/supply2.lpc`

Covered in \S1.1 above -- same `set_pre_exit_functions()` comment-out
fix as `ds386`, applied to ds-hakkard's own slightly-reindented copy of
this file.

## 4. Missing runtime scaffolding: TWO gitignored directories the lpcc batch sweep exposed as cascading false failures

`secure/` wasn't the only gitignored gap. This repo's `.gitignore` also
excludes the top-level `lib/log` and `lib/save` directories (the
driver's configured `log directory : /log` and the non-secure daemons'
save location) -- **neither exists anywhere in this repo's git
history either**, and their absence has a much nastier effect than a
missing engine directory: `secure/daemon/master.lpc`'s own
`log_error()`/`error_handler()` machinery tries to write compile
warnings and runtime backtraces to `/log/catch`/`/log/runtime`, and
when that write itself fails with "No such file or directory", the
resulting SECOND error recurses through the same handler and corrupts
the diagnostic output for whatever ordinary file triggered the first
warning. This silently miscategorized roughly 35 files with nothing
worse than a harmless "Illegal to declare nosave function" or
"Redeclaration of global variable" warning (the exact same
isolated-compile-warning artifact class `ds386`/`dsIII` already
documented) as full batch-compile FAILures, and masked several files'
REAL underlying errors entirely (`daemon/stargate.lpc`, `obj/book.lpc`,
and every stargate-instance object in every domain were actually
failing because `daemon/stargate.lpc`'s `create()` tries to
`SaveObject()` to `/save/stargate.o`, which also didn't exist).

Fixed by creating both directories (`mkdir -p`) with the same
subdirectory skeleton `ds386`'s own `work/log`/`work/secure/log` use
(`errors/<every top-level dir>`, `chan`, `router`, `adm`, `archive`,
`watch`, `imc2_server`, `secure`, `reports`, `law/*`), then re-running
the full batch sweep, which dropped the failure count from 43 to 10
purely from this fix -- **before touching a single line of ds-hakkard's
own code**. Unlike `ds386`'s own committed repo (which commits zero
files under `log/`, meaning a truly fresh checkout of `ds386` would
hit this exact same cascading-failure class again), this port commits
a lightweight `foo.txt` placeholder (the same convention this codebase
itself already uses under `secure/log/{bak,network,adm,intermud}`) in
every otherwise-empty log subdirectory, so a fresh clone of
`libs/dshakkard` boots and compiles cleanly without anyone needing to
manually recreate this scaffolding again.

## 5. Live verification

Booted clean (`Accepting telnet connections on 0.0.0.0:40230.`,
`Initializations complete.`, zero fatal errors).

**Confirmed the same three real outbound network connections at boot
as `ds386`/`dsIII`**:

1. **IMC2** (`secure/daemon/imc2.lpc`, preloaded) -- confirmed live
   (`ss -tnp` showed `ESTABLISHED ... 97.107.133.86:8787`).
2. **Intermud-3** (`daemon/intermud.lpc`, preloaded) -- confirmed live
   (`ss -tnp` showed `SYN-SENT ... 50.116.16.90:5000`).
3. **`secure/daemon/autoexec.lpc`'s automatic dead-souls.net
   RELEASE_NOTES fetch**, one second after boot, zero player
   interaction required -- confirmed live and reproducible on every
   boot (`doc/RELEASE_NOTES_HTTP` freshly rewritten with real, current
   `HTTP/1.1 200 OK` content each time). Reset to the pristine
   originally-shipped copy before every commit in this session, same
   as `dsIII`'s precedent -- a future boot will regenerate it again,
   which is expected. **Do not sweep this lib into high-frequency
   automated re-boot loops.**

Tested with a raw Python socket client (`scripts`-equivalent ad hoc
`mudclient.py`), all required flows in one session, using this
project's standard admin identity (`fluffos`/`Mud@2026`):

1. **First-boot admin installation wizard**
   (`secure/lib/connect.lpc`, pristine installer restored per \S1.1):
   username -> confirm -> "13 years of age or older?" age gate ->
   "screen reader?" prompt (answered `n`) -> password/confirm -> display
   name (default) -> gender -> real name (blank) -> email -- completed
   successfully; the mud self-shut-down as designed (matching
   `ds386`/`dsIII`'s installer behavior). `secure/cfg/groups.cfg` and
   `secure/include/config.h`'s `DEBUGGER` define correctly ended up
   with `fluffos` in place of the `ADMIN`/`DEBUG_NAME` placeholders,
   and the account saved under `secure/save/creators/f/fluffos.o` (a
   real creator, not a player).
2. **Reboot + admin login**: `fluffos`/`Mud@2026` -> arrived in
   `/realms/fluffos/workroom` with wizard robe+hat, `people` showed the
   admin present, `boards` reported pending board messages, `score`
   produced a correct character sheet, `update` (current-room form)
   reported `Ok`, `look`/`quit` both correct.
3. **Ordinary new-player registration** (`Qinhakkard`, an ASCII name --
   this archive enforces the same strict `A-Z a-z ' -` name-charset
   check as `ds386`/`dsIII`, so a real Chinese name is out of scope
   here by the same adapted bar): name -> confirm -> age gate ->
   screen-reader prompt (`n`) -> password/confirm -> gender -> email
   (validated; a blank first attempt correctly rejected and
   re-prompted) -> race selection (`list`/`pick human` -- 8 races,
   identical set to `ds386`/`dsIII`) -> news pages -> landed in "The
   start room" (the `default` domain's entry point, an ASCII-art room
   map) with a correct HP/MP/SP status bar. `look`/`score`/`quit` all
   correct.
4. **Reconnect as the same character**: name -> password -> landed back
   in the same room with inventory intact, `score`/`quit` correct --
   confirms the reconnect path is a distinct, working code path.

2432 of 2440 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep (99.7%); the 8 that don't are broken down in \S6.

## 6. Known pre-existing gaps (not fixed -- content/archive design, not driver-compat)

All of the following match a class already documented on `ds386`/
`dsIII`/`dsII`, confirmed either byte-identical to `ds386`'s own raw
archive or a clearly out-of-scope leftover:

- **`/obj/stargate`**: `#include this is here on purpose to prevent
  this from loading` -- the same deliberate author anti-load trap as
  `ds386`'s identical file.
- **`/open/prog`** and **`/obj/area_room`**: builder-tool scaffolding
  templates never meant to compile standalone in place (written/copied
  by other in-game tools at runtime with placeholders substituted
  later) -- same non-bug class as `ds386`/`dsIII`'s identical files.
- **`/domains/campus/chamber/elevator`**: fails with a "Redeclaration
  of global variable" warning (harmless, same isolated-compile artifact
  `ds386`/`dsIII` already documented) -- and a closer look at
  `/log/runtime` this session found the SAME file also hits `*Bad
  argument 1 to sscanf` at runtime (`SetFloors()`'s `atoi(key)` call
  gets an int key from a mapping instead of a string). Confirmed
  byte-identical to `ds386`'s own raw `domains/campus/chamber/
  elevator.c` -- a genuine, but pre-existing and already-accepted,
  original-archive content bug, not something this port introduced or
  should fix.
- **`/domains/Ylsrim/broken/jar`**: `LIB_CAPTURE` has no implementation
  anywhere in either archive -- same pre-existing gap as `ds386`/`dsII`
  (the file is literally shelved in a `broken/` subdirectory).
- **`/secure/cmds/admins/opcprof`**: calls the `opcprof()` efun, which
  doesn't exist in this driver build at all -- same as `ds386`/`dsIII`,
  a creator-only diagnostic tool, not on any core path.
- **`/realms/muirrum/tmp/eegndioa1558469566`** (and 2 sibling files in
  the same directory): auto-generated QCS/`ed` scratch buffers from a
  builder's abandoned copy-and-edit session (filenames are a random
  8-char id + a Unix-epoch suffix from May 2019, matching this repo's
  actual commit history), each with a dangling relative `#include
  "../customdefs.h"` that only resolves from the ORIGINAL template
  file's location, not this `tmp/` scratch path -- the same class of
  found evidence of abandoned wizard debug scratch as `dsI`'s
  `daemon/tmp/A_WEARON.lpc` and `dsII`'s
  `secure/tmp/cratylus_CMD_EVAL_TMP_FILE.lpc`. Left as-is.
- **`/daemon/help`** (NOT preloaded, so not on the boot-critical path,
  but reachable the first time any player types `help`): `LoadIndices()`
  concatenates several `get_dir()` calls with `+`, including
  `get_dir(DIR_SPELL_VERBS + "/*.lpc")` where `DIR_SPELL_VERBS` resolves
  to `/verbs/spells` -- a directory `ds386` ships (confirmed present in
  its raw archive) but **ds-hakkard's own repository never shipped at
  all** (not gitignored -- genuinely absent from the tree, at any
  commit). `get_dir()` on a non-existent directory returns `0` (an
  int), not `({})`, which then fails the `+` concatenation with
  existing `array`-typed results ("Bad type argument to +. Had array
  and int."). This is exactly the kind of missing-content situation
  this project's methodology says not to paper over by inventing a
  `verbs/spells` directory or spell-verb files that were never part of
  the source -- left as a documented gap. Whether this game simply
  doesn't have a spellcasting-verbs system (plausible given the custom
  domain content) or the directory was accidentally omitted from the
  public repo is unknowable from this archive alone.

## 7. WASM pass

Not attempted this session (`wasm_status` left `""`). Given the
confirmed live outbound HTTP/socket behavior (\S5) and this being the
same `sockets`-package-dependent `secure/sefun/sockets.lpc` codebase as
`ds386`, a future WASM pass should expect to need the same
gut-the-function-bodies treatment `ds386`'s own WASM notes describe
before this lib can boot under WASM at all.

## 8. Sibling sweep of the dsIII §7.121 currency-float bug — confirmed present, fixed

`AGENTS.md` §7.121 documents a currency/economy bug found in `dsIII`
(the Dead Souls 3.x lineage's shared `secure/sefun/economy.lpc`):
`query_base_rate()`, `query_player_money()`, `query_base_value()`, and
`query_value()` do real floating-point exchange-rate math internally
but are declared to return `int` with no `to_int()` on the actual
return, silently corrupting player currency into a float on every
buy/sell/exchange. `ds-hakkard` shares this exact file byte-for-byte
with `ds386`/pre-fix `dsIII` and had the identical gap, plus the same
two sibling misses: `lib/teller.lpc`'s `eventExchange()` (`i = val /
currency_rate(str2);`) and `lib/props/value.lpc`'s `SetBaseCost()`
(`Cost = i * rate;`). Fixed identically (wrapped all four
`economy.lpc` returns plus both call sites in `to_int()`).

Verification here was **compile-only, not a full live transaction**:
attempting to reach the bank (`enter town` from the start room, the
same path used to verify `ds386`) hits a severe, unrelated,
pre-existing bug that makes the entire town domain unreachable — see
§9 below. Instead, verified the fix with `lpcc --batch` compiling the
three touched files directly (`/secure/sefun/economy`, `/lib/teller`,
`/lib/props/value`) against this lib's own `config.fluffos`: all three
`PASS`, no new errors introduced (only pre-existing, unrelated `nosave`
declaration warnings). `secure/sefun/economy.lpc` is also a
simul_efun file the driver compiles unconditionally at every boot, and
both the very first plain boot and the boot used for this check
compiled it clean with zero errors. Given the fix is byte-for-byte the
same edit already live-verified working on `ds386`, `dsII`, and
`deadsouls_fluffos` (identical code shape, identical `to_int()`
wrapping), this is considered sufficiently verified without a live
transaction.

## 9. `enter town` infinite error-handler recursion — ROOT-CAUSED AND FIXED

Follow-up dedicated pass (2026-08-27) to the blocker flagged below (originally
found while verifying §8's currency fix). Confirmed the crash is real and
reproduced it directly by booting the real driver and walking an ordinary
(non-creator) test character through registration into `enter town`: the
driver logged `"Error in error handler: *Object cannot be loaded during
compilation."` thousands of times a second and pinned a CPU core, matching
the original report exactly (a stale `work/log/debug.log` from that repro
alone grew to **8.9 million lines**).

**The directory-vs-file theory below was a correct but incomplete diagnosis.**
`log/errors/daemon` (and 20 sibling top-level names) really were
directory-shaped where the runtime error path wants a plain file, and that
*is* the event that first triggers the crash — but the actual bug that turns
one failed log write into an *unbounded* crash is in
`secure/daemon/master.lpc`'s own `error_handler()`, at the exact line the
crash trace names:

```lpc
rlog += load_object("/secure/cmds/creators/dbxwhere")->cmd(this_player(1)->GetKeyName());
```

Full chain: some file (in the reproduced case, a file under `/secure/`) emits
an ordinary compile warning ("Illegal to declare nosave function" — the same
harmless `nosave`-on-a-function idiom already catalogued elsewhere in this
codebase family as a non-bug) while the driver is compiling it, mid-compile,
as part of a lazy load triggered by an ordinary player action.
`master.lpc`'s `log_error()` apply handles that warning and does
`catch(write_file(DIR_ERROR_LOGS "/" + nom, ...))` — if `DIR_ERROR_LOGS "/" +
nom` is a directory (the `log/errors/daemon`-shape bug), `write_file()`
throws `"Wrong permissions for opening file ... Is a directory"` inside that
`catch()`. FluffOS still reports even a *caught* runtime error to
`master->error_handler(mp, 1)` for logging purposes. `error_handler()` sees
`this_player(1)` set to the ordinary player who triggered the lazy compile,
and — since they're not a creator — falls into the branch that builds an
admin-facing incident report, including an UNGUARDED
`load_object("/secure/cmds/creators/dbxwhere")` (an admin debug command,
essentially never already-loaded for an ordinary player's session). Since the
driver is *still* mid-compile at this point, that `load_object()` itself
throws `"Object cannot be loaded during compilation."` — from inside
`error_handler()` itself, uncaught. This re-enters the same mudlib
error-report path, which lands right back on the same `load_object()` line,
which fails the same way again — the driver's own re-entrancy counter bounds
any *single* burst to a handful of frames, but nothing stops the *next*
triggering event (the still-uncompiled file being touched again by the next
heartbeat/command) from restarting the whole cycle immediately, which is
what produces the observed effectively-infinite CPU-pinning loop. This is
the exact same "load-mid-compile" driver-compat class already documented in
`AGENTS.md` §7.60 (and already fixed once, elsewhere in this very function,
for `WEB_SESSIONS_D`, by checking `find_object()` before assuming an object
is loaded) — `dbxwhere` was simply the one call in this file that hadn't
gotten that same guard.

**Fix** (`secure/daemon/master.lpc`, `error_handler()`): wrapped the
`dbxwhere` lookup+call in `catch()`, degrading to a plain placeholder string
when it fails instead of letting the throw escape `error_handler()` itself:

```lpc
if( catch(rlog += load_object("/secure/cmds/creators/dbxwhere")
        ->cmd(this_player(1)->GetKeyName())) )
    rlog += "(dbxwhere unavailable -- driver mid-compile)\n";
```

This is a real driver-compat/programming bug fix (an unguarded call-other
that can throw during a well-known illegal window), not a content change.

**Also converted every remaining directory-shaped `log/errors/<name>` entry
to a plain empty file** (the 21 named in the original diagnosis below,
`cfg cmds doc domains estates ftp include lib log news obj open powers
realms save secure shadows std tmp verbs www` — `daemon`/`town`/`campus`/
`default`/`Praxis`/`Ylsrim`/`fluffos` had already self-healed into files
from earlier boots). This directory is gitignored (`.gitignore:24`), so this
change is local-only and does not affect a fresh checkout or get committed —
but it removes the *triggering* event entirely for this local checkout, on
top of the real code fix which removes the ability for that trigger (or any
future one shaped like it) to cascade into a crash.

**Verification**: killed the stale driver process, booted fresh
(`Initializations complete`, zero fatal errors), registered a brand-new
ordinary player (`Bugtestchartwo`, via a raw Python socket client — the
existing admin account bypasses the buggy branch entirely since creators
take a different, always-safe code path in the same function, so a fresh
non-creator registration was required to actually exercise the fix), and
walked: start room -> `enter town` -> `look` -> `north` (into an NPC-populated
room, "a dirty beggar" who spoke and gave an item) -> `look` -> `south` ->
`look` -> `score` -> `quit`. Every step produced correct, clean output with
**zero runtime-error messages** and the driver's own log
(`driver_stdout.log`, this run's actual live console/debug output — this
driver's `debug.log` file target is unused in non-daemon mode) had zero
`Error in error handler`/`Object cannot be loaded`/`Wrong permissions`/
`runtime error` lines anywhere. Confirmed the driver process stayed at
single-digit-to-teens CPU (idle-normal, not pinned) throughout, and killed it
cleanly by exact PID afterward. Before this fix, the identical
registration-then-`enter town` sequence reproducibly hit the crash within
one or two commands of entering town.

Test-only side effects (the ad hoc player saves, `RELEASE_NOTES_HTTP`'s
autoexec-refetched content, IMC2/vote/save-daemon state touched by the test
sessions) were reverted/removed before committing, per this project's
standing convention of not shipping test-session churn — the only committed
change is the `master.lpc` fix itself.

---

*(Original diagnosis, kept for reference — see above for the completed
root-cause and fix.)* While trying to reach the bank to verify §8 above,
`enter town` from the start room triggers a genuine, severe bug: the driver
enters an infinite `"Error in error handler: *Object cannot be loaded during
compilation."` recursion (`error_handler()` calling itself via
`/secure/cmds/creators/dbxwhere`'s own `load_object()` attempt while already
mid-compile) and pins one CPU core indefinitely until killed. Root-caused to
`log/errors/daemon` being **a directory** (containing a `foo.txt`
placeholder) rather than a plain file — the very first error the driver
tries to log after any runtime error anywhere hits `"Wrong permissions for
opening file /log/errors/daemon for append.\n\"Is a directory\""`, and
logging *that* failure recurses forever. Every OTHER top-level name was, at
the time, still a directory-with-`foo.txt` and could plausibly trigger the
identical crash the first time any runtime error happened to target one of
those categories.

## Sibling sweep of ds386's round-two `eventRevive()`/room.lpc/combat.lpc/beggar.lpc bugs (2026-08-27)

Per `ds386/NOTES.md`'s "Deep functional test (round two, 2026-08-27)"
section (the reference master for this whole lineage), checked all four
flagged bug shapes here. All four were present and fixed identically:

- **Bug #1, SEVERE (`eventRevive()` float corruption, AGENTS.md
  §7.121 class)**: `lib/player.lpc`'s `eventRevive()` fed
  `GetMaxMagicPoints() * PERCENT_MP` / `GetMaxHealthPoints() *
  PERCENT_HP` (float expressions, `PERCENT_MP`/`PERCENT_HP` being
  `0.95`/`0.70` `#define`s) directly into `AddMagicPoints(int x)`/
  `AddHealthPoints(int x, ...)`, corrupting `MagicPoints`/
  `HealthPoints` into floats on every single player death. **Fixed**
  by wrapping both in `to_int()`, matching `ds386`'s fix exactly
  (`AddStaminaPoints()` left untouched -- its backing field is
  genuinely `float` by design). **Verified live**: booted, logged in
  as admin (`fluffos`/`Mud@2026`), ran `eval object x =
  find_player("fluffos"); x->eventDie("test");` then `regenerate` --
  post-fix status bar showed `hp: 120/400  mp: 0/780`, clean integers;
  `save` confirmed the raw save file has plain integer
  `HealthPoints 120` / `MagicPoints 0` lines, no float.
- **Bug #2 (`replace_program()` fold, AGENTS.md §7.141)**: same
  MudOS-era fold present in `lib/std/room.lpc`'s `create()`. Removed
  it entirely, identical to `ds386`/`dsI`/`dsIII`.
- **Bug #3 (`Wimpy` fraction-vs-percentage, AGENTS.md §7.124 class)**:
  `lib/combat.lpc:65` had `Wimpy = 0.20;` plus `float SetWimpy`/`float
  GetWimpy`. Fixed to `Wimpy = 20;` and `int SetWimpy`/`int GetWimpy`.
  **Verified live**: `wimpy` command showed `Percentage: 20%`, a clean
  integer.
- **Bug #4 (`GiveMap()` reentrancy, `domains/town/npc/beggar.lpc`)**:
  same missing delivery-time `!present("town map",ob)` guard. Fixed
  identically to `ds386`.

Following this lib's own standing convention noted above, only the
four source-file fixes plus the admin account's post-test save state
were committed -- `RELEASE_NOTES_HTTP`/IMC2/vote/daemon-state test
churn and a stray `secure/tmp/*_CMD_EVAL_TMP_FILE.lpc` scratch file
were reverted/removed first. Killed the test driver by exact PID when
done.
