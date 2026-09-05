inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tap your fingers together like Mr. Burns and say, $HR$\"Excellent!\"$N$\n", "#MN# taps #MP# fingers together like Mr. Burns and says, $HR$\"Excellent!\"$N$\n");
       target("You gaze at $HK$#TN#$N$ while you tap your fingers together like Mr. Burns and say, $HR$\"Excellent!\"$N$\n", "#MN# gazes at $HK$#TN#$N$ while #MS# taps #MP# fingers together like Mr. Burns and says, $HR$\"Excellent!\"$N$\n", "#MN# gazes at you while #MS# taps #MP# fingers together like Mr. Burns and says, $HR$\"Excellent!\"$N$\n");
       afar("You gaze at $HK$#TN#$N$ from afar while you tap your fingers together like Mr. Burns and say, $HR$\"Excellent!\"$N$\n", "#MN# gazes at you from afar while #MS# taps #MP# fingers together like Mr. Burns and says, $HR$\"Excellent!\"$N$\n");
    }
}

int
cmd_excellent(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
