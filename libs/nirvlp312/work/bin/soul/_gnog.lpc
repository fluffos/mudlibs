inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You guest nog.$N$\n", "#MN# guest nogs.$N$\n");
       target("You guest nog at #TN#.$N$\n", "#MN# guest nogs at #TN#.$N$\n", "#MN# guest nogs at you.$N$\n");
       afar("You guest nog at #TN# from afar.$N$\n", "#MN# guest nogs at you from afar.$N$\n");
    }
}

int
cmd_gnog(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
