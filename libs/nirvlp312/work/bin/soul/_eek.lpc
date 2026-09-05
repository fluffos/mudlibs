inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You place your hands over your ears and scream, 'EEEK!'\n", "#MN# places #MP# hands over #MP# ears and screams, 'EEEK!'\n");
       target("You jump into #TN#'s arms screaming, 'EEEK!'\n", "#MN# jumps into #TN#'s arms screaming, 'EEEK!'\n", "#MN# jumps into your arms screaming, 'EEEK!'\n");
       afar("You scream, 'EEEK!' at #TN# from afar.\n", "#MN# screams, 'EEEK!' at you from afar.\n");
    }
}

int
cmd_eek(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
