inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You rub your hands together excitedly.$N$\n", "#MN# rubs #MP# hands together excitedly.$N$\n");
       target("You rub your hands together excitedly at #TN#.$N$\n", "#MN# rubs #MP# hands together excitedly at #TN#.$N$\n", "#MN# rubs #MP# hands together excitedly at you.$N$\n");
       afar("You rub your hands together excitedly at #TN# from afar.$N$\n", "#MN# rubs #MP# hands together excitedly at you from afar.$N$\n");
    }
}

int
cmd_rubhands(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
