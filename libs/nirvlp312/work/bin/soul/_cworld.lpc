inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"Baby...everything I'm going to do to you I learned at SeaWorld\".$N$\n", "#MN# says, \"Baby...everything I'm going to do to you I learned at SeaWorld\".$N$\n");
       target("You gaze lovingly into #TN#'s eyes and say,#RET#\"Baby...everything I'm going to do to you I learned at SeaWorld\".$N$\n", "#MN# gazes lovingly into #TN#'s eyes and says,#RET#\"Baby...everything I'm going to do to you I learned at SeaWorld\".$N$\n", "#MN# gazes lovingly into your eyes and says,#RET#\"Baby...everything I'm going to do to you I learned at SeaWorld\".$N$\n");
       afar("You gaze lovingly into #TN#'s eyes from afar and say,#RET#\"Baby...everything I'm going to do to you I learned at SeaWorld\".$N$\n", "#MN# gazes lovingly into your eyes from afar and says,#RET#\"Baby...everything I'm going to do to you I learned at SeaWorld\".$N$\n");
    }
}

int
cmd_cworld(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
