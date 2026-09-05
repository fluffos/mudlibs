inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look for someone to beat with your cane. Just like Star!$N$\n", "#MN# looks for someone to beat on with #MP# cane. Just like Star!$N$\n");
       target("You threaten to beat #TN# with your cane. Just like Star!$N$\n", "#MN# threatens to beat #TN# with #MP# cane. Just like Star!$N$\n", "#MN# threatens to beat you with #MP# cane.. Just like Star!$N$\n");
       afar("From afar, you threaten to beat #TN# with your cane. Just like Star!\n", "From afar, #MN# threatens to beat you with his cane. Just like Star!\n");
    }
}

int
cmd_cane(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "shinshi"; }
