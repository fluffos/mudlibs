inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You pinch yourself and find that you are, indeed, awake!$N$\n", "#MN# pinches #MO#self to see if #MS# is awake!$N$\n");
       target("You pinch #TN# to see if #TS# is still awake.$N$\n", "#MN# pinches #TN# to see if #TS# is still awake.$N$\n", "#MN# pinches you to see if you're still awake.$N$\n");
       afar("From afar, You pinch #TN# to see if #TS#'s still awake.$N$\n", "From afar, #MN# pinches you to see if you're still awake.#RET#If you aren't, $B$WAKE$N$ $B$UP$N$!!$N$\n");
    }
}

int
cmd_pinch(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
