inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You hold yourself.$N$\n", "#MN# holds #MO#self.$N$\n");
       target("You hold #TN#.$N$\n", "#MN# holds #TN#.$N$\n", "#MN# holds you.$N$\n");
       afar("You hold #TN# from afar.$N$\n", "#MN# holds you from afar.$N$\n");
    }
}

int
cmd_hold(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
