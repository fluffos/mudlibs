inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chortle demonically!$N$\n", "#MN# chortles demonically!$N$\n");
       target("You chortle demonically at #TN#!$N$\n", "#MN# chortles demonically at #TN#!$N$\n", "#MN# chortles demonically at you!$N$\n");
       afar("You chortle demonically at #TN# from afar!$N$\n", "#MN# chortles demonically at you from afar!$N$\n");
    }
}

int
cmd_chortle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
