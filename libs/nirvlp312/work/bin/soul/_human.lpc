inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ask nobody in particular, \"Are you classified as human?\"$N$\n", "#MN# asks nobody in particular, \"Are you classified as human?\"$N$\n");
       target("You ask #TN#, \"Are you classified as human?\"#RET##TN# answers, \"Uh, negative.  I am a meat popsicle.\"$N$\n", "#MN# asks #TN#, \"Are you classified as human?\"#RET##TN# answers, \"Uh, negative.  I am a meat popsicle.\"$N$\n", "#MN# asks you, \"Are you classified as human?\"#RET#You answer, \"Uh, negative.  I am a meat popsicle.\"$N$\n");
       afar("From afar, you ask #TN#, \"Are you classified as human?\"#RET##TN# answers, \"Uh, negative.  I am a meat popsicle.\"$N$\n", "From afar, #MN# asks you, \"Are you classified as human?\"#RET#You answer, \"Uh, negative.  I am a meat popsicle.\"$N$\n");
    }
}

int
cmd_human(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
