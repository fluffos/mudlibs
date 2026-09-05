inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You groan loudly.$N$\n", "#MN# groans loudly.$N$\n");
       target("You groan loudly at #TN#.$N$\n", "#MN# groans loudly at #TN#.$N$\n", "#MN# groans loudly at you.$N$\n");
       afar("You groan loudly at #TN# from afar.$N$\n", "#MN# groans loudly at you from afar.$N$\n");
    }
}

int
cmd_groan(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
