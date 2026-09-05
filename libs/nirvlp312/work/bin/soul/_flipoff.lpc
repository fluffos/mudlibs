inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You extend your middle finger towards everybody.$N$\n", "#MN# flips everybody off!$N$\n");
       target("You extend your middle finger towards #TN#.$N$\n", "#MN# flips #TN# off!#RET##MN# exclaims: $R$SCREW$N$ $R$YOU!$N$$N$\n", "#MN# extends #MP# middle finger towards you.#RET##MN# exclaims: $R$SCREW$H$ $R$YOU!$N$$N$\n");
       afar("You extend your middle finger towards #TN# from afar.#RET#You exclaim: $R$SCREW$N$ $R$YOU!$N$$N$\n", "#MN# extends #MP# middle finger towards you from afar.#RET##CMN# exclaims: $R$SCREW$N$ $R$YOU!$N$$N$\n");
    }
}

int
cmd_flipoff(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "martha"; }
