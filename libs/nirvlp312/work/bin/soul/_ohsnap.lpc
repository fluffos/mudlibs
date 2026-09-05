inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You utter: \"OH SNAP!\"$N$\n", "#MN# utters: \"OH SNAP!\"$N$\n");
       target("You point at #TN# and utter: \"OH SNAP!\"$N$\n", "#MN# points at #TN# and utters: \"OH SNAP!\"$N$\n", "#MN# points at you and utters: \"OH SNAP!\"$N$\n");
       afar("You point at #TN# from afar and utter: \"OH SNAP!\"$N$\n", "#MN# points at you from afar and utters: \"OH SNAP!\"$N$\n");
    }
}

int
cmd_ohsnap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
