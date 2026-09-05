inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You roll your eyes and say, \"Duh!\"\n", "#MN# rolls #MP# eyes and says, \"Duh!\"\n");
       target("You rolls your eyes at #TN# and say, \"Duh!\"\n", "#MN# rolls #MP# eyes at #TN# and says, \"Duh!\"\n", "#MN# rolls #MP# eyes at you and says, \"Duh!\"\n");
       afar("You roll your eyes at #TN# from afar and yell, \"Duh!\"\n", "#MN# rolls #MP# eyes at you from afar and yells, \"Duh!\"\n");
    }
}

int
cmd_duh(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
