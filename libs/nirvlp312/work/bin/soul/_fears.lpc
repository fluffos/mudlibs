inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce: FEAR IT!$N$\n", "#MN# announces: FEAR IT!$N$\n");
       target("You fear #TN#.$N$\n", "#MN# fears #TN#.$N$\n", "#MN# fears you.$N$\n");
       afar("You fear #TN# from afar.$N$\n", "#MN# fears you from afar.$N$\n");
    }
}

int
cmd_fears(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
