inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ponder the situation.$N$\n", "#MN# ponders the situation.$N$\n");
       target("You ponder the meaning of #TN#.\n", "#MN# ponders the meaning of #TN#.\n", "#MN# ponders the meaning of YOU.\n");
       afar("You ponder the meaning of #TN# from afar.\n", "#MN# ponders the meaning of YOU from afar.\n");
    }
}

int
cmd_ponder(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
