inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tell everyone in the room to $Y$fuck off$N$!$N$\n", "#MN# tells everyone in the room to $Y$fuck off$N$!$N$\n");
       target("You tell #TN# to $Y$fuck off$N$!$N$\n", "#MN# tells #TN# to $Y$fuck off$N$!$N$\n", "#MN# tells you to $Y$fuck off$N$!$N$\n");
       afar("From afar, you tell #TN# to $Y$fuck off$N$!$N$\n", "From afar, #MN# tells you to $Y$fuck off$N$!$N$\n");
    }
}

int
cmd_foff(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
