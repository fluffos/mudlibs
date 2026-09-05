inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You melt.$N$\n", "#MN# melts.$N$\n");
       target("You melt in #TN#'s arms.$N$\n", "#MN# melts in #TN#'s arms.$N$\n", "#MN# melts in your arms.$N$\n");
       afar("You melt in #TN#'s arms from afar.$N$\n", "#MN# melts in your arms from afar.$N$\n");
    }
}

int
cmd_melt(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
