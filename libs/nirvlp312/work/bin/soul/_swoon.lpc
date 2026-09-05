inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You swoon over something.$N$\n", "#MN# swoons over something.$N$\n");
       target("You swoon over #TN#.$N$\n", "#MN# swoons over #TN#.$N$\n", "#MN# swoons over you.$N$\n");
       afar("$H$[afar]$N$ You swoon over #TN#.$N$\n", "$H$[afar]$N$ #MN# swoons over you.$N$\n");
    }
}

int
cmd_swoon(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
