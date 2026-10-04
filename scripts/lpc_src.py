"""Small LPC source helpers shared by the scripts/lpc_*.py fixers."""
import re

def read(path):
    try:
        return open(path, "rb").read().decode("latin-1")
    except OSError:
        return None


def blank_if0(src):
    """blank the inactive part of `#if 0` ... `#else`/`#endif` blocks (keeps newlines)"""
    lines = src.split("\n")
    depth, dead = 0, None
    for k, l in enumerate(lines):
        t = l.strip()
        if re.match(r"#\s*if(n?def)?\b", t):
            depth += 1
            if dead is None and re.match(r"#\s*if\s+0\s*($|//|/\*)", t):
                dead = depth
            continue
        if re.match(r"#\s*(else|elif)\b", t) and dead == depth:
            dead = None
            continue
        if re.match(r"#\s*endif\b", t):
            if dead == depth:
                dead = None
            depth -= 1
            continue
        if dead is not None:
            lines[k] = re.sub(r"[^\r]", " ", l)
    return "\n".join(lines)


HEREDOC = re.compile(r"@@?(\w+)[ \t]*\r?\n.*?\r?\n\1\b", re.S)


def blank_heredocs(src):
    """blank `@TEXT ... TEXT` here-document text (keeps newlines): a quote or apostrophe inside it would otherwise
    flip the string state of everything after it and hide the closing braces of the functions that follow"""
    return HEREDOC.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), src)


def mask(src):
    """same-length copy with comments, string/char literal contents, here-documents and `#if 0` blocks blanked"""
    src = blank_heredocs(blank_if0(src))
    out, i, n = list(src), 0, len(src)
    while i < n:
        c, two = src[i], src[i:i + 2]
        if two == "//":
            while i < n and src[i] != "\n":
                out[i] = " "
                i += 1
        elif two == "/*":
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if src[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            j = i + 1
            while j < n and src[j] != c and src[j] != "\n":
                j += 2 if src[j] == "\\" else 1
            for k in range(i + 1, min(j, n)):
                out[k] = " "
            i = j + 1
        else:
            i += 1
    return "".join(out)


MODS = {"varargs", "private", "protected", "public", "nomask", "static", "nosave", "deprecated"}
TYPES = {"void", "int", "string", "object", "mixed", "mapping", "float", "function", "status", "buffer"}


def top_level_defs(src, fn):
    """[(name start, open paren, close paren)] of every top-level definition of fn in the source"""
    m = mask(src)
    depth, i, n = 0, 0, len(m)
    found = []
    while i < n:
        c = m[i]
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
        elif depth == 0 and m.startswith(fn, i) and not (i and (m[i - 1].isalnum() or m[i - 1] == "_")) \
                and not (i + len(fn) < n and (m[i + len(fn)].isalnum() or m[i + len(fn)] == "_")):
            j = i + len(fn)
            while j < n and m[j] in " \t\r\n":
                j += 1
            if j < n and m[j] == "(":
                k, d = j, 0
                while k < n:
                    d += (m[k] == "(") - (m[k] == ")")
                    if d == 0:
                        break
                    k += 1
                e = k + 1
                while e < n and m[e] in " \t\r\n":
                    e += 1
                if e < n and m[e] == "{":
                    found.append((i, j, k))
        i += 1
    return found
