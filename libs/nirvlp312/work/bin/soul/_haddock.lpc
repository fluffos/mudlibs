inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You twirl A haddock (wielded) around your body with deadly grace.\n", "#MN# twirls A haddock (wielded) around #MP# body with deadly grace.\n");
       target("You whack #TN# over #TP# head with a dead haddock.\n", "#MN# whacks #TN# over #TP# head with a dead haddock.\n", "What the hell?  #MN# whacked you over your head with a dead haddock!\n");
       afar("You whack #TN# over #TP# head with a dead haddock from afar.  (somehow)\n", "#MN# whacks you over your head with a dead haddock from afar.  (somehow)\n");
    }
}

int
cmd_haddock(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
