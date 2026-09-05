inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You nod solemnly.$N$\n", "#MN# nods solemnly.$N$\n");
       target("You nod solemnly at #TN#.$N$\n", "#MN# nods solemnly at #TN#.$N$\n", "#MN# nods solemnly at you.$N$\n");
       afar("You nod solemnly at #TN# from afar.$N$\n", "#MN# nods solemnly at you from afar.$N$\n");
    }
}

int
cmd_nod(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
