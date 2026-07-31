"""Aggregate every lib's own libs/<slug>/meta.json (plus the handful of
non-mudlib/not-convertible entries that have no libs/ dir at all, under
scripts/non_mudlib_meta/<slug>.json) into scripts/lib_numbering.json --
a flat, generated index for quick number/slug/port lookups.

This is the "assembler" half of a per-lib-file design: each lib owns its
own metadata file (colocated with its NOTES.md/README.md/config.fluffos,
easy to edit alongside them, no risk of merge conflicts with 200+ libs
sharing one giant array); this script is what reconstitutes the single
flat view other tooling (README table generation, site index, etc.)
still wants to read.

Usage: python3 scripts/assemble_numbering.py
Run this after adding/editing any libs/<slug>/meta.json or
scripts/non_mudlib_meta/<slug>.json, before regenerating the README
table or the WASM site index.
"""
import json, os

MUDLIB_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LIBS_DIR = os.path.join(MUDLIB_ROOT, "libs")
NON_MUDLIB_DIR = os.path.join(MUDLIB_ROOT, "scripts", "non_mudlib_meta")
OUT = os.path.join(MUDLIB_ROOT, "scripts", "lib_numbering.json")

SCHEME = ("NNN = one unique game/codebase; NNN-M = confirmed derivative/variant "
          "of the same codebase (lineage confirmed via scripts/lib_similarity_cluster.py "
          "and/or manual master.c/chinese.c/etc diffing per AGENTS.md §2.1). "
          "9xx = non-LPC / not-convertible / deprioritized-English archives. "
          "Byte-identical duplicate archive files share their sibling's number "
          "(duplicate_of set).")

def load_all_meta():
    entries = []
    if os.path.isdir(LIBS_DIR):
        for slug in sorted(os.listdir(LIBS_DIR)):
            meta_path = os.path.join(LIBS_DIR, slug, "meta.json")
            if os.path.isfile(meta_path):
                with open(meta_path, encoding="utf-8") as f:
                    entries.append(json.load(f))
    if os.path.isdir(NON_MUDLIB_DIR):
        for fn in sorted(os.listdir(NON_MUDLIB_DIR)):
            if fn.endswith(".json"):
                with open(os.path.join(NON_MUDLIB_DIR, fn), encoding="utf-8") as f:
                    entries.append(json.load(f))
    return entries

def sort_key(entry):
    parts = entry["number"].split("-")
    base = int(parts[0])
    suffix = int(parts[1]) if len(parts) > 1 else 0
    return (base, suffix)

def main():
    entries = load_all_meta()
    entries.sort(key=sort_key)

    unique_games = len({e["number"].split("-")[0] for e in entries if int(e["number"].split("-")[0]) < 900})

    out = {
        "scheme": SCHEME,
        "unique_games": unique_games,
        "libs": entries,
    }
    with open(OUT, "w", encoding="utf-8") as f:
        json.dump(out, f, ensure_ascii=False, indent=2)
    print(f"assembled {len(entries)} entries ({unique_games} unique game families) -> {OUT}")

if __name__ == "__main__":
    main()
