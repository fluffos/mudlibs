inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pat yourself on the head.$N$\n", "#MN# pats #MO#self on the head.$N$\n");
       target("You pat #TN# on the head.$N$\n", "#MN# pats #TN# on the head.$N$\n", "#MN# pats you on the head.$N$\n");
       afar("You pat #TN# on the head from afar.$N$\n", "#MN# pats you on the head from afar.$N$\n");
    }
}

int
cmd_pat(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
