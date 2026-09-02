# Lil (lil)

A "fixed up version of the MudOS testsuite lib with MudOS docs added," per its original lpmuds.net listing -- genuinely a from-scratch bootstrapping base, not a game. Its own shipped `README` puts it bluntly: "about as bare bones as it gets without coding 100% from scratch... For the seriously leet only!" There is no login/password system, no rooms, no combat, no accounts -- connecting drops you straight into an anonymous session with a small handful of primitive commands, plus a sizeable bundled compiler/efun/operator self-test suite meant for driver developers, not players.

Source: a maintained, already-FluffOS-adapted archive (`lil_0.3.zip`)
from lpmuds.net, a now-defunct LPMud archive site. Recovered via the
Wayback Machine
(<https://web.archive.org/web/20160306101015id_/http://lpmuds.net/files/lil_0.3.zip>)
since the original site is down. Slug `lil`, number 179, port 40226.

## Highlights

- No accounts, no rooms, no combat, no Intermud -- exactly as documented
  upstream, confirmed live (see `NOTES.md` \S7 for the no-outbound-network
  check). Connecting auto-assigns a name (`stufN`) and every session is
  already a wizard by construction.
- Ten commands total: `dest`, `update`, `ed`, `eval`, `rm`, `say`, `who`,
  `quit`, `shutdown`, plus a `test` master-object flag for running the
  bundled self-test suite. An `efun <name>` command is referenced by both
  the boot banner and the mudlib's own `README` but was never actually
  shipped in the archive -- documented in `NOTES.md` \S4, not invented
  here; individual self-tests remain runnable via `eval`.
- Only one real FluffOS-compat fix was needed: the "global include file"
  (`config.h`) shipped as an empty customization stub, but nearly the
  entire bundled self-test suite relies on it to supply `ASSERT()`/
  `SAVETP`/`RESTORETP` -- without it, 150 of 199 files failed to compile.
  Full details in `NOTES.md` \S2.
- One genuine driver/dialect gap, left as-is by design: this driver's
  preprocessor doesn't implement C-style `##` token pasting, which one
  compiler self-test (`single/tests/compiler/succeed.lpc`) specifically
  exercises. See `NOTES.md` \S3.

## Status

Boots clean: zero fatal errors, empty `log/debug.log`, across repeated
fresh-driver boots. Verified live with a real driver session and a raw
socket client: connecting, `who`, `say`, `eval` (both arithmetic and
calling into the bundled self-tests), `rm`, `update`, `ed` (enter and
exit), `dest`, and `quit` all produce correct output. The bundled
self-test suite itself was also run live via `eval "/command/tests"->
main("");` and walks the entire test tree correctly, including every
deliberately-broken `compiler/fail/*` fixture correctly failing to load
as designed.

157 of 199 `.lpc` files pass a full `lpcc_check.sh` batch compile sweep;
every one of the 42 that don't is either a fixture deliberately designed
to fail compilation (41 files under `single/tests/compiler/fail/`) or the
one driver-dialect gap noted above -- expected for this kind of reference/
testsuite lib, not a sign of missing conversion work.

WASM status: not yet attempted (`wasm_status` left `""`).

## Local run

```
cd libs/lil
~/src/fluffos/build-debug/src/driver config.fluffos
```

Game port: **40226**.

No account system exists, so there is nothing to register -- just connect
and you're in, already with wizard access.
