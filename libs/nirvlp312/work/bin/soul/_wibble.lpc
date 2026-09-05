inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You wibble about the room!$N$\n", "#MN# wibbles about the room!$N$\n");
       target("You wibble around #TN#!$N$\n", "#MN# wibbles around #TN#!$N$\n", "#MN# wibbles around you!$N$\n");
       afar("0$N$\n", "0$N$\n");
    }
}

int
cmd_wibble(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
