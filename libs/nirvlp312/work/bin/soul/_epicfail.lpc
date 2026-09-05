inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce, \"$H$Epic Fail!$N$\"$N$\n", "#MN# announces, \"$H$Epic Fail!$N$\"$N$\n");
       target("You point at #TN# and announce, \"$H$Epic Fail!$N$\"$N$\n", "#MN# points at #TN# and announces, \"$H$Epic Fail!$N$\"$N$\n", "#MN# points at you and announces, \"$H$Epic Fail!$N$\"$N$\n");
       afar("Nope.  It doesn't work without an audience.$N$\n", "0$N$\n");
    }
}

int
cmd_epicfail(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
