inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yell, \"Respect my AUTHORITA!!!\"$N$\n", "#MN# yells, \"Respect my AUTHORITA!!!\".$N$\n");
       target("You thwack #TN# in the head with a club...#RET#You yell at #TN#, \"Respect my AUTHORITA!!!\".$N$\n", "#MN# thwacks #TN# in the head with a club....#RET##MN# yells at #TN#, \"Respect my AUTHORITA!!!\".$N$\n", "#MN# thwacks you in the head with a club....#RET##MN# yells at you, \"Respect my AUTHORITA!!!\".$N$\n");
       afar("$H$[afar]$N$ You thwack #TN# in the head with a club....#RET#$H$[afar]$N$ You yell at #TN#, \"Respect my AUTHORITA!!!\".$N$\n", "$H$[afar]$N$ #MN# thwacks you in the head with a club....#RET#$H$[afar]$N$ #MN# yells at you, \"Respect my AUTHORITA!!!\".$N$\n");
    }
}

int
cmd_authorita(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
