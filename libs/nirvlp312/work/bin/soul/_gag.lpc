inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You gag.$N$\n", "#MN# gags.$N$\n");
       target("You gag at #TN#.$N$\n", "#MN# gags at #TN#.$N$\n", "#MN# gags at you.$N$\n");
       afar("You gag at #TN# from afar.$N$\n", "#MN# gags at you from afar.$N$\n");
    }
}

int
cmd_gag(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
