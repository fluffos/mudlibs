inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You curse the gods!$N$\n", "#MN# curses the gods!$N$\n");
       target("You curse #TN#!$N$\n", "#MN# curses #TN#!$N$\n", "#MN# curses you!$N$\n");
       afar("You curse #TN# from afar!$N$\n", "#MN# curses you from afar!$N$\n");
    }
}

int
cmd_curse(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
