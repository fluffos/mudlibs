inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You grovel.$N$\n", "#MN# grovels.$N$\n");
       target("You grovel at #TN#.$N$\n", "#MN# grovels at #TN#.$N$\n", "#MN# grovels at you.$N$\n");
       afar("You grovel at #TN# from afar.$N$\n", "#MN# grovels at you from afar.$N$\n");
    }
}

int
cmd_grovel(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
