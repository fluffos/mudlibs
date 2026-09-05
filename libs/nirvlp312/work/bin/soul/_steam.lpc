inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You steam in silence.$N$\n", "#MN# steams in silence.$N$\n");
       target("You steam at #TN#.$N$\n", "#MN# steams at #TN#.$N$\n", "#MN# steams at you.$N$\n");
       afar("You steam at #TN# from afar.$N$\n", "#MN# steams at you from afar.$N$\n");
    }
}

int
cmd_steam(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
