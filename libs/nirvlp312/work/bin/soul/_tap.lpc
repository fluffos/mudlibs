inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tap your foot impatiently.\n", "#MN# taps #MP# foot impatiently.\n");
       target("You tap your foot impatiently at #TN#.\n", "#MN# taps #MP# foot impatiently at #TN#.\n", "#MN# taps #MP# foot impatiently at you.\n");
       afar("You tap your foot impatiently at #TN# from afar.\n", "#MN# taps #MP# foot impatiently at you from afar.\n");
    }
}

int
cmd_tap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
