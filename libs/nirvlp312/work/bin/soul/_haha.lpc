inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You point your finger and go, \"Ha ha!\"$N$\n", "#MN# points #MP# finger and goes, \"Ha ha!\"$N$\n");
       target("You point your finger at #TN# and go, \"Ha ha!\"$N$\n", "#MN# points #MP# finger at #TN# and goes, \"Ha ha!\"$N$\n", "#MN# points #MP# finger at you and goes, \"Ha ha!\"$N$\n");
       afar("From afar, you point your finger at #TN# and go, \"Ha ha!\"$N$\n", "From afar, #MN# points #MP# finger at you and goes, \"Ha ha!\"$N$\n");
    }
}

int
cmd_haha(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
