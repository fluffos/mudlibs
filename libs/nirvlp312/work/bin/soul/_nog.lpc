inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You nog.$N$\n", "#MN# nogs.$N$\n");
       target("You nog at #TN#.$N$\n", "#MN# nogs at #TN#.$N$\n", "#MN# nogs at you.$N$\n");
       afar("You nog at #TN# from afar.$N$\n", "#MN# nogs at you from afar.$N$\n");
    }
}

int
cmd_nog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
