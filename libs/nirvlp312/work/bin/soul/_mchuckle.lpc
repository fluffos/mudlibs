inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chuckle merrily.$N$\n", "#MN# chuckles merrily.$N$\n");
       target("You chuckle merrily at #TN#.$N$\n", "#MN# chuckles merrily at #TN#.$N$\n", "#MN# chuckles merrily at you.$N$\n");
       afar("You chuckle merrily at #TN# from afar.$N$\n", "#MN# chuckles merrily at you from afar.$N$\n");
    }
}

int
cmd_mchuckle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
