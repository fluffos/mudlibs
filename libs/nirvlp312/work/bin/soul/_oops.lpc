inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
        nontarget("You place your hand over your mouth and say, \"Oops! Did I say that out loud?!\"\n",
            "#MN# places #MP# hand over #MP# mouth and says, \"Oops! Did I say that out loud?!\"\n");
       target("You look at #TN# and say, \"Oops!\"\n", "#MN# looks at #TN# and says, \"Oops!\"\n", "#MN# looks at you and says, \"Oops!\"\n");
       afar("You say, \"Oops!\" at #TN# from afar.\n", "#MN# says, \"Oops!\" at you from afar.\n");
    }
}

int
cmd_oops(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
