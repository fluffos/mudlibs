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
    (r"(?i)(type|enter|input|输入|请输入|请键入|键入)\s*[`'\"“]?new[`'\"”]?\b", "{newword}"),
    (r"(?i)throw (the )?other copy|already (logged|playing|connected)|reconnect|重复|另一个连线|取代|赶出去", "y"),
    (r"(?i)(re-?type|again|confirm|verify|repeat|once more).{0,40}(password|passwd|pass)|(password|passwd).{0,40}(again|confirm|verify)|再输入一次|再输一次|确认密码|重新输入密码|(^|\n)\s*again\s*:\s*$", "{pw}"),
    (r"(?i)password|passwd|密码|口令", "{pw}"),
    (r"(?i)(e-?mail|email|电子邮件|邮箱|邮件地址)", "{email}"),
    (r"(?im)^[^\n]*(gbk|big5)[^\n]*utf-?8[^\n]*[:：]\s*$|^[^\n]*utf-?8[^\n]*(gbk|big5)[^\n]*[:：]\s*$", "utf-8"),            # the xkx family's encoding menu: "Select 国标码 GBK or 国际码 utf-8 (GBK/utf-8):"
    (r"(?i)\(gb/big5\)|\(big5/gb\)|\(gbk?/big5\)", "gb"),                    # the older xkx family menu: "Select 国标码 GB or 大五码 BIG5 (gb/big5):"
    (r"(?i)(gender|sex|male or female|\(m\)ale|\bmale\b.*\bfemale\b|男.*女|性别|扮演男性)", "{gender}"),
    (r"(?i)(real ?name|your name in real|真实姓名)", "Test User"),
    (r"中文姓氏|您的姓氏|请输入.{0,6}姓[：:]?\s*$", "测"),                       # nitan: "您的中文姓氏(不要超过两个汉字)：" and then the given name
    (r"(?i)(chinese name|中文名字|中文姓名|您的中文名)", "测试员"),
    (r"(?i)(中小学|小学生|学生或|未成年|under ?age|or younger)[^\n]{0,30}(\(yes/no\)|\(y/n\)|[?？])\s*$", "no"),          # mhsj, sjcs ...: "您是否是中小学学生或年龄更小？(yes/no)": not a pupil
    (r"(?i)(同意|接受|满意|agree|accept|satisfied)[^\n]{0,30}[?？:：]\s*$", "y"),
    (r"(?i)(do you want|would you like|are you sure|create (a )?(new )?(character|player)|new (character|player)\?|确定吗|\(y/n\)|\[y/n\]|\(yes/no\)|yes or no|'yes' or 'no'|y\(es\) or n\(o\)|y or n|y/n)", "y"),
    (r"(?i)\(s/n\)|\[s/n\]", "s"),                                    # Spanish: "No entiendo... (s/n)"
    (r"(?i)(press|hit)\s+(\[?enter\]?|\[?return\]?|any key)|\[more\]|--more--|continue\s*[:\.]?\s*$|按.{0,6}(回车|键)|任意键|<return>|\(return\)", ""),
    (r"(?i)(terminal|term type|screen|colou?r|ansi|vt100|client)\b.{0,50}[:?]\s*$", "{term}"),
    (r"你的选择[:：]\s*$|选择.{0,10}(种族|职业|门派)[^\n]{0,20}[:：]\s*$", "{first_of_list}"),            # a list of `name(name)  5 点业力` lines
    (r"(?i)(race|species)\b.{0,60}[:?]\s*$", "{first_of_race}"),
    (r"(?i)(class|profession|guild|vocation)\b.{0,60}[:?]\s*$", "{first_of_class}"),
    (r"(?i)(enter|type|give|choose|select|input).{0,30}(number|choice|option)|^\s*\[?1\]?[\.\)]\s", "1"),
    (r"(?i)(?:合法值是?|valid(?: values?)?(?: is| are)?|between|range)\s*(\d+)\s*(?:到|to|-|~|至|and)\s*(\d+)", "{range_mid}"),      # "合法值是 10-30"
    (r"\((\d+)\s*(?:到|to|-|~|至)\s*(\d+)\)", "{range_mid}"),
    (r"(?i)(请选择|请输入.{0,10}(数字|号码|编号)|choose|select|pick).{0,60}[:：?？\)]\s*$", "1"),
    (r"(?i)(what is|enter|give|type|input|tell me).{0,40}(your )?(character )?(name|id|handle)|(by )?what (is your |do you wish )?name|name do you|known\s*\?|login\s*:|name\s*:|name\?|名字|ID\s*[:：]|帐号|账号|new\)", "{name}"),
]
RACE_PICK = re.compile(r"(?is)valid races?:\s*([A-Za-z][\w-]*)")
NEW_CHAR = re.compile(r"(?im)^\s*N\s*-\s*New character")
MENU_DONE = re.compile(r"(?i)(?:^|\s)\[?(\d+)\]?\s*[-.):]\s*(?:done|finish|finished|accept|continue|save|完成|结束|确定)\b")
PATIENCE = re.compile(r"(?i)(may|will) pause|please wait|wait \d+ seconds|请稍候|请等待|一会儿")
GAME = re.compile(r"(?i)(exit|obvious|you are|you see|north|south|east|west|here|room|出口|这里|你|inventory|hp|health)")
NOT_GAME = re.compile(r"(?i)(password|passwd|name\s*:|login|密码|\(y/n\)|e-?mail|gender|press|return)")


CN_NUM = {"一": 1, "二": 2, "两": 2, "三": 3, "四": 4, "五": 5, "六": 6, "七": 7, "八": 8, "九": 9, "十": 10}


def cn_int(s):
    """a number written in digits or in Chinese (`五`, `十`, `十二`)"""
    if s.isdigit():
        return int(s)
    if len(s) == 1:
        return CN_NUM.get(s)
    if s[0] == "十" and len(s) == 2:
        return 10 + CN_NUM.get(s[1], 0)
    return None


def password_length(text):
    """(min, max) length a rejection message asks for -- `至少要十个字元`, `五到八个字元`, `at least 6 characters`, `between 4 and 8 characters` -- or None"""
    num = r"([一二两三四五六七八九十]+|\d+)"
    m = re.search(num + r"\s*(?:到|至|-|~)\s*" + num + r"\s*(?:个|個)?\s*(?:字元|字符|字母|位|个字|characters?)", text)
    if m and cn_int(m.group(1)) and cn_int(m.group(2)):
        return cn_int(m.group(1)), cn_int(m.group(2))
    m = re.search(r"(?:至少(?:要|需要|得)?|不少于|最少)\s*" + num + r"\s*(?:个|個)?\s*(?:字元|字符|字母|位|个字)", text)
    if m and cn_int(m.group(1)):
        return cn_int(m.group(1)), None
    m = re.search(r"(?i)at least\s+(\d+)\s+char", text)
    if m:
        return int(m.group(1)), None
    m = re.search(r"(?i)between\s+(\d+)\s+and\s+(\d+)\s+char", text)
    if m:
        return int(m.group(1)), int(m.group(2))
    return None


def password_of_length(lo, hi):
    pw = "Test1234abcdefghijklmnop"
    n = max(lo, 8)
    if hi:
        n = min(n, hi)
    return pw[:n]


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
PW_RULES = {i for i, (_, rep) in enumerate(RULES) if rep == "{pw}"}                  # the password prompts may repeat (type, retype, a lib that asks twice)


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
    waited = 0
    relaxed = False
    while steps < args.steps:
        if m.closed:
            print(f"RESULT closed steps={steps} last={last_prompt!r}")
            return 2
        low = tail(buf, 400)
        need = password_length(low)                          # a rejected password says how long it must be: use that from now on
        if need:
            mapping["pw"] = password_of_length(*need)
        last = low.rstrip().split("\n")[-1] if low.strip() else ""
        question = bool(re.search(r"([:：?？\)\]])\s*$", last)) or relaxed       # a prompt ends in a colon, a question mark, `(again)`, `[y/n]`
        rule_id, reply = None, None
        if NEW_CHAR.search(low) and not used.get("newchar"):                # Discworld: "F - Finger someone, N - New character, G - Guest character, or enter your character"
            used["newchar"] = 1
            rule_id, reply = "newchar", "N"
        pk = RACE_PICK.search(low) if reply is None else None
        if pk and re.search(r"(?i)\bpick\b", low) and used.get("racepick", 0) < 2:       # Dead Souls: "Valid races: dwarf elf ... Race:" and "pick RACE"
            used["racepick"] = used.get("racepick", 0) + 1
            rule_id, reply = "racepick", "pick " + pk.group(1)
        md = MENU_DONE.search(low) if reply is None else None
        if md and re.search(r"(?i)(choice|option|select|choose|pick|command)[^\n]*[:?]\s*$", last):       # a character-creation menu: its "Done" entry ends it
            rule_id, reply = len(RULES), md.group(1)
        if reply is None:
            rule_id, reply = match_rule(last, question) if last else (None, None)        # the prompt itself first, then its paragraph, then the text above
        if reply is None:
            rule_id, reply = match_rule(low.rstrip().split("\n\n")[-1], question)
        if reply is None:
            rule_id, reply = match_rule(low, question)
        if reply is not None:
            if reply == "{gender}" and re.search(r"(?i)\bmale\b", low) and re.search(r"(?i)\bfemale\b", low):
                reply = "male"                                  # Dead Souls, rifts: "pretend to be male, female, neutral, or none", "Gender: "
            reply = reply.replace("{first_of_race}", first_option(low, "race|species")).replace("{first_of_class}", first_option(low, "class|profession|guild|vocation"))
            for k, v in mapping.items():
                reply = reply.replace("{" + k + "}", v)
            reply = reply.replace("{newword}", "new")
            if "{first_of_list}" in reply:
                ml = re.search(r"(?m)^\s*([A-Za-z][\w-]*)\s*[(（]", low)
                reply = reply.replace("{first_of_list}", ml.group(1) if ml else "1")
            if reply == "y" and re.search(r"(?i)'yes' or 'no'|\(yes/no\)|\[yes/no\]|yes or no|enter yes", low):
                reply = "yes"                                   # Discworld: "You must enter 'yes' or 'no':"
            if "{range_mid}" in reply:
                mr = re.search(r"\((\d+)\s*(?:到|to|-|~|至)\s*(\d+)\)", low) or re.search(r"(?i)(?:合法值是?|valid(?: values?)?(?: is| are)?|between|range)\s*(\d+)\s*(?:到|to|-|~|至|and)\s*(\d+)", low)
                reply = str((int(mr.group(1)) + int(mr.group(2))) // 2) if mr else "20"
            used[rule_id] = used.get(rule_id, 0) + 1
            if used[rule_id] > (6 if rule_id in PW_RULES else 4) or (rule_id == 0 and used[rule_id] > 1):     # a loop means a wrong guess
                reply = None
        relaxed = False
        if reply is None and question and not relaxed_done.get(last):
            relaxed_done[last] = 1
            reply = "y" if re.search(r"[?？]\s*$", last) else "1"           # an unknown question: yes, or the first entry
        if reply is None and PATIENCE.search(low) and waited < 3:        # "Login may pause for 30 seconds or so": wait it out before probing
            waited += 1
            more, t_end = "", time.time() + 45
            while time.time() < t_end and not more.strip() and not m.closed:
                more = m.read(3.0, 3.0)
            if more.strip():
                buf = more
                last_prompt = tail(buf, 120)
                continue
        if reply is None:
            probe = m.cmd("look", idle=0.8, maxwait=6)
            if "Queued command" in probe:                       # Discworld queues commands while the character is busy: wait for the real answer
                probe += m.read(2.5, 25)
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
    ap.add_argument("--pw", default="Test1234")      # eight characters: some libs accept five to eight
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
