inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You howl loudly at the moon!  H O W L!$N$\n", "#MN# howls loudly at the moon!  H O W L!$N$\n");
       target("You howl loudly at #TN#!  H O W L!$N$\n", "#MN# howls loudly at #TN#!  H O W L!$N$\n", "#MN# howls loudly at you!  H O W L!$N$\n");
       afar("You howl loudly at #TN# from afar!  H O W L!$N$\n", "#MN# howls loudly at you from afar!  H O W L!$N$\n");
    }
}

int
cmd_howl(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
