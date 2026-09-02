# Foundation II (foundation2)

A stripped-down, classic descendant of the Nightmare mudlib lineage, originally released by George Reese ("Descartes of Borg") in the mid- 1990s. Per the mud's own boot banner: "This mud is NOT for newcomers to LPC. You must be hardcore." Foundation II ships no combat, limbs, or stats system at all -- it's a minimal, complete engine (login/ registration, security, command dispatch, help, mail, message boards, Intermud-3) meant as a clean base for LPC programmers to build their own game world on top of, not a playable-out-of-the-box game.

Source: a maintained, already-FluffOS-adapted archive
(`foundation2_fluffos_v1.zip`) from lpmuds.net, a now-defunct LPMud
archive site. Recovered via the Wayback Machine
(<https://web.archive.org/web/20160306101019if_/http://lpmuds.net/files/foundation/foundation2_fluffos_v1.zip>)
since the original site is down. Slug `foundation2`, number 174, port
40221.

## Highlights

- A genuine, working first-boot admin-setup wizard: connecting to a fresh
  install walks through a short "installation process" (superuser name,
  password, capitalized display form, gender, real name, email) before
  the mud's real login/registration flow ever activates. See `NOTES.md`
  for how this project's admin account was created through this exact
  flow.
- One small shipped starting area (`domains/Standard`, a softly-lit
  cavern with glowing lichen and magic pools) plus two optional teaching/
  example content trees (`domains/Examples`, `domains/School`) that, per
  `NOTES.md`, were evidently carried over from a different, incompatible
  version of this engine's room/item API and don't compile as shipped --
  documented as a pre-existing content mismatch in the archive, not
  something this port introduced or fixed.
- The highest-impact bugs found while porting this to FluffOS: a missing
  `creator_file()` master apply broke loading nearly every single object
  in the mudlib (this driver's `PACKAGE_UIDS` support calls it on every
  object creation), and a `.c`-to-`.lpc` rename side effect in the
  command-dispatch table's filename parsing silently broke every ordinary
  player/wizard command (`inventory`, `help`, `update`, ...) while
  soul/emote commands kept working through a separate path -- both fixed,
  full details in `NOTES.md`.
- Foundation II makes a real outbound network connection attempt to the
  historic Intermud-3 router a couple of seconds after every boot
  (`daemon/intermud.c`, preloaded by default) -- genuine upstream
  functionality, not a bug, but flagged in `NOTES.md` since it's unusual
  for this project's normally fully-sandboxed corpus.

## Registration flow

`new name` -> "Do you really wish `<name>` to be your name? (y/n)" ->
password (5+ letters) -> confirm password -> gender (`male`/`female`) ->
display name (blank = default) -> email (**required**, must look like
`user@host`) -> real name (optional, blank OK) -> two news screens
(<return> to continue) -> lands in the Standard domain's starting cavern.

Every account (mortal or wizard) saves under the same `secure/save/
creators/` tree -- this engine has no separate mortal/wizard save-file
split by default.

## Admin account

- **id**: `fluffos`
- **password**: `Mud@2026`
- **privilege**: `ASSIST` + `SECURE` group membership
  (`secure/cfg/groups.cfg`)

Created through the mud's own first-boot installation wizard (see
`NOTES.md`), not a save-file hand-edit. Verified live: `update <path>`
(this project's canonical ACL/compile-permission check) against a real
`cmds/player` file succeeds.

## Status

Boots clean: zero compile errors across repeated fresh-driver boots.
Verified live with a real driver session and a raw socket client: the
first-boot admin installation wizard, a brand-new ordinary character's
full registration, and `look`/`inventory`/`who`/`save`/a soul command
(`smile`)/the wizard `update` command all producing correct output, and a
clean `quit`. This engine has no combat/stats system, so there is no
`score` command to verify (see `NOTES.md` for what substitutes for it in
this port's verification pass).

223 of 246 `.lpc` files pass a full `lpcc_check.sh` batch compile sweep;
the 23 that don't are all non-preloaded, non-boot-critical example/
teaching content with a pre-existing content/API mismatch predating this
port (see `NOTES.md` \S3) -- expected for a deliberately minimal engine
like this one, not a sign of missing conversion work.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/foundation2
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40221**.
