inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You $C$grok$N$ solemnly.$N$\n", "#MN# $C$groks$N$ solemnly.$N$\n");
       target("You $C$grok$N$ solemnly at #TN#.$N$\n", "#MN# $C$groks$N$ solemnly at #TN#.$N$\n", "#MN# $C$groks$N$ solemnly at you.$N$\n");
       afar("You $C$grok$N$ solemnly at #TN# from afar.$N$\n", "#MN# $C$groks$N$ solemnly at you from afar.$N$\n");
    }
}

int
cmd_grok(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
