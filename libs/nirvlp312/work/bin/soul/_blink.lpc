inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You blink.$N$\n", "#MN# blinks.$N$\n");
       target("You blink at #TN#.$N$\n", "#MN# blinks at #TN#.$N$\n", "#MN# blinks at you.$N$\n");
       afar("You blink at #TN# from afar.$N$\n", "#MN# blinks at you from afar.$N$\n");
    }
}

int
cmd_blink(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
