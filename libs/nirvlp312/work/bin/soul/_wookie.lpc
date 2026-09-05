inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
      nontarget("You go: \"Graaggh naaahg WAUGH!\"\n", "#MN# goes: \"Graaggh naaahg WAUGH!\"\n");
       target("You look at #TN# and go: \"Graagh naaahg WAUGH!\"\n", "#MN# looks at #TN# and goes: \"Graaggh naaahg WAUGH!\"\n", "#MN# looks at you and goes: \"Graaggh naaahg WAUGH!\"\n");
       afar("You go: \"Graaggh naaahg WAUGH!\" to #TN# from afar.\n", "#MN# goes: \"Graaggh naaagh WAUGH!\" to you from afar.\n");
    }
}

int
cmd_wookie(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
