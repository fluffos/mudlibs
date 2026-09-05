inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You perform a stunning backflip!\n", "#MN# performs a stunning backflip!\n");
       target("You perform a backflip for #TN#.\n", "#MN# performs a backflip for #TN#.\n", "#MN# performs a stunning backflip for you!\n");
       afar("You do a stunning backflip for #TN# from afar.\n", "#MN# does a stunning backflip for you from afar.\n");
    }
}

int
cmd_backflip(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
