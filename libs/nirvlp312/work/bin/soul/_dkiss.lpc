inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You foolishly try to deeply kiss yourself. You need to get a mate!$N$\n", "#MN# foolishly tries to deeply kiss #MO#self. #MN# needs a mate!$N$\n");
       target("You give #TN# a deep kiss, leaving #TO# gasping for air. Wow!$N$\n", "#MN# gives #TN# a deep kiss, leaving #TO# gasping for air. Wow!$N$\n", "#MN# gives you a deep kiss, leaving you gasping for air. Wow!$N$\n");
       afar("You give #TN# a deep kiss, leaving #TO# gasping for air from afar. Wow!$N$\n", "#MN# gives you a deep kiss, leaving you gasping for air from afar. Wow!$N$\n");
    }
}

int
cmd_dkiss(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
