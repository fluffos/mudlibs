inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"The same thing we do every night, Pinky.  Try to take over the world!\"$N$\n", "#MN# says, \"The same thing we do every night, Pinky.  Try to take over the world!\"$N$\n");
       target("You tell #TN#, \"The same thing we do every night, Pinky.  Try to take over the world!\"$N$\n", "#MN# tells #TN#, \"The same thing we do every night, Pinky.  Try to take over the world!\"$N$\n", "#MN# tells you, \"The same thing we do every night, Pinky.  Try to take over the world!\"$N$\n");
       afar("From afar, you tell #TN#, \"The same thing we do every night, Pinky.  Try to take over the world!\"$N$\n", "From afar, #MN# tells you, \"The same thing we do every night, Pinky.  Try to take over the world!\"$N$\n");
    }
}

int
cmd_brain(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
