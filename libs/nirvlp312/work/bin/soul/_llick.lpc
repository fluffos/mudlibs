inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You lick your lips, leaving them slightly moist.$N$\n", "#MN# licks #MP# lips, leaving them slightly moist.$N$\n");
       target("You look at #TN#.#RET#You lick your lips, leaving them slightly moist.$N$\n", "#MN# looks at #TN#.#RET##MN# licks #MP# lips, leaving them slightly moist.$N$\n", "#MN# looks at you.#RET##MN# licks #MP# lips, leaving them slightly moist.$N$\n");
       afar("You lick your lips at #TN# from afar.$N$\n", "#MN# licks #MP# lips at you from afar.$N$\n");
    }
}

int
cmd_llick(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
