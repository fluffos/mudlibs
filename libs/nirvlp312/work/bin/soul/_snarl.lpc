inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You snarl angrily.$N$\n", "#MN# snarls angrily.$N$\n");
       target("You snarl angrily at #TN#.$N$\n", "#MN# snarls angrily at #TN#.$N$\n", "#MN# snarls angrily at you.$N$\n");
       afar("You snarl angrily at #TN# from afar.$N$\n", "#MN# snarls angrily at you from afar.$N$\n");
    }
}

int
cmd_snarl(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
