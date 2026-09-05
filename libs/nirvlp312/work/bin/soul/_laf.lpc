inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You laf.$N$\n", "#MN# lafs.$N$\n");
       target("You laf at #TN#.$N$\n", "#MN# lafs at #TN#.$N$\n", "#MN# lafs at you.$N$\n");
       afar("You laf at #TN# from afar.$N$\n", "#MN# lafs at you from afar.$N$\n");
    }
}

int
cmd_laf(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
