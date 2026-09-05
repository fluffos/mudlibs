inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look for a baby to punch.$N$\n", "#MN# looks for a baby to punch.$N$\n");
       target("You grab #TN# by the neck and begin to $HR$punch$N$ #TO# like a baby. (how fun!)$N$\n", "#MN# grabs #TN# by the neck and begins to $HR$punch$N$ #TO# like a baby. (how rude!)$N$\n", "#MN# grabs you by the neck and begins to $HR$punch$N$ you like a baby. (sicko!)$N$\n");
       afar("From afar, you grab #TN# by the neck and begin to $HR$punch$N$ #TO# like a baby. (how brave!)$N$\n", "From afar, #MN# grabs you by the neck and begins to $HR$punch$N$ you like a baby. (coward...)$N$\n");
    }
}

int
cmd_bpunch(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
