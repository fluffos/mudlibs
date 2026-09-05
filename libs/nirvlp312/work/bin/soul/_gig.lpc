inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go \"Gigitty gigitty goo!\"$N$\n", "#MN# goes \"Gigitty gigitty goo!\"$N$\n");
       target("You go \"Gigitty gigitty goo!\" to #TN#.$N$\n", "#MN# goes \"Gigitty gigitty goo!\" to #TN#.$N$\n", "#MN# goes \"Gigitty gigitty goo!\" to you.$N$\n");
       afar("From afar, you go \"Gigitty gigitty goo!\" to #TN#.$N$\n", "From afar, #MN# goes \"Gigitty gigitty goo!\" to you.$N$\n");
    }
}

int
cmd_gig(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
