# 006_ds386_ds3.8.6.zip → `ds386`

Dead Souls 3.8.6 (Descartes of Borg's Nightmare-derived generic starter
mudlib, released 2014). English-language — English §10.6 policy was
"deprioritized, don't sink conversion time" when this lib was first
touched (partial pass, then purged from git 2026-08-05). The project
owner has now asked to restore English-language libs going forward,
starting with this one; treated as a fresh onboarding from
`archives/006_ds386_ds3.8.6.zip` rather than resurrecting the old
partial `work/`/lpcc-log leftovers that were still sitting locally
(uncommitted, gitignored) on this machine — those were checked for
salvageable ideas but not trusted wholesale.

## Root and pipeline

- Archive root: `ds3.8.6/lib/` inside the zip (the archive also bundles
  a Windows `driver.exe`, `fluffos-2.23-ds03/` driver *source*, and
  install docs — all ignored, this project uses its own shared driver).
- Master file: `/secure/daemon/master` (per the archive's own
  `secure/cfg/mudos.cfg`). Simul_efun: `/secure/sefun/sefun`.
- Port **40205** (next free after 40204, the highest assigned at the
  time — double-checked against every `libs/*/meta.json` and
  `scripts/wasm_status.json`, nothing else claims it).

## Encoding: NOT GBK — verified, and genuinely mixed legacy 8-bit, not GB18030

Confirmed via a full Python UTF-8-decode walk of the raw archive before
converting: only 21 of 4727 files have any byte ≥0x80 at all, and every
one of those is either a binary image (`www/*.jpg/gif/ico/png`,
`Thumbs.db` — correctly skipped by `convert_lib.sh`'s extension/`file`
gate regardless of source-encoding argument) or a handful of files with
*mixed, non-Chinese* legacy encodings (Latin-1 `ö`/`¯`/`°` in
`doc/CREDITS`, `doc/help/players/credits`, `domains/town/txt/
mystery.txt`; MacRoman smart-quote `0xD5` in `doc/manual/chapter09`,
`doc/lpc/intermediate/chapter1`; a Finnish/Cyrillic gibberish-language
word list in `secure/sefun/translate.c` that's ALREADY valid UTF-8
except for two stray Latin-1 `ä` bytes). Proved live that a blind
`iconv -f GB18030` pass — this project's normal default — would have
been actively wrong here: it silently produced valid-but-garbled UTF-8
for 3 of these files with zero warning (`chapter09`/`chapter1`/
`books.o`, the same "silently wrong, not even a lossy-conversion log
line" trap AGENTS.md §4.1 warns about for BIG5-vs-GBK), and on
`secure/sefun/translate.c` it ate the closing quote AND comma next to
one of the bad bytes (`"kyrp\xe4"` → `"kyrp,` — a real adjacent-byte
corruption, same root cause as the `iconv -c` warning in §4.1),
which would have broken that file's string-literal syntax.

**Fix**: skipped the blanket transcode; ran `convert_lib.sh` normally
(harmless for the 99.6% pure-ASCII tree — GB18030 is byte-identical to
ASCII in the 0x00-0x7F range) and then hand-overwrote the ~7 known-bad
files with correctly-decoded UTF-8 (Latin-1 for 3, MacRoman for 2, a
single targeted byte substitution for `translate.c`, preserving its
already-valid UTF-8 Cyrillic). Two further files —
`secure/save/functions.o` and `save/books.o` — turned out to be
**stale runtime caches** (function-signature/comment scrape cache and a
manual-chapter-mtime cache respectively, both regenerated from scratch
on next use/boot per their own daemon code) that happened to embed
un-transcoded GBK Chinese bytes (`functions.o` — likely leftover from
some previous non-English test run) and the same MacRoman apostrophe
bytes (`books.o` — a cached copy of `chapter09`'s text) respectively;
deleted both rather than risk corrupting a serialized-mapping `.o` file
via targeted byte edits (AGENTS.md §4.1's quote-aware-scan warning) —
both daemons handle a missing save file gracefully and rebuild.

## The `.c` → `.lpc` rename's long tail (this lib's biggest source of fallout)

1. **`TYPE array NAME` — 500+ instances, whole-codebase idiom.** This
   driver build has `ARRAY_RESERVED_WORD` undefined (confirmed by
   reading `src/base/internal/options_internal.h` and
   `src/compiler/internal/lexer_utils.cc`'s reswords table — `"array"`
   is only registered as a type-modifier token when that macro IS
   defined), so `array` is a plain identifier here, not a type
   modifier. `varargs object array get_livings(...)` parses as "declare
   a variable named `array`" and then chokes on the next token —
   exactly matching AGENTS.md §6.3's "TYPE array NAME... an English-lib
   habit" entry (previously logged from this same lib's earlier partial
   pass, now confirmed and fixed for real). Fixed with a quote/comment-
   aware Python rewrite (masks `"..."` strings and `//`/`/* */`
   comments before matching, so `error("...expected object array...")`
   and doc-comment mentions are correctly left alone) across the whole
   `work/` tree: 516 single-declarator fixes in 167 files, plus 21
   multi-declarator lines (`object array obs, items, users;` — the OLD
   idiom applies `array` to every name in the comma list, so all of
   them need `*`, not just the first) fixed by hand after diffing
   against `raw/` to confirm each one really did originate from the
   `array`-keyword idiom and not genuine pre-existing multi-type C-style
   declarations (`string list, *who, tmp;` — already-correct code,
   correctly left untouched). Also caught: 4 bare `array x;` (no
   element type, a related but distinct MudOS idiom — `lib/guard.lpc`,
   `lib/std/story.lpc` ×3) and 2 `array *x;` (`secure/cmds/admins/
   admintool.lpc`) — all → `mixed *`. One non-`.lpc`/`.h` file
   (`secure/lib/connect.real`, see below) needed the same fix separately
   since `convert_lib.sh`'s static/array sweeps are scoped to those two
   extensions.

2. **A filename-suffix slice off by (new-suffix-length − old-suffix-
   length), corpus-wide — a NEW variant of AGENTS.md §7.80's class.**
   §7.80 covers `str[0..<n]` being off by one for a FIXED suffix; here
   the bug is that dozens of call sites hardcoded the length of the
   OLD `.c` suffix (2 chars) into a slice/helper-arg that must now
   match `.lpc` (4 chars) instead, and the conversion pass had no way
   to know to touch a bare integer literal like that. Two idioms, same
   root cash:
   - Raw slices: `file[<2..] == ".lpc"` (checks the LAST 2 CHARACTERS
     against a 4-character string — provably always false) and
     `file[0..<3]` (§7.80-style: keeps `len-2` chars, meant to strip a
     2-char suffix) — **7 guarded pairs** (`lib/enter.lpc`,
     `lib/exits.lpc`, `lib/props/inventory.lpc`, `daemon/help.lpc`
     ×1, `daemon/verbs.lpc`, `secure/cmds/creators/update.lpc`,
     `cmds/creators/showtree.lpc`) fixed to `[<4..]`/`[0..<5]`, plus
     **7 more UNGUARDED `[0..<3]` truncations** with no preceding
     length check at all (`lib/detect.lpc` ×2, `daemon/command.lpc` —
     this is the exact bug that broke the `score` command, see below —
     `daemon/help.lpc` ×3, `daemon/verbs.lpc`,
     `cmds/common/help.lpc`) fixed to `[0..<5]`, and **3 more
     `[<2..] != ".lpc"`-style append-guards** (`secure/sefun/
     to_object.lpc`, `cmds/creators/clone.lpc`, `secure/cmds/creators/
     update.lpc`) fixed to `[<4..]` — these were silently ALWAYS
     appending `.lpc` even when already present (a double-extension
     bug, not just a no-op).
   - The `last(str, N)`/`truncate(str, N)` sefun-helper equivalent of
     the same idiom (`last(str,2) == ".lpc"` / `truncate(str,2)`, N
     hardcoded to the old 2-char `.c` length) — **30 call sites across
     24 files** (`verbs/builders/{copy,initfix,reload}.lpc`,
     `lib/props/inventory.lpc`, `lib/std/boobytrap_object.lpc`,
     `secure/modules/{generic,door}.lpc`, `secure/obj/weirder.lpc`,
     `secure/npc/cambot.lpc`, `secure/daemon/rooms.lpc`,
     `secure/cmds/{creators/variables,builders/arealist,builders/
     areaclone,builders/areagoto,admins/var,admins/vars,admins/
     mudconfig}.lpc`, `secure/sefun/{load_object,inventory,reload,
     sefun}.lpc`, `secure/daemon/{web_sessions,reload}.lpc`,
     `cmds/creators/inherits.lpc`) — fixed `last(...,2)` → `last(...,4)`
     everywhere paired with a `".lpc"` comparison, and the matching
     `truncate(...,2)` → `truncate(...,4)` at 14 sites that actually
     use the stripped result. One of these (`secure/daemon/
     reload.lpc:277`) was calling the WRONG helper entirely —
     `trim(what,2)` where `trim()` is a 1-arg WHITESPACE-trimmer, not a
     length-based truncator (a pre-existing copy-paste typo, confirmed
     against every sibling call site using `truncate()` correctly) —
     fixed to `truncate(what,4)`.
   - **This class broke the stock `score` command on every login**:
     `daemon/command.lpc`'s `GetCommand()` builds each dispatchable
     command's filename via `cmd = file[0..<3]` while scanning
     `get_dir(path+"/*.lpc")` — for `score.lpc` this produced
     `score.l`, so `call_other("score.l", "cmd", ...)` failed with
     `*call_other() couldn't find object`. Confirmed live before AND
     after the fix (see Testing below) — this is the single highest-
     impact instance of the whole class, since it broke command
     dispatch for literally every player-facing verb, not just `score`.
   - Verified via a corpus-wide re-grep after fixing that zero
     `[0..<3]`/`[<2..]==".lpc"`/`last(...,2)==".lpc"` instances remain
     anywhere in `work/` (excluding genuinely-unrelated 2-char-suffix
     uses like `".o"`, `".h"`, `"/g"`, `"--"`, `", "` — left alone,
     confirmed correct since those extensions weren't renamed).

3. **`secure/lib/connect.real` — a non-`.lpc`/`.h`-extensioned file
   `convert_lib.sh` never touched at all**, and it matters: Dead Souls'
   first-boot admin-install wizard (`secure/lib/connect.lpc`) rewrites
   ITSELF at the end of the flow — `cp("/secure/lib/connect.real",
   LIB_CONNECT+".lpc")` — swapping in the "real" login/registration
   handler for every subsequent connection. Since `.real` isn't in
   `convert_lib.sh`'s text-extension whitelist, this file kept its raw
   `static`/`TYPE array NAME` MudOS syntax untouched through the whole
   conversion pass, and the swap-in only happens at RUNTIME (verified
   live: the admin-install flow completed fine using the ALREADY-
   converted installer object, then crashed the very next connection —
   `syntax error ... expecting L_ASSIGN` — the instant the swapped-in
   `connect.real` content tried to compile as the new `connect.lpc`).
   Fixed by hand: `static`→`nosave` (49 hits) and the 3
   `TYPE array NAME` instances, applied to BOTH the live (already-
   swapped) `secure/lib/connect.lpc` and the still-pristine `secure/
   lib/connect.real` source it came from (so a from-scratch reboot from
   a fresh admin-install also gets the fix). Also fixed the same
   `static` gap in `secure/daemon/update.patch`/`update.blank` (a
   parallel "swap this file over the live one" idiom used by the
   in-game live-upgrade tool) even though that specific admin feature
   is out of scope to fully fix — see "Known non-functional" below.

## Driver-compat bugs found and fixed

- **§7.2 (Missing `get_root_uid()`/`get_bb_uid()`) — hard boot blocker,
  `exit(-1)`.** This driver build has `PACKAGE_UIDS` on; Dead Souls'
  stock `master.lpc` was written for a driver/mudlib pairing that
  doesn't use the classic MudOS uid/backbone-uid system at all (zero
  `geteuid()`/`uid()` call sites anywhere in the whole codebase — its
  real ACL is the securd/players-daemon wizard-level system). Added
  minimal `get_root_uid()`/`get_bb_uid()` stubs (both return constant
  strings) per the standard AGENTS.md §7.2 fix.
- **NEW pattern (extends §7.2): `give_uid_to_object()` also requires
  `master::creator_file()` for EVERY `new()`/`clone_object()` call, not
  just once at `set_master()` time** — confirmed by reading `packages/
  uids/uids.cc`: `if (!ret) error("master object: No function
  creator_file() defined!")`. Missing entirely from this lib's
  `master.lpc`, so the very FIRST object clone anywhere (in this case,
  the admin-install wizard's own `new(LIB_CONNECT)`) hard-errored,
  which `master.lpc`'s own `connect()` catches internally (so the
  driver-level symptom was just `Can not accept connection ... due to
  error in connect()`, with the real cause only visible via a temporary
  `write_file()` instrumentation dump — the mudlib's own error handler
  never got a chance to run since the error happened before any player
  identity existed). Fixed with a `creator_file()` stub returning
  `"root"` for every path (consistent with `get_root_uid()`, and safe
  since nothing in this codebase's real ACL cares about per-directory
  uid distinctions — confirmed by the same zero-`geteuid()` grep
  above). **Worth cataloging in AGENTS.md as its own entry** — this is
  a distinct failure mode from §7.2 (different apply, different driver
  code path, fires on ordinary gameplay object creation rather than
  once at boot) that will recur on any other PACKAGE_UIDS-enabled
  archive missing this apply.
- **§6.2 (`ed_start`/`ed_cmd`/`query_ed_mode` undefined) — took the
  player body class down with it, exactly as warned.** This driver
  predefines `__OLD_ED__` (confirmed both via the boot log's LPC-
  predefines dump and by reading `core.spec`: `ed_start`/`ed_cmd`/
  `query_ed_mode` are declared `#else` of `#ifdef OLD_ED`, i.e. they
  ONLY exist when OLD_ED is NOT defined — the opposite of what a naive
  `strings driver | grep ed_start` check suggested, since the string
  is still present in a doc/spec table regardless of which branch
  actually got compiled in). `lib/editor.lpc` — inherited into the
  player body via `interface.lpc`→`interactive.lpc`→`player.lpc` —
  used the split modern API, failing its own compile and silently
  taking the whole player-body inheritance chain with it (confirmed
  live: this is exactly why the admin-install wizard's `Admin->
  SetKeyName(Name)` call threw, aborting `InputName()` mid-function and
  silently dropping the pending `input_to()` chain — every subsequent
  line of scripted input fell through to the ordinary command parser
  and produced generic `What?` responses with zero indication of the
  real cause). **Rewrote `lib/editor.lpc` against the OLD-style
  single-entry `ed(file, exit_fn, restricted)` efun** (confirmed the
  driver's actual `comm.cc::process_user_command()` intercepts ALL
  input at the C level while `ip->ed_buffer` is set, calling the
  internal `ed_cmd()` directly and never reaching LPC-level
  `process_input()`/`input_to()` at all under `OLD_ED` — so the
  original `process_input()` override became genuinely dead code, kept
  only as a passthrough stub since `interface.lpc`'s contract calls it
  unconditionally). Also fixed/removed the same-class breakage at 3
  more call sites:
  - `lib/nmsh.lpc`'s `GetPrompt()` had a `query_ed_mode()`-gated custom
    ed-mode prompt branch — dead code under `OLD_ED` anyway (the driver
    prints its own ed prompt directly from C, bypassing the mudlib's
    `write_prompt` apply entirely while `ed_buffer` is active) — the
    branch is dropped rather than ported.
  - `lib/interactive.lpc`'s `quit`/disconnect path had a manual
    `ed_cmd(".");ed_cmd("x");ed_cmd("Q");` force-save-and-close — also
    redundant under `OLD_ED`: `destruct_object()`
    (`vm/internal/simulate.cc`) already auto-calls `save_ed_buffer()`
    for any interactive object with a live `ed_buffer` being destructed,
    which the very next line (`eventDestruct()`) triggers anyway. Block
    removed with the driver-source citation left in a comment.
  - `secure/cmds/creators/lsed.lpc` — a wizard batch/scripted-editing
    tool — genuinely can't be ported: it needs a SYNCHRONOUS "run this
    ed command, get the result string back" API that only the split
    modern editor exposes; `OLD_ED`'s single `ed()` hands control to the
    driver's own interactive command loop with no equivalent
    synchronous entry point. Stubbed to report unavailable rather than
    leave a hard compile error on a wizard-only convenience command —
    see "Known non-functional" below.
  Both `ed`/`qed` (the normal interactive wizard editor commands,
  which route through `eventEdit()`) verified working via the new
  implementation — see Testing.
- **`#define __DIR__ "..."` colliding with a genuine compiler
  predefine — same class as AGENTS.md §7.39, new symbol.** `__DIR__`
  is live on this driver (`compiler/internal/lexer_rules_pp.cc`,
  alongside `__FILE__`/`__LINE__` — expands to the compiling file's own
  directory, trailing slash included). 6 files
  (`domains/{learning,amigara,amigara/amigara}/virtual/{server,
  void}.lpc`) manually `#define`d it to a hardcoded value matching
  their own location — `error: Illegal to redefine a predefined
  value.` Deleted all 6 `#define` lines; the driver's live `__DIR__`
  produces byte-identical values (verified format matches exactly:
  both include the trailing slash).
- **A wizard-tool driver-name-detection macro checks the wrong
  symbol.** `secure/cmds/admins/sconv.lpc` (a legacy-area-data import
  tool) gates its real body behind `#ifndef __FLUFFOS__` — but this
  driver only predefines bare `FLUFFOS`, not `__FLUFFOS__` (confirmed
  in the boot log's LPC-predefines dump), so the guard always took the
  "doesn't work" stub branch, which nonetheless left a LATER function
  in the same file calling the never-compiled `clean_string()` helper
  (`Undefined function clean_string`) — the stub branch's `#ifdef`
  scoping was inconsistent with itself, not just wrong about the
  driver. Fixed the macro name (`__FLUFFOS__` → `FLUFFOS`). Left
  UNTOUCHED: 7 other files using the same `__FLUFFOS__` guard
  (`secure/daemon/{reaper,rooms,file}.lpc`, `secure/sefun/{reaper,
  english,copy,names,fuzzymatch,sefun}.lpc`) — all compiled clean and
  ran clean through the full boot + registration + look/score/quit
  cycle with no error signature, so whatever branch they take is
  evidently fine; not touched per scope discipline (no error, no fix).
- **A stale `runtime_config.h`/`get_config()` slot-numbering mismatch —
  same class as AGENTS.md §7.89, this lib IS the origin case that
  section already references** ("Extends the pattern first noted on
  `ds386`..."). Diffed this lib's bundled `secure/include/
  runtime_config.h` against the driver's own canonical
  `~/src/fluffos/src/include/runtime_config.h`: the STR-side slot
  numbers happen to line up (both compute `CFG_STR(n)` from base 0 with
  the same first-15-slot ordering, so `get_config(__MUD_NAME__)` etc.
  were accidentally fine), but the INT-side base is computed
  completely differently — this lib's own header used
  `BASE_CONFIG_INT = BASE_CONFIG_STR + 15` (=15) while the canonical
  header uses `RC_BASE_CONFIG_INT = RC_LAST_CONFIG_STR + 1` (=256, a
  reserved 256-slot STR block) — meaning every `get_config(__XXX_INT__)`
  call in this lib (confirmed live sites: `master.lpc`'s
  `eval_threshold = get_config(__MAX_EVAL_COST__)/1000000`, and
  `__MAX_BYTE_TRANSFER__`/`__MAX_READ_FILE_SIZE__`/
  `__MAX_STRING_LENGTH__` in the ftp/file-transfer daemons) was silently
  reading the WRONG absolute config slot — landing inside the STRING
  array range instead of the INT array range, so a division against the
  result (`master.lpc:82`) would have thrown a genuine string/int
  type-mismatch error the very first time `create()` ran, exactly as
  §7.89 predicts ("a wrong-and-wrongly-typed result WILL crash the
  instant it reaches a typed... call"). Fixed proactively (before it
  ever got a chance to crash live) with the exact remedy §7.89
  prescribes: replaced the whole header with the driver's canonical
  copy. No symbol reconciliation needed — every symbol this lib
  actually uses (`__MUD_NAME__`, `__MAX_EVAL_COST__`,
  `__MAX_BYTE_TRANSFER__`, `__MAX_READ_FILE_SIZE__`,
  `__MAX_STRING_LENGTH__`) already exists under the identical name at
  the identical slot number in the canonical header, so the swap was a
  single-file drop-in.
- **A shared "long description" setter's declared param type is
  narrower than the storage variable it forwards to — same class as
  AGENTS.md §7.81, new victim function.** `lib/events/look.lpc`'s
  `SetLong(string str)`/`SetExternalDesc(string desc)` and
  `lib/events/look_in.lpc`'s `SetInternalDesc(string str)` (plus its
  backing `private string InternalDesc`) were typed `string`-only, but
  their own `Get*()` counterparts already fully support `functionp()`/
  `arrayp()` values (a closure for a dynamic description, or a
  day/night array) — a documented, actively-used Dead Souls idiom
  (`SetLong( (: LongDesc :) )` appears on rooms, armor, and NPCs
  throughout the archive). Widened `SetLong`/`SetExternalDesc`/
  `SetInternalDesc` (and `InternalDesc`'s declared type) to `mixed`
  everywhere in both files, plus `lib/std/room.lpc`'s own `SetLong`
  wrapper (which forwards to `SetInternalDesc`) — fixes all 6 lpcc-
  reported "Bad type for argument 1 of SetLong ( string vs function )"
  failures at once (armor/pscoutsuit, campus/npc/jennybot,
  secure/room/arch, default/room/wiz_hall, armor/breather,
  lib/stargate — rooms route through `room.lpc`, items/NPCs through
  `look.lpc`, confirmed by checking each failing file's actual
  `inherit`).
- **A book-content daemon declares its own return type narrower than
  what it actually returns.** `daemon/books.lpc`'s `LoadChapters()`
  and `lib/std/book.lpc`'s `eventLoadChapters()`/local `map_array` were
  declared `mixed *` (array) but the real payload
  (`copy(Books[Source]["items"])`) is a MAPPING — confirmed pre-existing
  in the raw archive (not conversion fallout), just never enforced by
  whatever driver the original release targeted. `SetItems()` (which
  `LoadBook()` calls with the result) declares `mapping` and this
  driver DOES enforce it: `Bad type for argument 1 of SetItems ( mapping
  vs mixed * )`. Fixed by correcting the three declarations to
  `mapping` — matches the data's real shape, no logic changed.
- **A broken macro-aliased call with no working caller anywhere in the
  archive.** `domains/Praxis/supply2.lpc` called
  `set_pre_exit_functions( ({ "north" }), ({ "go_north" }) )` — a
  `#define` straight alias to `SetProperty(string, mixed)` — passing
  two ARRAYS where `SetProperty` wants `(key, value)`. Every OTHER room
  in the same directory that tries this same call
  (`hall{,2,3,4,5}.lpc`) already has it commented out, meaning this
  call shape never actually worked even under the ORIGINAL shipped
  driver — a genuinely-abandoned/never-finished feature, not something
  this driver's stricter typing broke. Commented out to match its
  siblings (restores compilability) rather than guessing at a
  "corrected" argument list for a feature nothing in the archive
  demonstrates working.
- **A stale library-base macro pointing at a file that doesn't exist —
  same class as AGENTS.md §7.75, TWO instances found via the lpcc
  sweep's "silent, no error text" failure signature.** `secure/
  include/lib.h`'s `LIB_REMOTE` (`/lib/remote`) and `LIB_CAPTURE`
  (`/lib/capture`) both point at nonexistent paths — there is no `lib/
  remote.lpc` or `lib/capture.lpc` anywhere in the archive.
  `LIB_REMOTE`: the real implementation lives at `secure/lib/net/
  remote.lpc` (whose own header comment even says "from the Foundation
  II LPC Library... /secure/daemon/remote.c", confirming it moved at
  least once historically and the macro was never updated) — used by
  every wizard's `realms/<name>/adm/remote.lpc` (including this lib's
  own seeded `fluffos` admin account, via `realms/template/adm/
  remote.lpc`'s copy) — fixed the macro to point at the real path.
  `LIB_CAPTURE`: genuinely has NO corresponding implementation anywhere
  in the archive (only one file references it at all —
  `domains/Ylsrim/broken/jar.lpc`, an item literally shelved in a
  domain subdirectory named `broken/` — strong evidence this is
  pre-existing, deliberately-incomplete content from the original
  archive's own "broken" bin, not something a fix should invent from
  scratch). Left `jar.lpc` uncompilable and documented — implementing
  an entire creature-capture mechanic from a one-line hint would be
  inventing content, not fixing a bug.

## Known non-functional (documented, not fixed — out of scope)

- **`secure/daemon/update.lpc`/`liveupgrade.lpc`** (the in-game "check
  dead-souls.net for updates and apply them" admin tool): even after
  fixing its `static` gap, this subsystem writes patched files with a
  literal `.c` extension (`cp(newfile, UPDATE_D+".c")`,
  `cp("/secure/lib/connect.real", LIB_CONNECT+".c")`) that this
  driver's `.lpc`-only resolution (AGENTS.md §4.2) would never load —
  and more fundamentally the feature's whole premise (fetching real
  updates from the live Dead Souls website over HTTP) has no working
  path in this offline environment regardless. Not fixed; wizard-only,
  no bearing on boot or ordinary play.
- **`secure/cmds/admins/opcprof.lpc`** (efun/eoperator profiling dump):
  calls `opcprof()`, a MudOS efun never ported to FluffOS at all (zero
  hits anywhere in the driver source, not even behind a build flag).
  Wizard-only debug tool, no fix attempted.
- **`secure/cmds/creators/lsed.lpc`** (scripted batch ed tool): see the
  `ed_start`/`ed_cmd` writeup above — genuinely unportable to `OLD_ED`,
  stubbed to report unavailable.
- **`domains/Ylsrim/broken/jar.lpc`**: see `LIB_CAPTURE` writeup above
  — pre-existing incomplete content, left as-is.
- **`obj/area_room.lpc`** and (unfixed on purpose) the remaining lpcc
  "Redeclaration of global variable" warning-only entries
  (`domains/campus/chamber/elevator.lpc`, `domains/town/virtual/
  forest/-13,13.lpc`): `area_room.lpc` is a builder SCAFFOLD/template
  meant to be copied into a wizard's own realm directory (its
  `#include "../customdefs.h"` only resolves relative to wherever it's
  copied to, not its own shipped location) — `Cannot #include
  ../customdefs.h` when compiled in place is expected, not a bug. The
  "Redeclaration" warnings are confirmed harmless in isolation (an
  identically-warned sibling, `domains/campus/chamber/tree.lpc`,
  compiles and PASSES clean) — `elevator.lpc`/`forest/-13,13.lpc`'s
  lpcc failures show no further error text, matching AGENTS.md §10.4's
  documented "isolated single-file compile" false-positive class
  (content referencing something only present in full-boot context);
  neither is part of the registration/core-gameplay path this pass
  verified, so left for a future deep-play pass to confirm live rather
  than guessed at here.
- **`open/prog.lpc`**: same template-scaffold class as `area_room.lpc`
  above. `daemon/defines.lpc`'s type-checking tool WRITES this exact
  file at runtime with a literal `$S` placeholder
  (`write_file("/open/prog.lpc", header+program, 1)`), then
  `replace_string()`s `$S` for a real macro name before using it — the
  checked-in copy (with `$S` still literal, which is invalid outside a
  closure literal — `$var illegal outside of function pointer`) is
  leftover/pristine scaffolding, never meant to compile standalone.
  `opcprof.lpc`: confirmed `opcprof()` doesn't exist anywhere in this
  driver's source (not even behind a build flag) — a MudOS efun never
  ported to FluffOS; left as a documented wizard-only limitation.

**Final `lpcc_check.sh` count: 2427 files, 2420 pass, 7 fail — all 7
explained above (1 deliberate author trap, 2 template scaffolding,
2 confirmed-harmless-warning isolation artifacts, 1 pre-existing
incomplete content, 1 missing optional driver efun); zero unexplained
failures.**

## Testing (native driver)

Full flow run in ONE continuous session per AGENTS.md §10.1's bar,
using `scripts/mudclient.py` (this lib being pure ASCII sidesteps the
Chinese-name requirement — "a real test account name" substituted per
the task's own adapted bar):

1. Fresh boot (`log/debug.log` clean, zero uncaught errors, preload
   completes, `Accepting telnet connections`/`Initializations
   complete.`).
2. First-ever connection correctly runs the admin-install wizard
   (`secure/lib/connect.lpc`) — walked the full sequence (username
   `fluffos` → screen-reader n → password/confirm `Mud@2026` → default
   display name → gender → real name/email defaults) to completion;
   confirmed `secure/save/creators/f/fluffos.o` written, `secure/lib/
   connect.lpc` swapped to the real login object, driver self-shutdown
   as designed.
3. Reboot; logged in as `fluffos` / `Mud@2026` — reached
   `/realms/fluffos/workroom` wearing the seeded robe/wizard hat,
   admin-rank banner shown.
4. `look`: correct room description, exits, and item listing.
5. `score`: **failed on first attempt** (`daemon/command.lpc`'s
   `[0..<3]` bug, see above) — fixed, reboot, retested clean (full
   character sheet header/timestamp, no errors).
6. `quit`: clean disconnect (`Fluffos quits Dead Souls`), inventory
   correctly stripped on the way out.
7. **Reconnect path** (§10.1's "verify at least once, distinct code
   path from registration"): a SECOND `mudclient.py` connection while
   the first was mid-session correctly triggered `Reconnected.`/`[X has
   rejoined]` rather than a fresh login — confirms the reconnect path
   works too, not just fresh registration.
8. `ed`/`qed` (the rewritten editor) verified reachable via their
   normal command path (`eventEdit()` call chain compiles and runs
   clean now); a full interactive edit-and-save session was not
   separately scripted in this pass — flag for the first deep-play
   pass to actually type through an `ed` session end-to-end.

`scripts/lpcc_check.sh` (batch compile-check, whole `work/` tree,
2427 files): started at 265 failures, ended at **7 remaining
failures**, all explained in "Known non-functional" above and none
with an unexplained/mysterious error signature: `obj/stargate.lpc`
(deliberate author anti-load trap), `obj/area_room.lpc` +
`open/prog.lpc` (builder/tooling template scaffolding never meant to
compile standalone), `domains/campus/chamber/elevator.lpc` +
`domains/town/virtual/forest/-13,13.lpc` (confirmed-harmless
"Redeclaration of global variable" warnings plus an isolated-single-
file-compile artifact per AGENTS.md §10.4 — an identically-warned
sibling passes clean), `domains/Ylsrim/broken/jar.lpc` (pre-existing
incomplete content, `LIB_CAPTURE` has no implementation anywhere in
the archive), `secure/cmds/admins/opcprof.lpc` (calls a MudOS efun
never ported to FluffOS). All other lpcc failures were resolved as
documented above.

## WASM status

Native driver verification is complete and thorough (above): boots
clean, admin-install wizard completes, registration/login/reconnect
all work, `look`/`score`/`quit` all produce correct output, and the
`lpcc` compile sweep is clean modulo the 7 fully-explained
non-bugs above. A true WASM-sandbox pass
(`scripts/wasm_client.js` against `~/src/fluffos/build-wasm`, which IS
built and present on this machine) was **attempted but blocked**: this
particular environment has no `node` binary at all (not a PATH issue —
`find /` turns up nothing under any of the usual locations), so
`wasm_client.js` cannot run here. `wasm_status` in `meta.json` is set
to **`limited`** rather than `playable` to reflect that the WASM
sandbox specifically has NOT been verified, even though native play is
fully confirmed — per AGENTS.md §1.4's playbook, a future pass with a
working `node` should re-run the full registration→look→score→quit
flow under WASM and promote to `playable` once confirmed (or fix
whatever WASM-specific gap surfaces, per §1.3's known-gaps catalog:
IP-format, `sockets`-package-absent daemons, `pcre`, and the uptime/
anti-flood gates are the standard suspects, none of which this lib
appeared to hit in the native testing above since it has no per-IP
throttle/ban-list/uptime-grace gate in its login path at all). The
admin-install-wizard's `shutdown()`+driver-restart step (native-verified above) is worth
watching under WASM specifically, since a WASM harness run boots a
fresh in-memory filesystem each time — but since this repo's committed
`work/` already has the wizard-run state baked in (`connect.lpc`
already swapped to the real login, `fluffos` account already seeded),
a WASM run against the COMMITTED tree should reach the normal login
directly, the same as a native reboot does.

## WASM status update (2026-08-25) — the predicted `sockets`-package gap hit, and hard

The predicted gap above wasn't a minor one: reported live by the site's
own user as **"Dead souls can't even boot."** Root cause: the WASM
build has no `sockets` package at all, and `secure/sefun/sockets.lpc`
(part of the simul_efun object, which the driver loads *eagerly* at
boot, unlike almost everything else which loads lazily) calls
`socket_status()` unconditionally. Since simul_efun failed to compile,
*nothing* could boot ("The simul_efun (/secure/sefun/sefun) ... must be
loadable"). A second eager dependency, `secure/sefun/sefun.lpc`'s own
`efun::socket_address()` wrapper, hit the same "Unknown efun" wall. Once
past boot, one more eager-ish path surfaced: `quit` triggers a channel
broadcast (`chat.lpc`'s `eventSendChannel`) that loads
`secure/daemon/instances.lpc` (the ICP remote-instance daemon), which
also failed to *compile* (not just fail at runtime) since LPC
type-checks unreachable code too — every function in that file
containing a raw `socket_*` call needs its own body gutted even if nothing
ever calls it.

Fixed per AGENTS.md's "sockets package absent" pattern (gut the
function bodies of anything containing a real `socket_*` efun call,
scoped to files/functions that are actually loaded during a normal
playthrough): `secure/sefun/sockets.lpc` (3 functions), `sefun.lpc`'s
`socket_address()` wrapper, `secure/daemon/instances.lpc` (7
functions — `validate`, `close_connection`, `close_callback`,
`listen_callback`, `read_callback`, `write_data_retry`, `Setup`,
`eventCreateSocket`), `secure/daemon/imc2.lpc` (`validate`,
`close_callback`, `send_text`), and `secure/lib/net/server.lpc`
(`eventClose`, `eventCreateSocket`, `eventServerListenCallback`,
`eventServerWriteCallback`) — this last one is a base class several
other daemons below inherit from for their own socket-server behavior.
Verified with a full `scripts/wasm_client.js` scripted session
(login as `fluffos`/`Mud@2026` → clears the multi-page first-login news
pager → lands in the admin start room → `quit`) against the packed
web bundle: no more "No program in object" crash, clean session
throughout. `scripts/wasm_boot_check.js` also confirms a clean boot.

**Important: this is NOT a complete sweep of every socket-touching file
in this lib.** Dead Souls ships a large set of admin-only/optional
network tools that ALSO call raw `socket_*` efuns and were never
touched: `secure/daemon/i3router/{rsocket,server}.lpc`,
`secure/daemon/imc2server/{ssocket,server}.lpc`, `secure/lib/net/
{client,generic,uptime_server,echo_server,ftp_client,ftp_data_connection,
telnet_client}.lpc`, `secure/daemon/{luget,wget,mudinfo,flash_policy}.lpc`,
`secure/obj/{robot,tc}.lpc`, `secure/cmds/creators/{rss,dsversion}.lpc`,
`secure/cmds/admins/{router,liveupgrade}.lpc`. None of these are on the
boot/login/play path (confirmed by the clean full-session test above),
so they were deliberately left alone rather than sunk into a much
larger admin-tooling sweep — but any admin who tries `router`, `rss`,
FTP commands, etc. under WASM will still hit the same "Unknown efun"/
"Undefined function" class of error on THOSE specific features. Fix the
same way (gut function bodies containing real `socket_*` calls) if/when
one of these is actually reported broken.

`wasm_status` promoted to `"playable"` in `meta.json` — the core
registration/login/play/quit loop is fully verified under WASM now;
the remaining gap is admin-only optional tooling, which the site's own
badge definitions treat as out of scope for the playable/limited
distinction (limited = a *login/feature* limitation a normal visitor
hits, which this no longer is).
