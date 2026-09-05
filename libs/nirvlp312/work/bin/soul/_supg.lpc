inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout: SUP G!$N$\n", "#MN# shouts: SUP G!$N$\n");
       target("You turn to #TN# and shout: SUP G!$N$\n", "#MN# turns to #TN# and shouts: SUP G!$N$\n", "#MN# turns to you and shouts: SUP G!$N$\n");
       afar("You shout to #TN# from afar: SUP G!$N$\n", "#MN# shouts to you from afar: SUP G!$N$\n");
    }
}

int
cmd_supg(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
