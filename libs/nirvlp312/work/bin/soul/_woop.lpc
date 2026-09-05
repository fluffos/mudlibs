inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go: wOOp wOOp! $N$\n", "#MN# goes: wOOp wOOp!$N$\n");
       target("You look at #TN# and go: wOOp wOOp! $N$\n", "#MN# looks at #TN# and goes: wOOp wOOp!$N$\n", "#MN# looks at you and goes: wOOp wOOp!$N$\n");
       afar("You look at #TN# from afar and go: wOOp wOOp! $N$\n", "#MN# looks at you from afar and goes: wOOp wOOp!$N$\n");
    }
}

int
cmd_woop(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
