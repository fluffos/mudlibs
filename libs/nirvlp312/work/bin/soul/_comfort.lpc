inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You comfort yourself.$N$\n", "#MN# comforts #MO#self.$N$\n");
       target("You comfort #TN#.$N$\n", "#MN# comforts #TN#.$N$\n", "#MN# comforts you.$N$\n");
       afar("You comfort #TN# from afar.$N$\n", "#MN# comforts you from afar.$N$\n");
    }
}

int
cmd_comfort(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
