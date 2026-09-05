inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You squint your eyes and say, \"Good. Bad. I'm the one with the gun.\"\n", "#MN# squints #MP# eyes and says, \"Good. Bad. I'm the one with the gun.\"\n");
       target("You squint your eyes at #TN# and say, \"Good. Bad. I'm the one with the gun.\"#RET#You fire your BOOMSTICK at #MO#.\n", "#MN# squints #MP# eyes at #TN# and says, \"Good. Bad. I'm the one with the gun.\"#RET##MN# fires #MP# BOOMSTICK at #TN#.\n", "#MN# squints #MP# eyes at you and says, \"Good. Bad. I'm the one with the gun.\"#RET##MN# fires #MP# BOOMSTICK at you.\n");
       afar("From afar, You warn #TN#, \"Good. Bad. I'm the one with the gun.\"\n", "From afar, #MN# warns you, \"Good. Bad. I'm the one with the gun.\"\n");
    }
}

int
cmd_goodbad(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
