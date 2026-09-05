inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Taunt who?\n", "#MN# looks confused.\n");
       target("You taunt #TN#, hoping to pick a fight.\n", "#MN# taunts #TN#, hoping to pick a fight.\n", "#MN# taunts you, wanting to pick a fight.\n");
       afar("You taunt #TN# from afar, hoping to pick a fight.\n", "#MN# taunts you from afar, hoping to pick a fight.\n");
    }
}

int
cmd_taunt(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
