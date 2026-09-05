inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You attempt to strangle yourself.#RET#Why not just type 'suicide'?$N$\n", "#MN# attempts to strangle #MO#self.$N$\n");
       target("You attempt to strangle #TN# with your big, powerful hands.#RET#George Carlin asks: Why do they let guys like you on an airplane?$N$\n", "#MN# attempts to strangle #TN# with #MP# big, powerful hands.#RET#George Carlin asks: Why do they let guys like #MN# on an airplane?$N$\n", "#MN# attempts to strangle you with #MP# big, powerful hands.#RET#George Carlin asks: Why do they let guys like #MN# on an airplane?$N$\n");
       afar("You make some crazy twitching and groping motions far away from #TN#.$N$\n", "#MN# makes some crazy twitching and groping motions far away from you.$N$\n");
    }
}

int
cmd_strangle(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
