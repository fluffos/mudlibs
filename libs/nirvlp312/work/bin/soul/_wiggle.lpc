inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wiggle your bottom!$N$\n", "#MN# wiggles #MP# bottom!$N$\n");
       target("You wiggle your bottom at #TN#!$N$\n", "#MN# wiggles #MP# bottom at #TN#!$N$\n", "#MN# wiggles #MP# bottom at you!$N$\n");
       afar("You wiggle your bottom at #TN# from afar!$N$\n", "#MN# wiggles #MP# bottom at you from afar!$N$\n");
    }
}

int
cmd_wiggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
