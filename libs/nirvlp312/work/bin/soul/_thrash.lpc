inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You thrash around wildly! That is so metal!$N$\n", "#MN# thrashes around wildly! That is so metal!$N$\n");
       target("You thrash around, smashing into #TN#! That is so metal!$N$\n", "#MN# thrashes around, smashing into #TN#! That is so metal!$N$\n", "#MN# thrashes around, smashing into you! That is so metal!$N$\n");
       afar("You thrash around, attempting to smash into #TN# from afar. That is so metal!$N$\n", "#MN# thrashes around, attempting to smash into you from afar. That is so metal!$N$\n");
    }
}

int
cmd_thrash(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
