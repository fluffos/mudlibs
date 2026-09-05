inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("With supreme apathy, you mutter, \"Whatever.\"$N$\n", "With supreme apathy, #MN# mutters, \"Whatever.\"$N$\n");
       target("You turn to #TN# and mutter, \"Whatever.\"$N$\n", "#MN# turns to #TN# and mutters, \"Whatever.\"#RET##TN# looks a little more apathetic.$N$\n", "#MN# turns to you and mutters, \"Whatever.\"#RET#It must be contagious.  You find you actually care a little less too.$N$\n");
       afar("[afar]You turn to #TN# and mutter, \"Whatever.\"$N$\n", "[afar]#MN# turns to you and mutters, \"Whatever.\"#RET#[afar]It must be contagious.  You find you actually care a little less too.$N$\n");
    }
}

int
cmd_whatever(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
