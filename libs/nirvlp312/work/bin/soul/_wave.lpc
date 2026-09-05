inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wave.$N$\n", "#MN# waves.$N$\n");
       target("You wave at #TN#.$N$\n", "#MN# waves at #TN#.$N$\n", "#MN# waves at you.$N$\n");
       afar("You wave at #TN# from afar.$N$\n", "#MN# waves at you from afar.$N$\n");
    }
}

int
cmd_wave(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
