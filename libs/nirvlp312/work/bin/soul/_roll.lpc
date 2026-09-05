inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You roll your eyes!$N$\n", "#MN# rolls #MP# eyes!$N$\n");
       target("You roll your eyes at #TN#!$N$\n", "#MN# rolls #MP# eyes at #TN#!$N$\n", "#MN# rolls #MP# eyes at you!$N$\n");
       afar("You roll your eyes at #TN# from afar.$N$\n", "#MN# rolls #MP# eyes at you from afar.$N$\n");
    }
}

int
cmd_roll(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
