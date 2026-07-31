"""Regenerate the numbering table in the top-level README.md (between
the BEGIN/END NUMBERING TABLE markers) from scripts/lib_numbering.json.
Run scripts/assemble_numbering.py first if any meta.json changed.

Usage: python3 scripts/gen_readme_table.py
"""
import json, os, re

MUDLIB_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
README = os.path.join(MUDLIB_ROOT, "README.md")
NUMBERING = os.path.join(MUDLIB_ROOT, "scripts", "lib_numbering.json")

BEGIN = "<!-- BEGIN NUMBERING TABLE (generated from lib_numbering.json) -->"
END = "<!-- END NUMBERING TABLE -->"

def status_label(entry):
    ws = entry.get("wasm_status") or ""
    if ws == "playable":
        return "WASM playable"
    if ws in ("limited", "partial"):
        return f"WASM {ws}"
    if ws in ("not-mudlib", "not-convertible", "deprioritized", "noboot",
              "binary-pending-tooling"):
        return ws
    if ws:
        return ws
    if entry.get("port"):
        return "native-boot verified, WASM pending"
    return "pending"

def main():
    with open(NUMBERING, encoding="utf-8") as f:
        data = json.load(f)

    rows = ["| # | Slug | Game | Original archive | Port | WASM |", "|---|---|---|---|---|---|"]
    for e in data["libs"]:
        name = e.get("name") or e["slug"]
        archive = e.get("archive") or ""
        port = e.get("port") or "—"
        rows.append(
            f"| {e['number']} | `{e['slug']}` | {name} | `{archive}` | {port} | {status_label(e)} |"
        )
    table = "\n".join(rows)

    with open(README, encoding="utf-8") as f:
        content = f.read()

    pattern = re.compile(re.escape(BEGIN) + r".*?" + re.escape(END), re.DOTALL)
    replacement = f"{BEGIN}\n{table}\n{END}"
    new_content, n = pattern.subn(replacement, content)
    if n != 1:
        raise SystemExit(f"expected exactly one BEGIN/END NUMBERING TABLE block, found {n}")

    with open(README, "w", encoding="utf-8") as f:
        f.write(new_content)
    print(f"wrote {len(data['libs'])} rows to README.md's numbering table")

if __name__ == "__main__":
    main()
