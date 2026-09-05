inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You twirl your shirt around above your head like a helicopter!\n", "#MN# twirls #MP# shirt around above #MP# head like a helicopter!\n");
       target("You twirl your shirt around above your head like helicopter!#RET#You say to #TN#, \"You know you likey....!\"\n", "#MN# twirls #MP# shirt around above #MP# head like a helicopter!#RET#MN# says to #TN#, \"You know you likey...!\"\n", "#MN# twirls #MP# shirt around above #MP# head like a helicopter!#RET#MN# says to you, \"You know you likey....!\"\n");
       afar("You twirl your shirt around above your head like a helicopter!#RET#You yell at #TN#, \"You know you likey....!\"\n", "#MN# twirls #MP# shirt around above #MP# head like a helicopter!#RET#MN# yells at you, \"You know you likey....!\"\n");
    }
}

int
cmd_twirl(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
