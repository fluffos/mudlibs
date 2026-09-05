inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ruffle your own hair playfully.$N$\n", "#MN# ruffles #MP# own hair playfully.$N$\n");
       target("You ruffle #TN#'s hair playfully.$N$\n", "#MN# ruffles #TN#'s hair playfully.$N$\n", "#MN# ruffles your hair playfully.$N$\n");
       afar("You ruffle #TN#'s hair playfully from afar.$N$\n", "#MN# ruffles your hair playfully from afar.$N$\n");
    }
}

int
cmd_ruffle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
