inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You kiss yourself.$N$\n", "#MN# kisses #MO#self.\n");
       target("You kiss #TN#.$N$\n", "#MN# kisses #TN#.$N$\n", "#MN# kisses you.$N$\n");
       afar("You kiss #TN# from afar.$N$\n", "#MN# kisses you from afar.$N$\n");
    }
}

int
cmd_kiss(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
