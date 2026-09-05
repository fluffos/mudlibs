inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You squeeze yourself fondly.$N$\n", "#MN# squeezes #MO#self fondly.$N$\n");
       target("You squeeze #TN# fondly.$N$\n", "#MN# squeezes #TN# fondly.$N$\n", "#MN# squeezes you fondly.$N$\n");
       afar("You squeeze #TN# fondly from afar.$N$\n", "#MN# squeezes you fondly from afar.$N$\n");
    }
}

int
cmd_squeeze(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
