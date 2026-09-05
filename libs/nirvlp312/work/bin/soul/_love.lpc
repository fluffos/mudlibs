inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tell yourself how you really feel!$N$\n", "#MN# whispers sweet words of love...to #MO#self!$N$\n");
       target("You tell #TN# how you really feel.$N$\n", "#MN# whispers sweet words of love to #TN#.$N$\n", "#MN# whispers sweet words of love to you.$N$\n");
       afar("You tell #TN# how you really feel from afar.$N$\n", "#MN# whispers sweet words of $R$love$N$ to you from afar!$N$\n");
    }
}

int
cmd_love(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
