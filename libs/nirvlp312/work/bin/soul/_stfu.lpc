inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, 'STFU!'.$N$\n", "#MN# says, 'STFU!'.$N$\n");
       target("You tell #TN# to, 'STFU!'.$N$\n", "#MN# tells #TN# to, 'STFU!'.$N$\n", "#MN# tells you to, 'STFU!'.$N$\n");
       afar("$HY$[afar]$N$ You tell #TN# to, 'STFU!'.$N$\n", "$HY$[afar]$N$ #MN# tells you to, 'STFU!'.$N$\n");
    }
}

int
cmd_stfu(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
