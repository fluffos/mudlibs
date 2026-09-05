inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You dance wildly to the rave music in your head!$N$\n", "#MN# dances wildly to the rave music in #MP# head!$N$\n");
       target("You dance wildly to the rave music in your head!#RET#You beckon #TN# to join you!$N$\n", "#MN# dances wildly to the rave music in #MP# head!#RET##CMS# beckons #TN# to join #MO#!$N$\n", "#MN# dances wildly to the rave music in #MP# head!#RET##CMS# beckons you to join #MO#!$N$\n");
       afar("You dance wildly to the rave music in your head!#RET#You beckon #TN# to join you from afar!$N$\n", "#MN# dances wildly to the rave music in #MP# head!#RET##CMS# beckons you to join #MO# from afar!$N$\n");
    }
}

int
cmd_rave(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
