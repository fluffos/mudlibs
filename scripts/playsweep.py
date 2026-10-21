#!/usr/bin/env python3
"""scripts/playsweep.py -- run every verb of a lib with several argument shapes and report what the driver console and the player's screen say (KB 08 10.16).

    from mudplay import Mud, Console
    from playsweep import Sweep
    sw = Sweep(m, con, prompt_probe="look", prompt_rx=r"exit|Exit|出口", relogin=my_relogin)
    sw.run(verbs, shapes=SHAPES, skip={"quit", "shutdown"})
    sw.report()

For each `verb shape` line it sends the line, reads the answer, takes the driver console lines added meanwhile (a run-time error, a `Warning:`, a stack
trace, `insufficient permission`) and the answer's own error text, and records the pair when either looks wrong.  After every line it checks the session is
still in the normal command loop (the probe command, default `look`, must answer with something that matches prompt_rx): a verb that opens a prompt
(an editor, a password dialog, a mail mode) is closed with a list of escape lines (`~q`, `q`, `.`, `**`, empty lines) and the session is reopened by
`relogin()` (it returns the new Mud) when that does not help or the connection was closed (a crash or a kick is itself a finding).  "Answers like the normal command
loop" is: the probe's answer holds one of the two longest lines of the first probe's answer (the room description, letters and Chinese characters only), the baseline taken
before the first verb and again after every relogin.  A bare `matches anything` test passed a session that a verb had left at a lock-screen or password prompt, which answers
every line (xbtxiii `lockscreen`: the rest of the verb list, `practice`, `study`, `learn` ..., ran into the prompt and was never tested).  Nothing here knows a lib: the caller supplies
the verbs (from `add_action` calls, from the command directories, from the help index) and the login routine.
"""
import re
import time

SHAPES = ["", "me", "here", "1", "all", "a b c", "-h", "?", "你好 世界", "x" * 300]
SHAPES_X = SHAPES + ["%s%d%n", "-1", "0", "99999999999", "../..", "\"q\" 'q' \\", "*", "你好", "me 1", "all 你好"]    # the second round: format characters, numbers at the edges, path-like and quoted arguments
DRIVER_BAD = re.compile(r"(?i)(^\*|\berror\b|bad argument|too many|too few|warning:|illegal|insufficient permission|no such (function|object|file)|"
                        r"cannot|can't find|failed to|not allowed|runtime|trace|\*\*\*|expected|undefined|call_other|eval cost|too deep|out of memory|"
                        r"out of bounds|being indexed|执行时段错误|運行時|找不到|couldn't find)")
SCREEN_BAD = re.compile(r"(?i)(error in|runtime error|bad argument|\*\*\* |trace[:=]|line \d+: |call_other|object ?\d+ ?\(|0x[0-9a-f]{6,}|"
                        r"Failed to load|Too long evaluation|Too deep recursion|无法载入|读取错误|执行时段错误|\bNULL\b|\(null\)|<unknown>)")
ESCAPES = ["~q", "q", ".", "**", "", "", "no", "n", "x", "end", "quit"]
SIGJUNK = re.compile(r"[^A-Za-z\u4e00-\u9fff]")


def signature(txt):
    """the letters and Chinese characters of the two longest lines of a probe answer (the room description): they survive a live clock, an arriving NPC, a changed exit list"""
    lines = sorted((SIGJUNK.sub("", ln) for ln in txt.splitlines()), key=len, reverse=True)
    return [s[:20] for s in lines[:2] if len(s) >= 8]


class Sweep:
    def __init__(self, m, con, prompt_probe="look", prompt_rx=r".", relogin=None, idle=0.35, maxwait=4.0, out=print, probe_idle=0.3):
        self.m, self.con = m, con
        self.probe, self.prx = prompt_probe, re.compile(prompt_rx)
        self.relogin = relogin
        self.idle, self.maxwait = idle, maxwait
        self.probe_idle = probe_idle      # a lib whose `look` arrives in several flushes needs a longer quiet gap
        self.out = out
        self.findings = []        # (kind, line, screen tail, console lines)
        self.n = 0
        self.sig = None           # signature() of the first probe answer; None = take it at the next probe (relogin, first verb); [] = nothing to compare with
        self.use_sig = True       # off for a lib that queues commands (Discworld's burst mode: the first answer to `look` is `Queued command`)

    def _record(self, kind, line, screen, cons):
        self.findings.append((kind, line, screen.strip()[-400:], cons[:12]))
        self.out(f"FINDING [{kind}] {line!r}: console={cons[:3]!r} screen={screen.strip()[-160:]!r}")

    def _alive(self):
        """True when the probe command is answered like the normal command loop"""
        txt = self.m.cmd(self.probe, idle=self.probe_idle, maxwait=max(3.0, 4 * self.probe_idle))
        ok = bool(self.prx.search(txt))
        if ok and self.use_sig:
            if self.sig is None:
                self.sig = signature(txt)
            elif self.sig and not any(s in SIGJUNK.sub("", txt) for s in self.sig):
                txt += self.m.read(0.6, 2.5)      # the room description may arrive in a second flush
                ok = any(s in SIGJUNK.sub("", txt) for s in self.sig)
        return ok, txt

    def _back_to_loop(self, line):
        """True when the session answers the probe like the normal command loop; closes prompts with the escape lines one by one (probing after each, so
        a stray `quit` is never sent once the loop is back); False when the connection is gone or nothing helps"""
        ok, txt = self._alive()
        if ok:
            return True
        self.m.read(1.0, 4.0)      # the verb's own answer may still be arriving (a long `news`, a slow `map`) and polluted the probe's
        ok, txt = self._alive()
        if ok:
            return True
        for e in ESCAPES:
            if self.m.closed:
                return False
            self.m.send(e)
            self.m.read(0.15, 1.0)
            ok, txt = self._alive()
            if ok:
                self._record("needed-escape", line + f"  [{e!r} closed it]", txt, [])
                return True
        return False

    def _rebaseline(self):
        self.sig = None
        if self.use_sig:
            self._alive()          # thrown away: the first `look` of a fresh character can carry a newbie guide, which is not in the second
            self.sig = None
            self._alive()

    def one(self, line):
        self.n += 1
        if self.n == 1:
            self._rebaseline()
        txt = self.m.cmd(line, idle=self.idle, maxwait=self.maxwait)
        cons = [c for c in self.con.new() if c.strip()]
        bad_cons = [c for c in cons if DRIVER_BAD.search(c)]
        if self.m.closed:
            self._record("connection-closed", line, txt, cons)
            if self.relogin:
                self.m = self.relogin()
                self._rebaseline()
            return txt, cons
        if bad_cons:
            self._record("console", line, txt, bad_cons)
        elif SCREEN_BAD.search(txt):
            self._record("screen", line, txt, cons)
        if not self._back_to_loop(line):
            self._record("stuck-reconnect", line, txt, cons)
            try:
                self.m.close()
            except Exception:
                pass
            if self.relogin:
                self.m = self.relogin()
                self._rebaseline()
        self.con.new()    # whatever the probe printed
        return txt, cons

    def run(self, verbs, shapes=SHAPES, skip=()):
        for v in verbs:
            if v in skip:
                continue
            for sh in shapes:
                self.one((v + " " + sh).strip())

    def report(self):
        by = {}
        for kind, line, scr, cons in self.findings:
            by.setdefault(kind, []).append((line, scr, cons))
        self.out(f"{self.n} lines sent, {len(self.findings)} findings: " + ", ".join(f"{k}={len(v)}" for k, v in sorted(by.items())))
        return by
