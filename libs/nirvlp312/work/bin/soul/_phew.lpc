inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"Phew, that was close!\"$N$\n", "#MN# says, \"Phew, that was close!\"$N$\n");
       target("You say to #TN#, \"Phew, that was close!\"$N$\n", "#MN# says to #TN#, \"Phew, that was close!\"$N$\n", "#MN# says to you, \"Phew, that was close!\"$N$\n");
       afar("You yell at #TN#, \"Phew, that was close!\"$N$\n", "#MN# yells at you, \"Phew, that was close!\"$N$\n");
    }
}

int
cmd_phew(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
