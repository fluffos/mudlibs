# mudlib — Chinese LPMud/FluffOS mudlib archive collection

This directory holds ~100 archived LPC mudlib codebases (mostly Chinese wuxia/
xianxia MUDs from the late-1990s/2000s MudOS/FluffOS scene — 侠客行, 笑傲江湖,
金庸群侠传, 西游记, 风云, 大唐双龙, and many derivatives/forks of those).

The goal: unpack every archive, get its mudlib booting cleanly on the FluffOS
driver built at `~/src/fluffos` (a modern, actively-developed fork — these
libs were written against MudOS/FluffOS from ~2000-2010), with sources
transcoded to UTF-8 and normalized to the `.lpc` extension, and fix whatever
driver-compatibility issues come up along the way.

See `AGENTS.md` for the working process, tooling notes, and the running
catalog of compatibility issues and fixes discovered so far. See `TODO.md`
for per-archive status.

## Layout

```
archives/           original archive files, as downloaded (untouched)
libs/<slug>/raw/    pristine extraction of the archive, original encoding/extensions
libs/<slug>/work/   working copy: UTF-8, .lpc extensions, driver-compat fixes applied
                    (this is what "mudlib directory" points at)
libs/<slug>/config.fluffos   adapted FluffOS runtime config for this lib
libs/<slug>/NOTES.md         per-lib findings: layout quirks, fixes applied, open issues
scripts/            reusable extraction/conversion/boot-test tooling
TODO.md             master status table, one row per lib
```

`<slug>` is the archive's original name, sanitized (trimmed, de-duplicated
whitespace, no `()`/`.rar`/`.zip` suffix) — see `TODO.md` for the exact
archive → slug mapping.

## Running a lib

```
~/src/fluffos/build/src/driver libs/<slug>/config.fluffos
```

Default port is assigned per-lib in its `config.fluffos` (see NOTES.md for
the exact port) to avoid collisions if several are run at once.

## Duplicates

10 archives are byte-identical to another archive under a different filename
(browser-download "(1)" copies etc.) — only one copy of each is processed.
The mapping is recorded in `TODO.md`.
