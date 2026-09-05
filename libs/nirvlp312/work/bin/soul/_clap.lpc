inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You clap.$N$\n", "#MN# claps.$N$\n");
       target("You clap for #TN#.$N$\n", "#MN# claps for #TN#.$N$\n", "#MN# claps for you.$N$\n");
       afar("You clap for #TN# from afar.$N$\n", "#MN# claps for you from afar.$N$\n");
    }
}

int
cmd_clap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
