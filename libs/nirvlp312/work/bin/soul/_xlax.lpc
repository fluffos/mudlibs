inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You roll your eyes and say, \"Smooth move, $HW$X-LAX$N$.\"$N$\n", "#CMN# rolls #MP# eyes and say, \"Smooth move, $HW$X-LAX$N$.\"$N$\n");
       target("You look at #CTN# and go, \"Smooth move, $HW$X-LAX$N$!\"$N$\n", "#CMN# looks at #CTN# and goes, \"Smooth move, $HW$X-LAX$N$!\"$N$\n", "#CMN# looks at you and goes, \"Smooth move, $HW$X-LAX$N$!\"$N$\n");
       afar("You look at #CTN# from afar and go, \"Smooth move, $HW$X-LAX$N$!\" $N$\n", "#CMN# looks at you from afar and goes, \"Smooth move, $HW$X-LAX$N$!\" $N$\n");
    }
}

int
cmd_xlax(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
