inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shudder uncontrollably.\n", "#MN# shudders uncontrollably.\n");
       target("You shudder uncontrollably at #TN#.\n", "#MN# shudders uncontrollably at #TN#.\n", "#MN# shudders uncontrollably at you.\n");
       afar("You shudder at #TN# from afar.\n", "#MN# shudders at you from afar.\n");
    }
}

int
cmd_shudder(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
