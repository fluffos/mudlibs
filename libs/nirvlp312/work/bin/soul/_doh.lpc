inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();

       nontarget("You go: \"D'oh!\"\n", "#MN# goes: \"D'oh!\"\n");
         target("You look at #TN# and go: \"D'oh!\"\n", "#MN# looks at #TN# and goes: \"D'oh!\"\n", "#MN# looks at you and goes: \"D'oh!\"\n");
       afar("You go: \"D'oh!\" to #TN# from afar.\n", "#MN# goes: \"D'oh!\" to you from afar.\n");
    }
}

int
cmd_doh(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
