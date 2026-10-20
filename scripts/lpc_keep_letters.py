#!/usr/bin/env python3
"""scripts/lpc_keep_letters.py [--apply] SLUG BUCKET [BUCKET...]

Complete a per-letter directory bucket (`save/players/a` ... `save/players/z`) in scripts/wasm_keep_dirs.txt.

A lib that saves a character under `<bucket>/<first letter of the name>/<name>.o` needs the letter directory to exist: `save_object()` creates none, it
fails with `Could not open /save/players/s/sweepzq.o.gz.tmp for a save` and the character is never written.  The xkx / Eastern Story family has an
`assure_file()` sefun that makes the directories on demand, the Dead Souls / Nightmare / Foundation masters make the player directory themselves;
the Discworld mudlib (`discworld`, `dw_fluffos_v1`, `dw_fluffos_v2`) does neither.  Its buckets (`banish`, `save/mail`, `save/newsrc`, `save/players`)
exist in the archive only for the letters somebody had played with: a CI checkout, the site zip and a pristine tree get exactly those, so a visitor whose
name starts with `c`, `d`, `g`, `p`, `s` or `t` (v1), `b` or `s` (v2), anything but `f` (v3) never keeps a character.  gen_keep_dirs.py records the directories
the local tree happens to have, so it cannot know the missing ones: this adds the missing letters of the named buckets (lines are merged into the lib's
block in place, nothing else in the file changes).  Check a lib first with the survey (`scripts/play_survey.py --relogin SLUG`: a row `in` with `saved` 0 and
`Could not open ... for a save` in the unit's log/catch) -- a lib that makes its directories on demand needs nothing.

Without --apply the plan is printed: `ADD<TAB>slug<TAB>dir`."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import gen_keep_dirs as gk  # noqa: E402

LETTERS = "abcdefghijklmnopqrstuvwxyz"


def main():
    a = sys.argv[1:]
    apply_ = "--apply" in a
    pos = [x for x in a if not x.startswith("--")]
    if len(pos) < 2:
        sys.exit(__doc__)
    slug, buckets = pos[0], [b.strip("/") for b in pos[1:]]
    if not gk.scannable(slug):
        sys.exit(f"{slug}: no libs/{slug}/work or config.fluffos")
    lines = gk.read_lines()
    have = {ln[len(slug) + 1:] for ln in lines if ln.startswith(slug + "\t")} | gk.tracked_dirs(slug)
    add = []
    for b in buckets:
        for d in [b] + [f"{b}/{c}" for c in LETTERS]:
            if d not in have:
                add.append(d)
    for d in add:
        print(f"ADD\t{slug}\t{d}")
    if apply_ and add:
        lines = gk.set_block(lines, slug, add, merge=True)
        gk.OUT.write_text("\n".join(lines) + "\n", encoding="utf-8", errors="surrogateescape")
    print(f"{len(add)} dir(s) {'added' if apply_ else 'planned'}", file=sys.stderr)


if __name__ == "__main__":
    main()
