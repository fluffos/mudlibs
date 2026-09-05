inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ask, \"What do you want to do tonight, Brain?\"$N$\n", "$MN$ asks, \"What do you want to do tonight, Brain?\"$N$\n");
       target("You ask $TN$, \"What do you want to do tonight, Brain?\"$N$\n", "$MN$ asks $TN$, \"What do you want to do tonight, Brain?\"$N$\n", "$MN$ asks you, \"What do you want to do tonight, Brain?\"$N$\n");
       afar("From afar, you ask $TN$, \"What do you want to do tonight, Brain?\"$N$\n", "From afar, $MN$ asks you, \"What do you want to do tonight, Brain?\"$N$\n");
    }
}

int
cmd_pinky(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
