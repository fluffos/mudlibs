inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go \"BAM!\"$N$\n", "#MN# goes \"BAM!\"$N$\n");
       target("You look at #TN# and go \"BAM!\"$N$\n", "#MN# looks at #TN# and goes \"BAM!\"$N$\n", "#MN# looks at you and goes \"BAM!\"$N$\n");
       afar("[afar] You look at #TN# and go \"BAM!\"$N$\n", "[afar] #MN# looks at you and goes \"BAM!\"$N$\n");
    }
}

int
cmd_bam(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
