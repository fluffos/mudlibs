inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You present your naked body to the room.$N$\n", "#MN# presents her naked body to the room.$N$\n");
       target("You flash #TN#!$N$\n", "#MN# flashes #TN#!$N$\n", "#MN# flashes you!$N$\n");
       afar("You flash #TN# from afar!$N$\n", "#MN# flashes you from afar!$N$\n");
    }
}

int
cmd_flash(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
