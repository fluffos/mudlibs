inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shake your head.$N$\n", "#MN# shakes #MP# head.$N$\n");
       target("You shake your head at #TN#.$N$\n", "#MN# shakes #MP# head at #TN#.$N$\n", "#MN# shakes #MP# head at you.$N$\n");
       afar("You shake your head at #TN# from afar.$N$\n", "#MN# shakes #MP# head at you from afar.$N$\n");
    }
}

int
cmd_shake(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
