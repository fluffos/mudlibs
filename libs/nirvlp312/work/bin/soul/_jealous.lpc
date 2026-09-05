inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You turn $HG$green$N$ with jealousy.\n", "#MN# turns $HG$green$N$ with jealousy.\n");
       target("You're jealous of #TN#.\n", "#MN# is jealous of #TN#.\n", "#MN# seems to be jealous of you.\n");
       afar("You express feelings of jealousy towards #TN# from afar.\n", "#MN# seems to be jealous of you from afar.\n");
    }
}

int
cmd_jealous(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
