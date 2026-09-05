inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cower in absolute fear and terror!$N$\n", "#MN# cowers in absolute fear and terror!$N$\n");
       target("You cower away from #TN# in absolute fear and terror!$N$\n", "#MN# cowers away from #TN# in absolute fear and terror!$N$\n", "#MN# cowers away from you in absolute fear and terror!$N$\n");
       afar("You cower away from #TN# in absolute fear and terror! ... from afar!$N$\n", "#MN# cowers away from you in absolute fear and terror! ... from afar!$N$\n");
    }
}

int
cmd_cower(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
