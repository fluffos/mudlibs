inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You look around for someone to perform a babality upon.$N$\n", "#MN# looks around for someone to perform a babality upon.$N$\n");
       target("#TN# turns into a whining little baby...#RET##TN# cries: \"WAH! WAH! $HC$:~($N$\"#RET#You announce: $HK$BABALITY$N$!$N$\n", "#TN# turns into a whining little baby...#RET##TN# cries: \"WAH! WAH! $HC$:~($N$\"#RET##MN# announces: $HK$BABALITY$N$!$N$\n", "You turn into a whining little baby...#RET#You cry: \"WAH! WAH! $HC$:~($N$\"#RET##MN# announces: $HK$BABALITY$N$!$N$\n");
       afar("You attempt to perform a babality upon #TN# from afar, but fail.$N$\n", "#MN# attempts to perform a babality upon you from afar, but fails.$N$\n");
    }
}

int
cmd_babality(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
