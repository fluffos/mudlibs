"""Structured comparison of two scripts/ds_oracle.py outputs (KB 08 section 10.12).

usage: scripts/ds_oracle_diff.py OLD NEW [--objs REGEX] [--verbose] [--no-visibility]
Per object: function definer changes, visibility flips (public -> hidden), added/removed functions, variable
multiset changes (count down = a duplicate removed or renamed), getter and dynamic result changes keyed by label.
Without --verbose at most 14 lines are printed per object and the rest is summarised ("... N more").
--no-visibility drops the public -> hidden flips, which a `nosave` -> `protected` sweep makes by the thousand.
Random NPC stats (HP, MaxCarry) and clone-numbered ids differ between any two runs: read them as noise."""
import re, sys, collections
old_f, new_f = sys.argv[1], sys.argv[2]
objre = None
verbose = "--verbose" in sys.argv
no_vis = "--no-visibility" in sys.argv
if "--objs" in sys.argv: objre = re.compile(sys.argv[sys.argv.index("--objs") + 1])
def parse(path):
    objs = collections.OrderedDict(); cur = None; sect = None
    for l in open(path, errors="replace").read().split("\n"):
        if l.startswith("OBJ "):
            cur = {"fn": {}, "var": collections.Counter(), "get": {}, "dyn": {}, "kind": ""}; objs[l[4:]] = cur; sect = None; continue
        if cur is None: continue
        s = l.strip()
        if s.startswith("kind:"): cur["kind"] = s[5:].strip()
        elif s.startswith("functions:"): sect = "fn"
        elif s.startswith("variables:"): sect = "var"
        elif s == "getters:": sect = "get"
        elif s == "dynamic:": sect = "dyn"
        elif sect == "fn" and s.startswith("fn "):
            m = re.match(r"fn (\S+) @ (\S+) (pub|hid)$", s)
            if m: cur["fn"][m.group(1)] = (m.group(2), m.group(3))
        elif sect == "var" and s.startswith("var "): cur["var"][s[4:]] += 1
        elif sect in ("get", "dyn") and " = " in s:
            k, v = s.split(" = ", 1); cur[sect][k] = v
    return objs
O, N = parse(old_f), parse(new_f)
summary = collections.Counter(); printed = 0
for name in O:
    if objre and not objre.search(name): continue
    if name not in N:
        print(f"{name}: MISSING in new"); continue
    a, b = O[name], N[name]
    lines = []
    for fn in sorted(set(a["fn"]) | set(b["fn"])):
        x, y = a["fn"].get(fn), b["fn"].get(fn)
        if x != y:
            if x is None: lines.append(f"  fn + {fn} @ {y[0]} {y[1]}"); summary["fn-added"] += 1
            elif y is None: lines.append(f"  fn - {fn} (was @ {x[0]})"); summary["fn-removed"] += 1
            elif x[1] != y[1]:
                summary["fn-visibility"] += 1
                if not no_vis: lines.append(f"  fn {fn}: {x[1]} -> {y[1]}")
            else: lines.append(f"  fn {fn}: defined in {x[0]} -> {y[0]}"); summary["fn-definer"] += 1
    for v in sorted(set(a["var"]) | set(b["var"])):
        x, y = a["var"].get(v, 0), b["var"].get(v, 0)
        if x != y:
            lines.append(f"  var {v}: x{x} -> x{y}"); summary["var-count"] += 1
    for sect in ("get", "dyn"):
        for k in sorted(set(a[sect]) | set(b[sect])):
            x, y = a[sect].get(k), b[sect].get(k)
            if x != y:
                lines.append(f"  {sect} {k}: {str(x)[:90]} -> {str(y)[:90]}"); summary[sect + "-result"] += 1
    if lines:
        printed += 1
        print(f"{name}  [{b['kind']}]")
        for l in lines[:(200 if verbose else 14)]: print(l)
        if len(lines) > (200 if verbose else 14): print(f"  ... {len(lines) - 14} more")
print(f"\n{printed} objects differ of {len(O)}; totals: {dict(summary)}")
