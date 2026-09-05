inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Ah, don't take it so hard.$N$\n", "#MN# pouts.$N$\n");
       target("You pout on #TN#'s shoulder.$N$\n", "#MN# pouts on #TN#'s shoulder.$N$\n", "#MN# pouts on your shoulder.$N$\n");
       afar("You pout on #TN#'s shoulder from afar.$N$\n", "#MN# pouts on your shoulder from afar.$N$\n");
    }
}

int
cmd_pout(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
