inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout, \"Who's yer Daddy!\"$N$\n", "#MN# shouts, \"Who's yer Daddy!\"$N$\n");
       target("You spank #TN# on the ass and shout, \"Who's yer Daddy!\"$N$\n", "#MN# spanks #TN# on the ass and shouts, \"Who's yer Daddy!\"$N$\n", "#MN# spanks you on the ass and shouts, \"Who's yer Daddy!\"$N$\n");
       afar("$HM$[afar]$N$ You spank #TN# on the ass and shout, \"Who's yer Daddy!\"$N$\n", "$HM$[afar]$N$ #MN# spanks you on the ass and shouts, \"Who's yer Daddy!\"\n");
    }
}

int
cmd_yerdaddy(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
