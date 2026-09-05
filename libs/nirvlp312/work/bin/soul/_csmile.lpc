inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You crack a smile.$N$\n", "#MN# cracks a smile.$N$\n");
       target("You crack a smile at #TN#.$N$\n", "#MN# cracks a smile at #TN#.$N$\n", "#MN# cracks a smile at you.$N$\n");
       afar("You crack a smile at #TN# from afar.$N$\n", "#MN# cracks a smile at you from afar.$N$\n");
    }
}

int
cmd_csmile(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
