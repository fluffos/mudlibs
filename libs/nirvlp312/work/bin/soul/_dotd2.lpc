inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You explain: Any dead body that is not exterminated becomes one of them.#RET#It gets up and kills.#RET#The people it KILLS get up and KILL!$N$\n", "#MN# explains: Any dead body that is not exterminated becomes one of them.#RET#It gets up and kills.#RET#The people it KILLS get up and KILL!$N$\n");
       target("You explain to #TN#: Any dead body that is not exterminated becomes one of them.#RET#It gets up and kills.#RET#The people it KILLS get up and KILL!$N$\n", "#MN# explains to #TN#: Any dead body that is not exterminated becomes one of them.#RET#It gets up and kills.#RET#The people it KILLS get up and KILL!$N$\n", "#MN# explains to you: Any dead body that is not exterminated becomes one of them.#RET#It gets up and kills.#RET#The people it KILLS get up and KILL!$N$\n");
       afar("You explain to #TN# from afar: Any dead body that is not exterminated becomes one of them.#RET#It gets up and kills.#RET#The people it KILLS get up and KILL!$N$\n", "#MN# explains to you from afar: Any dead body that is not exterminated becomes one of them.#RET#It gets up and kills.#RET#The people it KILLS get up and KILL!$N$\n");
    }
}

int
cmd_dotd2(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
