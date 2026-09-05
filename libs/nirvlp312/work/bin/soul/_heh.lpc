inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: Heh. - Just like Novowels!\n", "#MN# goes: Heh.\n");
       target("You look at #TN# and go: Heh.\n", "#MN# looks at #TN# and goes: Heh.\n", "#MN# looks at you and goes: Heh.\n");
       afar("To #TN# from afar, you go: Heh.\n", "From afar, #MN# goes: Heh.\n");
    }
}

int
cmd_heh(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
