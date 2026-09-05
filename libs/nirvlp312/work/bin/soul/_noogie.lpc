inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You give yourself a noogie.#RET#YEEEEEOUUUCHHHH!$N$\n", "#MN# gives #MO#self a noogie.#RET#It looks like it hurts!$N$\n");
       target("You give #TN# a noogie.#RET#Take that!$N$\n", "#MN# gives #TN# a noogie.#RET#It looks like it hurts!$N$\n", "#MN# gives you a noogie.#RET#YEEEEEOUUUCHHHH!$N$\n");
       afar("You give #TN# a noogie from afar.#RET#Take that!$N$\n", "#MN# gives you a noogie from afar.#RET#YEEEEEOUUUCHHHH!$N$\n");
    }
}

int
cmd_noogie(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "vertebraker"; }
