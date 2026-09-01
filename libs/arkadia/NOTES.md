# Arkadia (Genesis MUD - PL version) -- porting notes

Source: `git clone https://github.com/84rn/lpmud` (commit `4be73fa8167a17c246c6bf22a4f528a4b45edd40`,
cloned 2026-08-26). Slug `arkadia` (short, avoids the generic "lpmud"),
number 942, port 40244.

## 0. What this repo actually is

A Polish-language localization/fork of the same Genesis/CD-driver mudlib
engine already onboarded in this collection as `libs/genesis` -- this
collection's **first non-Chinese/English/German-language entry**. The
archive ships two config variants side by side: `config/sys/local.h` (the
active Polish config) and `config/sys/local.h.Genesis` (a reference copy of
the original English config, with wizard names like "postmaster"/"mrpr"/
"fatty"/"lars" and domain "Genesis" instead of "Standard"), which by itself
confirms this is a real derivative, not an independently-authored mudlib.

**Encoding**: the task brief assumed ISO-8859-2/CP1250 (the classic Polish
DOS/Windows encodings) and instructed verifying empirically rather than
assuming. The archive is actually **plain ASCII**: every Polish diacritic
(a/c/e/l/n/o/s/z/z with their accents) is written out unaccented throughout
-- source comments, in-game text, help files, *and* the game's own
input-validation code (e.g. `wlasciwe_imie()` only accepts `a`-`z`). The
default GB18030 `convert_lib.sh` pass was therefore already correct; no
re-encoding was ever needed.

## 1. Boot bridge (same fix as genesis)

Identical CD-driver-derived boot sequence to genesis: a custom
`start_boot()`/`preload_boot()`/`final_boot()` chain in `secure/master.lpc`
that FluffOS never calls on its own. Bridged with the same `epilog()`
pattern already proven in `libs/genesis/work/secure/master.lpc`:

```lpc
mixed
epilog(int eflag)
{
    string *prefiles;
    int i, n;

    prefiles = start_boot(0);
    n = sizeof(prefiles);
    for (i = 0; i < n; i++)
        preload_boot(prefiles[i]);
    final_boot();
    return 0;
}
```

Also needed `valid_override(string file, string name, string main_file) {
return 1; }` in master.lpc (`std/living.lpc`'s `efun::command(cmd)` call
requires it) and `#undef ALWAYS_APPLY` in `config/sys/local.h` (bypasses the
human-review "podanie" application gate for local/solo testing -- matches
this project's standing precedent, AGENTS.md 1.3e, and the archive's own
`local.h.Genesis` alternate which ships the same way).

## 2. CD-driver -> FluffOS dialect sweep

Same catalogue of fixes as every other CD-driver-family lib in this
collection (genesis, wxddym, shenmo, etc.):

- **`&operator(OP)(args) @ INNER` / `&FUNC(, args)` / `&->method(...)`
  composition and partial application** -- unsupported on FluffOS, converted
  throughout `std/`, `secure/`, and `d/Standard/` to `(: FUNCNAME, bound... :)`
  closures or small `private __*_bound()` helper functions. Dozens of call
  sites across `secure/master.lpc`, `secure/master/fob.lpc`,
  `secure/master/notify.lpc`, `secure/master/guild.lpc`, `secure/mbs_central.lpc`,
  `secure/master/mail_gc.lpc`, `std/object.lpc`, `std/container.lpc`,
  `std/receptacle.lpc`, `std/living/things.lpc`, `cmd/live/things.lpc`,
  `cmd/live/social.lpc`, `cmd/wiz/lord.lpc`, `cmd/wiz/apprentice/communication.lpc`,
  `lib/store_support.lpc`, `std/player/more.lpc`, and `sys/filter_funs.h`'s
  macros (`FILTER_GENDER`/`FILTER_RACE`/`FILTER_CAN_SEE` etc.).
- **Closures cannot capture enclosing-function locals** (including sibling
  function *parameters*, and macro parameters that resolve to real locals)
  -- every fix above uses bound arguments (`(: FUNCNAME, local_var :)`),
  never a bare closure referencing an outer local.
- **`previous_object(-1)` semantic mismatch**: FluffOS's `previous_object(-1)`
  is a special alias for `all_previous_objects()` (returns an *array* of the
  whole call chain), not "one level further back" as ~20 call sites across
  `secure/master/fob.lpc`, `std/object.lpc`, and `d/Standard/login/ghost_player.lpc`
  assumed (confirmed by reading FluffOS's own `f_previous_object()` C
  source). Fixed with a `calling_object(int n)` simul_efun that walks
  `all_previous_objects()` -- same proven fix as genesis.
- Reserved-keyword collisions (`new`, `old`, `class`, `status`, `in` --
  `sys/global/cmdparse.lpc`'s `in_containers()` had an unused `int in;`
  local, a straightforward FluffOS reserved-word conflict), the Elvis
  operator (`a ?: b`), old-MudOS `TYPE name = expr` parameter defaults,
  `varargs` placement, `[..N]` omitted-start slices, `m_indexes`/`m_sizeof`/
  `mappingp`/`extract()` renames -- all handled by the same mechanical
  sweeps used throughout this collection.
- `secure/simul_efun.lpc` gained the same family of CD-driver-only-efun
  shims as genesis: `query_auth()`/`set_auth()` (a `private mapping
  auth_map` simulating this driver's uid:euid string-pair model, with a
  **realistic default** of `creator_object(ob) + ":0"` for never-set objects
  rather than a bare `"0:0"` -- see the auth bug below), `calling_object()`/
  `calling_program()`/`calling_function()` (via `call_stack()`), `wildmatch()`
  (translated to an anchored `regexp()`), `m_indexes`/`m_values`/`m_sizeof`/
  `m_delete`, `ftoa`/`ftoi`/`itof`, `set_alarm`/`remove_alarm`/`get_alarm`,
  `slice_array`, `break_string`, `val2str`/`mkmapping`, `restore_map`/
  `save_map`, and several more.

## 3. New-to-this-port bugs (beyond the standard catalogue)

- **Uninitialized `private mapping` globals in `secure/master/fob.lpc`**:
  `m_domains`, `m_wizards`, `m_applications`, `m_trainees`, `m_global_read`
  were declared with no initializer, so indexing any of them before the
  first real assignment threw "Value being indexed is zero" -- the single
  dominant crash class in the initial `lpcc_check.sh` batch sweep (163+
  failures). Fixed with `= ([])`. This one root cause was far more
  effective than patching individual call sites with `mapp()` guards.
- **Uninitialized array globals in `std/living/savevars.lpc`**:
  `cmdsoul_list`, `tool_list`, `textgivers` had no `= ({})` initializer,
  crashing `add_textgiver()` (and therefore every living object's very
  first command-soul setup) on `create()`.
- **The shipped `syslog/KEEPERSAVE.o` is a real but empty dev snapshot.**
  `restore_object(SAVEFILE)` succeeds against this file (it exists), so
  `master.lpc`'s own `load_fob_defaults()` fallback (which would otherwise
  populate `m_domains`/`m_wizards` from `config/sys/local.h`'s
  `DEFAULT_WIZARDS`/`DEFAULT_DOMAINS`) never ran -- `m_domains ([])` /
  `m_wizards ([])`, completely empty, confirming this was the original
  author's own never-really-set-up local test instance, not something this
  port broke. Renamed aside as `syslog/KEEPERSAVE.o.orig-empty-backup` so
  `load_fob_defaults()` runs for real. This is also what caused every
  `/d/Standard/...` preload file to fail with "Read access denied" during
  the first working boot (19 of the 24 initial preload failures):
  `valid_read()`'s domain-membership check requires `query_domain_number("Standard")
  != -1`, which is only true once a real "Standard" domain exists.
- **`DEFAULT_DOMAINS`'s own tuple layout was one field short and had
  MEMBERS/STEWARD swapped**, in *both* this file and the shipped
  `local.h.Genesis` alternate -- a genuine pre-existing bug in the original
  archive, never previously exercised because of the empty-KEEPERSAVE.o
  issue above. `secure/master/fob.lpc`'s own `FOB_DOM_*` constants (and its
  own `add_domain()`, which builds
  `({ dom_count++, sname, wname, "", ({ }), "", DOMAIN_MAX, 0, 0, 0 })`)
  expect 10 fields: NUM, SHORT, LORD, STEWARD, MEMBERS, MADWAND, MAXSIZE,
  QXP, CXP, CMNDS. The shipped macro instead wrote the members array where
  STEWARD belongs and an empty string where MEMBERS belongs, with only 9
  fields total -- so the moment this data was ever actually loaded,
  `query_mage_links()`'s `m_domains[WIZARD_DOMAIN][FOB_DOM_MEMBERS]` read
  that stray `""` and crashed `start_boot()` itself with "Bad type argument
  to +. Had array and string". Fixed to match `fob.lpc`'s real field order.
- **`ghost_player.lpc`'s bare `enter_game(...)` call lost `previous_object()`
  context inside an `input_to()` callback chain** (`end_query()` ->
  `next_query()` -> `ghost_start()`), crashing `enter_game()`'s own
  `MASTER_OB(previous_object())` check on `file_name(0)` and silently
  aborting **every single new character's promotion into the game**, right
  after the registration Q&A finished. Fixed with an explicit
  `this_object()->enter_game(...)` (forces a fresh call frame so
  `previous_object()` resolves to `ghost_player` itself, which passes the
  check).
- **`query_auth()`'s bare `"0:0"` default blocked all privilege
  elevation**, including ordinary login: `seteuid(creator(this_object()))`
  computed the right creator string but `valid_seteuid()`'s own checks all
  require the *caller* to already have some established identity, which a
  bare `"0:0"` default never satisfies. Fixed by making `query_auth()`
  lazily default to `creator_object(ob) + ":0"` for any object that was
  never explicitly `set_auth()`'d, matching this driver's automatic
  uid-assignment-at-creation guarantee.
- Missing `/players/<letter>/` save-directory buckets (only `players/r/`
  shipped, containing the original author's own real archived wizard save
  `root.o.backup`, an elf character -- left untouched). Created the
  remaining 25 letter directories.

## 4. Registration flow -- Polish grammatical-case declension

New characters must type out all 6 Polish grammatical cases of their own
name (mianownik/dopelniacz/celownik/biernik/narzednik/miejscownik),
validated (`a`-`z` only, length >= 3) with a re-confirmation window in the
first 6 hours of play -- a genuine, intentional localization feature, not a
bug. Standard English soul commands are fully replaced with Polish
equivalents (`spojrz`/`sp` for look, `zakoncz` for quit, `stan` for score,
`nagraj` for save, `haslo` for password); the old English names show
"deprecated" messages. Password policy requires >=6 chars, at least one
non-letter, and **must both start and end with a letter** -- the task's
mandated seed password `Mud@2026` fails this (ends in a digit); used
`Mud@2026x` instead for the seeded admin account (see section 6).

## 5. Known content gaps (pre-existing, not FluffOS-related -- documented,
not fixed, per this project's driver-bugs-only scope)

Both confirmed via direct code reading, not guesswork:

1. **Every new character's `GP_EMAIL` ghost-flag bit never gets cleared**
   after `ghost_player.lpc`'s own `ask_player()` already collects email
   inline (`GP_NEW` sets `GP_BODY|GP_EMAIL|GP_FEATURES|GP_SKILLS` and
   nothing in the registration path ever clears the `GP_EMAIL` bit alone).
   `query_default_start_location()` checks `GP_EMAIL` *first*, so every new
   character's very first arrival gets routed through
   `d/Standard/login/email.lpc`, a room whose `enter_inv()` re-triggers a
   second, near-identical copy of the same declension+email Q&A
   (`email.lpc` has its own independent `ask_player()`/`next_query()`/
   `q_odmien_*()` functions, byte-for-byte-similar to `ghost_player.lpc`'s).
   Confirmed via server-side instrumentation (temporary `log_file()` calls
   in `ask_player()`, since removed) that `ghost_player.lpc`'s own
   `ask_player()` really does fire only once per registration -- the
   duplicate text is genuinely a second, separate function in a different
   file, not a double-invocation bug. `email.lpc`'s own `end_query()`
   *does* clear `GP_EMAIL` once completed, so this is a one-time,
   self-resolving, non-crashing redundant prompt on a character's first
   arrival, not an infinite loop or persistent problem.
2. **The "become an embodied player" pipeline appears incomplete/unreachable
   as shipped.** `sala.lpc` (the race-choosing hall) offers `dotknij <race>`
   (touch a race statue, calls `set_race_name()` immediately) then `przejdz
   przez portal` (enter the portal), which is supposed to call `gotow()` ->
   `ghost_ready()` (clones the real race body, hands over a "declension
   correction" item, `exec()`s the connection to it). But:
   - `portal()`'s own precondition is `this_player()->query_ghost() == 0`
     (den ies with "you still need a body first" otherwise) -- yet nothing
     anywhere in the whole tree ever clears the `GP_BODY` bit (grepped for
     `~GP_BODY` and any `GP_BODY`-clearing assignment; only two sites *set*
     it, none clear it), so this precondition can never become true through
     the coded `dotknij()` path.
   - `gotow()` (the function that actually performs the embodiment) has
     **zero callers anywhere in the codebase** -- it's dead code as shipped.
   A character can register, log in, save/reconnect across a driver
   restart, and use basic ghost-level commands (`spojrz`, `stan`, `kto`,
   etc. via the ghost command souls `soul_cmd_ghost`/`misc_cmd_ghost`), but
   never actually leaves "ghost" status through normal play. This also
   means wizard-only command souls (granted only via a real embodied
   player's own `start_player()`, never a ghost's) are unreachable even for
   an account with keeper rank in `m_wizards` -- see section 6.

## 6. Admin account bootstrap

Per this project's standard practice, `root` is already occupied by the
archive's own real archived save (`players/r/root.o.backup`, an elf
character with real history) and was left untouched. Seeding a fresh
`fluffos` admin account needed a **two-step bootstrap** because of a
chicken-and-egg problem in `secure/login.lpc`'s `new_character()`: it
refuses to let a brand-new mortal register any name for which
`SECURITY->query_wiz_rank(name)` is already nonzero ("this name once
belonged to a wizard and was not properly released"). Listing `fluffos` in
`DEFAULT_WIZARDS` *before* it had ever registered would have made it
permanently unregistrable through normal play.

1. Registered `fluffos` as an ordinary mortal via the normal `nowa` flow
   (password `Mud@2026x` -- see the password-policy note in section 4),
   while `config/sys/local.h`'s `DEFAULT_WIZARDS`/`DEFAULT_DOMAINS` still
   only listed `root`/`wiz`. Player file created at `/players/f/fluffos.o`.
2. Added `"fluffos":({9,50,"root","Wiz","root",})` to `DEFAULT_WIZARDS`
   (keeper rank 9, matching `root`) and `"fluffos"` to the `"Wiz"` domain's
   member list in `DEFAULT_DOMAINS`, then removed the (by-then-regenerated)
   `syslog/KEEPERSAVE.o` again so `load_fob_defaults()` re-populated with
   `fluffos` included, without touching the already-separate
   `/players/f/fluffos.o` player file.

Login as `fluffos`/`Mud@2026x` shows the keeper-only "Mistrz" title on the
`kto` (who) listing, confirming `query_wiz_rank()` recognition works.
Exercising actual privileged wizard *commands* is blocked by the
unreachable-embodiment gap in section 5.2 (wizard command souls are never
granted to a still-ghost character regardless of rank) -- this is a content
gap inherent to the archive, not something specific to the admin account or
to this port.

For testing purposes only (not a mudlib code change), `fluffos`'s own saved
`is_ghost` flag was hand-edited from 30 (`GP_NEW`) to 26 (clearing just the
`GP_EMAIL` bit) in `/players/f/fluffos.o` to stop the redundant
email-room detour described in 5.1 from re-triggering on every reconnect
during testing; `GP_BODY` (and therefore the embodiment gap in 5.2) was
left as-is since there is no reachable in-game path that would set it
differently for a real player.

## 7. Verification performed

- `lpcc_check.sh` batch sweep, iterated to convergence: only 5 files remain
  unfixed, all in an isolated wizard-admin-tool cluster with their own
  independent, pre-existing internal syntax errors unrelated to the CD
  driver/FluffOS porting work (`cmd/wiz/apprentice.lpc` via its
  `files.lpc` fragment, `cmd/wiz/normal.lpc`, `cmd/wiz/mbs.lpc`,
  `secure/mbs_central.lpc`, `cmd/std/tracer_tool.lpc`) -- `preload_boot()`
  catches each gracefully (logged, not fatal), and none of the five sit on
  the registration/login/gameplay path actually exercised. One fix *was*
  applied outside that cluster: `cmd/wiz/apprentice/communication.lpc`'s
  three `&operator`/`&->`/`@` composition sites (an "audience" list
  formatter, a wizline-channel rank filter, and a busy-status filter) were
  converted to bound helpers, since those were genuine CD-driver-syntax
  issues distinct from the cluster's own pre-existing bugs; the file still
  doesn't fully compile because of separate, unrelated pre-existing errors
  in its sibling `files.lpc` fragment and in `apprentice.lpc` itself.
- Real driver boot (`~/src/fluffos/build-debug/src/driver config.fluffos`):
  clean boot, 92 preload-list files, 87 succeed, 5 known-cluster failures
  (see above), zero crashes.
  - Multiple full driver restart-and-reconnect cycles performed over the
    course of testing (this satisfies AGENTS.md 7.120), including
    reconnecting into a previously-registered character across a restart
    with save data intact (confirmed via `Ostatnie logowanie`/"last login"
    banner and `imiona`/`mailaddr` fields surviving in
    `players/f/fluffos.o` and other test characters' save files).
- New-character registration verified end-to-end multiple times with
  distinct real Polish names: name entry, name-collision/profanity/
  reserved-wizard-name checks, password policy enforcement, the full 6-case
  declension Q&A (including the length-validation retry path), email
  set/skip, and arrival at a live `> ` command prompt with `spojrz`/`stan`
  producing correct output.
- No outbound network connections observed at boot or during any
  registration/gameplay testing (checked via `ss`/process inspection
  during and after boot; no `socket_create`/`socket_connect` call sites
  found anywhere in the source either).

## 8. Deep functional test (round two) -- 2026-08-27

One continuous session per AGENTS.md §10.7: read `?wprowadzenie`/
`?trening` first, registered multiple real Polish characters through
the full flow (name/password/6-case declension/email), exercised
`spojrz`/`stan`/`inwentarz` at every state change, tested `zakoncz`
(quit) with a `debug.log` grep before and after, and reconnected both
within the same driver process (to exercise the still-live "revive"
code path) and after killing and restarting the driver (to exercise a
genuine cold restore). Admin login re-verified: `fluffos`/`Mud@2026x`
still authenticates and shows the keeper-only "Mistrz" title.

Four new, previously-undetected, live-reproduced bugs found and fixed
this pass -- all invisible to the original onboarding's shorter smoke
test for the same reason every §10.7 bug is: none of them can surface
without either a long wall-clock wait, a genuine abrupt disconnect, an
actual `quit`, or a look at a room with no dynamic content, none of
which a boot-watch or a brief registration walkthrough exercises.

### 8.1 `do_decay()` map()-over-mapping argument mismatch (AGENTS.md §7.132)

`secure/master/fob.lpc`'s `decay_exp()` (`m_domains = map(m_domains,
do_decay);`, called from `check_memory()` on a ~900-second
`reset_master()` alarm) crashed with `*String index out of bounds`
every time the alarm actually fired, because `do_decay(mixed *darr)`
only declares ONE parameter but this driver's `map()` over a MAPPING
always calls the function with `(key, value)` -- so `darr` silently
bound to the domain NAME (a string), not its data array. Caught live
on a real boot: the very first `reset_master()` tick after boot
crashed with the trace showing the string `"Standarc"` -- a byte-by-
byte corrupted `"Standard"`, decremented one character at a time by
`do_decay()`'s own arithmetic running against string bytes instead of
array elements, right up until an index walked past the string's
length. **Fix**: `do_decay(mixed *darr)` -> `do_decay(string dname,
mixed *darr)`. Verified live: after the fix, a full driver restart and
a second real 900+ second wait produced ZERO `do_decay`/`fob.lpc`
crashes in `debug.log` (confirmed by letting the final verification
driver run past the alarm interval before killing it -- see the
verification section below).

**Sibling check**: `libs/genesis` (the English-language ancestor this
port is a fork of) has the byte-identical bug in its own
`secure/master/fob.lpc`. Fixed there too; not exercised through a real
900-second alarm on that repo (it ships no domain content, so
`m_domains` never accumulates real decay-able data), verified only via
a boot-and-kill compile check. See `libs/genesis/NOTES.md`.

### 8.2 Missing `net_dead()` boot bridge + a companion type-mismatch crash (AGENTS.md §7.133)

The single most impactful finding this pass. `secure/master.lpc`
implements `remove_interactive(object ob, int linkdied)`, documented
as "Called from GD if a player logs out or goes linkdead" -- the
classic-driver convention of the game driver notifying the MASTER
object of every disconnect. This driver does no such thing: its own
disconnect teardown (`src/comm.cc`) calls a `net_dead()` apply
directly on the DISCONNECTING PLAYER OBJECT, with zero arguments, and
ONLY when the object hasn't already been destructed (an orderly `quit`
already destructs itself first, so the apply never fires for a clean
quit -- only for a genuine abrupt disconnect). A codebase-wide grep
found **zero** `net_dead` references anywhere in this mudlib: every
single abrupt disconnect was a complete, silent no-op. Confirmed live
via `debug_message()` instrumentation (since removed) that
`remove_interactive()` was NEVER once invoked across multiple raw
socket-close-and-reconnect cycles pre-fix.

The downstream symptom that led to this: reconnecting to a
disconnected character reported `"Straciles polaczenie na 20692 dni 14
godzin ... sekund"` ("You lost your connection for 20692 days...") --
`time() - query_linkdead()` computed against a `query_linkdead()` that
had never once been set (defaulting to `0`, the Unix epoch), followed
by `"Couldn't locate the location where you link died. Moving you to
your start location."`, since the statue-conversion mapping
(`d/Standard/obj/statue.lpc`'s `places[ob]`) was never populated
either.

**Fix**, added to `std/player_sec.lpc` alongside this codebase's own
`linkdie()`/`revive()`/`actual_linkdeath()`:
```lpc
nomask void
net_dead()
{
    SECURITY->remove_interactive(this_object(), 1);
}
```
Verified live via `debug_message()` tracing (confirmed the apply now
fires on a raw socket close) and via observed behavior change: before
the fix, a disconnected character's object was silently abandoned in
memory forever (still alive, still not destructed, no cleanup of any
kind attempted); after the fix, `remove_interactive()` now genuinely
runs every time.

**A second, closely-related crash surfaced once this bridge started
working**: `d/Standard/obj/statue.lpc`'s `revive()` declares `object
roomob;`, and its own fallback path (reached when the original
link-death location can't be found) did `roomob =
ob->query_default_start_location();` -- a function that returns a
STRING, not an object (exactly like this same function's OTHER,
correctly-handled `stringp(room)` branch a few lines above, which
correctly resolves it via `find_object()`). Assigning a string
straight into a strictly-typed `object` local threw `*Trying to put
string in object` uncaught, aborting `revive()` before it ever reached
the actual `move_living()` call or the `places[]`/alarm cleanup at the
end of the function. **Fix**: resolve `start_loc` through
`find_object()` (with the same lazy-compile retry the sibling branch
above it already uses) before the assignment.

**Honest caveat on live verification depth**: this mudlib's own
"become an embodied player" pipeline is unreachable as shipped (see
§5.2 above, a pre-existing, out-of-scope content gap, unchanged by
this pass) -- every test character, including the seeded admin
account, remains permanently classed as `/d/Standard/login/ghost_player`,
which is ALSO this codebase's own `LOGIN_NEW_PLAYER` constant (the
throwaway swap-dummy class used transiently during login handoff).
`remove_interactive()`'s own first guard (`if (master_ob ==
LOGIN_OBJECT || master_ob == LOGIN_NEW_PLAYER || ...) { ob->
remove_object(); return; }`) therefore ALWAYS takes the "just discard,
no linkdeath tracking" branch for every character in this snapshot --
by design, correct for a not-yet-embodied ghost, but universal here
only because of the separate embodiment gap. This means: the
`net_dead()` bridge fix itself IS fully live-verified (confirmed via
tracing that it now fires, and that `remove_interactive()` now
genuinely runs instead of doing nothing), but the deeper
`linkdie()`/`actual_linkdeath()`/statue-conversion/`revive()` chain
(including the `roomob` type-mismatch fix) could NOT be exercised
end-to-end through real play this pass, since no test character can
ever leave ghost state to take that branch. Both fixes are verified
via direct code reading, a clean compile, and a clean boot; the
`revive()` fix specifically mirrors an already-proven-correct pattern
two lines above it in the same function. A future pass that either
fixes the embodiment gap or synthesizes an embodied test object
directly (e.g. via a temporary `eval`-equivalent, not available here
since wizard command souls are equally gated behind embodiment) should
re-verify the full chain live.

### 8.3 Uninitialized `room_descs` breaking every room's `look` (AGENTS.md §7.134)

`std/room/description.lpc`'s `room_descs` (a per-room list of extra
descriptions dynamically contributed by present items via
`add_my_desc()`) was declared `nosave mixed room_descs;` with no
initializer. `long()` -- the function that runs on literally every
single `look`/glance at any room -- unconditionally opens with `while
((index = member_array(0, room_descs)) >= 0) { ... }`, and this
driver's `member_array()` requires a real string or array for its
second argument; called against a bare `0` it threw `*Bad argument 2
to member_array() Expected: string or array Got: 0` uncaught,
aborting `long()` immediately -- before ever returning the room's own
already-fully-built flavor text (sitting one local variable away) or
letting the caller append the exit list. Since `add_my_desc()` is an
opt-in feature only a minority of items ever call, this crashed on
essentially every look at every ordinary room, game-wide, from the
very first boot -- reproduced live: pre-fix, `spojrz` in the starting
hall (`d/Standard/login/sala`) printed only the bare room path
(`/d/Standard/login/sala`) and nothing else, no flavor text, no exit
list.

**Fix**: `nosave mixed room_descs;` -> `nosave mixed room_descs =
({});`, fully behavior-preserving (verified against `add_my_desc()`'s
own `if (!room_descs) ... else room_descs = room_descs + (...)` logic,
which produces an identical result starting from `({})` as from `0`
regardless of whether an empty array is itself truthy or falsy on this
driver). Verified live: after the fix, `spojrz` in the same room
prints the full flavor text AND `"Jest tutaj jedno widoczne wyjscie:
poludnie."`, both on first arrival and on every repeat look; confirmed
across two different rooms (`sala` and its southern neighbor).

**Sibling check**: `libs/genesis` has the byte-identical bug in its
own `std/room/description.lpc`. Fixed there too (not live-exercised on
that repo -- it ships no domain content -- verified via a boot-and-kill
compile check only). See `libs/genesis/NOTES.md`.

### 8.4 `query_list_temp_start()` missing its siblings' lazy-init guard, breaking `quit()` entirely (AGENTS.md §7.135)

The textbook `bxsj`-style silent quit crash this project's own §10.7
methodology was written around. `zakoncz` (quit) looked completely
normal pre-fix -- a bare prompt with no error -- but `debug.log` showed
`std/player/cmd_sec.lpc`'s `quit()` crashing uncaught inside its own
`check_recover_loc()` call with `*Bad type argument to +. Had int and
array`, meaning `quit()` aborted before ever reaching `save_me()` or
the player's actual removal from the game: the character was silently
NEVER saved and NEVER removed on every single quit, on a fresh boot,
until some other code path happened to touch `temp_locations` first.

Root cause: `secure/master.lpc`'s `temp_locations` global has three
consumer/mutator functions that all correctly lazy-default it
(`check_temp_start_loc()`, `add_temp_start_loc()`,
`remove_temp_start_loc()`, all doing `if (!temp_locations)
temp_locations = TEMP_STARTING_PLACES;`) -- except the plain query
function, `query_list_temp_start()`, which just returned
`secure_var(temp_locations)` with no guard. Nothing in a normal login
path calls any of the guarded functions (only a rare explicit
temporary-start-location override does), so `temp_locations` stays a
raw, never-assigned `0` for the life of a fresh boot. `sibling
def_locations`/`query_list_def_start()` happens to be safe only
because `enter_game()` unconditionally calls `check_def_start_loc()`
(which DOES have the guard) as an unrelated side effect on every
login -- `check_recover_loc()`'s `SECURITY->query_list_temp_start() +
SECURITY->query_list_def_start()` therefore always combined a raw `0`
with a real array, crashing every time.

**Fix**: added the identical guard to `query_list_temp_start()`, and
defensively to `query_list_def_start()` too (since its own safety was
accidental, not guaranteed). Verified live end-to-end on the `fluffos`
admin account: `zakoncz` now prints `"Nagrywam postac."` and completes
cleanly (zero `debug.log` errors), and a subsequent reconnect shows
the correct, just-updated `"Ostatnie logowanie"` timestamp and host
(`"Cz, 27 VIII 2026, 07:56:24 z hosta: localhost"`, replacing the
stale `"Sr, 31 XII 1969, 16:00:00"` default every account had shown in
every earlier test this session, itself evidence this bug had silently
prevented a real quit-save from ever succeeding before).

### 8.5 Minor: dangling alarm on a destructed login-flow helper object (not in AGENTS.md -- low severity, single instance)

`d/Standard/login/set_cechy.lpc` (a transient "/wybieracz/" helper
clone driving the trait/appearance-selection Q&A through a chain of
self-rearming `set_alarm(..., (: akcja :))` calls) could be destructed
(several `remove_object()` call sites in the file) while one of its
own alarms was still outstanding, producing `*Owner (.../set_cechy#N)
of function pointer is destructed` uncaught the next time that alarm
fired -- cosmetic only (a stopped typewriter-reveal effect on an
object that no longer exists, logged once, no gameplay impact, does
not accumulate), but a genuine dangling-timer bug. **Fix**: added a
`remove_object()` override that calls `remove_alarm(alarm_id)` before
deferring to `::remove_object()`, closing every one of this file's
several destruction paths through one choke point.

**Left unfixed, documented only**: an apparently-identical shape was
also observed once for `/secure/login#N` (`*Owner (/secure/login#13)
of function pointer is destructed"`, same `__alarm_fire()` site).
`secure/login.lpc` already carries the SAME lazy-cleanup idiom
correctly at roughly a dozen call sites (`remove_alarm(time_out_alarm)`
before nearly every handoff/exit point) -- this looks like a single
narrow edge case in an otherwise carefully-guarded state machine, and
given the low (cosmetic-only) severity plus the risk of a subtle
regression in a heavily-alarm-managed login flow I did not have time
to fully trace this session, it was left as an honest observation
rather than a guessed fix. Worth a closer look in a future pass if it
recurs.

### 8.6 Eight standing cross-cutting patterns (§7.121/§8.3a/§7.122/§7.123/§7.124/§7.126/§7.129/§7.130) -- all checked systematically, confirmed clean

- **§7.121** (float arithmetic in a declared-`int` function): checked
  every shop/bank/economy file (`lib/shop.lpc`'s `query_buy_price()`/
  `query_sell_price()`, `sys/global/money.lpc`, `std/coins.lpc`) --
  all pure integer arithmetic throughout, no float locals, no bare
  `(int)` casts on a computed (rather than passed-through) value.
  Clean.
- **§8.3a** (`private` command-dispatch/callback function demoted via
  inheritance): grepped every `private nomask` declaration codebase-
  wide against `add_action`/`call_out`/`set_alarm` usage AND against
  whether the declaring file is ever actually `inherit`ed elsewhere.
  Only one real inheritance case exists (`std/board.lpc` ->
  `d/Standard/lib/common_master.lpc`): its `add_action`-registered
  functions (`list_notes`/`new_msg`/etc.) are all `public nomask`, and
  its `private nomask` helpers (`load_headers` etc.) are only ever
  reached via internal calls or a bare-identifier `set_alarm(...,
  load_headers)` closure (bound at compile time within the SAME
  defining file, immune to the string-based-dispatch demotion this
  bug class depends on) -- never `add_action`/`call_out` by name.
  `secure/armageddon.lpc`'s `private nomask` functions ARE inherited
  (into `d/Standard/obj/armageddon.lpc`) and driven via
  `set_alarm(..., shutdown_dodelay)`, the same safe bare-closure
  shape. `cmd/wiz/normal/{files,edit}.lpc` and
  `cmd/wiz/apprentice/communication.lpc`'s `private nomask` functions
  are never `add_action`/`call_out` targets at all (plain internal
  calls only), and none of those three files are ever inherited
  anywhere -- also moot in practice since they sit in the pre-existing,
  already-documented non-compiling wizard-tool cluster (section 7
  above). Clean.
- **§7.122** (autoload class-object duplication on reconnect): this
  engine's architecture differs fundamentally from the TMI-2 lineage
  this bug class was found on -- `save_object()` here does not
  independently serialize inventory sub-objects (confirmed by reading
  `std/object.lpc`/`std/container.lpc`), so there is no redundant
  double-capture for `load_auto_obj()` to duplicate against. Also,
  `load_auto_obj()` is only ever called from `enter_game()`, itself
  only reached when `start_player()` clones fresh from disk
  (`!environment(ob)`); the "already-live, just reconnecting"
  path (`start_player2()`'s `revive()`/`fixup_screen()` branches) never
  calls `enter_game()` again. No re-invocation path exists. Clean.
- **§7.123** (bare top-level `IDENT = (...)` statement): corpus-wide
  grep for the pattern found zero matches anywhere in the codebase.
  Clean.
- **§7.124** (percentage-scale threshold initialized as a 0.0-1.0
  fraction): `std/living/savevars.lpc`'s `is_whimpy`/`std/living/
  combat.lpc`'s consumer are plain `int` throughout with no float
  literal anywhere in the whimpy code path; default `0` (off until a
  player explicitly opts in via `set_whimpy()`) is correct, intentional
  design, not a bug. Clean.
- **§7.126** (stale pre-`.c` extension in a saved door/exit
  reference): this engine has no coordinate-grid AREA/door-data
  persistence mechanism at all (unlike the ES2/Neolith "Annihilator"
  lineage this bug class was found on) -- rooms are individual `.lpc`
  files with ordinary `add_exit()` calls, and a corpus-wide
  `load_object()` grep found no call sites fed from saved mapping/
  dbase data anywhere. Not applicable to this engine family.
- **§7.129** (`tell_room()` forwarding an omitted optional argument as
  a literal `int(0)` to the `message()` efun): this codebase's
  `tell_room()`/`tell_roombb()`/`say()` (`secure/simul_efun.lpc`) are
  all implemented via `catch_msg()` on a filtered `all_inventory()`
  list, never touching the raw `message()` efun at all -- structurally
  immune to this bug class. Also specifically checked (per this task's
  own brief, since `genesis`'s sibling `es1` had this bug):
  `include/compress_obj.h` (the `es1`-specific `__FILE__`-misuse
  pattern) does not exist anywhere in this codebase. Clean.
- **§7.130** (`query_idle()` called unconditionally on a path reached
  only after the object was already found non-interactive): this
  lineage's own `heart_beat()` (`std/living/heart_beat.lpc`) is a
  complete no-op (`HEART_NEEDED` is `#undef`'d) -- net-death handling
  runs entirely through the `net_dead()` apply/statue mechanism fixed
  in §8.2 above, never an inline `heart_beat()` check. No matching
  call-after-branch shape exists anywhere in the codebase. Clean.

### 8.7 Shop/economy/combat/guild -- still unreachable, unchanged from onboarding

Confirmed again this pass, not newly investigated: the pre-existing
"become an embodied player" gap (§5.2 above) still blocks every real
gameplay system gated behind embodiment. A fresh registration this
pass reached only the race-selection ghost-state rooms (`sala.lpc` and
its unnamed southern "gallery" neighbor -- both now showing full
descriptions thanks to the §8.3 fix above), where `stan`/`inwentarz`
both correctly respond `"To nie jest mozliwe w tym miejscu."` -- ghost-
state command restrictions, not a bug. Shop/economy, combat, and guild/
skill acquisition remain explicitly UNVERIFIED this pass (stated
honestly per this project's own testing standard), same root cause as
originally documented, not something this pass's driver-bugs-only
scope permits fixing.

### 8.8 Verification summary

- Real driver boot (`~/src/fluffos/build-debug/src/driver
  config.fluffos`): clean boot after every fix, zero new compile
  errors in any edited file, same 5 pre-existing known-cluster preload
  failures as onboarding (unrelated, unchanged).
- Full register -> 6-case declension Q&A -> email -> arrival cycle
  re-verified multiple times with distinct real Polish names
  (`tomasz`, `marek`, `roberta`), including the already-documented
  redundant second Q&A (§5.1, confirmed still present, unfixed,
  content gap not a bug).
- `zakoncz` (quit) -> `debug.log` grep -> reconnect verified clean and
  correct end-to-end on the `fluffos` admin account (see §8.4).
- A genuine abrupt disconnect (raw socket close, no `quit`) and
  same-driver-process reconnect verified `net_dead()` now fires (see
  §8.2); a driver restart-and-reconnect cycle (this satisfies AGENTS.md
  7.120) also re-verified the admin account's `Mud@2026x` password and
  keeper-rank recognition still work correctly.
- `do_decay()`/`decay_exp()` fix verified by letting the FINAL
  verification driver run for a full 47 minutes (well past the
  ~900-second/15-minute `reset_master()` alarm interval, giving it
  several ticks' worth of margin, not just one) before killing it by
  exact PID: zero `fob.lpc`/`do_decay`/`String index out of bounds`
  entries appeared in `debug.log` across that whole window (pre-fix,
  the very first such tick crashed reliably on a fresh boot).
- All throwaway test characters (`robert`, `roberta`, `marek`,
  `tomasz`) deleted before commit; only the seeded `fluffos` admin
  account and the pre-existing archived `root.o.backup` remain.
- No outbound network connections observed at any point this pass
  either (spot-checked via `ss` during active testing).

## 9. WASM packaging + boot verification (2026-09-01)

Per AGENTS.md §1, ran `scripts/wasm_client.js` against
`~/src/fluffos/build-wasm/src` (the project's shared, already-built WASM
driver) with the exact registration flow documented in §4/§7 above
(`nowa` -> name -> password x2 -> 6-case declension Q&A -> email ->
arrival), same as the native transcripts.

**One real, previously-latent bug found and fixed, affecting BOTH native
and WASM (not WASM-specific):** `players/` only shipped the two letter
buckets that happen to contain real save files (`f/` for the seeded
`fluffos` admin, `r/` for the archive's own archived `root.o.backup`).
Section 3's "created the remaining 25 letter directories" note from the
original onboarding pass never actually persisted, because git does not
track empty directories -- once that session's shell-created `mkdir`s
were left with nothing to commit, the fix silently reverted itself on
the next fresh checkout. Symptom: any new character whose name starts
with a letter other than `f`/`r` fails to save
(`*Could not open /players/<letter>/<name>.o.tmp for a save`,
`std/player_sec.lpc:625`), which cascades into `ghost_start()` never
placing the character in a room (`environment()` returns 0), which in
turn crashes the very first `spojrz`/look with `*Bad argument 1 to EFUN
call_other()` in `do_glance()`. This is a real, general registration
blocker, not a content gap or a WASM-sandbox artifact -- confirmed the
same missing directories are absent from the native `work/` tree too.
Fixed properly this time: created all 24 missing single-letter
directories (`a`-`z` minus `f`/`r`) each with an empty `.gitkeep` file
(the convention already used elsewhere in this project, e.g.
`libs/openlib/work/u/p/.gitkeep`) so they survive as real git blobs and
get copied into both a fresh native checkout and the WASM MEMFS copy
`pack_lib_for_web.sh`/`wasm_client.js` build for every future run.

After that fix, a full WASM registration (`testarkb`, matching the
declension pattern used elsewhere in this file) completed cleanly and
reached the exact same place the native transcripts in §7/§8 describe:
the redundant second declension Q&A fires once (§5.1, confirmed still
present under WASM too, same self-resolving non-bug), then the
character lands in the `sala.lpc` race-choosing hall with its full room
description, where `stan` correctly answers `"To nie jest mozliwe w tym
miejscu."` -- identical to the native ghost-state restriction documented
in §8.7, not a WASM regression. `zakoncz` (quit) printed `"Nagrywam
postac."` and the connection closed cleanly, same as native.

**Conclusion: WASM boots and plays identically to the already-verified
native driver**, including reproducing the same documented,
deliberately-unfixed content gap (no reachable path out of ghost
status, so combat/shop/guild remain unverified/unreachable under WASM
for the same reason they are under native -- see §5.2/§8.7). No
WASM-specific blocker of any kind was found; the one real bug (missing
`players/` letter directories) was a general infrastructure gap that
happened to surface first here because this was the first full,
from-a-fresh-checkout registration test with a name outside `f`/`r`.
Checked precedent before picking `wasm_status`: of the ~234 libs already
classified, 233 are `"playable"` and exactly one (`zjdyzj`) is
`"limited"` -- and that one lone `"limited"` case is `"limited"` for a
purely technical reason unrelated to content depth: its `logind.lpc`
gates every connection behind a custom crypt-challenge mobile-client
handshake that this project's generic telnet-style web terminal cannot
compute automatically, so an ordinary site visitor can't even get past
the FIRST prompt without an external tool. By contrast, several other
libs with severe, code-confirmed content gaps at least as deep as
arkadia's -- `nitan6` (combat never applies real damage at all),
`kxkj` (a shared-file bug permanently corrupts room exits over uptime),
`zsdsj`, `bmxkx2001`, and many more across this collection's NOTES.md
-- are all still classified `"playable"`, because the standard
login/registration/explore loop works end to end through the ordinary
web terminal; the gap is something a player runs into DURING play, not
something that blocks the standard site experience from ever starting.
Arkadia's case fits that same pattern, not `zjdyzj`'s: the generic web
terminal completes the ENTIRE documented registration flow with no
special tooling, reaches a live, responsive `> ` prompt, and correctly
executes ghost-level commands (`spojrz`, the room description, the
ghost-state-restriction response from `stan`) -- exactly the "playable"
bar this collection has consistently applied elsewhere. The embodiment
gap is therefore recorded as a documented content limitation (per §5.2/
§8.7 above and in the README/meta.json description) rather than
expressed via a `"limited"` status, matching how this project has
classified every other lib with a comparably severe in-play content gap.
`wasm_status` set to `"playable"`.

Test characters (`testarka`, `testarkb`) never touched the real
on-disk `players/` tree at all -- `wasm_client.js` copies the lib into
an in-process MEMFS filesystem per run and all writes (including
character saves) land only there, discarded when the Node process
exits. Only the newly-added `.gitkeep` placeholders and the pre-existing
`fluffos`/`root.o.backup` files are present in `players/` after this
pass.
