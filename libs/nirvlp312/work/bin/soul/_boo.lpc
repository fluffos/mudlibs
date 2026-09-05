inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You chant: \"BOOOOOOOOOOOOOOOOOOO\".$N$\n", "#MN# chants: \"BOOOOOOOOOOOOOOOOOO\".$N$\n");
       target("You chant at #TN#: \"BOOOOOOOOOOOOOOOOOOO\".$N$\n", "#MN# chants at #TN#: \"BOOOOOOOOOOOOOOOOOO\".$N$\n", "#MN# chants at you: \"BOOOOOOOOOOOOOOOOOO\".$N$\n");
       afar("You chant at #TN# from afar: \"BOOOOOOOOOOOOOOOOOOO\".$N$\n", "#MN# chants at you from afar: \"BOOOOOOOOOOOOOOOOOO\".$N$\n");
    }
}

int
cmd_boo(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
