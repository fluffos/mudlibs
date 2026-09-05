inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You intone, \"$HR$Fatality.$N$\"$N$\n", "#MN# intones, \"$HR$Fatality.$N$\"$N$\n");
       target("You intone, \"$HR$#TN# wins.  Fatality.$N$\"$N$\n", "$MN$ intones, \"$HR$$TN$ wins.  Fatality.$N$\"$N$\n", "$MN$ intones, \"$HR$$TN$ wins.  Fatality.$N$\"$N$\n");
       afar("Nah.  Save it for someplace where you have an audience.$N$\n", "0$N$\n");
    }
}

int
cmd_fatality(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
