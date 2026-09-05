inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You gaze lovingly at yourself.$N$\n", "#MN# gazes lovingly at #MO#self.$N$\n");
       target("You gaze lovingly at #TN#, staring deep into #TP# eyes.$N$\n", "#MN# gazes lovingly at #TN#, staring deep into #TP# eyes.$N$\n", "#MN# gazes lovingly at you, staring deep into your eyes.$N$\n");
       afar("You gaze lovingly at #TN#, staring deep into #TO# eyes from afar. #RET# How'd ya do THAT?$N$\n", "#MN# gazes lovingly at you, staring deep into your eyes from afar. #RET# How'd #MS# do THAT?$N$\n");
    }
}

int
cmd_lgaze(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
