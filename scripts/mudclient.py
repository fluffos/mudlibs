#!/usr/bin/env python3
"""Minimal scriptable telnet client for smoke-testing a booted mudlib.

Handles just enough Telnet IAC negotiation to stay usable against old
MudOS/FluffOS-era servers (refuses/ignores option negotiation instead of
implementing it), sends a scripted list of lines with waits in between, and
streams everything received (decoded permissively) so it can be grepped for
a login prompt / room description / error text.

By default each outgoing line is echoed into the transcript with a wall-clock
timestamp and elapsed-since-connect, so you can see which --send produced
which reply:

  [19:51:03.201 +  1.12s] >>> SEND look

Use --no-echo for a game-text-only transcript (old behavior, no markers).

Usage:
  mudclient.py HOST PORT [--send LINE ...] [--timeout SEC] [--idle SEC]

Example:
  scripts/mudclient.py localhost 40001 --timeout 8 --idle 1.5

  scripts/mudclient.py localhost 40001 --timeout 15 \\
      --send "" --send "look" --send "quit"
"""
import argparse
import codecs
import datetime
import socket
import sys
import time

IAC = 255
DONT = 254
DO = 253
WONT = 252
WILL = 251
SB = 250
SE = 240


def negotiate_strip(buf: bytes, sock: socket.socket) -> bytes:
    """Strip IAC sequences from buf, replying WONT/DONT to any WILL/DO."""
    out = bytearray()
    i = 0
    n = len(buf)
    while i < n:
        b = buf[i]
        if b != IAC:
            out.append(b)
            i += 1
            continue
        if i + 1 >= n:
            break  # incomplete, drop (rare at chunk boundary)
        cmd = buf[i + 1]
        if cmd in (WILL, WONT, DO, DONT):
            if i + 2 >= n:
                break
            opt = buf[i + 2]
            if cmd in (WILL, DO):
                reply = bytes([IAC, DONT if cmd == WILL else WONT, opt])
                try:
                    sock.sendall(reply)
                except OSError:
                    pass
            i += 3
        elif cmd == SB:
            j = i + 2
            while j + 1 < n and not (buf[j] == IAC and buf[j + 1] == SE):
                j += 1
            i = j + 2
        elif cmd == IAC:
            out.append(IAC)
            i += 2
        else:
            i += 2
    return bytes(out)


def format_stamp(t0: float, now: float | None = None) -> str:
    """Wall-clock HH:MM:SS.mmm plus elapsed seconds since connect."""
    if now is None:
        now = time.time()
    wall = datetime.datetime.fromtimestamp(now).strftime("%H:%M:%S")
    msec = int((now % 1) * 1000)
    return f"{wall}.{msec:03d} +{now - t0:6.2f}s"


def emit_marker(kind: str, detail: str, t0: float, enabled: bool) -> None:
    if not enabled:
        return
    sys.stdout.write(f"[{format_stamp(t0)}] >>> {kind} {detail}\n")
    sys.stdout.flush()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("host")
    ap.add_argument("port", type=int)
    ap.add_argument("--send", action="append", default=None,
                     help="a line to send (repeatable, in order); '' sends a bare newline")
    ap.add_argument("--timeout", type=float, default=10.0,
                     help="hard cap on total session time")
    ap.add_argument("--idle", type=float, default=1.0,
                     help="seconds of silence before sending the next --send line")
    ap.add_argument("--connect-timeout", type=float, default=5.0)
    ap.add_argument("--no-echo", action="store_true",
                     help="omit timestamped SEND/CONNECT/CLOSE markers (game text only)")
    args = ap.parse_args()

    sends = args.send if args.send is not None else ["", "look", "quit"]
    echo = not args.no_echo

    try:
        sock = socket.create_connection((args.host, args.port), timeout=args.connect_timeout)
    except OSError as e:
        print(f"CONNECT_FAILED: {e}", file=sys.stderr)
        sys.exit(2)

    sock.settimeout(0.3)
    t0 = time.time()
    last_recv = t0
    send_idx = 0
    decoder = codecs.getincrementaldecoder("utf-8")("replace")
    got_any = False
    emit_marker("CONNECT", f"{args.host}:{args.port}", t0, echo)

    def write_recv(data: bytes, final: bool = False) -> None:
        nonlocal got_any
        if not data and not final:
            return
        text = decoder.decode(data, final)
        if text:
            got_any = True
            sys.stdout.write(text)
            sys.stdout.flush()

    while time.time() - t0 < args.timeout:
        try:
            chunk = sock.recv(4096)
            if not chunk:
                emit_marker("CLOSE", "peer hung up", t0, echo)
                break
            write_recv(negotiate_strip(chunk, sock))
            last_recv = time.time()
        except socket.timeout:
            pass
        except OSError:
            emit_marker("CLOSE", "socket error", t0, echo)
            break

        if send_idx < len(sends) and time.time() - last_recv >= args.idle:
            line = sends[send_idx]
            shown = '""' if line == "" else line
            emit_marker("SEND", shown, t0, echo)
            try:
                sock.sendall(line.encode("utf-8", "replace") + b"\r\n")
            except OSError:
                emit_marker("CLOSE", "send failed", t0, echo)
                break
            send_idx += 1
            last_recv = time.time()  # reset idle clock after sending
        elif send_idx >= len(sends) and time.time() - last_recv >= args.idle:
            emit_marker("CLOSE", "idle after last send", t0, echo)
            break  # nothing left to send and it's gone quiet
    else:
        emit_marker("CLOSE", "timeout", t0, echo)

    write_recv(b"", final=True)
    try:
        sock.close()
    except OSError:
        pass

    if not got_any:
        print("NOTE: empty transcript (server sent nothing / connection refused mid-way)",
              file=sys.stderr)


if __name__ == "__main__":
    main()
