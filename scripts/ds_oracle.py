#!/usr/bin/env python3
"""Golden-master oracle for the Dead Souls family libs (dsI, dsII, dsIII, ds386, dshakkard, ...).

Boot a throwaway tree (scripts/pristine_tree.sh + the changes under test), run this against
it, and diff the output of a HEAD tree against the working-tree tree:

  scripts/pristine_tree.sh dsII 40228 /tmp/oracle-head ; start the driver ; \\
  python3 scripts/ds_oracle.py /tmp/oracle-head/libs/dsII/work 40228 fluffos PASSWORD head.txt --lib
  ... same for the tree with your edits -> new.txt ... diff -u head.txt new.txt

Each OBJ block lists, per probed program: the file defining the final version of every
function, every global variable with its type modifiers, a battery of getters and a few
dynamic behaviours (see scripts/ds_oracle.lpc).  Clone numbers (#123) are normalised away.

usage: ds_oracle.py WORKDIR PORT ADMIN PASSWORD OUT [--lib] [--paths FILE] [PATH ...] [--no-player]
  --lib        probe every lib/**.lpc of the tree (loadable ones; load errors are recorded)
  --paths F    one object path per line ("/domains/town/obj/pack")
  PATH         explicit object paths
The admin account must exist and be a creator (dsI: fluffos/fluffwiz123, dsII: fluffos/fluffwiz123,
dsIII: fluffos/Mud@2026 in the pristine trees).
"""
import os
import re
import select
import shutil
import socket
import sys
import time

IAC, DONT, DO, WONT, WILL, SB, SE = 255, 254, 253, 252, 251, 250, 240
HERE = os.path.dirname(os.path.abspath(__file__))


class Conn:
    def __init__(self, port):
        self.s = socket.create_connection(("localhost", port), timeout=10)
        self.buf = ""

    def _read(self, wait):
        r, _, _ = select.select([self.s], [], [], wait)
        if not r:
            return ""
        data = self.s.recv(65536)
        if not data:
            raise EOFError("connection closed")
        out, i = bytearray(), 0
        while i < len(data):
            b = data[i]
            if b == IAC and i + 1 < len(data):
                c = data[i + 1]
                if c in (DO, DONT, WILL, WONT) and i + 2 < len(data):
                    opt = data[i + 2]
                    if c == DO:
                        self.s.sendall(bytes([IAC, WONT, opt]))
                    elif c == WILL:
                        self.s.sendall(bytes([IAC, DONT, opt]))
                    i += 3
                    continue
                if c == SB:
                    j = data.find(bytes([IAC, SE]), i)
                    i = j + 2 if j >= 0 else len(data)
                    continue
                i += 2
                continue
            out.append(b)
            i += 1
        return out.decode("utf-8", "replace")

    def expect(self, pattern, timeout=30):
        end = time.time() + timeout
        rx = re.compile(pattern, re.S)
        while time.time() < end:
            m = rx.search(self.buf)
            if m:
                got = self.buf[: m.end()]
                self.buf = self.buf[m.end():]
                return got
            self.buf += self._read(0.5)
        raise TimeoutError(f"timeout waiting for {pattern!r}; tail: {self.buf[-400:]!r}")

    def send(self, line):
        self.s.sendall(line.encode("utf-8") + b"\r\n")


def login(c, name, pw):
    c.expect(r"(?i)(what name|enter your name|name\?|your name)")
    c.send(name)
    c.expect(r"(?i)password")
    c.send(pw)
    c.send("")
    # A "Press <return> to continue" pager (the news screens) swallows whatever is typed at it,
    # so offer the marker again after every page until the command prompt answers it.
    for _ in range(40):
        c.send('eval return "ZZSTART"')
        try:
            out = c.expect(r"Result = \"?ZZSTART\"?|(?i:press <?return>?)", timeout=8)
        except TimeoutError:
            c.send("")
            continue
        if "ZZSTART" in out:
            return
        c.send("")
    raise TimeoutError("login never reached a command prompt")


def run(c, expr, timeout=120):
    c.send("eval " + expr)
    c.send('eval return "ZZEND"')
    out = c.expect(r"Result = \"?ZZEND\"?", timeout=timeout)
    return re.sub(r"\x1b\[[0-9;]*[A-Za-z]", "", out).replace("\r", "")


def lib_paths(work):
    out = []
    for dp, dn, fn in os.walk(os.path.join(work, "lib")):
        for f in sorted(fn):
            if f.endswith(".lpc"):
                rel = os.path.relpath(os.path.join(dp, f), work)
                out.append("/" + rel[:-4])
    return sorted(out)


def main():
    argv = sys.argv[1:]
    if len(argv) < 5:
        sys.exit(__doc__)
    work, port, admin, pw, outfile = argv[0], int(argv[1]), argv[2], argv[3], argv[4]
    rest = argv[5:]
    paths = []
    if "--lib" in rest:
        paths += lib_paths(work)
    if "--paths" in rest:
        with open(rest[rest.index("--paths") + 1]) as fh:
            paths += [l.strip() for l in fh if l.strip() and not l.startswith("#")]
    paths += [a for i, a in enumerate(rest) if a.startswith("/") and (i == 0 or rest[i - 1] != "--paths")]
    seen = set()
    paths = [p for p in paths if not (p in seen or seen.add(p))]

    realm = os.path.join(work, "realms", admin)
    os.makedirs(realm, exist_ok=True)
    shutil.copyfile(os.path.join(HERE, "ds_oracle.lpc"), os.path.join(realm, "oracle.lpc"))
    out_on_disk = os.path.join(realm, "oracle.out")
    if os.path.exists(out_on_disk):
        os.remove(out_on_disk)
    # the probe's output path is fixed to /realms/fluffos; patch it for another admin name
    src = open(os.path.join(realm, "oracle.lpc")).read().replace("/realms/fluffos/", f"/realms/{admin}/")
    open(os.path.join(realm, "oracle.lpc"), "w").write(src)

    c = Conn(port)
    login(c, admin, pw)
    target = f'load_object("/realms/{admin}/oracle")'
    r = run(c, f'object o = {target}; return o ? "loaded" : "no"')
    if "loaded" not in r:
        sys.exit("oracle.lpc did not load:\n" + r[-800:])
    t0 = time.time()
    if "--no-player" not in rest:
        r = run(c, f"return {target}->probe_player()")
    for i, p in enumerate(paths, 1):
        try:
            r = run(c, f'return {target}->probe("{p}")', timeout=180)
        except TimeoutError as e:
            print(f"!! timeout on {p}: {str(e)[-200:]}")
            # recover: send a blank line and a marker, hope the driver survives
            c.buf = ""
            c.send("")
            continue
        if i % 25 == 0:
            print(f"   {i}/{len(paths)} probed ({time.time() - t0:.0f}s)")
    try:
        c.send("quit")
        time.sleep(0.5)
    except OSError:
        pass
    text = open(out_on_disk, errors="replace").read() if os.path.exists(out_on_disk) else ""
    text = re.sub(r"#\d+", "#N", text)
    with open(outfile, "w") as fh:
        fh.write(text)
    print(f"{len(paths)} objects probed -> {outfile} ({len(text.splitlines())} lines)")


if __name__ == "__main__":
    main()
