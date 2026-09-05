inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce: GET OVER HERE!$N$\n", "#MN# announces: GET OVER HERE!$N$\n");
       target("You shoot a hook at #TN#!#RET#You announce: GET OVER HERE!#RET#TN# slides right up to you.#RET#You UPPERCUT #TN# through the fucking ceiling.$N$\n", "#MN# shoots a hook at #TN#!#RET##MN# announces: GET OVER HERE!#RET#TN# slides right up to #MN#.#RET##MN# UPPERCUTS #TN# through the fucking ceiling.$N$\n", "#MN# shoots a hook at you!#RET##MN# announces: GET OVER HERE!#RET#You slide right up to #MN#.#RET##MN# UPPERCUTS you through the fucking ceiling!$N$\n");
       afar("Your hook doesn't extend that far :($N$\n", "$N$\n");
    }
}

int
cmd_scorpion(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
