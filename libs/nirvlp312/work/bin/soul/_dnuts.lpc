inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yell, \"DEEZ NUTS!\"$N$\n", "#MN# yells, \"DEEZ NUTS!\"$N$\n");
       target("You yell, \"DEEZ NUTS!\" at #TN#$N$\n", "#MN# yells, \"DEEZ NUTS!\" at #TN#$N$\n", "#MN# yells, \"DEEZ NUTS\" at you$N$\n");
       afar("From afar, you yell, \"DEEZ NUTS!\" at #TN#$N$\n", "From afar, #MN# yells, \"DEEZ NUTS!\" at you$N$\n");
    }
}

int
cmd_dnuts(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "shinshi"; }
