inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You BOG!$N$\n", "#MN# BOGS!$N$\n");
       target("You BOG at #TN#!$N$\n", "#MN# BOGS at #TN#!$N$\n", "#MN# BOGS at you!$N$\n");
       afar("You BOG at #TN# from afar!$N$\n", "#MN# BOGS at you from afar!$N$\n");
    }
}

int
cmd_bog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
