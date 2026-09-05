inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You snuggle yourself.$N$\n", "#MN# snuggles #MO#self.$N$\n");
       target("You snuggle up to #TN#.$N$\n", "#MN# snuggles up to #TN#.$N$\n", "#MN# snuggles up to you.$N$\n");
       afar("You snuggle up to #TN# from afar.$N$\n", "#MN# snuggles up to you from afar.$N$\n");
    }
}

int
cmd_snuggle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
