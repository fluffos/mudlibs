inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go into TMI shock.$N$\n", "$MN$ goes into TMI shock.$N$\n");
       target("You go into TMI shock from what #TN# just said.$N$\n", "#MN# goes into TMI shock from what #TN# just said.$N$\n", "#MN# goes into TMI shock from what you just said.$N$\n");
       afar("You go into TMI shock, and hope #TN# feels bad about it, even from afar.$N$\n", "From afar, you sense #MN# go into TMI shock.  Rock on!$N$\n");
    }
}

int
cmd_tmi(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
