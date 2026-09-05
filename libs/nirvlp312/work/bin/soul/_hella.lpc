inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"That is $HW$hella$N$ cool!\"$N$\n", "#MN# says, \"That is $HW$hella$N$ cool!\" (What a douche!)$N$\n");
       target("You say to #TN#, \"That is $HW$hella$N$ cool!\"$N$\n", "#MN# says to #TN#, \"That is $HW$hella$N$ cool!\"  (What a complete douchebag!)$N$\n", "#MN# says to you, \"That is $HW$hella$N$ cool!\"  (What a complete douchebag!)$N$\n");
       afar("From afar, you say to #TN#, \"That is $HW$hella$N$ cool!\"$N$\n", "From afar, #MN# says to you, \"That is $HW$hella$N$ cool!\"  (What a total douchebag!)$N$\n");
    }
}

int
cmd_hella(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
