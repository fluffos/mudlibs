inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tease everyone in the room.\n", "#MN# teases everyone in the room.\n");
       target("You tease #TN#.\n", "#MN# teases #TN#.\n", "#MN# teases you.\n");
       afar("You tease #TN# from afar.\n", "#MN# teases you from afar.\n");
    }
}

int
cmd_tease(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
