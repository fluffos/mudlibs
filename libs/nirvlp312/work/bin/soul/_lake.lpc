inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You throw yourself into a nearby $B$lake$N$!$N$\n", "#MN# throws #MP#self into a nearby $B$lake$N$!$N$\n");
       target("You throw #TN# into a nearby $B$lake$N$!$N$\n", "#MN# throws #TN# into a nearby $B$lake$N$!$N$\n", "#MN# throws you into a nearby $B$lake$N$!$N$\n");
       afar("0$N$\n", "0$N$\n");
    }
}

int
cmd_lake(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
