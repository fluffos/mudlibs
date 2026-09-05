inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce: $HK$FLAWLESS$N$ Victory.$N$\n", "#MN# announces: $HK$FLAWLESS$N$ Victory.$N$\n");
       target("You announce to #TN#: $HK$FLAWLESS$N$ Victory.#RET##TN# appears puzzled.$N$\n", "#MN# announces to #TN#: $HK$FLAWLESS$N$ Victory.#RET##TN# appears puzzled.$N$\n", "#MN# announces to you: $HK$FLAWLESS$N$ Victory.#RET#You appear puzzled.$N$\n");
       afar("You announce to #TN# from afar: $HK$FLAWLESS$N$ Victory.#RET##TN# announces to you from afar: ...\n", "#MN# announces to you from afar: $HK$FLAWLESS$N$ Victory.#RET#What the hell was that?$N$\n");
    }
}

int
cmd_flawless(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
