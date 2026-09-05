inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"It's 106 miles to Chicago.  We gotta full tank of gas, half a packet of cigarettes, it's dark, and we're wearing sunglasses.\"$N$\n", "#MN# says, \"It's 106 miles to Chicago.  We gotta full tank of gas, half a packet of cigarettes, it's dark, and we're wearing sunglasses.\"$N$\n");
       target("You turn to #TN# and say, \"It's 106 miles to Chicago.  We gotta full tank of gas, half a packet of cigarettes, it's dark, and we're wearing sunglasses.\"#RET##TN# says, \"Hit it.\"$N$\n", "#MN# turns to #TN# and says, \"It's 106 miles to Chicago.  We gotta full tank of gas, half a packet of cigarettes, it's dark, and we're wearing sunglasses.\"#RET##TN# says, \"Hit it.\"$N$\n", "#MN# turns to you and says, \"It's 106 miles to Chicago.  We gotta full tank of gas, half a packet of cigarettes, it's dark, and we're wearing sunglasses.\"#RET#You say, \"Hit it.\"$N$\n");
       afar("You tell #TN#: It's 106 miles to Chicago.  We gotta full tank of gas, half a packet of cigarettes, it's dark, and we're wearing sunglasses.#RET##TN# tells you: Hit it.$N$\n", "#MN# tells you: It's 106 miles to Chicago.  We gotta full tank of gas, half a packet of cigarettes, it's dark, and we're wearing sunglasses.#RET#You tell #MN#: Hit it.$N$\n");
    }
}

int
cmd_bb(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
