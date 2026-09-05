inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tip your hat.$N$\n", "#MN# tips #MP# hat.$N$\n");
       target("You tip your hat to #TN#.$N$\n", "#MN# tips #MP# hat to #TN#.$N$\n", "#MN# tips #MP# hat to you.$N$\n");
       afar("You tip your hat to #TN# from afar.$N$\n", "#MN# tips #MP# hat to you from afar.$N$\n");
    }
}

int
cmd_tip(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
