inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pull your own hair!$N$\n", "#MN# pulls #MP# own hair!$N$\n");
       target("You pull #TN#'s hair!$N$\n", "#MN# pulls #TN#'s hair!$N$\n", "#MN# pulls your hair!$N$\n");
       afar("You pull #TN#'s hair from afar!$N$\n", "#MN# pulls your hair from afar!$N$\n");
    }
}

int
cmd_phair(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
