inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You kick yourself! Meanie!$N$\n", "#MN# kicks #MO#self. OUCH!!$N$\n");
       target("You kick #TN#.$N$\n", "#MN# kicks #TN#.$N$\n", "#MN# kicks you! OUCH!!$N$\n");
       afar("You kick #TN# from afar.$N$\n", "#MN# kicks you from afar. OUCH!!$N$\n");
    }
}

int
cmd_kick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
