inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You ask, 'sup Fred?$N$\n", "#MN# asks, 'sup Fred?$N$\n");
       target("You ask #TN#, 'sup Fred?$N$\n", "#MN# asks #TN#, 'sup Fred?$N$\n", "#MN# asks you, 'sup Fred?$N$\n");
       afar("You ask #TN# from afar, 'sup Fred?$N$\n", "#MN# asks you from afar, 'sup Fred?$N$\n");
    }
}

int
cmd_supf(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
