inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chant, \"spaghetti! spaghetti! spaghetti! spaghetti!\"$N$\n", "#MN# chants, \"spaghetti! spaghetti! spaghetti! spaghetti!\"$N$\n");
       target("You chant to #TN#, \"spaghetti! spaghetti! spaghetti! spaghetti!\"$N$\n", "#MN# chants to #TN#, \"spaghetti! spaghetti! spaghetti! spaghetti!\"$N$\n", "#MN# chants to you, \"spaghetti! spaghetti! spaghetti! spaghetti!\"$N$\n");
       afar("You chant to #TN# from afar, \"spaghetti! spaghetti! spaghetti! spaghetti!\"$N$\n", "#MN# chants to you from afar, \"spaghetti! spaghetti! spaghetti! spaghetti!\"$N$\n");
    }
}

int
cmd_spaghetti(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
