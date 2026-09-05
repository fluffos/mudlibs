inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You curtsey gracefully.$N$\n", "#MN# curtsies gracefully.$N$\n");
       target("You curtsey to #TN#.$N$\n", "#MN# curtsies to #TN#.$N$\n", "#MN# curtsies to you.$N$\n");
       afar("You curtsey to #TN# from afar.$N$\n", "#MN# curtsies to you from afar.$N$\n");
    }
}

int
cmd_curtsey(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
