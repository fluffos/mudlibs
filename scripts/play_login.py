#!/usr/bin/env python3
"""scripts/play_login.py PORT [--name NAME] [--pw PW] [--cmds "look;score;i"] [--host 127.0.0.1] [--steps 45] [--quiet] [--verbose]

A generic login robot for a booted lib (scripts/play_boot.sh): it answers the prompts of a registration or a login with defaults chosen by regex on the
last text the server sent (name, password twice, e-mail, gender, y/n, "press return", the first entry of a numbered menu, race / class lists), until a probe
command (`look`) answers like a game; then it runs the commands of --cmds and `quit`.  The transcript goes to stdout (--quiet: only the verdict).  It is a
survey tool, not a test of the login: a lib with an unusual dialogue ends `STUCK` with the last prompt, and gets a hand-written login (KB 08 10.16).

Exit status 0 when a game prompt was reached, 1 when stuck, 2 when the server closed the connection or never answered.  The verdict line is
`RESULT <in|stuck|closed> steps=N last=<last prompt>`."""
import argparse
import os
import re
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mudplay import Mud, Timeout  # noqa: E402

# (regex on the tail of the text, reply).  Order matters: the first match wins.  "{name}" "{pw}" "{email}" are filled in.
RULES = [
    (r"(?i)(type|enter|input|输入|请输入)\s*[`'\"“]?new[`'\"”]?\b", "{newword}"),
    (r"(?i)throw (the )?other copy|already (logged|playing|connected)|reconnect|重复|另一个连线|取代|赶出去", "y"),
    (r"(?i)(re-?type|again|confirm|verify|repeat|once more).{0,40}(password|passwd|pass)|(password|passwd).{0,40}(again|confirm|verify)|再输入一次|再输一次|确认密码|重新输入密码", "{pw}"),
    (r"(?i)password|passwd|密码|口令", "{pw}"),
    (r"(?i)(e-?mail|email|电子邮件|邮箱|邮件地址)", "{email}"),
    (r"(?i)(gender|sex|male or female|\(m\)ale|\bmale\b.*\bfemale\b|男.*女|性别|扮演男性)", "{gender}"),
    (r"(?i)(real ?name|your name in real|真实姓名)", "Test User"),
    (r"(?i)(chinese name|中文名字|中文姓名|您的中文名)", "测试员"),
    (r"(?i)(同意|接受|满意|agree|accept|satisfied)[^\n]{0,30}[?？:：]\s*$", "y"),
    (r"(?i)(do you want|would you like|are you sure|create (a )?(new )?(character|player)|new (character|player)\?|确定吗|\(y/n\)|\[y/n\]|\(yes/no\)|yes or no|y\(es\) or n\(o\)|y or n|y/n)", "y"),
    (r"(?i)(press|hit)\s+(\[?enter\]?|\[?return\]?|any key)|\[more\]|--more--|continue\s*[:\.]?\s*$|按.{0,6}(回车|键)|任意键|<return>|\(return\)", ""),
    (r"(?i)(terminal|term type|screen|colou?r|ansi|vt100|client)\b.{0,50}[:?]\s*$", "{term}"),
    (r"(?i)(race|species)\b.{0,60}[:?]\s*$", "{first_of_race}"),
    (r"(?i)(class|profession|guild|vocation)\b.{0,60}[:?]\s*$", "{first_of_class}"),
    (r"(?i)(enter|type|give|choose|select|input).{0,30}(number|choice|option)|^\s*\[?1\]?[\.\)]\s", "1"),
    (r"\((\d+)\s*(?:到|to|-|~|至)\s*(\d+)\)", "{range_mid}"),
    (r"(?i)(请选择|请输入.{0,10}(数字|号码|编号)|choose|select|pick).{0,60}[:：?？\)]\s*$", "1"),
    (r"(?i)(what is|enter|give|type|input|tell me).{0,40}(your )?(character )?(name|id|handle)|(by )?what (is your |do you wish )?name|name do you|known\s*\?|login\s*:|name\s*:|name\?|名字|ID\s*[:：]|帐号|账号|new\)", "{name}"),
]
MENU_DONE = re.compile(r"(?i)(?:^|\s)\[?(\d+)\]?\s*[-.):]\s*(?:done|finish|finished|accept|continue|save|完成|结束|确定)\b")
GAME = re.compile(r"(?i)(exit|obvious|you are|you see|north|south|east|west|here|room|出口|这里|你|inventory|hp|health)")
NOT_GAME = re.compile(r"(?i)(password|passwd|name\s*:|login|密码|\(y/n\)|e-?mail|gender|press|return)")


def tail(buf, n=500):
    return buf[-n:]


def first_option(text, kind):
    """a race / class prompt usually lists the choices: pick the first plausible word of the list that follows the keyword"""
    m = re.search(r"(?i)(?:" + kind + r")[^\n]{0,80}[:\n]\s*([A-Za-z][A-Za-z_-]{2,})", text)
    if m:
        return m.group(1)
    m = re.search(r"(?m)^\s*(?:\[?1\]?[\.\)]\s*)?([A-Za-z][A-Za-z_-]{2,})\s*$", text)
    return m.group(1) if m else "1"


def match_rule(low, question):
    """(rule index, reply template) for the tail of the text; the "press return" rules apply to any screen, the others only to a question"""
    for i, (rx, rep) in enumerate(RULES):
        if re.search(rx, low) and (question or i == PRESS):
            return i, rep
    return None, None


PRESS = next(i for i, (rx, _) in enumerate(RULES) if "press" in rx)


def run(args):
    t0 = time.time()
    out = (lambda *a: None) if args.quiet else print
    try:
        m = Mud(args.host, args.port, log=False)
    except OSError as e:
        print(f"RESULT closed steps=0 last=connect failed: {e}")
        return 2
    buf = m.read(2.0, 15)
    out("<<< " + buf.replace("\n", "\n<<< ")[-600:])
    last_prompt = tail(buf, 120)
    steps = 0
    mapping = {"name": args.name, "pw": args.pw, "email": args.email, "gender": args.gender, "term": args.term}
    used = {}
    relaxed_done = {}
    empties = 0
    relaxed = False
    while steps < args.steps:
        if m.closed:
            print(f"RESULT closed steps={steps} last={last_prompt!r}")
            return 2
        low = tail(buf, 400)
        last = low.rstrip().split("\n")[-1] if low.strip() else ""
        question = bool(re.search(r"([:：?？\)\]])\s*$", last)) or relaxed       # a prompt ends in a colon, a question mark, `(again)`, `[y/n]`
        rule_id, reply = None, None
        md = MENU_DONE.search(low)
        if md and re.search(r"(?i)(choice|option|select|choose|pick|command)[^\n]*[:?]\s*$", last):       # a character-creation menu: its "Done" entry ends it
            rule_id, reply = len(RULES), md.group(1)
        if reply is None:
            rule_id, reply = match_rule(last, question) if last else (None, None)        # the prompt itself first, then its paragraph, then the text above
        if reply is None:
            rule_id, reply = match_rule(low.rstrip().split("\n\n")[-1], question)
        if reply is None:
            rule_id, reply = match_rule(low, question)
        if reply is not None:
            reply = reply.replace("{first_of_race}", first_option(low, "race|species")).replace("{first_of_class}", first_option(low, "class|profession|guild|vocation"))
            for k, v in mapping.items():
                reply = reply.replace("{" + k + "}", v)
            reply = reply.replace("{newword}", "new")
            if "{range_mid}" in reply:
                mr = re.search(r"\((\d+)\s*(?:到|to|-|~|至)\s*(\d+)\)", low)
                reply = str((int(mr.group(1)) + int(mr.group(2))) // 2) if mr else "20"
            used[rule_id] = used.get(rule_id, 0) + 1
            if used[rule_id] > (6 if rule_id in (2, 3) else 4) or (rule_id == 0 and used[rule_id] > 1):     # a loop means a wrong guess
                reply = None
        relaxed = False
        if reply is None and question and not relaxed_done.get(last):
            relaxed_done[last] = 1
            reply = "y" if re.search(r"[?？]\s*$", last) else "1"           # an unknown question: yes, or the first entry
        if reply is None:
            probe = m.cmd("look", idle=0.8, maxwait=6)
            out(">>> look\n<<< " + probe.strip().replace("\n", "\n<<< ")[-300:])
            same = probe.strip()[-160:] == buf.strip()[-160:]          # a menu or a question redisplays itself when `look` is typed at it
            if len(probe.strip()) > 20 and not same and GAME.search(probe) and not NOT_GAME.search(tail(probe, 200)):
                nonsense = m.cmd("zzqxk", idle=0.8, maxwait=5)              # a game answers an unknown verb in a line; a menu or a dialogue shows itself again
                out(">>> zzqxk\n<<< " + nonsense.strip().replace("\n", "\n<<< ")[-200:])
                if len(nonsense.strip()) < 200 and not re.search(r"\d\s*[\.\)〗]|选择|choose|select|请输入|please", nonsense, re.I):
                    buf = probe
                    break
            empties += 1
            if empties > 4:
                print(f"RESULT stuck steps={steps} last={last_prompt!r}")
                return 1
            relaxed = True                  # the prompt may have no colon: let the rules look at the text anyway
            buf = probe if probe.strip() else m.cmd("", idle=0.8, maxwait=5)
            if buf.strip():
                last_prompt = tail(buf, 120)
            steps += 1
            continue
        out(f">>> {reply!r}")
        buf = m.cmd(reply, idle=0.9, maxwait=10)
        out("<<< " + buf.strip().replace("\n", "\n<<< ")[-400:])
        if buf.strip():
            last_prompt = tail(buf, 120)
        steps += 1
    else:
        print(f"RESULT stuck steps={steps} last={last_prompt!r}")
        return 1
    for c in [x.strip() for x in args.cmds.split(";") if x.strip()]:
        t = m.cmd(c, idle=0.9, maxwait=8)
        out(f">>> {c}\n<<< " + t.strip().replace("\n", "\n<<< ")[-300:])
    m.cmd("quit", idle=0.8, maxwait=4)
    print(f"RESULT in steps={steps} last={last_prompt!r} seconds={time.time() - t0:.0f}")
    return 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("port", type=int)
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--name", default="sweepzq")
    ap.add_argument("--pw", default="Test1234x")
    ap.add_argument("--email", default="a@b.cn")
    ap.add_argument("--gender", default="m")
    ap.add_argument("--term", default="ansi")
    ap.add_argument("--cmds", default="look;score;i;who;help")
    ap.add_argument("--steps", type=int, default=45)
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--verbose", action="store_true")
    sys.exit(run(ap.parse_args()))


if __name__ == "__main__":
    main()
