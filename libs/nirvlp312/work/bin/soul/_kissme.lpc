inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: Kiss me I'm $G$Irish$N$!$N$\n", "#MN# says: Kiss me I'm $G$Irish$N$!$N$\n");
       target("You say: Kiss me I'm $G$Irish$N$ to #TN#!$N$\n", "#MN# says: Kiss me I'm $G$Irish$N$ to #TN#!$N$\n", "#MN# says: Kiss me I'm $G$Irish$N$ to you!$N$\n");
       afar("You tell #TN# from afar: Kiss me I'm $G$Irish$N$!$N$\n", "#MN# tells you from afar: Kiss me I'm $G$Irish$N$!$N$\n");
    }
}

int
cmd_kissme(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
