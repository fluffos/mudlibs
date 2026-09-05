inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You tilt your head in puzzlement.\n", "#MN# tilts #MP# head in puzzlement.\n");
       target("You tilt your head in puzzlement at #TN#.\n", "#MN# tilts #MP# head in puzzlement at #TN#.\n", "#MN# tilts #MP# head in puzzlement at you.\n");
       afar("You tilt your head in puzzlement at #TN# from afar.\n", "#MN# tilts #MP# head in puzzlement at you from afar.\n");
    }
}

int
cmd_tilt(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
