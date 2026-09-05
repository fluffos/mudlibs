inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You growl.$N$\n", "#MN# growls.$N$\n");
       target("You growl at #TN#.$N$\n", "#MN# growls at #TN#.$N$\n", "#MN# growls at you.$N$\n");
       afar("You growl at #TN# from afar.$N$\n", "#MN# growls at you from afar.$N$\n");
    }
}

int
cmd_growl(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
