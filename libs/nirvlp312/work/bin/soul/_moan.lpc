inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You start to moan.$N$\n", "#MN# starts to moan.$N$\n");
       target("You start to moan at #TN#.$N$\n", "#MN# begins to moan at #TN#.$N$\n", "#MN# begins to moan at you.$N$\n");
       afar("You start to moan at #TN# from afar.$N$\n", "#MN# begins to moan at you from afar.$N$\n");
    }
}

int
cmd_moan(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
