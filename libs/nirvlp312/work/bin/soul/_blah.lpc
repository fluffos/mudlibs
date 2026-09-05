inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: $HR$BLAH!!!!$N$\n", "#MN# goes: $HR$BLAH!!!!$N$\n");
       target("You look at #TN# and go: $HR$BLAH!!!!$N$\n", "#MN# looks at #TN# and goes: $HR$BLAH!!!!$N$\n", "#MN# looks at you and goes $HR$BLAH!!!!$N$\n");
       afar("From afar to #TN#, you go: $HR$BLAH!!!!$N$\n", "From afar, #MN# goes: $HR$BLAH!!!!$N$\n");
    }
}

int
cmd_blah(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
