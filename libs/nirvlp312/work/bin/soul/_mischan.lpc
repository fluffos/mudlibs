inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You declare yourself to be the mischan Queen!$N$\n", "#MN# declares #MO#self to be the mischan Queen!$N$\n");
       target("You declare #TN# to be the mischan Queen!$N$\n", "#MN# declares #TN# to be the mischan Queen!$N$\n", "#MN# declares you to be the mischan Queen!#RET#Doh!$N$\n");
       afar("From afar, you declare #TN# to be the mischan Queen!$N$\n", "From afar, #MN# declares you to be the mischan Queen!#RET#Doh!$N$\n");
    }
}

int
cmd_mischan(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
