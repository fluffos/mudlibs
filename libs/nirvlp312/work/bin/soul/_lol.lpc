inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You laugh out loud!$N$\n", "#MN# laughs out loud!$N$\n");
       target("You laugh out loud at #TN#!$N$\n", "#MN# laughs out loud at #TN#!$N$\n", "#MN# laughs out loud at you!$N$\n");
       afar("You laugh out loud at #TN# from afar!$N$\n", "#MN# laughs out loud at you from afar!$N$\n");
    }
}

int
cmd_lol(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
