inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You hold up a finger and say, \"I'll be right back!\"\n", "#MN# holds up a finger and says, \"I'll be right back!\"\n");
       target("You hold up your finger to #TN# and say, \"I'll be right back!\"\n", "#MN# holds up a finger to #TN# and says, \"I'll be right back!\"\n", "#MN# holds up a finger to you and says, \"I'll be right back!\"\n");
       afar("You hold up a finger from afar and say, \"I'll be right back!\"\n", "#MN# holds up a finger to you from afar and says, \"I'll be right back!\"\n");
    }
}

int
cmd_brb(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
