# Basis -- porting notes

Source: `basis-20.tar.gz`, recovered directly from the still-live
`ftp.lysator.liu.se` LPMud archive mirror
(`https://ftp.lysator.liu.se/pub/lpmud/mudlibs/MudOS/basis-20.tar.gz`,
`Last-Modified: 05 Aug 2010`, itself an untouched 2010-era copy of the
original file). No Wayback Machine recovery was actually needed --
the CDX API had no capture of the file itself (only of its parent
directory listing), but the live mirror still serves the exact file.
Slug `basis`, number 959, port 40261. 233 files, real
`adm/obj/master.lpc` tree, mudlib root at the archive's top-level
`basis/` directory.

Author: John Garnett ("Truilkan"), same person as the already-onboarded
`tmi2` (TMI-2), but this is a distinct, earlier (1993), and much
smaller/thinner project -- explicitly described by its own author as
"an experiment," "far from a finished polished mudlib," intended "for
experimenters who actually want to start with something smaller and
less complete than TMI-2." Basis's own std/access/emoted conventions
were later inherited by TMI-2 (confirmed by the archive's own README).

## 1. Extraction and conversion

Pure ASCII/English archive, 0 lossy conversions (as expected --
`convert_lib.sh`'s encoding pass was a no-op). 233 files renamed
`.c`->`.lpc`, 43 literal `.c"` references fixed, 3 local angle-bracket
includes converted to quotes, 33 files `static`->`nosave`.

## 2. Proactive on-sight checklist findings

- `status` used as a declared type (AGENTS.md §6.8) in two places, one
  of which my initial targeted grep for `^\s*status\s` /
  `[(,]\s*status\s` MISSED: `std/i/pager.lpc`'s
  `nosave private status use_get_char;` (the `status` keyword sits
  mid-declaration after `nosave private`, not at line-start or inside
  a parameter list). **Lesson for future archives**: the safe general
  grep is `\bstatus\b` across the whole tree, filtering out plain-English
  prose/path-string false positives by hand, not the two narrower
  patterns AGENTS.md currently documents. Fixed: `int`.
- `new` used as an ordinary parameter/local name in two files
  (`adm/obj/simul_efun/resolv_path.lpc`, `.../replace_string.lpc`) --
  `new(...)`/`new(class ...)` is a hard-reserved keyword on this
  driver (object-instantiation syntax), unconditionally, unlike the
  compile-flag-gated `ref` reserved word (AGENTS.md §6.7). This is a
  new, previously-uncatalogued reserved-identifier collision class
  (added as a new AGENTS.md §6.2 entry this session, alongside the
  sibling `class` collision below).
- `class` used as an ordinary parameter name (`std/i.lpc`'s
  `receive_message(string class, string msg)`) -- also a hard-reserved
  keyword (typed-class/struct syntax), same failure shape as `new`.
- The proactive checklist found nothing else unusual: no `ed_start`/
  `ed_cmd`, no `efun::set/query/delete`, no `switch...default:` empty
  clause, no hardcoded ports, no `this_player()` inside the security
  daemon, no suspicious `destruct` calls in master.

## 3. Compile-time driver-compat fixes

- **Missing `global include file` config key.** The original archive's
  own config commented this out ("This is an optional define, and
  currently doesn't work" -- true on old MudOS, not true here): with
  the key entirely absent, this driver's config parser still zeroes
  the destination buffer, sees an empty (thus unquoted-looking) value,
  and unconditionally pushes a phantom `#include ""` before literally
  every compiled file's first line -- `error: Cannot read #include
  file` on every single compile, though non-fatal by itself (the rest
  of the file still compiles). Fixed by adding `global include file :
  <config.h>` (a pattern already used by 9 other libs in this corpus
  for a similar `config.h`-flavored header). Cross-checked: EVERY
  other lib's `config.fluffos` in this corpus sets this key -- worth
  treating its absence as a red flag on any new archive, not just an
  omission to fix reactively.
- **`extract()` and `log_file()` were never real efuns on this
  driver** (classic MudOS efuns, both absent from FluffOS's spec).
  `extract(str, start[, end])` (substring by inclusive index range,
  2- and 3-arg forms both used in this archive) and `log_file(file,
  str)` (append to a file under the mudlib's own `LOG_DIR`) both
  reimplemented as simul_efuns, added to `adm/obj/simul_efun.lpc`'s
  include chain. See AGENTS.md §6.2's new entries.
- **`move_object()` 2-arg vs 1-arg dialect gap** (AGENTS.md §7.158's
  documented class): `std/object/move.lpc`'s `move()` called
  `efun::move_object(this_object(), ob)` (old MudOS 2-arg form); this
  driver's `move_object()` efun takes exactly one argument (the
  destination) and always moves `this_object()`. Since the old first
  argument was always `this_object()` anyway here, the fix is the
  simplest case of this class: drop the first argument entirely.
- **A vestigial `private inherit` created an ambiguous duplicate of a
  needed public function -- a new bug class, not just AGENTS.md
  §7.48's "private declared in one file, called from an inheriting
  program" shape.** `std/living/envars.lpc` did `private nosave
  inherit CORE;` purely as leftover cruft -- it never actually called
  any of CORE's `query()`/`set()`/`delete()`/`add()` methods (it
  manages its own independent `evars` mapping). `std/living.lpc`
  inherits BOTH `std/object/base.lpc` (a normal, PUBLIC `inherit
  CORE`) and `envars.lpc` -- giving living.lpc two separate inherited
  copies of `query()`, one public (initialized, the one actually
  wanted) and one private (via the now-removed inherit, its own
  `attrs` never initialized since `envars.lpc`'s own `create()`
  override shadows CORE's). This driver picked the PRIVATE copy for
  living.lpc's own unqualified `query(a_name)`/`query(a_permissions)`
  calls, hard-failing with "Illegal to call inherited private function
  'query'" -- blocking the ENTIRE player-body compile (`std/i`,
  `std/admin`, `std/maker`, `std/user` all failed transitively).
  Diagnosed by noticing `envars.lpc` never actually uses anything from
  its own `inherit CORE` line. Fixed by deleting the vestigial
  inherit outright (not by loosening `private` to `protected`, which
  would have "fixed" the compile error but left the SAME wrong,
  uninitialized copy winning at runtime -- a silent wrong-mapping bug
  instead of a clean compile error). **New AGENTS.md §7 candidate**:
  when two inherited copies of the same base class collide (one
  public+wanted, one private+vestigial), check whether the private one
  is actually load-bearing before just relaxing its visibility.
- **The most severe bug: a runtime-only closure/function-pointer
  semantics gap, not a compile error at all.** `std/object/base.lpc`'s
  `setup_efun_attributes()` builds `(: SIMUL_EFUN_OB, "query_efuns" :)`
  -- old MudOS's "call_other-bound function pointer" idiom, meant to
  redirect `query(a_super)`/`query(a_contains)`/`query(a_uid)`/
  `query(a_ip_address)` through a simul_efun (`SIMUL_EFUN_OB` is the
  path string `"/adm/obj/simul_efun"`). This driver's grammar (per
  `~/src/fluffos/docs/lpc/types/function.md`, "the third type is the
  call_other function pointer... `(: object, function :)`") documents
  this working for ANY expression in the head slot including a bare
  string, but the ACTUAL implemented grammar
  (`compiler/internal/grammar.y`'s `L_FUNCTION_OPEN L_DEFINED_NAME ','
  arg_list ':' ')'` production) only builds that special call_other
  form when the token immediately after `(:` is a bare,
  compile-time-resolved NAME followed directly by a comma. A string
  constant (or even a called `this_object()`) instead falls through to
  the generic `L_FUNCTION_OPEN comma_expr ':' ')'` "expression
  functional" rule, which just evaluates the WHOLE thing as an
  ordinary C-style comma-expression and returns the value of the LAST
  operand, discarding everything before it and calling nothing at all.
  Confirmed empirically via a temporary `catch()` +
  `sprintf("%O", ...)` probe inserted into `query()`: invoking the
  closure printed `attr=(: <code>() :)` (an expression-functional, not
  a call_other pointer) and returned the literal string
  `"query_efuns"` verbatim -- no call ever happened. That bogus string
  then got treated as an object/path by the caller (`look.lpc`'s
  `act_ob->query(a_super)`), and the driver's own call_other-of-a-string
  fallback tried `compile_object("/query_efuns")`, which
  `virtuald.lpc`'s own generic-virtual-object `compile_object()`
  couldn't resolve either, falling back to `/adm/obj/virtual/0`, a
  path that ALSO doesn't exist -- triggering the driver's own
  `master::compile_object()` -> `virtuald::compile_object()` ->
  `master::compile_object()` self-referential recursion (since master
  unconditionally re-delegates every failed load back to virtuald),
  hard-crashing with `*Inherit chain too deep: > 30` on literally every
  `look` (and anything else touching `query(a_super)`/`query(a_contains)`).
  **Fix**: use `call_other` itself as the bare NAME (satisfying the
  grammar's special-cased shape) with the real target object/path and
  method name as BOUND arguments -- `(: call_other, SIMUL_EFUN_OB,
  "query_efuns" :)`. The query()-time argument (`key`) gets appended
  after the bound ones at invocation, giving exactly
  `call_other(SIMUL_EFUN_OB, "query_efuns", key)`, the old semantics.
  Applied the identical fix to `obj/weapon.lpc`'s
  `(: this_object, "query_damage_string" :)` (which ALSO first hit a
  separate, more obvious compile-time symptom: bare `this_object`
  -- no parens -- inside a closure literal is parsed as "call the
  this_object() EFUN with the following args," a hard compile error
  distinct from this runtime gap; even fixing that to `this_object()`
  -- called -- still only produces a broken expression-functional,
  not a working call_other pointer, until also rewritten through
  `call_other`). **This is a new, previously-uncatalogued AGENTS.md
  §6.2 bug class** -- added this session. Given how fundamental and
  silent this failure mode is (compiles clean, no error until the
  wrong return value is actually consumed, and even then no crash
  until something tries to use the bogus value as an object), any
  future archive using the classic `(: obj_or_path_expr, "method" :)`
  idiom for anything other than a bare bound NAME should be checked
  for this specifically.
- **A `valid_write()`/`valid_read()` save-file check forgot the driver
  appends the save extension** -- exactly AGENTS.md §7.49's documented
  class. `adm/std/master/valid.lpc`'s `valid_write`/`valid_read` both
  ended with `return (file == data_file(user));` where `data_file()`
  (a simul_efun) returns the bare path with no `.o` extension, while
  the driver's own `save_object()`/`restore_object()` pass the FULL
  suffixed filename. Every `save_data()` call -- including the very
  FIRST one, fired automatically during brand-new character creation
  by `new_user.lpc`'s `setup()` -- hard-errored with "Denied write
  permission in save_object()", silently aborting `setup()` mid-flow
  BEFORE it ever reached `switch_new_obj()`. Symptom: registration
  looked like it completed (name/password prompts all worked, reached
  a bare `>` prompt), but every single typed command produced only the
  generic fail message, because the connection was still attached to
  the ORIGINAL login object, never migrated to a real player body at
  all. Fixed with the standard widening: `file == data_file(user) ||
  file == data_file(user) + ".o"`.
- **`explode("/", "/")` returns an EMPTY array on this
  `SANE_EXPLODE_STRING`-built driver, not the two-element
  `({"", ""})` old MudOS returned** (AGENTS.md §6.7's documented
  class, previously found on `tmi2`). Hit THREE times in this archive
  (not just the usual single `master::domain_file()` boot-time probe):
  `adm/obj/simul_efun/domain_file.lpc`, `creator_file.lpc`, and
  `author_file.lpc` all did the same `path = explode(str, "/"); if
  (!path) return 0; switch (path[0]) {...}` shape, all three called
  transitively via `master.lpc`'s own `domain_file()`/`creator_file()`/
  `author_file()` delegators, all three hard-erroring "Array index out
  of bounds" on the driver's own first boot-time probe of `"/"`.
  Fixed all three with the standard `!path || !sizeof(path)` widening.
- **`indices()` is not a real efun on this driver** -- old MudOS's name
  for what this driver calls `keys()`. One hit:
  `bin/user/shell/nickname.lpc`.
- **`privp()` is not a real efun on this driver** (old MudOS predicate:
  "does this object have an effective uid, i.e. is it privileged").
  `wizardp()` DOES exist here and was already used correctly elsewhere
  in the archive; only `privp()` needed reimplementing (as a
  simul_efun: `geteuid(ob) && strlen(geteuid(ob))`). One call site:
  `bin/maker/objects/origin.lpc`.
- **`cat()`/`tail()` are not real efuns on this driver** -- classic
  MudOS file-display efuns (`cat(file[, start, num])` writes a file
  or a line-range of it directly to the current player and returns
  the line count; `tail(file)` writes the last 10 lines). Reimplemented
  as simul_efuns (AGENTS.md §6.2 already flags `tail()` as a known
  class; `cat()` is new). 6 call sites across
  `bin/maker/file/{cat,less,tail}.lpc`, `bin/maker/objects/log.lpc`,
  `adm/std/login/misc.lpc` (the login banner!), `adm/obj/mailer.lpc`.
- **`MUDOS_VERSION`/`MUDOS_ARCH` are not predefined on this driver**
  -- old MudOS injected these as compile-time macros; this driver
  predefines `__VERSION__`/`__ARCH__` (double-underscore) instead.
  Bridged with two `#define`s in `include/config.h`.
- **`MOVE_NO_ROOM` used as a `switch`/`case` label, but never
  `#define`d anywhere** (`bin/user/objects/give.lpc`) -- a genuine
  pre-existing author typo (AGENTS.md §6.6's class), not a conversion
  artifact. `include/move.h` defines `MOVE_OK`/`MOVE_FAILED`/
  `MOVE_ATTACHED`/`MOVE_FULL`/`MOVE_TOO_HEAVY`/`MOVE_TOO_BIG` but no
  `MOVE_NO_ROOM`. The adjacent fail message ("can't carry any more")
  matches `MOVE_FULL` exactly; fixed to that constant.
- **A comment-continuation typo, same shape as AGENTS.md §4.1's
  `qhxajh` finding but in a header, not a heredoc**:
  `adm/daemon/parsed.lpc`'s doc-comment block has one line missing its
  `//` prefix (`| direct_object_phrase preposition
  indirect_object_phrase`, meant as a continuation of the `// input:`
  line above it), leaving a bare `|` that's a hard syntax error.
  Genuine 1992-era author typo, not conversion damage (confirmed
  against the raw archive bytes). Fixed by adding the missing `//`.
- **Old MudOS silently allowed rebinding a typed `string` parameter to
  hold a `mixed *` value; this driver enforces the declared type
  strictly.** `bin/maker/objects/call.lpc`'s `do_command(string arg)`
  reused its own `arg` parameter to hold
  `(mixed *)previous_object()->parse_args(args) + dummy` (an array),
  a genuine 1990-era author habit (untyped/loosely-typed classic LPC),
  not a conversion bug. Fixed by introducing a separate, correctly
  `mixed *`-typed local (`parsed_args`) instead of reusing `arg`.
- **19 files' `inherit "/bin/bin_m"` (some with, some without the
  leading slash) pointed at a file that no longer exists at that
  path** -- but the content DOES exist, just relocated to
  `/adm/std/security/bin.lpc` (that file's own header comment still
  literally says `// file: /std/bin/bin_m.c`, confirming the move)
  without every reference being updated. This is a real, fixable
  archive-internal path-drift bug (the content exists), distinct from
  genuinely missing content -- confirmed by checking the moved file's
  actual implementation matches what every caller expects (a
  `do_command`/`execute`/permission-check base class for `bin/`
  commands). Fixed all 19 `inherit` statements to point at
  `/adm/std/security/bin`. This one bug alone accounted for the
  majority of the ~60 `lpcc_check.sh` failures found before any of the
  other fixes above (`Inherit chain too deep` cascading through the
  driver's virtual-object-compile fallback, same self-referential
  mechanism as the closure bug above, triggered by trying to load a
  file that plain doesn't exist at the referenced path).
- **`adm/daemon/whatisd.lpc` inherited `/bin/daemon/mand`**, a path
  that never existed anywhere in the archive; the real file is
  `/adm/daemon/mand.lpc`. A simple stale/typo'd path (`bin/daemon` vs.
  `adm/daemon`), fixed directly.

## 4. Compile-sweep triage: known-acceptable remaining failures (11 of 237)

All confirmed either (a) fragment-only files meant to compile ONLY as
part of `adm/obj/simul_efun.lpc`'s monolithic `#include` chain
(`existence.lpc`, `communications.lpc`, `to_object.lpc`,
`writef.lpc` -- all reference macros/globals that only exist once
pulled in via the parent file's own earlier includes; the parent file
itself compiles and loads cleanly, confirmed live), or (b) genuinely
unreachable dead/incomplete original content, none inherited by
anything live and none reachable from any in-game command:
- `std/i/tsh.lpc` -- an abandoned alternate shell implementation
  (its own header comment: "Brutally hacked up and destroyed by
  Buddha to install something 'better'"), `#include`s two headers
  (`commands.h`, `tsh.h`) that never existed anywhere in the archive.
  Never `inherit`ed by anything. `bin/maker/shell/tsh.lpc` (the `tsh`
  command wrapper) calls `pobj->tsh(str)`, which would fail at
  runtime since no player body inherits this file -- a genuinely
  broken, pre-existing, never-wired-up command, left as-is.
- `std/i/history.lpc` -- an incomplete bash-history-recall feature
  (`!!`/`!N` recall syntax) referencing `ptr`/`max`/`cmd_num`
  variables that are never declared anywhere in the file nor exposed
  by the `QUEUE_ADT` it uses. Never `inherit`ed by `std/i/shell.lpc`
  or anything else live -- genuinely incomplete original content.
- `bin/maker/test/ws.lpc` -- literally malformed at the type-declaration
  level (`nosave int\nstring do_command(path)` -- two conflicting
  return-type declarations on consecutive lines, plus an untyped K&R-
  style parameter), under a directory named `test/`. Never referenced
  elsewhere. Left as the author's own experimental scratch file.
- `bin/maker/objects/clean.lpc` -- `inherit CLEAN_UP;` where
  `CLEAN_UP` is never `#define`d anywhere in the archive (unlike
  `bin_m`, there is no relocated file to point this at instead).
  Never referenced elsewhere.
- `bin/maker/status/sockinfo.lpc` / `opcprof.lpc` -- call
  `dump_socket_status()` / `opcprof()`, MudOS-driver-level debug
  introspection efuns with no FluffOS equivalent at all (not
  reimplementable in pure LPC). Out of scope, same class as
  AGENTS.md §7.51's NTOS-heartbeat gap.
- `obj/terminal.lpc` -- `create()` calls `getuid(this_player())`; a
  standalone `lpcc_check.sh` isolated-load probe has no interactive
  `this_player()`, so this fails ONLY in isolation (confirmed:
  not preloaded, not cloned anywhere at boot, only ever created via a
  live player's own action, at which point `this_player()` is always
  valid) -- a known `lpcc`-vs-real-boot false positive (AGENTS.md
  §10.4).

## 5. Live playthrough (native driver)

Full flow verified in one continuous session, port 40261: fresh
registration (`fluffos` / `Mud@2026`) reaching `/room/start` ->
`look` (correct room description) -> `go east` (moves to the second
room, correct room-broadcast message to the departed room) -> `look`
again (correct new-room description) -> `quit` (clean disconnect
message). Re-login (the restore/existing-password path) verified
separately: password accepted, `look` shows `/room/start` again
(player position is not part of the minimal save data this archive
implements -- confirmed intentional/pre-existing scope, not a
regression, since `core::attrs`/`save_data()` never captured
environment in the first place). `debug.log` fully clean (zero error
lines) across every test session after all fixes above.

Also spot-checked: `help` (usage message with no args, as expected),
`who`, `uptime`, `version`, `inventory`, `say`. All correct.

**One additional finding, likely intentional design rather than a
bug** (no error signature; see AGENTS.md's "no error signature =
design" standard): `emote <text>` (free-form emote) and `mail`
require `a_permissions` >= 500 / >= 100 respectively, but NO code
path ever initializes a new player's `a_permissions` attribute at
all -- it silently defaults to 0. Every OTHER `bin/user/*` command
(look, go, say, inventory, drop, get, tell, etc. -- 30 of 33 total)
requires exactly permission 0 and works fine for a brand-new player;
only these two are gated. Given the MOTD's own text ("added a
security system (admin/promote, position, and so commands)") and that
`emote` is the one command letting a player type completely
unmoderated free text (unlike the canned-message `temote`/`semote`,
which both require only 0), this reads as a deliberate 1990s-era
anti-abuse gate requiring an admin to `promote` a vetted player before
they get free-text emote/mail access -- not a registration bug. Left
unmodified; documented here per the review standard rather than
"fixed."

## 6. WASM

Boots and plays identically under the WASM build
(`~/src/fluffos/build-wasm/src`, via `scripts/wasm_client.js`):
full password-login (reusing the same seeded account) -> `look` ->
`quit`, byte-for-byte the same output as native (modulo the expected
WASM startup noise/mojibake prefix before the listener is ready).
`wasm_status: playable`.

## 7. Admin account seeding detail

See `README.md`'s "Admin account" section for the procedure. Key
files touched: `adm/etc/groups` (added `fluffos` to the `(admin)`
group, alongside the original `truilkan:cynosure:sulam` -- not
replacing them), `data/users/f/fluffos.o` (the per-account "pith
file" PLAYER_D maintains independently of the main save; its
`a_filename` attribute, key 300, decides which player-body class
`std/user`/`std/maker`/`std/admin` a RETURNING login gets --
critically, ONLY on return-login via `check_password()`, not on the
very first login, since a brand-new account has no pith file yet and
always gets `"user"`), and `data/obj/i/admin/fluffos.o` (the actual
admin-class player save, seeded with `a_permissions=2999`
(`ADMIN(999)`) and `a_position="Admin"`, matching the archive's own
pre-shipped `truilkan` admin account's exact values byte-for-byte).
Verified: `update /bin/user/senses/look` succeeds (file write ACL via
the groups/access system), and `emote` (permission-gated, see §5
above) also works once promoted, confirming both independent
permission axes (file ACL vs. per-command `a_permissions` gate) are
correctly seeded.

Note: the archive ships a real 1992-era admin account (`truilkan`,
`data/users/t/truilkan.o`, crypted password unrecoverable) -- left
untouched, not reused, per this project's standard policy of never
guessing or discarding a pre-existing real account.

## 8. New AGENTS.md catalog entries added this session

1. **§6.2 addition**: `(: obj_or_path_expr, "method" :)` closures only
   build a real call_other pointer on this driver when the head is a
   bare compile-time NAME; anything else (string constant, called
   function) silently becomes a no-op comma-expression. Fix: route
   through `(: call_other, target, "method" :)`.
2. **§6.2 addition**: `new`/`class` as ordinary identifiers are
   unconditionally reserved keywords on this driver (object
   instantiation / typed-class syntax), unlike the compile-flag-gated
   `ref` (§6.7). Grep `\b(new|class)\b` in declaration position on any
   new archive.
3. **§6.2 additions**: `extract()`, `log_file()`, `privp()`, `cat()`
   are not real efuns on this driver (join the existing `tail()`
   entry) -- all reimplementable as simul_efuns per old MudOS manual
   semantics.
4. **§7 candidate**: a vestigial `private inherit` of an otherwise
   correctly-inherited base class can create an ambiguous SECOND copy
   of a needed public method, with this driver resolving unqualified
   calls to the wrong (private, uninitialized) copy -- check whether
   the private inherit is actually used before "fixing" by loosening
   its visibility.
5. **§4.2 item 4 confirmed on new content**: a `convert_lib.sh`
   `.c`->`.lpc` literal-string rename left a fixed-width extension
   slice (`[len-2..len-1]`) unwidened, permanently breaking a
   hand-rolled command-file cache -- every command in the game
   failed. Worth a proactive grep (`\[\(?len\s*-\s*[0-9]+\)?\.\.`) on
   any archive with a similar directory-scanning command cache.
