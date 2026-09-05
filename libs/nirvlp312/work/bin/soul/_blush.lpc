inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("Your cheeks are $R$burning$N$.$N$\n", "#MN# $R$blushes$N$.$N$\n");
       target("You $R$blush$N$ at #TN#.$N$\n", "#MN# $R$blushes$N$ at #TN#.$N$\n", "#MN# $R$blushes$N$ at you.$N$\n");
       afar("You $R$blush$N$ at #TN# from afar.$N$\n", "#MN# $R$blushes$N$ at you from afar.$N$\n");
    }
}

int
cmd_blush(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
