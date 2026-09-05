inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You bow to your audience.$N$\n", "#MN# bows gracefully.\n");
       target("You bow to #TN#.$N$\n", "#MN# bows to #TN#.$N$\n", "#MN# bows to you.$N$\n");
       afar("You bow to #TN# from afar.$N$\n", "#MN# bows to you from afar.$N$\n");
    }
}

int
cmd_bow(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
