inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You draw back into a corner, and softly utter, \"$B$Eep.$N$\"$N$\n", "$MN$ draws back into a corner, and softly utters, \"$B$Eep.$N$\"$N$\n");
       target("You draw away from $TN$, and softly utter, \"$B$Eep.$N$\"$N$\n", "$MN$ draws away from $TN$, and softly utters, \"$B$Eep.$N$\"$N$\n", "$MN$ draws away from you, and softly utters, \"$B$Eep.$N$\"$N$\n");
       afar("From afar, you utter \"$B$Eep$N$\" at #TN#.$N$\n", "From afar, #MN# utters \"$B$Eep$N$\" at you.$N$\n");
    }
}

int
cmd_eep(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
