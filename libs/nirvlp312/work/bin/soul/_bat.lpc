inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You bat your eyelashes.\n", "#MN# bats #MP# eyelashes.\n");
       target("You bat your eyelashes at #TN#.\n", "#MN# bats #MP# eyelashes at #TN#.\n", "#MN# bats #MP# eyelashes at you.\n");
       afar("You bat your eyelashes at #TN# from afar.\n", "#MN# bats #MP# eyelashes at you from afar.\n");
    }
}

int
cmd_bat(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
