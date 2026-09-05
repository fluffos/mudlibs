inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You apologize to everyone in the room.\n", "#MN# apologizes to everyone in the room.\n");
       target("You apologize to #TN#.\n", "#MN# apolgizes to #TN#.\n", "#MN# apologizes to you.\n");
       afar("You apologize to #TN# from afar.\n", "#MN# apologizes to you from afar.\n");
    }
}

int
cmd_apologize(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
