inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You rip your own sack off like a paper towel!   EEEAGH!\n", "#MN# rips #MP# sack off like a paper towel!\n");
       target("You rip #TN#'s sack off like a paper towel!\n", "#MN# rips #TN#'s sack off like a paper towel!\n", "#MN# rips your sack off like a paper towel!\n");
       afar("You magically rip off #TN#'s sack off like a paper towel.\n", "#MN# magically rips off your sack like a paper towel.\n");
    }
}

int
cmd_ripsack(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
