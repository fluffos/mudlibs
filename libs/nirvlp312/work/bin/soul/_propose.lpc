inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Propose to whom?\n", "#MN# suddenly looks confused.\n");
       target("You get down on one knee and ask #TN# to marry you.\n", "#MN# gets down on one knee and asks #TN# to marry #MO#.\n", "#MN# gets down on one knee and asks you to marry #MO#.\n");
    }
}

int
cmd_propose(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
