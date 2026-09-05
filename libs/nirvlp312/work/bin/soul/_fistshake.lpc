inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shake your fist violently!$N$\n", "#MN# shakes #MP# fist violently!$N$\n");
       target("You shake your fist violently at #TN#!$N$\n", "#MN# shakes #MP# fist violently at #TN#!$N$\n", "#MN# shakes #MP# fist violently at you!$N$\n");
       afar("You shake your fist violently at #TN# from afar!$N$\n", "#MN# shakes #MP# fist violently at you from afar!$N$\n");
    }
}

int
cmd_fistshake(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
