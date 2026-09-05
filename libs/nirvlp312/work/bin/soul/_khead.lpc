inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You caress your hair and kiss your forehead.$N$\n", "#MN# caresses #MP# hair and kisses #MP# forehead.$N$\n");
       target("You caress #TN#'s hair and kiss #TP# forehead.$N$\n", "#MN# caresses #TN#'s hair and kisses #TP# forehead.$N$\n", "#MN# caresses your hair and kisses your forehead.$N$\n");
       afar("You caress #TN#'s hair and kiss #TP# forehead from afar.$N$\n", "#MN# caresses your hair and kisses your forehead from afar.$N$\n");
    }
}

int
cmd_khead(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
