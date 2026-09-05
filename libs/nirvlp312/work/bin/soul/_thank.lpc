inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You thank yourself.$N$\n", "#MN# thanks #MO#self.$N$\n");
       target("You thank #TN#.$N$\n", "#MN# thanks #TN#.$N$\n", "#MN# thanks you.$N$\n");
       afar("You thank #TN# from afar.$N$\n", "#MN# thanks you from afar.$N$\n");
    }
}

int
cmd_thank(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
