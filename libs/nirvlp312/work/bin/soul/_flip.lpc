inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You flip head-over-heals.$N$\n", "#MN# flips head-over-heals.$N$\n");
       target("You flip over #TN#.$N$\n", "#MN# flips over #TN#.$N$\n", "#MN# flips over you.$N$\n");
       afar("You flip over #TN# from afar.$N$\n", "#MN# flips over you from afar.$N$\n");
    }
}

int
cmd_flip(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
