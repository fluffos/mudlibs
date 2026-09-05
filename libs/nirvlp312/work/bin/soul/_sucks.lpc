inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You announce: \"SUCKS TO BE YOU!\"$N$\n", "#MN# announces: \"SUCKS TO BE YOU!\"$N$\n");
       target("You stare at #TN#.#RET#You announce: \"SUCKS TO BE YOU!\"$N$\n", "#MN# stares at #TN#.#RET##MN# announces: \"SUCKS TO BE YOU!\"$N$\n", "#MN# stares at you.#RET##MN# announces: \"SUCKS TO BE YOU!\"$N$\n");
       afar("You scream as loudly as you can.#RET#Game driver nods.$N$\n", "Game driver tells you:#RET#<telepath from #MN#>#RET#SUCKS TO BE YOU!#RET#</telepath>$N$\n");
    }
}

int
cmd_sucks(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
