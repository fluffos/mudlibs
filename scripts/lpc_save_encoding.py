#!/usr/bin/env python3
"""scripts/lpc_save_encoding.py [--apply] [--from-raw] SLUG...|FILE...|--all
Text save files (`.o` starting with `#`) that were never transcoded: the archive's GBK or BIG5 bytes are still there, so
`restore_object()` stops with `Invalid utf8 string while restoring <var>` and the object starts empty (an emote daemon with
no emotes, a board with no posts, a player who cannot log in).  For each tracked one that is not valid UTF-8:
  - decode as GB18030 or BIG5 (cp950), whichever reads like the lib's own UTF-8 sources (mean log frequency of its CJK
    characters: the other decoding is mojibake made of rare characters); a lib whose sources hold almost no CJK (English,
    Finnish) has Windows-1252 bytes instead (Latin-1 when a byte is undefined there).  A file with at most 8 stray half characters (a byte cut off by a length limit,
    `\\xa1\\r`) is decoded as GB18030 with those bytes dropped;
  - MudOS wrote a backslash in a string as `\\\\`; a GBK/BIG5 character whose second byte is 0x5C followed by that escape
    (`XX 5C 5C`) would decode as character + a lone escape, so the extra 0x5C is dropped first when that is what parses;
  - the result must parse as a save file (every `name value` line a complete literal: numbers, floats, strings with
    escapes, ({ }), ([ ]), class records), otherwise the file is listed and left alone.
A double-byte character split by an ANSI colour code (BBS colour art) is rejoined and a lone lead byte dropped; trailing
zero padding is stripped.  Saves with zeroed blocks in the middle (disk damage) or broken literals stay listed.
Encrypted or binary saves (no `#` header) are skipped.  Without --apply only the plan is printed.

--from-raw: saves that were transcoded at onboarding but came out broken.  The conversion was
`iconv -f gb18030 -t utf-8 -c`, which drops an invalid pair as a unit: a lone lead byte before a closing quote takes the
quote with it (`"short":"\xc6\xe5\xca\xd2\xb0",` became `"short":"棋室,`), so `restore_object()` stops with `Illegal
mapping format` and the object starts empty.  For each tracked UTF-8 save (`#/` header) that does not parse: when iconv of
its raw/ original still gives the tracked bytes exactly (nobody edited it since), the original is decoded again with the
candidates above (the lone lead byte dropped, the quote kept) and the first decoding that parses replaces it.  When none
parses, the save is a GB copy of a BIG5 one: a stray backslash after a character whose BIG5 code ends in 0x5C (功, 许,
么 ...) is dropped (or the quote it swallowed escaped), nearest the break first, until it parses (dreamofseven, kxkj and naruto
boards; GBK's 賊 誠 運 ... too, and this step also runs on a save with no matching raw/, since it moves only
backslashes).  A raw newline inside a string (the archive's own saves: xjcq2000 boards and NPCs, fys) is written as
`\r`, the way save_object() stores one; restore_object() reads the file line by line and refuses it raw.  A save edited after onboarding, or whose original does not parse either, is listed and left alone.  FILE arguments
(libs/SLUG/work/...) limit the run to those saves."""
import collections
import glob
import math
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


class Bad(Exception):
    pass


_DEEP = [0]   # the furthest position parse_value() reached: where a failing save breaks


def parse_value(s, i):
    _DEEP[0] = max(_DEEP[0], i)
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
            if s[i] == "\n":   # restore_object() reads line by line: a raw newline ends the string (lf_to_cr())
                raise Bad("newline in a string")
            i += 1
        raise Bad("open string")
    if s.startswith("({", i):
        i += 2
        while True:
            if s.startswith("})", i):
                return i + 2
            i = parse_value(s, i)
            if i < n and s[i] == ",":   # save_object() ends every element with a comma; restore_object() insists
                i += 1
            else:
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
            else:
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
    """The whole file as one stream.  A raw newline inside a string and a blank line are refused, as restore_object()
    refuses them; `lf_to_cr()` writes them the way save_object() would."""
    i, n = 0, len(text)
    while i < n:
        if text[i] == "\n" or text.startswith("\r\n", i):
            return False   # a blank line: restore_object() wants `name value` on every line
        if text[i] == "\r":
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
        i += 1   # the line's own newline; another one right after it would be a blank line
    return True



def fail_pos(text):
    """None when the save parses, otherwise where the value that breaks it starts."""
    _DEEP[0] = 0
    return None if parses(text) else _DEEP[0]


def lf_to_cr(text):
    """(text, count): a raw newline inside a string literal written as `\\r`, which is how save_object() stores one,
    and blank lines dropped (restore_object() refuses a line without `name value`, even a trailing one)
    (restore_object() turns it back into a newline; a raw one ends the line and the string never closes).  The archive's
    own saves carry them (xjcq2000's boards and NPC saves, fys)."""
    out, i, n, k, ins = [], 0, len(text), 0, False
    while i < n:
        c = text[i]
        if ins:
            if c == "\\":
                out.append(text[i:i + 2])
                i += 2
                continue
            if c == '"':
                ins = False
            elif c == "\n":
                c = "\r"
                k += 1
        elif c == '"':
            ins = True
        elif c == "#" and (i == 0 or text[i - 1] == "\n"):
            j = text.find("\n", i)
            j = n if j < 0 else j + 1
            out.append(text[i:j])
            i = j
            continue
        out.append(c)
        i += 1
    lines = "".join(out).split("\n")   # every newline left is a line break now
    kept = [l for l in lines[:-1] if l not in ("", "\r")] + lines[-1:]
    k += len(lines) - len(kept)
    return "\n".join(kept), k


# Characters whose BIG5 or GBK code ends in 0x5C (BIG5 功 许 么, GBK 賊 誠 運; simplified forms too).  MudOS
# (byte-blind) wrote that byte as
# `\\`; a site that later converted the save to GB kept the character and one backslash, which now escapes whatever
# follows: `成功\",` never closes the string, and `么\\"` (the stray, then an escaped quote) closes it early.  A save
# written without the doubling has the reverse: MudOS read the 0x5C as the escape of the quote after it (`出\"俞" >`), so
# that quote belongs to the text and needs its backslash.
_B5C = set()
for _lead in range(0x81, 0xff):
    try:
        _B5C.add(bytes([_lead, 0x5c]).decode("cp950"))
    except UnicodeDecodeError:
        pass
_B5C |= set("殁泪许厩铀盖谷阅缕摆髅蹑")
for _lead in range(0x81, 0xff):
    try:
        _B5C.add(bytes([_lead, 0x5c]).decode("gbk"))
    except UnicodeDecodeError:
        pass
_B5C_STRAY = re.compile("[%s]\\\\" % re.escape("".join(sorted(_B5C))))
_B5C_QUOTE = re.compile("[%s]\"" % re.escape("".join(sorted(_B5C))))


def drop_big5_strays(text):
    """(repaired text, count) or (None, count): at the first such character after where the save breaks, drop the
    stray backslash or escape the quote, until it parses."""
    n = 0
    while n <= 500:
        d = fail_pos(text)
        if d is None:
            return text, n
        m, q = _B5C_STRAY.search(text, d), _B5C_QUOTE.search(text, d)
        if m and (not q or m.start() <= q.start()):
            text = text[:m.start() + 1] + text[m.end():]
        elif q:
            text = text[:q.start() + 1] + "\\" + text[q.start() + 1:]
        else:
            return None, n
        n += 1
    return None, n


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
            try:   # Windows text: 0x80-0x9f are quotes and dashes (0x92 is the apostrophe), never Latin-1's C1 controls
                out.append((raw.decode("cp1252"), "cp1252" + tag, 1.0))
            except UnicodeDecodeError:
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


def iconv_c(b, enc):
    return subprocess.run(["iconv", "-f", enc, "-t", "utf-8", "-c"], input=b, capture_output=True).stdout


def raw_counterpart(slug, rel):
    """libs/SLUG/raw/[DIR/[DIR/]]REL: the archive's own copy of a work/ file."""
    base = os.path.join(REPO, "libs", slug, "raw")
    for pre in ("", "*/", "*/*/"):
        hits = glob.glob(glob.escape(base) + "/" + pre + glob.escape(rel))
        if len(hits) == 1:
            return hits[0]
    return None


def from_raw(f, b):
    """(text, label) for a broken transcoded save, or (None, reason)."""
    slug, rel = f.split("/", 3)[1], f.split("/", 3)[3]
    r = raw_counterpart(slug, rel)
    why = "no raw/ original"
    if r:
        rb = open(r, "rb").read()
        why = "edited since onboarding (iconv of raw/ differs)"
        if any(iconv_c(rb, enc) == b for enc in ("gb18030", "big5", "cp950", "big5-hkscs")):
            why = "the raw/ original does not parse either"
            for text, how in candidates(rb, lib_profile(slug)):
                text, k = lf_to_cr(text)
                if parses(text):
                    return text, "raw " + how + (" +%d newline(s) as \\r" % k if k else "")
    # newlines and backslashes only: safe on a save edited since onboarding, and on one converted elsewhere
    text, k = lf_to_cr(b.decode("utf-8"))
    if parses(text):
        return text, "%d raw newline(s) inside strings written as \\r" % k
    text, n = drop_big5_strays(text)
    if text is not None:
        return text, "%d backslash(es) dropped or added after a 0x5C character" % n + (", %d newline(s) as \\r" % k if k else "")
    return None, why


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    apply = "--apply" in sys.argv
    raw_mode = "--from-raw" in sys.argv
    pat = (["libs/*/work/*.o"] if "--all" in sys.argv else
           [a if "/" in a else "libs/%s/work/*.o" % a for a in args])
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
            t = b.decode("utf-8")
            if not raw_mode or not b.startswith(b"#/") or parses(t):
                continue
            rel = p[len(REPO) + 1:]
            text, how = from_raw(rel, b)
            if text is None:
                print("LEFT %s: %s" % (rel, how))
                left += 1
                continue
            print("FIX  %s (%s)" % (rel, how))
            done += 1
            if apply:
                open(p, "wb").write(text.encode("utf-8"))
            continue
        except UnicodeDecodeError:
            if raw_mode:
                continue
        pick = None
        slug = f.decode("utf-8", "surrogateescape").split("/")[1]
        for text, how in candidates(b, lib_profile(slug)):
            text, k = lf_to_cr(text)
            if parses(text):
                pick = (text, how + (" +%d newline(s) as \\r" % k if k else ""))
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


if __name__ == "__main__":
    main()
