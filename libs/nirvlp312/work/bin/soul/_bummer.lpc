inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: Bummer!$N$\n", "#MN# goes: Bummer!$N$\n");
       target("You turn to #TN# and go: Bummer!$N$\n", "#MN# turns to #TN# and goes: Bummer!$N$\n", "#MN# turns to you and goes: Bummer!$N$\n");
       afar("From afar, you tell #TN#: Bummer!$N$\n", "From afar, #MN# tells you: Bummer!$N$\n");
    }
}

int
cmd_bummer(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
