inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You lick yourself.$N$\n", "#MN# licks #MO#self.$N$\n");
       target("You lick #TN#.$N$\n", "#MN# licks #TN#.$N$\n", "#MN# licks you.$N$\n");
       afar("You lick #TN# from afar.$N$\n", "#MN# licks you from afar.$N$\n");
    }
}

int
cmd_lick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
