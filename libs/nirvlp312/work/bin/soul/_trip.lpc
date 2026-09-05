inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look for someone to trip.\n", "#MN# looks around the room for someone to trip.\n");
       target("You stick out your foot and trip #TN#, making #TO# tumble to the floor.\n", "#MN# sticks out #MP# foot and trips #TN#, making #TO# tumble to the floor.\n", "#MN# trips you with #MP# foot!\n\You tumble to the floor!\n");
       afar("Are your feet really that long?\n", "0\n");
    }
}

int
cmd_trip(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }
