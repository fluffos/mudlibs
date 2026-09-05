inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You scratch your head.$N$\n", "#MN# scratches #MP# head.$N$\n");
       target("You scratch your head at #TN#.$N$\n", "#MN# scratches #MP# head at #TN#.$N$\n", "#MN# scratches #MP# head at you.$N$\n");
       afar("You scratch your head at #TN# from afar.$N$\n", "#MN# scratches #MP# head at you from afar.$N$\n");
    }
}

int
cmd_scratchhead(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
