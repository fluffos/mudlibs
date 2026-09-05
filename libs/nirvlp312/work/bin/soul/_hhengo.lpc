inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You clutch your hand in a limping gesture against your chest.#RET#You announce \"hhe ngo.\"$N$\n", "#MN# clutches #MP# hand in a limping gesture against #MP# chest.#RET##MN# announces \"hhe ngo.\"$N$\n");
       target("You stare at #TN# as if in a daze.#RET#You clutch your hand in a limping gesture against your chest.#RET#You announce \"hhe ngo.\"$N$\n", "#MN# stares at #TN# as if in a daze.#RET##MN# clutches #MP# hand in a limping gesture against #MP# chest.#RET##MN# announces \"hhe ngo.\"$N$\n", "#MN# stares at you as if in a daze.#RET##MN# clutches #MP# hand in a limping gesture against #MP# chest.#RET##MN# announces \"hhe ngo.\"$N$\n");
       afar("You stare at #TN# from afar as if in a daze.#RET#You clutch your hand in a limping gesture against your chest.#RET#You announce to #TN# \"hhe ngo.\"$N$\n", "#MN# stares at you from afar as if in a daze.#RET#In your mind's eye, #MN# clutches #MP# hand in a limping gesture against #MP# chest.#RET##MN# announces to you \"hhe ngo.\"$N$\n");
    }
}

int
cmd_hhengo(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
