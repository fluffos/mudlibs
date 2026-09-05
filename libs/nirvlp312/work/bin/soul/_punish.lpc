inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shout: $HR$PUNISH$N$$N$\n", "#MN# shouts: $HR$PUNISH$N$$N$\n");
       target("You look at #TN# with murder in your eye.#RET#You shout: $HR$PUNISH$N$$N$\n", "#MN# looks at #TN# with murder in #MP# eye.#RET##MN# shouts: $HR$PUNISH$N$$N$\n", "#MN# looks at you with murder in #MP# eye.#RET##MN# shouts: $HR$PUNISH$N$$N$\n");
       afar("You look at #TN# from afar with murder in your eye.#RET#You shout: $HR$PUNISH$N$$N$\n", "#MN# looks at you from afar with murder in #MP# eye.#RET##MN# shouts: $HR$PUNISH$N$$N$\n");
    }
}

int
cmd_punish(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
