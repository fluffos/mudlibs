inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You intone, \"Totes McGoats.\"$N$\n", "#MN# intones, \"Totes McGoats.\"$N$\n");
       target("With supreme aplomb, you say \"Totes McGoats\" to #TN#.#RET#\"Totes McGoats,\" #TN# replies.$N$\n", "With supreme aplomb, #MN# says \"Totes McGoats\" to #TN#.#RET#\"Totes McGoats,\" #TN# replies.$N$\n", "With supreme aplomb, #MN# says \"Totes McGoats\" to you.#RET#\"Totes McGoats,\" you reply.$N$\n");
       afar("From afar, and with supreme aplomb, you say \"Totes McGoats\" to #TN##RET#\"Totes McGoats,\" #TN# replies.$N$\n", "From afar, and with supreme aplomb, #MN# says \"Totes McGoats\" to you.#RET#\"Totes McGoats,\" you reply.$N$\n");
    }
}

int
cmd_totes(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "illarion"; }
