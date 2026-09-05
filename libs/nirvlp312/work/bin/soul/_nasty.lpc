inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: $Y$N*A*S*T*Y$N$ !!$N$\n", "#MN# goes: $Y$N*A*S*T*Y$N$ !!$N$\n");
       target("You turn to #TN# and go: $Y$N*A*S*T*Y$N$ !!$N$\n", "#MN# turns to #TN# and goes: $Y$N*A*S*T*Y$N$ !!$N$\n", "#MN# turns to you and goes: $Y$N*A*S*T*Y$N$ !!$N$\n");
       afar("From afar, you tell #TN#: $Y$N*A*S*T*Y$N$ !!$N$\n", "From afar, #MN# tells you: $Y$N*A*S*T*Y$N$ !!$N$\n");
    }
}

int
cmd_nasty(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
