inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You let off a real rip-roarer.#RET#How rude!$N$\n", "#MN# lets off a real rip-roarer.#RET#What's that smell??$N$\n");
       target("You fart at #TN#.$N$\n", "#MN# farts at #TN#.$N$\n", "#MN# farts at you.$N$\n");
       afar("You fart at #TN# from afar.$N$\n", "#MN# farts at you from afar.#RET#Who knew stench could travel?$N$\n");
    }
}

int
cmd_fart(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
