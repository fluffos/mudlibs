inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Nestle who?\n", "0\n");
       target("You nestle your head on #TN#'s chest.\n", "#MN# nestles #MP# head on #TN#'s chest.\n", "#MN# nestles #MP# head on your chest.\n");
       afar("You nestle your head on #TN#'s chest from afar.\n", "#MN# nestles #MP# head on your chest from afar.\n");
    }
}

int
cmd_nestle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
