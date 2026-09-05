inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wince.\n", "#MN# winces.\n");
       target("You wince at #TN#.\n", "#MN# winces at #TN#.\n", "#MN# winces at you.\n");
       afar("You wince at #TN# from afar.\n", "#MN# winces at you from afar.\n");
    }
}

int
cmd_wince(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
