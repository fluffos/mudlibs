inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You fondle yourself.$N$\n", "#MN# fondles #MO#self. Ewww. Get a room!$N$\n");
       target("You fondle #TN#.$N$\n", "#MN# fondles #TN#.$N$\n", "#MN# fondles you.$N$\n");
       afar("You fondle #TN# from afar.$N$\n", "#MN# fondles you from afar.$N$\n");
    }
}

int
cmd_fondle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
