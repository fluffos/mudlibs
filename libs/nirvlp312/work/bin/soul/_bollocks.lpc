inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You kick up some dirt and groan, \"Bollocks!\"$N$\n", "#CMN# kicks up some dirt and groans, \"Bollocks!\"$N$\n");
       target("You kick up some dirt at #CTN# and groan, \"Bollocks!\"$N$\n", "#CMN# kicks up some dirt at #CTN# and groans, \"Bollocks!\"$N$\n", "#CMN# kicks up some dirt at you and groans, \"Bollocks!\"$N$\n");
       afar("You kick up some dirt at #CTN# from far away and groan, \"Bollocks!\"$N$\n", "#CMN# kicks up some dirt at you from far away and groans, \"Bollocks!\"$N$\n");
    }
}

int
cmd_bollocks(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "forbin"; }
