inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You seem in desperate need of affection!!!$N$\n", "#MN# seems in desperate need of affection!!!$N$\n");
       target("You seem in desperate need of affection from #TN#.$N$\n", "#MN# seems in desperate need of affection from #TN#.$N$\n", "#MN# seems in desperate need of affection from you.$N$\n");
       afar("You seem in desperate need of affection from #TN# from afar.$N$\n", "From afar, #MN# seems in desperate need of affection from you!!!$N$\n");
    }
}

int
cmd_need(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
