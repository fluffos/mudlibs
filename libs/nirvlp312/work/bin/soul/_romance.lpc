inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You desire some romance in your pitiful existence!$N$\n", "#MN# desires some romance in #MP# pitiful existence!$N$\n");
       target("You romance #TN#, hoping to get lucky!$N$\n", "#MN# romances #TN#, hoping to get lucky!$N$\n", "#MN# romances you, hoping to get lucky!$N$\n");
       afar("You romance #TN# from afar, hoping to get lucky!$N$\n", "#MN# romances you from afar, hoping to get lucky!$N$\n");
    }
}

int
cmd_romance(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
