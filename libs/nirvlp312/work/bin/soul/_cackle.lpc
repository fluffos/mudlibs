inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You throw your head back and cackle with glee!$N$\n", "#MN# throws #MP# head back and cackles with glee!$N$\n");
       target("You cackle at #TN#.$N$\n", "#MN# cackles at #TN#.$N$\n", "#MN# cackles at you.$N$\n");
       afar("You cackle at #TN# from afar.$N$\n", "#MN# cackles at you from afar.$N$\n");
    }
}

int
cmd_cackle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
