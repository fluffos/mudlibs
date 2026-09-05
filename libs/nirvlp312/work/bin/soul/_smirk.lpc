inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You smirk.$N$\n", "#MN# smirks.$N$\n");
       target("You smirk at #TN#.$N$\n", "#MN# smirks at #TN#.$N$\n", "#MN# smirks at you.$N$\n");
       afar("You smirk at #TN# from afar.$N$\n", "#MN# smirks at you from afar.$N$\n");
    }
}

int
cmd_smirk(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
