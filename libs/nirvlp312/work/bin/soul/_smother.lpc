inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You smother yourself with kisses!$N$\n", "#MN# smothers #MO#self with kisses, leaving #MO#self happily out of breath!\n");
       target("You smother #TN# with kisses, leaving #TO# happily out of breath!$N$\n", "#MN# smothers #TN# with kisses, leaving #TO# happily out of breath!$N$\n", "#MN# smothers you with kisses, leaving you happily out of breath!$N$\n");
       afar("You smother #TN# with kisses, leaving #TO# happily out of breath from afar!$N$\n", "#MN# smothers you with kisses, leaving you happily out of breath from afar!$N$\n");
    }
}

int
cmd_smother(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
