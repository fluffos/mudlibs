# LPUniversity Mudlib (lpuni)

An English-language classic LPC teaching/reference mudlib. Per its own lpmuds.net description, LPUniversity was never meant to be a finished game -- "not ready for play... provides a chance to build a lib from the ground up without having to deal much with the driver." What actually shipped is more complete than that framing suggests: a full login/registration/ security/command-dispatch/help/mail/message-board/news/channel/Intermud-3 engine (including a real first-boot admin-setup wizard), plus one small real starting area -- "LPUniversity Cafe" -- with a greeter NPC and real room descriptions. There is no combat/stats/limbs system at all.

Source: a maintained, already-FluffOS-adapted archive
(`lpuni_fluffos_v1.zip`) from lpmuds.net, a now-defunct LPMud archive
site. Recovered via the Wayback Machine
(<https://web.archive.org/web/20160306051537if_/http://lpmuds.net/files/lpuni_fluffos_v1.zip>)
since the original site is down. Slug `lpuni`, number 177, port 40224.

## Highlights

- A genuine, working first-boot admin-setup wizard: the first account ever
  registered on a fresh install is automatically granted admin rights
  (`adm/etc/new_install`-gated). See `NOTES.md` for how this project's own
  admin account was created through this exact flow.
- One small shipped starting domain (`areas/lpuni/`): an entrance/cafe with
  a greeter NPC, three upstairs floors, a bar, lounge, and bathroom.
- The highest-impact bugs found while porting this to FluffOS: this
  driver's `PACKAGE_UIDS` support requires `get_root_uid()`/
  `get_bb_uid()`/`creator_file()` master applies that this archive never
  defined (without the first two the driver can't even boot); and a
  `.c`-to-`.lpc` rename side effect left several wizard/object commands
  (`update`, `clone`, `dest`, `clean`, `goto`) comparing a 2-character
  filename slice against the 4-character string `".lpc"` -- always false
  or always true depending on the comparison direction, so `update
  <file>` always failed with a double `.lpc.lpc` suffix, and `ls`/`more`
  never colorized or syntax-highlighted `.lpc` source. Full details,
  including two runtime hygiene fixes found via live play-testing, in
  `NOTES.md`.
- **LPUniversity makes a real outbound network connection at boot**,
  confirmed live: `adm/daemons/chan_d`'s Intermud-3 module connects to a
  real public I3 chat router (`*yatmim`) within a couple of seconds of
  every boot. Genuine upstream functionality, not a bug -- but this lib
  should not be swept into high-frequency automated re-boot loops the way
  this project's other (fully sandboxed) libs safely can be. See
  `NOTES.md` \S6.

## Registration flow

`select a name` -> (new account?) `y` -> password -> confirm password ->
public e-mail address -> `[Hit enter to continue]` twice -> lands in a
personal workroom (wizard/admin accounts) or the LPUniversity Cafe
entrance (ordinary accounts).

## Admin account

- **id**: `fluffos`
- **password**: `testpass123`
- **privilege**: admin (granted automatically by the archive's own
  first-boot install wizard)

Verified live: `update <path>` (this project's canonical ACL/compile-
permission check) against a real `adm/obj/master.lpc` file succeeds.

## Status

Boots clean: zero compile errors across repeated fresh-driver boots.
Verified live with a real driver session and a raw socket client: the
first-boot admin install, `look`/`inventory`/`who`/`ls`/`more`/the wizard
`update` command, movement into the real shipped starting domain (with a
scripted greeter NPC), and a clean `quit`. This engine has no combat/
stats system, so there is no `score` command to verify (confirmed: no
file or string literal named `score` exists anywhere in the archive) --
same precedent as `libs/foundation2/`.

138 of 151 `.lpc` files pass a full `lpcc_check.sh` batch compile sweep;
the 13 that don't are all either include-only fragments never meant to
compile standalone (the Intermud-3 `i3services/*.lpc` handlers, textually
`#include`d into `chdmod_i3.lpc`; `adm/simul_efun/overrides.lpc`, textually
`#include`d into the real `simul_efun` object -- both compile and load
fine as part of their real parent file) or an object whose `create()`
legitimately needs a live player context (`std_newsclient.lpc`) -- see
`NOTES.md` for the full triage.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/lpuni
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40224**.

**Note**: booting this lib makes a real outbound network connection (see
Highlights above) -- avoid scripting repeated/automated boots.
