inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You stare into space.$N$\n", "#MN# stares blankly.$N$\n");
       target("You stare deeply into #TN#'s eyes.$N$\n", "#MN# stares deeply into #TN#'s eyes.$N$\n", "#MN# stares deeply into your eyes.$N$\n");
       afar("You stare deeply into #TN#'s eyes from afar.$N$\n", "#MN# stares deeply into your eyes from afar.$N$\n");
    }
}

int
cmd_stare(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
