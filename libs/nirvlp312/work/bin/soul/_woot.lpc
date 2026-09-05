inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You victoriously raise your arms and yell: \"Woot!\"$N$\n", "#MN# victoriously raises #MP# arms and yells: \"Woot!\"$N$\n");
       target("You victoriously raise your arms and give #TN# a loud \"Woot!\"$N$\n", "#MN# victoriously raises #MP# arms and gives #TN# a loud \"Woot!\"$N$\n", "#MN# victoriously raises #MP# arms and gives you a loud \"Woot!\"$N$\n");
       afar("You victoriously raise your arms and give #TN# a loud \"Woot!\"$N$\n", "You somehow sense that #MN# is victoriously raising #MP# arms and yelling \"Woot!\"$N$\n");
    }
}

int
cmd_woot(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
