inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You moon everyone in the room!$N$\n", "#MN# moons everyone in the room!$N$\n");
       target("You pull your pants down and moon #TN#.$N$\n", "#MN# pulls #MP# pants down and moons #TN#.$N$\n", "#MN# pulls #MP# pants down and moons you!$N$\n");
       afar("You pull your pants down and moon #TN# from afar!$N$\n", "#MN# pulls #MP# pants down and moons you from afar!$N$\n");
    }
}

int
cmd_moon(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
