#!/usr/bin/env python3
"""scripts/lpc_uncollapse.py [SLUG...] [--apply] [--list FILE]

An object whose whole source sits on one line behind a leading `//` is an empty program: the driver compiles the comment and
nothing else (KB 06 section 7.268).  The archive's editor lost the line breaks and kept the indentation:

    // greyrobe.c 青色道袍// By kyd#include <armor.h>inherit CLOTH;void create(){\tset_name("青色道袍", ...);    set_weight(3000);    if( clonep() ) ...

so the sect robe, the tea-house child `taoyuan/npc/kid`, the `idiot` condition, hc's `zhenyuan-force` skill, wuhanzhan's shaolin kitchen and
weapon items ... load fine and are empty (no name, no id, nothing to wield).  Nothing in the compile scan or the load census sees them.

For every tracked `.lpc` / `.h` file with at most three line breaks whose first line starts with `//` and carries code:
  1. the leading comment head is cut at the first `#include` / `inherit` / `#define` / `#pragma` / function header;
     every `//` inside the head starts a line of its own;
  2. the code is walked with strings, character literals, block comments and `({ ... })` / `([ ... ])` literals kept whole, and a line
     break is put after each `;` outside parentheses, after each block `{` and `}`, after `#include <...>`, `#include "..."`,
     `#ifdef X`, `#ifndef X`, `#else`, `#endif`;
  3. a `//` comment inside the code ends at the first whitespace run of 4 or more characters (or a tab) after its first word: the run was the
     indentation of the next line;
  4. the text is saved with LF line endings (the one final CR LF of the archive stays on the last line).
A file with a `#define` / `#if` / heredoc (`@TEXT`) in the code, or an unbalanced result, is listed and left.  The result is not formatted:
run `format-corpus.mjs` over the changed files afterwards (KB 08 section 9) and load them at HEAD and in the tree.
Without --apply the plan is printed (FIX / SKIP lines); idempotent (a restored file has more than three line breaks)."""
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CODE_START = re.compile(r"(#\s*include\b|#\s*define\b|#\s*pragma\b|#\s*if(?:n?def)?\b)|"
                        r"(inherit\s+(?:[A-Z_]{2,}|__DIR__|\")|"
                        r"(?<![A-Za-z0-9_])(?:varargs\s+|nomask\s+|static\s+|private\s+|protected\s+|nosave\s+)*(?:void|int|string|mixed|object|mapping|float)\s+\**\w+\s*\()")
SKIP_DIRS = re.compile(r"/work/(backup|backups|bak|old)/")


def collapsed(b):
    if b.count(b"\n") > 3 or len(b) < 100:
        return False
    first = b.split(b"\n", 1)[0].lstrip()
    if not first.startswith(b"//"):
        return False
    return b";" in first and b"{" in first and b"}" in first


def head_and_code(text):
    m = CODE_START.search(text)
    if not m:
        return None, None
    return text[:m.start()], text[m.start():]


def comment_end(code, i):
    """index where the `//` comment starting at code[i] ends: before the first whitespace run of 4+ chars (or a tab) that follows a word"""
    j = i + 2
    n = len(code)
    seen_word = False
    while j < n:
        c = code[j]
        if c in " \t":
            k = j
            while k < n and code[k] in " \t":
                k += 1
            if seen_word and (k - j >= 4 or "\t" in code[j:k]):
                return j
            j = k
            continue
        seen_word = True
        j += 1
    return n


def reflow(code):
    """-> list of lines, or (None, reason)"""
    out = []
    cur = []
    i, n = 0, len(code)
    paren = 0
    lit = 0          # depth of ({ ... }) / ([ ... ]) literals
    idx = 0          # depth of a[...] index brackets
    stack = []       # kinds of open braces: 'b' block, 'l' literal
    nl_after_close = False

    def flush():
        s = "".join(cur).strip()
        if s:
            out.append(s)
        cur.clear()

    while i < n:
        c = code[i]
        two = code[i:i + 2]
        if c == '"':
            j = i + 1
            while j < n and code[j] != '"':
                j += 2 if code[j] == "\\" else 1
            cur.append(code[i:j + 1])
            i = j + 1
            continue
        if c == "'":
            j = i + 1
            while j < n and code[j] != "'":
                j += 2 if code[j] == "\\" else 1
            cur.append(code[i:j + 1])
            i = j + 1
            continue
        if two == "/*":
            j = code.find("*/", i + 2)
            if j < 0:
                return None, "unterminated block comment"
            cur.append(code[i:j + 2])
            i = j + 2
            continue
        if two == "//":
            j = comment_end(code, i)
            flush()
            out.append(code[i:j].strip())
            i = j
            while i < n and code[i] in " \t":
                i += 1
            continue
        if c == "@" and re.match(r"@[A-Za-z_]+", code[i:]):
            # `@LONG text LONG`: the text lost its line breaks too (kept as one line); the markers get lines of their own
            name = re.match(r"@([A-Za-z_]+)", code[i:]).group(1)
            end = re.search(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])", code[i + 1 + len(name):])
            if not end:
                return None, f"heredoc @{name} without a closing marker"
            body = code[i + 1 + len(name):i + 1 + len(name) + end.start()]
            cur.append("@" + name)
            flush()
            out.append(body.strip())
            cur.append(name)
            i += 1 + len(name) + end.start() + len(name)
            continue
        if c == "#" and (not "".join(cur).strip()):
            m = re.match(r"#\s*include\s*(<[^>\n]*>|\"[^\"\n]*\")", code[i:])
            if m:
                flush()
                out.append(m.group(0))
                i += m.end()
                while i < n and code[i] in " \t":
                    i += 1
                continue
            m = re.match(r"#\s*(ifdef|ifndef)\s+\w+", code[i:])
            if m:
                flush()
                out.append(m.group(0))
                i += m.end()
                continue
            m = re.match(r"#\s*(else|endif)\b", code[i:])
            if m:
                flush()
                out.append(m.group(0))
                i += m.end()
                continue
            return None, "a preprocessor line the walk cannot end (#define / #if / #pragma)"
        if c == "(":
            paren += 1
            cur.append(c)
            if code[i + 1:i + 2] in "{[" and code[i + 1:i + 2]:
                cur.append(code[i + 1])
                stack.append("l" if code[i + 1] == "{" else "m")
                lit += 1
                i += 2
                continue
        elif c == "[":
            idx += 1
            cur.append(c)
        elif c == "]":
            if idx > 0:
                idx -= 1
            elif stack and stack[-1] == "m" and code[i + 1:i + 2] == ")":
                stack.pop()
                lit -= 1
            cur.append(c)
        elif c == ")":
            paren -= 1
            cur.append(c)
        elif c == "{":
            if lit == 0 and paren == 0:
                stack.append("b")
                cur.append(c)
                flush()
            else:
                stack.append("l")
                lit += 1
                cur.append(c)
        elif c == "}":
            kind = stack.pop() if stack else "b"
            if kind in ("l", "m"):
                lit -= 1
                cur.append(c)
            else:
                flush()
                cur.append(c)
                # `} else`, `} while (...)` stay on the line
                rest = code[i + 1:].lstrip()
                if not re.match(r"(else\b|while\b)", rest) and not rest.startswith(";"):
                    flush()
        elif c == ";" and paren == 0 and lit == 0:
            cur.append(c)
            flush()
        else:
            cur.append(c)
        i += 1
    flush()
    if paren != 0 or lit != 0 or stack:
        return None, f"unbalanced result (paren {paren}, literal {lit}, braces {len(stack)})"
    return out, None


def restore(b):
    """-> (new bytes, None) or (None, reason)"""
    try:
        text = b.decode("utf-8")
    except UnicodeDecodeError:
        return None, "not UTF-8"
    text = text.replace("\r\n", "\n")
    lines = text.split("\n")
    first = lines[0]
    rest = "\n".join(lines[1:])
    head, code = head_and_code(first)
    if code is None:
        return None, "no code start in the first line"
    out = []
    # every `//` of the head starts a comment line
    parts = re.split(r"(?=//)", head.rstrip())
    out += [p.rstrip() for p in parts if p.strip()]
    body, why = reflow(code)
    if body is None:
        return None, why
    out += body
    tail = [l.rstrip() for l in rest.split("\n") if l.strip()]
    out += tail
    return ("\n".join(out) + "\n").encode("utf-8"), None


def main():
    args = sys.argv[1:]
    apply = "--apply" in args
    listfile = None
    if "--list" in args:
        i = args.index("--list")
        listfile = args[i + 1]
        del args[i:i + 2]
    only = [a for a in args if not a.startswith("--")]
    if listfile:
        paths = [l.strip() for l in open(listfile, encoding="utf-8") if l.strip()]
    else:
        out = subprocess.run(["git", "-c", "core.quotepath=false", "grep", "-l", "-a", "-P", r"^\s*//[^\n]{60,}\{[^\n]*;[^\n]*\}", "--",
                              "libs/*/work/*.lpc", "libs/*/work/*.h"], cwd=REPO, capture_output=True, text=True, errors="replace").stdout
        paths = [l for l in out.split("\n") if l]
    nfix = nskip = 0
    for rel in sorted(paths):
        slug = rel.split("/")[1]
        if only and slug not in only:
            continue
        if slug in ("wllz3", "longyunmeng_binary") or SKIP_DIRS.search("/" + rel):
            continue
        full = os.path.join(REPO, rel)
        try:
            b = open(full, "rb").read()
        except OSError:
            continue
        if not collapsed(b):
            continue
        new, why = restore(b)
        if new is None:
            print(f"SKIP  {slug} /{rel.split('/work/', 1)[1]}: {why}")
            nskip += 1
            continue
        nfix += 1
        print(f"FIX   {slug} /{rel.split('/work/', 1)[1]}: {new.count(chr(10).encode())} lines")
        if apply:
            open(full, "wb").write(new)
    print(f"{nfix} file(s) restored, {nskip} left" + ("" if apply else " (plan only; --apply writes)"))


if __name__ == "__main__":
    main()
