inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You slap yourself! $N$\n", "#MN# slaps #MO#self!$N$\n");
       target("You slap #TN#!$N$\n", "#MN# slaps #TN#!$N$\n", "#MN# slaps you!$N$\n");
       afar("You slap #TN# from afar!$N$\n", "#MN# slaps you from afar!$N$\n");
    }
}

int
cmd_slap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
