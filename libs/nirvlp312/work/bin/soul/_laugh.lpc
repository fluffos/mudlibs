inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You laugh.$N$\n", "#MN# laughs.$N$\n");
       target("You laugh at #TN#.$N$\n", "#MN# laughs at #TN#.$N$\n", "#MN# laughs at you.$N$\n");
       afar("You laugh at #TN# from afar.$N$\n", "#MN# laughs at you from afar.$N$\n");
    }
}

int
cmd_laugh(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
