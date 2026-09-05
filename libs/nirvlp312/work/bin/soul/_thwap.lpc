inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You thwap yourself!$N$\n", "#MN# thwaps #MO#self!$N$\n");
       target("You thwap #TN#!$N$\n", "#MN# thwaps #TN#!$N$\n", "#MN# thwaps you!$N$\n");
       afar("You thwap #TN# from afar!$N$\n", "#MN# thwaps you from afar!$N$\n");
    }
}

int
cmd_thwap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
