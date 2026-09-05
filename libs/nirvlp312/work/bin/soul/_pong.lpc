inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pong yourself.$N$\n", "#MN# pongs #MO#self.$N$\n");
       target("You pong #TN#!$N$\n", "#MN# pongs #TN#!$N$\n", "#MN# pongs you!$N$\n");
       afar("You pong #TN# from afar!$N$\n", "#MN# pongs you from afar!$N$\n");
    }
}

int
cmd_pong(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
