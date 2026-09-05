inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You whap yourself upside the head!$N$\n", "#MN# whaps #MO#self upside the head!#RET#Strange.$N$\n");
       target("You whap #TN# upside the head!$N$\n", "#MN# whaps #TN# upside the head!$N$\n", "#TN# whaps you upside the head!$N$\n");
       afar("From afar, you whap #TN# upside the head!$N$\n", "From afar, #MN# whaps you upside the head!$N$\n");
    }
}

int
cmd_whap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
