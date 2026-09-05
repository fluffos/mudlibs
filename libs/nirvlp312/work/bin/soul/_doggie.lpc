inherit "/bin/std";

void
reset(int x)
{
    if(!x) {
      ::reset();
       nontarget("You say: Fucking right doggie, that's some good cake.$N$\n", "#MN# says: Fucking right doggie, that's some good cake.#RET#You think to yourself, \"MMmmmmm cake.....\".$N$\n");
       target("You say: Fucking right doggie, that's some good cake.#RET#TN# drools....$N$\n", "#MN# says: Fucking right doggie, that's some good cake. #RET#TN# drools...$N$\n", "#MN# says: Fucking right doggie, that's some good cake.#RET#You think to yourself, \"Mmmmm cake......\".$N$\n");
       afar("You yell to #TN#: Fucking right doggie that's some good cake.#RET#TN# drools....$N$\n", "#MN# yells at you: Fucking right doggie that's some good cake.#RET#You think to yourself, \"Mmmmmm cake......\".$N$\n");
    }
}

int
cmd_doggie(string arg)
{
    return do_cmd(arg);
}

query_code_word() { return "verbal_kint"; }

query_creator() { return "fred"; }
