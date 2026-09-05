inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You applaud wholeheartedly.$N$\n", "#MN# applauds wholeheartedly.$N$\n");
       target("You applaud #TN# wholeheartedly.$N$\n", "#MN# applauds #TN# wholeheartedly.$N$\n", "#MN# applauds you wholeheartedly.$N$\n");
       afar("You applaud #TN# wholeheartedly from afar.$N$\n", "#MN# applauds you wholeheartedly from afar.$N$\n");
    }
}

int
cmd_applaud(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
