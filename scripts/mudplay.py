#!/usr/bin/env python3
"""scripts/mudplay.py -- a small scriptable telnet session for deep play tests (KB 08 section 10.7, 10.16).

    from mudplay import Mud, Console
    m = Mud("localhost", 45993)            # transcript goes to $LPC_SCRATCH/play/<port>.log unless log=None
    text = m.read()                        # everything until the line is quiet (idle=0.6 s) or maxwait
    text = m.cmd("look")                   # send one line, read the answer
    text = m.expect(r"name:", 15)          # read until the regex matches (raises Timeout)
    con = Console("/path/to/driver.out")   # follow the driver's stdout/log file
    new = con.new()                        # the lines the driver printed since the last call

The telnet layer answers every option the server offers with WONT/DONT (so no echo or GMCP surprises), strips IAC sequences, and decodes UTF-8
with a GB18030 fallback (the Chinese libs are UTF-8 now, but a stray byte must not abort a session).  `Mud.cmd` never raises on a quiet server: it
returns what arrived, possibly "" -- the caller validates each response before sending the next input (AGENTS.md 13.4).
"""
import os
import re
import socket
import sys
import time

IAC, DONT, DO, WONT, WILL, SB, SE = 255, 254, 253, 252, 251, 250, 240
SCR = os.environ.get("LPC_SCRATCH") or os.path.expanduser("~/.cache/lpc-scratch")
ANSI = re.compile(r"\x1b\[[0-9;]*[A-Za-z]")


class Timeout(Exception):
    pass


class Mud:
    def __init__(self, host="localhost", port=0, log=True, connect_timeout=10, strip_ansi=True):
        self.host, self.port = host, port
        self.strip_ansi = strip_ansi
        self.sock = socket.create_connection((host, port), timeout=connect_timeout)
        self.sock.setblocking(False)
        self.raw = b""
        self.t0 = time.time()
        self.logf = None
        if log:
            d = os.path.join(SCR, "play")
            os.makedirs(d, exist_ok=True)
            self.logf = open(os.path.join(d, f"{port}.log"), "a", encoding="utf-8", errors="replace")
            self.logf.write(f"\n##### session {time.strftime('%Y-%m-%d %H:%M:%S')} #####\n")

    # ---- low level -------------------------------------------------------------------------------------------------
    def _pump(self):
        """move what the socket has into self.raw (IAC handled); returns the number of new text bytes"""
        got = 0
        while True:
            try:
                d = self.sock.recv(65536)
            except BlockingIOError:
                break
            except OSError:
                break
            if not d:
                self.closed = True
                break
            got += self._strip(d)
        return got

    closed = False
    _pending = b""

    def _strip(self, d):
        d = self._pending + d
        self._pending = b""
        out = bytearray()
        i, n = 0, len(d)
        while i < n:
            b = d[i]
            if b != IAC:
                out.append(b)
                i += 1
                continue
            if i + 1 >= n:
                self._pending = d[i:]
                break
            c = d[i + 1]
            if c in (WILL, WONT, DO, DONT):
                if i + 2 >= n:
                    self._pending = d[i:]
                    break
                opt = d[i + 2]
                try:
                    if c == WILL:
                        self.sock.send(bytes([IAC, DONT, opt]))
                    elif c == DO:
                        self.sock.send(bytes([IAC, WONT, opt]))
                except OSError:
                    pass
                i += 3
            elif c == SB:
                j = d.find(bytes([IAC, SE]), i + 2)
                if j < 0:
                    self._pending = d[i:]
                    break
                i = j + 2
            elif c == IAC:
                out.append(255)
                i += 2
            else:
                i += 2
        self.raw += bytes(out)
        return len(out)

    def _decode(self, b):
        try:
            s = b.decode("utf-8")
        except UnicodeDecodeError:
            try:
                s = b.decode("gb18030")
            except UnicodeDecodeError:
                s = b.decode("utf-8", "replace")
        s = s.replace("\r\n", "\n").replace("\r", "\n")
        return ANSI.sub("", s) if self.strip_ansi else s

    # ---- API -------------------------------------------------------------------------------------------------------
    def read(self, idle=0.6, maxwait=6.0):
        """read until the connection has been quiet for `idle` seconds (or `maxwait` in all); returns the decoded text"""
        t_start = last = time.time()
        while True:
            if self._pump():
                last = time.time()
            now = time.time()
            if self.closed or now - last >= idle or now - t_start >= maxwait:
                break
            time.sleep(0.03)
        b, self.raw = self.raw, b""
        s = self._decode(b)
        if self.logf and s:
            self.logf.write(s if s.endswith("\n") else s + "\n")
            self.logf.flush()
        return s

    def send(self, line):
        if self.logf:
            self.logf.write(f"[{time.time() - self.t0:7.1f}s] >>> {line}\n")
        data = (line.encode("utf-8") + b"\r\n")
        self.sock.setblocking(True)
        try:
            self.sock.sendall(data)
        finally:
            self.sock.setblocking(False)

    def cmd(self, line, idle=0.6, maxwait=6.0):
        self.send(line)
        return self.read(idle, maxwait)

    def expect(self, pattern, timeout=15.0, idle=0.25):
        """accumulate output until `pattern` (regex) matches; returns everything read"""
        rx = re.compile(pattern)
        buf = ""
        t_end = time.time() + timeout
        while time.time() < t_end:
            buf += self.read(idle=idle, maxwait=min(1.0, max(0.1, t_end - time.time())))
            if rx.search(buf):
                return buf
            if self.closed:
                break
        raise Timeout(f"{pattern!r} not seen in {timeout}s; got: {buf[-300:]!r}")

    def close(self):
        try:
            self.sock.close()
        except OSError:
            pass
        if self.logf:
            self.logf.close()


class Console:
    """follow a growing file (the driver's stdout, a mudlib log): new() returns the complete lines added since the last call"""

    def __init__(self, path):
        self.path = path
        self.pos = 0
        try:
            self.pos = os.path.getsize(path)
        except OSError:
            pass
        self._part = ""

    def new(self):
        try:
            with open(self.path, "rb") as fh:
                fh.seek(self.pos)
                d = fh.read()
                self.pos = fh.tell()
        except OSError:
            return []
        s = self._part + d.decode("utf-8", "replace")
        lines = s.split("\n")
        self._part = lines.pop()
        return lines


if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    m = Mud(sys.argv[1], int(sys.argv[2]))
    print(m.read(1.5, 8))
    for ln in sys.argv[3:]:
        print(">>>", ln)
        print(m.cmd(ln))
    m.close()
