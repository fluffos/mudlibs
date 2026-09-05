inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("In tones of awe, you exclaim, \"Great Scott!\"$N$\n", "In tones of awe, #MN# exclaims, \"Great Scott!\"$N$\n");
       target("You turn to #TN# and say, \"Great Scott!\"#RET##TN# replies, \"I know, this is heavy.\"$N$\n", "#MN# turns to #TN# and says, \"Great Scott!\"#RET##TN# replies, \"I know, this is heavy.\"$N$\n", "#MN# turns to you and says, \"Great Scott!\"#RET##You reply, \"I know, this is heavy.\"$N$\n");
       afar("You tell #TN#: Great Scott!#RET##TN# tells you: \"I know, this is heavy.\"$N$\n", "#MN# tells you: Great Scott!#RET##You tell #MN#: \"I know, this is heavy.\"$N$\n");
    }
}

int
cmd_greatscott(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
