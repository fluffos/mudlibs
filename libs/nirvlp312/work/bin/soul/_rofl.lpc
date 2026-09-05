inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You roll on the floor laughing!$N$\n", "#MN# rolls on the floor laughing!$N$\n");
       target("You roll on the floor laughing at #TN#!$N$\n", "#MN# rolls on the floor laughing at #TN#!$N$\n", "#MN# rolls on the floor laughing at you!$N$\n");
       afar("From afar, you roll on the floor laughing at #TN#!$N$\n", "From afar, #MN# rolls on the floor laughing at you!$N$\n");
    }
}

int
cmd_rofl(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
