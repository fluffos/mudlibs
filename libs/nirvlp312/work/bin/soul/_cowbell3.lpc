inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yell, \"I've got a fevah!!#RET#And the only prescription is moah COWBELL!\"\n", "#MN# yells, \"I've got a fevah!!#RET#And the only prescription is moah COWBELL!\"\n");
       target("You yell at #TN#, \"I've got a fevah!!#RET#And the only prescription is moah COWBELL!\"\n", "#MN# yells at #TN#, \"I've got a fevah!!#RET#And the only prescription is moah COWBELL!\"\n", "#MN# yells at you, \"I've got a fevah!!#RET#And the only prescription is moah COWBELL!\"\n");
       afar("[afar] You yell at #TN#, \"I've got a fevah!!#RET#And the only prescription is moah COWBELL!\"\n", "[afar] #MN# yells at you, \"I've got a fevah!!#RET#And the only prescription is moah COWBELL!\"\n");
    }
}

int
cmd_cowbell3(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
