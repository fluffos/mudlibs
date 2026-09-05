inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say \"Bah!\" to the world!\n", "#MN# says \"Bah!\" to the world!\n");
       target("You say \"Bah!\" to #TN#.\n", "#MN# says \"Bah!\" to #TN#.\n", "#MN# says \"Bah!\" to you.\n");
       afar("You say \"Bah!\" to #TN# from afar.\n", "#MN# says \"Bah!\" to you from afar.\n");
    }
}

int
cmd_bah(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
