inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You worship before the feet of everyone around you.$N$\n", "#MN# worships before the feet of everyone around #MO#.$N$\n");
       target("You worship before the feet of #TN#.$N$\n", "#MN# worships at the feet of #TN#.$N$\n", "#MN# worships before your feet.$N$\n");
       afar("You worship #TN# from afar.$N$\n", "#MN# worships you from afar.$N$\n");
    }
}

int
cmd_worship(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
