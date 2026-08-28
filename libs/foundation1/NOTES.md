# Foundation I -- porting notes

Source: `foundationI_fluffos_v1.zip`, recovered from the MUDBytes File
Repository (mudbytes.net, file #1043) via the Wayback Machine, since the
live mudbytes.net file-download endpoint is gone. The CDX API
(`https://web.archive.org/cdx/search/cdx?url=mudbytes.net/files/download/1043*&output=json`)
showed one 200-status snapshot, `20190802021701` (2019-08-02); fetched as
`https://web.archive.org/web/20190802021701id_/http://mudbytes.net/files/download/1043/`
(a 301-redirect snapshot for the bare, non-timestamped URL also exists but
resolves to nothing useful directly -- the exact 200 snapshot above is the
one that works). Content-verified: 2,329,667 bytes, a valid zip (`store`
compression), 1542 entries, 897 real files under `lib/` dated 1994-95.
Slug `foundation1`, number 946, port 40248. The zip bundles a
`fluffos-2.9-ds2.12` driver source snapshot, plus `bin/`, `win32/`, `old/`
build/install scaffolding -- all ignored, this project uses its own
driver. The real mudlib root is the zip's `lib/` directory (its own
`bin/mudos.cfg` confirms: `mudlib directory : /mud/foundation/lib`,
`master file : /secure/daemon/master`). A full-tree grep for
`driver_hook`/`set_driver_hook` across `lib/` returned zero hits,
confirming genuine MudOS/FluffOS lineage (not LDMud).

## Relationship to `foundation2` -- NOT a duplicate

This collection already has an unrelated `foundation2` (174, port 40221).
Foundation I and Foundation II are both by the same author, George Reese
("Descartes of Borg"), but they are two distinct, independently-shipped
releases:

- Foundation I is the **earlier, more primitive** release: its own
  `README` (dated 2 April 1995) is subtitled "A minimalist LPC Library"
  and explicitly says "The intention is to have all Nightmare references
  removed, solidify the design base, and customize the documentation for
  **Foundation II, which is due May 15**" -- i.e. Foundation I's own
  authors describe Foundation II as its direct successor/rewrite.
- Foundation I's `master.c` reads "from Nightmare 3.3 ... created by
  Descartes of Borg 940910"; Foundation II's own master carries the exact
  same "from Nightmare 3.3" header. Both are Nightmare-3.3-derived, but
  they are separately-maintained snapshots, not the same codebase --
  `md5sum`/`diff` against `libs/foundation2/work` on shared filenames
  (`master.lpc`, `daemon/banish.lpc`, `secure/daemon/events.lpc`) shows
  real, substantive differences (Foundation I's `master.lpc` doesn't even
  have `get_root_uid()`/`get_bb_uid()`/`creator_file()` -- Foundation II's
  already-fixed copy does, from an earlier port of the sibling lib).
- Both libs independently reference the historic `lpmuds.net` Intermud-3
  ecosystem and share the same install-your-own-content design
  philosophy ("no combat, limbs, or stats system at all"), but Foundation
  I is strictly older/less developed: it has no first-boot admin-setup
  installation wizard (Foundation II's biggest structural feature),
  simpler `master.lpc` (no privs-string caching, no domain/write-access
  wizard install flow), and ships example/teaching content
  (`domains/Examples`) with the SAME kind of incompatible-API content gap
  Foundation II's own two teaching trees have -- a strong signal these
  are sibling snapshots of the same evolving Nightmare-3.3-based engine
  lineage at two different points in time, not a re-upload of the same
  release.

`meta.json`'s `duplicate_of` is `null` -- this is treated as its own
distinct onboarding target per the task, not folded into `foundation2`.

## 1. Conversion

English-language archive (not GBK-encoded) -- `scripts/convert_lib.sh`
against `raw/foundationI_fluffos_v1/lib` confirmed this: 880/897 files
already valid UTF-8, 1 lossy conversion, 16 skipped binaries (compiled
`.o` save files under `secure/save/`/`daemon/save/`, correctly left
alone), 275 files renamed `.c`->`.lpc`, 81 literal `.c"` references
fixed, 9 local angle-bracket `#include`s converted to quotes, 76 files
touched by the `static`->`nosave` sweep. No stragglers (`*.C`, unrenamed
`.c`) after conversion.

## 2. Compile-time driver-compat fixes

- **`ref` is a reserved keyword on this driver** (call-by-reference
  parameter modifier, `REF_RESERVED_WORD`) -- exactly the bug class
  already catalogued from `shadowgate` (\S6.7) and `foundation2`/
  `nightmare3`. Four sites, all fixed by renaming the identifier:
  - `std/user/refs.lpc`'s `set_ref(string ref, ...)`/`get_ref(string
    ref)` -- this file is `inherit`ed straight into the player body
    class (`std/user.lpc` via the `REFS` macro), so this alone broke
    compilation of the ENTIRE player body. Renamed `ref` -> `refname`.
  - `daemon/refs.lpc`'s parallel `set_ref`/`get_ref`/`resolv_ref`
    (the daemon-side interface to the above) -- same rename.
  - `secure/daemon/master.lpc`'s `load_access(string cfg, mapping ref)`
    (plus its `master.h` prototype) -- renamed to `refmap`.
- **`class` is a reserved keyword on this driver** (the `class` struct
  type) -- `secure/SimulEfun/magic_class.lpc` declared `string class;`.
  This particular file is dead/unreferenced scaffolding (never
  `inherit`ed or `#include`d by anything real in this stripped-down lib
  -- `query_class()`/character classes don't exist here), so it never
  actually blocks a real boot, but it's the same reserved-word collision
  class and cheap to fix on sight: renamed to `classname`.
- **A `.c`->`.lpc` filename-slice arithmetic bug in the command-dispatch
  table** -- \S7.118's exact bug class, confirmed on a 6th lib in the
  same session. `daemon/command.lpc`'s `rehash()` builds the verb->path
  lookup by `get_dir(dir+"/_*.lpc")` then slicing `choses[j][1..
  strlen(choses[j])-3]` to strip the leading `_` and the extension --
  correct arithmetic for the ORIGINAL 2-character `.c` extension, but
  after this project's `.lpc` rename every single verb key comes out
  corrupted (e.g. `_look.lpc` -> `"look.l"` instead of `"look"`), which
  would have silently broken every ordinary player command with no
  compile error and no crash. Fixed: `-3` -> `-5` (stripping the leading
  `_` and the 4-character `.lpc` extension). This is Foundation I's own
  independent command dispatcher (`daemon/command.lpc`, "from Nightmare
  IV, created by Descartes of Borg 940119") -- NOT the same file as
  `foundation2`'s dispatcher, which was already fixed for an unrelated
  bug and never had this slice-arithmetic issue.
- **`PACKAGE_UIDS` is enabled in this project's driver build, and this
  master object never defined the two applies it requires** -- the exact
  same fix `foundation2`/`nightmare3` needed (same "from Nightmare 3.3"
  master.lpc lineage, but NOT byte-identical -- diffed independently).
  `set_master()` calls `exit(-1)` at boot if `get_root_uid()` is missing
  (confirmed via `lpcc`'s own "No function get_root_uid() in master
  object" message, and by reading `vm/internal/master.cc`). Added:
  `get_root_uid() { return "Root"; }`, `get_bb_uid() { return
  "Backbone"; }` (ported verbatim from the sibling libs' fix).
  `creator_file(string str)` -- also required by `PACKAGE_UIDS`, called
  by the driver on EVERY object load -- was likewise never defined here.
  Reuses this codebase's own existing top-level-directory privs
  classification (`secure/SimulEfun/security.lpc`'s `file_privs()`,
  already used by `check_access()`/`privs_file()` for this lib's real
  access-control model) rather than inventing a new uid scheme, with the
  same `sscanf(str, "%s#%d", base, ext) != 2` unmatched-`%s`-defaults-
  to-int-0 guard `foundation2`'s port needed for the same reason (a
  clone-suffix-free path is the overwhelming majority of calls, and an
  unmatched `%s` target keeps its int-`0` default, which would otherwise
  crash `file_privs()`'s own `explode()`/string indexing).
- **`status` as a legacy LPMud integer-return-type keyword, unsupported
  by this driver** -- `std/room/senses.lpc` declared `status
  smell_things(string str)` and `status do_listen(string str)`, both
  hard syntax errors (`unexpected L_IDENTIFIER, expecting L_ASSIGN or
  ';' or '(' or ','`) on this driver, which doesn't recognize `status`
  as a type keyword at all. This one file's failure cascaded into
  `std/room.lpc` and every room in the mudlib (`std/room` inherits
  `std/room/senses`), including the actual starting room. Fixed:
  `status` -> `int` at both sites (only 2 occurrences in the whole
  tree, verified by grep).
- **Missing `#include <save.h>`** -- `std/access.lpc` (an inheritable
  access-list daemon, "from Nightmare 3.2.2") referenced the
  `SAVE_EXTENSION` macro (defined in `secure/include/save.h`) but only
  `#include`d `<std.h>`, which doesn't pull it in. The only file in the
  whole tree with this specific gap (grepped every other `SAVE_EXTENSION`
  user first). Fixed by adding the missing include.
- **Genuinely dead code that still had to be made syntactically legal**:
  `daemon/refs.lpc`'s `resolv_str()` parses a `"(:%s,%s:)"`-shaped input
  string (an old-style anonymous-function literal typed by a wizard into
  a `ref`/`call`-style debug command) and tried to build
  `(: gtmp1, gtmp2 :)` -- a functional/closure literal binding
  parameters to `gtmp1`, a `mixed` GLOBAL VARIABLE, not a function name.
  This driver hard-rejects that shape at compile time regardless of
  whether the branch ever runs (`grammar_rules_exprs.cc`'s `FP_L_VAR`/
  `FP_G_VAR` case: "Can't give parameters to functional."). The branch
  guarding this return was ALREADY unreachable dead code even in the
  original archive -- its condition checks `stringp(tmp2)`, but `tmp2`
  is never assigned anywhere in the function (only `gtmp2` is, a few
  lines above) -- so `tmp2` is always its default-unset value and the
  branch can never actually execute. Fixed by replacing the illegal
  literal with `return gtmp2;`, preserving the branch's existing
  (already-dead) unreachability while making the file compile. This
  broke compilation of 10 wizard-only debug commands that `inherit`
  `daemon/refs.lpc` (`_ref`, `_refs`, `_eref`, `_dref`, `_tref`, `_call`,
  `_move`, `_unref`, `_cref`, and the ambassador `_ss`/`_sc` "set/show
  class" pair) -- none of these are on the player registration/gameplay
  critical path.

**`lpcc_check.sh` result after fixes**: 270/275 files pass. The
remaining 5 are pre-existing content gaps (see \S3), none boot-critical.

## 3. Pre-existing content gaps (not fixed -- out of driver-compat scope)

- `domains/Examples/etc/{match,torch}.lpc` (`inherit LIGHT;`) and
  `domains/Examples/etc/flu.lpc` (`inherit GERM;`) reference `LIGHT`/
  `GERM` macros that are simply never defined anywhere in this
  stripped-down lib's `secure/include/objects.h` (which only defines
  `OB_SIMUL_EFUN`/`OB_LOGIN`/`OB_USER`/`OB_SHUT`/`OB_WORKROOM`/
  `OB_POSTAL`) -- a bare, undefined macro used as an `inherit` target is
  a hard parse error (`unexpected L_IDENTIFIER, expecting L_STRING or
  '('`), not a resolvable "undefined identifier". `domains/Examples/etc/
  chest.lpc` similarly references an undefined `OB_COINS`. This is the
  exact same class of gap `foundation2`'s own two "Examples"/"School"
  teaching trees have (content written against a different, fuller
  snapshot of this evolving engine lineage that this particular archive
  never carried the matching macros for) -- not something this port
  introduced, and not fixable without inventing a currency/lighting
  subsystem this lib was never shipped with. `/domains/Examples/room/*`
  and `/domains/Examples/virtual/*` also fail, but only as a side effect
  of inheriting `std/room` -- these compile cleanly now that \S2's
  `status`->`int` fix landed; only the 4 files above (plus `cowtown`,
  next) are genuinely-broken content.
- `secure/etc/cowtown.lpc` (a standalone quest object, "Nightmare, March
  1993") does `inherit "std/quest_ob";` -- there is no quest subsystem
  anywhere in this archive at all (matches the lib's own `README`:
  "does not come with ... a combat system for a fantasy MUD, or a
  starter area"). Not preloaded, not reachable from the real starting
  room; a leftover example file from a fuller codebase this minimalist
  release never included.
- `domains/Standard/xtra/freezer.lpc` (the linkdead-holding room a
  disconnected player's body is moved to, see \S4) has its own `"square"`
  exit pointing at `/domains/standard/square` -- lowercase, vs. this
  archive's real `/domains/Standard/` (capitalized). Moot either way:
  `/domains/Standard/square` (any case) simply doesn't exist anywhere in
  this archive -- a genuinely pre-existing dead-end exit in the original
  1994-95 content, not something this port's file renaming touched
  (renaming `.c`->`.lpc` never changes directory-name casing). Only
  reachable from the freezer holding-room, not the main gameplay loop.
- **A dormant instance of the `nightmare3`-lineage `__AutoLoad`
  save-before-strip double-clone bug** (see the `nightmare3`/`dsI`/
  `finalrealms` catalog entries) exists byte-for-byte in shape in
  `std/user/autosave.lpc` -- identical function/variable names
  (`__AutoLoad`, `pre_save()`, `setup()`), identical mechanism (`setup()`
  unconditionally `new()`s every `__AutoLoad` entry with no presence
  check, `pre_save()` never strips carried auto-load items from
  inventory before `save_object()` serializes them). Unlike `nightmare3`,
  this is currently **inert**: grepping the whole tree for
  `query_auto_load` found only 2 generic consumers (`cmds/creator/
  _clean.lpc`, `std/clean_up.lpc`) and zero real content objects that
  ever override `query_auto_load()` to return a non-zero value -- no
  guild markers, no wedding rings, no disease objects, nothing. Calling
  an undefined function via `->` returns 0 on this driver, so the whole
  mechanism is a no-op today. Left as-is (matches this project's
  "genuinely not applicable" precedent, \S2.3) rather than
  speculatively hardening dead code with no observable behavior to
  verify against; flagged here in case future content ever adds a real
  auto-load item.
- **A real, intentional outbound network side effect at boot**: like
  `imud`/`foundation2`, `daemon/intermud.lpc` (preloaded by
  `secure/cfg/preload.cfg`) makes a genuine `socket_create()`/UDP
  handshake attempt toward a historic Intermud-3 nameserver hardcoded as
  `"204.209.44.3 8080"` a couple of seconds after boot. This project's
  driver build does have `__PACKAGE_SOCKETS__` compiled in (confirmed via
  `strings`/the driver's own LPC-predefines dump), so the file loads and
  the attempt happens -- almost certainly against a long-dead 1990s
  host, but a real outbound connection nonetheless. Per \S2.3's
  precedent, this lib should NOT be swept into high-frequency automated
  reboot loops (round-two/round-three-style re-test cron, \S10.0
  long-sit scans).
- **Pervasive, harmless `nosave`-on-function warnings**: this codebase
  (like its `foundation2`/`nightmare3` siblings) applies the `nosave`
  modifier to ordinary function declarations throughout (an old MudOS-
  era idiom this driver just warns about -- "Illegal to declare nosave
  function" -- rather than erroring on). Hundreds of instances,
  cosmetic only, left as-is; several other harmless warnings turned up
  too during live testing (`std/room/exits.lpc`'s `query_enters()`
  prototype/definition return-type mismatch, `secure/SimulEfun/
  time.lpc`'s `date()` likewise, `std/user/editor.lpc`'s `(: "return_to_
  edit" :)` functional-literal-wrapping-a-string-constant warning) --
  none of them affected any tested behavior.

## 4. WASM-era standard patches

- **Loopback-allow (\S1.3b)**: added a fail-closed short-circuit to
  `daemon/banish.lpc`'s `allow_logon()` (`ip == "127.0.0.1" || ip ==
  "::1" || strsrch(ip, "127.") == 0` -> `return 1`, before any real
  banish-list parsing). Note: on a fresh install this gate has nothing
  to actually block -- `__Sites`/`__WatchSites`/`__Allowed`/`__Guests`
  all default to `({})` in `create()`, so `allow_logon()` returns 1
  unconditionally for everyone regardless of this patch. Added anyway
  per the standing policy, and it's ready the moment any site/name
  restriction is ever configured.
- **Admin seeding (\S1.5)**: registered `fluffos`/`Mud@2026` through the
  normal registration flow (verified live, see \S5). This lib's security
  model is a directory-based privs/group scheme, not a `wiz_status`
  mapping -- granted admin by adding `fluffos` to the existing `(SECURE)`
  group entry in `secure/cfg/groups.cfg` (`adminname` -> `adminname:
  fluffos`, colon-separated per `master.lpc`'s own `load_access()`
  parser). `adminname` is the ORIGINAL archive's own unclaimed template
  placeholder (no matching save file exists under `secure/save/users/`,
  unlike the real historical `descartes` account that IS present there)
  -- left in place rather than removed, so the deviation from a truly
  pristine template stays minimal and documented. Verified live via
  `_call`/`_eval` (both `secure/cmds/creator/`, ambassador-tier-and-up)
  producing correct results as `fluffos` -- `check_access()`'s privs
  logic grants SECURE-privs objects unrestricted read/write, satisfying
  this project's usual "wizard command actually works" bar even though
  this lib has no single canonical `update`-style command to test
  against (its wizard toolset is the `_call`/`_eval`/`_ref` family
  instead).

## 5. Live verification

Booted the real native driver (`~/src/fluffos/build-debug/src/driver
config.fluffos`, cd'd into `libs/foundation1` first) repeatedly; zero
fatal errors, "Accepting telnet connections on 0.0.0.0:40248." /
"Initializations complete." every time. Full registration -> world
entry -> command verification, via `scripts/mudclient.py`, one
continuous session:

```
name: wizbaz -> y -> password (Mud@2026) -> confirm -> gender: female ->
display name: <blank, defaults to Wizbaz> -> email: test4@example.com ->
real name: <blank, defaults to "Unknown"> -> [news pager: <return>] ->
look -> status -> inventory -> quit
```

All correct: entered `domains/Standard/center` (the "Pool Room" --
"You find yourself standing in a large cavern, lit softly by glowing
lichen...") with its `make_pools()`-cloned pool object present, `look`
re-displayed the same room correctly, `status` (this lib's real
score-equivalent -- there is no `score` command anywhere in this
minimalist archive, matching its own README's "no ... stats system"
description, \S2.3-style) printed `hp: 1/10  sp: 1/10  mp: 1/10
experience: 0`, `inventory` printed `You are empty-handed.`, and `quit`
cleanly printed `Please come back another time!`. Also verified the
name-validation gate (`BANISH_D->valid_name()` correctly rejects
non-lowercase-alphabetic names, e.g. a name containing a digit) and the
admin account end-to-end (registration, `(SECURE)` grant, live
`_call me;move;/domains/Standard/center` returning `MOVE_OK` (0) plus a
correct `look` afterward). `log/errors/*` only ever accumulated the
harmless `nosave`-function/prototype-mismatch warnings cataloged in
\S3 -- no runtime crash signatures.

**Environment note, not a Foundation I bug**: in this session's sandbox,
a driver launched even with `setsid nohup ... & disown` (\S10.8's
documented workaround for "plain `nohup ... &` has died from stray
SIGTERMs between tool calls") still reliably stopped listening/exited
cleanly (no crash trace, no log signature) around the ~100-130 second
mark regardless of activity -- reproduced 3 times, including one run
where nothing at all was sent to it. Every actual registration/
gameplay verification above completed well inside that window in one
continuous client session, so this didn't block verification, but a
future session re-testing this lib (or debugging via a long-sit \S10.0
boot-watch) should budget for restarting the driver more often than
usual and not read a disappearance alone as a Foundation I-side crash
without also checking whether the process merely aged out of this
particular sandbox's process lifetime.

WASM status: not attempted this session (`wasm_status` left `""`).
