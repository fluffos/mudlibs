inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You thwak yourself for being $B$stupid$N$.$N$\n", "#MN# thwaks #MO#self for being $B$stupid$N$.$N$\n");
       target("You thwak #TN# for being $B$stupid$N$.$N$\n", "#MN# thwaks #TN# for being $B$stupid$N$.$N$\n", "#MN# thwaks you for being $B$stupid$N$.$N$\n");
       afar("You thwak #TN# from afar for being $B$stupid$N$.$N$\n", "#MN# thwaks you from afar for being $B$stupid$N$.$N$\n");
    }
}

int
cmd_thwak(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
