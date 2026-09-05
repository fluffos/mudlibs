inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You stick out your tongue as an offering to the room.$N$\n", "#MN# sticks out #MP# tongue as an offering to the room.$N$\n");
       target("You offer to show #TN# all the interesting things that you can do with your tongue!$N$\n", "#MN# offers to show #TN# all the interesting things that can be done with the human tongue!$N$\n", "#MN# offers to show you all the interesting things #MS# can do with #MP# tongue!$N$\n");
       afar("0$N$\n", "0$N$\n");
    }
}

int
cmd_tongue(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "stardream"; }
