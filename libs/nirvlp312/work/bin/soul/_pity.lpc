inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You throw yourself a little Pity Party.\n", "#MN# throws #MO#self a little Pity Party.\n");
       target("You play a tiny air-violin for #TN#.#RET#You ask #TO#, \"Would you like some cheese with that whine?\n", "#MN# plays a tiny air-violin for #TN#.#RET##MN# asks #TO#, \"Would you like some cheese with that whine?\n", "#MN# plays a tiny air-violin for you.#RET##MN# asks you, \"Would you like some cheese with that whine?\n");
       afar("From afar, you play a tiny air-violin for #TN#.#RET#You ask #TO#, \"Would you like some cheese with that whine?\n", "From afar, #MN# plays a tiny air-violin for you.#RET##MN# asks you, \"Would you like some cheese with that whine?\n");
    }
}

int
cmd_pity(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "quicksilver"; }
