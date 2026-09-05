inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shake your finger and say, \"tsk! tsk! tsk!\".$N$\n", "#MN# shakes #MP# finger and says, \"tsk! tsk! tsk!\".$N$\n");
       target("You shake your finger at #TN# and say, \"tsk! tsk! tsk!\".$N$\n", "#MN# shakes #MP# finger at #TN# and says, \"tsk! tsk! tsk!\".$N$\n", "#MN# shakes #MP# finger at you and says, \"tsk! tsk! tsk!\".$N$\n");
       afar("[afar] You shake your finger at #TN# and say, \"tsk! tsk! tsk!\".$N$\n", "[afar] #MN# shakes #MP# finger at you and says, \"tsk! tsk! tsk!\".$N$\n");
    }
}

int
cmd_tsk(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
