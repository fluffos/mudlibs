# Contributing to fluffos/mudlibs

This repository preserves and restores classic LPC mudlibs — old MUD codebases
recovered from archives, converted, fixed, and made playable again on the
modern [FluffOS](https://github.com/fluffos/fluffos) driver, both natively
and in the browser via WebAssembly. Contributions of new libraries, bug
fixes, and improvements to the restoration tooling are all welcome.

## Ways to contribute

### 1. Suggest a mudlib we don't have yet

If you know of a historical LPC/MudOS/FluffOS mudlib (or even an LDMud/DGD
one — those are tracked for a future porting effort) that isn't in this
collection, [open an issue](https://github.com/fluffos/mudlibs/issues/new)
with:

- A link to the source (a GitHub repo, an archive download, or wherever
  you found it)
- Whatever you know about its history/lineage
- Whether it's still live/operating (source for still-operating games is
  usually private — abandoned/archived projects are the most recoverable)

You don't need to do the conversion work yourself — a good lead is a
contribution on its own.

### 2. Submit a new mudlib

If you want to do the conversion yourself, read **[`AGENTS.md`](AGENTS.md)**
first — it's the full technical playbook this project follows for every
library, covering:

- Recognizing a codebase's lineage and picking a port
- Archive extraction and encoding conversion (GB18030/BIG5 → UTF-8, the
  `.c` → `.lpc` rename)
- The compile-sweep and on-sight checklist (§2.2)
- The verification bar: boot the driver, register with a real name, reach
  an actual room, and confirm `look`/`score`/`quit` work — then a deeper
  full-playthrough pass (§10.7) that exercises every major system (skills,
  combat, shops, death/respawn, reconnect) and checks `debug.log` after
  every state change, not just that the driver starts
- `README.md`/`NOTES.md`/`meta.json` conventions for the finished lib

A PR for a new lib should include all of these files under `libs/<slug>/`,
plus a `README.md`/`NOTES.md` table row where applicable. If you found and
fixed a genuine driver-compatibility bug that's likely to recur in sibling
codebases, consider adding a numbered `AGENTS.md` entry documenting it —
that catalog is the project's main defense against re-discovering the same
bug independently in every related lib.

**Scope note**: fix real programming bugs (crashes, driver-API misuse,
missing guards, clear typos) as part of getting a lib running. Don't
change game balance, content, or design choices, even ones that look
surprising — if you're not sure which bucket something falls in, describe
it honestly in the lib's `NOTES.md` rather than "fixing" it.

### 3. Fix a bug in an existing lib

Bugs turn up during play or deep-testing that don't get caught by a
compile sweep alone. If you find one, a PR with the fix plus a short
`NOTES.md` writeup (what broke, why, how you confirmed the fix) is ideal.
If the underlying bug class looks like it could recur elsewhere in the
corpus, flag that in your PR description.

### 4. Improve the tooling

The conversion/testing scripts live in `scripts/`, and the WASM packaging
site-generation lives in `.github/workflows/` and `scripts/gen_site_index.py`
et al. Improvements here (faster conversion, better encoding detection,
more robust WASM boot checks) benefit every lib in the collection.

## A note on licensing

Most of these codebases are 1990s-2000s community projects with no clear
license attached to the original archive — that's the nature of recovering
abandoned hobbyist software. We preserve the original source as-is (with
attribution to the original archive/repo in each lib's `meta.json`) and
don't add license headers we can't substantiate. If you're contributing a
lib whose original author has stated licensing terms (even informally,
e.g. in a README or forum post), please include that context in your PR.

If a lib's original author (or a clear rights-holder) ever asks for their
work to be removed from this collection, we'll honor that request —
[open an issue](https://github.com/fluffos/mudlibs/issues/new) or contact
the maintainers directly.

## Questions

Open an issue, or start a discussion if you're not sure whether something
is a good fit. `AGENTS.md` also documents a long list of previously-found
bug classes and driver quirks (`§6`–`§10`) that's worth searching before
you dig too deep into a confusing failure — there's a good chance a
sibling codebase already hit the same thing.
