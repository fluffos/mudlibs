inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You suck your own big toe!$N$\n", "#MN# sucks #MP# own big toe!$N$\n");
       target("You suck #TN#'s big toe!$N$\n", "#MN# sucks #TN#'s big toe!$N$\n", "#MN# sucks your big toe!$N$\n");
       afar("You suck #TN#'s big toe from afar!$N$\n", "#MN# sucks your big toe from afar!$N$\n");
    }
}

int
cmd_toe(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
