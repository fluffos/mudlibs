inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You punch yourself!$N$\n", "#MN# punches #MO#self!$N$\n");
       target("You punch #TN#.$N$\n", "#MN# punches #TN#.$N$\n", "#MN# punches you!$N$\n");
       afar("You punch #TN# from afar.$N$\n", "#MN# punches you from afar!$N$\n");
    }
}

int
cmd_punch(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
