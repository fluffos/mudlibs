#!/usr/bin/env python3
"""scripts/lpc_scan_callout_targets.py [--unsure] [--kinds=call_out,add_action,input_to] [SLUG...]

A named function that `call_out("name", ...)`, `add_action("name", "verb")` or `input_to("name")` hands to the driver and that neither the object, its
`#include`d headers nor anything it inherits defines (KB 06 section 7.349).  The driver does nothing for a `call_out` / `input_to` to a function it does not
know (`safe_apply`): the timer fires into nothing (the buff that `check_fight` was to end never ends, the NPC that was to `destroying` stays, the reset that
`rebuild` was to run never comes) and the prompt that `input_to` opened is dead.  A VERB bound to such a function is worse: the player's command raises
`*Function for verb 'drop' not found.` and the verb's other handlers are never tried (one Guiyuan pill in the inventory and nothing can be dropped).  A renamed
or lost function is invisible to a compile pass.

Static resolver (no boot): per lib the tracked files are indexed, `#define NAME "/path"` macros are collected from every header of the lib, and each
object's definitions are the function definitions (a body, comments and strings masked) of the file, of the headers it includes (relative to the file or
in the lib's include dirs) and, recursively, of every file named by its `inherit` lines (a string, a macro, `__DIR__ "x"`).  A target that none of these
define is printed as `HIT<TAB>kind<TAB>slug<TAB>file<TAB>target<TAB>line`.  An inherit that cannot be resolved (a computed name, a file the archive lacks) makes
the object UNSURE: its missing targets are listed only with --unsure (`UNSURE<TAB>kind<TAB>...`), because the target may live in the part nobody can see.
Gitlink libs and wizard / backup directories are skipped.  Read every hit: a function created by a macro, a `#include` of a body that is not a header, or
a deliberate no-op timer (`call_out("destroy_me")` in an object whose parent was never shipped) is not a bug."""
import collections
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from lpc_fix_void_return import code_mask  # noqa: E402

GITLINKS = {"nt7", "xkx100utf8", "fy2005", "nightmare3", "residuum", "sanguozhi", "oxidus", "deadsouls_fluffos"}
SKIP = re.compile(r"/(u|w|wiz|wizard|wizards|open|players|backup|backups|old|bak|log|data|doc|example|examples|realms|test|tmp|raw)/|[-_.](bak|old)/")
FUNC = re.compile(rb"(?m)(?:^|[;}])[ \t]*((?:[A-Za-z_]\w*[ \t*]+)*)\**([A-Za-z_]\w*)[ \t\r\n]*\(([^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*)\)[ \t\r\n]*\{")      # a definition may follow a `}` or `;` on the same line (`void destroying() {..} int do_zhao()`)
NOT_FUNC = {b"if", b"while", b"for", b"switch", b"foreach", b"catch", b"return", b"sizeof", b"else", b"do"}
CALLOUT = re.compile(rb'(?<![A-Za-z_])call_out\(\s*"([A-Za-z_]\w*)"(?=\s*[,)])')
KINDS = collections.OrderedDict([
    ("call_out", re.compile(rb'(?<![A-Za-z_])call_out\(\s*"([A-Za-z_]\w*)"(?=\s*[,)])')),
    ("add_action", re.compile(rb'(?<![A-Za-z_])add_action\(\s*"([A-Za-z_]\w*)"(?=\s*[,)])')),
    ("input_to", re.compile(rb'(?<![A-Za-z_])(?:input_to|get_char)\(\s*"([A-Za-z_]\w*)"(?=\s*[,)])')),
])
DEFINE = re.compile(rb'(?m)^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)[ \t]+((?:(?:__DIR__|[A-Za-z_]\w*)(?!\w)[ \t]*|"[^"\n]*"[ \t]*)+)[ \t]*(?://.*)?\r?$')      # a path: strings, `__DIR__` and other macros (`FEATURE_DIR "item/fruit"`); `(?!\w)` keeps a word from being split, so a failing line costs one pass
INHERIT = re.compile(rb"(?m)(?:^|(?<=[;}]))[ \t]*inherit[ \t]+([^;]+);")      # `inherit NPC;inherit F_DEALER;` on one line is two inherits
INCLUDE = re.compile(rb'(?m)^[ \t]*#[ \t]*include[ \t]+([<"])([^>"\n]+)[>"]')
INCLUDE_MACRO = re.compile(rb'(?m)^[ \t]*#[ \t]*include[ \t]+([A-Za-z_][^\r\n]*)')       # `#include ED_DIR "buffer.lpc"`, `#include ROOM_FUNCTS`, `#include __DIR__"x.lpc"`
STR = re.compile(rb'"([^"\n]*)"')
FDEFINE = re.compile(rb'(?m)^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)\(([A-Za-z_\w, ]*)\)[ \t]+((?:"[^"\n]*"|[A-Za-z_]\w*(?!\w)|[ \t+()])+)[ \t]*(?://.*)?\r?$')


def strip_comments(b):
    b = re.sub(rb"/\*.*?\*/", lambda m: b"\n" * m.group(0).count(b"\n"), b, flags=re.S)
    return re.sub(rb"(?m)//[^\n]*", b"", b)


def masked(b):
    m = code_mask(b, heredoc=True)       # a `@LONG ... LONG` block of ASCII art holds quote marks that would shift the mask
    return bytes(c if m[i] else 32 for i, c in enumerate(b))


class Lib:
    def __init__(self, slug):
        self.slug = slug
        out = subprocess.run(["git", "ls-files", "-z", "--", f"libs/{slug}/work"], cwd=REPO, capture_output=True).stdout
        pre = f"libs/{slug}/work"
        self.files = set(p.decode("utf-8", "surrogateescape")[len(pre):] for p in out.split(b"\0") if p)
        self.cache = {}
        self.expanding = set()
        self.macros = {}
        for f in sorted(self.files):
            if f.endswith(".h") and not SKIP.search(f):
                b = self.read(f)
                for m in DEFINE.finditer(b):
                    self.macros.setdefault(m.group(1).decode(), (m.group(2), f))
        self.fmacros = {}
        for f in sorted(self.files):
            if f.endswith(".h") and not SKIP.search(f):
                for m in FDEFINE.finditer(self.read(f)):
                    self.fmacros.setdefault(m.group(1).decode(), ([a.strip().decode() for a in m.group(2).split(b",") if a.strip()], m.group(3).strip()))
        self.incdirs = [d for d in ("/include", "/adm/include", "/inc", "/sys", "/include/std") if any(x.startswith(d + "/") for x in self.files)]
        try:
            for ln in open(f"{REPO}/libs/{slug}/config.fluffos", encoding="utf-8", errors="replace"):
                m = re.match(r"\s*include directories\s*:\s*(\S+)", ln)
                if m:
                    for d in m.group(1).split(":"):
                        d = os.path.normpath("/" + d.strip().lstrip("/"))
                        if d not in self.incdirs and d != "/.":
                            self.incdirs.append(d)
        except OSError:
            pass

    def read(self, f):
        try:
            return open(f"{REPO}/libs/{self.slug}/work{f}", "rb").read()
        except OSError:
            return b""

    def real(self, path):
        """mudlib path -> tracked file or None"""
        p = path if path.startswith("/") else "/" + path
        p = os.path.normpath(p)
        for c in (p, p + ".lpc", p + ".c", (p[:-2] + ".lpc") if p.endswith(".c") else None):
            if c and c in self.files:
                return c
        return None

    def literal(self, expr, fdir, env=None):
        """value of a concatenation of `"a"`, `__DIR__`, MACRO, MACRO("arg") and `+`, or None when it is computed"""
        env = env or {}
        rest = expr.strip()
        s = ""
        while rest:
            rest = rest.strip()
            if rest[:1] in (b"+", b"(", b")"):
                rest = rest[1:]
                continue
            if rest.startswith(b"__DIR__"):
                s += fdir
                rest = rest[7:]
                continue
            if rest.startswith(b'"'):
                m = STR.match(rest)
                if not m:
                    return None
                s += m.group(1).decode("utf-8", "replace")
                rest = rest[m.end():]
                continue
            m = re.match(rb"([A-Za-z_]\w*)\s*", rest)
            if not m:
                return None
            name = m.group(1).decode()
            rest = rest[m.end():]
            if name in env:
                s += env[name]
                continue
            if rest.startswith(b"("):
                # function-like macro with literal arguments
                depth, i = 0, 0
                while i < len(rest):
                    c = rest[i:i + 1]
                    if c == b"(":
                        depth += 1
                    elif c == b")":
                        depth -= 1
                        if depth == 0:
                            break
                    i += 1
                if depth != 0 or name not in self.fmacros:
                    return None
                args = [a for a in re.split(rb"\s*,\s*", rest[1:i].strip()) if a != b""]
                params, body = self.fmacros[name]
                if len(args) != len(params):
                    return None
                vals = []
                for a in args:
                    v = self.literal(a, fdir, env)
                    if v is None:
                        return None
                    vals.append(v)
                v = self.literal(body, fdir, dict(zip(params, vals)))
                if v is None:
                    return None
                s += v
                rest = rest[i + 1:]
                continue
            hit = self.macros.get(name)
            if not hit or name in self.expanding:           # unknown, or `#define A B` / `#define B A`
                return None
            self.expanding.add(name)
            try:
                v = self.literal(hit[0], fdir)
            finally:
                self.expanding.discard(name)
            if v is None:
                return None
            s += v
        return s

    def info(self, f):
        """(defs, inherit file list, unresolved flag) of file f, headers folded in"""
        if f in self.cache:
            return self.cache[f]
        self.cache[f] = (set(), [], False, set())     # recursion guard
        b = strip_comments(self.read(f))
        code = masked(self.read(f))
        fdir = os.path.dirname(f) + "/"
        defs, privs = set(), set()
        for m in FUNC.finditer(code):
            if m.group(2) in NOT_FUNC:
                continue
            defs.add(m.group(2))
            if re.search(rb"\bprivate\b", m.group(1)):
                privs.add(m.group(2))
        inh, unsure = [], False
        for m in INCLUDE.finditer(b):
            name = m.group(2).decode("utf-8", "replace")
            if name.startswith("/"):
                cands = [os.path.normpath(name)]
            else:
                cands = [os.path.normpath(fdir + name)] if m.group(1) == b'"' else []
                cands += [os.path.normpath(d + "/" + name) for d in self.incdirs] + [os.path.normpath("/" + name)]
            for c in cands:
                if c in self.files:
                    d2, i2, u2, p2 = self.info(c)
                    defs |= d2
                    privs |= p2
                    inh += i2
                    unsure = unsure or u2
                    break
        local = {}
        for m in DEFINE.finditer(b):
            local.setdefault(m.group(1).decode(), []).append(m.group(2))     # the file's own macros: `#if __FILE__ == ..` often defines one twice
        for m in INCLUDE_MACRO.finditer(b):
            expr = m.group(1).strip()
            vals = []
            for k in range(max([len(v) for v in local.values()] or [1])):
                env = {}
                for n, vs in local.items():
                    v = self.literal(vs[min(k, len(vs) - 1)], fdir)
                    if v is not None:
                        env[n] = v
                v = self.literal(expr, fdir, env)
                if v is not None and v not in vals:
                    vals.append(v)
            found = False
            for v in vals:
                c = self.real(v)
                if c is not None:
                    d2, i2, u2, p2 = self.info(c)
                    defs |= d2
                    privs |= p2
                    inh += i2
                    unsure = unsure or u2
                    found = True
            if not found and not (vals and all(v.endswith(".h") for v in vals)):      # a header the archive lacks defines macros; any other body is part we cannot see
                unsure = True
        for m in INHERIT.finditer(b):
            val = self.literal(m.group(1), fdir)
            r = self.real(val) if val else None
            if r is None:
                unsure = True
            else:
                inh.append(r)
        self.cache[f] = (defs, inh, unsure, privs)
        return self.cache[f]

    def children(self):
        """reverse inheritance index: file -> files that inherit it (cheap: only the inherit lines are parsed)"""
        if getattr(self, "_children", None) is None:
            ch = collections.defaultdict(list)
            for g in self.files:
                if not g.endswith((".lpc", ".c")) or SKIP.search(g):
                    continue
                b = self.read(g)
                if b"inherit" not in b:
                    continue
                gdir = os.path.dirname(g) + "/"
                for m in INHERIT.finditer(strip_comments(b)):
                    val = self.literal(m.group(1), gdir)
                    r = self.real(val) if val else None
                    if r:
                        ch[r].append(g)
            self._children = ch
        return self._children

    def derived_defines(self, f, name):
        """does a file that (transitively) inherits f define `name`?  (an abstract base schedules a timer its derived objects answer)"""
        ch = self.children()
        seen, todo = set(), list(ch.get(f, []))
        while todo:
            g = todo.pop()
            if g in seen:
                continue
            seen.add(g)
            if name in self.all_defs(g)[0]:
                return g
            todo.extend(ch.get(g, []))
        return None

    def definer(self, f, name, seen=None, top=True):
        """the file (f itself, a header it includes is folded into f, or an ancestor) that defines `name` for the object of f, or None"""
        seen = seen if seen is not None else set()
        if f in seen:
            return None
        seen.add(f)
        defs, inh, unsure, privs = self.info(f)
        if name in defs and (top or name not in privs):
            return f
        for i in inh:
            r = self.definer(i, name, seen, False)
            if r:
                return r
        return None

    def all_defs(self, f, seen=None, top=True):
        """names the object of f can answer: its own functions (private ones too), the non-private functions of its ancestors.
        Returns (names, unsure, hidden) -- hidden: names that exist only as `private` functions of an ancestor"""
        seen = seen if seen is not None else set()
        if f in seen:
            return set(), False, set()
        seen.add(f)
        defs, inh, unsure, privs = self.info(f)
        vis = set(defs) if top else set(defs) - privs
        hidden = set() if top else set(privs)
        for i in inh:
            d2, u2, h2 = self.all_defs(i, seen, False)
            vis |= d2
            hidden |= h2
            unsure = unsure or u2
        return vis, unsure, hidden - vis


def main():
    argv = sys.argv[1:]
    show_unsure = "--unsure" in argv
    kinds = list(KINDS)
    for a in argv:
        if a.startswith("--kinds="):
            kinds = a.split("=", 1)[1].split(",")
    libs = [a for a in argv if not a.startswith("--")] or sorted(d for d in os.listdir(f"{REPO}/libs") if os.path.isdir(f"{REPO}/libs/{d}/work"))
    hits = unsure_n = 0
    for slug in libs:
        if slug in GITLINKS:
            continue
        lib = Lib(slug)
        for f in sorted(lib.files):
            if not f.endswith((".lpc", ".c")) or SKIP.search(f):
                continue
            b = lib.read(f)
            if not any(k.encode() in b for k in kinds):
                continue
            text = strip_comments(b)
            targets = collections.OrderedDict()
            for kind in kinds:
                for m in KINDS[kind].finditer(text):
                    targets.setdefault((kind, m.group(1)), text[:m.start()].count(b"\n") + 1)
            if not targets:
                continue
            defs, unsure, hidden = lib.all_defs(f)
            for (kind, t), line in targets.items():
                if t in defs:
                    continue
                if lib.derived_defines(f, t):
                    continue
                if t in hidden:
                    hits += 1
                    print(f"PRIVATE\t{kind}\t{slug}\t{f}\t{t.decode()}\t{line}")
                elif unsure:
                    unsure_n += 1
                    if show_unsure:
                        print(f"UNSURE\t{kind}\t{slug}\t{f}\t{t.decode()}\t{line}")
                else:
                    hits += 1
                    print(f"HIT\t{kind}\t{slug}\t{f}\t{t.decode()}\t{line}")
    print(f"{hits} hit(s), {unsure_n} unsure", file=sys.stderr)


if __name__ == "__main__":
    main()
