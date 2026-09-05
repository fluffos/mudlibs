inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You stick out your tongue and go '$Y$Ick$N$!'$N$\n", "#MN# sticks out #MP# tongue and goes '$Y$ICK$N$!'$N$\n");
       target("You stick out your tongue at #TN# and go '$Y$ICK$N$!'$N$\n", "#MN# sticks #MP# tongue out at #TN# and goes '$Y$ICK$N$!'$N$\n", "#MN# sticks #MP# tongue out at you and goes '$Y$ICK$N$!'$N$\n");
       afar("You stick out your tongue at #TN# from afar and go '$Y$ICK$N$!'$N$\n", "#MN# sticks out #MP# tongue at you from afar and goes '$Y$ICK$N$!'$N$\n");
    }
}

int
cmd_ick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
