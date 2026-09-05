inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You mutter something under your breath.$N$\n", "#MN# mutters something.$N$\n");
       target("You mutter about #TN# under your breath.$N$\n", "#MN# mutters about #TN#.$N$\n", "#MN# mutters about you.$N$\n");
       afar("0$N$\n", "0$N$\n");
    }
}

int
cmd_mutter(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
