inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You stick out your tongue!$N$\n", "#MN# sticks out #MP# tongue!$N$\n");
       target("You stick out your tongue at #TN#!$N$\n", "#MN# sticks out #MP# tongue at #TN#!$N$\n", "#MN# sticks out #MP# tongue at you!$N$\n");
       afar("You stick out your tongue at #TN# from afar!$N$\n", "#MN# sticks out #MP# tongue at you from afar!$N$\n");
    }
}

int
cmd_tstick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
