#!/usr/bin/env python3
"""scripts/play_login.py PORT [--name NAME] [--pw PW] [--cmds "look;score;i"] [--host 127.0.0.1] [--steps 30] [--quiet] [--verbose]

A generic login robot for a booted lib (scripts/play_boot.sh): it answers the prompts of a registration or a login with defaults chosen by regex on the
last text the server sent (name, password twice, e-mail, gender, y/n, "press return", the first entry of a numbered menu, race / class lists), until a probe
command (`look`) answers like a game; then it runs the commands of --cmds and `quit`.  The transcript goes to stdout (--quiet: only the verdict).  It is a
survey tool, not a test of the login: a lib with an unusual dialogue ends `STUCK` with the last prompt, and gets a hand-written login (KB 08 10.16).

Exit status 0 when a game prompt was reached, 1 when stuck, 2 when the server closed the connection or never answered.  The verdict line is
`RESULT <in|stuck|closed> steps=N last=<last prompt>`.  `login_session(port, name, pw)` returns the logged-in Mud for a sweep script."""
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
    (r"(?i)\bor\s+[`'\"“]new[`'\"”]\s+to\s+create", "{newword}"),
    (r"(?i)(请用|请使用|使用|用)\s*[`'\"“]?new[`'\"”]?\s*(来|注册|起用|创建)", "{newword}"),                           # xo, xajh2, wllz3: "这个id还没有登录过，请用new来起用这个id", "[新玩家请使用 new 注册]"                # pd: 'Enter one of these names, or "new" to create a character'
    (r"(?i)(入|type|enter)\s*[：:]?\s*register\s*(?:\S+@\S+|您的?\s*e-?mail)", "register {email}"),                      # nte, the nitan family: "输入： register player@me.com 即可正确注册"
    (r"(?i)login as\s*[`'\"“]new[`'\"”]", "{newword}"),                                                    # majik3/4: "To create a new character: please login as 'new'."
    (r"(?i)\[c\]\s*create new character[\s\S]*(command or name|\[c\])[^\n]*:\s*$", "c"),                        # questmud: "[c] Create new character  [g] Enter as a guest ... Command or Name:"
    (r"(?is)\bpick TOWN\b.*Town:\s*$", "pick haven"),                                                         # havenmud: "pick TOWN - pick a particular town for yourself ... Town:"
    (r"(?is)choose a race[^\n]*:\s*\n[^\n]*\bhuman\b[^\n]*$", "human"),                                         # nirvlp312: "Choose a race for your character, you may select: human elf dwarf custom <race>"
    (r"(?i)throw (the )?other copy|already (logged|playing|connected)|reconnect|重复|另一个连线|取代|赶出去", "y"),
    (r"(?i)(re-?type|again|confirm|verify|repeat|once more).{0,40}(password|passwd|pass)|(password|passwd).{0,40}(again|confirm|verify)|再输入一次|再输一次|再次核对|核对密码|再核对一次|确认密码|重新输入密码|(^|\n)\s*again(\s+to\s+verify)?\s*:\s*$", "{lastpw}"),
    (r"(?i)(普通密码|normal password|not be the same|must be different|different from)[^\n]{0,80}[:：]\s*$", "{pw2}"),     # tybxjh: "管理密码和普通密码不能相同": the second password is another one
    (r"(?:不能|不可|不得|不要)(?:和|与|跟|同)[^\n]{0,15}(?:一样|相同|一致)[^\n]{0,30}[:：]\s*$", "{pw2}"),       # dtxywzxzb: "您的登陆密码不能和管理密码一样，请重设您的密码："
    (r"选择\s*[\[\(（]?\d+[\]\)）]?\s*则(?:接受|完成|确认|结束)", "{accept_num}"),       # sjsh family: "请选择你想重新设置哪一项天赋的取值[0-3]，选择[9]则接受当前的设置："
    (r"(?:身份标识|身份识别码|身份识别)[^\n]{0,30}[:：]\s*$", "{pw}"),                                    # wuhanzhan, longyunmeng, ylfyxa3 ...: "请重设您的身份标识："
    (r"(?im)^[^\n]*(电子邮件|電子郵件|邮箱|信箱|邮件地址|郵件地址|邮件位址|郵件位址|e-?mail)[^\n]*[:：]\s*$", "{email}"),                                   # pkuxkx: "您的电子邮件地址（……以便在密码丢失或忘记时确认你的身份）："
    (r"(?i)password|passwd|密码|口令", "{pw}"),
    (r"(?i)(QQ号|QQ number|qq号码)", "12345678"),                                   # aoxiangtianji: "您的QQ号码："
    (r"(?i)(e-?mail|email|电子邮件|電子郵件|邮箱|信箱|邮件地址|郵件地址)", "{email}"),
    (r"(?im)^[^\n]*(gbk|big5)[^\n]*utf-?8[^\n]*[:：]\s*$|^[^\n]*utf-?8[^\n]*(gbk|big5)[^\n]*[:：]\s*$", "utf-8"),            # the xkx family's encoding menu: "Select 国标码 GBK or 国际码 utf-8 (GBK/utf-8):"
    (r"(?i)\(gb/big5\)|\(big5/gb\)|\(gbk?/big5\)", "gb"),                    # the older xkx family menu: "Select 国标码 GB or 大五码 BIG5 (gb/big5):"
    (r"(?i)(gender|sex|male or female|\(m\)ale|\bmale\b.*\bfemale\b|男.*女|性别|扮演男性)", "{gender}"),
    (r"(?i)(real ?name|your name in real|真实姓名)", "Test User"),
    (r"中文姓氏|您的姓氏|请输入.{0,6}姓[：:]?\s*$", "测"),                       # nitan: "您的中文姓氏(不要超过两个汉字)：" and then the given name
    (r"(?i)(chinese name|中文名字|中文姓名|您的中文名)", "测试"),
    (r"(名字|姓名|人物名|大名)[^\n]{0,24}(汉字|漢字|中文)[^\n]{0,12}[:：]\s*$", "测试"),                       # immaster: "您的名字(不要超过10个汉字)："
    (r"(?i)(中小学|小学生|学生或|未成年|under ?age|or younger|还有好多工作|工作.{0,6}没有做完)[^\n]{0,30}(\(yes/no\)|\(y/n\)|[?？﹖])\s*$", "no"),          # mhsj, sjcs ...: "您是否是中小学学生或年龄更小？(yes/no)": not a pupil
    (r"(?i)(同意|接受|满意|agree|accept|satisfied)[^\n]{0,30}[?？﹖:：﹕]\s*$", "y"),
    (r"(?i)(同意|接受|满意|agree|accept|satisfied)[^\n]{0,30}[?？﹖]?\s*[\(\[（［][^\n]{1,20}[\)\]）］]\s*$", "y"),                  # xiyouji family: "您同意这组天赋数值吗？[n]", jinyongwenzi: "(y 或 n)"
    (r"(?i)(do you want|would you like|are you sure|create (a )?(new )?(character|player)|new (character|player)\?|确定吗|\(y/n\)|\[y/n\]|\(yes/no\)|yes or no|'yes' or 'no'|y\(es\) or n\(o\)|y or n|y/n)", "y"),
    (r"(?i)\(s/n\)|\[s/n\]", "s"),                                    # Spanish: "No entiendo... (s/n)"
    (r"(?i)\(default:\s*[^)\n]*\)\s*[:：]?\s*$", ""),                                                  # foundation1/2: "Please choose a display name (default: sweepzq):"
    (r"(?i)(press|hit)\s+(\[?enter\]?|\[?return\]?|any key)|\[more\]|--more--|continue\s*[:\.]?\s*$|按.{0,6}(回车|键)|任意键|<return>|\(return\)", ""),
    (r"(?i)(terminal|term type|screen|colou?r|ansi|vt100|client)\b.{0,50}[:?]\s*$", "{term}"),
    (r"例如(?:输入|輸入)?[:：]\s*\d+(?:\s+\d+){2,}[\s\S]*[:：]\s*$", "{example_nums}"),                 # dtsl / dtsl2 / dtslmud: "请输入您想要的属性，四项之和必须等于八十点 ... 例如：20 20 20 20"; shzs: "例如输入: 15 10 10 6 17 2"
    (r"(?:属性|屬性|attributes?)\s*\[[^\]\n]*(?:显示说明|顯示說明|help)[^\]\n]*\]\s*[:：]\s*$", "h"),                   # shzs: "请决定您的人物属性 [输入 ?或 h 显示说明]:" -- the help text holds the example the rule above uses
    (r"(用英文|in english)[^\n]{0,20}[\)）:：]\s*[:：]?\s*$|请选择您的种族|请(?:您)?选择[你您]的职业", "{human_or_first}"),            # es1 / es1_win: "请选择您的种族(用英文):" over `人类(human)  精灵(elf) ...`
    (r"你的选择[:：]\s*$|选择.{0,10}(种族|职业|门派)[^\n]{0,20}[:：]\s*$", "{first_of_list}"),            # a list of `name(name)  5 点业力` lines
    (r"(?i)(race|species)\b.{0,60}[:?]\s*$", "{first_of_race}"),
    (r"(?i)(class|profession|guild|vocation)\b.{0,60}[:?]\s*$", "{first_of_class}"),
    (r"(?i)(enter|type|give|choose|select|input).{0,30}(number|choice|option)|^\s*\[?1\]?[\.\)]\s", "1"),
    (r"(?i)(?:合法的?值是?|valid(?: values?)?(?: is| are)?|between|range)\s*(\d+)\s*(?:到|to|-|~|至|and)\s*(\d+)", "{range_mid}"),      # "合法值是 10-30"
    (r"[\(\[](\d+)\s*(?:到|to|-|~|至)\s*(\d+)[\)\]]", "{range_mid}"),                 # "(10-30)", "[10-30]"
    (r"(?i)(select|choose|pick|enter|give)\s+(a|an|your)\s+(character\s+)?(name|handle|nickname)\s*[:?]?\s*$", "{name}"),          # lpuni: "Please select a name:" (the menu rule below would answer 1)
    (r"只能输入数字|请重新设定.{0,8}的值", "{range_mid}"),                                                   # xuanjianlu: "对不起，你只能输入数字。请重新设定膂力的值："
    (r"未完继续|\(\s*(?:n 或 )?<?ENTER>?\s*继续", ""),                                                             # xkm, xyj451: "== 未完继续 43% == (n 或 <ENTER> 继续下一页，q 离开，b 前一页)"
    (r"如果希望由游戏帮助你随机分配请输入\s*0", "0"),                                                              # tianxia: the point-allocation prompt: let the game roll
    (r"选择一种人物类型[^\n]*\(\s*([A-Z])\s*[-－–]+\s*[A-Z]\s*\)|\(\s*([A-Z])\s*[-－–]+\s*[A-Z]\s*\)\s*中选择", "{first_letter}"),    # xbtxiii: "你只能在(A--L)中选择一种人物类型:"
    (r"(?is)(select|choose|enter)\s+a\s+(height|weight|age)[^\n]*:\s*\n.*\d+\s+to\s+\d+\s*(ft|feet|cm|kg|years)", "{range_mid}"),                          # nirvlp312: "please select a height within race limits: human & custom, 4 to 7 ft."
    (r"(?i)(请选择|请输入.{0,10}(数字|号码|编号)|choose|select|pick).{0,60}[:：﹕?？﹖\)]\s*$", "1"),
    (r"(?i)(what is|enter|give|type|input|tell me).{0,40}(your )?(character )?(name|id|handle)|(by )?what (is your |do you wish )?name|name do you|known\s*\?|login\s*:|name\s*:|name\?|名字|使用者代号|用户名|道号|ID\s*[:：]|帐号|账号|new\)|名[稱称]\s*\(Name\)", "{name}"),
]

# the BIG5 libs print the same prompts in traditional characters (`請設定您的密碼`, `您的使用者代號`): every simplified character below that a pattern uses also matches its traditional one
TRAD = dict(zip("码个输请选择电邮确键认设统进这们体样为吗别识门读钮开级员发来汉标连线务续随则须时话齐联络资总满应该复让页间头现关见观触问题处约传条届开边专东丢书买单对头显将尽还远种范围乐"
                "护实让场术战斗击创际带满态数断气灵觉资摆击号户帐账国", "碼個輸請選擇電郵確鍵認設統進這們體樣為嗎別識門讀鈕開級員發來漢標連線務續隨則須時話齊聯絡資總滿應該復讓頁間頭現關見觀觸問題處約傳條屆開邊專東丟書買單對頭顯將盡還遠種範圍樂"
                "護實讓場術戰鬥擊創際帶滿態數斷氣靈覺資擺擊號戶帳賬國"[:len("码个输请选择电邮确键认设统进这们体样为吗别识门读钮开级员发来汉标连线务续随则须时话齐联络资总满应该复让页间头现关见观触问题处约传条届开边专东丢书买单对头显将尽还远种范围乐护实让场术战斗击创际带满态数断气灵觉资摆击号户帐账国")]))


def trad_expand(pat):
    out, depth, i = [], 0, 0
    while i < len(pat):
        ch = pat[i]
        if ch == "\\":
            out.append(pat[i:i + 2])
            i += 2
            continue
        if ch == "[":
            depth += 1
        elif ch == "]":
            depth = max(0, depth - 1)
        if ch in TRAD:
            out.append(ch + TRAD[ch] if depth else "[" + ch + TRAD[ch] + "]")
        else:
            out.append(ch)
        i += 1
    return "".join(out)


RULES = [(trad_expand(rx), rep) for rx, rep in RULES]
# rules that read the whole screen before the prompt line is looked at: the line says only "What is your character's name?" and the instruction is above it
PRIORITY = [
    (r"版本验证成功\s*$", "{name},{pw},x,{email}", "prio_hhsj_handshake"),                                                     # hhsj family (nitan170911, xfbhh): the server writes `ver1.0,KEY` / 版本验证成功 and waits for one line `id,password,x,email`
    (r"0008\s*$", "男性║1║路客", "prio_hhsj_char"),                                                                          # hhsj family: `0008` = a new account, the next line is `gender║img║Chinese name`
    (r"(?is)palabra resuena en tu conciencia: ['\"“]nacer['\"”]", "nacer", "prio_nacer"),                              # ninetears: the first word of the Spanish birth
    (r"(?is)enter your current character's name.*your choice:\s*$", "{name}", "prio_dwname"),                              # Discworld: the menu after N (new) was used up, or --existing
    (r"(?s)(还没有登录过|没有这个玩家|不存在)[^\n]*请(用|使用)\s*[`'\"“]?new.*[:：；;]\s*$", "{newword}", "prio_new_cn"),                  # xo, xajh2: "这个id还没有登录过，请用new来起用这个id.\n您的英文名字；"
    (r"(?is)(?:新玩家|new players?)[^\n]{0,12}(?:键入|输入|请键|type|enter)\s*[`'\"“]?new(?![a-z])[^\n]*$", "new", "prio_new_kb"),                 # xixingzhanji: "您的英文名字：（新玩家请键入New注册）"
    (r"(?is)1[.)、]\s*(?:登录|登入|login).*2[.)、]\s*(?:注册|註冊|register|new).*[:：]\s*$", "{reg_or_login}", "prio_reg_menu"),     # xxsj: "1. 登录  2. 注册  请输入选项 (1/2):"
    (r"(?s)(?:这种名字会造成|不合适的名字|名字.{0,6}(?:不当|不雅|不可用|不能使用)).*(?:中文名字|姓名|名字)[^\n]*[:：]\s*$", "路客", "prio_cname2"),             # yxxcii: its banned-name list holds `测试`
    (r"(?s)(?:创造|創造|建立|注册|註冊)[^\n]{0,12}(?:请输入|請輸入|请键入|請鍵入|请用|請用)\s*[`'\"“]?new[`'\"”]?[^\n]*\n[^\n]*[:：]\s*$", "new", "prio_new_create"),     # revivalworld: "創造新的遊戲角色請輸入 'new'。(允許玩家登入)\n您的英文名字："
    (r"(?is)No character with that name exists.*login as\s*[`'\"“]new[`'\"”]", "new", "prio_new"),                    # majik3/4
    (r"(?s)id@ccb[^\n]*格式[^\n]*\n[^\n]*[:：]\s*$", "tester@ccb", "prio_email_ccb"),                                  # yueyingqiyuan: "电子邮件地址需要是 id@ccb 的格式。"
    (r"(?s)([A-Za-z0-9])\s*键\s*接受此?天赋[^\n]*$", "{accept_key}", "prio_accept_key"),                              # sgzmudsgz: "以下天赋值满意吗 ... r键接受此天赋，h键帮助，m键返回上级选单，q键退出。" (no colon, so no rule sees a question)
    (r"(?s)例如(?:输入|輸入)?[:：]\s*\d+(?:\s+\d+){2,}[\s\S]*(?:属性|屬性)[^\n]*[:：]\s*$", "{example_nums}", "prio_attr_example"),         # shzs: the help text of the attribute prompt shows `15 10 10 6 17 2`; the prompt line alone only says `h`
    (r"(?is)\[c\]\s*create new character.*(?:command or name|\bname)[^\n]*:\s*$", "c", "prio_create"),                 # questmud: a menu whose last line is the generic `Command or Name:`
    (r"(?s)User Menu.*Enter the game.*\[spcrwq\]\s*$", "p", "prio_lima_menu"),                                         # lima: "s Select character to play  p Enter the game ... [spcrwq]" (autologin after 10 s otherwise)
]
RACE_PICK = re.compile(r"(?is)valid races?:\s*([A-Za-z][\w-]*)")
NEW_CHAR = re.compile(r"(?im)^\s*N\s*-\s*New character")
MENU_DONE = re.compile(r"(?i)(?:^|\s)\[?(\d+)\]?\s*[-.):]\s*(?:done|finish|finished|accept|continue|save|完成|结束|确定)\b")
LOADING = re.compile(r"\d{3} - (?:载入|載入) |(?:载入|載入)中")
PATIENCE = re.compile(r"(?i)(may|will) pause|please wait|wait \d+ seconds|请稍候|请等待|一会儿|terms and conditions CAREFULLY|载入中|載入中|\d{3} - (?:载入|載入) ")      # Discworld: the licence screen is a timed pause before its y/n
GAME = re.compile(r"(?i)(exit|obvious|you are|you see|north|south|east|west|here|room|出口|这里|你|inventory|hp|health)")
NOT_GAME = re.compile(r"(?i)(password|passwd|name\s*:|login|密码|\(y/n\)|e-?mail|gender|press (?:enter|return|any)|\[return\]|\(return\)|return (?:to|key)|英文名字|名字\s*[:：]|代号|道号|帐号|账号|用户名)")


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
    m = re.search(r"(?:至少(?:要由|要|需要|得|由)?|不少于|最少)\s*" + num + r"\s*(?:个|個)?\s*(?:字元|字符|字母|位|个字)", text)
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


def last_line(text):
    s = text.rstrip().split("\n")
    return s[-1] if s else ""


def text_tail(t):
    """the last line of an answer that is more than a bare prompt (`>`, `hp: 10/10 >`, `]`)"""
    for ln in reversed(t.replace("\x00", "").strip().split("\n")):
        if re.search(r"#BB[0-9A-F]{6}", ln):
            continue                                       # the ZJ protocol repeats its status line (气血.400:400/400:#BBFF0000║...) after every answer
        s = ln.strip().rstrip(">] ").strip().lstrip("[ ").strip()
        if s and (len(s) > 2 or s.isalnum()) and not re.fullmatch(r"(?:\w+\s*[:：]?\s*\d+(?:/\d+)?%?\s*)+", s):          # Dead Souls: `hp: 1020/1020  mp: 350/350  sp: 822/822 >` is the prompt; shzs: `[ 时间 10 精神 100% 移动 100% ]`
            return s
    return ""


def slow_read(m, first_wait=60.0, idle=1.5):
    """wait up to `first_wait` seconds for the first byte of a slow answer (Mud.read gives up after `idle` seconds of silence from the start), then read until it goes quiet"""
    t_end = time.time() + first_wait
    while time.time() < t_end and not m.closed:
        s = m.read(3.0, 3.0)
        if s.strip():
            return s + m.read(idle, 6.0)
    return ""


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
PW_RULES = {i for i, (_, rep) in enumerate(RULES) if rep in ("{pw}", "{pw2}", "{lastpw}")}                  # the password prompts may repeat (type, retype, a lib that asks twice)


def run(args):
    t0 = time.time()
    out = (lambda *a: None) if args.quiet else print
    try:
        m = Mud(args.host, args.port, log=False)
    except OSError as e:
        print(f"RESULT closed steps=0 last=connect failed: {e}")
        return 2
    buf = m.read(2.0, 15)
    if not buf.strip():
        buf = m.read(3.0, 90)                 # a driver busy with a boot-time load (nt1 restores ~140 users) greets late: do not answer a screen that has not come
    out("<<< " + buf.replace("\n", "\n<<< ")[-600:])
    last_prompt = tail(buf, 120)
    steps = 0
    mapping = {"name": args.name, "pw": args.pw, "email": args.email, "gender": args.gender, "term": args.term}
    mapping["pw2"] = "Other5678"
    mapping["lastpw"] = args.pw
    used = {}
    relaxed_done = {}
    empties = 0
    waited = 0
    patience_end = None
    relaxed = False
    saw_loader, reconnects, slow_waits = False, 0, 0
    while steps < args.steps:
        if LOADING.search(buf):
            saw_loader = True
        if m.closed:
            if saw_loader and reconnects < 1:
                reconnects += 1                         # revivalworld: the daemons load while the first visitor watches, and the lib closes every connection when it is done
                out("[the start-up loader closed the connection: reconnecting]")
                time.sleep(2)
                try:
                    m = Mud(args.host, args.port, log=False)
                except OSError as e:
                    print(f"RESULT closed steps={steps} last=connect failed: {e}")
                    return 2
                saw_loader = False
                buf = m.read(2.0, 15) or m.read(3.0, 90)
                continue
            print(f"RESULT closed steps={steps} last={last_prompt!r}")
            return 2
        low = tail(buf, 400)
        need = password_length(low)                          # a rejected password says how long it must be: use that from now on
        if need:
            mapping["pw"] = password_of_length(*need)
            mapping["pw2"] = "O" + mapping["pw"][1:][::-1]
            mapping["lastpw"] = mapping["pw"]
        last = low.rstrip().split("\n")[-1] if low.strip() else ""
        question = bool(re.search(r"([:：﹕?？﹖\)\]）】；;﹔])\s*$", last)) or relaxed       # a prompt ends in a colon, a question mark, `(again)`, `[y/n]`
        rule_id, reply = None, None
        if NEW_CHAR.search(low) and not used.get("newchar") and not getattr(args, "existing", False):                # Discworld: "F - Finger someone, N - New character, G - Guest character, or enter your character"
            used["newchar"] = 1
            rule_id, reply = "newchar", "N"
        pk = RACE_PICK.search(low) if reply is None else None
        if pk is None and re.search(r"(?i)\bpick RACE\b", low) and re.search(r"(?i)race\s*:\s*$", last_line(low)) and used.get("racepick", 0) < 2:
            used["racepick"] = used.get("racepick", 0) + 1        # Dead Souls I/II: "pick RACE - pick a particular race for yourself" and a bare "Race:" prompt; `human` is in every race list
            rule_id, reply = "racepick", "pick human"
        if pk and re.search(r"(?i)\bpick\b", low) and used.get("racepick", 0) < 2:       # Dead Souls: "Valid races: dwarf elf ... Race:" and "pick RACE"
            used["racepick"] = used.get("racepick", 0) + 1
            rule_id, reply = "racepick", "pick " + pk.group(1)
        md = MENU_DONE.search(low) if reply is None else None
        if md and re.search(r"(?i)(choice|option|select|choose|pick|command)[^\n]*[:?]\s*$", last):       # a character-creation menu: its "Done" entry ends it
            rule_id, reply = len(RULES), md.group(1)
        if reply is None:
            for prx, prep, pkey in PRIORITY:
                if used.get(pkey, 0) < 3 and re.search(prx, low):
                    used[pkey] = used.get(pkey, 0) + 1
                    rule_id, reply = pkey, (args.name if prep == "new" and getattr(args, "existing", False) else prep)
                    break
        if reply is None:
            rule_id, reply = match_rule(last, question) if last else (None, None)        # the prompt itself first, then its paragraph, then the text above
        if reply is None:
            rule_id, reply = match_rule(low.rstrip().split("\n\n")[-1], question)
        if reply is None:
            rule_id, reply = match_rule(low, question)
        if reply is not None and LOADING.search(last):
            reply = None                                        # a loader's progress line (`053 - 載入 房地產系統(ESTATE_D) ...Done`) looks like a menu entry: wait, do not answer
        if reply is not None:
            if reply == "{gender}" and re.search(r"(?i)\bmale\b", low) and re.search(r"(?i)\bfemale\b", low):
                reply = "male"                                  # Dead Souls, rifts: "pretend to be male, female, neutral, or none", "Gender: "
            reply = reply.replace("{first_of_race}", first_option(low, "race|species")).replace("{first_of_class}", first_option(low, "class|profession|guild|vocation"))
            for k, v in mapping.items():
                reply = reply.replace("{" + k + "}", v)
            reply = reply.replace("{newword}", args.name if getattr(args, "existing", False) else "new")
            if "{reg_or_login}" in reply:
                reply = "1" if getattr(args, "existing", False) else "2"
            if "{accept_key}" in reply:
                mk = re.search(r"([A-Za-z0-9])\s*键\s*接受", low)
                reply = mk.group(1) if mk else "r"
            if "{example_nums}" in reply:
                me = re.search(r"例如(?:输入|輸入)?[:：]\s*(\d+(?:\s+\d+){2,})", low)
                reply = reply.replace("{example_nums}", me.group(1) if me else "20 20 20 20")
            if "{human_or_first}" in reply:
                mh = re.search(r"\(([A-Za-z][\w-]*)\)", low)
                reply = reply.replace("{human_or_first}", "human" if re.search(r"(?i)\(human\)", low) else (mh.group(1) if mh else "human"))
            if "{first_of_list}" in reply:
                ml = re.search(r"(?m)^\s*([A-Za-z][\w-]*)\s*[(（]", low)
                reply = reply.replace("{first_of_list}", ml.group(1) if ml else "1")
            if reply == "y" and re.search(r"(?i)'yes' or 'no'|\(yes/no\)|\[yes/no\]|yes or no|enter yes", low):
                reply = "yes"                                   # Discworld: "You must enter 'yes' or 'no':"
            if "{first_letter}" in reply:
                mf = re.search(r"\(\s*([A-Z])\s*[-－–]+\s*[A-Z]\s*\)", low)
                reply = mf.group(1) if mf else "A"
            if "{accept_num}" in reply:
                ma = re.search(r"选择\s*[\[\(（]?(\d+)[\]\)）]?\s*则(?:接受|完成|确认|结束)", low)
                reply = ma.group(1) if ma else "9"
            if "{range_mid}" in reply:
                mr = re.search(r"[\(\[](\d+)\s*(?:到|to|-|~|至)\s*(\d+)[\)\]]", low) or re.search(r"(?:数字|數字)\s*(\d+)\s*[~～-]\s*(\d+)", low) or re.search(r"(?i)\b(\d+)\s+to\s+(\d+)\s*(?:ft|feet|cm|kg|years)", low) or re.search(r"(?i)(?:合法的?值是?|valid(?: values?)?(?: is| are)?|between|range)\s*(\d+)\s*(?:到|to|-|~|至|and)\s*(\d+)", low)
                reply = str((int(mr.group(1)) + int(mr.group(2))) // 2) if mr else "20"
            used[rule_id] = used.get(rule_id, 0) + 1
            if used[rule_id] > (6 if rule_id in PW_RULES else 12 if reply.isdigit() else 4) or (rule_id == 0 and used[rule_id] > 1):     # a loop means a wrong guess (a series of attribute prompts is not one)
                reply = None
        relaxed = False
        if reply is None and question and not relaxed_done.get(last) and not LOADING.search(last):
            relaxed_done[last] = 1
            reply = "y" if re.search(r"[?？﹖]\s*$", last) else "1"           # an unknown question: yes, or the first entry
        if reply is None and PATIENCE.search(low) and (waited < 3 or (patience_end and time.time() < patience_end)):        # "Login may pause for 30 seconds or so": wait it out before probing
            if patience_end is None:
                patience_end = time.time() + 240                                   # revivalworld, zsdsj: the first visitor sees the daemons load one by one (a minute); wait while it goes on
            waited += 1
            more, t_end = "", time.time() + 45
            while time.time() < t_end and not more.strip() and not m.closed:
                more = m.read(3.0, 3.0)
            out(f"[patience {waited}: {len(more)} bytes more]")
            if more.strip():
                buf = more
                last_prompt = tail(buf, 120)
                continue
            if time.time() < patience_end and not m.closed:
                continue                                                           # a silent stretch of the loader (revivalworld's html_d takes a minute on the debug driver)
        if reply is None:
            probe = m.cmd("look", idle=0.8, maxwait=6)
            if "Queued command" in probe:                       # Discworld queues commands while the character is busy: wait for the real answer
                probe += m.read(2.5, 25)
            out(">>> look\n<<< " + probe.strip().replace("\n", "\n<<< ")[-300:])
            same = probe.strip()[-160:] == buf.strip()[-160:]          # a menu or a question redisplays itself when `look` is typed at it
            if re.search(r"(?i)there (is|are) \w+ obvious exits?|^obvious exits:", probe, re.M) and not same:        # an LPC room description: the character is in the world (Discworld queues the next commands behind its intro)
                buf = probe
                break
            if len(probe.strip()) > 20 and (GAME.search(probe) or probe.count("\n") >= 3) and not NOT_GAME.search(tail(probe, 200)):
                nonsense = m.cmd("zzqxk", idle=0.8, maxwait=5)              # a game answers an unknown verb in a line; a menu or a dialogue shows itself again
                out(">>> zzqxk\n<<< " + nonsense.strip().replace("\n", "\n<<< ")[-200:])
                same_tail = text_tail(nonsense) == text_tail(probe)       # a dialogue redisplays its prompt for any input; a game answers `look` and `zzqxk` differently
                if len(nonsense.strip()) < 200 and not same_tail and not re.search(r"\d\s*[\.\)〗]|选择|choose|select|请输入(?!\s*help)|please", nonsense, re.I) and not (same and re.search(r"(?i)invalid|incorrect|illegal|choose again|重新|无效|错误", nonsense)):
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
        if not buf.strip() and not m.closed and slow_waits < 6:                # a slow answer (Dead Souls compiles its player files on the first login; nt1 answers every line 10-30 s late while its first heart beat restores 139 users): wait for it before probing
            slow_waits += 1
            buf = slow_read(m)
        if rule_id in PW_RULES and reply:
            mapping["lastpw"] = reply                       # the "once more" prompt that follows repeats it
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
    if getattr(args, "keep", False):                        # a sweep wants the logged-in session: no quit, the Mud object stays in args.session
        args.session = m
        print(f"RESULT in steps={steps} last={last_prompt!r} seconds={time.time() - t0:.0f}")
        return 0
    m.cmd("quit", idle=0.8, maxwait=4)
    print(f"RESULT in steps={steps} last={last_prompt!r} seconds={time.time() - t0:.0f}")
    return 0


def login_session(port, name="sweepzq", pw="Test1234", cmds="", steps=45, quiet=True, existing=False):
    """for a sweep script: walk the dialogue of a booted lib and return the logged-in `Mud` (None when the robot did not get in); the transcript stays quiet"""
    a = argparse.Namespace(host="127.0.0.1", port=port, name=name, pw=pw, email="tester@example.com", gender="m", term="ansi", cmds=cmds, steps=steps, quiet=quiet, verbose=False, keep=True, session=None, existing=existing)
    import io, contextlib
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        rc = run(a)
    return a.session if rc == 0 else None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("port", type=int)
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--name", default="sweepzq")
    ap.add_argument("--pw", default="Test1234")      # eight characters: some libs accept five to eight
    ap.add_argument("--email", default="tester@example.com")
    ap.add_argument("--gender", default="m")
    ap.add_argument("--term", default="ansi")
    ap.add_argument("--cmds", default="look;score;i;who;help")
    ap.add_argument("--steps", type=int, default=30)
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--existing", action="store_true", help="the character exists: type its name where a new one would be created (no `new`, no `N - New character`)")
    ap.add_argument("--verbose", action="store_true")
    sys.exit(run(ap.parse_args()))


if __name__ == "__main__":
    main()
