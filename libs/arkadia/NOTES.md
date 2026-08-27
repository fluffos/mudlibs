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
