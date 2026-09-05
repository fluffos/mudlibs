inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You hug yourself.$N$\n", "#MN# hugs #MO#self.$N$\n");
       target("You hug #TN#.$N$\n", "#MN# hugs #TN#.$N$\n", "#MN# hugs you.$N$\n");
       afar("You hug #TN# from afar.$N$\n", "#MN# hugs you from afar.$N$\n");
    }
}

int
cmd_hug(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
