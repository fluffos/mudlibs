inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cock your head to the side inquisitively.$N$\n", "#MN# cocks #MP# head to the side inquisitively.$N$\n");
       target("You cock your head to the side inquisitively at #TN#.$N$\n", "#MN# cocks her head to the side inquisitively at #TN#.$N$\n", "#MN# cocks her head to the side inquisitively at you.$N$\n");
       afar("You cock your head to the side inquisitively at #TP#, from afar.$N$\n", "#MN# cocks #MP# head to the side inquisitively at you from afar.$N$\n");
    }
}

int
cmd_headcock(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "wocket"; }
