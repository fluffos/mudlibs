inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cheer enthusiastically!$N$\n", "#MN# cheers enthusiastically!$N$\n");
       target("You cheer enthusiastically for #TN#!$N$\n", "#MN# cheers enthusiastically for #TN#!$N$\n", "#MN# cheers enthusiastically for you!$N$\n");
       afar("You cheer enthusiastically for #TN# from afar!$N$\n", "#MN# cheers enthusiastically for you from afar!$N$\n");
    }
}

int
cmd_cheer(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
