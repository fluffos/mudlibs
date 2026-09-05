inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say 'FUCKING fear IT!'$N$\n", "#MN# says 'FUCKING fear IT!'$N$\n");
       target("You fucking fear #TN#!$N$\n", "#MN# fucking fears #TN#!$N$\n", "#MN# fucking fears you!$N$\n");
       afar("You fucking fear #TN#, from afar.$N$\n", "#MN# fucking fears you, from afar.$N$\n");
    }
}

int
cmd_ffear(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
