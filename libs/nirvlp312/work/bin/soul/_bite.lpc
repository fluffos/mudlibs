inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You bite yourself in frustration.\n", "#MN# bites #MO#self in frustration.\n");
       target("You bite #TN#.\n", "#MN# bites #TN#.\n", "#MN# bites you.\n");
       afar("You bite #TN# from afar.\n", "#MN# bites you from afar.\n");
    }
}

int
cmd_bite(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
