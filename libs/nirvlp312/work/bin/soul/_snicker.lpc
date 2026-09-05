inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You snicker.$N$\n", "#MN# snickers.$N$\n");
       target("You snicker at #TN#.$N$\n", "#MN# snickers at #TN#.$N$\n", "#MN# snickers at you.$N$\n");
       afar("You snicker at #TN# from afar.$N$\n", "#MN# snickers at you from afar.$N$\n");
    }
}

int
cmd_snicker(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
