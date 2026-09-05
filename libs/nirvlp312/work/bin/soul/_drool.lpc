inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You drool!\n", "#MN# drools!\n");
       target("You drool all over #TN#!\n", "#MN# drools all over #TN#!\n", "#MN# drools all over you!\n");
       afar("You drool all over #TN# from afar!\n", "#MN# drools all over you from afar!\n");
    }
}

int
cmd_drool(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
