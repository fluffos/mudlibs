inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wonder aloud, \"Pinky, are you pondering what I'm pondering?\"$N$\n", "#MN# asks nobody in particular, \"Pinky, are you pondering what I'm pondering?\"$N$\n");
       target("You turn to #TN# and ask #TO#, \"Pinky, are you pondering what I'm pondering?\"$N$\n", "#MN# turns to #TN# and asks #TO#, \"Pinky, are you pondering what I'm pondering?\"$N$\n", "#MN# turns to you and asks, \"Pinky, are you pondering what I'm pondering?\"$N$\n");
       afar("From afar, you turn to #TN# and ask #TO#, \"Pinky, are you pondering what I'm pondering?\"$N$\n", "From afar, #MN# turns to you and asks, \"Pinky, are you pondering what I'm pondering?\"$N$\n");
    }
}

int
cmd_brain2(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
