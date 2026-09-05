inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You do the $HW$skeleton$N$ dance!$N$\n", "#MN# does the $HW$skeleton$N$ dance!$N$\n");
       target("You do the $HW$skeleton$N$ dance for #TN#!$N$\n", "#MN# does the $HW$skeleton$N$ dance for #TN#!$N$\n", "#MN# does the $HW$skeleton$N$ dance for you!$N$\n");
       afar("You do the $HW$skeleton$N$ dance for #TN# from afar!$N$\n", "#MN# does the $HW$skeleton$N$ dance for you from afar!$N$\n");
    }
}

int
cmd_skdance(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
