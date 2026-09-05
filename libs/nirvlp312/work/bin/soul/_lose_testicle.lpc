inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You lose a TESTICLE!$N$\n", "#MN# loses a TESTICLE!$N$\n");
       target("You lose a TESTICLE due to #TN#!$N$\n", "#MN# loses a TESTICLE due to #TN#!$N$\n", "#MN# loses a TESTICLE due to YOU!$N$\n");
       afar("You lose a TESTICLE due to #TN# from afar!$N$\n", "#MN# loses a TESTICLE due to YOU from afar!$N$\n");
    }
}

int
cmd_lose_testicle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
