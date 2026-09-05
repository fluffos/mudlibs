inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You glare stonily.$N$\n", "#MN# glares stonily.$N$\n");
       target("You glare stonily at #TN#.$N$\n", "#MN# glares stonily at #TN#.$N$\n", "#MN# glares stonily at you.$N$\n");
       afar("You glare stonily at #TN# from afar.$N$\n", "#MN# glares stonily at you from afar.$N$\n");
    }
}

int
cmd_glare(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
