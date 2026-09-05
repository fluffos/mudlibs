inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You softly press your top lip against your bottom lip.$N$\n", "#MN# softly presses #MP# top lip against #MP# bottom lip.$N$\n");
       target("You pull #TN# closer.#RET#You feel your heart flutter as you softly kiss #TP# lips.$N$\n", "#MN# pulls #TN# closer.#RET##MN# softly kisses #TP# lips.$N$\n", "#MN# pulls you closer.#RET##MN# softly kisses your lips.$N$\n");
       afar("You try to place an ol' smoocher on #TN# from afar, but fail.$N$\n", "#MN# tries to place an ol' smoocher on you from afar, but fails.$N$\n");
    }
}

int
cmd_kiss2(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
