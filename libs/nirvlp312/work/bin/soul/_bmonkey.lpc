inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You yell, \"$HY$BRASS MONKEY$N$, that funky monkey!!\"$N$\n", "#MN# yells, \"$HY$BRASS MONKEY$N$, taht funky monkey!!\"$N$\n");
       target("You yell at #TN#, \"$HY$BRASS MONKEY$N$, that funky monkey!!\"$N$\n", "#MN# yells at #TN#, \"$HY$BRASS MONKEY$N$, that funky monkey!!\"$N$\n", "#MN# yells at you, \"$HY$BRASS MONKEY$N$, that funky monkey!!\"$N$\n");
       afar("(From afar) You yell at #TN#, \"$HY$BRASS MONKEY$N$, that funky monkey!!\"$N$\n", "(From afar) #MN# yells at you, \"$HY$BRASS MONKEY$N$, that funky monkey!!\"$N$\n");
    }
}

int
cmd_bmonkey(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
