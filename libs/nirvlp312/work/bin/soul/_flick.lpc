inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You try to flick a booger but fail miserably.$N$\n", "#MN# miserably fails at flicking a booger off #MP# finger.$N$\n");
       target("You casually insert a finger into your nose and wiggle it around.#RET#You withdraw your finger, examine the results critically, and then flick them at #TN#.$N$\n", "#MN# casually inserts a finger into #MP# nose and wiggles it around.#RET##MN# withdraws #MP# finger, examines the results carefully, and flicks them at #TN#.$N$\n", "#MN# casually inserts a finger into #MP# nose and wiggles it around.#RET##MN# withdraws #MP# finger, examines the results carefully, and flicks them at you.$N$\n");
       afar("In a superb show of aim and accuracy you flick a booger on #TN# from afar!$N$\n", "With incredible accuracy, #MN# flicks a booger on you from afar!$N$\n");
    }
}

int
cmd_flick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "earwax"; }
