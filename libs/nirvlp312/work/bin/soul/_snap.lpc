inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You snap your fingers.$N$\n", "#MN# snaps #MP# fingers.$N$\n");
       target("You snap your fingers at #TN#.$N$\n", "#MN# snaps #MP# fingers at #TN#.$N$\n", "#MN# snaps #MP# fingers at you.$N$\n");
       afar("You snap your fingers at #TN# from afar.$N$\n", "#MN# snaps #MP# fingers at you from afar.$N$\n");
    }
}

int
cmd_snap(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
