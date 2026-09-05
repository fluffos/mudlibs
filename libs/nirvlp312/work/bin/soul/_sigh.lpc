inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sigh deeply.$N$\n", "#MN# sighs deeply.$N$\n");
       target("You sigh deeply at #TN#.$N$\n", "#MN# sighs deeply at #TN#.$N$\n", "#MN# sighs deeply at you.$N$\n");
       afar("You sigh deeply at #TN# from afar.$N$\n", "#MN# sighs deeply at you from afar.$N$\n");
    }
}

int
cmd_sigh(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
