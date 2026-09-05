inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("With a smarmy smirk, you say, \"Wouldn't wanna be ya!\"$N$\n", "With a smarmy smirk, $MN$ says, \"Wouldn't wanna be ya!\"$N$\n");
       target("With a smarmy smirk at #TN#, you say, \"Wouldn't wanna be ya!\"$N$\n", "With a smarmy smirk at #TN#, #MN# says, \"Wouldn't wanna be ya!\"$N$\n", "With a smarmy smirk at you, #MN# says, \"Wouldn't wanna be ya!\"$N$\n");
       afar("From afar, you confide to $TN$ that you really wouldn't want to be #TO#.$N$\n", "From afar, #MN# confides to you that #TS# really wouldn't want to be you.$N$\n");
    }
}

int
cmd_beya(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
