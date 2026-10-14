#!/usr/bin/env python3
"""scripts/lpc_save_encoding.py [--apply] SLUG...|--all
Text save files (`.o` starting with `#`) that were never transcoded: the archive's GBK or BIG5 bytes are still there, so
`restore_object()` stops with `Invalid utf8 string while restoring <var>` and the object starts empty (an emote daemon with
no emotes, a board with no posts, a player who cannot log in).  For each tracked one that is not valid UTF-8:
  - decode as GB18030 or BIG5 (cp950), whichever reads like the lib's own UTF-8 sources (mean log frequency of its CJK
    characters: the other decoding is mojibake made of rare characters); a lib whose sources hold almost no CJK (English,
    Finnish) has Latin-1 bytes instead.  A file with at most 8 stray half characters (a byte cut off by a length limit,
    `\\xa1\\r`) is decoded as GB18030 with those bytes dropped;
  - MudOS wrote a backslash in a string as `\\\\`; a GBK/BIG5 character whose second byte is 0x5C followed by that escape
    (`XX 5C 5C`) would decode as character + a lone escape, so the extra 0x5C is dropped first when that is what parses;
  - the result must parse as a save file (every `name value` line a complete literal: numbers, floats, strings with
    escapes, ({ }), ([ ]), class records), otherwise the file is listed and left alone.
A double-byte character split by an ANSI colour code (BBS colour art) is rejoined and a lone lead byte dropped; trailing
zero padding is stripped.  Saves with zeroed blocks in the middle (disk damage) or broken literals stay listed.
Encrypted or binary saves (no `#` header) are skipped.  Without --apply only the plan is printed."""
import collections
import math
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class Bad(Exception):
    pass


def parse_value(s, i):
    n = len(s)
    if i >= n:
        return i   # an empty value at the end of the file
    c = s[i]
    if c in ",:])}/\r\n":   # an unsaveable value (a function pointer, an object) is written as nothing
        return i
    if c == '"':
        i += 1
        while i < n:
            if s[i] == "\\":
                i += 2
                continue
            if s[i] == '"':
                return i + 1
            i += 1
        raise Bad("open string")
    if s.startswith("({", i):
        i += 2
        while True:
            if s.startswith("})", i):
                return i + 2
            i = parse_value(s, i)
            if i < n and s[i] == ",":
                i += 1
            elif not s.startswith("})", i):
                raise Bad("array")
    if s.startswith("([", i):
        i += 2
        while True:
            if s.startswith("])", i):
                return i + 2
            i = parse_value(s, i)
            if i >= n or s[i] != ":":
                raise Bad("mapping key")
            i = parse_value(s, i + 1)
            if i < n and s[i] == ",":
                i += 1
            elif not s.startswith("])", i):
                raise Bad("mapping")
    if s.startswith("(/", i):   # class
        i += 2
        while True:
            if s.startswith("/)", i):
                return i + 2
            i = parse_value(s, i)
            if i < n and s[i] == ",":
                i += 1
            elif not s.startswith("/)", i):
                raise Bad("class")
    m = re.compile(r"-?[0-9]+(?:\.[0-9]+(?:e[-+]?[0-9]+)?)?(?:=[0-9a-f]+)?").match(s, i)
    if m and m.end() > i:
        return m.end()
    raise Bad("value at %d: %r" % (i, s[i:i + 20]))


def parses(text):
    """The whole file as one stream: old saves keep raw newlines inside strings."""
    i, n = 0, len(text)
    while i < n:
        if text[i] in "\r\n":
            i += 1
            continue
        if text[i] == "#" and (i == 0 or text[i - 1] == "\n"):
            j = text.find("\n", i)
            i = n if j < 0 else j + 1
            continue
        m = re.compile(r"[A-Za-z_]\w* ").match(text, i)
        if not m:
            return False
        try:
            i = parse_value(text, m.end())
        except Bad:
            return False
        while i < n and text[i] == "\r":
            i += 1
        if i < n and text[i] != "\n":
            return False
    return True


def lib_profile(slug, cache={}):
    """CJK character counts of the lib's own (UTF-8) sources: the yardstick for which decoding reads like this lib."""
    if slug in cache:
        return cache[slug]
    files = subprocess.run(["git", "ls-files", "-z", "--", "libs/%s/work/*.lpc" % slug, "libs/%s/work/*.h" % slug],
                           cwd=REPO, capture_output=True).stdout.split(b"\0")
    counts, chars = collections.Counter(), 0
    for f in files[:4000]:
        if not f:
            continue
        try:
            t = open(os.path.join(REPO, f.decode("utf-8", "surrogateescape")), encoding="utf-8").read()
        except (OSError, UnicodeDecodeError):
            continue
        chars += len(t)
        counts.update(ch for ch in t if "\u3400" <= ch <= "\u9fff")
    cache[slug] = (counts, sum(counts.values()), chars)
    return cache[slug]


def score(text, profile):
    counts, total, _ = profile
    cjk = [ch for ch in text if "\u3400" <= ch <= "\u9fff"]
    if not cjk or not total:
        return 0.0
    return sum(math.log((counts.get(ch, 0) + 0.1) / total) for ch in cjk) / len(cjk)


def repair_dbcs(b):
    out, i, n = bytearray(), 0, len(b)
    esc = re.compile(rb"(?:\x1b\[[0-9;]*m)+")
    while i < n:
        c = b[i]
        if c < 0x81 or c == 0xff:
            out.append(c)
            i += 1
            continue
        m = esc.match(b, i + 1)
        j = m.end() if m else i + 1
        if j < n and (0x40 <= b[j] <= 0x7e or 0x80 <= b[j] <= 0xfe):
            out += bytes([c, b[j]])
            if m:
                out += m.group(0)
            i = j + 1
        else:
            i += 1   # a lone lead byte
    return bytes(out)


def candidates(b, profile):
    """(text, label) pairs, best first: decodings that read like the lib's own text come first."""
    counts, total, chars = profile
    western = chars and total < chars * 0.005   # an English/Finnish lib: its 8-bit bytes are Latin-1, not GBK
    undoubled = re.sub(rb"([\x81-\xfe]\x5c)\x5c", rb"\1", b)
    out = []
    variants = [(b, ""), (undoubled, "+5c")]
    if b.endswith(b"\x00") and b"\x00" not in b.rstrip(b"\x00"):
        variants.append((b.rstrip(b"\x00"), "+nul"))   # zero padding after the last line
    if not western:
        # BBS colour art splits one double-byte character with an ANSI code (lead, ESC[1m, trail): put the
        # code after the character; a lead byte with no trail (cut off by a length limit) is dropped
        joined = repair_dbcs(b)
        if joined != b:
            variants.append((joined, "+joined"))
    for raw, tag in variants:
        if western:
            out.append((raw.decode("latin-1"), "latin-1" + tag, 1.0))
            continue
        for enc in ("gb18030", "cp950"):
            try:
                t = raw.decode(enc)
                out.append((t, enc + tag, score(t, profile)))
            except UnicodeDecodeError:
                pass
        t = raw.decode("gb18030", "replace")
        if t.count("\ufffd") <= 8:
            t2 = raw.decode("gb18030", "ignore")
            out.append((t2, "gb18030-drop%d%s" % (t.count("\ufffd"), tag), score(t2, profile) - 0.01))
    out.sort(key=lambda x: -x[2])
    return [(t, how) for t, how, _ in out]


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    apply = "--apply" in sys.argv
    pat = ["libs/*/work/*.o"] if "--all" in sys.argv else ["libs/%s/work/*.o" % s for s in args]
    files = subprocess.run(["git", "ls-files", "-z", "--"] + pat, cwd=REPO, capture_output=True).stdout.split(b"\0")
    done = left = 0
    for f in files:
        if not f:
            continue
        p = os.path.join(REPO, f.decode("utf-8", "surrogateescape"))
        try:
            b = open(p, "rb").read()
        except OSError:
            continue
        if not b.startswith(b"#"):
            continue
        try:
            b.decode("utf-8")
            continue
        except UnicodeDecodeError:
            pass
        pick = None
        slug = f.decode("utf-8", "surrogateescape").split("/")[1]
        for text, how in candidates(b, lib_profile(slug)):
            if parses(text):
                pick = (text, how)
                break
        rel = p[len(REPO) + 1:]
        if not pick:
            print("LEFT %s: no decoding parses as a save file" % rel)
            left += 1
            continue
        print("FIX  %s (%s)" % (rel, pick[1]))
        done += 1
        if apply:
            open(p, "wb").write(pick[0].encode("utf-8"))
    print("%d file(s) %s, %d left" % (done, "converted" if apply else "to convert (plan only; --apply writes)", left))


main()
