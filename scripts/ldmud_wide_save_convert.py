#!/usr/bin/env python3
"""Convert LDMud multi-value mappings (and width-0 key sets, `(["a","b",])` -> `(["a":1,"b":1,])`) in save files (`([k:v1;v2;v3,k2:...])`) to the array-valued
form FluffOS can restore and this catalog's ported code reads (`([k:({v1,v2,v3}),k2:...])`, KB 03).  LDMud's shared
values (`<1>=({})` defines one, a later `<1>` in the same file refers back) are expanded into copies.

  python3 scripts/ldmud_wide_save_convert.py [--apply] FILE.o...

A width-1 mapping (no `;`) is left exactly as it is.  Every other line of the file is copied byte for
byte.  The parser understands the save syntax: strings with escapes, ints, floats, ({ }) arrays,
([ ]) mappings and bare tokens (0, object paths).  A line it cannot parse is left alone and reported."""
import re, sys
apply_ = "--apply" in sys.argv
files = [a for a in sys.argv[1:] if a != "--apply"]

class P:
    def __init__(self, s, refs=None): self.s = s; self.i = 0; self.wide = 0; self.refs = {} if refs is None else refs
    def peek(self): return self.s[self.i] if self.i < len(self.s) else ""
    def value(self):
        s, i = self.s, self.i
        m = re.match(r"<(\d+)>(=?)", s[i:])
        if m:   # LDMud shared value: <N>=value defines it, a bare <N> refers back (FluffOS has neither: expand a copy)
            self.i += m.end(); self.wide += 1
            if m.group(2):
                v = self.value(); self.refs[m.group(1)] = v; return v
            if m.group(1) not in self.refs: raise ValueError("undefined <%s> at %d" % (m.group(1), i))
            return self.refs[m.group(1)]
        if s.startswith('"', i):
            j = i + 1
            while s[j] != '"':
                j += 2 if s[j] == "\\" else 1
            self.i = j + 1; return s[i:j + 1]
        if s.startswith("({", i):
            self.i += 2; items = []
            while not self.s.startswith("})", self.i):
                items.append(self.value())
                if self.peek() == ",": self.i += 1
                else: break
            if not self.s.startswith("})", self.i): raise ValueError("array end at %d" % self.i)
            self.i += 2; return "({" + "".join(x + "," for x in items) + "})"
        if s.startswith("([", i):
            m = re.match(r"\(\[:\d+\]\)", s[i:])
            if m:   # empty mapping of a given width: ([:5])
                self.i += m.end(); self.wide += 1; return "([])"
            self.i += 2; pairs = []
            while not self.s.startswith("])", self.i):
                k = self.value()
                if self.peek() in (",", "]"):
                    # width-0 mapping (a key set): FluffOS has none; the ported code uses k:1
                    self.wide += 1; pairs.append(k + ":1")
                    if self.peek() == ",": self.i += 1
                    continue
                if self.peek() != ":": raise ValueError("':' expected at %d" % self.i)
                self.i += 1; vals = [self.value()]
                while self.peek() == ";":
                    self.i += 1; vals.append(self.value())
                if len(vals) > 1:
                    self.wide += 1; v = "({" + "".join(x + "," for x in vals) + "})"
                else:
                    v = vals[0]
                pairs.append(k + ":" + v)
                if self.peek() == ",": self.i += 1
                else: break
            if not self.s.startswith("])", self.i): raise ValueError("mapping end at %d" % self.i)
            self.i += 2; return "([" + "".join(p + "," for p in pairs) + "])"
        j = i
        while j < len(s) and s[j] not in ",;:)]}": j += 1
        if j == i: raise ValueError("token at %d" % i)
        self.i = j; return s[i:j]

total = 0
for f in files:
    raw = open(f, "rb").read(); text = raw.decode("latin-1")
    nl = "\r\n" if "\r\n" in text else "\n"
    out = []; changed = 0; refs = {}   # shared values are numbered per file
    for line in text.split(nl):
        sp = line.find(" ")
        if sp > 0 and not line.startswith("#") and ("([" in line or re.search(r"<\d+>", line)):
            try:
                p = P(line[sp + 1:], refs); v = p.value()
                if p.i == len(p.s) and p.wide:
                    line = line[:sp + 1] + v; changed += p.wide
            except (ValueError, IndexError) as e:
                print(f"  {f}: {line[:sp]}: cannot parse ({e})")
        out.append(line)
    if changed:
        total += changed
        print(f"{f}: {changed} multi-value entr{'y' if changed == 1 else 'ies'}")
        if apply_: open(f, "wb").write(nl.join(out).encode("latin-1"))
print("converted", total)
