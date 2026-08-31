# Basis (basis)

**Basis** is a small, historically significant English-language LPMud
mudlib written by John Garnett ("Truilkan") -- the same author as the
already-onboarded `tmi2` (TMI-2), but an earlier, deliberately smaller
1993 project. Per its own `README`: "Basis was conceived as an
experiment... It has some good features in it but is far from a
finished polished mudlib... Basis is for experimenters who actually
want to start with something smaller and less complete than TMI-2."
Basis's `std/` base classes, groups/access permission model, and `bin`
command-dispatch system were later inherited by TMI-2 itself (per
Basis's own README: "TMI-2 uses Basis's emoted system... uses the
groups/access model originated by Portals as does TMI-2... Both TMI-2
and Basis use some variant of the 'bin' command system").

This is a "core infrastructure" mudlib, not a game with content: a
tiny two-room test area (`/room/start`, `/room/void`, connected by
`go east`/`go west`), a working registration/login flow, and a real
`bin/`-command dispatch tree (movement, communication, inventory,
wizard tooling) -- but no quests, no combat, no `score` command
(never shipped one). "Definition of done" here means every command
the archive actually implements works, not a rich game world.

## Provenance

Recovered from the live `ftp.lysator.liu.se` LPMud archive mirror
(`pub/lpmud/mudlibs/MudOS/basis-20.tar.gz`, unchanged since 2010 per
its HTTP `Last-Modified` header, itself an untouched copy of the
original 1993 upload) -- the file happened to still be reachable
directly over HTTPS, so no Wayback Machine recovery was needed. 233
files, real `adm/obj/master.lpc` tree.

## Highlights (see `NOTES.md` for full detail)

- **A bug in this project's own `convert_lib.sh` broke every single
  command in the game.** `adm/daemon/commandd.lpc`'s command-cache
  builder matched files by a fixed-width slice on the OLD 2-character
  `.c` extension (`files[k][(len-2)..(len-1)] == ".c"`); the
  `.c`->`.lpc` literal-reference fixup updated the quoted string to
  `".lpc"` but not the slice width, so the comparison (2 chars vs. a
  4-char string) was always false. The command cache stayed
  permanently empty and every typed command produced only the generic
  "Errmm?" fail message. Confirmed as a real gap in the conversion
  tooling itself (AGENTS.md §4.2 item 4's known failure shape), not
  specific to this archive -- worth re-checking on any lib with a
  similar hand-rolled extension-matching cache.
- **A genuine, non-obvious closure/function-pointer semantics gap**:
  old MudOS's `(: object_or_path, "funcname" :)` bound call_other
  pointer works for ANY expression in the head slot; this driver's
  grammar only builds that special form when "(:" is immediately
  followed by a bare, compile-time-resolved NAME before the first
  comma. Anything else (a string constant, or even a called
  `this_object()`) silently falls through to a generic
  "expression functional" that just evaluates the whole thing as an
  ordinary comma-expression and returns the LAST operand verbatim --
  no error, no crash at construction time, just a badly wrong value
  used later. `std/object/base.lpc`'s `(: SIMUL_EFUN_OB,
  "query_efuns" :)` idiom (used to redirect `query(a_super)`,
  `query(a_contains)`, etc. through a simul_efun) hit this on every
  `look`, cascading into the virtual-object daemon's own
  self-referential `compile_object()` fallback and crashing with
  "Inherit chain too deep". Fixed by using `call_other` itself as the
  bare NAME with the real target and method as bound arguments. See
  the new AGENTS.md §6.2 entry this session added.
- Two missing-file `inherit`/reference bugs, both genuine archive
  content gaps rather than conversion damage: 19 files' `inherit
  "/bin/bin_m"` pointed at a file that was moved to
  `/adm/std/security/bin.lpc` at some point in the mudlib's own
  history without updating every reference (fixed -- the content
  exists, just at the wrong path); a handful of `/bin/bin_m`,
  `/bin/bin_u`-style wizard-tooling and test files (`std/i/tsh.lpc`,
  `std/i/history.lpc`, `bin/maker/test/ws.lpc`,
  `bin/maker/objects/clean.lpc`) reference genuinely never-shipped
  files or use genuinely-undeclared variables and were left broken,
  matching this archive's own acknowledged unfinished state -- none
  are reachable from the live game (unreferenced dead code).
- Reimplemented five classic MudOS efuns this driver never had:
  `extract()`, `log_file()`, `privp()`, `cat()`, `tail()` -- all as
  simul_efuns, all behavior-preserving per the old MudOS manual
  semantics (see AGENTS.md §6.2's new entries).
- A `valid_write()`/`valid_read()` save-file check compared the
  driver's fully-suffixed save filename against the mudlib's own
  bare-path helper with a strict `==`, denying every player's very
  first `save_data()` call during registration -- meaning a brand
  new character never actually finished character creation at all
  (silently stuck on the login object). Exactly AGENTS.md §7.49's
  documented bug class; fixed with the standard `file == bare ||
  file == bare + ".o"` widening.

## Registration flow

`name` -> confirm (`y`/`n`) -> (first-time only) `news`/credits text ->
password -> confirm password -> straight into `/room/start`. No
gender/race prompts (this thin mudlib never implemented character
attributes beyond a name).

## Admin account

Basis's file-permission system is a `/adm/etc/groups` +
`/adm/etc/access` named-group scheme (same lineage as TMI-2's), fully
independent from the ordinary "which player-body class did you get"
question (`std/user.lpc` / `std/maker.lpc` / `std/admin.lpc`,
resolved once at first login from a per-account "pith file" at
`/data/users/<letter>/<name>.o`, itself unrelated to the player's own
save file). To seed `fluffos` as an admin:

1. Registered `fluffos` (password `Mud@2026`) through the normal flow
   -- this always creates a plain `user`-class body on first login.
2. Added `fluffos` to the `(admin)` group in `adm/etc/groups`
   (alongside the original author accounts, not replacing them) --
   grants file read/write ACL.
3. Edited the account's pith file (`data/users/f/fluffos.o`) to
   change its stored body-class attribute from `"user"` to `"admin"`,
   matching exactly how the archive's own pre-shipped `truilkan`
   account (John Garnett's own, still present with its original
   1992-era crypt password we can't recover) is set up.
4. On the next login, the account gets destructed and rebuilt fresh
   as an `/obj/i/admin` body (since no admin-class save exists yet);
   seeded its resulting save file's `a_permissions` (2999,
   `ADMIN(999)`) and `a_position` (`"Admin"`) attributes, again
   matching `truilkan`'s own pre-shipped values exactly.
5. Verified: `update /bin/user/senses/look` succeeds (write ACL
   confirmed), and permission-gated player commands like `emote`
   (which ordinary new players cannot use at all -- see `NOTES.md`)
   also work.

## Local play

```
cd libs/basis
~/src/fluffos/build-debug/src/driver config.fluffos
```

Port **40261**.
