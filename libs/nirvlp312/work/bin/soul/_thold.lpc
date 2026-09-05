inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You hold yourself damn tight!$N$\n", "#MN# holds #MO#self damn tight!$N$\n");
       target("You hold #TN# damn tight!$N$\n", "#MN# holds #TN# damn tight!$N$\n", "#MN# holds you damn tight!$N$\n");
       afar("You hold #TN# damn tight from afar!$N$\n", "#MN# holds you damn tight from afar!$N$\n");
    }
}

int
cmd_thold(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
