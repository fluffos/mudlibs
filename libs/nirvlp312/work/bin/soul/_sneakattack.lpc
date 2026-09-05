inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yell: \"SNEAK ATTACK!\"$N$\n", "#MN# yells: \"SNEAK ATTACK!\"$N$\n");
       target("You yell at #TN#: \"SNEAK ATTACK!\"$N$\n", "#MN# yells at #TN#: \"SNEAK ATTACK!\"$N$\n", "#MN# yells at you: \"SNEAK ATTACK!\"$N$\n");
       afar("You yell at #TN# from afar: \"SNEAK ATTACK!\"$N$\n", "#MN# yells at you from afar: \"SNEAK ATTACK!\"$N$\n");
    }
}

int
cmd_sneakattack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
