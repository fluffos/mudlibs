inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You whistle innocently.$N$\n", "#MN# whistles innocently.$N$\n");
       target("You whistle innocently at #TN#.$N$\n", "#MN# whistles innocently at #TN#.$N$\n", "#MN# whistles innocently at you.$N$\n");
       afar("You whistle innocently at #TN# from afar.$N$\n", "#MN# whistles innocently at you from afar.$N$\n");
    }
}

int
cmd_innocent(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
