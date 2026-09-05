inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sulk.$N$\n", "#MN# sulks in the corner.$N$\n");
       target("You sulk at #TN#.$N$\n", "#MN# sulks at #TN#.$N$\n", "#MN# sulks at you.$N$\n");
       afar("You sulk at #TN# from afar.$N$\n", "#MN# sulks at you from afar.$N$\n");
    }
}

int
cmd_sulk(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
