inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You puke on your shoes.$N$\n", "#MN# doubles over and pukes.$N$\n");
       target("You puke on #TN#.$N$\n", "#MN# pukes on #TN#.$N$\n", "#MN# pukes on you.$N$\n");
       afar("You puke on #TN# from afar.$N$\n", "#MN# pukes on you from afar.$N$\n");
    }
}

int
cmd_puke(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
