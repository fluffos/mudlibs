inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say, \"No kitty this is my pot-pie.\"#RET#Kitty goes, \"meow\"#RET#You scream, \"$HR$NO KITTY THIS IS MY POT-PIE!!$N$\"$N$\n", "#MN# says, \"No kitty this is my pot-pie.\"#RET#Kitty goes, \"meow\"#RET#MN# screams, \"$HR$NO KITTY THIS IS MY POT-PIE!!$N$\"$N$\n");
       target("You say, \"No #TN# this is my pot-pie.\"#RET#TN# goes, \"meow\"#RET#You scream, \"$HR$NO #TN# THIS IS MY POT-PIE!!$N$\"$N$\n", "#MN# says, \"No #TN# this is my pot-pie.\"#RET#TN# goes, \"meow\"#RET#MN# screams, \"$HR$NO #TN# THIS IS MY POT-PIE!!$N$\"$N$\n", "#MN# says, \"No #TN# this is my pot-pie.\"#RET#You go, \"meow\"#RET#MN# screams, \"$HR$NO #TN# THIS IS MY POT-PIE!!$N$\"$N$\n");
       afar("You say, \"No #TN# this is my pot-pie.\"#RET#From afar, #TN# goes, \"meow\"#RET#You scream, \"$HR$NO #CTN# THIS IS MY POT-PIE!!$N$\"$N$\n", "From afar, #MN# says, \"No #TN# this is my pot-pie.\"#RET#You go, \"meow\"#RET#From afar, #MN# screams, \"$HR$NO #CTN# THIS IS MY POT-PIE!!$N$\"$N$\n");
    }
}

int
cmd_kitty(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
