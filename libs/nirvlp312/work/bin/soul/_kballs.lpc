inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You kick yourself in the balls! Daaaamn!$N$\n", "#MN# kicks #MO#self in the balls! Ouchers!$N$\n");
       target("You kick #TN# in the BALLS!$N$\n", "#MN# kicks #TN# in the BALLS!$N$\n", "#MN# kicks you in the BALLS!$N$\n");
       afar("You kick #TN# in the BALLS from afar!$N$\n", "#MN# kicks YOU in the BALLS from afar!$N$\n");
    }
}

int
cmd_kballs(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
