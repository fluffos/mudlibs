inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You send out a few $Y$hard nogs$N$.\n", "#MN# sends out a few $Y$hard nogs$N$.\n");
       target("You send out a few $Y$hard nogs$N$ to #TN#.\n", "#MN# sends out a few $Y$hard nogs$N$ to #TN#.\n", "#MN# sends out a few $Y$hard nogs$N$ to you.\n");
       afar("You send out a few $Y$hard nogs$N$ to #TN# from afar.\n", "#MN# sends out a few $Y$hard nogs$N$ to you from afar.\n");
    }
}

int
cmd_hnog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
