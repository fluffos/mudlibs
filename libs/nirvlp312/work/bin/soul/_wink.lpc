inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wink suggestively.$N$\n", "#MN# winks suggestively.$N$\n");
       target("You wink suggestively at #TN#.$N$\n", "#MN# winks suggestively at #TN#.$N$\n", "#MN# winks suggestively at you.$N$\n");
       afar("You wink suggestively at #TN# from afar.$N$\n", "#MN# winks suggestively at you from afar.$N$\n");
    }
}

int
cmd_wink(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
