inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You snort loudly and feel much better!$N$\n", "#MN# snorts loudly!$N$\n");
       target("You snort loudly at #TN#!$N$\n", "#MN# snorts loudly at #TN#!$N$\n", "#MN# snorts loudly at you!$N$\n");
       afar("You snort at #TN# from afar!$N$\n", "#MN# snorts at you from afar!$N$\n");
    }
}

int
cmd_snort(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
