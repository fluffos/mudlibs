inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You shoot the body on the ground.#RET#You query: Why? .. because it feels so goddamn good.#RET#You fire at the body again.$N$\n", "#MN# shoots the body on the ground.#RET##MN# queries: Why? .. because it feels so goddamn good.#RET##MN# fires at the body again.$N$\n");
       target("You shoot #TN# in the head.#RET#You query: Why? .. because it feels so goddamn good.#RET#You fire at #TN# again.$N$\n", "#MN# shoots #TN# in the head.#RET##MN# queries: Why? .. because it feels so goddamn good.#RET##MN# shoots at #TN# again.$N$\n", "#MN# shoots you in the head.#RET##MN# queries: Why? .. because it feels so goddamn good.#RET##MN# shoots at you again.$N$\n");
       afar("You say something, but it makes no sense.#RET#WATCH ALFREDO GARCIA$N$\n", "You have the sudden urge to watch \"Bring me the Head of Alfredo Garcia\".$N$\n");
    }
}

int
cmd_algarcia2(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
