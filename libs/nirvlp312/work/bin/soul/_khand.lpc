inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You stare yourself in the eyes as you softly kiss your hand.$N$\n", "#MN# stares #MO#self in the eyes as #MS# softly kisses #MP# hand.$N$\n");
       target("You stare #TN# in the eyes as you softly kiss #TP# hand.$N$\n", "#MN# stares #TN# in the eyes as #MS# softly kisses #TP# hand.$N$\n", "#MN# stares you in the eyes as #MS# softly kisses your hand.$N$\n");
       afar("You stare #TN# in the eyes as you softly kiss #TP# hand from afar.#RET#Who knew lips reached THAT far??$N$\n", "#MN# stares you in the eyes as #MS# softly kisses your hand from afar.#RET#Who knew lips reached THAT far??$N$\n");
    }
}

int
cmd_khand(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
