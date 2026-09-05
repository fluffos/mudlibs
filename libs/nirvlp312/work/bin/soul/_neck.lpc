inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You foolishly try to bite your own neck. What are you a contortionist?$N$\n", "#MN# foolishly tries to bite #MP# own neck.  #MN# must think #MS# is a contortionist!$N$\n");
       target("You lean closer to #TN# and bite #TP# neck lustily.$N$\n", "#MN# leans closer to #TN# and bites #TP# neck lustily.$N$\n", "#MN# leans closer and bites your neck lustily.  It feels very nice,#RET#sending shivers down your spine.$N$\n");
       afar("You lean closer and bite #TN#'s neck lustily from afar.$N$\n", "#MN# leans cloers and bites your neck lustily from afar.#RET#It feels very nice, sending shivers down your spine!$N$\n");
    }
}

int
cmd_neck(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
