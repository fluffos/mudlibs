inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You mosh wildly to the sounds of the underground!$N$\n", "#MN# moshes wildly to the sounds of the underground!$N$\n");
       target("You mosh wildly to the sounds of the underground!#RET#You smash into #TN#!$N$\n", "#MN# moshes wildly to the sounds of the underground!#RET##CMS# smashes into #TN#!$N$\n", "#MN# moshes wildly to the sounds of the underground!#RET##CMS# smashes into you!$N$\n");
       afar("You mosh wildly to #TN# from afar.$N$\n", "#MN# moshes wildly at you from afar. uh...$N$\n");
    }
}

int
cmd_mosh(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
