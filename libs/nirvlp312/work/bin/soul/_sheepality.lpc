inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You intone, \"$HW$Sheepality.$N$\"#RET#Off in the distance, you hear a \"Baaaah.\"$N$\n", "#MN# intones, \"$HW$Sheepality.$N$\"#RET#Off in the distance, you hear a \"Baaaah.\"$N$\n");
       target("You turn to #TN# and intone, \"$HW$Sheepality.$N$\"#RET##TN# replies with an agreeable \"Baaaah.\"$N$\n", "#MN# turns to #TN# and intones, \"$HW$Sheepality.$N$\"#RET##TN# replies with an agreeable \"Baaaah.\"#RET#Interesting.$N$\n", "#MN# turns to you and intones, \"$HW$Sheepality.$N$\"#RET#You reply with an agreeable \"Baaaah.\"#RET#Doh!$N$\n");
       afar("From afar, you inform #TN# that you're calling a sheepality.$N$\n", "From afar, #MN# informs you that #MS# is calling a sheepality.$N$\n");
    }
}

int
cmd_sheepality(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
