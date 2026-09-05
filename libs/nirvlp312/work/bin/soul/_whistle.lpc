inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You whistle appreciatively!$N$\n", "#MN# whistles appreciately!$N$\n");
       target("You whistle appreciatively for #TN#!$N$\n", "#MN# whistles appreciatively for #TN#!$N$\n", "#MN# whistles appreciatively for you!$N$\n");
       afar("You whistle appreciatively for #TN# from afar.$N$\n", "#MN# whistles appreciatively for you from afar.$N$\n");
    }
}

int
cmd_whistle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
