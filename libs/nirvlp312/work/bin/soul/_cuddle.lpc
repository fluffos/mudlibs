inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You cuddle yourself.$N$\n", "#MN# cuddles #MO#self.$N$\n");
       target("You cuddle #TN#.$N$\n", "#MN# cuddles #TN#.$N$\n", "#MN# cuddles you.$N$\n");
       afar("You cuddle #TN# from afar.$N$\n", "#MN# cuddles you from afar.$N$\n");
    }
}

int
cmd_cuddle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
