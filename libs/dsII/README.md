# Dead Souls II (dsII)

The real, self-identified "Dead Souls Mud Library II" -- public domain, released November 2006 by Cratylus. A genuinely distinct middle generation of the Dead Souls object library, sitting between the Nightmare-IV-era snapshot this collection already hosts as `dsI` (1996-98, 2 domains) and the later 3.8.6-era copies `ds386`/ `deadsouls_fluffos` (8 domains, much larger feature set). Confirmed distinct by a structural and byte-level diff -- see `NOTES.md` \S1.

Source: a ZIP archive from mudbytes.net, a now-dead site. Recovered via
the Wayback Machine
(<https://web.archive.org/web/20190802021627id_/http://mudbytes.net/files/download/843/>)
since the original site is down. Slug `dsII`, number 181, port 40228.

## Highlights

- A genuine, working first-boot admin-setup wizard
  (`secure/lib/connect.lpc`/`connect.real`): connecting to a fresh
  install walks through name/password/gender/display-name/
  email/real-name, then a **race selection** step (`list`/`help
  RACE`/`pick RACE` -- 7 races on offer: halfling, elf, orc, half-orc,
  human, half-elf, dwarf) before the mud's real, ongoing
  login/registration flow self-installs in its place. Unlike `dsI`,
  this codebase's installer **shuts the mud down** after the admin
  account is created -- a restart is required before logging in as the
  new admin.
- Four shipped domains: `default` (a small starting area), `town`,
  `Ylsrim` (an example town with a pub, armoury, weaponry, a
  jar-and-lightning-bug minigame object, and a couple of "broken"
  disease-item examples), and `campus` (an LPC University-themed area
  with a live greeter NPC bot) -- a larger content footprint than
  `dsI`'s 2 domains, smaller than `ds386`/`deadsouls_fluffos`'s 8.
- **Makes a real outbound network connection at boot**: `daemon/
  intermud.lpc` is preloaded by default and connects to a real
  Intermud-3 nameserver (`149.152.218.102:23`) a couple of seconds
  after boot -- confirmed live. Same safety-flagging convention as
  `dsI`/`imud`/`foundation2`: do **not** sweep this lib into
  high-frequency automated re-boot/deep-test loops.
- The single highest-impact bug found while porting this to FluffOS: a
  genuine original-archive logic bug in `lib/comp/seal.lpc` passed an
  object where `eventPick()`'s string lock-id argument was expected --
  since this "seal" composite (closeable+lockable) is inherited
  transitively by nearly every container/door/chest in the mudlib, this
  one bug alone broke 195 of 232 total compile failures found in the
  first sweep. Full list of fixes in `NOTES.md`.

## Registration flow

`name` -> "Do you really wish to be known as `<Name>`? (y/n)" ->
password (5+ letters) -> confirm password -> gender (`male`/`female`)
-> display name (blank = default) -> email (**required**, must look
like `user@host`) -> real name (optional, blank OK) -> race selection
(`list` to see options, `pick <race>` to choose) -> news screens
(<return> to continue) -> lands in `/domains/campus/room/reception`
(the LPC University reception area).

The very first account ever created goes through a separate, one-time
admin-installation wizard instead (see above) -- **the mud shuts down
after that wizard completes**, and every account after the restart
uses the normal flow described here.

## Admin account

- **id**: `fluffos`
- **password**: `fluffwiz123`
- **privilege**: `SECURE`/`ASSIST`/`ELDER`/`TEST`/`INTERMUD` group
  membership (`secure/cfg/groups.cfg`), account file under
  `secure/save/creators/`

Created through the mud's own first-boot installation wizard. One
recovery needed: the shipped archive's `secure/cfg/groups.cfg` and
`secure/include/config.h` already had the original author's name
("cratylus") hardcoded instead of the `ADMIN`/`DEBUG_NAME` placeholder
tokens the installer's own code searches for and replaces -- a
pre-existing archive bug (present on any driver, not FluffOS-specific)
that would have silently left the new admin with no real group
membership at all. Fixed by hand-editing both files to say `fluffos`
instead of `cratylus`; see `NOTES.md` \S5 for the full analysis.

Verified live: `who` lists `Arch: First Admin Fluffos`, login shows
general/creator/admin news sections, and `update` (this project's
canonical ACL/compile-permission smoke test) succeeds.

## Status

Boots clean, zero fatal errors. Verified live with a real driver
session and a raw socket client: the first-boot admin installation
wizard (including the mud's self-shutdown-after-install), a restart,
admin login, a brand-new ordinary character's full registration
(including race selection), and `look`/`score`/`who`/`update`/a clean
`quit` all producing correct output for both accounts.

1401 of 1407 `.lpc` files pass a full `lpcc_check.sh` batch compile
sweep (99.6%); the 6 that don't are all non-preloaded, pre-existing
archive content gaps (a deliberately-removed stargate system per the
archive's own release notes, a never-shipped `podium` object, a
missing library component, a foreign-codebase remote-admin daemon, and
two wizard debug scratch files) -- see `NOTES.md` \S7 for the full
breakdown.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/dsII
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40228**. Note the Intermud-3 outbound-connection caveat
above before repeated/automated boots.
