inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look $HC$very$N$ afraid.\n", "#MN# looks $HC$very$N$ afraid.\n");
       target("You ask #TN# if #TS# is afraid.\n", "#MN# accuses #TN# of being afraid.\n", "#MN# accuses you of being afraid.\n");
       afar("You ask #TN# if #TS# is afraid from afar.\n", "#MN# accuses you of being afraid from afar.\n");
    }
}

int
cmd_afraid(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
