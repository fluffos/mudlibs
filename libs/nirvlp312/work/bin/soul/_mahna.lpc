inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You sing, \"$HG$Mahna Mahna!$N$\"$N$\n", "#MN# sings, \"$HG$Mahna Mahna!$N$\"#RET#You feel the Mahna Mahna song starting to get stuck in your head.$N$\n");
       target("You sing \"$HG$Mahna Mahna!$N$\" to #TN#.#RET##CTS# gets a horrified look on #TP# face as #TS# responds, \"$HR$Do doo be-do-do!$N$\"\n", "#MN# sings \"$HG$Mahna Mahna!$N$\" to #TN#.#RET##CTS# gets a horrified look on #TP# face as #TS# responds, \"$HR$Do doo be-do-do!$N$\"$N$\n", "#MN# sings \"$HG$Mahna Mahna!$N$\" to you.#RET#You involuntarily respond, \"$HR$Do doo be-do-do!$N$\"  The horror!$N$\n");
       afar("From afar, you sing \"$HG$Mahna Mahna!$N$\" to #TN#.#RET#From afar, #TN# responds, \"$HR$Do doo be-do-do!$N$\"$N$\n", "From afar, #MN# sings \"$HG$Mahna Mahna!$N$\" to you.#RET#From afar, you involuntarily respond, \"$HR$Do doo be-do-do!$N$\"  The horror!$N$\n");
    }
}

int
cmd_mahna(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
