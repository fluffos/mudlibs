inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"That'll do, that'll do.\"\n", "#MN# says, \"That'll do, that'll do.\"\n");
       target("You pat #TN# on the head and say:#RET#\"That'll do #TN#, that'll do.\"$N$\n", "#MN# pats #TN# on the head and says:#RET#\"That'll do #TN#, that'll do.\"$N$\n", "#MN# pats you on the head and says:#RET#\"That'll do #TN#, that'll do.\"$N$\n");
       afar("You pat #TN# on the head from afar and say:#RET#\"That'll do #TN#, that'll do.\"$N$\n", "#MN# pats you on the head from afar and says:#RET#\"That'll do #TN#, that'll do.\"$N$\n");
    }
}

int
cmd_shrek(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
