inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You hop around like a little kid.\n", "#MN# hops around like a little kid.\n");
       target("You hop around #TN#.$N$\n", "#MN# hops around #TN#.$N$\n", "#MN# hops around you.$N$\n");
       afar("You hop around #TN# from afar.$N$\n", "#MN# hops around you from afar.$N$\n");
    }
}

int
cmd_hop(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
