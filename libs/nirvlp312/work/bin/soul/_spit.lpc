inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You spit on the ground.\n", "#MN# spits on the ground.\n");
       target("You spit on #TN#!$N$\n", "#MN# spits on #TN#!$N$\n", "#MN# spits on you!$N$\n");
       afar("You spit on #TN# from afar!$N$\n", "#MN# spits on you from afar!$N$\n");
    }
}

int
cmd_spit(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
