inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You nod your head in agreement.$N$\n", "#MN# nods in agreement.$N$\n");
       target("You nod in agreement with #TN#.$N$\n", "#MN# nods in agreement with #TN#.$N$\n", "#MN# nods in agreement with you.$N$\n");
       afar("You nod in agreement with #TN# from afar.$N$\n", "#MN# nods in agreement with you from afar.$N$\n");
    }
}

int
cmd_agree(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
