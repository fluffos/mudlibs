inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cringe in terror!$N$\n", "#MN# cringes in terror!$N$\n");
       target("You cringe at #TN#.$N$\n", "#MN# cringes at #TN#.$N$\n", "#MN# cringes at you.$N$\n");
       afar("You cringe at #TN# from afar.$N$\n", "#MN# cringes at you from afar.$N$\n");
    }
}

int
cmd_cringe(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
