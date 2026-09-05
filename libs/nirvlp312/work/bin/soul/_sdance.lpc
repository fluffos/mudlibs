inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You do a $Y$sexy dance$N$ to entertain everyone!$N$\n", "#MN# does a $Y$sexy dance$N$ to entertain everyone!$N$\n");
       target("You do a $Y$sexy dance$N$ to entertain #TN#!$N$\n", "#MN# does a $Y$sexy dance$N$ to entertain #TN#!$N$\n", "#MN# does a $Y$sexy dance$N$ to entertain you!$N$\n");
       afar("You do a $Y$sexy dance$N$ from afar to entertain #TN#!$N$\n", "#MN# does a $Y$sexy dance$N$ from afar to entertain you!$N$\n");
    }
}

int
cmd_sdance(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
