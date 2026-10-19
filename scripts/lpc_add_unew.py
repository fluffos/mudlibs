#!/usr/bin/env python3
"""scripts/lpc_add_unew.py SLUG... [--apply]

`unew(file)` is `new()` with the "unique" limit of the object honoured (the xkx lineage's sect NPCs and weapons call it).  A lib that calls it
without a definition dies in every caller with `Undefined function unew` (and `Bad assignment ( object vs unknown )` on the line that
assigns its result): KB 06 section 7.262.  The sefun is appended to the lib's `object.lpc` of the simulated-efun directory (the nitan family:
`adm/kernel/simul_efun/object.lpc`) or to the single simulated-efun file (`adm/single/simul_efun.lpc`); the text is the one dtsl, dtsl2, dtslmud,
pkuxkx, sjpl2 and sjplii carry, and a missing file does not kill the caller.  A lib that defines `unew` already is skipped.
Binary-safe, line endings of the target kept; without --apply the plan is printed."""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BODY = '''
object unew(string str) {
  object ob;
  int i, j, k;
  object *clone;

  if (!stringp(str)) return 0;

  ob = new(str);
  // new() of a missing file returns 0; the query below would raise call_other() Bad argument 1 and kill
  // the caller (carry_object() in an NPC's create())
  if (!ob) return ob;

  i = ob->query("unique");

  if (!i) return ob;
  clone = filter_array(children(base_name(ob)), (: clonep :));
  j = sizeof(clone);
  while (j--)
    if (!clone[j]->query("clone_by_wizard")) {
      if (k = clone[j]->query_amount()) i -= k;
      else i--;
    }
  if (i < 0) destruct(ob);
  return ob;
}
'''


def target(slug):
    cfg = open(f"{REPO}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace").read()
    m = re.search(r"(?m)^simulated efun file\s*:\s*(\S+)", cfg)
    if not m:
        return None
    path = m.group(1)
    d = f"{REPO}/libs/{slug}/work{path}"
    if os.path.isdir(d) and os.path.exists(d + "/object.lpc"):
        return d + "/object.lpc"
    f = d if d.endswith(".lpc") else d + ".lpc"
    return f if os.path.exists(f) else None


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    for slug in [a for a in args if not a.startswith("--")]:
        t = target(slug)
        if not t:
            print(f"SKIP  {slug}: no simulated efun file found")
            continue
        sdir = os.path.dirname(t)
        text = open(t, "rb").read()
        if re.search(rb"(?m)^\s*(?:varargs\s+)?object\s+unew\s*\(", text):
            print(f"SKIP  {slug}: unew() is defined in {os.path.relpath(t, REPO)}")
            continue
        eol = b"\r\n" if b"\r\n" in text else b"\n"
        add = BODY.encode("utf-8").replace(b"\n", eol)
        if not text.endswith(b"\n"):
            text += eol
        print(f"ADD   {slug}: unew() -> /{os.path.relpath(t, REPO + '/libs/' + slug + '/work')}")
        if apply:
            open(t, "wb").write(text + add)


if __name__ == "__main__":
    main()
