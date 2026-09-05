inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You throw back your head and R O A R!$N$\n", "#MN# roars... you shrink back in FEAR!$N$\n");
       target("You throw back your head and R O A R at #TN#!$N$\n", "#MN# roars at #TN#... you shrink back in FEAR!$N$\n", "#MN# roars at you... you shrink back in FEAR!$N$\n");
       afar("You throw back your head and R O A R at #TN# from afar!$N$\n", "#MN# roars at you from afar... you shrink back in FEAR!$N$\n");
    }
}

int
cmd_roar(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
