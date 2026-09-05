inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Hic!$N$\n", "#MN# hiccups.$N$\n");
       target("You hiccup at #TN#.$N$\n", "#MN# hiccups at #TN#.$N$\n", "#MN# hiccups at you.$N$\n");
       afar("You hiccup at #TN# from afar.$N$\n", "#MN# hiccups at you from afar.$N$\n");
    }
}

int
cmd_hiccup(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
