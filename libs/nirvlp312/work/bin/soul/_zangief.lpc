inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You turn into Zangief.#RET#ZANGIEF SAY: HAW HAW HAW$N$\n", "#MN# turns into Zangief.#RET#ZANGIEF SAY: HAW HAW HAW$N$\n");
       target("You turn into Zangief on #TN#.#RET#ZANGIEF SAY: HAW HAW HAW$N$\n", "#MN# turns into Zangief on #TN#.#RET#ZANGIEF SAY: HAW HAW HAW$N$\n", "#MN# turns into Zangief on you.#RET#ZANGIEF SAY: HAW HAW HAW$N$\n");
       afar("You turn into Zangief on #TN# from afar.#RET#ZANGIEF SAY: HAW HAW HAW$N$\n", "#MN# turns into Zangief on you from afar.#RET#ZANGIEF SAY: HAW HAW HAW$N$\n");
    }
}

int
cmd_zangief(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
