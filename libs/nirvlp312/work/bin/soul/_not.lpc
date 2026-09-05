inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You annoyingly announce to everybody: 'NOT!'\n", "#MN# annoyingly announces to everybody: 'NOT!'\n");
       target("You annoyingly announce to #TN#: 'NOT!'\n", "#MN# annoyingly announces to #TN#: 'NOT!'\n", "#MN# annoyingly announces to you: 'NOT!'\n");
       afar("From afar, you annoyingly announce to #TN#: 'NOT!'\n", "From afar, #MN# annoyingly announces to you: 'NOT!'\n");
    }
}

int
cmd_not(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
