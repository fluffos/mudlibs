inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You spurn everyone in the room.\n", "#MN# spurns everyone in the room.\n");
       target("You spurn #TN#.\n", "#MN# spurns #TN#.\n", "#MN# spurns you.\n");
       afar("You spurn #TN# from afar.\n", "#MN# spurns you from afar.\n");
    }
}

int
cmd_spurn(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
