inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You hold yourself tightly, and feel warm and cozy.$N$\n", "#MN# holds #MO#self tightly, making #MO# feel warm and cozy.$N$\n");
       target("You hold #TN# tightly, making #TO# feel warm and cozy.$N$\n", "#MN# holds #TN# tightly, making #TO# feel warm and cozy.$N$\n", "#MN# holds you tightly, making you feel warm and cozy.$N$\n");
       afar("You hold #TN# tightly, making #TO# feel warm and cozy from afar. #RET# You are good like that!$N$\n", "#MN# holds you tightly, making you feel warm and cozy from afar. #RET# #CMS# is good like that!$N$\n");
    }
}

int
cmd_ahold(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
