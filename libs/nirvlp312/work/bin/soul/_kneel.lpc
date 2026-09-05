inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You drop to one knee and lower your head.$N$\n", "#MN# drops to one knee and lowers #MP# head.$N$\n");
       target("You drop to one knee before #TN# and lower your head.$N$\n", "#MN# drops to one knee before #TN# and lowers #MP# head.$N$\n", "#MN# drops to one knee before you and lowers #MP# head.$N$\n");
       afar("From afar, you drop to one knee before #TN# and lower your head.$N$\n", "From afar, #MN# drops to one knee before you and lowers #MP# head.$N$\n");
    }
}

int
cmd_kneel(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
