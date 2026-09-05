inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You go, '$HW$NI$N$!'$N$\n", "#MN# goes '$HW$NI!$N$'$N$\n");
       target("You go, '$HW$NI$N$!' at #TN#, sending #TO# reeling.$N$\n", "#MN# goes, '$HW$NI$N$!' at #TN#, sending #TO# reeling.$N$\n", "#MN# goes, '$HW$NI$N$!' sending you reeling!$N$\n");
       afar("From afar, you go, '$HW$NI$N$!' at #TN#!$N$\n", "From afar, #MN# goes, '$HW$NI$N$!' at you!$N$\n");
    }
}

int
cmd_ni(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "khrell"; }
