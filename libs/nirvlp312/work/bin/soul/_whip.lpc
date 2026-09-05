inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You whip everyone into a $HR$frenzy$N$!$N$\n", "#MN# whips everyone into a $HR$frenzy$N$!$N$\n");
       target("You whip #TN# into a $HR$frenzy$N$!$N$\n", "#MN# whips #TN# into a $HR$frenzy$N$!$N$\n", "#MN# whips you into a $HR$frenzy$N$!$N$\n");
       afar("You whip #TN# into a $HR$frenzy$N$ from afar!$N$\n", "#MN# whips you into a $HR$frenzy$N$ from afar!$N$\n");
    }
}

int
cmd_whip(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
