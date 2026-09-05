inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"$G$High$N$\".$N$\n", "#MN# says, \"$G$High$N$\".$N$\n");
       target("You say, \"$G$High$N$\" to #TN#.$N$\n", "#MN# says, \"$G$High$N$\" to #TN#.$N$\n", "#MN# says, \"$G$High$N$\" to you.$N$\n");
       afar("You say, \"$G$High$N$\" to #TN# from afar.$N$\n", "#MN# says, \"$G$High$N$\" to you from afar.$N$\n");
    }
}

int
cmd_high(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
