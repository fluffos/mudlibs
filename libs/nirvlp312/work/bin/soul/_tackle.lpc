inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You attempt to tackle yourself and fall on the ground.$N$\n", "#MN# attempts to tackle #MO#self and falls on the ground.$N$\n");
       target("You tackle #TN# to the ground!$N$\n", "#MN# tackles #TN# to the ground!$N$\n", "#MN# tackles you to the ground!$N$\n");
       afar("You tackle #TN# to the ground from afar!$N$\n", "#MN# tackles you to the ground from afar!$N$\n");
    }
}

int
cmd_tackle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
